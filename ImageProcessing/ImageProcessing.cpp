#include "ImageProcessing.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/calib3d/calib3d.hpp>
//#include <opencv2/imgcodecs.hpp>
#include <opencv2/photo.hpp>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "..\Image\Images.h"
#include "..\oftenUseNamespace\oftenUseNamespace.h"

// wiener filter
#include "..\ImageProcessing\WienerDeconvolutioinSuperFuction.h"

// unsharp masking
#include "..\ImageProcessing\UnsharpMasking.h"

// detail enhancement
#include "..\ImageProcessing\DetailEnhancement.h"

// remove chromatic aberrations
#include "..\ImageProcessing\RemoveChromaticAberrations.h"

ImaProcSuperFct::ImaProcSuperFct() {}
ImaProcSuperFct::~ImaProcSuperFct() {}



void ImaProcSuperFct::ImageProcessingSuperFunction(cv::Mat& inputIma, cv::Mat& blueredIma, imageProcessing imaProc)
{
	mInputIma = inputIma.clone();
	mBlueredIma = blueredIma.clone();
	mImaProc = imaProc;

	// *** wiener filter *** //
	if (mImaProc == imageProcessing::wienerFilter)
	{
		WienerDeconvolutionSuperFunction wienerDevon_superFct;
		wienerDevon_superFct.setParameter_blue(mParaWD_blue);
		wienerDevon_superFct.setParameter_green(mParaWD_green);
		wienerDevon_superFct.setParameter_red(mParaWD_red);

		wienerDevon_superFct.improveImaQual_WD_superFct(mInputIma, mBlueredIma);

		mBestParaWD_blue = wienerDevon_superFct.getBestParameter_blue();
		mBestParaWD_green = wienerDevon_superFct.getBestParameter_green();
		mBestParaWD_red = wienerDevon_superFct.getBestParameter_red();

		mFilteredIma = wienerDevon_superFct.getFilteredImage();
	}

	// *** wiener filter parallel *** //
	else if (mImaProc == imageProcessing::wienerFilter24)
	{
		WienerDeconvolutionSF_parallel_BGR wienerDeconParallelBGR;
		wienerDeconParallelBGR.setParameterWD_Global_blue(mParaWD_blue);
		wienerDeconParallelBGR.setParameterWD_Global_green(mParaWD_green);
		wienerDeconParallelBGR.setParameterWD_Global_red(mParaWD_red);

		wienerDeconParallelBGR.improveImaQual_WD_superFct_BGR_parallel(mInputIma, mBlueredIma);

		mBestParaWD_blue = wienerDeconParallelBGR.getBestParameter_blue();
		mBestParaWD_green = wienerDeconParallelBGR.getBestParameter_green();
		mBestParaWD_red = wienerDeconParallelBGR.getBestParameter_red();

		mFilteredIma = wienerDeconParallelBGR.getFilteredResults_normedZeroAndMaxUchar();
	}

	// *** unsharp masking *** //
	else if (mImaProc == imageProcessing::unsharpMasking)
	{
		UnshaprMasking_singleCore_BGR unsharpMasking;
		unsharpMasking.setParameterUM_blue(mParaUnsMas_gray);
		unsharpMasking.setParameterUM_green(mParaUnsMas_green);
		unsharpMasking.setParameterUM_red(mParaUnsMas_red);

		unsharpMasking.improveImaQual_UnsharpMasking_superFct_BGR(mInputIma, mBlueredIma);

		mBestParaUnsMas_blue = unsharpMasking.getBestParameter_blue();
		mBestParaUnsMas_green = unsharpMasking.getBestParameter_green();
		mBestParaUnsMas_red = unsharpMasking.getBestParameter_red();

		mFilteredIma = unsharpMasking.getFilteredResults_normedZeroAndMaxUchar();
	}

	// *** unsharp masking parallel *** //
	else if (mImaProc == imageProcessing::unsharpMasking24)
	{
		unsharpMasking_BGR_parallel unsharpMasking_24;
		unsharpMasking_24.setParameterUM_blue(mParaUnsMas_blue);
		unsharpMasking_24.setParameterUM_green(mParaUnsMas_green);
		unsharpMasking_24.setParameterUM_red(mParaUnsMas_red);

		unsharpMasking_24.improveImaQual_UnsharpMasking_superFct_BGR_parallel(mInputIma, mBlueredIma);

		mBestParaUnsMas_blue = unsharpMasking_24.getBestParameter_blue();
		mBestParaUnsMas_green = unsharpMasking_24.getBestParameter_green();
		mBestParaUnsMas_red = unsharpMasking_24.getBestParameter_red();

		mFilteredIma = unsharpMasking_24.getFilteredResults_normedZeroAndMaxUchar();

	}

	// *** unsharp masking gray*** //
	else if (mImaProc == imageProcessing::unsharpMasking_gray)
	{
		UnshaprMasking_singleCore_gray unsharpMasking_gray;
		unsharpMasking_gray.setParameterUM(mParaUnsMas_gray);

		unsharpMasking_gray.improveImageQuality_unsharpMask_gray(mInputIma, mBlueredIma);

		mBestParaUnsMas_gray = unsharpMasking_gray.getBestParameter();

		mFilteredIma = mBestParaUnsMas_gray.getImage();

	}

	// *** unsharp masking parallel gray*** //
	else if (mImaProc == imageProcessing::unsharpMasking24_gray)
	{
	
		UnsharpMasking24_gray unsharpMasking24_gray;
		unsharpMasking24_gray.setParameterUM_gray(mParaUnsMas_gray);

		unsharpMasking24_gray.improveImaQual_UnsharpMasking_superFct_GRAY_parallel(mInputIma, mBlueredIma);

		mBestParaUnsMas_gray = unsharpMasking24_gray.getBestParameter_gray();

		mFilteredIma = mBestParaUnsMas_gray.getImage();
	}
	
	// *** detail enhancement *** ///
	else if (mImaProc == imageProcessing::detailEnhance)
	{
		DetailEnhancement_BGR detailEnhancement;
		detailEnhancement.setInitialParameter(mParaDetEnh);

		detailEnhancement.improveImageQuality_DetailEnhancement_BGR(mInputIma, mBlueredIma);

		mBestParaDetEnh = detailEnhancement.getBestParameter();

		mFilteredIma = detailEnhancement.getFilteredIma();
	}

	// *** detail enhancement 24*** ///
	else if (mImaProc == imageProcessing::detailEnhance24)
	{
		DetailEnhancement_BGR_parallel detailEnhancement_BGR_24;
		detailEnhancement_BGR_24.setParameter_global(mParaDetEnh);

		detailEnhancement_BGR_24.improveImageQuality_DetailEnhancement_BGR_parallel(mInputIma, mBlueredIma);

		mBestParaDetEnh = detailEnhancement_BGR_24.getBestParameter();
		mFilteredIma = detailEnhancement_BGR_24.getFilteredIma();
	}

	else if (mImaProc == imageProcessing::removeChromaticAber)
	{
		RemoveChromaticAberrations removeChromAber;
		removeChromAber.setInitialParameter(mParaRemoChroAber);

		removeChromAber.removeChromaticAberrations_superFct(mInputIma, mBlueredIma);

		mBestParaRemoChroAber = removeChromAber.getBestParameter();
		mFilteredIma = removeChromAber.getFilterdIma();
	}

	else if (mImaProc == imageProcessing::unshMas_DetailEnh_WienerDec_24)
	{
		real devideStepsByFactorForSecondSearch = 1.0;
		real reinizializePrecent = 20.0;

		mAllFilteredImages_UM_DE_WD.resize(3);
		// unsharp masking
		// _________________________________________________________
		unsharpMasking_BGR_parallel unsharpMasking_24_First;
		unsharpMasking_24_First.setParameterUM_blue(mParaUnsMas_blue);
		unsharpMasking_24_First.setParameterUM_green(mParaUnsMas_green);
		unsharpMasking_24_First.setParameterUM_red(mParaUnsMas_red);

		unsharpMasking_24_First.improveImaQual_UnsharpMasking_superFct_BGR_parallel(mInputIma, mBlueredIma);
		cv::Mat tempFilteredImages = unsharpMasking_24_First.getFilteredResults_normedZeroAndMaxUchar();
	
		mBestParaUnsMas_blue = unsharpMasking_24_First.getBestParameter_blue();
		mBestParaUnsMas_green = unsharpMasking_24_First.getBestParameter_green();
		mBestParaUnsMas_red = unsharpMasking_24_First.getBestParameter_red();

		reinitializeBestParaUnsMas(reinizializePrecent, mParaUnsMas_blue.getStepsSigma() / devideStepsByFactorForSecondSearch, mParaUnsMas_blue.getStepsThreshold() / devideStepsByFactorForSecondSearch, mParaUnsMas_blue.getStepsAmount() / devideStepsByFactorForSecondSearch);

		unsharpMasking_BGR_parallel unsharpMasking_24_Second;
		unsharpMasking_24_Second.setParameterUM_blue(mParaUnsMas_blue);
		unsharpMasking_24_Second.setParameterUM_green(mParaUnsMas_green);
		unsharpMasking_24_Second.setParameterUM_red(mParaUnsMas_red);

		unsharpMasking_24_Second.improveImaQual_UnsharpMasking_superFct_BGR_parallel(mInputIma, tempFilteredImages);
		tempFilteredImages = unsharpMasking_24_Second.getFilteredResults_normedZeroAndMaxUchar();

		mBestParaUnsMas_blue = unsharpMasking_24_Second.getBestParameter_blue();
		mBestParaUnsMas_green = unsharpMasking_24_Second.getBestParameter_green();
		mBestParaUnsMas_red = unsharpMasking_24_Second.getBestParameter_red();
		
		// save filtered images UM
		mAllFilteredImages_UM_DE_WD[0] = tempFilteredImages.clone();
		// _________________________________________________________

		// detail enhancement
		// _________________________________________________________
		DetailEnhancement_BGR_parallel detailEnhancement_BGR_24_First;
		detailEnhancement_BGR_24_First.setParameter_global(mParaDetEnh);

		detailEnhancement_BGR_24_First.improveImageQuality_DetailEnhancement_BGR_parallel(mInputIma, tempFilteredImages.clone());
		tempFilteredImages = detailEnhancement_BGR_24_First.getFilteredIma();
		mBestParaDetEnh = detailEnhancement_BGR_24_First.getBestParameter();

		reinitializeBestParaDetEng(reinizializePrecent, mParaDetEnh.getStepsSigma_r() / devideStepsByFactorForSecondSearch, mParaDetEnh.getStepsSigma_s() / devideStepsByFactorForSecondSearch);
		
		DetailEnhancement_BGR_parallel detailEnhancement_BGR_24_Second;
		detailEnhancement_BGR_24_Second.setParameter_global(mParaDetEnh);
		detailEnhancement_BGR_24_Second.improveImageQuality_DetailEnhancement_BGR_parallel(mInputIma, tempFilteredImages.clone());

		tempFilteredImages = detailEnhancement_BGR_24_Second.getFilteredIma();
		mBestParaDetEnh = detailEnhancement_BGR_24_Second.getBestParameter();
		
		mAllFilteredImages_UM_DE_WD[1] = tempFilteredImages.clone();
		// _________________________________________________________

		// wiener deconvolution
		// _________________________________________________________
		WienerDeconvolutionSF_parallel_BGR wienerDeconParallelBGR_First;
		wienerDeconParallelBGR_First.setParameterWD_Global_blue(mParaWD_blue);
		wienerDeconParallelBGR_First.setParameterWD_Global_green(mParaWD_green);
		wienerDeconParallelBGR_First.setParameterWD_Global_red(mParaWD_red);

		wienerDeconParallelBGR_First.improveImaQual_WD_superFct_BGR_parallel(mInputIma, tempFilteredImages);
		tempFilteredImages = wienerDeconParallelBGR_First.getFilteredResults_normedZeroAndMaxUchar();
		mBestParaWD_blue = wienerDeconParallelBGR_First.getBestParameter_blue();
		mBestParaWD_green = wienerDeconParallelBGR_First.getBestParameter_green();
		mBestParaWD_red = wienerDeconParallelBGR_First.getBestParameter_red();


		reinitializeBestParaWD(reinizializePrecent, mParaWD_blue.getStepsSNR() / devideStepsByFactorForSecondSearch, mParaWD_blue.getStepsSigmaXY() / devideStepsByFactorForSecondSearch);
		
		WienerDeconvolutionSF_parallel_BGR wienerDeconParallelBGR_Second;
		wienerDeconParallelBGR_Second.improveImaQual_WD_superFct_BGR_parallel(mInputIma, tempFilteredImages);
		
		mBestParaWD_blue = wienerDeconParallelBGR_Second.getBestParameter_blue();
		mBestParaWD_green = wienerDeconParallelBGR_Second.getBestParameter_green();
		mBestParaWD_red = wienerDeconParallelBGR_Second.getBestParameter_red();

		mFilteredIma = wienerDeconParallelBGR_Second.getFilteredResults_normedZeroAndMaxUchar();

		mAllFilteredImages_UM_DE_WD[2] = mFilteredIma.clone();
		// _________________________________________________________
	}


}

