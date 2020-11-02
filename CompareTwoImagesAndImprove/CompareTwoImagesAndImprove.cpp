#include "CompareTwoImagesAndImprove.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include "..\Image\ImproveImageQuality.h"
#include "..\Image\Images.h"

QualityAndImageStruct::QualityAndImageStruct() {};
QualityAndImageStruct::QualityAndImageStruct(real const& quality, cv::Mat const& image, real const& improvement) :
	mImage(image),
	mQuality(quality),
	mImprovement(improvement)
{}
QualityAndImageStruct::~QualityAndImageStruct() {};


// set quality
void QualityAndImageStruct::setQuality(real const& quality)
{
	mQuality = quality;
}
// get quality
real QualityAndImageStruct::getQuality() const&
{
	return mQuality;
}
// set image
void QualityAndImageStruct::setImage(cv::Mat const& image)
{
	mImage = image;
}
// get image
cv::Mat QualityAndImageStruct::getImage() const&
{
	return mImage;
}

// set improvement
void QualityAndImageStruct::setImprovement(real const& improvement)
{
	mImprovement = improvement;
}
// get improvement
real QualityAndImageStruct::getImprovement() const&
{
	return mImprovement;
}

// print parameters quality and image struct
void QualityAndImageStruct::printPara_QualityAndImaga_Struct() const &
{
	std::cout << "" << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "QualityAndImageStruct" << std::endl;
	std::cout << "quality: " << mQuality << std::endl;
	std::cout << "improvement " << mImprovement << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "" << std::endl;
}


CompareTwoImagesAndImprove::CompareTwoImagesAndImprove() {}
CompareTwoImagesAndImprove::~CompareTwoImagesAndImprove() {}

CompareTwoImagesAndImprove::CompareTwoImagesAndImprove(cv::Mat simulatedImage, cv::Mat sharpImage, cv::Mat simulatedCalibrationImage) :
	mSimulatedCalibrationImage(simulatedCalibrationImage)
{
	// resize the simulated image
	mSimulatedImage = Images::resizeImage(simulatedImage, simulatedCalibrationImage.size(), 0.0, 0.0, cv::INTER_LINEAR);
	mSharpImage = Images::resizeImage(sharpImage, simulatedCalibrationImage.size(), 0.0, 0.0, cv::INTER_LINEAR);

}


// set image 1
void CompareTwoImagesAndImprove::setSimulatedImage(cv::Mat const& image)
{
	mSimulatedImage = image;
}
// get image 1
cv::Mat CompareTwoImagesAndImprove::getSimulatedImage() const&
{
	return mSimulatedImage;
}
// set image 2
void CompareTwoImagesAndImprove::setSharpImage(cv::Mat const& image)
{
	mSharpImage = image;
}
// get image 1
cv::Mat CompareTwoImagesAndImprove::getSharpImage() const&
{
	return mSharpImage;
}

