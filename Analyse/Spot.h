#pragma once

#include "../LowLevelTracing/ImportantStructures.h"
#include <vector>

class Spot {
public:
	Spot() {};
	Spot(/*intersection points*/ std::vector<VectorStructR3> intersectionPoints,/*reference point*/ VectorStructR3 referencePosition);
	Spot(std::vector<pointAndIntensity> /*intersection point and intensity*/ interPointAndIntensity, /*reference point*/ VectorStructR3 referencePosition);

	~Spot() {};

	// calculate rms value of spot considerable intensity of every ray
	real calcRMSconsiderIntensity(std::vector<pointAndIntensity> /*intersection point and intensity*/ interPointAndIntensity, /*reference point*/ VectorStructR3 referencePosition);
	// calculate geometrical radius of spot conderable intensity
	//real calcGeoRadius_considerIntensity();

	// calc RMS value at surface i
	real calcRMS(std::vector<VectorStructR3> intersectionPoints, VectorStructR3 referencePosition);
	// get RMS value in mm
	real getRMS_mm();
	// get RMS value in µm
	real getRMS_µm();

	// calculate RMS of Spot depending on ray's intensity
	real calcRMS_byIntensity(std::vector<VectorStructR3> intersectionPoints, VectorStructR3 referencePosition, std::vector<Light_LLT> lightVector);

	// calculate geometrical radius
	real calcGeoRadius(std::vector <real> distancesVector);
	// get geometrical radius
	real getGeoRadius();

	// get all intersection points
	std::vector<VectorStructR3> getAllInterPoints();
	// get reference point
	VectorStructR3 getRefPoint();

private:

	std::vector<VectorStructR3> mIntersectionPoints;
	VectorStructR3 mReferencePosition;
	real mRMSradius;
	std::vector <real> mDistancesVector;
	real mGEOradius;

	std::vector<pointAndIntensity> mInterPointAndIntensity;
};