#include "WienerDeconvolutionSuperFunctionParallel.h"

// often use
#include "..\oftenUseNamespace\oftenUseNamespace.h"

// sharpness evaluation
#include "..\Image\SharpnessEvaluation.h"

// images
#include "..\Image\Images.h"

// open mp
#include <omp.h>

// *** for BGR images prarallel
WienerDeconvolutionSF_parallel_BGR::WienerDeconvolutionSF_parallel_BGR() {}
WienerDeconvolutionSF_parallel_BGR::~WienerDeconvolutionSF_parallel_BGR() {}

// ***


// *** for gray image 
WienerDeconvolutionSF_parallel_Gray::WienerDeconvolutionSF_parallel_Gray() {};
WienerDeconvolutionSF_parallel_Gray::~WienerDeconvolutionSF_parallel_Gray() {};
// load basic parameter
	// set basic parameter
void WienerDeconvolutionSF_parallel_Gray::setBasicParameter(parameterImaImprove_WD paraWD_parallel)
{
	mParaImaImproveWD_gray_global = paraWD_parallel;
}
// improve image quality 
void WienerDeconvolutionSF_parallel_Gray::improveImaQual_WD_superFct_gray_parallel(const cv::Mat sharpGrayImage, const cv::Mat blueredGrayImage)
{
	mSharpGrayImage = sharpGrayImage;
	mBlueredGrayImages = blueredGrayImage;
	// initial parameter for difference cores
	initializePrameterDifCores();
	// optimize image quality on difference cores
	improveImaQual_WD_superFct_gray_parallel();
	// find best parameter
	findBestParameterAllCores();
}
// initialize parameter for difference cores
void WienerDeconvolutionSF_parallel_Gray::initializePrameterDifCores()
{
	int kernelSizeHeightAndWidth = mParaImaImproveWD_gray_global.getKernelSizeHeightAndWidth();
	real compareInPercent = mParaImaImproveWD_gray_global.getCompareInPercent();

	// set kernel size height and width
	mParaImaImproveWD_gray_Core1.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_gray_Core2.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_gray_Core3.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_gray_Core4.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_gray_Core5.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_gray_Core6.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_gray_Core7.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_gray_Core8.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);

	mParaImaImproveWD_gray_Core1.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_gray_Core2.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_gray_Core3.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_gray_Core4.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_gray_Core5.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_gray_Core6.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_gray_Core7.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_gray_Core8.setCompareInPercent(compareInPercent);

	// numer of cores
	int numberCores = 8;

	// sigma
	real minSigmaGlobal = mParaImaImproveWD_gray_global.getMinSigmaXY();
	real maxSigmaGlobal = mParaImaImproveWD_gray_global.getMaxSigmaXY();

	real stepsPerCoreSigma = mParaImaImproveWD_gray_global.getStepsSigmaXY() / numberCores;

	mParaImaImproveWD_gray_Core1.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_gray_Core2.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_gray_Core3.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_gray_Core4.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_gray_Core5.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_gray_Core6.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_gray_Core7.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_gray_Core8.setStepsSigmaXY(stepsPerCoreSigma);

	// SNR
	real minSNR_Global = mParaImaImproveWD_gray_global.getMinSNR();
	real maxSNR_Global = mParaImaImproveWD_gray_global.getMaxSNR();

	real stepsPerCoreSNR = mParaImaImproveWD_gray_global.getStepsSNR() / numberCores;

	mParaImaImproveWD_gray_Core1.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_gray_Core2.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_gray_Core3.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_gray_Core4.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_gray_Core5.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_gray_Core6.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_gray_Core7.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_gray_Core8.setStepsSNR(stepsPerCoreSNR);


	//calc diff sigma per core
	real deltaSigmaGloal = (mParaImaImproveWD_gray_global.getMaxSigmaXY() - mParaImaImproveWD_gray_global.getMinSigmaXY()) / mParaImaImproveWD_gray_global.getStepsSigmaXY();
	real diffPerCoreSigma = deltaSigmaGloal * stepsPerCoreSigma;

	real minSigmaCore_1 = minSigmaGlobal;
	real maxSigmaCore_1 = minSigmaCore_1 + diffPerCoreSigma;
	real minSigmaCore_2 = maxSigmaCore_1;
	real maxSigmaCore_2 = minSigmaCore_2 + diffPerCoreSigma;
	real minSigmaCore_3 = maxSigmaCore_2;
	real maxSigmaCore_3 = minSigmaCore_3 + diffPerCoreSigma;
	real minSigmaCore_4 = maxSigmaCore_3;
	real maxSigmaCore_4 = minSigmaCore_4 + diffPerCoreSigma;
	real minSigmaCore_5 = maxSigmaCore_4;
	real maxSigmaCore_5 = minSigmaCore_5 + diffPerCoreSigma;
	real minSigmaCore_6 = maxSigmaCore_5;
	real maxSigmaCore_6 = minSigmaCore_6 + diffPerCoreSigma;
	real minSigmaCore_7 = maxSigmaCore_6;
	real maxSigmaCore_7 = minSigmaCore_7 + diffPerCoreSigma;
	real minSigmaCore_8 = maxSigmaCore_7;
	real maxSigmaCore_8 = maxSigmaGlobal;


	mParaImaImproveWD_gray_Core1.setMinSigmaXY(minSigmaCore_1);
	mParaImaImproveWD_gray_Core1.setMaxSigmaXY(maxSigmaCore_1);
	mParaImaImproveWD_gray_Core2.setMinSigmaXY(minSigmaCore_2);
	mParaImaImproveWD_gray_Core2.setMaxSigmaXY(maxSigmaCore_2);
	mParaImaImproveWD_gray_Core3.setMinSigmaXY(minSigmaCore_3);
	mParaImaImproveWD_gray_Core3.setMaxSigmaXY(maxSigmaCore_3);
	mParaImaImproveWD_gray_Core4.setMinSigmaXY(minSigmaCore_4);
	mParaImaImproveWD_gray_Core4.setMaxSigmaXY(maxSigmaCore_4);
	mParaImaImproveWD_gray_Core5.setMinSigmaXY(minSigmaCore_5);
	mParaImaImproveWD_gray_Core5.setMaxSigmaXY(maxSigmaCore_5);
	mParaImaImproveWD_gray_Core6.setMinSigmaXY(minSigmaCore_6);
	mParaImaImproveWD_gray_Core6.setMaxSigmaXY(maxSigmaCore_6);
	mParaImaImproveWD_gray_Core7.setMinSigmaXY(minSigmaCore_7);
	mParaImaImproveWD_gray_Core7.setMaxSigmaXY(maxSigmaCore_7);
	mParaImaImproveWD_gray_Core8.setMinSigmaXY(minSigmaCore_8);
	mParaImaImproveWD_gray_Core8.setMaxSigmaXY(maxSigmaCore_8);


	//calc diff SNR per core
	real deltaSNR_Gloal = (mParaImaImproveWD_gray_global.getMaxSNR() - mParaImaImproveWD_gray_global.getMinSNR()) / mParaImaImproveWD_gray_global.getStepsSNR();
	real diffPerCoreSNR = deltaSNR_Gloal * stepsPerCoreSNR;

	real minSNR_Core_1 = minSNR_Global;
	real maxSNR_Core_1 = minSNR_Core_1 + diffPerCoreSNR;
	real minSNR_Core_2 = maxSNR_Core_1;
	real maxSNR_Core_2 = minSNR_Core_2 + diffPerCoreSNR;
	real minSNR_Core_3 = maxSNR_Core_2;
	real maxSNR_Core_3 = minSNR_Core_3 + diffPerCoreSNR;
	real minSNR_Core_4 = maxSNR_Core_3;
	real maxSNR_Core_4 = minSNR_Core_4 + diffPerCoreSNR;
	real minSNR_Core_5 = maxSNR_Core_4;
	real maxSNR_Core_5 = minSNR_Core_5 + diffPerCoreSNR;
	real minSNR_Core_6 = maxSNR_Core_5;
	real maxSNR_Core_6 = minSNR_Core_6 + diffPerCoreSNR;
	real minSNR_Core_7 = maxSNR_Core_6;
	real maxSNR_Core_7 = minSNR_Core_7 + diffPerCoreSNR;
	real minSNR_Core_8 = maxSNR_Core_7;
	real maxSNR_Core_8 = maxSNR_Global;

	mParaImaImproveWD_gray_Core1.setMinSNR(minSNR_Core_1);
	mParaImaImproveWD_gray_Core1.setMaxSNR(maxSNR_Core_1);
	mParaImaImproveWD_gray_Core2.setMinSNR(minSNR_Core_2);
	mParaImaImproveWD_gray_Core2.setMaxSNR(maxSNR_Core_2);
	mParaImaImproveWD_gray_Core3.setMinSNR(minSNR_Core_3);
	mParaImaImproveWD_gray_Core3.setMaxSNR(maxSNR_Core_3);
	mParaImaImproveWD_gray_Core4.setMinSNR(minSNR_Core_4);
	mParaImaImproveWD_gray_Core4.setMaxSNR(maxSNR_Core_4);
	mParaImaImproveWD_gray_Core5.setMinSNR(minSNR_Core_5);
	mParaImaImproveWD_gray_Core5.setMaxSNR(maxSNR_Core_5);
	mParaImaImproveWD_gray_Core6.setMinSNR(minSNR_Core_6);
	mParaImaImproveWD_gray_Core6.setMaxSNR(maxSNR_Core_6);
	mParaImaImproveWD_gray_Core7.setMinSNR(minSNR_Core_7);
	mParaImaImproveWD_gray_Core7.setMaxSNR(maxSNR_Core_7);
	mParaImaImproveWD_gray_Core8.setMinSNR(minSNR_Core_8);
	mParaImaImproveWD_gray_Core8.setMaxSNR(maxSNR_Core_8);

	mWienderDeconSF_Gray_Core1.setBasicParameter(mParaImaImproveWD_gray_Core1);
	mWienderDeconSF_Gray_Core2.setBasicParameter(mParaImaImproveWD_gray_Core2);
	mWienderDeconSF_Gray_Core3.setBasicParameter(mParaImaImproveWD_gray_Core3);
	mWienderDeconSF_Gray_Core4.setBasicParameter(mParaImaImproveWD_gray_Core4);
	mWienderDeconSF_Gray_Core5.setBasicParameter(mParaImaImproveWD_gray_Core5);
	mWienderDeconSF_Gray_Core6.setBasicParameter(mParaImaImproveWD_gray_Core6);
	mWienderDeconSF_Gray_Core7.setBasicParameter(mParaImaImproveWD_gray_Core7);
	mWienderDeconSF_Gray_Core8.setBasicParameter(mParaImaImproveWD_gray_Core8);

}
// optimize image quality on difference cores
void WienerDeconvolutionSF_parallel_Gray::improveImaQual_WD_superFct_gray_parallel()
{

	mImprovements_vec.resize(8);
	mSaveAllBestParameters.resize(8);

	#pragma omp parallel
	{
		#pragma omp sections
		{
			#pragma omp section // 1
			{
				mWienderDeconSF_Gray_Core1.improveImaQual_WD_superFct_gray(mSharpGrayImage, mBlueredGrayImages);
				real impCore1 = mWienderDeconSF_Gray_Core1.getBestParameter().getImprovement();
				mImprovements_vec[0] = impCore1;
				mSaveAllBestParameters[0] = mWienderDeconSF_Gray_Core1.getBestParameter();
			}
			#pragma omp section // 2
			{
				mWienderDeconSF_Gray_Core2.improveImaQual_WD_superFct_gray(mSharpGrayImage, mBlueredGrayImages);
				real impCore2 = mWienderDeconSF_Gray_Core2.getBestParameter().getImprovement();
				mImprovements_vec[1] = impCore2;
				mSaveAllBestParameters[1] = mWienderDeconSF_Gray_Core2.getBestParameter();
			}
			#pragma omp section // 3
			{
				mWienderDeconSF_Gray_Core3.improveImaQual_WD_superFct_gray(mSharpGrayImage, mBlueredGrayImages);
				real impCore3 = mWienderDeconSF_Gray_Core3.getBestParameter().getImprovement();
				mImprovements_vec[2] = impCore3;
				mSaveAllBestParameters[2] = mWienderDeconSF_Gray_Core3.getBestParameter();
			}
			#pragma omp section // 4
			{
				mWienderDeconSF_Gray_Core4.improveImaQual_WD_superFct_gray(mSharpGrayImage, mBlueredGrayImages);
				real impCore4 = mWienderDeconSF_Gray_Core4.getBestParameter().getImprovement();
				mImprovements_vec[3] = impCore4;
				mSaveAllBestParameters[3] = mWienderDeconSF_Gray_Core4.getBestParameter();
			}
			#pragma omp section // 5
			{
				mWienderDeconSF_Gray_Core5.improveImaQual_WD_superFct_gray(mSharpGrayImage, mBlueredGrayImages);
				real impCore5 = mWienderDeconSF_Gray_Core5.getBestParameter().getImprovement();
				mImprovements_vec[4] = impCore5;
				mSaveAllBestParameters[4] = mWienderDeconSF_Gray_Core5.getBestParameter();
			}
			#pragma omp section // 6
			{
				mWienderDeconSF_Gray_Core6.improveImaQual_WD_superFct_gray(mSharpGrayImage, mBlueredGrayImages);
				real impCore6 = mWienderDeconSF_Gray_Core6.getBestParameter().getImprovement();
				mImprovements_vec[5] = impCore6;
				mSaveAllBestParameters[5] = mWienderDeconSF_Gray_Core6.getBestParameter();
			}
			#pragma omp section // 7
			{
				mWienderDeconSF_Gray_Core7.improveImaQual_WD_superFct_gray(mSharpGrayImage, mBlueredGrayImages);
				real impCore7 = mWienderDeconSF_Gray_Core7.getBestParameter().getImprovement();
				mImprovements_vec[6] = impCore7;
				mSaveAllBestParameters[6] = mWienderDeconSF_Gray_Core7.getBestParameter();
			}
			#pragma omp section // 8
			{
				mWienderDeconSF_Gray_Core8.improveImaQual_WD_superFct_gray(mSharpGrayImage, mBlueredGrayImages);
				real impCore8 = mWienderDeconSF_Gray_Core8.getBestParameter().getImprovement();
				mImprovements_vec[7] = impCore8;
				mSaveAllBestParameters[7] = mWienderDeconSF_Gray_Core8.getBestParameter();
			}
		}
	}
}

