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

	// *** object ***
	bool testLensReplaceAndOptimize_superFct_object();
	// E0
	bool testLensReplaceAndOptimize_E0_obj();
	// E1
	bool testLensReplaceAndOptimize_E1_obj();
	// E2
	bool testLensReplaceAndOptimize_E2_obj();
	// E3
	bool testLensReplaceAndOptimize_E3_obj();
	// E4
	bool testLensReplaceAndOptimize_E4_obj();
	// E5
	bool testLensReplaceAndOptimize_E5_obj();
	// E6
	bool testLensReplaceAndOptimize_E6_obj();
	// E7
	bool testLensReplaceAndOptimize_E7_obj();
	// E8
	bool testLensReplaceAndOptimize_E8_obj();
	// E9
	bool testLensReplaceAndOptimize_E9_obj();
	// E10
	bool testLensReplaceAndOptimize_E10_obj();
	// *** ***

	// *** inf ***
	bool testLensReplaceAndOptimize_superFct_infinity();
	// E0
	bool testLensReplaceAndOptimize_E0_inf();
	// *** ***

private:

	RefractedRay_LLT mRefrac{};
	Absorb_LLT mAbsorb{};
	DoNothingInteraction_LLT mDoNot{};

	Light_LLT mDefaulLight550{};
	glass mGlasses{};

};


