#include "Ray_LLT.h"

Ray_LLT::Ray_LLT() {};
Ray_LLT::Ray_LLT(/*origin*/ VectorStructR3 originRay,/*direction*/ VectorStructR3 directionRay,/*refractive index*/ double currentRefractiveIndex) :
	mOriginRay(originRay),
	mDirectionRayUnit(Math::unitVector(directionRay)),
	mCurrentRefractiveIndexRay(currentRefractiveIndex)
{};
Ray_LLT::~Ray_LLT() {};

// get Origin
VectorStructR3 Ray_LLT::getOriginRay() const
{
	return mOriginRay;
}

// get Origin
void Ray_LLT::setOriginRay(VectorStructR3& const vectorOrigin)
{
		mOriginRay = vectorOrigin;
}

// get direction unit
VectorStructR3 Ray_LLT::getDirectionRayUnit() const
{
	return mDirectionRayUnit;
}

// set direction unit
void Ray_LLT::setDirectionRayUnit(VectorStructR3& const DirectionRayUnit)
{
	mDirectionRayUnit = Math::unitVector(DirectionRayUnit);
}


// get current refractive index
double Ray_LLT::getCurrentRefractiveIndex() const
{
	return mCurrentRefractiveIndexRay;
}

// set current refractive index
void Ray_LLT::setCurrentRefractiveIndex(double& const curRefractiveIndex)
{
	mCurrentRefractiveIndexRay = curRefractiveIndex;
}

// set ray absorbed
void Ray_LLT::setRayAbsorbed()
{
	mOriginRay = { 0.0,0.0,0.0 };
	mDirectionRayUnit = { 0.0,0.0,0.0 };
	mCurrentRefractiveIndexRay = 0.0;
}
