#include "testLensReplaceAndOptimize.h"

#include "..\..\OpticalSystemElement\OpticalSystemElement.h"

//surface HLT
#include "..\..\SurfaceElements\PlanElement.h"
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\ApertureStopElement.h"

// often use
#include "..\..\oftenUseNamespace\oftenUseNamespace.h"
// lens replace
#include "..\..\lensReplace\LensReplace.h"
// lens replace and optimize
#include "..\..\LensReplaceAndOptimize\LensReplaceAndOptimize.h"
// inport export
#include "..\..\Inport_Export_Data\Inport_Export_Data.h"


typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

testLensReplaceAndOptimize::testLensReplaceAndOptimize() {}
testLensReplaceAndOptimize::~testLensReplaceAndOptimize() {}

bool testLensReplaceAndOptimize::testLensReplaceAndOptimize_superFct()
{
	std::vector<bool> workLensReplace_superFct;

	std::string location = "../tests/testLensReplaceAndOptimize";
	std::string name = "testLensReplaceAndOptimize_superFct";
	// clear txt
	inportExportData::clearDataInTXT(location, name);

	// E0
	bool checkE0 = testLensReplaceAndOptimize_E0();
	workLensReplace_superFct.push_back(checkE0);
	if (checkE0) { inportExportData::saveStringInTXT_includingTime(location, name, "E0 worked"); };
	// E1
	bool checkE1 = testLensReplaceAndOptimize_E1();
	workLensReplace_superFct.push_back(checkE1);
	if (checkE0) { inportExportData::saveStringInTXT_includingTime(location, name, "E1 worked"); };
	// E2
	bool checkE2 = testLensReplaceAndOptimize_E2();
	workLensReplace_superFct.push_back(checkE2);
	if (checkE0) { inportExportData::saveStringInTXT_includingTime(location, name, "E2 worked"); };
	// E3
	bool checkE3 = testLensReplaceAndOptimize_E3();
	workLensReplace_superFct.push_back(checkE3);
	if (checkE0) { inportExportData::saveStringInTXT_includingTime(location, name, "E3 worked"); };
	// E4
	bool checkE4 = testLensReplaceAndOptimize_E4();
	workLensReplace_superFct.push_back(checkE4);
	if (checkE0) { inportExportData::saveStringInTXT_includingTime(location, name, "E4 worked"); };
	// E5
	bool checkE5 = testLensReplaceAndOptimize_E5();
	workLensReplace_superFct.push_back(checkE5);
	if (checkE0) { inportExportData::saveStringInTXT_includingTime(location, name, "E5 worked"); };
	// E6
	bool checkE6 = testLensReplaceAndOptimize_E6();
	workLensReplace_superFct.push_back(checkE6);
	if (checkE0) { inportExportData::saveStringInTXT_includingTime(location, name, "E6 worked"); };
	// E7
	bool checkE7 = testLensReplaceAndOptimize_E7();
	workLensReplace_superFct.push_back(checkE7);
	if (checkE0) { inportExportData::saveStringInTXT_includingTime(location, name, "E7 worked"); };
	// E8
	bool checkE8 = testLensReplaceAndOptimize_E8();
	workLensReplace_superFct.push_back(checkE8);
	if (checkE0) { inportExportData::saveStringInTXT_includingTime(location, name, "E8 worked"); };
	// E9
	bool checkE9 = testLensReplaceAndOptimize_E9();
	workLensReplace_superFct.push_back(checkE9);
	if (checkE0) { inportExportData::saveStringInTXT_includingTime(location, name, "E9 worked"); };


	bool returnChecker_superFct = Math::checkTrueOfVectorElements(workLensReplace_superFct);
	return returnChecker_superFct;
}

