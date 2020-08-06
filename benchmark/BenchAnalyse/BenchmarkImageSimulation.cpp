#pragma once
#include "BenchmarkImageSimulation.h"
#include "..\..\Image\ImageSimulation.h"
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

#include "..\..\FillAptertureStop\FillApertureStop.h"


bool BenchmarkImageSimulation::checkMethodesImgSim()
{
	typedef std::shared_ptr< SurfaceIntersectionRay_LLT > surfacePtr_LLT;

	std::vector<bool> checkImgSim;

	RefractedRay_LLT refrac;
	DoNothingInteraction_LLT doNothing;
	Absorb_LLT absorb;
	

	real Air = 1.000269;	

	
	//**********************************************************************************************
	//**********************************************************************************************
	//**********************************************************************************************
	//**********************************************************************************************
	
	// surfaces of the optical system
	ApertureStop_LLT ApertureStop0E0_S0(1.001, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT S1(/*radius*/23.86929538, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 25.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S2(/*radius*/40.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 35.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S3(/*radius*/52.30117201, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 45.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	SphericalSurface_LLT S4(/*radius*/40.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 55.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	SphericalSurface_LLT S5(/*radius*/19.02468674, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 65.0 },
			/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S6(/*radius*/50.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 75.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT PlanS7(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,85 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	
	surfacePtr_LLT ApertureStop_ptr = ApertureStop0E0_S0.clone();
	surfacePtr_LLT S1_ptr = S1.clone();
	surfacePtr_LLT S2_ptr = S2.clone();
	surfacePtr_LLT S3_ptr  = S3.clone();
	surfacePtr_LLT S4_ptr = S4.clone();
	surfacePtr_LLT S5_ptr = S5.clone();
	surfacePtr_LLT S6_ptr = S1.clone();
	surfacePtr_LLT S7_ptr = PlanS7.clone();


	// build opitcal system
	OpticalSystem_LLT OptSysE0;
	OptSysE0.fillVectorSurfaceAndInteractingData(0, ApertureStop_ptr, doNothing.clone());
	OptSysE0.fillVectorSurfaceAndInteractingData(1, S1_ptr, refrac.clone());
	OptSysE0.fillVectorSurfaceAndInteractingData(2, S2_ptr, refrac.clone());
	OptSysE0.fillVectorSurfaceAndInteractingData(3, S3_ptr, refrac.clone());
	OptSysE0.fillVectorSurfaceAndInteractingData(4, S4_ptr, refrac.clone());
	OptSysE0.fillVectorSurfaceAndInteractingData(5, S5_ptr, refrac.clone());
	OptSysE0.fillVectorSurfaceAndInteractingData(6, S6_ptr, refrac.clone());
	OptSysE0.fillVectorSurfaceAndInteractingData(7, S7_ptr, doNothing.clone());
	
	// test the system
	SequentialRayTracing seqTraceE0(OptSysE0);
	Light_LLT Light;
	Light.setWavelength(550.0);
	FillApertureStop fillAperStopE0(/*start point rays*/{ 0.0,0.0,0.0 },/*semi height of aperture stop*/ 1.0,/*point of aperture stop*/{ 0.0,0.0,20.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/ 8,/*arms*/ 10,/*refractive index*/ 1.0,/*wavelength*/ Light);
	seqTraceE0.seqRayTracingWithVectorOfLightRays(fillAperStopE0.getVectorWithLightRays());
	Spot spotE0(seqTraceE0.getAllInterPointsAtSurf_i_notFiltered(7), seqTraceE0.getAllInterPointsAtSurf_i_notFiltered(7).at(0));
	real rms = spotE0.getRMS_mm() * 1000;
	real geo = spotE0.getGeoRadius() * 1000;
	//
	
	// calculate the position of the exit Pupil
	CardinalPoints cardinalPointsE0(OptSysE0, objectPoint_inf_obj::obj);
	real exxP_E0 = cardinalPointsE0.getEXPP_globalCoori();
	real exxD_E0 = cardinalPointsE0.getEXPD() * 1.2;
	
	// rings and arms
	// TODO increase the rings and arms -> rings 22 , arms 25
	int rings = 22;
	int arms = 25;
	
	// build the exit pupil;
	PlanGeometry_LLT exitPupil(/*semiHeight*/exxD_E0, /*point*/{ 0.0,0.0,exxP_E0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	surfacePtr_LLT exitPupil_ptr = exitPupil.clone();

	// OPD on the optical axis
	FillApertureStop fillAperStopE0_00(/*start point rays*/{0.0,0.0,0.0 },/*semi height of aperture stop*/ 1.0,/*point of aperture stop*/{ 0.0,0.0,20.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/ rings,/*arms*/ arms,/*refractive index*/ 1.0,/*wavelength*/ Light);
	OPD OPD_E0_00(/*exit pupil*/exitPupil_ptr,  /*optical system*/ OptSysE0, /*fill apertur stop with light ray*/fillAperStopE0_00.getVectorWithLightRays(), /*chief ray*/ fillAperStopE0_00.getVectorWithLightRays().at(0), /*Scalling*/0);
	OPD_E0_00.exportCV_MatToExcel(OPD_E0_00.getGlobalOPD(), "D:\OPD_00.csv");
	cv::Mat PSF2 = OPD_E0_00.getPSF();

	// OPD in file x is max
	FillApertureStop fillAperStopE0_X0(/*start point rays*/{ 1.0,0.0,0.0 },/*semi height of aperture stop*/ 1.0,/*point of aperture stop*/{ 0.0,0.0,20.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/ rings,/*arms*/ arms,/*refractive index*/ 1.0,/*wavelength*/ Light);
	OPD OPD_E0_X0(/*exit pupil*/exitPupil_ptr,  /*optical system*/ OptSysE0, /*fill apertur stop with light ray*/fillAperStopE0_X0.getVectorWithLightRays(), /*chief ray*/ fillAperStopE0_X0.getVectorWithLightRays().at(0), /*Scalling*/0);
	OPD_E0_X0.exportCV_MatToExcel(OPD_E0_X0.getGlobalOPD(), "D:\OPD_X0.csv");
	cv::Mat PSF3 = OPD_E0_X0.getPSF();
	
	// OPD in file x and y is max
	FillApertureStop fillAperStopE0_XY(/*start point rays*/{ 1.0,1.0,0.0 },/*semi height of aperture stop*/ 1.0,/*point of aperture stop*/{ 0.0,0.0,20.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/ rings,/*arms*/ arms,/*refractive index*/ 1.0,/*wavelength*/ Light);
	OPD OPD_E0_XY(/*exit pupil*/exitPupil_ptr,  /*optical system*/ OptSysE0, /*fill apertur stop with light ray*/fillAperStopE0_XY.getVectorWithLightRays(), /*chief ray*/ fillAperStopE0_XY.getVectorWithLightRays().at(0), /*Scalling*/0);
	OPD_E0_XY.exportCV_MatToExcel(OPD_E0_XY.getGlobalOPD(), "D:\OPD_XY.csv");
	cv::Mat PSF5 = OPD_E0_XY.getPSF();
	OPD_E0_XY.exportCV_MatToExcel(OPD_E0_XY.getPSF(), "D:\PSF_XY.csv");

	// check the image simulation
	ImageSimulation ImgSimE0(PSF2,PSF3,PSF5,cardinalPointsE0.getMagnification(), rms);
	cv::Mat simulatedImg = ImgSimE0.getSimulatedImage();
	//Images::showImage("simulated image TOM", simulatedImg);
	//Images::saveImage("../images/", "testSimulatedImagesTOM.png", simulatedImg);

	//**********************************************************************************************
	//// check optical path with marginal ray Py=1
	//SequentialRayTracing SeqTrac1(OptSys1);
	//SeqTrac1.sequentialRayTracing(LightRayMargPy1);
	//real distance0 = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(0).at(0).getIntersecInfos().getStepsToWalk();
	//real comDis0 = 40.1849771;
	//bool checkDis0 = Math::compareTwoNumbers(distance0, comDis0, 7);
	//real distance1 = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(1).at(0).getIntersecInfos().getStepsToWalk();
	//real comDis1 = 7.00981474;
	//bool checkDis1 = Math::compareTwoNumbers(distance1, comDis1, 7);
	//real distance2 = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(2).at(0).getIntersecInfos().getStepsToWalk();
	//real comDis2 = 17.38814711;
	//bool checkDis2 = Math::compareTwoNumbers(distance2, comDis2, 7);
	//real distance3 = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(0).getIntersecInfos().getStepsToWalk();
	//real comDis3 = 12.243998755;
	//bool checkDis3 = Math::compareTwoNumbers(distance3, comDis3, 7);
	//
	//real sumOPDPy1 = distance0 + distance1 + distance2 + distance3;
	//real OPDPy1sys = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(0).getTotalSteps();
	//bool checkImgSimPy = Math::compareTwoNumbers(sumOPDPy1, OPDPy1sys,7);
	//checkImgSim.push_back(checkImgSimPy);
	//**********************************************************************************************




	//// check optical path with ray on optical axis
	//SeqTrac1.clearAllTracedRays();
	//SeqTrac1.sequentialRayTracing(LightRayOptAx);
	//real distance0OA = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(0).at(0).getIntersecInfos().getStepsToWalk();
	//real comDis0OA = 40;
	//bool checkDis0OA = Math::compareTwoNumbers(distance0OA, comDis0OA, 7);
	//real distance1OA = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(1).at(0).getIntersecInfos().getStepsToWalk();
	//real comDis1OA = 7.5;
	//bool checkDis1OA = Math::compareTwoNumbers(distance1OA, comDis1OA, 6);
	//real distance2OA = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(2).at(0).getIntersecInfos().getStepsToWalk();
	//real comDis2OA = 17.07317073;
	//bool checkDis2OA = Math::compareTwoNumbers(distance2OA, comDis2OA, 7);
	//real distance3OA = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(0).getIntersecInfos().getStepsToWalk();
	//real comDis3OA = 12.157598499;
	//bool checkDis3OA = Math::compareTwoNumbers(distance3OA, comDis3OA, 7);
	//
	//real sumOPDoptAx = distance0OA + distance1OA + distance2OA + distance3OA;
	//real OPDoptAxSys = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(0).getTotalSteps();
	//bool checkImgSimoptAx = Math::compareTwoNumbers(sumOPDoptAx, OPDoptAxSys, 7);
	//checkImgSim.push_back(checkImgSimoptAx);


	//SeqTrac1.clearAllTracedRays();
	//SeqTrac1.sequentialRayTracing(LightRayPyHalf);
	//real sumOPD_Py_Half = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(0).getTotalSteps();
	////**********************************************************************************************
	//real OPDPy1 = (sumOPDoptAx - sumOPDPy1) * 1000; //µm
	////**********************************************************************************************
	//bool checkImgSimPy1 = Math::compareTwoNumbers(OPDPy1, -96.1683399876, 3);
	////**********************************************************************************************
	//real OPDYHalf = (sumOPDoptAx - sumOPD_Py_Half) * 1000; //µm
	// //**********************************************************************************************
	//bool checkImgSimYHalf = Math::compareTwoNumbers(OPDYHalf, -20.71933545669, 4);
	////**********************************************************************************************
	//std::vector<LightRayStruct> lightRayAlong_YE1 = SequentialRayTracing::lightRayAlongY({ 0.0,0.0,0.0 }, 21, 20, -1, +1, 550, 1.0);
	//SeqTrac1.clearAllTracedRays();
	//SeqTrac1.seqRayTracingWithVectorOfLightRays(lightRayAlong_YE1);
	//double referenceLenght = SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(10).getTotalSteps();
	//double OPDPX_1 = (referenceLenght - SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(11).getTotalSteps()) * 1000;
	//double OPDPX_2 = (referenceLenght - SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(12).getTotalSteps()) * 1000;
	//double OPDPX_3 = (referenceLenght - SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(13).getTotalSteps()) * 1000;
	//double OPDPX_4 = (referenceLenght - SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(14).getTotalSteps()) * 1000;
	//double OPDPX_5 = (referenceLenght - SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(15).getTotalSteps()) * 1000;
	//double OPDPX_6 = (referenceLenght - SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(16).getTotalSteps()) * 1000;
	//double OPDPX_7 = (referenceLenght - SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(17).getTotalSteps()) * 1000;
	//double OPDPX_8 = (referenceLenght - SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(18).getTotalSteps()) * 1000;
	//double OPDPX_9 = (referenceLenght - SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(19).getTotalSteps()) * 1000;
	//double OPDPX_10 = (referenceLenght - SeqTrac1.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(20).getTotalSteps()) * 1000;
	//
	//std::vector<double> allOPD = { OPDPX_1 , OPDPX_2 ,OPDPX_3 , OPDPX_4 ,OPDPX_5, OPDPX_6 , OPDPX_7, OPDPX_8 , OPDPX_9 , OPDPX_10 };
	//std::vector<double> refAllOPD = { -0.790038, -3.1791536, -7.22486, -13.024775, -20.719335, -30.495816, -42.5938366, -57.3126788, -75.02083805, -96.168399 };
	////**********************************************************************************************
	//bool checkImgSimE1 = Math::compareTwoSTDVecors(allOPD, refAllOPD, 3);
	////**********************************************************************************************
	//checkImgSim.push_back(checkImgSimE1);
	////**********************************************************************************************
	////**********************************************************************************************
	//
	//
	//// check how Zemax calculate the OPD
	//// exit pupil is global coordinate reference
	//// Py = 1 at the exit pupil: y = 0.83106246530, z = 0
	//// direction ray = (0.0,0.58363971658,1.8380709316) - (0.0, 0.83106246530, 0.0) = (0.0, -0.247422749, 1.8380709316)
	//Ray_LLT RayPy1E2(/*origin*/{ 0.0, 0.83106246530, 0.0 }, /*direction*/{ 0.0, -0.247422749, 1.8380709316 }, 1.0);
	//
	//LightRayStruct LightRayE2Py1= { Light, RayPy1E2, 1 };
	//
	//SphericalSurface_LLT S0E2(/*radius*/5.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 13}, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	//SphericalSurface_LLT S1E2(/*radius*/5.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 18 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	//SphericalSurface_LLT S2E2(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 21 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	//SphericalSurface_LLT S3E2(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 26 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	//PlanGeometry_LLT ImageE2(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,31.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	//
	//// build the optical system
	//// exit pupil it at position of Plan_Ex2_2
	//OpticalSystem_LLT OptSysE2;
	//OptSysE2.fillVectorSurfaceAndInteractingData(0, &ApertureStop0E0, doNothing.clone());
	//OptSysE2.fillVectorSurfaceAndInteractingData(1, &S0E2, refrac.clone());
	//OptSysE2.fillVectorSurfaceAndInteractingData(2, &S1E2, refrac.clone());
	//OptSysE2.fillVectorSurfaceAndInteractingData(3, &S2E2, refrac.clone());
	//OptSysE2.fillVectorSurfaceAndInteractingData(4, &S3E2, refrac.clone());
	//OptSysE2.fillVectorSurfaceAndInteractingData(5, &ImageE2, absorb.clone());
	//
	////**********************************************************************************************
	//
	//// calculate OPD with start point on optical axis
	//std::vector<LightRayStruct> lightRayAlong_X_optA1 = SequentialRayTracing::lightRayAlongX({ 0.0, 0.0, 0.0 }, 5, 12.0, -1.0, 1.0, 550, 1.0);
	//std::vector<LightRayStruct> lightRayAlong_Y_optA1 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 5, 12.0, -1.0, 1.0, 550, 1.0);
	//Ray_LLT chiefRayoptA1({ 0.0,0.0,0.0 }, { 0.0,0.0,1.0 }, 1.0);
	//LightRayStruct chiefLightRayOptA1(Light, chiefRayoptA1, 1);
	//PlanGeometry_LLT exitPupil1(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,19.144876330 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
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
	////**********************************************************************************************
	//checkImgSim.push_back(checkOPD_XoptA1);
	//checkImgSim.push_back(checkOPD_YoptA1);
	////**********************************************************************************************
	//
	//// calculate OPD with start point in the field {0.0,1.0,0.0}
	//
	//std::vector<LightRayStruct> lightRayAlong_X_F1_1 = SequentialRayTracing::lightRayAlongX({ 0.0, 1.0, 0.0 }, 5, 12.0, -1.0, 1.0, 550, 1.0);
	//std::vector<LightRayStruct> lightRayAlong_Y_F1_1 = SequentialRayTracing::lightRayAlongY({ 0.0, 1.0, 0.0 }, 5, 12.0, -1.0, 1.0, 550, 1.0);
	//Ray_LLT chiefRayF1_1({ 0.0,1.0,0.0 }, { 0.0,-1.0,12.0 }, 1.0);
	//LightRayStruct chiefLightRayF1_1(Light, chiefRayF1_1, 1);
	//OPD OPDF1_1(exitPupil1, OptSysE2, lightRayAlong_X_F1_1, lightRayAlong_Y_F1_1, chiefLightRayF1_1);
	//
	////std::vector<cv::Point2d> OPD_X_F1 = OPDF1_1.getPointsOPD_X();
	////std::vector<cv::Point2d> OPD_Y_F1 = OPDF1_1.getPointsOPD_Y();
	//
	//std::vector<real> refOPDF1_X{ 11.095197787414, 1.5657364218168, 0.0, 1.5657364218168 , 11.095197787414};
	//std::vector<real> refOPDF1_Y{ 16.831192337267, 2.5979333278438, 0.0, 1.6389782904700, 8.3923622095689};
	//
	//std::vector<real> sysOPD_XF1 = OPDF1_1.getOPD_X_inVec();
	//std::vector<real> sysOPD_YF1 = OPDF1_1.getOPD_Y_inVec();
	//
	//bool checkOPD_XF1 = Math::compareTwoSTDVecors(sysOPD_XF1, refOPDF1_X, 1);
	//bool checkOPD_YF1 = Math::compareTwoSTDVecors(sysOPD_YF1, refOPDF1_Y, 1);
	//
	////**********************************************************************************************
	//checkImgSim.push_back(checkOPD_XF1);
	//checkImgSim.push_back(checkOPD_YF1);
	////**********************************************************************************************
	//
	//// surfaces of the optical system
	//SphericalSurface_LLT S0E3(/*radius*/15.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 40.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	//SphericalSurface_LLT S1E3(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 45.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	//PlanGeometry_LLT PlanE3(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	//
	//OpticalSystem_LLT optSysE3;
	//optSysE3.fillVectorSurfaceAndInteractingData(0, &ApertureStop0E0, doNothing.clone());
	//optSysE3.fillVectorSurfaceAndInteractingData(1, &S0E3, refrac.clone());
	//optSysE3.fillVectorSurfaceAndInteractingData(2, &S1E3, refrac.clone());
	//optSysE3.fillVectorSurfaceAndInteractingData(3, &PlanE3, doNothing.clone());
	//
	//PlanGeometry_LLT exitPupilE3(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,74.230762215072 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	//
	//
	//// OPD on optical axis
	//std::vector<LightRayStruct> lightRayAlong_X_optA_E3 = SequentialRayTracing::lightRayAlongX({ 0.0, 0.0, 0.0 }, 5, 20.0, -1.0, 1.0, 550, 1.0);
	//std::vector<LightRayStruct> lightRayAlong_Y_optA_E3 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 5, 20.0, -1.0, 1.0, 550, 1.0);
	//
	//Ray_LLT chiefRayOptA_E3({ 0.0,0.0,0.0 }, { 0.0,0.0,1.0 }, 1.0);
	//LightRayStruct chiefLightRayOptA_E3(Light, chiefRayOptA_E3, 1);
	//
	//OPD OPD3OptA(exitPupilE3, optSysE3, lightRayAlong_X_optA_E3, lightRayAlong_Y_optA_E3, chiefLightRayOptA_E3);
	//
	//std::vector<real> refVecOPD2OptA{ -19.35254296825, -5.174155019256, 0.0, -5.174155019256, -19.35254296825 };
	//
	//std::vector<real> refSysOPD3OptA_X = OPD3OptA.getOPD_X_inVec();
	//std::vector<real> refSysOPD3OptA_Y = OPD3OptA.getOPD_Y_inVec();
	//
	//bool checkOPD3_OpdA_X = Math::compareTwoSTDVecors(refSysOPD3OptA_X, refVecOPD2OptA, 3);
	//bool checkOPD3_OpdA_Y = Math::compareTwoSTDVecors(refSysOPD3OptA_Y, refVecOPD2OptA, 3);
	//
	//checkImgSim.push_back(checkOPD3_OpdA_X);
	//checkImgSim.push_back(checkOPD3_OpdA_Y);
	//
	//// *****************************************************************************************************************
	//
	//// OPD on optical in field x=1
	//std::vector<LightRayStruct> lightRayAlong_X_F1_E3 = SequentialRayTracing::lightRayAlongX({ -0.5, 0.0, 0.0 }, 5, 20.0, -1.0, 1.0, 550, 1.0);
	//std::vector<LightRayStruct> lightRayAlong_Y_F1_E3 = SequentialRayTracing::lightRayAlongY({ -0.5, 0.0, 0.0 }, 5, 20.0, -1.0, 1.0, 550, 1.0);
	//
	//Ray_LLT chiefRayF05_E3({ -0.5,0.0,0.0 }, { 0.5,0.0,20.0 }, 1.0);
	//LightRayStruct chiefLightRayF1_E3(Light, chiefRayF05_E3, 1);
	//
	//OPD OPD3F1(exitPupilE3, optSysE3, lightRayAlong_X_F1_E3, lightRayAlong_Y_F1_E3, chiefLightRayF1_E3);
	//
	//std::vector<real> refSysOPD3F05_X = OPD3F1.getOPD_X_inVec();
	//std::vector<real> refSysOPD3F05_Y = OPD3F1.getOPD_Y_inVec();
	//
	//std::vector<real> refVecOPD3_F05_X{-20.77287044221, -5.128251783727, 0.0, -4.549571108316, -13.46850743476 };
	//std::vector<real> refVecOPD3_F05_Y{ -18.76999535012, -5.069924289691, 0.0, -5.069924289691, -18.76999535012 };
	//
	//bool checkOPD3_F05_X = Math::compareTwoSTDVecors(refSysOPD3F05_X, refVecOPD3_F05_X, 3);
	//bool checkOPD3_F05_Y = Math::compareTwoSTDVecors(refSysOPD3F05_Y, refVecOPD3_F05_Y, 3);
	//
	//checkImgSim.push_back(checkOPD3_F05_X);
	//checkImgSim.push_back(checkOPD3_F05_Y);
	//
	//// *****************************************************************************************************************
	//// *****************************************************************************************************************
	//// *****************************************************************************************************************
	//// calculate global OPD
	//// we build that optical system before
	//// OPD on optical axis
	//FillApertureStop fillAperStopE4_optAchse({ 0.0,0.0,0.0 }, 1, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, 6, 8, 1.0, Light);
	//OPD OPD4globalOPD_optAchse(/*exit pupil*/ exitPupilE3,  /*optical system*/ optSysE3,
	//	/*fill apertur stop with light ray*/ fillAperStopE4_optAchse.getVectorWithLightRays(), /*chief ray*/ fillAperStopE4_optAchse.getVectorWithLightRays().at(0), /*scalling*/ 0);
	//// OPD in field
	//FillApertureStop fillAperStopE4_field({ 0.0,0.5,0.0 }, 1, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, 3, 4, 1.0, Light);
	//OPD OPD4globalOPD_field(/*exit pupil*/ exitPupilE3,  /*optical system*/ optSysE3,
	//	/*fill apertur stop with light ray*/ fillAperStopE4_field.getVectorWithLightRays(), /*chief ray*/ fillAperStopE4_field.getVectorWithLightRays().at(0), /*scalling*/ 0);
	////cv::Mat globalOPD4 = OPD4globalOPD.getGlobalOPD();
	////std::cout << globalOPD4 << std::endl;
	//// *****************************************************************************************************************
	//// *****************************************************************************************************************
	//FillApertureStop fillAperStopE5({ 0.0,0.0,0.0 }, 1, { 0.0,0.0,12.0 }, { 0.0,0.0,1.0 }, 3, 4, 1.0, Light);
	//OPD OPDglobalOPD(/*exit pupil*/ exitPupil1,  /*optical system*/ OptSysE2,
	//	/*fill apertur stop with light ray*/ fillAperStopE5.getVectorWithLightRays(), /*chief ray*/ fillAperStopE5.getVectorWithLightRays().at(0), /*scalling*/ 0);
	//// *****************************************************************************************************************
	//// *****************************************************************************************************************
	//// *****************************************************************************************************************
	//bool output = Math::checkTrueOfVectorElements(checkImgSim);
	//// *****************************************************************************************************************
	//// *****************************************************************************************************************
	//// *****************************************************************************************************************

	return true;
}