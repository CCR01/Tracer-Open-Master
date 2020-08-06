#pragma once

// glass catalogue
#include "..\..\Glasses\Glasses.h"

// interactions
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"

// ray aiming
#include "..\..\RayAiming\RayAiming.h"

class testRayAiming_multiThreads_12
{
public:
	testRayAiming_multiThreads_12();
	~testRayAiming_multiThreads_12();

	bool testRayAiming_multiThreads_12_superFct_obj();
	bool testRayAiming_multiThreads_12_E0_obj();

	// load important stuff
	void loadImportantStuff();

private:

	defaultRayAimingStruct mDefaulRayAiming;

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

	std::vector<VectorStructR3> startOptA_vec{};


	unsigned int mRings{};
	unsigned int mArms{};

	Light_LLT mLight587{};
	real mStartRefIndexAir{};
};

