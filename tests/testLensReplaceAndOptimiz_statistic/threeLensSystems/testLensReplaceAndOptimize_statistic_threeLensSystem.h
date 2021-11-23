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

class testLensReplaceAndOptimize_statistic_THREE_LensSystem
{
public:
	testLensReplaceAndOptimize_statistic_THREE_LensSystem();
	~testLensReplaceAndOptimize_statistic_THREE_LensSystem();



	// do the statistic evaluation
	std::vector<saveLRaO_GeneticAndDLS_12_statistic> doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example);
	std::vector<saveLRaO_GeneticAndDLS_12_statistic> doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_inf(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example);

	// do the statistic evaluation left to right , right to left, max seidel, min seidel
	std::vector<saveLRaO_GeneticAndDLS_12_statistic>  doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example);
	std::vector<saveLRaO_GeneticAndDLS_12_statistic>  doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example);

	// do the statistic evaluation left to right, right to left, max seidel, min seidel save intermediate results
	saveLRaO_GeneticAndDLS_12_statistic  doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj_saveIntermediateResults(OpticalSystemElement optSysEle, std::vector<real> wavelength_vec, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example, replaceSequence repSequence, unsigned int numberBestFitLenses);
	// do the statistic evaluation given sequence
	saveLRaO_GeneticAndDLS_12_statistic  doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_givenSequence(OpticalSystemElement optSysEle, std::vector<real> wavelength_vec, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example, std::vector<unsigned int> seqence_vec, unsigned int numberBestFitLenses);



	// load importent parameter
	void loadImportantParameter();
	// debug mode
	void turn_ON_debugMode();
	void turn_OFF_debugMode();
	// export all statistic data replace three lenses
	void exportAllStatisticDataReplace_THREE_LensesGeneticAndDLS_12();
	void exportDataReplace_THREE_LensesGeneticAndDLS_12(std::string location, std::string repSeq, saveLRaO_GeneticAndDLS_12_statistic dataToExport);

	// super fct three lens system
	bool testLRaO_stat_THREE_lensSystem_superFct_obj();
	// E0 three lens system
	bool testLRaO_stat_THREE_LensSystem_E0(std::string example);
	// E1 three lens system
	bool testLRaO_stat_THREE_LensSystem_E1(std::string example);
	// E2 three lens system
	bool testLRaO_stat_THREE_LensSystem_E2(std::string example);
	// E3 three lens system
	bool testLRaO_stat_THREE_LensSystem_E3(std::string example);
	// E4 three lens system
	bool testLRaO_stat_THREE_LensSystem_E4(std::string example);
	// E5 three lens system
	bool testLRaO_stat_THREE_LensSystem_E5(std::string example);
	// E6 three lens system
	bool testLRaO_stat_THREE_LensSystem_E6(std::string example);
	// E7 three lens system
	bool testLRaO_stat_THREE_LensSystem_E7(std::string example);
	// E8 three lens system
	bool testLRaO_stat_THREE_LensSystem_E8(std::string example);
	// E9 three lens system
	bool testLRaO_stat_THREE_LensSystem_E9(std::string example);
	// E10 three lens system
	bool testLRaO_stat_THREE_LensSystem_E10(std::string example);
	// E11 three lens system
	bool testLRaO_stat_THREE_LensSystem_E11(std::string example);
	// E12 three lens system
	bool testLRaO_stat_THREE_LensSystem_E12(std::string example);
	// E13 three lens system
	bool testLRaO_stat_THREE_LensSystem_E13(std::string example);
	// E14 three lens system
	bool testLRaO_stat_THREE_LensSystem_E14(std::string example);
	// E15 three lens system
	bool testLRaO_stat_THREE_LensSystem_E15(std::string example);
	// E16 three lens system
	bool testLRaO_stat_THREE_LensSystem_E16(std::string example);
	// E17 three lens system
	bool testLRaO_stat_THREE_LensSystem_E17(std::string example);
	// E18 three lens system
	bool testLRaO_stat_THREE_LensSystem_E18(std::string example);
	// E19 three lens system
	bool testLRaO_stat_THREE_LensSystem_E19(std::string example);
	// E20 three lens system
	bool testLRaO_stat_THREE_LensSystem_E20(std::string example);
	// E21 three lens system
	bool testLRaO_stat_THREE_LensSystem_E21(std::string example);
	// E22 three lens system
	bool testLRaO_stat_THREE_LensSystem_E22(std::string example);
	// E23 three lens system
	bool testLRaO_stat_THREE_LensSystem_E23(std::string example);
	// E24 three lens system
	bool testLRaO_stat_THREE_LensSystem_E24(std::string example);
	// E25 three lens system
	bool testLRaO_stat_THREE_LensSystem_E25(std::string example);
	// E26 three lens system
	bool testLRaO_stat_THREE_LensSystem_E26(std::string example);
	// E27 three lens system
	bool testLRaO_stat_THREE_LensSystem_E27(std::string example);
	// E28 three lens system
	bool testLRaO_stat_THREE_LensSystem_E28(std::string example);
	// E29 three lens system
	bool testLRaO_stat_THREE_LensSystem_E29(std::string example);
	// E30 three lens system
	bool testLRaO_stat_THREE_LensSystem_E30(std::string example);
	// E31 three lens system
	bool testLRaO_stat_THREE_LensSystem_E31(std::string example);
	// E32 three lens system
	bool testLRaO_stat_THREE_LensSystem_E32(std::string example);
	// E33 three lens system
	bool testLRaO_stat_THREE_LensSystem_E33(std::string example);
	// E34 three lens system
	bool testLRaO_stat_THREE_LensSystem_E34(std::string example);
	// E35 three lens system
	bool testLRaO_stat_THREE_LensSystem_E35(std::string example);
	// E36 three lens system
	bool testLRaO_stat_THREE_LensSystem_E36(std::string example);
	// E37 three lens system
	bool testLRaO_stat_THREE_LensSystem_E37(std::string example);
	// E38 three lens system
	bool testLRaO_stat_THREE_LensSystem_E38(std::string example);
	// E39 three lens system
	bool testLRaO_stat_THREE_LensSystem_E39(std::string example);




	// *** inf ***
	// super fct
	bool testLRaO_stat_THREE_LensSystem_superFct_inf();
	// E0
	bool testLRaO_stat_THREE_LensSystem_EX_inf(std::string example);
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
	std::vector<real> mWavelength_green_vec{};
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

	std::vector<std::vector<saveLRaO_GeneticAndDLS_12_statistic>> mSaveAllResults_Three_LensSystem{};
	bool mDebugMode{};

	unsigned int mNumberBestFitLenses{};

	replaceSequence mLeftToRight_repSeq{};
	replaceSequence mRightToLeft_repSeq{};
	replaceSequence mMaxSeidel_repSeq{};
	replaceSequence mMinSeidel_repSeq{};
	replaceSequence mAllSequences_repSeq{};

};