// find best parameter
void WienerDeconvolutionSF_parallel_Gray::findBestParameterAllCores()
{
	// find best improvement
	real bestImprovement = mWienderDeconSF_Gray_Core1.getBestParameter().getImprovement();
	real tempImp;
	unsigned int tempBestPosInVec = 0;

	for (unsigned int i = 1; i < mImprovements_vec.size(); ++i)
	{
		tempImp = mImprovements_vec[i];
		if (tempImp > bestImprovement)
		{
			bestImprovement = tempImp;
			tempBestPosInVec = i;
		}
	}

	mBestParameterAllCores = mSaveAllBestParameters[tempBestPosInVec];
}

// get paramter for image processing
parameterImaImprove_WD WienerDeconvolutionSF_parallel_Gray::getParamerterImaImorove()
{
	return mParaImaImproveWD_gray_global;
}

// get best SNR and simga
saveBestParameterWD WienerDeconvolutionSF_parallel_Gray::getBestParameter()
{
	return mBestParameterAllCores;
}

// ***


// *** for gray images
WienerDeconvolutionSF_Gray::WienerDeconvolutionSF_Gray() {};
WienerDeconvolutionSF_Gray::~WienerDeconvolutionSF_Gray() {};
void WienerDeconvolutionSF_Gray::loadBasicParameterBGR()
{
	mParaImaImproveWD_gray.setMinSNR(1.0);
	mParaImaImproveWD_gray.setMaxSNR(100.0);
	mParaImaImproveWD_gray.setStepsSNR(1.0);
	mParaImaImproveWD_gray.setMinSigmaXY(1.0);
	mParaImaImproveWD_gray.setMaxSigmaXY(5.0);
	mParaImaImproveWD_gray.setStepsSigmaXY(0.5);
	mParaImaImproveWD_gray.setKernelSizeHeightAndWidth(30);
	mParaImaImproveWD_gray.setCompareInPercent(7.0);
}
// set basic parameter
void WienerDeconvolutionSF_Gray::setBasicParameter(parameterImaImprove_WD paraWD_parallel)
{
	mParaImaImproveWD_gray = paraWD_parallel;
}
// improve image quality 
void WienerDeconvolutionSF_Gray::improveImaQual_WD_superFct_gray(const cv::Mat sharpGrayImage, const cv::Mat blueredGrayImage)
{
	mSharpGrayImage = sharpGrayImage.clone();
	mBlueredGrayImages = blueredGrayImage.clone();
	cv::Size kernelSize(mParaImaImproveWD_gray.getKernelSizeHeightAndWidth(), mParaImaImproveWD_gray.getKernelSizeHeightAndWidth());
	mGaussKernel = cv::Mat::zeros(kernelSize, CV_64F);
	// check size sharp and bluered image
	checkSizeSharpAndBlueredImage();
	// norm the sharp and bluered image
	normeSharpAndBlueredImage();
	// calc roi to calc dif
	calcROI_toCalcDif();
	// find best psf blue
	findBestSNRandPSF();


}
// check size sharp and bluered image
void WienerDeconvolutionSF_Gray::checkSizeSharpAndBlueredImage()
{
	if (mSharpGrayImage.size() != mBlueredGrayImages.size())
	{
		cv::resize(mBlueredGrayImages, mBlueredGrayImages, mSharpGrayImage.size(), cv::INTER_LANCZOS4);
	}
}
// norm sharp and bluered image
void WienerDeconvolutionSF_Gray::normeSharpAndBlueredImage()
{
	cv::normalize(mSharpGrayImage, mSharpGrayImage, 0, 255, cv::NORM_MINMAX, CV_8UC1);
	cv::normalize(mBlueredGrayImages, mBlueredGrayImages, 0, 255, cv::NORM_MINMAX, CV_8UC1);
}
// calc roi to calc dif
void WienerDeconvolutionSF_Gray::calcROI_toCalcDif()
{
	unsigned int height = mSharpGrayImage.size().height;
	unsigned int width = mSharpGrayImage.size().width;

	unsigned int startX = mParaImaImproveWD_gray.getCompareInPercent() * width / 100.0;
	unsigned int startY = mParaImaImproveWD_gray.getCompareInPercent() * height / 100.0;
	unsigned int heighttROI = height - 2 * startY;
	unsigned int widthROI = width - 2 * startX;

	mRoiToCalcDif.x = startX;
	mRoiToCalcDif.y = startY;
	mRoiToCalcDif.width = widthROI;
	mRoiToCalcDif.height = heighttROI;
}
// build PSF
void WienerDeconvolutionSF_Gray::buildPSF(real sigmaXY, cv::Mat& psf)
{
	// build gaussian kernel
	buildGaussianKernel(sigmaXY);

	cv::Scalar summa = cv::sum(mGaussKernel);
	mGaussKernel = mGaussKernel / summa[0];

	cv::Size sizeGaussKernel = mGaussKernel.size();
	cv::Size sizePSF = psf.size();

	int startHeight = (sizePSF.height - sizeGaussKernel.height) / 2;
	int endHeigt = (sizePSF.height + sizeGaussKernel.height) / 2;
	int startWidth = (sizePSF.width - sizeGaussKernel.width) / 2;
	int endWidth = (sizePSF.width + sizeGaussKernel.width) / 2;

	mGaussKernel.copyTo(psf(cv::Range(startHeight, endHeigt), cv::Range(startWidth, endWidth)));

	// debug
	//Images::showImage_inputReal_normTheImage("psf_blue", psf);
}

