#include "UnsharpMasking.h"

// images
#include "..\Image\Images.h"

// math
#include "..\LowLevelTracing\Math_LLT.h"

// often use
#include "..\oftenUseNamespace\oftenUseNamespace.h"

// open mp
#include <omp.h>

// sharpness evaluation methode
#include "..\Image\SharpnessEvaluation.h"

UnshaprMasking_singleCore_gray::UnshaprMasking_singleCore_gray() {}
UnshaprMasking_singleCore_gray::~UnshaprMasking_singleCore_gray() {}

void UnshaprMasking_singleCore_gray::setParameterUM(parameterUnsharpMasking parameterUM)
{
	mParaUM = parameterUM;
}

void UnshaprMasking_singleCore_gray::unsharpMasking(real sigma, real threshold, real amount)
{

	
	//cv::GaussianBlur(mBlueredImage, mBluerdForUnsharpMasking, cv::Size(0,0), sigmaX, sigmaY, mParaUM.getBoarderType());
	//Images::showImage_inputUint8("GaussianBlur", mBluerdForUnsharpMasking);

	//mLowContrastMask = cv::abs(mBlueredImage - mBluerdForUnsharpMasking) < threshold;
	//Images::showImage_inputUint8("lowContrastMast", mLowContrastMask);
	//mTempFilterdImage = mBlueredImage * (1 + amount) + mBluerdForUnsharpMasking * (-amount);
	////Images::showImage("sharpenedImage1", sharpenedImage);
	////new_image.copyTo(sharpenedImage, lowContrastMask);
	////Images::showImage("return image", new_image);
	//mBlueredImage.copyTo(mTempFilterdImage, mLowContrastMask);
	////Images::showImage_inputUint8("filtered images", mTempFilterdImage);

	cv::GaussianBlur(mBlueredImage, mBluerdForUnsharpMasking, cv::Size(0,0), sigma, sigma);
	mLowContrastMask = cv::abs(mBlueredImage - mBluerdForUnsharpMasking) < threshold;
	mTempFilterdImage= mBlueredImage * (1 + amount) + mBluerdForUnsharpMasking * (-amount);
	mBlueredImage.copyTo(mTempFilterdImage, mLowContrastMask);
}

// calculate improvement
real UnshaprMasking_singleCore_gray::calculateImprovement(const cv::Mat& sharpIma, const cv::Mat& blueredIma, const cv::Mat& filteredIma)
{
	real differenceBluered = calcAbsDifGrayImage_uni8(sharpIma, blueredIma);
	real differenceFilteredIma = calcAbsDifGrayImage_uni8(sharpIma, filteredIma);

	real returnVariance = differenceBluered / differenceFilteredIma;

	return returnVariance;
}

int UnshaprMasking_singleCore_gray::calcAbsDifGrayImage_uni8(const cv::Mat& sharpIma, const cv::Mat& filterdIma)
{
	cv::absdiff(sharpIma(mRoiToCalcDif), filterdIma(mRoiToCalcDif), mTempDifMat);
	return cv::sum(mTempDifMat)[0];
}

// get best parameter
bestParameterStruct_unsharpMask UnshaprMasking_singleCore_gray::getBestParameter()
{
	return mBestResult_unsharpMaskStruct;
}

// calc roi to calc dif
void UnshaprMasking_singleCore_gray::calcROI_toCalcDif()
{
	unsigned int height = mSharpImage.size().height;
	unsigned int width = mSharpImage.size().width;

	unsigned int startX = mParaUM.getCompareInPercent() * width / 100.0;
	unsigned int startY = mParaUM.getCompareInPercent() * height / 100.0;
	unsigned int heighttROI = height - 2 * startY;
	unsigned int widthROI = width - 2 * startX;

	mRoiToCalcDif.x = startX;
	mRoiToCalcDif.y = startY;
	mRoiToCalcDif.width = widthROI;
	mRoiToCalcDif.height = heighttROI;
}

void UnshaprMasking_singleCore_gray::improveImageQuality_unsharpMask_gray(const cv::Mat& sharpImage, const cv::Mat& blueredImage)
{
	mSharpImage = sharpImage.clone();
	mBlueredImage = blueredImage.clone();

	// normalize images
	cv::normalize(mSharpImage, mSharpImage, 0.0, 255.0, cv::NORM_MINMAX, CV_8UC1);
	cv::normalize(mBlueredImage, mBlueredImage, 0.0, 255.0, cv::NORM_MINMAX, CV_8UC1);

	// calc roi to calc dif
	calcROI_toCalcDif();

	// find best parameter and save
	findBestParameter();
}

void UnshaprMasking_singleCore_gray::findBestParameter()
{
	real tempDifference{};
	real tempBestDifference = oftenUse::getInfReal();
	real tempImprovement = -1.0 * oftenUse::getInfReal();
	real tempBestImprovement = -1.0 * oftenUse::getInfReal();

	real tempSigma = mParaUM.getMinSigma();
	real tempThreshold = mParaUM.getMinThreshold();
	real tempAmount = mParaUM.getMinAmount();

	real deltaSigma = (mParaUM.getMaxSigma() - mParaUM.getMinSigma()) / mParaUM.getStepsSigma();
	real deltaThreshold = (mParaUM.getMaxThreshold() - mParaUM.getMinThreshold()) / mParaUM.getStepsThreshold();
	real deltaAmount = (mParaUM.getMaxAmount() - mParaUM.getMinAmount()) / mParaUM.getStepsAmount();
	
	SharpnessEvaluation SharpEval;
	real tempSharpness = -1.0 * oftenUse::getInfReal();
	real tempBestSharpness = -1.0 * oftenUse::getInfReal();

	while (tempSigma <= mParaUM.getMaxSigma())
	{
		while (tempThreshold <= mParaUM.getMaxThreshold())
		{
			while (tempAmount <= mParaUM.getMaxAmount())
			{
				unsharpMasking(tempSigma, tempThreshold, tempAmount);
				cv::normalize(mTempFilterdImage, mTempFilterdImage, 0.0, 255.0, cv::NORM_MINMAX, CV_8UC1);

				tempImprovement = Images::calcImprovementGray(mSharpImage, mBlueredImage, mTempFilterdImage, mParaUM.getCompareInPercent());

				// calculate difference sharp and filterd image
				if (mParaUM.getSharpnessEvalMethode() == sharpnessEvalMethode::sharpImage)
				{
					

					if (tempImprovement > tempBestImprovement)
					{
						tempBestImprovement = tempImprovement;

						// calculate difference sharp and filterd image
						tempDifference = calcAbsDifGrayImage_uni8(mSharpImage, mTempFilterdImage);
						
						mBestResult_unsharpMaskStruct.setImage(mTempFilterdImage.clone());
						mBestResult_unsharpMaskStruct.setDifference(tempDifference);
						mBestResult_unsharpMaskStruct.setSigma(tempSigma);
						mBestResult_unsharpMaskStruct.setAmount(tempAmount);
						mBestResult_unsharpMaskStruct.setThreshold(tempThreshold);
						mBestResult_unsharpMaskStruct.setBoarderType(mParaUM.getBoarderType());

						// debug
						//std::cout << "improvement: " << improvement << std::endl;
						mBestResult_unsharpMaskStruct.setImprovement(tempImprovement);

						//if (improvement_blue > 1)
						//{
						//	// debug -> save temp best filtered image
						//	std::string locationTest7 = "../tests/testImproveImageQuality/WienerDeconvolution/s7";
						//	std::string numberString = std::to_string(counter_blue);
						//	std::string nameNum = "blue_" + numberString;
						//	Images::saveImageGray_UN8_normByROI_percent(locationTest7, nameNum, "png", mFilterResultIma_blue, mParaImaImproveWD_blue.getCompareInPercent());
						//	++counter_blue;
						//}


					}
				}
			
				else if(mParaUM.getSharpnessEvalMethode() != sharpnessEvalMethode::sharpImage)
				{
					tempSharpness = SharpEval.calculateSharpness_superFct(mParaUM.getSharpnessEvalMethode(), mTempFilterdImage.clone());

					if (tempSharpness > tempBestSharpness)
					{
						tempBestSharpness = tempSharpness;

						mBestResult_unsharpMaskStruct.setImage(mTempFilterdImage.clone());
					
						mBestResult_unsharpMaskStruct.setSigma(tempSigma);
						mBestResult_unsharpMaskStruct.setAmount(tempAmount);
						mBestResult_unsharpMaskStruct.setThreshold(tempThreshold);
						mBestResult_unsharpMaskStruct.setBoarderType(mParaUM.getBoarderType());
						
						tempDifference = calcAbsDifGrayImage_uni8(mSharpImage, mTempFilterdImage);
						mBestResult_unsharpMaskStruct.setDifference(tempDifference);
						//// debug
						//std::string typeSharpIma = Images::getTypeImageC_VMat(mImageSharp_blue);
						//std::string typeBlueredIma = Images::getTypeImageC_VMat(mBluredIma_blue);
						//std::string typeFilteredIma = Images::getTypeImageC_VMat(mFilterResultIma_blue);

						//////// debug
						//Images::showImage_inputUint8("sharpIma", mImageSharp_blue);
						//Images::showImage_inputUint8("filtered mage", mFilterResultIma_blue);

						// debug
						// std::cout << "improvement: " << improvement << std::endl;
						mBestResult_unsharpMaskStruct.setImprovement(tempImprovement);

						// sharpness
						mBestResult_unsharpMaskStruct.setSharpness(tempSharpness);
					}
				}


			tempAmount = tempAmount + deltaAmount;
	 
			}

			tempAmount = mParaUM.getMinAmount();
			tempThreshold = tempThreshold + deltaThreshold;
		}

		tempAmount = mParaUM.getMinAmount();
		tempThreshold = mParaUM.getMinThreshold();
		tempSigma = tempSigma + deltaSigma;
	
	}

	// check improvement
	if ((mParaUM.getSharpnessEvalMethode() == sharpnessEvalMethode::sharpImage))
	{
		if (mBestResult_unsharpMaskStruct.getImprovement() <= 1.0)
		{
			mBestResult_unsharpMaskStruct.setImage(mBlueredImage.clone());
			mBestResult_unsharpMaskStruct.setImprovement(1.0);
		}
	}


}


unsharpMasking_BGR_parallel::unsharpMasking_BGR_parallel() {}

unsharpMasking_BGR_parallel::~unsharpMasking_BGR_parallel() {}


void unsharpMasking_BGR_parallel::setParameterUM_blue(parameterUnsharpMasking paraUM_blue)
{
	mParaUM_Global_blue = paraUM_blue;
}
void unsharpMasking_BGR_parallel::setParameterUM_green(parameterUnsharpMasking paraUM_green)
{
	mParaUM_Global_green = paraUM_green;
}
void unsharpMasking_BGR_parallel::setParameterUM_red(parameterUnsharpMasking paraUM_red)
{
	mParaUM_Global_red = paraUM_red;
}

