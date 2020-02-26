#include "BenchmarkRayAiming.h"
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\\Surfaces\PlanGeometry_LLT.h"
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\..\RayAiming\RayAiming.h"
#include "..\..\LowLevelTracing\Interaction\ReflectionRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Light_LLT.h"
#include "..\..\LowLevelTracing\Interaction\InteractionRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
// glass catalogue
#include "..\..\Glasses\Glasses.h"
#include "..\..\FillAptertureStop\FillApertureStop.h"

#include "..\..\Analyse\Spot.h"

#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

// Für timer, später löschen:
#include <iostream>
#include <cstdio>
#include <ctime>

lightRay_interPoint_onTarget::lightRay_interPoint_onTarget() {};
lightRay_interPoint_onTarget::lightRay_interPoint_onTarget(/*light ray*/ LightRayStruct lightRay, /*intersection point*/ VectorStructR3 interPoint, /*on target*/ bool onTarger) :
	mLightRay(lightRay),
	mInterPoint(interPoint),
	mOnTarget(onTarger)
{}

// light ray
LightRayStruct lightRay_interPoint_onTarget::getLightRay()
{
	return mLightRay;
}
void lightRay_interPoint_onTarget::setLightRay(LightRayStruct lightRay)
{
	mLightRay = lightRay;
}

// intersection point
VectorStructR3 lightRay_interPoint_onTarget::getIntersectionPoint()
{
	return mInterPoint;
}
void lightRay_interPoint_onTarget::setIntersectionPoint(VectorStructR3 interPoint)
{
	mInterPoint = interPoint;
}

// on target
bool lightRay_interPoint_onTarget::getOnTarget()
{
	return mOnTarget;
}
void lightRay_interPoint_onTarget::setOnTarget(bool onTarget)
{
	mOnTarget = onTarget;
}

bool BenchmarkRayAiming::checkRayAimingSuperFct()
{
	std::vector<bool> checkRayAiming_SuperFct;
	// E0 inf
	bool checkE0 = checkRayAimingE0_inf();
	checkRayAiming_SuperFct.push_back(checkE0);
	// E1 inf
	bool checkE1 = checkRayAimingE1_inf();
	checkRayAiming_SuperFct.push_back(checkE1);
	// E2 inf
	bool checkE2 = checkRayAimingE2_inf();
	checkRayAiming_SuperFct.push_back(checkE2);
	// E3 inf (aperture stop is first surface
	bool checkE3 = checkRayAimingE3_inf();
	checkRayAiming_SuperFct.push_back(checkE3);
	// E4
	bool checkE4 = checkRayAimingE4_inf();
	checkRayAiming_SuperFct.push_back(checkE4);

	bool returnCheckSuperFct = Math::checkTrueOfVectorElements(checkRayAiming_SuperFct);
	return returnCheckSuperFct;

}

