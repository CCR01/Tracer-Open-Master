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

testOptimizeSystemSuperFct_GeneticAndDLS::testOptimizeSystemSuperFct_GeneticAndDLS() { loadImportantStuff(); }

testOptimizeSystemSuperFct_GeneticAndDLS::~testOptimizeSystemSuperFct_GeneticAndDLS() {}

typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

// load important stuff
void testOptimizeSystemSuperFct_GeneticAndDLS::loadImportantStuff()
{
	mTolerance = 10.0;
	glasses.loadGlassCatalog_Schott();

	//  wave
	mWave587 = 587.5618;
	mWave486 = 486.1327;
	mWave656 = 656.2725;
	mWavelength_vec = { mWave587 , mWave486, mWave656 };

	// field
	mField0 = { 0.0,0.0,0.0 };
	mField1 = { 0.0,1.0,0.0 };
	mField2 = { 0.0,2.0,0.0 };
	mField3 = { 0.0,3.0,0.0 };
	mField4 = { 0.0,4.0,0.0 };

	mFields_vec012 = { mField0, mField1, mField2 };
	mFields_vec024 = { mField0, mField2, mField4 };

	// load defaul parameters for genetic
	mDefaultParaGenetic.setStartRefIndex(1.0);
	mDefaultParaGenetic.setToleranceWithoutMIN(-0.5);
	mDefaultParaGenetic.setToleranceWithoutMAX(0.5);
	mDefaultParaGenetic.setMaxInterationGenetic(3);
	mDefaultParaGenetic.setDeltaMeritValueStop(0.1);
	mDefaultParaGenetic.setToleranceForEvaluation(0.001);
	mDefaultParaGenetic.setChooseValueMode(normalDistributionDefaultMode);
	mDefaultParaGenetic.set_ON_CheckRMS_rayTracing();

	// load defaul parameters for DLS
	mDefaultParamDLS.setDampingFactor(5.0);
	mDefaultParamDLS.setFactorRadiusDeviation(0.000001);
	mDefaultParamDLS.setFactorPositionDeviation(0.000001);
	mDefaultParamDLS.setStartRefractivIndex(1.0);
	mDefaultParamDLS.setMaxWorstCounter(300);
	mDefaultParamDLS.setImproveMeritStopDiff(0.00000001);
	mDefaultParamDLS.setMaxInterations(500);
	mDefaultParamDLS.setFlipOrientationRadius(1000.0);
	mDefaultParamDLS.setMaxBorderViolations(5);
	mDefaultParamDLS.setMaxDeltaParameter(25.0);
	mDefaultParamDLS.setMinDeltaParameter(0.00000001);
	mDefaultParamDLS.setFactorGettingBetter(0.4);
	mDefaultParamDLS.setFactorGettingWorst(1.9);
	mDefaultParamDLS.setToleranceWithoutMin(0.0);
	mDefaultParamDLS.setToleranceWithoutMax(0.0);
	mDefaultParamDLS.set_Min_DamNumBefSwitchFactors(0.00001);
	mDefaultParamDLS.set_Max_DamNumBefSwitchFactors(9999.0);

	mRings = 6;
	mArms = 8;

	// debug
	// mPopulation = 50;
	mPopulation = 1000.0;
}

