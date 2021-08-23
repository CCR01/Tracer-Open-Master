#include "WienerDeconvolution.h"

// images
#include "..\Image\Images.h"

// often use
#include "..\oftenUseNamespace\oftenUseNamespace.h"



WienerDeconvolution::WienerDeconvolution() { };
WienerDeconvolution::~WienerDeconvolution() {};

void WienerDeconvolution::wienerFilter_AndreySmorodov_GrayImage(cv::Mat& src, cv::Mat& dst, cv::Mat& _h, double k)
{

	// implementation see: https://stackoverrun.com/fr/q/11209556

	//---------------------------------------------------
	// Small epsilon to avoid division by zero
	//---------------------------------------------------
	const double eps = 1E-8;
	//---------------------------------------------------
	int ImgW = src.size().width;
	int ImgH = src.size().height;
	//--------------------------------------------------
	cv::Mat Yf[2];
	ForwardFFT_AS(src, Yf);
	//--------------------------------------------------
	cv::Mat h = cv::Mat::zeros(ImgH, ImgW, CV_64FC1);

	int padx = h.cols - _h.cols;
	int pady = h.rows - _h.rows;

	cv::copyMakeBorder(_h, h, pady / 2, pady - pady / 2, padx / 2, padx - padx / 2, cv::BORDER_CONSTANT, cv::Scalar::all(0));

	//// debug
	//Images::showImage_inputReal_normTheImage("_h", _h);
	//Images::showImage_inputReal_normTheImage("h", h);

	cv::Mat Hf[2];
	ForwardFFT_AS(h, Hf);


	//--------------------------------------------------
	cv::Mat Fu[2];
	Fu[0] = cv::Mat::zeros(ImgH, ImgW, CV_64FC1);
	Fu[1] = cv::Mat::zeros(ImgH, ImgW, CV_64FC1);

	std::complex<double> a;
	std::complex<double> b;
	std::complex<double> c;

	double Hf_Re;
	double Hf_Im;
	double Phf;
	double hfz;
	double hz;
	double A;

	for (int i = 0; i < h.rows; i++)
	{
		for (int j = 0; j < h.cols; j++)
		{
			Hf_Re = Hf[0].at<double>(i, j);
			Hf_Im = Hf[1].at<double>(i, j);
			Phf = Hf_Re * Hf_Re + Hf_Im * Hf_Im;
			hfz = (Phf < eps) * eps;
			hz = (h.at<double>(i, j) > 0);
			A = Phf / (Phf + hz + k);
			a = std::complex<double>(Yf[0].at<double>(i, j), Yf[1].at<double>(i, j));
			b = std::complex<double>(Hf_Re + hfz, Hf_Im + hfz);
			c = a / b; // Deconvolution :) other work to avoid division by zero
			Fu[0].at<double>(i, j) = (c.real() * A);
			Fu[1].at<double>(i, j) = (c.imag() * A);
		}
	}
	InverseFFT_AS(Fu, dst);
	Recomb_AS(dst, dst);


}

void  WienerDeconvolution::convolveDFT_AS(cv::Mat& A, cv::Mat& B, cv::Mat& C)
{
	// reallocate the output array if needed
	C.create(abs(A.rows - B.rows) + 1, abs(A.cols - B.cols) + 1, A.type());
	cv::Size dftSize;
	// compute the size of DFT transform
	dftSize.width = cv::getOptimalDFTSize(A.cols + B.cols - 1);
	dftSize.height = cv::getOptimalDFTSize(A.rows + B.rows - 1);
	// allocate temporary buffers and initialize them with 0's
	cv::Mat tempA(dftSize, A.type(), cv::Scalar::all(0));
	cv::Mat tempB(dftSize, B.type(), cv::Scalar::all(0));
	// copy A and B to the top-left corners of tempA and tempB, respectively
	cv::Mat roiA(tempA, cv::Rect(0, 0, A.cols, A.rows));
	A.copyTo(roiA);
	cv::Mat roiB(tempB, cv::Rect(0, 0, B.cols, B.rows));
	B.copyTo(roiB);
	// now transform the padded A & B in-place;
	// use "nonzeroRows" hint for faster processing
	cv::dft(tempA, tempA, 0, A.rows);

	cv::dft(tempB, tempB, 0, A.rows);

	// multiply the spectrums;
	// the function handles packed spectrum representations well
	mulSpectrums(tempA, tempB, tempA, 0);
	// transform the product back from the frequency domain.
	// Even though all the result rows will be non-zero,
	// you need only the first C.rows of them, and thus you
	// pass nonzeroRows == C.rows

	cv::dft(tempA, tempA, cv::DFT_INVERSE + cv::DFT_SCALE);
	// now copy the result back to C.
	C = tempA(cv::Rect((dftSize.width - A.cols) / 2, (dftSize.height - A.rows) / 2, A.cols, A.rows)).clone();
	// all the temporary buffers will be deallocated automatically
}

// wiener filter by Andrey Smorodov for BGR images
void WienerDeconvolution::wienerFilter_AndreySmorodov_BGR_Image(cv::Mat& bluredImage_BGT, cv::Mat& PSF_blue, cv::Mat& PSF_green, cv::Mat& PSF_red, double k, cv::Size initialSize)
{
	bluredImage_BGT.convertTo(bluredImage_BGT, CV_64FC3, 1.0 / 255.0);

	mBluredIma_BGR = bluredImage_BGT;
	mPSF_blue = PSF_blue;
	mPSF_green = PSF_green;
	mPSF_red = PSF_red;
	mSNR = k;
	mSizeInitialObj = initialSize;

	// split BRG image in channels
	splitBGRIma();


	wienerFilter_AndreySmorodov_GrayImage(mBluredIma_blue, mImageSharp_blue, mPSF_blue, mSNR);
	//debug 
	//Images::showImage_inputReal_normTheImage("blued ima blue", mBluredIma_blue);
	//Images::showImage_inputReal_normTheImage("sharp ima blue", mImageSharp_blue);
	//cv::imshow("Kernel", mPSF_blue * 255);

	wienerFilter_AndreySmorodov_GrayImage(mBluredIma_green, mImageSharp_green, mPSF_green, mSNR);
	//debug 
	//Images::showImage_inputReal_normTheImage("blued ima green", mBluredIma_green);
	//Images::showImage_inputReal_normTheImage("sharp ima green", mImageSharp_green);

	wienerFilter_AndreySmorodov_GrayImage(mBluredIma_red, mImageSharp_red, mPSF_red, mSNR);
	//debug 
	//Images::showImage_inputReal_normTheImage("blued ima red", mBluredIma_red);
	//Images::showImage_inputReal_normTheImage("sharp ima red", mImageSharp_red);


	putImagesTogetherAndScale();

}

void WienerDeconvolution::ForwardFFT_AS(cv::Mat& Src, cv::Mat* FImg)
{
	int M = cv::getOptimalDFTSize(Src.rows);
	int N = cv::getOptimalDFTSize(Src.cols);
	cv::Mat padded;
	cv::copyMakeBorder(Src, padded, 0, M - Src.rows, 0, N - Src.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));
	cv::Mat planes[] = { cv::Mat_<double>(padded), cv::Mat::zeros(padded.size(), CV_64FC1) };
	cv::Mat complexImg;
	cv::merge(planes, 2, complexImg);
	cv::dft(complexImg, complexImg);
	cv::split(complexImg, planes);
	// crop result
	planes[0] = planes[0](cv::Rect(0, 0, Src.cols, Src.rows));
	planes[1] = planes[1](cv::Rect(0, 0, Src.cols, Src.rows));
	FImg[0] = planes[0].clone();
	FImg[1] = planes[1].clone();
}

void WienerDeconvolution::InverseFFT_AS(cv::Mat* FImg, cv::Mat& Dst)
{
	cv::Mat complexImg;
	cv::merge(FImg, 2, complexImg);
	cv::dft(complexImg, complexImg, cv::DFT_INVERSE + cv::DFT_SCALE);
	cv::split(complexImg, FImg);
	Dst = FImg[0];
}

