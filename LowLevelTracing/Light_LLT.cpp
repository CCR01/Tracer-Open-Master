#include "Light_LLT.h"

void Light_LLT::set(Light_LLT light_LLT)
{
	mWavelength = light_LLT.getWavelength();
	mIntensity = light_LLT.getIntensity();
	mPolarisation = light_LLT.getJonesVector();
	mLightType = light_LLT.getTypeLight();
	mIsAlive = light_LLT.isAlive();
}

// get wavelength
double Light_LLT::getWavelength() const&
{
	return mWavelength;
}
// set wavelength
void Light_LLT::setWavelength(double const& wavelength)
{
	mWavelength = wavelength;
}

// get intensity 
double Light_LLT::getIntensity()
{
	return mIntensity;
}
// set intensity
void Light_LLT::setIntensity(double intensity)
{
	mIntensity = intensity;
}
// get jones vector
JonesVector_LLT Light_LLT::getJonesVector()
{
	return mPolarisation;
}
// set jones vector
void Light_LLT::setJonesVector(JonesVector_LLT jonesVector)
{
	mPolarisation = jonesVector;
}
//get light type
typeLight Light_LLT::getTypeLight()
{
	return mLightType;
}
//set light type
void Light_LLT::setTypeLight(typeLight lightType)
{
	mLightType = lightType;
}
// is light alive
int Light_LLT::isAlive()
{
	return mIsAlive;
}
// set light alive
void Light_LLT::setIsAlive(int isAlive)
{
	mIsAlive = isAlive;
}