void unsharpMasking_BGR_parallel::initializePrameterDifCores_blue()
{
	int boarderTypeGlobal_blue = mParaUM_Global_blue.getBoarderType();
	mParaUM_blue_1.setBoarderType(boarderTypeGlobal_blue);
	mParaUM_blue_2.setBoarderType(boarderTypeGlobal_blue);
	mParaUM_blue_3.setBoarderType(boarderTypeGlobal_blue);
	mParaUM_blue_4.setBoarderType(boarderTypeGlobal_blue);
	mParaUM_blue_5.setBoarderType(boarderTypeGlobal_blue);
	mParaUM_blue_6.setBoarderType(boarderTypeGlobal_blue);
	mParaUM_blue_7.setBoarderType(boarderTypeGlobal_blue);
	mParaUM_blue_8.setBoarderType(boarderTypeGlobal_blue);

	real compareInPercent_blue = mParaUM_Global_blue.getCompareInPercent();
	mParaUM_blue_1.setCompareInPercent(compareInPercent_blue);
	mParaUM_blue_2.setCompareInPercent(compareInPercent_blue);
	mParaUM_blue_3.setCompareInPercent(compareInPercent_blue);
	mParaUM_blue_4.setCompareInPercent(compareInPercent_blue);
	mParaUM_blue_5.setCompareInPercent(compareInPercent_blue);
	mParaUM_blue_6.setCompareInPercent(compareInPercent_blue);
	mParaUM_blue_7.setCompareInPercent(compareInPercent_blue);
	mParaUM_blue_8.setCompareInPercent(compareInPercent_blue);

	// sharpness evaluation methode
	sharpnessEvalMethode sharpnessEvalMethode = mParaUM_Global_blue.getSharpnessEvalMethode();
	mParaUM_blue_1.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_blue_2.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_blue_3.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_blue_4.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_blue_5.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_blue_6.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_blue_7.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_blue_8.setSharpnessEvalMethode(sharpnessEvalMethode);

	// numer of cores
	int numberCores = 8;


	// sigma
	real minSigmaGlobal = mParaUM_Global_blue.getMinSigma();
	real maxSigmaGlobal = mParaUM_Global_blue.getMaxSigma();
	real stepsPerCoreSigma = mParaUM_Global_blue.getStepsSigma() / numberCores;

	// amount
	real minAmountGlobal = mParaUM_Global_blue.getMinAmount();
	real maxAmountGlobal = mParaUM_Global_blue.getMaxAmount();
	real stepsPerCoreAmount = mParaUM_Global_blue.getStepsAmount() / numberCores;

	// threshold
	real minThresholdGlobal = mParaUM_Global_blue.getMinThreshold();
	real maxThrasholdGlobal = mParaUM_Global_blue.getMaxThreshold();
	real stepsPerCoreThreshold = mParaUM_Global_blue.getStepsThreshold() / numberCores;

	// set steps per core sigma
	mParaUM_blue_1.setStepsSigma(stepsPerCoreSigma);
	mParaUM_blue_2.setStepsSigma(stepsPerCoreSigma);
	mParaUM_blue_3.setStepsSigma(stepsPerCoreSigma);
	mParaUM_blue_4.setStepsSigma(stepsPerCoreSigma);
	mParaUM_blue_5.setStepsSigma(stepsPerCoreSigma);
	mParaUM_blue_6.setStepsSigma(stepsPerCoreSigma);
	mParaUM_blue_7.setStepsSigma(stepsPerCoreSigma);
	mParaUM_blue_8.setStepsSigma(stepsPerCoreSigma);

	// set steps per core threshold
	mParaUM_blue_1.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_blue_2.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_blue_3.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_blue_4.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_blue_5.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_blue_6.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_blue_7.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_blue_8.setStepsThreshold(stepsPerCoreThreshold);

	// set steps per core amount
	mParaUM_blue_1.setStepsAmount(stepsPerCoreAmount);
	mParaUM_blue_2.setStepsAmount(stepsPerCoreAmount);
	mParaUM_blue_3.setStepsAmount(stepsPerCoreAmount);
	mParaUM_blue_4.setStepsAmount(stepsPerCoreAmount);
	mParaUM_blue_5.setStepsAmount(stepsPerCoreAmount);
	mParaUM_blue_6.setStepsAmount(stepsPerCoreAmount);
	mParaUM_blue_7.setStepsAmount(stepsPerCoreAmount);
	mParaUM_blue_8.setStepsAmount(stepsPerCoreAmount);

	// calc diff sigma per core
	real deltaSigmaGloal = (mParaUM_Global_blue.getMaxSigma() - mParaUM_Global_blue.getMinSigma()) / mParaUM_Global_blue.getStepsSigma();
	real diffPerCoreSigma = deltaSigmaGloal * stepsPerCoreSigma;

	real minSigmaCore_1 = minSigmaGlobal;
	real maxSigmaCore_1 = minSigmaCore_1 + diffPerCoreSigma;
	real minSigmaCore_2 = maxSigmaCore_1;
	real maxSigmaCore_2 = minSigmaCore_2 + diffPerCoreSigma;
	real minSigmaCore_3 = maxSigmaCore_2;
	real maxSigmaCore_3 = minSigmaCore_3 + diffPerCoreSigma;
	real minSigmaCore_4 = maxSigmaCore_3;
	real maxSigmaCore_4 = minSigmaCore_4 + diffPerCoreSigma;
	real minSigmaCore_5 = maxSigmaCore_4;
	real maxSigmaCore_5 = minSigmaCore_5 + diffPerCoreSigma;
	real minSigmaCore_6 = maxSigmaCore_5;
	real maxSigmaCore_6 = minSigmaCore_6 + diffPerCoreSigma;
	real minSigmaCore_7 = maxSigmaCore_6;
	real maxSigmaCore_7 = minSigmaCore_7 + diffPerCoreSigma;
	real minSigmaCore_8 = maxSigmaCore_7;
	real maxSigmaCore_8 = maxSigmaGlobal;


	mParaUM_blue_1.setMinSigma(minSigmaCore_1);
	mParaUM_blue_1.setMaxSigma(maxSigmaCore_1);
	mParaUM_blue_2.setMinSigma(minSigmaCore_2);
	mParaUM_blue_2.setMaxSigma(maxSigmaCore_2);
	mParaUM_blue_3.setMinSigma(minSigmaCore_3);
	mParaUM_blue_3.setMaxSigma(maxSigmaCore_3);
	mParaUM_blue_4.setMinSigma(minSigmaCore_4);
	mParaUM_blue_4.setMaxSigma(maxSigmaCore_4);
	mParaUM_blue_5.setMinSigma(minSigmaCore_5);
	mParaUM_blue_5.setMaxSigma(maxSigmaCore_5);
	mParaUM_blue_6.setMinSigma(minSigmaCore_6);
	mParaUM_blue_6.setMaxSigma(maxSigmaCore_6);
	mParaUM_blue_7.setMinSigma(minSigmaCore_7);
	mParaUM_blue_7.setMaxSigma(maxSigmaCore_7);
	mParaUM_blue_8.setMinSigma(minSigmaCore_8);
	mParaUM_blue_8.setMaxSigma(maxSigmaCore_8);

	// calc diff threshold per core
	real deltaThresholdGloal = (mParaUM_Global_blue.getMaxThreshold() - mParaUM_Global_blue.getMinThreshold()) / mParaUM_Global_blue.getStepsThreshold();
	real diffPerCoreThreshold = deltaThresholdGloal * stepsPerCoreThreshold;

	real minThresholdCore_1 = minThresholdGlobal;
	real maxThresholdCore_1 = minThresholdCore_1 + diffPerCoreThreshold;
	real minThresholdCore_2 = maxThresholdCore_1;
	real maxThresholdCore_2 = minThresholdCore_2 + diffPerCoreThreshold;
	real minThresholdCore_3 = maxThresholdCore_2;
	real maxThresholdCore_3 = minThresholdCore_3 + diffPerCoreThreshold;
	real minThresholdCore_4 = maxThresholdCore_3;
	real maxThresholdCore_4 = minThresholdCore_4 + diffPerCoreThreshold;
	real minThresholdCore_5 = maxThresholdCore_4;
	real maxThresholdCore_5 = minThresholdCore_5 + diffPerCoreThreshold;
	real minThresholdCore_6 = maxThresholdCore_5;
	real maxThresholdCore_6 = minThresholdCore_6 + diffPerCoreThreshold;
	real minThresholdCore_7 = maxThresholdCore_6;
	real maxThresholdCore_7 = minThresholdCore_7 + diffPerCoreThreshold;
	real minThresholdCore_8 = maxThresholdCore_7;
	real maxThresholdCore_8 = maxThrasholdGlobal;


	mParaUM_blue_1.setMinThreshold(minThresholdCore_1);
	mParaUM_blue_1.setMaxThreshold(maxThresholdCore_1);
	mParaUM_blue_2.setMinThreshold(minThresholdCore_2);
	mParaUM_blue_2.setMaxThreshold(maxThresholdCore_2);
	mParaUM_blue_3.setMinThreshold(minThresholdCore_3);
	mParaUM_blue_3.setMaxThreshold(maxThresholdCore_3);
	mParaUM_blue_4.setMinThreshold(minThresholdCore_4);
	mParaUM_blue_4.setMaxThreshold(maxThresholdCore_4);
	mParaUM_blue_5.setMinThreshold(minThresholdCore_5);
	mParaUM_blue_5.setMaxThreshold(maxThresholdCore_5);
	mParaUM_blue_6.setMinThreshold(minThresholdCore_6);
	mParaUM_blue_6.setMaxThreshold(maxThresholdCore_6);
	mParaUM_blue_7.setMinThreshold(minThresholdCore_7);
	mParaUM_blue_7.setMaxThreshold(maxThresholdCore_7);
	mParaUM_blue_8.setMinThreshold(minThresholdCore_8);
	mParaUM_blue_8.setMaxThreshold(maxThresholdCore_8);

	// calc diff Amount per core
	real deltaAmountGloal = (mParaUM_Global_blue.getMaxAmount() - mParaUM_Global_blue.getMinAmount()) / mParaUM_Global_blue.getStepsAmount();
	real diffPerCoreAmount = deltaAmountGloal * stepsPerCoreAmount;

	real minAmountCore_1 = minAmountGlobal;
	real maxAmountCore_1 = minAmountCore_1 + diffPerCoreAmount;
	real minAmountCore_2 = maxAmountCore_1;
	real maxAmountCore_2 = minAmountCore_2 + diffPerCoreAmount;
	real minAmountCore_3 = maxAmountCore_2;
	real maxAmountCore_3 = minAmountCore_3 + diffPerCoreAmount;
	real minAmountCore_4 = maxAmountCore_3;
	real maxAmountCore_4 = minAmountCore_4 + diffPerCoreAmount;
	real minAmountCore_5 = maxAmountCore_4;
	real maxAmountCore_5 = minAmountCore_5 + diffPerCoreAmount;
	real minAmountCore_6 = maxAmountCore_5;
	real maxAmountCore_6 = minAmountCore_6 + diffPerCoreAmount;
	real minAmountCore_7 = maxAmountCore_6;
	real maxAmountCore_7 = minAmountCore_7 + diffPerCoreAmount;
	real minAmountCore_8 = maxAmountCore_7;
	real maxAmountCore_8 = maxAmountGlobal;


	mParaUM_blue_1.setMinAmount(minAmountCore_1);
	mParaUM_blue_1.setMaxAmount(maxAmountCore_1);
	mParaUM_blue_2.setMinAmount(minAmountCore_2);
	mParaUM_blue_2.setMaxAmount(maxAmountCore_2);
	mParaUM_blue_3.setMinAmount(minAmountCore_3);
	mParaUM_blue_3.setMaxAmount(maxAmountCore_3);
	mParaUM_blue_4.setMinAmount(minAmountCore_4);
	mParaUM_blue_4.setMaxAmount(maxAmountCore_4);
	mParaUM_blue_5.setMinAmount(minAmountCore_5);
	mParaUM_blue_5.setMaxAmount(maxAmountCore_5);
	mParaUM_blue_6.setMinAmount(minAmountCore_6);
	mParaUM_blue_6.setMaxAmount(maxAmountCore_6);
	mParaUM_blue_7.setMinAmount(minAmountCore_7);
	mParaUM_blue_7.setMaxAmount(maxAmountCore_7);
	mParaUM_blue_8.setMinAmount(minAmountCore_8);
	mParaUM_blue_8.setMaxAmount(maxAmountCore_8);

	// set parameter
	mUM_singleCore_blue_1.setParameterUM(mParaUM_blue_1);
	mUM_singleCore_blue_2.setParameterUM(mParaUM_blue_2);
	mUM_singleCore_blue_3.setParameterUM(mParaUM_blue_3);
	mUM_singleCore_blue_4.setParameterUM(mParaUM_blue_4);
	mUM_singleCore_blue_5.setParameterUM(mParaUM_blue_5);
	mUM_singleCore_blue_6.setParameterUM(mParaUM_blue_6);
	mUM_singleCore_blue_7.setParameterUM(mParaUM_blue_7);
	mUM_singleCore_blue_8.setParameterUM(mParaUM_blue_8);
}

void unsharpMasking_BGR_parallel::initializePrameterDifCores_green()
{
	int boarderTypeGlobal_green = mParaUM_Global_green.getBoarderType();
	mParaUM_green_1.setBoarderType(boarderTypeGlobal_green);
	mParaUM_green_2.setBoarderType(boarderTypeGlobal_green);
	mParaUM_green_3.setBoarderType(boarderTypeGlobal_green);
	mParaUM_green_4.setBoarderType(boarderTypeGlobal_green);
	mParaUM_green_5.setBoarderType(boarderTypeGlobal_green);
	mParaUM_green_6.setBoarderType(boarderTypeGlobal_green);
	mParaUM_green_7.setBoarderType(boarderTypeGlobal_green);
	mParaUM_green_8.setBoarderType(boarderTypeGlobal_green);

	real compareInPercent_green = mParaUM_Global_green.getCompareInPercent();
	mParaUM_green_1.setCompareInPercent(compareInPercent_green);
	mParaUM_green_2.setCompareInPercent(compareInPercent_green);
	mParaUM_green_3.setCompareInPercent(compareInPercent_green);
	mParaUM_green_4.setCompareInPercent(compareInPercent_green);
	mParaUM_green_5.setCompareInPercent(compareInPercent_green);
	mParaUM_green_6.setCompareInPercent(compareInPercent_green);
	mParaUM_green_7.setCompareInPercent(compareInPercent_green);
	mParaUM_green_8.setCompareInPercent(compareInPercent_green);

	sharpnessEvalMethode sharpnessEvalMethode = mParaUM_Global_green.getSharpnessEvalMethode();
	mParaUM_green_1.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_green_2.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_green_3.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_green_4.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_green_5.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_green_6.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_green_7.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_green_8.setSharpnessEvalMethode(sharpnessEvalMethode);

	// numer of cores
	int numberCores = 8;


	// sigma
	real minSigmaGlobal = mParaUM_Global_green.getMinSigma();
	real maxSigmaGlobal = mParaUM_Global_green.getMaxSigma();
	real stepsPerCoreSigma = mParaUM_Global_green.getStepsSigma() / numberCores;

	// amount
	real minAmountGlobal = mParaUM_Global_green.getMinAmount();
	real maxAmountGlobal = mParaUM_Global_green.getMaxAmount();
	real stepsPerCoreAmount = mParaUM_Global_green.getStepsAmount() / numberCores;

	// threshold
	real minThresholdGlobal = mParaUM_Global_green.getMinThreshold();
	real maxThrasholdGlobal = mParaUM_Global_green.getMaxThreshold();
	real stepsPerCoreThreshold = mParaUM_Global_green.getStepsThreshold() / numberCores;

	// set steps per core sigma
	mParaUM_green_1.setStepsSigma(stepsPerCoreSigma);
	mParaUM_green_2.setStepsSigma(stepsPerCoreSigma);
	mParaUM_green_3.setStepsSigma(stepsPerCoreSigma);
	mParaUM_green_4.setStepsSigma(stepsPerCoreSigma);
	mParaUM_green_5.setStepsSigma(stepsPerCoreSigma);
	mParaUM_green_6.setStepsSigma(stepsPerCoreSigma);
	mParaUM_green_7.setStepsSigma(stepsPerCoreSigma);
	mParaUM_green_8.setStepsSigma(stepsPerCoreSigma);

	// set steps per core threshold
	mParaUM_green_1.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_green_2.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_green_3.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_green_4.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_green_5.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_green_6.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_green_7.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_green_8.setStepsThreshold(stepsPerCoreThreshold);

	// set steps per core amount
	mParaUM_green_1.setStepsAmount(stepsPerCoreAmount);
	mParaUM_green_2.setStepsAmount(stepsPerCoreAmount);
	mParaUM_green_3.setStepsAmount(stepsPerCoreAmount);
	mParaUM_green_4.setStepsAmount(stepsPerCoreAmount);
	mParaUM_green_5.setStepsAmount(stepsPerCoreAmount);
	mParaUM_green_6.setStepsAmount(stepsPerCoreAmount);
	mParaUM_green_7.setStepsAmount(stepsPerCoreAmount);
	mParaUM_green_8.setStepsAmount(stepsPerCoreAmount);

	// calc diff sigma per core
	real deltaSigmaGloal = (mParaUM_Global_green.getMaxSigma() - mParaUM_Global_green.getMinSigma()) / mParaUM_Global_green.getStepsSigma();
	real diffPerCoreSigma = deltaSigmaGloal * stepsPerCoreSigma;

	real minSigmaCore_1 = minSigmaGlobal;
	real maxSigmaCore_1 = minSigmaCore_1 + diffPerCoreSigma;
	real minSigmaCore_2 = maxSigmaCore_1;
	real maxSigmaCore_2 = minSigmaCore_2 + diffPerCoreSigma;
	real minSigmaCore_3 = maxSigmaCore_2;
	real maxSigmaCore_3 = minSigmaCore_3 + diffPerCoreSigma;
	real minSigmaCore_4 = maxSigmaCore_3;
	real maxSigmaCore_4 = minSigmaCore_4 + diffPerCoreSigma;
	real minSigmaCore_5 = maxSigmaCore_4;
	real maxSigmaCore_5 = minSigmaCore_5 + diffPerCoreSigma;
	real minSigmaCore_6 = maxSigmaCore_5;
	real maxSigmaCore_6 = minSigmaCore_6 + diffPerCoreSigma;
	real minSigmaCore_7 = maxSigmaCore_6;
	real maxSigmaCore_7 = minSigmaCore_7 + diffPerCoreSigma;
	real minSigmaCore_8 = maxSigmaCore_7;
	real maxSigmaCore_8 = maxSigmaGlobal;


	mParaUM_green_1.setMinSigma(minSigmaCore_1);
	mParaUM_green_1.setMaxSigma(maxSigmaCore_1);
	mParaUM_green_2.setMinSigma(minSigmaCore_2);
	mParaUM_green_2.setMaxSigma(maxSigmaCore_2);
	mParaUM_green_3.setMinSigma(minSigmaCore_3);
	mParaUM_green_3.setMaxSigma(maxSigmaCore_3);
	mParaUM_green_4.setMinSigma(minSigmaCore_4);
	mParaUM_green_4.setMaxSigma(maxSigmaCore_4);
	mParaUM_green_5.setMinSigma(minSigmaCore_5);
	mParaUM_green_5.setMaxSigma(maxSigmaCore_5);
	mParaUM_green_6.setMinSigma(minSigmaCore_6);
	mParaUM_green_6.setMaxSigma(maxSigmaCore_6);
	mParaUM_green_7.setMinSigma(minSigmaCore_7);
	mParaUM_green_7.setMaxSigma(maxSigmaCore_7);
	mParaUM_green_8.setMinSigma(minSigmaCore_8);
	mParaUM_green_8.setMaxSigma(maxSigmaCore_8);

	// calc diff threshold per core
	real deltaThresholdGloal = (mParaUM_Global_green.getMaxThreshold() - mParaUM_Global_green.getMinThreshold()) / mParaUM_Global_green.getStepsThreshold();
	real diffPerCoreThreshold = deltaThresholdGloal * stepsPerCoreThreshold;

	real minThresholdCore_1 = minThresholdGlobal;
	real maxThresholdCore_1 = minThresholdCore_1 + diffPerCoreThreshold;
	real minThresholdCore_2 = maxThresholdCore_1;
	real maxThresholdCore_2 = minThresholdCore_2 + diffPerCoreThreshold;
	real minThresholdCore_3 = maxThresholdCore_2;
	real maxThresholdCore_3 = minThresholdCore_3 + diffPerCoreThreshold;
	real minThresholdCore_4 = maxThresholdCore_3;
	real maxThresholdCore_4 = minThresholdCore_4 + diffPerCoreThreshold;
	real minThresholdCore_5 = maxThresholdCore_4;
	real maxThresholdCore_5 = minThresholdCore_5 + diffPerCoreThreshold;
	real minThresholdCore_6 = maxThresholdCore_5;
	real maxThresholdCore_6 = minThresholdCore_6 + diffPerCoreThreshold;
	real minThresholdCore_7 = maxThresholdCore_6;
	real maxThresholdCore_7 = minThresholdCore_7 + diffPerCoreThreshold;
	real minThresholdCore_8 = maxThresholdCore_7;
	real maxThresholdCore_8 = maxThrasholdGlobal;


	mParaUM_green_1.setMinThreshold(minThresholdCore_1);
	mParaUM_green_1.setMaxThreshold(maxThresholdCore_1);
	mParaUM_green_2.setMinThreshold(minThresholdCore_2);
	mParaUM_green_2.setMaxThreshold(maxThresholdCore_2);
	mParaUM_green_3.setMinThreshold(minThresholdCore_3);
	mParaUM_green_3.setMaxThreshold(maxThresholdCore_3);
	mParaUM_green_4.setMinThreshold(minThresholdCore_4);
	mParaUM_green_4.setMaxThreshold(maxThresholdCore_4);
	mParaUM_green_5.setMinThreshold(minThresholdCore_5);
	mParaUM_green_5.setMaxThreshold(maxThresholdCore_5);
	mParaUM_green_6.setMinThreshold(minThresholdCore_6);
	mParaUM_green_6.setMaxThreshold(maxThresholdCore_6);
	mParaUM_green_7.setMinThreshold(minThresholdCore_7);
	mParaUM_green_7.setMaxThreshold(maxThresholdCore_7);
	mParaUM_green_8.setMinThreshold(minThresholdCore_8);
	mParaUM_green_8.setMaxThreshold(maxThresholdCore_8);

	// calc diff Amount per core
	real deltaAmountGloal = (mParaUM_Global_green.getMaxAmount() - mParaUM_Global_green.getMinAmount()) / mParaUM_Global_green.getStepsAmount();
	real diffPerCoreAmount = deltaAmountGloal * stepsPerCoreAmount;

	real minAmountCore_1 = minAmountGlobal;
	real maxAmountCore_1 = minAmountCore_1 + diffPerCoreAmount;
	real minAmountCore_2 = maxAmountCore_1;
	real maxAmountCore_2 = minAmountCore_2 + diffPerCoreAmount;
	real minAmountCore_3 = maxAmountCore_2;
	real maxAmountCore_3 = minAmountCore_3 + diffPerCoreAmount;
	real minAmountCore_4 = maxAmountCore_3;
	real maxAmountCore_4 = minAmountCore_4 + diffPerCoreAmount;
	real minAmountCore_5 = maxAmountCore_4;
	real maxAmountCore_5 = minAmountCore_5 + diffPerCoreAmount;
	real minAmountCore_6 = maxAmountCore_5;
	real maxAmountCore_6 = minAmountCore_6 + diffPerCoreAmount;
	real minAmountCore_7 = maxAmountCore_6;
	real maxAmountCore_7 = minAmountCore_7 + diffPerCoreAmount;
	real minAmountCore_8 = maxAmountCore_7;
	real maxAmountCore_8 = maxAmountGlobal;


	mParaUM_green_1.setMinAmount(minAmountCore_1);
	mParaUM_green_1.setMaxAmount(maxAmountCore_1);
	mParaUM_green_2.setMinAmount(minAmountCore_2);
	mParaUM_green_2.setMaxAmount(maxAmountCore_2);
	mParaUM_green_3.setMinAmount(minAmountCore_3);
	mParaUM_green_3.setMaxAmount(maxAmountCore_3);
	mParaUM_green_4.setMinAmount(minAmountCore_4);
	mParaUM_green_4.setMaxAmount(maxAmountCore_4);
	mParaUM_green_5.setMinAmount(minAmountCore_5);
	mParaUM_green_5.setMaxAmount(maxAmountCore_5);
	mParaUM_green_6.setMinAmount(minAmountCore_6);
	mParaUM_green_6.setMaxAmount(maxAmountCore_6);
	mParaUM_green_7.setMinAmount(minAmountCore_7);
	mParaUM_green_7.setMaxAmount(maxAmountCore_7);
	mParaUM_green_8.setMinAmount(minAmountCore_8);
	mParaUM_green_8.setMaxAmount(maxAmountCore_8);

	// set parameter
	mUM_singleCore_green_1.setParameterUM(mParaUM_green_1);
	mUM_singleCore_green_2.setParameterUM(mParaUM_green_2);
	mUM_singleCore_green_3.setParameterUM(mParaUM_green_3);
	mUM_singleCore_green_4.setParameterUM(mParaUM_green_4);
	mUM_singleCore_green_5.setParameterUM(mParaUM_green_5);
	mUM_singleCore_green_6.setParameterUM(mParaUM_green_6);
	mUM_singleCore_green_7.setParameterUM(mParaUM_green_7);
	mUM_singleCore_green_8.setParameterUM(mParaUM_green_8);
}

