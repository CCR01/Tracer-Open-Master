#include "testSeidelCoefficients.h"
#include "..\..\SurfaceElements\ApertureStopElement.h"
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\PlanElement.h"
#include "..\..\OpticalSystemElement\OpticalSystemElement.h"

#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"

#include "..\..\Analyse\Seidel Coefficients.h"

#include "..\..\LowLevelTracing\Interaction\InteractionRay_LLT.h"

#include "..\..\Glasses\Glasses.h"

// often use
#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

testSeidelCoefficients::testSeidelCoefficients() {}

testSeidelCoefficients::~testSeidelCoefficients() {}

// check methodes seidel coefficients
bool testSeidelCoefficients::checkCalculationOfSeidelCoefficients_superFct()
{
	std::vector<bool> checkCalcSeidel;

	// E0
	bool checkE0 = checkCalculationOfSeidelCoefficients_E0();
	checkCalcSeidel.push_back(checkE0);

	// E1
	bool checkE1 = checkCalculationOfSeidelCoefficients_E1();
	checkCalcSeidel.push_back(checkE1);

	// E2
	bool checkE2 = checkCalculationOfSeidelCoefficients_E2();
	checkCalcSeidel.push_back(checkE2);

	// E3
	bool checkE3 = checkCalculationOfSeidelCoefficients_E3();
	checkCalcSeidel.push_back(checkE3);

	// E4
	bool checkE4 = checkCalculationOfSeidelCoefficients_E4();
	checkCalcSeidel.push_back(checkE4);

	// E5
	bool checkE5 = checkCalculationOfSeidelCoefficients_E5();
	checkCalcSeidel.push_back(checkE5);

	// E6
	bool checkE6 = checkCalculationOfSeidelCoefficients_E6();
	//checkCalcSeidel.push_back(checkE6);

	// E7
	bool checkE7 = checkCalculationOfSeidelCoefficients_E7();
	checkCalcSeidel.push_back(checkE7);

	// E8
	bool checkE8 = checkCalculationOfSeidelCoefficients_E8();
	checkCalcSeidel.push_back(checkE8);

	// E9
	bool checkE9 = checkCalculationOfSeidelCoefficients_E9();
	checkCalcSeidel.push_back(checkE9);

	// E10
	bool checkE10 = checkCalculationOfSeidelCoefficients_E10();
	checkCalcSeidel.push_back(checkE10);

	// E11
	bool checkE11 = checkCalculationOfSeidelCoefficients_E11();
	checkCalcSeidel.push_back(checkE11);

	// E12
	bool checkE12 = checkCalculationOfSeidelCoefficients_E12();
	checkCalcSeidel.push_back(checkE12);

	// E13
	bool checkE13 = checkCalculationOfSeidelCoefficients_E13();
	checkCalcSeidel.push_back(checkE13);

	bool checkSeidel = Math::checkTrueOfVectorElements(checkCalcSeidel);
	return checkSeidel;
}


