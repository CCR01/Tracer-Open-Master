#pragma once

// glass catalogue
#include "..\..\Glasses\Glasses.h"

// interactions
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"

#include "..\..\OptimizeSystem\DampedLeastSquares.h"

class testDLS_multiThreads_12
{
public:
	testDLS_multiThreads_12();
	~testDLS_multiThreads_12();

	// test super function
	bool testSuperFunction();

	// E0
	bool checkE0();

	// load important stuff
	void loadImportantStuff();

private:

	real mMinTolerance{};
	real mExtendeTolerance{};
	glass glasses{};

	RefractedRay_LLT refrac{};
	Absorb_LLT absorb{};
	DoNothingInteraction_LLT doNothing{};

	// wave
	real mWave587{};
	real mWave486{};
	real mWave656{};
	std::vector<real> mWavelength_vec{};

	// field
	VectorStructR3 mField0{};
	VectorStructR3 mField1{};
	VectorStructR3 mField2{};
	VectorStructR3 mField3{};
	VectorStructR3 mField4{};
	std::vector<VectorStructR3> mFields_vec012{};
	std::vector<VectorStructR3> mFields_vec024{};

	defaultParaDLS mDefaultParamDLS{};

	unsigned int mRings{};
	unsigned int mArms{};
;
};