void unsharpMasking_BGR_parallel::initializePrameterDifCores_red()
{
	int boarderTypeGlobal_red = mParaUM_Global_red.getBoarderType();
	mParaUM_red_1.setBoarderType(boarderTypeGlobal_red);
	mParaUM_red_2.setBoarderType(boarderTypeGlobal_red);
	mParaUM_red_3.setBoarderType(boarderTypeGlobal_red);
	mParaUM_red_4.setBoarderType(boarderTypeGlobal_red);
	mParaUM_red_5.setBoarderType(boarderTypeGlobal_red);
	mParaUM_red_6.setBoarderType(boarderTypeGlobal_red);
	mParaUM_red_7.setBoarderType(boarderTypeGlobal_red);
	mParaUM_red_8.setBoarderType(boarderTypeGlobal_red);

	real compareInPercent_red = mParaUM_Global_red.getCompareInPercent();
	mParaUM_red_1.setCompareInPercent(compareInPercent_red);
	mParaUM_red_2.setCompareInPercent(compareInPercent_red);
	mParaUM_red_3.setCompareInPercent(compareInPercent_red);
	mParaUM_red_4.setCompareInPercent(compareInPercent_red);
	mParaUM_red_5.setCompareInPercent(compareInPercent_red);
	mParaUM_red_6.setCompareInPercent(compareInPercent_red);
	mParaUM_red_7.setCompareInPercent(compareInPercent_red);
	mParaUM_red_8.setCompareInPercent(compareInPercent_red);

	sharpnessEvalMethode sharpnessEvalMethode = mParaUM_Global_red.getSharpnessEvalMethode();
	mParaUM_red_1.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_red_2.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_red_3.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_red_4.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_red_5.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_red_6.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_red_7.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_red_8.setSharpnessEvalMethode(sharpnessEvalMethode);

	// numer of cores
	int numberCores = 8;


	// sigma
	real minSigmaGlobal = mParaUM_Global_red.getMinSigma();
	real maxSigmaGlobal = mParaUM_Global_red.getMaxSigma();
	real stepsPerCoreSigma = mParaUM_Global_red.getStepsSigma() / numberCores;

	// amount
	real minAmountGlobal = mParaUM_Global_red.getMinAmount();
	real maxAmountGlobal = mParaUM_Global_red.getMaxAmount();
	real stepsPerCoreAmount = mParaUM_Global_red.getStepsAmount() / numberCores;

	// threshold
	real minThresholdGlobal = mParaUM_Global_red.getMinThreshold();
	real maxThrasholdGlobal = mParaUM_Global_red.getMaxThreshold();
	real stepsPerCoreThreshold = mParaUM_Global_red.getStepsThreshold() / numberCores;

	// set steps per core sigma
	mParaUM_red_1.setStepsSigma(stepsPerCoreSigma);
	mParaUM_red_2.setStepsSigma(stepsPerCoreSigma);
	mParaUM_red_3.setStepsSigma(stepsPerCoreSigma);
	mParaUM_red_4.setStepsSigma(stepsPerCoreSigma);
	mParaUM_red_5.setStepsSigma(stepsPerCoreSigma);
	mParaUM_red_6.setStepsSigma(stepsPerCoreSigma);
	mParaUM_red_7.setStepsSigma(stepsPerCoreSigma);
	mParaUM_red_8.setStepsSigma(stepsPerCoreSigma);

	// set steps per core threshold
	mParaUM_red_1.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_red_2.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_red_3.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_red_4.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_red_5.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_red_6.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_red_7.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_red_8.setStepsThreshold(stepsPerCoreThreshold);

	// set steps per core amount
	mParaUM_red_1.setStepsAmount(stepsPerCoreAmount);
	mParaUM_red_2.setStepsAmount(stepsPerCoreAmount);
	mParaUM_red_3.setStepsAmount(stepsPerCoreAmount);
	mParaUM_red_4.setStepsAmount(stepsPerCoreAmount);
	mParaUM_red_5.setStepsAmount(stepsPerCoreAmount);
	mParaUM_red_6.setStepsAmount(stepsPerCoreAmount);
	mParaUM_red_7.setStepsAmount(stepsPerCoreAmount);
	mParaUM_red_8.setStepsAmount(stepsPerCoreAmount);

	// calc diff sigma per core
	real deltaSigmaGloal = (mParaUM_Global_red.getMaxSigma() - mParaUM_Global_red.getMinSigma()) / mParaUM_Global_red.getStepsSigma();
	real diffPerCoreSigma = deltaSigmaGloal * stepsPerCoreSigma;

	real minSigmaCore_1 = minSigmaGlobal;
	real maxSigmaCore_1 = minSigmaCore_1 + diffPerCoreSigma;
	real minSigmaCore_2 = maxSigmaCore_1;
	real maxSigmaCore_2 = minSigmaCore_2 + diffPerCoreSigma;
	real minSigmaCore_3 = maxSigmaCore_2;
	real maxSigmaCore_3 = minSigmaCore_3 + diffPerCoreSigma;
	real minSigmaCore_4 = maxSigmaCore_3;
	real maxSigmaCore_4 = minSigmaCore_4 + diffPerCoreSigma;
	real minSigmaCore_5 = maxSigmaCore_4;
	real maxSigmaCore_5 = minSigmaCore_5 + diffPerCoreSigma;
	real minSigmaCore_6 = maxSigmaCore_5;
	real maxSigmaCore_6 = minSigmaCore_6 + diffPerCoreSigma;
	real minSigmaCore_7 = maxSigmaCore_6;
	real maxSigmaCore_7 = minSigmaCore_7 + diffPerCoreSigma;
	real minSigmaCore_8 = maxSigmaCore_7;
	real maxSigmaCore_8 = maxSigmaGlobal;


	mParaUM_red_1.setMinSigma(minSigmaCore_1);
	mParaUM_red_1.setMaxSigma(maxSigmaCore_1);
	mParaUM_red_2.setMinSigma(minSigmaCore_2);
	mParaUM_red_2.setMaxSigma(maxSigmaCore_2);
	mParaUM_red_3.setMinSigma(minSigmaCore_3);
	mParaUM_red_3.setMaxSigma(maxSigmaCore_3);
	mParaUM_red_4.setMinSigma(minSigmaCore_4);
	mParaUM_red_4.setMaxSigma(maxSigmaCore_4);
	mParaUM_red_5.setMinSigma(minSigmaCore_5);
	mParaUM_red_5.setMaxSigma(maxSigmaCore_5);
	mParaUM_red_6.setMinSigma(minSigmaCore_6);
	mParaUM_red_6.setMaxSigma(maxSigmaCore_6);
	mParaUM_red_7.setMinSigma(minSigmaCore_7);
	mParaUM_red_7.setMaxSigma(maxSigmaCore_7);
	mParaUM_red_8.setMinSigma(minSigmaCore_8);
	mParaUM_red_8.setMaxSigma(maxSigmaCore_8);

	// calc diff threshold per core
	real deltaThresholdGloal = (mParaUM_Global_red.getMaxThreshold() - mParaUM_Global_red.getMinThreshold()) / mParaUM_Global_red.getStepsThreshold();
	real diffPerCoreThreshold = deltaThresholdGloal * stepsPerCoreThreshold;

	real minThresholdCore_1 = minThresholdGlobal;
	real maxThresholdCore_1 = minThresholdCore_1 + diffPerCoreThreshold;
	real minThresholdCore_2 = maxThresholdCore_1;
	real maxThresholdCore_2 = minThresholdCore_2 + diffPerCoreThreshold;
	real minThresholdCore_3 = maxThresholdCore_2;
	real maxThresholdCore_3 = minThresholdCore_3 + diffPerCoreThreshold;
	real minThresholdCore_4 = maxThresholdCore_3;
	real maxThresholdCore_4 = minThresholdCore_4 + diffPerCoreThreshold;
	real minThresholdCore_5 = maxThresholdCore_4;
	real maxThresholdCore_5 = minThresholdCore_5 + diffPerCoreThreshold;
	real minThresholdCore_6 = maxThresholdCore_5;
	real maxThresholdCore_6 = minThresholdCore_6 + diffPerCoreThreshold;
	real minThresholdCore_7 = maxThresholdCore_6;
	real maxThresholdCore_7 = minThresholdCore_7 + diffPerCoreThreshold;
	real minThresholdCore_8 = maxThresholdCore_7;
	real maxThresholdCore_8 = maxThrasholdGlobal;


	mParaUM_red_1.setMinThreshold(minThresholdCore_1);
	mParaUM_red_1.setMaxThreshold(maxThresholdCore_1);
	mParaUM_red_2.setMinThreshold(minThresholdCore_2);
	mParaUM_red_2.setMaxThreshold(maxThresholdCore_2);
	mParaUM_red_3.setMinThreshold(minThresholdCore_3);
	mParaUM_red_3.setMaxThreshold(maxThresholdCore_3);
	mParaUM_red_4.setMinThreshold(minThresholdCore_4);
	mParaUM_red_4.setMaxThreshold(maxThresholdCore_4);
	mParaUM_red_5.setMinThreshold(minThresholdCore_5);
	mParaUM_red_5.setMaxThreshold(maxThresholdCore_5);
	mParaUM_red_6.setMinThreshold(minThresholdCore_6);
	mParaUM_red_6.setMaxThreshold(maxThresholdCore_6);
	mParaUM_red_7.setMinThreshold(minThresholdCore_7);
	mParaUM_red_7.setMaxThreshold(maxThresholdCore_7);
	mParaUM_red_8.setMinThreshold(minThresholdCore_8);
	mParaUM_red_8.setMaxThreshold(maxThresholdCore_8);

	// calc diff Amount per core
	real deltaAmountGloal = (mParaUM_Global_red.getMaxAmount() - mParaUM_Global_red.getMinAmount()) / mParaUM_Global_red.getStepsAmount();
	real diffPerCoreAmount = deltaAmountGloal * stepsPerCoreAmount;

	real minAmountCore_1 = minAmountGlobal;
	real maxAmountCore_1 = minAmountCore_1 + diffPerCoreAmount;
	real minAmountCore_2 = maxAmountCore_1;
	real maxAmountCore_2 = minAmountCore_2 + diffPerCoreAmount;
	real minAmountCore_3 = maxAmountCore_2;
	real maxAmountCore_3 = minAmountCore_3 + diffPerCoreAmount;
	real minAmountCore_4 = maxAmountCore_3;
	real maxAmountCore_4 = minAmountCore_4 + diffPerCoreAmount;
	real minAmountCore_5 = maxAmountCore_4;
	real maxAmountCore_5 = minAmountCore_5 + diffPerCoreAmount;
	real minAmountCore_6 = maxAmountCore_5;
	real maxAmountCore_6 = minAmountCore_6 + diffPerCoreAmount;
	real minAmountCore_7 = maxAmountCore_6;
	real maxAmountCore_7 = minAmountCore_7 + diffPerCoreAmount;
	real minAmountCore_8 = maxAmountCore_7;
	real maxAmountCore_8 = maxAmountGlobal;


	mParaUM_red_1.setMinAmount(minAmountCore_1);
	mParaUM_red_1.setMaxAmount(maxAmountCore_1);
	mParaUM_red_2.setMinAmount(minAmountCore_2);
	mParaUM_red_2.setMaxAmount(maxAmountCore_2);
	mParaUM_red_3.setMinAmount(minAmountCore_3);
	mParaUM_red_3.setMaxAmount(maxAmountCore_3);
	mParaUM_red_4.setMinAmount(minAmountCore_4);
	mParaUM_red_4.setMaxAmount(maxAmountCore_4);
	mParaUM_red_5.setMinAmount(minAmountCore_5);
	mParaUM_red_5.setMaxAmount(maxAmountCore_5);
	mParaUM_red_6.setMinAmount(minAmountCore_6);
	mParaUM_red_6.setMaxAmount(maxAmountCore_6);
	mParaUM_red_7.setMinAmount(minAmountCore_7);
	mParaUM_red_7.setMaxAmount(maxAmountCore_7);
	mParaUM_red_8.setMinAmount(minAmountCore_8);
	mParaUM_red_8.setMaxAmount(maxAmountCore_8);

	// set parameter
	mUM_singleCore_red_1.setParameterUM(mParaUM_red_1);
	mUM_singleCore_red_2.setParameterUM(mParaUM_red_2);
	mUM_singleCore_red_3.setParameterUM(mParaUM_red_3);
	mUM_singleCore_red_4.setParameterUM(mParaUM_red_4);
	mUM_singleCore_red_5.setParameterUM(mParaUM_red_5);
	mUM_singleCore_red_6.setParameterUM(mParaUM_red_6);
	mUM_singleCore_red_7.setParameterUM(mParaUM_red_7);
	mUM_singleCore_red_8.setParameterUM(mParaUM_red_8);
}

