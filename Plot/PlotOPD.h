#pragma once
#include "..\Analyse\OpticalPathDifference.h"
#include "..\Plot\Plot.h"
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>



class PlotOPD
{
public:
	PlotOPD() {};
	PlotOPD(OPD OPD);
	PlotOPD(std::shared_ptr<SurfaceIntersectionRay_LLT> Aperture, std::shared_ptr<SurfaceIntersectionRay_LLT> exitPupil, OpticalSystemElement OptSysEle,
		VectorStructR3 StartPointLightRay, real centerWavelenth, unsigned int numberLightRay);
	~PlotOPD() {};

	// calculate Matrix to plot OPD in x plane
	void calcMatrixToPlotOPD_X_Plane();

	// calculate Matrix to plot OPD in y plane
	void calcMatrixtoPlotOPD_Y_Plane();

	// get matrix to plot in x plane
	cv::Mat getMatrixToPlotOPD_X_Plane();

	// get matrix to plot in y plane
	cv::Mat getMatrixToPlotOPD_Y_Plane();

	//get points to plot in x plane mit Qwt
	QPolygonF getPointsVectorPolygon_X_Plane(double scale, double StartX, double StartY);

	//get points to plot in y plane mit Qwt
	QPolygonF getPointsVectorPolygon_Y_Plane(double scale, double StartX, double StartY);

	//calculate the scale of the OPD plot
	double getScaleOPDPlot();

	//get light wavelength
	int getWavelengthOPD();


private:
	OPD mOPD;
	unsigned int mHeight;
	unsigned int mWide;
	cv::Mat mImageOPD_X_Plane;
	cv::Mat mImageOPD_Y_Plane;
	double edge = 20;
	// hight 
	double height = 500;
	double heightOPDF = height - 2 * edge;
	// wide
	double wide = 500;
	double wideOPDFanHalfe = (wide - 2 * edge) / 2;
	double middleDiagramX_Achse = wide / 2;
	double symmetrie = height / 2;
	double Shiftintheplot = 550;

	std::shared_ptr<SurfaceIntersectionRay_LLT> mAperture;
	std::shared_ptr<SurfaceIntersectionRay_LLT> mExitPupil;
	OpticalSystemElement mOptSysEle;
	VectorStructR3 mStartPointLightRay;
	real mCenterWavelenth;
	unsigned int mNumberLightRay;
};

