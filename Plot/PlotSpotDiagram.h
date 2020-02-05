#pragma once
#include "..\Analyse\Spot.h"
#include "Plot.h"
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>


class PlotSpotDiagramm : public QwtPlotCurve
{
public:
	PlotSpotDiagramm() {};
	PlotSpotDiagramm(VectorStructR3 interPointChefRay, std::vector<Spot> vectorSpot, real numericalApertur, real centerWavelenth) :
		mInterPointChefRay(interPointChefRay),
		mVectorSpot(vectorSpot),
		mNA(numericalApertur),
		mCenterWavelenth(centerWavelenth)
	{
		mScaleSpotDia = calculateScaleSpotDia();
		calcMatrixToPlot();
		
	}
	~PlotSpotDiagramm() {};

	// calculate scale spot diagram
	real calculateScaleSpotDia();

	// calculate matrix to plot
	void calcMatrixToPlot();
	
	// get matrix to plot
	cv::Mat getMatrixToPlotSpot();

	// get matrix of points to plot
	//std::vector<VectorStructR2> getPointsVector(real scale);
	std::vector<VectorStructR2> getPointsVector();

	QPolygonF getPointsVectorPolygon(double scale, double intx, double inty);

	//set Scale
	void setmaxScale(int scale);

private:
	unsigned int mSpotdiagrammNumber;
	VectorStructR3 mInterPointChefRay;
	std::vector<Spot> mVectorSpot;
	std::vector<VectorStructR2> mPoints;

	real mNA;
	real mCenterWavelenth;
	cv::Mat mAllSpotImages;
	real mscale = 0.02;
	real mScaleSpotDia;
	int maxX;
	int maxY;

	// hight 
	unsigned int mHeight = 400;
	// wide
	unsigned int mWide = 400;
	unsigned int mEdge = 20;
	
};

