#include "testImproveImageQuality.h"

#include "..\..\Image\Images.h"

// math
#include "..\..\LowLevelTracing\Math_LLT.h"

// import export data
#include "..\..\Inport_Export_Data\Inport_Export_Data.h"

// image simulation
#include "..\..\Image\ImageSimulation.h"

// often use
#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

// unsharp masking
#include "..\..\ImageProcessing\UnsharpMasking.h"

// detail Enhance
#include "..\..\ImageProcessing\DetailEnhancement.h"

// test
// remove chromatic aberration
#include "..\..\ImageProcessing\RemoveChromaticAberrations.h"

// typedef
typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

testImproveImageQuality::testImproveImageQuality()
{
	loadImportantStuff();
}
testImproveImageQuality::~testImproveImageQuality() {}

// load important things
void testImproveImageQuality::loadImportantStuff()
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

// export all PSFs to CSV
void testImproveImageQuality::exportAllPSFsToCSV(std::vector<cv::Mat> psf_vec_blue, std::vector<cv::Mat> psf_vec_green, std::vector<cv::Mat> psf_vec_red, std::string location)
{

	unsigned int size = psf_vec_blue.size();
	std::string nameBlue = "blue_";
	std::string nameGreen = "green_";
	std::string nameRed = "red_";

	std::string tempNameBlue{};
	std::string tempNameGreen{};
	std::string tempNameRed{};

	std::string tempNumInt{};



	for (unsigned int i = 0; i < size; ++i)
	{
		tempNameBlue = nameBlue;
		tempNameGreen = nameGreen;
		tempNameRed = nameRed;

		tempNumInt = std::to_string(i);
		tempNameBlue = tempNameBlue + tempNumInt;
		tempNameGreen = tempNameGreen + tempNumInt;
		tempNameRed = tempNameRed + tempNumInt;

		inportExportData::exportCV_MatToExcel(psf_vec_blue[i], location, tempNameBlue);
		inportExportData::exportCV_MatToExcel(psf_vec_green[i], location, tempNameGreen);
		inportExportData::exportCV_MatToExcel(psf_vec_red[i], location, tempNameRed);

	}



}

std::vector<cv::Mat> testImproveImageQuality::inportManyPSFsToMat(std::string name, std::string location, unsigned int size)
{
	cv::Mat tempMat{};
	std::string tempNumber{};
	std::string tempNameAndNum{};
	std::vector<cv::Mat> returnMat_vec{};
	returnMat_vec.resize(size);

	for (unsigned int i = 0; i < size; ++i)
	{
		tempNumber = std::to_string(i);
		tempNameAndNum = name + tempNumber;
		tempMat = inportExportData::importCSVtoCVmat(location, tempNameAndNum);
		returnMat_vec[i] = tempMat;
	}

	return returnMat_vec;
}




