#pragma once
#include "InteractionRay_LLT.h"

class Absorb_LLT : public InteractionRay_LLT {
public:
	Absorb_LLT();
	virtual ~Absorb_LLT() override;
	Absorb_LLT& operator=(Absorb_LLT& source);
	Absorb_LLT(Absorb_LLT &source);
	virtual std::shared_ptr<InteractionRay_LLT> clone() override;
	
	Absorb_LLT(IntersectInformationStruct intersectInformation);

	virtual RaysRangeStruct howManyRays() override;

	virtual std::vector<LightRayStruct> calcInteraction(const IntersectInformationStruct& intersectInformation) override;


private:
	IntersectInformationStruct mIntersectionInformation{};
	std::vector<LightRayStruct> mReturnLightRay_vec{};
	LightRayStruct lightRay{};
};