// reload parameter according to best parameter
void ImaProcSuperFct::reloadParameterAccordingToBestParameter_WD(real variancePercent)
{
	if (mImaProc == imageProcessing::wienerFilter || mImaProc == imageProcessing::wienerFilter24)
	{
		// blue
		real bestSigma_blue = mBestParaWD_blue.getBestSigma();
		real bestSNR_blue = mBestParaWD_blue.getBestSNR();

		real newMinSigma_blue = (100.0 - variancePercent) * bestSigma_blue / 100.0;
		real newMaxSigma_blue = (100.0 + variancePercent) * bestSigma_blue / 100.0;
		real newMinSNR_blue = (100.0 - variancePercent) * bestSNR_blue / 100.0;
		real newMaxSNR_blue = (100.0 + variancePercent) * bestSNR_blue / 100.0;

		mParaWD_blue.setMinSigmaXY(newMinSigma_blue);
		mParaWD_blue.setMaxSigmaXY(newMaxSigma_blue);
		mParaWD_blue.setMinSNR(newMinSNR_blue);
		mParaWD_blue.setMaxSNR(newMaxSNR_blue);

		// green
		real bestSigma_green = mBestParaWD_green.getBestSigma();
		real bestSNR_green = mBestParaWD_green.getBestSNR();

		real newMinSigma_green = (100.0 - variancePercent) * bestSigma_green / 100.0;
		real newMaxSigma_green = (100.0 + variancePercent) * bestSigma_green / 100.0;
		real newMinSNR_green = (100.0 - variancePercent) * bestSNR_green / 100.0;
		real newMaxSNR_green = (100.0 + variancePercent) * bestSNR_green / 100.0;

		mParaWD_green.setMinSigmaXY(newMinSigma_green);
		mParaWD_green.setMaxSigmaXY(newMaxSigma_green);
		mParaWD_green.setMinSNR(newMinSNR_green);
		mParaWD_green.setMaxSNR(newMaxSNR_green);

		// red
		real bestSigma_red = mBestParaWD_red.getBestSigma();
		real bestSNR_red = mBestParaWD_red.getBestSNR();

		real newMinSigma_red = (100.0 - variancePercent) * bestSigma_red / 100.0;
		real newMaxSigma_red = (100.0 + variancePercent) * bestSigma_red / 100.0;
		real newMinSNR_red = (100.0 - variancePercent) * bestSNR_red / 100.0;
		real newMaxSNR_red = (100.0 + variancePercent) * bestSNR_red / 100.0;

		mParaWD_red.setMinSigmaXY(newMinSigma_red);
		mParaWD_red.setMaxSigmaXY(newMaxSigma_red);
		mParaWD_red.setMinSNR(newMinSNR_red);
		mParaWD_red.setMaxSNR(newMaxSNR_red);
	}
}

