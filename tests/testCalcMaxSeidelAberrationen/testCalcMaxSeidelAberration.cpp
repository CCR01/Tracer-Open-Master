#include "testCalcMaxSeidelAberration.h"

// seidel aberrations
#include "..\..\Analyse\Seidel Coefficients.h"

// elements
#include "..\..\SurfaceElements\ApertureStopElement.h"
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\PlanElement.h"

// optical system element
#include "..\..\OpticalSystemElement\OpticalSystemElement.h"

// interactions
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"

// glasses
#include "..\..\Glasses\Glasses.h"

// often use
#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

testCalcMaxSeidelAberration::testCalcMaxSeidelAberration() {}

testCalcMaxSeidelAberration::~testCalcMaxSeidelAberration() {}

typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr<InteractionRay_LLT> interaction_ptr;

bool testCalcMaxSeidelAberration::testCalcMaxSeidelAber_superFct()
{
	std::vector<bool> workTheSystem;

	// E0
	bool checkE0 = testCalcMaxSeidelAber_E0();
	workTheSystem.push_back(checkE0);
	
	// E1
	bool checkE1 = testCalcMaxSeidelAber_E1();
	workTheSystem.push_back(checkE1);
	
	//E2
	bool checkE2 = testCalcMaxSeidelAber_E2();
	workTheSystem.push_back(checkE2);
	
	//E3
	bool checkE3 = testCalcMaxSeidelAber_E3();
	workTheSystem.push_back(checkE3);

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}

