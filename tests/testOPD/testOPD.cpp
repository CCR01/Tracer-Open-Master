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

typedef std::shared_ptr< SurfaceIntersectionRay_LLT > surfacePtr_LLT;


bool TestOPD::checkOPD_superFct()
{

	std::vector<bool> workOPD;// hier gehts dann weiter

	// E0
	bool chE0 = checkE0();
	workOPD.push_back(chE0);

	//// E1
	//bool chE1 = checkE1();
	//workOPD.push_back(chE1);

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
	ApertureStop_LLT ApertureStop0E0(1.0, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT S0(/*radius*/15.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 40.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S1(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 45.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT Plan0(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,62.073 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	
	SphericalSurface_LLT RefSpherAtExitPupilPlanExP(/*radius*/12.158, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0, 0.0, 74.231 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);

	// build opitcal system
	// the exit pupil is behing the paraxial image point
	// --> Zemax place a plan surface at the exit pupil
	// -- we place PlanExP at the exit pupil
	OpticalSystem_LLT OptSys1;
	OptSys1.fillVectorSurfaceAndInteractingData(0, ApertureStop0E0.clone(), doNothing.clone());
	OptSys1.fillVectorSurfaceAndInteractingData(1, S0.clone(), refrac.clone());
	OptSys1.fillVectorSurfaceAndInteractingData(2, S1.clone(), refrac.clone());
	OptSys1.fillVectorSurfaceAndInteractingData(3, Plan0.clone(), doNothing.clone());
	OptSys1.fillVectorSurfaceAndInteractingData(4, RefSpherAtExitPupilPlanExP.clone(), doNothing.clone());

	//**********************************************************************************************
	// check optical path with marginal ray Py=1
	SequentialRayTracing SeqTrac1(OptSys1);
	SeqTrac1.sequentialRayTracing(LightRayMargPy1);
	real distance0 = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(0).at(0).getIntersecInfos().getStepsToWalk();
	real distance1 = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(1).at(0).getIntersecInfos().getStepsToWalk();
	real distance2 = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(2).at(0).getIntersecInfos().getStepsToWalk();
	real distance3 = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(0).getIntersecInfos().getStepsToWalk();
	real distance4 = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(0).getIntersecInfos().getStepsToWalk();

	real sumOPDPy1 = distance0 + distance1 + distance2 + distance3 + distance4;
	real OPDPy1sys = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(0).getTotalSteps();
	bool checkOPDPy = Math::compareTwoNumbers_decimals(sumOPDPy1, OPDPy1sys, 7);
	checkOPD.push_back(checkOPDPy);
	//**********************************************************************************************

	// check optical path with ray on optical axis
	SeqTrac1.clearAllTracedRays();
	SeqTrac1.sequentialRayTracing(LightRayOptAx);
	real distance0OA = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(0).at(0).getIntersecInfos().getStepsToWalk();
	real distance1OA = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(1).at(0).getIntersecInfos().getStepsToWalk();
	real distance2OA = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(2).at(0).getIntersecInfos().getStepsToWalk();
	real distance3OA = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(0).getIntersecInfos().getStepsToWalk();
	real distance4OA = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(0).getIntersecInfos().getStepsToWalk();

	real sumOPDoptAx = distance0OA + distance1OA + distance2OA + distance3OA + distance4OA;
	real OPDoptAxSys = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(0).getTotalSteps();
	bool checkOPDoptAx = Math::compareTwoNumbers_decimals(sumOPDoptAx, OPDoptAxSys, 7);
	checkOPD.push_back(checkOPDoptAx);


	SeqTrac1.clearAllTracedRays();
	SeqTrac1.sequentialRayTracing(LightRayPyHalf);
	real sumOPD_Py_Half = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(0).getTotalSteps();
	//**********************************************************************************************
	real OPDPy1 = (sumOPDoptAx - sumOPDPy1) / 1000; //µm
	//**********************************************************************************************
	bool checkOPDPy1 = Math::compareTwoNumbers_tolerance(OPDPy1 / (Light500.getWavelength() / 1000), 7.656, 0.001);
	//**********************************************************************************************
	real OPDYHalf = (sumOPDoptAx - sumOPD_Py_Half) / 1000; //µm
	 //**********************************************************************************************
	bool checkOPDYHalf = Math::compareTwoNumbers_tolerance(OPDYHalf / (Light500.getWavelength() / 1000), 0.393, 0.001);
	//**********************************************************************************************
	std::vector<LightRayStruct> lightRayAlong_YE1 = SequentialRayTracing::lightRayAlongY({ 0.0,0.0,0.0 }, 11, 20, -1, +1, 550, 1.0);
	SeqTrac1.clearAllTracedRays();
	SeqTrac1.seqRayTracingWithVectorOfLightRays(lightRayAlong_YE1);
	double referenceLenght = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(4).getTotalSteps();
	double OPDPX_0 = ((referenceLenght - SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(0).getTotalSteps()) / Light500.getWavelength()) * 1000000 ;
	double OPDPX_1 = ((referenceLenght - SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(1).getTotalSteps()) / Light500.getWavelength()) * 1000000;
	double OPDPX_2 = ((referenceLenght - SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(2).getTotalSteps()) / Light500.getWavelength()) * 1000000;
	double OPDPX_3 = ((referenceLenght - SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(3).getTotalSteps()) / Light500.getWavelength()) * 1000000;
	double OPDPX_4 = ((referenceLenght - SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(4).getTotalSteps()) / Light500.getWavelength()) * 1000000;
	double OPDPX_5 = ((referenceLenght - SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(5).getTotalSteps()) / Light500.getWavelength()) * 1000000;
	double OPDPX_6 = ((referenceLenght - SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(6).getTotalSteps()) / Light500.getWavelength()) * 1000000;
	double OPDPX_7 = ((referenceLenght - SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(7).getTotalSteps()) / Light500.getWavelength()) * 1000000;
	double OPDPX_8 = ((referenceLenght - SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(8).getTotalSteps()) / Light500.getWavelength()) * 1000000;
	double OPDPX_9 = ((referenceLenght - SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(9).getTotalSteps()) / Light500.getWavelength()) * 1000000;
	double OPDPX_10 = ((referenceLenght - SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(4).at(10).getTotalSteps()) / Light500.getWavelength()) * 1000000;

	std::vector<double> allOPD = { OPDPX_0, OPDPX_1 , OPDPX_2 ,OPDPX_3 , OPDPX_4 ,OPDPX_5, OPDPX_6 , OPDPX_7, OPDPX_8 , OPDPX_9 , OPDPX_10 };
	std::vector<double> refAllOPD = { 7.656, 2.855, 0.839, 0.157, 9.430E-3, 0.0, 9.430E-3, 0.157, 0.839, 2.855, 7.656 };
	//**********************************************************************************************
	bool checkOPDE1 = Math::compateTwoSTDVector_tolerance(allOPD, refAllOPD, 0.01);
	//**********************************************************************************************
	checkOPD.push_back(checkOPDE1);
	//**********************************************************************************************
	//**********************************************************************************************

	hier gehts dann weiter -> strahlen, die von nem Feld kommen und nicht der optischen Achse --> referenzsphere an der Austrittspupille bekommt nen neuen Mittelpunkt!



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
	
	// check how Zemax calculate the OPD
	// exit pupil is global coordinate reference
	// Py = 1 at the exit pupil: y = 0.83106246530, z = 0
	// direction ray = (0.0,0.58363971658,1.8380709316) - (0.0, 0.83106246530, 0.0) = (0.0, -0.247422749, 1.8380709316)
	Ray_LLT RayPy1E2(/*origin*/{ 0.0, 0.83106246530, 0.0 }, /*direction*/{ 0.0, -0.247422749, 1.8380709316 }, 1.0);

	LightRayStruct LightRayE2Py1 = { Light500, RayPy1E2, 1 };

	ApertureStop_LLT ApertureStop0E0(1.0, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT S0E2(/*radius*/5.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 13 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S1E2(/*radius*/5.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 18 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S2E2(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 21 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S3E2(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 26 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	PlanGeometry_LLT ImageE2(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,31.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	// build the optical system
	// exit pupil it at position of Plan_Ex2_2
	OpticalSystem_LLT OptSysE2;
	OptSysE2.fillVectorSurfaceAndInteractingData(0, ApertureStop0E0.clone(), doNothing.clone());
	OptSysE2.fillVectorSurfaceAndInteractingData(1, S0E2.clone(), refrac.clone());
	OptSysE2.fillVectorSurfaceAndInteractingData(2, S1E2.clone(), refrac.clone());
	OptSysE2.fillVectorSurfaceAndInteractingData(3, S2E2.clone(), refrac.clone());
	OptSysE2.fillVectorSurfaceAndInteractingData(4, S3E2.clone(), refrac.clone());
	OptSysE2.fillVectorSurfaceAndInteractingData(5, ImageE2.clone(), refrac.clone());

	//**********************************************************************************************

	//// calculate OPD with start point on optical axis
	//std::vector<LightRayStruct> lightRayAlong_X_optA1 = SequentialRayTracing::lightRayAlongX({ 0.0, 0.0, 0.0 }, 5, 12.0, -1.0, 1.0, 550, 1.0);
	//std::vector<LightRayStruct> lightRayAlong_Y_optA1 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 5, 12.0, -1.0, 1.0, 550, 1.0);
	//Ray_LLT chiefRayoptA1({ 0.0,0.0,0.0 }, { 0.0,0.0,1.0 }, 0.55, 1.0);
	//LightRayStruct chiefLightRayOptA1(Light, chiefRayoptA1, 1);
	PlanGeometry_LLT exitPupil1(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,19.144876330 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	//OPD OPDoptA1(exitPupil1, OptSysE2, lightRayAlong_X_optA1, lightRayAlong_Y_optA1, chiefLightRayOptA1);
	//
	//std::vector<cv::Point2d> OPD_X_optAx1 = OPDoptA1.getPointsOPD_X();
	//std::vector<cv::Point2d> OPD_Y_optAx1 = OPDoptA1.getPointsOPD_Y();
	//
	//std::vector<real> refOPDoptA1{ 10.160700194561, 1.5657142552642, 0.0, 1.5657142552642 , 10.160700194561 };
	//std::vector<real> sysOPD_XoptA1 = OPDoptA1.getOPD_X_inVec();
	//std::vector<real> sysOPD_YoptA1 = OPDoptA1.getOPD_Y_inVec();
	//
	//bool checkOPD_XoptA1 = Math::compareTwoSTDVecors(refOPDoptA1, sysOPD_XoptA1, 3);
	//bool checkOPD_YoptA1 = Math::compareTwoSTDVecors(refOPDoptA1, sysOPD_YoptA1, 3);
//	//**********************************************************************************************
//	//checkOPD.push_back(checkOPD_XoptA1);
//	checkOPD.push_back(checkOPD_YoptA1);
//	//**********************************************************************************************
//
//	// calculate OPD with start point in the field {0.0,1.0,0.0}
//
//	std::vector<LightRayStruct> lightRayAlong_X_F1_1 = SequentialRayTracing::lightRayAlongX({ 0.0, 1.0, 0.0 }, 5, 12.0, -1.0, 1.0, 550, 1.0);
//	std::vector<LightRayStruct> lightRayAlong_Y_F1_1 = SequentialRayTracing::lightRayAlongY({ 0.0, 1.0, 0.0 }, 5, 12.0, -1.0, 1.0, 550, 1.0);
//	Ray_LLT chiefRayF1_1({ 0.0,1.0,0.0 }, { 0.0,-1.0,12.0 }, 0.550, 1.0);
//	LightRayStruct chiefLightRayF1_1(Light, chiefRayF1_1, 1);
//	OPD OPDF1_1(exitPupil1, OptSysE2, lightRayAlong_X_F1_1, lightRayAlong_Y_F1_1, chiefLightRayF1_1);
//
//	//std::vector<cv::Point2d> OPD_X_F1 = OPDF1_1.getPointsOPD_X();
//	//std::vector<cv::Point2d> OPD_Y_F1 = OPDF1_1.getPointsOPD_Y();
//
//	std::vector<real> refOPDF1_X{ 11.095197787414, 1.5657364218168, 0.0, 1.5657364218168 , 11.095197787414};
//	std::vector<real> refOPDF1_Y{ 16.831192337267, 2.5979333278438, 0.0, 1.6389782904700, 8.3923622095689};
//
//	std::vector<real> sysOPD_XF1 = OPDF1_1.getOPD_X_inVec();
//	std::vector<real> sysOPD_YF1 = OPDF1_1.getOPD_Y_inVec();
//
//	bool checkOPD_XF1 = Math::compareTwoSTDVecors(sysOPD_XF1, refOPDF1_X, 1);
//	bool checkOPD_YF1 = Math::compareTwoSTDVecors(sysOPD_YF1, refOPDF1_Y, 1);
//
//	//**********************************************************************************************
//	checkOPD.push_back(checkOPD_XF1);
//	checkOPD.push_back(checkOPD_YF1);
//	//**********************************************************************************************
//
//	// surfaces of the optical system
	SphericalSurface_LLT S0E3(/*radius*/15.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 40.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S1E3(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 45.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT PlanE3(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	//
	OpticalSystem_LLT optSysE3;
	optSysE3.fillVectorSurfaceAndInteractingData(0, ApertureStop0E0.clone(), doNothing.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(1, S0E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(2, S1E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(3, PlanE3.clone(), refrac.clone());
	//
	PlanGeometry_LLT exitPupilE3(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,74.230762215072 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	surfacePtr_LLT exitPupilE3_ptr = exitPupilE3.clone();

	// OPD on optical axis
	std::vector<LightRayStruct> lightRayAlong_X_optA_E3 = SequentialRayTracing::lightRayAlongX({ 0.0, 0.0, 0.0 }, 5, 20.0, -1.0, 1.0, 550, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_optA_E3 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 5, 20.0, -1.0, 1.0, 550, 1.0);

	Ray_LLT chiefRayOptA_E3({ 0.0,0.0,0.0 }, { 0.0,0.0,1.0 }, 1.0);
	Light_LLT Light550;
	Light550.setWavelength(550);
	LightRayStruct chiefLightRayOptA_E3(Light550, chiefRayOptA_E3, 1);

	OPD OPD3OptA(exitPupilE3_ptr, optSysE3, lightRayAlong_X_optA_E3, lightRayAlong_Y_optA_E3, chiefLightRayOptA_E3);

	std::vector<real> refVecOPD2OptA{ -19.35254296825, -5.174155019256, 0.0, -5.174155019256, -19.35254296825 };

	std::vector<real> refSysOPD3OptA_X = OPD3OptA.getOPD_X_inVec();
	std::vector<real> refSysOPD3OptA_Y = OPD3OptA.getOPD_Y_inVec();

	bool checkOPD3_OpdA_X = Math::compareTwoSTDVecors_decimals(refSysOPD3OptA_X, refVecOPD2OptA, 3);
	bool checkOPD3_OpdA_Y = Math::compareTwoSTDVecors_decimals(refSysOPD3OptA_Y, refVecOPD2OptA, 3);

	checkOPD.push_back(checkOPD3_OpdA_X);
	checkOPD.push_back(checkOPD3_OpdA_Y);

	// *****************************************************************************************************************

	// OPD on optical in field x=1
	std::vector<LightRayStruct> lightRayAlong_X_F1_E3 = SequentialRayTracing::lightRayAlongX({ -0.5, 0.0, 0.0 }, 5, 20.0, -1.0, 1.0, 550, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_F1_E3 = SequentialRayTracing::lightRayAlongY({ -0.5, 0.0, 0.0 }, 5, 20.0, -1.0, 1.0, 550, 1.0);

	Ray_LLT chiefRayF05_E3({ -0.5,0.0,0.0 }, { 0.5,0.0,20.0 }, 1.0);
	LightRayStruct chiefLightRayF1_E3(Light550, chiefRayF05_E3, 1);

	OPD OPD3F1(exitPupilE3_ptr, optSysE3, lightRayAlong_X_F1_E3, lightRayAlong_Y_F1_E3, chiefLightRayF1_E3);


	std::vector<real> refSysOPD3F05_X = OPD3F1.getOPD_X_inVec();
	std::vector<real> refSysOPD3F05_Y = OPD3F1.getOPD_Y_inVec();

	std::vector<real> refVecOPD3_F05_X{ -20.77287044221, -5.128251783727, 0.0, -4.549571108316, -13.46850743476 };
	std::vector<real> refVecOPD3_F05_Y{ -18.76999535012, -5.069924289691, 0.0, -5.069924289691, -18.76999535012 };

	bool checkOPD3_F05_X = Math::compareTwoSTDVecors_decimals(refSysOPD3F05_X, refVecOPD3_F05_X, 3);
	bool checkOPD3_F05_Y = Math::compareTwoSTDVecors_decimals(refSysOPD3F05_Y, refVecOPD3_F05_Y, 3);

	checkOPD.push_back(checkOPD3_F05_X);
	checkOPD.push_back(checkOPD3_F05_Y);

	// *****************************************************************************************************************
	// *****************************************************************************************************************
	// *****************************************************************************************************************
	// calculate global OPD
	// we build that optical system before
	// OPD on optical axis
	FillApertureStop fillAperStopE4_optAchse({ 0.0,0.0,0.0 }, 1, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, 18, 25, 1.0, Light550);
	OPD OPD4globalOPD_optAchse(/*exit pupil*/ exitPupilE3_ptr,  /*optical system*/ optSysE3,
		/*fill apertur stop with light ray*/ fillAperStopE4_optAchse.getVectorWithLightRays(), /*chief ray*/ fillAperStopE4_optAchse.getVectorWithLightRays().at(0), /*scalling*/ 0);
	OPD4globalOPD_optAchse.exportCV_MatToExcel(OPD4globalOPD_optAchse.getGlobalOPD(), "D:\optA_test.csv");
	// OPD in field
	FillApertureStop fillAperStopE4_field({ 0.0,0.5,0.0 }, 1, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, 15, 20, 1.0, Light550);
	OPD OPD4globalOPD_field(/*exit pupil*/ exitPupilE3_ptr,  /*optical system*/ optSysE3,
		/*fill apertur stop with light ray*/ fillAperStopE4_field.getVectorWithLightRays(), /*chief ray*/ fillAperStopE4_field.getVectorWithLightRays().at(0), /*scalling*/ 0);
	OPD4globalOPD_field.exportCV_MatToExcel(OPD4globalOPD_field.getGlobalOPD(), "field_test.csv");

	// *****************************************************************************************************************
	// *****************************************************************************************************************

	// *****************************************************************************************************************
	// *****************************************************************************************************************
	// *****************************************************************************************************************
	bool output = Math::checkTrueOfVectorElements(checkOPD);
	return output;

}

