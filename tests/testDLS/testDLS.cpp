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
#include "..\..\Analyse\CardinalPoints.h"

// often use
#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

testDLS::testDLS()
{
	loadImportantValues();
}

testDLS::~testDLS() {}

// typedef
typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

// super function
bool testDLS::testDLS_superFct_optiRMS()
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

	// E8
	bool E8_MD = testE8_DLS_MD();
	testSuperFct_vec.push_back(E8_MD);



	bool returnChecker = Math::checkTrueOfVectorElements(testSuperFct_vec);
	return returnChecker;

}


// test cardinal points super function
bool testDLS::testDLS_superFct_optiCarPoints()
{
	std::vector<bool> testSuperFct_vec_cardinalPoints;

	// opti efl
	bool checkEFL = testDLS_carPoint_EFL();
	testSuperFct_vec_cardinalPoints.push_back(checkEFL);
	// PP_obj
	bool checkPP_obj = testDLS_carPoint_PP_obj();
	testSuperFct_vec_cardinalPoints.push_back(checkPP_obj);
	// PP_ima
	bool checkPP_ima = testDLS_carPoint_PP_ima();
	testSuperFct_vec_cardinalPoints.push_back(checkPP_ima);
	// EXPP_lastSurface
	bool checkEXPP_lastSurface = testDLS_carPoint_EXPP_lastSurface();
	testSuperFct_vec_cardinalPoints.push_back(checkEXPP_lastSurface);
	// EXPD
	bool checkEXPD = testDLS_carPoint_EXPD();
	testSuperFct_vec_cardinalPoints.push_back(checkEXPD);
	// Magnification
	bool checkMagnification = testDLS_carPoint_Magnification();
	testSuperFct_vec_cardinalPoints.push_back(checkMagnification);
	// NA_objSpace
	bool checkNA_objSpace = testDLS_carPoint_NA_objSpace();
	testSuperFct_vec_cardinalPoints.push_back(checkNA_objSpace);
	// ENPP_firstSurface
	bool checkENPP_firstSurface = testDLS_carPoint_ENPP_firstSurface();
	testSuperFct_vec_cardinalPoints.push_back(checkENPP_firstSurface);
	// ENPP_global
	bool checkENPP_global = testDLS_carPoint_ENPP_global();
	testSuperFct_vec_cardinalPoints.push_back(checkENPP_global);
	// ENPD
	bool checkENPD = testDLS_carPoint_ENPD();
	testSuperFct_vec_cardinalPoints.push_back(checkENPD);
	// f_number_imaSpace
	bool checkf_number_imaSpace = testDLS_carPoint_f_number_imaSpace();
	testSuperFct_vec_cardinalPoints.push_back(checkf_number_imaSpace);
	// NA_imaSpace
	bool checkNA_imaSpace = testDLS_carPoint_NA_imaSpace();
	testSuperFct_vec_cardinalPoints.push_back(checkNA_imaSpace);
	// WFNO
	bool checkWFNO = testDLS_carPoint_WFNO();
	testSuperFct_vec_cardinalPoints.push_back(checkWFNO);


	// E0 multiCarPoints
	bool checkE1 = testDLS__E0_MultiCarPoints();
	testSuperFct_vec_cardinalPoints.push_back(checkE1);

	bool returnChecker = Math::checkTrueOfVectorElements(testSuperFct_vec_cardinalPoints);
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
	mWave587d = 587.5618;
	mWave486F = 486.1327;
	mWave656C = 656.2725;
	mWavelength_FdV_vec.resize(3);
	mWavelength_FdV_vec[0] = mWave587d;
	mWavelength_FdV_vec[1] = mWave486F;
	mWavelength_FdV_vec[2] = mWave656C;

	mLight587.setWavelength(mWave587d);
	mLight486.setWavelength(mWave486F);
	mLight656.setWavelength(mWave656C);
	mLight_FdC_Vec.resize(3);
	mLight_FdC_Vec[0] = mLight587;
	mLight_FdC_Vec[1] = mLight486;
	mLight_FdC_Vec[2] = mLight656;

	// field
	mField0 = { 0.0,0.0,0.0 };
	mField05 = { 0.0,0.5,0.0 };
	mField1 = { 0.0,1.0,0.0 };
	mField2 = { 0.0,2.0,0.0 };
	mFields012_obj_vec.resize(3);
	mFields012_obj_vec[0] = mField0;
	mFields012_obj_vec[1] = mField1;
	mFields012_obj_vec[2] = mField2;

	mField0_05_1_obj_vec.resize(3);
	mField0_05_1_obj_vec[0] = mField0;
	mField0_05_1_obj_vec[1] = mField05;
	mField0_05_1_obj_vec[2] = mField1;

	// field angle
	mField_X_0 = 0.0;
	mField_Y_0 = 0.0;
	mField_Y_1 = 1.0;
	mField_Y_2 = 2.0;

	mFields000_inf_vec.resize(3);
	mFields012_inf_vec.resize(3);

	mFields000_inf_vec[0] = mField_X_0;
	mFields000_inf_vec[1] = mField_X_0;
	mFields000_inf_vec[2] = mField_X_0;

	mFields012_inf_vec[0] = mField_Y_0;
	mFields012_inf_vec[1] = mField_Y_1;
	mFields012_inf_vec[2] = mField_Y_2;

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
	std::vector<interaction_ptr> interactionsE0_ptr{ mDoNothing.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };



	//	build optical system
	OpticalSystemElement optSysEle_E0(opticalSystemE0_ptr, interactionsE0_ptr);


	// test the system
	std::vector<real> rms_Zemax{ 1530.53,1523.93,1504.26 };
	bool test_E0 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E0, mFields012_obj_vec, mWavelength_vec, rms_Zemax, 1.0, compareTOM_Zemax::comEqual);
	testE0_vec.push_back(test_E0);

	// start DLS 
	DLS DLS_E0(/*optSysEle*/ optSysEle_E0,/*fields*/ mFields012_obj_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	DLS_E0.setMaxWorstCounter(50);
	DLS_E0.setMaxInterations(200);

	DLS_E0.optimizeSystem_DLS_multiplicativ_Damping();

	OpticalSystemElement optimizedOptSysEle = DLS_E0.getOptimizedSystem_HLT();

	std::vector<real> rms_Z{ 60.093,79.343,126.244 };
	bool betterZ_E0 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optimizedOptSysEle, mFields012_obj_vec, mWavelength_vec, rms_Z, 1.0, compareTOM_Zemax::comBetter);
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
	std::vector<interaction_ptr> interactionsE1_ptr{ mDoNothing.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };



	//	build optical system
	OpticalSystemElement optSysEle_E1(opticalSystemE1_ptr, interactionsE1_ptr);


	// test the system
	std::vector<real> rms_Zemax{ 4815.08,4815.23,4815.71 };
	bool test_E1 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E1, mFields012_obj_vec, mWavelength_vec, rms_Zemax, 1.0, compareTOM_Zemax::comEqual);
	testE1_vec.push_back(test_E1);

	// start DLS 
	DLS DLS_E1(/*optSysEle*/ optSysEle_E1,/*fields*/ mFields012_obj_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
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
	bool betterZ_E1 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optimizedOptSysEle, mFields012_obj_vec, mWavelength_vec, rms_Z, 0.1, compareTOM_Zemax::comBetter);
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
	std::vector<interaction_ptr> interactionsE2_ptr{ mDoNothing.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };



	//	build optical system
	OpticalSystemElement optSysEle_E2(opticalSystemE2_ptr, interactionsE2_ptr);


	// test the system
	std::vector<real> rms_Zemax{ 522.001,514.671,493.353 };
	bool test_E2 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E2, mFields012_obj_vec, mWavelength_vec, rms_Zemax, 1.0, compareTOM_Zemax::comEqual);
	testE2_vec.push_back(test_E2);

	//// check changes thickness --> 0
	DLS DLS_E2_0(/*optSysEle*/ optSysEle_E2,/*fields*/ mFields012_obj_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	DLS_E2_0.changeThickness_Z_SurfaceTo_All(0, 1.0);
	std::vector<real> thicknessCorrect_0{ 1.0,10.0,10.0,5.0,10.0,10.0 };
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
	bool checkThick_0_rms = oftenUse::checkOptSysLLT_Equal_Better_Zemax(optSys_0_0, mFields012_obj_vec, rmsZemax_0_0, mDefaultTolerance, compareTOM_Zemax::comEqual);
	testE2_vec.push_back(checkThick_0_rms);

	// check changes thickness --> 1
	DLS DLS_E2_1(/*optSysEle*/ optSysEle_E2,/*fields*/ mFields012_obj_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	DLS_E2_1.changeThickness_Z_SurfaceTo_All(1, 10.0);
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
	bool checkThick_1_rms = oftenUse::checkOptSysLLT_Equal_Better_Zemax(optSys_1_1, mFields012_obj_vec, rmsZemax_1_1, mDefaultTolerance, compareTOM_Zemax::comEqual);
	testE2_vec.push_back(checkThick_1_rms);

	// check changes thickness --> 2
	DLS DLS_E2_2(/*optSysEle*/ optSysEle_E2,/*fields*/ mFields012_obj_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	DLS_E2_2.changeThickness_Z_SurfaceTo_All(2, 20.0);
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
	bool checkThick_2_rms = oftenUse::checkOptSysLLT_Equal_Better_Zemax(optSys_2_2, mFields012_obj_vec, rmsZemax_2_2, mDefaultTolerance, compareTOM_Zemax::comEqual);
	testE2_vec.push_back(checkThick_2_rms);

	// check changes thickness --> 3
	DLS DLS_E2_3(/*optSysEle*/ optSysEle_E2,/*fields*/ mFields012_obj_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	DLS_E2_3.changeThickness_Z_SurfaceTo_All(5, 20.0);
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
	bool checkThick_3_rms = oftenUse::checkOptSysLLT_Equal_Better_Zemax(optSys_3_0, mFields012_obj_vec, rmsZemax_3_0, mDefaultTolerance, compareTOM_Zemax::comEqual);
	testE2_vec.push_back(checkThick_3_rms);

	// optimization
	DLS DLS_E2(/*optSysEle*/ optSysEle_E2,/*fields*/ mFields012_obj_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/8);
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
	bool betterZ_E2 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optimizedOptSysEle, mFields012_obj_vec, mWavelength_vec, rms_Z, 10.0, compareTOM_Zemax::comBetter);
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
	std::vector<interaction_ptr> interactionsE3_ptr{ mDoNothing.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };



	//	build optical system
	OpticalSystemElement optSysEle_E3(opticalSystemE3_ptr, interactionsE3_ptr);

	std::vector<real> rmsZemax{ 81.210, 103.000, 166.007 };
	bool test_E3 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E3, mFields012_obj_vec, mWavelength_vec, rmsZemax, 1.0, compareTOM_Zemax::comEqual);
	testE3_vec.push_back(test_E3);

	// optimization
	DLS DLS_E3(/*optSysEle*/ optSysEle_E3,/*fields*/ mFields012_obj_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
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
	bool betterZ_E3 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optimizedOptSysEle, mFields012_obj_vec, mWavelength_vec, rms_Z, 1.0, compareTOM_Zemax::comBetter);
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
	std::vector<interaction_ptr> interactionsE4_ptr{ mDoNothing.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSysEle_E4(opticalSystemE4_ptr, interactionsE4_ptr);

	std::vector<real> rmsZemax{ 503.375, 493.512, 465.433 };
	bool test_E4 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E4, mFields012_obj_vec, mWavelength_vec, rmsZemax, 1.0, compareTOM_Zemax::comEqual);
	testE4_vec.push_back(test_E4);

	// optimization
	DLS DLS_E4(/*optSysEle*/ optSysEle_E4,/*fields*/ mFields012_obj_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
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
	bool betterZ_E4 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optimizedOptSysEle, mFields012_obj_vec, mWavelength_vec, rms_Z, 1.0, compareTOM_Zemax::comBetter);
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
	std::vector<interaction_ptr> interactionsE5_ptr{ mDoNothing.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSysEle_E5(opticalSystemE5_ptr, interactionsE5_ptr);

	std::vector<real> rmsZemax{ 307.413, 300.255, 282.021 };
	bool test_E5 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E5, mFields012_obj_vec, mWavelength_vec, rmsZemax, 1.0, compareTOM_Zemax::comEqual);
	testE5_vec.push_back(test_E5);

	// optimization
	DLS DLS_E5(/*optSysEle*/ optSysEle_E5,/*fields*/ mFields012_obj_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
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
	bool betterZ_E5 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optimizedOptSysEle, mFields012_obj_vec, mWavelength_vec, rms_Z, 10.0, compareTOM_Zemax::comBetter);
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
	std::vector<interaction_ptr> interactionsE6_ptr{ mDoNothing.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E6(opticalSystemE6_ptr, interactionsE6_ptr);

	// check the start system
	std::vector<real> rmsStartSystem_Z{ 203.472,202.240,201.159 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E6, mFields012_obj_vec, mWavelength_vec, rmsStartSystem_Z, 0.1, compareTOM_Zemax::comEqual);
	testE6_vec.push_back(checkStartSys);

	// optimization
	DLS DLS_E6(/*optSysEle*/ optSystemElement_E6,/*fields*/ mFields012_obj_vec, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
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
	bool betterZ_E6 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optimizedOptSysEle, mFields012_obj_vec, mWavelength_vec, rms_Z, 20.0, compareTOM_Zemax::comBetter);
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
	std::vector<interaction_ptr> interactions_E7_ptr{ mRefrac.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mDoNothing.clone(),mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E7(opticalSystem_E7_ptr, interactions_E7_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system E7" << std::endl;
	oftenUse::print(optSystemElement_E7, mWave587d);

	// check the start system
	std::vector<real> rmsStartSystem_Z{ 239.618,236.944,228.762 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E7, mField0_05_1_obj_vec, mWavelength_FdV_vec, rmsStartSystem_Z, 0.1, compareTOM_Zemax::comEqual);
	test_E7_vec.push_back(checkStartSys);

	// optimization
	DLS DLS_E7(/*optSysEle*/ optSystemElement_E7,/*fields*/ mField0_05_1_obj_vec, /*wavelength*/ mWavelength_FdV_vec, /*rings*/ 6, /*arms*/ 8);
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
	std::vector<real> rmsOptiSystem = oftenUse::getRMSoptSysHLT(optimizedOptSysEle, mField0_05_1_obj_vec, mWavelength_FdV_vec, 6, 8);
	real rmsOptiSysSum = Math::sumAllVectorValues(rmsOptiSystem);
	bool betterThanStartSystem = rmsOptiSysSum < rmsStartSum;
	test_E7_vec.push_back(betterThanStartSystem);

	oftenUse::print(optimizedOptSysEle, mWavelength_FdV_vec[0]);

	bool returnChecker_E7 = Math::checkTrueOfVectorElements(test_E7_vec);
	return returnChecker_E7;

}

bool testDLS::testE8_DLS_MD() // rays from infinity
{
	std::vector<bool> test_E8_vec;

	// surfaces _E8
	SphericalElement Sphere0_E8(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere1_E8(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere2_E8(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	ApertureStopElement AperStop3_E8(/* semi height*/1.5, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan4_E8(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere0_E8.setParameterPointZ(0.01, 20.0, 0.0, typeModifierVariable);
	Sphere2_E8.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);


	surfacePtr Sphere0_E8_ptr = Sphere0_E8.clone();
	surfacePtr Sphere1_E8_ptr = Sphere1_E8.clone();
	surfacePtr Sphere2_E8_ptr = Sphere2_E8.clone();
	surfacePtr Aper3_E8_ptr = AperStop3_E8.clone();
	surfacePtr Plan4_E8_ptr = Plan4_E8.clone();

	std::vector<surfacePtr> opticalSystem_E8_ptr{ Sphere0_E8_ptr , Sphere1_E8_ptr, Sphere2_E8_ptr, Aper3_E8_ptr,  Plan4_E8_ptr };
	std::vector<interaction_ptr> interactions_E8_ptr{ mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mDoNothing.clone(),mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E8(opticalSystem_E8_ptr, interactions_E8_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system _E8" << std::endl;
	oftenUse::print(optSystemElement_E8, mWave587d);

	// check the start system
	std::vector<real> rmsStartSystem_Z{ 207.944,203.879,200.495 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E8, mFields000_inf_vec, mFields012_inf_vec, mWavelength_FdV_vec, rmsStartSystem_Z, 0.1, compareTOM_Zemax::comEqual);
	test_E8_vec.push_back(checkStartSys);

	// optimization
	DLS DLS_E8(/*optSysEle*/ optSystemElement_E8,/*fields X*/ mFields000_inf_vec, /*fields X*/ mFields012_inf_vec, /*wavelength*/ mWavelength_FdV_vec, /*rings*/ 6, /*arms*/ 8);
	DLS_E8.setFactorPositionDeviation(0.00001);
	DLS_E8.setFactorRadiusDeviation(0.00001);
	DLS_E8.setMaxWorstCounter(250);
	DLS_E8.setMaxBorderViolations(5);
	DLS_E8.setMaxInterations(500);
	DLS_E8.setMaxDeltaParameter(50.0);
	DLS_E8.setFlipOrientationRadius(1000.0);
	DLS_E8.setMinDeltaParameter(0.00000001);
	DLS_E8.setFactorGettingBetter(0.2);
	DLS_E8.setFactorGettingWorst(2.1);

	DLS_E8.optimizeSystem_DLS_multiplicativ_Damping();
	OpticalSystemElement optimizedOptSysEle = DLS_E8.getOptimizedSystem_HLT();

	oftenUse::print(optimizedOptSysEle, mWavelength_FdV_vec[0]);

	bool checkRMS_bestMerit_optimizedSystem = oftenUse::checkDLS_resultRMS(DLS_E8, 0.1);
	test_E8_vec.push_back(checkRMS_bestMerit_optimizedSystem);


	real rmsStartSum = Math::sumAllVectorValues(rmsStartSystem_Z);
	// here we do not get a better result than Zemax, but the algorithm works...
	std::vector<real> rmsOptiSystem = oftenUse::getRMSoptSysHLT(optimizedOptSysEle, mFields000_inf_vec, mFields012_inf_vec, mWavelength_FdV_vec, 6, 8);
	real rmsOptiSysSum = Math::sumAllVectorValues(rmsOptiSystem);
	bool betterThanStartSystem = rmsOptiSysSum < rmsStartSum;
	test_E8_vec.push_back(betterThanStartSystem);

	oftenUse::print(optimizedOptSysEle, mWavelength_FdV_vec[0]);

	bool returnChecker_E8 = Math::checkTrueOfVectorElements(test_E8_vec);
	return returnChecker_E8;

}




// test EFL
bool testDLS::testDLS_carPoint_EFL()
{
	std::vector<bool> test_efl_vec;

	// surfaces _efl
	SphericalElement Sphere0_efl(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere1_efl(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere2_efl(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	ApertureStopElement AperStop3_efl(/* semi height*/1.5, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan4_efl(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere2_efl.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);

	surfacePtr Sphere0_efl_ptr = Sphere0_efl.clone();
	surfacePtr Sphere1_efl_ptr = Sphere1_efl.clone();
	surfacePtr Sphere2_efl_ptr = Sphere2_efl.clone();
	surfacePtr Aper3_efl_ptr = AperStop3_efl.clone();
	surfacePtr Plan4_efl_ptr = Plan4_efl.clone();

	std::vector<surfacePtr> opticalSystem_efl_ptr{ Sphere0_efl_ptr , Sphere1_efl_ptr, Sphere2_efl_ptr, Aper3_efl_ptr,  Plan4_efl_ptr };
	std::vector<interaction_ptr> interactions_efl_ptr{ mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mDoNothing.clone(),mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_efl(opticalSystem_efl_ptr, interactions_efl_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system _efl" << std::endl;
	oftenUse::print(optSystemElement_efl, mWave587d);

	// check the start system
	std::vector<real> rmsStartSystem_Z{ 207.944,203.879,200.495 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_efl, mFields000_inf_vec, mFields012_inf_vec, mWavelength_FdV_vec, rmsStartSystem_Z, 0.1, compareTOM_Zemax::comEqual);
	test_efl_vec.push_back(checkStartSys);

	// check initial cardinal point
	CardinalPoints carPoints(optSystemElement_efl, mWave587d, objectPoint_inf_obj::inf);
	real efl_ref = 17.5725;
	real efl_calc = carPoints.getEFL();
	bool checkEFL = Math::compareTwoNumbers_tolerance(efl_ref, efl_calc, 0.1);
	test_efl_vec.push_back(checkEFL);

	// load the target cardinal point
	targetCardinalPointsStruct targetCarPointEFL;
	real targetEFL = 20.0;
	targetCarPointEFL.setTargetEFL(targetEFL);

	// optimization
	DLS DLS_efl(/*optSysEle*/ optSystemElement_efl,/*fields X*/ mFields000_inf_vec, /*fields X*/ mFields012_inf_vec, /*wavelength*/ mWavelength_FdV_vec, /*rings*/ 6, /*arms*/ 8, false, targetCarPointEFL);
	DLS_efl.setFactorPositionDeviation(0.00001);
	DLS_efl.setFactorRadiusDeviation(0.00001);
	DLS_efl.setMaxWorstCounter(250);
	DLS_efl.setMaxBorderViolations(5);
	DLS_efl.setMaxInterations(500);
	DLS_efl.setMaxDeltaParameter(50.0);
	DLS_efl.setFlipOrientationRadius(1000.0);
	DLS_efl.setMinDeltaParameter(0.00000001);
	DLS_efl.setFactorGettingBetter(0.2);
	DLS_efl.setFactorGettingWorst(2.1);

	DLS_efl.optimizeSystem_DLS_multiplicativ_Damping();
	OpticalSystemElement optimizedOptSysEle = DLS_efl.getOptimizedSystem_HLT();

	oftenUse::print(optimizedOptSysEle, mWavelength_FdV_vec[0]);

	// check for optimized efl
	bool checkRMS_bestMerit_optimizedSystem = oftenUse::checkDLS_resultRMS(DLS_efl, 0.1);
	test_efl_vec.push_back(checkRMS_bestMerit_optimizedSystem);

	// check efl
	CardinalPoints carPoints_efl(optimizedOptSysEle, mWave587d, objectPoint_inf_obj::inf);
	real calcEFL = carPoints_efl.getEFL();
	bool checkEFL_opti = std::abs(calcEFL - targetEFL) < 0.1;
	test_efl_vec.push_back(checkEFL_opti);

	bool returnChecker_efl = Math::checkTrueOfVectorElements(test_efl_vec);
	return returnChecker_efl;
}

bool testDLS::testDLS_carPoint_PP_obj()
{
	// save bools in this vector
	std::vector<bool> test_vec;

	// surfaces _efl
	SphericalElement S0(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement S1(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	ApertureStopElement S2(/* semi height*/1.5, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement S3(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	S1.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);


	std::vector<surfacePtr> opticalSystem_efl_ptr = { S0.clone() , S1.clone(), S2.clone(), S3.clone() };
	std::vector<interaction_ptr> interactions_efl_ptr = { mRefrac.clone(), mRefrac.clone() ,mDoNothing.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSys(opticalSystem_efl_ptr, interactions_efl_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system _efl" << std::endl;
	oftenUse::print(optSys, mWave550);

	// check the start system
	real rmsStartSystem = 1019.87;
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSys, { 0.0,0.0,0.0 }, mWave550, rmsStartSystem, 0.5, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);

	// load the target cardinal point
	targetCardinalPointsStruct targetCarPointEFL;
	real targetPP_obj = 2.0;
	targetCarPointEFL.setTargetPP_obj(targetPP_obj);

	// optimization the system
	std::vector<VectorStructR3> field_vec = { {0.0,0.0,0.0} };
	std::vector<real> wave550_vec = { mWave550 };
	DLS DLS_PP_obj(/*optSysEle*/ optSys, field_vec, /*wavelength*/ wave550_vec, /*rings*/ 6, /*arms*/ 8, false, targetCarPointEFL);
	DLS_PP_obj.optimizeSystem_DLS_multiplicativ_Damping();

	// check cardinal point
	CardinalPoints carPoints_efl(DLS_PP_obj.getOptimizedSystem_HLT(), mWave550, objectPoint_inf_obj::obj);
	real optimizedPP_obj = carPoints_efl.getPP_obj();
	bool checkPP_obj = std::abs(optimizedPP_obj - targetPP_obj) < 0.1;
	test_vec.push_back(checkPP_obj);
	bool isPP_obj_var = DLS_PP_obj.getTargetCardinalPoints().isPP_obj_target();
	test_vec.push_back(isPP_obj_var);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

bool testDLS::testDLS_carPoint_PP_ima()
{
	// save bools in this vector
	std::vector<bool> test_vec;

	// surfaces PP_ima
	SphericalElement S0(/*radius*/ 150.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S1(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getNSF6_S1());
	SphericalElement S2(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF6_S1());
	ApertureStopElement S3(/* semi height*/3.0, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement S4(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,140.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	S1.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();


	std::vector<surfacePtr> opticalSystem_PP_ima_ptr = { S0.clone() , S1.clone(), S2.clone(), S3.clone() , S4.clone() };
	std::vector<interaction_ptr> interactions_PP_ima_ptr = { mRefrac.clone(), mRefrac.clone() , mRefrac.clone() ,mDoNothing.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSys(opticalSystem_PP_ima_ptr, interactions_PP_ima_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system PP_ima" << std::endl;
	oftenUse::print(optSys, mWave550);

	// check the start system
	real rmsStartSystem = 1698.87;
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSys, { 0.0,0.0,0.0 }, mWave550, rmsStartSystem, 0.5, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);

	// load the target cardinal point
	targetCardinalPointsStruct targetCarPointPP_ima;
	real targetPP_ima = -73.0;
	targetCarPointPP_ima.setTargetPP_ima(targetPP_ima);

	// optimization the system
	std::vector<VectorStructR3> field_vec = { {0.0,0.0,0.0} };
	std::vector<real> wave550_vec = { mWave550 };
	DLS DLS_PP_ima(/*optSysEle*/ optSys, field_vec, /*wavelength*/ wave550_vec, /*rings*/ 6, /*arms*/ 8, false, targetCarPointPP_ima);
	DLS_PP_ima.optimizeSystem_DLS_multiplicativ_Damping();

	// check cardinal point
	CardinalPoints carPoints_PP_ima(DLS_PP_ima.getOptimizedSystem_HLT(), mWave550, objectPoint_inf_obj::obj);
	real optimizedPP_ima = carPoints_PP_ima.getPP_ima();
	bool checkPP_ima = std::abs(optimizedPP_ima - targetPP_ima) < 0.1;
	test_vec.push_back(checkPP_ima);
	bool isPP_ima_var = DLS_PP_ima.getTargetCardinalPoints().isPP_ima_target();
	test_vec.push_back(isPP_ima_var);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

bool testDLS::testDLS_carPoint_EXPP_lastSurface()
{
	// save bools in this vector
	std::vector<bool> test_vec;

	// surfaces EXPP_lastSurface
	ApertureStopElement S0(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S1(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getF5_S1());
	SphericalElement S2(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getF5_S1());
	PlanElement S3(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	S1.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);


	std::vector<surfacePtr> opticalSystem_efl_ptr = { S0.clone() , S1.clone(), S2.clone(), S3.clone() };
	std::vector<interaction_ptr> interactions_efl_ptr = { mDoNothing.clone(),mRefrac.clone(), mRefrac.clone() , mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSys(opticalSystem_efl_ptr, interactions_efl_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system _efl" << std::endl;
	oftenUse::print(optSys, mWave550);

	// check the start system
	real rmsStartSystem = 330.308;
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSys, { 0.0,0.0,0.0 }, mWave550, rmsStartSystem, 0.5, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);

	// load the target cardinal point
	targetCardinalPointsStruct targetCarPointEFL;
	real targetEXPP_lastSurface = -70.0;
	targetCarPointEFL.setTargetEXPP_lastSurface(targetEXPP_lastSurface);

	// optimization the system
	std::vector<VectorStructR3> field_vec = { {0.0,0.0,0.0} };
	std::vector<real> wave550_vec = { mWave550 };
	DLS DLS_EXPP_lastSurface(/*optSysEle*/ optSys, field_vec, /*wavelength*/ wave550_vec, /*rings*/ 6, /*arms*/ 8, false, targetCarPointEFL);
	DLS_EXPP_lastSurface.optimizeSystem_DLS_multiplicativ_Damping();

	// check cardinal point
	CardinalPoints carPoints_efl(DLS_EXPP_lastSurface.getOptimizedSystem_HLT(), mWave550, objectPoint_inf_obj::obj);
	real optimizedEXPP_lastSurface = carPoints_efl.getEXPP_lastSurface();
	bool checkEXPP_lastSurface = std::abs(optimizedEXPP_lastSurface - targetEXPP_lastSurface) < 0.1;
	test_vec.push_back(checkEXPP_lastSurface);
	bool isEXPP_lastSurface_var = DLS_EXPP_lastSurface.getTargetCardinalPoints().isEXPP_lastSurface_target();
	test_vec.push_back(isEXPP_lastSurface_var);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

bool testDLS::testDLS_carPoint_EXPD()
{
	// save bools in this vector
	std::vector<bool> test_vec;

	// surfaces _efl
	SphericalElement S0(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNF2_S1());
	SphericalElement S1(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNF2_S1());
	ApertureStopElement S2(/* semi height*/2.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S3(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNF2_S1());
	SphericalElement S4(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNF2_S1());
	PlanElement S5(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,95.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	S4.setParameterRadius(0, 1000.0, 0.0, typeModifierVariable);


	std::vector<surfacePtr> opticalSystem_efl_ptr = { S0.clone() , S1.clone(), S2.clone(), S3.clone(), S4.clone(), S5.clone() };
	std::vector<interaction_ptr> interactions_efl_ptr = { mRefrac.clone(), mRefrac.clone() ,mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSys(opticalSystem_efl_ptr, interactions_efl_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system _efl" << std::endl;
	oftenUse::print(optSys, mWave550);

	// check the start system
	real rmsStartSystem = 1788.10;
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSys, { 0.0,0.0,0.0 }, mWave550, rmsStartSystem, 0.5, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);

	// load the target cardinal point
	targetCardinalPointsStruct targetCarPointEFL;
	real targetEXPD = 3.0;
	targetCarPointEFL.setTargetEXPD(targetEXPD);

	// optimization the system
	std::vector<VectorStructR3> field_vec = { {0.0,0.0,0.0} };
	std::vector<real> wave550_vec = { mWave550 };
	DLS DLS_EXPD(/*optSysEle*/ optSys, field_vec, /*wavelength*/ wave550_vec, /*rings*/ 6, /*arms*/ 8, false, targetCarPointEFL);
	DLS_EXPD.optimizeSystem_DLS_multiplicativ_Damping();

	// check cardinal point
	CardinalPoints carPoints_efl(DLS_EXPD.getOptimizedSystem_HLT(), mWave550, objectPoint_inf_obj::obj);
	real optimizedEXPD = carPoints_efl.getEXPD();
	bool checkEXPD = std::abs(optimizedEXPD - targetEXPD) < 0.1;
	test_vec.push_back(checkEXPD);
	bool isEXPD_var = DLS_EXPD.getTargetCardinalPoints().isEXPD_target();
	test_vec.push_back(isEXPD_var);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

bool testDLS::testDLS_carPoint_Magnification()
{
	// save bools in this vector
	std::vector<bool> test_vec;

	// surfaces _efl
	ApertureStopElement S0(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S1(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getF5_S1());
	SphericalElement S2(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getF5_S1(), /*refractive index B*/glasses.getNKF9_S1());
	SphericalElement S3(/*radius*/ 5.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNKF9_S1());
	PlanElement S4(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	S3.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);


	std::vector<surfacePtr> opticalSystem_efl_ptr = { S0.clone() , S1.clone(), S2.clone(), S3.clone() , S4.clone() };
	std::vector<interaction_ptr> interactions_efl_ptr = { mDoNothing.clone(),mRefrac.clone(), mRefrac.clone() ,mRefrac.clone() , mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSys(opticalSystem_efl_ptr, interactions_efl_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system Mag" << std::endl;
	oftenUse::print(optSys, mWave550);

	// check the start system
	real rmsStartSystem = 1163.26;
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSys, { 0.0,0.0,0.0 }, mWave550, rmsStartSystem, 0.5, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);

	// load the target cardinal point
	targetCardinalPointsStruct targetCarPointEFL;
	real targetMagnification = -0.5;
	targetCarPointEFL.setTargetMag(targetMagnification);

	// optimization the system
	std::vector<VectorStructR3> field_vec = { {0.0,0.0,0.0} };
	std::vector<real> wave550_vec = { mWave550 };
	DLS DLS_Magnification(/*optSysEle*/ optSys, field_vec, /*wavelength*/ wave550_vec, /*rings*/ 6, /*arms*/ 8, false, targetCarPointEFL);
	DLS_Magnification.optimizeSystem_DLS_multiplicativ_Damping();

	// check cardinal point
	CardinalPoints carPoints_efl(DLS_Magnification.getOptimizedSystem_HLT(), mWave550, objectPoint_inf_obj::obj);
	real optimizedMagnification = carPoints_efl.getMagnification();
	bool checkMagnification = std::abs(optimizedMagnification - targetMagnification) < 0.1;
	test_vec.push_back(checkMagnification);
	bool isMag_var = DLS_Magnification.getTargetCardinalPoints().isMag_target();
	test_vec.push_back(isMag_var);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

bool testDLS::testDLS_carPoint_NA_objSpace()
{
	// save bools in this vector
	std::vector<bool> test_vec;

	// surfaces _efl
	SphericalElement S0(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAF7_S1());
	SphericalElement S1(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF10_S1(), /*refractive index B*/glasses.getNLAF7_S1());
	SphericalElement S2(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF10_S1());
	ApertureStopElement S3(/* semi height*/2.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement S4(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	S1.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);


	std::vector<surfacePtr> opticalSystem_efl_ptr = { S0.clone() , S1.clone(), S2.clone(), S3.clone(), S4.clone() };
	std::vector<interaction_ptr> interactions_efl_ptr = { mRefrac.clone(), mRefrac.clone() ,mRefrac.clone() ,mDoNothing.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSys(opticalSystem_efl_ptr, interactions_efl_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system NA_objSpace" << std::endl;
	oftenUse::print(optSys, mWave550);

	// check the start system
	real rmsStartSystem = 1673.22;
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSys, { 0.0,0.0,0.0 }, mWave550, rmsStartSystem, 0.5, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);

	// load the target cardinal point
	targetCardinalPointsStruct targetCarPointEFL;
	real targetNA_objSpace = 0.05;
	targetCarPointEFL.setTargetNA_obj(targetNA_objSpace);

	// optimization the system
	std::vector<VectorStructR3> field_vec = { {0.0,0.0,0.0} };
	std::vector<real> wave550_vec = { mWave550 };
	DLS DLS_NA_objSpace(/*optSysEle*/ optSys, field_vec, /*wavelength*/ wave550_vec, /*rings*/ 6, /*arms*/ 8, false, targetCarPointEFL);
	DLS_NA_objSpace.optimizeSystem_DLS_multiplicativ_Damping();

	// check cardinal point
	CardinalPoints carPoints_efl(DLS_NA_objSpace.getOptimizedSystem_HLT(), mWave550, objectPoint_inf_obj::obj);
	real optimizedNA_objSpace = carPoints_efl.getNA_objSpace();
	bool checkNA_objSpace = std::abs(optimizedNA_objSpace - targetNA_objSpace) < 0.1;
	test_vec.push_back(checkNA_objSpace);
	bool isNA_objSpace_var = DLS_NA_objSpace.getTargetCardinalPoints().isNA_obj_target();
	test_vec.push_back(isNA_objSpace_var);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

bool testDLS::testDLS_carPoint_ENPP_firstSurface()
{
	// save bools in this vector
	std::vector<bool> test_vec;

	// surfaces _efl
	SphericalElement S0(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S1(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	ApertureStopElement S2(/* semi height*/1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S3(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getF5_S1());
	SphericalElement S4(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getK7_S1(), /*refractive index B*/glasses.getF5_S1());
	SphericalElement S5(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getK7_S1());
	PlanElement S6(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,150.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	S1.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);


	std::vector<surfacePtr> opticalSystem_efl_ptr = { S0.clone() , S1.clone(), S2.clone(), S3.clone() , S4.clone(), S5.clone(), S6.clone() };
	std::vector<interaction_ptr> interactions_efl_ptr = { mRefrac.clone(), mRefrac.clone(), mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSys(opticalSystem_efl_ptr, interactions_efl_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system ENPP_firstSurface" << std::endl;
	oftenUse::print(optSys, mWave550);

	// check the start system
	real rmsStartSystem = 1628.71;
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSys, { 0.0,0.0,0.0 }, mWave550, rmsStartSystem, 0.5, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);

	// load the target cardinal point
	targetCardinalPointsStruct targetCarPointEFL;
	real targetENPP_firstSurface = 20.5;
	targetCarPointEFL.setTargetENPP_firstSurface(targetENPP_firstSurface);

	// optimization the system
	std::vector<VectorStructR3> field_vec = { {0.0,0.0,0.0} };
	std::vector<real> wave550_vec = { mWave550 };
	DLS DLS_ENPP_firstSurface(/*optSysEle*/ optSys, field_vec, /*wavelength*/ wave550_vec, /*rings*/ 6, /*arms*/ 8, false, targetCarPointEFL);
	DLS_ENPP_firstSurface.optimizeSystem_DLS_multiplicativ_Damping();

	// check cardinal point
	CardinalPoints carPoints_efl(DLS_ENPP_firstSurface.getOptimizedSystem_HLT(), mWave550, objectPoint_inf_obj::obj);
	real optimizedENPP_firstSurface = carPoints_efl.getENPP_firstSurface();
	bool checkENPP_firstSurface = std::abs(optimizedENPP_firstSurface - targetENPP_firstSurface) < 0.1;
	test_vec.push_back(checkENPP_firstSurface);
	bool isENPP_firstSurface_var = DLS_ENPP_firstSurface.getTargetCardinalPoints().isENPP_firstSurface_target();
	test_vec.push_back(isENPP_firstSurface_var);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

bool testDLS::testDLS_carPoint_ENPP_global()
{
	// save bools in this vector
	std::vector<bool> test_vec;

	// surfaces _efl
	SphericalElement S0(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S1(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	ApertureStopElement S2(/* semi height*/1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S3(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getF5_S1());
	SphericalElement S4(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getK7_S1(), /*refractive index B*/glasses.getF5_S1());
	SphericalElement S5(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getK7_S1());
	PlanElement S6(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,150.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	S1.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);

	std::vector<surfacePtr> opticalSystem_efl_ptr = { S0.clone() , S1.clone(), S2.clone(), S3.clone() , S4.clone(), S5.clone(), S6.clone() };
	std::vector<interaction_ptr> interactions_efl_ptr = { mRefrac.clone(), mRefrac.clone(), mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSys(opticalSystem_efl_ptr, interactions_efl_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system ENPP_firstSurface" << std::endl;
	oftenUse::print(optSys, mWave550);

	// check the start system
	real rmsStartSystem = 1628.71;
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSys, { 0.0,0.0,0.0 }, mWave550, rmsStartSystem, 0.5, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);

	// load the target cardinal point
	targetCardinalPointsStruct targetCarPointEFL;
	real targetENPP_global = 50.0;
	targetCarPointEFL.setTargetENPP_globalCoori(targetENPP_global);

	// optimization the system
	std::vector<VectorStructR3> field_vec = { {0.0,0.0,0.0} };
	std::vector<real> wave550_vec = { mWave550 };
	DLS DLS_ENPP_global(/*optSysEle*/ optSys, field_vec, /*wavelength*/ wave550_vec, /*rings*/ 6, /*arms*/ 8, false, targetCarPointEFL);
	DLS_ENPP_global.optimizeSystem_DLS_multiplicativ_Damping();

	// check cardinal point
	CardinalPoints carPoints_efl(DLS_ENPP_global.getOptimizedSystem_HLT(), mWave550, objectPoint_inf_obj::obj);
	real optimizedENPP_global = carPoints_efl.getENPP_globalCoodi();
	bool checkENPP_global = std::abs(optimizedENPP_global - targetENPP_global) < 0.1;
	test_vec.push_back(checkENPP_global);
	bool isENPP_global_var = DLS_ENPP_global.getTargetCardinalPoints().isENPP_globalCoodi_target();
	test_vec.push_back(isENPP_global_var);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

bool testDLS::testDLS_carPoint_ENPD()
{
	// save bools in this vector
	std::vector<bool> test_vec;

	// surfaces _efl
	SphericalElement S0(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNLAF2_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement S1(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNLAF2_S1(), /*refractive index B*/glasses.getAir());
	ApertureStopElement S2(/* semi height*/4.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S3(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S4(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	PlanElement S5(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,80.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	S1.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);


	std::vector<surfacePtr> opticalSystem_efl_ptr = { S0.clone() , S1.clone(), S2.clone(), S3.clone(), S4.clone(), S5.clone() };
	std::vector<interaction_ptr> interactions_efl_ptr = { mRefrac.clone(), mRefrac.clone() ,mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(),mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSys(opticalSystem_efl_ptr, interactions_efl_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system ENPD" << std::endl;
	oftenUse::print(optSys, mWave550);

	// check the start system
	real rmsStartSystem = 1484.76;
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSys, { 0.0,0.0,0.0 }, mWave550, rmsStartSystem, 0.5, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);

	// load the target cardinal point
	targetCardinalPointsStruct targetCarPointEFL;
	real targetENPD = 6.0;
	targetCarPointEFL.setTargetENPD(targetENPD);

	// optimization the system
	std::vector<VectorStructR3> field_vec = { {0.0,0.0,0.0} };
	std::vector<real> wave550_vec = { mWave550 };
	DLS DLS_ENPD(/*optSysEle*/ optSys, field_vec, /*wavelength*/ wave550_vec, /*rings*/ 6, /*arms*/ 8, false, targetCarPointEFL);
	DLS_ENPD.optimizeSystem_DLS_multiplicativ_Damping();

	// check cardinal point
	CardinalPoints carPoints_efl(DLS_ENPD.getOptimizedSystem_HLT(), mWave550, objectPoint_inf_obj::obj);
	real optimizedENPD = carPoints_efl.getENPD();
	bool checkENPD = std::abs(optimizedENPD - targetENPD) < 0.1;
	test_vec.push_back(checkENPD);
	bool isENPD_var = DLS_ENPD.getTargetCardinalPoints().isENPD_target();
	test_vec.push_back(isENPD_var);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

bool testDLS::testDLS_carPoint_f_number_imaSpace()
{
	// save bools in this vector
	std::vector<bool> test_vec;

	// surfaces _efl
	SphericalElement S0(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNLAF2_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement S1(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNLAF2_S1(), /*refractive index B*/glasses.getNSK11_S1());
	SphericalElement S2(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSK11_S1());
	ApertureStopElement S3(/* semi height*/1.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement S4(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	S2.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);


	std::vector<surfacePtr> opticalSystem_efl_ptr = { S0.clone() , S1.clone(), S2.clone(), S3.clone(), S4.clone() };
	std::vector<interaction_ptr> interactions_efl_ptr = { mRefrac.clone(), mRefrac.clone() , mRefrac.clone() ,mDoNothing.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSys(opticalSystem_efl_ptr, interactions_efl_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system f_number_imaSpace" << std::endl;
	oftenUse::print(optSys, mWave550);

	// check the start system
	real rmsStartSystem = 948.487;
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSys, { 0.0,0.0,0.0 }, mWave550, rmsStartSystem, 0.5, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);

	// load the target cardinal point
	targetCardinalPointsStruct targetCarPointEFL;
	real targetf_number_imaSpace = 25.0;
	targetCarPointEFL.setTargetFnum(targetf_number_imaSpace);

	// optimization the system
	std::vector<VectorStructR3> field_vec = { {0.0,0.0,0.0} };
	std::vector<real> wave550_vec = { mWave550 };
	DLS DLS_f_number_imaSpace(/*optSysEle*/ optSys, field_vec, /*wavelength*/ wave550_vec, /*rings*/ 6, /*arms*/ 8, false, targetCarPointEFL);
	DLS_f_number_imaSpace.optimizeSystem_DLS_multiplicativ_Damping();

	// check cardinal point
	CardinalPoints carPoints_efl(DLS_f_number_imaSpace.getOptimizedSystem_HLT(), mWave550, objectPoint_inf_obj::obj);
	real optimizedf_number_imaSpace = carPoints_efl.getF_num_imaSpace();
	bool checkf_number_imaSpace = std::abs(optimizedf_number_imaSpace - targetf_number_imaSpace) < 0.1;
	test_vec.push_back(checkf_number_imaSpace);
	bool isf_number_imaSpace_var = DLS_f_number_imaSpace.getTargetCardinalPoints().isF_num_target();
	test_vec.push_back(isf_number_imaSpace_var);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

bool testDLS::testDLS_carPoint_NA_imaSpace()
{
	// save bools in this vector
	std::vector<bool> test_vec;

	// surfaces _efl
	ApertureStopElement S0(/* semi height*/2.5, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S1(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNLAF2_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement S2(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNLAF2_S1(), /*refractive index B*/glasses.getNSK11_S1());
	SphericalElement S3(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSK11_S1());
	PlanElement S4(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	S3.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);


	std::vector<surfacePtr> opticalSystem_efl_ptr = { S0.clone() , S1.clone(), S2.clone(), S3.clone(), S4.clone() };
	std::vector<interaction_ptr> interactions_efl_ptr = { mDoNothing.clone(), mRefrac.clone(), mRefrac.clone() , mRefrac.clone(),  mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSys(opticalSystem_efl_ptr, interactions_efl_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system NA_imaSpace" << std::endl;
	oftenUse::print(optSys, mWave550);

	// check the start system
	real rmsStartSystem = 5342.97;
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSys, { 0.0,0.0,0.0 }, mWave550, rmsStartSystem, 0.5, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);

	// load the target cardinal point
	targetCardinalPointsStruct targetCarPointEFL;
	real targetNA_imaSpace = 0.05;
	targetCarPointEFL.setTargetNA_imaSpace(targetNA_imaSpace);

	// optimization the system
	std::vector<VectorStructR3> field_vec = { {0.0,0.0,0.0} };
	std::vector<real> wave550_vec = { mWave550 };
	DLS DLS_NA_imaSpace(/*optSysEle*/ optSys, field_vec, /*wavelength*/ wave550_vec, /*rings*/ 6, /*arms*/ 8, false, targetCarPointEFL);
	DLS_NA_imaSpace.optimizeSystem_DLS_multiplicativ_Damping();

	// check cardinal point
	CardinalPoints carPoints_efl(DLS_NA_imaSpace.getOptimizedSystem_HLT(), mWave550, objectPoint_inf_obj::obj);
	real optimizedNA_imaSpace = carPoints_efl.getNA_imaSpace();
	bool checkNA_imaSpace = std::abs(optimizedNA_imaSpace - targetNA_imaSpace) < 0.1;
	test_vec.push_back(checkNA_imaSpace);
	bool isNA_imaSpace_var = DLS_NA_imaSpace.getTargetCardinalPoints().isNA_imaSpace();
	test_vec.push_back(isNA_imaSpace_var);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

bool testDLS::testDLS_carPoint_WFNO()
{
	// save bools in this vector
	std::vector<bool> test_vec;

	// surfaces _efl
	ApertureStopElement S0(/* semi height*/2.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S1(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSF6_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement S2(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF6_S1());
	PlanElement S3(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	S1.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);


	std::vector<surfacePtr> opticalSystem_efl_ptr = { S0.clone() , S1.clone(), S2.clone(), S3.clone() };
	std::vector<interaction_ptr> interactions_efl_ptr = { mDoNothing.clone(), mRefrac.clone(), mRefrac.clone() , mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSys(opticalSystem_efl_ptr, interactions_efl_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system _WFNO" << std::endl;
	oftenUse::print(optSys, mWave550);

	// check the start system
	real rmsStartSystem = 3658.69;
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSys, { 0.0,0.0,0.0 }, mWave550, rmsStartSystem, 0.5, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);

	// load the target cardinal point
	targetCardinalPointsStruct targetCarPointEFL;
	real targetWFNO = 8.0;
	targetCarPointEFL.setTargetWFNO(targetWFNO);

	// optimization the system
	std::vector<VectorStructR3> field_vec = { {0.0,0.0,0.0} };
	std::vector<real> wave550_vec = { mWave550 };
	DLS DLS_WFNO(/*optSysEle*/ optSys, field_vec, /*wavelength*/ wave550_vec, /*rings*/ 6, /*arms*/ 8, false, targetCarPointEFL);
	DLS_WFNO.optimizeSystem_DLS_multiplicativ_Damping();

	// check cardinal point
	CardinalPoints carPoints_efl(DLS_WFNO.getOptimizedSystem_HLT(), mWave550, objectPoint_inf_obj::obj);
	real optimizedWFNO = carPoints_efl.getWorkingFnumber();
	bool checkWFNO = std::abs(optimizedWFNO - targetWFNO) < 0.1;
	test_vec.push_back(checkWFNO);
	bool isWFNO_var = DLS_WFNO.getTargetCardinalPoints().isTargetWFNO();
	test_vec.push_back(isWFNO_var);

	bool returnChecker = Math::checkTrueOfVectorElements(test_vec);
	return returnChecker;
}

// E1
bool testDLS::testDLS__E0_MultiCarPoints()
{
	//***
	unsigned int systemNum = 1;
	std::cout << "check optimize system genetic and DLS system number: " << systemNum << std::endl;
	//***

	std::vector<bool> check_vec;

	// surfaces E0
	ApertureStopElement AperStop0_E1(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E1(/*radius*/ 25.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2_E1(/*radius*/ 25.00, /*semi height*/7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF11_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3_E1(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF11_S1());
	SphericalElement Sphere4_E1(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF4_S1());
	SphericalElement Sphere5_E1(/*radius*/ 70.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF4_S1());
	SphericalElement Sphere6_E1(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere7_E1(/*radius*/ 7.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere8_E1(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	PlanElement Plan9_E1(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,80.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere3_E1.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere5_E1.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);

	surfacePtr Aper0_E1_ptr = AperStop0_E1.clone();
	surfacePtr Sphere1_E1_ptr = Sphere1_E1.clone();
	surfacePtr Sphere2_E1_ptr = Sphere2_E1.clone();
	surfacePtr Sphere3_E1_ptr = Sphere3_E1.clone();
	surfacePtr Sphere4_E1_ptr = Sphere4_E1.clone();
	surfacePtr Sphere5_E1_ptr = Sphere5_E1.clone();
	surfacePtr Sphere6_E1_ptr = Sphere6_E1.clone();
	surfacePtr Sphere7_E1_ptr = Sphere7_E1.clone();
	surfacePtr Sphere8_E1_ptr = Sphere8_E1.clone();
	surfacePtr Plan9_E1_ptr = Plan9_E1.clone();

	std::vector<surfacePtr> opticalSystem_E1_ptr{ Aper0_E1_ptr, Sphere1_E1_ptr, Sphere2_E1_ptr , Sphere3_E1_ptr, Sphere4_E1_ptr, Sphere5_E1_ptr, Sphere6_E1_ptr, Sphere7_E1_ptr, Sphere8_E1_ptr, Plan9_E1_ptr };
	std::vector<interaction_ptr> interactions_E1_ptr{ mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone() };

	//	build optical system
	OpticalSystemElement optSysEle_E1(opticalSystem_E1_ptr, interactions_E1_ptr);

	// check the start system
	std::vector<real> rmsStartSystem_Z{ 132.546,125.691,106.697 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E1, mFields012_obj_vec, mWavelength_FdV_vec, rmsStartSystem_Z, 0.1, compareTOM_Zemax::comEqual);
	check_vec.push_back(checkStartSys);

	// check start cardinal points
	real ref_EFFL = 25.022;
	real targetEFFL = 30.0;
	real ref_EXPP = 24.085;
	real targetEXPP = 35.0;
	real ref_EXPD = 3.104;
	real targetEXPD = 4.5;
	real ref_Mag = -0.693;
	real targetPMAG = -1.0;
	real ref_ENPP = 0.0;
	real targetENPP = 0.0;
	real ref_WFNO = 6.910;
	real targetWFNO = 9.0;


	CardinalPoints carPointsE0(optSysEle_E1, mWavelength_FdV_vec[0], objectPoint_inf_obj::obj);
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
	DLS DLS_E1(/*optSysEle*/ optSysEle_E1, /*fields*/ mFields012_obj_vec, /*wavelengths*/ mWavelength_FdV_vec, /*rings*/ 6, /*arms*/ 8, /*target cardinal points*/ targetCarPoints, /*default DLS*/ oftenUse::getDefaultPara_DLS(false));


	DLS_E1.optimizeSystem_DLS_multiplicativ_Damping();
	OpticalSystemElement optimizedOptSysEle = DLS_E1.getOptimizedSystem_HLT();

	oftenUse::print(optimizedOptSysEle, mWavelength_FdV_vec[0]);

	// ** compare the results ** //
	// surfaces E1
	ApertureStopElement AperStop0_E1_compare(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E1_compare(/*radius*/ 25.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2_E1_compare(/*radius*/ 25.00, /*semi height*/7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF11_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3_E1_compare(/*radius*/ 14.200, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF11_S1());
	SphericalElement Sphere4_E1_compare(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF4_S1());
	SphericalElement Sphere5_E1_compare(/*radius*/ 59.197, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNSF4_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere6_E1_compare(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere7_E1_compare(/*radius*/ 7.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere8_E1_compare(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	PlanElement Plan9_E1_compare(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,80.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	surfacePtr Aper0_E1_compare_ptr = AperStop0_E1_compare.clone();
	surfacePtr Sphere1_E1_compare_ptr = Sphere1_E1_compare.clone();
	surfacePtr Sphere2_E1_compare_ptr = Sphere2_E1_compare.clone();
	surfacePtr Sphere3_E1_compare_ptr = Sphere3_E1_compare.clone();
	surfacePtr Sphere4_E1_compare_ptr = Sphere4_E1_compare.clone();
	surfacePtr Sphere5_E1_compare_ptr = Sphere5_E1_compare.clone();
	surfacePtr Sphere6_E1_compare_ptr = Sphere6_E1_compare.clone();
	surfacePtr Sphere7_E1_compare_ptr = Sphere7_E1_compare.clone();
	surfacePtr Sphere8_E1_compare_ptr = Sphere8_E1_compare.clone();
	surfacePtr Plan9_E1_compare_ptr = Plan9_E1_compare.clone();

	std::vector<surfacePtr> opticalSystem_E1_compare_ptr{ Aper0_E1_compare_ptr, Sphere1_E1_compare_ptr, Sphere2_E1_compare_ptr , Sphere3_E1_compare_ptr, Sphere4_E1_compare_ptr, Sphere5_E1_compare_ptr, Sphere6_E1_compare_ptr, Sphere7_E1_compare_ptr, Sphere8_E1_compare_ptr, Plan9_E1_compare_ptr };
	std::vector<interaction_ptr> interactions_E1_compare_ptr{ mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSysEle_E1_ref(opticalSystem_E1_compare_ptr, interactions_E1_compare_ptr);
	// ** compare the results ** //

	// **
	targetCardinalPointsStruct checkTargetCarPoints_ref = targetCarPoints;
	std::vector<real> checkTargetCarPoints_vector_ref;
	checkTargetCarPoints_vector_ref.resize(targetCarPoints.getNumerOfTargets());
	optSysEle_E1_ref.setRefractiveIndexAccordingToWavelength(mWavelength_FdV_vec[0]);
	checkTargetCarPoints_ref.calcualteMeritVal_targetCardinalPoints_forDLS(optSysEle_E1_ref.getOptSys_LLT_buildSystem(), DLS_E1.getInfOrObj(), checkTargetCarPoints_vector_ref);
	// **

	// **
	targetCardinalPointsStruct checkTargetCarPoints_tom = targetCarPoints;
	std::vector<real> checkTargetCarPoints_vector_tom;
	checkTargetCarPoints_vector_tom.resize(targetCarPoints.getNumerOfTargets());
	optimizedOptSysEle.setRefractiveIndexAccordingToWavelength(mWavelength_FdV_vec[0]);
	checkTargetCarPoints_tom.calcualteMeritVal_targetCardinalPoints_forDLS(optimizedOptSysEle.getOptSys_LLT_buildSystem(), DLS_E1.getInfOrObj(), checkTargetCarPoints_vector_tom);
	// **

	real sum_ref = Math::sumAllVectorValues_abs(checkTargetCarPoints_vector_ref);
	real sum_tom = Math::sumAllVectorValues_abs(checkTargetCarPoints_vector_tom);

	bool checkBetter = sum_tom <= sum_ref;
	check_vec.push_back(checkBetter);

	bool returnChecker = Math::checkTrueOfVectorElements(check_vec);
	return returnChecker;
}

// test opti rms and cardinal points
bool testDLS::testDLS_superFct_optiRMSAndCarPoints()
{
	std::vector<bool> testSuperFct_vec_RMS_carPoints;

	// opti rms and efl
	bool checkRMS_EFL = testRMSandEFL_E0_DLS();
	testSuperFct_vec_RMS_carPoints.push_back(checkRMS_EFL);

	// opti rms and efl,PMAG
	bool checkRMS_EFL_PMAG = testRMSandEFLandPMAG();
	testSuperFct_vec_RMS_carPoints.push_back(checkRMS_EFL_PMAG);

	bool returnChecker = Math::checkTrueOfVectorElements(testSuperFct_vec_RMS_carPoints);	// test rms and efl, PMAG
	return returnChecker;
}
// test rms and efl
bool testDLS::testRMSandEFL_E0_DLS()
{
	std::vector<bool> test_rms_carP_E0_vec;

	// surfaces _rms_carP_E0
	ApertureStopElement AperStop0_rms_carP_E0(/* semi height*/1.5, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_rms_carP_E0(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere2_rms_carP_E0(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere3_rms_carP_E0(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	PlanElement Plan4_rms_carP_E0(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere2_rms_carP_E0.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);

	surfacePtr Aper0_rms_carP_E0_ptr = AperStop0_rms_carP_E0.clone();
	surfacePtr Sphere1_rms_carP_E0_ptr = Sphere1_rms_carP_E0.clone();
	surfacePtr Sphere2_rms_carP_E0_ptr = Sphere2_rms_carP_E0.clone();
	surfacePtr Sphere3_rms_carP_E0_ptr = Sphere3_rms_carP_E0.clone();
	surfacePtr Plan4_rms_carP_E0_ptr = Plan4_rms_carP_E0.clone();

	std::vector<surfacePtr> opticalSystem_rms_carP_E0_ptr{ Aper0_rms_carP_E0_ptr, Sphere1_rms_carP_E0_ptr , Sphere2_rms_carP_E0_ptr, Sphere3_rms_carP_E0_ptr, Plan4_rms_carP_E0_ptr };
	std::vector<interaction_ptr> interactions_rms_carP_E0_ptr{ mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_rms_carP_E0(opticalSystem_rms_carP_E0_ptr, interactions_rms_carP_E0_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system _rms_carP_E0" << std::endl;
	oftenUse::print(optSystemElement_rms_carP_E0, mWave587d);

	// check the start system
	std::vector<real> rmsStartSystem_Z{ 434.376,434.124,433.366 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_rms_carP_E0, mFields000_inf_vec, mFields012_inf_vec, mWavelength_FdV_vec, rmsStartSystem_Z, 0.1, compareTOM_Zemax::comEqual);
	test_rms_carP_E0_vec.push_back(checkStartSys);

	// check initial cardinal point
	CardinalPoints carPoints(optSystemElement_rms_carP_E0, mWave587d, objectPoint_inf_obj::inf);
	real efl_ref = 17.5725;
	real efl_calc = carPoints.getEFL();
	bool checkEFL = Math::compareTwoNumbers_tolerance(efl_ref, efl_calc, 0.1);
	test_rms_carP_E0_vec.push_back(checkEFL);

	// load the target cardinal point
	targetCardinalPointsStruct targetCarPointEFL;
	real targetEFL = 20.0;
	targetCarPointEFL.setTargetEFL(targetEFL);

	// optimization
	DLS DLS_rms_carP_E0(/*optSysEle*/ optSystemElement_rms_carP_E0,/*fields X*/ mFields000_inf_vec, /*fields X*/ mFields012_inf_vec, /*wavelength*/ mWavelength_FdV_vec, /*rings*/ 6, /*arms*/ 8, true, targetCarPointEFL);
	DLS_rms_carP_E0.setFactorPositionDeviation(0.00001);
	DLS_rms_carP_E0.setFactorRadiusDeviation(0.00001);
	DLS_rms_carP_E0.setMaxWorstCounter(250);
	DLS_rms_carP_E0.setMaxBorderViolations(5);
	DLS_rms_carP_E0.setMaxInterations(500);
	DLS_rms_carP_E0.setMaxDeltaParameter(50.0);
	DLS_rms_carP_E0.setFlipOrientationRadius(1000.0);
	DLS_rms_carP_E0.setMinDeltaParameter(0.00000001);
	DLS_rms_carP_E0.setFactorGettingBetter(0.4);
	DLS_rms_carP_E0.setFactorGettingWorst(1.9);

	DLS_rms_carP_E0.optimizeSystem_DLS_multiplicativ_Damping();
	OpticalSystemElement optimizedOptSysEle = DLS_rms_carP_E0.getOptimizedSystem_HLT();

	oftenUse::print(optimizedOptSysEle, mWavelength_FdV_vec[0]);

	// check for optimized efl
	bool checkRMS_bestMerit_optimizedSystem = oftenUse::checkDLS_resultRMS(DLS_rms_carP_E0, 0.1);
	test_rms_carP_E0_vec.push_back(checkRMS_bestMerit_optimizedSystem);

	// check efl
	CardinalPoints carPoints_rms_carP_E0(optimizedOptSysEle, mWave587d, objectPoint_inf_obj::inf);
	real calcEFL = carPoints_rms_carP_E0.getEFL();
	bool checkEFL_opti = std::abs(calcEFL - targetEFL) < 0.1;
	test_rms_carP_E0_vec.push_back(checkEFL_opti);

	bool returnChecker_rms_carP_E0 = Math::checkTrueOfVectorElements(test_rms_carP_E0_vec);
	return returnChecker_rms_carP_E0;
}

// test rms and efl, PMAG
bool testDLS::testRMSandEFLandPMAG()
{
	std::vector<bool> test_rms_carP_E0_vec;

	// surfaces _rms_carP_E0
	ApertureStopElement AperStop0_rms_carP_E0(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_rms_carP_E0(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/ glasses.getNBK7_S1());
	SphericalElement Sphere2_rms_carP_E0(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/ glasses.getNBK7_S1());
	SphericalElement Sphere3_rms_carP_E0(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere4_rms_carP_E0(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	PlanElement Plan5_rms_carP_E0(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,90.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere2_rms_carP_E0.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere4_rms_carP_E0.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);

	surfacePtr Aper0_rms_carP_E0_ptr = AperStop0_rms_carP_E0.clone();
	surfacePtr Sphere1_rms_carP_E0_ptr = Sphere1_rms_carP_E0.clone();
	surfacePtr Sphere2_rms_carP_E0_ptr = Sphere2_rms_carP_E0.clone();
	surfacePtr Sphere3_rms_carP_E0_ptr = Sphere3_rms_carP_E0.clone();
	surfacePtr Sphere4_rms_carP_E0_ptr = Sphere4_rms_carP_E0.clone();
	surfacePtr Plan5_rms_carP_E0_ptr = Plan5_rms_carP_E0.clone();

	std::vector<surfacePtr> opticalSystem_rms_carP_E0_ptr{ Aper0_rms_carP_E0_ptr, Sphere1_rms_carP_E0_ptr , Sphere2_rms_carP_E0_ptr, Sphere3_rms_carP_E0_ptr, Sphere4_rms_carP_E0_ptr, Plan5_rms_carP_E0_ptr };
	std::vector<interaction_ptr> interactions_rms_carP_E0_ptr{ mDoNothing.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_rms_carP_E0(opticalSystem_rms_carP_E0_ptr, interactions_rms_carP_E0_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system _rms_carP_E0" << std::endl;
	oftenUse::print(optSystemElement_rms_carP_E0, mWave587d);

	// check single ray trace
	optSystemElement_rms_carP_E0.setRefractiveIndexAccordingToWavelength(mWave587d);
	bool checkSingleRay = oftenUse::checkRayTracing({ 0.0,0.0,0.0 }, { 0.0,1.0,10.0 }, { 0.0,0.77039249558,90.0 }, optSystemElement_rms_carP_E0.getOptSys_LLT_buildSystem(), 5, 0.1);
	test_rms_carP_E0_vec.push_back(checkSingleRay);

	// check the start system
	std::vector<real> rmsStartSystem_Z{ 587.141,575.136,540.054 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_rms_carP_E0, mField0_05_1_obj_vec, mWavelength_FdV_vec, rmsStartSystem_Z, 1.0, compareTOM_Zemax::comEqual);
	test_rms_carP_E0_vec.push_back(checkStartSys);

	// check initial cardinal point
	CardinalPoints carPoints(optSystemElement_rms_carP_E0, mWave587d, objectPoint_inf_obj::obj);
	real efl_ref = 22.9258;
	real PMAG_ref = -2.253;
	real efl_calc = carPoints.getEFL();
	real PMAG_calc = carPoints.getMagnification();
	bool checkEFL = Math::compareTwoNumbers_tolerance(efl_ref, efl_calc, 0.1);
	bool checkPMAG = Math::compareTwoNumbers_tolerance(PMAG_ref, PMAG_calc, 0.1);
	test_rms_carP_E0_vec.push_back(checkEFL);

	// load the target cardinal point
	targetCardinalPointsStruct targetCarPointEFL_PMAG;
	real targetEFL = 20.0;
	real targetPMAG = -2.0;
	targetCarPointEFL_PMAG.setTargetEFL(targetEFL);
	targetCarPointEFL_PMAG.setTargetMag(targetPMAG);

	// optimization
	DLS DLS_rms_carP_E0(/*optSysEle*/ optSystemElement_rms_carP_E0,/*field obj*/ mField0_05_1_obj_vec, /*wavelength*/ mWavelength_FdV_vec, /*rings*/ 6, /*arms*/ 8, true, targetCarPointEFL_PMAG);
	DLS_rms_carP_E0.setFactorPositionDeviation(0.00001);
	DLS_rms_carP_E0.setFactorRadiusDeviation(0.00001);
	DLS_rms_carP_E0.setMaxWorstCounter(250);
	DLS_rms_carP_E0.setMaxBorderViolations(5);
	DLS_rms_carP_E0.setMaxInterations(500);
	DLS_rms_carP_E0.setMaxDeltaParameter(50.0);
	DLS_rms_carP_E0.setFlipOrientationRadius(1000.0);
	DLS_rms_carP_E0.setMinDeltaParameter(0.00000001);
	DLS_rms_carP_E0.setFactorGettingBetter(0.4);
	DLS_rms_carP_E0.setFactorGettingWorst(1.9);

	DLS_rms_carP_E0.optimizeSystem_DLS_multiplicativ_Damping();
	OpticalSystemElement optimizedOptSysEle = DLS_rms_carP_E0.getOptimizedSystem_HLT();

	oftenUse::print(optimizedOptSysEle, mWavelength_FdV_vec[0]);

	// check for optimized efl
	bool checkRMS_bestMerit_optimizedSystem = oftenUse::checkDLS_resultRMS(DLS_rms_carP_E0, 0.1);
	test_rms_carP_E0_vec.push_back(checkRMS_bestMerit_optimizedSystem);

	// check efl and PMAG
	CardinalPoints carPoints_rms_carP_E0(optimizedOptSysEle, mWave587d, objectPoint_inf_obj::obj);
	real calcEFL = carPoints_rms_carP_E0.getEFL();
	bool checkEFL_opti = std::abs(calcEFL - targetEFL) < 0.1;
	real calcPMAG = carPoints_rms_carP_E0.getMagnification();
	bool checkPMAG_opti = std::abs(calcPMAG - targetPMAG) < 0.1;
	test_rms_carP_E0_vec.push_back(checkEFL_opti);
	test_rms_carP_E0_vec.push_back(checkPMAG_opti);



	bool returnChecker_rms_carP_E0 = Math::checkTrueOfVectorElements(test_rms_carP_E0_vec);
	return returnChecker_rms_carP_E0;
}