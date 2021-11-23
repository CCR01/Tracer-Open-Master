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

// Ray Aiming
#include "..\..\RayAiming\RayAiming.h"



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

	mDefaulParaImaSim.setWavelengthBlue(486.1327);
	mDefaulParaImaSim.setWavelengthGreen(587.5618);
	mDefaulParaImaSim.setWavelengthRed(656.2725);
	mDefaulParaImaSim.setRayDensity(6);

	//light
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	light.setJonesVector({ 1.0,1.0,1.0,1.0 });
	light.setTypeLight(typeLight::typeLightRay);

	mDefaulParaImaSim.setLight(light);
	mDefaulParaImaSim.setSizeMatrixToSaveOPD(128);
	mDefaulParaImaSim.setInfOrObj(objectPoint_inf_obj::obj);
	mDefaulParaImaSim.setRowColResizeOPD(64);
	mDefaulParaImaSim.setSampling_x(9);
	mDefaulParaImaSim.setSampling_y(11);
	mDefaulParaImaSim.setSemiHeightObj(2.0);
	mDefaulParaImaSim.setSemiWeidthObj(2.0);
	mDefaulParaImaSim.setPosition_Z_Object(0.0);
	mDefaulParaImaSim.setUpSamplePSF(true);
	mDefaulParaImaSim.setResizeOPD_linear(true);
	mDefaulParaImaSim.setPaddingFactorPSF(1);

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
	//
	//// test 3
	//bool checkTest3 = test3();
	//testSuperFct_vec.push_back(checkTest3);
	//
	//// test 4
	//bool checkTest4 = test4();
	//testSuperFct_vec.push_back(checkTest4);
	//
	////test 5
	//bool checkTest5 = test5();
	//testSuperFct_vec.push_back(checkTest5);
	//
	//// test 6
	//bool checkTest6 = test6();
	//testSuperFct_vec.push_back(checkTest6);
	//
	////test 7
	//bool checkTest7 = test7();
	//testSuperFct_vec.push_back(checkTest7);
	//
	//// test 8
	//bool checkTest8 = test8();
	//testSuperFct_vec.push_back(checkTest8);
	//
	//// test 9
	//bool checkTest9 = test9();
	//testSuperFct_vec.push_back(checkTest9);
	//
	//// test 10
	//bool checkTest10 = test10();
	//testSuperFct_vec.push_back(checkTest10);

	// test 11
	bool checkTest11 = test11();
	testSuperFct_vec.push_back(checkTest11);
	
	// test 12
	//bool checkTest12 = test12();
	//testSuperFct_vec.push_back(checkTest12);

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

	// just for debugging
	//Images::showImage_inputReal("PSF0", PSF0);

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

	//Images::showImage_inputReal_normTheImage("final ima", finalImage);
	std::string locationS2 = "../tests/testImageSimulation/s2";
	Images::saveImage_normalized("..", "finalImag", "png", finalImage);

	return true;
}