bool testImproveImageQuality::checkImproveImageQuality_openCV_Func()
{
	std::vector<bool> workTheSystem{};
	real tolerance = 1.0;



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

	//// unsharp masking --> elefant
	//std::vector<cv::Size> kernelSize{ {9,9}, {11,11} };
	//cv::Mat elefant_Sharp = Images::loadAnImage_Color("../images/color/useThatImages/useThat/", "elefant_sharp.jpg");
	//cv::Mat elefeant_Simulated = Images::loadAnImage_Color("../images/color/useThatImages/useThat/", "elefant_simulated.png");
	//cv::Mat elefant_Simulated_resize = Images::resizeImage(elefeant_Simulated, elefant_Sharp.size(), 0.0, 0.0, cv::INTER_LINEAR);
	//unsharpMaskStruct sharpImage_unsharpMasking_elefant_multiCore = improveImaQua.improveImageQuality_unsharpMask_multiCore(elefant_Sharp, elefant_Simulated_resize, kernelSize, 7.5, 10.0, 100.0, 1.0, 2.0, 100.0, cv::BORDER_DEFAULT, 0.0, 0.0, 1.0, 1.0, 1.0, 1);
	//sharpImage_unsharpMasking_elefant_multiCore.printPara_UnsharpMaskinFilter_Struct();
	//Images::showImage_inputReal_normTheImage("unsharp masking elefant", sharpImage_unsharpMasking_elefant_multiCore.getImage());
	//Images::saveImage("../images", "unsharpMaskingElefant" , "png", sharpImage_unsharpMasking_elefant_multiCore.getImage());

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


bool testImproveImageQuality::checkDetailEnhance_BFA_superFunc()
{
	std::vector<bool> workTheSystem{};

	//// test 0
	//bool checlDE0 = testDE_BFA_0();
	//workTheSystem.push_back(checlDE0);
	// test 1
	bool checkDE1 = testDE_BFA_1();
	workTheSystem.push_back(checkDE1);


	bool workReturn = Math::checkTrueOfVectorElements(workTheSystem);
	return workReturn;

}



bool testImproveImageQuality::checkUnsharpMasking_BFA_superFunc()
{
	std::vector<bool> workTheSystem{};

	// test 1
	bool checkUM0 = testUM_BFA_0();
	workTheSystem.push_back(checkUM0);
	// test 2
	bool checkUM1 = testUM_BFA_1();
	workTheSystem.push_back(checkUM1);

	bool workReturn = Math::checkTrueOfVectorElements(workTheSystem);
	return workReturn;

}

bool testImproveImageQuality::testDE_BFA_0()
{
	std::vector<bool> workTheSystem{};

	// location
	std::string locationTest0 = "../tests/testImproveImageQuality/detailEnhancement/E0";
	// sharp image
	std::string locSharpIma_BGR = "../images/color/useThatImages/useThat/elefant_900x900.png";
	cv::Mat sharpIma_BGR = cv::imread(locSharpIma_BGR, CV_LOAD_IMAGE_COLOR);
	// bluered images
	std::string locBluredIma_BGR = "../images/color/useThatImages/useThat/simIma.png";
	cv::Mat bluredIma_BGR = cv::imread(locBluredIma_BGR, CV_LOAD_IMAGE_COLOR);

	parameterDetailEnhancement paraDE;
	paraDE.setMinSigma_r(0.001);
	paraDE.setMaxSigma_r(1.0);
	paraDE.setStepsSigma_r(10.0);
	paraDE.setMinSigma_s(1.0);
	paraDE.setMaxSigma_s(5.0);
	paraDE.setStepsSigma_s(10.0);
	paraDE.setPercentCompare(1.0);

	DetailEnhancement_BGR detailEnhance;
	detailEnhance.setInitialParameter(paraDE);
	detailEnhance.improveImageQuality_DetailEnhancement_BGR(sharpIma_BGR, bluredIma_BGR);

	bestParameterStruct_detailEnhance bestParaDE = detailEnhance.getBestParameter();
	real bestSigma_r = bestParaDE.getSigmar_r();
	real bestSigma_s = bestParaDE.getSigmar_s();
	real improvement = bestParaDE.getImprovement();
	cv::Mat bestIma = bestParaDE.getImage();

	// // debug
	// std::cout << "best sigma r: " << bestSigma_r << std::endl;
	// std::cout << "best sigma s: " << bestSigma_s << std::endl;
	// std::cout << "improvement: " << improvement << std::endl;

	Images::saveImageGray_UN8_normByROI_percent(locationTest0, "bestFilteredIma", "png", bestIma, detailEnhance.getInitialParameter().getPercentCompare());

	// save best parameter
	bestParaDE.exportAsTXTfile(locationTest0, "bestParaE0", true);

	bool workReturn = Math::checkTrueOfVectorElements(workTheSystem);
	return workReturn;
}

//test 0
bool testImproveImageQuality::testUM_BFA_0()
{
	std::vector<bool> workTheSystem{};

	// location
	std::string locationTest0 = "../tests/testImproveImageQuality/unsharpMasking/E0";
	// load gray image
	std::string locationSharpGray = "../images/gray/elefant_900x900_gray.png";
	cv::Mat sharpIma_gray = cv::imread(locationSharpGray, cv::IMREAD_GRAYSCALE);
	// load simulated image
	std::string locationSimulatedImage = "../images/gray/simIma_900x900_gray.png";
	cv::Mat blueredIma_gray = cv::imread(locationSimulatedImage, cv::IMREAD_GRAYSCALE);

	parameterUnsharpMasking paraUM;
	paraUM.setMinSigma(0.5);
	paraUM.setMaxSigma(10.0);
	paraUM.setStepsSigma(1.0);
	paraUM.setMinAmount(0.01);
	paraUM.setMaxAmount(3.0);
	paraUM.setStepsAmount(1.0);
	paraUM.setMinThreshold(0.01);
	paraUM.setMaxThreshold(5.0);
	paraUM.setStepsThreshold(1.0);
	paraUM.setBoarderType(cv::BORDER_DEFAULT);
	paraUM.setCompareInPercent(1.0);

	UnshaprMasking_singleCore_gray unsharpMasking;
	unsharpMasking.setParameterUM(paraUM);
	unsharpMasking.improveImageQuality_unsharpMask_gray(sharpIma_gray, blueredIma_gray);

	bestParameterStruct_unsharpMask bestPara = unsharpMasking.getBestParameter();
	cv::Mat filteredImage = bestPara.getImage();
	real bestSigma = bestPara.getSigma();
	real bestAmount = bestPara.getAmount();
	real bestThreshold = bestPara.getThreshold();

	// print best parameter
	std::cout << "best sigma: " << bestSigma << std::endl;
	std::cout << "best amount: " << bestAmount << std::endl;
	std::cout << "best threshold: " << bestThreshold << std::endl;

	bestPara.exportAsTXTfile(locationTest0, "unsharpMaskingE0", true);

	Images::saveImage_normalized(locationTest0, "filterdImageUM", "png", filteredImage);

	bool workReturn = Math::checkTrueOfVectorElements(workTheSystem);
	return workReturn;


}

// test 1
bool testImproveImageQuality::testUM_BFA_1()
{

	std::vector<bool> workTheSystem{};

	// location
	std::string locationTest1 = "../tests/testImproveImageQuality/unsharpMasking/E1";
	// sharp image
	std::string locSharpIma_BGR = "../images/color/useThatImages/useThat/elefant_900x900.png";
	cv::Mat sharpIma_BGR = cv::imread(locSharpIma_BGR, CV_LOAD_IMAGE_COLOR);
	// bluered images
	std::string locBluredIma_BGR = "../images/color/useThatImages/useThat/simIma.png";
	cv::Mat bluredIma_BGR = cv::imread(locBluredIma_BGR, CV_LOAD_IMAGE_COLOR);

	parameterUnsharpMasking paraUM_blue;
	paraUM_blue.setMinSigma(0.1);
	paraUM_blue.setMaxSigma(10.0);
	paraUM_blue.setStepsSigma(100.0);
	paraUM_blue.setMinAmount(0.01);
	paraUM_blue.setMaxAmount(3.0);
	paraUM_blue.setStepsAmount(100.0);
	paraUM_blue.setMinThreshold(0.0);
	paraUM_blue.setMaxThreshold(5.0);
	paraUM_blue.setStepsThreshold(50.0);
	paraUM_blue.setBoarderType(cv::BORDER_DEFAULT);
	paraUM_blue.setCompareInPercent(1.0);

	parameterUnsharpMasking paraUM_green;
	paraUM_green.setMinSigma(0.1);
	paraUM_green.setMaxSigma(10.0);
	paraUM_green.setStepsSigma(100.0);
	paraUM_green.setMinAmount(0.01);
	paraUM_green.setMaxAmount(3.0);
	paraUM_green.setStepsAmount(100.0);
	paraUM_green.setMinThreshold(0.0);
	paraUM_green.setMaxThreshold(5.0);
	paraUM_green.setStepsThreshold(50.0);
	paraUM_green.setBoarderType(cv::BORDER_DEFAULT);
	paraUM_green.setCompareInPercent(1.0);

	parameterUnsharpMasking paraUM_red;
	paraUM_red.setMinSigma(0.1);
	paraUM_red.setMaxSigma(10.0);
	paraUM_red.setStepsSigma(100.0);
	paraUM_red.setMinAmount(0.01);
	paraUM_red.setMaxAmount(3.0);
	paraUM_red.setStepsAmount(100.0);
	paraUM_red.setMinThreshold(0.0);
	paraUM_red.setMaxThreshold(5.0);
	paraUM_red.setStepsThreshold(50.0);
	paraUM_red.setBoarderType(cv::BORDER_DEFAULT);
	paraUM_red.setCompareInPercent(1.0);

	unsharpMasking_BGR_parallel UM_BGR_parallel;
	UM_BGR_parallel.setParameterUM_blue(paraUM_blue);
	UM_BGR_parallel.setParameterUM_green(paraUM_green);
	UM_BGR_parallel.setParameterUM_red(paraUM_red);

	UM_BGR_parallel.improveImaQual_UnsharpMasking_superFct_BGR_parallel(sharpIma_BGR, bluredIma_BGR);

	// best parameter blue
	bestParameterStruct_unsharpMask bestParameter_blue = UM_BGR_parallel.getBestParameter_blue();
	real bestSigma_blue = bestParameter_blue.getSigma();
	real bestAmount_blue = bestParameter_blue.getAmount();
	real bestThreshold_blue = bestParameter_blue.getThreshold();
	real improvement_blue = bestParameter_blue.getImprovement();
	std::cout << "best sigma blue: " << bestSigma_blue << std::endl;
	std::cout << "best amount blue: " << bestAmount_blue << std::endl;
	std::cout << "best threshold blue: " << bestThreshold_blue << std::endl;
	std::cout << "improvement blue: " << improvement_blue << std::endl;
	bestParameter_blue.exportAsTXTfile(locationTest1, "bestPara_blue", true);
	// best filteres image blue
	Images::saveImageGray_UN8_normByROI_percent(locationTest1, "bestFilteredImage_blue", "png", UM_BGR_parallel.getBestParameter_blue().getImage(), UM_BGR_parallel.getInitialPara_blue().getCompareInPercent());

	// best parameter green
	bestParameterStruct_unsharpMask bestParameter_green = UM_BGR_parallel.getBestParameter_green();
	real bestSigma_green = bestParameter_green.getSigma();
	real bestAmount_green = bestParameter_green.getAmount();
	real bestThreshold_green = bestParameter_green.getThreshold();
	real improvement_green = bestParameter_green.getImprovement();
	std::cout << "best sigma green: " << bestSigma_green << std::endl;
	std::cout << "best amount green: " << bestAmount_green << std::endl;
	std::cout << "best threshold green: " << bestThreshold_green << std::endl;
	std::cout << "improvement green: " << improvement_green << std::endl;
	bestParameter_green.exportAsTXTfile(locationTest1, "bestPara_green", true);
	// best filteres image green
	Images::saveImageGray_UN8_normByROI_percent(locationTest1, "bestFilteredImage_green", "png", UM_BGR_parallel.getBestParameter_green().getImage(), UM_BGR_parallel.getInitialPara_green().getCompareInPercent());

	// best parameter red
	bestParameterStruct_unsharpMask bestParameter_red = UM_BGR_parallel.getBestParameter_red();
	real bestSigma_red = bestParameter_red.getSigma();
	real bestAmount_red = bestParameter_red.getAmount();
	real bestThreshold_red = bestParameter_red.getThreshold();
	real improvement_red = bestParameter_red.getImprovement();
	std::cout << "best sigma red: " << bestSigma_red << std::endl;
	std::cout << "best amount red: " << bestAmount_red << std::endl;
	std::cout << "best threshold red: " << bestThreshold_red << std::endl;
	std::cout << "improvement red: " << improvement_red << std::endl;
	bestParameter_red.exportAsTXTfile(locationTest1, "bestPara_red", true);
	// best filteres image red
	Images::saveImageGray_UN8_normByROI_percent(locationTest1, "bestFilteredImage_red", "png", UM_BGR_parallel.getBestParameter_red().getImage(), UM_BGR_parallel.getInitialPara_red().getCompareInPercent());

	// best filteres image
	Images::saveImageGray_UN8_normByROI_percent(locationTest1, "bestFilteredImage", "png", UM_BGR_parallel.getFilteredResults_normedLikeSharpIma(), UM_BGR_parallel.getInitialPara_red().getCompareInPercent());

	// *** check
	real deltaSigmaPercent = 1.0;
	real deltaAmountPercent = 1.0;
	real deltaThresholdPercent = 1.0;

	parameterUnsharpMasking paraUM_Test_blue;
	paraUM_Test_blue.setMinSigma((100 - deltaSigmaPercent) * bestSigma_blue / 100);
	paraUM_Test_blue.setMaxSigma((100 + deltaSigmaPercent) * bestSigma_blue / 100);
	paraUM_Test_blue.setStepsSigma(2.0);
	paraUM_Test_blue.setMinAmount((100 - deltaAmountPercent) * bestAmount_blue / 100);
	paraUM_Test_blue.setMaxAmount((100 + deltaAmountPercent) * bestAmount_blue / 100);
	paraUM_Test_blue.setStepsAmount(2.0);
	paraUM_Test_blue.setMinThreshold((100 - deltaThresholdPercent) * bestThreshold_blue / 100);
	paraUM_Test_blue.setMaxThreshold((100 + deltaThresholdPercent) * bestThreshold_blue / 100);
	paraUM_Test_blue.setStepsThreshold(2.0);
	paraUM_Test_blue.setBoarderType(cv::BORDER_DEFAULT);
	paraUM_Test_blue.setCompareInPercent(1.0);

	parameterUnsharpMasking paraUM_Test_green;
	paraUM_Test_green.setMinSigma((100 - deltaSigmaPercent) * bestSigma_green / 100);
	paraUM_Test_green.setMaxSigma((100 + deltaSigmaPercent) * bestSigma_green / 100);
	paraUM_Test_green.setStepsSigma(2.0);
	paraUM_Test_green.setMinAmount((100 - deltaAmountPercent) * bestAmount_green / 100);
	paraUM_Test_green.setMaxAmount((100 + deltaAmountPercent) * bestAmount_green / 100);
	paraUM_Test_green.setStepsAmount(2.0);
	paraUM_Test_green.setMinThreshold((100 - deltaThresholdPercent) * bestThreshold_green / 100);
	paraUM_Test_green.setMaxThreshold((100 + deltaThresholdPercent) * bestThreshold_green / 100);
	paraUM_Test_green.setStepsThreshold(2.0);
	paraUM_Test_green.setBoarderType(cv::BORDER_DEFAULT);
	paraUM_Test_green.setCompareInPercent(1.0);

	parameterUnsharpMasking paraUM_Test_red;
	paraUM_Test_red.setMinSigma((100 - deltaSigmaPercent) * bestSigma_red / 100);
	paraUM_Test_red.setMaxSigma((100 + deltaSigmaPercent) * bestSigma_red / 100);
	paraUM_Test_red.setStepsSigma(2.0);
	paraUM_Test_red.setMinAmount((100 - deltaAmountPercent) * bestAmount_red / 100);
	paraUM_Test_red.setMaxAmount((100 + deltaAmountPercent) * bestAmount_red / 100);
	paraUM_Test_red.setStepsAmount(2.0);
	paraUM_Test_red.setMinThreshold((100 - deltaThresholdPercent) * bestThreshold_red / 100);
	paraUM_Test_red.setMaxThreshold((100 + deltaThresholdPercent) * bestThreshold_red / 100);
	paraUM_Test_red.setStepsThreshold(2.0);
	paraUM_Test_red.setBoarderType(cv::BORDER_DEFAULT);
	paraUM_Test_red.setCompareInPercent(1.0);

	UnshaprMasking_singleCore_BGR UM_singleCore_BGR;
	UM_singleCore_BGR.setParameterUM_blue(paraUM_Test_blue);
	UM_singleCore_BGR.setParameterUM_green(paraUM_Test_green);
	UM_singleCore_BGR.setParameterUM_red(paraUM_Test_red);

	UM_singleCore_BGR.improveImaQual_UnsharpMasking_superFct_BGR(sharpIma_BGR, bluredIma_BGR);

	real improvement_Test_blue = UM_singleCore_BGR.getBestParameter_blue().getImprovement();
	real improvement_Test_green = UM_singleCore_BGR.getBestParameter_green().getImprovement();
	real improvement_Test_red = UM_singleCore_BGR.getBestParameter_red().getImprovement();

	real tolerance = 0.1;
	// test improvement _blue
	bool checkImpro_blue = Math::compareTwoNumbers_tolerance(improvement_Test_blue, improvement_blue, tolerance);
	workTheSystem.push_back(checkImpro_blue);
	// test improvement _green
	bool checkImpro_green = Math::compareTwoNumbers_tolerance(improvement_Test_green, improvement_green, tolerance);
	workTheSystem.push_back(checkImpro_green);
	// test improvement _red
	bool checkImpro_red = Math::compareTwoNumbers_tolerance(improvement_Test_red, improvement_red, tolerance);
	workTheSystem.push_back(checkImpro_red);

	bool workReturn = Math::checkTrueOfVectorElements(workTheSystem);
	return workReturn;
}



bool testImproveImageQuality::testDE_BFA_1()
{
	std::vector<bool> workTheSystem{};
	real tolerance = 0.1;
	// location
	std::string locationTest1 = "../tests/testImproveImageQuality/detailEnhancement/E1";
	// sharp image
	std::string locSharpIma_BGR = "../images/color/useThatImages/useThat/elefant_900x900.png";
	cv::Mat sharpIma_BGR = cv::imread(locSharpIma_BGR, CV_LOAD_IMAGE_COLOR);
	// bluered images
	std::string locBluredIma_BGR = "../images/color/useThatImages/useThat/simIma.png";
	cv::Mat bluredIma_BGR = cv::imread(locBluredIma_BGR, CV_LOAD_IMAGE_COLOR);

	parameterDetailEnhancement paraDE;
	paraDE.setMinSigma_r(0.001);
	paraDE.setMaxSigma_r(1.0);
	paraDE.setStepsSigma_r(200.0);
	paraDE.setMinSigma_s(1.0);
	paraDE.setMaxSigma_s(5.0);
	paraDE.setStepsSigma_s(200.0);
	paraDE.setPercentCompare(1.0);

	DetailEnhancement_BGR_parallel DE_BGR_parallel;
	DE_BGR_parallel.setParameter_global(paraDE);
	DE_BGR_parallel.improveImageQuality_DetailEnhancement_BGR_parallel(sharpIma_BGR, bluredIma_BGR);

	bestParameterStruct_detailEnhance bestParaDE = DE_BGR_parallel.getBestParameter();
	real bestSigma_r = bestParaDE.getSigmar_r();
	real bestSigma_s = bestParaDE.getSigmar_s();
	real improvement = bestParaDE.getImprovement();
	cv::Mat bestIma = bestParaDE.getImage();

	// // debug
	// std::cout << "best sigma r: " << bestSigma_r << std::endl;
	// std::cout << "best sigma s: " << bestSigma_s << std::endl;
	// std::cout << "improvement: " << improvement << std::endl;

	Images::saveImageGray_UN8_normByROI_percent(locationTest1, "bestFilteredIma", "png", bestIma, DE_BGR_parallel.getInitalParameter_global().getPercentCompare());

	// save best parameter
	bestParaDE.exportAsTXTfile(locationTest1, "bestParaE1", true);


	// test
	real deltaPercent = 1.0;
	parameterDetailEnhancement paraDE_test;
	paraDE_test.setMinSigma_r((100.0 - deltaPercent) * bestSigma_r / 100.0);
	paraDE_test.setMaxSigma_r((100.0 + deltaPercent) * bestSigma_r / 100.0);
	paraDE_test.setStepsSigma_r(3.0);
	paraDE_test.setMinSigma_s((100.0 - deltaPercent) * bestSigma_s / 100.0);
	paraDE_test.setMaxSigma_s((100.0 + deltaPercent) * bestSigma_s / 100.0);
	paraDE_test.setStepsSigma_s(3.0);
	paraDE_test.setPercentCompare(1.0);

	DetailEnhancement_BGR detailEnhance_test;
	detailEnhance_test.setInitialParameter(paraDE_test);
	detailEnhance_test.improveImageQuality_DetailEnhancement_BGR(sharpIma_BGR, bluredIma_BGR);

	bestParameterStruct_detailEnhance bestParaDE_test = detailEnhance_test.getBestParameter();
	real bestSigma_r_test = bestParaDE_test.getSigmar_r();
	real bestSigma_s_test = bestParaDE_test.getSigmar_s();
	real improvement_test = bestParaDE_test.getImprovement();
	cv::Mat bestIma_test = bestParaDE_test.getImage();

	// check improvement
	bool checkImprovement = Math::compareTwoNumbers_tolerance(improvement, improvement_test, tolerance);
	workTheSystem.push_back(checkImprovement);

	bool workReturn = Math::checkTrueOfVectorElements(workTheSystem);
	return workReturn;

}


// test improve image quality super function
// ***************************** 
bool testImproveImageQuality::checkImproverImaQuality_superFunc()
{
	std::vector<bool> workTheSystem{};

	//// test 0
	//bool checkTest0 = testImpImaQual_E0_WD24();
	//workTheSystem.push_back(checkTest0);
	//
	//// test 1
	//bool checkTest1 = testImpImaQual_E1_UnsMas24();
	//workTheSystem.push_back(checkTest1);
	
	//// test 2
	//bool  checkTest2 = testImpImaQual_E2_DetEnh24();
	//workTheSystem.push_back(checkTest2);
	//
	//// test3
	//bool checkTest3 = testImpQual_E3_RemChromAber();
	//workTheSystem.push_back(checkTest3);

	//// test 4
	//bool checkTest4 = testImaQual_E4_UnsMas_gray();
	//workTheSystem.push_back(checkTest4);

	// test 5
	bool checkTest5 = testImaQual_E5_Flower2_UnsMas_DetEnh_WD_24();
	workTheSystem.push_back(checkTest5);

	bool workReturn = Math::checkTrueOfVectorElements(workTheSystem);
	return workReturn;
}
// test 0
bool testImproveImageQuality::testImpImaQual_E0_WD24()
{
	std::string locationE0 = "../tests/testImproveImageQuality/improveImaQuality_superFct/E0";
	std::string loc_antelope = "../tests/testImproveImageQuality/improveImaQuality_superFct/E0/antelope";
	std::string loc_dragonfly = "../tests/testImproveImageQuality/improveImaQuality_superFct/E0/dragonfly";
	std::string loc_elefant = "../tests/testImproveImageQuality/improveImaQuality_superFct/E0/elefant";
	std::string loc_flower1 = "../tests/testImproveImageQuality/improveImaQuality_superFct/E0/flower1";
	std::string loc_flower2 = "../tests/testImproveImageQuality/improveImaQuality_superFct/E0/flower2";
	std::string loc_flower3 = "../tests/testImproveImageQuality/improveImaQuality_superFct/E0/flower3";
	std::string loc_landscape = "../tests/testImproveImageQuality/improveImaQuality_superFct/E0/landscape";
	std::string loc_pinguin = "../tests/testImproveImageQuality/improveImaQuality_superFct/E0/pinguin";
	std::string loc_rhino = "../tests/testImproveImageQuality/improveImaQuality_superFct/E0/rhino";
	std::string loc_salad = "../tests/testImproveImageQuality/improveImaQuality_superFct/E0/salad";

	// *** names objects *** // 
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

	// *** names filtered images *** //
	std::string filtered_antelope = "filtered_antelope";
	std::string second_filtered_antelope = "second_filtered_antelope";
	std::string filtered_dragonfly = "filtered_dragonfly";
	std::string second_filtered_dragonfly = "second_filtered_dragonfly";
	std::string filtered_elefant = "filtered_elefant";
	std::string second_filtered_elefant = "second_filtered_elefant";
	std::string filtered_flower1 = "filtered_flower1";
	std::string second_filtered_flower1 = "second_filtered_flower1";
	std::string filtered_flower2 = "filtered_flower2";
	std::string second_filtered_flower2 = "second_filtered_flower2";
	std::string filtered_flower3 = "filtered_flower3";
	std::string second_filtered_flower3 = "second_filtered_flower3";
	std::string filtered_landscape = "filtered_landscape";
	std::string second_filtered_landscape = "second_filtered_landscape";
	std::string filtered_pinguin = "filtered_pinguins";
	std::string second_filtered_pinguin = "second_filtered_pinguins";
	std::string filtered_rhino = "filtered_rhino";
	std::string second_filtered_rhino = "second_filtered_rhino";
	std::string filtered_salad = "filtered_salad";
	std::string second_filtered_salad = "second_filtered_salad";

	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_antelope = Images::loadAnImage_Color(loactionObject, antelope);
	cv::Mat object_dragonfly = Images::loadAnImage_Color(loactionObject, dragonfly);
	cv::Mat object_elefant = Images::loadAnImage_Color(loactionObject, elefant);
	cv::Mat object_flower1 = Images::loadAnImage_Color(loactionObject, flower1);
	cv::Mat object_flower2 = Images::loadAnImage_Color(loactionObject, flower2);
	cv::Mat object_flower3 = Images::loadAnImage_Color(loactionObject, flower3);
	cv::Mat object_landscape = Images::loadAnImage_Color(loactionObject, landscape);
	cv::Mat object_pinguin = Images::loadAnImage_Color(loactionObject, pinguin);
	cv::Mat object_rhino = Images::loadAnImage_Color(loactionObject, rhino);
	cv::Mat object_salad = Images::loadAnImage_Color(loactionObject, salad);

	// *** names simulated images *** //
	std::string locationImages = "../tests/testImageSimulation/S12";
	std::string simIma_antelope = "simIma_antelope";
	std::string simIma_dragonfly = "simIma_dragonfly";
	std::string simIma_elefant = "simIma_elefant";
	std::string simIma_flower1 = "simIma_flower1";
	std::string simIma_flower2 = "simIma_flower2";
	std::string simIma_flower3 = "simIma_flower3";
	std::string simIma_landscape = "simIma_landscape";
	std::string simIma_pinguin = "simIma_pinguin";
	std::string simIma_rhino = "simIma_rhino";
	std::string simIma_salad = "simIma_salad";

	// *** load simulated images *** //
	cv::Mat  simImaMat_antelope = Images::loadAnImage_Color(locationImages, simIma_antelope);
	cv::Mat  simImaMat_dragonfly = Images::loadAnImage_Color(locationImages, simIma_dragonfly);
	cv::Mat  simImaMat_elefant = Images::loadAnImage_Color(locationImages, simIma_elefant);
	cv::Mat  simImaMat_flower1 = Images::loadAnImage_Color(locationImages, simIma_flower1);
	cv::Mat  simImaMat_flower2 = Images::loadAnImage_Color(locationImages, simIma_flower2);
	cv::Mat  simImaMat_flower3 = Images::loadAnImage_Color(locationImages, simIma_flower3);
	cv::Mat  simImaMat_landscape = Images::loadAnImage_Color(locationImages, simIma_landscape);
	cv::Mat  simImaMat_pinguin = Images::loadAnImage_Color(locationImages, simIma_pinguin);
	cv::Mat  simImaMat_rhino = Images::loadAnImage_Color(locationImages, simIma_rhino);
	cv::Mat  simImaMat_salad = Images::loadAnImage_Color(locationImages, simIma_salad);

	// *** basic parameters
	imageProcessing methodeImaProc = imageProcessing::wienerFilter24;
	// *** parameter wiener filter *** 
	// *** parameter blue *** 
	parameterImaImprove_WD paraImaImproveWD_blue{};
	paraImaImproveWD_blue.setMinSNR(0.1);
	paraImaImproveWD_blue.setMaxSNR(200.0);
	//paraImaImproveWD_blue.setStepsSNR(200.0);
	paraImaImproveWD_blue.setStepsSNR(40.0);

	paraImaImproveWD_blue.setMinSigmaXY(0.1);
	paraImaImproveWD_blue.setMaxSigmaXY(5.0);
	//paraImaImproveWD_blue.setStepsSigmaXY(200.0);
	paraImaImproveWD_blue.setStepsSigmaXY(40.0);

	paraImaImproveWD_blue.setKernelSizeHeightAndWidth(30);
	paraImaImproveWD_blue.setCompareInPercent(0.0);
	// *** parameter green
	parameterImaImprove_WD paraImaImproveWD_green{};
	paraImaImproveWD_green = paraImaImproveWD_blue;
	// *** parameter red
	parameterImaImprove_WD paraImaImproveWD_red{};
	//  ***  *** //

	// *** *** //
	std::string stringToExport = "sigma_blue, SNR_blue, imp_blue, sigma_green, SNR_green, imp_green, sigma_red, SNR_red, imp_red, imp_total, bestCoreNum_blue, bestCoreNum_green, bestCoreNum_red";
	std::vector<std::vector<real>> vectoToExport_First{};
	std::vector<std::vector<real>> vectoToExport_Second{};
	// *** *** //

	// sharpness evaluation methodes
	std::vector<sharpnessEvalMethode> sharpEvalMethodes_vec{ sharpnessEvalMethode::sharpImage, sharpnessEvalMethode::Brenner, sharpnessEvalMethode::Tenengrad,
	sharpnessEvalMethode::Laplacian, sharpnessEvalMethode::SMD, sharpnessEvalMethode::SMD2, sharpnessEvalMethode::EnergyGradFct, sharpnessEvalMethode::EVA,
	sharpnessEvalMethode::NRSS, sharpnessEvalMethode::BlurAndNoise };
	//std::vector<sharpnessEvalMethode> sharpEvalMethodes_vec{ sharpnessEvalMethode::sharpImage, sharpnessEvalMethode::Brenner};
	// names of sharpness evaluation methodes
	std::vector<std::string> namesSharpEvalMeth_vec{ "sharpImage", "Brenner", "Tenengrad", "Laplacian", "SMD", "SMD2", "EnergyGradFct", "EVA", "NRSS", "BlurAndNoise" };
	//std::vector<std::string> namesSharpEvalMeth_vec{ "sharpImage", "Brenner"};
	real devideStepsByFactorForSecondSearch = 1.0;
	real reinitalizePercent = 20.0;
	std::string tempName;
	for (unsigned int i = 0; i < sharpEvalMethodes_vec.size(); ++i)
	{
		paraImaImproveWD_blue.setSharpnessEvalMethode(sharpEvalMethodes_vec[i]);
		paraImaImproveWD_green = paraImaImproveWD_blue;
		paraImaImproveWD_red = paraImaImproveWD_blue;

		ImaProcSuperFct imaProcessingSuperFunction;
		imaProcessingSuperFunction.setParameterWD_blue(paraImaImproveWD_blue);
		imaProcessingSuperFunction.setParameterWD_green(paraImaImproveWD_green);
		imaProcessingSuperFunction.setParameterWD_red(paraImaImproveWD_red);

		// *** antelope *** //
		std::cout << "improve antelope" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_antelope, simImaMat_antelope, methodeImaProc);
		cv::Mat filterdIma_antelope = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_antelope + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_antelope = loc_antelope + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_antelope, tempName, "png", filterdIma_antelope, paraImaImproveWD_blue.getCompareInPercent());

		saveBestParameterWD bestParaWD_blue_antelope = imaProcessingSuperFunction.getBestParaWD_blue();
		saveBestParameterWD bestParaWD_green_antelope = imaProcessingSuperFunction.getBestParaWD_green();
		saveBestParameterWD bestParaWD_red_antelope = imaProcessingSuperFunction.getBestParaWD_red();
		tempName = filtered_antelope + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		bestParaWD_blue_antelope.exportAsTXTfile(temp_loc_antelope, tempName, true);
		tempName = filtered_antelope + "_" + namesSharpEvalMeth_vec[i] + "_green";
		bestParaWD_green_antelope.exportAsTXTfile(temp_loc_antelope, tempName, true);
		tempName = filtered_antelope + "_" + namesSharpEvalMeth_vec[i] + "_red";
		bestParaWD_red_antelope.exportAsTXTfile(temp_loc_antelope, tempName, true);
		vectoToExport_First.push_back(collectParameterWD(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitializeBestParaWD(reinitalizePercent, paraImaImproveWD_blue.getStepsSNR() / devideStepsByFactorForSecondSearch, paraImaImproveWD_blue.getStepsSigmaXY() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_antelope, simImaMat_antelope, methodeImaProc);
		cv::Mat second_filterdIma_antelope = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_antelope + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_antelope, tempName, "png", second_filterdIma_antelope, paraImaImproveWD_blue.getCompareInPercent());

		saveBestParameterWD second_bestParaWD_blue_antelope = imaProcessingSuperFunction.getBestParaWD_blue();
		saveBestParameterWD second_bestParaWD_green_antelope = imaProcessingSuperFunction.getBestParaWD_green();
		saveBestParameterWD second_bestParaWD_red_antelope = imaProcessingSuperFunction.getBestParaWD_red();
		tempName = second_filtered_antelope + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		second_bestParaWD_blue_antelope.exportAsTXTfile(temp_loc_antelope, tempName, true);
		tempName = second_filtered_antelope + "_" + namesSharpEvalMeth_vec[i] + "_green";
		second_bestParaWD_green_antelope.exportAsTXTfile(temp_loc_antelope, tempName, true);
		tempName = second_filtered_antelope + "_" + namesSharpEvalMeth_vec[i] + "_red";
		second_bestParaWD_red_antelope.exportAsTXTfile(temp_loc_antelope, tempName, true);

		vectoToExport_Second.push_back(collectParameterWD(imaProcessingSuperFunction));
		// *** *** //

		// *** dragonfly *** //
		std::cout << "improve dragonfly" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_dragonfly, simImaMat_dragonfly, methodeImaProc);
		cv::Mat filterdIma_dragonfly = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_dragonfly = loc_dragonfly + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_dragonfly, tempName, "png", filterdIma_dragonfly, paraImaImproveWD_blue.getCompareInPercent());

		saveBestParameterWD bestParaWD_blue_dragonfly = imaProcessingSuperFunction.getBestParaWD_blue();
		saveBestParameterWD bestParaWD_green_dragonfly = imaProcessingSuperFunction.getBestParaWD_green();
		saveBestParameterWD bestParaWD_red_dragonfly = imaProcessingSuperFunction.getBestParaWD_red();
		tempName = filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		bestParaWD_blue_dragonfly.exportAsTXTfile(temp_loc_dragonfly, tempName, true);
		tempName = filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i] + "_green";
		bestParaWD_green_dragonfly.exportAsTXTfile(temp_loc_dragonfly, tempName, true);
		tempName = filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i] + "_red";
		bestParaWD_red_dragonfly.exportAsTXTfile(temp_loc_dragonfly, tempName, true);
		vectoToExport_First.push_back(collectParameterWD(imaProcessingSuperFunction));

		imaProcessingSuperFunction.reinitializeBestParaWD(reinitalizePercent, paraImaImproveWD_blue.getStepsSNR() / devideStepsByFactorForSecondSearch, paraImaImproveWD_blue.getStepsSigmaXY() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_dragonfly, simImaMat_dragonfly, methodeImaProc);
		cv::Mat second_filterdIma_dragonfly = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_dragonfly, tempName, "png", second_filterdIma_dragonfly, paraImaImproveWD_blue.getCompareInPercent());

		saveBestParameterWD second_bestParaWD_blue_dragonfly = imaProcessingSuperFunction.getBestParaWD_blue();
		saveBestParameterWD second_bestParaWD_green_dragonfly = imaProcessingSuperFunction.getBestParaWD_green();
		saveBestParameterWD second_bestParaWD_red_dragonfly = imaProcessingSuperFunction.getBestParaWD_red();
		tempName = second_filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		second_bestParaWD_blue_dragonfly.exportAsTXTfile(temp_loc_dragonfly, tempName, true);
		tempName = second_filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i] + "_green";
		second_bestParaWD_green_dragonfly.exportAsTXTfile(temp_loc_dragonfly, tempName, true);
		tempName = second_filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i] + "_red";
		second_bestParaWD_red_dragonfly.exportAsTXTfile(temp_loc_dragonfly, tempName, true);

		vectoToExport_Second.push_back(collectParameterWD(imaProcessingSuperFunction));
		// *** *** //

		// *** elefant *** //
		std::cout << "improve elefant" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant, methodeImaProc);
		cv::Mat filterdIma_elefant = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_elefant + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_elefant = loc_elefant + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_elefant, tempName, "png", filterdIma_elefant, paraImaImproveWD_blue.getCompareInPercent());

		saveBestParameterWD bestParaWD_blue_elefant = imaProcessingSuperFunction.getBestParaWD_blue();
		saveBestParameterWD bestParaWD_green_elefant = imaProcessingSuperFunction.getBestParaWD_green();
		saveBestParameterWD bestParaWD_red_elefant = imaProcessingSuperFunction.getBestParaWD_red();
		tempName = filtered_elefant + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		bestParaWD_blue_elefant.exportAsTXTfile(temp_loc_elefant, tempName, true);
		tempName = filtered_elefant + "_" + namesSharpEvalMeth_vec[i] + "_green";
		bestParaWD_green_elefant.exportAsTXTfile(temp_loc_elefant, tempName, true);
		tempName = filtered_elefant + "_" + namesSharpEvalMeth_vec[i] + "_red";
		bestParaWD_red_elefant.exportAsTXTfile(temp_loc_elefant, tempName, true);
		vectoToExport_First.push_back(collectParameterWD(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitializeBestParaWD(reinitalizePercent, paraImaImproveWD_blue.getStepsSNR() / devideStepsByFactorForSecondSearch, paraImaImproveWD_blue.getStepsSigmaXY() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant, methodeImaProc);
		cv::Mat second_filterdIma_elefant = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_elefant + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_elefant, tempName, "png", second_filterdIma_elefant, paraImaImproveWD_blue.getCompareInPercent());

		saveBestParameterWD second_bestParaWD_blue_elefant = imaProcessingSuperFunction.getBestParaWD_blue();
		saveBestParameterWD second_bestParaWD_green_elefant = imaProcessingSuperFunction.getBestParaWD_green();
		saveBestParameterWD second_bestParaWD_red_elefant = imaProcessingSuperFunction.getBestParaWD_red();
		tempName = second_filtered_elefant + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		second_bestParaWD_blue_elefant.exportAsTXTfile(temp_loc_elefant, tempName, true);
		tempName = second_filtered_elefant + "_" + namesSharpEvalMeth_vec[i] + "_green";
		second_bestParaWD_green_elefant.exportAsTXTfile(temp_loc_elefant, tempName, true);
		tempName = second_filtered_elefant + "_" + namesSharpEvalMeth_vec[i] + "_red";
		second_bestParaWD_red_elefant.exportAsTXTfile(temp_loc_elefant, tempName, true);

		vectoToExport_Second.push_back(collectParameterWD(imaProcessingSuperFunction));
		// *** *** //

		// *** flower1 *** //
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower1, simImaMat_flower1, methodeImaProc);
		cv::Mat filterdIma_flower1 = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_flower1 + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_flower1 = loc_flower1 + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower1, tempName, "png", filterdIma_flower1, paraImaImproveWD_blue.getCompareInPercent());

		saveBestParameterWD bestParaWD_blue_flower1 = imaProcessingSuperFunction.getBestParaWD_blue();
		saveBestParameterWD bestParaWD_green_flower1 = imaProcessingSuperFunction.getBestParaWD_green();
		saveBestParameterWD bestParaWD_red_flower1 = imaProcessingSuperFunction.getBestParaWD_red();
		tempName = filtered_flower1 + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		bestParaWD_blue_flower1.exportAsTXTfile(temp_loc_flower1, tempName, true);
		tempName = filtered_flower1 + "_" + namesSharpEvalMeth_vec[i] + "_green";
		bestParaWD_green_flower1.exportAsTXTfile(temp_loc_flower1, tempName, true);
		tempName = filtered_flower1 + "_" + namesSharpEvalMeth_vec[i] + "_red";
		bestParaWD_red_flower1.exportAsTXTfile(temp_loc_flower1, tempName, true);
		vectoToExport_First.push_back(collectParameterWD(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitializeBestParaWD(reinitalizePercent, paraImaImproveWD_blue.getStepsSNR() / devideStepsByFactorForSecondSearch, paraImaImproveWD_blue.getStepsSigmaXY() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower1, simImaMat_flower1, methodeImaProc);
		cv::Mat second_filterdIma_flower1 = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_flower1 + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower1, tempName, "png", second_filterdIma_flower1, paraImaImproveWD_blue.getCompareInPercent());

		saveBestParameterWD second_bestParaWD_blue_flower1 = imaProcessingSuperFunction.getBestParaWD_blue();
		saveBestParameterWD second_bestParaWD_green_flower1 = imaProcessingSuperFunction.getBestParaWD_green();
		saveBestParameterWD second_bestParaWD_red_flower1 = imaProcessingSuperFunction.getBestParaWD_red();
		tempName = second_filtered_flower1 + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		second_bestParaWD_blue_flower1.exportAsTXTfile(temp_loc_flower1, tempName, true);
		tempName = second_filtered_flower1 + "_" + namesSharpEvalMeth_vec[i] + "_green";
		second_bestParaWD_green_flower1.exportAsTXTfile(temp_loc_flower1, tempName, true);
		tempName = second_filtered_flower1 + "_" + namesSharpEvalMeth_vec[i] + "_red";
		second_bestParaWD_red_flower1.exportAsTXTfile(temp_loc_flower1, tempName, true);

		vectoToExport_Second.push_back(collectParameterWD(imaProcessingSuperFunction));
		// *** *** //

		// *** flower2 *** //
		std::cout << "improve flower2" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower2, simImaMat_flower2, methodeImaProc);
		cv::Mat filterdIma_flower2 = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_flower2 + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_flower2 = loc_flower2 + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower2, tempName, "png", filterdIma_flower2, paraImaImproveWD_blue.getCompareInPercent());

		saveBestParameterWD bestParaWD_blue_flower2 = imaProcessingSuperFunction.getBestParaWD_blue();
		saveBestParameterWD bestParaWD_green_flower2 = imaProcessingSuperFunction.getBestParaWD_green();
		saveBestParameterWD bestParaWD_red_flower2 = imaProcessingSuperFunction.getBestParaWD_red();
		tempName = filtered_flower2 + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		bestParaWD_blue_flower2.exportAsTXTfile(temp_loc_flower2, tempName, true);
		tempName = filtered_flower2 + "_" + namesSharpEvalMeth_vec[i] + "_green";
		bestParaWD_green_flower2.exportAsTXTfile(temp_loc_flower2, tempName, true);
		tempName = filtered_flower2 + "_" + namesSharpEvalMeth_vec[i] + "_red";
		bestParaWD_red_flower2.exportAsTXTfile(temp_loc_flower2, tempName, true);
		vectoToExport_First.push_back(collectParameterWD(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitializeBestParaWD(reinitalizePercent, paraImaImproveWD_blue.getStepsSNR() / devideStepsByFactorForSecondSearch, paraImaImproveWD_blue.getStepsSigmaXY() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower2, simImaMat_flower2, methodeImaProc);
		cv::Mat second_filterdIma_flower2 = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_flower2 + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower2, tempName, "png", second_filterdIma_flower2, paraImaImproveWD_blue.getCompareInPercent());

		saveBestParameterWD second_bestParaWD_blue_flower2 = imaProcessingSuperFunction.getBestParaWD_blue();
		saveBestParameterWD second_bestParaWD_green_flower2 = imaProcessingSuperFunction.getBestParaWD_green();
		saveBestParameterWD second_bestParaWD_red_flower2 = imaProcessingSuperFunction.getBestParaWD_red();
		tempName = second_filtered_flower2 + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		second_bestParaWD_blue_flower2.exportAsTXTfile(temp_loc_flower2, tempName, true);
		tempName = second_filtered_flower2 + "_" + namesSharpEvalMeth_vec[i] + "_green";
		second_bestParaWD_green_flower2.exportAsTXTfile(temp_loc_flower2, tempName, true);
		tempName = second_filtered_flower2 + "_" + namesSharpEvalMeth_vec[i] + "_red";
		second_bestParaWD_red_flower2.exportAsTXTfile(temp_loc_flower2, tempName, true);

		vectoToExport_Second.push_back(collectParameterWD(imaProcessingSuperFunction));
		// *** *** //

		// *** flower3 *** //
		std::cout << "improve flower3" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower3, simImaMat_flower3, methodeImaProc);
		cv::Mat filterdIma_flower3 = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_flower3 + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_flower3 = loc_flower3 + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower3, tempName, "png", filterdIma_flower3, paraImaImproveWD_blue.getCompareInPercent());

		saveBestParameterWD bestParaWD_blue_flower3 = imaProcessingSuperFunction.getBestParaWD_blue();
		saveBestParameterWD bestParaWD_green_flower3 = imaProcessingSuperFunction.getBestParaWD_green();
		saveBestParameterWD bestParaWD_red_flower3 = imaProcessingSuperFunction.getBestParaWD_red();
		tempName = filtered_flower3 + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		bestParaWD_blue_flower3.exportAsTXTfile(temp_loc_flower3, tempName, true);
		tempName = filtered_flower3 + "_" + namesSharpEvalMeth_vec[i] + "_green";
		bestParaWD_green_flower3.exportAsTXTfile(temp_loc_flower3, tempName, true);
		tempName = filtered_flower3 + "_" + namesSharpEvalMeth_vec[i] + "_red";
		bestParaWD_red_flower3.exportAsTXTfile(temp_loc_flower3, tempName, true);
		vectoToExport_First.push_back(collectParameterWD(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitializeBestParaWD(reinitalizePercent, paraImaImproveWD_blue.getStepsSNR() / devideStepsByFactorForSecondSearch, paraImaImproveWD_blue.getStepsSigmaXY() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower3, simImaMat_flower3, methodeImaProc);
		cv::Mat second_filterdIma_flower3 = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_flower3 + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower3, tempName, "png", second_filterdIma_flower3, paraImaImproveWD_blue.getCompareInPercent());

		saveBestParameterWD second_bestParaWD_blue_flower3 = imaProcessingSuperFunction.getBestParaWD_blue();
		saveBestParameterWD second_bestParaWD_green_flower3 = imaProcessingSuperFunction.getBestParaWD_green();
		saveBestParameterWD second_bestParaWD_red_flower3 = imaProcessingSuperFunction.getBestParaWD_red();
		tempName = second_filtered_flower3 + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		second_bestParaWD_blue_flower3.exportAsTXTfile(temp_loc_flower3, tempName, true);
		tempName = second_filtered_flower3 + "_" + namesSharpEvalMeth_vec[i] + "_green";
		second_bestParaWD_green_flower3.exportAsTXTfile(temp_loc_flower3, tempName, true);
		tempName = second_filtered_flower3 + "_" + namesSharpEvalMeth_vec[i] + "_red";
		second_bestParaWD_red_flower3.exportAsTXTfile(temp_loc_flower3, tempName, true);

		vectoToExport_Second.push_back(collectParameterWD(imaProcessingSuperFunction));
		// *** *** //

		// *** landscape *** //
		std::cout << "improve landscape" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_landscape, simImaMat_landscape, methodeImaProc);
		cv::Mat filterdIma_landscape = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_landscape + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_landscape = loc_landscape + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_landscape, tempName, "png", filterdIma_landscape, paraImaImproveWD_blue.getCompareInPercent());

		saveBestParameterWD bestParaWD_blue_landscape = imaProcessingSuperFunction.getBestParaWD_blue();
		saveBestParameterWD bestParaWD_green_landscape = imaProcessingSuperFunction.getBestParaWD_green();
		saveBestParameterWD bestParaWD_red_landscape = imaProcessingSuperFunction.getBestParaWD_red();
		tempName = filtered_landscape + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		bestParaWD_blue_landscape.exportAsTXTfile(temp_loc_landscape, tempName, true);
		tempName = filtered_landscape + "_" + namesSharpEvalMeth_vec[i] + "_green";
		bestParaWD_green_landscape.exportAsTXTfile(temp_loc_landscape, tempName, true);
		tempName = filtered_landscape + "_" + namesSharpEvalMeth_vec[i] + "_red";
		bestParaWD_red_landscape.exportAsTXTfile(temp_loc_landscape, tempName, true);
		vectoToExport_First.push_back(collectParameterWD(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitializeBestParaWD(reinitalizePercent, paraImaImproveWD_blue.getStepsSNR() / devideStepsByFactorForSecondSearch, paraImaImproveWD_blue.getStepsSigmaXY() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_landscape, simImaMat_landscape, methodeImaProc);
		cv::Mat second_filterdIma_landscape = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_landscape + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_landscape, tempName, "png", second_filterdIma_landscape, paraImaImproveWD_blue.getCompareInPercent());

		saveBestParameterWD second_bestParaWD_blue_landscape = imaProcessingSuperFunction.getBestParaWD_blue();
		saveBestParameterWD second_bestParaWD_green_landscape = imaProcessingSuperFunction.getBestParaWD_green();
		saveBestParameterWD second_bestParaWD_red_landscape = imaProcessingSuperFunction.getBestParaWD_red();
		tempName = second_filtered_landscape + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		second_bestParaWD_blue_landscape.exportAsTXTfile(temp_loc_landscape, tempName, true);
		tempName = second_filtered_landscape + "_" + namesSharpEvalMeth_vec[i] + "_green";
		second_bestParaWD_green_landscape.exportAsTXTfile(temp_loc_landscape, tempName, true);
		tempName = second_filtered_landscape + "_" + namesSharpEvalMeth_vec[i] + "_red";
		second_bestParaWD_red_landscape.exportAsTXTfile(temp_loc_landscape, tempName, true);

		vectoToExport_Second.push_back(collectParameterWD(imaProcessingSuperFunction));
		// *** *** //

		// *** pinguin *** //
		std::cout << "improve pinguion" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_pinguin, simImaMat_pinguin, methodeImaProc);
		cv::Mat filterdIma_pinguin = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_pinguin + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_pinguin = loc_pinguin + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_pinguin, tempName, "png", filterdIma_pinguin, paraImaImproveWD_blue.getCompareInPercent());

		saveBestParameterWD bestParaWD_blue_pinguin = imaProcessingSuperFunction.getBestParaWD_blue();
		saveBestParameterWD bestParaWD_green_pinguin = imaProcessingSuperFunction.getBestParaWD_green();
		saveBestParameterWD bestParaWD_red_pinguin = imaProcessingSuperFunction.getBestParaWD_red();
		tempName = filtered_pinguin + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		bestParaWD_blue_pinguin.exportAsTXTfile(temp_loc_pinguin, tempName, true);
		tempName = filtered_pinguin + "_" + namesSharpEvalMeth_vec[i] + "_green";
		bestParaWD_green_pinguin.exportAsTXTfile(temp_loc_pinguin, tempName, true);
		tempName = filtered_pinguin + "_" + namesSharpEvalMeth_vec[i] + "_red";
		bestParaWD_red_pinguin.exportAsTXTfile(temp_loc_pinguin, tempName, true);
		vectoToExport_First.push_back(collectParameterWD(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitializeBestParaWD(reinitalizePercent, paraImaImproveWD_blue.getStepsSNR() / devideStepsByFactorForSecondSearch, paraImaImproveWD_blue.getStepsSigmaXY() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_pinguin, simImaMat_pinguin, methodeImaProc);
		cv::Mat second_filterdIma_pinguin = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_pinguin + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_pinguin, tempName, "png", second_filterdIma_pinguin, paraImaImproveWD_blue.getCompareInPercent());

		saveBestParameterWD second_bestParaWD_blue_pinguin = imaProcessingSuperFunction.getBestParaWD_blue();
		saveBestParameterWD second_bestParaWD_green_pinguin = imaProcessingSuperFunction.getBestParaWD_green();
		saveBestParameterWD second_bestParaWD_red_pinguin = imaProcessingSuperFunction.getBestParaWD_red();
		tempName = second_filtered_pinguin + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		second_bestParaWD_blue_pinguin.exportAsTXTfile(temp_loc_pinguin, tempName, true);
		tempName = second_filtered_pinguin + "_" + namesSharpEvalMeth_vec[i] + "_green";
		second_bestParaWD_green_pinguin.exportAsTXTfile(temp_loc_pinguin, tempName, true);
		tempName = second_filtered_pinguin + "_" + namesSharpEvalMeth_vec[i] + "_red";
		second_bestParaWD_red_pinguin.exportAsTXTfile(temp_loc_pinguin, tempName, true);

		vectoToExport_Second.push_back(collectParameterWD(imaProcessingSuperFunction));
		// *** *** //

		// *** rhino *** //
		std::cout << "improve rhino" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_rhino, simImaMat_rhino, methodeImaProc);
		cv::Mat filterdIma_rhino = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_rhino + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_rhino = loc_rhino + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_rhino, tempName, "png", filterdIma_rhino, paraImaImproveWD_blue.getCompareInPercent());

		saveBestParameterWD bestParaWD_blue_rhino = imaProcessingSuperFunction.getBestParaWD_blue();
		saveBestParameterWD bestParaWD_green_rhino = imaProcessingSuperFunction.getBestParaWD_green();
		saveBestParameterWD bestParaWD_red_rhino = imaProcessingSuperFunction.getBestParaWD_red();
		tempName = filtered_rhino + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		bestParaWD_blue_rhino.exportAsTXTfile(temp_loc_rhino, tempName, true);
		tempName = filtered_rhino + "_" + namesSharpEvalMeth_vec[i] + "_green";
		bestParaWD_green_rhino.exportAsTXTfile(temp_loc_rhino, tempName, true);
		tempName = filtered_rhino + "_" + namesSharpEvalMeth_vec[i] + "_red";
		bestParaWD_red_rhino.exportAsTXTfile(temp_loc_rhino, tempName, true);
		vectoToExport_First.push_back(collectParameterWD(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitializeBestParaWD(reinitalizePercent, paraImaImproveWD_blue.getStepsSNR() / devideStepsByFactorForSecondSearch, paraImaImproveWD_blue.getStepsSigmaXY() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_rhino, simImaMat_rhino, methodeImaProc);
		cv::Mat second_filterdIma_rhino = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_rhino + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_rhino, tempName, "png", second_filterdIma_rhino, paraImaImproveWD_blue.getCompareInPercent());

		saveBestParameterWD second_bestParaWD_blue_rhino = imaProcessingSuperFunction.getBestParaWD_blue();
		saveBestParameterWD second_bestParaWD_green_rhino = imaProcessingSuperFunction.getBestParaWD_green();
		saveBestParameterWD second_bestParaWD_red_rhino = imaProcessingSuperFunction.getBestParaWD_red();
		tempName = second_filtered_rhino + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		second_bestParaWD_blue_rhino.exportAsTXTfile(temp_loc_rhino, tempName, true);
		tempName = second_filtered_rhino + "_" + namesSharpEvalMeth_vec[i] + "_green";
		second_bestParaWD_green_rhino.exportAsTXTfile(temp_loc_rhino, tempName, true);
		tempName = second_filtered_rhino + "_" + namesSharpEvalMeth_vec[i] + "_red";
		second_bestParaWD_red_rhino.exportAsTXTfile(temp_loc_rhino, tempName, true);

		vectoToExport_Second.push_back(collectParameterWD(imaProcessingSuperFunction));
		// *** *** //

		// *** salad *** //
		std::cout << "improve salad" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_salad, simImaMat_salad, methodeImaProc);
		cv::Mat filterdIma_salad = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_salad + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_salad = loc_salad + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_salad, tempName, "png", filterdIma_salad, paraImaImproveWD_blue.getCompareInPercent());

		saveBestParameterWD bestParaWD_blue_salad = imaProcessingSuperFunction.getBestParaWD_blue();
		saveBestParameterWD bestParaWD_green_salad = imaProcessingSuperFunction.getBestParaWD_green();
		saveBestParameterWD bestParaWD_red_salad = imaProcessingSuperFunction.getBestParaWD_red();
		tempName = filtered_salad + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		bestParaWD_blue_salad.exportAsTXTfile(temp_loc_salad, tempName, true);
		tempName = filtered_salad + "_" + namesSharpEvalMeth_vec[i] + "_green";
		bestParaWD_green_salad.exportAsTXTfile(temp_loc_salad, tempName, true);
		tempName = filtered_salad + "_" + namesSharpEvalMeth_vec[i] + "_red";
		bestParaWD_red_salad.exportAsTXTfile(temp_loc_salad, tempName, true);
		vectoToExport_First.push_back(collectParameterWD(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitializeBestParaWD(reinitalizePercent, paraImaImproveWD_blue.getStepsSNR() / devideStepsByFactorForSecondSearch, paraImaImproveWD_blue.getStepsSigmaXY() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_salad, simImaMat_salad, methodeImaProc);
		cv::Mat second_filterdIma_salad = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_salad + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_salad, tempName, "png", second_filterdIma_salad, paraImaImproveWD_blue.getCompareInPercent());

		saveBestParameterWD second_bestParaWD_blue_salad = imaProcessingSuperFunction.getBestParaWD_blue();
		saveBestParameterWD second_bestParaWD_green_salad = imaProcessingSuperFunction.getBestParaWD_green();
		saveBestParameterWD second_bestParaWD_red_salad = imaProcessingSuperFunction.getBestParaWD_red();
		tempName = second_filtered_salad + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		second_bestParaWD_blue_salad.exportAsTXTfile(temp_loc_salad, tempName, true);
		tempName = second_filtered_salad + "_" + namesSharpEvalMeth_vec[i] + "_green";
		second_bestParaWD_green_salad.exportAsTXTfile(temp_loc_salad, tempName, true);
		tempName = second_filtered_salad + "_" + namesSharpEvalMeth_vec[i] + "_red";
		second_bestParaWD_red_salad.exportAsTXTfile(temp_loc_salad, tempName, true);

		vectoToExport_Second.push_back(collectParameterWD(imaProcessingSuperFunction));
		// *** *** //
	}

	// *** *** //
	// first interation
	std::string firstIteration = "allData_FirstInteration_WD24_ImpImaQualSupFct_E0";
	// ***
	inportExportData::removeDateCSV(locationE0, firstIteration);
	// ***
	unsigned int numberDatas = vectoToExport_First.size();
	unsigned int numberShaprEvalMeth = namesSharpEvalMeth_vec.size();
	unsigned int numberImages = numberDatas / numberShaprEvalMeth;
	// ***
	// export all data to csv
	// first iteration
	unsigned int tempPos_firstIteration = 0;
	for (unsigned int i = 0; i < numberShaprEvalMeth; ++i)
	{
		inportExportData::exportDataToExcel(locationE0, firstIteration, namesSharpEvalMeth_vec[i], 0.0);
		for (unsigned int k = 0; k < numberImages; ++k)
		{
			inportExportData::exportDataToExcel_vector(locationE0, firstIteration, stringToExport, vectoToExport_First[tempPos_firstIteration]);
			++tempPos_firstIteration;
		}

	}
	// *** *** //


	// *** *** //
	// second interation
	std::string secondIteration = "allData_SecondInteration_WD24_ImpImaQualSupFct_E0";
	// ***
	inportExportData::removeDateCSV(locationE0, secondIteration);
	// ***
	// export all data to csv
	unsigned int tempPos_secondIteration = 0;
	for (unsigned int i = 0; i < numberShaprEvalMeth; ++i)
	{
		inportExportData::exportDataToExcel(locationE0, secondIteration, namesSharpEvalMeth_vec[i], 0.0);
		for (unsigned int k = 0; k < numberImages; ++k)
		{
			inportExportData::exportDataToExcel_vector(locationE0, secondIteration, stringToExport, vectoToExport_Second[tempPos_secondIteration]);
			++tempPos_secondIteration;
		}

	}
	// *** *** //
	bool checker = vectoToExport_First.size() == vectoToExport_Second.size();
	// *** *** //
	return checker;
}
// ***************************** 