void WienerDeconvolutionSF_Gray::buildGaussianKernel(real sigmaXY)
{
	real meanj = (mGaussKernel.rows - 1) / 2,
		meani = (mGaussKernel.cols - 1) / 2,

		temp = 0;

	real sigma = 2 * sigmaXY * sigmaXY;
	for (unsigned int j = 0; j < mGaussKernel.rows; j++)
	{
		for (unsigned int i = 0; i < mGaussKernel.cols; i++)
		{
			temp = std::exp(-((j - meanj) * (j - meanj) + (i - meani) * (i - meani)) / (sigma));

			mGaussKernel.at<real>(j, i) = temp;

		}
	}


	// debug
	//Images::showImage_inputReal_normTheImage("kernel", kernel);

}
// calc wiener filter
void WienerDeconvolutionSF_Gray::calcWnrFilter_CV(const cv::Mat& input_h_PSF, cv::Mat& output_G, double nsr)
{
	mH_PSF_shifted;
	fftshift_CV(input_h_PSF, mH_PSF_shifted);
	cv::Mat planes[2] = { cv::Mat_<real>(mH_PSF_shifted.clone()), cv::Mat::zeros(mH_PSF_shifted.size(), CV_64F) };

	cv::merge(planes, 2, mComplexI_wnrFilter);
	cv::dft(mComplexI_wnrFilter, mComplexI_wnrFilter);
	cv::split(mComplexI_wnrFilter, planes);

	cv::pow(abs(planes[0]), 2, mDenom);
	mDenom += nsr;
	divide(planes[0], mDenom, output_G);
}
// do wiener filtering
void WienerDeconvolutionSF_Gray::filter2DFreq_CV(const cv::Mat& inputImg, cv::Mat& outputImg, const cv::Mat& H)
{
	cv::Mat planes[2] = { cv::Mat_<real>(inputImg.clone()), cv::Mat::zeros(inputImg.size(), CV_64F) };
	mComplexI_filter2DFreq;
	merge(planes, 2, mComplexI_filter2DFreq);
	cv::dft(mComplexI_filter2DFreq, mComplexI_filter2DFreq, cv::DFT_SCALE);
	cv::Mat planesH[2] = { cv::Mat_<real>(H.clone()), cv::Mat::zeros(H.size(), CV_64F) };
	complexH_filter2DFreq;
	cv::merge(planesH, 2, complexH_filter2DFreq);
	complexIH_filter2DFreq;
	cv::mulSpectrums(mComplexI_filter2DFreq, complexH_filter2DFreq, complexIH_filter2DFreq, 0);
	cv::idft(complexIH_filter2DFreq, complexIH_filter2DFreq);
	cv::split(complexIH_filter2DFreq, planes);
	outputImg = planes[0];
}
// fft shift
void WienerDeconvolutionSF_Gray::fftshift_CV(const cv::Mat& inputImg, cv::Mat& outputImg)
{
	outputImg = inputImg.clone();
	int cx = outputImg.cols / 2;
	int cy = outputImg.rows / 2;
	cv::Mat q0(outputImg, cv::Rect(0, 0, cx, cy));
	cv::Mat q1(outputImg, cv::Rect(cx, 0, cx, cy));
	cv::Mat q2(outputImg, cv::Rect(0, cy, cx, cy));
	cv::Mat q3(outputImg, cv::Rect(cx, cy, cx, cy));

	q0.copyTo(mTmp_fftshift);
	q3.copyTo(q0);
	mTmp_fftshift.copyTo(q3);
	q1.copyTo(mTmp_fftshift);
	q2.copyTo(q1);
	mTmp_fftshift.copyTo(q2);
}
// calc difference gray image
int WienerDeconvolutionSF_Gray::calcAbsDifGrayImage_uni8(const cv::Mat& sharpIma, const cv::Mat& filterdIma)
{
	cv::absdiff(sharpIma(mRoiToCalcDif), filterdIma(mRoiToCalcDif), mTempDifMat);
	return cv::sum(mTempDifMat)[0];
}
// calculate improvement
real WienerDeconvolutionSF_Gray::calculateImprovement(const cv::Mat& sharpIma, const cv::Mat& blueredIma, const cv::Mat& filteredIma)
{
	real differenceBluered = calcAbsDifGrayImage_uni8(sharpIma, blueredIma);
	real differenceFilteredIma = calcAbsDifGrayImage_uni8(sharpIma, filteredIma);

	real returnVariance = differenceBluered / differenceFilteredIma;

	return returnVariance;
}
// get best parameter
saveBestParameterWD WienerDeconvolutionSF_Gray::getBestParameter()
{
	return mBestParameter;
}
// get Parameter
parameterImaImprove_WD WienerDeconvolutionSF_Gray::getParameter()
{
	return mParaImaImproveWD_gray;
}
// find best psf and SNR
void WienerDeconvolutionSF_Gray::findBestSNRandPSF()
{

	SharpnessEvaluation SharpEval;
	real tempSNR = mParaImaImproveWD_gray.getMinSNR();
	real deltaSNR = (mParaImaImproveWD_gray.getMaxSNR() - mParaImaImproveWD_gray.getMinSNR()) / mParaImaImproveWD_gray.getStepsSNR();
	real tempDifference = oftenUse::getInfReal();
	real tempBestDifference = oftenUse::getInfReal();
	real tempSharpness = -1.0 * oftenUse::getInfReal();
	real tempBestSharpness = -1.0 * oftenUse::getInfReal();
	real tempImprovement = - 1.0 * oftenUse::getInfReal();
	real tempBestImprovement = - 1.0 * oftenUse::getInfReal();

	real tempSigmaXY = mParaImaImproveWD_gray.getMinSigmaXY();
	real deltaSigmaXY = (mParaImaImproveWD_gray.getMaxSigmaXY() - mParaImaImproveWD_gray.getMinSigmaXY()) / mParaImaImproveWD_gray.getStepsSigmaXY();
	int tempKernelSizeHeightAndWidth_blue = mParaImaImproveWD_gray.getKernelSizeHeightAndWidth();
	cv::Size tempKernelSize_blue(tempKernelSizeHeightAndWidth_blue, tempKernelSizeHeightAndWidth_blue);
	cv::Size sizeSharpIma_blue = mSharpGrayImage.size();
	int counter_blue = 0;
	cv::Rect roi = cv::Rect(0, 0, mSharpGrayImage.cols & -2, mSharpGrayImage.rows & -2);

	//normImaByROI_in8U_out8U(mImageSharp_blue);

	while (tempSigmaXY <= mParaImaImproveWD_gray.getMaxSigmaXY())
	{
		// quess for PSF
		mPSF = cv::Mat::zeros(roi.size(), CV_64F);
		buildPSF(tempSigmaXY, mPSF);

		while (tempSNR <= mParaImaImproveWD_gray.getMaxSNR())
		{
			// calculate wiener filter
			calcWnrFilter_CV(mPSF, mWienerFilter, 1.0 / tempSNR);

			// do wiener deconvolution
			filter2DFreq_CV(mBlueredGrayImages(roi), mFilterResultIma, mWienerFilter);

			// norm filterd image
			mFilterResultIma.convertTo(mFilterResultIma, CV_8UC1);
			cv::normalize(mFilterResultIma, mFilterResultIma, 0.0, 255.0, cv::NORM_MINMAX, CV_8UC1);
			//std::string type = Images::getTypeImageC_VMat(mFilterResultIma_blue);
			//normImaByROI_in64_out8U(mFilterResultIma_blue);

			// debug
			//int first = mFilterResultIma_blue.at<uchar>(10, 10);
			//int sec = mFilterResultIma_blue.at<uchar>(23, 24);
			//int affe = mFilterResultIma_blue.at<uchar>(60, 30);

			tempImprovement = Images::calcImprovementGray(mSharpGrayImage, mBlueredGrayImages, mFilterResultIma, mParaImaImproveWD_gray.getCompareInPercent());

			if (mParaImaImproveWD_gray.getSharpnessEvalMethode() == sharpnessEvalMethode::sharpImage)
			{

				if (tempImprovement > tempBestImprovement)
				{
					tempBestImprovement = tempImprovement;

					// calculate difference sharp and filterd image
					tempDifference = calcAbsDifGrayImage_uni8(mSharpGrayImage, mFilterResultIma);
					
					mBestParameter.setBestFilter(mWienerFilter.clone());
					mBestParameter.setBestReconstruction(mFilterResultIma.clone());
					mBestParameter.setBestPSF(mPSF.clone());
					mBestParameter.setBestSigma(tempSigmaXY);
					mBestParameter.setBestSNR(tempSNR);
					mBestParameter.setDifference(tempDifference);
					//// debug
					//std::string typeSharpIma = Images::getTypeImageC_VMat(mImageSharp_blue);
					//std::string typeBlueredIma = Images::getTypeImageC_VMat(mBluredIma_blue);
					//std::string typeFilteredIma = Images::getTypeImageC_VMat(mFilterResultIma_blue);

					//////// debug
					//Images::showImage_inputUint8("sharpIma", mImageSharp_blue);
					//Images::showImage_inputUint8("filtered mage", mFilterResultIma_blue);

					// debug
					// std::cout << "improvement: " << improvement << std::endl;
					mBestParameter.setImprovement(tempImprovement);

					//if (improvement_blue > 1)
					//{
					//	// debug -> save temp best filtered image
					//	std::string locationTest7 = "../tests/testImproveImageQuality/WienerDeconvolution/s7";
					//	std::string numberString = std::to_string(counter_blue);
					//	std::string nameNum = "blue_" + numberString;
					//	Images::saveImageGray_UN8_normByROI_percent(locationTest7, nameNum, "png", mFilterResultIma_blue, mParaImaImproveWD_blue.getCompareInPercent());
					//	++counter_blue;
					//}

				}
			}
			
			else if(mParaImaImproveWD_gray.getSharpnessEvalMethode() != sharpnessEvalMethode::sharpImage)
			{
				tempSharpness = SharpEval.calculateSharpness_superFct(mParaImaImproveWD_gray.getSharpnessEvalMethode(), mFilterResultIma.clone());

				if (tempSharpness > tempBestSharpness)
				{
					tempBestSharpness = tempSharpness;

					mBestParameter.setBestFilter(mWienerFilter.clone());
					mBestParameter.setBestReconstruction(mFilterResultIma.clone());
					mBestParameter.setBestPSF(mPSF.clone());
					mBestParameter.setBestSigma(tempSigmaXY);
					mBestParameter.setBestSNR(tempSNR);

					tempDifference = calcAbsDifGrayImage_uni8(mSharpGrayImage, mFilterResultIma);
					mBestParameter.setDifference(tempDifference);
					//// debug
					//std::string typeSharpIma = Images::getTypeImageC_VMat(mImageSharp_blue);
					//std::string typeBlueredIma = Images::getTypeImageC_VMat(mBluredIma_blue);
					//std::string typeFilteredIma = Images::getTypeImageC_VMat(mFilterResultIma_blue);

					//////// debug
					//Images::showImage_inputUint8("sharpIma", mImageSharp_blue);
					//Images::showImage_inputUint8("filtered mage", mFilterResultIma_blue);

	
					// debug
					// std::cout << "improvement: " << improvement << std::endl;
					mBestParameter.setImprovement(tempImprovement);
					
					// sharpness
					mBestParameter.setSharpness(tempSharpness);
				}
			}

			tempSNR = tempSNR + deltaSNR;
		}

		tempSNR = mParaImaImproveWD_gray.getMinSNR();
		tempSigmaXY = tempSigmaXY + deltaSigmaXY;

	}

	// check improvement
	if (mParaImaImproveWD_gray.getSharpnessEvalMethode() == sharpnessEvalMethode::sharpImage)
	{
		if (mBestParameter.getImprovement() <= 1.0)
		{
			mBestParameter.setBestReconstruction(mBlueredGrayImages.clone());
			mBestParameter.setImprovement(1.0);
		}
	}


}
// ***

void WienerDeconvolutionSF_parallel_BGR::setParameterWD_Global_blue(parameterImaImprove_WD para_blue)
{
	mParaImaImproveWD_blue_global = para_blue;
}
void WienerDeconvolutionSF_parallel_BGR::setParameterWD_Global_green(parameterImaImprove_WD para_green)
{
	mParaImaImproveWD_green_global = para_green;
}
void WienerDeconvolutionSF_parallel_BGR::setParameterWD_Global_red(parameterImaImprove_WD para_red)
{
	mParaImaImproveWD_red_global = para_red;
}

