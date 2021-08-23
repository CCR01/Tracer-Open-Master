#pragma once

// important structs for WD
#include "structsWD_superFcts.h"

// for gray images
class WienerDeconvolutionSF_Gray
{
public:
	WienerDeconvolutionSF_Gray();
	~WienerDeconvolutionSF_Gray();

	// load basic parameter
	void loadBasicParameterBGR();
	// set basic parameter
	void setBasicParameter(parameterImaImprove_WD paraWD_parallel);
	// improve image quality 
	void improveImaQual_WD_superFct_gray(const cv::Mat sharpGrayImage, const cv::Mat blueredGrayImage);
	// check size sharp and bluered image
	void checkSizeSharpAndBlueredImage();
	// norm sharp and bluered image
	void normeSharpAndBlueredImage();
	// calc roi to calc dif
	void calcROI_toCalcDif();
	// find best psf and SNR
	void findBestSNRandPSF();
	// build PSF
	void buildPSF(real sigmaXY, cv::Mat& psf);
	// build gauss kernel
	void buildGaussianKernel(real sigmaXY);
	// calc wiener filter
	void calcWnrFilter_CV(const cv::Mat& input_h_PSF, cv::Mat& output_G, double nsr);
	// do wiener filtering
	void filter2DFreq_CV(const cv::Mat& inputImg, cv::Mat& outputImg, const cv::Mat& H);
	// fft shift
	void fftshift_CV(const cv::Mat& inputImg, cv::Mat& outputImg);
	// calc difference gray image
	int calcAbsDifGrayImage_uni8(const cv::Mat& sharpIma, const cv::Mat& filterdIma);
	// calculate improvement
	real calculateImprovement(const cv::Mat& sharpIma, const cv::Mat& blueredIma, const cv::Mat& filteredIma);
	// get best parameter
	saveBestParameterWD getBestParameter();
	// get Parameter
	parameterImaImprove_WD getParameter();

private:
	cv::Mat mSharpGrayImage{};
	cv::Mat mBlueredGrayImages{};

	parameterImaImprove_WD mParaImaImproveWD_gray{};
	saveBestParameterWD mBestParameter{};

	cv::Rect mRoiToCalcDif{};
	cv::Mat mPSF{};
	cv::Mat mGaussKernel{};
	cv::Mat mWienerFilter{};
	cv::Mat mFilterResultIma{};
	cv::Mat mTempDifMat{};

	// *** calcWnrFilter_CV
	cv::Mat mH_PSF_shifted{};
	cv::Mat mComplexI_wnrFilter{};
	cv::Mat mDenom{};
	// ***

	// *** filter2DFreq_CV
	cv::Mat mComplexI_filter2DFreq{};
	cv::Mat complexH_filter2DFreq{};
	cv::Mat complexIH_filter2DFreq{};

	// *** fftshift_CV
	cv::Mat mTmp_fftshift{};
};

// for gray image parallel
class WienerDeconvolutionSF_parallel_Gray
{
public:
	WienerDeconvolutionSF_parallel_Gray();
	~WienerDeconvolutionSF_parallel_Gray();
	// set basic parameter
	void setBasicParameter(parameterImaImprove_WD paraWD_parallel);
	// improve image quality 
	void improveImaQual_WD_superFct_gray_parallel(const cv::Mat sharpGrayImage, const cv::Mat blueredGrayImage);
	// initialize parameter for difference cores
	void initializePrameterDifCores();
	// optimize image quality on difference cores
	void improveImaQual_WD_superFct_gray_parallel();
	// find best parameter
	void findBestParameterAllCores();

	// get paramter for image processing
	parameterImaImprove_WD getParamerterImaImorove();
	// get best SNR and simga
	saveBestParameterWD getBestParameter();


private:
	cv::Mat mSharpGrayImage{};
	cv::Mat mBlueredGrayImages{};
	parameterImaImprove_WD mParaImaImproveWD_gray_global{};

