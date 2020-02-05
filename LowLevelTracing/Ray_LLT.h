#pragma once
#include "Math_LLT.h"	//TODO Ques Sergej: Ist das hier Sinnvoll? -> wir brauchen es nur für "mDirectionUnitRay (Math::unitVector(directionRay))"
									// man könnte es auch in {}; schreiben....

class Ray_LLT  {
public:
	Ray_LLT() {};
	Ray_LLT(/*origin*/ VectorStructR3 originRay,/*direction*/ VectorStructR3 directionRay,/*refractive index*/ double currentRefractiveIndex) :
		mOriginRay(originRay),
		mDirectionRayUnit (Math::unitVector(directionRay)),
		mCurrentRefractiveIndexRay(currentRefractiveIndex)
	{};
	~Ray_LLT() {};

	// get Origin
	VectorStructR3 getOriginRay() const&;
	
	// set Origin
	void setOriginRay(VectorStructR3 const& vectorOrigin);
	
	// get direction unit
	VectorStructR3 getDirectionRayUnit() const&;

	// set direction unit
	void setDirectionRayUnit(VectorStructR3 const& DirectionRayUnit);

	// get direction 
	VectorStructR3 getDirectionRay() const&;

	// set direction
	void setDirectionRay(VectorStructR3 const& DirectionRay);

		// get current refractive index
	double getCurrentRefractiveIndex() const&;

	// set current refractive index
	void setCurrentRefractiveIndex(double const& curRefractiveIndex);


private:
	VectorStructR3 mOriginRay;
	VectorStructR3 mDirectionRayUnit;
	VectorStructR3 mDirection;
	double mCurrentRefractiveIndexRay;

};