// test 1 
bool testImproveImageQuality::testImpImaQual_E1_UnsMas24()
{
	std::string locationE1 = "../tests/testImproveImageQuality/improveImaQuality_superFct/E1";
	std::string loc_antelope = "../tests/testImproveImageQuality/improveImaQuality_superFct/E1/antelope";
	std::string loc_dragonfly = "../tests/testImproveImageQuality/improveImaQuality_superFct/E1/dragonfly";
	std::string loc_elefant = "../tests/testImproveImageQuality/improveImaQuality_superFct/E1/elefant";
	std::string loc_flower1 = "../tests/testImproveImageQuality/improveImaQuality_superFct/E1/flower1";
	std::string loc_flower2 = "../tests/testImproveImageQuality/improveImaQuality_superFct/E1/flower2";
	std::string loc_flower3 = "../tests/testImproveImageQuality/improveImaQuality_superFct/E1/flower3";
	std::string loc_landscape = "../tests/testImproveImageQuality/improveImaQuality_superFct/E1/landscape";
	std::string loc_pinguin = "../tests/testImproveImageQuality/improveImaQuality_superFct/E1/pinguin";
	std::string loc_rhino = "../tests/testImproveImageQuality/improveImaQuality_superFct/E1/rhino";
	std::string loc_salad = "../tests/testImproveImageQuality/improveImaQuality_superFct/E1/salad";

	// *** names objects *** // 
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

	// *** names filtered images *** //
	std::string filtered_antelope = "filtered_antelope";
	std::string second_filtered_antelope = "second_filtered_antelope";
	std::string filtered_dragonfly = "filtered_dragonfly";
	std::string second_filtered_dragonfly = "second_filtered_dragonfly";
	std::string filtered_elefant = "filtered_elefant";
	std::string second_filtered_elefant = "second_filtered_elefant";
	std::string filtered_flower1 = "filtered_flower1";
	std::string second_filtered_flower1 = "second_filtered_flower1";
	std::string filtered_flower2 = "filtered_flower2";
	std::string second_filtered_flower2 = "second_filtered_flower2";
	std::string filtered_flower3 = "filtered_flower3";
	std::string second_filtered_flower3 = "second_filtered_flower3";
	std::string filtered_landscape = "filtered_landscape";
	std::string second_filtered_landscape = "second_filtered_landscape";
	std::string filtered_pinguin = "filtered_pinguins";
	std::string second_filtered_pinguin = "second_filtered_pinguins";
	std::string filtered_rhino = "filtered_rhino";
	std::string second_filtered_rhino = "second_filtered_rhino";
	std::string filtered_salad = "filtered_salad";
	std::string second_filtered_salad = "second_filtered_salad";

	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_antelope = Images::loadAnImage_Color(loactionObject, antelope);
	cv::Mat object_dragonfly = Images::loadAnImage_Color(loactionObject, dragonfly);
	cv::Mat object_elefant = Images::loadAnImage_Color(loactionObject, elefant);
	cv::Mat object_flower1 = Images::loadAnImage_Color(loactionObject, flower1);
	cv::Mat object_flower2 = Images::loadAnImage_Color(loactionObject, flower2);
	cv::Mat object_flower3 = Images::loadAnImage_Color(loactionObject, flower3);
	cv::Mat object_landscape = Images::loadAnImage_Color(loactionObject, landscape);
	cv::Mat object_pinguin = Images::loadAnImage_Color(loactionObject, pinguin);
	cv::Mat object_rhino = Images::loadAnImage_Color(loactionObject, rhino);
	cv::Mat object_salad = Images::loadAnImage_Color(loactionObject, salad);

	// *** names simulated images *** //
	std::string locationImages = "../tests/testImageSimulation/S12";
	std::string simIma_antelope = "simIma_antelope";
	std::string simIma_dragonfly = "simIma_dragonfly";
	std::string simIma_elefant = "simIma_elefant";
	std::string simIma_flower1 = "simIma_flower1";
	std::string simIma_flower2 = "simIma_flower2";
	std::string simIma_flower3 = "simIma_flower3";
	std::string simIma_landscape = "simIma_landscape";
	std::string simIma_pinguin = "simIma_pinguin";
	std::string simIma_rhino = "simIma_rhino";
	std::string simIma_salad = "simIma_salad";

	// *** load simulated images *** //
	cv::Mat  simImaMat_antelope = Images::loadAnImage_Color(locationImages, simIma_antelope);
	cv::Mat  simImaMat_dragonfly = Images::loadAnImage_Color(locationImages, simIma_dragonfly);
	cv::Mat  simImaMat_elefant = Images::loadAnImage_Color(locationImages, simIma_elefant);
	cv::Mat  simImaMat_flower1 = Images::loadAnImage_Color(locationImages, simIma_flower1);
	cv::Mat  simImaMat_flower2 = Images::loadAnImage_Color(locationImages, simIma_flower2);
	cv::Mat  simImaMat_flower3 = Images::loadAnImage_Color(locationImages, simIma_flower3);
	cv::Mat  simImaMat_landscape = Images::loadAnImage_Color(locationImages, simIma_landscape);
	cv::Mat  simImaMat_pinguin = Images::loadAnImage_Color(locationImages, simIma_pinguin);
	cv::Mat  simImaMat_rhino = Images::loadAnImage_Color(locationImages, simIma_rhino);
	cv::Mat  simImaMat_salad = Images::loadAnImage_Color(locationImages, simIma_salad);

	// *** parameter unsharp masking ***///
	imageProcessing methodeImaProc = imageProcessing::unsharpMasking24;
	// blue
	parameterUnsharpMasking paraUM_blue;
	paraUM_blue.setMinSigma(0.1);
	paraUM_blue.setMaxSigma(20.0);
	paraUM_blue.setStepsSigma(100.0);
	//paraUM_blue.setStepsSigma(10.0);

	paraUM_blue.setMinThreshold(0.01);
	paraUM_blue.setMaxThreshold(5.0);
	paraUM_blue.setStepsThreshold(100.0);
	//paraUM_blue.setStepsThreshold(10.0);

	paraUM_blue.setMinAmount(0.01);
	paraUM_blue.setMaxAmount(10.0);
	paraUM_blue.setStepsAmount(100.0);
	//paraUM_blue.setStepsAmount(10.0);

	paraUM_blue.setBoarderType(cv::BORDER_DEFAULT);
	paraUM_blue.setCompareInPercent(0.0);
	// green
	parameterUnsharpMasking paraUM_green = paraUM_blue;
	// red
	parameterUnsharpMasking paraUM_red = paraUM_blue;
	// ***
	

	// *** *** //
	std::string stringToExport = "sigma_blue, threshold_blue, amount_blue, imp_blue, sigma_green, threshold_green, amount_green, imp_green, sigma_red, threshold_red, amount_red, imp_red, imp_total, bestCoreNumber_blue, bestCoreNumber_green, bestCoreNumber_red";
	std::vector<std::vector<real>> vectoToExport_first{};
	std::vector<std::vector<real>> vectoToExport_second{};

	// *** *** //

	// sharpness evaluation methodes
	std::vector<sharpnessEvalMethode> sharpEvalMethodes_vec{ sharpnessEvalMethode::sharpImage, sharpnessEvalMethode::Brenner, sharpnessEvalMethode::Tenengrad,
	sharpnessEvalMethode::Laplacian, sharpnessEvalMethode::SMD, sharpnessEvalMethode::SMD2, sharpnessEvalMethode::EnergyGradFct, sharpnessEvalMethode::EVA,
	sharpnessEvalMethode::NRSS, sharpnessEvalMethode::BlurAndNoise };
	//std::vector<sharpnessEvalMethode> sharpEvalMethodes_vec{ sharpnessEvalMethode::sharpImage, sharpnessEvalMethode::Brenner };
	// names of sharpness evaluation methodes
	std::vector<std::string> namesSharpEvalMeth_vec{ "sharpImage", "Brenner", "Tenengrad", "Laplacian", "SMD", "SMD2", "EnergyGradFct", "EVA", "NRSS", "BlurAndNoise" };
	//std::vector<std::string> namesSharpEvalMeth_vec{ "sharpImage", "Brenner"};
	real devideStepsByFactorForSecondSearch = 1.0;
	real reinizializePrecent = 20.0;
	std::string tempName;
	for (unsigned int i = 0; i < sharpEvalMethodes_vec.size(); ++i)
	{
		ImaProcSuperFct imaProcessingSuperFunction;

		paraUM_blue.setSharpnessEvalMethode(sharpEvalMethodes_vec[i]);
		paraUM_green = paraUM_blue;
		paraUM_red = paraUM_blue;

		imaProcessingSuperFunction.setParameterUnsMas_blue(paraUM_blue);
		imaProcessingSuperFunction.setParameterUnsMas_green(paraUM_green);
		imaProcessingSuperFunction.setParameterUnsMas_red(paraUM_red);

		// *** antelope *** //
		std::cout << "improve antelope" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_antelope, simImaMat_antelope, methodeImaProc);
		cv::Mat filterdIma_antelope = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_antelope + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_antelope = loc_antelope + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_antelope, tempName, "png", filterdIma_antelope, paraUM_blue.getCompareInPercent());

		bestParameterStruct_unsharpMask bestParaUnshMask_blue_antelope = imaProcessingSuperFunction.getBestParaUnsMas_blue();
		bestParameterStruct_unsharpMask bestParaUnshMask_green_antelope = imaProcessingSuperFunction.getBestParaUnsMas_green();
		bestParameterStruct_unsharpMask bestParaUnshMask_red_antelope = imaProcessingSuperFunction.getBestParaUnsMas_red();
		tempName = filtered_antelope + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		bestParaUnshMask_blue_antelope.exportAsTXTfile(temp_loc_antelope, tempName, true);
		tempName = filtered_antelope + "_" + namesSharpEvalMeth_vec[i] + "_green";
		bestParaUnshMask_green_antelope.exportAsTXTfile(temp_loc_antelope, tempName, true);
		tempName = filtered_antelope + "_" + namesSharpEvalMeth_vec[i] + "_red";
		bestParaUnshMask_red_antelope.exportAsTXTfile(temp_loc_antelope, tempName, true);
		vectoToExport_first.push_back(collectParameterUnsharpMasking(imaProcessingSuperFunction));

		imaProcessingSuperFunction.reinitializeBestParaUnsMas(reinizializePrecent, paraUM_blue.getStepsSigma() / devideStepsByFactorForSecondSearch, paraUM_blue.getStepsThreshold() / devideStepsByFactorForSecondSearch, paraUM_blue.getStepsAmount() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_antelope, simImaMat_antelope, methodeImaProc);
		cv::Mat second_filterdIma_antelope = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_antelope + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_antelope, tempName, "png", second_filterdIma_antelope, paraUM_blue.getCompareInPercent());

		bestParameterStruct_unsharpMask second_bestParaUnshMask_blue_antelope = imaProcessingSuperFunction.getBestParaUnsMas_blue();
		bestParameterStruct_unsharpMask second_bestParaUnshMask_green_antelope = imaProcessingSuperFunction.getBestParaUnsMas_green();
		bestParameterStruct_unsharpMask second_bestParaUnshMask_red_antelope = imaProcessingSuperFunction.getBestParaUnsMas_red();
		tempName = second_filtered_antelope + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		second_bestParaUnshMask_blue_antelope.exportAsTXTfile(temp_loc_antelope, tempName, true);
		tempName = second_filtered_antelope + "_" + namesSharpEvalMeth_vec[i] + "_green";
		second_bestParaUnshMask_green_antelope.exportAsTXTfile(temp_loc_antelope, tempName, true);
		tempName = second_filtered_antelope + "_" + namesSharpEvalMeth_vec[i] + "_red";
		second_bestParaUnshMask_red_antelope.exportAsTXTfile(temp_loc_antelope, tempName, true);

		vectoToExport_second.push_back(collectParameterUnsharpMasking(imaProcessingSuperFunction));
		// *** *** //

		// *** dragonfly *** //
		std::cout << "improve dragonfly" << std::endl;
		
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_dragonfly, simImaMat_dragonfly, methodeImaProc);
		cv::Mat filterdIma_dragonfly = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_dragonfly = loc_dragonfly + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_dragonfly, tempName, "png", filterdIma_dragonfly, paraUM_blue.getCompareInPercent());
		
		bestParameterStruct_unsharpMask bestParaUnshMask_blue_dragonfly = imaProcessingSuperFunction.getBestParaUnsMas_blue();
		bestParameterStruct_unsharpMask bestParaUnshMask_green_dragonfly = imaProcessingSuperFunction.getBestParaUnsMas_green();
		bestParameterStruct_unsharpMask bestParaUnshMask_red_dragonfly = imaProcessingSuperFunction.getBestParaUnsMas_red();
		tempName = filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		bestParaUnshMask_blue_dragonfly.exportAsTXTfile(temp_loc_dragonfly, tempName, true);
		tempName = filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i] + "_green";
		bestParaUnshMask_green_dragonfly.exportAsTXTfile(temp_loc_dragonfly, tempName, true);
		tempName = filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i] + "_red";
		bestParaUnshMask_red_dragonfly.exportAsTXTfile(temp_loc_dragonfly, tempName, true);
		vectoToExport_first.push_back(collectParameterUnsharpMasking(imaProcessingSuperFunction));
		
		imaProcessingSuperFunction.reinitializeBestParaUnsMas(reinizializePrecent, paraUM_blue.getStepsSigma() / devideStepsByFactorForSecondSearch, paraUM_blue.getStepsThreshold() / devideStepsByFactorForSecondSearch, paraUM_blue.getStepsAmount() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_dragonfly, simImaMat_dragonfly, methodeImaProc);
		cv::Mat second_filterdIma_dragonfly = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_dragonfly, tempName, "png", second_filterdIma_dragonfly, paraUM_blue.getCompareInPercent());
		
		bestParameterStruct_unsharpMask second_bestParaUnshMask_blue_dragonfly = imaProcessingSuperFunction.getBestParaUnsMas_blue();
		bestParameterStruct_unsharpMask second_bestParaUnshMask_green_dragonfly = imaProcessingSuperFunction.getBestParaUnsMas_green();
		bestParameterStruct_unsharpMask second_bestParaUnshMask_red_dragonfly = imaProcessingSuperFunction.getBestParaUnsMas_red();
		tempName = second_filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		second_bestParaUnshMask_blue_dragonfly.exportAsTXTfile(temp_loc_dragonfly, tempName, true);
		tempName = second_filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i] + "_green";
		second_bestParaUnshMask_green_dragonfly.exportAsTXTfile(temp_loc_dragonfly, tempName, true);
		tempName = second_filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i] + "_red";
		second_bestParaUnshMask_red_dragonfly.exportAsTXTfile(temp_loc_dragonfly, tempName, true);
		
		vectoToExport_second.push_back(collectParameterUnsharpMasking(imaProcessingSuperFunction));
		// *** *** //
		// *** elefant *** //
		std::cout << "improve elefant" << std::endl;
		
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant, methodeImaProc);
		cv::Mat filterdIma_elefant = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_elefant + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_elefant = loc_elefant + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_elefant, tempName, "png", filterdIma_elefant, paraUM_blue.getCompareInPercent());
		
		bestParameterStruct_unsharpMask bestParaUnshMask_blue_elefant = imaProcessingSuperFunction.getBestParaUnsMas_blue();
		bestParameterStruct_unsharpMask bestParaUnshMask_green_elefant = imaProcessingSuperFunction.getBestParaUnsMas_green();
		bestParameterStruct_unsharpMask bestParaUnshMask_red_elefant = imaProcessingSuperFunction.getBestParaUnsMas_red();
		tempName = filtered_elefant + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		bestParaUnshMask_blue_elefant.exportAsTXTfile(temp_loc_elefant, tempName, true);
		tempName = filtered_elefant + "_" + namesSharpEvalMeth_vec[i] + "_green";
		bestParaUnshMask_green_elefant.exportAsTXTfile(temp_loc_elefant, tempName, true);
		tempName = filtered_elefant + "_" + namesSharpEvalMeth_vec[i] + "_red";
		bestParaUnshMask_red_elefant.exportAsTXTfile(temp_loc_elefant, tempName, true);
		vectoToExport_first.push_back(collectParameterUnsharpMasking(imaProcessingSuperFunction));
		
		
		imaProcessingSuperFunction.reinitializeBestParaUnsMas(reinizializePrecent, paraUM_blue.getStepsSigma() / devideStepsByFactorForSecondSearch, paraUM_blue.getStepsThreshold() / devideStepsByFactorForSecondSearch, paraUM_blue.getStepsAmount() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant, methodeImaProc);
		cv::Mat second_filterdIma_elefant = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_elefant + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_elefant, tempName, "png", second_filterdIma_elefant, paraUM_blue.getCompareInPercent());
		
		bestParameterStruct_unsharpMask second_bestParaUnshMask_blue_elefant = imaProcessingSuperFunction.getBestParaUnsMas_blue();
		bestParameterStruct_unsharpMask second_bestParaUnshMask_green_elefant = imaProcessingSuperFunction.getBestParaUnsMas_green();
		bestParameterStruct_unsharpMask second_bestParaUnshMask_red_elefant = imaProcessingSuperFunction.getBestParaUnsMas_red();
		tempName = second_filtered_elefant + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		second_bestParaUnshMask_blue_elefant.exportAsTXTfile(temp_loc_elefant, tempName, true);
		tempName = second_filtered_elefant + "_" + namesSharpEvalMeth_vec[i] + "_green";
		second_bestParaUnshMask_green_elefant.exportAsTXTfile(temp_loc_elefant, tempName, true);
		tempName = second_filtered_elefant + "_" + namesSharpEvalMeth_vec[i] + "_red";
		second_bestParaUnshMask_red_elefant.exportAsTXTfile(temp_loc_elefant, tempName, true);
		
		vectoToExport_second.push_back(collectParameterUnsharpMasking(imaProcessingSuperFunction));
		// *** *** //
		
		// *** flower1 *** //
		std::cout << "improve flower1" << std::endl;
		
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower1, simImaMat_flower1, methodeImaProc);
		cv::Mat filterdIma_flower1 = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_flower1 + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_flower1 = loc_flower1 + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower1, tempName, "png", filterdIma_flower1, paraUM_blue.getCompareInPercent());
		
		bestParameterStruct_unsharpMask bestParaUnshMask_blue_flower1 = imaProcessingSuperFunction.getBestParaUnsMas_blue();
		bestParameterStruct_unsharpMask bestParaUnshMask_green_flower1 = imaProcessingSuperFunction.getBestParaUnsMas_green();
		bestParameterStruct_unsharpMask bestParaUnshMask_red_flower1 = imaProcessingSuperFunction.getBestParaUnsMas_red();
		tempName = filtered_flower1 + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		bestParaUnshMask_blue_flower1.exportAsTXTfile(temp_loc_flower1, tempName, true);
		tempName = filtered_flower1 + "_" + namesSharpEvalMeth_vec[i] + "_green";
		bestParaUnshMask_green_flower1.exportAsTXTfile(temp_loc_flower1, tempName, true);
		tempName = filtered_flower1 + "_" + namesSharpEvalMeth_vec[i] + "_red";
		bestParaUnshMask_red_flower1.exportAsTXTfile(temp_loc_flower1, tempName, true);
		vectoToExport_first.push_back(collectParameterUnsharpMasking(imaProcessingSuperFunction));
		
		
		imaProcessingSuperFunction.reinitializeBestParaUnsMas(reinizializePrecent, paraUM_blue.getStepsSigma() / devideStepsByFactorForSecondSearch, paraUM_blue.getStepsThreshold() / devideStepsByFactorForSecondSearch, paraUM_blue.getStepsAmount() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower1, simImaMat_flower1, methodeImaProc);
		cv::Mat second_filterdIma_flower1 = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_flower1 + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower1, tempName, "png", second_filterdIma_flower1, paraUM_blue.getCompareInPercent());
		
		bestParameterStruct_unsharpMask second_bestParaUnshMask_blue_flower1 = imaProcessingSuperFunction.getBestParaUnsMas_blue();
		bestParameterStruct_unsharpMask second_bestParaUnshMask_green_flower1 = imaProcessingSuperFunction.getBestParaUnsMas_green();
		bestParameterStruct_unsharpMask second_bestParaUnshMask_red_flower1 = imaProcessingSuperFunction.getBestParaUnsMas_red();
		tempName = second_filtered_flower1 + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		second_bestParaUnshMask_blue_flower1.exportAsTXTfile(temp_loc_flower1, tempName, true);
		tempName = second_filtered_flower1 + "_" + namesSharpEvalMeth_vec[i] + "_green";
		second_bestParaUnshMask_green_flower1.exportAsTXTfile(temp_loc_flower1, tempName, true);
		tempName = second_filtered_flower1 + "_" + namesSharpEvalMeth_vec[i] + "_red";
		second_bestParaUnshMask_red_flower1.exportAsTXTfile(temp_loc_flower1, tempName, true);
		
		vectoToExport_second.push_back(collectParameterUnsharpMasking(imaProcessingSuperFunction));
		// *** *** //
		
		
		// *** flower2 *** //
		std::cout << "improve flower2" << std::endl;
		
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower2, simImaMat_flower2, methodeImaProc);
		cv::Mat filterdIma_flower2 = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_flower2 + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_flower2 = loc_flower2 + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower2, tempName, "png", filterdIma_flower2, paraUM_blue.getCompareInPercent());
		
		bestParameterStruct_unsharpMask bestParaUnshMask_blue_flower2 = imaProcessingSuperFunction.getBestParaUnsMas_blue();
		bestParameterStruct_unsharpMask bestParaUnshMask_green_flower2 = imaProcessingSuperFunction.getBestParaUnsMas_green();
		bestParameterStruct_unsharpMask bestParaUnshMask_red_flower2 = imaProcessingSuperFunction.getBestParaUnsMas_red();
		tempName = filtered_flower2 + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		bestParaUnshMask_blue_flower2.exportAsTXTfile(temp_loc_flower2, tempName, true);
		tempName = filtered_flower2 + "_" + namesSharpEvalMeth_vec[i] + "_green";
		bestParaUnshMask_green_flower2.exportAsTXTfile(temp_loc_flower2, tempName, true);
		tempName = filtered_flower2 + "_" + namesSharpEvalMeth_vec[i] + "_red";
		bestParaUnshMask_red_flower2.exportAsTXTfile(temp_loc_flower2, tempName, true);
		vectoToExport_first.push_back(collectParameterUnsharpMasking(imaProcessingSuperFunction));
		
		
		imaProcessingSuperFunction.reinitializeBestParaUnsMas(reinizializePrecent, paraUM_blue.getStepsSigma() / devideStepsByFactorForSecondSearch, paraUM_blue.getStepsThreshold() / devideStepsByFactorForSecondSearch, paraUM_blue.getStepsAmount() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower2, simImaMat_flower2, methodeImaProc);
		cv::Mat second_filterdIma_flower2 = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_flower2 + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower2, tempName, "png", second_filterdIma_flower2, paraUM_blue.getCompareInPercent());
		
		bestParameterStruct_unsharpMask second_bestParaUnshMask_blue_flower2 = imaProcessingSuperFunction.getBestParaUnsMas_blue();
		bestParameterStruct_unsharpMask second_bestParaUnshMask_green_flower2 = imaProcessingSuperFunction.getBestParaUnsMas_green();
		bestParameterStruct_unsharpMask second_bestParaUnshMask_red_flower2 = imaProcessingSuperFunction.getBestParaUnsMas_red();
		tempName = second_filtered_flower2 + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		second_bestParaUnshMask_blue_flower2.exportAsTXTfile(temp_loc_flower2, tempName, true);
		tempName = second_filtered_flower2 + "_" + namesSharpEvalMeth_vec[i] + "_green";
		second_bestParaUnshMask_green_flower2.exportAsTXTfile(temp_loc_flower2, tempName, true);
		tempName = second_filtered_flower2 + "_" + namesSharpEvalMeth_vec[i] + "_red";
		second_bestParaUnshMask_red_flower2.exportAsTXTfile(temp_loc_flower2, tempName, true);
		
		vectoToExport_second.push_back(collectParameterUnsharpMasking(imaProcessingSuperFunction));
		// *** *** //
		
		// *** flower3 *** //
		std::cout << "improve flower3" << std::endl;
		
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower3, simImaMat_flower3, methodeImaProc);
		cv::Mat filterdIma_flower3 = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_flower3 + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_flower3 = loc_flower3 + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower3, tempName, "png", filterdIma_flower3, paraUM_blue.getCompareInPercent());
		
		bestParameterStruct_unsharpMask bestParaUnshMask_blue_flower3 = imaProcessingSuperFunction.getBestParaUnsMas_blue();
		bestParameterStruct_unsharpMask bestParaUnshMask_green_flower3 = imaProcessingSuperFunction.getBestParaUnsMas_green();
		bestParameterStruct_unsharpMask bestParaUnshMask_red_flower3 = imaProcessingSuperFunction.getBestParaUnsMas_red();
		tempName = filtered_flower3 + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		bestParaUnshMask_blue_flower3.exportAsTXTfile(temp_loc_flower3, tempName, true);
		tempName = filtered_flower3 + "_" + namesSharpEvalMeth_vec[i] + "_green";
		bestParaUnshMask_green_flower3.exportAsTXTfile(temp_loc_flower3, tempName, true);
		tempName = filtered_flower3 + "_" + namesSharpEvalMeth_vec[i] + "_red";
		bestParaUnshMask_red_flower3.exportAsTXTfile(temp_loc_flower3, tempName, true);
		vectoToExport_first.push_back(collectParameterUnsharpMasking(imaProcessingSuperFunction));
		
		
		imaProcessingSuperFunction.reinitializeBestParaUnsMas(reinizializePrecent, paraUM_blue.getStepsSigma() / devideStepsByFactorForSecondSearch, paraUM_blue.getStepsThreshold() / devideStepsByFactorForSecondSearch, paraUM_blue.getStepsAmount() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower3, simImaMat_flower3, methodeImaProc);
		cv::Mat second_filterdIma_flower3 = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_flower3 + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower3, tempName, "png", second_filterdIma_flower3, paraUM_blue.getCompareInPercent());
		
		bestParameterStruct_unsharpMask second_bestParaUnshMask_blue_flower3 = imaProcessingSuperFunction.getBestParaUnsMas_blue();
		bestParameterStruct_unsharpMask second_bestParaUnshMask_green_flower3 = imaProcessingSuperFunction.getBestParaUnsMas_green();
		bestParameterStruct_unsharpMask second_bestParaUnshMask_red_flower3 = imaProcessingSuperFunction.getBestParaUnsMas_red();
		tempName = second_filtered_flower3 + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		second_bestParaUnshMask_blue_flower3.exportAsTXTfile(temp_loc_flower3, tempName, true);
		tempName = second_filtered_flower3 + "_" + namesSharpEvalMeth_vec[i] + "_green";
		second_bestParaUnshMask_green_flower3.exportAsTXTfile(temp_loc_flower3, tempName, true);
		tempName = second_filtered_flower3 + "_" + namesSharpEvalMeth_vec[i] + "_red";
		second_bestParaUnshMask_red_flower3.exportAsTXTfile(temp_loc_flower3, tempName, true);
		
		vectoToExport_second.push_back(collectParameterUnsharpMasking(imaProcessingSuperFunction));
		// *** *** //
		
		// *** landscape *** //
		std::cout << "improve landscape" << std::endl;
		
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_landscape, simImaMat_landscape, methodeImaProc);
		cv::Mat filterdIma_landscape = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_landscape + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_landscape = loc_landscape + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_landscape, tempName, "png", filterdIma_landscape, paraUM_blue.getCompareInPercent());
		
		bestParameterStruct_unsharpMask bestParaUnshMask_blue_landscape = imaProcessingSuperFunction.getBestParaUnsMas_blue();
		bestParameterStruct_unsharpMask bestParaUnshMask_green_landscape = imaProcessingSuperFunction.getBestParaUnsMas_green();
		bestParameterStruct_unsharpMask bestParaUnshMask_red_landscape = imaProcessingSuperFunction.getBestParaUnsMas_red();
		tempName = filtered_landscape + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		bestParaUnshMask_blue_landscape.exportAsTXTfile(temp_loc_landscape, tempName, true);
		tempName = filtered_landscape + "_" + namesSharpEvalMeth_vec[i] + "_green";
		bestParaUnshMask_green_landscape.exportAsTXTfile(temp_loc_landscape, tempName, true);
		tempName = filtered_landscape + "_" + namesSharpEvalMeth_vec[i] + "_red";
		bestParaUnshMask_red_landscape.exportAsTXTfile(temp_loc_landscape, tempName, true);
		vectoToExport_first.push_back(collectParameterUnsharpMasking(imaProcessingSuperFunction));
		
		
		imaProcessingSuperFunction.reinitializeBestParaUnsMas(reinizializePrecent, paraUM_blue.getStepsSigma() / devideStepsByFactorForSecondSearch, paraUM_blue.getStepsThreshold() / devideStepsByFactorForSecondSearch, paraUM_blue.getStepsAmount() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_landscape, simImaMat_landscape, methodeImaProc);
		cv::Mat second_filterdIma_landscape = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_landscape + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_landscape, tempName, "png", second_filterdIma_landscape, paraUM_blue.getCompareInPercent());
		
		bestParameterStruct_unsharpMask second_bestParaUnshMask_blue_landscape = imaProcessingSuperFunction.getBestParaUnsMas_blue();
		bestParameterStruct_unsharpMask second_bestParaUnshMask_green_landscape = imaProcessingSuperFunction.getBestParaUnsMas_green();
		bestParameterStruct_unsharpMask second_bestParaUnshMask_red_landscape = imaProcessingSuperFunction.getBestParaUnsMas_red();
		tempName = second_filtered_landscape + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		second_bestParaUnshMask_blue_landscape.exportAsTXTfile(temp_loc_landscape, tempName, true);
		tempName = second_filtered_landscape + "_" + namesSharpEvalMeth_vec[i] + "_green";
		second_bestParaUnshMask_green_landscape.exportAsTXTfile(temp_loc_landscape, tempName, true);
		tempName = second_filtered_landscape + "_" + namesSharpEvalMeth_vec[i] + "_red";
		second_bestParaUnshMask_red_landscape.exportAsTXTfile(temp_loc_landscape, tempName, true);
		
		vectoToExport_second.push_back(collectParameterUnsharpMasking(imaProcessingSuperFunction));
		// *** *** //
		
		// *** pinguin *** //
		std::cout << "improve pinguin" << std::endl;
		
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_pinguin, simImaMat_pinguin, methodeImaProc);
		cv::Mat filterdIma_pinguin = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_pinguin + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_pinguin = loc_pinguin + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_pinguin, tempName, "png", filterdIma_pinguin, paraUM_blue.getCompareInPercent());
		
		bestParameterStruct_unsharpMask bestParaUnshMask_blue_pinguin = imaProcessingSuperFunction.getBestParaUnsMas_blue();
		bestParameterStruct_unsharpMask bestParaUnshMask_green_pinguin = imaProcessingSuperFunction.getBestParaUnsMas_green();
		bestParameterStruct_unsharpMask bestParaUnshMask_red_pinguin = imaProcessingSuperFunction.getBestParaUnsMas_red();
		tempName = filtered_pinguin + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		bestParaUnshMask_blue_pinguin.exportAsTXTfile(temp_loc_pinguin, tempName, true);
		tempName = filtered_pinguin + "_" + namesSharpEvalMeth_vec[i] + "_green";
		bestParaUnshMask_green_pinguin.exportAsTXTfile(temp_loc_pinguin, tempName, true);
		tempName = filtered_pinguin + "_" + namesSharpEvalMeth_vec[i] + "_red";
		bestParaUnshMask_red_pinguin.exportAsTXTfile(temp_loc_pinguin, tempName, true);
		vectoToExport_first.push_back(collectParameterUnsharpMasking(imaProcessingSuperFunction));
		
		
		imaProcessingSuperFunction.reinitializeBestParaUnsMas(reinizializePrecent, paraUM_blue.getStepsSigma() / devideStepsByFactorForSecondSearch, paraUM_blue.getStepsThreshold() / devideStepsByFactorForSecondSearch, paraUM_blue.getStepsAmount() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_pinguin, simImaMat_pinguin, methodeImaProc);
		cv::Mat second_filterdIma_pinguin = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_pinguin + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_pinguin, tempName, "png", second_filterdIma_pinguin, paraUM_blue.getCompareInPercent());
		
		bestParameterStruct_unsharpMask second_bestParaUnshMask_blue_pinguin = imaProcessingSuperFunction.getBestParaUnsMas_blue();
		bestParameterStruct_unsharpMask second_bestParaUnshMask_green_pinguin = imaProcessingSuperFunction.getBestParaUnsMas_green();
		bestParameterStruct_unsharpMask second_bestParaUnshMask_red_pinguin = imaProcessingSuperFunction.getBestParaUnsMas_red();
		tempName = second_filtered_pinguin + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		second_bestParaUnshMask_blue_pinguin.exportAsTXTfile(temp_loc_pinguin, tempName, true);
		tempName = second_filtered_pinguin + "_" + namesSharpEvalMeth_vec[i] + "_green";
		second_bestParaUnshMask_green_pinguin.exportAsTXTfile(temp_loc_pinguin, tempName, true);
		tempName = second_filtered_pinguin + "_" + namesSharpEvalMeth_vec[i] + "_red";
		second_bestParaUnshMask_red_pinguin.exportAsTXTfile(temp_loc_pinguin, tempName, true);
		
		vectoToExport_second.push_back(collectParameterUnsharpMasking(imaProcessingSuperFunction));
		// *** *** //
		
		// *** rhino *** //
		std::cout << "improve rhino" << std::endl;
		
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_rhino, simImaMat_rhino, methodeImaProc);
		cv::Mat filterdIma_rhino = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_rhino + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_rhino = loc_rhino + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_rhino, tempName, "png", filterdIma_rhino, paraUM_blue.getCompareInPercent());
		
		bestParameterStruct_unsharpMask bestParaUnshMask_blue_rhino = imaProcessingSuperFunction.getBestParaUnsMas_blue();
		bestParameterStruct_unsharpMask bestParaUnshMask_green_rhino = imaProcessingSuperFunction.getBestParaUnsMas_green();
		bestParameterStruct_unsharpMask bestParaUnshMask_red_rhino = imaProcessingSuperFunction.getBestParaUnsMas_red();
		tempName = filtered_rhino + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		bestParaUnshMask_blue_rhino.exportAsTXTfile(temp_loc_rhino, tempName, true);
		tempName = filtered_rhino + "_" + namesSharpEvalMeth_vec[i] + "_green";
		bestParaUnshMask_green_rhino.exportAsTXTfile(temp_loc_rhino, tempName, true);
		tempName = filtered_rhino + "_" + namesSharpEvalMeth_vec[i] + "_red";
		bestParaUnshMask_red_rhino.exportAsTXTfile(temp_loc_rhino, tempName, true);
		vectoToExport_first.push_back(collectParameterUnsharpMasking(imaProcessingSuperFunction));
		
		
		imaProcessingSuperFunction.reinitializeBestParaUnsMas(reinizializePrecent, paraUM_blue.getStepsSigma() / devideStepsByFactorForSecondSearch, paraUM_blue.getStepsThreshold() / devideStepsByFactorForSecondSearch, paraUM_blue.getStepsAmount() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_rhino, simImaMat_rhino, methodeImaProc);
		cv::Mat second_filterdIma_rhino = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_rhino + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_rhino, tempName, "png", second_filterdIma_rhino, paraUM_blue.getCompareInPercent());
		
		bestParameterStruct_unsharpMask second_bestParaUnshMask_blue_rhino = imaProcessingSuperFunction.getBestParaUnsMas_blue();
		bestParameterStruct_unsharpMask second_bestParaUnshMask_green_rhino = imaProcessingSuperFunction.getBestParaUnsMas_green();
		bestParameterStruct_unsharpMask second_bestParaUnshMask_red_rhino = imaProcessingSuperFunction.getBestParaUnsMas_red();
		tempName = second_filtered_rhino + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		second_bestParaUnshMask_blue_rhino.exportAsTXTfile(temp_loc_rhino, tempName, true);
		tempName = second_filtered_rhino + "_" + namesSharpEvalMeth_vec[i] + "_green";
		second_bestParaUnshMask_green_rhino.exportAsTXTfile(temp_loc_rhino, tempName, true);
		tempName = second_filtered_rhino + "_" + namesSharpEvalMeth_vec[i] + "_red";
		second_bestParaUnshMask_red_rhino.exportAsTXTfile(temp_loc_rhino, tempName, true);
		
		vectoToExport_second.push_back(collectParameterUnsharpMasking(imaProcessingSuperFunction));
		// *** *** //
		
		// *** salad *** //
		std::cout << "improve salad" << std::endl;
		
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_salad, simImaMat_salad, methodeImaProc);
		cv::Mat filterdIma_salad = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_salad + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_salad = loc_salad + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_salad, tempName, "png", filterdIma_salad, paraUM_blue.getCompareInPercent());
		
		bestParameterStruct_unsharpMask bestParaUnshMask_blue_salad = imaProcessingSuperFunction.getBestParaUnsMas_blue();
		bestParameterStruct_unsharpMask bestParaUnshMask_green_salad = imaProcessingSuperFunction.getBestParaUnsMas_green();
		bestParameterStruct_unsharpMask bestParaUnshMask_red_salad = imaProcessingSuperFunction.getBestParaUnsMas_red();
		tempName = filtered_salad + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		bestParaUnshMask_blue_salad.exportAsTXTfile(temp_loc_salad, tempName, true);
		tempName = filtered_salad + "_" + namesSharpEvalMeth_vec[i] + "_green";
		bestParaUnshMask_green_salad.exportAsTXTfile(temp_loc_salad, tempName, true);
		tempName = filtered_salad + "_" + namesSharpEvalMeth_vec[i] + "_red";
		bestParaUnshMask_red_salad.exportAsTXTfile(temp_loc_salad, tempName, true);
		vectoToExport_first.push_back(collectParameterUnsharpMasking(imaProcessingSuperFunction));
		
		
		imaProcessingSuperFunction.reinitializeBestParaUnsMas(reinizializePrecent, paraUM_blue.getStepsSigma() / devideStepsByFactorForSecondSearch, paraUM_blue.getStepsThreshold() / devideStepsByFactorForSecondSearch, paraUM_blue.getStepsAmount() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_salad, simImaMat_salad, methodeImaProc);
		cv::Mat second_filterdIma_salad = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_salad + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_salad, tempName, "png", second_filterdIma_salad, paraUM_blue.getCompareInPercent());
		
		bestParameterStruct_unsharpMask second_bestParaUnshMask_blue_salad = imaProcessingSuperFunction.getBestParaUnsMas_blue();
		bestParameterStruct_unsharpMask second_bestParaUnshMask_green_salad = imaProcessingSuperFunction.getBestParaUnsMas_green();
		bestParameterStruct_unsharpMask second_bestParaUnshMask_red_salad = imaProcessingSuperFunction.getBestParaUnsMas_red();
		tempName = second_filtered_salad + "_" + namesSharpEvalMeth_vec[i] + "_blue";
		second_bestParaUnshMask_blue_salad.exportAsTXTfile(temp_loc_salad, tempName, true);
		tempName = second_filtered_salad + "_" + namesSharpEvalMeth_vec[i] + "_green";
		second_bestParaUnshMask_green_salad.exportAsTXTfile(temp_loc_salad, tempName, true);
		tempName = second_filtered_salad + "_" + namesSharpEvalMeth_vec[i] + "_red";
		second_bestParaUnshMask_red_salad.exportAsTXTfile(temp_loc_salad, tempName, true);
		
		vectoToExport_second.push_back(collectParameterUnsharpMasking(imaProcessingSuperFunction));
		// *** *** //

	}

	// ***

	// ***
	unsigned int numberDatas = vectoToExport_first.size();
	unsigned int numberShaprEvalMeth = namesSharpEvalMeth_vec.size();
	unsigned int numberImages = numberDatas / numberShaprEvalMeth;

	//*** export all data to csv
	//*** first ***
	std::string firstIteration = "allData_First_UnsharpMasking24_ImpImaQualSupFct_E1";
	inportExportData::removeDateCSV(locationE1, firstIteration);
	unsigned int tempPos_first = 0;
	for (unsigned int i = 0; i < numberShaprEvalMeth; ++i)
	{
		inportExportData::exportDataToExcel(locationE1, firstIteration, namesSharpEvalMeth_vec[i], 0.0);
		for (unsigned int k = 0; k < numberImages; ++k)
		{
			inportExportData::exportDataToExcel_vector(locationE1, firstIteration, stringToExport, vectoToExport_first[tempPos_first]);
			++tempPos_first;
		}

	}

	// *** second ***
	unsigned int tempPos_second = 0;
	std::string secondIteration = "allData_Second_UnsharpMasking24_ImpImaQualSupFct_E1";
	inportExportData::removeDateCSV(locationE1, secondIteration);
	for (unsigned int i = 0; i < numberShaprEvalMeth; ++i)
	{
		inportExportData::exportDataToExcel(locationE1, secondIteration, namesSharpEvalMeth_vec[i], 0.0);
		for (unsigned int k = 0; k < numberImages; ++k)
		{
			inportExportData::exportDataToExcel_vector(locationE1, secondIteration, stringToExport, vectoToExport_second[tempPos_second]);
			++tempPos_second;
		}

	}

	// *** *** //
	bool checker = vectoToExport_first.size() == vectoToExport_second.size();
	// *** *** //
	return checker;

}