void WienerDeconvolutionSF_parallel_BGR::initializePrameterDifCores_blue()
{
	int kernelSizeHeightAndWidth = mParaImaImproveWD_blue_global.getKernelSizeHeightAndWidth();
	real compareInPercent = mParaImaImproveWD_blue_global.getCompareInPercent();
	sharpnessEvalMethode sharpEvalMeth = mParaImaImproveWD_blue_global.getSharpnessEvalMethode();

	// set kernel size height and width
	mParaImaImproveWD_blue_Core1.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_blue_Core2.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_blue_Core3.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_blue_Core4.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_blue_Core5.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_blue_Core6.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_blue_Core7.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_blue_Core8.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);

	// set compare in percent
	mParaImaImproveWD_blue_Core1.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_blue_Core2.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_blue_Core3.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_blue_Core4.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_blue_Core5.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_blue_Core6.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_blue_Core7.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_blue_Core8.setCompareInPercent(compareInPercent);

	// sharpness evaluation methode
	mParaImaImproveWD_blue_Core1.setSharpnessEvalMethode(sharpEvalMeth);
	mParaImaImproveWD_blue_Core2.setSharpnessEvalMethode(sharpEvalMeth);
	mParaImaImproveWD_blue_Core3.setSharpnessEvalMethode(sharpEvalMeth);
	mParaImaImproveWD_blue_Core4.setSharpnessEvalMethode(sharpEvalMeth);
	mParaImaImproveWD_blue_Core5.setSharpnessEvalMethode(sharpEvalMeth);
	mParaImaImproveWD_blue_Core6.setSharpnessEvalMethode(sharpEvalMeth);
	mParaImaImproveWD_blue_Core7.setSharpnessEvalMethode(sharpEvalMeth);
	mParaImaImproveWD_blue_Core8.setSharpnessEvalMethode(sharpEvalMeth);

	// numer of cores
	int numberCores = 8;

	// sigma
	real minSigmaGlobal = mParaImaImproveWD_blue_global.getMinSigmaXY();
	real maxSigmaGlobal = mParaImaImproveWD_blue_global.getMaxSigmaXY();

	real stepsPerCoreSigma = mParaImaImproveWD_blue_global.getStepsSigmaXY() / numberCores;

	mParaImaImproveWD_blue_Core1.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_blue_Core2.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_blue_Core3.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_blue_Core4.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_blue_Core5.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_blue_Core6.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_blue_Core7.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_blue_Core8.setStepsSigmaXY(stepsPerCoreSigma);

	// SNR
	real minSNR_Global = mParaImaImproveWD_blue_global.getMinSNR();
	real maxSNR_Global = mParaImaImproveWD_blue_global.getMaxSNR();

	real stepsPerCoreSNR = mParaImaImproveWD_blue_global.getStepsSNR() / numberCores;

	mParaImaImproveWD_blue_Core1.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_blue_Core2.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_blue_Core3.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_blue_Core4.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_blue_Core5.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_blue_Core6.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_blue_Core7.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_blue_Core8.setStepsSNR(stepsPerCoreSNR);


	//calc diff sigma per core
	real deltaSigmaGloal = (mParaImaImproveWD_blue_global.getMaxSigmaXY() - mParaImaImproveWD_blue_global.getMinSigmaXY()) / mParaImaImproveWD_blue_global.getStepsSigmaXY();
	real diffPerCoreSigma = deltaSigmaGloal * stepsPerCoreSigma;

	real minSigmaCore_1 = minSigmaGlobal;
	real maxSigmaCore_1 = minSigmaCore_1 + diffPerCoreSigma;
	real minSigmaCore_2 = maxSigmaCore_1;
	real maxSigmaCore_2 = minSigmaCore_2 + diffPerCoreSigma;
	real minSigmaCore_3 = maxSigmaCore_2;
	real maxSigmaCore_3 = minSigmaCore_3 + diffPerCoreSigma;
	real minSigmaCore_4 = maxSigmaCore_3;
	real maxSigmaCore_4 = minSigmaCore_4 + diffPerCoreSigma;
	real minSigmaCore_5 = maxSigmaCore_4;
	real maxSigmaCore_5 = minSigmaCore_5 + diffPerCoreSigma;
	real minSigmaCore_6 = maxSigmaCore_5;
	real maxSigmaCore_6 = minSigmaCore_6 + diffPerCoreSigma;
	real minSigmaCore_7 = maxSigmaCore_6;
	real maxSigmaCore_7 = minSigmaCore_7 + diffPerCoreSigma;
	real minSigmaCore_8 = maxSigmaCore_7;
	real maxSigmaCore_8 = maxSigmaGlobal;


	mParaImaImproveWD_blue_Core1.setMinSigmaXY(minSigmaCore_1);
	mParaImaImproveWD_blue_Core1.setMaxSigmaXY(maxSigmaCore_1);
	mParaImaImproveWD_blue_Core2.setMinSigmaXY(minSigmaCore_2);
	mParaImaImproveWD_blue_Core2.setMaxSigmaXY(maxSigmaCore_2);
	mParaImaImproveWD_blue_Core3.setMinSigmaXY(minSigmaCore_3);
	mParaImaImproveWD_blue_Core3.setMaxSigmaXY(maxSigmaCore_3);
	mParaImaImproveWD_blue_Core4.setMinSigmaXY(minSigmaCore_4);
	mParaImaImproveWD_blue_Core4.setMaxSigmaXY(maxSigmaCore_4);
	mParaImaImproveWD_blue_Core5.setMinSigmaXY(minSigmaCore_5);
	mParaImaImproveWD_blue_Core5.setMaxSigmaXY(maxSigmaCore_5);
	mParaImaImproveWD_blue_Core6.setMinSigmaXY(minSigmaCore_6);
	mParaImaImproveWD_blue_Core6.setMaxSigmaXY(maxSigmaCore_6);
	mParaImaImproveWD_blue_Core7.setMinSigmaXY(minSigmaCore_7);
	mParaImaImproveWD_blue_Core7.setMaxSigmaXY(maxSigmaCore_7);
	mParaImaImproveWD_blue_Core8.setMinSigmaXY(minSigmaCore_8);
	mParaImaImproveWD_blue_Core8.setMaxSigmaXY(maxSigmaCore_8);


	//calc diff SNR per core
	real deltaSNR_Gloal = (mParaImaImproveWD_blue_global.getMaxSNR() - mParaImaImproveWD_blue_global.getMinSNR()) / mParaImaImproveWD_blue_global.getStepsSNR();
	real diffPerCoreSNR = deltaSNR_Gloal * stepsPerCoreSNR;

	real minSNR_Core_1 = minSNR_Global;
	real maxSNR_Core_1 = minSNR_Core_1 + diffPerCoreSNR;
	real minSNR_Core_2 = maxSNR_Core_1;
	real maxSNR_Core_2 = minSNR_Core_2 + diffPerCoreSNR;
	real minSNR_Core_3 = maxSNR_Core_2;
	real maxSNR_Core_3 = minSNR_Core_3 + diffPerCoreSNR;
	real minSNR_Core_4 = maxSNR_Core_3;
	real maxSNR_Core_4 = minSNR_Core_4 + diffPerCoreSNR;
	real minSNR_Core_5 = maxSNR_Core_4;
	real maxSNR_Core_5 = minSNR_Core_5 + diffPerCoreSNR;
	real minSNR_Core_6 = maxSNR_Core_5;
	real maxSNR_Core_6 = minSNR_Core_6 + diffPerCoreSNR;
	real minSNR_Core_7 = maxSNR_Core_6;
	real maxSNR_Core_7 = minSNR_Core_7 + diffPerCoreSNR;
	real minSNR_Core_8 = maxSNR_Core_7;
	real maxSNR_Core_8 = maxSNR_Global;

	mParaImaImproveWD_blue_Core1.setMinSNR(minSNR_Core_1);
	mParaImaImproveWD_blue_Core1.setMaxSNR(maxSNR_Core_1);
	mParaImaImproveWD_blue_Core2.setMinSNR(minSNR_Core_2);
	mParaImaImproveWD_blue_Core2.setMaxSNR(maxSNR_Core_2);
	mParaImaImproveWD_blue_Core3.setMinSNR(minSNR_Core_3);
	mParaImaImproveWD_blue_Core3.setMaxSNR(maxSNR_Core_3);
	mParaImaImproveWD_blue_Core4.setMinSNR(minSNR_Core_4);
	mParaImaImproveWD_blue_Core4.setMaxSNR(maxSNR_Core_4);
	mParaImaImproveWD_blue_Core5.setMinSNR(minSNR_Core_5);
	mParaImaImproveWD_blue_Core5.setMaxSNR(maxSNR_Core_5);
	mParaImaImproveWD_blue_Core6.setMinSNR(minSNR_Core_6);
	mParaImaImproveWD_blue_Core6.setMaxSNR(maxSNR_Core_6);
	mParaImaImproveWD_blue_Core7.setMinSNR(minSNR_Core_7);
	mParaImaImproveWD_blue_Core7.setMaxSNR(maxSNR_Core_7);
	mParaImaImproveWD_blue_Core8.setMinSNR(minSNR_Core_8);
	mParaImaImproveWD_blue_Core8.setMaxSNR(maxSNR_Core_8);



	mWienderDeconSF_blue_Core1.setBasicParameter(mParaImaImproveWD_blue_Core1);
	mWienderDeconSF_blue_Core2.setBasicParameter(mParaImaImproveWD_blue_Core2);
	mWienderDeconSF_blue_Core3.setBasicParameter(mParaImaImproveWD_blue_Core3);
	mWienderDeconSF_blue_Core4.setBasicParameter(mParaImaImproveWD_blue_Core4);
	mWienderDeconSF_blue_Core5.setBasicParameter(mParaImaImproveWD_blue_Core5);
	mWienderDeconSF_blue_Core6.setBasicParameter(mParaImaImproveWD_blue_Core6);
	mWienderDeconSF_blue_Core7.setBasicParameter(mParaImaImproveWD_blue_Core7);
	mWienderDeconSF_blue_Core8.setBasicParameter(mParaImaImproveWD_blue_Core8);


}

