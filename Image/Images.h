#pragma once
#include "..\LowLevelTracing/ImportantStructures.h"


#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>


namespace Images
{
	// load an image in gray
	cv::Mat loadAnImage_Gray(const std::string fileLocation, const std::string fileName);

	// load a color image
	cv::Mat loadAnImage_Color(const std::string fileLocation, const std::string fileName);

	// resize two images
	cv::Mat resizeImage(cv::Mat inputImage, cv::Size targetSize, real scaleX, real scaleY, int interpolation);

	// Calculates the per-element absolute difference between two arrays
	cv::Mat PerElementAbsDifference(const cv::Mat& image1, const cv::Mat& image2);

	// calculate the sum of all matrix values
	real calcSumMatrix(const cv::Mat& matrix);
	// https://stackoverflow.com/questions/21874774/sum-of-elements-in-a-matrix-in-opencv

	// show an image
	void showImage_inputReal_normTheImage(const cv::String winname, cv::Mat ima);
	void showImage_inputReal_normImaByROI_inPercent(const cv::String winname, cv::Mat ima, real percent);
	void showImage_inputUint8(const cv::String winname, cv::Mat ima);
	void showImage_inputUint8_normImaByROI_inPercent(const cv::String winname, cv::Mat ima, real percent);
	cv::Mat convertImage_64FC3_to_CV_8UC3(const cv::Mat imaToConvert);
	cv::Mat convertImage_64FC1_to_CV_8UC1(const cv::Mat imaToConvert);

	// save an image
	void saveImage_normalized(std::string fileLocation, std::string nameImage, std::string typeIma, const cv::Mat image);
	void saveImage_NOTnormalized(std::string fileLocation, std::string nameImage, std::string typeIma, const cv::Mat image);
	void saveImage_inputReal_multiplyBy(std::string fileLocation, std::string nameImage, std::string typeIma, const cv::Mat image, real factor);
	void saveImage_inputReal_normByROI_percent(std::string fileLocation, std::string nameImage, std::string typeIma, const cv::Mat image, real percent);
	void saveImage_inputUN8C3_normByROI_percent(std::string fileLocation, std::string nameImage, std::string typeIma, const cv::Mat image, real percent);
	void saveImageGray_UN8_normByROI_percent(std::string fileLocation, std::string nameImage, std::string typeIma, const cv::Mat image, real percent);

	// get type of cv::Mat
	std::string getTypeImageC_VMat(cv::Mat matrix);

	// check if two images are the same
	bool checkImagesSame_64FC1(cv::Mat ima1, cv::Mat ima2, real tolerance);

	// calcualte difference
	int calcAbsDiff_BGR_uint8(const cv::Mat& sharpIma, const cv::Mat& filteredIma, real percent);

	// calculate total improvement BGR
	real calcImprovementBGR(cv::Mat sharpIma, cv::Mat blueredIma, cv::Mat filteredIma, real percent);
	real calcImprovementGray(cv::Mat sharpIma, cv::Mat blueredIma, cv::Mat filteredIma, real percent);
	real calcImprovement_noNorming(const cv::Mat& sharpImage, const cv::Mat& simulatedImage, const cv::Mat& improvetImage);

	// split the image in BGR
	std::vector<cv::Mat> splitImageBGR(cv::Mat imageBGR);

	// merge images
	cv::Mat mergeImages(std::vector<cv::Mat> image_vec);

	// two images equal
	bool compateTwoImages(cv::Mat ima1, cv::Mat ima2, int tolerance);

	// load an image and norm all colors between 0 and 255
	void loadImage_BGR_AndNormAllColors(std::string location, std::string name, std::string save_loc, std::string save_name);
}