void WienerDeconvolution::Recomb_AS(cv::Mat& src, cv::Mat& dst)
{

	int cx = src.cols >> 1;
	int cy = src.rows >> 1;
	cv::Mat tmp;
	tmp.create(src.size(), src.type());
	src(cv::Rect(0, 0, cx, cy)).copyTo(tmp(cv::Rect(cx, cy, cx, cy)));
	src(cv::Rect(cx, cy, cx, cy)).copyTo(tmp(cv::Rect(0, 0, cx, cy)));
	src(cv::Rect(cx, 0, cx, cy)).copyTo(tmp(cv::Rect(0, cy, cx, cy)));
	src(cv::Rect(0, cy, cx, cy)).copyTo(tmp(cv::Rect(cx, 0, cx, cy)));
	dst = tmp;

}



void WienerDeconvolution::calcPSF_CV_32(cv::Mat& outputImg, cv::Size filterSize, int R)
{
	cv::Mat h(filterSize, CV_32F, cv::Scalar(0));
	cv::Point point(filterSize.width / 2, filterSize.height / 2);
	cv::circle(h, point, R, 255, -1, 8);
	cv::Scalar summa = sum(h);
	outputImg = h / summa[0];

	// debug
	//Images::showImage_inputReal_normTheImage("psf", outputImg);
}

void WienerDeconvolution::calcPSF_CV_64(cv::Mat& outputImg, cv::Size filterSize, int R)
{
	cv::Mat h(filterSize, CV_64F, cv::Scalar(0));
	cv::Point point(filterSize.width / 2, filterSize.height / 2);
	cv::circle(h, point, R, 255, -1, 8);
	cv::Scalar summa = sum(h);
	outputImg = h / summa[0];
}

void WienerDeconvolution::fftshift_CV(const cv::Mat& inputImg, cv::Mat& outputImg)
{
	outputImg = inputImg.clone();
	int cx = outputImg.cols / 2;
	int cy = outputImg.rows / 2;
	cv::Mat q0(outputImg, cv::Rect(0, 0, cx, cy));
	cv::Mat q1(outputImg, cv::Rect(cx, 0, cx, cy));
	cv::Mat q2(outputImg, cv::Rect(0, cy, cx, cy));
	cv::Mat q3(outputImg, cv::Rect(cx, cy, cx, cy));
	cv::Mat tmp;
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);
	q1.copyTo(tmp);
	q2.copyTo(q1);
	tmp.copyTo(q2);
}

void WienerDeconvolution::filter2DFreq_CV(const cv::Mat& inputImg, cv::Mat& outputImg, const cv::Mat& H)
{
	cv::Mat planes[2] = { cv::Mat_<real>(inputImg.clone()), cv::Mat::zeros(inputImg.size(), CV_64F) };
	cv::Mat complexI;
	merge(planes, 2, complexI);
	cv::dft(complexI, complexI, cv::DFT_SCALE);
	cv::Mat planesH[2] = { cv::Mat_<real>(H.clone()), cv::Mat::zeros(H.size(), CV_64F) };
	cv::Mat complexH;
	cv::merge(planesH, 2, complexH);
	cv::Mat complexIH;
	cv::mulSpectrums(complexI, complexH, complexIH, 0);
	cv::idft(complexIH, complexIH);
	cv::split(complexIH, planes);
	outputImg = planes[0];
}

void WienerDeconvolution::calcWnrFilter_CV(const cv::Mat& input_h_PSF, cv::Mat& output_G, double nsr)
{
	cv::Mat h_PSF_shifted;
	fftshift_CV(input_h_PSF, h_PSF_shifted);
	cv::Mat planes[2] = { cv::Mat_<real>(h_PSF_shifted.clone()), cv::Mat::zeros(h_PSF_shifted.size(), CV_64F) };
	cv::Mat complexI;
	cv::merge(planes, 2, complexI);
	cv::dft(complexI, complexI);
	cv::split(complexI, planes);
	cv::Mat denom;
	cv::pow(abs(planes[0]), 2, denom);
	denom += nsr;
	divide(planes[0], denom, output_G);
}

// Wiener Filter -> CR -> based on 

void WienerDeconvolution::calcWienerFilter_CR_Gray(const cv::Mat& bluredImage, cv::Mat& sharpImage_out, const cv::Mat& psf, real SNR)
{

	// it needs to process even image only

	cv::Rect targetSizePSF = cv::Rect(0, 0, bluredImage.cols & -2, bluredImage.rows & -2);
	cv::Size targetSize = targetSizePSF.size();
	//Hw calculation (start)
	cv::Mat Hw;

	cv::Size tempImageSize = bluredImage.size();
	cv::Size tempPSFSize = psf.size();

	cv::Mat psf_expende;

	cv::Rect tempRoi;
	if (tempPSFSize.height >= tempImageSize.height && tempPSFSize.width >= tempImageSize.width)
	{
		psf_expende = cv::Mat::zeros(tempImageSize, CV_64F);
		tempRoi.x = psf.size().width / 2 - tempImageSize.width / 2;
		tempRoi.width = tempImageSize.width;
		tempRoi.y = psf.size().height / 2 - tempImageSize.height / 2;
		tempRoi.height = tempImageSize.height;

		psf_expende = psf(tempRoi);


		if (targetSize.height != psf_expende.size().height || targetSize.width != psf_expende.size().width)
		{
			cv::resize(psf_expende, psf_expende, targetSize, cv::INTER_LANCZOS4);
			
		}

	}


	else if (tempPSFSize.height <= tempImageSize.height && tempPSFSize.width >= tempImageSize.width)
	{

		psf_expende = cv::Mat::zeros(cv::Size(tempImageSize.height, tempImageSize.height), CV_64F);


		psf.copyTo(psf_expende(cv::Range((tempImageSize.height - tempPSFSize.height) / 2, (tempImageSize.height + tempPSFSize.height) / 2), cv::Range((tempImageSize.height -tempPSFSize.width) / 2, (tempImageSize.height + tempPSFSize.width) / 2)));

		tempRoi.x = psf_expende.size().width / 2 - tempImageSize.width / 2;
		tempRoi.width = tempImageSize.width;
		tempRoi.y = 0;
		tempRoi.height = tempImageSize.height;

		psf_expende = psf_expende(tempRoi);

		if (targetSize.height != psf_expende.size().height || targetSize.width != psf_expende.size().width)
		{
			cv::resize(psf_expende, psf_expende, targetSize, cv::INTER_LANCZOS4);
		}
	}

	else if (tempPSFSize.height >= tempImageSize.height && tempPSFSize.width <= tempImageSize.width)
	{

		psf_expende = cv::Mat::zeros(cv::Size(tempImageSize.width, tempImageSize.width), CV_64F);

		psf.copyTo(psf_expende(cv::Range((tempImageSize.width - tempPSFSize.height) / 2, (tempImageSize.width + tempPSFSize.height) / 2), cv::Range((tempImageSize.width - tempPSFSize.width) / 2, (tempImageSize.width + tempPSFSize.width) / 2)));
		
		tempRoi.x = 0;
		tempRoi.width = tempImageSize.width;
		tempRoi.y = psf_expende.size().height / 2 - tempImageSize.height / 2;;
		tempRoi.height = tempImageSize.height;

		psf_expende = psf_expende(tempRoi);


		if (targetSize.height != psf_expende.size().height || targetSize.width != psf_expende.size().width)
		{
			cv::resize(psf_expende, psf_expende, targetSize, cv::INTER_LANCZOS4);
		}
	}


	else
	{
		psf_expende = cv::Mat::zeros(targetSize, CV_64F);
		unsigned int heightOrigin_psf = psf.size().height;
		unsigned int widthOrigin_psf = psf.size().width;

		unsigned int heightExpended_psf = psf_expende.size().height;
		unsigned int widthExpended_psf = psf_expende.size().width;

		// debug
		//Images::showImage_inputReal("ps_origin", psf);
		psf.copyTo(psf_expende(cv::Range((heightExpended_psf - heightOrigin_psf) / 2, (heightExpended_psf + heightOrigin_psf) / 2), cv::Range((widthExpended_psf - widthOrigin_psf) / 2, (widthExpended_psf + widthOrigin_psf) / 2)));
	}
	

	// debug
	//Images::showImage_inputReal_normTheImage("psf origin", psf_expende);
	//Images::showImage_inputReal_normTheImage("psf_expende", psf_expende);

	calcWnrFilter_CV(psf_expende, Hw, 1.0 / double(SNR));
	//just for debugging
	// Images::showImage_inputReal("Hw", Hw);

	//Hw calculation (stop)
	// filtering (start)
	filter2DFreq_CV(bluredImage(targetSizePSF), sharpImage_out, Hw);
	// filtering (stop)
	sharpImage_out.convertTo(sharpImage_out, CV_8U);
	normalize(sharpImage_out, sharpImage_out, 0, 255, cv::NORM_MINMAX);

}

