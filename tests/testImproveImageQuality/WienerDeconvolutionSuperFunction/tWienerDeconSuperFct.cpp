#include "tWienerDeconSuperFct.h"

// important structs
#include "..\..\..\LowLevelTracing\ImportantStructures.h"

// images
#include "..\..\..\Image\Images.h"

// Math
#include "..\..\..\LowLevelTracing\Math_LLT.h"

// wiener deconvolution super function
#include "..\..\..\ImageProcessing\WienerDeconvolutioinSuperFuction.h"

testWienerDeconSuperFct::testWienerDeconSuperFct(){}

testWienerDeconSuperFct::~testWienerDeconSuperFct(){}



bool testWienerDeconSuperFct::testWienerDeconSuperFct_superFct()
{
	std::vector<bool> test_vec;

	// E0
	bool checkE0 = testE0();
	test_vec.push_back(checkE0);


	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

// E0
bool testWienerDeconSuperFct::testE0()
{
	std::vector<bool> test_vec;
	std::string locSharpIma = "../images/color/useThatImages/useThat/elefant_900x900.png";
	cv::Mat sharpIma = cv::imread(locSharpIma, CV_LOAD_IMAGE_COLOR);
	std::string locBluredIma = "../images/color/useThatImages/useThat/simIma.png";
	cv::Mat bluredIma = cv::imread(locBluredIma, CV_LOAD_IMAGE_COLOR);
	std::string locationTest7 = "../tests/testImproveImageQuality/WienerDeconvolutionSuperFunction/E0";

	// save gray images
	// sharp image
	cv::Mat channelSharpImage[3];
	cv::split(sharpIma, channelSharpImage);
	cv::Mat imageSharp_blue = channelSharpImage[0];
	cv::Mat imageSharp_green = channelSharpImage[1];
	cv::Mat imageSharp_red = channelSharpImage[2];

	// bluered image
	cv::Mat channelBluredImage[3];
	cv::split(bluredIma, channelBluredImage);
	cv::Mat bluredIma_blue = channelBluredImage[0];
	cv::Mat bluredIma_green = channelBluredImage[1];
	cv::Mat bluredIma_red = channelBluredImage[2];

	Images::saveImage_normalized(locationTest7, "sharp blue", "png", imageSharp_blue);
	Images::saveImage_normalized(locationTest7, "sharp green", "png", imageSharp_green);
	Images::saveImage_normalized(locationTest7, "sharp red", "png", imageSharp_red);

	Images::saveImage_normalized(locationTest7, "bluered blue", "png", bluredIma_blue);
	Images::saveImage_normalized(locationTest7, "bluered green", "png", bluredIma_green);
	Images::saveImage_normalized(locationTest7, "bluered red", "png", bluredIma_red);

	parameterImaImprove_WD paraWD_blue;
	paraWD_blue.setMinSNR(49.0);
	paraWD_blue.setMaxSNR(50.0);
	paraWD_blue.setStepsSNR(10.0);
	paraWD_blue.setMinSigmaXY(5.0);
	paraWD_blue.setMaxSigmaXY(6.0);
	paraWD_blue.setStepsSigmaXY(10.0);
	paraWD_blue.setKernelSizeHeightAndWidth(30);
	paraWD_blue.setCompareInPercent(7.0);

	parameterImaImprove_WD paraWD_green;
	paraWD_green.setMinSNR(4.0);
	paraWD_green.setMaxSNR(5.0);
	paraWD_green.setStepsSNR(10.0);
	paraWD_green.setMinSigmaXY(1.0);
	paraWD_green.setMaxSigmaXY(2.0);
	paraWD_green.setStepsSigmaXY(10.0);
	paraWD_green.setKernelSizeHeightAndWidth(30);
	paraWD_green.setCompareInPercent(7.0);

	parameterImaImprove_WD paraWD_red;
	paraWD_red.setMinSNR(138.0);
	paraWD_red.setMaxSNR(139.0);
	paraWD_red.setStepsSNR(10.0);
	paraWD_red.setMinSigmaXY(2.85);
	paraWD_red.setMaxSigmaXY(2.95);
	paraWD_red.setStepsSigmaXY(10.0);
	paraWD_red.setKernelSizeHeightAndWidth(30);
	paraWD_red.setCompareInPercent(7.0);

	WienerDeconvolutionSuperFunction wienerDevon_superFct;
	wienerDevon_superFct.setParameter_blue(paraWD_blue);
	wienerDevon_superFct.setParameter_green(paraWD_green);
	wienerDevon_superFct.setParameter_red(paraWD_red);

	wienerDevon_superFct.improveImaQual_WD_superFct(sharpIma, bluredIma);

	// *** blue
	saveBestParameterWD bestParameter_blue = wienerDevon_superFct.getBestParameter_blue();
	cv::Mat bestFilteredImage_blue = bestParameter_blue.getBestReconstruction();
	real bestSNR_blue = bestParameter_blue.getBestSNR();
	real bestSigma_blue = bestParameter_blue.getBestSigma();
	real improvement_blue = bestParameter_blue.getImprovement();

	Images::saveImageGray_UN8_normByROI_percent(locationTest7, "bestFilteredImage_blue", "png", bestFilteredImage_blue, wienerDevon_superFct.getParameter_blue().getCompareInPercent());

	// debug
	std::cout << "best SNR blue: " << bestSNR_blue << std::endl;
	std::cout << "best sigma blue: " << bestSigma_blue << std::endl;
	std::cout << "improvement blue: " << improvement_blue << std::endl;
	// ***

	// *** green
	saveBestParameterWD bestParameter_green = wienerDevon_superFct.getBestParameter_green();
	cv::Mat bestFilteredImage_green = bestParameter_green.getBestReconstruction();
	real bestSNR_green = bestParameter_green.getBestSNR();
	real bestSigma_green = bestParameter_green.getBestSigma();
	real improvement_green = bestParameter_green.getImprovement();

	Images::saveImageGray_UN8_normByROI_percent(locationTest7, "bestFilteredImage_green", "png", bestFilteredImage_green, wienerDevon_superFct.getParameter_green().getCompareInPercent());

	// debug
	std::cout << "best SNR green: " << bestSNR_green << std::endl;
	std::cout << "best sigma green: " << bestSigma_green << std::endl;
	std::cout << "improvement green: " << improvement_green << std::endl;
	// ***

	// *** red
	saveBestParameterWD bestParameter_red = wienerDevon_superFct.getBestParameter_red();
	cv::Mat bestFilteredImage_red = bestParameter_red.getBestReconstruction();
	real bestSNR_red = bestParameter_red.getBestSNR();
	real bestSigma_red = bestParameter_red.getBestSigma();
	real improvement_red = bestParameter_red.getImprovement();

	Images::saveImageGray_UN8_normByROI_percent(locationTest7, "bestFilteredImage_red", "png", bestFilteredImage_red, wienerDevon_superFct.getParameter_red().getCompareInPercent());

	// debug
	std::cout << "best SNR red: " << bestSNR_red << std::endl;
	std::cout << "best sigma red: " << bestSigma_red << std::endl;
	std::cout << "improvement red: " << improvement_red << std::endl;
	// ***

	cv::Mat filteredBRG_image = wienerDevon_superFct.getFilteredImage();

	Images::saveImageGray_UN8_normByROI_percent(locationTest7, "bestilteredImageBGR", "png", filteredBRG_image, wienerDevon_superFct.getParameter_red().getCompareInPercent());

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

	