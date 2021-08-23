#include "RemoveChromaticAberrations.h"

// often use
#include "..\oftenUseNamespace\oftenUseNamespace.h"

// sharpnes evaluation methodes
#include "..\Image\SharpnessEvaluation.h"

// images
#include "..\Image\Images.h"

RemoveChromaticAberrations::RemoveChromaticAberrations(){}

RemoveChromaticAberrations::~RemoveChromaticAberrations(){}

void RemoveChromaticAberrations::removeChromaticAberrations_superFct(cv::Mat sharpImage, cv::Mat blueredImage)
{
	mSharpImage = sharpImage.clone();
	mBlueredImage = blueredImage.clone();
	mBGR_Vec.resize(3);
	mBGR_Vec_transposed.resize(3);

	// normalize images
	cv::normalize(mSharpImage, mSharpImage, 0.0, 255.0, cv::NORM_MINMAX, CV_8UC3);
	cv::normalize(mBlueredImage, mBlueredImage, 0.0, 255.0, cv::NORM_MINMAX, CV_8UC3);

	//split the color image into individual color channel for convenient in calculation
	cv::split(mBlueredImage, mBGR_Vec);

	mHeight = mBGR_Vec[0].rows,
	mWidth = mBGR_Vec[0].cols;

	// calc roi to calc dif
	calcROI_toCalcDif();

	// find best parameter and save
	findBestParameter();

}

// find best parameter and save
void RemoveChromaticAberrations::findBestParameter()
{
	int deltaThres = (mInitialParameter.getMaxThreshold() - mInitialParameter.getMinThreshold()) / mInitialParameter.getStepsThreshold();

	if (std::abs(mInitialParameter.getStepsThreshold()) < 0.001)
	{
		deltaThres = 1;
	}
	else
	{
		deltaThres = (mInitialParameter.getMaxThreshold() - mInitialParameter.getMinThreshold()) / mInitialParameter.getStepsThreshold();
	}
	
	int tempThreshold = mInitialParameter.getMinThreshold();
	real tempDifference{};
	real tempBestDifference = oftenUse::getInfReal();
	real improvement{};
	SharpnessEvaluation SharpEval;
	real tempSharpness = -1.0 * oftenUse::getInfReal();
	real tempBestSharpness = -1.0 * oftenUse::getInfReal();
	mBestParameter.setImage(mBlueredImage.clone());

	while (tempThreshold <= mInitialParameter.getMaxThreshold())
	{
		CACorrection_RayXie29(mBlueredImage, mTempFilteredImage, tempThreshold);

		// norm image
		cv::normalize(mTempFilteredImage, mTempFilteredImage, 0.0, 255.0, cv::NORM_MINMAX, CV_8UC3);


		if (mInitialParameter.getSharpnessEvalMethode() == sharpnessEvalMethode::sharpImage)
		{
			// calculate difference
			tempDifference = Images::calcAbsDiff_BGR_uint8(mSharpImage, mTempFilteredImage, mInitialParameter.getCompateInPercent());

			if (tempDifference < tempBestDifference)
			{
				tempBestDifference = tempDifference;

				mBestParameter.setThreshold(tempThreshold);
				mBestParameter.setDifference(tempDifference);
				mBestParameter.setImage(mTempFilteredImage.clone());

				improvement = Images::calcImprovementBGR(mSharpImage, mBlueredImage, mTempFilteredImage, mInitialParameter.getCompateInPercent());
				mBestParameter.setImprovement(improvement);
				// debug
				// std::cout << "improvement: " << improvement << std::endl;
				// std::cout << "threshold: " << tempThreshold << std::endl;
			}
		}

		else
		{
			tempSharpness = SharpEval.calculateSharpness_superFct(mInitialParameter.getSharpnessEvalMethode(), mTempFilteredImage);

			if (tempSharpness > tempBestSharpness)
			{
				tempBestSharpness = tempSharpness;

				mBestParameter.setThreshold(tempThreshold);
				mBestParameter.setImage(mTempFilteredImage.clone());

				// calculate difference
				tempDifference = Images::calcAbsDiff_BGR_uint8(mSharpImage, mTempFilteredImage,mInitialParameter.getCompateInPercent());
				mBestParameter.setDifference(tempDifference);

				// improvement
				improvement = Images::calcImprovementBGR(mSharpImage, mBlueredImage, mTempFilteredImage, mInitialParameter.getCompateInPercent());
				mBestParameter.setImprovement(improvement);

				mBestParameter.setSharpness(tempBestSharpness);

				//// debug
				//std::string typeSharpIma = Images::getTypeImageC_VMat(mImageSharp_blue);
				//std::string typeBlueredIma = Images::getTypeImageC_VMat(mBluredIma_blue);
				//std::string typeFilteredIma = Images::getTypeImageC_VMat(mFilterResultIma_blue);

				//////// debug
				//Images::showImage_inputUint8("sharpIma", mImageSharp_blue);
				//Images::showImage_inputUint8("filtered mage", mFilterResultIma_blue);

				
			}
		}

		tempThreshold = tempThreshold + deltaThres;
	}

	if (mInitialParameter.getSharpnessEvalMethode() == sharpnessEvalMethode::sharpImage)
	{
		// check improvement
		if (mBestParameter.getImprovement() <= 1.0)
		{
			mBestParameter.setImage(mBlueredImage.clone());
			mBestParameter.setImprovement(1.0);
		}
	}

	
}


