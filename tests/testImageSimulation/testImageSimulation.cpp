#include "testImageSimulation.h"
#include "..\..\Analyse\OpticalPathDifference.h"



#include "..\..\SequentialRayTracing\SequentialRayTracer.h"

#include "..\..\FillAptertureStop\FillApertureStop.h"
#include "..\..\Analyse\Spot.h"

#include "..\..\FillAptertureStop\FillApertureStop.h"
#include"..\..\Image\Images.h"
#include "..\..\oftenUseNamespace\oftenUseNamespace.h"
#include "..\..\Inport_Export_Data\Inport_Export_Data.h"

// include elements
#include "..\..\SurfaceElements\ApertureStopElement.h"
#include "..\..\SurfaceElements\PlanElement.h"
#include "..\..\SurfaceElements\SphericalElement.h"

// PSF
#include "..\..\Point-Spread Function\Point-Spread Function.h"


TestImageSimulation::TestImageSimulation() { loadImportantStuff(); };
TestImageSimulation::~TestImageSimulation() {};

void TestImageSimulation::loadImportantStuff()
{
	glasses.loadGlassCatalog_Schott();
	
	mWavelenght_vec_dFC.resize(3);
	mWavelenght_vec_dFC[0] = 587.5618;
	mWavelenght_vec_dFC[1] = 486.1327;
	mWavelenght_vec_dFC[2] = 656.2725;

	mObject_vec_012.resize(3);
	mObject_vec_012[0] = { 0.0,0.0,0.0 };
	mObject_vec_012[1] = { 0.0,1.0,0.0 };
	mObject_vec_012[2] = { 0.0,2.0,0.0 };

	mDefaulParaImaSim.setRowBiggerForConV(10);
	mDefaulParaImaSim.setColBiggerForConv(10);
	mDefaulParaImaSim.setWavelengthBlue(486.1327);
	mDefaulParaImaSim.setWavelengthGreen(587.5818);
	mDefaulParaImaSim.setWavelengthRed(656.2725);
	mDefaulParaImaSim.setRayDensity(6);

	//light
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	light.setJonesVector({ 1.0,1.0,1.0,1.0 });
	light.setTypeLight(typeLight::typeLightRay);

	mDefaulParaImaSim.setLight(light);
	mDefaulParaImaSim.setStartRefIndex(1.0);
	mDefaulParaImaSim.setSizeMatrixToSaveOPD(31);
	mDefaulParaImaSim.setInfOrObj(objectPoint_inf_obj::obj);

	mDefaulParaImaSim.setRowColResizeOPD(256);
}


// typedef
typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

bool TestImageSimulation::testSuperFct()
{
	std::vector<bool> testSuperFct_vec;
	
	//// test system 0
	//bool checkSystem0 = test0();
	//testSuperFct_vec.push_back(checkSystem0);
	//
	//// test system 1
	//bool checkSystem1 = test1();
	//testSuperFct_vec.push_back(checkSystem1);
	//
	//// test 2 
	//bool checkTest2 = test2();
	//testSuperFct_vec.push_back(checkTest2);
	
	//// test 3
	//bool checkTest3 = test3();
	//testSuperFct_vec.push_back(checkTest3);

	// test 4
	bool checkTest4 = test4();
	testSuperFct_vec.push_back(checkTest4);
	//
	////test 5
	//bool checkTest5 = test5();
	//testSuperFct_vec.push_back(checkTest5);

	//// test 6
	//bool checkTest6 = test6();
	//testSuperFct_vec.push_back(checkTest6);

	////test 7
	//bool checkTest7 = test7();
	//testSuperFct_vec.push_back(checkTest7);

	bool returnChecker = Math::checkTrueOfVectorElements(testSuperFct_vec);
	return returnChecker;
}