void WienerDeconvolutionSF_parallel_BGR::initializePrameterDifCores_green()
{
	int kernelSizeHeightAndWidth = mParaImaImproveWD_green_global.getKernelSizeHeightAndWidth();
	real compareInPercent = mParaImaImproveWD_green_global.getCompareInPercent();
	sharpnessEvalMethode sharpEvalMeth = mParaImaImproveWD_green_global.getSharpnessEvalMethode();

	// set kernel size height and width
	mParaImaImproveWD_green_Core1.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_green_Core2.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_green_Core3.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_green_Core4.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_green_Core5.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_green_Core6.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_green_Core7.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_green_Core8.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);

	mParaImaImproveWD_green_Core1.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_green_Core2.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_green_Core3.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_green_Core4.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_green_Core5.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_green_Core6.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_green_Core7.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_green_Core8.setCompareInPercent(compareInPercent);

	// sharpness evaluation methode
	mParaImaImproveWD_green_Core1.setSharpnessEvalMethode(sharpEvalMeth);
	mParaImaImproveWD_green_Core2.setSharpnessEvalMethode(sharpEvalMeth);
	mParaImaImproveWD_green_Core3.setSharpnessEvalMethode(sharpEvalMeth);
	mParaImaImproveWD_green_Core4.setSharpnessEvalMethode(sharpEvalMeth);
	mParaImaImproveWD_green_Core5.setSharpnessEvalMethode(sharpEvalMeth);
	mParaImaImproveWD_green_Core6.setSharpnessEvalMethode(sharpEvalMeth);
	mParaImaImproveWD_green_Core7.setSharpnessEvalMethode(sharpEvalMeth);
	mParaImaImproveWD_green_Core8.setSharpnessEvalMethode(sharpEvalMeth);

	// numer of cores
	int numberCores = 8;

	// sigma
	real minSigmaGlobal = mParaImaImproveWD_green_global.getMinSigmaXY();
	real maxSigmaGlobal = mParaImaImproveWD_green_global.getMaxSigmaXY();

	real stepsPerCoreSigma = mParaImaImproveWD_green_global.getStepsSigmaXY() / numberCores;

	mParaImaImproveWD_green_Core1.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_green_Core2.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_green_Core3.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_green_Core4.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_green_Core5.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_green_Core6.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_green_Core7.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_green_Core8.setStepsSigmaXY(stepsPerCoreSigma);

	// SNR
	real minSNR_Global = mParaImaImproveWD_green_global.getMinSNR();
	real maxSNR_Global = mParaImaImproveWD_green_global.getMaxSNR();

	real stepsPerCoreSNR = mParaImaImproveWD_green_global.getStepsSNR() / numberCores;

	mParaImaImproveWD_green_Core1.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_green_Core2.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_green_Core3.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_green_Core4.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_green_Core5.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_green_Core6.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_green_Core7.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_green_Core8.setStepsSNR(stepsPerCoreSNR);


	//calc diff sigma per core
	real deltaSigmaGloal = (mParaImaImproveWD_green_global.getMaxSigmaXY() - mParaImaImproveWD_green_global.getMinSigmaXY()) / mParaImaImproveWD_green_global.getStepsSigmaXY();
	real diffPerCoreSigma = deltaSigmaGloal * stepsPerCoreSigma;

	real minSigmaCore_1 = minSigmaGlobal;
	real maxSigmaCore_1 = minSigmaCore_1 + diffPerCoreSigma;
	real minSigmaCore_2 = maxSigmaCore_1;
	real maxSigmaCore_2 = minSigmaCore_2 + diffPerCoreSigma;
	real minSigmaCore_3 = maxSigmaCore_2;
	real maxSigmaCore_3 = minSigmaCore_3 + diffPerCoreSigma;
	real minSigmaCore_4 = maxSigmaCore_3;
	real maxSigmaCore_4 = minSigmaCore_4 + diffPerCoreSigma;
	real minSigmaCore_5 = maxSigmaCore_4;
	real maxSigmaCore_5 = minSigmaCore_5 + diffPerCoreSigma;
	real minSigmaCore_6 = maxSigmaCore_5;
	real maxSigmaCore_6 = minSigmaCore_6 + diffPerCoreSigma;
	real minSigmaCore_7 = maxSigmaCore_6;
	real maxSigmaCore_7 = minSigmaCore_7 + diffPerCoreSigma;
	real minSigmaCore_8 = maxSigmaCore_7;
	real maxSigmaCore_8 = maxSigmaGlobal;


	mParaImaImproveWD_green_Core1.setMinSigmaXY(minSigmaCore_1);
	mParaImaImproveWD_green_Core1.setMaxSigmaXY(maxSigmaCore_1);
	mParaImaImproveWD_green_Core2.setMinSigmaXY(minSigmaCore_2);
	mParaImaImproveWD_green_Core2.setMaxSigmaXY(maxSigmaCore_2);
	mParaImaImproveWD_green_Core3.setMinSigmaXY(minSigmaCore_3);
	mParaImaImproveWD_green_Core3.setMaxSigmaXY(maxSigmaCore_3);
	mParaImaImproveWD_green_Core4.setMinSigmaXY(minSigmaCore_4);
	mParaImaImproveWD_green_Core4.setMaxSigmaXY(maxSigmaCore_4);
	mParaImaImproveWD_green_Core5.setMinSigmaXY(minSigmaCore_5);
	mParaImaImproveWD_green_Core5.setMaxSigmaXY(maxSigmaCore_5);
	mParaImaImproveWD_green_Core6.setMinSigmaXY(minSigmaCore_6);
	mParaImaImproveWD_green_Core6.setMaxSigmaXY(maxSigmaCore_6);
	mParaImaImproveWD_green_Core7.setMinSigmaXY(minSigmaCore_7);
	mParaImaImproveWD_green_Core7.setMaxSigmaXY(maxSigmaCore_7);
	mParaImaImproveWD_green_Core8.setMinSigmaXY(minSigmaCore_8);
	mParaImaImproveWD_green_Core8.setMaxSigmaXY(maxSigmaCore_8);


	//calc diff SNR per core
	real deltaSNR_Gloal = (mParaImaImproveWD_green_global.getMaxSNR() - mParaImaImproveWD_green_global.getMinSNR()) / mParaImaImproveWD_green_global.getStepsSNR();
	real diffPerCoreSNR = deltaSNR_Gloal * stepsPerCoreSNR;

	real minSNR_Core_1 = minSNR_Global;
	real maxSNR_Core_1 = minSNR_Core_1 + diffPerCoreSNR;
	real minSNR_Core_2 = maxSNR_Core_1;
	real maxSNR_Core_2 = minSNR_Core_2 + diffPerCoreSNR;
	real minSNR_Core_3 = maxSNR_Core_2;
	real maxSNR_Core_3 = minSNR_Core_3 + diffPerCoreSNR;
	real minSNR_Core_4 = maxSNR_Core_3;
	real maxSNR_Core_4 = minSNR_Core_4 + diffPerCoreSNR;
	real minSNR_Core_5 = maxSNR_Core_4;
	real maxSNR_Core_5 = minSNR_Core_5 + diffPerCoreSNR;
	real minSNR_Core_6 = maxSNR_Core_5;
	real maxSNR_Core_6 = minSNR_Core_6 + diffPerCoreSNR;
	real minSNR_Core_7 = maxSNR_Core_6;
	real maxSNR_Core_7 = minSNR_Core_7 + diffPerCoreSNR;
	real minSNR_Core_8 = maxSNR_Core_7;
	real maxSNR_Core_8 = maxSNR_Global;

	mParaImaImproveWD_green_Core1.setMinSNR(minSNR_Core_1);
	mParaImaImproveWD_green_Core1.setMaxSNR(maxSNR_Core_1);
	mParaImaImproveWD_green_Core2.setMinSNR(minSNR_Core_2);
	mParaImaImproveWD_green_Core2.setMaxSNR(maxSNR_Core_2);
	mParaImaImproveWD_green_Core3.setMinSNR(minSNR_Core_3);
	mParaImaImproveWD_green_Core3.setMaxSNR(maxSNR_Core_3);
	mParaImaImproveWD_green_Core4.setMinSNR(minSNR_Core_4);
	mParaImaImproveWD_green_Core4.setMaxSNR(maxSNR_Core_4);
	mParaImaImproveWD_green_Core5.setMinSNR(minSNR_Core_5);
	mParaImaImproveWD_green_Core5.setMaxSNR(maxSNR_Core_5);
	mParaImaImproveWD_green_Core6.setMinSNR(minSNR_Core_6);
	mParaImaImproveWD_green_Core6.setMaxSNR(maxSNR_Core_6);
	mParaImaImproveWD_green_Core7.setMinSNR(minSNR_Core_7);
	mParaImaImproveWD_green_Core7.setMaxSNR(maxSNR_Core_7);
	mParaImaImproveWD_green_Core8.setMinSNR(minSNR_Core_8);
	mParaImaImproveWD_green_Core8.setMaxSNR(maxSNR_Core_8);

	mWienderDeconSF_green_Core1.setBasicParameter(mParaImaImproveWD_green_Core1);
	mWienderDeconSF_green_Core2.setBasicParameter(mParaImaImproveWD_green_Core2);
	mWienderDeconSF_green_Core3.setBasicParameter(mParaImaImproveWD_green_Core3);
	mWienderDeconSF_green_Core4.setBasicParameter(mParaImaImproveWD_green_Core4);
	mWienderDeconSF_green_Core5.setBasicParameter(mParaImaImproveWD_green_Core5);
	mWienderDeconSF_green_Core6.setBasicParameter(mParaImaImproveWD_green_Core6);
	mWienderDeconSF_green_Core7.setBasicParameter(mParaImaImproveWD_green_Core7);
	mWienderDeconSF_green_Core8.setBasicParameter(mParaImaImproveWD_green_Core8);
}

