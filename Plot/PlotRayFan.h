#pragma once
#include "..\Analyse\RayFan.h"
#include "..\Plot\Plot.h"
#include <qwt_plot_curve.h>
#include "..\LowLevelTracing\SurfaceIntersectionRay_LLT.h"
#include "..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\OpticalSystemElement\OpticalSystemElement.h"

class PlotRayFan
{
public:

	PlotRayFan() {};
	PlotRayFan(RayFan RayFan);
	PlotRayFan(std::shared_ptr<SurfaceIntersectionRay_LLT> Aperture, std::shared_ptr<SurfaceIntersectionRay_LLT> EntrancePupil, OpticalSystemElement OptSys, VectorStructR3 StartPointLightRay, real centerWavelenth, unsigned int numberLightRay);
	~PlotRayFan() {};

	//get the QPoints of the Y Plan
	QPolygonF getRayFanYPlanPoints(double scale, double XStart, double YStart);
	//get the QPoints of the X Plan
	QPolygonF getRayFanXPlanPoints(double scale, double XStart, double YStart);
	//get max scale from both plots
	double getScaleRayFanPlot();
	//
	void calcYPlanescale();
	void calcXPlanescale();

	double getWavelength();

private:
	unsigned int edge = 20;
	unsigned int edgeY = 40;
	// hight 
	unsigned int height = 500;
	unsigned int heightRayFan = height - 2 * edge;
	// wide
	unsigned int wide = 500;
	unsigned int wideRayFanHalfe = (wide - 2 * edge) / 2;
	double Shiftintheplot = 0;
	double symmetrie = height / 2;

	double getMaxValueOfPointX(QPolygonF points);
	double getMaxValueOfPointY(QPolygonF points);

	double getMinValueOfPointX(QPolygonF points);
	double getMinValueOfPointY(QPolygonF points);

	double outputScaleYPlane;
	double outputScaleXPlane;

	double XShiftPos = 0;
	double YShiftPos;
	double originY = 232;
	RayFan mRayFan;
	QPolygonF RayFan_Image_X_Plane_Qwt;
	QPolygonF RayFan_Image_Y_Plane_Qwt;
	QPolygonF testPointsYPlane;


	/////

	std::shared_ptr<SurfaceIntersectionRay_LLT> mAperture;
	OpticalSystemElement mOptSysEle;
	VectorStructR3 mStartPointLightRay;
	real mCenterWavelenth;
	unsigned int mNumberLightRay;
	real curRefInd = 1.0;
	std::shared_ptr<SurfaceIntersectionRay_LLT> mEntrancePupil;

};
