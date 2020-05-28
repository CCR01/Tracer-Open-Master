#include "Absorb_LLT.h"
#include <iostream>

std::vector<LightRayStruct> Absorb_LLT::calcInteraction(const IntersectInformationStruct& intersectInformation)
{
	return mReturnLightRay_vec;
}

Absorb_LLT::Absorb_LLT() 
{ 
	lightRay.setLightRayAbsorb();
	mReturnLightRay_vec.push_back(lightRay);
};
Absorb_LLT::~Absorb_LLT() {};
Absorb_LLT::Absorb_LLT(IntersectInformationStruct intersectInformation) :
	mIntersectionInformation(intersectInformation)
{
	lightRay.setLightRayAbsorb();
	mReturnLightRay_vec.push_back(lightRay);
};

Absorb_LLT::Absorb_LLT(Absorb_LLT &source)
{
	if (this == &source)
	{
		return;
	}

	mIntersectionInformation = source.mIntersectionInformation;
	mReturnLightRay_vec = source.mReturnLightRay_vec;
}

Absorb_LLT& Absorb_LLT::operator=(Absorb_LLT& source)
{
	if (this == &source)
	{
		return *this;
	}

	mIntersectionInformation = source.mIntersectionInformation;
	mReturnLightRay_vec = source.mReturnLightRay_vec;

	return *this;
}

std::shared_ptr<InteractionRay_LLT> Absorb_LLT::clone()
{
	std::shared_ptr<InteractionRay_LLT> absorb_LLT(new Absorb_LLT(*this));

	return absorb_LLT;
}

RaysRangeStruct Absorb_LLT::howManyRays()
{
	return RaysRangeStruct{ 1,1 };
}