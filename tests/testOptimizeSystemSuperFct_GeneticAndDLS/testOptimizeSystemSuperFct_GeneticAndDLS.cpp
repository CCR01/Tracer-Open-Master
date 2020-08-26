#include "testOptimizeSystemSuperFct_GeneticAndDLS.h"

// element surfaces
#include "..\..\SurfaceElements\ApertureStopElement.h"
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\PlanElement.h"


// fill apeterture stop
#include "..\..\FillAptertureStop\FillApertureStop.h"
// analyses -> spot
#include "..\..\Analyse\Spot.h"
// often use
#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

// cardinal points
#include "..\..\Analyse\CardinalPoints.h"

testOptimizeSystemSuperFct_GeneticAndDLS::testOptimizeSystemSuperFct_GeneticAndDLS() { loadImportantStuff(); }

testOptimizeSystemSuperFct_GeneticAndDLS::~testOptimizeSystemSuperFct_GeneticAndDLS() {}

typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interactionPtr;

// load important stuff
void testOptimizeSystemSuperFct_GeneticAndDLS::loadImportantStuff()
{
	mTolerance = 10.0;
	glasses.loadGlassCatalog_Schott();

	//  wave
	mWave587 = 587.5618;
	mWave486 = 486.1327;
	mWave656 = 656.2725;
	mWavelength_FdC_vec = { mWave587 , mWave486, mWave656 };

	// fields obj
	mField0 = { 0.0,0.0,0.0 };
	mField1 = { 0.0,1.0,0.0 };
	mField2 = { 0.0,2.0,0.0 };
	mField3 = { 0.0,3.0,0.0 };
	mField4 = { 0.0,4.0,0.0 };

	mFields_vec012 = { mField0, mField1, mField2 };
	mFields_vec024 = { mField0, mField2, mField4 };

	// fields inf angles
	mAngleX_0 = 0.0;
	mAngleY_0 = 0.0;
	mAngleY_1 = 1.0;
	mAngleY_2 = 2.0;
	mAngleX_000_vec = { mAngleX_0 , mAngleX_0 , mAngleX_0 };
	mAngleY_012_vec = { mAngleY_0 , mAngleY_1 , mAngleY_2 };

	// load defaul parameters for genetic
	mDefaultParaGenetic_rayTracing_ON.setStartRefIndex(1.0);
	mDefaultParaGenetic_rayTracing_ON.setToleranceWithoutMIN(-0.5);
	mDefaultParaGenetic_rayTracing_ON.setToleranceWithoutMAX(0.5);
	mDefaultParaGenetic_rayTracing_ON.setMaxInterationGenetic(3);
	mDefaultParaGenetic_rayTracing_ON.setDeltaMeritValueStop(0.1);
	mDefaultParaGenetic_rayTracing_ON.setToleranceForEvaluation(0.001);
	mDefaultParaGenetic_rayTracing_ON.setChooseValueMode(normalDistributionDefaultMode);
	mDefaultParaGenetic_rayTracing_ON.set_ON_CheckRMS_rayTracing();

	mDefaultParaGenetic_rayTracing_OFF = mDefaultParaGenetic_rayTracing_ON;
	mDefaultParaGenetic_rayTracing_OFF.set_OFF_CheckRMS_rayTracing();

	// load defaul parameters for DLS
	mDefaultParamDLS_rayTracing_ON.setDampingFactor(5.0);
	mDefaultParamDLS_rayTracing_ON.setFactorRadiusDeviation(0.000001);
	mDefaultParamDLS_rayTracing_ON.setFactorPositionDeviation(0.000001);
	mDefaultParamDLS_rayTracing_ON.setStartRefractivIndex(1.0);
	mDefaultParamDLS_rayTracing_ON.setMaxWorstCounter(300);
	mDefaultParamDLS_rayTracing_ON.setImproveMeritStopDiff(0.00000001);
	mDefaultParamDLS_rayTracing_ON.setMaxInterations(500);
	mDefaultParamDLS_rayTracing_ON.setFlipOrientationRadius(1000.0);
	mDefaultParamDLS_rayTracing_ON.setMaxBorderViolations(5);
	mDefaultParamDLS_rayTracing_ON.setMaxDeltaParameter(25.0);
	mDefaultParamDLS_rayTracing_ON.setMinDeltaParameter(0.00000001);
	mDefaultParamDLS_rayTracing_ON.setFactorGettingBetter(0.4);
	mDefaultParamDLS_rayTracing_ON.setFactorGettingWorst(1.9);
	mDefaultParamDLS_rayTracing_ON.setToleranceWithoutMin(0.0);
	mDefaultParamDLS_rayTracing_ON.setToleranceWithoutMax(0.0);
	mDefaultParamDLS_rayTracing_ON.set_Min_DamNumBefSwitchFactors(0.00001);
	mDefaultParamDLS_rayTracing_ON.set_Max_DamNumBefSwitchFactors(9999.0);
	mDefaultParamDLS_rayTracing_ON.turn_ON_calcRMSusingRayTracing();

	mDefaultParamDLS_rayTracing_OFF = mDefaultParamDLS_rayTracing_ON;
	mDefaultParamDLS_rayTracing_OFF.turn_OFF_caclRMSusingRayTracing();

	mRings = 6;
	mArms = 8;

	// debug
	// mPopulation = 50;
	mPopulation = 1000.0;

	m_NO_targetCarPoint.setCardinalPoints_NO_target();
}

bool testOptimizeSystemSuperFct_GeneticAndDLS::testOptimizeSys_SuperFunction_GeneticDLS_rms()
{
	std::vector<bool> workTheOptimizerSuperFct_rms;
	
	// E0
	bool checkE0_rms = checkE0_GeneticAndDLS_rms();
	workTheOptimizerSuperFct_rms.push_back(checkE0_rms);
	
	// E1
	bool checkE1_rms = checkE1_GeneticAndDLS_rms();
	workTheOptimizerSuperFct_rms.push_back(checkE1_rms);
	
	// E2
	bool checkE2_rms = checkE2_GeneticAndDLS_rms();
	workTheOptimizerSuperFct_rms.push_back(checkE2_rms);
	
	// E3
	bool checkE3_rms = checkE3_GeneticAndDLS_rms();
	workTheOptimizerSuperFct_rms.push_back(checkE3_rms);
	
	// E4
	bool checkE4_rms = checkE4_GeneticAndDLS_rms();
	workTheOptimizerSuperFct_rms.push_back(checkE4_rms);
	
	// E5
	bool checkE5_rms = checkE5_GeneticAndDLS_rms();
	workTheOptimizerSuperFct_rms.push_back(checkE5_rms);
	
	// E6
	bool checkE6_rms = checkE6_GeneticAndDLS_rms();
	workTheOptimizerSuperFct_rms.push_back(checkE6_rms);
	
	// E7
	bool checkE7_rms = checkE7_GeneticAndDLS_rms();
	workTheOptimizerSuperFct_rms.push_back(checkE7_rms);
	
	// E8
	bool checkE8_rms = checkE8_GeneticAndDLS_rms();
	workTheOptimizerSuperFct_rms.push_back(checkE8_rms);
	
	// E9
	bool checkE9_rms = checkE9_GeneticAndDLS_rms();
	workTheOptimizerSuperFct_rms.push_back(checkE9_rms);
	
	// E10
	bool checkE10_rms = checkE10_GeneticAndDLS_rms();
	workTheOptimizerSuperFct_rms.push_back(checkE10_rms);
	
	// E11
	bool checkE11_rms = checkE11_GeneticAndDLS_rms();
	workTheOptimizerSuperFct_rms.push_back(checkE11_rms);

	// E12 
	bool checkE12_rms = checkE12_GeneticAndDLS_rms();
	workTheOptimizerSuperFct_rms.push_back(checkE12_rms);

	bool returnChecker_rms = Math::checkTrueOfVectorElements(workTheOptimizerSuperFct_rms);

	return returnChecker_rms;
}

