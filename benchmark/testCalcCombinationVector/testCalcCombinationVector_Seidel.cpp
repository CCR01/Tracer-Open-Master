#include "testCalcCombinationVector_Seidel.h"

#include "..\..\OptimizeSystem\EvaluateManyOptSystems_SeidelCoef.h"

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

testCalcCombiVector_Seidel::testCalcCombiVector_Seidel() {}

testCalcCombiVector_Seidel::~testCalcCombiVector_Seidel() {}

bool testCalcCombiVector_Seidel::testCalcCombiVec_Seidel_superFct()
{
	std::vector<bool> workCalcComVec_superFct;
	
	bool workE0 = testCalcCombiVec_Seidel_E0();
	workCalcComVec_superFct.push_back(workE0);

	bool returnCheckerSuperFct = Math::checkTrueOfVectorElements(workCalcComVec_superFct);
	return returnCheckerSuperFct;

}
bool testCalcCombiVector_Seidel::testCalcCombiVec_Seidel_E0()
{
	std::vector<bool> workCalcComVec_E0;
//
//	glass glasses;
//	glasses.loadGlassCatalog_Schott();
//
//	typedef std::shared_ptr< Element_CR > surfacePtr;
//	typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;
//
//	RefractedRay_LLT refrac;
//	Absorb_LLT absorb;
//	DoNothingInteraction_LLT doNothing;
//
//	// surfaces E0
//	ApertureStopElement AperStop0_E0(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
//	SphericalElement Sphere1_E0(/*radius*/ 10.0, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
//	SphericalElement Sphere2_E0(/*radius*/ 20.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
//	SphericalElement Sphere3_E0(/*radius*/ 70.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF13_S1(), /*refractive index B*/glasses.getAir());
//	SphericalElement Sphere4_E0(/*radius*/ 50.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF13_S1());
//	PlanElement Plan5_E0(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,55.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
//
//	Sphere1_E0.setParameterRadius(-30, 30.0, 0.0, typeModifierVariable);
//	Sphere3_E0.setParameterRadius(-30.0, 30.0, 0.0, typeModifierVariable);
//
//	surfacePtr Aper0_E0_ptr = AperStop0_E0.clone();
//	surfacePtr Sphere1_E0_ptr = Sphere1_E0.clone();
//	surfacePtr Sphere2_E0_ptr = Sphere2_E0.clone();
//	surfacePtr Sphere3_E0_ptr = Sphere3_E0.clone();
//	surfacePtr Sphere4_E0_ptr = Sphere4_E0.clone();
//	surfacePtr Plan5_E0_ptr = Plan5_E0.clone();
//
//	std::vector<surfacePtr> opticalSystemE0_ptr{ Aper0_E0_ptr, Sphere1_E0_ptr, Sphere2_E0_ptr , Sphere3_E0_ptr, Sphere4_E0_ptr, Plan5_E0_ptr };
//	std::vector<interaction_ptr> interactionsE0_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };
//
//
//	//	build optical system
//	OpticalSystemElement optSystemElement_E0(opticalSystemE0_ptr, interactionsE0_ptr);
//
//	// def steps variables
//	stepsWithoutMinWithoutMax addInfosVarS1(1, 10, -10.0, 10.0);
//	stepsWithoutMinWithoutMax addInfosVarS2(3, 10, -20.0, 20.0);
//	std::vector<stepsWithoutMinWithoutMax> addInfosVariable{ addInfosVarS1,addInfosVarS2 };
//
//	//StartRayPos startRayPos = notInfinity;
//
//	// fields
//	std::vector<VectorStructR3> fields;
//	fields.resize(3);
//	fields[0] = { 0.0,0.0,0.0 };
//	fields[1] = { 0.0,2.0,0.0 };
//	fields[2] = { 0.0,1.0,0.0 };
//
//	// wavelengths
//	std::vector<real> wavelengths;
//	wavelengths.resize(3);
//	wavelengths[0] = 550.0;
//	wavelengths[1] = 400.0;
//	wavelengths[2] = 700.0;
//
//	// calc the combination vectors
//	EvaluateManyOptSystems_SeidelCoef calcCombVec_E0(/*optical System Element*/ optSystemElement_E0, /* add infos*/ addInfosVariable, /*fields*/fields, /*wavelenghts*/ wavelengths);
//	
//	OpticalSystem_LLT bestOptSys_E0 = calcCombVec_E0.getBestOptSys().getLLTconversion_doConversion();
//	SequentialRayTracing seqTraceE0(bestOptSys_E0);
//	Light_LLT light(550.0, 1, { 0.0,0.0,0.0,0.0 }, typeLightRay, 1);
//
//	bestOptSys_E0.printAllOptSysParameter_LLT(bestOptSys_E0);
//
//	FillApertureStop fillAperE0(/*start point rays*/{ 0.0,0.0,0.0 },/*semi height of aperture stop*/ 1.0,/*point of aperture stop*/{ 0.0,0.0,20.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/6,/*arms*/ 8,/*refractive index*/ 1.0,/*wavelength*/ light);
//	seqTraceE0.seqRayTracingWithVectorOfLightRays(fillAperE0.getVectorWithLightRays());
//
//	Spot spotE0(seqTraceE0.getAllInterPointsAtSurf_i_notFiltered(5), seqTraceE0.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
//	real rmsSpotE0 = spotE0.getRMS_µm();
//	real excelBest_Zemax_RMS = 462.719;
//	bool checkE0_rmsBest = Math::compareTwoNumbers_decimals(excelBest_Zemax_RMS, rmsSpotE0, 2);
//	workCalcComVec_E0.push_back(checkE0_rmsBest);
//
//
	bool returnCheckerE0 = Math::checkTrueOfVectorElements(workCalcComVec_E0);
	return returnCheckerE0;
}

