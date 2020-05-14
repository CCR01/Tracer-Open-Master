#include "testBuildSysForCombination.h"

#include "..\..\OptimizeSystem\BuildSystemsForCombination.h"

// surfaces
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\PlanElement.h"
#include "..\..\SurfaceElements\ApertureStopElement.h"


// interactions
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"

// glasses
#include "..\..\Glasses\Glasses.h"



testBuildSysForCombination::testBuildSysForCombination() {}
testBuildSysForCombination::~testBuildSysForCombination() {}


bool testBuildSysForCombination::checkBuiildSysForCom_SUPERFUNCTION()
{
	std::vector<bool> checkerBuildSysForVom_Global;

	bool checkE0 = checkBuildSysForCom_E0();
	checkerBuildSysForVom_Global.push_back(checkE0);
	bool checkE0_Element = checkBuildSysForCom_E0_Element();
	checkerBuildSysForVom_Global.push_back(checkE0_Element);
	bool checkE1 = checkBuildSysForCom_E1();
	checkerBuildSysForVom_Global.push_back(checkE1);
	bool checkE1_Element = checkBuildSysForCom_E1_Element();
	checkerBuildSysForVom_Global.push_back(checkE1_Element);
	bool checkE2 = checkBuildSysForCom_E2();
	checkerBuildSysForVom_Global.push_back(checkE2);
	bool checkE2_Element = checkBuildSysForCom_E2_Element();
	checkerBuildSysForVom_Global.push_back(checkE2_Element);
	bool checkE3 = checkBuildSysForCom_E3();
	checkerBuildSysForVom_Global.push_back(checkE3);
	bool checkE3_Element = checkBuildSysForCom_E3_Element();
	checkerBuildSysForVom_Global.push_back(checkE3_Element);
	bool checkE4 = checkBuildSysForCom_E4();
	checkerBuildSysForVom_Global.push_back(checkE4);
	bool checkE4_Element = checkBuildSysForCom_E4_Element();
	checkerBuildSysForVom_Global.push_back(checkE4_Element);


	bool checkReturn_Global = Math::checkTrueOfVectorElements(checkerBuildSysForVom_Global);
	return checkReturn_Global;


}

