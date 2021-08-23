#include "WienerDeconvolutioinSuperFuction.h"

#include "..\oftenUseNamespace\oftenUseNamespace.h"



WienerDeconvolutionSuperFunction::WienerDeconvolutionSuperFunction()
{
	loadBasicParameterBGR();
}

WienerDeconvolutionSuperFunction::~WienerDeconvolutionSuperFunction() {}


void WienerDeconvolutionSuperFunction::splitColorImageInChannels()
{
	// sharp image
	cv::Mat channelSharpImage[3];
	cv::split(mSharpColorImage, channelSharpImage);
	mImageSharp_blue = channelSharpImage[0];
	mImageSharp_green = channelSharpImage[1];
	mImageSharp_red = channelSharpImage[2];

	// bluered image
	cv::Mat channelBluredImage[3];
	cv::split(mBlueredColorImage, channelBluredImage);
	mBluredIma_blue = channelBluredImage[0];
	mBluredIma_green = channelBluredImage[1];
	mBluredIma_red = channelBluredImage[2];

	//// debug
	//Images::showImage_inputUint8("sharpIma", mImageSharp_blue);
	//Images::showImage_inputUint8("blueredpIma", mBluredIma_blue);
}

void WienerDeconvolutionSuperFunction::loadBasicParameterBGR()
{
	// blue
	mParaImaImproveWD_blue.setMinSNR(1.0);
	mParaImaImproveWD_blue.setMaxSNR(100.0);
	mParaImaImproveWD_blue.setStepsSNR(100.0);
	mParaImaImproveWD_blue.setMinSigmaXY(1.0);
	mParaImaImproveWD_blue.setMaxSigmaXY(5.0);
	mParaImaImproveWD_blue.setStepsSigmaXY(10.0);
	mParaImaImproveWD_blue.setKernelSizeHeightAndWidth(30);
	mParaImaImproveWD_blue.setCompareInPercent(7.0);

	// green
	mParaImaImproveWD_green.setMinSNR(1.0);
	mParaImaImproveWD_green.setMaxSNR(100.0);
	mParaImaImproveWD_green.setStepsSNR(100.0);
	mParaImaImproveWD_green.setMinSigmaXY(1.0);
	mParaImaImproveWD_green.setMaxSigmaXY(5.0);
	mParaImaImproveWD_green.setStepsSigmaXY(10.0);
	mParaImaImproveWD_green.setKernelSizeHeightAndWidth(30);
	mParaImaImproveWD_green.setCompareInPercent(7.0);

	// red
	mParaImaImproveWD_red.setMinSNR(1.0);
	mParaImaImproveWD_red.setMaxSNR(100.0);
	mParaImaImproveWD_red.setStepsSNR(100.0);
	mParaImaImproveWD_red.setMinSigmaXY(1.0);
	mParaImaImproveWD_red.setMaxSigmaXY(5.0);
	mParaImaImproveWD_red.setStepsSigmaXY(10.0);
	mParaImaImproveWD_red.setKernelSizeHeightAndWidth(30);
	mParaImaImproveWD_red.setCompareInPercent(7.0);

}

// improve image quality 
void WienerDeconvolutionSuperFunction::improveImaQual_WD_superFct(const cv::Mat sharpColorImage, const cv::Mat blueredColorImage)
{
	mSharpColorImage = sharpColorImage;
	mBlueredColorImage = blueredColorImage;

	// split the image in RGB
	splitColorImageInChannels();

	WD_blue.setBasicParameter(mParaImaImproveWD_blue);
	WD_green.setBasicParameter(mParaImaImproveWD_green);
	WD_red.setBasicParameter(mParaImaImproveWD_red);

	WD_blue.improveImaQual_WD_superFct_gray(mImageSharp_blue, mBluredIma_blue);
	WD_green.improveImaQual_WD_superFct_gray(mImageSharp_green, mBluredIma_green); 
	WD_red.improveImaQual_WD_superFct_gray(mImageSharp_red, mBluredIma_red);

	mBestParameter_blue = WD_blue.getBestParameter();
	mBestParameter_green = WD_green.getBestParameter();
	mBestParameter_red = WD_red.getBestParameter();

	// put images together
	putImageChannelsTogether();

}



// get filtered image
cv::Mat WienerDeconvolutionSuperFunction::getFilteredImage()
{
	return mFilterResultIma_BGR;
}




void WienerDeconvolutionSuperFunction::putImageChannelsTogether()
{
	std::vector<cv::Mat> array_to_merge;

	array_to_merge.push_back(mBestParameter_blue.getBestReconstruction());
	array_to_merge.push_back(mBestParameter_green.getBestReconstruction());
	array_to_merge.push_back(mBestParameter_red.getBestReconstruction());

	cv::merge(array_to_merge, mFilterResultIma_BGR);
}


// get best parameter 
saveBestParameterWD WienerDeconvolutionSuperFunction::getBestParameter_blue()
{
	return mBestParameter_blue;
}
saveBestParameterWD WienerDeconvolutionSuperFunction::getBestParameter_green()
{
	return mBestParameter_green;
}
saveBestParameterWD WienerDeconvolutionSuperFunction::getBestParameter_red()
{
	return mBestParameter_red;
}

parameterImaImprove_WD WienerDeconvolutionSuperFunction::getParameter_blue()
{
	return mParaImaImproveWD_blue;
}
void WienerDeconvolutionSuperFunction::setParameter_blue(parameterImaImprove_WD para_blue)
{
	mParaImaImproveWD_blue = para_blue;
}

parameterImaImprove_WD WienerDeconvolutionSuperFunction::getParameter_green()
{
	return mParaImaImproveWD_green;
}
void WienerDeconvolutionSuperFunction::setParameter_green(parameterImaImprove_WD para_green)
{
	mParaImaImproveWD_green = para_green;
}
parameterImaImprove_WD WienerDeconvolutionSuperFunction::getParameter_red()
{
	return mParaImaImproveWD_red;
}
void WienerDeconvolutionSuperFunction::setParameter_red(parameterImaImprove_WD para_red)
{
	mParaImaImproveWD_red = para_red;
}