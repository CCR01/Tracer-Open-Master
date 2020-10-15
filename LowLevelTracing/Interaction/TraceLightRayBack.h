#pragma once

#include "InteractionRay_LLT.h"

class TraceLightRayBack : public InteractionRay_LLT
{
public:
	TraceLightRayBack();
	virtual ~TraceLightRayBack() override;
	TraceLightRayBack& operator=(TraceLightRayBack& source);
	TraceLightRayBack(TraceLightRayBack& source);
	virtual std::shared_ptr<InteractionRay_LLT> clone() override;
	TraceLightRayBack(IntersectInformationStruct intersectInformation);

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
