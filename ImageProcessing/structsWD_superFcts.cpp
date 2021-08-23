#include "structsWD_superFcts.h"
#include <iostream>
#include <fstream>

parameterImaImprove_WD::parameterImaImprove_WD() {};
parameterImaImprove_WD::~parameterImaImprove_WD() {};

// min SNR
real parameterImaImprove_WD::getMinSNR()
{
	return mMinSNR;
}
void parameterImaImprove_WD::setMinSNR(real minSNR)
{
	mMinSNR = minSNR;
}
// max SNR
real parameterImaImprove_WD::getMaxSNR()
{
	return mMaxSNR;
}
void parameterImaImprove_WD::setMaxSNR(real maxSNR)
{
	mMaxSNR = maxSNR;
}
// steps SNR
real parameterImaImprove_WD::getStepsSNR()
{
	return mStepsSNR;
}
void parameterImaImprove_WD::setStepsSNR(real stepsSNR)
{
	mStepsSNR = stepsSNR;
}
// min sigma
real parameterImaImprove_WD::getMinSigmaXY()
{
	return mMinSigmaXY;
}
void parameterImaImprove_WD::setMinSigmaXY(real minSigmaXY)
{
	mMinSigmaXY = minSigmaXY;
}
// max sigma
real parameterImaImprove_WD::getMaxSigmaXY()
{
	return mMaxSigmaXY;
}
void parameterImaImprove_WD::setMaxSigmaXY(real maxSigmaXY)
{
	mMaxSigmaXY = maxSigmaXY;
}
// steps sigma
real parameterImaImprove_WD::getStepsSigmaXY()
{
	return mStepsSigmaXY;
}
void parameterImaImprove_WD::setStepsSigmaXY(real stepsSigmaXY)
{
	mStepsSigmaXY = stepsSigmaXY;
}
// kernel size
int parameterImaImprove_WD::getKernelSizeHeightAndWidth()
{
	return mKernelSizeHeightAndWidth;
}
void parameterImaImprove_WD::setKernelSizeHeightAndWidth(int kernelSizeHeightAndWidth)
{
	mKernelSizeHeightAndWidth = kernelSizeHeightAndWidth;
}
// compare in percent
real parameterImaImprove_WD::getCompareInPercent()
{
	return mCompareInPercent;
}
void parameterImaImprove_WD::setCompareInPercent(real percent)
{
	mCompareInPercent = percent;
}

// sharpness evaluation methode
sharpnessEvalMethode parameterImaImprove_WD::getSharpnessEvalMethode()
{
	return mSharpEvalMethode;
}
void parameterImaImprove_WD::setSharpnessEvalMethode(sharpnessEvalMethode sharpEvalMethode)
{
	mSharpEvalMethode = sharpEvalMethode;
}

saveBestParameterWD::saveBestParameterWD() {};
saveBestParameterWD::~saveBestParameterWD() {};

// best PSF
cv::Mat saveBestParameterWD::getBestPSF()
{
	return mBestPSF;
}
void saveBestParameterWD::setBestPSF(cv::Mat bestPSF)
{
	mBestPSF = bestPSF;
}
// best filter
cv::Mat saveBestParameterWD::getBestFilter()
{
	return mBestWienerFilter;
}
void saveBestParameterWD::setBestFilter(cv::Mat bestFitler)
{
	mBestWienerFilter = bestFitler;
}
// best SNR
real saveBestParameterWD::getBestSNR()
{
	return mBestSNR;
}
void saveBestParameterWD::setBestSNR(real bestSNR)
{
	mBestSNR = bestSNR;
}
// best reconstruction
cv::Mat saveBestParameterWD::getBestReconstruction()
{
	return mBestReconstruction;
}
void saveBestParameterWD::setBestReconstruction(cv::Mat bestReconstruction)
{
	mBestReconstruction = bestReconstruction;
}
// best Sigma
real saveBestParameterWD::getBestSigma()
{
	return mBestSigma;
}
void saveBestParameterWD::setBestSigma(real bestSigma)
{
	mBestSigma = bestSigma;
}
// best core number
int saveBestParameterWD::getBestCoreNum()
{
	return mBestCoreNum;
}
void saveBestParameterWD::setBestCoreNum(int bestCoreNum)
{
	mBestCoreNum = bestCoreNum;
}
// quality
real saveBestParameterWD::getDifference()
{
	return mDifference;
}
void saveBestParameterWD::setDifference(real quality)
{
	mDifference = quality;
}
// improvement
real saveBestParameterWD::getImprovement()
{
	return mImprovement;
}
void saveBestParameterWD::setImprovement(real improvement)
{
	mImprovement = improvement;
}
// sharpness
real saveBestParameterWD::getSharpness()
{
	return mSharpness;
}
void saveBestParameterWD::setSharpness(real sharpness)
{
	mSharpness = sharpness;
}

// print parameters wiener filter
void saveBestParameterWD::printPara_wienerFilter_Struct()
{
	std::cout << "" << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "wiener filter:" << std::endl;
	std::cout << "sigma: " << mBestSigma << std::endl;
	std::cout << "SNR: " << mBestSNR << std::endl;
	std::cout << "difference: " << mDifference << std::endl;
	std::cout << "improvement " << mImprovement << std::endl;
	std::cout << "sharpness " << mSharpness << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "" << std::endl;

}

// export as txt fiel
void saveBestParameterWD::exportAsTXTfile(std::string loaction, std::string name, bool clearTXT)
{


	std::string locationAndName = loaction + "/" + name + ".txt";

	if (clearTXT)
	{
		std::ofstream file;
		file.open(locationAndName, std::ofstream::out | std::ofstream::trunc);
		file.close();
	}

	std::ofstream file;
	file.open(locationAndName, std::ios_base::app);
	if (file.is_open())
	{
		file << "" << std::endl;
		file << "___________________________________" << std::endl;
		file << "wiener filter" << std::endl;
		file << "sigma: " << mBestSigma << std::endl;
		file << "SNR: " << mBestSNR << std::endl;
		file << "difference: " << mDifference << std::endl;
		file << "improvement: " << mImprovement << std::endl;
		file << "sharpness: " << mSharpness << std::endl;
		file << "___________________________________" << std::endl;
		file << "" << std::endl;
	}
	file.close();
}