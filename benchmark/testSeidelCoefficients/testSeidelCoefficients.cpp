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

testSeidelCoefficients::testSeidelCoefficients() {}

testSeidelCoefficients::~testSeidelCoefficients() {}

// check methodes seidel coefficients
bool testSeidelCoefficients::checkCalculationOfSeidelCoefficients()
{
	std::vector<bool> checkCalcSeidel;
//	real tolerance_E0 = 0.01;
//	real tolerance_E1 = 2.0;
//
//	typedef std::shared_ptr< Element_CR > surfacePtr;
//	typedef std::shared_ptr<InteractionRay_LLT> interaction_ptr;
//
//	RefractedRay_LLT refrac;
//	Absorb_LLT absorb;
//	DoNothingInteraction_LLT doNothing;
//
//	glass glasses;
//	glasses.loadGlassCatalog_Schott();
//
//	// set the wavelength
//	Light_LLT Light0_E0;
//	Light0_E0.setWavelength(587.6);
//	Light0_E0.setIntensity(1.0);
//	std::vector<Light_LLT> lichtVecE0W0{ Light0_E0 };
//
//	Light_LLT Light1_E0;
//	Light1_E0.setWavelength(656.3);
//	Light1_E0.setIntensity(1.0);
//	std::vector<Light_LLT> lichtVecE0W1{ Light1_E0 };
//
//	Light_LLT Light2_E0;
//	Light2_E0.setWavelength(486.1);
//	Light2_E0.setIntensity(1.0);
//	std::vector<Light_LLT> lichtVecE0W2{ Light2_E0 };
//
//	std::vector<real> wavelenght_vec{ 587.6,656.3,486.1 };
//
//	// surfaces E0
//	//ApertureStopElement AperStop0_E0(/* semi height*/999.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
//	SphericalElement Sphere0_E0(/*radius*/ 42.987900, /*semi height*/ 11.5, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSK16_S1());
//	SphericalElement Sphere1_E0(/*radius*/ 248.077400, /*semi height*/ 11.5, /*point*/{ 0.0,0.0,14.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSK16_S1());
//	SphericalElement Sphere2_E0(/*radius*/ 38.210335, /*semi height*/ 9.852, /*point*/{ 0.0,0.0,24.51018 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getF4_S1(), /*refractive index B*/glasses.getAir());
//	ApertureStopElement AperStop3_E0(/* semi height*/10.0, /*point*/{ 0.0,0.0,27.01018 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getF4_S1());
//	SphericalElement Sphere4_E0(/*radius*/ 43.958940, /*semi height*/ 8.885, /*point*/{ 0.0,0.0,27.01019 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getF4_S1(), /*refractive index B*/glasses.getAir());
//	SphericalElement Sphere5_E0(/*radius*/656.663490, /*semi height*/ 14.0, /*point*/{ 0.0,0.0,36.87964 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSK16_S1());
//	SphericalElement Sphere6_E0(/*radius*/33.507540, /*semi height*/ 14.0, /*point*/{ 0.0,0.0,41.37964 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSK16_S1());
//	PlanElement Plan7_E0(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,127.86607 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
//
//	//surfacePtr Aper0_E0_ptr = AperStop0_E0.clone();
//	surfacePtr Sphere0_E0_ptr = Sphere0_E0.clone();
//	surfacePtr Sphere1_E0_ptr = Sphere1_E0.clone();
//	surfacePtr Sphere2_E0_ptr = Sphere2_E0.clone();
//	surfacePtr Aper3_E0_ptr = AperStop3_E0.clone();
//	surfacePtr Sphere4_E0_ptr = Sphere4_E0.clone();
//	surfacePtr Sphere5_E0_ptr = Sphere5_E0.clone();
//	surfacePtr Sphere6_E0_ptr = Sphere6_E0.clone();
//	surfacePtr Plan7_E0_ptr = Plan7_E0.clone();
//
//	std::vector<surfacePtr> opticalSystemE0_ptr{ Sphere0_E0_ptr, Sphere1_E0_ptr , Sphere2_E0_ptr, Aper3_E0_ptr, Sphere4_E0_ptr, Sphere5_E0_ptr, Sphere6_E0_ptr, Plan7_E0_ptr };
//	std::vector<interaction_ptr> interactionsE0_ptr{ refrac.clone(),refrac.clone(), refrac.clone(), doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };
//
//
//	//	build optical system
//	OpticalSystemElement optSystemElement_E0(opticalSystemE0_ptr, interactionsE0_ptr);
//
//
//	// ray opt achse
//	Ray_LLT rayE0_optA(/*origin*/{ 0.0,0.0,0.0 },/*direction*/{ 0.0,0.0,1.0 },/*refractive index*/ 1.0);
//	LightRayStruct lightRayW0optA(Light0_E0, rayE0_optA, 1);
//
//
//	Ray_LLT rayE0_MarginalRay(/*origin*/{ 0.0,11.11052,0.0 },/*direction*/{ 0.0,0.0,1.0 },/*refractive index*/ 1.0);
//	LightRayStruct lightRayMarginal(Light0_E0, rayE0_MarginalRay, 1);
//
//	Ray_LLT rayE0_Chief(/*origin*/{ 0.0,-11.091991292,0.0 },/*direction*/{ 0.0,3.86254752,10.61226208 },/*refractive index*/ 1.0);
//	LightRayStruct lightRayChief(Light0_E0, rayE0_Chief, 1);
//
//
//
//
//	// trace the ray thow the optical system
//	SequentialRayTracing seqTrace_E0_optA(/*optical system element*/ optSystemElement_E0, lightRayW0optA);
//	SequentialRayTracing seqTrace_E0_marginalRay(/*optical system element*/ optSystemElement_E0, lightRayMarginal);
//	SequentialRayTracing seqTrace_E0_chiefRay(/*optical system element*/ optSystemElement_E0, lightRayChief);
//
//	VectorStructR3 checkRayOptA = seqTrace_E0_optA.getAllInterPointsAtSurface_i_filtered_notFiltered(7).at(0);
//	VectorStructR3 testZemaxOptA{ 0.0, 0.0, 1.2786607000E2 };
//	bool checkOptA = Math::compareTwoVectorStructR3_decimals(checkRayOptA, testZemaxOptA, 3);
//	checkCalcSeidel.push_back(checkOptA);
//
//	VectorStructR3 checkRayMarginal = seqTrace_E0_marginalRay.getAllInterPointsAtSurface_i_filtered_notFiltered(7).at(0);
//	VectorStructR3 testZemaxMarginal{ 0.0, 0.014, 1.2786607000E2 };
//	bool checkMarginalRay = Math::compareTwoVectorStructR3_decimals(testZemaxMarginal, checkRayMarginal, 3);
//	checkCalcSeidel.push_back(checkMarginalRay);
//
//	VectorStructR3 checkRayChief = seqTrace_E0_chiefRay.getAllInterPointsAtSurface_i_filtered_notFiltered(7).at(0);
//	VectorStructR3 testZemaxCheifRay{ 0.0, 36.7981, 1.2786607000E2 };
//	bool checkCheifRay = Math::compareTwoVectorStructR3_decimals(checkRayChief, testZemaxCheifRay, 2);
//	checkCalcSeidel.push_back(checkCheifRay);
//
//
//
//	SeidelCoefficients SeidelCoefE0(/*optical system element*/optSystemElement_E0, /*chief Ray*/ lightRayChief, /*marginal ray*/ lightRayMarginal, wavelenght_vec, 4, 99.9953, -4.0439, true);
//
//	bool checkS1Sum_E0 = std::abs(SeidelCoefE0.getS1sum() - 0.011432) < tolerance_E0;
//	checkCalcSeidel.push_back(checkS1Sum_E0);
//	bool checkS2Sum_E0 = std::abs(SeidelCoefE0.getS2sum() - 0.010331) < tolerance_E0;
//	checkCalcSeidel.push_back(checkS2Sum_E0);
//	bool checkS3Sum_E0 = std::abs(SeidelCoefE0.getS3sum() - -0.028367) < tolerance_E0;
//	checkCalcSeidel.push_back(checkS3Sum_E0);
//	bool checkS4Sum_E0 = std::abs(SeidelCoefE0.getS4sum() - 0.062155) < tolerance_E0;
//	checkCalcSeidel.push_back(checkS4Sum_E0);
//	bool checkS5Sum_E0 = std::abs(SeidelCoefE0.getS5sum() - -0.059211) < tolerance_E0;
//	checkCalcSeidel.push_back(checkS5Sum_E0);
//	bool checkS6C1Sum_E0 = std::abs(SeidelCoefE0.getS6C1sum() - 0.000969) < tolerance_E0;
//	checkCalcSeidel.push_back(checkS6C1Sum_E0);
//	bool checkS7C2Sum_E0 = std::abs(SeidelCoefE0.getS7C2sum() - 0.000870) < tolerance_E0;
//	checkCalcSeidel.push_back(checkS7C2Sum_E0);
//
//
//	// TODO make that for all S and write get functons
//	int i = 0;
//	//SeidelCoefE0.calculate_RelevantValuesForSeidel();
//	//real S1 = 
//
//
//	//Second System
//
//	//set the wavelength for system 2
//	Light_LLT Light0_E1;
//	Light0_E1.setWavelength(587.6);
//	Light0_E1.setIntensity(1.0);
//
//
//	Light_LLT Light1_E1;
//	Light1_E1.setWavelength(656.3);
//	Light1_E1.setIntensity(1.0);
//
//
//	Light_LLT Light2_E1;
//	Light2_E1.setWavelength(486.1);
//	Light2_E1.setIntensity(1.0);
//
//
//	std::vector<real> wavelenght_vec_E1{ 587.6,656.3,486.1 };
//
//	// surfaces E1
//	//PlanElement Plan0_E1(/*semi height*/ 26.0, /*point*/{ 0.0,0.0,0.0001 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
//	PlanElement Plan0_E1(/*semi height*/ 26.0, /*point*/{ 0.0,0.0,0.0001 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getSK16_S1());
//	PlanElement Plan1_E1(/*semi height*/ 26.0, /*point*/{ 0.0,0.0,3.4701 },  /*direction*/{ 0.0,0.0,-1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getSK16_S1());
//	SphericalElement Sphere2_E1(/*radius*/ 45.31, /*semi height*/ 26.00, /*point*/{ 0.0,0.0,13.3201 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getLASFN9_S1(), /*refractive index B*/glasses.getAir());
//	SphericalElement Sphere3_E1(/*radius*/ 41.94, /*semi height*/ 32.00, /*point*/{ 0.0,0.0,29.9301 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getLASFN9_S1());
//	SphericalElement Sphere4_E1(/*radius*/ 195.81, /*semi height*/ 36.00, /*point*/{ 0.0,0.0,30.1701 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getLAF2_S1());
//	SphericalElement Sphere5_E1(/*radius*/ 145.34, /*semi height*/ 36.00, /*point*/{ 0.0,0.0,44.7701 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getLAF2_S1());
//	SphericalElement Sphere6_E1(/*radius*/112.37, /*semi height*/ 45.00, /*point*/{ 0.0,0.0,45.0101 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSK16_S1());
//	SphericalElement Sphere7_E1(/*radius*/47.24, /*semi height*/ 45.00, /*point*/{ 0.0,0.0,76.1501 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF63_S1(), /*refractive index B*/glasses.getSK16_S1());
//	SphericalElement Sphere8_E1(/*radius*/95.12, /*semi height*/ 45.00, /*point*/{ 0.0,0.0,79.9001 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF63_S1());
//	SphericalElement Sphere9_E1(/*radius*/349.66, /*semi height*/ 45.00, /*point*/{ 0.0,0.0,80.1401 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF9_S1());
//	SphericalElement Sphere10_E1(/*radius*/58.28, /*semi height*/ 45.00, /*point*/{ 0.0,0.0,84.9501 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF9_S1(), /*refractive index B*/glasses.getAir());
//	SphericalElement Sphere11_E1(/*radius*/256.57, /*semi height*/ 45.00, /*point*/{ 0.0,0.0,99.1501 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSK16_S1());
//	SphericalElement Sphere12_E1(/*radius*/115.95, /*semi height*/ 45.00, /*point*/{ 0.0,0.0,113.5601 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSK16_S1());
//	ApertureStopElement AperStop13_E1(/* semi height*/47.71, /*point*/{ 0.0,0.0,163.5601 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
//	PlanElement Plan14_E1(/*semi height*/ 999.0, /*point*/{ 0.0,0.0,168.5601 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
//	PlanElement Plan15_E1(/*semi height*/ 999.0, /*point*/{ 0.0,0.0,168.5602 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
//
//	surfacePtr Plan0_E1_ptr = Plan0_E1.clone();
//	surfacePtr Plan1_E1_ptr = Plan1_E1.clone();
//	surfacePtr Sphere2_E1_ptr = Sphere2_E1.clone();
//	surfacePtr Sphere3_E1_ptr = Sphere3_E1.clone();
//	surfacePtr Sphere4_E1_ptr = Sphere4_E1.clone();
//	surfacePtr Sphere5_E1_ptr = Sphere5_E1.clone();
//	surfacePtr Sphere6_E1_ptr = Sphere6_E1.clone();
//	surfacePtr Sphere7_E1_ptr = Sphere7_E1.clone();
//	surfacePtr Sphere8_E1_ptr = Sphere8_E1.clone();
//	surfacePtr Sphere9_E1_ptr = Sphere9_E1.clone();
//	surfacePtr Sphere10_E1_ptr = Sphere10_E1.clone();
//	surfacePtr Sphere11_E1_ptr = Sphere11_E1.clone();
//	surfacePtr Sphere12_E1_ptr = Sphere12_E1.clone();
//	surfacePtr Aper13_E1_ptr = AperStop13_E1.clone();
//	surfacePtr Plan14_E1_ptr = Plan14_E1.clone();
//	surfacePtr Plan15_E1_ptr = Plan15_E1.clone();
//
//
//	std::vector<surfacePtr> opticalSystemE1_ptr{ Plan0_E1_ptr, Plan1_E1_ptr, Sphere2_E1_ptr, Sphere3_E1_ptr, Sphere4_E1_ptr, Sphere5_E1_ptr, Sphere6_E1_ptr, Sphere7_E1_ptr, Sphere8_E1_ptr, Sphere9_E1_ptr, Sphere10_E1_ptr, Sphere11_E1_ptr, Sphere12_E1_ptr, Aper13_E1_ptr, Plan14_E1_ptr, Plan15_E1_ptr };
//	std::vector<interaction_ptr> interactionsE1_ptr{ refrac.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), doNothing.clone(), refrac.clone(),absorb.clone() };
//
//	// build optical system 2
//	OpticalSystemElement optSystemElement_E1(opticalSystemE1_ptr, interactionsE1_ptr);
//
//	// ray opt achse 2
//	Ray_LLT rayE1_ChiefRay_optA(/*origin*/{ 0.0,0.0,0.0 },/*direction*/{ 0.0,0.0,1.0 },/*refractive index*/ 1.0);
//	LightRayStruct lightRayW0optA_E1(Light0_E1, rayE1_ChiefRay_optA, 1);
//
//
//	Ray_LLT rayE1_Marginal(/*origin*/{ 0.0,0.0,0.0 },/*direction*/{ 0.0,0.000082,0.0001 },/*refractive index*/ 1.0);
//	LightRayStruct lightRayMarginal_E1(Light0_E1, rayE1_Marginal, 1);
//
//	Ray_LLT rayE1_ChiefRayField(/*origin*/{ 0.0,20.0,0.0 },/*direction*/{ 0.0,0.000044651,0.0001 },/*refractive index*/ 1.0);
//	LightRayStruct lightRayChiefRayField(Light0_E1, rayE1_ChiefRayField, 1);
//
//
//	// trace the ray thow the optical system 
//	SequentialRayTracing seqTrace_E1_optA(/*optical system element*/ optSystemElement_E1, lightRayW0optA_E1);
//	SequentialRayTracing seqTrace_E1_Marginal(/*optical system element*/ optSystemElement_E1, lightRayMarginal_E1);
//	SequentialRayTracing seqTrace_E1_ChiefRayField(/*optical system element*/ optSystemElement_E1, lightRayChiefRayField);
//
//	VectorStructR3 checkRayChiefRay_optA = seqTrace_E1_optA.getAllInterPointsAtSurf_i_notFiltered(14).at(0);
//	VectorStructR3 testZemaxChiefRayOptA{ 0.0, 0.0, 1.6856010000E2 };
//	bool checkChiefRayOptA = Math::compareTwoVectorStructR3_decimals(checkRayChiefRay_optA, testZemaxChiefRayOptA, 3);
//	checkCalcSeidel.push_back(checkChiefRayOptA);
//
//	VectorStructR3 checkMarginalRay_E1 = seqTrace_E1_Marginal.getAllInterPointsAtSurf_i_notFiltered(14).at(0);
//	VectorStructR3 testZemaxMarginal_E1{ 0.0, 36.67526, 1.6856010000E2 };
//	bool checkMarginal = Math::compareTwoVectorStructR3_decimals(checkMarginalRay_E1, testZemaxMarginal_E1, 3);
//	checkCalcSeidel.push_back(checkMarginal);
//
//	VectorStructR3 checkChiefRayField = seqTrace_E1_ChiefRayField.getAllInterPointsAtSurf_i_notFiltered(14).at(0);
//	VectorStructR3 testZemaxCheifRayField{ 0.0, -1.8632, 1.6856010000E2 };
//	bool checkCheifRayField = Math::compareTwoVectorStructR3_decimals(checkChiefRayField, testZemaxCheifRayField, 3);
//	checkCalcSeidel.push_back(checkCheifRayField);
//
//
//	SeidelCoefficients SeidelCoefE1(/*optical system element*/optSystemElement_E1, /*cheif Ray*/ lightRayChiefRayField, /*marginal ray*/ lightRayMarginal_E1, wavelenght_vec_E1, 13, 49.171, 16.4, false);
//	//SeidelCoefE0.calculate_RelevantValuesForSeidel();
//	//real S1 = 
//
//	bool checkS1Sum_E1 = std::abs(SeidelCoefE1.getS1sum() - 0.712787) < tolerance_E1;
//	checkCalcSeidel.push_back(checkS1Sum_E1);
//	bool checkS2Sum_E1 = std::abs(SeidelCoefE1.getS2sum() - -0.600932) < tolerance_E1;
//	checkCalcSeidel.push_back(checkS2Sum_E1);
//	bool checkS3Sum_E1 = std::abs(SeidelCoefE1.getS3sum() - -2.391047) < tolerance_E1;
//	checkCalcSeidel.push_back(checkS3Sum_E1);
//	bool checkS4Sum_E1 = std::abs(SeidelCoefE1.getS4sum() - 3.232359) < tolerance_E1;
//	checkCalcSeidel.push_back(checkS4Sum_E1);
//	bool checkS5Sum_E1 = std::abs(SeidelCoefE1.getS5sum() - 1.352281) < tolerance_E1;
//	checkCalcSeidel.push_back(checkS5Sum_E1);
//	bool checkS6C1Sum_E1 = std::abs(SeidelCoefE1.getS6C1sum() - 0.014312) < tolerance_E1;
//	checkCalcSeidel.push_back(checkS6C1Sum_E1);
//	bool checkS7C2Sum_E1 = std::abs(SeidelCoefE1.getS7C2sum() - 0.194830) < tolerance_E1;
//	checkCalcSeidel.push_back(checkS7C2Sum_E1);
//
//	// test seidel with LLT 
//
//
//	// ---
	bool checkSeidel = Math::checkTrueOfVectorElements(checkCalcSeidel);
//	//// ---
//	//
//	//real wavelenght550 = 550;
//	//real BK7 = glasses.getBK7_S1().calcRefractiveIndexSnellmeier1(wavelenght550);
//	//real SF13 = glasses.getSF13_S1().calcRefractiveIndexSnellmeier1(wavelenght550);
//	//
//	//// surfaces E0
//	//
//	//ApertureStop_LLT AperStop0_E2(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ 1.0);
//	//SphericalSurface_LLT Sphere1_E2(/*radius*/ 10.0, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ 1.0, /*refractive index B*/BK7);
//	//SphericalSurface_LLT Sphere2_E2(/*radius*/ 20.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ 1.0, /*refractive index B*/BK7);
//	//SphericalSurface_LLT Sphere3_E2(/*radius*/ 70.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ SF13, /*refractive index B*/1.0);
//	//SphericalSurface_LLT Sphere4_E2(/*radius*/ 50.00, /*semi height*/ 4.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ 1.0, /*refractive index B*/SF13);
//	//PlanGeometry_LLT Plan5_E2(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,55.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ 1.0, /*refractive index B*/ 1.0);
//	//
//	//typedef std::shared_ptr< SurfaceIntersectionRay_LLT > surfacePtr_LLT;
//	//
//	//OpticalSystem_LLT optSys_LLT_E2;
//	//optSys_LLT_E2.fillVectorSurfaceAndInteractingData(0, AperStop0_E2.clone(), doNothing.clone());
//	//optSys_LLT_E2.fillVectorSurfaceAndInteractingData(1, Sphere1_E2.clone(), refrac.clone());
//	//optSys_LLT_E2.fillVectorSurfaceAndInteractingData(2, Sphere2_E2.clone(), refrac.clone());
//	//optSys_LLT_E2.fillVectorSurfaceAndInteractingData(3, Sphere3_E2.clone(), refrac.clone());
//	//optSys_LLT_E2.fillVectorSurfaceAndInteractingData(4, Sphere4_E2.clone(), refrac.clone());
//	//optSys_LLT_E2.fillVectorSurfaceAndInteractingData(5, Plan5_E2.clone(), absorb.clone());
//	//
//	//// cheif light ray
//	//Ray_LLT cheifRay(/*origin*/{ 0.0,2.0,0.0 },/*direction*/{ 0.0,-2.0,20.0 },/*refractive index*/ 1.0);
//	//Light_LLT cheifLight(550.0, 1.0, { 0.0,0.0,0.0,0.0 }, typeLightRay, 1.0);
//	//LightRayStruct chiefLightRay(cheifLight, cheifRay, 1.0);
//	//
//	//// marginal light ray
//	//Ray_LLT marginalRay(/*origin*/{ 0.0,0.0,0.0 },/*direction*/{ 0.0,1.0,20.0 },/*refractive index*/ 1.0);
//	//Light_LLT marginalLight(550.0, 1.0, { 0.0,0.0,0.0,0.0 }, typeLightRay, 1.0);
//	//LightRayStruct marginalLightRay(marginalLight, marginalRay, 1.0);
//	//
	//SeidelCoefficients seidelCoef_E2(optSys_LLT_E2, chiefLightRay, marginalLightRay, 0, 11.4508, -0.10, 0);

	return checkSeidel;
}
