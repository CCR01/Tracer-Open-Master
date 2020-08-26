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
	bool testOptimizeSys_SuperFunction_GeneticDLS_rms();
	bool testOptimizeSystem_SuperFunction_GeneticDLS_carPoints();

	//E0 _rms
	bool checkE0_GeneticAndDLS_rms();

	//E1 _rms
	bool checkE1_GeneticAndDLS_rms();

	//E2 _rms
	bool checkE2_GeneticAndDLS_rms();

	//E3 _rms
	bool checkE3_GeneticAndDLS_rms();

	//E4 _rms
	bool checkE4_GeneticAndDLS_rms();

	//E5 _rms
	bool checkE5_GeneticAndDLS_rms();

	//E6 _rms
	bool checkE6_GeneticAndDLS_rms();

	//E7 _rms
	bool checkE7_GeneticAndDLS_rms();

	//E8 _rms
	bool checkE8_GeneticAndDLS_rms();
	 
	//E9 _rms
	bool checkE9_GeneticAndDLS_rms();

	//E10 _rms
	bool checkE10_GeneticAndDLS_rms();

	// E11 _rms
	bool checkE11_GeneticAndDLS_rms();

	// E12 _rms
	bool checkE12_GeneticAndDLS_rms();


	//E0 _cardinalPoints
	bool checkE0_GeneticAndDLS_cardinalPoints();



	// load important stuff
	void loadImportantStuff();


private:

	real mTolerance{};
	glass glasses{};

	RefractedRay_LLT mRefrac{};
	Absorb_LLT mAbsorb{};
	DoNothingInteraction_LLT mDoNothing{};

	// wave
	real mWave587{};
	real mWave486{};
	real mWave656{};
	std::vector<real> mWavelength_FdC_vec{};

	// field obj
	VectorStructR3 mField0{};
	VectorStructR3 mField1{};
	VectorStructR3 mField2{};
	VectorStructR3 mField3{};
	VectorStructR3 mField4{};
	std::vector<VectorStructR3> mFields_vec012{};
	std::vector<VectorStructR3> mFields_vec024{};

	// field angle inf
	real mAngleX_0{};
	real mAngleY_0{};
	real mAngleY_1{};
	real mAngleY_2{};
	std::vector<real> mAngleX_000_vec{};
	std::vector<real> mAngleY_012_vec{};

	targetCardinalPointsStruct m_NO_targetCarPoint{};

	defaultParaGenetic mDefaultParaGenetic_rayTracing_ON{};
	defaultParaDLS mDefaultParamDLS_rayTracing_ON{};

	defaultParaGenetic mDefaultParaGenetic_rayTracing_OFF{};
	defaultParaDLS mDefaultParamDLS_rayTracing_OFF{};

	unsigned int mRings{};
	unsigned int mArms{};

	real mPopulation{};
};

