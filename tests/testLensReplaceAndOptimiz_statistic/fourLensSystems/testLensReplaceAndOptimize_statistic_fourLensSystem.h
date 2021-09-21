#pragma once
#pragma once
// interactions
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"

// glass catalogue
#include "..\..\Glasses\Glasses.h"

// DLS
#include "..\..\OptimizeSystem\DampedLeastSquares.h"

// genetic and DLS 12
#include "..\..\OptimizeSystem\Genetic.h"

// structs for statistic evaluation
#include "..\testLensRepAndOptimize_statisticStruct.h"

class testLensReplaceAndOptimize_statistic_FOUR_LensSystem
{
public:
	testLensReplaceAndOptimize_statistic_FOUR_LensSystem();
	~testLensReplaceAndOptimize_statistic_FOUR_LensSystem();

	// do the statistic evaluation
	std::vector<saveLRaO_GeneticAndDLS_12_statistic> doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example);

	// load importent parameter
	void loadImportantParameter();
	// debug mode
	void turn_ON_debugMode();
	void turn_OFF_debugMode();
	// export all statistic data replace two lenses
	void exportAllStatisticDataReplace_FOUR_LensesGeneticAndDLS_12();

	// super fct four lens system
	bool testLRaO_stat_FOUR_lensSystem_superFct();
	// E0 four lens system
	bool testLRaO_stat_FOUR_lensSystem_E0(std::string example);

private:

	// load glass catalog
	glass mGlasses{};
	// interactions
	DoNothingInteraction_LLT mDoNot{};
	RefractedRay_LLT mRefrac{};
	Absorb_LLT mAbsorb{};

	// light FdC
	real mWave587d{};
	real mWave486F{};
	real mWave656C{};
	std::vector<real> mWavelength_FdV_vec{};
	Light_LLT mLight587{};
	Light_LLT mLight486{};
	Light_LLT mLight656{};
	std::vector<Light_LLT> mLight_FdC_Vec{};


	// field obj
	VectorStructR3 mField0{};
	VectorStructR3 mField283{};
	VectorStructR3 mField4{};
	std::vector<VectorStructR3> mField_vec{};

	real mTolerance{};
	unsigned int mRings{};
	unsigned int mArms{};

	defaultParaDLS mDefaulParaDLS{};
	defaultParaGenetic mDefaultParameterGenetic{};
	real mPopulation{};

	std::vector<std::vector<saveLRaO_GeneticAndDLS_12_statistic>> mSaveAllResults_FOUR_LensSystem{};
	bool mDebugMode{};

	unsigned int mNumberBestFitLenses{};
};
