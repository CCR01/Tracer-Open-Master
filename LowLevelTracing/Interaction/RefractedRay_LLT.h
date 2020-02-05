#pragma once
#include "InteractionRay_LLT.h"




class RefractedRay_LLT :  public InteractionRay_LLT {

public:
	RefractedRay_LLT() {};
	RefractedRay_LLT& operator=(RefractedRay_LLT& source);
	RefractedRay_LLT(RefractedRay_LLT &source);
	virtual ~RefractedRay_LLT() {};
	virtual std::shared_ptr<InteractionRay_LLT> clone() override;
	RefractedRay_LLT(IntersectInformationStruct intersectInformation) :
		mIntersectInformation(intersectInformation)
	{};
	


	// TODO Ques Sergej: Warum geht das nicht in der .cpp????
	RaysRangeStruct howManyRays()
	{
		return RaysRangeStruct{ 1,1 };
	}

	std::vector<LightRayStruct> calcInteraction(IntersectInformationStruct intersectInformation);

private:
	IntersectInformationStruct mIntersectInformation;

};

