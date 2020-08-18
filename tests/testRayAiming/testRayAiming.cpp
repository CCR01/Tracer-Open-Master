#include "testRayAiming.h"

#include "..\..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\..\RayAiming\RayAiming.h"
#include "..\..\LowLevelTracing\Interaction\ReflectionRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Light_LLT.h"
#include "..\..\LowLevelTracing\Interaction\InteractionRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"

#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
// glass catalogue
#include "..\..\Glasses\Glasses.h"
#include "..\..\FillAptertureStop\FillApertureStop.h"

#include "..\..\Analyse\Spot.h"

#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

// surface
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\PlanElement.h"
#include "..\..\SurfaceElements\ApertureStopElement.h"

// Für timer, später löschen:
#include <iostream>
#include <cstdio>
#include <ctime>

// typedef
typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interactionPtr;
// ***

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

bool testRayAiming::checkRayAimingSuperFct_inf()
{
	std::vector<bool> checkRayAiming_SuperFct_inf;
	// E0 inf
	bool checkE0 = checkRayAimingE0_inf();
	checkRayAiming_SuperFct_inf.push_back(checkE0);
	// E1 inf
	bool checkE1 = checkRayAimingE1_inf();
	checkRayAiming_SuperFct_inf.push_back(checkE1);
	// E2 inf
	bool checkE2 = checkRayAimingE2_inf();
	checkRayAiming_SuperFct_inf.push_back(checkE2);
	// E3 inf (aperture stop is first surface
	bool checkE3 = checkRayAimingE3_inf();
	checkRayAiming_SuperFct_inf.push_back(checkE3);
	// E4
	bool checkE4 = checkRayAimingE4_inf();
	checkRayAiming_SuperFct_inf.push_back(checkE4);
	// E5
	bool checkE5 = checkRayAimingE5_inf();
	checkRayAiming_SuperFct_inf.push_back(checkE5);


	bool returnCheckSuperFct_inf = Math::checkTrueOfVectorElements(checkRayAiming_SuperFct_inf);
	return returnCheckSuperFct_inf;

}

bool testRayAiming::checkRayAimingSuperFct_obj()
{
	std::vector<bool> checkRayAiming_SuperFct_obj;
	// E0 obj
	bool checkE0 = checkRayAimingE0_obj();
	checkRayAiming_SuperFct_obj.push_back(checkE0);
	// E1 obj
	bool checkE1 = checkRayAimingE1_obj();
	checkRayAiming_SuperFct_obj.push_back(checkE1);
	// E2 obj
	bool checkE2 = checkRayAimingE2_obj();
	checkRayAiming_SuperFct_obj.push_back(checkE2);
	// E3 obj
	bool checkE3 = checkRayAimingE3_obj();
	checkRayAiming_SuperFct_obj.push_back(checkE3);
	// E4 obj
	bool checkE4 = checkRayAimingE4_obj();
	checkRayAiming_SuperFct_obj.push_back(checkE4);
	// E5 obj
	bool checkE5 = checkRayAimingE5_obj();
	checkRayAiming_SuperFct_obj.push_back(checkE5);

	bool returnCheckSuperFct_obj = Math::checkTrueOfVectorElements(checkRayAiming_SuperFct_obj);
	return returnCheckSuperFct_obj;
}

bool testRayAiming::checkRayAimingE0_obj()
{
	std::vector<bool> checkRayAiming_E0;

	//*** standard ***//
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
	SphericalSurface_LLT SphericalSurfaceTS00_0(/*radius*/12.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,15.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.7);
	// 1 surface
	SphericalSurface_LLT SphericalSurfaceTS00_1(/*radius*/12.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,17.0 },
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

	//// origin from the optical axis
	VectorStructR3 originTS0_0 = { 0.0,0.0,0.0 };
	VectorStructR3 targetPointTS0_0 = { 0.277 ,-0.149,20.0 };
	lightRay_interPoint_onTarget ch00_obj_0 = checkRayAimingSingleRay_obj(/*opt sys LLT*/ TestSystem00, /*ray origin*/ originTS0_0, /*target point*/ targetPointTS0_0, /*light*/ light, /*accurency*/  0.0001);
	checkRayAiming_E0.push_back(ch00_obj_0.getOnTarget());
	
	VectorStructR3 targetPointTS0_1 = { -0.6 ,-0.5,20.0 };
	lightRay_interPoint_onTarget ch00_obj_1 = checkRayAimingSingleRay_obj(/*opt sys LLT*/ TestSystem00, /*ray origin*/ originTS0_0, /*target point*/ targetPointTS0_1, /*light*/ light, /*accurency*/  0.0001);
	checkRayAiming_E0.push_back(ch00_obj_1.getOnTarget());
	

	bool ch00_obj_manyOptA = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem00, /*ray origin*/ originTS0_0, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 622.192, /*tolerance*/ 0.1, /*accurency*/ 0.0001);
	checkRayAiming_E0.push_back(ch00_obj_manyOptA);
	
	// origin at x=1 , y = -0.5
	VectorStructR3 originTS0_1_neg05 = { 1.0,-0.5,0.0 };
	VectorStructR3 targetPointTS0_2 = { -0.4 ,0.5,20.0 };
	lightRay_interPoint_onTarget ch00_obj_1_neg05 = checkRayAimingSingleRay_obj(/*opt sys LLT*/ TestSystem00, /*ray origin*/ originTS0_1_neg05, /*target point*/ targetPointTS0_2, /*light*/ light, /*accurency*/  0.0001);
	checkRayAiming_E0.push_back(ch00_obj_1_neg05.getOnTarget());
	
	bool ch00_obj_1_neg05_1 = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem00, /*ray origin*/ originTS0_1_neg05, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 619.310, /*tolerance*/ 0.1, /*accurency*/ 0.0001);
	checkRayAiming_E0.push_back(ch00_obj_1_neg05_1);
	
	// origin at x=-1 , y = 1.5
	VectorStructR3 originTS0_neg1_15 = { -1.0,1.5,0.0 };
	bool ch00_obj_nge1_15 = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem00, /*ray origin*/ originTS0_neg1_15, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 614.482, /*tolerance*/ 0.1, /*accurency*/ 0.0001);
	checkRayAiming_E0.push_back(ch00_obj_nge1_15);


	bool returnCheckerE0 = Math::checkTrueOfVectorElements(checkRayAiming_E0);
	return returnCheckerE0;

}