// test 2
bool testImproveImageQuality::testImpImaQual_E2_DetEnh24()
{

	std::string locationE2 = "../tests/testImproveImageQuality/improveImaQuality_superFct/E2";
	std::string loc_antelope = "../tests/testImproveImageQuality/improveImaQuality_superFct/E2/antelope";
	std::string loc_dragonfly = "../tests/testImproveImageQuality/improveImaQuality_superFct/E2/dragonfly";
	std::string loc_elefant = "../tests/testImproveImageQuality/improveImaQuality_superFct/E2/elefant";
	std::string loc_flower1 = "../tests/testImproveImageQuality/improveImaQuality_superFct/E2/flower1";
	std::string loc_flower2 = "../tests/testImproveImageQuality/improveImaQuality_superFct/E2/flower2";
	std::string loc_flower3 = "../tests/testImproveImageQuality/improveImaQuality_superFct/E2/flower3";
	std::string loc_landscape = "../tests/testImproveImageQuality/improveImaQuality_superFct/E2/landscape";
	std::string loc_pinguin = "../tests/testImproveImageQuality/improveImaQuality_superFct/E2/pinguin";
	std::string loc_rhino = "../tests/testImproveImageQuality/improveImaQuality_superFct/E2/rhino";
	std::string loc_salad = "../tests/testImproveImageQuality/improveImaQuality_superFct/E2/salad";

	// *** names objects *** // 
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

	// *** names filtered images *** //
	std::string filtered_antelope = "filtered_antelope";
	std::string second_filtered_antelope = "second_filtered_antelope";
	std::string filtered_dragonfly = "filtered_dragonfly";
	std::string second_filtered_dragonfly = "second_filtered_dragonfly";
	std::string filtered_elefant = "filtered_elefant";
	std::string second_filtered_elefant = "second_filtered_elefant";
	std::string filtered_flower1 = "filtered_flower1";
	std::string second_filtered_flower1 = "second_filtered_flower1";
	std::string filtered_flower2 = "filtered_flower2";
	std::string second_filtered_flower2 = "second_filtered_flower2";
	std::string filtered_flower3 = "filtered_flower3";
	std::string second_filtered_flower3 = "second_filtered_flower3";
	std::string filtered_landscape = "filtered_landscape";
	std::string second_filtered_landscape = "second_filtered_landscape";
	std::string filtered_pinguin = "filtered_pinguins";
	std::string second_filtered_pinguin = "second_filtered_pinguins";
	std::string filtered_rhino = "filtered_rhino";
	std::string second_filtered_rhino = "second_filtered_rhino";
	std::string filtered_salad = "filtered_salad";
	std::string second_filtered_salad = "second_filtered_salad";

	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_antelope = Images::loadAnImage_Color(loactionObject, antelope);
	cv::Mat object_dragonfly = Images::loadAnImage_Color(loactionObject, dragonfly);
	cv::Mat object_elefant = Images::loadAnImage_Color(loactionObject, elefant);
	cv::Mat object_flower1 = Images::loadAnImage_Color(loactionObject, flower1);
	cv::Mat object_flower2 = Images::loadAnImage_Color(loactionObject, flower2);
	cv::Mat object_flower3 = Images::loadAnImage_Color(loactionObject, flower3);
	cv::Mat object_landscape = Images::loadAnImage_Color(loactionObject, landscape);
	cv::Mat object_pinguin = Images::loadAnImage_Color(loactionObject, pinguin);
	cv::Mat object_rhino = Images::loadAnImage_Color(loactionObject, rhino);
	cv::Mat object_salad = Images::loadAnImage_Color(loactionObject, salad);

	// *** names simulated images *** //
	std::string locationImages = "../tests/testImageSimulation/S12";
	std::string simIma_antelope = "simIma_antelope";
	std::string simIma_dragonfly = "simIma_dragonfly";
	std::string simIma_elefant = "simIma_elefant";
	std::string simIma_flower1 = "simIma_flower1";
	std::string simIma_flower2 = "simIma_flower2";
	std::string simIma_flower3 = "simIma_flower3";
	std::string simIma_landscape = "simIma_landscape";
	std::string simIma_pinguin = "simIma_pinguin";
	std::string simIma_rhino = "simIma_rhino";
	std::string simIma_salad = "simIma_salad";

	// *** load simulated images *** //
	cv::Mat  simImaMat_antelope = Images::loadAnImage_Color(locationImages, simIma_antelope);
	cv::Mat  simImaMat_dragonfly = Images::loadAnImage_Color(locationImages, simIma_dragonfly);
	cv::Mat  simImaMat_elefant = Images::loadAnImage_Color(locationImages, simIma_elefant);
	cv::Mat  simImaMat_flower1 = Images::loadAnImage_Color(locationImages, simIma_flower1);
	cv::Mat  simImaMat_flower2 = Images::loadAnImage_Color(locationImages, simIma_flower2);
	cv::Mat  simImaMat_flower3 = Images::loadAnImage_Color(locationImages, simIma_flower3);
	cv::Mat  simImaMat_landscape = Images::loadAnImage_Color(locationImages, simIma_landscape);
	cv::Mat  simImaMat_pinguin = Images::loadAnImage_Color(locationImages, simIma_pinguin);
	cv::Mat  simImaMat_rhino = Images::loadAnImage_Color(locationImages, simIma_rhino);
	cv::Mat  simImaMat_salad = Images::loadAnImage_Color(locationImages, simIma_salad);

	// *** parameter detail enhancement ***///
	imageProcessing methodeImaProc = imageProcessing::detailEnhance24;

	// *** parameter DE 
	parameterDetailEnhancement paraDE;
	paraDE.setMinSigma_r(0.001);
	paraDE.setMaxSigma_r(100.0);
	//paraDE.setStepsSigma_r(200.0);
	paraDE.setStepsSigma_r(50.0);

	paraDE.setMinSigma_s(1.0);
	paraDE.setMaxSigma_s(100.0);
	//paraDE.setStepsSigma_s(200.0);
	paraDE.setStepsSigma_s(50.0);

	paraDE.setPercentCompare(0.0);


	//  ***  *** //

	// *** *** //
	std::string stringToExport = "sigma_r, sigma_s, imp_total, bestCoreNum";
	std::vector<std::vector<real>> vectoToExport_first{};
	std::vector<std::vector<real>> vectoToExport_second{};

	// *** *** //

	// sharpness evaluation methodes
	std::vector<sharpnessEvalMethode> sharpEvalMethodes_vec{ sharpnessEvalMethode::sharpImage, sharpnessEvalMethode::Brenner, sharpnessEvalMethode::Tenengrad,
	sharpnessEvalMethode::Laplacian, sharpnessEvalMethode::SMD, sharpnessEvalMethode::SMD2, sharpnessEvalMethode::EnergyGradFct, sharpnessEvalMethode::EVA,
	sharpnessEvalMethode::NRSS, sharpnessEvalMethode::BlurAndNoise };
	//std::vector<sharpnessEvalMethode> sharpEvalMethodes_vec{ sharpnessEvalMethode::sharpImage, sharpnessEvalMethode::Brenner, sharpnessEvalMethode::Tenengrad};
	// names of sharpness evaluation methodes
	std::vector<std::string> namesSharpEvalMeth_vec{ "sharpImage", "Brenner", "Tenengrad", "Laplacian", "SMD", "SMD2", "EnergyGradFct", "EVA", "NRSS", "BlurAndNoise" };
	//std::vector<std::string> namesSharpEvalMeth_vec{ "sharpImage", "Brenner", "Tenengrad"};

	real devideStepsByFactorForSecondSearch = 1.0;
	real reinitailizePercent = 20.0;
	std::string tempName;
	for (unsigned int i = 0; i < sharpEvalMethodes_vec.size(); ++i)
	{
		//// test
		//if (i > 0)
		//{
		//	paraDE.setMinSigma_r(paraDE.getMaxSigma_r());
		//	paraDE.setMaxSigma_r(paraDE.getMaxSigma_r() + 2.0);
		//	//paraDE.setStepsSigma_r(200.0);
		//	paraDE.setMinSigma_s(paraDE.getMaxSigma_s());
		//	paraDE.setMaxSigma_s(paraDE.getMaxSigma_s() + 10.0);
		//	paraDE.setPercentCompare(0.0);
		//}

		ImaProcSuperFct imaProcessingSuperFunction;
		paraDE.setSharpnessEvalMethode(sharpEvalMethodes_vec[i]);
		imaProcessingSuperFunction.setParameterDetEnh(paraDE);



		// *** antelope *** //
		std::cout << "improve antelope" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_antelope, simImaMat_antelope, methodeImaProc);
		cv::Mat filterdIma_antelope = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_antelope + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_antelope = loc_antelope + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_antelope, tempName, "png", filterdIma_antelope, paraDE.getPercentCompare());

		bestParameterStruct_detailEnhance bestParaDetEnh_antelope = imaProcessingSuperFunction.getBestParaDetEnh();

		tempName = filtered_antelope + "_" + namesSharpEvalMeth_vec[i];
		bestParaDetEnh_antelope.exportAsTXTfile(temp_loc_antelope, tempName, true);
		vectoToExport_first.push_back(collectParameterDetailEnhancement(imaProcessingSuperFunction));

		imaProcessingSuperFunction.reinitializeBestParaDetEng(reinitailizePercent, paraDE.getStepsSigma_r() / devideStepsByFactorForSecondSearch, paraDE.getStepsSigma_s() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_antelope, simImaMat_antelope, methodeImaProc);
		cv::Mat second_filterdIma_antelope = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_antelope + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_antelope, tempName, "png", second_filterdIma_antelope, paraDE.getPercentCompare());

		bestParameterStruct_detailEnhance second_bestParaDetEnh_antelope = imaProcessingSuperFunction.getBestParaDetEnh();

		tempName = second_filtered_antelope + "_" + namesSharpEvalMeth_vec[i];
		second_bestParaDetEnh_antelope.exportAsTXTfile(temp_loc_antelope, tempName, true);

		vectoToExport_second.push_back(collectParameterDetailEnhancement(imaProcessingSuperFunction));
		// *** *** //

		// *** dragonfly *** //
		std::cout << "improve dragonfly" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_dragonfly, simImaMat_dragonfly, methodeImaProc);
		cv::Mat filterdIma_dragonfly = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_dragonfly = loc_dragonfly + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_dragonfly, tempName, "png", filterdIma_dragonfly, paraDE.getPercentCompare());

		bestParameterStruct_detailEnhance bestParaDetEnh_dragonfly = imaProcessingSuperFunction.getBestParaDetEnh();

		tempName = filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i];
		bestParaDetEnh_dragonfly.exportAsTXTfile(temp_loc_dragonfly, tempName, true);
		vectoToExport_first.push_back(collectParameterDetailEnhancement(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitializeBestParaDetEng(reinitailizePercent, paraDE.getStepsSigma_r() / devideStepsByFactorForSecondSearch, paraDE.getStepsSigma_s() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_dragonfly, simImaMat_dragonfly, methodeImaProc);
		cv::Mat second_filterdIma_dragonfly = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_dragonfly, tempName, "png", second_filterdIma_dragonfly, paraDE.getPercentCompare());

		bestParameterStruct_detailEnhance second_bestParaDetEnh_dragonfly = imaProcessingSuperFunction.getBestParaDetEnh();

		tempName = second_filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i];
		second_bestParaDetEnh_dragonfly.exportAsTXTfile(temp_loc_dragonfly, tempName, true);

		vectoToExport_second.push_back(collectParameterDetailEnhancement(imaProcessingSuperFunction));
		// *** *** //

		// *** elefant *** //
		std::cout << "improve elefant" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant, methodeImaProc);
		cv::Mat filterdIma_elefant = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_elefant + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_elefant = loc_elefant + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_elefant, tempName, "png", filterdIma_elefant, paraDE.getPercentCompare());

		bestParameterStruct_detailEnhance bestParaDetEnh_elefant = imaProcessingSuperFunction.getBestParaDetEnh();

		tempName = filtered_elefant + "_" + namesSharpEvalMeth_vec[i];
		bestParaDetEnh_elefant.exportAsTXTfile(temp_loc_elefant, tempName, true);
		vectoToExport_first.push_back(collectParameterDetailEnhancement(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitializeBestParaDetEng(reinitailizePercent, paraDE.getStepsSigma_r() / devideStepsByFactorForSecondSearch, paraDE.getStepsSigma_s() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant, methodeImaProc);
		cv::Mat second_filterdIma_elefant = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_elefant + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_elefant, tempName, "png", second_filterdIma_elefant, paraDE.getPercentCompare());

		bestParameterStruct_detailEnhance second_bestParaDetEnh_elefant = imaProcessingSuperFunction.getBestParaDetEnh();

		tempName = second_filtered_elefant + "_" + namesSharpEvalMeth_vec[i];
		second_bestParaDetEnh_elefant.exportAsTXTfile(temp_loc_elefant, tempName, true);

		vectoToExport_second.push_back(collectParameterDetailEnhancement(imaProcessingSuperFunction));
		// *** *** //


		// *** flower1 *** //
		std::cout << "improve flower1" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower1, simImaMat_flower1, methodeImaProc);
		cv::Mat filterdIma_flower1 = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_flower1 + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_flower1 = loc_flower1 + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower1, tempName, "png", filterdIma_flower1, paraDE.getPercentCompare());

		bestParameterStruct_detailEnhance bestParaDetEnh_flower1 = imaProcessingSuperFunction.getBestParaDetEnh();

		tempName = filtered_flower1 + "_" + namesSharpEvalMeth_vec[i];
		bestParaDetEnh_flower1.exportAsTXTfile(temp_loc_flower1, tempName, true);
		vectoToExport_first.push_back(collectParameterDetailEnhancement(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitializeBestParaDetEng(reinitailizePercent, paraDE.getStepsSigma_r() / devideStepsByFactorForSecondSearch, paraDE.getStepsSigma_s() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower1, simImaMat_flower1, methodeImaProc);
		cv::Mat second_filterdIma_flower1 = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_flower1 + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower1, tempName, "png", second_filterdIma_flower1, paraDE.getPercentCompare());

		bestParameterStruct_detailEnhance second_bestParaDetEnh_flower1 = imaProcessingSuperFunction.getBestParaDetEnh();

		tempName = second_filtered_flower1 + "_" + namesSharpEvalMeth_vec[i];
		second_bestParaDetEnh_flower1.exportAsTXTfile(temp_loc_flower1, tempName, true);

		vectoToExport_second.push_back(collectParameterDetailEnhancement(imaProcessingSuperFunction));
		// *** *** //

		// *** flower2 *** //
		std::cout << "improve flower2" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower2, simImaMat_flower2, methodeImaProc);
		cv::Mat filterdIma_flower2 = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_flower2 + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_flower2 = loc_flower2 + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower2, tempName, "png", filterdIma_flower2, paraDE.getPercentCompare());

		bestParameterStruct_detailEnhance bestParaDetEnh_flower2 = imaProcessingSuperFunction.getBestParaDetEnh();

		tempName = filtered_flower2 + "_" + namesSharpEvalMeth_vec[i];
		bestParaDetEnh_flower2.exportAsTXTfile(temp_loc_flower2, tempName, true);
		vectoToExport_first.push_back(collectParameterDetailEnhancement(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitializeBestParaDetEng(reinitailizePercent, paraDE.getStepsSigma_r() / devideStepsByFactorForSecondSearch, paraDE.getStepsSigma_s() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower2, simImaMat_flower2, methodeImaProc);
		cv::Mat second_filterdIma_flower2 = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_flower2 + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower2, tempName, "png", second_filterdIma_flower2, paraDE.getPercentCompare());

		bestParameterStruct_detailEnhance second_bestParaDetEnh_flower2 = imaProcessingSuperFunction.getBestParaDetEnh();

		tempName = second_filtered_flower2 + "_" + namesSharpEvalMeth_vec[i];
		second_bestParaDetEnh_flower2.exportAsTXTfile(temp_loc_flower2, tempName, true);

		vectoToExport_second.push_back(collectParameterDetailEnhancement(imaProcessingSuperFunction));
		// *** *** //

		// *** flower3 *** //
		std::cout << "improve flower3" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower3, simImaMat_flower3, methodeImaProc);
		cv::Mat filterdIma_flower3 = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_flower3 + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_flower3 = loc_flower3 + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower3, tempName, "png", filterdIma_flower3, paraDE.getPercentCompare());

		bestParameterStruct_detailEnhance bestParaDetEnh_flower3 = imaProcessingSuperFunction.getBestParaDetEnh();

		tempName = filtered_flower3 + "_" + namesSharpEvalMeth_vec[i];
		bestParaDetEnh_flower3.exportAsTXTfile(temp_loc_flower3, tempName, true);
		vectoToExport_first.push_back(collectParameterDetailEnhancement(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitializeBestParaDetEng(reinitailizePercent, paraDE.getStepsSigma_r() / devideStepsByFactorForSecondSearch, paraDE.getStepsSigma_s() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower3, simImaMat_flower3, methodeImaProc);
		cv::Mat second_filterdIma_flower3 = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_flower3 + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower3, tempName, "png", second_filterdIma_flower3, paraDE.getPercentCompare());

		bestParameterStruct_detailEnhance second_bestParaDetEnh_flower3 = imaProcessingSuperFunction.getBestParaDetEnh();

		tempName = second_filtered_flower3 + "_" + namesSharpEvalMeth_vec[i];
		second_bestParaDetEnh_flower3.exportAsTXTfile(temp_loc_flower3, tempName, true);

		vectoToExport_second.push_back(collectParameterDetailEnhancement(imaProcessingSuperFunction));
		// *** *** //

		// *** landscape *** //
		std::cout << "improve landscape" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_landscape, simImaMat_landscape, methodeImaProc);
		cv::Mat filterdIma_landscape = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_landscape + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_landscape = loc_landscape + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_landscape, tempName, "png", filterdIma_landscape, paraDE.getPercentCompare());

		bestParameterStruct_detailEnhance bestParaDetEnh_landscape = imaProcessingSuperFunction.getBestParaDetEnh();

		tempName = filtered_landscape + "_" + namesSharpEvalMeth_vec[i];
		bestParaDetEnh_landscape.exportAsTXTfile(temp_loc_landscape, tempName, true);
		vectoToExport_first.push_back(collectParameterDetailEnhancement(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitializeBestParaDetEng(reinitailizePercent, paraDE.getStepsSigma_r() / devideStepsByFactorForSecondSearch, paraDE.getStepsSigma_s() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_landscape, simImaMat_landscape, methodeImaProc);
		cv::Mat second_filterdIma_landscape = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_landscape + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_landscape, tempName, "png", second_filterdIma_landscape, paraDE.getPercentCompare());

		bestParameterStruct_detailEnhance second_bestParaDetEnh_landscape = imaProcessingSuperFunction.getBestParaDetEnh();

		tempName = second_filtered_landscape + "_" + namesSharpEvalMeth_vec[i];
		second_bestParaDetEnh_landscape.exportAsTXTfile(temp_loc_landscape, tempName, true);

		vectoToExport_second.push_back(collectParameterDetailEnhancement(imaProcessingSuperFunction));
		// *** *** //

		// *** pinguin *** //
		std::cout << "improve pinguin" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_pinguin, simImaMat_pinguin, methodeImaProc);
		cv::Mat filterdIma_pinguin = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_pinguin + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_pinguin = loc_pinguin + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_pinguin, tempName, "png", filterdIma_pinguin, paraDE.getPercentCompare());

		bestParameterStruct_detailEnhance bestParaDetEnh_pinguin = imaProcessingSuperFunction.getBestParaDetEnh();

		tempName = filtered_pinguin + "_" + namesSharpEvalMeth_vec[i];
		bestParaDetEnh_pinguin.exportAsTXTfile(temp_loc_pinguin, tempName, true);
		vectoToExport_first.push_back(collectParameterDetailEnhancement(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitializeBestParaDetEng(reinitailizePercent, paraDE.getStepsSigma_r() / devideStepsByFactorForSecondSearch, paraDE.getStepsSigma_s() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_pinguin, simImaMat_pinguin, methodeImaProc);
		cv::Mat second_filterdIma_pinguin = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_pinguin + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_pinguin, tempName, "png", second_filterdIma_pinguin, paraDE.getPercentCompare());

		bestParameterStruct_detailEnhance second_bestParaDetEnh_pinguin = imaProcessingSuperFunction.getBestParaDetEnh();

		tempName = second_filtered_pinguin + "_" + namesSharpEvalMeth_vec[i];
		second_bestParaDetEnh_pinguin.exportAsTXTfile(temp_loc_pinguin, tempName, true);

		vectoToExport_second.push_back(collectParameterDetailEnhancement(imaProcessingSuperFunction));
		// *** *** //

		// *** rhino *** //
		std::cout << "improve rhino" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_rhino, simImaMat_rhino, methodeImaProc);
		cv::Mat filterdIma_rhino = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_rhino + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_rhino = loc_rhino + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_rhino, tempName, "png", filterdIma_rhino, paraDE.getPercentCompare());

		bestParameterStruct_detailEnhance bestParaDetEnh_rhino = imaProcessingSuperFunction.getBestParaDetEnh();

		tempName = filtered_rhino + "_" + namesSharpEvalMeth_vec[i];
		bestParaDetEnh_rhino.exportAsTXTfile(temp_loc_rhino, tempName, true);
		vectoToExport_first.push_back(collectParameterDetailEnhancement(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitializeBestParaDetEng(reinitailizePercent, paraDE.getStepsSigma_r() / devideStepsByFactorForSecondSearch, paraDE.getStepsSigma_s() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_rhino, simImaMat_rhino, methodeImaProc);
		cv::Mat second_filterdIma_rhino = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_rhino + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_rhino, tempName, "png", second_filterdIma_rhino, paraDE.getPercentCompare());

		bestParameterStruct_detailEnhance second_bestParaDetEnh_rhino = imaProcessingSuperFunction.getBestParaDetEnh();

		tempName = second_filtered_rhino + "_" + namesSharpEvalMeth_vec[i];
		second_bestParaDetEnh_rhino.exportAsTXTfile(temp_loc_rhino, tempName, true);

		vectoToExport_second.push_back(collectParameterDetailEnhancement(imaProcessingSuperFunction));
		// *** *** //

		// *** salad *** //
		std::cout << "improve salad" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_salad, simImaMat_salad, methodeImaProc);
		cv::Mat filterdIma_salad = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_salad + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_salad = loc_salad + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_salad, tempName, "png", filterdIma_salad, paraDE.getPercentCompare());

		bestParameterStruct_detailEnhance bestParaDetEnh_salad = imaProcessingSuperFunction.getBestParaDetEnh();

		tempName = filtered_salad + "_" + namesSharpEvalMeth_vec[i];
		bestParaDetEnh_salad.exportAsTXTfile(temp_loc_salad, tempName, true);
		vectoToExport_first.push_back(collectParameterDetailEnhancement(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitializeBestParaDetEng(reinitailizePercent, paraDE.getStepsSigma_r() / devideStepsByFactorForSecondSearch, paraDE.getStepsSigma_s() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_salad, simImaMat_salad, methodeImaProc);
		cv::Mat second_filterdIma_salad = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_salad + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_salad, tempName, "png", second_filterdIma_salad, paraDE.getPercentCompare());

		bestParameterStruct_detailEnhance second_bestParaDetEnh_salad = imaProcessingSuperFunction.getBestParaDetEnh();

		tempName = second_filtered_salad + "_" + namesSharpEvalMeth_vec[i];
		second_bestParaDetEnh_salad.exportAsTXTfile(temp_loc_salad, tempName, true);

		vectoToExport_second.push_back(collectParameterDetailEnhancement(imaProcessingSuperFunction));
		// *** *** //

	}




	// ***
	unsigned int numberDatas = vectoToExport_first.size();
	unsigned int numberShaprEvalMeth = namesSharpEvalMeth_vec.size();
	unsigned int numberImages = numberDatas / numberShaprEvalMeth;

	// export all data to csv
	// ***
	// first
	std::string firstInteration = "allData_First_DetailEnhancement24_ImpImaQualSupFct_E2";
	inportExportData::removeDateCSV(locationE2, firstInteration);
	// ***
	unsigned int tempPos_First = 0;
	for (unsigned int i = 0; i < numberShaprEvalMeth; ++i)
	{
		inportExportData::exportDataToExcel(locationE2, firstInteration, namesSharpEvalMeth_vec[i], 0.0);
		for (unsigned int k = 0; k < numberImages; ++k)
		{
			inportExportData::exportDataToExcel_vector(locationE2, firstInteration, stringToExport, vectoToExport_first[tempPos_First]);
			++tempPos_First;
		}

	}

	// second
	std::string secondInteration = "allData_Second_DetailEnhancement24_ImpImaQualSupFct_E2";
	inportExportData::removeDateCSV(locationE2, secondInteration);
	unsigned int tempPos_Second = 0;
	for (unsigned int i = 0; i < numberShaprEvalMeth; ++i)
	{
		inportExportData::exportDataToExcel(locationE2, secondInteration, namesSharpEvalMeth_vec[i], 0.0);
		for (unsigned int k = 0; k < numberImages; ++k)
		{
			inportExportData::exportDataToExcel_vector(locationE2, secondInteration, stringToExport, vectoToExport_second[tempPos_Second]);
			++tempPos_Second;
		}

	}

	// *** *** //
	bool checker = vectoToExport_first.size() == vectoToExport_second.size();
	// *** *** //
	return checker;
}