void unsharpMasking_BGR_parallel::splitImagesInBGR()
{
	// sharp image
	cv::Mat channelSharpImage[3];
	cv::split(mSharpImage_BGR, channelSharpImage);
	mSharpImage_blue = channelSharpImage[0];
	mSharpImage_green = channelSharpImage[1];
	mSharpImage_red = channelSharpImage[2];

	// bluered image
	cv::Mat channelBluredImage[3];
	cv::split(mBlueredImage_BGR, channelBluredImage);
	mBlueredImage_blue = channelBluredImage[0];
	mBlueredImage_green = channelBluredImage[1];
	mBlueredImage_red = channelBluredImage[2];
}

void unsharpMasking_BGR_parallel::calcMinMax()
{
	unsigned int height = mSharpImage_BGR.size().height;
	unsigned int width = mSharpImage_BGR.size().width;

	unsigned int startX = mParaUM_Global_blue.getCompareInPercent() * width / 100.0;
	unsigned int startY = mParaUM_Global_blue.getCompareInPercent() * height / 100.0;
	unsigned int heighttROI = height - 2 * startY;
	unsigned int widthROI = width - 2 * startX;
	mMin_blue = oftenUse::getInfInt();
	mMax_blue = 0;
	int temp_blue;
	for (unsigned int x = 0; x < width; ++x)
	{
		for (unsigned int y = 0; y < height; ++y)
		{
			temp_blue = mSharpImage_blue.at<uchar>(y, x);
			if (temp_blue < mMin_blue)
			{
				mMin_blue = temp_blue;
			}

			if (temp_blue > mMax_blue)
			{
				mMax_blue = temp_blue;
			}
		}
	}

	mMin_green = oftenUse::getInfInt();
	mMax_green = 0;
	int temp_green;
	for (unsigned int x = 0; x < width; ++x)
	{
		for (unsigned int y = 0; y < height; ++y)
		{
			temp_green = mSharpImage_green.at<uchar>(y, x);
			if (temp_green < mMin_green)
			{
				mMin_green = temp_green;
			}

			if (temp_green > mMax_green)
			{
				mMax_green = temp_green;
			}
		}
	}

	mMin_red = oftenUse::getInfInt();
	mMax_red = 0;
	int temp_red;
	for (unsigned int x = 0; x < width; ++x)
	{
		for (unsigned int y = 0; y < height; ++y)
		{
			temp_red = mSharpImage_red.at<uchar>(y, x);
			if (temp_red < mMin_red)
			{
				mMin_red = temp_red;
			}

			if (temp_red > mMax_red)
			{
				mMax_red = temp_red;
			}
		}
	}

}

void unsharpMasking_BGR_parallel::putChannlesTogehter()
{
	std::vector<cv::Mat> array_to_merge;

	array_to_merge.push_back(mFilterResultIma_normedSharp_blue);
	array_to_merge.push_back(mFilterResultIma_normedSharp_green);
	array_to_merge.push_back(mFilterResultIma_normedSharp_red);

	cv::merge(array_to_merge, mFilterResultIma_BGR_normedLikeSharpIma);
}

// norm the gray images according to the sharp image
void unsharpMasking_BGR_parallel::normTheGrayImagesAccordingToSharpIma()

{	// blue
	cv::Mat filterResultIma_blue = mBestParameterGlobal_blue.getImage().clone();
	cv::normalize(filterResultIma_blue, mFilterResultIma_normedSharp_blue, mMin_blue, mMax_blue, cv::NORM_MINMAX, CV_8UC1);

	// green
	cv::Mat filterResultIma_green = mBestParameterGlobal_green.getImage().clone();
	cv::normalize(filterResultIma_green, mFilterResultIma_normedSharp_green, mMin_green, mMax_green, cv::NORM_MINMAX, CV_8UC1);

	// red
	cv::Mat filterResultIma_red = mBestParameterGlobal_red.getImage().clone();
	cv::normalize(filterResultIma_red, mFilterResultIma_normedSharp_red, mMin_red, mMax_red, cv::NORM_MINMAX, CV_8UC1);

}

cv::Mat unsharpMasking_BGR_parallel::getFilteredResults_normedLikeSharpIma()
{
	return mFilterResultIma_BGR_normedLikeSharpIma;
}

cv::Mat unsharpMasking_BGR_parallel::getFilteredResults_normedZeroAndMaxUchar()
{
	std::vector<cv::Mat> array_to_merge;
	cv::Mat mFilterResultIma_BGR__normedZeroAndMaxUchar;

	array_to_merge.push_back(mBestParameterGlobal_blue.getImage());
	array_to_merge.push_back(mBestParameterGlobal_green.getImage());
	array_to_merge.push_back(mBestParameterGlobal_red.getImage());

	cv::merge(array_to_merge, mFilterResultIma_BGR__normedZeroAndMaxUchar);

	return mFilterResultIma_BGR__normedZeroAndMaxUchar;
}

bestParameterStruct_unsharpMask unsharpMasking_BGR_parallel::getBestParameter_blue()
{
	return mBestParameterGlobal_blue;
}
bestParameterStruct_unsharpMask unsharpMasking_BGR_parallel::getBestParameter_green()
{
	return mBestParameterGlobal_green;
}
bestParameterStruct_unsharpMask unsharpMasking_BGR_parallel::getBestParameter_red()
{
	return mBestParameterGlobal_red;
}

parameterUnsharpMasking unsharpMasking_BGR_parallel::getInitialPara_blue()
{
	return mParaUM_Global_blue;
}
parameterUnsharpMasking unsharpMasking_BGR_parallel::getInitialPara_green()
{
	return mParaUM_Global_green;
}
parameterUnsharpMasking unsharpMasking_BGR_parallel::getInitialPara_red()
{
	return mParaUM_Global_red;
}

// find best parameter _blue
void unsharpMasking_BGR_parallel::findBestParameterAllCores_blue()
{
	// find best improvement
	real bestImprovement = mUM_singleCore_blue_1.getBestParameter().getImprovement();
	real tempImp;
	real tempSharpness;
	real bestSharpness = -1.0 * oftenUse::getInfReal();
	unsigned int tempBestPosInVec = 0;

	if (mParaUM_Global_blue.getSharpnessEvalMethode() == sharpnessEvalMethode::sharpImage)
	{
		for (unsigned int i = 0; i < mImprovements_vec_blue.size(); ++i)
		{
			tempImp = mImprovements_vec_blue[i];
			// debug
			std::cout << "temp improvement unsharp masking: " << tempImp << " core number: " << i << std::endl;

			if (tempImp > bestImprovement)
			{
				bestImprovement = tempImp;
				tempBestPosInVec = i;
			}
		}
	}

	else if (mParaUM_Global_blue.getSharpnessEvalMethode() != sharpnessEvalMethode::sharpImage)
	{
		for (unsigned int i = 0; i < mSharpness_vec_blue.size(); ++i)
		{
			tempSharpness = mSharpness_vec_blue[i];
			// debug
			std::cout << "temp improvement unsharp masking blue: " << mImprovements_vec_blue[i] << " core number: " << i << std::endl;
			std::cout << "temp sharpness unsharp masking blue: " << tempSharpness << " core number: " << i << std::endl;

			if (tempSharpness > bestSharpness)
			{
				bestSharpness = tempSharpness;
				tempBestPosInVec = i;


			}
		}
	}

	// debug 
	std::cout << " --> best improvement unsharp masking blue: " << mImprovements_vec_blue[tempBestPosInVec] << " core number: " << tempBestPosInVec << std::endl;
	std::cout << " --> best sharpness unsharp makking blue: " << mSharpness_vec_blue[tempBestPosInVec] << " core number: " << tempBestPosInVec << std::endl;

	mBestParameterGlobal_blue = mBestParaUM_vec_blue[tempBestPosInVec];
	mBestParameterGlobal_blue.setBestCoreNumber(tempBestPosInVec);
}

// find best parameter _green
void unsharpMasking_BGR_parallel::findBestParameterAllCores_green()
{
	// find best improvement
	real bestImprovement = mUM_singleCore_green_1.getBestParameter().getImprovement();
	real tempImp;
	real tempSharpness;
	real bestSharpness = -1.0 * oftenUse::getInfReal();
	unsigned int tempBestPosInVec = 0;

	if (mParaUM_Global_green.getSharpnessEvalMethode() == sharpnessEvalMethode::sharpImage)
	{
		for (unsigned int i = 0; i < mImprovements_vec_green.size(); ++i)
		{
			tempImp = mImprovements_vec_green[i];
			// debug
			std::cout << "temp improvement unsharp masking: " << tempImp << " core number: " << i << std::endl;

			if (tempImp > bestImprovement)
			{
				bestImprovement = tempImp;
				tempBestPosInVec = i;
			}
		}
	}

	else if (mParaUM_Global_green.getSharpnessEvalMethode() != sharpnessEvalMethode::sharpImage)
	{
		for (unsigned int i = 0; i < mSharpness_vec_green.size(); ++i)
		{
			tempSharpness = mSharpness_vec_green[i];
			// debug
			std::cout << "temp improvement unsharp masking green: " << mImprovements_vec_green[i] << " core number: " << i << std::endl;
			std::cout << "temp sharpness unsharp masking green: " << tempSharpness << " core number: " << i << std::endl;

			if (tempSharpness > bestSharpness)
			{
				bestSharpness = tempSharpness;
				tempBestPosInVec = i;


			}
		}
	}

	// debug 
	std::cout << " --> best improvement unsharp masking green: " << mImprovements_vec_green[tempBestPosInVec] << " core number: " << tempBestPosInVec << std::endl;
	std::cout << " --> best sharpness unsharp makking green: " << mSharpness_vec_green[tempBestPosInVec] << " core number: " << tempBestPosInVec << std::endl;

	mBestParameterGlobal_green = mBestParaUM_vec_green[tempBestPosInVec];
	mBestParameterGlobal_green.setBestCoreNumber(tempBestPosInVec);
}

// find best parameter _red
void unsharpMasking_BGR_parallel::findBestParameterAllCores_red()
{
	// find best improvement
	real bestImprovement = mUM_singleCore_red_1.getBestParameter().getImprovement();
	real tempImp;
	real tempSharpness;
	real bestSharpness = -1.0 * oftenUse::getInfReal();
	unsigned int tempBestPosInVec = 0;

	if (mParaUM_Global_red.getSharpnessEvalMethode() == sharpnessEvalMethode::sharpImage)
	{
		for (unsigned int i = 0; i < mImprovements_vec_red.size(); ++i)
		{
			tempImp = mImprovements_vec_red[i];
			// debug
			std::cout << "temp improvement unsharp masking: " << tempImp << " core number: " << i << std::endl;

			if (tempImp > bestImprovement)
			{
				bestImprovement = tempImp;
				tempBestPosInVec = i;
			}
		}
	}

	else if (mParaUM_Global_red.getSharpnessEvalMethode() != sharpnessEvalMethode::sharpImage)
	{
		for (unsigned int i = 0; i < mSharpness_vec_red.size(); ++i)
		{
			tempSharpness = mSharpness_vec_red[i];
			// debug
			std::cout << "temp improvement unsharp masking red: " << mImprovements_vec_red[i] << " core number: " << i << std::endl;
			std::cout << "temp sharpness unsharp masking red: " << tempSharpness << " core number: " << i << std::endl;

			if (tempSharpness > bestSharpness)
			{
				bestSharpness = tempSharpness;
				tempBestPosInVec = i;


			}
		}
	}

	// debug 
	std::cout << " --> best improvement unsharp masking red: " << mImprovements_vec_red[tempBestPosInVec] << " core number: " << tempBestPosInVec << std::endl;
	std::cout << " --> best sharpness unsharp makking red: " << mSharpness_vec_red[tempBestPosInVec] << " core number: " << tempBestPosInVec << std::endl;

	mBestParameterGlobal_red = mBestParaUM_vec_red[tempBestPosInVec];
	mBestParameterGlobal_red.setBestCoreNumber(tempBestPosInVec);
}

