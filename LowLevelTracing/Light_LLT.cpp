#include "Light_LLT.h"

Light_LLT::Light_LLT() {};
Light_LLT::Light_LLT(/*wavelength*/ double wavelength, /*intensity*/ double intensity,/*polarisation*/ JonesVector_LLT polarisation,/*light type*/ typeLight lightType) :
	mWavelength(wavelength),
	mIntensity(intensity),
	mPolarisation(polarisation),
	mLightType(lightType)
{}
Light_LLT::Light_LLT(/*wavelength*/ double wavelength) :
	mWavelength(wavelength)
{
	mIntensity = 1.0;
	mPolarisation = { 1.0,1.0,1.0,1.0 };
	mLightType = typeLight::typeLightRay;
}


Light_LLT::~Light_LLT() {};



void Light_LLT::set(Light_LLT light_LLT)
{
	mWavelength = light_LLT.getWavelength();
	mIntensity = light_LLT.getIntensity();
	mPolarisation = light_LLT.getJonesVector();
	mLightType = light_LLT.getTypeLight();
}

// get wavelength
double Light_LLT::getWavelength() const
{
	return mWavelength;
}
// set wavelength
void Light_LLT::setWavelength(const double wavelength)
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
JonesVector_LLT Light_LLT::getJonesVector() const
{
	return mPolarisation;
}
// set jones vector
void Light_LLT::setJonesVector(const JonesVector_LLT& jonesVector)
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

// set light to absorb
void Light_LLT::setLightToAbsorb()
{
	mWavelength = 0.0;
	mIntensity = 0.0;
	mPolarisation = { 0.0,0.0,0.0,0.0 };
	mLightType = typeLight::typeDeath;
}

void Light_LLT::buildDefaultLight()
{
	mWavelength = 550.0;
	mIntensity = 1.0;
	mPolarisation = { 0.0,0.0,0.0,0.0 };
	mLightType = typeLight::typeLightRay;
}