#include "testSequentialRayTracer.h"

// include interactions
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DeflectedRayParaxialLens_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ParaxialLens_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DeflectedRayParaxialLens_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"

// include surfaces
#include "..\..\LowLevelTracing/Surfaces\AsphericalSurface_LLT.h"
#include "..\..\LowLevelTracing/Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing/Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing/Surfaces\ParaxialLens_LLT.h"

// surface elements
#include "..\..\SurfaceElements\ApertureStopElement.h"
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\PlanElement.h"

// glasses
#include "..\..\Glasses\Glasses.h"

// often use
#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

#include "..\..\Analyse\Spot.h"
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\..\FillAptertureStop\FillApertureStop.h"

// typedef
typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;
// ***

testSequentialRayTracing::testSequentialRayTracing() {};
testSequentialRayTracing::~testSequentialRayTracing() {};

// check methodes of class Element
bool testSequentialRayTracing::checkSequentialRayTracing_superFct()
{
	std::vector<bool> workTheSystem;

	// E1
	bool checkE1 = checkSeqTrac_E1();
	workTheSystem.push_back(checkE1);
	// E2
	bool checkE2 = checkSeqTrac_E2();
	workTheSystem.push_back(checkE2);
	// E3
	bool checkE3 = checkSeqTrac_E3();
	workTheSystem.push_back(checkE3);
	// E4
	bool checkE4 = checkSeqTrac_E4();
	workTheSystem.push_back(checkE4);
	// E5
	bool checkE5 = checkSeqTrac_E5();
	workTheSystem.push_back(checkE5);
	// E6
	bool checkE6 = checkSeqTrac_E6();
	workTheSystem.push_back(checkE6);

	bool output = Math::checkTrueOfVectorElements(workTheSystem);
	return output;

}


