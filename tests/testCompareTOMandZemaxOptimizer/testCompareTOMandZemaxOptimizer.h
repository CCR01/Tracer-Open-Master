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

struct saveResultsOptimizationMethodes
{
public:
	saveResultsOptimizationMethodes();
	~saveResultsOptimizationMethodes();

	// Zemax
	void setRMSvec_Zemax(std::vector<real> RMS_Zemax);
	std::vector<real> getRMSvec_Zemax();
	real getRMSsum_Zemax();
	// DLS
	void setRMSvec_DLS(std::vector<real> RMS_DLS);
	std::vector<real> getRMSvec_DLS();
	real getRMSsum_DLS();
	void setOptimizedSystem_DLS(OpticalSystemElement optimizedSystemDLS);
	OpticalSystemElement getOptimizedSystem_DLS();
	// DLS 12
	void setRMSvec_DLS_12(std::vector<real> RMS_DLS_12);
	std::vector<real> getRMSvec_DLS_12();
	real getRMSsum_DLS_12();
	void setOptimizedSystem_DLS_12(OpticalSystemElement optimizedSystemDLS_12);
	OpticalSystemElement getOptimizedSystem_DLS_12();
	// Genetic and DLS
	void setRMSvec_GeneticAndDLS(std::vector<real> RMS_GeneticAndDLS);
	std::vector<real> getRMSvec_GeneticAndDLS();
	real getRMSsum_GeneticAndDLS();
	void setOptimizedSystem_GeneticAndDLS(OpticalSystemElement optimizedSystemGeneticAndDLS);
	OpticalSystemElement getOptimizedSystem_GeneticAndDLS();
	// Genetic and DLS 12
	void setRMSvec_GeneticAndDLS_12(std::vector<real> RMS_GeneticAndDLS_12);
	std::vector<real> getRMSvec_GeneticAndDLS_12();
	real getRMSsum_GeneticAndDLS_12();
	void setOptimizedSystem_GeneticAndDLS_12(OpticalSystemElement optimizedSystemGeneticAndDLS_12);
	OpticalSystemElement getOptimizedSystem_GeneticAndDLS_12();
	// calc all sums
	void calcAllSums();

private:
	std::vector<real> mRMSvec_Zemax{};
	real mRMS_Zemax_sum{};
	std::vector<real> mRMSvec_DLS{};
	real mRMS_DLS_sum{};
	std::vector<real> mRMSvec_DLS_12{};
	real mRMS_DLS_12_sum{};
	std::vector<real> mRMSvec_GeneticAndDLS{};
	real mRMS_GeneticAndDLS_sum{};
	std::vector<real> mRMSvec_GeneticAndDLS_12{};
	real mRMS_GeneticAndDLS_12_sum{};

	// optimized optical System
	OpticalSystemElement mOptimizedOptSys_DLS{};
	OpticalSystemElement mOptimizedOptSys_DLS_12{};
	OpticalSystemElement mOptimizedOptSys_GeneticAndDLS{};
	OpticalSystemElement mOptimizedOptSys_GeneticAndDLS_12{};
};

class testCompareTOMandZemaxOptimizer
{
public:
	testCompareTOMandZemaxOptimizer();
	~testCompareTOMandZemaxOptimizer();
	
	void loadImportantValues();

	// try all optimization methodes
	saveResultsOptimizationMethodes tryAllOptimizationMethodes(OpticalSystemElement optSysEle, std::vector<real> rmsZ);

	// super function
	bool testCompareTOMandZemaxOptimizer_superFct();
	// E0
	bool testCompareTOMandZemaxOptimizer_E0();
	// E1
	bool testCompareTOMandZemaxOptimizer_E1();
	// E2
	bool testCompareTOMandZemaxOptimizer_E2();
	// E3
	bool testCompareTOMandZemaxOptimizer_E3();
	// E4
	bool testCompareTOMandZemaxOptimizer_E4();
	// E5
	bool testCompareTOMandZemaxOptimizer_E5();
	// E6
	bool testCompareTOMandZemaxOptimizer_E6();
	// E7
	bool testCompareTOMandZemaxOptimizer_E7();
	// E8
	bool testCompareTOMandZemaxOptimizer_E8();
	// E9
	bool testCompareTOMandZemaxOptimizer_E9();
	// E10
	bool testCompareTOMandZemaxOptimizer_E10();
	// E11
	bool testCompareTOMandZemaxOptimizer_E11();
	// E12
	bool testCompareTOMandZemaxOptimizer_E12();
	// E13
	bool testCompareTOMandZemaxOptimizer_E13();
	// E14
	bool testCompareTOMandZemaxOptimizer_E14();

	// export all results
	void exportResults(std::string location, std::string name, std::string example, unsigned);
	void exportAllOpticalSystems(std::string location, saveResultsOptimizationMethodes saveResOptimizationMethodes);
	// debug mode
	void turn_ON_debugMode();
	void turn_OFF_debugMode();

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

	std::vector<saveResultsOptimizationMethodes> mSaveAllResults{};
	bool mDebugMode{};
};