void unsharpMasking_BGR_parallel::improveImaQual_UnsharpMasking_superFct_BGR_parallel(const cv::Mat sharpBGR_Image, const cv::Mat blueredBGR_Image)
{
	mSharpImage_BGR = sharpBGR_Image.clone();
	mBlueredImage_BGR = blueredBGR_Image.clone();

	// split the image in BGR channels
	splitImagesInBGR();
	// calc min max
	calcMinMax();
	// initialize parameter
	initializePrameterDifCores_blue();
	initializePrameterDifCores_green();
	initializePrameterDifCores_red();

	mImprovements_vec_blue.resize(8);
	mBestParaUM_vec_blue.resize(8);
	mSharpness_vec_blue.resize(8);
	mImprovements_vec_green.resize(8);
	mBestParaUM_vec_green.resize(8);
	mSharpness_vec_green.resize(8);
	mImprovements_vec_red.resize(8);
	mBestParaUM_vec_red.resize(8);
	mSharpness_vec_red.resize(8);

	// find best SNR and Sigma parallel
	findingBestParaUM_BGR_parallel();

	// find best parameter of all cores
	findBestParameterAllCores_blue();
	findBestParameterAllCores_green();
	findBestParameterAllCores_red();

	// norm the gray images
	normTheGrayImagesAccordingToSharpIma();
	// put channels together
	putChannlesTogehter();
}

void unsharpMasking_BGR_parallel::findingBestParaUM_BGR_parallel()
{

omp_set_num_threads(24);
#pragma omp parallel
{
#pragma omp sections
	{
#pragma omp section // _blue_1
		{
			//std::cout << "start core 1" << std::endl;
			mUM_singleCore_blue_1.improveImageQuality_unsharpMask_gray(mSharpImage_blue, mBlueredImage_blue);
			real impCore1 = mUM_singleCore_blue_1.getBestParameter().getImprovement();
			mImprovements_vec_blue[0] = impCore1;
			mSharpness_vec_blue[0] = mUM_singleCore_blue_1.getBestParameter().getSharpness();
			mBestParaUM_vec_blue[0] = mUM_singleCore_blue_1.getBestParameter();
		}
#pragma omp section // _blue_2
		{
			//std::cout << "start core 2" << std::endl;
			mUM_singleCore_blue_2.improveImageQuality_unsharpMask_gray(mSharpImage_blue, mBlueredImage_blue);
			real impCore2 = mUM_singleCore_blue_2.getBestParameter().getImprovement();
			mImprovements_vec_blue[1] = impCore2;
			mSharpness_vec_blue[1] = mUM_singleCore_blue_2.getBestParameter().getSharpness();
			mBestParaUM_vec_blue[1] = mUM_singleCore_blue_2.getBestParameter();
		}
#pragma omp section // _blue_3
		{
			//std::cout << "start core 3" << std::endl;
			mUM_singleCore_blue_3.improveImageQuality_unsharpMask_gray(mSharpImage_blue, mBlueredImage_blue);
			real impCore3 = mUM_singleCore_blue_3.getBestParameter().getImprovement();
			mImprovements_vec_blue[2] = impCore3;
			mSharpness_vec_blue[2] = mUM_singleCore_blue_3.getBestParameter().getSharpness();
			mBestParaUM_vec_blue[2] = mUM_singleCore_blue_3.getBestParameter();
		}
#pragma omp section // _blue_4
		{
			//std::cout << "start core 4" << std::endl;
			mUM_singleCore_blue_4.improveImageQuality_unsharpMask_gray(mSharpImage_blue, mBlueredImage_blue);
			real impCore4 = mUM_singleCore_blue_4.getBestParameter().getImprovement();
			mImprovements_vec_blue[3] = impCore4;
			mSharpness_vec_blue[3] = mUM_singleCore_blue_4.getBestParameter().getSharpness();
			mBestParaUM_vec_blue[3] = mUM_singleCore_blue_4.getBestParameter();
		}
#pragma omp section // _blue_5
		{
			//std::cout << "start core 5" << std::endl;
			mUM_singleCore_blue_5.improveImageQuality_unsharpMask_gray(mSharpImage_blue, mBlueredImage_blue);
			real impCore5 = mUM_singleCore_blue_5.getBestParameter().getImprovement();
			mImprovements_vec_blue[4] = impCore5;
			mSharpness_vec_blue[4] = mUM_singleCore_blue_5.getBestParameter().getSharpness();
			mBestParaUM_vec_blue[4] = mUM_singleCore_blue_5.getBestParameter();
		}
#pragma omp section // _blue_6
		{
			//std::cout << "start core 6" << std::endl;
			mUM_singleCore_blue_6.improveImageQuality_unsharpMask_gray(mSharpImage_blue, mBlueredImage_blue);
			real impCore6 = mUM_singleCore_blue_6.getBestParameter().getImprovement();
			mImprovements_vec_blue[5] = impCore6;
			mSharpness_vec_blue[5] = mUM_singleCore_blue_6.getBestParameter().getSharpness();
			mBestParaUM_vec_blue[5] = mUM_singleCore_blue_6.getBestParameter();
		}
#pragma omp section // _blue_7
		{
			//std::cout << "start core 7" << std::endl;
			mUM_singleCore_blue_7.improveImageQuality_unsharpMask_gray(mSharpImage_blue, mBlueredImage_blue);
			real impCore7 = mUM_singleCore_blue_7.getBestParameter().getImprovement();
			mImprovements_vec_blue[6] = impCore7;
			mSharpness_vec_blue[6] = mUM_singleCore_blue_7.getBestParameter().getSharpness();
			mBestParaUM_vec_blue[6] = mUM_singleCore_blue_7.getBestParameter();
		}
#pragma omp section // _blue_8
		{
			//std::cout << "start core 8" << std::endl;
			mUM_singleCore_blue_8.improveImageQuality_unsharpMask_gray(mSharpImage_blue, mBlueredImage_blue);
			real impCore8 = mUM_singleCore_blue_8.getBestParameter().getImprovement();
			mImprovements_vec_blue[7] = impCore8;
			mSharpness_vec_blue[7] = mUM_singleCore_blue_8.getBestParameter().getSharpness();
			mBestParaUM_vec_blue[7] = mUM_singleCore_blue_8.getBestParameter();
		}
#pragma omp section // _green_1
		{
			//std::cout << "start core 9" << std::endl;
			mUM_singleCore_green_1.improveImageQuality_unsharpMask_gray(mSharpImage_green, mBlueredImage_green);
			real impCore1 = mUM_singleCore_green_1.getBestParameter().getImprovement();
			mImprovements_vec_green[0] = impCore1;
			mSharpness_vec_green[0] = mUM_singleCore_green_1.getBestParameter().getSharpness();
			mBestParaUM_vec_green[0] = mUM_singleCore_green_1.getBestParameter();
		}
#pragma omp section // _green_2
		{
			//std::cout << "start core 10" << std::endl;
			mUM_singleCore_green_2.improveImageQuality_unsharpMask_gray(mSharpImage_green, mBlueredImage_green);
			real impCore2 = mUM_singleCore_green_2.getBestParameter().getImprovement();
			mImprovements_vec_green[1] = impCore2;
			mSharpness_vec_green[1] = mUM_singleCore_green_2.getBestParameter().getSharpness();
			mBestParaUM_vec_green[1] = mUM_singleCore_green_2.getBestParameter();
		}
#pragma omp section // _green_3
		{
			//std::cout << "start core 11" << std::endl;
			mUM_singleCore_green_3.improveImageQuality_unsharpMask_gray(mSharpImage_green, mBlueredImage_green);
			real impCore3 = mUM_singleCore_green_3.getBestParameter().getImprovement();
			mImprovements_vec_green[2] = impCore3;
			mSharpness_vec_green[2] = mUM_singleCore_green_3.getBestParameter().getSharpness();
			mBestParaUM_vec_green[2] = mUM_singleCore_green_3.getBestParameter();
		}
#pragma omp section // _green_4
		{
			//std::cout << "start core 12" << std::endl;
			mUM_singleCore_green_4.improveImageQuality_unsharpMask_gray(mSharpImage_green, mBlueredImage_green);
			real impCore4 = mUM_singleCore_green_4.getBestParameter().getImprovement();
			mImprovements_vec_green[3] = impCore4;
			mSharpness_vec_green[3] = mUM_singleCore_green_4.getBestParameter().getSharpness();
			mBestParaUM_vec_green[3] = mUM_singleCore_green_4.getBestParameter();
		}
#pragma omp section // _green_5
		{
			//std::cout << "start core 13" << std::endl;
			mUM_singleCore_green_5.improveImageQuality_unsharpMask_gray(mSharpImage_green, mBlueredImage_green);
			real impCore5 = mUM_singleCore_green_5.getBestParameter().getImprovement();
			mImprovements_vec_green[4] = impCore5;
			mSharpness_vec_green[4] = mUM_singleCore_green_5.getBestParameter().getSharpness();
			mBestParaUM_vec_green[4] = mUM_singleCore_green_5.getBestParameter();
		}
#pragma omp section // _green_6
		{
			//std::cout << "start core 14" << std::endl;
			mUM_singleCore_green_6.improveImageQuality_unsharpMask_gray(mSharpImage_green, mBlueredImage_green);
			real impCore6 = mUM_singleCore_green_6.getBestParameter().getImprovement();
			mImprovements_vec_green[5] = impCore6;
			mSharpness_vec_green[5] = mUM_singleCore_green_6.getBestParameter().getSharpness();
			mBestParaUM_vec_green[5] = mUM_singleCore_green_6.getBestParameter();
		}
#pragma omp section // _green_7
		{
			//std::cout << "start core 15" << std::endl;
			mUM_singleCore_green_7.improveImageQuality_unsharpMask_gray(mSharpImage_green, mBlueredImage_green);
			real impCore7 = mUM_singleCore_green_7.getBestParameter().getImprovement();
			mImprovements_vec_green[6] = impCore7;
			mSharpness_vec_green[6] = mUM_singleCore_green_7.getBestParameter().getSharpness();
			mBestParaUM_vec_green[6] = mUM_singleCore_green_7.getBestParameter();
		}
#pragma omp section // _green_8
		{
			//std::cout << "start core 16" << std::endl;
			mUM_singleCore_green_8.improveImageQuality_unsharpMask_gray(mSharpImage_green, mBlueredImage_green);
			real impCore8 = mUM_singleCore_green_8.getBestParameter().getImprovement();
			mImprovements_vec_green[7] = impCore8;
			mSharpness_vec_green[7] = mUM_singleCore_green_8.getBestParameter().getSharpness();
			mBestParaUM_vec_green[7] = mUM_singleCore_green_8.getBestParameter();
		}
#pragma omp section // _red_1
		{
			//std::cout << "start core 17" << std::endl;
			mUM_singleCore_red_1.improveImageQuality_unsharpMask_gray(mSharpImage_red, mBlueredImage_red);
			real impCore1 = mUM_singleCore_red_1.getBestParameter().getImprovement();
			mImprovements_vec_red[0] = impCore1;
			mSharpness_vec_red[0] = mUM_singleCore_red_1.getBestParameter().getSharpness();
			mBestParaUM_vec_red[0] = mUM_singleCore_red_1.getBestParameter();
		}
#pragma omp section // _red_2
		{
			//std::cout << "start core 18" << std::endl;
			mUM_singleCore_red_2.improveImageQuality_unsharpMask_gray(mSharpImage_red, mBlueredImage_red);
			real impCore2 = mUM_singleCore_red_2.getBestParameter().getImprovement();
			mImprovements_vec_red[1] = impCore2;
			mSharpness_vec_red[1] = mUM_singleCore_red_2.getBestParameter().getSharpness();
			mBestParaUM_vec_red[1] = mUM_singleCore_red_2.getBestParameter();
		}
#pragma omp section // _red_3
		{
			//std::cout << "start core 19" << std::endl;
			mUM_singleCore_red_3.improveImageQuality_unsharpMask_gray(mSharpImage_red, mBlueredImage_red);
			real impCore3 = mUM_singleCore_red_3.getBestParameter().getImprovement();
			mImprovements_vec_red[2] = impCore3;
			mSharpness_vec_red[2] = mUM_singleCore_red_3.getBestParameter().getSharpness();
			mBestParaUM_vec_red[2] = mUM_singleCore_red_3.getBestParameter();
		}
#pragma omp section // _red_4
		{
			//std::cout << "start core 20" << std::endl;
			mUM_singleCore_red_4.improveImageQuality_unsharpMask_gray(mSharpImage_red, mBlueredImage_red);
			real impCore4 = mUM_singleCore_red_4.getBestParameter().getImprovement();
			mImprovements_vec_red[3] = impCore4;
			mSharpness_vec_red[3] = mUM_singleCore_red_4.getBestParameter().getSharpness();
			mBestParaUM_vec_red[3] = mUM_singleCore_red_4.getBestParameter();
		}
#pragma omp section // _red_5
		{
			//std::cout << "start core 21" << std::endl;
			mUM_singleCore_red_5.improveImageQuality_unsharpMask_gray(mSharpImage_red, mBlueredImage_red);
			real impCore5 = mUM_singleCore_red_5.getBestParameter().getImprovement();
			mImprovements_vec_red[4] = impCore5;
			mSharpness_vec_red[4] = mUM_singleCore_red_5.getBestParameter().getSharpness();
			mBestParaUM_vec_red[4] = mUM_singleCore_red_5.getBestParameter();
		}
#pragma omp section // _red_6
		{
			//std::cout << "start core 22" << std::endl;
			mUM_singleCore_red_6.improveImageQuality_unsharpMask_gray(mSharpImage_red, mBlueredImage_red);
			real impCore6 = mUM_singleCore_red_6.getBestParameter().getImprovement();
			mImprovements_vec_red[5] = impCore6;
			mSharpness_vec_red[5] = mUM_singleCore_red_6.getBestParameter().getSharpness();
			mBestParaUM_vec_red[5] = mUM_singleCore_red_6.getBestParameter();
		}
#pragma omp section // _red_7
		{
			//std::cout << "start core 23" << std::endl;
			mUM_singleCore_red_7.improveImageQuality_unsharpMask_gray(mSharpImage_red, mBlueredImage_red);
			real impCore7 = mUM_singleCore_red_7.getBestParameter().getImprovement();
			mImprovements_vec_red[6] = impCore7;
			mSharpness_vec_red[6] = mUM_singleCore_red_7.getBestParameter().getSharpness();
			mBestParaUM_vec_red[6] = mUM_singleCore_red_7.getBestParameter();
		}
#pragma omp section // _red_8
		{
			//std::cout << "start core 24" << std::endl;
			mUM_singleCore_red_8.improveImageQuality_unsharpMask_gray(mSharpImage_red, mBlueredImage_red);
			real impCore8 = mUM_singleCore_red_8.getBestParameter().getImprovement();
			mImprovements_vec_red[7] = impCore8;
			mSharpness_vec_red[7] = mUM_singleCore_red_8.getBestParameter().getSharpness();
			mBestParaUM_vec_red[7] = mUM_singleCore_red_8.getBestParameter();
		}
	}
	}
}


