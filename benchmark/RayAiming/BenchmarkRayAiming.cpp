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

// Für timer, später löschen:
#include <iostream>
#include <cstdio>
#include <ctime>

bool BenchmarkRayAiming::checkRayAimingSuperFct()
{
	std::vector<bool> checkRayAiming_SuperFct;
	// E0
	bool checkE0 = checkRayAimingE0();
	checkRayAiming_SuperFct.push_back(checkE0);




	bool returnCheckSuperFct = Math::checkTrueOfVectorElements(checkRayAiming_SuperFct);
	return returnCheckSuperFct;

}

// check ray aiming E0
bool BenchmarkRayAiming::checkRayAimingE0()
{
	std::vector<bool> checkRayAiming_E0;
	
	//*** standart ***//
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	unsigned int rings = 4;
	unsigned int arms = 6;
	real refIndexAir = 1.0;
	VectorStructR3 startRay0 = { 0.0,0.0,0.0 };
	VectorStructR3 startRay1 = { 0.0,1.0,0.0 };
	//*** ------  ***//

	// TestSystem00 ///////////////////////////////////////////////////
	OpticalSystem_LLT TestSystem00;

	// 0 surface
	SphericalSurface_LLT SphericalSurfaceTS00_0(/*radius*/9.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,15.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.7);
	// 1 surface
	SphericalSurface_LLT SphericalSurfaceTS00_1(/*radius*/9.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,17.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.7);
	// 2 surface
	ApertureStop_LLT AperturStopTS00_2{/*semiHeight*/ 0.8, /*Apex*/{ 0.0,0.0,20.0 },/*direction*/ { 0.0,0.0,20.0 },
		/*refIndex*/ 1.0 };
	// 3 surface
	PlanGeometry_LLT PlanSurfaceTS00_3(/*semiHeight*/ 4.0, /*Apex*/{ 0.0,0.0,23.0 }, /*Direction*/{ 0.0,0.0,1.0 },
		/*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);

	// build the optical system
	TestSystem00.fillVectorSurfaceAndInteractingData(0, &SphericalSurfaceTS00_0, refrac.clone());
	TestSystem00.fillVectorSurfaceAndInteractingData(1, &SphericalSurfaceTS00_1, refrac.clone());
	TestSystem00.fillVectorSurfaceAndInteractingData(2, &AperturStopTS00_2, doNothing.clone());
	TestSystem00.fillVectorSurfaceAndInteractingData(3, &PlanSurfaceTS00_3, absorb.clone());

//	// Object 0
//	VectorStructR3 startPoint00_0{ 0.0,0.0,0.0 };
//	VectorStructR3 targetPoint00_0{ 0.4,-0.399,20.0 };
//	bool ch00_obj_0 = checkRayAimingSingleRay_obj(TestSystem00, startPoint00_0, targetPoint00_0, light);
//	checkRayAiming_E0.push_back(ch00_obj_0);
//	
//	// Field
//	VectorStructR3 startPoint00_01{ 0.0,0.5,0.0 };
//	VectorStructR3 targetPoint00_1{ -0.145,0.356,20.0 };
//	bool ch00_obj_1 = checkRayAimingSingleRay_obj(TestSystem00, startPoint00_01, targetPoint00_1, light);
//	checkRayAiming_E0.push_back(ch00_obj_1);
//
//	// many ray	
//	bool cTS00_0_obj = checkRayAimingManyRay_obj(TestSystem00, startRay0, rings, arms, refIndexAir, light);
//	checkRayAiming_E0.push_back(cTS00_0_obj);
//	bool cTS00_1_obj = checkRayAimingManyRay_obj(TestSystem00, startRay1, rings, arms, refIndexAir, light);
//	checkRayAiming_E0.push_back(cTS00_1_obj);

	
	//// ***********************************
	//// ray aiming with test system 0 with rays from infinity !!!
	//// ***********************************

	VectorStructR3 rayDirectionTS00_1 = { 0.0,0.0,1.0 };

	//VectorStructR3 targetPointTS00_0 = { 0.7 ,-0.02,20.0 };
	//bool ch00_inf_0 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem00, /*ray direction*/ rayDirectionTS00_1, /*target point*/ targetPointTS00_0, /*light*/ light);
	//checkRayAiming_E0.push_back(ch00_inf_0);

	VectorStructR3 targetPointTS00_1 = { -0.4 ,-0.69282,20.0 };
	bool ch00_inf_1 = checkRayAimingSingleRay_inf(/*opt sys LLT*/TestSystem00, /*ray direction*/ rayDirectionTS00_1, /*target point*/ targetPointTS00_1, /*light*/ light);
	checkRayAiming_E0.push_back(ch00_inf_1);

	bool ch00_inf_many = checkRayAimingManyRay_inf(/*opt sys LLT*/ TestSystem00, /*ray direction*/ rayDirectionTS00_1, /*rings*/ rings,/*arms*/ arms,/*light*/ light);
	checkRayAiming_E0.push_back(ch00_inf_many);

	
	
	
	
	
	// Ray Aiming from infinity   
	RayAiming checkRayAimingTS00_2(TestSystem00);
	SequentialRayTracing seqTrace00_2(TestSystem00);
	VectorStructR3 rayDirection00_2 = { 0.0,0.0,1.0 };
	LightRayStruct testLightRay00_2_inf;
	VectorStructR3 checkTS00_2;
	std::vector<bool> bool00_2;
	std::vector<VectorStructR3> interPoints00_1;
	real semiHeightTest00_0 = 0.8;
	VectorStructR3 apexAperture00_0{ 0.0,0.0,20.0 };
	FillApertureStop fillAperStopRayAiming00_3;
	std::vector<VectorStructR3> pointsInApStopTS00_3 = fillAperStopRayAiming00_3.fillAS_withPointsDithered(5, apexAperture00_0, { 0.0,0.0,1.0 }, semiHeightTest00_0);
	FillApertureStop fillAperStopRayAiming00_2;
	std::vector<VectorStructR3> pointsInApStopTS00_2 = fillAperStopRayAiming00_2.fillAS_withPointsSquare(5, apexAperture00_0, { 0.0,0.0,1.0 }, semiHeightTest00_0);
	FillApertureStop fillAperStopRayAiming00_4;
	std::vector<VectorStructR3> pointsInApStopTS00_1 = fillAperStopRayAiming00_4.fillAS_withPoints(5, apexAperture00_0, { 0.0,0.0,1.0 }, semiHeightTest00_0);
	
	//std::clock_t start1;
	//double duration1;
	//start1 = std::clock();
	//duration1 = (std::clock() - start1) / (double)CLOCKS_PER_SEC;
	//std::cout << "printf2: " << duration1 << '\n';
	
	//for (unsigned int i = 0; i < pointsInApStopTS00_1.size(); i++)
	//{
	//	testLightRay00_2_inf = checkRayAimingTS00_2.infinityRayAiming(rayDirection00_2, pointsInApStopTS00_1.at(i), light, 1.0);
	//	seqTrace00_2.sequentialRayTracing(testLightRay00_2_inf);
	//	checkTS00_2 = seqTrace00_2.getAllInterPointsAtSurf_i(checkRayAimingTS00_2.getPositionApertureStop(TestSystem00)).at(i);
	//	interPoints00_1.push_back(checkTS00_2);
	//	cTS00_0_obj = Math::compareTwoVectorStructR3(pointsInApStopTS00_1.at(i), checkTS00_2, 4);
	//	bool00_2.push_back(cTS00_0_obj);
	//
	//}
	
	//std::cout << '\n' << "Duration Objekt: " << duration0 << '\n';
	//std::cout << "RMS Objekt: " << rmsTS00_0 << '\n';
	
	//duration1 = (std::clock() - start1) / (double)CLOCKS_PER_SEC;
	//std::cout << '\n' << "Duration infinity: " << duration1 << '\n';
	//
	//Spot spotTS00_2;
	//real rmsTS00_2 = spotTS00_1.calcRMS(seqTrace00_2.getAllInterPointsAtSurf_i(3), seqTrace00_2.getAllInterPointsAtSurf_i(3).at(0)) * 1000;
	//
	//std::cout << "RMS Infinity: " << rmsTS00_1 << '\n';
	//
	bool returnCheckerE0 = Math::checkTrueOfVectorElements(checkRayAiming_E0);
	return returnCheckerE0;

}