//E0
bool testCalcMaxSeidelAberration::testCalcMaxSeidelAber_E0()
{
	std::vector<bool> workTheSystem;
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	DoNothingInteraction_LLT doNothing;
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	
	SphericalElement S1(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S2(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSF10_S1(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S3(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF10_S1());
	
	SphericalElement S4(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S5(/*radius*/40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getNSF10_S1());
	SphericalElement S6(/*radius*/40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF10_S1());
	
	SphericalElement S7(/*radius*/30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S8(/*radius*/30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	
	SphericalElement S9(/*radius*/25.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S10(/*radius*/25.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	
	PlanElement S11(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,65.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	//surfacePtr Aper0_E0_ptr = AperStop0_E0.clone();
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

	std::vector<surfacePtr> opticalSystemE0_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr };
	std::vector<interaction_ptr> interactionsE0_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE0_ptr, interactionsE0_ptr);

	oftenUse::print(optSystemElement, 587.6);

	// check the start system
	std::vector<real> rms_Zemax{ 137.836, 314.542 };
	std::vector<real> wave_vec = { 500.0,400.0,450.0 };
	std::vector<VectorStructR3> startPoints_vec{ {0.0,0.0,0.0},{0.0,2.0,0.0} };
	real tolerance = 0.1;
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, startPoints_vec, wave_vec, rms_Zemax, tolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	// test seidel sum
	// *** *** //
	SeidelCoefficients seidelCoef;
	Light_LLT light = oftenUse::getDefaultLight();
	seidelCoef.calcSeidelCoef_superFuction(optSystemElement, wave_vec, light, startPoints_vec[1]);

	real S1_sum = seidelCoef.getS1sum();
	real S2_sum = seidelCoef.getS2sum();
	real S3_sum = seidelCoef.getS3sum();
	real S4_sum = seidelCoef.getS4sum();
	real S5_sum = seidelCoef.getS5sum();
	real S6_sum = seidelCoef.getS6C1sum();
	real S7_sum = seidelCoef.getS7C2sum();

	real S1_sum_ref = 0.069999;
	real S2_sum_ref = -0.073452;
	real S3_sum_ref = 0.077625;
	real S4_sum_ref = 0.008202;
	real S5_sum_ref = -0.091370;
	real S6_sum_ref = -0.040047;
	real S7_sum_ref = 0.041889;

	real toleranceSeidel = 0.1;

	bool checkS1Sum = Math::compareTwoNumbers_tolerance(S1_sum, S1_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS1Sum);
	bool checkS2Sum = Math::compareTwoNumbers_tolerance(S2_sum, S2_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS2Sum);
	bool checkS3Sum = Math::compareTwoNumbers_tolerance(S3_sum, S3_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS3Sum);
	bool checkS4Sum = Math::compareTwoNumbers_tolerance(S4_sum, S4_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS4Sum);
	bool checkS5Sum = Math::compareTwoNumbers_tolerance(S5_sum, S5_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS5Sum);
	bool checkS6Sum = Math::compareTwoNumbers_tolerance(S6_sum, S6_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS6Sum);
	bool checkS7Sum = Math::compareTwoNumbers_tolerance(S7_sum, S7_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS7Sum);
	// *** *** ///

	real SeidelSumSurface_0 = seidelCoef.calcSeidelSumSurface_i(0);
	real SeidelSumSurface_1 = seidelCoef.calcSeidelSumSurface_i(1);
	real SeidelSumSurface_2 = seidelCoef.calcSeidelSumSurface_i(2);
	real SeidelSumSurface_3 = seidelCoef.calcSeidelSumSurface_i(3);
	real SeidelSumSurface_4 = seidelCoef.calcSeidelSumSurface_i(4);
	real SeidelSumSurface_5 = seidelCoef.calcSeidelSumSurface_i(5);
	real SeidelSumSurface_6 = seidelCoef.calcSeidelSumSurface_i(6);
	real SeidelSumSurface_7 = seidelCoef.calcSeidelSumSurface_i(7);
	real SeidelSumSurface_8 = seidelCoef.calcSeidelSumSurface_i(8);
	real SeidelSumSurface_9 = seidelCoef.calcSeidelSumSurface_i(9);
	real SeidelSumSurface_10 = seidelCoef.calcSeidelSumSurface_i(10);

	real refSeidelSumSurface_0 = 0.0;
	real refSeidelSumSurface_1 = 0.061887;
	real refSeidelSumSurface_2 = 0.001724;
	real refSeidelSumSurface_3 = 0.017408;
	real refSeidelSumSurface_4 = 0.042631;
	real refSeidelSumSurface_5 = 0.030249;
	real refSeidelSumSurface_6 = 0.018900;
	real refSeidelSumSurface_7 = 0.009613;
	real refSeidelSumSurface_8 = 0.078406;
	real refSeidelSumSurface_9 = 0.007645;
	real refSeidelSumSurface_10 = 0.174415;

	real toleranceSeidelSumSurface = 0.01;
	bool checkSeidelSum_0 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_0, refSeidelSumSurface_0, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_0);
	bool checkSeidelSum_1 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_1, refSeidelSumSurface_1, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_1);
	bool checkSeidelSum_2 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_2, refSeidelSumSurface_2, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_2);
	bool checkSeidelSum_3 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_3, refSeidelSumSurface_3, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_3);
	bool checkSeidelSum_4 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_4, refSeidelSumSurface_4, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_4);
	bool checkSeidelSum_5 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_5, refSeidelSumSurface_5, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_5);
	bool checkSeidelSum_6 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_6, refSeidelSumSurface_6, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_6);
	bool checkSeidelSum_7 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_7, refSeidelSumSurface_7, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_7);
	bool checkSeidelSum_8 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_8, refSeidelSumSurface_8, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_8);
	bool checkSeidelSum_9 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_9, refSeidelSumSurface_9, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_9);
	bool checkSeidelSum_10 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_10, refSeidelSumSurface_10, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_10);

	// calc seidel sum all lenses
	real toleranceSeidelSumLenses = 0.01;
	std::vector<real> seidelSumAllLenses =  seidelCoef.calcSeidelSum_allLenses();
	real seidelSumLens_0 = SeidelSumSurface_1 + SeidelSumSurface_2 + SeidelSumSurface_3;
	real seidelSumLens_1 = SeidelSumSurface_4 + SeidelSumSurface_5 + SeidelSumSurface_6;
	real seidelSumLens_2 = SeidelSumSurface_7 + SeidelSumSurface_8;
	real seidelSumLens_3 = SeidelSumSurface_9 + SeidelSumSurface_10;

	real refseidelSumLens_0 = refSeidelSumSurface_1 +refSeidelSumSurface_2 + refSeidelSumSurface_3;
	real refseidelSumLens_1 = refSeidelSumSurface_4 +refSeidelSumSurface_5 + refSeidelSumSurface_6;
	real refseidelSumLens_2 = refSeidelSumSurface_7 +refSeidelSumSurface_8;
	real refseidelSumLens_3 = refSeidelSumSurface_9 +refSeidelSumSurface_10;

	bool checkSeidelSumLens_0 = Math::compareTwoNumbers_tolerance(seidelSumLens_0, refseidelSumLens_0, toleranceSeidelSumLenses);
	bool checkSeidelSumLens_0_0 = Math::compareTwoNumbers_tolerance(seidelSumLens_0, seidelSumAllLenses[0], toleranceSeidelSumLenses);
	workTheSystem.push_back(checkSeidelSumLens_0);
	workTheSystem.push_back(checkSeidelSumLens_0_0);

	bool checkSeidelSumLens_1 = Math::compareTwoNumbers_tolerance(seidelSumLens_1, refseidelSumLens_1, toleranceSeidelSumLenses);
	bool checkSeidelSumLens_1_1 = Math::compareTwoNumbers_tolerance(seidelSumLens_1, seidelSumAllLenses[1], toleranceSeidelSumLenses);
	workTheSystem.push_back(checkSeidelSumLens_1);
	workTheSystem.push_back(checkSeidelSumLens_1_1);

	bool checkSeidelSumLens_2 = Math::compareTwoNumbers_tolerance(seidelSumLens_2, refseidelSumLens_2, toleranceSeidelSumLenses);
	bool checkSeidelSumLens_2_2 = Math::compareTwoNumbers_tolerance(seidelSumLens_2, seidelSumAllLenses[2], toleranceSeidelSumLenses);
	workTheSystem.push_back(checkSeidelSumLens_2);
	workTheSystem.push_back(checkSeidelSumLens_2_2);

	bool checkSeidelSumLens_3 = Math::compareTwoNumbers_tolerance(seidelSumLens_3, refseidelSumLens_3, toleranceSeidelSumLenses);
	bool checkSeidelSumLens_3_3 = Math::compareTwoNumbers_tolerance(seidelSumLens_3, seidelSumAllLenses[3], toleranceSeidelSumLenses);
	workTheSystem.push_back(checkSeidelSumLens_3);
	workTheSystem.push_back(checkSeidelSumLens_3_3);

	int lensMaxSeidelAber = seidelCoef.getLensNumber_Max_SeidelAber(seidelSumAllLenses);
	int refLensMaxSeidelAber = 3;
	bool checkLensMaxSeidelAber = Math::compareTwoNumbers_tolerance(refLensMaxSeidelAber, lensMaxSeidelAber, toleranceSeidelSumLenses);
	workTheSystem.push_back(checkLensMaxSeidelAber);

	int lensMinSeidelAber = seidelCoef.getLensNumber_Min_SeidelAber(seidelSumAllLenses);
	int refLensMinSeidelAber = 0;
	bool checkLensMinSeidelAber = Math::compareTwoNumbers_tolerance(refLensMinSeidelAber, lensMinSeidelAber, toleranceSeidelSumLenses);
	workTheSystem.push_back(checkLensMinSeidelAber);

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}

