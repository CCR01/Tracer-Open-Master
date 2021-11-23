#include "DetailEnhancement.h"

// open cv
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/photo.hpp>

// images
#include "..\Image\Images.h"

// math
#include "..\LowLevelTracing\Math_LLT.h"

// often use
#include "..\oftenUseNamespace\oftenUseNamespace.h"

// open mp
#include <omp.h>

// sharpness evaluation
#include "..\Image\SharpnessEvaluation.h"


DetailEnhancement_BGR::DetailEnhancement_BGR() {}

DetailEnhancement_BGR::~DetailEnhancement_BGR() {}


bestParameterStruct_detailEnhance DetailEnhancement_BGR::getBestParameter()
{
	return mBestParaDE;
}
parameterDetailEnhancement DetailEnhancement_BGR::getInitialParameter()
{
	return mParaDE;
}
void DetailEnhancement_BGR::setInitialParameter(parameterDetailEnhancement paraDE_initial)
{
	mParaDE = paraDE_initial;
}

// calc roi to calc dif
void DetailEnhancement_BGR::calcROI_toCalcDif()
{
	unsigned int height = mSharpImage.size().height;
	unsigned int width = mSharpImage.size().width;

	unsigned int startX = mParaDE.getPercentCompare() * width / 100.0;
	unsigned int startY = mParaDE.getPercentCompare() * height / 100.0;
	unsigned int heighttROI = height - 2 * startY;
	unsigned int widthROI = width - 2 * startX;

	mRoiToCalcDif.x = startX;
	mRoiToCalcDif.y = startY;
	mRoiToCalcDif.width = widthROI;
	mRoiToCalcDif.height = heighttROI;
}

void DetailEnhancement_BGR::improveImageQuality_DetailEnhancement_BGR(const cv::Mat& sharpImage, const cv::Mat& blueredImage)
{
	mSharpImage = sharpImage.clone();
	mBlueredImage = blueredImage.clone();

	// normalize images
	cv::normalize(mSharpImage, mSharpImage, 0.0, 255.0, cv::NORM_MINMAX, CV_8UC3);
	cv::normalize(mBlueredImage, mBlueredImage, 0.0, 255.0, cv::NORM_MINMAX, CV_8UC3);
	// calc roi to calc dif
	calcROI_toCalcDif();
	// find best parameter and save
	findBestParameter();

}

// find best parameter and save
void DetailEnhancement_BGR::findBestParameter()
{
	real tempDifference{};
	real tempBestDifference_blue = oftenUse::getInfReal();
	real tempImprovement;
	real tempBestImprovement = -1.0 * oftenUse::getInfReal();

	float tempSigma_s = mParaDE.getMinSigma_s();
	float tempSigma_r = mParaDE.getMinSigma_r();

	float deltaSigma_s = (mParaDE.getMaxSigma_s() - mParaDE.getMinSigma_s()) / mParaDE.getStepsSigma_s();
	float deltaSigma_r = (mParaDE.getMaxSigma_r() - mParaDE.getMinSigma_r()) / mParaDE.getStepsSigma_r();

	SharpnessEvaluation SharpEval;
	real tempSharpness = -1.0 * oftenUse::getInfReal();
	real tempBestSharpness = -1.0 * oftenUse::getInfReal();

	while (tempSigma_s < mParaDE.getMaxSigma_s())
	{
		while (tempSigma_r < mParaDE.getMaxSigma_r())
		{
			cv::detailEnhance(mBlueredImage, mTempFilteredIma, tempSigma_s, tempSigma_r);

			cv::normalize(mTempFilteredIma, mTempFilteredIma, 0.0, 255.0, cv::NORM_MINMAX, CV_8UC3);

			// calculate improvement
			tempImprovement = Images::calcImprovementBGR(mSharpImage, mBlueredImage, mTempFilteredIma, mParaDE.getPercentCompare());

			if (mParaDE.getSharpnessEvalMethode() == sharpnessEvalMethode::sharpImage)
			{

				if (tempImprovement > tempBestImprovement)
				{
					tempDifference = Images::calcAbsDiff_BGR_uint8(mSharpImage, mTempFilteredIma, mParaDE.getPercentCompare());
					tempBestImprovement = tempImprovement;

					mBestParaDE.setDifference(tempDifference);
					mBestParaDE.setImage(mTempFilteredIma.clone());
					mBestParaDE.setSigmar_r(tempSigma_r);
					mBestParaDE.setSigmar_s(tempSigma_s);

					mBestParaDE.setImprovement(tempImprovement);
					// debug
					// std::cout << "improvement: " << improvement << std::endl;
				}
			}

			else if (mParaDE.getSharpnessEvalMethode() != sharpnessEvalMethode::sharpImage)
			{
				tempSharpness = SharpEval.calculateSharpness_superFct(mParaDE.getSharpnessEvalMethode(), mTempFilteredIma.clone());

				if (tempSharpness > tempBestSharpness)
				{
					tempBestSharpness = tempSharpness;

					// calculate difference sharp and filterd image
					tempDifference = Images::calcAbsDiff_BGR_uint8(mSharpImage, mTempFilteredIma, mParaDE.getPercentCompare());

					mBestParaDE.setDifference(tempDifference);
					mBestParaDE.setImage(mTempFilteredIma.clone());
					mBestParaDE.setSigmar_r(tempSigma_r);
					mBestParaDE.setSigmar_s(tempSigma_s);

					//tempImprovement = Images::calcImprovementBGR(mSharpImage, mBlueredImage, mTempFilteredIma, mParaDE.getPercentCompare());
					mBestParaDE.setImprovement(tempImprovement);
					// debug
					// std::cout << "improvement: " << improvement << std::endl;
					mBestParaDE.setSharpness(tempSharpness);
				}
			}

			tempSigma_r = tempSigma_r + deltaSigma_r;
		}

		tempSigma_r = mParaDE.getMinSigma_r();
		tempSigma_s = tempSigma_s + deltaSigma_s;
	}

	// check improvement
	if (mParaDE.getSharpnessEvalMethode() == sharpnessEvalMethode::sharpImage)
	{
		// check improvement
		if (mBestParaDE.getImprovement() <= 1.0)
		{
			mBestParaDE.setImage(mBlueredImage.clone());
			mBestParaDE.setImprovement(1.0);
		}
	}
}


