#pragma once
#include "InteractionRay_LLT.h"

class DoNothingInteraction_LLT : public InteractionRay_LLT {
public:
	DoNothingInteraction_LLT() {};
	DoNothingInteraction_LLT& operator=(DoNothingInteraction_LLT& source);
	DoNothingInteraction_LLT(DoNothingInteraction_LLT &source);
	virtual std::shared_ptr<InteractionRay_LLT> clone() override;
	virtual ~DoNothingInteraction_LLT() {};
	DoNothingInteraction_LLT(IntersectInformationStruct intersectInformation) :
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