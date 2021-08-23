
#include "structsUnsharpMasking_superFcts.h"
#include <fstream>

parameterUnsharpMasking::parameterUnsharpMasking() {};
parameterUnsharpMasking::~parameterUnsharpMasking() {};

// sigma 
void parameterUnsharpMasking::setMinSigma(real minSigma)
{
	mMinSigma = minSigma;
}
real parameterUnsharpMasking::getMinSigma()
{
	return mMinSigma;
}
void parameterUnsharpMasking::setMaxSigma(real maxSigma)
{
	mMaxSigma = maxSigma;
}
real parameterUnsharpMasking::getMaxSigma()
{
	return mMaxSigma;
}
void parameterUnsharpMasking::setStepsSigma(real stepsSigma)
{
	mStepsSigma = stepsSigma;
}
real parameterUnsharpMasking::getStepsSigma()
{
	return mStepsSigma;
}


// threshold
void parameterUnsharpMasking::setMinThreshold(real minThreshold)
{
	mMinThreshold = minThreshold;
}
real parameterUnsharpMasking::getMinThreshold()
{
	return mMinThreshold;
}
void parameterUnsharpMasking::setMaxThreshold(real maxThreshold)
{
	mMaxThreshold = maxThreshold;
}
real parameterUnsharpMasking::getMaxThreshold()
{
	return mMaxThreshold;
}
void parameterUnsharpMasking::setStepsThreshold(real stepsThreshold)
{
	mStepsThreshold = stepsThreshold;
}
real parameterUnsharpMasking::getStepsThreshold()
{
	return mStepsThreshold;
}
// amount
void parameterUnsharpMasking::setMinAmount(real minAmount)
{
	mMinAmount = minAmount;
}
real parameterUnsharpMasking::getMinAmount()
{
	return mMinAmount;
}
void parameterUnsharpMasking::setMaxAmount(real maxAmount)
{
	mMaxAmount = maxAmount;
}
real parameterUnsharpMasking::getMaxAmount()
{
	return mMaxAmount;
}
void parameterUnsharpMasking::setStepsAmount(real stepsAmount)
{
	mStepsAmount = stepsAmount;
}
real parameterUnsharpMasking::getStepsAmount()
{
	return mStepsAmount;
}

// boarder type
void parameterUnsharpMasking::setBoarderType(int boarderType)
{
	mBoarderType = boarderType;
}
int parameterUnsharpMasking::getBoarderType()
{
	return mBoarderType;
}
// compare in percent
void parameterUnsharpMasking::setCompareInPercent(real compareInPercent)
{
	mCompareInPercent = compareInPercent;
}
real parameterUnsharpMasking::getCompareInPercent()
{
	return mCompareInPercent;
}
// sharpness evaluation methode
sharpnessEvalMethode parameterUnsharpMasking::getSharpnessEvalMethode()
{
	return mSharpEvalMethode;
}
void parameterUnsharpMasking::setSharpnessEvalMethode(sharpnessEvalMethode sharpEvalMethode)
{
	mSharpEvalMethode = sharpEvalMethode;
}

bestParameterStruct_unsharpMask::bestParameterStruct_unsharpMask() {};
bestParameterStruct_unsharpMask::~bestParameterStruct_unsharpMask() {};

// set image
void bestParameterStruct_unsharpMask::setImage(const cv::Mat& image)
{
	mImage = image;
}
// get image
cv::Mat bestParameterStruct_unsharpMask::getImage() const
{
	return mImage;
}
// set quality
void bestParameterStruct_unsharpMask::setDifference(real const difference)
{
	mDifference = difference;
}
// get quality
real bestParameterStruct_unsharpMask::getDifference() const
{
	return mDifference;
}
// get sigma
real bestParameterStruct_unsharpMask::getSigma() const
{
	return mSigma;
}
// set sigma
void bestParameterStruct_unsharpMask::setSigma(real const sigma)
{
	mSigma = sigma;
}

// get threshold
real bestParameterStruct_unsharpMask::getThreshold() const
{
	return mThreshold;
}
// set threshold
void bestParameterStruct_unsharpMask::setThreshold(real const threshold)
{
	mThreshold = threshold;
}
// get amount
real bestParameterStruct_unsharpMask::getAmount() const
{
	return mAmount;
}
// set amout
void bestParameterStruct_unsharpMask::setAmount(real const amount)
{
	mAmount = amount;
}
// get boarder type
int bestParameterStruct_unsharpMask::getBoarderType() const
{
	return mBoarderType;
}
// set boarder type
void bestParameterStruct_unsharpMask::setBoarderType(int const boarderType)
{
	mBoarderType = boarderType;
}
// get best core number
int bestParameterStruct_unsharpMask::getBestCoreNumber()
{
	return mBestCoreNumber;
}
// set best core number
void bestParameterStruct_unsharpMask::setBestCoreNumber(int bestCoreNum)
{
	mBestCoreNumber = bestCoreNum;
}
// set improvement
void bestParameterStruct_unsharpMask::setImprovement(real const improvement)
{
	mImprovement = improvement;
}
// get improvement
real bestParameterStruct_unsharpMask::getImprovement()
{
	return mImprovement;
}

// sharpness
void bestParameterStruct_unsharpMask::setSharpness(real sharpness)
{
	mSharpness = sharpness;
}
real bestParameterStruct_unsharpMask::getSharpness()
{
	return mSharpness;
}

// print parameters unsharp masking filter
void bestParameterStruct_unsharpMask::printPara_UnsharpMaskinFilter_Struct()
{
	std::cout << "" << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "unsharp mask" << std::endl;
	std::cout << "sigma: " << mSigma << std::endl;
	std::cout << "boarder type: " << mBoarderType << std::endl;
	std::cout << "threshold: " << mThreshold << std::endl;
	std::cout << "amount: " << mAmount << std::endl;
	std::cout << "difference: " << mDifference << std::endl;
	std::cout << "improvement: " << mImprovement << std::endl;
	std::cout << "sharpness: " << mSharpness << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "" << std::endl;
}

// export as txt fiel
void bestParameterStruct_unsharpMask::exportAsTXTfile(std::string loaction, std::string name, bool clearTXT)
{
	std::string locationAndName = loaction + "/" + name + ".txt";

	if (clearTXT)
	{
		if (clearTXT)
		{
			std::ofstream file;
			file.open(locationAndName, std::ofstream::out | std::ofstream::trunc);
			file.close();
		}
	}

	std::ofstream file;
	file.open(locationAndName, std::ios_base::app);
	if (file.is_open())
	{
		file << "" << std::endl;
		file << "___________________________________" << std::endl;
		file << "unsharp mask parameter" << std::endl;
		file << "sigma: " << mSigma << std::endl;
		file << "boarder type: " << mBoarderType << std::endl;
		file << "threshold: " << mThreshold << std::endl;
		file << "amount: " << mAmount << std::endl;
		file << "improvement: " << mImprovement << std::endl;
		file << "sharpness: " << mSharpness << std::endl;
		file << "___________________________________" << std::endl;
		file << "" << std::endl;
	}
	file.close();
}