// get filtered image
cv::Mat DetailEnhancement_BGR::getFilteredIma()
{
	return mBestParaDE.getImage();
}

void DetailEnhancement_BGR_parallel::setParameter_global(parameterDetailEnhancement paraDE_global)
{
	mParaDE_global = paraDE_global;
}
parameterDetailEnhancement DetailEnhancement_BGR_parallel::getInitalParameter_global()
{
	return mParaDE_global;
}
bestParameterStruct_detailEnhance DetailEnhancement_BGR_parallel::getBestParameter()
{
	return mBestParaDE_global;
}

void DetailEnhancement_BGR_parallel::improveImageQuality_DetailEnhancement_BGR_parallel(const cv::Mat& sharpImage, const cv::Mat& blueredImage)
{
	mSharpImage = sharpImage.clone();
	mBlueredImage = blueredImage.clone();
	initializePrameterDifCores();

	// find best parameter parallel
	findBestParameter_DE_parallel();

	// save best parameter
	findBestParameterAllCores();
}

void DetailEnhancement_BGR_parallel::findBestParameterAllCores()
{
	// find best improvement
	real bestImprovement = mDE_core1.getBestParameter().getImprovement();
	real tempImp;
	real bestSharpness = mDE_core1.getBestParameter().getShrarpness();
	real tempSharpness;
	unsigned int tempBestPosInVec = 0;

	if (mParaDE_global.getSharpnessEvalMethode() == sharpnessEvalMethode::sharpImage)
	{
		for (unsigned int i = 0; i < mImprovement_vec.size(); ++i)
		{
			tempImp = mImprovement_vec[i];
			// debug
			std::cout << "temp improvement Detail Enhancement: " << tempImp << " core number: " << i << std::endl;

			if (tempImp > bestImprovement)
			{
				bestImprovement = tempImp;
				tempBestPosInVec = i;


			}
		}
	}
	else if (mParaDE_global.getSharpnessEvalMethode() != sharpnessEvalMethode::sharpImage)
	{
		for (unsigned int i = 0; i < mSharpness_vec.size(); ++i)
		{
			tempSharpness = mSharpness_vec[i];
			// debug
			std::cout << "temp improvement Detail Enhancement: " << mImprovement_vec[i] << " core number: " << i << std::endl;
			std::cout << "temp sharpness Detail Enhancement: " << tempSharpness << " core number: " << i << std::endl;

			if (tempSharpness > bestSharpness)
			{
				bestSharpness = tempSharpness;
				tempBestPosInVec = i;


			}
		}
	}

	// debug 
	std::cout << " --> best improvement Detail Enhancement: " << mImprovement_vec[tempBestPosInVec] << " core number: " << tempBestPosInVec << std::endl;
	std::cout << " --> best sharpness Detail Enhancement: " << mSharpness_vec[tempBestPosInVec] << " core number: " << tempBestPosInVec << std::endl;

	mBestParaDE_global = mBestParameter_vec[tempBestPosInVec];
	mBestParaDE_global.setBestCoreNumber(tempBestPosInVec);
}

cv::Mat DetailEnhancement_BGR_parallel::getFilteredIma()
{
	return mBestParaDE_global.getImage();
}