bool testBuildSysForCombination::checkBuildSysForCom_E0()
{
	std::vector<bool> workBuildSysForCom_E0;
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
//	Sphere1_E0.setParameterRadius(-50, 50.0, 0.0, typeModifierVariable);
//	Sphere2_E0.setParameterRadius(-30, 75.0, 0.0, typeModifierVariable);
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
//	// check opt sys by ray tracing
//	SequentialRayTracing seqTracE0_optA(/*optical system element*/ optSystemElement_E0, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6.0,/*arms*/ 8.0, /*refractive index*/ 1.0, Light_E0);
//	Spot spot_E0_optA(seqTracE0_optA.getAllInterPointsAtSurf_i_notFiltered(5), seqTracE0_optA.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
//	real rms_E0_optA = spot_E0_optA.getRMS_µm();
//	bool checkSysE0_optA = Math::compareTwoNumbers_decimals(rms_E0_optA, 105.347, 2);
//	workBuildSysForCom_E0.push_back(checkSysE0_optA);
//
//	// def steps variables
//	stepsWithoutMinWithoutMax addInfosVarS1(1, 10, -10, 10);
//	stepsWithoutMinWithoutMax addInfosVarS2(2, 5, -5, 5);
//
//	std::vector<stepsWithoutMinWithoutMax> addInfosVariable{ addInfosVarS1,addInfosVarS2 };
//
//	BuildSystemsForCombination buildSysCom_E0(optSystemElement_E0, addInfosVariable, 550.0, buildLLT);
//	bool checkDistances = buildSysCom_E0.checkDistances();
//	workBuildSysForCom_E0.push_back(checkDistances);
//	bool checkInteractions = buildSysCom_E0.checkInteractions();
//	workBuildSysForCom_E0.push_back(checkInteractions);
//
//	std::vector<unsigned int> combinationChecker{ 1,8,19,1,1,1 };
//	bool checkCombinations = buildSysCom_E0.checkCombinations_LLT(6, combinationChecker);
//	workBuildSysForCom_E0.push_back(checkCombinations);
//
//	std::vector<real>save_allCombinations_Radius_S1{
//		-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,
//		-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,
//		-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,
//		-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,
//		20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,
//		30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,
//		40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,
//		50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0, };
//
//	std::vector<real> save_allCombinatins_Radius_S2{
//		-30.0,-25.0,-20.0,-15.0,-10.0,10.0,15.0,20.0,25.0,30.0,35.0,40.0,45.0,50.0,55.0,60.0,65.0,70.0,75.0,
//		-30.0,-25.0,-20.0,-15.0,-10.0,10.0,15.0,20.0,25.0,30.0,35.0,40.0,45.0,50.0,55.0,60.0,65.0,70.0,75.0,
//		-30.0,-25.0,-20.0,-15.0,-10.0,10.0,15.0,20.0,25.0,30.0,35.0,40.0,45.0,50.0,55.0,60.0,65.0,70.0,75.0,
//		-30.0,-25.0,-20.0,-15.0,-10.0,10.0,15.0,20.0,25.0,30.0,35.0,40.0,45.0,50.0,55.0,60.0,65.0,70.0,75.0,
//		-30.0,-25.0,-20.0,-15.0,-10.0,10.0,15.0,20.0,25.0,30.0,35.0,40.0,45.0,50.0,55.0,60.0,65.0,70.0,75.0,
//		-30.0,-25.0,-20.0,-15.0,-10.0,10.0,15.0,20.0,25.0,30.0,35.0,40.0,45.0,50.0,55.0,60.0,65.0,70.0,75.0,
//		-30.0,-25.0,-20.0,-15.0,-10.0,10.0,15.0,20.0,25.0,30.0,35.0,40.0,45.0,50.0,55.0,60.0,65.0,70.0,75.0,
//		-30.0,-25.0,-20.0,-15.0,-10.0,10.0,15.0,20.0,25.0,30.0,35.0,40.0,45.0,50.0,55.0,60.0,65.0,70.0,75.0, };
//
//	bool checkCombinationsSurface1_radius = buildSysCom_E0.checkCombiRadiusAtSurface(1, save_allCombinations_Radius_S1, 0.001);
//	workBuildSysForCom_E0.push_back(checkCombinationsSurface1_radius);
//	bool checkCombinationsSurface2_radius = buildSysCom_E0.checkCombiRadiusAtSurface(2, save_allCombinatins_Radius_S2, 0.001);
//	workBuildSysForCom_E0.push_back(checkCombinationsSurface2_radius);
//
//
	bool returnChecker_E0 = Math::checkTrueOfVectorElements(workBuildSysForCom_E0);

	return returnChecker_E0;
}
bool testBuildSysForCombination::checkBuildSysForCom_E1()
{

	std::vector<bool> workBuildSysForCom_E1;

//	// set the wavelength
//	Light_LLT Light_E1;
//	Light_E1.setWavelength(550.0);
//	Light_E1.setIntensity(1.0);
//	std::vector<Light_LLT> lichtVecE1{ Light_E1 };
//

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
//
//	// surfaces E1
//	ApertureStopElement AperStop0_E1(/* semi height*/1.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
//	SphericalElement Sphere1_E1(/*radius*/ 10.0, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
//	SphericalElement Sphere2_E1(/*radius*/ 70.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF8_S1(), /*refractive index B*/glasses.getBK7_S1());
//	SphericalElement Sphere3_E1(/*radius*/ 50.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF8_S1());
//	SphericalElement Sphere4_E1(/*radius*/ 15.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF13_S1());
//	SphericalElement Sphere5_E1(/*radius*/ 20.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF13_S1(), /*refractive index B*/glasses.getBK7_S1());
//	SphericalElement Sphere6_E1(/*radius*/ 30.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
//	PlanElement Plan7_E1(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,50.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
//
//	Sphere2_E1.setParameterRadius(-50.0, 50.0, 0.0, typeModifierVariable);
//	Sphere2_E1.setParameterPointZ(15.0, 25.0, 0.0, typeModifierVariable);
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
//
//	// check opt sys by ray tracing
//	SequentialRayTracing seqTracE1_optA(/*optical system element*/ optSystemElement_E1, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6.0,/*arms*/ 8.0, /*refractive index*/ 1.0, Light_E1);
//	Spot spot_E1_optA(seqTracE1_optA.getAllInterPointsAtSurf_i_notFiltered(7), seqTracE1_optA.getAllInterPointsAtSurf_i_notFiltered(7).at(0));
//	real rms_E1_optA = spot_E1_optA.getRMS_µm();
//	bool checkSysE1_optA = Math::compareTwoNumbers_decimals(rms_E1_optA, 704.485, 3);
//	workBuildSysForCom_E1.push_back(checkSysE1_optA);
//
//	// def steps variables
//	stepsWithoutMinWithoutMax addInfosVarS2_Radius(2, 10, -10, 10);
//	stepsWithoutMinWithoutMax addInfosVarS2_Pos(2, 5, -5, 5); //was eingeben, wenn nichts ausgeblendet wird
//
//	std::vector<stepsWithoutMinWithoutMax> addInfosVariable{ addInfosVarS2_Radius,addInfosVarS2_Pos };
//
//	BuildSystemsForCombination buildSysCom_E1(optSystemElement_E1, addInfosVariable, 550.0, buildLLT);
//	bool checkDistances = buildSysCom_E1.checkDistances();
//	workBuildSysForCom_E1.push_back(checkDistances);
//	bool checkInteractions = buildSysCom_E1.checkInteractions();
//	workBuildSysForCom_E1.push_back(checkInteractions);
//
//	std::vector<unsigned int> combinationChecker{ 1,1,24,1,1,1,1,1 };
//	bool checkCombinations = buildSysCom_E1.checkCombinations_LLT(8, combinationChecker);
//	workBuildSysForCom_E1.push_back(checkCombinations);
//
//	std::vector<real>save_allCombinations_Radius_S2{
//		-50.0,-50.0,-50.0,
//		-40.0,-40.0,-40.0,
//		-30.0,-30.0,-30.0,
//		-20.0,-20.0,-20.0,
//		20.0,20.0,20.0,
//		30.0,30.0,30.0,
//		40.0,40.0,40.0,
//		50.0,50.0,50.0 };
//
//	std::vector<real> save_allCombinatins_Position_S2{
//		15.0,20.0,25.0,
//		15.0,20.0,25.0,
//		15.0,20.0,25.0,
//		15.0,20.0,25.0,
//		15.0,20.0,25.0,
//		15.0,20.0,25.0,
//		15.0,20.0,25.0,
//		15.0,20.0,25.0, };
//
//	bool checkCombinationsSurface2_radius = buildSysCom_E1.checkCombiRadiusAtSurface(2, save_allCombinations_Radius_S2, 0.001);
//	workBuildSysForCom_E1.push_back(checkCombinationsSurface2_radius);
//	bool checkCombinationsSurface2_postition = buildSysCom_E1.checkCombiPosAtSurface(2, save_allCombinatins_Position_S2, 0.001);
//	workBuildSysForCom_E1.push_back(checkCombinationsSurface2_postition);
//
//
	bool returnChecker_E1 = Math::checkTrueOfVectorElements(workBuildSysForCom_E1);
	return returnChecker_E1;
}
bool testBuildSysForCombination::checkBuildSysForCom_E2()
{
	std::vector<bool> workBuildSysForCom_E2;

//	// set the wavelength
//	Light_LLT Light_E2;
//	Light_E2.setWavelength(550.0);
//	Light_E2.setIntensity(1.0);
//	std::vector<Light_LLT> lichtVecE2{ Light_E2 };
//

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
//
//	// check opt sys by ray tracing
//	SequentialRayTracing seqTracE2_optA(/*optical system element*/ optSystemElement_E2, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6.0,/*arms*/ 8.0, /*refractive index*/ 1.0, Light_E2);
//	Spot spot_E2_optA(seqTracE2_optA.getAllInterPointsAtSurf_i_notFiltered(5), seqTracE2_optA.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
//	real rms_E2_optA = spot_E2_optA.getRMS_µm();
//	bool checkSysE2_optA = Math::compareTwoNumbers_decimals(rms_E2_optA, 1558.55, 0);
//	workBuildSysForCom_E2.push_back(checkSysE2_optA);
//
//	// def steps variables
//	stepsWithoutMinWithoutMax addInfosVarS3_Radius(3, 10, -10, 10);
//	stepsWithoutMinWithoutMax addInfosVarS4_Radius(4, 5, -10, 10);
//
//	std::vector<stepsWithoutMinWithoutMax> addInfosVariable{ addInfosVarS3_Radius,addInfosVarS4_Radius };
//
//	BuildSystemsForCombination buildSysCom_E2(optSystemElement_E2, addInfosVariable, 550.0, buildLLT);
//	bool checkDistances = buildSysCom_E2.checkDistances();
//	workBuildSysForCom_E2.push_back(checkDistances);
//	bool checkInteractions = buildSysCom_E2.checkInteractions();
//	workBuildSysForCom_E2.push_back(checkInteractions);
//
//	std::vector<unsigned int> combinationChecker{ 1,1,1,8,6,1 };
//	bool checkCombinations = buildSysCom_E2.checkCombinations_LLT(6, combinationChecker);
//	workBuildSysForCom_E2.push_back(checkCombinations);
//
//	std::vector<real>save_allCombinations_Radius_S3{
//		-50.0, -50.0,-50.0,-50.0,-50.0,-50.0,
//		-40.0, -40.0,-40.0,-40.0,-40.0,-40.0,
//		-30.0, -30.0,-30.0,-30.0,-30.0,-30.0,
//		-20.0, -20.0,-20.0,-20.0,-20.0,-20.0,
//		20.0, 20.0,20.0,20.0,20.0,20.0,
//		30.0, 30.0,30.0,30.0,30.0,30.0,
//		40.0, 40.0,40.0,40.0,40.0,40.0,
//		50.0, 50.0,50.0,50.0,50.0,50.0 };
//
//	std::vector<real> save_allCombinatins_Radius_S4{
//		-25.0,-20.0,-15.0,15.0,20.0,25.0,
//		-25.0,-20.0,-15.0,15.0,20.0,25.0,
//		-25.0,-20.0,-15.0,15.0,20.0,25.0,
//		-25.0,-20.0,-15.0,15.0,20.0,25.0,
//		-25.0,-20.0,-15.0,15.0,20.0,25.0,
//		-25.0,-20.0,-15.0,15.0,20.0,25.0,
//		-25.0,-20.0,-15.0,15.0,20.0,25.0,
//		-25.0,-20.0,-15.0,15.0,20.0,25.0, };
//
//	bool checkCombinationsSurface3_radius = buildSysCom_E2.checkCombiRadiusAtSurface(3, save_allCombinations_Radius_S3, 0.001);
//	workBuildSysForCom_E2.push_back(checkCombinationsSurface3_radius);
//	bool checkCombinationsSurface4_radius = buildSysCom_E2.checkCombiRadiusAtSurface(4, save_allCombinatins_Radius_S4, 0.001);
//	workBuildSysForCom_E2.push_back(checkCombinationsSurface4_radius);


	bool returnChecker_E2 = Math::checkTrueOfVectorElements(workBuildSysForCom_E2);
	return returnChecker_E2;
}


