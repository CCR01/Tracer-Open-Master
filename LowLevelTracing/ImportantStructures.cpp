#include "ImportantStructures.h"
#include <iostream>
#include "Math_LLT.h"



pointAndIntensity::pointAndIntensity() {};
pointAndIntensity::~pointAndIntensity() {};

pointAndIntensity::pointAndIntensity(VectorStructR3 /*intersection point*/ const& point, real /*intensity*/ const& intensity) :
	mPoint(point),
	mIntensity(intensity) {};

//get point
VectorStructR3 pointAndIntensity::getPoint() const
{
	return mPoint;
}
// set point
void pointAndIntensity::setPoint(VectorStructR3& const setPoint)
{
	mPoint = setPoint;
}
//get intesity
real pointAndIntensity::getIntensity() const
{
	return mIntensity;
}
//set intesity
void pointAndIntensity::setIntesity(real const setIntensity)
{
	mIntensity = setIntensity;
}

IntersectInformationStruct::IntersectInformationStruct() {};
IntersectInformationStruct::~IntersectInformationStruct() {};
IntersectInformationStruct::IntersectInformationStruct(VectorStructR3 intersectionPoint, VectorStructR3 normaleUnitVector, surfaceSide surfaceSideABN,
	real stepsToWalk, real refractiveIndexA, real refractiveIndexB, VectorStructR3 directionRayUnit, Light_LLT mLight) :

	mIntersectionPoint(intersectionPoint),
	mNormaleUnitVector(normaleUnitVector),
	mSurfaceSideABN(surfaceSideABN),
	mStepsToWalk(stepsToWalk),
	mRefractiveIndexA(refractiveIndexA),
	mRefractiveIndexB(refractiveIndexB),
	mDirectionRayUnit(directionRayUnit),
	mLight(mLight)

{}

// set no intersection point
void IntersectInformationStruct::setNoIntersectionPoint()
{
	mIntersectionPoint = { 0.0,0.0,0.0 };
	mNormaleUnitVector = { 0.0,0.0,0.0 };
	mSurfaceSideABN = N;
	mStepsToWalk = 0.0;
	mRefractiveIndexA = 0.0;
	mRefractiveIndexB = 0.0;
	mDirectionRayUnit = { 0.0,0.0,0.0 };
	mLight.setLightToAbsorb();
}

// set all
void IntersectInformationStruct::setAll(VectorStructR3 intersectionPoint, VectorStructR3 normaleUnitVector, surfaceSide surfaceSideABN,
	real stepsToWalk, real refractiveIndexA, real refractiveIndexB, VectorStructR3 directionRayUnit, Light_LLT mLight)
{
	setIntersectionPoint(intersectionPoint);
	setNormalUnitVector(normaleUnitVector);
	setSurfaceSide(surfaceSideABN);
	setStepsToWalk(stepsToWalk);
	setRefractiveIndex_A(refractiveIndexA);
	setRefractiveIndex_B(refractiveIndexB);
	setDirectionRayUnit(directionRayUnit);
	setLight(mLight);
}

//Matrix3x3AndExist::Matrix3x3AndExist() {};
//Matrix3x3AndExist::~Matrix3x3AndExist() {};

//// save the matrix
//void  Matrix3x3AndExist::saveMatrix(real const mat[3][3])
//{
//	for (int i = 0; i < 3; ++i)
//	{
//		for (int j = 0; j < 3; ++j)
//
//			Matrix[i][j] = mat[i][j];
//	}
//}
//
//// get the matrix from the struct
//void  Matrix3x3AndExist::getMatrix(real mat[3][3])
//{
//	for (int i = 0; i < 3; ++i)
//	{
//		for (int j = 0; j < 3; ++j)
//			mat[i][j] = Matrix[i][j];
//	}
//}

//// save the matrix
//void  Matrix3x3AndExist::saveMatrix(real const mat[3][3])
//{
//	for (int i = 0; i < 3; ++i)
//	{
//		for (int j = 0; j < 3; ++j)
//
//			mMatrix[i][j] = mat[i][j];
//	}
//}
//
//// get the matrix from the struct
//real** Matrix3x3AndExist::getMatrix()
//{
//	return mMatrix
//}
//
//void Matrix3x3AndExist::setMatrixexist(bool exist)
//{
//	mExistMatrix = exist;
//}
//bool Matrix3x3AndExist::getMatrixExist()
//{
//	return mExistMatrix;
//}

//____________________________________________________

VectorStructR3::VectorStructR3() {};
VectorStructR3::VectorStructR3(real X, real Y, real Z) :
	mX(X),
	mY(Y),
	mZ(Z)
{}
VectorStructR3::~VectorStructR3() {};

// Vector R3
void VectorStructR3::print() const
{

	std::cout << "{" << mX << "," << mY << "," << mZ << "}" << std::endl;
}

// set X
void VectorStructR3::setX(real const X_set)
{
	mX = X_set;
}
// get X
double VectorStructR3::getX() const
{
	return mX;
}
// set Y
void VectorStructR3::setY(real const Y_set)
{
	mY = Y_set;
}
//get Y
double VectorStructR3::getY() const
{
	return mY;
}
// set Z
void VectorStructR3::setZ(real const Z_set)
{
	mZ = Z_set;
}
//get Z
double VectorStructR3::getZ() const
{
	return mZ;
}
//____________________________________________________



//____________________________________________________
// IntersectInformationStruct

// set intersection point
void IntersectInformationStruct::setIntersectionPoint(VectorStructR3& const interPoint)
{
	mIntersectionPoint = interPoint;
}

