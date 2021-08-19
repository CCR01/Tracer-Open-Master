#include "managementBenchmark.h"
#include <iostream>

#include "..\..\LowLevelTracing\Math_LLT.h"

// ray tracing
#include "..\..\benchmark\benchRayTracing\benchRayTracing.h"
// genetic and DLS
#include "..\..\benchmark\benchGeneticAndDLS\benchGeneticAndDLS.h"
// ray aiming
#include "..\..\benchmark\benchRayAiming\BenchRayAiming.h"

managementBenchmark::managementBenchmark(){}
managementBenchmark::managementBenchmark(std::vector<benchWhat> benchWhat_vec) :
	mBenchWhat_vec(benchWhat_vec)
{}
managementBenchmark::~managementBenchmark(){}

bool managementBenchmark::benchWhatInBenchWhatVec(benchWhat checkBenchWhatInVec)
{
	std::vector<benchWhat>::iterator it = std::find(mBenchWhat_vec.begin(), mBenchWhat_vec.end(), checkBenchWhatInVec);
	if (it != mBenchWhat_vec.end())
	{
		return true;
	}

	return false;
}

bool managementBenchmark::benchSuperFct()
{
	std::vector<bool> workTheSystem_benchmark;
	bool bechmarkAll = benchWhatInBenchWhatVec(benchWhat::bALL);

	// benchmark ray tracing
	if (benchWhatInBenchWhatVec(benchWhat::bRayTrac) || bechmarkAll)
	{
		BenchRayTracing benchRT;
		bool checkSpeedRayTraching = benchRT.benchmarkRayTracing_superFct();
		workTheSystem_benchmark.push_back(checkSpeedRayTraching);
	}

	// benchmark genetic and DLS
	if (benchWhatInBenchWhatVec(benchWhat::bGeneticAndDLS) || bechmarkAll)
	{
		benchGeneticAndDLS benchGenAndDLS;
		bool checkBenchGeneticAndDLS = benchGenAndDLS.testSpeedGeneticAndDLS();
		workTheSystem_benchmark.push_back(checkBenchGeneticAndDLS);
	}
	// benchmark ray aiming
	if (benchWhatInBenchWhatVec(benchWhat::bRayAiming) || bechmarkAll)
	{
		BenchRayAiming benchRayAiming;
		bool checkBenchRayAiming = benchRayAiming.benchRayAiming_superFct();
		workTheSystem_benchmark.push_back(checkBenchRayAiming);
	}



	bool checkBenchmark = Math::checkTrueOfVectorElements(workTheSystem_benchmark);
	return checkBenchmark;

}