void WienerDeconvolution::calcWienerFilter_CR_Gray_outputNotNormed(const cv::Mat& bluredImage, cv::Mat& sharpImage_out, const cv::Mat& psf, real SNR)
{

	// it needs to process even image only

	cv::Rect targetSizePSF = cv::Rect(0, 0, bluredImage.cols & -2, bluredImage.rows & -2);
	cv::Size targetSize = targetSizePSF.size();
	//Hw calculation (start)
	cv::Mat Hw;

	cv::Size tempImageSize = bluredImage.size();
	cv::Size tempPSFSize = psf.size();

	cv::Mat psf_expende;

	cv::Rect tempRoi;
	if (tempPSFSize.height >= tempImageSize.height && tempPSFSize.width >= tempImageSize.width)
	{
		psf_expende = cv::Mat::zeros(tempImageSize, CV_64F);
		tempRoi.x = psf.size().width / 2 - tempImageSize.width / 2;
		tempRoi.width = tempImageSize.width;
		tempRoi.y = psf.size().height / 2 - tempImageSize.height / 2;
		tempRoi.height = tempImageSize.height;

		psf_expende = psf(tempRoi);


		if (targetSize.height != psf_expende.size().height || targetSize.width != psf_expende.size().width)
		{
			cv::resize(psf_expende, psf_expende, targetSize, cv::INTER_LANCZOS4);

		}

	}


	else if (tempPSFSize.height <= tempImageSize.height && tempPSFSize.width >= tempImageSize.width)
	{

		psf_expende = cv::Mat::zeros(cv::Size(tempImageSize.height, tempImageSize.height), CV_64F);


		psf.copyTo(psf_expende(cv::Range((tempImageSize.height - tempPSFSize.height) / 2, (tempImageSize.height + tempPSFSize.height) / 2), cv::Range((tempImageSize.height - tempPSFSize.width) / 2, (tempImageSize.height + tempPSFSize.width) / 2)));

		tempRoi.x = psf_expende.size().width / 2 - tempImageSize.width / 2;
		tempRoi.width = tempImageSize.width;
		tempRoi.y = 0;
		tempRoi.height = tempImageSize.height;

		psf_expende = psf_expende(tempRoi);

		if (targetSize.height != psf_expende.size().height || targetSize.width != psf_expende.size().width)
		{
			cv::resize(psf_expende, psf_expende, targetSize, cv::INTER_LANCZOS4);
		}
	}

	else if (tempPSFSize.height >= tempImageSize.height && tempPSFSize.width <= tempImageSize.width)
	{

		psf_expende = cv::Mat::zeros(cv::Size(tempImageSize.width, tempImageSize.width), CV_64F);

		psf.copyTo(psf_expende(cv::Range((tempImageSize.width - tempPSFSize.height) / 2, (tempImageSize.width + tempPSFSize.height) / 2), cv::Range((tempImageSize.width - tempPSFSize.width) / 2, (tempImageSize.width + tempPSFSize.width) / 2)));

		tempRoi.x = 0;
		tempRoi.width = tempImageSize.width;
		tempRoi.y = psf_expende.size().height / 2 - tempImageSize.height / 2;;
		tempRoi.height = tempImageSize.height;

		psf_expende = psf_expende(tempRoi);


		if (targetSize.height != psf_expende.size().height || targetSize.width != psf_expende.size().width)
		{
			cv::resize(psf_expende, psf_expende, targetSize, cv::INTER_LANCZOS4);
		}
	}


	else
	{
		psf_expende = cv::Mat::zeros(targetSize, CV_32F);
		unsigned int heightOrigin_psf = psf.size().height;
		unsigned int widthOrigin_psf = psf.size().width;

		unsigned int heightExpended_psf = psf_expende.size().height;
		unsigned int widthExpended_psf = psf_expende.size().width;

		// debug
		//Images::showImage_inputReal("ps_origin", psf);
		psf.copyTo(psf_expende(cv::Range((heightExpended_psf - heightOrigin_psf) / 2, (heightExpended_psf + heightOrigin_psf) / 2), cv::Range((widthExpended_psf - widthOrigin_psf) / 2, (widthExpended_psf + widthOrigin_psf) / 2)));
	}


	// debug
	//Images::showImage_inputReal_normTheImage("psf origin", psf_expende);
	//Images::showImage_inputReal_normTheImage("psf_expende", psf_expende);

	calcWnrFilter_CV(psf_expende, Hw, 1.0 / double(SNR));
	//just for debugging
	// Images::showImage_inputReal("Hw", Hw);

	//Hw calculation (stop)
	// filtering (start)

	cv::normalize(bluredImage, bluredImage, 0,255, cv::NORM_MINMAX);
	cv::Mat bluredImage_CV_8U;
	bluredImage.convertTo(bluredImage_CV_8U, CV_8U);

	
	filter2DFreq_CV(bluredImage_CV_8U(targetSizePSF), sharpImage_out, Hw);

}

void WienerDeconvolution::calcHw(const cv::Mat& input_h_PSF, cv::Mat& output_H, double nsr)
{
	cv::Mat h_PSF_shifted;
	fftshift_CV(input_h_PSF, h_PSF_shifted);
	cv::Mat planes[2] = { cv::Mat_<real>(h_PSF_shifted.clone()), cv::Mat::zeros(h_PSF_shifted.size(), CV_64F) };
	cv::Mat complexI;
	cv::merge(planes, 2, complexI);
	cv::dft(complexI, complexI);
	cv::split(complexI, planes);
	cv::Mat denom;
	cv::pow(abs(planes[0]), 2, denom);
	denom += nsr;
	cv::divide(planes[0], denom, output_H);
}

void WienerDeconvolution::filter2DFreq_CR(const cv::Mat& inputImg, cv::Mat& outputImg, const cv::Mat& Hw)
{
	cv::Mat planes[2] = { cv::Mat_<real>(inputImg.clone()), cv::Mat::zeros(inputImg.size(), CV_64F) };
	cv::Mat complexI;
	merge(planes, 2, complexI);
	cv::dft(complexI, complexI, cv::DFT_SCALE);
	cv::Mat planesH[2] = { cv::Mat_<real>(Hw.clone()), cv::Mat::zeros(Hw.size(), CV_64F) };
	cv::Mat complexH;
	cv::merge(planesH, 2, complexH);
	cv::Mat complexIH;
	cv::mulSpectrums(complexI, complexH, complexIH, 0);
	cv::idft(complexIH, complexIH);
	cv::split(complexIH, planes);
	outputImg = planes[0];

}

// Wiener Filter -> CR -> based on OpenCV -> BGR
void WienerDeconvolution::calcWienerFilter_CR_BGR(const cv::Mat& bluredImage, const cv::Mat& psf_blue, cv::Mat& psf_green, cv::Mat& psf_red, real SNR, /*size initial object*/ cv::Size initialSize)
{
	mBluredIma_BGR = bluredImage;
	mPSF_blue = psf_blue;
	mPSF_green = psf_green;
	mPSF_red = psf_red;
	mSNR = SNR;
	mSizeInitialObj = initialSize;

	// split image in BGR
	splitBGRIma();

	// wiener filter blue
	calcWienerFilter_blue();

	// wiener filter green
	calcWienerFilter_green();

	// wiener filter red
	calcWienerFilter_red();

	// put bgr image to sharp ima
	putImagesTogetherAndScale();

}

