#pragma once

// interaction
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"

#include "..\..\Glasses\Glasses.h"

#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"

#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"

class TestGlobalOPD {
public:
	TestGlobalOPD();
	~TestGlobalOPD();

	// load important staff
	void loadImportantparameter();

	// check OPD super function
	bool checkGlobalOPD_superFunction_obj();
	bool checkGlobalOPD_superFunction_inf();

	// check fill OPD in Matrix (EP behind ima surface)
	bool checkFillOPDinMatrix_E0_obj();

	// check fill OPD in Matrix (EP before ima surface)
	bool checkFillOPDinMatrix_E1_obj();

	// check fill OPD in Matrix (EP behind ima surface)
	bool checkFillOPDinMatrix_E2_inf();

	// check fill OPD in Matrix (EP before ima surface)
	bool checkFillOPDinMatrix_E3_inf();

	// check fill OPD in Matrix (EP before ima surface)
	bool checkFillOPDinMatrix_E4_inf();

	// compare results calc single and global OPD obj
	bool compareResultsCalcSingleAndGlobalOPDsoptSys_obj(OpticalSystem_LLT optSys, VectorStructR3 startPointRay, real PX, real PY, Light_LLT light, real tolerance);

	// compare results calc single and global OPD inf
	bool compareResultsCalcSingleAndGlobalOPDsoptSys_inf(OpticalSystem_LLT optSys, real angle_X, real angle_Y, real PX, real PY, Light_LLT light, real tolerance);

	// test upsamling OPD
	bool testUpsamplingOPD();

private:
	RefractedRay_LLT mRefrac{};
	Absorb_LLT mAbsorb{};
	DoNothingInteraction_LLT mDoNothing{};
	Light_LLT mLight550{};
	std::vector<LightRayStruct> mVecLightRaysE0_Field_negY1{};
	LightRayStruct mChiefLightRay_Field_negY1{};
	glass mGlasCat{};

	PlanGeometry_LLT mExitPupilE0{};
	std::shared_ptr< SurfaceIntersectionRay_LLT > mExitPupilE0_ptr{};


};