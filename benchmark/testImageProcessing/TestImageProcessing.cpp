#include "TestImageProcessing.h"
#include "..\..\ImageProcessing\ImageProcessing.h"
#include "..\..\Image\Images.h"

#include "..\..\LowLevelTracing\Math_LLT.h"

TestImageProcessing::TestImageProcessing() {}
TestImageProcessing::~TestImageProcessing() {}


bool TestImageProcessing::checkImageProcessing()
{
	std::vector<bool> chekImaProcVec;

	cv::Mat image1_Input_Color = Images::loadAnImage_Color("../images/", "inputImage.png");
	cv::Mat image2_Simulated_Color = Images::loadAnImage_Color("../images/", "simulatedImage.png");
	cv::Mat image2_Simulated_Gray;
	cv::cvtColor(image2_Simulated_Color, image2_Simulated_Gray, cv::COLOR_BGR2GRAY); // Convert the image to grayscale


	cv::Mat imageBrighCont = ImageProcessing::brighContrastAdjust(image2_Simulated_Color, 2.0, 10);
	cv::Mat gammaCorrect = ImageProcessing::gammaCorrection(image2_Simulated_Color, 0.5);

	//Images::showImage("input", image1_Input_Color);
	//Images::showImage("simulated", image2_Simulated_Color);
	//Images::showImage("bright contrast", imageBrighCont);
	//Images::showImage("gamma", gammaCorrect);


	// bilateralFilter
	cv::Mat bilateralFilteredIma = ImageProcessing::bilateralFilter(image2_Simulated_Color, 15, 80, 80,cv::BORDER_DEFAULT);
	//Images::showImage("bilateral filter", bilateralFilteredIma);

	// boxFilter
	cv::Size size(45, 45);
	cv::Point point(-1, -1);
	cv::Mat boxFilteredIma = ImageProcessing::boxFilter(image2_Simulated_Color, 40, size, point, true, cv::BORDER_DEFAULT);
	//Images::showImage("box filter", boxFilteredIma);


	// erosion
	cv::Point pointErosion(1, 1);
	cv::Size sizeErsosion(5, 5);
	cv::Mat erosionIma = ImageProcessing::erosion(image2_Simulated_Color, 0, sizeErsosion, pointErosion);
	//Images::showImage("erosion", erosionIma);

	// dilation
	cv::Point pointDilation(1, 1);
	cv::Size sizeDilation(5, 5);
	cv::Mat dilationIma = ImageProcessing::dilation(image2_Simulated_Color, 0, sizeDilation, pointDilation);
	//Images::showImage("dilation", dilationIma);

	// correct distortion
	//cv::Mat distortedImage = Images::loadAnImage_Color("../images/", "chessBoardDistortion.png");
	//cv::Mat distortionFreeImage = ImageProcessing::correctDistortion(distortedImage, distortedImage,9,6);
	////Images::showImage("distorted Image", distortedImage);
	//Images::showImage("distortionFree", distortionFreeImage);

	// correct distortion
	//cv::Mat distortedImage_Chessboard_Big = Images::loadAnImage_Color("../images/color/useThatImages/useThat/", "chessboard_Big_simulated.png");
	//cv::Mat distortionFreeImage_Chessboard_Big = ImageProcessing::correctDistortion(distortedImage_Chessboard_Big, distortedImage_Chessboard_Big, 19, 14);
	//Images::showImage("distortedImage_Chessboard_Big", distortedImage_Chessboard_Big);
	//Images::showImage("distortionFreeImage_Chessboard_Big", distortionFreeImage_Chessboard_Big);

	// detail enhance
	cv::Mat detailEnhancedIma = ImageProcessing::detailEnhancin(image2_Simulated_Color, 10, 0.15);
	//Images::showImage("detail enhance", detailEnhancedIma);

	// Laplacian
	cv::Mat laplacianImage = ImageProcessing::laplacian(image2_Simulated_Color, CV_16S, 5, 3, 0);
	//Images::showImage("laplacian", laplacianImage);

	// Canny
	cv::Mat	cannyImage = ImageProcessing::canny(image2_Simulated_Color, 50.0, 255.0, 5, false);
	//Images::showImage("canny", cannyImage);

	// Sobel
	cv::Mat sobelIma = ImageProcessing::sobel(image2_Simulated_Color, CV_16S, 1, 0, 11, 1, 0, cv::BORDER_DEFAULT);
	//Images::showImage("sobel", sobelIma);

	// unsharp mask
	cv::Size kernelSizeUnsharpMask(11, 11);
	cv::Mat unsharpMastImage = ImageProcessing::unsharpMask(image2_Simulated_Color, kernelSizeUnsharpMask, 1.0, 1.0, cv::BORDER_DEFAULT, 5.0, 1);
	//Images::showImage("unsharp mark", unsharpMastImage);

	// bilateral filter
	cv::Mat bilateralFilterImage = ImageProcessing::bilateralFilter(image2_Simulated_Color, 5, 10.0, 10.0, cv::BORDER_DEFAULT);
	//Images::showImage("bilateral filter", bilateralFilteredIma);

	// median blur filter
	cv::Mat medianBlurImage = ImageProcessing::MedianBlurFilter(image2_Simulated_Color, 5);
	//Images::showImage("median blur", medianBlurImage);

	// unsharp masking --> elefant
	std::vector<cv::Size> kernelSize{ {11,11} };
	cv::Mat elefant_Sharp = Images::loadAnImage_Color("../images/color/useThatImages/useThat/", "elefant_sharp.jpg");
	cv::Mat elefeant_Simulated = Images::loadAnImage_Color("../images/color/useThatImages/useThat/", "elefant_simulated.png");
	cv::Mat elefant_Simulated_resize = Images::resizeImage(elefeant_Simulated, elefant_Sharp.size(), 0.0, 0.0, cv::INTER_LINEAR);
	cv::Mat sharpImage_unsharpMasking_elefant = ImageProcessing::unsharpMask(elefant_Simulated_resize, { 11,11 }, 9.502, 9.5, cv::BORDER_DEFAULT, 0.1, 0.6);
	//Images::showImage("unsharp masking elefant", sharpImage_unsharpMasking_elefant);
	Images::saveImage("../images/", "unsharp_masking_elefant.png", sharpImage_unsharpMasking_elefant);
	real improvement = Images::calcImprovement(elefant_Sharp, elefant_Simulated_resize, sharpImage_unsharpMasking_elefant);

	bool returnTestImaProc = Math::checkTrueOfVectorElements(chekImaProcVec);
	return returnTestImaProc;

}