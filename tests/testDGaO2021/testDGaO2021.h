#pragma once

// optical System element
#include "..\..\OpticalSystemElement\OpticalSystemElement.h"

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

// target cardenal points
#include "..\..\OptimizeSystem\importantOptimizeStructs.h"

class testDGaO2021
{
public:
	testDGaO2021();
	~testDGaO2021();

	void loadImportantValues();
	void turn_ON_DebugMode();
	void turn_OFF_DebugMode();

	// *** ***
	bool testDGaO2021_superFct();
	// *** ***

	// *** E0 ***
	bool checkE0_DGaO2021();
	// check the start system
	bool E0_checkStartSystem();
	// check optimize start system
	bool E0_checkOptimizeStartSystem_DoOptimization();
	// find best lenses in optimized system
	bool E0_findBestLensesInOptimizedSystem();
	// check Lens replace and optimize leftToRight
	bool E0_checkLensReplaceAndOptimizeLeftToRight();
	// load optimized System
	bool E0_loadOptimizedSystem();
	// load Replaced System
	bool E0_loadReplacedSystem_leftToRight();
	// do image simulation with E0 first optimized system
	bool E0_checkImageSimulationFirstOptimization();
	// do image simulation with E0 replaced system
	bool E0_checkImageSimulationReplacedSystem();
	// replace lens 0 and optimize
	bool replaceLenses_andOptimize_stepByStep();
	// find lenses for first optimized system
	bool findLensesForFirstOptimizedSystem();
	// replace left to right and image simulation
	bool E0_replace_LeftToRight_andImaSim();
	// replace all sequences and image simulation
	bool E0_replace_AllSequences_andImaSim();
	// *** ***

	// *** E1 ***
	bool checkE1_DGaO2021();
	bool E1_checkStartSystem();
	bool E1_loadFirstOptimizedSystem();
	bool E1_checkOptimizeStartSystem_DoOptimization();
	bool E1_checkLensReplaceAndOptimizeLeftToRight();
	bool E1_loadReplacedSystem_leftToRight();
	bool E1_checkImageSimulationReplacedSystem_leftToRight();
	bool E1_improveImageQuality_ReplacedLeftToRight();

	bool E1_LoadRepalceSystem_allPosSequences();
	bool E1_checkLensReplaceAndOptimizeAllPossibleSequencesAndImaSim();
	bool E1_imaSimLensReplacedAllSequences();
	bool E1_improveImageQuality_AllPossibleSequences();
	// *** ***

private:

	// *** E0 ***
	// startOpticalSystem
	OpticalSystemElement mStartOpticalSystem_E0{};
	OpticalSystemElement mOptimizedOpticalSystemEle_E0{};
	OpticalSystemElement mReplacedOpticalSystemEle_E0{};
	std::string mLocation_E0{};
	std::string mLocation_E0_LeftToRight{};
	std::string mLocation_E0_LeftToRight_stepByStep{};
	std::string mLocation_E0_RightToLeft{};
	std::string mLocation_E0_allPosSequences{};
	// *** ***

	// *** E1 ***
	OpticalSystemElement mStartOpticalSystem_E1{};
	OpticalSystemElement mOptimizedOpticalSystemEle_E1{};
	OpticalSystemElement mReplacedOpticalSystemEle_E1_leftToRight{};
	OpticalSystemElement mReplacedOpticalSystemEle_E1_allSequences{};
	std::string mLocation_E1{};
	std::string mLocation_E1_LeftToRight{};
	std::string mLocation_E1_allSequences{};
	// *** ***

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
	VectorStructR3 mField707{};
	VectorStructR3 mField1000{};
	std::vector<VectorStructR3> mField_vec{};

	real mTolerance{};
	unsigned int mRings{};
	unsigned int mArms{};

	defaultParaDLS mDefaulParaDLS{};
	defaultParaGenetic mDefaultParameterGenetic{};
	real mPopulation{};

	targetCardinalPointsStruct mTargetCarPoints{};

	bool mDebugMode{};

	real mTargetMag{};
	real mTargetWFNO{};

	unsigned int mNumberBestFitLenses{};
};

