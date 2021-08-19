#pragma once
#include "..\LowLevelTracing\ImportantStructures.h"

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

// parameter wiener filter 
#include "..\ImageProcessing\structsWD_superFcts.h"
// parameter unsharp masking
#include "..\ImageProcessing\structsUnsharpMasking_superFcts.h"
// detail enhancement
#include "..\ImageProcessing\structDetailEnhancement_superFct.h"
// remove chromativ aberrations
#include "..\ImageProcessing\structsRemoveChromAber.h"

// image Processing
enum class imageProcessing { wienerFilter, wienerFilter24, unsharpMasking, unsharpMasking24, unsharpMasking_gray, unsharpMasking24_gray, detailEnhance, detailEnhance24, removeChromaticAber,
							unshMas_DetailEnh_WienerDec_24};

class ImaProcSuperFct
{
public:
	ImaProcSuperFct();
	~ImaProcSuperFct();

	// image processing super function
	void ImageProcessingSuperFunction(cv::Mat& inputIma, cv::Mat& blueredIma, imageProcessing imaProc);
	

	// reload parameter according to best parameter
	void reloadParameterAccordingToBestParameter_WD(real variancePercent);

	// *** wiener filter ***
	void setParameterWD_blue(parameterImaImprove_WD paraWD_blue);
	void setParameterWD_green(parameterImaImprove_WD paraWD_green);
	void setParameterWD_red(parameterImaImprove_WD paraWD_red);
	parameterImaImprove_WD getParameterWD_blue();
	parameterImaImprove_WD getParameterWD_green();
	parameterImaImprove_WD getParameterWD_red();
	saveBestParameterWD getBestParaWD_blue();
	saveBestParameterWD getBestParaWD_green();
	saveBestParameterWD getBestParaWD_red();
	void reinitializeBestParaWD(real percent, real stepsSNR, real stepsSigma);
	// *** ***

	// *** unsharp masking ***
	void setParameterUnsMas_blue(parameterUnsharpMasking paraUnsMas_blue);
	void setParameterUnsMas_green(parameterUnsharpMasking paraUnsMas_green);
	void setParameterUnsMas_red(parameterUnsharpMasking paraUnsMas_red);
	void setParameterUnsMas_gray(parameterUnsharpMasking paraUnsMas_gray);
	parameterUnsharpMasking getParameterUnsMas_blue();
	parameterUnsharpMasking getParameterUnsMas_green();
	parameterUnsharpMasking getParameterUnsMas_red();
	parameterUnsharpMasking getParameterUnsMas_gray();
	bestParameterStruct_unsharpMask getBestParaUnsMas_blue();
	bestParameterStruct_unsharpMask getBestParaUnsMas_green();
	bestParameterStruct_unsharpMask getBestParaUnsMas_red();
	bestParameterStruct_unsharpMask getBestParaUnsMas_gray();
	void reinitializeBestParaUnsMas(real percent, real stepsSigma, real stepsThreshold, real stepsAmount);
	void reinitializeBestParaUnsMas_gray(real percent, real stepsSigma, real stepsThreshold, real stepsAmount);
	// *** ***

	// *** detail enhancement ***
	void setParameterDetEnh(parameterDetailEnhancement paraDetEnh);
	parameterDetailEnhancement getParameterDetEnh();
	bestParameterStruct_detailEnhance getBestParaDetEnh();
	void reinitializeBestParaDetEng(real percent, real stepsSigma_r, real stepsSigma_s);
	// *** ***

	// *** remove chromatic aberrations ***
	void setParameterRemoveChromAber(initialPararemChromAber parameterRemovChromAber);
	initialPararemChromAber getParameterRemoveChromAber();
	bestParaRemChromAber getBestParaRemoveChromAber();
	void reinitalizeBestParaRemoChromAber(real percent, real stepsThreshold);
	// *** ***

	cv::Mat getInputIma();
	cv::Mat getBlueredIma();
	cv::Mat getFilteredIma();
	std::vector<cv::Mat> getAllFilteredImages_UM_DE_WD();

private:
	cv::Mat mInputIma{};
	cv::Mat mBlueredIma{};
	cv::Mat mFilteredIma{};
	imageProcessing mImaProc;

	// *** wiener filter ***
	parameterImaImprove_WD mParaWD_blue{};
	parameterImaImprove_WD mParaWD_green{};
	parameterImaImprove_WD mParaWD_red{};
	saveBestParameterWD mBestParaWD_blue{};
	saveBestParameterWD mBestParaWD_green{};
	saveBestParameterWD mBestParaWD_red{};
	// *** ***

	// *** unsharp masking *** //
	parameterUnsharpMasking mParaUnsMas_blue{};
	parameterUnsharpMasking mParaUnsMas_green{};
	parameterUnsharpMasking mParaUnsMas_red{};
	bestParameterStruct_unsharpMask mBestParaUnsMas_blue{};
	bestParameterStruct_unsharpMask mBestParaUnsMas_green{};
	bestParameterStruct_unsharpMask mBestParaUnsMas_red{};

