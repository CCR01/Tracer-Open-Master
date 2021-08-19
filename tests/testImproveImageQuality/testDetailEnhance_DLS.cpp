#include "testDetailEnhance_DLS.h"
#include "..\..\ImageProcessing\DetailEnhance_DLS.h"

// important structs
#include "..\..\LowLevelTracing\ImportantStructures.h"

// math
#include "..\..\LowLevelTracing\Math_LLT.h"

// Images
#include "..\..\Image\Images.h"

testDetailEnhance_DLS_thisIsNotWorking::testDetailEnhance_DLS_thisIsNotWorking() {}

testDetailEnhance_DLS_thisIsNotWorking::~testDetailEnhance_DLS_thisIsNotWorking() {}

bool testDetailEnhance_DLS_thisIsNotWorking::testDetailEnhanceDLS_superFunction()
{
	std::vector<bool> testSuperFct_vec;

	// testE0
	bool checkE0 = testE0();
	testSuperFct_vec.push_back(checkE0);

	bool returnChecker = Math::checkTrueOfVectorElements(testSuperFct_vec);
	return returnChecker;

}

// E0
bool testDetailEnhance_DLS_thisIsNotWorking::testE0()
{
	std::vector<bool> test_vec;
	std::string loactionColorImages = "../images/color/useThatImages/useThat/";

	// load sharp image
	std::string nameSharpIma = "elefant_250x250.png";
	cv::Mat sharpIma = Images::loadAnImage_Color(loactionColorImages, nameSharpIma);
	// load blured image
	std::string nameBluredIma = "simIma250x250.png";
	cv::Mat bluredIma = Images::loadAnImage_Color(loactionColorImages, nameBluredIma);

	DetailEnhance_DLS_ThisIsNOTworking detailEnh_DLS;
	detailEnh_DLS.detailEnhanceSuperFunc_DLS(/*blured image*/ bluredIma, /*sharp image*/ sharpIma);

	cv::Mat detailEnhIma = detailEnh_DLS.getDetailEnhanceIma();

	real improvement = Images::calcImprovement_noNorming(sharpIma, bluredIma, detailEnhIma);
	std::cout << "improvement: " << improvement << std::endl;
 
	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;

}