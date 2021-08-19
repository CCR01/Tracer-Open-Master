#include "testSharpnessEvaluation.h"

// sharpness evaluation
#include "..\..\Image\SharpnessEvaluation.h"

// important structs
#include "..\..\LowLevelTracing\ImportantStructures.h"

// math
#include "..\..\LowLevelTracing\Math_LLT.h"



#include <iostream>
//#include <vector>

testSharpnessEvaluation::testSharpnessEvaluation() { loadImages(); }
testSharpnessEvaluation::~testSharpnessEvaluation() {}

// load all images
void testSharpnessEvaluation::loadImages()
{

	// location objects
	std::string locObj = "../images/color/testImaSim_test12";
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

	// *** names simulated images *** //
	std::string locationImages = "../tests/testImageSimulation/S12";
	std::string simImaName_antelope = "simIma_antelope";
	std::string simImaName_dragonfly = "simIma_dragonfly";
	std::string simImaName_elefant = "simIma_elefant";
	std::string simImaName_flower1 = "simIma_flower1";
	std::string simImaName_flower2 = "simIma_flower2";
	std::string simImaName_flower3 = "simIma_flower3";
	std::string simImaName_landscape = "simIma_landscape";
	std::string simImaName_pinguin = "simIma_pinguin";
	std::string simImaName_rhino = "simIma_rhino";
	std::string simImaName_salad = "simIma_salad";

	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	object_antelope = Images::loadAnImage_Color(loactionObject, antelope);
	object_dragonfly = Images::loadAnImage_Color(loactionObject, dragonfly);
	object_elefant = Images::loadAnImage_Color(loactionObject, elefant);
	object_flower1 = Images::loadAnImage_Color(loactionObject, flower1);
	object_flower2 = Images::loadAnImage_Color(loactionObject, flower2);
	object_flower3 = Images::loadAnImage_Color(loactionObject, flower3);
	object_landscape = Images::loadAnImage_Color(loactionObject, landscape);
	object_pinguin = Images::loadAnImage_Color(loactionObject, pinguin);
	object_rhino = Images::loadAnImage_Color(loactionObject, rhino);
	object_salad = Images::loadAnImage_Color(loactionObject, salad);

	// *** load simulated images *** //
	simIma_antelope = Images::loadAnImage_Color(locationImages, simImaName_antelope);
	simIma_dragonfly = Images::loadAnImage_Color(locationImages, simImaName_dragonfly);
	simIma_elefant = Images::loadAnImage_Color(locationImages, simImaName_elefant);
	simIma_flower1 = Images::loadAnImage_Color(locationImages, simImaName_flower1);
	simIma_flower2 = Images::loadAnImage_Color(locationImages, simImaName_flower2);
	simIma_flower3 = Images::loadAnImage_Color(locationImages, simImaName_flower3);
	simIma_landscape = Images::loadAnImage_Color(locationImages, simImaName_landscape);
	simIma_pinguin = Images::loadAnImage_Color(locationImages, simImaName_pinguin);
	simIma_rhino = Images::loadAnImage_Color(locationImages, simImaName_rhino);
	simIma_salad = Images::loadAnImage_Color(locationImages, simImaName_salad);
}

