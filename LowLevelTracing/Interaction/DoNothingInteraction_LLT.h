#pragma once
#include "InteractionRay_LLT.h"

class DoNothingInteraction_LLT : public InteractionRay_LLT {
public:
	DoNothingInteraction_LLT();
	virtual ~DoNothingInteraction_LLT() override;
	DoNothingInteraction_LLT& operator=(DoNothingInteraction_LLT& source);
	DoNothingInteraction_LLT(DoNothingInteraction_LLT &source);
	virtual std::shared_ptr<InteractionRay_LLT> clone() override;
	DoNothingInteraction_LLT(IntersectInformationStruct intersectInformation);
	
	virtual RaysRangeStruct howManyRays() override;

	virtual std::vector<LightRayStruct> calcInteraction(const IntersectInformationStruct& intersectInformation) override;

private:

	IntersectInformationStruct mIntersectionInformation{};

	// infos to calc interaction
	LightRayStruct mReturnLightRay{};
	std::vector<LightRayStruct> mReturnLightRay_vec{};
	Ray_LLT mRay{};
	real mRefIndexSideA{};
	real mRefIndexSideB{};


};