// test 3
bool testImproveImageQuality::testImpQual_E3_RemChromAber()
{
	std::string locationE3 = "../tests/testImproveImageQuality/improveImaQuality_superFct/E3";
	std::string loc_antelope = "../tests/testImproveImageQuality/improveImaQuality_superFct/E3/antelope";
	std::string loc_dragonfly = "../tests/testImproveImageQuality/improveImaQuality_superFct/E3/dragonfly";
	std::string loc_elefant = "../tests/testImproveImageQuality/improveImaQuality_superFct/E3/elefant";
	std::string loc_flower1 = "../tests/testImproveImageQuality/improveImaQuality_superFct/E3/flower1";
	std::string loc_flower2 = "../tests/testImproveImageQuality/improveImaQuality_superFct/E3/flower2";
	std::string loc_flower3 = "../tests/testImproveImageQuality/improveImaQuality_superFct/E3/flower3";
	std::string loc_landscape = "../tests/testImproveImageQuality/improveImaQuality_superFct/E3/landscape";
	std::string loc_pinguin = "../tests/testImproveImageQuality/improveImaQuality_superFct/E3/pinguin";
	std::string loc_rhino = "../tests/testImproveImageQuality/improveImaQuality_superFct/E3/rhino";
	std::string loc_salad = "../tests/testImproveImageQuality/improveImaQuality_superFct/E3/salad";

	// *** names objects *** // 
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

	// *** names filtered images *** //
	std::string filtered_antelope = "filtered_antelope";
	std::string second_filtered_antelope = "second_filtered_antelope";
	std::string filtered_dragonfly = "filtered_dragonfly";
	std::string second_filtered_dragonfly = "second_filtered_dragonfly";
	std::string filtered_elefant = "filtered_elefant";
	std::string second_filtered_elefant = "second_filtered_elefant";
	std::string filtered_flower1 = "filtered_flower1";
	std::string second_filtered_flower1 = "second_filtered_flower1";
	std::string filtered_flower2 = "filtered_flower2";
	std::string second_filtered_flower2 = "second_filtered_flower2";
	std::string filtered_flower3 = "filtered_flower3";
	std::string second_filtered_flower3 = "second_filtered_flower3";
	std::string filtered_landscape = "filtered_landscape";
	std::string second_filtered_landscape = "second_filtered_landscape";
	std::string filtered_pinguin = "filtered_pinguins";
	std::string second_filtered_pinguin = "second_filtered_pinguins";
	std::string filtered_rhino = "filtered_rhino";
	std::string second_filtered_rhino = "second_filtered_rhino";
	std::string filtered_salad = "filtered_salad";
	std::string second_filtered_salad = "second_filtered_salad";

	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_antelope = Images::loadAnImage_Color(loactionObject, antelope);
	cv::Mat object_dragonfly = Images::loadAnImage_Color(loactionObject, dragonfly);
	cv::Mat object_elefant = Images::loadAnImage_Color(loactionObject, elefant);
	cv::Mat object_flower1 = Images::loadAnImage_Color(loactionObject, flower1);
	cv::Mat object_flower2 = Images::loadAnImage_Color(loactionObject, flower2);
	cv::Mat object_flower3 = Images::loadAnImage_Color(loactionObject, flower3);
	cv::Mat object_landscape = Images::loadAnImage_Color(loactionObject, landscape);
	cv::Mat object_pinguin = Images::loadAnImage_Color(loactionObject, pinguin);
	cv::Mat object_rhino = Images::loadAnImage_Color(loactionObject, rhino);
	cv::Mat object_salad = Images::loadAnImage_Color(loactionObject, salad);

	// *** names simulated images *** //
	std::string locationImages = "../tests/testImageSimulation/S12";
	std::string simIma_antelope = "simIma_antelope";
	std::string simIma_dragonfly = "simIma_dragonfly";
	std::string simIma_elefant = "simIma_elefant";
	std::string simIma_flower1 = "simIma_flower1";
	std::string simIma_flower2 = "simIma_flower2";
	std::string simIma_flower3 = "simIma_flower3";
	std::string simIma_landscape = "simIma_landscape";
	std::string simIma_pinguin = "simIma_pinguin";
	std::string simIma_rhino = "simIma_rhino";
	std::string simIma_salad = "simIma_salad";

	// *** load simulated images *** //
	cv::Mat  simImaMat_antelope = Images::loadAnImage_Color(locationImages, simIma_antelope);
	cv::Mat  simImaMat_dragonfly = Images::loadAnImage_Color(locationImages, simIma_dragonfly);
	cv::Mat  simImaMat_elefant = Images::loadAnImage_Color(locationImages, simIma_elefant);
	cv::Mat  simImaMat_flower1 = Images::loadAnImage_Color(locationImages, simIma_flower1);
	cv::Mat  simImaMat_flower2 = Images::loadAnImage_Color(locationImages, simIma_flower2);
	cv::Mat  simImaMat_flower3 = Images::loadAnImage_Color(locationImages, simIma_flower3);
	cv::Mat  simImaMat_landscape = Images::loadAnImage_Color(locationImages, simIma_landscape);
	cv::Mat  simImaMat_pinguin = Images::loadAnImage_Color(locationImages, simIma_pinguin);
	cv::Mat  simImaMat_rhino = Images::loadAnImage_Color(locationImages, simIma_rhino);
	cv::Mat  simImaMat_salad = Images::loadAnImage_Color(locationImages, simIma_salad);

	// *** parameter detail enhancement ***///
	imageProcessing methodeImaProc = imageProcessing::removeChromaticAber;

	// *** parameter DE 
	initialPararemChromAber iniParaRemChromAber;
	iniParaRemChromAber.setMinThreshold(-100);
	iniParaRemChromAber.setMaxThreshold(100);
	iniParaRemChromAber.setStepsThreshold(1000.0);
	iniParaRemChromAber.setCompateInPercent(0.0);

	// *** set the parameter
	ImaProcSuperFct imaProcessingSuperFunction;
	//  ***  *** //

	// *** *** //
	std::string stringToExport = "threshold, imp_total";
	std::vector<std::vector<real>> vectoToExport_First{};
	std::vector<std::vector<real>> vectoToExport_Second{};
	// *** *** //

	// sharpness evaluation methodes
	std::vector<sharpnessEvalMethode> sharpEvalMethodes_vec{ sharpnessEvalMethode::sharpImage, sharpnessEvalMethode::Brenner, sharpnessEvalMethode::Tenengrad,
	sharpnessEvalMethode::Laplacian, sharpnessEvalMethode::SMD, sharpnessEvalMethode::SMD2, sharpnessEvalMethode::EnergyGradFct, sharpnessEvalMethode::EVA,
	sharpnessEvalMethode::NRSS, sharpnessEvalMethode::BlurAndNoise };
	// names of sharpness evaluation methodes
	std::vector<std::string> namesSharpEvalMeth_vec{ "sharpImage", "Brenner", "Tenengrad", "Laplacian", "SMD", "SMD2", "EnergyGradFct", "EVA", "NRSS", "BlurAndNoise" };
	real devideStepsByFactorForSecondSearch = 1.0;
	real reinizalizePercent = 10.0;
	std::string tempName;

	for (unsigned int i = 0; i < sharpEvalMethodes_vec.size(); ++i)
	{
		iniParaRemChromAber.setSharpnessEvalMethode(sharpEvalMethodes_vec[i]);
		imaProcessingSuperFunction.setParameterRemoveChromAber(iniParaRemChromAber);

		// *** antelope *** //
		std::cout << "improve antelope" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_antelope, simImaMat_antelope, methodeImaProc);
		cv::Mat filterdIma_antelope = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_antelope + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_antelope = loc_antelope + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_antelope, tempName, "png", filterdIma_antelope, iniParaRemChromAber.getCompateInPercent());

		bestParaRemChromAber bestParaRemChromAber_antelope = imaProcessingSuperFunction.getBestParaRemoveChromAber();

		tempName = filtered_antelope + "_" + namesSharpEvalMeth_vec[i];
		bestParaRemChromAber_antelope.exportAsTXTfile(temp_loc_antelope, tempName, true);
		vectoToExport_First.push_back(collectParameterRemoveChromaticAberrations(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitalizeBestParaRemoChromAber(reinizalizePercent, iniParaRemChromAber.getStepsThreshold() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_antelope, simImaMat_antelope, methodeImaProc);
		cv::Mat second_filterdIma_antelope = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_antelope + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_antelope, tempName, "png", second_filterdIma_antelope, iniParaRemChromAber.getCompateInPercent());

		bestParaRemChromAber second_bestParaTemChromAber_antelope = imaProcessingSuperFunction.getBestParaRemoveChromAber();

		tempName = second_filtered_antelope + "_" + namesSharpEvalMeth_vec[i];
		second_bestParaTemChromAber_antelope.exportAsTXTfile(temp_loc_antelope, tempName, true);

		vectoToExport_Second.push_back(collectParameterRemoveChromaticAberrations(imaProcessingSuperFunction));
		// *** *** //

		// *** dragonfly *** //
		std::cout << "improve dragonfly" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_dragonfly, simImaMat_dragonfly, methodeImaProc);
		cv::Mat filterdIma_dragonfly = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_dragonfly = loc_dragonfly + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_dragonfly, tempName, "png", filterdIma_dragonfly, iniParaRemChromAber.getCompateInPercent());

		bestParaRemChromAber bestParaRemChromAber_dragonfly = imaProcessingSuperFunction.getBestParaRemoveChromAber();

		tempName = filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i];
		bestParaRemChromAber_dragonfly.exportAsTXTfile(temp_loc_dragonfly, tempName, true);
		vectoToExport_First.push_back(collectParameterRemoveChromaticAberrations(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitalizeBestParaRemoChromAber(reinizalizePercent, iniParaRemChromAber.getStepsThreshold() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_dragonfly, simImaMat_dragonfly, methodeImaProc);
		cv::Mat second_filterdIma_dragonfly = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_dragonfly, tempName, "png", second_filterdIma_dragonfly, iniParaRemChromAber.getCompateInPercent());

		bestParaRemChromAber second_bestParaTemChromAber_dragonfly = imaProcessingSuperFunction.getBestParaRemoveChromAber();

		tempName = second_filtered_dragonfly + "_" + namesSharpEvalMeth_vec[i];
		second_bestParaTemChromAber_dragonfly.exportAsTXTfile(temp_loc_dragonfly, tempName, true);

		vectoToExport_Second.push_back(collectParameterRemoveChromaticAberrations(imaProcessingSuperFunction));
		// *** *** //

		// *** elefant *** //
		std::cout << "improve elefant" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant, methodeImaProc);
		cv::Mat filterdIma_elefant = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_elefant + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_elefant = loc_elefant + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_elefant, tempName, "png", filterdIma_elefant, iniParaRemChromAber.getCompateInPercent());

		bestParaRemChromAber bestParaRemChromAber_elefant = imaProcessingSuperFunction.getBestParaRemoveChromAber();

		tempName = filtered_elefant + "_" + namesSharpEvalMeth_vec[i];
		bestParaRemChromAber_elefant.exportAsTXTfile(temp_loc_elefant, tempName, true);
		vectoToExport_First.push_back(collectParameterRemoveChromaticAberrations(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitalizeBestParaRemoChromAber(reinizalizePercent, iniParaRemChromAber.getStepsThreshold() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant, methodeImaProc);
		cv::Mat second_filterdIma_elefant = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_elefant + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_elefant, tempName, "png", second_filterdIma_elefant, iniParaRemChromAber.getCompateInPercent());

		bestParaRemChromAber second_bestParaTemChromAber_elefant = imaProcessingSuperFunction.getBestParaRemoveChromAber();

		tempName = second_filtered_elefant + "_" + namesSharpEvalMeth_vec[i];
		second_bestParaTemChromAber_elefant.exportAsTXTfile(temp_loc_elefant, tempName, true);

		vectoToExport_Second.push_back(collectParameterRemoveChromaticAberrations(imaProcessingSuperFunction));
		// *** *** //

		// *** flower1 *** //
		std::cout << "improve flower1" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower1, simImaMat_flower1, methodeImaProc);
		cv::Mat filterdIma_flower1 = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_flower1 + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_flower1 = loc_flower1 + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower1, tempName, "png", filterdIma_flower1, iniParaRemChromAber.getCompateInPercent());

		bestParaRemChromAber bestParaRemChromAber_flower1 = imaProcessingSuperFunction.getBestParaRemoveChromAber();

		tempName = filtered_flower1 + "_" + namesSharpEvalMeth_vec[i];
		bestParaRemChromAber_flower1.exportAsTXTfile(temp_loc_flower1, tempName, true);
		vectoToExport_First.push_back(collectParameterRemoveChromaticAberrations(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitalizeBestParaRemoChromAber(reinizalizePercent, iniParaRemChromAber.getStepsThreshold() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower1, simImaMat_flower1, methodeImaProc);
		cv::Mat second_filterdIma_flower1 = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_flower1 + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower1, tempName, "png", second_filterdIma_flower1, iniParaRemChromAber.getCompateInPercent());

		bestParaRemChromAber second_bestParaTemChromAber_flower1 = imaProcessingSuperFunction.getBestParaRemoveChromAber();

		tempName = second_filtered_flower1 + "_" + namesSharpEvalMeth_vec[i];
		second_bestParaTemChromAber_flower1.exportAsTXTfile(temp_loc_flower1, tempName, true);

		vectoToExport_Second.push_back(collectParameterRemoveChromaticAberrations(imaProcessingSuperFunction));
		// *** *** //

		// *** flower2 *** //
		std::cout << "improve flower2" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower2, simImaMat_flower2, methodeImaProc);
		cv::Mat filterdIma_flower2 = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_flower2 + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_flower2 = loc_flower2 + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower2, tempName, "png", filterdIma_flower2, iniParaRemChromAber.getCompateInPercent());

		bestParaRemChromAber bestParaRemChromAber_flower2 = imaProcessingSuperFunction.getBestParaRemoveChromAber();

		tempName = filtered_flower2 + "_" + namesSharpEvalMeth_vec[i];
		bestParaRemChromAber_flower2.exportAsTXTfile(temp_loc_flower2, tempName, true);
		vectoToExport_First.push_back(collectParameterRemoveChromaticAberrations(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitalizeBestParaRemoChromAber(reinizalizePercent, iniParaRemChromAber.getStepsThreshold() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower2, simImaMat_flower2, methodeImaProc);
		cv::Mat second_filterdIma_flower2 = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_flower2 + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower2, tempName, "png", second_filterdIma_flower2, iniParaRemChromAber.getCompateInPercent());

		bestParaRemChromAber second_bestParaTemChromAber_flower2 = imaProcessingSuperFunction.getBestParaRemoveChromAber();

		tempName = second_filtered_flower2 + "_" + namesSharpEvalMeth_vec[i];
		second_bestParaTemChromAber_flower2.exportAsTXTfile(temp_loc_flower2, tempName, true);

		vectoToExport_Second.push_back(collectParameterRemoveChromaticAberrations(imaProcessingSuperFunction));
		// *** *** //

		// *** flower3 *** //
		std::cout << "improve flower3" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower3, simImaMat_flower3, methodeImaProc);
		cv::Mat filterdIma_flower3 = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_flower3 + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_flower3 = loc_flower3 + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower3, tempName, "png", filterdIma_flower3, iniParaRemChromAber.getCompateInPercent());

		bestParaRemChromAber bestParaRemChromAber_flower3 = imaProcessingSuperFunction.getBestParaRemoveChromAber();

		tempName = filtered_flower3 + "_" + namesSharpEvalMeth_vec[i];
		bestParaRemChromAber_flower3.exportAsTXTfile(temp_loc_flower3, tempName, true);
		vectoToExport_First.push_back(collectParameterRemoveChromaticAberrations(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitalizeBestParaRemoChromAber(reinizalizePercent, iniParaRemChromAber.getStepsThreshold() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower3, simImaMat_flower3, methodeImaProc);
		cv::Mat second_filterdIma_flower3 = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_flower3 + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_flower3, tempName, "png", second_filterdIma_flower3, iniParaRemChromAber.getCompateInPercent());

		bestParaRemChromAber second_bestParaTemChromAber_flower3 = imaProcessingSuperFunction.getBestParaRemoveChromAber();

		tempName = second_filtered_flower3 + "_" + namesSharpEvalMeth_vec[i];
		second_bestParaTemChromAber_flower3.exportAsTXTfile(temp_loc_flower3, tempName, true);

		vectoToExport_Second.push_back(collectParameterRemoveChromaticAberrations(imaProcessingSuperFunction));
		// *** *** //

		// *** landscape *** //
		std::cout << "improve landscape" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_landscape, simImaMat_landscape, methodeImaProc);
		cv::Mat filterdIma_landscape = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_landscape + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_landscape = loc_landscape + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_landscape, tempName, "png", filterdIma_landscape, iniParaRemChromAber.getCompateInPercent());

		bestParaRemChromAber bestParaRemChromAber_landscape = imaProcessingSuperFunction.getBestParaRemoveChromAber();

		tempName = filtered_landscape + "_" + namesSharpEvalMeth_vec[i];
		bestParaRemChromAber_landscape.exportAsTXTfile(temp_loc_landscape, tempName, true);
		vectoToExport_First.push_back(collectParameterRemoveChromaticAberrations(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitalizeBestParaRemoChromAber(reinizalizePercent, iniParaRemChromAber.getStepsThreshold() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_landscape, simImaMat_landscape, methodeImaProc);
		cv::Mat second_filterdIma_landscape = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_landscape + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_landscape, tempName, "png", second_filterdIma_landscape, iniParaRemChromAber.getCompateInPercent());

		bestParaRemChromAber second_bestParaTemChromAber_landscape = imaProcessingSuperFunction.getBestParaRemoveChromAber();

		tempName = second_filtered_landscape + "_" + namesSharpEvalMeth_vec[i];
		second_bestParaTemChromAber_landscape.exportAsTXTfile(temp_loc_landscape, tempName, true);

		vectoToExport_Second.push_back(collectParameterRemoveChromaticAberrations(imaProcessingSuperFunction));
		// *** *** //

		// *** pinguin *** //
		std::cout << "improve pinguin" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_pinguin, simImaMat_pinguin, methodeImaProc);
		cv::Mat filterdIma_pinguin = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_pinguin + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_pinguin = loc_pinguin + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_pinguin, tempName, "png", filterdIma_pinguin, iniParaRemChromAber.getCompateInPercent());

		bestParaRemChromAber bestParaRemChromAber_pinguin = imaProcessingSuperFunction.getBestParaRemoveChromAber();

		tempName = filtered_pinguin + "_" + namesSharpEvalMeth_vec[i];
		bestParaRemChromAber_pinguin.exportAsTXTfile(temp_loc_pinguin, tempName, true);
		vectoToExport_First.push_back(collectParameterRemoveChromaticAberrations(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitalizeBestParaRemoChromAber(reinizalizePercent, iniParaRemChromAber.getStepsThreshold() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_pinguin, simImaMat_pinguin, methodeImaProc);
		cv::Mat second_filterdIma_pinguin = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_pinguin + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_pinguin, tempName, "png", second_filterdIma_pinguin, iniParaRemChromAber.getCompateInPercent());

		bestParaRemChromAber second_bestParaTemChromAber_pinguin = imaProcessingSuperFunction.getBestParaRemoveChromAber();

		tempName = second_filtered_pinguin + "_" + namesSharpEvalMeth_vec[i];
		second_bestParaTemChromAber_pinguin.exportAsTXTfile(temp_loc_pinguin, tempName, true);

		vectoToExport_Second.push_back(collectParameterRemoveChromaticAberrations(imaProcessingSuperFunction));
		// *** *** //

		// *** rhino *** //
		std::cout << "improve rhino" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_rhino, simImaMat_rhino, methodeImaProc);
		cv::Mat filterdIma_rhino = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_rhino + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_rhino = loc_rhino + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_rhino, tempName, "png", filterdIma_rhino, iniParaRemChromAber.getCompateInPercent());

		bestParaRemChromAber bestParaRemChromAber_rhino = imaProcessingSuperFunction.getBestParaRemoveChromAber();

		tempName = filtered_rhino + "_" + namesSharpEvalMeth_vec[i];
		bestParaRemChromAber_rhino.exportAsTXTfile(temp_loc_rhino, tempName, true);
		vectoToExport_First.push_back(collectParameterRemoveChromaticAberrations(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitalizeBestParaRemoChromAber(reinizalizePercent, iniParaRemChromAber.getStepsThreshold() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_rhino, simImaMat_rhino, methodeImaProc);
		cv::Mat second_filterdIma_rhino = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_rhino + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_rhino, tempName, "png", second_filterdIma_rhino, iniParaRemChromAber.getCompateInPercent());

		bestParaRemChromAber second_bestParaTemChromAber_rhino = imaProcessingSuperFunction.getBestParaRemoveChromAber();

		tempName = second_filtered_rhino + "_" + namesSharpEvalMeth_vec[i];
		second_bestParaTemChromAber_rhino.exportAsTXTfile(temp_loc_rhino, tempName, true);

		vectoToExport_Second.push_back(collectParameterRemoveChromaticAberrations(imaProcessingSuperFunction));
		// *** *** //

		// *** salad *** //
		std::cout << "improve salad" << std::endl;

		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_salad, simImaMat_salad, methodeImaProc);
		cv::Mat filterdIma_salad = imaProcessingSuperFunction.getFilteredIma();
		tempName = filtered_salad + "_" + namesSharpEvalMeth_vec[i];
		std::string temp_loc_salad = loc_salad + "/" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_salad, tempName, "png", filterdIma_salad, iniParaRemChromAber.getCompateInPercent());

		bestParaRemChromAber bestParaRemChromAber_salad = imaProcessingSuperFunction.getBestParaRemoveChromAber();

		tempName = filtered_salad + "_" + namesSharpEvalMeth_vec[i];
		bestParaRemChromAber_salad.exportAsTXTfile(temp_loc_salad, tempName, true);
		vectoToExport_First.push_back(collectParameterRemoveChromaticAberrations(imaProcessingSuperFunction));


		imaProcessingSuperFunction.reinitalizeBestParaRemoChromAber(reinizalizePercent, iniParaRemChromAber.getStepsThreshold() / devideStepsByFactorForSecondSearch);
		imaProcessingSuperFunction.ImageProcessingSuperFunction(object_salad, simImaMat_salad, methodeImaProc);
		cv::Mat second_filterdIma_salad = imaProcessingSuperFunction.getFilteredIma();
		tempName = second_filtered_salad + "_" + namesSharpEvalMeth_vec[i];
		Images::saveImage_inputUN8C3_normByROI_percent(temp_loc_salad, tempName, "png", second_filterdIma_salad, iniParaRemChromAber.getCompateInPercent());

		bestParaRemChromAber second_bestParaTemChromAber_salad = imaProcessingSuperFunction.getBestParaRemoveChromAber();

		tempName = second_filtered_salad + "_" + namesSharpEvalMeth_vec[i];
		second_bestParaTemChromAber_salad.exportAsTXTfile(temp_loc_salad, tempName, true);

		vectoToExport_Second.push_back(collectParameterRemoveChromaticAberrations(imaProcessingSuperFunction));
		// *** *** //

	}

	// export all data to csv
	// ***
	unsigned int numberDatas = vectoToExport_First.size();
	unsigned int numberShaprEvalMeth = namesSharpEvalMeth_vec.size();
	unsigned int numberImages = numberDatas / numberShaprEvalMeth;


	// first interation
	unsigned int tempPos_first = 0;
	std::string firstIteration = "allData_First_RemoveChromaticAber_ImpImaQualSupFct_E3";
	inportExportData::removeDateCSV(locationE3, firstIteration);
	for (unsigned int i = 0; i < numberShaprEvalMeth; ++i)
	{
		inportExportData::exportDataToExcel(locationE3, firstIteration, namesSharpEvalMeth_vec[i], 0.0);
		for (unsigned int k = 0; k < numberImages; ++k)
		{
			inportExportData::exportDataToExcel_vector(locationE3, firstIteration, stringToExport, vectoToExport_First[tempPos_first]);
			++tempPos_first;
		}

	}


	// second iteration
	unsigned int tempPos_second = 0;
	std::string secondIteration = "allData_Second_RemoveChromaticAber_ImpImaQualSupFct_E3";
	for (unsigned int i = 0; i < numberShaprEvalMeth; ++i)
	{
		inportExportData::exportDataToExcel(locationE3, secondIteration, namesSharpEvalMeth_vec[i], 0.0);
		for (unsigned int k = 0; k < numberImages; ++k)
		{
			inportExportData::exportDataToExcel_vector(locationE3, secondIteration, stringToExport, vectoToExport_Second[tempPos_second]);
			++tempPos_second;
		}

	}


	// load object
	// sharp image
	cv::Mat chessboardSharp = cv::imread("../images/color/useThatImages/useThat/chessboard12x8.png", CV_LOAD_IMAGE_COLOR);
	// bluered image
	cv::Mat chessboardBluered = cv::imread("../images/color/useThatImages/useThat/sinImaChessboard12x8.png", CV_LOAD_IMAGE_COLOR);
	// *** chessboard *** //
	std::cout << "improve chessboard" << std::endl;

	imaProcessingSuperFunction.ImageProcessingSuperFunction(chessboardSharp, chessboardBluered, methodeImaProc);
	cv::Mat filterdIma_chessboard = imaProcessingSuperFunction.getFilteredIma();
	std::string loc_chessboard = "../tests/testImproveImageQuality/improveImaQuality_superFct/E3/chessboard";
	Images::saveImage_inputUN8C3_normByROI_percent(loc_chessboard, "filterdIma_chessboard", "png", filterdIma_chessboard, iniParaRemChromAber.getCompateInPercent());

	bestParaRemChromAber bestParaRemChromAber_chessboard = imaProcessingSuperFunction.getBestParaRemoveChromAber();
	bestParaRemChromAber_chessboard.exportAsTXTfile(loc_chessboard, "bestPara_chessboard", true);

	//// *** test chessboard ***
	//initialPararemChromAber iniParaRemChromAber_test;
	//iniParaRemChromAber_test.setMinThreshold(-100);
	//iniParaRemChromAber_test.setMaxThreshold(100);
	//iniParaRemChromAber_test.setStepsThreshold(1000);
	//iniParaRemChromAber_test.setCompateInPercent(0.0);
	//
	//RemoveChromaticAberrations remChromAber;
	//remChromAber.setInitialParameter(iniParaRemChromAber_test);
	//remChromAber.removeChromaticAberrations_superFct(chessboardSharp, chessboardBluered);
	//
	//bestParaRemChromAber bestPara = remChromAber.getBestParameter();
	//cv::Mat bestFilteredIma = bestPara.getImage();
	//bestPara.exportAsTXTfile(loc_chessboard, "bestParaTest0", true);
	//Images::saveImage_inputUN8C3_normByROI_percent(loc_chessboard, "filterdIma_chessboard_test", "png", bestFilteredIma, iniParaRemChromAber.getCompateInPercent());

	// *** *** //

		// *** *** //
	bool checker = vectoToExport_First.size() == vectoToExport_Second.size();
	// *** *** //
	return checker;


}

