#include "DoNothingInteraction_LLT.h"
#include <iostream>

std::vector<LightRayStruct> DoNothingInteraction_LLT::calcInteraction(IntersectInformationStruct intersectInformation)
{
	Ray_LLT ray(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 0.0 }, 1.0);
	Light_LLT light = intersectInformation.getLight();
	LightRayStruct output;
	output.setIsAlive(1);
	std::vector<LightRayStruct> returnLightRay;
	

	if (intersectInformation.getSurfaceSide() == 'N') //there is no intersection point
	{
		std::cout << "there is no interaction point! \n";
		output.setIsAlive(0);
	}
	else
	{
		ray.setOriginRay(intersectInformation.getIntersectionPoint());
		ray.setDirectionRayUnit(intersectInformation.getDirectionRayUnit());
		if (intersectInformation.getSurfaceSide() == 'A') //0--> surface side A
		{
			ray.setCurrentRefractiveIndex(intersectInformation.getRefractiveIndex_A());
		}
		else // ray must come from surface side B
		{
			ray.setCurrentRefractiveIndex(intersectInformation.getRefractiveIndex_B());
		}
		output.setRay_LLT(ray);
		output.setLight_LLT(light);
	}

	returnLightRay.push_back(output);
	return returnLightRay;
}

DoNothingInteraction_LLT::DoNothingInteraction_LLT(DoNothingInteraction_LLT &source)
{
	if (this == &source)
	{
		return;
	}

	mIntersectionInformation = source.mIntersectionInformation;
}

DoNothingInteraction_LLT& DoNothingInteraction_LLT::operator=(DoNothingInteraction_LLT& source)
{
	if (this == &source)
	{
		return *this;
	}

	mIntersectionInformation = source.mIntersectionInformation;

	return *this;
}

std::shared_ptr<InteractionRay_LLT> DoNothingInteraction_LLT::clone()
{
	std::shared_ptr<InteractionRay_LLT> doNothingInteraction_LLT(new DoNothingInteraction_LLT(*this));

	return doNothingInteraction_LLT;
}