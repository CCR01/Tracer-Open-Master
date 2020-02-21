#include "BenchmarkExitPupilCalculation.h"
#include "..\..\LowLevelTracing\Math_LLT.h"
#include <vector>
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\..\FillAptertureStop\FillApertureStop.h"
#include "..\..\Analyse\Spot.h"
#include "..\..\Analyse\CardinalPoints.h"


bool BenchExitPupilCalc::checkMethodesExitPupilCalculation()

{
	std::vector<bool> checkExpPupCalc;
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	Light.setWavelength(550.0);

	//*************
	FillApertureStop FillEntPupilRayE0(/*start point ray*/{ 0.0,0.0,0.0 }, /*semi height*/ 1.0, /*apex*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, Light);
	//*************
	// define the surfaces
	ApertureStop_LLT ApertureStop0E0(1.0, { 0.0,0.0,30.0 }, { 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT SphericalSurface1E0(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,35.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT SphericalSurface2E0(/*radius*/30.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,40.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT SphericalSurface3E0(/*radius*/50.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,45.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	SphericalSurface_LLT SphericalSurface4E0(/*radius*/15.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,50.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	PlanGeometry_LLT Plan5E0(/*semi Height*/ 1.0, /*apex*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0, 1.0);
	//*************
	// build the optical system
	OpticalSystem_LLT optSysE0;
	optSysE0.fillVectorSurfaceAndInteractingData(0, ApertureStop0E0.clone(), doNothing.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(1, SphericalSurface1E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(2, SphericalSurface2E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(3, SphericalSurface3E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(4, SphericalSurface4E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(5, Plan5E0.clone(), absorb.clone());
	//*************
	// single ray tracing
	Ray_LLT Ray0(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,1.0,30.0 }, 1.0);

	LightRayStruct LightRay0(Light, Ray0, 1);
	SequentialRayTracing seqTraceOne(optSysE0);
	seqTraceOne.sequentialRayTracing(LightRay0);

	VectorStructR3 vecImage0 = seqTraceOne.getAllInterPointsAtSurf_i(0).at(0);
	VectorStructR3 vecImage1 = seqTraceOne.getAllInterPointsAtSurf_i(1).at(0);
	VectorStructR3 vecImage2 = seqTraceOne.getAllInterPointsAtSurf_i(2).at(0);
	VectorStructR3 vecImage3 = seqTraceOne.getAllInterPointsAtSurf_i(3).at(0);
	VectorStructR3 vecImage4 = seqTraceOne.getAllInterPointsAtSurf_i(4).at(0);
	VectorStructR3 vecImage5 = seqTraceOne.getAllInterPointsAtSurf_i(5).at(0);
	//*************
	//do sequential ray tracing
	SequentialRayTracing seqTrac(optSysE0);
	seqTrac.seqRayTracingWithVectorOfLightRays(FillEntPupilRayE0.getVectorWithLightRays());
	//*************
	// check the optical system
	Spot spotE0(seqTrac.getAllInterPointsAtSurf_i(5), seqTrac.getAllInterPointsAtSurf_i(5).at(0));
	real rmsValue = spotE0.getRMS_mm();
	real geoRadois = spotE0.getGeoRadius();
	//*************
	CardinalPoints calcExitPupilE0(optSysE0);
	std::vector<real> posSurAfterStopE0 = calcExitPupilE0.getPosSurAfterStop();
	std::vector<real> realPosSurAfterStopE0{ 35,40,45,50 };
	bool checkPosSurAfterStopE0 = Math::compareTwoSTDVecors(posSurAfterStopE0, realPosSurAfterStopE0, 8);
	checkExpPupCalc.push_back(checkPosSurAfterStopE0);
	std::vector<real> focalLengthes = calcExitPupilE0.getFocalLengthAfterStop();
	std::vector<real> realFocalLengthes{ 30.0,60.0,133.333333333333,25.0 };
	bool checkFocalLengthes = Math::compareTwoSTDVecors(focalLengthes, realFocalLengthes, 5);
	checkExpPupCalc.push_back(checkFocalLengthes);
	std::vector<real> refractiveIndexes = calcExitPupilE0.getRefractivIndexesAfterStop();
	std::vector<real> realRefIndex{ 1.5,1.0,1.6,1.0 };
	bool checkRefIndex = Math::compareTwoSTDVecors(refractiveIndexes, realRefIndex, 5);
	checkExpPupCalc.push_back(checkRefIndex);
	real diameterApertureStop = calcExitPupilE0.getDiameterAperture();
	real realDimApertStop = 2.0;
	bool checkAperStopDia = Math::compareTwoNumbers_decimals(diameterApertureStop, realDimApertStop, 5);
	checkExpPupCalc.push_back(checkAperStopDia);

	//*************
	//OpticalSystem_LLT optSysE1;
	//optSysE1.fillVectorSurfaceAndInteractingData(0, &SphericalSurface1E0, refrac.clone());
	//optSysE1.fillVectorSurfaceAndInteractingData(1, &SphericalSurface2E0, refrac.clone());
	//optSysE1.fillVectorSurfaceAndInteractingData(2, &ApertureStop0E0, doNothing.clone());
	//optSysE1.fillVectorSurfaceAndInteractingData(3, &SphericalSurface3E0, refrac.clone());
	//optSysE1.fillVectorSurfaceAndInteractingData(4, &SphericalSurface4E0, refrac.clone());
	//optSysE1.fillVectorSurfaceAndInteractingData(5, &Plan5E0, absorb.clone());
	//CardinalPoints calcExitPupilE1(optSysE1);
	//std::vector<real> posSurAfterStopE1 = calcExitPupilE1.calcPosSurAfterStop();
	//std::vector<real> realPosSurAfterStopE1{45,50 };
	//bool checkPosSurAfterStopE1 = Math::compareTwoSTDVecors(posSurAfterStopE1, realPosSurAfterStopE1, 8);
	//checkExpPupCalc.push_back(checkPosSurAfterStopE1);
	////*************



	//*************
	bool returnCheck = Math::checkTrueOfVectorElements(checkExpPupCalc);
	return returnCheck;
}