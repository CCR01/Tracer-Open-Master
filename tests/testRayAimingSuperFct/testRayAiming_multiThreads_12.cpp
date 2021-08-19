#include "testRayAiming_multiThreads_12.h"

// element surfaces
#include "..\..\SurfaceElements\ApertureStopElement.h"
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\PlanElement.h"

// often use
#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

// ray Aiming super function 12 cores
#include "..\..\RayAiming\RayAimingSuperFct.h"

testRayAiming_multiThreads_12::testRayAiming_multiThreads_12() 
{ 
	loadImportantStuff();
}

testRayAiming_multiThreads_12::~testRayAiming_multiThreads_12() {}

// load important stuff
void testRayAiming_multiThreads_12::loadImportantStuff()
{
	mDefaulRayAiming.setTolerance_XandY(0.0001);
	mDefaulRayAiming.setStartPointFactor(1.0);
	mDefaulRayAiming.setMaxLoopsTraceToLastSurface(5);
	mDefaulRayAiming.setMaxIterationsRayAiming(50);
	mDefaulRayAiming.setFactor_inf(0.9);
	mDefaulRayAiming.setFactor_obj(0.1);
	mDefaulRayAiming.turn_On_RobustRayAiming();
	mDefaulRayAiming.setVariancePercentRRA(5.0);
	mDefaulRayAiming.setMaxStayCounter(2);
	mDefaulRayAiming.setIncreaserFactorTimes(10.0);


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

	startOptA_vec.push_back(mField0);

	mRings = 6;
	mArms = 8;

	mLight587.setWavelength(mWave587);
	mLight587.setTypeLight(typeLight::typeLightRay);
	mLight587.setJonesVector({ 1.0,1.0,1.0,1.0 });
	mLight587.setIntensity(1.0);

	mStartRefIndexAir = 1.0;
}

bool testRayAiming_multiThreads_12::testRayAiming_multiThreads_12_superFct_obj()
{
	std::vector<bool> checkRayAiming_multiThreads_12;

	// E0 obj
	bool checkE0_obj = testRayAiming_multiThreads_12_E0_obj();
	checkRayAiming_multiThreads_12.push_back(checkE0_obj);


	bool returnChecker = Math::checkTrueOfVectorElements(checkRayAiming_multiThreads_12);
	return returnChecker;
}