void WienerDeconvolution::calcWienerFilter_blue()
{
	// it needs to process even image only
	cv::Rect roi = cv::Rect(0, 0, mBluredIma_blue.cols & -2, mBluredIma_blue.rows & -2);

	real nsr = 1.0 / mSNR;

	// calculate Hw
		//cv::normalize(mSimulatedIma_bgr_unscaled, mSimulatedIma_bgr_final, 0, 255, cv::NORM_MINMAX);
	cv::Mat Hw;
	cv::Size sizeROI(roi.height, roi.width);
	cv::Mat psf_expende(sizeROI, CV_64F, cv::Scalar(0));

	cv::normalize(mPSF_blue, mPSF_blue, 0.0, 255.0, cv::NORM_MINMAX);
	unsigned int heightOrigin_psf = mPSF_blue.size().height;
	unsigned int widthOrigin_psf = mPSF_blue.size().width;

	unsigned int heightExpended_psf = psf_expende.size().height;
	unsigned int widthExpended_psf = psf_expende.size().width;

	// debug
	//Images::showImage_inputReal("ps_origin", psf);
	mPSF_blue.copyTo(psf_expende(cv::Range((heightExpended_psf - heightOrigin_psf) / 2, (heightExpended_psf + heightOrigin_psf) / 2), cv::Range((widthExpended_psf - widthOrigin_psf) / 2, (widthExpended_psf + widthOrigin_psf) / 2)));
	// debug
	//Images::showImage_inputReal("psf_expende", psf_expende);
	cv::normalize(psf_expende, psf_expende, 0.0, 255.0, cv::NORM_MINMAX);
	cv::Scalar summa = cv::sum(psf_expende);
	psf_expende = psf_expende / summa[0];
	//////test ***
	//cv::Mat h;
	//real R = 1.5;
	//calcPSF_CV(h, roi.size(), R);

	// ***
	calcHw(psf_expende, Hw, nsr);

	filter2DFreq_CR(mBluredIma_blue(roi), mImageSharp_blue, Hw);

}

void WienerDeconvolution::calcWienerFilter_green()
{
	// it needs to process even image only
	cv::Rect roi = cv::Rect(0, 0, mBluredIma_green.cols & -2, mBluredIma_green.rows & -2);

	real nsr = 1.0 / mSNR;

	// calculate Hw
		//cv::normalize(mSimulatedIma_bgr_unscaled, mSimulatedIma_bgr_final, 0, 255, cv::NORM_MINMAX);
	cv::Mat Hw;
	cv::Size sizeROI(roi.height, roi.width);
	cv::Mat psf_expende(sizeROI, CV_64F, cv::Scalar(0));

	cv::normalize(mPSF_green, mPSF_green, 0.0, 255.0, cv::NORM_MINMAX);
	unsigned int heightOrigin_psf = mPSF_green.size().height;
	unsigned int widthOrigin_psf = mPSF_green.size().width;

	unsigned int heightExpended_psf = psf_expende.size().height;
	unsigned int widthExpended_psf = psf_expende.size().width;

	// debug
	//Images::showImage_inputReal("ps_origin", psf);
	mPSF_green.copyTo(psf_expende(cv::Range((heightExpended_psf - heightOrigin_psf) / 2, (heightExpended_psf + heightOrigin_psf) / 2), cv::Range((widthExpended_psf - widthOrigin_psf) / 2, (widthExpended_psf + widthOrigin_psf) / 2)));
	// debug
	//Images::showImage_inputReal("psf_expende", psf_expende);
	cv::normalize(psf_expende, psf_expende, 0.0, 255.0, cv::NORM_MINMAX);
	cv::Scalar summa = cv::sum(psf_expende);
	psf_expende = psf_expende / summa[0];
	//////test ***
	//cv::Mat h;
	//real R = 1.5;
	//calcPSF_CV(h, roi.size(), R);

	// ***
	calcHw(psf_expende, Hw, nsr);

	filter2DFreq_CR(mBluredIma_green(roi), mImageSharp_green, Hw);
}

void WienerDeconvolution::calcWienerFilter_red()
{
	// it needs to process even image only
	cv::Rect roi = cv::Rect(0, 0, mBluredIma_red.cols & -2, mBluredIma_red.rows & -2);

	real nsr = 1.0 / mSNR;

	// calculate Hw
		//cv::normalize(mSimulatedIma_bgr_unscaled, mSimulatedIma_bgr_final, 0, 255, cv::NORM_MINMAX);
	cv::Mat Hw;
	cv::Size sizeROI(roi.height, roi.width);
	cv::Mat psf_expende(sizeROI, CV_64F, cv::Scalar(0));

	cv::normalize(mPSF_red, mPSF_red, 0.0, 255.0, cv::NORM_MINMAX);
	unsigned int heightOrigin_psf = mPSF_red.size().height;
	unsigned int widthOrigin_psf = mPSF_red.size().width;

	unsigned int heightExpended_psf = psf_expende.size().height;
	unsigned int widthExpended_psf = psf_expende.size().width;

	// debug
	//Images::showImage_inputReal("ps_origin", psf);
	mPSF_red.copyTo(psf_expende(cv::Range((heightExpended_psf - heightOrigin_psf) / 2, (heightExpended_psf + heightOrigin_psf) / 2), cv::Range((widthExpended_psf - widthOrigin_psf) / 2, (widthExpended_psf + widthOrigin_psf) / 2)));
	// debug
	//Images::showImage_inputReal("psf_expende", psf_expende);
	cv::normalize(psf_expende, psf_expende, 0.0, 255.0, cv::NORM_MINMAX);
	cv::Scalar summa = cv::sum(psf_expende);
	psf_expende = psf_expende / summa[0];
	//////test ***
	//cv::Mat h;
	//real R = 1.5;
	//calcPSF_CV(h, roi.size(), R);

	// ***
	calcHw(psf_expende, Hw, nsr);

	filter2DFreq_CR(mBluredIma_red(roi), mImageSharp_red, Hw);
}

void WienerDeconvolution::splitBGRIma()
{
	cv::Mat channel[3];
	cv::split(mBluredIma_BGR, channel);


	mBluredIma_blue = channel[0];
	mBluredIma_green = channel[1];
	mBluredIma_red = channel[2];

}

void WienerDeconvolution::putImagesTogetherAndScale()
{
	std::vector<cv::Mat> array_to_merge;

	array_to_merge.push_back(mImageSharp_blue);
	array_to_merge.push_back(mImageSharp_green);
	array_to_merge.push_back(mImageSharp_red);
	//debug 
	//Images::showImage_inputReal_normTheImage("sharp ima red", mImageSharp_red);

	cv::merge(array_to_merge, mSharpImageFinal_BGR_64);
	//debug 
	//Images::showImage_inputReal_normTheImage("final sharp ima", mSharpImageFinal_BGR_64);

	real min{};
	real max{};

	cv::minMaxLoc(mSharpImageFinal_BGR_64, &min, &max);
	real ratio = 1.0 / max;

	mSharpImageFinal_BGR_64 = mSharpImageFinal_BGR_64 * ratio;

	cv::resize(mSharpImageFinal_BGR_64, mSharpImageFinal_BGR_64_initialSize, mSizeInitialObj, cv::INTER_LANCZOS4);



}

void WienerDeconvolution::wienerDeconvolution_superFct_doNotUseThatFunction(std::vector<cv::Mat> /*PSF vec blue*/ psf_vec_blue, std::vector<cv::Mat> /*PSF vec green*/ psf_vec_green, std::vector<cv::Mat> /*PSF vec red*/ psf_vec_red,
	std::vector<cv::Mat> /*image parts blue*/ imageParts_blue, std::vector<cv::Mat> /*image parts green*/ imageParts_green, std::vector<cv::Mat> /*image parts red*/ imageParts_red,
	loadParaImaSim /*parameter ima sim*/ defaulPara,  /*SNR*/ real SNR, /*size initial object*/ cv::Size sizeInitialObj, /*size obj for convolution*/ cv::Size sizeObjForConv)
{
	// save data in private
	mPsf_vec_blue = psf_vec_blue;
	mPsf_vec_green = psf_vec_green;
	mPsf_vec_red = psf_vec_red;
	mImageParts_blue = imageParts_blue;
	mImageParts_green = imageParts_green;
	mImageParts_red = imageParts_red;
	mParameterImageSimulation = defaulPara;
	mSNR = SNR;
	mSizeInitialObj = sizeInitialObj;
	mSizeResizedObjForConv = sizeObjForConv;

	// wiender filtering
	calcWienerFileterInSuperFct_doNotUseThatFunction();

	// put all image grids together
	putAllImageGridsTogether_doNotUseThatFunction();

}

