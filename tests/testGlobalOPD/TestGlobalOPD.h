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
	bool checkGlobalOPD_superFunction();

	// check fill OPD in Matrix (EP behind ima surface)
	bool checkFillOPDinMatrix_E0();

	// check fill OPD in Matrix (EP before ima surface)
	bool checkFillOPDinMatrix_E1();


	// compare results calc single and global OPD
	bool compareResultsCalcSingleAndGlobalOPDsoptSys(OpticalSystem_LLT optSys, VectorStructR3 startPointRay, real PX, real PY, Light_LLT light, real tolerance);

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