// test sharpness evaluation super function
bool testSharpnessEvaluation::testSharpnessEvaluation_superFct()
{
	std::vector<bool> workTheSystem;
	
	// test brenner
	bool checkBrenner = test_brenner();
	workTheSystem.push_back(checkBrenner);

	// test tennegrad
	bool checkTennegrad = test_tennegrad();
	workTheSystem.push_back(checkTennegrad);

	// test laplacian
	bool checkLaplacian = test_laplacian();
	workTheSystem.push_back(checkLaplacian);

	// test SMD
	bool checkSMD = test_SMD();
	workTheSystem.push_back(checkSMD);

	// test SMD2
	bool checkSMD2 = test_SMD2();
	workTheSystem.push_back(checkSMD2);

	// test energy gradient function
	bool checkEnergyGradFct = testEnergyGradFct();
	workTheSystem.push_back(checkEnergyGradFct);

	// test EVA
	bool checkEVA = test_EVA();
	workTheSystem.push_back(checkEVA);

	// test NRSS
	bool checkNRSS = test_NRSS();
	workTheSystem.push_back(checkNRSS);

	// blur noise IQA
	bool checkIQA = test_blur_noise_IQA();
	workTheSystem.push_back(checkIQA);


	bool checkSharpEval = Math::checkTrueOfVectorElements(workTheSystem);
	return checkSharpEval;
}
// test brenner
bool testSharpnessEvaluation::test_brenner()
{
	std::vector<bool> workTheSystem;

	SharpnessEvaluation sharpEval;
	// *** antelope ***
	real obj_antelope_sharpEval = sharpEval.sharpnessEval_brenner_colorUN(object_antelope);
	real ima_antelope_sharpEval = sharpEval.sharpnessEval_brenner_colorUN(simIma_antelope);
	bool checkSharpness_antelope = obj_antelope_sharpEval > ima_antelope_sharpEval;
	workTheSystem.push_back(checkSharpness_antelope);
	// *** *** 

	// *** dragonfly ***
	real obj_dragonfly_sharpEval = sharpEval.sharpnessEval_brenner_colorUN(object_dragonfly);
	real ima_dragonfly_sharpEval = sharpEval.sharpnessEval_brenner_colorUN(simIma_dragonfly);
	bool checkSharpness_dragonfly = obj_dragonfly_sharpEval > ima_dragonfly_sharpEval;
	workTheSystem.push_back(checkSharpness_dragonfly);
	// *** *** 

	// *** elefant ***
	real obj_elefant_sharpEval = sharpEval.sharpnessEval_brenner_colorUN(object_elefant);
	real ima_elefant_sharpEval = sharpEval.sharpnessEval_brenner_colorUN(simIma_elefant);
	bool checkSharpness_elefant = obj_elefant_sharpEval > ima_elefant_sharpEval;
	workTheSystem.push_back(checkSharpness_elefant);
	// *** *** 

	// *** flower1 ***
	real obj_flower1_sharpEval = sharpEval.sharpnessEval_brenner_colorUN(object_flower1);
	real ima_flower1_sharpEval = sharpEval.sharpnessEval_brenner_colorUN(simIma_flower1);
	bool checkSharpness_flower1 = obj_flower1_sharpEval > ima_flower1_sharpEval;
	workTheSystem.push_back(checkSharpness_flower1);
	// *** *** 

	// *** flower2 ***
	real obj_flower2_sharpEval = sharpEval.sharpnessEval_brenner_colorUN(object_flower2);
	real ima_flower2_sharpEval = sharpEval.sharpnessEval_brenner_colorUN(simIma_flower2);
	bool checkSharpness_flower2 = obj_flower2_sharpEval > ima_flower2_sharpEval;
	workTheSystem.push_back(checkSharpness_flower2);
	// *** *** 

	// *** flower3 ***
	real obj_flower3_sharpEval = sharpEval.sharpnessEval_brenner_colorUN(object_flower3);
	real ima_flower3_sharpEval = sharpEval.sharpnessEval_brenner_colorUN(simIma_flower3);
	bool checkSharpness_flower3 = obj_flower3_sharpEval > ima_flower3_sharpEval;
	workTheSystem.push_back(checkSharpness_flower3);
	// *** *** 

	// *** landscape ***
	real obj_landscape_sharpEval = sharpEval.sharpnessEval_brenner_colorUN(object_landscape);
	real ima_landscape_sharpEval = sharpEval.sharpnessEval_brenner_colorUN(simIma_landscape);
	bool checkSharpness_landscape = obj_landscape_sharpEval > ima_landscape_sharpEval;
	workTheSystem.push_back(checkSharpness_landscape);
	// *** *** 

	// *** pinguin ***
	real obj_pinguin_sharpEval = sharpEval.sharpnessEval_brenner_colorUN(object_pinguin);
	real ima_pinguin_sharpEval = sharpEval.sharpnessEval_brenner_colorUN(simIma_pinguin);
	bool checkSharpness_pinguin = obj_pinguin_sharpEval > ima_pinguin_sharpEval;
	workTheSystem.push_back(checkSharpness_pinguin);
	// *** *** 

	// *** rhino ***
	real obj_rhino_sharpEval = sharpEval.sharpnessEval_brenner_colorUN(object_rhino);
	real ima_rhino_sharpEval = sharpEval.sharpnessEval_brenner_colorUN(simIma_rhino);
	bool checkSharpness_rhino = obj_rhino_sharpEval > ima_rhino_sharpEval;
	workTheSystem.push_back(checkSharpness_rhino);
	// *** *** 

	// *** salad ***
	real obj_salad_sharpEval = sharpEval.sharpnessEval_brenner_colorUN(object_salad);
	real ima_salad_sharpEval = sharpEval.sharpnessEval_brenner_colorUN(simIma_salad);
	bool checkSharpness_salad = obj_salad_sharpEval > ima_salad_sharpEval;
	workTheSystem.push_back(checkSharpness_salad);
	// *** *** 

	bool checkTheSystem = Math::checkTrueOfVectorElements(workTheSystem);
	return checkTheSystem;

}

// test tennegrad
bool testSharpnessEvaluation::test_tennegrad()
{
	std::vector<bool> workTheSystem;

	SharpnessEvaluation sharpEval;
	// *** antelope ***
	real obj_antelope_sharpEval = sharpEval.sharpnessEval_tenegrad_colorUN(object_antelope);
	real ima_antelope_sharpEval = sharpEval.sharpnessEval_tenegrad_colorUN(simIma_antelope);
	bool checkSharpness_antelope = obj_antelope_sharpEval > ima_antelope_sharpEval;
	workTheSystem.push_back(checkSharpness_antelope);
	// *** *** 

	// *** dragonfly ***
	real obj_dragonfly_sharpEval = sharpEval.sharpnessEval_tenegrad_colorUN(object_dragonfly);
	real ima_dragonfly_sharpEval = sharpEval.sharpnessEval_tenegrad_colorUN(simIma_dragonfly);
	bool checkSharpness_dragonfly = obj_dragonfly_sharpEval > ima_dragonfly_sharpEval;
	workTheSystem.push_back(checkSharpness_dragonfly);
	// *** *** 

	// *** elefant ***
	real obj_elefant_sharpEval = sharpEval.sharpnessEval_tenegrad_colorUN(object_elefant);
	real ima_elefant_sharpEval = sharpEval.sharpnessEval_tenegrad_colorUN(simIma_elefant);
	bool checkSharpness_elefant = obj_elefant_sharpEval > ima_elefant_sharpEval;
	workTheSystem.push_back(checkSharpness_elefant);
	// *** *** 

	// *** flower1 ***
	real obj_flower1_sharpEval = sharpEval.sharpnessEval_tenegrad_colorUN(object_flower1);
	real ima_flower1_sharpEval = sharpEval.sharpnessEval_tenegrad_colorUN(simIma_flower1);
	bool checkSharpness_flower1 = obj_flower1_sharpEval > ima_flower1_sharpEval;
	workTheSystem.push_back(checkSharpness_flower1);
	// *** *** 

	// *** flower2 ***
	real obj_flower2_sharpEval = sharpEval.sharpnessEval_tenegrad_colorUN(object_flower2);
	real ima_flower2_sharpEval = sharpEval.sharpnessEval_tenegrad_colorUN(simIma_flower2);
	bool checkSharpness_flower2 = obj_flower2_sharpEval > ima_flower2_sharpEval;
	workTheSystem.push_back(checkSharpness_flower2);
	// *** *** 

	// *** flower3 ***
	real obj_flower3_sharpEval = sharpEval.sharpnessEval_tenegrad_colorUN(object_flower3);
	real ima_flower3_sharpEval = sharpEval.sharpnessEval_tenegrad_colorUN(simIma_flower3);
	bool checkSharpness_flower3 = obj_flower3_sharpEval > ima_flower3_sharpEval;
	workTheSystem.push_back(checkSharpness_flower3);
	// *** *** 

	// *** landscape ***
	real obj_landscape_sharpEval = sharpEval.sharpnessEval_tenegrad_colorUN(object_landscape);
	real ima_landscape_sharpEval = sharpEval.sharpnessEval_tenegrad_colorUN(simIma_landscape);
	bool checkSharpness_landscape = obj_landscape_sharpEval > ima_landscape_sharpEval;
	workTheSystem.push_back(checkSharpness_landscape);
	// *** *** 

	// *** pinguin ***
	real obj_pinguin_sharpEval = sharpEval.sharpnessEval_tenegrad_colorUN(object_pinguin);
	real ima_pinguin_sharpEval = sharpEval.sharpnessEval_tenegrad_colorUN(simIma_pinguin);
	bool checkSharpness_pinguin = obj_pinguin_sharpEval > ima_pinguin_sharpEval;
	workTheSystem.push_back(checkSharpness_pinguin);
	// *** *** 

	// *** rhino ***
	real obj_rhino_sharpEval = sharpEval.sharpnessEval_tenegrad_colorUN(object_rhino);
	real ima_rhino_sharpEval = sharpEval.sharpnessEval_tenegrad_colorUN(simIma_rhino);
	bool checkSharpness_rhino = obj_rhino_sharpEval > ima_rhino_sharpEval;
	workTheSystem.push_back(checkSharpness_rhino);
	// *** *** 

	// *** salad ***
	real obj_salad_sharpEval = sharpEval.sharpnessEval_tenegrad_colorUN(object_salad);
	real ima_salad_sharpEval = sharpEval.sharpnessEval_tenegrad_colorUN(simIma_salad);
	bool checkSharpness_salad = obj_salad_sharpEval > ima_salad_sharpEval;
	workTheSystem.push_back(checkSharpness_salad);
	// *** *** 

	bool checkTheSystem = Math::checkTrueOfVectorElements(workTheSystem);
	return checkTheSystem;
}

