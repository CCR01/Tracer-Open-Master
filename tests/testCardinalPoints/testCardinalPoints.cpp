
#include "testCardinalPoints.h"

// include surfaces
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"

// include interactions
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"

// include optical system
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"

// include sequential ray tracing 
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"

// include cardinal points
#include "..\..\Analyse\CardinalPoints.h"

// often use namespace
#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

// element surfaces
#include "..\..\SurfaceElements\ApertureStopElement.h"
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\PlanElement.h"

// glass catalog
#include "..\..\Glasses\Glasses.h"

typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

testCardinalPoints::testCardinalPoints()
{
	mGlobalTolerance = 0.1;
	mGlobalToleranceExtender = 1.0;
}

testCardinalPoints::~testCardinalPoints() {}


bool testCardinalPoints::superFuncTestCalcCardinalPoints()
{
	std::vector<bool> checkCalcCardinal;

	bool testE0 = testCalcCardinalPointsE0_obj();
	checkCalcCardinal.push_back(testE0);
	bool testE1 = testCalcCardinalPointsE1_obj();
	checkCalcCardinal.push_back(testE1);
	bool testE2 = testCalcCardinalPointsE2_obj();
	checkCalcCardinal.push_back(testE2);
	bool testE3 = testCalcCardinalPointsE3_obj();
	checkCalcCardinal.push_back(testE3);
	bool testE4 = testCalcCardinalPointsE4_obj();
	checkCalcCardinal.push_back(testE4);
	bool testE5 = testCalcCardinalPointsE5_obj();
	checkCalcCardinal.push_back(testE5);
	bool testE6 = testCalcCardinalPointsE6_inf();
	checkCalcCardinal.push_back(testE6);
	bool testE7 = testCalcCardinalPointsE7_inf();
	checkCalcCardinal.push_back(testE7);
	bool testE8 = testCalcCardinalPointsE8_inf();
	checkCalcCardinal.push_back(testE8);
	bool testE9 = testCalcCardinalPointsE9_inf();
	checkCalcCardinal.push_back(testE9);
	bool testE10 = testCalcCardinalPointsE10_obj();
	checkCalcCardinal.push_back(testE10);
	bool testE11 = testCalcCardinalPointsE11_obj();
	checkCalcCardinal.push_back(testE11);
	//bool testE12 = testCalcCardinalPointsE12_obj();
	//checkCalcCardinal.push_back(testE12);
	bool testE13 = testCalcCardinalPointsE13_obj();
	checkCalcCardinal.push_back(testE13);
	bool testE14 = testCalcCardinalPointsE14_obj();
	checkCalcCardinal.push_back(testE14);
	bool testE15 = testCalcCardinalPointsE15_obj();
	checkCalcCardinal.push_back(testE15);
	bool testE16 = testCalcCardinalPointsE16_inf();
	checkCalcCardinal.push_back(testE16);
	bool testE17 = testCalcCardinalPointsE17_inf();
	checkCalcCardinal.push_back(testE17);
	bool testE18 = testCalcCardinalPointsE18_inf();
	checkCalcCardinal.push_back(testE18);
	bool testE19 = testCalcCardinalPointsE19_inf();
	checkCalcCardinal.push_back(testE19);
	bool testE20 = testCalcCardinalPointsE20_inf();
	checkCalcCardinal.push_back(testE20);
	bool testE21 = testCalcCardinalPointsE21_inf();
	checkCalcCardinal.push_back(testE21);
	bool testE22 = testCalcCardinalPointsE22_inf();
	checkCalcCardinal.push_back(testE22);
	bool testE23 = testCalcCardinalPointsE23_inf();
	checkCalcCardinal.push_back(testE23);
	bool testE24 = testCalcCardinalPointsE24_inf();
	checkCalcCardinal.push_back(testE24);


	bool returnCheck = Math::checkTrueOfVectorElements(checkCalcCardinal);

	return returnCheck;
}

