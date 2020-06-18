#include "ReflectionRay_LLT.h"
#include "../Math_LLT.h"
#include <iostream>



std::vector<LightRayStruct> ReflectionRay_LLT::calcInteraction(const IntersectInformationStruct& intersectInformation) {

	Ray_LLT ray(/*origin*/{ 0.0, 0.0, 0.0 }, /*direction*/{ 0.0, 0.0, 0.0 }, 1.0);
	Light_LLT mLight = intersectInformation.getLight();
	LightRayStruct output;
	std::vector<LightRayStruct> returnVecLightRay;

	if (intersectInformation.getSurfaceSide() == N) //there is no intersection point
	{
		std::cout << "there is no interaction point! \n";
	}

	else // there must be an intersection point
	{
		// for our calculation it is not important from witch side the ray
		// interact with the surface.
		// --> we bulid a line from the intersection point an the unit vector
		// --> we mirrow the start point of the ray at that line 
		
			// Spiegelung eines Punktes an einer Geraden: 
			//https://www.abiweb.de/mathematik-analytische-geometrie-lineare-algebra-agla/spiegelungen/spiegelung-geraden.html
		
		VectorStructR3 pointToMirrow = intersectInformation.getIntersectionPoint() + -1 * intersectInformation.getDirectionRayUnit();
		double D = Math::calc_D_ofPlane(intersectInformation.getNormalUnitVector(), pointToMirrow);
		double T = Math::calc_T_ofPlanAndLine(intersectInformation.getIntersectionPoint(), intersectInformation.getNormalUnitVector(), D);
		// calc point S (shortest distance) from point P to plane
		VectorStructR3 S = intersectInformation.getIntersectionPoint() + T*intersectInformation.getNormalUnitVector();
		// calc mirrow point P_Mirrow = OP + 2* PS
		VectorStructR3 P_Mirrow = pointToMirrow + 2 * (S - pointToMirrow);

		// calc new ray
	
		ray.setOriginRay(intersectInformation.getIntersectionPoint());
		ray.setDirectionRayUnit(P_Mirrow - intersectInformation.getIntersectionPoint());
		if (intersectInformation.getSurfaceSide() == A) //0--> surface side A
		{
			real refIndexSideA = intersectInformation.getRefractiveIndex_A();
			ray.setCurrentRefractiveIndex(refIndexSideA);
		}
		else // ray must come from surface side B
		{
			real refIndexSideB = intersectInformation.getRefractiveIndex_B();
			ray.setCurrentRefractiveIndex(refIndexSideB);
		}

		output.setRay_LLT(ray);
	}
	returnVecLightRay.push_back(output);
	return returnVecLightRay;
}

ReflectionRay_LLT::ReflectionRay_LLT() {};
ReflectionRay_LLT::~ReflectionRay_LLT() {};
ReflectionRay_LLT::ReflectionRay_LLT(IntersectInformationStruct intersectInformation) :
	mIntersectionInformation(intersectInformation)
{};

ReflectionRay_LLT::ReflectionRay_LLT(ReflectionRay_LLT &source)
{
	if (this == &source)
	{
		return;
	}

	mIntersectionInformation = source.mIntersectionInformation;
}

ReflectionRay_LLT& ReflectionRay_LLT::operator=(ReflectionRay_LLT& source)
{
	if (this == &source)
	{
		return *this;
	}

	mIntersectionInformation = source.mIntersectionInformation;


	return *this;
}

std::shared_ptr<InteractionRay_LLT> ReflectionRay_LLT::clone()
{
	std::shared_ptr<InteractionRay_LLT> reflectionRay_LLT(new ReflectionRay_LLT(*this));

	return reflectionRay_LLT;
}

RaysRangeStruct ReflectionRay_LLT::howManyRays()
{
	return RaysRangeStruct{ 1,1 };
}