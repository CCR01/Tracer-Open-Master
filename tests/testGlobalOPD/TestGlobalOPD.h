#pragma once

// interaction
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"

#include "..\..\Glasses\Glasses.h"

#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"

class TestGlobalOPD {
public:
	TestGlobalOPD();
	~TestGlobalOPD();

	// load important staff
	void loadImportantparameter();

	// check OPD super function
	bool checkGlobalOPD_superFunction();

	bool checkGlobalOPD_E0();
	bool checkGlobalOPD_E1();

private:
	RefractedRay_LLT mRefrac{};
	Absorb_LLT mAbsorb{};
	DoNothingInteraction_LLT mDoNothing{};
	Light_LLT mLight{};
	std::vector<LightRayStruct> mVecLightRaysE0_Field_negY1{};
	LightRayStruct mChiefLightRay_Field_negY1{};
	glass mGlasCat{};

	PlanGeometry_LLT mExitPupilE0{};
	std::shared_ptr< SurfaceIntersectionRay_LLT > mExitPupilE0_ptr{};



	

	//light.setW...
	//glasCat.loadGlassCatalog_Schott();

};