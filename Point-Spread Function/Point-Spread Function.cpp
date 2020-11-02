#include "Point-Spread Function.h"

#include "opencv2/core/core.hpp"

//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/highgui/highgui.hpp"

PSF::PSF() {}
PSF::~PSF() {}


cv::Mat PSF::calcPSF_FFT_P_Fct(cv::Mat& OPD)
{
	return MagnitudeOfTwochannelsMat(calcFFT(OPD));
}

cv::Mat PSF::MagnitudeOfTwochannelsMat(cv::Mat& Matrix)
{
	cv::Mat chan[2];
	cv::split(Matrix, chan);
	cv::Mat mag;
	cv::magnitude(chan[0], chan[1], mag);
	return mag;
}

cv::Mat PSF::calcFFT(cv::Mat& PSF)
{
	// for more infomrations
	// --> https://docs.opencv.org/3.4/d8/d01/tutorial_discrete_fourier_transform.html

	cv::Mat PSFfloat;
	PSF.convertTo(PSFfloat, CV_32F);
	PSFfloat = ifftshiftOneChan(PSFfloat);
	//expand PSF to optimum size
	cv::Mat padded;
	//expand input image to optimal size
	int m = cv::getOptimalDFTSize(PSFfloat.rows);
	int n = cv::getOptimalDFTSize(PSFfloat.cols);
	// on the border add zero values
	cv::copyMakeBorder(PSFfloat, padded, 0, m - PSFfloat.rows, 0, n - PSFfloat.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));
	
	//take DFT
	cv::Mat OTFcomplex[2] = { padded,cv::Mat::zeros(padded.size(),CV_32F) };
	cv::Mat DFTready;
	cv::Mat dftOfOriginal;
	cv::merge(OTFcomplex, 2, DFTready);
	cv::dft(DFTready, dftOfOriginal, cv::DFT_COMPLEX_OUTPUT);
	dftOfOriginal = ifftshiftOneChan(dftOfOriginal);
	return dftOfOriginal;
}

cv::Mat  PSF::ifftshiftOneChan(cv::Mat& input)
{
	int centerX = input.cols / 2;
	int centerY = input.rows / 2;


	cv::Mat q1(input, cv::Rect(0, 0, centerX, centerY));
	cv::Mat q2(input, cv::Rect(centerX, 0, centerX, centerY));
	cv::Mat q3(input, cv::Rect(0, centerY, centerX, centerY));
	cv::Mat q4(input, cv::Rect(centerX, centerY, centerX, centerY));

	cv::Mat SwapMap;
	q1.copyTo(SwapMap);
	q4.copyTo(q1);
	SwapMap.copyTo(q4);

	q2.copyTo(SwapMap);
	q3.copyTo(q2);
	SwapMap.copyTo(q3);

	return input;
}