bool testBuildSysForCombination::checkBuildSysForCom_E3()
{

	std::vector<bool> workBuildSysForCom_E3;
//	// set the wavelength
//	Light_LLT Light_E3;
//	Light_E3.setWavelength(550.0);
//	Light_E3.setIntensity(1.0);
//	std::vector<Light_LLT> lichtVecE3{ Light_E3 };
//
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
//
//	// single ray tracing
//	Ray_LLT rayE3(/*origin*/{ 0.0,0.0,0.0 },/*direction*/{ 0.0,1.0,10.0 },/*refractive index*/ 1.0);
//	LightRayStruct ligthRayE3(Light_E3, rayE3, 1.0);
//	SequentialRayTracing singleTrace(optSystemElement_E3);
//	singleTrace.sequentialRayTracing(ligthRayE3);
//
//	// check opt sys by ray tracing
//	SequentialRayTracing seqTracE3_optA(/*optical system element*/ optSystemElement_E3, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6.0,/*arms*/ 8.0, /*refractive index*/ 1.0, Light_E3);
//	Spot spot_E3_optA(seqTracE3_optA.getAllInterPointsAtSurf_i_notFiltered(6), seqTracE3_optA.getAllInterPointsAtSurf_i_notFiltered(6).at(0));
//	real rms_E3_optA = spot_E3_optA.getRMS_µm();
//	bool checkSysE3_optA = Math::compareTwoNumbers_decimals(rms_E3_optA, 394.514, 3);
//	workBuildSysForCom_E3.push_back(checkSysE3_optA);
//
//	// def steps variables
//	stepsWithoutMinWithoutMax addInfosVarS3_Position(3, 10, -1, 1);
//	stepsWithoutMinWithoutMax addInfosVarS4_Position(4, 10, -1, 1);
//
//	std::vector<stepsWithoutMinWithoutMax> addInfosVariable{ addInfosVarS3_Position,addInfosVarS4_Position };
//	//stop here!
//	BuildSystemsForCombination buildSysCom_E3(optSystemElement_E3, addInfosVariable, 550.0, buildLLT);
//	bool checkDistances = buildSysCom_E3.checkDistances();
//	workBuildSysForCom_E3.push_back(checkDistances);
//	bool checkInteractions = buildSysCom_E3.checkInteractions();
//	workBuildSysForCom_E3.push_back(checkInteractions);
//
//	std::vector<unsigned int> combinationChecker{ 1,1,1,3,6,1,1 };
//	bool checkCombinations = buildSysCom_E3.checkCombinations_LLT(7, combinationChecker);
//	workBuildSysForCom_E3.push_back(checkCombinations);
//
//	std::vector<real>save_allCombinations_Position_S3{
//	29.0, 29.0, 29.0, 29.0, 29.0, 29.0,
//	39.0, 39.0, 39.0, 39.0, 39.0, 39.0,
//	49.0, 49.0, 49.0,49.0, 49.0, 49.0
//	};
//
//	std::vector<real> save_allCombinatins_Position_S4{
//		59.0, 69.0, 79.0, 89.0, 99.0, 109.0,
//		59.0, 69.0, 79.0, 89.0, 99.0, 109.0,
//		59.0, 69.0, 79.0, 89.0, 99.0, 109.0,
//	};
//
//	bool checkCombinationsSurface3_position = buildSysCom_E3.checkCombiPosAtSurface(3, save_allCombinations_Position_S3, 0.001);
//	workBuildSysForCom_E3.push_back(checkCombinationsSurface3_position);
//	bool checkCombinationsSurface4_position = buildSysCom_E3.checkCombiPosAtSurface(4, save_allCombinatins_Position_S4, 0.001);
//	workBuildSysForCom_E3.push_back(checkCombinationsSurface4_position);
//
//
	bool returnChecker_E3 = Math::checkTrueOfVectorElements(workBuildSysForCom_E3);
	return returnChecker_E3;
}
bool testBuildSysForCombination::checkBuildSysForCom_E4()
{
	std::vector<bool> workBuildSysForCom_E4;
	//	// set the wavelength
	//	Light_LLT Light_E4;
	//	Light_E4.setWavelength(550.0);
	//	Light_E4.setIntensity(1.0);
	//	std::vector<Light_LLT> lichtVecE4{ Light_E4 };
	//
	
	//
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
	//
	//	// surfaces E4
	//	ApertureStopElement AperStop0_E4(/* semi height*/1.0, /*point*/{ 0.0,0.0,7.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	//	SphericalElement Sphere1_E4(/*radius*/ 15.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,12.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF13_S1());
	//	SphericalElement Sphere2_E4(/*radius*/ 20.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,17.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF13_S1());
	//	SphericalElement Sphere3_E4(/*radius*/ 40.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,32.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF13_S1(), /*refractive index B*/glasses.getAir());
	//	SphericalElement Sphere4_E4(/*radius*/ 90.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,37.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF13_S1(), /*refractive index B*/glasses.getAir());
	//	SphericalElement Sphere5_E4(/*radius*/ 40.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF13_S1());
	//	SphericalElement Sphere6_E4(/*radius*/ 15.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF13_S1());
	//	PlanElement Plan7_E4(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	//
	//	Sphere1_E4.setParameterRadius(-50.0, 50.0, 0.0, typeModifierVariable);
	//	Sphere4_E4.setParameterRadius(-200.0, 200.0, 0.0, typeModifierVariable);
	//
	//
	//	surfacePtr Aper0_E4_ptr = AperStop0_E4.clone();
	//	surfacePtr Sphere1_E4_ptr = Sphere1_E4.clone();
	//	surfacePtr Sphere2_E4_ptr = Sphere2_E4.clone();
	//	surfacePtr Sphere3_E4_ptr = Sphere3_E4.clone();
	//	surfacePtr Sphere4_E4_ptr = Sphere4_E4.clone();
	//	surfacePtr Sphere5_E4_ptr = Sphere5_E4.clone();
	//	surfacePtr Sphere6_E4_ptr = Sphere6_E4.clone();
	//	surfacePtr Plan7_E4_ptr = Plan7_E4.clone();
	//
	//	std::vector<surfacePtr> opticalSystemE4_ptr{ Aper0_E4_ptr, Sphere1_E4_ptr, Sphere2_E4_ptr , Sphere3_E4_ptr, Sphere4_E4_ptr, Sphere5_E4_ptr, Sphere6_E4_ptr, Plan7_E4_ptr };
	//	std::vector<interaction_ptr> interactionsE4_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(),  refrac.clone(),  refrac.clone(), absorb.clone() };
	//
	//	//	build optical system
	//	OpticalSystemElement optSystemElement_E4(opticalSystemE4_ptr, interactionsE4_ptr);
	//	optSystemElement_E4.setRefractiveIndexAccordingToWavelength(550.0);
	//
	//	// single ray tracing
	//	Ray_LLT rayE4(/*origin*/{ 0.0,0.0,0.0 },/*direction*/{ 0.0,1.0,7.0 },/*refractive index*/ 1.0);
	//	LightRayStruct ligthRayE4(Light_E4, rayE4, 1.0);
	//	SequentialRayTracing singleTrace(optSystemElement_E4);
	//	singleTrace.sequentialRayTracing(ligthRayE4);
	//
	//	// check opt sys by ray tracing
	//	SequentialRayTracing seqTracE4_optA(/*optical system element*/ optSystemElement_E4, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6.0,/*arms*/ 8.0, /*refractive index*/ 1.0, Light_E4);
	//	Spot spot_E4_optA(seqTracE4_optA.getAllInterPointsAtSurf_i_notFiltered(7), seqTracE4_optA.getAllInterPointsAtSurf_i_notFiltered(7).at(0));
	//	real rms_E4_optA = spot_E4_optA.getRMS_µm();
	//	bool checkSysE4_optA = Math::compareTwoNumbers_decimals(rms_E4_optA, 909.391, 3);
	//	workBuildSysForCom_E4.push_back(checkSysE4_optA);
	//
	//	// def steps variables
	//	stepsWithoutMinWithoutMax addInfosVarS1_Radius(1, 10, -10, 10);
	//	stepsWithoutMinWithoutMax addInfosVarS4_Radius(4, 20, -20, 20);
	//
	//	std::vector<stepsWithoutMinWithoutMax> addInfosVariable{ addInfosVarS1_Radius,addInfosVarS4_Radius };
	//
	//	BuildSystemsForCombination buildSysCom_E4(optSystemElement_E4, addInfosVariable, 550.0, buildLLT);
	//	bool checkDistances = buildSysCom_E4.checkDistances();
	//	workBuildSysForCom_E4.push_back(checkDistances);
	//	bool checkInteractions = buildSysCom_E4.checkInteractions();
	//	workBuildSysForCom_E4.push_back(checkInteractions);
	//
	//	std::vector<unsigned int> combinationChecker{ 1,8,1,1,18,1,1,1 };
	//	bool checkCombinations = buildSysCom_E4.checkCombinations_LLT(8, combinationChecker);
	//	workBuildSysForCom_E4.push_back(checkCombinations);
	//
	//	std::vector<real>save_allCombinations_Radius_S1{
	//		-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,
	//		-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,
	//		-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,
	//		-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,
	//		20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,
	//		30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,
	//		40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,
	//		50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,
	//	};
	//
	//	std::vector<real> save_allCombinatins_Radius_S4{
	//
	//		-200.0,-180.0,-160.0,-140.0,-120.0,-100.0,-80.0,-60.0,-40.0,40.0,60.0,80.0,100.0,120.0,140.0,160.0,180.0,200.0,
	//		-200.0,-180.0,-160.0,-140.0,-120.0,-100.0,-80.0,-60.0,-40.0,40.0,60.0,80.0,100.0,120.0,140.0,160.0,180.0,200.0,
	//		-200.0,-180.0,-160.0,-140.0,-120.0,-100.0,-80.0,-60.0,-40.0,40.0,60.0,80.0,100.0,120.0,140.0,160.0,180.0,200.0,
	//		-200.0,-180.0,-160.0,-140.0,-120.0,-100.0,-80.0,-60.0,-40.0,40.0,60.0,80.0,100.0,120.0,140.0,160.0,180.0,200.0,
	//		-200.0,-180.0,-160.0,-140.0,-120.0,-100.0,-80.0,-60.0,-40.0,40.0,60.0,80.0,100.0,120.0,140.0,160.0,180.0,200.0,
	//		-200.0,-180.0,-160.0,-140.0,-120.0,-100.0,-80.0,-60.0,-40.0,40.0,60.0,80.0,100.0,120.0,140.0,160.0,180.0,200.0,
	//		-200.0,-180.0,-160.0,-140.0,-120.0,-100.0,-80.0,-60.0,-40.0,40.0,60.0,80.0,100.0,120.0,140.0,160.0,180.0,200.0,
	//		-200.0,-180.0,-160.0,-140.0,-120.0,-100.0,-80.0,-60.0,-40.0,40.0,60.0,80.0,100.0,120.0,140.0,160.0,180.0,200.0,
	//	};
	//
	//	bool checkCombinationsSurfacE4_radius = buildSysCom_E4.checkCombiRadiusAtSurface(1, save_allCombinations_Radius_S1, 0.001);
	//	workBuildSysForCom_E4.push_back(checkCombinationsSurfacE4_radius);
	//	bool checkCombinationsSurface4_radius = buildSysCom_E4.checkCombiRadiusAtSurface(4, save_allCombinatins_Radius_S4, 0.001);
	//	workBuildSysForCom_E4.push_back(checkCombinationsSurface4_radius);
	//
	//
	bool returnChecker_E4 = Math::checkTrueOfVectorElements(workBuildSysForCom_E4);
	return returnChecker_E4;
}


