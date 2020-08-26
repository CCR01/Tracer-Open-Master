#pragma once

#include "..\LowLevelTracing\Interaction\InteractionRay_LLT.h"
#include "..\LowLevelTracing\OpticalSystem_LLT.h"


class RayAimingSuperFct
{
public:
	RayAimingSuperFct();
	RayAimingSuperFct(const /*optical system*/ OpticalSystem_LLT& optSys_LLT, /*rings*/ unsigned int rings,/*arms*/ unsigned int arms, const /*start point ray*/ VectorStructR3 startPointRay, Light_LLT /*light*/ light, real /*start ref index*/ curRefracIndex);
	~RayAimingSuperFct();

	std::vector<LightRayStruct> calcAimedLightRay_vec_12cores_obj();
	void splitPointsInAsFor12Cores();

	void loadPointsInAS();
	std::vector<LightRayStruct> getAimedLightRays();

private:

	OpticalSystem_LLT mOptcalSystem_LLT{};
	unsigned int mRings{};
	unsigned int mArms{};
	VectorStructR3 mStartPointRay{};
	Light_LLT mLight{};
	real mCurRefIndex{};
	unsigned int mNumberPointsInAS{};
	std::vector<VectorStructR3> mPointsInAS{};

	std::vector<LightRayStruct> mAimedLightRays{};

	std::vector<VectorStructR3> mPoints_1{};
	std::vector<VectorStructR3> mPoints_2{};
	std::vector<VectorStructR3> mPoints_3{};
	std::vector<VectorStructR3> mPoints_4{};
	std::vector<VectorStructR3> mPoints_5{};
	std::vector<VectorStructR3> mPoints_6{};
	std::vector<VectorStructR3> mPoints_7{};
	std::vector<VectorStructR3> mPoints_8{};
	std::vector<VectorStructR3> mPoints_9{};
	std::vector<VectorStructR3> mPoints_10{};
	std::vector<VectorStructR3> mPoints_11{};
	std::vector<VectorStructR3> mPoints_12{};

};

