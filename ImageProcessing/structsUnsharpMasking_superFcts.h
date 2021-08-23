#pragma once

#include "..\LowLevelTracing/ImportantStructures.h"


#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

struct parameterUnsharpMasking
{
public:
	parameterUnsharpMasking();
	~parameterUnsharpMasking();

	// sigma
	void setMinSigma(real minSigmaX);
	real getMinSigma();
	void setMaxSigma(real maxSigmaX);
	real getMaxSigma();
	void setStepsSigma(real stepsSigmaX);
	real getStepsSigma();
	// threshold
	void setMinThreshold(real minThreshold);
	real getMinThreshold();
	void setMaxThreshold(real maxThreshold);
	real getMaxThreshold();
	void setStepsThreshold(real stepsThreshold);
	real getStepsThreshold();
	// amount
	void setMinAmount(real minAmount);
	real getMinAmount();
	void setMaxAmount(real maxAmount);
	real getMaxAmount();
	void setStepsAmount(real stepsAmount);
	real getStepsAmount();
	// boarder type
	void setBoarderType(int boarderType);
	int getBoarderType();
	// compare in percent
	void setCompareInPercent(real compareInPercent);
	real getCompareInPercent();
	// sharpness evaluation methode
	sharpnessEvalMethode getSharpnessEvalMethode();
	void setSharpnessEvalMethode(sharpnessEvalMethode sharpEvalMethode);

private:
	real mMinSigma{};
	real mMaxSigma{};
	real mStepsSigma{};

	real mMinThreshold{};
	real mMaxThreshold{};
	real mStepsThreshold{};

	real mMinAmount{};
	real mMaxAmount{};
	real mStepsAmount{};

	int mBoarderType{};
	real mCompareInPercent{};

	sharpnessEvalMethode mSharpEvalMethode{};
};


struct bestParameterStruct_unsharpMask
{
public:
	bestParameterStruct_unsharpMask();
	~bestParameterStruct_unsharpMask();

	// set image
	void setImage(const cv::Mat& image);
	// get image
	cv::Mat getImage() const;
	// set quality
	void setDifference(real const quality);
	// get quality
	real getDifference() const;
	// get sigma x
	real getSigma() const;
	// set sigma x
	void setSigma(real const sigmaX);
	// get threshold
	real getThreshold() const;
	// set threshold
	void setThreshold(real const threshold);
	// get amount
	real getAmount() const;
	// set amout
	void setAmount(real const amount);
	// get boarder type
	int getBoarderType() const;
	// set boarder type
	void setBoarderType(int boarderType);
	// get best core number
	int getBestCoreNumber();
	// set best core number
	void setBestCoreNumber(int bestCoreNum);

	// set improvement
	void setImprovement(real const improvement);
	// get improvement
	real getImprovement();

	// sharpness
	void setSharpness(real sharpness);
	real getSharpness();

	// print parameters unsharp masking filter
	void printPara_UnsharpMaskinFilter_Struct();

	// export as txt fiel
	void exportAsTXTfile(std::string loaction, std::string name, bool clearTXT);

private:
	cv::Mat mImage{};
	real mAmount{};
	real mSigma{};
	real mThreshold{};
	real mDifference{};
	int mBoarderType{};
	int mBestCoreNumber{};
	real mImprovement{};
	real mSharpness{};

};