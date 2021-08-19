#include "tWienerDeconvolution.h"

// wiener deconvolution
#include "..\..\..\ImageProcessing\WienerDeconvolution.h"

// important structs
#include "..\..\..\LowLevelTracing\ImportantStructures.h"

// images
#include "..\..\..\Image\Images.h"

// Math
#include "..\..\..\LowLevelTracing\Math_LLT.h"

#include <iostream>

// open cv
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/calib3d/calib3d.hpp>
//#include <opencv2/imgcodecs.hpp>
#include <opencv2/photo.hpp>


// inport export date
#include "..\..\..\Inport_Export_Data\Inport_Export_Data.h"

// Surface elements
#include "..\..\..\SurfaceElements\ApertureStopElement.h"
#include "..\..\..\SurfaceElements\PlanElement.h"
#include "..\..\..\SurfaceElements\SphericalElement.h"

// often use
#include "..\..\..\oftenUseNamespace\oftenUseNamespace.h"


// typedef
typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

testWienerDeconvolution::testWienerDeconvolution() { loadImportantStuff(); }

testWienerDeconvolution::~testWienerDeconvolution(){}

// load important things
void testWienerDeconvolution::loadImportantStuff()
{
	mGlasses.loadGlassCatalog_Schott();

	mWavelenght_vec_dFC.resize(3);
	mWavelenght_vec_dFC[0] = 587.5618;
	mWavelenght_vec_dFC[1] = 486.1327;
	mWavelenght_vec_dFC[2] = 656.2725;

	mObject_vec_012.resize(3);
	mObject_vec_012[0] = { 0.0,0.0,0.0 };
	mObject_vec_012[1] = { 0.0,1.0,0.0 };
	mObject_vec_012[2] = { 0.0,2.0,0.0 };
}

bool testWienerDeconvolution::checkImproveImageQuality_WienerDeconvolution_superFct()
{
	std::vector<bool> testSuperFct_vec;

	// test 0 WD Andrey Smorodov gray
	bool check0 = test0_WD_Andrey_Smorodov_Gray();
	testSuperFct_vec.push_back(check0);
	// test 1 WD Open CV
	bool check1 = test1_WD_OpenCV();
	testSuperFct_vec.push_back(check1);
	// test 2 WD CR
	bool check2 = test2_WD_CR();
	testSuperFct_vec.push_back(check2);
	// test 3 WD Andrey Smorodov color
	bool check3 = test3_WD_Andrey_Smorodov_BGR_Ima();
	testSuperFct_vec.push_back(check3);
	// test 4
	bool check4 = test4_WD_Andrey_Smorodov_BGR_Ima();
	testSuperFct_vec.push_back(check4);
	// test5
	bool check5 = test5_WS_OpenCV_BGR();
	testSuperFct_vec.push_back(check5);
	// test6
	bool check6 = test6_WD_CR();
	testSuperFct_vec.push_back(check6);
	// test7
	bool check7 = test7_WD();
	testSuperFct_vec.push_back(check7);
	// E0
	bool chE0 = checkFuncE0();


	bool returnChecker = Math::checkTrueOfVectorElements(testSuperFct_vec);
	return returnChecker;
}