bool testRayAiming::checkRayAimingE1_obj()
{
	std::vector<bool> checkRayAiming_E1_DG;

	//*** standard ***//
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
	SphericalSurface_LLT SphericalSurfaceTS01_0(/*radius*/3.55191, /*semiHeight*/2.215, /*Apex of the sphere*/{ 0.0,0.0,105.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.846663);
	// 1 surface
	PlanGeometry_LLT PlanSurfaceTS01_1(/*semiHeight*/2.215,/*Apex*/{ 0.0,0.0,106.39909 }, /*Direction*/{ 0.0,0.0,1.0 }, /*refIndexSideA*/  1.846663,  /*refIndexSideB*/ 1.0);;
	// 2 surface
	SphericalSurface_LLT SphericalSurfaceTS01_2(/*radius*/1.70434, /*semiHeight*/1.47, /*Apex of the sphere*/{ 0.0,0.0,106.40786 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.552322);
	// 3 surface
	SphericalSurface_LLT SphericalSurfaceTS01_3(/*radius*/16.23815, /*semiHeight*/1.47, /*Apex of the sphere*/{ 0.0,0.0,107.346384 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.717360, /*refIndexSideB*/1.552322);
	// 4 surface
	SphericalSurface_LLT SphericalSurfaceTS01_4(/*radius*/0.98604, /*semiHeight*/0.81, /*Apex of the sphere*/{ 0.0,0.0,107.598577 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.717360, /*refIndexSideB*/1.0);
	// 5 surface
	ApertureStop_LLT AperturStopTS01_5{/*semiHeight*/ 0.50, /*Apex*/{ 0.0,0.0,108.03220600 },/*direction*/ { 0.0,0.0,1.0 }, /*refIndex*/ 1.0 };
	// 6 surface
	SphericalSurface_LLT SphericalSurfaceTS01_6(/*radius*/1.642380, /*semiHeight*/0.81, /*Apex of the sphere*/{ 0.0,0.0,108.3098700 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.717360, /*refIndexSideB*/1.0);
	// 7 surface
	SphericalSurface_LLT SphericalSurfaceTS01_7(/*radius*/1.80278, /*semiHeight*/1.024999980, /*Apex of the sphere*/{ 0.0,0.0,108.580042 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.717360, /*refIndexSideB*/1.744002);
	// 8 surface
	SphericalSurface_LLT SphericalSurfaceTS01_8(/*radius*/2.33364, /*semiHeight*/1.024999980, /*Apex of the sphere*/{ 0.0,0.0,109.738626 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.744002);
	// 9 surface
	SphericalSurface_LLT SphericalSurfaceTS01_9(/*radius*/1.65927, /*semiHeight*/0.93, /*Apex of the sphere*/{ 0.0,0.0,110.185872 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.744002);
	// 10 surface
	SphericalSurface_LLT SphericalSurfaceTS01_10(/*radius*/14.41124, /*semiHeight*/0.93, /*Apex of the sphere*/{ 0.0,0.0,111.229631 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.744002, /*refIndexSideB*/1.0);
	// 11 surface
	PlanGeometry_LLT PlanSurfaceTS01_11(/*semiHeight*/ 1.0, /*Apex*/{ 0.0,0.0,111.552572675 }, /*Direction*/{ 0.0,0.0,1.0 }, /*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);


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

	// origin from the optical axis
	VectorStructR3 originTS01_DG_optA = { 0.0,0.0,0.0 };
	bool ch01_obj_manyOptA = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem01_DG, /*ray origin*/ originTS01_DG_optA, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 42.725, /*tolerance*/ 0.01, /*accurency*/ 0.0001);
	checkRayAiming_E1_DG.push_back(ch01_obj_manyOptA);
	
	// origin x=2 y=3
	VectorStructR3 originTS01_DG_2_3 = { 2.0,3.0,0.0 };
	bool ch01_obj_2_3 = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem01_DG, /*ray origin*/ originTS01_DG_2_3, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 42.494, /*tolerance*/ 0.01, /*accurency*/ 0.0001);
	checkRayAiming_E1_DG.push_back(ch01_obj_2_3);

	// origin x=-4 y=8
	VectorStructR3 originTS01_DG_neg4_8 = { -4.0,8.0,0.0 };
	VectorStructR3 targetPointTS01_0 = {-0.469846, -0.17101, 108.032 };
	lightRay_interPoint_onTarget ch00_obj_neg4_8 = checkRayAimingSingleRay_obj(/*opt sys LLT*/ TestSystem01_DG, /*ray origin*/ originTS01_DG_neg4_8, /*target point*/ targetPointTS01_0, /*light*/ light, /*accurency*/  0.0001);
	checkRayAiming_E1_DG.push_back(ch00_obj_neg4_8.getOnTarget());
	
	bool ch01_obj_neg4_8 = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem01_DG, /*ray origin*/ originTS01_DG_neg4_8, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 40.817, /*tolerance*/ 0.01, /*accurency*/ 0.0001);
	checkRayAiming_E1_DG.push_back(ch01_obj_neg4_8);
	
	// origin x=3 y=-7
	VectorStructR3 originTS01_DG_3_neg7 = { 3.0,-7.0,0.0 };
	bool ch01_obj_3_nge7 = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem01_DG, /*ray direction*/ originTS01_DG_3_neg7, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 41.450, /*tolerance*/ 0.01, /*accurency*/ 0.0001);
	checkRayAiming_E1_DG.push_back(ch01_obj_3_nge7);

	bool returnCheckerE1 = Math::checkTrueOfVectorElements(checkRayAiming_E1_DG);
	return returnCheckerE1;

}

bool testRayAiming::checkRayAimingE2_obj()
{
	std::vector<bool> checkRayAiming_E2;

	//*** standard ***//
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
	SphericalSurface_LLT SphericalSurfaceTS02_0(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,20.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	// 2 surface
	SphericalSurface_LLT SphericalSurfaceTS02_1(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,21.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	// 3 surface
	SphericalSurface_LLT SphericalSurfaceTS02_2(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,22.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 4 surface
	SphericalSurface_LLT SphericalSurfaceTS02_3(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,23.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 5 surface
	ApertureStop_LLT AperturStopTS02_4{/*semiHeight*/ 1.5, /*Apex*/{ 0.0,0.0,24.0 },/*direction*/ { 0.0,0.0,1.0 }, /*refIndex*/ 1.0 };
	// 6 surface
	PlanGeometry_LLT PlanSurfaceTS02_5(/*semiHeight*/ 10.0, /*Apex*/{ 0.0,0.0,34.0 }, /*Direction*/{ 0.0,0.0,1.0 }, /*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);

	// build the optical system
	TestSystem02.fillVectorSurfaceAndInteractingData(0, SphericalSurfaceTS02_0.clone(), refrac.clone());
	TestSystem02.fillVectorSurfaceAndInteractingData(1, SphericalSurfaceTS02_1.clone(), refrac.clone());
	TestSystem02.fillVectorSurfaceAndInteractingData(2, SphericalSurfaceTS02_2.clone(), refrac.clone());
	TestSystem02.fillVectorSurfaceAndInteractingData(3, SphericalSurfaceTS02_3.clone(), refrac.clone());
	TestSystem02.fillVectorSurfaceAndInteractingData(4, AperturStopTS02_4.clone(), doNothing.clone());
	TestSystem02.fillVectorSurfaceAndInteractingData(5, PlanSurfaceTS02_5.clone(), absorb.clone());

	// origin from the optical axis
	VectorStructR3 originTS02_optA = { 0.0,0.0,0.0 };
	bool ch2_obj_manyOptA = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem02, /*ray origin*/ originTS02_optA, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 149.410, /*tolerance*/ 0.1, /*accurency*/ 0.0001);
	checkRayAiming_E2.push_back(ch2_obj_manyOptA);
	
	// origin x=2 y=-6
	VectorStructR3 originTS02_2_neg6 = { 2.0,-6.0,0.0 };
	bool ch2_obj_2_neg6 = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem02, /*ray origin*/ originTS02_2_neg6, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 140.512, /*tolerance*/ 0.1, /*accurency*/ 0.0001);
	checkRayAiming_E2.push_back(ch2_obj_2_neg6);
	
	// origin x=3 y=4
	VectorStructR3 originTS02_3_4 = { 3.0,4.0,0.0 };
	bool ch2_obj_3_4 = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem02, /*ray origin*/ originTS02_3_4, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 97.480, /*tolerance*/ 0.1, /*accurency*/ 0.0001);
	checkRayAiming_E2.push_back(ch2_obj_3_4);
	
	// origin x=-5 y=6
	VectorStructR3 originTS02_neg5_6 = { -5.0,6.0,0.0 };
	VectorStructR3 targetPointTS02_0 = { -1.1490666646805165, -0.96418141452736972, 24.0};
	lightRay_interPoint_onTarget ch02_obj_neg5_6 = checkRayAimingSingleRay_obj(/*opt sys LLT*/ TestSystem02, /*ray origin*/ originTS02_neg5_6, /*target point*/ targetPointTS02_0, /*light*/ light, /*accurency*/  0.0001);
	checkRayAiming_E2.push_back(ch02_obj_neg5_6.getOnTarget());
	
	bool ch2_obj_neg5_6 = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem02, /*ray origin*/ originTS02_neg5_6, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 258.655, /*tolerance*/ 0.1, /*accurency*/ 0.0001);
	checkRayAiming_E2.push_back(ch2_obj_neg5_6);
	
	// origin x=4 y=1
	VectorStructR3 originTS02_4_1 = { 4.0,1.0,0.0 };
	bool ch2_obj_4_1 = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem02, /*ray origin*/ originTS02_4_1, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 100.205, /*tolerance*/ 0.1, /*accurency*/ 0.0001);
	checkRayAiming_E2.push_back(ch2_obj_4_1);

	bool returnCheckerE2 = Math::checkTrueOfVectorElements(checkRayAiming_E2);
	return returnCheckerE2;
}


bool testRayAiming::checkRayAimingE3_obj()
{
	std::vector<bool> checkRayAiming_E3;

	//*** standard ***//
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
	ApertureStop_LLT AperturStopTS03_0{/*semiHeight*/ 1.5, /*Apex*/{ 0.0,0.0,10.0 },/*direction*/ { 0.0,0.0,1.0 }, /*refIndex*/ 1.0 };
	// 1 surface
	SphericalSurface_LLT SphericalSurfaceTS03_1(/*radius*/10, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,15.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 2 surface
	SphericalSurface_LLT SphericalSurfaceTS03_2(/*radius*/10, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,20.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 3 surface
	PlanGeometry_LLT PlanSurfaceTS03_3(/*semiHeight*/ 10.0, /*Apex*/{ 0.0,0.0,25.0 }, /*Direction*/{ 0.0,0.0,1.0 }, /*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);

	// build the optical system
	TestSystem03.fillVectorSurfaceAndInteractingData(0, AperturStopTS03_0.clone(), doNothing.clone());
	TestSystem03.fillVectorSurfaceAndInteractingData(1, SphericalSurfaceTS03_1.clone(), refrac.clone());
	TestSystem03.fillVectorSurfaceAndInteractingData(2, SphericalSurfaceTS03_2.clone(), refrac.clone());
	TestSystem03.fillVectorSurfaceAndInteractingData(3, PlanSurfaceTS03_3.clone(), absorb.clone());

	/// origin from the optical axis
	VectorStructR3 originTS03_optA = { 0.0,0.0,0.0 };
	bool ch3_obj_manyOptA = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem03, /*ray origin*/ originTS03_optA, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 341.960, /*tolerance*/ 0.1, /*accurency*/ 0.0001);
	checkRayAiming_E3.push_back(ch3_obj_manyOptA);

	// origin x=1 y=-2
	VectorStructR3 originTS03_1_neg2 = { 1.0,-2.0,0.0 };
	bool ch3_obj_1_neg2 = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem03, /*ray origin*/ originTS03_1_neg2, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 348.312, /*tolerance*/ 0.1, /*accurency*/ 0.0001);
	checkRayAiming_E3.push_back(ch3_obj_1_neg2);

	// origin x=0.5 y=2
	VectorStructR3 originTS03_05_2 = { 0.5,2.0,0.0 };
	bool ch3_obj_05_2 = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem03, /*ray origin*/ originTS03_05_2, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 330.052, /*tolerance*/ 0.1, /*accurency*/ 0.0001);
	checkRayAiming_E3.push_back(ch3_obj_05_2);

	// origin x=-1.2 y=-2
	VectorStructR3 originTS03_neg12_neg2 = { -1.2,-2.0,0.0 };
	bool ch3_obj_neg12_neg2 = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem03, /*ray origin*/ originTS03_neg12_neg2, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 362.561, /*tolerance*/ 0.1, /*accurency*/ 0.0001);
	checkRayAiming_E3.push_back(ch3_obj_neg12_neg2);

	bool returnCheckerE3 = Math::checkTrueOfVectorElements(checkRayAiming_E3);
	return returnCheckerE3;
}

bool testRayAiming::checkRayAimingE4_obj()
{
	std::vector<bool> checkRayAiming_E4;

	//*** standard ***//
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
	SphericalSurface_LLT SphericalSurfaceTS4_0(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 1 surface
	SphericalSurface_LLT SphericalSurfaceTS4_1(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,22.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 2 surface
	SphericalSurface_LLT SphericalSurfaceTS4_2(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,32.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 3 surface
	SphericalSurface_LLT SphericalSurfaceTS4_3(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,34.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 4 surface
	ApertureStop_LLT AperturStopTS4_4{/*semiHeight*/ 1.1, /*Apex*/{ 0.0,0.0,37.0 },/*direction*/ { 0.0,0.0,1.0 },
		/*refIndex*/ 1.0 };
	// 5 surface
	SphericalSurface_LLT SphericalSurfaceTS4_5(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,40.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	// 6 surface
	SphericalSurface_LLT SphericalSurfaceTS4_6(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,42.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	// 7 surface
	PlanGeometry_LLT PlanSurfaceTS4_7(/*semiHeight*/ 4.0, /*Apex*/{ 0.0,0.0,47.0 }, /*Direction*/{ 0.0,0.0,1.0 },
		/*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);

	// build the optical system
	TestSystem4.fillVectorSurfaceAndInteractingData(0, &SphericalSurfaceTS4_0, refrac.clone());
	TestSystem4.fillVectorSurfaceAndInteractingData(1, &SphericalSurfaceTS4_1, refrac.clone());
	TestSystem4.fillVectorSurfaceAndInteractingData(2, &SphericalSurfaceTS4_2, refrac.clone());
	TestSystem4.fillVectorSurfaceAndInteractingData(3, &SphericalSurfaceTS4_3, refrac.clone());
	TestSystem4.fillVectorSurfaceAndInteractingData(4, &AperturStopTS4_4, doNothing.clone());
	TestSystem4.fillVectorSurfaceAndInteractingData(5, &SphericalSurfaceTS4_5, refrac.clone());
	TestSystem4.fillVectorSurfaceAndInteractingData(6, &SphericalSurfaceTS4_6, refrac.clone());
	TestSystem4.fillVectorSurfaceAndInteractingData(7, &PlanSurfaceTS4_7, absorb.clone());

	// origin from the optical axis
	VectorStructR3 originTS04_optA = { 0.0,0.0,0.0 };
	bool ch2_obj_manyOptA = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem4, /*ray origin*/ originTS04_optA, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 560.709, /*tolerance*/ 0.1, /*accurency*/ 0.0001);
	checkRayAiming_E4.push_back(ch2_obj_manyOptA);

	// origin x=2 y=-3
	VectorStructR3 originTS04_2_neg3 = { 2.0,-3.0,0.0 };
	VectorStructR3 targetPointTS04_0 = { 0.871802, -0.283266, 37.0 };
	lightRay_interPoint_onTarget ch04_obj_2_neg3 = checkRayAimingSingleRay_obj(/*opt sys LLT*/ TestSystem4, /*ray origin*/ originTS04_2_neg3, /*target point*/ targetPointTS04_0, /*light*/ light, /*accurency*/  0.0001);
	checkRayAiming_E4.push_back(ch04_obj_2_neg3.getOnTarget());

	bool ch2_obj_2_neg3 = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem4, /*ray origin*/ originTS04_2_neg3, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 387.298, /*tolerance*/ 0.1, /*accurency*/ 0.0001);
	checkRayAiming_E4.push_back(ch2_obj_2_neg3);

	// origin x=1 y=4
	VectorStructR3 originTS04_1_4 = { 1.0,4.0,0.0 };
	VectorStructR3 targetPointTS04_1 = { 0.635085, 0.366667, 37.0 };
	lightRay_interPoint_onTarget ch04_obj_1 = checkRayAimingSingleRay_obj(/*opt sys LLT*/ TestSystem4, /*ray origin*/ originTS04_1_4, /*target point*/ targetPointTS04_1, /*light*/ light, /*accurency*/  0.0001);
	checkRayAiming_E4.push_back(ch04_obj_1.getOnTarget());

	VectorStructR3 targetPointTS04_2 = { -0.19101299543117342, 1.0832885283138618, 37.0 };
	lightRay_interPoint_onTarget ch04_obj_2 = checkRayAimingSingleRay_obj(/*opt sys LLT*/ TestSystem4, /*ray origin*/ originTS04_1_4, /*target point*/ targetPointTS04_2, /*light*/ light, /*accurency*/  0.0001);
	checkRayAiming_E4.push_back(ch04_obj_2.getOnTarget());

	bool ch2_obj_1_4 = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem4, /*ray origin*/ originTS04_1_4, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 346.375, /*tolerance*/ 0.1, /*accurency*/ 0.0001);
	checkRayAiming_E4.push_back(ch2_obj_1_4);

	// origin x=-2 y=-3
	VectorStructR3 originTS04_neg2_neg3 = { -2.0,-3.0,0.0 };
	bool ch2_obj_neg2_neg3 = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem4, /*ray origin*/ originTS04_neg2_neg3, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 387.298, /*tolerance*/ 0.1, /*accurency*/ 0.0001);
	checkRayAiming_E4.push_back(ch2_obj_neg2_neg3);

	// origin x=-4 y=1
	VectorStructR3 originTS04_neg4_1 = { -4.0,1.0,0.0 };
	bool ch2_obj_neg4_1 = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem4, /*ray origin*/ originTS04_neg4_1, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 346.375, /*tolerance*/ 0.1, /*accurency*/ 0.0001);
	checkRayAiming_E4.push_back(ch2_obj_neg4_1);


	bool returnCheckerE4 = Math::checkTrueOfVectorElements(checkRayAiming_E4);
	return returnCheckerE4;
}


bool testRayAiming::checkRayAimingE5_obj()
{
	// attention: in this example ray aiming is not possible!
	// the aperture stop can not be filled with rays.

	std::vector<bool> checkRayAiming_E5;

	//*** standard ***//
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



	OpticalSystem_LLT TestSystem5;

	// 0 surface
	SphericalSurface_LLT SphericalSurfaceTS5_0(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,10.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	// 1 surface
	SphericalSurface_LLT SphericalSurfaceTS5_1(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,12.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/2.0);
	// 2 surface
	SphericalSurface_LLT SphericalSurfaceTS5_2(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,14.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 3 surface
	ApertureStop_LLT AperturStopTS5_3{/*semiHeight*/ 3.0, /*Apex*/{ 0.0,0.0,17.0 },/*direction*/ { 0.0,0.0,1.0 },
		/*refIndex*/ 1.0 };
	// 4 surface
	SphericalSurface_LLT SphericalSurfaceTS5_4(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	// 5 surface
	SphericalSurface_LLT SphericalSurfaceTS5_5(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,22.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	// 6 surface
	PlanGeometry_LLT PlanSurfaceTS5_6(/*semiHeight*/ 10.0, /*Apex*/{ 0.0,0.0,27.0 }, /*Direction*/{ 0.0,0.0,1.0 },
		/*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);

	// build the optical system
	TestSystem5.fillVectorSurfaceAndInteractingData(0, &SphericalSurfaceTS5_0, refrac.clone());
	TestSystem5.fillVectorSurfaceAndInteractingData(1, &SphericalSurfaceTS5_1, refrac.clone());
	TestSystem5.fillVectorSurfaceAndInteractingData(2, &SphericalSurfaceTS5_2, refrac.clone());
	TestSystem5.fillVectorSurfaceAndInteractingData(3, &AperturStopTS5_3, doNothing.clone());
	TestSystem5.fillVectorSurfaceAndInteractingData(4, &SphericalSurfaceTS5_4, refrac.clone());
	TestSystem5.fillVectorSurfaceAndInteractingData(5, &SphericalSurfaceTS5_5, refrac.clone());
	TestSystem5.fillVectorSurfaceAndInteractingData(6, &PlanSurfaceTS5_6, absorb.clone());

	// origin x=0 y=0
	VectorStructR3 origin_0 = { 0.0,0.0,0.0 };
	VectorStructR3 targetPoint_0 = { 3.0, 3.0, 17.0 };
	lightRay_interPoint_onTarget ch_obj_1 = checkRayAimingSingleRay_obj(/*opt sys LLT*/ TestSystem5, /*ray origin*/ origin_0, /*target point*/ targetPoint_0, /*light*/ light, /*accurency*/  0.001);
	// here ray aiming is not possible, because of that we can not match the target point 
	bool check_obj_0 = ch_obj_1.getOnTarget() == false;
	checkRayAiming_E5.push_back(check_obj_0);

	// origin {2.0, -0.5, 0.0} -> target {-1.0, 1.3205, 17.0}
	VectorStructR3 origin_singel_1 = { 2.0, -0.5, 0.0 };
	VectorStructR3 target_singel_1 = { -0.7, 1.53205, 17.0 };
	lightRay_interPoint_onTarget ch_single_1 = checkRayAimingSingleRay_obj(/*opt sys LLT*/ TestSystem5, /*ray origin*/ origin_singel_1, /*target point*/ target_singel_1, /*light*/ light, /*accurency*/  0.001);
	bool check_field_singel_1 = ch_single_1.getOnTarget();
	checkRayAiming_E5.push_back(check_field_singel_1);
	
	// origin from the optical axis
	VectorStructR3 originTS05_optA = { 0.0,0.0,0.0 };
	bool check_obj_manyOptA = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem5, /*ray origin*/ originTS05_optA, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 1506.19, /*tolerance*/ 0.1, /*accurency*/ 0.0001);
	checkRayAiming_E5.push_back(check_obj_manyOptA);
	
	// origin from field 0 {-2.0, -1.0, 0.0}
	VectorStructR3 originTS05_field0 = { -2.0, -1.0, 0.0 };
	bool check_field0 = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem5, /*ray origin*/ originTS05_field0, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 1484.79, /*tolerance*/ 0.1, /*accurency*/ 0.0001);
	checkRayAiming_E5.push_back(check_field0);
	
	// origin from field 1 {2.0, -0.5, 0.0}
	VectorStructR3 originTS05_field1 = {2.0, -0.5, 0.0 };
	bool check_field1 = checkRayAimingManyRay_obj(/*opt sys LLT*/  TestSystem5, /*ray origin*/ originTS05_field1, /*rings*/ 6,/*arms*/ 8,/*light*/ light, /*compare rms*/ 1377.00, /*tolerance*/ 0.1, /*accurency*/ 0.0001);
	checkRayAiming_E5.push_back(check_field1);
	
	bool returnCheckerE5 = Math::checkTrueOfVectorElements(checkRayAiming_E5);
	return returnCheckerE5;


}

bool testRayAiming::checkRayAimingE0_inf()
{
	std::vector<bool> checkRayAiming_E0;

	//*** standard ***//
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
	lightRay_interPoint_onTarget ch00_inf_0 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem00, /*ray direction*/ rayDirectionTS00_1, /*target point*/ targetPointTS00_0, /*light*/ light, /*accurancy*/ 0.0001);
	checkRayAiming_E0.push_back(ch00_inf_0.getOnTarget());
	
	VectorStructR3 targetPointTS00_1 = { -0.4 ,-0.69282,20.0 };
	lightRay_interPoint_onTarget ch00_inf_1 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem00, /*ray direction*/ rayDirectionTS00_1, /*target point*/ targetPointTS00_1, /*light*/ light, /*accurancy*/ 0.0001);
	checkRayAiming_E0.push_back(ch00_inf_1.getOnTarget());
	
	VectorStructR3 targetPointTS00_2 = { -0.642788 ,-0.766044 ,20.0 };
	lightRay_interPoint_onTarget ch00_inf_2 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem00, /*ray direction*/ rayDirectionTS00_1, /*target point*/ targetPointTS00_2, /*light*/ light, /*accurancy*/ 0.0001);
	checkRayAiming_E0.push_back(ch00_inf_2.getOnTarget());
	
	VectorStructR3 targetPointTS00_3 = { -0.76604443120 ,-0.64278760968 ,20.0 };
	lightRay_interPoint_onTarget ch00_inf_3 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem00, /*ray direction*/ rayDirectionTS00_1, /*target point*/ targetPointTS00_3, /*light*/ light, /*accurancy*/ 0.0001);
	checkRayAiming_E0.push_back(ch00_inf_3.getOnTarget());

	VectorStructR3 targetPointTS00_4 = { -0.17101007166323409 ,-0.46984631039280861 ,20.0 };
	lightRay_interPoint_onTarget ch00_inf_4 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem00, /*ray direction*/ rayDirectionTS00_1, /*target point*/ targetPointTS00_4, /*light*/ light, /*accurancy*/ 0.0001);
	checkRayAiming_E0.push_back(ch00_inf_4.getOnTarget());

	bool ch00_inf_many_0 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem00, /*ray direction*/ rayDirectionTS00_1, /*rings*/ rings,/*arms*/ arms,/*light*/ light, /*compare rms*/ 300.496, /*tolerance*/  1.0, /*accurancy*/ 0.0001);
	checkRayAiming_E0.push_back(ch00_inf_many_0);
	// *** *** //

	// *** angle y 0.5 *** //
	VectorStructR3 rayDirectionTS00_05 = Math::convertAngleInDirection(0.0, 0.5);

	VectorStructR3 targetPointTS00_05_0 = { 0.254 ,-0.249,20.0 };
	lightRay_interPoint_onTarget ch00_inf_05_0 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem00, /*ray direction*/ rayDirectionTS00_05, /*target point*/ targetPointTS00_05_0, /*light*/ light, /*accurancy*/ 0.0001);
	checkRayAiming_E0.push_back(ch00_inf_05_0.getOnTarget());
	bool checkDirection_E0_05_0 = checkDirection_inf(0.0, 0.5, ch00_inf_05_0.getLightRay().getRay_LLT().getDirectionRayUnit(), 0.001);
	checkRayAiming_E0.push_back(checkDirection_E0_05_0);

	VectorStructR3 targetPointTS00_05_1 = { 0.0 ,-0.8,20.0 };
	lightRay_interPoint_onTarget ch00_inf_05_1 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem00, /*ray direction*/ rayDirectionTS00_05, /*target point*/ targetPointTS00_05_1, /*light*/ light, /*accurancy*/ 0.0001);
	checkRayAiming_E0.push_back(ch00_inf_05_1.getOnTarget());
	bool checkDirection_E0_05_1 = checkDirection_inf(0.0, 0.5, ch00_inf_05_1.getLightRay().getRay_LLT().getDirectionRayUnit(), 0.001);
	checkRayAiming_E0.push_back(checkDirection_E0_05_1);

	VectorStructR3 targetPointTS00_05_2 = { 0.5 ,0.5,20.0 };
	lightRay_interPoint_onTarget ch00_inf_05_2 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem00, /*ray direction*/ rayDirectionTS00_05, /*target point*/ targetPointTS00_05_2, /*light*/ light, /*accurancy*/ 0.0001);
	checkRayAiming_E0.push_back(ch00_inf_05_2.getOnTarget());
	bool checkDirection_E0_05_2 = checkDirection_inf(0.0, 0.5, ch00_inf_05_2.getLightRay().getRay_LLT().getDirectionRayUnit(), 0.001);
	checkRayAiming_E0.push_back(checkDirection_E0_05_2);

	bool ch00_inf_many_05 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem00, /*ray direction*/ rayDirectionTS00_05, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 300.214, /*tolerance*/  1.0, /*accurancy*/ 0.0001);
	checkRayAiming_E0.push_back(ch00_inf_many_05);

	// *** angle x 0.5 / y 0.5 *** //
	VectorStructR3 rayDirectionTS00_05_05 = Math::convertAngleInDirection(0.5, 0.5);

	VectorStructR3 targetPointTS00_05_05_0 = { 0.3 ,-0.4,20.0 };
	lightRay_interPoint_onTarget ch00_inf_05_05_0 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem00, /*ray direction*/ rayDirectionTS00_05_05, /*target point*/ targetPointTS00_05_05_0, /*light*/ light,/*accurancy*/ 0.0001);
	checkRayAiming_E0.push_back(ch00_inf_05_05_0.getOnTarget());
	bool checkDirection_E0_05_05_0 = checkDirection_inf(0.5, 0.5, ch00_inf_05_05_0.getLightRay().getRay_LLT().getDirectionRayUnit(), 3);
	checkRayAiming_E0.push_back(checkDirection_E0_05_05_0);

	bool ch00_inf_many_05_05 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem00, /*ray direction*/ rayDirectionTS00_05_05, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 299.931, /*tolerance*/  1.0,/*accurancy*/ 0.0001);
	checkRayAiming_E0.push_back(ch00_inf_many_05_05);



	bool returnCheckerE0 = Math::checkTrueOfVectorElements(checkRayAiming_E0);
	return returnCheckerE0;

}

