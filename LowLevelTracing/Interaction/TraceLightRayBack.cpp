#include "TraceLightRayBack.h"

TraceLightRayBack::TraceLightRayBack(){ mReturnLightRay_vec.resize(1); }

TraceLightRayBack::~TraceLightRayBack() {}

std::vector<LightRayStruct> TraceLightRayBack::calcInteraction(const IntersectInformationStruct& intersectInformation)
{

	mReturnLightRay.setLight_LLT(intersectInformation.getLight());


	if (intersectInformation.getSurfaceSide() == N) //there is no intersection point
	{
		// just for debugging
		// std::cout << "there is no interaction point! \n";
		mReturnLightRay.setLightRayAbsorb();
		mReturnLightRay.setIsAlive(false);
	}
	else
	{
		mRay.setOriginRay(intersectInformation.getIntersectionPoint());
		mRay.setDirectionRayUnit(-1.0 * intersectInformation.getDirectionRayUnit());

		if (intersectInformation.getSurfaceSide() == A) //0--> surface side A
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



TraceLightRayBack::TraceLightRayBack(IntersectInformationStruct intersectInformation) :
	mIntersectionInformation(intersectInformation)
{
	mReturnLightRay_vec.resize(1);
}


TraceLightRayBack::TraceLightRayBack(TraceLightRayBack& source)
{
	if (this == &source)
	{
		return;
	}

	mIntersectionInformation = source.mIntersectionInformation;
	mReturnLightRay_vec = source.mReturnLightRay_vec;
}

TraceLightRayBack& TraceLightRayBack::operator=(TraceLightRayBack& source)
{
	if (this == &source)
	{
		return *this;
	}

	mIntersectionInformation = source.mIntersectionInformation;
	mReturnLightRay_vec = source.mReturnLightRay_vec;

	return *this;
}

std::shared_ptr<InteractionRay_LLT> TraceLightRayBack::clone()
{
	std::shared_ptr<InteractionRay_LLT> traceLightRayBack(new TraceLightRayBack(*this));

	return traceLightRayBack;
}

RaysRangeStruct TraceLightRayBack::howManyRays()
{
	return RaysRangeStruct{ 1,1 };
}