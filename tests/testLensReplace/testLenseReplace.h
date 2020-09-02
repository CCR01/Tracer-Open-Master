#pragma once

//interactions
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"

// include the glas cataloge
#include "..\..\Glasses\Glasses.h"

class testLensReplace
{
public:
	testLensReplace();
	~testLensReplace();

	void loadDefaulParameter_testLensReplace();

	bool testLensReplace_superFct();
	bool testLensReplace_E0();
	bool testLensReplace_E1();
	bool testLensReplace_E2();
	bool testLensReplace_E3();
	

private:

	RefractedRay_LLT mRefrac{};
	Absorb_LLT mAbsorb{};
	DoNothingInteraction_LLT mDoNot{};

	Light_LLT mDefaulLight550{};
	glass mGlasses{};

	VectorStructR3 mStartOptA{};
	std::vector<VectorStructR3> mStartOptA_vec{};

	real mWave550{};
	std::vector<real> mWave500_vec{};

	real mGlobalTolerance;



};