void DetailEnhancement_BGR_parallel::findBestParameter_DE_parallel()
{
	mBestParameter_vec.resize(24);
	mImprovement_vec.resize(24);
	mSharpness_vec.resize(24);

omp_set_num_threads(24);
#pragma omp parallel
	{
#pragma omp sections
		{
#pragma omp section 
			{
				//std::cout << "start core 1" << std::endl;
				mDE_core1.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore1 = mDE_core1.getBestParameter().getImprovement();
				mImprovement_vec[0] = impCore1;
				mSharpness_vec[0] = mDE_core1.getBestParameter().getShrarpness();
				mBestParameter_vec[0] = mDE_core1.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 2" << std::endl;
				mDE_core2.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore2 = mDE_core2.getBestParameter().getImprovement();
				mImprovement_vec[1] = impCore2;
				mSharpness_vec[1] = mDE_core2.getBestParameter().getShrarpness();
				mBestParameter_vec[1] = mDE_core2.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 3" << std::endl;
				mDE_core3.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore3 = mDE_core3.getBestParameter().getImprovement();
				mImprovement_vec[2] = impCore3;
				mSharpness_vec[2] = mDE_core3.getBestParameter().getShrarpness();
				mBestParameter_vec[2] = mDE_core3.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 4" << std::endl;
				mDE_core4.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore4 = mDE_core4.getBestParameter().getImprovement();
				mImprovement_vec[3] = impCore4;
				mSharpness_vec[3] = mDE_core4.getBestParameter().getShrarpness();
				mBestParameter_vec[3] = mDE_core4.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 5" << std::endl;
				mDE_core5.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore5 = mDE_core5.getBestParameter().getImprovement();
				mImprovement_vec[4] = impCore5;
				mSharpness_vec[4] = mDE_core5.getBestParameter().getShrarpness();
				mBestParameter_vec[4] = mDE_core5.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 6" << std::endl;
				mDE_core6.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore6 = mDE_core6.getBestParameter().getImprovement();
				mImprovement_vec[5] = impCore6;
				mSharpness_vec[5] = mDE_core6.getBestParameter().getShrarpness();
				mBestParameter_vec[5] = mDE_core6.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 7" << std::endl;
				mDE_core7.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore7 = mDE_core7.getBestParameter().getImprovement();
				mImprovement_vec[6] = impCore7;
				mSharpness_vec[6] = mDE_core7.getBestParameter().getShrarpness();
				mBestParameter_vec[6] = mDE_core7.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 8" << std::endl;
				mDE_core8.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore8 = mDE_core8.getBestParameter().getImprovement();
				mImprovement_vec[7] = impCore8;
				mSharpness_vec[7] = mDE_core8.getBestParameter().getShrarpness();
				mBestParameter_vec[7] = mDE_core8.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 9" << std::endl;
				mDE_core9.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore9 = mDE_core9.getBestParameter().getImprovement();
				mImprovement_vec[8] = impCore9;
				mSharpness_vec[8] = mDE_core9.getBestParameter().getShrarpness();
				mBestParameter_vec[8] = mDE_core9.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 10" << std::endl;
				mDE_core10.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore10 = mDE_core10.getBestParameter().getImprovement();
				mImprovement_vec[9] = impCore10;
				mSharpness_vec[9] = mDE_core10.getBestParameter().getShrarpness();
				mBestParameter_vec[9] = mDE_core10.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 11" << std::endl;
				mDE_core11.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore11 = mDE_core11.getBestParameter().getImprovement();
				mImprovement_vec[10] = impCore11;
				mSharpness_vec[10] = mDE_core11.getBestParameter().getShrarpness();
				mBestParameter_vec[10] = mDE_core11.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 12" << std::endl;
				mDE_core12.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore12 = mDE_core12.getBestParameter().getImprovement();
				mImprovement_vec[11] = impCore12;
				mSharpness_vec[11] = mDE_core12.getBestParameter().getShrarpness();
				mBestParameter_vec[11] = mDE_core12.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 13" << std::endl;
				mDE_core13.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore13 = mDE_core13.getBestParameter().getImprovement();
				mImprovement_vec[12] = impCore13;
				mSharpness_vec[12] = mDE_core13.getBestParameter().getShrarpness();
				mBestParameter_vec[12] = mDE_core13.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 14" << std::endl;
				mDE_core14.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore14 = mDE_core14.getBestParameter().getImprovement();
				mImprovement_vec[13] = impCore14;
				mSharpness_vec[13] = mDE_core14.getBestParameter().getShrarpness();
				mBestParameter_vec[13] = mDE_core14.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 15" << std::endl;
				mDE_core15.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore15 = mDE_core15.getBestParameter().getImprovement();
				mImprovement_vec[14] = impCore15;
				mSharpness_vec[14] = mDE_core15.getBestParameter().getShrarpness();
				mBestParameter_vec[14] = mDE_core15.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 16" << std::endl;
				mDE_core16.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore16 = mDE_core16.getBestParameter().getImprovement();
				mImprovement_vec[15] = impCore16;
				mSharpness_vec[15] = mDE_core16.getBestParameter().getShrarpness();
				mBestParameter_vec[15] = mDE_core16.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 17" << std::endl;
				mDE_core17.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore17 = mDE_core17.getBestParameter().getImprovement();
				mImprovement_vec[16] = impCore17;
				mSharpness_vec[16] = mDE_core17.getBestParameter().getShrarpness();
				mBestParameter_vec[16] = mDE_core17.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 18" << std::endl;
				mDE_core18.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore18 = mDE_core18.getBestParameter().getImprovement();
				mImprovement_vec[17] = impCore18;
				mSharpness_vec[17] = mDE_core18.getBestParameter().getShrarpness();
				mBestParameter_vec[17] = mDE_core18.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 19" << std::endl;
				mDE_core19.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore19 = mDE_core19.getBestParameter().getImprovement();
				mImprovement_vec[18] = impCore19;
				mSharpness_vec[18] = mDE_core19.getBestParameter().getShrarpness();
				mBestParameter_vec[18] = mDE_core19.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 20" << std::endl;
				mDE_core20.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore20 = mDE_core20.getBestParameter().getImprovement();
				mImprovement_vec[19] = impCore20;
				mSharpness_vec[19] = mDE_core20.getBestParameter().getShrarpness();
				mBestParameter_vec[19] = mDE_core20.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 21" << std::endl;
				mDE_core21.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore21 = mDE_core21.getBestParameter().getImprovement();
				mImprovement_vec[20] = impCore21;
				mSharpness_vec[20] = mDE_core21.getBestParameter().getShrarpness();
				mBestParameter_vec[20] = mDE_core21.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 22" << std::endl;
				mDE_core22.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore22 = mDE_core22.getBestParameter().getImprovement();
				mImprovement_vec[21] = impCore22;
				mSharpness_vec[21] = mDE_core22.getBestParameter().getShrarpness();
				mBestParameter_vec[21] = mDE_core22.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 23" << std::endl;
				mDE_core23.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore23 = mDE_core23.getBestParameter().getImprovement();
				mImprovement_vec[22] = impCore23;
				mSharpness_vec[22] = mDE_core23.getBestParameter().getShrarpness();
				mBestParameter_vec[22] = mDE_core23.getBestParameter();
			}
#pragma omp section 
			{
				//std::cout << "start core 24" << std::endl;
				mDE_core24.improveImageQuality_DetailEnhancement_BGR(mSharpImage, mBlueredImage);
				real impCore24 = mDE_core24.getBestParameter().getImprovement();
				mImprovement_vec[23] = impCore24;
				mSharpness_vec[23] = mDE_core24.getBestParameter().getShrarpness();
				mBestParameter_vec[23] = mDE_core24.getBestParameter();
			}
		}
	}
}