	// classes
	WienerDeconvolutionSF_Gray mWienderDeconSF_Gray_Core1{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_Gray_Core2{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_Gray_Core3{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_Gray_Core4{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_Gray_Core5{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_Gray_Core6{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_Gray_Core7{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_Gray_Core8{};

	parameterImaImprove_WD mParaImaImproveWD_gray_Core1{};
	parameterImaImprove_WD mParaImaImproveWD_gray_Core2{};
	parameterImaImprove_WD mParaImaImproveWD_gray_Core3{};
	parameterImaImprove_WD mParaImaImproveWD_gray_Core4{};
	parameterImaImprove_WD mParaImaImproveWD_gray_Core5{};
	parameterImaImprove_WD mParaImaImproveWD_gray_Core6{};
	parameterImaImprove_WD mParaImaImproveWD_gray_Core7{};
	parameterImaImprove_WD mParaImaImproveWD_gray_Core8{};

	std::vector<real> mImprovements_vec{};
	std::vector<saveBestParameterWD> mSaveAllBestParameters{};
	saveBestParameterWD mBestParameterAllCores{};
};

// for BGR images prarallel
class WienerDeconvolutionSF_parallel_BGR
{
public:
	WienerDeconvolutionSF_parallel_BGR();
	~WienerDeconvolutionSF_parallel_BGR();

	void setParameterWD_Global_blue(parameterImaImprove_WD para_blue);
	void setParameterWD_Global_green(parameterImaImprove_WD para_green);
	void setParameterWD_Global_red(parameterImaImprove_WD para_red);

	// initialize parameter for difference cores
	void initializePrameterDifCores_blue();
	void initializePrameterDifCores_green();
	void initializePrameterDifCores_red();

	void improveImaQual_WD_superFct_BGR_parallel(const cv::Mat sharpBGR_Image, const cv::Mat blueredBGR_Image);
	void findingBestSNRandSigma_BGR_parallel();
	void splitImagesInBGR();
	void calcMinMax();
	void putChannlesTogehter();
	void normTheGrayImagesAccordingToSharpIma();

	cv::Mat getFilteredResults_normedLikeSharpIma();
	cv::Mat getFilteredResults_normedZeroAndMaxUchar();
	saveBestParameterWD getBestParameter_blue();
	saveBestParameterWD getBestParameter_green();
	saveBestParameterWD getBestParameter_red();

	parameterImaImprove_WD getInitialPara_blue();
	parameterImaImprove_WD getInitialPara_green();
	parameterImaImprove_WD getInitialPara_red();

	// find best parameter
	void findBestParameterAllCores_blue();
	void findBestParameterAllCores_green();
	void findBestParameterAllCores_red();

private:
	cv::Mat mSharpImage_blue{};
	cv::Mat mSharpImage_green{};
	cv::Mat mSharpImage_red{};
	cv::Mat mSharpImage_BGR{};

	cv::Mat mBlueredImage_blue{};
	cv::Mat mBlueredImage_green{};
	cv::Mat mBlueredImage_red{};
	cv::Mat mBlueredImage_BGR{};


	parameterImaImprove_WD mParaImaImproveWD_blue_global{};
	parameterImaImprove_WD mParaImaImproveWD_green_global{};
	parameterImaImprove_WD mParaImaImproveWD_red_global{};


	saveBestParameterWD mBestParameterGlobal_blue{};
	saveBestParameterWD mBestParameterGlobal_green{};
	saveBestParameterWD mBestParameterGlobal_red{};

	std::vector<real> mImprovements_vec_blue{};
	std::vector<real> mImprovements_vec_green{};
	std::vector<real> mImprovements_vec_red{};

	std::vector<real> mSharpness_vec_blue{};
	std::vector<real> mSharpness_vec_green{};
	std::vector<real> mSharpness_vec_red{};


	std::vector<saveBestParameterWD> mSaveAllBestParameters_blue{};
	std::vector<saveBestParameterWD> mSaveAllBestParameters_green{};
	std::vector<saveBestParameterWD> mSaveAllBestParameters_red{};

	cv::Mat mFilterResultIma_BGR_normedLikeSharpIma;
	cv::Mat mFilterResultIma_blue_normedSharpBlue;
	cv::Mat mFilterResultIma_green_normedSharpGreen;
	cv::Mat mFilterResultIma_red__normedSharpRed;


	int mMin_blue;
	int mMax_blue;
	int mMin_green;
	int mMax_green;
	int mMin_red;
	int mMax_red;


	// _blue
	WienerDeconvolutionSF_Gray mWienderDeconSF_blue_Core1{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_blue_Core2{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_blue_Core3{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_blue_Core4{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_blue_Core5{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_blue_Core6{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_blue_Core7{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_blue_Core8{};

	parameterImaImprove_WD mParaImaImproveWD_blue_Core1{};
	parameterImaImprove_WD mParaImaImproveWD_blue_Core2{};
	parameterImaImprove_WD mParaImaImproveWD_blue_Core3{};
	parameterImaImprove_WD mParaImaImproveWD_blue_Core4{};
	parameterImaImprove_WD mParaImaImproveWD_blue_Core5{};
	parameterImaImprove_WD mParaImaImproveWD_blue_Core6{};
	parameterImaImprove_WD mParaImaImproveWD_blue_Core7{};
	parameterImaImprove_WD mParaImaImproveWD_blue_Core8{};

	// _green
	WienerDeconvolutionSF_Gray mWienderDeconSF_green_Core1{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_green_Core2{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_green_Core3{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_green_Core4{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_green_Core5{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_green_Core6{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_green_Core7{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_green_Core8{};

	parameterImaImprove_WD mParaImaImproveWD_green_Core1{};
	parameterImaImprove_WD mParaImaImproveWD_green_Core2{};
	parameterImaImprove_WD mParaImaImproveWD_green_Core3{};
	parameterImaImprove_WD mParaImaImproveWD_green_Core4{};
	parameterImaImprove_WD mParaImaImproveWD_green_Core5{};
	parameterImaImprove_WD mParaImaImproveWD_green_Core6{};
	parameterImaImprove_WD mParaImaImproveWD_green_Core7{};
	parameterImaImprove_WD mParaImaImproveWD_green_Core8{};

	// _red
	WienerDeconvolutionSF_Gray mWienderDeconSF_red_Core1{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_red_Core2{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_red_Core3{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_red_Core4{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_red_Core5{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_red_Core6{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_red_Core7{};
	WienerDeconvolutionSF_Gray mWienderDeconSF_red_Core8{};

	parameterImaImprove_WD mParaImaImproveWD_red_Core1{};
	parameterImaImprove_WD mParaImaImproveWD_red_Core2{};
	parameterImaImprove_WD mParaImaImproveWD_red_Core3{};
	parameterImaImprove_WD mParaImaImproveWD_red_Core4{};
	parameterImaImprove_WD mParaImaImproveWD_red_Core5{};
	parameterImaImprove_WD mParaImaImproveWD_red_Core6{};
	parameterImaImprove_WD mParaImaImproveWD_red_Core7{};
	parameterImaImprove_WD mParaImaImproveWD_red_Core8{};


};









