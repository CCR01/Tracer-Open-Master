#include "testDistortion.h"

#include "..\..\Analyse\Distortion.h"

// inport export data
#include "..\..\Inport_Export_Data\Inport_Export_Data.h"

// images
#include "..\..\Image\Images.h"

// often use
#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

// surfaces
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"

// interaction
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"

typedef std::shared_ptr<SurfaceIntersectionRay_LLT> surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

testDistortion::testDistortion() {};

testDistortion::~testDistortion() {};

// test distortion super 
bool testDistortion::testDistortion_superFuction()
{
	std::vector<bool> test_vec{};
	//// test 0
	//bool check0 = test0();
	//test_vec.push_back(check0);
	//// test 1
	//bool check1 = test1();
	//test_vec.push_back(check1);
	// test 2
	//bool check2 = test2();
	//test_vec.push_back(check2);
	//// test 3
	//bool check3 = test3();
	//test_vec.push_back(check3);
	//test 4
	//bool check4 = test4();
	//test_vec.push_back(check4);
	//test 5
	//bool check5 = test5();
	//test_vec.push_back(check5);
	//test 6
	bool check6 = test6();
	test_vec.push_back(check6);

	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

// test 0;
bool testDistortion::test0()
{
	std::vector<bool> test_vec{};

	std::string location = "../tests/testDistortion/s0";
	std::string nameToLoad = "s0_x";

	cv::Mat mapX_loaded = inportExportData::importTXTtoCVmat(location, nameToLoad, 10, 10);
	mapX_loaded.convertTo(mapX_loaded, CV_32F);
	cv::Mat mapX_resized;

	cv::resize(mapX_loaded, mapX_resized, cv::Size(210, 210), cv::INTER_LANCZOS4);
	cv::Mat mapY;

	cv::Point2f src_center(mapX_resized.cols / 2.0F, mapX_resized.rows / 2.0F);
	cv::Mat rotMat = cv::getRotationMatrix2D(src_center, -90.0, 1.0);
	cv::warpAffine(mapX_resized, mapY, rotMat, mapX_resized.size());

	cv::Mat elefantObj_210 = cv::imread("../images/color/useThatImages/useThat/elefant_sharp_squared_210x210.png", CV_LOAD_IMAGE_COLOR);

	Distortion dis;

	cv::Mat disIma;
	dis.calcDistortedIma(elefantObj_210, disIma, mapX_resized, mapY);

	// just for debugging
	Images::showImage_inputUint8("distorted ima", disIma);

	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;

}

// test 1
bool testDistortion::test1()
{
	std::vector<bool> test_vec{};
	real tolerace = 0.001;

	RefractedRay_LLT refrac{};
	DoNothingInteraction_LLT doNothing{};
	Absorb_LLT absorb{};

	// optical system
	//all the surfaces
	ApertureStop_LLT S0(/*semi height*/ 1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index*/ 1.0);
	SphericalSurface_LLT S1(/*radius*/30, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S2(/*radius*/30.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 30.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S3(/*radius*/40.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 40.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S4(/*radius*/40.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 50.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S5(/*semiHeight*/10.0, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	std::vector< surfacePtr> surfacePtr_vec = { S0.clone(),S1.clone(),S2.clone() ,S3.clone(),S4.clone(),S5.clone() };
	std::vector< interaction_ptr > interac_ptr = { doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(), absorb.clone() };

	OpticalSystem_LLT optSys;
	optSys.fillOptSysWithSurfaceAndInteractions(surfacePtr_vec, interac_ptr);

	// test the start system
	bool testStartSystem = oftenUse::checkOptSysLLT_Equal_Better_Zemax(optSys, { 0.0,0.0,0.0 }, 422.821, 0.01, compareTOM_Zemax::comEqual);
	test_vec.push_back(testStartSystem);

	Light_LLT light = oftenUse::getDefaultLight();


	// *** distortion 0
	Distortion dis0;
	real calcDis0 = dis0.calcDistortion_obj(optSys, { 0.0,2.0,0.0 }, light);
	real refDisY0 = -5.79476949;
	test_vec.push_back(Math::compareTwoNumbers_tolerance(calcDis0, refDisY0, tolerace));
	//***

	// *** distortion 1
	Distortion dis1;
	real calcDis1 = dis1.calcDistortion_obj(optSys, { 0.25,2.0,0.0 }, light);
	real refDis1 = -5.88338992;
	test_vec.push_back(Math::compareTwoNumbers_tolerance(calcDis1, refDis1, tolerace));
	//***

	// *** distortion 2
	Distortion dis2;
	real calcDis2 = dis2.calcDistortion_obj(optSys, { 1.0,2.0,0.0 }, light);
	real refDis2 = -7.20584049;
	test_vec.push_back(Math::compareTwoNumbers_tolerance(calcDis2, refDis2, tolerace));
	//***

	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

// test 2
bool testDistortion::test2()
{
	std::string location = "../tests/testDistortion/s2";
	std::vector<bool> test_vec{};
	real tolerance = 0.001;

	RefractedRay_LLT refrac{};
	DoNothingInteraction_LLT doNothing{};
	Absorb_LLT absorb{};

	// optical system
	//all the surfaces
	ApertureStop_LLT S0(/*semi height*/ 1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index*/ 1.0);
	SphericalSurface_LLT S1(/*radius*/30, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S2(/*radius*/30.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 30.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S3(/*radius*/40.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 40.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S4(/*radius*/40.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 50.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S5(/*semiHeight*/10.0, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	std::vector< surfacePtr> surfacePtr_vec = { S0.clone(),S1.clone(),S2.clone() ,S3.clone(),S4.clone(),S5.clone() };
	std::vector< interaction_ptr > interac_ptr = { doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(), absorb.clone() };

	OpticalSystem_LLT optSys;
	optSys.fillOptSysWithSurfaceAndInteractions(surfacePtr_vec, interac_ptr);

	// test the start system
	bool testStartSystem = oftenUse::checkOptSysLLT_Equal_Better_Zemax(optSys, { 0.0,0.0,0.0 }, 422.821, 0.01, compareTOM_Zemax::comEqual);
	test_vec.push_back(testStartSystem);



	cv::Mat imaElefant = cv::imread("../images/gray/elefant_sharp_gray_small.png", CV_LOAD_IMAGE_COLOR);
	Light_LLT light = oftenUse::getDefaultLight();

	Distortion disFunc;
	disFunc.calculateDistortion_superFunction_obj(/*image*/ imaElefant, /*optical system LLT*/ optSys, /*lght*/ light, /*sampling height*/ 75, /*sampling width*/ 150, /*hight object*/ 3.0,/*width object*/ 5.0, /*start point Z*/ 0.0);


	//// *** export distortion map
	//cv::Mat disMap_Q0 = disFunc.getDistortionMap_Q0();
	//inportExportData::exportCV_MatToExcel(disMap_Q0, location, "disMap_Q0");
	//cv::Mat disMap_Q0_upsampled = disFunc.getDistortionMap_Q0_upsampled();
	//inportExportData::exportCV_MatToExcel(disMap_Q0_upsampled, location, "disMap_Q0_upsampled");
	//cv::Mat disMapQ1 = disFunc.getDistortionMap_Q1();
	//inportExportData::exportCV_MatToExcel(disMapQ1, location, "disMap_Q1");
	//cv::Mat disMap_Q0_Q1 = disFunc.getDistortionMap_Q0_Q1();
	//inportExportData::exportCV_MatToExcel(disMap_Q0_Q1, location, "disMap_Q0_Q1");
	//cv::Mat disMap_Q2_Q3 = disFunc.getDistortionMap_Q2_Q3();
	//inportExportData::exportCV_MatToExcel(disMap_Q2_Q3, location, "disMap_Q2_Q3");
	//cv::Mat disMap_total = disFunc.getTotalDistortionMap();
	//inportExportData::exportCV_MatToExcel(disMap_total, location, "disMap_total");
	//// ***


	//// check distortion map
	//int heightPos = disMap_total.size().height - 1;
	//int widthPos = disMap_total.size().width - 1;
	//float refVal = -11.9499;
	//float val0 = disMap_total.at<float>(0, 0);
	//float val1 = disMap_total.at<float>(0, widthPos);
	//float val2 = disMap_total.at<float>(heightPos, 0);
	//float val3 = disMap_total.at<float>(heightPos, widthPos);
	//bool check0 = Math::compareTwoNumbers_tolerance(val0, refVal, tolerance);
	//bool check1 = Math::compareTwoNumbers_tolerance(val1, refVal, tolerance);
	//bool check2 = Math::compareTwoNumbers_tolerance(val2, refVal, tolerance);
	//bool check3 = Math::compareTwoNumbers_tolerance(val3, refVal, tolerance);
	//test_vec.push_back(check0);
	//test_vec.push_back(check1);
	//test_vec.push_back(check2);
	//test_vec.push_back(check3);

	//float val4 = disMap_total.at<float>(5, 10);
	//float val4_1 = disMap_total.at<float>(heightPos - 5, widthPos - 10);
	//bool check4 = Math::compareTwoNumbers_tolerance(val4, val4_1, tolerance);
	//test_vec.push_back(check4);
	//
	//float val5 = disMap_total.at<float>(52, 41);
	//float val5_1 = disMap_total.at<float>(heightPos - 52, widthPos - 41);
	//bool check5 = Math::compareTwoNumbers_tolerance(val5, val5_1, tolerance);
	//test_vec.push_back(check5);
	//
	//float val6 = disMap_total.at<float>(66, 76);
	//float val6_1 = disMap_total.at<float>(heightPos - 66, widthPos - 76);
	//bool check6 = Math::compareTwoNumbers_tolerance(val6, val6_1, tolerance);
	//test_vec.push_back(check6);
	//
	//float val7 = disMap_total.at<float>(81, 89);
	//float val7_1 = disMap_total.at<float>(heightPos - 81, widthPos - 89);
	//bool check7 = Math::compareTwoNumbers_tolerance(val7, val7_1, tolerance);
	//test_vec.push_back(check7);

	//// check ramap matrix
	//cv::Mat remapMatrix_X = disFunc.getRemap_X();
	//inportExportData::exportCV_MatToExcel(remapMatrix_X, location, "remapMatrix_X");
	//cv::Mat remapMatrix_Y = disFunc.getRemap_Y();
	//inportExportData::exportCV_MatToExcel(remapMatrix_Y, location, "remapMatrix_Y");

	// distorted image
	cv::Mat distortedIma = disFunc.getDistortedImage();

	// save the distorted image
	Images::saveImage_normalized(location, "distortedImageS2", "png", distortedIma);

	// just for debugging
	// Images::showImage_inputUint8("distortedImage", distortedIma);

	// correct distortion
	cv::Mat disCorrectedIma = disFunc.correctDistortion();
	// just for debugging
	Images::showImage_inputUint8("distortion corrected ima", disCorrectedIma);

	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

// test 3
bool testDistortion::test3()
{
	std::string location = "../tests/testDistortion/s3";
	std::vector<bool> test_vec{};
	real tolerance = 0.001;

	RefractedRay_LLT refrac{};
	DoNothingInteraction_LLT doNothing{};
	Absorb_LLT absorb{};

	// optical system
	//all the surfaces

	SphericalSurface_LLT S0(/*radius*/5.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 5.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S1(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	ApertureStop_LLT S2(/*semi height*/ 1.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index*/ 1.0);
	SphericalSurface_LLT S3(/*radius*/40.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 35.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S4(/*radius*/10.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 45.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S5(/*radius*/15.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 55.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S6(/*radius*/18.07516306, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 65.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S7(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	std::vector< surfacePtr> surfacePtr_vec = { S0.clone(),S1.clone(),S2.clone() ,S3.clone(),S4.clone(),S5.clone(), S6.clone(), S7.clone() };
	std::vector< interaction_ptr > interac_ptr = { refrac.clone(), refrac.clone(), doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(),refrac.clone(), absorb.clone() };

	OpticalSystem_LLT optSys;
	optSys.fillOptSysWithSurfaceAndInteractions(surfacePtr_vec, interac_ptr);

	// test the start system
	bool testStartSystem = oftenUse::checkOptSysLLT_Equal_Better_Zemax(optSys, { 0.0,0.0,0.0 }, 82.119, 0.01, compareTOM_Zemax::comEqual);
	test_vec.push_back(testStartSystem);

	cv::Mat imaElefant = cv::imread("../images/gray/elefant_sharp_gray_small.png", CV_LOAD_IMAGE_COLOR);
	Light_LLT light = oftenUse::getDefaultLight();

	Distortion disFunc;
	disFunc.calculateDistortion_superFunction_obj(/*image*/ imaElefant, /*optical system LLT*/ optSys, /*lght*/ light, /*sampling height*/ 100, /*sampling width*/ 200, /*hight object*/ 0.5,/*width object*/ 1.0, /*start point Z*/ 0.0);

	cv::Mat distortedIma = disFunc.getDistortedImage();

	// *** export distortion map
	cv::Mat disMap_Q0 = disFunc.getDistortionMap_Q0();
	inportExportData::exportCV_MatToExcel(disMap_Q0, location, "disMap_Q0");
	cv::Mat disMap_Q0_upsampled = disFunc.getDistortionMap_Q0_upsampled();
	inportExportData::exportCV_MatToExcel(disMap_Q0_upsampled, location, "disMap_Q0_upsampled");
	cv::Mat disMapQ1 = disFunc.getDistortionMap_Q1();
	inportExportData::exportCV_MatToExcel(disMapQ1, location, "disMap_Q1");
	cv::Mat disMap_Q0_Q1 = disFunc.getDistortionMap_Q0_Q1();
	inportExportData::exportCV_MatToExcel(disMap_Q0_Q1, location, "disMap_Q0_Q1");
	cv::Mat disMap_Q2_Q3 = disFunc.getDistortionMap_Q2_Q3();
	inportExportData::exportCV_MatToExcel(disMap_Q2_Q3, location, "disMap_Q2_Q3");
	cv::Mat disMap_total = disFunc.getTotalDistortionMap();
	inportExportData::exportCV_MatToExcel(disMap_total, location, "disMap_total");
	// check ramap matrix
	cv::Mat remapMatrix_X = disFunc.getRemap_X();
	inportExportData::exportCV_MatToExcel(remapMatrix_X, location, "remapMatrix_X");
	cv::Mat remapMatrix_Y = disFunc.getRemap_Y();
	inportExportData::exportCV_MatToExcel(remapMatrix_Y, location, "remapMatrix_Y");
	// ***

	// just for debugging
	Images::showImage_inputUint8("distorted image", distortedIma);

	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;

}

// test 4
bool testDistortion::test4()
{
	std::string location = "../tests/testDistortion/s4";
	std::vector<bool> test_vec{};
	real tolerance = 0.001;

	RefractedRay_LLT refrac{};
	DoNothingInteraction_LLT doNothing{};
	Absorb_LLT absorb{};

	// optical system
	//all the surfaces
	ApertureStop_LLT S0(/*semi height*/ 1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index*/ 1.0);
	PlanGeometry_LLT S1(/*semiHeight*/10.0, /*point*/{ 0.0,0.0,10.1 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.5);
	SphericalSurface_LLT S2(/*radius*/10.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 20.1 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S3(/*radius*/15.6, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 30.1 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S4(/*radius*/30.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 40.1 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S5(/*radius*/10.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 50.1 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S6(/*radius*/5.7, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 60.1 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	PlanGeometry_LLT S7(/*semiHeight*/30.0, /*point*/{ 0.0,0.0,110.1 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	std::vector< surfacePtr> surfacePtr_vec = { S0.clone(),S1.clone(),S2.clone() ,S3.clone(),S4.clone(),S5.clone(), S6.clone(), S7.clone() };
	std::vector< interaction_ptr > interac_ptr = { doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	OpticalSystem_LLT optSys;
	optSys.fillOptSysWithSurfaceAndInteractions(surfacePtr_vec, interac_ptr);

	// test the start system
	bool testStartSystem = oftenUse::checkOptSysLLT_Equal_Better_Zemax(optSys, { 0.0,0.0,0.0 }, 19.527, 0.01, compareTOM_Zemax::comEqual);
	test_vec.push_back(testStartSystem);



	cv::Mat checkBoard = cv::imread("../images/gray/chessBoard640x480.png", CV_LOAD_IMAGE_GRAYSCALE);
	cv::resize(checkBoard, checkBoard, cv::Size(320, 240), cv::INTER_LANCZOS4);
	Light_LLT light = oftenUse::getDefaultLight();

	Distortion disFunc;
	disFunc.calculateDistortion_superFunction_obj(/*image*/ checkBoard, /*optical system LLT*/ optSys, /*lght*/ light, /*sampling height*/ 100, /*sampling width*/ 134, /*hight object*/ 2.0,/*width object*/ 2.67, /*start point Z*/ 0.0);

	//// *** export distortion map
	//cv::Mat disMap_Q0 = disFunc.getDistortionMap_Q0();
	//inportExportData::exportCV_MatToExcel(disMap_Q0, location, "disMap_Q0");
	//cv::Mat disMap_Q0_upsampled = disFunc.getDistortionMap_Q0_upsampled();
	//inportExportData::exportCV_MatToExcel(disMap_Q0_upsampled, location, "disMap_Q0_upsampled");
	//cv::Mat disMapQ1 = disFunc.getDistortionMap_Q1();
	//inportExportData::exportCV_MatToExcel(disMapQ1, location, "disMap_Q1");
	//cv::Mat disMap_Q0_Q1 = disFunc.getDistortionMap_Q0_Q1();
	//inportExportData::exportCV_MatToExcel(disMap_Q0_Q1, location, "disMap_Q0_Q1");
	//cv::Mat disMap_Q2_Q3 = disFunc.getDistortionMap_Q2_Q3();
	//inportExportData::exportCV_MatToExcel(disMap_Q2_Q3, location, "disMap_Q2_Q3");
	//cv::Mat disMap_total = disFunc.getTotalDistortionMap();
	//inportExportData::exportCV_MatToExcel(disMap_total, location, "disMap_total");
	//// check ramap matrix
	//cv::Mat remapMatrix_X = disFunc.getRemap_X();
	//inportExportData::exportCV_MatToExcel(remapMatrix_X, location, "remapMatrix_X");
	//cv::Mat remapMatrix_Y = disFunc.getRemap_Y();
	//inportExportData::exportCV_MatToExcel(remapMatrix_Y, location, "remapMatrix_Y");
	//// ***

	// distorted image
	cv::Mat distortedIma = disFunc.getDistortedImage();

	// save the distorted image
	Images::saveImage_normalized(location, "distortedImageS4", "png", distortedIma);

	// just for debugging
	Images::showImage_inputUint8("distortedImage", distortedIma);

	// total distortion map
	cv::Mat totalDistortionMap = disFunc.getTotalDistortionMap();

	cv::Mat distortionCorrectionIma = disFunc.correctDistortion();

	// just for debugging
	Images::showImage_inputUint8("distortionCorrectionIma", distortionCorrectionIma);

	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}


// test 5
bool testDistortion::test5()
{
	std::string location = "../tests/testDistortion/s5";
	std::vector<bool> test_vec{};
	real tolerance = 0.001;

	RefractedRay_LLT refrac{};
	DoNothingInteraction_LLT doNothing{};
	Absorb_LLT absorb{};

	// optical system
	//all the surfaces
	ApertureStop_LLT S0(/*semi height*/ 1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index*/ 1.0);
	SphericalSurface_LLT S1(/*radius*/30, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S2(/*radius*/30.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 30.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S3(/*radius*/40.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 40.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S4(/*radius*/40.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 50.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S5(/*semiHeight*/10.0, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	std::vector< surfacePtr> surfacePtr_vec = { S0.clone(),S1.clone(),S2.clone() ,S3.clone(),S4.clone(),S5.clone() };
	std::vector< interaction_ptr > interac_ptr = { doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(), absorb.clone() };

	OpticalSystem_LLT optSys;
	optSys.fillOptSysWithSurfaceAndInteractions(surfacePtr_vec, interac_ptr);

	// test the start system
	bool testStartSystem = oftenUse::checkOptSysLLT_Equal_Better_Zemax(optSys, { 0.0,0.0,0.0 }, 422.821, 0.01, compareTOM_Zemax::comEqual);
	test_vec.push_back(testStartSystem);

	cv::Mat chessBoard = cv::imread("../images/gray/chessBoard640x480.png", CV_LOAD_IMAGE_GRAYSCALE);
	Light_LLT light = oftenUse::getDefaultLight();

	Distortion disFunc;
	disFunc.calculateDistortion_superFunction_obj(/*image*/ chessBoard, /*optical system LLT*/ optSys, /*lght*/ light, /*sampling height*/ 1250, /*sampling width*/ 1667, /*hight object*/ 4.0,/*width object*/ 5.3333, /*start point Z*/ 0.0);


	// distorted image
	cv::Mat distortedImaChessBoard = disFunc.getDistortedImage();

	// save the distorted image
	Images::saveImage_normalized(location, "distortedImaChessBoardS5", "png", distortedImaChessBoard);

	// just for debugging
	// Images::showImage_inputUint8("distortedImage", distortedIma);

	// correct distortion
	cv::Mat disCorrectedIma = disFunc.correctDistortion();
	// just for debugging
	// Images::showImage_inputUint8("distortion corrected ima", disCorrectedIma);

	Images::saveImage_normalized(location, "distortedCorrectedImaChessBoardS5", "png", disCorrectedIma);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

// test 6
bool testDistortion::test6()
{
	std::string location = "../tests/testDistortion/s6";
	std::vector<bool> test_vec{};
	real tolerance = 0.001;

	RefractedRay_LLT refrac{};
	DoNothingInteraction_LLT doNothing{};
	Absorb_LLT absorb{};

	// optical system
	//all the surfaces
	ApertureStop_LLT S0(/*semi height*/ 1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index*/ 1.0);
	PlanGeometry_LLT S1(/*semiHeight*/10.0, /*point*/{ 0.0,0.0,10.1 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.5);
	SphericalSurface_LLT S2(/*radius*/10.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 20.1 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S3(/*radius*/15.6, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 30.1 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S4(/*radius*/30.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 40.1 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S5(/*radius*/10.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 50.1 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S6(/*radius*/5.7, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 60.1 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	PlanGeometry_LLT S7(/*semiHeight*/30.0, /*point*/{ 0.0,0.0,110.1 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	std::vector< surfacePtr> surfacePtr_vec = { S0.clone(),S1.clone(),S2.clone() ,S3.clone(),S4.clone(),S5.clone(), S6.clone(), S7.clone() };
	std::vector< interaction_ptr > interac_ptr = { doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	OpticalSystem_LLT optSys;
	optSys.fillOptSysWithSurfaceAndInteractions(surfacePtr_vec, interac_ptr);

	// test the start system
	bool testStartSystem = oftenUse::checkOptSysLLT_Equal_Better_Zemax(optSys, { 0.0,0.0,0.0 }, 19.527, 0.01, compareTOM_Zemax::comEqual);
	test_vec.push_back(testStartSystem);



	cv::Mat checkBoard = cv::imread("../images/gray/chessBoard640x480.png", CV_LOAD_IMAGE_GRAYSCALE);
	Light_LLT light = oftenUse::getDefaultLight();

	Distortion disFunc;
	disFunc.calculateDistortion_superFunction_obj(/*image*/ checkBoard, /*optical system LLT*/ optSys, /*lght*/ light,  /*sampling height*/ 1250, /*sampling width*/ 1667,  /*hight object*/ 3.0,/*width object*/ 4.0, /*start point Z*/ 0.0);


	// distorted image
	cv::Mat distortedIma = disFunc.getDistortedImage();

	// save the distorted image
	Images::saveImage_normalized(location, "distortedImageS6", "png", distortedIma);

	// just for debugging
	//Images::showImage_inputUint8("distortedImage", distortedIma);

	// total distortion map
	cv::Mat totalDistortionMap = disFunc.getTotalDistortionMap();

	cv::Mat distortionCorrectionIma = disFunc.correctDistortion();

	// save the distorted image
	Images::saveImage_normalized(location, "distortionCorrectionImaS6", "png", distortionCorrectionIma);

	// just for debugging
	//Images::showImage_inputUint8("distortionCorrectionIma", distortionCorrectionIma);

	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}