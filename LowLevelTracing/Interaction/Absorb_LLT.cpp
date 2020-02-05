#include "Absorb_LLT.h"
#include <iostream>

std::vector<LightRayStruct> Absorb_LLT::calcInteraction(IntersectInformationStruct intersectInformation)
{
	// if the direction of a ray is { 0.0, 0.0, 0.0 } it means, that the ray is NOT alive!

	Ray_LLT ray(/*origin*/{ 1.0, 1.0, 1.0 }, /*direction*/{ 1.0, 1.0, 1.0 }, 1.0);
	Light_LLT light(1.0, 1.0, { 0.0, 0.0, 0.0,0.0 }, typeLightRay, 0);
	LightRayStruct output;
	output.setIsAlive(0); // ray ist not alive
	std::vector<LightRayStruct> returnRay;


	returnRay.push_back(output);
	return returnRay;
}

Absorb_LLT::Absorb_LLT(Absorb_LLT &source)
{
	if (this == &source)
	{
		return;
	}

	mIntersectionInformation = source.mIntersectionInformation;

}

Absorb_LLT& Absorb_LLT::operator=(Absorb_LLT& source)
{
	if (this == &source)
	{
		return *this;
	}

	mIntersectionInformation = source.mIntersectionInformation;

	return *this;
}

std::shared_ptr<InteractionRay_LLT> Absorb_LLT::clone()
{
	std::shared_ptr<InteractionRay_LLT> absorb_LLT(new Absorb_LLT(*this));

	return absorb_LLT;
}