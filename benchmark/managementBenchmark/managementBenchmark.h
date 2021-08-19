#pragma once
#include <vector>

enum class benchWhat {bALL, bNothing, bRayTrac, bGeneticAndDLS, bRayAiming };

class managementBenchmark
{
public:
	managementBenchmark();
	managementBenchmark(std::vector<benchWhat> benchWhat_vec);
	~managementBenchmark();

	bool benchWhatInBenchWhatVec(benchWhat checkBenchWhatInVec);
	bool benchSuperFct();

private:
	std::vector<benchWhat> mBenchWhat_vec;
};