// test 4
bool testImproveImageQuality::testImaQual_E4_UnsMas_gray()
{
	std::string locationE4 = "../tests/testImproveImageQuality/improveImaQuality_superFct/E4";
	// load images
	cv::Mat sharpImaSaladGray = Images::loadAnImage_Gray(locationE4, "salad_900x900_gray");
	cv::Mat blueredImaSaladGray = Images::loadAnImage_Gray(locationE4, "simIma_salad_gray");

	// gray
	parameterUnsharpMasking paraUM_gray;
	paraUM_gray.setMinSigma(0.1);
	paraUM_gray.setMaxSigma(20.0);
	paraUM_gray.setStepsSigma(200.0);
	//paraUM_gray.setStepsSigma(10.0);
	paraUM_gray.setMinThreshold(0.01);
	paraUM_gray.setMaxThreshold(5.0);
	paraUM_gray.setStepsThreshold(200.0);
	//paraUM_gray.setStepsThreshold(10.0);
	paraUM_gray.setMinAmount(0.01);
	paraUM_gray.setMaxAmount(10.0);
	paraUM_gray.setStepsAmount(200.0);
	//paraUM_gray.setStepsAmount(10.0);
	paraUM_gray.setBoarderType(cv::BORDER_DEFAULT);
	paraUM_gray.setCompareInPercent(0.0);

	// *** parameter detail enhancement ***///
	imageProcessing methodeImaProc = imageProcessing::unsharpMasking24_gray;
	paraUM_gray.setSharpnessEvalMethode(sharpnessEvalMethode::sharpImage);

	// *** set the parameters
	ImaProcSuperFct imaProcessingSuperFunction;
	imaProcessingSuperFunction.setParameterUnsMas_gray(paraUM_gray);

	// first iteration
	imaProcessingSuperFunction.ImageProcessingSuperFunction(sharpImaSaladGray, blueredImaSaladGray, methodeImaProc);
	bestParameterStruct_unsharpMask bestParaUM_first_gray = imaProcessingSuperFunction.getBestParaUnsMas_gray();
	cv::Mat bestImaGray_first = bestParaUM_first_gray.getImage();
	Images::saveImage_normalized(locationE4, "firstSharpIma", "png", bestImaGray_first);
	bestParaUM_first_gray.exportAsTXTfile(locationE4, "firstInteration_UM_gray", true);

	//second interation
	imaProcessingSuperFunction.reinitializeBestParaUnsMas_gray(20.0, paraUM_gray.getStepsSigma(), paraUM_gray.getStepsThreshold(), paraUM_gray.getStepsAmount());
	imaProcessingSuperFunction.ImageProcessingSuperFunction(sharpImaSaladGray, blueredImaSaladGray, methodeImaProc);
	bestParameterStruct_unsharpMask bestParaUM_second_gray = imaProcessingSuperFunction.getBestParaUnsMas_gray();
	cv::Mat bestImaGray_second = bestParaUM_second_gray.getImage();
	Images::saveImage_normalized(locationE4, "secondSharpIma", "png", bestImaGray_second);
	bestParaUM_second_gray.exportAsTXTfile(locationE4, "secondInteration_UM_gray", true);
	//
	real sigma = bestParaUM_second_gray.getSigma();
	real threshold = bestParaUM_second_gray.getThreshold();
	real amount = bestParaUM_second_gray.getAmount();

	//real sigma = 3.2424;
	//real threshold = 0.626188;
	//real amount = 1.65724;

	// unsharp masking 
	cv::Mat bluerdForUnsharpMasking;
	cv::Mat lowContrastMask;
	cv::Mat tempFilterdImage;
	cv::GaussianBlur(blueredImaSaladGray, bluerdForUnsharpMasking, cv::Size(0, 0), sigma, sigma);
	lowContrastMask = cv::abs(blueredImaSaladGray - bluerdForUnsharpMasking) < threshold;
	tempFilterdImage = blueredImaSaladGray * (1 + amount) + bluerdForUnsharpMasking * (-amount);
	blueredImaSaladGray.copyTo(tempFilterdImage, lowContrastMask);

	// save images
	Images::saveImage_normalized(locationE4, "lowContrastMask", "png", lowContrastMask);
	Images::saveImage_normalized(locationE4, "tempFilterdImage", "png", tempFilterdImage);
	Images::saveImage_normalized(locationE4, "blueredImaSaladGray", "png", blueredImaSaladGray);


	return true;
}

