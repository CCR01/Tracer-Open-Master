#pragma once

// structs for WD
#include "WienerDeconvolutionSuperFunctionParallel.h"




class WienerDeconvolutionSuperFunction
{
public:
	WienerDeconvolutionSuperFunction();
	~WienerDeconvolutionSuperFunction();
	void loadBasicParameterBGR();

	// improve image quality 
	void improveImaQual_WD_superFct(const cv::Mat sharpColorImage, const cv::Mat blueredColorImage);
	void splitColorImageInChannels();
	cv::Mat getFilteredImage();
	void putImageChannelsTogether();


	// get best parameter 
	saveBestParameterWD getBestParameter_blue();
	saveBestParameterWD getBestParameter_green();
	saveBestParameterWD getBestParameter_red();

	// set parameer
	void setParameter_blue(parameterImaImprove_WD para_blue);
	void setParameter_green(parameterImaImprove_WD para_green);
	void setParameter_red(parameterImaImprove_WD para_red);

	// get parameter
	parameterImaImprove_WD getParameter_blue();
	parameterImaImprove_WD getParameter_green();
	parameterImaImprove_WD getParameter_red();

private:

	cv::Mat mImageSharp_blue;
	cv::Mat mImageSharp_green;
	cv::Mat mImageSharp_red;

	cv::Mat mBluredIma_blue;
	cv::Mat mBluredIma_green;
	cv::Mat mBluredIma_red;

	parameterImaImprove_WD mParaImaImproveWD_blue{};
	parameterImaImprove_WD mParaImaImproveWD_green{};
	parameterImaImprove_WD mParaImaImproveWD_red{};

	saveBestParameterWD mBestParameter_blue{};
	saveBestParameterWD mBestParameter_green{};
	saveBestParameterWD mBestParameter_red{};
	

	WienerDeconvolutionSF_Gray WD_blue;
	WienerDeconvolutionSF_Gray WD_green;
	WienerDeconvolutionSF_Gray WD_red;

	cv::Mat mSharpColorImage;
	cv::Mat mBlueredColorImage;
	cv::Mat mFilterResultIma_BGR;
};



