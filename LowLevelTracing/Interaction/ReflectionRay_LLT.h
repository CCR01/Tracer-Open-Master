#pragma once
#include "InteractionRay_LLT.h"

class ReflectionRay_LLT : public InteractionRay_LLT {
public:
	ReflectionRay_LLT() {};
	ReflectionRay_LLT(ReflectionRay_LLT &source);
	ReflectionRay_LLT& operator=(ReflectionRay_LLT& source);
	virtual std::shared_ptr<InteractionRay_LLT> clone() override;
	virtual ~ReflectionRay_LLT() {};
	ReflectionRay_LLT(IntersectInformationStruct intersectInformation) :
		mIntersectionInformation(intersectInformation)
	{};
	

	// TODO Ques Sergej: Warum geht das nicht in der .cpp????
	RaysRangeStruct howManyRays()
	{
		return RaysRangeStruct{ 1,1 };
	}

	std::vector<LightRayStruct> calcInteraction(IntersectInformationStruct intersectInformation);

private:
	IntersectInformationStruct mIntersectionInformation;


};