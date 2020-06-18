#include "testApertureStop.h"
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\Interaction\ReflectionRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"

#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

bool testApertureStop::checkApertureStop()
{
	std::vector<bool> workTheApertureStop;
	real tolerance = 0.01;

	RefractedRay_LLT refrac;
	OpticalSystem_LLT optSys;
	ReflectionRay_LLT reflect;
	DoNothingInteraction_LLT doNothing;
	

	SphericalSurface_LLT S0(/*radius*/9.0, /*semiHeight*/5, /*Apex of the sphere*/{ 0.0, 0.0, 50.0 },/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S1(/*semiHeight*/5.0, /*point*/ { 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	ApertureStop_LLT S2(/*semiHeight*/2.0, /*point*/ { 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ 1.0);
	PlanGeometry_LLT S3(/*semiHeight*/5.0, /*point*/ { 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	// set tolerance to absorb light;
	S2.setTolerance(0.01);

	optSys.fillVectorSurfaceAndInteractingData(0, S0.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(1, S1.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(2, S2.clone(), doNothing.clone());
	optSys.fillVectorSurfaceAndInteractingData(3, S3.clone(), doNothing.clone());

	SequentialRayTracing seqTrace0(optSys);
	Ray_LLT Ray0(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,2.86879,50.4694642 }, 1.0);
	Light_LLT Light{};
	Light.buildDefaultLight();
	LightRayStruct LightRay0(Light, Ray0, 1);

	seqTrace0.sequentialRayTracing(LightRay0);


	IntersectInformationStruct interInfos0 = seqTrace0.getAllInterInfosOfSurf_i(0).at(0);
	IntersectInformationStruct controlIntersectInfos0({ 0.0,2.86879,50.4694642 }, { 0.0,0.3187545109,-0.9478373076 }, A, 50.550932526349, 1.0, 1.5, { 0.0,0.0567504981,0.9983883918 }, Light);
	workTheApertureStop.push_back(oftenUse::checkIntersectInfos(interInfos0, controlIntersectInfos0, tolerance));

	IntersectInformationStruct interInfos1 = seqTrace0.getAllInterInfosOfSurf_i(1).at(0);
	IntersectInformationStruct controlIntersectInfos1({ 0.0,2.5339262584,55.0 }, { 0.0,0.0,-1.0 }, A, 6.81434142, 1.5, 1.0, { 0.0,-0.0737116735,0.9972795943 }, Light);
	workTheApertureStop.push_back(oftenUse::checkIntersectInfos(interInfos1, controlIntersectInfos1, tolerance));

	IntersectInformationStruct interInfos2 = seqTrace0.getAllInterInfosOfSurf_i(2).at(0);
	IntersectInformationStruct controlIntersectInfos2({ 0.0,1.9776781366,60.0 }, { 0.0,0.0,-1.0 }, A, 5.030846049, 1.0, 1.0, { 0.0,-0.1105675102,0.9938686159 }, Light);
	workTheApertureStop.push_back(oftenUse::checkIntersectInfos(interInfos2, controlIntersectInfos2, tolerance));

	IntersectInformationStruct interInfos3 = seqTrace0.getAllInterInfosOfSurf_i(3).at(0);
	IntersectInformationStruct controlIntersectInfos3({ 0.0,0.30893377129,75.0 }, { 0.0,0.0,-1.0 }, A, 15.092538148, 1.0, 1.0, { 0.0,-0.1105675102,0.9938686159 }, Light);
	workTheApertureStop.push_back(oftenUse::checkIntersectInfos(interInfos3, controlIntersectInfos3, tolerance));

	SequentialRayTracing seqTrace1(optSys);
	Ray_LLT Ray1(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,4.0,50.0 }, 1.0);
	LightRayStruct LightRay1(Light, Ray1, 1);

	seqTrace1.sequentialRayTracing(LightRay1);

	IntersectInformationStruct interInfos0_1 = seqTrace1.getAllInterInfosOfSurf_i(0).at(0);
	IntersectInformationStruct controlIntersectInfos0_1({ 0.0,4.0781595738,50.976994672 }, { 0.0,0.4531288415,-0.8914450364 }, A, 51.13986088, 1.0, 1.5, { 0.0,0.0797452223,0.996815278 }, Light);
	workTheApertureStop.push_back(oftenUse::checkIntersectInfos(interInfos0_1, controlIntersectInfos0_1, tolerance));

	IntersectInformationStruct interInfos1_1 = seqTrace1.getAllInterInfosOfSurf_i(1).at(0);
	IntersectInformationStruct controlIntersectInfos1_1({ 0.0,3.616380093,55.0 }, { 0.0,0.0,-1.0 }, A, 6.074131819, 1.5, 1.0, { 0.0,-0.1140359218,0.9934766271 }, Light);
	workTheApertureStop.push_back(oftenUse::checkIntersectInfos(interInfos1_1, controlIntersectInfos1_1, tolerance));

	IntersectInformationStruct interInfos2_1 = seqTrace1.getAllInterInfosOfSurf_i_notFiltered(2).at(0);
	workTheApertureStop.push_back(interInfos2_1.getSurfaceSide() == N);

	IntersectInformationStruct interInfos3_1 = seqTrace1.getAllInterInfosOfSurf_i_notFiltered(3).at(0);
	workTheApertureStop.push_back(interInfos3_1.getSurfaceSide() == N);



	bool check = Math::checkTrueOfVectorElements(workTheApertureStop);
	return check;
}