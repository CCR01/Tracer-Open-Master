#include "testCalculateParaxialDistances.h"

#include "..\..\OpticalSystemElement\OpticalSystemElement.h"

// surfaces
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\PlanElement.h"
#include "..\..\SurfaceElements\ApertureStopElement.h"


// interactions
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"

// glasses
#include "..\..\Glasses\Glasses.h"

#include "..\..\OptimizeSystem\calculateParaxialDistances.h"

testCalcPraxialDistances::testCalcPraxialDistances() {}

testCalcPraxialDistances::~testCalcPraxialDistances() {}


bool testCalcPraxialDistances::checkCalcParaxialDistances()
{
	std::vector<bool> workCalcPraxialDistances;
//
//	glass glasses;
//	glasses.loadGlassCatalog_Schott();
//
//	typedef std::shared_ptr< Element_CR > surfacePtr;
//	typedef std::shared_ptr<InteractionRay_LLT> interaction_ptr;
//
//	RefractedRay_LLT refrac;
//	Absorb_LLT absorb;
//	DoNothingInteraction_LLT doNothing;
//
//	// set the wavelength
//	real primWavelength = 550.0;
//
//
//	// surfaces E0
//	ApertureStopElement AperStop0_E0(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
//	SphericalElement Sphere1_E0(/*radius*/ 10.0, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
//	SphericalElement Sphere2_E0(/*radius*/ 20.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
//	SphericalElement Sphere3_E0(/*radius*/ 70.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF13_S1(), /*refractive index B*/glasses.getAir());
//	SphericalElement Sphere4_E0(/*radius*/ 50.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF13_S1());
//	PlanElement Plan5_E0(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,55.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
//
//	surfacePtr Aper0_E0_ptr = AperStop0_E0.clone();
//	surfacePtr Sphere1_E0_ptr = Sphere1_E0.clone();
//	surfacePtr Sphere2_E0_ptr = Sphere2_E0.clone();
//	surfacePtr Sphere3_E0_ptr = Sphere3_E0.clone();
//	surfacePtr Sphere4_E0_ptr = Sphere4_E0.clone();
//	surfacePtr Plan5_E0_ptr = Plan5_E0.clone();
//
//	std::vector<surfacePtr> opticalSystemE0_ptr{ Aper0_E0_ptr, Sphere1_E0_ptr, Sphere2_E0_ptr , Sphere3_E0_ptr, Sphere4_E0_ptr, Plan5_E0_ptr };
//	std::vector<interaction_ptr> interactionsE0_ptr{ doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };
//
//
//	//	build optical system
//	OpticalSystemElement optSystemElement_E0(opticalSystemE0_ptr, interactionsE0_ptr);
//
//	StartRayPos startRayPos = notInfinity;
//	CalculateParaxialDistances calcParaDis_E0(optSystemElement_E0, startRayPos, primWavelength);
//
//	// test E0
//
//
//	// check all s
//	bool checkS1 = Math::compareTwoNumbers_decimals(calcParaDis_E0.getS_atSurface_i(1), -25.0, 2);
//	workCalcPraxialDistances.push_back(checkS1);
//	bool checkS2 = Math::compareTwoNumbers_decimals(calcParaDis_E0.getS_atSurface_i(2), 123.12, 2);
//	workCalcPraxialDistances.push_back(checkS2);
//	bool checkS3 = Math::compareTwoNumbers_decimals(calcParaDis_E0.getS_atSurface_i(3), 16.14, 2);
//	workCalcPraxialDistances.push_back(checkS3);
//	bool checkS4 = Math::compareTwoNumbers_decimals(calcParaDis_E0.getS_atSurface_i(4), 29.04, 2);
//	workCalcPraxialDistances.push_back(checkS4);
//
//
//	// check all s_dash
//	bool checkS1_dash = Math::compareTwoNumbers_decimals(calcParaDis_E0.getS_dash_atSurface_i(1), 128.12, 2);
//	workCalcPraxialDistances.push_back(checkS1_dash);
//	bool checkS2_dash = Math::compareTwoNumbers_decimals(calcParaDis_E0.getS_dash_atSurface_i(2), 26.14, 2);
//	workCalcPraxialDistances.push_back(checkS2_dash);
//	bool checkS3_dash = Math::compareTwoNumbers_decimals(calcParaDis_E0.getS_dash_atSurface_i(3), 34.04, 2);
//	workCalcPraxialDistances.push_back(checkS3_dash);
//	bool checkS4_dash = Math::compareTwoNumbers_decimals(calcParaDis_E0.getS_dash_atSurface_i(4), 13.32, 2);
//	workCalcPraxialDistances.push_back(checkS4_dash);
//
//	//check all focallengths
//	bool check_focal1_E0 = Math::compareTwoNumbers_decimals(calcParaDis_E0.getFocallength_atSurface_i(1), 29.2856, 2);
//	workCalcPraxialDistances.push_back(check_focal1_E0);
//	bool check_focal2_E0 = Math::compareTwoNumbers_decimals(calcParaDis_E0.getFocallength_atSurface_i(2), 38.5711, 2);
//	workCalcPraxialDistances.push_back(check_focal2_E0);
//	bool check_focal3_E0 = Math::compareTwoNumbers_decimals(calcParaDis_E0.getFocallength_atSurface_i(3), -163.7795, 2);
//	workCalcPraxialDistances.push_back(check_focal3_E0);
//	bool check_focal4_E0 = Math::compareTwoNumbers_decimals(calcParaDis_E0.getFocallength_atSurface_i(4), 66.9853, 2);
//	workCalcPraxialDistances.push_back(check_focal4_E0);
//
//
//
//	// surfaces E1_best is the excel optimized system E0
//	ApertureStopElement AperStop0_E1_best(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
//	SphericalElement Sphere1_E1_best(/*radius*/ 70.0, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
//	SphericalElement Sphere2_E1_best(/*radius*/ 20.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
//	SphericalElement Sphere3_E1_best(/*radius*/ 10.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF13_S1());
//	SphericalElement Sphere4_E1_best(/*radius*/ 50.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF13_S1());
//	PlanElement Plan5_E1_best(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,55.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
//
//	surfacePtr Aper0_E1_best_ptr = AperStop0_E1_best.clone();
//	surfacePtr Sphere1_E1_best_ptr = Sphere1_E1_best.clone();
//	surfacePtr Sphere2_E1_best_ptr = Sphere2_E1_best.clone();
//	surfacePtr Sphere3_E1_best_ptr = Sphere3_E1_best.clone();
//	surfacePtr Sphere4_E1_best_ptr = Sphere4_E1_best.clone();
//	surfacePtr Plan5_E1_best_ptr = Plan5_E1_best.clone();
//
//	std::vector<surfacePtr> opticalSystemE1_best_ptr{ Aper0_E1_best_ptr, Sphere1_E1_best_ptr, Sphere2_E1_best_ptr , Sphere3_E1_best_ptr, Sphere4_E1_best_ptr, Plan5_E1_best_ptr };
//	std::vector<interaction_ptr> interactionsE1_best_ptr{ doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };
//
//
//	//	build optical system
//	OpticalSystemElement optSystemElement_E1_best(opticalSystemE1_best_ptr, interactionsE1_best_ptr);
//	CalculateParaxialDistances calcParaDis_E1_best(optSystemElement_E1_best, startRayPos, primWavelength);
//
//
//	// check all s
//	bool checkS1_E1_best = Math::compareTwoNumbers_decimals(calcParaDis_E1_best.getS_atSurface_i(1), -25.00, 2);
//	workCalcPraxialDistances.push_back(checkS1_E1_best);
//	bool checkS2_E1_best = Math::compareTwoNumbers_decimals(calcParaDis_E1_best.getS_atSurface_i(2), -51.59, 2);
//	workCalcPraxialDistances.push_back(checkS2_E1_best);
//	bool checkS3_E1_best = Math::compareTwoNumbers_decimals(calcParaDis_E1_best.getS_atSurface_i(3), -295.09, 2);
//	workCalcPraxialDistances.push_back(checkS3_E1_best);
//	bool checkS4_E1_best = Math::compareTwoNumbers_decimals(calcParaDis_E1_best.getS_atSurface_i(4), 19.51, 2);
//	workCalcPraxialDistances.push_back(checkS4_E1_best);
//
//
//	// check all s_dash
//	bool checkS1_dash_E1_best = Math::compareTwoNumbers_decimals(calcParaDis_E1_best.getS_dash_atSurface_i(1), -46.59, 2);
//	workCalcPraxialDistances.push_back(checkS1_dash_E1_best);
//	bool checkS2_dash_E1_best = Math::compareTwoNumbers_decimals(calcParaDis_E1_best.getS_dash_atSurface_i(2), -285.0886, 2);
//	workCalcPraxialDistances.push_back(checkS2_dash_E1_best);
//	bool checkS3_dash_E1_best = Math::compareTwoNumbers_decimals(calcParaDis_E1_best.getS_dash_atSurface_i(3), 24.5098, 2);
//	workCalcPraxialDistances.push_back(checkS3_dash_E1_best);
//	bool checkS4_dash_E1_best = Math::compareTwoNumbers_decimals(calcParaDis_E1_best.getS_dash_atSurface_i(4), 9.5745, 2);
//	workCalcPraxialDistances.push_back(checkS4_dash_E1_best);
//
//	//check all focallengths
//	bool check_focal1_E1_best = Math::compareTwoNumbers_decimals(calcParaDis_E1_best.getFocallength_atSurface_i(1), 204.999, 2);
//	workCalcPraxialDistances.push_back(check_focal1_E1_best);
//	bool check_focal2_E1_best = Math::compareTwoNumbers_decimals(calcParaDis_E1_best.getFocallength_atSurface_i(2), 38.5711, 2);
//	workCalcPraxialDistances.push_back(check_focal2_E1_best);
//	bool check_focal3_E1_best = Math::compareTwoNumbers_decimals(calcParaDis_E1_best.getFocallength_atSurface_i(3), 23.3971, 2);
//	workCalcPraxialDistances.push_back(check_focal3_E1_best);
//	bool check_focal4_E1_best = Math::compareTwoNumbers_decimals(calcParaDis_E1_best.getFocallength_atSurface_i(4), 66.9853, 2);
//	workCalcPraxialDistances.push_back(check_focal4_E1_best);
//
//	//real SF6_refIndex = glasses.getSF13_S1().calcRefractiveIndexSnellmeier1(550.0);
//
//	// surfaces E1
//	ApertureStopElement AperStop0_E1(/* semi height*/1.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
//	SphericalElement Sphere1_E1(/*radius*/ 10.0, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
//	SphericalElement Sphere2_E1(/*radius*/ 70.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF6_S1(), /*refractive index B*/glasses.getBK7_S1());
//	SphericalElement Sphere3_E1(/*radius*/ 50.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
//	SphericalElement Sphere4_E1(/*radius*/ 15.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF13_S1());
//	SphericalElement Sphere5_E1(/*radius*/ 20.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF13_S1(), /*refractive index B*/glasses.getBK7_S1());
//	SphericalElement Sphere6_E1(/*radius*/ 30.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
//	PlanElement Plan7_E1(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,50.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
//
//
//	surfacePtr Aper0_E1_ptr = AperStop0_E1.clone();
//	surfacePtr Sphere1_E1_ptr = Sphere1_E1.clone();
//	surfacePtr Sphere2_E1_ptr = Sphere2_E1.clone();
//	surfacePtr Sphere3_E1_ptr = Sphere3_E1.clone();
//	surfacePtr Sphere4_E1_ptr = Sphere4_E1.clone();
//	surfacePtr Sphere5_E1_ptr = Sphere5_E1.clone();
//	surfacePtr Sphere6_E1_ptr = Sphere6_E1.clone();
//	surfacePtr Plan7_E1_ptr = Plan7_E1.clone();
//
//	std::vector<surfacePtr> opticalSystemE1_ptr{ Aper0_E1_ptr, Sphere1_E1_ptr, Sphere2_E1_ptr , Sphere3_E1_ptr, Sphere4_E1_ptr, Sphere5_E1_ptr, Sphere6_E1_ptr, Plan7_E1_ptr };
//	std::vector<interaction_ptr> interactionsE1_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(),  refrac.clone(),  refrac.clone(), absorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement_E1(opticalSystemE1_ptr, interactionsE1_ptr);
//	CalculateParaxialDistances calcParaDis_E1(optSystemElement_E1, startRayPos, primWavelength);
//
//
//	// check all s
//	bool checkS1_E1 = Math::compareTwoNumbers_decimals(calcParaDis_E1.getS_atSurface_i(1), -10.00, 2);
//	workCalcPraxialDistances.push_back(checkS1_E1);
//	bool checkS2_E1 = Math::compareTwoNumbers_decimals(calcParaDis_E1.getS_atSurface_i(2), -36.54, 2);
//	workCalcPraxialDistances.push_back(checkS2_E1);
//	bool checkS3_E1 = Math::compareTwoNumbers_decimals(calcParaDis_E1.getS_atSurface_i(3), -44.60, 2);
//	workCalcPraxialDistances.push_back(checkS3_E1);
//	bool checkS4_E1 = Math::compareTwoNumbers_decimals(calcParaDis_E1.getS_atSurface_i(4), -46.01, 2);
//	workCalcPraxialDistances.push_back(checkS4_E1);
//	bool checkS5_E1 = Math::compareTwoNumbers_decimals(calcParaDis_E1.getS_atSurface_i(5), 57.31, 2);
//	workCalcPraxialDistances.push_back(checkS5_E1);
//	bool checkS6_E1 = Math::compareTwoNumbers_decimals(calcParaDis_E1.getS_atSurface_i(6), 74.60, 2);
//	workCalcPraxialDistances.push_back(checkS6_E1);
//
//	// check all s_dash
//	bool checkS1_dash_E1 = Math::compareTwoNumbers_decimals(calcParaDis_E1.getS_dash_atSurface_i(1), -31.54, 2);
//	workCalcPraxialDistances.push_back(checkS1_dash_E1);
//	bool checkS2_dash_E1 = Math::compareTwoNumbers_decimals(calcParaDis_E1.getS_dash_atSurface_i(2), -39.60, 2);
//	workCalcPraxialDistances.push_back(checkS2_dash_E1);
//	bool checkS3_dash_E1 = Math::compareTwoNumbers_decimals(calcParaDis_E1.getS_dash_atSurface_i(3), -41.01, 2);
//	workCalcPraxialDistances.push_back(checkS3_dash_E1);
//	bool checkS4_dash_E1 = Math::compareTwoNumbers_decimals(calcParaDis_E1.getS_dash_atSurface_i(4), 62.31, 2);
//	workCalcPraxialDistances.push_back(checkS4_dash_E1);
//	bool checkS5_dash_E1 = Math::compareTwoNumbers_decimals(calcParaDis_E1.getS_dash_atSurface_i(5), 79.60, 2);
//	workCalcPraxialDistances.push_back(checkS5_dash_E1);
//	bool checkS6_dash_E1 = Math::compareTwoNumbers_decimals(calcParaDis_E1.getS_dash_atSurface_i(6), 26.57, 2);
//	workCalcPraxialDistances.push_back(checkS6_dash_E1);
//
//	//check all focallengths
//	bool check_focal1_E1 = Math::compareTwoNumbers_decimals(calcParaDis_E1.getFocallength_atSurface_i(1), 29.29, 2);
//	workCalcPraxialDistances.push_back(check_focal1_E1);
//	bool check_focal2_E1 = Math::compareTwoNumbers_decimals(calcParaDis_E1.getFocallength_atSurface_i(2), -432.37, 2);
//	workCalcPraxialDistances.push_back(check_focal2_E1);
//	bool check_focal3_E1 = Math::compareTwoNumbers_decimals(calcParaDis_E1.getFocallength_atSurface_i(3), 61.59, 2);
//	workCalcPraxialDistances.push_back(check_focal3_E1);
//	bool check_focal4_E1 = Math::compareTwoNumbers_decimals(calcParaDis_E1.getFocallength_atSurface_i(4), 35.10, 2);
//	workCalcPraxialDistances.push_back(check_focal4_E1);
//	bool check_focal5_E1 = Math::compareTwoNumbers_decimals(calcParaDis_E1.getFocallength_atSurface_i(5), -133.26, 2);
//	workCalcPraxialDistances.push_back(check_focal5_E1);
//	bool check_focal6_E1 = Math::compareTwoNumbers_decimals(calcParaDis_E1.getFocallength_atSurface_i(6), 57.86, 2);
//	workCalcPraxialDistances.push_back(check_focal6_E1);
//
//
//	// surfaces E2
//	ApertureStopElement AperStop0_E2(/* semi height*/1.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
//	SphericalElement Sphere1_E2(/*radius*/ 10.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,6.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
//	SphericalElement Sphere2_E2(/*radius*/ 10.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,11.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
//	SphericalElement Sphere3_E2(/*radius*/ 10.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,13.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF13_S1());
//	SphericalElement Sphere4_E2(/*radius*/ 8.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,18.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF13_S1());
//	PlanElement Plan5_E2(/*semi height*/ 5.00, /*point*/{ 0.0,0.0,33.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
//
//	Sphere3_E2.setParameterRadius(-50.0, 50.0, 0.0, typeModifierVariable);
//	Sphere4_E2.setParameterRadius(-25.0, 25.0, 0.0, typeModifierVariable);
//
//
//	surfacePtr Aper0_E2_ptr = AperStop0_E2.clone();
//	surfacePtr SpherE2_E2_ptr = Sphere1_E2.clone();
//	surfacePtr Sphere2_E2_ptr = Sphere2_E2.clone();
//	surfacePtr Sphere3_E2_ptr = Sphere3_E2.clone();
//	surfacePtr Sphere4_E2_ptr = Sphere4_E2.clone();
//	surfacePtr Plan5_E2_ptr = Plan5_E2.clone();
//
//	std::vector<surfacePtr> opticalSystemE2_ptr{ Aper0_E2_ptr, SpherE2_E2_ptr, Sphere2_E2_ptr , Sphere3_E2_ptr, Sphere4_E2_ptr, Plan5_E2_ptr };
//	std::vector<interaction_ptr> interactionsE2_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement_E2(opticalSystemE2_ptr, interactionsE2_ptr);
//	CalculateParaxialDistances calcParaDis_E2(optSystemElement_E2, startRayPos, primWavelength);
//
//
//	// check all s
//	bool checkS1_E2 = Math::compareTwoNumbers_decimals(calcParaDis_E2.getS_atSurface_i(1), -6.00, 2);
//	workCalcPraxialDistances.push_back(checkS1_E2);
//	bool checkS2_E2 = Math::compareTwoNumbers_decimals(calcParaDis_E2.getS_atSurface_i(2), -18.23, 2);
//	workCalcPraxialDistances.push_back(checkS2_E2);
//	bool checkS3_E2 = Math::compareTwoNumbers_decimals(calcParaDis_E2.getS_atSurface_i(3), -33.78, 2);
//	workCalcPraxialDistances.push_back(checkS3_E2);
//	bool checkS4_E2 = Math::compareTwoNumbers_decimals(calcParaDis_E2.getS_atSurface_i(4), 33.77, 2);
//	workCalcPraxialDistances.push_back(checkS4_E2);
//
//	// check all s_dash
//	bool checkS1_dash_E2 = Math::compareTwoNumbers_decimals(calcParaDis_E2.getS_dash_atSurface_i(1), -13.23, 2);
//	workCalcPraxialDistances.push_back(checkS1_dash_E2);
//	bool checkS2_dash_E2 = Math::compareTwoNumbers_decimals(calcParaDis_E2.getS_dash_atSurface_i(2), -31.78, 2);
//	workCalcPraxialDistances.push_back(checkS2_dash_E2);
//	bool checkS3_dash_E2 = Math::compareTwoNumbers_decimals(calcParaDis_E2.getS_dash_atSurface_i(3), 38.77, 2);
//	workCalcPraxialDistances.push_back(checkS3_dash_E2);
//	bool checkS4_dash_E2 = Math::compareTwoNumbers_decimals(calcParaDis_E2.getS_dash_atSurface_i(4), 6.90, 2);
//	workCalcPraxialDistances.push_back(checkS4_dash_E2);
//
//
//	//check all focallengths
//	bool check_focal1_E2 = Math::compareTwoNumbers_decimals(calcParaDis_E2.getFocallength_atSurface_i(1), 29.29, 2);
//	workCalcPraxialDistances.push_back(check_focal1_E2);
//	bool check_focal2_E2 = Math::compareTwoNumbers_decimals(calcParaDis_E2.getFocallength_atSurface_i(2), 19.29, 2);
//	workCalcPraxialDistances.push_back(check_focal2_E2);
//	bool check_focal3_E2 = Math::compareTwoNumbers_decimals(calcParaDis_E2.getFocallength_atSurface_i(3), 23.40, 2);
//	workCalcPraxialDistances.push_back(check_focal3_E2);
//	bool check_focal4_E2 = Math::compareTwoNumbers_decimals(calcParaDis_E2.getFocallength_atSurface_i(4), 10.72, 2);
//	workCalcPraxialDistances.push_back(check_focal4_E2);
//
//
//	// surfaces E3
//	ApertureStopElement AperStop0_E3(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
//	SphericalElement Sphere1_E3(/*radius*/ 15.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,11.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
//	SphericalElement Sphere2_E3(/*radius*/ 20.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,16.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF13_S1(), /*refractive index B*/glasses.getSF6_S1());
//	SphericalElement Sphere3_E3(/*radius*/ 50.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,21.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF13_S1(), /*refractive index B*/glasses.getAir());
//	SphericalElement Sphere4_E3(/*radius*/ 25.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,29.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF13_S1());
//	SphericalElement Sphere5_E3(/*radius*/ 30.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,34.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF13_S1());
//	PlanElement Plan6_E3(/*semi height*/ 5.0, /*point*/{ 0.0,0.0,64.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
//
//	Sphere3_E3.setParameterPointZ(29.0, 51.0, 0.0, typeModifierVariable);
//	Sphere4_E3.setParameterPointZ(59.0, 109.0, 0.0, typeModifierVariable);
//
//
//	surfacePtr Aper0_E3_ptr = AperStop0_E3.clone();
//	surfacePtr Sphere1_E3_ptr = Sphere1_E3.clone();
//	surfacePtr Sphere2_E3_ptr = Sphere2_E3.clone();
//	surfacePtr Sphere3_E3_ptr = Sphere3_E3.clone();
//	surfacePtr Sphere4_E3_ptr = Sphere4_E3.clone();
//	surfacePtr Sphere5_E3_ptr = Sphere5_E3.clone();
//	surfacePtr Plan6_E3_ptr = Plan6_E3.clone();
//
//	std::vector<surfacePtr> opticalSystemE3_ptr{ Aper0_E3_ptr, Sphere1_E3_ptr, Sphere2_E3_ptr , Sphere3_E3_ptr, Sphere4_E3_ptr, Sphere5_E3_ptr, Plan6_E3_ptr };
//	std::vector<interaction_ptr> interactionsE3_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(),  refrac.clone(), absorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement_E3(opticalSystemE3_ptr, interactionsE3_ptr);
//	CalculateParaxialDistances calcParaDis_E3(optSystemElement_E3, startRayPos, primWavelength);
//
//
//	// check all s
//	bool checkS1_E3 = Math::compareTwoNumbers_decimals(calcParaDis_E3.getS_atSurface_i(1), -11.0, 2);
//	workCalcPraxialDistances.push_back(checkS1_E3);
//	bool checkS2_E3 = Math::compareTwoNumbers_decimals(calcParaDis_E3.getS_atSurface_i(2), -54.26, 2);
//	workCalcPraxialDistances.push_back(checkS2_E3);
//	bool checkS3_E3 = Math::compareTwoNumbers_decimals(calcParaDis_E3.getS_atSurface_i(3), -62.98, 2);
//	workCalcPraxialDistances.push_back(checkS3_E3);
//	bool checkS4_E3 = Math::compareTwoNumbers_decimals(calcParaDis_E3.getS_atSurface_i(4), -31.44, 2);
//	workCalcPraxialDistances.push_back(checkS4_E3);
//	bool checkS5_E3 = Math::compareTwoNumbers_decimals(calcParaDis_E3.getS_atSurface_i(5), -901.26, 2);
//	workCalcPraxialDistances.push_back(checkS5_E3);
//
//	// check all s_dash
//	bool checkS1_dash_E3 = Math::compareTwoNumbers_decimals(calcParaDis_E3.getS_dash_atSurface_i(1), -49.26, 2);
//	workCalcPraxialDistances.push_back(checkS1_dash_E3);
//	bool checkS2_dash_E3 = Math::compareTwoNumbers_decimals(calcParaDis_E3.getS_dash_atSurface_i(2), -57.98, 2);
//	workCalcPraxialDistances.push_back(checkS2_dash_E3);
//	bool checkS3_dash_E3 = Math::compareTwoNumbers_decimals(calcParaDis_E3.getS_dash_atSurface_i(3), -23.44, 2);
//	workCalcPraxialDistances.push_back(checkS3_dash_E3);
//	bool checkS4_dash_E3 = Math::compareTwoNumbers_decimals(calcParaDis_E3.getS_dash_atSurface_i(4), -896.26, 2);
//	workCalcPraxialDistances.push_back(checkS4_dash_E3);
//	bool checkS5_dash_E3 = Math::compareTwoNumbers_decimals(calcParaDis_E3.getS_dash_atSurface_i(5), 43.59, 2);
//	workCalcPraxialDistances.push_back(checkS5_dash_E3);
//
//	//check all focallengths
//	bool check_focal1_E3 = Math::compareTwoNumbers_decimals(calcParaDis_E3.getFocallength_atSurface_i(1), 33.48, 2);
//	workCalcPraxialDistances.push_back(check_focal1_E3);
//	bool check_focal2_E3 = Math::compareTwoNumbers_decimals(calcParaDis_E3.getFocallength_atSurface_i(2), 533.86, 2);
//	workCalcPraxialDistances.push_back(check_focal2_E3);
//	bool check_focal3_E3 = Math::compareTwoNumbers_decimals(calcParaDis_E3.getFocallength_atSurface_i(3), -66.99, 2);
//	workCalcPraxialDistances.push_back(check_focal3_E3);
//	bool check_focal4_E3 = Math::compareTwoNumbers_decimals(calcParaDis_E3.getFocallength_atSurface_i(4), 58.49, 2);
//	workCalcPraxialDistances.push_back(check_focal4_E3);
//	bool check_focal5_E3 = Math::compareTwoNumbers_decimals(calcParaDis_E3.getFocallength_atSurface_i(5), 40.19, 2);
//	workCalcPraxialDistances.push_back(check_focal5_E3);
//
//
//
	bool returnBool = Math::checkTrueOfVectorElements(workCalcPraxialDistances);
	return returnBool;

}