bool testRayAiming::checkRayAimingE1_inf()
{
	std::vector<bool> checkRayAiming_E1;

	//*** standard ***//
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

	bool checkSingleRay = checkRayTracing_inf(TestSystem01_DG, { 0.0,1.4006185992,0.0 }, 0.0, 0.0, 1.0, light, { 0.0,-0.02700151822,11.552572675 }, 11, 0.0001);

	VectorStructR3 targetPointTS1_0 = { -0.31 ,0.21,8.032206 };
	lightRay_interPoint_onTarget ch1_inf_0 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem01_DG, /*ray direction*/ rayDirectionTS1_1, /*target point*/ targetPointTS1_0, /*light*/ light, /*accurancy*/ 0.0001);
	checkRayAiming_E1.push_back(ch1_inf_0.getOnTarget());
	
	VectorStructR3 targetPointTS1_2 = { -0.39 ,0.21,8.032206 };
	lightRay_interPoint_onTarget ch1_inf_1 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem01_DG, /*ray direction*/ rayDirectionTS1_1, /*target point*/ targetPointTS1_2, /*light*/ light, /*accurancy*/ 0.0001);
	checkRayAiming_E1.push_back(ch1_inf_1.getOnTarget());
	
	bool ch1_inf_many_1_3 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem01_DG, /*ray direction*/ rayDirectionTS1_1, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 2.024, /*tolerance*/  0.1, /*accurancy*/ 0.0001);
	checkRayAiming_E1.push_back(ch1_inf_many_1_3);

	// *** angle x -0.5 / y -0.5 *** //
	VectorStructR3 rayDirectionTS01_neg05_neg05 = Math::convertAngleInDirection(-0.5, -0.5);
	
	VectorStructR3 targetPointTS1DG_05_05_0 = { 0.3 ,-0.4,8.032206 };
	lightRay_interPoint_onTarget ch1DG_inf_05_05_0 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem01_DG, /*ray direction*/ rayDirectionTS01_neg05_neg05, /*target point*/ targetPointTS1DG_05_05_0, /*light*/ light,/*accurancy*/ 0.0001);
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
	
	bool ch00_inf_many_neg05_neg05 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem01_DG, /*ray direction*/ rayDirectionTS01_neg05_neg05, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 2.204, /*tolerance*/  0.1,/*accurancy*/ 0.0001);
	checkRayAiming_E1.push_back(ch00_inf_many_neg05_neg05);
	
	// *** angle x 1.5 / y 0.5 *** //
	VectorStructR3 rayDirectionTS01_15_05 = Math::convertAngleInDirection(1.5, 0.5);
	VectorStructR3 targetPointTS1_15_05_0 = { 0.08682408883459026 ,1.0849515730271262e-12,8.0322060000000004 };
	lightRay_interPoint_onTarget ch1_inf_15_05 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem01_DG, /*ray direction*/ rayDirectionTS01_15_05, /*target point*/ targetPointTS1_15_05_0, /*light*/ light, /*accurancy*/ 0.0001);
	checkRayAiming_E1.push_back(ch1_inf_15_05.getOnTarget());

	
	bool ch00_inf_many_15_05 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem01_DG, /*ray direction*/ rayDirectionTS01_15_05, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 2.929, /*tolerance*/  0.1,/*accurancy*/ 0.0001);
	checkRayAiming_E1.push_back(ch00_inf_many_15_05);

	bool returnCheckerE1 = Math::checkTrueOfVectorElements(checkRayAiming_E1);
	return returnCheckerE1;

}


