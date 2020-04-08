#pragma once
#include "..\SurfaceIntersectionRay_LLT.h"
#include "..\..\Plot\Plot.h"
#include <qwt_plot_curve.h>
#include <qwt_curve_fitter.h>

class PlanGeometryQwt : public QwtPlotCurve
{


public:
	PlanGeometryQwt(double semiHeight, VectorStructR3 point, VectorStructR3 direction);

	//return the Points coordinates of the plan geometry
	QPolygonF getPoints();

private:
	QPolygonF PointsOfPlanGeometry;
	VectorStructR3 mDirectionPlan;
	VectorStructR3 mPointPlan;
	double mSemiHeightPlan;


};

class PlanGeometry_LLT : public SurfaceIntersectionRay_LLT
{
public:
	PlanGeometry_LLT() {};
	PlanGeometry_LLT(PlanGeometry_LLT &source);
	PlanGeometry_LLT& operator=(PlanGeometry_LLT& source);
	std::shared_ptr<SurfaceIntersectionRay_LLT> clone() override;
	virtual ~PlanGeometry_LLT() {};
	PlanGeometry_LLT(/*semi height*/ double semiHeight,/*point*/ VectorStructR3 point,/*direction*/ VectorStructR3 direction,/*refractive index A*/ double refractiveSideA, /*refractive index B*/ double refractiveSideB) :
		// ToDo Ques Sergej: Was soll passieren, fals mit jemand eine direction von (0,0,0) gibt? Muss ich das überprüfen?
		// Das Gleiche gilt auch für anderen Oberflächen (z.B. Sphäre, Asphäre,...)
		mSemiHeightPlan(semiHeight),
		mPointPlan(point),
		mDirectionPlan(direction),
		mRefractiveIndexA_Plan(refractiveSideA),
		mRefractiveIndexB_Plan(refractiveSideB)
	{
		calcSphericalSurfaceQwtCoord();
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


	// set refractive index side A
	virtual void setRefractiveIndexSide_A(double const& refractiveIndex) override;

	// set refractive index side B
	virtual void setRefractiveIndexSide_B(double const& refractiveIndex) override;

	// calculate the intersection information
	IntersectInformationStruct calculateIntersection(LightRayStruct const& lightray) override;

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
	virtual double getRadius() override;

	virtual void setRadius(real radius) override;
	virtual void setPosition(VectorStructR3 position) override;
	virtual void setDirection(VectorStructR3 direction) override;

	//get pointer of the qwt curve
	//PlanGeometryQwt* getPointerPlot();

	//get pointer of the qwt curve
	PlanGeometryQwt* getPointerPlot();

	//get QPolygonF of the surface
	virtual QPolygonF* getQPolygonFCurve();

	void calcSphericalSurfaceQwtCoord();

private:
	double mSemiHeightPlan;
	VectorStructR3 mPointPlan;
	VectorStructR3 mDirectionPlan;
	double mRefractiveIndexA_Plan;
	double mRefractiveIndexB_Plan;

	PlanGeometryQwt* PlanGeometry_Qwt_Ptr;
	QPolygonF pointsofPlanGeometry;

	// TODO: Attention!!!
	// Here we must be carefull! Maybe we can also use here smart pointe to delete the object (bacause of new)!
	//PlanGeometryQwt* PlanGeometry_Qwt_Ptr = new PlanGeometryQwt(mSemiHeightPlan, mPointPlan, mDirectionPlan);



};