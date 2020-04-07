#pragma once
#include "..\LowLevelTracing\Math_LLT.h"
#include "..\LowLevelTracing\Interaction\InteractionRay_LLT.h"
#include <string>

#include "..\LowLevelTracing/OpticalSystem_LLT.h"


class FillApertureStop
{
public:
	FillApertureStop() {};
	FillApertureStop(OpticalSystem_LLT optSys, unsigned int rings, unsigned int arms);
	FillApertureStop(infosAS infosAS_fillAS, unsigned int rings, unsigned int arms);
	// Object height given by the start point of the ray
	FillApertureStop(/*start point rays*/VectorStructR3 startPointLightRay,/*semi height of aperture stop*/ real semiHeightAB,/*point of aperture stop*/ VectorStructR3 pointAB,/*direction of aperture stop*/ VectorStructR3 directionAB, /*rings*/ unsigned int ringsAB,/*arms*/ unsigned int armsAB,/*refractive index*/ double refractiveIndex,/*light*/ Light_LLT Light) :
		mStartPointRay(startPointLightRay),
		mSemiHeightAS(semiHeightAB),
		mPointAS(pointAB),
		mDirectionAS_Unit(Math::unitVector(directionAB)),
		mRings(ringsAB),
		mArms(armsAB),
		mRefractiveIndex(refractiveIndex),
		mLight(Light)
	{
		mVectorWithManyPointsInAS = fillAS_withPoints(mRayDensity, mPointAS, mDirectionAS_Unit, mSemiHeightAS);
		mVectorWithLightRays = fillASWithLightRayFromObjectPoint(mVectorWithManyPointsInAS);
	};
	// angle in degree according to the optical axis
	FillApertureStop(real /*angle in degree in Y*/ angleX, real /*angle in degree in Y*/ angleY, real semiHeightAB, VectorStructR3 pointAB, VectorStructR3 directionAB, unsigned int ringsAB, unsigned int armsAB, double refractiveIndex, Light_LLT Light) :
		mAngleX(angleX),
		mAngleY(angleY),
		mSemiHeightAS(semiHeightAB),
		mPointAS(pointAB),
		mDirectionAS_Unit(Math::unitVector(directionAB)),
		mRings(ringsAB),
		mArms(armsAB),
		mRefractiveIndex(refractiveIndex),
		mLight(Light)
	{
		mVectorWithManyPointsInAS = fillAS_withPoints(mRayDensity, mPointAS, mDirectionAS_Unit, mSemiHeightAS);
		mVectorWithLightRays = fillASWithLightRayFromInfinity(mVectorWithManyPointsInAS);
	};

	~FillApertureStop();

	// get number of rings in aperture stop
	unsigned int getNumberOfRingsInApertureStop() const&;

	// get a vector with many LightRays
	std::vector<LightRayStruct> getVectorWithLightRays() const&;

	// get points on entrance pupil
	std::vector<VectorStructR3> getPointsInAS();

	// calculate points on one arm of the entrance pupil
	std::vector<VectorStructR3> calcPointsOnOneArm(VectorStructR3 const& direction);

	// print all points in the entrace pupil
	void printAllPointsInAS() const&;

	// build many LightRays from an object point
	std::vector<LightRayStruct> fillASWithLightRayFromObjectPoint(std::vector<VectorStructR3> const& points);

	// build many LightRay from infinity
	std::vector<LightRayStruct> fillASWithLightRayFromInfinity(std::vector<VectorStructR3> const points);

	// In the SpotDiagram Zemax use the "Ray Density" to calculate the RMS radius
	// There are 6 rays in the first ring, 12 in the second 18 ind the third,...
	// build LightRays to calculate the RMS radius
	std::vector<VectorStructR3> fillAS_withPoints(unsigned int const& rayDensity, VectorStructR3 const& PointApertureStop, VectorStructR3 const& directionApertureStop, real const& semiHeightAS);

	// Gibt einen Vektor mit ringförmig angeordneten Targetpunkten in der Aperturblende zurück
	std::vector<VectorStructR3> fillAS_withPointsRing(int nrOfRings, double semiHeightAperture, VectorStructR3 apexApertureStop);

	// Gibt einen Vektor mit quadratisch angeordneten Targetpunkten in der Aperturblende zurück
	std::vector<VectorStructR3> fillAS_withPointsSquare(unsigned int rayDensity, VectorStructR3 pointEntrancePupil, VectorStructR3 directionEntrancePupil, real semiHeightEntrancePupil);

	// Gibt einen Vektor mit zufälligen Targetpunkten in der Aperturblende zurück
	std::vector<VectorStructR3> fillAS_withPointsDithered(unsigned int nrOfRings, VectorStructR3 apexApertureStop, VectorStructR3 directionEntrancePupil, real semiHeightAperture);

	// Einlesen einer .csv Tabelle mit 2 Spalten
	std::vector<VectorStructR2> getcsv2columns(std::string fname);

	// Ändert die Intensität eines Strahls anhand des nach einer .csv-Tabelle/Vector gegebenen Gradzahl
	LightRayStruct changeIntensityByDegree(LightRayStruct lightRay, std::vector<VectorStructR2> vec1);



private:
	VectorStructR3 mStartPointRay;
	real mAngleX;
	real mAngleY;
	real mSemiHeightAS;
	VectorStructR3 mPointAS;
	VectorStructR3 mDirectionAS_Unit;

	unsigned int mRings;
	unsigned int mRayDensity = mRings;
	unsigned int mArms;

	real mRefractiveIndex;
	Light_LLT mLight;

	std::vector<VectorStructR3> mVectorWithManyPointsInAS;
	std::vector<LightRayStruct> mVectorWithLightRays;

	OpticalSystem_LLT mOptSys_LLT;
};