	parameterUnsharpMasking mParaUnsMas_gray{};
	bestParameterStruct_unsharpMask mBestParaUnsMas_gray{};
	// *** ***

	// *** detail enhancement *** //
	parameterDetailEnhancement mParaDetEnh{};
	bestParameterStruct_detailEnhance mBestParaDetEnh{};
	// *** ***

	// *** remove chromatic aberrations ** //
	initialPararemChromAber mParaRemoChroAber{};
	bestParaRemChromAber mBestParaRemoChroAber{};
	// *** ***

	// all filtered images
	std::vector<cv::Mat> mAllFilteredImages_UM_DE_WD{};
};




namespace ImageProcessing
{
	// Brightness and contrast adjustments
	// see https://docs.opencv.org/3.4/d3/dc1/tutorial_basic_linear_transform.html
	cv::Mat brighContrastAdjust(cv::Mat const& image, real const& alpha, int const& beta);

	// Correct an underexposed image -> Gamma correction
	// https://docs.opencv.org/3.4/d3/dc1/tutorial_basic_linear_transform.html
	// more informations: https://learnopengl.com/Advanced-Lighting/Gamma-Correction
	cv::Mat gammaCorrection(cv::Mat const& image, real const& gamma);

	// bilateralFilter
	//can reduce unwanted noise very well while keeping edges fairly sharp.However, it is very slow compared to most filters.
	// https://www.tutorialspoint.com/opencv/opencv_bilateral_filter.htm
	cv::Mat bilateralFilter(cv::Mat const& image, int const& pixelNeighborhood, int const& sigmaColor, int const& sigmaSpace, int const& borderType);

	// boxFilter
	// Blurs an image using the box filter.
	// https://www.tutorialspoint.com/opencv/opencv_box_filter.htm
	cv::Mat boxFilter(cv::Mat const& image, int const& depthOutputImage, cv::Size const& ksize, cv::Point const& point, bool const& normalize, int const& borderType);

	// erosion
	cv::Mat erosion(cv::Mat const& image,/*erosion type*/ int erosionType,/*kernel size*/ cv::Size  const& ksize,/*anchor point*/ cv::Point const& point);

	// dilation
	cv::Mat dilation(cv::Mat const& image,/*erosion type*/ int erosionType,/*kernel size*/ cv::Size  const& ksize,/*anchor point*/ cv::Point const& point);

	// correct distortion of an image
	// see: http://aishack.in/tutorials/calibrating-undistorting-opencv-oh-yeah/
	cv::Mat correctDistortion(cv::Mat const& image, cv::Mat const& calibrationImage, int const& numCornersHor, int const& numCornersVer); 

	// Detail Enhancing Filter
	// see: https://docs.opencv.org/3.4/df/dac/group__photo__render.html
	// sigma_s	Range between 0 to 200.
	// sigma_r	Range between 0 to 1
	void detailEnhancin(const cv::Mat& image, cv::Mat& detailEnhanceImage, float sigma_s, float sigma_r);

	// laplacian
	// see: https://docs.opencv.org/3.4/d5/db5/tutorial_laplace_operator.html
	cv::Mat laplacian(cv::Mat const& image, int const& ddepth, int const& kernel_size, int const& scale, int const& delta);

	// canny
	// see: https://docs.opencv.org/2.4/doc/tutorials/imgproc/imgtrans/canny_detector/canny_detector.html
	cv::Mat canny(cv::Mat const& image, real const& lowThreshold, real const& heightThreshold, int const& apertureSize, bool const& L2gradient);

	// sobel
	// see: https://docs.opencv.org/2.4/doc/tutorials/imgproc/imgtrans/sobel_derivatives/sobel_derivatives.html
	cv::Mat sobel(cv::Mat image, int const& ddepth, int const& dx, int const& dy, int const& ksize, double const& scale, double const& delta, int const& borderType);

	// unsharp mask
	// see: https://docs.opencv.org/master/d1/d10/classcv_1_1MatExpr.html#details
	cv::Mat	unsharpMask(const cv::Mat& image, cv::Size kernelSize, const double sigmaX, const double sigmaY, int borderType, const double threshold, const double amount);
	
	// bilateralFilter 
	// see: https://docs.opencv.org/3.0-beta/modules/imgproc/doc/filtering.html
	cv::Mat bilateralFilter(cv::Mat const& image, int const& d, double const& sigmarColor, double const& sigmarSpace, int const& boarderType);
	
	// median blur
	// see: https://docs.opencv.org/3.3.1/d4/d86/group__imgproc__filter.html#ga564869aa33e58769b4469101aac458f9
	// see: https://docs.opencv.org/3.1.0/d4/d13/tutorial_py_filtering.html
	// The function smoothes an image using the median filter with the ksize�ksize aperture.
	// Each channel of a multi-channel image is processed independently. In-place operation is supported
	cv::Mat MedianBlurFilter(cv::Mat const& image,  int const& ksize);


};


