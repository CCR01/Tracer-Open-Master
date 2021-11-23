#pragma once
#include <vector>
#include <string>

enum class testWhat {
	tALL, tNothing, tMath, tFillAS, tAspherical_LLT, tApertureStop_LLT, tLensCatalogEO, tSphericalSurface_LLT, tGlasses,
	tParaxialLens_LLT, tPlanGeo_LLT, tCardinalPoints, tRayAiming_obj, tRayAiming_inf, tRayAiming_obj_initialRays, tRayAiming_inf_initialRays, tRayAiming_12Cores, tGenetic_opti, tGenetic_modes,
	tGenetic_cardinalPoints, tDLS_optiRMS, tDLS_optiCarPoints, tDLS_optiRMS_carPoints, tDLS_Parallel, tOptiIncluding_GeneticAndDLS_Parallel_RMS,
	tOptiIncluding_GeneticAndDLS_Parallel_CardinalPoints, tDLS_optiImageProcessing, tLensReplace, tOPD_obj, tOPD_inf, tGlobalOPD_obj, tGlobalOPD_inf, tImaSim, tPSF, tWienerFilter, tImproveImaQuality_openCV_Func,
	tDistortion, tNoise, tDetailEnhance_BFA, tDetailEnhance_DLS, tWienerFilterSuperFunction, tWienerFilterSuperFunction_parallel, tUnsharpMasking_BFA, tRemoveChroAber, tSequantialRayTracing,
	tImproveImaQual_superFct, tSharpnessEvaluation, tLensCatalogThorlabs, tSeidelCoef, tCalcMaxSeidelAber, tLensReplaceAndOptimize_object, tLensReplaceAndOptimize_inf, tLensCatalogQioptiq, tCompareTOMandZemaxOptimizer, tLensReplaceAndOptimize_statistic_ALL,
	tLensReplaceAndOptimize_statistic_twoLenses_obj, tLensReplaceAndOptimize_statistic_threeLenses_obj, tLensReplaceAndOptimize_statistic_fourLenses_obj, tLensReplaceAndOptimize_statistic_fiveLenses_obj,
	tLensReplaceAndOptimize_statistic_twoLenses_inf, tLensReplaceAndOptimize_statistic_threeLenses_inf, tLensReplaceAndOptimize_statistic_fourLenses_inf, tLensReplaceAndOptimize_statistic_fiveLenses_inf, tDGaO2021
};

class ManagementTests
{
public:
	ManagementTests();
	ManagementTests(std::vector<testWhat> testWhat_vec);
	~ManagementTests();

	bool testSuperFct();
	bool testWhatInTestWhatVec(testWhat checkTestWhatInVec);
	void checkerAndCout(bool check, std::string currentTestSystem);

private:
	std::vector<testWhat> mTestWhat_vec{};
};

