#include "testOPD.h"
#include "..\..\Analyse\OpticalPathDifference.h"
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\..\LowLevelTracing\Surfaces\ParaxialLens_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DeflectedRayParaxialLens_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\FillAptertureStop\FillApertureStop.h"
#include "..\..\Analyse\Spot.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"
#include "..\..\Analyse\CardinalPoints.h"
#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

typedef std::shared_ptr< SurfaceIntersectionRay_LLT > surfacePtr_LLT;


bool TestOPD::checkOPD_superFct()
{

	std::vector<bool> workOPD;// hier gehts dann weiter

	// E0
	bool chE0 = checkE0();
	workOPD.push_back(chE0);
	
	// E1
	bool chE1 = checkE1();
	workOPD.push_back(chE1);

	// E2
	bool chE2 = checkE2();
	workOPD.push_back(chE2);

	// E3
	bool chE3 = checkE3();
	workOPD.push_back(chE3);

	// E4
	bool chE4 = checkE4();
	workOPD.push_back(chE4);


	bool returnCheckOPD = Math::checkTrueOfVectorElements(workOPD);
	return returnCheckOPD;
}

// E0
bool TestOPD::checkE0()
{
	std::vector<bool> checkOPD;

	RefractedRay_LLT refrac;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light500;
	Light500.setWavelength(500.0);
	Absorb_LLT absorb;

	real Air = 1.0;

	// define rays to trace
	Ray_LLT Ray1(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 20.0 }, 1.0);
	Ray_LLT Ray2(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 20.0 }, 1.0);
	Ray_LLT Ray3(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 20.0 }, 1.0);
	Ray_LLT Ray4(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 20.0 }, 1.0);

	//define lightrays
	LightRayStruct LightRayMargPy1 = { Light500, Ray1, 1 };
	LightRayStruct LightRayPyHalf = { Light500, Ray2, 1 };
	LightRayStruct LightRayOptAx = { Light500, Ray3, 1 };

	// surfaces of the optical system
	ApertureStop_LLT ApertureStop0_E0(1.0, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT S1_E0(/*radius*/15.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 40.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S2_E0(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 45.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S3_E0(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,62.073 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	
	SphericalSurface_LLT RefSpherAtExitPupilPlanExP(/*radius*/12.158, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0, 0.0, 74.231 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	// build opitcal system
	OpticalSystem_LLT OptSys_E0;
	OptSys_E0.fillVectorSurfaceAndInteractingData(0, ApertureStop0_E0.clone(), doNothing.clone());
	OptSys_E0.fillVectorSurfaceAndInteractingData(1, S1_E0.clone(), refrac.clone());
	OptSys_E0.fillVectorSurfaceAndInteractingData(2, S2_E0.clone(), refrac.clone());
	OptSys_E0.fillVectorSurfaceAndInteractingData(3, S3_E0.clone(), doNothing.clone());
	OptSys_E0.fillVectorSurfaceAndInteractingData(4, RefSpherAtExitPupilPlanExP.clone(), doNothing.clone());

	//**********************************************************************************************
	// check optical path with marginal ray Py=1
	SequentialRayTracing SeqTrac_0(OptSys_E0);
	SeqTrac_0.sequentialRayTracing(LightRayMargPy1);
	real distance0 = SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(0).at(0).getIntersecInfos().getStepsToWalk();
	real distance1 = SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(1).at(0).getIntersecInfos().getStepsToWalk();
	real distance2 = SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(2).at(0).getIntersecInfos().getStepsToWalk();
	real distance3 = SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(0).getIntersecInfos().getStepsToWalk();
	real distance4 = SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(0).getIntersecInfos().getStepsToWalk();

	real sumOPDPy1 = distance0 + distance1 + distance2 + distance3 + distance4;
	real OPDPy1sys = SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(0).getTotalSteps();
	bool checkOPDPy = Math::compareTwoNumbers_decimals(sumOPDPy1, OPDPy1sys, 7);
	checkOPD.push_back(checkOPDPy);
	//**********************************************************************************************

	// check optical path with ray on optical axis
	SeqTrac_0.clearAllTracedRays();
	SeqTrac_0.sequentialRayTracing(LightRayOptAx);
	real distance0OA = SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(0).at(0).getIntersecInfos().getStepsToWalk();
	real distance1OA = SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(1).at(0).getIntersecInfos().getStepsToWalk();
	real distance2OA = SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(2).at(0).getIntersecInfos().getStepsToWalk();
	real distance3OA = SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(0).getIntersecInfos().getStepsToWalk();
	real distance4OA = SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(0).getIntersecInfos().getStepsToWalk();

	real sumOPDoptAx = distance0OA + distance1OA + distance2OA + distance3OA + distance4OA;
	real OPDoptAxSys = SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(0).getTotalSteps();
	bool checkOPDoptAx = Math::compareTwoNumbers_decimals(sumOPDoptAx, OPDoptAxSys, 7);
	checkOPD.push_back(checkOPDoptAx);


	std::vector<LightRayStruct> lightRayAlong_YE1 = SequentialRayTracing::lightRayAlongY({ 0.0,0.0,0.0 }, 11, 20, -1, +1, 550, 1.0);
	SeqTrac_0.clearAllTracedRays();
	SeqTrac_0.seqRayTracingWithVectorOfLightRays(lightRayAlong_YE1);
	double referenceLenght = SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(4).getTotalSteps();
	double OPDPX_0 = ((referenceLenght - SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(0).getTotalSteps()) / Light500.getWavelength()) * 1000000 ;
	double OPDPX_1 = ((referenceLenght - SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(1).getTotalSteps()) / Light500.getWavelength()) * 1000000;
	double OPDPX_2 = ((referenceLenght - SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(2).getTotalSteps()) / Light500.getWavelength()) * 1000000;
	double OPDPX_3 = ((referenceLenght - SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(3).getTotalSteps()) / Light500.getWavelength()) * 1000000;
	double OPDPX_4 = ((referenceLenght - SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(4).getTotalSteps()) / Light500.getWavelength()) * 1000000;
	double OPDPX_5 = ((referenceLenght - SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(5).getTotalSteps()) / Light500.getWavelength()) * 1000000;
	double OPDPX_6 = ((referenceLenght - SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(6).getTotalSteps()) / Light500.getWavelength()) * 1000000;
	double OPDPX_7 = ((referenceLenght - SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(7).getTotalSteps()) / Light500.getWavelength()) * 1000000;
	double OPDPX_8 = ((referenceLenght - SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(8).getTotalSteps()) / Light500.getWavelength()) * 1000000;
	double OPDPX_9 = ((referenceLenght - SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(9).getTotalSteps()) / Light500.getWavelength()) * 1000000;
	double OPDPX_10 = ((referenceLenght - SeqTrac_0.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(10).getTotalSteps()) / Light500.getWavelength()) * 1000000;

	std::vector<double> allOPD = { OPDPX_0, OPDPX_1 , OPDPX_2 ,OPDPX_3 , OPDPX_4 ,OPDPX_5, OPDPX_6 , OPDPX_7, OPDPX_8 , OPDPX_9 , OPDPX_10 };
	std::vector<double> refAllOPD = { 7.656, 2.855, 0.839, 0.157, 9.430E-3, 0.0, 9.430E-3, 0.157, 0.839, 2.855, 7.656 };
	//**********************************************************************************************
	bool checkOPDE1 = Math::compateTwoSTDVector_tolerance(allOPD, refAllOPD, 0.01);
	checkOPD.push_back(checkOPDE1);
	//**********************************************************************************************
	//**********************************************************************************************

	// checking the OPD for the field (0,1) 
	// surfaces of the optical system
	ApertureStop_LLT ApertureStop0_E1(1.0, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT S1_E1(/*radius*/15.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 40.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S2_E1(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 45.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S3_E1(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,62.073 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	PlanGeometry_LLT S4_E1(/*semiHeight*/99.0, /*point*/{ 0.0,0.0,74.231 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	

	// build opitcal system
	OpticalSystem_LLT OptSys_E1;
	OptSys_E1.fillVectorSurfaceAndInteractingData(0, ApertureStop0_E1.clone(), doNothing.clone());
	OptSys_E1.fillVectorSurfaceAndInteractingData(1, S1_E1.clone(), refrac.clone());
	OptSys_E1.fillVectorSurfaceAndInteractingData(2, S2_E1.clone(), refrac.clone());
	OptSys_E1.fillVectorSurfaceAndInteractingData(3, S3_E1.clone(), doNothing.clone());
	OptSys_E1.fillVectorSurfaceAndInteractingData(4, S4_E1.clone(), doNothing.clone());

	//* find pos and direction of exit pupil
	Ray_LLT Ray_01_chief(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0, -1.0, 20.0 }, 1.0);
	LightRayStruct LightRayChief01 = { Light500, Ray_01_chief, 1 };
	SequentialRayTracing seqTraceChief01(OptSys_E1);
	seqTraceChief01.sequentialRayTracing(LightRayChief01);

	VectorStructR3 interPointChief01_ima = seqTraceChief01.getAllInterPointsAtSurface_i_filtered(3)[0];
	VectorStructR3 interPointChief01_exitPupil = seqTraceChief01.getAllInterPointsAtSurface_i_filtered(4)[0];
	VectorStructR3 directionExitPupil = interPointChief01_ima - interPointChief01_exitPupil;


	real radius = Math::lengthOfVector(directionExitPupil);

	SphericalSurface_LLT RefSpherAtExitPupil_01(/*radius*/radius, /*semiHeight*/99.0, /*Apex of the sphere*/interPointChief01_exitPupil, /*Direction*/ directionExitPupil, /*refIndexSideA*/Air, /*refIndexSideB*/Air);

	// build the system including reference sphere on exit pupil
	OpticalSystem_LLT OptSys_E1_includingRefSphere01;
	OptSys_E1_includingRefSphere01.fillVectorSurfaceAndInteractingData(0, ApertureStop0_E1.clone(), doNothing.clone());
	OptSys_E1_includingRefSphere01.fillVectorSurfaceAndInteractingData(1, S1_E1.clone(), refrac.clone());
	OptSys_E1_includingRefSphere01.fillVectorSurfaceAndInteractingData(2, S2_E1.clone(), refrac.clone());
	OptSys_E1_includingRefSphere01.fillVectorSurfaceAndInteractingData(3, S3_E1.clone(), doNothing.clone());
	OptSys_E1_includingRefSphere01.fillVectorSurfaceAndInteractingData(4, RefSpherAtExitPupil_01.clone(), doNothing.clone());


	// define rays to trace
	Ray_LLT Ray5(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0, 0.0, 1.0 }, 1.0); // 0 1
	Ray_LLT Ray6_chief(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0, -1.0, 20.0 }, 1.0); // 0 0
	Ray_LLT Ray7(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0, -2.0, 20.0 }, 1.0); // 0 -1
	Ray_LLT Ray8(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.5, -0.5, 20.0 }, 1.0); // 0,5 0,5
	Ray_LLT Ray9(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0, -0.5, 20.0 }, 1.0); // 0 0,5
	Ray_LLT Ray10(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.5, -1.5, 20.0 }, 1.0); // 0,5 -0,5 
	Ray_LLT Ray11(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.3, -0.7, 20.0 }, 1.0); // 0,3 0,3
	Ray_LLT Ray12(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ -0.2, 0.4, 20.0 }, 1.0); // -0,2 0,6

	//define lightrays
	LightRayStruct LightRay5 = { Light500, Ray5, 1 };
	LightRayStruct LightRay6_cheif = { Light500, Ray6_chief, 1 };
	LightRayStruct LightRay7 = { Light500, Ray7, 1 };
	LightRayStruct LightRay8 = { Light500, Ray8, 1 };
	LightRayStruct LightRay9 = { Light500, Ray9, 1 };
	LightRayStruct LightRay10 = { Light500, Ray10, 1 };
	LightRayStruct LightRay11 = { Light500, Ray11, 1 };
	LightRayStruct LightRay12 = { Light500, Ray12, 1 };

	std::vector<LightRayStruct> lightRay_vec_01{ LightRay5, LightRay6_cheif, LightRay7, LightRay8, LightRay9, LightRay10, LightRay11, LightRay12 };
	SequentialRayTracing seqTraceExitPupil_01(OptSys_E1_includingRefSphere01);
	seqTraceExitPupil_01.seqRayTracingWithVectorOfLightRays(lightRay_vec_01);

	real distance_5 = seqTraceExitPupil_01.getInterInf_PosSurface_TotalSteps_ofSur_i(4)[0].getTotalSteps();
	real distance_6_cheif = seqTraceExitPupil_01.getInterInf_PosSurface_TotalSteps_ofSur_i(4)[1].getTotalSteps();
	real distance_7 = seqTraceExitPupil_01.getInterInf_PosSurface_TotalSteps_ofSur_i(4)[2].getTotalSteps();
	real distance_8 = seqTraceExitPupil_01.getInterInf_PosSurface_TotalSteps_ofSur_i(4)[3].getTotalSteps();
	real distance_9 = seqTraceExitPupil_01.getInterInf_PosSurface_TotalSteps_ofSur_i(4)[4].getTotalSteps();
	real distance_10 = seqTraceExitPupil_01.getInterInf_PosSurface_TotalSteps_ofSur_i(4)[5].getTotalSteps();
	real distance_11 = seqTraceExitPupil_01.getInterInf_PosSurface_TotalSteps_ofSur_i(4)[6].getTotalSteps();
	real distance_12 = seqTraceExitPupil_01.getInterInf_PosSurface_TotalSteps_ofSur_i(4)[7].getTotalSteps();

	real OPD_5 = ((distance_6_cheif - distance_5) / Light500.getWavelength()) * 1000000;
	real OPD_6 = ((distance_6_cheif - distance_6_cheif) / Light500.getWavelength()) * 1000000;
	real OPD_7 = ((distance_6_cheif - distance_7) / Light500.getWavelength()) * 1000000;
	real OPD_8 = ((distance_6_cheif - distance_8) / Light500.getWavelength()) * 1000000;
	real OPD_9 = ((distance_6_cheif - distance_9) / Light500.getWavelength()) * 1000000;
	real OPD_10 = ((distance_6_cheif - distance_10) / Light500.getWavelength()) * 1000000;
	real OPD_11 = ((distance_6_cheif - distance_11) / Light500.getWavelength()) * 1000000;
	real OPD_12 = ((distance_6_cheif - distance_12) / Light500.getWavelength()) * 1000000;

	std::vector<real> calc_OPD_01{ OPD_5,OPD_6,OPD_7,OPD_8,OPD_9,OPD_10,OPD_11,OPD_12 };
	std::vector<real> ref_OPD_01{ 3.168,0.0,47.305,1.555,1.130,10.221,0.636,1.456 };

	Math::compateTwoSTDVector_tolerance(calc_OPD_01, ref_OPD_01, 0.01);

	bool returnCheckOPD = Math::checkTrueOfVectorElements(checkOPD);
	return returnCheckOPD;

}

// E1
bool TestOPD::checkE1()
{	
	RefractedRay_LLT refrac;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light500;
	Light500.setWavelength(500.0);
	Absorb_LLT absorb;
	
	std::vector<bool> checkOPD;
	
	Ray_LLT RayPy1E2(/*origin*/{ 0.0, 0.83106246530, 0.0 }, /*direction*/{ 0.0, -0.247422749, 1.8380709316 }, 1.0);

	LightRayStruct LightRayE2Py1 = { Light500, RayPy1E2, 1 };

	ApertureStop_LLT ApertureStop_S0_E1(1.0, { 0.0,0.0,10.0 }, { 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT S0_E1(/*radius*/5.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 13 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S1_E1(/*radius*/5.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 18 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S2_E1(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 21 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.6, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S3_E1(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 26 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.6, /*refIndexSideB*/1.0);
	PlanGeometry_LLT Image_E1(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,31.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	// build the optical system
	OpticalSystem_LLT OptSysE2;
	OptSysE2.fillVectorSurfaceAndInteractingData(0, ApertureStop_S0_E1.clone(), doNothing.clone());
	OptSysE2.fillVectorSurfaceAndInteractingData(1, S0_E1.clone(), refrac.clone());
	OptSysE2.fillVectorSurfaceAndInteractingData(2, S1_E1.clone(), refrac.clone());
	OptSysE2.fillVectorSurfaceAndInteractingData(3, S2_E1.clone(), refrac.clone());
	OptSysE2.fillVectorSurfaceAndInteractingData(4, S3_E1.clone(), refrac.clone());
	OptSysE2.fillVectorSurfaceAndInteractingData(5, Image_E1.clone(), refrac.clone());

	//**********************************************************************************************
	CardinalPoints carPointsE2(OptSysE2, objectPoint_inf_obj::obj);
	real exitPupilPosition_globalCoodiSys_Z = carPointsE2.getEXPP_globalCoori();
	VectorStructR3 posExitPos = { 0.0,0.0,exitPupilPosition_globalCoodiSys_Z };
	real radiusExitPupilOptA = (Image_E1.getPoint() - posExitPos).getZ();
	
	SphericalSurface_LLT refSphereAtExitPupil_optA(/*radius*/radiusExitPupilOptA, /*semiHeight*/99.0, /*Apex of the sphere*/posExitPos, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/refractiveIndexAir, /*refIndexSideB*/refractiveIndexAir);

	Ray_LLT Ray0_chief(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 10.0 }, 1.0); 
	Ray_LLT Ray1(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 10.0 }, 1.0); 
	Ray_LLT Ray2(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.5, 0.5, 10.0 }, 1.0); 
	Ray_LLT Ray3(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ -0.5, 0.5, 10.0 }, 1.0);
	Ray_LLT Ray4(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.5, -0.5, 10.0 }, 1.0);
	Ray_LLT Ray5(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.2, -0.5, 10.0 }, 1.0);
	Ray_LLT Ray6(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ -0.7, 0.3, 10.0 }, 1.0);
	Ray_LLT Ray7(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ -0.3, -0.4, 10.0 }, 1.0);
	Ray_LLT Ray8(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.7, 0.3, 10.0 }, 1.0);
	Ray_LLT Ray9(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.6, 0.5, 10.0 }, 1.0);

	LightRayStruct lightRay0(Light500, Ray0_chief, 1);
	LightRayStruct lightRay1(Light500, Ray1, 1);
	LightRayStruct lightRay2(Light500, Ray2, 1);
	LightRayStruct lightRay3(Light500, Ray3, 1);
	LightRayStruct lightRay4(Light500, Ray4, 1);
	LightRayStruct lightRay5(Light500, Ray5, 1);
	LightRayStruct lightRay6(Light500, Ray6, 1);
	LightRayStruct lightRay7(Light500, Ray7, 1);
	LightRayStruct lightRay8(Light500, Ray8, 1);
	LightRayStruct lightRay9(Light500, Ray9, 1);

	std::vector<LightRayStruct> lightRay_optA{ lightRay0 ,lightRay1 ,lightRay2 ,lightRay3 ,lightRay4 ,lightRay5 ,lightRay6 ,lightRay7 ,lightRay8,lightRay9 };

	SequentialRayTracing seqTraceE1_optA(OptSysE2);
	seqTraceE1_optA.seqRayTracingWithVectorOfLightRays(lightRay_optA);

	// distance to image surface
	real distance_imaSurface_0 = seqTraceE1_optA.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[0].getTotalSteps();
	real distance_imaSurface_1 = seqTraceE1_optA.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[1].getTotalSteps();
	real distance_imaSurface_2 = seqTraceE1_optA.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[2].getTotalSteps();
	real distance_imaSurface_3 = seqTraceE1_optA.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[3].getTotalSteps();
	real distance_imaSurface_4 = seqTraceE1_optA.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[4].getTotalSteps();
	real distance_imaSurface_5 = seqTraceE1_optA.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[5].getTotalSteps();
	real distance_imaSurface_6 = seqTraceE1_optA.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[6].getTotalSteps();
	real distance_imaSurface_7 = seqTraceE1_optA.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[7].getTotalSteps();
	real distance_imaSurface_8 = seqTraceE1_optA.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[8].getTotalSteps();
	real distance_imaSurface_9 = seqTraceE1_optA.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[9].getTotalSteps();

	VectorStructR3 directionRayToTraceack_0 = -1.0 * seqTraceE1_optA.getAllInterInfosOfSurf_i(5)[0].getDirectionRayUnit();
	VectorStructR3 directionRayToTraceack_1 = -1.0 * seqTraceE1_optA.getAllInterInfosOfSurf_i(5)[1].getDirectionRayUnit();
	VectorStructR3 directionRayToTraceack_2 = -1.0 * seqTraceE1_optA.getAllInterInfosOfSurf_i(5)[2].getDirectionRayUnit();
	VectorStructR3 directionRayToTraceack_3 = -1.0 * seqTraceE1_optA.getAllInterInfosOfSurf_i(5)[3].getDirectionRayUnit();
	VectorStructR3 directionRayToTraceack_4 = -1.0 * seqTraceE1_optA.getAllInterInfosOfSurf_i(5)[4].getDirectionRayUnit();
	VectorStructR3 directionRayToTraceack_5 = -1.0 * seqTraceE1_optA.getAllInterInfosOfSurf_i(5)[5].getDirectionRayUnit();
	VectorStructR3 directionRayToTraceack_6 = -1.0 * seqTraceE1_optA.getAllInterInfosOfSurf_i(5)[6].getDirectionRayUnit();
	VectorStructR3 directionRayToTraceack_7 = -1.0 * seqTraceE1_optA.getAllInterInfosOfSurf_i(5)[7].getDirectionRayUnit();
	VectorStructR3 directionRayToTraceack_8 = -1.0 * seqTraceE1_optA.getAllInterInfosOfSurf_i(5)[8].getDirectionRayUnit();
	VectorStructR3 directionRayToTraceack_9 = -1.0 * seqTraceE1_optA.getAllInterInfosOfSurf_i(5)[9].getDirectionRayUnit();

	VectorStructR3 interPointIma_0 = seqTraceE1_optA.getAllInterPointsAtSurface_i_filtered(5)[0];
	VectorStructR3 interPointIma_1 = seqTraceE1_optA.getAllInterPointsAtSurface_i_filtered(5)[1];
	VectorStructR3 interPointIma_2 = seqTraceE1_optA.getAllInterPointsAtSurface_i_filtered(5)[2];
	VectorStructR3 interPointIma_3 = seqTraceE1_optA.getAllInterPointsAtSurface_i_filtered(5)[3];
	VectorStructR3 interPointIma_4 = seqTraceE1_optA.getAllInterPointsAtSurface_i_filtered(5)[4];
	VectorStructR3 interPointIma_5 = seqTraceE1_optA.getAllInterPointsAtSurface_i_filtered(5)[5];
	VectorStructR3 interPointIma_6 = seqTraceE1_optA.getAllInterPointsAtSurface_i_filtered(5)[6];
	VectorStructR3 interPointIma_7 = seqTraceE1_optA.getAllInterPointsAtSurface_i_filtered(5)[7];
	VectorStructR3 interPointIma_8 = seqTraceE1_optA.getAllInterPointsAtSurface_i_filtered(5)[8];
	VectorStructR3 interPointIma_9 = seqTraceE1_optA.getAllInterPointsAtSurface_i_filtered(5)[9];

	Ray_LLT ray0_back(/*origin*/interPointIma_0, /*direction*/directionRayToTraceack_0, 1.0);
	Ray_LLT ray1_back(/*origin*/interPointIma_1, /*direction*/directionRayToTraceack_1, 1.0);
	Ray_LLT ray2_back(/*origin*/interPointIma_2, /*direction*/directionRayToTraceack_2, 1.0);
	Ray_LLT ray3_back(/*origin*/interPointIma_3, /*direction*/directionRayToTraceack_3, 1.0);
	Ray_LLT ray4_back(/*origin*/interPointIma_4, /*direction*/directionRayToTraceack_4, 1.0);
	Ray_LLT ray5_back(/*origin*/interPointIma_5, /*direction*/directionRayToTraceack_5, 1.0);
	Ray_LLT ray6_back(/*origin*/interPointIma_6, /*direction*/directionRayToTraceack_6, 1.0);
	Ray_LLT ray7_back(/*origin*/interPointIma_7, /*direction*/directionRayToTraceack_7, 1.0);
	Ray_LLT ray8_back(/*origin*/interPointIma_8, /*direction*/directionRayToTraceack_8, 1.0);
	Ray_LLT ray9_back(/*origin*/interPointIma_9, /*direction*/directionRayToTraceack_9, 1.0);

	LightRayStruct lightRay0_back(Light500, ray0_back, 1);
	LightRayStruct lightRay1_back(Light500, ray1_back, 1);
	LightRayStruct lightRay2_back(Light500, ray2_back, 1);
	LightRayStruct lightRay3_back(Light500, ray3_back, 1);
	LightRayStruct lightRay4_back(Light500, ray4_back, 1);
	LightRayStruct lightRay5_back(Light500, ray5_back, 1);
	LightRayStruct lightRay6_back(Light500, ray6_back, 1);
	LightRayStruct lightRay7_back(Light500, ray7_back, 1);
	LightRayStruct lightRay8_back(Light500, ray8_back, 1);
	LightRayStruct lightRay9_back(Light500, ray9_back, 1);

	std::vector<LightRayStruct> lightRay_traceBack_vec{ lightRay0_back ,lightRay1_back ,lightRay2_back ,lightRay3_back ,lightRay4_back ,lightRay5_back ,lightRay6_back ,lightRay7_back ,lightRay8_back,lightRay9_back };

	OpticalSystem_LLT optSysExitPupil;
	PlanGeometry_LLT exitPupil(/*semiHeight*/99.0, /*point*/posExitPos, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	optSysExitPupil.fillVectorSurfaceAndInteractingData(0, exitPupil.clone(), doNothing.clone());

	OpticalSystem_LLT optSysRefSphereAtExitPupil;
	optSysRefSphereAtExitPupil.fillVectorSurfaceAndInteractingData(0, refSphereAtExitPupil_optA.clone(), doNothing.clone());
	SequentialRayTracing seqTrace_back(optSysRefSphereAtExitPupil);
	seqTrace_back.seqRayTracingWithVectorOfLightRays(lightRay_traceBack_vec);

	real distanceBack_0 = seqTrace_back.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[0].getTotalSteps();
	real distanceBack_1 = seqTrace_back.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[1].getTotalSteps();
	real distanceBack_2 = seqTrace_back.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[2].getTotalSteps();
	real distanceBack_3 = seqTrace_back.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[3].getTotalSteps();
	real distanceBack_4 = seqTrace_back.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[4].getTotalSteps();
	real distanceBack_5 = seqTrace_back.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[5].getTotalSteps();
	real distanceBack_6 = seqTrace_back.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[6].getTotalSteps();
	real distanceBack_7 = seqTrace_back.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[7].getTotalSteps();
	real distanceBack_8 = seqTrace_back.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[8].getTotalSteps();
	real distanceBack_9 = seqTrace_back.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[9].getTotalSteps();

	real referenceDistance = distance_imaSurface_0 - distanceBack_0;

	real OPD1 = ((referenceDistance - (distance_imaSurface_1 - distanceBack_1)) / Light500.getWavelength()) * 1000000;
	real OPD2 = ((referenceDistance - (distance_imaSurface_2 - distanceBack_2)) / Light500.getWavelength()) * 1000000;
	real OPD3 = ((referenceDistance - (distance_imaSurface_3 - distanceBack_3)) / Light500.getWavelength()) * 1000000;
	real OPD4 = ((referenceDistance - (distance_imaSurface_4 - distanceBack_4)) / Light500.getWavelength()) * 1000000;
	real OPD5 = ((referenceDistance - (distance_imaSurface_5 - distanceBack_5)) / Light500.getWavelength()) * 1000000;
	real OPD6 = ((referenceDistance - (distance_imaSurface_6 - distanceBack_6)) / Light500.getWavelength()) * 1000000;
	real OPD7 = ((referenceDistance - (distance_imaSurface_7 - distanceBack_7)) / Light500.getWavelength()) * 1000000;
	real OPD8 = ((referenceDistance - (distance_imaSurface_8 - distanceBack_8)) / Light500.getWavelength()) * 1000000;
	real OPD9 = ((referenceDistance - (distance_imaSurface_9 - distanceBack_9)) / Light500.getWavelength()) * 1000000;

	std::vector<real> calcOPD_optA = { OPD1 ,OPD2 ,OPD3 ,OPD4 ,OPD5 ,OPD6 ,OPD7 ,OPD8 ,OPD9 };
	std::vector<real> refOPD_optA = {0.162,1.738,1.738,1.738,0.314,2.578,0.162,2.578,2.938 };

	bool checkOPD_optA = Math::compateTwoSTDVector_tolerance(calcOPD_optA, refOPD_optA, 0.01);
	checkOPD.push_back(checkOPD_optA);

	// ******************************************************************

	// field 0 1
	Ray_LLT Ray10_chief(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0, -1.0, 10.0 }, 1.0);
	Ray_LLT Ray11(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0, -0.5, 10.0 }, 1.0);	// 0 0,5
	Ray_LLT Ray12(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ -0.5, -0.5, 10.0 }, 1.0); // -0,5 0,5
	Ray_LLT Ray13(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ -1.0, -1.0, 10.0 }, 1.0);	// -1 0
	Ray_LLT Ray14(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ -0.5, -1.5, 10.0 }, 1.0);	// -0,5 -0,5
	Ray_LLT Ray15(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ -0.2, -0.5, 10.0 }, 1.0);	// -0,2 0,5
	Ray_LLT Ray16(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ -0.7, -0.3, 10.0 }, 1.0);	// -0,7 0,7
	Ray_LLT Ray17(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ -0.3, -0.4, 10.0 }, 1.0);	// -0,3 0,6
	Ray_LLT Ray18(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ -0.7, -0.7, 10.0 }, 1.0);	// -0,7 0,3
	Ray_LLT Ray19(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ -0.6, -0.5, 10.0 }, 1.0);	// -0,6 0,5

	LightRayStruct lightRay10(Light500, Ray10_chief, 1);
	LightRayStruct lightRay11(Light500, Ray11, 1);
	LightRayStruct lightRay12(Light500, Ray12, 1);
	LightRayStruct lightRay13(Light500, Ray13, 1);
	LightRayStruct lightRay14(Light500, Ray14, 1);
	LightRayStruct lightRay15(Light500, Ray15, 1);
	LightRayStruct lightRay16(Light500, Ray16, 1);
	LightRayStruct lightRay17(Light500, Ray17, 1);
	LightRayStruct lightRay18(Light500, Ray18, 1);
	LightRayStruct lightRay19(Light500, Ray19, 1);

	std::vector<LightRayStruct> lightRay_field01{ lightRay10 ,lightRay11 ,lightRay12 ,lightRay13 ,lightRay14 ,lightRay15 ,lightRay16 ,lightRay17 ,lightRay18,lightRay19 };

	SequentialRayTracing seqTraceE1_field01(OptSysE2);
	seqTraceE1_field01.seqRayTracingWithVectorOfLightRays(lightRay_field01);

	// distance to image surface
	real distance_imaSurface_10 = seqTraceE1_field01.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[0].getTotalSteps();
	real distance_imaSurface_11 = seqTraceE1_field01.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[1].getTotalSteps();
	real distance_imaSurface_12 = seqTraceE1_field01.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[2].getTotalSteps();
	real distance_imaSurface_13 = seqTraceE1_field01.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[3].getTotalSteps();
	real distance_imaSurface_14 = seqTraceE1_field01.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[4].getTotalSteps();
	real distance_imaSurface_15 = seqTraceE1_field01.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[5].getTotalSteps();
	real distance_imaSurface_16 = seqTraceE1_field01.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[6].getTotalSteps();
	real distance_imaSurface_17 = seqTraceE1_field01.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[7].getTotalSteps();
	real distance_imaSurface_18 = seqTraceE1_field01.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[8].getTotalSteps();
	real distance_imaSurface_19 = seqTraceE1_field01.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[9].getTotalSteps();

	VectorStructR3 directionRayToTraceack_10 = -1.0 * seqTraceE1_field01.getAllInterInfosOfSurf_i(5)[0].getDirectionRayUnit();
	VectorStructR3 directionRayToTraceack_11 = -1.0 * seqTraceE1_field01.getAllInterInfosOfSurf_i(5)[1].getDirectionRayUnit();
	VectorStructR3 directionRayToTraceack_12 = -1.0 * seqTraceE1_field01.getAllInterInfosOfSurf_i(5)[2].getDirectionRayUnit();
	VectorStructR3 directionRayToTraceack_13 = -1.0 * seqTraceE1_field01.getAllInterInfosOfSurf_i(5)[3].getDirectionRayUnit();
	VectorStructR3 directionRayToTraceack_14 = -1.0 * seqTraceE1_field01.getAllInterInfosOfSurf_i(5)[4].getDirectionRayUnit();
	VectorStructR3 directionRayToTraceack_15 = -1.0 * seqTraceE1_field01.getAllInterInfosOfSurf_i(5)[5].getDirectionRayUnit();
	VectorStructR3 directionRayToTraceack_16 = -1.0 * seqTraceE1_field01.getAllInterInfosOfSurf_i(5)[6].getDirectionRayUnit();
	VectorStructR3 directionRayToTraceack_17 = -1.0 * seqTraceE1_field01.getAllInterInfosOfSurf_i(5)[7].getDirectionRayUnit();
	VectorStructR3 directionRayToTraceack_18 = -1.0 * seqTraceE1_field01.getAllInterInfosOfSurf_i(5)[8].getDirectionRayUnit();
	VectorStructR3 directionRayToTraceack_19 = -1.0 * seqTraceE1_field01.getAllInterInfosOfSurf_i(5)[9].getDirectionRayUnit();

	VectorStructR3 interPointIma_10 = seqTraceE1_field01.getAllInterPointsAtSurface_i_filtered(5)[0];
	VectorStructR3 interPointIma_11 = seqTraceE1_field01.getAllInterPointsAtSurface_i_filtered(5)[1];
	VectorStructR3 interPointIma_12 = seqTraceE1_field01.getAllInterPointsAtSurface_i_filtered(5)[2];
	VectorStructR3 interPointIma_13 = seqTraceE1_field01.getAllInterPointsAtSurface_i_filtered(5)[3];
	VectorStructR3 interPointIma_14 = seqTraceE1_field01.getAllInterPointsAtSurface_i_filtered(5)[4];
	VectorStructR3 interPointIma_15 = seqTraceE1_field01.getAllInterPointsAtSurface_i_filtered(5)[5];
	VectorStructR3 interPointIma_16 = seqTraceE1_field01.getAllInterPointsAtSurface_i_filtered(5)[6];
	VectorStructR3 interPointIma_17 = seqTraceE1_field01.getAllInterPointsAtSurface_i_filtered(5)[7];
	VectorStructR3 interPointIma_18 = seqTraceE1_field01.getAllInterPointsAtSurface_i_filtered(5)[8];
	VectorStructR3 interPointIma_19 = seqTraceE1_field01.getAllInterPointsAtSurface_i_filtered(5)[9];

	Ray_LLT ray10_back(/*origin*/interPointIma_10, /*direction*/directionRayToTraceack_10, 1.0);
	Ray_LLT ray11_back(/*origin*/interPointIma_11, /*direction*/directionRayToTraceack_11, 1.0);
	Ray_LLT ray12_back(/*origin*/interPointIma_12, /*direction*/directionRayToTraceack_12, 1.0);
	Ray_LLT ray13_back(/*origin*/interPointIma_13, /*direction*/directionRayToTraceack_13, 1.0);
	Ray_LLT ray14_back(/*origin*/interPointIma_14, /*direction*/directionRayToTraceack_14, 1.0);
	Ray_LLT ray15_back(/*origin*/interPointIma_15, /*direction*/directionRayToTraceack_15, 1.0);
	Ray_LLT ray16_back(/*origin*/interPointIma_16, /*direction*/directionRayToTraceack_16, 1.0);
	Ray_LLT ray17_back(/*origin*/interPointIma_17, /*direction*/directionRayToTraceack_17, 1.0);
	Ray_LLT ray18_back(/*origin*/interPointIma_18, /*direction*/directionRayToTraceack_18, 1.0);
	Ray_LLT ray19_back(/*origin*/interPointIma_19, /*direction*/directionRayToTraceack_19, 1.0);

	LightRayStruct lightRay10_back(Light500, ray10_back, 1);
	LightRayStruct lightRay11_back(Light500, ray11_back, 1);
	LightRayStruct lightRay12_back(Light500, ray12_back, 1);
	LightRayStruct lightRay13_back(Light500, ray13_back, 1);
	LightRayStruct lightRay14_back(Light500, ray14_back, 1);
	LightRayStruct lightRay15_back(Light500, ray15_back, 1);
	LightRayStruct lightRay16_back(Light500, ray16_back, 1);
	LightRayStruct lightRay17_back(Light500, ray17_back, 1);
	LightRayStruct lightRay18_back(Light500, ray18_back, 1);
	LightRayStruct lightRay19_back(Light500, ray19_back, 1);

	std::vector<LightRayStruct> lightRay10_traceBack{ lightRay10_back ,lightRay11_back ,lightRay12_back ,lightRay13_back ,lightRay14_back ,lightRay15_back ,lightRay16_back ,lightRay17_back ,lightRay18_back,lightRay19_back };

	OpticalSystem_LLT optSys_LLT_exitPupilPlan;
	optSys_LLT_exitPupilPlan.fillVectorSurfaceAndInteractingData(0, exitPupil.clone(), doNothing.clone());
	SequentialRayTracing seqTraceImaToExitPlan_back(optSys_LLT_exitPupilPlan);
	seqTraceImaToExitPlan_back.sequentialRayTracing(lightRay10_back);
	VectorStructR3 interPointChiefRayExitPupil01 = seqTraceImaToExitPlan_back.getAllInterPointsAtSurface_i_filtered(0)[0];

	VectorStructR3 directionRefSphere01 = interPointIma_10 - interPointChiefRayExitPupil01;
	real radiusRefSphere01 = Math::lengthOfVector(directionRefSphere01);

	SphericalSurface_LLT refSphereAtExitPupil_01(/*radius*/radiusRefSphere01, /*semiHeight*/99.0, /*Apex of the sphere*/interPointChiefRayExitPupil01, /*Direction*/ directionRefSphere01, /*refIndexSideA*/refractiveIndexAir, /*refIndexSideB*/refractiveIndexAir);

	OpticalSystem_LLT optSysImaAndRefSphere;
	optSysImaAndRefSphere.fillVectorSurfaceAndInteractingData(0, refSphereAtExitPupil_01.clone(), doNothing.clone());
	SequentialRayTracing seqTrace_back_01(optSysImaAndRefSphere);
	seqTrace_back_01.seqRayTracingWithVectorOfLightRays(lightRay10_traceBack);

	real distanceBack_10 = seqTrace_back_01.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[0].getTotalSteps();
	real distanceBack_11 = seqTrace_back_01.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[1].getTotalSteps();
	real distanceBack_12 = seqTrace_back_01.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[2].getTotalSteps();
	real distanceBack_13 = seqTrace_back_01.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[3].getTotalSteps();
	real distanceBack_14 = seqTrace_back_01.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[4].getTotalSteps();
	real distanceBack_15 = seqTrace_back_01.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[5].getTotalSteps();
	real distanceBack_16 = seqTrace_back_01.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[6].getTotalSteps();
	real distanceBack_17 = seqTrace_back_01.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[7].getTotalSteps();
	real distanceBack_18 = seqTrace_back_01.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[8].getTotalSteps();
	real distanceBack_19 = seqTrace_back_01.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[9].getTotalSteps();

	real referenceDistance01 = distance_imaSurface_10 - distanceBack_10;

	real OPD11 = ((referenceDistance01 - (distance_imaSurface_11 - distanceBack_11)) / Light500.getWavelength()) * 1000000;
	real OPD12 = ((referenceDistance01 - (distance_imaSurface_12 - distanceBack_12)) / Light500.getWavelength()) * 1000000;
	real OPD13 = ((referenceDistance01 - (distance_imaSurface_13 - distanceBack_13)) / Light500.getWavelength()) * 1000000;
	real OPD14 = ((referenceDistance01 - (distance_imaSurface_14 - distanceBack_14)) / Light500.getWavelength()) * 1000000;
	real OPD15 = ((referenceDistance01 - (distance_imaSurface_15 - distanceBack_15)) / Light500.getWavelength()) * 1000000;
	real OPD16 = ((referenceDistance01 - (distance_imaSurface_16 - distanceBack_16)) / Light500.getWavelength()) * 1000000;
	real OPD17 = ((referenceDistance01 - (distance_imaSurface_17 - distanceBack_17)) / Light500.getWavelength()) * 1000000;
	real OPD18 = ((referenceDistance01 - (distance_imaSurface_18 - distanceBack_18)) / Light500.getWavelength()) * 1000000;
	real OPD19 = ((referenceDistance01 - (distance_imaSurface_19 - distanceBack_19)) / Light500.getWavelength()) * 1000000;

	std::vector<real> calcOPD_01 = { OPD11 ,OPD12 ,OPD13 ,OPD14 ,OPD15 ,OPD16 ,OPD17 ,OPD18 ,OPD19 };
	std::vector<real> refOPD_01 = { 0.585,1.099,14.009,9.363,0.578,4.694,0.871,2.366, 1.774 };

	bool checkOPD_01 = Math::compateTwoSTDVector_tolerance(calcOPD_01, refOPD_01, 0.01);
	checkOPD.push_back(checkOPD_01);


	bool output = Math::checkTrueOfVectorElements(checkOPD);
	return output;

}