void WienerDeconvolutionSF_parallel_BGR::initializePrameterDifCores_red()
{
	int kernelSizeHeightAndWidth = mParaImaImproveWD_red_global.getKernelSizeHeightAndWidth();
	real compareInPercent = mParaImaImproveWD_red_global.getCompareInPercent();
	sharpnessEvalMethode sharpEvalMeth = mParaImaImproveWD_red_global.getSharpnessEvalMethode();

	// set kernel size height and width
	mParaImaImproveWD_red_Core1.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_red_Core2.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_red_Core3.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_red_Core4.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_red_Core5.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_red_Core6.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_red_Core7.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);
	mParaImaImproveWD_red_Core8.setKernelSizeHeightAndWidth(kernelSizeHeightAndWidth);

	mParaImaImproveWD_red_Core1.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_red_Core2.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_red_Core3.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_red_Core4.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_red_Core5.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_red_Core6.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_red_Core7.setCompareInPercent(compareInPercent);
	mParaImaImproveWD_red_Core8.setCompareInPercent(compareInPercent);

	// sharpness evaluation methode
	mParaImaImproveWD_red_Core1.setSharpnessEvalMethode(sharpEvalMeth);
	mParaImaImproveWD_red_Core2.setSharpnessEvalMethode(sharpEvalMeth);
	mParaImaImproveWD_red_Core3.setSharpnessEvalMethode(sharpEvalMeth);
	mParaImaImproveWD_red_Core4.setSharpnessEvalMethode(sharpEvalMeth);
	mParaImaImproveWD_red_Core5.setSharpnessEvalMethode(sharpEvalMeth);
	mParaImaImproveWD_red_Core6.setSharpnessEvalMethode(sharpEvalMeth);
	mParaImaImproveWD_red_Core7.setSharpnessEvalMethode(sharpEvalMeth);
	mParaImaImproveWD_red_Core8.setSharpnessEvalMethode(sharpEvalMeth);

	// numer of cores
	int numberCores = 8;

	// sigma
	real minSigmaGlobal = mParaImaImproveWD_red_global.getMinSigmaXY();
	real maxSigmaGlobal = mParaImaImproveWD_red_global.getMaxSigmaXY();

	real stepsPerCoreSigma = mParaImaImproveWD_red_global.getStepsSigmaXY() / numberCores;

	mParaImaImproveWD_red_Core1.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_red_Core2.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_red_Core3.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_red_Core4.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_red_Core5.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_red_Core6.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_red_Core7.setStepsSigmaXY(stepsPerCoreSigma);
	mParaImaImproveWD_red_Core8.setStepsSigmaXY(stepsPerCoreSigma);

	// SNR
	real minSNR_Global = mParaImaImproveWD_red_global.getMinSNR();
	real maxSNR_Global = mParaImaImproveWD_red_global.getMaxSNR();

	real stepsPerCoreSNR = mParaImaImproveWD_red_global.getStepsSNR() / numberCores;

	mParaImaImproveWD_red_Core1.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_red_Core2.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_red_Core3.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_red_Core4.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_red_Core5.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_red_Core6.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_red_Core7.setStepsSNR(stepsPerCoreSNR);
	mParaImaImproveWD_red_Core8.setStepsSNR(stepsPerCoreSNR);


	//calc diff sigma per core
	real deltaSigmaGloal = (mParaImaImproveWD_red_global.getMaxSigmaXY() - mParaImaImproveWD_red_global.getMinSigmaXY()) / mParaImaImproveWD_red_global.getStepsSigmaXY();
	real diffPerCoreSigma = deltaSigmaGloal * stepsPerCoreSigma;

	real minSigmaCore_1 = minSigmaGlobal;
	real maxSigmaCore_1 = minSigmaCore_1 + diffPerCoreSigma;
	real minSigmaCore_2 = maxSigmaCore_1;
	real maxSigmaCore_2 = minSigmaCore_2 + diffPerCoreSigma;
	real minSigmaCore_3 = maxSigmaCore_2;
	real maxSigmaCore_3 = minSigmaCore_3 + diffPerCoreSigma;
	real minSigmaCore_4 = maxSigmaCore_3;
	real maxSigmaCore_4 = minSigmaCore_4 + diffPerCoreSigma;
	real minSigmaCore_5 = maxSigmaCore_4;
	real maxSigmaCore_5 = minSigmaCore_5 + diffPerCoreSigma;
	real minSigmaCore_6 = maxSigmaCore_5;
	real maxSigmaCore_6 = minSigmaCore_6 + diffPerCoreSigma;
	real minSigmaCore_7 = maxSigmaCore_6;
	real maxSigmaCore_7 = minSigmaCore_7 + diffPerCoreSigma;
	real minSigmaCore_8 = maxSigmaCore_7;
	real maxSigmaCore_8 = maxSigmaGlobal;


	mParaImaImproveWD_red_Core1.setMinSigmaXY(minSigmaCore_1);
	mParaImaImproveWD_red_Core1.setMaxSigmaXY(maxSigmaCore_1);
	mParaImaImproveWD_red_Core2.setMinSigmaXY(minSigmaCore_2);
	mParaImaImproveWD_red_Core2.setMaxSigmaXY(maxSigmaCore_2);
	mParaImaImproveWD_red_Core3.setMinSigmaXY(minSigmaCore_3);
	mParaImaImproveWD_red_Core3.setMaxSigmaXY(maxSigmaCore_3);
	mParaImaImproveWD_red_Core4.setMinSigmaXY(minSigmaCore_4);
	mParaImaImproveWD_red_Core4.setMaxSigmaXY(maxSigmaCore_4);
	mParaImaImproveWD_red_Core5.setMinSigmaXY(minSigmaCore_5);
	mParaImaImproveWD_red_Core5.setMaxSigmaXY(maxSigmaCore_5);
	mParaImaImproveWD_red_Core6.setMinSigmaXY(minSigmaCore_6);
	mParaImaImproveWD_red_Core6.setMaxSigmaXY(maxSigmaCore_6);
	mParaImaImproveWD_red_Core7.setMinSigmaXY(minSigmaCore_7);
	mParaImaImproveWD_red_Core7.setMaxSigmaXY(maxSigmaCore_7);
	mParaImaImproveWD_red_Core8.setMinSigmaXY(minSigmaCore_8);
	mParaImaImproveWD_red_Core8.setMaxSigmaXY(maxSigmaCore_8);


	//calc diff SNR per core
	real deltaSNR_Gloal = (mParaImaImproveWD_red_global.getMaxSNR() - mParaImaImproveWD_red_global.getMinSNR()) / mParaImaImproveWD_red_global.getStepsSNR();
	real diffPerCoreSNR = deltaSNR_Gloal * stepsPerCoreSNR;

	real minSNR_Core_1 = minSNR_Global;
	real maxSNR_Core_1 = minSNR_Core_1 + diffPerCoreSNR;
	real minSNR_Core_2 = maxSNR_Core_1;
	real maxSNR_Core_2 = minSNR_Core_2 + diffPerCoreSNR;
	real minSNR_Core_3 = maxSNR_Core_2;
	real maxSNR_Core_3 = minSNR_Core_3 + diffPerCoreSNR;
	real minSNR_Core_4 = maxSNR_Core_3;
	real maxSNR_Core_4 = minSNR_Core_4 + diffPerCoreSNR;
	real minSNR_Core_5 = maxSNR_Core_4;
	real maxSNR_Core_5 = minSNR_Core_5 + diffPerCoreSNR;
	real minSNR_Core_6 = maxSNR_Core_5;
	real maxSNR_Core_6 = minSNR_Core_6 + diffPerCoreSNR;
	real minSNR_Core_7 = maxSNR_Core_6;
	real maxSNR_Core_7 = minSNR_Core_7 + diffPerCoreSNR;
	real minSNR_Core_8 = maxSNR_Core_7;
	real maxSNR_Core_8 = maxSNR_Global;

	mParaImaImproveWD_red_Core1.setMinSNR(minSNR_Core_1);
	mParaImaImproveWD_red_Core1.setMaxSNR(maxSNR_Core_1);
	mParaImaImproveWD_red_Core2.setMinSNR(minSNR_Core_2);
	mParaImaImproveWD_red_Core2.setMaxSNR(maxSNR_Core_2);
	mParaImaImproveWD_red_Core3.setMinSNR(minSNR_Core_3);
	mParaImaImproveWD_red_Core3.setMaxSNR(maxSNR_Core_3);
	mParaImaImproveWD_red_Core4.setMinSNR(minSNR_Core_4);
	mParaImaImproveWD_red_Core4.setMaxSNR(maxSNR_Core_4);
	mParaImaImproveWD_red_Core5.setMinSNR(minSNR_Core_5);
	mParaImaImproveWD_red_Core5.setMaxSNR(maxSNR_Core_5);
	mParaImaImproveWD_red_Core6.setMinSNR(minSNR_Core_6);
	mParaImaImproveWD_red_Core6.setMaxSNR(maxSNR_Core_6);
	mParaImaImproveWD_red_Core7.setMinSNR(minSNR_Core_7);
	mParaImaImproveWD_red_Core7.setMaxSNR(maxSNR_Core_7);
	mParaImaImproveWD_red_Core8.setMinSNR(minSNR_Core_8);
	mParaImaImproveWD_red_Core8.setMaxSNR(maxSNR_Core_8);

	mWienderDeconSF_red_Core1.setBasicParameter(mParaImaImproveWD_red_Core1);
	mWienderDeconSF_red_Core2.setBasicParameter(mParaImaImproveWD_red_Core2);
	mWienderDeconSF_red_Core3.setBasicParameter(mParaImaImproveWD_red_Core3);
	mWienderDeconSF_red_Core4.setBasicParameter(mParaImaImproveWD_red_Core4);
	mWienderDeconSF_red_Core5.setBasicParameter(mParaImaImproveWD_red_Core5);
	mWienderDeconSF_red_Core6.setBasicParameter(mParaImaImproveWD_red_Core6);
	mWienderDeconSF_red_Core7.setBasicParameter(mParaImaImproveWD_red_Core7);
	mWienderDeconSF_red_Core8.setBasicParameter(mParaImaImproveWD_red_Core8);
}

void WienerDeconvolutionSF_parallel_BGR::improveImaQual_WD_superFct_BGR_parallel(const cv::Mat sharpBGR_Image, const cv::Mat blueredBGR_Image)
{
	mSharpImage_BGR = sharpBGR_Image.clone();
	mBlueredImage_BGR = blueredBGR_Image.clone();

	// split the image in BGR channels
	splitImagesInBGR();
	// calc min max
	calcMinMax();
	// initialize parameter
	initializePrameterDifCores_blue();
	initializePrameterDifCores_green();
	initializePrameterDifCores_red();

	mImprovements_vec_blue.resize(8);
	mSaveAllBestParameters_blue.resize(8);
	mSharpness_vec_blue.resize(8);
	mImprovements_vec_green.resize(8);
	mSaveAllBestParameters_green.resize(8);
	mSharpness_vec_green.resize(8);
	mImprovements_vec_red.resize(8);
	mSaveAllBestParameters_red.resize(8);
	mSharpness_vec_red.resize(8);

	// find best SNR and Sigma parallel
	findingBestSNRandSigma_BGR_parallel();

	// find best parameter of all cores
	findBestParameterAllCores_blue();
	findBestParameterAllCores_green();
	findBestParameterAllCores_red();

	// norm the gray images
	normTheGrayImagesAccordingToSharpIma();
	// put channels together
	putChannlesTogehter();
}

