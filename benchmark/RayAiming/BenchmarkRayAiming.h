#pragma once
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"

class BenchmarkRayAiming
{
public:
	BenchmarkRayAiming() {};
	~BenchmarkRayAiming() {};

	// check methodes of class ParaxialLens_LLT
	bool checkRayAimingE0();

	bool checkRayAimingSuperFct();

	bool checkMethodesRayAiming();
	bool checkRayAimingSingleRay_obj(/*opt sys LLT

	// check ray aiming sing*/ OpticalSystem_LLT& const optSys_LLT, /*start point Ray*/ VectorStructR3& const startPointRay, /*target point*/ VectorStructR3& const  targetPoint, /*light*/ Light_LLT& const Light);
	bool checkRayAimingSingleRay_inf(/*opt sys LLT*/ OpticalSystem_LLT& const optSys_LLT, /*ray direction*/ VectorStructR3& const rayDirection, /*target point*/ VectorStructR3& const  targetPoint, /*light*/ Light_LLT& const Light);
	bool checkRayAimingManyRay_obj(/*opt sys LLT*/ OpticalSystem_LLT& const optSys_LLT, /*start point Ray*/ VectorStructR3& const startPointRay, /*rings*/ unsigned int& const ringsAB,/*arms*/ unsigned int& const armsAB,/*refractive index*/ double& const refractiveIndex,/*light*/ Light_LLT& const Light);
	bool checkRayAimingManyRay_inf(/*opt sys LLT*/ OpticalSystem_LLT& const optSys_LLT, /*ray direction*/ VectorStructR3& const rayDirection, /*rings*/ unsigned int& const ringsAB,/*arms*/ unsigned int& const armsAB,/*light*/ Light_LLT& const Light);

private:


};