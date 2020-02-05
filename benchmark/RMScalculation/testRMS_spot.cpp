#include "testRMS_Spot.h"
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"

#include "..\..\Analyse\Spot.h"
#include "..\..\FillAptertureStop\FillApertureStop.h"



testRMS_Spot::testRMS_Spot() {};
testRMS_Spot::~testRMS_Spot() {};

bool testRMS_Spot::checkRMScalculationSpot()
{

	RefractedRay_LLT refrac;
	std::vector<bool>  checkRMScalcSpot_vec;

	// first example
	JonesVector_LLT jones{ 1.0,1.0,1.0,1.0 };
	//dummy light
	Light_LLT light{ 550.0, 1.0,jones,typeLightRay,1 };

	// Startwert (0.0, 0.0, 0.0)
	Ray_LLT Ray1(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 50.0 }, 1.0);
	LightRayStruct lightRay1{ light,Ray1,1 };


	SphericalSurface_LLT S0E0(/*radius*/15.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 55.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S1E0(/*radius*/30.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 60.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.6, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S2E0(/*radius*/60.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 65.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	PlanGeometry_LLT S3E0(/*semi height*/ 5.0,/*point*/{ 0.0,0.0,95.0},/*direction*/{ 0.0,0.0,1.0 },/*refractive index A*/ 1.0, /*refractive index B*/ 1.0);

	// fill aperture stop
	FillApertureStop fillAperStopE0(/*start point rays*/{ 0.0,0.0,0.0 },/*semi height of aperture stop*/ 1.0,/*point of aperture stop*/{ 0.0,0.0,50.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/6,/*arms*/ 8,/*refractive index*/ 1.0, light);

	// build optical system
	OpticalSystem_LLT optSysE0;
	optSysE0.fillVectorSurfaceAndInteractingData(0, &S0E0, refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(1, &S1E0, refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(2, &S2E0, refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(3, &S3E0, refrac.clone());

	// single ray tracing
	SequentialRayTracing singleRayTracing(optSysE0);
	singleRayTracing.sequentialRayTracing(lightRay1);
	VectorStructR3 interP0 = singleRayTracing.getAllInterPointsAtSurf_i(0).at(0);
	VectorStructR3 interP1 = singleRayTracing.getAllInterPointsAtSurf_i(1).at(0);
	VectorStructR3 interP2 = singleRayTracing.getAllInterPointsAtSurf_i(2).at(0);
	VectorStructR3 interP3 = singleRayTracing.getAllInterPointsAtSurf_i(3).at(0);

	std::vector<VectorStructR3> checkerSingleRayTrace{ {0.0,1.1008,55.0404},{0.0,1.0454,59.98178},{0.0,1.0037,64.9916 },{0.0,0.3026,95.0} };
	std::vector<VectorStructR3> compareVector{ interP0, interP1,interP2,interP3 };
	bool testSingleRayTrace = Math::compareAllVectorElements(checkerSingleRayTrace, compareVector,3);
	checkRMScalcSpot_vec.push_back(testSingleRayTrace);


	// do sequential ray tracing
	SequentialRayTracing seqtrace(optSysE0);
	seqtrace.seqRayTracingWithVectorOfLightRays(fillAperStopE0.getVectorWithLightRays());
	Spot spot(seqtrace.getAllInterPointsAtSurf_i(3), seqtrace.getAllInterPointsAtSurf_i(3).at(0));
	real rmsE0 = spot.getRMS_mm();

	// calculate rms value of spot
	Spot spotE0(/*intersection points*/ seqtrace.getAllInterPointsAndIntensityAtSurface_i(3), /*reference point*/seqtrace.getAllInterPointsAtSurf_i(2).at(0));


	bool returnTestRMS_spot = Math::checkTrueOfVectorElements(checkRMScalcSpot_vec);
	return returnTestRMS_spot;
}