bool TestImageSimulation::test0()
{
	real tolerancePSF = 0.001;
	std::vector<bool> test_vec;

	std::string loaction = "../tests/testImageSimulation/s0";
	std::string type = "txt";
	std::string namePSF0 = "PSF(0,0)";
	std::string namePSF1 = "PSF(0,1)";
	std::string namePSF2 = "PSF(0,-1)";
	std::string namePSF3 = "PSF(1,0)";
	std::string namePSF4 = "PSF(-1,0)";
	std::string namePSF5 = "PSF(1,1)";
	std::string namePSF6 = "PSF(1,-1)";
	std::string namePSF7 = "PSF(-1,1)";
	std::string namePSF8 = "PSF(-1,-1)";


	// load all PSFs from txt data
	cv::Mat PSF0 = inportExportData::importTXTtoCVmat(loaction, namePSF0, 127, 127);
	cv::Mat PSF1 = inportExportData::importTXTtoCVmat(loaction, namePSF1, 127, 127);
	cv::Mat PSF2 = inportExportData::importTXTtoCVmat(loaction, namePSF2, 127, 127);
	cv::Mat PSF3 = inportExportData::importTXTtoCVmat(loaction, namePSF3, 127, 127);
	cv::Mat PSF4 = inportExportData::importTXTtoCVmat(loaction, namePSF4, 127, 127);
	cv::Mat PSF5 = inportExportData::importTXTtoCVmat(loaction, namePSF5, 127, 127);
	cv::Mat PSF6 = inportExportData::importTXTtoCVmat(loaction, namePSF6, 127, 127);
	cv::Mat PSF7 = inportExportData::importTXTtoCVmat(loaction, namePSF7, 127, 127);
	cv::Mat PSF8 = inportExportData::importTXTtoCVmat(loaction, namePSF8, 127, 127);

	// check PSF 0
	real loadPSF0_00 = PSF0.at<real>(0, 0);
	real refPSF0_00 = 3.0166E-005;
	real loadPSF0_11 = PSF0.at<real>(1, 1);
	real refPSF0_11 = 1.8692E-006;
	bool checkPSF0_00 = Math::compareTwoNumbers_tolerance(loadPSF0_00, refPSF0_00, tolerancePSF);
	test_vec.push_back(checkPSF0_00);
	bool checkPSF0_11 = Math::compareTwoNumbers_tolerance(loadPSF0_11, refPSF0_11, tolerancePSF);
	test_vec.push_back(checkPSF0_11);
	inportExportData::exportCV_MatToExcel(PSF0, loaction, namePSF0);

	// check PSF 1
	real loadPSF1_56 = PSF1.at<real>(5, 6);
	real refPSF1_56 = 7.9780E-007;
	real loadPSF1_12 = PSF1.at<real>(1, 2);
	real refPSF1_12 = 1.7824E-006;
	bool checkPSF1_56 = Math::compareTwoNumbers_tolerance(loadPSF1_56, refPSF1_56, tolerancePSF);
	test_vec.push_back(checkPSF1_56);
	bool checkPSF1_12 = Math::compareTwoNumbers_tolerance(loadPSF1_12, refPSF1_12, tolerancePSF);
	test_vec.push_back(checkPSF1_12);
	inportExportData::exportCV_MatToExcel(PSF1, loaction, namePSF1);

	// check PSF 2
	real loadPSF2_02 = PSF2.at<real>(0, 2);
	real refPSF2_02 = 1.8302E-006;
	real loadPSF2_31 = PSF2.at<real>(3, 1);
	real refPSF2_31 = 2.5848E-006;
	bool checkPSF2_02 = Math::compareTwoNumbers_tolerance(loadPSF2_02, refPSF2_02, tolerancePSF);
	test_vec.push_back(checkPSF2_02);
	bool checkPSF2_31 = Math::compareTwoNumbers_tolerance(loadPSF2_31, refPSF2_31, tolerancePSF);
	test_vec.push_back(checkPSF2_31);
	inportExportData::exportCV_MatToExcel(PSF2, loaction, namePSF2);

	// check PSF 3
	real loadPSF3_13 = PSF3.at<real>(1, 3);
	real refPSF3_13 = 8.5358E-006;
	real loadPSF3_23 = PSF3.at<real>(2, 3);
	real refPSF3_23 = 2.8567E-006;
	bool checkPSF3_13 = Math::compareTwoNumbers_tolerance(loadPSF3_13, refPSF3_13, tolerancePSF);
	test_vec.push_back(checkPSF3_13);
	bool checkPSF3_23 = Math::compareTwoNumbers_tolerance(loadPSF3_23, refPSF3_23, tolerancePSF);
	test_vec.push_back(checkPSF3_23);
	inportExportData::exportCV_MatToExcel(PSF3, loaction, namePSF3);

	// check PSF 4
	real loadPSF4_30 = PSF4.at<real>(1, 3);
	real refPSF4_30 = 1.7494E-005;
	real loadPSF4_04 = PSF4.at<real>(2, 3);
	real refPSF4_04 = 2.8951E-007;
	bool checkPSF4_30 = Math::compareTwoNumbers_tolerance(loadPSF4_30, refPSF3_13, tolerancePSF);
	test_vec.push_back(checkPSF4_30);
	bool checkPSF4_04 = Math::compareTwoNumbers_tolerance(loadPSF4_04, refPSF3_23, tolerancePSF);
	test_vec.push_back(checkPSF4_04);
	inportExportData::exportCV_MatToExcel(PSF4, loaction, namePSF4);

	// check PSF 5
	real loadPSF5_41 = PSF5.at<real>(4, 1);
	real refPSF5_41 = 2.2275E-005;
	real loadPSF5_32 = PSF5.at<real>(3, 2);
	real refPSF5_32 = 2.0706E-005;
	bool checkPSF5_41 = Math::compareTwoNumbers_tolerance(loadPSF5_41, refPSF5_41, tolerancePSF);
	test_vec.push_back(checkPSF5_41);
	bool checkPSF5_32 = Math::compareTwoNumbers_tolerance(loadPSF5_32, refPSF5_32, tolerancePSF);
	test_vec.push_back(checkPSF5_32);
	inportExportData::exportCV_MatToExcel(PSF5, loaction, namePSF5);


	// check PSF 6
	real loadPSF6_33 = PSF6.at<real>(3, 3);
	real refPSF6_33 = 2.5545E-005;
	real loadPSF6_44 = PSF6.at<real>(4, 4);
	real refPSF6_44 = 4.5046E-005;
	bool checkPSF6_33 = Math::compareTwoNumbers_tolerance(loadPSF6_33, refPSF6_33, tolerancePSF);
	test_vec.push_back(checkPSF6_33);
	bool checkPSF6_44 = Math::compareTwoNumbers_tolerance(loadPSF6_44, refPSF6_44, tolerancePSF);
	test_vec.push_back(checkPSF6_44);
	inportExportData::exportCV_MatToExcel(PSF6, loaction, namePSF6);

	// check PSF 7
	real loadPSF7_12 = PSF7.at<real>(1, 2);
	real refPSF7_12 = 8.8751E-006;
	real loadPSF7_31 = PSF7.at<real>(3, 1);
	real refPSF7_31 = 3.9907E-006;
	bool checkPSF7_33 = Math::compareTwoNumbers_tolerance(loadPSF7_12, refPSF7_12, tolerancePSF);
	test_vec.push_back(checkPSF7_33);
	bool checkPSF7_44 = Math::compareTwoNumbers_tolerance(loadPSF7_31, refPSF7_31, tolerancePSF);
	test_vec.push_back(checkPSF7_44);
	inportExportData::exportCV_MatToExcel(PSF7, loaction, namePSF7);

	// check PSF 8
	real loadPSF8_56 = PSF8.at<real>(5, 6);
	real refPSF8_56 = 1.1101E-005;
	real loadPSF8_78 = PSF8.at<real>(7, 8);
	real refPSF8_78 = 7.9185E-006;
	bool checkPSF8_56 = Math::compareTwoNumbers_tolerance(loadPSF8_56, refPSF8_56, tolerancePSF);
	test_vec.push_back(checkPSF8_56);
	bool checkPSF8_78 = Math::compareTwoNumbers_tolerance(loadPSF8_78, refPSF8_78, tolerancePSF);
	test_vec.push_back(checkPSF8_78);
	inportExportData::exportCV_MatToExcel(PSF8, loaction, namePSF8);

	// load an image 
	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_sharp_squared_210x210.png", CV_LOAD_IMAGE_COLOR);
	// just for debugging
	// cv::imshow("elefant", elefantObj);
	
	ImageSimulationFunctions imaSim;
	std::vector<cv::Mat> PSF_vec = { PSF7,PSF1,PSF5,PSF4,PSF0,PSF3,PSF8,PSF2,PSF6 };
	// for the first test the PSF are independent from the color
	imaSim.loadPSFs_blue(PSF_vec);
	imaSim.loadPSFs_green(PSF_vec);
	imaSim.loadPSFs_red(PSF_vec);

	imaSim.setRowBiggerForConv(10);
	imaSim.setColBiggerForConv(10);

	imaSim.setGridFactor(3);
	imaSim.imageSimulationSuperFct(elefantObj);

	cv::Mat simulatedIma = imaSim.getSimulatedImage();
	// save the simulated image
	Images::saveImage(loaction, "elefantSim_s0", "png", simulatedIma);
	

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

bool TestImageSimulation::test1()
{
	real tolerancePSF = 0.001;
	std::vector<bool> test_vec;
	
	std::string loaction = "../tests/testImageSimulation/s1";
	std::string namePSF0 = "PSF(0,0)";
	std::string namePSF1 = "PSF(0,0.5)";
	std::string namePSF2 = "PSF(0,-0.5)";
	std::string namePSF3 = "PSF(0.5,0)";
	std::string namePSF4 = "PSF(-0.5,0)";
	std::string namePSF5 = "PSF(0.5,0.5)";
	std::string namePSF6 = "PSF(0.5,-0.5)";
	std::string namePSF7 = "PSF(-0.5,0.5)";
	std::string namePSF8 = "PSF(-0.5,-0.5)";


	// load all PSFs from txt data

	cv::Mat PSF0 = inportExportData::importTXTtoCVmat(loaction, namePSF0, 128, 128);
	cv::Mat PSF1 = inportExportData::importTXTtoCVmat(loaction, namePSF1, 128, 128);
	cv::Mat PSF2 = inportExportData::importTXTtoCVmat(loaction, namePSF2, 128, 128);
	cv::Mat PSF3 = inportExportData::importTXTtoCVmat(loaction, namePSF3, 128, 128);
	cv::Mat PSF4 = inportExportData::importTXTtoCVmat(loaction, namePSF4, 128, 128);
	cv::Mat PSF5 = inportExportData::importTXTtoCVmat(loaction, namePSF5, 128, 128);
	cv::Mat PSF6 = inportExportData::importTXTtoCVmat(loaction, namePSF6, 128, 128);
	cv::Mat PSF7 = inportExportData::importTXTtoCVmat(loaction, namePSF7, 128, 128);
	cv::Mat PSF8 = inportExportData::importTXTtoCVmat(loaction, namePSF8, 128, 128);

	// check PSF 0
	real loadPSF0_00 = PSF0.at<real>(0, 0);
	real refPSF0_00 = 2.0366E-005;
	bool checkPSF0_00 = Math::compareTwoNumbers_tolerance(loadPSF0_00, refPSF0_00, tolerancePSF);
	test_vec.push_back(checkPSF0_00);

	// check PSF 1
	real loadPSF1_56 = PSF1.at<real>(5, 6);
	real refPSF1_56 = 8.1727E-006;
	bool checkPSF1_56 = Math::compareTwoNumbers_tolerance(loadPSF1_56, refPSF1_56, tolerancePSF);
	test_vec.push_back(checkPSF1_56);

	// check PSF 2
	real loadPSF2_02 = PSF2.at<real>(0, 2);
	real refPSF2_02 = 1.8021E-005;
	bool checkPSF2_02 = Math::compareTwoNumbers_tolerance(loadPSF2_02, refPSF2_02, tolerancePSF);
	test_vec.push_back(checkPSF2_02);

	// check PSF 3
	real loadPSF3_13 = PSF3.at<real>(1, 3);
	real refPSF3_13 = 2.0976E-005;
	bool checkPSF3_13 = Math::compareTwoNumbers_tolerance(loadPSF3_13, refPSF3_13, tolerancePSF);
	test_vec.push_back(checkPSF3_13);

	// check PSF 4
	real loadPSF4_30 = PSF4.at<real>(1, 3);
	real refPSF4_30 = 2.7048E-005;
	bool checkPSF4_30 = Math::compareTwoNumbers_tolerance(loadPSF4_30, refPSF3_13, tolerancePSF);
	test_vec.push_back(checkPSF4_30);

	// check PSF 5
	real loadPSF5_41 = PSF5.at<real>(4, 1);
	real refPSF5_41 = 2.7836E-006;
	bool checkPSF5_41 = Math::compareTwoNumbers_tolerance(loadPSF5_41, refPSF5_41, tolerancePSF);
	test_vec.push_back(checkPSF5_41);

	// check PSF 6
	real loadPSF6_33 = PSF6.at<real>(3, 3);
	real refPSF6_33 = 1.4392E-005;
	bool checkPSF6_33 = Math::compareTwoNumbers_tolerance(loadPSF6_33, refPSF6_33, tolerancePSF);
	test_vec.push_back(checkPSF6_33);

	// check PSF 7
	real loadPSF7_12 = PSF7.at<real>(1, 2);
	real refPSF7_12 = 8.8570E-006;
	bool checkPSF7_33 = Math::compareTwoNumbers_tolerance(loadPSF7_12, refPSF7_12, tolerancePSF);
	test_vec.push_back(checkPSF7_33);

	// check PSF 8
	real loadPSF8_56 = PSF8.at<real>(5, 6);
	real refPSF8_56 = 3.0011E-007;
	bool checkPSF8_56 = Math::compareTwoNumbers_tolerance(loadPSF8_56, refPSF8_56, tolerancePSF);
	test_vec.push_back(checkPSF8_56);
			
	// load an image 
	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_sharp_squared_840x840.png", CV_LOAD_IMAGE_COLOR);
	// just for debugging
	// cv::imshow("elefant", elefantObj);

	ImageSimulationFunctions imaSim;
	//std::vector<cv::Mat> PSF_vec = {PSF0,PSF0,PSF0,PSF0};
	std::vector<cv::Mat> PSF_vec = { PSF7,PSF1,PSF5,PSF4,PSF0,PSF3,PSF8,PSF2,PSF6 };
	//
	//std::vector<cv::Mat> PSF_vec;
	//unsigned sizePSF = 12 * 12;
	//PSF_vec.resize(sizePSF);
	//for (unsigned int i = 0; i < sizePSF; ++i)
	//{
	//	PSF_vec[i] = PSF0;
	//}
	//std::vector<cv::Mat> PSF_vec = { PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0 };
	imaSim.loadPSFs_blue(PSF_vec);
	imaSim.loadPSFs_green(PSF_vec);
	imaSim.loadPSFs_red(PSF_vec);

	imaSim.setGridFactor(12);
	imaSim.setRowBiggerForConv(10);
	imaSim.setColBiggerForConv(10);
	imaSim.imageSimulationSuperFct(elefantObj);
	//
	cv::Mat simulatedIma = imaSim.getSimulatedImage();
	// save the simulated image
	Images::saveImage(loaction, "elefantSim_s1", "png", simulatedIma);


	//// load an image randomLines
	//cv::Mat randomLines = cv::imread("../images/color/useThatImages/useThat/randomLines.png", CV_LOAD_IMAGE_COLOR);
	//imaSim.imageSimulationSuperFct(randomLines);
	//cv::Mat chessBoadSim = imaSim.getSimulatedImage();
	//// save the simulated image
	//Images::saveImage(loaction, "randomLines_s1", "png", chessBoadSim);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;

}

bool TestImageSimulation::test2()
{
	// imread the elefant 210 x 210
	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_sharp_squared_210x210.png", CV_LOAD_IMAGE_COLOR);

	cv::Mat finalImage = cv::Mat::zeros(cv::Size(210,210), CV_8UC3);

	cv::Mat part0 = elefantObj(cv::Range(0, 105), cv::Range(0, 105));
	cv::Mat part1 = elefantObj(cv::Range(0, 105), cv::Range(105, 210));
	cv::Mat part2 = elefantObj(cv::Range(105, 210), cv::Range(0, 105));
	cv::Mat part3 = elefantObj(cv::Range(105, 210), cv::Range(105, 210));

	part0.copyTo(finalImage(cv::Range(0, 105), cv::Range(0, 105)));
	part1.copyTo(finalImage(cv::Range(0, 105), cv::Range(105, 210)));
	part2.copyTo(finalImage(cv::Range(105, 210), cv::Range(0, 105)));
	part3.copyTo(finalImage(cv::Range(105, 210), cv::Range(105, 210)));

	Images::showImage_inputReal("final ima", finalImage);
	Images::saveImage("..", "finalImag", "png", finalImage);

	return true;
}

bool TestImageSimulation::test3()
{
	real tolerance = 0.01;
	std::vector<bool> test_vec;

	ImageSimulationFunctions imaSim;
	imaSim.calcPointsToSampleObject(/*semi weidth object*/ 3.0, /*semi height object*/ 2.0, /*sampling*/ 7, /*z pos obejct*/ 1.0);

	VectorStructR3 refPoint0 = { 3.0, 2.0, 1.0 };
	VectorStructR3 refPoint1 = { 2.0, 2.0, 1.0 };
	VectorStructR3 refPoint2 = { 1.0, 2.0, 1.0 };
	VectorStructR3 refPoint3 = { 0.0, 2.0, 1.0 };

	VectorStructR3 refPoint4 = { 3.0, 1.333, 1.0 };
	VectorStructR3 refPoint5 = { 2.0, 1.333, 1.0 };
	VectorStructR3 refPoint6 = { 1.0, 1.333, 1.0 };
	VectorStructR3 refPoint7 = { 0.0, 1.333, 1.0 };

	VectorStructR3 refPoint8 = { 3.0, 0.667, 1.0 };
	VectorStructR3 refPoint9 = { 2.0, 0.667, 1.0 };
	VectorStructR3 refPoint10 = { 1.0, 0.667, 1.0 };
	VectorStructR3 refPoint11 = { 0.0, 0.667, 1.0 };


	VectorStructR3 refPoint12 = { 3.0, 0.0, 1.0 };
	VectorStructR3 refPoint13 = { 2.0, 0.0, 1.0 };
	VectorStructR3 refPoint14 = { 1.0, 0.0, 1.0 };
	VectorStructR3 refPoint15 = { 0.0, 0.0, 1.0 };

	

	std::vector<VectorStructR3> refPointsVec = { refPoint0, refPoint1, refPoint2, refPoint3, refPoint4, refPoint5, refPoint6, refPoint7, refPoint8,
	refPoint9, refPoint10, refPoint11, refPoint12, refPoint13, refPoint14, refPoint15};

	bool checkRefPoints = Math::compareAllVectorElementsSTDVectorStructR3_tolerance(refPointsVec, imaSim.getPointsToSampleObj(), tolerance);
	test_vec.push_back(checkRefPoints);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

bool TestImageSimulation::test4()
{

	std::vector<bool> test_vec;
	real tolerance = 0.01;

	// test system
	// build the optical system
	ApertureStopElement AperStop0(/* semi height*/1.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1(/*radius*/ 30.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2(/*radius*/ 29.188, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3(/*radius*/ 30.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere4(/*radius*/ 40.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	PlanElement Plan5(/*semi height*/ 5.0, /*point*/{ 0.0,0.0,104.661 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	surfacePtr AperStop_ptr = AperStop0.clone();
	surfacePtr Sphere1_ptr = Sphere1.clone();
	surfacePtr Sphere2_ptr = Sphere2.clone();
	surfacePtr Sphere3_ptr = Sphere3.clone();
	surfacePtr Sphere4_ptr = Sphere4.clone();
	surfacePtr Plan5_ptr = Plan5.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ AperStop_ptr, Sphere1_ptr, Sphere2_ptr, Sphere3_ptr, Sphere4_ptr, Plan5_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSysEle(opticalSystem_ptr, interactions_ptr);

	// test the system
	std::vector<real> rms_Zemax{ 12.371,12.508,13.003 };
	bool testStart = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle, mObject_vec_012, mWavelenght_vec_dFC, rms_Zemax, 0.01, compareTOM_Zemax::comEqual);
	test_vec.push_back(testStart);

	// calculate OPDs
	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_sharp_squared_210x210.png", CV_LOAD_IMAGE_COLOR);
	ImageSimulationFunctions imaSim;
	imaSim.setOpticalSystemElement(optSysEle);
	imaSim.setDefaulParameter(mDefaulParaImaSim);

	// build all optical systems LLT
	imaSim.buildAllOptSysLLT_BGR();
	// calc points to sample object
	unsigned int samplinfTotalObject = 5;
	imaSim.calcPointsToSampleObject(/*semi weidth object*/ 2.0, /*semi height object*/ 2.0, /*sampling*/ samplinfTotalObject, /*z pos obejct*/ 0.0);
	// trace the rays and calculate OPS upsampled
	imaSim.calcALL_OPDs();

	cv::Mat OPD_blue_22 = imaSim.getOPD_blue()[0]; // OPD at position 2/2
	cv::Mat OPD_green_22 = imaSim.getOPD_green()[0]; // OPD at position 2/2
	cv::Mat OPD_red_22 = imaSim.getOPD_red()[0]; // OPD at position 2/2

	std::string location = "../tests/testImageSimulation/s4";
	inportExportData::exportCV_MatToExcel(OPD_blue_22, location, "blue22_s4");
	inportExportData::exportCV_MatToExcel(OPD_green_22, location, "green22_s4");
	inportExportData::exportCV_MatToExcel(OPD_red_22, location, "red22_s4");

	// test OPD
	Light_LLT light_blue;
	light_blue.setWavelength(486.1327);
	light_blue.setIntensity(1.0);
	light_blue.setJonesVector({ 1.0,1.0,1.0,1.0 });
	light_blue.setTypeLight(typeLight::typeLightRay);
	OPD testOPD;
	real testOPD_blue_0 = testOPD.OPD_singelRay_obj(imaSim.getOptSys_blue(), { 2.0,2.0,0.0 }, -1.0, 0.0, light_blue);
	real refTestOPD_blue_0 = 0.268;
	bool checkTestOPD_blue_0 = Math::compareTwoNumbers_tolerance(testOPD_blue_0, refTestOPD_blue_0, tolerance);
	test_vec.push_back(checkTestOPD_blue_0);

	real testOPD_blue_1 = testOPD.OPD_singelRay_obj(imaSim.getOptSys_blue(), { 2.0,2.0,0.0 }, 1.0, 0.0, light_blue);
	real refTestOPD_blue_1 = 0.032;
	bool checkTestOPD_blue_1 = Math::compareTwoNumbers_tolerance(testOPD_blue_1, refTestOPD_blue_1, tolerance);
	test_vec.push_back(checkTestOPD_blue_1);

	Light_LLT light_green;
	light_green.setWavelength(587.5618);
	light_green.setIntensity(1.0);
	light_green.setJonesVector({ 1.0,1.0,1.0,1.0 });
	light_green.setTypeLight(typeLight::typeLightRay);

	real testOPD_green_0 = testOPD.OPD_singelRay_obj(imaSim.getOptSys_green(), { 2.0,2.0,0.0 }, -1.0, 0.0, light_green);
	real refTestOPD_green_0 = -0.418;
	bool checkTestOPD_green_0 = Math::compareTwoNumbers_tolerance(testOPD_green_0, refTestOPD_green_0, tolerance);
	test_vec.push_back(checkTestOPD_green_0);

	real testOPD_green_1 = testOPD.OPD_singelRay_obj(imaSim.getOptSys_green(), { 2.0,2.0,0.0 }, 1.0, 0.0, light_green);
	real refTestOPD_green_1 = -0.606;
	bool checkTestOPD_green_1 = Math::compareTwoNumbers_tolerance(testOPD_green_1, refTestOPD_green_1, tolerance);
	test_vec.push_back(checkTestOPD_green_1);

	Light_LLT light_red;
	light_red.setWavelength(656.2725);
	light_red.setIntensity(1.0);
	light_red.setJonesVector({ 1.0,1.0,1.0,1.0 });
	light_red.setTypeLight(typeLight::typeLightRay);
	real testOPD_red_0 = testOPD.OPD_singelRay_obj(imaSim.getOptSys_red(), { 2.0,2.0,0.0 }, -1.0, 0.0, light_red);
	real refTestOPD_red_0 = -0.626;
	bool checkTestOPD_red_0 = Math::compareTwoNumbers_tolerance(testOPD_red_0, refTestOPD_red_0, tolerance);
	test_vec.push_back(checkTestOPD_red_0);

	real testOPD_red_1 = testOPD.OPD_singelRay_obj(imaSim.getOptSys_red(), { 2.0,2.0,0.0 }, 1.0, 0.0, light_red);
	real refTestOPD_red_1 = -0.791;
	bool checkTestOPD_red_1 = Math::compareTwoNumbers_tolerance(testOPD_red_1, refTestOPD_red_1, tolerance);
	test_vec.push_back(checkTestOPD_red_1);

	real refIndex_blue = imaSim.getOptSys_blue().getPosAndInteractingSurface().at(1).getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	real refIndex_green = imaSim.getOptSys_green().getPosAndInteractingSurface().at(1).getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	real refIndex_red = imaSim.getOptSys_red().getPosAndInteractingSurface().at(1).getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	test_vec.push_back(refIndex_blue > refIndex_green);
	test_vec.push_back(refIndex_green > refIndex_red);

	// resize all OPDs  
	imaSim.resizeAllOPDs();

	// check resize OPDs
	cv::Mat OPD_resized_blue_22 = imaSim.getOPD_resized_blue()[0];
	cv::Mat OPD_resized_green_22 = imaSim.getOPD_resized_green()[0];
	cv::Mat OPD_resized_red_22 = imaSim.getOPD_resized_red()[0];
	inportExportData::exportCV_MatToExcel(OPD_resized_blue_22, location, "blue22_resized_s4");
	inportExportData::exportCV_MatToExcel(OPD_resized_green_22, location, "green22_resized_s4");
	inportExportData::exportCV_MatToExcel(OPD_resized_red_22, location, "red22_resized_s4");

	// check calc PSF
	PSF PSF_fft;
	cv::Mat psf22_blue = PSF_fft.calcPSF_FFT_P_Fct(OPD_blue_22);
	cv::Mat psf22_blue_resized = PSF_fft.calcPSF_FFT_P_Fct(OPD_resized_blue_22);
	cv::Mat psf22_green = PSF_fft.calcPSF_FFT_P_Fct(OPD_green_22);
	cv::Mat psf22_green_resized = PSF_fft.calcPSF_FFT_P_Fct(OPD_resized_green_22);
	cv::Mat psf22_red = PSF_fft.calcPSF_FFT_P_Fct(OPD_red_22);
	cv::Mat psf22_red_resized = PSF_fft.calcPSF_FFT_P_Fct(OPD_resized_red_22);

	// just for debugging
	Images::showImage_inputReal("psf blue", psf22_blue);
	Images::showImage_inputReal("psf blue resized", psf22_blue_resized);
	Images::showImage_inputReal("psf green", psf22_green);
	Images::showImage_inputReal("psf green resized", psf22_green_resized);
	Images::showImage_inputReal("psf red", psf22_red);
	Images::showImage_inputReal("psf red resized", psf22_red_resized);

	// save all PSFs
	Images::saveImage(location, "psf blue 22", "png", psf22_blue);
	Images::saveImage(location, "psf blue 22 resized", "png", psf22_blue_resized);
	Images::saveImage(location, "psf green 22", "png", psf22_green);
	Images::saveImage(location, "psf green 22 resized", "png", psf22_green_resized);
	Images::saveImage(location, "psf red 22", "png", psf22_red);
	Images::saveImage(location, "psf red 22 resized", "png", psf22_red_resized);

	//// calculate all PSFs
	//imaSim.calcAllPSFs();
	//// greate more PSFs between the calcualted PSFs
	//imaSim.sampleUP_PSFs_horizontal(samplinfTotalObject);   
	//imaSim.sampleUP_PSFs_vertical(samplinfTotalObject);
	//// rotate the PSFs to get all PSFs for convolution
	//imaSim.calcAllPSFsForConv_Q1(samplinfTotalObject);
	//imaSim.calcAllPSFsForConv_Q2andQ3(samplinfTotalObject);
	//// convolute the object with the corresponding PSF


	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}


bool TestImageSimulation::test5()
{
	std::vector<bool> test_vec;

	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_sharp_squared_210x210.png", CV_LOAD_IMAGE_COLOR);
	ImageSimulationFunctions imaSim;

	cv::Mat rotIma = imaSim.rotateMatrixBy_90degrees(elefantObj);
	real checkRot1015 = rotIma.at<cv::Vec3b>(10, 15)[0];
	bool checkRotation = Math::compareTwoNumbers_tolerance(checkRot1015, 154, 0.1);
	test_vec.push_back(checkRotation);

	cv::Mat flipedVertical = imaSim.flipMatrixVertical(elefantObj);
	real checkFlipVer = flipedVertical.at<cv::Vec3b>(20, 31)[0];
	bool chFlipVer = Math::compareTwoNumbers_tolerance(checkFlipVer, 114, 0.1);
	test_vec.push_back(chFlipVer);

	cv::Mat flipedHori = imaSim.flipMatrixHorizontal(elefantObj);
	real checkFlipHori = flipedHori.at<cv::Vec3b>(56, 16)[0];
	bool chFlipHori = Math::compareTwoNumbers_tolerance(checkFlipHori, 139, 0.1);
	test_vec.push_back(chFlipHori);

	// just for debugging
	Images::showImage_inputUint8("rotIma", rotIma);

	// just for debugging
	Images::showImage_inputUint8("flipVer", flipedVertical);

	// just for debugging
	Images::showImage_inputUint8("flipHor", flipedHori);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

bool TestImageSimulation::test6()
{
	cv::Mat inpPSF = inportExportData::importTXTtoCVmat("../", "s0_P0_mod", 64, 64);

	real test = inpPSF.at<real>(0, 0);
	real ref = 3.7957E-005;

	bool checker = Math::compareTwoNumbers_tolerance(test, ref, 0.001);

	return checker;

}

bool TestImageSimulation::test7()
{
	real tolerancePSF = 0.001;
	std::vector<bool> test_vec;

	std::string loaction = "../tests/testImageSimulation/s7";
	std::string namePSF0 = "PSF(0,0)";

	cv::Mat PSF0 = inportExportData::importTXTtoCVmat(loaction, namePSF0, 128, 128);
	
	//cv::Mat PSFtest = inportExportData::importTXTtoCVmat(loaction, namePSF0, 64, 64);
	//std::vector<cv::Mat> test;
	//test.push_back(PSF0);
	//test.push_back(PSFtest);

	// load an image 
	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_sharp_squared_840x840.png", CV_LOAD_IMAGE_COLOR);
	// just for debugging
	// cv::imshow("elefant", elefantObj);

	ImageSimulationFunctions imaSim;
	unsigned int sampling = 5;
	
	std::vector<cv::Mat> PSF_vec;
	unsigned sizePSF = sampling * sampling;
	PSF_vec.resize(sizePSF);
	for (unsigned int i = 0; i < sizePSF; ++i)
	{
		PSF_vec[i] = PSF0;
	}

	imaSim.loadPSFs_blue(PSF_vec);
	imaSim.loadPSFs_green(PSF_vec);
	imaSim.loadPSFs_red(PSF_vec);

	imaSim.setGridFactor(sampling);
	imaSim.setRowBiggerForConv(10);
	imaSim.setColBiggerForConv(10);
	imaSim.imageSimulationSuperFct(elefantObj);
	//
	cv::Mat simulatedIma = imaSim.getSimulatedImage();
	// save the simulated image
	Images::saveImage(loaction, "elefantSim_s1", "png", simulatedIma);
	
	// just for debugging
	Images::showImage_inputUint8("simulated elefant", simulatedIma);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;


}