cv::Mat ImaProcSuperFct::getInputIma()
{
	return mInputIma;
}
cv::Mat ImaProcSuperFct::getBlueredIma()
{
	return mBlueredIma;
}

cv::Mat ImaProcSuperFct::getFilteredIma()
{
	return mFilteredIma;
}
std::vector<cv::Mat> ImaProcSuperFct::getAllFilteredImages_UM_DE_WD()
{
	return mAllFilteredImages_UM_DE_WD;
}

// wiener filter
void ImaProcSuperFct::setParameterWD_blue(parameterImaImprove_WD paraWD_blue)
{
	mParaWD_blue = paraWD_blue;
}
void ImaProcSuperFct::setParameterWD_green(parameterImaImprove_WD paraWD_green)
{
	mParaWD_green = paraWD_green;
}
void ImaProcSuperFct::setParameterWD_red(parameterImaImprove_WD paraWD_red)
{
	mParaWD_red = paraWD_red;
}
parameterImaImprove_WD ImaProcSuperFct::getParameterWD_blue()
{
	return mParaWD_blue;
}
parameterImaImprove_WD ImaProcSuperFct::getParameterWD_green()
{
	return mParaWD_green;
}
parameterImaImprove_WD ImaProcSuperFct::getParameterWD_red()
{
	return mParaWD_red;
}
saveBestParameterWD ImaProcSuperFct::getBestParaWD_blue()
{
	return mBestParaWD_blue;
}
saveBestParameterWD ImaProcSuperFct::getBestParaWD_green()
{
	return mBestParaWD_green;
}
saveBestParameterWD ImaProcSuperFct::getBestParaWD_red()
{
	return mBestParaWD_red;
}
void ImaProcSuperFct::reinitializeBestParaWD(real percent, real stepsSNR, real stepsSigma)
{	
	// *** SNR _blue *** //
	real tempBestSNR_blue = mBestParaWD_blue.getBestSNR();
	real minSNR_blue = (tempBestSNR_blue * (100.0 - percent)) / 100.0;
	real maxSNR_blue = (tempBestSNR_blue * (100.0 + percent)) / 100.0;
	mParaWD_blue.setMinSNR(minSNR_blue);
	mParaWD_blue.setMaxSNR(maxSNR_blue);
	mParaWD_blue.setStepsSNR(stepsSNR);

	// *** SNR _green *** //
	real tempBestSNR_green = mBestParaWD_green.getBestSNR();
	real minSNR_green = (tempBestSNR_green * (100.0 - percent)) / 100.0;
	real maxSNR_green = (tempBestSNR_green * (100.0 + percent)) / 100.0;
	mParaWD_green.setMinSNR(minSNR_green);
	mParaWD_green.setMaxSNR(maxSNR_green);
	mParaWD_green.setStepsSNR(stepsSNR);

	// *** SNR _red *** //
	real tempBestSNR_red = mBestParaWD_red.getBestSNR();
	real minSNR_red = (tempBestSNR_red * (100.0 - percent)) / 100.0;
	real maxSNR_red = (tempBestSNR_red * (100.0 + percent)) / 100.0;
	mParaWD_red.setMinSNR(minSNR_red);
	mParaWD_red.setMaxSNR(maxSNR_red);
	mParaWD_red.setStepsSNR(stepsSNR);

	// *** sigma _blue *** //
	real tempBestSigma_blue = mBestParaWD_blue.getBestSigma();
	real minSigma_blue = (tempBestSigma_blue * (100.0 - percent)) / 100.0;
	real maxSigma_blue = (tempBestSigma_blue * (100.0 + percent)) / 100.0;
	mParaWD_blue.setMinSigmaXY(minSigma_blue);
	mParaWD_blue.setMaxSigmaXY(maxSigma_blue);
	mParaWD_blue.setStepsSigmaXY(stepsSigma);

	// *** sigma _green *** //
	real tempBestSigma_green = mBestParaWD_green.getBestSigma();
	real minSigma_green = (tempBestSigma_green * (100.0 - percent)) / 100.0;
	real maxSigma_green = (tempBestSigma_green * (100.0 + percent)) / 100.0;
	mParaWD_green.setMinSigmaXY(minSigma_green);
	mParaWD_green.setMaxSigmaXY(maxSigma_green);
	mParaWD_green.setStepsSigmaXY(stepsSigma);

	// *** sigma _red *** //
	real tempBestSigma_red = mBestParaWD_red.getBestSigma();
	real minSigma_red = (tempBestSigma_red * (100.0 - percent)) / 100.0;
	real maxSigma_red = (tempBestSigma_red * (100.0 + percent)) / 100.0;
	mParaWD_red.setMinSigmaXY(minSigma_red);
	mParaWD_red.setMaxSigmaXY(maxSigma_red);
	mParaWD_red.setStepsSigmaXY(stepsSigma);

}