// check methodes seidel coefficients
bool testSeidelCoefficients::checkCalculationOfSeidelCoefficients_E0()
{
	std::vector<bool> checkCalcSeidel;
	real tolerance_E0 = 0.1;

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr<InteractionRay_LLT> interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// set the wavelength
	Light_LLT Light0_E0;
	Light0_E0.setWavelength(587.6);
	Light0_E0.setIntensity(1.0);
	std::vector<Light_LLT> lichtVecE0W0{ Light0_E0 };

	Light_LLT Light1_E0;
	Light1_E0.setWavelength(656.3);
	Light1_E0.setIntensity(1.0);
	std::vector<Light_LLT> lichtVecE0W1{ Light1_E0 };

	Light_LLT Light2_E0;
	Light2_E0.setWavelength(486.1);
	Light2_E0.setIntensity(1.0);
	std::vector<Light_LLT> lichtVecE0W2{ Light2_E0 };

	std::vector<real> wavelenght_vec{ 587.6,656.3,486.1 };

	real shift = 0.0;

	// surfaces E0
	//ApertureStopElement AperStop0_E0(/* semi height*/999.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere0_E0(/*radius*/ 42.987900, /*semi height*/ 16.5, /*point*/{ 0.0,0.0,shift + 10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSK16_S1());
	SphericalElement Sphere1_E0(/*radius*/ 248.077400, /*semi height*/ 16.5, /*point*/{ 0.0,0.0,shift + 14.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSK16_S1());
	SphericalElement Sphere2_E0(/*radius*/ 38.21035, /*semi height*/ 16.5, /*point*/{ 0.0,0.0,shift + 24.51018 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.get_F4_S1(), /*refractive index B*/glasses.getAir());
	ApertureStopElement AperStop3_E0(/* semi height*/8.675, /*point*/{ 0.0,0.0,shift + 27.01017 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.get_F4_S1());
	SphericalElement Sphere4_E0(/*radius*/ 43.958940, /*semi height*/ 16.5, /*point*/{ 0.0,0.0,shift + 27.01018 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.get_F4_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere5_E0(/*radius*/656.663490, /*semi height*/ 16.3, /*point*/{ 0.0,0.0,shift + 36.87964 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSK16_S1());
	SphericalElement Sphere6_E0(/*radius*/33.507540, /*semi height*/ 16.3, /*point*/{ 0.0,0.0,shift + 41.37964 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSK16_S1());
	PlanElement Plan7_E0(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,shift + 127.86607 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	//surfacePtr Aper0_E0_ptr = AperStop0_E0.clone();
	surfacePtr Sphere0_E0_ptr = Sphere0_E0.clone();
	surfacePtr Sphere1_E0_ptr = Sphere1_E0.clone();
	surfacePtr Sphere2_E0_ptr = Sphere2_E0.clone();
	surfacePtr Aper3_E0_ptr = AperStop3_E0.clone();
	surfacePtr Sphere4_E0_ptr = Sphere4_E0.clone();
	surfacePtr Sphere5_E0_ptr = Sphere5_E0.clone();
	surfacePtr Sphere6_E0_ptr = Sphere6_E0.clone();
	surfacePtr Plan7_E0_ptr = Plan7_E0.clone();

	std::vector<surfacePtr> opticalSystemE0_ptr{ Sphere0_E0_ptr, Sphere1_E0_ptr , Sphere2_E0_ptr, Aper3_E0_ptr, Sphere4_E0_ptr, Sphere5_E0_ptr, Sphere6_E0_ptr, Plan7_E0_ptr };
	std::vector<interaction_ptr> interactionsE0_ptr{ refrac.clone(),refrac.clone(), refrac.clone(), doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };



	//	build optical system
	OpticalSystemElement optSystemElement_E0(opticalSystemE0_ptr, interactionsE0_ptr);

	oftenUse::print(optSystemElement_E0, 587.6);

	// check the start system
	std::vector<real> rms_Zemax{ 7.071 };
	std::vector<real> wave_vec = { 587.6 };
	real tolerance = 0.1;
	//bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_E0, 0.0,0.0, wave_vec, rms_Zemax, tolerance, compareTOM_Zemax::comEqual);
	//checkCalcSeidel.push_back(test);

	LightRayStruct marginalLightRay = oftenUse::findMarginalRay_inf(optSystemElement_E0, 587.6, oftenUse::getDefaultLight());
	LightRayStruct chiefLightRay = oftenUse::findChiefRay_inf(optSystemElement_E0, 587.6, 20.0, oftenUse::getDefaultLight());


	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_E0_marginalRay(/*optical system element*/ optSystemElement_E0, marginalLightRay);
	SequentialRayTracing seqTrace_E0_chiefRay(/*optical system element*/ optSystemElement_E0, chiefLightRay);


	VectorStructR3 checkRayMarginal = seqTrace_E0_marginalRay.getAllInterPointsAtSurface_i_filtered(7).at(0);
	VectorStructR3 testZemaxMarginal{ 0.0, 8.40668069E-3, 127.86607 };
	bool checkMarginalRay = Math::compareTwoVectorStructR3_tolerance(testZemaxMarginal, checkRayMarginal, 0.1);
	checkCalcSeidel.push_back(checkMarginalRay);

	VectorStructR3 checkRayChief = seqTrace_E0_chiefRay.getAllInterPointsAtSurface_i_filtered(7).at(0);
	VectorStructR3 testZemaxCheifRay{ 0.0, 36.797455244, 127.86607 };
	bool checkCheifRay = Math::compareTwoVectorStructR3_tolerance(checkRayChief, testZemaxCheifRay, 0.1);
	checkCalcSeidel.push_back(checkCheifRay);

	// test -> build marginal and chief ray from zemax	
	VectorStructR3 originMarginalRay = { 0.0,10.837748570,-1.0 };
	VectorStructR3 directionMarginalRay = { 0.0,0.0,1.0 };
	real curRefIndex = 1.0;
	Ray_LLT marginalRay(originMarginalRay, directionMarginalRay, curRefIndex);
	Light_LLT light = oftenUse::getDefaultLight();
	LightRayStruct lightRayMarginalZ(light, marginalRay, true);

	VectorStructR3 originChiefRay = { 0.0, -11.091981935, 0.0 };
	VectorStructR3 directionChiefRay = { 0.0, 0.36397023, 1.0 };
	Ray_LLT chiefRay(originChiefRay, directionChiefRay, curRefIndex);
	LightRayStruct lightRayChiefZ(light, chiefRay, true);
	// ***


	SeidelCoefficients SeidelCoefE0(/*optical system element*/optSystemElement_E0, /*chief Ray*/ lightRayChiefZ, /*marginal ray*/ lightRayMarginalZ, wavelenght_vec, 4, 99.9953, -4.0439, true, objectPoint_inf_obj::inf);


	bool checkS1Sum_E0 = std::abs(SeidelCoefE0.getS1sum() - 0.011464) < tolerance_E0;
	checkCalcSeidel.push_back(checkS1Sum_E0);
	bool checkS2Sum_E0 = std::abs(SeidelCoefE0.getS2sum() - 0.010903) < tolerance_E0;
	checkCalcSeidel.push_back(checkS2Sum_E0);
	bool checkS3Sum_E0 = std::abs(SeidelCoefE0.getS3sum() - -0.027276) < tolerance_E0;
	checkCalcSeidel.push_back(checkS3Sum_E0);
	bool checkS4Sum_E0 = std::abs(SeidelCoefE0.getS4sum() - 0.062141) < tolerance_E0;
	checkCalcSeidel.push_back(checkS4Sum_E0);
	bool checkS5Sum_E0 = std::abs(SeidelCoefE0.getS5sum() - -0.060275) < tolerance_E0;
	checkCalcSeidel.push_back(checkS5Sum_E0);
	bool checkS6C1Sum_E0 = std::abs(SeidelCoefE0.getS6C1sum() - -0.000970) < tolerance_E0;
	checkCalcSeidel.push_back(checkS6C1Sum_E0);
	bool checkS7C2Sum_E0 = std::abs(SeidelCoefE0.getS7C2sum() - -0.000920) < tolerance_E0;
	checkCalcSeidel.push_back(checkS7C2Sum_E0);

	bool checkSeidel = Math::checkTrueOfVectorElements(checkCalcSeidel);
	return checkSeidel;
}

// E1
bool testSeidelCoefficients::checkCalculationOfSeidelCoefficients_E1()
{
	std::vector<bool> checkCalcSeidel;

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr<InteractionRay_LLT> interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	std::vector<real> wavelenght_vec{ 550.0, 400.0, 600.0 };


	// surfaces E1
	ApertureStopElement S0(/* semi height*/2.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S1(/*radius*/ 50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 70.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNF2_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNF2_S1());
	SphericalElement S4(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLASF41_S1());
	SphericalElement S5(/*radius*/40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSF5_S1(), /*refractive index B*/glasses.getNLASF41_S1());
	SphericalElement S6(/*radius*/20.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	PlanElement S7(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,60.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());


	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr };
	std::vector<interaction_ptr> interactions_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	std::vector<real> rms_Zemax{ 228.420, 345.011 };
	std::vector<VectorStructR3> fieldPoints = { {0.0,0.0,0.0}, {0.0,1.0,0.0} };
	std::vector<real> wave_vec = { 550.0, 400.0, 600.0 };
	real tolerance = 0.1;
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, fieldPoints, wave_vec, rms_Zemax, tolerance, compareTOM_Zemax::comEqual);
	checkCalcSeidel.push_back(test);

	SeidelCoefficients seidelCoef;
	VectorStructR3 maxStartPoint_Y = { 0.0, 1.0, 0.0 };
	Light_LLT light = oftenUse::getDefaultLight();
	seidelCoef.calcSeidelCoef_superFuction(optSystemElement, wave_vec, light, maxStartPoint_Y);

	real S1_sum = seidelCoef.getS1sum();
	real S2_sum = seidelCoef.getS2sum();
	real S3_sum = seidelCoef.getS3sum();
	real S4_sum = seidelCoef.getS4sum();
	real S5_sum = seidelCoef.getS5sum();
	real S6_sum = seidelCoef.getS6C1sum();
	real S7_sum = seidelCoef.getS7C2sum();


	real S1_sum_ref = 0.200735;
	real S2_sum_ref = -0.066140;
	real S3_sum_ref = 0.023110;
	real S4_sum_ref = 0.002101;
	real S5_sum_ref = -0.009139;
	real S6_sum_ref = -0.075527;
	real S7_sum_ref = 0.025313;

	real toleranceSeidel = 0.1;

	bool checkS1Sum = Math::compareTwoNumbers_tolerance(S1_sum, S1_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS1Sum);
	bool checkS2Sum = Math::compareTwoNumbers_tolerance(S2_sum, S2_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS2Sum);
	bool checkS3Sum = Math::compareTwoNumbers_tolerance(S3_sum, S3_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS3Sum);
	bool checkS4Sum = Math::compareTwoNumbers_tolerance(S4_sum, S4_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS4Sum);
	bool checkS5Sum = Math::compareTwoNumbers_tolerance(S5_sum, S5_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS5Sum);
	bool checkS6Sum = Math::compareTwoNumbers_tolerance(S6_sum, S6_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS6Sum);
	bool checkS7Sum = Math::compareTwoNumbers_tolerance(S7_sum, S7_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS7Sum);

	bool checkSeidel = Math::checkTrueOfVectorElements(checkCalcSeidel);
	return checkSeidel;

}

// E2
bool testSeidelCoefficients::checkCalculationOfSeidelCoefficients_E2()
{
	std::vector<bool> checkCalcSeidel;

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr<InteractionRay_LLT> interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// surfaces E2
	ApertureStopElement S0(/* semi height*/2.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S1(/*radius*/ 50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 70.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNF2_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNF2_S1());
	SphericalElement S4(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLASF41_S1());
	SphericalElement S5(/*radius*/40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSF5_S1(), /*refractive index B*/glasses.getNLASF41_S1());
	SphericalElement S6(/*radius*/20.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	PlanElement S7(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,45.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());


	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr };
	std::vector<interaction_ptr> interactions_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	real maxIncidenceAngel_Y = 10.0;

	std::vector<real> rms_Zemax{ 271.613 };
	std::vector<real> wave_vec = { 550.0, 400.0, 600.0 };
	Light_LLT light = oftenUse::getDefaultLight();
	real tolerance = 0.1;
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, 0.0, maxIncidenceAngel_Y, wave_vec, rms_Zemax, tolerance, compareTOM_Zemax::comEqual);
	checkCalcSeidel.push_back(test);

	SeidelCoefficients seidelCoef;
	seidelCoef.calcSeidelCoef_superFuction(optSystemElement, wave_vec, light, maxIncidenceAngel_Y);


	real S1_sum = seidelCoef.getS1sum();
	real S2_sum = seidelCoef.getS2sum();
	real S3_sum = seidelCoef.getS3sum();
	real S4_sum = seidelCoef.getS4sum();
	real S5_sum = seidelCoef.getS5sum();
	real S6_sum = seidelCoef.getS6C1sum();
	real S7_sum = seidelCoef.getS7C2sum();


	real S1_sum_ref = 0.004929;
	real S2_sum_ref = 0.003713;
	real S3_sum_ref = 0.003859;
	real S4_sum_ref = 0.006533;
	real S5_sum_ref = 0.020006;
	real S6_sum_ref = -0.007402;
	real S7_sum_ref = -0.015418;

	real toleranceSeidel = 0.1;

	bool checkS1Sum = Math::compareTwoNumbers_tolerance(S1_sum, S1_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS1Sum);
	bool checkS2Sum = Math::compareTwoNumbers_tolerance(S2_sum, S2_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS2Sum);
	bool checkS3Sum = Math::compareTwoNumbers_tolerance(S3_sum, S3_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS3Sum);
	bool checkS4Sum = Math::compareTwoNumbers_tolerance(S4_sum, S4_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS4Sum);
	bool checkS5Sum = Math::compareTwoNumbers_tolerance(S5_sum, S5_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS5Sum);
	bool checkS6Sum = Math::compareTwoNumbers_tolerance(S6_sum, S6_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS6Sum);
	bool checkS7Sum = Math::compareTwoNumbers_tolerance(S7_sum, S7_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS7Sum);

	bool checkSeidel = Math::checkTrueOfVectorElements(checkCalcSeidel);
	return checkSeidel;
}

// E3
bool testSeidelCoefficients::checkCalculationOfSeidelCoefficients_E3()
{
	std::vector<bool> checkCalcSeidel;

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr<InteractionRay_LLT> interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// surfaces E3
	ApertureStopElement S0(/* semi height*/2.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S1(/*radius*/ 60.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBASF64_S1());
	SphericalElement S2(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSF5_S1(), /*refractive index B*/glasses.getNBASF64_S1());
	SphericalElement S3(/*radius*/ 30.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S4(/*radius*/ 100.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLASF41_S1());
	SphericalElement S5(/*radius*/50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getNLASF41_S1());
	SphericalElement S6(/*radius*/50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S7(/*radius*/90.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF10_S1());
	SphericalElement S8(/*radius*/80.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNSF10_S1(), /*refractive index B*/glasses.getNSF66_S1());
	SphericalElement S9(/*radius*/70.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNLAF36_S1(), /*refractive index B*/glasses.getNSF66_S1());
	SphericalElement S10(/*radius*/50.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAF36_S1());
	PlanElement S11(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,65.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());


	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();
	surfacePtr S11_ptr = S11.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr };
	std::vector<interaction_ptr> interactions_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	std::vector<real> incidenceAngel_X_vec = { 0.0, 0.0 };
	std::vector<real> incidenceAngel_Y_vec = { 0.0, 15.0 };

	// wave vec
	std::vector<real> wave_vec = { 550.0, 400.0, 600.0 };
	// show optical system
	oftenUse::print(optSystemElement, wave_vec[0]);

	std::vector<real> rms_Zemax{ 645.459, 694.264 };

	Light_LLT light = oftenUse::getDefaultLight();
	real tolerance = 0.1;
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, incidenceAngel_X_vec, incidenceAngel_Y_vec, wave_vec, rms_Zemax, tolerance, compareTOM_Zemax::comEqual);
	checkCalcSeidel.push_back(test);

	SeidelCoefficients seidelCoef;
	seidelCoef.calcSeidelCoef_superFuction(optSystemElement, wave_vec, light, incidenceAngel_Y_vec[1]);


	real S1_sum = seidelCoef.getS1sum();
	real S2_sum = seidelCoef.getS2sum();
	real S3_sum = seidelCoef.getS3sum();
	real S4_sum = seidelCoef.getS4sum();
	real S5_sum = seidelCoef.getS5sum();
	real S6_sum = seidelCoef.getS6C1sum();
	real S7_sum = seidelCoef.getS7C2sum();


	real S1_sum_ref = 0.002338;
	real S2_sum_ref = -0.000209;
	real S3_sum_ref = -0.002287;
	real S4_sum_ref = 0.014130;
	real S5_sum_ref = 0.036849;
	real S6_sum_ref = -0.005058;
	real S7_sum_ref = -0.017265;

	real toleranceSeidel = 0.001;

	bool checkS1Sum = Math::compareTwoNumbers_tolerance(S1_sum, S1_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS1Sum);
	bool checkS2Sum = Math::compareTwoNumbers_tolerance(S2_sum, S2_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS2Sum);
	bool checkS3Sum = Math::compareTwoNumbers_tolerance(S3_sum, S3_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS3Sum);
	bool checkS4Sum = Math::compareTwoNumbers_tolerance(S4_sum, S4_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS4Sum);
	bool checkS5Sum = Math::compareTwoNumbers_tolerance(S5_sum, S5_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS5Sum);
	bool checkS6Sum = Math::compareTwoNumbers_tolerance(S6_sum, S6_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS6Sum);
	bool checkS7Sum = Math::compareTwoNumbers_tolerance(S7_sum, S7_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS7Sum);

	bool checkSeidel = Math::checkTrueOfVectorElements(checkCalcSeidel);
	return checkSeidel;
}

// E4
bool testSeidelCoefficients::checkCalculationOfSeidelCoefficients_E4()
{
	std::vector<bool> checkCalcSeidel;

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr<InteractionRay_LLT> interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// surfaces E4
	SphericalElement S0(/*radius*/ 60.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBASF64_S1());
	SphericalElement S1(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSF5_S1(), /*refractive index B*/glasses.getNBASF64_S1());
	SphericalElement S2(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	ApertureStopElement S3(/* semi height*/ 1.5, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S4(/*radius*/ 100.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLASF41_S1());
	SphericalElement S5(/*radius*/50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getNLASF41_S1());
	SphericalElement S6(/*radius*/50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	PlanElement S7(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,40.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());


	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();


	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr };
	std::vector<interaction_ptr> interactions_ptr{ refrac.clone(),refrac.clone(), refrac.clone(), doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	std::vector<real> incidenceAngel_X_vec = { 0.0 };
	std::vector<real> incidenceAngel_Y_vec = { 0.0 };

	// wave vec
	std::vector<real> wave_vec = { 550.0, 400.0, 600.0 };
	// show optical system
	oftenUse::print(optSystemElement, wave_vec[0]);

	std::vector<real> rms_Zemax{ 172.077 };

	Light_LLT light = oftenUse::getDefaultLight();
	real tolerance = 0.1;
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, incidenceAngel_X_vec, incidenceAngel_Y_vec, wave_vec, rms_Zemax, tolerance, compareTOM_Zemax::comEqual);
	checkCalcSeidel.push_back(test);

	SeidelCoefficients seidelCoef;
	seidelCoef.calcSeidelCoef_superFuction(optSystemElement, wave_vec, light, 15.0);


	real S1_sum = seidelCoef.getS1sum();
	real S2_sum = seidelCoef.getS2sum();
	real S3_sum = seidelCoef.getS3sum();
	real S4_sum = seidelCoef.getS4sum();
	real S5_sum = seidelCoef.getS5sum();
	real S6_sum = seidelCoef.getS6C1sum();
	real S7_sum = seidelCoef.getS7C2sum();


	real S1_sum_ref = 0.002126;
	real S2_sum_ref = -0.005536;
	real S3_sum_ref = 0.013991;
	real S4_sum_ref = 0.009582;
	real S5_sum_ref = -0.025454;
	real S6_sum_ref = -0.006679;
	real S7_sum_ref = 0.001788;

	real toleranceSeidel = 0.001;

	bool checkS1Sum = Math::compareTwoNumbers_tolerance(S1_sum, S1_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS1Sum);
	bool checkS2Sum = Math::compareTwoNumbers_tolerance(S2_sum, S2_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS2Sum);
	bool checkS3Sum = Math::compareTwoNumbers_tolerance(S3_sum, S3_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS3Sum);
	bool checkS4Sum = Math::compareTwoNumbers_tolerance(S4_sum, S4_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS4Sum);
	bool checkS5Sum = Math::compareTwoNumbers_tolerance(S5_sum, S5_sum_ref, toleranceSeidel + 0.01);
	checkCalcSeidel.push_back(checkS5Sum);
	bool checkS6Sum = Math::compareTwoNumbers_tolerance(S6_sum, S6_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS6Sum);
	bool checkS7Sum = Math::compareTwoNumbers_tolerance(S7_sum, S7_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS7Sum);

	bool checkSeidel = Math::checkTrueOfVectorElements(checkCalcSeidel);
	return checkSeidel;
}
// E5
bool testSeidelCoefficients::checkCalculationOfSeidelCoefficients_E5()
{
	std::vector<bool> checkCalcSeidel;

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr<InteractionRay_LLT> interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// surfaces E5
	SphericalElement S0(/*radius*/ 200.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNBASF64_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement S1(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSF5_S1(), /*refractive index B*/glasses.getNBASF64_S1());
	SphericalElement S2(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	ApertureStopElement S3(/* semi height*/ 1.5, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S4(/*radius*/ 100.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLASF41_S1());
	SphericalElement S5(/*radius*/50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getNLASF41_S1());
	SphericalElement S6(/*radius*/50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S7(/*radius*/80.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S8(/*radius*/80.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	PlanElement S9(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,50.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());


	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ refrac.clone(),refrac.clone(), refrac.clone(), doNothing.clone(), refrac.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	std::vector<real> incidenceAngel_X_vec = { 0.0 };
	std::vector<real> incidenceAngel_Y_vec = { 0.0 };

	// wave vec
	std::vector<real> wave_vec = { 400.0, 550.0, 600.0 };
	// show optical system
	oftenUse::print(optSystemElement, wave_vec[0]);

	std::vector<real> rms_Zemax{ 103.641 };

	Light_LLT light = oftenUse::getDefaultLight();
	real tolerance = 0.1;
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, incidenceAngel_X_vec, incidenceAngel_Y_vec, wave_vec, rms_Zemax, tolerance, compareTOM_Zemax::comEqual);
	checkCalcSeidel.push_back(test);

	SeidelCoefficients seidelCoef;
	seidelCoef.calcSeidelCoef_superFuction(optSystemElement, wave_vec, light, 15.0);


	real S1_sum = seidelCoef.getS1sum();
	real S2_sum = seidelCoef.getS2sum();
	real S3_sum = seidelCoef.getS3sum();
	real S4_sum = seidelCoef.getS4sum();
	real S5_sum = seidelCoef.getS5sum();
	real S6_sum = seidelCoef.getS6C1sum();
	real S7_sum = seidelCoef.getS7C2sum();


	real S1_sum_ref = 0.000954;
	real S2_sum_ref = -0.002331;
	real S3_sum_ref = 0.004190;
	real S4_sum_ref = 0.006691;
	real S5_sum_ref = 0.008671;
	real S6_sum_ref = -0.004281;
	real S7_sum_ref = -0.003239;

	real toleranceSeidel = 0.001;

	bool checkS1Sum = Math::compareTwoNumbers_tolerance(S1_sum, S1_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS1Sum);
	bool checkS2Sum = Math::compareTwoNumbers_tolerance(S2_sum, S2_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS2Sum);
	bool checkS3Sum = Math::compareTwoNumbers_tolerance(S3_sum, S3_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS3Sum);
	bool checkS4Sum = Math::compareTwoNumbers_tolerance(S4_sum, S4_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS4Sum);
	bool checkS5Sum = Math::compareTwoNumbers_tolerance(S5_sum, S5_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS5Sum);
	bool checkS6Sum = Math::compareTwoNumbers_tolerance(S6_sum, S6_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS6Sum);
	bool checkS7Sum = Math::compareTwoNumbers_tolerance(S7_sum, S7_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS7Sum);

	bool checkSeidel = Math::checkTrueOfVectorElements(checkCalcSeidel);
	return checkSeidel;
}
// E6
bool testSeidelCoefficients::checkCalculationOfSeidelCoefficients_E6()
{
	std::vector<bool> checkCalcSeidel;

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr<InteractionRay_LLT> interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// surfaces E6
	SphericalElement S0(/*radius*/ 100.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBASF64_S1());
	SphericalElement S1(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNSF5_S1(), /*refractive index B*/glasses.getNBASF64_S1());
	SphericalElement S2(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	ApertureStopElement S3(/* semi height*/ 1.5, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S4(/*radius*/ 100.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNLASF41_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement S5(/*radius*/50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getNLASF41_S1());
	SphericalElement S6(/*radius*/50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S7(/*radius*/50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement S8(/*radius*/50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getAir());
	PlanElement S9(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,50.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());


	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ refrac.clone(),refrac.clone(), refrac.clone(), doNothing.clone(), refrac.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	std::vector<real> incidenceAngel_X_vec = { 0.0 };
	std::vector<real> incidenceAngel_Y_vec = { 0.0 };

	// wave vec
	std::vector<real> wave_vec = { 600.0, 550.0, 750.0 };
	// show optical system
	oftenUse::print(optSystemElement, wave_vec[0]);

	std::vector<real> rms_Zemax{ 161.201 };

	Light_LLT light = oftenUse::getDefaultLight();
	real tolerance = 0.1;
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, incidenceAngel_X_vec, incidenceAngel_Y_vec, wave_vec, rms_Zemax, tolerance, compareTOM_Zemax::comEqual);
	checkCalcSeidel.push_back(test);

	SeidelCoefficients seidelCoef;
	seidelCoef.calcSeidelCoef_superFuction(optSystemElement, wave_vec, light, 13.0);


	real S1_sum = seidelCoef.getS1sum();
	real S2_sum = seidelCoef.getS2sum();
	real S3_sum = seidelCoef.getS3sum();
	real S4_sum = seidelCoef.getS4sum();
	real S5_sum = seidelCoef.getS5sum();
	real S6_sum = seidelCoef.getS6C1sum();
	real S7_sum = seidelCoef.getS7C2sum();


	real S1_sum_ref = 0.001090;
	real S2_sum_ref = -0.003013;
	real S3_sum_ref = 0.009969;
	real S4_sum_ref = 0.001594;
	real S5_sum_ref = -0.024198;
	real S6_sum_ref = -0.001889;
	real S7_sum_ref = 0.001141;

	real toleranceSeidel = 0.001;

	bool checkS1Sum = Math::compareTwoNumbers_tolerance(S1_sum, S1_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS1Sum);
	bool checkS2Sum = Math::compareTwoNumbers_tolerance(S2_sum, S2_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS2Sum);
	bool checkS3Sum = Math::compareTwoNumbers_tolerance(S3_sum, S3_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS3Sum);
	bool checkS4Sum = Math::compareTwoNumbers_tolerance(S4_sum, S4_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS4Sum);
	bool checkS5Sum = Math::compareTwoNumbers_tolerance(S5_sum, S5_sum_ref, toleranceSeidel + 0.01);
	checkCalcSeidel.push_back(checkS5Sum);
	bool checkS6Sum = Math::compareTwoNumbers_tolerance(S6_sum, S6_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS6Sum);
	bool checkS7Sum = Math::compareTwoNumbers_tolerance(S7_sum, S7_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS7Sum);

	bool checkSeidel = Math::checkTrueOfVectorElements(checkCalcSeidel);
	return checkSeidel;
}
// E7
bool testSeidelCoefficients::checkCalculationOfSeidelCoefficients_E7()
{
	std::vector<bool> checkCalcSeidel;

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr<InteractionRay_LLT> interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// surfaces E7
	SphericalElement S0(/*radius*/ 70.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBASF64_S1());
	SphericalElement S1(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNSF5_S1(), /*refractive index B*/glasses.getNBASF64_S1());
	SphericalElement S2(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S3(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement S4(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	ApertureStopElement S5(/* semi height*/ 1.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S6(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement S7(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getAir());
	PlanElement S8(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,45.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());


	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();


	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr };
	std::vector<interaction_ptr> interactions_ptr{ refrac.clone(),refrac.clone(), refrac.clone(),  refrac.clone(),refrac.clone(), doNothing.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	std::vector<real> incidenceAngel_X_vec = { 0.0 };
	std::vector<real> incidenceAngel_Y_vec = { 0.0 };

	// wave vec
	std::vector<real> wave_vec = { 500.0, 400.0, 450.0 };
	// show optical system
	oftenUse::print(optSystemElement, wave_vec[0]);

	std::vector<real> rms_Zemax{ 217.102 };

	Light_LLT light = oftenUse::getDefaultLight();
	real tolerance = 0.1;
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, incidenceAngel_X_vec, incidenceAngel_Y_vec, wave_vec, rms_Zemax, tolerance, compareTOM_Zemax::comEqual);
	checkCalcSeidel.push_back(test);

	SeidelCoefficients seidelCoef;
	seidelCoef.calcSeidelCoef_superFuction(optSystemElement, wave_vec, light, 5.0);


	real S1_sum = seidelCoef.getS1sum();
	real S2_sum = seidelCoef.getS2sum();
	real S3_sum = seidelCoef.getS3sum();
	real S4_sum = seidelCoef.getS4sum();
	real S5_sum = seidelCoef.getS5sum();
	real S6_sum = seidelCoef.getS6C1sum();
	real S7_sum = seidelCoef.getS7C2sum();


	real S1_sum_ref = 0.001077;
	real S2_sum_ref = -0.002182;
	real S3_sum_ref = 0.004790;
	real S4_sum_ref = 0.000159;
	real S5_sum_ref = -0.010774;
	real S6_sum_ref = -0.003203;
	real S7_sum_ref = 0.004240;

	real toleranceSeidel = 0.001;

	bool checkS1Sum = Math::compareTwoNumbers_tolerance(S1_sum, S1_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS1Sum);
	bool checkS2Sum = Math::compareTwoNumbers_tolerance(S2_sum, S2_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS2Sum);
	bool checkS3Sum = Math::compareTwoNumbers_tolerance(S3_sum, S3_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS3Sum);
	bool checkS4Sum = Math::compareTwoNumbers_tolerance(S4_sum, S4_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS4Sum);
	bool checkS5Sum = Math::compareTwoNumbers_tolerance(S5_sum, S5_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS5Sum);
	bool checkS6Sum = Math::compareTwoNumbers_tolerance(S6_sum, S6_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS6Sum);
	bool checkS7Sum = Math::compareTwoNumbers_tolerance(S7_sum, S7_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS7Sum);

	bool checkSeidel = Math::checkTrueOfVectorElements(checkCalcSeidel);
	return checkSeidel;
}
// E8
bool testSeidelCoefficients::checkCalculationOfSeidelCoefficients_E8()
{
	std::vector<bool> checkCalcSeidel;

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr<InteractionRay_LLT> interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// surfaces E8
	SphericalElement S0(/*radius*/ 80.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNSF5_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement S1(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S2(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement S3(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	ApertureStopElement S4(/* semi height*/ 3.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S5(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement S6(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement S7(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S8(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S9(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF10_S1());
	SphericalElement S10(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF10_S1());
	PlanElement S11(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());


	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();
	surfacePtr S11_ptr = S11.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr };
	std::vector<interaction_ptr> interactions_ptr{ refrac.clone(), refrac.clone(), refrac.clone(),  refrac.clone(), doNothing.clone(), refrac.clone(),  refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),  absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	std::vector<real> incidenceAngel_X_vec = { 0.0 };
	std::vector<real> incidenceAngel_Y_vec = { 0.0 };

	// wave vec
	std::vector<real> wave_vec = { 500.0, 400.0, 450.0 };
	// show optical system
	oftenUse::print(optSystemElement, wave_vec[0]);

	std::vector<real> rms_Zemax{ 103.295 };

	Light_LLT light = oftenUse::getDefaultLight();
	real tolerance = 0.1;
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, incidenceAngel_X_vec, incidenceAngel_Y_vec, wave_vec, rms_Zemax, tolerance, compareTOM_Zemax::comEqual);
	checkCalcSeidel.push_back(test);

	SeidelCoefficients seidelCoef;
	seidelCoef.calcSeidelCoef_superFuction(optSystemElement, wave_vec, light, /*max incidence angele*/ 10.0);


	real S1_sum = seidelCoef.getS1sum();
	real S2_sum = seidelCoef.getS2sum();
	real S3_sum = seidelCoef.getS3sum();
	real S4_sum = seidelCoef.getS4sum();
	real S5_sum = seidelCoef.getS5sum();
	real S6_sum = seidelCoef.getS6C1sum();
	real S7_sum = seidelCoef.getS7C2sum();


	real S1_sum_ref = 0.014754;
	real S2_sum_ref = 0.003915;
	real S3_sum_ref = 0.007614;
	real S4_sum_ref = 0.009181;
	real S5_sum_ref = 0.022842;
	real S6_sum_ref = -0.022091;
	real S7_sum_ref = -0.024476;

	real toleranceSeidel = 0.001;

	bool checkS1Sum = Math::compareTwoNumbers_tolerance(S1_sum, S1_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS1Sum);
	bool checkS2Sum = Math::compareTwoNumbers_tolerance(S2_sum, S2_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS2Sum);
	bool checkS3Sum = Math::compareTwoNumbers_tolerance(S3_sum, S3_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS3Sum);
	bool checkS4Sum = Math::compareTwoNumbers_tolerance(S4_sum, S4_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS4Sum);
	bool checkS5Sum = Math::compareTwoNumbers_tolerance(S5_sum, S5_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS5Sum);
	bool checkS6Sum = Math::compareTwoNumbers_tolerance(S6_sum, S6_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS6Sum);
	bool checkS7Sum = Math::compareTwoNumbers_tolerance(S7_sum, S7_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS7Sum);

	bool checkSeidel = Math::checkTrueOfVectorElements(checkCalcSeidel);
	return checkSeidel;
}
// E9
bool testSeidelCoefficients::checkCalculationOfSeidelCoefficients_E9()
{
	std::vector<bool> checkCalcSeidel;

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr<InteractionRay_LLT> interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// surfaces E9
	SphericalElement S0(/*radius*/ 80.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S1(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S2(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement S3(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	ApertureStopElement S4(/* semi height*/ 3.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S5(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement S6(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement S7(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S8(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S9(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF10_S1());
	SphericalElement S10(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF10_S1());
	PlanElement S11(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,90.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());


	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();
	surfacePtr S11_ptr = S11.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr };
	std::vector<interaction_ptr> interactions_ptr{ refrac.clone(), refrac.clone(), refrac.clone(),  refrac.clone(), doNothing.clone(), refrac.clone(),  refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),  absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	std::vector<real> rms_Zemax{ 152.569, 256.082 };
	std::vector<VectorStructR3> fieldPoints = { {0.0,0.0,0.0}, {0.0,2.0,0.0} };
	std::vector<real> wave_vec = { 500.0, 400.0, 450.0 };
	// show optical system
	oftenUse::print(optSystemElement, wave_vec[0]);
	real tolerance = 0.1;
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, fieldPoints, wave_vec, rms_Zemax, tolerance, compareTOM_Zemax::comEqual);
	checkCalcSeidel.push_back(test);

	SeidelCoefficients seidelCoef;
	VectorStructR3 maxStartPoint_Y = { 0.0, 2.0, 0.0 };
	Light_LLT light = oftenUse::getDefaultLight();
	seidelCoef.calcSeidelCoef_superFuction(optSystemElement, wave_vec, light, maxStartPoint_Y);


	real S1_sum = seidelCoef.getS1sum();
	real S2_sum = seidelCoef.getS2sum();
	real S3_sum = seidelCoef.getS3sum();
	real S4_sum = seidelCoef.getS4sum();
	real S5_sum = seidelCoef.getS5sum();
	real S6_sum = seidelCoef.getS6C1sum();
	real S7_sum = seidelCoef.getS7C2sum();


	real S1_sum_ref = 0.077818;
	real S2_sum_ref = -0.023420;
	real S3_sum_ref = 0.009095;
	real S4_sum_ref = 0.002812;
	real S5_sum_ref = -0.005075;
	real S6_sum_ref = -0.067345;
	real S7_sum_ref = 0.020257;

	real toleranceSeidel = 0.001;

	bool checkS1Sum = Math::compareTwoNumbers_tolerance(S1_sum, S1_sum_ref, toleranceSeidel + 0.1);
	checkCalcSeidel.push_back(checkS1Sum);
	bool checkS2Sum = Math::compareTwoNumbers_tolerance(S2_sum, S2_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS2Sum);
	bool checkS3Sum = Math::compareTwoNumbers_tolerance(S3_sum, S3_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS3Sum);
	bool checkS4Sum = Math::compareTwoNumbers_tolerance(S4_sum, S4_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS4Sum);
	bool checkS5Sum = Math::compareTwoNumbers_tolerance(S5_sum, S5_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS5Sum);
	bool checkS6Sum = Math::compareTwoNumbers_tolerance(S6_sum, S6_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS6Sum);
	bool checkS7Sum = Math::compareTwoNumbers_tolerance(S7_sum, S7_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS7Sum);

	bool checkSeidel = Math::checkTrueOfVectorElements(checkCalcSeidel);
	return checkSeidel;
}
// E10
bool testSeidelCoefficients::checkCalculationOfSeidelCoefficients_E10()
{
	std::vector<bool> checkCalcSeidel;

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr<InteractionRay_LLT> interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// surfaces E10
	SphericalElement S0(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S1(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNSF10_S1(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S2(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getNSF10_S1());
	SphericalElement S3(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	ApertureStopElement S4(/* semi height*/ 3.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S5(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getNSF10_S1());
	SphericalElement S7(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF10_S1());
	PlanElement S8(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,55.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());


	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr };
	std::vector<interaction_ptr> interactions_ptr{ refrac.clone(), refrac.clone(), refrac.clone(),  refrac.clone(), doNothing.clone(), refrac.clone(),  refrac.clone(), refrac.clone(),  absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	std::vector<real> rms_Zemax{ 2519.64, 2509.43 };
	std::vector<VectorStructR3> fieldPoints = { {0.0,0.0,0.0}, {0.0,2.0,0.0} };
	std::vector<real> wave_vec = { 500.0, 400.0, 450.0 };
	// show optical system
	oftenUse::print(optSystemElement, wave_vec[0]);
	real tolerance = 0.1;
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, fieldPoints, wave_vec, rms_Zemax, tolerance, compareTOM_Zemax::comEqual);
	checkCalcSeidel.push_back(test);

	SeidelCoefficients seidelCoef;
	VectorStructR3 maxStartPoint_Y = { 0.0, 2.0, 0.0 };
	Light_LLT light = oftenUse::getDefaultLight();
	seidelCoef.calcSeidelCoef_superFuction(optSystemElement, wave_vec, light, maxStartPoint_Y);


	real S1_sum = seidelCoef.getS1sum();
	real S2_sum = seidelCoef.getS2sum();
	real S3_sum = seidelCoef.getS3sum();
	real S4_sum = seidelCoef.getS4sum();
	real S5_sum = seidelCoef.getS5sum();
	real S6_sum = seidelCoef.getS6C1sum();
	real S7_sum = seidelCoef.getS7C2sum();


	real S1_sum_ref = 0.014380;
	real S2_sum_ref = -0.004571;
	real S3_sum_ref = 0.002476;
	real S4_sum_ref = 0.002944;
	real S5_sum_ref = -0.000749;
	real S6_sum_ref = -0.025041;
	real S7_sum_ref = 0.001984;

	real toleranceSeidel = 0.001;

	bool checkS1Sum = Math::compareTwoNumbers_tolerance(S1_sum, S1_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS1Sum);
	bool checkS2Sum = Math::compareTwoNumbers_tolerance(S2_sum, S2_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS2Sum);
	bool checkS3Sum = Math::compareTwoNumbers_tolerance(S3_sum, S3_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS3Sum);
	bool checkS4Sum = Math::compareTwoNumbers_tolerance(S4_sum, S4_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS4Sum);
	bool checkS5Sum = Math::compareTwoNumbers_tolerance(S5_sum, S5_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS5Sum);
	bool checkS6Sum = Math::compareTwoNumbers_tolerance(S6_sum, S6_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS6Sum);
	bool checkS7Sum = Math::compareTwoNumbers_tolerance(S7_sum, S7_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS7Sum);

	bool checkSeidel = Math::checkTrueOfVectorElements(checkCalcSeidel);
	return checkSeidel;
}
// E11
bool testSeidelCoefficients::checkCalculationOfSeidelCoefficients_E11()
{
	std::vector<bool> checkCalcSeidel;

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr<InteractionRay_LLT> interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// surfaces E11
	SphericalElement S0(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S1(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNSF10_S1(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S2(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getNSF10_S1());
	SphericalElement S3(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S4(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getNSF10_S1());
	SphericalElement S6(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF10_S1());
	ApertureStopElement S7(/* semi height*/ 2.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S8(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S9(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S10(/*radius*/ 25.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S11(/*radius*/ 25.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	PlanElement S12(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());


	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();
	surfacePtr S11_ptr = S11.clone();
	surfacePtr S12_ptr = S12.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ refrac.clone(), refrac.clone(), refrac.clone(),  refrac.clone(),  refrac.clone(),  refrac.clone(), refrac.clone(), doNothing.clone(), refrac.clone(), refrac.clone() ,refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	std::vector<real> rms_Zemax{ 213.715, 205.326 };
	std::vector<VectorStructR3> fieldPoints = { {0.0,0.0,0.0}, {0.0,2.0,0.0} };
	std::vector<real> wave_vec = { 500.0, 400.0, 450.0 };
	// show optical system
	oftenUse::print(optSystemElement, wave_vec[0]);
	real tolerance = 0.1;
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, fieldPoints, wave_vec, rms_Zemax, tolerance, compareTOM_Zemax::comEqual);
	checkCalcSeidel.push_back(test);

	SeidelCoefficients seidelCoef;
	VectorStructR3 maxStartPoint_Y = { 0.0, 2.0, 0.0 };
	Light_LLT light = oftenUse::getDefaultLight();
	seidelCoef.calcSeidelCoef_superFuction(optSystemElement, wave_vec, light, maxStartPoint_Y);


	real S1_sum = seidelCoef.getS1sum();
	real S2_sum = seidelCoef.getS2sum();
	real S3_sum = seidelCoef.getS3sum();
	real S4_sum = seidelCoef.getS4sum();
	real S5_sum = seidelCoef.getS5sum();
	real S6_sum = seidelCoef.getS6C1sum();
	real S7_sum = seidelCoef.getS7C2sum();


	real S1_sum_ref = 0.007383;
	real S2_sum_ref = -0.000363;
	real S3_sum_ref = 0.000168;
	real S4_sum_ref = 0.002911;
	real S5_sum_ref = -0.000123;
	real S6_sum_ref = -0.012685;
	real S7_sum_ref = -0.000568;

	real toleranceSeidel = 0.001;

	bool checkS1Sum = Math::compareTwoNumbers_tolerance(S1_sum, S1_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS1Sum);
	bool checkS2Sum = Math::compareTwoNumbers_tolerance(S2_sum, S2_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS2Sum);
	bool checkS3Sum = Math::compareTwoNumbers_tolerance(S3_sum, S3_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS3Sum);
	bool checkS4Sum = Math::compareTwoNumbers_tolerance(S4_sum, S4_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS4Sum);
	bool checkS5Sum = Math::compareTwoNumbers_tolerance(S5_sum, S5_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS5Sum);
	bool checkS6Sum = Math::compareTwoNumbers_tolerance(S6_sum, S6_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS6Sum);
	bool checkS7Sum = Math::compareTwoNumbers_tolerance(S7_sum, S7_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS7Sum);

	bool checkSeidel = Math::checkTrueOfVectorElements(checkCalcSeidel);
	return checkSeidel;
}
// E12
bool testSeidelCoefficients::checkCalculationOfSeidelCoefficients_E12()
{
	std::vector<bool> checkCalcSeidel;

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr<InteractionRay_LLT> interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// surfaces E12
	SphericalElement S0(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S1(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getNSF10_S1());
	SphericalElement S2(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF10_S1());
	ApertureStopElement S3(/* semi height*/ 2.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S4(/*radius*/ 25.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 25.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S7(/*radius*/ 25.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	PlanElement S8(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,55.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());


	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();


	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr };
	std::vector<interaction_ptr> interactions_ptr{ refrac.clone(), refrac.clone(), refrac.clone(), doNothing.clone(), refrac.clone(),  refrac.clone(),  refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	std::vector<real> rms_Zemax{ 370.268, 292.919 };
	std::vector<VectorStructR3> fieldPoints = { {0.0,0.0,0.0}, {0.0,4.0,0.0} };
	std::vector<real> wave_vec = { 400.0, 550.0, 700.0 };
	// show optical system
	oftenUse::print(optSystemElement, wave_vec[0]);
	real tolerance = 0.1;
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, fieldPoints, wave_vec, rms_Zemax, tolerance, compareTOM_Zemax::comEqual);
	checkCalcSeidel.push_back(test);

	SeidelCoefficients seidelCoef;
	VectorStructR3 maxStartPoint_Y = { 0.0, 4.0, 0.0 };
	Light_LLT light = oftenUse::getDefaultLight();
	seidelCoef.calcSeidelCoef_superFuction(optSystemElement, wave_vec, light, maxStartPoint_Y);


	real S1_sum = seidelCoef.getS1sum();
	real S2_sum = seidelCoef.getS2sum();
	real S3_sum = seidelCoef.getS3sum();
	real S4_sum = seidelCoef.getS4sum();
	real S5_sum = seidelCoef.getS5sum();
	real S6_sum = seidelCoef.getS6C1sum();
	real S7_sum = seidelCoef.getS7C2sum();


	real S1_sum_ref = 0.016529;
	real S2_sum_ref = -0.010599;
	real S3_sum_ref = 0.010724;
	real S4_sum_ref = 0.015936;
	real S5_sum_ref = -0.024365;
	real S6_sum_ref = -0.028493;
	real S7_sum_ref = 0.017990;

	real toleranceSeidel = 0.001;

	bool checkS1Sum = Math::compareTwoNumbers_tolerance(S1_sum, S1_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS1Sum);
	bool checkS2Sum = Math::compareTwoNumbers_tolerance(S2_sum, S2_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS2Sum);
	bool checkS3Sum = Math::compareTwoNumbers_tolerance(S3_sum, S3_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS3Sum);
	bool checkS4Sum = Math::compareTwoNumbers_tolerance(S4_sum, S4_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS4Sum);
	bool checkS5Sum = Math::compareTwoNumbers_tolerance(S5_sum, S5_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS5Sum);
	bool checkS6Sum = Math::compareTwoNumbers_tolerance(S6_sum, S6_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS6Sum);
	bool checkS7Sum = Math::compareTwoNumbers_tolerance(S7_sum, S7_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS7Sum);

	bool checkSeidel = Math::checkTrueOfVectorElements(checkCalcSeidel);
	return checkSeidel;
}
// E13
bool testSeidelCoefficients::checkCalculationOfSeidelCoefficients_E13()
{
	std::vector<bool> checkCalcSeidel;

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr<InteractionRay_LLT> interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// surfaces E13
	SphericalElement S0(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S1(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getNSF10_S1());
	SphericalElement S2(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF10_S1());
	ApertureStopElement S3(/* semi height*/ 1.5, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S4(/*radius*/ 25.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 25.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S6(/*radius*/ 25.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNBAF10_S1(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S7(/*radius*/ 25.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF10_S1());
	PlanElement S8(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,55.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());


	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();


	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr };
	std::vector<interaction_ptr> interactions_ptr{ refrac.clone(), refrac.clone(), refrac.clone(), doNothing.clone(), refrac.clone(),  refrac.clone(),  refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	std::vector<real> rms_Zemax{ 935.470, 882.153 };
	std::vector<VectorStructR3> fieldPoints = { {0.0,0.0,0.0}, {0.0,4.0,0.0} };
	std::vector<real> wave_vec = { 400.0, 550.0, 700.0 };
	// show optical system
	oftenUse::print(optSystemElement, wave_vec[0]);
	real tolerance = 0.1;
	bool test = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, fieldPoints, wave_vec, rms_Zemax, tolerance, compareTOM_Zemax::comEqual);
	checkCalcSeidel.push_back(test);

	SeidelCoefficients seidelCoef;
	VectorStructR3 maxStartPoint_Y = { 0.0, 4.0, 0.0 };
	Light_LLT light = oftenUse::getDefaultLight();
	seidelCoef.calcSeidelCoef_superFuction(optSystemElement, wave_vec, light, maxStartPoint_Y);


	real S1_sum = seidelCoef.getS1sum();
	real S2_sum = seidelCoef.getS2sum();
	real S3_sum = seidelCoef.getS3sum();
	real S4_sum = seidelCoef.getS4sum();
	real S5_sum = seidelCoef.getS5sum();
	real S6_sum = seidelCoef.getS6C1sum();
	real S7_sum = seidelCoef.getS7C2sum();


	real S1_sum_ref = 0.002932;
	real S2_sum_ref = -0.003138;
	real S3_sum_ref = 0.004940;
	real S4_sum_ref = 0.006074;
	real S5_sum_ref = -0.009292;
	real S6_sum_ref = -0.015077;
	real S7_sum_ref = 0.007703;

	real toleranceSeidel = 0.001;

	bool checkS1Sum = Math::compareTwoNumbers_tolerance(S1_sum, S1_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS1Sum);
	bool checkS2Sum = Math::compareTwoNumbers_tolerance(S2_sum, S2_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS2Sum);
	bool checkS3Sum = Math::compareTwoNumbers_tolerance(S3_sum, S3_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS3Sum);
	bool checkS4Sum = Math::compareTwoNumbers_tolerance(S4_sum, S4_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS4Sum);
	bool checkS5Sum = Math::compareTwoNumbers_tolerance(S5_sum, S5_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS5Sum);
	bool checkS6Sum = Math::compareTwoNumbers_tolerance(S6_sum, S6_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS6Sum);
	bool checkS7Sum = Math::compareTwoNumbers_tolerance(S7_sum, S7_sum_ref, toleranceSeidel);
	checkCalcSeidel.push_back(checkS7Sum);

	bool checkSeidel = Math::checkTrueOfVectorElements(checkCalcSeidel);
	return checkSeidel;
}