void DetailEnhancement_BGR_parallel::initializePrameterDifCores()
{
	// numer of cores
	int numberCores = 24;

	// sigma r
	real minSigmaGlobal_r = mParaDE_global.getMinSigma_r();
	real maxSigmaGlobal_r = mParaDE_global.getMaxSigma_r();
	real stepsPerCoreSigma_r = mParaDE_global.getStepsSigma_r() / numberCores;

	// sigma s
	real minSigmaGlobal_s = mParaDE_global.getMinSigma_s();
	real maxSigmaGlobal_s = mParaDE_global.getMaxSigma_s();
	real stepsPerCoreSigma_s = mParaDE_global.getStepsSigma_s() / numberCores;

	// compate in percent
	real compareInPercent = mParaDE_global.getPercentCompare();
	mParaDE_core1.setPercentCompare(compareInPercent);
	mParaDE_core2.setPercentCompare(compareInPercent);
	mParaDE_core3.setPercentCompare(compareInPercent);
	mParaDE_core4.setPercentCompare(compareInPercent);
	mParaDE_core5.setPercentCompare(compareInPercent);
	mParaDE_core6.setPercentCompare(compareInPercent);
	mParaDE_core7.setPercentCompare(compareInPercent);
	mParaDE_core8.setPercentCompare(compareInPercent);
	mParaDE_core9.setPercentCompare(compareInPercent);
	mParaDE_core10.setPercentCompare(compareInPercent);
	mParaDE_core11.setPercentCompare(compareInPercent);
	mParaDE_core12.setPercentCompare(compareInPercent);
	mParaDE_core13.setPercentCompare(compareInPercent);
	mParaDE_core14.setPercentCompare(compareInPercent);
	mParaDE_core15.setPercentCompare(compareInPercent);
	mParaDE_core16.setPercentCompare(compareInPercent);
	mParaDE_core17.setPercentCompare(compareInPercent);
	mParaDE_core18.setPercentCompare(compareInPercent);
	mParaDE_core19.setPercentCompare(compareInPercent);
	mParaDE_core20.setPercentCompare(compareInPercent);
	mParaDE_core21.setPercentCompare(compareInPercent);
	mParaDE_core22.setPercentCompare(compareInPercent);
	mParaDE_core23.setPercentCompare(compareInPercent);
	mParaDE_core24.setPercentCompare(compareInPercent);

	// sharpness evalutation methode
	sharpnessEvalMethode sharpnessEvalMet = mParaDE_global.getSharpnessEvalMethode();
	mParaDE_core1.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core2.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core3.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core4.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core5.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core6.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core7.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core8.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core9.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core10.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core11.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core12.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core13.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core14.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core15.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core16.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core17.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core18.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core19.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core20.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core21.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core22.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core23.setSharpnessEvalMethode(sharpnessEvalMet);
	mParaDE_core24.setSharpnessEvalMethode(sharpnessEvalMet);

	// sigma r
	real deltaSigmaGloal_r = (mParaDE_global.getMaxSigma_r() - mParaDE_global.getMinSigma_r()) / mParaDE_global.getStepsSigma_r();
	real diffPerCoreSigma_r = deltaSigmaGloal_r * stepsPerCoreSigma_r;

	real minSigma_r_Core_1 = minSigmaGlobal_r;
	real maxSigma_r_Core_1 = minSigma_r_Core_1 + diffPerCoreSigma_r;
	real minSigma_r_Core_2 = maxSigma_r_Core_1;
	real maxSigma_r_Core_2 = minSigma_r_Core_2 + diffPerCoreSigma_r;
	real minSigma_r_Core_3 = maxSigma_r_Core_2;
	real maxSigma_r_Core_3 = minSigma_r_Core_3 + diffPerCoreSigma_r;
	real minSigma_r_Core_4 = maxSigma_r_Core_3;
	real maxSigma_r_Core_4 = minSigma_r_Core_4 + diffPerCoreSigma_r;
	real minSigma_r_Core_5 = maxSigma_r_Core_4;
	real maxSigma_r_Core_5 = minSigma_r_Core_5 + diffPerCoreSigma_r;
	real minSigma_r_Core_6 = maxSigma_r_Core_5;
	real maxSigma_r_Core_6 = minSigma_r_Core_6 + diffPerCoreSigma_r;
	real minSigma_r_Core_7 = maxSigma_r_Core_6;
	real maxSigma_r_Core_7 = minSigma_r_Core_7 + diffPerCoreSigma_r;
	real minSigma_r_Core_8 = maxSigma_r_Core_7;
	real maxSigma_r_Core_8 = minSigma_r_Core_8 + diffPerCoreSigma_r;
	real minSigma_r_Core_9 = maxSigma_r_Core_8;
	real maxSigma_r_Core_9 = minSigma_r_Core_9 + diffPerCoreSigma_r;
	real minSigma_r_Core_10 = maxSigma_r_Core_9;
	real maxSigma_r_Core_10 = minSigma_r_Core_10 + diffPerCoreSigma_r;
	real minSigma_r_Core_11 = maxSigma_r_Core_10;
	real maxSigma_r_Core_11 = minSigma_r_Core_11 + diffPerCoreSigma_r;
	real minSigma_r_Core_12 = maxSigma_r_Core_11;
	real maxSigma_r_Core_12 = minSigma_r_Core_12 + diffPerCoreSigma_r;
	real minSigma_r_Core_13 = maxSigma_r_Core_12;
	real maxSigma_r_Core_13 = minSigma_r_Core_13 + diffPerCoreSigma_r;
	real minSigma_r_Core_14 = maxSigma_r_Core_13;
	real maxSigma_r_Core_14 = minSigma_r_Core_14 + diffPerCoreSigma_r;
	real minSigma_r_Core_15 = maxSigma_r_Core_14;
	real maxSigma_r_Core_15 = minSigma_r_Core_15 + diffPerCoreSigma_r;
	real minSigma_r_Core_16 = maxSigma_r_Core_15;
	real maxSigma_r_Core_16 = minSigma_r_Core_16 + diffPerCoreSigma_r;
	real minSigma_r_Core_17 = maxSigma_r_Core_16;
	real maxSigma_r_Core_17 = minSigma_r_Core_17 + diffPerCoreSigma_r;
	real minSigma_r_Core_18 = maxSigma_r_Core_17;
	real maxSigma_r_Core_18 = minSigma_r_Core_18 + diffPerCoreSigma_r;
	real minSigma_r_Core_19 = maxSigma_r_Core_18;
	real maxSigma_r_Core_19 = minSigma_r_Core_19 + diffPerCoreSigma_r;
	real minSigma_r_Core_20 = maxSigma_r_Core_19;
	real maxSigma_r_Core_20 = minSigma_r_Core_20 + diffPerCoreSigma_r;
	real minSigma_r_Core_21 = maxSigma_r_Core_20;
	real maxSigma_r_Core_21 = minSigma_r_Core_21 + diffPerCoreSigma_r;
	real minSigma_r_Core_22 = maxSigma_r_Core_21;
	real maxSigma_r_Core_22 = minSigma_r_Core_22 + diffPerCoreSigma_r;
	real minSigma_r_Core_23 = maxSigma_r_Core_22;
	real maxSigma_r_Core_23 = minSigma_r_Core_23 + diffPerCoreSigma_r;
	real minSigma_r_Core_24 = maxSigma_r_Core_23;
	real maxSigma_r_Core_24 = maxSigmaGlobal_r;

	mParaDE_core1.setMinSigma_r(minSigma_r_Core_1);
	mParaDE_core2.setMinSigma_r(minSigma_r_Core_2);
	mParaDE_core3.setMinSigma_r(minSigma_r_Core_3);
	mParaDE_core4.setMinSigma_r(minSigma_r_Core_4);
	mParaDE_core5.setMinSigma_r(minSigma_r_Core_5);
	mParaDE_core6.setMinSigma_r(minSigma_r_Core_6);
	mParaDE_core7.setMinSigma_r(minSigma_r_Core_7);
	mParaDE_core8.setMinSigma_r(minSigma_r_Core_8);
	mParaDE_core9.setMinSigma_r(minSigma_r_Core_9);
	mParaDE_core10.setMinSigma_r(minSigma_r_Core_10);
	mParaDE_core11.setMinSigma_r(minSigma_r_Core_11);
	mParaDE_core12.setMinSigma_r(minSigma_r_Core_12);
	mParaDE_core13.setMinSigma_r(minSigma_r_Core_13);
	mParaDE_core14.setMinSigma_r(minSigma_r_Core_14);
	mParaDE_core15.setMinSigma_r(minSigma_r_Core_15);
	mParaDE_core16.setMinSigma_r(minSigma_r_Core_16);
	mParaDE_core17.setMinSigma_r(minSigma_r_Core_17);
	mParaDE_core18.setMinSigma_r(minSigma_r_Core_18);
	mParaDE_core19.setMinSigma_r(minSigma_r_Core_19);
	mParaDE_core20.setMinSigma_r(minSigma_r_Core_20);
	mParaDE_core21.setMinSigma_r(minSigma_r_Core_21);
	mParaDE_core22.setMinSigma_r(minSigma_r_Core_22);
	mParaDE_core23.setMinSigma_r(minSigma_r_Core_23);
	mParaDE_core24.setMinSigma_r(minSigma_r_Core_24);

	mParaDE_core1.setMaxSigma_r(maxSigma_r_Core_1);
	mParaDE_core2.setMaxSigma_r(maxSigma_r_Core_2);
	mParaDE_core3.setMaxSigma_r(maxSigma_r_Core_3);
	mParaDE_core4.setMaxSigma_r(maxSigma_r_Core_4);
	mParaDE_core5.setMaxSigma_r(maxSigma_r_Core_5);
	mParaDE_core6.setMaxSigma_r(maxSigma_r_Core_6);
	mParaDE_core7.setMaxSigma_r(maxSigma_r_Core_7);
	mParaDE_core8.setMaxSigma_r(maxSigma_r_Core_8);
	mParaDE_core9.setMaxSigma_r(maxSigma_r_Core_9);
	mParaDE_core10.setMaxSigma_r(maxSigma_r_Core_10);
	mParaDE_core11.setMaxSigma_r(maxSigma_r_Core_11);
	mParaDE_core12.setMaxSigma_r(maxSigma_r_Core_12);
	mParaDE_core13.setMaxSigma_r(maxSigma_r_Core_13);
	mParaDE_core14.setMaxSigma_r(maxSigma_r_Core_14);
	mParaDE_core15.setMaxSigma_r(maxSigma_r_Core_15);
	mParaDE_core16.setMaxSigma_r(maxSigma_r_Core_16);
	mParaDE_core17.setMaxSigma_r(maxSigma_r_Core_17);
	mParaDE_core18.setMaxSigma_r(maxSigma_r_Core_18);
	mParaDE_core19.setMaxSigma_r(maxSigma_r_Core_19);
	mParaDE_core20.setMaxSigma_r(maxSigma_r_Core_20);
	mParaDE_core21.setMaxSigma_r(maxSigma_r_Core_21);
	mParaDE_core22.setMaxSigma_r(maxSigma_r_Core_22);
	mParaDE_core23.setMaxSigma_r(maxSigma_r_Core_23);
	mParaDE_core24.setMaxSigma_r(maxSigma_r_Core_24);

	mParaDE_core1.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core2.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core3.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core4.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core5.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core6.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core7.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core8.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core9.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core10.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core11.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core12.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core13.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core14.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core15.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core16.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core17.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core18.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core19.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core20.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core21.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core22.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core23.setStepsSigma_r(stepsPerCoreSigma_r);
	mParaDE_core24.setStepsSigma_r(stepsPerCoreSigma_r);

	// sigma s
	real deltaSigmaGloal_s = (mParaDE_global.getMaxSigma_s() - mParaDE_global.getMinSigma_s()) / mParaDE_global.getStepsSigma_s();
	real diffPerCoreSigma_s = deltaSigmaGloal_s * stepsPerCoreSigma_s;

	real minSigma_s_Core_1 = minSigmaGlobal_s;
	real maxSigma_s_Core_1 = minSigma_s_Core_1 + diffPerCoreSigma_s;
	real minSigma_s_Core_2 = maxSigma_s_Core_1;
	real maxSigma_s_Core_2 = minSigma_s_Core_2 + diffPerCoreSigma_s;
	real minSigma_s_Core_3 = maxSigma_s_Core_2;
	real maxSigma_s_Core_3 = minSigma_s_Core_3 + diffPerCoreSigma_s;
	real minSigma_s_Core_4 = maxSigma_s_Core_3;
	real maxSigma_s_Core_4 = minSigma_s_Core_4 + diffPerCoreSigma_s;
	real minSigma_s_Core_5 = maxSigma_s_Core_4;
	real maxSigma_s_Core_5 = minSigma_s_Core_5 + diffPerCoreSigma_s;
	real minSigma_s_Core_6 = maxSigma_s_Core_5;
	real maxSigma_s_Core_6 = minSigma_s_Core_6 + diffPerCoreSigma_s;
	real minSigma_s_Core_7 = maxSigma_s_Core_6;
	real maxSigma_s_Core_7 = minSigma_s_Core_7 + diffPerCoreSigma_s;
	real minSigma_s_Core_8 = maxSigma_s_Core_7;
	real maxSigma_s_Core_8 = minSigma_s_Core_8 + diffPerCoreSigma_s;
	real minSigma_s_Core_9 = maxSigma_s_Core_8;
	real maxSigma_s_Core_9 = minSigma_s_Core_9 + diffPerCoreSigma_s;
	real minSigma_s_Core_10 = maxSigma_s_Core_9;
	real maxSigma_s_Core_10 = minSigma_s_Core_10 + diffPerCoreSigma_s;
	real minSigma_s_Core_11 = maxSigma_s_Core_10;
	real maxSigma_s_Core_11 = minSigma_s_Core_11 + diffPerCoreSigma_s;
	real minSigma_s_Core_12 = maxSigma_s_Core_11;
	real maxSigma_s_Core_12 = minSigma_s_Core_12 + diffPerCoreSigma_s;
	real minSigma_s_Core_13 = maxSigma_s_Core_12;
	real maxSigma_s_Core_13 = minSigma_s_Core_13 + diffPerCoreSigma_s;
	real minSigma_s_Core_14 = maxSigma_s_Core_13;
	real maxSigma_s_Core_14 = minSigma_s_Core_14 + diffPerCoreSigma_s;
	real minSigma_s_Core_15 = maxSigma_s_Core_14;
	real maxSigma_s_Core_15 = minSigma_s_Core_15 + diffPerCoreSigma_s;
	real minSigma_s_Core_16 = maxSigma_s_Core_15;
	real maxSigma_s_Core_16 = minSigma_s_Core_16 + diffPerCoreSigma_s;
	real minSigma_s_Core_17 = maxSigma_s_Core_16;
	real maxSigma_s_Core_17 = minSigma_s_Core_17 + diffPerCoreSigma_s;
	real minSigma_s_Core_18 = maxSigma_s_Core_17;
	real maxSigma_s_Core_18 = minSigma_s_Core_18 + diffPerCoreSigma_s;
	real minSigma_s_Core_19 = maxSigma_s_Core_18;
	real maxSigma_s_Core_19 = minSigma_s_Core_19 + diffPerCoreSigma_s;
	real minSigma_s_Core_20 = maxSigma_s_Core_19;
	real maxSigma_s_Core_20 = minSigma_s_Core_20 + diffPerCoreSigma_s;
	real minSigma_s_Core_21 = maxSigma_s_Core_20;
	real maxSigma_s_Core_21 = minSigma_s_Core_21 + diffPerCoreSigma_s;
	real minSigma_s_Core_22 = maxSigma_s_Core_21;
	real maxSigma_s_Core_22 = minSigma_s_Core_22 + diffPerCoreSigma_s;
	real minSigma_s_Core_23 = maxSigma_s_Core_22;
	real maxSigma_s_Core_23 = minSigma_s_Core_23 + diffPerCoreSigma_s;
	real minSigma_s_Core_24 = maxSigma_s_Core_23;
	real maxSigma_s_Core_24 = maxSigmaGlobal_s;

	mParaDE_core1.setMinSigma_s(minSigma_s_Core_1);
	mParaDE_core2.setMinSigma_s(minSigma_s_Core_2);
	mParaDE_core3.setMinSigma_s(minSigma_s_Core_3);
	mParaDE_core4.setMinSigma_s(minSigma_s_Core_4);
	mParaDE_core5.setMinSigma_s(minSigma_s_Core_5);
	mParaDE_core6.setMinSigma_s(minSigma_s_Core_6);
	mParaDE_core7.setMinSigma_s(minSigma_s_Core_7);
	mParaDE_core8.setMinSigma_s(minSigma_s_Core_8);
	mParaDE_core9.setMinSigma_s(minSigma_s_Core_9);
	mParaDE_core10.setMinSigma_s(minSigma_s_Core_10);
	mParaDE_core11.setMinSigma_s(minSigma_s_Core_11);
	mParaDE_core12.setMinSigma_s(minSigma_s_Core_12);
	mParaDE_core13.setMinSigma_s(minSigma_s_Core_13);
	mParaDE_core14.setMinSigma_s(minSigma_s_Core_14);
	mParaDE_core15.setMinSigma_s(minSigma_s_Core_15);
	mParaDE_core16.setMinSigma_s(minSigma_s_Core_16);
	mParaDE_core17.setMinSigma_s(minSigma_s_Core_17);
	mParaDE_core18.setMinSigma_s(minSigma_s_Core_18);
	mParaDE_core19.setMinSigma_s(minSigma_s_Core_19);
	mParaDE_core20.setMinSigma_s(minSigma_s_Core_20);
	mParaDE_core21.setMinSigma_s(minSigma_s_Core_21);
	mParaDE_core22.setMinSigma_s(minSigma_s_Core_22);
	mParaDE_core23.setMinSigma_s(minSigma_s_Core_23);
	mParaDE_core24.setMinSigma_s(minSigma_s_Core_24);

	mParaDE_core1.setMaxSigma_s(maxSigma_s_Core_1);
	mParaDE_core2.setMaxSigma_s(maxSigma_s_Core_2);
	mParaDE_core3.setMaxSigma_s(maxSigma_s_Core_3);
	mParaDE_core4.setMaxSigma_s(maxSigma_s_Core_4);
	mParaDE_core5.setMaxSigma_s(maxSigma_s_Core_5);
	mParaDE_core6.setMaxSigma_s(maxSigma_s_Core_6);
	mParaDE_core7.setMaxSigma_s(maxSigma_s_Core_7);
	mParaDE_core8.setMaxSigma_s(maxSigma_s_Core_8);
	mParaDE_core9.setMaxSigma_s(maxSigma_s_Core_9);
	mParaDE_core10.setMaxSigma_s(maxSigma_s_Core_10);
	mParaDE_core11.setMaxSigma_s(maxSigma_s_Core_11);
	mParaDE_core12.setMaxSigma_s(maxSigma_s_Core_12);
	mParaDE_core13.setMaxSigma_s(maxSigma_s_Core_13);
	mParaDE_core14.setMaxSigma_s(maxSigma_s_Core_14);
	mParaDE_core15.setMaxSigma_s(maxSigma_s_Core_15);
	mParaDE_core16.setMaxSigma_s(maxSigma_s_Core_16);
	mParaDE_core17.setMaxSigma_s(maxSigma_s_Core_17);
	mParaDE_core18.setMaxSigma_s(maxSigma_s_Core_18);
	mParaDE_core19.setMaxSigma_s(maxSigma_s_Core_19);
	mParaDE_core20.setMaxSigma_s(maxSigma_s_Core_20);
	mParaDE_core21.setMaxSigma_s(maxSigma_s_Core_21);
	mParaDE_core22.setMaxSigma_s(maxSigma_s_Core_22);
	mParaDE_core23.setMaxSigma_s(maxSigma_s_Core_23);
	mParaDE_core24.setMaxSigma_s(maxSigma_s_Core_24);

	mParaDE_core1.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core2.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core3.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core4.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core5.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core6.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core7.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core8.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core9.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core10.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core11.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core12.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core13.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core14.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core15.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core16.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core17.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core18.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core19.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core20.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core21.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core22.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core23.setStepsSigma_s(stepsPerCoreSigma_s);
	mParaDE_core24.setStepsSigma_s(stepsPerCoreSigma_s);

	// set parameter to cores
	mDE_core1.setInitialParameter(mParaDE_core1);
	mDE_core2.setInitialParameter(mParaDE_core2);
	mDE_core3.setInitialParameter(mParaDE_core3);
	mDE_core4.setInitialParameter(mParaDE_core4);
	mDE_core5.setInitialParameter(mParaDE_core5);
	mDE_core6.setInitialParameter(mParaDE_core6);
	mDE_core7.setInitialParameter(mParaDE_core7);
	mDE_core8.setInitialParameter(mParaDE_core8);
	mDE_core9.setInitialParameter(mParaDE_core9);
	mDE_core10.setInitialParameter(mParaDE_core10);
	mDE_core11.setInitialParameter(mParaDE_core11);
	mDE_core12.setInitialParameter(mParaDE_core12);
	mDE_core13.setInitialParameter(mParaDE_core13);
	mDE_core14.setInitialParameter(mParaDE_core14);
	mDE_core15.setInitialParameter(mParaDE_core15);
	mDE_core16.setInitialParameter(mParaDE_core16);
	mDE_core17.setInitialParameter(mParaDE_core17);
	mDE_core18.setInitialParameter(mParaDE_core18);
	mDE_core19.setInitialParameter(mParaDE_core19);
	mDE_core20.setInitialParameter(mParaDE_core20);
	mDE_core21.setInitialParameter(mParaDE_core21);
	mDE_core22.setInitialParameter(mParaDE_core22);
	mDE_core23.setInitialParameter(mParaDE_core23);
	mDE_core24.setInitialParameter(mParaDE_core24);
}