// E1
bool testSequentialRayTracing::checkSeqTrac_E1()
{
	// DO sequential ray tracing
	RefractedRay_LLT refraction;
	Absorb_LLT absorb;
	Light_LLT Light;
	// *****************************************************************************************************************
	std::vector<bool> workTheSystem;
	// *****************************************************************************************************************

	// *****************************************************************************************************************
	// *****************************************************************************************************************
	//example 1
	// *****************************************************************************************************************
	SphericalSurface_LLT S1(/*radius*/9.0, /*semiHeight*/7.0, /*Apex of the sphere*/{ 0.0,0.0,15.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S2(/*radius*/9.0, /*semiHeight*/7.0, /*Apex of the sphere*/{ 0.0,0.0,22.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT P1(20.0, { 0.0,0.0,37.0 }, { 0.0,0.0,1.0 }, 1.0, 1.0);



	Ray_LLT Ray1(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,4.2902316034,16.088368513 }, 1.0);
	Ray_LLT Ray2(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,2.7427763586,15.428117019 }, 1.0);
	Ray_LLT Ray3(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,1.3422807391,15.100658316 }, 1.0);
	Ray_LLT Ray4(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,-1.3422807391,15.100658316 }, 1.0);
	Ray_LLT Ray5(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,-2.7427763586,15.428117019 }, 1.0);
	Ray_LLT Ray6(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,-4.2902316034,16.088368513 }, 1.0);

	LightRayStruct LightRay1;
	LightRayStruct LightRay2;
	LightRayStruct LightRay3;
	LightRayStruct LightRay4;
	LightRayStruct LightRay5;
	LightRayStruct LightRay6;

	LightRay1.setRay_LLT(Ray1);
	LightRay2.setRay_LLT(Ray2);
	LightRay3.setRay_LLT(Ray3);
	LightRay4.setRay_LLT(Ray4);
	LightRay5.setRay_LLT(Ray5);
	LightRay6.setRay_LLT(Ray6);


	OpticalSystem_LLT optSys1;
	optSys1.fillVectorSurfaceAndInteractingData(0, &S1, refraction.clone());
	optSys1.fillVectorSurfaceAndInteractingData(1, &S2, refraction.clone());
	optSys1.fillVectorSurfaceAndInteractingData(2, &P1, refraction.clone());

	SequentialRayTracing seqTrace1(optSys1);
	seqTrace1.sequentialRayTracing(LightRay1);
	seqTrace1.sequentialRayTracing(LightRay2);
	seqTrace1.sequentialRayTracing(LightRay3);
	seqTrace1.sequentialRayTracing(LightRay4);
	seqTrace1.sequentialRayTracing(LightRay5);
	seqTrace1.sequentialRayTracing(LightRay6);


	//Element.printAllIntersectInfosSRT();
	//Element.printAllIntersectionPoints();

	std::vector<VectorStructR3> checkResultSRT =
	{
		/*Ray1*/{0.0,4.2902316034,16.088368513 },{0.0,4.1874392392,20.966514459 },{ 0.0,-1.2712208903 ,37.0},
		/*Ray2*/{ 0.0,2.7427763586,15.428117019 } ,{ 0.0,2.7841284715,21.558541269 } ,{ 0.0,0.33685915457, 37.0},
		/*Ray3*/{ 0.0,1.3422807391,15.100658316 } ,{ 0.0,1.3990498812,21.890593874 } ,{ 0.0,0.39234010729,37.0 },
		/*Ray6*/{ 0.0,-1.3422807391,15.100658316 } ,{ 0.0,-1.3990498812,21.890593874 } ,{ 0.0,-0.39234010729,37.0 },
		/*Ray5*/ { 0.0,-2.7427763586,15.428117019 } ,{ 0.0,-2.7841284715,21.558541269 } ,{ 0.0,-0.33685915457, 37.0 },
		/*Ray4*/{ 0.0,-4.2902316034,16.088368513 },{ 0.0,-4.1874392392,20.966514459 },{ 0.0,1.2712208903 ,37.0 }
	};

	bool checkSRT1 = Math::compareAllVectorElementsSTDVectorStructR3_decimals(seqTrace1.getAllIntersectionPointsSRT(), checkResultSRT, 7);
	workTheSystem.push_back(checkSRT1);

	bool output = Math::checkTrueOfVectorElements(workTheSystem);
	return output;
}

