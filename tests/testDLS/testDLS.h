#pragma once

// interactions
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"

// glass catalogue
#include "..\..\Glasses\Glasses.h"

class testDLS
{
public:
	testDLS();
	~testDLS();

	void loadImportantValues();

	//**
	// super function
	bool testDLS_superFct_optiRMS();
	// E0
	bool testE0_DLS_MD();
	// E1
	bool testE1_DLS_MD(); // switch radius from neg to pos
	// E2
	bool testE2_DLS_MD(); // positions are variable
	// E3
	bool testE3_DLS_MD(); // 2 radii are variable
	// E4
	bool testE4_DLS_MD(); // 1 radius and 1 thickness is variable
	// E5
	bool testE5_DLS_MD(); // 2 radii and 1 thickness is variable
	// E6
	bool testE6_DLS_MD(); // min thickness is 0.01
	// E7
	bool testE7_DLS_MD(); // aperture stop is not first surface
	// E8
	bool testE8_DLS_MD(); // rays from infinity
	//**


	//**
	// test cardinal points super function
	bool testDLS_superFct_optiCarPoints();
	// E0
	bool testE0_carPoint();
	// E1
	bool testE1_carPoint();
	//**


	//**
	// test opti rms and cardinal points
	bool testDLS_superFct_optiRMSAndCarPoints();
	// test rms and efl
	bool testRMSandEFL_E0_DLS();
	// test rms and efl, PMAG
	bool testRMSandEFLandPMAG();
	//**


private:
	// load glass catalog
	glass glasses{};
	// interactions
	DoNothingInteraction_LLT mDoNothing{};
	RefractedRay_LLT mRefrac{};
	Absorb_LLT mAbsorb{};

	// light basic
	real mWave550{};
	real mWave400{};
	real mWave700{};
	std::vector<real> mWavelength_vec{};
	Light_LLT mLight550{};
	Light_LLT mLight400{};
	Light_LLT mLight700{};
	std::vector<Light_LLT> mLightVec{};

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
	VectorStructR3 mField05{};
	VectorStructR3 mField1{};
	VectorStructR3 mField2{};
	std::vector<VectorStructR3> mFields012_obj_vec{};
	std::vector<VectorStructR3> mField0_05_1_obj_vec{};

	// field angle
	real mField_X_0{};
	real mField_Y_0{};
	real mField_Y_1{};
	real mField_Y_2{};
	std::vector<real> mFields000_inf_vec{};
	std::vector<real> mFields012_inf_vec{};
	

	real mDefaultTolerance{};


};

