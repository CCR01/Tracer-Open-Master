#pragma once
#include "InteractionRay_LLT.h"

class ReflectionRay_LLT : public InteractionRay_LLT {
public:
	ReflectionRay_LLT();
	virtual ~ReflectionRay_LLT() override;
	ReflectionRay_LLT(ReflectionRay_LLT &source);
	ReflectionRay_LLT& operator=(ReflectionRay_LLT& source);
	virtual std::shared_ptr<InteractionRay_LLT> clone() override;	
	ReflectionRay_LLT(IntersectInformationStruct intersectInformation);

	virtual RaysRangeStruct howManyRays() override;

	virtual std::vector<LightRayStruct> calcInteraction(const IntersectInformationStruct& intersectInformation) override;

private:
	IntersectInformationStruct mIntersectionInformation{};
	

};