bool testWienerDeconvolution::test0_WD_Andrey_Smorodov_Gray()
{
	std::vector<bool> test_vec;
	std::string locationTest0 = "../tests/testImproveImageQuality/WienerDeconvolution/s0";
	std::string locationImagesGray = "../images/gray/elefant_900x900_gray.png";
	cv::Mat greyMat = cv::imread(locationImagesGray, cv::IMREAD_GRAYSCALE); // Source image


	//cv::Mat greyMat;
	//cv::cvtColor(Img, greyMat, CV_BGR2GRAY);
	greyMat.convertTo(greyMat, CV_32FC1, 1.0 / 255.0);

	cv::Mat psf = inportExportData::importTXTtoCVmat(locationTest0, "psf00_128", 128, 128);

	// debug
	//Images::showImage_inputUint8("initial psf", psf);

	psf.convertTo(psf, CV_32FC1, 1.0 / 255.0);
	float kernel_sum = cv::sum(psf)[0];
	psf /= kernel_sum;
	//Images::showImage_inputReal_normTheImage("initial psf + 1", psf);

	int width = greyMat.cols;
	int height = greyMat.rows;
	cv::Mat resim;

	WienerDeconvolution WienderDecon;

	WienderDecon.convolveDFT_AS(greyMat, psf, resim);

	// debug
	//Images::showImage_inputReal_normTheImage("initial psf + 2", psf);

	cv::Mat resim2;
	psf.convertTo(psf, CV_64FC1);
	// Apply filter
	WienderDecon.wienerFilter_AndreySmorodov_GrayImage(resim, resim2, psf, 0.01);

	//// debug
	//cv::imshow("Filterergebnis", resim2);
	//Images::showImage_inputReal_normTheImage("initial psf + 3", psf);
	//cv::imshow("Image", greyMat);
	//cv::imshow("bluered image", resim);
	//cvWaitKey(0);




	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

// test 1
bool testWienerDeconvolution::test1_WD_OpenCV()
{
	std::vector<bool> test_vec;

	std::string locationImages = "../images/gray/elefantSimulated_S3_640x480_gray.png";
	std::string locationTest0 = "../tests/testImproveImageQuality/WienerDeconvolution/s1";
	WienerDeconvolution WienderDecon;

	int R = 2;
	int snr = 10.0;

	cv::Mat imgIn;
	imgIn = cv::imread(locationImages, cv::IMREAD_GRAYSCALE);
	if (imgIn.empty()) //check whether the image is loaded or not
	{
		std::cout << "ERROR : Image cannot be loaded..!!" << endl;
		return -1;
	}
	cv::Mat imgOut;
	// it needs to process even image only
	cv::Rect roi = cv::Rect(0, 0, imgIn.cols & -2, imgIn.rows & -2);
	//Hw calculation (start)
	cv::Mat Hw, h;
	WienderDecon.calcPSF_CV_32(h, roi.size(), R);
	// debug
	//Images::showImage_inputReal_normTheImage("h", h);

	WienderDecon.calcWnrFilter_CV(h, Hw, 1.0 / double(snr));
	//just for debugging
	// Images::showImage_inputReal("Hw", Hw);

	//Hw calculation (stop)
	// filtering (start)
	WienderDecon.filter2DFreq_CV(imgIn(roi), imgOut, Hw);
	// filtering (stop)
	imgOut.convertTo(imgOut, CV_8U);
	normalize(imgOut, imgOut, 0, 255, cv::NORM_MINMAX);
	std::string saveIma = "../tests/testImproveImageQuality/WienerDeconvolution/s1/improvedIma.png";
	cv::imwrite(saveIma, imgOut);

	////debug
	//Images::showImage_inputUint8("blueredIma", imgIn);
	//Images::showImage_inputUint8("improvedIma", imgOut);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

// tesr 2 WD CR
bool testWienerDeconvolution::test2_WD_CR()
{
	std::vector<bool> test_vec;
	std::string locationTest2 = "../tests/testImproveImageQuality/WienerDeconvolution/s2";
	std::string locationImages = "../images/gray/elefant_900x900_gray.png";
	cv::Mat grayIma = cv::imread(locationImages, cv::IMREAD_GRAYSCALE); // Source image
	cv::Mat psf = inportExportData::importTXTtoCVmat(locationTest2, "psf00_128", 128, 128);

	//psf.convertTo(psf, CV_64FC1, 1.0 / 255.0);


	// debug 
	// Images::showImage_inputReal_normTheImage("psf", psf);

	// make blured image
	ImageSimulationFunctions imaSim;
	cv::Mat blueredIma = imaSim.convolution_Gray_unit8(grayIma, psf);
	cv::normalize(blueredIma, blueredIma, 0, 255, cv::NORM_MINMAX);
	blueredIma.convertTo(blueredIma, CV_8U);
	//normalize(blueredIma, blueredIma, 0, 255, cv::NORM_MINMAX);


	// just for debugging
	//Images::showImage_inputUint8("bluered image", blueredIma);
	Images::saveImage_normalized(locationTest2, "blured image", "png", blueredIma);

	float kernel_sum = cv::sum(psf)[0];
	psf /= kernel_sum;

	WienerDeconvolution WienderDecon;
	cv::Mat sharpIma;
	WienderDecon.calcWienerFilter_CR_Gray(blueredIma, sharpIma, psf, 10.0);

	// debug
	//Images::showImage_inputUint8("sharp image", sharpIma);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;


}

// test 3
bool testWienerDeconvolution::test3_WD_Andrey_Smorodov_BGR_Ima()
{
	std::vector<bool> test_vec;
	std::string locationTest3 = "../tests/testImproveImageQuality/WienerDeconvolution/s3";
	std::string locationImages = "../images/color/useThatImages/useThat/elefant_900x900.png";
	cv::Mat colorIma = cv::imread(locationImages, CV_LOAD_IMAGE_COLOR); // Source image


	cv::Mat psf = inportExportData::importTXTtoCVmat(locationTest3, "psf00_128", 128, 128);
	psf.convertTo(psf, CV_64FC1, 1.0 / 255.0);
	float kernel_sum = cv::sum(psf)[0];
	psf /= kernel_sum;
	//Images::showImage_inputReal_normTheImage("PSF", psf);

	ImageSimulationFunctions ImaSim;
	cv::Mat bluredIma = ImaSim.convolution_BGR_uint8(colorIma, psf);

	// debug show
	//Images::showImage_inputReal_normTheImage("blured ima", bluredIma);

	// save blured ima
	Images::saveImage_normalized(locationTest3, "bluredImage_test3", "png", bluredIma);

	WienerDeconvolution WienderDecon;

	// Apply filter
	WienderDecon.wienerFilter_AndreySmorodov_BGR_Image(bluredIma, psf, psf, psf, 0.01, bluredIma.size());


	cv::Mat sharpIma = WienderDecon.getFinalSharpImage_initialSize();

	//// debug show
	//Images::showImage_inputReal_normImaByROI_inPercent("sharp ima", sharpIma, 5.0);
	//Images::showImage_inputReal_normTheImage("Kernel", psf);

	// save sharp ima
	Images::saveImage_normalized(locationTest3, "sharpIma_test3", "png", sharpIma);
	Images::saveImage_inputReal_normByROI_percent(locationTest3, "sharpIma_test3_normByROI", "png", sharpIma, 5.0);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

bool testWienerDeconvolution::test4_WD_Andrey_Smorodov_BGR_Ima()
{
	std::vector<bool> test_vec;
	std::string locationTest4 = "../tests/testImproveImageQuality/WienerDeconvolution/s4";
	std::string locationImages = "../tests/testImproveImageQuality/WienerDeconvolution/s4/simIma.png";
	cv::Mat colorIma = cv::imread(locationImages, CV_LOAD_IMAGE_COLOR); // Source image


	cv::Mat psf = inportExportData::importCSVtoCVmat(locationTest4, "psf");
	psf.convertTo(psf, CV_64FC1, 1.0 / 255.0);
	float kernel_sum = cv::sum(psf)[0];
	psf /= kernel_sum;

	// debug show
	//Images::showImage_inputReal_normTheImage("blured ima", colorIma);

	WienerDeconvolution WienderDecon;

	// Apply filter
	WienderDecon.wienerFilter_AndreySmorodov_BGR_Image(colorIma, psf, psf, psf, 0.1, cv::Size(900, 900));


	cv::Mat sharpIma = WienderDecon.getFinalSharpImage_initialSize();

	//// debug show
	//Images::showImage_inputReal_normImaByROI_inPercent("sharp ima 1", sharpIma, 10.0);
	//Images::showImage_inputReal_normTheImage("sharp ima 2", sharpIma);

	// save sharp ima
	Images::saveImage_inputReal_normByROI_percent(locationTest4, "sharpIma_test3", "png", sharpIma,10);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;


}


// test5
bool testWienerDeconvolution::test5_WS_OpenCV_BGR()
{
	std::vector<bool> test_vec;
	std::string locationTest5 = "../tests/testImproveImageQuality/WienerDeconvolution/s5";
	std::string locationImages = "../tests/testImproveImageQuality/WienerDeconvolution/s5/simImaE0_initialSize.png";
	cv::Mat colorIma = cv::imread(locationImages, CV_LOAD_IMAGE_COLOR); // Source image


	//WienerDeconvolution wienderDecon;
	//cv::Mat psf_blue;
	//real tempRadius = 4;
	//wienderDecon.calcPSF_CV_64(psf_blue, cv::Size(128,128), tempRadius);
	//cv::Mat psf_green;
	//wienderDecon.calcPSF_CV_64(psf_green, cv::Size(128, 128), tempRadius);
	//cv::Mat psf_red;
	//wienderDecon.calcPSF_CV_64(psf_red, cv::Size(128, 128), tempRadius);
	////psf.convertTo(psf, CV_64FC3, 1.0 / 255.0);
	////float kernel_sum = cv::sum(psf)[0];
	////psf /= kernel_sum;

	cv::Mat psf_blue = inportExportData::importCSVtoCVmat(locationTest5, "psf_edge_blue");
	psf_blue.convertTo(psf_blue, CV_64FC1, 1.0 / 255.0);
	float kernel_sum_blue = cv::sum(psf_blue)[0];
	psf_blue /= kernel_sum_blue;

	//Images::showImage_inputReal_normTheImage("psf_blue", psf_blue);

	cv::Mat psf_green = inportExportData::importCSVtoCVmat(locationTest5, "psf_edge_green");
	psf_green.convertTo(psf_green, CV_64FC1, 1.0 / 255.0);
	float kernel_sum_green = cv::sum(psf_green)[0];
	psf_green /= kernel_sum_green;

	cv::Mat psf_red = inportExportData::importCSVtoCVmat(locationTest5, "psf_edge_red");
	psf_red.convertTo(psf_red, CV_64FC1, 1.0 / 255.0);
	float kernel_sum_red = cv::sum(psf_red)[0];
	psf_red /= kernel_sum_red;


	

	WienerDeconvolution wienerDevon;

	// Apply filter
	wienerDevon.calcWienerFilter_CR_BGR(colorIma, psf_blue, psf_green, psf_red, 10.0, cv::Size(900, 900));


	cv::Mat sharpIma = wienerDevon.getFinalSharpImage_initialSize();

	//// debug show
	//Images::showImage_inputReal_normTheImage("blured ima", colorIma);
	//Images::showImage_inputReal_normImaByROI_inPercent("sharp ima 1", sharpIma, 10.0);
	//Images::showImage_inputReal_normTheImage("sharp ima 2", sharpIma);

	// save sharp ima
	Images::saveImage_normalized(locationTest5, "sharpIma_test3 edge", "png", sharpIma);
	Images::saveImage_inputReal_normByROI_percent(locationTest5, "sharpIma_test3_roi egde", "png", sharpIma, 20.0);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;



}


// test6
bool testWienerDeconvolution::test6_WD_CR()
{
	std::vector<bool> test_vec;
	std::string locationTest6 = "../tests/testImproveImageQuality/WienerDeconvolution/s6";
	std::string imaPartCenterBlue = "../tests/testImproveImageQuality/WienerDeconvolution/s6/imagePart_blue_center.png";
	std::string psfPartCenterBlue = "../tests/testImproveImageQuality/WienerDeconvolution/s6/PSF_blue_center.png";
	cv::Mat grayImaPartCenterBlue = cv::imread(imaPartCenterBlue, cv::IMREAD_GRAYSCALE); // Source image
	cv::Mat psfCenterBlue = cv::imread(psfPartCenterBlue, cv::IMREAD_GRAYSCALE); // Source image

	psfCenterBlue.convertTo(psfCenterBlue, CV_64FC1, 1.0 / 255.0);
	real kernel_sum = cv::sum(psfCenterBlue)[0];
	psfCenterBlue /= kernel_sum;

	WienerDeconvolution WienderDecon;
	cv::Mat sharpIma;
	WienderDecon.calcWienerFilter_CR_Gray_outputNotNormed(grayImaPartCenterBlue, sharpIma, psfCenterBlue, 50.0);

	//// debug
	//Images::showImage_inputUint8("blured image", grayImaPartCenterBlue);
	//Images::showImage_inputReal_normTheImage("sharp image", sharpIma);
	//Images::showImage_inputReal_normImaByROI_inPercent("sharp image norm by roi", sharpIma,10.0);

	// save
	Images::saveImage_normalized(locationTest6, "sharpIma", "png", sharpIma);
	cv::Mat sharpImaReal;
	sharpIma.convertTo(sharpImaReal, CV_64F);
	Images::saveImage_inputReal_normByROI_percent(locationTest6, "sharpImaNormByROI", "png", sharpImaReal, 10.0);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

// test 7
bool testWienerDeconvolution::test7_WD()
{
	std::vector<bool> test_vec;
	std::string locSharpIma = "../tests/testImproveImageQuality/WienerDeconvolution/S7/sharp_blue.png";
	cv::Mat sharpImaLoaded = cv::imread(locSharpIma, cv::IMREAD_GRAYSCALE);
	std::string locBluredIma = "../tests/testImproveImageQuality/WienerDeconvolution/S7/bluered_blue.png";
	cv::Mat bluredIma = cv::imread(locBluredIma, cv::IMREAD_GRAYSCALE);
	std::string locPSFBluecenter = "../tests/testImproveImageQuality/WienerDeconvolution/S7/PSF_blue_center.png";
	cv::Mat psfBlueCenter = cv::imread(locPSFBluecenter, cv::IMREAD_GRAYSCALE);
	std::string locationTest8 = "../tests/testImproveImageQuality/WienerDeconvolution/s8";

	//psfBlueCenter.convertTo(psfBlueCenter, CV_64FC1, 1.0 / 255.0);
	//real kernel_sum = cv::sum(psfBlueCenter)[0];
	//psfBlueCenter /= kernel_sum;



	WienerDeconvolution WienderDecon;
	WienderDecon.calcPSF_CV_32(psfBlueCenter, cv::Size(900, 900), 5);
	cv::Mat FilteredIma;
	WienderDecon.calcWienerFilter_CR_Gray_outputNotNormed(bluredIma, FilteredIma, psfBlueCenter, 5000.0);

	///// debug
	//Images::showImage_inputUint8("blured image", bluredIma);
	//Images::showImage_inputUint8("sharp image", sharpImaLoaded);
	//Images::showImage_inputReal_normTheImage("filtered image", FilteredIma);
	//Images::showImage_inputUint8_normImaByROI_inPercent("filtered image norm by roi", FilteredIma, 5.0);

	// save
	Images::saveImage_normalized(locationTest8, "sharpIma", "png", FilteredIma);
	cv::Mat sharpImaReal;
	FilteredIma.convertTo(sharpImaReal, CV_64F);
	Images::saveImage_inputReal_normByROI_percent(locationTest8, "sharpImaNormByROI", "png", sharpImaReal, 5.0);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}



// E0
bool testWienerDeconvolution::checkFuncE0()
{
	std::vector<bool> workTheSystem{};
	std::string location = "../tests/testImproveImageQuality/WienerDeconvolution/E0";

	// test system
	// build the optical system
	ApertureStopElement AperStop0(/* semi height*/0.5, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
	SphericalElement Sphere1(/*radius*/ 87.016, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement Sphere2(/*radius*/ 16.059, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement Sphere3(/*radius*/ 365.1, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK4_S1());
	SphericalElement Sphere4(/*radius*/ 127.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK4_S1());
	SphericalElement Sphere5(/*radius*/ 51.4, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement Sphere6(/*radius*/ 113.9, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement Sphere7(/*radius*/ 16.724, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK4_S1());
	SphericalElement Sphere8(/*radius*/ 348.824, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK4_S1());
	PlanElement Plan9(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,100.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	surfacePtr AperStop_ptr = AperStop0.clone();
	surfacePtr Sphere1_ptr = Sphere1.clone();
	surfacePtr Sphere2_ptr = Sphere2.clone();
	surfacePtr Sphere3_ptr = Sphere3.clone();
	surfacePtr Sphere4_ptr = Sphere4.clone();
	surfacePtr Sphere5_ptr = Sphere5.clone();
	surfacePtr Sphere6_ptr = Sphere6.clone();
	surfacePtr Sphere7_ptr = Sphere7.clone();
	surfacePtr Sphere8_ptr = Sphere8.clone();
	surfacePtr Plan9_ptr = Plan9.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ AperStop_ptr, Sphere1_ptr, Sphere2_ptr, Sphere3_ptr, Sphere4_ptr,  Sphere5_ptr, Sphere6_ptr, Sphere7_ptr, Sphere8_ptr, Plan9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSysEle(opticalSystem_ptr, interactions_ptr);

	// test the system
	std::vector<real> rms_Zemax{ 11.199,29.858,67.422 };
	bool testStart = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle, mObject_vec_012, mWavelenght_vec_dFC, rms_Zemax, 0.01, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testStart);

	// load object
	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_900x900.png", CV_LOAD_IMAGE_COLOR);


	ImageSimulationFunctions imaSim;

	loadParaImaSim parameterTest10;
	parameterTest10.loadImportandStuff();
	parameterTest10.setSampling_x(5);
	parameterTest10.setUpSamplePSF(true);
	parameterTest10.setRowBiggerForConV(9999.0);
	parameterTest10.setColBiggerForConv(9999.0);
	parameterTest10.setSizeMatrixToSaveOPD(64);
	parameterTest10.setRowColResizeOPD(128);
	parameterTest10.setSemiHeightObj(1.0);
	parameterTest10.setSemiWeidthObj(1.0);
	parameterTest10.setCalcDistortion(false);
	parameterTest10.setSamplingDistortionHeight(450);
	parameterTest10.setSamplingDistortionWidth(450);
	parameterTest10.setPaddingFactorPSF(1);
	imaSim.imageSimulationSuperFct(/*optical System Element*/ optSysEle, /*object*/ elefantObj, /*parameter*/ parameterTest10);

	cv::Mat simulatedIma_initialSize = imaSim.getSimulatedImage_initialSize();
	cv::Mat simulatedIma_sizeForConv = imaSim.getSimulatedImage_sizeForConvolution();
	// just for debugging
	//Images::showImage_inputReal("simulated ima test 10", simulatedIma);
	// save the simulate images
	Images::saveImage_normalized(location, "simImaE0_initialSize", "png", simulatedIma_initialSize);
	Images::saveImage_normalized(location, "simImaE0_sizeForConv", "png", simulatedIma_sizeForConv);

	// get all PSFs
	std::vector<cv::Mat> PSF_vec_blue = imaSim.getAllPSFsForConvolution_blue();
	std::vector<cv::Mat> PSF_vec_green = imaSim.getAllPSFsForConvolution_green();
	std::vector<cv::Mat> PSF_vec_red = imaSim.getAllPSFsForConvolution_red();

	std::vector<cv::Mat> simImageParts_blue = imaSim.getSimulatedImaGrid_blue();
	std::vector<cv::Mat> simImageParts_green = imaSim.getSimulatedImaGrid_green();
	std::vector<cv::Mat> simImageParts_red = imaSim.getSimulatedImaGrid_red();

	// save PSfs in center
	Images::saveImage_normalized(location, "PSF_blue_center", "png", PSF_vec_blue[40]);
	Images::saveImage_normalized(location, "PSF_green_center", "png", PSF_vec_green[40]);
	Images::saveImage_normalized(location, "PSF_red_center", "png", PSF_vec_red[40]);

	// save PSFs edge
	Images::saveImage_normalized(location, "PSF_blue_edge", "png", PSF_vec_blue[0]);
	Images::saveImage_normalized(location, "PSF_green_edge", "png", PSF_vec_green[0]);
	Images::saveImage_normalized(location, "PSF_red_edge", "png", PSF_vec_red[0]);

	// save image part center
	Images::saveImage_normalized(location, "imagePart_blue_center", "png", simImageParts_blue[40]);
	Images::saveImage_normalized(location, "imagePart_green_center", "png", simImageParts_green[40]);
	Images::saveImage_normalized(location, "imagePart_red_center", "png", simImageParts_red[40]);

	// save image part edge
	Images::saveImage_normalized(location, "imagePart_blue_edge", "png", simImageParts_blue[0]);
	Images::saveImage_normalized(location, "imagePart_green_edge", "png", simImageParts_green[0]);
	Images::saveImage_normalized(location, "imagePart_red_edge", "png", simImageParts_red[0]);

	// *** export All PSFs
	// std::string locationExportPSF = "../tests/testImproveImageQuality/E0/PSFs";
	// exportAllPSFsToCSV(PSF_vec_blue, PSF_vec_green, PSF_vec_red, locationExportPSF);
	//// inport all PSFs
	//std::vector<cv::Mat> PSF_vec_blue_inport = inportManyPSFsToMat("blue_", locationExportPSF, 81);
	//std::vector<cv::Mat> PSF_vec_green_inport = inportManyPSFsToMat("green_", locationExportPSF, 81);
	//std::vector<cv::Mat> PSF_vec_red_inport = inportManyPSFsToMat("red_", locationExportPSF, 81);
	//// test
	//real refBlue = PSF_vec_blue[5].at<real>(25, 36);
	//real loadBlue = PSF_vec_blue_inport[5].at<real>(25, 36);
	//bool checkLoadBlue = Math::compareTwoNumbers_tolerance(refBlue, loadBlue, 0.001);
	//workTheSystem.push_back(checkLoadBlue);
	//real refGreen = PSF_vec_green[6].at<real>(17, 18);
	//real loadGreen = PSF_vec_green_inport[6].at<real>(17, 18);
	//bool checkLoadGreen = Math::compareTwoNumbers_tolerance(refGreen, loadGreen, 0.001);
	//workTheSystem.push_back(checkLoadGreen);
	//real refRed = PSF_vec_red[6].at<real>(14, 15);
	//real loadRed = PSF_vec_red_inport[6].at<real>(14, 15);
	//bool checkLoadRed = Math::compareTwoNumbers_tolerance(refRed, loadRed, 0.001);
	//workTheSystem.push_back(checkLoadRed);
	// *** 

	cv::Mat channelSimIma[3];
	cv::Mat simIma = imaSim.getSimulatedImage_sizeForConvolution();
	cv::split(simIma, channelSimIma);
	cv::Mat simImaBlue = channelSimIma[0];

	cv::Mat sharpImaBlue = imaSim.getAdaptedObj_blue();

	// find best SNR
	real startSNR = 0.001;
	real endSNR = 10.0;
	real deltaSNR = 0.1;
	real tempSNR = startSNR;
	bool checker = true;
	real difference;
	WienerDeconvolution wienderDecon_gray;
	cv::Mat grayIma;
	real percent = 10.0;
	cv::Mat grayIma_8U;


	cv::normalize(sharpImaBlue, sharpImaBlue, 0, 255, cv::NORM_MINMAX);
	real tempDif;
	cv::Mat tempDifMat;
	real bestDif = oftenUse::getInfReal();
	real bestSNR;
	while (checker)
	{
		wienderDecon_gray.wienderDeconv_superFkt_grayIma(PSF_vec_blue, simImageParts_blue, imaSim.getLoadParameterImaSim(), tempSNR, imaSim.getSizeResizedObjForConv());
		grayIma = wienderDecon_gray.getGrayImage();

		unsigned int height = grayIma.size().height;
		unsigned int width = grayIma.size().width;

		unsigned int startX = percent * width / 100.0;
		unsigned int startY = percent * height / 100.0;
		unsigned int heighttROI = height - 2 * startY;
		unsigned int widthROI = width - 2 * startX;


		cv::Rect roi;
		roi.x = startX;
		roi.y = startY;
		roi.width = widthROI;
		roi.height = heighttROI;

		real min{};
		real max{};
		cv::minMaxLoc(grayIma(roi), &min, &max);

		grayIma = grayIma * 1.0 / max;

		cv::normalize(grayIma, grayIma, 0, 255, cv::NORM_MINMAX);
		grayIma.convertTo(grayIma_8U, CV_8U);

		cv::absdiff(grayIma_8U, sharpImaBlue, tempDifMat);
		tempDif = cv::sum(tempDifMat)[0];

		if (tempDif < bestDif)
		{
			bestSNR = tempSNR;
			bestDif = tempDif;
			std::cout << "best SNR: " << bestSNR << std::endl;
			std::cout << "tempDif: " << tempDif << std::endl;
		}

		tempSNR = deltaSNR + tempSNR;

		if (tempSNR > endSNR)
		{
			checker = false;
		}

	}

	std::cout << "best SNR: " << bestSNR << std::endl;
	wienderDecon_gray.wienderDeconv_superFkt_grayIma(PSF_vec_blue, simImageParts_blue, imaSim.getLoadParameterImaSim(), bestSNR, imaSim.getSizeResizedObjForConv());
	grayIma = wienderDecon_gray.getGrayImage();
	

	//// debug 
	//Images::showImage_inputUint8("sim ima blue", simImaBlue);
	//Images::showImage_inputUint8("sharp ima blue", sharpImaBlue);
	//Images::showImage_inputReal_normImaByROI_inPercent("gray ima", grayIma, percent);

	// save
	Images::saveImage_normalized(location, "SimImaBlue", "png", simImaBlue);
	Images::saveImage_normalized(location, "sharpImaBlue", "png", sharpImaBlue);
	Images::saveImage_inputReal_normByROI_percent(location, "bestImprovemtImagBlue", "png", grayIma, percent);
	
	bool workReturn = Math::checkTrueOfVectorElements(workTheSystem);
	return workReturn;

}

