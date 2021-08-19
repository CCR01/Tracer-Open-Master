#include "InteractionRay_LLT.h"

RaysRangeStruct::RaysRangeStruct() {};
RaysRangeStruct::RaysRangeStruct(unsigned int const min, unsigned int const max) :
	mMin(min),
	mMax(max)
{};
RaysRangeStruct::~RaysRangeStruct() {};

// min
unsigned int RaysRangeStruct::getMin()
{
	return mMin;
}
void RaysRangeStruct::setMin(unsigned int min)
{
	mMin = min;
}
// max 
unsigned int RaysRangeStruct::getMax()
{
	return mMax;
}
void RaysRangeStruct::setMax(unsigned int max)
{
	mMax = max;
}

LightRayStruct::LightRayStruct() { setIsAlive(true);  };
LightRayStruct::LightRayStruct(VectorStructR3 origin, VectorStructR3 direction, real refractivIndex)
{
	mRay.setOriginRay(origin);
	mRay.setDirectionRayUnit(direction);
	mRay.setCurrentRefractiveIndex(refractivIndex);

	mLight.buildDefaultLight();
}
LightRayStruct::LightRayStruct(/*light*/ Light_LLT iLight, /*ray*/ Ray_LLT iRay)
{
	mLight = iLight;
	mRay = iRay;
	mIsAlive = true;
}
LightRayStruct::LightRayStruct(/*light*/ Light_LLT iLight, /*ray*/ Ray_LLT iRay, /*is alive*/ bool i_Alive)
{
	mLight = iLight;
	mRay = iRay;
	mIsAlive = i_Alive;
}
LightRayStruct::~LightRayStruct() {};

// get Ray_LLT
Ray_LLT LightRayStruct::getRay_LLT() const
{
	return mRay;
}
// set Ray_LLT
void LightRayStruct::setRay_LLT(Ray_LLT const raySet)
{
	mRay = raySet;
}
// ray origin
void LightRayStruct::setRayOrigin(VectorStructR3 rayOrigin)
{
	mRay.setOriginRay(rayOrigin);
}
// ray direction unit
void LightRayStruct::setRayDirectionUni(VectorStructR3 rayDirection)
{
	mRay.setDirectionRayUnit(rayDirection);
}
// currecnt refractiv index ray
void LightRayStruct::setCurrentRefractivIndex(real curRefIndex)
{
	mRay.setCurrentRefractiveIndex(curRefIndex);
}
//get Light_LLT
Light_LLT LightRayStruct::getLight_LLT() const
{
	return mLight;
}
//set Light_LLT
void LightRayStruct::setLight_LLT(Light_LLT const lightSet)
{
	mLight = lightSet;
}
// wavelength
void LightRayStruct::setLightWavelength(real wavelenght)
{
	mLight.setWavelength(wavelenght);
}

bool LightRayStruct::getIsAlive() const
{
	return mIsAlive;
}

// set is LightRay alive
void LightRayStruct::setIsAlive(const bool alive)
{
	mIsAlive = alive;
}

// set light ray absorb
void LightRayStruct::setLightRayAbsorb()
{
	mRay.setRayAbsorbed();
	mLight.setLightToAbsorb();
	setIsAlive(false);
}

InteractionRay_LLT::InteractionRay_LLT() {};
InteractionRay_LLT::~InteractionRay_LLT() {};