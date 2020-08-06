#pragma once
#include "..\SurfaceIntersectionRay_LLT.h"
#include <iostream>
#include "..\..\Plot\Plot2D.h"


// Struct to save the calculated intersection point between ray and spherical surface
struct ALL_IntersectionPointsStruct
{
public:
	ALL_IntersectionPointsStruct();
	~ALL_IntersectionPointsStruct();

	// first intersection point
	VectorStructR3 getFirstIntersectionPoint();
	void setFirstIntersectionPoint(VectorStructR3 firstInterPoint);
	
	// second intersection point
	VectorStructR3 getSecondIntersectionPoint();
	void setSecondIntersectionPoint(VectorStructR3 secondInterPoint);

	// steps first inter point
	real getStepsFirstIP();
	void setStepsFirstIP(real stepsFirstIP);

	// steps second inter pont
	real getStepsSecondIP();
	void setStepsSecondIP(real stepsSecondIP);


	// is intersection point
	unsigned int getNumIntersectionPoint();
	void setNumIntersectionPoint(unsigned int numIntersectionPoint);

	// setAll
	void setAll(VectorStructR3 firstInterPoint, VectorStructR3 secondInterPoint, real stepFirst, real stepSecond, unsigned int numInterPoints);

private:
	VectorStructR3 mFirstIntersectionPoint{};
	VectorStructR3 mSecondIntersectionPoint{};
	real mStepsT_first{};
	real mStepsT_second{};
	unsigned int mNumberIntersectionPoint{};
};
//__________

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
	SphericalSurface_LLT();
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
		calcFocalLength();
		setPointerPlotQwt();
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
	virtual double getSemiHeight() override;
	//set Height
	virtual void setSemiHeight(double height);;
	// get Point 
	virtual VectorStructR3 getPoint() override;
	// set Point
	void setPoint(VectorStructR3 Point);
	// get Direction
	virtual VectorStructR3 getDirection() override;
	//get Refractiv Index Left
	double getRefractivIndexSide_A() const;
	//set Refractive Index Left
	virtual void setRefractiveIndexSide_A(double const refractiveIndexLeft) override;
	//get Refractiv Index Right
	double getRefractivIndexSide_B() const;
	//set Refractive Index Right
	virtual void setRefractiveIndexSide_B(double const refractiveIndexRight) override;
	// get the focal length of the surface
	// get focal length
	virtual real getFocalLength() override;
	// get focal length dash
	virtual real getFocalLength_dash() override;
	// get refractive index side A
	virtual real getRefractiveIndex_A() override;
	// get refractive index side B
	virtual real getRefractiveIndex_B() override;
	// calc focal length
	virtual void calcFocalLength() override;

	// make the 2d plot
	void plot2D(cv::Mat image, unsigned int scale, unsigned int thickness, unsigned int lineType) override;

	// calculate center of shere after rotation	
	void calcCenterSphereAfterRotation();

	virtual void setRadius(real radius) override;
	virtual void setPosition(VectorStructR3 position) override;
	virtual void setDirection(VectorStructR3 direction) override;

	virtual IntersectInformationStruct calculateIntersection(LightRayStruct const lightRay) override;

	//ALTIntersectInformationStruct calculateIntersection(Ray_LLT ray);
	//IntersectInformationStruct publicIntersectInformation = intersectInformation();
	//void getPublicIntersectionInformation();

	//allocate qwt curve to a pointer
	void setPointerPlotQwt();

	//get the pointer of the qwt curve
	SphericalSurfaceQwt* getPointerPlot();

	//get QPolygonF of the surface
	virtual QPolygonF* getQPolygonFCurve();

private:
	real mRadius{};
	real mSemiHeight{};
	VectorStructR3 mPointSphere{};
	VectorStructR3 mDirection{};
	real mRefractiveIndexA{};
	real mRefractiveIndexB{};
	VectorStructR3 mCenterSphereAfterRotation{};
	real mFocalLength{};
	real mFocalLength_dash{};

	SphericalSurfaceQwt* SphericalSurface_Qwt_Ptr{};
	QPolygonF pointsofSphericalSurface{};

	// parameters to calc intersection point
	Ray_LLT mRay{};
	Light_LLT mLight{};
	IntersectInformationStruct ReturnIntersectInformation{};
	VectorStructR3 mFirstIntersectionPoint{};
	VectorStructR3 mSecondIntersectionPoint{};
	ALL_IntersectionPointsStruct mALL_IntersectionPoints{};
	real mDistancePointFirstIntersectionPoint{};
	real mDistancePointSecondIntersectionPoint{};
	real mShortestDistanceDirection_FIRST_IntersectionPoint{};
	real mShortestDistanceDirection_SECOND_IntersectionPoint{};
	VectorStructR3 mNormalOnSphereAtIntersectPointUnit{};
	real mShortestDistance_FIRST_IntersectionPoint{};
	real mSqrtTermQadraticFormular{};
	real mStepsT_first_zeroSqrtTerm{};
	real mC_Term{};
	real mB_Term{};
	real mA_Term{};
	real mStepsT_first{};
	real mStepsT_second{};

};
