#pragma once
// optical system element
#include "..\OpticalSystemElement\OpticalSystemElement.h"
// ray aiming
#include "..\RayAiming\RayAiming.h"

class RayAiming_12Cores_initalRays
{
public:
	RayAiming_12Cores_initalRays();
	~RayAiming_12Cores_initalRays();

	void loadInput(/*optical system*/ OpticalSystemElement optSysEle, /*rings*/ unsigned int rings,/*arms*/ unsigned int arms, const /*start point ray*/ VectorStructR3 startPointRay, Light_LLT /*light*/ light, /*wavelength vector*/ std::vector<real> wavelength_vec);
	void splitPointsInAsFor12Cores();
	void loadDefaultParameter_initalRays(defaultRayAimingStruct defaulParaRayAim_initalRays);
	void loadPointsInAS();
	std::vector<std::vector<LightRayStruct>> getAimedLightRays();

	std::vector<std::vector<LightRayStruct>> calcRayAimingInitalRays_vec_12cores_obj();
	std::vector<real> getTotalTime_sec();

	// get tolerance X and Y
	real getToleranceXandY();

private:
	unsigned int mNumberPointsInAS{};
	std::vector<VectorStructR3> mPointsInAS{};

	OpticalSystemElement mOptiSysEle{};
	defaultRayAimingStruct mDefaulParaRayAiming_initalRays;
	bool mSetDefaulParameter;
	unsigned int mRings{};
	unsigned int mArms{};
	VectorStructR3 mStartPointRay{};
	Light_LLT mLight{};
	real mCurRefIndex{};
	
	std::vector<real> mWavelength_vec{};

	std::vector<std::vector<LightRayStruct>> mAllAimedLightRays{};

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


	// times
	std::vector<real> mTime_sec_1;
	std::vector<real> mTime_sec_2;
	std::vector<real> mTime_sec_3;
	std::vector<real> mTime_sec_4;
	std::vector<real> mTime_sec_5;
	std::vector<real> mTime_sec_6;
	std::vector<real> mTime_sec_7;
	std::vector<real> mTime_sec_8;
	std::vector<real> mTime_sec_9;
	std::vector<real> mTime_sec_10;
	std::vector<real> mTime_sec_11;
	std::vector<real> mTime_sec_12;

	std::vector<real>mTimeTotal_sec{};
};