void WienerDeconvolution::wienerDeconvolution_superFct(std::vector<cv::Mat> /*PSF vec blue*/ psf_vec_blue, std::vector<cv::Mat> /*PSF vec green*/ psf_vec_green, std::vector<cv::Mat> /*PSF vec red*/ psf_vec_red,
	std::vector<cv::Mat> /*image parts blue*/ imageParts_blue, std::vector<cv::Mat> /*image parts green*/ imageParts_green, std::vector<cv::Mat> /*image parts red*/ imageParts_red,
	loadParaImaSim /*parameter ima sim*/ defaulPara,  /*SNR*/ real SNR, /*size initial object*/ cv::Size sizeInitialObj, /*size obj for convolution*/ cv::Size sizeObjForConv, cv::Size inceaseSize)
{
	// save data in private
	mPsf_vec_blue = psf_vec_blue;
	mPsf_vec_green = psf_vec_green;
	mPsf_vec_red = psf_vec_red;
	mImageParts_blue = imageParts_blue;
	mImageParts_green = imageParts_green;
	mImageParts_red = imageParts_red;
	mParameterImageSimulation = defaulPara;
	mSNR = SNR;
	mSizeInitialObj = sizeInitialObj;
	mSizeResizedObjForConv = sizeObjForConv;
	mInceaseSize = inceaseSize;

	// wiender filtering
	calcWienerFileterInSuperFct();

	// put all image grids together
	putAllImageGridsTogether_doNotUseThatFunction();


}


void WienerDeconvolution::calcWienerFileterInSuperFct()
{
	unsigned int sizeImaParts = mImageParts_blue.size();
	real nsr = 1.0 / mSNR;

	cv::Mat tempImag_blue;
	cv::Size tempIma_blueSize;
	cv::Mat tempIma_bLueResize;
	cv::Mat tempSharpIma_blue;
	cv::Mat tempSharpIma_blue_originalSize;

	cv::Mat tempImag_green;
	cv::Size tempIma_greenSize;
	cv::Mat tempIma_greenResize;
	cv::Mat tempSharpIma_green;
	cv::Mat tempSharpIma_green_originalSize;

	cv::Mat tempImag_red;
	cv::Size tempIma_redSize;
	cv::Mat tempIma_redResize;
	cv::Mat tempSharpIma_red;
	cv::Mat tempSharpIma_red_originalSize;

	mImagePartsSharp_blue.resize(sizeImaParts);
	mImagePartsSharp_green.resize(sizeImaParts);
	mImagePartsSharp_red.resize(sizeImaParts);

	for (unsigned int i = 0; i < sizeImaParts; ++i)
	{

		// blue
		tempImag_blue = mImageParts_blue[i];
		tempIma_blueSize = tempImag_blue.size();
		cv::resize(tempImag_blue, tempIma_bLueResize, mInceaseSize, cv::INTER_LANCZOS4);
		calcWienerFilter_CR_Gray(tempIma_bLueResize, tempSharpIma_blue, mPsf_vec_blue[i], mSNR);
		cv::resize(tempIma_bLueResize, tempSharpIma_blue_originalSize, tempIma_blueSize, cv::INTER_LANCZOS4);
		mImagePartsSharp_blue[i] = tempSharpIma_blue_originalSize.clone();

		// debug
		//Images::showImage_inputReal_normTheImage("sharpImaBlue", tempSharpIma_blue_originalSize);

		// green
		tempImag_green = mImageParts_green[i];
		tempIma_greenSize = tempImag_green.size();
		cv::resize(tempImag_green, tempIma_greenResize, mInceaseSize, cv::INTER_LANCZOS4);
		calcWienerFilter_CR_Gray(tempIma_greenResize, tempSharpIma_green, mPsf_vec_green[i], mSNR);
		cv::resize(tempIma_greenResize, tempSharpIma_green_originalSize, tempIma_greenSize, cv::INTER_LANCZOS4);
		mImagePartsSharp_green[i] = tempSharpIma_green_originalSize.clone();

		// red
		tempImag_red = mImageParts_red[i];
		tempIma_redSize = tempImag_red.size();
		cv::resize(tempImag_red, tempIma_redResize, mInceaseSize, cv::INTER_LANCZOS4);
		calcWienerFilter_CR_Gray(tempIma_redResize, tempSharpIma_red, mPsf_vec_red[i], mSNR);
		cv::resize(tempIma_redResize, tempSharpIma_red_originalSize, tempIma_redSize, cv::INTER_LANCZOS4);
		mImagePartsSharp_red[i] = tempSharpIma_red_originalSize.clone();

	}

}

void WienerDeconvolution::wienderDeconv_superFkt_grayIma(std::vector<cv::Mat> /*PSF vec*/ psf_vec, std::vector<cv::Mat> /*image parts blue*/ imageParts, loadParaImaSim /*parameter ima sim*/ defaulPara,  /*SNR*/ real SNR, cv::Size sizeObjForConv)
{
	unsigned int sizeImaParts = imageParts.size();
	mSNR = SNR;

	cv::Mat tempImag;
	cv::Size tempImaSize;
	cv::Mat tempSharpImaPart;

	mShartImageParts_gray.resize(sizeImaParts);


	for (unsigned int i = 0; i < sizeImaParts; ++i)
	{

		tempImag = imageParts[i];
		tempImaSize = tempImag.size();
		calcWienerFilter_CR_Gray_outputNotNormed(tempImag, tempSharpImaPart, psf_vec[i], mSNR);
		cv::resize(tempSharpImaPart, tempSharpImaPart, tempImaSize, cv::INTER_LANCZOS4);
		mShartImageParts_gray[i] = tempSharpImaPart.clone();

		// debug
		//if (i == 40)
		//{
		//	Images::showImage_inputReal_normImaByROI_inPercent("sharpImaBlue40", tempSharpImaPart, 10.0);
		//}
		

	}


	unsigned int sampling = defaulPara.getSampling_x();
	unsigned int rowObjAda = sizeObjForConv.height;
	unsigned int colObjAda = sizeObjForConv.width;

	unsigned int tempStartRow = 0;
	unsigned int separationRow = rowObjAda / (sampling - 1);
	unsigned int tempEndRow = separationRow / 2;

	unsigned int tempStartRowInGrid = 0;
	unsigned int tempEndRowInGrid = separationRow / 2;

	unsigned int tempStartCol = 0;
	unsigned int separationCol = colObjAda / (sampling - 1);
	unsigned int tempEndCol = separationCol / 2;

	unsigned int tempStartColInGrid = 0;
	unsigned int tempEndColInGrid = separationCol / 2;

	unsigned int sizeObjGrid = defaulPara.getSampling_x() * defaulPara.getSampling_x();

	mImageSharp_gray = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), imageParts[0].type());


	cv::Mat imageSharpPart_gray;


	unsigned int counter = 0;
	// just for debugging
	//std::string counterStr;

	real tempMin{};
	real tempMax{};
	real deltaCol{};
	real deltaRow{};

	for (unsigned int i = 0; i < defaulPara.getSampling_x(); ++i)
	{
		for (unsigned int j = 0; j < defaulPara.getSampling_x(); ++j)
		{
			if (j == sampling - 1)
			{
				//tempEndColInGrid = mSimulatedImageGrid_blue[counter].size().width;
				tempEndCol = mImageSharp_gray.size().width;

				deltaCol = tempEndCol - tempStartCol;
				tempEndColInGrid = tempStartColInGrid + deltaCol;

				//Images::showImage_inputReal_normTheImage("affe", mImageSharp_gray);
				//Images::showImage_inputReal_normTheImage("part", imageSharpPart_gray);

		
			}

			// *** gray
			imageSharpPart_gray = mShartImageParts_gray[counter](cv::Range(tempStartRowInGrid, tempEndRowInGrid), cv::Range(tempStartColInGrid, tempEndColInGrid));
			//tempMin = mMinBlue_vec[counter];
			//tempMax = mMaxBlue_vec[counter];
			//cv::normalize(imagePart_blue, imagePart_blue, tempMin, tempMax, cv::NORM_MINMAX);
			imageSharpPart_gray.copyTo(mImageSharp_gray(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol)));
			// just for debugging
			//Images::showImage_inputReal_normTheImage("blue ima grid", mImageSharp_blue);
			//Images::showImage_inputReal("blue ima", mSimulatedIma_blue);
			//counterStr = std::to_string(counter);
			//Images::saveImage("..", "partBlue" + counterStr, "png", imagePart_blue);

			tempStartCol = tempEndCol;
			tempEndCol = tempEndCol + separationCol;

			tempStartColInGrid = defaulPara.getColBiggerForConv();
			tempEndColInGrid = separationCol + defaulPara.getColBiggerForConv();

			++counter;

		}

		tempStartColInGrid = 0;
		tempEndColInGrid = separationCol / 2;

		tempStartCol = 0;
		tempEndCol = separationCol / 2;

		tempStartRow = tempEndRow;
		tempEndRow = tempEndRow + separationRow;

		tempStartRowInGrid = defaulPara.getRowBiggerForConv();
		tempEndRowInGrid = separationRow + defaulPara.getRowBiggerForConv();

		if (i == sampling - 2)
		{
			// tempEndRowInGrid = mSimulatedImageGrid_blue[counter].size().height;
			tempEndRow = mImageSharp_gray.size().height;

			deltaRow = tempEndRow - tempStartRow;
			tempEndRowInGrid = tempStartRowInGrid + deltaRow;
		}

	}


}


