#include "structDetailEnhancement_superFct.h"
#include <fstream>

parameterDetailEnhancement::parameterDetailEnhancement() {};
parameterDetailEnhancement::~parameterDetailEnhancement() {};

// sigma s
float parameterDetailEnhancement::getMinSigma_s()
{
	return mMinSigmar_s;
}
void parameterDetailEnhancement::setMinSigma_s(float minSigma_s)
{
	mMinSigmar_s = minSigma_s;
}
float parameterDetailEnhancement::getMaxSigma_s()
{
	return mMaxSigmar_s;
}
void parameterDetailEnhancement::setMaxSigma_s(float maxSigma_s)
{
	mMaxSigmar_s = maxSigma_s;
}
float parameterDetailEnhancement::getStepsSigma_s()
{
	return mStepsSigmar_s;
}
void parameterDetailEnhancement::setStepsSigma_s(float stepsSigma_s)
{
	mStepsSigmar_s = stepsSigma_s;
}
// sigma r
float parameterDetailEnhancement::getMinSigma_r()
{
	return mMinSigmar_r;
}
void parameterDetailEnhancement::setMinSigma_r(float minSigma_r)
{
	mMinSigmar_r = minSigma_r;
}
float parameterDetailEnhancement::getMaxSigma_r()
{
	return mMaxSigmar_r;
}
void parameterDetailEnhancement::setMaxSigma_r(float maxSigma_r)
{
	mMaxSigmar_r = maxSigma_r;
}
float parameterDetailEnhancement::getStepsSigma_r()
{
	return mStepsSigmar_r;
}
void parameterDetailEnhancement::setStepsSigma_r(float stepsSigma_r)
{
	mStepsSigmar_r = stepsSigma_r;
}
// percent to compare
real parameterDetailEnhancement::getPercentCompare()
{
	return mPercentComp;
}
void parameterDetailEnhancement::setPercentCompare(real percentComp)
{
	mPercentComp = percentComp;
}
// sharpness evaluation methode
sharpnessEvalMethode parameterDetailEnhancement::getSharpnessEvalMethode()
{
	return mSharpEvalMethode;
}
void parameterDetailEnhancement::setSharpnessEvalMethode(sharpnessEvalMethode sharpEvalMethode)
{
	mSharpEvalMethode = sharpEvalMethode;
}

bestParameterStruct_detailEnhance::bestParameterStruct_detailEnhance() {};
bestParameterStruct_detailEnhance::~bestParameterStruct_detailEnhance() {};

// set image
void bestParameterStruct_detailEnhance::setImage(const cv::Mat  image)
{
	mImage = image;
}

// get image
cv::Mat bestParameterStruct_detailEnhance::getImage()
{
	return mImage;
}

//set best result
void bestParameterStruct_detailEnhance::setDifference(double dif)
{
	mDifference = dif;
}
// get best result
real bestParameterStruct_detailEnhance::getDifference()
{
	return mDifference;
}
// set sigmar s
void bestParameterStruct_detailEnhance::setSigmar_s(float sigmar_s)
{
	mSigmar_s = sigmar_s;
}
// get sigmar s
float bestParameterStruct_detailEnhance::getSigmar_s()
{
	return mSigmar_s;
}
// set sigmar r
void bestParameterStruct_detailEnhance::setSigmar_r(float sigmar_r)
{
	mSigmar_r = sigmar_r;
}
// get sigmar r
float bestParameterStruct_detailEnhance::getSigmar_r()
{
	return mSigmar_r;
}

// set improvement
void bestParameterStruct_detailEnhance::setImprovement(real improvement)
{
	mImprovement = improvement;
}
// get improvement
real bestParameterStruct_detailEnhance::getImprovement() {
	return mImprovement;
}

// set best core number
void bestParameterStruct_detailEnhance::setBestCoreNumber(int bestCoreNumber)
{
	mBestCoreNumber = bestCoreNumber;
}
// get best core number
int bestParameterStruct_detailEnhance::getbestCoreNumber()
{
	return mBestCoreNumber;
}

//sharpness
void bestParameterStruct_detailEnhance::setSharpness(real sharpness)
{
	mSharpness = sharpness;
}
real bestParameterStruct_detailEnhance::getShrarpness()
{
	return mSharpness;
}

// print parameters detailEnhanceStruct
void bestParameterStruct_detailEnhance::printPara_DetailEnhance_Struct()
{
	std::cout << "" << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "detail enhance parameter:" << std::endl;
	std::cout << "sigma s: " << mSigmar_s << std::endl;
	std::cout << "sigma r: " << mSigmar_r << std::endl;
	std::cout << "best core number: " << mBestCoreNumber << std::endl;
	std::cout << "quality: " << mDifference << std::endl;
	std::cout << "improvement " << mImprovement << std::endl;
	std::cout << "sharpness " << mSharpness << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "" << std::endl;

}

// export as txt fiel
void bestParameterStruct_detailEnhance::exportAsTXTfile(std::string loaction, std::string name, bool clearTXT)
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
		file << "detail enhance parameter:" << std::endl;
		file << "sigma r: " << mSigmar_r << std::endl;
		file << "sigma s: " << mSigmar_s << std::endl;
		file << "best core number: " << mBestCoreNumber << std::endl;
		file << "quality: " << mDifference << std::endl;
		file << "improvement " << mImprovement << std::endl;
		file << "sharpness " << mSharpness << std::endl;
		file << "___________________________________" << std::endl;
		file << "" << std::endl;
	}
	file.close();

}