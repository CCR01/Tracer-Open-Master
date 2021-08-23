#pragma once

// important structs
#include "..\LowLevelTracing\ImportantStructures.h"

// image simulation
#include "..\Image\ImageSimulation.h"


// open cv
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/calib3d/calib3d.hpp>
//#include <opencv2/imgcodecs.hpp>
#include <opencv2/photo.hpp>




class WienerDeconvolution
{
public:
	WienerDeconvolution();
	~WienerDeconvolution();

	// https://stackoverrun.com/fr/q/11209556 -> from Andrey Smorodov
	void wienerFilter_AndreySmorodov_GrayImage(cv::Mat& src, cv::Mat& dst, cv::Mat& _h, double k);
	void ForwardFFT_AS(cv::Mat& Src, cv::Mat* FImg);
	void InverseFFT_AS(cv::Mat* FImg, cv::Mat& Dst);
	void Recomb_AS(cv::Mat& src, cv::Mat& dst);
	void convolveDFT_AS(cv::Mat& A, cv::Mat& B, cv::Mat& C);

	// wiener filter by Andrey Smorodov for BGR images
	void wienerFilter_AndreySmorodov_BGR_Image(cv::Mat& bluredImage_BGT, cv::Mat& PSF_blue, cv::Mat& PSF_green, cv::Mat& PSF_red, double k, cv::Size initialSize);

	// https://docs.opencv.org/master/de/d3c/tutorial_out_of_focus_deblur_filter.html -> from open CV
	void calcWnrFilter_CV(const cv::Mat& input_h_PSF, cv::Mat& output_G, double nsr);
	void filter2DFreq_CV(const cv::Mat& inputImg, cv::Mat& outputImg, const cv::Mat& H);
	void calcPSF_CV_32(cv::Mat& outputImg, cv::Size filterSize, int R);
	void calcPSF_CV_64(cv::Mat& outputImg, cv::Size filterSize, int R);
	void fftshift_CV(const cv::Mat& inputImg, cv::Mat& outputImg);

	// Wiener Filter -> CR -> based on OpenCV -> Gray
	void calcWienerFilter_CR_Gray(const cv::Mat& bluredImage, cv::Mat& sharpImage_out, const cv::Mat& psf, real SNR);
	void calcWienerFilter_CR_Gray_outputNotNormed(const cv::Mat& bluredImage, cv::Mat& sharpImage_out, const cv::Mat& psf, real SNR);
	void calcHw(const cv::Mat& input_h_PSF, cv::Mat& output_H, double nsr);
	void filter2DFreq_CR(const cv::Mat& inputImg, cv::Mat& outputImg, const cv::Mat& Hw);

	// Wiener Filter -> CR -> based on OpenCV -> BGR
	void calcWienerFilter_CR_BGR(const cv::Mat& bluredImage, const cv::Mat& psf_blue, cv::Mat& psf_green, cv::Mat& psf_red, real SNR, /*size initial object*/  cv::Size initialSize);
	void calcWienerFilter_blue();
	void calcWienerFilter_green();
	void calcWienerFilter_red();
	void splitBGRIma();
	void putImagesTogetherAndScale();

	void wienerDeconvolution_superFct_doNotUseThatFunction(std::vector<cv::Mat> /*PSF vec blue*/ psf_vec_blue, std::vector<cv::Mat> /*PSF vec green*/ psf_vec_green, std::vector<cv::Mat> /*PSF vec red*/ psf_vec_red,
		std::vector<cv::Mat> /*image parts blue*/ imageParts_blue, std::vector<cv::Mat> /*image parts green*/ imageParts_green, std::vector<cv::Mat> /*image parts red*/ imageParts_red,
		loadParaImaSim /*parameter ima sim*/ defaulPara,  /*SNR*/ real SNR, /*size initial object*/ cv::Size sizeInitialObj, /*size obj for convolution*/ cv::Size sizeObjForConv);
	void calcWienerFileterInSuperFct_doNotUseThatFunction();
	void putAllImageGridsTogether_doNotUseThatFunction();



	void wienerDeconvolution_superFct(std::vector<cv::Mat> /*PSF vec blue*/ psf_vec_blue, std::vector<cv::Mat> /*PSF vec green*/ psf_vec_green, std::vector<cv::Mat> /*PSF vec red*/ psf_vec_red,
		std::vector<cv::Mat> /*image parts blue*/ imageParts_blue, std::vector<cv::Mat> /*image parts green*/ imageParts_green, std::vector<cv::Mat> /*image parts red*/ imageParts_red,
		loadParaImaSim /*parameter ima sim*/ defaulPara,  /*SNR*/ real SNR, /*size initial object*/ cv::Size sizeInitialObj, /*size obj for convolution*/ cv::Size sizeObjForConv, cv::Size inceaseSize);
	void calcWienerFileterInSuperFct();

	void wienderDeconv_superFkt_grayIma(std::vector<cv::Mat> /*PSF vec*/ psf_vec, std::vector<cv::Mat> /*image parts blue*/ imageParts, loadParaImaSim /*parameter ima sim*/ defaulPara,  /*SNR*/ real SNR, cv::Size sizeObjForConv);

	void WienerDeconvolution::saveAllSharpImageParts_blue(std::string /*locaion*/ location);
	void WienerDeconvolution::saveAllSharpImageParts_green(std::string /*locaion*/ location);
	void WienerDeconvolution::saveAllSharpImageParts_red(std::string /*locaion*/ location);


	// get final sharp image
	cv::Mat getFinalSharpImage_initialSize();

	// get gray image
	cv::Mat getGrayImage();





private:


	cv::Mat mImageSharp_blue{};
	cv::Mat mImageSharp_green{};
	cv::Mat mImageSharp_red{};

	cv::Mat mPSF_blue{};
	cv::Mat mPSF_green{};
	cv::Mat mPSF_red{};

	cv::Mat mBluredIma_blue{};
	cv::Mat mBluredIma_green{};
	cv::Mat mBluredIma_red{};

	cv::Mat mBluredIma_BGR{};

	std::vector<cv::Mat> mPsf_vec_blue{};
	std::vector<cv::Mat> mPsf_vec_green{};
	std::vector<cv::Mat> mPsf_vec_red{};
	std::vector<cv::Mat> mImageParts_blue{};
	std::vector<cv::Mat> mImageParts_green{};
	std::vector<cv::Mat> mImageParts_red{};

	std::vector<cv::Mat> mImagePartsSharp_blue{};
	std::vector<cv::Mat> mImagePartsSharp_green{};
	std::vector<cv::Mat> mImagePartsSharp_red{};

	loadParaImaSim mParameterImageSimulation{};
	real mSNR{};

	std::vector<cv::Mat> mShartImageParts_blue{};
	std::vector<cv::Mat> mShartImageParts_green{};
	std::vector<cv::Mat> mShartImageParts_red{};
	std::vector<cv::Mat> mShartImageParts_gray{};


	cv::Mat mWienerFilter_blue{};
	cv::Mat mWienerFilter_green{};
	cv::Mat mWienerFilter_red{};


	cv::Mat mImageSharp_gray{};

	

	cv::Mat mImageSharp_blue_initialSize{};
	cv::Mat mImageSharp_green_initialSize{};
	cv::Mat mImageSharp_red_initialSize{};

	cv::Size mSizeResizedObjForConv{};
	cv::Size mSizeInitialObj{};
	cv::Size mInceaseSize{};

	cv::Mat mSharpImageFinal_BGR_64{};
	cv::Mat mSharpImageFinal_BGR_64_initialSize{};



};