// get gray image
cv::Mat WienerDeconvolution::getGrayImage()
{
	return mImageSharp_gray;
}

void WienerDeconvolution::calcWienerFileterInSuperFct_doNotUseThatFunction()
{

	unsigned int sizeImaParts = mImageParts_blue.size();
	cv::Rect tempRoi{};
	real nsr = 1.0 / mSNR;

	cv::Mat tempPSF_blue;
	cv::Mat tempAdaptedPSF_blue;
	cv::Mat Hw_blue;
	cv::Mat sharpImage_blue;
	cv::Scalar summa_blue;
	cv::Mat sharpImagePart_blue;
	mShartImageParts_blue.resize(sizeImaParts);

	cv::Mat tempPSF_green;
	cv::Mat tempAdaptedPSF_green;
	cv::Mat Hw_green;
	cv::Mat sharpImage_green;
	cv::Scalar summa_green;
	cv::Mat sharpImagePart_green;
	mShartImageParts_green.resize(sizeImaParts);

	cv::Mat tempPSF_red;
	cv::Mat tempAdaptedPSF_red;
	cv::Mat Hw_red;
	cv::Mat sharpImage_red;
	cv::Scalar summa_red;
	cv::Mat sharpImagePart_red;
	mShartImageParts_red.resize(sizeImaParts);

	mImagePartsSharp_blue.resize(sizeImaParts);
	mImagePartsSharp_green.resize(sizeImaParts);
	mImagePartsSharp_red.resize(sizeImaParts);

	cv::Size tempImageSize;

	for (unsigned int i = 0; i < sizeImaParts; ++i)
	{

		tempPSF_blue = mPsf_vec_blue[i];
		tempPSF_green = mPsf_vec_green[i];
		tempPSF_red = mPsf_vec_red[i];

		tempImageSize = mImageParts_blue[i].size();

		if (tempPSF_blue.size().height >= tempImageSize.height && tempPSF_blue.size().width >= tempImageSize.width)
		{

			tempRoi.x = tempPSF_blue.size().width / 2 - tempImageSize.width / 2;
			tempRoi.width = tempImageSize.width;
			tempRoi.y = tempPSF_blue.size().height / 2 - tempImageSize.height / 2;
			tempRoi.height = tempImageSize.height;

			tempAdaptedPSF_blue = tempPSF_blue(tempRoi);
			tempAdaptedPSF_green = tempPSF_green(tempRoi);
			tempAdaptedPSF_red = tempPSF_red(tempRoi);

			if (tempImageSize.height != tempAdaptedPSF_blue.size().height || tempImageSize.width != tempAdaptedPSF_blue.size().width)
			{
				cv::resize(tempAdaptedPSF_blue, tempAdaptedPSF_blue, tempImageSize, cv::INTER_LANCZOS4);
				cv::resize(tempAdaptedPSF_green, tempAdaptedPSF_green, tempImageSize, cv::INTER_LANCZOS4);
				cv::resize(tempAdaptedPSF_red, tempAdaptedPSF_red, tempImageSize, cv::INTER_LANCZOS4);
			}

		}

		else if (tempPSF_blue.size().height <= tempImageSize.height && tempPSF_blue.size().width <= tempImageSize.width)
		{

			tempAdaptedPSF_blue = cv::Mat::zeros(tempImageSize, CV_64F);
			tempAdaptedPSF_green = cv::Mat::zeros(tempImageSize, CV_64F);
			tempAdaptedPSF_red = cv::Mat::zeros(tempImageSize, CV_64F);

			tempPSF_blue.copyTo(tempAdaptedPSF_blue(cv::Range((tempImageSize.height - tempPSF_blue.size().height) / 2, (tempImageSize.height + tempPSF_blue.size().height) / 2), cv::Range((tempImageSize.width - tempPSF_blue.size().width) / 2, (tempImageSize.width + tempPSF_blue.size().width) / 2)));
			tempPSF_green.copyTo(tempAdaptedPSF_green(cv::Range((tempImageSize.height - tempPSF_blue.size().height) / 2, (tempImageSize.height + tempPSF_blue.size().height) / 2), cv::Range((tempImageSize.width - tempPSF_blue.size().width) / 2, (tempImageSize.width + tempPSF_blue.size().width) / 2)));
			tempPSF_red.copyTo(tempAdaptedPSF_red(cv::Range((tempImageSize.height - tempPSF_blue.size().height) / 2, (tempImageSize.height + tempPSF_blue.size().height) / 2), cv::Range((tempImageSize.width - tempPSF_blue.size().width) / 2, (tempImageSize.width + tempPSF_blue.size().width) / 2)));

			if (tempImageSize.height != tempAdaptedPSF_blue.size().height || tempImageSize.width != tempAdaptedPSF_blue.size().width)
			{
				cv::resize(tempAdaptedPSF_blue, tempAdaptedPSF_blue, tempImageSize, cv::INTER_LANCZOS4);
				cv::resize(tempAdaptedPSF_green, tempAdaptedPSF_green, tempImageSize, cv::INTER_LANCZOS4);
				cv::resize(tempAdaptedPSF_red, tempAdaptedPSF_red, tempImageSize, cv::INTER_LANCZOS4);
			}
		}

		else if (tempPSF_blue.size().height <= tempImageSize.height && tempPSF_blue.size().width >= tempImageSize.width)
		{

			tempAdaptedPSF_blue = cv::Mat::zeros(cv::Size(tempImageSize.height, tempImageSize.height), CV_64F);
			tempAdaptedPSF_green = cv::Mat::zeros(cv::Size(tempImageSize.height, tempImageSize.height), CV_64F);
			tempAdaptedPSF_red = cv::Mat::zeros(cv::Size(tempImageSize.height, tempImageSize.height), CV_64F);

			tempPSF_blue.copyTo(tempAdaptedPSF_blue(cv::Range((tempImageSize.height - tempPSF_blue.size().height) / 2, (tempImageSize.height + tempPSF_blue.size().height) / 2), cv::Range((tempImageSize.height - tempPSF_blue.size().width) / 2, (tempImageSize.height + tempPSF_blue.size().width) / 2)));
			tempPSF_green.copyTo(tempAdaptedPSF_green(cv::Range((tempImageSize.height - tempPSF_blue.size().height) / 2, (tempImageSize.height + tempPSF_blue.size().height) / 2), cv::Range((tempImageSize.height - tempPSF_blue.size().width) / 2, (tempImageSize.height + tempPSF_blue.size().width) / 2)));
			tempPSF_red.copyTo(tempAdaptedPSF_red(cv::Range((tempImageSize.height - tempPSF_blue.size().height) / 2, (tempImageSize.height + tempPSF_blue.size().height) / 2), cv::Range((tempImageSize.height - tempPSF_blue.size().width) / 2, (tempImageSize.height + tempPSF_blue.size().width) / 2)));

			tempRoi.x = tempAdaptedPSF_blue.size().width / 2 - tempImageSize.width / 2;
			tempRoi.width = tempImageSize.width;
			tempRoi.y = 0;
			tempRoi.height = tempImageSize.height;

			tempAdaptedPSF_blue = tempAdaptedPSF_blue(tempRoi);
			tempAdaptedPSF_green = tempAdaptedPSF_green(tempRoi);
			tempAdaptedPSF_red = tempAdaptedPSF_red(tempRoi);

			if (tempImageSize.height != tempAdaptedPSF_blue.size().height || tempImageSize.width != tempAdaptedPSF_blue.size().width)
			{
				cv::resize(tempAdaptedPSF_blue, tempAdaptedPSF_blue, tempImageSize, cv::INTER_LANCZOS4);
				cv::resize(tempAdaptedPSF_green, tempAdaptedPSF_green, tempImageSize, cv::INTER_LANCZOS4);
				cv::resize(tempAdaptedPSF_red, tempAdaptedPSF_red, tempImageSize, cv::INTER_LANCZOS4);
			}
		}

		else if (tempPSF_blue.size().height >= tempImageSize.height && tempPSF_blue.size().width <= tempImageSize.width)
		{

			tempAdaptedPSF_blue = cv::Mat::zeros(cv::Size(tempImageSize.width, tempImageSize.width), CV_64F);
			tempAdaptedPSF_green = cv::Mat::zeros(cv::Size(tempImageSize.width, tempImageSize.width), CV_64F);
			tempAdaptedPSF_red = cv::Mat::zeros(cv::Size(tempImageSize.width, tempImageSize.width), CV_64F);

			tempPSF_blue.copyTo(tempAdaptedPSF_blue(cv::Range((tempImageSize.width - tempPSF_blue.size().height) / 2, (tempImageSize.width + tempPSF_blue.size().height) / 2), cv::Range((tempImageSize.width - tempPSF_blue.size().width) / 2, (tempImageSize.width + tempPSF_blue.size().width) / 2)));
			tempPSF_green.copyTo(tempAdaptedPSF_green(cv::Range((tempImageSize.width - tempPSF_blue.size().height) / 2, (tempImageSize.width + tempPSF_blue.size().height) / 2), cv::Range((tempImageSize.width - tempPSF_blue.size().width) / 2, (tempImageSize.width + tempPSF_blue.size().width) / 2)));
			tempPSF_red.copyTo(tempAdaptedPSF_red(cv::Range((tempImageSize.width - tempPSF_blue.size().height) / 2, (tempImageSize.width + tempPSF_blue.size().height) / 2), cv::Range((tempImageSize.width - tempPSF_blue.size().width) / 2, (tempImageSize.width + tempPSF_blue.size().width) / 2)));

			tempRoi.x = 0;
			tempRoi.width = tempImageSize.width;
			tempRoi.y = tempAdaptedPSF_blue.size().height / 2 - tempImageSize.height / 2;;
			tempRoi.height = tempImageSize.height;

			tempAdaptedPSF_blue = tempAdaptedPSF_blue(tempRoi);
			tempAdaptedPSF_green = tempAdaptedPSF_green(tempRoi);
			tempAdaptedPSF_red = tempAdaptedPSF_red(tempRoi);

			if (tempImageSize.height != tempAdaptedPSF_blue.size().height || tempImageSize.width != tempAdaptedPSF_blue.size().width)
			{
				cv::resize(tempAdaptedPSF_blue, tempAdaptedPSF_blue, tempImageSize, cv::INTER_LANCZOS4);
				cv::resize(tempAdaptedPSF_green, tempAdaptedPSF_green, tempImageSize, cv::INTER_LANCZOS4);
				cv::resize(tempAdaptedPSF_red, tempAdaptedPSF_red, tempImageSize, cv::INTER_LANCZOS4);
			}
		}

		// debug
		//if (i < 5)
		//{
		//	Images::showImage_inputReal("PSF blue", tempAdaptedPSF_blue);
		//}

		cv::normalize(tempAdaptedPSF_blue, tempAdaptedPSF_blue, 0.0, 255.0, cv::NORM_MINMAX);
		cv::normalize(tempAdaptedPSF_green, tempAdaptedPSF_green, 0.0, 255.0, cv::NORM_MINMAX);
		cv::normalize(tempAdaptedPSF_red, tempAdaptedPSF_red, 0.0, 255.0, cv::NORM_MINMAX);
		//
		summa_blue = cv::sum(tempAdaptedPSF_blue);
		summa_green = cv::sum(tempAdaptedPSF_green);
		summa_red = cv::sum(tempAdaptedPSF_red);

		tempAdaptedPSF_blue = tempAdaptedPSF_blue / summa_blue[0];
		tempAdaptedPSF_green = tempAdaptedPSF_green / summa_green[0];
		tempAdaptedPSF_red = tempAdaptedPSF_red / summa_red[0];

		// ***
		calcHw(tempAdaptedPSF_blue, Hw_blue, nsr);
		calcHw(tempAdaptedPSF_green, Hw_green, nsr);
		calcHw(tempAdaptedPSF_red, Hw_red, nsr);

		//calcHw(psf_normalized_blue, Hw_blue, nsr);
		//calcHw(psf_normalized_green, Hw_green, nsr);
		//calcHw(psf_normalized_red, Hw_red, nsr);


		//cv::resize(Hw_blue, Hw_blue, mImageParts_blue[i].size(), cv::INTER_LANCZOS4);
		//cv::resize(Hw_green, Hw_green, mImageParts_green[i].size(), cv::INTER_LANCZOS4);
		//cv::resize(Hw_red, Hw_red, mImageParts_red[i].size(), cv::INTER_LANCZOS4);

		// debug
		//Images::showImage_inputReal("Hw origin", Hw_blue);
		//Images::saveImage("..", "Hw_origin", "png", Hw);


		//// debug
		//Images::showImage_inputReal("Hw expended", H_expanded);
		//Images::saveImage("../", "test", "png", H_expanded);

		//debug
		//int k{};
		//if (mImageParts_blue[i].size() != Hw_blue.size())
		//{
		//	k = 5;
		//}

		cv::Mat tempImaBlue;
		cv::Mat tempImaGreen;
		cv::Mat tempImaRed;

		//cv::normalize(mImageParts_blue[i], tempImaBlue, 0.0, 255.0, cv::NORM_MINMAX);
		//cv::normalize(mImageParts_green[i], tempImaGreen, 0.0, 255.0, cv::NORM_MINMAX);
		//cv::normalize(mImageParts_red[i], tempImaRed, 0.0, 255.0, cv::NORM_MINMAX);
		//
		//filter2DFreq_CR(tempImaBlue, sharpImagePart_blue, Hw_blue);
		//filter2DFreq_CR(tempImaGreen, sharpImagePart_green, Hw_green);
		//filter2DFreq_CR(tempImaRed, sharpImagePart_red, Hw_red);

		filter2DFreq_CR(mImageParts_blue[i], sharpImagePart_blue, Hw_blue);
		filter2DFreq_CR(mImageParts_green[i], sharpImagePart_green, Hw_green);
		filter2DFreq_CR(mImageParts_red[i], sharpImagePart_red, Hw_red);

		//filter2DFreq_CR(mImageParts_blue[i], sharpImagePart_blue, Hw_blue);
		//filter2DFreq_CR(mImageParts_green[i], sharpImagePart_green, Hw_green);
		//filter2DFreq_CR(mImageParts_red[i], sharpImagePart_red, Hw_red);


		//cv::normalize(sharpImagePart_blue, sharpImagePart_blue, 0.0, 1.0, cv::NORM_MINMAX);
		//cv::normalize(sharpImagePart_green, sharpImagePart_green, 0.0, 1.0, cv::NORM_MINMAX);
		//cv::normalize(sharpImagePart_red, sharpImagePart_red, 0.0, 1.0, cv::NORM_MINMAX);

		mImagePartsSharp_blue[i] = sharpImagePart_blue;
		mImagePartsSharp_green[i] = sharpImagePart_green;
		mImagePartsSharp_red[i] = sharpImagePart_red;

		// debug
		//if (i < 5)
		//{
		//	Images::showImage_inputReal("sharp ima blue", sharpImagePart_blue);
		//}

		//// debug
		//Images::showImage_inputReal("sharp image part blue", sharpImagePart_blue);

	}


	//// debug
	//std::string location = "../tests/testImproveImageQuality/E0";
	//saveAllSharpImageParts_blue(location);
	//saveAllSharpImageParts_green(location);
	//saveAllSharpImageParts_red(location);


}

