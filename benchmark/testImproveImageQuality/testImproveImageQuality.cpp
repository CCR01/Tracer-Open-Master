#include "testImproveImageQuality.h"
#include "..\..\Image\ImproveImageQuality.h"
#include "..\..\Image\Images.h"

testImproveImageQuality::testImproveImageQuality(){}

testImproveImageQuality::~testImproveImageQuality(){}

bool testImproveImageQuality::checkImproveImageQuality()
{

	//load sharp image
	cv::Mat sharpImage = Images::loadAnImage_Color("../images/", "inputImage.png");
	// image to be improved
	cv::Mat imageToImprove = Images::loadAnImage_Color("../images/", "simulatedImage.png");
	// resize the simulated image
	cv::Mat imageToImproveResize = Images::resizeImage(imageToImprove, sharpImage.size(), 1, 1, cv::INTER_LINEAR);

	ImproveImageQuality improveImaQua;
	//detailEnhanceStruct shaprImage = improveImaQua.improveImageQuality_ditailEnhance(sharpImage, imageToImproveResize, 10, 100, 6, 0.1, 0.9, 6);
	//detailEnhanceStruct sharpImage_detailEnhanceStruct = improveImaQua.improveImageQuality_ditailEnhance_multiCore(sharpImage, imageToImproveResize, 10, 100, 32, 0.1, 0.9, 32);
	//Images::showImage("detail Ennhance", sharpImage_detailEnhanceStruct.getImage());

	//// bilateral filter --> salad
	//cv::Mat salad_Sharp_1 = Images::loadAnImage_Color("../images/color/useThatImages/useThat/", "salad_sharp.jpg");
	//cv::Mat saled_Simulated_1 = Images::loadAnImage_Color("../images/color/useThatImages/useThat/", "salad_simulated.png");
	//cv::Mat salad_Simulated_resize_1 = Images::resizeImage(saled_Simulated_1, salad_Sharp_1.size(), 0.0, 0.0, cv::INTER_LINEAR);
	//bilateralFilterStruct sharpImage_bilateralFilter_salad  = improveImaQua.improveImageQuality_bilateralFilter (salad_Sharp_1, salad_Simulated_resize_1, 1, 6, 20, 0.1, 5.0, 0.1, 0.0, 20.0, 10.0, cv::BORDER_DEFAULT);
	//Images::showImage("bilateral filter salad", sharpImage_bilateralFilter_salad.getImage());
	//Images::saveImage("../images/", "salad.png", sharpImage_bilateralFilter_salad.getImage());

	////// bilateral filter --> salad
	//cv::Mat salad_Sharp = Images::loadAnImage_Color("../images/color/useThatImages/useThat/", "salad_sharp.jpg");
	//cv::Mat saled_Simulated = Images::loadAnImage_Color("../images/color/useThatImages/useThat/", "salad_simulated.png");
	//cv::Mat salad_Simulated_resize = Images::resizeImage(saled_Simulated, salad_Sharp.size(), 0.0, 0.0, cv::INTER_LINEAR);
	//bilateralFilterStruct sharpImage_bilateralFilter_salad_multiCore = improveImaQua.improveImageQuality_bilateralFilter_multiCore(salad_Sharp, salad_Simulated_resize, 3, 7, 4, 2.0, 5.0, 50.0, 20.0, 40.0, 50.0, cv::BORDER_DEFAULT);
	//Images::showImage("bilateral filter salad", sharpImage_bilateralFilter_salad_multiCore.getImage());
	//Images::saveImage("../images/", "salad.png", sharpImage_bilateralFilter_salad_multiCore.getImage());

	//// bilateral filter --> salad --> gray
	//cv::Mat salad_Sharp_gray = Images::loadAnImage_Gray("../images/color/useThatImages/useThat/", "salad_sharp_gray.jpg");
	//cv::Mat saled_Simulated_gray = Images::loadAnImage_Gray("../images/color/useThatImages/useThat/", "salad_simulated_gray.png");
	//cv::Mat salad_Simulated_resize_gray = Images::resizeImage(saled_Simulated_gray, salad_Sharp_gray.size(), 0.0, 0.0, cv::INTER_LINEAR);
	//bilateralFilterStruct sharpImage_bilateralFilter_salad_multiCore_gray = improveImaQua.improveImageQuality_bilateralFilter_multiCore(salad_Sharp_gray, salad_Simulated_resize_gray, 3, 7, 4, 2.0, 5.0, 10.0, 20.0, 40.0, 10.0, cv::BORDER_DEFAULT);
	//Images::showImage("bilateral filter salad gray", sharpImage_bilateralFilter_salad_multiCore_gray.getImage());
	//Images::saveImage("../images/", "salad_gray_improved.png", sharpImage_bilateralFilter_salad_multiCore_gray.getImage());


	//// bilateral filter --> landscape
	//cv::Mat landscape_Sharp = Images::loadAnImage_Color("../images/color/useThatImages/useThat/", "landscape_sharp.jpg");
	//cv::Mat landscale_Simulated = Images::loadAnImage_Color("../images/color/useThatImages/useThat/", "landscape_simulated.png");
	//cv::Mat landscape_Simulated_resize = Images::resizeImage(landscale_Simulated, landscape_Sharp.size(), 0.0, 0.0, cv::INTER_LINEAR);
	//bilateralFilterStruct sharpImage_bilateralFilter_landscape_multiCore = improveImaQua.improveImageQuality_bilateralFilter_multiCore(landscape_Sharp, landscape_Simulated_resize, 1, 10, 9, 1.0, 100.0, 10.0, 1.0, 100.0, 10.0, cv::BORDER_DEFAULT);
	//Images::showImage("bilateral filter landcape", sharpImage_bilateralFilter_landscape_multiCore.getImage());
	//Images::saveImage("../images/", "bilateral_filter_landcape.png", sharpImage_bilateralFilter_landscape_multiCore.getImage());


	//// unsharp masking --> landscape
	//std::vector<cv::Size> kernelSize{ {3,3},{5,5},{7,7} };
	//cv::Mat landscape_Sharp = Images::loadAnImage_Color("../images/color/useThatImages/useThat/", "landscape_sharp.jpg");
	//cv::Mat landscale_Simulated = Images::loadAnImage_Color("../images/color/useThatImages/useThat/", "landscape_simulated.png");
	//cv::Mat landscape_Simulated_resize = Images::resizeImage(landscale_Simulated, landscape_Sharp.size(), 0.0, 0.0, cv::INTER_LINEAR);
	//unsharpMaskStruct sharpImage_unsharpMasking_landscape_multiCore = improveImaQua.improveImageQuality_unsharpMask_multiCore(landscape_Sharp, landscape_Simulated_resize, kernelSize, 10.0, 100.0, 10.0, 10.0, 100.0, 10.0, cv::BORDER_DEFAULT, 10.0, 100.0, 10.0, 5.0, 50.0, 10.0);
	//Images::showImage("unsharp masking landscape", sharpImage_unsharpMasking_landscape_multiCore.getImage());
	//Images::saveImage("../images/", "unsharp_masking_landscape.png", sharpImage_unsharpMasking_landscape_multiCore.getImage());

	// unsharp masking --> elefant
	std::vector<cv::Size> kernelSize{ {9,9}, {11,11} };
	cv::Mat elefant_Sharp = Images::loadAnImage_Color("../images/color/useThatImages/useThat/", "elefant_sharp.jpg");
	cv::Mat elefeant_Simulated = Images::loadAnImage_Color("../images/color/useThatImages/useThat/", "elefant_simulated.png");
	cv::Mat elefant_Simulated_resize = Images::resizeImage(elefeant_Simulated, elefant_Sharp.size(), 0.0, 0.0, cv::INTER_LINEAR);
	unsharpMaskStruct sharpImage_unsharpMasking_elefant_multiCore = improveImaQua.improveImageQuality_unsharpMask_multiCore(elefant_Sharp, elefant_Simulated_resize, kernelSize, 7.5, 10.0, 100.0, 1.0, 2.0, 100.0, cv::BORDER_DEFAULT, 0.0, 0.0, 1.0, 1.0, 1.0, 1);
	sharpImage_unsharpMasking_elefant_multiCore.printPara_UnsharpMaskinFilter_Struct();
	Images::showImage("unsharp masking elefant", sharpImage_unsharpMasking_elefant_multiCore.getImage());
	Images::saveImage("../images", "unsharpMaskingElefant" , "png", sharpImage_unsharpMasking_elefant_multiCore.getImage());

	//// detail enhance --> elefant
	//cv::Mat elefant_Sharp = Images::loadAnImage_Color("../images/color/useThatImages/useThat/", "elefant_sharp.jpg");
	//cv::Mat elefeant_Simulated = Images::loadAnImage_Color("../images/color/useThatImages/useThat/", "elefant_simulated.png");
	//cv::Mat elefant_Simulated_resize = Images::resizeImage(elefeant_Simulated, elefant_Sharp.size(), 0.0, 0.0, cv::INTER_LINEAR);
	//detailEnhanceStruct sharpImage_detailEnhance_elefant = improveImaQua.improveImageQuality_ditailEnhance(elefant_Sharp, elefant_Simulated_resize, 0.1, 20.0, 50, 0.1, 20.0, 50.0);
	//Images::saveImage("../images/", "detail_enhance_elefant.png", sharpImage_detailEnhance_elefant.getImage());

	//(image2_Simulated_Color, kernelSizeUnsharpMask, 1.0, 1.0, cv::BORDER_DEFAULT, 5.0, 1);

	//// median blur
	//std::vector<int> kernelSizeMedianBlur{ 3,5,7,9,11,13 };
	//medianBlurStruct sharpImage_medianBlur = improveImaQua.improveImageQuality_medianBlur(sharpImage, imageToImproveResize, kernelSizeMedianBlur);
	//Images::showImage("median Blur", sharpImage_medianBlur.getImage());

	return true;


}