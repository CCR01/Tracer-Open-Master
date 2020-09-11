#include "testPSF.h"

// surfaces
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"

// interaction
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"

#include "..\..\FillAptertureStop\FillApertureStop.h"

#include "..\..\Analyse\OpticalPathDifference.h"

#include "..\..\Analyse\CardinalPoints.h"

//bool TestPSF::checkMethodesPSF()
//{
//
//	typedef std::shared_ptr< SurfaceIntersectionRay_LLT > surfacePtr_LLT;
//
//	LightRayStruct lightRay;
//	std::vector<bool> workTheSystem;
//	// build the optical system
//
//	//	//all the surfaces
//	ApertureStop_LLT A0(/*semi height*/ 1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index*/ 1.0);
//	SphericalSurface_LLT S1(/*radius*/20, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 21.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
//	SphericalSurface_LLT S2(/*radius*/25.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 26.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
//	SphericalSurface_LLT S3(/*radius*/20.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 27.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
//	SphericalSurface_LLT S4(/*radius*/20, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 32.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
//	PlanGeometry_LLT S5(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,51.47339407559657 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
//
//
//	// build the optical system
//	RefractedRay_LLT refrac;
//	Absorb_LLT absorb;
//	DoNothingInteraction_LLT doNothing;
//	Light_LLT light;
//	OpticalSystem_LLT optSysE0;
//	optSysE0.fillVectorSurfaceAndInteractingData(0, &A0, doNothing.clone());
//	optSysE0.fillVectorSurfaceAndInteractingData(1, &S1, refrac.clone());
//	optSysE0.fillVectorSurfaceAndInteractingData(2, &S2, refrac.clone());
//	optSysE0.fillVectorSurfaceAndInteractingData(3, &S3, refrac.clone());
//	optSysE0.fillVectorSurfaceAndInteractingData(4, &S4, refrac.clone());
//	optSysE0.fillVectorSurfaceAndInteractingData(5, &S5, doNothing.clone());
//
//	//	// single ray tracing
//	Ray_LLT cheif({ 0.0,0.0,0.0 }, { 0.0,0.0,20.0 }, 1.0);
//	Ray_LLT rayE0_0({ 0.0,0.0,0.0 }, { 0.0,1.0,20.0 }, 1.0);
//	Ray_LLT rayE0_1({ 0.0,0.0,0.0 }, { 0.0,-0.5,20.0 }, 1.0);
//	Ray_LLT rayE0_2({ 0.0,0.0,0.0 }, { -1.0,0.0,20.0 }, 1.0);
//	Ray_LLT rayE0_3({ 0.0,0.0,0.0 }, { 0.5,0.5,20.0 },  1.0);
//	Ray_LLT rayE0_4({ 0.0,0.0,0.0 }, { -0.5,0.5,20.0 }, 1.0);
//	Ray_LLT rayE0_5({ 0.0,0.0,0.0 }, { 0.3,-0.7,20.0 }, 1.0);
//	LightRayStruct chiefLightRay(light, cheif, 1);
//	LightRayStruct lightRayE0_0(light, rayE0_0, 1);
//	LightRayStruct lightRayE0_1(light, rayE0_1, 1);
//	LightRayStruct lightRayE0_2(light, rayE0_2, 1);
//	LightRayStruct lightRayE0_3(light, rayE0_3, 1);
//	LightRayStruct lightRayE0_4(light, rayE0_4, 1);
//	LightRayStruct lightRayE0_5(light, rayE0_5, 1);
//
//	std::vector<LightRayStruct> vecLightRaysE0{ lightRayE0_0, lightRayE0_1, lightRayE0_2, lightRayE0_3, lightRayE0_4, lightRayE0_5 };
//	SequentialRayTracing seqTraceE0_single(optSysE0);
//	seqTraceE0_single.seqRayTracingWithVectorOfLightRays(vecLightRaysE0);
//
//	//exit pupil
//	PlanGeometry_LLT exitPupilE0(/*semiHeight*/20.0, /*point*/{ 0.0,0.0,18.51839803 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
//	surfacePtr_LLT exitPupilE0_ptr = exitPupilE0.clone();
//
//	//	//___ test opt achse
//	// test rays to calculate OPD
//	// calc global OPD optical achse 
//	OPD OPDglobalE0_optAchse_single(/*exit pupil*/ exitPupilE0_ptr,  /*optical system*/ optSysE0,
//		/*fill apertur stop with light ray*/ vecLightRaysE0, /*chief ray*/ chiefLightRay, /*scalling*/ 0);
//	std::vector<real> checkOPD = OPDglobalE0_optAchse_single.getVecWithAllCalcGlobalOPD();
//	std::vector<real> zemaxDataOPD = { -7.461469657163181E-002, -6.048673068919702E-002, -7.461469657163181E-002,-9.317664088656388E-002,-9.317664088656388E-002,-9.774428660115252E-002 };
//	bool checkerOPD = Math::compareTwoSTDVecors_decimals(checkOPD, zemaxDataOPD, 8);
//	workTheSystem.push_back(checkerOPD);
//	//___ end test opt achse
//
//	//__ start check gloabl OPD in the optical axis
//	// fill aperture stop with many lightrays
//	FillApertureStop fillAperStopE0_optAxis({ 0.0,0.0,0.0 }, 1, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, /*rings*/23, /*arms*/22, 1.0, light);
//	// calc global OPD y=0 for may rays
//	OPD OPDglobalE0_optA_full(/*exit pupil*/ exitPupilE0_ptr,  /*optical system*/ optSysE0,
//		/*fill apertur stop with light ray*/ fillAperStopE0_optAxis.getVectorWithLightRays(), /*chief ray*/ fillAperStopE0_optAxis.getVectorWithLightRays().at(0), /*scalling*/ 0);
//	OPDglobalE0_optA_full.exportCV_MatToExcel(OPDglobalE0_optA_full.getGlobalOPD(), "D:\OPDglobal_optAxis.csv");
//	//__ end check gloabl OPD in the field (y=1) for many ray
//
//	//__ start check gloabl OPD in the field y=1
//	// fill aperture stop with many lightrays
//	FillApertureStop fillAperStopE0_Y1({ 0.0,1.0,0.0 }, 1, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, /*rings*/23, /*arms*/22, 1.0, light);
//	// calc global OPD optical field (y=1) for many rays
//	OPD OPDglobalE0_Y1(/*exit pupil*/ exitPupilE0_ptr,  /*optical system*/ optSysE0,
//		/*fill apertur stop with light ray*/ fillAperStopE0_Y1.getVectorWithLightRays(), /*chief ray*/ fillAperStopE0_Y1.getVectorWithLightRays().at(0), /*scalling*/ 0);
//	OPDglobalE0_Y1.exportCV_MatToExcel(OPDglobalE0_Y1.getGlobalOPD(), "D:\OPDglobalY1.csv");
//	//__ end check gloabl OPD in the field (y=1) for many ray
//
//	return true;
//
//}