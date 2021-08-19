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

// lens replace and optimize
#include "..\..\..\LensReplaceAndOptimize\LensReplaceAndOptimize.h"

struct saveLRaO_statistic
{
public:
	saveLRaO_statistic(unsigned int numberLensesInOptSys);
	~saveLRaO_statistic();

	void setMeritVal_DLS(real meritValDLS);
	real getMeritVaL_DLS();

	void setMeritVal_DLS_12(real meritValDLS12);
	real getMeritVal_DLS_12();

	void setMeritVal_GeneticAndDLS(real meritValGeneticAndDLS);
	real getMeritVaL_GeneticAndDLS();

	void setMeritVal_GeneticAndDLS_12(real meritValGeneticAndDLS12);
	real getMeritVaL_GeneticAndDLS_12();

	void setDurationTime_DLS(real DurationTimeDLS);
	real getDurationTime_DLS();

	void setDurationTime_DLS_12(real DurationTimeDLS12);
	real getDurationTime_DLS_12();

	void setDurationTime_GeneticAndDLS(real DurationTimeGeneticAndDLS);
	real getDurationTime_GeneticAndDLS();

	void setDurationTime_GeneticAndDLS_12(real DurationTimeGeneticAndDLS12);
	real getDurationTime_GeneticAndDLS_12();

	std::vector<unsigned int> getReplaceSequence_leftToRight();
	void setReplaceSequence_leftToRight(std::vector<unsigned int> repSeq_leftToRight);

	std::vector<unsigned int> getReplaceSequence_rightToLeft();
	void setReplaceSequence_rightToLeft(std::vector<unsigned int> repSeq_rightToLeft);

	std::vector<unsigned int> getReplaceSequence_maxSeidel();
	void setReplaceSequence_maxSeidel(std::vector<unsigned int> repSeq_maxSeidel);

	std::vector<unsigned int> getReplaceSequence_minSeidel();
	void setReplaceSequence_minSeidel(std::vector<unsigned int> repSeq_minSeidel);

	std::vector<unsigned int> getReplaceSequence_best();
	void setReplaceSequence_best(std::vector<unsigned int> repSeq_best);

	void calcBestOptimizationMethode();
	std::vector<optimizeMethode> getOptiMethode_sorted();

	std::vector<unsigned int> getBestLensNumberWasTaken();
	void setBestLensNumberWasTaken(unsigned int lensNumReplaced, unsigned bestLensNumWasTaken);

	unsigned int getNumberOfLensesInOptSys();
	void setNumberOfLensesInOptSys(unsigned int numberOfLenses);
	

private:
	std::vector<optimizeMethode> mOptiMethode_sorted{};
	replaceSequence mBestReplaceSequence{};

	// merit values
	real mMeritVal_DLS{};
	real mMeritVal_DLS_12{};
	real mMeritVal_GeneticAndDLS{};
	real mMeritVal_GeneticAndDLS_12{};

	// duration times
	real mDurationTime_DLS{};
	real mDurationTime_DLS_12{};
	real mDurationTime_GeneticAndDLS{};
	real mDurationTime_GeneticAndDLS_12{};

	// replace sequences
	std::vector<unsigned int> mReplaceSequence_leftToRight;
	std::vector<unsigned int> mReplaceSequence_rightToLeft;
	std::vector<unsigned int> mReplaceSequence_maxSeidel;
	std::vector<unsigned int> mReplaceSequence_minSeidel;
	std::vector<unsigned int> mReplaceSequence_best;

	// number of best lens was taken
	std::vector<unsigned int> mNumBestLensWasTaken{};

	// number of lenses in optical system
	unsigned int mNumberOfLensesInOptSys{};

};


class testLensReplaceAndOptimize_statistic_twoLensSystem
{
public:
	testLensReplaceAndOptimize_statistic_twoLensSystem();
	~testLensReplaceAndOptimize_statistic_twoLensSystem();

	// do the statistic evaluation
	saveLRaO_statistic doTheStatisticEvaluation(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location);

	// load importent parameter
	void loadImportantParameter();
	// debug mode
	void turn_ON_debugMode();
	void turn_OFF_debugMode();

	bool testLRaO_stat_twoLensSystem_superFct();
	// E0
	bool testLRaO_stat_twoLensSystem_E0();

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

	std::vector<saveLRaO_statistic> mSaveAllResults{};
	bool mDebugMode{};

	unsigned int mNumberBestFitLenses{};
};