bool testOptimizeSystemSuperFct_GeneticAndDLS::testOptimizeSystemSysSupFct_GeneticDLS()
{
	std::vector<bool> workTheOptimizerSuperFct;
	
	//// E0
	//bool checkE0 = checkE0_optSysSupFct_GeneticAndDLS();
	//workTheOptimizerSuperFct.push_back(checkE0);
	//
	//// E1
	//bool checkE1 = checkE1_optSysSupFct_GeneticAndDLS();
	//workTheOptimizerSuperFct.push_back(checkE1);
	//
	//// E2
	//bool checkE2 = checkE2_optSysSupFct_GeneticAndDLS();
	//workTheOptimizerSuperFct.push_back(checkE2);
	//
	//// E3
	//bool checkE3 = checkE3_optSysSupFct_GeneticAndDLS();
	//workTheOptimizerSuperFct.push_back(checkE3);
	//
	//// E4
	//bool checkE4 = checkE4_optSysSupFct_GeneticAndDLS();
	//workTheOptimizerSuperFct.push_back(checkE4);
	//
	//// E5
	//bool checkE5 = checkE5_optSysSupFct_GeneticAndDLS();
	//workTheOptimizerSuperFct.push_back(checkE5);
	//
	//// E6
	//bool checkE6 = checkE6_optSysSupFct_GeneticAndDLS();
	//workTheOptimizerSuperFct.push_back(checkE6);
	
	//// E7
	//bool checkE7 = checkE7_optSysSupFct_GeneticAndDLS();
	//workTheOptimizerSuperFct.push_back(checkE7);
	
	//// E8
	//bool checkE8 = checkE8_optSysSupFct_GeneticAndDLS();
	//workTheOptimizerSuperFct.push_back(checkE8);
	
	//// E9
	//bool checkE9 = checkE9_optSysSupFct_GeneticAndDLS();
	//workTheOptimizerSuperFct.push_back(checkE9);
	//
	// E10
	bool checkE10 = checkE10_optSysSupFct_GeneticAndDLS();
	workTheOptimizerSuperFct.push_back(checkE10);


	bool returnChecker = Math::checkTrueOfVectorElements(workTheOptimizerSuperFct);

	return returnChecker;
}


bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE0_optSysSupFct_GeneticAndDLS()
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
	std::vector<interaction_ptr> interactionsE0_ptr{ doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSysEle_E0(opticalSystemE0_ptr, interactionsE0_ptr);
	
	// check the start system
	std::vector<real> rmsStartSystem_Z{ 196.503,192.101,179.353 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E0, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);
	
	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSysEle_E0,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParaGenetic, /*default DLS*/ mDefaultParamDLS);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();

	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_vec[0]);

	std::vector<real> rmsOpti_Z{ 17.240,22.200,35.897 }; // sum 75.337
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);
	
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;

}

bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE1_optSysSupFct_GeneticAndDLS()
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
	std::vector<interaction_ptr> interactionsE1_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E1(opticalSystemE1_ptr, interactionsE1_ptr);

	// check the start system
	std::vector<real> rmsStartSystem_Z{ 77.542,87.021,113.632 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E1, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);

	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E1,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParaGenetic, /*default DLS*/ mDefaultParamDLS);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();

	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_vec[0]);

	std::vector<real> rmsOpti_Z{ 20.872,28.502,50.817 }; // sum 100.191
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

//E2
bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE2_optSysSupFct_GeneticAndDLS()
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
	std::vector<interaction_ptr> interactionsE2_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E2(opticalSystemE2_ptr, interactionsE2_ptr);

	// check the start system
	std::vector<real> rmsStartSystem_Z{ 32.135,40.076,59.620 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E2, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);
	
	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E2,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParaGenetic, /*default DLS*/ mDefaultParamDLS);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();
	
	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_vec[0]);
	
	std::vector<real> rmsOpti_Z{ 17.621,20.095,27.465 }; // sum 65.181
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

//E3
bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE3_optSysSupFct_GeneticAndDLS()
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
	std::vector<interaction_ptr> interactionsE3_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSystemElement_E3(opticalSystemE3_ptr, interactionsE3_ptr);
	
	// check the start system
	std::vector<real> rmsStartSystem_Z{ 324.164,307.127,261.495 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E3, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);
		
	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E3,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParaGenetic, /*default DLS*/ mDefaultParamDLS);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();
	
	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_vec[0]);
	
	std::vector<real> rmsOpti_Z{ 45.330,56.613,117.711 }; // sum 219.654
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}


//E4
bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE4_optSysSupFct_GeneticAndDLS()
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
	std::vector<interaction_ptr> interactionsE4_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),absorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSystemElement_E4(opticalSystemE4_ptr, interactionsE4_ptr);
	
	// check the start system
	std::vector<real> rmsStartSystem_Z{ 269.294,260.916,238.140 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E4, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);
		
	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E4,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParaGenetic, /*default DLS*/ mDefaultParamDLS);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();
	
	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_vec[0]);
	
	std::vector<real> rmsOpti_Z{ 42.453,54.593,85.239 }; // sum 182.285
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}