// compare and improve the image quality example 1
QualityAndImageStruct CompareTwoImagesAndImprove::comTwoImaAndImprove_E0_Dis_MedB_UnsMas_bilFil_DitalEnhan()
{
	QualityAndImageStruct returnQualityAndIma;

	ImproveImageQuality ImproveImaQual;

	// correct distortion
	cv::Mat notDestortedImage = cv::Mat::zeros(mSharpImage.size(), mSharpImage.type());
	notDestortedImage = ImageProcessing::correctDistortion(mSimulatedImage, mSimulatedCalibrationImage, 19, 14);

	// Improvement accoring to correct distortion
	real improvementCorrectDistortion = Images::calcImprovement(mSharpImage, mSimulatedImage, notDestortedImage);

	// print improvement according to distortion
	std::cout << "" << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "distortion correction " << std::endl;
	std::cout << "improvement: " << improvementCorrectDistortion << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "" << std::endl;
	Images::saveImage("../image/", "notDistortedImages_elefant", "png", notDestortedImage);

	// median blur filter
	std::vector<int> kernelSizeMedianBlur{ 3,5,7,9,11,13,15,17,19 };
	medianBlurStruct sharpImage_medianBlur = ImproveImaQual.improveImageQuality_medianBlur(mSharpImage, notDestortedImage, kernelSizeMedianBlur);
	sharpImage_medianBlur.printPara_MedianBlur_Struct();
	Images::saveImage("../images", "sharpImage_medianBlur" ,"png", sharpImage_medianBlur.getImage());

	// unsharp masking
	std::vector<cv::Size> kernelSize_unsharpMasking{ {7,7},{9,9} };
	unsharpMaskStruct sharpImage_unsharpMasking = ImproveImaQual.improveImageQuality_unsharpMask_multiCore(mSharpImage, sharpImage_medianBlur.getImage(), kernelSize_unsharpMasking, 8.0, 11.0, 200, 1.0, 2.0, 200, cv::BORDER_DEFAULT, 0.0, 0.0, 1, 1.0, 1.0, 1);
	sharpImage_unsharpMasking.printPara_UnsharpMaskinFilter_Struct();
	Images::saveImage("../images", "sharpImage_unsharpMasking", "png", sharpImage_unsharpMasking.getImage());

	// bilateral Filter 
	bilateralFilterStruct sharpImage_bilateralFilter = ImproveImaQual.improveImageQuality_bilateralFilter_multiCore(mSharpImage, sharpImage_unsharpMasking.getImage(), 7, 8, 1, 6.0, 7.0, 150, 0.3, 0.7, 150, cv::BORDER_DEFAULT);
	sharpImage_bilateralFilter.printPara_BilateralFilter_Struct();
	Images::saveImage("../images", "sharpImage_bilateralFilter" , "png", sharpImage_bilateralFilter.getImage());
	
	// detail enhancement
	detailEnhanceStruct sharpImage_detailEnhange = ImproveImaQual.improveImageQuality_ditailEnhance_multiCore(mSharpImage, sharpImage_bilateralFilter.getImage(), 0.3, 0.7, 50, 0.9, 1.1, 50);
	sharpImage_detailEnhange.printPara_DetailEnhance_Struct();
	Images::saveImage("../images", "sharpImage_detailEnhange", "png", sharpImage_detailEnhange.getImage());
	
	real Quality = Images::calcSumMatrix(Images::PerElementAbsDifference(sharpImage_detailEnhange.getImage(), mSharpImage));
	
	returnQualityAndIma.setImage(sharpImage_detailEnhange.getImage());
	returnQualityAndIma.setQuality(Quality);
	returnQualityAndIma.setImprovement(Images::calcImprovement(mSharpImage, mSimulatedImage, sharpImage_detailEnhange.getImage()));
	
	returnQualityAndIma.printPara_QualityAndImaga_Struct();

	return returnQualityAndIma;
}