bool testCardinalPoints::testCalcCardinalPointsE0_obj()
{
	std::vector<bool> checkE0_vecBool;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	Light.setWavelength(550.0);


	SphericalSurface_LLT SphericalSurface1E0(/*radius*/5.5, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,5.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT SphericalSurface2E0(/*radius*/8, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,10.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	ApertureStop_LLT ApertureStop0E0(1.0, { 0.0,0.0,15.0 }, { 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT SphericalSurface3E0(/*radius*/100.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,25.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT SphericalSurface4E0(/*radius*/100.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,30.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT SphericalSurface5E0(/*radius*/40.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,35.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT SphericalSurface6E0(/*radius*/40.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,40.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	PlanGeometry_LLT Plan5E0(/*semi Height*/ 10.0, /*apex*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, 1.5, 1.0);


	//*************
	// build the optical system
	OpticalSystem_LLT optSysE0;

	optSysE0.fillVectorSurfaceAndInteractingData(0, SphericalSurface1E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(1, SphericalSurface2E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(2, ApertureStop0E0.clone(), doNothing.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(3, SphericalSurface3E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(4, SphericalSurface4E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(5, SphericalSurface5E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(6, SphericalSurface6E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(7, Plan5E0.clone(), absorb.clone());

	// check the system
	std::vector<VectorStructR3> fieldPoint_0_vec(1);
	fieldPoint_0_vec[0] = { 0.0,0.0,0.0 };
	std::vector<real> RMS_ref(1);
	RMS_ref[0] = 1590.40;
	bool checkTheSystem = oftenUse::checkOptSysLLT_Equal_Better_Zemax(optSysE0, fieldPoint_0_vec, RMS_ref, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE0_vecBool.push_back(checkTheSystem);
	// ***

	CardinalPoints calcCardinalPointsE0(optSysE0, objectPoint_inf_obj::obj);

	real EFL_ref = 4.52272;
	real PP_obj_ref = -2.633821;
	real PP_ima_ref = -28.752718;
	real EXPP_lastSurface_ref = -24.29743;
	real EXPP_global_ref = -25.70257;
	real EXPD_ref = 1.211248;
	real Mag_ref = 2.09721;
	real NA_objSpace_ref = 0.1336559;
	real ENPP_firstSurface_ref = 296.153846;
	real ENPP_global_ref = 301.153846;
	real ENPD_ref = 81.230769;
	real f_number_imaSpace_ref = 0.05567737;
	real NA_imaSpace_ref = 0.06417467;
	real WFNO_ref = 8.31765;

	real EFL_calc = calcCardinalPointsE0.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE0.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE0.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE0.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE0.getEXPD();
	real Mag_calc = calcCardinalPointsE0.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE0.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE0.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE0.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE0.getENPD();
	real f_number_imaSpace_calc = calcCardinalPointsE0.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE0.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE0.getWorkingFnumber();

	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE0_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE0_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE0_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE0_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE0_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE0_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE0_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE0_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE0_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE0_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc, f_number_imaSpace_ref, mGlobalTolerance);
	checkE0_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE0_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE0_vecBool.push_back(checkWFNO);

	bool checkE0 = Math::checkTrueOfVectorElements(checkE0_vecBool);
	return checkE0;

}
bool testCardinalPoints::testCalcCardinalPointsE1_obj()
{

	std::vector<bool> checkE1_vecBool;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	Light.setWavelength(550.0);

	ApertureStop_LLT ApertureStop0E1(1.0, { 0.0,0.0,5.0 }, { 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT SphericalSurface1E1(/*radius*/5.5, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,10.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT SphericalSurface2E1(/*radius*/8, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,15.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT SphericalSurface3E1(/*radius*/100.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT SphericalSurface4E1(/*radius*/100.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,25.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	PlanGeometry_LLT Plan5E1(/*semi Height*/ 10.0, /*apex*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, 1.5, 1.0);


	//*************
	// build the optical system
	OpticalSystem_LLT optSysE1;
	optSysE1.fillVectorSurfaceAndInteractingData(0, ApertureStop0E1.clone(), doNothing.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(1, SphericalSurface1E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(2, SphericalSurface2E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(3, SphericalSurface3E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(4, SphericalSurface4E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(5, Plan5E1.clone(), absorb.clone());

	// check the system
	std::vector<VectorStructR3> fieldPoint_0_vec(1);
	fieldPoint_0_vec[0] = { 0.0,0.0,0.0 };
	std::vector<real> RMS_ref(1);
	RMS_ref[0] = 203.349;
	bool checkTheSystem = oftenUse::checkOptSysLLT_Equal_Better_Zemax(optSysE1, fieldPoint_0_vec, RMS_ref, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE1_vecBool.push_back(checkTheSystem);
	// ***

	CardinalPoints calcCardinalPointsE1(optSysE1, objectPoint_inf_obj::obj);



	real EFL_ref = 7.32802;
	real PP_obj_ref = 5.891194;
	real PP_ima_ref = -15.429237;
	real EXPP_lastSurface_ref = -45.4752474;
	real EXPP_global_ref = -15.475247;
	real EXPD_ref = 10.20031489;
	real Mag_ref = -2.0566;
	real NA_objSpace_ref = 0.1961161;
	real ENPP_firstSurface_ref = 0.0;
	real ENPP_global_ref = 5.0;
	real ENPD_ref = 2.0;
	real f_number_imaSpace_ref = 3.664008;
	real NA_imaSpace_ref = 0.0967915;
	real WFNO_ref = 3.552;



	real EFL_calc = calcCardinalPointsE1.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE1.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE1.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE1.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE1.getEXPD();
	real Mag_calc = calcCardinalPointsE1.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE1.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE1.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE1.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE1.getENPD();
	real f_number_imaSpace_calc = calcCardinalPointsE1.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE1.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE1.getWorkingFnumber();

	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE1_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE1_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE1_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE1_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE1_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE1_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE1_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE1_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE1_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE1_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc, f_number_imaSpace_ref, mGlobalTolerance);
	checkE1_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE1_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE1_vecBool.push_back(checkWFNO);

	bool checkE1 = Math::checkTrueOfVectorElements(checkE1_vecBool);
	return checkE1;


}


bool testCardinalPoints::testCalcCardinalPointsE2_obj()
{

	std::vector<bool> checkE2_vecBool;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	Light.setWavelength(550.0);


	SphericalSurface_LLT SphericalSurface1E2(/*radius*/20.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,10.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);

	SphericalSurface_LLT SphericalSurface2E2(/*radius*/14.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,15.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);

	SphericalSurface_LLT SphericalSurface3E2(/*radius*/15.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,25.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);

	SphericalSurface_LLT SphericalSurface4E2(/*radius*/15.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,30.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);

	ApertureStop_LLT ApertureStop0E2(1.0, { 0.0,0.0,40.0 }, { 0.0,0.0,1.0 }, 1.0);

	SphericalSurface_LLT SphericalSurface5E2(/*radius*/25.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,50.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);

	SphericalSurface_LLT SphericalSurface6E2(/*radius*/60.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,55.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);

	SphericalSurface_LLT SphericalSurface7E2(/*radius*/40.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,65.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);

	SphericalSurface_LLT SphericalSurface8E2(/*radius*/40.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,70.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);

	PlanGeometry_LLT Plan9E2(/*semi Height*/ 10.0, /*apex*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0, 1.0);


	//*************
	// build the optical system
	OpticalSystem_LLT optSysE2;

	optSysE2.fillVectorSurfaceAndInteractingData(0, SphericalSurface1E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(1, SphericalSurface2E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(2, SphericalSurface3E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(3, SphericalSurface4E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(4, ApertureStop0E2.clone(), doNothing.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(5, SphericalSurface5E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(6, SphericalSurface6E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(7, SphericalSurface7E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(8, SphericalSurface8E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(9, Plan9E2.clone(), absorb.clone());

	// check the system
	std::vector<VectorStructR3> fieldPoint_0_vec(1);
	fieldPoint_0_vec[0] = { 0.0,0.0,0.0 };
	std::vector<real> RMS_ref(1);
	RMS_ref[0] = 3435.34;
	bool checkTheSystem = oftenUse::checkOptSysLLT_Equal_Better_Zemax(optSysE2, fieldPoint_0_vec, RMS_ref, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE2_vecBool.push_back(checkTheSystem);
	// ***

	CardinalPoints calcCardinalPointsE2(optSysE2, objectPoint_inf_obj::obj);

	real EFL_ref = 10.279;
	real PP_obj_ref = -51.746677;
	real PP_ima_ref = -37.195998;
	real EXPP_lastSurface_ref = -25.8305261;
	real EXPP_global_ref = 54.16947390;
	real EXPD_ref = 0.9685867861712;
	real Mag_ref = 0.197576;
	real NA_objSpace_ref = 0.03067983;
	real ENPP_firstSurface_ref = -159.2727272727;
	real ENPP_global_ref = -149.27272727;
	real ENPD_ref = 9.16363636363;
	real f_number_imaSpace_ref = 1.121718;
	real NA_imaSpace_ref = 0.153513;
	real WFNO_ref = 3.20058;

	real EFL_calc = calcCardinalPointsE2.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE2.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE2.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE2.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE2.getEXPD();
	real Mag_calc = calcCardinalPointsE2.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE2.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE2.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE2.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE2.getENPD();
	real f_number_imaSpace_calc = calcCardinalPointsE2.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE2.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE2.getWorkingFnumber();


	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE2_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE2_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE2_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE2_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE2_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE2_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE2_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE2_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE2_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE2_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc, f_number_imaSpace_ref, mGlobalTolerance);
	checkE2_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE2_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE2_vecBool.push_back(checkWFNO);


	bool checkE2 = Math::checkTrueOfVectorElements(checkE2_vecBool);
	return checkE2;


}

bool testCardinalPoints::testCalcCardinalPointsE3_obj()
{

	std::vector<bool> checkE3_vecBool;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	Light.setWavelength(550.0);


	SphericalSurface_LLT SphericalSurface1E3(/*radius*/30.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0,0.0,10.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);

	SphericalSurface_LLT SphericalSurface2E3(/*radius*/12.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0,0.0,15.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);

	SphericalSurface_LLT SphericalSurface3E3(/*radius*/18.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0,0.0,25.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);

	SphericalSurface_LLT SphericalSurface4E3(/*radius*/60.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0,0.0,30.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);

	SphericalSurface_LLT SphericalSurface5E3(/*radius*/15.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0,0.0,40.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);

	SphericalSurface_LLT SphericalSurface6E3(/*radius*/15.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0,0.0,45.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);

	ApertureStop_LLT ApertureStop0E3(0.5, { 0.0,0.0,55.0 }, { 0.0,0.0,1.0 }, 1.0);

	SphericalSurface_LLT SphericalSurface7E3(/*radius*/10.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0,0.0,60.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);

	SphericalSurface_LLT SphericalSurface8E3(/*radius*/25.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0,0.0,70.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);

	PlanGeometry_LLT Plan9E3(/*semi Height*/ 10.0, /*apex*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0,1.0 }, 1.5, 1.0);


	//*************
	// build the optical system
	OpticalSystem_LLT optSysE3;

	optSysE3.fillVectorSurfaceAndInteractingData(0, SphericalSurface1E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(1, SphericalSurface2E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(2, SphericalSurface3E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(3, SphericalSurface4E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(4, SphericalSurface5E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(5, SphericalSurface6E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(6, ApertureStop0E3.clone(), doNothing.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(7, SphericalSurface7E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(8, SphericalSurface8E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(9, Plan9E3.clone(), absorb.clone());

	// check singel ray
	bool checkSingleRay = oftenUse::checkRayTracing({ 0.0,0.0,0.0 }, { 0.0,0.0624019185,10.0 }, { 0.0,0.4597232375,75.0 }, optSysE3, 9, mGlobalTolerance);
	checkE3_vecBool.push_back(checkSingleRay);

	// check the system
	std::vector<VectorStructR3> fieldPoint_0_vec(1);
	fieldPoint_0_vec[0] = { 0.0,0.0,0.0 };
	std::vector<real> RMS_ref(1);
	RMS_ref[0] = 349.792;
	bool checkTheSystem = oftenUse::checkOptSysLLT_Equal_Better_Zemax(optSysE3, fieldPoint_0_vec, RMS_ref, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE3_vecBool.push_back(checkTheSystem);
	// ***

	CardinalPoints calcCardinalPointsE3(optSysE3, objectPoint_inf_obj::obj);

	real EFL_ref = 11.5738;
	real PP_obj_ref = 37.480285;
	real PP_ima_ref = 8.472246;
	real EXPP_lastSurface_ref = -23.18181504614;
	real EXPP_global_ref = 51.81818495;
	real EXPD_ref = 1.8181817004864;
	real Mag_ref = -0.32233;
	real NA_objSpace_ref = 0.00624003;
	real ENPP_firstSurface_ref = 29.005268405283;
	real ENPP_global_ref = 39.005268405283;
	real ENPD_ref = 0.48679755669;
	real f_number_imaSpace_ref = 23.7753;
	real NA_imaSpace_ref = 0.01935587;
	real WFNO_ref = 25.6963;

	real EFL_calc = calcCardinalPointsE3.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE3.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE3.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE3.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE3.getEXPD();
	real Mag_calc = calcCardinalPointsE3.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE3.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE3.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE3.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE3.getENPD();
	real f_number_imaSpace_calc = calcCardinalPointsE3.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE3.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE3.getWorkingFnumber();

	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE3_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE3_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE3_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE3_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE3_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE3_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE3_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE3_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE3_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE3_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc, f_number_imaSpace_ref, mGlobalTolerance);
	checkE3_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE3_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE3_vecBool.push_back(checkWFNO);


	bool checkE3 = Math::checkTrueOfVectorElements(checkE3_vecBool);
	return checkE3;


}

bool testCardinalPoints::testCalcCardinalPointsE4_obj()
{
	std::vector<bool> checkE4_vecBool;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	real defaultWavelength = 550.0;
	Light.setWavelength(defaultWavelength);

	// surfaces E4
	SphericalElement Sphere0_E4(/*radius*/ 25.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere1_E4(/*radius*/ 25.00, /*semi height*/7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF11_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2_E4(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF11_S1());
	SphericalElement Sphere3_E4(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF4_S1());
	SphericalElement Sphere4_E4(/*radius*/ 70.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF4_S1());
	ApertureStopElement AperStop5_E4(/* semi height*/1.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere6_E4(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere7_E4(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere8_E4(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	PlanElement Plan9_E4(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,80.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	surfacePtr Sphere0_E4_ptr = Sphere0_E4.clone();
	surfacePtr Sphere1_E4_ptr = Sphere1_E4.clone();
	surfacePtr Sphere2_E4_ptr = Sphere2_E4.clone();
	surfacePtr Sphere3_E4_ptr = Sphere3_E4.clone();
	surfacePtr Sphere4_E4_ptr = Sphere4_E4.clone();
	surfacePtr ApertureStop5_E4_ptr = AperStop5_E4.clone();
	surfacePtr Sphere6_E4_ptr = Sphere6_E4.clone();
	surfacePtr Sphere7_E4_ptr = Sphere7_E4.clone();
	surfacePtr Sphere8_E4_ptr = Sphere8_E4.clone();
	surfacePtr Plan9_E4_ptr = Plan9_E4.clone();

	std::vector<surfacePtr> opticalSystemE4_ptr{ Sphere0_E4_ptr, Sphere1_E4_ptr, Sphere2_E4_ptr , Sphere3_E4_ptr, Sphere4_E4_ptr, ApertureStop5_E4_ptr, Sphere6_E4_ptr, Sphere7_E4_ptr, Sphere8_E4_ptr, Plan9_E4_ptr };
	std::vector<interaction_ptr> interactionsE4_ptr{ refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSysEle_E4(opticalSystemE4_ptr, interactionsE4_ptr);
	optSysEle_E4.setRefractiveIndexAccordingToWavelength(defaultWavelength);
	// check the start system

	std::vector<VectorStructR3> fieldPoint_0_vec(1);
	fieldPoint_0_vec[0] = { 0.0,0.0,0.0 };
	std::vector<real> wavelenght_vec(1);
	wavelenght_vec[0] = defaultWavelength;
	std::vector<real> rmsStartSystem{ 144.429 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle_E4, fieldPoint_0_vec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE4_vecBool.push_back(checkTheSystem);
	// ***

	CardinalPoints calcCardinalPointsE4(optSysEle_E4, defaultWavelength, objectPoint_inf_obj::obj);

	real EFL_ref = 24.7829;
	real PP_obj_ref = 32.635592;
	real PP_ima_ref = -39.561144;
	real EXPP_lastSurface_ref = -25.1361555;
	real EXPP_global_ref = 54.86384450;
	real EXPD_ref = 2.8468105465784;
	real Mag_ref = -0.754363;
	real NA_objSpace_ref = 0.036933339;
	real ENPP_firstSurface_ref = 67.149677269814;
	real ENPP_global_ref = 92.149677269814;
	real ENPD_ref = 6.8114470536041;
	real f_number_imaSpace_ref = 3.638414;
	real NA_imaSpace_ref = 0.04893447;
	real WFNO_ref = 10.1879;

	real EFL_calc = calcCardinalPointsE4.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE4.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE4.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE4.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE4.getEXPD();
	real Mag_calc = calcCardinalPointsE4.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE4.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE4.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE4.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE4.getENPD();
	real f_number_imaSpace_calc = calcCardinalPointsE4.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE4.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE4.getWorkingFnumber();

	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE4_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE4_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE4_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE4_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE4_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE4_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE4_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE4_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE4_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE4_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc, f_number_imaSpace_ref, mGlobalTolerance);
	checkE4_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE4_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE4_vecBool.push_back(checkWFNO);

	bool checkE4 = Math::checkTrueOfVectorElements(checkE4_vecBool);
	return checkE4;
}

bool testCardinalPoints::testCalcCardinalPointsE5_obj()
{
	std::vector<bool> checkE5_vecBool;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	real defaultWavelength = 550.0;
	Light.setWavelength(defaultWavelength);

	// surfaces E5
	SphericalElement Sphere0_E5(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF4_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere1_E5(/*radius*/ 150.00, /*semi height*/7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF4_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere2_E5(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere3_E5(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere4_E5(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement Sphere5_E5(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF4_S1());
	SphericalElement Sphere6_E5(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF57_S1(), /*refractive index B*/glasses.getSF4_S1());
	SphericalElement Sphere7_E5(/*radius*/ 35.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF57_S1());
	ApertureStopElement AperStop8_E5(/* semi height*/1.7, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan9_E5(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,100.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	surfacePtr Sphere0_E5_ptr = Sphere0_E5.clone();
	surfacePtr Sphere1_E5_ptr = Sphere1_E5.clone();
	surfacePtr Sphere2_E5_ptr = Sphere2_E5.clone();
	surfacePtr Sphere3_E5_ptr = Sphere3_E5.clone();
	surfacePtr Sphere4_E5_ptr = Sphere4_E5.clone();
	surfacePtr Sphere5_E5_ptr = Sphere5_E5.clone();
	surfacePtr Sphere6_E5_ptr = Sphere6_E5.clone();
	surfacePtr Sphere7_E5_ptr = Sphere7_E5.clone();
	surfacePtr Aper8_E5_ptr = AperStop8_E5.clone();
	surfacePtr Plan9_E5_ptr = Plan9_E5.clone();

	std::vector<surfacePtr> opticalSystemE5_ptr{ Sphere0_E5_ptr, Sphere1_E5_ptr, Sphere2_E5_ptr , Sphere3_E5_ptr, Sphere4_E5_ptr, Sphere5_E5_ptr, Sphere6_E5_ptr, Sphere7_E5_ptr, Aper8_E5_ptr, Plan9_E5_ptr };
	std::vector<interaction_ptr> interactionsE5_ptr{ refrac.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),doNothing.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E5(opticalSystemE5_ptr, interactionsE5_ptr);
	optSystemElement_E5.setRefractiveIndexAccordingToWavelength(defaultWavelength);

	// check the start system
	std::vector<VectorStructR3> fieldPoint_0_vec(1);
	fieldPoint_0_vec[0] = { 0.0,0.0,0.0 };
	std::vector<real> wavelenght_vec(1);
	wavelenght_vec[0] = defaultWavelength;
	std::vector<real> rmsStartSystem{ 176.119 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E5, fieldPoint_0_vec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE5_vecBool.push_back(checkTheSystem);
	// ***

	CardinalPoints calcCardinalPointsE5(optSystemElement_E5, defaultWavelength, objectPoint_inf_obj::obj);

	real EFL_ref = 18.4306;
	real PP_obj_ref = 25.967604;
	real PP_ima_ref = -26.750482;
	real EXPP_lastSurface_ref = -10.0;
	real EXPP_global_ref = 90.0;
	real EXPD_ref = 3.4;
	real Mag_ref = -0.433283;
	real NA_objSpace_ref = 0.07598512;
	real ENPP_firstSurface_ref = 209.7214;
	real ENPP_global_ref = 244.7214;
	real ENPD_ref = 37.2982;
	real f_number__imaSpace_ref = 0.4941408;
	real NA_imaSpace_ref = 0.1732205;
	real WFNO_ref = 2.57221;

	real EFL_calc = calcCardinalPointsE5.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE5.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE5.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE5.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE5.getEXPD();
	real Mag_calc = calcCardinalPointsE5.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE5.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE5.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE5.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE5.getENPD();
	real f_number_imaSpace_calc_imaSpace = calcCardinalPointsE5.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE5.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE5.getWorkingFnumber();


	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE5_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE5_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE5_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE5_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE5_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE5_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE5_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE5_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE5_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE5_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc_imaSpace, f_number__imaSpace_ref, mGlobalTolerance);
	checkE5_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE5_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE5_vecBool.push_back(checkWFNO);

	bool checkE5 = Math::checkTrueOfVectorElements(checkE5_vecBool);
	return checkE5;
}

bool testCardinalPoints::testCalcCardinalPointsE6_inf()
{
	std::vector<bool> checkE6_vecBool;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	real defaultWavelength = 550.0;
	Light.setWavelength(defaultWavelength);

	// surfaces E6
	SphericalElement Sphere0_E6(/*radius*/ 60, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF4_S1());
	SphericalElement Sphere1_E6(/*radius*/ 150, /*semi height*/7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF4_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2_E6(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere3_E6(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere4_E6(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	ApertureStopElement AperStop5_E6(/* semi height*/2.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere6_E6(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF4_S1());
	SphericalElement Sphere7_E6(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF57_S1(), /*refractive index B*/glasses.getSF4_S1());
	SphericalElement Sphere8_E6(/*radius*/ 35.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF57_S1());
	PlanElement Plan9_E6(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	surfacePtr Sphere0_E6_ptr = Sphere0_E6.clone();
	surfacePtr Sphere1_E6_ptr = Sphere1_E6.clone();
	surfacePtr Sphere2_E6_ptr = Sphere2_E6.clone();
	surfacePtr Sphere3_E6_ptr = Sphere3_E6.clone();
	surfacePtr Sphere4_E6_ptr = Sphere4_E6.clone();
	surfacePtr Aper5_E6_ptr = AperStop5_E6.clone();
	surfacePtr Sphere6_E6_ptr = Sphere6_E6.clone();
	surfacePtr Sphere7_E6_ptr = Sphere7_E6.clone();
	surfacePtr Sphere8_E6_ptr = Sphere8_E6.clone();
	surfacePtr Plan9_E6_ptr = Plan9_E6.clone();

	std::vector<surfacePtr> opticalSystemE6_ptr{ Sphere0_E6_ptr, Sphere1_E6_ptr, Sphere2_E6_ptr , Sphere3_E6_ptr, Sphere4_E6_ptr, Aper5_E6_ptr, Sphere6_E6_ptr, Sphere7_E6_ptr, Sphere8_E6_ptr, Plan9_E6_ptr };
	std::vector<interaction_ptr> interactionsE6_ptr{ refrac.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), doNothing.clone(), refrac.clone(),refrac.clone(),refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E6(opticalSystemE6_ptr, interactionsE6_ptr);
	optSystemElement_E6.setRefractiveIndexAccordingToWavelength(defaultWavelength);



	//// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> wavelenght_vec{ defaultWavelength };
	std::vector<real> rmsStartSystem{ 524.084 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E6, anglesXvec, anglesYvec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE6_vecBool.push_back(checkTheSystem);
	//// ***

	CardinalPoints calcCardinalPointsE6(optSystemElement_E6, defaultWavelength, objectPoint_inf_obj::inf);

	real EFL_ref = 24.4171;
	real PP_obj_ref = 35.737181;
	real PP_ima_ref = -28.972062;
	real EXPP_lastSurface_ref = -24.65094;
	real EXPP_global_ref = 40.34906;
	real EXPD_ref = 5.766619;
	real Mag_ref = 0.0;
	real NA_objSpace_ref = 0.0;
	real ENPP_firstSurface_ref = 40.98745;
	real ENPP_global_ref = 40.98745;
	real ENPD_ref = 7.006586;
	real f_number_imaSpace_ref = 3.484874;
	real NA_imaSpace_ref = 0.1420228;
	real WFNO_ref = 3.460687;

	real EFL_calc = calcCardinalPointsE6.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE6.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE6.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE6.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE6.getEXPD();
	real Mag_calc = calcCardinalPointsE6.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE6.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE6.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE6.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE6.getENPD();
	real f_number_imaSpace_calc = calcCardinalPointsE6.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE6.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE6.getWorkingFnumber();


	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE6_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE6_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE6_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE6_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE6_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE6_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE6_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE6_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE6_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE6_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc, f_number_imaSpace_ref, mGlobalTolerance);
	checkE6_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE6_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE6_vecBool.push_back(checkWFNO);

	bool checkE6 = Math::checkTrueOfVectorElements(checkE6_vecBool);
	return checkE6;
}

bool testCardinalPoints::testCalcCardinalPointsE7_inf()
{
	std::vector<bool> checkE7_vecBool;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	real defaultWavelength = 550.0;
	Light.setWavelength(defaultWavelength);

	// surfaces E7
	ApertureStopElement AperStop0_E7(/* semi height*/3.21, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E7(/*radius*/ 60, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF4_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere2_E7(/*radius*/ 150, /*semi height*/7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF4_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3_E7(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere4_E7(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere5_E7(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	PlanElement Plan6_E7(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	surfacePtr Aper0_E7_ptr = AperStop0_E7.clone();
	surfacePtr Sphere1_E7_ptr = Sphere1_E7.clone();
	surfacePtr Sphere2_E7_ptr = Sphere2_E7.clone();
	surfacePtr Sphere3_E7_ptr = Sphere3_E7.clone();
	surfacePtr Sphere4_E7_ptr = Sphere4_E7.clone();
	surfacePtr Sphere5_E7_ptr = Sphere5_E7.clone();
	surfacePtr Plan6_E7_ptr = Plan6_E7.clone();

	std::vector<surfacePtr> opticalSystemE7_ptr{ Aper0_E7_ptr, Sphere1_E7_ptr, Sphere2_E7_ptr , Sphere3_E7_ptr, Sphere4_E7_ptr, Sphere5_E7_ptr, Plan6_E7_ptr };
	std::vector<interaction_ptr> interactionsE7_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E7(opticalSystemE7_ptr, interactionsE7_ptr);
	optSystemElement_E7.setRefractiveIndexAccordingToWavelength(defaultWavelength);


	//// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> wavelenght_vec{ defaultWavelength };
	std::vector<real> rmsStartSystem{ 2017.45 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E7, anglesXvec, anglesYvec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE7_vecBool.push_back(checkTheSystem);
	//// ***

	CardinalPoints calcCardinalPointsE7(optSystemElement_E7, defaultWavelength, objectPoint_inf_obj::inf);

	real EFL_ref = 60.8795;
	real PP_obj_ref = 38.692339;
	real PP_ima_ref = -9.988797;
	real EXPP_lastSurface_ref = -116.1569;
	real EXPP_global_ref = -40.1569;
	real EXPD_ref = 17.61587;
	real Mag_ref = 0.0;
	real NA_objSpace_ref = 0.0;
	real ENPP_firstSurface_ref = 0.0;
	real ENPP_global_ref = 0.0;
	real ENPD_ref = 6.42;
	real f_number_imaSpace_ref = 9.482791;
	real NA_imaSpace_ref = 0.05265395;
	real WFNO_ref = 9.32455;

	real EFL_calc = calcCardinalPointsE7.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE7.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE7.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE7.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE7.getEXPD();
	real Mag_calc = calcCardinalPointsE7.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE7.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE7.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE7.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE7.getENPD();
	real f_number_imaSpace_calc = calcCardinalPointsE7.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE7.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE7.getWorkingFnumber();


	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE7_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE7_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE7_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE7_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE7_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE7_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE7_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE7_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE7_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE7_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc, f_number_imaSpace_ref, mGlobalTolerance);
	checkE7_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE7_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE7_vecBool.push_back(checkWFNO);

	bool checkE7 = Math::checkTrueOfVectorElements(checkE7_vecBool);
	return checkE7;
}

bool testCardinalPoints::testCalcCardinalPointsE8_inf()
{
	std::vector<bool> checkE8_vecBool;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	real defaultWavelength = 550.0;
	Light.setWavelength(defaultWavelength);

	// surfaces E8
	SphericalElement Sphere0_E8(/*radius*/ 60, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,00.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF4_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere1_E8(/*radius*/ 150, /*semi height*/7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF4_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2_E8(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere3_E8(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere4_E8(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	ApertureStopElement AperStop5_E8(/* semi height*/3.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan6_E8(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	surfacePtr Sphere0_E8_ptr = Sphere0_E8.clone();
	surfacePtr Sphere1_E8_ptr = Sphere1_E8.clone();
	surfacePtr Sphere2_E8_ptr = Sphere2_E8.clone();
	surfacePtr Sphere3_E8_ptr = Sphere3_E8.clone();
	surfacePtr Sphere4_E8_ptr = Sphere4_E8.clone();
	surfacePtr Aper5_E8_ptr = AperStop5_E8.clone();
	surfacePtr Plan6_E8_ptr = Plan6_E8.clone();

	std::vector<surfacePtr> opticalSystemE8_ptr{ Sphere0_E8_ptr, Sphere1_E8_ptr, Sphere2_E8_ptr , Sphere3_E8_ptr, Sphere4_E8_ptr, Aper5_E8_ptr, Plan6_E8_ptr };
	std::vector<interaction_ptr> interactionsE8_ptr{ refrac.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), doNothing.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E8(opticalSystemE8_ptr, interactionsE8_ptr);
	optSystemElement_E8.setRefractiveIndexAccordingToWavelength(defaultWavelength);

	std::cout << "" << std::endl;
	std::cout << "test system E8" << std::endl;
	oftenUse::print(optSystemElement_E8, defaultWavelength);

	//// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> wavelenght_vec{ defaultWavelength };
	std::vector<real> rmsStartSystem{ 1543.23 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E8, anglesXvec, anglesYvec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE8_vecBool.push_back(checkTheSystem);
	//// ***

	CardinalPoints calcCardinalPointsE8(optSystemElement_E8, defaultWavelength, objectPoint_inf_obj::inf);

	real EFL_ref = 34.1126;
	real PP_obj_ref = 23.397838;
	real PP_ima_ref = -11.588775;
	real EXPP_lastSurface_ref = -10.0;
	real EXPP_global_ref = 55.0 - 10;
	real EXPD_ref = 6.0;
	real Mag_ref = 0.0;
	real NA_objSpace_ref = 0.0;
	real ENPP_firstSurface_ref = 25.06422;
	real ENPP_global_ref = 25.06422;
	real ENPD_ref = 6.293097;
	real f_number_imaSpace_ref = 5.420639;
	real NA_imaSpace_ref = 0.09185013;
	real WFNO_ref = 5.08738;

	real EFL_calc = calcCardinalPointsE8.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE8.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE8.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE8.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE8.getEXPD();
	real Mag_calc = calcCardinalPointsE8.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE8.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE8.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE8.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE8.getENPD();
	real f_number_imaSpace_calc = calcCardinalPointsE8.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE8.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE8.getWorkingFnumber();


	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE8_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE8_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE8_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE8_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE8_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE8_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE8_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE8_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE8_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE8_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc, f_number_imaSpace_ref, mGlobalTolerance);
	checkE8_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE8_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE8_vecBool.push_back(checkWFNO);

	bool checkE8 = Math::checkTrueOfVectorElements(checkE8_vecBool);
	return checkE8;
}

bool testCardinalPoints::testCalcCardinalPointsE9_inf()
{
	std::vector<bool> checkE9_vecBool;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	real defaultWavelength = 550.0;
	Light.setWavelength(defaultWavelength);

	SphericalElement Sphere0_E9(/*radius*/ 100, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement Sphere1_E9(/*radius*/ 70, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBAFN10_S1(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement Sphere2_E9(/*radius*/ 120, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	ApertureStopElement AperStop3_E9(/* semi height*/1.5, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere4_E9(/*radius*/ 60, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF4_S1());
	SphericalElement Sphere5_E9(/*radius*/ 80, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF4_S1());
	PlanElement Plan6_E9(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	surfacePtr Sphere0_E9_ptr = Sphere0_E9.clone();
	surfacePtr Sphere1_E9_ptr = Sphere1_E9.clone();
	surfacePtr Sphere2_E9_ptr = Sphere2_E9.clone();
	surfacePtr Aper3_E9_ptr = AperStop3_E9.clone();
	surfacePtr Sphere4_E9_ptr = Sphere4_E9.clone();
	surfacePtr Sphere5_E9_ptr = Sphere5_E9.clone();
	surfacePtr Plan6_E9_ptr = Plan6_E9.clone();

	std::vector<surfacePtr> opticalSystemE9_ptr{ Sphere0_E9_ptr, Sphere1_E9_ptr, Sphere2_E9_ptr, Aper3_E9_ptr, Sphere4_E9_ptr, Sphere5_E9_ptr, Plan6_E9_ptr };
	std::vector<interaction_ptr> interactionsE9_ptr{ refrac.clone(), refrac.clone(),refrac.clone(), doNothing.clone(), refrac.clone(),  refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E9(opticalSystemE9_ptr, interactionsE9_ptr);
	optSystemElement_E9.setRefractiveIndexAccordingToWavelength(defaultWavelength);

	std::cout << "" << std::endl;
	std::cout << "test system E9" << std::endl;
	oftenUse::print(optSystemElement_E9, defaultWavelength);

	//// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> wavelenght_vec{ defaultWavelength };
	std::vector<real> rmsStartSystem{ 538.112 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E9, anglesXvec, anglesYvec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE9_vecBool.push_back(checkTheSystem);
	//// ***

	CardinalPoints calcCardinalPointsE9(optSystemElement_E9, defaultWavelength, objectPoint_inf_obj::inf);

	real EFL_ref = 36.9615;
	real PP_obj_ref = 22.2944;
	real PP_ima_ref = -22.3472;
	real EXPP_lastSurface_ref = -22.3069;
	real EXPP_global_ref = 37.6931;
	real EXPD_ref = 3.578;
	real Mag_ref = 0.0;
	real NA_objSpace_ref = 0.0;
	real ENPP_firstSurface_ref = 22.3347;
	real ENPP_global_ref = 22.3347;
	real ENPD_ref = 3.582;
	real f_number_imaSpace_ref = 10.3186;
	real NA_imaSpace_ref = 0.0484;
	real WFNO_ref = 10.315;

	real EFL_calc = calcCardinalPointsE9.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE9.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE9.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE9.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE9.getEXPD();
	real Mag_calc = calcCardinalPointsE9.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE9.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE9.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE9.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE9.getENPD();
	real f_number_imaSpace_calc = calcCardinalPointsE9.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE9.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE9.getWorkingFnumber();


	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE9_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE9_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE9_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE9_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE9_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE9_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE9_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE9_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE9_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE9_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc, f_number_imaSpace_ref, mGlobalTolerance);
	checkE9_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE9_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE9_vecBool.push_back(checkWFNO);

	bool checkE9 = Math::checkTrueOfVectorElements(checkE9_vecBool);
	return checkE9;

}

bool testCardinalPoints::testCalcCardinalPointsE10_obj()
{
	std::vector<bool> checkE10_vecBool;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	real defaultWavelength = 550.0;
	Light.setWavelength(defaultWavelength);

	// surfaces E10
	SphericalElement Sphere0_E10(/*radius*/ 80.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getF5_S1());
	SphericalElement Sphere1_E10(/*radius*/ 60.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBAF52_S1(), /*refractive index B*/glasses.getF5_S1());
	SphericalElement Sphere2_E10(/*radius*/ 70.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF52_S1());
	ApertureStopElement AperStop3_E10(/* semi height*/2.0, /*point*/{ 0.0,0.0,50 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere4_E10(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement Sphere5_E10(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getNBAK2_S1());
	SphericalElement Sphere6_E10(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAK2_S1());
	PlanElement Plan7_E10(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,105.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	surfacePtr Sphere0_E10_ptr = Sphere0_E10.clone();
	surfacePtr Sphere1_E10_ptr = Sphere1_E10.clone();
	surfacePtr Sphere2_E10_ptr = Sphere2_E10.clone();
	surfacePtr Aper3_E10_ptr = AperStop3_E10.clone();
	surfacePtr Sphere4_E10_ptr = Sphere4_E10.clone();
	surfacePtr Sphere5_E10_ptr = Sphere5_E10.clone();
	surfacePtr Sphere6_E10_ptr = Sphere6_E10.clone();
	surfacePtr Plan7_E10_ptr = Plan7_E10.clone();

	std::vector<surfacePtr> opticalSystemE10_ptr{ Sphere0_E10_ptr, Sphere1_E10_ptr, Sphere2_E10_ptr , Aper3_E10_ptr, Sphere4_E10_ptr, Sphere5_E10_ptr, Sphere6_E10_ptr, Plan7_E10_ptr };
	std::vector<interaction_ptr> interactionsE10_ptr{ refrac.clone(), refrac.clone(),refrac.clone(), doNothing.clone(), refrac.clone(), refrac.clone(),refrac.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E10(opticalSystemE10_ptr, interactionsE10_ptr);
	optSystemElement_E10.setRefractiveIndexAccordingToWavelength(defaultWavelength);

	// check the start system
	std::vector<VectorStructR3> fieldPoint_0_vec(1);
	fieldPoint_0_vec[0] = { 0.0,0.0,0.0 };
	std::vector<real> wavelenght_vec(1);
	wavelenght_vec[0] = defaultWavelength;
	std::vector<real> rmsStartSystem{ 1282.77 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E10, fieldPoint_0_vec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE10_vecBool.push_back(checkTheSystem);
	// ***

	CardinalPoints calcCardinalPointsE10(optSystemElement_E10, defaultWavelength, objectPoint_inf_obj::obj);

	real EFL_ref = 36.7534;
	real PP_obj_ref = 33.9369;
	real PP_ima_ref = -49.5268;
	real EXPP_lastSurface_ref = -56.0516;
	real EXPP_global_ref = 105.0 - 56.0516;
	real EXPD_ref = 6.264;
	real Mag_ref = -2.139;
	real NA_objSpace_ref = 0.054877;
	real ENPP_firstSurface_ref = 28.3957;
	real ENPP_global_ref = 28.3957 + 20.0;
	real ENPD_ref = 5.3197;
	real f_number__imaSpace_ref = 6.90888;
	real NA_imaSpace_ref = 0.02568;
	real WFNO_ref = 19.3154;

	real EFL_calc = calcCardinalPointsE10.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE10.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE10.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE10.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE10.getEXPD();
	real Mag_calc = calcCardinalPointsE10.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE10.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE10.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE10.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE10.getENPD();
	real f_number_imaSpace_calc_imaSpace = calcCardinalPointsE10.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE10.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE10.getWorkingFnumber();


	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE10_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE10_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE10_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE10_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE10_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE10_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE10_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE10_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE10_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE10_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc_imaSpace, f_number__imaSpace_ref, mGlobalTolerance);
	checkE10_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE10_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE10_vecBool.push_back(checkWFNO);

	bool checkE10 = Math::checkTrueOfVectorElements(checkE10_vecBool);
	return checkE10;
}

bool testCardinalPoints::testCalcCardinalPointsE11_obj()
{
	std::vector<bool> checkE11_vecBool;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	real defaultWavelength = 550.0;
	Light.setWavelength(defaultWavelength);

	// surfaces E11
	SphericalElement Sphere0_E11(/*radius*/ 20.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAK4_S1());
	SphericalElement Sphere1_E11(/*radius*/ 30.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAK4_S1());
	SphericalElement Sphere2_E11(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF66_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere3_E11(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF66_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere4_E11(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getLLF1_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere5_E11(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getLLF1_S1());
	ApertureStopElement AperStop6_E11(/* semi height*/1.0, /*point*/{ 0.0,0.0,140 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan7_E11(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,150.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

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
	OpticalSystemElement optSystemElement_E11(opticalSystemE11_ptr, interactionsE11_ptr);
	optSystemElement_E11.setRefractiveIndexAccordingToWavelength(defaultWavelength);

	// check single ray
	bool checkSinglRay = oftenUse::checkRayTracing(/*start point ray*/{ 0.0,0.0,0.0 },/*direction ray*/{ 0.0,1.5241117435,100.05815747 },/*target point*/{ 0.0,0.82257,150.0 },/*optical system LLT*/ optSystemElement_E11.getOptSys_LLT_buildSystem(),/*surface num*/ 7,/*tolerance*/ 0.1);

	// check the start system
	std::vector<VectorStructR3> fieldPoint_0_vec(1);
	fieldPoint_0_vec[0] = { 0.0,0.0,0.0 };
	std::vector<real> wavelenght_vec(1);
	wavelenght_vec[0] = defaultWavelength;
	std::vector<real> rmsStartSystem{ 626.82 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E11, fieldPoint_0_vec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE11_vecBool.push_back(checkTheSystem);
	// ***

	CardinalPoints calcCardinalPointsE11(optSystemElement_E11, defaultWavelength, objectPoint_inf_obj::obj);

	real EFL_ref = 51.0501;
	real PP_obj_ref = 9.4021;
	real PP_ima_ref = -47.8712;
	real EXPP_lastSurface_ref = -10.0;
	real EXPP_global_ref = 140;
	real EXPD_ref = 2.0;
	real Mag_ref = -0.8749;
	real NA_objSpace_ref = 0.0151;
	real ENPP_firstSurface_ref = 156.1002;
	real ENPP_global_ref = 156.1002 + 100.0;
	real ENPD_ref = 7.7472;
	real f_number__imaSpace_ref = 6.5895;
	real NA_imaSpace_ref = 0.0173;
	real WFNO_ref = 28.2498;

	real EFL_calc = calcCardinalPointsE11.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE11.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE11.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE11.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE11.getEXPD();
	real Mag_calc = calcCardinalPointsE11.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE11.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE11.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE11.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE11.getENPD();
	real f_number_imaSpace_calc_imaSpace = calcCardinalPointsE11.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE11.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE11.getWorkingFnumber();


	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE11_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE11_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE11_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE11_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE11_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE11_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE11_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE11_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE11_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE11_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc_imaSpace, f_number__imaSpace_ref, mGlobalTolerance);
	checkE11_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE11_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE11_vecBool.push_back(checkWFNO);

	bool checkE11 = Math::checkTrueOfVectorElements(checkE11_vecBool);
	return checkE11;
}

bool testCardinalPoints::testCalcCardinalPointsE12_obj()
{
	std::vector<bool> checkE12_vecBool;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	real defaultWavelength = 550.0;
	Light.setWavelength(defaultWavelength);

	// surfaces E12
	ApertureStopElement AperStop0_E12(/* semi height*/0.25, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E12(/*radius*/ 100.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getPSK57_S1());
	SphericalElement Sphere2_E12(/*radius*/ 100.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSK15_S1(), /*refractive index B*/glasses.getPSK57_S1());
	PlanElement Plan3_E12(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,75.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getNSK15_S1(), /*refractive index B*/ glasses.getAir());
	SphericalElement Sphere4_E12(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSK4_S1());
	SphericalElement Sphere5_E12(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getNSK4_S1());
	SphericalElement Sphere6_E12(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getAir());
	PlanElement Plan7_E12(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,130.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	surfacePtr Aper0_E12_ptr = AperStop0_E12.clone();
	surfacePtr Sphere1_E12_ptr = Sphere1_E12.clone();
	surfacePtr Sphere2_E12_ptr = Sphere2_E12.clone();
	surfacePtr Plan3_E12_ptr = Plan3_E12.clone();
	surfacePtr Sphere4_E12_ptr = Sphere4_E12.clone();
	surfacePtr Sphere5_E12_ptr = Sphere5_E12.clone();
	surfacePtr Sphere6_E12_ptr = Sphere6_E12.clone();
	surfacePtr Plan7_E12_ptr = Plan7_E12.clone();

	std::vector<surfacePtr> opticalSystemE12_ptr{ Aper0_E12_ptr, Sphere1_E12_ptr, Sphere2_E12_ptr, Plan3_E12_ptr , Sphere4_E12_ptr , Sphere5_E12_ptr , Sphere6_E12_ptr , Plan7_E12_ptr };
	std::vector<interaction_ptr> interactionsE12_ptr{ doNothing.clone() , refrac.clone(), refrac.clone(), refrac.clone() , refrac.clone() , refrac.clone() ,  refrac.clone()  , absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E12(opticalSystemE12_ptr, interactionsE12_ptr);
	optSystemElement_E12.setRefractiveIndexAccordingToWavelength(defaultWavelength);

	// check single ray
	bool checkSinglRay = oftenUse::checkRayTracing(/*start point ray*/{ 0.0,0.0,0.0 },/*direction ray*/{ 0.0,0.25,10.0 },/*target point*/{ 0.0,1.45412,130.0 },/*optical system LLT*/ optSystemElement_E12.getOptSys_LLT_buildSystem(),/*surface num*/ 7,/*tolerance*/ 0.1);

	// check the start system
	std::vector<VectorStructR3> fieldPoint_0_vec(1);
	fieldPoint_0_vec[0] = { 0.0,0.0,0.0 };
	std::vector<real> wavelenght_vec(1);
	wavelenght_vec[0] = defaultWavelength;
	std::vector<real> rmsStartSystem{ 1106.33 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E12, fieldPoint_0_vec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE12_vecBool.push_back(checkTheSystem);
	// ***

	CardinalPoints calcCardinalPointsE12(optSystemElement_E12, defaultWavelength, objectPoint_inf_obj::obj);

	real EFL_ref = 43.8361;
	real PP_obj_ref = 74.3930;
	real PP_ima_ref = -28.3218;
	real EXPP_lastSurface_ref = 78.4006;
	real EXPP_global_ref = 130 + 78.4006;
	real EXPD_ref = 0.7173;
	real Mag_ref = -1.0809;
	real NA_objSpace_ref = 0.0250;
	real ENPP_firstSurface_ref = 0;
	real ENPP_global_ref = 10;
	real ENPD_ref = 0.5;
	real f_number__imaSpace_ref = 87.6722;
	real NA_imaSpace_ref = 0.0231;
	real WFNO_ref = 21.5687;

	real EFL_calc = calcCardinalPointsE12.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE12.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE12.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE12.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE12.getEXPD();
	real Mag_calc = calcCardinalPointsE12.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE12.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE12.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE12.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE12.getENPD();
	real f_number_imaSpace_calc_imaSpace = calcCardinalPointsE12.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE12.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE12.getWorkingFnumber();


	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE12_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE12_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE12_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE12_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE12_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE12_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE12_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE12_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE12_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE12_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc_imaSpace, f_number__imaSpace_ref, mGlobalTolerance);
	checkE12_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE12_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE12_vecBool.push_back(checkWFNO);

	bool checkE12 = Math::checkTrueOfVectorElements(checkE12_vecBool);
	return checkE12;
}

bool testCardinalPoints::testCalcCardinalPointsE13_obj()
{
	std::vector<bool> checkE13_vecBool;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	real defaultWavelength = 550.0;
	Light.setWavelength(defaultWavelength);

	// surfaces E13
	SphericalElement Sphere0_E13(/*radius*/ 20.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAK22_S1());
	SphericalElement Sphere1_E13(/*radius*/ 100.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNLAK22_S1(), /*refractive index B*/glasses.getAir());
	ApertureStopElement AperStop2_E13(/* semi height*/5.0, /*point*/{ 0.0,0.0,30 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere3_E13(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6G05_S1());
	SphericalElement Sphere4_E13(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBAK1_S1(), /*refractive index B*/glasses.getSF6G05_S1());
	SphericalElement Sphere5_E13(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAK1_S1());
	PlanElement Plan6_E13(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

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
	OpticalSystemElement optSystemElement_E13(opticalSystemE13_ptr, interactionsE13_ptr);
	optSystemElement_E13.setRefractiveIndexAccordingToWavelength(defaultWavelength);



	// check the start system
	std::vector<VectorStructR3> fieldPoint_0_vec(1);
	fieldPoint_0_vec[0] = { 0.0,0.0,0.0 };
	std::vector<real> wavelenght_vec(1);
	wavelenght_vec[0] = defaultWavelength;
	std::vector<real> rmsStartSystem{ 2498.85 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E13, fieldPoint_0_vec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE13_vecBool.push_back(checkTheSystem);
	// ***

	CardinalPoints calcCardinalPointsE13(optSystemElement_E13, defaultWavelength, objectPoint_inf_obj::obj);

	real EFL_ref = 27.2711;
	real PP_obj_ref = 36.4825;
	real PP_ima_ref = -39.5184;
	real EXPP_lastSurface_ref = -75.8193;
	real EXPP_global_ref = 70 - 75.8193;
	real EXPD_ref = 36.7335;
	real Mag_ref = -1.1352;
	real NA_objSpace_ref = 0.2149;
	real ENPP_firstSurface_ref = 20.8776;
	real ENPP_global_ref = 20.8776 + 15;
	real ENPD_ref = 15.7909;
	real f_number__imaSpace_ref = 1.7333;
	real NA_imaSpace_ref = 0.1903;
	real WFNO_ref = 2.3513;

	real EFL_calc = calcCardinalPointsE13.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE13.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE13.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE13.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE13.getEXPD();
	real Mag_calc = calcCardinalPointsE13.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE13.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE13.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE13.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE13.getENPD();
	real f_number_imaSpace_calc_imaSpace = calcCardinalPointsE13.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE13.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE13.getWorkingFnumber();


	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE13_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE13_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE13_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE13_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE13_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE13_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE13_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE13_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE13_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE13_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc_imaSpace, f_number__imaSpace_ref, mGlobalTolerance);
	checkE13_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE13_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE13_vecBool.push_back(checkWFNO);

	bool checkE13 = Math::checkTrueOfVectorElements(checkE13_vecBool);
	return checkE13;
}

bool testCardinalPoints::testCalcCardinalPointsE14_obj()
{
	std::vector<bool> checkE14_vecBool;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	real defaultWavelength = 550.0;
	Light.setWavelength(defaultWavelength);

	// surfaces E14
	ApertureStopElement AperStop0_E14(/* semi height*/1.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E14(/*radius*/ 10.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getPSK60_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere2_E14(/*radius*/ 10.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK5_S1(), /*refractive index B*/glasses.getPSK60_S1());
	SphericalElement Sphere3_E14(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF4_S1(), /*refractive index B*/glasses.getNSSK5_S1());
	SphericalElement Sphere4_E14(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNZK7_S1(), /*refractive index B*/glasses.getSF4_S1());
	SphericalElement Sphere5_E14(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNZK7_S1());
	PlanElement Plan6_E14(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

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
	OpticalSystemElement optSystemElement_E14(opticalSystemE14_ptr, interactionsE14_ptr);
	optSystemElement_E14.setRefractiveIndexAccordingToWavelength(defaultWavelength);

	// check single ray
	bool checkSinglRay = oftenUse::checkRayTracing(/*start point ray*/{ 0.0,0.0,0.0 },/*direction ray*/{ 0.0,1.0,5.0 },/*target point*/{ 0.0,4.968,35.0 },/*optical system LLT*/ optSystemElement_E14.getOptSys_LLT_buildSystem(),/*surface num*/ 6,/*tolerance*/ 0.1);
	checkE14_vecBool.push_back(checkSinglRay);


	std::vector<VectorStructR3> fieldPoint_0_vec(1);
	fieldPoint_0_vec[0] = { 0.0,0.0,0.0 };
	std::vector<real> wavelenght_vec(1);
	wavelenght_vec[0] = defaultWavelength;
	std::vector<real> rmsStartSystem{ 3910.71 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E14, fieldPoint_0_vec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE14_vecBool.push_back(checkTheSystem);
	// ***

	CardinalPoints calcCardinalPointsE14(optSystemElement_E14, defaultWavelength, objectPoint_inf_obj::obj);

	real EFL_ref = 20.2972;
	real PP_obj_ref = 20.5756;
	real PP_ima_ref = 10.3214;
	real EXPP_lastSurface_ref = 1509.806;
	real EXPP_global_ref = 35.0 + 1509.806;
	real EXPD_ref = 145.7502;
	real Mag_ref = -3.8453;
	real NA_objSpace_ref = 0.1961;
	real ENPP_firstSurface_ref = 0.0;
	real ENPP_global_ref = 5.0;
	real ENPD_ref = 2.0;
	real f_number__imaSpace_ref = 10.1486;
	real NA_imaSpace_ref = 0.0519;
	real WFNO_ref = 5.5754;

	real EFL_calc = calcCardinalPointsE14.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE14.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE14.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE14.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE14.getEXPD();
	real Mag_calc = calcCardinalPointsE14.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE14.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE14.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE14.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE14.getENPD();
	real f_number_imaSpace_calc_imaSpace = calcCardinalPointsE14.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE14.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE14.getWorkingFnumber();


	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE14_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE14_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE14_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, 1.0 + mGlobalTolerance);
	checkE14_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE14_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE14_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE14_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE14_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE14_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE14_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc_imaSpace, f_number__imaSpace_ref, mGlobalTolerance);
	checkE14_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE14_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE14_vecBool.push_back(checkWFNO);

	bool checkE14 = Math::checkTrueOfVectorElements(checkE14_vecBool);
	return checkE14;

}

bool testCardinalPoints::testCalcCardinalPointsE15_obj()
{
	std::vector<bool> checkE15_vecBool;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	real defaultWavelength = 550.0;
	Light.setWavelength(defaultWavelength);

	// surfaces E15
	SphericalElement Sphere0_E15(/*radius*/ 20.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSFL57_S1());
	SphericalElement Sphere1_E15(/*radius*/ 20.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getF2G12_S1(), /*refractive index B*/glasses.getSFL57_S1());
	SphericalElement Sphere2_E15(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getLASFN9_S1(), /*refractive index B*/glasses.getF2G12_S1());
	SphericalElement Sphere3_E15(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getLASFN9_S1(), /*refractive index B*/glasses.getAir());
	ApertureStopElement AperStop4_E15(/* semi height*/1.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere5_E15(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF11_S1());
	SphericalElement Sphere6_E15(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF11_S1(), /*refractive index B*/glasses.getAir());
	PlanElement Plan7_E15(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

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
	OpticalSystemElement optSystemElement_E15(opticalSystemE15_ptr, interactionsE15_ptr);
	optSystemElement_E15.setRefractiveIndexAccordingToWavelength(defaultWavelength);

	// check the start system
	std::vector<VectorStructR3> fieldPoint_0_vec(1);
	fieldPoint_0_vec[0] = { 0.0,0.0,0.0 };
	std::vector<real> wavelenght_vec(1);
	wavelenght_vec[0] = defaultWavelength;
	std::vector<real> rmsStartSystem{ 2992.53 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E15, fieldPoint_0_vec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE15_vecBool.push_back(checkTheSystem);
	// ***

	CardinalPoints calcCardinalPointsE15(optSystemElement_E15, defaultWavelength, objectPoint_inf_obj::obj);

	real EFL_ref = 22.148;
	real PP_obj_ref = -52.049128;
	real PP_ima_ref = -44.571867;
	real EXPP_lastSurface_ref = -24.98126;
	real EXPP_global_ref = 70 - 24.98126;
	real EXPD_ref = 1.315936;
	real Mag_ref = 0.345;
	real NA_objSpace_ref = 0.04460836;
	real ENPP_firstSurface_ref = 117.6107;
	real ENPP_global_ref = 117.6107 + 10.0;
	real ENPD_ref = 11.39635;
	real f_number__imaSpace_ref = 1.943432;
	real NA_imaSpace_ref = 0.1283577;
	real WFNO_ref = 3.80149;

	real EFL_calc = calcCardinalPointsE15.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE15.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE15.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE15.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE15.getEXPD();
	real Mag_calc = calcCardinalPointsE15.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE15.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE15.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE15.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE15.getENPD();
	real f_number_imaSpace_calc_imaSpace = calcCardinalPointsE15.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE15.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE15.getWorkingFnumber();


	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE15_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE15_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE15_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE15_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE15_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE15_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE15_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE15_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE15_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE15_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc_imaSpace, f_number__imaSpace_ref, mGlobalTolerance);
	checkE15_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE15_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE15_vecBool.push_back(checkWFNO);

	bool checkE15 = Math::checkTrueOfVectorElements(checkE15_vecBool);
	return checkE15;
}

bool testCardinalPoints::testCalcCardinalPointsE16_inf()
{
	std::vector<bool> checkE16_vecBool;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	real defaultWavelength = 550.0;
	Light.setWavelength(defaultWavelength);

	// surfaces E16
	SphericalElement Sphere0_E16(/*radius*/ 10.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF66_S1());
	SphericalElement Sphere1_E16(/*radius*/ 20.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF66_S1());
	SphericalElement Sphere2_E16(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getKZFSN4_S1());
	SphericalElement Sphere3_E16(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getKZFSN4_S1());
	SphericalElement Sphere4_E16(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN6_S1());
	SphericalElement Sphere5_E16(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN6_S1());
	ApertureStopElement AperStop6_E16(/* semi height*/3.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan7_E16(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

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
	OpticalSystemElement optSystemElement_E16(opticalSystemE16_ptr, interactionsE16_ptr);
	optSystemElement_E16.setRefractiveIndexAccordingToWavelength(defaultWavelength);



	// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> wavelenght_vec(1);
	wavelenght_vec[0] = defaultWavelength;
	std::vector<real> rmsStartSystem{ 2581.10 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E16, anglesXvec, anglesYvec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE16_vecBool.push_back(checkTheSystem);
	// ***

	CardinalPoints calcCardinalPointsE16(optSystemElement_E16, defaultWavelength, objectPoint_inf_obj::inf);

	real EFL_ref = 20.211;
	real PP_obj_ref = 22.121718;
	real PP_ima_ref = -106.092074;
	real EXPP_lastSurface_ref = -10;
	real EXPP_global_ref = 60;
	real EXPD_ref = 6.0;
	real Mag_ref = 0.0;
	real NA_objSpace_ref = 0.0;
	real ENPP_firstSurface_ref = -3.472569;
	real ENPP_global_ref = -3.472569;
	real ENPD_ref = 1.59811;
	real f_number__imaSpace_ref = 12.64684;
	real NA_imaSpace_ref = 0.03950471;
	real WFNO_ref = 12.7623;

	real EFL_calc = calcCardinalPointsE16.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE16.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE16.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE16.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE16.getEXPD();
	real Mag_calc = calcCardinalPointsE16.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE16.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE16.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE16.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE16.getENPD();
	real f_number_imaSpace_calc_imaSpace = calcCardinalPointsE16.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE16.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE16.getWorkingFnumber();


	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE16_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE16_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE16_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE16_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE16_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE16_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE16_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE16_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE16_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE16_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc_imaSpace, f_number__imaSpace_ref, mGlobalTolerance);
	checkE16_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE16_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE16_vecBool.push_back(checkWFNO);

	bool checkE16 = Math::checkTrueOfVectorElements(checkE16_vecBool);
	return checkE16;
}

bool testCardinalPoints::testCalcCardinalPointsE17_inf()
{
	std::vector<bool> checkE17_vecBool;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	real defaultWavelength = 550.0;
	Light.setWavelength(defaultWavelength);

	// surfaces E17
	SphericalElement Sphere0_E17(/*radius*/ 99999999999999999.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getLAFN7_S1());
	SphericalElement Sphere1_E17(/*radius*/ 20.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getLAFN7_S1(), /*refractive index B*/glasses.getNBAK4_S1());
	SphericalElement Sphere2_E17(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBAK4_S1(), /*refractive index B*/glasses.getAir());
	ApertureStopElement AperStop3_E17(/* semi height*/0.5, /*point*/{ 0.0,0.0,15 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere4_E17(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK10_S1());
	SphericalElement Sphere5_E17(/*radius*/ 200.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBK10_S1(), /*refractive index B*/glasses.getNLAK10_S1());
	SphericalElement Sphere6_E17(/*radius*/ 300.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAK10_S1());
	PlanElement Plan7_E17(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

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
	OpticalSystemElement optSystemElement_E17(opticalSystemE17_ptr, interactionsE17_ptr);
	optSystemElement_E17.setRefractiveIndexAccordingToWavelength(defaultWavelength);

	// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> wavelenght_vec(1);
	wavelenght_vec[0] = defaultWavelength;
	std::vector<real> rmsStartSystem{ 498.142 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E17, anglesXvec, anglesYvec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE17_vecBool.push_back(checkTheSystem);
	// ***

	CardinalPoints calcCardinalPointsE17(optSystemElement_E17, defaultWavelength, objectPoint_inf_obj::inf);

	real EFL_ref = -58.4281;
	real PP_obj_ref = -1.555353;
	real PP_ima_ref = -31.30745;
	real EXPP_lastSurface_ref = -16.77004;
	real EXPP_global_ref = 35.0 - EXPP_lastSurface_ref;
	real EXPD_ref = 1.064773;
	real Mag_ref = 0.0;
	real NA_objSpace_ref = 0.0;
	real ENPP_firstSurface_ref = 10.08567;
	real ENPP_global_ref = 10.08567;
	real ENPD_ref = 0.8526377;
	real f_number__imaSpace_ref = 68.52631;
	real NA_imaSpace_ref = 0.007296273;
	real WFNO_ref = 68.501;

	real EFL_calc = calcCardinalPointsE17.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE17.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE17.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE17.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE17.getEXPD();
	real Mag_calc = calcCardinalPointsE17.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE17.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE17.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE17.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE17.getENPD();
	real f_number_imaSpace_calc_imaSpace = calcCardinalPointsE17.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE17.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE17.getWorkingFnumber();


	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE17_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE17_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE17_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE17_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE17_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE17_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE17_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE17_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE17_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE17_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc_imaSpace, f_number__imaSpace_ref, mGlobalTolerance);
	checkE17_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE17_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE17_vecBool.push_back(checkWFNO);

	bool checkE17 = Math::checkTrueOfVectorElements(checkE17_vecBool);
	return checkE17;
}

bool testCardinalPoints::testCalcCardinalPointsE18_inf()
{
	std::vector<bool> checkE18_vecBool;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	real defaultWavelength = 550.0;
	Light.setWavelength(defaultWavelength);

	// surfaces E18
	ApertureStopElement AperStop0_E18(/* semi height*/1.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E18(/*radius*/ 10.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,3.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF66_S1());
	SphericalElement Sphere2_E18(/*radius*/ 50.0, /*semi height*/7.0, /*point*/{ 0.0,0.0,8.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF66_S1());
	SphericalElement Sphere3_E18(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,18.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7G18_S1());
	SphericalElement Sphere4_E18(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,23.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getK5G20_S1(), /*refractive index B*/glasses.getBK7G18_S1());
	PlanElement Plan5_E18(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,26.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getK5G20_S1(), /*refractive index B*/ glasses.getAir());
	PlanElement Plan6_E18(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,56.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

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
	OpticalSystemElement optSystemElement_E18(opticalSystemE18_ptr, interactionsE18_ptr);
	optSystemElement_E18.setRefractiveIndexAccordingToWavelength(defaultWavelength);

	//std::cout << "" << std::endl;
	//std::cout << "test system E18" << std::endl;
	//oftenUse::print(optSystemElement_E18, defaultWavelength); 

	// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> wavelenght_vec(1);
	wavelenght_vec[0] = defaultWavelength;
	std::vector<real> rmsStartSystem{ 2916.14 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E18, anglesXvec, anglesYvec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE18_vecBool.push_back(checkTheSystem);
	// ***

	CardinalPoints calcCardinalPointsE18(optSystemElement_E18, defaultWavelength, objectPoint_inf_obj::inf);

	real EFL_ref = 10.0773;
	real PP_obj_ref = 6.6484;
	real PP_ima_ref = -48.4997;
	real EXPP_lastSurface_ref = -68.0388;
	real EXPP_global_ref = 56 - 68.0388;
	real EXPD_ref = 5.8778;
	real Mag_ref = 0.0;
	real NA_objSpace_ref = 0.0;
	real ENPP_firstSurface_ref = 0;
	real ENPP_global_ref = 0;
	real ENPD_ref = 2;
	real f_number__imaSpace_ref = 5.0387;
	real NA_imaSpace_ref = 0.0987;
	real WFNO_ref = 5.0355;

	real EFL_calc = calcCardinalPointsE18.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE18.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE18.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE18.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE18.getEXPD();
	real Mag_calc = calcCardinalPointsE18.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE18.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE18.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE18.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE18.getENPD();
	real f_number_imaSpace_calc_imaSpace = calcCardinalPointsE18.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE18.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE18.getWorkingFnumber();


	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE18_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE18_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE18_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, 1.0 + mGlobalTolerance);
	checkE18_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, 1.0 + mGlobalTolerance);
	checkE18_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE18_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE18_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE18_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE18_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE18_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc_imaSpace, f_number__imaSpace_ref, mGlobalTolerance);
	checkE18_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE18_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE18_vecBool.push_back(checkWFNO);

	bool checkE18 = Math::checkTrueOfVectorElements(checkE18_vecBool);
	return checkE18;
}


bool testCardinalPoints::testCalcCardinalPointsE19_inf()
{
	std::vector<bool> checkE19_vecBool;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	real defaultWavelength = 550.0;
	Light.setWavelength(defaultWavelength);

	SphericalElement Sphere0_E19(/*radius*/ 70, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getLAKL12_S1());
	SphericalElement Sphere1_E19(/*radius*/ 20, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getLAKL12_S1(), /*refractive index B*/glasses.getPBK7_S1());
	SphericalElement Sphere2_E19(/*radius*/ 100, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getPBK7_S1());
	ApertureStopElement AperStop3_E19(/* semi height*/3, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere4_E19(/*radius*/ 10, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getFK3_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere5_E19(/*radius*/ 10, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF1_S1(), /*refractive index B*/glasses.getFK3_S1());
	SphericalElement Sphere6_E19(/*radius*/ 100, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF1_S1());
	PlanElement Plan7_E19(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,110.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

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
	OpticalSystemElement optSystemElement_E19(opticalSystemE19_ptr, interactionsE19_ptr);
	optSystemElement_E19.setRefractiveIndexAccordingToWavelength(defaultWavelength);


	//// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> wavelenght_vec{ defaultWavelength };
	std::vector<real> rmsStartSystem{ 5263.98 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E19, anglesXvec, anglesYvec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE19_vecBool.push_back(checkTheSystem);
	//// ***

	CardinalPoints calcCardinalPointsE19(optSystemElement_E19, defaultWavelength, objectPoint_inf_obj::inf);

	real EFL_ref = -35.2295;
	real PP_obj_ref = 172.6703;
	real PP_ima_ref = -10.7111;
	real EXPP_lastSurface_ref = -34.3585;
	real EXPP_global_ref = 110 - 34.3585;
	real EXPD_ref = 3.3464;
	real Mag_ref = 0.0;
	real NA_objSpace_ref = 0.0;
	real ENPP_firstSurface_ref = 100.7413;
	real ENPP_global_ref = 100.7413;
	real ENPD_ref = 10.1787;
	real f_number_imaSpace_ref = 3.4613;
	real NA_imaSpace_ref = 0.143;
	real WFNO_ref = 3.2541;

	real EFL_calc = calcCardinalPointsE19.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE19.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE19.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE19.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE19.getEXPD();
	real Mag_calc = calcCardinalPointsE19.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE19.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE19.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE19.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE19.getENPD();
	real f_number_imaSpace_calc = calcCardinalPointsE19.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE19.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE19.getWorkingFnumber();


	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE19_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE19_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE19_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE19_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE19_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE19_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE19_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE19_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE19_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE19_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc, f_number_imaSpace_ref, mGlobalTolerance);
	checkE19_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE19_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE19_vecBool.push_back(checkWFNO);

	bool checkE19 = Math::checkTrueOfVectorElements(checkE19_vecBool);
	return checkE19;

}

bool testCardinalPoints::testCalcCardinalPointsE20_inf()
{
	std::vector<bool> checkE20_vecBool;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	real defaultWavelength = 550.0;
	Light.setWavelength(defaultWavelength);

	// surfaces E20
	SphericalElement Sphere0_E20(/*radius*/ 100, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAK21_S1());
	SphericalElement Sphere1_E20(/*radius*/ 100, /*semi height*/7.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAK21_S1());
	SphericalElement Sphere2_E20(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLASF40_S1());
	SphericalElement Sphere3_E20(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNLASF40_S1(), /*refractive index B*/glasses.getAir());
	ApertureStopElement AperStop4_E20(/* semi height*/1.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere5_E20(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAF7_S1());
	SphericalElement Sphere6_E20(/*radius*/ 10.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAF7_S1());
	PlanElement Plan7_E20(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

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
	OpticalSystemElement optSystemElement_E20(opticalSystemE20_ptr, interactionsE20_ptr);
	optSystemElement_E20.setRefractiveIndexAccordingToWavelength(defaultWavelength);



	//// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> wavelenght_vec{ defaultWavelength };
	std::vector<real> rmsStartSystem{ 156.585 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E20, anglesXvec, anglesYvec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE20_vecBool.push_back(checkTheSystem);
	//// ***

	CardinalPoints calcCardinalPointsE6(optSystemElement_E20, defaultWavelength, objectPoint_inf_obj::inf);

	real EFL_ref = 17.8268;
	real PP_obj_ref = 60.2766;
	real PP_ima_ref = -20.0961;
	real EXPP_lastSurface_ref = 95.2435;
	real EXPP_global_ref = 95.2435 + 55;
	real EXPD_ref = 17.0943;
	real Mag_ref = 0.0;
	real NA_objSpace_ref = 0.0;
	real ENPP_firstSurface_ref = 39.1909;
	real ENPP_global_ref = 39.190;
	real ENPD_ref = 3.1251;
	real f_number_imaSpace_ref = 5.7043;
	real NA_imaSpace_ref = 0.0873;
	real WFNO_ref = 5.6797;

	real EFL_calc = calcCardinalPointsE6.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE6.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE6.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE6.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE6.getEXPD();
	real Mag_calc = calcCardinalPointsE6.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE6.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE6.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE6.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE6.getENPD();
	real f_number_imaSpace_calc = calcCardinalPointsE6.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE6.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE6.getWorkingFnumber();


	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE20_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE20_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE20_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE20_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE20_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE20_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE20_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE20_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE20_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE20_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc, f_number_imaSpace_ref, mGlobalTolerance);
	checkE20_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE20_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE20_vecBool.push_back(checkWFNO);

	bool checkE20 = Math::checkTrueOfVectorElements(checkE20_vecBool);
	return checkE20;
}

bool testCardinalPoints::testCalcCardinalPointsE21_inf()
{
	std::vector<bool> checkE21_vecBool;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	real defaultWavelength = 550.0;
	Light.setWavelength(defaultWavelength);

	// surfaces E21
	SphericalElement Sphere0_E21(/*radius*/ 10, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getPLAF37_S1());
	SphericalElement Sphere1_E21(/*radius*/ 10, /*semi height*/7.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getPLAF37_S1(), /*refractive index B*/glasses.getAir());
	ApertureStopElement AperStop2_E21(/* semi height*/2.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere3_E21(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSK4_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere4_E21(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNSK4_S1(), /*refractive index B*/glasses.getSF1_S1());
	SphericalElement Sphere5_E21(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getPSK60_S1(), /*refractive index B*/glasses.getSF1_S1());
	SphericalElement Sphere6_E21(/*radius*/ 5.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getPSK60_S1());
	PlanElement Plan7_E21(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

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
	OpticalSystemElement optSystemElement_E21(opticalSystemE21_ptr, interactionsE21_ptr);
	optSystemElement_E21.setRefractiveIndexAccordingToWavelength(defaultWavelength);



	//// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> wavelenght_vec{ defaultWavelength };
	std::vector<real> rmsStartSystem{ 817.341 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E21, anglesXvec, anglesYvec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE21_vecBool.push_back(checkTheSystem);
	//// ***

	CardinalPoints calcCardinalPointsE21(optSystemElement_E21, defaultWavelength, objectPoint_inf_obj::inf);

	real EFL_ref = 21.7192;
	real PP_obj_ref = 117.6151;
	real PP_ima_ref = -29.6882;
	real EXPP_lastSurface_ref = -2.2988;
	real EXPP_global_ref = 60 - 2.2988;
	real EXPD_ref = 1.4868;
	real Mag_ref = 0.0;
	real NA_objSpace_ref = 0.0;
	real ENPP_firstSurface_ref = 12.70166;
	real ENPP_global_ref = 12.70166;
	real ENPD_ref = 5.6950;
	real f_number_imaSpace_ref = 3.8137;
	real NA_imaSpace_ref = 0.130;
	real WFNO_ref = 4.0514;

	real EFL_calc = calcCardinalPointsE21.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE21.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE21.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE21.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE21.getEXPD();
	real Mag_calc = calcCardinalPointsE21.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE21.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE21.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE21.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE21.getENPD();
	real f_number_imaSpace_calc = calcCardinalPointsE21.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE21.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE21.getWorkingFnumber();


	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE21_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE21_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE21_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE21_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE21_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE21_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE21_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE21_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE21_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE21_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc, f_number_imaSpace_ref, mGlobalTolerance);
	checkE21_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE21_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE21_vecBool.push_back(checkWFNO);

	bool checkE21 = Math::checkTrueOfVectorElements(checkE21_vecBool);
	return checkE21;
}

bool testCardinalPoints::testCalcCardinalPointsE22_inf()
{
	std::vector<bool> checkE22_vecBool;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	real defaultWavelength = 550.0;
	Light.setWavelength(defaultWavelength);

	// surfaces E22
	SphericalElement Sphere0_E22(/*radius*/ 100, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF66_S1());
	SphericalElement Sphere1_E22(/*radius*/ 70, /*semi height*/7.0, /*point*/{ 0.0,0.0,3.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getF2G12_S1(), /*refractive index B*/glasses.getSF66_S1());
	PlanElement Plan2_E22(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,6.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getF2G12_S1(), /*refractive index B*/ glasses.getAir());
	ApertureStopElement AperStop3_E22(/* semi height*/3.0, /*point*/{ 0.0,0.0,16.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan4_E22(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,41.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getPPK53_S1());
	SphericalElement Sphere5_E22(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,43.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getPPK53_S1(), /*refractive index B*/glasses.getNSF19_S1());
	SphericalElement Sphere6_E22(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF19_S1());
	PlanElement Plan7_E22(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,75.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

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
	OpticalSystemElement optSystemElement_E22(opticalSystemE22_ptr, interactionsE22_ptr);
	optSystemElement_E22.setRefractiveIndexAccordingToWavelength(defaultWavelength);



	//// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> wavelenght_vec{ defaultWavelength };
	std::vector<real> rmsStartSystem{ 339.152 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E22, anglesXvec, anglesYvec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE22_vecBool.push_back(checkTheSystem);
	//// ***

	CardinalPoints calcCardinalPointsE22(optSystemElement_E22, defaultWavelength, objectPoint_inf_obj::inf);

	real EFL_ref = 53.0492;
	real PP_obj_ref = 24.684;
	real PP_ima_ref = -59.4145;
	real EXPP_lastSurface_ref = -69.559;
	real EXPP_global_ref = 75 - 69.559;
	real EXPD_ref = 8.6766;
	real Mag_ref = 0.0;
	real NA_objSpace_ref = 0.0;
	real ENPP_firstSurface_ref = 16.1683;
	real ENPP_global_ref = 16.1683;
	real ENPD_ref = 7.2837;
	real f_number_imaSpace_ref = 7.2832;
	real NA_imaSpace_ref = 0.0685;
	real WFNO_ref = 7.2760;

	real EFL_calc = calcCardinalPointsE22.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE22.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE22.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE22.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE22.getEXPD();
	real Mag_calc = calcCardinalPointsE22.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE22.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE22.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE22.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE22.getENPD();
	real f_number_imaSpace_calc = calcCardinalPointsE22.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE22.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE22.getWorkingFnumber();


	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, 1.0 + mGlobalTolerance);
	checkE22_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, 2.0 + mGlobalTolerance);
	checkE22_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE22_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE22_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE22_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE22_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE22_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE22_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE22_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE22_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc, f_number_imaSpace_ref, mGlobalTolerance);
	checkE22_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE22_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE22_vecBool.push_back(checkWFNO);

	bool checkE22 = Math::checkTrueOfVectorElements(checkE22_vecBool);
	return checkE22;
}

bool testCardinalPoints::testCalcCardinalPointsE23_inf()
{
	std::vector<bool> checkE23_vecBool;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	real defaultWavelength = 550.0;
	Light.setWavelength(defaultWavelength);

	// surfaces E23
	ApertureStopElement AperStop0_E23(/* semi height*/1.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E23(/*radius*/ 200, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getLF5_S1());
	SphericalElement Sphere2_E23(/*radius*/ 5, /*semi height*/7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK10_S1(), /*refractive index B*/glasses.getLF5_S1());
	SphericalElement Sphere3_E23(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBAK4_S1(), /*refractive index B*/glasses.getNBK10_S1());
	SphericalElement Sphere4_E23(/*radius*/ 3.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBAK4_S1(), /*refractive index B*/glasses.getLLF1_S1());
	SphericalElement Sphere5_E23(/*radius*/ 4.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getLLF1_S1());
	PlanElement Plan6_E23(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,90.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

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
	OpticalSystemElement optSystemElement_E23(opticalSystemE23_ptr, interactionsE23_ptr);
	optSystemElement_E23.setRefractiveIndexAccordingToWavelength(defaultWavelength);



	//// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> wavelenght_vec{ defaultWavelength };
	std::vector<real> rmsStartSystem{ 10.693 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E23, anglesXvec, anglesYvec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE23_vecBool.push_back(checkTheSystem);
	//// ***

	CardinalPoints calcCardinalPointsE23(optSystemElement_E23, defaultWavelength, objectPoint_inf_obj::inf);

	real EFL_ref = 18.1429;
	real PP_obj_ref = 122.6035;
	real PP_ima_ref = -17.7721;
	real EXPP_lastSurface_ref = 3.5218;
	real EXPP_global_ref = 90 + 3.5218;
	real EXPD_ref = 0.3473587;
	real Mag_ref = 0.0;
	real NA_objSpace_ref = 0.0;
	real ENPP_firstSurface_ref = 0.0;
	real ENPP_global_ref = 0.0;
	real ENPD_ref = 2.0;
	real f_number_imaSpace_ref = 9.071452;
	real NA_imaSpace_ref = 0.05503444;
	real WFNO_ref = 9.32514;

	real EFL_calc = calcCardinalPointsE23.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE23.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE23.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE23.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE23.getEXPD();
	real Mag_calc = calcCardinalPointsE23.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE23.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE23.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE23.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE23.getENPD();
	real f_number_imaSpace_calc = calcCardinalPointsE23.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE23.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE23.getWorkingFnumber();


	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE23_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE23_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE23_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE23_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE23_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE23_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE23_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE23_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE23_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE23_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc, f_number_imaSpace_ref, mGlobalTolerance);
	checkE23_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE23_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE23_vecBool.push_back(checkWFNO);

	bool checkE23 = Math::checkTrueOfVectorElements(checkE23_vecBool);
	return checkE23;
}

bool testCardinalPoints::testCalcCardinalPointsE24_inf()
{
	std::vector<bool> checkE24_vecBool;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	real defaultWavelength = 550.0;
	Light.setWavelength(defaultWavelength);

	// surfaces E24
	SphericalElement Sphere0_E24(/*radius*/ 250, /*semi height*/ 50.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLASF45_S1());
	SphericalElement Sphere1_E24(/*radius*/ 250, /*semi height*/50.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLASF45_S1());
	SphericalElement Sphere2_E24(/*radius*/ 150.00, /*semi height*/ 50.0, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNPSK3_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere3_E24(/*radius*/ 100.00, /*semi height*/ 50.0, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNPSK3_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere4_E24(/*radius*/ 60.00, /*semi height*/ 50, /*point*/{ 0.0,0.0,280.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF1_S1());
	SphericalElement Sphere5_E24(/*radius*/ 100.00, /*semi height*/ 50, /*point*/{ 0.0,0.0,315.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNSF1_S1(), /*refractive index B*/glasses.getAir());
	ApertureStopElement AperStop6_E24(/* semi height*/10.0, /*point*/{ 0.0,0.0,390.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan7_E24(/*semi height*/ 50.0, /*point*/{ 0.0,0.0,410.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

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
	OpticalSystemElement optSystemElement_E24(opticalSystemE24_ptr, interactionsE24_ptr);
	optSystemElement_E24.setRefractiveIndexAccordingToWavelength(defaultWavelength);



	//// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> wavelenght_vec{ defaultWavelength };
	std::vector<real> rmsStartSystem{ 8351.81 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E24, anglesXvec, anglesYvec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE24_vecBool.push_back(checkTheSystem);
	//// ***

	CardinalPoints calcCardinalPointsE24(optSystemElement_E24, defaultWavelength, objectPoint_inf_obj::inf);

	real EFL_ref = 417.325;
	real PP_obj_ref = 615.3224;
	real PP_ima_ref = -624.8682;
	real EXPP_lastSurface_ref = -20.001;
	real EXPP_global_ref = 410 - 20.001;
	real EXPD_ref = 20.0;
	real Mag_ref = 0.0;
	real NA_objSpace_ref = 0.0;
	real ENPP_firstSurface_ref = -730.6479;
	real ENPP_global_ref = -730.6479;
	real ENPD_ref = 44.5046;
	real f_number_imaSpace_ref = 9.3771;
	real NA_imaSpace_ref = 0.0532;
	real WFNO_ref = 10.5016;

	real EFL_calc = calcCardinalPointsE24.getEFL();
	real PP_objSpace_calc = calcCardinalPointsE24.getPP_obj();
	real PP_imageSpace_calc = calcCardinalPointsE24.getPP_ima();
	real EXPP_LastSurface_calc = calcCardinalPointsE24.getEXPP_lastSurface();
	real EXPD_calc = calcCardinalPointsE24.getEXPD();
	real Mag_calc = calcCardinalPointsE24.getMagnification();
	real NA_objSpace_calc = calcCardinalPointsE24.getNA_objSpace();
	real ENPP_firstSurface_calc = calcCardinalPointsE24.getENPP_firstSurface();
	real ENPP_global_calc = calcCardinalPointsE24.getENPP_globalCoodi();
	real ENPD_calc = calcCardinalPointsE24.getENPD();
	real f_number_imaSpace_calc = calcCardinalPointsE24.getF_num_imaSpace();
	real NA_imaSpace_calc = calcCardinalPointsE24.getNA_imaSpace();
	real WFNO_calc = calcCardinalPointsE24.getWorkingFnumber();


	bool checkEFL = Math::compareTwoNumbers_tolerance(EFL_ref, EFL_calc, mGlobalTolerance);
	checkE24_vecBool.push_back(checkEFL);
	bool checkPP = Math::compareTwoNumbers_tolerance(PP_obj_ref, PP_objSpace_calc, mGlobalTolerance);
	checkE24_vecBool.push_back(checkPP);
	bool checkAntiPP = Math::compareTwoNumbers_tolerance(PP_ima_ref, PP_imageSpace_calc, mGlobalTolerance);
	checkE24_vecBool.push_back(checkAntiPP);
	bool checkEXPP = Math::compareTwoNumbers_tolerance(EXPP_lastSurface_ref, EXPP_LastSurface_calc, mGlobalTolerance);
	checkE24_vecBool.push_back(checkEXPP);
	bool checkEXPD = Math::compareTwoNumbers_tolerance(EXPD_ref, EXPD_calc, mGlobalTolerance);
	checkE24_vecBool.push_back(checkEXPD);
	bool checkMag = Math::compareTwoNumbers_tolerance(Mag_ref, Mag_calc, mGlobalTolerance);
	checkE24_vecBool.push_back(checkMag);
	bool checkNA_objSpac = Math::compareTwoNumbers_tolerance(NA_objSpace_ref, NA_objSpace_calc, mGlobalTolerance);
	checkE24_vecBool.push_back(checkNA_objSpac);
	bool checkENPP_firstSurface = Math::compareTwoNumbers_tolerance(ENPP_firstSurface_ref, ENPP_firstSurface_calc, mGlobalTolerance);
	checkE24_vecBool.push_back(checkENPP_firstSurface);
	bool checkENPP_globalCoordi = Math::compareTwoNumbers_tolerance(ENPP_global_ref, ENPP_global_calc, mGlobalTolerance);
	checkE24_vecBool.push_back(checkENPP_globalCoordi);
	bool checkENPD = Math::compareTwoNumbers_tolerance(ENPD_ref, ENPD_calc, mGlobalTolerance);
	checkE24_vecBool.push_back(checkENPD);
	bool checkF_number_imaSpace = Math::compareTwoNumbers_tolerance(f_number_imaSpace_calc, f_number_imaSpace_ref, mGlobalTolerance);
	checkE24_vecBool.push_back(checkF_number_imaSpace);
	bool checkNA_imaSpace = Math::compareTwoNumbers_tolerance(NA_imaSpace_ref, NA_imaSpace_calc, mGlobalTolerance);
	checkE24_vecBool.push_back(checkNA_imaSpace);
	bool checkWFNO = Math::compareTwoNumbers_tolerance(WFNO_ref, WFNO_calc, mGlobalTolerance);
	checkE24_vecBool.push_back(checkWFNO);

	bool checkE24 = Math::checkTrueOfVectorElements(checkE24_vecBool);
	return checkE24;
}



