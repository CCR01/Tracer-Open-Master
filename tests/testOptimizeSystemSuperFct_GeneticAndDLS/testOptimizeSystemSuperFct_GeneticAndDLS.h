#pragma once

// glass catalogue
#include "..\..\Glasses\Glasses.h"

// interactions
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"


#include "..\..\OptimizeSystem\OptimizeSystemSuperFct_GeneticAndDLS.h"



class testOptimizeSystemSuperFct_GeneticAndDLS
{
public:
	testOptimizeSystemSuperFct_GeneticAndDLS();
	~testOptimizeSystemSuperFct_GeneticAndDLS();

	// super function
	bool testOptimizeSystemSysSupFct_GeneticDLS();

	//E0
	bool checkE0_optSysSupFct_GeneticAndDLS();

	//E1
	bool checkE1_optSysSupFct_GeneticAndDLS();

	//E2
	bool checkE2_optSysSupFct_GeneticAndDLS();

	//E3
	bool checkE3_optSysSupFct_GeneticAndDLS();

	//E4
	bool checkE4_optSysSupFct_GeneticAndDLS();

	//E5
	bool checkE5_optSysSupFct_GeneticAndDLS();

	//E6
	bool checkE6_optSysSupFct_GeneticAndDLS();

	//E7
	bool checkE7_optSysSupFct_GeneticAndDLS();

	//E8
	bool checkE8_optSysSupFct_GeneticAndDLS();

	//E9
	bool checkE9_optSysSupFct_GeneticAndDLS();

	//E10
	bool checkE10_optSysSupFct_GeneticAndDLS();


	// load important stuff
	void loadImportantStuff();


private:

	real mTolerance{};
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

	defaultParaGenetic mDefaultParaGenetic{};
	defaultParaDLS mDefaultParamDLS{};

	unsigned int mRings{};
	unsigned int mArms{};

	real mPopulation{};
};

