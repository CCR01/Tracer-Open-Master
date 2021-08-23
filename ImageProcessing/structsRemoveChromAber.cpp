
#include "structsRemoveChromAber.h"

initialPararemChromAber::initialPararemChromAber() {}
initialPararemChromAber::~initialPararemChromAber() {}
// thresold
void initialPararemChromAber::setMinThreshold(int minThreshold)
{
	mMinThreshold = minThreshold;
}
int	initialPararemChromAber::getMinThreshold()
{
	return mMinThreshold;
}
void initialPararemChromAber::setMaxThreshold(int maxThreshold)
{
	mMaxThreshold = maxThreshold;
}
int	initialPararemChromAber::getMaxThreshold()
{
	return mMaxThreshold;
}
void initialPararemChromAber::setStepsThreshold(int stepsThresold)
{
	mStepsThreshold = stepsThresold;
	checkStepsThreshold();
}
int	initialPararemChromAber::getStepsThreshold()
{
	return mStepsThreshold;
}


// compare in percent
void initialPararemChromAber::setCompateInPercent(real compareInPercent)
{
	mCompareInPercent = compareInPercent;
}
real initialPararemChromAber::getCompateInPercent()
{
	return mCompareInPercent;
}

// sharpness evaluation methode
sharpnessEvalMethode initialPararemChromAber::getSharpnessEvalMethode()
{
	return mSharpEvalMethode;
}
void initialPararemChromAber::setSharpnessEvalMethode(sharpnessEvalMethode sharpEvalMethode)
{
	mSharpEvalMethode = sharpEvalMethode;
}

void initialPararemChromAber::checkStepsThreshold()
{
	int maxSteps = mMaxThreshold - mMinThreshold;

	if (maxSteps < mStepsThreshold)
	{
		mStepsThreshold = maxSteps;
	}
}

bestParaRemChromAber::bestParaRemChromAber() {};
bestParaRemChromAber::~bestParaRemChromAber() {};
// thresold
void bestParaRemChromAber::setThreshold(int threshold)
{
	mThreshold = threshold;
}
int bestParaRemChromAber::getThreshold()
{
	return mThreshold;
}
// improvement
void bestParaRemChromAber::setImprovement(real improvement)
{
	mImprovement = improvement;
}
real bestParaRemChromAber::getImprovement()
{
	return mImprovement;
}
// quality
void bestParaRemChromAber::setDifference(real difference)
{
	mDifference = difference;
}
real bestParaRemChromAber::getDifference()
{
	return mDifference;
}
// image
void bestParaRemChromAber::setImage(cv::Mat ima)
{
	mImage = ima;
}
cv::Mat bestParaRemChromAber::getImage()
{
	return mImage;
}
// sharpness
void bestParaRemChromAber::setSharpness(real sharpness)
{
	mSharpness = sharpness;
}
real bestParaRemChromAber::getSharpness()
{
	return mSharpness;
}

// print parameters remove chromatic aberrations
void bestParaRemChromAber::printPara_RemChromAber_Struct()
{
	std::cout << "" << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "remove chromatic aberrations" << std::endl;
	std::cout << "thresold: " << mThreshold << std::endl;
	std::cout << "improvement: " << mImprovement << std::endl;
	std::cout << "sharpness: " << mSharpness << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "" << std::endl;
}


// export as txt fiel
void bestParaRemChromAber::exportAsTXTfile(std::string loaction, std::string name, bool clearTXT)
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
		file << "remove chromatic aberrations parameter" << std::endl;
		file << "threshold: " << mThreshold << std::endl;
		file << "quality: " << mDifference << std::endl;
		file << "improvement: " << mImprovement << std::endl;
		file << "sharpness: " << mSharpness << std::endl;
		file << "___________________________________" << std::endl;
		file << "" << std::endl;
	}
	file.close();
}