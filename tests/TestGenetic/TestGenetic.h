#pragma once

// interactions
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"

// glass catalogue
#include "..\..\Glasses\Glasses.h"

class TestGenetic
{
public:
	TestGenetic();
	~TestGenetic();

	// super function
	bool testGeneticSuperFunc();

	// E0
	bool testE0();

	// E1
	bool testE1();

	// E2
	bool testE2();

	// E3
	bool testE3();

	// test geneartion modes
	bool testGenerationModes(real min, real max, real sampling, unsigned int maxInteration);
	// random generation mode
	bool testRandomMode(real min, real max, real sampling, unsigned int maxInteration);
	// clever sample Mode
	bool testClerverSampleMode(real min, real max, real sampling, unsigned int maxInteration);
	// normal distribution mode
	bool testNormalDistributionMode(real min, real max, real sampling, unsigned int maxInteration);
	// normal distribution default mode
	bool testNormalDistributionDeefaultMode(real min, real max, real sampling, unsigned int maxInteration);

private:

	DoNothingInteraction_LLT doNothing{};
	RefractedRay_LLT refrac{};
	Absorb_LLT absorb{};

	glass glasses{};

	MaterialSellmeier1 glass1{};
	MaterialSellmeier1 glass15{};
	MaterialSellmeier1 glass16{};

	Light_LLT Light_550{};
	std::vector<Light_LLT> lichtVec550{};
	
	std::vector<VectorStructR3> fields_vec_optA{};
	std::vector<real> wavelenth_vec_550{};

	unsigned int defaultRings_6{};
	unsigned int defaultArms_8{};


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

	double mTolerance;
};
