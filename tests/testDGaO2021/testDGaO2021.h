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

	// *** E2 ***
	bool checkE2_DGaO2021();
	bool E2_checkStartSystem();
	bool E2_checkOptimizeStartSystem_DoOptimization();
	bool E2_loadFirstOptimizedSystem();
	bool E2_lensReplaceAllSequences();
	bool E2_loadReplacedSystemAllSequences();
	bool E2_imageSimulationWithReplacesSysAllSequences();
	// filtering sharp image
	bool E2_improveImageQuality_AllPossibleSequences_refImage_UM_DE_WD();
	bool E2_improveImageQuality_AllPossibleSequences_refImage_UM();
	bool E2_improveImageQuality_AllPossibleSequences_refImage_DE();
	bool E2_improveImageQuality_AllPossibleSequences_refImage_WD();
	// filtering blur and noise
	bool E2_improveImageQuality_AllPossibleSequences_BlurAndNois_UM_DE_WD();
	bool E2_improveImageQuality_AllPossibleSequences_BlurAndNois_UM();
	bool E2_improveImageQuality_AllPossibleSequences_BlurAndNois_DE();
	bool E2_improveImageQuality_AllPossibleSequences_BlurAndNois_WD();
	// *** ***

	// *** E3 ***
	bool checkE3_DGaO2021();
	bool E3_checkStartSystem();
	bool E3_checkOptimizeStartSystem_DoOptimization();
	bool E3_lensReplace();
	bool E3_loadReplaceSystemLeftToRight();
	bool E3_doImageSimulation_replayedSysLeftToRight();
	// filtering sharp image
	bool E3_improveImageQuality_AllPossibleSequences_refImage_UM_DE_WD();
	bool E3_improveImageQuality_AllPossibleSequences_refImage_UM();
	bool E3_improveImageQuality_AllPossibleSequences_refImage_DE();
	bool E3_improveImageQuality_AllPossibleSequences_refImage_WD();
	// filtering blur and noise
	bool E3_improveImageQuality_AllPossibleSequences_BlurAndNoise_UM_DE_WD();
	bool E3_improveImageQuality_AllPossibleSequences_BlurAndNois_UM();
	bool E3_improveImageQuality_AllPossibleSequences_BlurAndNois_DE();
	bool E3_improveImageQuality_AllPossibleSequences_BlurAndNois_WD();
	// *** *** //

	// *** E4 ***
	bool checkE4_superFct();
	bool E4_checkStartSystem();
	bool E4_checkOptimizeStartSystem_DoOptimization();
	bool E4_loadOptimizedSystemFirst();
	bool E4_lensReplace();
	// *** *** //

	// *** E21 ***
	bool checkE21_fromStatLensRepl_threeLensSys();
	bool loadBestReplaceSystemE21_mono();
	bool optimizeThicknessesAirSpace_poly();
	bool loadReplacedSysE21_poly();
	bool doImageSimulationE21_poly();
	// filtering sharp image
	bool E21_improveImageQuality_AllPossibleSequences_refImage_UM_DE_WD();
	bool E21_improveImageQuality_AllPossibleSequences_refImage_UM();
	bool E21_improveImageQuality_AllPossibleSequences_refImage_DE();
	bool E21_improveImageQuality_AllPossibleSequences_refImage_WD();
	// filtering blur and noise
	bool E21_improveImageQuality_AllPossibleSequences_BlurAndNoise_UM_DE_WD();
	bool E21_improveImageQuality_AllPossibleSequences_BlurAndNois_UM();
	bool E21_improveImageQuality_AllPossibleSequences_BlurAndNois_DE();
	bool E21_improveImageQuality_AllPossibleSequences_BlurAndNois_WD();



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
	std::string mLocation_E2;
	std::string mLocation_E2_allSequences;
	// *** ***

	// *** E2 ***
	OpticalSystemElement mStartOpticalSystem_E2{};
	OpticalSystemElement mOptimizedOpticalSystemEle_E2{};
	OpticalSystemElement mReplacedOpticalSystemEle_E2_allSequences{};
	// *** ***

	// *** E3 ***
	OpticalSystemElement mStartOpticalSystem_E3{};
	OpticalSystemElement mOptimizedOpticalSystemEle_E3{};
	OpticalSystemElement mReplacedOpticalSystemEle_E3_leftToRight{};
	std::string mLocationE3{};
	VectorStructR3 mField_0{};
	VectorStructR3 mField_176{};
	VectorStructR3 mField_250{};
	std::vector<VectorStructR3> mField_E3_vec{};
	targetCardinalPointsStruct mTargetCarPoints_E3{};
	std::string mLocation_E3_leftToRight;
	// *** ***

	// *** E4 ***
	std::string mLocation_E4{};
	OpticalSystemElement mStartOpticalSystem_E4{};
	OpticalSystemElement mOptimizedOpticalSystemEle_E4{};
	VectorStructR3 mField_17_67{};
	VectorStructR3 mField_25{};
	std::vector<VectorStructR3> mField_E4_vec{};
	targetCardinalPointsStruct mTargetCarPoints_E4{};
	// *** ***

	// *** E21 ***
	OpticalSystemElement mReplacedOpticalSystemEle_E21_allSequences_mono{};
	OpticalSystemElement mReplacedOpticalSystemEle_E21_allSequences_poly{};
	std::string mLocationE21{};
	VectorStructR3 mField_E21_0{};
	VectorStructR3 mField_E21_283{};
	VectorStructR3 mField_E21_4{};
	std::vector<VectorStructR3> mField_E21_vec{};
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

