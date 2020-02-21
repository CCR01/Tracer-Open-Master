#include "testCalcCombinationVector_Paraxial.h"

#include "..\..\OptimizeSystem\EvaluateManyOptSystems_ParaxialDistances.h"

// surfaces
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\PlanElement.h"
#include "..\..\SurfaceElements\ApertureStopElement.h"

// interactions
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"

// glasses
#include "..\..\Glasses\Glasses.h"

#include "..\..\FillAptertureStop\FillApertureStop.h"
#include "..\..\Analyse\Spot.h"

testCalcComVec_Paraxial::testCalcComVec_Paraxial() {}

testCalcComVec_Paraxial::~testCalcComVec_Paraxial() {}

bool testCalcComVec_Paraxial::testCalcComVec_SuperFct_Paraxial()
{
	std::vector<bool> workCalcComVec_superFct;


	bool workE0 = testCalcComVec_E0();
	workCalcComVec_superFct.push_back(workE0);
	bool workE1 = testCalcComVec_E1();
	workCalcComVec_superFct.push_back(workE1);
	bool workE2 = testCalcComVec_E2();
	workCalcComVec_superFct.push_back(workE2);
	bool workE3 = testCalcComVec_E3();
	workCalcComVec_superFct.push_back(workE3);

	bool returnCheckerSuperFct = Math::checkTrueOfVectorElements(workCalcComVec_superFct);
	return returnCheckerSuperFct;

}


