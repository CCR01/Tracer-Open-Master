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
	QPolygonF getPointsVectorPolygon_X_Plane();

	//get points to plot in x plane mit Qwt
	QPolygonF getPointsVectorPolygon();

	//load Informations to OPD plot:
	//add a comment to the vector containing the comments to be added to the OPD plot
	void AddCommentToOPDPlot(QString comment, VectorStructR2 position);
	//get the vector containing comments information to be plotted on the OPD plot
	std::vector<CommentandPosCommentToPlotInOPD> getVectorComments();
	//change the color of the OPD plot points
	void setSymbolColor(QBrush SymbolColor);
	//get the color of the OPD plot points
	QBrush getSymbolColor();
	//change the chape of the OPD plot points
	void setSymbolStyle(QwtSymbol::Style SymbolStyle);
	//get the shape of the OPD plot shape
	QwtSymbol::Style getSymbolStyle();
	//change the color of the contour of the points of the OPD curve points
	void setContourColorSymbol(QPen SymbolPen);
	//get the color of the contour of the points of the OPD curve points
	QPen getContourColorSymbol();
	//change the size of the OPD plot points 
	void setSizeSymbol(QSize SymbolSize);
	//get the size of the OPD plot points
	QSize getSizeSymbol();
	//change the frame color 
	void setFrameColor(QPen ColorOfTheFrame);
	//get the frame color
	QPen getFrameColor();

private:
	OPD mOPD;
	unsigned int mHeight;
	unsigned int mWide;
	cv::Mat mImageOPD_X_Plane;
	cv::Mat mImageOPD_Y_Plane;
	std::vector<CommentandPosCommentToPlotInOPD> mCommentandPosCommentToPlot;
	QBrush mSymbolColorOPD = QBrush(Qt::white);
	QwtSymbol::Style mSymbolStyleOPD = QwtSymbol::Ellipse;
	QPen mSymbolPenOPD = QPen(Qt::black, 1);
	QSize mSymbolSizeOPD = QSize(2, 2);
	QPen mColorOfTheFrameOPD = QColor("lightGrey");

};

