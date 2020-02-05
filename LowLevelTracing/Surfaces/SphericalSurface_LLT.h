#pragma once
#include "..\SurfaceIntersectionRay_LLT.h"
#include <iostream>
#include "..\..\Plot\Plot2D.h"

class SphericalSurfaceQwt :
	public QwtPlotCurve
{


public:

	SphericalSurfaceQwt(double radius, double semiHeight, VectorStructR3 direction, VectorStructR3 point);

	//return a vector with the coordinates of the surface
	virtual QPolygonF points(double radius, double semiHeight, VectorStructR3 direction, VectorStructR3 point);

private:

	QPolygonF SphericalSurfacePoints;


};

class SphericalSurface_LLT : public SurfaceIntersectionRay_LLT
{
public:
	SphericalSurface_LLT() {};
	SphericalSurface_LLT(SphericalSurface_LLT &source);
	SphericalSurface_LLT& operator=(SphericalSurface_LLT& source);
	virtual ~SphericalSurface_LLT() {};
	std::shared_ptr<SurfaceIntersectionRay_LLT> clone() override;
	SphericalSurface_LLT(/*radius*/ double radius,/*semi height*/ double  semiHeight,/*point*/ VectorStructR3 point,
		/*direction*/ VectorStructR3 direction,/*refractive index A*/ double refractiveSideA,/*refractive index B*/ double refractiveSideB) :
		mRadius(radius),
		mSemiHeight(std::abs(semiHeight)),
		mPointSphere(point),
		mDirection(direction),
		mRefractiveIndexA(refractiveSideA),
		mRefractiveIndexB(refractiveSideB)


	{
		calcCenterSphereAfterRotation();
		mFocalLengthSphericalSurfaceSide_A = calcFocallLengthSphericalSurface(getRefractivIndexSide_B(), getRefractivIndexSide_A(), getRadius());
		mFocalLengthSphericalSurfaceSide_B = calcFocallLengthSphericalSurface(getRefractivIndexSide_A(), getRefractivIndexSide_B(), getRadius());
	}


	//VectorStructR3 Dir = pRay.getDirectionRay();

	//TODO Question:
	// We have to check wether the height of the spherical surface is heigher than the radius!
	// if radius > semiHeight -> this is possible
	// if radius < semiHeight -> set semiHeight = radius
	// this should be always be checkt when a new spherical surface is implemented
	/*
	int foo()
	{
	throw std::runtime_error("Carsten error");
	}

	try
	{
		foo();
	}
	catch (const std::exception& exception)
	{
		std::cout << "Carsten SAGT fehler: " << exception.what();
	}
	*/

	//~SphericalSurface_LLT() { std::cout << "deleted sphere LLT" << std::endl;; };



	//get Radius
	virtual double getRadius() override;
	//get Height
	double getSemiHeight() override;
	//set Height
	void setSemiHeight(double height);;
	// get Point 
	VectorStructR3 getPoint() override;
	// set Point
	void setPoint(VectorStructR3 Point);
	// get Direction
	VectorStructR3 getDirection() override;
	// set Diretion
	void setDirectionSphere(VectorStructR3 const& Direction);
	//get Refractiv Index Left
	double getRefractivIndexSide_A() const&;
	//set Refractive Index Left
	virtual void setRefractiveIndexSide_A(double const& refractiveIndexLeft) override;
	//get Refractiv Index Right
	double getRefractivIndexSide_B() const&;
	//set Refractive Index Right
	virtual void setRefractiveIndexSide_B(double const& refractiveIndexRight) override;
	// calculate focal length spherical surface
	double calcFocallLengthSphericalSurface(double const& refIndes1, double const& refIndex2, double const& radius);
	// get the focal length of the surface
	// get focal length side B
	virtual real getFocalLength_B() override;
	// get focal length side A
	virtual real getFocalLength_A() override;
	// get refractive index side A
	virtual real getRefractiveIndex_A() override;
	// get refractive index side B
	virtual real getRefractiveIndex_B() override;


	// make the 2d plot
	void plot2D(cv::Mat image, unsigned int scale, unsigned int thickness, unsigned int lineType) override;

	// calculate center of shere after rotation	
	void calcCenterSphereAfterRotation();

	virtual void setRadius(real radius) override;
	virtual void setPosition(VectorStructR3 position) override;

	//__________
	// Struct to save the calculated intersection point between ray and spherical surface
	struct ALL_IntersectionPointsStruct
	{
		VectorStructR3 firstIntersectionPoint;
		VectorStructR3 secondIntersectionPoint;
		double stepsT_first;
		double stepsT_second;
		int yesNoIntersectionPoint;

		VectorStructR3 getFirstIntersectionPoint();
		VectorStructR3 getSecondIntersectionPoint();
		int isIntersectionPoint();
	};
	//__________
	// Struct to save the right intersection point
	struct CheckedIntersectionPointStruct
	{
		VectorStructR3 IntersectionPoint;
		double stepsToIntersectionPoint;
		int isIntersectionPoint; //if 0 -> there is no intersectionpoint

		VectorStructR3 getIntersectionPoint();
		int yesNoIntersectionPoint();
	};
	//_________

	IntersectInformationStruct calculateIntersection(LightRayStruct const& lightRay) override;

	//ALTIntersectInformationStruct calculateIntersection(Ray_LLT ray);
	//IntersectInformationStruct publicIntersectInformation = intersectInformation();
	//void getPublicIntersectionInformation();

	//get the pointer of the qwt curve
	SphericalSurfaceQwt* getPointerPlot();

	//get QPolygonF of the surface
	virtual QPolygonF* getQPolygonFCurve();

private:
	double mRadius;
	double mSemiHeight;
	VectorStructR3 mPointSphere;
	VectorStructR3 mDirection;
	double mRefractiveIndexA;
	double mRefractiveIndexB;
	VectorStructR3 mCenterSphereAfterRotation;
	real mFocalLengthSphericalSurfaceSide_A;
	real mFocalLengthSphericalSurfaceSide_B;

	SphericalSurfaceQwt* SphericalSurface_Qwt_Ptr; // = new SphericalSurfaceQwt(mRadius, mSemiHeight, mDirection, mPointSphere);
	QPolygonF pointsofSphericalSurface; // = SphericalSurface_Qwt_Ptr->points(mRadius, mSemiHeight, mDirection, mPointSphere);

	// TODO: Attention!!!
	// Here we must be carefull! Maybe we can also use here smart pointe to delete the object (bacause of new)!
	// SphericalSurfaceQwt* SphericalSurface_Qwt_Ptr = new SphericalSurfaceQwt(mRadius, mSemiHeight, mDirection, mPointSphere);
};
