#include "tWienerDeconvolutionSuperFunctionParallel.h"

// important structs
#include "..\..\..\LowLevelTracing\ImportantStructures.h"

// images
#include "..\..\..\Image\Images.h"

// Math
#include "..\..\..\LowLevelTracing\Math_LLT.h"

// wiener functuion parallel
#include "..\..\..\ImageProcessing\WienerDeconvolutionSuperFunctionParallel.h"

// inport export date
#include "..\..\..\Inport_Export_Data\Inport_Export_Data.h"

// wiener deconvolution super function
#include "..\..\..\ImageProcessing\WienerDeconvolutioinSuperFuction.h"


tWienerDeconSuperFctParallel::tWienerDeconSuperFctParallel() {}
tWienerDeconSuperFctParallel::~tWienerDeconSuperFctParallel() {}


// test super function
bool tWienerDeconSuperFctParallel::testWD_SuprFct_Parallel()
{
	std::vector<bool> test_vec;

	// E0
	bool checkE0 = testE0();
	test_vec.push_back(checkE0);
	
	// E1
	bool checkE1 = testE1();
	test_vec.push_back(checkE1);
	
	// E2
	bool checkE2 = testE2();
	test_vec.push_back(checkE2);
	
	// E3
	bool checkE3 = testE3();
	test_vec.push_back(checkE3);
	
	// E4
	bool checkE4 = testE4();
	test_vec.push_back(checkE4);

	// E5
	bool checkE5 = testE5();
	test_vec.push_back(checkE5);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

// test E0
bool tWienerDeconSuperFctParallel::testE0()
{
	std::vector<bool> test_vec;
	// location
	std::string locationTestE0 = "../tests/testImproveImageQuality/WienerDeconvolutionSuperFunctionParallel/E0";
	// load gray image
	std::string locationSharpGray = "../images/gray/elefant_900x900_gray.png";
	cv::Mat sharpIma_gray = cv::imread(locationSharpGray, cv::IMREAD_GRAYSCALE);
	// load simulated image
	std::string locationSimulatedImage = "../images/gray/simIma_900x900_gray.png";
	cv::Mat simIma_gray = cv::imread(locationSimulatedImage, cv::IMREAD_GRAYSCALE);

	parameterImaImprove_WD paraImaImproveWD_gray{};
	paraImaImproveWD_gray.setMinSNR(3.0);
	paraImaImproveWD_gray.setMaxSNR(5.0);
	paraImaImproveWD_gray.setStepsSNR(30);
	paraImaImproveWD_gray.setMinSigmaXY(0.1);
	paraImaImproveWD_gray.setMaxSigmaXY(2.0);
	paraImaImproveWD_gray.setStepsSigmaXY(20);
	paraImaImproveWD_gray.setKernelSizeHeightAndWidth(30);
	paraImaImproveWD_gray.setCompareInPercent(7.0);

	WienerDeconvolutionSF_Gray wienerDeconSF_gray;
	wienerDeconSF_gray.setBasicParameter(paraImaImproveWD_gray);
	wienerDeconSF_gray.improveImaQual_WD_superFct_gray(sharpIma_gray, simIma_gray);

	// ***
	saveBestParameterWD bestParameter_blue = wienerDeconSF_gray.getBestParameter();
	cv::Mat bestFilteredImage = bestParameter_blue.getBestReconstruction();
	real bestSNR = bestParameter_blue.getBestSNR();
	real bestSigma = bestParameter_blue.getBestSigma();
	real improvement = bestParameter_blue.getImprovement();

	Images::saveImageGray_UN8_normByROI_percent(locationTestE0, "bestFilteredImage", "png", bestFilteredImage, wienerDeconSF_gray.getParameter().getCompareInPercent());

	//// debug
	//std::cout << "best SNR: " << bestSNR << std::endl;
	//std::cout << "best sigma: " << bestSigma << std::endl;
	//std::cout << "improvement: " << improvement << std::endl;
	//// ***

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

// test E1
bool tWienerDeconSuperFctParallel::testE1()
{
	std::vector<bool> test_vec;
	// location
	std::string locationTestE1 = "../tests/testImproveImageQuality/WienerDeconvolutionSuperFunctionParallel/E1";
	// load gray image
	std::string locationSharpGray = "../images/gray/elefant_900x900_gray.png";
	cv::Mat sharpIma_gray = cv::imread(locationSharpGray, cv::IMREAD_GRAYSCALE);
	// load simulated image
	std::string locationSimulatedImage = "../images/gray/simIma_900x900_gray.png";
	cv::Mat simIma_gray = cv::imread(locationSimulatedImage, cv::IMREAD_GRAYSCALE);

	parameterImaImprove_WD paraImaImproveWD_gray{};
	paraImaImproveWD_gray.setMinSNR(1.0);
	paraImaImproveWD_gray.setMaxSNR(200.0);
	paraImaImproveWD_gray.setStepsSNR(100);
	paraImaImproveWD_gray.setMinSigmaXY(0.1);
	paraImaImproveWD_gray.setMaxSigmaXY(5.0);
	paraImaImproveWD_gray.setStepsSigmaXY(100);
	paraImaImproveWD_gray.setKernelSizeHeightAndWidth(30);
	paraImaImproveWD_gray.setCompareInPercent(1.0);

	WienerDeconvolutionSF_parallel_Gray wienerDeconSF_gray;
	wienerDeconSF_gray.setBasicParameter(paraImaImproveWD_gray);
	wienerDeconSF_gray.improveImaQual_WD_superFct_gray_parallel(sharpIma_gray, simIma_gray);

	// ***

	saveBestParameterWD bestParameter = wienerDeconSF_gray.getBestParameter();
	cv::Mat bestFilteredImage = bestParameter.getBestReconstruction();
	real bestSNR = bestParameter.getBestSNR();
	real bestSigma = bestParameter.getBestSigma();
	real improvement = bestParameter.getImprovement();


	Images::saveImageGray_UN8_normByROI_percent(locationTestE1, "bestFilteredImage_normedByROI", "png", bestFilteredImage, wienerDeconSF_gray.getParamerterImaImorove().getCompareInPercent());
	Images::saveImage_normalized(locationTestE1, "bestFilteredImage", "png", bestFilteredImage);
	
	// debug
	std::cout << "best SNR parallel: " << bestSNR << std::endl;
	std::cout << "best sigma parallel: " << bestSigma << std::endl;
	std::cout << "improvement parallel: " << improvement << std::endl;
	// ***
	

	// test
	parameterImaImprove_WD paraImaImproveWD_gray_test{};
	paraImaImproveWD_gray_test.setMinSNR(bestSNR - 0.1);
	paraImaImproveWD_gray_test.setMaxSNR(bestSNR + 0.1);
	paraImaImproveWD_gray_test.setStepsSNR(10);
	paraImaImproveWD_gray_test.setMinSigmaXY(bestSigma - 0.1);
	paraImaImproveWD_gray_test.setMaxSigmaXY(bestSigma + 0.1);
	paraImaImproveWD_gray_test.setStepsSigmaXY(10);
	paraImaImproveWD_gray_test.setKernelSizeHeightAndWidth(paraImaImproveWD_gray.getKernelSizeHeightAndWidth());
	paraImaImproveWD_gray_test.setCompareInPercent(paraImaImproveWD_gray.getCompareInPercent());

	
	real compPer1 = paraImaImproveWD_gray.getCompareInPercent();
	//std::cout << "comp percent1: " << compPer1 << std::endl;
	real comPer2 = paraImaImproveWD_gray_test.getCompareInPercent();
	std::cout << "comp percent2: " << comPer2 << std::endl;
	bool checkComPer = Math::compareTwoNumbers_tolerance(compPer1, comPer2, 0.01);
	test_vec.push_back(checkComPer);

	WienerDeconvolutionSF_Gray wienerDeconSF_gray_test;
	wienerDeconSF_gray_test.setBasicParameter(paraImaImproveWD_gray_test);
	wienerDeconSF_gray_test.improveImaQual_WD_superFct_gray(sharpIma_gray, simIma_gray);

	saveBestParameterWD bestParameter_test = wienerDeconSF_gray_test.getBestParameter();
	cv::Mat bestFilteredImage_test = bestParameter_test.getBestReconstruction();
	real bestSNR_test = bestParameter_test.getBestSNR();
	real bestSigma_test = bestParameter_test.getBestSigma();
	real improvement_test = bestParameter_test.getImprovement();

	// debug
	std::cout << "best SNR parallel test: " << bestSNR_test << std::endl;
	std::cout << "best sigma parallel test: " << bestSigma_test << std::endl;
	std::cout << "improvement parallel test: " << improvement_test << std::endl;
	// ***

	// ***
	// compate improvements
	bool checkImprovement = Math::compareTwoNumbers_tolerance(improvement_test, improvement, 0.1);
	test_vec.push_back(checkImprovement);
	// ***

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

// test E2
bool tWienerDeconSuperFctParallel::testE2()
{
	std::vector<bool> test_vec;
	// location
	std::string locationTestE2 = "../tests/testImproveImageQuality/WienerDeconvolutionSuperFunctionParallel/E2";
	// load gray image
	std::string locationSharpGray = "../images/gray/elefant_900x900_gray.png";
	cv::Mat sharpIma_gray = cv::imread(locationSharpGray, cv::IMREAD_GRAYSCALE);
	// load simulated image
	std::string locationSimulatedImage = "../images/gray/simIma_900x900_gray.png";
	cv::Mat simIma_gray = cv::imread(locationSimulatedImage, cv::IMREAD_GRAYSCALE);

	parameterImaImprove_WD paraImaImproveWD_gray{};
	paraImaImproveWD_gray.setMinSNR(3.9);
	paraImaImproveWD_gray.setMaxSNR(4.1);
	paraImaImproveWD_gray.setStepsSNR(30);
	paraImaImproveWD_gray.setMinSigmaXY(0.4);
	paraImaImproveWD_gray.setMaxSigmaXY(2.6);
	paraImaImproveWD_gray.setStepsSigmaXY(30);
	paraImaImproveWD_gray.setKernelSizeHeightAndWidth(30);
	paraImaImproveWD_gray.setCompareInPercent(1.0);

	WienerDeconvolutionSF_Gray wienerDeconSF_gray;
	wienerDeconSF_gray.setBasicParameter(paraImaImproveWD_gray);
	wienerDeconSF_gray.improveImaQual_WD_superFct_gray(sharpIma_gray, simIma_gray);

	// ***
	saveBestParameterWD bestParameter_blue = wienerDeconSF_gray.getBestParameter();
	cv::Mat bestFilteredImage = bestParameter_blue.getBestReconstruction();
	real bestSNR = bestParameter_blue.getBestSNR();
	real bestSigma = bestParameter_blue.getBestSigma();
	real improvement = bestParameter_blue.getImprovement();

	Images::saveImageGray_UN8_normByROI_percent(locationTestE2, "bestFilteredImage", "png", bestFilteredImage, wienerDeconSF_gray.getParameter().getCompareInPercent());

	//// debug
	//std::cout << "best SNR: " << bestSNR << std::endl;
	//std::cout << "best sigma: " << bestSigma << std::endl;
	//std::cout << "improvement: " << improvement << std::endl;
	//// ***

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

// test E3
bool tWienerDeconSuperFctParallel::testE3()
{
	// tolerance
	real tolerance = 0.1;
	std::vector<bool> test_vec;
	// location
	std::string locationTestE3 = "../tests/testImproveImageQuality/WienerDeconvolutionSuperFunctionParallel/E3";
	// sharp image
	std::string locSharpIma_BGR = "../images/color/useThatImages/useThat/elefant_900x900.png";
	cv::Mat sharpIma_BGR = cv::imread(locSharpIma_BGR, CV_LOAD_IMAGE_COLOR);
	// bluered images
	std::string locBluredIma_BGR = "../images/color/useThatImages/useThat/simIma.png";
	cv::Mat bluredIma_BGR = cv::imread(locBluredIma_BGR, CV_LOAD_IMAGE_COLOR);
	
	// parameter blue
	parameterImaImprove_WD paraImaImproveWD_blue{};
	paraImaImproveWD_blue.setMinSNR(0.1);
	paraImaImproveWD_blue.setMaxSNR(200.0);
	paraImaImproveWD_blue.setStepsSNR(50);
	paraImaImproveWD_blue.setMinSigmaXY(0.1);
	paraImaImproveWD_blue.setMaxSigmaXY(5.0);
	paraImaImproveWD_blue.setStepsSigmaXY(100);
	paraImaImproveWD_blue.setKernelSizeHeightAndWidth(30);
	paraImaImproveWD_blue.setCompareInPercent(1.0);

	// parameter green
	parameterImaImprove_WD paraImaImproveWD_green{};
	paraImaImproveWD_green.setMinSNR(0.1);
	paraImaImproveWD_green.setMaxSNR(200.0);
	paraImaImproveWD_green.setStepsSNR(50);
	paraImaImproveWD_green.setMinSigmaXY(0.1);
	paraImaImproveWD_green.setMaxSigmaXY(5.0);
	paraImaImproveWD_green.setStepsSigmaXY(100);
	paraImaImproveWD_green.setKernelSizeHeightAndWidth(30);
	paraImaImproveWD_green.setCompareInPercent(1.0);

	// parameter red
	parameterImaImprove_WD paraImaImproveWD_red{};
	paraImaImproveWD_red.setMinSNR(0.1);
	paraImaImproveWD_red.setMaxSNR(200.0);
	paraImaImproveWD_red.setStepsSNR(50);
	paraImaImproveWD_red.setMinSigmaXY(0.1);
	paraImaImproveWD_red.setMaxSigmaXY(5.0);
	paraImaImproveWD_red.setStepsSigmaXY(100);
	paraImaImproveWD_red.setKernelSizeHeightAndWidth(30);
	paraImaImproveWD_red.setCompareInPercent(1.0);

	WienerDeconvolutionSF_parallel_BGR wienerDeconParallelBGR;
	wienerDeconParallelBGR.setParameterWD_Global_blue(paraImaImproveWD_blue);
	wienerDeconParallelBGR.setParameterWD_Global_green(paraImaImproveWD_green);
	wienerDeconParallelBGR.setParameterWD_Global_red(paraImaImproveWD_red);

	wienerDeconParallelBGR.improveImaQual_WD_superFct_BGR_parallel(sharpIma_BGR, bluredIma_BGR);

	// *** blue
	saveBestParameterWD bestParameter_blue = wienerDeconParallelBGR.getBestParameter_blue();
	cv::Mat bestFilteredImage_blue = bestParameter_blue.getBestReconstruction();
	real bestSNR_blue = bestParameter_blue.getBestSNR();
	real bestSigma_blue = bestParameter_blue.getBestSigma();
	real improvement_blue = bestParameter_blue.getImprovement();
	Images::saveImageGray_UN8_normByROI_percent(locationTestE3, "bestFilteredImage_blue", "png", bestFilteredImage_blue, wienerDeconParallelBGR.getInitialPara_blue().getCompareInPercent());

	// *** green
	saveBestParameterWD bestParameter_green = wienerDeconParallelBGR.getBestParameter_green();
	cv::Mat bestFilteredImage_green = bestParameter_green.getBestReconstruction();
	real bestSNR_green = bestParameter_green.getBestSNR();
	real bestSigma_green = bestParameter_green.getBestSigma();
	real improvement_green = bestParameter_green.getImprovement();
	Images::saveImageGray_UN8_normByROI_percent(locationTestE3, "bestFilteredImage_green", "png", bestFilteredImage_green, wienerDeconParallelBGR.getInitialPara_green().getCompareInPercent());

	// *** red
	saveBestParameterWD bestParameter_red = wienerDeconParallelBGR.getBestParameter_red();
	cv::Mat bestFilteredImage_red = bestParameter_red.getBestReconstruction();
	real bestSNR_red = bestParameter_red.getBestSNR();
	real bestSigma_red = bestParameter_red.getBestSigma();
	real improvement_red = bestParameter_red.getImprovement();
	Images::saveImageGray_UN8_normByROI_percent(locationTestE3, "bestFilteredImage_red", "png", bestFilteredImage_red, wienerDeconParallelBGR.getInitialPara_red().getCompareInPercent());

	// best filteres image
	Images::saveImageGray_UN8_normByROI_percent(locationTestE3, "bestFilteredImage", "png", wienerDeconParallelBGR.getFilteredResults_normedLikeSharpIma(), wienerDeconParallelBGR.getInitialPara_red().getCompareInPercent());

	// export to txt
	inportExportData::saveStringInTXT_includingTime(locationTestE3 + "/", "saveBestParameterE3", "bestSNR_blue " + std::to_string(bestSNR_blue));
	inportExportData::saveStringInTXT_includingTime(locationTestE3 + "/", "saveBestParameterE3", "bestSigma_blue " + std::to_string(bestSigma_blue));
	inportExportData::saveStringInTXT_includingTime(locationTestE3 + "/", "saveBestParameterE3", "improvement_blue " + std::to_string(improvement_blue));
	
	inportExportData::saveStringInTXT_includingTime(locationTestE3 + "/", "saveBestParameterE3", "bestSNR_green " + std::to_string(bestSNR_green));
	inportExportData::saveStringInTXT_includingTime(locationTestE3 + "/", "saveBestParameterE3", "bestSigma_green " + std::to_string(bestSigma_green));
	inportExportData::saveStringInTXT_includingTime(locationTestE3 + "/", "saveBestParameterE3", "improvement_green " + std::to_string(improvement_green));

	inportExportData::saveStringInTXT_includingTime(locationTestE3 + "/", "saveBestParameterE3", "bestSNR_red " + std::to_string(bestSNR_red));
	inportExportData::saveStringInTXT_includingTime(locationTestE3 + "/", "saveBestParameterE3", "bestSigma_red " + std::to_string(bestSigma_red));
	inportExportData::saveStringInTXT_includingTime(locationTestE3 + "/", "saveBestParameterE3", "improvement_red " + std::to_string(improvement_red));


	real improvement_1 = Images::calcImprovementBGR(sharpIma_BGR, bluredIma_BGR, wienerDeconParallelBGR.getFilteredResults_normedZeroAndMaxUchar(), wienerDeconParallelBGR.getInitialPara_red().getCompareInPercent());
	inportExportData::saveStringInTXT_includingTime(locationTestE3 + "/", "saveBestParameterE3", "improvement_1: " + std::to_string(improvement_1));
	
	real improvement_2 = Images::calcImprovementBGR(sharpIma_BGR, bluredIma_BGR, wienerDeconParallelBGR.getFilteredResults_normedLikeSharpIma(), wienerDeconParallelBGR.getInitialPara_red().getCompareInPercent());
	inportExportData::saveStringInTXT_includingTime(locationTestE3 + "/", "saveBestParameterE3", "improvement_2: " + std::to_string(improvement_2));


	paraImaImproveWD_blue.setMinSNR(bestSNR_blue - 0.5);
	paraImaImproveWD_blue.setMaxSNR(bestSNR_blue + 0.5);
	paraImaImproveWD_blue.setStepsSNR(5.0);
	paraImaImproveWD_blue.setMinSigmaXY(bestSigma_blue - 0.5);
	paraImaImproveWD_blue.setMaxSigmaXY(bestSigma_blue + 0.5);
	paraImaImproveWD_blue.setStepsSigmaXY(5.0);

	paraImaImproveWD_green.setMinSNR(bestSNR_green - 0.5);
	paraImaImproveWD_green.setMaxSNR(bestSNR_green + 0.5);
	paraImaImproveWD_green.setStepsSNR(5.0);
	paraImaImproveWD_green.setMinSigmaXY(bestSigma_green - 0.5);
	paraImaImproveWD_green.setMaxSigmaXY(bestSigma_green + 0.5);
	paraImaImproveWD_green.setStepsSigmaXY(5.0);

	paraImaImproveWD_red.setMinSNR(bestSNR_red - 0.5);
	paraImaImproveWD_red.setMaxSNR(bestSNR_red + 0.5);
	paraImaImproveWD_red.setStepsSNR(5.0);
	paraImaImproveWD_red.setMinSigmaXY(bestSigma_red - 0.5);
	paraImaImproveWD_red.setMaxSigmaXY(bestSigma_red + 0.5);
	paraImaImproveWD_red.setStepsSigmaXY(5.0);

	WienerDeconvolutionSuperFunction wienerDevon_superFct;
	
	wienerDevon_superFct.setParameter_blue(paraImaImproveWD_blue);
	wienerDevon_superFct.setParameter_green(paraImaImproveWD_green);
	wienerDevon_superFct.setParameter_red(paraImaImproveWD_red);
	wienerDevon_superFct.improveImaQual_WD_superFct(sharpIma_BGR, bluredIma_BGR);
	
	cv::Mat filteredBRG_image = wienerDevon_superFct.getFilteredImage();
	real improvement_3 = Images::calcImprovementBGR(sharpIma_BGR, bluredIma_BGR, filteredBRG_image, wienerDeconParallelBGR.getInitialPara_red().getCompareInPercent());
	bool checkImprovement1_3 = Math::compareTwoNumbers_tolerance(improvement_1, improvement_3, tolerance);
	test_vec.push_back(checkImprovement1_3);
	inportExportData::saveStringInTXT_includingTime(locationTestE3 + "/", "saveBestParameterE3", "improvement_3: " + std::to_string(improvement_3));

	// bluered image
	cv::Mat imageBluered_blue;
	cv::Mat imageBluered_green;
	cv::Mat imageBluered_red;
	cv::Mat channelBluredImage[3];
	cv::split(bluredIma_BGR, channelBluredImage);
	imageBluered_blue = channelBluredImage[0];
	imageBluered_green = channelBluredImage[1];
	imageBluered_red = channelBluredImage[2];

	// sharp image
	cv::Mat imageSharp_blue;
	cv::Mat imageSharp_green;
	cv::Mat imageSharp_red;
	cv::Mat channelSharpImage[3];
	cv::split(sharpIma_BGR, channelSharpImage);
	imageSharp_blue = channelSharpImage[0];
	imageSharp_green = channelSharpImage[1];
	imageSharp_red = channelSharpImage[2];

	WienerDeconvolutionSF_parallel_Gray wienerDeconSF_blue;
	wienerDeconSF_blue.setBasicParameter(paraImaImproveWD_blue);
	wienerDeconSF_blue.improveImaQual_WD_superFct_gray_parallel(imageSharp_blue, imageBluered_blue);

	WienerDeconvolutionSF_parallel_Gray wienerDeconSF_green;
	wienerDeconSF_green.setBasicParameter(paraImaImproveWD_green);
	wienerDeconSF_green.improveImaQual_WD_superFct_gray_parallel(imageSharp_green, imageBluered_green);

	WienerDeconvolutionSF_parallel_Gray wienerDeconSF_red;
	wienerDeconSF_red.setBasicParameter(paraImaImproveWD_red);
	wienerDeconSF_red.improveImaQual_WD_superFct_gray_parallel(imageSharp_red, imageBluered_red);

	// *** _blue
	saveBestParameterWD bestParameter_blue_test = wienerDeconSF_blue.getBestParameter();
	cv::Mat bestFilteredImage_blue_test = bestParameter_blue_test.getBestReconstruction();
	real improvement_test_blue = Images::calcImprovementGray(imageSharp_blue, imageBluered_blue, bestFilteredImage_blue_test, wienerDeconParallelBGR.getInitialPara_blue().getCompareInPercent());
	bool checkImp_blue = Math::compareTwoNumbers_tolerance(improvement_test_blue, improvement_blue, tolerance);
	test_vec.push_back(checkImp_blue);
	// ***

	// *** _green
	saveBestParameterWD bestParameter_green_test = wienerDeconSF_green.getBestParameter();
	cv::Mat bestFilteredImage_green_test = bestParameter_green_test.getBestReconstruction();
	real improvement_test_green = Images::calcImprovementGray(imageSharp_green, imageBluered_green, bestFilteredImage_green_test, wienerDeconParallelBGR.getInitialPara_green().getCompareInPercent());
	bool checkImp_green = Math::compareTwoNumbers_tolerance(improvement_test_green, improvement_green, tolerance);
	test_vec.push_back(checkImp_green);
	// ***

	// *** _red
	saveBestParameterWD bestParameter_red_test = wienerDeconSF_red.getBestParameter();
	cv::Mat bestFilteredImage_red_test = bestParameter_red_test.getBestReconstruction();
	real improvement_test_red = Images::calcImprovementGray(imageSharp_red, imageBluered_red, bestFilteredImage_red_test, wienerDeconParallelBGR.getInitialPara_red().getCompareInPercent());
	bool checkImp_red = Math::compareTwoNumbers_tolerance(improvement_test_red, improvement_red, tolerance);
	test_vec.push_back(checkImp_red);
	// ***



	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

// test E4
bool tWienerDeconSuperFctParallel::testE4()
{
	std::vector<bool> test_vec;
	// location
	std::string locationTestE4 = "../tests/testImproveImageQuality/WienerDeconvolutionSuperFunctionParallel/E4";
	// sharp image
	std::string locSharpIma_BGR = "../images/color/useThatImages/useThat/elefant_900x900.png";
	cv::Mat sharpIma_BGR = cv::imread(locSharpIma_BGR, CV_LOAD_IMAGE_COLOR);
	// bluered images
	std::string locBluredIma_BGR = "../images/color/useThatImages/useThat/simIma.png";
	cv::Mat bluredIma_BGR = cv::imread(locBluredIma_BGR, CV_LOAD_IMAGE_COLOR);


	// bluered image blue
	cv::Mat imageBluered_blue;
	cv::Mat channelBluredImage[3];
	cv::split(bluredIma_BGR, channelBluredImage);
	imageBluered_blue = channelBluredImage[0];

	// sharp image blue
	cv::Mat imageSharp_blue;
	cv::Mat channelSharpImage[3];
	cv::split(sharpIma_BGR, channelSharpImage);
	imageSharp_blue = channelSharpImage[0];

	parameterImaImprove_WD paraImaImproveWD_blue{};
	paraImaImproveWD_blue.setMinSNR(0.1);
	paraImaImproveWD_blue.setMaxSNR(100.0);
	paraImaImproveWD_blue.setStepsSNR(50);
	paraImaImproveWD_blue.setMinSigmaXY(0.1);
	paraImaImproveWD_blue.setMaxSigmaXY(5.0);
	paraImaImproveWD_blue.setStepsSigmaXY(50);
	paraImaImproveWD_blue.setKernelSizeHeightAndWidth(30);
	paraImaImproveWD_blue.setCompareInPercent(1.0);

	WienerDeconvolutionSF_parallel_Gray wienerDeconSF_blue;
	wienerDeconSF_blue.setBasicParameter(paraImaImproveWD_blue);
	wienerDeconSF_blue.improveImaQual_WD_superFct_gray_parallel(imageSharp_blue, imageBluered_blue);

	// ***
	saveBestParameterWD bestParameter_blue = wienerDeconSF_blue.getBestParameter();
	cv::Mat bestFilteredImage = bestParameter_blue.getBestReconstruction();
	real bestSNR = bestParameter_blue.getBestSNR();
	real bestSigma = bestParameter_blue.getBestSigma();
	real improvement = bestParameter_blue.getImprovement();

	Images::saveImageGray_UN8_normByROI_percent(locationTestE4, "bestFilteredImage", "png", bestFilteredImage, wienerDeconSF_blue.getParamerterImaImorove().getCompareInPercent());

	//// debug
	//std::cout << "best SNR: " << bestSNR << std::endl;
	//std::cout << "best sigma: " << bestSigma << std::endl;
	//std::cout << "improvement: " << improvement << std::endl;
	//// ***

	real testImprovement = Images::calcImprovementGray(imageSharp_blue, imageBluered_blue, bestFilteredImage, wienerDeconSF_blue.getParamerterImaImorove().getCompareInPercent());
	std::cout << "test improvement: " << testImprovement << std::endl;

	bool checkImprovement = Math::compareTwoNumbers_tolerance(testImprovement, improvement, 0.001);
	test_vec.push_back(checkImprovement);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

// test E5
bool tWienerDeconSuperFctParallel::testE5()
{
	std::vector<bool> test_vec{};

	// object
	std::string pinguin = "pinguin_900x900";
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_pinguin = Images::loadAnImage_Color(loactionObject, pinguin);

	// sim ima
	std::string simIma_pinguin = "simIma_pinguin";
	std::string locationImages = "../tests/testImageSimulation/S12";
	cv::Mat  simImaMat_pinguin = Images::loadAnImage_Color(locationImages, simIma_pinguin);

	// *** parameter wiener filter *** 
	// *** parameter blue *** 
	parameterImaImprove_WD paraImaImproveWD_blue{};
	paraImaImproveWD_blue.setMinSigmaXY(4.5);
	paraImaImproveWD_blue.setMaxSigmaXY(5.0);
	paraImaImproveWD_blue.setStepsSigmaXY(20.0);
	paraImaImproveWD_blue.setMinSNR(191.0);
	paraImaImproveWD_blue.setMaxSNR(195.0);
	paraImaImproveWD_blue.setStepsSNR(20.0);
	paraImaImproveWD_blue.setKernelSizeHeightAndWidth(30);
	paraImaImproveWD_blue.setCompareInPercent(3.0);
	paraImaImproveWD_blue.setSharpnessEvalMethode(sharpnessEvalMethode::sharpImage);
	// *** parameter green
	parameterImaImprove_WD paraImaImproveWD_green{};
	paraImaImproveWD_green.setMinSigmaXY(4.0);
	paraImaImproveWD_green.setMaxSigmaXY(4.2);
	paraImaImproveWD_green.setStepsSigmaXY(20.0);
	paraImaImproveWD_green.setMinSNR(160.0);
	paraImaImproveWD_green.setMaxSNR(163.0);
	paraImaImproveWD_green.setStepsSNR(20.0);
	paraImaImproveWD_green.setKernelSizeHeightAndWidth(30);
	paraImaImproveWD_green.setCompareInPercent(3.0);
	paraImaImproveWD_green.setSharpnessEvalMethode(sharpnessEvalMethode::sharpImage);
	// *** parameter red
	parameterImaImprove_WD paraImaImproveWD_red{};
	paraImaImproveWD_red.setMinSigmaXY(3.1);
	paraImaImproveWD_red.setMaxSigmaXY(3.3);
	paraImaImproveWD_red.setStepsSigmaXY(20.0);
	paraImaImproveWD_red.setMinSNR(125.0);
	paraImaImproveWD_red.setMaxSNR(128.0);
	paraImaImproveWD_red.setStepsSNR(20.0);
	paraImaImproveWD_red.setKernelSizeHeightAndWidth(30);
	paraImaImproveWD_red.setCompareInPercent(3.0);
	paraImaImproveWD_red.setSharpnessEvalMethode(sharpnessEvalMethode::sharpImage);

	WienerDeconvolutionSF_parallel_BGR wienerDevon_superFct;
	wienerDevon_superFct.setParameterWD_Global_blue(paraImaImproveWD_blue);
	wienerDevon_superFct.setParameterWD_Global_green(paraImaImproveWD_green);
	wienerDevon_superFct.setParameterWD_Global_red(paraImaImproveWD_red);

	wienerDevon_superFct.improveImaQual_WD_superFct_BGR_parallel(object_pinguin, simImaMat_pinguin);

	saveBestParameterWD bestPara_blue = wienerDevon_superFct.getBestParameter_blue();
	saveBestParameterWD bestPara_green = wienerDevon_superFct.getBestParameter_green();
	saveBestParameterWD bestPara_red = wienerDevon_superFct.getBestParameter_red();

	cv::Mat filteredIma = wienerDevon_superFct.getFilteredResults_normedZeroAndMaxUchar();

	std::string location = "../tests/testImproveImageQuality/WienerDeconvolutionSuperFunctionParallel/E5";
	// save filtered images
	Images::saveImage_normalized(location, "filteredIma", "png", filteredIma);
	bestPara_blue.exportAsTXTfile(location, "bestPara_blue", true);
	bestPara_green.exportAsTXTfile(location, "bestPara_green", true);
	bestPara_red.exportAsTXTfile(location, "bestPara_red", true);

	real improvement = Images::calcImprovementBGR(object_pinguin, simImaMat_pinguin, filteredIma, paraImaImproveWD_blue.getCompareInPercent());
	inportExportData::saveDoubleInTXT(location, "improvement", "total improvement: ", improvement);


	real improv_blue = bestPara_blue.getImprovement();
	bool checkImpro_blue = improv_blue > 1.269;
	test_vec.push_back(checkImpro_blue);
	real improv_green = bestPara_green.getImprovement();
	bool checkImpro_green = improv_green > 1.292;
	test_vec.push_back(checkImpro_green);
	real improv_red = bestPara_red.getImprovement();
	bool checkImpro_red = improv_red > 1.350;
	test_vec.push_back(checkImpro_red);

	bool totalCheck = Math::checkTrueOfVectorElements(test_vec);
	return totalCheck;

}