// test laplacian
bool testSharpnessEvaluation::test_laplacian()
{
	std::vector<bool> workTheSystem;

	SharpnessEvaluation sharpEval;
	// *** antelope ***
	real obj_antelope_sharpEval = sharpEval.sharpnessEval_laplacian_colorUN(object_antelope);
	real ima_antelope_sharpEval = sharpEval.sharpnessEval_laplacian_colorUN(simIma_antelope);
	bool checkSharpness_antelope = obj_antelope_sharpEval > ima_antelope_sharpEval;
	workTheSystem.push_back(checkSharpness_antelope);
	// *** *** 

	// *** dragonfly ***
	real obj_dragonfly_sharpEval = sharpEval.sharpnessEval_laplacian_colorUN(object_dragonfly);
	real ima_dragonfly_sharpEval = sharpEval.sharpnessEval_laplacian_colorUN(simIma_dragonfly);
	bool checkSharpness_dragonfly = obj_dragonfly_sharpEval > ima_dragonfly_sharpEval;
	workTheSystem.push_back(checkSharpness_dragonfly);
	// *** *** 

	// *** elefant ***
	real obj_elefant_sharpEval = sharpEval.sharpnessEval_laplacian_colorUN(object_elefant);
	real ima_elefant_sharpEval = sharpEval.sharpnessEval_laplacian_colorUN(simIma_elefant);
	bool checkSharpness_elefant = obj_elefant_sharpEval > ima_elefant_sharpEval;
	workTheSystem.push_back(checkSharpness_elefant);
	// *** *** 

	// *** flower1 ***
	real obj_flower1_sharpEval = sharpEval.sharpnessEval_laplacian_colorUN(object_flower1);
	real ima_flower1_sharpEval = sharpEval.sharpnessEval_laplacian_colorUN(simIma_flower1);
	bool checkSharpness_flower1 = obj_flower1_sharpEval > ima_flower1_sharpEval;
	workTheSystem.push_back(checkSharpness_flower1);
	// *** *** 

	// *** flower2 ***
	real obj_flower2_sharpEval = sharpEval.sharpnessEval_laplacian_colorUN(object_flower2);
	real ima_flower2_sharpEval = sharpEval.sharpnessEval_laplacian_colorUN(simIma_flower2);
	bool checkSharpness_flower2 = obj_flower2_sharpEval > ima_flower2_sharpEval;
	workTheSystem.push_back(checkSharpness_flower2);
	// *** *** 

	// *** flower3 ***
	real obj_flower3_sharpEval = sharpEval.sharpnessEval_laplacian_colorUN(object_flower3);
	real ima_flower3_sharpEval = sharpEval.sharpnessEval_laplacian_colorUN(simIma_flower3);
	bool checkSharpness_flower3 = obj_flower3_sharpEval > ima_flower3_sharpEval;
	workTheSystem.push_back(checkSharpness_flower3);
	// *** *** 

	// *** landscape ***
	real obj_landscape_sharpEval = sharpEval.sharpnessEval_laplacian_colorUN(object_landscape);
	real ima_landscape_sharpEval = sharpEval.sharpnessEval_laplacian_colorUN(simIma_landscape);
	bool checkSharpness_landscape = obj_landscape_sharpEval > ima_landscape_sharpEval;
	workTheSystem.push_back(checkSharpness_landscape);
	// *** *** 

	// *** pinguin ***
	real obj_pinguin_sharpEval = sharpEval.sharpnessEval_laplacian_colorUN(object_pinguin);
	real ima_pinguin_sharpEval = sharpEval.sharpnessEval_laplacian_colorUN(simIma_pinguin);
	bool checkSharpness_pinguin = obj_pinguin_sharpEval > ima_pinguin_sharpEval;
	workTheSystem.push_back(checkSharpness_pinguin);
	// *** *** 

	// *** rhino ***
	real obj_rhino_sharpEval = sharpEval.sharpnessEval_laplacian_colorUN(object_rhino);
	real ima_rhino_sharpEval = sharpEval.sharpnessEval_laplacian_colorUN(simIma_rhino);
	bool checkSharpness_rhino = obj_rhino_sharpEval > ima_rhino_sharpEval;
	workTheSystem.push_back(checkSharpness_rhino);
	// *** *** 

	// *** salad ***
	real obj_salad_sharpEval = sharpEval.sharpnessEval_laplacian_colorUN(object_salad);
	real ima_salad_sharpEval = sharpEval.sharpnessEval_laplacian_colorUN(simIma_salad);
	bool checkSharpness_salad = obj_salad_sharpEval > ima_salad_sharpEval;
	workTheSystem.push_back(checkSharpness_salad);
	// *** *** 

	bool checkTheSystem = Math::checkTrueOfVectorElements(workTheSystem);
	return checkTheSystem;

}

