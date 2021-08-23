#pragma once

// open cv
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/calib3d/calib3d.hpp>
//#include <opencv2/imgcodecs.hpp>
#include <opencv2/photo.hpp>

// important structs
#include "..\LowLevelTracing\ImportantStructures.h"

struct parameterImaImprove_WD
{
public:
	parameterImaImprove_WD();
	~parameterImaImprove_WD();

	// min SNR
	real getMinSNR();
	void setMinSNR(real minSNR);
	// max SNR
	real getMaxSNR();
	void setMaxSNR(real maxSNR);
	// delta SNR
	real getStepsSNR();
	void setStepsSNR(real stepsSNR);
	// min sigma
	real getMinSigmaXY();
	void setMinSigmaXY(real minSigmaXY);
	// max sigma
	real getMaxSigmaXY();
	void setMaxSigmaXY(real maxSigmaXY);
	// delta sigma
	real getStepsSigmaXY();
	void setStepsSigmaXY(real stepsSigmaXY);
	// kernel size
	int getKernelSizeHeightAndWidth();
	void setKernelSizeHeightAndWidth(int kernelSizeHeightAndWidth);
	// compare in percent
	real getCompareInPercent();
	void setCompareInPercent(real percent);
	// sharpness evaluation methode
	sharpnessEvalMethode getSharpnessEvalMethode();
	void setSharpnessEvalMethode(sharpnessEvalMethode sharpEvalMethode);

private:

	real mMinSNR;
	real mMaxSNR;
	real mStepsSNR;
	real mMinSigmaXY;
	real mMaxSigmaXY;
	real mStepsSigmaXY;
	int mKernelSizeHeightAndWidth;
	real mCompareInPercent;
	sharpnessEvalMethode mSharpEvalMethode{};
};

struct saveBestParameterWD
{
public:
	saveBestParameterWD();
	~saveBestParameterWD();

	// best PSF
	cv::Mat getBestPSF();
	void setBestPSF(cv::Mat bestPSF);
	// best filter
	cv::Mat getBestFilter();
	void setBestFilter(cv::Mat bestFitler);
	// best SNR
	real getBestSNR();
	void setBestSNR(real bestSNR);
	// best reconstruction
	cv::Mat getBestReconstruction();
	void setBestReconstruction(cv::Mat bestReconstruction);
	// best Sigma
	real getBestSigma();
	void setBestSigma(real bestSigma);
	// best core number
	int getBestCoreNum();
	void setBestCoreNum(int bestCoreNum);
	// quality
	real getDifference();
	void setDifference(real difference);
	// improvement
	real getImprovement();
	void setImprovement(real improvement);
	// sharpness
	real getSharpness();
	void setSharpness(real sharpness);


	// print parameters wiener filter
	void printPara_wienerFilter_Struct();

	// export as txt fiel
	void exportAsTXTfile(std::string loaction, std::string name, bool clearTXT);

private:
	cv::Mat mBestPSF{};
	cv::Mat mBestWienerFilter{};
	cv::Mat mBestReconstruction{};
	real mBestSNR;
	real mBestSigma;
	int mBestCoreNum;
	real mDifference;
	real mImprovement;
	real mSharpness;
};
