#pragma once
#include "..\basicdefinition\basicdefinitions.h"
#include <math.h>
#include "..\LowLevelTracing\Light_LLT.h"





struct VectorStructR3
{
public:
	VectorStructR3();
	VectorStructR3(real X, real Y, real Z);
	~VectorStructR3();

	void print() const;

	// set X
	void setX(real const X_set);
	// get X
	double getX() const;
	// set Y
	void setY(real const Y_set);
	// get Y
	double getY() const;
	//set Z;
	void setZ(real const Z_set);
	//get Z
	double getZ() const;

private:
	real mX{};
	real mY{};
	real mZ{};

};

enum surfaceSide { A, B, N };
enum class objectPoint_inf_obj { inf, obj };


struct IntersectInformationStruct
{
public:
	IntersectInformationStruct();
	~IntersectInformationStruct();
	IntersectInformationStruct(VectorStructR3 mIntersectionPoint, VectorStructR3 mNormaleUnitVector, surfaceSide mSurfaceSideABN,
		real mStepsToWalk, real mRefractiveIndexA, real mRefractiveIndexB, VectorStructR3 mDirectionRayUnit, Light_LLT mLight);


	// set intersection point
	void setIntersectionPoint(VectorStructR3& const interPoint);
	// get intersection point
	VectorStructR3 getIntersectionPoint() const;
	// set normal unit vector
	void setNormalUnitVector(VectorStructR3& const NormalUnitVector);
	// get normal unit vector
	VectorStructR3 getNormalUnitVector() const;
	// set surface side
	void setSurfaceSide(surfaceSide const surSid);
	// get surface side
	surfaceSide getSurfaceSide() const;
	// set steps to walk
	void setStepsToWalk(real const steps);
	// get steps to walk
	real getStepsToWalk() const;
	// set refractive index side A
	void setRefractiveIndex_A(real& refractiveIndex);
	// get refractive index side A
	real getRefractiveIndex_A() const;
	// set refractive index side B
	void setRefractiveIndex_B(real& refractiveIndex);
	// get refractive index side B
	real getRefractiveIndex_B() const;
	// set direction ray unit
	void setDirectionRayUnit(VectorStructR3& const direction);
	// get direction ray unit
	VectorStructR3 getDirectionRayUnit() const;
	// set light
	void setLight(const Light_LLT& light);
	// get Light
	Light_LLT getLight() const;



	// print intersect information
	void printIntersectInformation() const;

	// calculate unit vector
	VectorStructR3 unitVectorForIntersectInfoStruct(VectorStructR3& const V);

	// set no intersection point
	void setNoIntersectionPoint();

	// set all
	void setAll(VectorStructR3 intersectionPoint, VectorStructR3 normaleUnitVector, surfaceSide surfaceSideABN,
		real stepsToWalk, real refractiveIndexA, real refractiveIndexB, VectorStructR3 directionRayUnit, Light_LLT mLight);

private:
	VectorStructR3 mIntersectionPoint{};
	VectorStructR3 mNormaleUnitVector{};
	surfaceSide mSurfaceSideABN{}; // A or B -> if N -> there is NO intersection point!
	real mStepsToWalk{};
	real mRefractiveIndexA{};
	real mRefractiveIndexB{};
	VectorStructR3 mDirectionRayUnit{};
	Light_LLT mLight;

	// TODO: write functions gethitPoint, sethitPoint,...
};


struct pointAndIntensity
{
	pointAndIntensity();
	~pointAndIntensity();

	pointAndIntensity(VectorStructR3 /*intersection point*/ const& point, real /*intensity*/ const& intensity);

	//get point
	VectorStructR3 getPoint() const;
	// set point
	void setPoint(VectorStructR3& const setPoint);
	//get intesity
	real getIntensity() const;
	//set intesity
	void setIntesity(real const setIntensity);

private:
	VectorStructR3 mPoint{};
	real mIntensity{};

};

// We use this struct primary for ray aiming
struct VectorElementAndPosition
{
public:
	VectorElementAndPosition();
	VectorElementAndPosition(real val, unsigned int pos);
	~VectorElementAndPosition();

	//get value in vector
	double getValue() const;
	//get position in vector
	unsigned int getPosInVector() const;

private:

	double mValue{};
	unsigned int mPosInVector{};

};

struct VectorStructR2
{
public:
	VectorStructR2();
	VectorStructR2(real x, real y);
	~VectorStructR2();

	// set X
	void setX(const real X_set);
	// get X
	double getX() const;
	// set Y
	void setY(const real Y_set);
	// get Y
	double getY() const;

private:
	real mX{};
	real mY{};
};


struct twoVaulesReal
{
public:

	twoVaulesReal();
	twoVaulesReal(real val_1, real val_2);
	~twoVaulesReal();

	// value 1
	real getVal_1();
	void setVal_1(real val1);

	// value 2
	real getVal_2();
	void setVal_2(real val2);

private:
	real mVal_1{};
	real mVal_2{};


};