// E2
bool testSequentialRayTracing::checkSeqTrac_E2()
{
	std::vector<bool> workTheSystem;
	RefractedRay_LLT refraction;

	//example 2
	// *****************************************************************************************************************

	ParaxialLens_LLT ParaxialLens_1(3.0, { 0.0,0.0,0.0 }, { 0.0,0.0,1.0 }, 10, 1.0, 1.0);
	DeflectedRayParaxialLens_LLT deflectionParaxial_1(ParaxialLens_1.getInfosForDefelction());

	ParaxialLens_LLT ParaxialLens_2(3.0, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, 10, 1.0, 1.0);
	DeflectedRayParaxialLens_LLT deflectionParaxial_2(ParaxialLens_2.getInfosForDefelction());

	ParaxialLens_LLT ParaxialLens_3(3.0, { 0.0,0.0,30.0 }, { 0.0,0.0,1.0 }, 10, 1.0, 1.0);
	DeflectedRayParaxialLens_LLT deflectionParaxial_3(ParaxialLens_3.getInfosForDefelction());

	ParaxialLens_LLT ParaxialLens_4(3.0, { 0.0,0.0,50.0 }, { 0.0,0.0,1.0 }, 10, 1.0, 1.0);
	DeflectedRayParaxialLens_LLT deflectionParaxial_4(ParaxialLens_4.getInfosForDefelction());
	PlanGeometry_LLT Plan(4.0, { 0.0,0.0,60.0 }, { 0.0,0.0,1.0 }, 1.0, 1.0);

	Ray_LLT Ray7(/*origin*/{ 0.0, 3.0, -1.0 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0);
	Ray_LLT Ray8(/*origin*/{ 0.0, 2.0, -1.0 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0);
	Ray_LLT Ray9(/*origin*/{ 0.0, 1.0, -1.0 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0);
	Ray_LLT Ray10(/*origin*/{ 0.0, 0.0, -1.0 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0);
	Ray_LLT Ray11(/*origin*/{ 0.0, -1.0, -1.0 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0);
	Ray_LLT Ray12(/*origin*/{ 0.0, -2.0, -1.0 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0);
	Ray_LLT Ray13(/*origin*/{ 0.0, -3.0, -1.0 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0);

	LightRayStruct LightRay7;
	LightRayStruct LightRay8;
	LightRayStruct LightRay9;
	LightRayStruct LightRay10;
	LightRayStruct LightRay11;
	LightRayStruct LightRay12;
	LightRayStruct LightRay13;

	LightRay7.setRay_LLT(Ray7);
	LightRay8.setRay_LLT(Ray8);
	LightRay9.setRay_LLT(Ray9);
	LightRay10.setRay_LLT(Ray10);
	LightRay11.setRay_LLT(Ray11);
	LightRay12.setRay_LLT(Ray12);
	LightRay13.setRay_LLT(Ray13);

	OpticalSystem_LLT OptSys2;
	OptSys2.fillVectorSurfaceAndInteractingData(0, &ParaxialLens_1, deflectionParaxial_1.clone());
	OptSys2.fillVectorSurfaceAndInteractingData(1, &ParaxialLens_2, deflectionParaxial_2.clone());
	OptSys2.fillVectorSurfaceAndInteractingData(2, &ParaxialLens_3, deflectionParaxial_3.clone());
	OptSys2.fillVectorSurfaceAndInteractingData(3, &ParaxialLens_4, deflectionParaxial_4.clone());
	OptSys2.fillVectorSurfaceAndInteractingData(4, &Plan, refraction.clone());

	SequentialRayTracing seqTrac2(OptSys2);

	seqTrac2.sequentialRayTracing(LightRay7);
	seqTrac2.sequentialRayTracing(LightRay8);
	seqTrac2.sequentialRayTracing(LightRay9);
	seqTrac2.sequentialRayTracing(LightRay10);
	seqTrac2.sequentialRayTracing(LightRay11);
	seqTrac2.sequentialRayTracing(LightRay12);
	seqTrac2.sequentialRayTracing(LightRay13);

	//	ElementExample2.printAllIntersectionPoints();

	std::vector<VectorStructR3> checkResultSRTParaxialSurface =
	{
		/*Ray7*/{ 0.0,3.0,0.0 },{ 0.0,-3.0,20.0 },{ 0.0,-3.0,30.0 },{ 0.0,3.0,50.0 },{ 0.0,3.0,60.0 },
		/*Ray8*/{ 0.0,2.0,0.0 },{ 0.0,-2.0,20.0 },{ 0.0,-2.0,30.0 },{ 0.0,2.0,50.0 },{ 0.0,2.0,60.0 },
		/*Ray9*/{ 0.0,1.0,0.0 },{ 0.0,-1.0,20.0 },{ 0.0,-1.0,30.0 },{ 0.0,1.0,50.0 },{ 0.0,1.0,60.0 },
		/*Ray10*/{ 0.0,0.0,0.0 },{ 0.0,0.0,20.0 },{ 0.0,0.0,30.0 },{ 0.0,0.0,50.0 },{ 0.0,0.0,60.0 },
		/*Ray11*/{ 0.0,-1.0,0.0 },{ 0.0,1.0,20.0 },{ 0.0,1.0,30.0 },{ 0.0,-1.0,50.0 },{ 0.0,-1.0,60.0 },
		/*Ray12*/{ 0.0,-2.0,0.0 },{ 0.0,2.0,20.0 },{ 0.0,2.0,30.0 },{ 0.0,-2.0,50.0 },{ 0.0,-2.0,60.0 },
		/*Ray13*/{ 0.0,-3.0,0.0 },{ 0.0,3.0,20.0 },{ 0.0,3.0,30.0 },{ 0.0,-3.0,50.0 },{ 0.0,-3.0,60.0 },
	};

	bool checkSRT2 = Math::compareAllVectorElementsSTDVectorStructR3_decimals(seqTrac2.getAllIntersectionPointsSRT(), checkResultSRTParaxialSurface, 10);
	workTheSystem.push_back(checkSRT2);

	bool output = Math::checkTrueOfVectorElements(workTheSystem);
	return output;
}
// E3
bool testSequentialRayTracing::checkSeqTrac_E3()
{
	//example 3
	// *****************************************************************************************************************
	std::vector<bool> workTheSystem;
	Light_LLT Light;
	RefractedRay_LLT refraction;
	Absorb_LLT absorb;

	// check aspherical surface with many rays

	// fill entrance pupil with many rays
	FillApertureStop FillEntPupilRay1(/*start point ray*/{ 0.0,0.0,0.0 }, /*semi height*/ 1.0, /*apex*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, Light);

	// aspherical surface
	AsphericalSurface_LLT AsphericalSurface(/*radius*/3.0, /*semiHeight*/3.0, /*Apex of the asphere*/{ 0.0,0.0,10.0 },
		/*Direction*/{ 0.0,0.0,1.0 }, /*refIndexSideA*/ 1.0, /*refIndexSideB*/1.5, /*Conic*/-0.5, /*term heigher order*/0.0001, 0.0001, -0.0001, -0.0001, 0.0000001, 0.0000001, 0.0000001, 0.0000001);

	// plan surface
	PlanGeometry_LLT PlanSurface1(/*semiHeight*/ 3.0, /*Apex*/{ 0.0,0.0,20.0 }, /*Direction*/{ 0.0,0.0,1.0 }, /*refIndexSideA*/  1.5,  /*refIndexSideB*/ 1.0);

	// plan surface
	PlanGeometry_LLT PlanSurface2(/*semiHeight*/ 3.0, /*Apex*/{ 0.0,0.0,25.0 }, /*Direction*/{ 0.0,0.0,1.0 }, /*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);

	// build the optical system
	OpticalSystem_LLT OptSys3;

	//________________


	// build the optical system
	OptSys3.fillTracingVectorSurfaces(0, AsphericalSurface.clone());
	OptSys3.fillTracingVectorSurfaces(1, PlanSurface1.clone());
	OptSys3.fillTracingVectorSurfaces(2, PlanSurface2.clone());

	// determine the intersection
	OptSys3.fillTracingVectorInteraction(0, refraction.clone());
	OptSys3.fillTracingVectorInteraction(1, refraction.clone());
	OptSys3.fillTracingVectorInteraction(2, absorb.clone());

	// trace all the rays
	SequentialRayTracing SeqTrac3(OptSys3);
	SeqTrac3.seqRayTracingWithVectorOfLightRays(FillEntPupilRay1.getVectorWithLightRays());

	// get all intersection points of surface 2
	std::vector<VectorStructR3> intersecPoints1 = SeqTrac3.getAllInterPointsAtSurf_i_notFiltered(2);

	// calculate RMS and Geo radius
	Spot ClassSpot(intersecPoints1, intersecPoints1.at(0)); // The ChiefRay Intersection point is always the first intersection point

	real RMSvalue1 = ClassSpot.getRMS_mm();
	real geoRadius1 = ClassSpot.getGeoRadius();

	//	std::cout << RMSvalue << std::endl;
	//	std::cout << geoRadius << std::endl;

	bool checkRMSvalue1 = Math::compareTwoNumbers_decimals(RMSvalue1, 0.249246, 6);
	workTheSystem.push_back(checkRMSvalue1);
	bool checkGeoRadius1 = Math::compareTwoNumbers_decimals(geoRadius1, 0.419460, 6);
	workTheSystem.push_back(checkGeoRadius1);
	// *****************************************************************************************************************
	// *****************************************************************************************************************

	bool output = Math::checkTrueOfVectorElements(workTheSystem);
	return output;
}
// E4
bool testSequentialRayTracing::checkSeqTrac_E4()
{
	RefractedRay_LLT refraction;
	Absorb_LLT absorb;
	Light_LLT Light;
	std::vector<bool> workTheSystem;

	//example 4
	// *****************************************************************************************************************

	// fill entrance pupil with many rays
	FillApertureStop FillEntPupilRayE4(/*start point ray*/{ 0.0,0.0,0.0 }, /*semi height*/ 1.0, /*apex*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, Light);

	// aspherical surface
	AsphericalSurface_LLT AsphericalSurface1E4(/*radius*/5.0, /*semiHeight*/3.0, /*Apex of the asphere*/{ 0.0,0.0,10.0 },
		/*Direction*/{ 0.0,0.0,1.0 }, /*refIndexSideA*/ 1.0, /*refIndexSideB*/1.5, /*Conic*/0.5, /*term heigher order*/-0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);

	// aspherical surface
	AsphericalSurface_LLT AsphericalSurface2E4(/*radius*/5.0, /*semiHeight*/3.0, /*Apex of the asphere*/{ 0.0,0.0,15.0 },
		/*Direction*/{ 0.0,0.0,-1.0 }, /*refIndexSideA*/ 1.0, /*refIndexSideB*/1.5, /*Conic*/0.5, /*term heigher order*/0.001, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);

	// plan surface
	PlanGeometry_LLT PlanSurfaceE4(/*semiHeight*/ 3.0, /*Apex*/{ 0.0,0.0,22.0 }, /*Direction*/{ 0.0,0.0,1.0 }, /*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);

	// build the optical system
	OpticalSystem_LLT OptSys4;




	// build the optical system
	OptSys4.fillTracingVectorSurfaces(0, AsphericalSurface1E4.clone());
	OptSys4.fillTracingVectorSurfaces(1, AsphericalSurface2E4.clone());
	OptSys4.fillTracingVectorSurfaces(2, PlanSurfaceE4.clone());

	// determine the intersection
	OptSys4.fillTracingVectorInteraction(0, refraction.clone());
	OptSys4.fillTracingVectorInteraction(1, refraction.clone());
	OptSys4.fillTracingVectorInteraction(2, absorb.clone());

	// trace all the rays+
	SequentialRayTracing SeqTrac4(OptSys4);
	SeqTrac4.seqRayTracingWithVectorOfLightRays(FillEntPupilRayE4.getVectorWithLightRays());

	// get all intersection points of surface 5
	std::vector<VectorStructR3> intersecPointsE4 = SeqTrac4.getAllInterPointsAtSurf_i_notFiltered(2);

	// calculate RMS and Geo radius
	Spot ClassSpotE4(intersecPointsE4, intersecPointsE4.at(0)); // The ChiefRay Intersection point is always the first intersection point

	real RMSvalueE4 = ClassSpotE4.getRMS_mm();
	real geoRadiusE4 = ClassSpotE4.getGeoRadius();

	bool checkRMSvalueE4 = Math::compareTwoNumbers_decimals(RMSvalueE4, 0.183559, 6);
	workTheSystem.push_back(checkRMSvalueE4);
	bool checkGeoRadiusE4 = Math::compareTwoNumbers_decimals(geoRadiusE4, 0.241762, 6);
	workTheSystem.push_back(checkGeoRadiusE4);


	bool output = Math::checkTrueOfVectorElements(workTheSystem);
	return output;
}
// E5
bool testSequentialRayTracing::checkSeqTrac_E5()
{
	RefractedRay_LLT refraction;
	Absorb_LLT absorb;
	Light_LLT Light;
	std::vector<bool> workTheSystem;

	//example 5
	// *****************************************************************************************************************

	OpticalSystem_LLT OptSys5;
	Spot SpotValue;
	DeflectedRayParaxialLens_LLT deflectRay;

	// test system

	// fill entrance pupil with many rays
	FillApertureStop FillEntPupilRay1E5(/*start point ray*/{ 0.0,0.1,0.0 }, /*semi height*/ 1.0, /*apex*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, Light);

	// 1 surface
	SphericalSurface_LLT SphericalSurface1E5(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,10.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);

	// 2 surface
	SphericalSurface_LLT SphericalSurface2E5(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,15.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);

	// 3 surface
	AsphericalSurface_LLT AsphericalSurface1E5(/*radius*/10.0, /*semiHeight*/2.5, /*Apex of the asphere*/{ 0.0,0.0,20.0 },
		/*Direction*/{ 0.0,0.0,1.0 }, /*refIndexSideA*/ 1.0, /*refIndexSideB*/1.5, /*Conic*/0.5, /*term heigher order*/0.001, 0.001, -0.001, 0.0000001, 0.0000001, 0.0000001, -0.0000001, 0.0000001);

	// 4 surface
	AsphericalSurface_LLT AsphericalSurface2E5(/*radius*/10.0, /*semiHeight*/2.5, /*Apex of the asphere*/{ 0.0,0.0,25.0 },
		/*Direction*/{ 0.0,0.0,-1.0 }, /*refIndexSideA*/ 1.0, /*refIndexSideB*/1.5, /*Conic*/-0.5, /*term heigher order*/0.001, 0.001, -0.001, 0.0000001, 0.0000001, 0.0000001, -0.0000001, 0.0000001);

	// 5 surface
	ParaxialLens_LLT ParaxialLensE5(/*semiHeight*/ 4.0, /*Apex*/{ 0.0,0.0,30.0 }, /*Direction*/{ 0.0,0.0,1.0 }, /*focallength*/ 100, /*refIndexSideA*/ 1.0, /*refIndexSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflectionParaxialLensE5(ParaxialLensE5.getInfosForDefelction());

	// 6 surface
	PlanGeometry_LLT PlanSurfaceE5(/*semiHeight*/ 4.0, /*Apex*/{ 0.0,0.0,35.0 }, /*Direction*/{ 0.0,0.0,1.0 }, /*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);



	// build the optical system
	OptSys5.fillTracingVectorSurfaces(0, SphericalSurface1E5.clone());
	OptSys5.fillTracingVectorSurfaces(1, SphericalSurface2E5.clone());
	OptSys5.fillTracingVectorSurfaces(2, AsphericalSurface1E5.clone());
	OptSys5.fillTracingVectorSurfaces(3, AsphericalSurface2E5.clone());
	OptSys5.fillTracingVectorSurfaces(4, ParaxialLensE5.clone());
	OptSys5.fillTracingVectorSurfaces(5, PlanSurfaceE5.clone());

	// determine the intersection
	OptSys5.fillTracingVectorInteraction(0, refraction.clone());
	OptSys5.fillTracingVectorInteraction(1, refraction.clone());
	OptSys5.fillTracingVectorInteraction(2, refraction.clone());
	OptSys5.fillTracingVectorInteraction(3, refraction.clone());
	OptSys5.fillTracingVectorInteraction(4, deflectionParaxialLensE5.clone());
	OptSys5.fillTracingVectorInteraction(5, absorb.clone());

	// trace all the rays
	SequentialRayTracing SeqTrac5(OptSys5);
	SeqTrac5.seqRayTracingWithVectorOfLightRays(FillEntPupilRay1E5.getVectorWithLightRays());


	// get all intersection points of surface 5
	std::vector<VectorStructR3> intersecPoints1E5 = SeqTrac5.getAllInterPointsAtSurf_i_notFiltered(5);

	// calculate RMS and Geo radius
	Spot ClassSpotE5(intersecPoints1E5, intersecPoints1E5.at(0)); // The ChiefRay Intersection point is always the first intersection point

	real RMSvalueE5 = ClassSpotE5.getRMS_mm();
	real geoRadiusE5 = ClassSpotE5.getGeoRadius();

	bool checkRMSvalueE5 = Math::compareTwoNumbers_decimals(RMSvalueE5, 0.533412, 6);
	workTheSystem.push_back(checkRMSvalueE5);
	bool checkGeoRadiusE5 = Math::compareTwoNumbers_decimals(geoRadiusE5, 1.57639, 5);
	workTheSystem.push_back(checkGeoRadiusE5);

	//******************************************************************************************************************
	//******************************************************************************************************************
	// distances paraxial lenses

	// check with paraxial lens!
	ParaxialLens_LLT ParaxialLens_0D(/*semi Height*/ 7.0, /*apex*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*focallength*/ 45.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflectP0(ParaxialLens_0D.getInfosForDefelction());
	ParaxialLens_LLT ParaxialLens_1D(/*semi Height*/ 7.0, /*apex*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*focallength*/ 20.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflectP1(ParaxialLens_1D.getInfosForDefelction());
	PlanGeometry_LLT PlanPara1D(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,66.15942025 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	SphericalSurface_LLT S_ExitPupilD(/*radius*/17.8881988, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 84.04761905 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);


	// build opitcal system
	OpticalSystem_LLT OptSys1Para;
	DoNothingInteraction_LLT doNothing;


	OptSys1Para.fillVectorSurfaceAndInteractingData(0, &ParaxialLens_0D, deflectP0.clone());
	OptSys1Para.fillVectorSurfaceAndInteractingData(1, &ParaxialLens_1D, deflectP1.clone());
	OptSys1Para.fillVectorSurfaceAndInteractingData(2, &PlanPara1D, doNothing.clone());
	OptSys1Para.fillVectorSurfaceAndInteractingData(3, &S_ExitPupilD, doNothing.clone());

	SequentialRayTracing SeqTraceParaxialMarg(OptSys1Para);
	SequentialRayTracing SeqTraceParaxialOptAch(OptSys1Para);
	// marginal ray -> y=1
	Ray_LLT RayMarg1(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 1.0, 20.0 }, 1.0);
	// Optical axis ray -> y=0
	Ray_LLT RayOptAch(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 20.0 }, 1.0);
	LightRayStruct LightRayMarg1 = { Light, RayMarg1, 1 };
	LightRayStruct LightRayOptAch = { Light, RayOptAch, 1 };
	SeqTraceParaxialMarg.sequentialRayTracing(LightRayMarg1);
	SeqTraceParaxialOptAch.sequentialRayTracing(LightRayOptAch);

	// marginal ray -> y=1
	real distance0 = SeqTraceParaxialMarg.getInterInf_PosSurface_TotalSteps_ofSur_i(0).at(0).getIntersecInfos().getStepsToWalk();
	real checkDis0 = 40.04996879;
	bool compDis0 = Math::compareTwoNumbers_decimals(distance0, checkDis0, 8); //8
	real distance1 = SeqTraceParaxialMarg.getInterInf_PosSurface_TotalSteps_ofSur_i(1).at(0).getIntersecInfos().getStepsToWalk();
	real checkDis1 = 5.00007715990;
	bool compDis1 = Math::compareTwoNumbers_decimals(distance1, checkDis1, 8); //8
	real distance2 = SeqTraceParaxialMarg.getInterInf_PosSurface_TotalSteps_ofSur_i(2).at(0).getIntersecInfos().getStepsToWalk();
	real checkDis2 = 21.25636257;
	bool compDis2 = Math::compareTwoNumbers_decimals(distance2, checkDis2, 6); //6
	real distance3 = SeqTraceParaxialMarg.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(0).getIntersecInfos().getStepsToWalk();
	real checkDis3 = 17.8881988;
	bool compDis3 = Math::compareTwoNumbers_decimals(distance3, checkDis3, 8); //6
	real sumDisMargY1 = distance0 + distance1 + distance2 + distance3;
	real checkSumY1 = 84.19460731990;
	bool compSum = Math::compareTwoNumbers_decimals(sumDisMargY1, checkSumY1, 7); //7
	workTheSystem.push_back(compSum);
	// opt achs ray -> y=0
	real distance0OA = SeqTraceParaxialOptAch.getInterInf_PosSurface_TotalSteps_ofSur_i(0).at(0).getIntersecInfos().getStepsToWalk();
	real checkDis0OA = 40.0;
	bool compDis0OA = Math::compareTwoNumbers_decimals(distance0OA, checkDis0OA, 8); //8
	real distance1OA = SeqTraceParaxialOptAch.getInterInf_PosSurface_TotalSteps_ofSur_i(1).at(0).getIntersecInfos().getStepsToWalk();
	real checkDis1OA = 5.0;
	bool compDis1OA = Math::compareTwoNumbers_decimals(distance1OA, checkDis1OA, 8); //8
	real distance2OA = SeqTraceParaxialOptAch.getInterInf_PosSurface_TotalSteps_ofSur_i(2).at(0).getIntersecInfos().getStepsToWalk();
	real checkDis2OA = 21.15942029;
	bool compDis2OA = Math::compareTwoNumbers_decimals(distance2OA, checkDis2OA, 6); //6
	real distance3OA = SeqTraceParaxialOptAch.getInterInf_PosSurface_TotalSteps_ofSur_i(3).at(0).getIntersecInfos().getStepsToWalk();
	real checkDis3OA = 17.8881987580;
	bool compDis3OA = Math::compareTwoNumbers_decimals(distance3OA, checkDis3OA, 7); //7
	real sumDisMargY1OA = distance0OA + distance1OA + distance2OA + distance3OA;
	real checkSumOA = 84.047619048;
	bool compSumOA = Math::compareTwoNumbers_decimals(sumDisMargY1OA, checkSumOA, 6); //6
	workTheSystem.push_back(compSumOA);

	bool output = Math::checkTrueOfVectorElements(workTheSystem);
	return output;
}

// E6
bool testSequentialRayTracing::checkSeqTrac_E6()
{
	//example 6
	// *****************************************************************************************************************

	//*** standard ***//
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	
	RefractedRay_LLT refraction;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	std::vector<bool> workTheSystem;

	glass glasses;
	glasses.loadGlassCatalog_Schott();
		

	Light_LLT light = oftenUse::getDefaultLight();
	//*** ------  ***//

	// test system
	// build the optical system
	ApertureStopElement S0(/* semi height*/1.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S1(/*radius*/ 2.75, /*semi height*/ 1.5, /*point*/{ 0.0,0.0,1.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement S2(/*radius*/ 1.85, /*semi height*/ 1.5, /*point*/{ 0.0,0.0,1.0 + 1.645 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSF56_S1(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement S3(/*radius*/ 5.848, /*semi height*/ 1.5, /*point*/{ 0.0,0.0,1.0 + 1.645 + 0.75 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF56_S1());
	PlanElement S4(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,15.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr };
	std::vector<interaction_ptr> interactions_ptr{ doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSysEle(opticalSystem_ptr, interactions_ptr);

	// test the system
	real rms_Zemax = 1721.08;
	real wavelength = 550.0;
	real tolerance_forNSF6 = 1.0;
	bool testStart = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle, 0.0, 0.0, wavelength, rms_Zemax, tolerance_forNSF6, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testStart);

	oftenUse::print(optSysEle, 550.0);

	bool output = Math::checkTrueOfVectorElements(workTheSystem);
	return output;

}