#include "testAsphericalSurface_LLT.h"
#include <iostream>
#include "..\..\LowLevelTracing\Surfaces\AsphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ParaxialLens_LLT.h"

#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"

#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DeflectedRayParaxialLens_LLT.h"

#include "..\..\FillAptertureStop\FillApertureStop.h"
#include "..\..\Analyse\Spot.h"

testAsphericalSurface_LLT::testAsphericalSurface_LLT() {};
testAsphericalSurface_LLT::~testAsphericalSurface_LLT() {};



bool testAsphericalSurface_LLT::checkAsphericalSurfaceSuperFct_LLT()
{
	std::vector<bool> testAspSur_LLT;

	// E0
	bool checkE0 = checkAsphere_LLT_E0();
	testAspSur_LLT.push_back(checkE0);
	// E1
	bool checkE1 = checkAsphere_LLT_E1();
	testAspSur_LLT.push_back(checkE1);
	// E2
	bool checkE2 = checkAsphere_LLT_E2();
	testAspSur_LLT.push_back(checkE2);
	// E3
	bool checkE3 = checkAsphere_LLT_E3();
	testAspSur_LLT.push_back(checkE3);
	// E4
	bool checkE4 = checkAsphere_LLT_E4();
	testAspSur_LLT.push_back(checkE4);
	


	bool workTheAsphere_LLT = Math::checkTrueOfVectorElements(testAspSur_LLT);
	return workTheAsphere_LLT;

}

