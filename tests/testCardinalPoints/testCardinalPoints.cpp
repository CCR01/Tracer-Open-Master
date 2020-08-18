
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
typedef std::shared_ptr< InteractionRay_LLT > interactionPtr;

testCardinalPoints::testCardinalPoints() 
{ 
	mGlobalTolerance = 0.1;
	mGlobalToleranceExtender = 1.0;
}

testCardinalPoints::~testCardinalPoints() {}


bool testCardinalPoints::superFuncTestCalcCardinalPoints()
{
	std::vector<bool> checkCalcCardinal;

	//bool testE0 = testCalcCardinalPointsE0_obj();
	//checkCalcCardinal.push_back(testE0);
	//bool testE1 = testCalcCardinalPointsE1_obj();
	//checkCalcCardinal.push_back(testE1);
	//bool testE2 = testCalcCardinalPointsE2_obj();
	//checkCalcCardinal.push_back(testE2);
	//bool testE3 = testCalcCardinalPointsE3_obj();
	//checkCalcCardinal.push_back(testE3);
	//bool testE4 =testCalcCardinalPointsE4_obj();
	//checkCalcCardinal.push_back(testE4);
	//bool testE5 = testCalcCardinalPointsE5_obj();
	//checkCalcCardinal.push_back(testE5);
	//bool testE6 = testCalcCardinalPointsE6_inf();
	//checkCalcCardinal.push_back(testE6);
	//bool testE7 = testCalcCardinalPointsE7_inf();
	//checkCalcCardinal.push_back(testE7);
	bool testE8 = testCalcCardinalPointsE8_inf();
	checkCalcCardinal.push_back(testE8);

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
	std::vector<interactionPtr> interactionsE4_ptr{ refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

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
	std::vector<interactionPtr> interactionsE5_ptr{ refrac.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),doNothing.clone(),absorb.clone() };

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
	std::vector<interactionPtr> interactionsE6_ptr{ refrac.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), doNothing.clone(), refrac.clone(),refrac.clone(),refrac.clone(), absorb.clone() };

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

	// surfaces E6
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
	std::vector<interactionPtr> interactionsE7_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

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

	// surfaces E6
	SphericalElement Sphere0_E8(/*radius*/ 60, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,00.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF4_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere1_E8(/*radius*/ 150, /*semi height*/7.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF4_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2_E8(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere3_E8(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere4_E8(/*radius*/ 20.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	ApertureStopElement AperStop5_E8(/* semi height*/3.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	PlanElement Plan6_E8(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	surfacePtr Sphere0_E8_ptr = Sphere0_E8.clone();
	surfacePtr Sphere1_E8_ptr = Sphere1_E8.clone();
	surfacePtr Sphere2_E8_ptr = Sphere2_E8.clone();
	surfacePtr Sphere3_E8_ptr = Sphere3_E8.clone();
	surfacePtr Sphere4_E8_ptr = Sphere4_E8.clone();
	surfacePtr Aper5_E8_ptr = AperStop5_E8.clone();
	surfacePtr Plan6_E8_ptr = Plan6_E8.clone();

	std::vector<surfacePtr> opticalSystemE8_ptr{ Sphere0_E8_ptr, Sphere1_E8_ptr, Sphere2_E8_ptr , Sphere3_E8_ptr, Sphere4_E8_ptr, Aper5_E8_ptr, Plan6_E8_ptr };
	std::vector<interactionPtr> interactionsE8_ptr{ refrac.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), doNothing.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E8(opticalSystemE8_ptr, interactionsE8_ptr);
	optSystemElement_E8.setRefractiveIndexAccordingToWavelength(defaultWavelength);

	//// check the start system
	std::vector<real> anglesXvec{ 0.0 };
	std::vector<real> anglesYvec{ 0.0 };
	std::vector<real> wavelenght_vec{ defaultWavelength };
	std::vector<real> rmsStartSystem{ 804.551 };
	bool checkTheSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E8, anglesXvec, anglesYvec, wavelenght_vec, rmsStartSystem, mGlobalToleranceExtender, compareTOM_Zemax::comEqual);
	checkE8_vecBool.push_back(checkTheSystem);
	//// ***

	CardinalPoints calcCardinalPointsE8(optSystemElement_E8, defaultWavelength, objectPoint_inf_obj::inf);

	real EFL_ref = 34.1126;
	real PP_obj_ref = 23.397838;
	real PP_ima_ref = -21.588775;
	real EXPP_lastSurface_ref = -20.0;
	real EXPP_global_ref = 55.0;
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