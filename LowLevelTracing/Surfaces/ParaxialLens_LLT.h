#pragma once
#include "..\SurfaceIntersectionRay_LLT.h"
#include "..\Math_LLT.h"
#include "..\..\Plot\Plot2D.h"
#include <iostream>

class ParaxialLensQwtCurve : public QwtPlotCurve
{
public:
	ParaxialLensQwtCurve(double semiHeight, VectorStructR3 point, VectorStructR3 direction);

	//return the points of the surface
	QPolygonF getPoints();

	//rotate a given point p around (cx,cy) 
	QPointF rotate_point(double cx, double cy, double angle, QPointF p);


private:
	QPolygonF PointsParaxialLensQwtCurve;
};

// For an deflection of a ray with a paraxial lens we need additional information
// that are not saved in the struct "IntersectInformationStruct".
// For raytracing with a paraxial lens we save those additional 
// information in the struct "additionalInfosDeflectedRayParaLensStruct"
struct additionalInfosDeflectedRayParaLensStruct
{
	real focalLengthOfIntersecSurface_Side_A;
	real focalLengthOfIntersecSurface_Side_B;
	VectorStructR3 directionOfIntersecSurfaceUNIT;
	VectorStructR3 pointOfIntersectSurface;

	// get focal lenght of intersected surface side A
	real getFocalLengthOfIntersecSurface_Side_A() const&;
	// set focal lenght of intersected surface side A
	void setfocalLengthOfIntersecSurface_Side_A(real const& focalLengthSide_A);
	// get focal lenght of intersected surface side B
	real getFocalLengthOfIntersecSurface_Side_B() const&;
	// set focal lenght of intersected surface side B
	void setfocalLengthOfIntersecSurface_Side_B(real const& focalLengthSide_B);
	// get direction of intersected surface;
	VectorStructR3 getDirectionOfIntersecSurfaceUNIT() const&;
	// set direction of intersected surface;
	void setDirectionOfIntersecSurfaceUNIT(VectorStructR3 const& directionIntersecSurface);
	// get point of intersected surface
	VectorStructR3 getPointofIntersectSurface() const&;
	// set point of intersected surface
	void setPointofIntersectSurface(VectorStructR3 const& pointIntersecSurface);

	
	// calculate unit vector
	VectorStructR3 unitVectorForAddInfosParaLens(VectorStructR3 const& V);
};

class ParaxialLens_LLT : public SurfaceIntersectionRay_LLT
{
public:
	ParaxialLens_LLT() {};
	ParaxialLens_LLT(ParaxialLens_LLT &source);
	ParaxialLens_LLT& operator=(ParaxialLens_LLT& source);
	std::shared_ptr<SurfaceIntersectionRay_LLT> clone() override;
	virtual ~ParaxialLens_LLT() {};
	ParaxialLens_LLT(double semiHeight, VectorStructR3 point, VectorStructR3 direction, double focallength, double refractiveSideA, double refractiveSideB) :
		mSemiHeightParaxialLens(std::abs(semiHeight)),
		mPointParaxialLens(point),
		mDirectionParaxialLens(direction),
		mDirectionParaxialLensUnit(Math::unitVector(direction)),
		mFocallenghtParaxialLensSide_A(focallength * refractiveSideA),
		mFocallenghtParaxialLensSide_B(focallength * refractiveSideB),
		mRefractiveIndexA_ParaxialLens(refractiveSideA),
		mRefractiveIndexB_ParaxialLens(refractiveSideB)		
	{
		setInfosForDeflection(); // save the information that are important to deflect a ray at this paraxial lens
	};

	

	// get semt height
	double getSemiHeight() override;
	//set semi height
	void setSemiHeight(double semiHeight);

	//get point
	VectorStructR3 getPoint();
	// set point
	void setPoint(VectorStructR3 point);

	// get direction
	virtual VectorStructR3 getDirection() override;

	// get direction unit
	VectorStructR3 getDirectionParaxialLensUNIT() const;
	//set direction unit
	void setDirectionParaxialLensUNIT(VectorStructR3 const& direction);

	// get focal length 
	double getFocalLengthParaxialLens() const&;
	// set focal lenght 
	void setFocalLengthParaxialLens(double const& focalLenght);

	// set refractive index side A
	virtual void setRefractiveIndexSide_A(real const& refractiveIndex) override;

	// set refractive index side B
	virtual void setRefractiveIndexSide_B(real const& refractiveIndex) override;

	// set infos for deflection
	void setInfosForDeflection();
	// get infos for deflection
	additionalInfosDeflectedRayParaLensStruct getInfosForDefelction() const&;
	//calculate intersection
	IntersectInformationStruct calculateIntersection(LightRayStruct const& lightRay) override;

	// make the 2d plot
	void plot2D(cv::Mat image, unsigned int scale, unsigned int thickness, unsigned int lineType) override;

	// get focal length side A
	virtual real getFocalLength_A() override;
	// get focal length side B
	virtual real getFocalLength_B() override;
	// get refractive index side A
	virtual real getRefractiveIndex_A() override;
	// get refractive index side B
	virtual real getRefractiveIndex_B() override;
	//get Radius
	virtual double getRadius() override; // the paraxial has no radius so we give 999999999.0
	
	virtual void setRadius(real radius) override;
	virtual void setPosition(VectorStructR3 position) override;
	virtual void setDirection(VectorStructR3 direction) override;

	//get pointer of the qwt curve
	ParaxialLensQwtCurve* getPointerPlot();

	virtual QPolygonF* getQPolygonFCurve();


private:
	double mSemiHeightParaxialLens;
	VectorStructR3 mPointParaxialLens;
	VectorStructR3 mDirectionParaxialLens;
	VectorStructR3 mDirectionParaxialLensUnit;
	real mFocallenghtParaxialLensSide_A;
	real mFocallenghtParaxialLensSide_B;
	real mRefractiveIndexA_ParaxialLens;
	real mRefractiveIndexB_ParaxialLens;
	additionalInfosDeflectedRayParaLensStruct mInfosForDefelction;
	ParaxialLensQwtCurve* ParaxialLensQwtCurve_Ptr = new ParaxialLensQwtCurve(mSemiHeightParaxialLens, mPointParaxialLens, mDirectionParaxialLens);
	QPolygonF PointsOfParaxialLens = ParaxialLensQwtCurve_Ptr->getPoints();
};