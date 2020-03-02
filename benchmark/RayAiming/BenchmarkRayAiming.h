#pragma once
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"

struct lightRay_interPoint_onTarget
{
public:
	lightRay_interPoint_onTarget();
	lightRay_interPoint_onTarget(/*light ray*/ LightRayStruct lightRay, /*intersection point*/ VectorStructR3 interPoint, /*on target*/ bool onTarger);

	// light ray
	LightRayStruct getLightRay();
	void setLightRay(LightRayStruct lightRay);

	// intersection point
	VectorStructR3 getIntersectionPoint();
	void setIntersectionPoint(VectorStructR3 interPoint);

	// on target
	bool getOnTarget();
	void setOnTarget(bool onTarget);

private:
	LightRayStruct mLightRay;
	VectorStructR3 mInterPoint;
	bool mOnTarget;

};

class BenchmarkRayAiming
{
public:
	BenchmarkRayAiming() {};
	~BenchmarkRayAiming() {};

	// check ray aiming --> obj
	bool checkRayAimingSuperFct_obj();
	bool checkRayAimingE0_obj();
	bool checkRayAimingE1_obj();
	bool checkRayAimingE2_obj();
	bool checkRayAimingE3_obj();
	bool checkRayAimingE4_obj();

	// check ray aiming --> inf
	bool checkRayAimingSuperFct_inf();
	bool checkRayAimingE0_inf();
	bool checkRayAimingE1_inf();
	bool checkRayAimingE2_inf();
	bool checkRayAimingE3_inf();
	bool checkRayAimingE4_inf();


	// ***obj*** //
	lightRay_interPoint_onTarget checkRayAimingSingleRay_obj(/*opt sys LLT*/ OpticalSystem_LLT& const optSys_LLT, /*ray origin*/ VectorStructR3& const rayOrigin, /*target point*/ VectorStructR3& const  targetPoint, /*light*/ Light_LLT& const Light, /*accurency*/ real accurency);
	bool checkRayAimingManyRay_obj(/*opt sys LLT*/ OpticalSystem_LLT& const optSys_LLT, /*ray direction*/ VectorStructR3& const rayOrigin, /*rings*/ unsigned int const ringsAB,/*arms*/ unsigned int const armsAB,/*light*/ Light_LLT& const Light, /*compare rms*/ real checkRMS, real tolerance, real accurancy);
	bool checkStartPointRay(LightRayStruct lightRay, VectorStructR3 checkStartPoint, real tolerance);
	bool checkStartPointRayMany(std::vector<LightRayStruct> lightRay_vec, VectorStructR3 checkStartPoint, real tolerance);

	// ***inf*** //
	lightRay_interPoint_onTarget checkRayAimingSingleRay_inf(/*opt sys LLT*/ OpticalSystem_LLT& const optSys_LLT, /*ray direction*/ VectorStructR3& const rayDirection, /*target point*/ VectorStructR3& const  targetPoint, /*light*/ Light_LLT& const Light, /*accurency*/ real accurency);
	bool checkRayAimingManyRay_inf(/*opt sys LLT*/ OpticalSystem_LLT& const optSys_LLT, /*ray direction*/ VectorStructR3& const rayDirection, /*rings*/ unsigned int& const ringsAB,/*arms*/ unsigned int& const armsAB,/*light*/ Light_LLT& const Light, /*compare rms*/ real checkRMS, real tolerance, real accurancy);
	bool checkDirection_inf(real targetAngel_X, real targetAngle_Y, VectorStructR3 direction, real tolerance);
	bool checkDirectionManyLightRay_inf(real targetAngel_X, real targetAngle_Y, std::vector<LightRayStruct> lightRayVec, real tolerance);
	bool checkRayTracing_inf(OpticalSystem_LLT optSys_LLT, VectorStructR3 origin, real angle_X, real angle_Y, real refIndex, Light_LLT light, VectorStructR3 targetPoint, unsigned int posSurface, real tolerance);
	
	

private:

};