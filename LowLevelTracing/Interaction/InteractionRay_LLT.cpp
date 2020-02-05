#include "InteractionRay_LLT.h"

// get Ray_LLT
Ray_LLT LightRayStruct::getRay_LLT() const&
{
	return ray;
}
// set Ray_LLT
void LightRayStruct::setRay_LLT(Ray_LLT const& raySet)
{
	ray = raySet;
}
//get Light_LLT
Light_LLT LightRayStruct::getLight_LLT() const&
{
	return light;
}
//set Light_LLT
void LightRayStruct::setLight_LLT(Light_LLT const& lightSet)
{
	light = lightSet;
}

int LightRayStruct::getIsAlive() const&
{
	return isAlive;
}

// set is LightRay alive
void LightRayStruct::setIsAlive(int const& alive)
{
	isAlive = alive;
}