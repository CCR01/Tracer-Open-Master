#include "DLSmulticheck.h"

// DLS
#include "..\..\..\OptimizeSystem\DampedLeastSquares.h"

// for light ray struct
#include "..\..\..\LowLevelTracing\Interaction\InteractionRay_LLT.h"

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

typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interactionPtr;

DLSmulticheck::DLSmulticheck()
{
	loadImportantStuff();
}
DLSmulticheck::~DLSmulticheck() {}

void DLSmulticheck::loadImportantStuff()
{
	mFactorBetter_vec = { 0.2,0.2,0.2,0.2,0.2,0.2,0.2,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.4,0.4,0.4,0.4,0.4,0.4,0.4,0.5,0.5,0.5,0.49,0.5,0.5,0.5,0.6,0.6,0.6,0.6,0.6,0.6,0.6,0.7,0.7,0.7,0.7,0.7,0.7,0.7,0.8,0.8,0.8,0.8,0.8,0.8,0.8 };
	mFactorWorst_vec = { 1.7,1.8,1.9,2.0,2.1,2.2,2.3,1.7,1.8,1.9,2.0,2.1,2.2,2.3,1.7,1.8,1.9,2.0,2.1,2.2,2.3,1.7,1.8,1.9,2.01,2.1,2.2,2.3,1.7,1.8,1.9,2.0,2.1,2.2,2.3,1.7,1.8,1.9,2.0,2.1,2.2,2.3,1.7,1.8,1.9,2.0,2.1,2.2,2.3 };

	// mFactorBetter_vec = { 0.4 };
	// mFactorWorst_vec = { 1.9 };

	mTolerance = 0.1;

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
}

// check super function
bool DLSmulticheck::checkSuperFuction()
{
	std::vector<bool> checkSuperFunc{};

	//bool E0 = checkE0();
	//checkSuperFunc.push_back(E0);
	//
	//bool E1 = checkE1();
	//checkSuperFunc.push_back(E1);
	//
	//bool E2 = checkE2();
	//checkSuperFunc.push_back(E2);
	//
	//bool E3 = checkE3();
	//checkSuperFunc.push_back(E3);
	//
	//bool E4 = checkE4();
	//checkSuperFunc.push_back(E4);
	//
	//bool E5 = checkE5();
	//checkSuperFunc.push_back(E5);
	//
	//bool E6 = checkE6();
	//checkSuperFunc.push_back(E6);
	//
	//bool E7 = checkE7();
	//checkSuperFunc.push_back(E7);
	//
	//bool E8 = checkE8();
	//checkSuperFunc.push_back(E8);
	//
	//bool E9 = checkE9();
	//checkSuperFunc.push_back(E9);
	//
	//bool E10 = checkE10();
	//checkSuperFunc.push_back(E10);
	//
	//bool E11 = checkE11();
	//checkSuperFunc.push_back(E11);
	//
	//bool E12 = checkE12();
	//checkSuperFunc.push_back(E12);
	//
	//bool E13 = checkE13();
	//checkSuperFunc.push_back(E13);
	//
	//bool E14 = checkE14();
	//checkSuperFunc.push_back(E14);
	//
	//bool E15 = checkE15();
	//checkSuperFunc.push_back(E15);
	//
	//bool E16 = checkE16();
	//checkSuperFunc.push_back(E16);
	//
	//bool E17 = checkE17();
	//checkSuperFunc.push_back(E17);
	//
	//bool E18 = checkE18();
	//checkSuperFunc.push_back(E18);
	//
	//bool E19 = checkE19();
	//checkSuperFunc.push_back(E19);
	//
	//bool E20 = checkE20();
	//checkSuperFunc.push_back(E20);

	//bool E21 = checkE21();
	//checkSuperFunc.push_back(E21);

	bool checkSuFc = Math::checkTrueOfVectorElements(checkSuperFunc);
	return checkSuFc;
}