bool testOptimizeSystemSuperFct_GeneticAndDLS::testOptimizeSystem_SuperFunction_GeneticDLS_carPoints()
{
	std::vector<bool> workTheOptimizerSuperFct_cardinalPoints;

	// E0
	bool checkE0_carPoint = checkE0_GeneticAndDLS_cardinalPoints();
	workTheOptimizerSuperFct_cardinalPoints.push_back(checkE0_carPoint);


	bool returnChecker_carP = Math::checkTrueOfVectorElements(workTheOptimizerSuperFct_cardinalPoints);

	return returnChecker_carP;
}

bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE0_GeneticAndDLS_rms()
{
	//***
	unsigned int systemNum = 0;
	std::cout << "check optimize system genetic and DLS system number: " << systemNum << std::endl;
	//***

	std::vector<bool> check_vec;

	// surfaces E0
	ApertureStopElement AperStop0_E0(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E0(/*radius*/ 25.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2_E0(/*radius*/ 25.00, /*semi height*/7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF11_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3_E0(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF11_S1());
	SphericalElement Sphere4_E0(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF4_S1());
	SphericalElement Sphere5_E0(/*radius*/ 70.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF4_S1());
	SphericalElement Sphere6_E0(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere7_E0(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere8_E0(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	PlanElement Plan9_E0(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,80.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	
	Sphere3_E0.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere5_E0.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere7_E0.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	
	surfacePtr Aper0_E0_ptr = AperStop0_E0.clone();
	surfacePtr Sphere1_E0_ptr = Sphere1_E0.clone();
	surfacePtr Sphere2_E0_ptr = Sphere2_E0.clone();
	surfacePtr Sphere3_E0_ptr = Sphere3_E0.clone();
	surfacePtr Sphere4_E0_ptr = Sphere4_E0.clone();
	surfacePtr Sphere5_E0_ptr = Sphere5_E0.clone();
	surfacePtr Sphere6_E0_ptr = Sphere6_E0.clone();
	surfacePtr Sphere7_E0_ptr = Sphere7_E0.clone();
	surfacePtr Sphere8_E0_ptr = Sphere8_E0.clone();
	surfacePtr Plan9_E0_ptr = Plan9_E0.clone();
	
	std::vector<surfacePtr> opticalSystemE0_ptr{ Aper0_E0_ptr, Sphere1_E0_ptr, Sphere2_E0_ptr , Sphere3_E0_ptr, Sphere4_E0_ptr, Sphere5_E0_ptr, Sphere6_E0_ptr, Sphere7_E0_ptr, Sphere8_E0_ptr, Plan9_E0_ptr };
	std::vector<interactionPtr> interactionsE0_ptr{ mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSysEle_E0(opticalSystemE0_ptr, interactionsE0_ptr);
	
	// check the start system
	std::vector<real> rmsStartSystem_Z{ 196.503,192.101,179.353 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E0, mFields_vec012, mWavelength_FdC_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);
	
	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSysEle_E0,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_FdC_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParaGenetic_rayTracing_ON, /*default DLS*/ mDefaultParamDLS_rayTracing_ON);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();

	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_FdC_vec[0]);

	std::vector<real> rmsOpti_Z{ 17.240,22.200,35.897 }; // sum 75.337
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_FdC_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);
	
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;

}

bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE1_GeneticAndDLS_rms()
{
	//***
	unsigned int systemNum = 1;
	std::cout << "check optimize system genetic and DLS system number: " << systemNum << std::endl;
	//***

	std::vector<bool> check_vec;

	// surfaces E1
	ApertureStopElement AperStop0_E1(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E1(/*radius*/ 35.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2_E1(/*radius*/ 35.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF11_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3_E1(/*radius*/ 45.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF11_S1());
	SphericalElement Sphere4_E1(/*radius*/ 100.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF4_S1());
	SphericalElement Sphere5_E1(/*radius*/ 90.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF4_S1());
	SphericalElement Sphere6_E1(/*radius*/ 60.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere7_E1(/*radius*/ 45.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere8_E1(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement Sphere9_E1(/*radius*/ 80.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere10_E1(/*radius*/ 70.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	PlanElement Plan11_E1(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,95.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere1_E1.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2_E1.setParameterPointZ(5.0, 100.0, 0.0, typeModifierVariable);
	Sphere10_E1.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);

	surfacePtr Aper0_E1_ptr = AperStop0_E1.clone();
	surfacePtr Sphere1_E1_ptr = Sphere1_E1.clone();
	surfacePtr Sphere2_E1_ptr = Sphere2_E1.clone();
	surfacePtr Sphere3_E1_ptr = Sphere3_E1.clone();
	surfacePtr Sphere4_E1_ptr = Sphere4_E1.clone();
	surfacePtr Sphere5_E1_ptr = Sphere5_E1.clone();
	surfacePtr Sphere6_E1_ptr = Sphere6_E1.clone();
	surfacePtr Sphere7_E1_ptr = Sphere7_E1.clone();
	surfacePtr Sphere8_E1_ptr = Sphere8_E1.clone();
	surfacePtr Sphere9_E1_ptr = Sphere9_E1.clone();
	surfacePtr Sphere10_E1_ptr = Sphere10_E1.clone();
	surfacePtr Plan11_E1_ptr = Plan11_E1.clone();

	std::vector<surfacePtr> opticalSystemE1_ptr{ Aper0_E1_ptr, Sphere1_E1_ptr, Sphere2_E1_ptr , Sphere3_E1_ptr, Sphere4_E1_ptr, Sphere5_E1_ptr, Sphere6_E1_ptr, Sphere7_E1_ptr, Sphere8_E1_ptr, Sphere9_E1_ptr, Sphere10_E1_ptr, Plan11_E1_ptr };
	std::vector<interactionPtr> interactionsE1_ptr{ mDoNothing.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E1(opticalSystemE1_ptr, interactionsE1_ptr);

	// check the start system
	std::vector<real> rmsStartSystem_Z{ 77.542,87.021,113.632 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E1, mFields_vec012, mWavelength_FdC_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);

	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E1,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_FdC_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParaGenetic_rayTracing_ON, /*default DLS*/ mDefaultParamDLS_rayTracing_ON);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();

	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_FdC_vec[0]);

	std::vector<real> rmsOpti_Z{ 20.872,28.502,50.817 }; // sum 100.191
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_FdC_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

//E2
bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE2_GeneticAndDLS_rms()
{
	//***
	unsigned int systemNum = 2;
	std::cout << "check optimize system genetic and DLS system number: " << systemNum << std::endl;
	//***

	std::vector<bool> check_vec;

	//	// surfaces E2
	ApertureStopElement AperStop0_E2(/* semi height*/1.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E2(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF4_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere2_E2(/*radius*/ 150.00, /*semi height*/7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF4_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere3_E2(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere4_E2(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere5_E2(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement Sphere6_E2(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF4_S1());
	SphericalElement Sphere7_E2(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF57_S1(), /*refractive index B*/glasses.getSF4_S1());
	SphericalElement Sphere8_E2(/*radius*/ 35.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF57_S1());
	PlanElement Plan9_E2(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,100.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere2_E2.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere5_E2.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere8_E2.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);

	surfacePtr Aper0_E2_ptr = AperStop0_E2.clone();
	surfacePtr Sphere1_E2_ptr = Sphere1_E2.clone();
	surfacePtr Sphere2_E2_ptr = Sphere2_E2.clone();
	surfacePtr Sphere3_E2_ptr = Sphere3_E2.clone();
	surfacePtr Sphere4_E2_ptr = Sphere4_E2.clone();
	surfacePtr Sphere5_E2_ptr = Sphere5_E2.clone();
	surfacePtr Sphere6_E2_ptr = Sphere6_E2.clone();
	surfacePtr Sphere7_E2_ptr = Sphere7_E2.clone();
	surfacePtr Sphere8_E2_ptr = Sphere8_E2.clone();
	surfacePtr Plan9_E2_ptr = Plan9_E2.clone();

	std::vector<surfacePtr> opticalSystemE2_ptr{ Aper0_E2_ptr, Sphere1_E2_ptr, Sphere2_E2_ptr , Sphere3_E2_ptr, Sphere4_E2_ptr, Sphere5_E2_ptr, Sphere6_E2_ptr, Sphere7_E2_ptr, Sphere8_E2_ptr, Plan9_E2_ptr };
	std::vector<interactionPtr> interactionsE2_ptr{ mDoNothing.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E2(opticalSystemE2_ptr, interactionsE2_ptr);

	// check the start system
	std::vector<real> rmsStartSystem_Z{ 32.135,40.076,59.620 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E2, mFields_vec012, mWavelength_FdC_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);
	
	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E2,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_FdC_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParaGenetic_rayTracing_ON, /*default DLS*/ mDefaultParamDLS_rayTracing_ON);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();
	
	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_FdC_vec[0]);
	
	std::vector<real> rmsOpti_Z{ 17.621,20.095,27.465 }; // sum 65.181
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_FdC_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

//E3
bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE3_GeneticAndDLS_rms()
{
	//***
	unsigned int systemNum = 3;
	std::cout << "check optimize system genetic and DLS system number: " << systemNum << std::endl;
	//***

	std::vector<bool> check_vec;

	// surfaces E3
	ApertureStopElement AperStop0_E3(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E3(/*radius*/ 80.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF4_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere2_E3(/*radius*/ 110.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF4_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3_E3(/*radius*/ 90.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere4_E3(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere5_E3(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere6_E3(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement Sphere7_E3(/*radius*/ 100.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF5_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere8_E3(/*radius*/ 100.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF5_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere9_E3(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere10_E3(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF57_S1(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere11_E3(/*radius*/ 35.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF57_S1());
	PlanElement Plan12_E3(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,115.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	
	Sphere2_E3.setParameterPointZ(1.0, 200.0, 0.0, typeModifierVariable);
	Sphere5_E3.setParameterPointZ(1.0, 200.0, 0.0, typeModifierVariable);
	Sphere9_E3.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
		
	
	surfacePtr Aper0_E3_ptr = AperStop0_E3.clone();
	surfacePtr Sphere1_E3_ptr = Sphere1_E3.clone();
	surfacePtr Sphere2_E3_ptr = Sphere2_E3.clone();
	surfacePtr Sphere3_E3_ptr = Sphere3_E3.clone();
	surfacePtr Sphere4_E3_ptr = Sphere4_E3.clone();
	surfacePtr Sphere5_E3_ptr = Sphere5_E3.clone();
	surfacePtr Sphere6_E3_ptr = Sphere6_E3.clone();
	surfacePtr Sphere7_E3_ptr = Sphere7_E3.clone();
	surfacePtr Sphere8_E3_ptr = Sphere8_E3.clone();
	surfacePtr Sphere9_E3_ptr = Sphere9_E3.clone();
	surfacePtr Sphere10_E3_ptr = Sphere10_E3.clone();
	surfacePtr Sphere11_E3_ptr = Sphere11_E3.clone();
	surfacePtr Plan12_E3_ptr = Plan12_E3.clone();
	
	std::vector<surfacePtr> opticalSystemE3_ptr{ Aper0_E3_ptr, Sphere1_E3_ptr, Sphere2_E3_ptr , Sphere3_E3_ptr, Sphere4_E3_ptr, Sphere5_E3_ptr, Sphere6_E3_ptr, Sphere7_E3_ptr, Sphere8_E3_ptr, Sphere9_E3_ptr, Sphere10_E3_ptr, Sphere11_E3_ptr, Plan12_E3_ptr };
	std::vector<interactionPtr> interactionsE3_ptr{ mDoNothing.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSystemElement_E3(opticalSystemE3_ptr, interactionsE3_ptr);
	
	// check the start system
	std::vector<real> rmsStartSystem_Z{ 324.164,307.127,261.495 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E3, mFields_vec012, mWavelength_FdC_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);
		
	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E3,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_FdC_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParaGenetic_rayTracing_ON, /*default DLS*/ mDefaultParamDLS_rayTracing_ON);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();
	
	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_FdC_vec[0]);
	
	std::vector<real> rmsOpti_Z{ 45.330,56.613,117.711 }; // sum 219.654
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_FdC_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}


//E4
bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE4_GeneticAndDLS_rms()
{
	//***
	unsigned int systemNum = 4;
	std::cout << "check optimize system genetic and DLS system number: " << systemNum << std::endl;
	//***

	std::vector<bool> check_vec;

	// surfaces E4
	ApertureStopElement AperStop0_E4(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E4(/*radius*/ 60.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF4_S1());
	SphericalElement Sphere2_E4(/*radius*/ 70.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getSF4_S1());
	SphericalElement Sphere3_E4(/*radius*/ 50.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere4_E4(/*radius*/ 200.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBAFN10_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere5_E4(/*radius*/ 150.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getBAFN10_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere6_E4(/*radius*/ 50.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere7_E4(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere8_E4(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	PlanElement Plan9_E4(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,100.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	
	Sphere2_E4.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere4_E4.setParameterPointZ(1.0, 200.0, 0.0, typeModifierVariable);
	Sphere6_E4.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	
	surfacePtr Aper0_E4_ptr = AperStop0_E4.clone();
	surfacePtr Sphere1_E4_ptr = Sphere1_E4.clone();
	surfacePtr Sphere2_E4_ptr = Sphere2_E4.clone();
	surfacePtr Sphere3_E4_ptr = Sphere3_E4.clone();
	surfacePtr Sphere4_E4_ptr = Sphere4_E4.clone();
	surfacePtr Sphere5_E4_ptr = Sphere5_E4.clone();
	surfacePtr Sphere6_E4_ptr = Sphere6_E4.clone();
	surfacePtr Sphere7_E4_ptr = Sphere7_E4.clone();
	surfacePtr Sphere8_E4_ptr = Sphere8_E4.clone();
	surfacePtr Plan9_E4_ptr = Plan9_E4.clone();
	
	std::vector<surfacePtr> opticalSystemE4_ptr{ Aper0_E4_ptr, Sphere1_E4_ptr, Sphere2_E4_ptr , Sphere3_E4_ptr, Sphere4_E4_ptr, Sphere5_E4_ptr, Sphere6_E4_ptr, Sphere7_E4_ptr, Sphere8_E4_ptr, Plan9_E4_ptr };
	std::vector<interactionPtr> interactionsE4_ptr{ mDoNothing.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mAbsorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSystemElement_E4(opticalSystemE4_ptr, interactionsE4_ptr);
	
	// check the start system
	std::vector<real> rmsStartSystem_Z{ 269.294,260.916,238.140 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E4, mFields_vec012, mWavelength_FdC_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);
		
	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E4,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_FdC_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParaGenetic_rayTracing_ON, /*default DLS*/ mDefaultParamDLS_rayTracing_ON);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();
	
	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_FdC_vec[0]);
	
	std::vector<real> rmsOpti_Z{ 42.453,54.593,85.239 }; // sum 182.285
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_FdC_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}


//E5
bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE5_GeneticAndDLS_rms()
{
	//***
	unsigned int systemNum = 5;
	std::cout << "check optimize system genetic and DLS system number: " << systemNum << std::endl;
	//***

	std::vector<bool> check_vec;

	// surfaces E5
	ApertureStopElement AperStop0_E5(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E5(/*radius*/ 80.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere2_E5(/*radius*/ 70.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere3_E5(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere4_E5(/*radius*/ 35.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere5_E5(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	PlanElement Plan6_E5(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,75.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	
	Sphere1_E5.setParameterPointZ(0.01, 20.0, 0.0, typeModifierVariable);
	Sphere2_E5.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere4_E5.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	
	surfacePtr Aper0_E5_ptr = AperStop0_E5.clone();
	surfacePtr Sphere1_E5_ptr = Sphere1_E5.clone();
	surfacePtr Sphere2_E5_ptr = Sphere2_E5.clone();
	surfacePtr Sphere3_E5_ptr = Sphere3_E5.clone();
	surfacePtr Sphere4_E5_ptr = Sphere4_E5.clone();
	surfacePtr Sphere5_E5_ptr = Sphere5_E5.clone();
	surfacePtr Plan6_E5_ptr = Plan6_E5.clone();
	
	std::vector<surfacePtr> opticalSystemE5_ptr{ Aper0_E5_ptr, Sphere1_E5_ptr, Sphere2_E5_ptr , Sphere3_E5_ptr, Sphere4_E5_ptr, Sphere5_E5_ptr,  Plan6_E5_ptr };
	std::vector<interactionPtr> interactionsE5_ptr{ mDoNothing.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mAbsorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSystemElement_E5(opticalSystemE5_ptr, interactionsE5_ptr);
	
	// check the start system
	std::vector<real> rmsStartSystem_Z{ 221.602,215.043,196.523 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E5, mFields_vec012, mWavelength_FdC_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);
		
	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E5,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_FdC_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation /*1000*/, /*default Genetic*/ mDefaultParaGenetic_rayTracing_ON, /*default DLS*/ mDefaultParamDLS_rayTracing_ON);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();
	
	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_FdC_vec[0]);
	
	std::vector<real> rmsOpti_Z{ 7.975,8.719,10.737 }; // sum 27.431
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_FdC_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}


//E6
bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE6_GeneticAndDLS_rms()
{
	//***
	unsigned int systemNum = 6;
	std::cout << "check optimize system genetic and DLS system number: " << systemNum << std::endl;
	//***

	std::vector<bool> check_vec;

	// surfaces E6
	ApertureStopElement AperStop0_E6(/* semi height*/2.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E6(/*radius*/ 20.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere2_E6(/*radius*/ 20.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere3_E6(/*radius*/ 20.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	PlanElement Plan4_E6(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	
	Sphere1_E6.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2_E6.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere3_E6.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	
	surfacePtr Aper0_E6_ptr = AperStop0_E6.clone();
	surfacePtr Sphere1_E6_ptr = Sphere1_E6.clone();
	surfacePtr Sphere2_E6_ptr = Sphere2_E6.clone();
	surfacePtr Sphere3_E6_ptr = Sphere3_E6.clone();
	surfacePtr Plan4_E6_ptr = Plan4_E6.clone();
	
	std::vector<surfacePtr> opticalSystemE6_ptr{ Aper0_E6_ptr, Sphere1_E6_ptr, Sphere2_E6_ptr , Sphere3_E6_ptr, Plan4_E6_ptr };
	std::vector<interactionPtr> interactionsE6_ptr{ mDoNothing.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSystemElement_E6(opticalSystemE6_ptr, interactionsE6_ptr);
	
	// check the start system
	std::vector<real> rmsStartSystem_Z{ 1032.04,981.987,859.466 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E6, mFields_vec012, mWavelength_FdC_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);
		
	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E6,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_FdC_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParaGenetic_rayTracing_ON, /*default DLS*/ mDefaultParamDLS_rayTracing_ON);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();
	
	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_FdC_vec[0]);
	
	std::vector<real> rmsOpti_Z{ 180.933,274.871,522.848 }; // sum 978.652
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_FdC_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}


//E7
bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE7_GeneticAndDLS_rms()
{
	//***
	unsigned int systemNum = 7;
	std::cout << "check optimize system genetic and DLS system number: 7" << systemNum << std::endl;
	//***

	std::vector<bool> check_vec;

	// surfaces E7
	ApertureStopElement AperStop0_E7(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E7(/*radius*/ 15.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere2_E7(/*radius*/ 30.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF6_S1(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere3_E7(/*radius*/ 25.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
	PlanElement Plan4_E7(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,75.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	
	Sphere1_E7.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere1_E7.setParameterPointZ(5.0, 20.0, 0.0, typeModifierVariable);
	Sphere3_E7.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	
	surfacePtr Aper0_E7_ptr = AperStop0_E7.clone();
	surfacePtr Sphere1_E7_ptr = Sphere1_E7.clone();
	surfacePtr Sphere2_E7_ptr = Sphere2_E7.clone();
	surfacePtr Sphere3_E7_ptr = Sphere3_E7.clone();
	surfacePtr Plan4_E7_ptr = Plan4_E7.clone();
	
	std::vector<surfacePtr> opticalSystemE7_ptr{ Aper0_E7_ptr, Sphere1_E7_ptr, Sphere2_E7_ptr , Sphere3_E7_ptr, Plan4_E7_ptr };
	std::vector<interactionPtr> interactionsE7_ptr{ mDoNothing.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSystemElement_E7(opticalSystemE7_ptr, interactionsE7_ptr);
	
	// check the start system
	std::vector<real> rmsStartSystem_Z{ 102.085,125.210,184.717 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E7, mFields_vec012, mWavelength_FdC_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);
	
	
	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E7,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_FdC_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParaGenetic_rayTracing_ON, /*default DLS*/ mDefaultParamDLS_rayTracing_ON);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();
	
	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_FdC_vec[0]);
	
	std::vector<real> rmsOpti_Z{ 64.942,77.548,114.383 }; // sum 256,873
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_FdC_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}


//E8
bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE8_GeneticAndDLS_rms()
{
	//***
	unsigned int systemNum = 8;
	std::cout << "check optimize system genetic and DLS system number: " << systemNum << std::endl;
	//***

	std::vector<bool> check_vec;

	// surfaces E8
	ApertureStopElement AperStop0_E8(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E8(/*radius*/ 60.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2_E8(/*radius*/ 50.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3_E8(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement Sphere4_E8(/*radius*/ 50.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere5_E8(/*radius*/ 50.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere6_E8(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	PlanElement Plan7_E8(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,95.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	
	Sphere2_E8.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere4_E8.setParameterPointZ(2.0, 20.0, 0.0, typeModifierVariable);
	Sphere6_E8.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	
	surfacePtr Aper0_E8_ptr = AperStop0_E8.clone();
	surfacePtr Sphere1_E8_ptr = Sphere1_E8.clone();
	surfacePtr Sphere2_E8_ptr = Sphere2_E8.clone();
	surfacePtr Sphere3_E8_ptr = Sphere3_E8.clone();
	surfacePtr Sphere4_E8_ptr = Sphere4_E8.clone();
	surfacePtr Sphere5_E8_ptr = Sphere5_E8.clone();
	surfacePtr Sphere6_E8_ptr = Sphere6_E8.clone();
	surfacePtr Plan7_E8_ptr = Plan7_E8.clone();
	
	std::vector<surfacePtr> opticalSystemE8_ptr{ Aper0_E8_ptr, Sphere1_E8_ptr, Sphere2_E8_ptr , Sphere3_E8_ptr, Sphere4_E8_ptr, Sphere5_E8_ptr, Sphere6_E8_ptr, Plan7_E8_ptr };
	std::vector<interactionPtr> interactionsE8_ptr{ mDoNothing.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mAbsorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSystemElement_E8(opticalSystemE8_ptr, interactionsE8_ptr);
	
	
	// check the start system
	std::vector<real> rmsStartSystem_Z{ 318.440,307.550,278.838 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E8, mFields_vec012, mWavelength_FdC_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);
	
	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E8,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_FdC_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParaGenetic_rayTracing_ON, /*default DLS*/ mDefaultParamDLS_rayTracing_ON);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();
	
	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_FdC_vec[0]);
	
	std::vector<real> rmsOpti_Z{ 58.661,73.741,118.741 }; // sum 251.143
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_FdC_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}


//E9
bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE9_GeneticAndDLS_rms()
{
	//***
	unsigned int systemNum = 9;
	std::cout << "check optimize system genetic and DLS system number: " << systemNum << std::endl;
	//***

	std::vector<bool> check_vec;

	// surfaces E9
	ApertureStopElement AperStop0_E9(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E9(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2_E9(/*radius*/ 100.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement Sphere3_E9(/*radius*/ 90.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere4_E9(/*radius*/ 80.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF5_S1(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement Sphere5_E9(/*radius*/ 70.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF10_S1(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement Sphere6_E9(/*radius*/ 60.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBAK4_S1(), /*refractive index B*/glasses.getSF10_S1());
	SphericalElement Sphere7_E9(/*radius*/ 20.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAK4_S1());
	PlanElement Plan8_E9(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,110.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	
	Sphere1_E9.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2_E9.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere6_E9.setParameterPointZ(1.0, 20.0, 0.0, typeModifierVariable);
	
	surfacePtr Aper0_E9_ptr = AperStop0_E9.clone();
	surfacePtr Sphere1_E9_ptr = Sphere1_E9.clone();
	surfacePtr Sphere2_E9_ptr = Sphere2_E9.clone();
	surfacePtr Sphere3_E9_ptr = Sphere3_E9.clone();
	surfacePtr Sphere4_E9_ptr = Sphere4_E9.clone();
	surfacePtr Sphere5_E9_ptr = Sphere5_E9.clone();
	surfacePtr Sphere6_E9_ptr = Sphere6_E9.clone();
	surfacePtr Sphere7_E9_ptr = Sphere7_E9.clone();
	surfacePtr Plan8_E9_ptr = Plan8_E9.clone();
	
	std::vector<surfacePtr> opticalSystemE9_ptr{ Aper0_E9_ptr, Sphere1_E9_ptr, Sphere2_E9_ptr , Sphere3_E9_ptr, Sphere4_E9_ptr, Sphere5_E9_ptr, Sphere6_E9_ptr, Sphere7_E9_ptr, Plan8_E9_ptr };
	std::vector<interactionPtr> interactionsE9_ptr{ mDoNothing.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mAbsorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSystemElement_E9(opticalSystemE9_ptr, interactionsE9_ptr);
	
	// check the start system
	std::vector<real> rmsStartSystem_Z{ 1285.00,1251.18,1153.43 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E9, mFields_vec012, mWavelength_FdC_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);
		
	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E9,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_FdC_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParaGenetic_rayTracing_ON, /*default DLS*/ mDefaultParamDLS_rayTracing_ON);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();
	
	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_FdC_vec[0]);
	
	std::vector<real> rmsOpti_Z{ 66.259,113.022,229.296 }; // sum 408,577
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_FdC_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}


//E10
bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE10_GeneticAndDLS_rms()
{
	mDefaultParamDLS_rayTracing_ON.setToleranceWithoutMax(0.0);
	mDefaultParamDLS_rayTracing_ON.setToleranceWithoutMin(0.0);

	//***
	unsigned int systemNum = 10;
	std::cout << "check optimize system genetic and DLS system number: " << systemNum << std::endl;
	//***

	std::vector<bool> check_vec;

	// surfaces E10
	ApertureStopElement AperStop0_E10(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E10(/*radius*/ 25.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere2_E10(/*radius*/ 30.00, /*semi height*/7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF6_S1(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere3_E10(/*radius*/ 25.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
	PlanElement Plan4_E10(/*semi height*/ 100.0, /*point*/{ 0.0,0.0,75.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	
	Sphere1_E10.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2_E10.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere3_E10.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	
	surfacePtr Aper0_E10_ptr = AperStop0_E10.clone();
	surfacePtr Sphere1_E10_ptr = Sphere1_E10.clone();
	surfacePtr Sphere2_E10_ptr = Sphere2_E10.clone();
	surfacePtr Sphere3_E10_ptr = Sphere3_E10.clone();
	surfacePtr Plan4_E10_ptr = Plan4_E10.clone();
	
	std::vector<surfacePtr> opticalSystemE10_ptr{ Aper0_E10_ptr, Sphere1_E10_ptr, Sphere2_E10_ptr , Sphere3_E10_ptr, Plan4_E10_ptr };
	std::vector<interactionPtr> interactionsE10_ptr{ mDoNothing.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSystemElement_E10(opticalSystemE10_ptr, interactionsE10_ptr);
	
	// check the start system
	std::vector<real> rmsStartSystem_Z{ 533.850,529.486,516.527 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E10, mFields_vec012, mWavelength_FdC_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);
	
	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E10,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_FdC_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParaGenetic_rayTracing_ON, /*default DLS*/ mDefaultParamDLS_rayTracing_ON);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();
	
	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_FdC_vec[0]);
	
	std::vector<real> rmsOpti_Z{ 23.485,27.538,45.055 }; // sum 96.078
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_FdC_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

// E11 _rms
bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE11_GeneticAndDLS_rms()
{
	std::vector<bool> test_E11_vec;

	// surfaces _E11
	SphericalElement Sphere0_E11(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere1_E11(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere2_E11(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	ApertureStopElement AperStop3_E11(/* semi height*/1.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan4_E11(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere0_E11.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere1_E11.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2_E11.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);


	surfacePtr Sphere0_E11_ptr = Sphere0_E11.clone();
	surfacePtr Sphere1_E11_ptr = Sphere1_E11.clone();
	surfacePtr Sphere2_E11_ptr = Sphere2_E11.clone();
	surfacePtr Aper3_E11_ptr = AperStop3_E11.clone();
	surfacePtr Plan4_E11_ptr = Plan4_E11.clone();

	std::vector<surfacePtr> opticalSystem_E11_ptr{ Sphere0_E11_ptr , Sphere1_E11_ptr, Sphere2_E11_ptr, Aper3_E11_ptr,  Plan4_E11_ptr };
	std::vector<interactionPtr> interactions_E11_ptr{ mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mDoNothing.clone(),mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E11(opticalSystem_E11_ptr, interactions_E11_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system _E11" << std::endl;
	oftenUse::print(optSystemElement_E11, mWave587);

	// check the start system
	std::vector<real> rmsStartSystem_Z{ 172.542,169.394,160.077 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E11, mAngleX_000_vec, mAngleY_012_vec, mWavelength_FdC_vec, rmsStartSystem_Z, 0.1, compareTOM_Zemax::comEqual);
	test_E11_vec.push_back(checkStartSys);

	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E11, /*fields X*/ mAngleX_000_vec, /*fields Y*/ mAngleY_012_vec, /*wavelength*/ mWavelength_FdC_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*target cardinal points*/ m_NO_targetCarPoint, /*default Genetic*/ mDefaultParaGenetic_rayTracing_ON, /*default DLS*/ mDefaultParamDLS_rayTracing_ON);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();

	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_FdC_vec[0]);

	std::vector<real> rmsOpti_Z{ 29.190,40.285,79.644 }; // sum 149,119
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), /*fields X*/ mAngleX_000_vec, /*fields Y*/ mAngleY_012_vec, mWavelength_FdC_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	test_E11_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(test_E11_vec);
	return checker;

}

// E12 _rms
bool testOptimizeSystemSuperFct_GeneticAndDLS ::checkE12_GeneticAndDLS_rms()
{
	std::vector<bool> test_E12_vec;

	// surfaces _E12
	SphericalElement Sphere0_E12(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere1_E12(/*radius*/ 80.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere2_E12(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	ApertureStopElement AperStop3_E12(/* semi height*/1.5, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere4_E12(/*radius*/ 100.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF11_S1());
	SphericalElement Sphere5_E12(/*radius*/ 100.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF6_S1(), /*refractive index B*/glasses.getSF11_S1());
	SphericalElement Sphere6_E12(/*radius*/ 100.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF6_S1(), /*refractive index B*/glasses.getAir());
	PlanElement Plan7_E12(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere0_E12.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2_E12.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere4_E12.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere6_E12.setParameterPointZ(5.0, 30.0, 0.0, typeModifierVariable);


	surfacePtr Sphere0_E12_ptr = Sphere0_E12.clone();
	surfacePtr Sphere1_E12_ptr = Sphere1_E12.clone();
	surfacePtr Sphere2_E12_ptr = Sphere2_E12.clone();
	surfacePtr Aper3_E12_ptr = AperStop3_E12.clone();
	surfacePtr Sphere4_E12_ptr = Sphere4_E12.clone();
	surfacePtr Sphere5_E12_ptr = Sphere5_E12.clone();
	surfacePtr Sphere6_E12_ptr = Sphere6_E12.clone();
	surfacePtr Plan7_E12_ptr = Plan7_E12.clone();

	std::vector<surfacePtr> opticalSystem_E12_ptr{ Sphere0_E12_ptr , Sphere1_E12_ptr, Sphere2_E12_ptr, Aper3_E12_ptr, Sphere4_E12_ptr, Sphere5_E12_ptr, Sphere6_E12_ptr,  Plan7_E12_ptr };
	std::vector<interactionPtr> interactions_E12_ptr{ mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mDoNothing.clone(),mRefrac.clone(),mRefrac.clone(),mRefrac.clone(),mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E12(opticalSystem_E12_ptr, interactions_E12_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system _E12" << std::endl;
	oftenUse::print(optSystemElement_E12, mWave587);

	// check the start system
	std::vector<real> rmsStartSystem_Z{ 80.182,81.547,85.672 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E12, mAngleX_000_vec, mAngleY_012_vec, mWavelength_FdC_vec, rmsStartSystem_Z, 0.1, compareTOM_Zemax::comEqual);
	test_E12_vec.push_back(checkStartSys);

	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E12, /*fields X*/ mAngleX_000_vec, /*fields Y*/ mAngleY_012_vec, /*wavelength*/ mWavelength_FdC_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*target cardinal points*/ m_NO_targetCarPoint, /*default Genetic*/ mDefaultParaGenetic_rayTracing_ON, /*default DLS*/ mDefaultParamDLS_rayTracing_ON);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();

	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_FdC_vec[0]);

	std::vector<real> rmsOpti_Z{ 7.633,8.860,12.429 }; // sum 28.922
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(),  /*fields X*/ mAngleX_000_vec, /*fields Y*/ mAngleY_012_vec, mWavelength_FdC_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	test_E12_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(test_E12_vec);
	return checker;
}


//E0 _cardinalPoints
bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE0_GeneticAndDLS_cardinalPoints()
{
	//***
	unsigned int systemNum = 0;
	std::cout << "check optimize system genetic and DLS system number: " << systemNum << std::endl;
	//***

	std::vector<bool> check_vec;

	// surfaces E0
	ApertureStopElement AperStop0_E0(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E0(/*radius*/ 25.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2_E0(/*radius*/ 25.00, /*semi height*/7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF11_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3_E0(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF11_S1());
	SphericalElement Sphere4_E0(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF4_S1());
	SphericalElement Sphere5_E0(/*radius*/ 70.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF4_S1());
	SphericalElement Sphere6_E0(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere7_E0(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere8_E0(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	PlanElement Plan9_E0(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,80.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere3_E0.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere5_E0.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere7_E0.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);

	surfacePtr Aper0_E0_ptr = AperStop0_E0.clone();
	surfacePtr Sphere1_E0_ptr = Sphere1_E0.clone();
	surfacePtr Sphere2_E0_ptr = Sphere2_E0.clone();
	surfacePtr Sphere3_E0_ptr = Sphere3_E0.clone();
	surfacePtr Sphere4_E0_ptr = Sphere4_E0.clone();
	surfacePtr Sphere5_E0_ptr = Sphere5_E0.clone();
	surfacePtr Sphere6_E0_ptr = Sphere6_E0.clone();
	surfacePtr Sphere7_E0_ptr = Sphere7_E0.clone();
	surfacePtr Sphere8_E0_ptr = Sphere8_E0.clone();
	surfacePtr Plan9_E0_ptr = Plan9_E0.clone();

	std::vector<surfacePtr> opticalSystemE0_ptr{ Aper0_E0_ptr, Sphere1_E0_ptr, Sphere2_E0_ptr , Sphere3_E0_ptr, Sphere4_E0_ptr, Sphere5_E0_ptr, Sphere6_E0_ptr, Sphere7_E0_ptr, Sphere8_E0_ptr, Plan9_E0_ptr };
	std::vector<interactionPtr> interactionsE0_ptr{ mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSysEle_E0(opticalSystemE0_ptr, interactionsE0_ptr);

	// check the start system
	std::vector<real> rmsStartSystem_Z{ 196.503,192.101,179.353 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E0, mFields_vec012, mWavelength_FdC_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);

	// check start cardinal points
	real ref_EFFL = 24.8281;
	real targetEFFL = 30.0;
	// **
	real ref_PP_obj = 37.593750;
	real ref_PP_ima = -39.563715;
	// **
	real ref_Mag = -0.758;
	real targetPMAG = -1.0;
	real ref_WFNO = 7.570;
	real targetWFNO = 9.0;
	real ref_ENPP = 0.0;
	real targetENPP = 0.0;
	real ref_EXPP = 33.553;
	real targetEXPP = 35.0;
	real ref_EXPD = 3.890;
	real targetEXPD = 4.5;

	CardinalPoints carPointsE0(optSysEle_E0, mWavelength_FdC_vec[0], objectPoint_inf_obj::obj);
	real calc_EFFL = carPointsE0.getEFL();
	real calc_PP_obj = carPointsE0.getPP_obj();
	real calc_PP_ima = carPointsE0.getPP_ima();
	real calc_Mag = carPointsE0.getMagnification();
	real calc_WFNO = carPointsE0.getWorkingFnumber();
	real calc_ENPP = carPointsE0.getENPP_firstSurface();
	real calc_EXPP = carPointsE0.getEXPP_lastSurface();
	real calc_EXPD = carPointsE0.getEXPD();

	bool checkEFFL = Math::compareTwoNumbers_tolerance(ref_EFFL, calc_EFFL, 0.1);
	check_vec.push_back(checkEFFL);
	bool checkPP_obj = Math::compareTwoNumbers_tolerance(ref_PP_obj, calc_PP_obj, 0.1);
	check_vec.push_back(checkPP_obj);
	bool checkPP_ima = Math::compareTwoNumbers_tolerance(ref_PP_ima, calc_PP_ima, 0.1);
	check_vec.push_back(checkPP_ima);
	bool checkMag = Math::compareTwoNumbers_tolerance(ref_Mag, calc_Mag, 0.1);
	check_vec.push_back(checkMag);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(ref_WFNO, calc_WFNO, 0.1);
	check_vec.push_back(checkWFNO);
	bool checkENPP = Math::compareTwoNumbers_tolerance(ref_ENPP, calc_ENPP, 0.1);
	check_vec.push_back(checkENPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(ref_EXPP, calc_EXPP, 0.1);
	check_vec.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(ref_EXPD, calc_EXPD, 0.1);
	check_vec.push_back(checkEXPD);

	targetCardinalPointsStruct targetCarPoints;
	targetCarPoints.setTargetEFL(targetEFFL);
	targetCarPoints.setTargetMag(targetPMAG);
	targetCarPoints.setTargetWFNO(targetWFNO);
	targetCarPoints.setTargetENPP_firstSurface(targetENPP);
	targetCarPoints.setTargetEXPP_lastSurface(targetEXPP);
	targetCarPoints.setTargetEXPD(targetEXPD);

	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSysEle_E0,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_FdC_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*target cardinal points*/ targetCarPoints, /*default Genetic*/ mDefaultParaGenetic_rayTracing_OFF, /*default DLS*/ mDefaultParamDLS_rayTracing_OFF);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();

	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_FdC_vec[0]);

	// optimized system
	OpticalSystemElement optimizedOpticalSystem = GeneticAndDLS.getOptimizedOpticalSystem();
	CardinalPoints optiCarPoints(optimizedOpticalSystem, mWavelength_FdC_vec[0], GeneticAndDLS.getObjPoint_inf_obj());
	
	// EFFL
	real opti_EFFL = optiCarPoints.getEFL();
	bool checkOptiEFL = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ calc_EFFL, /*optimized value*/ opti_EFFL, /*target val*/ targetEFFL);
	check_vec.push_back(checkOptiEFL);

	// Mag
	real opti_Mag = optiCarPoints.getMagnification();
	bool checkOptiMag = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ calc_Mag, /*optimized value*/ opti_Mag, /*target val*/ targetPMAG);
	check_vec.push_back(checkOptiMag);

	// WFNO
	real opti_WFNO = optiCarPoints.getWorkingFnumber();
	bool checkOptiWFNO = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ calc_WFNO, /*optimized value*/ opti_WFNO, /*target val*/ targetWFNO);
	check_vec.push_back(checkOptiWFNO);

	// ENPP
	real opti_ENPP = optiCarPoints.getENPP_firstSurface();
	bool checkOptiENPP = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ calc_ENPP, /*optimized value*/ opti_ENPP, /*target val*/ targetENPP);
	check_vec.push_back(checkOptiENPP);

	// EXPP
	real opti_EXPP = optiCarPoints.getEXPP_lastSurface();
	bool checkOptiEXPP = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ calc_EXPP, /*optimized value*/ opti_EXPP, /*target val*/ targetEXPP);
	check_vec.push_back(checkOptiEXPP);

	// EXPD
	real opti_EXPD = optiCarPoints.getEXPD();
	bool checkOptiEXPD = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ calc_EXPD, /*optimized value*/ opti_EXPD, /*target val*/ targetEXPD);
	check_vec.push_back(checkOptiEXPD);

	// ** compare the results ** //
	// surfaces E0
	ApertureStopElement AperStop0_E0_compare(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E0_compare(/*radius*/ 25.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2_E0_compare(/*radius*/ 25.00, /*semi height*/7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF11_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3_E0_compare(/*radius*/ 14.200, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF11_S1());
	SphericalElement Sphere4_E0_compare(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF4_S1());
	SphericalElement Sphere5_E0_compare(/*radius*/ 59.197, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNSF4_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere6_E0_compare(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere7_E0_compare(/*radius*/ 7.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere8_E0_compare(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	PlanElement Plan9_E0_compare(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,80.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	surfacePtr Aper0_E0_compare_ptr = AperStop0_E0_compare.clone();
	surfacePtr Sphere1_E0_compare_ptr = Sphere1_E0_compare.clone();
	surfacePtr Sphere2_E0_compare_ptr = Sphere2_E0_compare.clone();
	surfacePtr Sphere3_E0_compare_ptr = Sphere3_E0_compare.clone();
	surfacePtr Sphere4_E0_compare_ptr = Sphere4_E0_compare.clone();
	surfacePtr Sphere5_E0_compare_ptr = Sphere5_E0_compare.clone();
	surfacePtr Sphere6_E0_compare_ptr = Sphere6_E0_compare.clone();
	surfacePtr Sphere7_E0_compare_ptr = Sphere7_E0_compare.clone();
	surfacePtr Sphere8_E0_compare_ptr = Sphere8_E0_compare.clone();
	surfacePtr Plan9_E0_compare_ptr = Plan9_E0_compare.clone();

	std::vector<surfacePtr> opticalSystem_E0_compare_ptr{ Aper0_E0_compare_ptr, Sphere1_E0_compare_ptr, Sphere2_E0_compare_ptr , Sphere3_E0_compare_ptr, Sphere4_E0_compare_ptr, Sphere5_E0_compare_ptr, Sphere6_E0_compare_ptr, Sphere7_E0_compare_ptr, Sphere8_E0_compare_ptr, Plan9_E0_compare_ptr };
	std::vector<interactionPtr> interactions_E0_compare_ptr{ mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSysEle_E0_ref(opticalSystem_E0_compare_ptr, interactions_E0_compare_ptr);
	// ** compare the results ** //

	// **
	targetCardinalPointsStruct checkTargetCarPoints_ref = targetCarPoints;
	std::vector<real> checkTargetCarPoints_vector_ref;
	checkTargetCarPoints_vector_ref.resize(targetCarPoints.getNumerOfTargets());
	optSysEle_E0_ref.setRefractiveIndexAccordingToWavelength(mWavelength_FdC_vec[0]);
	checkTargetCarPoints_ref.calcualteMeritVal_targetCardinalPoints_forDLS(optSysEle_E0_ref.getOptSys_LLT_buildSystem(), GeneticAndDLS.getObjPoint_inf_obj(), checkTargetCarPoints_vector_ref);
	// **

	// **
	targetCardinalPointsStruct checkTargetCarPoints_tom = targetCarPoints;
	std::vector<real> checkTargetCarPoints_vector_tom;
	checkTargetCarPoints_vector_tom.resize(targetCarPoints.getNumerOfTargets());
	optimizedOpticalSystem.setRefractiveIndexAccordingToWavelength(mWavelength_FdC_vec[0]);
	checkTargetCarPoints_tom.calcualteMeritVal_targetCardinalPoints_forDLS(optimizedOpticalSystem.getOptSys_LLT_buildSystem(), GeneticAndDLS.getObjPoint_inf_obj(), checkTargetCarPoints_vector_tom);
	// **

	real sum_ref = Math::sumAllVectorValues_abs(checkTargetCarPoints_vector_ref);
	real sum_tom = Math::sumAllVectorValues_abs(checkTargetCarPoints_vector_tom);

	bool checkBetter = sum_tom <= sum_ref;
	check_vec.push_back(checkBetter);

	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}