#include "BenchmarkParaxialLens_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DeflectedRayParaxialLens_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\FillAptertureStop\FillApertureStop.h"
#include "..\..\Analyse\Spot.h"
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\Analyse\Spot.h"
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"

// check methodes of class ParaxialLens_LLT
bool  BenchmarkParaxialLens::checkMethodesParaxialLens_LLT()
{
	std::vector<bool> checkParaxialLens;
	Absorb_LLT absorb;
	Light_LLT Light;

	// *****************************************************************************************************************
	// *****************************************************************************************************************

	//example 1
	// *****************************************************************************************************************

	
	// fill entrance pupil with many rays
	FillApertureStop FillEntPupilRayE1(/*start point ray*/{ 0.0,0.0,0.0 }, /*semi height*/ 1.0, /*apex*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0,Light);
	

	ParaxialLens_LLT ParaxialLens_0(/*semi Height*/ 9.0, /*apex*/ { 0.0,0.0,10.0 }, /*direction*/ { 0.0,0.0,1.0 }, /*focallength*/ 10.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflectP0(ParaxialLens_0.getInfosForDefelction());
	ParaxialLens_LLT ParaxialLens_1(/*semi Height*/ 9.0, /*apex*/ { 0.0,0.0,15.0 }, /*direction*/ { 0.0,0.0,1.0 }, /*focallength*/ -100.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflectP1(ParaxialLens_1.getInfosForDefelction());
	ParaxialLens_LLT ParaxialLens_2(/*semi Height*/ 9.0, /*apex*/ {0.0,0.0,20.0 }, /*direction*/  { 0.0,0.0,1.0 }, /*focallength*/ 10.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflectP2(ParaxialLens_2.getInfosForDefelction());
	ParaxialLens_LLT ParaxialLens_3(/*semi Height*/ 9.0, /*apex*/ {0.0,0.0,30.0 }, /*direction*/ { 0.0,0.0,1.0 }, /*focallength*/ 10.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflectP3(ParaxialLens_3.getInfosForDefelction());
	PlanGeometry_LLT Plan4E1(/*semi Height*/ 9.0, /*apex*/ { 0.0,0.0,31.0 }, /*direction*/  { 0.0,0.0,1.0 }, 1.0, 1.0);

//	//________________

	
	OpticalSystem_LLT OptSysE1;
	OptSysE1.fillVectorSurfaceAndInteractingData(0, &ParaxialLens_0, deflectP0.clone());
	OptSysE1.fillVectorSurfaceAndInteractingData(1, &ParaxialLens_1, deflectP1.clone());
	OptSysE1.fillVectorSurfaceAndInteractingData(2, &ParaxialLens_2, deflectP2.clone());
	OptSysE1.fillVectorSurfaceAndInteractingData(3, &ParaxialLens_3, deflectP3.clone());
	OptSysE1.fillVectorSurfaceAndInteractingData(4, &Plan4E1, absorb.clone());

	// trace all the rays
	SequentialRayTracing seqTraceE1(OptSysE1);
	seqTraceE1.seqRayTracingWithVectorOfLightRays(FillEntPupilRayE1.getVectorWithLightRays());

	Spot SpotValue(seqTraceE1.getAllInterPointsAtSurf_i(4), seqTraceE1.getAllInterPointsAtSurf_i(4).at(0));

	double RMS_E1 = SpotValue.getRMS_mm();
	double GEO_E1 = SpotValue.getGeoRadius();

	bool checkRMSvalueE1 = Math::compareTwoNumbers_decimals(RMS_E1, 0.007607, 6);
	checkParaxialLens.push_back(checkRMSvalueE1);
	bool checkGeoRadiusE5 = Math::compareTwoNumbers_decimals(GEO_E1, 0.01, 2);
	checkParaxialLens.push_back(checkGeoRadiusE5);

	// *****************************************************************************************************************
	// *****************************************************************************************************************


	ParaxialLens_LLT ParaxialLens4(/*semi Height*/ 5.0, /*apex*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*focallength*/ 5.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflect4(ParaxialLens4.getInfosForDefelction());
	PlanGeometry_LLT Plan4(/*semi Height*/20.0, /*apex*/{ 0.0,0.0,20.5 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0, 1.0);

	OpticalSystem_LLT OptSys4;
	OptSys4.fillVectorSurfaceAndInteractingData(0, &ParaxialLens4, deflect4.clone());
	OptSys4.fillVectorSurfaceAndInteractingData(1, &Plan4, absorb.clone());

	// start on optical axis
	Ray_LLT Ray41(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,1.0,5.0 }, 1.0);
	Ray_LLT Ray42(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 },  1.0);
	Ray_LLT Ray43(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);

	// start on filed {0.0,2.0,0.0}
	Ray_LLT Ray44(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray45(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);
	Ray_LLT Ray46(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-2.0,5.0 }, 1.0);

	
	LightRayStruct LightRay41(Light, Ray41, 1);
	LightRayStruct LightRay42(Light, Ray42, 1);
	LightRayStruct LightRay43(Light, Ray43, 1);
	LightRayStruct LightRay44(Light, Ray44, 1);
	LightRayStruct LightRay45(Light, Ray45, 1);
	LightRayStruct LightRay46(Light, Ray46, 1);
	
	// fill tracing vector
	std::vector<LightRayStruct> vecLightRay1{ LightRay41, LightRay42, LightRay43, LightRay44, LightRay45, LightRay46 };

	// do sequential ray tracing
	SequentialRayTracing seqTrace4(OptSys4);
	seqTrace4.seqRayTracingWithVectorOfLightRays(vecLightRay1);

	// get all intersection points
	std::vector<VectorStructR3> allInterPoints = seqTrace4.getAllInterPointsAtSurf_i(1);

	// get the reference points from Zemax
	std::vector<VectorStructR3> refInterPoints = { {0.0,-0.1,20.5},{0.0,0.0,20.5},{0.0,0.1,20.5},{ 0.0,-1.1,20.5 },{ 0.0,-1.0,20.5 },{ 0.0,-0.9,20.5 } };

	// compare trace open with Zemax data
	bool chech1 = Math::compareAllVectorElements(allInterPoints, refInterPoints, 8);
	checkParaxialLens.push_back(chech1);
	// *****************************************************************************************************************
	// *****************************************************************************************************************
	ParaxialLens_LLT ParaxialLensTestCR1(/*semi Height*/ 7.5, /*apex*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*focallength*/ 5.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflectCR1(ParaxialLensTestCR1.getInfosForDefelction());
	PlanGeometry_LLT PlanCR1(/*semi Height*/5.0, /*apex*/{ 0.0,0.0,19.8 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0, 1.0);
	FillApertureStop FillApStopCR1(/*start point ray*/{ 0.0,0.0,0.0 }, /*semi height*/ 1.0, /*apex*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0,Light);
	FillApertureStop FillApStopFieldCR1(/*start point ray*/{ 0.0,1.0,0.0 }, /*semi height*/ 1.0, /*apex*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, Light);
	
	OpticalSystem_LLT OptSysCR1;
	OptSysCR1.fillVectorSurfaceAndInteractingData(0, &ParaxialLensTestCR1, deflectCR1.clone());
	OptSysCR1.fillVectorSurfaceAndInteractingData(1, &PlanCR1, absorb.clone());

	SequentialRayTracing SeqTraceCR1(OptSysCR1);
	SeqTraceCR1.seqRayTracingWithVectorOfLightRays(FillApStopCR1.getVectorWithLightRays());
	Spot SpotDiaCR1(SeqTraceCR1.getAllInterPointsAtSurf_i(1), SeqTraceCR1.getAllInterPointsAtSurf_i(1).at(0));
	real rmsCR1 = SpotDiaCR1.getRMS_mm();
	real RMSCR1_Z = 0.030430;
	bool checkRMS_CR1 = Math::compareTwoNumbers_decimals(rmsCR1, RMSCR1_Z, 5);
	checkParaxialLens.push_back(checkRMS_CR1);

	SequentialRayTracing SeqTraceFieldCR1(OptSysCR1);
	SeqTraceFieldCR1.seqRayTracingWithVectorOfLightRays(FillApStopFieldCR1.getVectorWithLightRays());
	Spot SpotDiaFiledCR1(SeqTraceFieldCR1.getAllInterPointsAtSurf_i(1), SeqTraceFieldCR1.getAllInterPointsAtSurf_i(1).at(0));
	real rmsFild_CR1 = SpotDiaFiledCR1.getRMS_mm();
	real RMS_Field_CR1_Z = 0.030430;
	bool checkFieldRMS_CR1 = Math::compareTwoNumbers_decimals(rmsFild_CR1, RMS_Field_CR1_Z, 5);
	checkParaxialLens.push_back(checkFieldRMS_CR1);

	// *****************************************************************************************************************
	// *****************************************************************************************************************
	
	ParaxialLens_LLT ParaxialLensTestCR2(/*semi Height*/ 7.5, /*apex*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*focallength*/ 5.0, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflectCR2(ParaxialLensTestCR2.getInfosForDefelction());
	PlanGeometry_LLT PlanCR2(/*semi Height*/5.0, /*apex*/{ 0.0,0.0,19.8 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0, 1.5);
	FillApertureStop FillApStopCR2(/*start point ray*/{ 0.0,0.0,0.0 }, /*semi height*/ 1.0, /*apex*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, Light);
	FillApertureStop FillApStopFieldCR2(/*start point ray*/{ 0.0,1.0,0.0 }, /*semi height*/ 1.0, /*apex*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, Light);

	OpticalSystem_LLT OptSysCR2;
	OptSysCR2.fillVectorSurfaceAndInteractingData(0, &ParaxialLensTestCR2, deflectCR2.clone());
	OptSysCR2.fillVectorSurfaceAndInteractingData(1, &PlanCR2, absorb.clone());

	// singel ray tracing!
	//***


	//***

	SequentialRayTracing SeqTraceCR2(OptSysCR2);
	SeqTraceCR2.seqRayTracingWithVectorOfLightRays(FillApStopCR2.getVectorWithLightRays());
	Spot SpotDiaCR2(SeqTraceCR2.getAllInterPointsAtSurf_i(1), SeqTraceCR2.getAllInterPointsAtSurf_i(1).at(0));
	real rmsCR2 = SpotDiaCR2.getRMS_mm();
	real RMS_ZemaxCR2 = 0.527453;
	bool checkRMS_CR2 = Math::compareTwoNumbers_decimals(rmsCR2, RMS_ZemaxCR2, 1);
	checkParaxialLens.push_back(checkRMS_CR2);

	SequentialRayTracing SeqTraceFieldCR2(OptSysCR2);
	SeqTraceFieldCR2.seqRayTracingWithVectorOfLightRays(FillApStopFieldCR2.getVectorWithLightRays());
	Spot SpotDiaFieldCR2(SeqTraceFieldCR2.getAllInterPointsAtSurf_i(1), SeqTraceFieldCR2.getAllInterPointsAtSurf_i(1).at(0));
	real rmsFild_CR2 = SpotDiaFieldCR2.getRMS_mm();
	real RMS_ZemaxFieldCR2 = 0.527453;
	bool checkFieldRMS_CR2 = Math::compareTwoNumbers_decimals(rmsFild_CR2, RMS_ZemaxFieldCR2, 1);
	checkParaxialLens.push_back(checkFieldRMS_CR2);


	// *****************************************************************************************************************
	// *****************************************************************************************************************

	ParaxialLens_LLT ParaxialLensTestCR3(/*semi Height*/ 7.5, /*apex*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*focallength*/ 5.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.5);
	DeflectedRayParaxialLens_LLT deflectCR3(ParaxialLensTestCR3.getInfosForDefelction());
	PlanGeometry_LLT PlanCR3(/*semi Height*/5.0, /*apex*/{ 0.0,0.0,19.8 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0, 1.0);
	FillApertureStop FillApStopCR3(/*start point ray*/{ 0.0,0.0,0.0 }, /*semi height*/ 1.0, /*apex*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.5, Light);
	FillApertureStop FillApStopFieldCR3(/*start point ray*/{ 0.0,1.0,0.0 }, /*semi height*/ 1.0, /*apex*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.5, Light);

	OpticalSystem_LLT OptSysCR3;
	OptSysCR3.fillVectorSurfaceAndInteractingData(0, &ParaxialLensTestCR3, deflectCR3.clone());
	OptSysCR3.fillVectorSurfaceAndInteractingData(1, &PlanCR3, absorb.clone());

	SequentialRayTracing SeqTraceCR3(OptSysCR3);
	SeqTraceCR3.seqRayTracingWithVectorOfLightRays(FillApStopCR3.getVectorWithLightRays());
	Spot SpotDiaCR3(SeqTraceCR3.getAllInterPointsAtSurf_i(1), SeqTraceCR3.getAllInterPointsAtSurf_i(1).at(0));
	real rmsCR3 = SpotDiaCR3.getRMS_mm();
	real RMS_ZemaxCR3 = 0.775965;
	bool checkRMS_CR3 = Math::compareTwoNumbers_decimals(rmsCR3, RMS_ZemaxCR3, 1);
	checkParaxialLens.push_back(checkRMS_CR3);

	// *****************************************************************************************************************
	// *****************************************************************************************************************

	ParaxialLens_LLT ParaxialLensTestCR4(/*semi HlightRayCR4eight*/ 5.0, /*apex*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*focallength*/ 30.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.5);
	DeflectedRayParaxialLens_LLT deflectCR4(ParaxialLensTestCR4.getInfosForDefelction());
	PlanGeometry_LLT PlanCR4(/*semi Height*/5.0, /*apex*/{ 0.0,0.0,100 }, /*direction*/{ 0.0,0.0,1.0 }, 1.5, 1.0);
	Ray_LLT rayCR4(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,1.0,30.0 }, 1.0);
	Light_LLT lightCR4;
	LightRayStruct lightRayCR4(lightCR4, rayCR4, 1);
	OpticalSystem_LLT CR4;
	CR4.fillVectorSurfaceAndInteractingData(0, &ParaxialLensTestCR4, deflectCR4.clone());
	CR4.fillVectorSurfaceAndInteractingData(1, &PlanCR4, absorb.clone());
	SequentialRayTracing traceCR4(CR4);
	traceCR4.sequentialRayTracing(lightRayCR4);
	VectorStructR3 interPointCR4 = traceCR4.getAllInterPointsAtSurf_i(1).at(0);
	
	// *****************************************************************************************************************
	ParaxialLens_LLT ParaxialLens5(/*semi Height*/ 5.0, /*apex*/{ 1.0,1.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*focallength*/ 5.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflect5(ParaxialLens5.getInfosForDefelction());
	PlanGeometry_LLT Plan5(/*semi Height*/20.0, /*apex*/{ 0.0,0.0,20.5 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0, 1.0);

	OpticalSystem_LLT OptSys5;
	OptSys5.fillVectorSurfaceAndInteractingData(0, &ParaxialLens5, deflect5.clone());
	OptSys5.fillVectorSurfaceAndInteractingData(1, &Plan5, absorb.clone());
	
	// start on optical axis
	Ray_LLT Ray51(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,1.0,5.0 }, 1.0);
	Ray_LLT Ray52(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray53(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);

	// start on filed {0.0,1.0,0.0}
	Ray_LLT Ray54(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray55(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);
	Ray_LLT Ray56(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-2.0,5.0 }, 1.0);

	Light_LLT Light5;
	LightRayStruct LightRay51(Light5, Ray51, 1);
	LightRayStruct LightRay52(Light5, Ray52, 1);
	LightRayStruct LightRay53(Light5, Ray53, 1);
	LightRayStruct LightRay54(Light5, Ray54, 1);
	LightRayStruct LightRay55(Light5, Ray55, 1);
	LightRayStruct LightRay56(Light5, Ray56, 1);

	// fill tracing vector
	std::vector<LightRayStruct> vecLightRay5{ LightRay51, LightRay52, LightRay53, LightRay54, LightRay55, LightRay56 };

	// do sequential ray tracing
	SequentialRayTracing seqTrace5(OptSys5);
	seqTrace5.seqRayTracingWithVectorOfLightRays(vecLightRay5);

	// get all intersection points
	std::vector<VectorStructR3> allInterPoints5 = seqTrace5.getAllInterPointsAtSurf_i(1);

	// get the reference points from Zemax
	std::vector<VectorStructR3> refInterPoints5 = { { 2.1, 2.0, 20.5 },{ 2.1, 2.1, 20.5 },{ 2.1, 2.2, 20.5 },{ 2.1, 1.0, 20.5 },{ 2.1, 1.1, 20.5 },{ 2.1, 1.2, 20.5 } };

	// compare trace open with Zemax data
	bool check2 = Math::compareAllVectorElements(allInterPoints5, refInterPoints5, 8);
	checkParaxialLens.push_back(check2);
	// *****************************************************************************************************************
	// *****************************************************************************************************************
	
	ParaxialLens_LLT ParaxialLens6(/*semi Height*/ 5.0, /*apex*/{ -1.0,1.0,10.0 }, /*direction*/{ 0.0,-1.0,1.0 }, /*focallength*/ 5.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflect6(ParaxialLens6.getInfosForDefelction());
	PlanGeometry_LLT Plan6(/*semi Height*/20.0, /*apex*/{ 0.0,0.0,20.5 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0, 1.0);

	OpticalSystem_LLT OptSys6;
	OptSys6.fillVectorSurfaceAndInteractingData(0, &ParaxialLens6, deflect6.clone());
	OptSys6.fillVectorSurfaceAndInteractingData(1, &Plan6, absorb.clone());



	// start on optical axis
	Ray_LLT Ray61(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,1.0,5.0 }, 1.0);
	Ray_LLT Ray62(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray63(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);

	// start on filed {0.0,1.0,0.0}
	Ray_LLT Ray64(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray65(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);
	Ray_LLT Ray66(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-2.0,5.0 }, 1.0);

	Light_LLT Light6;
	LightRayStruct LightRay61(Light6, Ray61, 1);
	LightRayStruct LightRay62(Light6, Ray62, 1);
	LightRayStruct LightRay63(Light6, Ray63, 1);
	LightRayStruct LightRay64(Light6, Ray64, 1);
	LightRayStruct LightRay65(Light6, Ray65, 1);
	LightRayStruct LightRay66(Light6, Ray66, 1);

	// fill tracing vector
	std::vector<LightRayStruct> vecLightRay6{ LightRay61, LightRay62, LightRay63, LightRay64, LightRay65, LightRay66 };

	// do sequential ray tracing
	SequentialRayTracing seqTrace6(OptSys6);
	seqTrace6.seqRayTracingWithVectorOfLightRays(vecLightRay6);

	//VectorStructR3 checkInterPoint2 = seqTrace6.getAllInterPointsAtSurf_i(0).at(0);

	// get all intersection points
	std::vector<VectorStructR3> allInterPoints6 = seqTrace6.getAllInterPointsAtSurf_i(1);

	// get the reference points from Zemax
	std::vector<VectorStructR3> refInterPoints6 = { { -1.2188959553, 2.8811040447, 20.5 },{ -1.424842446, 1.4248424456, 20.5 },{ -1.5489916552, 0.54697496574, 20.5 },{ -1.4849242405, 1.0, 20.5 },{ -1.6095128272, 0.11902565449, 20.5 },{ -1.6890872965, -0.4436508139, 20.5 } };

	// compare trace open with Zemax data
	bool check3 = Math::compareAllVectorElements(allInterPoints6, refInterPoints6, 8);
	checkParaxialLens.push_back(check3);

	// *****************************************************************************************************************
	// *****************************************************************************************************************
	
	ParaxialLens_LLT ParaxialLens7(/*semi Height*/ 5.0, /*apex*/{ 0.5,0.5,8.5 }, /*direction*/{ 17.63269807,0.0,100.0 }, /*focallength*/ 5.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflect7(ParaxialLens7.getInfosForDefelction());
	PlanGeometry_LLT Plan7(/*semi Height*/20.0, /*apex*/{ 0.0,0.0,20.5 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0, 1.0);

	OpticalSystem_LLT OptSys7;
	OptSys7.fillVectorSurfaceAndInteractingData(0, &ParaxialLens7, deflect7.clone());
	OptSys7.fillVectorSurfaceAndInteractingData(1, &Plan7, absorb.clone());

	// start on optical axis
	Ray_LLT Ray71(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,1.0,5.0 }, 1.0);
	Ray_LLT Ray72(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray73(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);

	// start on filed {0.0,2.0,0.0}
	Ray_LLT Ray74(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray75(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);
	Ray_LLT Ray76(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-2.0,5.0 }, 1.0);

	Light_LLT Light7;
	LightRayStruct LightRay71(Light7, Ray71, 1);
	LightRayStruct LightRay72(Light7, Ray72, 1);
	LightRayStruct LightRay73(Light7, Ray73, 1);
	LightRayStruct LightRay74(Light7, Ray74, 1);
	LightRayStruct LightRay75(Light7, Ray75, 1);
	LightRayStruct LightRay76(Light7, Ray76, 1);

	// fill tracing vector
	std::vector<LightRayStruct> vecLightRay7{ LightRay71, LightRay72, LightRay73, LightRay74, LightRay75, LightRay76 };

	// do sequential ray tracing
	SequentialRayTracing seqTrace7(OptSys7);
	seqTrace7.seqRayTracingWithVectorOfLightRays(vecLightRay7);

	// get all intersection points
	std::vector<VectorStructR3> allInterPoints7 = seqTrace7.getAllInterPointsAtSurf_i(1);

	// get the reference points from Zemax
	std::vector<VectorStructR3> refInterPoints7 = { { -0.39677777610, 2.0407565173, 16.155449228 },{ -0.56308456008, -0.56308456008, 15.449869300 },{ -0.67526747025, -2.3195160339, 14.973917521 },{ -0.53109216769, -0.062184335382, 15.585601526 },{ -0.6559312875, -2.0114777364, 15.057388683 },{ -0.74344573491, -3.3869731867, 14.684661641 } };

	// compare trace open with Zemax data
	bool check4 = Math::compareAllVectorElements(allInterPoints7, refInterPoints7, 8);
	checkParaxialLens.push_back(check4);

	// *****************************************************************************************************************
	// *****************************************************************************************************************
	ParaxialLens_LLT ParaxialLens8(/*semi Height*/ 5.0, /*apex*/{ -0.5,-0.5,8.5 }, /*direction*/{ 17.63269807,-17.63269807,100.0 }, /*focallength*/ 5.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflect8(ParaxialLens8.getInfosForDefelction());
	PlanGeometry_LLT Plan8(/*semi Height*/20.0, /*apex*/{ 0.0,0.0,20.5 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0, 1.0);

	OpticalSystem_LLT OptSys8;
	OptSys8.fillVectorSurfaceAndInteractingData(0, &ParaxialLens8, deflect8.clone());
	OptSys8.fillVectorSurfaceAndInteractingData(1, &Plan8, absorb.clone());

	// start on optical axis
	Ray_LLT Ray81(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,1.0,5.0 }, 1.0);
	Ray_LLT Ray82(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray83(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);

	// start on filed {0.0,1.0,0.0}
	Ray_LLT Ray84(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray85(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);
	Ray_LLT Ray86(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-2.0,5.0 }, 1.0);

	Light_LLT Light8;
	LightRayStruct LightRay81(Light8, Ray81, 1);
	LightRayStruct LightRay82(Light8, Ray82, 1);
	LightRayStruct LightRay83(Light8, Ray83, 1);
	LightRayStruct LightRay84(Light8, Ray84, 1);
	LightRayStruct LightRay85(Light8, Ray85, 1);
	LightRayStruct LightRay86(Light8, Ray86, 1);

	// fill tracing vector
	std::vector<LightRayStruct> vecLightRay8{ LightRay81, LightRay82, LightRay83, LightRay84, LightRay85, LightRay86 };

	// do sequential ray tracing
	SequentialRayTracing seqTrace8(OptSys8);
	seqTrace8.seqRayTracingWithVectorOfLightRays(vecLightRay8);

	// get all intersection points
	std::vector<VectorStructR3> allInterPoints8 = seqTrace8.getAllInterPointsAtSurf_i(1);

	// get the reference points from Zemax
	std::vector<VectorStructR3> refInterPoints8 = { { 0.62155966824, 0.89283436818, 13.787566865 },{ 0.53064249902, -0.53064249902, 14.417329574 },{ -0.40221461162, -2.5415192136, 14.718169126 },{ 0.55722466900, -0.11444933801, 14.060517150 },{ 0.44258280610, -1.9093802764, 14.546901382 },{ 0.27333122941, -4.5593275442, 15.264975008 } };

	// compare trace open with Zemax data
	bool check5 = Math::compareAllVectorElements(allInterPoints8, refInterPoints8, 8);
	checkParaxialLens.push_back(check5);
	// *****************************************************************************************************************

	// negative focal length!!!
	// *****************************************************************************************************************
	ParaxialLens_LLT ParaxialLens9(/*semi Height*/ 5.0, /*apex*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*focallength*/ -5.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflect9(ParaxialLens9.getInfosForDefelction());
	PlanGeometry_LLT Plan9(/*semi Height*/20.0, /*apex*/{ 0.0,0.0,20.5 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0, 1.0);

	OpticalSystem_LLT OptSys9;
	OptSys9.fillVectorSurfaceAndInteractingData(0, &ParaxialLens9, deflect9.clone());
	OptSys9.fillVectorSurfaceAndInteractingData(1, &Plan9, absorb.clone());

	// start on optical axis
	Ray_LLT Ray91(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,1.0,5.0 }, 1.0);
	Ray_LLT Ray92(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray93(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);

	// start on filed {0.0,1.0,0.0}
	Ray_LLT Ray94(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray95(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);
	Ray_LLT Ray96(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-2.0,5.0 }, 1.0);

	Light_LLT Light9;
	LightRayStruct LightRay91(Light9, Ray91, 1);
	LightRayStruct LightRay92(Light9, Ray92, 1);
	LightRayStruct LightRay93(Light9, Ray93, 1);
	LightRayStruct LightRay94(Light9, Ray94, 1);
	LightRayStruct LightRay95(Light9, Ray95, 1);
	LightRayStruct LightRay96(Light9, Ray96, 1);

	// fill tracing vector
	std::vector<LightRayStruct> vecLightRay9{ LightRay91, LightRay92, LightRay93, LightRay94, LightRay95, LightRay96 };

	// do sequential ray tracing
	SequentialRayTracing seqTrace9(OptSys9);
	seqTrace9.seqRayTracingWithVectorOfLightRays(vecLightRay9);

	// get all intersection points
	std::vector<VectorStructR3> allInterPoints9 = seqTrace9.getAllInterPointsAtSurf_i(1);

	// get the reference points from Zemax
	std::vector<VectorStructR3> refInterPoints9 = { { 0.0, 8.3, 20.5 },{ 0.0, 0.0, 20.5 },{ 0.0, -8.3, 20.5 },{ 0.0, 3.1, 20.5 },{ 0.0, -5.2, 20.5 },{ 0.0, -13.5, 20.5 } };

	// compare trace open with Zemax data
	bool check6 = Math::compareAllVectorElements(allInterPoints9, refInterPoints9, 8);
	checkParaxialLens.push_back(check6);
	// *****************************************************************************************************************

	// *****************************************************************************************************************
	ParaxialLens_LLT ParaxialLens10(/*semi Height*/ 5.0, /*apex*/{ 1.0,-1.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*focallength*/ -5.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflect10(ParaxialLens10.getInfosForDefelction());
	PlanGeometry_LLT Plan10(/*semi Height*/20.0, /*apex*/{ 0.0,0.0,20.5 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0, 1.0);

	OpticalSystem_LLT OptSys10;
	OptSys10.fillVectorSurfaceAndInteractingData(0, &ParaxialLens10, deflect10.clone());
	OptSys10.fillVectorSurfaceAndInteractingData(1, &Plan10, absorb.clone());

	// start on optical axis
	Ray_LLT Ray101(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,1.0,5.0 }, 1.0);
	Ray_LLT Ray102(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray103(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);

	// start on filed {0.0,1.0,0.0}
	Ray_LLT Ray104(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray105(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);
	Ray_LLT Ray106(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-2.0,5.0 }, 1.0);

	Light_LLT Light10;
	LightRayStruct LightRay101(Light10, Ray101, 1);
	LightRayStruct LightRay102(Light10, Ray102, 1);
	LightRayStruct LightRay103(Light10, Ray103, 1);
	LightRayStruct LightRay104(Light10, Ray104, 1);
	LightRayStruct LightRay105(Light10, Ray105, 1);
	LightRayStruct LightRay106(Light10, Ray106, 1);

	// fill tracing vector
	std::vector<LightRayStruct> vecLightRay10{ LightRay101, LightRay102, LightRay103, LightRay104, LightRay105, LightRay106 };

	// do sequential ray tracing
	SequentialRayTracing seqTrace10(OptSys10);
	seqTrace10.seqRayTracingWithVectorOfLightRays(vecLightRay10);

	// get all intersection points
	std::vector<VectorStructR3> allInterPoints10 = seqTrace10.getAllInterPointsAtSurf_i(1);

	// get the reference points from Zemax
	std::vector<VectorStructR3> refInterPoints10 = { { -2.1, 10.4, 20.5 },{ -2.1, 2.1, 20.5 },{ -2.1, -6.2, 20.5 },{ -2.1, 5.2, 20.5 },{ -2.1, -3.1, 20.5 },{ -2.1, -11.4, 20.5 } };

	// compare trace open with Zemax data
	bool check7 = Math::compareAllVectorElements(allInterPoints10, refInterPoints10, 8);
	checkParaxialLens.push_back(check7);
	// *****************************************************************************************************************
	// *****************************************************************************************************************
	ParaxialLens_LLT ParaxialLens11(/*semi Height*/ 5.0, /*apex*/{ -1.0,1.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*focallength*/ -5.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflect11(ParaxialLens11.getInfosForDefelction());
	PlanGeometry_LLT Plan11(/*semi Height*/20.0, /*apex*/{ 0.0,0.0,20.5 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0, 1.0);

	OpticalSystem_LLT OptSys11;
	OptSys11.fillVectorSurfaceAndInteractingData(0, &ParaxialLens11, deflect11.clone());
	OptSys11.fillVectorSurfaceAndInteractingData(1, &Plan11, absorb.clone());

	// start on optical axis
	Ray_LLT Ray111(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,1.0,5.0 }, 1.0);
	Ray_LLT Ray112(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray113(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);

	// start on filed {0.0,1.0,0.0}
	Ray_LLT Ray114(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray115(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);
	Ray_LLT Ray116(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-2.0,5.0 }, 1.0);

	Light_LLT Light11;
	LightRayStruct LightRay111(Light11, Ray111, 1);
	LightRayStruct LightRay112(Light11, Ray112, 1);
	LightRayStruct LightRay113(Light11, Ray113,  1);
	LightRayStruct LightRay114(Light11, Ray114, 1);
	LightRayStruct LightRay115(Light11, Ray115, 1);
	LightRayStruct LightRay116(Light11, Ray116, 1);

	// fill tracing vector
	std::vector<LightRayStruct> vecLightRay11{ LightRay111, LightRay112, LightRay113, LightRay114, LightRay115, LightRay116 };

	// do sequential ray tracing
	SequentialRayTracing seqTrace11(OptSys11);
	seqTrace11.seqRayTracingWithVectorOfLightRays(vecLightRay11);

	// get all intersection points
	std::vector<VectorStructR3> allInterPoints11 = seqTrace11.getAllInterPointsAtSurf_i(1);

	// get the reference points from Zemax
	std::vector<VectorStructR3> refInterPoints11 = { { 2.1, 6.2, 20.5 },{ 2.1, -2.1, 20.5 },{ 2.1, -10.4, 20.5 },{ 2.1, 1.0, 20.5 },{ 2.1, -7.3, 20.5 },{ 2.1, -15.6, 20.5 } };

	// compare trace open with Zemax data
	bool check8 = Math::compareAllVectorElements(allInterPoints11, refInterPoints11, 8);
	checkParaxialLens.push_back(check8);
	// *****************************************************************************************************************

	// *****************************************************************************************************************
	ParaxialLens_LLT ParaxialLens12(/*semi Height*/ 5.0, /*apex*/{ 0.5,0.5,8.5 }, /*direction*/{ 17.63269807,0.0,100.0 }, /*focallength*/ -5.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflect12(ParaxialLens12.getInfosForDefelction());
	PlanGeometry_LLT Plan12(/*semi Height*/20.0, /*apex*/{ 0.0,0.0,20.5 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0, 1.0);

	OpticalSystem_LLT OptSys12;
	OptSys12.fillVectorSurfaceAndInteractingData(0, &ParaxialLens12, deflect12.clone());
	OptSys12.fillVectorSurfaceAndInteractingData(1, &Plan12, absorb.clone());

	// start on optical axis
	Ray_LLT Ray121(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,1.0,5.0 }, 1.0);
	Ray_LLT Ray122(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray123(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);

	// start on filed {0.0,1.0,0.0}
	Ray_LLT Ray124(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray125(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);
	Ray_LLT Ray126(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-2.0,5.0 }, 1.0);

	Light_LLT Light12;
	LightRayStruct LightRay121(Light12, Ray121, 1);
	LightRayStruct LightRay122(Light12, Ray122, 1);
	LightRayStruct LightRay123(Light12, Ray123, 1);
	LightRayStruct LightRay124(Light12, Ray124, 1);
	LightRayStruct LightRay125(Light12, Ray125, 1);
	LightRayStruct LightRay126(Light12, Ray126, 1);

	// fill tracing vector
	std::vector<LightRayStruct> vecLightRay12{ LightRay121, LightRay122, LightRay123, LightRay124, LightRay125, LightRay126 };

	// do sequential ray tracing
	SequentialRayTracing seqTrace12(OptSys12);
	seqTrace12.seqRayTracingWithVectorOfLightRays(vecLightRay12);

	// get all intersection points
	std::vector<VectorStructR3> allInterPoints12 = seqTrace12.getAllInterPointsAtSurf_i(1);

	// get the reference points from Zemax
	//Programm gibt 5 Intersection Points aus, Zemax 6
	std::vector<VectorStructR3> refInterPoints12 = { {},{},{},{},{} }; // Zemax daten einfüllen

	// compare trace open with Zemax data
	bool check9 = Math::compareAllVectorElements(allInterPoints12, refInterPoints12, 8);
	checkParaxialLens.push_back(check9);
	// *****************************************************************************************************************
	// *****************************************************************************************************************
	ParaxialLens_LLT ParaxialLens13(/*semi Height*/ 5.0, /*apex*/{ 0.5,0.5,8.5 }, /*direction*/{ 17.63269807,-17.63269807,100.0 }, /*focallength*/ -5.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflect13(ParaxialLens13.getInfosForDefelction());
	PlanGeometry_LLT Plan13(/*semi Height*/20.0, /*apex*/{ 0.0,0.0,20.5 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0, 1.0);

	OpticalSystem_LLT OptSys13;
	OptSys13.fillVectorSurfaceAndInteractingData(0, &ParaxialLens13, deflect13.clone());
	OptSys13.fillVectorSurfaceAndInteractingData(1, &Plan13, absorb.clone());

	// start on optical axis
	Ray_LLT Ray131(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,1.0,5.0 }, 1.0);
	Ray_LLT Ray132(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray133(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);

	// start on filed {0.0,1.0,0.0}
	Ray_LLT Ray134(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray135(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);
	Ray_LLT Ray136(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-2.0,5.0 }, 1.0);

	Light_LLT Light13;
	LightRayStruct LightRay131(Light13, Ray131, 1);
	LightRayStruct LightRay132(Light13, Ray132, 1);
	LightRayStruct LightRay133(Light13, Ray133, 1);
	LightRayStruct LightRay134(Light13, Ray134, 1);
	LightRayStruct LightRay135(Light13, Ray135, 1);
	LightRayStruct LightRay136(Light13, Ray136, 1);

	// fill tracing vector
	std::vector<LightRayStruct> vecLightRay13{ LightRay131, LightRay132, LightRay133, LightRay134, LightRay135, LightRay136 };

	// do sequential ray tracing
	SequentialRayTracing seqTrace13(OptSys13);
	seqTrace13.seqRayTracingWithVectorOfLightRays(vecLightRay13);

	// get all intersection points
	std::vector<VectorStructR3> allInterPoints13 = seqTrace13.getAllInterPointsAtSurf_i(1);

	// get the reference points from Zemax
	// Programm gibt 5 IntersectionPoints raus, Zemax 6
	std::vector<VectorStructR3> refInterPoints13 = { {},{},{},{},{} };

	// compare trace open with Zemax data
	bool check10 = Math::compareAllVectorElements(allInterPoints13, refInterPoints13, 8);
	checkParaxialLens.push_back(check10);
	// *****************************************************************************************************************


	// positiv focal length!!! --> change refractive index
	// *****************************************************************************************************************
	ParaxialLens_LLT ParaxialLens14(/*semi Height*/ 5.0, /*apex*/{ 0.0,0.0,8.5 }, /*direction*/{ 0.0,0.0,1.0 }, /*focallength*/ 5.0, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflect14(ParaxialLens14.getInfosForDefelction());
	PlanGeometry_LLT Plan14(/*semi Height*/20.0, /*apex*/{ 0.0,0.0,20.5 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0, 1.0);

	OpticalSystem_LLT OptSys14;
	OptSys14.fillVectorSurfaceAndInteractingData(0, &ParaxialLens14, deflect14.clone());
	OptSys14.fillVectorSurfaceAndInteractingData(1, &Plan14, absorb.clone());

	// start on optical axis
	Ray_LLT Ray141(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,1.0,5.0 }, 1.5);
	Ray_LLT Ray142(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.5);
	Ray_LLT Ray143(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.5);

	// start on filed {0.0,1.0,0.0}
	Ray_LLT Ray144(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.5);
	Ray_LLT Ray145(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.5);
	Ray_LLT Ray146(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-2.0,5.0 }, 1.5);

	Light_LLT Light14;
	LightRayStruct LightRay141(Light14, Ray141, 1);
	LightRayStruct LightRay142(Light14, Ray142, 1);
	LightRayStruct LightRay143(Light14, Ray143, 1);
	LightRayStruct LightRay144(Light14, Ray144, 1);
	LightRayStruct LightRay145(Light14, Ray145, 1);
	LightRayStruct LightRay146(Light14, Ray146, 1);

	// fill tracing vector
	std::vector<LightRayStruct> vecLightRay14{ LightRay141, LightRay142, LightRay143, LightRay144, LightRay145, LightRay146 };

	// do sequential ray tracing
	SequentialRayTracing seqTrace14(OptSys14);
	seqTrace14.seqRayTracingWithVectorOfLightRays(vecLightRay14);

	// get all intersection points
	std::vector<VectorStructR3> allInterPoints14 = seqTrace14.getAllInterPointsAtSurf_i(1);

	// get the reference points from Zemax
	std::vector<VectorStructR3> refInterPoints14 = { { 0.0, 0.2517299704, 20.5 },{ 0.0, 0.0, 20.5 },{ 0.0, -0.25172997046, 20.5 },{ 0.0, -1.1, 20.5 },{ 0.0, -1.3517299795, 20.5 },{ 0.0, -1.5193939165, 20.5 } };

	// compare trace open with Zemax data
	bool check11 = Math::compareAllVectorElements(allInterPoints14, refInterPoints14, 8);
	checkParaxialLens.push_back(check11);
	// *****************************************************************************************************************

	// positiv focal length!!! --> change refractive index
	// *****************************************************************************************************************
	ParaxialLens_LLT ParaxialLens15(/*semi Height*/ 5.0, /*apex*/{ 0.0,0.0,8.5 }, /*direction*/{ 0.0,0.0,1.0 }, /*focallength*/ 5.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.5);
	DeflectedRayParaxialLens_LLT deflect15(ParaxialLens15.getInfosForDefelction());
	PlanGeometry_LLT Plan15(/*semi Height*/20.0, /*apex*/{ 0.0,0.0,20.5 }, /*direction*/{ 0.0,0.0,1.0 }, 1.5, 1.0);

	OpticalSystem_LLT OptSys15;
	OptSys15.fillVectorSurfaceAndInteractingData(0, &ParaxialLens15, deflect15.clone());
	OptSys15.fillVectorSurfaceAndInteractingData(1, &Plan15, absorb.clone());

	// start on optical axis
	Ray_LLT Ray151(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,1.0,5.0 }, 1.0);
	Ray_LLT Ray152(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray153(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);

	// start on filed {0.0,1.0,0.0}
	Ray_LLT Ray154(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray155(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);
	Ray_LLT Ray156(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-2.0,5.0 }, 1.0);

	Light_LLT Light15;
	LightRayStruct LightRay151(Light15, Ray151, 1);
	LightRayStruct LightRay152(Light15, Ray152, 1);
	LightRayStruct LightRay153(Light15, Ray153, 1);
	LightRayStruct LightRay154(Light15, Ray154, 1);
	LightRayStruct LightRay155(Light15, Ray155, 1);
	LightRayStruct LightRay156(Light15, Ray156, 1);

	// fill tracing vector
	std::vector<LightRayStruct> vecLightRay15{LightRay151, LightRay152, LightRay153, LightRay154, LightRay155, LightRay156 };

	// do sequential ray tracing
	SequentialRayTracing seqTrace15(OptSys15);
	seqTrace15.seqRayTracingWithVectorOfLightRays(vecLightRay15);

	// get all intersection points
	std::vector<VectorStructR3> allInterPoints15 = seqTrace15.getAllInterPointsAtSurf_i(1);

	// get the reference points from Zemax
	std::vector<VectorStructR3> refInterPoints15 = { { 0.0, 0.6, 20.5 },{ 0.0, 0.0, 20.5 },{ 0.0, -0.6, 20.5 },{ 0.0, -0.4, 20.5 },{ 0.0, -1.0, 20.5 },{ 0.0, -1.6, 20.5 } };

	// compare trace open with Zemax data
	bool check12 = Math::compareAllVectorElements(allInterPoints15, refInterPoints15, 8);
	checkParaxialLens.push_back(check12);
	// *****************************************************************************************************************

	// positiv focal length!!! --> change refractive index
	// *****************************************************************************************************************
	ParaxialLens_LLT ParaxialLens16(/*semi Height*/ 5.0, /*apex*/{ 0.0,0.0,8.5 }, /*direction*/{ 0.0,0.0,1.0 }, /*focallength*/ 5.0, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.5);
	DeflectedRayParaxialLens_LLT deflect16(ParaxialLens16.getInfosForDefelction());
	PlanGeometry_LLT Plan16(/*semi Height*/20.0, /*apex*/{ 0.0,0.0,20.5 }, /*direction*/{ 0.0,0.0,1.0 }, 1.5, 1.0);

	OpticalSystem_LLT OptSys16;
	OptSys16.fillVectorSurfaceAndInteractingData(0, &ParaxialLens16, deflect16.clone());
	OptSys16.fillVectorSurfaceAndInteractingData(1, &Plan16, absorb.clone());

	// start on optical axis
	Ray_LLT Ray161(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,1.0,5.0 }, 1.5);
	Ray_LLT Ray162(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.5);
	Ray_LLT Ray163(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.5);

	// start on filed {0.0,1.0,0.0}
	Ray_LLT Ray164(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.5);
	Ray_LLT Ray165(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.5);
	Ray_LLT Ray166(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-2.0,5.0 }, 1.5);

	Light_LLT Light16;
	LightRayStruct LightRay161(Light16, Ray161, 1);
	LightRayStruct LightRay162(Light16, Ray162, 1);
	LightRayStruct LightRay163(Light16, Ray163, 1);
	LightRayStruct LightRay164(Light16, Ray164, 1);
	LightRayStruct LightRay165(Light16, Ray165, 1);
	LightRayStruct LightRay166(Light16, Ray166, 1);

	// fill tracing vector
	std::vector<LightRayStruct> vecLightRay16{ LightRay161, LightRay162, LightRay163, LightRay164, LightRay165, LightRay166 };

	// do sequential ray tracing
	SequentialRayTracing seqTrace16(OptSys16);
	seqTrace16.seqRayTracingWithVectorOfLightRays(vecLightRay16);

	// get all intersection points
	std::vector<VectorStructR3> allInterPoints16 = seqTrace16.getAllInterPointsAtSurf_i(1);

	// get the reference points from Zemax
	std::vector<VectorStructR3> refInterPoints16 = { { 0.0, 0.72094680477, 20.5 },{ 0.0, 0.0, 20.5 },{ 0.0, -0.72094680477, 20.5 },{ 0.0, -0.4, 20.5 },{ 0.0, -1.1209468048, 20.5 },{ 0.0, -1.7721803210, 20.5 } };

	// compare trace open with Zemax data
	bool check13 = Math::compareAllVectorElements(allInterPoints16, refInterPoints16, 8);
	checkParaxialLens.push_back(check13);
	// *****************************************************************************************************************

	// positiv focal length!!! --> change refractive index
	// *****************************************************************************************************************
	ParaxialLens_LLT ParaxialLens17(/*semi Height*/ 5.0, /*apex*/{ 0.5,-0.5,8.5 }, /*direction*/{ 0.0,-17.63269807,100.0 }, /*focallength*/ 5.0, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.5);
	DeflectedRayParaxialLens_LLT deflect17(ParaxialLens17.getInfosForDefelction());
	PlanGeometry_LLT Plan17(/*semi Height*/20.0, /*apex*/{ 0.0,0.0,20.5 }, /*direction*/{ 0.0,0.0,1.0 }, 1.5, 1.0);

	OpticalSystem_LLT OptSys17;
	OptSys17.fillVectorSurfaceAndInteractingData(0, &ParaxialLens17, deflect17.clone());
	OptSys17.fillVectorSurfaceAndInteractingData(1, &Plan17, absorb.clone());

	


	// start on optical axis
	Ray_LLT Ray171(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,1.0,5.0 }, 1.5);
	Ray_LLT Ray172(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.5);
	Ray_LLT Ray173(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.5);

	// start on filed {0.0,1.0,0.0}
	Ray_LLT Ray174(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.5);
	Ray_LLT Ray175(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.5);
	Ray_LLT Ray176(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-2.0,5.0 }, 1.5);

	Light_LLT Light17;
	LightRayStruct LightRay171(Light17, Ray171, 1);
	LightRayStruct LightRay172(Light17, Ray172, 1);
	LightRayStruct LightRay173(Light17, Ray173, 1);
	LightRayStruct LightRay174(Light17, Ray174, 1);
	LightRayStruct LightRay175(Light17, Ray175, 1);
	LightRayStruct LightRay176(Light17, Ray176, 1);

	//***
//	// single ray tracing
//	SequentialRayTracing seqTest(OptSys17);
//	seqTest.sequentialRayTracing(LightRay171);
//	VectorStructR3 interPoint = seqTest.getAllInterPointsAtSurf_i(0).at(0);
	//***

	// fill tracing vector
	std::vector<LightRayStruct> vecLightRay17{ LightRay171, LightRay172, LightRay173, LightRay174, LightRay175, LightRay176 };

	// do sequential ray tracing
	SequentialRayTracing seqTrace17(OptSys17);
	seqTrace17.seqRayTracingWithVectorOfLightRays(vecLightRay17);

	// get all intersection points
	std::vector<VectorStructR3> allInterPoints17 = seqTrace17.getAllInterPointsAtSurf_i(1);

	// get the reference points from Zemax
	std::vector<VectorStructR3> refInterPoints17 = { { 0.77361587816, 0.48792108094, 16.717514421 },{ 0.66492454974, -0.6649245497, 16.717514421 },{ 0.51996977377, -2.2024021256, 16.717514421 },{ 0.69150391330, -0.38300782660, 16.717514421 },{ 0.56381927818, -1.7373078968, 16.717514421 },{ 0.39909494089, -3.4844733356, 16.717514421 } };

	// compare trace open with Zemax data
	bool check14 = Math::compareAllVectorElements(allInterPoints17, refInterPoints17, 8);
	checkParaxialLens.push_back(check14);
	// *****************************************************************************************************************


	// negativ focal length!!! --> change refractive index
	// *****************************************************************************************************************
	ParaxialLens_LLT ParaxialLens18(/*semi Height*/ 5.0, /*apex*/{ 0.0,0.0,8.5 }, /*direction*/{ 0.0,0.0,1.0 }, /*focallength*/ -5.0, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflect18(ParaxialLens18.getInfosForDefelction());
	PlanGeometry_LLT Plan18(/*semi Height*/20.0, /*apex*/{ 0.0,0.0,20.5 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0, 1.0);

	OpticalSystem_LLT OptSys18;
	OptSys18.fillVectorSurfaceAndInteractingData(0, &ParaxialLens18, deflect18.clone());
	OptSys18.fillVectorSurfaceAndInteractingData(1, &Plan18, absorb.clone());

	// start on optical axis
	Ray_LLT Ray181(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,1.0,5.0 }, 1.5);
	Ray_LLT Ray182(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.5);
	Ray_LLT Ray183(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.5);

	// start on filed {0.0,1.0,0.0}
	Ray_LLT Ray184(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.5);
	Ray_LLT Ray185(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.5);
	Ray_LLT Ray186(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-2.0,5.0 }, 1.5);

	Light_LLT Light18;
	LightRayStruct LightRay181(Light18, Ray181, 1);
	LightRayStruct LightRay182(Light18, Ray182, 1);
	LightRayStruct LightRay183(Light18, Ray183, 1);
	LightRayStruct LightRay184(Light18, Ray184, 1);
	LightRayStruct LightRay185(Light18, Ray185, 1);
	LightRayStruct LightRay186(Light18, Ray186, 1);

	//***
		// single ray tracing
		SequentialRayTracing seqTest1(OptSys18);
		seqTest1.sequentialRayTracing(LightRay181);
		IntersectInformationStruct interInfos10 = seqTest1.getAllInterInfosOfSurf_i(0).at(0);
		IntersectInformationStruct interInfos11 = seqTest1.getAllInterInfosOfSurf_i(1).at(0);
	//***

	// fill tracing vector
	std::vector<LightRayStruct> vecLightRay18{ LightRay181, LightRay182, LightRay183, LightRay184, LightRay185, LightRay186 };

	// do sequential ray tracing
	SequentialRayTracing seqTrace18(OptSys18);
	seqTrace18.seqRayTracingWithVectorOfLightRays(vecLightRay18);

	// get all intersection points
	std::vector<VectorStructR3> allInterPoints18 = seqTrace18.getAllInterPointsAtSurf_i(1);

	// get the reference points from Zemax
	std::vector<VectorStructR3> refInterPoints18 = { { 0.0, 7.2211279587, 20.5 },{ 0.0, 0.0, 20.5 },{ 0.0, -7.2211279587, 20.5 },{ 0.0, 3.1, 20.5 },{ 0.0, -4.1211279587, 20.5 },{ 0.0, -11.085957062, 20.5 } };

	// compare trace open with Zemax data
	bool check15 = Math::compareAllVectorElements(allInterPoints18, refInterPoints18, 8);
	checkParaxialLens.push_back(check15);
	// *****************************************************************************************************************

	// positiv focal length!!! --> change refractive index
	// *****************************************************************************************************************
	ParaxialLens_LLT ParaxialLens19(/*semi Height*/ 5.0, /*apex*/{ 0.0,0.0,8.5 }, /*direction*/{ 0.0,0.0,1.0 }, /*focallength*/ -5.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.5);
	DeflectedRayParaxialLens_LLT deflect19(ParaxialLens19.getInfosForDefelction());
	PlanGeometry_LLT Plan19(/*semi Height*/20.0, /*apex*/{ 0.0,0.0,20.5 }, /*direction*/{ 0.0,0.0,1.0 }, 1.5, 1.0);

	OpticalSystem_LLT OptSys19;
	OptSys19.fillVectorSurfaceAndInteractingData(0, &ParaxialLens19, deflect19.clone());
	OptSys19.fillVectorSurfaceAndInteractingData(1, &Plan19, absorb.clone());

	// start on optical axis
	Ray_LLT Ray191(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,1.0,5.0 }, 1.0);
	Ray_LLT Ray192(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray193(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);

	// start on filed {0.0,1.0,0.0}
	Ray_LLT Ray194(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.0);
	Ray_LLT Ray195(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.0);
	Ray_LLT Ray196(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-2.0,5.0 }, 1.0);

	Light_LLT Light19;
	LightRayStruct LightRay191(Light19, Ray181, 1);
	LightRayStruct LightRay192(Light19, Ray182, 1);
	LightRayStruct LightRay193(Light19, Ray183, 1);
	LightRayStruct LightRay194(Light19, Ray184, 1);
	LightRayStruct LightRay195(Light19, Ray185, 1);
	LightRayStruct LightRay196(Light19, Ray186, 1);

	// fill tracing vector
	std::vector<LightRayStruct> vecLightRay19{ LightRay191, LightRay192, LightRay193, LightRay194, LightRay195, LightRay196 };

	// do sequential ray tracing
	SequentialRayTracing seqTrace19(OptSys19);
	seqTrace19.seqRayTracingWithVectorOfLightRays(vecLightRay19);

	// get all intersection points
	std::vector<VectorStructR3> allInterPoints19 = seqTrace19.getAllInterPointsAtSurf_i(1);

	// get the reference points from Zemax
	std::vector<VectorStructR3> refInterPoints19 = { { 0.0, 6.2, 20.5 },{ 0.0, 0.0, 20.5 },{ 0.0, -6.2, 20.5 },{ 0.0, 2.4, 20.5 },{ 0.0, -3.8, 20.5 },{ 0.0, -10.5, 20.5 } };

	// compare trace open with Zemax data
	bool check16 = Math::compareAllVectorElements(allInterPoints19, refInterPoints19, 8);
	checkParaxialLens.push_back(check16);
	// *****************************************************************************************************************

	// positiv focal length!!! --> change refractive index
	// *****************************************************************************************************************
	ParaxialLens_LLT ParaxialLens20(/*semi Height*/ 5.0, /*apex*/{ 0.0,0.0,8.5 }, /*direction*/{ 0.0,0.0,1.0 }, /*focallength*/ -5.0, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.5);
	DeflectedRayParaxialLens_LLT deflect20(ParaxialLens20.getInfosForDefelction());
	PlanGeometry_LLT Plan20(/*semi Height*/20.0, /*apex*/{ 0.0,0.0,20.5 }, /*direction*/{ 0.0,0.0,1.0 }, 1.5, 1.0);

	OpticalSystem_LLT OptSys20;
	OptSys20.fillVectorSurfaceAndInteractingData(0, &ParaxialLens20, deflect20.clone());
	OptSys20.fillVectorSurfaceAndInteractingData(1, &Plan20, absorb.clone());

	// start on optical axis
	Ray_LLT Ray201(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,1.0,5.0 }, 1.5);
	Ray_LLT Ray202(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.5);
	Ray_LLT Ray203(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.5);

	// start on filed {0.0,1.0,0.0}
	Ray_LLT Ray204(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.5);
	Ray_LLT Ray205(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.5);
	Ray_LLT Ray206(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-2.0,5.0 }, 1.5);

	Light_LLT Light20;
	LightRayStruct LightRay201(Light20, Ray201, 1);
	LightRayStruct LightRay202(Light20, Ray202, 1);
	LightRayStruct LightRay203(Light20, Ray203, 1);
	LightRayStruct LightRay204(Light20, Ray204, 1);
	LightRayStruct LightRay205(Light20, Ray205, 1);
	LightRayStruct LightRay206(Light20, Ray206, 1);

	// fill tracing vector
	std::vector<LightRayStruct> vecLightRay20{ LightRay201, LightRay202, LightRay203, LightRay204, LightRay205, LightRay206 };

	// do sequential ray tracing
	SequentialRayTracing seqTrace20(OptSys20);
	seqTrace20.seqRayTracingWithVectorOfLightRays(vecLightRay20);

	// get all intersection points
	std::vector<VectorStructR3> allInterPoints20 = seqTrace20.getAllInterPointsAtSurf_i(1);

	// get the reference points from Zemax
	std::vector<VectorStructR3> refInterPoints20 = { { 0.0, 5.3672121303, 20.5 },{ 0.0, 0.0, 20.5 },{ 0.0, -5.3672121303, 20.5 },{ 0.0, 2.4, 20.5 },{ 0.0, -2.9672121303, 20.5 },{ 0.0, -8.1498890850, 20.5 } };

	// compare trace open with Zemax data
	bool check17 = Math::compareAllVectorElements(allInterPoints20, refInterPoints20, 8); 
	checkParaxialLens.push_back(check17);
	// *****************************************************************************************************************

	// positiv focal length!!! --> change refractive index
	// *****************************************************************************************************************
	ParaxialLens_LLT ParaxialLens21(/*semi Height*/ 5.0, /*apex*/{ -0.5,0.5,8.5 }, /*direction*/{ -17.63269807,-17.63269807,100.0 }, /*focallength*/ -5.0, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.5);
	DeflectedRayParaxialLens_LLT deflect21(ParaxialLens21.getInfosForDefelction());
	PlanGeometry_LLT Plan21(/*semi Height*/20.0, /*apex*/{ 0.0,0.0,20.5 }, /*direction*/{ 0.0,0.0,1.0 }, 1.5, 1.0);

	OpticalSystem_LLT OptSys21;
	OptSys21.fillVectorSurfaceAndInteractingData(0, &ParaxialLens18, deflect18.clone());
	OptSys21.fillVectorSurfaceAndInteractingData(1, &Plan18, absorb.clone());

	// start on optical axis
	Ray_LLT Ray211(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,1.0,5.0 }, 1.5);
	Ray_LLT Ray212(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.5);
	Ray_LLT Ray213(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.5);

	// start on filed {0.0,1.0,0.0}
	Ray_LLT Ray214(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,0.0,5.0 }, 1.5);
	Ray_LLT Ray215(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-1.0,5.0 }, 1.5);
	Ray_LLT Ray216(/*origin*/{ 0.0, 1.0, 0.0 }, /*direction*/{ 0.0,-2.0,5.0 }, 1.5);

	Light_LLT Light21;
	LightRayStruct LightRay211(Light21, Ray211, 1);
	LightRayStruct LightRay212(Light21, Ray212, 1);
	LightRayStruct LightRay213(Light21, Ray213, 1);
	LightRayStruct LightRay214(Light21, Ray214, 1);
	LightRayStruct LightRay215(Light21, Ray215, 1);
	LightRayStruct LightRay216(Light21, Ray216, 1);

	// fill tracing vector
	std::vector<LightRayStruct> vecLightRay21{ LightRay211, LightRay212, LightRay213, LightRay214, LightRay215, LightRay216 };

	// do sequential ray tracing
	SequentialRayTracing seqTrace21(OptSys21);
	seqTrace21.seqRayTracingWithVectorOfLightRays(vecLightRay21);

	// get all intersection points
	std::vector<VectorStructR3> allInterPoints21 = seqTrace21.getAllInterPointsAtSurf_i(1);

	// get the reference points from Zemax
	std::vector<VectorStructR3> refInterPoints21 = { { 0.17999378040, 2.5599017334, 15.928571647 },{ 3.0787914593, -0.30787914593, 15.159928469 },{ 0.44654819857, -3.4174801238, 14.326470936 },{ 0.24955579081, 1.0, 15.510475608 },{ 0.37944749656, -1.9127722988, 14.729773508 },{ 0.51566736715, -4.9674512971, 14.911036557 } };

	// compare trace open with Zemax data
	bool check18 = Math::compareAllVectorElements(allInterPoints21, refInterPoints21, 8);
	checkParaxialLens.push_back(check18);
	// *****************************************************************************************************************
	
	// *****************************************************************************************************************
	bool output = Math::checkTrueOfVectorElements(checkParaxialLens);
	// *****************************************************************************************************************

	return output;
}