// test SMD
bool testSharpnessEvaluation::test_SMD()
{
	std::vector<bool> workTheSystem;

	SharpnessEvaluation sharpEval;
	// *** antelope ***
	real obj_antelope_sharpEval = sharpEval.sharpnessEval_SMD_colorUN(object_antelope);
	real ima_antelope_sharpEval = sharpEval.sharpnessEval_SMD_colorUN(simIma_antelope);
	bool checkSharpness_antelope = obj_antelope_sharpEval > ima_antelope_sharpEval;
	workTheSystem.push_back(checkSharpness_antelope);
	// *** *** 

	// *** dragonfly ***
	real obj_dragonfly_sharpEval = sharpEval.sharpnessEval_SMD_colorUN(object_dragonfly);
	real ima_dragonfly_sharpEval = sharpEval.sharpnessEval_SMD_colorUN(simIma_dragonfly);
	bool checkSharpness_dragonfly = obj_dragonfly_sharpEval > ima_dragonfly_sharpEval;
	workTheSystem.push_back(checkSharpness_dragonfly);
	// *** *** 

	// *** elefant ***
	real obj_elefant_sharpEval = sharpEval.sharpnessEval_SMD_colorUN(object_elefant);
	real ima_elefant_sharpEval = sharpEval.sharpnessEval_SMD_colorUN(simIma_elefant);
	bool checkSharpness_elefant = obj_elefant_sharpEval > ima_elefant_sharpEval;
	workTheSystem.push_back(checkSharpness_elefant);
	// *** *** 

	// *** flower1 ***
	real obj_flower1_sharpEval = sharpEval.sharpnessEval_SMD_colorUN(object_flower1);
	real ima_flower1_sharpEval = sharpEval.sharpnessEval_SMD_colorUN(simIma_flower1);
	bool checkSharpness_flower1 = obj_flower1_sharpEval > ima_flower1_sharpEval;
	workTheSystem.push_back(checkSharpness_flower1);
	// *** *** 

	// *** flower2 ***
	real obj_flower2_sharpEval = sharpEval.sharpnessEval_SMD_colorUN(object_flower2);
	real ima_flower2_sharpEval = sharpEval.sharpnessEval_SMD_colorUN(simIma_flower2);
	bool checkSharpness_flower2 = obj_flower2_sharpEval > ima_flower2_sharpEval;
	workTheSystem.push_back(checkSharpness_flower2);
	// *** *** 

	// *** flower3 ***
	real obj_flower3_sharpEval = sharpEval.sharpnessEval_SMD_colorUN(object_flower3);
	real ima_flower3_sharpEval = sharpEval.sharpnessEval_SMD_colorUN(simIma_flower3);
	bool checkSharpness_flower3 = obj_flower3_sharpEval > ima_flower3_sharpEval;
	workTheSystem.push_back(checkSharpness_flower3);
	// *** *** 

	// *** landscape ***
	real obj_landscape_sharpEval = sharpEval.sharpnessEval_SMD_colorUN(object_landscape);
	real ima_landscape_sharpEval = sharpEval.sharpnessEval_SMD_colorUN(simIma_landscape);
	bool checkSharpness_landscape = obj_landscape_sharpEval > ima_landscape_sharpEval;
	workTheSystem.push_back(checkSharpness_landscape);
	// *** *** 

	// *** pinguin ***
	real obj_pinguin_sharpEval = sharpEval.sharpnessEval_SMD_colorUN(object_pinguin);
	real ima_pinguin_sharpEval = sharpEval.sharpnessEval_SMD_colorUN(simIma_pinguin);
	bool checkSharpness_pinguin = obj_pinguin_sharpEval > ima_pinguin_sharpEval;
	workTheSystem.push_back(checkSharpness_pinguin);
	// *** *** 

	// *** rhino ***
	real obj_rhino_sharpEval = sharpEval.sharpnessEval_SMD_colorUN(object_rhino);
	real ima_rhino_sharpEval = sharpEval.sharpnessEval_SMD_colorUN(simIma_rhino);
	bool checkSharpness_rhino = obj_rhino_sharpEval > ima_rhino_sharpEval;
	workTheSystem.push_back(checkSharpness_rhino);
	// *** *** 

	// *** salad ***
	real obj_salad_sharpEval = sharpEval.sharpnessEval_SMD_colorUN(object_salad);
	real ima_salad_sharpEval = sharpEval.sharpnessEval_SMD_colorUN(simIma_salad);
	bool checkSharpness_salad = obj_salad_sharpEval > ima_salad_sharpEval;
	workTheSystem.push_back(checkSharpness_salad);
	// *** *** 

	bool checkTheSystem = Math::checkTrueOfVectorElements(workTheSystem);
	return checkTheSystem;
}