bool TestImageSimulation::test3()
{
	real tolerance = 0.01;
	std::vector<bool> test_vec;

	// parameter
	loadParaImaSim paraImaSimTest3;
	paraImaSimTest3.setSampling_x(7);
	paraImaSimTest3.setSampling_y(7);
	paraImaSimTest3.setSemiHeightObj(2.0);
	paraImaSimTest3.setSemiWeidthObj(3.0);
	paraImaSimTest3.setPosition_Z_Object(1.0);

	ImageSimulationFunctions imaSim;
	imaSim.setInitialParameters(paraImaSimTest3);
	//imaSim.calcPointsToSampleObject(/*semi weidth object*/ 3.0, /*semi height object*/ 2.0, /*sampling*/ 7, /*z pos obejct*/ 1.0);
	imaSim.calcPointsToSampleObject();

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
	real tolerancePSF = 0.000001;

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

	// parameter
	loadParaImaSim paraImaSimTest4;
	paraImaSimTest4.setSampling_x(5);
	paraImaSimTest4.setSampling_y(5);
	paraImaSimTest4.setSemiHeightObj(2.0);
	paraImaSimTest4.setSemiWeidthObj(3.0);
	paraImaSimTest4.setPosition_Z_Object(1.0);
	paraImaSimTest4.setLight(oftenUse::getDefaultLight());
	paraImaSimTest4.setWavelengthBlue(400.0);
	paraImaSimTest4.setWavelengthGreen(550.0);
	paraImaSimTest4.setWavelengthRed(700.0);
	paraImaSimTest4.setRayDensity(12);
	paraImaSimTest4.setInfOrObj(objectPoint_inf_obj::obj);
	paraImaSimTest4.setSizeMatrixToSaveOPD(63);
	paraImaSimTest4.setPaddingFactorPSF(1);
	paraImaSimTest4.setResizeOPD_linear(true);
	paraImaSimTest4.setUpSamplePSF(true);
	paraImaSimTest4.setRowColResizeOPD(paraImaSimTest4.getSizeMatrixToSaveOPD() * 2.0);

	ImageSimulationFunctions imaSim;
	imaSim.setOpticalSystemElement(optSysEle);
	imaSim.setInitialParameters(paraImaSimTest4);

	// build all optical systems LLT
	imaSim.getRefIndexBeforeFirstSurface();
	imaSim.buildAllOptSysLLT_BGR();
	imaSim.calcPointsToSampleObject();
	imaSim.calcALL_OPDs();
	std::string location;
	cv::Mat OPD_blue_22;
	cv::Mat OPD_green_22;
	cv::Mat OPD_red_22;

	//// calculate all PSFs
	imaSim.checkForResizeOPD();
	imaSim.calcAllPSFs();
	cv::Mat PSF_blue_22 = imaSim.getCalcPSF_blue()[0];
	cv::Mat PSF_green_22 = imaSim.getCalcPSF_green()[0];
	cv::Mat PSF_red_22 = imaSim.getCalcPSF_red()[0];


	//// greate more PSFs between the calcualted PSFs
	imaSim.upSample_PSFs_horizontal(); 

	bool checkPSF_blue_up_horizontal = Images::checkImagesSame_64FC1(imaSim.getSampledUpPSF_horizontal_blue()[2], imaSim.getCalcPSF_blue()[1], tolerancePSF);
	test_vec.push_back(checkPSF_blue_up_horizontal);

	cv::Mat testSampledUp_blue = (imaSim.getCalcPSF_blue()[1] + imaSim.getCalcPSF_blue()[0]) / 2;
	bool testCheckPSF_blue_up_horizontal = Images::checkImagesSame_64FC1(testSampledUp_blue, imaSim.getSampledUpPSF_horizontal_blue()[1], tolerancePSF);
	test_vec.push_back(testCheckPSF_blue_up_horizontal);

	bool checkPSF_green_up_horizontal = Images::checkImagesSame_64FC1(imaSim.getSampledUpPSF_horizontal_green()[2], imaSim.getCalcPSF_green()[1], tolerancePSF);
	test_vec.push_back(checkPSF_green_up_horizontal);

	cv::Mat testSampledUp_green = (imaSim.getCalcPSF_green()[1] + imaSim.getCalcPSF_green()[0]) / 2;
	bool testCheckPSF_green_up_horizontal = Images::checkImagesSame_64FC1(testSampledUp_green, imaSim.getSampledUpPSF_horizontal_green()[1], tolerancePSF);
	test_vec.push_back(testCheckPSF_green_up_horizontal);

	bool checkPSF_red_up_horizontal = Images::checkImagesSame_64FC1(imaSim.getSampledUpPSF_horizontal_red()[2], imaSim.getCalcPSF_red()[1], tolerancePSF);
	test_vec.push_back(checkPSF_red_up_horizontal);

	cv::Mat testSampledUp_red = (imaSim.getCalcPSF_red()[1] + imaSim.getCalcPSF_red()[0]) / 2;
	bool testCheckPSF_red_up_horizontal = Images::checkImagesSame_64FC1(testSampledUp_red, imaSim.getSampledUpPSF_horizontal_red()[1], tolerancePSF);
	test_vec.push_back(testCheckPSF_red_up_horizontal);



	imaSim.upSample_PSFs_vertical();

	cv::Mat psf_blue_9 = imaSim.getSampledUpPSF_horizontal_blue()[9];
	cv::Mat psf_blue_14 = imaSim.getSampledUpPSF_horizontal_blue()[14];
	cv::Mat psf_blue_upSampled_19 = (psf_blue_9 + psf_blue_14) / 2;
	bool check19_blue = Images::checkImagesSame_64FC1(psf_blue_upSampled_19, imaSim.getSampledUpPSF_vertical_blue()[19], tolerancePSF);
	test_vec.push_back(check19_blue);


	cv::Mat psf_green_9 = imaSim.getSampledUpPSF_horizontal_green()[9];
	cv::Mat psf_green_14 = imaSim.getSampledUpPSF_horizontal_green()[14];
	cv::Mat psf_green_upSampled_19 = (psf_green_9 + psf_green_14) / 2;
	bool check19_green = Images::checkImagesSame_64FC1(psf_green_upSampled_19, imaSim.getSampledUpPSF_vertical_green()[19], tolerancePSF);
	test_vec.push_back(check19_green);
	
	cv::Mat psf_red_9 = imaSim.getSampledUpPSF_horizontal_red()[9];
	cv::Mat psf_red_14 = imaSim.getSampledUpPSF_horizontal_red()[14];
	cv::Mat psf_red_upSampled_19 = (psf_red_9 + psf_red_14) / 2;
	bool check19_red = Images::checkImagesSame_64FC1(psf_red_upSampled_19, imaSim.getSampledUpPSF_vertical_red()[19], tolerancePSF);
	test_vec.push_back(check19_red);

	//// rotate the PSFs to get all PSFs for convolution
	imaSim.calcAllPSFsForConv_Q1();

	unsigned int size = imaSim.getAllPSFsForConvolution_blue().size();
	bool checkSize = size == 81;
	test_vec.push_back(checkSize);

	cv::Mat calcPSF_blue_19 = imaSim.getAllPSFsForConvolution_blue()[19];
	cv::Mat refPSF_blue_19 = imaSim.flipMatrixVertical(imaSim.getSampledUpPSF_vertical_blue()[11]);
	bool checkPSF_blue_19 = Images::checkImagesSame_64FC1(calcPSF_blue_19, refPSF_blue_19, tolerancePSF);
	test_vec.push_back(checkPSF_blue_19);

	cv::Mat calcPSF_green_19 = imaSim.getAllPSFsForConvolution_green()[19];
	cv::Mat refPSF_green_19 = imaSim.flipMatrixVertical(imaSim.getSampledUpPSF_vertical_green()[11]);
	bool checkPSF_green_19 = Images::checkImagesSame_64FC1(calcPSF_green_19, refPSF_green_19, tolerancePSF);
	test_vec.push_back(checkPSF_green_19);

	cv::Mat calcPSF_red_19 = imaSim.getAllPSFsForConvolution_red()[19];
	cv::Mat refPSF_red_19 = imaSim.flipMatrixVertical(imaSim.getSampledUpPSF_vertical_red()[11]);
	bool checkPSF_red_19 = Images::checkImagesSame_64FC1(calcPSF_red_19, refPSF_red_19, tolerancePSF);
	test_vec.push_back(checkPSF_red_19);

	imaSim.calcAllPSFsForConv_Q2andQ3();

	cv::Mat refPSF_blue_11_flipH = imaSim.flipMatrixHorizontal(imaSim.getAllPSFsForConvolution_blue()[11]);
	cv::Mat calcPSF_blue_65 = imaSim.getAllPSFsForConvolution_blue()[65];
	bool checkPSF65_blue = Images::checkImagesSame_64FC1(refPSF_blue_11_flipH, calcPSF_blue_65, tolerancePSF);
	test_vec.push_back(checkPSF65_blue);

	cv::Mat refPSF_blue_7_flipH = imaSim.flipMatrixHorizontal(imaSim.getAllPSFsForConvolution_blue()[7]);
	cv::Mat calcPSF_blue_79 = imaSim.getAllPSFsForConvolution_blue()[79];
	bool checkPSF79_blue = Images::checkImagesSame_64FC1(refPSF_blue_7_flipH, calcPSF_blue_79, tolerancePSF);
	test_vec.push_back(checkPSF79_blue);

	cv::Mat refPSF_green_11_flipH = imaSim.flipMatrixHorizontal(imaSim.getAllPSFsForConvolution_green()[11]);
	cv::Mat calcPSF_green_65 = imaSim.getAllPSFsForConvolution_green()[65];
	bool checkPSF65_green = Images::checkImagesSame_64FC1(refPSF_green_11_flipH, calcPSF_green_65, tolerancePSF);
	test_vec.push_back(checkPSF65_green);

	cv::Mat refPSF_green_7_flipH = imaSim.flipMatrixHorizontal(imaSim.getAllPSFsForConvolution_green()[7]);
	cv::Mat calcPSF_green_79 = imaSim.getAllPSFsForConvolution_green()[79];
	bool checkPSF79_green = Images::checkImagesSame_64FC1(refPSF_green_7_flipH, calcPSF_green_79, tolerancePSF);
	test_vec.push_back(checkPSF79_green);

	cv::Mat refPSF_red_11_flipH = imaSim.flipMatrixHorizontal(imaSim.getAllPSFsForConvolution_red()[11]);
	cv::Mat calcPSF_red_65 = imaSim.getAllPSFsForConvolution_red()[65];
	bool checkPSF65_red = Images::checkImagesSame_64FC1(refPSF_red_11_flipH, calcPSF_red_65, tolerancePSF);
	test_vec.push_back(checkPSF65_red);

	cv::Mat refPSF_red_7_flipH = imaSim.flipMatrixHorizontal(imaSim.getAllPSFsForConvolution_red()[7]);
	cv::Mat calcPSF_red_79 = imaSim.getAllPSFsForConvolution_red()[79];
	bool checkPSF79_red = Images::checkImagesSame_64FC1(refPSF_red_7_flipH, calcPSF_red_79, tolerancePSF);
	test_vec.push_back(checkPSF79_red);

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
	//Images::showImage_inputUint8("rotIma", rotIma);

	// just for debugging
	//Images::showImage_inputUint8("flipVer", flipedVertical);

	// just for debugging
	//Images::showImage_inputUint8("flipHor", flipedHori);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

bool TestImageSimulation::test6()
{
	std::vector<bool> test_vec;
	real tolerance = 0.1;

	// load color image
	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_sharp_squared_210x210.png", CV_LOAD_IMAGE_COLOR);

	// parameter
	loadParaImaSim paraImaSimTest6;
	paraImaSimTest6.setSampling_x(5);
	paraImaSimTest6.setSampling_y(3);
	paraImaSimTest6.setSemiHeightObj(2.0);
	paraImaSimTest6.setSemiWeidthObj(3.0);
	paraImaSimTest6.setPosition_Z_Object(0.0);
	paraImaSimTest6.setLight(oftenUse::getDefaultLight());
	paraImaSimTest6.setWavelengthBlue(400.0);
	paraImaSimTest6.setWavelengthGreen(550.0);
	paraImaSimTest6.setWavelengthRed(700.0);
	paraImaSimTest6.setRayDensity(12);
	paraImaSimTest6.setInfOrObj(objectPoint_inf_obj::obj);
	paraImaSimTest6.setSizeMatrixToSaveOPD(63);
	paraImaSimTest6.setPaddingFactorPSF(1);
	paraImaSimTest6.setResizeOPD_linear(true);
	paraImaSimTest6.setUpSamplePSF(true);
	paraImaSimTest6.setRowColResizeOPD(paraImaSimTest6.getSizeMatrixToSaveOPD() * 2.0);


	ImageSimulationFunctions imaSim;
	imaSim.setInitialParameters(paraImaSimTest6);
	imaSim.setInitialObject(elefantObj);
	imaSim.calcWidthAccordingToHeight();
	imaSim.calcPointsToSampleObject();

	real semiWidth = imaSim.getLoadParameterImaSim().getSemiWidthObj();
	real semiHeight = imaSim.getLoadParameterImaSim().getSemiHeightObj();
	bool checkWandH = Math::compareTwoNumbers_tolerance(semiWidth, semiHeight, tolerance);
	test_vec.push_back(checkWandH);

	// checkPoints
	VectorStructR3 refP_0 = { 2.0,2.0,0.0 };
	VectorStructR3 refP_1 = { 1.0,2.0,0.0 };
	VectorStructR3 refP_2 = { 0.0,2.0,0.0 };
	VectorStructR3 refP_3 = { 2.0,0.0,0.0 };
	VectorStructR3 refP_4 = { 1.0,0.0,0.0 };
	VectorStructR3 refP_5 = { 0.0,0.0,0.0 };

	std::vector<VectorStructR3> refPointsVec = { refP_0, refP_1, refP_2, refP_3, refP_4, refP_5};
	std::vector<VectorStructR3> pointsSampleObj = imaSim.getPointsToSampleObj();

	bool checkRefPoints = Math::compareAllVectorElementsSTDVectorStructR3_tolerance(refPointsVec, pointsSampleObj, tolerance);
	test_vec.push_back(checkRefPoints);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;

}

bool TestImageSimulation::test7()
{
	real tolerance = 0.001;
	std::vector<bool> test_vec;

	// load color image
	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_sharp_250x188.png", CV_LOAD_IMAGE_COLOR);

	// parameter
	loadParaImaSim paraImaSimTest6;
	paraImaSimTest6.setSampling_x(11);
	paraImaSimTest6.setSampling_y(7);
	paraImaSimTest6.setSemiHeightObj(2.0);
	paraImaSimTest6.setSemiWeidthObj(3.0);
	paraImaSimTest6.setPosition_Z_Object(0.0);

	ImageSimulationFunctions imaSim;
	imaSim.setInitialParameters(paraImaSimTest6);
	imaSim.setInitialObject(elefantObj);
	imaSim.calcWidthAccordingToHeight();
	imaSim.calcPointsToSampleObject();

	real semiWidth = imaSim.getLoadParameterImaSim().getSemiWidthObj();
	real semiHeight = imaSim.getLoadParameterImaSim().getSemiHeightObj();
	bool checkHeight = Math::compareTwoNumbers_tolerance(semiHeight, paraImaSimTest6.getSemiHeightObj(), tolerance);
	test_vec.push_back(checkHeight);
	bool checkWidth = Math::compareTwoNumbers_tolerance(semiWidth,2.6596, tolerance);
	test_vec.push_back(checkWidth);

	int refPointSize = imaSim.getPointsToSampleObj().size();
	int calcRefPointSize = 6 * 4;
	bool checkRefPointSize = Math::compareTwoNumbers_tolerance(refPointSize, calcRefPointSize, tolerance);
	test_vec.push_back(checkRefPointSize);

	std::vector<VectorStructR3> allRefP = imaSim.getPointsToSampleObj();
	VectorStructR3 refP_0{ semiWidth , semiHeight , 0.0 };
	VectorStructR3 refP_9{ 1.0638,1.333,0.0 };
	VectorStructR3 refP_14{ 1.5957,0.666,0.0 };
	VectorStructR3 refP_23 = { 0.0,0.0,0.0 };

	VectorStructR3 calcP_0 = allRefP[0];
	VectorStructR3 calcP_9 = allRefP[9];
	VectorStructR3 calcP_14 = allRefP[14];
	VectorStructR3 calcP_23 = allRefP[23];

	bool checkP_0 = Math::compareTwoVectorStructR3_tolerance(calcP_0, refP_0, tolerance);
	test_vec.push_back(checkP_0);
	bool checkP_9 = Math::compareTwoVectorStructR3_tolerance(calcP_9, refP_9, tolerance);
	test_vec.push_back(checkP_9);
	bool checkP_14 = Math::compareTwoVectorStructR3_tolerance(calcP_14, refP_14, tolerance);
	test_vec.push_back(checkP_14);
	bool checkP_23 = Math::compareTwoVectorStructR3_tolerance(calcP_23, refP_23, tolerance);
	test_vec.push_back(checkP_23);



	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;


}

bool TestImageSimulation::test8()
{
	// load an image 
	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_sharp_squared_840x840.png", CV_LOAD_IMAGE_COLOR);

	// load PSF
	std::string loaction = "../tests/testImageSimulation/s8";
	std::string namePSF0 = "s1_centerPSF";
	cv::Mat loadPSF = inportExportData::importTXTtoCVmat(loaction, namePSF0, 128, 128);
	
	// convolut image with PSF
	ImageSimulationFunctions imaSim;
	cv::Mat simulatedImage = imaSim.convolution_BGR_uint8(elefantObj, loadPSF);

	// show the simulated ima
	//Images::showImage_inputReal_normTheImage("simulated ima", simulatedImage);
	

	// save the simulated ima
	Images::saveImage_normalized("..", "simulatedIma", "png", simulatedImage);

	return true;
}

bool TestImageSimulation::test9()
{
	std::vector<bool> test_vec;
	real tolerance = 0.01;
	std::string location = "../tests/testImageSimulation/s9";

	// load object
	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_sharp_250x188.png", CV_LOAD_IMAGE_COLOR);

	// test system
	// build the optical system
	ApertureStopElement AperStop0(/* semi height*/1.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1(/*radius*/ 20.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2(/*radius*/ 36.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF5_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3(/*radius*/ 20.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	PlanElement Plan4(/*semi height*/ 5.0, /*point*/{ 0.0,0.0,105.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	
	surfacePtr AperStop_ptr = AperStop0.clone();
	surfacePtr Sphere1_ptr = Sphere1.clone();
	surfacePtr Sphere2_ptr = Sphere2.clone();
	surfacePtr Sphere3_ptr = Sphere3.clone();
	surfacePtr Plan4_ptr = Plan4.clone();
	
	std::vector<surfacePtr> opticalSystem_ptr{ AperStop_ptr, Sphere1_ptr, Sphere2_ptr, Sphere3_ptr, Plan4_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSysEle(opticalSystem_ptr, interactions_ptr);
	//
	// test the system
	std::vector<real> rms_Zemax{ 13.1,13.789,15.986 };
	bool testStart = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle, mObject_vec_012, mWavelenght_vec_dFC, rms_Zemax, 0.01, compareTOM_Zemax::comEqual);
	test_vec.push_back(testStart);

	ImageSimulationFunctions imaSim;

	loadParaImaSim parameterTest10 = mDefaulParaImaSim;
	parameterTest10.setSampling_x(5);
	parameterTest10.setSampling_y(5);
	parameterTest10.setUpSamplePSF(true);
	parameterTest10.setSizeMatrixToSaveOPD(32);
	parameterTest10.setRowColResizeOPD(64);
	parameterTest10.setSemiHeightObj(1.0);
	parameterTest10.setCalcDistortion(false);
	parameterTest10.setPaddingFactorPSF(1);
	imaSim.imageSimulationSuperFct(/*optical System Element*/ optSysEle, /*object*/ elefantObj, /*parameter*/ parameterTest10);

	cv::Mat simIma = imaSim.getSimulatedImage_initialSize();
	Images::saveImage_normalized(location, "simImaTest", "png", simIma);

	//std::vector<cv::Mat> imaGrid_blue = imaSim.getAll


	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}



bool TestImageSimulation::test10()
{
	std::vector<bool> test_vec;

	real tolerance = 0.01;
	real tolerancePSF = 0.000001;
	std::string location = "../tests/testImageSimulation/s10";

	// test system
	// build the optical system
	ApertureStopElement AperStop0(/* semi height*/1.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1(/*radius*/ 30.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2(/*radius*/ 36.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3(/*radius*/ 60.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSF5_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere4(/*radius*/ 40.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement Sphere5(/*radius*/ 27.040, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF10_S1());
	SphericalElement Sphere6(/*radius*/ 50.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF10_S1());
	PlanElement Plan7(/*semi height*/ 5.0, /*point*/{ 0.0,0.0,120.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	
	surfacePtr AperStop_ptr = AperStop0.clone();
	surfacePtr Sphere1_ptr = Sphere1.clone();
	surfacePtr Sphere2_ptr = Sphere2.clone();
	surfacePtr Sphere3_ptr = Sphere3.clone();
	surfacePtr Sphere4_ptr = Sphere4.clone();
	surfacePtr Sphere5_ptr = Sphere5.clone();
	surfacePtr Sphere6_ptr = Sphere6.clone();
	surfacePtr Plan7_ptr = Plan7.clone();
	
	std::vector<surfacePtr> opticalSystem_ptr{ AperStop_ptr, Sphere1_ptr, Sphere2_ptr, Sphere3_ptr, Sphere4_ptr, Sphere5_ptr, Sphere6_ptr, Plan7_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSysEle(opticalSystem_ptr, interactions_ptr);
	
	// test the system
	std::vector<real> rms_Zemax{ 13.463,14.163,16.195 };
	bool testStart = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle, mObject_vec_012, mWavelenght_vec_dFC, rms_Zemax, 0.01, compareTOM_Zemax::comEqual);
	test_vec.push_back(testStart);

	// load object
	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_900x900.png", CV_LOAD_IMAGE_COLOR);
	//just for debugging
	//Images::showImage_inputUint8("loaded image", elefantObj);

	ImageSimulationFunctions imaSim;

	loadParaImaSim parameterTest10 = mDefaulParaImaSim;
	parameterTest10.setSampling_x(11);
	parameterTest10.setSampling_y(11);
	parameterTest10.setUpSamplePSF(false);
	parameterTest10.setSizeMatrixToSaveOPD(32);
	parameterTest10.setRowColResizeOPD(64);
	parameterTest10.setSemiHeightObj(4.0);
	parameterTest10.setSemiWeidthObj(4.0);
	parameterTest10.setCalcDistortion(true);
	parameterTest10.setSamplingDistortionHeight(450);
	parameterTest10.setSamplingDistortionWidth(450);

	imaSim.imageSimulationSuperFct(/*optical System Element*/ optSysEle, /*object*/ elefantObj, /*parameter*/ parameterTest10);

	cv::Mat simulatedIma = imaSim.getSimulatedImage_initialSize();
	// just for debugging
	Images::showImage_inputReal_normTheImage("simulated ima test 10", simulatedIma);
	// save the simulate images
	Images::saveImage_normalized(location, "simImaTest10", "png", simulatedIma);

	 cv::Mat testIma = simulatedIma * 255;
	cv::imwrite("../tests/testImageSimulation/s10/test.png", testIma);


	bool checkResultsImaSim = checkImaSim_test10(imaSim, /*show*/ false);
	test_vec.push_back(checkResultsImaSim);

	// just for debugging
	cv::Mat channel[3];
	cv::split(simulatedIma, channel);
	cv::Mat blueImage = channel[0];
	cv::Mat greenImage = channel[1];
	cv::Mat redImage = channel[2];

	real min_blue{};
	real max_blue{};
	cv::Point minLoc_blue, maxLoc_blue;
	cv::minMaxLoc(blueImage, &min_blue, &max_blue, &minLoc_blue, &maxLoc_blue);
	std::cout << "min: " << min_blue << std::endl;
	std::cout << "max: " << max_blue << std::endl;
	std::cout << "max location blue: " << maxLoc_blue << std::endl;

	real min_green{};
	real max_green{};
	cv::Point minLoc_green, maxLoc_green;
	cv::minMaxLoc(greenImage, &min_green, &max_green, &minLoc_green, &maxLoc_green);
	std::cout << "min: " << min_green << std::endl;
	std::cout << "max: " << max_green << std::endl;
	std::cout << "max location green: " << maxLoc_green << std::endl;

	real min_red{};
	real max_red{};
	cv::Point minLoc_red, maxLoc_red;
	cv::minMaxLoc(redImage, &min_red, &max_red, &minLoc_red, &maxLoc_red);
	std::cout << "min: " << min_red << std::endl;
	std::cout << "max: " << max_red << std::endl;
	std::cout << "max location red: " << maxLoc_red << std::endl;

	
	
	// load simulated image
	cv::Mat simIma_loaded = cv::imread("../tests/testImageSimulation/s10/test.png", CV_LOAD_IMAGE_COLOR);

	cv::Mat channel_loaded[3];
	cv::split(simIma_loaded, channel_loaded);
	cv::Mat blueImage_loaded = channel_loaded[0];
	cv::Mat greenImage_loaded = channel_loaded[1];
	cv::Mat redImage_loaded = channel_loaded[2];

	real min_blue_loaded{};
	real max_blue_loaded{};
	cv::Point minLoc_blue_loaded, maxLoc_blue_loaded;
	cv::minMaxLoc(blueImage_loaded, &min_blue_loaded, &max_blue_loaded, &minLoc_blue_loaded, &maxLoc_blue_loaded);
	std::cout << "min: " << min_blue_loaded << std::endl;
	std::cout << "max: " << max_blue_loaded << std::endl;
	std::cout << "max location blue: " << maxLoc_blue_loaded << std::endl;

	real min_green_loaded{};
	real max_green_loaded{};
	cv::Point minLoc_green_loaded, maxLoc_green_loaded;
	cv::minMaxLoc(greenImage_loaded, &min_green_loaded, &max_green_loaded, &minLoc_green_loaded, &maxLoc_green_loaded);
	std::cout << "min: " << min_green_loaded << std::endl;
	std::cout << "max: " << max_green_loaded << std::endl;
	std::cout << "max location green: " << maxLoc_green_loaded << std::endl;

	real min_red_loaded{};
	real max_red_loaded{};
	cv::Point minLoc_red_loaded, maxLoc_red_loaded;
	cv::minMaxLoc(redImage_loaded, &min_red_loaded, &max_red_loaded, &minLoc_red_loaded, &maxLoc_red_loaded);
	std::cout << "min: " << min_red_loaded << std::endl;
	std::cout << "max: " << max_red_loaded << std::endl;
	std::cout << "max location red: " << maxLoc_red_loaded << std::endl;


	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

bool TestImageSimulation::test11()
{
	
	std::vector<bool> test_vec;
	real tolerance = 0.01;
	std::string location = "../tests/testImageSimulation/s11";

	// load object
	cv::Mat chessBoard_12x8 = cv::imread("../images/color/useThatImages/useThat/chessboard12x8.png", CV_LOAD_IMAGE_COLOR);
	cv::Mat chessBoard_8x8 = cv::imread("../images/color/useThatImages/useThat/chessBoard8x8_900x900.png", CV_LOAD_IMAGE_COLOR);


	// test system
	// build the optical system
	ApertureStopElement AperStop0(/* semi height*/1.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1(/*radius*/ 20.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2(/*radius*/ 36.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF5_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3(/*radius*/ 20.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	PlanElement Plan4(/*semi height*/ 5.0, /*point*/{ 0.0,0.0,105.41320334 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	surfacePtr AperStop_ptr = AperStop0.clone();
	surfacePtr Sphere1_ptr = Sphere1.clone();
	surfacePtr Sphere2_ptr = Sphere2.clone();
	surfacePtr Sphere3_ptr = Sphere3.clone();
	surfacePtr Plan4_ptr = Plan4.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ AperStop_ptr, Sphere1_ptr, Sphere2_ptr, Sphere3_ptr, Plan4_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSysEle(opticalSystem_ptr, interactions_ptr);
	//
	// test the system
	std::vector<real> rms_Zemax{ 11.514,13.204,17.596 };
	bool testStart = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle, mObject_vec_012, mWavelenght_vec_dFC, rms_Zemax, 0.01, compareTOM_Zemax::comEqual);
	test_vec.push_back(testStart);


	// *** chess board 12 x 8 ***
	ImageSimulationFunctions imaSimChessBoard12x8;
	loadParaImaSim parameterCB_12x8 = mDefaulParaImaSim;
	parameterCB_12x8.setSampling_x(5);
	parameterCB_12x8.setSampling_y(5);
	parameterCB_12x8.setUpSamplePSF(false);
	parameterCB_12x8.setSizeMatrixToSaveOPD(32);
	parameterCB_12x8.setRowColResizeOPD(64);
	parameterCB_12x8.setSemiHeightObj(1.0);
	parameterCB_12x8.setCalcDistortion(false);
	parameterCB_12x8.setPaddingFactorPSF(1);
	imaSimChessBoard12x8.imageSimulationSuperFct(/*optical System Element*/ optSysEle, /*object*/ chessBoard_12x8, /*parameter*/ parameterCB_12x8);
	cv::Mat simImaChessBoard12x8 = imaSimChessBoard12x8.getSimulatedImage_initialSize();
	Images::saveImage_normalized(location, "simImaChessBoard12x8", "png", simImaChessBoard12x8);
	// *** ***

		// *** chess board 8 x 8 ***
	ImageSimulationFunctions imaSimChessBoard8x8;
	loadParaImaSim parameterCB_8x8 = mDefaulParaImaSim;
	parameterCB_8x8.setSampling_x(5);
	parameterCB_8x8.setSampling_y(5);
	parameterCB_8x8.setUpSamplePSF(false);
	parameterCB_8x8.setSizeMatrixToSaveOPD(32);
	parameterCB_8x8.setRowColResizeOPD(64);
	parameterCB_8x8.setSemiHeightObj(1.0);
	parameterCB_8x8.setCalcDistortion(false);
	parameterCB_8x8.setPaddingFactorPSF(1);
	imaSimChessBoard8x8.imageSimulationSuperFct(/*optical System Element*/ optSysEle, /*object*/ chessBoard_8x8, /*parameter*/ parameterCB_8x8);
	cv::Mat simImaChessBoard8x8 = imaSimChessBoard8x8.getSimulatedImage_initialSize();
	Images::saveImage_normalized(location, "simImaChessBoard8x8", "png", simImaChessBoard8x8);
	// *** ***


	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}


bool TestImageSimulation::test12()
{
	std::vector<bool> test_vec;
	real tolerance = 0.5;
	std::string locationSaveIma = "../tests/testImageSimulation/s12";

	// test system
	// build the optical system
	SphericalElement S0(/*radius*/ 25.5,	/*semi height*/ 6.0, /*point*/{ 0.0,0.0,20000.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAK10_S1());
	SphericalElement S1(/*radius*/ 80.0,	/*semi height*/ 6.0, /*point*/{ 0.0,0.0,20003.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNF2_S1(), /*refractive index B*/glasses.getNLAK10_S1());
	SphericalElement S2(/*radius*/ 83.0,	/*semi height*/ 6.0, /*point*/{ 0.0,0.0,20004.5 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNF2_S1(), /*refractive index B*/glasses.getAir());

	SphericalElement S3(/*radius*/ 9.0,		/*semi height*/	6.0, /*point*/{ 0.0,0.0,20004.6 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement S4(/*radius*/ 6.66,	/*semi height*/ 4.0, /*point*/{ 0.0,0.0,20007.6 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getSF5_S1(), /*refractive index B*/glasses.getAir());

	ApertureStopElement S5(					/* semi height*/2.0, /*point*/{ 0.0,0.0,20010.6 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractiv index*/ glasses.getAir());

	SphericalElement S6(/*radius*/ 7.8,		/*semi height*/ 4.0, /*point*/{ 0.0,0.0,20013.6 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSF56_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement S7(/*radius*/ 108.0,	/*semi height*/ 6.0, /*point*/{ 0.0,0.0,20014.8 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNSF56_S1(), /*refractive index B*/glasses.getNLAF2_S1());
	SphericalElement S8(/*radius*/ 10.4,	/*semi height*/ 6.0, /*point*/{ 0.0,0.0,20018.8 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAF2_S1());

	SphericalElement S9(/*radius*/ 86.0,	/*semi height*/ 6.0, /*point*/{ 0.0,0.0,20018.9 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAF2_S1());
	SphericalElement S10(/*radius*/ 22.0,	/*semi height*/ 6.0, /*point*/{ 0.0,0.0,20021.9 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAF2_S1());

	PlanElement S11(						/*semi height*/ 5.0, /*point*/{ 0.0,0.0,20041.9 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();
	surfacePtr S11_ptr = S11.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr };
	std::vector<interaction_ptr> interactions_ptr{mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),  mRefrac.clone(), mRefrac.clone(), mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSysEle(opticalSystem_ptr, interactions_ptr);
	//
	// test the system
	std::vector<real> rms_Zemax{ 29.692,29.267,28.077,26.689,29.019,28.824,28.569,28.382 };
	std::vector<VectorStructR3> fieldVec = { {0.0,0.0,0.0},{0.0,1000.0,0.0}, {0.0,2000.0,0.0},{2000.0,2000.0,0.0},{1200.0,400.0,0.0}, {1200,800.0,0.0}, {1600.0,400.0,0.0}, {1600,800.0,0.0} };
	std::vector<real> waveVec = { 465.0,535.0,606.0 };
	bool testStart = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle, fieldVec, waveVec, rms_Zemax, tolerance, compareTOM_Zemax::comEqual);
	test_vec.push_back(testStart);

	ImageSimulationFunctions imaSim;

	loadParaImaSim parameterTest10 = mDefaulParaImaSim;
	parameterTest10.setSampling_x(13);
	parameterTest10.setSampling_y(13);
	parameterTest10.setUpSamplePSF(true);
	parameterTest10.setSizeMatrixToSaveOPD(32);
	parameterTest10.setRowColResizeOPD(64);
	parameterTest10.setSemiHeightObj(2000.0);
	parameterTest10.setSemiWeidthObj(2000.0);
	parameterTest10.setWavelengthBlue(waveVec[0]);
	parameterTest10.setWavelengthGreen(waveVec[1]);
	parameterTest10.setWavelengthRed(waveVec[2]);


	std::string locationImages = "../images/color/testImaSim_test12";
	std::string antelope = "antelope_900x900";
	std::string dragonfly = "dragonfly_900x900";
	std::string elefant = "elefant_900x900";
	std::string flower1 = "flower1_900x900";
	std::string flower2 = "flower2_900x900";
	std::string flower3 = "flower3_900x900";
	std::string landscape = "landscape_900x900";
	std::string pinguin = "pinguin_900x900";
	std::string rhino = "rhino_900x900";
	std::string salad = "salad_900x900";

	// *** load images *** ///
	cv::Mat antelopeIma = Images::loadAnImage_Color(locationImages, antelope);
	cv::Mat dragonflyIma = Images::loadAnImage_Color(locationImages, dragonfly);
	cv::Mat elefantIma = Images::loadAnImage_Color(locationImages, elefant);
	cv::Mat flower1Ima = Images::loadAnImage_Color(locationImages,flower1 );
	cv::Mat flower2Ima = Images::loadAnImage_Color(locationImages, flower2);
	cv::Mat flower3Ima = Images::loadAnImage_Color(locationImages, flower3);
	cv::Mat landscapeIma = Images::loadAnImage_Color(locationImages, landscape);
	cv::Mat pinguinIma = Images::loadAnImage_Color(locationImages, pinguin);
	cv::Mat rhinoIma = Images::loadAnImage_Color(locationImages, rhino);
	cv::Mat saladIma = Images::loadAnImage_Color(locationImages, salad);

	// norm B G R images
	Images::loadImage_BGR_AndNormAllColors(locationImages, antelope, locationImages, antelope);
	Images::loadImage_BGR_AndNormAllColors(locationImages, dragonfly, locationImages, dragonfly);
	Images::loadImage_BGR_AndNormAllColors(locationImages, elefant, locationImages, elefant);
	Images::loadImage_BGR_AndNormAllColors(locationImages, flower1, locationImages, flower1);
	Images::loadImage_BGR_AndNormAllColors(locationImages, flower2, locationImages, flower2);
	Images::loadImage_BGR_AndNormAllColors(locationImages, flower3, locationImages, flower3);
	Images::loadImage_BGR_AndNormAllColors(locationImages, landscape, locationImages, landscape);
	Images::loadImage_BGR_AndNormAllColors(locationImages, pinguin, locationImages, pinguin);
	Images::loadImage_BGR_AndNormAllColors(locationImages, rhino, locationImages, rhino);
	Images::loadImage_BGR_AndNormAllColors(locationImages, salad, locationImages, salad);

	// *** load normed images *** ///
	antelopeIma = Images::loadAnImage_Color(locationImages, antelope);
	dragonflyIma = Images::loadAnImage_Color(locationImages, dragonfly);
	elefantIma = Images::loadAnImage_Color(locationImages, elefant);
	flower1Ima = Images::loadAnImage_Color(locationImages, flower1);
	flower2Ima = Images::loadAnImage_Color(locationImages, flower2);
	flower3Ima = Images::loadAnImage_Color(locationImages, flower3);
	landscapeIma = Images::loadAnImage_Color(locationImages, landscape);
	pinguinIma = Images::loadAnImage_Color(locationImages, pinguin);
	rhinoIma = Images::loadAnImage_Color(locationImages, rhino);
	saladIma = Images::loadAnImage_Color(locationImages, salad);

	// *** antilope *** //
	imaSim.imageSimulationSuperFct(/*optical System Element*/ optSysEle, /*object*/ antelopeIma, /*parameter*/ parameterTest10);
	cv::Mat simIma_antelope = imaSim.getSimulatedImage_initialSize();
	Images::saveImage_normalized(locationSaveIma, "simIma_antelope", "png", simIma_antelope);
	// *** *** //

	// *** dragonfly *** //
	imaSim.imageSimulationSuperFct(/*optical System Element*/ optSysEle, /*object*/ dragonflyIma, /*parameter*/ parameterTest10);
	cv::Mat simIma_dragonfly = imaSim.getSimulatedImage_initialSize();
	Images::saveImage_normalized(locationSaveIma, "simIma_dragonfly", "png", simIma_dragonfly);
	// *** *** //

	// *** elefant *** //
	imaSim.imageSimulationSuperFct(/*optical System Element*/ optSysEle, /*object*/ elefantIma, /*parameter*/ parameterTest10);
	cv::Mat simIma_elefant = imaSim.getSimulatedImage_initialSize();
	Images::saveImage_normalized(locationSaveIma, "simIma_elefant", "png", simIma_elefant);
	// *** *** //

	// *** flower1 *** //
	imaSim.imageSimulationSuperFct(/*optical System Element*/ optSysEle, /*object*/ flower1Ima, /*parameter*/ parameterTest10);
	cv::Mat simIma_flower1 = imaSim.getSimulatedImage_initialSize();
	Images::saveImage_normalized(locationSaveIma, "simIma_flower1", "png", simIma_flower1);
	// *** *** //

	// *** flower2 *** //
	imaSim.imageSimulationSuperFct(/*optical System Element*/ optSysEle, /*object*/ flower2Ima, /*parameter*/ parameterTest10);
	cv::Mat simIma_flower2 = imaSim.getSimulatedImage_initialSize();
	Images::saveImage_normalized(locationSaveIma, "simIma_flower2", "png", simIma_flower2);
	// *** *** //

	// *** flower3 *** //
	imaSim.imageSimulationSuperFct(/*optical System Element*/ optSysEle, /*object*/ flower3Ima, /*parameter*/ parameterTest10);
	cv::Mat simIma_flower3 = imaSim.getSimulatedImage_initialSize();
	Images::saveImage_normalized(locationSaveIma, "simIma_flower3", "png", simIma_flower3);
	// *** *** //

	// *** landscape *** //
	imaSim.imageSimulationSuperFct(/*optical System Element*/ optSysEle, /*object*/ landscapeIma, /*parameter*/ parameterTest10);
	cv::Mat simIma_landscape = imaSim.getSimulatedImage_initialSize();
	Images::saveImage_normalized(locationSaveIma, "simIma_landscape", "png", simIma_landscape);
	// *** *** //

	// *** pinguin *** //
	imaSim.imageSimulationSuperFct(/*optical System Element*/ optSysEle, /*object*/ pinguinIma, /*parameter*/ parameterTest10);
	cv::Mat simIma_pinguin = imaSim.getSimulatedImage_initialSize();
	Images::saveImage_normalized(locationSaveIma, "simIma_pinguin", "png", simIma_pinguin);
	// *** *** //

	// *** rhino *** //
	imaSim.imageSimulationSuperFct(/*optical System Element*/ optSysEle, /*object*/ rhinoIma, /*parameter*/ parameterTest10);
	cv::Mat simIma_rhino = imaSim.getSimulatedImage_initialSize();
	Images::saveImage_normalized(locationSaveIma, "simIma_rhino", "png", simIma_rhino);
	// *** *** //

	// *** salad *** //
	imaSim.imageSimulationSuperFct(/*optical System Element*/ optSysEle, /*object*/ saladIma, /*parameter*/ parameterTest10);
	cv::Mat simIma_salad = imaSim.getSimulatedImage_initialSize();
	Images::saveImage_normalized(locationSaveIma, "simIma_salad", "png", simIma_salad);
	// *** *** //

	
	// just for debugging
	// cv::Mat simulatedIma = imaSim.getSimulatedImage_initialSize();
	// Images::showImage_inputReal_normTheImage("simulated ima test 10", simulatedIma);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

bool TestImageSimulation::checkImaSim_test10(ImageSimulationFunctions imaSim, bool show)
{
	std::string location = "../tests/testImageSimulation/s10";
	std::vector<bool> test_vec;

	// get the calculated OPDs
	cv::Mat calcOPD_blue_22 = imaSim.getOPD_blue()[0]; // OPD at position 2/2
	cv::Mat calcOPD_green_22 = imaSim.getOPD_green()[0]; // OPD at position 2/2
	cv::Mat calcOPD_red_22 = imaSim.getOPD_red()[0]; // OPD at position 2/2

	// import reference OPDs
	cv::Mat refOPD_blue_22 = inportExportData::importTXTtoCVmat(location, "OPD_22_blue", 32, 32);
	cv::Mat refOPD_green_22 = inportExportData::importTXTtoCVmat(location, "OPD_22_green", 32, 32);
	cv::Mat refOPD_red_22 = inportExportData::importTXTtoCVmat(location, "OPD_22_red", 32, 32);

	// save all OPDs
	Images::saveImage_normalized(location, "calcOPD_blue_22", "png", calcOPD_blue_22);
	Images::saveImage_normalized(location, "refOPD_blue_22", "png", refOPD_blue_22);
	Images::saveImage_normalized(location, "calcOPD_green_22", "png", calcOPD_green_22);
	Images::saveImage_normalized(location, "refOPD_green_22", "png", refOPD_green_22);
	Images::saveImage_normalized(location, "calcOPD_red_22", "png", calcOPD_red_22);
	Images::saveImage_normalized(location, "refOPD_red_22", "png", refOPD_red_22);

	if (show)
	{
		// show the blue OPD
		Images::showImage_inputReal_normTheImage("calc OPD blue", calcOPD_blue_22);
		Images::showImage_inputReal_normTheImage("ref OPD blue", refOPD_blue_22);

		// show the green OPD
		Images::showImage_inputReal_normTheImage("calc OPD green", calcOPD_green_22);
		Images::showImage_inputReal_normTheImage("ref OPD green", refOPD_green_22);

		// show the green OPD
		Images::showImage_inputReal_normTheImage("calc OPD red", calcOPD_red_22);
		Images::showImage_inputReal_normTheImage("ref OPD red", refOPD_red_22);
	}



	// check calc PSF
	// get the calculated PSFs
	cv::Mat calcPSF_blue_22 = imaSim.getCalcPSF_blue()[0]; // OPD at position 2/2
	cv::Mat calcPSF_green_22 = imaSim.getCalcPSF_green()[0]; // OPD at position 2/2
	cv::Mat calcPSF_red_22 = imaSim.getCalcPSF_red()[0]; // OPD at position 2/2

	// import reference PSF
	cv::Mat refPSF_blue_22 = inportExportData::importTXTtoCVmat(location, "PSF_22_blue", 64, 64);
	cv::Mat refPSF_green_22 = inportExportData::importTXTtoCVmat(location, "PSF_22_green", 64, 64);
	cv::Mat refPSF_red_22 = inportExportData::importTXTtoCVmat(location, "PSF_22_red", 64, 64);

	if (show)
	{
		// show the blue PSF
		Images::showImage_inputReal_normTheImage("calc PSF blue", calcPSF_blue_22);
		Images::showImage_inputReal_normTheImage("ref PSF blue", refPSF_blue_22);

		// show the green PSF
		Images::showImage_inputReal_normTheImage("calc PSF green", calcPSF_green_22);
		Images::showImage_inputReal_normTheImage("ref PSF green", refPSF_green_22);

		// show the green PSF
		Images::showImage_inputReal_normTheImage("calc PSF red", calcPSF_red_22);
		Images::showImage_inputReal_normTheImage("ref PSF red", refPSF_red_22);
	}


	// save all PSFs
	Images::saveImage_normalized(location, "calcPSF_blue_22", "png", calcPSF_blue_22);
	Images::saveImage_normalized(location, "refPSF_blue_22", "png", refPSF_blue_22);
	Images::saveImage_normalized(location, "calcPSF_green_22", "png", calcPSF_green_22);
	Images::saveImage_normalized(location, "refPSF_green_22", "png", refPSF_green_22);
	Images::saveImage_normalized(location, "calcPSF_red_22", "png", calcPSF_red_22);
	Images::saveImage_normalized(location, "refPSF_red_22", "png", refPSF_red_22);

	if(show)
	{ 
		// show all PSFs 
		cv::Size targetSize(840, 840);
		showAllPSFsInAnImageAndSave(imaSim.getAllPSFsForConvolution_blue(), targetSize, location, "allPSFs_blue", true);
		showAllPSFsInAnImageAndSave(imaSim.getAllPSFsForConvolution_green(), targetSize, location, "allPSFs_green", true);
		showAllPSFsInAnImageAndSave(imaSim.getAllPSFsForConvolution_red(), targetSize, location, "allPSFs_red", true);
	}

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;

}


// show all PSFs in an image
void TestImageSimulation::showAllPSFsInAnImageAndSave(const std::vector<cv::Mat>& psf_vec, cv::Size targetSize, std::string location, std::string nameSave, bool show)
{
	unsigned int rowSize = psf_vec[0].size().height;
	unsigned int colSize = psf_vec[0].size().width;

	unsigned int numberHeightAndWidth = std::sqrt(psf_vec.size());

	unsigned targetRow = rowSize * numberHeightAndWidth;
	unsigned targetCol = colSize * numberHeightAndWidth;


	cv::Mat allPSFs_ima = cv::Mat::zeros(cv::Size(targetRow, targetCol), CV_64FC1);
	unsigned int counter = 0;

	cv::Mat tempPSF{};
	unsigned int tempStartRow = 0;
	unsigned int tempEndRow = rowSize;
	unsigned int tempStartCol = 0;
	unsigned int tempEndCol = colSize;

	for (unsigned int i = 0; i < numberHeightAndWidth; ++i)
	{
		for (unsigned int j = 0; j < numberHeightAndWidth; ++j)
		{
			tempPSF = psf_vec[counter](cv::Range(0, rowSize), cv::Range(0, colSize));
			tempPSF.copyTo(allPSFs_ima(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol)));

			tempStartCol = tempEndCol;
			tempEndCol = tempEndCol + colSize;

			++counter;
		}

		tempStartCol = 0;
		tempEndCol = colSize;

		tempStartRow = tempEndRow;
		tempEndRow = tempStartRow + rowSize;
	}

	//cv2.resize(src, dsize[, dst[, fx[, fy[, interpolation]]]])

	cv::Mat resizedImaAllPSF{};
	cv::resize(allPSFs_ima, resizedImaAllPSF, targetSize, cv::INTER_LANCZOS4);

	if(show)
	{
		// show the image
		Images::showImage_inputReal_normTheImage(nameSave, resizedImaAllPSF);
	}


	// save the final Image
	Images::saveImage_normalized(location, nameSave, "png", resizedImaAllPSF);

}