bool testRayAiming::checkRayAimingE2_inf()
{
	std::vector<bool> checkRayAiming_E2;

	//*** standard ***//
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
	SphericalSurface_LLT SphericalSurfaceTS02_0(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,10.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	// 2 surface
	SphericalSurface_LLT SphericalSurfaceTS02_1(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,11.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	// 3 surface
	SphericalSurface_LLT SphericalSurfaceTS02_2(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,12.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 4 surface
	SphericalSurface_LLT SphericalSurfaceTS02_3(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,13.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
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

	bool checkSingleRay = checkRayTracing_inf(TestSystem02, { 0.0,1.5161367647,0.0 }, 0.0, 0.0, 1.0, light, { 0.0,-0.5536520483,24.0 }, 5, 0.0001);
	checkRayAiming_E2.push_back(checkSingleRay);

	// ***********************************
	// ray aiming with test system 1 with rays from infinity !!!
	// ***********************************
	// *** direction Z = 1 *** //
	VectorStructR3 rayDirectionTS2_1 = { 0.0,0.0,1.0 };
	

	VectorStructR3 targetPointTS2_0 = { -0.7 ,0.6,14.0 };
	lightRay_interPoint_onTarget ch2_inf_0 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem02, /*ray direction*/ rayDirectionTS2_1, /*target point*/ targetPointTS2_0, /*light*/ light, /*accurancy*/ 0.0001);
	checkRayAiming_E2.push_back(ch2_inf_0.getOnTarget());
	
	VectorStructR3 targetPointTS2_2 = { -0.3 ,0.1,14.0 };
	lightRay_interPoint_onTarget ch2_inf_1 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem02, /*ray direction*/ rayDirectionTS2_1, /*target point*/ targetPointTS2_2, /*light*/ light, /*accurancy*/ 0.0001);
	checkRayAiming_E2.push_back(ch2_inf_1.getOnTarget());
	
	bool ch2_inf_many_1 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem02, /*ray direction*/ rayDirectionTS2_1, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 386.763, /*tolerance*/  0.1, /*accurancy*/ 0.0001);
	checkRayAiming_E2.push_back(ch2_inf_many_1);
	
	// *** angle x -1.0 / y 2.0 *** //
	VectorStructR3 rayDirectionTS02_neg1_2 = Math::convertAngleInDirection(-1.0, 2.0);
	
	VectorStructR3 targetPointTS2_neg1_2 = { 0.8 ,-0.2,14.0 };
	lightRay_interPoint_onTarget ch2_inf_neg1_2 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem02, /*ray direction*/ rayDirectionTS02_neg1_2, /*target point*/ targetPointTS2_neg1_2, /*light*/ light,/*accurancy*/ 0.0001);
	checkRayAiming_E2.push_back(ch2_inf_neg1_2.getOnTarget());
	
	bool ch2_inf_many_neg1_2 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem02, /*ray direction*/ rayDirectionTS02_neg1_2, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 391.278, /*tolerance*/  0.1,/*accurancy*/ 0.0001);
	checkRayAiming_E2.push_back(ch2_inf_many_neg1_2);

	// *** angle x 1.5 / y -0.5 *** //
	VectorStructR3 rayDirectionTS2_15_neg05 = Math::convertAngleInDirection(1.5, -0.5);
	bool ch2_inf_many_15_05 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem02, /*ray direction*/ rayDirectionTS2_15_neg05, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 389.017, /*tolerance*/  0.1,/*accurancy*/ 0.0001);
	checkRayAiming_E2.push_back(ch2_inf_many_15_05);

	bool returnCheckerE2 = Math::checkTrueOfVectorElements(checkRayAiming_E2);
	return returnCheckerE2;
}