// test 5
bool testImproveImageQuality::testImaQual_E5_Flower2_UnsMas_DetEnh_WD_24()
{
	bool debugVersion = true;

	std::string locationE5_first = "../tests/testImproveImageQuality/improveImaQuality_superFct/E5/first";

	// *** names objects *** // 
	std::string flower2 = "flower2_900x900";
	std::string pinguin = "pinguin_900x900";

	// *** names filtered images *** //
	std::string filtered_flower2 = "filtered_flower2";
	std::string second_filtered_flower2 = "second_filtered_flower2";	
	std::string filtered_pinguin = "filtered_pinguins";
	std::string second_filtered_pinguin = "second_filtered_pinguins";


	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";	
	cv::Mat object_flower2 = Images::loadAnImage_Color(loactionObject, flower2);
	cv::Mat object_pinguin = Images::loadAnImage_Color(loactionObject, pinguin);


	// *** names simulated images *** //
	std::string locationImages = "../tests/testImageSimulation/S12";
	std::string simIma_flower2 = "simIma_flower2";
	std::string simIma_pinguin = "simIma_pinguin";

	// *** load simulated images *** //
	cv::Mat  simImaMat_flower2 = Images::loadAnImage_Color(locationImages, simIma_flower2);
	cv::Mat  simImaMat_pinguin = Images::loadAnImage_Color(locationImages, simIma_pinguin);

	imageProcessing methodeImaProc = imageProcessing::unshMas_DetailEnh_WienerDec_24;

	// *** parameter unsharp masking ***//
	// blue
	parameterUnsharpMasking paraUM_blue;
	paraUM_blue.setMinSigma(0.1);
	paraUM_blue.setMaxSigma(20.0);
	
	paraUM_blue.setMinThreshold(0.01);
	paraUM_blue.setMaxThreshold(5.0);
	
	paraUM_blue.setMinAmount(0.01);
	paraUM_blue.setMaxAmount(10.0);
	
	if (debugVersion)
	{
		paraUM_blue.setStepsSigma(5.0);
		paraUM_blue.setStepsThreshold(5.0);
		paraUM_blue.setStepsAmount(5.0);
	}
	else
	{
		paraUM_blue.setStepsSigma(100.0);
		paraUM_blue.setStepsThreshold(100.0);
		paraUM_blue.setStepsAmount(100.0);
	}

	paraUM_blue.setBoarderType(cv::BORDER_DEFAULT);
	paraUM_blue.setCompareInPercent(0.0);
	// green
	parameterUnsharpMasking paraUM_green = paraUM_blue;
	// red
	parameterUnsharpMasking paraUM_red = paraUM_blue;
	// ***

	// *** parameter DE 
	parameterDetailEnhancement paraDE;
	paraDE.setMinSigma_r(0.001);
	paraDE.setMaxSigma_r(100.0);
	
	paraDE.setMinSigma_s(1.0);
	paraDE.setMaxSigma_s(100.0);
	
	paraDE.setPercentCompare(0.0);

	if (debugVersion)
	{
		paraDE.setStepsSigma_r(20.0);
		paraDE.setStepsSigma_s(20.0);
	}
	else
	{
		paraDE.setStepsSigma_r(200.0);
		paraDE.setStepsSigma_s(200.0);
	}

	// *** parameter wiener filter *** 
	// *** parameter blue *** 
	parameterImaImprove_WD paraWD_blue{};
	paraWD_blue.setMinSNR(0.1);
	paraWD_blue.setMaxSNR(200.0);
	
	

	paraWD_blue.setMinSigmaXY(0.1);
	paraWD_blue.setMaxSigmaXY(5.0);
	
	

	paraWD_blue.setKernelSizeHeightAndWidth(30);
	paraWD_blue.setCompareInPercent(0.0);

	if (debugVersion)
	{
		paraWD_blue.setStepsSNR(20.0);
		paraWD_blue.setStepsSigmaXY(20.0);
	}
	else
	{
		paraWD_blue.setStepsSNR(200.0);
		paraWD_blue.setStepsSigmaXY(200.0);
	}

	// *** parameter green
	parameterImaImprove_WD paraWD_green{};
	paraWD_green = paraWD_blue;
	// *** parameter red
	parameterImaImprove_WD paraWD_red{};
	paraWD_red = paraWD_blue;
	//  ***  *** //

	// sharpness evaluation methode
	sharpnessEvalMethode tempShapEvalMethode = sharpnessEvalMethode::sharpImage;
	paraUM_blue.setSharpnessEvalMethode(tempShapEvalMethode);
	paraUM_green.setSharpnessEvalMethode(tempShapEvalMethode);
	paraUM_red.setSharpnessEvalMethode(tempShapEvalMethode);
	paraDE.setSharpnessEvalMethode(tempShapEvalMethode);
	paraWD_blue.setSharpnessEvalMethode(tempShapEvalMethode);
	paraWD_green.setSharpnessEvalMethode(tempShapEvalMethode);
	paraWD_red.setSharpnessEvalMethode(tempShapEvalMethode);

	// set parameter
	ImaProcSuperFct imaProcessingSuperFunction;
	imaProcessingSuperFunction.setParameterUnsMas_blue(paraUM_blue);
	imaProcessingSuperFunction.setParameterUnsMas_green(paraUM_green);
	imaProcessingSuperFunction.setParameterUnsMas_red(paraUM_red);
	imaProcessingSuperFunction.setParameterDetEnh(paraDE);
	imaProcessingSuperFunction.setParameterWD_blue(paraWD_blue);
	imaProcessingSuperFunction.setParameterWD_green(paraWD_green);
	imaProcessingSuperFunction.setParameterWD_red(paraWD_red);

	// *** flower2 *** //
	std::cout << "improve flower2" << std::endl;

	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower2, simImaMat_flower2, methodeImaProc);

	// *** UM
	std::string firstUM = "first_UM_Flower2";
	std::string stringToExport_UM = "sigma_blue, threshold_blue, amount_blue, imp_blue, sigma_green, threshold_green, amount_green, imp_green, sigma_red, threshold_red, amount_red, imp_red, imp_total, bestCoreNumber_blue, bestCoreNumber_green, bestCoreNumber_red";
	std::vector<std::vector<real>> vectoToExport_first_UM{};
	cv::Mat filteredIma_UM_first = imaProcessingSuperFunction.getAllFilteredImages_UM_DE_WD()[0];
	vectoToExport_first_UM.push_back(collectParameterUnsharpMasking(imaProcessingSuperFunction));
	Images::saveImage_inputUN8C3_normByROI_percent(locationE5_first, firstUM, "png", filteredIma_UM_first, paraUM_blue.getCompareInPercent());
	inportExportData::removeDateCSV(locationE5_first, firstUM);
	inportExportData::exportDataToExcel_vector(locationE5_first, firstUM, stringToExport_UM, vectoToExport_first_UM[0]);

	// *** DE
	std::string firstDE = "first_DE_Flower2";
	std::string stringToExport_DE = "sigma_r, sigma_s, imp_total, bestCoreNum";
	std::vector<std::vector<real>> vectoToExport_first_DE{};
	cv::Mat filteredIma_DE_first = imaProcessingSuperFunction.getAllFilteredImages_UM_DE_WD()[1];
	vectoToExport_first_DE.push_back(collectParameterDetailEnhancement(imaProcessingSuperFunction));
	Images::saveImage_inputUN8C3_normByROI_percent(locationE5_first, firstDE, "png", filteredIma_DE_first, paraDE.getPercentCompare());
	inportExportData::removeDateCSV(locationE5_first, firstDE);
	inportExportData::exportDataToExcel_vector(locationE5_first, firstDE, stringToExport_DE, vectoToExport_first_DE[0]);

	// *** WD
	std::string firstWD = "first_WD_Flower2";
	std::string stringToExport_WD = "sigma_blue, SNR_blue, imp_blue, sigma_green, SNR_green, imp_green, sigma_red, SNR_red, imp_red, imp_total, bestCoreNum_blue, bestCoreNum_green, bestCoreNum_red";
	std::vector<std::vector<real>> vectoToExport_first_WD{};
	cv::Mat filteredIma_WD_first = imaProcessingSuperFunction.getAllFilteredImages_UM_DE_WD()[2];
	vectoToExport_first_WD.push_back(collectParameterWD(imaProcessingSuperFunction));
	Images::saveImage_inputUN8C3_normByROI_percent(locationE5_first, firstWD, "png", filteredIma_WD_first, paraWD_blue.getCompareInPercent());
	inportExportData::removeDateCSV(locationE5_first, firstWD);
	inportExportData::exportDataToExcel_vector(locationE5_first, firstWD, stringToExport_WD, vectoToExport_first_WD[0]);
	// *** *** //

	// calculate improvements
	// debug
	Images::showImage_inputUint8("object", object_flower2);
	Images::showImage_inputUint8("sim ima", simImaMat_flower2);
	Images::showImage_inputUint8("filtered ima", filteredIma_UM_first);

	real improvementUM = Images::calcImprovementBGR(object_flower2, simImaMat_flower2, filteredIma_UM_first, paraUM_blue.getCompareInPercent());
	real improvementDE = Images::calcImprovementBGR(object_flower2, filteredIma_UM_first, filteredIma_DE_first, paraDE.getPercentCompare());
	real improvementWD = Images::calcImprovementBGR(object_flower2, filteredIma_DE_first, filteredIma_WD_first, paraWD_blue.getCompareInPercent());
	// export improvements
	inportExportData::removeDateCSV(locationE5_first, "improvementsFirst");
	inportExportData::exportDataToExcel(locationE5_first, "improvementsFirst", "improvement UM", improvementUM);
	inportExportData::exportDataToExcel(locationE5_first, "improvementsFirst", "improvement DE", improvementDE);
	inportExportData::exportDataToExcel(locationE5_first, "improvementsFirst", "improvement WD", improvementWD);




	return true;

}



