#pragma once
//#include "../SurfaceIntersectionRay_LLT.h"
#include "..\..\Plot\Plot2D.h"

class ApertureStopQwtUp : public QwtPlotCurve
{


public:
	ApertureStopQwtUp(double semiHeight, VectorStructR3 point, VectorStructR3 direction);
	QPolygonF getPoints();
	QPointF rotate_point(double cx, double cy, double angle, QPointF p);

private:
	QPolygonF ApertureStopPoints;

};

class ApertureStopQwtDown : public QwtPlotCurve
{


public:
	ApertureStopQwtDown(double semiHeight, VectorStructR3 point, VectorStructR3 direction);
	QPolygonF getPoints();
	QPointF rotate_point(double cx, double cy, double angle, QPointF p);

private:
	QPolygonF ApertureStopPoints;

};


class ApertureStop_LLT : public SurfaceIntersectionRay_LLT
{
public:
	ApertureStop_LLT();
	ApertureStop_LLT(ApertureStop_LLT &source);
	ApertureStop_LLT& operator=(ApertureStop_LLT& source);
	std::shared_ptr<SurfaceIntersectionRay_LLT> clone() override;
	virtual ~ApertureStop_LLT();
	ApertureStop_LLT(double semiHeight, VectorStructR3 point, VectorStructR3 direction, double refractiveIndex) :
		mSemiHeightAperture(semiHeight),
		mPointAperture(point),
		mDirectionAperture(direction),
		mRrefractiveIndex(refractiveIndex)
	{
		calcApertureStopQwtCoord();
		
	}
	
	void calcApertureStopQwtCoord();
	// get semt height
	double getSemiHeight() override;
	//set semi height
	void setSemiHeight(double semiHeight);

	//get point
	VectorStructR3 getPoint();
	// set point
	void setPoint(VectorStructR3 point);

	// get direction
	VectorStructR3 getDirection() override;
	//set direction
	void setDirection(VectorStructR3 direction);

	// get refractive index
	double getRefractiveIndex();
	// set refractive indes
	virtual void setRefractiveIndexSide_A(real const& refractiveIndex) override;
	virtual void setRefractiveIndexSide_B(real const& refractiveIndex) override;

	// calculate the intersection information
	IntersectInformationStruct calculateIntersection(LightRayStruct const& lightRay) override;

	// get focal length side A
	virtual real getFocalLength_A() override;
	// get focal length side B
	virtual real getFocalLength_B() override;
	// get refractive index side A
	virtual real getRefractiveIndex_A() override;
	// get refractive index side B
	virtual real getRefractiveIndex_B() override;
	//get Radius
	virtual double getRadius() override; // the aperture stop do not has a radius. We give hier 999999999.0
	


//	// make the 2d plot
	void plot2D(cv::Mat image, unsigned int scale, unsigned int thickness, unsigned int lineType) override;

	virtual void setRadius(real radius) override;
	virtual void setPosition(VectorStructR3 position) override;

	//get pointer of the Upper qwt curve
	ApertureStopQwtUp* getPointerPlotUp();

	//get pointer of the Upper qwt curve
	ApertureStopQwtDown* getPointerPlotDown();

	virtual QPolygonF* getQPolygonFCurve() override;



private:
	double mSemiHeightAperture;
	VectorStructR3 mPointAperture;
	VectorStructR3 mDirectionAperture;
	double mRrefractiveIndex;
	ApertureStopQwtUp* ApertureStopUp_Qwt_Ptr{};
	ApertureStopQwtDown* ApertureStopDown_Qwt_Ptr{};
	QPolygonF pointsofApertureStopUp{};
	QPolygonF pointsofApertureStopDown{};
};