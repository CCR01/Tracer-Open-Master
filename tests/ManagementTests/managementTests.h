#pragma once
#include <vector>

enum class testWhat{tALL, tNothing, tMath, tFillAS, tAspherical_LLT, tApertureStop_LLT, tLensCatalogEO, tSphericalSurface_LLT, tGlasses, tParaxialLens_LLT, tPlanGeo_LLT, tCardinalPoints, tRayAiming_obj, tRayAiming_inf, tRayAiming_12Cores, tGenetic_opti, tGenetic_modes, tGenetic_cardinalPoints, tDLS_optiRMS};

class ManagementTests
{
public:
	ManagementTests();
	ManagementTests(std::vector<testWhat> testWhat_vec);
	~ManagementTests();

	bool testSuperFct();
	bool testWhatInTestWhatVec(testWhat checkTestWhatInVec);

private:
	std::vector<testWhat> mTestWhat_vec{};
};