// E2
bool TestOPD::checkE2()
{
	std::vector<bool> checkOPD;

	RefractedRay_LLT refrac;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light500;
	Light500.setWavelength(500.0);
	Absorb_LLT absorb;
		
	SphericalSurface_LLT S0_E2(/*radius*/10.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 10.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S1_E2(/*radius*/10.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 15.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	ApertureStop_LLT S2_E2(0.75, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT S3_E2(/*radius*/7.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 30.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	SphericalSurface_LLT S4_E2(/*radius*/7.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 35.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	PlanGeometry_LLT S5_E2(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	// build the optical system
	OpticalSystem_LLT OptSys_E2;
	OptSys_E2.fillVectorSurfaceAndInteractingData(0, S0_E2.clone(), refrac.clone());
	OptSys_E2.fillVectorSurfaceAndInteractingData(1, S1_E2.clone(), refrac.clone());
	OptSys_E2.fillVectorSurfaceAndInteractingData(2, S2_E2.clone(), doNothing.clone());
	OptSys_E2.fillVectorSurfaceAndInteractingData(3, S3_E2.clone(), refrac.clone());
	OptSys_E2.fillVectorSurfaceAndInteractingData(4, S4_E2.clone(), refrac.clone());
	OptSys_E2.fillVectorSurfaceAndInteractingData(5, S5_E2.clone(), absorb.clone());

	OPD testOPDE2;
	VectorStructR3 startPointRayOptA{ 0.0,0.0,0.0 };

	real OPD11 = testOPDE2.OPD_singelRay_obj(OptSys_E2, startPointRayOptA, 1.0, 1.0, Light500);
	real refOPD11 = 12.853;
	bool checkOPD11 = Math::compareTwoNumbers_tolerance(OPD11, refOPD11, 0.01);
	checkOPD.push_back(checkOPD11);
	
	real OPD051 = testOPDE2.OPD_singelRay_obj(OptSys_E2, startPointRayOptA, 0.5, 1.0, Light500);
	real refOPD051 = 7.358;
	bool checkOPD051 = Math::compareTwoNumbers_tolerance(OPD051, refOPD051, 0.01);
	checkOPD.push_back(checkOPD051);
	
	real OPDneg0507 = testOPDE2.OPD_singelRay_obj(OptSys_E2, startPointRayOptA, -0.5, 0.7, Light500);
	real refOPDneg0507 = 4.092;
	bool checkOPDneg0507 = Math::compareTwoNumbers_tolerance(OPDneg0507, refOPDneg0507, 0.01);
	checkOPD.push_back(checkOPDneg0507);
	
	real OPDneg05neg03 = testOPDE2.OPD_singelRay_obj(OptSys_E2, startPointRayOptA, -0.5, -0.3, Light500);
	real refOPDneg05neg03 = 1.787;
	bool checkOPDneg05neg03 = Math::compareTwoNumbers_tolerance(OPDneg05neg03, refOPDneg05neg03, 0.01);
	checkOPD.push_back(checkOPDneg05neg03);
	
	real OPDn07neg03 = testOPDE2.OPD_singelRay_obj(OptSys_E2, startPointRayOptA, 0.7, -0.3, Light500);
	real refOPD07neg03 = 3.143;
	bool checkOPD07neg03 = Math::compareTwoNumbers_tolerance(OPDn07neg03, refOPD07neg03, 0.01);
	checkOPD.push_back(checkOPD07neg03);
	
	VectorStructR3 startPointField_0{ 0.0,1.0,0.0 };
	real OPDfield_0 = testOPDE2.OPD_singelRay_obj(OptSys_E2, startPointField_0, 1.0, 0.0, Light500);
	real refOPDfield_0 = 7.870;
	bool checkOPD_0 = Math::compareTwoNumbers_tolerance(OPDfield_0, refOPDfield_0, 0.01);
	checkOPD.push_back(checkOPD_0);

	VectorStructR3 startPointField_1{ 0.5,0.5,0.0 };
	real OPDfield_1 = testOPDE2.OPD_singelRay_obj(OptSys_E2, startPointField_1, 0.5, 0.5, Light500);
	real refOPDfield_1 = 3.490;
	bool checkOPD_1 = Math::compareTwoNumbers_tolerance(OPDfield_1, refOPDfield_1, 0.01);
	checkOPD.push_back(checkOPD_1);

	VectorStructR3 startPointField_2{ -0.3,0.7,0.0 };
	real OPDfield_2 = testOPDE2.OPD_singelRay_obj(OptSys_E2, startPointField_2, -0.3, 0.7, Light500);
	real refOPDfield_2 = 4.237;
	bool checkOPD_2 = Math::compareTwoNumbers_tolerance(OPDfield_2, refOPDfield_2, 0.01);
	checkOPD.push_back(checkOPD_2);
	
	VectorStructR3 startPointField_3{ 0.5,-0.8,0.0 };
	real OPDfield_3 = testOPDE2.OPD_singelRay_obj(OptSys_E2, startPointField_3, 0.8, 0.2, Light500);
	real refOPDfield_3 = 4.829;
	bool checkOPD_3 = Math::compareTwoNumbers_tolerance(OPDfield_3, refOPDfield_3, 0.01);
	checkOPD.push_back(checkOPD_3);

	bool output = Math::checkTrueOfVectorElements(checkOPD);
	return output;
}

// E3
bool TestOPD::checkE3()
{
	std::vector<bool> checkOPD;

	RefractedRay_LLT refrac;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light500;
	Light500.setWavelength(500.0);
	Absorb_LLT absorb;

	SphericalSurface_LLT S0_E3(/*radius*/10.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 10.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S1_E3(/*radius*/10.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 15.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	ApertureStop_LLT S2_E3(1.25, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT S3_E3(/*radius*/10.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 25.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.6, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S4_E3(/*radius*/20.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 30.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.6, /*refIndexSideB*/1.0);
	PlanGeometry_LLT S5_E3(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	// build the optical system
	OpticalSystem_LLT OptSys_E3;
	OptSys_E3.fillVectorSurfaceAndInteractingData(0, S0_E3.clone(), refrac.clone());
	OptSys_E3.fillVectorSurfaceAndInteractingData(1, S1_E3.clone(), refrac.clone());
	OptSys_E3.fillVectorSurfaceAndInteractingData(2, S2_E3.clone(), doNothing.clone());
	OptSys_E3.fillVectorSurfaceAndInteractingData(3, S3_E3.clone(), refrac.clone());
	OptSys_E3.fillVectorSurfaceAndInteractingData(4, S4_E3.clone(), refrac.clone());
	OptSys_E3.fillVectorSurfaceAndInteractingData(5, S5_E3.clone(), absorb.clone());

	// check the start system
	std::vector<VectorStructR3> startOptA = { {0.0,0.0,0.0} };
	std::vector<real> ref_rms = { {1447.13} };
	bool checkStartSys = oftenUse::checkOptSysLLT_Equal_Better_Zemax(OptSys_E3, startOptA, ref_rms, 0.01, compareTOM_Zemax::comEqual);
	checkOPD.push_back(checkStartSys);

	OPD testOPDE3;
	VectorStructR3 startPointRayOptA{ 0.0,0.0,0.0 };

	//real OPD11 = testOPDE3.OPD_singelRay_obj(OptSys_E3, startPointRayOptA, 1.0, 1.0, Light500);
	//real refOPD11 = -275.229;
	//bool checkOPD11 = Math::compareTwoNumbers_tolerance(OPD11, refOPD11, 0.1);
	//checkOPD.push_back(checkOPD11);

	//real OPD_05neg002 = testOPDE3.OPD_singelRay_obj(OptSys_E3, startPointRayOptA, 0.5, -0.02, Light500);
	//real refOPD_05neg002 = -35.462;
	//bool checkOPD_05neg002 = Math::compareTwoNumbers_tolerance(OPD_05neg002, refOPD_05neg002, 0.1);
	//checkOPD.push_back(checkOPD_05neg002);

	//real OPD_neg0308 = testOPDE3.OPD_singelRay_obj(OptSys_E3, startPointRayOptA, -0.3, 0.8, Light500);
	//real refOPD_neg0308 = -102.553;
	//bool checkOPD_neg0308 = Math::compareTwoNumbers_tolerance(OPD_neg0308, refOPD_neg0308, 0.1);
	//checkOPD.push_back(checkOPD_neg0308);

	//VectorStructR3 startPointField0503{ 0.5,0.3,0.0 };
	//real OPD_0806 = testOPDE3.OPD_singelRay_obj(OptSys_E3, startPointField0503, 0.8, 0.6, Light500);
	//real refOPD_0806 = -140.813;
	//bool checkOPD_0806 = Math::compareTwoNumbers_tolerance(OPD_0806, refOPD_0806, 1.0);
	//checkOPD.push_back(checkOPD_0806);

	//VectorStructR3 startPointField0705{ 0.7,0.5,0.0 };
	//real OPD_0705 = testOPDE3.OPD_singelRay_obj(OptSys_E3, startPointField0705, 0.7, 0.5, Light500);
	//real refOPD_0705 = -102.601;
	//bool checkOPD_0705 = Math::compareTwoNumbers_tolerance(OPD_0705, refOPD_0705, 1.0);
	//checkOPD.push_back(checkOPD_0705);

	VectorStructR3 startPointField1neg02{ 1.0,-0.2,0.0 };
	real OPD_neg04neg06 = testOPDE3.OPD_singelRay_obj(OptSys_E3, startPointField1neg02, -0.4, -0.6, Light500);
	real refOPD_neg04neg06 = -68.870;
	bool checkOPD_neg04neg06 = Math::compareTwoNumbers_tolerance(OPD_neg04neg06, refOPD_neg04neg06, 2.0);
	checkOPD.push_back(checkOPD_neg04neg06);

	bool output = Math::checkTrueOfVectorElements(checkOPD);
	return output;
}


// E4
bool TestOPD::checkE4()
{
	std::vector<bool> checkOPD;

	RefractedRay_LLT refrac;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light500;
	Light500.setWavelength(500.0);
	Absorb_LLT absorb;

	SphericalSurface_LLT S0_E3(/*radius*/10.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 10.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S1_E3(/*radius*/10.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 15.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	ApertureStop_LLT S2_E3(1.25, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT S3_E3(/*radius*/10.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 25.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.6, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S4_E3(/*radius*/20.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 30.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.6, /*refIndexSideB*/1.0);
	PlanGeometry_LLT S5_E3(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	// build the optical system
	OpticalSystem_LLT OptSys_E3;
	OptSys_E3.fillVectorSurfaceAndInteractingData(0, S0_E3.clone(), refrac.clone());
	OptSys_E3.fillVectorSurfaceAndInteractingData(1, S1_E3.clone(), refrac.clone());
	OptSys_E3.fillVectorSurfaceAndInteractingData(2, S2_E3.clone(), doNothing.clone());
	OptSys_E3.fillVectorSurfaceAndInteractingData(3, S3_E3.clone(), refrac.clone());
	OptSys_E3.fillVectorSurfaceAndInteractingData(4, S4_E3.clone(), refrac.clone());
	OptSys_E3.fillVectorSurfaceAndInteractingData(5, S5_E3.clone(), absorb.clone());

	CardinalPoints cardinalPoint(OptSys_E3, objectPoint_inf_obj::obj);
	real positionExitPupilGlobal_Z = cardinalPoint.getEXPP_globalCoori();
	real exitPupil_refIma = cardinalPoint.getEXPP_lastSurface();
	bool checkExitPupil = Math::compareTwoNumbers_tolerance(exitPupil_refIma, -10.765, 0.01);
	checkOPD.push_back(checkExitPupil);
	real posEXP_global = S5_E3.getPoint().getZ() + exitPupil_refIma;
	bool checkEXP_global = Math::compareTwoNumbers_tolerance(positionExitPupilGlobal_Z, posEXP_global, 0.01);
	checkOPD.push_back(checkEXP_global);

	// *** chief ray ***
	VectorStructR3 startPointChiefRay = { 1.0,-0.2,0.0 };
	VectorStructR3 interPointFirstSurfaceChiefRay = { 0.66836378124, -0.13367275625, 10.023255969 };
	VectorStructR3 directionChiefRay = interPointFirstSurfaceChiefRay - startPointChiefRay;
	Ray_LLT cheifRay(startPointChiefRay, directionChiefRay, 1.0);
	LightRayStruct chiefLightRay(Light500, cheifRay, true);

	SequentialRayTracing seqTraceOptSys(OptSys_E3);
	seqTraceOptSys.sequentialRayTracing(chiefLightRay);
	VectorStructR3 interPointImaSurface = seqTraceOptSys.getAllInterPointsAtSurface_i_filtered(5)[0];

	// *** build optical system with exit pupil
	PlanGeometry_LLT ExitPupil(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,positionExitPupilGlobal_Z }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	OpticalSystem_LLT OptSys_E3_includingExitPupil;
	OptSys_E3_includingExitPupil.fillVectorSurfaceAndInteractingData(0, S0_E3.clone(), refrac.clone());
	OptSys_E3_includingExitPupil.fillVectorSurfaceAndInteractingData(1, S1_E3.clone(), refrac.clone());
	OptSys_E3_includingExitPupil.fillVectorSurfaceAndInteractingData(2, S2_E3.clone(), doNothing.clone());
	OptSys_E3_includingExitPupil.fillVectorSurfaceAndInteractingData(3, ExitPupil.clone(), doNothing.clone());
	OptSys_E3_includingExitPupil.fillVectorSurfaceAndInteractingData(4, S3_E3.clone(), refrac.clone());
	OptSys_E3_includingExitPupil.fillVectorSurfaceAndInteractingData(5, S4_E3.clone(), refrac.clone());
	OptSys_E3_includingExitPupil.fillVectorSurfaceAndInteractingData(6, S5_E3.clone(), absorb.clone());

	SequentialRayTracing seqTraceChiefRay_sysIncExP(OptSys_E3_includingExitPupil);
	seqTraceChiefRay_sysIncExP.sequentialRayTracing(chiefLightRay);

	VectorStructR3 interPointExitPupilChiefRay = seqTraceChiefRay_sysIncExP.getAllInterPointsAtSurface_i_filtered(3)[0];
	VectorStructR3 interPointImaSurfaceChiefRay = seqTraceChiefRay_sysIncExP.getAllInterPointsAtSurface_i_filtered(6)[0];
	VectorStructR3 directionRefSphere = interPointImaSurfaceChiefRay - interPointExitPupilChiefRay;
	real radiusRefSphere = Math::lengthOfVector(directionRefSphere);

	// check both interpoints with the ima surface
	bool checkInterImaChiefRay = Math::compareTwoVectorStructR3_tolerance(interPointImaSurfaceChiefRay, interPointImaSurface, 0.001);
	checkOPD.push_back(checkInterImaChiefRay);

	// trace wanted ray
	VectorStructR3 startPointWantedRay = { 1.0, -0.2,0.0 };
	VectorStructR3 interPointFirstSurfaceWantedRay = { 0.22022158989, -0.80847303321, 10.035168150 };
	VectorStructR3 directionWanterRay = interPointFirstSurfaceWantedRay - startPointWantedRay;
	Ray_LLT wantedRay(startPointWantedRay, directionWanterRay, 1.0);
	LightRayStruct wantedLightRay(Light500, wantedRay, true);

	SequentialRayTracing seqTraceWantedRay(OptSys_E3);
	seqTraceWantedRay.sequentialRayTracing(wantedLightRay);

	VectorStructR3 interPointWantedRayImaSurface = seqTraceWantedRay.getAllInterPointsAtSurface_i_filtered(5)[0];
	VectorStructR3 directionRayWantedImaSurface = seqTraceWantedRay.getAllInterInfosOfSurf_i(5)[0].getDirectionRayUnit();

	VectorStructR3 interPointWantedBeforeImaSurface = seqTraceWantedRay.getAllInterPointsAtSurface_i_filtered(4)[0];
	VectorStructR3 directionWantedBeforImaToIma = interPointWantedRayImaSurface - interPointWantedBeforeImaSurface;
	VectorStructR3 directionWantedBeforImaToIma_unit = Math::unitVector(directionWantedBeforImaToIma);
	bool checkDirection = Math::compareTwoVectorStructR3_tolerance(directionRayWantedImaSurface, directionWantedBeforImaToIma_unit, 0.01);
	checkOPD.push_back(checkDirection);

	// Reference sphere
	SphericalSurface_LLT ReferenceSphere(/*radius*/radiusRefSphere, /*semiHeight*/5.0, /*Apex of the sphere*/interPointExitPupilChiefRay, /*Direction*/ directionRefSphere, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	// *** trace the ray back
	Ray_LLT chiefRayTraceBack(interPointImaSurfaceChiefRay, -1.0 * directionRefSphere, 1.0);
	LightRayStruct chiefLightRayBack(Light500, chiefRayTraceBack, true);

	Ray_LLT wantedRayTraceBack(interPointWantedRayImaSurface, -1.0 * directionRayWantedImaSurface, 1.0);
	LightRayStruct wanterLightRayBack(Light500, wantedRayTraceBack, true);

	OpticalSystem_LLT optSysTraceBack;
	optSysTraceBack.fillVectorSurfaceAndInteractingData(0, ReferenceSphere.clone(), doNothing.clone());

	SequentialRayTracing seqTraceBack(optSysTraceBack);
	seqTraceBack.sequentialRayTracing(chiefLightRayBack);
	seqTraceBack.sequentialRayTracing(wanterLightRayBack);

	// lenght start chief ray
	real lengthStarChiefRay = Math::lengthOfVector(directionChiefRay);

	// length wanted ray
	real lengthStartWantedRay = Math::lengthOfVector(directionWanterRay);

	// length cheif ray
	real lengthChief_1 = seqTraceOptSys.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[0].getTotalSteps();
	real lengthChief_back = seqTraceBack.getAllInterInfosOfSurf_i(0)[0].getStepsToWalk();
	real refLength = lengthChief_1 - lengthChief_back;

	// length wanted ray
	real lengthWanted_1 = seqTraceWantedRay.getInterInf_PosSurface_TotalSteps_ofSur_i(5)[0].getTotalSteps();
	real lengthWanted_back = seqTraceBack.getAllInterInfosOfSurf_i(0)[1].getStepsToWalk();
	real lengthWanted = lengthWanted_1 - lengthWanted_back;

	real calcOPD_1 = ((refLength - lengthWanted) / Light500.getWavelength()) * 1000000.0;
	OPD refOPD;
	real calcOPD_2 = refOPD.OPD_singelRay_obj(OptSys_E3, { 1.0,-0.2,0.0 },-0.4,-0.6,Light500);
	bool checkCalcOPD = Math::compareTwoNumbers_tolerance(calcOPD_1, calcOPD_2, 0.01);
	checkOPD.push_back(checkCalcOPD);



	bool output = Math::checkTrueOfVectorElements(checkOPD);
	return output;

}