#pragma once

// important structs
#include "..\LowLevelTracing/ImportantStructures.h"

// open cv
#include <opencv2\opencv.hpp>

struct initialPararemChromAber
{
public:
	initialPararemChromAber();
	~initialPararemChromAber();
	// thresold
	void setMinThreshold(int minThreshold);
	int	getMinThreshold();
	void setMaxThreshold(int maxThreshold);
	int	getMaxThreshold();
	void setStepsThreshold(int stepsThresold);
	int	getStepsThreshold();

	// compare in percent
	void setCompateInPercent(real compareInPercent);
	real getCompateInPercent();

	// sharpness evaluation methode
	sharpnessEvalMethode getSharpnessEvalMethode();
	void setSharpnessEvalMethode(sharpnessEvalMethode sharpEvalMethode);

	void checkStepsThreshold();

private:
	int mMinThreshold{};
	int mMaxThreshold{};
	int mStepsThreshold{};
	real mCompareInPercent{};
	sharpnessEvalMethode mSharpEvalMethode{};
};


struct bestParaRemChromAber
{
public:
	bestParaRemChromAber();
	~bestParaRemChromAber();
	// thresold
	void setThreshold(int threshold);
	int getThreshold();
	// improvement
	void setImprovement(real improvement);
	real getImprovement();
	// quality
	void setDifference(real difference);
	real getDifference();
	// image
	void setImage(cv::Mat ima);
	cv::Mat getImage();
	// sharpness
	void setSharpness(real sharpness);
	real getSharpness();

	// print parameters remove chromatic aberrations
	void printPara_RemChromAber_Struct();

	// export as txt fiel
	void exportAsTXTfile(std::string loaction, std::string name, bool clearTXT);

private:
	int mThreshold;
	real mImprovement;
	real mDifference;
	cv::Mat mImage;
	real mSharpness;
};