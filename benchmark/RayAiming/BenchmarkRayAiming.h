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

	// check methodes of class ParaxialLens_LLT
	bool checkRayAimingE0_inf();
	bool checkRayAimingE1_inf();
	bool checkRayAimingE2_inf();


	bool checkRayAimingSuperFct();

	bool checkMethodesRayAiming();
	bool checkRayAimingSingleRay_obj(/*opt sys LLT*/ OpticalSystem_LLT& const optSys_LLT, /*start point Ray*/ VectorStructR3& const startPointRay, /*target point*/ VectorStructR3& const  targetPoint, /*light*/ Light_LLT& const Light);

	// check ray aiming sing*/ OpticalSystem_LLT& const optSys_LLT, /*start point Ray*/ VectorStructR3& const startPointRay, /*target point*/ VectorStructR3& const  targetPoint, /*light*/ Light_LLT& const Light);
	lightRay_interPoint_onTarget checkRayAimingSingleRay_inf(/*opt sys LLT*/ OpticalSystem_LLT& const optSys_LLT, /*ray direction*/ VectorStructR3& const rayDirection, /*target point*/ VectorStructR3& const  targetPoint, /*light*/ Light_LLT& const Light, /*accurency*/ real accurency);
	bool checkRayAimingManyRay_obj(/*opt sys LLT*/ OpticalSystem_LLT& const optSys_LLT, /*start point Ray*/ VectorStructR3& const startPointRay, /*rings*/ unsigned int& const ringsAB,/*arms*/ unsigned int& const armsAB,/*refractive index*/ double& const refractiveIndex,/*light*/ Light_LLT& const Light);
	bool checkRayAimingManyRay_inf(/*opt sys LLT*/ OpticalSystem_LLT& const optSys_LLT, /*ray direction*/ VectorStructR3& const rayDirection, /*rings*/ unsigned int& const ringsAB,/*arms*/ unsigned int& const armsAB,/*light*/ Light_LLT& const Light, /*compare rms*/ real checkRMS, real tolerance, real accurancy);

	bool checkStartPointRay(lightRay_interPoint_onTarget lightRay_IP_OT, VectorStructR3 checkStartPoint, real tolerance);
	bool checkDirection_inf(real targetAngel_X, real targetAngle_Y, VectorStructR3 direction, real tolerance);
	bool checkDirectionManyLightRay_inf(real targetAngel_X, real targetAngle_Y, std::vector<LightRayStruct> lightRayVec, real tolerance);

	bool checkRayTracing_inf(OpticalSystem_LLT optSys_LLT, VectorStructR3 origin, real angle_X, real angle_Y, real refIndex, Light_LLT light, VectorStructR3 targetPoint, unsigned int posSurface, real tolerance);


private:

};