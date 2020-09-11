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
	virtual ~ApertureStop_LLT() override;
	ApertureStop_LLT(ApertureStop_LLT &source);
	ApertureStop_LLT& operator=(ApertureStop_LLT& source);
	virtual std::shared_ptr<SurfaceIntersectionRay_LLT> clone() override;
	
	ApertureStop_LLT(/*semi height*/ double semiHeight, /*point*/ VectorStructR3 point,/*direction*/ VectorStructR3 direction,/*refractiv index*/ double refractiveIndex);
	
	void calcApertureStopQwtCoord();
	// get semt height
	virtual double getSemiHeight() override;
	//set semi height
	void setSemiHeight(double semiHeight);

	//get point
	VectorStructR3 getPoint();
	// set point
	void setPoint(VectorStructR3 point);

	// get direction
	virtual VectorStructR3 getDirection() override;

	// get refractive index
	double getRefractiveIndex();
	// set refractive indes
	virtual void setRefractiveIndexSide_A(real const refractiveIndex) override;
	virtual void setRefractiveIndexSide_B(real const refractiveIndex) override;

	// calculate the intersection information
	virtual IntersectInformationStruct calculateIntersection(LightRayStruct const lightRay) override;

	// get focal length side A
	virtual real getFocalLength() override;
	// get focal length side B
	virtual real getFocalLength_dash() override;
	// calc focal length
	virtual void calcFocalLength() override;
	// get refractive index side A
	virtual real getRefractiveIndex_A() override;
	// get refractive index side B
	virtual real getRefractiveIndex_B() override;
	//get Radius
	virtual double getRadius() override; // the aperture stop do not has a radius. We give hier 999999999.0
	
	void setTolerance(real tolerance);

//	// make the 2d plot
	void plot2D(cv::Mat image, unsigned int scale, unsigned int thickness, unsigned int lineType) override;

	virtual void setRadius(real radius) override;
	virtual void setPosition(VectorStructR3 position) override;
	virtual void setDirection(VectorStructR3 direction) override;

	//get pointer of the Upper qwt curve
	ApertureStopQwtUp* getPointerPlotUp();

	//get pointer of the Upper qwt curve
	ApertureStopQwtDown* getPointerPlotDown();

	virtual QPolygonF* getQPolygonFCurve() override;



private:
	double mSemiHeightAperture{};
	VectorStructR3 mPointAperture{};
	VectorStructR3 mDirectionAperture{};
	double mRrefractiveIndex{};
	ApertureStopQwtUp* ApertureStopUp_Qwt_Ptr{};
	ApertureStopQwtDown* ApertureStopDown_Qwt_Ptr{};
	QPolygonF pointsofApertureStopUp{};
	QPolygonF pointsofApertureStopDown{};
	Light_LLT mLightAbsorb;
	real mToleranceAS = 1.0;
};