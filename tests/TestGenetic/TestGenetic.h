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

	// E4
	bool testE4();

	// E5
	bool testE5();

	// E6
	bool testE6();

	// E7
	bool testE7();

	// E8
	bool testE8();

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


	// test target cardinal points super function
	bool testCardinalPointsSuperFct();
	// test target EFL
	bool testTargetEFL_genetic_obj();
	bool testTargetEFL_genetic_inf();
	


private:

	DoNothingInteraction_LLT mDoNothing{};
	RefractedRay_LLT mRefrac{};
	Absorb_LLT mAbsorb{};

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
	std::vector<real> mWavelength_FdC_vec{};

	// wave 550 vec
	std::vector<real> mWave550_vec;
	// start point optical axis
	std::vector<VectorStructR3> startOptA_vec;

	// field
	VectorStructR3 mField0{};
	VectorStructR3 mField1{};
	VectorStructR3 mField2{};
	VectorStructR3 mField3{};
	VectorStructR3 mField4{};
	std::vector<VectorStructR3> mFields_vec012{};
	std::vector<VectorStructR3> mFields_vec024{};

	// angles
	real mAngle_X0{};
	std::vector<real> mAngle000_X_vec{};

	real mAngle_Y0{};
	real mAngle_Y1{};
	real mAngle_Y2{};
	std::vector<real> mAngle012_Y_vec{};

	real mTolerance_RMS;
	real mTolerance_target;
	
};