void UnshaprMasking_singleCore_BGR::improveImaQual_UnsharpMasking_superFct_BGR(const cv::Mat sharpBGR_Image, const cv::Mat blueredBGR_Image)
{
	mSharpImage_BGR = sharpBGR_Image;
	mBlueredImage_BGR = blueredBGR_Image;

	// split sharp BGR image
	std::vector<cv::Mat> imagesBGR_sharp_vec = Images::splitImageBGR(mSharpImage_BGR);
	mSharpImage_blue = imagesBGR_sharp_vec[0];
	mSharpImage_green = imagesBGR_sharp_vec[1];
	mSharpImage_red = imagesBGR_sharp_vec[2];

	// split blured BGR image
	std::vector<cv::Mat> imagesBGR_blured_vec = Images::splitImageBGR(mBlueredImage_BGR);
	mBlueredImage_blue = imagesBGR_blured_vec[0];
	mBlueredImage_green = imagesBGR_blured_vec[1];
	mBlueredImage_red = imagesBGR_blured_vec[2];

	// calc min max sharp image
	calcMinMax();

	mUM_blue.setParameterUM(mParaUM_Global_blue);
	mUM_green.setParameterUM(mParaUM_Global_green);
	mUM_red.setParameterUM(mParaUM_Global_red);
	
	mUM_blue.improveImageQuality_unsharpMask_gray(mSharpImage_blue, mBlueredImage_blue);
	mUM_green.improveImageQuality_unsharpMask_gray(mSharpImage_green, mBlueredImage_green);
	mUM_red.improveImageQuality_unsharpMask_gray(mSharpImage_red, mBlueredImage_red);

	mBestParaUM_blue = mUM_blue.getBestParameter();
	mBestParaUM_green = mUM_green.getBestParameter();
	mBestParaUM_red = mUM_red.getBestParameter();


	// norm the gray images
	normTheGrayImagesAccordingToSharpIma();
	// put channels to BGR image together
	putChannlesTogehter();
}


// calc min max sharp images
void UnshaprMasking_singleCore_BGR::calcMinMax()
{
	unsigned int height = mSharpImage_BGR.size().height;
	unsigned int width = mSharpImage_BGR.size().width;
	
	unsigned int startX = mParaUM_Global_blue.getCompareInPercent() * width / 100.0;
	unsigned int startY = mParaUM_Global_blue.getCompareInPercent() * height / 100.0;
	unsigned int heighttROI = height - 2 * startY;
	unsigned int widthROI = width - 2 * startX;
	mMin_blue = oftenUse::getInfInt();
	mMax_blue = 0;
	int temp_blue;
	for (unsigned int x = 0; x < width; ++x)
	{
		for (unsigned int y = 0; y < height; ++y)
		{
			temp_blue = mSharpImage_blue.at<uchar>(y, x);
			if (temp_blue < mMin_blue)
			{
				mMin_blue = temp_blue;
			}
	
			if (temp_blue > mMax_blue)
			{
				mMax_blue = temp_blue;
			}
		}
	}
	
	mMin_green = oftenUse::getInfInt();
	mMax_green = 0;
	int temp_green;
	for (unsigned int x = 0; x < width; ++x)
	{
		for (unsigned int y = 0; y < height; ++y)
		{
			temp_green = mSharpImage_green.at<uchar>(y, x);
			if (temp_green < mMin_green)
			{
				mMin_green = temp_green;
			}
	
			if (temp_green > mMax_green)
			{
				mMax_green = temp_green;
			}
		}
	}
	
	mMin_red = oftenUse::getInfInt();
	mMax_red = 0;
	int temp_red;
	for (unsigned int x = 0; x < width; ++x)
	{
		for (unsigned int y = 0; y < height; ++y)
		{
			temp_red = mSharpImage_red.at<uchar>(y, x);
			if (temp_red < mMin_red)
			{
				mMin_red = temp_red;
			}

			if (temp_red > mMax_red)
			{
				mMax_red = temp_red;
			}
		}
	}
}

// set parameter 
void UnshaprMasking_singleCore_BGR::setParameterUM_blue(parameterUnsharpMasking paraUM_blue)
{
	mParaUM_Global_blue = paraUM_blue;
}
void UnshaprMasking_singleCore_BGR::setParameterUM_green(parameterUnsharpMasking paraUM_green)
{
	mParaUM_Global_green = paraUM_green;
}
void UnshaprMasking_singleCore_BGR::setParameterUM_red(parameterUnsharpMasking paraUM_red)
{
	mParaUM_Global_red = paraUM_red;
}
// get parameter 
parameterUnsharpMasking UnshaprMasking_singleCore_BGR::getInitialPara_blue()
{
	return mParaUM_Global_blue;
}
parameterUnsharpMasking UnshaprMasking_singleCore_BGR::getInitialPara_green()
{
	return mParaUM_Global_green;
}
parameterUnsharpMasking UnshaprMasking_singleCore_BGR::getInitialPara_red()
{
	return mParaUM_Global_red;
}
// get best parameter
bestParameterStruct_unsharpMask UnshaprMasking_singleCore_BGR::getBestParameter_blue()
{
	return mBestParaUM_blue;
}
bestParameterStruct_unsharpMask UnshaprMasking_singleCore_BGR::getBestParameter_green()
{
	return mBestParaUM_green;
}
bestParameterStruct_unsharpMask UnshaprMasking_singleCore_BGR::getBestParameter_red()
{
	return mBestParaUM_red;
}

void UnshaprMasking_singleCore_BGR::putChannlesTogehter()
{
	std::vector<cv::Mat> array_to_merge;

	array_to_merge.push_back(mFilterResultIma_normedSharp_blue);
	array_to_merge.push_back(mFilterResultIma_normedSharp_green);
	array_to_merge.push_back(mFilterResultIma_normedSharp_red);

	cv::merge(array_to_merge, mFilterResultIma_BGR_normedLikeSharpIma);
}

// norm the gray images according to the sharp image
void UnshaprMasking_singleCore_BGR::normTheGrayImagesAccordingToSharpIma()

{	// blue
	cv::Mat filterResultIma_blue = mBestParaUM_blue.getImage().clone();
	cv::normalize(filterResultIma_blue, mFilterResultIma_normedSharp_blue, mMin_blue, mMax_blue, cv::NORM_MINMAX, CV_8UC1);

	// green
	cv::Mat filterResultIma_green = mBestParaUM_green.getImage().clone();
	cv::normalize(filterResultIma_green, mFilterResultIma_normedSharp_green, mMin_green, mMax_green, cv::NORM_MINMAX, CV_8UC1);

	// red
	cv::Mat filterResultIma_red = mBestParaUM_red.getImage().clone();
	cv::normalize(filterResultIma_red, mFilterResultIma_normedSharp_red, mMin_red, mMax_red, cv::NORM_MINMAX, CV_8UC1);

}

cv::Mat UnshaprMasking_singleCore_BGR::getFilteredResults_normedLikeSharpIma()
{
	return mFilterResultIma_BGR_normedLikeSharpIma;
}

cv::Mat UnshaprMasking_singleCore_BGR::getFilteredResults_normedZeroAndMaxUchar()
{
	std::vector<cv::Mat> array_to_merge;
	cv::Mat mFilterResultIma_BGR__normedZeroAndMaxUchar;

	array_to_merge.push_back(mBestParaUM_blue.getImage());
	array_to_merge.push_back(mBestParaUM_green.getImage());
	array_to_merge.push_back(mBestParaUM_red.getImage());

	cv::merge(array_to_merge, mFilterResultIma_BGR__normedZeroAndMaxUchar);

	return mFilterResultIma_BGR__normedZeroAndMaxUchar;
}


UnsharpMasking24_gray::UnsharpMasking24_gray() {}
UnsharpMasking24_gray::~UnsharpMasking24_gray() {}

// set parameter
void UnsharpMasking24_gray::setParameterUM_gray(parameterUnsharpMasking paraUM_gray)
{
	mParaUM_Global_gray = paraUM_gray;
}

// get best parameter
bestParameterStruct_unsharpMask UnsharpMasking24_gray::getBestParameter_gray()
{
	return mBestParameterGlobal_gray;
}
// get initial parameter
parameterUnsharpMasking UnsharpMasking24_gray::getInitialPara_gray()
{
	return mParaUM_Global_gray;
}
// find best parameter
void UnsharpMasking24_gray::findBestParameterAllCores_gray()
{
	// find best improvement
	real bestImprovement = mUM_singleCore_gray_1.getBestParameter().getImprovement();
	real tempImp;
	unsigned int tempBestPosInVec = 0;

	for (unsigned int i = 1; i < mImprovements_vec_gray.size(); ++i)
	{
		tempImp = mImprovements_vec_gray[i];
		if (tempImp > bestImprovement)
		{
			bestImprovement = tempImp;
			tempBestPosInVec = i;
		}
	}

	mBestParameterGlobal_gray = mBestParaUM_vec_gray[tempBestPosInVec];
}

