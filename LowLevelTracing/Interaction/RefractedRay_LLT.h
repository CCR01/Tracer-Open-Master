#pragma once
#include "InteractionRay_LLT.h"




class RefractedRay_LLT :  public InteractionRay_LLT {

public:
	RefractedRay_LLT();
	virtual ~RefractedRay_LLT() override;
	RefractedRay_LLT& operator=(RefractedRay_LLT& source);
	RefractedRay_LLT(RefractedRay_LLT &source);
	virtual std::shared_ptr<InteractionRay_LLT> clone() override;
	RefractedRay_LLT(IntersectInformationStruct intersectInformation);
	

	virtual RaysRangeStruct howManyRays() override;

	virtual std::vector<LightRayStruct> calcInteraction(const IntersectInformationStruct& intersectInformation) override;

private:
	IntersectInformationStruct mIntersectInformation{};

	// infos to calc refraction

	LightRayStruct mReturnLightRayStruct{};
	std::vector<LightRayStruct> mReturnLightRay_vec{};
	real mSqrtTerm{};
	VectorStructR3 mDirectionRefractedRay;
};

