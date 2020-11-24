#include "Point-Spread Function.h"

#include "opencv2/core/core.hpp"

#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/highgui/highgui.hpp"

PSF::PSF() {}
PSF::~PSF() {}


cv::Mat PSF::calcPSF_FFT_P_Fct(cv::Mat& OPD)
{
	// for more infomrations
	// --> https://docs.opencv.org/3.4/d8/d01/tutorial_discrete_fourier_transform.html

	unsigned int factorPadding = 5;
	//expand PSF to optimum size
	cv::Mat padded;
	//expand input image to optimal size
	int m = cv::getOptimalDFTSize(OPD.rows);
	int n = cv::getOptimalDFTSize(OPD.cols);

	int m_padding = m * factorPadding;
	int n_padding = n * factorPadding;
	// on the border add zero values
	cv::copyMakeBorder(OPD.clone(), padded, 0, m_padding - OPD.rows, 0, n_padding - OPD.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));

	cv::Mat planes[] = { cv::Mat_<double>(padded), cv::Mat::zeros(padded.size(), CV_64F) };
	cv::Mat complexI;
	cv::merge(planes, 2, complexI);

	cv::dft(complexI, complexI, cv::DFT_COMPLEX_OUTPUT);


	cv::split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
	cv::magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude
	cv::Mat magI = planes[0];


	//magI += cv::Scalar::all(1);                    // switch to logarithmic scale
	//log(magI, magI);

	// crop the spectrum, if it has an odd number of rows or columns
	magI = magI(cv::Rect(0, 0, magI.cols & -2, magI.rows & -2));

	// rearrange the quadrants of Fourier image  so that the origin is at the image center
	int cx = magI.cols / 2;
	int cy = magI.rows / 2;
	cv::Mat q0(magI, cv::Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
	cv::Mat q1(magI, cv::Rect(cx, 0, cx, cy));  // Top-Right
	cv::Mat q2(magI, cv::Rect(0, cy, cx, cy));  // Bottom-Left
	cv::Mat q3(magI, cv::Rect(cx, cy, cx, cy)); // Bottom-Right
	cv::Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);
	q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
	q2.copyTo(q1);
	tmp.copyTo(q2);

	cv::Mat originalSize;

	// cut ínformations from the middle

	unsigned int middlePX = m_padding / 2;
	unsigned middlePY = n_padding / 2;
	cv::Mat PSF_relevant(magI, cv::Rect(middlePY - n/2,middlePX - m/2, n, m));


	//cv::resize(magI, magI, cv::Size(m,n), 0, 0, cv::INTER_AREA);


	return PSF_relevant;
}

cv::Mat PSF::MagnitudeOfTwochannelsMat(cv::Mat& Matrix)
{
	cv::Mat chan[2];
	cv::split(Matrix, chan);
	cv::Mat mag;
	cv::magnitude(chan[0], chan[1], mag);
	return mag;
}


cv::Mat  PSF::ifftshiftOneChan(cv::Mat& input)
{

	// see: https://codereview.stackexchange.com/questions/84872/fftshift-implementation-for-opencv

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