// initialize parameter for difference cores
void UnsharpMasking24_gray::initializePrameterDifCores_gray()
{

	int boarderTypeGlobal_gray = mParaUM_Global_gray.getBoarderType();
	mParaUM_gray_1.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_2.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_3.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_4.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_5.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_6.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_7.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_8.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_9.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_10.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_11.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_12.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_13.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_14.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_15.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_16.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_17.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_18.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_19.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_20.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_21.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_22.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_23.setBoarderType(boarderTypeGlobal_gray);
	mParaUM_gray_24.setBoarderType(boarderTypeGlobal_gray);


	real compareInPercent_gray = mParaUM_Global_gray.getCompareInPercent();
	mParaUM_gray_1.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_2.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_3.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_4.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_5.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_6.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_7.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_8.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_9.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_10.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_11.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_12.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_13.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_14.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_15.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_16.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_17.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_18.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_19.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_20.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_21.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_22.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_23.setCompareInPercent(compareInPercent_gray);
	mParaUM_gray_24.setCompareInPercent(compareInPercent_gray);



	// sharpness evaluation methode
	sharpnessEvalMethode sharpnessEvalMethode = mParaUM_Global_gray.getSharpnessEvalMethode();
	mParaUM_gray_1.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_2.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_3.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_4.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_5.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_6.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_7.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_8.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_9.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_10.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_11.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_12.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_13.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_14.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_15.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_16.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_17.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_18.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_19.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_20.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_21.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_22.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_23.setSharpnessEvalMethode(sharpnessEvalMethode);
	mParaUM_gray_24.setSharpnessEvalMethode(sharpnessEvalMethode);


	// numer of cores
	int numberCores = 24;

	// sigma
	real minSigmaGlobal = mParaUM_Global_gray.getMinSigma();
	real maxSigmaGlobal = mParaUM_Global_gray.getMaxSigma();
	real stepsPerCoreSigma = mParaUM_Global_gray.getStepsSigma() / numberCores;

	// amount
	real minAmountGlobal = mParaUM_Global_gray.getMinAmount();
	real maxAmountGlobal = mParaUM_Global_gray.getMaxAmount();
	real stepsPerCoreAmount = mParaUM_Global_gray.getStepsAmount() / numberCores;

	// threshold
	real minThresholdGlobal = mParaUM_Global_gray.getMinThreshold();
	real maxThrasholdGlobal = mParaUM_Global_gray.getMaxThreshold();
	real stepsPerCoreThreshold = mParaUM_Global_gray.getStepsThreshold() / numberCores;

	// set steps per core sigma
	mParaUM_gray_1.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_2.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_3.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_4.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_5.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_6.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_7.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_8.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_9.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_10.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_11.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_12.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_13.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_14.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_15.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_16.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_17.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_18.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_19.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_20.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_21.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_22.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_23.setStepsSigma(stepsPerCoreSigma);
	mParaUM_gray_24.setStepsSigma(stepsPerCoreSigma);

	// set steps per core threshold
	mParaUM_gray_1.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_2.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_3.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_4.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_5.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_6.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_7.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_8.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_9.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_10.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_11.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_12.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_13.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_14.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_15.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_16.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_17.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_18.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_19.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_20.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_21.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_22.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_23.setStepsThreshold(stepsPerCoreThreshold);
	mParaUM_gray_24.setStepsThreshold(stepsPerCoreThreshold);

	// set steps per core amount
	mParaUM_gray_1.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_2.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_3.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_4.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_5.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_6.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_7.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_8.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_9.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_10.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_11.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_12.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_13.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_14.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_15.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_16.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_17.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_18.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_19.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_20.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_21.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_22.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_23.setStepsAmount(stepsPerCoreAmount);
	mParaUM_gray_24.setStepsAmount(stepsPerCoreAmount);


	// calc diff sigma per core
	real deltaSigmaGloal = (mParaUM_Global_gray.getMaxSigma() - mParaUM_Global_gray.getMinSigma()) / mParaUM_Global_gray.getStepsSigma();
	real diffPerCoreSigma = deltaSigmaGloal * stepsPerCoreSigma;

	real minSigmaCore_1 = minSigmaGlobal;
	real maxSigmaCore_1 = minSigmaCore_1 + diffPerCoreSigma;
	real minSigmaCore_2 = maxSigmaCore_1;
	real maxSigmaCore_2 = minSigmaCore_2 + diffPerCoreSigma;
	real minSigmaCore_3 = maxSigmaCore_2;
	real maxSigmaCore_3 = minSigmaCore_3 + diffPerCoreSigma;
	real minSigmaCore_4 = maxSigmaCore_3;
	real maxSigmaCore_4 = minSigmaCore_4 + diffPerCoreSigma;
	real minSigmaCore_5 = maxSigmaCore_4;
	real maxSigmaCore_5 = minSigmaCore_5 + diffPerCoreSigma;
	real minSigmaCore_6 = maxSigmaCore_5;
	real maxSigmaCore_6 = minSigmaCore_6 + diffPerCoreSigma;
	real minSigmaCore_7 = maxSigmaCore_6;
	real maxSigmaCore_7 = minSigmaCore_7 + diffPerCoreSigma;
	real minSigmaCore_8 = maxSigmaCore_7;
	real maxSigmaCore_8 = minSigmaCore_8 + diffPerCoreSigma;
	real minSigmaCore_9 = maxSigmaCore_8;
	real maxSigmaCore_9 = minSigmaCore_9 + diffPerCoreSigma;
	real minSigmaCore_10 = maxSigmaCore_9;
	real maxSigmaCore_10 = minSigmaCore_10 + diffPerCoreSigma;
	real minSigmaCore_11 = maxSigmaCore_10;
	real maxSigmaCore_11 = minSigmaCore_11 + diffPerCoreSigma;
	real minSigmaCore_12 = maxSigmaCore_11;
	real maxSigmaCore_12 = minSigmaCore_12 + diffPerCoreSigma;
	real minSigmaCore_13 = maxSigmaCore_12;
	real maxSigmaCore_13 = minSigmaCore_13 + diffPerCoreSigma;
	real minSigmaCore_14 = maxSigmaCore_13;
	real maxSigmaCore_14 = minSigmaCore_14 + diffPerCoreSigma;
	real minSigmaCore_15 = maxSigmaCore_14;
	real maxSigmaCore_15 = minSigmaCore_15 + diffPerCoreSigma;
	real minSigmaCore_16 = maxSigmaCore_15;
	real maxSigmaCore_16 = minSigmaCore_16 + diffPerCoreSigma;
	real minSigmaCore_17 = maxSigmaCore_16;
	real maxSigmaCore_17 = minSigmaCore_17 + diffPerCoreSigma;
	real minSigmaCore_18 = maxSigmaCore_17;
	real maxSigmaCore_18 = minSigmaCore_18 + diffPerCoreSigma;
	real minSigmaCore_19 = maxSigmaCore_18;
	real maxSigmaCore_19 = minSigmaCore_19 + diffPerCoreSigma;
	real minSigmaCore_20 = maxSigmaCore_19;
	real maxSigmaCore_20 = minSigmaCore_20 + diffPerCoreSigma;
	real minSigmaCore_21 = maxSigmaCore_20;
	real maxSigmaCore_21 = minSigmaCore_21 + diffPerCoreSigma;
	real minSigmaCore_22 = maxSigmaCore_21;
	real maxSigmaCore_22 = minSigmaCore_22 + diffPerCoreSigma;
	real minSigmaCore_23 = maxSigmaCore_22;
	real maxSigmaCore_23 = minSigmaCore_23 + diffPerCoreSigma;
	real minSigmaCore_24 = maxSigmaCore_23;
	real maxSigmaCore_24 = mParaUM_Global_gray.getMaxSigma();

	mParaUM_gray_1.setMinSigma(minSigmaCore_1);
	mParaUM_gray_1.setMaxSigma(maxSigmaCore_1);
	mParaUM_gray_2.setMinSigma(minSigmaCore_2);
	mParaUM_gray_2.setMaxSigma(maxSigmaCore_2);
	mParaUM_gray_3.setMinSigma(minSigmaCore_3);
	mParaUM_gray_3.setMaxSigma(maxSigmaCore_3);
	mParaUM_gray_4.setMinSigma(minSigmaCore_4);
	mParaUM_gray_4.setMaxSigma(maxSigmaCore_4);
	mParaUM_gray_5.setMinSigma(minSigmaCore_5);
	mParaUM_gray_5.setMaxSigma(maxSigmaCore_5);
	mParaUM_gray_6.setMinSigma(minSigmaCore_6);
	mParaUM_gray_6.setMaxSigma(maxSigmaCore_6);
	mParaUM_gray_7.setMinSigma(minSigmaCore_7);
	mParaUM_gray_7.setMaxSigma(maxSigmaCore_7);
	mParaUM_gray_8.setMinSigma(minSigmaCore_8);
	mParaUM_gray_8.setMaxSigma(maxSigmaCore_8);
	mParaUM_gray_9.setMinSigma(minSigmaCore_9);
	mParaUM_gray_9.setMaxSigma(maxSigmaCore_9);
	mParaUM_gray_10.setMinSigma(minSigmaCore_10);
	mParaUM_gray_10.setMaxSigma(maxSigmaCore_10);
	mParaUM_gray_11.setMinSigma(minSigmaCore_11);
	mParaUM_gray_11.setMaxSigma(maxSigmaCore_11);
	mParaUM_gray_12.setMinSigma(minSigmaCore_12);
	mParaUM_gray_12.setMaxSigma(maxSigmaCore_12);
	mParaUM_gray_13.setMinSigma(minSigmaCore_13);
	mParaUM_gray_13.setMaxSigma(maxSigmaCore_13);
	mParaUM_gray_14.setMinSigma(minSigmaCore_14);
	mParaUM_gray_14.setMaxSigma(maxSigmaCore_14);
	mParaUM_gray_15.setMinSigma(minSigmaCore_15);
	mParaUM_gray_15.setMaxSigma(maxSigmaCore_15);
	mParaUM_gray_16.setMinSigma(minSigmaCore_16);
	mParaUM_gray_16.setMaxSigma(maxSigmaCore_16);
	mParaUM_gray_17.setMinSigma(minSigmaCore_17);
	mParaUM_gray_17.setMaxSigma(maxSigmaCore_17);
	mParaUM_gray_18.setMinSigma(minSigmaCore_18);
	mParaUM_gray_18.setMaxSigma(maxSigmaCore_18);
	mParaUM_gray_19.setMinSigma(minSigmaCore_19);
	mParaUM_gray_19.setMaxSigma(maxSigmaCore_19);
	mParaUM_gray_20.setMinSigma(minSigmaCore_20);
	mParaUM_gray_20.setMaxSigma(maxSigmaCore_20);
	mParaUM_gray_21.setMinSigma(minSigmaCore_21);
	mParaUM_gray_21.setMaxSigma(maxSigmaCore_21);
	mParaUM_gray_22.setMinSigma(minSigmaCore_22);
	mParaUM_gray_22.setMaxSigma(maxSigmaCore_22);
	mParaUM_gray_23.setMinSigma(minSigmaCore_23);
	mParaUM_gray_23.setMaxSigma(maxSigmaCore_23);
	mParaUM_gray_24.setMinSigma(minSigmaCore_24);
	mParaUM_gray_24.setMaxSigma(maxSigmaCore_24);


	// calc diff threshold per core
	real deltaThresholdGloal = (mParaUM_Global_gray.getMaxThreshold() - mParaUM_Global_gray.getMinThreshold()) / mParaUM_Global_gray.getStepsThreshold();
	real diffPerCoreThreshold = deltaThresholdGloal * stepsPerCoreThreshold;

	real minThresholdCore_1 = minThresholdGlobal;
	real maxThresholdCore_1 = minThresholdCore_1 + diffPerCoreThreshold;
	real minThresholdCore_2 = maxThresholdCore_1;
	real maxThresholdCore_2 = minThresholdCore_2 + diffPerCoreThreshold;
	real minThresholdCore_3 = maxThresholdCore_2;
	real maxThresholdCore_3 = minThresholdCore_3 + diffPerCoreThreshold;
	real minThresholdCore_4 = maxThresholdCore_3;
	real maxThresholdCore_4 = minThresholdCore_4 + diffPerCoreThreshold;
	real minThresholdCore_5 = maxThresholdCore_4;
	real maxThresholdCore_5 = minThresholdCore_5 + diffPerCoreThreshold;
	real minThresholdCore_6 = maxThresholdCore_5;
	real maxThresholdCore_6 = minThresholdCore_6 + diffPerCoreThreshold;
	real minThresholdCore_7 = maxThresholdCore_6;
	real maxThresholdCore_7 = minThresholdCore_7 + diffPerCoreThreshold;
	real minThresholdCore_8 = maxThresholdCore_7;
	real maxThresholdCore_8 = minThresholdCore_8 + diffPerCoreThreshold;
	real minThresholdCore_9 = maxThresholdCore_8;
	real maxThresholdCore_9 = minThresholdCore_9 + diffPerCoreThreshold;
	real minThresholdCore_10 = maxThresholdCore_9;
	real maxThresholdCore_10 = minThresholdCore_10 + diffPerCoreThreshold;
	real minThresholdCore_11 = maxThresholdCore_10;
	real maxThresholdCore_11 = minThresholdCore_11 + diffPerCoreThreshold;
	real minThresholdCore_12 = maxThresholdCore_11;
	real maxThresholdCore_12 = minThresholdCore_12 + diffPerCoreThreshold;
	real minThresholdCore_13 = maxThresholdCore_12;
	real maxThresholdCore_13 = minThresholdCore_13 + diffPerCoreThreshold;
	real minThresholdCore_14 = maxThresholdCore_13;
	real maxThresholdCore_14 = minThresholdCore_14 + diffPerCoreThreshold;
	real minThresholdCore_15 = maxThresholdCore_14;
	real maxThresholdCore_15 = minThresholdCore_15 + diffPerCoreThreshold;
	real minThresholdCore_16 = maxThresholdCore_15;
	real maxThresholdCore_16 = minThresholdCore_16 + diffPerCoreThreshold;
	real minThresholdCore_17 = maxThresholdCore_16;
	real maxThresholdCore_17 = minThresholdCore_17 + diffPerCoreThreshold;
	real minThresholdCore_18 = maxThresholdCore_17;
	real maxThresholdCore_18 = minThresholdCore_18 + diffPerCoreThreshold;
	real minThresholdCore_19 = maxThresholdCore_18;
	real maxThresholdCore_19 = minThresholdCore_19 + diffPerCoreThreshold;
	real minThresholdCore_20 = maxThresholdCore_19;
	real maxThresholdCore_20 = minThresholdCore_20 + diffPerCoreThreshold;
	real minThresholdCore_21 = maxThresholdCore_20;
	real maxThresholdCore_21 = minThresholdCore_21 + diffPerCoreThreshold;
	real minThresholdCore_22 = maxThresholdCore_21;
	real maxThresholdCore_22 = minThresholdCore_22 + diffPerCoreThreshold;
	real minThresholdCore_23 = maxThresholdCore_22;
	real maxThresholdCore_23 = minThresholdCore_23 + diffPerCoreThreshold;
	real minThresholdCore_24 = maxThresholdCore_23;
	real maxThresholdCore_24 = maxThrasholdGlobal;


	mParaUM_gray_1.setMinThreshold(minThresholdCore_1);
	mParaUM_gray_1.setMaxThreshold(maxThresholdCore_1);
	mParaUM_gray_2.setMinThreshold(minThresholdCore_2);
	mParaUM_gray_2.setMaxThreshold(maxThresholdCore_2);
	mParaUM_gray_3.setMinThreshold(minThresholdCore_3);
	mParaUM_gray_3.setMaxThreshold(maxThresholdCore_3);
	mParaUM_gray_4.setMinThreshold(minThresholdCore_4);
	mParaUM_gray_4.setMaxThreshold(maxThresholdCore_4);
	mParaUM_gray_5.setMinThreshold(minThresholdCore_5);
	mParaUM_gray_5.setMaxThreshold(maxThresholdCore_5);
	mParaUM_gray_6.setMinThreshold(minThresholdCore_6);
	mParaUM_gray_6.setMaxThreshold(maxThresholdCore_6);
	mParaUM_gray_7.setMinThreshold(minThresholdCore_7);
	mParaUM_gray_7.setMaxThreshold(maxThresholdCore_7);
	mParaUM_gray_8.setMinThreshold(minThresholdCore_8);
	mParaUM_gray_8.setMaxThreshold(maxThresholdCore_8);
	mParaUM_gray_9.setMinThreshold(minThresholdCore_9);
	mParaUM_gray_9.setMaxThreshold(maxThresholdCore_9);
	mParaUM_gray_10.setMinThreshold(minThresholdCore_10);
	mParaUM_gray_10.setMaxThreshold(maxThresholdCore_10);
	mParaUM_gray_11.setMinThreshold(minThresholdCore_11);
	mParaUM_gray_11.setMaxThreshold(maxThresholdCore_11);
	mParaUM_gray_12.setMinThreshold(minThresholdCore_12);
	mParaUM_gray_12.setMaxThreshold(maxThresholdCore_12);
	mParaUM_gray_13.setMinThreshold(minThresholdCore_13);
	mParaUM_gray_13.setMaxThreshold(maxThresholdCore_13);
	mParaUM_gray_14.setMinThreshold(minThresholdCore_14);
	mParaUM_gray_14.setMaxThreshold(maxThresholdCore_14);
	mParaUM_gray_15.setMinThreshold(minThresholdCore_15);
	mParaUM_gray_15.setMaxThreshold(maxThresholdCore_15);
	mParaUM_gray_16.setMinThreshold(minThresholdCore_16);
	mParaUM_gray_16.setMaxThreshold(maxThresholdCore_16);
	mParaUM_gray_17.setMinThreshold(minThresholdCore_17);
	mParaUM_gray_17.setMaxThreshold(maxThresholdCore_17);
	mParaUM_gray_18.setMinThreshold(minThresholdCore_18);
	mParaUM_gray_18.setMaxThreshold(maxThresholdCore_18);
	mParaUM_gray_19.setMinThreshold(minThresholdCore_19);
	mParaUM_gray_19.setMaxThreshold(maxThresholdCore_19);
	mParaUM_gray_20.setMinThreshold(minThresholdCore_20);
	mParaUM_gray_20.setMaxThreshold(maxThresholdCore_20);
	mParaUM_gray_21.setMinThreshold(minThresholdCore_21);
	mParaUM_gray_21.setMaxThreshold(maxThresholdCore_21);
	mParaUM_gray_22.setMinThreshold(minThresholdCore_22);
	mParaUM_gray_22.setMaxThreshold(maxThresholdCore_22);
	mParaUM_gray_23.setMinThreshold(minThresholdCore_23);
	mParaUM_gray_23.setMaxThreshold(maxThresholdCore_23);
	mParaUM_gray_24.setMinThreshold(minThresholdCore_24);
	mParaUM_gray_24.setMaxThreshold(maxThresholdCore_24);

	// calc diff Amount per core
	real deltaAmountGloal = (mParaUM_Global_gray.getMaxAmount() - mParaUM_Global_gray.getMinAmount()) / mParaUM_Global_gray.getStepsAmount();
	real diffPerCoreAmount = deltaAmountGloal * stepsPerCoreAmount;

	real minAmountCore_1 = minAmountGlobal;
	real maxAmountCore_1 = minAmountCore_1 + diffPerCoreAmount;
	real minAmountCore_2 = maxAmountCore_1;
	real maxAmountCore_2 = minAmountCore_2 + diffPerCoreAmount;
	real minAmountCore_3 = maxAmountCore_2;
	real maxAmountCore_3 = minAmountCore_3 + diffPerCoreAmount;
	real minAmountCore_4 = maxAmountCore_3;
	real maxAmountCore_4 = minAmountCore_4 + diffPerCoreAmount;
	real minAmountCore_5 = maxAmountCore_4;
	real maxAmountCore_5 = minAmountCore_5 + diffPerCoreAmount;
	real minAmountCore_6 = maxAmountCore_5;
	real maxAmountCore_6 = minAmountCore_6 + diffPerCoreAmount;
	real minAmountCore_7 = maxAmountCore_6;
	real maxAmountCore_7 = minAmountCore_7 + diffPerCoreAmount;
	real minAmountCore_8 = maxAmountCore_7;
	real maxAmountCore_8 = minAmountCore_8 + diffPerCoreAmount;
	real minAmountCore_9 = maxAmountCore_8;
	real maxAmountCore_9 = minAmountCore_9 + diffPerCoreAmount;
	real minAmountCore_10 = maxAmountCore_9;
	real maxAmountCore_10 = minAmountCore_10 + diffPerCoreAmount;
	real minAmountCore_11 = maxAmountCore_10;
	real maxAmountCore_11 = minAmountCore_11 + diffPerCoreAmount;
	real minAmountCore_12 = maxAmountCore_11;
	real maxAmountCore_12 = minAmountCore_12 + diffPerCoreAmount;
	real minAmountCore_13 = maxAmountCore_12;
	real maxAmountCore_13 = minAmountCore_13 + diffPerCoreAmount;
	real minAmountCore_14 = maxAmountCore_13;
	real maxAmountCore_14 = minAmountCore_14 + diffPerCoreAmount;
	real minAmountCore_15 = maxAmountCore_14;
	real maxAmountCore_15 = minAmountCore_15 + diffPerCoreAmount;
	real minAmountCore_16 = maxAmountCore_15;
	real maxAmountCore_16 = minAmountCore_16 + diffPerCoreAmount;
	real minAmountCore_17 = maxAmountCore_16;
	real maxAmountCore_17 = minAmountCore_17 + diffPerCoreAmount;
	real minAmountCore_18 = maxAmountCore_17;
	real maxAmountCore_18 = minAmountCore_18 + diffPerCoreAmount;
	real minAmountCore_19 = maxAmountCore_18;
	real maxAmountCore_19 = minAmountCore_19 + diffPerCoreAmount;
	real minAmountCore_20 = maxAmountCore_19;
	real maxAmountCore_20 = minAmountCore_20 + diffPerCoreAmount;
	real minAmountCore_21 = maxAmountCore_20;
	real maxAmountCore_21 = minAmountCore_21 + diffPerCoreAmount;
	real minAmountCore_22 = maxAmountCore_21;
	real maxAmountCore_22 = minAmountCore_22 + diffPerCoreAmount;
	real minAmountCore_23 = maxAmountCore_22;
	real maxAmountCore_23 = minAmountCore_23 + diffPerCoreAmount;
	real minAmountCore_24 = maxAmountCore_23;
	real maxAmountCore_24 = maxAmountGlobal;


	mParaUM_gray_1.setMinAmount(minAmountCore_1);
	mParaUM_gray_1.setMaxAmount(maxAmountCore_1);
	mParaUM_gray_2.setMinAmount(minAmountCore_2);
	mParaUM_gray_2.setMaxAmount(maxAmountCore_2);
	mParaUM_gray_3.setMinAmount(minAmountCore_3);
	mParaUM_gray_3.setMaxAmount(maxAmountCore_3);
	mParaUM_gray_4.setMinAmount(minAmountCore_4);
	mParaUM_gray_4.setMaxAmount(maxAmountCore_4);
	mParaUM_gray_5.setMinAmount(minAmountCore_5);
	mParaUM_gray_5.setMaxAmount(maxAmountCore_5);
	mParaUM_gray_6.setMinAmount(minAmountCore_6);
	mParaUM_gray_6.setMaxAmount(maxAmountCore_6);
	mParaUM_gray_7.setMinAmount(minAmountCore_7);
	mParaUM_gray_7.setMaxAmount(maxAmountCore_7);
	mParaUM_gray_8.setMinAmount(minAmountCore_8);
	mParaUM_gray_8.setMaxAmount(maxAmountCore_8);
	mParaUM_gray_9.setMinAmount(minAmountCore_9);
	mParaUM_gray_9.setMaxAmount(maxAmountCore_9);
	mParaUM_gray_10.setMinAmount(minAmountCore_10);
	mParaUM_gray_10.setMaxAmount(maxAmountCore_10);
	mParaUM_gray_11.setMinAmount(minAmountCore_11);
	mParaUM_gray_11.setMaxAmount(maxAmountCore_11);
	mParaUM_gray_12.setMinAmount(minAmountCore_12);
	mParaUM_gray_12.setMaxAmount(maxAmountCore_12);
	mParaUM_gray_13.setMinAmount(minAmountCore_13);
	mParaUM_gray_13.setMaxAmount(maxAmountCore_13);
	mParaUM_gray_14.setMinAmount(minAmountCore_14);
	mParaUM_gray_14.setMaxAmount(maxAmountCore_14);
	mParaUM_gray_15.setMinAmount(minAmountCore_15);
	mParaUM_gray_15.setMaxAmount(maxAmountCore_15);
	mParaUM_gray_16.setMinAmount(minAmountCore_16);
	mParaUM_gray_16.setMaxAmount(maxAmountCore_16);
	mParaUM_gray_17.setMinAmount(minAmountCore_17);
	mParaUM_gray_17.setMaxAmount(maxAmountCore_17);
	mParaUM_gray_18.setMinAmount(minAmountCore_18);
	mParaUM_gray_18.setMaxAmount(maxAmountCore_18);
	mParaUM_gray_19.setMinAmount(minAmountCore_19);
	mParaUM_gray_19.setMaxAmount(maxAmountCore_19);
	mParaUM_gray_20.setMinAmount(minAmountCore_20);
	mParaUM_gray_20.setMaxAmount(maxAmountCore_20);
	mParaUM_gray_21.setMinAmount(minAmountCore_21);
	mParaUM_gray_21.setMaxAmount(maxAmountCore_21);
	mParaUM_gray_22.setMinAmount(minAmountCore_22);
	mParaUM_gray_22.setMaxAmount(maxAmountCore_22);
	mParaUM_gray_23.setMinAmount(minAmountCore_23);
	mParaUM_gray_23.setMaxAmount(maxAmountCore_23);
	mParaUM_gray_24.setMinAmount(minAmountCore_24);
	mParaUM_gray_24.setMaxAmount(maxAmountCore_24);

	// set parameter
	mUM_singleCore_gray_1.setParameterUM(mParaUM_gray_1);
	mUM_singleCore_gray_2.setParameterUM(mParaUM_gray_2);
	mUM_singleCore_gray_3.setParameterUM(mParaUM_gray_3);
	mUM_singleCore_gray_4.setParameterUM(mParaUM_gray_4);
	mUM_singleCore_gray_5.setParameterUM(mParaUM_gray_5);
	mUM_singleCore_gray_6.setParameterUM(mParaUM_gray_6);
	mUM_singleCore_gray_7.setParameterUM(mParaUM_gray_7);
	mUM_singleCore_gray_8.setParameterUM(mParaUM_gray_8);
	mUM_singleCore_gray_9.setParameterUM(mParaUM_gray_9);
	mUM_singleCore_gray_10.setParameterUM(mParaUM_gray_10);
	mUM_singleCore_gray_11.setParameterUM(mParaUM_gray_11);
	mUM_singleCore_gray_12.setParameterUM(mParaUM_gray_12);
	mUM_singleCore_gray_13.setParameterUM(mParaUM_gray_13);
	mUM_singleCore_gray_14.setParameterUM(mParaUM_gray_14);
	mUM_singleCore_gray_15.setParameterUM(mParaUM_gray_15);
	mUM_singleCore_gray_16.setParameterUM(mParaUM_gray_16);
	mUM_singleCore_gray_17.setParameterUM(mParaUM_gray_17);
	mUM_singleCore_gray_18.setParameterUM(mParaUM_gray_18);
	mUM_singleCore_gray_19.setParameterUM(mParaUM_gray_19);
	mUM_singleCore_gray_20.setParameterUM(mParaUM_gray_20);
	mUM_singleCore_gray_21.setParameterUM(mParaUM_gray_21);
	mUM_singleCore_gray_22.setParameterUM(mParaUM_gray_22);
	mUM_singleCore_gray_23.setParameterUM(mParaUM_gray_23);
	mUM_singleCore_gray_24.setParameterUM(mParaUM_gray_24);
}

