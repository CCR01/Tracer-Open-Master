#include "RefractedRay_LLT.h"
#include <iostream>
#include "..\Math_LLT.h"





std::vector<LightRayStruct> RefractedRay_LLT::calcInteraction(IntersectInformationStruct intersectInformation)
{

	Ray_LLT ray(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 0.0 }, 1.0);
	Light_LLT light = intersectInformation.getLight();
	LightRayStruct output;
	output.setIsAlive(1);
	output.setLight_LLT(light);
	std::vector<LightRayStruct> returnRay;


	if (intersectInformation.getSurfaceSide() == 'N') //there is no intersection point
	{
		//std::cout << "there is no interaction point! \n";
		output.setIsAlive(0);

	}

	else
	{
		// in the struct IntersectInformationStruct are all relevant information to calculate the refracted ray.

		//	if (intersectInformation.getDirectionRayUnit() * intersectInformation.getNormalUnitVector() > 0) // we have to flip the normal vercor
		//	{
		//		intersectInformation.setNormalUnitVector(-1 * intersectInformation.getNormalUnitVector());
		//	}

		if (intersectInformation.getSurfaceSide() == 'A') // ray comes from A side !
		{


			double sqrtTerm = 1 - pow((intersectInformation.getRefractiveIndex_A() / intersectInformation.getRefractiveIndex_B()), 2) * ((Math::DoCrossProduct(intersectInformation.getNormalUnitVector(), intersectInformation.getDirectionRayUnit())) * (Math::DoCrossProduct(intersectInformation.getNormalUnitVector(), intersectInformation.getDirectionRayUnit())));
			if (sqrtTerm < 0) // there is total reflexion
			{
				std::cout << "there is total reflexion! \n";
				// TODO: Hier muss dann die reflection function aufgefufen werden
				// Bzw. beim sequentiellen raytracing der Strahl vernichtet werden!

			}


			else //calculate the direction of the refraction ray
			{
				VectorStructR3 directionRefractedRay = (intersectInformation.getRefractiveIndex_A() / intersectInformation.getRefractiveIndex_B()) * (Math::DoCrossProduct(intersectInformation.getNormalUnitVector(), (Math::DoCrossProduct(-1.0 * intersectInformation.getNormalUnitVector(), intersectInformation.getDirectionRayUnit())))) - (intersectInformation.getNormalUnitVector() * std::sqrt(sqrtTerm));

				output.ray.setOriginRay(intersectInformation.getIntersectionPoint());
				output.light.setWavelength(intersectInformation.getLight().getWavelength());
				output.ray.setDirectionRayUnit(directionRefractedRay);
				output.ray.setCurrentRefractiveIndex(intersectInformation.getRefractiveIndex_B());
			}
		}



		else // ray must comes from B side !
		{
			double sqrtTerm = 1 - pow((intersectInformation.getRefractiveIndex_B() / intersectInformation.getRefractiveIndex_A()), 2) * ((Math::DoCrossProduct(intersectInformation.getNormalUnitVector(), intersectInformation.getDirectionRayUnit())) * (Math::DoCrossProduct(intersectInformation.getNormalUnitVector(), intersectInformation.getDirectionRayUnit())));
			if (sqrtTerm < 0) // there is total reflexion
			{
				std::cout << "there is total reflexion!";
				// TODO: Hier muss dann die reflection function aufgefufen werden
			}


			// TODO: überprüfen, warum man das braucht...Raff ich nicht ganz...
			else if (intersectInformation.getDirectionRayUnit().getZ() == intersectInformation.getNormalUnitVector().getZ())
			{
				output.ray.setOriginRay(intersectInformation.getIntersectionPoint());
				output.light.setWavelength(intersectInformation.getLight().getWavelength());
				output.ray.setDirectionRayUnit(intersectInformation.getDirectionRayUnit());
				output.ray.setCurrentRefractiveIndex(intersectInformation.getRefractiveIndex_A());
			}

			else //calculate the direction of the refraction ray
			{
				VectorStructR3 directionRefractedRay = (intersectInformation.getRefractiveIndex_B() / intersectInformation.getRefractiveIndex_A()) * (Math::DoCrossProduct(intersectInformation.getNormalUnitVector(), (Math::DoCrossProduct(-1.0 * intersectInformation.getNormalUnitVector(), intersectInformation.getDirectionRayUnit())))) - (intersectInformation.getNormalUnitVector() * sqrt(sqrtTerm));
				output.ray.setOriginRay(intersectInformation.getIntersectionPoint());
				output.light.setWavelength(intersectInformation.getLight().getWavelength());
				output.ray.setDirectionRayUnit(directionRefractedRay);
				output.ray.setCurrentRefractiveIndex(intersectInformation.getRefractiveIndex_A());
			}

		}


	}

	returnRay.push_back(output);
	return returnRay;

}

RefractedRay_LLT::RefractedRay_LLT(RefractedRay_LLT &source)
{
	if (this == &source)
	{
		return;
	}

	mIntersectInformation = source.mIntersectInformation;
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