#include "BenchmarkApertureStop.h"
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"
#include "..\..\SequentialRayTracer.h"
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\Interaction\ReflectionRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\FillApertureStop.h"

bool BenchmarkApertureStop::checkApertureStop()
{
	RefractedRay_LLT refrac;
	OpticalSystem_LLT optSys;
	ReflectionRay_LLT reflect;
	DoNothingInteraction_LLT doNothing;
	

	SphericalSurface_LLT S0(/*radius*/9.0, /*semiHeight*/5, /*Apex of the sphere*/{ 0.0, 0.0, 50.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S1(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	ApertureStop_LLT S2(2, { 0.0,0.0,60.0 }, { 0.0,0.0,1.0 }, 1.0);
	PlanGeometry_LLT S3(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);

	optSys.fillVectorSurfaceAndInteractingData(0, &S0, &refrac);
	optSys.fillVectorSurfaceAndInteractingData(1, &S1, &refrac);
	optSys.fillVectorSurfaceAndInteractingData(2, &S2, &doNothing);
	optSys.fillVectorSurfaceAndInteractingData(3, &S3, &doNothing);

	SequentialRayTracing seqTrace0(optSys);
	Ray_LLT Ray0(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,2.4,50.0 }, /*wavelenght*/550.0, 1.0);
	Light_LLT Light;
	LightRayStruct LightRay0(Ray0, Light, 1);

	seqTrace0.sequentialRayTracing(LightRay0);

	IntersectInformationStruct interInfos0 = seqTrace0.getAllInterInfosOfSurf_i(0).at(0);
	IntersectInformationStruct interInfos1 = seqTrace0.getAllInterInfosOfSurf_i(1).at(0);
	IntersectInformationStruct interInfos2 = seqTrace0.getAllInterInfosOfSurf_i(2).at(0);
	IntersectInformationStruct interInfos3 = seqTrace0.getAllInterInfosOfSurf_i(3).at(0);

	SequentialRayTracing seqTrace1(optSys);
	Ray_LLT Ray1(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,4.0,50.0 }, /*wavelenght*/550.0, 1.0);
	LightRayStruct LightRay1(Ray1, Light, 1);

	seqTrace1.sequentialRayTracing(LightRay1);

	IntersectInformationStruct interInfos0_1 = seqTrace1.getAllInterInfosOfSurf_i(0).at(0);
	IntersectInformationStruct interInfos1_1 = seqTrace1.getAllInterInfosOfSurf_i(1).at(0);
	IntersectInformationStruct interInfos2_1 = seqTrace1.getAllInterInfosOfSurf_i_notFiltered(2).at(0);
	IntersectInformationStruct interInfos3_1 = seqTrace1.getAllInterInfosOfSurf_i_notFiltered(3).at(0);



	return true;
}