void UnsharpMasking24_gray::improveImaQual_UnsharpMasking_superFct_GRAY_parallel(const cv::Mat sharpBGR_Image, const cv::Mat blueredBGR_Image)
{
	mSharpImage_gray = sharpBGR_Image.clone();
	mBlueredImage_gray = blueredBGR_Image.clone();

	// initialize parameter
	initializePrameterDifCores_gray();

	mImprovements_vec_gray.resize(24);
	mBestParaUM_vec_gray.resize(24);

	findingBestParaUM_GRAY_parallel();

	findBestParameterAllCores_gray();

}

void UnsharpMasking24_gray::findingBestParaUM_GRAY_parallel()
{

omp_set_num_threads(24);
#pragma omp parallel
#pragma omp sections
	{
#pragma omp section // _gray_1
		{
			//std::cout << "start core 1" << std::endl;
			mUM_singleCore_gray_1.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore1 = mUM_singleCore_gray_1.getBestParameter().getImprovement();
			mImprovements_vec_gray[0] = impCore1;
			mBestParaUM_vec_gray[0] = mUM_singleCore_gray_1.getBestParameter();
		}
#pragma omp section // _gray_2
		{
			//std::cout << "start core 2" << std::endl;
			mUM_singleCore_gray_2.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore2 = mUM_singleCore_gray_2.getBestParameter().getImprovement();
			mImprovements_vec_gray[1] = impCore2;
			mBestParaUM_vec_gray[1] = mUM_singleCore_gray_2.getBestParameter();
		}
#pragma omp section // _gray_3
		{
			//std::cout << "start core 3" << std::endl;
			mUM_singleCore_gray_3.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore3 = mUM_singleCore_gray_3.getBestParameter().getImprovement();
			mImprovements_vec_gray[2] = impCore3;
			mBestParaUM_vec_gray[2] = mUM_singleCore_gray_3.getBestParameter();
		}
#pragma omp section // _gray_4
		{
			//std::cout << "start core 4" << std::endl;
			mUM_singleCore_gray_4.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore4 = mUM_singleCore_gray_4.getBestParameter().getImprovement();
			mImprovements_vec_gray[3] = impCore4;
			mBestParaUM_vec_gray[3] = mUM_singleCore_gray_4.getBestParameter();
		}
#pragma omp section // _gray_5
		{
			//std::cout << "start core 5" << std::endl;
			mUM_singleCore_gray_5.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore5 = mUM_singleCore_gray_5.getBestParameter().getImprovement();
			mImprovements_vec_gray[4] = impCore5;
			mBestParaUM_vec_gray[4] = mUM_singleCore_gray_5.getBestParameter();
		}
#pragma omp section // _gray_6
		{
			//std::cout << "start core 6" << std::endl;
			mUM_singleCore_gray_6.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore6 = mUM_singleCore_gray_6.getBestParameter().getImprovement();
			mImprovements_vec_gray[5] = impCore6;
			mBestParaUM_vec_gray[5] = mUM_singleCore_gray_6.getBestParameter();
		}
#pragma omp section // _gray_7
		{
			//std::cout << "start core 7" << std::endl;
			mUM_singleCore_gray_7.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore7 = mUM_singleCore_gray_7.getBestParameter().getImprovement();
			mImprovements_vec_gray[6] = impCore7;
			mBestParaUM_vec_gray[6] = mUM_singleCore_gray_7.getBestParameter();
		}
#pragma omp section // _gray_8
		{
			//std::cout << "start core 8" << std::endl;
			mUM_singleCore_gray_8.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore8 = mUM_singleCore_gray_8.getBestParameter().getImprovement();
			mImprovements_vec_gray[7] = impCore8;
			mBestParaUM_vec_gray[7] = mUM_singleCore_gray_8.getBestParameter();
		}
#pragma omp section // _gray_9
		{
			//std::cout << "start core 9" << std::endl;
			mUM_singleCore_gray_9.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore9 = mUM_singleCore_gray_9.getBestParameter().getImprovement();
			mImprovements_vec_gray[8] = impCore9;
			mBestParaUM_vec_gray[8] = mUM_singleCore_gray_9.getBestParameter();
		}
#pragma omp section // _gray_10
		{
			//std::cout << "start core 10" << std::endl;
			mUM_singleCore_gray_10.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore10 = mUM_singleCore_gray_10.getBestParameter().getImprovement();
			mImprovements_vec_gray[9] = impCore10;
			mBestParaUM_vec_gray[9] = mUM_singleCore_gray_10.getBestParameter();
		}
#pragma omp section // _gray_11
		{
			//std::cout << "start core 11" << std::endl;
			mUM_singleCore_gray_11.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore11 = mUM_singleCore_gray_11.getBestParameter().getImprovement();
			mImprovements_vec_gray[10] = impCore11;
			mBestParaUM_vec_gray[10] = mUM_singleCore_gray_11.getBestParameter();
		}
#pragma omp section // _gray_12
		{
			//std::cout << "start core 12" << std::endl;
			mUM_singleCore_gray_12.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore12 = mUM_singleCore_gray_12.getBestParameter().getImprovement();
			mImprovements_vec_gray[11] = impCore12;
			mBestParaUM_vec_gray[11] = mUM_singleCore_gray_12.getBestParameter();
		}
#pragma omp section // _gray_13
		{
			//std::cout << "start core 13" << std::endl;
			mUM_singleCore_gray_13.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore13 = mUM_singleCore_gray_13.getBestParameter().getImprovement();
			mImprovements_vec_gray[12] = impCore13;
			mBestParaUM_vec_gray[12] = mUM_singleCore_gray_13.getBestParameter();
		}
#pragma omp section // _gray_14
		{
			//std::cout << "start core 14" << std::endl;
			mUM_singleCore_gray_14.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore14 = mUM_singleCore_gray_14.getBestParameter().getImprovement();
			mImprovements_vec_gray[13] = impCore14;
			mBestParaUM_vec_gray[13] = mUM_singleCore_gray_14.getBestParameter();
		}
#pragma omp section // _gray_15
		{
			//std::cout << "start core 15" << std::endl;
			mUM_singleCore_gray_15.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore15 = mUM_singleCore_gray_15.getBestParameter().getImprovement();
			mImprovements_vec_gray[14] = impCore15;
			mBestParaUM_vec_gray[14] = mUM_singleCore_gray_15.getBestParameter();
		}
#pragma omp section // _gray_16
		{
			//std::cout << "start core 16" << std::endl;
			mUM_singleCore_gray_16.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore16 = mUM_singleCore_gray_16.getBestParameter().getImprovement();
			mImprovements_vec_gray[15] = impCore16;
			mBestParaUM_vec_gray[15] = mUM_singleCore_gray_16.getBestParameter();
		}
#pragma omp section // _gray_17
		{
			//std::cout << "start core 17" << std::endl;
			mUM_singleCore_gray_17.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore17 = mUM_singleCore_gray_17.getBestParameter().getImprovement();
			mImprovements_vec_gray[16] = impCore17;
			mBestParaUM_vec_gray[16] = mUM_singleCore_gray_1.getBestParameter();
		}
#pragma omp section // _gray_18
		{
			//std::cout << "start core 18" << std::endl;
			mUM_singleCore_gray_18.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore18 = mUM_singleCore_gray_18.getBestParameter().getImprovement();
			mImprovements_vec_gray[17] = impCore18;
			mBestParaUM_vec_gray[17] = mUM_singleCore_gray_18.getBestParameter();
		}
#pragma omp section // _gray_19
		{
			//std::cout << "start core 19" << std::endl;
			mUM_singleCore_gray_19.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore19 = mUM_singleCore_gray_19.getBestParameter().getImprovement();
			mImprovements_vec_gray[18] = impCore19;
			mBestParaUM_vec_gray[18] = mUM_singleCore_gray_19.getBestParameter();
		}
#pragma omp section // _gray_20
		{
			//std::cout << "start core 20" << std::endl;
			mUM_singleCore_gray_20.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore20 = mUM_singleCore_gray_20.getBestParameter().getImprovement();
			mImprovements_vec_gray[19] = impCore20;
			mBestParaUM_vec_gray[19] = mUM_singleCore_gray_20.getBestParameter();
		}
#pragma omp section // _gray_21
		{
			//std::cout << "start core 21" << std::endl;
			mUM_singleCore_gray_21.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore21 = mUM_singleCore_gray_21.getBestParameter().getImprovement();
			mImprovements_vec_gray[20] = impCore21;
			mBestParaUM_vec_gray[20] = mUM_singleCore_gray_21.getBestParameter();
		}
#pragma omp section // _gray_22
		{
			//std::cout << "start core 22" << std::endl;
			mUM_singleCore_gray_22.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore22 = mUM_singleCore_gray_22.getBestParameter().getImprovement();
			mImprovements_vec_gray[21] = impCore22;
			mBestParaUM_vec_gray[21] = mUM_singleCore_gray_22.getBestParameter();
		}
#pragma omp section // _gray_23
		{
			//std::cout << "start core 23" << std::endl;
			mUM_singleCore_gray_23.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore23 = mUM_singleCore_gray_23.getBestParameter().getImprovement();
			mImprovements_vec_gray[22] = impCore23;
			mBestParaUM_vec_gray[22] = mUM_singleCore_gray_23.getBestParameter();
		}
#pragma omp section // _gray_24
		{
			//std::cout << "start core 24" << std::endl;
			mUM_singleCore_gray_24.improveImageQuality_unsharpMask_gray(mSharpImage_gray, mBlueredImage_gray);
			real impCore24 = mUM_singleCore_gray_24.getBestParameter().getImprovement();
			mImprovements_vec_gray[23] = impCore24;
			mBestParaUM_vec_gray[23] = mUM_singleCore_gray_24.getBestParameter();
		}
	}

}