bool testRayAiming_multiThreads_12::testRayAiming_multiThreads_12_E0_obj()
{
	std::vector<bool> checkRayAiming_E0_vec;

	// TestSystem00 ///////////////////////////////////////////////////
	OpticalSystem_LLT TestSystem00;

	// 0 surface
	SphericalSurface_LLT SphericalSurfaceTS00_0(/*radius*/12.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,15.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.7);
	// 1 surface
	SphericalSurface_LLT SphericalSurfaceTS00_1(/*radius*/12.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,17.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.7);
	// 2 surface
	ApertureStop_LLT AperturStopTS00_2{/*semiHeight*/ 1.0, /*Apex*/{ 0.0,0.0,20.0 },/*direction*/ { 0.0,0.0,20.0 },
		/*refIndex*/ 1.0 };
	// 3 surface
	PlanGeometry_LLT PlanSurfaceTS00_3(/*semiHeight*/ 4.0, /*Apex*/{ 0.0,0.0,23.0 }, /*Direction*/{ 0.0,0.0,1.0 },
		/*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);

	// build the optical system
	TestSystem00.fillVectorSurfaceAndInteractingData(0, &SphericalSurfaceTS00_0, refrac.clone());
	TestSystem00.fillVectorSurfaceAndInteractingData(1, &SphericalSurfaceTS00_1, refrac.clone());
	TestSystem00.fillVectorSurfaceAndInteractingData(2, &AperturStopTS00_2, doNothing.clone());
	TestSystem00.fillVectorSurfaceAndInteractingData(3, &PlanSurfaceTS00_3, absorb.clone());

	// start point optical axis { 0.0,0.0,0.0 }
	VectorStructR3 startPointOptA{ 0.0,0.0,0.0 };
	std::vector<real> optA_rms_ref{ 622.192 };
	RayAiming_12Cores rayAimingSuperFct_E0_optA(/*optical system*/ TestSystem00, /*rings*/ mRings,/*arms*/ mArms, /*start point ray*/ startPointOptA, /*light*/ mLight587, /*start ref index*/ mStartRefIndexAir);
	std::vector<LightRayStruct> aimedLightRays_E0_optA = rayAimingSuperFct_E0_optA.getAimedLightRays();
	bool checkRayAimingOptA = oftenUse::checkOptSysLLT_Equal_Better_Zemax(TestSystem00, startOptA_vec, optA_rms_ref, mMinTolerance, compareTOM_Zemax::comEqual);
	checkRayAiming_E0_vec.push_back(checkRayAimingOptA);
	// ***
	
	// start point field1 {1.0, -0.5, 0.0}
	VectorStructR3 startPointField1{ 1.0, -0.5, 0.0 };
	std::vector<VectorStructR3> startPointField1_vec{ startPointField1 };
	std::vector<real> field1_rms_ref = { 619.310 };
	RayAiming_12Cores rayAimingSuperFct_E0_field1(/*optical system*/ TestSystem00, /*rings*/ mRings,/*arms*/ mArms, /*start point ray*/ startPointField1, /*light*/ mLight587, /*start ref index*/ mStartRefIndexAir);
	std::vector<LightRayStruct> aimedLightRays_E0_field1 = rayAimingSuperFct_E0_field1.getAimedLightRays();
	bool checkRayAimingField1 = oftenUse::checkOptSysLLT_Equal_Better_Zemax(TestSystem00, startPointField1_vec, field1_rms_ref, mMinTolerance, compareTOM_Zemax::comEqual);
	checkRayAiming_E0_vec.push_back(checkRayAimingField1);
	// ***

	// start point field2 {0.5, 0.5, 0.0}
	VectorStructR3 startPointField2{ 0.5, 0.5, 0.0 };
	std::vector<VectorStructR3> startPointField2_vec{ startPointField2 };
	std::vector<real> field2_rms_ref = { 621.051 };
	RayAiming_12Cores rayAimingSuperFct_E0_field2(/*optical system*/ TestSystem00, /*rings*/ mRings,/*arms*/ mArms, /*start point ray*/ startPointField2, /*light*/ mLight587, /*start ref index*/ mStartRefIndexAir);
	std::vector<LightRayStruct> aimedLightRays_E0_field2 = rayAimingSuperFct_E0_field2.getAimedLightRays();
	bool checkRayAimingField2 = oftenUse::checkOptSysLLT_Equal_Better_Zemax(TestSystem00, startPointField2_vec, field2_rms_ref, mMinTolerance, compareTOM_Zemax::comEqual);
	checkRayAiming_E0_vec.push_back(checkRayAimingField2);
	// ***

	// start point field3 {3.0, 3.0, 0.0}
	VectorStructR3 startPointField3{ 3.0, 3.0, 0.0 };
	std::vector<VectorStructR3> startPointField3_vec{ startPointField3 };
	std::vector<real> field3_rms_ref = { 566.528 };
	RayAiming_12Cores rayAimingSuperFct_E0_field3(/*optical system*/ TestSystem00, /*rings*/ mRings,/*arms*/ mArms, /*start point ray*/ startPointField3, /*light*/ mLight587, /*start ref index*/ mStartRefIndexAir);
	std::vector<LightRayStruct> aimedLightRays_E0_field3 = rayAimingSuperFct_E0_field3.getAimedLightRays();
	bool checkRayAimingField3 = oftenUse::checkOptSysLLT_Equal_Better_Zemax(TestSystem00, startPointField3_vec, field3_rms_ref, mMinTolerance, compareTOM_Zemax::comEqual);
	checkRayAiming_E0_vec.push_back(checkRayAimingField3);
	// ***

	// start point field3 {3.0, 3.0, 0.0}
	VectorStructR3 startPointField4{ 2.0, -3.0, 0.0 };
	std::vector<VectorStructR3> startPointField4_vec{ startPointField4 };
	std::vector<real> field4_rms_ref = { 585.943 };
	RayAiming_12Cores rayAimingSuperFct_E0_field4(/*optical system*/ TestSystem00, /*rings*/ mRings,/*arms*/ mArms, /*start point ray*/ startPointField4, /*light*/ mLight587, /*start ref index*/ mStartRefIndexAir);
	std::vector<LightRayStruct> aimedLightRays_E0_field4 = rayAimingSuperFct_E0_field4.getAimedLightRays();
	bool checkRayAimingField4 = oftenUse::checkOptSysLLT_Equal_Better_Zemax(TestSystem00, startPointField4_vec, field4_rms_ref, mMinTolerance, compareTOM_Zemax::comEqual);
	checkRayAiming_E0_vec.push_back(checkRayAimingField4);
	// ***

	bool returnCheckerE0 = Math::checkTrueOfVectorElements(checkRayAiming_E0_vec);
	return returnCheckerE0;
}