// E0
bool testLensReplaceAndOptimize::testLensReplaceAndOptimize_E0()
{
	std::vector<bool> workTheSystem;
	real tolerance_rms = 0.1;
	mGlasses.loadGlassCatalog_Schott();

	ApertureStopElement S0(/* semi height*/1.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S2(/*radius*/ 50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S3(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNSF57_S1());
	SphericalElement S6(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());
	SphericalElement S7(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S9(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	PlanElement S10(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S2.setParameterRadius(/*min value*/ -1000.0,  /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	// **********************************

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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	//oftenUse::print(optSystemElement, 550.0);

	// check the start system
	std::vector<real> rms_Zemax{ 277.024, 290.844 };
	std::vector<real> wave_vec{ 550.0, 400.0};
	std::vector<VectorStructR3> field_vec{ {0.0,0.0,0.0}, {0.0,1.0,0.0} };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, field_vec, wave_vec, rms_Zemax, tolerance_rms, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	LensReplaceAndOptimize lensRepAndOpti;
	int rings = 6;
	int arms = 8;
	optimizeMethode optMethode = optimizeMethode::DLS;
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetEFL(20.0);
	tarCarP.setTargetMag(-1.0);
	lensRepAndOpti.setTargetCardinalPoints(tarCarP);
	defaultParaDLS defParaDLS = oftenUse::getDefaultPara_DLS(true);
	//defParaDLS.setFlipOrientationRadius(500.0);
	defParaDLS.setMaxBorderViolations(200.0);
	lensRepAndOpti.setDefaulParaDLS(defParaDLS);

	// *** set lens catalogs
	std::vector<lensTypes> loadLensCatalogEO_vec;
	loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConvex_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PosAchromat_MgF_Coated);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConvex_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConcav_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConcav_VIS_NIR);
	lensRepAndOpti.setLoadLensCatalogs(loadLensCatalogEO_vec);
	// ***

	unsigned int numberBestFitLenses = 3;

	// 0 lens
	lensRepAndOpti.lensReplaceAndOptimize(optSystemElement, field_vec, wave_vec, rings, arms, optMethode, /*lens number*/ 0, /*number best fit lenses*/numberBestFitLenses, true);
	OpticalSystemElement bestReplacedOptSys_0 = lensRepAndOpti.getBestReplacedOpticalSystem();
	oftenUse::print(bestReplacedOptSys_0, 550.0);
	// 1 lens
	lensRepAndOpti.lensReplaceAndOptimize(bestReplacedOptSys_0, field_vec, wave_vec, rings, arms, optMethode,  /*lens number*/ 1,/*number best fit lenses*/ numberBestFitLenses, false);
	OpticalSystemElement bestReplacedOptSys_1 = lensRepAndOpti.getBestReplacedOpticalSystem();
	oftenUse::print(bestReplacedOptSys_1, 550.0);
	// 2 lens
	lensRepAndOpti.lensReplaceAndOptimize(bestReplacedOptSys_1, field_vec, wave_vec, rings, arms, optMethode,  /*lens number*/ 2,/*number best fit lenses*/ numberBestFitLenses, false);
	OpticalSystemElement bestReplacedOptSys_2 = lensRepAndOpti.getBestReplacedOpticalSystem();
	oftenUse::print(bestReplacedOptSys_2, 550.0);


	LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
	testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(tarCarP);
	testLensReplaceAndOptiSuperFct.setDefaulParaDLS(defParaDLS);
	testLensReplaceAndOptiSuperFct.setLoadLensCatalogs(loadLensCatalogEO_vec);

	replaceSequence repSequence = replaceSequence::leftToRight;
	Light_LLT light = oftenUse::getDefaultLight();
	testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(optSystemElement, field_vec, wave_vec, rings, arms,  optMethode, /*number best fit lenses*/ numberBestFitLenses, true, repSequence, light);
	OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();

	real tolerance = 0.1;
	bool checkOptSys = oftenUse::compareTwoOpticalSystemsSurfaces(optSysEle_lensRepSuperFct, bestReplacedOptSys_2, tolerance);
	workTheSystem.push_back(checkOptSys);

	// debug
	oftenUse::print(optSysEle_lensRepSuperFct, 550.0);
	oftenUse::print(bestReplacedOptSys_2, 550.0);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;

}

// E1
bool testLensReplaceAndOptimize::testLensReplaceAndOptimize_E1()
{
	std::vector<bool> workTheSystem;
	real tolerance_rms = 0.1;
	mGlasses.loadGlassCatalog_Schott();

	ApertureStopElement S0(/* semi height*/1.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S2(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S3(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 15.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF57_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S6(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());
	SphericalElement S7(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 200.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S9(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	PlanElement S10(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S2.setParameterRadius(/*min value*/ -1000.0,  /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S9.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	// **********************************

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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	std::vector<real> rms_Zemax{ 35.582, 46.621 };
	std::vector<real> wave_vec{ 550.0, 400.0 };
	std::vector<VectorStructR3> field_vec{ {0.0,0.0,0.0}, {0.0,1.0,0.0} };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, field_vec, wave_vec, rms_Zemax, tolerance_rms, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	LensReplaceAndOptimize lensRepAndOpti;
	int rings = 6;
	int arms = 8;
	optimizeMethode optMethode = optimizeMethode::DLS;
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetEFL(20.0);
	tarCarP.setTargetMag(-1.0);
	lensRepAndOpti.setTargetCardinalPoints(tarCarP);
	defaultParaDLS defParaDLS = oftenUse::getDefaultPara_DLS(true);
	//defParaDLS.setFlipOrientationRadius(500.0);
	defParaDLS.setMaxBorderViolations(200.0);
	lensRepAndOpti.setDefaulParaDLS(defParaDLS);

	// *** set lens catalogs
	std::vector<lensTypes> loadLensCatalogEO_vec;
	loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConvex_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PosAchromat_MgF_Coated);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConvex_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConcav_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConcav_VIS_NIR);
	lensRepAndOpti.setLoadLensCatalogs(loadLensCatalogEO_vec);
	// ***

	unsigned int numberBestFitLenses = 2;

	// 0 lens
	lensRepAndOpti.lensReplaceAndOptimize(optSystemElement, field_vec, wave_vec, rings, arms, optMethode, /*lens number*/ 0, /*number best fit lenses*/numberBestFitLenses, true);
	OpticalSystemElement bestReplacedOptSys_0 = lensRepAndOpti.getBestReplacedOpticalSystem();
	oftenUse::print(bestReplacedOptSys_0, 550.0);
	// 1 lens
	lensRepAndOpti.lensReplaceAndOptimize(bestReplacedOptSys_0, field_vec, wave_vec, rings, arms, optMethode,  /*lens number*/ 1,/*number best fit lenses*/ numberBestFitLenses, false);
	OpticalSystemElement bestReplacedOptSys_1 = lensRepAndOpti.getBestReplacedOpticalSystem();
	oftenUse::print(bestReplacedOptSys_1, 550.0);
	// 2 lens
	lensRepAndOpti.lensReplaceAndOptimize(bestReplacedOptSys_1, field_vec, wave_vec, rings, arms, optMethode,  /*lens number*/ 2,/*number best fit lenses*/ numberBestFitLenses, false);
	OpticalSystemElement bestReplacedOptSys_2 = lensRepAndOpti.getBestReplacedOpticalSystem();
	oftenUse::print(bestReplacedOptSys_2, 550.0);

	LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
	testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(tarCarP);
	testLensReplaceAndOptiSuperFct.setDefaulParaDLS(defParaDLS);
	testLensReplaceAndOptiSuperFct.setLoadLensCatalogs(loadLensCatalogEO_vec);

	replaceSequence repSequence = replaceSequence::leftToRight;
	Light_LLT light = oftenUse::getDefaultLight();
	testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(optSystemElement, field_vec, wave_vec, rings, arms, optMethode, /*number best fit lenses*/ numberBestFitLenses, true, repSequence, light);
	OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();

	real tolerance = 0.1;
	bool checkOptSys = oftenUse::compareTwoOpticalSystemsSurfaces(optSysEle_lensRepSuperFct, bestReplacedOptSys_2, tolerance);
	workTheSystem.push_back(checkOptSys);

	// debug
	oftenUse::print(optSysEle_lensRepSuperFct, 550.0);
	oftenUse::print(bestReplacedOptSys_2, 550.0);

	testLensReplaceAndOptiSuperFct.printBestParameterCatalogForReplace();

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;

}


// E2
bool testLensReplaceAndOptimize::testLensReplaceAndOptimize_E2()
{
	std::vector<bool> workTheSystem;
	real tolerance_rms = 0.1;
	mGlasses.loadGlassCatalog_Schott();

	ApertureStopElement S0(/* semi height*/1.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S3(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 15.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF57_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S6(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());
	SphericalElement S7(/*radius*/ 15.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 100.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S9(/*radius*/ 20.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	PlanElement S10(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S2.setParameterRadius(/*min value*/ -1000.0,  /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0,  /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S9.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	// **********************************

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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	std::vector<real> rms_Zemax{ 371.083, 381.559 };
	std::vector<real> wave_vec{ 550.0, 400.0 };
	std::vector<VectorStructR3> field_vec{ {0.0,0.0,0.0}, {0.0,1.0,0.0} };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, field_vec, wave_vec, rms_Zemax, tolerance_rms, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);


	int rings = 6;
	int arms = 8;
	optimizeMethode optMethode = optimizeMethode::DLS;
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetEFL(20.0);
	tarCarP.setTargetMag(-1.0);
	defaultParaDLS defParaDLS = oftenUse::getDefaultPara_DLS(true);
	//defParaDLS.setFlipOrientationRadius(500.0);
	defParaDLS.setMaxBorderViolations(200.0);

	// *** set lens catalogs
	std::vector<lensTypes> loadLensCatalogEO_vec;
	loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConvex_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PosAchromat_MgF_Coated);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConvex_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConcav_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConcav_VIS_NIR);
	// ***

	unsigned int numberBestFitLenses = 2;

	LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
	testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(tarCarP);
	testLensReplaceAndOptiSuperFct.setDefaulParaDLS(defParaDLS);
	testLensReplaceAndOptiSuperFct.setLoadLensCatalogs(loadLensCatalogEO_vec);

	replaceSequence repSequence = replaceSequence::maxSeidelAberLens;
	Light_LLT light = oftenUse::getDefaultLight();
	testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(optSystemElement, field_vec, wave_vec, rings, arms, optMethode, /*number best fit lenses*/ numberBestFitLenses, true, repSequence, light);
	OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();

	// debug
	oftenUse::print(optSysEle_lensRepSuperFct, 550.0);

	testLensReplaceAndOptiSuperFct.printBestParameterCatalogForReplace();

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// E3
bool testLensReplaceAndOptimize::testLensReplaceAndOptimize_E3()
{
	std::vector<bool> workTheSystem;
	real tolerance_rms = 0.1;
	mGlasses.loadGlassCatalog_Schott();

	ApertureStopElement S0(/* semi height*/1.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S2(/*radius*/ 60.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S3(/*radius*/ 15.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 15.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF57_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S6(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());
	SphericalElement S7(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 100.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S9(/*radius*/ 20.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());
	PlanElement S10(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	// **********************************

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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	std::vector<real> rms_Zemax{ 636.704, 643.913 };
	std::vector<real> wave_vec{ 550.0, 400.0 };
	std::vector<VectorStructR3> field_vec{ {0.0,0.0,0.0}, {0.0,1.0,0.0} };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, field_vec, wave_vec, rms_Zemax, tolerance_rms, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	// save the start system
	std::string location = "../tests/testLensReplaceAndOptimize/E3";
	std::string nameOptSysStart = "E3_optSys_start";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, nameOptSysStart);

	int rings = 6;
	int arms = 8;
	optimizeMethode optMethode = optimizeMethode::DLS;
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetEFL(20.0);
	tarCarP.setTargetMag(-1.0);
	defaultParaDLS defParaDLS = oftenUse::getDefaultPara_DLS(true);
	//defParaDLS.setFlipOrientationRadius(500.0);
	defParaDLS.setMaxBorderViolations(200.0);
	
	// *** set lens catalogs
	std::vector<lensTypes> loadLensCatalogEO_vec;
	loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConvex_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PosAchromat_MgF_Coated);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConvex_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConcav_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConcav_VIS_NIR);
	// ***
	
	unsigned int numberBestFitLenses = 2;
	
	LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
	testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(tarCarP);
	testLensReplaceAndOptiSuperFct.setDefaulParaDLS(defParaDLS);
	testLensReplaceAndOptiSuperFct.setLoadLensCatalogs(loadLensCatalogEO_vec);
	
	replaceSequence repSequence = replaceSequence::allPossibleSequences;
	Light_LLT light = oftenUse::getDefaultLight();
	testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(optSystemElement, field_vec, wave_vec, rings, arms, optMethode, /*number best fit lenses*/ numberBestFitLenses, true, repSequence, light);
	OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();
	
	// debug
	oftenUse::print(optSysEle_lensRepSuperFct, 550.0);
	testLensReplaceAndOptiSuperFct.printBestParameterCatalogForReplace();
	
	// save parameter
	//std::string location = "../tests/testLensReplaceAndOptimize/E3";
	std::string nameOptSysReplaced = "E3_optSys_Replaced";
	std::string bestCatalogLensesForReplace = "E3_bestCatalogLensesForReplace";
	std::string E3_replaceSequence = "E3_replaceSequence";
	
	std::vector<unsigned int> E3_replacedSequence = testLensReplaceAndOptiSuperFct.getReplacedSequence();


	inportExportData::saveOpticalSystemAsTXT(optSysEle_lensRepSuperFct, 550.0, location, nameOptSysReplaced);
	inportExportData::exportIntVecInTXT(location, E3_replaceSequence, "E3_replaceSequence", E3_replacedSequence, true);
	testLensReplaceAndOptiSuperFct.exportBestParameterCatalogForReplaceTXT(location, bestCatalogLensesForReplace);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// E4
bool testLensReplaceAndOptimize::testLensReplaceAndOptimize_E4()
{
	std::vector<bool> workTheSystem;
	real tolerance_rms = 0.1;
	mGlasses.loadGlassCatalog_Schott();

	ApertureStopElement S0(/* semi height*/1.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
	SphericalElement S1(/*radius*/ 50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S2(/*radius*/ 70.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S3(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S4(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF57_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());
	SphericalElement S6(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S7(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	PlanElement S8(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,65.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	std::vector<real> rms_Zemax{ 74.473, 79.297 };
	std::vector<real> wave_vec{ 550.0, 400.0 };
	std::vector<VectorStructR3> field_vec{ {0.0,0.0,0.0}, {0.0,1.0,0.0} };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, field_vec, wave_vec, rms_Zemax, tolerance_rms, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	// save the start system
	std::string location = "../tests/testLensReplaceAndOptimize/E4";
	std::string nameOptSysStart = "E4_optSys_start";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, nameOptSysStart);

	int rings = 6;
	int arms = 8;
	optimizeMethode optMethode = optimizeMethode::DLS;
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetEFL(15.0);
	tarCarP.setTargetMag(-1.5);
	defaultParaDLS defParaDLS = oftenUse::getDefaultPara_DLS(true);
	//defParaDLS.setFlipOrientationRadius(500.0);
	defParaDLS.setMaxBorderViolations(200.0);

	// *** set lens catalogs
	std::vector<lensTypes> loadLensCatalogEO_vec;
	loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConvex_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PosAchromat_MgF_Coated);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConvex_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConcav_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConcav_VIS_NIR);
	// ***

	unsigned int numberBestFitLenses = 2;

	LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
	testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(tarCarP);
	testLensReplaceAndOptiSuperFct.setDefaulParaDLS(defParaDLS);
	testLensReplaceAndOptiSuperFct.setLoadLensCatalogs(loadLensCatalogEO_vec);

	replaceSequence repSequence = replaceSequence::RightToLeft;
	Light_LLT light = oftenUse::getDefaultLight();
	testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(optSystemElement, field_vec, wave_vec, rings, arms, optMethode, /*number best fit lenses*/ numberBestFitLenses, true, repSequence, light);
	OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();

	// debug
	oftenUse::print(optSysEle_lensRepSuperFct, 550.0);
	testLensReplaceAndOptiSuperFct.printBestParameterCatalogForReplace();

	// save parameter
	//std::string location = "../tests/testLensReplaceAndOptimize/E4";
	std::string nameOptSysReplaced = "E4_optSys_Replaced";
	std::string bestCatalogLensesForReplace = "E4_bestCatalogLensesForReplace";
	std::string E4_replaceSequence = "E4_replaceSequence";

	std::vector<unsigned int> E4_replacedSequence = testLensReplaceAndOptiSuperFct.getReplacedSequence();


	inportExportData::saveOpticalSystemAsTXT(optSysEle_lensRepSuperFct, 550.0, location, nameOptSysReplaced);
	inportExportData::exportIntVecInTXT(location, E4_replaceSequence, "E4_replaceSequence", E4_replacedSequence, true);
	testLensReplaceAndOptiSuperFct.exportBestParameterCatalogForReplaceTXT(location, bestCatalogLensesForReplace);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// E5
bool testLensReplaceAndOptimize::testLensReplaceAndOptimize_E5()
{
	std::vector<bool> workTheSystem;
	real tolerance_rms = 0.1;
	mGlasses.loadGlassCatalog_Schott();

	ApertureStopElement S0(/* semi height*/1.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
	SphericalElement S1(/*radius*/ 50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S2(/*radius*/ 70.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S3(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S7(/*radius*/ 100.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S8(/*radius*/ 100.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,60.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S2.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S3.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	// **********************************

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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	std::vector<real> rms_Zemax{ 102.195, 103.094 };
	std::vector<real> wave_vec{ 550.0, 400.0 };
	std::vector<VectorStructR3> field_vec{ {0.0,0.0,0.0}, {0.0,1.0,0.0} };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, field_vec, wave_vec, rms_Zemax, tolerance_rms, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	// save the start system
	std::string location = "../tests/testLensReplaceAndOptimize/E5";
	std::string nameOptSysStart = "E5_optSys_start";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, nameOptSysStart);

	int rings = 6;
	int arms = 8;
	optimizeMethode optMethode = optimizeMethode::DLS;
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetEFL(15.0);
	tarCarP.setTargetMag(-1.0);
	defaultParaDLS defParaDLS = oftenUse::getDefaultPara_DLS(true);
	//defParaDLS.setFlipOrientationRadius(500.0);
	defParaDLS.setMaxBorderViolations(200.0);

	// *** set lens catalogs
	std::vector<lensTypes> loadLensCatalogEO_vec;
	loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConvex_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PosAchromat_MgF_Coated);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConvex_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConcav_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConcav_VIS_NIR);
	// ***

	unsigned int numberBestFitLenses = 2;

	LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
	testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(tarCarP);
	testLensReplaceAndOptiSuperFct.setDefaulParaDLS(defParaDLS);
	testLensReplaceAndOptiSuperFct.setLoadLensCatalogs(loadLensCatalogEO_vec);

	replaceSequence repSequence = replaceSequence::minSeidelAberLens;
	Light_LLT light = oftenUse::getDefaultLight();
	testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(optSystemElement, field_vec, wave_vec, rings, arms, optMethode, /*number best fit lenses*/ numberBestFitLenses, true, repSequence, light);
	OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();

	// debug
	oftenUse::print(optSysEle_lensRepSuperFct, 550.0);
	testLensReplaceAndOptiSuperFct.printBestParameterCatalogForReplace();

	// save parameter
	//std::string location = "../tests/testLensReplaceAndOptimize/E5";
	std::string nameOptSysReplaced = "E5_optSys_Replaced";
	std::string bestCatalogLensesForReplace = "E5_bestCatalogLensesForReplace";
	std::string E5_replaceSequence = "E5_replaceSequence";

	std::vector<unsigned int> E5_replacedSequence = testLensReplaceAndOptiSuperFct.getReplacedSequence();


	inportExportData::saveOpticalSystemAsTXT(optSysEle_lensRepSuperFct, 550.0, location, nameOptSysReplaced);
	inportExportData::exportIntVecInTXT(location, E5_replaceSequence, "E5_replaceSequence", E5_replacedSequence, true);
	testLensReplaceAndOptiSuperFct.exportBestParameterCatalogForReplaceTXT(location, bestCatalogLensesForReplace);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// E6
bool testLensReplaceAndOptimize::testLensReplaceAndOptimize_E6()
{
	std::vector<bool> workTheSystem;
	real tolerance_rms = 0.1;
	mGlasses.loadGlassCatalog_Schott();

	ApertureStopElement S0(/* semi height*/1.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S2(/*radius*/ 60.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S3(/*radius*/ 60.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF57_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S6(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());
	SphericalElement S7(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 100.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S9(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	PlanElement S10(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S9.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	// **********************************

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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	std::vector<real> rms_Zemax{ 42.921, 67.788 };
	std::vector<real> wave_vec{ 550.0, 400.0 };
	std::vector<VectorStructR3> field_vec{ {0.0,0.0,0.0}, {0.0,1.0,0.0} };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, field_vec, wave_vec, rms_Zemax, tolerance_rms, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	// save the start system
	std::string location = "../tests/testLensReplaceAndOptimize/E6";
	std::string nameOptSysStart = "E6_optSys_start";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, nameOptSysStart);

	int rings = 6;
	int arms = 8;
	optimizeMethode optMethode = optimizeMethode::DLS;
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetEFL(15.0);
	tarCarP.setTargetMag(-1.0);
	defaultParaDLS defParaDLS = oftenUse::getDefaultPara_DLS(true);
	//defParaDLS.setFlipOrientationRadius(500.0);
	defParaDLS.setMaxBorderViolations(200.0);

	// *** set lens catalogs
	std::vector<lensTypes> loadLensCatalogEO_vec;
	loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConvex_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PosAchromat_MgF_Coated);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConvex_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConcav_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConcav_VIS_NIR);
	// ***

	unsigned int numberBestFitLenses = 2;

	LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
	testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(tarCarP);
	testLensReplaceAndOptiSuperFct.setDefaulParaDLS(defParaDLS);
	testLensReplaceAndOptiSuperFct.setLoadLensCatalogs(loadLensCatalogEO_vec);
	std::vector<unsigned int> loadSequence = { 1,0,2 };
	testLensReplaceAndOptiSuperFct.loadSequence(loadSequence);

	replaceSequence repSequence = replaceSequence::givenSequence;
	Light_LLT light = oftenUse::getDefaultLight();
	testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(optSystemElement, field_vec, wave_vec, rings, arms, optMethode, /*number best fit lenses*/ numberBestFitLenses, true, repSequence, light);
	OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();

	// debug
	oftenUse::print(optSysEle_lensRepSuperFct, 550.0);
	testLensReplaceAndOptiSuperFct.printBestParameterCatalogForReplace();

	// save parameter
	//std::string location = "../tests/testLensReplaceAndOptimize/E6";
	std::string nameOptSysReplaced = "E6_optSys_Replaced";
	std::string bestCatalogLensesForReplace = "E6_bestCatalogLensesForReplace";
	std::string E6_replaceSequence = "E6_replaceSequence";

	std::vector<unsigned int> E6_replacedSequence = testLensReplaceAndOptiSuperFct.getReplacedSequence();


	inportExportData::saveOpticalSystemAsTXT(optSysEle_lensRepSuperFct, 550.0, location, nameOptSysReplaced);
	inportExportData::exportIntVecInTXT(location, E6_replaceSequence, "E6_replaceSequence", E6_replacedSequence, true);
	testLensReplaceAndOptiSuperFct.exportBestParameterCatalogForReplaceTXT(location, bestCatalogLensesForReplace);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// E7
bool testLensReplaceAndOptimize::testLensReplaceAndOptimize_E7()
{
	std::vector<bool> workTheSystem;
	real tolerance_rms = 0.1;
	mGlasses.loadGlassCatalog_Schott();

	ApertureStopElement S0(/* semi height*/1.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
	SphericalElement S1(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S2(/*radius*/ 60.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S3(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF57_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S6(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());
	SphericalElement S7(/*radius*/ 80.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 100.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF10_S1());
	SphericalElement S9(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF10_S1());
	PlanElement S10(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	// **********************************

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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	std::vector<real> rms_Zemax{ 123.254, 125.290 };
	std::vector<real> wave_vec{ 550.0, 400.0 };
	std::vector<VectorStructR3> field_vec{ {0.0,0.0,0.0}, {0.0,1.0,0.0} };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, field_vec, wave_vec, rms_Zemax, tolerance_rms, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	// save the start system
	std::string location = "../tests/testLensReplaceAndOptimize/E7";
	std::string nameOptSysStart = "E7_optSys_start";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, nameOptSysStart);


	int rings = 6;
	int arms = 8;
	optimizeMethode optMethode = optimizeMethode::DLS_12;
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetEFL(21.0);
	tarCarP.setTargetMag(-1.0);
	
	defaultParaDLS defParaDLS = oftenUse::getDefaultPara_DLS(true);
	//defParaDLS.setFlipOrientationRadius(500.0);
	defParaDLS.setMaxBorderViolations(200.0);

	// *** set lens catalogs
	std::vector<lensTypes> loadLensCatalogEO_vec;
	loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConvex_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PosAchromat_MgF_Coated);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConvex_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConcav_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConcav_VIS_NIR);
	// ***

	unsigned int numberBestFitLenses = 2;

	LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
	testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(tarCarP);
	testLensReplaceAndOptiSuperFct.setDefaulParaDLS(defParaDLS);
	testLensReplaceAndOptiSuperFct.setLoadLensCatalogs(loadLensCatalogEO_vec);
	std::vector<unsigned int> loadSequence = { 1,0,2 };
	testLensReplaceAndOptiSuperFct.loadSequence(loadSequence);

	replaceSequence repSequence = replaceSequence::givenSequence;
	Light_LLT light = oftenUse::getDefaultLight();
	testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(optSystemElement, field_vec, wave_vec, rings, arms, optMethode, /*number best fit lenses*/ numberBestFitLenses, true, repSequence, light);
	OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();

	// debug
	oftenUse::print(optSysEle_lensRepSuperFct, 550.0);
	testLensReplaceAndOptiSuperFct.printBestParameterCatalogForReplace();

	// save parameter
	//std::string location = "../tests/testLensReplaceAndOptimize/E7";
	std::string nameOptSysReplaced = "E7_optSys_Replaced";
	std::string bestCatalogLensesForReplace = "E7_bestCatalogLensesForReplace";
	std::string E7_replaceSequence = "E7_replaceSequence";

	std::vector<unsigned int> E7_replacedSequence = testLensReplaceAndOptiSuperFct.getReplacedSequence();


	inportExportData::saveOpticalSystemAsTXT(optSysEle_lensRepSuperFct, 550.0, location, nameOptSysReplaced);
	inportExportData::exportIntVecInTXT(location, E7_replaceSequence, "E7_replaceSequence", E7_replacedSequence, true);
	testLensReplaceAndOptiSuperFct.exportBestParameterCatalogForReplaceTXT(location, bestCatalogLensesForReplace);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}



// E8
bool testLensReplaceAndOptimize::testLensReplaceAndOptimize_E8()
{
	std::vector<bool> workTheSystem;
	real tolerance_rms = 0.1;
	mGlasses.loadGlassCatalog_Schott();

	ApertureStopElement S0(/* semi height*/1.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
	SphericalElement S1(/*radius*/ 50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S3(/*radius*/ 20.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S4(/*radius*/ 20.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF10_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S7(/*radius*/ 50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF10_S1());
	SphericalElement S8(/*radius*/ 60.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S9(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	PlanElement S10(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	// **********************************

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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	std::vector<real> rms_Zemax{ 42.123, 97.363 };
	std::vector<real> wave_vec{ 550.0, 400.0 };
	std::vector<VectorStructR3> field_vec{ {0.0,0.0,0.0}, {0.0,1.0,0.0} };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, field_vec, wave_vec, rms_Zemax, tolerance_rms, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	// save the start system
	std::string location = "../tests/testLensReplaceAndOptimize/E8";
	std::string nameOptSysStart = "E8_optSys_start";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, nameOptSysStart);

	int rings = 6;
	int arms = 8;
	optimizeMethode optMethode = optimizeMethode::GeneticAndDLS;
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetEFL(15.0);
	tarCarP.setTargetMag(-1.0);
	defaultParaDLS defParaDLS = oftenUse::getDefaultPara_DLS(true);
	//defParaDLS.setFlipOrientationRadius(500.0);
	defParaDLS.setMaxBorderViolations(200.0);
	defaultParaGenetic defParaGenetic = oftenUse::getDafulatPara_Genetic(true);

	// *** set lens catalogs
	std::vector<lensTypes> loadLensCatalogEO_vec;
	loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConvex_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PosAchromat_MgF_Coated);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConvex_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConcav_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConcav_VIS_NIR);
	// ***

	unsigned int numberBestFitLenses = 2;

	LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
	testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(tarCarP);
	testLensReplaceAndOptiSuperFct.setDefaulParaDLS(defParaDLS);
	testLensReplaceAndOptiSuperFct.setDefaultParaGenetic(defParaGenetic);
	testLensReplaceAndOptiSuperFct.setPopulation(1000.0);
	testLensReplaceAndOptiSuperFct.setLoadLensCatalogs(loadLensCatalogEO_vec);
	std::vector<unsigned int> loadSequence = { 1,0,2,3 };
	testLensReplaceAndOptiSuperFct.loadSequence(loadSequence);

	replaceSequence repSequence = replaceSequence::givenSequence;
	Light_LLT light = oftenUse::getDefaultLight();
	testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(optSystemElement, field_vec, wave_vec, rings, arms, optMethode, /*number best fit lenses*/ numberBestFitLenses, true, repSequence, light);
	OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();

	// debug
	oftenUse::print(optSysEle_lensRepSuperFct, 550.0);
	testLensReplaceAndOptiSuperFct.printBestParameterCatalogForReplace();

	// save parameter
	//std::string location = "../tests/testLensReplaceAndOptimize/E8";
	std::string nameOptSysReplaced = "E8_optSys_Replaced";
	std::string bestCatalogLensesForReplace = "E8_bestCatalogLensesForReplace";
	std::string E8_replaceSequence = "E8_replaceSequence";

	std::vector<unsigned int> E8_replacedSequence = testLensReplaceAndOptiSuperFct.getReplacedSequence();


	inportExportData::saveOpticalSystemAsTXT(optSysEle_lensRepSuperFct, 550.0, location, nameOptSysReplaced);
	inportExportData::exportIntVecInTXT(location, E8_replaceSequence, "E8_replaceSequence", E8_replacedSequence, true);
	testLensReplaceAndOptiSuperFct.exportBestParameterCatalogForReplaceTXT(location, bestCatalogLensesForReplace);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// E9
bool testLensReplaceAndOptimize::testLensReplaceAndOptimize_E9()
{
	std::vector<bool> workTheSystem;
	real tolerance_rms = 0.1;
	mGlasses.loadGlassCatalog_Schott();

	ApertureStopElement S0(/* semi height*/1.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
	SphericalElement S1(/*radius*/ 60.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF66_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S3(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 80.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S7(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S8(/*radius*/ 50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S9(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	PlanElement S10(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,75.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	// **********************************

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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	std::vector<real> rms_Zemax{ 123.389, 203.286 };
	std::vector<real> wave_vec{ 550.0, 400.0 };
	std::vector<VectorStructR3> field_vec{ {0.0,0.0,0.0}, {0.0,1.0,0.0} };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, field_vec, wave_vec, rms_Zemax, tolerance_rms, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	// save the start system
	std::string location = "../tests/testLensReplaceAndOptimize/E9";
	std::string nameOptSysStart = "E9_optSys_start";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, 550.0, location, nameOptSysStart);

	int rings = 6;
	int arms = 8;
	optimizeMethode optMethode = optimizeMethode::GeneticAndDLS_12;
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetEFL(15.0);
	tarCarP.setTargetMag(-0.7);
	defaultParaDLS defParaDLS = oftenUse::getDefaultPara_DLS(true);
	//defParaDLS.setFlipOrientationRadius(500.0);
	defParaDLS.setMaxBorderViolations(200.0);
	defaultParaGenetic defParaGenetic = oftenUse::getDafulatPara_Genetic(true);

	// *** set lens catalogs
	std::vector<lensTypes> loadLensCatalogEO_vec;
	loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConvex_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PosAchromat_MgF_Coated);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConvex_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConcav_VIS_NIR);
	loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConcav_VIS_NIR);
	// ***

	unsigned int numberBestFitLenses = 2;

	LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
	testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(tarCarP);
	testLensReplaceAndOptiSuperFct.setDefaulParaDLS(defParaDLS);
	testLensReplaceAndOptiSuperFct.setDefaultParaGenetic(defParaGenetic);
	testLensReplaceAndOptiSuperFct.setPopulation(1000.0);
	testLensReplaceAndOptiSuperFct.setLoadLensCatalogs(loadLensCatalogEO_vec);
	std::vector<unsigned int> loadSequence = { 3,1,0,2 };
	testLensReplaceAndOptiSuperFct.loadSequence(loadSequence);

	replaceSequence repSequence = replaceSequence::givenSequence;
	Light_LLT light = oftenUse::getDefaultLight();
	testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(optSystemElement, field_vec, wave_vec, rings, arms, optMethode, /*number best fit lenses*/ numberBestFitLenses, true, repSequence, light);
	OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();

	// debug
	oftenUse::print(optSysEle_lensRepSuperFct, 550.0);
	testLensReplaceAndOptiSuperFct.printBestParameterCatalogForReplace();

	// save parameter
	//std::string location = "../tests/testLensReplaceAndOptimize/E9";
	std::string nameOptSysReplaced = "E9_optSys_Replaced";
	std::string bestCatalogLensesForReplace = "E9_bestCatalogLensesForReplace";
	std::string E9_replaceSequence = "E9_replaceSequence";

	std::vector<unsigned int> E9_replacedSequence = testLensReplaceAndOptiSuperFct.getReplacedSequence();


	inportExportData::saveOpticalSystemAsTXT(optSysEle_lensRepSuperFct, 550.0, location, nameOptSysReplaced);
	inportExportData::exportIntVecInTXT(location, E9_replaceSequence, "E9_replaceSequence", E9_replacedSequence, true);
	testLensReplaceAndOptiSuperFct.exportBestParameterCatalogForReplaceTXT(location, bestCatalogLensesForReplace);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}