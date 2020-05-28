#pragma once


#include "InteractionRay_LLT.h"
#include "..\Surfaces\ParaxialLens_LLT.h" // we need that for the struct additionalInfosDeflectedRayParaLensStruct

class DeflectedRayParaxialLens_LLT : public InteractionRay_LLT {

public:
	DeflectedRayParaxialLens_LLT();
	virtual ~DeflectedRayParaxialLens_LLT() override;
	DeflectedRayParaxialLens_LLT& operator=(DeflectedRayParaxialLens_LLT& source);
	DeflectedRayParaxialLens_LLT(DeflectedRayParaxialLens_LLT &source);	
	virtual std::shared_ptr<InteractionRay_LLT> clone() override;
	DeflectedRayParaxialLens_LLT(additionalInfosDeflectedRayParaLensStruct addInfos);
	DeflectedRayParaxialLens_LLT(IntersectInformationStruct intersectInformation, additionalInfosDeflectedRayParaLensStruct addInfos);


	virtual RaysRangeStruct howManyRays() override;

	virtual std::vector<LightRayStruct> calcInteraction(const IntersectInformationStruct& intersectInformation) override;

private:
	IntersectInformationStruct mIntersectInformation{};
	additionalInfosDeflectedRayParaLensStruct mAddInfos{};
};