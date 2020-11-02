#include "testImages.h"
#include "..\..\LowLevelTracing\Math_LLT.h"
#include "..\..\Image\Images.h"

TestImages::TestImages(){}
TestImages::~TestImages(){}

bool TestImages::checkMethodesNamespaceImages()
{
	std::vector<bool> checkNamespaceImages;


	// Gray image
	cv::Mat image1_Gray = Images::loadAnImage_Gray("../images/", "example1_1.png");
	cv::Mat image2_Gray = Images::loadAnImage_Gray("../images/", "example1_2.png");
	cv::Size size1_Gray = image1_Gray.size();
	cv::Size size2_Gray = image2_Gray.size();
	bool compareSize_Gray = size1_Gray == size2_Gray;
	checkNamespaceImages.push_back(compareSize_Gray);

	// color image
	cv::Mat image1_Color = Images::loadAnImage_Color("../images/", "inputImage.png");
	cv::Mat image2_Color = Images::loadAnImage_Color("../images/", "simulatedImage.png");
	cv::Mat resizedImage = Images::resizeImage(image2_Color, image1_Color.size(), 0.0, 0.0, cv::INTER_LINEAR);
	bool checkResize_Color = resizedImage.size() == image1_Color.size();
	checkNamespaceImages.push_back(checkResize_Color);

	// save an image
	Images::saveImage("../images", "test", "png", image1_Color);

	cv::Mat imageColorAbsDif = Images::PerElementAbsDifference(image1_Color, resizedImage);
	real sumMatrix = Images::calcSumMatrix(imageColorAbsDif);

	// compatre the same image
	cv::Mat imageSame1_Color = Images::loadAnImage_Color("../images/", "inputImage.bmp");
	cv::Mat imageSame2_Color = Images::loadAnImage_Color("../images/", "inputImage.bmp");
	cv::Mat imageColorAbsDif_same = Images::PerElementAbsDifference(imageSame1_Color, imageSame2_Color);
	real sumMatrix_same = Images::calcSumMatrix(imageColorAbsDif_same);
	bool checkSumMatrix_same = sumMatrix_same == 0.0;
	checkNamespaceImages.push_back(checkSumMatrix_same);



	bool returnTestCompTwoIm = Math::checkTrueOfVectorElements(checkNamespaceImages);

	return true;
}