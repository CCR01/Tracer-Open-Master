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
	std::vector<saveLRaO_GeneticAndDLS_12_statistic> doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_obj(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example);
	std::vector<saveLRaO_GeneticAndDLS_12_statistic> doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_inf(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example);

	// do the statistic evaluation left to right , right to left, max seidel, min seidel
	std::vector<saveLRaO_GeneticAndDLS_12_statistic>  doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example);
	std::vector<saveLRaO_GeneticAndDLS_12_statistic>  doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example);


	// load importent parameter
	void loadImportantParameter();
	// debug mode
	void turn_ON_debugMode();
	void turn_OFF_debugMode();
	// export all statistic data replace two lenses
	void exportAllStatisticDataReplace_FOUR_LensesGeneticAndDLS_12();

	// super fct four lens system
	bool testLRaO_stat_FOUR_lensSystem_superFct_obj();
	// E0 four lens system
	bool testLRaO_stat_FOUR_lensSystem_E0(std::string example);
	// E1 four lens system
	bool testLRaO_stat_FOUR_lensSystem_E1(std::string example);
	// E2 four lens system
	bool testLRaO_stat_FOUR_lensSystem_E2(std::string example);
	// E3 four lens system
	bool testLRaO_stat_FOUR_lensSystem_E3(std::string example);
	// E4 four lens system
	bool testLRaO_stat_FOUR_lensSystem_E4(std::string example);
	// E5 four lens system
	bool testLRaO_stat_FOUR_lensSystem_E5(std::string example);
	// E6 four lens system
	bool testLRaO_stat_FOUR_lensSystem_E6(std::string example);
	// E7 four lens system
	bool testLRaO_stat_FOUR_lensSystem_E7(std::string example);
	// E8 four lens system
	bool testLRaO_stat_FOUR_lensSystem_E8(std::string example);
	// E9 four lens system
	bool testLRaO_stat_FOUR_lensSystem_E9(std::string example);
	// E10 four lens system
	bool testLRaO_stat_FOUR_lensSystem_E10(std::string example);
	// E11 four lens system
	bool testLRaO_stat_FOUR_lensSystem_E11(std::string example);
	// E12 four lens system
	bool testLRaO_stat_FOUR_lensSystem_E12(std::string example);
	// E13 four lens system
	bool testLRaO_stat_FOUR_lensSystem_E13(std::string example);
	// E14 four lens system
	bool testLRaO_stat_FOUR_lensSystem_E14(std::string example);
	// E15 four lens system
	bool testLRaO_stat_FOUR_lensSystem_E15(std::string example);
	// E16 four lens system
	bool testLRaO_stat_FOUR_lensSystem_E16(std::string example);
	// E17 four lens system
	bool testLRaO_stat_FOUR_lensSystem_E17(std::string example);
	// E18 four lens system
	bool testLRaO_stat_FOUR_lensSystem_E18(std::string example);
	// E19 four lens system
	bool testLRaO_stat_FOUR_lensSystem_E19(std::string example);


	//// E20 four lens system
	//bool testLRaO_stat_FOUR_lensSystem_E20(std::string example);
	//// E21 four lens system
	//bool testLRaO_stat_FOUR_lensSystem_E21(std::string example);
	//// E22 four lens system
	//bool testLRaO_stat_FOUR_lensSystem_E22(std::string example);
	//// E23 four lens system
	//bool testLRaO_stat_FOUR_lensSystem_E23(std::string example);
	//// E24 four lens system
	//bool testLRaO_stat_FOUR_lensSystem_E24(std::string example);
	//// E25 four lens system
	//bool testLRaO_stat_FOUR_lensSystem_E25(std::string example);
	//// E26 four lens system
	//bool testLRaO_stat_FOUR_lensSystem_E26(std::string example);
	//// E27 four lens system
	//bool testLRaO_stat_FOUR_lensSystem_E27(std::string example);
	//// E28 four lens system
	//bool testLRaO_stat_FOUR_lensSystem_E28(std::string example);
	//// E29 four lens system
	//bool testLRaO_stat_FOUR_lensSystem_E29(std::string example);
	//// E30 four lens system
	//bool testLRaO_stat_FOUR_lensSystem_E30(std::string example);
	//// E31 four lens system
	//bool testLRaO_stat_FOUR_lensSystem_E31(std::string example);
	//// E32 four lens system
	//bool testLRaO_stat_FOUR_lensSystem_E32(std::string example);
	//// E33 four lens system
	//bool testLRaO_stat_FOUR_lensSystem_E33(std::string example);
	//// E34 four lens system
	//bool testLRaO_stat_FOUR_lensSystem_E34(std::string example);
	//// E35 four lens system
	//bool testLRaO_stat_FOUR_lensSystem_E35(std::string example);
	//// E36 four lens system
	//bool testLRaO_stat_FOUR_lensSystem_E36(std::string example);
	//// E37 four lens system
	//bool testLRaO_stat_FOUR_lensSystem_E37(std::string example);
	//// E38 four lens system
	//bool testLRaO_stat_FOUR_lensSystem_E38(std::string example);
	//// E39 four lens system
	//bool testLRaO_stat_FOUR_lensSystem_E39(std::string example);

	// *** inf ***
	// super fct
	bool testLRaO_stat_FOUR_LensSystem_superFct_inf();
	// E0
	bool testLRaO_stat_FOUE_LensSystem_EX_inf(std::string example);
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

	std::vector<std::vector<saveLRaO_GeneticAndDLS_12_statistic>> mSaveAllResults_FOUR_LensSystem{};
	bool mDebugMode{};

	unsigned int mNumberBestFitLenses{};
};