// *** unsharp masking ***
void ImaProcSuperFct::setParameterUnsMas_blue(parameterUnsharpMasking paraUnsMas_blue)
{
	mParaUnsMas_blue = paraUnsMas_blue;
}
void ImaProcSuperFct::setParameterUnsMas_green(parameterUnsharpMasking paraUnsMas_green)
{
	mParaUnsMas_green = paraUnsMas_green;
}
void ImaProcSuperFct::setParameterUnsMas_red(parameterUnsharpMasking paraUnsMas_red)
{
	mParaUnsMas_red = paraUnsMas_red;
}
void ImaProcSuperFct::setParameterUnsMas_gray(parameterUnsharpMasking paraUnsMas_gray)
{
	mParaUnsMas_gray = paraUnsMas_gray;
}
parameterUnsharpMasking ImaProcSuperFct::getParameterUnsMas_blue()
{
	return mParaUnsMas_gray;
}
parameterUnsharpMasking ImaProcSuperFct::getParameterUnsMas_green()
{
	return mParaUnsMas_green;
}
parameterUnsharpMasking ImaProcSuperFct::getParameterUnsMas_red()
{
	return mParaUnsMas_red;
}
parameterUnsharpMasking ImaProcSuperFct::getParameterUnsMas_gray()
{
	return mParaUnsMas_gray;
}
bestParameterStruct_unsharpMask ImaProcSuperFct::getBestParaUnsMas_blue()
{
	return mBestParaUnsMas_blue;
}
bestParameterStruct_unsharpMask ImaProcSuperFct::getBestParaUnsMas_green()
{
	return mBestParaUnsMas_green;
}
bestParameterStruct_unsharpMask ImaProcSuperFct::getBestParaUnsMas_red()
{
	return mBestParaUnsMas_red;
}
bestParameterStruct_unsharpMask ImaProcSuperFct::getBestParaUnsMas_gray()
{
	return mBestParaUnsMas_gray;
}
void ImaProcSuperFct::reinitializeBestParaUnsMas(real percent, real stepsSigma, real stepsThreshold, real stepsAmount)
{
	// *** sigma _blue ***
	real temBestSigma_blue = mBestParaUnsMas_blue.getSigma();
	real minSigma_blue = (temBestSigma_blue * (100.0 - percent)) / 100.0;
	real maxSigma_blue = (temBestSigma_blue * (100.0 + percent)) / 100.0;
	mParaUnsMas_blue.setMinSigma(minSigma_blue);
	mParaUnsMas_blue.setMaxSigma(maxSigma_blue);
	mParaUnsMas_blue.setStepsSigma(stepsSigma);

	// *** sigma _green ***
	real temBestSigma_green = mBestParaUnsMas_green.getSigma();
	real minSigma_green = (temBestSigma_green * (100.0 - percent)) / 100.0;
	real maxSigma_green = (temBestSigma_green * (100.0 + percent)) / 100.0;
	mParaUnsMas_green.setMinSigma(minSigma_green);
	mParaUnsMas_green.setMaxSigma(maxSigma_green);
	mParaUnsMas_green.setStepsSigma(stepsSigma);

	// *** sigma _red ***
	real temBestSigma_red = mBestParaUnsMas_red.getSigma();
	real minSigma_red = (temBestSigma_red * (100.0 - percent)) / 100.0;
	real maxSigma_red = (temBestSigma_red * (100.0 + percent)) / 100.0;
	mParaUnsMas_red.setMinSigma(minSigma_red);
	mParaUnsMas_red.setMaxSigma(maxSigma_red);
	mParaUnsMas_red.setStepsSigma(stepsSigma);

	// *** threshold _blue ***
	real tempBestThreshold_blue = mBestParaUnsMas_blue.getThreshold();
	real minThreshold_blue = (tempBestThreshold_blue * (100.0 - percent)) / 100.0;
	real maxThreshold_blue = (tempBestThreshold_blue * (100.0 + percent)) / 100.0;
	mParaUnsMas_blue.setMinThreshold(minThreshold_blue);
	mParaUnsMas_blue.setMaxThreshold(maxThreshold_blue);
	mParaUnsMas_blue.setStepsThreshold(stepsThreshold);

	// *** threshold _green ***
	real tempBestThreshold_green = mBestParaUnsMas_green.getThreshold();
	real minThreshold_green = (tempBestThreshold_green * (100.0 - percent)) / 100.0;
	real maxThreshold_green = (tempBestThreshold_green * (100.0 + percent)) / 100.0;
	mParaUnsMas_green.setMinThreshold(minThreshold_green);
	mParaUnsMas_green.setMaxThreshold(maxThreshold_green);
	mParaUnsMas_green.setStepsThreshold(stepsThreshold);

	// *** threshold _red ***
	real tempBestThreshold_red = mBestParaUnsMas_red.getThreshold();
	real minThreshold_red = (tempBestThreshold_red * (100.0 - percent)) / 100.0;
	real maxThreshold_red = (tempBestThreshold_red * (100.0 + percent)) / 100.0;
	mParaUnsMas_red.setMinThreshold(minThreshold_red);
	mParaUnsMas_red.setMaxThreshold(maxThreshold_red);
	mParaUnsMas_red.setStepsThreshold(stepsThreshold);

	// *** amount _blue ***
	real tempBestAmount_blue = mBestParaUnsMas_blue.getAmount();
	real minAmount_blue = (tempBestAmount_blue * (100.0 - percent)) / 100.0;
	real maxAmount_blue = (tempBestAmount_blue * (100.0 + percent)) / 100.0;
	mParaUnsMas_blue.setMinAmount(minAmount_blue);
	mParaUnsMas_blue.setMaxAmount(maxAmount_blue);
	mParaUnsMas_blue.setStepsAmount(stepsAmount);

	// *** amount _green ***
	real tempBestAmount_green = mBestParaUnsMas_green.getAmount();
	real minAmount_green = (tempBestAmount_green * (100.0 - percent)) / 100.0;
	real maxAmount_green = (tempBestAmount_green * (100.0 + percent)) / 100.0;
	mParaUnsMas_green.setMinAmount(minAmount_green);
	mParaUnsMas_green.setMaxAmount(maxAmount_green);
	mParaUnsMas_green.setStepsAmount(stepsAmount);

	// *** amount _red ***
	real tempBestAmount_red = mBestParaUnsMas_red.getAmount();
	real minAmount_red = (tempBestAmount_red * (100.0 - percent)) / 100.0;
	real maxAmount_red = (tempBestAmount_red * (100.0 + percent)) / 100.0;
	mParaUnsMas_red.setMinAmount(minAmount_red);
	mParaUnsMas_red.setMaxAmount(maxAmount_red);
	mParaUnsMas_red.setStepsAmount(stepsAmount);

}
// *** ***

