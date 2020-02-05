#include "DoubleGauss5DegreeField.h"
// Surfaces
#include "..\..\..\SurfaceElements\SphericalElement.h"
#include "..\..\..\SurfaceElements\PlanElement.h"
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"
// Interaction
#include "..\..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"
// optical system and raytracing
#include "..\..\..\FillAptertureStop\FillApertureStop.h"
#include "..\..\..\LowLevelTracing\Light_LLT.h"
#include "..\..\..\OptimizeSystem\OptimizeOpticalSystem.h"
// Analyse
#include "..\..\..\Analyse\Spot.h"
// glass catalogue
#include "..\..\..\Glasses\Glasses.h"

DoubleGauss5DegreeField::DoubleGauss5DegreeField() {};
DoubleGauss5DegreeField::~DoubleGauss5DegreeField() {};

bool DoubleGauss5DegreeField::buildDoubleGauss5DegreeField()
{
//	std::vector<bool> checkDoubleGauss5DegreeField;
//
//	// interacetions
//	RefractedRay_LLT refrac;
//	Absorb_LLT absorb;
//
//	// import glasses
//	glass glasses;
//	real wavelength = 550;
//	glasses.loadGlassCatalog_Schott();
//	real refIndex_LAF2 = glasses.getLAF2_S1().calcRefractiveIndexSnellmeier1(wavelength);
//	real refIndex_PSK3 = glasses.getPSK3_S1().calcRefractiveIndexSnellmeier1(wavelength);
//	real refIndex_SF1 = glasses.getSF1_S1().calcRefractiveIndexSnellmeier1(wavelength);
//
//
//	// surfaces
//	//---
//	// hier muss noch die Aperturblende eingefügt werden!
//	SphericalElement S0(/*radius*/3.552, /*semi height*/2.215, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/1.0,/*refractive index B*/ refIndex_LAF2);
//	PlanElement S1(/*semiHeight*/ 2.215, /*Apex*/{ 0.0,0.0,1.39909 }, /*Direction*/{ 0.0,0.0,1.0 }, /*refIndexSideA*/  refIndex_LAF2, /*refIndexSideB*/ 1.0);
//	SphericalElement S2(/*radius*/1.704, /*semi height*/1.470, /*point*/{ 0.0,0.0,1.40786 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/1.0,/*refractive index B*/ refIndex_PSK3);
//	SphericalElement S3(/*radius*/-16.238, /*semi height*/1.470, /*point*/{ 0.0,0.0,2.346384 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/refIndex_PSK3,/*refractive index B*/ refIndex_SF1);
//	SphericalElement S4(/*radius*/0.986, /*semi height*/0.810, /*point*/{ 0.0,0.0,2.598577 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/refIndex_SF1,/*refractive index B*/ 1.0);
//	//ApertureStop_LLT A5{/*semiHeight*/ 0.8, /*Apex*/{ 0.0,0.0,3.032206 },/*direction*/ { 0.0,0.0,1.0 }, /*refIndex*/ 1.0 };
//	SphericalElement S6(/*radius*/1.642, /*semi height*/0.810, /*point*/{ 0.0,0.0,3.30987 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/1.0,/*refractive index B*/ refIndex_SF1);
//	SphericalElement S7(/*radius*/1.803, /*semi height*/1.025, /*point*/{ 0.0,0.0,3.580042 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/refIndex_SF1,/*refractive index B*/ refIndex_LAF2);
//	SphericalElement S8(/*radius*/2.334, /*semi height*/1.025, /*point*/{ 0.0,0.0,4.738626 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/refIndex_LAF2,/*refractive index B*/ 1.0);
//	SphericalElement S9(/*radius*/1.659, /*semi height*/0.930, /*point*/{ 0.0,0.0,5.185872 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/1.0,/*refractive index B*/ refIndex_LAF2);
//	SphericalElement S10(/*radius*/14.411, /*semi height*/0.930, /*point*/{ 0.0,0.0,6.229631 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/refIndex_LAF2,/*refractive index B*/ 1.0);
//	PlanElement S11(/*semiHeight*/19.0, /*point*/{ 0.0,0.0,60.1767461670 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/1.0,/*refractive index B*/ 1.0);
//	//---
//
//	// build optical system
//	//---
//	OpticalSystemElement doubleGauss5DegreeField;
//	doubleGauss5DegreeField.fillPosAndElementAndInteraction(0, &S0, refrac.clone());
//	doubleGauss5DegreeField.fillPosAndElementAndInteraction(1, &S1, refrac.clone());
//	doubleGauss5DegreeField.fillPosAndElementAndInteraction(2, &S2, refrac.clone());
//	doubleGauss5DegreeField.fillPosAndElementAndInteraction(3, &S3, refrac.clone());
//	doubleGauss5DegreeField.fillPosAndElementAndInteraction(4, &S4, refrac.clone());
//	//doubleGauss5DegreeField.fillVectorSurfaceAndInteractingData(5, &A5, doNothing.clone());
//	doubleGauss5DegreeField.fillPosAndElementAndInteraction(6, &S6, refrac.clone());
//	doubleGauss5DegreeField.fillPosAndElementAndInteraction(7, &S7, refrac.clone());
//	doubleGauss5DegreeField.fillPosAndElementAndInteraction(8, &S8, refrac.clone());
//	doubleGauss5DegreeField.fillPosAndElementAndInteraction(9, &S9, refrac.clone());
//	doubleGauss5DegreeField.fillPosAndElementAndInteraction(10, &S10, refrac.clone());
//	doubleGauss5DegreeField.fillPosAndElementAndInteraction(11, &S11, absorb.clone());
//	doubleGauss5DegreeField.convertHLTtoLLT();
//
//	// build LLT system in LLT
//	OpticalSystem_LLT doubleGauss5DegreeField_LLT(doubleGauss5DegreeField.getPosAndIntersection_LLT(), doubleGauss5DegreeField.getPosAndInteraction_LLT());
//	//---
//
//	// single ray tracing (just for debugging)
//	//---
//	Ray_LLT rayE1_0({ 0.0,1.0,0.0 }, { 0.0,0.0,1.0 }, 1.0);
//	Light_LLT light;
//	light.setWavelength(550.0);
//	LightRayStruct lightRayE0_0(light, rayE1_0, 1);
//	SequentialRayTracing seqTraceE1_single(doubleGauss5DegreeField_LLT);
//	seqTraceE1_single.sequentialRayTracing(lightRayE0_0);
//	IntersectInformationStruct interInfosS0 = seqTraceE1_single.getAllInterInfosOfSurf_i(0).at(0);
//	IntersectInformationStruct interInfosS1 = seqTraceE1_single.getAllInterInfosOfSurf_i(1).at(0);
//	IntersectInformationStruct interInfosS2 = seqTraceE1_single.getAllInterInfosOfSurf_i(2).at(0);
//	IntersectInformationStruct interInfosS3 = seqTraceE1_single.getAllInterInfosOfSurf_i(3).at(0);
//	IntersectInformationStruct interInfosS4 = seqTraceE1_single.getAllInterInfosOfSurf_i(4).at(0);
//	IntersectInformationStruct interInfosS5 = seqTraceE1_single.getAllInterInfosOfSurf_i(5).at(0);
//	IntersectInformationStruct interInfosS6 = seqTraceE1_single.getAllInterInfosOfSurf_i(6).at(0);
//	IntersectInformationStruct interInfosS7 = seqTraceE1_single.getAllInterInfosOfSurf_i(7).at(0);
//	IntersectInformationStruct interInfosS8 = seqTraceE1_single.getAllInterInfosOfSurf_i(8).at(0);
//	IntersectInformationStruct interInfosS9 = seqTraceE1_single.getAllInterInfosOfSurf_i(9).at(0);
//	IntersectInformationStruct interInfosS10 = seqTraceE1_single.getAllInterInfosOfSurf_i(10).at(0);
//	IntersectInformationStruct interInfosS11 = seqTraceE1_single.getAllInterInfosOfSurf_i(11).at(0);
//	//---
//
//	// build and trace the lightray field 0
//	//---
//	FillApertureStop FillOptSys_optAxis(0, 0, /*semi height*/ 2.0, /*apex*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*rings*/ 6, /*arms*/8, /*refractive index*/ 1.0, light);
//	SequentialRayTracing seqTraceE0_optA(doubleGauss5DegreeField_LLT);
//	seqTraceE0_optA.seqRayTracingWithVectorOfLightRays(FillOptSys_optAxis.getVectorWithLightRays());
//	//---
//	// calculate rms value of the spot on optical axis
//	Spot spotDiagramDoubleGauss5_optAxis(seqTraceE0_optA.getAllInterPointsAtSurf_i(6), seqTraceE0_optA.getAllInterPointsAtSurf_i(6).at(0));
//	real rmsValueE0_optA = spotDiagramDoubleGauss5_optAxis.getRMS_mm();
//	bool checkRMS_optA = Math::compareTwoNumbers(rmsValueE0_optA, 0.004295, 3);
//	checkDoubleGauss5DegreeField.push_back(checkRMS_optA);
//	//---
//
//		// build and trace the lightray field Y14°
//	//---
//	FillApertureStop FillOptSys_Y14(0, 14, /*semi height*/ 2.0, /*apex*/{ 0.0,-2.8703031261, 0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*rings*/ 6, /*arms*/8, /*refractive index*/ 1.0, /*wavelength*/ 550);
//	SequentialRayTracing seqTraceE0_Y14(doubleGauss5DegreeField_LLT);
//	seqTraceE0_Y14.seqRayTracingWithVectorOfLightRays(FillOptSys_Y14.getVectorWithLightRays());
//	// calculate rms value of the spot for field Y14°
//	Spot spotDiagramCook40_Y14(seqTraceE0_Y14.getAllInterPointsAtSurf_i(6), seqTraceE0_Y14.getAllInterPointsAtSurf_i(6).at(0));
//	real rmsValueE0_Y14 = spotDiagramCook40_Y14.getRMS();
//	bool checkRMS_Y14 = Math::compareTwoNumbers(rmsValueE0_Y14, 0.016922, 3);
//	//---
//
//	// build and trace the lightray field Y20°
//	//---
//	FillApertureStop FillOptSys_Y20(0, 20, /*semi height*/ 5.0, /*apex*/{ 0.0,-4.1900824990, 0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*rings*/ 6, /*arms*/8, /*refractive index*/ 1.0, /*wavelength*/ 550);
//	SequentialRayTracing seqTraceE0_Y20(Cooke40DegreeField_LLT);
//	seqTraceE0_Y20.seqRayTracingWithVectorOfLightRays(FillOptSys_Y20.getVectorWithLightRays());
//	std::vector<VectorStructR3> allInterPointsOfSurface_S0 = seqTraceE0_Y20.getAllInterPointsAtSurf_i(0);
//	// calculate rms value of the spot for field Y20°
//	Spot spotDiagramCook40_Y20(seqTraceE0_Y20.getAllInterPointsAtSurf_i(6), seqTraceE0_Y20.getAllInterPointsAtSurf_i(6).at(0));
//	real rmsValueE0_Y20 = spotDiagramCook40_Y20.getRMS();
//	bool checkRMS_Y20 = Math::compareTwoNumbers(rmsValueE0_Y20, 0.012110, 3);
//	//---



	return true;
}