void RemoveChromaticAberrations::setInitialParameter(initialPararemChromAber iniParaChromAber)
{
	mInitialParameter = iniParaChromAber;
}
bestParaRemChromAber RemoveChromaticAberrations::getBestParameter()
{
	return mBestParameter;
}
void RemoveChromaticAberrations::calcROI_toCalcDif()
{
	unsigned int height = mSharpImage.size().height;
	unsigned int width = mSharpImage.size().width;

	unsigned int startX = mInitialParameter.getCompateInPercent() * width / 100.0;
	unsigned int startY = mInitialParameter.getCompateInPercent() * height / 100.0;
	unsigned int heighttROI = height - 2 * startY;
	unsigned int widthROI = width - 2 * startX;

	mRoiToCalcDif.x = startX;
	mRoiToCalcDif.y = startY;
	mRoiToCalcDif.width = widthROI;
	mRoiToCalcDif.height = heighttROI;
}

// get filtered image
cv::Mat RemoveChromaticAberrations::getFilterdIma()
{
	return mBestParameter.getImage();
}

void RemoveChromaticAberrations::CACorrection_RayXie29(cv::Mat& Src, cv::Mat& Dst, int threshold)
{
	std::vector<cv::Mat> bgrVec(3);
	//split the color image into individual color channel for convenient in calculation
	cv::split(Src, bgrVec);

	rmCA_RayXie29(bgrVec, threshold);

	//transpose the R,G B channel image to correct chromatic aberration in vertical direction 
	bgrVec[0] = bgrVec[0].t();
	bgrVec[1] = bgrVec[1].t();
	bgrVec[2] = bgrVec[2].t();

	rmCA_RayXie29(bgrVec, threshold);

	cv::merge(bgrVec, Dst);
	//rotate the image back to original position
	cv::transpose(Dst.clone(), Dst);
}

void RemoveChromaticAberrations::rmCA_RayXie29(std::vector<cv::Mat>& bgrVec, int threshold)
{

	// Attention!The code was taken from:
	// https://github.com/RayXie29/Chromatic_aberration_correction
	// the algorithm based on: Soon-Wook Chung, Byoung-Kwang Kim, Woo-Jin Song, "Removing chromatic aberration by digital image processing", Optical Engineering, 49(6), 067002 (2010). https://doi.org/10.1117/1.3455506
		
		int height = bgrVec[0].rows, width = bgrVec[0].cols;

		for (int i = 0; i < height; ++i)
		{
			uchar* bptr = bgrVec[0].ptr<uchar>(i);
			uchar* gptr = bgrVec[1].ptr<uchar>(i);
			uchar* rptr = bgrVec[2].ptr<uchar>(i);

			for (int j = 1; j < width - 1; ++j)
			{
				//find the edge by finding green channel gradient bigger than threshold
				if (abs(gptr[j + 1] - gptr[j - 1]) >= threshold)
				{
					// +/- sign of this edge
					int sign = 0;
					if (gptr[j + 1] - gptr[j - 1] > 0) { sign = 1; }
					else { sign = -1; }

					//Searching the boundary for correction range
					int lpos = j - 1, rpos = j + 1;
					for (; lpos > 0; --lpos)
					{
						//make sure the gradient is the same sign with edge
						int ggrad = (gptr[lpos + 1] - gptr[lpos - 1]) * sign;
						int bgrad = (bptr[lpos + 1] - bptr[lpos - 1]) * sign;
						int rgrad = (rptr[lpos + 1] - rptr[lpos - 1]) * sign;
						if (std::max(std::max(bgrad, ggrad), rgrad) < threshold) { break; }
					}
					lpos -= 1;
					for (; rpos < width - 1; ++rpos)
					{
						//make sure the gradient is the same sign with edge
						int ggrad = (gptr[rpos + 1] - gptr[rpos - 1]) * sign;
						int bgrad = (bptr[rpos + 1] - bptr[rpos - 1]) * sign;
						int rgrad = (rptr[rpos + 1] - rptr[rpos - 1]) * sign;
						if (std::max(std::max(bgrad, ggrad), rgrad) < threshold) { break; }
					}
					rpos += 1;

					//record the maximum and minimum color difference between R&G and B&G of range boundary
					int bgmaxVal = std::max(bptr[lpos] - gptr[lpos], bptr[rpos] - gptr[rpos]);
					int bgminVal = std::min(bptr[lpos] - gptr[lpos], bptr[rpos] - gptr[rpos]);
					int rgmaxVal = std::max(rptr[lpos] - gptr[lpos], rptr[rpos] - gptr[rpos]);
					int rgminVal = std::min(rptr[lpos] - gptr[lpos], rptr[rpos] - gptr[rpos]);

					for (int k = lpos; k <= rpos; ++k)
					{
						int bdiff = bptr[k] - gptr[k];
						int rdiff = rptr[k] - gptr[k];

						//Replace the B or R value if its color difference of R/G and B/G is bigger(smaller)
						//than maximum(minimum) of color difference on range boundary
						bptr[k] = cv::saturate_cast<uchar>(bdiff > bgmaxVal ? bgmaxVal + gptr[k] :
							(bdiff < bgminVal ? bgminVal + gptr[k] : bptr[k]));
						rptr[k] = cv::saturate_cast<uchar>(rdiff > rgmaxVal ? rgmaxVal + gptr[k] :
							(rdiff < rgminVal ? rgminVal + gptr[k] : rptr[k]));
					}
					j = rpos - 2;
				}
			}
		}
}