// test SMD2
bool testSharpnessEvaluation::test_SMD2()
{
	std::vector<bool> workTheSystem;

	SharpnessEvaluation sharpEval;
	// *** antelope ***
	real obj_antelope_sharpEval = sharpEval.sharpnessEval_SMD2_colorUN(object_antelope);
	real ima_antelope_sharpEval = sharpEval.sharpnessEval_SMD2_colorUN(simIma_antelope);
	bool checkSharpness_antelope = obj_antelope_sharpEval > ima_antelope_sharpEval;
	workTheSystem.push_back(checkSharpness_antelope);
	// *** *** 

	// *** dragonfly ***
	real obj_dragonfly_sharpEval = sharpEval.sharpnessEval_SMD2_colorUN(object_dragonfly);
	real ima_dragonfly_sharpEval = sharpEval.sharpnessEval_SMD2_colorUN(simIma_dragonfly);
	bool checkSharpness_dragonfly = obj_dragonfly_sharpEval > ima_dragonfly_sharpEval;
	workTheSystem.push_back(checkSharpness_dragonfly);
	// *** *** 

	// *** elefant ***
	real obj_elefant_sharpEval = sharpEval.sharpnessEval_SMD2_colorUN(object_elefant);
	real ima_elefant_sharpEval = sharpEval.sharpnessEval_SMD2_colorUN(simIma_elefant);
	bool checkSharpness_elefant = obj_elefant_sharpEval > ima_elefant_sharpEval;
	workTheSystem.push_back(checkSharpness_elefant);
	// *** *** 

	// *** flower1 ***
	real obj_flower1_sharpEval = sharpEval.sharpnessEval_SMD2_colorUN(object_flower1);
	real ima_flower1_sharpEval = sharpEval.sharpnessEval_SMD2_colorUN(simIma_flower1);
	bool checkSharpness_flower1 = obj_flower1_sharpEval > ima_flower1_sharpEval;
	workTheSystem.push_back(checkSharpness_flower1);
	// *** *** 

	// *** flower2 ***
	real obj_flower2_sharpEval = sharpEval.sharpnessEval_SMD2_colorUN(object_flower2);
	real ima_flower2_sharpEval = sharpEval.sharpnessEval_SMD2_colorUN(simIma_flower2);
	bool checkSharpness_flower2 = obj_flower2_sharpEval > ima_flower2_sharpEval;
	workTheSystem.push_back(checkSharpness_flower2);
	// *** *** 

	// *** flower3 ***
	real obj_flower3_sharpEval = sharpEval.sharpnessEval_SMD2_colorUN(object_flower3);
	real ima_flower3_sharpEval = sharpEval.sharpnessEval_SMD2_colorUN(simIma_flower3);
	bool checkSharpness_flower3 = obj_flower3_sharpEval > ima_flower3_sharpEval;
	workTheSystem.push_back(checkSharpness_flower3);
	// *** *** 

	// *** landscape ***
	real obj_landscape_sharpEval = sharpEval.sharpnessEval_SMD2_colorUN(object_landscape);
	real ima_landscape_sharpEval = sharpEval.sharpnessEval_SMD2_colorUN(simIma_landscape);
	bool checkSharpness_landscape = obj_landscape_sharpEval > ima_landscape_sharpEval;
	workTheSystem.push_back(checkSharpness_landscape);
	// *** *** 

	// *** pinguin ***
	real obj_pinguin_sharpEval = sharpEval.sharpnessEval_SMD2_colorUN(object_pinguin);
	real ima_pinguin_sharpEval = sharpEval.sharpnessEval_SMD2_colorUN(simIma_pinguin);
	bool checkSharpness_pinguin = obj_pinguin_sharpEval > ima_pinguin_sharpEval;
	workTheSystem.push_back(checkSharpness_pinguin);
	// *** *** 

	// *** rhino ***
	real obj_rhino_sharpEval = sharpEval.sharpnessEval_SMD2_colorUN(object_rhino);
	real ima_rhino_sharpEval = sharpEval.sharpnessEval_SMD2_colorUN(simIma_rhino);
	bool checkSharpness_rhino = obj_rhino_sharpEval > ima_rhino_sharpEval;
	workTheSystem.push_back(checkSharpness_rhino);
	// *** *** 

	// *** salad ***
	real obj_salad_sharpEval = sharpEval.sharpnessEval_SMD2_colorUN(object_salad);
	real ima_salad_sharpEval = sharpEval.sharpnessEval_SMD2_colorUN(simIma_salad);
	bool checkSharpness_salad = obj_salad_sharpEval > ima_salad_sharpEval;
	workTheSystem.push_back(checkSharpness_salad);
	// *** *** 

	bool checkTheSystem = Math::checkTrueOfVectorElements(workTheSystem);
	return checkTheSystem;
}

