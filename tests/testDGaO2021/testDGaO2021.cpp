#include "testDGaO2021.h"

#pragma once

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
// image simulation
#include "..\..\Image\ImageSimulation.h"
// images
#include"..\..\Image\Images.h"
// DLS 12
#include "..\..\OptimizeSystem\multiThreads\DLS_mulitThreads12.h"

testDGaO2021::testDGaO2021()
{
	loadImportantValues();
}


testDGaO2021::~testDGaO2021() {}

typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;


void testDGaO2021::loadImportantValues()
{
	// load glass catalog
	mGlasses.loadGlassCatalog_Schott();

	// light FdC
	mWave587d = 587.5618;
	mWave486F = 486.1327;
	mWave656C = 656.2725;
	mWavelength_FdV_vec.push_back(mWave587d);
	mWavelength_FdV_vec.push_back(mWave486F);
	mWavelength_FdV_vec.push_back(mWave656C);

	mLight587 = oftenUse::getDefaultLight();
	mLight587.setWavelength(mWave587d);
	mLight486 = oftenUse::getDefaultLight();
	mLight486.setWavelength(mWave486F);
	mLight656 = oftenUse::getDefaultLight();
	mLight656.setWavelength(mWave656C);

	mLight_FdC_Vec.push_back(mLight587);
	mLight_FdC_Vec.push_back(mLight486);
	mLight_FdC_Vec.push_back(mLight656);


	// field obj
	mField0 = { 0.0,0.0,0.0 };
	mField707 = { 0.0,707.0, 0.0 };
	mField1000 = { 0.0,1000.0,0.0 };
	mField_vec.push_back(mField0);
	mField_vec.push_back(mField707);
	mField_vec.push_back(mField1000);

	mTolerance = 0.1;
	mRings = 6;
	mArms = 8;

	mDefaulParaDLS = oftenUse::getDefaultPara_DLS(true);
	mDefaultParameterGenetic = oftenUse::getDafulatPara_Genetic(true);
	mPopulation = 1000.0;

	mNumberBestFitLenses = 5;

	mTargetMag = -0.003;
	mTargetWFNO = 6.0;
	mTargetCarPoints.setTargetMag(mTargetMag);
	mTargetCarPoints.setTargetWFNO(mTargetWFNO);

	mLocation_E0 = "../tests/testDGaO2021/E0";
	mLocation_E0_LeftToRight = "../tests/testDGaO2021/E0/leftToRight";
	mLocation_E0_LeftToRight_stepByStep = "../tests/testDGaO2021/E0/leftToRight/stepByStep";
	mLocation_E0_RightToLeft = "../tests/testDGaO2021/E0/rightToLeft";
	mLocation_E0_allPosSequences = "../tests/testDGaO2021/E0/allPossibleSequences";

	mLocation_E1 = "../tests/testDGaO2021/E1";
	mLocation_E1_LeftToRight = "../tests/testDGaO2021/E1/leftToRight";
	mLocation_E1_allSequences = "../tests/testDGaO2021/E1/allSequences";

	mLocation_E2 = "../tests/testDGaO2021/E2";
	mLocation_E2_allSequences = "../tests/testDGaO2021/E2/allSequences";

	// *** basics E3 ***
	mLocationE3 = "../tests/testDGaO2021/E3";
	mField_0 = { 0.0,0.0,0.0 };
	mField_176 = { 0.0,176.78,0.0 };
	mField_250 = { 0.0,250.0,0.0 };
	mField_E3_vec.push_back(mField_0);
	mField_E3_vec.push_back(mField_176);
	mField_E3_vec.push_back(mField_250);
	mTargetCarPoints_E3.setTargetMag(-0.05);
	mLocation_E3_leftToRight = "../tests/testDGaO2021/E3/leftToRight";
	// *** ***

	// *** basics E4 ***
	mLocation_E4 = "../tests/testDGaO2021/E4";
	mField_17_67 = { 0.0,17.67767,0.0 };
	mField_25 = { 0.0, 25.0,0.0 };
	mField_E4_vec.push_back(mField_0);
	mField_E4_vec.push_back(mField_17_67);
	mField_E4_vec.push_back(mField_25);
	mTargetCarPoints_E4.setTargetMag(-0.2);
	mTargetCarPoints_E4.setTargetWFNO(5.0);
	// *** ***

	// *** E4 ***
	mLocation_E5 = "../tests/testDGaO2021/E5";
	mField_35355 = { 0.0,35.355,0.0 };
	mField_50 = { 0.0,50.0,0.0 };;
	mField_E5_vec.push_back(mField_0);
	mField_E5_vec.push_back(mField_35355);
	mField_E5_vec.push_back(mField_50);
	mTargetCarPoints_E5.setTargetMag(-0.1);
	mTargetCarPoints_E5.setTargetWFNO(5.0);
	// *** ***

	// *** basics E21 ***
	mLocationE21 = "../tests/testDGaO2021/E21";
	mField_E21_0 = { 0.0,0.0,0.0 };
	mField_E21_283 = { 0.0, 2.83, 0.0 };
	mField_E21_4 = { 0.0,4.0,0.0 };
	mField_E21_vec.push_back(mField_E21_0);
	mField_E21_vec.push_back(mField_E21_283);
	mField_E21_vec.push_back(mField_E21_4);
	// *** ***
}

void testDGaO2021::turn_ON_DebugMode()
{
	mDebugMode = true;

	mDefaulParaDLS.setMaxInterations(1);
	mDefaultParameterGenetic.setMaxInterationGenetic(1);
	mPopulation = 1;
	mNumberBestFitLenses = 1;


}
void testDGaO2021::turn_OFF_DebugMode()
{
	mDebugMode = false;

	mDefaulParaDLS = oftenUse::getDefaultPara_DLS(true);
	mDefaultParameterGenetic = oftenUse::getDafulatPara_Genetic(true);
	mPopulation = 1000.0;
}