bool testRayAiming::checkRayAimingE3_inf()
{
	std::vector<bool> checkRayAiming_E3;

	//*** standard ***//
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
	bool ch3_inf_many_1 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem03, /*ray direction*/ rayDirectionTS3_1, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 195.275, /*tolerance*/  0.1, /*accurancy*/ 0.0001);
	checkRayAiming_E3.push_back(ch3_inf_many_1);

	// *** angle x 1.5 / y 2.0 *** //
	VectorStructR3 rayDirectionTS02_15_2 = Math::convertAngleInDirection(1.5, 2.0);
	bool ch3_inf_many_15_2 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem03, /*ray direction*/ rayDirectionTS02_15_2, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 198.574, /*tolerance*/  0.1,/*accurancy*/ 0.0001);
	checkRayAiming_E3.push_back(ch3_inf_many_15_2);

	// *** angle x 1.2 / y -1.3 *** //
	VectorStructR3 rayDirectionTS2_12_neg13 = Math::convertAngleInDirection(1.2, -1.3);
	bool ch3_inf_many_12_neg13 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem03, /*ray direction*/ rayDirectionTS2_12_neg13, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 196.924, /*tolerance*/  0.1,/*accurancy*/ 0.0001);
	checkRayAiming_E3.push_back(ch3_inf_many_12_neg13);


	bool returnCheckerE3 = Math::checkTrueOfVectorElements(checkRayAiming_E3);
	return returnCheckerE3;

}