// test energy gradient function
bool testSharpnessEvaluation::testEnergyGradFct()
{
	std::vector<bool> workTheSystem;

	SharpnessEvaluation sharpEval;
	// *** antelope ***
	real obj_antelope_sharpEval = sharpEval.sharpnessEval_EnergyGradFct_colorUN(object_antelope);
	real ima_antelope_sharpEval = sharpEval.sharpnessEval_EnergyGradFct_colorUN(simIma_antelope);
	bool checkSharpness_antelope = obj_antelope_sharpEval > ima_antelope_sharpEval;
	workTheSystem.push_back(checkSharpness_antelope);
	// *** *** 

	// *** dragonfly ***
	real obj_dragonfly_sharpEval = sharpEval.sharpnessEval_EnergyGradFct_colorUN(object_dragonfly);
	real ima_dragonfly_sharpEval = sharpEval.sharpnessEval_EnergyGradFct_colorUN(simIma_dragonfly);
	bool checkSharpness_dragonfly = obj_dragonfly_sharpEval > ima_dragonfly_sharpEval;
	workTheSystem.push_back(checkSharpness_dragonfly);
	// *** *** 

	// *** elefant ***
	real obj_elefant_sharpEval = sharpEval.sharpnessEval_EnergyGradFct_colorUN(object_elefant);
	real ima_elefant_sharpEval = sharpEval.sharpnessEval_EnergyGradFct_colorUN(simIma_elefant);
	bool checkSharpness_elefant = obj_elefant_sharpEval > ima_elefant_sharpEval;
	workTheSystem.push_back(checkSharpness_elefant);
	// *** *** 

	// *** flower1 ***
	real obj_flower1_sharpEval = sharpEval.sharpnessEval_EnergyGradFct_colorUN(object_flower1);
	real ima_flower1_sharpEval = sharpEval.sharpnessEval_EnergyGradFct_colorUN(simIma_flower1);
	bool checkSharpness_flower1 = obj_flower1_sharpEval > ima_flower1_sharpEval;
	workTheSystem.push_back(checkSharpness_flower1);
	// *** *** 

	// *** flower2 ***
	real obj_flower2_sharpEval = sharpEval.sharpnessEval_EnergyGradFct_colorUN(object_flower2);
	real ima_flower2_sharpEval = sharpEval.sharpnessEval_EnergyGradFct_colorUN(simIma_flower2);
	bool checkSharpness_flower2 = obj_flower2_sharpEval > ima_flower2_sharpEval;
	workTheSystem.push_back(checkSharpness_flower2);
	// *** *** 

	// *** flower3 ***
	real obj_flower3_sharpEval = sharpEval.sharpnessEval_EnergyGradFct_colorUN(object_flower3);
	real ima_flower3_sharpEval = sharpEval.sharpnessEval_EnergyGradFct_colorUN(simIma_flower3);
	bool checkSharpness_flower3 = obj_flower3_sharpEval > ima_flower3_sharpEval;
	workTheSystem.push_back(checkSharpness_flower3);
	// *** *** 

	// *** landscape ***
	real obj_landscape_sharpEval = sharpEval.sharpnessEval_EnergyGradFct_colorUN(object_landscape);
	real ima_landscape_sharpEval = sharpEval.sharpnessEval_EnergyGradFct_colorUN(simIma_landscape);
	bool checkSharpness_landscape = obj_landscape_sharpEval > ima_landscape_sharpEval;
	workTheSystem.push_back(checkSharpness_landscape);
	// *** *** 

	// *** pinguin ***
	real obj_pinguin_sharpEval = sharpEval.sharpnessEval_EnergyGradFct_colorUN(object_pinguin);
	real ima_pinguin_sharpEval = sharpEval.sharpnessEval_EnergyGradFct_colorUN(simIma_pinguin);
	bool checkSharpness_pinguin = obj_pinguin_sharpEval > ima_pinguin_sharpEval;
	workTheSystem.push_back(checkSharpness_pinguin);
	// *** *** 

	// *** rhino ***
	real obj_rhino_sharpEval = sharpEval.sharpnessEval_EnergyGradFct_colorUN(object_rhino);
	real ima_rhino_sharpEval = sharpEval.sharpnessEval_EnergyGradFct_colorUN(simIma_rhino);
	bool checkSharpness_rhino = obj_rhino_sharpEval > ima_rhino_sharpEval;
	workTheSystem.push_back(checkSharpness_rhino);
	// *** *** 

	// *** salad ***
	real obj_salad_sharpEval = sharpEval.sharpnessEval_EnergyGradFct_colorUN(object_salad);
	real ima_salad_sharpEval = sharpEval.sharpnessEval_EnergyGradFct_colorUN(simIma_salad);
	bool checkSharpness_salad = obj_salad_sharpEval > ima_salad_sharpEval;
	workTheSystem.push_back(checkSharpness_salad);
	// *** *** 

	bool checkTheSystem = Math::checkTrueOfVectorElements(workTheSystem);
	return checkTheSystem;
}

// test EVA
bool testSharpnessEvaluation::test_EVA()
{
	std::vector<bool> workTheSystem;

	SharpnessEvaluation sharpEval;
	// *** antelope ***
	real obj_antelope_sharpEval = sharpEval.sharpnessEval_EVA_colorUN(object_antelope);
	real ima_antelope_sharpEval = sharpEval.sharpnessEval_EVA_colorUN(simIma_antelope);
	bool checkSharpness_antelope = obj_antelope_sharpEval > ima_antelope_sharpEval;
	workTheSystem.push_back(checkSharpness_antelope);
	// *** *** 

	// *** dragonfly ***
	real obj_dragonfly_sharpEval = sharpEval.sharpnessEval_EVA_colorUN(object_dragonfly);
	real ima_dragonfly_sharpEval = sharpEval.sharpnessEval_EVA_colorUN(simIma_dragonfly);
	bool checkSharpness_dragonfly = obj_dragonfly_sharpEval > ima_dragonfly_sharpEval;
	workTheSystem.push_back(checkSharpness_dragonfly);
	// *** *** 

	// *** elefant ***
	real obj_elefant_sharpEval = sharpEval.sharpnessEval_EVA_colorUN(object_elefant);
	real ima_elefant_sharpEval = sharpEval.sharpnessEval_EVA_colorUN(simIma_elefant);
	bool checkSharpness_elefant = obj_elefant_sharpEval > ima_elefant_sharpEval;
	workTheSystem.push_back(checkSharpness_elefant);
	// *** *** 

	// *** flower1 ***
	real obj_flower1_sharpEval = sharpEval.sharpnessEval_EVA_colorUN(object_flower1);
	real ima_flower1_sharpEval = sharpEval.sharpnessEval_EVA_colorUN(simIma_flower1);
	bool checkSharpness_flower1 = obj_flower1_sharpEval > ima_flower1_sharpEval;
	workTheSystem.push_back(checkSharpness_flower1);
	// *** *** 

	// *** flower2 ***
	real obj_flower2_sharpEval = sharpEval.sharpnessEval_EVA_colorUN(object_flower2);
	real ima_flower2_sharpEval = sharpEval.sharpnessEval_EVA_colorUN(simIma_flower2);
	bool checkSharpness_flower2 = obj_flower2_sharpEval > ima_flower2_sharpEval;
	workTheSystem.push_back(checkSharpness_flower2);
	// *** *** 

	// *** flower3 ***
	real obj_flower3_sharpEval = sharpEval.sharpnessEval_EVA_colorUN(object_flower3);
	real ima_flower3_sharpEval = sharpEval.sharpnessEval_EVA_colorUN(simIma_flower3);
	bool checkSharpness_flower3 = obj_flower3_sharpEval > ima_flower3_sharpEval;
	workTheSystem.push_back(checkSharpness_flower3);
	// *** *** 

	// *** landscape ***
	real obj_landscape_sharpEval = sharpEval.sharpnessEval_EVA_colorUN(object_landscape);
	real ima_landscape_sharpEval = sharpEval.sharpnessEval_EVA_colorUN(simIma_landscape);
	bool checkSharpness_landscape = obj_landscape_sharpEval > ima_landscape_sharpEval;
	workTheSystem.push_back(checkSharpness_landscape);
	// *** *** 

	// *** pinguin ***
	real obj_pinguin_sharpEval = sharpEval.sharpnessEval_EVA_colorUN(object_pinguin);
	real ima_pinguin_sharpEval = sharpEval.sharpnessEval_EVA_colorUN(simIma_pinguin);
	bool checkSharpness_pinguin = obj_pinguin_sharpEval > ima_pinguin_sharpEval;
	workTheSystem.push_back(checkSharpness_pinguin);
	// *** *** 

	// *** rhino ***
	real obj_rhino_sharpEval = sharpEval.sharpnessEval_EVA_colorUN(object_rhino);
	real ima_rhino_sharpEval = sharpEval.sharpnessEval_EVA_colorUN(simIma_rhino);
	bool checkSharpness_rhino = obj_rhino_sharpEval > ima_rhino_sharpEval;
	workTheSystem.push_back(checkSharpness_rhino);
	// *** *** 

	// *** salad ***
	real obj_salad_sharpEval = sharpEval.sharpnessEval_EVA_colorUN(object_salad);
	real ima_salad_sharpEval = sharpEval.sharpnessEval_EVA_colorUN(simIma_salad);
	bool checkSharpness_salad = obj_salad_sharpEval > ima_salad_sharpEval;
	workTheSystem.push_back(checkSharpness_salad);
	// *** *** 

	bool checkTheSystem = Math::checkTrueOfVectorElements(workTheSystem);
	return checkTheSystem;
}