bool testBuildSysForCombination::checkBuildSysForCom_E0_Element()
{
	std::vector<bool> workBuildSysForCom_E0_Element;
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
//	Sphere1_E0.setParameterRadius(-50, 50.0, 0.0, typeModifierVariable);
//	Sphere2_E0.setParameterRadius(-30, 75.0, 0.0, typeModifierVariable);
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
//	// check opt sys by ray tracing
//	SequentialRayTracing seqTracE0_optA(/*optical system element*/ optSystemElement_E0, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6.0,/*arms*/ 8.0, /*refractive index*/ 1.0, Light_E0);
//	Spot spot_E0_optA(seqTracE0_optA.getAllInterPointsAtSurf_i_notFiltered(5), seqTracE0_optA.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
//	real rms_E0_optA = spot_E0_optA.getRMS_µm();
//	bool checkSysE0_optA = Math::compareTwoNumbers_decimals(rms_E0_optA, 105.347, 2);
//	workBuildSysForCom_E0_Element.push_back(checkSysE0_optA);
//
//	// def steps variables
//	stepsWithoutMinWithoutMax addInfosVarS1(1, 10, -10, 10);
//	stepsWithoutMinWithoutMax addInfosVarS2(2, 5, -5, 5);
//
//	std::vector<stepsWithoutMinWithoutMax> addInfosVariable{ addInfosVarS1,addInfosVarS2 };
//
//	BuildSystemsForCombination buildSysCom_E0(optSystemElement_E0, addInfosVariable, 550.0, buildElement);
//
//
//	//BuildSystemsForCombination buildSysCom_E0(optSystemElement_E0, addInfosVariable, 550.0, buildLLT);
//	bool checkDistances = buildSysCom_E0.checkDistances();
//	workBuildSysForCom_E0_Element.push_back(checkDistances);
//	bool checkInteractions = buildSysCom_E0.checkInteractions();
//	workBuildSysForCom_E0_Element.push_back(checkInteractions);
//
//	std::vector<unsigned int> combinationChecker{ 1,8,19,1,1,1 };
//	bool checkCombinations = buildSysCom_E0.checkCombination_Element(6, combinationChecker);
//	workBuildSysForCom_E0_Element.push_back(checkCombinations);
//
//	std::vector<real>save_allCombinations_Radius_S1{
//		-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,
//		-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,
//		-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,
//		-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,
//		20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,
//		30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,
//		40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,
//		50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0, };
//
//	std::vector<real> save_allCombinatins_Radius_S2{
//		-30.0,-25.0,-20.0,-15.0,-10.0,10.0,15.0,20.0,25.0,30.0,35.0,40.0,45.0,50.0,55.0,60.0,65.0,70.0,75.0,
//		-30.0,-25.0,-20.0,-15.0,-10.0,10.0,15.0,20.0,25.0,30.0,35.0,40.0,45.0,50.0,55.0,60.0,65.0,70.0,75.0,
//		-30.0,-25.0,-20.0,-15.0,-10.0,10.0,15.0,20.0,25.0,30.0,35.0,40.0,45.0,50.0,55.0,60.0,65.0,70.0,75.0,
//		-30.0,-25.0,-20.0,-15.0,-10.0,10.0,15.0,20.0,25.0,30.0,35.0,40.0,45.0,50.0,55.0,60.0,65.0,70.0,75.0,
//		-30.0,-25.0,-20.0,-15.0,-10.0,10.0,15.0,20.0,25.0,30.0,35.0,40.0,45.0,50.0,55.0,60.0,65.0,70.0,75.0,
//		-30.0,-25.0,-20.0,-15.0,-10.0,10.0,15.0,20.0,25.0,30.0,35.0,40.0,45.0,50.0,55.0,60.0,65.0,70.0,75.0,
//		-30.0,-25.0,-20.0,-15.0,-10.0,10.0,15.0,20.0,25.0,30.0,35.0,40.0,45.0,50.0,55.0,60.0,65.0,70.0,75.0,
//		-30.0,-25.0,-20.0,-15.0,-10.0,10.0,15.0,20.0,25.0,30.0,35.0,40.0,45.0,50.0,55.0,60.0,65.0,70.0,75.0, };
//
//	bool checkCombinationsSurface1_radius = buildSysCom_E0.checkCombiRadiusAtSurface(1, save_allCombinations_Radius_S1, 0.001);
//	workBuildSysForCom_E0_Element.push_back(checkCombinationsSurface1_radius);
//	bool checkCombinationsSurface2_radius = buildSysCom_E0.checkCombiRadiusAtSurface(2, save_allCombinatins_Radius_S2, 0.001);
//	workBuildSysForCom_E0_Element.push_back(checkCombinationsSurface2_radius);
//
//
	bool returnChecker_E0_Element = Math::checkTrueOfVectorElements(workBuildSysForCom_E0_Element);
	return returnChecker_E0_Element;

}
bool testBuildSysForCombination::checkBuildSysForCom_E1_Element()
{
	std::vector<bool> workBuildSysForCom_E1_Element;
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
//	Light_LLT Light_E1;
//	Light_E1.setWavelength(550.0);
//	Light_E1.setIntensity(1.0);
//	std::vector<Light_LLT> lichtVecE1{ Light_E1 };
//
//
//	// set the wavelength
//	real primWavelength = 550.0;
//
//	// surfaces E1
//	ApertureStopElement AperStop0_E1(/* semi height*/1.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
//	SphericalElement Sphere1_E1(/*radius*/ 10.0, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
//	SphericalElement Sphere2_E1(/*radius*/ 70.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF8_S1(), /*refractive index B*/glasses.getBK7_S1());
//	SphericalElement Sphere3_E1(/*radius*/ 50.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF8_S1());
//	SphericalElement Sphere4_E1(/*radius*/ 15.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF13_S1());
//	SphericalElement Sphere5_E1(/*radius*/ 20.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF13_S1(), /*refractive index B*/glasses.getBK7_S1());
//	SphericalElement Sphere6_E1(/*radius*/ 30.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBK7_S1());
//	PlanElement Plan7_E1(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,50.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
//
//	Sphere2_E1.setParameterRadius(-50.0, 50.0, 0.0, typeModifierVariable);
//	Sphere2_E1.setParameterPointZ(15.0, 25.0, 0.0, typeModifierVariable);
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
//
//	// check opt sys by ray tracing
//	SequentialRayTracing seqTracE1_optA(/*optical system element*/ optSystemElement_E1, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6.0,/*arms*/ 8.0, /*refractive index*/ 1.0, Light_E1);
//	Spot spot_E1_optA(seqTracE1_optA.getAllInterPointsAtSurf_i_notFiltered(7), seqTracE1_optA.getAllInterPointsAtSurf_i_notFiltered(7).at(0));
//	real rms_E1_optA = spot_E1_optA.getRMS_µm();
//	bool checkSysE1_optA = Math::compareTwoNumbers_decimals(rms_E1_optA, 704.485, 3);
//	workBuildSysForCom_E1_Element.push_back(checkSysE1_optA);
//
//	// def steps variables
//	stepsWithoutMinWithoutMax addInfosVarS2_Radius(2, 10, -10, 10);
//	stepsWithoutMinWithoutMax addInfosVarS2_Pos(2, 5, -5, 5); //was eingeben, wenn nichts ausgeblendet wird
//
//	std::vector<stepsWithoutMinWithoutMax> addInfosVariable{ addInfosVarS2_Radius,addInfosVarS2_Pos };
//
//	BuildSystemsForCombination buildSysCom_E1(optSystemElement_E1, addInfosVariable, 550.0, buildElement);
//	bool checkDistances = buildSysCom_E1.checkDistances();
//	workBuildSysForCom_E1_Element.push_back(checkDistances);
//	bool checkInteractions = buildSysCom_E1.checkInteractions();
//	workBuildSysForCom_E1_Element.push_back(checkInteractions);
//
//	std::vector<unsigned int> combinationChecker{ 1,1,24,1,1,1,1,1 };
//	bool checkCombinations = buildSysCom_E1.checkCombination_Element(8, combinationChecker);
//	workBuildSysForCom_E1_Element.push_back(checkCombinations);
//
//	std::vector<real>save_allCombinations_Radius_S2{
//		-50.0,-50.0,-50.0,
//		-40.0,-40.0,-40.0,
//		-30.0,-30.0,-30.0,
//		-20.0,-20.0,-20.0,
//		20.0,20.0,20.0,
//		30.0,30.0,30.0,
//		40.0,40.0,40.0,
//		50.0,50.0,50.0 };
//
//	std::vector<real> save_allCombinatins_Position_S2{
//		15.0,20.0,25.0,
//		15.0,20.0,25.0,
//		15.0,20.0,25.0,
//		15.0,20.0,25.0,
//		15.0,20.0,25.0,
//		15.0,20.0,25.0,
//		15.0,20.0,25.0,
//		15.0,20.0,25.0, };
//
//	bool checkCombinationsSurface2_radius = buildSysCom_E1.checkCombiRadiusAtSurface(2, save_allCombinations_Radius_S2, 0.001);
//	workBuildSysForCom_E1_Element.push_back(checkCombinationsSurface2_radius);
//	bool checkCombinationsSurface2_postition = buildSysCom_E1.checkCombiPosAtSurface(2, save_allCombinatins_Position_S2, 0.001);
//	workBuildSysForCom_E1_Element.push_back(checkCombinationsSurface2_postition);
//

	bool returnChecker_E1 = Math::checkTrueOfVectorElements(workBuildSysForCom_E1_Element);
	return returnChecker_E1;
}

