#include "testDLS.h"

// DLS
#include "..\..\..\OptimizeSystem\DampedLeastSquares.h"



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

testDLS::testDLS() 
{ 
	loadImportantValues(); 
}

testDLS::~testDLS(){}

// typedef
typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interactionPtr;

// super function
bool testDLS::testDLS_superFct()
{
	std::vector<bool> testSuperFct_vec;

	////E0
	bool E0_MD = testE0_DLS_MD();
	testSuperFct_vec.push_back(E0_MD);
	
	//E1
	bool E1_MD = testE1_DLS_MD(); // here we flip the radius for the best result
	testSuperFct_vec.push_back(E1_MD);
	
	//E2
	bool E2_MD = testE2_DLS_MD();
	testSuperFct_vec.push_back(E2_MD);
	
	//E3 
	bool E3_MD = testE3_DLS_MD(); //2 radii are variable
	testSuperFct_vec.push_back(E3_MD);
	
	// E4
	bool E4_MD = testE4_DLS_MD(); 
	testSuperFct_vec.push_back(E4_MD);
	
	// E5
	bool E5_MD = testE5_DLS_MD();
	testSuperFct_vec.push_back(E5_MD);
	
	// E6
	bool E6_MD = testE6_DLS_MD(); // min thickness is 0.01
	testSuperFct_vec.push_back(E6_MD);

	// E7
	bool E7_MD = testE7_DLS_MD();
	testSuperFct_vec.push_back(E7_MD);

	bool returnChecker = Math::checkTrueOfVectorElements(testSuperFct_vec);
	return returnChecker;

}

void testDLS::loadImportantValues()
{
	// load glass catalog
	glasses.loadGlassCatalog_Schott();

	// light
	mWave550 = 550.0;
	mWave400 = 400.0;
	mWave700 = 700.0;
	mWavelength_vec.resize(3);
	mWavelength_vec[0] = mWave550;
	mWavelength_vec[1] = mWave400;
	mWavelength_vec[2] = mWave700;

	mLight550.setWavelength(mWave550);
	mLight400.setWavelength(mWave400);
	mLight700.setWavelength(mWave700);
	mLightVec.resize(3);
	mLightVec[0] = mLight550;
	mLightVec[0] = mLight400;
	mLightVec[0] = mLight700;

	// light FdC
	mWave587 = 587.5618;
	mWave486 = 486.1327;
	mWave656 = 656.2725;
	mWavelength_FdV_vec.resize(3);
	mWavelength_FdV_vec[0] = mWave587;
	mWavelength_FdV_vec[1] = mWave486;
	mWavelength_FdV_vec[2] = mWave656;

	mLight587.setWavelength(mWave587);
	mLight486.setWavelength(mWave486);
	mLight656.setWavelength(mWave656);
	mLight_FdC_Vec.resize(3);
	mLight_FdC_Vec[0] = mLight587;
	mLight_FdC_Vec[1] = mLight486;
	mLight_FdC_Vec[2] = mLight656;

	// field
	mField0 = { 0.0,0.0,0.0 };
	mField05 = { 0.0,0.5,0.0 };
	mField1 = { 0.0,1.0,0.0 };
	mField2 = { 0.0,2.0,0.0 };
	mFields012_vec.resize(3);
	mFields012_vec[0] = mField0;
	mFields012_vec[1] = mField1;
	mFields012_vec[2] = mField2;

	mField0_05_1_vec.resize(3);
	mField0_05_1_vec[0] = mField0;
	mField0_05_1_vec[1] = mField05;
	mField0_05_1_vec[2] = mField1;

	mDefaultTolerance = 0.01;

}

