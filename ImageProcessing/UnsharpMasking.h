#pragma once


#include "structsUnsharpMasking_superFcts.h"



class UnshaprMasking_singleCore_gray
{
public:
	UnshaprMasking_singleCore_gray();
	~UnshaprMasking_singleCore_gray();

	void setParameterUM(parameterUnsharpMasking parameterUM);
	void improveImageQuality_unsharpMask_gray(const cv::Mat& sharpImage,const cv::Mat& blueredImage);
	void findBestParameter();
	void unsharpMasking(real sigma, real threshold, real amount);

	// calc roi to calc dif
	void calcROI_toCalcDif();
	// calculate improvement
	real calculateImprovement(const cv::Mat& sharpIma, const cv::Mat& blueredIma, const cv::Mat& filteredIma);
	// calc difference gray image
	int calcAbsDifGrayImage_uni8(const cv::Mat& sharpIma, const cv::Mat& filterdIma);
	// get best parameter
	bestParameterStruct_unsharpMask getBestParameter();

private:
	cv::Mat mSharpImage{};
	cv::Mat mBlueredImage{};
	cv::Mat mTempFilterdImage{};

	cv::Mat mBluerdForUnsharpMasking{};
	cv::Mat mLowContrastMask{};
	cv::Mat mTempDifMat;

	cv::Rect mRoiToCalcDif{};

	parameterUnsharpMasking mParaUM{};
	bestParameterStruct_unsharpMask mBestResult_unsharpMaskStruct{};
};


class UnsharpMasking24_gray
{
public:
	UnsharpMasking24_gray();
	~UnsharpMasking24_gray();

	void improveImaQual_UnsharpMasking_superFct_GRAY_parallel(const cv::Mat sharpBGR_Image, const cv::Mat blueredBGR_Image);

	// finding best parameters unsharp masking gray parallel
	void findingBestParaUM_GRAY_parallel();

	// set parameter
	void setParameterUM_gray(parameterUnsharpMasking paraUM_gray);
	// initialize parameter for difference cores
	void initializePrameterDifCores_gray();
	// get best parameter
	bestParameterStruct_unsharpMask getBestParameter_gray();
	// get initial parameter
	parameterUnsharpMasking getInitialPara_gray();
	// find best parameter
	void findBestParameterAllCores_gray();


private:

	cv::Mat mSharpImage_gray;
	cv::Mat mBlueredImage_gray;
	parameterUnsharpMasking mParaUM_Global_gray;
	bestParameterStruct_unsharpMask mBestParameterGlobal_gray;