void WienerDeconvolutionSF_parallel_BGR::findingBestSNRandSigma_BGR_parallel()
{

omp_set_num_threads(24);
#pragma omp parallel 
	{
		#pragma omp sections
		{
			#pragma omp section // _blue_1
			{
				//std::cout << "start WD blue 1" << std::endl;
				mWienderDeconSF_blue_Core1.improveImaQual_WD_superFct_gray(mSharpImage_blue, mBlueredImage_blue);
				real impCore1 = mWienderDeconSF_blue_Core1.getBestParameter().getImprovement();
				mImprovements_vec_blue[0] = impCore1;
				mSaveAllBestParameters_blue[0] = mWienderDeconSF_blue_Core1.getBestParameter();
				mSharpness_vec_blue[0] = mWienderDeconSF_blue_Core1.getBestParameter().getSharpness();
			}
			#pragma omp section // _blue_2
			{
				//std::cout << "start WD blue 2" << std::endl;
				mWienderDeconSF_blue_Core2.improveImaQual_WD_superFct_gray(mSharpImage_blue, mBlueredImage_blue);
				real impCore2 = mWienderDeconSF_blue_Core2.getBestParameter().getImprovement();
				mImprovements_vec_blue[1] = impCore2;
				mSaveAllBestParameters_blue[1] = mWienderDeconSF_blue_Core2.getBestParameter();
				mSharpness_vec_blue[1] = mWienderDeconSF_blue_Core2.getBestParameter().getSharpness();
			}
			#pragma omp section // _blue_3
			{
				//std::cout << "start WD blue 3" << std::endl;
				mWienderDeconSF_blue_Core3.improveImaQual_WD_superFct_gray(mSharpImage_blue, mBlueredImage_blue);
				real impCore3 = mWienderDeconSF_blue_Core3.getBestParameter().getImprovement();
				mImprovements_vec_blue[2] = impCore3;
				mSaveAllBestParameters_blue[2] = mWienderDeconSF_blue_Core3.getBestParameter();
				mSharpness_vec_blue[2] = mWienderDeconSF_blue_Core3.getBestParameter().getSharpness();
			}
			#pragma omp section // _blue_4
			{
				//std::cout << "start WD blue 4" << std::endl;
				mWienderDeconSF_blue_Core4.improveImaQual_WD_superFct_gray(mSharpImage_blue, mBlueredImage_blue);
				real impCore4 = mWienderDeconSF_blue_Core4.getBestParameter().getImprovement();
				mImprovements_vec_blue[3] = impCore4;
				mSaveAllBestParameters_blue[3] = mWienderDeconSF_blue_Core4.getBestParameter();
				mSharpness_vec_blue[3] = mWienderDeconSF_blue_Core4.getBestParameter().getSharpness();
			}
			#pragma omp section // _blue_5
			{
				//std::cout << "start WD blue 5" << std::endl;
				mWienderDeconSF_blue_Core5.improveImaQual_WD_superFct_gray(mSharpImage_blue, mBlueredImage_blue);
				real impCore5 = mWienderDeconSF_blue_Core5.getBestParameter().getImprovement();
				mImprovements_vec_blue[4] = impCore5;
				mSaveAllBestParameters_blue[4] = mWienderDeconSF_blue_Core5.getBestParameter();
				mSharpness_vec_blue[4] = mWienderDeconSF_blue_Core5.getBestParameter().getSharpness();
			}
			#pragma omp section // _blue_6
			{
				//std::cout << "start WD blue 6" << std::endl;
				mWienderDeconSF_blue_Core6.improveImaQual_WD_superFct_gray(mSharpImage_blue, mBlueredImage_blue);
				real impCore6 = mWienderDeconSF_blue_Core6.getBestParameter().getImprovement();
				mImprovements_vec_blue[5] = impCore6;
				mSaveAllBestParameters_blue[5] = mWienderDeconSF_blue_Core6.getBestParameter();
				mSharpness_vec_blue[5] = mWienderDeconSF_blue_Core6.getBestParameter().getSharpness();
			}
			#pragma omp section // _blue_7
			{
				//std::cout << "start WD blue 7" << std::endl;
				mWienderDeconSF_blue_Core7.improveImaQual_WD_superFct_gray(mSharpImage_blue, mBlueredImage_blue);
				real impCore7 = mWienderDeconSF_blue_Core7.getBestParameter().getImprovement();
				mImprovements_vec_blue[6] = impCore7;
				mSaveAllBestParameters_blue[6] = mWienderDeconSF_blue_Core7.getBestParameter();
				mSharpness_vec_blue[6] = mWienderDeconSF_blue_Core7.getBestParameter().getSharpness();
			}
			#pragma omp section // _blue_8
			{
				//std::cout << "start WD blue 8" << std::endl;
				mWienderDeconSF_blue_Core8.improveImaQual_WD_superFct_gray(mSharpImage_blue, mBlueredImage_blue);
				real impCore8 = mWienderDeconSF_blue_Core8.getBestParameter().getImprovement();
				mImprovements_vec_blue[7] = impCore8;
				mSaveAllBestParameters_blue[7] = mWienderDeconSF_blue_Core8.getBestParameter();
				mSharpness_vec_blue[7] = mWienderDeconSF_blue_Core8.getBestParameter().getSharpness();
			}
			#pragma omp section // _green_1
			{
				//std::cout << "start WD green 1" << std::endl;
				mWienderDeconSF_green_Core1.improveImaQual_WD_superFct_gray(mSharpImage_green, mBlueredImage_green);
				real impCore1 = mWienderDeconSF_green_Core1.getBestParameter().getImprovement();
				mImprovements_vec_green[0] = impCore1;
				mSaveAllBestParameters_green[0] = mWienderDeconSF_green_Core1.getBestParameter();
				mSharpness_vec_green[0] = mWienderDeconSF_green_Core1.getBestParameter().getSharpness();
			}
			#pragma omp section // _green_2
			{
				//std::cout << "start WD green 2" << std::endl;
				mWienderDeconSF_green_Core2.improveImaQual_WD_superFct_gray(mSharpImage_green, mBlueredImage_green);
				real impCore2 = mWienderDeconSF_green_Core2.getBestParameter().getImprovement();
				mImprovements_vec_green[1] = impCore2;
				mSaveAllBestParameters_green[1] = mWienderDeconSF_green_Core2.getBestParameter();
				mSharpness_vec_green[1] = mWienderDeconSF_green_Core2.getBestParameter().getSharpness();
			}
			#pragma omp section // _green_3
			{
				//std::cout << "start WD green 3" << std::endl;
				mWienderDeconSF_green_Core3.improveImaQual_WD_superFct_gray(mSharpImage_green, mBlueredImage_green);
				real impCore3 = mWienderDeconSF_green_Core3.getBestParameter().getImprovement();
				mImprovements_vec_green[2] = impCore3;
				mSaveAllBestParameters_green[2] = mWienderDeconSF_green_Core3.getBestParameter();
				mSharpness_vec_green[2] = mWienderDeconSF_green_Core3.getBestParameter().getSharpness();
			}
			#pragma omp section // _green_4
			{
				//std::cout << "start WD green 4" << std::endl;
				mWienderDeconSF_green_Core4.improveImaQual_WD_superFct_gray(mSharpImage_green, mBlueredImage_green);
				real impCore4 = mWienderDeconSF_green_Core4.getBestParameter().getImprovement();
				mImprovements_vec_green[3] = impCore4;
				mSaveAllBestParameters_green[3] = mWienderDeconSF_green_Core4.getBestParameter();
				mSharpness_vec_green[3] = mWienderDeconSF_green_Core4.getBestParameter().getSharpness();
			}
			#pragma omp section // _green_5
			{
				//std::cout << "start WD green 5" << std::endl;
				mWienderDeconSF_green_Core5.improveImaQual_WD_superFct_gray(mSharpImage_green, mBlueredImage_green);
				real impCore5 = mWienderDeconSF_green_Core5.getBestParameter().getImprovement();
				mImprovements_vec_green[4] = impCore5;
				mSaveAllBestParameters_green[4] = mWienderDeconSF_green_Core5.getBestParameter();
				mSharpness_vec_green[4] = mWienderDeconSF_green_Core5.getBestParameter().getSharpness();
			}
			#pragma omp section // _green_6
			{
				//std::cout << "start WD green 6" << std::endl;
				mWienderDeconSF_green_Core6.improveImaQual_WD_superFct_gray(mSharpImage_green, mBlueredImage_green);
				real impCore6 = mWienderDeconSF_green_Core6.getBestParameter().getImprovement();
				mImprovements_vec_green[5] = impCore6;
				mSaveAllBestParameters_green[5] = mWienderDeconSF_green_Core6.getBestParameter();
				mSharpness_vec_green[5] = mWienderDeconSF_green_Core6.getBestParameter().getSharpness();
			}
			#pragma omp section // _green_7
			{
				//std::cout << "start WD green 7" << std::endl;
				mWienderDeconSF_green_Core7.improveImaQual_WD_superFct_gray(mSharpImage_green, mBlueredImage_green);
				real impCore7 = mWienderDeconSF_green_Core7.getBestParameter().getImprovement();
				mImprovements_vec_green[6] = impCore7;
				mSaveAllBestParameters_green[6] = mWienderDeconSF_green_Core7.getBestParameter();
				mSharpness_vec_green[6] = mWienderDeconSF_green_Core7.getBestParameter().getSharpness();
			}
			#pragma omp section // _green_8
			{
				//std::cout << "start WD green 8" << std::endl;
				mWienderDeconSF_green_Core8.improveImaQual_WD_superFct_gray(mSharpImage_green, mBlueredImage_green);
				real impCore8 = mWienderDeconSF_green_Core8.getBestParameter().getImprovement();
				mImprovements_vec_green[7] = impCore8;
				mSaveAllBestParameters_green[7] = mWienderDeconSF_green_Core8.getBestParameter();
				mSharpness_vec_green[7] = mWienderDeconSF_green_Core8.getBestParameter().getSharpness();
			}
			#pragma omp section // _red_1
			{
				//std::cout << "start WD red 1" << std::endl;
				mWienderDeconSF_red_Core1.improveImaQual_WD_superFct_gray(mSharpImage_red, mBlueredImage_red);
				real impCore1 = mWienderDeconSF_red_Core1.getBestParameter().getImprovement();
				mImprovements_vec_red[0] = impCore1;
				mSaveAllBestParameters_red[0] = mWienderDeconSF_red_Core1.getBestParameter();
				mSharpness_vec_red[0] = mWienderDeconSF_red_Core1.getBestParameter().getSharpness();
			}
			#pragma omp section // _red_2
			{
				//std::cout << "start WD red 2" << std::endl;
				mWienderDeconSF_red_Core2.improveImaQual_WD_superFct_gray(mSharpImage_red, mBlueredImage_red);
				real impCore2 = mWienderDeconSF_red_Core2.getBestParameter().getImprovement();
				mImprovements_vec_red[1] = impCore2;
				mSaveAllBestParameters_red[1] = mWienderDeconSF_red_Core2.getBestParameter();
				mSharpness_vec_red[1] = mWienderDeconSF_red_Core2.getBestParameter().getSharpness();
			}
			#pragma omp section // _red_3
			{
				//std::cout << "start WD red 3" << std::endl;
				mWienderDeconSF_red_Core3.improveImaQual_WD_superFct_gray(mSharpImage_red, mBlueredImage_red);
				real impCore3 = mWienderDeconSF_red_Core3.getBestParameter().getImprovement();
				mImprovements_vec_red[2] = impCore3;
				mSaveAllBestParameters_red[2] = mWienderDeconSF_red_Core3.getBestParameter();
				mSharpness_vec_red[2] = mWienderDeconSF_red_Core3.getBestParameter().getSharpness();
			}
			#pragma omp section // _red_4
			{
				//std::cout << "start WD red 4" << std::endl;
				mWienderDeconSF_red_Core4.improveImaQual_WD_superFct_gray(mSharpImage_red, mBlueredImage_red);
				real impCore4 = mWienderDeconSF_red_Core4.getBestParameter().getImprovement();
				mImprovements_vec_red[3] = impCore4;
				mSaveAllBestParameters_red[3] = mWienderDeconSF_red_Core4.getBestParameter();
				mSharpness_vec_red[3] = mWienderDeconSF_red_Core4.getBestParameter().getSharpness();
			}
			#pragma omp section // _red_5
			{
				//std::cout << "start WD red 5" << std::endl;
				mWienderDeconSF_red_Core5.improveImaQual_WD_superFct_gray(mSharpImage_red, mBlueredImage_red);
				real impCore5 = mWienderDeconSF_red_Core5.getBestParameter().getImprovement();
				mImprovements_vec_red[4] = impCore5;
				mSaveAllBestParameters_red[4] = mWienderDeconSF_red_Core5.getBestParameter();
				mSharpness_vec_red[4] = mWienderDeconSF_red_Core5.getBestParameter().getSharpness();
			}
			#pragma omp section // _red_6
			{
				//std::cout << "start WD red 6" << std::endl;
				mWienderDeconSF_red_Core6.improveImaQual_WD_superFct_gray(mSharpImage_red, mBlueredImage_red);
				real impCore6 = mWienderDeconSF_red_Core6.getBestParameter().getImprovement();
				mImprovements_vec_red[5] = impCore6;
				mSaveAllBestParameters_red[5] = mWienderDeconSF_red_Core6.getBestParameter();
				mSharpness_vec_red[5] = mWienderDeconSF_red_Core6.getBestParameter().getSharpness();
			}
			#pragma omp section // _red_7
			{
				//std::cout << "start WD red 7" << std::endl;
				mWienderDeconSF_red_Core7.improveImaQual_WD_superFct_gray(mSharpImage_red, mBlueredImage_red);
				real impCore7 = mWienderDeconSF_red_Core7.getBestParameter().getImprovement();
				mImprovements_vec_red[6] = impCore7;
				mSaveAllBestParameters_red[6] = mWienderDeconSF_red_Core7.getBestParameter();
				mSharpness_vec_red[6] = mWienderDeconSF_red_Core7.getBestParameter().getSharpness();
			}
			#pragma omp section // _red_8
			{
				//std::cout << "start WD red 8" << std::endl;
				mWienderDeconSF_red_Core8.improveImaQual_WD_superFct_gray(mSharpImage_red, mBlueredImage_red);
				real impCore8 = mWienderDeconSF_red_Core8.getBestParameter().getImprovement();
				mImprovements_vec_red[7] = impCore8;
				mSaveAllBestParameters_red[7] = mWienderDeconSF_red_Core8.getBestParameter();
				mSharpness_vec_red[7] = mWienderDeconSF_red_Core8.getBestParameter().getSharpness();
			}

		}
	}
}

void WienerDeconvolutionSF_parallel_BGR::normTheGrayImagesAccordingToSharpIma()
{
	// blue
	cv::Mat filterResultIma_blue = mBestParameterGlobal_blue.getBestReconstruction().clone();
	cv::normalize(filterResultIma_blue, mFilterResultIma_blue_normedSharpBlue, mMin_blue, mMax_blue, cv::NORM_MINMAX, CV_8UC1);

	// green
	cv::Mat filterResultIma_green = mBestParameterGlobal_green.getBestReconstruction().clone();
	cv::normalize(filterResultIma_green, mFilterResultIma_green_normedSharpGreen, mMin_green, mMax_green, cv::NORM_MINMAX, CV_8UC1);

	// red
	cv::Mat filterResultIma_red = mBestParameterGlobal_red.getBestReconstruction().clone();
	cv::normalize(filterResultIma_red, mFilterResultIma_red__normedSharpRed, mMin_red, mMax_red, cv::NORM_MINMAX, CV_8UC1);
}

