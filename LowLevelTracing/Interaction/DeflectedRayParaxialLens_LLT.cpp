#include "DeflectedRayParaxialLens_LLT.h"
#include <vector>

std::vector<LightRayStruct> DeflectedRayParaxialLens_LLT::calcInteraction(IntersectInformationStruct intersectInformation)
{

	LightRayStruct output;
	output.setIsAlive(1); // LightRay is alive
	Light_LLT light = intersectInformation.getLight();
	output.setLight_LLT(light);
	std::vector<LightRayStruct> returnLightRay;
	real tolerance = 0.000001;
	bool checkIfSideA_and_B_haveSameRefractiveIndex = std::abs(intersectInformation.getRefractiveIndex_B() - intersectInformation.getRefractiveIndex_A()) > tolerance;

		if (mAddInfos.getFocalLengthOfIntersecSurface_Side_A() == 0 )
		{
			//TODO Question: Was soll bei einer Brennweite von 0 passieren? returnRay = returnRay
		}
		else {

			if (intersectInformation.getSurfaceSide() == 'N') //there is no intersection point!
			{
				// TODO Question: Was soll hier gemacht werden? 
				returnLightRay = returnLightRay;
			}

			else //There must be an intersection point
			{

				if (intersectInformation.getSurfaceSide() == 'A' && mAddInfos.getFocalLengthOfIntersecSurface_Side_B() > 0) // Ray from side A on paraxial lens and focallenght bigger than 0
				{
					// direction of nodal ray;
					VectorStructR3 dirNodalRayUnit = intersectInformation.getDirectionRayUnit();

					if (checkIfSideA_and_B_haveSameRefractiveIndex)
					{	
						// calculate incoming angle
						real incomAngleRad = std::acos(dirNodalRayUnit * (-1*intersectInformation.getNormalUnitVector()));					

						// calculate the deflected angle
						real deflectAngleRad = intersectInformation.getRefractiveIndex_B() / intersectInformation.getRefractiveIndex_A() * incomAngleRad;

						//we have to deflect the nodal ray

						real cosPhi1 = std::sqrt(1 - std::pow(incomAngleRad, 2));
						real cosPhi2 = std::sqrt(1 - std::pow(deflectAngleRad, 2));

						
						dirNodalRayUnit = (intersectInformation.getRefractiveIndex_A() / intersectInformation.getRefractiveIndex_B()) * intersectInformation.getDirectionRayUnit() + (intersectInformation.getRefractiveIndex_A() / intersectInformation.getRefractiveIndex_B() * cosPhi1 - cosPhi2) * intersectInformation.getNormalUnitVector();
						
					}
	

					// calculate focal plan
					VectorStructR3 FocalPoint = mAddInfos.getPointofIntersectSurface() + mAddInfos.getFocalLengthOfIntersecSurface_Side_B() * mAddInfos.getDirectionOfIntersecSurfaceUNIT();
					// flat in coordinate form: E:Nx * X+ Ny * Y+ Nz * Z= d 
					double d = FocalPoint.x * mAddInfos.getDirectionOfIntersecSurfaceUNIT().x + FocalPoint.y * mAddInfos.getDirectionOfIntersecSurfaceUNIT().y + FocalPoint.z * mAddInfos.getDirectionOfIntersecSurfaceUNIT().z;
					// calculate Intersection point ray and plan in focal point
					double denominator = mAddInfos.getDirectionOfIntersecSurfaceUNIT().x*dirNodalRayUnit.getX() + mAddInfos.getDirectionOfIntersecSurfaceUNIT().y*dirNodalRayUnit.getY() + mAddInfos.getDirectionOfIntersecSurfaceUNIT().z*dirNodalRayUnit.getZ();
					double numerator = d - mAddInfos.getDirectionOfIntersecSurfaceUNIT().x*intersectInformation.getIntersectionPoint().x - mAddInfos.getDirectionOfIntersecSurfaceUNIT().y*intersectInformation.getIntersectionPoint().y - mAddInfos.getDirectionOfIntersecSurfaceUNIT().z*intersectInformation.getIntersectionPoint().z;
					double stepsT = numerator / denominator;
					VectorStructR3 intersectionPoint = mAddInfos.getPointofIntersectSurface() + stepsT * dirNodalRayUnit;
					VectorStructR3 newDirection = intersectionPoint - intersectInformation.getIntersectionPoint();
					Ray_LLT newRay(intersectInformation.getIntersectionPoint(), newDirection, intersectInformation.getRefractiveIndex_B());
					output.ray = newRay;

				}

				else if (intersectInformation.getSurfaceSide() == 'A' && mAddInfos.getFocalLengthOfIntersecSurface_Side_B() < 0) // Ray from side A on paraxial lens and focallenght smaller than 0
				{
					// direction of nodal ray;
					VectorStructR3 dirNodalRayUnit = intersectInformation.getDirectionRayUnit();

					if (checkIfSideA_and_B_haveSameRefractiveIndex)
					{
						// calculate incoming angle
						real incomAngleRad = std::acos(dirNodalRayUnit * (-1 * intersectInformation.getNormalUnitVector()));

						// calculate the deflected angle
						real deflectAngleRad = intersectInformation.getRefractiveIndex_B() / intersectInformation.getRefractiveIndex_A() * incomAngleRad;

						//we have to deflect the nodal ray

						real cosPhi1 = std::sqrt(1 - std::pow(incomAngleRad, 2));
						real cosPhi2 = std::sqrt(1 - std::pow(deflectAngleRad, 2));


						dirNodalRayUnit = (intersectInformation.getRefractiveIndex_A() / intersectInformation.getRefractiveIndex_B()) * intersectInformation.getDirectionRayUnit() + (intersectInformation.getRefractiveIndex_A() / intersectInformation.getRefractiveIndex_B() * cosPhi1 - cosPhi2) * intersectInformation.getNormalUnitVector();

					}


					// calculate focal plan
					VectorStructR3 FocalPoint = mAddInfos.getPointofIntersectSurface() + mAddInfos.getFocalLengthOfIntersecSurface_Side_A() * mAddInfos.getDirectionOfIntersecSurfaceUNIT();
					// flat in coordinate form: E:Nx * X+ Ny * Y+ Nz * Z= d 
					double d = FocalPoint.getX() * mAddInfos.getDirectionOfIntersecSurfaceUNIT().x + FocalPoint.y * mAddInfos.getDirectionOfIntersecSurfaceUNIT().y + FocalPoint.z * mAddInfos.getDirectionOfIntersecSurfaceUNIT().z;
					// calculate Intersection point ray and plan in focal point
					double denominator = mAddInfos.getDirectionOfIntersecSurfaceUNIT().x*dirNodalRayUnit.getX() + mAddInfos.getDirectionOfIntersecSurfaceUNIT().y*dirNodalRayUnit.getY() + mAddInfos.getDirectionOfIntersecSurfaceUNIT().z*dirNodalRayUnit.getZ();
					double numerator = d - mAddInfos.getDirectionOfIntersecSurfaceUNIT().x*intersectInformation.getIntersectionPoint().x - mAddInfos.getDirectionOfIntersecSurfaceUNIT().y*intersectInformation.getIntersectionPoint().y - mAddInfos.getDirectionOfIntersecSurfaceUNIT().z*intersectInformation.getIntersectionPoint().z;
					double stepsT = numerator / denominator;
					VectorStructR3 intersectionPoint = mAddInfos.getPointofIntersectSurface() + stepsT * dirNodalRayUnit;
					VectorStructR3 newDirection = intersectInformation.getIntersectionPoint() - intersectionPoint;
					Ray_LLT newRay(intersectInformation.getIntersectionPoint(), newDirection, intersectInformation.getRefractiveIndex_B());
					output.ray = newRay;

				}

				else if (intersectInformation.getSurfaceSide() == 'B' && mAddInfos.getFocalLengthOfIntersecSurface_Side_A() > 0) // Ray from side B on paraxial lens and focallenght bigger than 0
				{
					// direction of nodal ray;
					VectorStructR3 dirNodalRayUnit = intersectInformation.getDirectionRayUnit();

					if (checkIfSideA_and_B_haveSameRefractiveIndex)
					{
						// calculate incoming angle
						real incomAngleRad = std::acos(dirNodalRayUnit * (-1 * intersectInformation.getNormalUnitVector()));

						// calculate the deflected angle
						real deflectAngleRad = intersectInformation.getRefractiveIndex_A() / intersectInformation.getRefractiveIndex_B() * incomAngleRad;

						//we have to deflect the nodal ray

						real cosPhi1 = std::sqrt(1 - std::pow(incomAngleRad, 2));
						real cosPhi2 = std::sqrt(1 - std::pow(deflectAngleRad, 2));


						dirNodalRayUnit = (intersectInformation.getRefractiveIndex_B() / intersectInformation.getRefractiveIndex_A()) * intersectInformation.getDirectionRayUnit() + (intersectInformation.getRefractiveIndex_B() / intersectInformation.getRefractiveIndex_A() * cosPhi1 - cosPhi2) * intersectInformation.getNormalUnitVector();
					}


					// calculate focal plan
					VectorStructR3 FocalPoint = mAddInfos.getPointofIntersectSurface() - mAddInfos.getFocalLengthOfIntersecSurface_Side_A() * mAddInfos.getDirectionOfIntersecSurfaceUNIT();
					// flat in coordinate form: E:Nx * X+ Ny * Y+ Nz * Z= d 
					double d = FocalPoint.x * mAddInfos.getDirectionOfIntersecSurfaceUNIT().x + FocalPoint.y * mAddInfos.getDirectionOfIntersecSurfaceUNIT().y + FocalPoint.z * mAddInfos.getDirectionOfIntersecSurfaceUNIT().z;
					// calculate Intersection point ray and plan in focal point
					double denominator = mAddInfos.getDirectionOfIntersecSurfaceUNIT().x*dirNodalRayUnit.getX() + mAddInfos.getDirectionOfIntersecSurfaceUNIT().y*dirNodalRayUnit.getY() + mAddInfos.getDirectionOfIntersecSurfaceUNIT().z*dirNodalRayUnit.getZ();
					double numerator = d - mAddInfos.getDirectionOfIntersecSurfaceUNIT().x*intersectInformation.getIntersectionPoint().x - mAddInfos.getDirectionOfIntersecSurfaceUNIT().y*intersectInformation.getIntersectionPoint().y - mAddInfos.getDirectionOfIntersecSurfaceUNIT().z*intersectInformation.getIntersectionPoint().z;
					double stepsT = numerator / denominator;
					VectorStructR3 intersectionPoint = mAddInfos.getPointofIntersectSurface() + stepsT * dirNodalRayUnit;
					VectorStructR3 newDirection = intersectionPoint - intersectInformation.getIntersectionPoint();
					Ray_LLT newRay(intersectInformation.getIntersectionPoint(), newDirection, intersectInformation.getRefractiveIndex_A());
					output.ray = newRay;
				}

				else if (intersectInformation.getSurfaceSide() == 'B' && mAddInfos.getFocalLengthOfIntersecSurface_Side_A() < 0) // Ray from side B on paraxial lens and focallenght smaller than 0
				{
					// direction of nodal ray;
					VectorStructR3 dirNodalRayUnit = intersectInformation.getDirectionRayUnit();

					if (checkIfSideA_and_B_haveSameRefractiveIndex)
					{
						// calculate incoming angle
						real incomAngleRad = std::acos(dirNodalRayUnit * (-1 * intersectInformation.getNormalUnitVector()));

						// calculate the deflected angle
						real deflectAngleRad = intersectInformation.getRefractiveIndex_A() / intersectInformation.getRefractiveIndex_B() * incomAngleRad;

						//we have to deflect the nodal ray

						real cosPhi1 = std::sqrt(1 - std::pow(incomAngleRad, 2));
						real cosPhi2 = std::sqrt(1 - std::pow(deflectAngleRad, 2));


						dirNodalRayUnit = (intersectInformation.getRefractiveIndex_B() / intersectInformation.getRefractiveIndex_A()) * intersectInformation.getDirectionRayUnit() + (intersectInformation.getRefractiveIndex_B() / intersectInformation.getRefractiveIndex_A() * cosPhi1 - cosPhi2) * intersectInformation.getNormalUnitVector();
					}

					// calculate focal plan
					VectorStructR3 FocalPoint = mAddInfos.getPointofIntersectSurface() - mAddInfos.getFocalLengthOfIntersecSurface_Side_A() * mAddInfos.getDirectionOfIntersecSurfaceUNIT();
					// flat in coordinate form: E:Nx * X+ Ny * Y+ Nz * Z= d 
					double d = FocalPoint.x * mAddInfos.getDirectionOfIntersecSurfaceUNIT().x + FocalPoint.y * mAddInfos.getDirectionOfIntersecSurfaceUNIT().y + FocalPoint.z * mAddInfos.getDirectionOfIntersecSurfaceUNIT().z;
					// calculate Intersection point ray and plan in focal point
					double denominator = mAddInfos.getDirectionOfIntersecSurfaceUNIT().x*dirNodalRayUnit.getX() + mAddInfos.getDirectionOfIntersecSurfaceUNIT().y*dirNodalRayUnit.getY() + mAddInfos.getDirectionOfIntersecSurfaceUNIT().z*dirNodalRayUnit.getZ();
					double numerator = d - mAddInfos.getDirectionOfIntersecSurfaceUNIT().x*intersectInformation.getIntersectionPoint().x - mAddInfos.getDirectionOfIntersecSurfaceUNIT().y*intersectInformation.getIntersectionPoint().y - mAddInfos.getDirectionOfIntersecSurfaceUNIT().z*intersectInformation.getIntersectionPoint().z;
					double stepsT = numerator / denominator;

					VectorStructR3 intersectionPoint = mAddInfos.getPointofIntersectSurface() + stepsT * dirNodalRayUnit;
					VectorStructR3 newDirection = intersectInformation.getIntersectionPoint() - intersectionPoint;
					Ray_LLT newRay(intersectInformation.getIntersectionPoint(), newDirection, intersectInformation.getRefractiveIndex_A());
					output.ray = newRay;
				}

			}

		}



		returnLightRay.push_back(output);
		return returnLightRay;




}

DeflectedRayParaxialLens_LLT::DeflectedRayParaxialLens_LLT(DeflectedRayParaxialLens_LLT &source)
{
	if (this == &source)
	{
		return;
	}

	mIntersectInformation = source.mIntersectInformation;
	mAddInfos = source.mAddInfos;
}

DeflectedRayParaxialLens_LLT& DeflectedRayParaxialLens_LLT::operator=(DeflectedRayParaxialLens_LLT& source)
{
	if (this == &source)
	{
		return *this;
	}

	mIntersectInformation = source.mIntersectInformation;
	mAddInfos = source.mAddInfos;

	return *this;
}

std::shared_ptr<InteractionRay_LLT> DeflectedRayParaxialLens_LLT::clone()
{
	std::shared_ptr<InteractionRay_LLT> deflectedRayParaxialLens_LLT(new DeflectedRayParaxialLens_LLT(*this));

	return deflectedRayParaxialLens_LLT;
}