// compare and improve the image quality example 1
QualityAndImageStruct CompareTwoImagesAndImprove::comTwoImaAndImprove_E0_Dis_UnsMas_DitalEnhan_ConGamma()
{
	QualityAndImageStruct returnQualityAndIma;

	ImproveImageQuality ImproveImaQual;

	// correct distortion
	cv::Mat notDestortedImage = cv::Mat::zeros(mSharpImage.size(), mSharpImage.type());
	notDestortedImage = ImageProcessing::correctDistortion(mSimulatedImage, mSimulatedCalibrationImage, 19, 14);

	// Improvement accoring to correct distortion
	real improvementCorrectDistortion = Images::calcImprovement(mSharpImage, mSimulatedImage, notDestortedImage);

	// print improvement according to distortion
	std::cout << "" << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "distortion correction " << std::endl;
	std::cout << "improvement: " << improvementCorrectDistortion << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "" << std::endl;
	Images::saveImage("../images", "notDistortedImages_elefant", "png", notDestortedImage);

	// unsharp masking
	std::vector<cv::Size> kernelSize_unsharpMasking{ {9,9} };
	unsharpMaskStruct sharpImage_unsharpMasking = ImproveImaQual.improveImageQuality_unsharpMask_multiCore(mSharpImage, notDestortedImage, kernelSize_unsharpMasking, 8.0, 8.0, 1, 1.735, 1.735, 1, cv::BORDER_DEFAULT, 0.0, 0.0, 1, 1.0, 1.0, 1);
	sharpImage_unsharpMasking.printPara_UnsharpMaskinFilter_Struct();
	Images::saveImage("../images", "sharpImage_unsharpMasking" ,"png", sharpImage_unsharpMasking.getImage());

	// detail enhancement
	detailEnhanceStruct sharpImage_detailEnhange = ImproveImaQual.improveImageQuality_ditailEnhance_multiCore(mSharpImage, sharpImage_unsharpMasking.getImage(), 0.5, 0.6, 30, 0.8, 1.0, 40);
	sharpImage_detailEnhange.printPara_DetailEnhance_Struct();
	Images::saveImage("../images", "sharpImage_detailEnhange", "png", sharpImage_detailEnhange.getImage());

	// Contrast and Gamma
	ContrastAndGammaStruct sharpImage_ContrastAndGamma = ImproveImaQual.improveImageQuality_contrastAndGamma_multiCore(mSharpImage, sharpImage_detailEnhange.getImage(), 1.0, 5.0, 50, 0.0, 100.0, 100, 0.0, 2.0, 50);
	sharpImage_ContrastAndGamma.printPara_ContGamma_Struct();
	Images::saveImage("../images", "sharpImage_ContrastGamma" ,"png", sharpImage_ContrastAndGamma.getImage());


	real Quality = Images::calcSumMatrix(Images::PerElementAbsDifference(sharpImage_ContrastAndGamma.getImage(), mSharpImage));

	returnQualityAndIma.setImage(sharpImage_ContrastAndGamma.getImage());
	returnQualityAndIma.setQuality(Quality);
	returnQualityAndIma.setImprovement(Images::calcImprovement(mSharpImage, mSimulatedImage, sharpImage_ContrastAndGamma.getImage()));

	returnQualityAndIma.printPara_QualityAndImaga_Struct();

	return returnQualityAndIma;

}

// compare and improve for holistiv optimasation
QualityAndImageStruct CompareTwoImagesAndImprove::comTwoImaAndImprove_ForHolistivOptimasation()
{
	QualityAndImageStruct returnQualityAndIma;

	ImproveImageQuality ImproveImaQual;

	// correct distortion
	cv::Mat notDestortedImage = cv::Mat::zeros(mSharpImage.size(), mSharpImage.type());
	notDestortedImage = ImageProcessing::correctDistortion(mSimulatedImage, mSimulatedCalibrationImage, 14, 14);

	// Improvement accoring to correct distortion
	real improvementCorrectDistortion = Images::calcImprovement(mSharpImage, mSimulatedImage, notDestortedImage);

	// print improvement according to distortion
	std::cout << "" << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "distortion correction " << std::endl;
	std::cout << "improvement: " << improvementCorrectDistortion << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "" << std::endl;
	Images::saveImage("../images", "notDistortedImages_elefant" , "png", notDestortedImage);

	// unsharp masking
	std::vector<cv::Size> kernelSize_unsharpMasking{ {3,3}, {5,5}, {7,7}, {9,9}, {11,11} };
	unsharpMaskStruct sharpImage_unsharpMasking = ImproveImaQual.improveImageQuality_unsharpMask_multiCore(mSharpImage, notDestortedImage, kernelSize_unsharpMasking, 0.01, 1.0, 100, 0.01, 1.0, 100, cv::BORDER_DEFAULT, 0.0, 0.0, 1, 1.0, 1.0, 1);
	sharpImage_unsharpMasking.printPara_UnsharpMaskinFilter_Struct();
	Images::saveImage("../images", "sharpImage_unsharpMasking" , "png", sharpImage_unsharpMasking.getImage());

	
	real Quality = Images::calcSumMatrix(Images::PerElementAbsDifference(sharpImage_unsharpMasking.getImage(), mSharpImage));

	returnQualityAndIma.setImage(sharpImage_unsharpMasking.getImage());
	returnQualityAndIma.setQuality(Quality);
	returnQualityAndIma.setImprovement(Images::calcImprovement(mSharpImage, mSimulatedImage, sharpImage_unsharpMasking.getImage()));

	returnQualityAndIma.printPara_QualityAndImaga_Struct();

	return returnQualityAndIma;

}
