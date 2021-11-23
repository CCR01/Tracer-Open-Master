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



class testLensReplaceAndOptimize_statistic_twoLensSystem
{
public:
	testLensReplaceAndOptimize_statistic_twoLensSystem();
	~testLensReplaceAndOptimize_statistic_twoLensSystem();

	// do the statistic evaluation left to right , right to left, max seidel, min seidel
	std::vector<saveLRaO_statistic> doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example);
	std::vector<saveLRaO_GeneticAndDLS_12_statistic> doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example);

	// load importent parameter
	void loadImportantParameter();
	// debug mode
	void turn_ON_debugMode();
	void turn_OFF_debugMode();
	// export all statistic data replace two lenses
	void exportAllStatisticDataReplaceTwoLenses();
	// export all statistic data replace three lenses
	void exportAllStatisticDataReplace_TWO_LensesGeneticAndDLS_12();

	// *** obj ***
	// super fct
	bool testLRaO_stat_twoLensSystem_superFct_obj();
	// E0
	bool testLRaO_stat_twoLensSystem_E0(std::string example);
	// E1
	bool testLRaO_stat_twoLensSystem_E1(std::string example);
	//E2
	bool testLRaO_stat_twoLensSystem_E2(std::string example);
	//E3
	bool testLRaO_stat_twoLensSystem_E3(std::string example);
	//E4
	bool testLRaO_stat_twoLensSystem_E4(std::string example);
	//E5
	bool testLRaO_stat_twoLensSystem_E5(std::string example);
	//E6
	bool testLRaO_stat_twoLensSystem_E6(std::string example);
	//E7
	bool testLRaO_stat_twoLensSystem_E7(std::string example);
	//E8
	bool testLRaO_stat_twoLensSystem_E8(std::string example);
	//E9
	bool testLRaO_stat_twoLensSystem_E9(std::string example);
	//E10
	bool testLRaO_stat_twoLensSystem_E10(std::string example);
	// E11
	bool testLRaO_stat_twoLensSystem_E11(std::string example);
	// E12
	bool testLRaO_stat_twoLensSystem_E12(std::string example);
	// E13
	bool testLRaO_stat_twoLensSystem_E13(std::string example);
	// E14
	bool testLRaO_stat_twoLensSystem_E14(std::string example);
	// E15
	bool testLRaO_stat_twoLensSystem_E15(std::string example);
	// E16
	bool testLRaO_stat_twoLensSystem_E16(std::string example);
	// E17
	bool testLRaO_stat_twoLensSystem_E17(std::string example);
	// E18
	bool testLRaO_stat_twoLensSystem_E18(std::string example);
	// E19
	bool testLRaO_stat_twoLensSystem_E19(std::string example);

	// *** inf ***
	// super fct
	bool testLRaO_stat_twoLensSystem_superFct_inf();
	// E0
	bool testLRaO_stat_twoLensSystem_EX_inf(std::string example);
	// *** ***

private:

	bool mInf{};
	bool mObj{};

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

	// field angles
	real mFieldAngel_X_0{};
	real mFieldAngel_Y_0{};
	real mFieldAngle_Y_707{};
	real mFieldAngle_Y_10{};
	std::vector<real> mFieldAngle_Vec_X{};
	std::vector<real> mFieldAngle_Vec_Y{};

	real mTolerance{};
	unsigned int mRings{};
	unsigned int mArms{};

	defaultParaDLS mDefaulParaDLS{};
	defaultParaGenetic mDefaultParameterGenetic{};
	real mPopulation{};

	std::vector<std::vector<saveLRaO_statistic>> mSaveAllResults{};
	std::vector<std::vector<saveLRaO_GeneticAndDLS_12_statistic>> mSaveAllResults_TWO_LensSystem{};
	bool mDebugMode{};

	unsigned int mNumberBestFitLenses{};
};

