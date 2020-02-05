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
	void showImage(std::string nameImage, cv::Mat image);

	// save an image
	void saveImage(std::string const& fileLocation, std::string const& nameImage, cv::Mat const& image);

	// calculate improvement
	real calcImprovement(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, cv::Mat const& improvetImage);

}