bool testRayAiming::checkRayAimingE4_inf()
{
	std::vector<bool> checkRayAiming_E4;

	//*** standard ***//
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
	SphericalSurface_LLT SphericalSurfaceTS4_0(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,15.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 1 surface
	SphericalSurface_LLT SphericalSurfaceTS4_1(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,17.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 2 surface
	SphericalSurface_LLT SphericalSurfaceTS4_2(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,27.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 3 surface
	SphericalSurface_LLT SphericalSurfaceTS4_3(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,29.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 4 surface
	ApertureStop_LLT AperturStopTS4_4{/*semiHeight*/ 1.1, /*Apex*/{ 0.0,0.0,32.0 },/*direction*/ { 0.0,0.0,1.0 },
		/*refIndex*/ 1.0 };
	// 5 surface
	SphericalSurface_LLT SphericalSurfaceTS4_5(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,35.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	// 6 surface
	SphericalSurface_LLT SphericalSurfaceTS4_6(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,37.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	// 7 surface
	PlanGeometry_LLT PlanSurfaceTS4_7(/*semiHeight*/ 4.0, /*Apex*/{ 0.0,0.0,42.0 }, /*Direction*/{ 0.0,0.0,1.0 },
		/*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);

	// build the optical system
	TestSystem4.fillVectorSurfaceAndInteractingData(0, &SphericalSurfaceTS4_0, refrac.clone());
	TestSystem4.fillVectorSurfaceAndInteractingData(1, &SphericalSurfaceTS4_1, refrac.clone());
	TestSystem4.fillVectorSurfaceAndInteractingData(2, &SphericalSurfaceTS4_2, refrac.clone());
	TestSystem4.fillVectorSurfaceAndInteractingData(3, &SphericalSurfaceTS4_3, refrac.clone());
	TestSystem4.fillVectorSurfaceAndInteractingData(4, &AperturStopTS4_4, doNothing.clone());
	TestSystem4.fillVectorSurfaceAndInteractingData(5, &SphericalSurfaceTS4_5, refrac.clone());
	TestSystem4.fillVectorSurfaceAndInteractingData(6, &SphericalSurfaceTS4_6, refrac.clone());
	TestSystem4.fillVectorSurfaceAndInteractingData(7, &PlanSurfaceTS4_7, absorb.clone());

	// ***********************************
	// ray aiming with test system 1 with rays from infinity !!!
	// ***********************************
	// *** direction Z = 1 *** //
	VectorStructR3 rayDirectionTS4_1 = { 0.0,0.0,1.0 };
	bool ch4_inf_many_1 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem4, /*ray direction*/ rayDirectionTS4_1, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 187.740, /*tolerance*/  0.1, /*accurancy*/ 0.0001);
	checkRayAiming_E4.push_back(ch4_inf_many_1);

	// *** angle x -0.3 / y 0.6 *** //
	VectorStructR3 rayDirectionTS02_neg03_06 = Math::convertAngleInDirection(-0.3, 0.6);
	bool ch3_inf_many_neg03_06 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem4, /*ray direction*/ rayDirectionTS02_neg03_06, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 187.418, /*tolerance*/  0.1,/*accurancy*/ 0.0001);
	checkRayAiming_E4.push_back(ch3_inf_many_neg03_06);

	// *** angle x -0.9 / y -0.3 *** //
	VectorStructR3 rayDirectionTS2_neg09_neg03 = Math::convertAngleInDirection(0.9, -0.3);
	bool ch3_inf_many_neg09_neg03 = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem4, /*ray direction*/ rayDirectionTS2_neg09_neg03, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 187.096, /*tolerance*/  0.1,/*accurancy*/ 0.0001);
	checkRayAiming_E4.push_back(ch3_inf_many_neg09_neg03);


	bool returnCheckerE4 = Math::checkTrueOfVectorElements(checkRayAiming_E4);
	return returnCheckerE4;

}

bool testRayAiming::checkRayAimingE5_inf()
{
	std::vector<bool> checkRayAiming_E5;

	//*** standard ***//
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

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// surfaces E5
	SphericalElement Sphere0_E5(/*radius*/ 80.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ 1.0, /*refractive index B*/1.67);
	SphericalElement Sphere1_E5(/*radius*/ 70.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ 1.0, /*refractive index B*/1.67);
	SphericalElement Sphere2_E5(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ 1.0, /*refractive index B*/1.81);
	SphericalElement Sphere3_E5(/*radius*/ 35.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ 1.52, /*refractive index B*/1.81);
	SphericalElement Sphere4_E5(/*radius*/ 20.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ 1.0, /*refractive index B*/1.52);
	ApertureStopElement AperStop5_E5(/* semi height*/1.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/1.0);
	PlanElement Plan6_E5(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ 1.0, /*refractive index B*/ 1.0);

	Sphere1_E5.setParameterPointZ(0.01, 20.0, 0.0, typeModifierVariable);
	Sphere2_E5.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere4_E5.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);

	surfacePtr Sphere0_E5_ptr = Sphere0_E5.clone();
	surfacePtr Sphere1_E5_ptr = Sphere1_E5.clone();
	surfacePtr Sphere2_E5_ptr = Sphere2_E5.clone();
	surfacePtr Sphere3_E5_ptr = Sphere3_E5.clone();
	surfacePtr Sphere4_E5_ptr = Sphere4_E5.clone();
	surfacePtr AperStop5_E5_ptr = AperStop5_E5.clone();
	surfacePtr Plan6_E5_ptr = Plan6_E5.clone();

	std::vector<surfacePtr> opticalSystem_E5_ptr{Sphere0_E5_ptr, Sphere1_E5_ptr, Sphere2_E5_ptr , Sphere3_E5_ptr, Sphere4_E5_ptr, AperStop5_E5_ptr, Plan6_E5_ptr };
	std::vector<interactionPtr> interactions_E5_ptr{refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), doNothing.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E5(opticalSystem_E5_ptr, interactions_E5_ptr);
	//optSystemElement_E5.setRefractiveIndexAccordingToWavelength(587.5618);

	OpticalSystem_LLT optSys_LLT_E5 = optSystemElement_E5.getLLTconversion_doConversion();
	optSys_LLT_E5.printAllOptSysParameter_LLT(optSys_LLT_E5);
	

	// *** angle x 0 / y 0 *** //
	VectorStructR3 rayDirection00 = Math::convertAngleInDirection(0.0, 0.0);
	bool ch_inf_many_00 = checkRayAimingManyRay_inf(/*opt sys LLT*/ optSys_LLT_E5, /*ray direction*/ rayDirection00, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 24.806, /*tolerance*/  0.1,/*accurancy*/ 0.00001);
	checkRayAiming_E5.push_back(ch_inf_many_00);
	
	/// *** angle x 0 / y 1 *** //
	VectorStructR3 rayDirection01 = Math::convertAngleInDirection(0.0, 1.0);
	bool ch_inf_many_01 = checkRayAimingManyRay_inf(/*opt sys LLT*/ optSys_LLT_E5, /*ray direction*/ rayDirection01, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 41.032, /*tolerance*/  0.1,/*accurancy*/ 0.00001);
	checkRayAiming_E5.push_back(ch_inf_many_01);
	
	/// *** angle x 0 / y 0.5 *** //
	VectorStructR3 rayDirection0_05 = Math::convertAngleInDirection(0.0, 0.5);
	bool ch_inf_many_0_05 = checkRayAimingManyRay_inf(/*opt sys LLT*/ optSys_LLT_E5, /*ray direction*/ rayDirection0_05, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 28.496, /*tolerance*/  0.1,/*accurancy*/ 0.00001);
	checkRayAiming_E5.push_back(ch_inf_many_0_05);
	
	/// *** angle x 0 / y 1.5 *** //
	VectorStructR3 rayDirection0_15 = Math::convertAngleInDirection(0.0, 1.5);
	bool ch_inf_many_0_15 = checkRayAimingManyRay_inf(/*opt sys LLT*/ optSys_LLT_E5, /*ray direction*/ rayDirection0_15, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 66.019, /*tolerance*/  0.1,/*accurancy*/ 0.00001);
	checkRayAiming_E5.push_back(ch_inf_many_0_15);
	
	///// *** angle x 0 / y 1.8 *** //
	VectorStructR3 rayDirection0_18 = Math::convertAngleInDirection(0.0, 1.8);
	bool ch_inf_many_0_18 = checkRayAimingManyRay_inf(/*opt sys LLT*/ optSys_LLT_E5, /*ray direction*/ rayDirection0_18, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 89.905, /*tolerance*/  0.1,/*accurancy*/ 0.00001);
	checkRayAiming_E5.push_back(ch_inf_many_0_18);
	
	///// *** angle x 0 / y 1.8 *** //
	VectorStructR3 rayDirection0_185 = Math::convertAngleInDirection(0.0, 1.85);
	bool ch_inf_many_0_185 = checkRayAimingManyRay_inf(/*opt sys LLT*/ optSys_LLT_E5, /*ray direction*/ rayDirection0_185, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 94.817, /*tolerance*/  0.1,/*accurancy*/ 0.00001);
	checkRayAiming_E5.push_back(ch_inf_many_0_185);
	
	///// *** angle x 0 / y 1.89 *** //
	VectorStructR3 rayDirection0_189 = Math::convertAngleInDirection(0.0, 1.89);
	bool ch_inf_many_0_189 = checkRayAimingManyRay_inf(/*opt sys LLT*/ optSys_LLT_E5, /*ray direction*/ rayDirection0_189, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 98.986, /*tolerance*/  0.1,/*accurancy*/ 0.00001);
	checkRayAiming_E5.push_back(ch_inf_many_0_189);

	// ** attention ** // both rays have the same direction by a differece origin. Both go through the same point in the aperture stop!
	// ** single ray tracing ** //
	bool singleRayTrace1 = oftenUse::checkRayTracing({ -1.085793283,-9.931626278,-1.0 }, { 0.0,0.033155178,0.999450216 }, { -0.173648178,-0.984807753,35.0 }, optSys_LLT_E5, 5, 0.1);
	checkRayAiming_E5.push_back(singleRayTrace1);
	// ** single ray tracing ** //
	bool singleRayTrace2 = oftenUse::checkRayTracing({ -0.70721649967,-6.560404639,-1.0 }, { 0.0,0.033155178,0.999450216 }, { -0.173648178,-0.984807753,35.0 }, optSys_LLT_E5, 5, 0.1);
	checkRayAiming_E5.push_back(singleRayTrace2);

	///// *** angle x 0 / y 2.0 *** //
	VectorStructR3 rayDirection0_2 = Math::convertAngleInDirection(0.0, 2.0);
	bool ch_inf_many_0_2 = checkRayAimingManyRay_inf(/*opt sys LLT*/ optSys_LLT_E5, /*ray direction*/ rayDirection0_2, /*rings*/ rings,/*arms*/ arms,/*light*/ light,  /*compare rms*/ 111.727, /*tolerance*/  0.1,/*accurancy*/ 0.00001);
	checkRayAiming_E5.push_back(ch_inf_many_0_2);

	bool returnCheckerE5 = Math::checkTrueOfVectorElements(checkRayAiming_E5);
	return returnCheckerE5;

}



	
	


	
	
	






lightRay_interPoint_onTarget testRayAiming::checkRayAimingSingleRay_inf(/*opt sys LLT*/ OpticalSystem_LLT& const optSys_LLT, /*ray direction*/ VectorStructR3& const rayDirection, /*target point*/ VectorStructR3& const  targetPoint, /*light*/ Light_LLT& const Light, /*accurency*/ real accurency)
{

	RayAiming RayAiming(optSys_LLT);
	RayAiming.setTolerance_XandY(accurency);
	RayAiming.setFactorStartHeight_inf(0.1);

	LightRayStruct testLightRay = RayAiming.rayAiming_inf(rayDirection, targetPoint, Light, 1.0);
	SequentialRayTracing seqTrace(optSys_LLT);
	seqTrace.sequentialRayTracing(testLightRay);
	VectorStructR3 checkerPoint = seqTrace.getAllInterPointsAtSurf_i_notFiltered(RayAiming.getPositionApertureStop(optSys_LLT)).at(0);
	real disX = RayAiming.calcDistance_X(targetPoint, checkerPoint);
	real disY = RayAiming.calcDistance_Y(targetPoint, checkerPoint);

	bool checkDisX = std::abs(disX) <= RayAiming.getDefaultParameters().getTolerance_XandY();
	bool checkDisY = std::abs(disY) <= RayAiming.getDefaultParameters().getTolerance_XandY();

	bool onTarget = checkDisX && checkDisY;

	lightRay_interPoint_onTarget returnLR_IP_OT(testLightRay, checkerPoint, onTarget);

	return returnLR_IP_OT;
}

bool testRayAiming::checkRayAimingManyRay_inf(/*opt sys LLT*/ OpticalSystem_LLT& const optSys_LLT, /*ray direction*/ VectorStructR3& const rayDirection, /*rings*/ unsigned int& const ringsAB,/*arms*/ unsigned int& const armsAB,/*light*/ Light_LLT& const Light, /*compare rms*/ real checkRMS, real tolerance, real accurancy)
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

	// check all intersection points at the aperture stop
	for (unsigned int i = 0; i < pointsInApStop.size(); i++)
	{
		////just for debugging!
		//int j = 0;
		//if (i == 126)
		//{
		//	j = 1;
		//}

		checker = checkRayAimingSingleRay_inf(/*opt sys LLT*/ optSys_LLT, /*ray direction*/ rayDirection, /*target point*/ pointsInApStop[i], /*light*/ Light, accurancy);

		if (checker.getOnTarget() == false)
		{
			// just for debugging
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
	std::vector<VectorStructR3> allInterPointsLastSurface = seqTraceForRMS.getAllInterPointsAtSurface_i_filtered(posLastSurface);
	VectorStructR3 refPointLastSurface = seqTraceForRMS.getAllInterPointsAtSurface_i_filtered(posLastSurface)[0];

	//// *** test *** ///
	//std::vector<VectorStructR3> test;
	//std::copy(allInterPointsLastSurface.begin(), allInterPointsLastSurface.end() - 1, std::back_inserter(test));

	Spot Spot(allInterPointsLastSurface, refPointLastSurface);
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
	cheker_vec.push_back(checkDirection);

	return Math::checkTrueOfVectorElements(cheker_vec);

}

bool testRayAiming::checkStartPointRay(LightRayStruct lightRay, VectorStructR3 checkStartPoint, real tolerance)
{
	VectorStructR3 startPointTOM = lightRay.getRay_LLT().getOriginRay();

	bool returnChecker = Math::compareTwoVectorStructR3_tolerance(checkStartPoint, startPointTOM, tolerance);

	return returnChecker;
}

bool testRayAiming::checkDirection_inf(real targetAngel_X, real targetAngle_Y, VectorStructR3 direction, real tolerance)
{

	twoVaulesReal angelX_Y = Math::convertDirectionInAngle(direction);

	bool checkAngle_X = Math::compareTwoNumbers_tolerance(angelX_Y.getVal_1(), targetAngel_X, tolerance);
	bool checkAngle_Y = Math::compareTwoNumbers_tolerance(angelX_Y.getVal_2(), targetAngle_Y, tolerance);

	return checkAngle_X && checkAngle_Y;

}

bool testRayAiming::checkDirectionManyLightRay_inf(real targetAngel_X, real targetAngle_Y, std::vector<LightRayStruct> lightRayVec, real tolerance)
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

bool testRayAiming::checkRayTracing_inf(OpticalSystem_LLT optSys_LLT, VectorStructR3 origin, real angle_X, real angle_Y, real refIndex, Light_LLT light, VectorStructR3 targetPoint, unsigned int posSurface, real tolerance)
{
	SequentialRayTracing seqTrace(optSys_LLT);

	// build the light ray
	VectorStructR3 direction = Math::convertAngleInDirection(angle_X, angle_Y);
	Ray_LLT ray(origin, direction, refIndex);
	LightRayStruct lightRay(light, ray, 1);

	// trace the ray
	seqTrace.sequentialRayTracing(lightRay);

	//unsigned int posAperStop = optSys_LLT.getPosApertureStop();

	VectorStructR3 intersecPointAS = seqTrace.getAllInterPointsAtSurf_i_notFiltered(posSurface)[0];

	bool checkInterPoint = Math::compareTwoVectorStructR3_tolerance(targetPoint, intersecPointAS, tolerance);

	return checkInterPoint;

}

lightRay_interPoint_onTarget testRayAiming::checkRayAimingSingleRay_obj(/*opt sys LLT*/ OpticalSystem_LLT& const optSys_LLT, /*ray origin*/ VectorStructR3& const rayOrigin, /*target point*/ VectorStructR3& const  targetPoint, /*light*/ Light_LLT& const Light, /*accurency*/ real accurency)
{
	RayAiming RayAiming(optSys_LLT);
	RayAiming.setTolerance_XandY(accurency);
	////VectorStructR3 rayDirectionTS00_2 = { 0.0,0.0,1.0 };
	//VectorStructR3 targetPointTS00_2 = { 0.7 ,-0.02,20.0 };
	LightRayStruct testLightRay = RayAiming.rayAiming_obj(rayOrigin, targetPoint, Light, 1.0);

	unsigned int posApertureStop = RayAiming.getPositionApertureStop(optSys_LLT);
	surfaceSide surSide{};
	bool onTarget{};
	VectorStructR3 checkerPoint{};

	if (testLightRay.getIsAlive() == true) // light ray is alive
	{
		SequentialRayTracing seqTrace(optSys_LLT);
		seqTrace.sequentialRayTracing(testLightRay);

		surSide = seqTrace.getAllInterInfosOfSurf_i_notFiltered(posApertureStop).at(0).getSurfaceSide();
		if (surSide != N)
		{
			checkerPoint = seqTrace.getAllInterPointsAtSurface_i_filtered(posApertureStop).at(0);
			real disX = RayAiming.calcDistance_X(targetPoint, checkerPoint);
			real disY = RayAiming.calcDistance_Y(targetPoint, checkerPoint);

			bool checkDisX = std::abs(disX) <= RayAiming.getDefaultParameters().getTolerance_XandY();
			bool checkDisY = std::abs(disY) <= RayAiming.getDefaultParameters().getTolerance_XandY();

			onTarget = checkDisX && checkDisY;
		}
		
		else // ray aiming is not psooible 
		{
			testLightRay.setLightRayAbsorb();
			checkerPoint = { 999.0, 999.0, 999.0 };
			onTarget = false;
		}




		lightRay_interPoint_onTarget returnLR_IP_OT(testLightRay, checkerPoint, onTarget);

		return returnLR_IP_OT;
	}
	
	else // light ray is death
	{
		lightRay_interPoint_onTarget returnLR_IP_OT;

		LightRayStruct deathLightRay;
		deathLightRay.setLightRayAbsorb();
		returnLR_IP_OT.setLightRay(deathLightRay);
		returnLR_IP_OT.setIntersectionPoint({ -999.0,-999.0,-999.0 });
		returnLR_IP_OT.setOnTarget(false);

		return returnLR_IP_OT;
	}
	

}

bool testRayAiming::checkRayAimingManyRay_obj(/*opt sys LLT*/ OpticalSystem_LLT& const optSys_LLT, /*ray origin*/ VectorStructR3& const rayOrigin, /*rings*/ unsigned int const ringsAB,/*arms*/ unsigned int const armsAB,/*light*/ Light_LLT& const Light, /*compare rms*/ real checkRMS, real tolerance, real accurancy)
{
	

	// find position aperture stop in opt sys
	unsigned int posApertureStop = optSys_LLT.getPosApertureStop();
	// get semi height aberture stop
	real semiHeightApertureStop = optSys_LLT.getPosAndInteractingSurface()[posApertureStop].getSurfaceInterRay_ptr()->getSemiHeight();
	// get point of aperture stop
	VectorStructR3 pointApertureStop = optSys_LLT.getPosAndInteractingSurface()[posApertureStop].getSurfaceInterRay_ptr()->getPoint();
	// get direction aperture stop
	VectorStructR3 directionApertureStop = optSys_LLT.getPosAndInteractingSurface()[posApertureStop].getSurfaceInterRay_ptr()->getDirection();

	// Ray Aiming from obj
	SequentialRayTracing seqTrace(optSys_LLT);
	LightRayStruct testLightRay;
	std::vector<bool> cheker_vec;
	//std::vector<VectorStructR3> interPoints05_5;
	FillApertureStop fillAperStop;
	std::vector<VectorStructR3> pointsInApStop = fillAperStop.fillAS_withPoints(ringsAB, pointApertureStop, directionApertureStop, semiHeightApertureStop);

	std::vector<LightRayStruct> lightRays_vec;
	lightRay_interPoint_onTarget checker;
	VectorStructR3 tempTargetPoint;

	unsigned int sizePointsInApStop = pointsInApStop.size();
	real maxFailedAimedPoints = sizePointsInApStop / 50.0;

	real tempDir_X{};
	real tempDir_Y{};
	real tempDir_Z{};
	bool tempIsAlive{};

	unsigned int faildRayAimingCounter = 0;

	// check all intersectio points at the aperture stop
	for (unsigned int i = 0; i < sizePointsInApStop; i++)
	{
		//// just for debugging!
		//int j = 0;
		//if (i == 96)
		//{
		//	j = 1;
		//	std::cout << "j = " << j << std::endl;
		//}
		tempTargetPoint = pointsInApStop[i];
		checker = checkRayAimingSingleRay_obj(/*opt sys LLT*/ optSys_LLT, /*ray origin*/ rayOrigin, /*target point*/ tempTargetPoint, /*light*/ Light, accurancy);

		if (checker.getOnTarget() == false)
		{
			tempDir_X = checker.getLightRay().getRay_LLT().getDirectionRayUnit().getX();
			tempDir_Y = checker.getLightRay().getRay_LLT().getDirectionRayUnit().getY();
			tempDir_Z = checker.getLightRay().getRay_LLT().getDirectionRayUnit().getZ();
			tempIsAlive = checker.getLightRay().getIsAlive();

			if (tempDir_X == 0.0 && tempDir_Y == 0.0 && tempDir_Z == 0.0 && tempIsAlive==false)
			{
				// ray Aiming is not possible 
				cheker_vec.push_back(true);
			}
			
			else
			{
				++faildRayAimingCounter;

				if (faildRayAimingCounter > maxFailedAimedPoints)
				{
					// just for debugging
					std::cout << "target point: " << std::endl;
					pointsInApStop[i].print();
					std::cout << "point by ray tracing: " << i << std::endl;

					cheker_vec.push_back(false);
				}

				else
				{
					cheker_vec.push_back(true);
				}
				
			}


		}

		else
		{
			cheker_vec.push_back(checker.getOnTarget());
			lightRays_vec.push_back(checker.getLightRay());

		}

	}

	// just for debugging
	optSys_LLT.printAllOptSysParameter_LLT(optSys_LLT);

	// check rms on image surface
	unsigned int posLastSurface = optSys_LLT.getPosAndInteractingSurface().size() - 1;
	SequentialRayTracing seqTraceForRMS(optSys_LLT);
	seqTraceForRMS.seqRayTracingWithVectorOfLightRays(lightRays_vec);
	Spot spot(seqTraceForRMS.getAllInterPointsAtSurface_i_filtered(posLastSurface), seqTraceForRMS.getAllInterPointsAtSurface_i_filtered(posLastSurface)[0]);
	real rmsTOM = spot.getRMS_µm();
	
	unsigned int sizeAimedLightRay = lightRays_vec.size();

	if (sizeAimedLightRay == sizePointsInApStop) // we aimed all points in the aperture stop
	{
		bool checkRMS_bool = std::abs(rmsTOM - checkRMS) < tolerance;
		cheker_vec.push_back(checkRMS_bool);
	}
	
	

	// check for vignetting
	unsigned int sizeFilterInterPoint = seqTraceForRMS.getAllInterInfosOfSurf_i(posLastSurface).size();
	unsigned int sizeNotFilterInterPoint = seqTraceForRMS.getAllInterInfosOfSurf_i_notFiltered(posLastSurface).size();
	bool checkVignetting = sizeFilterInterPoint == sizeNotFilterInterPoint;
	cheker_vec.push_back(checkVignetting);


	// check all origins
	bool checkOrigin = checkStartPointRayMany(lightRays_vec, rayOrigin, tolerance);

	return Math::checkTrueOfVectorElements(cheker_vec);

}


bool testRayAiming::checkStartPointRayMany(std::vector<LightRayStruct> lightRay_vec, VectorStructR3 checkStartPoint, real tolerance)
{

	unsigned int sizeLightRay = lightRay_vec.size();

	LightRayStruct tempLightRay;
	std::vector<bool> checker_vec;
	checker_vec.resize(sizeLightRay);
	bool tempChecker;

	for (unsigned int i = 0; i < sizeLightRay; ++i)
	{
		tempLightRay = lightRay_vec[i];
		tempChecker = checkStartPointRay(tempLightRay, checkStartPoint, tolerance);

		checker_vec[i] = tempChecker;
	}

	bool returnChecker = Math::checkTrueOfVectorElements(checker_vec);

	return returnChecker;

}