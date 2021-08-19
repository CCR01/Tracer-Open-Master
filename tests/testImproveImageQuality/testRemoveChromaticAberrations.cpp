#include "testRemoveChromaticAberrations.h"

// math
#include "..\..\LowLevelTracing\Math_LLT.h"

// import export data
#include "..\..\Inport_Export_Data\Inport_Export_Data.h"

// image simulation
#include "..\..\Image\ImageSimulation.h"

// often use
#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

// remove chromatic aberrations
#include "..\..\ImageProcessing\RemoveChromaticAberrations.h"

// images
#include "..\..\Image\Images.h"

testRemoveChromaticAberrations::testRemoveChromaticAberrations(){}

testRemoveChromaticAberrations::~testRemoveChromaticAberrations(){}



bool testRemoveChromaticAberrations::testRenChromAber_superFunc()
{
	std::vector<bool> workTheSystem{};

	//// test0
	//bool chech0 = test0();
	//workTheSystem.push_back(chech0);
	// test 1
	bool check1 = test1();
	workTheSystem.push_back(check1);


	bool workReturn = Math::checkTrueOfVectorElements(workTheSystem);
	return workReturn;
}

// test 0
bool testRemoveChromaticAberrations::test0()
{
	std::vector<bool> workTheSystem{};

	// loaction
	std::string location = "../tests/testImproveImageQuality/removeChromaticAberrations/E0";

	// load object
	// sharp image
	cv::Mat chessboardSharp = cv::imread("../images/color/useThatImages/useThat/chessboard12x8.png", CV_LOAD_IMAGE_COLOR);
	// bluered image
	cv::Mat chessboardBluered = cv::imread("../images/color/useThatImages/useThat/sinImaChessboard12x8.png", CV_LOAD_IMAGE_COLOR);

	initialPararemChromAber iniParaRemChromAber;
	iniParaRemChromAber.setMinThreshold(-100);
	iniParaRemChromAber.setMaxThreshold(100);
	iniParaRemChromAber.setStepsThreshold(1000);
	iniParaRemChromAber.setCompateInPercent(0.0);
	
	RemoveChromaticAberrations remChromAber;
	remChromAber.setInitialParameter(iniParaRemChromAber);
	remChromAber.removeChromaticAberrations_superFct(chessboardSharp, chessboardBluered);
	
	bestParaRemChromAber bestPara = remChromAber.getBestParameter();
	cv::Mat bestFilteredIma = bestPara.getImage();
	bestPara.printPara_RemChromAber_Struct();
	bestPara.exportAsTXTfile(location, "bestParaTest0", true);
	
	// debug
	Images::showImage_inputUint8("result", bestFilteredIma);
	Images::saveImage_normalized(location, "finalImage", "png", bestFilteredIma);

	// test
	cv::Mat chessboardBluered_normalized;
	cv::normalize(chessboardBluered, chessboardBluered_normalized, 0.0, 255.0, cv::NORM_MINMAX, CV_8UC3);
	cv::Mat filteredIma_test;
	RemoveChromaticAberrations remChromAber_test;
	remChromAber_test.CACorrection_RayXie29(chessboardBluered_normalized, filteredIma_test, bestPara.getThreshold());
	Images::saveImage_normalized(location, "finalImage_test", "png", filteredIma_test);

	cv::normalize(filteredIma_test, filteredIma_test, 0.0, 255.0, cv::NORM_MINMAX, CV_8UC3);
	cv::normalize(bestFilteredIma, bestFilteredIma, 0.0, 255.0, cv::NORM_MINMAX, CV_8UC3);

	real imp1 = Images::calcImprovementBGR(chessboardSharp, chessboardBluered, bestFilteredIma, iniParaRemChromAber.getCompateInPercent());
	real imp2 = Images::calcImprovementBGR(chessboardSharp, chessboardBluered, filteredIma_test, iniParaRemChromAber.getCompateInPercent());

	bool checkTwoImages = Images::compateTwoImages(filteredIma_test, bestFilteredIma, 1);
	workTheSystem.push_back(checkTwoImages);


	bool workReturn = Math::checkTrueOfVectorElements(workTheSystem);
	return workReturn;
}

// test 1
bool testRemoveChromaticAberrations::test1()
{
	std::vector<bool> workTheSystem{};

	// loaction
	std::string location = "../tests/testImproveImageQuality/removeChromaticAberrations/E1";

	// load object
	// sharp image
	cv::Mat chessboardSharp = cv::imread("../images/color/useThatImages/useThat/chessBoard8x8_900x900.png", CV_LOAD_IMAGE_COLOR);
	// bluered image
	cv::Mat chessboardBluered = cv::imread("../tests/testImageSimulation/s11/simImaChessBoard8x8.png", CV_LOAD_IMAGE_COLOR);

	initialPararemChromAber iniParaRemChromAber;
	iniParaRemChromAber.setMinThreshold(-100);
	iniParaRemChromAber.setMaxThreshold(100);
	iniParaRemChromAber.setStepsThreshold(1000);
	iniParaRemChromAber.setCompateInPercent(0.0);

	RemoveChromaticAberrations remChromAber;
	remChromAber.setInitialParameter(iniParaRemChromAber);
	remChromAber.removeChromaticAberrations_superFct(chessboardSharp, chessboardBluered);

	bestParaRemChromAber bestPara = remChromAber.getBestParameter();
	cv::Mat bestFilteredIma = bestPara.getImage();
	bestPara.printPara_RemChromAber_Struct();
	bestPara.exportAsTXTfile(location, "bestParaTest1", true);

	// debug
	Images::showImage_inputUint8("result", bestFilteredIma);
	Images::saveImage_normalized(location, "finalImage", "png", bestFilteredIma);

	// test
	cv::Mat chessboardBluered_normalized;
	cv::normalize(chessboardBluered, chessboardBluered_normalized, 0.0, 255.0, cv::NORM_MINMAX, CV_8UC3);
	cv::Mat filteredIma_test;
	RemoveChromaticAberrations remChromAber_test;
	remChromAber_test.CACorrection_RayXie29(chessboardBluered_normalized, filteredIma_test, bestPara.getThreshold());
	Images::saveImage_normalized(location, "finalImage_test", "png", filteredIma_test);

	cv::normalize(filteredIma_test, filteredIma_test, 0.0, 255.0, cv::NORM_MINMAX, CV_8UC3);
	cv::normalize(bestFilteredIma, bestFilteredIma, 0.0, 255.0, cv::NORM_MINMAX, CV_8UC3);

	real imp1 = Images::calcImprovementBGR(chessboardSharp, chessboardBluered, bestFilteredIma, iniParaRemChromAber.getCompateInPercent());
	real imp2 = Images::calcImprovementBGR(chessboardSharp, chessboardBluered, filteredIma_test, iniParaRemChromAber.getCompateInPercent());

	bool checkTwoImages = Images::compateTwoImages(filteredIma_test, bestFilteredIma, 1);
	workTheSystem.push_back(checkTwoImages);


	bool workReturn = Math::checkTrueOfVectorElements(workTheSystem);
	return workReturn;
}