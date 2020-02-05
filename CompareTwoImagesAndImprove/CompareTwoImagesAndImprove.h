#pragma once
//#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/imgproc/imgproc.hpp>

#include "..\LowLevelTracing/ImportantStructures.h"

struct QualityAndImageStruct
{
	QualityAndImageStruct();
	QualityAndImageStruct(real const& quality, cv::Mat const& image, real const& improvement);
	~QualityAndImageStruct();


	// set quality
	void setQuality(real const&  quality);
	// get quality
	real getQuality() const&;
	// set image
	void setImage(cv::Mat const& image);
	// get image
	cv::Mat getImage() const&;
	// set improvement
	void setImprovement(real const& improvement);
	// get improvement
	real getImprovement() const&;

	// print parameters quality and image struct
	void printPara_QualityAndImaga_Struct() const &;

private:
	real mQuality;
	cv::Mat mImage;
	real mImprovement;

};

class CompareTwoImagesAndImprove
{
public:
	CompareTwoImagesAndImprove();
	CompareTwoImagesAndImprove(cv::Mat simulatedImage, cv::Mat sharpImage, cv::Mat simulatedCalibrationImage);
	~CompareTwoImagesAndImprove();


	// set simulatet image
	void setSimulatedImage(cv::Mat const& image);
	// get simulatet image
	cv::Mat getSimulatedImage() const&;
	// set sharp image
	void setSharpImage(cv::Mat const& image);
	// get sharp image
	cv::Mat getSharpImage() const&;

	
	// compare and improve the image quality example 0
	QualityAndImageStruct comTwoImaAndImprove_E0_Dis_MedB_UnsMas_bilFil_DitalEnhan();

	// compare and improve the image quality example 1
	QualityAndImageStruct comTwoImaAndImprove_E0_Dis_UnsMas_DitalEnhan_ConGamma();

	// compare and improve for holistiv optimasation
	QualityAndImageStruct comTwoImaAndImprove_ForHolistivOptimasation();

private:
	cv::Mat mSimulatedImage;
	cv::Mat mSharpImage;
	cv::Mat mSimulatedCalibrationImage;

};