bool testBuildSysForCombination::checkBuildSysForCom_E2_Element()
{
	std::vector<bool> workBuildSysForCom_E2_Element;
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
//	Light_LLT Light_E2;
//	Light_E2.setWavelength(550.0);
//	Light_E2.setIntensity(1.0);
//	std::vector<Light_LLT> lichtVecE2{ Light_E2 };
//
//
//	// set the wavelength
//	real primWavelength = 550.0;
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
//
//	// check opt sys by ray tracing
//	SequentialRayTracing seqTracE2_optA(/*optical system element*/ optSystemElement_E2, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6.0,/*arms*/ 8.0, /*refractive index*/ 1.0, Light_E2);
//	Spot spot_E2_optA(seqTracE2_optA.getAllInterPointsAtSurf_i_notFiltered(5), seqTracE2_optA.getAllInterPointsAtSurf_i_notFiltered(5).at(0));
//	real rms_E2_optA = spot_E2_optA.getRMS_µm();
//	bool checkSysE2_optA = Math::compareTwoNumbers_decimals(rms_E2_optA, 1558.55, 0);
//	workBuildSysForCom_E2_Element.push_back(checkSysE2_optA);
//
//	// def steps variables
//	stepsWithoutMinWithoutMax addInfosVarS3_Radius(3, 10, -10, 10);
//	stepsWithoutMinWithoutMax addInfosVarS4_Radius(4, 5, -10, 10);
//
//	std::vector<stepsWithoutMinWithoutMax> addInfosVariable{ addInfosVarS3_Radius,addInfosVarS4_Radius };
//
//	BuildSystemsForCombination buildSysCom_E2(optSystemElement_E2, addInfosVariable, 550.0, buildElement);
//	bool checkDistances = buildSysCom_E2.checkDistances();
//	workBuildSysForCom_E2_Element.push_back(checkDistances);
//	bool checkInteractions = buildSysCom_E2.checkInteractions();
//	workBuildSysForCom_E2_Element.push_back(checkInteractions);
//
//	std::vector<unsigned int> combinationChecker{ 1,1,1,8,6,1 };
//	bool checkCombinations = buildSysCom_E2.checkCombination_Element(6, combinationChecker);
//	workBuildSysForCom_E2_Element.push_back(checkCombinations);
//
//	std::vector<real>save_allCombinations_Radius_S3{
//		-50.0, -50.0,-50.0,-50.0,-50.0,-50.0,
//		-40.0, -40.0,-40.0,-40.0,-40.0,-40.0,
//		-30.0, -30.0,-30.0,-30.0,-30.0,-30.0,
//		-20.0, -20.0,-20.0,-20.0,-20.0,-20.0,
//		20.0, 20.0,20.0,20.0,20.0,20.0,
//		30.0, 30.0,30.0,30.0,30.0,30.0,
//		40.0, 40.0,40.0,40.0,40.0,40.0,
//		50.0, 50.0,50.0,50.0,50.0,50.0 };
//
//	std::vector<real> save_allCombinatins_Radius_S4{
//		-25.0,-20.0,-15.0,15.0,20.0,25.0,
//		-25.0,-20.0,-15.0,15.0,20.0,25.0,
//		-25.0,-20.0,-15.0,15.0,20.0,25.0,
//		-25.0,-20.0,-15.0,15.0,20.0,25.0,
//		-25.0,-20.0,-15.0,15.0,20.0,25.0,
//		-25.0,-20.0,-15.0,15.0,20.0,25.0,
//		-25.0,-20.0,-15.0,15.0,20.0,25.0,
//		-25.0,-20.0,-15.0,15.0,20.0,25.0, };
//
//	bool checkCombinationsSurface3_radius = buildSysCom_E2.checkCombiRadiusAtSurface(3, save_allCombinations_Radius_S3, 0.001);
//	workBuildSysForCom_E2_Element.push_back(checkCombinationsSurface3_radius);
//	bool checkCombinationsSurface4_radius = buildSysCom_E2.checkCombiRadiusAtSurface(4, save_allCombinatins_Radius_S4, 0.001);
//	workBuildSysForCom_E2_Element.push_back(checkCombinationsSurface4_radius);
//
//
	bool returnChecker_E2 = Math::checkTrueOfVectorElements(workBuildSysForCom_E2_Element);
	return returnChecker_E2;
}