bool testCalcComVec_Paraxial::testCalcComVec_E0()
{
	std::vector<bool> workCalcComVec_E0;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	// set the wavelength
	real primWavelength = 550.0;
	Light_LLT Light_E0;
	Light_E0.setWavelength(550.0);
	Light_E0.setIntensity(1.0);
	std::vector<Light_LLT> lichtVecE0{ Light_E0 };


	// surfaces E0
	ApertureStopElement AperStop0_E0(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAirZemax());
	SphericalElement Sphere1_E0(/*radius*/ 10.0, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBK7_S1());
	SphericalElement Sphere2_E0(/*radius*/ 20.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBK7_S1());
	SphericalElement Sphere3_E0(/*radius*/ 70.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF13_S1(), /*refractive index B*/glasses.getAirZemax());
	SphericalElement Sphere4_E0(/*radius*/ 50.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF13_S1());
	PlanElement Plan5_E0(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,55.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAirZemax(), /*refractive index B*/ glasses.getAirZemax());

	Sphere1_E0.setParameterRadius(-70.0, 70.0, 0.0, typeModifierVariable);
	Sphere3_E0.setParameterRadius(-60.0, 70.0, 0.0, typeModifierVariable);

	surfacePtr Aper0_E0_ptr = AperStop0_E0.clone();
	surfacePtr Sphere1_E0_ptr = Sphere1_E0.clone();
	surfacePtr Sphere2_E0_ptr = Sphere2_E0.clone();
	surfacePtr Sphere3_E0_ptr = Sphere3_E0.clone();
	surfacePtr Sphere4_E0_ptr = Sphere4_E0.clone();
	surfacePtr Plan5_E0_ptr = Plan5_E0.clone();

	std::vector<surfacePtr> opticalSystemE0_ptr{ Aper0_E0_ptr, Sphere1_E0_ptr, Sphere2_E0_ptr , Sphere3_E0_ptr, Sphere4_E0_ptr, Plan5_E0_ptr };
	std::vector<interaction_ptr> interactionsE0_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement_E0(opticalSystemE0_ptr, interactionsE0_ptr);

	// def steps variables
	stepsWithoutMinWithoutMax addInfosVarS1(1, 10, 0.0, 0.0);
	stepsWithoutMinWithoutMax addInfosVarS2(3, 10, 0.0, 0.0);
	std::vector<stepsWithoutMinWithoutMax> addInfosVariable{ addInfosVarS1,addInfosVarS2 };

	StartRayPos startRayPos = notInfinity;

	// calc the combination vectors
	EvaluateManyOptSystems_ParaxialDistances calcCombVec_E0(/*optical System Element*/ optSystemElement_E0, /* add infos*/ addInfosVariable, /*start point ray*/startRayPos, /*prim wavelenght*/ primWavelength);

	OpticalSystem_LLT bestOptSys = calcCombVec_E0.getBestOptSys();
	SequentialRayTracing seqTraceE0(bestOptSys);
	Light_LLT light(550.0, 1, { 0.0,0.0,0.0,0.0 }, typeLightRay, 1);

	FillApertureStop fillAperE0(/*start point rays*/{ 0.0,0.0,0.0 },/*semi height of aperture stop*/ 1.0,/*point of aperture stop*/{ 0.0,0.0,20.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/6,/*arms*/ 8,/*refractive index*/ 1.0,/*wavelength*/ light);
	seqTraceE0.seqRayTracingWithVectorOfLightRays(fillAperE0.getVectorWithLightRays());

	Spot spotE0(seqTraceE0.getAllInterPointsAtSurf_i(5), seqTraceE0.getAllInterPointsAtSurf_i(5).at(0));
	real rmsSpotE0 = spotE0.getRMS_µm();
	real excelBest_Zemax_RMS = 47.641;
	bool checkE0_rmsBest = Math::compareTwoNumbers_decimals(excelBest_Zemax_RMS, rmsSpotE0, 2);
	workCalcComVec_E0.push_back(checkE0_rmsBest);


	bool returnCheckerE0 = Math::checkTrueOfVectorElements(workCalcComVec_E0);

	return returnCheckerE0;
}



bool testCalcComVec_Paraxial::testCalcComVec_E1()
{
	std::vector<bool> workCalcComVec_E1;

	std::vector<bool> workBuildSysForCom_E1;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;


	// set the wavelength
	real primWavelength = 550.0;
	Light_LLT Light_E1;
	Light_E1.setWavelength(550.0);
	Light_E1.setIntensity(1.0);
	std::vector<Light_LLT> lichtVecE2{ Light_E1 };


	// surfaces E1
	ApertureStopElement AperStop0_E1(/* semi height*/1.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAirZemax());
	SphericalElement Sphere1_E1(/*radius*/ 10.0, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBK7_S1());
	SphericalElement Sphere2_E1(/*radius*/ 70.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF6_S1(), /*refractive index B*/glasses.getBK7_S1());
	SphericalElement Sphere3_E1(/*radius*/ 50.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere4_E1(/*radius*/ 15.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF13_S1());
	SphericalElement Sphere5_E1(/*radius*/ 20.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF13_S1(), /*refractive index B*/glasses.getBK7_S1());
	SphericalElement Sphere6_E1(/*radius*/ 30.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBK7_S1());
	PlanElement Plan7_E1(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,50.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAirZemax(), /*refractive index B*/ glasses.getAirZemax());

	Sphere2_E1.setParameterRadius(-50.0, 50.0, 0.0, typeModifierVariable);
	Sphere2_E1.setParameterPointZ(15.0, 25.0, 0.0, typeModifierVariable);


	surfacePtr Aper0_E1_ptr = AperStop0_E1.clone();
	surfacePtr Sphere1_E1_ptr = Sphere1_E1.clone();
	surfacePtr Sphere2_E1_ptr = Sphere2_E1.clone();
	surfacePtr Sphere3_E1_ptr = Sphere3_E1.clone();
	surfacePtr Sphere4_E1_ptr = Sphere4_E1.clone();
	surfacePtr Sphere5_E1_ptr = Sphere5_E1.clone();
	surfacePtr Sphere6_E1_ptr = Sphere6_E1.clone();
	surfacePtr Plan7_E1_ptr = Plan7_E1.clone();

	std::vector<surfacePtr> opticalSystemE1_ptr{ Aper0_E1_ptr, Sphere1_E1_ptr, Sphere2_E1_ptr , Sphere3_E1_ptr, Sphere4_E1_ptr, Sphere5_E1_ptr, Sphere6_E1_ptr, Plan7_E1_ptr };
	std::vector<interaction_ptr> interactionsE1_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(),  refrac.clone(),  refrac.clone(), absorb.clone() };


	//	build optical system
	OpticalSystemElement optSystemElement_E1(opticalSystemE1_ptr, interactionsE1_ptr);

	// def steps variables
	stepsWithoutMinWithoutMax addInfosVarS2_Radius(2, 10, -10, 10);
	stepsWithoutMinWithoutMax addInfosVarS2_Pos(2, 5, -5, 5); //was eingeben, wenn nichts ausgeblendet wird
	std::vector<stepsWithoutMinWithoutMax> addInfosVariable{ addInfosVarS2_Radius,addInfosVarS2_Pos };

	StartRayPos startRayPos = notInfinity;

	// calc the combination vectors
	EvaluateManyOptSystems_ParaxialDistances calcCombVec_E1(/*optical System Element*/ optSystemElement_E1, /* add infos*/ addInfosVariable, /*start point ray*/startRayPos, /*prim wavelenght*/ primWavelength);

	OpticalSystem_LLT bestOptSys = calcCombVec_E1.getBestOptSys();
	SequentialRayTracing seqTraceE1(bestOptSys);
	bestOptSys.printAllPositions();
	bestOptSys.printAllRadii();
	Light_LLT light(550.0, 1, { 0.0,0.0,0.0,0.0 }, typeLightRay, 1);

	real SF6refIndex = glasses.getSF6_S1().calcRefractiveIndexSnellmeier1(550.0);

	// check by single ray tracing
	Ray_LLT rayTestE1(/*origin*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0, 1.0, 5.0 },/*refractive index*/ 1.0);
	LightRayStruct lightRaySingleE1(light, rayTestE1, 1);
	SequentialRayTracing singleRayTrace(bestOptSys);
	singleRayTrace.sequentialRayTracing(lightRaySingleE1);
	VectorStructR3 singleRayTraceZemax{ 0.0,-0.18611, 55.0 };
	bool checkSingleRay = Math::compareTwoVectorStructR3_decimals(singleRayTraceZemax, singleRayTrace.getAllIntersectionPointsSRT()[7], 0.01);
	workCalcComVec_E1.push_back(checkSingleRay);

	FillApertureStop fillAperE1(/*start point rays*/{ 0.0,0.0,0.0 },/*semi height of aperture stop*/ 1.0,/*point of aperture stop*/{ 0.0,0.0,5.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/6,/*arms*/ 8,/*refractive index*/ 1.0,/*wavelength*/ light);
	seqTraceE1.seqRayTracingWithVectorOfLightRays(fillAperE1.getVectorWithLightRays());

	Spot spotE1(seqTraceE1.getAllInterPointsAtSurf_i(7), seqTraceE1.getAllInterPointsAtSurf_i(7).at(0));
	real rmsSpotE1 = spotE1.getRMS_µm();
	real excelBest_Zemax_RMS = 109.061;
	bool checkE1_rmsBest = Math::compareTwoNumbers_decimals(excelBest_Zemax_RMS, rmsSpotE1, 2);
	workCalcComVec_E1.push_back(checkE1_rmsBest);


	bool returnCheckerE1 = Math::checkTrueOfVectorElements(workCalcComVec_E1);




	return returnCheckerE1;
}

bool testCalcComVec_Paraxial::testCalcComVec_E2()
{
	std::vector<bool> workCalcComVec_E2;

	std::vector<bool> workBuildSysForCom_E2;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;


	// set the wavelength
	real primWavelength = 550.0;
	Light_LLT Light_E2;
	Light_E2.setWavelength(550.0);
	Light_E2.setIntensity(1.0);
	std::vector<Light_LLT> lichtVecE2{ Light_E2 };


	// surfaces E2
	ApertureStopElement AperStop0_E2(/* semi height*/1.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAirZemax());
	SphericalElement Sphere1_E2(/*radius*/ 10.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,6.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBK7_S1());
	SphericalElement Sphere2_E2(/*radius*/ 10.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,11.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBK7_S1());
	SphericalElement Sphere3_E2(/*radius*/ 10.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,13.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF13_S1());
	SphericalElement Sphere4_E2(/*radius*/ 8.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,18.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF13_S1());
	PlanElement Plan5_E2(/*semi height*/ 5.00, /*point*/{ 0.0,0.0,33.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAirZemax(), /*refractive index B*/ glasses.getAirZemax());

	Sphere3_E2.setParameterRadius(-50.0, 50.0, 0.0, typeModifierVariable);
	Sphere4_E2.setParameterRadius(-25.0, 25.0, 0.0, typeModifierVariable);


	surfacePtr Aper0_E2_ptr = AperStop0_E2.clone();
	surfacePtr Sphere1_E2_ptr = Sphere1_E2.clone();
	surfacePtr Sphere2_E2_ptr = Sphere2_E2.clone();
	surfacePtr Sphere3_E2_ptr = Sphere3_E2.clone();
	surfacePtr Sphere4_E2_ptr = Sphere4_E2.clone();
	surfacePtr Plan5_E2_ptr = Plan5_E2.clone();

	std::vector<surfacePtr> opticalSystemE2_ptr{ Aper0_E2_ptr, Sphere1_E2_ptr, Sphere2_E2_ptr , Sphere3_E2_ptr, Sphere4_E2_ptr, Plan5_E2_ptr };
	std::vector<interaction_ptr> interactionsE2_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E2(opticalSystemE2_ptr, interactionsE2_ptr);

	// def steps variables
	stepsWithoutMinWithoutMax addInfosVarS1(1, 10, 0.0, 0.0);
	stepsWithoutMinWithoutMax addInfosVarS2(3, 10, 0.0, 0.0);
	std::vector<stepsWithoutMinWithoutMax> addInfosVariable{ addInfosVarS1,addInfosVarS2 };

	StartRayPos startRayPos = notInfinity;

	// calc the combination vectors
	EvaluateManyOptSystems_ParaxialDistances calcCombVec_E2(/*optical System Element*/ optSystemElement_E2, /* add infos*/ addInfosVariable, /*start point ray*/startRayPos, /*prim wavelenght*/ primWavelength);

	OpticalSystem_LLT bestOptSys = calcCombVec_E2.getBestOptSys();
	SequentialRayTracing seqTraceE2(bestOptSys);
	Light_LLT light(550.0, 1, { 0.0,0.0,0.0,0.0 }, typeLightRay, 1);

	FillApertureStop fillAperE2(/*start point rays*/{ 0.0,0.0,0.0 },/*semi height of aperture stop*/ 1.0,/*point of aperture stop*/{ 0.0,0.0,5.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/6,/*arms*/ 8,/*refractive index*/ 1.0,/*wavelength*/ light);
	seqTraceE2.seqRayTracingWithVectorOfLightRays(fillAperE2.getVectorWithLightRays());

	Spot spotE2(seqTraceE2.getAllInterPointsAtSurf_i(5), seqTraceE2.getAllInterPointsAtSurf_i(5).at(0));
	real rmsSpotE2 = spotE2.getRMS_µm();
	real excelBest_Zemax_RMS = 534.690;
	bool checkE2_rmsBest = Math::compareTwoNumbers_decimals(excelBest_Zemax_RMS, rmsSpotE2, 2);
	workCalcComVec_E2.push_back(checkE2_rmsBest);


	bool returnCheckerE2 = Math::checkTrueOfVectorElements(workCalcComVec_E2);




	return returnCheckerE2;
}

bool testCalcComVec_Paraxial::testCalcComVec_E3()
{
	std::vector<bool> workCalcComVec_E3;

	std::vector<bool> workBuildSysForCom_E3;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;


	// set the wavelength
	real primWavelength = 550.0;
	Light_LLT Light_E3;
	Light_E3.setWavelength(550.0);
	Light_E3.setIntensity(1.0);
	std::vector<Light_LLT> lichtVecE3{ Light_E3 };


	// surfaces E3
	ApertureStopElement AperStop0_E3(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAirZemax());
	SphericalElement Sphere1_E3(/*radius*/ 15.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,11.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere2_E3(/*radius*/ 20.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,16.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF13_S1(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere3_E3(/*radius*/ 50.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,21.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF13_S1(), /*refractive index B*/glasses.getAirZemax());
	SphericalElement Sphere4_E3(/*radius*/ 25.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,29.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF13_S1());
	SphericalElement Sphere5_E3(/*radius*/ 30.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,34.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF13_S1());
	PlanElement Plan6_E3(/*semi height*/ 5.0, /*point*/{ 0.0,0.0,64.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAirZemax(), /*refractive index B*/ glasses.getAirZemax());

	Sphere3_E3.setParameterPointZ(29.0, 51.0, 0.0, typeModifierVariable);
	Sphere4_E3.setParameterPointZ(59.0, 109.0, 0.0, typeModifierVariable);


	surfacePtr Aper0_E3_ptr = AperStop0_E3.clone();
	surfacePtr Sphere1_E3_ptr = Sphere1_E3.clone();
	surfacePtr Sphere2_E3_ptr = Sphere2_E3.clone();
	surfacePtr Sphere3_E3_ptr = Sphere3_E3.clone();
	surfacePtr Sphere4_E3_ptr = Sphere4_E3.clone();
	surfacePtr Sphere5_E3_ptr = Sphere5_E3.clone();
	surfacePtr Plan6_E3_ptr = Plan6_E3.clone();

	std::vector<surfacePtr> opticalSystemE3_ptr{ Aper0_E3_ptr, Sphere1_E3_ptr, Sphere2_E3_ptr , Sphere3_E3_ptr, Sphere4_E3_ptr, Sphere5_E3_ptr, Plan6_E3_ptr };
	std::vector<interaction_ptr> interactionsE3_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(),  refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E3(opticalSystemE3_ptr, interactionsE3_ptr);

	// def steps variables
	stepsWithoutMinWithoutMax addInfosVarS1(3, 10, 0.0, 0.0);
	stepsWithoutMinWithoutMax addInfosVarS2(4, 10, 0.0, 0.0);
	std::vector<stepsWithoutMinWithoutMax> addInfosVariable{ addInfosVarS1,addInfosVarS2 };

	StartRayPos startRayPos = notInfinity;

	// calc the combination vectors
	EvaluateManyOptSystems_ParaxialDistances calcCombVec_E3(/*optical System Element*/ optSystemElement_E3, /* add infos*/ addInfosVariable, /*start point ray*/startRayPos, /*prim wavelenght*/ primWavelength);

	OpticalSystem_LLT bestOptSys = calcCombVec_E3.getBestOptSys();
	bestOptSys.printAllPositions();
	SequentialRayTracing seqTraceE3(bestOptSys);
	Light_LLT light(550.0, 1, { 0.0,0.0,0.0,0.0 }, typeLightRay, 1);

	FillApertureStop fillAperE3(/*start point rays*/{ 0.0,0.0,0.0 },/*semi height of aperture stop*/ 1.0,/*point of aperture stop*/{ 0.0,0.0,10.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/6,/*arms*/ 8,/*refractive index*/ 1.0,/*wavelength*/ light);
	seqTraceE3.seqRayTracingWithVectorOfLightRays(fillAperE3.getVectorWithLightRays());

	Spot spotE3(seqTraceE3.getAllInterPointsAtSurf_i(6), seqTraceE3.getAllInterPointsAtSurf_i(6).at(0));
	real rmsSpotE3 = spotE3.getRMS_µm();
	real excelBest_Zemax_RMS = 91.162;
	bool checkE3_rmsBest = Math::compareTwoNumbers_decimals(excelBest_Zemax_RMS, rmsSpotE3, 2);
	workCalcComVec_E3.push_back(checkE3_rmsBest);


	bool returnCheckerE3 = Math::checkTrueOfVectorElements(workCalcComVec_E3);




	return returnCheckerE3;
}