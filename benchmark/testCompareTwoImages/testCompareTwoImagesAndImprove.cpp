#include "testCompareTwoImagesAndImprove.h"
#include "..\..\LowLevelTracing\Math_LLT.h"
#include "..\..\CompareTwoImagesAndImprove\comparetwoimagesandimprove.h"
#include "..\..\Image\Images.h"


testCompareTwoImagesAndImprove::testCompareTwoImagesAndImprove() {}
testCompareTwoImagesAndImprove::~testCompareTwoImagesAndImprove() {}

bool testCompareTwoImagesAndImprove::testMethodesCompageTwoImagesAndImprove()
{

	//cv::Mat elefant_sharp = Images::loadAnImage_Color("../images/color/useThatImages/useThat/", "elefant_sharp.jpg");
	////Images::showImage("landscape", landscape_sharp);
	//
	//cv::Mat elefant_simulated = Images::loadAnImage_Color("../images/color/useThatImages/useThat/", "elefant_simulated.png");
	////Images::showImage("landscape resize", landscape_simulated_resize);
	//
	//cv::Mat chessboard_simulated_Big = Images::loadAnImage_Color("../images/color/useThatImages/useThat/", "chessboard_Big_simulated.png");
	////Images::showImage("chessboard big simulated resize", chessboard_simulated_Big);
	//
	////// example 0
	//CompareTwoImagesAndImprove comTwoImaAndImprove_elefant_E0_Dis_MedB_UnsMas_bilFil_DitalEnhan(elefant_simulated, elefant_sharp, chessboard_simulated_Big);
	//comTwoImaAndImprove_elefant_E0_Dis_MedB_UnsMas_bilFil_DitalEnhan.comTwoImaAndImprove_E0_Dis_MedB_UnsMas_bilFil_DitalEnhan();

	//// example 1
	//CompareTwoImagesAndImprove comTwoImaAndImprove_elefant_E1_Dis_UnsMas_DitalEnhan_ConGamma(elefant_simulated, elefant_sharp, chessboard_simulated_Big);
	//comTwoImaAndImprove_elefant_E1_Dis_UnsMas_DitalEnhan_ConGamma.comTwoImaAndImprove_E0_Dis_UnsMas_DitalEnhan_ConGamma();

	// holo 1
	cv::Mat elefant_gray_sharp = Images::loadAnImage_Color("../images/color/useThatImages/useThat/gray/", "elefant_sharp_gray_symetric_small.png");
	cv::Mat chessboard_small_symetric = Images::loadAnImage_Color("../images/color/useThatImages/useThat/gray/", "chessBoardBig_Symetric.png");
	cv::Mat elefant_gray_simulated = Images::loadAnImage_Color("../images/color/useThatImages/useThat/gray/", "simlulatedImage_TOM_small.bmp");
	CompareTwoImagesAndImprove comTwoImaAndImprove_holo(elefant_gray_simulated, elefant_gray_sharp, chessboard_small_symetric);
	comTwoImaAndImprove_holo.comTwoImaAndImprove_ForHolistivOptimasation();

	return true;
}