#include "Ray_LLT.h"



// get Origin
VectorStructR3 Ray_LLT::getOriginRay() const&
{
	return mOriginRay;
}

// get Origin
void Ray_LLT::setOriginRay(VectorStructR3 const& vectorOrigin)
{
		mOriginRay = vectorOrigin;
}

// get direction unit
VectorStructR3 Ray_LLT::getDirectionRayUnit() const&
{
	return mDirectionRayUnit;
}

// get direction 
VectorStructR3 Ray_LLT::getDirectionRay() const&
{
	return mDirection;
}

// set direction
void Ray_LLT::setDirectionRay(VectorStructR3 const& DirectionRay)
{
	mDirection = DirectionRay;
}

	
	// set direction unit
	void Ray_LLT::setDirectionRayUnit(VectorStructR3 const& DirectionRayUnit)
	{
		mDirectionRayUnit = Math::unitVector(DirectionRayUnit);
	}


	// get current refractive index
	double Ray_LLT::getCurrentRefractiveIndex() const&
	{
		return mCurrentRefractiveIndexRay;
	}

	// set current refractive index
	void Ray_LLT::setCurrentRefractiveIndex(double const& curRefractiveIndex)
	{
		mCurrentRefractiveIndexRay = curRefractiveIndex;
	}