bool testBuildSysForCombination::checkBuildSysForCom_E3_Element()
{
	std::vector<bool> workBuildSysForCom_E3_Element;
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
//	Light_LLT Light_E3;
//	Light_E3.setWavelength(550.0);
//	Light_E3.setIntensity(1.0);
//	std::vector<Light_LLT> lichtVecE3{ Light_E3 };
//
//	// set the wavelength
//	real primWavelength = 550.0;
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
//
//	// single ray tracing
//	Ray_LLT rayE3(/*origin*/{ 0.0,0.0,0.0 },/*direction*/{ 0.0,1.0,10.0 },/*refractive index*/ 1.0);
//	LightRayStruct ligthRayE3(Light_E3, rayE3, 1.0);
//	SequentialRayTracing singleTrace(optSystemElement_E3);
//	singleTrace.sequentialRayTracing(ligthRayE3);
//
//	// check opt sys by ray tracing
//	SequentialRayTracing seqTracE3_optA(/*optical system element*/ optSystemElement_E3, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6.0,/*arms*/ 8.0, /*refractive index*/ 1.0, Light_E3);
//	Spot spot_E3_optA(seqTracE3_optA.getAllInterPointsAtSurf_i_notFiltered(6), seqTracE3_optA.getAllInterPointsAtSurf_i_notFiltered(6).at(0));
//	real rms_E3_optA = spot_E3_optA.getRMS_µm();
//	bool checkSysE3_optA = Math::compareTwoNumbers_decimals(rms_E3_optA, 394.514, 3);
//	workBuildSysForCom_E3_Element.push_back(checkSysE3_optA);
//
//	// def steps variables
//	stepsWithoutMinWithoutMax addInfosVarS3_Position(3, 10, -1, 1);
//	stepsWithoutMinWithoutMax addInfosVarS4_Position(4, 10, -1, 1);
//
//	std::vector<stepsWithoutMinWithoutMax> addInfosVariable{ addInfosVarS3_Position,addInfosVarS4_Position };
//	//stop here!
//	BuildSystemsForCombination buildSysCom_E3(optSystemElement_E3, addInfosVariable, 550.0, buildElement);
//	bool checkDistances = buildSysCom_E3.checkDistances();
//	workBuildSysForCom_E3_Element.push_back(checkDistances);
//	bool checkInteractions = buildSysCom_E3.checkInteractions();
//	workBuildSysForCom_E3_Element.push_back(checkInteractions);
//
//	std::vector<unsigned int> combinationChecker{ 1,1,1,3,6,1,1 };
//	bool checkCombinations = buildSysCom_E3.checkCombination_Element(7, combinationChecker);
//	workBuildSysForCom_E3_Element.push_back(checkCombinations);
//
//	std::vector<real>save_allCombinations_Position_S3{
//	29.0, 29.0, 29.0, 29.0, 29.0, 29.0,
//	39.0, 39.0, 39.0, 39.0, 39.0, 39.0,
//	49.0, 49.0, 49.0,49.0, 49.0, 49.0
//	};
//
//	std::vector<real> save_allCombinatins_Position_S4{
//		59.0, 69.0, 79.0, 89.0, 99.0, 109.0,
//		59.0, 69.0, 79.0, 89.0, 99.0, 109.0,
//		59.0, 69.0, 79.0, 89.0, 99.0, 109.0,
//	};
//
//	bool checkCombinationsSurface3_position = buildSysCom_E3.checkCombiPosAtSurface(3, save_allCombinations_Position_S3, 0.001);
//	workBuildSysForCom_E3_Element.push_back(checkCombinationsSurface3_position);
//	bool checkCombinationsSurface4_position = buildSysCom_E3.checkCombiPosAtSurface(4, save_allCombinatins_Position_S4, 0.001);
//	workBuildSysForCom_E3_Element.push_back(checkCombinationsSurface4_position);
//
//
	bool returnChecker_E3 = Math::checkTrueOfVectorElements(workBuildSysForCom_E3_Element);
	return returnChecker_E3;
}

