#include "BenchmarkOpticalSystem.h"
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"

bool BenchmarkOpticalSystem::checkMethodesOpticalSystem()
{

	std::vector<bool> checkOpticalSystem;

	RefractedRay_LLT refrac;
	Light_LLT Light;
	Light.setWavelength(550.0);
	
	Ray_LLT Ray1(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 20.0 }, 1.0);
	Ray_LLT Ray2(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.5, 20.0 }, 1.0);
	Ray_LLT Ray3(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 20.0 }, 1.0);
	Ray_LLT Ray4(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -0.5, 20.0}, 1.0);
	Ray_LLT Ray5(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, -1.0, 20.0}, 1.0);

	//*****************************************************
	

	LightRayStruct LightRay1 = { Light, Ray1,  1 };
	LightRayStruct LightRay2 = { Light, Ray2,  1 };
	LightRayStruct LightRay3 = { Light, Ray3,  1 };
	LightRayStruct LightRay4 = { Light, Ray4,  1 };
	LightRayStruct LightRay5 = { Light, Ray5,  1 };

	std::vector<LightRayStruct> VecLightRay{ LightRay1,LightRay2,LightRay3,LightRay4, LightRay5 };

	SphericalSurface_LLT S0(/*radius*/15.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 40.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S1(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 45.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT Plan0(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,61.45456863 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	// build opitcal system
	OpticalSystem_LLT OptSys1;
	OptSys1.fillVectorSurfaceAndInteractingData(0, &S0, refrac.clone());
	OptSys1.fillVectorSurfaceAndInteractingData(1, &S1, refrac.clone());
	OptSys1.fillVectorSurfaceAndInteractingData(2, &Plan0, refrac.clone());

	unsigned int numnerOfSurfaces = OptSys1.getNumberOfSurfaces();
	bool checkNumSurfaces = numnerOfSurfaces == 2;
	checkOpticalSystem.push_back(checkNumSurfaces);

	// do sequential raytracing
	SequentialRayTracing SeqTrac1(OptSys1);
	SeqTrac1.seqRayTracingWithVectorOfLightRays(VecLightRay);

	std::vector<VectorStructR3> allInterPoints1 = SeqTrac1.getAllInterPointsAtSurf_i_notFiltered(2);

	// Surface and interaction to fill on
	SphericalSurface_LLT S_fillIn(/*radius*/12.776143019852, /*semiHeight*/1.39, /*Apex of the sphere*/{ 0.0,0.0,28.6784256101 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
	OptSys1.fillInSurfaceAndInteracAtPos_i(2, S_fillIn.clone(), refrac.clone());

	// do sequential raytracing
	SequentialRayTracing SeqTrac2(OptSys1);
	SeqTrac2.seqRayTracingWithVectorOfLightRays(VecLightRay);

	std::vector<VectorStructR3> allInterPoints2 = SeqTrac2.getAllInterPointsAtSurf_i_notFiltered(3);
	bool check1 = Math::compareAllVectorElements(allInterPoints1, allInterPoints2, 8);
	checkOpticalSystem.push_back(check1);


	// *****************************************************************************************************************
	bool output = Math::checkTrueOfVectorElements(checkOpticalSystem);
	// *****************************************************************************************************************

	return output;
}