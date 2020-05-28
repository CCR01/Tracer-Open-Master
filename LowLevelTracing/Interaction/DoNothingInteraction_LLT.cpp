#include "DoNothingInteraction_LLT.h"
#include <iostream>

std::vector<LightRayStruct> DoNothingInteraction_LLT::calcInteraction(const IntersectInformationStruct& intersectInformation)
{
		
	mReturnLightRay.setLight_LLT(intersectInformation.getLight());
	

	if (intersectInformation.getSurfaceSide() == 'N') //there is no intersection point
	{
		std::cout << "there is no interaction point! \n";
		mReturnLightRay_vec[0].setLightRayAbsorb();
	}
	else
	{
		mRay.setOriginRay(intersectInformation.getIntersectionPoint());
		mRay.setDirectionRayUnit(intersectInformation.getDirectionRayUnit());
		if (intersectInformation.getSurfaceSide() == 'A') //0--> surface side A
		{
			mRefIndexSideA = intersectInformation.getRefractiveIndex_A();
			mRay.setCurrentRefractiveIndex(mRefIndexSideA);
		}
		else // ray must come from surface side B
		{
			mRefIndexSideB = intersectInformation.getRefractiveIndex_B();
			mRay.setCurrentRefractiveIndex(mRefIndexSideB);
		}
		mReturnLightRay.setRay_LLT(mRay);
	}

	mReturnLightRay_vec[0] = mReturnLightRay;
	return mReturnLightRay_vec;
}

DoNothingInteraction_LLT::DoNothingInteraction_LLT() { mReturnLightRay_vec.resize(1); };
DoNothingInteraction_LLT::~DoNothingInteraction_LLT() {};
DoNothingInteraction_LLT::DoNothingInteraction_LLT(IntersectInformationStruct intersectInformation) :
	mIntersectionInformation(intersectInformation)
{
	mReturnLightRay_vec.resize(1);
};


DoNothingInteraction_LLT::DoNothingInteraction_LLT(DoNothingInteraction_LLT &source)
{
	if (this == &source)
	{
		return;
	}

	mIntersectionInformation = source.mIntersectionInformation;
	mReturnLightRay_vec = source.mReturnLightRay_vec;
}

DoNothingInteraction_LLT& DoNothingInteraction_LLT::operator=(DoNothingInteraction_LLT& source)
{
	if (this == &source)
	{
		return *this;
	}

	mIntersectionInformation = source.mIntersectionInformation;
	mReturnLightRay_vec = source.mReturnLightRay_vec;

	return *this;
}

std::shared_ptr<InteractionRay_LLT> DoNothingInteraction_LLT::clone()
{
	std::shared_ptr<InteractionRay_LLT> doNothingInteraction_LLT(new DoNothingInteraction_LLT(*this));

	return doNothingInteraction_LLT;
}

RaysRangeStruct DoNothingInteraction_LLT::howManyRays()
{
	return RaysRangeStruct{ 1,1 };
}