void WienerDeconvolution::putAllImageGridsTogether_doNotUseThatFunction()
{
	unsigned int sampling = mParameterImageSimulation.getSampling_x();
	unsigned int rowObjAda = mSizeResizedObjForConv.height;
	unsigned int colObjAda = mSizeResizedObjForConv.width;

	unsigned int tempStartRow = 0;
	unsigned int separationRow = rowObjAda / (sampling - 1);
	unsigned int tempEndRow = separationRow / 2;

	unsigned int tempStartRowInGrid = 0;
	unsigned int tempEndRowInGrid = separationRow / 2;

	unsigned int tempStartCol = 0;
	unsigned int separationCol = colObjAda / (sampling - 1);
	unsigned int tempEndCol = separationCol / 2;

	unsigned int tempStartColInGrid = 0;
	unsigned int tempEndColInGrid = separationCol / 2;

	unsigned int sizeObjGrid = mParameterImageSimulation.getSampling_x() * mParameterImageSimulation.getSampling_x();

	mImageSharp_blue = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mImagePartsSharp_blue[0].type());
	mImageSharp_green = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mImagePartsSharp_green[0].type());
	mImageSharp_red = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mImagePartsSharp_red[0].type());

	cv::Mat imageSharpPart_blue;
	cv::Mat imageSharpPart_green;
	cv::Mat imageSharpPart_red;

	unsigned int counter = 0;
	// just for debugging
	//std::string counterStr;

	real tempMin{};
	real tempMax{};
	real deltaCol{};
	real deltaRow{};

	for (unsigned int i = 0; i < mParameterImageSimulation.getSampling_x(); ++i)
	{
		for (unsigned int j = 0; j < mParameterImageSimulation.getSampling_x(); ++j)
		{
			if (j == sampling - 1)
			{
				//tempEndColInGrid = mSimulatedImageGrid_blue[counter].size().width;
				tempEndCol = mImageSharp_blue.size().width;

				deltaCol = tempEndCol - tempStartCol;
				tempEndColInGrid = tempStartColInGrid + deltaCol;
			}

			// *** blue
			imageSharpPart_blue = mImagePartsSharp_blue[counter](cv::Range(tempStartRowInGrid, tempEndRowInGrid), cv::Range(tempStartColInGrid, tempEndColInGrid));
			//tempMin = mMinBlue_vec[counter];
			//tempMax = mMaxBlue_vec[counter];
			//cv::normalize(imagePart_blue, imagePart_blue, tempMin, tempMax, cv::NORM_MINMAX);
			imageSharpPart_blue.copyTo(mImageSharp_blue(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol)));
			// just for debugging
			//Images::showImage_inputReal_normTheImage("blue ima grid", mImageSharp_blue);
			//Images::showImage_inputReal("blue ima", mSimulatedIma_blue);
			//counterStr = std::to_string(counter);
			//Images::saveImage("..", "partBlue" + counterStr, "png", imagePart_blue);

			// *** green
			imageSharpPart_green = mImagePartsSharp_green[counter](cv::Range(tempStartRowInGrid, tempEndRowInGrid), cv::Range(tempStartColInGrid, tempEndColInGrid));
			//tempMin = mMinGreen_vec[counter];
			//tempMax = mMaxGreen_vec[counter];
			//cv::normalize(imagePart_green, imagePart_green, tempMin, tempMax, cv::NORM_MINMAX);
			imageSharpPart_green.copyTo(mImageSharp_green(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol)));

			// *** red
			imageSharpPart_red = mImagePartsSharp_red[counter](cv::Range(tempStartRowInGrid, tempEndRowInGrid), cv::Range(tempStartColInGrid, tempEndColInGrid));
			//tempMin = mMinRed_vec[counter];
			//tempMax = mMaxRed_vec[counter];
			//cv::normalize(imagePart_red, imagePart_red, tempMin, tempMax, cv::NORM_MINMAX);
			imageSharpPart_red.copyTo(mImageSharp_red(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol)));

			tempStartCol = tempEndCol;
			tempEndCol = tempEndCol + separationCol;

			tempStartColInGrid = mParameterImageSimulation.getColBiggerForConv();
			tempEndColInGrid = separationCol + mParameterImageSimulation.getColBiggerForConv();

			++counter;

		}

		tempStartColInGrid = 0;
		tempEndColInGrid = separationCol / 2;

		tempStartCol = 0;
		tempEndCol = separationCol / 2;

		tempStartRow = tempEndRow;
		tempEndRow = tempEndRow + separationRow;

		tempStartRowInGrid = mParameterImageSimulation.getRowBiggerForConv();
		tempEndRowInGrid = separationRow + mParameterImageSimulation.getRowBiggerForConv();

		if (i == sampling - 2)
		{
			// tempEndRowInGrid = mSimulatedImageGrid_blue[counter].size().height;
			tempEndRow = mImageSharp_blue.size().height;

			deltaRow = tempEndRow - tempStartRow;
			tempEndRowInGrid = tempStartRowInGrid + deltaRow;
		}

	}

}