void ImaProcSuperFct::reinitializeBestParaUnsMas_gray(real percent, real stepsSigma, real stepsThreshold, real stepsAmount)
{
	// *** sigma _gray ***
	real temBestSigma_gray = mBestParaUnsMas_gray.getSigma();
	real minSigma_gray = (temBestSigma_gray * (100.0 - percent)) / 100.0;
	real maxSigma_gray = (temBestSigma_gray * (100.0 + percent)) / 100.0;
	mParaUnsMas_gray.setMinSigma(minSigma_gray);
	mParaUnsMas_gray.setMaxSigma(maxSigma_gray);
	mParaUnsMas_gray.setStepsSigma(stepsSigma);

	// *** threshold _gray ***
	real tempBestThreshold_gray = mBestParaUnsMas_gray.getThreshold();
	real minThreshold_gray = (tempBestThreshold_gray * (100.0 - percent)) / 100.0;
	real maxThreshold_gray = (tempBestThreshold_gray * (100.0 + percent)) / 100.0;
	mParaUnsMas_gray.setMinThreshold(minThreshold_gray);
	mParaUnsMas_gray.setMaxThreshold(maxThreshold_gray);
	mParaUnsMas_gray.setStepsThreshold(stepsThreshold);

	// *** amount _gray ***
	real tempBestAmount_gray = mBestParaUnsMas_gray.getAmount();
	real minAmount_gray = (tempBestAmount_gray * (100.0 - percent)) / 100.0;
	real maxAmount_gray = (tempBestAmount_gray * (100.0 + percent)) / 100.0;
	mParaUnsMas_gray.setMinAmount(minAmount_gray);
	mParaUnsMas_gray.setMaxAmount(maxAmount_gray);
	mParaUnsMas_gray.setStepsAmount(stepsAmount);
}

