#include "Light_LLT.h"

Light_LLT::Light_LLT() {};
Light_LLT::Light_LLT(/*wavelength*/ double wavelength, /*intensity*/ double intensity,/*polarisation*/ JonesVector_LLT polarisation,/*light type*/ typeLight lightType,/*is alive*/ int isAlive) :
	mWavelength(wavelength),
	mIntensity(intensity),
	mPolarisation(polarisation),
	mLightType(lightType),
	mIsAlive(isAlive)
{}
Light_LLT::Light_LLT(/*wavelength*/ double wavelength) :
	mWavelength(wavelength)
{
	mIntensity = 1.0;
	mPolarisation = { 1.0,1.0,1.0,1.0 };
	mLightType = typeLightRay;
	mIsAlive = 1;
}


Light_LLT::~Light_LLT() {};



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