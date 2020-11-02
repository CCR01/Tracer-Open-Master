#include "testImageSimulation.h"
#include "..\..\Analyse\OpticalPathDifference.h"
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\..\LowLevelTracing\Surfaces\ParaxialLens_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DeflectedRayParaxialLens_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\FillAptertureStop\FillApertureStop.h"
#include "..\..\Analyse\Spot.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"

#include "..\..\FillAptertureStop\FillApertureStop.h"
#include"..\..\Image\Images.h"
#include "..\..\oftenUseNamespace\oftenUseNamespace.h"
#include "..\..\Inport_Export_Data\Inport_Export_Data.h"

TestImageSimulation::TestImageSimulation() {};
TestImageSimulation::~TestImageSimulation() {};

bool TestImageSimulation::testSuperFct()
{
	std::vector<bool> testSuperFct_vec;

	// test system 0
	bool checkSystem0 = test0();
	testSuperFct_vec.push_back(checkSystem0);

	// test system 1
	bool checkSystem1 = test1();
	testSuperFct_vec.push_back(checkSystem1);
	
	// test 2 
	bool checkTest2 = test2();
	testSuperFct_vec.push_back(checkTest2);


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
	float loadPSF0_00 = PSF0.at<float>(0, 0);
	float refPSF0_00 = 3.0166E-005;
	float loadPSF0_11 = PSF0.at<float>(1, 1);
	float refPSF0_11 = 1.8692E-006;
	bool checkPSF0_00 = Math::compareTwoNumbers_tolerance(loadPSF0_00, refPSF0_00, tolerancePSF);
	test_vec.push_back(checkPSF0_00);
	bool checkPSF0_11 = Math::compareTwoNumbers_tolerance(loadPSF0_11, refPSF0_11, tolerancePSF);
	test_vec.push_back(checkPSF0_11);
	inportExportData::exportCV_MatToExcel(PSF0, loaction, namePSF0);

	// check PSF 1
	float loadPSF1_56 = PSF1.at<float>(5, 6);
	float refPSF1_56 = 7.9780E-007;
	float loadPSF1_12 = PSF1.at<float>(1, 2);
	float refPSF1_12 = 1.7824E-006;
	bool checkPSF1_56 = Math::compareTwoNumbers_tolerance(loadPSF1_56, refPSF1_56, tolerancePSF);
	test_vec.push_back(checkPSF1_56);
	bool checkPSF1_12 = Math::compareTwoNumbers_tolerance(loadPSF1_12, refPSF1_12, tolerancePSF);
	test_vec.push_back(checkPSF1_12);
	inportExportData::exportCV_MatToExcel(PSF1, loaction, namePSF1);

	// check PSF 2
	float loadPSF2_02 = PSF2.at<float>(0, 2);
	float refPSF2_02 = 1.8302E-006;
	float loadPSF2_31 = PSF2.at<float>(3, 1);
	float refPSF2_31 = 2.5848E-006;
	bool checkPSF2_02 = Math::compareTwoNumbers_tolerance(loadPSF2_02, refPSF2_02, tolerancePSF);
	test_vec.push_back(checkPSF2_02);
	bool checkPSF2_31 = Math::compareTwoNumbers_tolerance(loadPSF2_31, refPSF2_31, tolerancePSF);
	test_vec.push_back(checkPSF2_31);
	inportExportData::exportCV_MatToExcel(PSF2, loaction, namePSF2);

	// check PSF 3
	float loadPSF3_13 = PSF3.at<float>(1, 3);
	float refPSF3_13 = 8.5358E-006;
	float loadPSF3_23 = PSF3.at<float>(2, 3);
	float refPSF3_23 = 2.8567E-006;
	bool checkPSF3_13 = Math::compareTwoNumbers_tolerance(loadPSF3_13, refPSF3_13, tolerancePSF);
	test_vec.push_back(checkPSF3_13);
	bool checkPSF3_23 = Math::compareTwoNumbers_tolerance(loadPSF3_23, refPSF3_23, tolerancePSF);
	test_vec.push_back(checkPSF3_23);
	inportExportData::exportCV_MatToExcel(PSF3, loaction, namePSF3);

	// check PSF 4
	float loadPSF4_30 = PSF4.at<float>(1, 3);
	float refPSF4_30 = 1.7494E-005;
	float loadPSF4_04 = PSF4.at<float>(2, 3);
	float refPSF4_04 = 2.8951E-007;
	bool checkPSF4_30 = Math::compareTwoNumbers_tolerance(loadPSF4_30, refPSF3_13, tolerancePSF);
	test_vec.push_back(checkPSF4_30);
	bool checkPSF4_04 = Math::compareTwoNumbers_tolerance(loadPSF4_04, refPSF3_23, tolerancePSF);
	test_vec.push_back(checkPSF4_04);
	inportExportData::exportCV_MatToExcel(PSF4, loaction, namePSF4);

	// check PSF 5
	float loadPSF5_41 = PSF5.at<float>(4, 1);
	float refPSF5_41 = 2.2275E-005;
	float loadPSF5_32 = PSF5.at<float>(3, 2);
	float refPSF5_32 = 2.0706E-005;
	bool checkPSF5_41 = Math::compareTwoNumbers_tolerance(loadPSF5_41, refPSF5_41, tolerancePSF);
	test_vec.push_back(checkPSF5_41);
	bool checkPSF5_32 = Math::compareTwoNumbers_tolerance(loadPSF5_32, refPSF5_32, tolerancePSF);
	test_vec.push_back(checkPSF5_32);
	inportExportData::exportCV_MatToExcel(PSF5, loaction, namePSF5);


	// check PSF 6
	float loadPSF6_33 = PSF6.at<float>(3, 3);
	float refPSF6_33 = 2.5545E-005;
	float loadPSF6_44 = PSF6.at<float>(4, 4);
	float refPSF6_44 = 4.5046E-005;
	bool checkPSF6_33 = Math::compareTwoNumbers_tolerance(loadPSF6_33, refPSF6_33, tolerancePSF);
	test_vec.push_back(checkPSF6_33);
	bool checkPSF6_44 = Math::compareTwoNumbers_tolerance(loadPSF6_44, refPSF6_44, tolerancePSF);
	test_vec.push_back(checkPSF6_44);
	inportExportData::exportCV_MatToExcel(PSF6, loaction, namePSF6);

	// check PSF 7
	float loadPSF7_12 = PSF7.at<float>(1, 2);
	float refPSF7_12 = 8.8751E-006;
	float loadPSF7_31 = PSF7.at<float>(3, 1);
	float refPSF7_31 = 3.9907E-006;
	bool checkPSF7_33 = Math::compareTwoNumbers_tolerance(loadPSF7_12, refPSF7_12, tolerancePSF);
	test_vec.push_back(checkPSF7_33);
	bool checkPSF7_44 = Math::compareTwoNumbers_tolerance(loadPSF7_31, refPSF7_31, tolerancePSF);
	test_vec.push_back(checkPSF7_44);
	inportExportData::exportCV_MatToExcel(PSF7, loaction, namePSF7);

	// check PSF 8
	float loadPSF8_56 = PSF8.at<float>(5, 6);
	float refPSF8_56 = 1.1101E-005;
	float loadPSF8_78 = PSF8.at<float>(7, 8);
	float refPSF8_78 = 7.9185E-006;
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

	imaSim.setPixBiggerForConvolution_Row(10);
	imaSim.setPixBiggerForConvolution_Col(10);

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
	float loadPSF0_00 = PSF0.at<float>(0, 0);
	float refPSF0_00 = 2.0366E-005;
	bool checkPSF0_00 = Math::compareTwoNumbers_tolerance(loadPSF0_00, refPSF0_00, tolerancePSF);
	test_vec.push_back(checkPSF0_00);

	// check PSF 1
	float loadPSF1_56 = PSF1.at<float>(5, 6);
	float refPSF1_56 = 8.1727E-006;
	bool checkPSF1_56 = Math::compareTwoNumbers_tolerance(loadPSF1_56, refPSF1_56, tolerancePSF);
	test_vec.push_back(checkPSF1_56);

	// check PSF 2
	float loadPSF2_02 = PSF2.at<float>(0, 2);
	float refPSF2_02 = 1.8021E-005;
	bool checkPSF2_02 = Math::compareTwoNumbers_tolerance(loadPSF2_02, refPSF2_02, tolerancePSF);
	test_vec.push_back(checkPSF2_02);

	// check PSF 3
	float loadPSF3_13 = PSF3.at<float>(1, 3);
	float refPSF3_13 = 2.0976E-005;
	bool checkPSF3_13 = Math::compareTwoNumbers_tolerance(loadPSF3_13, refPSF3_13, tolerancePSF);
	test_vec.push_back(checkPSF3_13);

	// check PSF 4
	float loadPSF4_30 = PSF4.at<float>(1, 3);
	float refPSF4_30 = 2.7048E-005;
	bool checkPSF4_30 = Math::compareTwoNumbers_tolerance(loadPSF4_30, refPSF3_13, tolerancePSF);
	test_vec.push_back(checkPSF4_30);

	// check PSF 5
	float loadPSF5_41 = PSF5.at<float>(4, 1);
	float refPSF5_41 = 2.7836E-006;
	bool checkPSF5_41 = Math::compareTwoNumbers_tolerance(loadPSF5_41, refPSF5_41, tolerancePSF);
	test_vec.push_back(checkPSF5_41);

	// check PSF 6
	float loadPSF6_33 = PSF6.at<float>(3, 3);
	float refPSF6_33 = 1.4392E-005;
	bool checkPSF6_33 = Math::compareTwoNumbers_tolerance(loadPSF6_33, refPSF6_33, tolerancePSF);
	test_vec.push_back(checkPSF6_33);

	// check PSF 7
	float loadPSF7_12 = PSF7.at<float>(1, 2);
	float refPSF7_12 = 8.8570E-006;
	bool checkPSF7_33 = Math::compareTwoNumbers_tolerance(loadPSF7_12, refPSF7_12, tolerancePSF);
	test_vec.push_back(checkPSF7_33);

	// check PSF 8
	float loadPSF8_56 = PSF8.at<float>(5, 6);
	float refPSF8_56 = 3.0011E-007;
	bool checkPSF8_56 = Math::compareTwoNumbers_tolerance(loadPSF8_56, refPSF8_56, tolerancePSF);
	test_vec.push_back(checkPSF8_56);
			
	// load an image 
	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_sharp_squared_840x840.png", CV_LOAD_IMAGE_COLOR);
	// just for debugging
	// cv::imshow("elefant", elefantObj);

	ImageSimulationFunctions imaSim;
	//std::vector<cv::Mat> PSF_vec = {PSF0,PSF0,PSF0,PSF0};
	//std::vector<cv::Mat> PSF_vec = { PSF7,PSF1,PSF5,PSF4,PSF0,PSF3,PSF8,PSF2,PSF6 };
	//
	std::vector<cv::Mat> PSF_vec;
	unsigned sizePSF = 12 * 12;
	PSF_vec.resize(sizePSF);
	for (unsigned int i = 0; i < sizePSF; ++i)
	{
		PSF_vec[i] = PSF0;
	}
	//std::vector<cv::Mat> PSF_vec = { PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0,PSF0 };
	imaSim.loadPSFs_blue(PSF_vec);
	imaSim.loadPSFs_green(PSF_vec);
	imaSim.loadPSFs_red(PSF_vec);

	imaSim.setGridFactor(12);
	imaSim.setPixBiggerForConvolution_Row(10);
	imaSim.setPixBiggerForConvolution_Col(10);
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

	Images::showImage("final ima", finalImage);
	Images::saveImage("..", "finalImag", "png", finalImage);

	return true;
}