// get intersection point
VectorStructR3 IntersectInformationStruct::getIntersectionPoint() const
{
	return mIntersectionPoint;
}

// set normal unit vector
void IntersectInformationStruct::setNormalUnitVector(VectorStructR3& const norUnVec)
{
	mNormaleUnitVector = norUnVec;
}

// get normal unit vector
VectorStructR3 IntersectInformationStruct::getNormalUnitVector() const
{
	return mNormaleUnitVector;
}

// set surface side
void IntersectInformationStruct::setSurfaceSide(surfaceSide const surSid)
{
	mSurfaceSideABN = surSid;
}

// get surface side
char IntersectInformationStruct::getSurfaceSide() const
{
	// TODO Question: Gibt es hier eine bessere Alternative?!
	// Was passiert, wenn hier ein neues enum dazukommt -> in Bezug auf die Reihenfolge?
	// Wir haben uns mal darüber unterhalten das mit strings zu machen ...
	char returnSurfaceSide = 'N';
	if (mSurfaceSideABN == 0)
	{
		returnSurfaceSide = 'A';
	}
	else if (mSurfaceSideABN == 1)
	{
		returnSurfaceSide = 'B';
	}
	else if (mSurfaceSideABN == 2)
	{
		returnSurfaceSide = 'N';
	}

	return returnSurfaceSide;
}

// set steps to walk
void IntersectInformationStruct::setStepsToWalk(real const steps)
{
	mStepsToWalk = steps;
}

// get steps to walk
real IntersectInformationStruct::getStepsToWalk() const
{
	return mStepsToWalk;
}


// set refractive index side A
void IntersectInformationStruct::setRefractiveIndex_A(real& refractiveIndex)
{
	mRefractiveIndexA = refractiveIndex;
}

// get refractive index side A
real IntersectInformationStruct::getRefractiveIndex_A() const
{
	return mRefractiveIndexA;
}

// set refractive index side B
void IntersectInformationStruct::setRefractiveIndex_B(real& refractiveIndex)
{
	mRefractiveIndexB = refractiveIndex;
}

// get refractive index side B
real IntersectInformationStruct::getRefractiveIndex_B() const
{
	return mRefractiveIndexB;
}

// set direction ray unit
void IntersectInformationStruct::setDirectionRayUnit(VectorStructR3& const direction)
{
	mDirectionRayUnit = direction;
}

// get direction ray unit
VectorStructR3 IntersectInformationStruct::getDirectionRayUnit() const
{
	return mDirectionRayUnit;
}

// set light
void IntersectInformationStruct::setLight(const Light_LLT& light)
{
	mLight = light;
}
// get Light
Light_LLT IntersectInformationStruct::getLight() const
{
	return mLight;
}


// print intersect information
void IntersectInformationStruct::printIntersectInformation() const
{

	std::cout << "intersection point: \n";
	getIntersectionPoint().print();
	std::cout << "normal Vector: \n";
	mNormaleUnitVector.print();
	std::cout << "surface side: " << getSurfaceSide() << std::endl;
	std::cout << "steps to walk: " << getStepsToWalk() << std::endl;
	std::cout << "refractive index A side: " << getRefractiveIndex_A() << std::endl;
	std::cout << "refractive index B side: " << getRefractiveIndex_B() << std::endl;
	std::cout << "direction Ray: \n";
	getDirectionRayUnit().print();

}


// calculate unit vector
VectorStructR3 IntersectInformationStruct::unitVectorForIntersectInfoStruct(VectorStructR3& const V)
{
	VectorStructR3 returnUnitVector;
	real lenghtOfVector = 1 / (std::sqrt(V.getX()*V.getX() + V.getY()*V.getY() + V.getZ()*V.getZ()));

	real xUnit = lenghtOfVector * V.getX();
	real yUnit = lenghtOfVector * V.getY();
	real zUnit = lenghtOfVector * V.getZ();


	returnUnitVector.setX(xUnit);
	returnUnitVector.setY(yUnit);
	returnUnitVector.setZ(zUnit);

	return returnUnitVector;
}

VectorElementAndPosition::VectorElementAndPosition() {};
VectorElementAndPosition::~VectorElementAndPosition() {};
VectorElementAndPosition::VectorElementAndPosition(real val, unsigned int pos) :
	mValue(val),
	mPosInVector(pos)
{}

//get value in vector
double VectorElementAndPosition::getValue() const
{
	return mValue;
}
//get position in vector
unsigned int  VectorElementAndPosition::getPosInVector() const
{
	return mPosInVector;
};


VectorStructR2::VectorStructR2() {};
VectorStructR2::VectorStructR2(real x, real y) :
	mX(x),
	mY(y)
{};

VectorStructR2::~VectorStructR2() {};

// set X
void VectorStructR2::setX(const real X_set)
{
	mX = X_set;
}
// get X
real VectorStructR2::getX() const
{
	return mX;
}

// set Y
void VectorStructR2::setY(const real Y_set)
{
	mY = Y_set;
}
// get Y
real VectorStructR2::getY() const
{
	return mY;
}

// ---
twoVaulesReal::twoVaulesReal() {};
twoVaulesReal::twoVaulesReal(real val_1, real val_2) :
	mVal_1(val_1),
	mVal_2(val_2)
{};
twoVaulesReal::~twoVaulesReal() {};

// value 1
real twoVaulesReal::getVal_1()
{
	return mVal_1;
}
void twoVaulesReal::setVal_1(real val1)
{
	mVal_1 = val1;
}

// value 2
real twoVaulesReal::getVal_2()
{
	return mVal_2;
}
void twoVaulesReal::setVal_2(real val2)
{
	mVal_2 = val2;
}

// ---