void WienerDeconvolution::saveAllSharpImageParts_blue(std::string /*locaion*/ location)
{
	unsigned int size = mImageParts_blue.size();
	std::string nameBlue = "blue_";
	std::string tempNumInt{};
	std::string tempNameBlue{};

	for (unsigned int i = 0; i < size; ++i)
	{
		tempNameBlue = nameBlue;
		tempNumInt = std::to_string(i);
		tempNameBlue = tempNameBlue + tempNumInt;

		Images::saveImage_normalized(location, tempNameBlue, "png", mImagePartsSharp_blue[i]);

	}

}

void WienerDeconvolution::saveAllSharpImageParts_green(std::string /*locaion*/ location)
{
	unsigned int size = mImageParts_green.size();
	std::string nameGreen = "green_";
	std::string tempNumInt{};
	std::string tempNameGreen{};

	for (unsigned int i = 0; i < size; ++i)
	{
		tempNameGreen = nameGreen;
		tempNumInt = std::to_string(i);
		tempNameGreen = tempNameGreen + tempNumInt;

		Images::saveImage_normalized(location, tempNameGreen, "png", mImagePartsSharp_green[i]);

	}

}

void WienerDeconvolution::saveAllSharpImageParts_red(std::string /*locaion*/ location)
{
	unsigned int size = mImageParts_red.size();
	std::string nameRed = "red_";
	std::string tempNumInt{};
	std::string tempNameRed{};

	for (unsigned int i = 0; i < size; ++i)
	{
		tempNameRed = nameRed;
		tempNumInt = std::to_string(i);
		tempNameRed = tempNameRed + tempNumInt;

		Images::saveImage_normalized(location, tempNameRed, "png", mImagePartsSharp_red[i]);

	}

}

cv::Mat WienerDeconvolution::getFinalSharpImage_initialSize()
{
	return mSharpImageFinal_BGR_64_initialSize;
}