// checkSystem E0
bool DLSmulticheck::checkE0()
{
	//***
	unsigned int systemNum = 0;
	std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	//***

	std::vector<bool> check_vec;

	//// surfaces E0
	//ApertureStopElement AperStop0_E0(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Sphere1_E0(/*radius*/ 25.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
	//SphericalElement Sphere2_E0(/*radius*/ 25.00, /*semi height*/7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF11_S1(), /*refractive index B*/glasses.getBK7_S1());
	//SphericalElement Sphere3_E0(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF11_S1());
	//SphericalElement Sphere4_E0(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF3_S1());
	//SphericalElement Sphere5_E0(/*radius*/ 70.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF3_S1());
	//SphericalElement Sphere6_E0(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	//SphericalElement Sphere7_E0(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	//SphericalElement Sphere8_E0(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	//PlanElement Plan9_E0(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,80.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//Sphere3_E0.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere5_E0.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere7_E0.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//
	//surfacePtr Aper0_E0_ptr = AperStop0_E0.clone();
	//surfacePtr Sphere1_E0_ptr = Sphere1_E0.clone();
	//surfacePtr Sphere2_E0_ptr = Sphere2_E0.clone();
	//surfacePtr Sphere3_E0_ptr = Sphere3_E0.clone();
	//surfacePtr Sphere4_E0_ptr = Sphere4_E0.clone();
	//surfacePtr Sphere5_E0_ptr = Sphere5_E0.clone();
	//surfacePtr Sphere6_E0_ptr = Sphere6_E0.clone();
	//surfacePtr Sphere7_E0_ptr = Sphere7_E0.clone();
	//surfacePtr Sphere8_E0_ptr = Sphere8_E0.clone();
	//surfacePtr Plan9_E0_ptr = Plan9_E0.clone();
	//
	//std::vector<surfacePtr> opticalSystemE0_ptr{ Aper0_E0_ptr, Sphere1_E0_ptr, Sphere2_E0_ptr , Sphere3_E0_ptr, Sphere4_E0_ptr, Sphere5_E0_ptr, Sphere6_E0_ptr, Sphere7_E0_ptr, Sphere8_E0_ptr, Plan9_E0_ptr };
	//std::vector<interaction_ptr> interactionsE0_ptr{ doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSysEle_E0(opticalSystemE0_ptr, interactionsE0_ptr);
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 209.256,204.757,191.674 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E0, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS_E0(/*optSysEle*/ optSysEle_E0,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 17.049,22.008,35.681 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS_E0, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

// checkSystem E1
bool DLSmulticheck::checkE1()
{

	////***
	//unsigned int systemNum = 1;
	//std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	////***
	//
	std::vector<bool> check_vec;
	//
	//// surfaces E1
	//ApertureStopElement AperStop0_E1(/* semi height*/1.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Sphere1_E1(/*radius*/ 35.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
	//SphericalElement Sphere2_E1(/*radius*/ 35.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF11_S1(), /*refractive index B*/glasses.getBK7_S1());
	//SphericalElement Sphere3_E1(/*radius*/ 45.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF11_S1());
	//SphericalElement Sphere4_E1(/*radius*/ 100.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF3_S1());
	//SphericalElement Sphere5_E1(/*radius*/ 90.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF3_S1());
	//SphericalElement Sphere6_E1(/*radius*/ 60.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	//SphericalElement Sphere7_E1(/*radius*/ 45.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	//SphericalElement Sphere8_E1(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	//SphericalElement Sphere9_E1(/*radius*/ 80.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement Sphere10_E1(/*radius*/ 70.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	//PlanElement Plan11_E1(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,115.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//Sphere1_E1.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere2_E1.setParameterPointZ(0.0, 0.0, 0.0, typeModifierVariable);
	//Sphere10_E1.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//
	//surfacePtr Aper0_E1_ptr = AperStop0_E1.clone();
	//surfacePtr Sphere1_E1_ptr = Sphere1_E1.clone();
	//surfacePtr Sphere2_E1_ptr = Sphere2_E1.clone();
	//surfacePtr Sphere3_E1_ptr = Sphere3_E1.clone();
	//surfacePtr Sphere4_E1_ptr = Sphere4_E1.clone();
	//surfacePtr Sphere5_E1_ptr = Sphere5_E1.clone();
	//surfacePtr Sphere6_E1_ptr = Sphere6_E1.clone();
	//surfacePtr Sphere7_E1_ptr = Sphere7_E1.clone();
	//surfacePtr Sphere8_E1_ptr = Sphere8_E1.clone();
	//surfacePtr Sphere9_E1_ptr = Sphere9_E1.clone();
	//surfacePtr Sphere10_E1_ptr = Sphere10_E1.clone();
	//surfacePtr Plan11_E1_ptr = Plan11_E1.clone();
	//
	//std::vector<surfacePtr> opticalSystemE1_ptr{ Aper0_E1_ptr, Sphere1_E1_ptr, Sphere2_E1_ptr , Sphere3_E1_ptr, Sphere4_E1_ptr, Sphere5_E1_ptr, Sphere6_E1_ptr, Sphere7_E1_ptr, Sphere8_E1_ptr, Sphere9_E1_ptr, Sphere10_E1_ptr, Plan11_E1_ptr };
	//std::vector<interaction_ptr> interactionsE1_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(), refrac.clone(), absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSystemElement(opticalSystemE1_ptr, interactionsE1_ptr);
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 369.911,372.768,381.338 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS(/*optSysEle*/ optSystemElement,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 25.969,30.947,50.276 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}


// checkSystem E2
bool DLSmulticheck::checkE2()
{
	////***
	//unsigned int systemNum = 2;
	//std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	////***
	//
	std::vector<bool> check_vec;
	//
	//// surfaces E2
	//ApertureStopElement AperStop0_E2(/* semi height*/1.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Sphere1_E2(/*radius*/ 100.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF3_S1(), /*refractive index B*/glasses.getAir());
	//SphericalElement Sphere2_E2(/*radius*/ 150.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF3_S1(), /*refractive index B*/glasses.getAir());
	//SphericalElement Sphere3_E2(/*radius*/ 50.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	//SphericalElement Sphere4_E2(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	//SphericalElement Sphere5_E2(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	//SphericalElement Sphere6_E2(/*radius*/ 50.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF4_S1());
	//SphericalElement Sphere7_E2(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF57_S1(), /*refractive index B*/glasses.getSF4_S1());
	//SphericalElement Sphere8_E2(/*radius*/ 35.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF57_S1());
	//PlanElement Plan9_E2(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,100.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//Sphere2_E2.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere5_E2.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere8_E2.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//
	//surfacePtr Aper0_E2_ptr = AperStop0_E2.clone();
	//surfacePtr Sphere1_E2_ptr = Sphere1_E2.clone();
	//surfacePtr Sphere2_E2_ptr = Sphere2_E2.clone();
	//surfacePtr Sphere3_E2_ptr = Sphere3_E2.clone();
	//surfacePtr Sphere4_E2_ptr = Sphere4_E2.clone();
	//surfacePtr Sphere5_E2_ptr = Sphere5_E2.clone();
	//surfacePtr Sphere6_E2_ptr = Sphere6_E2.clone();
	//surfacePtr Sphere7_E2_ptr = Sphere7_E2.clone();
	//surfacePtr Sphere8_E2_ptr = Sphere8_E2.clone();
	//surfacePtr Plan9_E2_ptr = Plan9_E2.clone();
	//
	//std::vector<surfacePtr> opticalSystemE2_ptr{ Aper0_E2_ptr, Sphere1_E2_ptr, Sphere2_E2_ptr , Sphere3_E2_ptr, Sphere4_E2_ptr, Sphere5_E2_ptr, Sphere6_E2_ptr, Sphere7_E2_ptr, Sphere8_E2_ptr, Plan9_E2_ptr };
	//std::vector<interaction_ptr> interactionsE2_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSystemElement_E2(opticalSystemE2_ptr, interactionsE2_ptr);
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 35.321,43.031,62.382 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E2, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS(/*optSysEle*/ optSystemElement_E2,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 17.614,20.015,27.205 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

// checkSystem E3
bool DLSmulticheck::checkE3()
{
	////***
	//unsigned int systemNum = 3;
	//std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	////***
	//
	std::vector<bool> check_vec;
	//
	//
	//// surfaces E3
	//ApertureStopElement AperStop0_E3(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Sphere1_E3(/*radius*/ 80.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF3_S1(), /*refractive index B*/glasses.getAir());
	//SphericalElement Sphere2_E3(/*radius*/ 110.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF3_S1(), /*refractive index B*/glasses.getBK7_S1());
	//SphericalElement Sphere3_E3(/*radius*/ 90.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getAir());
	//SphericalElement Sphere4_E3(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	//SphericalElement Sphere5_E3(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	//SphericalElement Sphere6_E3(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	//SphericalElement Sphere7_E3(/*radius*/ 100.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF5_S1(), /*refractive index B*/glasses.getAir());
	//SphericalElement Sphere8_E3(/*radius*/ 100.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF5_S1(), /*refractive index B*/glasses.getAir());
	//SphericalElement Sphere9_E3(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement Sphere10_E3(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF57_S1(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement Sphere11_E3(/*radius*/ 35.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF57_S1());
	//PlanElement Plan12_E3(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,115.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//Sphere2_E3.setParameterPointZ(0.0, 0.0, 0.0, typeModifierVariable);
	//Sphere5_E3.setParameterPointZ(0.0, 0.0, 0.0, typeModifierVariable);
	//Sphere9_E3.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//
	//
	//
	//surfacePtr Aper0_E3_ptr = AperStop0_E3.clone();
	//surfacePtr Sphere1_E3_ptr = Sphere1_E3.clone();
	//surfacePtr Sphere2_E3_ptr = Sphere2_E3.clone();
	//surfacePtr Sphere3_E3_ptr = Sphere3_E3.clone();
	//surfacePtr Sphere4_E3_ptr = Sphere4_E3.clone();
	//surfacePtr Sphere5_E3_ptr = Sphere5_E3.clone();
	//surfacePtr Sphere6_E3_ptr = Sphere6_E3.clone();
	//surfacePtr Sphere7_E3_ptr = Sphere7_E3.clone();
	//surfacePtr Sphere8_E3_ptr = Sphere8_E3.clone();
	//surfacePtr Sphere9_E3_ptr = Sphere9_E3.clone();
	//surfacePtr Sphere10_E3_ptr = Sphere10_E3.clone();
	//surfacePtr Sphere11_E3_ptr = Sphere11_E3.clone();
	//surfacePtr Plan12_E3_ptr = Plan12_E3.clone();
	//
	//std::vector<surfacePtr> opticalSystemE3_ptr{ Aper0_E3_ptr, Sphere1_E3_ptr, Sphere2_E3_ptr , Sphere3_E3_ptr, Sphere4_E3_ptr, Sphere5_E3_ptr, Sphere6_E3_ptr, Sphere7_E3_ptr, Sphere8_E3_ptr, Sphere9_E3_ptr, Sphere10_E3_ptr, Sphere11_E3_ptr, Plan12_E3_ptr };
	//std::vector<interaction_ptr> interactionsE3_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSystemElement_E3(opticalSystemE3_ptr, interactionsE3_ptr);
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 316.664,299.806,254.875 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E3, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS(/*optSysEle*/ optSystemElement_E3,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 48.482,60.820,128.369 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

// checkSystem E4
bool DLSmulticheck::checkE4()
{
	////***
	//unsigned int systemNum = 4;
	//std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	////***
	//
	std::vector<bool> check_vec;
	//
	//// surfaces E4
	//ApertureStopElement AperStop0_E4(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Sphere1_E4(/*radius*/ 60.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF3_S1());
	//SphericalElement Sphere2_E4(/*radius*/ 70.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getSF3_S1());
	//SphericalElement Sphere3_E4(/*radius*/ 50.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
	//SphericalElement Sphere4_E4(/*radius*/ 200.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBAFN10_S1(), /*refractive index B*/glasses.getAir());
	//SphericalElement Sphere5_E4(/*radius*/ 150.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getBAFN10_S1(), /*refractive index B*/glasses.getAir());
	//SphericalElement Sphere6_E4(/*radius*/ 50.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
	//SphericalElement Sphere7_E4(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getSF6_S1());
	//SphericalElement Sphere8_E4(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
	//PlanElement Plan9_E4(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,100.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//Sphere2_E4.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere4_E4.setParameterPointZ(0.0, 0.0, 0.0, typeModifierVariable);
	//Sphere6_E4.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//
	//surfacePtr Aper0_E4_ptr = AperStop0_E4.clone();
	//surfacePtr Sphere1_E4_ptr = Sphere1_E4.clone();
	//surfacePtr Sphere2_E4_ptr = Sphere2_E4.clone();
	//surfacePtr Sphere3_E4_ptr = Sphere3_E4.clone();
	//surfacePtr Sphere4_E4_ptr = Sphere4_E4.clone();
	//surfacePtr Sphere5_E4_ptr = Sphere5_E4.clone();
	//surfacePtr Sphere6_E4_ptr = Sphere6_E4.clone();
	//surfacePtr Sphere7_E4_ptr = Sphere7_E4.clone();
	//surfacePtr Sphere8_E4_ptr = Sphere8_E4.clone();
	//surfacePtr Plan9_E4_ptr = Plan9_E4.clone();
	//
	//std::vector<surfacePtr> opticalSystemE4_ptr{ Aper0_E4_ptr, Sphere1_E4_ptr, Sphere2_E4_ptr , Sphere3_E4_ptr, Sphere4_E4_ptr, Sphere5_E4_ptr, Sphere6_E4_ptr, Sphere7_E4_ptr, Sphere8_E4_ptr, Plan9_E4_ptr };
	//std::vector<interaction_ptr> interactionsE4_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSystemElement_E4(opticalSystemE4_ptr, interactionsE4_ptr);
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 281.402,272.763,249.064 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E4, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS(/*optSysEle*/ optSystemElement_E4,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 43.134,56.100,88.750 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

// checkSystem E5
bool DLSmulticheck::checkE5()
{
	////***
	//unsigned int systemNum = 5;
	//std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	////***
	//
	std::vector<bool> check_vec;
	//
	//// surfaces E5
	//ApertureStopElement AperStop0_E5(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Sphere1_E5(/*radius*/ 80.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	//SphericalElement Sphere2_E5(/*radius*/ 70.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	//SphericalElement Sphere3_E5(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
	//SphericalElement Sphere4_E5(/*radius*/ 35.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getSF6_S1());
	//SphericalElement Sphere5_E5(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
	//PlanElement Plan6_E5(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,90.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//Sphere1_E5.setParameterPointZ(0.0, 0.0, 0.0, typeModifierVariable);
	//Sphere2_E5.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere4_E5.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//
	//surfacePtr Aper0_E5_ptr = AperStop0_E5.clone();
	//surfacePtr Sphere1_E5_ptr = Sphere1_E5.clone();
	//surfacePtr Sphere2_E5_ptr = Sphere2_E5.clone();
	//surfacePtr Sphere3_E5_ptr = Sphere3_E5.clone();
	//surfacePtr Sphere4_E5_ptr = Sphere4_E5.clone();
	//surfacePtr Sphere5_E5_ptr = Sphere5_E5.clone();
	//surfacePtr Plan6_E5_ptr = Plan6_E5.clone();
	//
	//std::vector<surfacePtr> opticalSystemE5_ptr{ Aper0_E5_ptr, Sphere1_E5_ptr, Sphere2_E5_ptr , Sphere3_E5_ptr, Sphere4_E5_ptr, Sphere5_E5_ptr,  Plan6_E5_ptr };
	//std::vector<interaction_ptr> interactionsE5_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSystemElement_E5(opticalSystemE5_ptr, interactionsE5_ptr);
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 137.444,131.322,116.881 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E5, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS(/*optSysEle*/ optSystemElement_E5,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 8.718,9.141,11.141 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

// checkSystem E6
bool DLSmulticheck::checkE6()
{
	////***
	//unsigned int systemNum = 6;
	//std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	////***
	//
	std::vector<bool> check_vec;
	//
	//// surfaces E6
	//ApertureStopElement AperStop0_E6(/* semi height*/2.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Sphere1_E6(/*radius*/ 20.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
	//SphericalElement Sphere2_E6(/*radius*/ 20.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getSF6_S1());
	//SphericalElement Sphere3_E6(/*radius*/ 20.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
	//PlanElement Plan4_E6(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//Sphere1_E6.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere2_E6.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere3_E6.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//
	//surfacePtr Aper0_E6_ptr = AperStop0_E6.clone();
	//surfacePtr Sphere1_E6_ptr = Sphere1_E6.clone();
	//surfacePtr Sphere2_E6_ptr = Sphere2_E6.clone();
	//surfacePtr Sphere3_E6_ptr = Sphere3_E6.clone();
	//surfacePtr Plan4_E6_ptr = Plan4_E6.clone();
	//
	//std::vector<surfacePtr> opticalSystemE6_ptr{ Aper0_E6_ptr, Sphere1_E6_ptr, Sphere2_E6_ptr , Sphere3_E6_ptr, Plan4_E6_ptr };
	//std::vector<interaction_ptr> interactionsE6_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSystemElement_E6(opticalSystemE6_ptr, interactionsE6_ptr);
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 1032.04,981.987,859.466 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E6, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS(/*optSysEle*/ optSystemElement_E6,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 180.923,274.864,522.860 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

// checkSystem E7
bool DLSmulticheck::checkE7()
{
	////***
	//unsigned int systemNum = 7;
	//std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	////***
	//
	std::vector<bool> check_vec;
	//
	//// surfaces E7
	//ApertureStopElement AperStop0_E7(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Sphere1_E7(/*radius*/ 15.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement Sphere2_E7(/*radius*/ 30.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF6_S1(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement Sphere3_E7(/*radius*/ 25.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
	//PlanElement Plan4_E7(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,75.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//Sphere1_E7.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere1_E7.setParameterPointZ(0.0, 0.0, 0.0, typeModifierVariable);
	//Sphere3_E7.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//
	//surfacePtr Aper0_E7_ptr = AperStop0_E7.clone();
	//surfacePtr Sphere1_E7_ptr = Sphere1_E7.clone();
	//surfacePtr Sphere2_E7_ptr = Sphere2_E7.clone();
	//surfacePtr Sphere3_E7_ptr = Sphere3_E7.clone();
	//surfacePtr Plan4_E7_ptr = Plan4_E7.clone();
	//
	//std::vector<surfacePtr> opticalSystemE7_ptr{ Aper0_E7_ptr, Sphere1_E7_ptr, Sphere2_E7_ptr , Sphere3_E7_ptr, Plan4_E7_ptr };
	//std::vector<interaction_ptr> interactionsE7_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSystemElement_E7(opticalSystemE7_ptr, interactionsE7_ptr);
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 102.085,125.210,184.717 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E7, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS(/*optSysEle*/ optSystemElement_E7,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 64.942,77.548,114.383 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

// checkSystem E8
bool DLSmulticheck::checkE8()
{
	////***
	//unsigned int systemNum = 8;
	//std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	////***
	//
	std::vector<bool> check_vec;
	//
	//// surfaces E8
	//ApertureStopElement AperStop0_E8(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Sphere1_E8(/*radius*/ 60.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
	//SphericalElement Sphere2_E8(/*radius*/ 50.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSSKN8_S1(), /*refractive index B*/glasses.getBK7_S1());
	//SphericalElement Sphere3_E8(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSSKN8_S1());
	//SphericalElement Sphere4_E8(/*radius*/ 50.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement Sphere5_E8(/*radius*/ 50.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSSKN8_S1(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement Sphere6_E8(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSSKN8_S1());
	//PlanElement Plan7_E8(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,95.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//Sphere2_E8.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere4_E8.setParameterPointZ(0.0, 0.0, 0.0, typeModifierVariable);
	//Sphere6_E8.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//
	//surfacePtr Aper0_E8_ptr = AperStop0_E8.clone();
	//surfacePtr Sphere1_E8_ptr = Sphere1_E8.clone();
	//surfacePtr Sphere2_E8_ptr = Sphere2_E8.clone();
	//surfacePtr Sphere3_E8_ptr = Sphere3_E8.clone();
	//surfacePtr Sphere4_E8_ptr = Sphere4_E8.clone();
	//surfacePtr Sphere5_E8_ptr = Sphere5_E8.clone();
	//surfacePtr Sphere6_E8_ptr = Sphere6_E8.clone();
	//surfacePtr Plan7_E8_ptr = Plan7_E8.clone();
	//
	//std::vector<surfacePtr> opticalSystemE8_ptr{ Aper0_E8_ptr, Sphere1_E8_ptr, Sphere2_E8_ptr , Sphere3_E8_ptr, Sphere4_E8_ptr, Sphere5_E8_ptr, Sphere6_E8_ptr, Plan7_E8_ptr };
	//std::vector<interaction_ptr> interactionsE8_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSystemElement_E8(opticalSystemE8_ptr, interactionsE8_ptr);
	//
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 318.448,307.559,278.849 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E8, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS(/*optSysEle*/ optSystemElement_E8,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 58.639,73.607,118.683 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

// checkSystem E9
bool DLSmulticheck::checkE9()
{
	////***
	//unsigned int systemNum = 9;
	//std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	////***
	//
	std::vector<bool> check_vec;
	//
	//// surfaces E9
	//ApertureStopElement AperStop0_E9(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Sphere1_E9(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
	//SphericalElement Sphere2_E9(/*radius*/ 100.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getSSKN8_S1());
	//SphericalElement Sphere3_E9(/*radius*/ 90.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSSKN8_S1(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement Sphere4_E9(/*radius*/ 80.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF5_S1(), /*refractive index B*/glasses.getSSKN8_S1());
	//SphericalElement Sphere5_E9(/*radius*/ 70.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF10_S1(), /*refractive index B*/glasses.getSSKN8_S1());
	//SphericalElement Sphere6_E9(/*radius*/ 60.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBAK4_S1(), /*refractive index B*/glasses.getSF10_S1());
	//SphericalElement Sphere7_E9(/*radius*/ 20.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAK4_S1());
	//PlanElement Plan8_E9(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,110.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//Sphere1_E9.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere2_E9.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere6_E9.setParameterPointZ(0.0, 0.0, 0.0, typeModifierVariable);
	//
	//surfacePtr Aper0_E9_ptr = AperStop0_E9.clone();
	//surfacePtr Sphere1_E9_ptr = Sphere1_E9.clone();
	//surfacePtr Sphere2_E9_ptr = Sphere2_E9.clone();
	//surfacePtr Sphere3_E9_ptr = Sphere3_E9.clone();
	//surfacePtr Sphere4_E9_ptr = Sphere4_E9.clone();
	//surfacePtr Sphere5_E9_ptr = Sphere5_E9.clone();
	//surfacePtr Sphere6_E9_ptr = Sphere6_E9.clone();
	//surfacePtr Sphere7_E9_ptr = Sphere7_E9.clone();
	//surfacePtr Plan8_E9_ptr = Plan8_E9.clone();
	//
	//std::vector<surfacePtr> opticalSystemE9_ptr{ Aper0_E9_ptr, Sphere1_E9_ptr, Sphere2_E9_ptr , Sphere3_E9_ptr, Sphere4_E9_ptr, Sphere5_E9_ptr, Sphere6_E9_ptr, Sphere7_E9_ptr, Plan8_E9_ptr };
	//std::vector<interaction_ptr> interactionsE9_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSystemElement_E9(opticalSystemE9_ptr, interactionsE9_ptr);
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 1285.01,1251.19,1153.44 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E9, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS(/*optSysEle*/ optSystemElement_E9,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 67.644,115.118,235.557 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

// checkSystem E10
bool DLSmulticheck::checkE10()

{
	////***
	//unsigned int systemNum = 10;
	//std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	////***
	//
	std::vector<bool> check_vec;
	//
	//// surfaces E10
	//ApertureStopElement AperStop0_E10(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Sphere1_E10(/*radius*/ 25.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement Sphere2_E10(/*radius*/ 30.00, /*semi height*/7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF6_S1(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement Sphere3_E10(/*radius*/ 25.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
	//PlanElement Plan4_E10(/*semi height*/ 100.0, /*point*/{ 0.0,0.0,75.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//Sphere1_E10.setParameterRadius(10.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere2_E10.setParameterRadius(10.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere3_E10.setParameterRadius(10.0, 10000.0, 0.0, typeModifierVariable);
	//
	//surfacePtr Aper0_E10_ptr = AperStop0_E10.clone();
	//surfacePtr Sphere1_E10_ptr = Sphere1_E10.clone();
	//surfacePtr Sphere2_E10_ptr = Sphere2_E10.clone();
	//surfacePtr Sphere3_E10_ptr = Sphere3_E10.clone();
	//surfacePtr Plan4_E10_ptr = Plan4_E10.clone();
	//
	//std::vector<surfacePtr> opticalSystemE10_ptr{ Aper0_E10_ptr, Sphere1_E10_ptr, Sphere2_E10_ptr , Sphere3_E10_ptr, Plan4_E10_ptr };
	//std::vector<interaction_ptr> interactionsE10_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSystemElement_E10(opticalSystemE10_ptr, interactionsE10_ptr);
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 533.850,529.486,516.527 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E10, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS(/*optSysEle*/ optSystemElement_E10,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 25.969,30.947,50.276 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

// checkSystem E11
bool DLSmulticheck::checkE11()
{
	////***
	//unsigned int systemNum = 11;
	//std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	////***
	//
	std::vector<bool> check_vec;
	//
	//// surfaces E11
	//ApertureStopElement AperStop0_E11(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Sphere1_E11(/*radius*/ 25.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
	//SphericalElement Sphere2_E11(/*radius*/ 25.00, /*semi height*/7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF11_S1(), /*refractive index B*/glasses.getBK7_S1());
	//SphericalElement Sphere3_E11(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF11_S1());
	//SphericalElement Sphere4_E11(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF3_S1());
	//SphericalElement Sphere5_E11(/*radius*/ 581.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF3_S1(), /*refractive index B*/glasses.getAir());
	//SphericalElement Sphere6_E11(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	//SphericalElement Sphere7_E11(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getBAFN10_S1(), /*refractive index B*/glasses.getNSSK8_S1());
	//SphericalElement Sphere8_E11(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	//PlanElement Plan9_E11(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,80.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//
	//Sphere3_E11.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere5_E11.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere7_E11.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//
	//surfacePtr Aper0_E11_ptr = AperStop0_E11.clone();
	//surfacePtr Sphere1_E11_ptr = Sphere1_E11.clone();
	//surfacePtr Sphere2_E11_ptr = Sphere2_E11.clone();
	//surfacePtr Sphere3_E11_ptr = Sphere3_E11.clone();
	//surfacePtr Sphere4_E11_ptr = Sphere4_E11.clone();
	//surfacePtr Sphere5_E11_ptr = Sphere5_E11.clone();
	//surfacePtr Sphere6_E11_ptr = Sphere6_E11.clone();
	//surfacePtr Sphere7_E11_ptr = Sphere7_E11.clone();
	//surfacePtr Sphere8_E11_ptr = Sphere8_E11.clone();
	//surfacePtr Plan9_E11_ptr = Plan9_E11.clone();
	//
	//std::vector<surfacePtr> opticalSystemE11_ptr{ Aper0_E11_ptr, Sphere1_E11_ptr, Sphere2_E11_ptr , Sphere3_E11_ptr, Sphere4_E11_ptr, Sphere5_E11_ptr, Sphere6_E11_ptr, Sphere7_E11_ptr, Sphere8_E11_ptr, Plan9_E11_ptr };
	//std::vector<interaction_ptr> interactionsE11_ptr{ doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSysEle_E11(opticalSystemE11_ptr, interactionsE11_ptr);
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 20.352,27.105,43.332 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E11, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS_E11(/*optSysEle*/ optSysEle_E11,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 17.049,22.008,35.681 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS_E11, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

// checkSystem E12
bool DLSmulticheck::checkE12()
{
	////***
	//unsigned int systemNum = 12;
	//std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	////***
	//
	std::vector<bool> check_vec;
	//
	//// surfaces E12
	//ApertureStopElement AperStop0_E12(/* semi height*/1.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Spher1_E12(/*radius*/ 106.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
	//SphericalElement Sphere2_E12(/*radius*/ 35.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF11_S1(), /*refractive index B*/glasses.getBK7_S1());
	//SphericalElement Sphere3_E12(/*radius*/ 45.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF11_S1());
	//SphericalElement Sphere4_E12(/*radius*/ 100.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF3_S1());
	//SphericalElement Sphere5_E12(/*radius*/ 90.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF3_S1());
	//SphericalElement Sphere6_E12(/*radius*/ 60.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	//SphericalElement Sphere7_E12(/*radius*/ 45.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	//SphericalElement Sphere8_E12(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	//SphericalElement Sphere9_E12(/*radius*/ 80.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement SpherE120_E12(/*radius*/ 10.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF5_S1(), /*refractive index B*/glasses.getAir());
	//PlanElement Plan11_E12(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,115.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//Spher1_E12.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere2_E12.setParameterPointZ(0.0, 0.0, 0.0, typeModifierVariable);
	//SpherE120_E12.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//
	//surfacePtr Aper0_E12_ptr = AperStop0_E12.clone();
	//surfacePtr Sphere1_E12_ptr = Spher1_E12.clone();
	//surfacePtr Sphere2_E12_ptr = Sphere2_E12.clone();
	//surfacePtr Sphere3_E12_ptr = Sphere3_E12.clone();
	//surfacePtr Sphere4_E12_ptr = Sphere4_E12.clone();
	//surfacePtr Sphere5_E12_ptr = Sphere5_E12.clone();
	//surfacePtr Sphere6_E12_ptr = Sphere6_E12.clone();
	//surfacePtr Sphere7_E12_ptr = Sphere7_E12.clone();
	//surfacePtr Sphere8_E12_ptr = Sphere8_E12.clone();
	//surfacePtr Sphere9_E12_ptr = Sphere9_E12.clone();
	//surfacePtr SpherE120_E12_ptr = SpherE120_E12.clone();
	//surfacePtr Plan11_E12_ptr = Plan11_E12.clone();
	//
	//std::vector<surfacePtr> opticalSystemE12_ptr{ Aper0_E12_ptr, Sphere1_E12_ptr, Sphere2_E12_ptr , Sphere3_E12_ptr, Sphere4_E12_ptr, Sphere5_E12_ptr, Sphere6_E12_ptr, Sphere7_E12_ptr, Sphere8_E12_ptr, Sphere9_E12_ptr, SpherE120_E12_ptr, Plan11_E12_ptr };
	//std::vector<interaction_ptr> interactionsE12_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(), refrac.clone(), absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSystemElement(opticalSystemE12_ptr, interactionsE12_ptr);
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 52.762,59.946,80.124 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS(/*optSysEle*/ optSystemElement,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 19.963,25.911,41.716 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

// checkSystem E13
bool DLSmulticheck::checkE13()
{
	////***
	//unsigned int systemNum = 13;
	//std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	////***
	//
	std::vector<bool> check_vec;
	//
	//// surfaces E13
	//ApertureStopElement AperStop0_E13(/* semi height*/1.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Sphere1_E13(/*radius*/ 100.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF3_S1(), /*refractive index B*/glasses.getAir());
	//SphericalElement Sphere2_E13(/*radius*/ 20.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF3_S1());
	//SphericalElement Sphere3_E13(/*radius*/ 50.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	//SphericalElement Sphere4_E13(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	//SphericalElement Sphere5_E13(/*radius*/ 45.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	//SphericalElement Sphere6_E13(/*radius*/ 50.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF4_S1());
	//SphericalElement Sphere7_E13(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF57_S1(), /*refractive index B*/glasses.getSF4_S1());
	//SphericalElement Sphere8_E13(/*radius*/ 14.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF57_S1(), /*refractive index B*/glasses.getAir());
	//PlanElement Plan9_E13(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,100.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//Sphere2_E13.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere5_E13.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere8_E13.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//
	//surfacePtr Aper0_E13_ptr = AperStop0_E13.clone();
	//surfacePtr Sphere1_E13_ptr = Sphere1_E13.clone();
	//surfacePtr Sphere2_E13_ptr = Sphere2_E13.clone();
	//surfacePtr Sphere3_E13_ptr = Sphere3_E13.clone();
	//surfacePtr Sphere4_E13_ptr = Sphere4_E13.clone();
	//surfacePtr Sphere5_E13_ptr = Sphere5_E13.clone();
	//surfacePtr Sphere6_E13_ptr = Sphere6_E13.clone();
	//surfacePtr Sphere7_E13_ptr = Sphere7_E13.clone();
	//surfacePtr Sphere8_E13_ptr = Sphere8_E13.clone();
	//surfacePtr Plan9_E13_ptr = Plan9_E13.clone();
	//
	//std::vector<surfacePtr> opticalSystemE13_ptr{ Aper0_E13_ptr, Sphere1_E13_ptr, Sphere2_E13_ptr , Sphere3_E13_ptr, Sphere4_E13_ptr, Sphere5_E13_ptr, Sphere6_E13_ptr, Sphere7_E13_ptr, Sphere8_E13_ptr, Plan9_E13_ptr };
	//std::vector<interaction_ptr> interactionsE13_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSystemElement_E13(opticalSystemE13_ptr, interactionsE13_ptr);
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 33.233,34.351,38.245 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E13, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS(/*optSysEle*/ optSystemElement_E13,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 17.614,20.015,27.205 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

// checkSystem E14
bool DLSmulticheck::checkE14()
{
	////***
	//unsigned int systemNum = 14;
	//std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	////***
	//
	std::vector<bool> check_vec;
	//
	//
	//// surfaces E14
	//ApertureStopElement AperStop0_E14(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Sphere1_E14(/*radius*/ 80.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF3_S1(), /*refractive index B*/glasses.getAir());
	//SphericalElement Sphere2_E14(/*radius*/ 110.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF3_S1(), /*refractive index B*/glasses.getBK7_S1());
	//SphericalElement Sphere3_E14(/*radius*/ 90.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getAir());
	//SphericalElement Sphere4_E14(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	//SphericalElement Sphere5_E14(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	//SphericalElement Sphere6_E14(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	//SphericalElement Sphere7_E14(/*radius*/ 100.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF5_S1(), /*refractive index B*/glasses.getAir());
	//SphericalElement Sphere8_E14(/*radius*/ 100.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF5_S1(), /*refractive index B*/glasses.getAir());
	//SphericalElement Sphere9_E14(/*radius*/ 46.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement Sphere10_E14(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF57_S1(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement Sphere11_E14(/*radius*/ 35.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF57_S1());
	//PlanElement Plan12_E14(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,115.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//Sphere2_E14.setParameterPointZ(0.0, 0.0, 0.0, typeModifierVariable);
	//Sphere5_E14.setParameterPointZ(0.0, 0.0, 0.0, typeModifierVariable);
	//Sphere9_E14.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//
	//
	//
	//surfacePtr Aper0_E14_ptr = AperStop0_E14.clone();
	//surfacePtr Sphere1_E14_ptr = Sphere1_E14.clone();
	//surfacePtr Sphere2_E14_ptr = Sphere2_E14.clone();
	//surfacePtr Sphere3_E14_ptr = Sphere3_E14.clone();
	//surfacePtr Sphere4_E14_ptr = Sphere4_E14.clone();
	//surfacePtr Sphere5_E14_ptr = Sphere5_E14.clone();
	//surfacePtr Sphere6_E14_ptr = Sphere6_E14.clone();
	//surfacePtr Sphere7_E14_ptr = Sphere7_E14.clone();
	//surfacePtr Sphere8_E14_ptr = Sphere8_E14.clone();
	//surfacePtr Sphere9_E14_ptr = Sphere9_E14.clone();
	//surfacePtr Sphere10_E14_ptr = Sphere10_E14.clone();
	//surfacePtr Sphere11_E14_ptr = Sphere11_E14.clone();
	//surfacePtr Plan12_E14_ptr = Plan12_E14.clone();
	//
	//std::vector<surfacePtr> opticalSystemE14_ptr{ Aper0_E14_ptr, Sphere1_E14_ptr, Sphere2_E14_ptr , Sphere3_E14_ptr, Sphere4_E14_ptr, Sphere5_E14_ptr, Sphere6_E14_ptr, Sphere7_E14_ptr, Sphere8_E14_ptr, Sphere9_E14_ptr, Sphere10_E14_ptr, Sphere11_E14_ptr, Plan12_E14_ptr };
	//std::vector<interaction_ptr> interactionsE14_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSystemElement_E14(opticalSystemE14_ptr, interactionsE14_ptr);
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 429.118,411.849,362.923 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E14, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS(/*optSysEle*/ optSystemElement_E14,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 48.482,60.820,128.369 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

// checkSystem E15
bool DLSmulticheck::checkE15()
{
	////***
	//unsigned int systemNum = 15;
	//std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	////***
	//
	std::vector<bool> check_vec;
	//
	//// surfaces E15
	//ApertureStopElement AperStop0_E15(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Sphere1_E15(/*radius*/ 60.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF3_S1());
	//SphericalElement Sphere2_E15(/*radius*/ 14.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getSF3_S1());
	//SphericalElement Sphere3_E15(/*radius*/ 50.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
	//SphericalElement Sphere4_E15(/*radius*/ 200.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBAFN10_S1(), /*refractive index B*/glasses.getAir());
	//SphericalElement Sphere5_E15(/*radius*/ 150.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getBAFN10_S1(), /*refractive index B*/glasses.getAir());
	//SphericalElement Sphere6_E15(/*radius*/ 56.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
	//SphericalElement Sphere7_E15(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getSF6_S1());
	//SphericalElement Sphere8_E15(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
	//PlanElement Plan9_E15(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,110.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//Sphere2_E15.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere4_E15.setParameterPointZ(0.0, 0.0, 0.0, typeModifierVariable);
	//Sphere6_E15.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//
	//surfacePtr Aper0_E15_ptr = AperStop0_E15.clone();
	//surfacePtr Sphere1_E15_ptr = Sphere1_E15.clone();
	//surfacePtr Sphere2_E15_ptr = Sphere2_E15.clone();
	//surfacePtr Sphere3_E15_ptr = Sphere3_E15.clone();
	//surfacePtr Sphere4_E15_ptr = Sphere4_E15.clone();
	//surfacePtr Sphere5_E15_ptr = Sphere5_E15.clone();
	//surfacePtr Sphere6_E15_ptr = Sphere6_E15.clone();
	//surfacePtr Sphere7_E15_ptr = Sphere7_E15.clone();
	//surfacePtr Sphere8_E15_ptr = Sphere8_E15.clone();
	//surfacePtr Plan9_E15_ptr = Plan9_E15.clone();
	//
	//std::vector<surfacePtr> opticalSystemE15_ptr{ Aper0_E15_ptr, Sphere1_E15_ptr, Sphere2_E15_ptr , Sphere3_E15_ptr, Sphere4_E15_ptr, Sphere5_E15_ptr, Sphere6_E15_ptr, Sphere7_E15_ptr, Sphere8_E15_ptr, Plan9_E15_ptr };
	//std::vector<interaction_ptr> interactionsE15_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSystemElement_E15(opticalSystemE15_ptr, interactionsE15_ptr);
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 46.765,67.803,115.658 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E15, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS(/*optSysEle*/ optSystemElement_E15,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 43.134,56.100,88.750 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

// checkSystem E16
bool DLSmulticheck::checkE16()
{
	////***
	//unsigned int systemNum = 16;
	//std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	////***
	//
	std::vector<bool> check_vec;
	//
	//// surfaces E16
	//ApertureStopElement AperStop0_E16(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Sphere1_E16(/*radius*/ 80.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	//SphericalElement Sphere2_E16(/*radius*/ 15.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	//SphericalElement Sphere3_E16(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
	//SphericalElement Sphere4_E16(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF6_S1(), /*refractive index B*/glasses.getBK7_S1());
	//SphericalElement Sphere5_E16(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
	//PlanElement Plan6_E16(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,90.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//Sphere1_E16.setParameterPointZ(0.0, 0.0, 0.0, typeModifierVariable);
	//Sphere2_E16.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere4_E16.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//
	//surfacePtr Aper0_E16_ptr = AperStop0_E16.clone();
	//surfacePtr Sphere1_E16_ptr = Sphere1_E16.clone();
	//surfacePtr Sphere2_E16_ptr = Sphere2_E16.clone();
	//surfacePtr Sphere3_E16_ptr = Sphere3_E16.clone();
	//surfacePtr Sphere4_E16_ptr = Sphere4_E16.clone();
	//surfacePtr Sphere5_E16_ptr = Sphere5_E16.clone();
	//surfacePtr Plan6_E16_ptr = Plan6_E16.clone();
	//
	//std::vector<surfacePtr> opticalSystemE16_ptr{ Aper0_E16_ptr, Sphere1_E16_ptr, Sphere2_E16_ptr , Sphere3_E16_ptr, Sphere4_E16_ptr, Sphere5_E16_ptr,  Plan6_E16_ptr };
	//std::vector<interaction_ptr> interactionsE16_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSystemElement_E16(opticalSystemE16_ptr, interactionsE16_ptr);
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 24.724,26.539,31.512 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E16, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS(/*optSysEle*/ optSystemElement_E16,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 8.718,9.141,11.141 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

// checkSystem E17
bool DLSmulticheck::checkE17()
{
	////***
	//unsigned int systemNum = 17;
	//std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	////***
	//
	std::vector<bool> check_vec;
	//
	//// surfaces E17
	//ApertureStopElement AperStop0_E17(/* semi height*/2.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Sphere1_E17(/*radius*/ 16.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
	//SphericalElement Sphere2_E17(/*radius*/ 13.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getSF6_S1());
	//SphericalElement Sphere3_E17(/*radius*/ 20.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
	//PlanElement Plan4_E17(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//Sphere1_E17.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere2_E17.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere3_E17.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//
	//surfacePtr Aper0_E17_ptr = AperStop0_E17.clone();
	//surfacePtr Sphere1_E17_ptr = Sphere1_E17.clone();
	//surfacePtr Sphere2_E17_ptr = Sphere2_E17.clone();
	//surfacePtr Sphere3_E17_ptr = Sphere3_E17.clone();
	//surfacePtr Plan4_E17_ptr = Plan4_E17.clone();
	//
	//std::vector<surfacePtr> opticalSystemE17_ptr{ Aper0_E17_ptr, Sphere1_E17_ptr, Sphere2_E17_ptr , Sphere3_E17_ptr, Plan4_E17_ptr };
	//std::vector<interaction_ptr> interactionsE17_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSystemElement_E17(opticalSystemE17_ptr, interactionsE17_ptr);
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 430.446,576.343,939.022 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E17, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS(/*optSysEle*/ optSystemElement_E17,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 180.923,274.864,522.860 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;

}

// checkSystem E18
bool DLSmulticheck::checkE18()
{
	////***
	//unsigned int systemNum = 18;
	//std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	////***
	//
	std::vector<bool> check_vec;
	//
	//// surfaces E18
	//ApertureStopElement AperStop0_E18(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Sphere1_E18(/*radius*/ 21.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement Sphere2_E18(/*radius*/ 30.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF6_S1(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement Sphere3_E18(/*radius*/ 25.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
	//PlanElement Plan4_E18(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,75.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//Sphere1_E18.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere1_E18.setParameterPointZ(0.0, 0.0, 0.0, typeModifierVariable);
	//Sphere3_E18.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//
	//surfacePtr Aper0_E18_ptr = AperStop0_E18.clone();
	//surfacePtr Sphere1_E18_ptr = Sphere1_E18.clone();
	//surfacePtr Sphere2_E18_ptr = Sphere2_E18.clone();
	//surfacePtr Sphere3_E18_ptr = Sphere3_E18.clone();
	//surfacePtr Plan4_E18_ptr = Plan4_E18.clone();
	//
	//std::vector<surfacePtr> opticalSystemE18_ptr{ Aper0_E18_ptr, Sphere1_E18_ptr, Sphere2_E18_ptr , Sphere3_E18_ptr, Plan4_E18_ptr };
	//std::vector<interaction_ptr> interactionsE18_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSystemElement_E18(opticalSystemE18_ptr, interactionsE18_ptr);
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 717.927,708.642,681.245 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E18, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS(/*optSysEle*/ optSystemElement_E18,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 64.942,77.548,114.383 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

// checkSystem E19
bool DLSmulticheck::checkE19()
{
	////***
	//unsigned int systemNum = 19;
	//std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	////***
	//
	std::vector<bool> check_vec;
	//
	//// surfaces E19
	//ApertureStopElement AperStop0_E19(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Sphere1_E19(/*radius*/ 60.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
	//SphericalElement Sphere2_E19(/*radius*/ 21.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getSSKN8_S1());
	//SphericalElement Sphere3_E19(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSSKN8_S1());
	//SphericalElement Sphere4_E19(/*radius*/ 50.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement Sphere5_E19(/*radius*/ 50.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSSKN8_S1(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement Sphere6_E19(/*radius*/ 65.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSSKN8_S1());
	//PlanElement Plan7_E19(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,145.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//Sphere2_E19.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere4_E19.setParameterPointZ(0.0, 0.0, 0.0, typeModifierVariable);
	//Sphere6_E19.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//
	//surfacePtr Aper0_E19_ptr = AperStop0_E19.clone();
	//surfacePtr Sphere1_E19_ptr = Sphere1_E19.clone();
	//surfacePtr Sphere2_E19_ptr = Sphere2_E19.clone();
	//surfacePtr Sphere3_E19_ptr = Sphere3_E19.clone();
	//surfacePtr Sphere4_E19_ptr = Sphere4_E19.clone();
	//surfacePtr Sphere5_E19_ptr = Sphere5_E19.clone();
	//surfacePtr Sphere6_E19_ptr = Sphere6_E19.clone();
	//surfacePtr Plan7_E19_ptr = Plan7_E19.clone();
	//
	//std::vector<surfacePtr> opticalSystemE19_ptr{ Aper0_E19_ptr, Sphere1_E19_ptr, Sphere2_E19_ptr , Sphere3_E19_ptr, Sphere4_E19_ptr, Sphere5_E19_ptr, Sphere6_E19_ptr, Plan7_E19_ptr };
	//std::vector<interaction_ptr> interactionsE19_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSystemElement_E19(opticalSystemE19_ptr, interactionsE19_ptr);
	//
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 81.289,107.507,174.142 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E19, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS(/*optSysEle*/ optSystemElement_E19,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 58.639,73.607,118.683 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

// checkSystem E20
bool DLSmulticheck::checkE20()
{
	////***
	//unsigned int systemNum = 20;
	//std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	////***
	//
	std::vector<bool> check_vec;
	//
	//// surfaces E20
	//ApertureStopElement AperStop0_E20(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Sphere1_E20(/*radius*/ 16.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
	//SphericalElement Sphere2_E20(/*radius*/ 26.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getSSKN8_S1());
	//SphericalElement Sphere3_E20(/*radius*/ 90.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSSKN8_S1(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement Sphere4_E20(/*radius*/ 80.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF5_S1(), /*refractive index B*/glasses.getSSKN8_S1());
	//SphericalElement Sphere5_E20(/*radius*/ 70.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF10_S1(), /*refractive index B*/glasses.getSSKN8_S1());
	//SphericalElement Sphere6_E20(/*radius*/ 60.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBAK4_S1(), /*refractive index B*/glasses.getSF10_S1());
	//SphericalElement Sphere7_E20(/*radius*/ 20.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAK4_S1());
	//PlanElement Plan8_E20(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,110.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//Sphere1_E20.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere2_E20.setParameterRadius(7.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere6_E20.setParameterPointZ(0.0, 0.0, 0.0, typeModifierVariable);
	//
	//surfacePtr Aper0_E20_ptr = AperStop0_E20.clone();
	//surfacePtr Sphere1_E20_ptr = Sphere1_E20.clone();
	//surfacePtr Sphere2_E20_ptr = Sphere2_E20.clone();
	//surfacePtr Sphere3_E20_ptr = Sphere3_E20.clone();
	//surfacePtr Sphere4_E20_ptr = Sphere4_E20.clone();
	//surfacePtr Sphere5_E20_ptr = Sphere5_E20.clone();
	//surfacePtr Sphere6_E20_ptr = Sphere6_E20.clone();
	//surfacePtr Sphere7_E20_ptr = Sphere7_E20.clone();
	//surfacePtr Plan8_E20_ptr = Plan8_E20.clone();
	//
	//std::vector<surfacePtr> opticalSystemE20_ptr{ Aper0_E20_ptr, Sphere1_E20_ptr, Sphere2_E20_ptr , Sphere3_E20_ptr, Sphere4_E20_ptr, Sphere5_E20_ptr, Sphere6_E20_ptr, Sphere7_E20_ptr, Plan8_E20_ptr };
	//std::vector<interaction_ptr> interactionsE20_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSystemElement_E20(opticalSystemE20_ptr, interactionsE20_ptr);
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 100.259,165.954,310.301 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E20, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS(/*optSysEle*/ optSystemElement_E20,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 67.644,115.118,235.557 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}

bool DLSmulticheck::checkE21()
{
	////***
	//unsigned int systemNum = 21;
	//std::cout << "DLSmulticheck of system: " << systemNum << std::endl;
	////***
	//
	std::vector<bool> check_vec;
	//// surfaces E21
	//ApertureStopElement AperStop0_E21(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//SphericalElement Sphere1_E21(/*radius*/ 15.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement Sphere2_E21(/*radius*/ 11.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF6_S1(), /*refractive index B*/glasses.getSF5_S1());
	//SphericalElement Sphere3_E21(/*radius*/ 20.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
	//PlanElement Plan4_E21(/*semi height*/ 100.0, /*point*/{ 0.0,0.0,75.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//Sphere1_E21.setParameterRadius(10.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere2_E21.setParameterRadius(10.0, 10000.0, 0.0, typeModifierVariable);
	//Sphere3_E21.setParameterRadius(10.0, 10000.0, 0.0, typeModifierVariable);
	//
	//surfacePtr Aper0_E21_ptr = AperStop0_E21.clone();
	//surfacePtr Sphere1_E21_ptr = Sphere1_E21.clone();
	//surfacePtr Sphere2_E21_ptr = Sphere2_E21.clone();
	//surfacePtr Sphere3_E21_ptr = Sphere3_E21.clone();
	//surfacePtr Plan4_E21_ptr = Plan4_E21.clone();
	//
	//std::vector<surfacePtr> opticalSystemE21_ptr{ Aper0_E21_ptr, Sphere1_E21_ptr, Sphere2_E21_ptr , Sphere3_E21_ptr, Plan4_E21_ptr };
	//std::vector<interaction_ptr> interactionsE21_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), absorb.clone() };
	//
	////	build optical system
	//OpticalSystemElement optSystemElement_E21(opticalSystemE21_ptr, interactionsE21_ptr);
	//
	//// check the start system
	//std::vector<real> rmsStartSystem_Z{ 33.912,43.733,69.423 };
	//bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E21, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	//check_vec.push_back(checkStartSys);
	//
	//// optimization
	//DLS DLS(/*optSysEle*/ optSystemElement_E21,/*fields*/ mFields_vec012, /*wavelength*/ mWavelength_vec, /*rings*/ 6, /*arms*/ 8);
	//
	//std::vector<real> rmsOpti_Z{ 25.969,30.947,50.276 };
	//bool checkOptSys = oftenUse::DLSmulticheck(DLS, mFactorBetter_vec, mFactorWorst_vec, rmsOpti_Z, systemNum);
	//check_vec.push_back(checkOptSys);
	//
	bool checker = Math::checkTrueOfVectorElements(check_vec);
	return checker;
}