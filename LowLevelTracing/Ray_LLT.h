#pragma once
#include "Math_LLT.h"	//TODO Ques Sergej: Ist das hier Sinnvoll? -> wir brauchen es nur für "mDirectionUnitRay (Math::unitVector(directionRay))"
									// man könnte es auch in {}; schreiben....

class Ray_LLT  {
public:
	Ray_LLT();
	Ray_LLT(/*origin*/ VectorStructR3 originRay,/*direction*/ VectorStructR3 directionRay,/*refractive index*/ double currentRefractiveIndex);
	~Ray_LLT();

	// get Origin
	VectorStructR3 getOriginRay() const;
	
	// set Origin
	void setOriginRay(VectorStructR3& const vectorOrigin);
	
	// get direction unit
	VectorStructR3 getDirectionRayUnit() const;

	// set direction unit
	void setDirectionRayUnit(VectorStructR3& const DirectionRayUnit);

		// get current refractive index
	double getCurrentRefractiveIndex() const;

	// set current refractive index
	void setCurrentRefractiveIndex(double& const curRefractiveIndex);

	// set ray absorbed
	void setRayAbsorbed();


private:
	VectorStructR3 mOriginRay{};
	VectorStructR3 mDirectionRayUnit{};
	double mCurrentRefractiveIndexRay{};

};