// NRSS
bool testSharpnessEvaluation::test_NRSS()
{
	std::vector<bool> workTheSystem;

	SharpnessEvaluation sharpEval;
	// *** antelope ***
	real obj_antelope_sharpEval = sharpEval.sharpnessEval_NRSS_colorUN(object_antelope);
	real ima_antelope_sharpEval = sharpEval.sharpnessEval_NRSS_colorUN(simIma_antelope);
	bool checkSharpness_antelope = obj_antelope_sharpEval > ima_antelope_sharpEval;
	workTheSystem.push_back(checkSharpness_antelope);
	// *** *** 

	// *** dragonfly ***
	real obj_dragonfly_sharpEval = sharpEval.sharpnessEval_NRSS_colorUN(object_dragonfly);
	real ima_dragonfly_sharpEval = sharpEval.sharpnessEval_NRSS_colorUN(simIma_dragonfly);
	bool checkSharpness_dragonfly = obj_dragonfly_sharpEval > ima_dragonfly_sharpEval;
	workTheSystem.push_back(checkSharpness_dragonfly);
	// *** *** 

	// *** elefant ***
	real obj_elefant_sharpEval = sharpEval.sharpnessEval_NRSS_colorUN(object_elefant);
	real ima_elefant_sharpEval = sharpEval.sharpnessEval_NRSS_colorUN(simIma_elefant);
	bool checkSharpness_elefant = obj_elefant_sharpEval > ima_elefant_sharpEval;
	workTheSystem.push_back(checkSharpness_elefant);
	// *** *** 

	// *** flower1 ***
	real obj_flower1_sharpEval = sharpEval.sharpnessEval_NRSS_colorUN(object_flower1);
	real ima_flower1_sharpEval = sharpEval.sharpnessEval_NRSS_colorUN(simIma_flower1);
	bool checkSharpness_flower1 = obj_flower1_sharpEval > ima_flower1_sharpEval;
	workTheSystem.push_back(checkSharpness_flower1);
	// *** *** 

	// *** flower2 ***
	real obj_flower2_sharpEval = sharpEval.sharpnessEval_NRSS_colorUN(object_flower2);
	real ima_flower2_sharpEval = sharpEval.sharpnessEval_NRSS_colorUN(simIma_flower2);
	bool checkSharpness_flower2 = obj_flower2_sharpEval > ima_flower2_sharpEval;
	workTheSystem.push_back(checkSharpness_flower2);
	// *** *** 

	// *** flower3 ***
	real obj_flower3_sharpEval = sharpEval.sharpnessEval_NRSS_colorUN(object_flower3);
	real ima_flower3_sharpEval = sharpEval.sharpnessEval_NRSS_colorUN(simIma_flower3);
	bool checkSharpness_flower3 = obj_flower3_sharpEval > ima_flower3_sharpEval;
	workTheSystem.push_back(checkSharpness_flower3);
	// *** *** 

	// *** landscape ***
	real obj_landscape_sharpEval = sharpEval.sharpnessEval_NRSS_colorUN(object_landscape);
	real ima_landscape_sharpEval = sharpEval.sharpnessEval_NRSS_colorUN(simIma_landscape);
	bool checkSharpness_landscape = obj_landscape_sharpEval > ima_landscape_sharpEval;
	workTheSystem.push_back(checkSharpness_landscape);
	// *** *** 

	// *** pinguin ***
	real obj_pinguin_sharpEval = sharpEval.sharpnessEval_NRSS_colorUN(object_pinguin);
	real ima_pinguin_sharpEval = sharpEval.sharpnessEval_NRSS_colorUN(simIma_pinguin);
	bool checkSharpness_pinguin = obj_pinguin_sharpEval > ima_pinguin_sharpEval;
	workTheSystem.push_back(checkSharpness_pinguin);
	// *** *** 

	// *** rhino ***
	real obj_rhino_sharpEval = sharpEval.sharpnessEval_NRSS_colorUN(object_rhino);
	real ima_rhino_sharpEval = sharpEval.sharpnessEval_NRSS_colorUN(simIma_rhino);
	bool checkSharpness_rhino = obj_rhino_sharpEval > ima_rhino_sharpEval;
	workTheSystem.push_back(checkSharpness_rhino);
	// *** *** 

	// *** salad ***
	real obj_salad_sharpEval = sharpEval.sharpnessEval_NRSS_colorUN(object_salad);
	real ima_salad_sharpEval = sharpEval.sharpnessEval_NRSS_colorUN(simIma_salad);
	bool checkSharpness_salad = obj_salad_sharpEval > ima_salad_sharpEval;
	workTheSystem.push_back(checkSharpness_salad);
	// *** *** 

	bool checkTheSystem = Math::checkTrueOfVectorElements(workTheSystem);
	return checkTheSystem;

}