bool testBuildSysForCombination::checkBuildSysForCom_E4_Element()
{
	std::vector<bool> workBuildSysForCom_E4_Element;
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
//	Light_LLT Light_E4;
//	Light_E4.setWavelength(550.0);
//	Light_E4.setIntensity(1.0);
//	std::vector<Light_LLT> lichtVecE4{ Light_E4 };
//
//	// set the wavelength
//	real primWavelength = 550.0;
//
//	// surfaces E4
//	ApertureStopElement AperStop0_E4(/* semi height*/1.0, /*point*/{ 0.0,0.0,7.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
//	SphericalElement Sphere1_E4(/*radius*/ 15.0, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,12.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF13_S1());
//	SphericalElement Sphere2_E4(/*radius*/ 20.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,17.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF13_S1());
//	SphericalElement Sphere3_E4(/*radius*/ 40.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,32.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF13_S1(), /*refractive index B*/glasses.getAir());
//	SphericalElement Sphere4_E4(/*radius*/ 90.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,37.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF13_S1(), /*refractive index B*/glasses.getAir());
//	SphericalElement Sphere5_E4(/*radius*/ 40.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF13_S1());
//	SphericalElement Sphere6_E4(/*radius*/ 15.00, /*semi height*/ 5.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF13_S1());
//	PlanElement Plan7_E4(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
//
//	Sphere1_E4.setParameterRadius(-50.0, 50.0, 0.0, typeModifierVariable);
//	Sphere4_E4.setParameterRadius(-200.0, 200.0, 0.0, typeModifierVariable);
//
//
//	surfacePtr Aper0_E4_ptr = AperStop0_E4.clone();
//	surfacePtr Sphere1_E4_ptr = Sphere1_E4.clone();
//	surfacePtr Sphere2_E4_ptr = Sphere2_E4.clone();
//	surfacePtr Sphere3_E4_ptr = Sphere3_E4.clone();
//	surfacePtr Sphere4_E4_ptr = Sphere4_E4.clone();
//	surfacePtr Sphere5_E4_ptr = Sphere5_E4.clone();
//	surfacePtr Sphere6_E4_ptr = Sphere6_E4.clone();
//	surfacePtr Plan7_E4_ptr = Plan7_E4.clone();
//
//	std::vector<surfacePtr> opticalSystemE4_ptr{ Aper0_E4_ptr, Sphere1_E4_ptr, Sphere2_E4_ptr , Sphere3_E4_ptr, Sphere4_E4_ptr, Sphere5_E4_ptr, Sphere6_E4_ptr, Plan7_E4_ptr };
//	std::vector<interaction_ptr> interactionsE4_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(),  refrac.clone(),  refrac.clone(), absorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement_E4(opticalSystemE4_ptr, interactionsE4_ptr);
//	optSystemElement_E4.setRefractiveIndexAccordingToWavelength(550.0);
//
//	// single ray tracing
//	Ray_LLT rayE4(/*origin*/{ 0.0,0.0,0.0 },/*direction*/{ 0.0,1.0,7.0 },/*refractive index*/ 1.0);
//	LightRayStruct ligthRayE4(Light_E4, rayE4, 1.0);
//	SequentialRayTracing singleTrace(optSystemElement_E4);
//	singleTrace.sequentialRayTracing(ligthRayE4);
//
//	// check opt sys by ray tracing
//	SequentialRayTracing seqTracE4_optA(/*optical system element*/ optSystemElement_E4, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6.0,/*arms*/ 8.0, /*refractive index*/ 1.0, Light_E4);
//	Spot spot_E4_optA(seqTracE4_optA.getAllInterPointsAtSurf_i_notFiltered(7), seqTracE4_optA.getAllInterPointsAtSurf_i_notFiltered(7).at(0));
//	real rms_E4_optA = spot_E4_optA.getRMS_µm();
//	bool checkSysE4_optA = Math::compareTwoNumbers_decimals(rms_E4_optA, 909.391, 3);
//	workBuildSysForCom_E4_Element.push_back(checkSysE4_optA);
//
//	// def steps variables
//	stepsWithoutMinWithoutMax addInfosVarS1_Radius(1, 10, -10, 10);
//	stepsWithoutMinWithoutMax addInfosVarS4_Radius(4, 20, -20, 20);
//
//	std::vector<stepsWithoutMinWithoutMax> addInfosVariable{ addInfosVarS1_Radius,addInfosVarS4_Radius };
//
//	BuildSystemsForCombination buildSysCom_E4(optSystemElement_E4, addInfosVariable, 550.0, buildElement);
//	bool checkDistances = buildSysCom_E4.checkDistances();
//	workBuildSysForCom_E4_Element.push_back(checkDistances);
//	bool checkInteractions = buildSysCom_E4.checkInteractions();
//	workBuildSysForCom_E4_Element.push_back(checkInteractions);
//
//	std::vector<unsigned int> combinationChecker{ 1,8,1,1,18,1,1,1 };
//	bool checkCombinations = buildSysCom_E4.checkCombination_Element(8, combinationChecker);
//	workBuildSysForCom_E4_Element.push_back(checkCombinations);
//
//	std::vector<real>save_allCombinations_Radius_S1{
//		-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,-50.0,
//		-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,-40.0,
//		-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,-30.0,
//		-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,-20.0,
//		20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,
//		30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,30.0,
//		40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,40.0,
//		50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,
//	};
//
//	std::vector<real> save_allCombinatins_Radius_S4{
//
//		-200.0,-180.0,-160.0,-140.0,-120.0,-100.0,-80.0,-60.0,-40.0,40.0,60.0,80.0,100.0,120.0,140.0,160.0,180.0,200.0,
//		-200.0,-180.0,-160.0,-140.0,-120.0,-100.0,-80.0,-60.0,-40.0,40.0,60.0,80.0,100.0,120.0,140.0,160.0,180.0,200.0,
//		-200.0,-180.0,-160.0,-140.0,-120.0,-100.0,-80.0,-60.0,-40.0,40.0,60.0,80.0,100.0,120.0,140.0,160.0,180.0,200.0,
//		-200.0,-180.0,-160.0,-140.0,-120.0,-100.0,-80.0,-60.0,-40.0,40.0,60.0,80.0,100.0,120.0,140.0,160.0,180.0,200.0,
//		-200.0,-180.0,-160.0,-140.0,-120.0,-100.0,-80.0,-60.0,-40.0,40.0,60.0,80.0,100.0,120.0,140.0,160.0,180.0,200.0,
//		-200.0,-180.0,-160.0,-140.0,-120.0,-100.0,-80.0,-60.0,-40.0,40.0,60.0,80.0,100.0,120.0,140.0,160.0,180.0,200.0,
//		-200.0,-180.0,-160.0,-140.0,-120.0,-100.0,-80.0,-60.0,-40.0,40.0,60.0,80.0,100.0,120.0,140.0,160.0,180.0,200.0,
//		-200.0,-180.0,-160.0,-140.0,-120.0,-100.0,-80.0,-60.0,-40.0,40.0,60.0,80.0,100.0,120.0,140.0,160.0,180.0,200.0,
//	};
//
//	bool checkCombinationsSurfacE4_radius = buildSysCom_E4.checkCombiRadiusAtSurface(1, save_allCombinations_Radius_S1, 0.001);
//	workBuildSysForCom_E4_Element.push_back(checkCombinationsSurfacE4_radius);
//	bool checkCombinationsSurface4_radius = buildSysCom_E4.checkCombiRadiusAtSurface(4, save_allCombinatins_Radius_S4, 0.001);
//	workBuildSysForCom_E4_Element.push_back(checkCombinationsSurface4_radius);
//
//
	bool returnChecker_E4 = Math::checkTrueOfVectorElements(workBuildSysForCom_E4_Element);
	return returnChecker_E4;
}