#include "Cooke40DegreeField.h"

// Surfaces
#include "..\..\..\SurfaceElements\SphericalElement.h"
#include "..\..\..\SurfaceElements\PlanElement.h"

// Interaction
#include "..\..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\..\LowLevelTracing\Interaction\Absorb_LLT.h"

// optical system and raytracing
#include "..\..\..\FillAptertureStop\FillApertureStop.h"
#include "..\..\..\LowLevelTracing\Light_LLT.h"
#include "..\..\..\OptimizeSystem\OptimizeOpticalSystem.h"

// Analyse
#include "..\..\..\Analyse\Spot.h"

// glass catalogue
#include "..\..\..\Glasses\Glasses.h"


bool Cooke40DegreeField::buildCooke40DegreeField()
{
//S	std::vector<bool> checkCooke40DegreeField;
//S
//S	// interacetions
//S	RefractedRay_LLT refrac;
//S	Absorb_LLT absorb;
//S
//S	// import glasses
//S	glass glasses;
//S	real wavelenght = 550;
//S	glasses.loadGlassCatalog_Schott();
//S	real refIndex_N_SK16 = glasses.getNSK16_S1().calcRefractiveIndexSnellmeier1(wavelenght);
//S	real refIndex_SK16 = glasses.getSK16_S1().calcRefractiveIndexSnellmeier1(wavelenght);
//S	real refIndex_F2 = glasses.get_F2_S1().calcRefractiveIndexSnellmeier1(wavelenght);
//S	
//S	
//S	// surfaces
//S	//---
//S	// hier muss noch die Aperturblende eingefügt werden!
//S	SphericalElement S0(/*radius*/22.01359250842754, /*semi height*/9.5, /*point*/{ 0.0,0.0,0.0}, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/1.0,/*refractive index B*/ refIndex_N_SK16);
//S	SphericalElement S1(/*radius*/435.76043616830793, /*semi height*/9.5, /*point*/{ 0.0,0.0,3.2589558300}, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/1.0,/*refractive index B*/ refIndex_N_SK16);
//S	SphericalElement S2(/*radius*/22.21327718231509, /*semi height*/5.0, /*point*/{ 0.0,0.0,9.2665069300}, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/refIndex_F2,/*refractive index B*/ 1.0);
//S	SphericalElement S3(/*radius*/20.29192412527334, /*semi height*/5.0, /*point*/{ 0.0,0.0,10.2664814970}, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/refIndex_F2,/*refractive index B*/ 1.0);
//S	// hier muss noch die Aperturblende eingefügt werden!
//S	SphericalElement S4(/*radius*/79.68360255049363, /*semi height*/7.5, /*point*/{ 0.0,0.0,15.0168904270}, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/1.0,/*refractive index B*/ refIndex_SK16);
//S	SphericalElement S5(/*radius*/18.39533260304032, /*semi height*/7.5, /*point*/{ 0.0,0.0,17.9689660670}, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/1.0,/*refractive index B*/ refIndex_SK16);
//S	PlanElement S6(/*semiHeight*/19.0, /*point*/{ 0.0,0.0,60.1767461670}, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/1.0,/*refractive index B*/ 1.0);
//S	//---
//S
//S	// build optical system
//S	//---
//S	OpticalSystemElement Cooke40DegreeField;
//S	Cooke40DegreeField.fillPosAndElementAndInteraction(0, &S0, refrac.clone());
//S	Cooke40DegreeField.fillPosAndElementAndInteraction(1, &S1, refrac.clone());
//S	Cooke40DegreeField.fillPosAndElementAndInteraction(2, &S2, refrac.clone());
//S	Cooke40DegreeField.fillPosAndElementAndInteraction(3, &S3, refrac.clone());
//S	// hier muss noch die Aperturblende eingefügt werden!
//S	Cooke40DegreeField.fillPosAndElementAndInteraction(4, &S4, refrac.clone());
//S	Cooke40DegreeField.fillPosAndElementAndInteraction(5, &S5, refrac.clone());
//S	Cooke40DegreeField.fillPosAndElementAndInteraction(6, &S6, absorb.clone());
//S	Cooke40DegreeField.convertHLTtoLLT();
//S	
//S	// build LLT system in LLT
//S	OpticalSystem_LLT Cooke40DegreeField_LLT(Cooke40DegreeField.getPosAndIntersection_LLT(), Cooke40DegreeField.getPosAndInteraction_LLT());
//S	//---
//S
//S	// single ray tracing (just for debugging)
//S	//---
//S	Ray_LLT rayE1_0({ 0.0,5.0,0.0 }, { 0.0,0.0,1.0 }, 1.0);
//S	Light_LLT light;
//S	light.setWavelength(550.0);
//S	LightRayStruct lightRayE0_0(light, rayE1_0, 1);
//S	SequentialRayTracing seqTraceE1_single(Cooke40DegreeField_LLT);
//S	seqTraceE1_single.sequentialRayTracing(lightRayE0_0);
//S	IntersectInformationStruct interInfosS0 = seqTraceE1_single.getAllInterInfosOfSurf_i(0).at(0);
//S	IntersectInformationStruct interInfosS1 = seqTraceE1_single.getAllInterInfosOfSurf_i(1).at(0);
//S	IntersectInformationStruct interInfosS2 = seqTraceE1_single.getAllInterInfosOfSurf_i(2).at(0);
//S	IntersectInformationStruct interInfosS3 = seqTraceE1_single.getAllInterInfosOfSurf_i(3).at(0);
//S	IntersectInformationStruct interInfosS4 = seqTraceE1_single.getAllInterInfosOfSurf_i(4).at(0);
//S	IntersectInformationStruct interInfosS5 = seqTraceE1_single.getAllInterInfosOfSurf_i(5).at(0);
//S	IntersectInformationStruct interInfosS6 = seqTraceE1_single.getAllInterInfosOfSurf_i(6).at(0);
//S	//---
//S	
//S	// build and trace the lightray field 0
//S	//---
//S	FillApertureStop FillOptSys_optAxis(0,0, /*semi height*/ 5.0, /*apex*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*rings*/ 6, /*arms*/8 , /*refractive index*/ 1.0, light);
//S	SequentialRayTracing seqTraceE0_optA(Cooke40DegreeField_LLT);
//S	seqTraceE0_optA.seqRayTracingWithVectorOfLightRays(FillOptSys_optAxis.getVectorWithLightRays());
//S	//---
//S	// calculate rms value of the spot on optical axis
//S	Spot spotDiagramCook40_optAxis(seqTraceE0_optA.getAllInterPointsAtSurf_i(6), seqTraceE0_optA.getAllInterPointsAtSurf_i(6).at(0));
//S	real rmsValueE0_optA = spotDiagramCook40_optAxis.getRMS_mm();
//S	bool checkRMS_optA = Math::compareTwoNumbers(rmsValueE0_optA, 0.004295, 3);
//S	checkCooke40DegreeField.push_back(checkRMS_optA);
//S	//---
//S
//S		// build and trace the lightray field Y14°
//S	//---
//S	FillApertureStop FillOptSys_Y14(0, 14, /*semi height*/ 5.0, /*apex*/{ 0.0,-2.8703031261, 0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*rings*/ 6, /*arms*/8, /*refractive index*/ 1.0, light);
//S	SequentialRayTracing seqTraceE0_Y14(Cooke40DegreeField_LLT);
//S	seqTraceE0_Y14.seqRayTracingWithVectorOfLightRays(FillOptSys_Y14.getVectorWithLightRays());
//S	// calculate rms value of the spot for field Y14°
//S	Spot spotDiagramCook40_Y14(seqTraceE0_Y14.getAllInterPointsAtSurf_i(6), seqTraceE0_Y14.getAllInterPointsAtSurf_i(6).at(0));
//S	real rmsValueE0_Y14 = spotDiagramCook40_Y14.getRMS_mm();
//S	bool checkRMS_Y14 = Math::compareTwoNumbers(rmsValueE0_Y14, 0.016922, 3);
//S	//---
//S
//S	// build and trace the lightray field Y20°
//S	//---
//S	FillApertureStop FillOptSys_Y20(0, 20, /*semi height*/ 5.0, /*apex*/{ 0.0,-4.1900824990, 0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*rings*/ 6, /*arms*/8, /*refractive index*/ 1.0, light);
//S	SequentialRayTracing seqTraceE0_Y20(Cooke40DegreeField_LLT);
//S	seqTraceE0_Y20.seqRayTracingWithVectorOfLightRays(FillOptSys_Y20.getVectorWithLightRays());
//S	std::vector<VectorStructR3> allInterPointsOfSurface_S0 = seqTraceE0_Y20.getAllInterPointsAtSurf_i(0);
//S	// calculate rms value of the spot for field Y20°
//S	Spot spotDiagramCook40_Y20(seqTraceE0_Y20.getAllInterPointsAtSurf_i(6), seqTraceE0_Y20.getAllInterPointsAtSurf_i(6).at(0));
//S	real rmsValueE0_Y20 = spotDiagramCook40_Y20.getRMS_mm();
//S	bool checkRMS_Y20 = Math::compareTwoNumbers(rmsValueE0_Y20, 0.012110, 3);
//S	//---
//S
//S
//S
	return true;

}