//E5
bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE5_optSysSupFct_GeneticAndDLS()
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
	std::vector<interaction_ptr> interactionsE5_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),absorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSystemElement_E5(opticalSystemE5_ptr, interactionsE5_ptr);
	
	// check the start system
	std::vector<real> rmsStartSystem_Z{ 221.602,215.043,196.523 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E5, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);
		
	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E5,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation /*1000*/, /*default Genetic*/ mDefaultParaGenetic, /*default DLS*/ mDefaultParamDLS);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();
	
	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_vec[0]);
	
	std::vector<real> rmsOpti_Z{ 7.975,8.719,10.737 }; // sum 27.431
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}


//E6
bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE6_optSysSupFct_GeneticAndDLS()
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
	std::vector<interaction_ptr> interactionsE6_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), absorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSystemElement_E6(opticalSystemE6_ptr, interactionsE6_ptr);
	
	// check the start system
	std::vector<real> rmsStartSystem_Z{ 1032.04,981.987,859.466 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E6, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);
		
	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E6,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParaGenetic, /*default DLS*/ mDefaultParamDLS);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();
	
	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_vec[0]);
	
	std::vector<real> rmsOpti_Z{ 180.933,274.871,522.848 }; // sum 978.652
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}


//E7
bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE7_optSysSupFct_GeneticAndDLS()
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
	std::vector<interaction_ptr> interactionsE7_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), absorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSystemElement_E7(opticalSystemE7_ptr, interactionsE7_ptr);
	
	// check the start system
	std::vector<real> rmsStartSystem_Z{ 102.085,125.210,184.717 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E7, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);
	
	
	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E7,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParaGenetic, /*default DLS*/ mDefaultParamDLS);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();
	
	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_vec[0]);
	
	std::vector<real> rmsOpti_Z{ 64.942,77.548,114.383 }; // sum 256,873
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}


//E8
bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE8_optSysSupFct_GeneticAndDLS()
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
	std::vector<interaction_ptr> interactionsE8_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),absorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSystemElement_E8(opticalSystemE8_ptr, interactionsE8_ptr);
	
	
	// check the start system
	std::vector<real> rmsStartSystem_Z{ 318.440,307.550,278.838 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E8, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);
	
	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E8,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParaGenetic, /*default DLS*/ mDefaultParamDLS);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();
	
	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_vec[0]);
	
	std::vector<real> rmsOpti_Z{ 58.661,73.741,118.741 }; // sum 251.143
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}


//E9
bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE9_optSysSupFct_GeneticAndDLS()
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
	std::vector<interaction_ptr> interactionsE9_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),absorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSystemElement_E9(opticalSystemE9_ptr, interactionsE9_ptr);
	
	// check the start system
	std::vector<real> rmsStartSystem_Z{ 1285.00,1251.18,1153.43 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E9, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);
		
	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E9,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParaGenetic, /*default DLS*/ mDefaultParamDLS);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();
	
	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_vec[0]);
	
	std::vector<real> rmsOpti_Z{ 66.259,113.022,229.296 }; // sum 408,577
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}


//E10
bool testOptimizeSystemSuperFct_GeneticAndDLS::checkE10_optSysSupFct_GeneticAndDLS()
{
	mDefaultParamDLS.setToleranceWithoutMax(0.0);
	mDefaultParamDLS.setToleranceWithoutMin(0.0);

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
	std::vector<interaction_ptr> interactionsE10_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), absorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSystemElement_E10(opticalSystemE10_ptr, interactionsE10_ptr);
	
	// check the start system
	std::vector<real> rmsStartSystem_Z{ 533.850,529.486,516.527 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E10, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);
	
	// optimization
	OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ optSystemElement_E10,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ mPopulation, /*default Genetic*/ mDefaultParaGenetic, /*default DLS*/ mDefaultParamDLS);
	GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();
	
	// print the optical system
	oftenUse::print(GeneticAndDLS.getOptimizedOpticalSystem(), mWavelength_vec[0]);
	
	std::vector<real> rmsOpti_Z{ 23.485,27.538,45.055 }; // sum 96.078
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(GeneticAndDLS.getOptimizedOpticalSystem(), mFields_vec012, mWavelength_vec, rmsOpti_Z, mTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}
