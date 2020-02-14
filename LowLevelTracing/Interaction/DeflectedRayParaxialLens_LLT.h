#pragma once


#include "InteractionRay_LLT.h"
#include "..\Surfaces\ParaxialLens_LLT.h" // we need that for the struct additionalInfosDeflectedRayParaLensStruct

class DeflectedRayParaxialLens_LLT : public InteractionRay_LLT {

public:
	DeflectedRayParaxialLens_LLT() {};
	DeflectedRayParaxialLens_LLT& operator=(DeflectedRayParaxialLens_LLT& source);
	DeflectedRayParaxialLens_LLT(DeflectedRayParaxialLens_LLT &source);
	virtual ~DeflectedRayParaxialLens_LLT() {};
	virtual std::shared_ptr<InteractionRay_LLT> clone() override;
	DeflectedRayParaxialLens_LLT(additionalInfosDeflectedRayParaLensStruct addInfos) :
		mAddInfos(addInfos)
	{}
	DeflectedRayParaxialLens_LLT(IntersectInformationStruct intersectInformation, additionalInfosDeflectedRayParaLensStruct addInfos) :
		mIntersectInformation(intersectInformation)
	{};


	RaysRangeStruct howManyRays() override
		//TODO: in cpp
	{
		return RaysRangeStruct{ 1,1 };
	}

	std::vector<LightRayStruct> calcInteraction(IntersectInformationStruct intersectInformation);

private:
	IntersectInformationStruct mIntersectInformation;
	additionalInfosDeflectedRayParaLensStruct mAddInfos;
};