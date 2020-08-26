#include "managementBenchmark.h"
#include <iostream>

#include "..\..\LowLevelTracing\Math_LLT.h"

#include "..\..\benchmark\benachRayTracing\benchRayTracing.h"
#include "..\..\benchmark\benchGeneticAndDLS\benchGeneticAndDLS.h"

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
	bool testAll = benchWhatInBenchWhatVec(benchWhat::bALL);

	// benchmark ray tracing
	if (benchWhatInBenchWhatVec(benchWhat::bRayTrac) || testAll)
	{
		benchRayTracing benchRT;
		bool checkSpeedRayTraching = benchRT.testSpeedRayTracing();
		workTheSystem_benchmark.push_back(checkSpeedRayTraching);
	}

	// benchmark genetic and DLS
	if (benchWhatInBenchWhatVec(benchWhat::bGeneticAndDLS) || testAll)
	{
		benchGeneticAndDLS benchGenAndDLS;
		bool checkBenchGeneticAndDLS = benchGenAndDLS.testSpeedGeneticAndDLS();
		workTheSystem_benchmark.push_back(checkBenchGeneticAndDLS);
	}



	bool checkBenchmark = Math::checkTrueOfVectorElements(workTheSystem_benchmark);
	return checkBenchmark;

}