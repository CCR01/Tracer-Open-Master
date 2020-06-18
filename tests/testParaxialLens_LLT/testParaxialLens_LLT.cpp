#include "testParaxialLens_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DeflectedRayParaxialLens_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\FillAptertureStop\FillApertureStop.h"
#include "..\..\Analyse\Spot.h"
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\Analyse\Spot.h"
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"


testParaxialLens::testParaxialLens() {};
testParaxialLens::~testParaxialLens() {};

// check methodes of class ParaxialLens_LLT
bool  testParaxialLens::checkMethodesParaxialLens_LLT()
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

	Spot SpotValue(seqTraceE1.getAllInterPointsAtSurf_i_notFiltered(4), seqTraceE1.getAllInterPointsAtSurf_i_notFiltered(4).at(0));

	double RMS_E1 = SpotValue.getRMS_µm();
	double GEO_E1 = SpotValue.getGeoRadius();

	bool checkRMSvalueE1 = Math::compareTwoNumbers_decimals(RMS_E1, 7.607, 2);
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
	std::vector<VectorStructR3> allInterPoints = seqTrace4.getAllInterPointsAtSurf_i_notFiltered(1);

	// get the reference points from Zemax
	std::vector<VectorStructR3> refInterPoints = { {0.0,-0.1,20.5},{0.0,0.0,20.5},{0.0,0.1,20.5},{ 0.0,-1.1,20.5 },{ 0.0,-1.0,20.5 },{ 0.0,-0.9,20.5 } };

	// compare trace open with Zemax data
	bool chech1 = Math::compareAllVectorElements(allInterPoints, refInterPoints, 2);
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
	Spot SpotDiaCR1(SeqTraceCR1.getAllInterPointsAtSurf_i_notFiltered(1), SeqTraceCR1.getAllInterPointsAtSurf_i_notFiltered(1).at(0));
	real rmsCR1 = SpotDiaCR1.getRMS_µm();
	real RMSCR1_Z = 30.430;
	bool checkRMS_CR1 = Math::compareTwoNumbers_decimals(rmsCR1, RMSCR1_Z, 2);
	checkParaxialLens.push_back(checkRMS_CR1);

	SequentialRayTracing SeqTraceFieldCR1(OptSysCR1);
	SeqTraceFieldCR1.seqRayTracingWithVectorOfLightRays(FillApStopFieldCR1.getVectorWithLightRays());
	Spot SpotDiaFiledCR1(SeqTraceFieldCR1.getAllInterPointsAtSurf_i_notFiltered(1), SeqTraceFieldCR1.getAllInterPointsAtSurf_i_notFiltered(1).at(0));
	real rmsFild_CR1 = SpotDiaFiledCR1.getRMS_µm();
	real RMS_Field_CR1_Z = 30.430;
	bool checkFieldRMS_CR1 = Math::compareTwoNumbers_decimals(rmsFild_CR1, RMS_Field_CR1_Z, 2);
	checkParaxialLens.push_back(checkFieldRMS_CR1);

	// *****************************************************************************************************************
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
	std::vector<VectorStructR3> allInterPoints5 = seqTrace5.getAllInterPointsAtSurf_i_notFiltered(1);

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
	std::vector<VectorStructR3> allInterPoints6 = seqTrace6.getAllInterPointsAtSurf_i_notFiltered(1);

	// get the reference points from Zemax
	std::vector<VectorStructR3> refInterPoints6 = { { -1.2188959553, 2.8811040447, 20.5 },{ -1.424842446, 1.4248424456, 20.5 },{ -1.5489916552, 0.54697496574, 20.5 },{ -1.4849242405, 1.0, 20.5 },{ -1.6095128272, 0.11902565449, 20.5 },{ -1.6890872965, -0.4436508139, 20.5 } };

	// compare trace open with Zemax data
	bool check3 = Math::compareAllVectorElements(allInterPoints6, refInterPoints6, 8);
	checkParaxialLens.push_back(check3);

	// *****************************************************************************************************************
	// *****************************************************************************************************************
	
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
	std::vector<VectorStructR3> allInterPoints9 = seqTrace9.getAllInterPointsAtSurf_i_notFiltered(1);

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
	std::vector<VectorStructR3> allInterPoints10 = seqTrace10.getAllInterPointsAtSurf_i_notFiltered(1);

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
	std::vector<VectorStructR3> allInterPoints11 = seqTrace11.getAllInterPointsAtSurf_i_notFiltered(1);

	// get the reference points from Zemax
	std::vector<VectorStructR3> refInterPoints11 = { { 2.1, 6.2, 20.5 },{ 2.1, -2.1, 20.5 },{ 2.1, -10.4, 20.5 },{ 2.1, 1.0, 20.5 },{ 2.1, -7.3, 20.5 },{ 2.1, -15.6, 20.5 } };

	// compare trace open with Zemax data
	bool check8 = Math::compareAllVectorElements(allInterPoints11, refInterPoints11, 8);
	checkParaxialLens.push_back(check8);

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
	std::vector<VectorStructR3> allInterPoints16 = seqTrace16.getAllInterPointsAtSurf_i_notFiltered(1);

	// get the reference points from Zemax
	std::vector<VectorStructR3> refInterPoints16 = { { 0.0, 1.38, 20.5 },{ 0.0, 0.0, 20.5 },{ 0.0, -1.38, 20.5 },{ 0.0, -0.6, 20.5 },{ 0.0, -1.98, 20.5 },{ 0.0, -3.36, 20.5 } };

	// compare trace open with Zemax data
	bool check13 = Math::compareAllVectorElements(allInterPoints16, refInterPoints16, 8);
	checkParaxialLens.push_back(check13);
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
	std::vector<VectorStructR3> allInterPoints20 = seqTrace20.getAllInterPointsAtSurf_i_notFiltered(1);

	// get the reference points from Zemax
	std::vector<VectorStructR3> refInterPoints20 = { { 0.0, 6.82, 20.5 },{ 0.0, 0.0, 20.5 },{ 0.0, -6.82, 20.5 },{ 0.0, 2.6, 20.5 },{ 0.0, -4.22, 20.5 },{ 0.0, -11.04, 20.5 } };

	// compare trace open with Zemax data

	bool check17 = Math::compareAllVectorElements(allInterPoints20, refInterPoints20, 8); 
	checkParaxialLens.push_back(check17);
	// *****************************************************************************************************************
	// *****************************************************************************************************************
	
	// *****************************************************************************************************************
	bool output = Math::checkTrueOfVectorElements(checkParaxialLens);
	// *****************************************************************************************************************

	return output;
}