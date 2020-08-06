#include "Spot.h"
#include "../LowLevelTracing/Math_LLT.h"
#include <iostream>

Spot::Spot() {};
Spot::~Spot() {};

Spot::Spot(/*intersection points*/ std::vector<VectorStructR3> intersectionPoints,/*reference point*/ VectorStructR3 referencePosition) :
	mIntersectionPoints(intersectionPoints),
	mReferencePosition(referencePosition)
{
	mRMSradius = calcRMS(mIntersectionPoints, mReferencePosition);
	mGEOradius = calcGeoRadius(mIntersectionPoints, mReferencePosition);
};

Spot::Spot(std::vector<pointAndIntensity> /*intersection point and intensity*/ interPointAndIntensity, /*reference point*/ VectorStructR3 referencePosition) :
	mInterPointAndIntensity(interPointAndIntensity),
	mReferencePosition(referencePosition)
{
	// calculate rms value of spot considerable intensity of every ray
	mRMSradius = calcRMSconsiderIntensity(interPointAndIntensity, referencePosition);
};

// calculate rms value of spot considerable intensity of every ray
real Spot::calcRMSconsiderIntensity(std::vector<pointAndIntensity> /*intersection point and intensity*/ interPointAndIntensity, /*reference point*/ VectorStructR3 referencePosition)
{

	real sumDistance = 0;
	real sumIntensity = 0;
	unsigned int size = interPointAndIntensity.size();

	for (unsigned int i = 0; i < size; ++i)
	{
		sumDistance = sumDistance + /*consider intensity*/ interPointAndIntensity.at(i).getIntensity() * std::pow(Math::distanceTwoVectors(referencePosition, interPointAndIntensity.at(i).getPoint()),2);
		sumIntensity = sumIntensity + interPointAndIntensity.at(i).getIntensity();

	}

	real returnRMSradius = std::sqrt(sumDistance / sumIntensity);
	return returnRMSradius;
}

// calc RMS value at surface i
real Spot::calcRMS(std::vector<VectorStructR3> intersectionPoints, VectorStructR3 referencePosition)
{
	real numerator = 0.0;
	unsigned int denominator = intersectionPoints.size();
	real distance{};

	real pow2distance{};

	for (unsigned int i = 0; i < denominator; ++i)
	{
		distance = Math::distanceTwoVectors(referencePosition, intersectionPoints.at(i));

		pow2distance = std::pow(distance, 2);
		//just for debugging
		//std::cout << "distance pow2: " << pow2distance << std::endl;
		numerator = numerator + pow2distance;
	}

	real returnRMSradius = std::sqrt(numerator / denominator);
	return returnRMSradius;
}

// get RMS value
real Spot::getRMS_mm()
{
	return mRMSradius;
}

// get RMS value in µm
real Spot::getRMS_µm()
{
	return mRMSradius * 1000;
}


// calculate geometrical radius
real Spot::calcGeoRadius(std::vector<VectorStructR3> intersectionPoints, VectorStructR3 referencePosition)
{
	real distance{};
	real returnMaxDistance = 0.0;
	unsigned int size = intersectionPoints.size();

	for (unsigned int i = 0; i < size; i++)
	{
		distance = Math::distanceTwoVectors(referencePosition, intersectionPoints[i]);
	
		if (returnMaxDistance < distance)
		{
			returnMaxDistance = distance;
		}
	}

	return returnMaxDistance;
}

// get geometrical radius
real Spot::getGeoRadius()
{
	return mGEOradius;
}

// get all intersection points
std::vector<VectorStructR3> Spot::getAllInterPoints()
{
	return mIntersectionPoints;
}

// get reference point
VectorStructR3 Spot::getRefPoint()
{
	return mReferencePosition;
}

// calculate RMS of Spot depending on ray's intensity
real Spot::calcRMS_byIntensity(std::vector<VectorStructR3> intersectionPoints, VectorStructR3 referencePosition, std::vector<Light_LLT> lightVector)
{
	real numerator = 0.0;
	real denominator = 0.0;
	real distance{};

	real pow2distance{};
	real tempIntensity{};

	unsigned int size = intersectionPoints.size();

	for (unsigned int i = 0; i < size; ++i)
	{

		distance = Math::distanceTwoVectors(referencePosition, intersectionPoints.at(i));
		tempIntensity = lightVector.at(i).getIntensity();

		denominator = denominator + tempIntensity;

		pow2distance = std::pow(distance, 2) * tempIntensity;
		numerator = numerator + pow2distance;
	}

	real returnRMSradius = std::sqrt(numerator / denominator);
	return returnRMSradius;
}