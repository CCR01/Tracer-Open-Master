#pragma once
#include "InteractionRay_LLT.h"

class Absorb_LLT : public InteractionRay_LLT {
public:
	Absorb_LLT() {};
	Absorb_LLT& operator=(Absorb_LLT& source);
	Absorb_LLT(Absorb_LLT &source);
	virtual std::shared_ptr<InteractionRay_LLT> clone() override;
	virtual ~Absorb_LLT() {};
	Absorb_LLT(IntersectInformationStruct intersectInformation) :
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
