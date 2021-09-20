#pragma once
//interactions
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"

// include the glas cataloge
#include "..\..\Glasses\Glasses.h"

class testLensReplaceAndOptimize
{
public:
	testLensReplaceAndOptimize();
	~testLensReplaceAndOptimize();

	bool testLensReplaceAndOptimize_superFct();
	// E0
	bool testLensReplaceAndOptimize_E0();
	// E1
	bool testLensReplaceAndOptimize_E1();
	// E2
	bool testLensReplaceAndOptimize_E2();
	// E3
	bool testLensReplaceAndOptimize_E3();
	// E4
	bool testLensReplaceAndOptimize_E4();
	// E5
	bool testLensReplaceAndOptimize_E5();
	// E6
	bool testLensReplaceAndOptimize_E6();
	// E7
	bool testLensReplaceAndOptimize_E7();
	// E8
	bool testLensReplaceAndOptimize_E8();
	// E9
	bool testLensReplaceAndOptimize_E9();
	// E10
	bool testLensReplaceAndOptimize_E10();

private:

	RefractedRay_LLT mRefrac{};
	Absorb_LLT mAbsorb{};
	DoNothingInteraction_LLT mDoNot{};

	Light_LLT mDefaulLight550{};
	glass mGlasses{};

};


