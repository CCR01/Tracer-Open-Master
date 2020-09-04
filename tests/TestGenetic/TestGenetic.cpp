#include "TestGenetic.h"

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

// genetic
#include "..\..\OptimizeSystem\Genetic.h"

// import export data
#include "..\..\Inport_Export_Data\Inport_Export_Data.h"

// cardinal points
#include "..\..\Analyse\CardinalPoints.h"

#include <iomanip>
#include <iostream>
#include <fstream>

// typedef
typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;
// ***

TestGenetic::TestGenetic() 
{
	glasses.loadGlassCatalog_Schott(); 

	glass1.setRealGlass(false);
	glass1.setRefractiveIndex(1.0);

	glass15.setRealGlass(false);
	glass15.setRefractiveIndex(1.5);

	glass16.setRealGlass(false);
	glass16.setRefractiveIndex(1.6);

	Light_550.setWavelength(550.0);
	Light_550.setIntensity(1.0);
	lichtVec550.push_back(Light_550);

	fields_vec_optA.push_back({ 0.0,0.0,0.0 });

	wavelenth_vec_550.push_back(550.0);

	defaultRings_6 = 6;
	defaultArms_8 = 8;

	//  wave
	mWave587 = 587.5618;
	mWave486 = 486.1327;
	mWave656 = 656.2725;
	mWavelength_FdC_vec = { mWave587 , mWave486, mWave656 };

	// field
	mField0 = { 0.0,0.0,0.0 };
	mField1 = { 0.0,1.0,0.0 };
	mField2 = { 0.0,2.0,0.0 };
	mField3 = { 0.0,3.0,0.0 };
	mField4 = { 0.0,4.0,0.0 };
	mFields_vec012 = { mField0, mField1, mField2 };
	mFields_vec024 = { mField0, mField2, mField4 };

	// angles
	mAngle_X0 = 0.0;
	mAngle000_X_vec = { mAngle_X0, mAngle_X0, mAngle_X0 };

	mAngle_Y0 = 0.0;
	mAngle_Y1 = 1.0;
	mAngle_Y2 = 2.0;
	mAngle012_Y_vec = { mAngle_Y0,mAngle_Y1,mAngle_Y2 };

	mTolerance_RMS = 0.1;
	mTolerance_target = 10.0;

	// wave 550 vec
	mWave550_vec.push_back(550.0);
	// start point optical axis
	startOptA_vec.push_back( {0.0,0.0,0.0} );

};
TestGenetic::~TestGenetic() {};

// super function
bool TestGenetic::testGeneticSuperFunc()
{
	std::vector<bool> testSuperFct_vec;

	// E0
	bool checkE0 = testE0();
	testSuperFct_vec.push_back(checkE0);
	
	// E1
	bool checkE1 = testE1();
	testSuperFct_vec.push_back(checkE1);
	
	// E2
	bool chekeE2 = testE2();
	testSuperFct_vec.push_back(chekeE2);
	
	// E3
	bool checkE3 = testE3();
	testSuperFct_vec.push_back(checkE3);
	
	// E4
	bool checkE4 = testE4();
	testSuperFct_vec.push_back(checkE4);
	
	// E5
	bool checkE5 = testE5();
	testSuperFct_vec.push_back(checkE5);
	
	// E6
	bool checkE6 = testE6();
	testSuperFct_vec.push_back(checkE6);
	
	//E7
	bool checkE7 = testE7();
	testSuperFct_vec.push_back(checkE7);
	
	// E8
	bool checkE8 = testE8();
	testSuperFct_vec.push_back(checkE8);

	bool checker = Math::checkTrueOfVectorElements(testSuperFct_vec);
	return checker;
}