bool testDGaO2021::testDGaO2021_superFct()
{
	std::vector<bool> workTheSystem;

	
	turn_ON_DebugMode();
	//turn_OFF_DebugMode();


	// E0
	bool checkE0 = checkE0_DGaO2021();
	workTheSystem.push_back(checkE0);

	//// E1
	//bool checkE1 = checkE1_DGaO2021();
	//workTheSystem.push_back(checkE1);

	//// E2
	//bool checkE2 = checkE2_DGaO2021();
	//workTheSystem.push_back(checkE2);

	//// E3
	//bool checkE3 = checkE3_DGaO2021();
	//workTheSystem.push_back(checkE3);

	//// *** E4 ***
	//bool checkE4 = checkE4_superFct();
	//workTheSystem.push_back(checkE4);
	//// *** *** //

	//// *** E5 ***
	//bool checkE5 = checkE5_superFct();
	//workTheSystem.push_back(checkE5);

	// E21
	//bool checkE21 = checkE21_fromStatLensRepl_threeLensSys();
	//workTheSystem.push_back(checkE21);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}


bool testDGaO2021::checkE0_DGaO2021()
{
	std::vector<bool> workTheSystem;

	//// check the start system
	bool checkTheStartSystem = E0_checkStartSystem();
	workTheSystem.push_back(checkTheStartSystem);
	//
	//// check load optimized system
	bool checkLoadOptimizedSystem = E0_loadOptimizedSystem();
	workTheSystem.push_back(checkLoadOptimizedSystem);
	
	// check first optimisation
	bool checkOptimizationStartSystem = E0_checkOptimizeStartSystem_DoOptimization();
	workTheSystem.push_back(checkOptimizationStartSystem);
	
	// check Lens replace and optimize leftToRight
	bool checkLRaO_leftToRight = E0_checkLensReplaceAndOptimizeLeftToRight();
	workTheSystem.push_back(checkLRaO_leftToRight);
	
	// check replace system
	bool checkReplacedSystem_E0 = E0_loadReplacedSystem_leftToRight();
	workTheSystem.push_back(checkReplacedSystem_E0);
	//
	// do image simulation with E0
	bool checkImaSim_E0 = E0_checkImageSimulationReplacedSystem();
	workTheSystem.push_back(checkImaSim_E0);

	// replace Lens 0
	bool checRreplace_0 = replaceLenses_andOptimize_stepByStep();
	workTheSystem.push_back(checRreplace_0);

	// do image simulation with E0 first optimized system
	bool checkImaSimFirstOptiSys = E0_checkImageSimulationFirstOptimization();
	workTheSystem.push_back(checkImaSimFirstOptiSys);

	// find lenses for first optimized system
	bool checkFindLensesForFirstOptiSys = findLensesForFirstOptimizedSystem();
	workTheSystem.push_back(checkFindLensesForFirstOptiSys);

	// replace left to right and image simulation
	bool checkE0_replace_LeftToRight_andImaSim = E0_replace_LeftToRight_andImaSim();
	workTheSystem.push_back(checkE0_replace_LeftToRight_andImaSim);

	// replace all sequences and image simulation
	bool checkE0_replace_AllSequences_andImaSim = E0_replace_AllSequences_andImaSim();
	workTheSystem.push_back(checkE0_replace_AllSequences_andImaSim);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::E0_checkStartSystem()
{
	std::vector<bool> workTheSystem;

	real semiHeight = 15.0;
	real firstThickness = 20000.0;

	ApertureStopElement S0(/* semi height*/5.0, /*point*/{ 0.0,0.0, firstThickness + 10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 20.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 180.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 30.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 900.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 40.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S4(/*radius*/ 25.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S6(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 70.0 }, /*direction*/{ 0.0,0.0,   1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S7(/*radius*/ 22.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF10_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S8(/*radius*/ 25.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 90.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getNSF10_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S9(/*radius*/ 22.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 100.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S10(/*radius*/40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 110.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getAir());

	PlanElement S11(/*semi height*/ 99.0, /*point*/{ 0.0,0.0, firstThickness + 125.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	// radii
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	// thicknesses
	S3.setParameterPointZ(/*min value*/ 10.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 10.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/ 10.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/10.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S11_ptr = S11.clone();


	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	mStartOpticalSystem_E0.fillPosAndElementAndInteraction(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(mStartOpticalSystem_E0, 550.0);
	// save the start system

	inportExportData::saveOpticalSystemAsTXT(mStartOpticalSystem_E0, 550.0, mLocation_E0, "E0_start_DGaO2021");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(mStartOpticalSystem_E0);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 162.123, 159.829, 157.617 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(mStartOpticalSystem_E0, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);


	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// check optimize start system
bool testDGaO2021::E0_checkOptimizeStartSystem_DoOptimization()
{
	std::vector<bool> workTheSystem;

	OpticalSystemElement initalOpticalSystemEle = mStartOpticalSystem_E0.getDeepCopyOptSysEle();


	// optimize optical system
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ initalOpticalSystemEle,/*fields*/ mField_vec, /*wavelength*/ mWavelength_FdV_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default Genetic*/mDefaultParameterGenetic, /*default DLS*/ mDefaulParaDLS);
	mOptimizedOpticalSystemEle_E0 = GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();

	// export the first optimized system
	inportExportData::saveOpticalSystemAsTXT(mOptimizedOpticalSystemEle_E0, 550.0, mLocation_E0, "E0_optimized_first_DGaO2021");


	// check optimized system
	std::vector<real> rmsVecInitalOptSys = oftenUse::getRMSoptSysHLT(mStartOpticalSystem_E0, mField_vec, mWavelength_FdV_vec, mRings, mArms);
	std::vector<real> rmsVecGeneticDLS_12 = oftenUse::getRMSoptSysHLT(mOptimizedOpticalSystemEle_E0, mField_vec, mWavelength_FdV_vec, mRings, mArms);

	real sumRMS_initalOptSys = oftenUse::sum(rmsVecInitalOptSys);
	real sumRMS_optimizedOptSys = oftenUse::sum(rmsVecGeneticDLS_12);

	bool checkOptimization = sumRMS_initalOptSys > sumRMS_optimizedOptSys;
	workTheSystem.push_back(checkOptimization);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// find best lenses in optimized system
bool testDGaO2021::E0_findBestLensesInOptimizedSystem()
{
	std::vector<bool> workTheSystem;

	if (mOptimizedOpticalSystemEle_E0.getPosAndElement().size() < mStartOpticalSystem_E0.getPosAndElement().size())
	{
		bool checkLoadOptimizedSystem = E0_loadOptimizedSystem();
		workTheSystem.push_back(checkLoadOptimizedSystem);
	}

	// replace lenses
	LensReplace lensReplace;
	lensReplace.setRefIndexSurroundMat(1.0);
	lensReplace.replaceSuperFuction(mOptimizedOpticalSystemEle_E0);

	lensReplace.load_ALL_LensCatalogs();

	lensReplace.replaceLensesAccordingToLensReplaceSequence_superFct(replaceSequence::leftToRight, 3);
	std::vector<OpticalSystemElement> replacedOptSysEle_vec = lensReplace.getOpticalSysEle_replacedLens_vec();



	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// load optimized System
bool testDGaO2021::E0_loadOptimizedSystem()
{
	std::vector<bool> workTheSystem;

	real semiHeight = 15.0;
	real firstThickness = 20000.0;

	ApertureStopElement S0(/* semi height*/5.0, /*point*/{ 0.0,0.0, firstThickness + 10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 194.02600, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 20.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 308.30890, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 30.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 390.31227, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 40.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S4(/*radius*/ 96.89852, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 55.54023 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 139.88140, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 65.54023 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S6(/*radius*/ 251.25247, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 78.26542 }, /*direction*/{ 0.0,0.0,   1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S7(/*radius*/ 22.52321, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 88.26542 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF10_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S8(/*radius*/ 284.77496, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 98.26542 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF10_S1());

	SphericalElement S9(/*radius*/ 86.84694, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 119.2815 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S10(/*radius*/192.66508, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 129.2815 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	PlanElement S11(/*semi height*/ 99.0, /*point*/{ 0.0,0.0, firstThickness + 140.0227 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	// thicknesses
	S3.setParameterPointZ(/*min value*/ 10.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 10.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/ 10.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/10.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S11_ptr = S11.clone();


	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	mOptimizedOpticalSystemEle_E0.fillPosAndElementAndInteraction(opticalSystem_ptr, interactions_ptr);

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(mOptimizedOpticalSystemEle_E0);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_optimized{ 1.386, 4.539, 6.521 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(mOptimizedOpticalSystemEle_E0, mField_vec, mWavelength_FdV_vec, rms_optimized, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// load Replaced System
bool testDGaO2021::E0_loadReplacedSystem_leftToRight()
{
	std::vector<bool> workTheSystem;

	real firstThickness = 20000.0;
	real semiHeight = 15.0;

	ApertureStopElement S0(/* semi height*/5.0, /*point*/{ 0.0,0.0, firstThickness + 10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	// EO49364
	SphericalElement S1(/*radius*/ 124.12, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 20.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 87.26, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 28.5 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 253.1, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 32.5 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	//TH Lh1015
	SphericalElement S4(/*radius*/ 95.11, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 62.5 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S5(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 65.5 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	
	SphericalElement S6(/*radius*/ 51.98263, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 75.5 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S7(/*radius*/ 43.36338, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 83.5 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getNSF6_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S8(/*radius*/ 217.3623, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 87.5 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());
	
	SphericalElement S9(/*radius*/91.31, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 97.5 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S10(/*radius*/65.57, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 105.6 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S11(/*radius*/195.87, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 108.2 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0, firstThickness + 136.8464 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	surfacePtr S12_ptr = S12.clone();


	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	mReplacedOpticalSystemEle_E0.fillPosAndElementAndInteraction(opticalSystem_ptr, interactions_ptr);

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(mReplacedOpticalSystemEle_E0);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_ReplacedSystem{ 12.314, 8.712, 5.538 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(mReplacedOpticalSystemEle_E0, mField_vec, mWavelength_FdV_vec, rms_ReplacedSystem, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	inportExportData::saveOpticalSystemAsTXT(mReplacedOpticalSystemEle_E0, 550.0, mLocation_E0_LeftToRight, "E0_ReplacedSystem_LeftToRigth_loaded");

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// do image simulation with E0 first optimized system
bool testDGaO2021::E0_checkImageSimulationFirstOptimization()
{
	if (mOptimizedOpticalSystemEle_E0.getPosAndElement().size() < 1)
	{
		E0_loadOptimizedSystem();
	}

	loadParaImaSim parameterImaSim{};
	parameterImaSim.setWavelengthBlue(486.1327);
	parameterImaSim.setWavelengthGreen(587.5818);
	parameterImaSim.setWavelengthRed(656.2725);
	parameterImaSim.setRayDensity(30);

	//light
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	light.setJonesVector({ 1.0,1.0,1.0,1.0 });
	light.setTypeLight(typeLight::typeLightRay);

	parameterImaSim.setLight(light);
	parameterImaSim.setSizeMatrixToSaveOPD(64);
	parameterImaSim.setInfOrObj(objectPoint_inf_obj::obj);
	parameterImaSim.setRowColResizeOPD(128);
	parameterImaSim.setSampling_x(11);
	parameterImaSim.setSampling_y(11);
	parameterImaSim.setSemiHeightObj(1000.0);
	parameterImaSim.setSemiWeidthObj(1000.0);
	parameterImaSim.setPosition_Z_Object(0.0);
	parameterImaSim.setUpSamplePSF(true);
	parameterImaSim.setResizeOPD_linear(true);
	parameterImaSim.setPaddingFactorPSF(1);
	parameterImaSim.setCalcDistortion(true);
	parameterImaSim.setSamplingDistortionHeight(450);
	parameterImaSim.setSamplingDistortionWidth(450);

	// load object
	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_900x900.png", CV_LOAD_IMAGE_COLOR);

	ImageSimulationFunctions imaSim;
	imaSim.imageSimulationSuperFct(/*optical System Element*/ mOptimizedOpticalSystemEle_E0, /*object*/ elefantObj, /*parameter*/ parameterImaSim);

	cv::Mat simulatedIma = imaSim.getSimulatedImage_initialSize();
	// just for debugging
	//Images::showImage_inputReal_normTheImage("simulatedIma_E0_ReplaceLeftToRight", simulatedIma);
	// save the simulate images
	Images::saveImage_normalized(mLocation_E0_LeftToRight, "simulatedIma_E0_FirstOptimizedSystem", "png", simulatedIma);

	return true;
}

// do image simulation with E0
bool testDGaO2021::E0_checkImageSimulationReplacedSystem()
{
	if (mReplacedOpticalSystemEle_E0.getPosAndElement().size() < 1)
	{
		E0_loadReplacedSystem_leftToRight();
	}

	loadParaImaSim parameterImaSim{};
	parameterImaSim.setWavelengthBlue(486.1327);
	parameterImaSim.setWavelengthGreen(587.5818);
	parameterImaSim.setWavelengthRed(656.2725);
	parameterImaSim.setRayDensity(30);

	//light
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	light.setJonesVector({ 1.0,1.0,1.0,1.0 });
	light.setTypeLight(typeLight::typeLightRay);

	parameterImaSim.setLight(light);
	parameterImaSim.setSizeMatrixToSaveOPD(64);
	parameterImaSim.setInfOrObj(objectPoint_inf_obj::obj);
	parameterImaSim.setRowColResizeOPD(128);
	parameterImaSim.setSampling_x(11);
	parameterImaSim.setSampling_y(11);
	parameterImaSim.setSemiHeightObj(1000.0);
	parameterImaSim.setSemiWeidthObj(1000.0);
	parameterImaSim.setPosition_Z_Object(0.0);
	parameterImaSim.setUpSamplePSF(true);
	parameterImaSim.setResizeOPD_linear(true);
	parameterImaSim.setPaddingFactorPSF(1);
	parameterImaSim.setCalcDistortion(true);
	parameterImaSim.setSamplingDistortionHeight(450);
	parameterImaSim.setSamplingDistortionWidth(450);

	// load object
	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_900x900.png", CV_LOAD_IMAGE_COLOR);

	ImageSimulationFunctions imaSim;
	imaSim.imageSimulationSuperFct(/*optical System Element*/ mReplacedOpticalSystemEle_E0, /*object*/ elefantObj, /*parameter*/ parameterImaSim);

	cv::Mat simulatedIma = imaSim.getSimulatedImage_initialSize();
	// just for debugging
	//Images::showImage_inputReal_normTheImage("simulatedIma_E0_ReplaceLeftToRight", simulatedIma);
	// save the simulate images
	Images::saveImage_normalized(mLocation_E0_LeftToRight, "simulatedIma_E0_ReplaceLeftToRight", "png", simulatedIma);

	return true;
}

// replace lens 0 and optimize
bool testDGaO2021::replaceLenses_andOptimize_stepByStep()
{
	optimizeMethode optMethode = optimizeMethode::GeneticAndDLS_12;
	std::vector<std::string> nameDoubel_vec = { "field0", "field707", "field1000" };
	replaceSequence repSeq = replaceSequence::givenSequence;

	if (mOptimizedOpticalSystemEle_E0.getPosAndElement().size() < 1)
	{
		E0_loadOptimizedSystem();
	}

	// ____________________________________________
	// replace lenses _0
	LensReplace lensReplace_0;
	lensReplace_0.setRefIndexSurroundMat(1.0);
	lensReplace_0.replaceSuperFuction(mOptimizedOpticalSystemEle_E0);
	lensReplace_0.load_ALL_LensCatalogs();
	// zero lens
	unsigned int lensNumber_0 = 0;
	std::string name_bestLensForReplace_0 = "bestLensesForReplace_0";
	std::vector<OptSysEle_Merit_LensType> bestLens_0 = lensReplace_0.checkLensCatalogsForBestFitLenses_many(/*lens number*/lensNumber_0, /*parameter lens*/ lensReplace_0.getParameterLenses()[lensNumber_0], mNumberBestFitLenses);
	
	std::string location_E0_LeftToRight_stepByStep_0 = mLocation_E0_LeftToRight_stepByStep + "/lens_0";
	inportExportData::clearDataInTXT(location_E0_LeftToRight_stepByStep_0, name_bestLensForReplace_0);
	for (unsigned int i = 0; i < bestLens_0.size(); ++i)
	{
		bestLens_0[i].exportDataToTXT(location_E0_LeftToRight_stepByStep_0, name_bestLensForReplace_0);
	}

	LensReplaceAndOptimize lensReplaceAndOpti_0;
	lensReplaceAndOpti_0.setTargetCardinalPoints(mTargetCarPoints);
	lensReplaceAndOpti_0.setDefaulParaDLS(mDefaulParaDLS);
	lensReplaceAndOpti_0.setDefaultParaGenetic(mDefaultParameterGenetic);
	lensReplaceAndOpti_0.setPopulation(mPopulation);
	lensReplaceAndOpti_0.setLoad_ALL_LensCatalogs();
	std::vector<unsigned int> sequence_0 = { 0 };
	lensReplaceAndOpti_0.loadSequence(sequence_0);
	lensReplaceAndOpti_0.lensReplaceAndOptimize_superFct(mOptimizedOpticalSystemEle_E0, mField_vec, mWavelength_FdV_vec, mRings, mArms, optMethode, /*number best fit lenses*/ mNumberBestFitLenses, false, repSeq, mLight587);
	OpticalSystemElement optSysEle_Replace_0 = lensReplaceAndOpti_0.getBestReplacedOpticalSystem();

	// save parameter
	std::string nameOptSysReplaced_0 = "E0_optSysDGaO_Replaced_0";
	std::string bestCatalogLensesForReplace_0 = "E0_bestCatalogLensesForReplace_DGaO2021_0";
	std::string replaceSequence_0 = "E0_replaceSequence_DGaO2021_0";
	std::string replaceRMSvalue_0 = "E0_replacedRMSvalues_0";

	std::vector<unsigned int> replacedSequenceDGaO2021_vec_0 = lensReplaceAndOpti_0.getReplacedSequence();

	
	inportExportData::saveOpticalSystemAsTXT(optSysEle_Replace_0, 550.0, location_E0_LeftToRight_stepByStep_0, nameOptSysReplaced_0);
	inportExportData::exportIntVecInTXT(location_E0_LeftToRight_stepByStep_0, replaceSequence_0, replaceSequence_0, replacedSequenceDGaO2021_vec_0, true);
	lensReplaceAndOpti_0.exportBestParameterCatalogForReplaceTXT(location_E0_LeftToRight_stepByStep_0, bestCatalogLensesForReplace_0);

	// export rms values
	std::vector<real> rmsVecReplaceSys_0 = oftenUse::getRMSoptSysHLT(optSysEle_Replace_0, mField_vec, mWavelength_FdV_vec, mRings, mArms);
	inportExportData::saveVecDoubleInTXT(location_E0_LeftToRight_stepByStep_0, replaceRMSvalue_0, nameDoubel_vec, rmsVecReplaceSys_0, true);
	// ____________________________________________

	
	// ____________________________________________
	// replace lenses _1
	LensReplace lensReplace_1;
	lensReplace_1.setRefIndexSurroundMat(1.0);
	lensReplace_1.replaceSuperFuction(optSysEle_Replace_0);
	lensReplace_1.load_ALL_LensCatalogs();
	// zero lens
	unsigned int lensNumber_1 = 1;
	std::string name_bestLensForReplace_1 = "bestLensesForReplace_1";
	std::vector<OptSysEle_Merit_LensType> bestLens_1 = lensReplace_1.checkLensCatalogsForBestFitLenses_many(/*lens number*/lensNumber_1, /*parameter lens*/ lensReplace_1.getParameterLenses()[lensNumber_1], mNumberBestFitLenses);

	std::string location_E0_LeftToRight_stepByStep_1 = mLocation_E0_LeftToRight_stepByStep + "/lens_1";
	inportExportData::clearDataInTXT(location_E0_LeftToRight_stepByStep_1, name_bestLensForReplace_1);
	for (unsigned int i = 0; i < bestLens_1.size(); ++i)
	{
		bestLens_1[i].exportDataToTXT(location_E0_LeftToRight_stepByStep_1, name_bestLensForReplace_1);
	}

	LensReplaceAndOptimize lensReplaceAndOpti_1;
	lensReplaceAndOpti_1.setTargetCardinalPoints(mTargetCarPoints);
	lensReplaceAndOpti_1.setDefaulParaDLS(mDefaulParaDLS);
	lensReplaceAndOpti_1.setDefaultParaGenetic(mDefaultParameterGenetic);
	lensReplaceAndOpti_1.setPopulation(mPopulation);
	lensReplaceAndOpti_1.setLoad_ALL_LensCatalogs();

	std::vector<unsigned int> sequence_1 = { 1 };
	lensReplaceAndOpti_1.loadSequence(sequence_1);
	lensReplaceAndOpti_1.lensReplaceAndOptimize_superFct(optSysEle_Replace_0, mField_vec, mWavelength_FdV_vec, mRings, mArms, optMethode, /*number best fit lenses*/ mNumberBestFitLenses, false, repSeq, mLight587);
	OpticalSystemElement optSysEle_Replace_1 = lensReplaceAndOpti_1.getBestReplacedOpticalSystem();

	// save parameter
	std::string nameOptSysReplaced_1 = "E0_optSysDGaO_Replaced_1";
	std::string bestCatalogLensesForReplace_1 = "E0_bestCatalogLensesForReplace_DGaO2021_1";
	std::string replaceSequence_1 = "E0_replaceSequence_DGaO2021_1";
	std::string replaceRMSvalue_1 = "E0_replacedRMSvalues_1";

	std::vector<unsigned int> replacedSequenceDGaO2021_vec_1 = lensReplaceAndOpti_1.getReplacedSequence();


	inportExportData::saveOpticalSystemAsTXT(optSysEle_Replace_1, 550.0, location_E0_LeftToRight_stepByStep_1, nameOptSysReplaced_1);
	inportExportData::exportIntVecInTXT(location_E0_LeftToRight_stepByStep_1, replaceSequence_1, replaceSequence_1, replacedSequenceDGaO2021_vec_1, true);
	lensReplaceAndOpti_1.exportBestParameterCatalogForReplaceTXT(location_E0_LeftToRight_stepByStep_1, bestCatalogLensesForReplace_1);

	// export rms values
	std::vector<real> rmsVecReplaceSys_1 = oftenUse::getRMSoptSysHLT(optSysEle_Replace_1, mField_vec, mWavelength_FdV_vec, mRings, mArms);
	inportExportData::saveVecDoubleInTXT(location_E0_LeftToRight_stepByStep_1, replaceRMSvalue_1, nameDoubel_vec, rmsVecReplaceSys_1, true);
	// ____________________________________________

	// ____________________________________________
	// replace lenses _2
	LensReplace lensReplace_2;
	lensReplace_2.setRefIndexSurroundMat(1.0);
	lensReplace_2.replaceSuperFuction(optSysEle_Replace_1);
	lensReplace_2.load_ALL_LensCatalogs();
	// zero lens
	unsigned int lensNumber_2 = 2;
	std::string name_bestLensForReplace_2 = "bestLensesForReplace_2";
	std::vector<OptSysEle_Merit_LensType> bestLens_2 = lensReplace_2.checkLensCatalogsForBestFitLenses_many(/*lens number*/lensNumber_2, /*parameter lens*/ lensReplace_2.getParameterLenses()[lensNumber_2], mNumberBestFitLenses);

	std::string location_E0_LeftToRight_stepByStep_2 = mLocation_E0_LeftToRight_stepByStep + "/lens_2";
	inportExportData::clearDataInTXT(location_E0_LeftToRight_stepByStep_2, name_bestLensForReplace_2);
	for (unsigned int i = 0; i < bestLens_2.size(); ++i)
	{
		bestLens_2[i].exportDataToTXT(location_E0_LeftToRight_stepByStep_2, name_bestLensForReplace_2);
	}

	LensReplaceAndOptimize lensReplaceAndOpti_2;
	lensReplaceAndOpti_2.setTargetCardinalPoints(mTargetCarPoints);
	lensReplaceAndOpti_2.setDefaulParaDLS(mDefaulParaDLS);
	lensReplaceAndOpti_2.setDefaultParaGenetic(mDefaultParameterGenetic);
	lensReplaceAndOpti_2.setPopulation(mPopulation);
	lensReplaceAndOpti_2.setLoad_ALL_LensCatalogs();
	std::vector<unsigned int> sequence_2 = { 2 };
	lensReplaceAndOpti_2.loadSequence(sequence_2);
	lensReplaceAndOpti_2.lensReplaceAndOptimize_superFct(optSysEle_Replace_1, mField_vec, mWavelength_FdV_vec, mRings, mArms, optMethode, /*number best fit lenses*/ mNumberBestFitLenses, false, repSeq, mLight587);
	OpticalSystemElement optSysEle_Replace_2 = lensReplaceAndOpti_2.getBestReplacedOpticalSystem();

	// save parameter
	std::string nameOptSysReplaced_2 = "E0_optSysDGaO_Replaced_2";
	std::string bestCatalogLensesForReplace_2 = "E0_bestCatalogLensesForReplace_DGaO2021_2";
	std::string replaceSequence_2 = "E0_replaceSequence_DGaO2021_2";
	std::string replaceRMSvalue_2 = "E0_replacedRMSvalues_2";

	std::vector<unsigned int> replacedSequenceDGaO2021_vec_2 = lensReplaceAndOpti_2.getReplacedSequence();

	inportExportData::saveOpticalSystemAsTXT(optSysEle_Replace_2, 550.0, location_E0_LeftToRight_stepByStep_2, nameOptSysReplaced_2);
	inportExportData::exportIntVecInTXT(location_E0_LeftToRight_stepByStep_2, replaceSequence_2, replaceSequence_2, replacedSequenceDGaO2021_vec_2, true);
	lensReplaceAndOpti_2.exportBestParameterCatalogForReplaceTXT(location_E0_LeftToRight_stepByStep_2, bestCatalogLensesForReplace_2);

	// export rms values
	std::vector<real> rmsVecReplaceSys_2 = oftenUse::getRMSoptSysHLT(optSysEle_Replace_2, mField_vec, mWavelength_FdV_vec, mRings, mArms);
	inportExportData::saveVecDoubleInTXT(location_E0_LeftToRight_stepByStep_2, replaceRMSvalue_2, nameDoubel_vec, rmsVecReplaceSys_2, true);
	// ____________________________________________

	// ____________________________________________
	// replace lenses _3
	LensReplace lensReplace_3;
	lensReplace_3.setRefIndexSurroundMat(1.0);
	lensReplace_3.replaceSuperFuction(optSysEle_Replace_2);
	lensReplace_3.load_ALL_LensCatalogs();
	// zero lens
	unsigned int lensNumber_3 = 3;
	std::string name_bestLensForReplace_3 = "bestLensesForReplace_3";
	std::vector<OptSysEle_Merit_LensType> bestLens_3 = lensReplace_3.checkLensCatalogsForBestFitLenses_many(/*lens number*/lensNumber_3, /*parameter lens*/ lensReplace_3.getParameterLenses()[lensNumber_3], mNumberBestFitLenses);

	std::string location_E0_LeftToRight_stepByStep_3 = mLocation_E0_LeftToRight_stepByStep + "/lens_3";
	inportExportData::clearDataInTXT(location_E0_LeftToRight_stepByStep_3, name_bestLensForReplace_3);
	for (unsigned int i = 0; i < bestLens_3.size(); ++i)
	{
		bestLens_3[i].exportDataToTXT(location_E0_LeftToRight_stepByStep_3, name_bestLensForReplace_3);
	}

	LensReplaceAndOptimize lensReplaceAndOpti_3;
	lensReplaceAndOpti_3.setTargetCardinalPoints(mTargetCarPoints);
	lensReplaceAndOpti_3.setDefaulParaDLS(mDefaulParaDLS);
	lensReplaceAndOpti_3.setDefaultParaGenetic(mDefaultParameterGenetic);
	lensReplaceAndOpti_3.setPopulation(mPopulation);
	lensReplaceAndOpti_3.setLoad_ALL_LensCatalogs();
	std::vector<unsigned int> sequence_3 = { 3 };
	lensReplaceAndOpti_3.loadSequence(sequence_3);
	lensReplaceAndOpti_3.lensReplaceAndOptimize_superFct(optSysEle_Replace_2, mField_vec, mWavelength_FdV_vec, mRings, mArms, optMethode, /*number best fit lenses*/ mNumberBestFitLenses, false, repSeq, mLight587);
	OpticalSystemElement optSysEle_Replace_3 = lensReplaceAndOpti_3.getBestReplacedOpticalSystem();

	// save parameter
	std::string nameOptSysReplaced_3 = "E0_optSysDGaO_Replaced_3";
	std::string bestCatalogLensesForReplace_3 = "E0_bestCatalogLensesForReplace_DGaO2021_3";
	std::string replaceSequence_3 = "E0_replaceSequence_DGaO2021_3";
	std::string replaceRMSvalue_3 = "E0_replacedRMSvalues_3";

	std::vector<unsigned int> replacedSequenceDGaO2021_vec_3 = lensReplaceAndOpti_3.getReplacedSequence();

	inportExportData::saveOpticalSystemAsTXT(optSysEle_Replace_3, 550.0, location_E0_LeftToRight_stepByStep_3, nameOptSysReplaced_3);
	inportExportData::exportIntVecInTXT(location_E0_LeftToRight_stepByStep_3, replaceSequence_3, replaceSequence_3, replacedSequenceDGaO2021_vec_3, true);
	lensReplaceAndOpti_3.exportBestParameterCatalogForReplaceTXT(location_E0_LeftToRight_stepByStep_3, bestCatalogLensesForReplace_3);

	// export rms values
	std::vector<real> rmsVecReplaceSys_3 = oftenUse::getRMSoptSysHLT(optSysEle_Replace_3, mField_vec, mWavelength_FdV_vec, mRings, mArms);
	inportExportData::saveVecDoubleInTXT(location_E0_LeftToRight_stepByStep_3, replaceRMSvalue_3, nameDoubel_vec, rmsVecReplaceSys_3, true);
	// ____________________________________________

	return true;
}

// find lenses for first optimized system
bool testDGaO2021::findLensesForFirstOptimizedSystem()
{
	if (mOptimizedOpticalSystemEle_E0.getPosAndElement().size() < 1)
	{
		E0_loadOptimizedSystem();
	}

	// replace lenses
	LensReplace lensReplace;
	lensReplace.setRefIndexSurroundMat(1.0);
	lensReplace.replaceSuperFuction(mOptimizedOpticalSystemEle_E0);


	lensReplace.load_ALL_LensCatalogs();
	unsigned int numberBestFitLenses = 5;
	std::string locationSaveDataBestLenses = mLocation_E0 + "/findBestLenses";

	// zero lens
	unsigned int lensNumber_0 = 0;

	std::string nameBestLenses_0 = "bestLensesLens_0";
	std::vector<OptSysEle_Merit_LensType> bestLens_0_vec = lensReplace.checkLensCatalogsForBestFitLenses_many(/*lens number*/lensNumber_0, /*parameter lens*/ lensReplace.getParameterLenses()[lensNumber_0],/*number best fit lenses*/ numberBestFitLenses);
	inportExportData::clearDataInTXT(locationSaveDataBestLenses, nameBestLenses_0);
	for (unsigned int i = 0; i < numberBestFitLenses; ++i)
	{
		bestLens_0_vec[i].exportDataToTXT(locationSaveDataBestLenses, nameBestLenses_0);
	}

	// first lens
	unsigned int lensNumber_1 = 1;
	std::string nameBestLenses_1 = "bestLensesLens_1";
	std::vector<OptSysEle_Merit_LensType> bestLens_1_vec = lensReplace.checkLensCatalogsForBestFitLenses_many(/*lens number*/lensNumber_1, /*parameter lens*/ lensReplace.getParameterLenses()[lensNumber_1],/*number best fit lenses*/ numberBestFitLenses);
	inportExportData::clearDataInTXT(locationSaveDataBestLenses, nameBestLenses_1);
	for (unsigned int i = 0; i < numberBestFitLenses; ++i)
	{
		bestLens_1_vec[i].exportDataToTXT(locationSaveDataBestLenses, nameBestLenses_1);
	}

	// second lens
	unsigned int lensNumber_2 = 2;
	std::string nameBestLenses_2 = "bestLensesLens_2";
	std::vector<OptSysEle_Merit_LensType> bestLens_2_vec = lensReplace.checkLensCatalogsForBestFitLenses_many(/*lens number*/lensNumber_2, /*parameter lens*/ lensReplace.getParameterLenses()[lensNumber_2],/*number best fit lenses*/ numberBestFitLenses + 1);
	inportExportData::clearDataInTXT(locationSaveDataBestLenses, nameBestLenses_2);
	for (unsigned int i = 0; i < bestLens_2_vec.size(); ++i)
	{
		bestLens_2_vec[i].exportDataToTXT(locationSaveDataBestLenses, nameBestLenses_2);
	}

	// thrid lens
	unsigned int lensNumber_3 = 3;
	std::string nameBestLenses_3 = "bestLensesLens_3";
	std::vector<OptSysEle_Merit_LensType> bestLens_3_vec = lensReplace.checkLensCatalogsForBestFitLenses_many(/*lens number*/lensNumber_3, /*parameter lens*/ lensReplace.getParameterLenses()[lensNumber_3],/*number best fit lenses*/ numberBestFitLenses);
	inportExportData::clearDataInTXT(locationSaveDataBestLenses, nameBestLenses_3);
	for (unsigned int i = 0; i < numberBestFitLenses; ++i)
	{
		bestLens_3_vec[i].exportDataToTXT(locationSaveDataBestLenses, nameBestLenses_3);
	}

	return true;
}


bool testDGaO2021::E0_replace_LeftToRight_andImaSim()
{
	std::vector<bool> workTheSystem;

	if (mOptimizedOpticalSystemEle_E0.getPosAndElement().size() < 1)
	{
		bool checkLoadOptimizedSystem = E0_loadOptimizedSystem();
		workTheSystem.push_back(checkLoadOptimizedSystem);
	}

	optimizeMethode optMethode = optimizeMethode::GeneticAndDLS_12;

	LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
	testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(mTargetCarPoints);
	testLensReplaceAndOptiSuperFct.setDefaulParaDLS(mDefaulParaDLS);
	testLensReplaceAndOptiSuperFct.setDefaultParaGenetic(mDefaultParameterGenetic);
	testLensReplaceAndOptiSuperFct.setPopulation(mPopulation);
	testLensReplaceAndOptiSuperFct.setLoad_ALL_LensCatalogs();
	replaceSequence repSeq = replaceSequence::leftToRight;


	testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(mOptimizedOpticalSystemEle_E0, mField_vec, mWavelength_FdV_vec, mRings, mArms, optMethode, /*number best fit lenses*/ mNumberBestFitLenses, false, repSeq, mLight587);
	OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();

	//// debug
	//oftenUse::print(optSysEle_lensRepSuperFct, 550.0);
	//testLensReplaceAndOptiSuperFct.printBestParameterCatalogForReplace();

	// save parameter

	std::string nameOptSysReplaced_RightToLeft = "E0_optSysDGaO_Replaced_RightToLeft";
	std::string bestCatalogLensesForReplace = "E0_bestCatalogLensesForReplace_DGaO2021_RightToLeft";
	std::string replaceSequence = "E0_replaceSequence_DGaO2021_RightToLeft";
	std::string replaceRMSvalue = "E0_replacedRMSvalues_RightToLeft";
	std::vector<std::string> nameDoubel_vec = { "field0", "field707", "field1000" };

	std::vector<unsigned int> replacedSequenceDGaO2021_vec = testLensReplaceAndOptiSuperFct.getReplacedSequence();

	inportExportData::saveOpticalSystemAsTXT(optSysEle_lensRepSuperFct, 550.0, mLocation_E0_RightToLeft, nameOptSysReplaced_RightToLeft);
	inportExportData::exportIntVecInTXT(mLocation_E0_RightToLeft, replaceSequence, replaceSequence, replacedSequenceDGaO2021_vec, true);
	testLensReplaceAndOptiSuperFct.exportBestParameterCatalogForReplaceTXT(mLocation_E0_RightToLeft, bestCatalogLensesForReplace);

	// export rms values
	std::vector<real> rmsVecReplaceSys = oftenUse::getRMSoptSysHLT(optSysEle_lensRepSuperFct, mField_vec, mWavelength_FdV_vec, mRings, mArms);
	inportExportData::saveVecDoubleInTXT(mLocation_E0_RightToLeft, replaceRMSvalue, nameDoubel_vec, rmsVecReplaceSys, true);



	// *** image simulation *** 
	loadParaImaSim parameterImaSim{};
	parameterImaSim.setWavelengthBlue(486.1327);
	parameterImaSim.setWavelengthGreen(587.5818);
	parameterImaSim.setWavelengthRed(656.2725);
	parameterImaSim.setRayDensity(30);

	//light
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	light.setJonesVector({ 1.0,1.0,1.0,1.0 });
	light.setTypeLight(typeLight::typeLightRay);

	parameterImaSim.setLight(light);
	parameterImaSim.setSizeMatrixToSaveOPD(64);
	parameterImaSim.setInfOrObj(objectPoint_inf_obj::obj);
	parameterImaSim.setRowColResizeOPD(128);
	parameterImaSim.setSampling_x(11);
	parameterImaSim.setSampling_y(11);
	parameterImaSim.setSemiHeightObj(1000.0);
	parameterImaSim.setSemiWeidthObj(1000.0);
	parameterImaSim.setPosition_Z_Object(0.0);
	parameterImaSim.setUpSamplePSF(true);
	parameterImaSim.setResizeOPD_linear(true);
	parameterImaSim.setPaddingFactorPSF(1);
	parameterImaSim.setCalcDistortion(true);
	parameterImaSim.setSamplingDistortionHeight(450);
	parameterImaSim.setSamplingDistortionWidth(450);

	// load object
	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_900x900.png", CV_LOAD_IMAGE_COLOR);

	ImageSimulationFunctions imaSim;
	imaSim.imageSimulationSuperFct(/*optical System Element*/ optSysEle_lensRepSuperFct, /*object*/ elefantObj, /*parameter*/ parameterImaSim);

	cv::Mat simulatedIma = imaSim.getSimulatedImage_initialSize();
	// just for debugging
	//Images::showImage_inputReal_normTheImage("simulatedIma_E0_ReplaceLeftToRight", simulatedIma);
	// save the simulate images
	Images::saveImage_normalized(mLocation_E0_RightToLeft, "simulatedIma_E0_Replaced_rightToLeft", "png", simulatedIma);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}


// replace all sequences and image simulation
bool testDGaO2021::E0_replace_AllSequences_andImaSim()
{
	std::vector<bool> workTheSystem;

	if (mOptimizedOpticalSystemEle_E0.getPosAndElement().size() < 1)
	{
		bool checkLoadOptimizedSystem = E0_loadOptimizedSystem();
		workTheSystem.push_back(checkLoadOptimizedSystem);
	}

	optimizeMethode optMethode = optimizeMethode::GeneticAndDLS_12;

	LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
	testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(mTargetCarPoints);
	testLensReplaceAndOptiSuperFct.setDefaulParaDLS(mDefaulParaDLS);
	testLensReplaceAndOptiSuperFct.setDefaultParaGenetic(mDefaultParameterGenetic);
	testLensReplaceAndOptiSuperFct.setPopulation(mPopulation);
	testLensReplaceAndOptiSuperFct.setLoad_ALL_LensCatalogs();
	replaceSequence repSeq = replaceSequence::allPossibleSequences;


	testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(mOptimizedOpticalSystemEle_E0, mField_vec, mWavelength_FdV_vec, mRings, mArms, optMethode, /*number best fit lenses*/ mNumberBestFitLenses, false, repSeq, mLight587);
	OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();

	//// debug
	//oftenUse::print(optSysEle_lensRepSuperFct, 550.0);
	//testLensReplaceAndOptiSuperFct.printBestParameterCatalogForReplace();

	// save parameter

	std::string nameOptSysReplaced_AllPosSequences = "E0_optSysDGaO_Replaced_AllPosSequences";
	std::string bestCatalogLensesForReplace = "E0_bestCatalogLensesForReplace_DGaO2021_AllPosSequences";
	std::string replaceSequence = "E0_replaceSequence_DGaO2021_AllPosSequences";
	std::string replaceRMSvalue = "E0_replacedRMSvalues_AllPosSequences";
	std::vector<std::string> nameDoubel_vec = { "field0", "field707", "field1000" };

	std::vector<unsigned int> replacedSequenceDGaO2021_vec = testLensReplaceAndOptiSuperFct.getReplacedSequence();

	inportExportData::saveOpticalSystemAsTXT(optSysEle_lensRepSuperFct, 550.0, mLocation_E0_allPosSequences, nameOptSysReplaced_AllPosSequences);
	inportExportData::exportIntVecInTXT(mLocation_E0_allPosSequences, replaceSequence, replaceSequence, replacedSequenceDGaO2021_vec, true);
	testLensReplaceAndOptiSuperFct.exportBestParameterCatalogForReplaceTXT(mLocation_E0_allPosSequences, bestCatalogLensesForReplace);

	// export rms values
	std::vector<real> rmsVecReplaceSys = oftenUse::getRMSoptSysHLT(optSysEle_lensRepSuperFct, mField_vec, mWavelength_FdV_vec, mRings, mArms);
	inportExportData::saveVecDoubleInTXT(mLocation_E0_allPosSequences, replaceRMSvalue, nameDoubel_vec, rmsVecReplaceSys, true);



	// *** image simulation *** 
	loadParaImaSim parameterImaSim{};
	parameterImaSim.setWavelengthBlue(486.1327);
	parameterImaSim.setWavelengthGreen(587.5818);
	parameterImaSim.setWavelengthRed(656.2725);
	parameterImaSim.setRayDensity(30);

	//light
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	light.setJonesVector({ 1.0,1.0,1.0,1.0 });
	light.setTypeLight(typeLight::typeLightRay);

	parameterImaSim.setLight(light);
	parameterImaSim.setSizeMatrixToSaveOPD(64);
	parameterImaSim.setInfOrObj(objectPoint_inf_obj::obj);
	parameterImaSim.setRowColResizeOPD(128);
	parameterImaSim.setSampling_x(11);
	parameterImaSim.setSampling_y(11);
	parameterImaSim.setSemiHeightObj(1000.0);
	parameterImaSim.setSemiWeidthObj(1000.0);
	parameterImaSim.setPosition_Z_Object(0.0);
	parameterImaSim.setUpSamplePSF(true);
	parameterImaSim.setResizeOPD_linear(true);
	parameterImaSim.setPaddingFactorPSF(1);
	parameterImaSim.setCalcDistortion(true);
	parameterImaSim.setSamplingDistortionHeight(450);
	parameterImaSim.setSamplingDistortionWidth(450);

	// load object
	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_900x900.png", CV_LOAD_IMAGE_COLOR);

	ImageSimulationFunctions imaSim;
	imaSim.imageSimulationSuperFct(/*optical System Element*/ optSysEle_lensRepSuperFct, /*object*/ elefantObj, /*parameter*/ parameterImaSim);

	cv::Mat simulatedIma = imaSim.getSimulatedImage_initialSize();
	// just for debugging
	//Images::showImage_inputReal_normTheImage("simulatedIma_E0_ReplaceLeftToRight", simulatedIma);
	// save the simulate images
	Images::saveImage_normalized(mLocation_E0_allPosSequences, "simulatedIma_E0_Replaced_allSequences", "png", simulatedIma);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// check Lens replace and optimize leftToRight
bool testDGaO2021::E0_checkLensReplaceAndOptimizeLeftToRight()
{
	std::vector<bool> workTheSystem;

	if (mOptimizedOpticalSystemEle_E0.getPosAndElement().size() < mStartOpticalSystem_E0.getPosAndElement().size())
	{
		bool checkLoadOptimizedSystem = E0_loadOptimizedSystem();
		workTheSystem.push_back(checkLoadOptimizedSystem);
	}

	optimizeMethode optMethode = optimizeMethode::GeneticAndDLS_12;

	LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
	testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(mTargetCarPoints);
	testLensReplaceAndOptiSuperFct.setDefaulParaDLS(mDefaulParaDLS);
	testLensReplaceAndOptiSuperFct.setDefaultParaGenetic(mDefaultParameterGenetic);
	testLensReplaceAndOptiSuperFct.setPopulation(mPopulation);
	testLensReplaceAndOptiSuperFct.setLoad_ALL_LensCatalogs();
	replaceSequence repSeq = replaceSequence::leftToRight;


	testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(mOptimizedOpticalSystemEle_E0, mField_vec, mWavelength_FdV_vec, mRings, mArms, optMethode, /*number best fit lenses*/ mNumberBestFitLenses, false, repSeq, mLight587);
	OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();

	// debug
	oftenUse::print(optSysEle_lensRepSuperFct, 550.0);
	testLensReplaceAndOptiSuperFct.printBestParameterCatalogForReplace();

	// save parameter

	std::string nameOptSysReplaced = "E0_optSysDGaO_Replaced";
	std::string bestCatalogLensesForReplace = "E0_bestCatalogLensesForReplace_DGaO2021";
	std::string replaceSequence = "E0_replaceSequence_DGaO2021";
	std::string replaceRMSvalue = "E0_replacedRMSvalues";
	std::vector<std::string> nameDoubel_vec = { "field0", "field707", "field1000" };

	std::vector<unsigned int> replacedSequenceDGaO2021_vec = testLensReplaceAndOptiSuperFct.getReplacedSequence();


	inportExportData::saveOpticalSystemAsTXT(optSysEle_lensRepSuperFct, 550.0, mLocation_E0_LeftToRight, nameOptSysReplaced);
	inportExportData::exportIntVecInTXT(mLocation_E0_LeftToRight, replaceSequence, replaceSequence, replacedSequenceDGaO2021_vec, true);
	testLensReplaceAndOptiSuperFct.exportBestParameterCatalogForReplaceTXT(mLocation_E0_LeftToRight, bestCatalogLensesForReplace);

	// export rms values
	std::vector<real> rmsVecReplaceSys = oftenUse::getRMSoptSysHLT(optSysEle_lensRepSuperFct, mField_vec, mWavelength_FdV_vec, mRings, mArms);
	inportExportData::saveVecDoubleInTXT(mLocation_E0_LeftToRight, replaceRMSvalue, nameDoubel_vec, rmsVecReplaceSys, true);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;

}

bool testDGaO2021::checkE1_DGaO2021()
{
	std::vector<bool> workTheSystem;

	//bool checkStartSystem_E1 = E1_checkStartSystem();
	//workTheSystem.push_back(checkStartSystem_E1);
	//
	//// check first optimisation
	//bool checkOptimizationStartSystem = E1_checkOptimizeStartSystem_DoOptimization();
	//workTheSystem.push_back(checkOptimizationStartSystem);
	//
	//bool checkLensRepLeftRight_E1 = E1_checkLensReplaceAndOptimizeLeftToRight();
	//workTheSystem.push_back(checkLensRepLeftRight_E1);

	//// check replace system
	//bool checkReplacedSystem_E1 = E1_loadReplacedSystem_leftToRight();
	//workTheSystem.push_back(checkReplacedSystem_E1);
	
	//bool checkImprovIma = E1_improveImageQuality_ReplacedLeftToRight();
	//workTheSystem.push_back(checkImprovIma);

	//// do image simulation with E1
	//bool checkImaSim_E1 = E1_checkImageSimulationReplacedSystem();
	//workTheSystem.push_back(checkImaSim_E1);

	//bool checkE1_LoadRepalceSystem_allPosSequences = E1_LoadRepalceSystem_allPosSequences();
	//workTheSystem.push_back(checkE1_LoadRepalceSystem_allPosSequences);

	//bool checkE1_imaSimLensReplacedAllSequences = E1_imaSimLensReplacedAllSequences();
	//workTheSystem.push_back(checkE1_imaSimLensReplacedAllSequences);

	bool checkE1_improveImageQuality_AllPossibleSequences = E1_improveImageQuality_AllPossibleSequences();
	workTheSystem.push_back(checkE1_improveImageQuality_AllPossibleSequences);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}


bool testDGaO2021::E1_checkStartSystem()
{
	std::vector<bool> workTheSystem;

	real semiHeight = 15.0;
	real firstThickness = 20000.0;

	ApertureStopElement S0(/* semi height*/5.0, /*point*/{ 0.0,0.0, firstThickness + 10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 20.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 180.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 30.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 900.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 40.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S6(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 70.0 }, /*direction*/{ 0.0,0.0,   1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S7(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF10_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S8(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 90.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getNSF10_S1(), /*refractive index B*/mGlasses.getAir());


	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0, firstThickness + 100.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	// radii
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	// thicknesses
	S3.setParameterPointZ(/*min value*/ 10.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 10.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/ 10.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	mStartOpticalSystem_E1.fillPosAndElementAndInteraction(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(mStartOpticalSystem_E1, 550.0);
	// save the start system

	inportExportData::saveOpticalSystemAsTXT(mStartOpticalSystem_E1, 550.0, mLocation_E1, "E1_start_DGaO2021");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(mStartOpticalSystem_E1);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 33.176, 34.378, 35.550 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(mStartOpticalSystem_E1, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);


	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::E1_checkOptimizeStartSystem_DoOptimization()
{
	std::vector<bool> workTheSystem;

	OpticalSystemElement initalOpticalSystemEle = mStartOpticalSystem_E1.getDeepCopyOptSysEle();


	// optimize optical system
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ initalOpticalSystemEle,/*fields*/ mField_vec, /*wavelength*/ mWavelength_FdV_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default Genetic*/mDefaultParameterGenetic, /*default DLS*/ mDefaulParaDLS);
	mOptimizedOpticalSystemEle_E1 = GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();

	// export the first optimized system
	inportExportData::saveOpticalSystemAsTXT(mOptimizedOpticalSystemEle_E1, 550.0, mLocation_E1, "E1_optimized_first_DGaO2021");


	// check optimized system
	std::vector<real> rmsVecInitalOptSys = oftenUse::getRMSoptSysHLT(mStartOpticalSystem_E1, mField_vec, mWavelength_FdV_vec, mRings, mArms);
	std::vector<real> rmsVecGeneticDLS_12 = oftenUse::getRMSoptSysHLT(mOptimizedOpticalSystemEle_E1, mField_vec, mWavelength_FdV_vec, mRings, mArms);

	real sumRMS_initalOptSys = oftenUse::sum(rmsVecInitalOptSys);
	real sumRMS_optimizedOptSys = oftenUse::sum(rmsVecGeneticDLS_12);

	bool checkOptimization = sumRMS_initalOptSys > sumRMS_optimizedOptSys;
	workTheSystem.push_back(checkOptimization);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::E1_loadFirstOptimizedSystem()
{
	std::vector<bool> workTheSystem;

	real semiHeight = 15.0;
	real firstThickness = 20000.0;

	ApertureStopElement S0(/* semi height*/5.0, /*point*/{ 0.0,0.0, firstThickness + 10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 139.90859, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 20.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 45.47816, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 30.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 141.23440, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 40.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S4(/*radius*/ 40.3237, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 54.08006 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 330.57221, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 64.08006 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S6(/*radius*/ 204.72701, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 76.41347 }, /*direction*/{ 0.0,0.0,   1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S7(/*radius*/ 501.22634, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 86.41347 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNSF10_S1());
	SphericalElement S8(/*radius*/ 80.55502, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 96.41347 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getNSF10_S1(), /*refractive index B*/mGlasses.getAir());


	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0, firstThickness + 117.023 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	// radii
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	// thicknesses
	S3.setParameterPointZ(/*min value*/ 10.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 10.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/ 10.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	mOptimizedOpticalSystemEle_E1.fillPosAndElementAndInteraction(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(mOptimizedOpticalSystemEle_E1, 550.0);
	// save the start system

	inportExportData::saveOpticalSystemAsTXT(mOptimizedOpticalSystemEle_E1, 550.0, mLocation_E1, "E1_start_DGaO2021");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(mOptimizedOpticalSystemEle_E1);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 6.084, 6.180, 10.557 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(mOptimizedOpticalSystemEle_E1, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);


	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::E1_checkLensReplaceAndOptimizeLeftToRight()
{
	std::vector<bool> workTheSystem;

	if (mOptimizedOpticalSystemEle_E1.getPosAndElement().size() < mStartOpticalSystem_E1.getPosAndElement().size())
	{
		//bool checkLoadOptimizedSystem = E1_loadOptimizedSystem();
		//workTheSystem.push_back(checkLoadOptimizedSystem);
	}

	optimizeMethode optMethode = optimizeMethode::GeneticAndDLS_12;

	LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
	testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(mTargetCarPoints);
	testLensReplaceAndOptiSuperFct.setDefaulParaDLS(mDefaulParaDLS);
	testLensReplaceAndOptiSuperFct.setDefaultParaGenetic(mDefaultParameterGenetic);
	testLensReplaceAndOptiSuperFct.setPopulation(mPopulation);
	testLensReplaceAndOptiSuperFct.setLoad_ALL_LensCatalogs();
	replaceSequence repSeq = replaceSequence::leftToRight;


	testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(mOptimizedOpticalSystemEle_E1, mField_vec, mWavelength_FdV_vec, mRings, mArms, optMethode, /*number best fit lenses*/ mNumberBestFitLenses, false, repSeq, mLight587);
	OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();

	// debug
	oftenUse::print(optSysEle_lensRepSuperFct, 550.0);
	testLensReplaceAndOptiSuperFct.printBestParameterCatalogForReplace();

	// save parameter

	std::string nameOptSysReplaced = "E1_optSysDGaO_Replaced";
	std::string bestCatalogLensesForReplace = "E1_bestCatalogLensesForReplace_DGaO2021";
	std::string replaceSequence = "E1_replaceSequence_DGaO2021";
	std::string replaceRMSvalue = "E1_replacedRMSvalues";
	std::vector<std::string> nameDoubel_vec = { "field0", "field707", "field1000" };

	std::vector<unsigned int> replacedSequenceDGaO2021_vec = testLensReplaceAndOptiSuperFct.getReplacedSequence();


	inportExportData::saveOpticalSystemAsTXT(optSysEle_lensRepSuperFct, 550.0, mLocation_E1_LeftToRight, nameOptSysReplaced);
	inportExportData::exportIntVecInTXT(mLocation_E1_LeftToRight, replaceSequence, replaceSequence, replacedSequenceDGaO2021_vec, true);
	testLensReplaceAndOptiSuperFct.exportBestParameterCatalogForReplaceTXT(mLocation_E1_LeftToRight, bestCatalogLensesForReplace);

	// export rms values
	std::vector<real> rmsVecReplaceSys = oftenUse::getRMSoptSysHLT(optSysEle_lensRepSuperFct, mField_vec, mWavelength_FdV_vec, mRings, mArms);
	inportExportData::saveVecDoubleInTXT(mLocation_E1_LeftToRight, replaceRMSvalue, nameDoubel_vec, rmsVecReplaceSys, true);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::E1_loadReplacedSystem_leftToRight()
{
	std::vector<bool> workTheSystem;

	real firstThickness = 20000.0;
	real semiHeight = 12.5;

	ApertureStopElement S0(/* semi height*/5.0, /*point*/{ 0.0,0.0, firstThickness + 10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 253.1, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 20.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S2(/*radius*/ 87.26, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 24.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 124.12, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 32.5 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S4(/*radius*/ 109.16, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 61.23659 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 79.38, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 67.23659 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 226.03, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 70.23659 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S7(/*radius*/ 124.51, /*semi height*/ 20.0, /*point*/{ 0.0,0.0, firstThickness + 100.2366 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S8(/*radius*/ 31.54, /*semi height*/ 20.0, /*point*/{ 0.0,0.0, firstThickness + 103.2366 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNSK11_S1());
	SphericalElement S9(/*radius*/ 37.33, /*semi height*/ 20.0, /*point*/{ 0.0,0.0, firstThickness + 117.6966 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSK11_S1());

	PlanElement S10(/*semi height*/ 99.0, /*point*/{ 0.0,0.0, firstThickness + 140.5442 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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



	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr};
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	mReplacedOpticalSystemEle_E1_leftToRight.fillPosAndElementAndInteraction(opticalSystem_ptr, interactions_ptr);

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(mReplacedOpticalSystemEle_E1_leftToRight);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_ReplacedSystem{ 9.12987, 11.9046, 22.4767 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(mReplacedOpticalSystemEle_E1_leftToRight, mField_vec, mWavelength_FdV_vec, rms_ReplacedSystem, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	inportExportData::saveOpticalSystemAsTXT(mReplacedOpticalSystemEle_E1_leftToRight, 550.0, mLocation_E1_LeftToRight, "E1_ReplacedSystem_LeftToRigth_loaded");

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::E1_checkImageSimulationReplacedSystem_leftToRight()
{
	if (mReplacedOpticalSystemEle_E1_leftToRight.getPosAndElement().size() < 1)
	{
		E1_loadReplacedSystem_leftToRight();
	}

	loadParaImaSim parameterImaSim{};
	parameterImaSim.setWavelengthBlue(486.1327);
	parameterImaSim.setWavelengthGreen(587.5818);
	parameterImaSim.setWavelengthRed(656.2725);
	parameterImaSim.setRayDensity(30);

	//light
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	light.setJonesVector({ 1.0,1.0,1.0,1.0 });
	light.setTypeLight(typeLight::typeLightRay);

	parameterImaSim.setLight(light);
	parameterImaSim.setSizeMatrixToSaveOPD(64);
	parameterImaSim.setInfOrObj(objectPoint_inf_obj::obj);
	parameterImaSim.setRowColResizeOPD(128);
	parameterImaSim.setSampling_x(11);
	parameterImaSim.setSampling_y(11);
	parameterImaSim.setSemiHeightObj(1000.0);
	parameterImaSim.setSemiWeidthObj(1000.0);
	parameterImaSim.setPosition_Z_Object(0.0);
	parameterImaSim.setUpSamplePSF(true);
	parameterImaSim.setResizeOPD_linear(true);
	parameterImaSim.setPaddingFactorPSF(1);
	parameterImaSim.setCalcDistortion(true);
	parameterImaSim.setSamplingDistortionHeight(450);
	parameterImaSim.setSamplingDistortionWidth(450);

	// load object
	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_900x900.png", CV_LOAD_IMAGE_COLOR);

	ImageSimulationFunctions imaSim;
	imaSim.imageSimulationSuperFct(/*optical System Element*/ mReplacedOpticalSystemEle_E1_leftToRight, /*object*/ elefantObj, /*parameter*/ parameterImaSim);

	cv::Mat simulatedIma = imaSim.getSimulatedImage_initialSize();
	// just for debugging
	Images::showImage_inputReal_normTheImage("simulatedIma_E1_ReplaceLeftToRight", simulatedIma);
	// save the simulate images
	Images::saveImage_normalized(mLocation_E1_LeftToRight, "simulatedIma_E1_ReplaceLeftToRight", "png", simulatedIma);

	return true;
}

bool testDGaO2021::E1_improveImageQuality_ReplacedLeftToRight()
{
	bool debugVersion = true;
	

	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_elefant = Images::loadAnImage_Color(loactionObject, "elefant_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMat_elefant = Images::loadAnImage_Color(mLocation_E1_LeftToRight, "simulatedIma_E1_ReplaceLeftToRight");

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


	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant, methodeImaProc);


	cv::Mat filteredIma_final = imaProcessingSuperFunction.getAllFilteredImages_UM_DE_WD()[2];
	Images::saveImage_inputUN8C3_normByROI_percent(mLocation_E1_LeftToRight, "E1_filteredIma_LeftToRight", "png", filteredIma_final, paraWD_blue.getCompareInPercent());

	return true;

}

bool testDGaO2021::E1_LoadRepalceSystem_allPosSequences()
{
	std::vector<bool> workTheSystem;

	real firstThickness = 20000.0;
	real semiHeight = 12.5;

	ApertureStopElement S0(/* semi height*/5.0, /*point*/{ 0.0,0.0, firstThickness + 10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 61.36, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 20.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 44.30, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 28.25 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/ mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 128.90, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 31.05 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S4(/*radius*/ 50.85, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 61.05 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());
	SphericalElement S5(/*radius*/ 40.06, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 68.05 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF56_S1(), /*refractive index B*/mGlasses.getNSSK8_S1());
	SphericalElement S6(/*radius*/ 148.78, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 71.05 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());

	SphericalElement S7(/*radius*/ 92.3, /*semi height*/ 20.0, /*point*/{ 0.0,0.0, firstThickness + 85.61235 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S8(/*radius*/ 68.87, /*semi height*/ 20.0, /*point*/{ 0.0,0.0, firstThickness + 88.11235 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S9(/*radius*/ 204.15, /*semi height*/ 20.0, /*point*/{ 0.0,0.0, firstThickness + 92.17235 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());

	PlanElement S10(/*semi height*/ 99.0, /*point*/{ 0.0,0.0, firstThickness + 104.6373 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	mReplacedOpticalSystemEle_E1_allSequences.fillPosAndElementAndInteraction(opticalSystem_ptr, interactions_ptr);

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(mReplacedOpticalSystemEle_E1_allSequences);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_ReplacedSystem{ 2.24408, 4.91718, 7.19163 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(mReplacedOpticalSystemEle_E1_allSequences, mField_vec, mWavelength_FdV_vec, rms_ReplacedSystem, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	inportExportData::saveOpticalSystemAsTXT(mReplacedOpticalSystemEle_E1_allSequences, 550.0, mLocation_E1_LeftToRight, "E1_ReplacedSystem_LeftToRigth_loaded");

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::E1_checkLensReplaceAndOptimizeAllPossibleSequencesAndImaSim()
{
	std::vector<bool> workTheSystem;

	if (mOptimizedOpticalSystemEle_E1.getPosAndElement().size() < 1)
	{
		bool checkLoadOptimizedSystem = E1_loadFirstOptimizedSystem();
		workTheSystem.push_back(checkLoadOptimizedSystem);
	}

	optimizeMethode optMethode = optimizeMethode::GeneticAndDLS_12;

	LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
	testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(mTargetCarPoints);
	testLensReplaceAndOptiSuperFct.setDefaulParaDLS(mDefaulParaDLS);
	testLensReplaceAndOptiSuperFct.setDefaultParaGenetic(mDefaultParameterGenetic);
	testLensReplaceAndOptiSuperFct.setPopulation(mPopulation);
	testLensReplaceAndOptiSuperFct.setLoad_ALL_LensCatalogs();
	replaceSequence repSeq = replaceSequence::allPossibleSequences;


	testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(mOptimizedOpticalSystemEle_E1, mField_vec, mWavelength_FdV_vec, mRings, mArms, optMethode, /*number best fit lenses*/ mNumberBestFitLenses, false, repSeq, mLight587);
	OpticalSystemElement mReplacedOpticalSystemEle_E1_allSequences = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();

	// debug
	oftenUse::print(mReplacedOpticalSystemEle_E1_allSequences, 550.0);
	testLensReplaceAndOptiSuperFct.printBestParameterCatalogForReplace();

	// save parameter

	std::string nameOptSysReplaced_AllSequences = "E1_optSysDGaO_Replaced_AllSequences";
	std::string bestCatalogLensesForReplace_AllSequences = "E1_bestCatalogLensesForReplace_DGaO2021_AllSequences";
	std::string replaceSequence = "E1_replaceSequence_DGaO2021_AllSequences";
	std::string replaceRMSvalue = "E1_replacedRMSvalues_AllSequences";
	std::vector<std::string> nameDoubel_vec = { "field0", "field707", "field1000" };

	std::vector<unsigned int> replacedSequenceDGaO2021_vec = testLensReplaceAndOptiSuperFct.getReplacedSequence();


	inportExportData::saveOpticalSystemAsTXT(mReplacedOpticalSystemEle_E1_allSequences, 550.0, mLocation_E1_allSequences, nameOptSysReplaced_AllSequences);
	inportExportData::exportIntVecInTXT(mLocation_E1_allSequences, replaceSequence, replaceSequence, replacedSequenceDGaO2021_vec, true);
	testLensReplaceAndOptiSuperFct.exportBestParameterCatalogForReplaceTXT(mLocation_E1_allSequences, bestCatalogLensesForReplace_AllSequences);

	// export rms values
	std::vector<real> rmsVecReplaceSys = oftenUse::getRMSoptSysHLT(mReplacedOpticalSystemEle_E1_allSequences, mField_vec, mWavelength_FdV_vec, mRings, mArms);
	inportExportData::saveVecDoubleInTXT(mLocation_E1_allSequences, replaceRMSvalue, nameDoubel_vec, rmsVecReplaceSys, true);


	if (mReplacedOpticalSystemEle_E1_allSequences.getPosAndElement().size() < 1)
	{
		E1_LoadRepalceSystem_allPosSequences();
	}

	loadParaImaSim parameterImaSim{};
	parameterImaSim.setWavelengthBlue(486.1327);
	parameterImaSim.setWavelengthGreen(587.5818);
	parameterImaSim.setWavelengthRed(656.2725);
	parameterImaSim.setRayDensity(30);

	//light
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	light.setJonesVector({ 1.0,1.0,1.0,1.0 });
	light.setTypeLight(typeLight::typeLightRay);

	parameterImaSim.setLight(light);
	parameterImaSim.setSizeMatrixToSaveOPD(64);
	parameterImaSim.setInfOrObj(objectPoint_inf_obj::obj);
	parameterImaSim.setRowColResizeOPD(128);
	parameterImaSim.setSampling_x(11);
	parameterImaSim.setSampling_y(11);
	parameterImaSim.setSemiHeightObj(1000.0);
	parameterImaSim.setSemiWeidthObj(1000.0);
	parameterImaSim.setPosition_Z_Object(0.0);
	parameterImaSim.setUpSamplePSF(true);
	parameterImaSim.setResizeOPD_linear(true);
	parameterImaSim.setPaddingFactorPSF(1);
	parameterImaSim.setCalcDistortion(true);
	parameterImaSim.setSamplingDistortionHeight(450);
	parameterImaSim.setSamplingDistortionWidth(450);

	// load object
	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_900x900.png", CV_LOAD_IMAGE_COLOR);

	ImageSimulationFunctions imaSim;
	imaSim.imageSimulationSuperFct(/*optical System Element*/ mReplacedOpticalSystemEle_E1_allSequences, /*object*/ elefantObj, /*parameter*/ parameterImaSim);

	cv::Mat simulatedIma = imaSim.getSimulatedImage_initialSize();
	// just for debugging
	// Images::showImage_inputReal_normTheImage("simulatedIma_E1_ReplaceLeftToRight", simulatedIma);
	// save the simulate images
	Images::saveImage_normalized(mLocation_E1_allSequences, "simulatedIma_E1_allPosSequences", "png", simulatedIma);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::E1_imaSimLensReplacedAllSequences()
{
	if (mReplacedOpticalSystemEle_E1_allSequences.getPosAndElement().size() < 1)
	{
		E1_LoadRepalceSystem_allPosSequences();
	}

	loadParaImaSim parameterImaSim{};
	parameterImaSim.setWavelengthBlue(486.1327);
	parameterImaSim.setWavelengthGreen(587.5818);
	parameterImaSim.setWavelengthRed(656.2725);
	parameterImaSim.setRayDensity(30);

	//light
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	light.setJonesVector({ 1.0,1.0,1.0,1.0 });
	light.setTypeLight(typeLight::typeLightRay);

	parameterImaSim.setLight(light);
	parameterImaSim.setSizeMatrixToSaveOPD(64);
	parameterImaSim.setInfOrObj(objectPoint_inf_obj::obj);
	parameterImaSim.setRowColResizeOPD(128);
	parameterImaSim.setSampling_x(11);
	parameterImaSim.setSampling_y(11);
	parameterImaSim.setSemiHeightObj(1000.0);
	parameterImaSim.setSemiWeidthObj(1000.0);
	parameterImaSim.setPosition_Z_Object(0.0);
	parameterImaSim.setUpSamplePSF(true);
	parameterImaSim.setResizeOPD_linear(true);
	parameterImaSim.setPaddingFactorPSF(1);
	parameterImaSim.setCalcDistortion(false);
	parameterImaSim.setSamplingDistortionHeight(450);
	parameterImaSim.setSamplingDistortionWidth(450);

	// load object
	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_900x900.png", CV_LOAD_IMAGE_COLOR);

	ImageSimulationFunctions imaSim;
	imaSim.imageSimulationSuperFct(/*optical System Element*/ mReplacedOpticalSystemEle_E1_allSequences, /*object*/ elefantObj, /*parameter*/ parameterImaSim);

	cv::Mat simulatedIma = imaSim.getSimulatedImage_initialSize();
	// just for debugging
	// Images::showImage_inputReal_normTheImage("simulatedIma_E1_ReplaceLeftToRight", simulatedIma);
	// save the simulate images
	Images::saveImage_normalized(mLocation_E1_allSequences, "test_simulatedIma_E1_allSequences", "png", simulatedIma);

	//cv::Mat distortionCorIma = imaSim.getSimulatedImage_initialSize_distortionCorrected();
	//Images::saveImage_normalized(mLocation_E1_allSequences, "simulatedIma_E1_allSequences_distortionCorrected", "png", distortionCorIma);
	
	return true;
}

bool testDGaO2021::E1_improveImageQuality_AllPossibleSequences()
{
	bool debugVersion = false;


	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_elefant = Images::loadAnImage_Color(loactionObject, "elefant_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMat_elefant = Images::loadAnImage_Color(mLocation_E1_allSequences, "simulatedIma_E1_allSequences_distortionCorrected");

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


	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant, methodeImaProc);


	cv::Mat filteredIma_final = imaProcessingSuperFunction.getAllFilteredImages_UM_DE_WD()[2];
	Images::saveImage_inputUN8C3_normByROI_percent(mLocation_E1_allSequences, "E1_filteredIma_allSequnces", "png", filteredIma_final, paraWD_blue.getCompareInPercent());

	std::string locationFiltering = "../tests/testDGaO2021/E1/allSequences/filtering";

	// save best parameters WD
	saveBestParameterWD bestPara_blue = imaProcessingSuperFunction.getBestParaWD_blue();
	bestPara_blue.exportAsTXTfile(locationFiltering, "bestParaWD_blue", true);
	saveBestParameterWD bestPara_green = imaProcessingSuperFunction.getBestParaWD_green();
	bestPara_green.exportAsTXTfile(locationFiltering, "bestParaWD_green", true);
	saveBestParameterWD bestPara_red = imaProcessingSuperFunction.getBestParaWD_red();
	bestPara_red.exportAsTXTfile(locationFiltering, "bestParaWD_red", true);

	// save best para DE
	bestParameterStruct_detailEnhance bestParaDE = imaProcessingSuperFunction.getBestParaDetEnh();
	bestParaDE.exportAsTXTfile(locationFiltering, "bestParaDE", true);

	// save best para UM
	bestParameterStruct_unsharpMask bestParaUM_blue = imaProcessingSuperFunction.getBestParaUnsMas_blue();
	bestParaUM_blue.exportAsTXTfile(locationFiltering, "bestParaUM_blue", true);
	bestParameterStruct_unsharpMask bestParaUM_green = imaProcessingSuperFunction.getBestParaUnsMas_green();
	bestParaUM_green.exportAsTXTfile(locationFiltering, "bestParaUM_green", true);
	bestParameterStruct_unsharpMask bestParaUM_red = imaProcessingSuperFunction.getBestParaUnsMas_red();
	bestParaUM_red.exportAsTXTfile(locationFiltering, "bestParaUM_red", true);

	return true;
}


bool testDGaO2021::checkE2_DGaO2021()
{
	std::vector<bool> workTheSystem;

	//// check start system
	//bool checkE2_checkStartSystem = E2_checkStartSystem();
	//workTheSystem.push_back(checkE2_checkStartSystem);
	//
	//// check optimize start system#
	//bool checkE2_checkOptimizeStartSystem_DoOptimization = E2_checkOptimizeStartSystem_DoOptimization();
	//workTheSystem.push_back(checkE2_checkOptimizeStartSystem_DoOptimization);
	//
	//// check lens replace and optimize
	//bool checkE2_lensReplaceAllSequences = E2_lensReplaceAllSequences();
	//workTheSystem.push_back(checkE2_lensReplaceAllSequences);
	//
	//// check load first optimizes system
	//bool checkE2_loadFirstOptimizedSystem = E2_loadFirstOptimizedSystem();
	//workTheSystem.push_back(checkE2_loadFirstOptimizedSystem);

	//// load replace opt sys all sequences
	//bool checkE2_loadReplacedSystemAllSequences = E2_loadReplacedSystemAllSequences();
	//workTheSystem.push_back(checkE2_loadReplacedSystemAllSequences);
	//
	// image simulation with replaces system
	bool checkE2_imageSimulationWithReplacesSysAllSequences = E2_imageSimulationWithReplacesSysAllSequences();
	workTheSystem.push_back(checkE2_imageSimulationWithReplacesSysAllSequences);

	// improve image quality

	//// filtering sharp image
	//bool checkE2_improveImageQuality_AllPossibleSequences_refImage = E2_improveImageQuality_AllPossibleSequences_refImage_UM_DE_WD();
	//workTheSystem.push_back(checkE2_improveImageQuality_AllPossibleSequences_refImage);
	//
	//bool checkE2_improveImageQuality_AllPossibleSequences_refImage_UM = E2_improveImageQuality_AllPossibleSequences_refImage_UM();
	//workTheSystem.push_back(checkE2_improveImageQuality_AllPossibleSequences_refImage_UM);
	//
	//bool checkE2_improveImageQuality_AllPossibleSequences_refImage_DE = E2_improveImageQuality_AllPossibleSequences_refImage_DE();
	//workTheSystem.push_back(checkE2_improveImageQuality_AllPossibleSequences_refImage_DE);
	//
	//bool checkE2_improveImageQuality_AllPossibleSequences_refImage_WD = E2_improveImageQuality_AllPossibleSequences_refImage_WD();
	//workTheSystem.push_back(checkE2_improveImageQuality_AllPossibleSequences_refImage_WD);
	//
	//// filtering blur and noise
	//bool checkE2_improveImageQuality_AllPossibleSequences_BlurAndNois_UM_DE_WD = E2_improveImageQuality_AllPossibleSequences_BlurAndNois_UM_DE_WD();
	//workTheSystem.push_back(checkE2_improveImageQuality_AllPossibleSequences_BlurAndNois_UM_DE_WD);
	//
	//bool checkE2_improveImageQuality_AllPossibleSequences_BlurAndNois_UM = E2_improveImageQuality_AllPossibleSequences_BlurAndNois_UM();
	//workTheSystem.push_back(checkE2_improveImageQuality_AllPossibleSequences_BlurAndNois_UM);
	//
	//bool checkE2_improveImageQuality_AllPossibleSequences_BlurAndNois_DE = E2_improveImageQuality_AllPossibleSequences_BlurAndNois_DE();
	//workTheSystem.push_back(checkE2_improveImageQuality_AllPossibleSequences_BlurAndNois_DE);
	//
	//bool checkE2_improveImageQuality_AllPossibleSequences_BlurAndNois_WD  = E2_improveImageQuality_AllPossibleSequences_BlurAndNois_WD();
	//workTheSystem.push_back(checkE2_improveImageQuality_AllPossibleSequences_BlurAndNois_WD);


	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;

}


bool testDGaO2021::E2_checkStartSystem()
{
	std::vector<bool> workTheSystem;

	real semiHeight = 15.0;
	real firstThickness = 20000.0;

	ApertureStopElement S0(/* semi height*/5.0, /*point*/{ 0.0,0.0, firstThickness + 10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 20.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 60.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 30.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 50.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 40.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0, firstThickness + 75.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	// radii
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	// thicknesses
	S3.setParameterPointZ(/*min value*/ 10.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 10.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	mStartOpticalSystem_E2.fillPosAndElementAndInteraction(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(mStartOpticalSystem_E2, 550.0);
	// save the start system
	inportExportData::saveOpticalSystemAsTXT(mStartOpticalSystem_E2, 550.0, mLocation_E2, "E2_start_DGaO2021");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(mStartOpticalSystem_E2);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 166.010, 169.551, 173.084 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(mStartOpticalSystem_E2, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;

}

bool testDGaO2021::E2_checkOptimizeStartSystem_DoOptimization()
{
	std::vector<bool> workTheSystem;

	OpticalSystemElement initalOpticalSystemEle = mStartOpticalSystem_E2.getDeepCopyOptSysEle();


	// optimize optical system
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ initalOpticalSystemEle,/*fields*/ mField_vec, /*wavelength*/ mWavelength_FdV_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints, /*default Genetic*/mDefaultParameterGenetic, /*default DLS*/ mDefaulParaDLS);
	mOptimizedOpticalSystemEle_E2 = GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();

	// export the first optimized system
	inportExportData::saveOpticalSystemAsTXT(mOptimizedOpticalSystemEle_E2, 550.0, mLocation_E2, "E2_optimized_first_DGaO2021");


	// check optimized system
	std::vector<real> rmsVecInitalOptSys = oftenUse::getRMSoptSysHLT(mStartOpticalSystem_E2, mField_vec, mWavelength_FdV_vec, mRings, mArms);
	std::vector<real> rmsVecGeneticDLS_12 = oftenUse::getRMSoptSysHLT(mOptimizedOpticalSystemEle_E2, mField_vec, mWavelength_FdV_vec, mRings, mArms);

	real sumRMS_initalOptSys = oftenUse::sum(rmsVecInitalOptSys);
	real sumRMS_optimizedOptSys = oftenUse::sum(rmsVecGeneticDLS_12);

	bool checkOptimization = sumRMS_initalOptSys > sumRMS_optimizedOptSys;
	workTheSystem.push_back(checkOptimization);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::E2_loadFirstOptimizedSystem()
{
	std::vector<bool> workTheSystem;

	real semiHeight = 15.0;
	real firstThickness = 20000.0;

	ApertureStopElement S0(/* semi height*/5.0, /*point*/{ 0.0,0.0, firstThickness + 10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 65.69952, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 20.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 25.45804, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 30.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 59.45440, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 40.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S4(/*radius*/ 51.47415,/*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 68.39804 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 133.71265, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 78.39804 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0, firstThickness + 105.88 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	// radii
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	// thicknesses
	S3.setParameterPointZ(/*min value*/ 10.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 10.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	mOptimizedOpticalSystemEle_E2.fillPosAndElementAndInteraction(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(mOptimizedOpticalSystemEle_E2, 550.0);
	// save the start system
	inportExportData::saveOpticalSystemAsTXT(mOptimizedOpticalSystemEle_E2, 550.0, mLocation_E2, "E2_start_DGaO2021");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(mOptimizedOpticalSystemEle_E2);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 1.25, 5.568, 8.592 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(mOptimizedOpticalSystemEle_E2, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::E2_lensReplaceAllSequences()
{
	std::vector<bool> workTheSystem;

	if (mOptimizedOpticalSystemEle_E2.getPosAndElement().size() < 1)
	{
		bool checkLoadOptimizedSystem = E2_loadFirstOptimizedSystem();
		workTheSystem.push_back(checkLoadOptimizedSystem);
	}

	optimizeMethode optMethode = optimizeMethode::GeneticAndDLS_12;

	LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
	testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(mTargetCarPoints);
	testLensReplaceAndOptiSuperFct.setDefaulParaDLS(mDefaulParaDLS);
	testLensReplaceAndOptiSuperFct.setDefaultParaGenetic(mDefaultParameterGenetic);
	testLensReplaceAndOptiSuperFct.setPopulation(mPopulation);
	testLensReplaceAndOptiSuperFct.setLoad_ALL_LensCatalogs();
	replaceSequence repSeq = replaceSequence::allPossibleSequences;


	testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(mOptimizedOpticalSystemEle_E2, mField_vec, mWavelength_FdV_vec, mRings, mArms, optMethode, /*number best fit lenses*/ mNumberBestFitLenses, false, repSeq, mLight587);
	mReplacedOpticalSystemEle_E2_allSequences = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();

	// debug
	oftenUse::print(mReplacedOpticalSystemEle_E2_allSequences, 550.0);
	testLensReplaceAndOptiSuperFct.printBestParameterCatalogForReplace();

	// save parameter

	std::string nameOptSysReplaced_AllSequences = "E2_optSysDGaO_Replaced_AllSequences";
	std::string bestCatalogLensesForReplace_AllSequences = "E2_bestCatalogLensesForReplace_DGaO2021_AllSequences";
	std::string replaceSequence = "E2_replaceSequence_DGaO2021_AllSequences";
	std::string replaceRMSvalue = "E2_replacedRMSvalues_AllSequences";
	std::vector<std::string> nameDoubel_vec = { "field0", "field707", "field1000" };

	std::vector<unsigned int> replacedSequenceDGaO2021_vec = testLensReplaceAndOptiSuperFct.getReplacedSequence();


	inportExportData::saveOpticalSystemAsTXT(mReplacedOpticalSystemEle_E2_allSequences, 550.0, mLocation_E2_allSequences, nameOptSysReplaced_AllSequences);
	inportExportData::exportIntVecInTXT(mLocation_E2_allSequences, replaceSequence, replaceSequence, replacedSequenceDGaO2021_vec, true);
	testLensReplaceAndOptiSuperFct.exportBestParameterCatalogForReplaceTXT(mLocation_E2_allSequences, bestCatalogLensesForReplace_AllSequences);

	// export rms values
	std::vector<real> rmsVecReplaceSys = oftenUse::getRMSoptSysHLT(mReplacedOpticalSystemEle_E2_allSequences, mField_vec, mWavelength_FdV_vec, mRings, mArms);
	inportExportData::saveVecDoubleInTXT(mLocation_E2_allSequences, replaceRMSvalue, nameDoubel_vec, rmsVecReplaceSys, true);


	if (mReplacedOpticalSystemEle_E2_allSequences.getPosAndElement().size() < 1)
	{
		// do it
		//E2_LoadRepalceSystem_allPosSequences();
	}

	loadParaImaSim parameterImaSim{};
	parameterImaSim.setWavelengthBlue(486.1327);
	parameterImaSim.setWavelengthGreen(587.5818);
	parameterImaSim.setWavelengthRed(656.2725);
	parameterImaSim.setRayDensity(30);

	//light
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	light.setJonesVector({ 1.0,1.0,1.0,1.0 });
	light.setTypeLight(typeLight::typeLightRay);

	parameterImaSim.setLight(light);
	parameterImaSim.setSizeMatrixToSaveOPD(128);
	parameterImaSim.setInfOrObj(objectPoint_inf_obj::obj);
	parameterImaSim.setRowColResizeOPD(64);
	parameterImaSim.setSampling_x(11);
	parameterImaSim.setSampling_y(11);
	parameterImaSim.setSemiHeightObj(1000.0);
	parameterImaSim.setSemiWeidthObj(1000.0);
	parameterImaSim.setPosition_Z_Object(0.0);
	parameterImaSim.setUpSamplePSF(true);
	parameterImaSim.setResizeOPD_linear(true);
	parameterImaSim.setPaddingFactorPSF(1);
	parameterImaSim.setCalcDistortion(true);
	parameterImaSim.setSamplingDistortionHeight(450);
	parameterImaSim.setSamplingDistortionWidth(450);

	// load object
	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_900x900.png", CV_LOAD_IMAGE_COLOR);

	ImageSimulationFunctions imaSim;
	imaSim.imageSimulationSuperFct(/*optical System Element*/ mReplacedOpticalSystemEle_E2_allSequences, /*object*/ elefantObj, /*parameter*/ parameterImaSim);

	cv::Mat simulatedIma = imaSim.getSimulatedImage_initialSize();
	// just for debugging
	// Images::showImage_inputReal_normTheImage("simulatedIma_E2_ReplaceLeftToRight", simulatedIma);
	// save the simulate images
	Images::saveImage_normalized(mLocation_E2_allSequences, "simulatedIma_E2_allPosSequences", "png", simulatedIma);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::E2_loadReplacedSystemAllSequences()
{
	std::vector<bool> workTheSystem;

	real firstThickness = 20000.0;

	ApertureStopElement S0(/* semi height*/5.0, /*point*/{ 0.0,0.0, firstThickness + 10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 25.62, /*semi height*/ 15.0, /*point*/{ 0.0,0.0, firstThickness + 20.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S2(/*radius*/ 25.62, /*semi height*/15.0, /*point*/{ 0.0,0.0, firstThickness + 30.9 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF57_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S3(/*radius*/ 144.37, /*semi height*/15.0, /*point*/{ 0.0,0.0, firstThickness + 35.5 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());

	SphericalElement S4(/*radius*/ 17.75,/*semi height*/ 6.25, /*point*/{ 0.0,0.0, firstThickness + 57.97677 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S5(/*radius*/ 12.17, /*semi height*/ 6.25, /*point*/{ 0.0,0.0, firstThickness + 59.97677 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNSF10_S1());
	SphericalElement S6(/*radius*/ 109.75, /*semi height*/ 6.25, /*point*/{ 0.0,0.0, firstThickness + 62.52677 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF10_S1(), /*refractive index B*/mGlasses.getAir());

	PlanElement S7(/*semi height*/ 99.0, /*point*/{ 0.0,0.0, firstThickness + 72.6955 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());


	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	mReplacedOpticalSystemEle_E2_allSequences.fillPosAndElementAndInteraction(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(mReplacedOpticalSystemEle_E2_allSequences, 550.0);
	// save the start system
	inportExportData::saveOpticalSystemAsTXT(mReplacedOpticalSystemEle_E2_allSequences, 550.0, mLocation_E2, "E2_start_DGaO2021");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(mReplacedOpticalSystemEle_E2_allSequences);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 7.644, 6.799, 12.986 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(mReplacedOpticalSystemEle_E2_allSequences, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::E2_imageSimulationWithReplacesSysAllSequences()
{

	std::vector<bool> workTheSystem;

	if (mReplacedOpticalSystemEle_E2_allSequences.getPosAndElement().size() < 1)
	{
		bool checkE2_loadReplacedSystemAllSequences = E2_loadReplacedSystemAllSequences();
		workTheSystem.push_back(checkE2_loadReplacedSystemAllSequences);
	}

	loadParaImaSim parameterImaSim{};
	parameterImaSim.setWavelengthBlue(486.1327);
	parameterImaSim.setWavelengthGreen(587.5818);
	parameterImaSim.setWavelengthRed(656.2725);
	parameterImaSim.setRayDensity(30);

	//light
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	light.setJonesVector({ 1.0,1.0,1.0,1.0 });
	light.setTypeLight(typeLight::typeLightRay);

	parameterImaSim.setLight(light);
	parameterImaSim.setSizeMatrixToSaveOPD(64);
	parameterImaSim.setInfOrObj(objectPoint_inf_obj::obj);
	parameterImaSim.setRowColResizeOPD(128);
	parameterImaSim.setSampling_x(11);
	parameterImaSim.setSampling_y(11);
	parameterImaSim.setSemiHeightObj(1000.0);
	parameterImaSim.setSemiWeidthObj(1000.0);
	parameterImaSim.setPosition_Z_Object(0.0);
	parameterImaSim.setUpSamplePSF(true);
	parameterImaSim.setResizeOPD_linear(true);
	parameterImaSim.setPaddingFactorPSF(1);
	parameterImaSim.setCalcDistortion(true);
	parameterImaSim.setSamplingDistortionHeight(450);
	parameterImaSim.setSamplingDistortionWidth(450);

	// load object
	cv::Mat elefantObj = cv::imread("../images/color/useThatImages/useThat/elefant_900x900.png", CV_LOAD_IMAGE_COLOR);

	ImageSimulationFunctions imaSim;
	imaSim.imageSimulationSuperFct(/*optical System Element*/ mReplacedOpticalSystemEle_E2_allSequences, /*object*/ elefantObj, /*parameter*/ parameterImaSim);

	cv::Mat simulatedIma = imaSim.getSimulatedImage_initialSize();
	// just for debugging
	// Images::showImage_inputReal_normTheImage("simulatedIma_E2_ReplaceLeftToRight", simulatedIma);
	// save the simulate images
	Images::saveImage_normalized(mLocation_E2_allSequences, "simulatedIma_E2_allPosSequences", "png", simulatedIma);


	cv::Mat distortionCorIma = imaSim.getSimulatedImage_initialSize_distortionCorrected();
	Images::saveImage_normalized(mLocation_E2_allSequences, "simulatedIma_E2_allSequences_distortionCorrected", "png", distortionCorIma);

	// *** noise *** //
	Noise noiseE2;
	float wave587d = 587.5618;
	cv::Mat simImaElefant = cv::imread("../tests/testDGaO2021/E2/allSequences/simulatedIma_E2_allSequences_distortionCorrected.png", CV_LOAD_IMAGE_COLOR);
	cameraParameterStruct camPara_VistecEco655 = oftenUse::getCamPara_VistecEco655();
	std::vector<float> wavelength{ wave587d, wave587d, wave587d };
	noiseE2.noiseSuperFunction_colorImage(simImaElefant, camPara_VistecEco655, 21, 0.002,/*Frage: welcher Wert passt hier*/ 0.035, wavelength, true);

	cv::Mat imageWithNoise = noiseE2.getImageWithNoise_Color_uint8_normed();
	// save the image
	Images::saveImage_normalized(mLocation_E2_allSequences, "imageWithNoise", "png", imageWithNoise);
	// make noise visable
	cv::Mat noiseImage = simImaElefant - imageWithNoise;
	cv::normalize(noiseImage, noiseImage, 0, 255, cv::NORM_MINMAX);
	Images::saveImage_normalized(mLocation_E2_allSequences, "noiseVisable_normalized", "png", noiseImage);
	Images::saveImage_NOTnormalized(mLocation_E2_allSequences, "noiseVisable_NOTnormalized", "png", noiseImage);
	// *** noise *** //

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::E2_improveImageQuality_AllPossibleSequences_refImage_UM_DE_WD()
{

	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_elefant = Images::loadAnImage_Color(loactionObject, "elefant_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMat_elefant_withNoise = Images::loadAnImage_Color(mLocation_E2_allSequences, "imageWithNoise");

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

	if (mDebugMode)
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

	if (mDebugMode)
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

	if (mDebugMode)
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


	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant_withNoise, methodeImaProc);


	cv::Mat filteredIma_final = imaProcessingSuperFunction.getAllFilteredImages_UM_DE_WD()[2];
	std::string locationFiltering = "../tests/testDGaO2021/E2/allSequences/filtering_SharpImage_UM_DE_WD";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E2_filteredIma_allSequnces_SharpImage_UM_DE_WD", "png", filteredIma_final, paraWD_blue.getCompareInPercent());

	

	// save best parameters WD
	saveBestParameterWD bestPara_blue = imaProcessingSuperFunction.getBestParaWD_blue();
	bestPara_blue.exportAsTXTfile(locationFiltering, "bestParaWD_blue", true);
	saveBestParameterWD bestPara_green = imaProcessingSuperFunction.getBestParaWD_green();
	bestPara_green.exportAsTXTfile(locationFiltering, "bestParaWD_green", true);
	saveBestParameterWD bestPara_red = imaProcessingSuperFunction.getBestParaWD_red();
	bestPara_red.exportAsTXTfile(locationFiltering, "bestParaWD_red", true);

	// save best para DE
	bestParameterStruct_detailEnhance bestParaDE = imaProcessingSuperFunction.getBestParaDetEnh();
	bestParaDE.exportAsTXTfile(locationFiltering, "bestParaDE", true);

	// save best para UM
	bestParameterStruct_unsharpMask bestParaUM_blue = imaProcessingSuperFunction.getBestParaUnsMas_blue();
	bestParaUM_blue.exportAsTXTfile(locationFiltering, "bestParaUM_blue", true);
	bestParameterStruct_unsharpMask bestParaUM_green = imaProcessingSuperFunction.getBestParaUnsMas_green();
	bestParaUM_green.exportAsTXTfile(locationFiltering, "bestParaUM_green", true);
	bestParameterStruct_unsharpMask bestParaUM_red = imaProcessingSuperFunction.getBestParaUnsMas_red();
	bestParaUM_red.exportAsTXTfile(locationFiltering, "bestParaUM_red", true);

	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_elefant, simImaMat_elefant_withNoise, filteredIma_final, paraUM_blue.getCompareInPercent());
	inportExportData::saveDoubleInTXT(locationFiltering,"improvement_SharpImage_UM_DE_WD", "improvement_SharpImage_UM_DE_WD: ", improvement, true);


	return true;
}

bool testDGaO2021::E2_improveImageQuality_AllPossibleSequences_refImage_UM()
{

	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_elefant = Images::loadAnImage_Color(loactionObject, "elefant_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMat_elefant_withNoise = Images::loadAnImage_Color(mLocation_E2_allSequences, "imageWithNoise");

	imageProcessing methodeImaProc = imageProcessing::unsharpMasking24;

	// *** parameter unsharp masking ***//
	// blue
	parameterUnsharpMasking paraUM_blue;
	paraUM_blue.setMinSigma(0.1);
	paraUM_blue.setMaxSigma(20.0);

	paraUM_blue.setMinThreshold(0.01);
	paraUM_blue.setMaxThreshold(5.0);

	paraUM_blue.setMinAmount(0.01);
	paraUM_blue.setMaxAmount(10.0);

	if (mDebugMode)
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

	

	// sharpness evaluation methode
	sharpnessEvalMethode tempShapEvalMethode = sharpnessEvalMethode::sharpImage;
	paraUM_blue.setSharpnessEvalMethode(tempShapEvalMethode);
	paraUM_green.setSharpnessEvalMethode(tempShapEvalMethode);
	paraUM_red.setSharpnessEvalMethode(tempShapEvalMethode);
	
	// set parameter
	ImaProcSuperFct imaProcessingSuperFunction;
	imaProcessingSuperFunction.setParameterUnsMas_blue(paraUM_blue);
	imaProcessingSuperFunction.setParameterUnsMas_green(paraUM_green);
	imaProcessingSuperFunction.setParameterUnsMas_red(paraUM_red);

	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant_withNoise, methodeImaProc);
	real reinizializePrecent = 20.0;
	imaProcessingSuperFunction.reinitializeBestParaUnsMas(reinizializePrecent, paraUM_blue.getStepsSigma(),paraUM_blue.getStepsThreshold(), paraUM_blue.getStepsAmount());
	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant_withNoise, methodeImaProc);

	cv::Mat filteredIma_final = imaProcessingSuperFunction.getFilteredIma();
	std::string locationFiltering = "../tests/testDGaO2021/E2/allSequences/filtering_SharpImage_UM";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E2_filteredIma_allSequnces_SharpImage_UM", "png", filteredIma_final, paraUM_blue.getCompareInPercent());


	// save best para UM
	bestParameterStruct_unsharpMask bestParaUM_blue = imaProcessingSuperFunction.getBestParaUnsMas_blue();
	bestParaUM_blue.exportAsTXTfile(locationFiltering, "bestParaUM_blue", true);
	bestParameterStruct_unsharpMask bestParaUM_green = imaProcessingSuperFunction.getBestParaUnsMas_green();
	bestParaUM_green.exportAsTXTfile(locationFiltering, "bestParaUM_green", true);
	bestParameterStruct_unsharpMask bestParaUM_red = imaProcessingSuperFunction.getBestParaUnsMas_red();
	bestParaUM_red.exportAsTXTfile(locationFiltering, "bestParaUM_red", true);

	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_elefant, simImaMat_elefant_withNoise, filteredIma_final, paraUM_blue.getCompareInPercent());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_SharpImage_UM", "improvement_SharpImage_UM: ", improvement, true);


	return true;
}
bool testDGaO2021::E2_improveImageQuality_AllPossibleSequences_refImage_DE()
{
	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_elefant = Images::loadAnImage_Color(loactionObject, "elefant_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMat_elefant_withNoise = Images::loadAnImage_Color(mLocation_E2_allSequences, "imageWithNoise");

	imageProcessing methodeImaProc = imageProcessing::detailEnhance24;

	// *** parameter DE 
	parameterDetailEnhancement paraDE;
	paraDE.setMinSigma_r(0.001);
	paraDE.setMaxSigma_r(100.0);

	paraDE.setMinSigma_s(1.0);
	paraDE.setMaxSigma_s(100.0);

	paraDE.setPercentCompare(0.0);

	if (mDebugMode)
	{
		paraDE.setStepsSigma_r(20.0);
		paraDE.setStepsSigma_s(20.0);
	}
	else
	{
		paraDE.setStepsSigma_r(200.0);
		paraDE.setStepsSigma_s(200.0);
	}

	
	// sharpness evaluation methode
	sharpnessEvalMethode tempShapEvalMethode = sharpnessEvalMethode::sharpImage;
	paraDE.setSharpnessEvalMethode(tempShapEvalMethode);

	// set parameter
	ImaProcSuperFct imaProcessingSuperFunction;
	imaProcessingSuperFunction.setParameterDetEnh(paraDE);


	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant_withNoise, methodeImaProc);
	real reinizializePrecent = 20.0;
	imaProcessingSuperFunction.reinitializeBestParaDetEng(reinizializePrecent, paraDE.getStepsSigma_r(), paraDE.getStepsSigma_s());
	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant_withNoise, methodeImaProc);


	cv::Mat filteredIma_final = imaProcessingSuperFunction.getFilteredIma();
	std::string locationFiltering = "../tests/testDGaO2021/E2/allSequences/filtering_SharpImage_DE";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E2_filteredIma_allSequnces_SharpImage_DE", "png", filteredIma_final, paraDE.getPercentCompare());

	// save best para DE
	bestParameterStruct_detailEnhance bestParaDE = imaProcessingSuperFunction.getBestParaDetEnh();
	bestParaDE.exportAsTXTfile(locationFiltering, "bestParaDE", true);

	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_elefant, simImaMat_elefant_withNoise, filteredIma_final, paraDE.getPercentCompare());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_SharpImage_DE", "improvement_SharpImage_DE: ", improvement, true);


	return true;
}
bool testDGaO2021::E2_improveImageQuality_AllPossibleSequences_refImage_WD()
{
	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_elefant = Images::loadAnImage_Color(loactionObject, "elefant_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMat_elefant_withNoise = Images::loadAnImage_Color(mLocation_E2_allSequences, "imageWithNoise");

	imageProcessing methodeImaProc = imageProcessing::wienerFilter24;

	// *** parameter wiener filter *** 
	// *** parameter blue *** 
	parameterImaImprove_WD paraWD_blue{};
	paraWD_blue.setMinSNR(0.1);
	paraWD_blue.setMaxSNR(200.0);
	paraWD_blue.setMinSigmaXY(0.1);
	paraWD_blue.setMaxSigmaXY(5.0);
	paraWD_blue.setKernelSizeHeightAndWidth(30);
	paraWD_blue.setCompareInPercent(0.0);

	if (mDebugMode)
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
	paraWD_blue.setSharpnessEvalMethode(tempShapEvalMethode);
	paraWD_green.setSharpnessEvalMethode(tempShapEvalMethode);
	paraWD_red.setSharpnessEvalMethode(tempShapEvalMethode);

	// set parameter
	ImaProcSuperFct imaProcessingSuperFunction;
	imaProcessingSuperFunction.setParameterWD_blue(paraWD_blue);
	imaProcessingSuperFunction.setParameterWD_green(paraWD_green);
	imaProcessingSuperFunction.setParameterWD_red(paraWD_red);


	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant_withNoise, methodeImaProc);
	real reinizializePrecent = 20.0;
	imaProcessingSuperFunction.reinitializeBestParaWD(reinizializePrecent, paraWD_blue.getStepsSNR(), paraWD_blue.getStepsSigmaXY());
	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant_withNoise, methodeImaProc);

	cv::Mat filteredIma_final = imaProcessingSuperFunction.getFilteredIma();
	std::string locationFiltering = "../tests/testDGaO2021/E2/allSequences/filtering_SharpImage_WD";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E2_filteredIma_allSequnces_SharpImage_WD", "png", filteredIma_final, paraWD_blue.getCompareInPercent());



	// save best parameters WD
	saveBestParameterWD bestPara_blue = imaProcessingSuperFunction.getBestParaWD_blue();
	bestPara_blue.exportAsTXTfile(locationFiltering, "bestParaWD_blue", true);
	saveBestParameterWD bestPara_green = imaProcessingSuperFunction.getBestParaWD_green();
	bestPara_green.exportAsTXTfile(locationFiltering, "bestParaWD_green", true);
	saveBestParameterWD bestPara_red = imaProcessingSuperFunction.getBestParaWD_red();
	bestPara_red.exportAsTXTfile(locationFiltering, "bestParaWD_red", true);

	

	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_elefant, simImaMat_elefant_withNoise, filteredIma_final, paraWD_blue.getCompareInPercent());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_SharpImag_WD", "improvement_SharpImage_WD: ", improvement, true);

	return true;
}

bool testDGaO2021::E2_improveImageQuality_AllPossibleSequences_BlurAndNois_UM_DE_WD()
{

	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_elefant = Images::loadAnImage_Color(loactionObject, "elefant_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMat_elefant_withNoise = Images::loadAnImage_Color(mLocation_E2_allSequences, "imageWithNoise");

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

	if (mDebugMode)
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

	if (mDebugMode)
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

	if (mDebugMode)
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
	sharpnessEvalMethode tempShapEvalMethode = sharpnessEvalMethode::BlurAndNoise;
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


	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant_withNoise, methodeImaProc);
	std::string locationFiltering = "../tests/testDGaO2021/E2/allSequences/filtering_BlurAndNoise_UM_DE_WD";

	// image UM
	cv::Mat filteredIma_firstUM = imaProcessingSuperFunction.getAllFilteredImages_UM_DE_WD()[0];
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E2_filteredIma_allSequnces_BlurAndNoise_firstUM", "png", filteredIma_firstUM, paraWD_blue.getCompareInPercent());

	// image UM-DE
	cv::Mat filteredIma_SecondUM_DE = imaProcessingSuperFunction.getAllFilteredImages_UM_DE_WD()[1];
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E2_filteredIma_allSequnces_BlurAndNoise_secondUM_DE", "png", filteredIma_SecondUM_DE, paraWD_blue.getCompareInPercent());

	// final image (UM_DE_WD)
	cv::Mat filteredIma_final = imaProcessingSuperFunction.getAllFilteredImages_UM_DE_WD()[2];
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E2_filteredIma_allSequnces_BlurAndNoise_UM_DE_WD", "png", filteredIma_final, paraWD_blue.getCompareInPercent());

	

	// save best parameters WD
	saveBestParameterWD bestPara_blue = imaProcessingSuperFunction.getBestParaWD_blue();
	bestPara_blue.exportAsTXTfile(locationFiltering, "bestParaWD_blue", true);
	saveBestParameterWD bestPara_green = imaProcessingSuperFunction.getBestParaWD_green();
	bestPara_green.exportAsTXTfile(locationFiltering, "bestParaWD_green", true);
	saveBestParameterWD bestPara_red = imaProcessingSuperFunction.getBestParaWD_red();
	bestPara_red.exportAsTXTfile(locationFiltering, "bestParaWD_red", true);

	// save best para DE
	bestParameterStruct_detailEnhance bestParaDE = imaProcessingSuperFunction.getBestParaDetEnh();
	bestParaDE.exportAsTXTfile(locationFiltering, "bestParaDE", true);

	// save best para UM
	bestParameterStruct_unsharpMask bestParaUM_blue = imaProcessingSuperFunction.getBestParaUnsMas_blue();
	bestParaUM_blue.exportAsTXTfile(locationFiltering, "bestParaUM_blue", true);
	bestParameterStruct_unsharpMask bestParaUM_green = imaProcessingSuperFunction.getBestParaUnsMas_green();
	bestParaUM_green.exportAsTXTfile(locationFiltering, "bestParaUM_green", true);
	bestParameterStruct_unsharpMask bestParaUM_red = imaProcessingSuperFunction.getBestParaUnsMas_red();
	bestParaUM_red.exportAsTXTfile(locationFiltering, "bestParaUM_red", true);

	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_elefant, simImaMat_elefant_withNoise, filteredIma_final, paraUM_blue.getCompareInPercent());
	inportExportData::saveDoubleInTXT(mLocation_E2_allSequences, "improvement_BlurAndNoise_UM_DE_WD", "improvement_BlurAndNoise_UM_DE_WD: ", improvement, true);


	return true;
}

bool testDGaO2021::E2_improveImageQuality_AllPossibleSequences_BlurAndNois_UM()
{
	
	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_elefant = Images::loadAnImage_Color(loactionObject, "elefant_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMat_elefant_withNoise = Images::loadAnImage_Color(mLocation_E2_allSequences, "imageWithNoise");

	imageProcessing methodeImaProc = imageProcessing::unsharpMasking24;

	// *** parameter unsharp masking ***//
	// blue
	parameterUnsharpMasking paraUM_blue;
	paraUM_blue.setMinSigma(0.1);
	paraUM_blue.setMaxSigma(20.0);

	paraUM_blue.setMinThreshold(0.01);
	paraUM_blue.setMaxThreshold(5.0);

	paraUM_blue.setMinAmount(0.01);
	paraUM_blue.setMaxAmount(10.0);

	if (mDebugMode)
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



	// sharpness evaluation methode
	sharpnessEvalMethode tempShapEvalMethode = sharpnessEvalMethode::BlurAndNoise;
	paraUM_blue.setSharpnessEvalMethode(tempShapEvalMethode);
	paraUM_green.setSharpnessEvalMethode(tempShapEvalMethode);
	paraUM_red.setSharpnessEvalMethode(tempShapEvalMethode);

	// set parameter
	ImaProcSuperFct imaProcessingSuperFunction;
	imaProcessingSuperFunction.setParameterUnsMas_blue(paraUM_blue);
	imaProcessingSuperFunction.setParameterUnsMas_green(paraUM_green);
	imaProcessingSuperFunction.setParameterUnsMas_red(paraUM_red);

	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant_withNoise, methodeImaProc);
	real reinizializePrecent = 20.0;
	imaProcessingSuperFunction.reinitializeBestParaUnsMas(reinizializePrecent, paraUM_blue.getStepsSigma(), paraUM_blue.getStepsThreshold(), paraUM_blue.getStepsAmount());
	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant_withNoise, methodeImaProc);

	cv::Mat filteredIma_final = imaProcessingSuperFunction.getFilteredIma();
	std::string locationFiltering = "../tests/testDGaO2021/E2/allSequences/filtering_BlurAndNoise_UM";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E2_filteredIma_allSequnces_BlurAndNoise_UM", "png", filteredIma_final, paraUM_blue.getCompareInPercent());


	// save best para UM
	bestParameterStruct_unsharpMask bestParaUM_blue = imaProcessingSuperFunction.getBestParaUnsMas_blue();
	bestParaUM_blue.exportAsTXTfile(locationFiltering, "bestParaUM_blue", true);
	bestParameterStruct_unsharpMask bestParaUM_green = imaProcessingSuperFunction.getBestParaUnsMas_green();
	bestParaUM_green.exportAsTXTfile(locationFiltering, "bestParaUM_green", true);
	bestParameterStruct_unsharpMask bestParaUM_red = imaProcessingSuperFunction.getBestParaUnsMas_red();
	bestParaUM_red.exportAsTXTfile(locationFiltering, "bestParaUM_red", true);

	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_elefant, simImaMat_elefant_withNoise, filteredIma_final, paraUM_blue.getCompareInPercent());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_BlurAndNoise_UM", "improvement_BlurAndNoise_UM: ", improvement, true);


	return true;
}

bool testDGaO2021::E2_improveImageQuality_AllPossibleSequences_BlurAndNois_DE()
{
	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_elefant = Images::loadAnImage_Color(loactionObject, "elefant_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMat_elefant_withNoise = Images::loadAnImage_Color(mLocation_E2_allSequences, "imageWithNoise");

	imageProcessing methodeImaProc = imageProcessing::detailEnhance24;

	// *** parameter DE 
	parameterDetailEnhancement paraDE;
	paraDE.setMinSigma_r(0.001);
	paraDE.setMaxSigma_r(100.0);

	paraDE.setMinSigma_s(1.0);
	paraDE.setMaxSigma_s(100.0);

	paraDE.setPercentCompare(0.0);

	if (mDebugMode)
	{
		paraDE.setStepsSigma_r(20.0);
		paraDE.setStepsSigma_s(20.0);
	}
	else
	{
		paraDE.setStepsSigma_r(200.0);
		paraDE.setStepsSigma_s(200.0);
	}


	// sharpness evaluation methode
	sharpnessEvalMethode tempShapEvalMethode = sharpnessEvalMethode::BlurAndNoise;
	paraDE.setSharpnessEvalMethode(tempShapEvalMethode);

	// set parameter
	ImaProcSuperFct imaProcessingSuperFunction;
	imaProcessingSuperFunction.setParameterDetEnh(paraDE);


	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant_withNoise, methodeImaProc);
	real reinizializePrecent = 20.0;
	imaProcessingSuperFunction.reinitializeBestParaDetEng(reinizializePrecent, paraDE.getStepsSigma_r(), paraDE.getStepsSigma_s());
	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant_withNoise, methodeImaProc);


	cv::Mat filteredIma_final = imaProcessingSuperFunction.getFilteredIma();
	std::string locationFiltering = "../tests/testDGaO2021/E2/allSequences/filtering_BlurAndNoise_DE";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E2_filteredIma_allSequnces_BlurAndNoise_DE", "png", filteredIma_final, paraDE.getPercentCompare());


	// save best para DE
	bestParameterStruct_detailEnhance bestParaDE = imaProcessingSuperFunction.getBestParaDetEnh();
	bestParaDE.exportAsTXTfile(locationFiltering, "bestParaDE", true);


	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_elefant, simImaMat_elefant_withNoise, filteredIma_final, paraDE.getPercentCompare());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_BlurAndNoise_DE", "improvement_BlurAndNoise_DE: ", improvement, true);


	return true;
}

bool testDGaO2021::E2_improveImageQuality_AllPossibleSequences_BlurAndNois_WD()
{
	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_elefant = Images::loadAnImage_Color(loactionObject, "elefant_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMat_elefant_withNoise = Images::loadAnImage_Color(mLocation_E2_allSequences, "imageWithNoise");

	imageProcessing methodeImaProc = imageProcessing::wienerFilter24;

	// *** parameter wiener filter *** 
	// *** parameter blue *** 
	parameterImaImprove_WD paraWD_blue{};
	paraWD_blue.setMinSNR(0.1);
	paraWD_blue.setMaxSNR(200.0);
	paraWD_blue.setMinSigmaXY(0.1);
	paraWD_blue.setMaxSigmaXY(5.0);
	paraWD_blue.setKernelSizeHeightAndWidth(30);
	paraWD_blue.setCompareInPercent(0.0);

	if (mDebugMode)
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
	sharpnessEvalMethode tempShapEvalMethode = sharpnessEvalMethode::BlurAndNoise;
	paraWD_blue.setSharpnessEvalMethode(tempShapEvalMethode);
	paraWD_green.setSharpnessEvalMethode(tempShapEvalMethode);
	paraWD_red.setSharpnessEvalMethode(tempShapEvalMethode);

	// set parameter
	ImaProcSuperFct imaProcessingSuperFunction;
	imaProcessingSuperFunction.setParameterWD_blue(paraWD_blue);
	imaProcessingSuperFunction.setParameterWD_green(paraWD_green);
	imaProcessingSuperFunction.setParameterWD_red(paraWD_red);


	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant_withNoise, methodeImaProc);
	real reinizializePrecent = 20.0;
	imaProcessingSuperFunction.reinitializeBestParaWD(reinizializePrecent, paraWD_blue.getStepsSNR(), paraWD_blue.getStepsSigmaXY());
	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_elefant, simImaMat_elefant_withNoise, methodeImaProc);

	cv::Mat filteredIma_final = imaProcessingSuperFunction.getFilteredIma();
	std::string locationFiltering = "../tests/testDGaO2021/E2/allSequences/filtering_BlurAndNoise_WD";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E2_filteredIma_allSequnces_BlurAndNoise_WD", "png", filteredIma_final, paraWD_blue.getCompareInPercent());



	// save best parameters WD
	saveBestParameterWD bestPara_blue = imaProcessingSuperFunction.getBestParaWD_blue();
	bestPara_blue.exportAsTXTfile(locationFiltering, "bestParaWD_blue", true);
	saveBestParameterWD bestPara_green = imaProcessingSuperFunction.getBestParaWD_green();
	bestPara_green.exportAsTXTfile(locationFiltering, "bestParaWD_green", true);
	saveBestParameterWD bestPara_red = imaProcessingSuperFunction.getBestParaWD_red();
	bestPara_red.exportAsTXTfile(locationFiltering, "bestParaWD_red", true);


	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_elefant, simImaMat_elefant_withNoise, filteredIma_final, paraWD_blue.getCompareInPercent());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_BlurAndNoise_WD", "improvement_BlurAndNoise_WD: ", improvement, true);

	return true;
}


// *** E3 ***
bool testDGaO2021::checkE3_DGaO2021()
{
	std::vector<bool> workTheSystem;

	//// check start system
	//bool checkE3_checkStartSystem = E3_checkStartSystem();
	//workTheSystem.push_back(checkE3_checkStartSystem);
	//
	//// check optimize start system
	//bool checkE3_checkOptimizeStartSystem_DoOptimization = E3_checkOptimizeStartSystem_DoOptimization();
	//workTheSystem.push_back(checkE3_checkOptimizeStartSystem_DoOptimization);
	//
	//// do the lens replace
	//bool checkE3_lensReplace = E3_lensReplace();
	//workTheSystem.push_back(checkE3_lensReplace);
	//
	//// check load replace system left to right
	//bool checkE3_loadReplaceSystemLeftTpRight = E3_loadReplaceSystemLeftToRight();
	//workTheSystem.push_back(checkE3_loadReplaceSystemLeftTpRight);
	//
	// do image simulation
	//bool checkE3_imageSimulation = E3_doImageSimulation_replayedSysLeftToRight();
	//workTheSystem.push_back(checkE3_imageSimulation);
	
	// filtering sharp image
	bool check_refImage_UM_DE_WD = E3_improveImageQuality_AllPossibleSequences_refImage_UM_DE_WD();
	workTheSystem.push_back(check_refImage_UM_DE_WD);
	bool check_refImage_UM = E3_improveImageQuality_AllPossibleSequences_refImage_UM();
	workTheSystem.push_back(check_refImage_UM);
	bool check_refImage_DE = E3_improveImageQuality_AllPossibleSequences_refImage_DE();
	workTheSystem.push_back(check_refImage_DE);
	bool check_refImage_WD = E3_improveImageQuality_AllPossibleSequences_refImage_WD();
	workTheSystem.push_back(check_refImage_WD);
	
	// filtering blur and noise
	bool check_BlurAndNoise_UM_DE_WD = E3_improveImageQuality_AllPossibleSequences_BlurAndNoise_UM_DE_WD();
	workTheSystem.push_back(check_BlurAndNoise_UM_DE_WD);
	bool check_BlurAndNoise_UM = E3_improveImageQuality_AllPossibleSequences_BlurAndNois_UM();
	workTheSystem.push_back(check_BlurAndNoise_UM);
	bool check_BlurAndNoise_DE = E3_improveImageQuality_AllPossibleSequences_BlurAndNois_DE();
	workTheSystem.push_back(check_BlurAndNoise_DE);
	bool check_BlurAndNoise_WD = E3_improveImageQuality_AllPossibleSequences_BlurAndNois_WD();
	workTheSystem.push_back(check_BlurAndNoise_WD);


	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}
	

bool testDGaO2021::E3_checkStartSystem()
{

	std::vector<bool> workTheSystem;

	real semiHeight = 15.0;
	real firstThickness = 1500.0;

	

	SphericalElement S0(/*radius*/ 300.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 10.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S1(/*radius*/ 80.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 15.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 300.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 20.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	ApertureStopElement S3(/* semi height*/ 3.0, /*point*/{ 0.0,0.0, firstThickness + 30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S4(/*radius*/ 180.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF10_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S6(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF10_S1());

	SphericalElement S7(/*radius*/ 2500.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSK11_S1());
	SphericalElement S8(/*radius*/ 350.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSK11_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S9(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S10(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S11(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 90.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S12(/*radius*/ 300.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 100.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getSF5_S1());

	PlanElement S13(/*semi height*/ 99.0, /*point*/{ 0.0,0.0, firstThickness + 140.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	// radii
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	// thicknesses
	S12.setParameterPointZ(/*min value*/ 10.0, /*max value*/ 50.0, 0.0, typeModifierVariable);
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
	surfacePtr S11_ptr = S11.clone();
	surfacePtr S12_ptr = S12.clone();
	surfacePtr S13_ptr = S13.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	mStartOpticalSystem_E3.fillPosAndElementAndInteraction(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(mStartOpticalSystem_E3, mWave587d);
	// save the start system
	inportExportData::saveOpticalSystemAsTXT(mStartOpticalSystem_E3, mWave587d, mLocationE3, "E3_start_DGaO2021");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(mStartOpticalSystem_E3);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 22.301, 34.038, 43.304 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(mStartOpticalSystem_E3, mField_E3_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);


	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}


bool testDGaO2021::E3_checkOptimizeStartSystem_DoOptimization()
{
	std::vector<bool> workTheSystem;

	OpticalSystemElement initalOpticalSystemEle = mStartOpticalSystem_E3.getDeepCopyOptSysEle();

	// optimize optical system
	DLS_multiThreads_12 DLS12(/*optSysEle*/ initalOpticalSystemEle,/*fields*/ mField_E3_vec, /*wavelength*/ mWavelength_FdV_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints_E3, /*default DLS*/ mDefaulParaDLS);
	mOptimizedOpticalSystemEle_E3 = DLS12.DLS_optimisation_multiThreads_12_obj();

	// export the first optimized system
	inportExportData::saveOpticalSystemAsTXT(mOptimizedOpticalSystemEle_E3, mWave587d, mLocationE3, "E3_optimized_first");


	// check optimized system
	std::vector<real> rmsVecInitalOptSys = oftenUse::getRMSoptSysHLT(mStartOpticalSystem_E3, mField_E3_vec, mWavelength_FdV_vec, mRings, mArms);
	std::vector<real> rmsVecGeneticDLS_12 = oftenUse::getRMSoptSysHLT(mOptimizedOpticalSystemEle_E3, mField_E3_vec, mWavelength_FdV_vec, mRings, mArms);

	real sumRMS_initalOptSys = oftenUse::sum(rmsVecInitalOptSys);
	real sumRMS_optimizedOptSys = oftenUse::sum(rmsVecGeneticDLS_12);

	bool checkOptimization = sumRMS_initalOptSys > sumRMS_optimizedOptSys;
	workTheSystem.push_back(checkOptimization);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}



bool testDGaO2021::E3_lensReplace()
{
	std::vector<bool> workTheSystem;
	std::string example = "E3";
	unsigned int numberBestFitLenses = 2;
	optimizeMethode optMethode = optimizeMethode::DLS_12;

	// left to right
	replaceSequence leftToRight = replaceSequence::leftToRight;
	saveLRaO_GeneticAndDLS_12_statistic leftToRight_statRes = oftenUse::doTheStatisticEvaluation_lensSystem_LTR_RTL_MaxSei_MinSei_obj_saveIntermediateResults(mOptimizedOpticalSystemEle_E3, mField_E3_vec,mWavelength_FdV_vec, mTargetCarPoints_E3, mLocationE3, example, leftToRight, optMethode, numberBestFitLenses, mDebugMode, false);
	std::string leftToRight_name = "leftToRight";
	std::string locLeftToRight = mLocationE3 + "/" + leftToRight_name;
	oftenUse::exportDataReplace_FOUR_LensesGeneticAndDLS_12(locLeftToRight, leftToRight_name, leftToRight_statRes);

	// right to left
	replaceSequence rightToLeft = replaceSequence::RightToLeft;
	saveLRaO_GeneticAndDLS_12_statistic rightToLeft_statRes = oftenUse::doTheStatisticEvaluation_lensSystem_LTR_RTL_MaxSei_MinSei_obj_saveIntermediateResults(mOptimizedOpticalSystemEle_E3, mField_E3_vec, mWavelength_FdV_vec, mTargetCarPoints_E3, mLocationE3, example, rightToLeft, optMethode, numberBestFitLenses, mDebugMode, false);
	std::string rightToLeft_name = "rightToLeft";
	std::string locRightToLeft = mLocationE3 + "/" + rightToLeft_name;
	oftenUse::exportDataReplace_FOUR_LensesGeneticAndDLS_12(locRightToLeft, rightToLeft_name, rightToLeft_statRes);

	// max Seidel
	replaceSequence maxSeidel = replaceSequence::maxSeidelAberLens;
	saveLRaO_GeneticAndDLS_12_statistic maxSeidel_statRes = oftenUse::doTheStatisticEvaluation_lensSystem_LTR_RTL_MaxSei_MinSei_obj_saveIntermediateResults(mOptimizedOpticalSystemEle_E3, mField_E3_vec, mWavelength_FdV_vec, mTargetCarPoints_E3, mLocationE3, example, maxSeidel, optMethode, numberBestFitLenses, mDebugMode, false);
	std::string maxSeidel_name = "maxSeidel";
	std::string locMaxSeidel = mLocationE3 + "/" + maxSeidel_name;
	oftenUse::exportDataReplace_FOUR_LensesGeneticAndDLS_12(locMaxSeidel, maxSeidel_name, maxSeidel_statRes);

	// min Seidel
	replaceSequence minSeidel = replaceSequence::minSeidelAberLens;
	saveLRaO_GeneticAndDLS_12_statistic minSeidel_statRes = oftenUse::doTheStatisticEvaluation_lensSystem_LTR_RTL_MaxSei_MinSei_obj_saveIntermediateResults(mOptimizedOpticalSystemEle_E3, mField_E3_vec, mWavelength_FdV_vec, mTargetCarPoints_E3, mLocationE3, example, minSeidel, optMethode, numberBestFitLenses, mDebugMode, false);
	std::string minSeidel_name = "minSeidel";
	std::string locMinxSeidel = mLocationE3 + "/" + minSeidel_name;
	oftenUse::exportDataReplace_FOUR_LensesGeneticAndDLS_12(locMinxSeidel, minSeidel_name, minSeidel_statRes);


	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::E3_loadReplaceSystemLeftToRight()
{
	std::vector<bool> workTheSystem;
	real firstThickness = 1500.0;

	SphericalElement S0(/*radius*/ 315.18, /*semi height*/ 20.0, /*point*/{ 0.0,0.0, firstThickness + 10.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S1(/*radius*/ 506.69, /*semi height*/20.0, /*point*/{ 0.0,0.0, firstThickness + 14.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	PlanElement S2(/*semi height*/ 20.0, /*point*/{ 0.0,0.0, firstThickness + 18.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/ mGlasses.getAir());

	ApertureStopElement S3(/* semi height*/ 3.0, /*point*/{ 0.0,0.0, firstThickness + 28.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S4(/*radius*/ 91.31, /*semi height*/ 15.0, /*point*/{ 0.0,0.0, firstThickness + 38.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 65.57, /*semi height*/ 15.0, /*point*/{ 0.0,0.0, firstThickness + 46.1 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 195.87, /*semi height*/ 15.0, /*point*/{ 0.0,0.0, firstThickness + 48.7 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S7(/*radius*/ 195.87, /*semi height*/ 15.0, /*point*/{ 0.0,0.0, firstThickness + 58.7 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S8(/*radius*/ 65.57, /*semi height*/ 15.0, /*point*/{ 0.0,0.0, firstThickness + 61.3 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S9(/*radius*/ 91.31, /*semi height*/ 15.0, /*point*/{ 0.0,0.0, firstThickness + 69.4 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S10(/*radius*/ 124.12, /*semi height*/ 12.5, /*point*/{ 0.0,0.0, firstThickness + 79.4 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S11(/*radius*/ 87.26, /*semi height*/ 12.5, /*point*/{ 0.0,0.0, firstThickness + 87.9 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S12(/*radius*/ 253.1, /*semi height*/ 12.5, /*point*/{ 0.0,0.0, firstThickness + 91.9 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getSF5_S1());

	PlanElement S13(/*semi height*/ 99.0, /*point*/{ 0.0,0.0, firstThickness + 126.4833 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());


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
	surfacePtr S12_ptr = S12.clone();
	surfacePtr S13_ptr = S13.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	mReplacedOpticalSystemEle_E3_leftToRight.fillPosAndElementAndInteraction(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(mReplacedOpticalSystemEle_E3_leftToRight, 550.0);
	// save the start system
	inportExportData::saveOpticalSystemAsTXT(mReplacedOpticalSystemEle_E3_leftToRight, 550.0, mLocation_E3_leftToRight, "E3_ReplaceLeftToRight");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(mReplacedOpticalSystemEle_E3_leftToRight);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 14.533, 5.021, 17.270 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(mReplacedOpticalSystemEle_E3_leftToRight, mField_E3_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::E3_doImageSimulation_replayedSysLeftToRight()
{
	std::vector<bool> workTheSystem;

	if (mReplacedOpticalSystemEle_E3_leftToRight.getPosAndElement().size() < 1)
	{
		bool checkReplacedOpticalSystemEle_E3_leftToRight = E3_loadReplaceSystemLeftToRight();
		workTheSystem.push_back(checkReplacedOpticalSystemEle_E3_leftToRight);
	}

	loadParaImaSim parameterImaSim{};
	parameterImaSim.setWavelengthBlue(486.1327);
	parameterImaSim.setWavelengthGreen(587.5818);
	parameterImaSim.setWavelengthRed(656.2725);
	parameterImaSim.setRayDensity(30);

	//light
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	light.setJonesVector({ 1.0,1.0,1.0,1.0 });
	light.setTypeLight(typeLight::typeLightRay);

	parameterImaSim.setLight(light);
	parameterImaSim.setSizeMatrixToSaveOPD(64);
	parameterImaSim.setInfOrObj(objectPoint_inf_obj::obj);
	parameterImaSim.setRowColResizeOPD(128);
	parameterImaSim.setSampling_x(11);
	parameterImaSim.setSampling_y(11);
	parameterImaSim.setSemiHeightObj(250.0);
	parameterImaSim.setSemiWeidthObj(250.0);
	parameterImaSim.setPosition_Z_Object(0.0);
	parameterImaSim.setUpSamplePSF(true);
	parameterImaSim.setResizeOPD_linear(true);
	parameterImaSim.setPaddingFactorPSF(1);
	// there is no distortion in the image
	parameterImaSim.setCalcDistortion(false);
	parameterImaSim.setSamplingDistortionHeight(450);
	parameterImaSim.setSamplingDistortionWidth(450);

	// load object
	cv::Mat flower2 = cv::imread("../images/color/testImaSim_test12/flower2_900x900.png", CV_LOAD_IMAGE_COLOR);

	ImageSimulationFunctions imaSim;
	imaSim.imageSimulationSuperFct(/*optical System Element*/ mReplacedOpticalSystemEle_E3_leftToRight, /*object*/ flower2, /*parameter*/ parameterImaSim);


	cv::Mat simulatedIma = imaSim.getSimulatedImage_initialSize();
	// just for debugging
	// Images::showImage_inputReal_normTheImage("simulatedIma_E2_ReplaceLeftToRight", simulatedIma);
	// save the simulate images
	Images::saveImage_normalized(mLocation_E3_leftToRight, "simulatedIma_E3_leftToRight", "png", simulatedIma);

	//cv::Mat distortionCorIma = imaSim.getSimulatedImage_initialSize_distortionCorrected();
	//Images::saveImage_normalized(mLocation_E3_leftToRight, "simulatedIma_E3_leftToRight_distortionCorrected", "png", distortionCorIma);


	// *** noise *** //
	Noise noiseE3;
	float wave587d = 587.5618;
	cv::Mat simImaflower2 = cv::imread("../tests/testDGaO2021/E3/leftToRight/simulatedIma_E3_leftToRight.png", CV_LOAD_IMAGE_COLOR);
	cameraParameterStruct camPara_VistecEco655 = oftenUse::getCamPara_VistecEco655();
	std::vector<float> wavelength{ wave587d, wave587d, wave587d };
	noiseE3.noiseSuperFunction_colorImage(simImaflower2, camPara_VistecEco655, 21, 0.002,/*Frage: welcher Wert passt hier*/ 0.035, wavelength, true);

	cv::Mat imageWithNoise = noiseE3.getImageWithNoise_Color_uint8_normed();
	// save the image
	Images::saveImage_normalized(mLocation_E3_leftToRight, "imageWithNoise", "png", imageWithNoise);
	// make noise visable
	cv::Mat noiseImage = simImaflower2 - imageWithNoise;
	cv::normalize(noiseImage, noiseImage, 0, 255, cv::NORM_MINMAX);
	Images::saveImage_normalized(mLocation_E3_leftToRight, "noiseVisable_normalized", "png", noiseImage);
	Images::saveImage_NOTnormalized(mLocation_E3_leftToRight, "noiseVisable_NOTnormalized", "png", noiseImage);
	// *** noise *** //

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// filtering sharp image
bool testDGaO2021::E3_improveImageQuality_AllPossibleSequences_refImage_UM_DE_WD()
{
	// *** load objects *** //
	std::string loactionFlower = "../images/color/testImaSim_test12";
	cv::Mat object_flower = Images::loadAnImage_Color(loactionFlower, "flower2_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMatFlowerWithNoise = Images::loadAnImage_Color(mLocation_E3_leftToRight, "imageWithNoise");

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

	if (mDebugMode)
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

	if (mDebugMode)
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

	if (mDebugMode)
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


	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower, simImaMatFlowerWithNoise, methodeImaProc);


	cv::Mat filteredIma_final = imaProcessingSuperFunction.getAllFilteredImages_UM_DE_WD()[2];
	std::string locationFiltering = "../tests/testDGaO2021/E3/leftToRight/filtering_SharpImage_UM_DE_WD";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E3_filteredIma_leftToRight_SharpImage_UM_DE_WD", "png", filteredIma_final, paraWD_blue.getCompareInPercent());

	// save best parameters WD
	saveBestParameterWD bestPara_blue = imaProcessingSuperFunction.getBestParaWD_blue();
	bestPara_blue.exportAsTXTfile(locationFiltering, "bestParaWD_blue", true);
	saveBestParameterWD bestPara_green = imaProcessingSuperFunction.getBestParaWD_green();
	bestPara_green.exportAsTXTfile(locationFiltering, "bestParaWD_green", true);
	saveBestParameterWD bestPara_red = imaProcessingSuperFunction.getBestParaWD_red();
	bestPara_red.exportAsTXTfile(locationFiltering, "bestParaWD_red", true);

	// save best para DE
	bestParameterStruct_detailEnhance bestParaDE = imaProcessingSuperFunction.getBestParaDetEnh();
	bestParaDE.exportAsTXTfile(locationFiltering, "bestParaDE", true);

	// save best para UM
	bestParameterStruct_unsharpMask bestParaUM_blue = imaProcessingSuperFunction.getBestParaUnsMas_blue();
	bestParaUM_blue.exportAsTXTfile(locationFiltering, "bestParaUM_blue", true);
	bestParameterStruct_unsharpMask bestParaUM_green = imaProcessingSuperFunction.getBestParaUnsMas_green();
	bestParaUM_green.exportAsTXTfile(locationFiltering, "bestParaUM_green", true);
	bestParameterStruct_unsharpMask bestParaUM_red = imaProcessingSuperFunction.getBestParaUnsMas_red();
	bestParaUM_red.exportAsTXTfile(locationFiltering, "bestParaUM_red", true);

	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_flower, simImaMatFlowerWithNoise, filteredIma_final, paraUM_blue.getCompareInPercent());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_SharpImage_UM_DE_WD", "improvement_SharpImage_UM_DE_WD: ", improvement, true);


	return true;
}
bool testDGaO2021::E3_improveImageQuality_AllPossibleSequences_refImage_UM()
{
	// *** load objects *** //
	std::string loactionFlower = "../images/color/testImaSim_test12";
	cv::Mat object_Flower = Images::loadAnImage_Color(loactionFlower, "flower2_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMatFlowerWithNoise = Images::loadAnImage_Color(mLocation_E3_leftToRight, "imageWithNoise");

	imageProcessing methodeImaProc = imageProcessing::unsharpMasking24;

	// *** parameter unsharp masking ***//
	// blue
	parameterUnsharpMasking paraUM_blue;
	paraUM_blue.setMinSigma(0.1);
	paraUM_blue.setMaxSigma(20.0);

	paraUM_blue.setMinThreshold(0.01);
	paraUM_blue.setMaxThreshold(5.0);

	paraUM_blue.setMinAmount(0.01);
	paraUM_blue.setMaxAmount(10.0);

	if (mDebugMode)
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



	// sharpness evaluation methode
	sharpnessEvalMethode tempShapEvalMethode = sharpnessEvalMethode::sharpImage;
	paraUM_blue.setSharpnessEvalMethode(tempShapEvalMethode);
	paraUM_green.setSharpnessEvalMethode(tempShapEvalMethode);
	paraUM_red.setSharpnessEvalMethode(tempShapEvalMethode);

	// set parameter
	ImaProcSuperFct imaProcessingSuperFunction;
	imaProcessingSuperFunction.setParameterUnsMas_blue(paraUM_blue);
	imaProcessingSuperFunction.setParameterUnsMas_green(paraUM_green);
	imaProcessingSuperFunction.setParameterUnsMas_red(paraUM_red);

	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_Flower, simImaMatFlowerWithNoise, methodeImaProc);
	real reinizializePrecent = 20.0;
	imaProcessingSuperFunction.reinitializeBestParaUnsMas(reinizializePrecent, paraUM_blue.getStepsSigma(), paraUM_blue.getStepsThreshold(), paraUM_blue.getStepsAmount());
	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_Flower, simImaMatFlowerWithNoise, methodeImaProc);

	cv::Mat filteredIma_final = imaProcessingSuperFunction.getFilteredIma();
	std::string locationFiltering = "../tests/testDGaO2021/E3/leftToRight/filtering_SharpImage_UM";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E3_filteredIma_leftToRight_SharpImage_UM", "png", filteredIma_final, paraUM_blue.getCompareInPercent());


	// save best para UM
	bestParameterStruct_unsharpMask bestParaUM_blue = imaProcessingSuperFunction.getBestParaUnsMas_blue();
	bestParaUM_blue.exportAsTXTfile(locationFiltering, "bestParaUM_blue", true);
	bestParameterStruct_unsharpMask bestParaUM_green = imaProcessingSuperFunction.getBestParaUnsMas_green();
	bestParaUM_green.exportAsTXTfile(locationFiltering, "bestParaUM_green", true);
	bestParameterStruct_unsharpMask bestParaUM_red = imaProcessingSuperFunction.getBestParaUnsMas_red();
	bestParaUM_red.exportAsTXTfile(locationFiltering, "bestParaUM_red", true);

	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_Flower, simImaMatFlowerWithNoise, filteredIma_final, paraUM_blue.getCompareInPercent());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_SharpImage_UM", "improvement_SharpImage_UM: ", improvement, true);


	return true;
}
bool testDGaO2021::E3_improveImageQuality_AllPossibleSequences_refImage_DE()
{
	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_flower = Images::loadAnImage_Color(loactionObject, "flower2_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMat_elefant = Images::loadAnImage_Color(mLocation_E3_leftToRight, "imageWithNoise");

	imageProcessing methodeImaProc = imageProcessing::detailEnhance24;

	// *** parameter DE 
	parameterDetailEnhancement paraDE;
	paraDE.setMinSigma_r(0.001);
	paraDE.setMaxSigma_r(100.0);

	paraDE.setMinSigma_s(1.0);
	paraDE.setMaxSigma_s(100.0);

	paraDE.setPercentCompare(0.0);

	if (mDebugMode)
	{
		paraDE.setStepsSigma_r(20.0);
		paraDE.setStepsSigma_s(20.0);
	}
	else
	{
		paraDE.setStepsSigma_r(200.0);
		paraDE.setStepsSigma_s(200.0);
	}


	// sharpness evaluation methode
	sharpnessEvalMethode tempShapEvalMethode = sharpnessEvalMethode::sharpImage;
	paraDE.setSharpnessEvalMethode(tempShapEvalMethode);

	// set parameter
	ImaProcSuperFct imaProcessingSuperFunction;
	imaProcessingSuperFunction.setParameterDetEnh(paraDE);


	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower, simImaMat_elefant, methodeImaProc);
	real reinizializePrecent = 20.0;
	imaProcessingSuperFunction.reinitializeBestParaDetEng(reinizializePrecent, paraDE.getStepsSigma_r(), paraDE.getStepsSigma_s());
	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower, simImaMat_elefant, methodeImaProc);


	cv::Mat filteredIma_final = imaProcessingSuperFunction.getFilteredIma();
	std::string locationFiltering = "../tests/testDGaO2021/E3/leftToRight/filtering_SharpImage_DE";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E3_filteredIma_leftToRight_SharpImage_DE", "png", filteredIma_final, paraDE.getPercentCompare());

	// save best para DE
	bestParameterStruct_detailEnhance bestParaDE = imaProcessingSuperFunction.getBestParaDetEnh();
	bestParaDE.exportAsTXTfile(locationFiltering, "bestParaDE", true);

	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_flower, simImaMat_elefant, filteredIma_final, paraDE.getPercentCompare());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_SharpImage_DE", "improvement_SharpImage_DE: ", improvement, true);


	return true;
}
bool testDGaO2021::E3_improveImageQuality_AllPossibleSequences_refImage_WD()
{
	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_flower = Images::loadAnImage_Color(loactionObject, "flower2_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMat_flower = Images::loadAnImage_Color(mLocation_E3_leftToRight, "imageWithNoise");

	imageProcessing methodeImaProc = imageProcessing::wienerFilter24;

	// *** parameter wiener filter *** 
	// *** parameter blue *** 
	parameterImaImprove_WD paraWD_blue{};
	paraWD_blue.setMinSNR(0.1);
	paraWD_blue.setMaxSNR(200.0);
	paraWD_blue.setMinSigmaXY(0.1);
	paraWD_blue.setMaxSigmaXY(5.0);
	paraWD_blue.setKernelSizeHeightAndWidth(30);
	paraWD_blue.setCompareInPercent(0.0);

	if (mDebugMode)
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
	paraWD_blue.setSharpnessEvalMethode(tempShapEvalMethode);
	paraWD_green.setSharpnessEvalMethode(tempShapEvalMethode);
	paraWD_red.setSharpnessEvalMethode(tempShapEvalMethode);

	// set parameter
	ImaProcSuperFct imaProcessingSuperFunction;
	imaProcessingSuperFunction.setParameterWD_blue(paraWD_blue);
	imaProcessingSuperFunction.setParameterWD_green(paraWD_green);
	imaProcessingSuperFunction.setParameterWD_red(paraWD_red);


	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower, simImaMat_flower, methodeImaProc);
	real reinizializePrecent = 20.0;
	imaProcessingSuperFunction.reinitializeBestParaWD(reinizializePrecent, paraWD_blue.getStepsSNR(), paraWD_blue.getStepsSigmaXY());
	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower, simImaMat_flower, methodeImaProc);

	cv::Mat filteredIma_final = imaProcessingSuperFunction.getFilteredIma();
	std::string locationFiltering = "../tests/testDGaO2021/E3/leftToRight/filtering_SharpImage_WD";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E3_filteredIma_leftToRight_SharpImage_WD", "png", filteredIma_final, paraWD_blue.getCompareInPercent());



	// save best parameters WD
	saveBestParameterWD bestPara_blue = imaProcessingSuperFunction.getBestParaWD_blue();
	bestPara_blue.exportAsTXTfile(locationFiltering, "bestParaWD_blue", true);
	saveBestParameterWD bestPara_green = imaProcessingSuperFunction.getBestParaWD_green();
	bestPara_green.exportAsTXTfile(locationFiltering, "bestParaWD_green", true);
	saveBestParameterWD bestPara_red = imaProcessingSuperFunction.getBestParaWD_red();
	bestPara_red.exportAsTXTfile(locationFiltering, "bestParaWD_red", true);



	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_flower, simImaMat_flower, filteredIma_final, paraWD_blue.getCompareInPercent());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_SharpImag_WD", "improvement_SharpImage_WD: ", improvement, true);

	return true;
}
// filtering blur and noise
bool testDGaO2021::E3_improveImageQuality_AllPossibleSequences_BlurAndNoise_UM_DE_WD()
{
	// *** load objects *** //
	std::string loactionFlower = "../images/color/testImaSim_test12";
	cv::Mat object_flower = Images::loadAnImage_Color(loactionFlower, "flower2_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMatFlowerWithNoise = Images::loadAnImage_Color(mLocation_E3_leftToRight, "imageWithNoise");

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

	if (mDebugMode)
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

	if (mDebugMode)
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

	if (mDebugMode)
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
	sharpnessEvalMethode tempShapEvalMethode = sharpnessEvalMethode::BlurAndNoise;
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


	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower, simImaMatFlowerWithNoise, methodeImaProc);


	cv::Mat filteredIma_final = imaProcessingSuperFunction.getAllFilteredImages_UM_DE_WD()[2];
	std::string locationFiltering = "../tests/testDGaO2021/E3/leftToRight/filtering_BlurAndNoise_UM_DE_WD";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E3_filteredIma_leftToRight_BlurAndNoise_UM_DE_WD", "png", filteredIma_final, paraWD_blue.getCompareInPercent());

	// save best parameters WD
	saveBestParameterWD bestPara_blue = imaProcessingSuperFunction.getBestParaWD_blue();
	bestPara_blue.exportAsTXTfile(locationFiltering, "bestParaWD_blue", true);
	saveBestParameterWD bestPara_green = imaProcessingSuperFunction.getBestParaWD_green();
	bestPara_green.exportAsTXTfile(locationFiltering, "bestParaWD_green", true);
	saveBestParameterWD bestPara_red = imaProcessingSuperFunction.getBestParaWD_red();
	bestPara_red.exportAsTXTfile(locationFiltering, "bestParaWD_red", true);

	// save best para DE
	bestParameterStruct_detailEnhance bestParaDE = imaProcessingSuperFunction.getBestParaDetEnh();
	bestParaDE.exportAsTXTfile(locationFiltering, "bestParaDE", true);

	// save best para UM
	bestParameterStruct_unsharpMask bestParaUM_blue = imaProcessingSuperFunction.getBestParaUnsMas_blue();
	bestParaUM_blue.exportAsTXTfile(locationFiltering, "bestParaUM_blue", true);
	bestParameterStruct_unsharpMask bestParaUM_green = imaProcessingSuperFunction.getBestParaUnsMas_green();
	bestParaUM_green.exportAsTXTfile(locationFiltering, "bestParaUM_green", true);
	bestParameterStruct_unsharpMask bestParaUM_red = imaProcessingSuperFunction.getBestParaUnsMas_red();
	bestParaUM_red.exportAsTXTfile(locationFiltering, "bestParaUM_red", true);

	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_flower, simImaMatFlowerWithNoise, filteredIma_final, paraUM_blue.getCompareInPercent());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_BlurAndNoise_UM_DE_WD", "improvement_BlurAndNoise_UM_DE_WD: ", improvement, true);


	return true;
}
bool testDGaO2021::E3_improveImageQuality_AllPossibleSequences_BlurAndNois_UM()
{
	// *** load objects *** //
	std::string loactionFlower = "../images/color/testImaSim_test12";
	cv::Mat object_Flower = Images::loadAnImage_Color(loactionFlower, "flower2_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMatFlowerWithNoise = Images::loadAnImage_Color(mLocation_E3_leftToRight, "imageWithNoise");

	imageProcessing methodeImaProc = imageProcessing::unsharpMasking24;

	// *** parameter unsharp masking ***//
	// blue
	parameterUnsharpMasking paraUM_blue;
	paraUM_blue.setMinSigma(0.1);
	paraUM_blue.setMaxSigma(20.0);

	paraUM_blue.setMinThreshold(0.01);
	paraUM_blue.setMaxThreshold(5.0);

	paraUM_blue.setMinAmount(0.01);
	paraUM_blue.setMaxAmount(10.0);

	if (mDebugMode)
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



	// sharpness evaluation methode
	sharpnessEvalMethode tempShapEvalMethode = sharpnessEvalMethode::BlurAndNoise;
	paraUM_blue.setSharpnessEvalMethode(tempShapEvalMethode);
	paraUM_green.setSharpnessEvalMethode(tempShapEvalMethode);
	paraUM_red.setSharpnessEvalMethode(tempShapEvalMethode);

	// set parameter
	ImaProcSuperFct imaProcessingSuperFunction;
	imaProcessingSuperFunction.setParameterUnsMas_blue(paraUM_blue);
	imaProcessingSuperFunction.setParameterUnsMas_green(paraUM_green);
	imaProcessingSuperFunction.setParameterUnsMas_red(paraUM_red);

	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_Flower, simImaMatFlowerWithNoise, methodeImaProc);
	real reinizializePrecent = 20.0;
	imaProcessingSuperFunction.reinitializeBestParaUnsMas(reinizializePrecent, paraUM_blue.getStepsSigma(), paraUM_blue.getStepsThreshold(), paraUM_blue.getStepsAmount());
	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_Flower, simImaMatFlowerWithNoise, methodeImaProc);

	cv::Mat filteredIma_final = imaProcessingSuperFunction.getFilteredIma();
	std::string locationFiltering = "../tests/testDGaO2021/E3/leftToRight/filtering_BlurAndNoise_UM";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E3_filteredIma_leftToRight_BlurAndNoise_UM", "png", filteredIma_final, paraUM_blue.getCompareInPercent());


	// save best para UM
	bestParameterStruct_unsharpMask bestParaUM_blue = imaProcessingSuperFunction.getBestParaUnsMas_blue();
	bestParaUM_blue.exportAsTXTfile(locationFiltering, "bestParaUM_blue", true);
	bestParameterStruct_unsharpMask bestParaUM_green = imaProcessingSuperFunction.getBestParaUnsMas_green();
	bestParaUM_green.exportAsTXTfile(locationFiltering, "bestParaUM_green", true);
	bestParameterStruct_unsharpMask bestParaUM_red = imaProcessingSuperFunction.getBestParaUnsMas_red();
	bestParaUM_red.exportAsTXTfile(locationFiltering, "bestParaUM_red", true);

	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_Flower, simImaMatFlowerWithNoise, filteredIma_final, paraUM_blue.getCompareInPercent());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_BlurAndNoise_UM", "improvement_BlurAndNoise_UM: ", improvement, true);


	return true;

}
bool testDGaO2021::E3_improveImageQuality_AllPossibleSequences_BlurAndNois_DE()
{
	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_flower = Images::loadAnImage_Color(loactionObject, "flower2_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMat_elefant = Images::loadAnImage_Color(mLocation_E3_leftToRight, "imageWithNoise");

	imageProcessing methodeImaProc = imageProcessing::detailEnhance24;

	// *** parameter DE 
	parameterDetailEnhancement paraDE;
	paraDE.setMinSigma_r(0.001);
	paraDE.setMaxSigma_r(100.0);

	paraDE.setMinSigma_s(1.0);
	paraDE.setMaxSigma_s(100.0);

	paraDE.setPercentCompare(0.0);

	if (mDebugMode)
	{
		paraDE.setStepsSigma_r(20.0);
		paraDE.setStepsSigma_s(20.0);
	}
	else
	{
		paraDE.setStepsSigma_r(200.0);
		paraDE.setStepsSigma_s(200.0);
	}


	// sharpness evaluation methode
	sharpnessEvalMethode tempShapEvalMethode = sharpnessEvalMethode::BlurAndNoise;
	paraDE.setSharpnessEvalMethode(tempShapEvalMethode);

	// set parameter
	ImaProcSuperFct imaProcessingSuperFunction;
	imaProcessingSuperFunction.setParameterDetEnh(paraDE);


	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower, simImaMat_elefant, methodeImaProc);
	real reinizializePrecent = 20.0;
	imaProcessingSuperFunction.reinitializeBestParaDetEng(reinizializePrecent, paraDE.getStepsSigma_r(), paraDE.getStepsSigma_s());
	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower, simImaMat_elefant, methodeImaProc);


	cv::Mat filteredIma_final = imaProcessingSuperFunction.getFilteredIma();
	std::string locationFiltering = "../tests/testDGaO2021/E3/leftToRight/filtering_BlurAndNoise_DE";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E3_filteredIma_leftToRight_BlurAndNoisev_DE", "png", filteredIma_final, paraDE.getPercentCompare());

	// save best para DE
	bestParameterStruct_detailEnhance bestParaDE = imaProcessingSuperFunction.getBestParaDetEnh();
	bestParaDE.exportAsTXTfile(locationFiltering, "bestParaDE", true);

	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_flower, simImaMat_elefant, filteredIma_final, paraDE.getPercentCompare());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_BlurAndNoise_DE", "improvement_BlurAndNoise_DE: ", improvement, true);


	return true;

}
bool testDGaO2021::E3_improveImageQuality_AllPossibleSequences_BlurAndNois_WD()
{
	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_flower = Images::loadAnImage_Color(loactionObject, "flower2_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMat_flower = Images::loadAnImage_Color(mLocation_E3_leftToRight, "imageWithNoise");

	imageProcessing methodeImaProc = imageProcessing::wienerFilter24;

	// *** parameter wiener filter *** 
	// *** parameter blue *** 
	parameterImaImprove_WD paraWD_blue{};
	paraWD_blue.setMinSNR(0.1);
	paraWD_blue.setMaxSNR(200.0);
	paraWD_blue.setMinSigmaXY(0.1);
	paraWD_blue.setMaxSigmaXY(5.0);
	paraWD_blue.setKernelSizeHeightAndWidth(30);
	paraWD_blue.setCompareInPercent(0.0);

	if (mDebugMode)
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
	sharpnessEvalMethode tempShapEvalMethode = sharpnessEvalMethode::BlurAndNoise;
	paraWD_blue.setSharpnessEvalMethode(tempShapEvalMethode);
	paraWD_green.setSharpnessEvalMethode(tempShapEvalMethode);
	paraWD_red.setSharpnessEvalMethode(tempShapEvalMethode);

	// set parameter
	ImaProcSuperFct imaProcessingSuperFunction;
	imaProcessingSuperFunction.setParameterWD_blue(paraWD_blue);
	imaProcessingSuperFunction.setParameterWD_green(paraWD_green);
	imaProcessingSuperFunction.setParameterWD_red(paraWD_red);


	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower, simImaMat_flower, methodeImaProc);
	real reinizializePrecent = 20.0;
	imaProcessingSuperFunction.reinitializeBestParaWD(reinizializePrecent, paraWD_blue.getStepsSNR(), paraWD_blue.getStepsSigmaXY());
	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower, simImaMat_flower, methodeImaProc);

	cv::Mat filteredIma_final = imaProcessingSuperFunction.getFilteredIma();
	std::string locationFiltering = "../tests/testDGaO2021/E3/leftToRight/filtering_BlurAndNoise_WD";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E3_filteredIma_leftToRight_BlurAndNoise_WD", "png", filteredIma_final, paraWD_blue.getCompareInPercent());



	// save best parameters WD
	saveBestParameterWD bestPara_blue = imaProcessingSuperFunction.getBestParaWD_blue();
	bestPara_blue.exportAsTXTfile(locationFiltering, "bestParaWD_blue", true);
	saveBestParameterWD bestPara_green = imaProcessingSuperFunction.getBestParaWD_green();
	bestPara_green.exportAsTXTfile(locationFiltering, "bestParaWD_green", true);
	saveBestParameterWD bestPara_red = imaProcessingSuperFunction.getBestParaWD_red();
	bestPara_red.exportAsTXTfile(locationFiltering, "bestParaWD_red", true);



	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_flower, simImaMat_flower, filteredIma_final, paraWD_blue.getCompareInPercent());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_BlurAndNoise_WD", "improvement_BlurAndNoise_WD: ", improvement, true);

	return true;
}


// *** *** //

bool testDGaO2021::checkE21_fromStatLensRepl_threeLensSys()
{
	std::vector<bool> workTheSystem;

	//bool checkLoadBestRepE21 = loadBestReplaceSystemE21_mono();
	//workTheSystem.push_back(checkLoadBestRepE21);
	//
	//bool checkOptiThickAirSpace_poly = optimizeThicknessesAirSpace_poly();
	//workTheSystem.push_back(checkOptiThickAirSpace_poly);

	bool checkLoadReplacedSysE21_poly = loadReplacedSysE21_poly();;
	workTheSystem.push_back(checkLoadReplacedSysE21_poly);
	
	bool chceckDoImageSimulationE21_poly = doImageSimulationE21_poly();
	workTheSystem.push_back(chceckDoImageSimulationE21_poly);

	// filtering sharp image
	bool check_refImage_UM_DE_WD = E21_improveImageQuality_AllPossibleSequences_refImage_UM_DE_WD();
	bool check_refImage_UM = E21_improveImageQuality_AllPossibleSequences_refImage_UM();
	bool check_refImage_DE = E21_improveImageQuality_AllPossibleSequences_refImage_DE();
	bool check_refImage_WD = E21_improveImageQuality_AllPossibleSequences_refImage_WD();

	// filtering blur and noise
	bool check_BlurAndNoise_UM_DE_WD = E21_improveImageQuality_AllPossibleSequences_BlurAndNoise_UM_DE_WD();
	bool check_BlurAndNoise_UM = E21_improveImageQuality_AllPossibleSequences_BlurAndNois_UM();
	bool check_BlurAndNoise_DE = E21_improveImageQuality_AllPossibleSequences_BlurAndNois_DE();
	bool check_BlurAndNoise_WD = E21_improveImageQuality_AllPossibleSequences_BlurAndNois_WD();


	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

// *** E21 ***
bool testDGaO2021::loadBestReplaceSystemE21_mono()
{

	std::vector<bool> workTheSystem;
	std::string example = "E21";

	SphericalElement S0(/*radius*/ 217.3623, /*semi height*/ 12.7, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());
	SphericalElement S1(/*radius*/ 43.36338, /*semi height*/ 12.7, /*point*/{ 0.0,0.0,84.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF6_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S2(/*radius*/ 51.98263, /*semi height*/ 12.7, /*point*/{ 0.0,0.0,92.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	ApertureStopElement S3(/* semi height*/ 5.0, /*point*/{ 0.0,0.0,97.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S4(/*radius*/ 34.81, /*semi height*/ 15.0, /*point*/{ 0.0,0.0,102.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 22.12, /*semi height*/ 15.0, /*point*/{ 0.0,0.0,113.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF10_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S6(/*radius*/ 203.48, /*semi height*/ 15.0, /*point*/{ 0.0,0.0,115.2 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF10_S1());

	SphericalElement S7(/*radius*/ 129.94, /*semi height*/ 12.7, /*point*/{ 0.0,0.0,125.2 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S8(/*radius*/ 44.64, /*semi height*/ 12.7, /*point*/{ 0.0,0.0,127.7 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S9(/*radius*/ 61.47, /*semi height*/ 12.7, /*point*/{ 0.0,0.0,133.7 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S10(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,151.6078},  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());


	// **********************************
	// set parameter variable
	// thicknesses
	S2.setParameterPointZ(/*min value*/ 1.0, /*max value*/ 50.0, 0.0, typeModifierVariable);
	S3.setParameterPointZ(/*min value*/ 1.0, /*max value*/ 50.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/ 1.0, /*max value*/ 50.0, 0.0, typeModifierVariable);
	S9.setParameterPointZ(/*min value*/ 1.0, /*max value*/ 50.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr};
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mAbsorb.clone() };

	//	build optical system
	mReplacedOpticalSystemEle_E21_allSequences_mono.fillPosAndElementAndInteraction(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(mReplacedOpticalSystemEle_E21_allSequences_mono, mWave587d);
	// save the start system
	inportExportData::saveOpticalSystemAsTXT(mReplacedOpticalSystemEle_E21_allSequences_mono, mWave587d, mLocationE21, "E21_replaced_mono");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(mReplacedOpticalSystemEle_E21_allSequences_mono);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 8.430, 6.867, 9.824 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(mReplacedOpticalSystemEle_E21_allSequences_mono, mField_E21_vec, mWave587d, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);


	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::optimizeThicknessesAirSpace_poly()
{
	std::vector<bool> workTheSystem;

	OpticalSystemElement initalOpticalSystemEle1 = mReplacedOpticalSystemEle_E21_allSequences_mono.getDeepCopyOptSysEle();
	OpticalSystemElement initalOpticalSystemEle2 = mReplacedOpticalSystemEle_E21_allSequences_mono.getDeepCopyOptSysEle();

	// optimize optical system3
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.68149);
	tarCarP.setTargetMag(-0.451986);

	DLS_multiThreads_12 DLS12(/*optSysEle*/ initalOpticalSystemEle1,/*fields*/ mField_E21_vec, /*wavelength*/ mWavelength_FdV_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ tarCarP, /*default DLS*/ mDefaulParaDLS);
	mReplacedOpticalSystemEle_E21_allSequences_poly = DLS12.DLS_optimisation_multiThreads_12_obj();
	inportExportData::saveOpticalSystemAsTXT(mReplacedOpticalSystemEle_E21_allSequences_poly, mWave587d, mLocationE21, "E21_replaced_poly_DLS_12");

	// check optimized system
	std::vector<real> rmsVecMono = oftenUse::getRMSoptSysHLT(mReplacedOpticalSystemEle_E21_allSequences_mono, mField_E21_vec, mWavelength_FdV_vec, mRings, mArms);
	std::vector<real> rmsVecPoly = oftenUse::getRMSoptSysHLT(mReplacedOpticalSystemEle_E21_allSequences_poly, mField_E21_vec, mWavelength_FdV_vec, mRings, mArms);

	real sumRMS_Mono = oftenUse::sum(rmsVecMono);
	real sumRMS_Ploy = oftenUse::sum(rmsVecPoly);

	bool checkOptimization = sumRMS_Mono > sumRMS_Ploy;
	workTheSystem.push_back(checkOptimization);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;

}

bool testDGaO2021::loadReplacedSysE21_poly()
{
	std::vector<bool> workTheSystem;
	std::string example = "E21";

	SphericalElement S0(/*radius*/ 217.3623, /*semi height*/ 12.7, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());
	SphericalElement S1(/*radius*/ 43.36338, /*semi height*/ 12.7, /*point*/{ 0.0,0.0,84.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF6_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S2(/*radius*/ 51.98263, /*semi height*/ 12.7, /*point*/{ 0.0,0.0,92.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	ApertureStopElement S3(/* semi height*/ 5.0, /*point*/{ 0.0,0.0,108.3833 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S4(/*radius*/ 34.81, /*semi height*/ 15.0, /*point*/{ 0.0,0.0,114.0851 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 22.12, /*semi height*/ 15.0, /*point*/{ 0.0,0.0,125.0851 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF10_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S6(/*radius*/ 203.48, /*semi height*/ 15.0, /*point*/{ 0.0,0.0,127.2851 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF10_S1());

	SphericalElement S7(/*radius*/ 129.94, /*semi height*/ 12.7, /*point*/{ 0.0,0.0,137.0228 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S8(/*radius*/ 44.64, /*semi height*/ 12.7, /*point*/{ 0.0,0.0,139.5228 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S9(/*radius*/ 61.47, /*semi height*/ 12.7, /*point*/{ 0.0,0.0,145.5228 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S10(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,163.5844 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());


	// **********************************
	// set parameter variable
	// thicknesses
	S2.setParameterPointZ(/*min value*/ 1.0, /*max value*/ 50.0, 0.0, typeModifierVariable);
	S3.setParameterPointZ(/*min value*/ 1.0, /*max value*/ 50.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/ 1.0, /*max value*/ 50.0, 0.0, typeModifierVariable);
	S9.setParameterPointZ(/*min value*/ 1.0, /*max value*/ 50.0, 0.0, typeModifierVariable);
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
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mAbsorb.clone() };

	//	build optical system
	mReplacedOpticalSystemEle_E21_allSequences_poly.fillPosAndElementAndInteraction(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(mReplacedOpticalSystemEle_E21_allSequences_poly, mWave587d);
	// save the start system
	inportExportData::saveOpticalSystemAsTXT(mReplacedOpticalSystemEle_E21_allSequences_poly, mWave587d, mLocationE21, "E21_replaced_opti_poly");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(mReplacedOpticalSystemEle_E21_allSequences_poly);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 7.781, 9.588, 14.502 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(mReplacedOpticalSystemEle_E21_allSequences_poly, mField_E21_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);


	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}


bool testDGaO2021::doImageSimulationE21_poly()
{
	std::vector<bool> workTheSystem;

	if (mReplacedOpticalSystemEle_E21_allSequences_poly.getPosAndElement().size() < 1)
	{
		bool checkE21_replacedOpticalSystemEle_E21_allSequences_poly = loadReplacedSysE21_poly();
		workTheSystem.push_back(checkE21_replacedOpticalSystemEle_E21_allSequences_poly);
	}

	loadParaImaSim parameterImaSim{};
	parameterImaSim.setWavelengthBlue(486.1327);
	parameterImaSim.setWavelengthGreen(587.5818);
	parameterImaSim.setWavelengthRed(656.2725);
	parameterImaSim.setRayDensity(30);

	//light
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	light.setJonesVector({ 1.0,1.0,1.0,1.0 });
	light.setTypeLight(typeLight::typeLightRay);

	parameterImaSim.setLight(light);
	parameterImaSim.setSizeMatrixToSaveOPD(64);
	parameterImaSim.setInfOrObj(objectPoint_inf_obj::obj);
	parameterImaSim.setRowColResizeOPD(128);
	parameterImaSim.setSampling_x(11);
	parameterImaSim.setSampling_y(11);
	parameterImaSim.setSemiHeightObj(4.0);
	parameterImaSim.setSemiWeidthObj(4.0);
	parameterImaSim.setPosition_Z_Object(0.0);
	parameterImaSim.setUpSamplePSF(true);
	parameterImaSim.setResizeOPD_linear(true);
	parameterImaSim.setPaddingFactorPSF(1);
	// there is no distortion in the image
	parameterImaSim.setCalcDistortion(false);
	parameterImaSim.setSamplingDistortionHeight(450);
	parameterImaSim.setSamplingDistortionWidth(450);

	// load object
	cv::Mat flower3 = cv::imread("../images/color/testImaSim_test12/flower3_900x900.png", CV_LOAD_IMAGE_COLOR);

	ImageSimulationFunctions imaSim;
	imaSim.imageSimulationSuperFct(/*optical System Element*/ mReplacedOpticalSystemEle_E21_allSequences_poly, /*object*/ flower3, /*parameter*/ parameterImaSim);
	
	cv::Mat simulatedIma = imaSim.getSimulatedImage_initialSize();
	// just for debugging
	// Images::showImage_inputReal_normTheImage("simulatedIma_E2_ReplaceLeftToRight", simulatedIma);
	// save the simulate images
	Images::saveImage_normalized(mLocationE21, "simulatedIma_E21_allPosSequences", "png", simulatedIma);
	

	// *** noise *** //
	Noise noiseE21;
	float wave587d = 587.5618;
	cv::Mat simImaflower3 = cv::imread("../tests/testDGaO2021/E21/simulatedIma_E21_allPosSequences.png", CV_LOAD_IMAGE_COLOR);
	cameraParameterStruct camPara_VistecEco655 = oftenUse::getCamPara_VistecEco655();
	std::vector<float> wavelength{ wave587d, wave587d, wave587d };
	noiseE21.noiseSuperFunction_colorImage(simImaflower3, camPara_VistecEco655, 21, 0.002,/*Frage: welcher Wert passt hier*/ 0.035, wavelength, true);
	
	cv::Mat imageWithNoise = noiseE21.getImageWithNoise_Color_uint8_normed();
	// save the image
	Images::saveImage_normalized(mLocationE21, "imageWithNoise", "png", imageWithNoise);
	// make noise visable
	cv::Mat noiseImage = simImaflower3 - imageWithNoise;
	cv::normalize(noiseImage, noiseImage, 0, 255, cv::NORM_MINMAX);
	Images::saveImage_normalized(mLocationE21, "noiseVisable_normalized", "png", noiseImage);
	Images::saveImage_NOTnormalized(mLocationE21, "noiseVisable_NOTnormalized", "png", noiseImage);
	// *** noise *** //


	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::E21_improveImageQuality_AllPossibleSequences_refImage_UM_DE_WD()
{
	// *** load objects *** //
	std::string loactionFlower = "../images/color/testImaSim_test12";
	cv::Mat object_flower = Images::loadAnImage_Color(loactionFlower, "flower3_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMatFlowerWithNoise = Images::loadAnImage_Color(mLocationE21, "imageWithNoise");

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

	if (mDebugMode)
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

	if (mDebugMode)
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

	if (mDebugMode)
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


	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower, simImaMatFlowerWithNoise, methodeImaProc);


	cv::Mat filteredIma_final = imaProcessingSuperFunction.getAllFilteredImages_UM_DE_WD()[2];
	std::string locationFiltering = "../tests/testDGaO2021/E21/filtering_SharpImage_UM_DE_WD";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E21_filteredIma_allSequnces_SharpImage_UM_DE_WD", "png", filteredIma_final, paraWD_blue.getCompareInPercent());

	// save best parameters WD
	saveBestParameterWD bestPara_blue = imaProcessingSuperFunction.getBestParaWD_blue();
	bestPara_blue.exportAsTXTfile(locationFiltering, "bestParaWD_blue", true);
	saveBestParameterWD bestPara_green = imaProcessingSuperFunction.getBestParaWD_green();
	bestPara_green.exportAsTXTfile(locationFiltering, "bestParaWD_green", true);
	saveBestParameterWD bestPara_red = imaProcessingSuperFunction.getBestParaWD_red();
	bestPara_red.exportAsTXTfile(locationFiltering, "bestParaWD_red", true);

	// save best para DE
	bestParameterStruct_detailEnhance bestParaDE = imaProcessingSuperFunction.getBestParaDetEnh();
	bestParaDE.exportAsTXTfile(locationFiltering, "bestParaDE", true);

	// save best para UM
	bestParameterStruct_unsharpMask bestParaUM_blue = imaProcessingSuperFunction.getBestParaUnsMas_blue();
	bestParaUM_blue.exportAsTXTfile(locationFiltering, "bestParaUM_blue", true);
	bestParameterStruct_unsharpMask bestParaUM_green = imaProcessingSuperFunction.getBestParaUnsMas_green();
	bestParaUM_green.exportAsTXTfile(locationFiltering, "bestParaUM_green", true);
	bestParameterStruct_unsharpMask bestParaUM_red = imaProcessingSuperFunction.getBestParaUnsMas_red();
	bestParaUM_red.exportAsTXTfile(locationFiltering, "bestParaUM_red", true);

	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_flower, simImaMatFlowerWithNoise, filteredIma_final, paraUM_blue.getCompareInPercent());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_SharpImage_UM_DE_WD", "improvement_SharpImage_UM_DE_WD: ", improvement, true);


	return true;
}

bool testDGaO2021::E21_improveImageQuality_AllPossibleSequences_refImage_UM()
{
	// *** load objects *** //
	std::string loactionFlower = "../images/color/testImaSim_test12";
	cv::Mat object_Flower = Images::loadAnImage_Color(loactionFlower, "flower3_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMatFlowerWithNoise = Images::loadAnImage_Color(mLocationE21, "imageWithNoise");

	imageProcessing methodeImaProc = imageProcessing::unsharpMasking24;

	// *** parameter unsharp masking ***//
	// blue
	parameterUnsharpMasking paraUM_blue;
	paraUM_blue.setMinSigma(0.1);
	paraUM_blue.setMaxSigma(20.0);

	paraUM_blue.setMinThreshold(0.01);
	paraUM_blue.setMaxThreshold(5.0);

	paraUM_blue.setMinAmount(0.01);
	paraUM_blue.setMaxAmount(10.0);

	if (mDebugMode)
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



	// sharpness evaluation methode
	sharpnessEvalMethode tempShapEvalMethode = sharpnessEvalMethode::sharpImage;
	paraUM_blue.setSharpnessEvalMethode(tempShapEvalMethode);
	paraUM_green.setSharpnessEvalMethode(tempShapEvalMethode);
	paraUM_red.setSharpnessEvalMethode(tempShapEvalMethode);

	// set parameter
	ImaProcSuperFct imaProcessingSuperFunction;
	imaProcessingSuperFunction.setParameterUnsMas_blue(paraUM_blue);
	imaProcessingSuperFunction.setParameterUnsMas_green(paraUM_green);
	imaProcessingSuperFunction.setParameterUnsMas_red(paraUM_red);

	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_Flower, simImaMatFlowerWithNoise, methodeImaProc);
	real reinizializePrecent = 20.0;
	imaProcessingSuperFunction.reinitializeBestParaUnsMas(reinizializePrecent, paraUM_blue.getStepsSigma(), paraUM_blue.getStepsThreshold(), paraUM_blue.getStepsAmount());
	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_Flower, simImaMatFlowerWithNoise, methodeImaProc);

	cv::Mat filteredIma_final = imaProcessingSuperFunction.getFilteredIma();
	std::string locationFiltering = "../tests/testDGaO2021/E21/filtering_SharpImage_UM";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E21_filteredIma_allSequnces_SharpImage_UM", "png", filteredIma_final, paraUM_blue.getCompareInPercent());


	// save best para UM
	bestParameterStruct_unsharpMask bestParaUM_blue = imaProcessingSuperFunction.getBestParaUnsMas_blue();
	bestParaUM_blue.exportAsTXTfile(locationFiltering, "bestParaUM_blue", true);
	bestParameterStruct_unsharpMask bestParaUM_green = imaProcessingSuperFunction.getBestParaUnsMas_green();
	bestParaUM_green.exportAsTXTfile(locationFiltering, "bestParaUM_green", true);
	bestParameterStruct_unsharpMask bestParaUM_red = imaProcessingSuperFunction.getBestParaUnsMas_red();
	bestParaUM_red.exportAsTXTfile(locationFiltering, "bestParaUM_red", true);

	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_Flower, simImaMatFlowerWithNoise, filteredIma_final, paraUM_blue.getCompareInPercent());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_SharpImage_UM", "improvement_SharpImage_UM: ", improvement, true);


	return true;
}
bool testDGaO2021::E21_improveImageQuality_AllPossibleSequences_refImage_DE()
{
	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_flower = Images::loadAnImage_Color(loactionObject, "flower3_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMat_elefant = Images::loadAnImage_Color(mLocationE21, "imageWithNoise");

	imageProcessing methodeImaProc = imageProcessing::detailEnhance24;

	// *** parameter DE 
	parameterDetailEnhancement paraDE;
	paraDE.setMinSigma_r(0.001);
	paraDE.setMaxSigma_r(100.0);

	paraDE.setMinSigma_s(1.0);
	paraDE.setMaxSigma_s(100.0);

	paraDE.setPercentCompare(0.0);

	if (mDebugMode)
	{
		paraDE.setStepsSigma_r(20.0);
		paraDE.setStepsSigma_s(20.0);
	}
	else
	{
		paraDE.setStepsSigma_r(200.0);
		paraDE.setStepsSigma_s(200.0);
	}


	// sharpness evaluation methode
	sharpnessEvalMethode tempShapEvalMethode = sharpnessEvalMethode::sharpImage;
	paraDE.setSharpnessEvalMethode(tempShapEvalMethode);

	// set parameter
	ImaProcSuperFct imaProcessingSuperFunction;
	imaProcessingSuperFunction.setParameterDetEnh(paraDE);


	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower, simImaMat_elefant, methodeImaProc);
	real reinizializePrecent = 20.0;
	imaProcessingSuperFunction.reinitializeBestParaDetEng(reinizializePrecent, paraDE.getStepsSigma_r(), paraDE.getStepsSigma_s());
	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower, simImaMat_elefant, methodeImaProc);


	cv::Mat filteredIma_final = imaProcessingSuperFunction.getFilteredIma();
	std::string locationFiltering = "../tests/testDGaO2021/E21/filtering_SharpImage_DE";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E21_filteredIma_allSequnces_SharpImage_DE", "png", filteredIma_final, paraDE.getPercentCompare());

	// save best para DE
	bestParameterStruct_detailEnhance bestParaDE = imaProcessingSuperFunction.getBestParaDetEnh();
	bestParaDE.exportAsTXTfile(locationFiltering, "bestParaDE", true);

	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_flower, simImaMat_elefant, filteredIma_final, paraDE.getPercentCompare());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_SharpImage_DE", "improvement_SharpImage_DE: ", improvement, true);


	return true;
}
bool testDGaO2021::E21_improveImageQuality_AllPossibleSequences_refImage_WD()
{
	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_flower = Images::loadAnImage_Color(loactionObject, "flower3_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMat_flower = Images::loadAnImage_Color(mLocationE21, "imageWithNoise");

	imageProcessing methodeImaProc = imageProcessing::wienerFilter24;

	// *** parameter wiener filter *** 
	// *** parameter blue *** 
	parameterImaImprove_WD paraWD_blue{};
	paraWD_blue.setMinSNR(0.1);
	paraWD_blue.setMaxSNR(200.0);
	paraWD_blue.setMinSigmaXY(0.1);
	paraWD_blue.setMaxSigmaXY(5.0);
	paraWD_blue.setKernelSizeHeightAndWidth(30);
	paraWD_blue.setCompareInPercent(0.0);

	if (mDebugMode)
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
	paraWD_blue.setSharpnessEvalMethode(tempShapEvalMethode);
	paraWD_green.setSharpnessEvalMethode(tempShapEvalMethode);
	paraWD_red.setSharpnessEvalMethode(tempShapEvalMethode);

	// set parameter
	ImaProcSuperFct imaProcessingSuperFunction;
	imaProcessingSuperFunction.setParameterWD_blue(paraWD_blue);
	imaProcessingSuperFunction.setParameterWD_green(paraWD_green);
	imaProcessingSuperFunction.setParameterWD_red(paraWD_red);


	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower, simImaMat_flower, methodeImaProc);
	real reinizializePrecent = 20.0;
	imaProcessingSuperFunction.reinitializeBestParaWD(reinizializePrecent, paraWD_blue.getStepsSNR(), paraWD_blue.getStepsSigmaXY());
	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower, simImaMat_flower, methodeImaProc);

	cv::Mat filteredIma_final = imaProcessingSuperFunction.getFilteredIma();
	std::string locationFiltering = "../tests/testDGaO2021/E21/filtering_SharpImage_WD";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E21_filteredIma_allSequnces_SharpImage_WD", "png", filteredIma_final, paraWD_blue.getCompareInPercent());



	// save best parameters WD
	saveBestParameterWD bestPara_blue = imaProcessingSuperFunction.getBestParaWD_blue();
	bestPara_blue.exportAsTXTfile(locationFiltering, "bestParaWD_blue", true);
	saveBestParameterWD bestPara_green = imaProcessingSuperFunction.getBestParaWD_green();
	bestPara_green.exportAsTXTfile(locationFiltering, "bestParaWD_green", true);
	saveBestParameterWD bestPara_red = imaProcessingSuperFunction.getBestParaWD_red();
	bestPara_red.exportAsTXTfile(locationFiltering, "bestParaWD_red", true);



	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_flower, simImaMat_flower, filteredIma_final, paraWD_blue.getCompareInPercent());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_SharpImag_WD", "improvement_SharpImage_WD: ", improvement, true);

	return true;
}
bool testDGaO2021::E21_improveImageQuality_AllPossibleSequences_BlurAndNoise_UM_DE_WD()
{
	// *** load objects *** //
	std::string loactionFlower = "../images/color/testImaSim_test12";
	cv::Mat object_flower = Images::loadAnImage_Color(loactionFlower, "flower3_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMatFlowerWithNoise = Images::loadAnImage_Color(mLocationE21, "imageWithNoise");

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

	if (mDebugMode)
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

	if (mDebugMode)
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

	if (mDebugMode)
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
	sharpnessEvalMethode tempShapEvalMethode = sharpnessEvalMethode::BlurAndNoise;
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


	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower, simImaMatFlowerWithNoise, methodeImaProc);


	cv::Mat filteredIma_final = imaProcessingSuperFunction.getAllFilteredImages_UM_DE_WD()[2];
	std::string locationFiltering = "../tests/testDGaO2021/E21/filtering_BlurAndNoise_UM_DE_WD";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E21_filteredIma_allSequnces_BlurAndNoise_UM_DE_WD", "png", filteredIma_final, paraWD_blue.getCompareInPercent());

	// save best parameters WD
	saveBestParameterWD bestPara_blue = imaProcessingSuperFunction.getBestParaWD_blue();
	bestPara_blue.exportAsTXTfile(locationFiltering, "bestParaWD_blue", true);
	saveBestParameterWD bestPara_green = imaProcessingSuperFunction.getBestParaWD_green();
	bestPara_green.exportAsTXTfile(locationFiltering, "bestParaWD_green", true);
	saveBestParameterWD bestPara_red = imaProcessingSuperFunction.getBestParaWD_red();
	bestPara_red.exportAsTXTfile(locationFiltering, "bestParaWD_red", true);

	// save best para DE
	bestParameterStruct_detailEnhance bestParaDE = imaProcessingSuperFunction.getBestParaDetEnh();
	bestParaDE.exportAsTXTfile(locationFiltering, "bestParaDE", true);

	// save best para UM
	bestParameterStruct_unsharpMask bestParaUM_blue = imaProcessingSuperFunction.getBestParaUnsMas_blue();
	bestParaUM_blue.exportAsTXTfile(locationFiltering, "bestParaUM_blue", true);
	bestParameterStruct_unsharpMask bestParaUM_green = imaProcessingSuperFunction.getBestParaUnsMas_green();
	bestParaUM_green.exportAsTXTfile(locationFiltering, "bestParaUM_green", true);
	bestParameterStruct_unsharpMask bestParaUM_red = imaProcessingSuperFunction.getBestParaUnsMas_red();
	bestParaUM_red.exportAsTXTfile(locationFiltering, "bestParaUM_red", true);

	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_flower, simImaMatFlowerWithNoise, filteredIma_final, paraUM_blue.getCompareInPercent());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_BlurAndNoise_UM_DE_WD", "improvement_BlurAndNoise_UM_DE_WD: ", improvement, true);


	return true;
}
bool testDGaO2021::E21_improveImageQuality_AllPossibleSequences_BlurAndNois_UM()
{
	// *** load objects *** //
	std::string loactionFlower = "../images/color/testImaSim_test12";
	cv::Mat object_Flower = Images::loadAnImage_Color(loactionFlower, "flower3_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMatFlowerWithNoise = Images::loadAnImage_Color(mLocationE21, "imageWithNoise");

	imageProcessing methodeImaProc = imageProcessing::unsharpMasking24;

	// *** parameter unsharp masking ***//
	// blue
	parameterUnsharpMasking paraUM_blue;
	paraUM_blue.setMinSigma(0.1);
	paraUM_blue.setMaxSigma(20.0);

	paraUM_blue.setMinThreshold(0.01);
	paraUM_blue.setMaxThreshold(5.0);

	paraUM_blue.setMinAmount(0.01);
	paraUM_blue.setMaxAmount(10.0);

	if (mDebugMode)
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



	// sharpness evaluation methode
	sharpnessEvalMethode tempShapEvalMethode = sharpnessEvalMethode::BlurAndNoise;
	paraUM_blue.setSharpnessEvalMethode(tempShapEvalMethode);
	paraUM_green.setSharpnessEvalMethode(tempShapEvalMethode);
	paraUM_red.setSharpnessEvalMethode(tempShapEvalMethode);

	// set parameter
	ImaProcSuperFct imaProcessingSuperFunction;
	imaProcessingSuperFunction.setParameterUnsMas_blue(paraUM_blue);
	imaProcessingSuperFunction.setParameterUnsMas_green(paraUM_green);
	imaProcessingSuperFunction.setParameterUnsMas_red(paraUM_red);

	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_Flower, simImaMatFlowerWithNoise, methodeImaProc);
	real reinizializePrecent = 20.0;
	imaProcessingSuperFunction.reinitializeBestParaUnsMas(reinizializePrecent, paraUM_blue.getStepsSigma(), paraUM_blue.getStepsThreshold(), paraUM_blue.getStepsAmount());
	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_Flower, simImaMatFlowerWithNoise, methodeImaProc);

	cv::Mat filteredIma_final = imaProcessingSuperFunction.getFilteredIma();
	std::string locationFiltering = "../tests/testDGaO2021/E21/filtering_BlurAndNoise_UM";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E21_filteredIma_allSequnces_BlurAndNoise_UM", "png", filteredIma_final, paraUM_blue.getCompareInPercent());


	// save best para UM
	bestParameterStruct_unsharpMask bestParaUM_blue = imaProcessingSuperFunction.getBestParaUnsMas_blue();
	bestParaUM_blue.exportAsTXTfile(locationFiltering, "bestParaUM_blue", true);
	bestParameterStruct_unsharpMask bestParaUM_green = imaProcessingSuperFunction.getBestParaUnsMas_green();
	bestParaUM_green.exportAsTXTfile(locationFiltering, "bestParaUM_green", true);
	bestParameterStruct_unsharpMask bestParaUM_red = imaProcessingSuperFunction.getBestParaUnsMas_red();
	bestParaUM_red.exportAsTXTfile(locationFiltering, "bestParaUM_red", true);

	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_Flower, simImaMatFlowerWithNoise, filteredIma_final, paraUM_blue.getCompareInPercent());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_BlurAndNoise_UM", "improvement_BlurAndNoise_UM: ", improvement, true);


	return true;
}
bool testDGaO2021::E21_improveImageQuality_AllPossibleSequences_BlurAndNois_DE()
{
	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_flower = Images::loadAnImage_Color(loactionObject, "flower3_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMat_elefant = Images::loadAnImage_Color(mLocationE21, "imageWithNoise");

	imageProcessing methodeImaProc = imageProcessing::detailEnhance24;

	// *** parameter DE 
	parameterDetailEnhancement paraDE;
	paraDE.setMinSigma_r(0.001);
	paraDE.setMaxSigma_r(100.0);

	paraDE.setMinSigma_s(1.0);
	paraDE.setMaxSigma_s(100.0);

	paraDE.setPercentCompare(0.0);

	if (mDebugMode)
	{
		paraDE.setStepsSigma_r(20.0);
		paraDE.setStepsSigma_s(20.0);
	}
	else
	{
		paraDE.setStepsSigma_r(200.0);
		paraDE.setStepsSigma_s(200.0);
	}


	// sharpness evaluation methode
	sharpnessEvalMethode tempShapEvalMethode = sharpnessEvalMethode::BlurAndNoise;
	paraDE.setSharpnessEvalMethode(tempShapEvalMethode);

	// set parameter
	ImaProcSuperFct imaProcessingSuperFunction;
	imaProcessingSuperFunction.setParameterDetEnh(paraDE);


	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower, simImaMat_elefant, methodeImaProc);
	real reinizializePrecent = 20.0;
	imaProcessingSuperFunction.reinitializeBestParaDetEng(reinizializePrecent, paraDE.getStepsSigma_r(), paraDE.getStepsSigma_s());
	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower, simImaMat_elefant, methodeImaProc);


	cv::Mat filteredIma_final = imaProcessingSuperFunction.getFilteredIma();
	std::string locationFiltering = "../tests/testDGaO2021/E21/filtering_BlurAndNoise_DE";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E21_filteredIma_allSequnces_BlurAndNoisev_DE", "png", filteredIma_final, paraDE.getPercentCompare());

	// save best para DE
	bestParameterStruct_detailEnhance bestParaDE = imaProcessingSuperFunction.getBestParaDetEnh();
	bestParaDE.exportAsTXTfile(locationFiltering, "bestParaDE", true);

	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_flower, simImaMat_elefant, filteredIma_final, paraDE.getPercentCompare());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_BlurAndNoise_DE", "improvement_BlurAndNoise_DE: ", improvement, true);


	return true;
}
bool testDGaO2021::E21_improveImageQuality_AllPossibleSequences_BlurAndNois_WD()
{
	// *** load objects *** //
	std::string loactionObject = "../images/color/testImaSim_test12";
	cv::Mat object_flower = Images::loadAnImage_Color(loactionObject, "flower3_900x900");


	// *** load simulated images *** //
	cv::Mat  simImaMat_flower = Images::loadAnImage_Color(mLocationE21, "imageWithNoise");

	imageProcessing methodeImaProc = imageProcessing::wienerFilter24;

	// *** parameter wiener filter *** 
	// *** parameter blue *** 
	parameterImaImprove_WD paraWD_blue{};
	paraWD_blue.setMinSNR(0.1);
	paraWD_blue.setMaxSNR(200.0);
	paraWD_blue.setMinSigmaXY(0.1);
	paraWD_blue.setMaxSigmaXY(5.0);
	paraWD_blue.setKernelSizeHeightAndWidth(30);
	paraWD_blue.setCompareInPercent(0.0);

	if (mDebugMode)
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
	sharpnessEvalMethode tempShapEvalMethode = sharpnessEvalMethode::BlurAndNoise;
	paraWD_blue.setSharpnessEvalMethode(tempShapEvalMethode);
	paraWD_green.setSharpnessEvalMethode(tempShapEvalMethode);
	paraWD_red.setSharpnessEvalMethode(tempShapEvalMethode);

	// set parameter
	ImaProcSuperFct imaProcessingSuperFunction;
	imaProcessingSuperFunction.setParameterWD_blue(paraWD_blue);
	imaProcessingSuperFunction.setParameterWD_green(paraWD_green);
	imaProcessingSuperFunction.setParameterWD_red(paraWD_red);


	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower, simImaMat_flower, methodeImaProc);
	real reinizializePrecent = 20.0;
	imaProcessingSuperFunction.reinitializeBestParaWD(reinizializePrecent, paraWD_blue.getStepsSNR(), paraWD_blue.getStepsSigmaXY());
	imaProcessingSuperFunction.ImageProcessingSuperFunction(object_flower, simImaMat_flower, methodeImaProc);

	cv::Mat filteredIma_final = imaProcessingSuperFunction.getFilteredIma();
	std::string locationFiltering = "../tests/testDGaO2021/E21/filtering_BlurAndNoise_WD";
	Images::saveImage_inputUN8C3_normByROI_percent(locationFiltering, "E21_filteredIma_allSequnces_BlurAndNoise_WD", "png", filteredIma_final, paraWD_blue.getCompareInPercent());



	// save best parameters WD
	saveBestParameterWD bestPara_blue = imaProcessingSuperFunction.getBestParaWD_blue();
	bestPara_blue.exportAsTXTfile(locationFiltering, "bestParaWD_blue", true);
	saveBestParameterWD bestPara_green = imaProcessingSuperFunction.getBestParaWD_green();
	bestPara_green.exportAsTXTfile(locationFiltering, "bestParaWD_green", true);
	saveBestParameterWD bestPara_red = imaProcessingSuperFunction.getBestParaWD_red();
	bestPara_red.exportAsTXTfile(locationFiltering, "bestParaWD_red", true);



	// calcualte improvement
	real improvement = Images::calcImprovementBGR(object_flower, simImaMat_flower, filteredIma_final, paraWD_blue.getCompareInPercent());
	inportExportData::saveDoubleInTXT(locationFiltering, "improvement_BlurAndNoise_WD", "improvement_BlurAndNoise_WD: ", improvement, true);

	return true;
}


// *** E4 ***
bool testDGaO2021::checkE4_superFct()
{
	std::vector<bool> workTheSystem;

	//bool checkE4_StartSystem = E4_checkStartSystem();
	//workTheSystem.push_back(checkE4_StartSystem);
	//
	//bool checkE4_OptimizeStartSystem = E4_checkOptimizeStartSystem_DoOptimization();
	//workTheSystem.push_back(checkE4_OptimizeStartSystem);

	//bool checkE4_loadOptiSysFirst = E4_loadOptimizedSystemFirst();
	//workTheSystem.push_back(checkE4_loadOptiSysFirst);

	bool checkE4_lensReplace = E4_lensReplace();
	workTheSystem.push_back(checkE4_lensReplace);


	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::E4_checkStartSystem()
{
	std::vector<bool> workTheSystem;

	real semiHeight = 15.0;
	real firstThickness = 200;
	

	SphericalElement S0(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 10.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S1(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 20.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	
	SphericalElement S2(/*radius*/ 100.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 30.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S3(/*radius*/ 100.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 40.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	ApertureStopElement S4(/* semi height*/3.0, /*point*/{ 0.0,0.0, firstThickness + 50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S5(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S7(/*semi height*/ 99.0, /*point*/{ 0.0,0.0, firstThickness + 85.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	// radii
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	// thicknesses
	S1.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S3.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S4.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	mStartOpticalSystem_E4.fillPosAndElementAndInteraction(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(mStartOpticalSystem_E4, 550.0);
	// save the start system
	inportExportData::saveOpticalSystemAsTXT(mStartOpticalSystem_E4, 550.0, mLocation_E4, "E4_start");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(mStartOpticalSystem_E4);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 244.840, 220.341, 196.052 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(mStartOpticalSystem_E4, mField_E4_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::E4_checkOptimizeStartSystem_DoOptimization()
{
	std::vector<bool> workTheSystem;

	OpticalSystemElement initalOpticalSystemEle = mStartOpticalSystem_E4.getDeepCopyOptSysEle();

	// optimize optical system
	DLS_multiThreads_12 DLS12(/*optSysEle*/ initalOpticalSystemEle,/*fields*/ mField_E4_vec, /*wavelength*/ mWavelength_FdV_vec, /*rings*/ mRings, /*arms*/ mArms, /*target cardinal points*/ mTargetCarPoints_E4, /*default DLS*/ mDefaulParaDLS);
	mOptimizedOpticalSystemEle_E4 = DLS12.DLS_optimisation_multiThreads_12_obj();

	// export the first optimized system
	inportExportData::saveOpticalSystemAsTXT(mOptimizedOpticalSystemEle_E4, mWave587d, mLocation_E4, "E4_optimized_first");

	// check optimized system
	std::vector<real> rmsVecInitalOptSys = oftenUse::getRMSoptSysHLT(mStartOpticalSystem_E4, mField_E4_vec, mWavelength_FdV_vec, mRings, mArms);
	std::vector<real> rmsVecDLS_12 = oftenUse::getRMSoptSysHLT(mOptimizedOpticalSystemEle_E4, mField_E4_vec, mWavelength_FdV_vec, mRings, mArms);

	real sumRMS_initalOptSys = oftenUse::sum(rmsVecInitalOptSys);
	real sumRMS_optimizedOptSys = oftenUse::sum(rmsVecDLS_12);

	bool checkOptimization = sumRMS_initalOptSys > sumRMS_optimizedOptSys;
	workTheSystem.push_back(checkOptimization);
	
	// export rms values
	std::vector<std::string> nameDoubel_vec = { "field0", "field1", "field2" };
	std::string optiRMSvalue_str = "optimizedFirst_RMSvalue";
	std::string nameTXT_optiRMSvalueFields = optiRMSvalue_str + "_" + "E4";
	inportExportData::saveVecDoubleInTXT(mLocation_E4, nameTXT_optiRMSvalueFields, nameDoubel_vec, rmsVecDLS_12, true);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::E4_loadOptimizedSystemFirst()
{
	std::vector<bool> workTheSystem;

	real semiHeight = 15.0;
	real firstThickness = 200;


	SphericalElement S0(/*radius*/ 197.71790, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 10.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S1(/*radius*/ 71.69951, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 20.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S2(/*radius*/ 121.99574, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 25.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S3(/*radius*/ 144.26454, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 35.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	ApertureStopElement S4(/* semi height*/3.0, /*point*/{ 0.0,0.0, firstThickness + 42.88281 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S5(/*radius*/ 144.10203, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 62.88281 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 20.66008, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 72.88281 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S7(/*semi height*/ 99.0, /*point*/{ 0.0,0.0, firstThickness + 87.00781 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	// radii
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	// thicknesses
	S1.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S3.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S4.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	mOptimizedOpticalSystemEle_E4.fillPosAndElementAndInteraction(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(mOptimizedOpticalSystemEle_E4, 550.0);
	// save the start system
	inportExportData::saveOpticalSystemAsTXT(mOptimizedOpticalSystemEle_E4, 550.0, mLocation_E4, "E4_loadedOptimizedFirst");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(mOptimizedOpticalSystemEle_E4);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 45.5349, 26.7858, 53.0463 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(mOptimizedOpticalSystemEle_E4, mField_E4_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::E4_lensReplace()
{
	// load optimized System E4
	E4_loadOptimizedSystemFirst();

	std::vector<bool> workTheSystem;
	std::string example = "E4";
	unsigned int numberBestFitLenses = 3;
	optimizeMethode optMethode = optimizeMethode::DLS_12;

	//// left to right
	//replaceSequence leftToRight = replaceSequence::leftToRight;
	//saveLRaO_GeneticAndDLS_12_statistic leftToRight_statRes = oftenUse::doTheStatisticEvaluation_lensSystem_LTR_RTL_MaxSei_MinSei_obj_saveIntermediateResults(mOptimizedOpticalSystemEle_E4, mField_E4_vec, mWavelength_FdV_vec, mTargetCarPoints_E4, mLocation_E4, example, leftToRight, optMethode, numberBestFitLenses, mDebugMode, false);
	//std::string leftToRight_name = "leftToRight";
	//std::string locLeftToRight = mLocation_E4 + "/" + leftToRight_name;
	//oftenUse::exportDataReplace_THREE_LensesGeneticAndDLS_12(locLeftToRight, leftToRight_name, leftToRight_statRes);
	//
	//// right to left
	//replaceSequence rightToLeft = replaceSequence::RightToLeft;
	//saveLRaO_GeneticAndDLS_12_statistic rightToLeft_statRes = oftenUse::doTheStatisticEvaluation_lensSystem_LTR_RTL_MaxSei_MinSei_obj_saveIntermediateResults(mOptimizedOpticalSystemEle_E4, mField_E4_vec, mWavelength_FdV_vec, mTargetCarPoints_E4, mLocation_E4, example, rightToLeft, optMethode, numberBestFitLenses, mDebugMode, false);
	//std::string rightToLeft_name = "rightToLeft";
	//std::string locRightToLeft = mLocation_E4 + "/" + rightToLeft_name;
	//oftenUse::exportDataReplace_THREE_LensesGeneticAndDLS_12(locRightToLeft, rightToLeft_name, rightToLeft_statRes);
	//
	//// max Seidel
	//replaceSequence maxSeidel = replaceSequence::maxSeidelAberLens;
	//saveLRaO_GeneticAndDLS_12_statistic maxSeidel_statRes = oftenUse::doTheStatisticEvaluation_lensSystem_LTR_RTL_MaxSei_MinSei_obj_saveIntermediateResults(mOptimizedOpticalSystemEle_E4, mField_E4_vec, mWavelength_FdV_vec, mTargetCarPoints_E4, mLocation_E4, example, maxSeidel, optMethode, numberBestFitLenses, mDebugMode, false);
	//std::string maxSeidel_name = "maxSeidel";
	//std::string locMaxSeidel = mLocation_E4 + "/" + maxSeidel_name;
	//oftenUse::exportDataReplace_THREE_LensesGeneticAndDLS_12(locMaxSeidel, maxSeidel_name, maxSeidel_statRes);
	//
	//// min Seidel
	//replaceSequence minSeidel = replaceSequence::minSeidelAberLens;
	//saveLRaO_GeneticAndDLS_12_statistic minSeidel_statRes = oftenUse::doTheStatisticEvaluation_lensSystem_LTR_RTL_MaxSei_MinSei_obj_saveIntermediateResults(mOptimizedOpticalSystemEle_E4, mField_E4_vec, mWavelength_FdV_vec, mTargetCarPoints_E4, mLocation_E4, example, minSeidel, optMethode, numberBestFitLenses, mDebugMode, false);
	//std::string minSeidel_name = "minSeidel";
	//std::string locMinxSeidel = mLocation_E4 + "/" + minSeidel_name;
	//oftenUse::exportDataReplace_THREE_LensesGeneticAndDLS_12(locMinxSeidel, minSeidel_name, minSeidel_statRes);

	// 102
	std::vector<unsigned int> repSeq102 = { 1,0,2 };
	saveLRaO_GeneticAndDLS_12_statistic results102 = oftenUse::doTheStatisticEvaluation_lensSystem_givenSequence_saveIntermediateResults(mOptimizedOpticalSystemEle_E4, mField_E4_vec, mWavelength_FdV_vec, mTargetCarPoints_E4, mLocation_E4, example, optMethode, numberBestFitLenses, mDebugMode, false, repSeq102);
	std::string loc102 = mLocation_E4 + "/" + "102";
	oftenUse::exportDataReplace_THREE_LensesGeneticAndDLS_12(loc102, "102", results102);

	// 201
	std::vector<unsigned int> repSeq201 = { 2,0,1 };
	saveLRaO_GeneticAndDLS_12_statistic results201 = oftenUse::doTheStatisticEvaluation_lensSystem_givenSequence_saveIntermediateResults(mOptimizedOpticalSystemEle_E4, mField_E4_vec, mWavelength_FdV_vec, mTargetCarPoints_E4, mLocation_E4, example, optMethode, numberBestFitLenses, mDebugMode, false, repSeq201);
	std::string loc201 = mLocation_E4 + "/" + "201";
	oftenUse::exportDataReplace_THREE_LensesGeneticAndDLS_12(loc201, "201", results201);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}
// *** *** //


// *** E5 ***
bool testDGaO2021::checkE5_superFct()
{
	std::vector<bool> workTheSystem;

	bool checkE5_StartSystem = E5_checkStartSystem();
	workTheSystem.push_back(checkE5_StartSystem);

	bool checkE5_firstOptimization = E5_checkOptimizeStartSystem_DoOptimization();
	workTheSystem.push_back(checkE5_firstOptimization);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}
bool testDGaO2021::E5_checkStartSystem()
{
	std::vector<bool> workTheSystem;

	real semiHeight = 25.0;
	real firstThickness = 1000.0;

	ApertureStopElement S0(/* semi height*/10.0, /*point*/{ 0.0,0.0, firstThickness + 10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 20.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 30.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 900.0, /*semi height*/semiHeight, /*point*/{ 0.0,0.0, firstThickness + 35.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S4(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S6(/*radius*/ 500.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S7(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 90.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S8(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 100.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF10_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S9(/*radius*/ 400.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 105.00 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF10_S1());

	SphericalElement S10(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 125.0 }, /*direction*/{ 0.0,0.0,  1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());
	SphericalElement S11(/*radius*/100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 135.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF10_S1(), /*refractive index B*/mGlasses.getNSSK8_S1());
	SphericalElement S12(/*radius*/100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0, firstThickness + 140.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF10_S1(), /*refractive index B*/mGlasses.getAir());

	PlanElement S13(/*semi height*/ 99.0, /*point*/{ 0.0,0.0, firstThickness + 155.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	// radii
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	// thicknesses
	S3.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 25.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 25.0, 0.0, typeModifierVariable);
	S9.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 25.0, 0.0, typeModifierVariable);
	S12.setParameterPointZ(/*min value*/5.0, /*max value*/ 25.0, 0.0, typeModifierVariable);
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
	surfacePtr S11_ptr = S11.clone();
	surfacePtr S12_ptr = S12.clone();
	surfacePtr S13_ptr = S13.clone();


	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr,S5_ptr,S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),  mRefrac.clone(),  mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };


	//	build optical system
	mStartOpticalSystem_E5.fillPosAndElementAndInteraction(opticalSystem_ptr, interactions_ptr);
	oftenUse::print(mStartOpticalSystem_E5, 550.0);
	// save the start system

	inportExportData::saveOpticalSystemAsTXT(mStartOpticalSystem_E5, 550.0, mLocation_E5, "E5_start_DGaO2021");

	// check ref indexes
	bool checkRefIndexes = oftenUse::checkRefractivIndex(mStartOpticalSystem_E5);
	workTheSystem.push_back(checkRefIndexes);
	// check the start system
	std::vector<real> rms_Zemax{ 386.965, 391.544, 396.106 };
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(mStartOpticalSystem_E5, mField_E5_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(test);


	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}

bool testDGaO2021::E5_checkOptimizeStartSystem_DoOptimization()
{
	std::vector<bool> workTheSystem;

	OpticalSystemElement initalOpticalSystemEle = mStartOpticalSystem_E5.getDeepCopyOptSysEle();

	// optimize optical system
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ initalOpticalSystemEle,/*fields*/ mField_E5_vec, /*wavelength*/ mWavelength_FdV_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCarPoints_E5, /*default Genetic*/mDefaultParameterGenetic, /*default DLS*/ mDefaulParaDLS);
	mOptimizedOpticalSystemEle_E5 = GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();

	// export the first optimized system
	inportExportData::saveOpticalSystemAsTXT(mOptimizedOpticalSystemEle_E5, mWave587d, mLocation_E5, "E5_optimized_first");

	// check optimized system
	std::vector<real> rmsVecInitalOptSys = oftenUse::getRMSoptSysHLT(mStartOpticalSystem_E5, mField_E5_vec, mWavelength_FdV_vec, mRings, mArms);
	std::vector<real> rmsVecGeneticAndDLS_12 = oftenUse::getRMSoptSysHLT(mOptimizedOpticalSystemEle_E5, mField_E5_vec, mWavelength_FdV_vec, mRings, mArms);

	real sumRMS_initalOptSys = oftenUse::sum(rmsVecInitalOptSys);
	real sumRMS_optimizedOptSys = oftenUse::sum(rmsVecGeneticAndDLS_12);

	bool checkOptimization = sumRMS_initalOptSys > sumRMS_optimizedOptSys;
	workTheSystem.push_back(checkOptimization);

	// export rms values
	std::vector<std::string> nameDoubel_vec = { "field0", "field1", "field2" };
	std::string optiRMSvalue_str = "optimizedFirst_RMSvalue";
	std::string nameTXT_optiRMSvalueFields = optiRMSvalue_str + "_" + "E5";
	inportExportData::saveVecDoubleInTXT(mLocation_E5, nameTXT_optiRMSvalueFields, nameDoubel_vec, rmsVecGeneticAndDLS_12, true);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}
// *** *** //