//E1
bool testCalcMaxSeidelAberration::testCalcMaxSeidelAber_E1()
{
	std::vector<bool> workTheSystem;
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	DoNothingInteraction_LLT doNothing;
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());

	SphericalElement S1(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S2(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSF10_S1(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S3(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF10_S1());

	SphericalElement S4(/*radius*/ 100.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 100.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBAF10_S1(), /*refractive index B*/glasses.getAir());

	SphericalElement S6(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S7(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getNSF10_S1());
	SphericalElement S8(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF10_S1());

	SphericalElement S9(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S10(/*radius*/ 25.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S11(/*radius*/ 25.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());

	SphericalElement S12(/*radius*/ 80.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement S13(/*radius*/ 80.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getAir());

	PlanElement S14(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,85.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	//surfacePtr Aper0_E0_ptr = AperStop0_E0.clone();
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
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystemE1_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr,S12_ptr,S13_ptr,S14_ptr };
	std::vector<interaction_ptr> interactionsE1_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE1_ptr, interactionsE1_ptr);

	oftenUse::print(optSystemElement, 587.6);

	// check the start system
	std::vector<real> rms_Zemax{ 298.365, 988.418 };
	std::vector<real> wave_vec = { 550.0,400.0,700.0 };
	std::vector<VectorStructR3> startPoints_vec{ {0.0,0.0,0.0},{0.0,4.0,0.0} };
	real tolerance = 0.1;
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, startPoints_vec, wave_vec, rms_Zemax, tolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	// test seidel sum
	// *** *** //
	SeidelCoefficients seidelCoef;
	Light_LLT light = oftenUse::getDefaultLight();
	seidelCoef.calcSeidelCoef_superFuction(optSystemElement, wave_vec, light, startPoints_vec[1]);

	real S1_sum = seidelCoef.getS1sum();
	real S2_sum = seidelCoef.getS2sum();
	real S3_sum = seidelCoef.getS3sum();
	real S4_sum = seidelCoef.getS4sum();
	real S5_sum = seidelCoef.getS5sum();
	real S6_sum = seidelCoef.getS6C1sum();
	real S7_sum = seidelCoef.getS7C2sum();

	real S1_sum_ref = 0.020033;
	real S2_sum_ref = -0.040198;
	real S3_sum_ref = 0.083137;
	real S4_sum_ref = 0.008997;
	real S5_sum_ref = -0.195779;
	real S6_sum_ref = -0.050423;
	real S7_sum_ref = 0.105058;

	real toleranceSeidel = 0.1;

	bool checkS1Sum = Math::compareTwoNumbers_tolerance(S1_sum, S1_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS1Sum);
	bool checkS2Sum = Math::compareTwoNumbers_tolerance(S2_sum, S2_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS2Sum);
	bool checkS3Sum = Math::compareTwoNumbers_tolerance(S3_sum, S3_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS3Sum);
	bool checkS4Sum = Math::compareTwoNumbers_tolerance(S4_sum, S4_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS4Sum);
	bool checkS5Sum = Math::compareTwoNumbers_tolerance(S5_sum, S5_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS5Sum);
	bool checkS6Sum = Math::compareTwoNumbers_tolerance(S6_sum, S6_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS6Sum);
	bool checkS7Sum = Math::compareTwoNumbers_tolerance(S7_sum, S7_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS7Sum);
	// *** *** ///

	real SeidelSumSurface_0 = seidelCoef.calcSeidelSumSurface_i(0);
	real SeidelSumSurface_1 = seidelCoef.calcSeidelSumSurface_i(1);
	real SeidelSumSurface_2 = seidelCoef.calcSeidelSumSurface_i(2);
	real SeidelSumSurface_3 = seidelCoef.calcSeidelSumSurface_i(3);
	real SeidelSumSurface_4 = seidelCoef.calcSeidelSumSurface_i(4);
	real SeidelSumSurface_5 = seidelCoef.calcSeidelSumSurface_i(5);
	real SeidelSumSurface_6 = seidelCoef.calcSeidelSumSurface_i(6);
	real SeidelSumSurface_7 = seidelCoef.calcSeidelSumSurface_i(7);
	real SeidelSumSurface_8 = seidelCoef.calcSeidelSumSurface_i(8);
	real SeidelSumSurface_9 = seidelCoef.calcSeidelSumSurface_i(9);
	real SeidelSumSurface_10 = seidelCoef.calcSeidelSumSurface_i(10);
	real SeidelSumSurface_11 = seidelCoef.calcSeidelSumSurface_i(11);
	real SeidelSumSurface_12 = seidelCoef.calcSeidelSumSurface_i(12);
	real SeidelSumSurface_13 = seidelCoef.calcSeidelSumSurface_i(13);

	real refSeidelSumSurface_0 = 0.0;
	real refSeidelSumSurface_1 = 0.077702;
	real refSeidelSumSurface_2 = 0.002784;
	real refSeidelSumSurface_3 = 0.025244;
	real refSeidelSumSurface_4 = 0.046683;
	real refSeidelSumSurface_5 = 0.051406;
	real refSeidelSumSurface_6 = 0.072061;
	real refSeidelSumSurface_7 = 0.049945;
	real refSeidelSumSurface_8 = 0.046141;
	real refSeidelSumSurface_9 = 0.013054;
	real refSeidelSumSurface_10 = 0.014616;
	real refSeidelSumSurface_11 = 0.308859;
	real refSeidelSumSurface_12 = 0.057207;
	real refSeidelSumSurface_13 = 0.009610;

	real toleranceSeidelSumSurface = 0.01;
	bool checkSeidelSum_0 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_0, refSeidelSumSurface_0, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_0);
	bool checkSeidelSum_1 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_1, refSeidelSumSurface_1, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_1);
	bool checkSeidelSum_2 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_2, refSeidelSumSurface_2, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_2);
	bool checkSeidelSum_3 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_3, refSeidelSumSurface_3, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_3);
	bool checkSeidelSum_4 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_4, refSeidelSumSurface_4, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_4);
	bool checkSeidelSum_5 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_5, refSeidelSumSurface_5, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_5);
	bool checkSeidelSum_6 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_6, refSeidelSumSurface_6, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_6);
	bool checkSeidelSum_7 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_7, refSeidelSumSurface_7, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_7);
	bool checkSeidelSum_8 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_8, refSeidelSumSurface_8, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_8);
	bool checkSeidelSum_9 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_9, refSeidelSumSurface_9, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_9);
	bool checkSeidelSum_10 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_10, refSeidelSumSurface_10, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_10);
	bool checkSeidelSum_11 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_11, refSeidelSumSurface_11, toleranceSeidelSumSurface * 5.0);
	workTheSystem.push_back(checkSeidelSum_11);
	bool checkSeidelSum_12 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_12, refSeidelSumSurface_12, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_12);
	bool checkSeidelSum_13 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_13, refSeidelSumSurface_13, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_13);


	// calc seidel sum all lenses
	real toleranceSeidelSumLenses = 0.05;
	std::vector<real> seidelSumAllLenses = seidelCoef.calcSeidelSum_allLenses();
	real seidelSumLens_0 = SeidelSumSurface_1 + SeidelSumSurface_2 + SeidelSumSurface_3;
	real seidelSumLens_1 = SeidelSumSurface_4 + SeidelSumSurface_5;
	real seidelSumLens_2 = SeidelSumSurface_6 + SeidelSumSurface_7 + SeidelSumSurface_8;
	real seidelSumLens_3 = SeidelSumSurface_9 + SeidelSumSurface_10 + SeidelSumSurface_11;
	real seidelSumLens_4 = SeidelSumSurface_12 + SeidelSumSurface_13;

	real refseidelSumLens_0 = refSeidelSumSurface_1 + refSeidelSumSurface_2 + refSeidelSumSurface_3;
	real refseidelSumLens_1 = refSeidelSumSurface_4 + refSeidelSumSurface_5;
	real refseidelSumLens_2 = refSeidelSumSurface_6 + refSeidelSumSurface_7 + refSeidelSumSurface_8;
	real refseidelSumLens_3 = refSeidelSumSurface_9 + refSeidelSumSurface_10 + refSeidelSumSurface_11;
	real refseidelSumLens_4 = refSeidelSumSurface_12 + refSeidelSumSurface_13;

	bool checkSeidelSumLens_0 = Math::compareTwoNumbers_tolerance(seidelSumLens_0, refseidelSumLens_0, toleranceSeidelSumLenses);
	bool checkSeidelSumLens_0_0 = Math::compareTwoNumbers_tolerance(seidelSumLens_0, seidelSumAllLenses[0], toleranceSeidelSumLenses);
	workTheSystem.push_back(checkSeidelSumLens_0);
	workTheSystem.push_back(checkSeidelSumLens_0_0);

	bool checkSeidelSumLens_1 = Math::compareTwoNumbers_tolerance(seidelSumLens_1, refseidelSumLens_1, toleranceSeidelSumLenses);
	bool checkSeidelSumLens_1_1 = Math::compareTwoNumbers_tolerance(seidelSumLens_1, seidelSumAllLenses[1], toleranceSeidelSumLenses);
	workTheSystem.push_back(checkSeidelSumLens_1);
	workTheSystem.push_back(checkSeidelSumLens_1_1);

	bool checkSeidelSumLens_2 = Math::compareTwoNumbers_tolerance(seidelSumLens_2, refseidelSumLens_2, toleranceSeidelSumLenses);
	bool checkSeidelSumLens_2_2 = Math::compareTwoNumbers_tolerance(seidelSumLens_2, seidelSumAllLenses[2], toleranceSeidelSumLenses);
	workTheSystem.push_back(checkSeidelSumLens_2);
	workTheSystem.push_back(checkSeidelSumLens_2_2);

	bool checkSeidelSumLens_3 = Math::compareTwoNumbers_tolerance(seidelSumLens_3, refseidelSumLens_3, toleranceSeidelSumLenses);
	bool checkSeidelSumLens_3_3 = Math::compareTwoNumbers_tolerance(seidelSumLens_3, seidelSumAllLenses[3], toleranceSeidelSumLenses);
	workTheSystem.push_back(checkSeidelSumLens_3);
	workTheSystem.push_back(checkSeidelSumLens_3_3);

	bool checkSeidelSumLens_4 = Math::compareTwoNumbers_tolerance(seidelSumLens_4, refseidelSumLens_4, toleranceSeidelSumLenses);
	bool checkSeidelSumLens_4_4 = Math::compareTwoNumbers_tolerance(seidelSumLens_4, seidelSumAllLenses[4], toleranceSeidelSumLenses);
	workTheSystem.push_back(checkSeidelSumLens_4);
	workTheSystem.push_back(checkSeidelSumLens_4_4);

	int lensMaxSeidelAber = seidelCoef.getLensNumber_Max_SeidelAber(seidelSumAllLenses);
	int refLensMaxSeidelAber = 3;
	bool checkLensMaxSeidelAber = Math::compareTwoNumbers_tolerance(refLensMaxSeidelAber, lensMaxSeidelAber, toleranceSeidelSumLenses);
	workTheSystem.push_back(checkLensMaxSeidelAber);

	int lensMinSeidelAber = seidelCoef.getLensNumber_Min_SeidelAber(seidelSumAllLenses);
	int refLensMinSeidelAber = 4;
	bool checkLensMinSeidelAber = Math::compareTwoNumbers_tolerance(refLensMinSeidelAber, lensMinSeidelAber, toleranceSeidelSumLenses);
	workTheSystem.push_back(checkLensMinSeidelAber);

	int lensMaxSeidelAber_superFct = seidelCoef.getLensNumber_Max_SeidelAber_superFct();
	bool checkLensMaxSeidelAber_superFct = Math::compareTwoNumbers_tolerance(lensMaxSeidelAber, lensMaxSeidelAber_superFct, toleranceSeidelSumLenses);
	workTheSystem.push_back(checkLensMaxSeidelAber_superFct);

	int lensMinSeidelAber_superFct = seidelCoef.getLensNumber_Min_SeidelAber_superFct();
	bool checkLensMinSeidelAber_superFct = Math::compareTwoNumbers_tolerance(lensMinSeidelAber, lensMinSeidelAber_superFct, toleranceSeidelSumLenses);
	workTheSystem.push_back(checkLensMinSeidelAber_superFct);

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
//E2
bool testCalcMaxSeidelAberration::testCalcMaxSeidelAber_E2()
{
	std::vector<bool> workTheSystem;
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	DoNothingInteraction_LLT doNothing;
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());

	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S2(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSF10_S1(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S3(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,  -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF10_S1());

	SphericalElement S4(/*radius*/ 25.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNBAF10_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement S5(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNBAF10_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getNSF10_S1());
	SphericalElement S7(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF10_S1());
	
	SphericalElement S8(/*radius*/ 25.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S9(/*radius*/ 80.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S10(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	
	PlanElement S11(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,80.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());


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


	std::vector<surfacePtr> opticalSystemE2_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr };
	std::vector<interaction_ptr> interactionsE2_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE2_ptr, interactionsE2_ptr);

	oftenUse::print(optSystemElement, 400.0);
	real tolerance = 0.1;


	// check single ray
	Light_LLT light = oftenUse::getDefaultLight();
	optSystemElement.setRefractiveIndexAccordingToWavelength(400.0);
	LightRayStruct singleLightRay = oftenUse::findMarginalRay_obj(optSystemElement, 400.0, light);
	bool checkSingleRay = oftenUse::checkRayTracing(/*start point ray*/{ 0.0,0.0,0.0 },/*direction ray*/{ 0.0,1.5,15.0 },/*target point*/{0.0,0.1273,80.0},/*optical system LLT*/ optSystemElement.getLLTconversion_doConversion(),/*surface num*/ 12,/*tolerance*/ tolerance);


	// check the start system
	std::vector<real> rms_Zemax{ 296.019, 340.907 };
	std::vector<real> wave_vec = { 400.0,550.0,700.0 };
	std::vector<VectorStructR3> startPoints_vec{ {0.0,0.0,0.0},{0.0,3.0,0.0} };
	
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, startPoints_vec, wave_vec, rms_Zemax, tolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	// test seidel sum
	// *** *** //
	SeidelCoefficients seidelCoef;
	seidelCoef.calcSeidelCoef_superFuction(optSystemElement, wave_vec, light, startPoints_vec[1]);

	real S1_sum = seidelCoef.getS1sum();
	real S2_sum = seidelCoef.getS2sum();
	real S3_sum = seidelCoef.getS3sum();
	real S4_sum = seidelCoef.getS4sum();
	real S5_sum = seidelCoef.getS5sum();
	real S6_sum = seidelCoef.getS6C1sum();
	real S7_sum = seidelCoef.getS7C2sum();

	real S1_sum_ref = 0.020333;
	real S2_sum_ref = -0.028796;
	real S3_sum_ref = 0.042513;
	real S4_sum_ref = 0.004728;
	real S5_sum_ref = -0.073120;
	real S6_sum_ref = -0.053389;
	real S7_sum_ref = 0.076335;

	real toleranceSeidel = 0.1;

	bool checkS1Sum = Math::compareTwoNumbers_tolerance(S1_sum, S1_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS1Sum);
	bool checkS2Sum = Math::compareTwoNumbers_tolerance(S2_sum, S2_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS2Sum);
	bool checkS3Sum = Math::compareTwoNumbers_tolerance(S3_sum, S3_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS3Sum);
	bool checkS4Sum = Math::compareTwoNumbers_tolerance(S4_sum, S4_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS4Sum);
	bool checkS5Sum = Math::compareTwoNumbers_tolerance(S5_sum, S5_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS5Sum);
	bool checkS6Sum = Math::compareTwoNumbers_tolerance(S6_sum, S6_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS6Sum);
	bool checkS7Sum = Math::compareTwoNumbers_tolerance(S7_sum, S7_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS7Sum);
	// *** *** ///

	real SeidelSumSurface_0 = seidelCoef.calcSeidelSumSurface_i(0);
	real SeidelSumSurface_1 = seidelCoef.calcSeidelSumSurface_i(1);
	real SeidelSumSurface_2 = seidelCoef.calcSeidelSumSurface_i(2);
	real SeidelSumSurface_3 = seidelCoef.calcSeidelSumSurface_i(3);
	real SeidelSumSurface_4 = seidelCoef.calcSeidelSumSurface_i(4);
	real SeidelSumSurface_5 = seidelCoef.calcSeidelSumSurface_i(5);
	real SeidelSumSurface_6 = seidelCoef.calcSeidelSumSurface_i(6);
	real SeidelSumSurface_7 = seidelCoef.calcSeidelSumSurface_i(7);
	real SeidelSumSurface_8 = seidelCoef.calcSeidelSumSurface_i(8);
	real SeidelSumSurface_9 = seidelCoef.calcSeidelSumSurface_i(9);
	real SeidelSumSurface_10 = seidelCoef.calcSeidelSumSurface_i(10);
	
	real refSeidelSumSurface_0 = 0.0;
	real refSeidelSumSurface_1 = 0.058452;
	real refSeidelSumSurface_2 = 0.001950;
	real refSeidelSumSurface_3 = 0.014059;
	real refSeidelSumSurface_4 = 0.007586;
	real refSeidelSumSurface_5 = 0.020049;
	real refSeidelSumSurface_6 = 0.061739;
	real refSeidelSumSurface_7 = 0.025086;
	real refSeidelSumSurface_8 = 0.060396;
	real refSeidelSumSurface_9 = 0.018558;
	real refSeidelSumSurface_10 = 0.101987;

	real toleranceSeidelSumSurface = 0.01;
	bool checkSeidelSum_0 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_0, refSeidelSumSurface_0, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_0);
	bool checkSeidelSum_1 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_1, refSeidelSumSurface_1, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_1);
	bool checkSeidelSum_2 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_2, refSeidelSumSurface_2, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_2);
	bool checkSeidelSum_3 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_3, refSeidelSumSurface_3, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_3);
	bool checkSeidelSum_4 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_4, refSeidelSumSurface_4, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_4);
	bool checkSeidelSum_5 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_5, refSeidelSumSurface_5, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_5);
	bool checkSeidelSum_6 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_6, refSeidelSumSurface_6, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_6);
	bool checkSeidelSum_7 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_7, refSeidelSumSurface_7, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_7);
	bool checkSeidelSum_8 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_8, refSeidelSumSurface_8, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_8);
	bool checkSeidelSum_9 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_9, refSeidelSumSurface_9, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_9);
	bool checkSeidelSum_10 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_10, refSeidelSumSurface_10, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_10);
	
	// calc seidel sum all lenses
	real toleranceSeidelSumLenses = 0.05;
	std::vector<real> seidelSumAllLenses = seidelCoef.calcSeidelSum_allLenses();
	real seidelSumLens_0 = SeidelSumSurface_1 + SeidelSumSurface_2 + SeidelSumSurface_3;
	real seidelSumLens_1 = SeidelSumSurface_4 + SeidelSumSurface_5 + SeidelSumSurface_6 + SeidelSumSurface_7;
	real seidelSumLens_2 = SeidelSumSurface_8 + SeidelSumSurface_9 + SeidelSumSurface_10;

	real refseidelSumLens_0 = refSeidelSumSurface_1 + refSeidelSumSurface_2 + refSeidelSumSurface_3;
	real refseidelSumLens_1 = refSeidelSumSurface_4 + refSeidelSumSurface_5 + refSeidelSumSurface_6 + refSeidelSumSurface_7;
	real refseidelSumLens_2 = refSeidelSumSurface_8 + refSeidelSumSurface_9 + refSeidelSumSurface_10;

	bool checkSeidelSumLens_0 = Math::compareTwoNumbers_tolerance(seidelSumLens_0, refseidelSumLens_0, toleranceSeidelSumLenses);
	bool checkSeidelSumLens_0_0 = Math::compareTwoNumbers_tolerance(seidelSumLens_0, seidelSumAllLenses[0], toleranceSeidelSumLenses);
	workTheSystem.push_back(checkSeidelSumLens_0);
	workTheSystem.push_back(checkSeidelSumLens_0_0);

	bool checkSeidelSumLens_1 = Math::compareTwoNumbers_tolerance(seidelSumLens_1, refseidelSumLens_1, toleranceSeidelSumLenses);
	bool checkSeidelSumLens_1_1 = Math::compareTwoNumbers_tolerance(seidelSumLens_1, seidelSumAllLenses[1], toleranceSeidelSumLenses);
	workTheSystem.push_back(checkSeidelSumLens_1);
	workTheSystem.push_back(checkSeidelSumLens_1_1);

	bool checkSeidelSumLens_2 = Math::compareTwoNumbers_tolerance(seidelSumLens_2, refseidelSumLens_2, toleranceSeidelSumLenses);
	bool checkSeidelSumLens_2_2 = Math::compareTwoNumbers_tolerance(seidelSumLens_2, seidelSumAllLenses[2], toleranceSeidelSumLenses);
	workTheSystem.push_back(checkSeidelSumLens_2);
	workTheSystem.push_back(checkSeidelSumLens_2_2);

	int lensMaxSeidelAber = seidelCoef.getLensNumber_Max_SeidelAber(seidelSumAllLenses);
	int refLensMaxSeidelAber = 2;
	bool checkLensMaxSeidelAber = Math::compareTwoNumbers_tolerance(refLensMaxSeidelAber, lensMaxSeidelAber, toleranceSeidelSumLenses);
	workTheSystem.push_back(checkLensMaxSeidelAber);

	int lensMinSeidelAber = seidelCoef.getLensNumber_Min_SeidelAber(seidelSumAllLenses);
	int refLensMinSeidelAber = 0;
	bool checkLensMinSeidelAber = Math::compareTwoNumbers_tolerance(refLensMinSeidelAber, lensMinSeidelAber, toleranceSeidelSumLenses);
	workTheSystem.push_back(checkLensMinSeidelAber);

	int lensMaxSeidelAber_superFct = seidelCoef.getLensNumber_Max_SeidelAber_superFct();
	bool checkLensMaxSeidelAber_superFct = Math::compareTwoNumbers_tolerance(lensMaxSeidelAber, lensMaxSeidelAber_superFct, toleranceSeidelSumLenses);
	workTheSystem.push_back(checkLensMaxSeidelAber_superFct);

	int lensMinSeidelAber_superFct = seidelCoef.getLensNumber_Min_SeidelAber_superFct();
	bool checkLensMinSeidelAber_superFct = Math::compareTwoNumbers_tolerance(lensMinSeidelAber, lensMinSeidelAber_superFct, toleranceSeidelSumLenses);
	workTheSystem.push_back(checkLensMinSeidelAber_superFct);

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
//E3
bool testCalcMaxSeidelAberration::testCalcMaxSeidelAber_E3()
{
	std::vector<bool> workTheSystem;
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	DoNothingInteraction_LLT doNothing;
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());

	SphericalElement S1(/*radius*/ 60.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBASF64_S1());
	SphericalElement S2(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBASF64_S1());
	
	SphericalElement S3(/*radius*/ 80.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getNSK10_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNSK10_S1(), /*refractive index B*/glasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF10_S1());

	SphericalElement S6(/*radius*/ 80.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	SphericalElement S7(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNSF5_S1(), /*refractive index B*/glasses.getNSF10_S1());
	SphericalElement S8(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF10_S1());

	SphericalElement S9(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF56_S1());
	SphericalElement S10(/*radius*/ 25.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNSF56_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S11(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());

	PlanElement S12(/*semi height*/ 40.0, /*point*/{ 0.0,0.0,75.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	//surfacePtr Aper0_E0_ptr = AperStop0_E0.clone();
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

	std::vector<surfacePtr> opticalSystemE3_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactionsE3_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemE3_ptr, interactionsE3_ptr);

	oftenUse::print(optSystemElement, 700.0);

	// check the start system
	std::vector<real> rms_Zemax{ 368.421, 434.264};
	std::vector<real> wave_vec = { 700.0,400.0,550.0 };
	std::vector<VectorStructR3> startPoints_vec{ {0.0,0.0,0.0},{0.0,5.0,0.0} };
	real tolerance = 0.1;
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, startPoints_vec, wave_vec, rms_Zemax, tolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	// test seidel sum
	// *** *** //
	SeidelCoefficients seidelCoef;
	Light_LLT light = oftenUse::getDefaultLight();
	seidelCoef.calcSeidelCoef_superFuction(optSystemElement, wave_vec, light, startPoints_vec[1]);

	real S1_sum = seidelCoef.getS1sum();
	real S2_sum = seidelCoef.getS2sum();
	real S3_sum = seidelCoef.getS3sum();
	real S4_sum = seidelCoef.getS4sum();
	real S5_sum = seidelCoef.getS5sum();
	real S6_sum = seidelCoef.getS6C1sum();
	real S7_sum = seidelCoef.getS7C2sum();

	real S1_sum_ref = 0.015952;
	real S2_sum_ref = -0.033388;
	real S3_sum_ref = 0.072090;
	real S4_sum_ref = 0.016312;
	real S5_sum_ref = -0.199990;
	real S6_sum_ref = -0.038146;
	real S7_sum_ref = 0.090170;

	real toleranceSeidel = 0.1;

	bool checkS1Sum = Math::compareTwoNumbers_tolerance(S1_sum, S1_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS1Sum);
	bool checkS2Sum = Math::compareTwoNumbers_tolerance(S2_sum, S2_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS2Sum);
	bool checkS3Sum = Math::compareTwoNumbers_tolerance(S3_sum, S3_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS3Sum);
	bool checkS4Sum = Math::compareTwoNumbers_tolerance(S4_sum, S4_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS4Sum);
	bool checkS5Sum = Math::compareTwoNumbers_tolerance(S5_sum, S5_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS5Sum);
	bool checkS6Sum = Math::compareTwoNumbers_tolerance(S6_sum, S6_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS6Sum);
	bool checkS7Sum = Math::compareTwoNumbers_tolerance(S7_sum, S7_sum_ref, toleranceSeidel);
	workTheSystem.push_back(checkS7Sum);
	// *** *** ///

	real SeidelSumSurface_0 = seidelCoef.calcSeidelSumSurface_i(0);
	real SeidelSumSurface_1 = seidelCoef.calcSeidelSumSurface_i(1);
	real SeidelSumSurface_2 = seidelCoef.calcSeidelSumSurface_i(2);
	real SeidelSumSurface_3 = seidelCoef.calcSeidelSumSurface_i(3);
	real SeidelSumSurface_4 = seidelCoef.calcSeidelSumSurface_i(4);
	real SeidelSumSurface_5 = seidelCoef.calcSeidelSumSurface_i(5);
	real SeidelSumSurface_6 = seidelCoef.calcSeidelSumSurface_i(6);
	real SeidelSumSurface_7 = seidelCoef.calcSeidelSumSurface_i(7);
	real SeidelSumSurface_8 = seidelCoef.calcSeidelSumSurface_i(8);
	real SeidelSumSurface_9 = seidelCoef.calcSeidelSumSurface_i(9);
	real SeidelSumSurface_10 = seidelCoef.calcSeidelSumSurface_i(10);
	real SeidelSumSurface_11 = seidelCoef.calcSeidelSumSurface_i(11);


	real refSeidelSumSurface_0 = 0.0;
	real refSeidelSumSurface_1 = 0.110951;
	real refSeidelSumSurface_2 = 0.038152;
	real refSeidelSumSurface_3 = 0.035695;
	real refSeidelSumSurface_4 = 0.015640;
	real refSeidelSumSurface_5 = 0.011301;
	real refSeidelSumSurface_6 = 0.047821;
	real refSeidelSumSurface_7 = 0.009758;
	real refSeidelSumSurface_8 = 0.135051;
	real refSeidelSumSurface_9 = 0.031548;
	real refSeidelSumSurface_10 = 0.016010;
	real refSeidelSumSurface_11 = 0.138034;
	

	real toleranceSeidelSumSurface = 0.01;
	bool checkSeidelSum_0 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_0, refSeidelSumSurface_0, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_0);
	bool checkSeidelSum_1 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_1, refSeidelSumSurface_1, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_1);
	bool checkSeidelSum_2 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_2, refSeidelSumSurface_2, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_2);
	bool checkSeidelSum_3 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_3, refSeidelSumSurface_3, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_3);
	bool checkSeidelSum_4 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_4, refSeidelSumSurface_4, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_4);
	bool checkSeidelSum_5 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_5, refSeidelSumSurface_5, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_5);
	bool checkSeidelSum_6 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_6, refSeidelSumSurface_6, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_6);
	bool checkSeidelSum_7 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_7, refSeidelSumSurface_7, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_7);
	bool checkSeidelSum_8 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_8, refSeidelSumSurface_8, toleranceSeidelSumSurface + 0.01);
	workTheSystem.push_back(checkSeidelSum_8);
	bool checkSeidelSum_9 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_9, refSeidelSumSurface_9, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_9);
	bool checkSeidelSum_10 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_10, refSeidelSumSurface_10, toleranceSeidelSumSurface);
	workTheSystem.push_back(checkSeidelSum_10);
	bool checkSeidelSum_11 = Math::compareTwoNumbers_tolerance(SeidelSumSurface_11, refSeidelSumSurface_11, toleranceSeidelSumSurface * 5.0);
	workTheSystem.push_back(checkSeidelSum_11);



	// calc seidel sum all lenses
	real toleranceSeidelSumLenses = 0.05;
	std::vector<real> seidelSumAllLenses = seidelCoef.calcSeidelSum_allLenses();
	real seidelSumLens_0 = SeidelSumSurface_1 + SeidelSumSurface_2;
	real seidelSumLens_1 = SeidelSumSurface_3 +SeidelSumSurface_4 + SeidelSumSurface_5;
	real seidelSumLens_2 = SeidelSumSurface_6 + SeidelSumSurface_7 + SeidelSumSurface_8;
	real seidelSumLens_3 = SeidelSumSurface_9 + SeidelSumSurface_10 + SeidelSumSurface_11;

	real refseidelSumLens_0 = refSeidelSumSurface_1 + refSeidelSumSurface_2 + refSeidelSumSurface_3;
	real refseidelSumLens_1 = refSeidelSumSurface_4 + refSeidelSumSurface_5;
	real refseidelSumLens_2 = refSeidelSumSurface_6 + refSeidelSumSurface_7 + refSeidelSumSurface_8;
	real refseidelSumLens_3 = refSeidelSumSurface_9 + refSeidelSumSurface_10 + refSeidelSumSurface_11;

	bool checkSeidelSumLens_0 = Math::compareTwoNumbers_tolerance(seidelSumLens_0, refseidelSumLens_0, toleranceSeidelSumLenses);
	bool checkSeidelSumLens_0_0 = Math::compareTwoNumbers_tolerance(seidelSumLens_0, seidelSumAllLenses[0], toleranceSeidelSumLenses);
	workTheSystem.push_back(checkSeidelSumLens_0);
	workTheSystem.push_back(checkSeidelSumLens_0_0);

	bool checkSeidelSumLens_1 = Math::compareTwoNumbers_tolerance(seidelSumLens_1, refseidelSumLens_1, toleranceSeidelSumLenses);
	bool checkSeidelSumLens_1_1 = Math::compareTwoNumbers_tolerance(seidelSumLens_1, seidelSumAllLenses[1], toleranceSeidelSumLenses);
	workTheSystem.push_back(checkSeidelSumLens_1);
	workTheSystem.push_back(checkSeidelSumLens_1_1);

	bool checkSeidelSumLens_2 = Math::compareTwoNumbers_tolerance(seidelSumLens_2, refseidelSumLens_2, toleranceSeidelSumLenses);
	bool checkSeidelSumLens_2_2 = Math::compareTwoNumbers_tolerance(seidelSumLens_2, seidelSumAllLenses[2], toleranceSeidelSumLenses);
	workTheSystem.push_back(checkSeidelSumLens_2);
	workTheSystem.push_back(checkSeidelSumLens_2_2);

	bool checkSeidelSumLens_3 = Math::compareTwoNumbers_tolerance(seidelSumLens_3, refseidelSumLens_3, toleranceSeidelSumLenses);
	bool checkSeidelSumLens_3_3 = Math::compareTwoNumbers_tolerance(seidelSumLens_3, seidelSumAllLenses[3], toleranceSeidelSumLenses);
	workTheSystem.push_back(checkSeidelSumLens_3);
	workTheSystem.push_back(checkSeidelSumLens_3_3);

	int lensMaxSeidelAber = seidelCoef.getLensNumber_Max_SeidelAber(seidelSumAllLenses);
	int refLensMaxSeidelAber = 2;
	bool checkLensMaxSeidelAber = Math::compareTwoNumbers_tolerance(refLensMaxSeidelAber, lensMaxSeidelAber, toleranceSeidelSumLenses);
	workTheSystem.push_back(checkLensMaxSeidelAber);

	int lensMinSeidelAber = seidelCoef.getLensNumber_Min_SeidelAber(seidelSumAllLenses);
	int refLensMinSeidelAber = 1;
	bool checkLensMinSeidelAber = Math::compareTwoNumbers_tolerance(refLensMinSeidelAber, lensMinSeidelAber, toleranceSeidelSumLenses);
	workTheSystem.push_back(checkLensMinSeidelAber);

	int lensMaxSeidelAber_superFct = seidelCoef.getLensNumber_Max_SeidelAber_superFct();
	bool checkLensMaxSeidelAber_superFct = Math::compareTwoNumbers_tolerance(lensMaxSeidelAber, lensMaxSeidelAber_superFct, toleranceSeidelSumLenses);
	workTheSystem.push_back(checkLensMaxSeidelAber_superFct);

	int lensMinSeidelAber_superFct = seidelCoef.getLensNumber_Min_SeidelAber_superFct();
	bool checkLensMinSeidelAber_superFct = Math::compareTwoNumbers_tolerance(lensMinSeidelAber, lensMinSeidelAber_superFct, toleranceSeidelSumLenses);
	workTheSystem.push_back(checkLensMinSeidelAber_superFct);

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}