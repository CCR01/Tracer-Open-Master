#pragma once
#include "..\LowLevelTracing/ImportantStructures.h"


#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

namespace Images
{
	// load an image in gray
	cv::Mat loadAnImage_Gray(std::string const& fileLocation, std::string const& fileName);

	// load a color image
	cv::Mat loadAnImage_Color(std::string const& fileLocation, std::string const& fileName);

	// resize two images
	cv::Mat resizeImage(cv::Mat inputImage, cv::Size targetSize, real scaleX, real scaleY, int interpolation);



	// Calculates the per-element absolute difference between two arrays
	cv::Mat PerElementAbsDifference(cv::Mat const& image1, cv::Mat const& image2);

	// calculate the sum of all matrix values
	real calcSumMatrix(cv::Mat const& matrix);
	// https://stackoverflow.com/questions/21874774/sum-of-elements-in-a-matrix-in-opencv

	// show an image
	void showImage_inputReal(const cv::String winname, cv::Mat& ima);
	void showImage_inputUint8(const cv::String winname, cv::Mat& ima);
	cv::Mat convertImage_64FC3_to_CV_8UC3(const cv::Mat& imaToConvert);
	cv::Mat convertImage_64FC1_to_CV_8UC1(const cv::Mat& imaToConvert);

	// save an image
	void saveImage(std::string fileLocation, std::string nameImage, std::string typeIma, const cv::Mat& image);

	// calculate improvement
	real calcImprovement(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, cv::Mat const& improvetImage);

	// get type of cv::Mat
	std::string getTypeImageC_VMat(cv::Mat matrix);

}