// E0
bool testAsphericalSurface_LLT::checkAsphere_LLT_E0()
{
	std::vector<bool> testAspSur_LLT;
	Light_LLT Light;
	Light.buildDefaultLight();
	// interactions
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;

	//*****
	//E0
	//*****

	// surfaces
	AsphericalSurface_LLT S0E0(/*radius*/ 1.7, /*semi height*/ 1.0,/*point*/{ 0.0,0.0,32.0 }, /*direction*/{ 0.0,0.0,1.0 },/*refractive index A*/ 1.0,/*refractive index B*/ 1.5,/*conic*/ 1.0,
		/*second order term*/ -0.2, /*fourth order term*/ -0.12, /*sixth order term*/ 0.044, /*eighth order term*/ 0.02,/*tenth order term*/ -0.04,/*twelfth oder term*/ 0.0,
		/*fourteenth order term*/0.0,/*sixteenth order tem*/ 0.0);
	PlanGeometry_LLT S1E0(/*semi height*/ 1.0,/*point*/{ 0.0,0.0,37.0 },/*direction*/{ 0.0,0.0,1.0 },/*refractive index A*/ 1.5, /*refractive index B*/ 1.0);
	PlanGeometry_LLT S2E0(/*semi height*/ 5.0,/*point*/{ 0.0,0.0,62.0 },/*direction*/{ 0.0,0.0,1.0 },/*refractive index A*/ 1.0, /*refractive index B*/ 1.0);

	// build optical system
	OpticalSystem_LLT optSysE0;
	optSysE0.fillVectorSurfaceAndInteractingData(0, S0E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(1, S1E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(2, S2E0.clone(), refrac.clone());

	// optical axis
	SequentialRayTracing seqTraceE0_optA(optSysE0);
	FillApertureStop fillAperStopE0_optA(/*start point rays*/{ 0.0,0.0,0.0 },/*semi height of aperture stop*/ 0.5,/*point of aperture stop*/{ 0.0,0.0,30.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/6,/*arms*/ 8,/*refractive index*/ 1.0, Light);
	seqTraceE0_optA.seqRayTracingWithVectorOfLightRays(fillAperStopE0_optA.getVectorWithLightRays());
	Spot spotE0_optA(/*intersection points*/ seqTraceE0_optA.getAllInterPointsAtSurf_i_notFiltered(2), /*reference point*/seqTraceE0_optA.getAllInterPointsAtSurf_i_notFiltered(2).at(0));
	real rmsImageE0_optA = spotE0_optA.getRMS_mm();
	real tartgetZemaxE0_optA = 0.107282;
	bool checkE0_optA = Math::compareTwoNumbers_decimals(tartgetZemaxE0_optA, rmsImageE0_optA, 6);
	testAspSur_LLT.push_back(checkE0_optA);
	// ---

	// fild Y=1
	SequentialRayTracing seqTraceE0_fieldY1(optSysE0);
	FillApertureStop fillAperStopE0_fieldY1(/*start point rays*/{ 0.0,1.0,0.0 },/*semi height of aperture stop*/ 0.5,/*point of aperture stop*/{ 0.0,0.0,30.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/6,/*arms*/ 8,/*refractive index*/ 1.0, Light);
	seqTraceE0_fieldY1.seqRayTracingWithVectorOfLightRays(fillAperStopE0_fieldY1.getVectorWithLightRays());
	Spot spotE0_fieldY1(/*intersection points*/ seqTraceE0_fieldY1.getAllInterPointsAtSurf_i_notFiltered(2), /*reference point*/seqTraceE0_fieldY1.getAllInterPointsAtSurf_i_notFiltered(2).at(0));
	real rmsImageE0_fieldY1 = spotE0_fieldY1.getRMS_mm();
	real tartgetZemaxE0_fieldY1 = 0.116111;
	bool checkE0_fieldY1 = Math::compareTwoNumbers_decimals(tartgetZemaxE0_fieldY1, rmsImageE0_fieldY1, 6);
	testAspSur_LLT.push_back(checkE0_fieldY1);
	// ---

	bool returnCheck = Math::checkTrueOfVectorElements(testAspSur_LLT);
	return returnCheck;

}
// E1
bool testAsphericalSurface_LLT::checkAsphere_LLT_E1()
{
	std::vector<bool> testAspSur_LLT;
	Light_LLT Light;
	Light.buildDefaultLight();
	// interactions
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;


	//*****
	//E1
	//*****
	// surfaces
	PlanGeometry_LLT S0E1(/*semi height*/ 1.0,/*point*/{ 0.0,0.0,32.0 },/*direction*/{ 0.0,0.0,1.0 },/*refractive index A*/ 1.0, /*refractive index B*/ 1.5);
	AsphericalSurface_LLT S1E1(/*radius*/ 5.0, /*semi height*/ 1.0,/*point*/{ 0.0,0.0,37.0 }, /*direction*/{ 0.0,0.0,-1.0 },/*refractive index A*/ 1.0,/*refractive index B*/ 1.5,/*conic*/ -1.0,
		/*second order term*/ 0.02, /*fourth order term*/ 0.02, /*sixth order term*/ -0.01, /*eighth order term*/ -0.01,/*tenth order term*/ 0.01,/*twelfth oder term*/ 0.01,
		/*fourteenth order term*/0.01,/*sixteenth order tem*/ 0.01);
	PlanGeometry_LLT S2E1(/*semi height*/ 5.0,/*point*/{ 0.0,0.0,62.0 },/*direction*/{ 0.0,0.0,1.0 },/*refractive index A*/ 1.0, /*refractive index B*/ 1.0);

	// build optical system
	OpticalSystem_LLT optSysE1;
	optSysE1.fillVectorSurfaceAndInteractingData(0, S0E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(1, S1E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(2, S2E1.clone(), refrac.clone());

	// optical axis
	//single ray tracing
	Ray_LLT rayE1(/*origin*/{ 0.0,0.5,0.0 },/*direction*/{ 0.0,0.0,1.0 },/*refractive index*/ 1.0);
	Light.setWavelength(550.0);
	LightRayStruct lightRay(Light, rayE1, true);
	SequentialRayTracing seqTraceE1_optA_single(optSysE1);
	seqTraceE1_optA_single.sequentialRayTracing(lightRay);
	VectorStructR3 imagePoint = seqTraceE1_optA_single.getAllInterPointsAtSurf_i_notFiltered(2).at(0);
	VectorStructR3 targetSingleE1 = { 0.0,-0.40525889187,62.0 };
	bool checkSingleE0 = Math::compareTwoVectorStructR3_decimals(targetSingleE1, imagePoint, 6);
	testAspSur_LLT.push_back(checkSingleE0);

	// ---
	SequentialRayTracing seqTraceE1_optA(optSysE1);
	FillApertureStop fillAperStopE1_optA(/*start point rays*/{ 0.0,0.0,0.0 },/*semi height of aperture stop*/ 0.5,/*point of aperture stop*/{ 0.0,0.0,30.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/6,/*arms*/ 8,/*refractive index*/ 1.0, Light);
	seqTraceE1_optA.seqRayTracingWithVectorOfLightRays(fillAperStopE1_optA.getVectorWithLightRays());
	Spot spotE1_optA(/*intersection points*/ seqTraceE1_optA.getAllInterPointsAtSurf_i_notFiltered(2), /*reference point*/seqTraceE1_optA.getAllInterPointsAtSurf_i_notFiltered(2).at(0));
	real rmsImageE1_optA = spotE1_optA.getRMS_mm();
	real tartgetZemaxE1_optA = 0.049435;
	bool checkE1_optA = Math::compareTwoNumbers_decimals(tartgetZemaxE1_optA, rmsImageE1_optA, 6);
	testAspSur_LLT.push_back(checkE1_optA);
	// ---

	// ---
	SequentialRayTracing seqTraceE1_fieldYneg1(optSysE1);
	FillApertureStop fillAperStopE1_fieldYneg1(/*start point rays*/{ 0.0,-1.0,0.0 },/*semi height of aperture stop*/ 0.5,/*point of aperture stop*/{ 0.0,0.0,30.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/6,/*arms*/ 8,/*refractive index*/ 1.0, Light);
	seqTraceE1_fieldYneg1.seqRayTracingWithVectorOfLightRays(fillAperStopE1_fieldYneg1.getVectorWithLightRays());
	Spot spotE1_fieldYneg1(/*intersection points*/ seqTraceE1_fieldYneg1.getAllInterPointsAtSurf_i_notFiltered(2), /*reference point*/seqTraceE1_fieldYneg1.getAllInterPointsAtSurf_i_notFiltered(2).at(0));
	real rmsImageE1_fieldYneg1 = spotE1_fieldYneg1.getRMS_mm();
	real tartgetZemaxE1_fieldYneg1 = 0.078751;
	bool checkE1_fieldYneg1 = Math::compareTwoNumbers_decimals(tartgetZemaxE1_fieldYneg1, rmsImageE1_fieldYneg1, 6);
	testAspSur_LLT.push_back(checkE1_fieldYneg1);
	// ---

	bool returnCheck = Math::checkTrueOfVectorElements(testAspSur_LLT);
	return returnCheck;

}
// E2
bool testAsphericalSurface_LLT::checkAsphere_LLT_E2()
{
	std::vector<bool> testAspSur_LLT;
	Light_LLT Light;
	Light.buildDefaultLight();
	// interactions
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;


	//*****
	//E2
	//*****
	// surfaces
	SphericalSurface_LLT S0E2(/*radius*/ 5.0,/*semi height*/ 1.0,/*point*/{ 0.0,0.0,32.0 }, /*direction*/{ 0.0,0.0,1.0 },/*refractive index A*/ 1.0,/*refractive index B*/ 1.5);
	AsphericalSurface_LLT S1E2(/*radius*/ 20.0, /*semi height*/ 1.0,/*point*/{ 0.0,0.0,37.0 }, /*direction*/{ 0.0,0.0,1.0 },/*refractive index A*/ 1.5,/*refractive index B*/ 1.0,/*conic*/ 1.0,
		/*second order term*/ 0.02, /*fourth order term*/ 0.008, /*sixth order term*/ 0.0006, /*eighth order term*/ -0.01,/*tenth order term*/ 0.01,/*twelfth oder term*/ -0.2,
		/*fourteenth order term*/0.25,/*sixteenth order tem*/ -0.2);
	PlanGeometry_LLT S2E2(/*semi height*/ 5.0,/*point*/{ 0.0,0.0,62.0 },/*direction*/{ 0.0,0.0,1.0 },/*refractive index A*/ 1.0, /*refractive index B*/ 1.0);

	// build optical system
	OpticalSystem_LLT optSysE2;
	optSysE2.fillVectorSurfaceAndInteractingData(0, S0E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(1, S1E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(2, S2E2.clone(), refrac.clone());

	//single ray tracing
	Ray_LLT rayE2(/*origin*/{ 0.0,-0.5,0.0 },/*direction*/{ 0.0,0.0,1.0 },/*refractive index*/ 1.0);
	LightRayStruct lightRayE2(Light, rayE2, 1);
	SequentialRayTracing seqTraceE2_optA_single(optSysE2);
	seqTraceE2_optA_single.sequentialRayTracing(lightRayE2);
	IntersectInformationStruct interInfosE2 = seqTraceE2_optA_single.getAllInterInfosOfSurf_i_notFiltered(1).at(0);
	VectorStructR3 imagePointE2 = seqTraceE2_optA_single.getAllInterPointsAtSurf_i_notFiltered(2).at(0);
	VectorStructR3 targetSingleE2 = { 0.0,0.53182903026,62.0 };
	bool checkSingleE2 = Math::compareTwoVectorStructR3_decimals(targetSingleE2, imagePointE2, 6);
	testAspSur_LLT.push_back(checkSingleE2);

	// ---
	SequentialRayTracing seqTraceE2_optA(optSysE2);
	FillApertureStop fillAperStopE2_optA(/*start point rays*/{ 0.0,0.0,0.0 },/*semi height of aperture stop*/ 0.5,/*point of aperture stop*/{ 0.0,0.0,30.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/6,/*arms*/ 8,/*refractive index*/ 1.0, Light);
	seqTraceE2_optA.seqRayTracingWithVectorOfLightRays(fillAperStopE2_optA.getVectorWithLightRays());
	Spot spotE2_optA(/*intersection points*/ seqTraceE2_optA.getAllInterPointsAtSurf_i_notFiltered(2), /*reference point*/seqTraceE2_optA.getAllInterPointsAtSurf_i_notFiltered(2).at(0));
	real rmsImageE2_optA = spotE2_optA.getRMS_mm();
	real tartgetZemaxE2_optA = 0.022677;
	bool checkE2_optA = Math::compareTwoNumbers_decimals(tartgetZemaxE2_optA, rmsImageE2_optA, 6);
	testAspSur_LLT.push_back(checkE2_optA);
	// ---

	// ---
	SequentialRayTracing seqTraceE2_Xneg05_Y05(optSysE2);
	FillApertureStop fillAperStopE2_Xneg05_Y05(/*start point rays*/{ -0.5,0.5,0.0 },/*semi height of aperture stop*/ 0.5,/*point of aperture stop*/{ 0.0,0.0,30.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/6,/*arms*/ 8,/*refractive index*/ 1.0, Light);
	seqTraceE2_Xneg05_Y05.seqRayTracingWithVectorOfLightRays(fillAperStopE2_Xneg05_Y05.getVectorWithLightRays());
	Spot spotE2_Xneg05_Y05(/*intersection points*/ seqTraceE2_Xneg05_Y05.getAllInterPointsAtSurf_i_notFiltered(2), /*reference point*/seqTraceE2_Xneg05_Y05.getAllInterPointsAtSurf_i_notFiltered(2).at(0));
	real rmsImageE2_Xneg05_Y05 = spotE2_Xneg05_Y05.getRMS_mm();
	real tartgetZemaxE2_Xneg05_Y05 = 0.023127;
	bool checkE2_Xneg05_Y05 = Math::compareTwoNumbers_decimals(tartgetZemaxE2_Xneg05_Y05, rmsImageE2_Xneg05_Y05, 6);
	testAspSur_LLT.push_back(checkE2_Xneg05_Y05);
	// ---

	bool returnCheck = Math::checkTrueOfVectorElements(testAspSur_LLT);
	return returnCheck;

}

// E3
bool testAsphericalSurface_LLT::checkAsphere_LLT_E3()
{
	std::vector<bool> testAspSur_LLT;
	Light_LLT Light;
	Light.buildDefaultLight();
	// interactions
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;


	//*****
	//E3
	//*****
	// surfaces
	AsphericalSurface_LLT S0E3(/*radius*/ 20.0, /*semi height*/ 1.0,/*point*/{ 0.0,0.0,32.0 }, /*direction*/{ 0.0,0.0,-1.0 },/*refractive index A*/ 1.5,/*refractive index B*/ 1.0,/*conic*/ 1.0,
		/*second order term*/ -0.02, /*fourth order term*/ -0.008, /*sixth order term*/ -0.0006, /*eighth order term*/ 0.01,/*tenth order term*/ -0.01,/*twelfth oder term*/ 0.2,
		/*fourteenth order term*/-0.25,/*sixteenth order tem*/ 0.2);
	SphericalSurface_LLT S1E3(/*radius*/ 5.0,/*semi height*/ 1.0,/*point*/{ 0.0,0.0,37.0 }, /*direction*/{ 0.0,0.0,-1.0 },/*refractive index A*/ 1.0,/*refractive index B*/ 1.5);
	PlanGeometry_LLT S2E3(/*semi height*/ 5.0,/*point*/{ 0.0,0.0,62.0 },/*direction*/{ 0.0,0.0,1.0 },/*refractive index A*/ 1.0, /*refractive index B*/ 1.0);

	// build optical system
	OpticalSystem_LLT optSysE3;
	optSysE3.fillVectorSurfaceAndInteractingData(0, S0E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(1, S1E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(2, S2E3.clone(), refrac.clone());

	//single ray tracing
	Ray_LLT rayE3(/*origin*/{ 0.0,0.5,0.0 },/*direction*/{ 0.0,0.0,1.0 },/*refractive index*/ 1.0);
	LightRayStruct lightRayE3(Light, rayE3, 1);
	SequentialRayTracing seqTraceE3_optA_single(optSysE3);
	seqTraceE3_optA_single.sequentialRayTracing(lightRayE3);
	IntersectInformationStruct interInfosE3 = seqTraceE3_optA_single.getAllInterInfosOfSurf_i_notFiltered(1).at(0);
	VectorStructR3 imagePointE3 = seqTraceE3_optA_single.getAllInterPointsAtSurf_i_notFiltered(2).at(0);
	VectorStructR3 targetSingleE3 = { 0.0,-0.28378330415,62.0 };
	bool checkSingleE3 = Math::compareTwoVectorStructR3_decimals(targetSingleE3, imagePointE3, 6);
	testAspSur_LLT.push_back(checkSingleE3);

	// ray tracing optica axis
	SequentialRayTracing seqTraceE3_optA(optSysE3);
	FillApertureStop fillAperStopE3_optA(/*start point rays*/{ 0.0,0.0,0.0 },/*semi height of aperture stop*/ 0.5,/*point of aperture stop*/{ 0.0,0.0,30.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/6,/*arms*/ 8,/*refractive index*/ 1.0, Light);
	seqTraceE3_optA.seqRayTracingWithVectorOfLightRays(fillAperStopE3_optA.getVectorWithLightRays());
	Spot spotE3_optA(/*intersection points*/ seqTraceE3_optA.getAllInterPointsAtSurf_i_notFiltered(2), /*reference point*/seqTraceE3_optA.getAllInterPointsAtSurf_i_notFiltered(2).at(0));
	real rmsImageE3_optA = spotE3_optA.getRMS_mm();
	real tartgetZemaxE3_optA = 0.021009;
	bool checkE3_optA = Math::compareTwoNumbers_decimals(tartgetZemaxE3_optA, rmsImageE3_optA, 6);
	testAspSur_LLT.push_back(checkE3_optA);

	// ---
	SequentialRayTracing seqTraceE3_X05_Y05(optSysE3);
	FillApertureStop fillAperStopE3_X05_Y05(/*start point rays*/{ 0.5,0.5,0.0 },/*semi height of aperture stop*/ 0.5,/*point of aperture stop*/{ 0.0,0.0,30.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/6,/*arms*/ 8,/*refractive index*/ 1.0, Light);
	seqTraceE3_X05_Y05.seqRayTracingWithVectorOfLightRays(fillAperStopE3_X05_Y05.getVectorWithLightRays());
	Spot spotE3_X05_Y05(/*intersection points*/ seqTraceE3_X05_Y05.getAllInterPointsAtSurf_i_notFiltered(2), /*reference point*/seqTraceE3_X05_Y05.getAllInterPointsAtSurf_i_notFiltered(2).at(0));
	real rmsImageE3_X05_Y05 = spotE3_X05_Y05.getRMS_mm();
	real tartgetZemaxE3_X05_Y05 = 0.020195;
	bool checkE3_X05_Y05 = Math::compareTwoNumbers_decimals(tartgetZemaxE3_X05_Y05, rmsImageE3_X05_Y05, 6);
	testAspSur_LLT.push_back(checkE3_X05_Y05);
	// ---


	bool returnCheck = Math::checkTrueOfVectorElements(testAspSur_LLT);
	return returnCheck;
}
// E4
bool testAsphericalSurface_LLT::checkAsphere_LLT_E4()
{
	std::vector<bool> testAspSur_LLT;
	Light_LLT Light;
	Light.buildDefaultLight();
	// interactions
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;


	// E4
	// surfaces
	ApertureStop_LLT S0E4(/*semiHeight*/ 0.5, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveIndex*/ 1.0);
	AsphericalSurface_LLT S1E4(/*radius*/ 30.0, /*semi height*/ 6.0,/*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 },/*refractive index A*/ 1.0,/*refractive index B*/ 1.5,/*conic*/ -1.0,
		/*second order term*/ 2.0E-3, /*fourth order term*/ 2.0E-3, /*sixth order term*/ 2.0E-5, /*eighth order term*/ 1.0E-7,/*tenth order term*/ 1.0E-11,/*twelfth oder term*/ 1.0E-11,
		/*fourteenth order term*/1.0E-11,/*sixteenth order tem*/ 1.0E-15);
	AsphericalSurface_LLT S2E4(/*radius*/ 60.0, /*semi height*/ 6.0,/*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,-1.0 },/*refractive index A*/ 1.0,/*refractive index B*/ 1.5,/*conic*/ 1.0,
		/*second order term*/ -2.0E-3, /*fourth order term*/ 2.0E-3, /*sixth order term*/ -2.0E-5, /*eighth order term*/ -1.0E-7,/*tenth order term*/ 1.0E-11,/*twelfth oder term*/ -1.0E-11,
		/*fourteenth order term*/-1.0E-15,/*sixteenth order tem*/ -1.0E-15);
	ParaxialLens_LLT S3E4(/*semi Height*/ 5.0, /*apex*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*focallength*/ 6.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflectCR3(S3E4.getInfosForDefelction());
	AsphericalSurface_LLT S4E4(/*radius*/ 100.0, /*semi height*/ 5.0,/*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 },/*refractive index A*/ 1.6,/*refractive index B*/ 1.0,/*conic*/ -2.0,
		/*second order term*/ -1.0E-4, /*fourth order term*/ -1.0E-4, /*sixth order term*/ -1.0E-4, /*eighth order term*/ -1.0E-10,/*tenth order term*/ -1.0E-10,/*twelfth oder term*/ -1.0E-10,
		/*fourteenth order term*/1.0E-10,/*sixteenth order tem*/ 1.0E-15);
	AsphericalSurface_LLT S5E4(/*radius*/ 50.0, /*semi height*/ 5.0,/*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 },/*refractive index A*/ 1.6,/*refractive index B*/ 1.0,/*conic*/ 2.0,
		/*second order term*/ 1.0E-4, /*fourth order term*/ 1.0E-4, /*sixth order term*/ 1.0E-4, /*eighth order term*/ 1.0E-10,/*tenth order term*/ 1.0E-10,/*twelfth oder term*/ 1.0E-10,
		/*fourteenth order term*/1.0E-10,/*sixteenth order tem*/ 1.0E-15);
	SphericalSurface_LLT S6E4(/*radius*/ 20.0,/*semi height*/ 6.0,/*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 },/*refractive index A*/ 1.0,/*refractive index B*/ 1.3);
	SphericalSurface_LLT S7E4(/*radius*/ 20.0,/*semi height*/ 6.0,/*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 },/*refractive index A*/ 1.0,/*refractive index B*/ 1.3);
	PlanGeometry_LLT S8E4(/*semi Height*/5.0, /*apex*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0, 1.0);

	// build optical system
	OpticalSystem_LLT optSysE4;
	optSysE4.fillVectorSurfaceAndInteractingData(0, S0E4.clone(), refrac.clone());
	optSysE4.fillVectorSurfaceAndInteractingData(1, S1E4.clone(), refrac.clone());
	optSysE4.fillVectorSurfaceAndInteractingData(2, S2E4.clone(), refrac.clone());
	optSysE4.fillVectorSurfaceAndInteractingData(3, S3E4.clone(), deflectCR3.clone());
	optSysE4.fillVectorSurfaceAndInteractingData(4, S4E4.clone(), refrac.clone());
	optSysE4.fillVectorSurfaceAndInteractingData(5, S5E4.clone(), refrac.clone());
	optSysE4.fillVectorSurfaceAndInteractingData(6, S6E4.clone(), refrac.clone());
	optSysE4.fillVectorSurfaceAndInteractingData(7, S7E4.clone(), refrac.clone());
	optSysE4.fillVectorSurfaceAndInteractingData(8, S8E4.clone(), absorb.clone());

	//single ray tracing
	Ray_LLT rayE4(/*origin*/{ 0.0,0.0,0.0 },/*direction*/{ 0.0,0.5,5.0 },/*refractive index*/ 1.0);
	LightRayStruct lightRayE4(Light, rayE4, 1);
	SequentialRayTracing seqTraceE4_optA_single(optSysE4);
	seqTraceE4_optA_single.sequentialRayTracing(lightRayE4);
	IntersectInformationStruct interInfosE4 = seqTraceE4_optA_single.getAllInterInfosOfSurf_i_notFiltered(8).at(0);
	VectorStructR3 imagePointE4 = seqTraceE4_optA_single.getAllInterPointsAtSurf_i_notFiltered(8).at(0);
	VectorStructR3 targetSingleE4 = { 0.0,-2.3806090496,45.0 };
	bool checkSingleE4 = Math::compareTwoVectorStructR3_decimals(imagePointE4, targetSingleE4, 6);
	testAspSur_LLT.push_back(checkSingleE4);

	// ray tracing optica axis
	SequentialRayTracing seqTraceE4_optA(optSysE4);
	FillApertureStop fillAperStopE4_optA(/*start point rays*/{ 0.0,0.0,0.0 },/*semi height of aperture stop*/ 0.5,/*point of aperture stop*/{ 0.0,0.0,5.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/6,/*arms*/ 8,/*refractive index*/ 1.0, Light);
	seqTraceE4_optA.seqRayTracingWithVectorOfLightRays(fillAperStopE4_optA.getVectorWithLightRays());
	Spot spotE4_optA(/*intersection points*/ seqTraceE4_optA.getAllInterPointsAtSurf_i_notFiltered(8), /*reference point*/seqTraceE4_optA.getAllInterPointsAtSurf_i_notFiltered(8).at(0));
	real rmsImageE4_optA = spotE4_optA.getRMS_µm();
	real tartgetZemaxE4_optA = 1826.90;
	bool checkE4_optA = Math::compareTwoNumbers_decimals(tartgetZemaxE4_optA, rmsImageE4_optA, 2);
	testAspSur_LLT.push_back(checkE4_optA);

	// ray tracing field 1
	SequentialRayTracing seqTraceE4_field1(optSysE4);
	FillApertureStop fillAperStopE4_field1(/*start point rays*/{ 0.0,1.0,0.0 },/*semi height of aperture stop*/ 0.5,/*point of aperture stop*/{ 0.0,0.0,5.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/6,/*arms*/ 8,/*refractive index*/ 1.0, Light);
	seqTraceE4_field1.seqRayTracingWithVectorOfLightRays(fillAperStopE4_field1.getVectorWithLightRays());
	Spot spotE4_field1(/*intersection points*/ seqTraceE4_field1.getAllInterPointsAtSurf_i_notFiltered(8), /*reference point*/seqTraceE4_field1.getAllInterPointsAtSurf_i_notFiltered(8).at(0));
	real rmsImageE4_field1 = spotE4_field1.getRMS_µm();
	real tartgetZemaxE4_field1 = 1599.79;
	bool checkE4_field1 = Math::compareTwoNumbers_decimals(tartgetZemaxE4_field1, rmsImageE4_field1, 2);
	testAspSur_LLT.push_back(checkE4_field1);



	bool returnCheck = Math::checkTrueOfVectorElements(testAspSur_LLT);
	return returnCheck;
}