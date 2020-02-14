#pragma once
#include "..\Analyse\OpticalPathDifference.h"
#include "..\Plot\Plot.h"
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>

struct CommentandPosCommentToPlotInOPD
{
	CommentandPosCommentToPlotInOPD() {};
	~CommentandPosCommentToPlotInOPD() {};
	CommentandPosCommentToPlotInOPD(QString Comment, VectorStructR2 PositionComment)
	{
		mComment = Comment;
		mPositionComment = PositionComment;
	}
	QString mComment;
	VectorStructR2 mPositionComment;

	//set Image name
	void setComment(QString Comment);
	//get Image name
	QString getComment();
	// set PlotSpot Diagramm
	void setPositionComment(VectorStructR2 PositionComment);
	//get Plot Spot Diagramm
	VectorStructR2 getPositionComment();
};


class PlotOPD
{
public:
	PlotOPD() {};
	PlotOPD(OPD OPD) :
		mOPD(OPD)

	{
		calcMatrixToPlotOPD_X_Plane();
		calcMatrixtoPlotOPD_Y_Plane();
	}
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
	QPolygonF getPointsVectorPolygon(double scale, double StartX, double StartY);

	//calculate the scale of the OPD plot
	double getScaleOPDPlot();

private:
	OPD mOPD;
	unsigned int mHeight;
	unsigned int mWide;
	cv::Mat mImageOPD_X_Plane;
	cv::Mat mImageOPD_Y_Plane;
};