// check ray aiming E0
bool BenchmarkRayAiming::checkRayAimingE0_inf()
{
	std::vector<bool> checkRayAiming_E0;

	//*** standart ***//
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	unsigned int rings = 6;
	unsigned int arms = 8;
	real refIndexAir = 1.0;
	//*** ------  ***//

	// TestSystem00 ///////////////////////////////////////////////////
	OpticalSystem_LLT TestSystem00;

	// 0 surface
	SphericalSurface_LLT SphericalSurfaceTS00_0(/*radius*/12.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,15.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.7);
	// 1 surface
	SphericalSurface_LLT SphericalSurfaceTS00_1(/*radius*/12.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,17.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.7);
	// 2 surface
	ApertureStop_LLT AperturStopTS00_2{/*semiHeight*/ 1.0, /*Apex*/{ 0.0,0.0,20.0 },/*direction*/ { 0.0,0.0,20.0 },
		/*refIndex*/ 1.0 };
	// 3 surface
	PlanGeometry_LLT PlanSurfaceTS00_3(/*semiHeight*/ 4.0, /*Apex*/{ 0.0,0.0,23.0 }, /*Direction*/{ 0.0,0.0,1.0 },
		/*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);

	// build the optical system
	TestSystem00.fillVectorSurfaceAndInteractingData(0, &SphericalSurfaceTS00_0, refrac.clone());
	TestSystem00.fillVectorSurfaceAndInteractingData(1, &SphericalSurfaceTS00_1, refrac.clone());
	TestSystem00.fillVectorSurfaceAndInteractingData(2, &AperturStopTS00_2, doNothing.clone());
	TestSystem00.fillVectorSurfaceAndInteractingData(3, &PlanSurfaceTS00_3, absorb.clone());

	///// ***********************************
	///// ray aiming with test system 0 with rays from infinity !!!
	///// ***********************************
	/// *** direction Z = 1 *** //
	VectorStructR3 rayDirectionTS00_1 = { 0.0,0.0,1.0 };

	VectorStructR3 targetPointTS00_0 = { 0.7 ,-0.02,20.0 };
	lightRay_interPoint_onTarget ch00_inf_0 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem00, /*ray direction*/ rayDirectionTS00_1, /*target point*/ targetPointTS00_0, /*light*/ light, /*accurancy*/ 0.00001);
	checkRayAiming_E0.push_back(ch00_inf_0.getOnTarget());

	VectorStructR3 targetPointTS00_1 = { -0.4 ,-0.69282,20.0 };
	lightRay_interPoint_onTarget ch00_inf_1 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem00, /*ray direction*/ rayDirectionTS00_1, /*target point*/ targetPointTS00_1, /*light*/ light, /*accurancy*/ 0.00001);
	checkRayAiming_E0.push_back(ch00_inf_1.getOnTarget());

	VectorStructR3 targetPointTS00_2 = { -0.642788 ,-0.766044 ,20.0 };
	lightRay_interPoint_onTarget ch00_inf_2 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem00, /*ray direction*/ rayDirectionTS00_1, /*target point*/ targetPointTS00_2, /*light*/ light, /*accurancy*/ 0.00001);
	checkRayAiming_E0.push_back(ch00_inf_2.getOnTarget());

	VectorStructR3 targetPointTS00_3 = { -0.76604443120 ,-0.64278760968 ,20.0 };
	lightRay_interPoint_onTarget ch00_inf_3 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem00, /*ray direction*/ rayDirectionTS00_1, /*target point*/ targetPointTS00_3, /*light*/ light, /*accurancy*/ 0.00001);
	checkRayAiming_E0.push_back(ch00_inf_3.getOnTarget());

	bool ch00_inf_many_0 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem00, /*ray direction*/ rayDirectionTS00_1, /*rings*/ rings,/*arms*/ arms,/*light*/ light, /*compare rms*/ 300.496, /*tolerance*/  1.0, /*accurancy*/ 0.00001);
	checkRayAiming_E0.push_back(ch00_inf_many_0);
	// *** *** //

	// *** angle y 0.5 *** //
	VectorStructR3 rayDirectionTS00_05 = Math::convertAngleInDirection(0.0, 0.5);

	VectorStructR3 targetPointTS00_05_0 = { 0.254 ,-0.249,20.0 };
	lightRay_interPoint_onTarget ch00_inf_05_0 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem00, /*ray direction*/ rayDirectionTS00_05, /*target point*/ targetPointTS00_05_0, /*light*/ light, /*accurancy*/ 0.00001);
	checkRayAiming_E0.push_back(ch00_inf_05_0.getOnTarget());
	bool checkStartP_E0_05_0 = checkStartPointRay(ch00_inf_05_0, { 0.4300800456,-0.49798195051,13.0 }, 0.001);
	checkRayAiming_E0.push_back(checkStartP_E0_05_0);
	bool checkDirection_E0_05_0 = checkDirection_inf(0.0, 0.5, ch00_inf_05_0.getLightRay().getRay_LLT().getDirectionRayUnit(), 0.001);
	checkRayAiming_E0.push_back(checkDirection_E0_05_0);

	VectorStructR3 targetPointTS00_05_1 = { 0.0 ,-0.8,20.0 };
	lightRay_interPoint_onTarget ch00_inf_05_1 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem00, /*ray direction*/ rayDirectionTS00_05, /*target point*/ targetPointTS00_05_1, /*light*/ light, /*accurancy*/ 0.00001);
	checkRayAiming_E0.push_back(ch00_inf_05_1.getOnTarget());
	bool checkStartP_E0_05_1 = checkStartPointRay(ch00_inf_05_1, { 0.0,-1.4601280734,13.0 }, 0.001);
	checkRayAiming_E0.push_back(checkStartP_E0_05_1);
	bool checkDirection_E0_05_1 = checkDirection_inf(0.0, 0.5, ch00_inf_05_1.getLightRay().getRay_LLT().getDirectionRayUnit(), 0.001);
	checkRayAiming_E0.push_back(checkDirection_E0_05_1);

	VectorStructR3 targetPointTS00_05_2 = { 0.5 ,0.5,20.0 };
	lightRay_interPoint_onTarget ch00_inf_05_2 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem00, /*ray direction*/ rayDirectionTS00_05, /*target point*/ targetPointTS00_05_2, /*light*/ light, /*accurancy*/ 0.00001);
	checkRayAiming_E0.push_back(ch00_inf_05_2.getOnTarget());
	bool checkStartP_E0_05_2 = checkStartPointRay(ch00_inf_05_2, { 0.85508961601,0.77763913885,13.0 }, 0.001);
	checkRayAiming_E0.push_back(checkStartP_E0_05_2);
	bool checkDirection_E0_05_2 = checkDirection_inf(0.0, 0.5, ch00_inf_05_2.getLightRay().getRay_LLT().getDirectionRayUnit(), 0.001);
	checkRayAiming_E0.push_back(checkDirection_E0_05_2);

	bool ch00_inf_many_05 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem00, /*ray direction*/ rayDirectionTS00_05, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 300.214, /*tolerance*/  1.0, /*accurancy*/ 0.00001);
	checkRayAiming_E0.push_back(ch00_inf_many_05);

	// *** angle x 0.5 / y 0.5 *** //
	VectorStructR3 rayDirectionTS00_05_05 = Math::convertAngleInDirection(0.5, 0.5);

	VectorStructR3 targetPointTS00_05_05_0 = { 0.3 ,-0.4,20.0 };
	lightRay_interPoint_onTarget ch00_inf_05_05_0 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem00, /*ray direction*/ rayDirectionTS00_05_05, /*target point*/ targetPointTS00_05_05_0, /*light*/ light,/*accurancy*/ 0.00001);
	checkRayAiming_E0.push_back(ch00_inf_05_05_0.getOnTarget());
	bool checkDirection_E0_05_05_0 = checkDirection_inf(0.5, 0.5, ch00_inf_05_05_0.getLightRay().getRay_LLT().getDirectionRayUnit(), 3);
	checkRayAiming_E0.push_back(checkDirection_E0_05_05_0);

	bool ch00_inf_many_05_05 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem00, /*ray direction*/ rayDirectionTS00_05_05, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 299.931, /*tolerance*/  1.0,/*accurancy*/ 0.00001);
	checkRayAiming_E0.push_back(ch00_inf_many_05_05);



	bool returnCheckerE0 = Math::checkTrueOfVectorElements(checkRayAiming_E0);
	return returnCheckerE0;

}