void WienerDeconvolutionSF_parallel_BGR::splitImagesInBGR()
{
	// sharp image
	cv::Mat channelSharpImage[3];
	cv::split(mSharpImage_BGR, channelSharpImage);
	mSharpImage_blue = channelSharpImage[0];
	mSharpImage_green = channelSharpImage[1];
	mSharpImage_red = channelSharpImage[2];

	// bluered image
	cv::Mat channelBluredImage[3];
	cv::split(mBlueredImage_BGR, channelBluredImage);
	mBlueredImage_blue = channelBluredImage[0];
	mBlueredImage_green = channelBluredImage[1];
	mBlueredImage_red = channelBluredImage[2];
}

void WienerDeconvolutionSF_parallel_BGR::calcMinMax()
{ 
	unsigned int height = mSharpImage_BGR.size().height;
	unsigned int width = mSharpImage_BGR.size().width;

	unsigned int startX = mParaImaImproveWD_blue_global.getCompareInPercent() * width / 100.0;
	unsigned int startY = mParaImaImproveWD_blue_global.getCompareInPercent() * height / 100.0;
	unsigned int heighttROI = height - 2 * startY;
	unsigned int widthROI = width - 2 * startX;
	mMin_blue = oftenUse::getInfInt();
	mMax_blue = 0;
	int temp_blue;
	for (unsigned int x = 0; x < width; ++x)
	{
		for (unsigned int y = 0; y < height; ++y)
		{
			temp_blue = mSharpImage_blue.at<uchar>(y, x);
			if (temp_blue < mMin_blue)
			{
				mMin_blue = temp_blue;
			}

			if (temp_blue > mMax_blue)
			{
				mMax_blue = temp_blue;
			}
		}
	}

	mMin_green = oftenUse::getInfInt();
	mMax_green = 0;
	int temp_green;
	for (unsigned int x = 0; x < width; ++x)
	{
		for (unsigned int y = 0; y < height; ++y)
		{
			temp_green = mSharpImage_green.at<uchar>(y, x);
			if (temp_green < mMin_green)
			{
				mMin_green = temp_green;
			}

			if (temp_green > mMax_green)
			{
				mMax_green = temp_green;
			}
		}
	}

	mMin_red = oftenUse::getInfInt();
	mMax_red = 0;
	int temp_red;
	for (unsigned int x = 0; x < width; ++x)
	{
		for (unsigned int y = 0; y < height; ++y)
		{
			temp_red = mSharpImage_red.at<uchar>(y, x);
			if (temp_red < mMin_red)
			{
				mMin_red = temp_red;
			}

			if (temp_red > mMax_red)
			{
				mMax_red = temp_red;
			}
		}
	}

}

void WienerDeconvolutionSF_parallel_BGR::putChannlesTogehter()
{
	std::vector<cv::Mat> array_to_merge;

	array_to_merge.push_back(mFilterResultIma_blue_normedSharpBlue);
	array_to_merge.push_back(mFilterResultIma_green_normedSharpGreen);
	array_to_merge.push_back(mFilterResultIma_red__normedSharpRed);

	cv::merge(array_to_merge, mFilterResultIma_BGR_normedLikeSharpIma);
}

cv::Mat WienerDeconvolutionSF_parallel_BGR::getFilteredResults_normedLikeSharpIma()
{
	return mFilterResultIma_BGR_normedLikeSharpIma;
}

cv::Mat WienerDeconvolutionSF_parallel_BGR::getFilteredResults_normedZeroAndMaxUchar()
{
	std::vector<cv::Mat> array_to_merge;
	cv::Mat mFilterResultIma_BGR__normedZeroAndMaxUchar;

	array_to_merge.push_back(mBestParameterGlobal_blue.getBestReconstruction());
	array_to_merge.push_back(mBestParameterGlobal_green.getBestReconstruction());
	array_to_merge.push_back(mBestParameterGlobal_red.getBestReconstruction());

	cv::merge(array_to_merge, mFilterResultIma_BGR__normedZeroAndMaxUchar);

	return mFilterResultIma_BGR__normedZeroAndMaxUchar;
}

// find best parameter
void WienerDeconvolutionSF_parallel_BGR::findBestParameterAllCores_blue()
{
	// find best improvement
	real bestImprovement = mWienderDeconSF_blue_Core1.getBestParameter().getImprovement();
	real tempImp;
	real tempSharpness;
	real bestSharpness = -1.0 * oftenUse::getInfReal();
	unsigned int tempBestPosInVec = 0;

	if (mParaImaImproveWD_blue_global.getSharpnessEvalMethode() == sharpnessEvalMethode::sharpImage)
	{
		for (unsigned int i = 0; i < mImprovements_vec_blue.size(); ++i)
		{
			tempImp = mImprovements_vec_blue[i];
			// debug
			//std::cout << "temp improvement Wiener Deconvolution: " << tempImp << " core number: " << i << std::endl;

			if (tempImp > bestImprovement)
			{
				bestImprovement = tempImp;
				tempBestPosInVec = i;
			}
		}
	}

	else if (mParaImaImproveWD_blue_global.getSharpnessEvalMethode() != sharpnessEvalMethode::sharpImage)
	{
		for (unsigned int i = 0; i < mSharpness_vec_blue.size(); ++i)
		{
			tempSharpness = mSharpness_vec_blue[i];
			// debug
			//std::cout << "temp improvement Wiener Deconvolution blue: " << mImprovements_vec_blue[i] << " core number: " << i << std::endl;
			//std::cout << "temp sharpness Wiener Deconvolution blue: " << tempSharpness << " core number: " << i << std::endl;

			if (tempSharpness > bestSharpness)
			{
				bestSharpness = tempSharpness;
				tempBestPosInVec = i;


			}
		}
	}

	// debug 
	//std::cout << " --> best improvement Wiener Deconvolution blue: " << mImprovements_vec_blue[tempBestPosInVec] << " core number: " << tempBestPosInVec << std::endl;
	//std::cout << " --> best sharpness Wiener Deconvolution blue: " << mSharpness_vec_blue[tempBestPosInVec] << " core number: " << tempBestPosInVec << std::endl;

	mBestParameterGlobal_blue = mSaveAllBestParameters_blue[tempBestPosInVec];
	mBestParameterGlobal_blue.setBestCoreNum(tempBestPosInVec);
}

void WienerDeconvolutionSF_parallel_BGR::findBestParameterAllCores_green()
{
	// find best improvement
	real bestImprovement = mWienderDeconSF_green_Core1.getBestParameter().getImprovement();
	real tempImp;
	real tempSharpness;
	real bestSharpness = -1.0 * oftenUse::getInfReal();
	unsigned int tempBestPosInVec = 0;

	if (mParaImaImproveWD_green_global.getSharpnessEvalMethode() == sharpnessEvalMethode::sharpImage)
	{
		for (unsigned int i = 0; i < mImprovements_vec_green.size(); ++i)
		{
			tempImp = mImprovements_vec_green[i];
			// debug
			//std::cout << "temp improvement Wiener Deconvolution: " << tempImp << " core number: " << i << std::endl;

			if (tempImp > bestImprovement)
			{
				bestImprovement = tempImp;
				tempBestPosInVec = i;
			}
		}
	}

	else if (mParaImaImproveWD_green_global.getSharpnessEvalMethode() != sharpnessEvalMethode::sharpImage)
	{
		for (unsigned int i = 0; i < mSharpness_vec_green.size(); ++i)
		{
			tempSharpness = mSharpness_vec_green[i];
			// debug
			//std::cout << "temp improvement Wiener Deconvolution green: " << mImprovements_vec_green[i] << " core number: " << i << std::endl;
			//std::cout << "temp sharpness Wiener Deconvolution green: " << tempSharpness << " core number: " << i << std::endl;

			if (tempSharpness > bestSharpness)
			{
				bestSharpness = tempSharpness;
				tempBestPosInVec = i;


			}
		}
	}

	// debug 
	//std::cout << " --> best improvement Wiener Deconvolution green: " << mImprovements_vec_green[tempBestPosInVec] << " core number: " << tempBestPosInVec << std::endl;
	//std::cout << " --> best sharpness Wiener Deconvolution green: " << mSharpness_vec_green[tempBestPosInVec] << " core number: " << tempBestPosInVec << std::endl;

	mBestParameterGlobal_green = mSaveAllBestParameters_green[tempBestPosInVec];
	mBestParameterGlobal_green.setBestCoreNum(tempBestPosInVec);
}
void WienerDeconvolutionSF_parallel_BGR::findBestParameterAllCores_red()
{
	// find best improvement
	real bestImprovement = mWienderDeconSF_red_Core1.getBestParameter().getImprovement();
	real tempImp;
	real tempSharpness;
	real bestSharpness = -1.0 * oftenUse::getInfReal();
	unsigned int tempBestPosInVec = 0;

	if (mParaImaImproveWD_red_global.getSharpnessEvalMethode() == sharpnessEvalMethode::sharpImage)
	{
		for (unsigned int i = 0; i < mImprovements_vec_red.size(); ++i)
		{
			tempImp = mImprovements_vec_red[i];
			// debug
			//std::cout << "temp improvement Wiener Deconvolution: " << tempImp << " core number: " << i << std::endl;

			if (tempImp > bestImprovement)
			{
				bestImprovement = tempImp;
				tempBestPosInVec = i;
			}
		}
	}

	else if (mParaImaImproveWD_red_global.getSharpnessEvalMethode() != sharpnessEvalMethode::sharpImage)
	{
		for (unsigned int i = 0; i < mSharpness_vec_red.size(); ++i)
		{
			tempSharpness = mSharpness_vec_red[i];
			// debug
			//std::cout << "temp improvement Wiener Deconvolution red: " << mImprovements_vec_red[i] << " core number: " << i << std::endl;
			//std::cout << "temp sharpness Wiener Deconvolution red: " << tempSharpness << " core number: " << i << std::endl;

			if (tempSharpness > bestSharpness)
			{
				bestSharpness = tempSharpness;
				tempBestPosInVec = i;


			}
		}
	}

	// debug 
	//std::cout << " --> best improvement Wiener Deconvolution red: " << mImprovements_vec_red[tempBestPosInVec] << " core number: " << tempBestPosInVec << std::endl;
	//std::cout << " --> best sharpness Wiener Deconvolution red: " << mSharpness_vec_red[tempBestPosInVec] << " core number: " << tempBestPosInVec << std::endl;

	mBestParameterGlobal_red = mSaveAllBestParameters_red[tempBestPosInVec];
	mBestParameterGlobal_red.setBestCoreNum(tempBestPosInVec);
}


// best parameter
saveBestParameterWD WienerDeconvolutionSF_parallel_BGR::getBestParameter_blue()
{
	return mBestParameterGlobal_blue;
}
saveBestParameterWD WienerDeconvolutionSF_parallel_BGR::getBestParameter_green()
{
	return mBestParameterGlobal_green;
}
saveBestParameterWD WienerDeconvolutionSF_parallel_BGR::getBestParameter_red()
{
	return mBestParameterGlobal_red;
}

// initial Parameter
parameterImaImprove_WD WienerDeconvolutionSF_parallel_BGR::getInitialPara_blue()
{
	return mParaImaImproveWD_blue_global;
}
parameterImaImprove_WD WienerDeconvolutionSF_parallel_BGR::getInitialPara_green()
{
	return mParaImaImproveWD_green_global;
}
parameterImaImprove_WD WienerDeconvolutionSF_parallel_BGR::getInitialPara_red()
{
	{
		return mParaImaImproveWD_red_global;
	}
}
