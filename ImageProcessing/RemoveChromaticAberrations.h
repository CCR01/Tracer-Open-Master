#pragma once

// structs
#include "structsRemoveChromAber.h"

// Math
#include "..\LowLevelTracing\Math_LLT.h"



class RemoveChromaticAberrations
{
public:
	RemoveChromaticAberrations();
	~RemoveChromaticAberrations();

	// super function
	void removeChromaticAberrations_superFct(cv::Mat sharpImage, cv::Mat blueredImage);
	// find best parameter and save
	void findBestParameter();
	void setInitialParameter(initialPararemChromAber iniParaChromAber);
	bestParaRemChromAber getBestParameter();
	void calcROI_toCalcDif();

	// get filtered image
	cv::Mat getFilterdIma();

	// *** RayXie29
	void CACorrection_RayXie29(cv::Mat& Src, cv::Mat& Dst, int threshold);
	void rmCA_RayXie29(std::vector<cv::Mat>& bgrVec, int threshold);

private:
	cv::Mat mSharpImage{};
	cv::Mat mTempFilteredImage{};
	cv::Mat mBlueredImage{};
	cv::Mat mTempDifMat{};

	initialPararemChromAber mInitialParameter{};
	bestParaRemChromAber mBestParameter{};
	cv::Rect mRoiToCalcDif{};

	std::vector<cv::Mat> mBGR_Vec;
	std::vector<cv::Mat> mBGR_Vec_transposed;
	int mHeight;
	int	mWidth;



};


