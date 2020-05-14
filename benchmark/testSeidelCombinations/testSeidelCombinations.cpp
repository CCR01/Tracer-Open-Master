#include "testSeidelCombinations.h"

#include "..\..\OptimizeSystem\BuildSystemsForCombination.h"
#include "..\..\OptimizeSystem\EvaluateManyOptSystems_ParaxialDistances.h"
#include "..\..\OptimizeSystem\EvaluateManyOptSystems_SeidelCoef.h"

// surfaces
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\PlanElement.h"
#include "..\..\SurfaceElements\ApertureStopElement.h"

// interactions
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"

#include "..\..\Glasses\Glasses.h"

testSeidelCombinations::testSeidelCombinations() {};
testSeidelCombinations::~testSeidelCombinations() {};

bool testSeidelCombinations::testSeidelCom_superFct()
{
	std::vector<bool> checkSteidelCom_superFct;
	bool checkSeidelCom_E0 = testSeidelCom_E0();


	bool checkerSeidelCom = Math::checkTrueOfVectorElements(checkSteidelCom_superFct);
	return checkerSeidelCom;

}

bool testSeidelCombinations::testSeidelCom_E0()
{
	std::vector<bool> checkSteidelCom_E0;
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
//	// set the wavelength
//	real primWavelength = 550.0;
//	Light_LLT Light_E0;
//	Light_E0.setWavelength(550.0);
//	Light_E0.setIntensity(1.0);
//	std::vector<Light_LLT> lichtVecE0{ Light_E0 };
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
//	Sphere1_E0.setParameterRadius(-30.0, 30.0, 0.0, typeModifierVariable); // TODO: increase that number range later
//	Sphere3_E0.setParameterRadius(-30.0, 30.0, 0.0, typeModifierVariable); // TODO: increase that number range later
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
//	stepsWithoutMinWithoutMax addInfosVarS1(1, 10, 0.0, 0.0);
//	stepsWithoutMinWithoutMax addInfosVarS2(3, 10, 0.0, 0.0);
//	std::vector<stepsWithoutMinWithoutMax> addInfosVariable{ addInfosVarS1,addInfosVarS2 };
//
//	StartRayPos startRayPos = notInfinity;
//	std::vector<VectorStructR3> fields = { {0.0,0.0,0.0}, {0.0,1.0,0.0} };
//	std::vector<real> wavelengths = { 550.0,400.0,600.0 };
//
//	// calc the combination vectors
//	EvaluateManyOptSystems_SeidelCoef calcCombVec_E0(/*optical System Element*/ optSystemElement_E0, /* add infos*/ addInfosVariable, /*field points*/fields, /*wavelenghts*/ wavelengths);
//
	bool checkerSeidelCom_E0 = Math::checkTrueOfVectorElements(checkSteidelCom_E0);
	return checkerSeidelCom_E0;

}