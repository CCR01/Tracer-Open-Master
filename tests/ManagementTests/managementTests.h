#pragma once
#include <vector>
#include <string>

enum class testWhat {
	tALL, tNothing, tMath, tFillAS, tAspherical_LLT, tApertureStop_LLT, tLensCatalogEO, tSphericalSurface_LLT, tGlasses,
	tParaxialLens_LLT, tPlanGeo_LLT, tCardinalPoints, tRayAiming_obj, tRayAiming_inf, tRayAiming_12Cores, tGenetic_opti, tGenetic_modes,
	tGenetic_cardinalPoints, tDLS_optiRMS, tDLS_optiCarPoints, tDLS_optiRMS_carPoints, tDLS_Parallel, tOptiIncluding_GeneticAndDLS_Parallel_RMS,
	tOptiIncluding_GeneticAndDLS_Parallel_CardinalPoints, tLensReplace
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

