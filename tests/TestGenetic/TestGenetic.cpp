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

#include "..\..\Inport_Export_Data\Inport_Export_Data.h"

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
	mWavelength_vec = { mWave587 , mWave486, mWave656 };

	// field
	mField0 = { 0.0,0.0,0.0 };
	mField1 = { 0.0,1.0,0.0 };
	mField2 = { 0.0,2.0,0.0 };
	mField3 = { 0.0,3.0,0.0 };
	mField4 = { 0.0,4.0,0.0 };
	mFields_vec012 = { mField0, mField1, mField2 };
	mFields_vec024 = { mField0, mField2, mField4 };

	mTolerance = 0.1;

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
	bool test_E0 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E0, fields_vec_optA, wavelenth_vec_550, rms_Zemax, 1.0, comEqual);
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
	bool test_E1 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E1, fields_vec_optA, wavelenth_vec_550, rms_Zemax, 1.0, comEqual);
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
	bool test_E2 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E2, fields_vec_optA, wavelenth_vec_550, rms_Zemax, 1.0, comEqual);
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
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E3, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	test_vec.push_back(checkStartSys);

	// genetic
	Genetic genetic(/*optSysEle*/ optSysEle_E3, /*fields*/ mFields_vec012,/*wavelengths*/ mWavelength_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 5000);
	genetic.doTheGeneticProcess();

	OpticalSystemElement optimizedOpticalSystem = genetic.getOptimizedOpticalSystemElement();
	oftenUse::print(optimizedOpticalSystem, mWavelength_vec[0]);

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
	bool checkStartSys = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E4, mFields_vec012, mWavelength_vec, rmsStartSystem_Z, mTolerance, comEqual);
	test_vec.push_back(checkStartSys);

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement_E4, /*fields*/ mFields_vec012,/*wavelengths*/ mWavelength_vec, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/ 5000);
	genetic.doTheGeneticProcess();

	std::vector<real> bestValues{ 9.21487,-14.09026,9.2527 };
	test_vec.push_back(oftenUse::checkDeltaVariables(genetic.getOptimizedOpticalSystemElement(), bestValues, 300.0));

	// print the optimized system
	oftenUse::print(genetic.getOptimizedOpticalSystemElement(), mWavelength_vec[0]);

	bool checker = Math::checkTrueOfVectorElements(test_vec);
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