// blur noise IQA
bool testSharpnessEvaluation::test_blur_noise_IQA()
{
	std::vector<bool> workTheSystem;

	SharpnessEvaluation sharpEval;
	// *** antelope ***
	real obj_antelope_sharpEval = sharpEval.sharpnessEval_blur_noise_IQA_colorUN(object_antelope);
	real ima_antelope_sharpEval = sharpEval.sharpnessEval_blur_noise_IQA_colorUN(simIma_antelope);
	bool checkSharpness_antelope = obj_antelope_sharpEval > ima_antelope_sharpEval;
	workTheSystem.push_back(checkSharpness_antelope);
	// *** *** 

	// *** dragonfly ***
	real obj_dragonfly_sharpEval = sharpEval.sharpnessEval_blur_noise_IQA_colorUN(object_dragonfly);
	real ima_dragonfly_sharpEval = sharpEval.sharpnessEval_blur_noise_IQA_colorUN(simIma_dragonfly);
	bool checkSharpness_dragonfly = obj_dragonfly_sharpEval > ima_dragonfly_sharpEval;
	workTheSystem.push_back(checkSharpness_dragonfly);
	// *** *** 

	// *** elefant ***
	real obj_elefant_sharpEval = sharpEval.sharpnessEval_blur_noise_IQA_colorUN(object_elefant);
	real ima_elefant_sharpEval = sharpEval.sharpnessEval_blur_noise_IQA_colorUN(simIma_elefant);
	bool checkSharpness_elefant = obj_elefant_sharpEval > ima_elefant_sharpEval;
	workTheSystem.push_back(checkSharpness_elefant);
	// *** *** 

	// *** flower1 ***
	real obj_flower1_sharpEval = sharpEval.sharpnessEval_blur_noise_IQA_colorUN(object_flower1);
	real ima_flower1_sharpEval = sharpEval.sharpnessEval_blur_noise_IQA_colorUN(simIma_flower1);
	bool checkSharpness_flower1 = obj_flower1_sharpEval > ima_flower1_sharpEval;
	workTheSystem.push_back(checkSharpness_flower1);
	// *** *** 

	// *** flower2 ***
	real obj_flower2_sharpEval = sharpEval.sharpnessEval_blur_noise_IQA_colorUN(object_flower2);
	real ima_flower2_sharpEval = sharpEval.sharpnessEval_blur_noise_IQA_colorUN(simIma_flower2);
	bool checkSharpness_flower2 = obj_flower2_sharpEval > ima_flower2_sharpEval;
	workTheSystem.push_back(checkSharpness_flower2);
	// *** *** 

	// *** flower3 ***
	real obj_flower3_sharpEval = sharpEval.sharpnessEval_blur_noise_IQA_colorUN(object_flower3);
	real ima_flower3_sharpEval = sharpEval.sharpnessEval_blur_noise_IQA_colorUN(simIma_flower3);
	bool checkSharpness_flower3 = obj_flower3_sharpEval > ima_flower3_sharpEval;
	workTheSystem.push_back(checkSharpness_flower3);
	// *** *** 

	// *** landscape ***
	real obj_landscape_sharpEval = sharpEval.sharpnessEval_blur_noise_IQA_colorUN(object_landscape);
	real ima_landscape_sharpEval = sharpEval.sharpnessEval_blur_noise_IQA_colorUN(simIma_landscape);
	bool checkSharpness_landscape = obj_landscape_sharpEval > ima_landscape_sharpEval;
	workTheSystem.push_back(checkSharpness_landscape);
	// *** *** 

	// *** pinguin ***
	real obj_pinguin_sharpEval = sharpEval.sharpnessEval_blur_noise_IQA_colorUN(object_pinguin);
	real ima_pinguin_sharpEval = sharpEval.sharpnessEval_blur_noise_IQA_colorUN(simIma_pinguin);
	bool checkSharpness_pinguin = obj_pinguin_sharpEval > ima_pinguin_sharpEval;
	workTheSystem.push_back(checkSharpness_pinguin);
	// *** *** 

	// *** rhino ***
	real obj_rhino_sharpEval = sharpEval.sharpnessEval_blur_noise_IQA_colorUN(object_rhino);
	real ima_rhino_sharpEval = sharpEval.sharpnessEval_blur_noise_IQA_colorUN(simIma_rhino);
	bool checkSharpness_rhino = obj_rhino_sharpEval > ima_rhino_sharpEval;
	workTheSystem.push_back(checkSharpness_rhino);
	// *** *** 

	// *** salad ***
	real obj_salad_sharpEval = sharpEval.sharpnessEval_blur_noise_IQA_colorUN(object_salad);
	real ima_salad_sharpEval = sharpEval.sharpnessEval_blur_noise_IQA_colorUN(simIma_salad);
	bool checkSharpness_salad = obj_salad_sharpEval > ima_salad_sharpEval;
	workTheSystem.push_back(checkSharpness_salad);
	// *** *** 

	bool checkTheSystem = Math::checkTrueOfVectorElements(workTheSystem);
	return checkTheSystem;

}