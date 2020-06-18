#include "RefractedRay_LLT.h"
#include <iostream>
#include "..\Math_LLT.h"





std::vector<LightRayStruct> RefractedRay_LLT::calcInteraction(const IntersectInformationStruct& intersectInformation)
{

	mReturnLightRayStruct.setLight_LLT(intersectInformation.getLight());


	if (intersectInformation.getSurfaceSide() == N) //there is no intersection point
	{
		//std::cout << "there is no interaction point! \n";
		mReturnLightRayStruct.setLightRayAbsorb();
		mReturnLightRayStruct.setIsAlive(false);
	}

	else
	{
		// in the struct IntersectInformationStruct are all relevant information to calculate the refracted ray.


		if (intersectInformation.getSurfaceSide() == A) // ray comes from A side !
		{


			mSqrtTerm = 1 - pow((intersectInformation.getRefractiveIndex_A() / intersectInformation.getRefractiveIndex_B()), 2) * ((Math::DoCrossProduct(intersectInformation.getNormalUnitVector(), intersectInformation.getDirectionRayUnit())) * (Math::DoCrossProduct(intersectInformation.getNormalUnitVector(), intersectInformation.getDirectionRayUnit())));
			if (mSqrtTerm < 0) // there is total reflexion
			{
				// std::cout << "there is total reflexion! \n";
				// TODO: Hier muss dann die reflection function aufgefufen werden
				// Bzw. beim sequentiellen raytracing der Strahl vernichtet werden!

			}


			else //calculate the direction of the refraction ray
			{
				mDirectionRefractedRay = (intersectInformation.getRefractiveIndex_A() / intersectInformation.getRefractiveIndex_B()) * (Math::DoCrossProduct(intersectInformation.getNormalUnitVector(), (Math::DoCrossProduct(-1.0 * intersectInformation.getNormalUnitVector(), intersectInformation.getDirectionRayUnit())))) - (intersectInformation.getNormalUnitVector() * std::sqrt(mSqrtTerm));

				mReturnLightRayStruct.setRayOrigin(intersectInformation.getIntersectionPoint());
				mReturnLightRayStruct.setLightWavelength(intersectInformation.getLight().getWavelength());
				mReturnLightRayStruct.setRayDirectionUni(mDirectionRefractedRay);
				mReturnLightRayStruct.setCurrentRefractivIndex(intersectInformation.getRefractiveIndex_B());
			}
		}



		else // ray must comes from B side !
		{
			mSqrtTerm = 1 - pow((intersectInformation.getRefractiveIndex_B() / intersectInformation.getRefractiveIndex_A()), 2) * ((Math::DoCrossProduct(intersectInformation.getNormalUnitVector(), intersectInformation.getDirectionRayUnit())) * (Math::DoCrossProduct(intersectInformation.getNormalUnitVector(), intersectInformation.getDirectionRayUnit())));
			if (mSqrtTerm < 0) // there is total reflexion
			{
				// std::cout << "there is total reflexion!";
				// TODO: Hier muss dann die reflection function aufgefufen werden
				mReturnLightRayStruct.setIsAlive(false);
				mReturnLightRay_vec[0] = mReturnLightRayStruct;
				return mReturnLightRay_vec;
			}


			// TODO: überprüfen, warum man das braucht...Raff ich nicht ganz...
			else if (intersectInformation.getDirectionRayUnit().getZ() == intersectInformation.getNormalUnitVector().getZ())
			{
				mReturnLightRayStruct.setRayOrigin(intersectInformation.getIntersectionPoint());
				mReturnLightRayStruct.setLightWavelength(intersectInformation.getLight().getWavelength());
				mReturnLightRayStruct.setRayDirectionUni(intersectInformation.getDirectionRayUnit());
				mReturnLightRayStruct.setCurrentRefractivIndex(intersectInformation.getRefractiveIndex_A());
			}

			else //calculate the direction of the refraction ray
			{
				mDirectionRefractedRay = (intersectInformation.getRefractiveIndex_B() / intersectInformation.getRefractiveIndex_A()) * (Math::DoCrossProduct(intersectInformation.getNormalUnitVector(), (Math::DoCrossProduct(-1.0 * intersectInformation.getNormalUnitVector(), intersectInformation.getDirectionRayUnit())))) - (intersectInformation.getNormalUnitVector() * sqrt(mSqrtTerm));
				mReturnLightRayStruct.setRayOrigin(intersectInformation.getIntersectionPoint());
				mReturnLightRayStruct.setLightWavelength(intersectInformation.getLight().getWavelength());
				mReturnLightRayStruct.setRayDirectionUni(mDirectionRefractedRay);
				mReturnLightRayStruct.setCurrentRefractivIndex(intersectInformation.getRefractiveIndex_A());
			}

		}


	}

	mReturnLightRay_vec[0] = mReturnLightRayStruct;
	return mReturnLightRay_vec;

}

RefractedRay_LLT::RefractedRay_LLT() { mReturnLightRay_vec.resize(1); };
RefractedRay_LLT::~RefractedRay_LLT() {};

RefractedRay_LLT::RefractedRay_LLT(IntersectInformationStruct intersectInformation) :
	mIntersectInformation(intersectInformation)
{
	mReturnLightRay_vec.resize(1);
};

RefractedRay_LLT::RefractedRay_LLT(RefractedRay_LLT &source)
{
	if (this == &source)
	{
		return;
	}

	mIntersectInformation = source.mIntersectInformation;
	mReturnLightRay_vec = source.mReturnLightRay_vec;
}

RefractedRay_LLT& RefractedRay_LLT::operator=(RefractedRay_LLT& source)
{
	if (this == &source)
	{
		return *this;
	}

	mIntersectInformation = source.mIntersectInformation;

	return *this;
}

std::shared_ptr<InteractionRay_LLT> RefractedRay_LLT::clone()
{
	std::shared_ptr<InteractionRay_LLT> refractionRay_LLT(new RefractedRay_LLT(*this));

	return refractionRay_LLT;
}

RaysRangeStruct RefractedRay_LLT::howManyRays() 
{ 
	return RaysRangeStruct{ 1,1 }; 
}