// check methodes of class ParaxialLens_LLT
bool  BenchmarkRayAiming::checkMethodesRayAiming()
{
	std::vector<bool> checkRayAiming;
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);



	// TestSystem08 ///////////////////////////////////////////////////
	// Für INtensität/Winkel-Test
	OpticalSystem_LLT TestSystem08;
	
	// 0 surface
	SphericalSurface_LLT SphericalSurfaceTS08_0(/*radius*/10.0, /*semiHeight*/1.5, /*Apex of the sphere*/{ 0.0,0.0,1.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.8);
	// 1 surface
	SphericalSurface_LLT SphericalSurfaceTS08_1(/*radius*/10.0, /*semiHeight*/2.0, /*Apex of the sphere*/{ 0.0,0.0,2.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.8);
	// 2 surface
	ApertureStop_LLT AperturStopTS08_2{/*semiHeight*/ 0.82, /*Apex*/{ 0.0,0.0,4.0 },/*direction*/ { 0.0,0.0,1.0 },
		/*refIndex*/ 1.0 };
	// 3 surface
	PlanGeometry_LLT PlanSurfaceTS08_3(/*semiHeight*/ 4.0, /*Apex*/{ 0.0,0.0,6.0 }, /*Direction*/{ 0.0,0.0,1.0 },
		/*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);
	
	// build the optical system
	TestSystem08.fillVectorSurfaceAndInteractingData(0, &SphericalSurfaceTS08_0, refrac.clone());
	TestSystem08.fillVectorSurfaceAndInteractingData(1, &SphericalSurfaceTS08_1, refrac.clone());
	TestSystem08.fillVectorSurfaceAndInteractingData(2, &AperturStopTS08_2, doNothing.clone());
	TestSystem08.fillVectorSurfaceAndInteractingData(3, &PlanSurfaceTS08_3, absorb.clone());

	// Object 0
	RayAiming checkRayAimingTS08_0(TestSystem08);
	VectorStructR3 startPoint08_0{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint08_0{ 0.4,-0.4,4.0 };
	LightRayStruct testLightRay08_0 = checkRayAimingTS08_0.calcRayThrowPointInApertureStop(startPoint08_0, targetPoint08_0, light, 1.0);
	SequentialRayTracing seqTrace08_0(TestSystem08);
	seqTrace08_0.sequentialRayTracing(testLightRay08_0);
	VectorStructR3 checkTS08 = seqTrace08_0.getAllInterPointsAtSurf_i(checkRayAimingTS08_0.getPositionApertureStop(TestSystem08)).at(0);
	bool ch08 = Math::compareTwoVectorStructR3(targetPoint08_0, checkTS08, 4);
	checkRayAiming.push_back(ch08);
	
	// Field
	RayAiming checkRayAimingTS08_1(TestSystem08);
	VectorStructR3 startPoint08_1{ 0.0,0.5,0.0 };
	VectorStructR3 targetPoint08_1{ -0.3,0.5,4.0 };
	LightRayStruct testLightRay08_1 = checkRayAimingTS08_1.calcRayThrowPointInApertureStop(startPoint08_1, targetPoint08_1, light, 1.0);
	SequentialRayTracing seqTrace08_1(TestSystem08);
	seqTrace08_1.sequentialRayTracing(testLightRay08_1);
	checkTS08 = seqTrace08_1.getAllInterPointsAtSurf_i(checkRayAimingTS08_1.getPositionApertureStop(TestSystem08)).at(0);
	ch08 = Math::compareTwoVectorStructR3(targetPoint08_1, checkTS08, 4);
	checkRayAiming.push_back(ch08);
	
	FillApertureStop fillAperStopRayAiming08_2;
	//std::string fileName = "C:/Users/Dominik/Desktop/Bachelorarbeit Ray Aiming/Lichtquelle_Tbl_Werte.csv";
	std::vector<VectorStructR2> vector08_2 = fillAperStopRayAiming08_2.getcsv2columns("D:/TracerOpenMasterRepos/Tracer-Open-Master-Source/LightSources/Lichtquelle Tbl Werte.csv");
	
	LightRayStruct testLightRayChanged08_2 = fillAperStopRayAiming08_2.changeIntensityByDegree(testLightRay08_0, vector08_2);
	Light_LLT light08_1 = testLightRayChanged08_2.getLight_LLT();
	testLightRay08_1.setLight_LLT(light08_1);


	//	// Ray aiming from one point
	RayAiming checkRayAimingTS08_3(TestSystem08);
	SequentialRayTracing seqTrace08_3(TestSystem08);
	// Test targets Ring
	double semiHeightTest08_3 = 0.8;
	VectorStructR3 startPoint08_3 = { 0.0,0.0,0.0 };
	VectorStructR3 apexAperture08_3 = { 0.0,0.0,4.0 };
	std::vector<bool> bool08_3;
	std::vector<VectorStructR3> interPoints08_3;
	LightRayStruct testLightRay08_3;
	LightRayStruct testLightRayChanged08_5;
	VectorStructR3 checkTS08_3;
	bool cTS08_3;
	
	FillApertureStop fillAperStopRayAiming08_3;
	FillApertureStop fillAperStopRayAiming08_5;
	std::vector<VectorStructR3> pointsInApStopTS08_3 = fillAperStopRayAiming08_3.fillAS_withPoints(5, apexAperture08_3, { 0.0,0.0,1.0 }, semiHeightTest08_3);
	
	std::vector<LightRayStruct> lightRayVector08_3;


	std::clock_t start0;
	double duration0;
	start0 = std::clock();
	duration0 = (std::clock() - start0) / (double)CLOCKS_PER_SEC;
	std::cout << "duration0: " << duration0 << '\n';
	
	for (unsigned int i = 0; i < pointsInApStopTS08_3.size(); i++)
	{
		testLightRay08_3 = checkRayAimingTS08_3.calcRayThrowPointInApertureStop(startPoint08_3, pointsInApStopTS08_3.at(i), light, 1.0);
		testLightRayChanged08_5 = fillAperStopRayAiming08_5.changeIntensityByDegree(testLightRay08_3, vector08_2);
		lightRayVector08_3.push_back(testLightRayChanged08_5);
		seqTrace08_3.sequentialRayTracing(testLightRay08_3);
		checkTS08_3 = seqTrace08_3.getAllInterPointsAtSurf_i(checkRayAimingTS08_3.getPositionApertureStop(TestSystem08)).at(i);
		interPoints08_3.push_back(checkTS08_3);
		cTS08_3 = Math::compareTwoVectorStructR3(pointsInApStopTS08_3.at(i), checkTS08_3, 4);
		bool08_3.push_back(cTS08_3);
	}
	duration0 = (std::clock() - start0) / (double)CLOCKS_PER_SEC;
	
	Spot spotTS08_3;
	real rmsTS08_3 = spotTS08_3.calcRMS(seqTrace08_3.getAllInterPointsAtSurf_i(3), seqTrace08_3.getAllInterPointsAtSurf_i(3).at(0)) * 1000;
	

	// Ray Aiming from infinity   
	RayAiming checkRayAimingTS08_5(TestSystem08);
	SequentialRayTracing seqTrace08_5(TestSystem08);
	VectorStructR3 rayDirection08_5 = { 0.0,0.0,1.0 };
	LightRayStruct testLightRay08_5;
	VectorStructR3 checkTS08_5;
	std::vector<bool> bool08_5;
	bool cTS08_5;
	std::vector<VectorStructR3> interPoints08_5;
	FillApertureStop fillAperStopRayAiming08_52;
	std::vector<VectorStructR3> pointsInApStopTS08_5 = fillAperStopRayAiming08_52.fillAS_withPoints(5, apexAperture08_3, { 0.0,0.0,1.0 }, semiHeightTest08_3);
	
	std::clock_t start1;
	double duration1;
	start1 = std::clock();
	duration1 = (std::clock() - start1) / (double)CLOCKS_PER_SEC;
	//	std::cout << "duration1: " << duration1 << '\n';
	
	for (unsigned int i = 0; i < pointsInApStopTS08_3.size(); i++)
	{
		testLightRay08_5 = checkRayAimingTS08_5.infinityRayAiming(rayDirection08_5, pointsInApStopTS08_3.at(i), light, 1.0);
		seqTrace08_5.sequentialRayTracing(testLightRay08_5);
		checkTS08_5 = seqTrace08_5.getAllInterPointsAtSurf_i(checkRayAimingTS08_5.getPositionApertureStop(TestSystem08)).at(i);
		interPoints08_5.push_back(checkTS08_5);
		cTS08_5 = Math::compareTwoVectorStructR3(pointsInApStopTS08_3.at(i), checkTS08_5, 4);
		bool08_5.push_back(cTS08_3);
	}
	
	duration1 = (std::clock() - start0) / (double)CLOCKS_PER_SEC;
	std::cout << '\n' << "duration0: " << duration0 << '\n';
	std::cout << "durationi: " << duration1 << '\n';
	
	Spot spotTS08_4;
	real rmsTS08_4 = spotTS08_3.calcRMS(seqTrace08_5.getAllInterPointsAtSurf_i(3), seqTrace08_5.getAllInterPointsAtSurf_i(3).at(0)) * 1000;
	
	
	FillApertureStop fillAperStopRayAiming08_4;
	//std::string fileName = "C:/Users/Dominik/Desktop/Bachelorarbeit Ray Aiming/Lichtquelle_Tbl_Werte.csv";
	std::vector<VectorStructR2> vector08_4 = fillAperStopRayAiming08_4.getcsv2columns("C:/Users/Dominik/Desktop/Bachelorarbeit Ray Aiming/Lichtquelle Tbl Werte2.csv");
	std::vector<LightRayStruct> vectorLightRays;
	std::vector<Light_LLT> vectorLightLLT;
	LightRayStruct testLightRayChanged08_4;
	Light_LLT lightVal;


	// TestSystem05 ///////////////////////////////////////////////////
	OpticalSystem_LLT DoubleGauss5DegreeField;
	
	// 0 surface
	SphericalSurface_LLT SphericalSurfaceTS05_0(/*radius*/3.552, /*semiHeight*/1.5, /*Apex of the sphere*/{ 0.0,0.0,5.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.74);
	// 1 surface
	SphericalSurface_LLT SphericalSurfaceTS05_1(/*radius*/ 200.0, /*semiHeight*/1.5,/*Apex*/{ 0.0,0.0,6.4 }, /*Direction*/{ 0.0,0.0,1.0 },
		/*refIndexSideA*/  1.74,  /*refIndexSideB*/ 1.0);;
	// 2 surface
	SphericalSurface_LLT SphericalSurfaceTS05_2(/*radius*/1.704, /*semiHeight*/1.5, /*Apex of the sphere*/{ 0.0,0.0,6.5 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.55);
	// 3 surface
	SphericalSurface_LLT SphericalSurfaceTS05_3(/*radius*/16.238, /*semiHeight*/1.5, /*Apex of the sphere*/{ 0.0,0.0,7.5 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.71, /*refIndexSideB*/1.55);
	// 4 surface
	SphericalSurface_LLT SphericalSurfaceTS05_4(/*radius*/0.986, /*semiHeight*/0.8, /*Apex of the sphere*/{ 0.0,0.0,7.8 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.71, /*refIndexSideB*/1.0);
	// 5 surface
	ApertureStop_LLT AperturStopTS05_5{/*semiHeight*/ 0.42, /*Apex*/{ 0.0,0.0,8.2 },/*direction*/ { 0.0,0.0,1.0 },
		/*refIndex*/ 1.0 };
	// 6 surface
	SphericalSurface_LLT SphericalSurfaceTS05_6(/*radius*/1.642, /*semiHeight*/0.8, /*Apex of the sphere*/{ 0.0,0.0,8.5 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.71, /*refIndexSideB*/1.0);
	// 7 surface
	SphericalSurface_LLT SphericalSurfaceTS05_7(/*radius*/1.803, /*semiHeight*/1.0, /*Apex of the sphere*/{ 0.0,0.0,8.8 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.71, /*refIndexSideB*/1.74);
	// 8 surface
	SphericalSurface_LLT SphericalSurfaceTS05_8(/*radius*/2.334, /*semiHeight*/1.0, /*Apex of the sphere*/{ 0.0,0.0,10.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.74);
	// 9 surface
	SphericalSurface_LLT SphericalSurfaceTS05_9(/*radius*/1.659, /*semiHeight*/1.1, /*Apex of the sphere*/{ 0.0,0.0,10.4 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.74);
	// 10 surface
	SphericalSurface_LLT SphericalSurfaceTS05_10(/*radius*/14.411, /*semiHeight*/1.1, /*Apex of the sphere*/{ 0.0,0.0,11.4 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.74, /*refIndexSideB*/1.0);
	// 11 surface
	PlanGeometry_LLT PlanSurfaceTS05_11(/*semiHeight*/ 2.0, /*Apex*/{ 0.0,0.0,12.2 }, /*Direction*/{ 0.0,0.0,1.0 },
		/*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);
	
	// build the optical system
	DoubleGauss5DegreeField.fillVectorSurfaceAndInteractingData(0, &SphericalSurfaceTS05_0, refrac.clone());
	DoubleGauss5DegreeField.fillVectorSurfaceAndInteractingData(1, &SphericalSurfaceTS05_1, refrac.clone());
	DoubleGauss5DegreeField.fillVectorSurfaceAndInteractingData(2, &SphericalSurfaceTS05_2, refrac.clone());
	DoubleGauss5DegreeField.fillVectorSurfaceAndInteractingData(3, &SphericalSurfaceTS05_3, refrac.clone());
	DoubleGauss5DegreeField.fillVectorSurfaceAndInteractingData(4, &SphericalSurfaceTS05_4, refrac.clone());
	DoubleGauss5DegreeField.fillVectorSurfaceAndInteractingData(5, &AperturStopTS05_5, doNothing.clone());
	DoubleGauss5DegreeField.fillVectorSurfaceAndInteractingData(6, &SphericalSurfaceTS05_6, refrac.clone());
	DoubleGauss5DegreeField.fillVectorSurfaceAndInteractingData(7, &SphericalSurfaceTS05_7, refrac.clone());
	DoubleGauss5DegreeField.fillVectorSurfaceAndInteractingData(8, &SphericalSurfaceTS05_8, refrac.clone());
	DoubleGauss5DegreeField.fillVectorSurfaceAndInteractingData(9, &SphericalSurfaceTS05_9, refrac.clone());
	DoubleGauss5DegreeField.fillVectorSurfaceAndInteractingData(10, &SphericalSurfaceTS05_10, refrac.clone());
	DoubleGauss5DegreeField.fillVectorSurfaceAndInteractingData(11, &PlanSurfaceTS05_11, absorb.clone());
	
	
	// Object 0
	RayAiming checkRayAimingTS05_0(DoubleGauss5DegreeField);
	VectorStructR3 startPoint05_0{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint05_0{ 0.0,0.4,8.2};
	LightRayStruct testLightRay05_0 = checkRayAimingTS05_0.calcRayThrowPointInApertureStop(startPoint05_0, targetPoint05_0, light, 1.0);
	SequentialRayTracing seqTrace05_0(DoubleGauss5DegreeField);
	seqTrace05_0.sequentialRayTracing(testLightRay05_0);
	VectorStructR3 checkTS05 = seqTrace05_0.getAllInterPointsAtSurf_i(checkRayAimingTS05_0.getPositionApertureStop(DoubleGauss5DegreeField)).at(0);
	bool ch05 = Math::compareTwoVectorStructR3(targetPoint05_0, checkTS05, 4);
	checkRayAiming.push_back(ch05);
	
	// Field
	RayAiming checkRayAimingTS05_1(DoubleGauss5DegreeField);
	VectorStructR3 startPoint05_1{ 0.0,-0.40,0.0 };
	VectorStructR3 targetPoint05_1{ -0.3,0.23,8.2 };
	LightRayStruct testLightRay05_1 = checkRayAimingTS05_1.calcRayThrowPointInApertureStop(startPoint05_1, targetPoint05_1, light, 1.0);
	SequentialRayTracing seqTrace05_1(DoubleGauss5DegreeField);
	seqTrace05_1.sequentialRayTracing(testLightRay05_1);
	checkTS05 = seqTrace05_1.getAllInterPointsAtSurf_i(checkRayAimingTS05_1.getPositionApertureStop(DoubleGauss5DegreeField)).at(0);
	ch05 = Math::compareTwoVectorStructR3(targetPoint05_1, checkTS05, 4);
	checkRayAiming.push_back(ch05);
	
	// Infinity 0
	RayAiming checkRayAimingTS05_2(DoubleGauss5DegreeField);
	VectorStructR3 rayDirectionTS05_2 = { 0.0,0.0,1.0 };
	VectorStructR3 targetPointTS05_2 = { 0.2111111,-0.07856,8.2 };
	LightRayStruct testLightRay05_2 = checkRayAimingTS05_2.infinityRayAiming(rayDirectionTS05_2, targetPointTS05_2, light, 1.0);
	SequentialRayTracing seqTraceTS05_2(DoubleGauss5DegreeField);
	seqTraceTS05_2.sequentialRayTracing(testLightRay05_2);
	checkTS05 = seqTraceTS05_2.getAllInterPointsAtSurf_i(checkRayAimingTS05_2.getPositionApertureStop(DoubleGauss5DegreeField)).at(0);
	ch05 = Math::compareTwoVectorStructR3(targetPointTS05_2, checkTS05, 4);
	checkRayAiming.push_back(ch05);
	
	// Infinity 1
	RayAiming checkRayAimingTS05_3(DoubleGauss5DegreeField);
	VectorStructR3 rayDirectionTS05_3 = { 0.0,0.05,1.0 };
	VectorStructR3 targetPointTS05_3 = { 0.142,-0.1134,8.2 };
	LightRayStruct testLightRay05_3 = checkRayAimingTS05_3.infinityRayAiming(rayDirectionTS05_3, targetPointTS05_3, light, 1.0);
	SequentialRayTracing seqTraceTS05_3(DoubleGauss5DegreeField);
	seqTraceTS05_3.sequentialRayTracing(testLightRay05_3);
	checkTS05 = seqTraceTS05_3.getAllInterPointsAtSurf_i(checkRayAimingTS05_3.getPositionApertureStop(DoubleGauss5DegreeField)).at(0);
	ch05 = Math::compareTwoVectorStructR3(targetPointTS05_3, checkTS05, 4);
	checkRayAiming.push_back(ch05);
	
	
	// Ray aiming from one point
	RayAiming checkRayAimingTS05_4(DoubleGauss5DegreeField);
	SequentialRayTracing seqTrace05_4(DoubleGauss5DegreeField);
	// Test targets Ring
	double semiHeightTest05_4 = 0.4;
	VectorStructR3 startPoint05_4 = { 0.0,0.0,0.0 };
	VectorStructR3 apexAperture05_4 = { 0.0,0.0,8.2 };
	std::vector<bool> bool05_4;
	std::vector<VectorStructR3> interPoints05_4;
	LightRayStruct testLightRay05_4;
	VectorStructR3 checkTS05_4;
	bool cTS05_4;
	
	FillApertureStop fillAperStopRayAiming05_4;
	std::vector<VectorStructR3> pointsInApStopTS05_4 = fillAperStopRayAiming05_4.fillAS_withPoints(6, apexAperture05_4, { 0.0,0.0,1.0 }, semiHeightTest05_4);
	
	std::clock_t start;
	double duration;
	start = std::clock();
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "printf: " << duration << '\n';
	
	for (unsigned int i = 0; i < pointsInApStopTS05_4.size(); i++)
	{
		testLightRay05_4 = checkRayAimingTS05_4.calcRayThrowPointInApertureStop(startPoint05_4, pointsInApStopTS05_4.at(i), light, 1.0);
		seqTrace05_4.sequentialRayTracing(testLightRay05_4);
		checkTS05_4 = seqTrace05_4.getAllInterPointsAtSurf_i(checkRayAimingTS05_4.getPositionApertureStop(DoubleGauss5DegreeField)).at(i);
		interPoints05_4.push_back(checkTS05_4);
		cTS05_4 = Math::compareTwoVectorStructR3(pointsInApStopTS05_4.at(i), checkTS05_4, 4);
		bool05_4.push_back(cTS05_4);
	}
	
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "printf: " << duration << '\n';
	
	Spot spotTS05_4;
	real rmsTS05_4 = spotTS05_4.calcRMS(seqTrace05_4.getAllInterPointsAtSurf_i(11), seqTrace05_4.getAllInterPointsAtSurf_i(11).at(0)) * 1000;
	std::cout << "RMS: " << rmsTS05_4 << '\n';
	
	// Ray Aiming from infinity   
	RayAiming checkRayAimingTS05_5(DoubleGauss5DegreeField);
	SequentialRayTracing seqTrace05_5(DoubleGauss5DegreeField);
	VectorStructR3 rayDirection05_5 = { 0.0,0.0,1.0 };
	LightRayStruct testLightRay05_5;
	VectorStructR3 checkTS05_5;
	std::vector<bool> bool05_5;
	std::vector<VectorStructR3> interPoints05_5;
	FillApertureStop fillAperStopRayAiming05_5;
	std::vector<VectorStructR3> pointsInApStopTS05_52 = fillAperStopRayAiming05_5.fillAS_withPointsDithered(4, apexAperture05_4, { 0.0,0.0,1.0 }, semiHeightTest05_4);
	FillApertureStop fillAperStopRayAiming05_51;
	std::vector<VectorStructR3> pointsInApStopTS05_51 = fillAperStopRayAiming05_51.fillAS_withPointsSquare(3, apexAperture05_4, { 0.0,0.0,1.0 }, semiHeightTest05_4);
	FillApertureStop fillAperStopRayAiming05_52;
	std::vector<VectorStructR3> pointsInApStopTS05_5 = fillAperStopRayAiming05_52.fillAS_withPoints(5, apexAperture05_4, { 0.0,0.0,1.0 }, semiHeightTest05_4);
	
	for (unsigned int i = 0; i < pointsInApStopTS05_5.size(); i++)
	{
		testLightRay05_5 = checkRayAimingTS05_5.infinityRayAiming(rayDirection05_5, pointsInApStopTS05_5.at(i), light, 1.0);
		seqTrace05_5.sequentialRayTracing(testLightRay05_5);
		checkTS05_5 = seqTrace05_5.getAllInterPointsAtSurf_i(checkRayAimingTS05_5.getPositionApertureStop(DoubleGauss5DegreeField)).at(i);
		interPoints05_5.push_back(checkTS05_5);
		cTS05_4 = Math::compareTwoVectorStructR3(pointsInApStopTS05_5.at(i), checkTS05_5, 4);
		bool05_4.push_back(cTS05_4);
	}
	
	Spot spotTS05_5;
	real rmsTS05_5 = spotTS05_5.calcRMS(seqTrace05_5.getAllInterPointsAtSurf_i(11), seqTrace05_5.getAllInterPointsAtSurf_i(11).at(0)) * 1000;
	
	

	

	// Test System 04
	OpticalSystem_LLT(TestSystem04);

	// 0 surface
	SphericalSurface_LLT SphericalSurfaceTS04_0(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,15.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 1 surface
	SphericalSurface_LLT SphericalSurfaceTS04_1(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,17.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 2 surface
	SphericalSurface_LLT SphericalSurfaceTS04_2(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,19.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 3 surface
	SphericalSurface_LLT SphericalSurfaceTS04_3(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,21.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 4 surface
	ApertureStop_LLT AperturStopTS04_4{/*semiHeight*/ 0.92, /*Apex*/{ 0.0,0.0,24.0 },/*direction*/ { 0.0,0.0,1.0 },
		/*refIndex*/ 1.0 };
	// 5 surface
	SphericalSurface_LLT SphericalSurfaceTS04_5(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,27.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 6 surface
	SphericalSurface_LLT SphericalSurfaceTS04_6(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,29.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 7 surface
	PlanGeometry_LLT PlanSurfaceTS04_7(/*semiHeight*/ 4.0, /*Apex*/{ 0.0,0.0,34.0 }, /*Direction*/{ 0.0,0.0,1.0 },
		/*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);

	// build the optical system
	TestSystem04.fillVectorSurfaceAndInteractingData(0, &SphericalSurfaceTS04_0, refrac.clone());
	TestSystem04.fillVectorSurfaceAndInteractingData(1, &SphericalSurfaceTS04_1, refrac.clone());
	TestSystem04.fillVectorSurfaceAndInteractingData(2, &SphericalSurfaceTS04_2, refrac.clone());
	TestSystem04.fillVectorSurfaceAndInteractingData(3, &SphericalSurfaceTS04_3, refrac.clone());
	TestSystem04.fillVectorSurfaceAndInteractingData(4, &AperturStopTS04_4, doNothing.clone());
	TestSystem04.fillVectorSurfaceAndInteractingData(5, &SphericalSurfaceTS04_5, refrac.clone());
	TestSystem04.fillVectorSurfaceAndInteractingData(6, &SphericalSurfaceTS04_6, refrac.clone());
	TestSystem04.fillVectorSurfaceAndInteractingData(7, &PlanSurfaceTS04_7, absorb.clone());


	// 0,0,0
	RayAiming checkRayAimingTS04_0(TestSystem04);
	VectorStructR3 startPoint04_0{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint04_0{ -0.5,0.5,24.0 };
	LightRayStruct testLightRay04_0 = checkRayAimingTS04_0.calcRayThrowPointInApertureStop(startPoint04_0, targetPoint04_0, light, 1.0);
	SequentialRayTracing seqTrace04_0(TestSystem04);
	seqTrace04_0.sequentialRayTracing(testLightRay04_0);
	VectorStructR3 checkTS04 = seqTrace04_0.getAllInterPointsAtSurf_i(checkRayAimingTS04_0.getPositionApertureStop(TestSystem04)).at(0);
	bool ch04 = Math::compareTwoVectorStructR3(targetPoint04_0, checkTS04, 3);
	checkRayAiming.push_back(ch04);
	
	// Field
	RayAiming checkRayAimingTS04_1(TestSystem04);
	VectorStructR3 startPoint04_1{ 2.0,0.0,0.0 };
	VectorStructR3 targetPoint04_1{ 0.5,-0.5,24.0 };
	LightRayStruct testLightRay04_1 = checkRayAimingTS04_1.calcRayThrowPointInApertureStop(startPoint04_1, targetPoint04_1, light, 1.0);
	SequentialRayTracing seqTrace04_1(TestSystem04);
	seqTrace04_1.sequentialRayTracing(testLightRay04_1);
	checkTS04 = seqTrace04_1.getAllInterPointsAtSurf_i(checkRayAimingTS04_1.getPositionApertureStop(TestSystem04)).at(0);
	ch04 = Math::compareTwoVectorStructR3(targetPoint04_1, checkTS04, 3);
	checkRayAiming.push_back(ch04);
	
	// Infinity
	RayAiming checkRayAimingTS04_2(TestSystem04);
	VectorStructR3 rayDirectionTS04_2 = { 0.0,0.0,1.0 };
	VectorStructR3 targetPointTS04_2 = { 0.6,-0.,24.0 };
	LightRayStruct testLightRay04_2 = checkRayAimingTS04_2.infinityRayAiming(rayDirectionTS04_2, targetPointTS04_2, light, 1.0);
	SequentialRayTracing seqTraceTS04_2(TestSystem04);
	seqTraceTS04_2.sequentialRayTracing(testLightRay04_2);
	checkTS04 = seqTraceTS04_2.getAllInterPointsAtSurf_i(checkRayAimingTS04_2.getPositionApertureStop(TestSystem04)).at(0);
	ch04 = Math::compareTwoVectorStructR3(targetPointTS04_2, checkTS04, 4);
	checkRayAiming.push_back(ch04);


	// Ray aiming from one point
	RayAiming checkRayAimingTS04_3(TestSystem04);
	SequentialRayTracing seqTrace04_3(TestSystem04);
	// Test targets Ring
	double semiHeightTest04_3 = 0.9;
	VectorStructR3 startPoint04_3 = { 0.0,0.0,0.0 };
	VectorStructR3 apexAperture04_3 = { 0.0,0.0,24.0 };
	std::vector<bool> bool04_3;
	std::vector<VectorStructR3> interPoints04_3;
	LightRayStruct testLightRay04_3;
	VectorStructR3 checkTS04_3;
	bool cTS04_3;
	
	FillApertureStop fillAperStopRayAiming04_3;
	std::vector<VectorStructR3> pointsInApStopTS04_3 = fillAperStopRayAiming04_3.fillAS_withPoints(4, apexAperture04_3, { 0.0,0.0,1.0 }, semiHeightTest04_3);
	
	for (unsigned int i = 0; i < pointsInApStopTS04_3.size(); i++)
	{
		testLightRay04_3 = checkRayAimingTS04_3.calcRayThrowPointInApertureStop(startPoint04_3, pointsInApStopTS04_3.at(i), light, 1.0);
		seqTrace04_3.sequentialRayTracing(testLightRay04_3);
		checkTS04_3 = seqTrace04_3.getAllInterPointsAtSurf_i(checkRayAimingTS04_3.getPositionApertureStop(TestSystem04)).at(i);
		interPoints04_3.push_back(checkTS04_3);
		cTS04_3 = Math::compareTwoVectorStructR3(pointsInApStopTS04_3.at(i), checkTS04_3, 4);
		bool04_3.push_back(cTS04_3);
		// manche false, aber nur wenig daneben. Der RMS-Wert bleibt dadurch praktisch unbeeinflusst und stimmt mit dem von Zemax überein.
	}
	
	Spot spotTS04_03;
	real rmsTS04_03 = spotTS04_03.calcRMS(seqTrace04_3.getAllInterPointsAtSurf_i(7), seqTrace04_3.getAllInterPointsAtSurf_i(7).at(0)) * 1000;
	
	// Ray Aiming from infinity   // Kein Test möglich. Unerklärliches "out of range"
	RayAiming checkRayAimingTS04_4(TestSystem04);
	SequentialRayTracing seqTrace04_4(TestSystem04);
	VectorStructR3 rayDirection04_4 = { 0.0,0.0,1.0 };
	LightRayStruct testLightRay04_4;
	VectorStructR3 checkTS04_4;
	std::vector<bool> bool04_4;
	std::vector<VectorStructR3> interPoints04_4;
	semiHeightTest04_3 = 0.8;
	FillApertureStop fillAperStopRayAiming04_4;
	std::vector<VectorStructR3> pointsInApStopTS04_4 = fillAperStopRayAiming04_4.fillAS_withPoints(4, apexAperture04_3, { 0.0,0.0,1.0 }, semiHeightTest04_3);
	
	for (unsigned int i = 0; i < pointsInApStopTS04_4.size(); i++)
	{
		testLightRay04_4 = checkRayAimingTS04_4.infinityRayAiming(rayDirection04_4, pointsInApStopTS04_4.at(i), light, 1.0);
		seqTrace04_4.sequentialRayTracing(testLightRay04_4);
		checkTS04_4 = seqTrace04_4.getAllInterPointsAtSurf_i(checkRayAimingTS04_4.getPositionApertureStop(TestSystem04)).at(i);
		interPoints04_4.push_back(checkTS04_4);
		cTS04_3 = Math::compareTwoVectorStructR3(pointsInApStopTS04_4.at(i), checkTS04_4, 6);
		bool04_4.push_back(cTS04_3);
	}
	
	Spot spotTS04_4;
	real rmsTS04_04 = spotTS04_4.calcRMS(seqTrace04_4.getAllInterPointsAtSurf_i(7), seqTrace04_4.getAllInterPointsAtSurf_i(7).at(0)) * 1000;
	
	
	
	
		// TestSystem03 ///////////////////////////////////////////////////
	OpticalSystem_LLT TestSystem03;

	// 0 surface
	SphericalSurface_LLT SphericalSurfaceTS03_0(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,15.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	// 1 surface
	SphericalSurface_LLT SphericalSurfaceTS03_1(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,16.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	// 2 surface
	SphericalSurface_LLT SphericalSurfaceTS03_2(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,17.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 3 surface
	SphericalSurface_LLT SphericalSurfaceTS03_3(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,18.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 4 surface
	ApertureStop_LLT AperturStopTS03_4{/*semiHeight*/ 1.1, /*Apex*/{ 0.0,0.0,19.0 },/*direction*/ { 0.0,0.0,1.0 },
		/*refIndex*/ 1.0 };
	// 5 surface
	PlanGeometry_LLT PlanSurfaceTS03_5(/*semiHeight*/ 4.0, /*Apex*/{ 0.0,0.0,29.0 }, /*Direction*/{ 0.0,0.0,1.0 },
		/*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);

	// build the optical system
	TestSystem03.fillVectorSurfaceAndInteractingData(0, &SphericalSurfaceTS03_0, refrac.clone());
	TestSystem03.fillVectorSurfaceAndInteractingData(1, &SphericalSurfaceTS03_1, refrac.clone());
	TestSystem03.fillVectorSurfaceAndInteractingData(2, &SphericalSurfaceTS03_2, refrac.clone());
	TestSystem03.fillVectorSurfaceAndInteractingData(3, &SphericalSurfaceTS03_3, refrac.clone());
	TestSystem03.fillVectorSurfaceAndInteractingData(4, &AperturStopTS03_4, doNothing.clone());
	TestSystem03.fillVectorSurfaceAndInteractingData(5, &PlanSurfaceTS03_5, absorb.clone());
	
	// Object 0
	RayAiming checkRayAimingTS03_00(TestSystem03);
	VectorStructR3 startPoint03_00{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint03_0{ 0.7,-0.6,19.0 };
	LightRayStruct testLightRay03_00 = checkRayAimingTS03_00.calcRayThrowPointInApertureStop(startPoint03_00, targetPoint03_0, light, 1.0);
	SequentialRayTracing seqTrace03_00(TestSystem03);
	seqTrace03_00.sequentialRayTracing(testLightRay03_00);
	VectorStructR3 checkTS03 = seqTrace03_00.getAllInterPointsAtSurf_i(checkRayAimingTS03_00.getPositionApertureStop(TestSystem03)).at(0);
	bool ch03 = Math::compareTwoVectorStructR3(targetPoint03_0, checkTS03, 4);
	checkRayAiming.push_back(ch03);
	
	// Field
	RayAiming checkRayAimingTS03_01(TestSystem03);
	VectorStructR3 startPoint03_01{ 0.0,0.5,0.0 };
	VectorStructR3 targetPoint03_1{ 0.1,-0.8,19.0 };
	LightRayStruct testLightRay03_01 = checkRayAimingTS03_01.calcRayThrowPointInApertureStop(startPoint03_01, targetPoint03_1, light, 1.0);
	SequentialRayTracing seqTrace03_01(TestSystem03);
	seqTrace03_01.sequentialRayTracing(testLightRay03_01);
	checkTS03 = seqTrace03_01.getAllInterPointsAtSurf_i(checkRayAimingTS03_01.getPositionApertureStop(TestSystem03)).at(0);
	ch03 = Math::compareTwoVectorStructR3(targetPoint03_1, checkTS03, 4);
	checkRayAiming.push_back(ch03);
	
	// Infinity
	RayAiming checkRayAimingTS03_02(TestSystem03);
	VectorStructR3 rayDirectionTS03_2 = { 0.0,0.001,1.0 };
	VectorStructR3 targetPointTS03_2 = { 1.0 ,-0.02,19.0 };
	LightRayStruct testLightRay03_2 = checkRayAimingTS03_02.infinityRayAiming(rayDirectionTS03_2, targetPointTS03_2, light, 1.0);
	SequentialRayTracing seqTraceTS03_2(TestSystem03);
	seqTraceTS03_2.sequentialRayTracing(testLightRay03_2);
	checkTS03 = seqTraceTS03_2.getAllInterPointsAtSurf_i(checkRayAimingTS03_02.getPositionApertureStop(TestSystem03)).at(0);
	ch03 = Math::compareTwoVectorStructR3(targetPointTS03_2, checkTS03, 4);
	checkRayAiming.push_back(ch03);
	
		// Ray aiming from one point
	RayAiming checkRayAimingTS03_0(TestSystem03);
	SequentialRayTracing seqTrace03_0(TestSystem03);
	// Test targets Ring
	double semiHeightTest03_0 = 1.0;
	VectorStructR3 startPoint03_0 = { 0.0,0.0,0.0 };
	VectorStructR3 apexAperture03_0 = { 0.0,0.0,19.0 };
	std::vector<bool> bool03_0;
	std::vector<VectorStructR3> interPoints03_0;
	LightRayStruct testLightRay03_0;
	VectorStructR3 checkTS03_0;
	bool cTS03_0;

	FillApertureStop fillAperStopRayAiming03_0;
	std::vector<VectorStructR3> pointsInApStopTS03_0 = fillAperStopRayAiming03_0.fillAS_withPoints(5, apexAperture03_0, { 0.0,0.0,1.0 }, semiHeightTest03_0);

	//std::clock_t start0;
	//double duration0;
	//start0 = std::clock();

	for (unsigned int i = 0; i < pointsInApStopTS03_0.size(); i++)
	{
		testLightRay03_0 = checkRayAimingTS03_0.calcRayThrowPointInApertureStop(startPoint03_0, pointsInApStopTS03_0.at(i), light, 1.0);
		seqTrace03_0.sequentialRayTracing(testLightRay03_0);
		checkTS03_0 = seqTrace03_0.getAllInterPointsAtSurf_i(checkRayAimingTS03_0.getPositionApertureStop(TestSystem03)).at(i);
		interPoints03_0.push_back(checkTS03_0);
		cTS03_0 = Math::compareTwoVectorStructR3(pointsInApStopTS03_0.at(i), checkTS03_0, 4);
		bool03_0.push_back(cTS03_0);
	}

	//duration0 = (std::clock() - start0) / (double)CLOCKS_PER_SEC;

	Spot spotTS03_0;
	real rmsTS03_0 = spotTS03_0.calcRMS(seqTrace03_0.getAllInterPointsAtSurf_i(5), seqTrace03_0.getAllInterPointsAtSurf_i(5).at(0)) * 1000;

	// Ray Aiming from infinity   
	RayAiming checkRayAimingTS03_1(TestSystem03);
	SequentialRayTracing seqTrace03_1(TestSystem03);
	VectorStructR3 rayDirection03_1 = { 0.0,0.001,1.0 };
	LightRayStruct testLightRay03_1;
	VectorStructR3 checkTS03_1;
	std::vector<bool> bool03_1;
	std::vector<VectorStructR3> interPoints03_1;
	semiHeightTest03_0 = 1.0;
	FillApertureStop fillAperStopRayAiming03_1;
	std::vector<VectorStructR3> pointsInApStopTS03_1 = fillAperStopRayAiming03_1.fillAS_withPoints(5, apexAperture03_0, { 0.0,0.0,1.0 }, semiHeightTest03_0);

	//std::clock_t start1;
	//double duration1;
	//start1 = std::clock();

	for (unsigned int i = 0; i < pointsInApStopTS03_1.size(); i++)
	{
		testLightRay03_1 = checkRayAimingTS03_1.infinityRayAiming(rayDirection03_1, pointsInApStopTS03_1.at(i), light, 1.0);
		seqTrace03_1.sequentialRayTracing(testLightRay03_1);
		checkTS03_1 = seqTrace03_1.getAllInterPointsAtSurf_i(checkRayAimingTS03_1.getPositionApertureStop(TestSystem03)).at(i);
		interPoints03_1.push_back(checkTS03_1);
		cTS03_0 = Math::compareTwoVectorStructR3(pointsInApStopTS03_1.at(i), checkTS03_1, 4);
		bool03_1.push_back(cTS03_0);
	}

	//duration1 = (std::clock() - start1) / (double)CLOCKS_PER_SEC;
	//std::cout << "duration0: " << duration0 << '\n';
	//std::cout << "duration1: " << duration1 << '\n';

	Spot spotTS03_1;
	real rmsTS03_1 = spotTS03_1.calcRMS(seqTrace03_1.getAllInterPointsAtSurf_i(5), seqTrace03_1.getAllInterPointsAtSurf_i(5).at(0)) * 1000;

	// TestSystem02 ///////////////////////////////////////////////////

	OpticalSystem_LLT TestSystem02;
	
	// 0 surface
	SphericalSurface_LLT SphericalSurfaceTS02_0(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,15.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 1 surface
	SphericalSurface_LLT SphericalSurfaceTS02_1(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,17.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 2 surface
	SphericalSurface_LLT SphericalSurfaceTS02_2(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,27.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 3 surface
	SphericalSurface_LLT SphericalSurfaceTS02_3(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,29.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/2.0);
	// 4 surface
	ApertureStop_LLT AperturStopTS02_4{/*semiHeight*/ 1.1, /*Apex*/{ 0.0,0.0,32.0 },/*direction*/ { 0.0,0.0,1.0 },
		/*refIndex*/ 1.0 };
	// 5 surface
	SphericalSurface_LLT SphericalSurfaceTS02_5(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,35.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	// 6 surface
	SphericalSurface_LLT SphericalSurfaceTS02_6(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,37.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	// 7 surface
	PlanGeometry_LLT PlanSurfaceTS02_7(/*semiHeight*/ 4.0, /*Apex*/{ 0.0,0.0,42.0 }, /*Direction*/{ 0.0,0.0,1.0 },
		/*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);
	
	// build the optical system
	TestSystem02.fillVectorSurfaceAndInteractingData(0, &SphericalSurfaceTS02_0, refrac.clone());
	TestSystem02.fillVectorSurfaceAndInteractingData(1, &SphericalSurfaceTS02_1, refrac.clone());
	TestSystem02.fillVectorSurfaceAndInteractingData(2, &SphericalSurfaceTS02_2, refrac.clone());
	TestSystem02.fillVectorSurfaceAndInteractingData(3, &SphericalSurfaceTS02_3, refrac.clone());
	TestSystem02.fillVectorSurfaceAndInteractingData(4, &AperturStopTS02_4, doNothing.clone());
	TestSystem02.fillVectorSurfaceAndInteractingData(5, &SphericalSurfaceTS02_5, refrac.clone());
	TestSystem02.fillVectorSurfaceAndInteractingData(6, &SphericalSurfaceTS02_6, refrac.clone());
	TestSystem02.fillVectorSurfaceAndInteractingData(7, &PlanSurfaceTS02_7, absorb.clone());
	
	
	Ray_LLT testRay2_E0(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 1.0,-1.0,15.0 }, 1.0);
	light.setWavelength(550.0);
	LightRayStruct testtestLightRay2_E0(light, testRay2_E0, 1);
	SequentialRayTracing seqTraceTest2_E0(TestSystem02);
	seqTraceTest2_E0.sequentialRayTracing(testtestLightRay2_E0);
	VectorStructR3 testtestInter2_E0 = seqTraceTest2_E0.getAllInterPointsAtSurf_i(4).at(0);
	
	// 0,0,0
	RayAiming checkRayAimingTS02_0(TestSystem02);
	VectorStructR3 startPoint02_0{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint02_0{ 0.7,-0.4,32.0 };
	LightRayStruct testLightRay02_0 = checkRayAimingTS02_0.calcRayThrowPointInApertureStop(startPoint02_0, targetPoint02_0, light, 1.0);
	SequentialRayTracing seqTrace02_0(TestSystem02);
	seqTrace02_0.sequentialRayTracing(testLightRay02_0);
	VectorStructR3 checkTS02 = seqTrace02_0.getAllInterPointsAtSurf_i(checkRayAimingTS02_0.getPositionApertureStop(TestSystem02)).at(0);
	bool ch02 = Math::compareTwoVectorStructR3(targetPoint02_0, checkTS02, 4);
	checkRayAiming.push_back(ch02);
	
	// Field
	RayAiming checkRayAimingTS02_1(TestSystem02);
	VectorStructR3 startPoint02_1{ 1.5,0.0,0.0 };
	VectorStructR3 targetPoint02_1{ 0.5,-0.3,32.0 };
	LightRayStruct testLightRay02_1 = checkRayAimingTS02_1.calcRayThrowPointInApertureStop(startPoint02_1, targetPoint02_1, light, 1.0);
	SequentialRayTracing seqTrace02_1(TestSystem02);
	seqTrace02_1.sequentialRayTracing(testLightRay02_1);
	checkTS02 = seqTrace02_1.getAllInterPointsAtSurf_i(checkRayAimingTS02_1.getPositionApertureStop(TestSystem02)).at(0);
	ch02 = Math::compareTwoVectorStructR3(targetPoint02_1, checkTS02, 4);
	checkRayAiming.push_back(ch02);
	
	// Infinity
	RayAiming checkRayAimingTS02_2(TestSystem02);
	VectorStructR3 rayDirectionTS02_2 = { 0.0,0.0,1.0 };
	VectorStructR3 targetPointTS02_2 = { 0.7 ,-0.02,32.0 };
	LightRayStruct testLightRay02_2 = checkRayAimingTS02_2.infinityRayAiming(rayDirectionTS02_2, targetPointTS02_2, light, 1.0);
	SequentialRayTracing seqTraceTS02_2(TestSystem02);
	seqTraceTS02_2.sequentialRayTracing(testLightRay02_2);
	checkTS02 = seqTraceTS02_2.getAllInterPointsAtSurf_i(checkRayAimingTS02_2.getPositionApertureStop(TestSystem02)).at(0);
	ch02 = Math::compareTwoVectorStructR3(targetPointTS02_2, checkTS02, 4);
	checkRayAiming.push_back(ch02);
	
	
	// Ray aiming from one point
	RayAiming checkRayAimingTS02_3(TestSystem02);
	SequentialRayTracing seqTrace02_3(TestSystem02);
	// Test targets Ring
	double semiHeightTest02_3 = 1.0;
	VectorStructR3 startPoint02_3 = { 0.0,0.0,0.0 };
	VectorStructR3 apexAperture02_3 = { 0.0,0.0,32.0 };
	std::vector<bool> bool02_3;
	std::vector<VectorStructR3> interPoints02_3;
	LightRayStruct testLightRay02_3;
	VectorStructR3 checkTS02_3;
	bool cTS02_3;
	
	FillApertureStop fillAperStopRayAiming02_3;
	std::vector<VectorStructR3> pointsInApStopTS02_3 = fillAperStopRayAiming02_3.fillAS_withPoints(5, apexAperture02_3, { 0.0,0.0,1.0 }, semiHeightTest02_3);
	

	
	for (unsigned int i = 0; i < pointsInApStopTS02_3.size(); i++)
	{
		testLightRay02_3 = checkRayAimingTS02_3.calcRayThrowPointInApertureStop(startPoint02_3, pointsInApStopTS02_3.at(i), light, 1.0);
		seqTrace02_3.sequentialRayTracing(testLightRay02_3);
		checkTS02_3 = seqTrace02_3.getAllInterPointsAtSurf_i(checkRayAimingTS02_3.getPositionApertureStop(TestSystem02)).at(i);
		interPoints02_3.push_back(checkTS02_3);
		cTS02_3 = Math::compareTwoVectorStructR3(pointsInApStopTS02_3.at(i), checkTS02_3, 4);
		bool02_3.push_back(cTS02_3);
	}
	

	
	Spot spotTS02_03;
	real rmsTS02_03 = spotTS02_03.calcRMS(seqTrace02_3.getAllInterPointsAtSurf_i(7), seqTrace02_3.getAllInterPointsAtSurf_i(7).at(0)) * 1000;
	
	// Ray Aiming from infinity   // Kein Test möglich. Unerklärliches "out of range"
	RayAiming checkRayAimingTS02_4(TestSystem02);
	SequentialRayTracing seqTrace02_4(TestSystem02);
	VectorStructR3 rayDirection02_4 = { 0.0,0.0,1.0 };
	LightRayStruct testLightRay02_4;
	VectorStructR3 checkTS02_4;
	std::vector<bool> bool02_4;
	std::vector<VectorStructR3> interPoints02_4;
	semiHeightTest02_3 = 0.9;
	FillApertureStop fillAperStopRayAiming02_4;
	std::vector<VectorStructR3> pointsInApStopTS02_4 = fillAperStopRayAiming02_4.fillAS_withPoints(5, apexAperture02_3, { 0.0,0.0,1.0 }, semiHeightTest02_3);
	

	
	for (unsigned int i = 0; i < pointsInApStopTS02_4.size(); i++)
	{
		testLightRay02_4 = checkRayAimingTS02_4.infinityRayAiming(rayDirection02_4, pointsInApStopTS02_4.at(i), light, 1.0);
		seqTrace02_4.sequentialRayTracing(testLightRay02_4);
		checkTS02_4 = seqTrace02_4.getAllInterPointsAtSurf_i(checkRayAimingTS02_4.getPositionApertureStop(TestSystem02)).at(i);
		interPoints02_4.push_back(checkTS02_4);
		cTS02_3 = Math::compareTwoVectorStructR3(pointsInApStopTS02_4.at(i), checkTS02_4, 4);
		bool02_4.push_back(cTS02_3);
	}
	
	Spot spotTS02_4;
	real rmsTS02_04 = spotTS02_4.calcRMS(seqTrace02_4.getAllInterPointsAtSurf_i(7), seqTrace02_4.getAllInterPointsAtSurf_i(7).at(0)) * 1000;
	

	
	
	
	// TestSystem01 ///////////////////////////////////////////////////
	OpticalSystem_LLT TestSystem01;
	
	// 0 surface
	SphericalSurface_LLT SphericalSurfaceTS01_0(/*radius*/15.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,10.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	// 1 surface
	SphericalSurface_LLT SphericalSurfaceTS01_1(/*radius*/15.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,12.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	// 2 surface
	SphericalSurface_LLT SphericalSurfaceTS01_2(/*radius*/12.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,17.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	// 3 surface
	SphericalSurface_LLT SphericalSurfaceTS01_3(/*radius*/12.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,19.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	// 4 surface
	ApertureStop_LLT AperturStopTS01_4{/*semiHeight*/ 5.0, /*Apex*/{ 0.0,0.0,24.0 },/*direction*/ { 0.0,0.0,1.0 },
		/*refIndex*/ 1.0 };
	// 5 surface
	PlanGeometry_LLT PlanSurfaceTS01_5(/*semiHeight*/ 4.0, /*Apex*/{ 0.0,0.0,34.0 }, /*Direction*/{ 0.0,0.0,1.0 },
		/*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);
	
	// build the optical system
	TestSystem01.fillVectorSurfaceAndInteractingData(0, &SphericalSurfaceTS01_0, refrac.clone());
	TestSystem01.fillVectorSurfaceAndInteractingData(1, &SphericalSurfaceTS01_1, refrac.clone());
	TestSystem01.fillVectorSurfaceAndInteractingData(2, &SphericalSurfaceTS01_2, refrac.clone());
	TestSystem01.fillVectorSurfaceAndInteractingData(3, &SphericalSurfaceTS01_3, refrac.clone());
	TestSystem01.fillVectorSurfaceAndInteractingData(4, &AperturStopTS01_4, doNothing.clone());
	TestSystem01.fillVectorSurfaceAndInteractingData(5, &PlanSurfaceTS01_5, absorb.clone());
	
	//____
	//// test opt sys single ray
	//LightRayStruct testLightRay;
	//Light_LLT lightTest;
	//lightTest.setWavelength(550.0);
	//Ray_LLT testRay({ 0.0,0.0,0.0 }, { 0.0,-2.8293137790,10.269250408 }, 1.0);
	//testLightRay.setRay_LLT(testRay);
	//SequentialRayTracing testSeqTrace(TestSystem01);
	//testSeqTrace.sequentialRayTracing(testLightRay);
	//VectorStructR3 interPointPlanSurface = testSeqTrace.getAllInterInfosOfSurf_i(5).at(0).getIntersectionPoint();
	//____
	
	RayAiming checkRayAimingTS01_0(TestSystem01);
	VectorStructR3 startPoint01_0{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint01_0{ 1.2,-1.2,24.0 };
	LightRayStruct testLightRay01_0 = checkRayAimingTS01_0.calcRayThrowPointInApertureStop(startPoint01_0, targetPoint01_0, light, 1.0);
	SequentialRayTracing seqTrace01_0(TestSystem01);
	seqTrace01_0.sequentialRayTracing(testLightRay01_0);
	VectorStructR3 checkTS01 = seqTrace01_0.getAllInterPointsAtSurf_i(checkRayAimingTS01_0.getPositionApertureStop(TestSystem01)).at(0);
	bool ch01_0 = Math::compareTwoVectorStructR3(targetPoint01_0, checkTS01, 4);
	checkRayAiming.push_back(ch01_0);
	
	RayAiming checkRayAimingTS01_1(TestSystem01);
	VectorStructR3 rayDirectionTS01_0 = { 0.0,0.0,1.0 };
	VectorStructR3 targetPointTS01_2 = { 0.4 ,-0.4,24.0 };
	LightRayStruct testLightRay01_2 = checkRayAimingTS01_1.infinityRayAiming(rayDirectionTS01_0, targetPointTS01_2, light, 1.0);
	SequentialRayTracing seqTraceTS01_1(TestSystem01);
	seqTraceTS01_1.sequentialRayTracing(testLightRay01_2);
	checkTS01 = seqTraceTS01_1.getAllInterPointsAtSurf_i(checkRayAimingTS01_1.getPositionApertureStop(TestSystem01)).at(0);
	ch01_0 = Math::compareTwoVectorStructR3(targetPointTS01_2, checkTS01, 3);
	checkRayAiming.push_back(ch01_0);
	
	
	// Ray aiming from one point
	RayAiming checkRayAimingTS01_O0(TestSystem01);
	SequentialRayTracing seqTrace01_1(TestSystem01);
	// Test targets Ring
	double semiHeightTest01_0 = 1.2;
	VectorStructR3 startPoint01_01 = { 0.0,0.5,0.0 };
	VectorStructR3 apexAperture01_0 = { 0.0,0.0,24.0 };
	std::vector<bool> bool01_0;
	std::vector<VectorStructR3> interPoints01_0;
	LightRayStruct testLightRay01_1;
	VectorStructR3 checkTS01_0;
	bool cTS01_0;
	
	FillApertureStop fillAperStopRayAiming01_0;
	std::vector<VectorStructR3> pointsInApStopTS01_0 = fillAperStopRayAiming01_0.fillAS_withPoints(6, apexAperture01_0, { 0.0,0.0,1.0 }, semiHeightTest01_0);
	
	for (unsigned int i = 0; i < pointsInApStopTS01_0.size(); i++)
	{
		testLightRay01_1 = checkRayAimingTS01_O0.calcRayThrowPointInApertureStop(startPoint01_01, pointsInApStopTS01_0.at(i), light, 1.0);
		seqTrace01_1.sequentialRayTracing(testLightRay01_1);
		checkTS01_0 = seqTrace01_1.getAllInterPointsAtSurf_i(checkRayAimingTS01_O0.getPositionApertureStop(TestSystem01)).at(i);
		interPoints01_0.push_back(checkTS01_0);
		cTS01_0 = Math::compareTwoVectorStructR3(pointsInApStopTS01_0.at(i), checkTS01_0, 4);
		VectorStructR3 febonrwbow = pointsInApStopTS01_0.at(i);
		bool01_0.push_back(cTS01_0);
	}
	
	Spot spotTS01_01;
	real rmsTS01_01 = spotTS01_01.calcRMS(seqTrace01_1.getAllInterPointsAtSurf_i(5), seqTrace01_1.getAllInterPointsAtSurf_i(5).at(0)) * 1000;
	
	// Ray Aiming from infinity
	RayAiming checkRayAimingTS01_O1(TestSystem01);
	SequentialRayTracing seqTrace01_2(TestSystem01);
	VectorStructR3 rayDirection01_0 = { 0.0,0.0,1.0 };
	SequentialRayTracing seqTrace01_3(TestSystem01);
	LightRayStruct testLightRay01_3;
	VectorStructR3 checkTS01_1;
	std::vector<bool> bool01_1;
	std::vector<VectorStructR3> interPoints01_1;
	semiHeightTest01_0 = 0.4;
	FillApertureStop fillAperStopRayAiming01_1;
	std::vector<VectorStructR3> pointsInApStopTS01_1 = fillAperStopRayAiming01_1.fillAS_withPoints(6, apexAperture01_0, { 0.0,0.0,1.0 }, semiHeightTest01_0);
	
	for (unsigned int i = 0; i < pointsInApStopTS01_0.size(); i++)
	{
		testLightRay01_3 = checkRayAimingTS01_O0.infinityRayAiming(rayDirection01_0, pointsInApStopTS01_1.at(i), light, 1.0);
		seqTrace01_3.sequentialRayTracing(testLightRay01_3);
		checkTS01_1 = seqTrace01_3.getAllInterPointsAtSurf_i(checkRayAimingTS01_O1.getPositionApertureStop(TestSystem01)).at(i);
		interPoints01_1.push_back(checkTS01_1);
		cTS01_0 = Math::compareTwoVectorStructR3(pointsInApStopTS01_1.at(i), checkTS01_1, 4);
		bool01_1.push_back(cTS01_0);
	}
	
	Spot spotTS01_02;
	real rmsTS01_02 = spotTS01_02.calcRMS(seqTrace01_3.getAllInterPointsAtSurf_i(5), seqTrace01_3.getAllInterPointsAtSurf_i(5).at(0)) * 1000;
	
	// *****************************************************************************************************************
	// *****************************************************************************************************************
	//Example 0 (positive lens)
	// *****************************************************************************************************************
	
	OpticalSystem_LLT optSys_E0;
	
	// 0 surface
	SphericalSurface_LLT SphericalSurface0E0(/*radius*/15.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	// 1 surface
	SphericalSurface_LLT SphericalSurface1E0(/*radius*/15.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,30.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	// 2 surface
	ApertureStop_LLT AperturStopE0{/*semiHeight*/ 5, /*Apex*/{ 0.0,0.0,35.0 },/*direction*/ { 0.0,0.0,1.0 },
		/*refIndex*/ 1.0 };
	// 3 surface
	PlanGeometry_LLT PlanSurface3E0(/*semiHeight*/ 4.0, /*Apex*/{ 0.0,0.0,45.0 }, /*Direction*/{ 0.0,0.0,1.0 },
		/*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);
	
	
	// build the optical system
	optSys_E0.fillVectorSurfaceAndInteractingData(0, &SphericalSurface0E0, refrac.clone());
	optSys_E0.fillVectorSurfaceAndInteractingData(1, &SphericalSurface1E0, refrac.clone());
	optSys_E0.fillVectorSurfaceAndInteractingData(2, &AperturStopE0, doNothing.clone());
	optSys_E0.fillVectorSurfaceAndInteractingData(3, &PlanSurface3E0, absorb.clone());
	
	// --> check the optical system using single ray tracing!
	// testRay0
	Ray_LLT testRay0_E0(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.49668230404,0.49668230404,20.016455247 }, 1.0);
	light.setWavelength(550.0);
	LightRayStruct testtestLightRay0_E0(light, testRay0_E0, 1);
	SequentialRayTracing seqTraceTest0_E0(optSys_E0);
	seqTraceTest0_E0.sequentialRayTracing(testtestLightRay0_E0);
	VectorStructR3 testtestInter0_E0 = seqTraceTest0_E0.getAllInterPointsAtSurf_i(3).at(0);
	VectorStructR3 targetInter0_E0{ 0.39804352983, 0.39804352983, 45.0 };
	bool checkTestInter0_E0 = Math::compareTwoVectorStructR3(testtestInter0_E0, targetInter0_E0, 4);
	checkRayAiming.push_back(checkTestInter0_E0);
	// testRay1
	Ray_LLT testRay1_E0(/*origin*/{ 0.55901699437, 1.1180339887, 0.0 }, /*direction*/{ 0.235037048,0.470074097,20.105457681 }, 1.0);
	LightRayStruct testtestLightRay1_E0(light, testRay1_E0, 1);
	SequentialRayTracing seqTraceTest1_E0(optSys_E0);
	seqTraceTest1_E0.sequentialRayTracing(testtestLightRay1_E0);
	VectorStructR3 testInter1_E0 = seqTraceTest1_E0.getAllInterPointsAtSurf_i(3).at(0);
	VectorStructR3 targetInter1_E0{ 0.1140434275, 0.22808685515, 45.0 };
	bool checkTestInter1_E0 = Math::compareTwoVectorStructR3(testInter1_E0, targetInter1_E0, 4);
	checkRayAiming.push_back(checkTestInter1_E0);
	
	//___
	//0_E0
	RayAiming checkRayAiming0_E0(optSys_E0);
	VectorStructR3 startPoint0_E0{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint0_E0{ 1.0, 0.01 ,35.0 };
	LightRayStruct testLightRay0_E0 = checkRayAiming0_E0.calcRayThrowPointInApertureStop(startPoint0_E0, targetPoint0_E0, light, 1.0);
	SequentialRayTracing seqTrace0_E0(optSys_E0);
	seqTrace0_E0.sequentialRayTracing(testLightRay0_E0);
	int test = checkRayAiming0_E0.getPositionApertureStop(optSys_E0);
	VectorStructR3 check0_E0 = seqTrace0_E0.getAllInterPointsAtSurf_i(checkRayAiming0_E0.getPositionApertureStop(optSys_E0)).at(0);
	bool c0_E0 = Math::compareTwoVectorStructR3(targetPoint0_E0, check0_E0, 4);
	checkRayAiming.push_back(c0_E0);
	
	//___
	//1_E0
	RayAiming checkRayAiming1_E0(optSys_E0);
	VectorStructR3 startPoint1_E0{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint1_E0{ 0.5, -0.8,35.0 };
	LightRayStruct testLightRay1_E0 = checkRayAiming1_E0.calcRayThrowPointInApertureStop(startPoint1_E0, targetPoint1_E0, light, 1.0);
	SequentialRayTracing seqTrace1_E0(optSys_E0);
	seqTrace1_E0.sequentialRayTracing(testLightRay1_E0);
	VectorStructR3 check1_E0 = seqTrace1_E0.getAllInterPointsAtSurf_i(checkRayAiming1_E0.getPositionApertureStop(optSys_E0)).at(0);
	bool c1_E0 = Math::compareTwoVectorStructR3(targetPoint1_E0, check1_E0, 4);
	checkRayAiming.push_back(c1_E0);
	//___
	//2_E0
	RayAiming checkRayAiming2_E0(optSys_E0);
	VectorStructR3 startPoint2_E0{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint2_E0{ -0.5,0.6,35.0 };
	LightRayStruct testLightRay2_E0 = checkRayAiming2_E0.calcRayThrowPointInApertureStop(startPoint2_E0, targetPoint2_E0, light, 1.0);
	SequentialRayTracing seqTrace2_E0(optSys_E0);
	seqTrace2_E0.sequentialRayTracing(testLightRay2_E0);
	VectorStructR3 check2_E0 = seqTrace2_E0.getAllInterPointsAtSurf_i(checkRayAiming2_E0.getPositionApertureStop(optSys_E0)).at(0);
	bool c2_E0 = Math::compareTwoVectorStructR3(targetPoint2_E0, check2_E0, 4);
	checkRayAiming.push_back(c2_E0);
	//__
	//3_E0
	RayAiming checkRayAiming3_E0(optSys_E0);
	VectorStructR3 startPoint3_E0{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint3_E0{ 0.3,0.7,35.0 };
	LightRayStruct testLightRay3_E0 = checkRayAiming3_E0.calcRayThrowPointInApertureStop(startPoint3_E0, targetPoint3_E0, light, 1.0);
	SequentialRayTracing seqTrace3_E0(optSys_E0);
	seqTrace3_E0.sequentialRayTracing(testLightRay3_E0);
	VectorStructR3 check3_E0 = seqTrace3_E0.getAllInterPointsAtSurf_i(checkRayAiming3_E0.getPositionApertureStop(optSys_E0)).at(0);
	bool c3_E0 = Math::compareTwoVectorStructR3(targetPoint3_E0, check3_E0, 4);
	checkRayAiming.push_back(c3_E0);
	//__
	//4_E0
	RayAiming checkRayAiming4_E0(optSys_E0);
	VectorStructR3 startPoint4_E0{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint4_E0{ -0.8,-0.2,35.0 };
	LightRayStruct testLightRay4_E0 = checkRayAiming4_E0.calcRayThrowPointInApertureStop(startPoint4_E0, targetPoint4_E0, light, 1.0);
	SequentialRayTracing seqTrace4_E0(optSys_E0);
	seqTrace4_E0.sequentialRayTracing(testLightRay4_E0);
	VectorStructR3 check4_E0 = seqTrace4_E0.getAllInterPointsAtSurf_i(checkRayAiming4_E0.getPositionApertureStop(optSys_E0)).at(0);
	bool c4_E0 = Math::compareTwoVectorStructR3(targetPoint4_E0, check4_E0, 4);
	checkRayAiming.push_back(c4_E0);
	//__
	//5_E0
	RayAiming checkRayAiming5_E0(optSys_E0);
	VectorStructR3 startPoint5_E0{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint5_E0{ 1.0,0.0,35.0 };
	LightRayStruct testLightRay5_E0 = checkRayAiming5_E0.calcRayThrowPointInApertureStop(startPoint5_E0, targetPoint5_E0, light, 1.0);
	SequentialRayTracing seqTrace5_E0(optSys_E0);
	seqTrace5_E0.sequentialRayTracing(testLightRay5_E0);
	VectorStructR3 check5_E0 = seqTrace5_E0.getAllInterPointsAtSurf_i(checkRayAiming5_E0.getPositionApertureStop(optSys_E0)).at(0);
	bool c5_E0 = Math::compareTwoVectorStructR3(targetPoint5_E0, check5_E0, 4);
	checkRayAiming.push_back(c5_E0);
	//6_E0
	RayAiming checkRayAiming6_E0(optSys_E0);
	VectorStructR3 startPoint6_E0{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint6_E0{ 0.0,1.0,35.0 };
	LightRayStruct testLightRay6_E0 = checkRayAiming6_E0.calcRayThrowPointInApertureStop(startPoint6_E0, targetPoint6_E0, light, 1.0);
	SequentialRayTracing seqTrace6_E0(optSys_E0);
	seqTrace6_E0.sequentialRayTracing(testLightRay6_E0);
	VectorStructR3 check6_E0 = seqTrace6_E0.getAllInterPointsAtSurf_i(checkRayAiming6_E0.getPositionApertureStop(optSys_E0)).at(0);
	bool c6_E0 = Math::compareTwoVectorStructR3(targetPoint6_E0, check6_E0, 4);
	checkRayAiming.push_back(c6_E0);
	//7_E0
	RayAiming checkRayAiming7_E0(optSys_E0);
	VectorStructR3 startPoint7_E0{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint7_E0{ -1.0,0.0,35.0 };
	LightRayStruct testLightRay7_E0 = checkRayAiming7_E0.calcRayThrowPointInApertureStop(startPoint7_E0, targetPoint7_E0, light, 1.0);
	SequentialRayTracing seqTrace7_E0(optSys_E0);
	seqTrace7_E0.sequentialRayTracing(testLightRay7_E0);
	VectorStructR3 check7_E0 = seqTrace7_E0.getAllInterPointsAtSurf_i(checkRayAiming7_E0.getPositionApertureStop(optSys_E0)).at(0);
	bool c7_E0 = Math::compareTwoVectorStructR3(targetPoint7_E0, check7_E0, 4);
	checkRayAiming.push_back(c7_E0);
	//8_E0
	RayAiming checkRayAiming8_E0(optSys_E0);
	VectorStructR3 startPoint8_E0{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint8_E0{ 0.0,-1.0,35.0 };
	LightRayStruct testLightRay8_E0 = checkRayAiming8_E0.calcRayThrowPointInApertureStop(startPoint8_E0, targetPoint8_E0, light, 1.0);
	SequentialRayTracing seqTrace8_E0(optSys_E0);
	seqTrace8_E0.sequentialRayTracing(testLightRay8_E0);
	VectorStructR3 check8_E0 = seqTrace8_E0.getAllInterPointsAtSurf_i(checkRayAiming8_E0.getPositionApertureStop(optSys_E0)).at(0);
	bool c8_E0 = Math::compareTwoVectorStructR3(targetPoint8_E0, check8_E0, 4);
	checkRayAiming.push_back(c8_E0);
	//9_E0
	RayAiming checkRayAiming9_E0(optSys_E0);
	VectorStructR3 startPoint9_E0{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint9_E0{ 0.0,0.0,35.0 };
	LightRayStruct testLightRay9_E0 = checkRayAiming9_E0.calcRayThrowPointInApertureStop(startPoint9_E0, targetPoint9_E0, light, 1.0);
	SequentialRayTracing seqTrace9_E0(optSys_E0);
	seqTrace9_E0.sequentialRayTracing(testLightRay9_E0);
	VectorStructR3 check9_E0 = seqTrace9_E0.getAllInterPointsAtSurf_i(checkRayAiming9_E0.getPositionApertureStop(optSys_E0)).at(0);
	bool c9_E0 = Math::compareTwoVectorStructR3(targetPoint9_E0, check9_E0, 6);
	checkRayAiming.push_back(c9_E0);
	
	//10_E0 TODO Dominik: Hier wird ein Fehler geworfen.
	RayAiming checkRayAiming10_E0(optSys_E0);
	VectorStructR3 rayDirection10_E0{ 0.0,0.0,1.0 };
	VectorStructR3 targetPoint10_E0{ 0.0,0.5,35.0 };
	LightRayStruct testLightRay10_E0 = checkRayAiming10_E0.infinityRayAiming(rayDirection10_E0, targetPoint10_E0, light, 1.0);
	SequentialRayTracing seqTrace10_E0(optSys_E0);
	seqTrace10_E0.sequentialRayTracing(testLightRay10_E0);
	VectorStructR3 check10_E0 = seqTrace10_E0.getAllInterPointsAtSurf_i(checkRayAiming10_E0.getPositionApertureStop(optSys_E0)).at(0);
	bool c10_E0 = Math::compareTwoVectorStructR3(targetPoint10_E0, check10_E0, 6);
	checkRayAiming.push_back(c10_E0);
	
	RayAiming checkRayAiming11_E0(optSys_E0);
	VectorStructR3 rayDirection11_E0{ 0.0,0.08,1.0 };
	VectorStructR3 targetPoint11_E0{ 0.0,0.2,35.0 };
	LightRayStruct testLightRay11_E0 = checkRayAiming11_E0.infinityRayAiming(rayDirection11_E0, targetPoint11_E0, light, 1.0);
	SequentialRayTracing seqTrace11_E0(optSys_E0);
	seqTrace11_E0.sequentialRayTracing(testLightRay11_E0);
	VectorStructR3 check11_E0 = seqTrace11_E0.getAllInterPointsAtSurf_i(checkRayAiming11_E0.getPositionApertureStop(optSys_E0)).at(0);
	bool c11_E0 = Math::compareTwoVectorStructR3(targetPoint11_E0, check11_E0, 6);
	checkRayAiming.push_back(c11_E0);
	
	//////////////////////////////////////////////////////////////////////////
	
	// Ray aiming from infinity
	RayAiming checkRayAiming12_E0(optSys_E0);
	VectorStructR3 rayDirection12_E0{ 0.0,0.0,1.0 };
	// Test targets Ring
	double semiHeightTest = 1.0;
	VectorStructR3 apexAperture = { 0.0,0.0,35.0 };
	VectorStructR3 directionAperStop = { 0.0,0.0,1.0 };
	std::vector<bool> affe0;
	std::vector<VectorStructR3> interPoints1;
	LightRayStruct testLightRayI0_E0;
	RayAiming tempRayAiming0(optSys_E0);
	SequentialRayTracing seqTraceE0_ObjectTest(optSys_E0);
	VectorStructR3 checkI0_E0;
	bool cI0_E0;
	
	FillApertureStop fillAperStopRayAiming;
	std::vector<VectorStructR3> pointsInApStopE12 = fillAperStopRayAiming.fillAS_withPoints(6, apexAperture, { 0.0,0.0,1.0 }, semiHeightTest);
	
	for (unsigned int i = 0; i < pointsInApStopE12.size(); i++)
	{
		testLightRayI0_E0 = tempRayAiming0.infinityRayAiming({ 0.0,0.0,1.0 }, pointsInApStopE12.at(i), light, 1.0);
		seqTraceE0_ObjectTest.sequentialRayTracing(testLightRayI0_E0);
		checkI0_E0 = seqTraceE0_ObjectTest.getAllInterPointsAtSurf_i(tempRayAiming0.getPositionApertureStop(optSys_E0)).at(i);
		interPoints1.push_back(checkI0_E0);
		cI0_E0 = Math::compareTwoVectorStructR3(pointsInApStopE12.at(i), checkI0_E0, 6);
		affe0.push_back(cI0_E0);
	}
	
	
	std::vector<LightRayStruct> lightRayStrucVec = fillAperStopRayAiming.fillAperStopRayAimingInfinity(pointsInApStopE12, rayDirection12_E0, light, 1.0, optSys_E0);
	
	SequentialRayTracing seqTraceE12(optSys_E0);
	seqTraceE12.seqRayTracingWithVectorOfLightRays(lightRayStrucVec);
	
	
	
	Spot calcSpot;
	real rmsSpot = calcSpot.calcRMS(seqTraceE12.getAllInterPointsAtSurf_i(3), seqTraceE12.getAllInterPointsAtSurf_i(3).at(0)) * 1000;
	
	///////////////////////////////////////////////////////////
	// Ray aiming from one point
	FillApertureStop fillASRayAimingFromPoint;
	std::vector<LightRayStruct> lightRayStrucVecFromPoint = fillASRayAimingFromPoint.fillAperStopRayAimingFromPoint(pointsInApStopE12, { 0.0,0.0,0.0 }, light, 1.0, optSys_E0);
	SequentialRayTracing seqTraceE12FromPoint(optSys_E0);
	seqTraceE12FromPoint.seqRayTracingWithVectorOfLightRays(lightRayStrucVecFromPoint);
	RayAiming tempRayAiming(optSys_E0);
	LightRayStruct testLightRay15_E0;
	bool c15_E0;
	SequentialRayTracing seqTraceE15ObjectTest(optSys_E0);
	VectorStructR3 check15_E0;
	std::vector<bool> affe1;
	std::vector<VectorStructR3> interPoints2;
	for (unsigned int i = 0; i < pointsInApStopE12.size(); i++)
	{
		testLightRay15_E0 = tempRayAiming.calcRayThrowPointInApertureStop({ 0.0,0.0,0.0 }, pointsInApStopE12.at(i), light, 1.0);
		seqTraceE15ObjectTest.sequentialRayTracing(testLightRay15_E0);
		check15_E0 = seqTraceE15ObjectTest.getAllInterPointsAtSurf_i(tempRayAiming.getPositionApertureStop(optSys_E0)).at(i);
		interPoints2.push_back(check15_E0);
		c15_E0 = Math::compareTwoVectorStructR3(pointsInApStopE12.at(i), check15_E0, 6);
		affe1.push_back(c15_E0);
	}
	
	Spot spotFromPoint;
	real rmsSpotOnPoint = spotFromPoint.calcRMS(seqTraceE12FromPoint.getAllInterPointsAtSurf_i(3), seqTraceE12FromPoint.getAllInterPointsAtSurf_i(3).at(0)) * 1000;

		// *****************************************************************************************************************
	// *****************************************************************************************************************
	//Example 20 (positive lens)
	// *****************************************************************************************************************



	OpticalSystem_LLT optSys_E20;
	
	// 0 surface
	ApertureStop_LLT AperturStop0E20{/*semiHeight*/ 4, /*Apex*/{ 0.0,0.0,20.0 },/*direction*/ { 0.0,0.0,1.0 },
		/*refIndex*/ 1.0 };
	// 1 surface
	SphericalSurface_LLT SphericalSurface1E20(/*radius*/15.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,25.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	// 2 surface
	SphericalSurface_LLT SphericalSurface2E20(/*radius*/15.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,35.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	// 3 surface
	PlanGeometry_LLT PlanSurface3E20(/*semiHeight*/ 4.0, /*Apex*/{ 0.0,0.0,45.0 }, /*Direction*/{ 0.0,0.0,1.0 },
		/*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);
	
	// build the optical system
	optSys_E20.fillVectorSurfaceAndInteractingData(0, &AperturStop0E20, doNothing.clone());
	optSys_E20.fillVectorSurfaceAndInteractingData(1, &SphericalSurface1E20, refrac.clone());
	optSys_E20.fillVectorSurfaceAndInteractingData(2, &SphericalSurface2E20, refrac.clone());
	optSys_E20.fillVectorSurfaceAndInteractingData(3, &PlanSurface3E20, absorb.clone());
	
	RayAiming checkRayAiming20_E0(optSys_E20);
	VectorStructR3 startPoint20_E0{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint20_E0{ -0.5,0.5,20.0 };
	LightRayStruct testLightRay20_E20 = checkRayAiming20_E0.calcRayThrowPointInApertureStop(startPoint20_E0, targetPoint20_E0, light, 1.0);
	SequentialRayTracing seqTrace20_E0(optSys_E20);
	seqTrace20_E0.sequentialRayTracing(testLightRay20_E20);
	VectorStructR3 check20_E20 = seqTrace20_E0.getAllInterPointsAtSurf_i(checkRayAiming20_E0.getPositionApertureStop(optSys_E20)).at(0);
	bool c20_E20 = Math::compareTwoVectorStructR3(targetPoint20_E0, check20_E20, 7);
	checkRayAiming.push_back(c20_E20);
	
	// Ray aiming from infinity
	RayAiming checkRayAiming0_E20(optSys_E20);
	VectorStructR3 rayDirection20_E0{ 0.0,0.0,1.0 };
	// Test targets Ring
	semiHeightTest = 1.0;
	apexAperture = { 0.0,0.0,20.0 };
	directionAperStop = { 0.0,0.0,1.0 };
	
	FillApertureStop fillAperStopRayAiming_20;
	std::vector<VectorStructR3> pointsInApStopE20 = fillAperStopRayAiming_20.fillAS_withPoints(6, apexAperture, { 0.0,0.0,1.0 }, semiHeightTest);
	std::vector<LightRayStruct> lightRayStrucVec20 = fillAperStopRayAiming_20.fillAperStopRayAimingInfinity(pointsInApStopE20, rayDirection20_E0, light, 1.0, optSys_E20);
	
	SequentialRayTracing seqTraceE20(optSys_E20);
	seqTraceE20.seqRayTracingWithVectorOfLightRays(lightRayStrucVec20);
	
	Spot calcSpot20;
	real rmsSpot20I = calcSpot20.calcRMS(seqTraceE20.getAllInterPointsAtSurf_i(3), seqTraceE20.getAllInterPointsAtSurf_i(3).at(0)) * 1000;


		///////////////////////////////////////////////////////////
		// Ray aiming from one point
	FillApertureStop fillASRayAimingFromPoint20;
	std::vector<LightRayStruct> lightRayStrucVecFromPoint20 = fillASRayAimingFromPoint20.fillAperStopRayAimingFromPoint(pointsInApStopE20, { 0.0,0.0,0.0 }, light, 1.0, optSys_E20);
	SequentialRayTracing seqTraceE20FromPoint(optSys_E20);
	seqTraceE20FromPoint.seqRayTracingWithVectorOfLightRays(lightRayStrucVecFromPoint20);
	RayAiming tempRayAiming20(optSys_E20);
	LightRayStruct testLightRay20_E0;
	bool c20_E0;
	SequentialRayTracing seqTraceE20ObjectTest(optSys_E20);
	VectorStructR3 check20_E0;
	std::vector<bool> affe20;
	std::vector<VectorStructR3> interPoints20;
	for (unsigned int i = 0; i < pointsInApStopE20.size(); i++)
	{
		testLightRay20_E0 = tempRayAiming20.calcRayThrowPointInApertureStop({ 0.0,0.0,0.0 }, pointsInApStopE20.at(i), light, 1.0);
		seqTraceE20ObjectTest.sequentialRayTracing(testLightRay20_E0);
		check20_E0 = seqTraceE20ObjectTest.getAllInterPointsAtSurf_i(tempRayAiming20.getPositionApertureStop(optSys_E20)).at(i);
		interPoints20.push_back(check20_E0);
		c20_E0 = Math::compareTwoVectorStructR3(pointsInApStopE20.at(i), check20_E0, 6);
		affe20.push_back(c20_E0);
	}
	
	Spot spotFromPoint20;
	real rmsSpotOnPoint20 = spotFromPoint20.calcRMS(seqTraceE20FromPoint.getAllInterPointsAtSurf_i(3), seqTraceE20FromPoint.getAllInterPointsAtSurf_i(3).at(0)) * 1000;



		// *****************************************************************************************************************
		// *****************************************************************************************************************
		//Example 1 -> here we use the optical system from example 0
		// and start at the field (-0.5,0.0,0.0)
		// *****************************************************************************************************************
		//0_E1
	RayAiming checkRayAiming0_E1(optSys_E0);
	VectorStructR3 startPoint0_E1{ 0.5,0.0,0.0 };
	VectorStructR3 targetPoint0_E1{ 0.3,0.7,35.0 };
	LightRayStruct testLightRay0_E1 = checkRayAiming0_E1.calcRayThrowPointInApertureStop(startPoint0_E1, targetPoint0_E1, light, 1.0);
	SequentialRayTracing seqTrace0_E1(optSys_E0);
	seqTrace0_E1.sequentialRayTracing(testLightRay0_E1);
	VectorStructR3 check0_E1 = seqTrace0_E1.getAllInterPointsAtSurf_i(checkRayAiming0_E1.getPositionApertureStop(optSys_E0)).at(0);
	bool c0_E1 = Math::compareTwoVectorStructR3(targetPoint0_E1, check0_E1, 6);
	checkRayAiming.push_back(c0_E1);
	//1_E1
	RayAiming checkRayAiming1_E1(optSys_E0);
	VectorStructR3 startPoint1_E1{ 0.5,0.0,0.0 };
	VectorStructR3 targetPoint1_E1{ -0.2,0.8,35.0 };
	LightRayStruct testLightRay1_E1 = checkRayAiming1_E1.calcRayThrowPointInApertureStop(startPoint1_E1, targetPoint1_E1, light, 1.0);
	SequentialRayTracing seqTrace1_E1(optSys_E0);
	seqTrace1_E1.sequentialRayTracing(testLightRay1_E1);
	VectorStructR3 check1_E1 = seqTrace1_E1.getAllInterPointsAtSurf_i(checkRayAiming1_E1.getPositionApertureStop(optSys_E0)).at(0);
	bool c1_E1 = Math::compareTwoVectorStructR3(targetPoint1_E1, check1_E1, 6);
	checkRayAiming.push_back(c1_E1);
	//2_E1
	RayAiming checkRayAiming2_E1(optSys_E0);
	VectorStructR3 startPoint2_E1{ 0.5,0.0,0.0 };
	VectorStructR3 targetPoint2_E1{ 0.4,-0.6,35.0 };
	LightRayStruct testLightRay2_E1 = checkRayAiming2_E1.calcRayThrowPointInApertureStop(startPoint2_E1, targetPoint2_E1, light, 1.0);
	SequentialRayTracing seqTrace2_E1(optSys_E0);
	seqTrace2_E1.sequentialRayTracing(testLightRay2_E1);
	VectorStructR3 check2_E1 = seqTrace2_E1.getAllInterPointsAtSurf_i(checkRayAiming2_E1.getPositionApertureStop(optSys_E0)).at(0);
	bool c2_E1 = Math::compareTwoVectorStructR3(targetPoint2_E1, check2_E1, 6);
	checkRayAiming.push_back(c2_E1);
	//3_E1
	RayAiming checkRayAiming3_E1(optSys_E0);
	VectorStructR3 startPoint3_E1{ 0.5,0.0,0.0 };
	VectorStructR3 targetPoint3_E1{ -0.5,-0.6,35.0 };
	LightRayStruct testLightRay3_E1 = checkRayAiming3_E1.calcRayThrowPointInApertureStop(startPoint3_E1, targetPoint3_E1, light, 1.0); // hier gibt es einen Fehler
	SequentialRayTracing seqTrace3_E1(optSys_E0);
	seqTrace3_E1.sequentialRayTracing(testLightRay3_E1);
	VectorStructR3 check3_E1 = seqTrace3_E1.getAllInterPointsAtSurf_i(checkRayAiming3_E1.getPositionApertureStop(optSys_E0)).at(0);
	bool c3_E1 = Math::compareTwoVectorStructR3(targetPoint3_E1, check3_E1, 6);
	checkRayAiming.push_back(c3_E1);
	// *****************************************************************************************************************
	// *****************************************************************************************************************
	//Example 2 -> here we use the optical system from example 0
	// and start at the field (1.0,-0.5,0.0)
	// *****************************************************************************************************************
	//0_E2
	RayAiming checkRayAiming0_E2(optSys_E0);
	VectorStructR3 startPoint0_E2{ 1.0,-0.5,0.0 };
	VectorStructR3 targetPoint0_E2{ 0.0,0.5,35.0 };
	LightRayStruct testLightRay0_E2 = checkRayAiming0_E2.calcRayThrowPointInApertureStop(startPoint0_E2, targetPoint0_E2, light, 1.0);
	SequentialRayTracing seqTrace0_E2(optSys_E0);
	seqTrace0_E2.sequentialRayTracing(testLightRay0_E2);
	VectorStructR3 check0_E2 = seqTrace0_E2.getAllInterPointsAtSurf_i(checkRayAiming0_E2.getPositionApertureStop(optSys_E0)).at(0);
	bool c0_E2 = Math::compareTwoVectorStructR3(targetPoint0_E2, check0_E2, 6);
	checkRayAiming.push_back(c0_E2);
	//1_E2
	RayAiming checkRayAiming1_E2(optSys_E0);
	VectorStructR3 startPoint1_E2{ -0.7,0.3,0.0 };
	VectorStructR3 targetPoint1_E2{ 0.0,0.0,35.0 };
	LightRayStruct testLightRay1_E2 = checkRayAiming1_E2.calcRayThrowPointInApertureStop(startPoint1_E2, targetPoint1_E2, light, 1.0);
	SequentialRayTracing seqTrace1_E2(optSys_E0);
	seqTrace1_E2.sequentialRayTracing(testLightRay1_E2);
	VectorStructR3 check1_E2 = seqTrace1_E2.getAllInterPointsAtSurf_i(checkRayAiming1_E2.getPositionApertureStop(optSys_E0)).at(0);
	bool c1_E2 = Math::compareTwoVectorStructR3(targetPoint1_E2, check1_E2, 6);
	checkRayAiming.push_back(c1_E2);
	//2_E3
	RayAiming checkRayAiming2_E2(optSys_E0);
	VectorStructR3 startPoint2_E2{ 1.0,-0.5,0.0 };
	VectorStructR3 targetPoint2_E2{ 0.1,-0.001,35.0 };
	LightRayStruct testLightRay2_E2 = checkRayAiming2_E2.calcRayThrowPointInApertureStop(startPoint2_E2, targetPoint2_E2, light, 1.0);
	SequentialRayTracing seqTrace2_E2(optSys_E0);
	seqTrace2_E2.sequentialRayTracing(testLightRay2_E2);
	VectorStructR3 check2_E2 = seqTrace2_E2.getAllInterPointsAtSurf_i(checkRayAiming2_E2.getPositionApertureStop(optSys_E0)).at(0);
	bool c2_E2 = Math::compareTwoVectorStructR3(targetPoint2_E2, check2_E2, 6);
	checkRayAiming.push_back(c2_E2);
	//3_E3
	RayAiming checkRayAiming3_E2(optSys_E0);
	VectorStructR3 startPoint3_E2{ 1.0,-0.5,0.0 };
	VectorStructR3 targetPoint3_E2{ -0.6,0.6,35.0 };
	LightRayStruct testLightRay3_E2 = checkRayAiming3_E2.calcRayThrowPointInApertureStop(startPoint3_E2, targetPoint3_E2, light, 1.0);
	SequentialRayTracing seqTrace3_E2(optSys_E0);
	seqTrace3_E2.sequentialRayTracing(testLightRay3_E2);
	VectorStructR3 check3_E2 = seqTrace3_E2.getAllInterPointsAtSurf_i(checkRayAiming3_E2.getPositionApertureStop(optSys_E0)).at(0);
	bool c3_E2 = Math::compareTwoVectorStructR3(targetPoint3_E2, check3_E2, 6);
	checkRayAiming.push_back(c3_E2);
	
	
	// *****************************************************************************************************************
	// *****************************************************************************************************************
	//Example 4 (negative lens)
	// *****************************************************************************************************************
	// 0 surface
	SphericalSurface_LLT SphericalSurface0E4(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	// 1 surface
	SphericalSurface_LLT SphericalSurface1E4(/*radius*/5.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,30.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	// 2 surface
	ApertureStop_LLT AperturStopE4{/*semiHeight*/ 10, /*Apex*/{ 0.0,0.0,35.0 },/*direction*/ { 0.0,0.0,1.0 },
		/*refIndex*/ 1.0 };
	// 3 surface
	PlanGeometry_LLT PlanSurface3E4(/*semiHeight*/ 4.0, /*Apex*/{ 0.0,0.0,45.0 }, /*Direction*/{ 0.0,0.0,1.0 },
		/*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);
	
	// build the optical system
	OpticalSystem_LLT optSys_E4;
	optSys_E4.fillVectorSurfaceAndInteractingData(0, &SphericalSurface0E4, refrac.clone());
	optSys_E4.fillVectorSurfaceAndInteractingData(1, &SphericalSurface1E4, refrac.clone());
	optSys_E4.fillVectorSurfaceAndInteractingData(2, &AperturStopE4, doNothing.clone());
	optSys_E4.fillVectorSurfaceAndInteractingData(3, &PlanSurface3E4, absorb.clone());
	
	//_____________________________________________________________
	// --> check the optical system using single ray tracing!
	// testRay0E4
	Ray_LLT testRay0_E4(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0,0.33196029542,19.994488599 }, 1.0);
	LightRayStruct testLightRay0_E4(light, testRay0_E4, 1);
	SequentialRayTracing seqTraceTest0_E4(optSys_E4);
	seqTraceTest0_E4.sequentialRayTracing(testLightRay0_E4);
	VectorStructR3 testInter0_E4 = seqTraceTest0_E4.getAllInterPointsAtSurf_i(3).at(0);
	VectorStructR3 targetInter0_E4{ 0.0, 1.8972259576, 45.0 };
	bool checkTestInter0_E4 = Math::compareTwoVectorStructR3(testInter0_E4, targetInter0_E4, 6);
	checkRayAiming.push_back(checkTestInter0_E4);
	
	// testRay1E4
	Ray_LLT testRay1_E4(/*origin*/{ -0.55901699437, 1.1180339887, 0.0 }, /*direction*/{ 0.419222684,-0.506454807,19.98030202 }, 1.0);
	LightRayStruct testLightRay1_E4(light, testRay1_E4, 1);
	SequentialRayTracing seqTraceTest1_E4(optSys_E4);
	seqTraceTest1_E4.sequentialRayTracing(testLightRay1_E4);
	VectorStructR3 testtestInter1_E4 = seqTraceTest1_E4.getAllInterPointsAtSurf_i(3).at(0);
	VectorStructR3 targetInter1_E4{ 0.093073982206, 1.7112959338, 45.0 };
	bool checkTestInter1_E4 = Math::compareTwoVectorStructR3(testtestInter1_E4, targetInter1_E4, 6);
	checkRayAiming.push_back(checkTestInter1_E4);
	
	// testRay21E4
	Ray_LLT testRay21_E4(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0 ,0.033331978772,19.999944449 }, 1.0);
	LightRayStruct testLightRay21_E4(light, testRay21_E4, 1);
	SequentialRayTracing seqTraceTest21_E4(optSys_E4);
	seqTraceTest21_E4.sequentialRayTracing(testLightRay21_E4);
	VectorStructR3 testtestInter21_E4 = seqTraceTest21_E4.getAllInterPointsAtSurf_i(2).at(0);
	VectorStructR3 targetInter21_E4{ 0.0, 0.1, 35.0 };
	bool checkTestInter21_E4 = Math::compareTwoVectorStructR3(testtestInter21_E4, targetInter21_E4, 6);
	checkRayAiming.push_back(checkTestInter21_E4);

	//_____________________________________________________________
	
	//___
	//0_E4
	RayAiming checkRayAiming0_E4(optSys_E4);
	VectorStructR3 startPoint0_E4{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint0_E4{ 0.0,0.1,35.0 };
	LightRayStruct testtestLightRay0_E4 = checkRayAiming0_E4.calcRayThrowPointInApertureStop(startPoint0_E4, targetPoint0_E4, light, 1.0);
	SequentialRayTracing seqTrace0_E4(optSys_E4);
	seqTrace0_E4.sequentialRayTracing(testtestLightRay0_E4);
	VectorStructR3 check0_E4 = seqTrace0_E4.getAllInterPointsAtSurf_i(checkRayAiming0_E4.getPositionApertureStop(optSys_E4)).at(0);
	bool c0_E4 = Math::compareTwoVectorStructR3(targetPoint0_E4, check0_E4, 6);
	checkRayAiming.push_back(c0_E4);
	//1_E4
	RayAiming checkRayAiming1_E4(optSys_E4);
	VectorStructR3 startPoint1_E4{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint1_E4{ -0.6,0.4,35.0 };
	LightRayStruct testtestLightRay1_E4 = checkRayAiming1_E4.calcRayThrowPointInApertureStop(startPoint1_E4, targetPoint1_E4, light, 1.0);
	SequentialRayTracing seqTrace1_E4(optSys_E4);
	seqTrace1_E4.sequentialRayTracing(testtestLightRay1_E4);
	VectorStructR3 check1_E4 = seqTrace1_E4.getAllInterPointsAtSurf_i(checkRayAiming1_E4.getPositionApertureStop(optSys_E4)).at(0);
	bool c1_E4 = Math::compareTwoVectorStructR3(targetPoint1_E4, check1_E4, 6);
	checkRayAiming.push_back(c1_E4);
	//2_E4
	RayAiming checkRayAiming2_E4(optSys_E4);
	VectorStructR3 startPoint2_E4{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint2_E4{ 0.2,-0.6,35.0 };
	LightRayStruct testLightRay2_E4 = checkRayAiming2_E4.calcRayThrowPointInApertureStop(startPoint2_E4, targetPoint2_E4, light, 1.0);
	SequentialRayTracing seqTrace2_E4(optSys_E4);
	seqTrace2_E4.sequentialRayTracing(testLightRay2_E4);
	VectorStructR3 check2_E4 = seqTrace2_E4.getAllInterPointsAtSurf_i(checkRayAiming2_E4.getPositionApertureStop(optSys_E4)).at(0);
	bool c2_E4 = Math::compareTwoVectorStructR3(targetPoint2_E4, check2_E4, 6);
	checkRayAiming.push_back(c2_E4);
	//3_E4
	RayAiming checkRayAiming3_E4(optSys_E4);
	VectorStructR3 startPoint3_E4{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint3_E4{ -0.4,-0.2,35.0 };
	LightRayStruct testLightRay3_E4 = checkRayAiming3_E4.calcRayThrowPointInApertureStop(startPoint3_E4, targetPoint3_E4, light, 1.0);
	SequentialRayTracing seqTrace3_E4(optSys_E4);
	seqTrace3_E4.sequentialRayTracing(testLightRay3_E4);
	VectorStructR3 check3_E4 = seqTrace3_E4.getAllInterPointsAtSurf_i(checkRayAiming3_E4.getPositionApertureStop(optSys_E4)).at(0);
	bool c3_E4 = Math::compareTwoVectorStructR3(targetPoint3_E4, check3_E4, 6);
	checkRayAiming.push_back(c3_E4);
	// *****************************************************************************************************************
	// *****************************************************************************************************************
	//Example 5 -> here we use the optical system from example 4
	// and start at the field (-0.5,1.0,0.0)
	// *****************************************************************************************************************
	//0_E5
	RayAiming checkRayAiming0_E5(optSys_E4);
	VectorStructR3 startPoint0_E5{ -0.5,1.0,0.0 };
	VectorStructR3 targetPoint0_E5{ 0.1,0.3,35.0 };
	LightRayStruct testLightRay0_E5 = checkRayAiming0_E5.calcRayThrowPointInApertureStop(startPoint0_E5, targetPoint0_E5, light, 1.0);
	SequentialRayTracing seqTrace0_E5(optSys_E4);
	seqTrace0_E5.sequentialRayTracing(testLightRay0_E5);
	VectorStructR3 check0_E5 = seqTrace0_E5.getAllInterPointsAtSurf_i(checkRayAiming0_E5.getPositionApertureStop(optSys_E4)).at(0);
	bool c0_E5 = Math::compareTwoVectorStructR3(targetPoint0_E5, check0_E5, 6);
	checkRayAiming.push_back(c0_E5);
	//1_E5
	RayAiming checkRayAiming1_E5(optSys_E4);
	VectorStructR3 startPoint1_E5{ -0.5,1.0,0.0 };
	VectorStructR3 targetPoint1_E5{ -0.4,0.2,35.0 };
	LightRayStruct testLightRay1_E5 = checkRayAiming1_E5.calcRayThrowPointInApertureStop(startPoint1_E5, targetPoint1_E5, light, 1.0);
	SequentialRayTracing seqTrace1_E5(optSys_E4);
	seqTrace1_E5.sequentialRayTracing(testLightRay1_E5);
	VectorStructR3 check1_E5 = seqTrace1_E5.getAllInterPointsAtSurf_i(checkRayAiming1_E5.getPositionApertureStop(optSys_E4)).at(0);
	bool c1_E5 = Math::compareTwoVectorStructR3(targetPoint1_E5, check1_E5, 6);
	checkRayAiming.push_back(c1_E5);
	//2_E5
	RayAiming checkRayAiming2_E5(optSys_E4);
	VectorStructR3 startPoint2_E5{ -0.5,1.0,0.0 };
	VectorStructR3 targetPoint2_E5{ 0.0,0.0,35.0 };
	LightRayStruct testLightRay2_E5 = checkRayAiming2_E5.calcRayThrowPointInApertureStop(startPoint2_E5, targetPoint2_E5, light, 1.0);
	SequentialRayTracing seqTrace2_E5(optSys_E4);
	seqTrace2_E5.sequentialRayTracing(testLightRay2_E5);
	VectorStructR3 check2_E5 = seqTrace2_E5.getAllInterPointsAtSurf_i(checkRayAiming2_E5.getPositionApertureStop(optSys_E4)).at(0);
	bool c2_E5 = Math::compareTwoVectorStructR3(targetPoint2_E5, check2_E5, 6);
	checkRayAiming.push_back(c2_E5);
	//3_E5
	RayAiming checkRayAiming3_E5(optSys_E4);
	VectorStructR3 startPoint3_E5{ -0.5,1.0,0.0 };
	VectorStructR3 targetPoint3_E5{ -0.1,0.9,35.0 };
	LightRayStruct testLightRay3_E5 = checkRayAiming3_E5.calcRayThrowPointInApertureStop(startPoint3_E5, targetPoint3_E5, light, 1.0);
	SequentialRayTracing seqTrace3_E5(optSys_E4);
	seqTrace3_E5.sequentialRayTracing(testLightRay3_E5);
	VectorStructR3 check3_E5 = seqTrace3_E5.getAllInterPointsAtSurf_i(checkRayAiming3_E5.getPositionApertureStop(optSys_E4)).at(0);
	bool c3_E5 = Math::compareTwoVectorStructR3(targetPoint3_E5, check3_E5, 6);
	checkRayAiming.push_back(c3_E5);
	//4_E5
	RayAiming checkRayAiming4_E5(optSys_E4);
	VectorStructR3 startPoint4_E5{ 0.5,1.0,0.0 };
	VectorStructR3 targetPoint4_E5{ 0.0,0.0,35.0 };
	LightRayStruct testLightRay4_E5 = checkRayAiming4_E5.calcRayThrowPointInApertureStop(startPoint4_E5, targetPoint4_E5, light, 1.0);
	SequentialRayTracing seqTrace4_E5(optSys_E4);
	seqTrace4_E5.sequentialRayTracing(testLightRay4_E5);
	VectorStructR3 check4_E5 = seqTrace4_E5.getAllInterPointsAtSurf_i(checkRayAiming4_E5.getPositionApertureStop(optSys_E4)).at(0);
	bool c4_E5 = Math::compareTwoVectorStructR3(targetPoint4_E5, check4_E5, 6);
	checkRayAiming.push_back(c4_E5);

	
	// *****************************************************************************************************************
	// *****************************************************************************************************************
	//Example 6 -> here we use the optical system from example 4
	// and start at the field (0.3,-0.7,0.0)
	// *****************************************************************************************************************
	//0_E6
	RayAiming checkRayAiming0_E6(optSys_E4);
	VectorStructR3 startPoint0_E6{ 0.3,-0.7,0.0 };
	VectorStructR3 targetPoint0_E6{ 0.9,0.1,35.0 };
	LightRayStruct testLightRay0_E6 = checkRayAiming0_E6.calcRayThrowPointInApertureStop(startPoint0_E6, targetPoint0_E6, light, 1.0);
	SequentialRayTracing seqTrace0_E6(optSys_E4);
	seqTrace0_E6.sequentialRayTracing(testLightRay0_E6);
	VectorStructR3 check0_E6 = seqTrace0_E6.getAllInterPointsAtSurf_i(checkRayAiming0_E6.getPositionApertureStop(optSys_E4)).at(0);
	bool c0_E6 = Math::compareTwoVectorStructR3(targetPoint0_E6, check0_E6, 6);
	checkRayAiming.push_back(c0_E6);
	//1_E6
	RayAiming checkRayAiming1_E6(optSys_E4);
	VectorStructR3 startPoint1_E6{ 0.3,-0.7,0.0 };
	VectorStructR3 targetPoint1_E6{ -1.0,0.0,35.0 };
	LightRayStruct testLightRay1_E6 = checkRayAiming1_E6.calcRayThrowPointInApertureStop(startPoint1_E6, targetPoint1_E6, light, 1.0);
	SequentialRayTracing seqTrace1_E6(optSys_E4);
	seqTrace1_E6.sequentialRayTracing(testLightRay1_E6);
	VectorStructR3 check1_E6 = seqTrace1_E6.getAllInterPointsAtSurf_i(checkRayAiming1_E6.getPositionApertureStop(optSys_E4)).at(0);
	bool c1_E6 = Math::compareTwoVectorStructR3(targetPoint1_E6, check1_E6, 6);
	checkRayAiming.push_back(c1_E6);
	//2_E6
	RayAiming checkRayAiming2_E6(optSys_E4);
	VectorStructR3 startPoint2_E6{ 0.3,-0.7,0.0 };
	VectorStructR3 targetPoint2_E6{ 0.0,-1.0,35.0 };
	LightRayStruct testLightRay2_E6 = checkRayAiming2_E6.calcRayThrowPointInApertureStop(startPoint2_E6, targetPoint2_E6, light, 1.0);
	SequentialRayTracing seqTrace2_E6(optSys_E4);
	seqTrace2_E6.sequentialRayTracing(testLightRay2_E6);
	VectorStructR3 check2_E6 = seqTrace2_E6.getAllInterPointsAtSurf_i(checkRayAiming2_E6.getPositionApertureStop(optSys_E4)).at(0);
	bool c2_E6 = Math::compareTwoVectorStructR3(targetPoint2_E6, check2_E6, 6);
	checkRayAiming.push_back(c2_E6);
	//3_E6
	RayAiming checkRayAiming3_E6(optSys_E4);
	VectorStructR3 startPoint3_E6{ 0.3,-0.7,0.0 };
	VectorStructR3 targetPoint3_E6{ -0.5,-0.4,35.0 };
	LightRayStruct testLightRay3_E6 = checkRayAiming3_E6.calcRayThrowPointInApertureStop(startPoint3_E6, targetPoint3_E6, light, 1.0);
	SequentialRayTracing seqTrace3_E6(optSys_E4);
	seqTrace3_E6.sequentialRayTracing(testLightRay3_E6);
	VectorStructR3 check3_E6 = seqTrace3_E6.getAllInterPointsAtSurf_i(checkRayAiming3_E6.getPositionApertureStop(optSys_E4)).at(0);
	bool c3_E6 = Math::compareTwoVectorStructR3(targetPoint3_E6, check3_E6, 6);
	checkRayAiming.push_back(c3_E6);



	
	// 0 surface
	SphericalSurface_LLT SphericalSurface0E5(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,15.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	// 1 surface
	SphericalSurface_LLT SphericalSurface1E5(/*radius*/10.0, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0,0.0,20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	// 2 surface
	ApertureStop_LLT AperturStopE5{/*semiHeight*/ 1.0, /*Apex*/{ 0.0,0.0,25.0 },/*direction*/ { 0.0,0.0,1.0 },
		/*refIndex*/ 1.0 };
	// 3 surface
	PlanGeometry_LLT PlanSurface3E5(/*semiHeight*/ 5.0, /*Apex*/{ 0.0,0.0,35.0 }, /*Direction*/{ 0.0,0.0,1.0 },
		/*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);
	
	// build the optical system
	OpticalSystem_LLT optSys_E10;
	optSys_E10.fillVectorSurfaceAndInteractingData(0, &SphericalSurface0E5, refrac.clone());
	optSys_E10.fillVectorSurfaceAndInteractingData(1, &SphericalSurface1E5, refrac.clone());
	optSys_E10.fillVectorSurfaceAndInteractingData(2, &AperturStopE5, doNothing.clone());
	optSys_E10.fillVectorSurfaceAndInteractingData(3, &PlanSurface3E5, absorb.clone());
	
	RayAiming checkRayAiming0_E10(optSys_E10);
	VectorStructR3 startPoint0_E10{ 0.0,0.0,0.0 };
	VectorStructR3 targetPoint0_E10{ 0.0,-0.4,25.0 };
	LightRayStruct testLightRay0_E10 = checkRayAiming0_E10.calcRayThrowPointInApertureStop(startPoint0_E10, targetPoint0_E10, light, 1.0);
	SequentialRayTracing seqTrace0_E10(optSys_E10);
	seqTrace0_E10.sequentialRayTracing(testLightRay0_E10);
	VectorStructR3 check0_E10 = seqTrace0_E10.getAllInterPointsAtSurf_i(checkRayAiming0_E10.getPositionApertureStop(optSys_E10)).at(0);
	bool c0_E10 = Math::compareTwoVectorStructR3(targetPoint0_E10, check0_E10, 6);
	checkRayAiming.push_back(c0_E10);



	bool output = Math::checkTrueOfVectorElements(checkRayAiming);
	return output;

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
		singleCheckInterPoint = Math::compareTwoVectorStructR3(fillAperStop.getPointsInAS().at(i), checker, 4);
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
	bool returnChecker = Math::compareTwoVectorStructR3(targetPoint, checker, 4);

	return returnChecker;
}

bool BenchmarkRayAiming::checkRayAimingSingleRay_inf(/*opt sys LLT*/ OpticalSystem_LLT& const optSys_LLT, /*ray direction*/ VectorStructR3& const rayDirection, /*target point*/ VectorStructR3& const  targetPoint, /*light*/ Light_LLT& const Light)
{

	RayAiming RayAiming(optSys_LLT);
	////VectorStructR3 rayDirectionTS00_2 = { 0.0,0.0,1.0 };
	//VectorStructR3 targetPointTS00_2 = { 0.7 ,-0.02,20.0 };
	LightRayStruct testLightRay = RayAiming.infinityRayAiming(rayDirection, targetPoint, Light, 1.0);
	SequentialRayTracing seqTrace(optSys_LLT);
	seqTrace.sequentialRayTracing(testLightRay);
	VectorStructR3 checkerPoint = seqTrace.getAllInterPointsAtSurf_i(RayAiming.getPositionApertureStop(optSys_LLT)).at(0);
	bool returnChecker = Math::compareTwoVectorStructR3(targetPoint, checkerPoint, 4);

	return returnChecker;
}

bool BenchmarkRayAiming::checkRayAimingManyRay_inf(/*opt sys LLT*/ OpticalSystem_LLT& const optSys_LLT, /*ray direction*/ VectorStructR3& const rayDirection, /*rings*/ unsigned int& const ringsAB,/*arms*/ unsigned int& const armsAB,/*light*/ Light_LLT& const Light)
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
	bool checker{};
	RayAiming RayAiming(optSys_LLT);
	SequentialRayTracing seqTrace(optSys_LLT);
	LightRayStruct testLightRay;
	VectorStructR3 checkerPoint;
	std::vector<bool> cheker_vec;
	//std::vector<VectorStructR3> interPoints05_5;
	FillApertureStop fillAperStop;
	std::vector<VectorStructR3> pointsInApStop = fillAperStop.fillAS_withPoints(ringsAB, pointApertureStop, directionApertureStop, semiHeightApertureStop);

	for (unsigned int i = 0; i < pointsInApStop.size(); i++)
	{
		testLightRay = RayAiming.infinityRayAiming(rayDirection, pointsInApStop.at(i), Light, 1.0);
		seqTrace.sequentialRayTracing(testLightRay);
		checkerPoint = seqTrace.getAllInterPointsAtSurf_i(posApertureStop)[i];
		checker = Math::compareTwoVectorStructR3(pointsInApStop.at(i), checkerPoint, 3);
		if (checker == false)
		{
			std::cout << "target point: " << std::endl;
			pointsInApStop[i].print();
			std::cout << "point by ray tracing: " << std::endl;
			checkerPoint.print();
		}

		cheker_vec.push_back(checker);
	}
	

	return Math::checkTrueOfVectorElements(cheker_vec);

}