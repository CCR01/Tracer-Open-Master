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

class testLensReplaceAndOptimize_statistic_FIVE_LensSystem
{
public:
	testLensReplaceAndOptimize_statistic_FIVE_LensSystem();
	~testLensReplaceAndOptimize_statistic_FIVE_LensSystem();

	// do the statistic evaluation
	std::vector<saveLRaO_GeneticAndDLS_12_statistic> doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_obj(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example);
	std::vector<saveLRaO_GeneticAndDLS_12_statistic> doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_inf(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example);

	// do the statistic evaluation left to right, right to left, max seidel, min seidel
	std::vector<saveLRaO_GeneticAndDLS_12_statistic>  doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example);
	std::vector<saveLRaO_GeneticAndDLS_12_statistic>  doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example);


	// load importent parameter
	void loadImportantParameter();
	// debug mode
	void turn_ON_debugMode();
	void turn_OFF_debugMode();
	// export all statistic data replace FIVE lenses
	void exportAllStatisticDataReplace_FIVE_LensesGeneticAndDLS_12();

	// super fct FIVE lens system
	bool testLRaO_stat_FIVE_lensSystem_superFct_obj();
	// E0 FIVE lens system
	bool testLRaO_stat_FIVE_lensSystem_E0(std::string example);
	// E1 FIVE lens system
	bool testLRaO_stat_FIVE_lensSystem_E1(std::string example);
	// E2 FIVE lens system
	bool testLRaO_stat_FIVE_lensSystem_E2(std::string example);
	// E3 FIVE lens system
	bool testLRaO_stat_FIVE_lensSystem_E3(std::string example);
	// E4 FIVE lens system
	bool testLRaO_stat_FIVE_lensSystem_E4(std::string example);
	// E5 FIVE lens system
	bool testLRaO_stat_FIVE_lensSystem_E5(std::string example);
	// E6 FIVE lens system
	bool testLRaO_stat_FIVE_lensSystem_E6(std::string example);
	// E7 FIVE lens system
	bool testLRaO_stat_FIVE_lensSystem_E7(std::string example);
	// E8 FIVE lens system
	bool testLRaO_stat_FIVE_lensSystem_E8(std::string example);
	// E9 FIVE lens system
	bool testLRaO_stat_FIVE_lensSystem_E9(std::string example);
	// E10 FIVE lens system
	bool testLRaO_stat_FIVE_lensSystem_E10(std::string example);
	// E11 FIVE lens system
	bool testLRaO_stat_FIVE_lensSystem_E11(std::string example);
	// E12 FIVE lens system
	bool testLRaO_stat_FIVE_lensSystem_E12(std::string example);
	// E13 FIVE lens system
	bool testLRaO_stat_FIVE_lensSystem_E13(std::string example);
	// E14 FIVE lens system
	bool testLRaO_stat_FIVE_lensSystem_E14(std::string example);
	// E15 FIVE lens system
	bool testLRaO_stat_FIVE_lensSystem_E15(std::string example);
	// E16 FIVE lens system
	bool testLRaO_stat_FIVE_lensSystem_E16(std::string example);
	// E17 FIVE lens system
	bool testLRaO_stat_FIVE_lensSystem_E17(std::string example);
	// E18 FIVE lens system
	bool testLRaO_stat_FIVE_lensSystem_E18(std::string example);
	// E19 FIVE lens system
	bool testLRaO_stat_FIVE_lensSystem_E19(std::string example);


	// *** inf ***
	// super fct
	bool testLRaO_stat_FIVE_LensSystem_superFct_inf();
	// E0
	bool testLRaO_stat_FIVE_LensSystem_EX_inf(std::string example);
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

	std::vector<std::vector<saveLRaO_GeneticAndDLS_12_statistic>> mSaveAllResults_FIVE_LensSystem{};
	bool mDebugMode{};

	unsigned int mNumberBestFitLenses{};
};