// *** detail enhancement ***
void ImaProcSuperFct::setParameterDetEnh(parameterDetailEnhancement paraDetEnh)
{
	mParaDetEnh = paraDetEnh;
}
parameterDetailEnhancement ImaProcSuperFct::getParameterDetEnh()
{
	return mParaDetEnh;
}
bestParameterStruct_detailEnhance ImaProcSuperFct::getBestParaDetEnh()
{
	return mBestParaDetEnh;
}
void ImaProcSuperFct::reinitializeBestParaDetEng(real percent, real stepsSigma_r, real stepsSigma_s)
{
	// *** sigma_r ***
	real temBestSigma_r = mBestParaDetEnh.getSigmar_r();
	real minSigma_r = (temBestSigma_r * (100.0 - percent)) / 100.0;
	real maxSigma_r = (temBestSigma_r * (100.0 + percent)) / 100.0;
	mParaDetEnh.setMinSigma_r(minSigma_r);
	mParaDetEnh.setMaxSigma_r(maxSigma_r);
	mParaDetEnh.setStepsSigma_r(stepsSigma_r);

	// *** sigma_s ***
	real temBestSigma_s = mBestParaDetEnh.getSigmar_s();
	real minSigma_s = (temBestSigma_s * (100.0 - percent)) / 100.0;
	real maxSigma_s = (temBestSigma_s * (100.0 + percent)) / 100.0;
	mParaDetEnh.setMinSigma_s(minSigma_s);
	mParaDetEnh.setMaxSigma_s(maxSigma_s);
	mParaDetEnh.setStepsSigma_s(stepsSigma_s);

}
// *** ***

