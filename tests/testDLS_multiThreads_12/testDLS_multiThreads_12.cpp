#include "testDLS_multiThreads_12.h"

#include "..\..\OptimizeSystem\multiThreads\DLS_mulitThreads12.h"

// element surfaces
#include "..\..\SurfaceElements\ApertureStopElement.h"
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\PlanElement.h"

// often use
#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

testDLS_multiThreads_12::testDLS_multiThreads_12() { loadImportantStuff(); }

testDLS_multiThreads_12::~testDLS_multiThreads_12(){}

typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

// load important stuff
void testDLS_multiThreads_12::loadImportantStuff()
{
	mMinTolerance = 0.1;
	mExtendeTolerance = 10.0;
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
	mDefaultParamDLS.set_Min_DamNumBefSwitchFactors(0.00001);
	mDefaultParamDLS.set_Max_DamNumBefSwitchFactors(9999.0);

	mRings = 6;
	mArms = 8;

}

// test super function
bool testDLS_multiThreads_12::testSuperFunction()
{
	std::vector<bool> testDLS_multiThreads_12;

	// check example E0
	bool cE0 = checkE0();
	testDLS_multiThreads_12.push_back(cE0);



	bool returnChecker = Math::checkTrueOfVectorElements(testDLS_multiThreads_12);
	return returnChecker;
}



// E0
bool testDLS_multiThreads_12::checkE0()
{
	//***
	unsigned int systemNum = 0;
	std::cout << "check DLS multi threads 12 " << systemNum << std::endl;
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
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E0, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mMinTolerance, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);

	DLS_multiThreads_12 DLS_multi_12(optSysEle_E0, mFields_vec012, mWavelength_vec, mRings, mArms, mDefaultParamDLS);
	OpticalSystemElement optimizedSyste_E0 = DLS_multi_12.DLS_optimisation_multiThreads_12();

	std::vector<real> rmsOpti_Z{ 17.240,22.200,35.897 }; // sum 75.337
	bool checkOptimizedSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optimizedSyste_E0, mFields_vec012, mWavelength_vec, rmsOpti_Z, mExtendeTolerance, compareTOM_Zemax::comBetter);
	check_vec.push_back(checkOptimizedSys);

	bool checker = Math::checkTrueOfVectorElements(check_vec);

	return checker;
}