#pragma once

#include "..\LowLevelTracing/ImportantStructures.h"

#include <opencv2/core/core.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/ml/ml.hpp"
#include <iostream>


struct parameterDetailEnhancement
{
public:
	parameterDetailEnhancement();
	~parameterDetailEnhancement();

	// sigma s
	float getMinSigma_s();
	void setMinSigma_s(float minSigma_s);
	float getMaxSigma_s();
	void setMaxSigma_s(float maxSigma_s);
	float getStepsSigma_s();
	void setStepsSigma_s(float stepsSigma_s);
	// sigma r
	float getMinSigma_r();
	void setMinSigma_r(float minSigma_r);
	float getMaxSigma_r();
	void setMaxSigma_r(float maxSigma_r);
	float getStepsSigma_r();
	void setStepsSigma_r(float stepsSigma_r);
	// percent to compare
	real getPercentCompare();
	void setPercentCompare(real percentComp);
	// sharpness evaluation methode
	sharpnessEvalMethode getSharpnessEvalMethode();
	void setSharpnessEvalMethode(sharpnessEvalMethode sharpEvalMethode);

private:
	float mMinSigmar_s;
	float mMaxSigmar_s;
	float mStepsSigmar_s;
	float mMinSigmar_r;
	float mMaxSigmar_r;
	float mStepsSigmar_r;
	real mPercentComp;
	sharpnessEvalMethode mSharpEvalMethode{};
};

struct bestParameterStruct_detailEnhance
{
	bestParameterStruct_detailEnhance();
	~bestParameterStruct_detailEnhance();

	// set image
	void setImage(cv::Mat image);
	// get image
	cv::Mat getImage();
	//set best result
	void setDifference(double dif);
	// get best result
	real getDifference();
	// set sigmar s
	void setSigmar_s(float sigmar_s);
	// get sigmar s
	float getSigmar_s();
	// set sigmar r
	void setSigmar_r(float sigmar_r);
	// get sigmar r
	float getSigmar_r();

	// set improvement
	void setImprovement(real improvement);
	// get improvement
	real getImprovement();

	// set best core number
	void setBestCoreNumber(int bestCoreNumber);
	// get best core number
	int getbestCoreNumber();

	//sharpness
	void setSharpness(real sharpness);
	real getShrarpness();

	// print parameters detailEnhanceStruct
	void printPara_DetailEnhance_Struct();

	// export as txt fiel
	void exportAsTXTfile(std::string loaction, std::string name, bool clearTXT);

private:
	cv::Mat mImage{};
	float mSigmar_s{};
	float mSigmar_r{};
	real mDifference{};
	real mImprovement{};
	real mSharpness{};
	int mBestCoreNumber{};

};