// *** remove chromatic aberrations ***
void ImaProcSuperFct::setParameterRemoveChromAber(initialPararemChromAber parameterRemovChromAber)
{
	mParaRemoChroAber = parameterRemovChromAber;
}
initialPararemChromAber ImaProcSuperFct::getParameterRemoveChromAber()
{
	return mParaRemoChroAber;
}
bestParaRemChromAber ImaProcSuperFct::getBestParaRemoveChromAber()
{
	return mBestParaRemoChroAber;
}
void ImaProcSuperFct::reinitalizeBestParaRemoChromAber(real percent, real stepsThreshold)
{
	// *** threshold ***
	real tempThreshold = mBestParaRemoChroAber.getThreshold();
	real minThreshold = (tempThreshold * (100.0 - percent)) / 100.0;
	real maxThreshold = (tempThreshold * (100.0 + percent)) / 100.0;
	mParaRemoChroAber.setMinThreshold(minThreshold);
	mParaRemoChroAber.setMaxThreshold(maxThreshold);
	mParaRemoChroAber.setStepsThreshold(stepsThreshold);
}
// *** ***

// Brightness and contrast adjustments
// see https://docs.opencv.org/3.4/d3/dc1/tutorial_basic_linear_transform.html
cv::Mat ImageProcessing::brighContrastAdjust(cv::Mat const& image, real const& alpha, int const& beta)
{
	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());
	image.convertTo(new_image, -1, alpha, beta);

	return new_image;
}

// Correct an underexposed image -> Gamma correction
// https://docs.opencv.org/3.4/d3/dc1/tutorial_basic_linear_transform.html
// more informations: https://learnopengl.com/Advanced-Lighting/Gamma-Correction
cv::Mat ImageProcessing::gammaCorrection(cv::Mat const& image, real const& gamma)
{
	cv::Mat lookUpTable(1, 256, CV_8U);
	uchar* p = lookUpTable.ptr();
	for (int i = 0; i < 256; ++i)
		p[i] = cv::saturate_cast<uchar>(pow(i / 255.0, gamma) * 255.0);
	cv::Mat result = image.clone();
	cv::LUT(image, lookUpTable, result);


	return result;
}

// bilateralFilter
	//can reduce unwanted noise very well while keeping edges fairly sharp.However, it is very slow compared to most filters.
	// https://www.tutorialspoint.com/opencv/opencv_bilateral_filter.htm
cv::Mat ImageProcessing::bilateralFilter(cv::Mat const& image, int const& pixelNeighborhood, int const& sigmaColor, int const& sigmaSpace, int const& borderType)
{
	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());
	cv::bilateralFilter(image, new_image, pixelNeighborhood, sigmaColor, sigmaSpace, borderType);

	return new_image;
}

// boxFilter
// Blurs an image using the box filter.
// https://www.tutorialspoint.com/opencv/opencv_box_filter.htm
cv::Mat ImageProcessing::boxFilter(cv::Mat const& image, int const& depthOutputImage, cv::Size const& ksize, cv::Point const& point, bool const& normalize, int const& borderType)
{
	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());
	cv::boxFilter(image, new_image, depthOutputImage, ksize, point, true, borderType);

	return new_image;
}

// erosion
cv::Mat ImageProcessing::erosion(cv::Mat const& image,/*erosion type*/ int erosionType,/*kernel size*/ cv::Size  const& ksize,/*anchor point*/ cv::Point const& point)
{
	
	
	if (erosionType == 0) { erosionType = cv::MORPH_RECT; }
	else if (erosionType == 1) { erosionType = cv::MORPH_CROSS; }
	else if (erosionType == 2) { erosionType = cv::MORPH_ELLIPSE; }

	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());

	// build the element fpr erosion
	cv::Mat element = cv::getStructuringElement(erosionType, ksize, point);

	cv::erode(image, new_image, element);

	return new_image;

}

// dilation
cv::Mat ImageProcessing::dilation(cv::Mat const& image,/*erosion type*/ int erosionType,/*kernel size*/ cv::Size  const& ksize,/*anchor point*/ cv::Point const& point)
{
	if (erosionType == 0) { erosionType = cv::MORPH_RECT; }
	else if (erosionType == 1) { erosionType = cv::MORPH_CROSS; }
	else if (erosionType == 2) { erosionType = cv::MORPH_ELLIPSE; }

	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());

	// build the element fpr erosion
	cv::Mat element = cv::getStructuringElement(erosionType, ksize, point);

	cv::dilate(image, new_image, element);

	return new_image;
}