// E0
bool TestGenetic::testE0()
{
	std::vector<bool> test_vec;

	// surfaces E0
	ApertureStopElement AperStop0_E0(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glass1);
	SphericalElement Sphere1_E0(/*radius*/ 5.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere2_E0(/*radius*/ 5.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	PlanElement Plan3_E0(/*semi height*/ 200.0, /*point*/{ 0.0,0.0,30.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glass1, /*refractive index B*/ glass1);

	// set the radius variable
	Sphere1_E0.setParameterRadius(-500.0, 500.0, 0.0, typeModifierVariable);
	Sphere2_E0.setParameterRadius(-500.0, 500.0, 0.0, typeModifierVariable);

	surfacePtr AperStop0_E0_ptr = AperStop0_E0.clone();
	surfacePtr Sphere1_E0_ptr = Sphere1_E0.clone();
	surfacePtr Sphere2_E0_ptr = Sphere2_E0.clone();
	surfacePtr Plan3_E0_ptr = Plan3_E0.clone();

	std::vector<surfacePtr> opticalSystemE0_ptr{ AperStop0_E0_ptr, Sphere1_E0_ptr, Sphere2_E0_ptr, Plan3_E0_ptr };
	std::vector<interaction_ptr> interactionsE0_ptr{ refrac.clone(),refrac.clone(), refrac.clone(), absorb.clone() };

	// build optical system
	OpticalSystemElement optSystemElement_E0(opticalSystemE0_ptr, interactionsE0_ptr);

	// test the system
	std::vector<real> rms_Zemax{ 558.824 };
	bool test_E0 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E0, fields_vec_optA, wavelenth_vec_550, rms_Zemax, 1.0, compareTOM_Zemax::comEqual);
	test_vec.push_back(test_E0);

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement_E0, /*fields*/ fields_vec_optA,/*wavelengths*/ wavelenth_vec_550, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/5000);
	genetic.setChooseValueMode(cleverSamplingMode);
	genetic.doTheGeneticProcess();

	OpticalSystemElement optimizedOpticalSystem = genetic.getOptimizedOpticalSystemElement();
	oftenUse::print(optimizedOpticalSystem, wavelenth_vec_550[0]);

	std::vector<real> bestValues{ 5.57118,-7.40529 };
	test_vec.push_back(oftenUse::checkDeltaVariables(optimizedOpticalSystem, bestValues, 50.0));

	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;

}

// E1
bool TestGenetic::testE1()
{
	std::vector<bool> test_vec;

	// surfaces E1
	ApertureStopElement AperStop0_E1(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glass1);
	SphericalElement Sphere1_E1(/*radius*/ 15.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere2_E1(/*radius*/ 7.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere3_E1(/*radius*/ 100.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass15, /*refractive index B*/glass1);
	SphericalElement Sphere4_E1(/*radius*/ 100.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass15, /*refractive index B*/glass1);
	PlanElement Plan5_E1(/*semi height*/ 3.0, /*point*/{ 0.0,0.0,40.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glass1, /*refractive index B*/ glass1);

	// set the radius variable
	Sphere1_E1.setParameterRadius(-500.0, 500.0, 0.0, typeModifierVariable);
	Sphere2_E1.setParameterRadius(-500.0, 500.0, 0, typeModifierVariable);

	surfacePtr AperStop0_E1_ptr = AperStop0_E1.clone();
	surfacePtr Sphere1_E1_ptr = Sphere1_E1.clone();
	surfacePtr Sphere2_E1_ptr = Sphere2_E1.clone();
	surfacePtr Sphere3_E1_ptr = Sphere3_E1.clone();
	surfacePtr Sphere4_E1_ptr = Sphere4_E1.clone();
	surfacePtr Plan5_E1_ptr = Plan5_E1.clone();

	std::vector<surfacePtr> opticalSystemE1_ptr{ AperStop0_E1_ptr, Sphere1_E1_ptr, Sphere2_E1_ptr, Sphere3_E1_ptr, Sphere4_E1_ptr, Plan5_E1_ptr };
	std::vector<interaction_ptr> interactionsE1_ptr{ doNothing.clone() ,refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(), absorb.clone() };

	// build optical system
	OpticalSystemElement optSystemElement_E1(opticalSystemE1_ptr, interactionsE1_ptr);

	// test the system
	std::vector<real> rms_Zemax{ 345.544 };
	bool test_E1 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E1, fields_vec_optA, wavelenth_vec_550, rms_Zemax, 1.0, compareTOM_Zemax::comEqual);
	test_vec.push_back(test_E1);

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement_E1, /*fields*/ fields_vec_optA,/*wavelengths*/ wavelenth_vec_550, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 5000);
	genetic.doTheGeneticProcess();

	OpticalSystemElement optimizedOpticalSystem = genetic.getOptimizedOpticalSystemElement();
	oftenUse::print(optimizedOpticalSystem, wavelenth_vec_550[0]);

	std::vector<real> bestValues{ 7.9865,-8.4249 };
	test_vec.push_back(oftenUse::checkDeltaVariables(optimizedOpticalSystem, bestValues, 50.0));

	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;


}


// E2
bool TestGenetic::testE2()
{
	std::vector<bool> test_vec;


	// surfaces E2
	ApertureStopElement AperStop0_E2(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glass1);
	SphericalElement Sphere1_E2(/*radius*/ 15.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere2_E2(/*radius*/ 7.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass1, /*refractive index B*/glass15);
	SphericalElement Sphere3_E2(/*radius*/ 100.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glass15, /*refractive index B*/glass1);
	SphericalElement Sphere4_E2(/*radius*/ 100.0, /*semi height*/ 3.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glass15, /*refractive index B*/glass1);
	PlanElement Plan5_E2(/*semi height*/ 3.0, /*point*/{ 0.0,0.0,40.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glass1, /*refractive index B*/ glass1);

	// set the radius variable
	Sphere1_E2.setParameterRadius(-500.0, 500.0, 0.0, typeModifierVariable);
	Sphere2_E2.setParameterRadius(-500.0, 500.0, 0.0, typeModifierVariable);
	Sphere3_E2.setParameterPointZ(2.0, 100.0, 0.0, typeModifierVariable);

	surfacePtr AperStop0_E2_ptr = AperStop0_E2.clone();
	surfacePtr Sphere1_E2_ptr = Sphere1_E2.clone();
	surfacePtr Sphere2_E2_ptr = Sphere2_E2.clone();
	surfacePtr Sphere3_E2_ptr = Sphere3_E2.clone();
	surfacePtr Sphere4_E2_ptr = Sphere4_E2.clone();
	surfacePtr Plan5_E2_ptr = Plan5_E2.clone();

	std::vector<surfacePtr> opticalSystemE2_ptr{ AperStop0_E2_ptr, Sphere1_E2_ptr, Sphere2_E2_ptr, Sphere3_E2_ptr, Sphere4_E2_ptr, Plan5_E2_ptr };
	std::vector<interaction_ptr> interactionsE2_ptr{ doNothing.clone() ,refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(), absorb.clone() };

	// build optical system
	OpticalSystemElement optSystemElement_E2(opticalSystemE2_ptr, interactionsE2_ptr);

	// test the system
	std::vector<real> rms_Zemax{ 345.544 };
	bool test_E2 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E2, fields_vec_optA, wavelenth_vec_550, rms_Zemax, 1.0, compareTOM_Zemax::comEqual);
	test_vec.push_back(test_E2);

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement_E2, /*fields*/ fields_vec_optA,/*wavelengths*/ wavelenth_vec_550, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 5000);
	genetic.doTheGeneticProcess();

	OpticalSystemElement optimizedOpticalSystem = genetic.getOptimizedOpticalSystemElement();
	oftenUse::print(optimizedOpticalSystem, wavelenth_vec_550[0]);

	std::vector<real> bestValues{ 8.82760,-8.64891,12.2568 };
	test_vec.push_back(oftenUse::checkDeltaVariables(optimizedOpticalSystem, bestValues, 200.0));

	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

// E3
bool TestGenetic::testE3()
{
	std::vector<bool> test_vec;

	// surfaces E3
	ApertureStopElement AperStop0_E3(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E3(/*radius*/ 25.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2_E3(/*radius*/ 25.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF11_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3_E3(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF11_S1());
	SphericalElement Sphere4_E3(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF4_S1());
	SphericalElement Sphere5_E3(/*radius*/ 70.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF4_S1());
	SphericalElement Sphere6_E3(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF10_S1());
	SphericalElement Sphere7_E3(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getNBAF10_S1());
	SphericalElement Sphere8_E3(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	PlanElement Plan9_E3(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,80.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere3_E3.setParameterRadius(-500.0, 500.0, 0.0, typeModifierVariable);
	Sphere5_E3.setParameterRadius(-500.0, 500.0, 0.0, typeModifierVariable);
	Sphere7_E3.setParameterRadius(-500.0, 500.0, 0.0, typeModifierVariable);

	surfacePtr Aper0_E3_ptr = AperStop0_E3.clone();
	surfacePtr Sphere1_E3_ptr = Sphere1_E3.clone();
	surfacePtr Sphere2_E3_ptr = Sphere2_E3.clone();
	surfacePtr Sphere3_E3_ptr = Sphere3_E3.clone();
	surfacePtr Sphere4_E3_ptr = Sphere4_E3.clone();
	surfacePtr Sphere5_E3_ptr = Sphere5_E3.clone();
	surfacePtr Sphere6_E3_ptr = Sphere6_E3.clone();
	surfacePtr Sphere7_E3_ptr = Sphere7_E3.clone();
	surfacePtr Sphere8_E3_ptr = Sphere8_E3.clone();
	surfacePtr Plan9_E3_ptr = Plan9_E3.clone();

	std::vector<surfacePtr> opticalSystemE3_ptr{ Aper0_E3_ptr, Sphere1_E3_ptr, Sphere2_E3_ptr , Sphere3_E3_ptr, Sphere4_E3_ptr, Sphere5_E3_ptr, Sphere6_E3_ptr, Sphere7_E3_ptr, Sphere8_E3_ptr, Plan9_E3_ptr };
	std::vector<interaction_ptr> interactionsE3_ptr{ doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSysEle_E3(opticalSystemE3_ptr, interactionsE3_ptr);

	// check the start system
	std::vector<real> rmsStartSystem_Z{ 196.505,192.103,179.353 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E3, mFields_vec012, mWavelength_FdC_vec, rmsStartSystem_Z, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);

	// genetic
	Genetic genetic(/*optSysEle*/ optSysEle_E3, /*fields*/ mFields_vec012,/*wavelengths*/ mWavelength_FdC_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 5000);
	genetic.doTheGeneticProcess();

	OpticalSystemElement optimizedOpticalSystem = genetic.getOptimizedOpticalSystemElement();
	oftenUse::print(optimizedOpticalSystem, mWavelength_FdC_vec[0]);

	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

// E4
bool TestGenetic::testE4()
{	
	std::vector<bool> test_vec;

	// surfaces E4
	ApertureStopElement AperStop0_E4(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E4(/*radius*/ 80.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere2_E4(/*radius*/ 70.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere3_E4(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere4_E4(/*radius*/ 35.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere5_E4(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	PlanElement Plan6_E4(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,75.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere1_E4.setParameterPointZ(0.01, 20.0, 0.0, typeModifierVariable);
	Sphere2_E4.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere4_E4.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);

	surfacePtr Aper0_E4_ptr = AperStop0_E4.clone();
	surfacePtr Sphere1_E4_ptr = Sphere1_E4.clone();
	surfacePtr Sphere2_E4_ptr = Sphere2_E4.clone();
	surfacePtr Sphere3_E4_ptr = Sphere3_E4.clone();
	surfacePtr Sphere4_E4_ptr = Sphere4_E4.clone();
	surfacePtr Sphere5_E4_ptr = Sphere5_E4.clone();
	surfacePtr Plan6_E4_ptr = Plan6_E4.clone();

	std::vector<surfacePtr> opticalSystemE4_ptr{ Aper0_E4_ptr, Sphere1_E4_ptr, Sphere2_E4_ptr , Sphere3_E4_ptr, Sphere4_E4_ptr, Sphere5_E4_ptr,  Plan6_E4_ptr };
	std::vector<interaction_ptr> interactionsE4_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E4(opticalSystemE4_ptr, interactionsE4_ptr);

	// check the start system
	std::vector<real> rmsStartSystem_Z{ 221.602,215.043,196.523 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E4, mFields_vec012, mWavelength_FdC_vec, rmsStartSystem_Z, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement_E4, /*fields*/ mFields_vec012,/*wavelengths*/ mWavelength_FdC_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 5000);
	genetic.doTheGeneticProcess();

	std::vector<real> bestValues{ 9.21487,-14.09026,9.2527 };
	test_vec.push_back(oftenUse::checkDeltaVariables(genetic.getOptimizedOpticalSystemElement(), bestValues, 300.0));

	// print the optimized system
	oftenUse::print(genetic.getOptimizedOpticalSystemElement(), mWavelength_FdC_vec[0]);

	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

// E5
bool TestGenetic::testE5()
{
	std::vector<bool> test_vec;

	// surfaces E5
	SphericalElement Sphere0_E5(/*radius*/ 80.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere1_E5(/*radius*/ 70.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere2_E5(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere3_E5(/*radius*/ 35.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere4_E5(/*radius*/ 20.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	ApertureStopElement AperStop5_E5(/* semi height*/1.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan6_E5(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere1_E5.setParameterPointZ(0.01, 20.0, 0.0, typeModifierVariable);
	Sphere2_E5.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere4_E5.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);

	surfacePtr Sphere0_E5_ptr = Sphere0_E5.clone();
	surfacePtr Sphere1_E5_ptr = Sphere1_E5.clone();
	surfacePtr Sphere2_E5_ptr = Sphere2_E5.clone();
	surfacePtr Sphere3_E5_ptr = Sphere3_E5.clone();
	surfacePtr Sphere4_E5_ptr = Sphere4_E5.clone();
	surfacePtr AperStop5_E5_ptr = AperStop5_E5.clone();
	surfacePtr Plan6_E5_ptr = Plan6_E5.clone();

	std::vector<surfacePtr> opticalSystem_E5_ptr{ Sphere0_E5_ptr, Sphere1_E5_ptr, Sphere2_E5_ptr , Sphere3_E5_ptr, Sphere4_E5_ptr, AperStop5_E5_ptr,  Plan6_E5_ptr };
	std::vector<interaction_ptr> interactions_E5_ptr{ refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), doNothing.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E5(opticalSystem_E5_ptr, interactions_E5_ptr);

	// check the start system
	std::vector<real> rmsStartSystem_Z{ 36.272,54.120,135.459 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E5, mAngle000_X_vec, mAngle012_Y_vec, mWavelength_FdC_vec, rmsStartSystem_Z, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement_E5, /*angleX*/ mAngle000_X_vec, /*angleY*/ mAngle012_Y_vec, /*wavelengths*/ mWavelength_FdC_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.doTheGeneticProcess();

	std::vector<real> bestValues{ 0.0,27.8377,-30.2265 };
	test_vec.push_back(oftenUse::checkDeltaVariables(genetic.getOptimizedOpticalSystemElement(), bestValues, 600.0));

	// print the optimized system
	oftenUse::print(genetic.getOptimizedOpticalSystemElement(), mWavelength_FdC_vec[0]);

	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;


}

bool TestGenetic::testE6()
{
	std::vector<bool> test_vec;

	// surfaces E6
	SphericalElement Sphere0_E6(/*radius*/ 80.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere1_E6(/*radius*/ 70.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere2_E6(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere3_E6(/*radius*/ 35.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere4_E6(/*radius*/ 20.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	ApertureStopElement AperStop5_E6(/* semi height*/1.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan6_E6(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere1_E6.setParameterPointZ(0.01, 20.0, 0.0, typeModifierVariable);
	Sphere2_E6.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere4_E6.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);

	surfacePtr Sphere0_E6_ptr = Sphere0_E6.clone();
	surfacePtr Sphere1_E6_ptr = Sphere1_E6.clone();
	surfacePtr Sphere2_E6_ptr = Sphere2_E6.clone();
	surfacePtr Sphere3_E6_ptr = Sphere3_E6.clone();
	surfacePtr Sphere4_E6_ptr = Sphere4_E6.clone();
	surfacePtr AperStop5_E6_ptr = AperStop5_E6.clone();
	surfacePtr Plan6_E6_ptr = Plan6_E6.clone();

	std::vector<surfacePtr> opticalSystem_E6_ptr{ Sphere0_E6_ptr, Sphere1_E6_ptr, Sphere2_E6_ptr , Sphere3_E6_ptr, Sphere4_E6_ptr, AperStop5_E6_ptr,  Plan6_E6_ptr };
	std::vector<interaction_ptr> interactions_E6_ptr{ refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), doNothing.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E6(opticalSystem_E6_ptr, interactions_E6_ptr);

	// check the start system
	std::vector<real> rmsStartSystem_Z{386.081, 384.057, 377.901 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E6, mFields_vec012, mWavelength_FdC_vec, rmsStartSystem_Z, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement_E6, mFields_vec012, /*wavelengths*/ mWavelength_FdC_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 100);
	genetic.doTheGeneticProcess();


	// check rms better start system
	real rmsStartSum = Math::sumAllVectorValues(rmsStartSystem_Z);
	// here we do not get a better result than Zemax, but the algorithm works...
	std::vector<real> rmsOptiSystem = oftenUse::getRMSoptSysHLT(genetic.getOptimizedOpticalSystemElement(), mFields_vec012, mWavelength_FdC_vec, 6, 8);
	real rmsOptiSysSum = Math::sumAllVectorValues(rmsOptiSystem);
	bool betterThanStartSystem = rmsOptiSysSum < rmsStartSum;
	test_vec.push_back(betterThanStartSystem);

	// print the optimized system
	oftenUse::print(genetic.getOptimizedOpticalSystemElement(), mWavelength_FdC_vec[0]);

	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;

}

// E7
bool TestGenetic::testE7()
{
	std::vector<bool> test_E7_vec;

	// surfaces _E7
	SphericalElement Sphere0_E7(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere1_E7(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere2_E7(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	ApertureStopElement AperStop3_E7(/* semi height*/1.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan4_E7(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere0_E7.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere1_E7.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2_E7.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);


	surfacePtr Sphere0_E7_ptr = Sphere0_E7.clone();
	surfacePtr Sphere1_E7_ptr = Sphere1_E7.clone();
	surfacePtr Sphere2_E7_ptr = Sphere2_E7.clone();
	surfacePtr Aper3_E7_ptr = AperStop3_E7.clone();
	surfacePtr Plan4_E7_ptr = Plan4_E7.clone();

	std::vector<surfacePtr> opticalSystem_E7_ptr{ Sphere0_E7_ptr , Sphere1_E7_ptr, Sphere2_E7_ptr, Aper3_E7_ptr,  Plan4_E7_ptr };
	std::vector<interaction_ptr> interactions_E7_ptr{ refrac.clone(), refrac.clone(),refrac.clone(),doNothing.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E7(opticalSystem_E7_ptr, interactions_E7_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system _E7" << std::endl;
	oftenUse::print(optSystemElement_E7, mWave587);

	// check the start system
	std::vector<real> rmsStartSystem_Z{ 169.979,166.698,156.925 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E7, mAngle000_X_vec, mAngle012_Y_vec, mWave550_vec, rmsStartSystem_Z, 0.1, compareTOM_Zemax::comEqual);
	test_E7_vec.push_back(checkStartSys);

	// optimization
	targetCardinalPointsStruct targetCarPoint{};
	targetCarPoint.setCardinalPoints_NO_target();
	Genetic genetic(/*optSysEle*/ optSystemElement_E7, mAngle000_X_vec, mAngle012_Y_vec, /*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 500, targetCarPoint, oftenUse::getDafulatPara_Genetic(true));
	genetic.doTheGeneticProcess();

	// check rms better start system
	real rmsStartSum = Math::sumAllVectorValues(rmsStartSystem_Z);
	// here we do not get a better result than Zemax, but the algorithm works...
	std::vector<real> rmsOptiSystem = oftenUse::getRMSoptSysHLT(genetic.getOptimizedOpticalSystemElement(), mAngle000_X_vec, mAngle012_Y_vec, mWavelength_FdC_vec, 6, 8);
	real rmsOptiSysSum = Math::sumAllVectorValues(rmsOptiSystem);
	bool betterThanStartSystem = rmsOptiSysSum < rmsStartSum;
	test_E7_vec.push_back(betterThanStartSystem);

	// print the optimized system
	oftenUse::print(genetic.getOptimizedOpticalSystemElement(), mWavelength_FdC_vec[0]);

	bool checker = Math::checkTrueOfVectorElements(test_E7_vec);
	return checker;


}

// E8
bool TestGenetic::testE8()
{
	std::vector<bool> test_E8_vec;

	// surfaces _E8
	SphericalElement Sphere0_E8(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere1_E8(/*radius*/ 80.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere2_E8(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	ApertureStopElement AperStop3_E8(/* semi height*/1.5, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere4_E8(/*radius*/ 100.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF11_S1());
	SphericalElement Sphere5_E8(/*radius*/ 100.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF6_S1(), /*refractive index B*/glasses.getSF11_S1());
	SphericalElement Sphere6_E8(/*radius*/ 100.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF6_S1(), /*refractive index B*/glasses.getAir());
	PlanElement Plan7_E8(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere0_E8.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2_E8.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere4_E8.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere6_E8.setParameterPointZ(5.0, 30.0, 0.0, typeModifierVariable);


	surfacePtr Sphere0_E8_ptr = Sphere0_E8.clone();
	surfacePtr Sphere1_E8_ptr = Sphere1_E8.clone();
	surfacePtr Sphere2_E8_ptr = Sphere2_E8.clone();
	surfacePtr Aper3_E8_ptr = AperStop3_E8.clone();
	surfacePtr Sphere4_E8_ptr = Sphere4_E8.clone();
	surfacePtr Sphere5_E8_ptr = Sphere5_E8.clone();
	surfacePtr Sphere6_E8_ptr = Sphere6_E8.clone();
	surfacePtr Plan7_E8_ptr = Plan7_E8.clone();

	std::vector<surfacePtr> opticalSystem_E8_ptr{ Sphere0_E8_ptr , Sphere1_E8_ptr, Sphere2_E8_ptr, Aper3_E8_ptr, Sphere4_E8_ptr, Sphere5_E8_ptr, Sphere6_E8_ptr,  Plan7_E8_ptr };
	std::vector<interaction_ptr> interactions_E8_ptr{ refrac.clone(), refrac.clone(),refrac.clone(),doNothing.clone(),refrac.clone(),refrac.clone(),refrac.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E8(opticalSystem_E8_ptr, interactions_E8_ptr);

	// print the start system
	std::cout << "" << std::endl;
	std::cout << "start system _E8" << std::endl;
	oftenUse::print(optSystemElement_E8, mWave550_vec[0]);

	//// check the start system
	std::vector<real> rmsStartSystem_Z{ 81.550,82.912,87.026 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E8, mAngle000_X_vec, mAngle012_Y_vec, mWave550_vec, rmsStartSystem_Z, 0.1, compareTOM_Zemax::comEqual);
	test_E8_vec.push_back(checkStartSys);

	// optimization
	targetCardinalPointsStruct NO_targetCarPoint;
	NO_targetCarPoint.setCardinalPoints_NO_target();
	Genetic genetic(/*optSysEle*/ optSystemElement_E8, /*fields X*/ mAngle000_X_vec, /*fields Y*/ mAngle012_Y_vec, /*wavelength*/ mWave550_vec, /*rings*/ 6, /*arms*/ 8, /*populatuion*/ 300, /*target cardinal points*/ NO_targetCarPoint, /*default Genetic*/ oftenUse::getDafulatPara_Genetic(true));
	genetic.doTheGeneticProcess();

	// print the optical system
	oftenUse::print(genetic.getOptimizedOpticalSystemElement(), mWave550_vec[0]);

	// check rms better start system
	real rmsStartSum = Math::sumAllVectorValues(rmsStartSystem_Z);
	// here we do not get a better result than Zemax, but the algorithm works...
	std::vector<real> rmsOptiSystem = oftenUse::getRMSoptSysHLT(genetic.getOptimizedOpticalSystemElement(), mAngle000_X_vec, mAngle012_Y_vec, mWave550_vec, 6, 8);
	real rmsOptiSysSum = Math::sumAllVectorValues(rmsOptiSystem);
	bool betterThanStartSystem = rmsOptiSysSum < rmsStartSum;
	test_E8_vec.push_back(betterThanStartSystem);

	// print the optimized system
	oftenUse::print(genetic.getOptimizedOpticalSystemElement(), mWave550_vec[0]);

	bool checker = Math::checkTrueOfVectorElements(test_E8_vec);
	return checker;
}

// test geneartion modes
bool TestGenetic::testGenerationModes(real min, real max, real sampling, unsigned int maxInteration)
{
	std::vector<bool> test_vec;


	// test random
	auto startRandom = std::chrono::high_resolution_clock::now();
	bool testRandom = testRandomMode(min, max, sampling, maxInteration);
	auto endRandom = std::chrono::high_resolution_clock::now();
	std::chrono::duration<real> timeRandom = endRandom -startRandom;

	// test clever sampling mode
	auto startClever = std::chrono::high_resolution_clock::now();
	bool cleverSampling = testClerverSampleMode(min, max, sampling, maxInteration);
	auto endClever = std::chrono::high_resolution_clock::now();
	std::chrono::duration<real> timeClever = endClever - startClever;
	
	// test normal distibution mode
	auto startND = std::chrono::high_resolution_clock::now();
	bool testNormalDistibution = testNormalDistributionMode(min, max, sampling, maxInteration);
	auto endND = std::chrono::high_resolution_clock::now();
	std::chrono::duration<real> timeND = endND -startND;


	// test normal distibution default mode
	auto startNDD = std::chrono::high_resolution_clock::now();
	bool testNormalDistibutionDefault = testNormalDistributionDeefaultMode(min, max, sampling, maxInteration);
	auto endNDD = std::chrono::high_resolution_clock::now();
	std::chrono::duration<real> timeNDD = endNDD - startNDD;
	

	// export time
	std::string location = "../tests/TestGenetic/samplingModes/";
	inportExportData::saveDoubleInTXT(location, "times", "random: ", timeRandom.count());
	inportExportData::saveDoubleInTXT(location, "times", "clever: ", timeClever.count());
	inportExportData::saveDoubleInTXT(location, "times", "normal distribution: ", timeND.count());
	inportExportData::saveDoubleInTXT(location, "times", "normal default distribution: ", timeNDD.count());

	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

// random generation mode
bool TestGenetic::testRandomMode(real min, real max, real sampling, unsigned int maxInteration)
{
	Genetic genetic;
	genetic.setChooseValueMode(randomMode);
	bool checker = true;
	unsigned int iteration = 0;
	real tempNumber;


	std::vector<real> number_vec;
	number_vec.resize(maxInteration);

	while (checker)
	{
		tempNumber = genetic.getNumberToBuildOptSys(min, max);

		// just for debugging
		// std::cout << "temp number: " << tempNumber << std::endl;

		number_vec[iteration] = tempNumber;

		++iteration;
		if (iteration >= maxInteration)
		{
			checker = false;
		}
	}

	// make the histigram
	std::vector<real> histogram = oftenUse::makeHistogram(number_vec, min, max, sampling);

	// export vector to csv data
	std::string location = "../tests/TestGenetic/samplingModes/";
	std::string nameExcel = "randomMode";

	std::string holeFile = "../tests/TestGenetic/samplingModes/randomMode.csv";
	std::ofstream ofs;
	ofs.open(holeFile, std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	inportExportData::exportHistogramToExcel(location, nameExcel, histogram, sampling, min, max);


	return true;
}

// clever sample Mode
bool TestGenetic::testClerverSampleMode(real min, real max, real sampling, unsigned int maxInteration)
{
	Genetic genetic;
	genetic.setChooseValueMode(cleverSamplingMode);
	bool checker = true;
	unsigned int iteration = 0;
	real tempNumber;


	std::vector<real> number_vec;
	number_vec.resize(maxInteration);

	while (checker)
	{
		tempNumber = genetic.getNumberToBuildOptSys(min, max);

		// just for debugging
		// std::cout << "temp number: " << tempNumber << std::endl;

		number_vec[iteration] = tempNumber;

		++iteration;
		if (iteration >= maxInteration)
		{
			checker = false;
		}
	}

	// make the histigram
	std::vector<real> histogram = oftenUse::makeHistogram(number_vec, min, max, sampling);
		
	// export vector to csv data
	std::string location = "../tests/TestGenetic/samplingModes/";
	std::string nameExcel = "cleverSamplingMode";

	std::string holeFile = "../tests/TestGenetic/samplingModes/cleverSamplingMode.csv";
	std::ofstream ofs;
	ofs.open(holeFile, std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	inportExportData::exportHistogramToExcel(location, nameExcel, histogram, sampling, min, max);
	
	return true;
}

// normal distribution mode
bool TestGenetic::testNormalDistributionMode(real min, real max, real sampling, unsigned int maxInteration)
{
	Genetic genetic;
	genetic.setChooseValueMode(normalDistributionMode);
	genetic.setMeanToCalcND(0.0);
	genetic.setStddevToCalcND(450);
	bool checker = true;
	unsigned int iteration = 0;
	real tempNumber;


	std::vector<real> number_vec;
	number_vec.resize(maxInteration);

	while (checker)
	{
		tempNumber = genetic.getNumberToBuildOptSys(min, max);

		// just for debugging
		//std::cout << "temp number: " << tempNumber << std::endl;

		number_vec[iteration] = tempNumber;

		++iteration;
		if (iteration >= maxInteration)
		{
			checker = false;
		}
	}

	// make the histigram
	std::vector<real> histogram = oftenUse::makeHistogram(number_vec, min, max, sampling);

	// export vector to csv data
	std::string location = "../tests/TestGenetic/samplingModes/";
	std::string nameExcel = "normalDistributionMode";

	std::string holeFile = "../tests/TestGenetic/samplingModes/normalDistributionMode.csv";
	std::ofstream ofs;
	ofs.open(holeFile, std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	inportExportData::exportHistogramToExcel(location, nameExcel, histogram, sampling, min, max);

	return true;

}

// normal distribution default mode
bool TestGenetic::testNormalDistributionDeefaultMode(real min, real max, real sampling, unsigned int maxInteration)
{
	Genetic genetic;
	genetic.setChooseValueMode(normalDistributionDefaultMode);
	bool checker = true;
	unsigned int iteration = 0;
	real tempNumber;


	std::vector<real> number_vec;
	number_vec.resize(maxInteration);

	while (checker)
	{
		tempNumber = genetic.getNumberToBuildOptSys(min, max);

		// just for debugging
		// std::cout << "temp number: " << tempNumber << std::endl;

		number_vec[iteration] = tempNumber;

		++iteration;
		if (iteration >= maxInteration)
		{
			checker = false;
		}
	}

	// make the histigram
	std::vector<real> histogram = oftenUse::makeHistogram(number_vec, min, max, sampling);

	// export vector to csv data
	std::string location = "../tests/TestGenetic/samplingModes/";
	std::string nameExcel = "normalDistributionDefaulMode";

	std::string holeFile = "../tests/TestGenetic/samplingModes/normalDistributionDefaulMode.csv";
	std::ofstream ofs;
	ofs.open(holeFile, std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	inportExportData::exportHistogramToExcel(location, nameExcel, histogram, sampling, min, max);

	return true;

}



// test target cardinal points super function
bool TestGenetic::testCardinalPointsSuperFct()
{
	std::vector<bool> test_vec;

	// EFL
	bool checkEFL_obj = testTargetEFL_genetic_obj();
	test_vec.push_back(checkEFL_obj);
	bool checkEFL_inf = testTargetEFL_genetic_inf();
	test_vec.push_back(checkEFL_inf);
	// PP_obj
	bool checkPP_obj_obj = testTargetPP_genetic_obj();
	test_vec.push_back(checkPP_obj_obj);
	bool checkPP_obj_inf = testTargetPP_genetic_inf();
	test_vec.push_back(checkPP_obj_inf);
	// PP_ima
	bool checkPP_ima_obj = testTargetPP_ima_genetic_obj();
	test_vec.push_back(checkPP_ima_obj);
	bool checkPP_ima_inf = testTargetPP_ima_genetic_inf();
	test_vec.push_back(checkPP_ima_inf);
	// EXPP_lastSurface 
	bool checkEXPP_lastSurface_obj = testTargetEXPP_lastSurface_genetic_obj();
	test_vec.push_back(checkEXPP_lastSurface_obj);
	bool checkEXPP_lastSurface_inf = testTargetEXPP_lastSurface_genetic_inf();
	test_vec.push_back(checkEXPP_lastSurface_inf);
	// EXPD
	bool checkEXPD_obj = testTargetEXPD_obj();
	test_vec.push_back(checkEXPD_obj);
	bool checkEXPD_inf = testTargetEXPD_inf();
	test_vec.push_back(checkEXPD_inf);
	// Mag
	bool checkMag_obj = testTargetMag_obj();
	test_vec.push_back(checkMag_obj);
	bool checkMag_inf = testTargetMag_inf();
	test_vec.push_back(checkMag_inf);
	// NA_objSpace
	bool checkNA_objSpace_obj = testTargetNA_objSpace_obj();
	test_vec.push_back(checkNA_objSpace_obj);
	bool checkNA_objSpace_inf = testTargetNA_objSpace_inf();
	test_vec.push_back(checkNA_objSpace_inf);
	// ENPP_firstSurface
	bool checkENPP_firstSurface_obj = testTargetENPP_firstSurface_obj();
	test_vec.push_back(checkENPP_firstSurface_obj);
	bool checkENPP_firstSurface_inf = testTargetENPP_firstSurface_inf();
	test_vec.push_back(checkENPP_firstSurface_inf);
	// ENPP_global
	bool checkENPP_global_obj = testTargetENPP_global_obj();
	test_vec.push_back(checkENPP_global_obj);
	bool checkENPP_global_inf = testTargetENPP_global_inf();
	test_vec.push_back(checkENPP_global_inf);
	// ENPD
	bool checkENPD_obj = testTargetENPD_obj();
	test_vec.push_back(checkENPD_obj);
	bool checkENPD_inf = testTargetENPD_inf();
	test_vec.push_back(checkENPD_inf);
	// f_number_imaSpace
	bool checkf_number_imaSpace_obj = testTargetf_number_imaSpace_obj();
	test_vec.push_back(checkf_number_imaSpace_obj);
	bool checkf_number_imaSpace_inf = testTargetf_number_imaSpace_inf();
	test_vec.push_back(checkf_number_imaSpace_inf);
	// NA_imaSpace
	bool checkNA_imaSpace_obj = testTargetNA_imaSpace_obj();
	test_vec.push_back(checkNA_imaSpace_obj);
	bool checkNA_imaSpace_inf = testTargetNA_imaSpace_inf();
	test_vec.push_back(checkNA_imaSpace_inf);
	// WFNO
	bool checkWFNO_obj = testTargetWFNO_obj();
	test_vec.push_back(checkWFNO_obj);
	bool checkWFNO_inf = testTargetWFNO_inf();
	test_vec.push_back(checkWFNO_inf);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}


// test target EFL
bool TestGenetic::testTargetEFL_genetic_obj()
{
	std::vector<bool> test_vec;

	// surfaces 
	SphericalElement Sphere0(/*radius*/ 20.0, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere1(/*radius*/ 15.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getSF11_S1());
	SphericalElement Sphere2(/*radius*/ 15.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF11_S1());
	ApertureStopElement AperStop3(/* semi height*/1.5, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan4(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere0.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2.setParameterPointZ(0.0, 1000.0, 0.0, typeModifierVariable);


	surfacePtr Sphere0_ptr = Sphere0.clone();
	surfacePtr Sphere1_ptr = Sphere1.clone();
	surfacePtr Sphere2_ptr = Sphere2.clone();
	surfacePtr AperStop3_ptr = AperStop3.clone();
	surfacePtr Plan4_ptr = Plan4.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ Sphere0_ptr, Sphere1_ptr, Sphere2_ptr , AperStop3_ptr, Plan4_ptr };
	std::vector<interaction_ptr> interactions_ptr{ refrac.clone(), refrac.clone(), refrac.clone(), doNothing.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSysEle(opticalSystem_ptr, interactions_ptr);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSysEle, mWavelength_FdC_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSysEle, mWavelength_FdC_vec[0], objectPoint_inf_obj::obj);
	real startEFL = startCardinalPoints.getEFL();

	// check the start system
	std::vector<real> rmsStartSystem{ 56.243, 72.755 };
	std::vector<VectorStructR3> startFields{ {0.0,0.0,0.0},{0.0,1.0,0.0} };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle, startFields, mWavelength_FdC_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);

	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetEFL = 20.0;
	targetCarPoints.setTargetEFL(targetEFL);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSysEle, /*fields*/ startFields,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();

	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);

	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWavelength_FdC_vec[0], objectPoint_inf_obj::obj);
	real optEFL = cardinalPointsOptimizedSystem.getEFL();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startEFL, /*optimized value*/ optEFL, /*target val*/ targetEFL);
	test_vec.push_back(checkOptCar);

	bool isEFL_target = targetCarPoints.isEFL_target();
	test_vec.push_back(isEFL_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

bool TestGenetic::testTargetEFL_genetic_inf()
{
	std::vector<bool> test_vec;

	// surfaces 
	SphericalElement Sphere0(/*radius*/ 40.0, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere1(/*radius*/ 30.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBAFN10_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2(/*radius*/ 20.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	ApertureStopElement AperStop3(/* semi height*/1.5, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan4(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere1.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);

	surfacePtr Sphere0_ptr = Sphere0.clone();
	surfacePtr Sphere1_ptr = Sphere1.clone();
	surfacePtr Sphere2_ptr = Sphere2.clone();
	surfacePtr AperStop3_ptr = AperStop3.clone();
	surfacePtr Plan4_ptr = Plan4.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ Sphere0_ptr, Sphere1_ptr, Sphere2_ptr , AperStop3_ptr, Plan4_ptr };
	std::vector<interaction_ptr> interactions_ptr{ refrac.clone(), refrac.clone(), refrac.clone(), doNothing.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSysEle(opticalSystem_ptr, interactions_ptr);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSysEle, mWavelength_FdC_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSysEle, mWavelength_FdC_vec[0], objectPoint_inf_obj::obj);
	real startEFL = startCardinalPoints.getEFL();

	// check the start system
	std::vector<real> rmsStartSystem{ 276.724, 273.232 };
	std::vector<real> angelX{ 0.0, 0.0 };
	std::vector<real> anlgeY{ 0.0, 1.0 };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle, angelX, anlgeY, mWavelength_FdC_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);

	targetCardinalPointsStruct targetCarPoints;
	// ***
	real targetEFL = 30.0;
	targetCarPoints.setTargetEFL(targetEFL);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSysEle, angelX, anlgeY,/*wavelengths*/ mWavelength_FdC_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();

	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	oftenUse::print(optimizedSystem, mWavelength_FdC_vec[0]);

	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::obj);
	real optEFL = cardinalPointsOptimizedSystem.getEFL();

	std::cout << "targe EFL: " << targetEFL << std::endl;
	std::cout << "optimized EFL: " << optEFL << std::endl;

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startEFL, /*optimized value*/ optEFL, /*target val*/ targetEFL);
	test_vec.push_back(checkOptCar);

	bool isEFL_target = targetCarPoints.isEFL_target();
	test_vec.push_back(isEFL_target);

	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;

}

//test target PP_obj
bool TestGenetic::testTargetPP_genetic_obj()
{
	std::vector<bool> test_vec;

	// surfaces E10
	SphericalElement Sphere0(/*radius*/ 80.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getF5_S1());
	SphericalElement Sphere1(/*radius*/ 60.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBAF52_S1(), /*refractive index B*/glasses.getF5_S1());
	SphericalElement Sphere2(/*radius*/ 70.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF52_S1());
	ApertureStopElement AperStop3(/* semi height*/2.0, /*point*/{ 0.0,0.0,50 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere4(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement Sphere5(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getNBAK2_S1());
	SphericalElement Sphere6(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAK2_S1());
	PlanElement Plan7(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,105.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere1.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2.setParameterPointZ(0.0, 20.0, 0.0, typeModifierVariable);

	surfacePtr Sphere0_ptr = Sphere0.clone();
	surfacePtr Sphere1_ptr = Sphere1.clone();
	surfacePtr Sphere2_ptr = Sphere2.clone();
	surfacePtr Aper3_ptr = AperStop3.clone();
	surfacePtr Sphere4_ptr = Sphere4.clone();
	surfacePtr Sphere5_ptr = Sphere5.clone();
	surfacePtr Sphere6_ptr = Sphere6.clone();
	surfacePtr Plan7_ptr = Plan7.clone();

	std::vector<surfacePtr> opticalSystemE10_ptr{ Sphere0_ptr, Sphere1_ptr, Sphere2_ptr , Aper3_ptr, Sphere4_ptr, Sphere5_ptr, Sphere6_ptr, Plan7_ptr };
	std::vector<interaction_ptr> interactionsE10_ptr{ refrac.clone(), refrac.clone(),refrac.clone(), doNothing.clone(), refrac.clone(), refrac.clone(),refrac.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE10_ptr, interactionsE10_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::obj);
	real startPP_Obj = startCardinalPoints.getPP_obj();

	// check the start system
	std::vector<real> rmsStartSystem{ 1282.77 };
	std::vector<VectorStructR3> startFields{ {0.0,0.0,0.0} };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, startFields, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);

	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetPP_obj = 40.0;
	targetCarPoints.setTargetPP_obj(targetPP_obj);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*fields*/ startFields,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();

	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);

	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWavelength_FdC_vec[0], objectPoint_inf_obj::obj);
	real optPP_obj = cardinalPointsOptimizedSystem.getPP_obj();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startPP_Obj, /*optimized value*/ optPP_obj, /*target val*/ targetPP_obj);
	test_vec.push_back(checkOptCar);

	bool isPP_obj_target = targetCarPoints.isPP_obj_target();
	test_vec.push_back(isPP_obj_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

bool TestGenetic::testTargetPP_genetic_inf()
{
	std::vector<bool> test_vec;

	// surfaces E16
	SphericalElement Sphere0_E16(/*radius*/ 10.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF66_S1());
	SphericalElement Sphere1_E16(/*radius*/ 20.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF66_S1());
	SphericalElement Sphere2_E16(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getKZFSN4_S1());
	SphericalElement Sphere3_E16(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getKZFSN4_S1());
	SphericalElement Sphere4_E16(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN6_S1());
	SphericalElement Sphere5_E16(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN6_S1());
	ApertureStopElement AperStop6_E16(/* semi height*/3.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan7_E16(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere0_E16.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2_E16.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere5_E16.setParameterPointZ(0.0, 100.0, 0.0, typeModifierVariable);

	surfacePtr Sphere0_E16_ptr = Sphere0_E16.clone();
	surfacePtr Sphere1_E16_ptr = Sphere1_E16.clone();
	surfacePtr Sphere2_E16_ptr = Sphere2_E16.clone();
	surfacePtr Sphere3_E16_ptr = Sphere3_E16.clone();
	surfacePtr Sphere4_E16_ptr = Sphere4_E16.clone();
	surfacePtr Sphere5_E16_ptr = Sphere5_E16.clone();
	surfacePtr Aper6_E16_ptr = AperStop6_E16.clone();
	surfacePtr Plan7_E16_ptr = Plan7_E16.clone();

	std::vector<surfacePtr> opticalSystemE16_ptr{ Sphere0_E16_ptr, Sphere1_E16_ptr, Sphere2_E16_ptr , Sphere3_E16_ptr,   Sphere4_E16_ptr, Sphere5_E16_ptr, Aper6_E16_ptr, Plan7_E16_ptr };
	std::vector<interaction_ptr> interactionsE16_ptr{ refrac.clone(), refrac.clone(),refrac.clone(),  refrac.clone(), refrac.clone(),refrac.clone(),doNothing.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE16_ptr, interactionsE16_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);



	// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> wavelenght_vec(1);
	wavelenght_vec[0] = 550.0;
	std::vector<real> rmsStartSystem{ 2581.10 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, anglesXvec, anglesYvec, wavelenght_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkTheSystem);
	// ***

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::inf);
	real startPP_Obj = startCardinalPoints.getPP_obj();


	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetPP_obj = 15.0;
	targetCarPoints.setTargetPP_obj(targetPP_obj);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*angleX*/ anglesXvec, /*angleY*/ anglesYvec,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();

	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);

	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::inf);
	real optPP_obj = cardinalPointsOptimizedSystem.getPP_obj();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startPP_Obj, /*optimized value*/ optPP_obj, /*target val*/ targetPP_obj);
	test_vec.push_back(checkOptCar);

	bool isPP_obj_target = targetCarPoints.isPP_obj_target();
	test_vec.push_back(isPP_obj_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

//test target PP_ima
bool TestGenetic::testTargetPP_ima_genetic_obj()
{
	std::vector<bool> test_vec;

	// surfaces E10
	SphericalElement Sphere0_E10(/*radius*/ 80.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getF5_S1());
	SphericalElement Sphere1_E10(/*radius*/ 60.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBAF52_S1(), /*refractive index B*/glasses.getF5_S1());
	SphericalElement Sphere2_E10(/*radius*/ 70.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF52_S1());
	ApertureStopElement AperStop3_E10(/* semi height*/2.0, /*point*/{ 0.0,0.0,50 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere4_E10(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement Sphere5_E10(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getNBAK2_S1());
	SphericalElement Sphere6_E10(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAK2_S1());
	PlanElement Plan7_E10(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,105.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere1_E10.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2_E10.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2_E10.setParameterPointZ(0.0, 20.0, 0.0, typeModifierVariable);

	surfacePtr Sphere0_E10_ptr = Sphere0_E10.clone();
	surfacePtr Sphere1_E10_ptr = Sphere1_E10.clone();
	surfacePtr Sphere2_E10_ptr = Sphere2_E10.clone();
	surfacePtr Aper3_E10_ptr = AperStop3_E10.clone();
	surfacePtr Sphere4_E10_ptr = Sphere4_E10.clone();
	surfacePtr Sphere5_E10_ptr = Sphere5_E10.clone();
	surfacePtr Sphere6_E10_ptr = Sphere6_E10.clone();
	surfacePtr Plan7_E10_ptr = Plan7_E10.clone();

	std::vector<surfacePtr> opticalSystemE10_ptr{ Sphere0_E10_ptr, Sphere1_E10_ptr, Sphere2_E10_ptr , Aper3_E10_ptr, Sphere4_E10_ptr, Sphere5_E10_ptr, Sphere6_E10_ptr, Plan7_E10_ptr };
	std::vector<interaction_ptr> interactionsE10_ptr{ refrac.clone(), refrac.clone(),refrac.clone(), doNothing.clone(), refrac.clone(), refrac.clone(),refrac.clone(),absorb.clone() };;

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE10_ptr, interactionsE10_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::obj);
	real startPP_Ima = startCardinalPoints.getPP_ima();

	// check the start system
	std::vector<real> rmsStartSystem{ 1282.77 };
	std::vector<VectorStructR3> startFields{ {0.0,0.0,0.0} };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, startFields, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);

	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetPP_ima = -40.0;
	targetCarPoints.setTargetPP_ima(targetPP_ima);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*fields*/ startFields,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();

	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);

	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::obj);
	real optPP_ima = cardinalPointsOptimizedSystem.getPP_ima();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startPP_Ima, /*optimized value*/ optPP_ima, /*target val*/ targetPP_ima);
	test_vec.push_back(checkOptCar);

	bool isPP_ima_target = targetCarPoints.isPP_ima_target();
	test_vec.push_back(isPP_ima_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

bool TestGenetic::testTargetPP_ima_genetic_inf()
{
	std::vector<bool> test_vec;

	// surfaces E16
	SphericalElement Sphere0_E16(/*radius*/ 10.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF66_S1());
	SphericalElement Sphere1_E16(/*radius*/ 20.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF66_S1());
	SphericalElement Sphere2_E16(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getKZFSN4_S1());
	SphericalElement Sphere3_E16(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getKZFSN4_S1());
	SphericalElement Sphere4_E16(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN6_S1());
	SphericalElement Sphere5_E16(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN6_S1());
	ApertureStopElement AperStop6_E16(/* semi height*/3.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan7_E16(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere1_E16.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2_E16.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2_E16.setParameterPointZ(0.0, 20.0, 0.0, typeModifierVariable);

	surfacePtr Sphere0_E16_ptr = Sphere0_E16.clone();
	surfacePtr Sphere1_E16_ptr = Sphere1_E16.clone();
	surfacePtr Sphere2_E16_ptr = Sphere2_E16.clone();
	surfacePtr Sphere3_E16_ptr = Sphere3_E16.clone();
	surfacePtr Sphere4_E16_ptr = Sphere4_E16.clone();
	surfacePtr Sphere5_E16_ptr = Sphere5_E16.clone();
	surfacePtr Aper6_E16_ptr = AperStop6_E16.clone();
	surfacePtr Plan7_E16_ptr = Plan7_E16.clone();

	std::vector<surfacePtr> opticalSystemE16_ptr{ Sphere0_E16_ptr, Sphere1_E16_ptr, Sphere2_E16_ptr , Sphere3_E16_ptr,   Sphere4_E16_ptr, Sphere5_E16_ptr, Aper6_E16_ptr, Plan7_E16_ptr };
	std::vector<interaction_ptr> interactionsE16_ptr{ refrac.clone(), refrac.clone(),refrac.clone(),  refrac.clone(), refrac.clone(),refrac.clone(),doNothing.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE16_ptr, interactionsE16_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::inf);
	real startPP_Ima = startCardinalPoints.getPP_ima();

	// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> rmsStartSystem{ 2581.10 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, anglesXvec, anglesYvec, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkTheSystem);


	// ***

	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetPP_ima = -100.0;
	targetCarPoints.setTargetPP_ima(targetPP_ima);
	// ***



	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*angleX*/ anglesXvec, /*angleY*/ anglesYvec,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();


	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);

	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::inf);
	real optPP_ima = cardinalPointsOptimizedSystem.getPP_ima();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startPP_Ima, /*optimized value*/ optPP_ima, /*target val*/ targetPP_ima);
	test_vec.push_back(checkOptCar);

	bool isPP_ima_target = targetCarPoints.isPP_ima_target();
	test_vec.push_back(isPP_ima_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

//test target EXPP_lastSurface
bool TestGenetic::testTargetEXPP_lastSurface_genetic_obj()
{
	std::vector<bool> test_vec;

	// surfaces E11
	SphericalElement Sphere0_E11(/*radius*/ 20.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAK4_S1());
	SphericalElement Sphere1_E11(/*radius*/ 30.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAK4_S1());
	SphericalElement Sphere2_E11(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF66_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere3_E11(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF66_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere4_E11(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getLLF1_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere5_E11(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getLLF1_S1());
	ApertureStopElement AperStop6_E11(/* semi height*/1.0, /*point*/{ 0.0,0.0,140 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan7_E11(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,150.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere1_E11.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere3_E11.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere3_E11.setParameterPointZ(0.0, 150.0, 0.0, typeModifierVariable);

	surfacePtr Sphere0_E11_ptr = Sphere0_E11.clone();
	surfacePtr Sphere1_E11_ptr = Sphere1_E11.clone();
	surfacePtr Sphere2_E11_ptr = Sphere2_E11.clone();
	surfacePtr Sphere3_E11_ptr = Sphere3_E11.clone();
	surfacePtr Sphere4_E11_ptr = Sphere4_E11.clone();
	surfacePtr Sphere5_E11_ptr = Sphere5_E11.clone();
	surfacePtr Aper6_E11_ptr = AperStop6_E11.clone();
	surfacePtr Plan7_E11_ptr = Plan7_E11.clone();

	std::vector<surfacePtr> opticalSystemE11_ptr{ Sphere0_E11_ptr, Sphere1_E11_ptr, Sphere2_E11_ptr , Sphere3_E11_ptr , Sphere4_E11_ptr , Sphere5_E11_ptr , Aper6_E11_ptr, Plan7_E11_ptr };
	std::vector<interaction_ptr> interactionsE11_ptr{ refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone() , refrac.clone() , refrac.clone() ,doNothing.clone() , absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE11_ptr, interactionsE11_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::obj);
	real startEXPP_lastSurface = startCardinalPoints.getEXPP_lastSurface();

	// check the start system
	std::vector<real> rmsStartSystem{ 626.82 };
	std::vector<VectorStructR3> startFields{ {0.0,0.0,0.0} };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, startFields, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);


	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetEXPP_lastSurface = -7;
	targetCarPoints.setTargetEXPP_lastSurface(targetEXPP_lastSurface);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*fields*/ startFields,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();


	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);



	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::obj);
	real optEXPP_lastSurface = cardinalPointsOptimizedSystem.getEXPP_lastSurface();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startEXPP_lastSurface, /*optimized value*/ optEXPP_lastSurface, /*target val*/ targetEXPP_lastSurface);
	test_vec.push_back(checkOptCar);

	bool isEXPP_lastSurface_target = targetCarPoints.isEXPP_lastSurface_target();
	test_vec.push_back(isEXPP_lastSurface_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

bool TestGenetic::testTargetEXPP_lastSurface_genetic_inf()
{
	std::vector<bool> test_vec;

	// surfaces E9
	SphericalElement Sphere0(/*radius*/ 100, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement Sphere1(/*radius*/ 70, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBAFN10_S1(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement Sphere2(/*radius*/ 120, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	ApertureStopElement AperStop3(/* semi height*/1.5, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere4(/*radius*/ 60, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF4_S1());
	SphericalElement Sphere5(/*radius*/ 80, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF4_S1());
	PlanElement Plan6(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere1.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere5.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere4.setParameterPointZ(0.0, 40.0, 0.0, typeModifierVariable);

	surfacePtr Sphere0_ptr = Sphere0.clone();
	surfacePtr Sphere1_ptr = Sphere1.clone();
	surfacePtr Sphere2_ptr = Sphere2.clone();
	surfacePtr Aper3_ptr = AperStop3.clone();
	surfacePtr Sphere4_ptr = Sphere4.clone();
	surfacePtr Sphere5_ptr = Sphere5.clone();
	surfacePtr Plan6_ptr = Plan6.clone();

	std::vector<surfacePtr> opticalSystemE9_ptr{ Sphere0_ptr, Sphere1_ptr, Sphere2_ptr, Aper3_ptr, Sphere4_ptr, Sphere5_ptr, Plan6_ptr };
	std::vector<interaction_ptr> interactionsE9_ptr{ refrac.clone(), refrac.clone(),refrac.clone(), doNothing.clone(), refrac.clone(),  refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE9_ptr, interactionsE9_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::inf);
	real startEXPP_lastSurface = startCardinalPoints.getEXPP_lastSurface();

	// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> rmsStartSystem{ 538.112 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, anglesXvec, anglesYvec, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkTheSystem);

	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetEXPP_lastSurface = -30;
	targetCarPoints.setTargetEXPP_lastSurface(targetEXPP_lastSurface);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*angleX*/ anglesXvec, /*angleY*/ anglesYvec,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();

	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);

	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::inf);
	real optEXPP_lastSurface = cardinalPointsOptimizedSystem.getEXPP_lastSurface();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startEXPP_lastSurface, /*optimized value*/ optEXPP_lastSurface, /*target val*/ targetEXPP_lastSurface);
	test_vec.push_back(checkOptCar);

	bool isEXPP_lastSurface_target = targetCarPoints.isEXPP_lastSurface_target();
	test_vec.push_back(isEXPP_lastSurface_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

//test target EXPD
bool TestGenetic::testTargetEXPD_obj()
{
	std::vector<bool> test_vec;

	// surfaces E11
	SphericalElement Sphere0_E11(/*radius*/ 20.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAK4_S1());
	SphericalElement Sphere1_E11(/*radius*/ 30.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAK4_S1());
	SphericalElement Sphere2_E11(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF66_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere3_E11(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF66_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere4_E11(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getLLF1_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere5_E11(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getLLF1_S1());
	ApertureStopElement AperStop6_E11(/* semi height*/1.0, /*point*/{ 0.0,0.0,140 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan7_E11(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,150.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere5_E11.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2_E11.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere3_E11.setParameterPointZ(0.0, 150.0, 0.0, typeModifierVariable);

	surfacePtr Sphere0_E11_ptr = Sphere0_E11.clone();
	surfacePtr Sphere1_E11_ptr = Sphere1_E11.clone();
	surfacePtr Sphere2_E11_ptr = Sphere2_E11.clone();
	surfacePtr Sphere3_E11_ptr = Sphere3_E11.clone();
	surfacePtr Sphere4_E11_ptr = Sphere4_E11.clone();
	surfacePtr Sphere5_E11_ptr = Sphere5_E11.clone();
	surfacePtr Aper6_E11_ptr = AperStop6_E11.clone();
	surfacePtr Plan7_E11_ptr = Plan7_E11.clone();

	std::vector<surfacePtr> opticalSystemE11_ptr{ Sphere0_E11_ptr, Sphere1_E11_ptr, Sphere2_E11_ptr , Sphere3_E11_ptr , Sphere4_E11_ptr , Sphere5_E11_ptr , Aper6_E11_ptr, Plan7_E11_ptr };
	std::vector<interaction_ptr> interactionsE11_ptr{ refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone() , refrac.clone() , refrac.clone() ,doNothing.clone() , absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE11_ptr, interactionsE11_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::obj);
	real startEXPD = startCardinalPoints.getEXPD();

	// check the start system
	std::vector<real> rmsStartSystem{ 626.82 };
	std::vector<VectorStructR3> startFields{ {0.0,0.0,0.0} };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, startFields, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);


	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetEXPD = 1.0;
	targetCarPoints.setTargetEXPD(targetEXPD);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*fields*/ startFields,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();


	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);



	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::obj);
	real optEXPD = cardinalPointsOptimizedSystem.getEXPD();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startEXPD, /*optimized value*/ optEXPD, /*target val*/ targetEXPD);
	test_vec.push_back(checkOptCar);

	bool isEXPD_target = targetCarPoints.isEXPD_target();
	test_vec.push_back(isEXPD_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

bool TestGenetic::testTargetEXPD_inf()
{
	std::vector<bool> test_vec;

	// surfaces E17
	SphericalElement Sphere0_E17(/*radius*/ 99999999999999999.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getLAFN7_S1());
	SphericalElement Sphere1_E17(/*radius*/ 20.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getLAFN7_S1(), /*refractive index B*/glasses.getNBAK4_S1());
	SphericalElement Sphere2_E17(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBAK4_S1(), /*refractive index B*/glasses.getAir());
	ApertureStopElement AperStop3_E17(/* semi height*/0.5, /*point*/{ 0.0,0.0,15 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere4_E17(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK10_S1());
	SphericalElement Sphere5_E17(/*radius*/ 200.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBK10_S1(), /*refractive index B*/glasses.getNLAK10_S1());
	SphericalElement Sphere6_E17(/*radius*/ 300.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAK10_S1());
	PlanElement Plan7_E17(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());


	Sphere1_E17.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere4_E17.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2_E17.setParameterPointZ(0.0, 20.0, 0.0, typeModifierVariable);

	surfacePtr Sphere0_E17_ptr = Sphere0_E17.clone();
	surfacePtr Sphere1_E17_ptr = Sphere1_E17.clone();
	surfacePtr Sphere2_E17_ptr = Sphere2_E17.clone();
	surfacePtr Aper3_E17_ptr = AperStop3_E17.clone();
	surfacePtr Sphere4_E17_ptr = Sphere4_E17.clone();
	surfacePtr Sphere5_E17_ptr = Sphere5_E17.clone();
	surfacePtr Sphere6_E17_ptr = Sphere6_E17.clone();
	surfacePtr Plan7_E17_ptr = Plan7_E17.clone();

	std::vector<surfacePtr> opticalSystemE17_ptr{ Sphere0_E17_ptr, Sphere1_E17_ptr, Sphere2_E17_ptr , Aper3_E17_ptr, Sphere4_E17_ptr, Sphere5_E17_ptr, Sphere6_E17_ptr, Plan7_E17_ptr };
	std::vector<interaction_ptr> interactionsE17_ptr{ refrac.clone(), refrac.clone(),refrac.clone(), doNothing.clone(), refrac.clone(), refrac.clone(),refrac.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE17_ptr, interactionsE17_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::inf);
	real startEXPD = startCardinalPoints.getEXPD();

	// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> rmsStartSystem{ 498.142 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, anglesXvec, anglesYvec, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkTheSystem);

	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetEXPD = 2;
	targetCarPoints.setTargetEXPD(targetEXPD);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*angleX*/ anglesXvec, /*angleY*/ anglesYvec,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();

	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);

	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::inf);
	real optEXPD = cardinalPointsOptimizedSystem.getEXPD();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startEXPD, /*optimized value*/ optEXPD, /*target val*/ targetEXPD);
	test_vec.push_back(checkOptCar);

	bool isEXPD_target = targetCarPoints.isEXPD_target();
	test_vec.push_back(isEXPD_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

//test target NA_objSpace
bool TestGenetic::testTargetNA_objSpace_obj()
{
	std::vector<bool> test_vec;

	// surfaces E10
	SphericalElement Sphere0(/*radius*/ 80.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getF5_S1());
	SphericalElement Sphere1(/*radius*/ 60.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBAF52_S1(), /*refractive index B*/glasses.getF5_S1());
	SphericalElement Sphere2(/*radius*/ 70.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF52_S1());
	ApertureStopElement AperStop3(/* semi height*/2.0, /*point*/{ 0.0,0.0,50 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere4(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement Sphere5(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getNBAK2_S1());
	SphericalElement Sphere6(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAK2_S1());
	PlanElement Plan7(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,105.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere1.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2.setParameterPointZ(0.0, 40.0, 0.0, typeModifierVariable);

	surfacePtr Sphere0_ptr = Sphere0.clone();
	surfacePtr Sphere1_ptr = Sphere1.clone();
	surfacePtr Sphere2_ptr = Sphere2.clone();
	surfacePtr Aper3_ptr = AperStop3.clone();
	surfacePtr Sphere4_ptr = Sphere4.clone();
	surfacePtr Sphere5_ptr = Sphere5.clone();
	surfacePtr Sphere6_ptr = Sphere6.clone();
	surfacePtr Plan7_ptr = Plan7.clone();

	std::vector<surfacePtr> opticalSystemE10_ptr{ Sphere0_ptr, Sphere1_ptr, Sphere2_ptr , Aper3_ptr, Sphere4_ptr, Sphere5_ptr, Sphere6_ptr, Plan7_ptr };
	std::vector<interaction_ptr> interactionsE10_ptr{ refrac.clone(), refrac.clone(),refrac.clone(), doNothing.clone(), refrac.clone(), refrac.clone(),refrac.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE10_ptr, interactionsE10_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::obj);
	real startNA_objSpace = startCardinalPoints.getNA_objSpace();

	// check the start system
	std::vector<real> rmsStartSystem{ 1282.77 };
	std::vector<VectorStructR3> startFields{ {0.0,0.0,0.0} };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, startFields, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);


	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetNA_objSpace = 1;
	targetCarPoints.setTargetNA_obj(targetNA_objSpace);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*fields*/ startFields,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();


	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);



	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::obj);
	real optNA_objSpace = cardinalPointsOptimizedSystem.getNA_objSpace();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startNA_objSpace, /*optimized value*/ optNA_objSpace, /*target val*/ targetNA_objSpace);
	test_vec.push_back(checkOptCar);

	bool isNA_objSpace_target = targetCarPoints.isNA_obj_target();
	test_vec.push_back(isNA_objSpace_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

bool TestGenetic::testTargetNA_objSpace_inf()
{
	std::vector<bool> test_vec;

	// surfaces E20
	SphericalElement Sphere0_E20(/*radius*/ 100, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAK21_S1());
	SphericalElement Sphere1_E20(/*radius*/ 100, /*semi height*/7.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAK21_S1());
	SphericalElement Sphere2_E20(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLASF40_S1());
	SphericalElement Sphere3_E20(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNLASF40_S1(), /*refractive index B*/glasses.getAir());
	ApertureStopElement AperStop4_E20(/* semi height*/1.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere5_E20(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAF7_S1());
	SphericalElement Sphere6_E20(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAF7_S1());
	PlanElement Plan7_E20(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere1_E20.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere6_E20.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2_E20.setParameterPointZ(0.0, 20.0, 0.0, typeModifierVariable);


	surfacePtr Sphere0_E20_ptr = Sphere0_E20.clone();
	surfacePtr Sphere1_E20_ptr = Sphere1_E20.clone();
	surfacePtr Sphere2_E20_ptr = Sphere2_E20.clone();
	surfacePtr Sphere3_E20_ptr = Sphere3_E20.clone();
	surfacePtr Aper4_E20_ptr = AperStop4_E20.clone();
	surfacePtr Sphere5_E20_ptr = Sphere5_E20.clone();
	surfacePtr Sphere6_E20_ptr = Sphere6_E20.clone();
	surfacePtr Plan7_E20_ptr = Plan7_E20.clone();

	std::vector<surfacePtr> opticalSystemE20_ptr{ Sphere0_E20_ptr, Sphere1_E20_ptr, Sphere2_E20_ptr , Sphere3_E20_ptr, Aper4_E20_ptr,Sphere5_E20_ptr, Sphere6_E20_ptr,  Plan7_E20_ptr };
	std::vector<interaction_ptr> interactionsE20_ptr{ refrac.clone(), refrac.clone(),refrac.clone(), refrac.clone(),  doNothing.clone(),refrac.clone(),  refrac.clone(), absorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE20_ptr, interactionsE20_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::inf);
	real startNA_objSpace = startCardinalPoints.getNA_objSpace();

	// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> rmsStartSystem{ 156.585 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, anglesXvec, anglesYvec, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkTheSystem);

	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetNA_objSpace = 1.0;
	targetCarPoints.setTargetNA_obj(targetNA_objSpace);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*angleX*/ anglesXvec, /*angleY*/ anglesYvec,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();

	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);

	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::inf);
	real optNA_objSpace = cardinalPointsOptimizedSystem.getNA_objSpace();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startNA_objSpace, /*optimized value*/ optNA_objSpace, /*target val*/ targetNA_objSpace);
	test_vec.push_back(checkOptCar);

	bool isNA_objSpace_target = targetCarPoints.isNA_obj_target();
	test_vec.push_back(isNA_objSpace_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

//test target Mag
bool TestGenetic::testTargetMag_obj()
{
	std::vector<bool> test_vec;

	// surfaces E13
	SphericalElement Sphere0_E13(/*radius*/ 20.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAK22_S1());
	SphericalElement Sphere1_E13(/*radius*/ 100.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNLAK22_S1(), /*refractive index B*/glasses.getAir());
	ApertureStopElement AperStop2_E13(/* semi height*/5.0, /*point*/{ 0.0,0.0,30 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere3_E13(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6G05_S1());
	SphericalElement Sphere4_E13(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBAK1_S1(), /*refractive index B*/glasses.getSF6G05_S1());
	SphericalElement Sphere5_E13(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAK1_S1());
	PlanElement Plan6_E13(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());


	Sphere0_E13.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere3_E13.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere1_E13.setParameterPointZ(0.0, 40.0, 0.0, typeModifierVariable);


	surfacePtr Sphere0_E13_ptr = Sphere0_E13.clone();
	surfacePtr Sphere1_E13_ptr = Sphere1_E13.clone();
	surfacePtr Aper2_E13_ptr = AperStop2_E13.clone();
	surfacePtr Sphere3_E13_ptr = Sphere3_E13.clone();
	surfacePtr Sphere4_E13_ptr = Sphere4_E13.clone();
	surfacePtr Sphere5_E13_ptr = Sphere5_E13.clone();
	surfacePtr Plan6_E13_ptr = Plan6_E13.clone();

	std::vector<surfacePtr> opticalSystemE13_ptr{ Sphere0_E13_ptr, Sphere1_E13_ptr, Aper2_E13_ptr , Sphere3_E13_ptr ,  Sphere4_E13_ptr, Sphere5_E13_ptr,  Plan6_E13_ptr };
	std::vector<interaction_ptr> interactionsE13_ptr{ refrac.clone(), refrac.clone() , doNothing.clone(), refrac.clone(), refrac.clone() , refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE13_ptr, interactionsE13_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::obj);
	real startMag = startCardinalPoints.getMagnification();

	// check the start system
	std::vector<real> rmsStartSystem{ 2498.85 };
	std::vector<VectorStructR3> startFields{ {0.0,0.0,0.0} };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, startFields, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);


	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetMag = -3;
	targetCarPoints.setTargetMag(targetMag);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*fields*/ startFields,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();


	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);



	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::obj);
	real optMag = cardinalPointsOptimizedSystem.getMagnification();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startMag, /*optimized value*/ optMag, /*target val*/ targetMag);
	test_vec.push_back(checkOptCar);

	bool isMag_target = targetCarPoints.isMag_target();
	test_vec.push_back(isMag_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

bool TestGenetic::testTargetMag_inf()
{
	std::vector<bool> test_vec;

	// surfaces E18
	ApertureStopElement AperStop0_E18(/* semi height*/1.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E18(/*radius*/ 10.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,3.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF66_S1());
	SphericalElement Sphere2_E18(/*radius*/ 50.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,8.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF66_S1());
	SphericalElement Sphere3_E18(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,18.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7G18_S1());
	SphericalElement Sphere4_E18(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,23.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getK5G20_S1(), /*refractive index B*/glasses.getBK7G18_S1());
	PlanElement Plan5_E18(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,26.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getK5G20_S1(), /*refractive index B*/ glasses.getAir());
	PlanElement Plan6_E18(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,56.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere2_E18.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere4_E18.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Plan5_E18.setParameterPointZ(0.0, 60.0, 0.0, typeModifierVariable);


	surfacePtr Aper0_E18_ptr = AperStop0_E18.clone();
	surfacePtr Sphere1_E18_ptr = Sphere1_E18.clone();
	surfacePtr Sphere2_E18_ptr = Sphere2_E18.clone();
	surfacePtr Sphere3_E18_ptr = Sphere3_E18.clone();
	surfacePtr Sphere4_E18_ptr = Sphere4_E18.clone();
	surfacePtr Plan5_E18_ptr = Plan5_E18.clone();
	surfacePtr Plan6_E18_ptr = Plan6_E18.clone();

	std::vector<surfacePtr> opticalSystemE18_ptr{ Aper0_E18_ptr, Sphere1_E18_ptr, Sphere2_E18_ptr , Sphere3_E18_ptr, Sphere4_E18_ptr, Plan5_E18_ptr, Plan6_E18_ptr };
	std::vector<interaction_ptr> interactionsE18_ptr{ doNothing.clone(),refrac.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE18_ptr, interactionsE18_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::inf);
	real startMag = startCardinalPoints.getMagnification();

	// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> rmsStartSystem{ 2916.14 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, anglesXvec, anglesYvec, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkTheSystem);

	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetMag = 0.0;
	targetCarPoints.setTargetMag(targetMag);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*angleX*/ anglesXvec, /*angleY*/ anglesYvec,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();

	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);

	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::inf);
	real optMag = cardinalPointsOptimizedSystem.getMagnification();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startMag, /*optimized value*/ optMag, /*target val*/ targetMag);
	test_vec.push_back(checkOptCar);

	bool isMag_target = targetCarPoints.isMag_target();
	test_vec.push_back(isMag_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

//test target ENPP_firstSurface
bool TestGenetic::testTargetENPP_firstSurface_obj()
{
	std::vector<bool> test_vec;

	// surfaces E14
	ApertureStopElement AperStop0_E14(/* semi height*/1.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E14(/*radius*/ 10.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getPSK60_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere2_E14(/*radius*/ 10.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK5_S1(), /*refractive index B*/glasses.getPSK60_S1());
	SphericalElement Sphere3_E14(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF4_S1(), /*refractive index B*/glasses.getNSSK5_S1());
	SphericalElement Sphere4_E14(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNZK7_S1(), /*refractive index B*/glasses.getSF4_S1());
	SphericalElement Sphere5_E14(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNZK7_S1());
	PlanElement Plan6_E14(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere1_E14.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere4_E14.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere1_E14.setParameterPointZ(0.0, 40.0, 0.0, typeModifierVariable);


	surfacePtr Aper0_E14_ptr = AperStop0_E14.clone();
	surfacePtr Sphere1_E14_ptr = Sphere1_E14.clone();
	surfacePtr Sphere2_E14_ptr = Sphere2_E14.clone();
	surfacePtr Sphere3_E14_ptr = Sphere3_E14.clone();
	surfacePtr Sphere4_E14_ptr = Sphere4_E14.clone();
	surfacePtr Sphere5_E14_ptr = Sphere5_E14.clone();
	surfacePtr Plan6_E14_ptr = Plan6_E14.clone();

	std::vector<surfacePtr> opticalSystemE14_ptr{ Aper0_E14_ptr, Sphere1_E14_ptr, Sphere2_E14_ptr, Sphere3_E14_ptr , Sphere4_E14_ptr, Sphere5_E14_ptr,  Plan6_E14_ptr };
	std::vector<interaction_ptr> interactionsE14_ptr{ doNothing.clone(), refrac.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE14_ptr, interactionsE14_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::obj);
	real startENPP_firstSurface = startCardinalPoints.getENPP_firstSurface();

	// check the start system
	std::vector<real> rmsStartSystem{ 3910.71 };
	std::vector<VectorStructR3> startFields{ {0.0,0.0,0.0} };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, startFields, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);


	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetENPP_firstSurface = 1.0;
	targetCarPoints.setTargetENPP_firstSurface(targetENPP_firstSurface);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*fields*/ startFields,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();


	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);



	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::obj);
	real optENPP_firstSurface = cardinalPointsOptimizedSystem.getENPP_firstSurface();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startENPP_firstSurface, /*optimized value*/ optENPP_firstSurface, /*target val*/ targetENPP_firstSurface);
	test_vec.push_back(checkOptCar);

	bool isENPP_firstSurface_target = targetCarPoints.isENPP_firstSurface_target();
	test_vec.push_back(isENPP_firstSurface_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

bool TestGenetic::testTargetENPP_firstSurface_inf()
{
	std::vector<bool> test_vec;

	SphericalElement Sphere0_E19(/*radius*/ 70, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getLAKL12_S1());
	SphericalElement Sphere1_E19(/*radius*/ 20, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getLAKL12_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2_E19(/*radius*/ 100, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	ApertureStopElement AperStop3_E19(/* semi height*/3, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere4_E19(/*radius*/ 10, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getFK3_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere5_E19(/*radius*/ 10, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF1_S1(), /*refractive index B*/glasses.getFK3_S1());
	SphericalElement Sphere6_E19(/*radius*/ 100, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF1_S1());
	PlanElement Plan7_E19(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,110.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere4_E19.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere5_E19.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere6_E19.setParameterPointZ(0.0, 100.0, 0.0, typeModifierVariable);


	surfacePtr Sphere0_E19_ptr = Sphere0_E19.clone();
	surfacePtr Sphere1_E19_ptr = Sphere1_E19.clone();
	surfacePtr Sphere2_E19_ptr = Sphere2_E19.clone();
	surfacePtr Aper3_E19_ptr = AperStop3_E19.clone();
	surfacePtr Sphere4_E19_ptr = Sphere4_E19.clone();
	surfacePtr Sphere5_E19_ptr = Sphere5_E19.clone();
	surfacePtr Sphere6_E19_ptr = Sphere6_E19.clone();
	surfacePtr Plan7_E19_ptr = Plan7_E19.clone();

	std::vector<surfacePtr> opticalSystemE19_ptr{ Sphere0_E19_ptr, Sphere1_E19_ptr, Sphere2_E19_ptr, Aper3_E19_ptr, Sphere4_E19_ptr, Sphere5_E19_ptr, Sphere6_E19_ptr,Plan7_E19_ptr };
	std::vector<interaction_ptr> interactionsE19_ptr{ refrac.clone(), refrac.clone(),refrac.clone(), doNothing.clone(), refrac.clone(),  refrac.clone(),refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE19_ptr, interactionsE19_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::inf);
	real startENPP_firstSurface = startCardinalPoints.getENPP_firstSurface();

	// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> rmsStartSystem{ 5255.28 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, anglesXvec, anglesYvec, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkTheSystem);

	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetENPP_firstSurface = 100;
	targetCarPoints.setTargetENPP_firstSurface(targetENPP_firstSurface);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*angleX*/ anglesXvec, /*angleY*/ anglesYvec,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();

	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);

	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::inf);
	real optENPP_firstSurface = cardinalPointsOptimizedSystem.getENPP_firstSurface();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startENPP_firstSurface, /*optimized value*/ optENPP_firstSurface, /*target val*/ targetENPP_firstSurface);
	test_vec.push_back(checkOptCar);

	bool isENPP_firstSurface_target = targetCarPoints.isENPP_firstSurface_target();
	test_vec.push_back(isENPP_firstSurface_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

//test target ENPP_global
bool TestGenetic::testTargetENPP_global_obj()
{
	std::vector<bool> test_vec;

	// surfaces E11
	SphericalElement Sphere0(/*radius*/ 20.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAK4_S1());
	SphericalElement Sphere1(/*radius*/ 30.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAK4_S1());
	SphericalElement Sphere2(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF66_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere3(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF66_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere4(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getLLF1_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere5(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getLLF1_S1());
	ApertureStopElement AperStop6(/* semi height*/1.0, /*point*/{ 0.0,0.0,140 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan7(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,150.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere1.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere3.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere3.setParameterPointZ(0.0, 40.0, 0.0, typeModifierVariable);

	surfacePtr Sphere0_ptr = Sphere0.clone();
	surfacePtr Sphere1_ptr = Sphere1.clone();
	surfacePtr Sphere2_ptr = Sphere2.clone();
	surfacePtr Sphere3_ptr = Sphere3.clone();
	surfacePtr Sphere4_ptr = Sphere4.clone();
	surfacePtr Sphere5_ptr = Sphere5.clone();
	surfacePtr Aper6_ptr = AperStop6.clone();
	surfacePtr Plan7_ptr = Plan7.clone();

	std::vector<surfacePtr> opticalSystemE11_ptr{ Sphere0_ptr, Sphere1_ptr, Sphere2_ptr , Sphere3_ptr , Sphere4_ptr , Sphere5_ptr , Aper6_ptr, Plan7_ptr };
	std::vector<interaction_ptr> interactionsE11_ptr{ refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone() , refrac.clone() , refrac.clone() ,doNothing.clone() , absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE11_ptr, interactionsE11_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::obj);
	real startENPP_global = startCardinalPoints.getENPP_globalCoodi();

	// check the start system
	std::vector<real> rmsStartSystem{ 626.82 };
	std::vector<VectorStructR3> startFields{ {0.0,0.0,0.0} };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, startFields, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);


	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetENPP_global = 250;
	targetCarPoints.setTargetENPP_globalCoori(targetENPP_global);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*fields*/ startFields,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();


	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);



	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::obj);
	real optENPP_global = cardinalPointsOptimizedSystem.getENPP_globalCoodi();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startENPP_global, /*optimized value*/ optENPP_global, /*target val*/ targetENPP_global);
	test_vec.push_back(checkOptCar);

	bool isENPP_global_target = targetCarPoints.isENPP_globalCoodi_target();
	test_vec.push_back(isENPP_global_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

bool TestGenetic::testTargetENPP_global_inf()
{
	std::vector<bool> test_vec;

	// surfaces E21
	SphericalElement Sphere0_E21(/*radius*/ 10, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getPLAF37_S1());
	SphericalElement Sphere1_E21(/*radius*/ 10, /*semi height*/7.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getPLAF37_S1(), /*refractive index B*/glasses.getAir());
	ApertureStopElement AperStop2_E21(/* semi height*/2.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere3_E21(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSK4_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere4_E21(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNSK4_S1(), /*refractive index B*/glasses.getSF1_S1());
	SphericalElement Sphere5_E21(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getPSK60_S1(), /*refractive index B*/glasses.getSF1_S1());
	SphericalElement Sphere6_E21(/*radius*/ 5.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getPSK60_S1());
	PlanElement Plan7_E21(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere1_E21.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere3_E21.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere6_E21.setParameterPointZ(0.0, 70.0, 0.0, typeModifierVariable);


	surfacePtr Sphere0_E21_ptr = Sphere0_E21.clone();
	surfacePtr Sphere1_E21_ptr = Sphere1_E21.clone();
	surfacePtr Aper2_E21_ptr = AperStop2_E21.clone();
	surfacePtr Sphere3_E21_ptr = Sphere3_E21.clone();
	surfacePtr Sphere4_E21_ptr = Sphere4_E21.clone();
	surfacePtr Sphere5_E21_ptr = Sphere5_E21.clone();
	surfacePtr Sphere6_E21_ptr = Sphere6_E21.clone();
	surfacePtr Plan7_E21_ptr = Plan7_E21.clone();

	std::vector<surfacePtr> opticalSystemE21_ptr{ Sphere0_E21_ptr, Sphere1_E21_ptr,  Aper2_E21_ptr, Sphere3_E21_ptr, Sphere4_E21_ptr,Sphere5_E21_ptr, Sphere6_E21_ptr, Plan7_E21_ptr };
	std::vector<interaction_ptr> interactionsE21_ptr{ refrac.clone(), refrac.clone(),doNothing.clone(),refrac.clone(),refrac.clone(), refrac.clone() ,refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE21_ptr, interactionsE21_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::inf);
	real startENPP_global = startCardinalPoints.getENPP_globalCoodi();

	// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> rmsStartSystem{ 817.341 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, anglesXvec, anglesYvec, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkTheSystem);

	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetENPP_global = 15.0;
	targetCarPoints.setTargetENPP_globalCoori(targetENPP_global);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*angleX*/ anglesXvec, /*angleY*/ anglesYvec,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();

	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);

	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::inf);
	real optENPP_global = cardinalPointsOptimizedSystem.getENPP_globalCoodi();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startENPP_global, /*optimized value*/ optENPP_global, /*target val*/ targetENPP_global);
	test_vec.push_back(checkOptCar);

	bool isENPP_global_target = targetCarPoints.isENPP_globalCoodi_target();
	test_vec.push_back(isENPP_global_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}


//test target ENPD 
bool TestGenetic::testTargetENPD_obj()
{
	std::vector<bool> test_vec;

	// surfaces E15
	SphericalElement Sphere0_E15(/*radius*/ 20.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSFL57_S1());
	SphericalElement Sphere1_E15(/*radius*/ 20.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getF2G12_S1(), /*refractive index B*/glasses.getSFL57_S1());
	SphericalElement Sphere2_E15(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getLASFN9_S1(), /*refractive index B*/glasses.getF2G12_S1());
	SphericalElement Sphere3_E15(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getLASFN9_S1(), /*refractive index B*/glasses.getAir());
	ApertureStopElement AperStop4_E15(/* semi height*/1.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere5_E15(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF11_S1());
	SphericalElement Sphere6_E15(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF11_S1(), /*refractive index B*/glasses.getAir());
	PlanElement Plan7_E15(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere0_E15.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere5_E15.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere0_E15.setParameterPointZ(0.0, 30.0, 0.0, typeModifierVariable);


	surfacePtr Sphere0_E15_ptr = Sphere0_E15.clone();
	surfacePtr Sphere1_E15_ptr = Sphere1_E15.clone();
	surfacePtr Sphere2_E15_ptr = Sphere2_E15.clone();
	surfacePtr Sphere3_E15_ptr = Sphere3_E15.clone();
	surfacePtr Aper4_E15_ptr = AperStop4_E15.clone();
	surfacePtr Sphere5_E15_ptr = Sphere5_E15.clone();
	surfacePtr Sphere6_E15_ptr = Sphere6_E15.clone();
	surfacePtr Plan7_E15_ptr = Plan7_E15.clone();

	std::vector<surfacePtr> opticalSystemE15_ptr{ Sphere0_E15_ptr, Sphere1_E15_ptr, Sphere2_E15_ptr , Sphere3_E15_ptr,  Aper4_E15_ptr, Sphere5_E15_ptr, Sphere6_E15_ptr, Plan7_E15_ptr };
	std::vector<interaction_ptr> interactionsE15_ptr{ refrac.clone(), refrac.clone(),refrac.clone(),  refrac.clone(), doNothing.clone(), refrac.clone(),refrac.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE15_ptr, interactionsE15_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::obj);
	real startENPD = startCardinalPoints.getENPD();

	// check the start system
	std::vector<real> rmsStartSystem{ 2992.53 };
	std::vector<VectorStructR3> startFields{ {0.0,0.0,0.0} };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, startFields, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);

	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetENPD = 10.0;
	targetCarPoints.setTargetENPD(targetENPD);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*fields*/ startFields,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();

	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);

	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::obj);
	real optENPD = cardinalPointsOptimizedSystem.getENPD();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startENPD, /*optimized value*/ optENPD, /*target val*/ targetENPD);
	test_vec.push_back(checkOptCar);

	bool isENPD_target = targetCarPoints.isENPD_target();
	test_vec.push_back(isENPD_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

bool TestGenetic::testTargetENPD_inf()
{
	std::vector<bool> test_vec;

	// surfaces E20
	SphericalElement Sphere0_E20(/*radius*/ 100, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAK21_S1());
	SphericalElement Sphere1_E20(/*radius*/ 100, /*semi height*/7.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAK21_S1());
	SphericalElement Sphere2_E20(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLASF40_S1());
	SphericalElement Sphere3_E20(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNLASF40_S1(), /*refractive index B*/glasses.getAir());
	ApertureStopElement AperStop4_E20(/* semi height*/1.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere5_E20(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAF7_S1());
	SphericalElement Sphere6_E20(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAF7_S1());
	PlanElement Plan7_E20(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere1_E20.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere6_E20.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere1_E20.setParameterPointZ(0.0, 70.0, 0.0, typeModifierVariable);


	surfacePtr Sphere0_E20_ptr = Sphere0_E20.clone();
	surfacePtr Sphere1_E20_ptr = Sphere1_E20.clone();
	surfacePtr Sphere2_E20_ptr = Sphere2_E20.clone();
	surfacePtr Sphere3_E20_ptr = Sphere3_E20.clone();
	surfacePtr Aper4_E20_ptr = AperStop4_E20.clone();
	surfacePtr Sphere5_E20_ptr = Sphere5_E20.clone();
	surfacePtr Sphere6_E20_ptr = Sphere6_E20.clone();
	surfacePtr Plan7_E20_ptr = Plan7_E20.clone();

	std::vector<surfacePtr> opticalSystemE20_ptr{ Sphere0_E20_ptr, Sphere1_E20_ptr, Sphere2_E20_ptr , Sphere3_E20_ptr, Aper4_E20_ptr,Sphere5_E20_ptr, Sphere6_E20_ptr,  Plan7_E20_ptr };
	std::vector<interaction_ptr> interactionsE20_ptr{ refrac.clone(), refrac.clone(),refrac.clone(), refrac.clone(),  doNothing.clone(),refrac.clone(),  refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE20_ptr, interactionsE20_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::inf);
	real startENPD = startCardinalPoints.getENPD();

	// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> rmsStartSystem{ 156.585 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, anglesXvec, anglesYvec, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkTheSystem);

	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetENPD = 5.0;
	targetCarPoints.setTargetENPD(targetENPD);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*angleX*/ anglesXvec, /*angleY*/ anglesYvec,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();

	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);

	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::inf);
	real optENPD = cardinalPointsOptimizedSystem.getENPD();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startENPD, /*optimized value*/ optENPD, /*target val*/ targetENPD);
	test_vec.push_back(checkOptCar);

	bool isENPD_target = targetCarPoints.isENPD_target();
	test_vec.push_back(isENPD_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

//test target f_number_imaSpace
bool TestGenetic::testTargetf_number_imaSpace_obj()
{
	std::vector<bool> test_vec;

	// surfaces E13
	SphericalElement Sphere0_E13(/*radius*/ 20.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAK22_S1());
	SphericalElement Sphere1_E13(/*radius*/ 100.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNLAK22_S1(), /*refractive index B*/glasses.getAir());
	ApertureStopElement AperStop2_E13(/* semi height*/5.0, /*point*/{ 0.0,0.0,30 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere3_E13(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6G05_S1());
	SphericalElement Sphere4_E13(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBAK1_S1(), /*refractive index B*/glasses.getSF6G05_S1());
	SphericalElement Sphere5_E13(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAK1_S1());
	PlanElement Plan6_E13(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere5_E13.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere0_E13.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere0_E13.setParameterPointZ(0.0, 30.0, 0.0, typeModifierVariable);

	surfacePtr Sphere0_E13_ptr = Sphere0_E13.clone();
	surfacePtr Sphere1_E13_ptr = Sphere1_E13.clone();
	surfacePtr Aper2_E13_ptr = AperStop2_E13.clone();
	surfacePtr Sphere3_E13_ptr = Sphere3_E13.clone();
	surfacePtr Sphere4_E13_ptr = Sphere4_E13.clone();
	surfacePtr Sphere5_E13_ptr = Sphere5_E13.clone();
	surfacePtr Plan6_E13_ptr = Plan6_E13.clone();

	std::vector<surfacePtr> opticalSystemE13_ptr{ Sphere0_E13_ptr, Sphere1_E13_ptr, Aper2_E13_ptr , Sphere3_E13_ptr ,  Sphere4_E13_ptr, Sphere5_E13_ptr,  Plan6_E13_ptr };
	std::vector<interaction_ptr> interactionsE13_ptr{ refrac.clone(), refrac.clone() , doNothing.clone(), refrac.clone(), refrac.clone() , refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE13_ptr, interactionsE13_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::obj);
	real startf_number_imaSpace = startCardinalPoints.getF_num_imaSpace();

	// check the start system
	std::vector<real> rmsStartSystem{ 2498.85 };
	std::vector<VectorStructR3> startFields{ {0.0,0.0,0.0} };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, startFields, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);


	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetf_number_imaSpace = 2.0;
	targetCarPoints.setTargetFnum(targetf_number_imaSpace);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*fields*/ startFields,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();


	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);



	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::obj);
	real optf_number_imaSpace = cardinalPointsOptimizedSystem.getF_num_imaSpace();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startf_number_imaSpace, /*optimized value*/ optf_number_imaSpace, /*target val*/ targetf_number_imaSpace);
	test_vec.push_back(checkOptCar);

	bool isf_number_imaSpace_target = targetCarPoints.isF_num_target();
	test_vec.push_back(isf_number_imaSpace_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

bool TestGenetic::testTargetf_number_imaSpace_inf()
{
	std::vector<bool> test_vec;

	// surfaces E22
	SphericalElement Sphere0_E22(/*radius*/ 100, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF66_S1());
	SphericalElement Sphere1_E22(/*radius*/ 70, /*semi height*/7.0, /*point*/{ 0.0,0.0,3.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getF2G12_S1(), /*refractive index B*/glasses.getSF66_S1());
	PlanElement Plan2_E22(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,6.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getF2G12_S1(), /*refractive index B*/ glasses.getAir());
	ApertureStopElement AperStop3_E22(/* semi height*/3.0, /*point*/{ 0.0,0.0,16.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan4_E22(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,41.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getPPK53_S1());
	SphericalElement Sphere5_E22(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,43.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getPPK53_S1(), /*refractive index B*/glasses.getNSF19_S1());
	SphericalElement Sphere6_E22(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF19_S1());
	PlanElement Plan7_E22(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,75.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere0_E22.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere5_E22.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere5_E22.setParameterPointZ(0.0, 70.0, 0.0, typeModifierVariable);


	surfacePtr Sphere0_E22_ptr = Sphere0_E22.clone();
	surfacePtr Sphere1_E22_ptr = Sphere1_E22.clone();
	surfacePtr Plan2_E22_ptr = Plan2_E22.clone();
	surfacePtr Aper3_E22_ptr = AperStop3_E22.clone();
	surfacePtr Plan4_E22_ptr = Plan4_E22.clone();
	surfacePtr Sphere5_E22_ptr = Sphere5_E22.clone();
	surfacePtr Sphere6_E22_ptr = Sphere6_E22.clone();
	surfacePtr Plan7_E22_ptr = Plan7_E22.clone();

	std::vector<surfacePtr> opticalSystemE22_ptr{ Sphere0_E22_ptr, Sphere1_E22_ptr,  Plan2_E22_ptr ,Aper3_E22_ptr, Plan4_E22_ptr , Sphere5_E22_ptr, Sphere6_E22_ptr,  Plan7_E22_ptr };
	std::vector<interaction_ptr> interactionsE22_ptr{ refrac.clone(), refrac.clone(),refrac.clone(),doNothing.clone(),refrac.clone(), refrac.clone() ,refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE22_ptr, interactionsE22_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::inf);
	real startf_number_imaSpace = startCardinalPoints.getF_num_imaSpace();

	// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> rmsStartSystem{ 339.154 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, anglesXvec, anglesYvec, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkTheSystem);

	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetf_number_imaSpace = 10.0;
	targetCarPoints.setTargetFnum(targetf_number_imaSpace);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*angleX*/ anglesXvec, /*angleY*/ anglesYvec,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();

	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);

	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::inf);
	real optf_number_imaSpace = cardinalPointsOptimizedSystem.getF_num_imaSpace();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startf_number_imaSpace, /*optimized value*/ optf_number_imaSpace, /*target val*/ targetf_number_imaSpace);
	test_vec.push_back(checkOptCar);

	bool isf_number_imaSpace_target = targetCarPoints.isF_num_target();
	test_vec.push_back(isf_number_imaSpace_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

//test target NA_imaSpace
bool TestGenetic::testTargetNA_imaSpace_obj()
{
	std::vector<bool> test_vec;

	// surfaces E13
	SphericalElement Sphere0_E13(/*radius*/ 20.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAK22_S1());
	SphericalElement Sphere1_E13(/*radius*/ 100.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNLAK22_S1(), /*refractive index B*/glasses.getAir());
	ApertureStopElement AperStop2_E13(/* semi height*/5.0, /*point*/{ 0.0,0.0,30 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere3_E13(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6G05_S1());
	SphericalElement Sphere4_E13(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBAK1_S1(), /*refractive index B*/glasses.getSF6G05_S1());
	SphericalElement Sphere5_E13(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAK1_S1());
	PlanElement Plan6_E13(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere0_E13.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere5_E13.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere1_E13.setParameterPointZ(0.0, 40.0, 0.0, typeModifierVariable);


	surfacePtr Sphere0_E13_ptr = Sphere0_E13.clone();
	surfacePtr Sphere1_E13_ptr = Sphere1_E13.clone();
	surfacePtr Aper2_E13_ptr = AperStop2_E13.clone();
	surfacePtr Sphere3_E13_ptr = Sphere3_E13.clone();
	surfacePtr Sphere4_E13_ptr = Sphere4_E13.clone();
	surfacePtr Sphere5_E13_ptr = Sphere5_E13.clone();
	surfacePtr Plan6_E13_ptr = Plan6_E13.clone();

	std::vector<surfacePtr> opticalSystemE13_ptr{ Sphere0_E13_ptr, Sphere1_E13_ptr, Aper2_E13_ptr , Sphere3_E13_ptr ,  Sphere4_E13_ptr, Sphere5_E13_ptr,  Plan6_E13_ptr };
	std::vector<interaction_ptr> interactionsE13_ptr{ refrac.clone(), refrac.clone() , doNothing.clone(), refrac.clone(), refrac.clone() , refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE13_ptr, interactionsE13_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::inf);
	real startNA_imaSpace = startCardinalPoints.getNA_imaSpace();

	// check the start system
	std::vector<VectorStructR3> fieldPoint_0_vec(1);
	fieldPoint_0_vec[0] = { 0.0,0.0,0.0 };
	std::vector<real> wavelenght_vec(1);
	wavelenght_vec[0] = mWave550_vec[0];
	std::vector<real> rmsStartSystem{ 2498.85 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, fieldPoint_0_vec, wavelenght_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkTheSystem);
	

	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetNA_imaSpace = 1.0;
	targetCarPoints.setTargetNA_imaSpace(targetNA_imaSpace);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*field 0*/ fieldPoint_0_vec, /*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();

	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);

	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::inf);
	real optNA_imaSpace = cardinalPointsOptimizedSystem.getNA_imaSpace();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startNA_imaSpace, /*optimized value*/ optNA_imaSpace, /*target val*/ targetNA_imaSpace);
	test_vec.push_back(checkOptCar);

	bool isNA_imaSpace_target = targetCarPoints.isNA_imaSpace();
	test_vec.push_back(isNA_imaSpace_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

bool TestGenetic::testTargetNA_imaSpace_inf()
{
	std::vector<bool> test_vec;

	// surfaces E23
	ApertureStopElement AperStop0_E23(/* semi height*/1.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E23(/*radius*/ 200, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getLF5_S1());
	SphericalElement Sphere2_E23(/*radius*/ 5, /*semi height*/7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK10_S1(), /*refractive index B*/glasses.getLF5_S1());
	SphericalElement Sphere3_E23(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBAK4_S1(), /*refractive index B*/glasses.getNBK10_S1());
	SphericalElement Sphere4_E23(/*radius*/ 3.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBAK4_S1(), /*refractive index B*/glasses.getLLF1_S1());
	SphericalElement Sphere5_E23(/*radius*/ 4.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getLLF1_S1());
	PlanElement Plan6_E23(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,90.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere1_E23.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2_E23.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere2_E23.setParameterPointZ(0.0, 70.0, 0.0, typeModifierVariable);


	surfacePtr Aper0_E23_ptr = AperStop0_E23.clone();
	surfacePtr Sphere1_E23_ptr = Sphere1_E23.clone();
	surfacePtr Sphere2_E23_ptr = Sphere2_E23.clone();
	surfacePtr Sphere3_E23_ptr = Sphere3_E23.clone();
	surfacePtr Sphere4_E23_ptr = Sphere4_E23.clone();
	surfacePtr Sphere5_E23_ptr = Sphere5_E23.clone();
	surfacePtr Plan6_E23_ptr = Plan6_E23.clone();

	std::vector<surfacePtr> opticalSystemE23_ptr{ Aper0_E23_ptr,Sphere1_E23_ptr, Sphere2_E23_ptr, Sphere3_E23_ptr, Sphere4_E23_ptr,  Sphere5_E23_ptr, Plan6_E23_ptr };
	std::vector<interaction_ptr> interactionsE23_ptr{ doNothing.clone(),refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(), refrac.clone() ,absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE23_ptr, interactionsE23_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::inf);
	real startNA_imaSpace = startCardinalPoints.getNA_imaSpace();

	// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> rmsStartSystem{ 10.693 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, anglesXvec, anglesYvec, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkTheSystem);

	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetNA_imaSpace = 1.0;
	targetCarPoints.setTargetNA_imaSpace(targetNA_imaSpace);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*angleX*/ anglesXvec, /*angleY*/ anglesYvec,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();

	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);

	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::inf);
	real optNA_imaSpace = cardinalPointsOptimizedSystem.getNA_imaSpace();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startNA_imaSpace, /*optimized value*/ optNA_imaSpace, /*target val*/ targetNA_imaSpace);
	test_vec.push_back(checkOptCar);

	bool isNA_imaSpace_target = targetCarPoints.isNA_imaSpace();
	test_vec.push_back(isNA_imaSpace_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

//test target WFNO
bool TestGenetic::testTargetWFNO_obj()
{
	std::vector<bool> test_vec;

	// surfaces E14
	ApertureStopElement AperStop0_E14(/* semi height*/1.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E14(/*radius*/ 10.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getPSK60_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere2_E14(/*radius*/ 10.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK5_S1(), /*refractive index B*/glasses.getPSK60_S1());
	SphericalElement Sphere3_E14(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF4_S1(), /*refractive index B*/glasses.getNSSK5_S1());
	SphericalElement Sphere4_E14(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNZK7_S1(), /*refractive index B*/glasses.getSF4_S1());
	SphericalElement Sphere5_E14(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNZK7_S1());
	PlanElement Plan6_E14(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere1_E14.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere4_E14.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere1_E14.setParameterPointZ(0.0, 40.0, 0.0, typeModifierVariable);


	surfacePtr Aper0_E14_ptr = AperStop0_E14.clone();
	surfacePtr Sphere1_E14_ptr = Sphere1_E14.clone();
	surfacePtr Sphere2_E14_ptr = Sphere2_E14.clone();
	surfacePtr Sphere3_E14_ptr = Sphere3_E14.clone();
	surfacePtr Sphere4_E14_ptr = Sphere4_E14.clone();
	surfacePtr Sphere5_E14_ptr = Sphere5_E14.clone();
	surfacePtr Plan6_E14_ptr = Plan6_E14.clone();

	std::vector<surfacePtr> opticalSystemE14_ptr{ Aper0_E14_ptr, Sphere1_E14_ptr, Sphere2_E14_ptr, Sphere3_E14_ptr , Sphere4_E14_ptr, Sphere5_E14_ptr,  Plan6_E14_ptr };
	std::vector<interaction_ptr> interactionsE14_ptr{ doNothing.clone(), refrac.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE14_ptr, interactionsE14_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::obj);
	real startWFNO = startCardinalPoints.getWorkingFnumber();

	// check the start system
	std::vector<real> rmsStartSystem{ 3910.71 };
	std::vector<VectorStructR3> startFields{ {0.0,0.0,0.0} };
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, startFields, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkStartSys);


	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetWFNO = 10.0;
	targetCarPoints.setTargetWFNO(targetWFNO);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*fields*/ startFields,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();


	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);



	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::obj);
	real optWFNO = cardinalPointsOptimizedSystem.getWorkingFnumber();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startWFNO, /*optimized value*/ optWFNO, /*target val*/ targetWFNO);
	test_vec.push_back(checkOptCar);

	bool isWFNO_target = targetCarPoints.isTargetWFNO();
	test_vec.push_back(isWFNO_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

bool TestGenetic::testTargetWFNO_inf()
{
	std::vector<bool> test_vec;


	// surfaces E24
	SphericalElement Sphere0_E24(/*radius*/ 250, /*semi height*/ 50.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLASF45_S1());
	SphericalElement Sphere1_E24(/*radius*/ 250, /*semi height*/50.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLASF45_S1());
	SphericalElement Sphere2_E24(/*radius*/ 150.00, /*semi height*/ 50.0, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNPSK3_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere3_E24(/*radius*/ 100.00, /*semi height*/ 50.0, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNPSK3_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere4_E24(/*radius*/ 60.00, /*semi height*/ 50, /*point*/{ 0.0,0.0,280.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF1_S1());
	SphericalElement Sphere5_E24(/*radius*/ 100.00, /*semi height*/ 50, /*point*/{ 0.0,0.0,315.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNSF1_S1(), /*refractive index B*/glasses.getAir());
	ApertureStopElement AperStop6_E24(/* semi height*/10.0, /*point*/{ 0.0,0.0,390.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan7_E24(/*semi height*/ 50.0, /*point*/{ 0.0,0.0,410.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere4_E24.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere5_E24.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere4_E24.setParameterPointZ(0.0, 300.0, 0.0, typeModifierVariable);


	surfacePtr Sphere0_E24_ptr = Sphere0_E24.clone();
	surfacePtr Sphere1_E24_ptr = Sphere1_E24.clone();
	surfacePtr Sphere2_E24_ptr = Sphere2_E24.clone();
	surfacePtr Sphere3_E24_ptr = Sphere3_E24.clone();
	surfacePtr Sphere4_E24_ptr = Sphere4_E24.clone();
	surfacePtr Sphere5_E24_ptr = Sphere5_E24.clone();
	surfacePtr Aper6_E24_ptr = AperStop6_E24.clone();
	surfacePtr Plan7_E24_ptr = Plan7_E24.clone();

	std::vector<surfacePtr> opticalSystemE24_ptr{ Sphere0_E24_ptr,Sphere1_E24_ptr, Sphere2_E24_ptr, Sphere3_E24_ptr, Sphere4_E24_ptr,  Sphere5_E24_ptr,Aper6_E24_ptr, Plan7_E24_ptr };
	std::vector<interaction_ptr> interactionsE24_ptr{ refrac.clone(),  refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(), refrac.clone() ,doNothing.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE24_ptr, interactionsE24_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(mWave550_vec[0]);

	std::cout << "" << std::endl;
	std::cout << "start system" << std::endl;
	oftenUse::print(optSystemElement, mWave550_vec[0]);

	// calculate start cardinal points
	CardinalPoints startCardinalPoints(optSystemElement, mWave550_vec[0], objectPoint_inf_obj::inf);
	real startWFNO = startCardinalPoints.getWorkingFnumber();

	// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> rmsStartSystem{ 8351.81 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, anglesXvec, anglesYvec, mWave550_vec, rmsStartSystem, mTolerance_RMS, compareTOM_Zemax::comEqual);
	test_vec.push_back(checkTheSystem);

	// ***
	targetCardinalPointsStruct targetCarPoints;
	real targetWFNO = 10.0;
	targetCarPoints.setTargetWFNO(targetWFNO);
	// ***

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement, /*angleX*/ anglesXvec, /*angleY*/ anglesYvec,/*wavelengths*/ mWave550_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 1000);
	genetic.set_OFF_CheckRMS_rayTracing();
	genetic.setTargetCardinalPoints(targetCarPoints);
	genetic.doTheGeneticProcess();

	// optimized optical system
	OpticalSystemElement optimizedSystem = genetic.getOptimizedOpticalSystemElement();
	std::cout << "" << std::endl;
	std::cout << "optimized system" << std::endl;
	oftenUse::print(optimizedSystem, mWave550_vec[0]);

	CardinalPoints cardinalPointsOptimizedSystem(optimizedSystem, mWave550_vec[0], objectPoint_inf_obj::inf);
	real optWFNO = cardinalPointsOptimizedSystem.getWorkingFnumber();

	bool checkOptCar = oftenUse::optimizedTargetBetterThanStartCardinalPoint(/*start value*/ startWFNO, /*optimized value*/ optWFNO, /*target val*/ targetWFNO);
	test_vec.push_back(checkOptCar);

	bool isWFNO_target = targetCarPoints.isTargetWFNO();
	test_vec.push_back(isWFNO_target);


	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}