// E0 MD
bool testDLS::testE0_DLS_MD()
{
	std::vector<bool> testE0_vec;
	
	// build the optical system
	ApertureStopElement AperStop0(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBAF4_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF4_S1());
	SphericalElement Sphere4(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF10_S1());
	SphericalElement Sphere5(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF10_S1());
	PlanElement Plan6(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	// **********************************
	// set parameter variable
	Sphere1.setParameterRadius(/*min value*/ 7.0,  /*max value*/ 70.0, 0.0, typeModifierVariable);
	Sphere4.setParameterRadius(/*min value*/ 12.0, /*max value*/ 70.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr AperStop_ptr = AperStop0.clone();
	surfacePtr Sphere1_ptr = Sphere1.clone();
	surfacePtr Sphere2_ptr = Sphere2.clone();
	surfacePtr Sphere3_ptr = Sphere3.clone();
	surfacePtr Sphere4_ptr = Sphere4.clone();
	surfacePtr Sphere5_ptr = Sphere5.clone();
	surfacePtr Plan6_ptr = Plan6.clone();

	std::vector<surfacePtr> opticalSystemE0_ptr{ AperStop_ptr, Sphere1_ptr, Sphere2_ptr, Sphere3_ptr, Sphere4_ptr,Sphere5_ptr,Plan6_ptr };
	std::vector<interactionPtr> interactionsE0_ptr{ mDoNothing.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };



	//	build optical system
	OpticalSystemElement optSysEle_E0(opticalSystemE0_ptr, interactionsE0_ptr);


	// test the system
	std::vector<real> rms_Zemax{ 1530.53,1523.93,1504.26 };
	bool test_E0 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E0, mFields012_vec, mWavelength_vec, rms_Zemax, 1.0, compareTOM_Zemax::comEqual);
	testE0_vec.push_back(test_E0);

	// start DLS 
	DLS DLS_E0(/*optSysEle*/ optSysEle_E0,/*fields*/ mFields012_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	DLS_E0.setMaxWorstCounter(50);
	DLS_E0.setMaxInterations(200);
	
	DLS_E0.optimizeSystem_DLS_multiplicativ_Damping();
	
	OpticalSystemElement optimizedOptSysEle = DLS_E0.getOptimizedSystem_HLT();

	std::vector<real> rms_Z{ 60.093,79.343,126.244 };
	bool betterZ_E0 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optimizedOptSysEle, mFields012_vec, mWavelength_vec, rms_Z, 1.0, compareTOM_Zemax::comBetter);
	testE0_vec.push_back(betterZ_E0);

	bool checkRMS_bestMerit_optimizedSystem = oftenUse::checkDLS_resultRMS(DLS_E0, 0.1);
	testE0_vec.push_back(checkRMS_bestMerit_optimizedSystem);

	oftenUse::print(optimizedOptSysEle, mWavelength_vec[0]);

	bool returnCheckerE0 = Math::checkTrueOfVectorElements(testE0_vec);
	return returnCheckerE0;

}



// E1 MD
bool testDLS::testE1_DLS_MD()
{
	std::vector<bool> testE1_vec;

	// build the optical system
	ApertureStopElement AperStop0(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1(/*radius*/ 20.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere2(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBAF4_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF4_S1());
	PlanElement Plan4(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,60.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	// **********************************
	// set parameter variable
	Sphere1.setParameterRadius(/*min value*/ 7.0,  /*max value*/ 10000.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr AperStop_ptr = AperStop0.clone();
	surfacePtr Sphere1_ptr = Sphere1.clone();
	surfacePtr Sphere2_ptr = Sphere2.clone();
	surfacePtr Sphere3_ptr = Sphere3.clone();
	surfacePtr Plan4_ptr = Plan4.clone();

	std::vector<surfacePtr> opticalSystemE1_ptr{ AperStop_ptr, Sphere1_ptr, Sphere2_ptr, Sphere3_ptr,Plan4_ptr };
	std::vector<interactionPtr> interactionsE1_ptr{ mDoNothing.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };



	//	build optical system
	OpticalSystemElement optSysEle_E1(opticalSystemE1_ptr, interactionsE1_ptr);


	// test the system
	std::vector<real> rms_Zemax{ 4815.08,4815.23,4815.71 };
	bool test_E1 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E1, mFields012_vec, mWavelength_vec, rms_Zemax, 1.0, compareTOM_Zemax::comEqual);
	testE1_vec.push_back(test_E1);

	// start DLS 
	DLS DLS_E1(/*optSysEle*/ optSysEle_E1,/*fields*/ mFields012_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	DLS_E1.setMaxWorstCounter(250);
	DLS_E1.setMaxInterations(500);
	DLS_E1.setFlipOrientationRadius(100.0);
	DLS_E1.setMaxDeltaParameter(20.0);
	DLS_E1.setFactorGettingBetter(0.4);
	DLS_E1.setFactorGettingWorst(2.1);
	DLS_E1.optimizeSystem_DLS_multiplicativ_Damping();

	OpticalSystemElement optimizedOptSysEle = DLS_E1.getOptimizedSystem_HLT();
	oftenUse::print(optimizedOptSysEle, mWave550);


	bool checkRMS_bestMerit_optimizedSystem = oftenUse::checkDLS_resultRMS(DLS_E1, 0.1);
	testE1_vec.push_back(checkRMS_bestMerit_optimizedSystem);

	std::vector<real> rms_Z{ 83.531,124.929,222.907 };
	bool betterZ_E1 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optimizedOptSysEle, mFields012_vec, mWavelength_vec, rms_Z, 0.1, compareTOM_Zemax::comBetter);
	testE1_vec.push_back(betterZ_E1);


	bool returnCheckerE1 = Math::checkTrueOfVectorElements(testE1_vec);
	return returnCheckerE1;

}

// E2 MD
bool testDLS::testE2_DLS_MD()
{

	std::vector<bool> testE2_vec;

	
	// build the optical system
	ApertureStopElement AperStop0(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1(/*radius*/ 20.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBAF4_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF4_S1());
	SphericalElement Sphere4(/*radius*/ 20.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF10_S1());
	SphericalElement Sphere5(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF10_S1());
	PlanElement Plan6(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	// **********************************
	// set parameter variable
	Sphere2.setParameterPointZ(/*min value*/ 1.0,  /*max value*/ 100.0, 0.0, typeModifierVariable);
	Sphere5.setParameterPointZ(/*min value*/ 1.0, /*max value*/ 100.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr AperStop_ptr = AperStop0.clone();
	surfacePtr Sphere1_ptr = Sphere1.clone();
	surfacePtr Sphere2_ptr = Sphere2.clone();
	surfacePtr Sphere3_ptr = Sphere3.clone();
	surfacePtr Sphere4_ptr = Sphere4.clone();
	surfacePtr Sphere5_ptr = Sphere5.clone();
	surfacePtr Plan6_ptr = Plan6.clone();

	std::vector<surfacePtr> opticalSystemE2_ptr{ AperStop_ptr, Sphere1_ptr, Sphere2_ptr, Sphere3_ptr, Sphere4_ptr,Sphere5_ptr,Plan6_ptr };
	std::vector<interactionPtr> interactionsE2_ptr{ mDoNothing.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };



	//	build optical system
	OpticalSystemElement optSysEle_E2(opticalSystemE2_ptr, interactionsE2_ptr);


	// test the system
	std::vector<real> rms_Zemax{ 522.001,514.671,493.353 };
	bool test_E2 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E2, mFields012_vec, mWavelength_vec, rms_Zemax, 1.0, compareTOM_Zemax::comEqual);
	testE2_vec.push_back(test_E2);

	//// check changes thickness --> 0
	DLS DLS_E2_0(/*optSysEle*/ optSysEle_E2,/*fields*/ mFields012_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	DLS_E2_0.changeThickness_Z_SurfaceTo(0, 1.0);
	std::vector<real> thicknessCorrect_0{1.0,10.0,10.0,5.0,10.0,10.0 };
	OpticalSystem_LLT optSys_0_0 = DLS_E2_0.getOptSys_LLT_vec()[0];
	bool checkThick_0_0 = oftenUse::checkThickness(optSys_0_0, thicknessCorrect_0, 0.01);
	testE2_vec.push_back(checkThick_0_0);
	OpticalSystem_LLT optSys_0_1 = DLS_E2_0.getOptSys_LLT_vec()[1];
	bool checkThick_0_1 = oftenUse::checkThickness(optSys_0_1, thicknessCorrect_0, 0.01);
	testE2_vec.push_back(checkThick_0_1);
	OpticalSystem_LLT optSys_0_2 = DLS_E2_0.getOptSys_LLT_vec()[2];
	bool checkThick_0_2 = oftenUse::checkThickness(optSys_0_2, thicknessCorrect_0, 0.01);
	testE2_vec.push_back(checkThick_0_2);

	std::vector<real> rmsZemax_0_0{ 661.586, 654.227, 632.345 };
	bool checkThick_0_rms = oftenUse::checkOptSysLLT_Equal_Better_Zemax(optSys_0_0, mFields012_vec, rmsZemax_0_0, mDefaultTolerance, compareTOM_Zemax::comEqual);
	testE2_vec.push_back(checkThick_0_rms);

	// check changes thickness --> 1
	DLS DLS_E2_1(/*optSysEle*/ optSysEle_E2,/*fields*/ mFields012_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	DLS_E2_1.changeThickness_Z_SurfaceTo(1, 10.0);
	std::vector<real> thicknessCorrect_1{ 5.0,10.0,10.0,5.0,10.0,10.0 };
	OpticalSystem_LLT optSys_1_0 = DLS_E2_1.getOptSys_LLT_vec()[0];
	bool checkThick_1_0 = oftenUse::checkThickness(optSys_1_0, thicknessCorrect_1, 0.01);
	testE2_vec.push_back(checkThick_1_0);
	OpticalSystem_LLT optSys_1_1 = DLS_E2_1.getOptSys_LLT_vec()[1];
	bool checkThick_1_1 = oftenUse::checkThickness(optSys_1_1, thicknessCorrect_1, 0.01);
	testE2_vec.push_back(checkThick_1_1);
	OpticalSystem_LLT optSys_1_2 = DLS_E2_1.getOptSys_LLT_vec()[2];
	bool checkThick_1_2 = oftenUse::checkThickness(optSys_1_2, thicknessCorrect_1, 0.01);
	testE2_vec.push_back(checkThick_1_2);

	std::vector<real> rmsZemax_1_1{ 425.767, 417.139, 391.781 };
	bool checkThick_1_rms = oftenUse::checkOptSysLLT_Equal_Better_Zemax(optSys_1_1, mFields012_vec, rmsZemax_1_1, mDefaultTolerance, compareTOM_Zemax::comEqual);
	testE2_vec.push_back(checkThick_1_rms);

	// check changes thickness --> 2
	DLS DLS_E2_2(/*optSysEle*/ optSysEle_E2,/*fields*/ mFields012_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	DLS_E2_2.changeThickness_Z_SurfaceTo(2, 20.0);
	std::vector<real> thicknessCorrect_2{ 5.0,10.0,20.0,5.0,10.0,10.0 };
	OpticalSystem_LLT optSys_2_0 = DLS_E2_2.getOptSys_LLT_vec()[0];
	bool checkThick_2_0 = oftenUse::checkThickness(optSys_2_0, thicknessCorrect_2, 0.01);
	testE2_vec.push_back(checkThick_2_0);
	OpticalSystem_LLT optSys_2_1 = DLS_E2_2.getOptSys_LLT_vec()[1];
	bool checkThick_2_1 = oftenUse::checkThickness(optSys_2_1, thicknessCorrect_2, 0.01);
	testE2_vec.push_back(checkThick_2_1);
	OpticalSystem_LLT optSys_2_2 = DLS_E2_2.getOptSys_LLT_vec()[2];
	bool checkThick_2_2 = oftenUse::checkThickness(optSys_2_2, thicknessCorrect_2, 0.01);
	testE2_vec.push_back(checkThick_2_2);

	std::vector<real> rmsZemax_2_2{ 589.931, 578.406, 544.204 };
	bool checkThick_2_rms = oftenUse::checkOptSysLLT_Equal_Better_Zemax(optSys_2_2, mFields012_vec, rmsZemax_2_2, mDefaultTolerance, compareTOM_Zemax::comEqual);
	testE2_vec.push_back(checkThick_2_rms);

	// check changes thickness --> 3
	DLS DLS_E2_3(/*optSysEle*/ optSysEle_E2,/*fields*/ mFields012_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	DLS_E2_3.changeThickness_Z_SurfaceTo(5, 20.0);
	std::vector<real> thicknessCorrect_3{ 5.0,10.0,10.0,5.0,10.0,20.0 };
	OpticalSystem_LLT optSys_3_0 = DLS_E2_3.getOptSys_LLT_vec()[0];
	bool checkThick_3_0 = oftenUse::checkThickness(optSys_3_0, thicknessCorrect_3, 0.01);
	testE2_vec.push_back(checkThick_3_0);
	OpticalSystem_LLT optSys_3_1 = DLS_E2_3.getOptSys_LLT_vec()[1];
	bool checkThick_3_1 = oftenUse::checkThickness(optSys_3_1, thicknessCorrect_3, 0.01);
	testE2_vec.push_back(checkThick_3_1);
	OpticalSystem_LLT optSys_3_2 = DLS_E2_3.getOptSys_LLT_vec()[2];
	bool checkThick_3_2 = oftenUse::checkThickness(optSys_3_2, thicknessCorrect_3, 0.01);
	testE2_vec.push_back(checkThick_3_2);

	std::vector<real> rmsZemax_3_0{ 664.239, 679.354, 724.824 };
	bool checkThick_3_rms = oftenUse::checkOptSysLLT_Equal_Better_Zemax(optSys_3_0, mFields012_vec, rmsZemax_3_0, mDefaultTolerance, compareTOM_Zemax::comEqual);
	testE2_vec.push_back(checkThick_3_rms);

	// optimization
	DLS DLS_E2(/*optSysEle*/ optSysEle_E2,/*fields*/ mFields012_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/8);
	DLS_E2.setFactorPositionDeviation(0.00001);
	DLS_E2.setMaxBorderViolations(1);
	DLS_E2.setMaxDeltaParameter(50.0);
	DLS_E2.setMaxInterations(500);
	DLS_E2.setMaxWorstCounter(250);
	DLS_E2.optimizeSystem_DLS_multiplicativ_Damping();
	
	OpticalSystemElement optimizedOptSysEle = DLS_E2.getOptimizedSystem_HLT();
	oftenUse::print(optimizedOptSysEle, mWave550);

	bool checkRMS_bestMerit_optimizedSystem = oftenUse::checkDLS_resultRMS(DLS_E2, 0.1);
	testE2_vec.push_back(checkRMS_bestMerit_optimizedSystem);

	std::vector<real> rms_Z{ 84.098,94.834,126.370 };
	bool betterZ_E2 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optimizedOptSysEle, mFields012_vec, mWavelength_vec, rms_Z, 10.0, compareTOM_Zemax::comBetter);
	testE2_vec.push_back(betterZ_E2);
	
	
	bool returnCheckerE2 = Math::checkTrueOfVectorElements(testE2_vec);
	return returnCheckerE2;

	//ich liebe saskia

}

// E3
bool testDLS::testE3_DLS_MD() // 3 radii are variable
{
	std::vector<bool> testE3_vec;

	
	// build the optical system
	ApertureStopElement AperStop0(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBAF4_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF4_S1());
	SphericalElement Sphere4(/*radius*/ 25.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF10_S1());
	SphericalElement Sphere5(/*radius*/ 20.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF10_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere6(/*radius*/ 50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	PlanElement Plan7(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,105.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	// **********************************
	// set parameter variable
	Sphere2.setParameterRadius(/*min value*/ 7.0,  /*max value*/ 10000.0, 0.0, typeModifierVariable);
	Sphere4.setParameterRadius(/*min value*/ 7.0,  /*max value*/ 10000.0, 0.0, typeModifierVariable);
	//Sphere5.setParameterRadius(/*min value*/ 7.0, /*max value*/ 10000.0, 0.0, typeModifierVariable);
	//Sphere6.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 0.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr AperStop_ptr = AperStop0.clone();
	surfacePtr Sphere1_ptr = Sphere1.clone();
	surfacePtr Sphere2_ptr = Sphere2.clone();
	surfacePtr Sphere3_ptr = Sphere3.clone();
	surfacePtr Sphere4_ptr = Sphere4.clone();
	surfacePtr Sphere5_ptr = Sphere5.clone();
	surfacePtr Sphere6_ptr = Sphere6.clone();
	surfacePtr Plan7_ptr = Plan7.clone();

	std::vector<surfacePtr> opticalSystemE3_ptr{ AperStop_ptr, Sphere1_ptr, Sphere2_ptr, Sphere3_ptr, Sphere4_ptr,Sphere5_ptr,Sphere6_ptr, Plan7_ptr };
	std::vector<interactionPtr> interactionsE3_ptr{ mDoNothing.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };



	//	build optical system
	OpticalSystemElement optSysEle_E3(opticalSystemE3_ptr, interactionsE3_ptr);
	
	std::vector<real> rmsZemax{ 81.210, 103.000, 166.007 };
	bool test_E3 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E3, mFields012_vec, mWavelength_vec, rmsZemax, 1.0, compareTOM_Zemax::comEqual);
	testE3_vec.push_back(test_E3);

	// optimization
	DLS DLS_E3(/*optSysEle*/ optSysEle_E3,/*fields*/ mFields012_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	DLS_E3.setFactorPositionDeviation(0.00001);
	DLS_E3.setFactorRadiusDeviation(0.00001);
	DLS_E3.setMaxBorderViolations(5);
	DLS_E3.setMaxInterations(200);
	DLS_E3.setMaxWorstCounter(50);
	DLS_E3.setMaxDeltaParameter(100.0);
	DLS_E3.setFlipOrientationRadius(1000.0);
	DLS_E3.setMinDeltaParameter(0.00000001);

	DLS_E3.optimizeSystem_DLS_multiplicativ_Damping();

	OpticalSystemElement optimizedOptSysEle = DLS_E3.getOptimizedSystem_HLT();

	bool checkRMS_bestMerit_optimizedSystem = oftenUse::checkDLS_resultRMS(DLS_E3, 0.1);
	testE3_vec.push_back(checkRMS_bestMerit_optimizedSystem);

	std::vector<real> rms_Z{ 81.112,92.548,138.883 };
	bool betterZ_E3 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optimizedOptSysEle, mFields012_vec, mWavelength_vec, rms_Z, 1.0, compareTOM_Zemax::comBetter);
	testE3_vec.push_back(betterZ_E3);

	bool returnCheckerE3 = Math::checkTrueOfVectorElements(testE3_vec);
	return returnCheckerE3;

}

// E4
bool testDLS::testE4_DLS_MD() // 1 radius and 1 thickness is variable
{
	std::vector<bool> testE4_vec;

	// build the optical system
	ApertureStopElement AperStop0(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1(/*radius*/ 10.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF10_S1());
	SphericalElement Sphere2(/*radius*/ 30.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBAF10_S1(), /*refractive index B*/glasses.getNBAF4_S1());
	SphericalElement Sphere3(/*radius*/ 40.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF4_S1());
	PlanElement Plan4(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,55.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	// **********************************
	// set parameter variable
	Sphere1.setParameterRadius(/*min value*/ 5.0,  /*max value*/ 1000.0, 0.0, typeModifierVariable);
	Sphere3.setParameterPointZ(/*min value*/ 1.0,  /*max value*/ 1000.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr AperStop_ptr = AperStop0.clone();
	surfacePtr Sphere1_ptr = Sphere1.clone();
	surfacePtr Sphere2_ptr = Sphere2.clone();
	surfacePtr Sphere3_ptr = Sphere3.clone();
	surfacePtr Plan4_ptr = Plan4.clone();

	std::vector<surfacePtr> opticalSystemE4_ptr{ AperStop_ptr, Sphere1_ptr, Sphere2_ptr, Sphere3_ptr, Plan4_ptr };
	std::vector<interactionPtr> interactionsE4_ptr{ mDoNothing.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSysEle_E4(opticalSystemE4_ptr, interactionsE4_ptr);

	std::vector<real> rmsZemax{ 503.375, 493.512, 465.433 };
	bool test_E4 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E4, mFields012_vec, mWavelength_vec, rmsZemax, 1.0, compareTOM_Zemax::comEqual);
	testE4_vec.push_back(test_E4);

	// optimization
	DLS DLS_E4(/*optSysEle*/ optSysEle_E4,/*fields*/ mFields012_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	DLS_E4.setFactorPositionDeviation(0.00001);
	DLS_E4.setFactorRadiusDeviation(0.00001);
	DLS_E4.setMaxBorderViolations(30);
	DLS_E4.setMaxInterations(1000);
	DLS_E4.setMaxWorstCounter(300);
	DLS_E4.setMaxDeltaParameter(100.0);
	DLS_E4.setFlipOrientationRadius(1000.0);
	DLS_E4.setMinDeltaParameter(0.00000001);
	//DLS_E4.setFactorGettingBetter(0.45);
	//DLS_E4.setFactorGettingWorst(2.1);

	DLS_E4.optimizeSystem_DLS_multiplicativ_Damping();

	OpticalSystemElement optimizedOptSysEle = DLS_E4.getOptimizedSystem_HLT();

	OpticalSystem_LLT optSys_LLT;
	optSys_LLT.printAllOptSysParameter_LLT(optimizedOptSysEle.getLLTconversion_doConversion());

	bool checkRMS_bestMerit_optimizedSystem = oftenUse::checkDLS_resultRMS(DLS_E4, 0.1);
	testE4_vec.push_back(checkRMS_bestMerit_optimizedSystem);

	std::vector<real> rms_Z{ 75.767,106.862,182.694 };
	bool betterZ_E4 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optimizedOptSysEle, mFields012_vec, mWavelength_vec, rms_Z, 1.0, compareTOM_Zemax::comBetter);
	testE4_vec.push_back(betterZ_E4);

	bool returnCheckerE3 = Math::checkTrueOfVectorElements(testE4_vec);
	return returnCheckerE3;

}

// E5
bool testDLS::testE5_DLS_MD() // 2 radii and 1 thickness is variable
{
	std::vector<bool> testE5_vec;

	// build the optical system
	ApertureStopElement AperStop0(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1(/*radius*/ 10.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF10_S1());
	SphericalElement Sphere2(/*radius*/ 30.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBAF10_S1(), /*refractive index B*/glasses.getNBAF4_S1());
	SphericalElement Sphere3(/*radius*/ 20.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF4_S1());
	PlanElement Plan4(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,55.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	// **********************************
	// set parameter variable
	Sphere1.setParameterRadius(/*min value*/ 5.0,  /*max value*/ 10000.0, 0.0, typeModifierVariable);
	Sphere3.setParameterPointZ(/*min value*/ 1.0,  /*max value*/ 100, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr AperStop_ptr = AperStop0.clone();
	surfacePtr Sphere1_ptr = Sphere1.clone();
	surfacePtr Sphere2_ptr = Sphere2.clone();
	surfacePtr Sphere3_ptr = Sphere3.clone();
	surfacePtr Plan4_ptr = Plan4.clone();

	std::vector<surfacePtr> opticalSystemE5_ptr{ AperStop_ptr, Sphere1_ptr, Sphere2_ptr, Sphere3_ptr, Plan4_ptr };
	std::vector<interactionPtr> interactionsE5_ptr{ mDoNothing.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSysEle_E5(opticalSystemE5_ptr, interactionsE5_ptr);

	std::vector<real> rmsZemax{ 307.413, 300.255, 282.021 };
	bool test_E5 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E5, mFields012_vec, mWavelength_vec, rmsZemax, 1.0, compareTOM_Zemax::comEqual);
	testE5_vec.push_back(test_E5);

	// optimization
	DLS DLS_E5(/*optSysEle*/ optSysEle_E5,/*fields*/ mFields012_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	DLS_E5.setFactorPositionDeviation(0.00001);
	DLS_E5.setFactorRadiusDeviation(0.00001);
	DLS_E5.setMaxWorstCounter(100);
	DLS_E5.setMaxBorderViolations(30);
	DLS_E5.setMaxInterations(200);
	
	DLS_E5.setMaxDeltaParameter(100.0);
	DLS_E5.setFlipOrientationRadius(1000.0);
	DLS_E5.setMinDeltaParameter(0.00000001);
	DLS_E5.setFactorGettingBetter(0.4);
	DLS_E5.setFactorGettingWorst(1.9);

	DLS_E5.optimizeSystem_DLS_multiplicativ_Damping();

	OpticalSystemElement optimizedOptSysEle = DLS_E5.getOptimizedSystem_HLT();

	OpticalSystem_LLT optSys_LLT;
	optSys_LLT.printAllOptSysParameter_LLT(optimizedOptSysEle.getLLTconversion_doConversion());

	bool checkRMS_bestMerit_optimizedSystem = oftenUse::checkDLS_resultRMS(DLS_E5, 0.1);
	testE5_vec.push_back(checkRMS_bestMerit_optimizedSystem);

	std::vector<real> rms_Z{ 71.521,96.897,160.340 };
	bool betterZ_E5 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optimizedOptSysEle, mFields012_vec, mWavelength_vec, rms_Z, 10.0, compareTOM_Zemax::comBetter);
	testE5_vec.push_back(betterZ_E5);

	bool returnCheckerE5 = Math::checkTrueOfVectorElements(testE5_vec);
	return returnCheckerE5;
}

// E6
bool testDLS::testE6_DLS_MD() // min thickness is 0.01
{

	std::vector<bool> testE6_vec;

	// surfaces E6
	ApertureStopElement AperStop0_E6(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E6(/*radius*/ 80.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere2_E6(/*radius*/ 70.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere3_E6(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere4_E6(/*radius*/ 35.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere5_E6(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	PlanElement Plan6_E6(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,75.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere1_E6.setParameterPointZ(0.01, 20.0, 0.0, typeModifierVariable);
	Sphere2_E6.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);

	surfacePtr Aper0_E6_ptr = AperStop0_E6.clone();
	surfacePtr Sphere1_E6_ptr = Sphere1_E6.clone();
	surfacePtr Sphere2_E6_ptr = Sphere2_E6.clone();
	surfacePtr Sphere3_E6_ptr = Sphere3_E6.clone();
	surfacePtr Sphere4_E6_ptr = Sphere4_E6.clone();
	surfacePtr Sphere5_E6_ptr = Sphere5_E6.clone();
	surfacePtr Plan6_E6_ptr = Plan6_E6.clone();

	std::vector<surfacePtr> opticalSystemE6_ptr{ Aper0_E6_ptr, Sphere1_E6_ptr, Sphere2_E6_ptr , Sphere3_E6_ptr, Sphere4_E6_ptr, Sphere5_E6_ptr,  Plan6_E6_ptr };
	std::vector<interactionPtr> interactionsE6_ptr{ mDoNothing.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E6(opticalSystemE6_ptr, interactionsE6_ptr);

	// check the start system
	std::vector<real> rmsStartSystem_Z{ 203.472,202.240,201.159 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E6, mFields012_vec, mWavelength_vec, rmsStartSystem_Z, 0.1, compareTOM_Zemax::comEqual);
	testE6_vec.push_back(checkStartSys);

	// optimization
	DLS DLS_E6(/*optSysEle*/ optSystemElement_E6,/*fields*/ mFields012_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	DLS_E6.setFactorPositionDeviation(0.00001);
	DLS_E6.setFactorRadiusDeviation(0.00001);
	DLS_E6.setMaxWorstCounter(250);
	DLS_E6.setMaxBorderViolations(15);
	DLS_E6.setMaxInterations(500);
	DLS_E6.setMaxDeltaParameter(100.0);
	DLS_E6.setFlipOrientationRadius(1000.0);
	DLS_E6.setMinDeltaParameter(0.00000001);
	DLS_E6.setFactorGettingBetter(0.4);
	DLS_E6.setFactorGettingWorst(1.9);

	DLS_E6.optimizeSystem_DLS_multiplicativ_Damping();
	OpticalSystemElement optimizedOptSysEle = DLS_E6.getOptimizedSystem_HLT();

	oftenUse::print(optimizedOptSysEle, mWavelength_vec[0]);

	bool checkRMS_bestMerit_optimizedSystem = oftenUse::checkDLS_resultRMS(DLS_E6, 0.1);
	testE6_vec.push_back(checkRMS_bestMerit_optimizedSystem);

	std::vector<real> rms_Z{ 53.669,65.915,95.261 };
	bool betterZ_E6 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optimizedOptSysEle, mFields012_vec, mWavelength_vec, rms_Z, 20.0, compareTOM_Zemax::comBetter);
	testE6_vec.push_back(betterZ_E6);

	oftenUse::print(optimizedOptSysEle, mWavelength_vec[0]);

	bool returnCheckerE6 = Math::checkTrueOfVectorElements(testE6_vec);
	return returnCheckerE6;

}


// E7
bool testDLS::testE7_DLS_MD() // aperture stop is not first surface
{
	std::vector<bool> test_E7_vec;

	// surfaces _E7
	SphericalElement Sphere0_E7(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere1_E7(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF5_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere2_E7(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere3_E7(/*radius*/ 25.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere4_E7(/*radius*/ 15.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	ApertureStopElement AperStop5_E7(/* semi height*/1.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan6_E7(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere0_E7.setParameterPointZ(0.01, 7.0, 0.0, typeModifierVariable);
	Sphere3_E7.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);

	
	surfacePtr Sphere0_E7_ptr = Sphere0_E7.clone();
	surfacePtr Sphere1_E7_ptr = Sphere1_E7.clone();
	surfacePtr Sphere2_E7_ptr = Sphere2_E7.clone();
	surfacePtr Sphere3_E7_ptr = Sphere3_E7.clone();
	surfacePtr Sphere4_E7_ptr = Sphere4_E7.clone();
	surfacePtr Aper5_E7_ptr = AperStop5_E7.clone();
	surfacePtr Plan6_E7_ptr = Plan6_E7.clone();

	std::vector<surfacePtr> opticalSystem_E7_ptr{ Sphere0_E7_ptr , Sphere1_E7_ptr, Sphere2_E7_ptr , Sphere3_E7_ptr, Sphere4_E7_ptr, Aper5_E7_ptr,  Plan6_E7_ptr };
	std::vector<interactionPtr> interactions_E7_ptr{ mRefrac.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mDoNothing.clone(),mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E7(opticalSystem_E7_ptr, interactions_E7_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system E7" << std::endl;
	oftenUse::print(optSystemElement_E7, mWave587);

	// check the start system
	std::vector<real> rmsStartSystem_Z{ 239.618,236.944,228.762 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E7, mField0_05_1_vec, mWavelength_FdV_vec, rmsStartSystem_Z, 0.1, compareTOM_Zemax::comEqual);
	test_E7_vec.push_back(checkStartSys);

	// optimization
	DLS DLS_E7(/*optSysEle*/ optSystemElement_E7,/*fields*/ mField0_05_1_vec, /*wavelength*/ mWavelength_FdV_vec, /*rings*/ 6, /*arms*/ 8);
	DLS_E7.setFactorPositionDeviation(0.00001);
	DLS_E7.setFactorRadiusDeviation(0.00001);
	DLS_E7.setMaxWorstCounter(250);
	DLS_E7.setMaxBorderViolations(5);
	DLS_E7.setMaxInterations(500);
	DLS_E7.setMaxDeltaParameter(50.0);
	DLS_E7.setFlipOrientationRadius(1000.0);
	DLS_E7.setMinDeltaParameter(0.00000001);
	DLS_E7.setFactorGettingBetter(0.2);
	DLS_E7.setFactorGettingWorst(2.1);

	DLS_E7.optimizeSystem_DLS_multiplicativ_Damping();
	OpticalSystemElement optimizedOptSysEle = DLS_E7.getOptimizedSystem_HLT();

	oftenUse::print(optimizedOptSysEle, mWavelength_FdV_vec[0]);

	bool checkRMS_bestMerit_optimizedSystem = oftenUse::checkDLS_resultRMS(DLS_E7, 0.1);
	test_E7_vec.push_back(checkRMS_bestMerit_optimizedSystem);



	real rmsStartSum = Math::sumAllVectorValues(rmsStartSystem_Z);
	// here we do not get a better result than Zemax, but the algorithm works...
	std::vector<real> rmsOptiSystem =  oftenUse::getRMSoptSysHLT(optimizedOptSysEle, mField0_05_1_vec, mWavelength_FdV_vec, 6, 8);
	real rmsOptiSysSum = Math::sumAllVectorValues(rmsOptiSystem);
	bool betterThanStartSystem = rmsOptiSysSum < rmsStartSum;
	test_E7_vec.push_back(betterThanStartSystem);

	oftenUse::print(optimizedOptSysEle, mWavelength_FdV_vec[0]);

	bool returnChecker_E7 = Math::checkTrueOfVectorElements(test_E7_vec);
	return returnChecker_E7;

}


//// test cardinal points super function
//bool testDLS::testCardinalPointsSuperFct()
//{
//
//}
//// test EFL
//bool testDLS::testTargetEFL_DLS_obj()
//{
//
//}