// collect function
std::vector<real> testImproveImageQuality::collectParameterWD(ImaProcSuperFct imaProcSuperFct)
{

	saveBestParameterWD bestParaWD_blue = imaProcSuperFct.getBestParaWD_blue();
	saveBestParameterWD bestParaWD_green = imaProcSuperFct.getBestParaWD_green();
	saveBestParameterWD bestParaWD_red = imaProcSuperFct.getBestParaWD_red();
	cv::Mat object = imaProcSuperFct.getInputIma();
	cv::Mat blueredIma = imaProcSuperFct.getBlueredIma();
	cv::Mat filteredIma = imaProcSuperFct.getFilteredIma();
	real comPercent = imaProcSuperFct.getParameterWD_blue().getCompareInPercent();

	cv::normalize(object, object, 0, 255, cv::NORM_MINMAX, CV_8UC3);
	cv::normalize(blueredIma, blueredIma, 0, 255, cv::NORM_MINMAX, CV_8UC3);
	cv::normalize(filteredIma, filteredIma, 0, 255, cv::NORM_MINMAX, CV_8UC3);

	// debug
	// Images::showImage_inputUint8("object", object);
	// Images::showImage_inputUint8("blueredIma", blueredIma);
	// Images::showImage_inputUint8("filteredIma", filteredIma);

	std::vector<real> bestParameter;

	// blue
	real sigma_blue = bestParaWD_blue.getBestSigma();
	bestParameter.push_back(sigma_blue);
	real SNR_blue = bestParaWD_blue.getBestSNR();
	bestParameter.push_back(SNR_blue);
	real imp_blue = bestParaWD_blue.getImprovement();
	bestParameter.push_back(imp_blue);

	// green
	real sigma_green = bestParaWD_green.getBestSigma();
	bestParameter.push_back(sigma_green);
	real SNR_green = bestParaWD_green.getBestSNR();
	bestParameter.push_back(SNR_green);
	real imp_green = bestParaWD_green.getImprovement();
	bestParameter.push_back(imp_green);

	// red
	real sigma_red = bestParaWD_red.getBestSigma();
	bestParameter.push_back(sigma_red);
	real SNR_red = bestParaWD_red.getBestSNR();
	bestParameter.push_back(SNR_red);
	real imp_red = bestParaWD_red.getImprovement();
	bestParameter.push_back(imp_red);

	// total improvement
	real totalImp = Images::calcImprovementBGR(object, blueredIma, filteredIma, comPercent);
	bestParameter.push_back(totalImp);

	// best core number
	int bestCoreNumber_blue = bestParaWD_blue.getBestCoreNum();
	int bestCoreNumber_green = bestParaWD_green.getBestCoreNum();
	int bestCoreNumber_red = bestParaWD_red.getBestCoreNum();

	bestParameter.push_back(bestCoreNumber_blue);
	bestParameter.push_back(bestCoreNumber_green);
	bestParameter.push_back(bestCoreNumber_red);

	return bestParameter;
}

std::vector<real> testImproveImageQuality::collectParameterUnsharpMasking(ImaProcSuperFct imaProcSuperFct)
{
	bestParameterStruct_unsharpMask bestParaUnsMas_blue = imaProcSuperFct.getBestParaUnsMas_blue();
	bestParameterStruct_unsharpMask bestParaUnsMas_green = imaProcSuperFct.getBestParaUnsMas_green();
	bestParameterStruct_unsharpMask bestParaUnsMas_red = imaProcSuperFct.getBestParaUnsMas_red();
	cv::Mat object = imaProcSuperFct.getInputIma();
	cv::Mat blueredIma = imaProcSuperFct.getBlueredIma();
	cv::Mat filteredIma = imaProcSuperFct.getFilteredIma();
	real comPercent = imaProcSuperFct.getParameterUnsMas_blue().getCompareInPercent();

	cv::normalize(object, object, 0, 255, cv::NORM_MINMAX, CV_8UC3);
	cv::normalize(blueredIma, blueredIma, 0, 255, cv::NORM_MINMAX, CV_8UC3);
	cv::normalize(filteredIma, filteredIma, 0, 255, cv::NORM_MINMAX, CV_8UC3);

	// debug
	// Images::showImage_inputUint8("object", object);
	// Images::showImage_inputUint8("blueredIma", blueredIma);
	// Images::showImage_inputUint8("filteredIma", filteredIma);

	std::vector<real> bestParameter;

	// blue
	real sigma_blue = bestParaUnsMas_blue.getSigma();
	bestParameter.push_back(sigma_blue);
	real threshold_blue = bestParaUnsMas_blue.getThreshold();
	bestParameter.push_back(threshold_blue);
	real amount_blue = bestParaUnsMas_blue.getAmount();
	bestParameter.push_back(amount_blue);
	real imp_blue = bestParaUnsMas_blue.getImprovement();
	bestParameter.push_back(imp_blue);

	// green
	real sigma_green = bestParaUnsMas_green.getSigma();
	bestParameter.push_back(sigma_green);
	real threshold_green = bestParaUnsMas_green.getThreshold();
	bestParameter.push_back(threshold_green);
	real amount_green = bestParaUnsMas_green.getAmount();
	bestParameter.push_back(amount_green);
	real imp_green = bestParaUnsMas_green.getImprovement();
	bestParameter.push_back(imp_green);

	// red
	real sigma_red = bestParaUnsMas_red.getSigma();
	bestParameter.push_back(sigma_red);
	real threshold_red = bestParaUnsMas_red.getThreshold();
	bestParameter.push_back(threshold_red);
	real amount_red = bestParaUnsMas_red.getAmount();
	bestParameter.push_back(amount_red);
	real imp_red = bestParaUnsMas_red.getImprovement();
	bestParameter.push_back(imp_red);

	// total improvement
	real totalImp = Images::calcImprovementBGR(object, blueredIma, filteredIma, comPercent);
	bestParameter.push_back(totalImp);

	// best cores
	int bestCore_blue = bestParaUnsMas_blue.getBestCoreNumber();
	int bestCore_green = bestParaUnsMas_green.getBestCoreNumber();
	int bestCore_red = bestParaUnsMas_red.getBestCoreNumber();

	bestParameter.push_back(bestCore_blue);
	bestParameter.push_back(bestCore_green);
	bestParameter.push_back(bestCore_red);


	return bestParameter;
}

std::vector<real> testImproveImageQuality::collectParameterDetailEnhancement(ImaProcSuperFct imaProcSuperFct)
{
	bestParameterStruct_detailEnhance bestParaDetEnh = imaProcSuperFct.getBestParaDetEnh();

	cv::Mat object = imaProcSuperFct.getInputIma();
	cv::Mat blueredIma = imaProcSuperFct.getBlueredIma();
	cv::Mat filteredIma = imaProcSuperFct.getFilteredIma();
	real comPercent = imaProcSuperFct.getParameterDetEnh().getPercentCompare();

	cv::normalize(object, object, 0, 255, cv::NORM_MINMAX, CV_8UC3);
	cv::normalize(blueredIma, blueredIma, 0, 255, cv::NORM_MINMAX, CV_8UC3);
	cv::normalize(filteredIma, filteredIma, 0, 255, cv::NORM_MINMAX, CV_8UC3);

	std::vector<real> bestParameter;

	real sigma_r = bestParaDetEnh.getSigmar_r();
	bestParameter.push_back(sigma_r);
	real sigma_s = bestParaDetEnh.getSigmar_s();
	bestParameter.push_back(sigma_s);

	// total improvement
	real totalImp = bestParaDetEnh.getImprovement();
	bestParameter.push_back(totalImp);

	// best core number
	int bestCoreNum = bestParaDetEnh.getbestCoreNumber();
	bestParameter.push_back(bestCoreNum);

	return bestParameter;
}

std::vector<real> testImproveImageQuality::collectParameterRemoveChromaticAberrations(ImaProcSuperFct imaProcSuperFct)
{
	bestParaRemChromAber bestParaRemChromAber = imaProcSuperFct.getBestParaRemoveChromAber();

	cv::Mat object = imaProcSuperFct.getInputIma();
	cv::Mat blueredIma = imaProcSuperFct.getBlueredIma();
	cv::Mat filteredIma = imaProcSuperFct.getFilteredIma();
	real comPercent = imaProcSuperFct.getParameterRemoveChromAber().getCompateInPercent();

	cv::normalize(object, object, 0, 255, cv::NORM_MINMAX, CV_8UC3);
	cv::normalize(blueredIma, blueredIma, 0, 255, cv::NORM_MINMAX, CV_8UC3);
	cv::normalize(filteredIma, filteredIma, 0, 255, cv::NORM_MINMAX, CV_8UC3);

	std::vector<real> bestParameter;

	real thresold = bestParaRemChromAber.getThreshold();
	bestParameter.push_back(thresold);

	// total improvement
	real totalImp = bestParaRemChromAber.getImprovement();
	bestParameter.push_back(totalImp);

	return bestParameter;
}

