#pragma once
#include "ImportantStructures.h"
#include "Interaction/InteractionRay_LLT.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QPolygonF> 


class SurfaceIntersectionRay_LLT {
public:
	SurfaceIntersectionRay_LLT();
	virtual ~SurfaceIntersectionRay_LLT();
	virtual std::shared_ptr<SurfaceIntersectionRay_LLT> clone() = 0;
	

	// calculate the intersection information
	virtual IntersectInformationStruct calculateIntersection(LightRayStruct const lightRay) = 0;
	
	
	// We need those functions for ray aiming
	// get semt height
	virtual real getSemiHeight() = 0;
	//get point
	virtual VectorStructR3 getPoint() = 0;
	// get direction
	virtual VectorStructR3 getDirection() = 0;
	// get focal length side A
	virtual real getFocalLength() = 0;
	// get focal length side B
	virtual real getFocalLength_dash() = 0;
	// get refractive index side A
	virtual real getRefractiveIndex_A() = 0;
	// get refractive index side B
	virtual real getRefractiveIndex_B() = 0;
	// get radius of surface
	virtual real getRadius() = 0;
	// calc focal length
	virtual void calcFocalLength() = 0;

	virtual void setRefractiveIndexSide_A(double const refractiveIndexLeft) = 0;
	virtual void setRefractiveIndexSide_B(double const refractiveIndexRight) = 0;

	virtual void setRadius(real radius) = 0;
	virtual void setPosition(VectorStructR3 position) = 0;
	virtual void setDirection(VectorStructR3 direction) = 0;

	virtual void plot2D(cv::Mat image, unsigned int scale, unsigned int lineType, unsigned int thickness) = 0;

	//get QPolygonF of surface
	virtual QPolygonF* getQPolygonFCurve() = 0;

	virtual std::string getSurfaceType() = 0;
};