bool BenchmarkRayAiming::checkRayAimingE1_inf()
{
	std::vector<bool> checkRayAiming_E1;

	//*** standart ***//
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	unsigned int rings = 6;
	unsigned int arms = 8;
	real refIndexAir = 1.0;
	//*** ------  ***//


	// TestSystem01 ///////////////////////////////////////////////////
	OpticalSystem_LLT TestSystem01_DG;

	// 0 surface
	SphericalSurface_LLT SphericalSurfaceTS01_0(/*radius*/3.55191, /*semiHeight*/2.215, /*Apex of the sphere*/{ 0.0,0.0,5.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.846663);
	// 1 surface
	PlanGeometry_LLT PlanSurfaceTS01_1(/*semiHeight*/2.215,/*Apex*/{ 0.0,0.0,6.39909 }, /*Direction*/{ 0.0,0.0,1.0 }, /*refIndexSideA*/  1.846663,  /*refIndexSideB*/ 1.0);;
	// 2 surface
	SphericalSurface_LLT SphericalSurfaceTS01_2(/*radius*/1.70434, /*semiHeight*/1.47, /*Apex of the sphere*/{ 0.0,0.0,6.40786 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.552322);
	// 3 surface
	SphericalSurface_LLT SphericalSurfaceTS01_3(/*radius*/16.23815, /*semiHeight*/1.47, /*Apex of the sphere*/{ 0.0,0.0,7.346384 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.717360, /*refIndexSideB*/1.552322);
	// 4 surface
	SphericalSurface_LLT SphericalSurfaceTS01_4(/*radius*/0.98604, /*semiHeight*/0.81, /*Apex of the sphere*/{ 0.0,0.0,7.598577 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.717360, /*refIndexSideB*/1.0);
	// 5 surface
	ApertureStop_LLT AperturStopTS01_5{/*semiHeight*/ 0.50, /*Apex*/{ 0.0,0.0,8.03220600 },/*direction*/ { 0.0,0.0,1.0 }, /*refIndex*/ 1.0 };
	// 6 surface
	SphericalSurface_LLT SphericalSurfaceTS01_6(/*radius*/1.642380, /*semiHeight*/0.81, /*Apex of the sphere*/{ 0.0,0.0,8.3098700 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.717360, /*refIndexSideB*/1.0);
	// 7 surface
	SphericalSurface_LLT SphericalSurfaceTS01_7(/*radius*/1.80278, /*semiHeight*/1.024999980, /*Apex of the sphere*/{ 0.0,0.0,8.580042 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.717360, /*refIndexSideB*/1.744002);
	// 8 surface
	SphericalSurface_LLT SphericalSurfaceTS01_8(/*radius*/2.33364, /*semiHeight*/1.024999980, /*Apex of the sphere*/{ 0.0,0.0,9.738626 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.744002);
	// 9 surface
	SphericalSurface_LLT SphericalSurfaceTS01_9(/*radius*/1.65927, /*semiHeight*/0.93, /*Apex of the sphere*/{ 0.0,0.0,10.185872 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.744002);
	// 10 surface
	SphericalSurface_LLT SphericalSurfaceTS01_10(/*radius*/14.41124, /*semiHeight*/0.93, /*Apex of the sphere*/{ 0.0,0.0,11.229631 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.744002, /*refIndexSideB*/1.0);
	// 11 surface
	PlanGeometry_LLT PlanSurfaceTS01_11(/*semiHeight*/ 1.0, /*Apex*/{ 0.0,0.0,11.552572675 }, /*Direction*/{ 0.0,0.0,1.0 }, /*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);


	// build the optical system
	TestSystem01_DG.fillVectorSurfaceAndInteractingData(0, SphericalSurfaceTS01_0.clone(), refrac.clone());
	TestSystem01_DG.fillVectorSurfaceAndInteractingData(1, PlanSurfaceTS01_1.clone(), refrac.clone());
	TestSystem01_DG.fillVectorSurfaceAndInteractingData(2, SphericalSurfaceTS01_2.clone(), refrac.clone());
	TestSystem01_DG.fillVectorSurfaceAndInteractingData(3, SphericalSurfaceTS01_3.clone(), refrac.clone());
	TestSystem01_DG.fillVectorSurfaceAndInteractingData(4, SphericalSurfaceTS01_4.clone(), refrac.clone());
	TestSystem01_DG.fillVectorSurfaceAndInteractingData(5, AperturStopTS01_5.clone(), doNothing.clone());
	TestSystem01_DG.fillVectorSurfaceAndInteractingData(6, SphericalSurfaceTS01_6.clone(), refrac.clone());
	TestSystem01_DG.fillVectorSurfaceAndInteractingData(7, SphericalSurfaceTS01_7.clone(), refrac.clone());
	TestSystem01_DG.fillVectorSurfaceAndInteractingData(8, SphericalSurfaceTS01_8.clone(), refrac.clone());
	TestSystem01_DG.fillVectorSurfaceAndInteractingData(9, SphericalSurfaceTS01_9.clone(), refrac.clone());
	TestSystem01_DG.fillVectorSurfaceAndInteractingData(10, SphericalSurfaceTS01_10.clone(), refrac.clone());
	TestSystem01_DG.fillVectorSurfaceAndInteractingData(11, PlanSurfaceTS01_11.clone(), absorb.clone());

	/// ***********************************
	/// ray aiming with test system 1 with rays from infinity !!!
	/// ***********************************
	/// *** direction Z = 1 *** //
	VectorStructR3 rayDirectionTS1_1 = { 0.0,0.0,1.0 };

	bool checkSingleRay = checkRayTracing_inf(TestSystem01_DG, { 0.0,1.4006185992,0.0 }, 0.0, 0.0, 1.0, light, { 0.0,-0.02700151822,11.552572675 }, 11, 0.00001);

	VectorStructR3 targetPointTS1_0 = { -0.31 ,0.21,20.0 };
	lightRay_interPoint_onTarget ch1_inf_0 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem01_DG, /*ray direction*/ rayDirectionTS1_1, /*target point*/ targetPointTS1_0, /*light*/ light, /*accurancy*/ 0.00001);
	checkRayAiming_E1.push_back(ch1_inf_0.getOnTarget());
	
	VectorStructR3 targetPointTS1_2 = { -0.39 ,0.21,20.0 };
	lightRay_interPoint_onTarget ch1_inf_1 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem01_DG, /*ray direction*/ rayDirectionTS1_1, /*target point*/ targetPointTS1_2, /*light*/ light, /*accurancy*/ 0.00001);
	checkRayAiming_E1.push_back(ch1_inf_1.getOnTarget());
	
	bool ch1_inf_many_1_3 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem01_DG, /*ray direction*/ rayDirectionTS1_1, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 2.024, /*tolerance*/  0.1, /*accurancy*/ 0.00001);
	checkRayAiming_E1.push_back(ch1_inf_many_1_3);

	// *** angle x -0.5 / y -0.5 *** //
	VectorStructR3 rayDirectionTS01_neg05_neg05 = Math::convertAngleInDirection(-0.5, -0.5);
	
	VectorStructR3 targetPointTS1DG_05_05_0 = { 0.3 ,-0.4,20.0 };
	lightRay_interPoint_onTarget ch1DG_inf_05_05_0 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem01_DG, /*ray direction*/ rayDirectionTS01_neg05_neg05, /*target point*/ targetPointTS1DG_05_05_0, /*light*/ light,/*accurancy*/ 0.00001);
	checkRayAiming_E1.push_back(ch1DG_inf_05_05_0.getOnTarget());
	bool checkDirection_E0_05_05_0 = checkDirection_inf(-0.5, -0.5, ch1DG_inf_05_05_0.getLightRay().getRay_LLT().getDirectionRayUnit(), 3);
	checkRayAiming_E1.push_back(checkDirection_E0_05_05_0);


	// *** check single ray tracing *** //
	VectorStructR3 startPoint0(0.0937985385, 0.0937985385, 0.0);
	VectorStructR3 direction_neg05_neg05 = Math::convertAngleInDirection(-0.5, -0.5);
	VectorStructR3 targetPoint0(-0.0383826, -0.0383826, 11.552572675);
	unsigned int posLastSurface = 11;
	real tolerance = 0.001;
	bool checkSingleRayTrace0 = oftenUse::checkRayTracing(startPoint0, direction_neg05_neg05, targetPoint0, TestSystem01_DG, posLastSurface, tolerance);
	// *** *** //
	
	bool ch00_inf_many_neg05_neg05 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem01_DG, /*ray direction*/ rayDirectionTS01_neg05_neg05, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 2.204, /*tolerance*/  0.1,/*accurancy*/ 0.00001);
	checkRayAiming_E1.push_back(ch00_inf_many_neg05_neg05);
	
	// *** angle x 1.5 / y 0.5 *** //
	VectorStructR3 rayDirectionTS01_15_05 = Math::convertAngleInDirection(1.5, 0.5);
	bool ch00_inf_many_15_05 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem01_DG, /*ray direction*/ rayDirectionTS01_15_05, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 2.929, /*tolerance*/  0.1,/*accurancy*/ 0.00001);
	checkRayAiming_E1.push_back(ch00_inf_many_15_05);

	bool returnCheckerE1 = Math::checkTrueOfVectorElements(checkRayAiming_E1);
	return returnCheckerE1;

}


bool BenchmarkRayAiming::checkRayAimingE2_inf()
{
	std::vector<bool> checkRayAiming_E2;

	//*** standart ***//
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	unsigned int rings = 6;
	unsigned int arms = 8;
	real refIndexAir = 1.0;
	//*** ------  ***//


	// TestSystem02 ///////////////////////////////////////////////////
	OpticalSystem_LLT TestSystem02;

	// 0 surface
	SphericalSurface_LLT SphericalSurfaceTS02_0(/*radius*/10, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,10.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	// 2 surface
	SphericalSurface_LLT SphericalSurfaceTS02_1(/*radius*/10, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,11.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	// 3 surface
	SphericalSurface_LLT SphericalSurfaceTS02_2(/*radius*/10, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,12.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 4 surface
	SphericalSurface_LLT SphericalSurfaceTS02_3(/*radius*/10, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,13.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 5 surface
	ApertureStop_LLT AperturStopTS02_4{/*semiHeight*/ 1.5, /*Apex*/{ 0.0,0.0,14.0 },/*direction*/ { 0.0,0.0,1.0 }, /*refIndex*/ 1.0 };
	// 6 surface
	PlanGeometry_LLT PlanSurfaceTS02_5(/*semiHeight*/ 10.0, /*Apex*/{ 0.0,0.0,24.0 }, /*Direction*/{ 0.0,0.0,1.0 }, /*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);

	// build the optical system
	TestSystem02.fillVectorSurfaceAndInteractingData(0, SphericalSurfaceTS02_0.clone(), refrac.clone());
	TestSystem02.fillVectorSurfaceAndInteractingData(1, SphericalSurfaceTS02_1.clone(), refrac.clone());
	TestSystem02.fillVectorSurfaceAndInteractingData(2, SphericalSurfaceTS02_2.clone(), refrac.clone());
	TestSystem02.fillVectorSurfaceAndInteractingData(3, SphericalSurfaceTS02_3.clone(), refrac.clone());
	TestSystem02.fillVectorSurfaceAndInteractingData(4, AperturStopTS02_4.clone(), doNothing.clone());
	TestSystem02.fillVectorSurfaceAndInteractingData(5, PlanSurfaceTS02_5.clone(), absorb.clone());

	bool checkSingleRay = checkRayTracing_inf(TestSystem02, { 0.0,1.5161367647,0.0 }, 0.0, 0.0, 1.0, light, { 0.0,-0.5536520483,24.0 }, 5, 0.00001);
	checkRayAiming_E2.push_back(checkSingleRay);

	// ***********************************
	// ray aiming with test system 1 with rays from infinity !!!
	// ***********************************
	// *** direction Z = 1 *** //
	VectorStructR3 rayDirectionTS2_1 = { 0.0,0.0,1.0 };
	

	VectorStructR3 targetPointTS2_0 = { -0.7 ,0.6,14.0 };
	lightRay_interPoint_onTarget ch2_inf_0 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem02, /*ray direction*/ rayDirectionTS2_1, /*target point*/ targetPointTS2_0, /*light*/ light, /*accurancy*/ 0.00001);
	checkRayAiming_E2.push_back(ch2_inf_0.getOnTarget());
	
	VectorStructR3 targetPointTS2_2 = { -0.3 ,0.1,14.0 };
	lightRay_interPoint_onTarget ch2_inf_1 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem02, /*ray direction*/ rayDirectionTS2_1, /*target point*/ targetPointTS2_2, /*light*/ light, /*accurancy*/ 0.00001);
	checkRayAiming_E2.push_back(ch2_inf_1.getOnTarget());
	
	bool ch2_inf_many_1 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem02, /*ray direction*/ rayDirectionTS2_1, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 386.763, /*tolerance*/  0.1, /*accurancy*/ 0.00001);
	checkRayAiming_E2.push_back(ch2_inf_many_1);
	
	// *** angle x -1.0 / y 2.0 *** //
	VectorStructR3 rayDirectionTS02_neg1_2 = Math::convertAngleInDirection(-1.0, 2.0);
	
	VectorStructR3 targetPointTS2_neg1_2 = { 0.8 ,-0.2,14.0 };
	lightRay_interPoint_onTarget ch2_inf_neg1_2 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem02, /*ray direction*/ rayDirectionTS02_neg1_2, /*target point*/ targetPointTS2_neg1_2, /*light*/ light,/*accurancy*/ 0.00001);
	checkRayAiming_E2.push_back(ch2_inf_neg1_2.getOnTarget());
	
	bool ch2_inf_many_neg1_2 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem02, /*ray direction*/ rayDirectionTS02_neg1_2, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 391.278, /*tolerance*/  0.1,/*accurancy*/ 0.00001);
	checkRayAiming_E2.push_back(ch2_inf_many_neg1_2);

	// *** angle x 1.5 / y -0.5 *** //
	VectorStructR3 rayDirectionTS2_15_neg05 = Math::convertAngleInDirection(1.5, -0.5);
	bool ch2_inf_many_15_05 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem02, /*ray direction*/ rayDirectionTS2_15_neg05, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 389.017, /*tolerance*/  0.1,/*accurancy*/ 0.00001);
	checkRayAiming_E2.push_back(ch2_inf_many_15_05);

	bool returnCheckerE2 = Math::checkTrueOfVectorElements(checkRayAiming_E2);
	return returnCheckerE2;
}


bool BenchmarkRayAiming::checkRayAimingE3_inf()
{
	std::vector<bool> checkRayAiming_E3;

	//*** standart ***//
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	unsigned int rings = 6;
	unsigned int arms = 8;
	real refIndexAir = 1.0;
	//*** ------  ***//

		// TestSystem03 ///////////////////////////////////////////////////
	OpticalSystem_LLT TestSystem03;

	// 0 surface
	ApertureStop_LLT AperturStopTS03_0{/*semiHeight*/ 1.5, /*Apex*/{ 0.0,0.0,5.0 },/*direction*/ { 0.0,0.0,1.0 }, /*refIndex*/ 1.0 };
	// 1 surface
	SphericalSurface_LLT SphericalSurfaceTS03_1(/*radius*/10, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,10.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 2 surface
	SphericalSurface_LLT SphericalSurfaceTS03_2(/*radius*/10, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,15.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 3 surface
	PlanGeometry_LLT PlanSurfaceTS03_3(/*semiHeight*/ 10.0, /*Apex*/{ 0.0,0.0,20.0 }, /*Direction*/{ 0.0,0.0,1.0 }, /*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);

	// build the optical system
	TestSystem03.fillVectorSurfaceAndInteractingData(0, AperturStopTS03_0.clone(), doNothing.clone());
	TestSystem03.fillVectorSurfaceAndInteractingData(1, SphericalSurfaceTS03_1.clone(), refrac.clone());
	TestSystem03.fillVectorSurfaceAndInteractingData(2, SphericalSurfaceTS03_2.clone(), refrac.clone());
	TestSystem03.fillVectorSurfaceAndInteractingData(3, PlanSurfaceTS03_3.clone(), absorb.clone());

	// ***********************************
	// ray aiming with test system 1 with rays from infinity !!!
	// ***********************************
	// *** direction Z = 1 *** //
	VectorStructR3 rayDirectionTS3_1 = { 0.0,0.0,1.0 };
	bool ch3_inf_many_1 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem03, /*ray direction*/ rayDirectionTS3_1, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 195.275, /*tolerance*/  0.1, /*accurancy*/ 0.00001);
	checkRayAiming_E3.push_back(ch3_inf_many_1);

	// *** angle x 1.5 / y 2.0 *** //
	VectorStructR3 rayDirectionTS02_15_2 = Math::convertAngleInDirection(1.5, 2.0);
	bool ch3_inf_many_15_2 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem03, /*ray direction*/ rayDirectionTS02_15_2, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 198.574, /*tolerance*/  0.1,/*accurancy*/ 0.00001);
	checkRayAiming_E3.push_back(ch3_inf_many_15_2);

	// *** angle x 1.2 / y -1.3 *** //
	VectorStructR3 rayDirectionTS2_12_neg13 = Math::convertAngleInDirection(1.2, -1.3);
	bool ch3_inf_many_12_neg13 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem03, /*ray direction*/ rayDirectionTS2_12_neg13, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 196.924, /*tolerance*/  0.1,/*accurancy*/ 0.00001);
	checkRayAiming_E3.push_back(ch3_inf_many_12_neg13);


	bool returnCheckerE3 = Math::checkTrueOfVectorElements(checkRayAiming_E3);
	return returnCheckerE3;

}

bool BenchmarkRayAiming::checkRayAimingE4_inf()
{
	std::vector<bool> checkRayAiming_E4;

	//*** standart ***//
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	unsigned int rings = 6;
	unsigned int arms = 8;
	real refIndexAir = 1.0;
	//*** ------  ***//

	OpticalSystem_LLT TestSystem4;

	// 0 surface
	SphericalSurface_LLT SphericalSurfaceTS3_0(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,15.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 1 surface
	SphericalSurface_LLT SphericalSurfaceTS3_1(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,17.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 2 surface
	SphericalSurface_LLT SphericalSurfaceTS3_2(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,27.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 3 surface
	SphericalSurface_LLT SphericalSurfaceTS3_3(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,29.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 4 surface
	ApertureStop_LLT AperturStopTS3_4{/*semiHeight*/ 1.1, /*Apex*/{ 0.0,0.0,32.0 },/*direction*/ { 0.0,0.0,1.0 },
		/*refIndex*/ 1.0 };
	// 5 surface
	SphericalSurface_LLT SphericalSurfaceTS3_5(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,35.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	// 6 surface
	SphericalSurface_LLT SphericalSurfaceTS3_6(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,37.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	// 7 surface
	PlanGeometry_LLT PlanSurfaceTS3_7(/*semiHeight*/ 4.0, /*Apex*/{ 0.0,0.0,42.0 }, /*Direction*/{ 0.0,0.0,1.0 },
		/*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);

	// build the optical system
	TestSystem4.fillVectorSurfaceAndInteractingData(0, &SphericalSurfaceTS3_0, refrac.clone());
	TestSystem4.fillVectorSurfaceAndInteractingData(1, &SphericalSurfaceTS3_1, refrac.clone());
	TestSystem4.fillVectorSurfaceAndInteractingData(2, &SphericalSurfaceTS3_2, refrac.clone());
	TestSystem4.fillVectorSurfaceAndInteractingData(3, &SphericalSurfaceTS3_3, refrac.clone());
	TestSystem4.fillVectorSurfaceAndInteractingData(4, &AperturStopTS3_4, doNothing.clone());
	TestSystem4.fillVectorSurfaceAndInteractingData(5, &SphericalSurfaceTS3_5, refrac.clone());
	TestSystem4.fillVectorSurfaceAndInteractingData(6, &SphericalSurfaceTS3_6, refrac.clone());
	TestSystem4.fillVectorSurfaceAndInteractingData(7, &PlanSurfaceTS3_7, absorb.clone());

	// ***********************************
	// ray aiming with test system 1 with rays from infinity !!!
	// ***********************************
	// *** direction Z = 1 *** //
	VectorStructR3 rayDirectionTS4_1 = { 0.0,0.0,1.0 };
	bool ch4_inf_many_1 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem4, /*ray direction*/ rayDirectionTS4_1, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 187.740, /*tolerance*/  0.1, /*accurancy*/ 0.00001);
	checkRayAiming_E4.push_back(ch4_inf_many_1);

	// *** angle x -0.3 / y 0.6 *** //
	VectorStructR3 rayDirectionTS02_neg03_06 = Math::convertAngleInDirection(-0.3, 0.6);
	bool ch3_inf_many_neg03_06 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem4, /*ray direction*/ rayDirectionTS02_neg03_06, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 187.418, /*tolerance*/  0.1,/*accurancy*/ 0.00001);
	checkRayAiming_E4.push_back(ch3_inf_many_neg03_06);

	// *** angle x -0.9 / y -0.3 *** //
	VectorStructR3 rayDirectionTS2_neg09_neg03 = Math::convertAngleInDirection(0.9, -0.3);
	bool ch3_inf_many_neg09_neg03 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem4, /*ray direction*/ rayDirectionTS2_neg09_neg03, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 187.096, /*tolerance*/  0.1,/*accurancy*/ 0.00001);
	checkRayAiming_E4.push_back(ch3_inf_many_neg09_neg03);


	bool returnCheckerE4 = Math::checkTrueOfVectorElements(checkRayAiming_E4);
	return returnCheckerE4;

}




	
	


	
	
	



bool BenchmarkRayAiming::checkRayAimingManyRay_obj(OpticalSystem_LLT& const optSys_LLT, VectorStructR3& const startPointRay, /*rings*/ unsigned int& const ringsAB,/*arms*/ unsigned int& const armsAB,/*refractive index*/ double& const refractiveIndex,/*light*/ Light_LLT& const Light)
{
	// find position aperture stop in opt sys
	unsigned int posApertureStop = optSys_LLT.getPosApertureStop();
	// get semi height aberture stop
	real semiHeightApertureStop = optSys_LLT.getPosAndInteractingSurface()[posApertureStop].getSurfaceInterRay_ptr()->getSemiHeight();
	// get point of aperture stop
	VectorStructR3 pointApertureStop = optSys_LLT.getPosAndInteractingSurface()[posApertureStop].getSurfaceInterRay_ptr()->getPoint();
	// get direction aperture stop
	VectorStructR3 directionApertureStop = optSys_LLT.getPosAndInteractingSurface()[posApertureStop].getSurfaceInterRay_ptr()->getDirection();
	
	FillApertureStop fillAperStop(/*start point rays*/startPointRay,/*semi height of aperture stop*/ semiHeightApertureStop,/*point of aperture stop*/ pointApertureStop,/*direction of aperture stop*/ directionApertureStop, /*rings*/ ringsAB,/*arms*/ armsAB,/*refractive index*/ refractiveIndex,/*light*/ Light);

	LightRayStruct tempLightRay;
	RayAiming rayAiming(optSys_LLT);
	SequentialRayTracing seqTrac(optSys_LLT);
	VectorStructR3 checker;
	bool singleCheckInterPoint;
	std::vector<bool> checkInterPoints_vec;

	for (unsigned int i = 0; i < fillAperStop.getPointsInAS().size(); ++i)
	{
		tempLightRay = rayAiming.calcRayThrowPointInApertureStop(startPointRay, fillAperStop.getPointsInAS()[i], Light, 1.0);
		seqTrac.sequentialRayTracing(tempLightRay);
		checker = seqTrac.getAllInterPointsAtSurf_i(posApertureStop)[i];
		//interPoints00_0.push_back(checkTS00_0);
		singleCheckInterPoint = Math::compareTwoVectorStructR3_decimals(fillAperStop.getPointsInAS().at(i), checker, 4);
		checkInterPoints_vec.push_back(singleCheckInterPoint);
	}

	return Math::checkTrueOfVectorElements(checkInterPoints_vec);

}

bool BenchmarkRayAiming::checkRayAimingSingleRay_obj(/*opt sys LLT*/ OpticalSystem_LLT& const optSys_LLT, /*start point Ray*/ VectorStructR3& const startPointRay, /*target point*/ VectorStructR3& const  targetPoint, /*light*/ Light_LLT& const Light)
{

	RayAiming RayAiming(optSys_LLT);
	LightRayStruct testLightRay = RayAiming.calcRayThrowPointInApertureStop(startPointRay, targetPoint, Light, 1.0);
	SequentialRayTracing seqTrace(optSys_LLT);
	seqTrace.sequentialRayTracing(testLightRay);
	VectorStructR3 checker = seqTrace.getAllInterPointsAtSurf_i(RayAiming.getPositionApertureStop(optSys_LLT)).at(0);
	bool returnChecker = Math::compareTwoVectorStructR3_decimals(targetPoint, checker, 3);

	return returnChecker;
}

lightRay_interPoint_onTarget BenchmarkRayAiming::checkRayAimingSingleRay_inf(/*opt sys LLT*/ OpticalSystem_LLT& const optSys_LLT, /*ray direction*/ VectorStructR3& const rayDirection, /*target point*/ VectorStructR3& const  targetPoint, /*light*/ Light_LLT& const Light, /*accurency*/ real accurency)
{

	RayAiming RayAiming(optSys_LLT);
	RayAiming.setToleranceX_Y(accurency);
	////VectorStructR3 rayDirectionTS00_2 = { 0.0,0.0,1.0 };
	//VectorStructR3 targetPointTS00_2 = { 0.7 ,-0.02,20.0 };
	LightRayStruct testLightRay = RayAiming.infinityRayAiming(rayDirection, targetPoint, Light, 1.0);
	SequentialRayTracing seqTrace(optSys_LLT);
	seqTrace.sequentialRayTracing(testLightRay);
	VectorStructR3 checkerPoint = seqTrace.getAllInterPointsAtSurf_i(RayAiming.getPositionApertureStop(optSys_LLT)).at(0);
	real disX = RayAiming.calcDistance_X(targetPoint, checkerPoint);
	real disY = RayAiming.calcDistance_Y(targetPoint, checkerPoint);

	bool checkDisX = std::abs(disX) <= RayAiming.getDefaultParameters().getTolerance_XandY();
	bool checkDisY = std::abs(disY) <= RayAiming.getDefaultParameters().getTolerance_XandY();

	bool onTarget = checkDisX && checkDisY;

	lightRay_interPoint_onTarget returnLR_IP_OT(testLightRay, checkerPoint, onTarget);

	return returnLR_IP_OT;
}

bool BenchmarkRayAiming::checkRayAimingManyRay_inf(/*opt sys LLT*/ OpticalSystem_LLT& const optSys_LLT, /*ray direction*/ VectorStructR3& const rayDirection, /*rings*/ unsigned int& const ringsAB,/*arms*/ unsigned int& const armsAB,/*light*/ Light_LLT& const Light, /*compare rms*/ real checkRMS, real tolerance, real accurancy)
{
	// find position aperture stop in opt sys
	unsigned int posApertureStop = optSys_LLT.getPosApertureStop();
	// get semi height aberture stop
	real semiHeightApertureStop = optSys_LLT.getPosAndInteractingSurface()[posApertureStop].getSurfaceInterRay_ptr()->getSemiHeight();
	// get point of aperture stop
	VectorStructR3 pointApertureStop = optSys_LLT.getPosAndInteractingSurface()[posApertureStop].getSurfaceInterRay_ptr()->getPoint();
	// get direction aperture stop
	VectorStructR3 directionApertureStop = optSys_LLT.getPosAndInteractingSurface()[posApertureStop].getSurfaceInterRay_ptr()->getDirection();

	// Ray Aiming from infinity   
	RayAiming RayAiming(optSys_LLT);
	SequentialRayTracing seqTrace(optSys_LLT);
	LightRayStruct testLightRay;
	std::vector<bool> cheker_vec;
	//std::vector<VectorStructR3> interPoints05_5;
	FillApertureStop fillAperStop;
	std::vector<VectorStructR3> pointsInApStop = fillAperStop.fillAS_withPoints(ringsAB, pointApertureStop, directionApertureStop, semiHeightApertureStop);

	std::vector<LightRayStruct> lightRays_vec;
	lightRay_interPoint_onTarget checker;

	// check all intersectio points at the aperture stop
	for (unsigned int i = 0; i < pointsInApStop.size(); i++)
	{
		// just for debugging!
		//int j = 0;
		//if (i == 96)
		//{
		//	j = 1;
		//}

		checker = checkRayAimingSingleRay_inf(/*opt sys LLT*/ optSys_LLT, /*ray direction*/ rayDirection, /*target point*/ pointsInApStop[i], /*light*/ Light, accurancy);

		if (checker.getOnTarget() == false)
		{
			std::cout << "target point: " << std::endl;
			pointsInApStop[i].print();
			std::cout << "point by ray tracing: " << i << std::endl;

		}

		cheker_vec.push_back(checker.getOnTarget());
		lightRays_vec.push_back(checker.getLightRay());
	}

	// just for debugging
	optSys_LLT.printAllOptSysParameter_LLT(optSys_LLT);

	// check rms on image surface
	unsigned int posLastSurface = optSys_LLT.getPosAndInteractingSurface().size() - 1;
	SequentialRayTracing seqTraceForRMS(optSys_LLT);
	seqTraceForRMS.seqRayTracingWithVectorOfLightRays(lightRays_vec);
	Spot Spot(seqTraceForRMS.getAllInterPointsAtSurf_i(posLastSurface), seqTraceForRMS.getAllInterPointsAtSurf_i(posLastSurface)[0]);
	real rmsTOM = Spot.getRMS_µm();
	bool checkRMS_bool = std::abs(rmsTOM - checkRMS) < tolerance;
	cheker_vec.push_back(checkRMS_bool);

	// check for vignetting
	unsigned int sizeFilterInterPoint = seqTraceForRMS.getAllInterInfosOfSurf_i(posLastSurface).size();
	unsigned int sizeNotFilterInterPoint = seqTraceForRMS.getAllInterInfosOfSurf_i_notFiltered(posLastSurface).size();
	bool checkVignetting = sizeFilterInterPoint == sizeNotFilterInterPoint;
	cheker_vec.push_back(checkVignetting);

	// check all directions
	twoVaulesReal angel_X_Y = Math::convertDirectionInAngle(rayDirection);
	real angle_X = angel_X_Y.getVal_1();
	real angle_Y = angel_X_Y.getVal_2();
	bool checkDirection = checkDirectionManyLightRay_inf(angle_X, angle_Y, lightRays_vec, tolerance);

	return Math::checkTrueOfVectorElements(cheker_vec);

}

bool BenchmarkRayAiming::checkStartPointRay(lightRay_interPoint_onTarget lightRay_IP_OT, VectorStructR3 checkStartPoint, real tolerance)
{
	VectorStructR3 startPointTOM = lightRay_IP_OT.getLightRay().getRay_LLT().getOriginRay();

	bool returnChecker = Math::compareTwoVectorStructR3_tolerance(checkStartPoint, startPointTOM, tolerance);

	return returnChecker;
}

bool BenchmarkRayAiming::checkDirection_inf(real targetAngel_X, real targetAngle_Y, VectorStructR3 direction, real tolerance)
{

	twoVaulesReal angelX_Y = Math::convertDirectionInAngle(direction);

	bool checkAngle_X = Math::compareTwoNumbers_tolrance(angelX_Y.getVal_1(), targetAngel_X, tolerance);
	bool checkAngle_Y = Math::compareTwoNumbers_tolrance(angelX_Y.getVal_2(), targetAngle_Y, tolerance);

	return checkAngle_X && checkAngle_Y;

}

bool BenchmarkRayAiming::checkDirectionManyLightRay_inf(real targetAngel_X, real targetAngle_Y, std::vector<LightRayStruct> lightRayVec, real tolerance)
{
	unsigned int size = lightRayVec.size();
	VectorStructR3 tempDirection;
	std::vector<bool> checker_vec;
	checker_vec.resize(size);
	bool tempChecker;

	for (unsigned int i = 0; i < size; ++i)
	{
		tempDirection = lightRayVec[i].getRay_LLT().getDirectionRayUnit();
		tempChecker = checkDirection_inf(targetAngel_X, targetAngle_Y, tempDirection, tolerance);

		checker_vec[i] = tempChecker;
	}

	bool returnChecker = Math::checkTrueOfVectorElements(checker_vec);

	return returnChecker;

}

bool BenchmarkRayAiming::checkRayTracing_inf(OpticalSystem_LLT optSys_LLT, VectorStructR3 origin, real angle_X, real angle_Y, real refIndex, Light_LLT light, VectorStructR3 targetPoint, unsigned int posSurface, real tolerance)
{
	SequentialRayTracing seqTrace(optSys_LLT);

	// build the light ray
	VectorStructR3 direction = Math::convertAngleInDirection(angle_X, angle_Y);
	Ray_LLT ray(origin, direction, refIndex);
	LightRayStruct lightRay(light, ray, 1);

	// trace the ray
	seqTrace.sequentialRayTracing(lightRay);

	//unsigned int posAperStop = optSys_LLT.getPosApertureStop();

	VectorStructR3 intersecPointAS = seqTrace.getAllInterPointsAtSurf_i(posSurface)[0];

	bool checkInterPoint = Math::compareTwoVectorStructR3_tolerance(targetPoint, intersecPointAS, tolerance);

	return checkInterPoint;

}