//correct distortion of an image
cv::Mat ImageProcessing::correctDistortion(cv::Mat const& image, cv::Mat const& calibrationImage, int const& numCornersHor, int const& numCornersVer) 
{
	int numSquares = numCornersHor * numCornersVer;
	cv::Size board_sz = cv::Size(numCornersHor, numCornersVer);
			

	std::vector<cv::Point3f> obj;
	for (int j = 0; j < numSquares; j++)
		obj.push_back(cv::Point3f(j / numCornersHor, j%numCornersHor, 0.0f));

	cv::Mat gray_image;
	cv::cvtColor(calibrationImage, gray_image, CV_BGR2GRAY);
	
	std::vector<cv::Point2f> corners;
	// looking for chessboard corners
	bool found = cv::findChessboardCorners(calibrationImage, board_sz, corners, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS);

	std::vector<std::vector<cv::Point3f>> object_points;
	std::vector<std::vector<cv::Point2f>> image_points_calibration;
	if (found == 1)
	{
		cv::cornerSubPix(gray_image, corners, cv::Size(11, 11), cv::Size(0, 0), cv::TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 30, 0.1));
		cv::drawChessboardCorners(gray_image, board_sz, corners, found);

		image_points_calibration.push_back(corners);
		object_points.push_back(obj);

	}

	else // we did not find the corners
	{
		std::cout << "we did not find the cornders of the chessboard" << std::endl;
		// error and stop the program
		oftenUse::errorProtocol_stopSystem("we did not find the cornders of the chessboard", "ImageProcessing.cpp", 0, true);
	}
	

	cv::Mat intrinsic = cv::Mat(3, 3, CV_64FC1);
	cv::Mat distCoeffs;
	std::vector<cv::Mat> rvecs;
	std::vector<cv::Mat> tvecs;
	intrinsic.ptr<float>(0)[0] = 1;
	intrinsic.ptr<float>(1)[1] = 1;


	cv::calibrateCamera(object_points, image_points_calibration, calibrationImage.size(), intrinsic, distCoeffs, rvecs, tvecs);
	
	// undistor the image
	cv::Mat distortionFreeImage;
	cv::undistort(image, distortionFreeImage, intrinsic, distCoeffs);

	
	return distortionFreeImage;
}


// Detail Enhancing Filter

void ImageProcessing::detailEnhancin(const cv::Mat& image, cv::Mat& detailEnhanceImage, float sigma_s, float sigma_r)
{	
	//// debug
	//int typeIma = image.type();
	//int typeDetal = detailEnhanceImage.type();

	cv::detailEnhance(image, detailEnhanceImage, sigma_s, sigma_r);
}


// laplacian
// see: https://docs.opencv.org/3.4/d5/db5/tutorial_laplace_operator.html
cv::Mat ImageProcessing::laplacian(cv::Mat const& image, int const& ddepth, int const& kernel_size, int const& scale, int const& delta)
{
	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());
	cv::Mat return_new_image = cv::Mat::zeros(image.size(), image.type());

	cv::Laplacian(image, new_image, ddepth, kernel_size, scale, delta, cv::BORDER_DEFAULT);
	//converting back to CV_8U
	cv::convertScaleAbs(new_image, return_new_image);

	return return_new_image;
}

// canny
	// see: https://docs.opencv.org/2.4/doc/tutorials/imgproc/imgtrans/canny_detector/canny_detector.html
cv::Mat ImageProcessing::canny(cv::Mat const& image, real const& lowThreshold, real const& heightThreshold, int const& apertureSize, bool const& L2gradient)
{

	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());
	cv::Canny(image, new_image, lowThreshold, heightThreshold, apertureSize, L2gradient);

	return new_image;

}

// sobel
	// see: https://docs.opencv.org/2.4/doc/tutorials/imgproc/imgtrans/sobel_derivatives/sobel_derivatives.html
cv::Mat ImageProcessing::sobel(cv::Mat image, int const& ddepth, int const& dx, int const& dy, int const& ksize, double const& scale, double const& delta, int const& borderType)
{
	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());
	cv::Sobel(image, new_image, ddepth, dx, dy, ksize, scale, delta, borderType);

	return new_image;

}


// unsharp mask
// see: https://docs.opencv.org/master/d1/d10/classcv_1_1MatExpr.html#details
cv::Mat	ImageProcessing::unsharpMask(const cv::Mat& image, cv::Size kernelSize, const double sigmaX, const double sigmaY, int borderType, const double threshold, const double amount)
{

	cv::Mat blurred;
	cv::GaussianBlur(image, blurred, kernelSize, sigmaX, sigmaY);
	cv::Mat lowContrastMask = abs(image - blurred) < threshold;
	cv::Mat sharpened = image * (1 + amount) + blurred * (-amount);
	image.copyTo(sharpened, lowContrastMask);

  	return sharpened;

}

// bilateralFilter 
	// see: https://docs.opencv.org/3.0-beta/modules/imgproc/doc/filtering.html
cv::Mat ImageProcessing::bilateralFilter(cv::Mat const& image, int const& d, double const& sigmarColor, double const& sigmarSpace, int const& boarderType)
{
	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());

	cv::bilateralFilter(image, new_image, d, sigmarColor, sigmarSpace, boarderType);
	return new_image;
}

// median blur
	// see: https://docs.opencv.org/3.3.1/d4/d86/group__imgproc__filter.html#ga564869aa33e58769b4469101aac458f9
	// see: https://docs.opencv.org/3.1.0/d4/d13/tutorial_py_filtering.html
	// The function smoothes an image using the median filter with the ksize×ksize aperture.
	// Each channel of a multi-channel image is processed independently. In-place operation is supported
cv::Mat ImageProcessing::MedianBlurFilter(cv::Mat const& image, int const& ksize)
{
	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());

	cv::medianBlur(image, new_image, ksize);

	return new_image;
}