	UnshaprMasking_singleCore_gray mUM_singleCore_gray_1{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_2{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_3{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_4{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_5{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_6{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_7{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_8{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_9{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_10{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_11{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_12{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_13{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_14{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_15{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_16{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_17{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_18{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_19{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_20{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_21{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_22{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_23{};
	UnshaprMasking_singleCore_gray mUM_singleCore_gray_24{};


	parameterUnsharpMasking mParaUM_gray_1{};
	parameterUnsharpMasking mParaUM_gray_2{};
	parameterUnsharpMasking mParaUM_gray_3{};
	parameterUnsharpMasking mParaUM_gray_4{};
	parameterUnsharpMasking mParaUM_gray_5{};
	parameterUnsharpMasking mParaUM_gray_6{};
	parameterUnsharpMasking mParaUM_gray_7{};
	parameterUnsharpMasking mParaUM_gray_8{};
	parameterUnsharpMasking mParaUM_gray_9{};
	parameterUnsharpMasking mParaUM_gray_10{};
	parameterUnsharpMasking mParaUM_gray_11{};
	parameterUnsharpMasking mParaUM_gray_12{};
	parameterUnsharpMasking mParaUM_gray_13{};
	parameterUnsharpMasking mParaUM_gray_14{};
	parameterUnsharpMasking mParaUM_gray_15{};
	parameterUnsharpMasking mParaUM_gray_16{};
	parameterUnsharpMasking mParaUM_gray_17{};
	parameterUnsharpMasking mParaUM_gray_18{};
	parameterUnsharpMasking mParaUM_gray_19{};
	parameterUnsharpMasking mParaUM_gray_20{};
	parameterUnsharpMasking mParaUM_gray_21{};
	parameterUnsharpMasking mParaUM_gray_22{};
	parameterUnsharpMasking mParaUM_gray_23{};
	parameterUnsharpMasking mParaUM_gray_24{};


	std::vector<bestParameterStruct_unsharpMask> mBestParaUM_vec_gray{};
	std::vector<real> mImprovements_vec_gray{};
};




class UnshaprMasking_singleCore_BGR
{
public:

	void improveImaQual_UnsharpMasking_superFct_BGR(const cv::Mat sharpBGR_Image, const cv::Mat blueredBGR_Image);

	// calc min max sharp images
	void calcMinMax();

	// set parameter 
	void setParameterUM_blue(parameterUnsharpMasking paraUM_blue);
	void setParameterUM_green(parameterUnsharpMasking paraUM_green);
	void setParameterUM_red(parameterUnsharpMasking paraUM_red);
	// get parameter 
	parameterUnsharpMasking getInitialPara_blue();
	parameterUnsharpMasking getInitialPara_green();
	parameterUnsharpMasking getInitialPara_red();
	// get best parameter
	bestParameterStruct_unsharpMask getBestParameter_blue();
	bestParameterStruct_unsharpMask getBestParameter_green();
	bestParameterStruct_unsharpMask getBestParameter_red();

	// put channels together
	void putChannlesTogehter();
	// norm the gray images according to the sharp image
	void normTheGrayImagesAccordingToSharpIma();

	cv::Mat getFilteredResults_normedLikeSharpIma();
	cv::Mat getFilteredResults_normedZeroAndMaxUchar();

private:

	cv::Mat mSharpImage_BGR;
	cv::Mat mSharpImage_blue;
	cv::Mat mSharpImage_green;
	cv::Mat mSharpImage_red;

	cv::Mat mBlueredImage_BGR;
	cv::Mat mBlueredImage_blue;
	cv::Mat mBlueredImage_green;
	cv::Mat mBlueredImage_red;

	UnshaprMasking_singleCore_gray mUM_blue{};
	UnshaprMasking_singleCore_gray mUM_green{};
	UnshaprMasking_singleCore_gray mUM_red{};

	parameterUnsharpMasking mParaUM_Global_blue{};
	parameterUnsharpMasking mParaUM_Global_green{};
	parameterUnsharpMasking mParaUM_Global_red{};

	bestParameterStruct_unsharpMask mBestParaUM_blue{};
	bestParameterStruct_unsharpMask mBestParaUM_green{};
	bestParameterStruct_unsharpMask mBestParaUM_red{};

	int mMin_blue;
	int mMax_blue;
	int mMin_green;
	int mMax_green;
	int mMin_red;
	int mMax_red;

	cv::Mat mFilterResultIma_normedSharp_blue;
	cv::Mat mFilterResultIma_normedSharp_green;
	cv::Mat mFilterResultIma_normedSharp_red;

	cv::Mat mFilterResultIma_BGR_normedLikeSharpIma;

};


class unsharpMasking_BGR_parallel
{
public:
	unsharpMasking_BGR_parallel();
	~unsharpMasking_BGR_parallel();

	void improveImaQual_UnsharpMasking_superFct_BGR_parallel(const cv::Mat sharpBGR_Image, const cv::Mat blueredBGR_Image);
	void findingBestParaUM_BGR_parallel();

	void setParameterUM_blue(parameterUnsharpMasking paraUM_blue);
	void setParameterUM_green(parameterUnsharpMasking paraUM_green);
	void setParameterUM_red(parameterUnsharpMasking paraUM_red);

	// initialize parameter for difference cores
	void initializePrameterDifCores_blue();
	void initializePrameterDifCores_green();
	void initializePrameterDifCores_red();

	// split the image in BGR
	void splitImagesInBGR();
	// calc min max sharp image
	void calcMinMax();
	// put channels together
	void putChannlesTogehter();
	// norm the gray images according to the sharp image
	void normTheGrayImagesAccordingToSharpIma();

	cv::Mat getFilteredResults_normedLikeSharpIma();
	cv::Mat getFilteredResults_normedZeroAndMaxUchar();

	bestParameterStruct_unsharpMask getBestParameter_blue();
	bestParameterStruct_unsharpMask getBestParameter_green();
	bestParameterStruct_unsharpMask getBestParameter_red();

	parameterUnsharpMasking getInitialPara_blue();
	parameterUnsharpMasking getInitialPara_green();
	parameterUnsharpMasking getInitialPara_red();

	// find best parameter
	void findBestParameterAllCores_blue();
	void findBestParameterAllCores_green();
	void findBestParameterAllCores_red();

private:

	cv::Mat mSharpImage_BGR;
	cv::Mat mSharpImage_blue;
	cv::Mat mSharpImage_green;
	cv::Mat mSharpImage_red;

	cv::Mat mBlueredImage_BGR;
	cv::Mat mBlueredImage_blue;
	cv::Mat mBlueredImage_green;
	cv::Mat mBlueredImage_red;

	parameterUnsharpMasking mParaUM_Global_blue;
	parameterUnsharpMasking mParaUM_Global_green;
	parameterUnsharpMasking mParaUM_Global_red;

	UnshaprMasking_singleCore_gray mUM_singleCore_blue_1{};
	UnshaprMasking_singleCore_gray mUM_singleCore_blue_2{};
	UnshaprMasking_singleCore_gray mUM_singleCore_blue_3{};
	UnshaprMasking_singleCore_gray mUM_singleCore_blue_4{};
	UnshaprMasking_singleCore_gray mUM_singleCore_blue_5{};
	UnshaprMasking_singleCore_gray mUM_singleCore_blue_6{};
	UnshaprMasking_singleCore_gray mUM_singleCore_blue_7{};
	UnshaprMasking_singleCore_gray mUM_singleCore_blue_8{};

	UnshaprMasking_singleCore_gray mUM_singleCore_green_1{};
	UnshaprMasking_singleCore_gray mUM_singleCore_green_2{};
	UnshaprMasking_singleCore_gray mUM_singleCore_green_3{};
	UnshaprMasking_singleCore_gray mUM_singleCore_green_4{};
	UnshaprMasking_singleCore_gray mUM_singleCore_green_5{};
	UnshaprMasking_singleCore_gray mUM_singleCore_green_6{};
	UnshaprMasking_singleCore_gray mUM_singleCore_green_7{};
	UnshaprMasking_singleCore_gray mUM_singleCore_green_8{};

	UnshaprMasking_singleCore_gray mUM_singleCore_red_1{};
	UnshaprMasking_singleCore_gray mUM_singleCore_red_2{};
	UnshaprMasking_singleCore_gray mUM_singleCore_red_3{};
	UnshaprMasking_singleCore_gray mUM_singleCore_red_4{};
	UnshaprMasking_singleCore_gray mUM_singleCore_red_5{};
	UnshaprMasking_singleCore_gray mUM_singleCore_red_6{};
	UnshaprMasking_singleCore_gray mUM_singleCore_red_7{};
	UnshaprMasking_singleCore_gray mUM_singleCore_red_8{};

	parameterUnsharpMasking mParaUM_blue_1{};
	parameterUnsharpMasking mParaUM_blue_2{};
	parameterUnsharpMasking mParaUM_blue_3{};
	parameterUnsharpMasking mParaUM_blue_4{};
	parameterUnsharpMasking mParaUM_blue_5{};
	parameterUnsharpMasking mParaUM_blue_6{};
	parameterUnsharpMasking mParaUM_blue_7{};
	parameterUnsharpMasking mParaUM_blue_8{};

	parameterUnsharpMasking mParaUM_green_1{};
	parameterUnsharpMasking mParaUM_green_2{};
	parameterUnsharpMasking mParaUM_green_3{};
	parameterUnsharpMasking mParaUM_green_4{};
	parameterUnsharpMasking mParaUM_green_5{};
	parameterUnsharpMasking mParaUM_green_6{};
	parameterUnsharpMasking mParaUM_green_7{};
	parameterUnsharpMasking mParaUM_green_8{};

	parameterUnsharpMasking mParaUM_red_1{};
	parameterUnsharpMasking mParaUM_red_2{};
	parameterUnsharpMasking mParaUM_red_3{};
	parameterUnsharpMasking mParaUM_red_4{};
	parameterUnsharpMasking mParaUM_red_5{};
	parameterUnsharpMasking mParaUM_red_6{};
	parameterUnsharpMasking mParaUM_red_7{};
	parameterUnsharpMasking mParaUM_red_8{};

	std::vector<bestParameterStruct_unsharpMask> mBestParaUM_vec_blue{};
	std::vector<bestParameterStruct_unsharpMask> mBestParaUM_vec_green{};
	std::vector<bestParameterStruct_unsharpMask> mBestParaUM_vec_red{};

	bestParameterStruct_unsharpMask mBestParameterGlobal_blue;
	bestParameterStruct_unsharpMask mBestParameterGlobal_green;
	bestParameterStruct_unsharpMask mBestParameterGlobal_red;

	int mMin_blue;
	int mMax_blue;
	int mMin_green;
	int mMax_green;
	int mMin_red;
	int mMax_red;

	cv::Mat mFilterResultIma_normedSharp_blue;
	cv::Mat mFilterResultIma_normedSharp_green;
	cv::Mat mFilterResultIma_normedSharp_red;

	std::vector<real> mImprovements_vec_blue;
	std::vector<real> mImprovements_vec_green;
	std::vector<real> mImprovements_vec_red;

	std::vector<real> mSharpness_vec_blue;
	std::vector<real> mSharpness_vec_green;
	std::vector<real> mSharpness_vec_red;


	cv::Mat mFilterResultIma_BGR_normedLikeSharpIma;
};


