#pragma once
#pragma once
#include <vector>
#include "..\LowLevelTracing\SurfaceIntersectionRay_LLT.h"
#include "..\LowLevelTracing\Interaction\InteractionRay_LLT.h"
#include "..\Plot\Plot.h"
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "..\Plot\PlotSpotDiagram.h"

struct CommentandPosCommentToPlot
{
	CommentandPosCommentToPlot() {};
	~CommentandPosCommentToPlot() {};
	CommentandPosCommentToPlot(QString Comment, VectorStructR2 PositionComment)
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


class PlotParameterQwt
{
public:
	PlotParameterQwt() {};
	~PlotParameterQwt() {};



	//**load parameters of QwtPlot:



//*********************************RayTracing
//get the color of the surfaces in the optical system
	QColor getColorSurfaces();
	//get the thickness of the line of the plotted surfaces 
	double getThicknessSurfaces();
	//change the color of the surfaces to be plotted
	void setColorSurfaces(QColor color);
	//change the thickness of the surfaces to be plotted
	void setThicknessSurfaces(double thickness);
	//add a comment information to the vector of comments to be plotted on the Ray tracing plot
	void AddCommentToRayTracingPlot(QString comment, VectorStructR2 position);
	//return the vector containing the comments to be added to the plot of ray tracing
	std::vector<CommentandPosCommentToPlot> getVectorCommentsRayTracingPlot();



	//***********************************Spot Diagram
	//add a comment information to the vector of the spot diagramm to be plotted
	void AddCommentToSpotDiagramPlot(QString comment, VectorStructR2 position);
	//return the vector containing the comments to be added on the spot diagram
	std::vector<CommentandPosCommentToPlot> getVectorCommentsSpotDiagramPlot();
	//change the color of the airy disk on the spot diagram
	void setAiryDiskColor(QColor AiryDiskColor);
	//get the color of the airydisk curve of the spot diagram
	QColor getAiryDiskColor();
	//change the thickness of the curve of the airydisc
	void setAiryDiskThickness(int AiryDiskThickness);
	//get the thickness of the airydisc curve
	int getAiryDiskThickness();
	//change the color of the Spot Diagram plot
	void setSymbolColorOfSpotDiagrammPoints(QBrush SymbolColor);
	//get the color of the spot diagram plot
	QBrush getSymbolColorOfSpotDiagrammPoints();
	//change the shape of the Spot diagram plot points
	void setSymbolStyleOfSpotDiagrammPoints(QwtSymbol::Style SymbolStyle);
	//get the shape of the Spot diagram plot points
	QwtSymbol::Style getSymbolStyleOfSpotDiagrammPoints();
	//change the color of the contour of the symbol of the spot diagram spots
	void setContourColorSymbolOfSpotDiagrammPoints(QPen SymbolPen);
	//get the color of the contour of the symbol of the spot diagram spots
	QPen getContourColorSymbolOfSpotDiagrammPoints();
	//change the size of the spot diagram curve points
	void setSizeSymbolOfSpotDiagrammPoints(QSize SymbolSize);
	//get the size of the spot diagram curve points
	QSize getSizeSymbolOfSpotDiagrammPoints();
	//change the color of the frame of the spot diagramms
	void setFrameColorOfSpotDiagrammPoints(QPen ColorOfTheFrame);
	//get the color of the frame of the spot diagramms
	QPen getFrameColorOfSpotDiagrammPoints();

	//***********************************load Informations to OPD plot:
	//add a comment to the vector containing the comments to be added to the OPD plot
	void AddCommentToOPDPlot(QString comment, VectorStructR2 position);
	//get the vector containing comments information to be plotted on the OPD plot
	std::vector<CommentandPosCommentToPlot> getOPDVectorComments();
	//change the color of the OPD plot points
	void setOPDSymbolColor(QBrush SymbolColor);
	//get the color of the OPD plot points
	QBrush getOPDSymbolColor();
	//change the chape of the OPD plot points
	void setOPDSymbolStyle(QwtSymbol::Style SymbolStyle);
	//get the shape of the OPD plot shape
	QwtSymbol::Style getOPDSymbolStyle();
	//change the color of the contour of the points of the OPD curve points
	void setOPDContourColorSymbol(QPen SymbolPen);
	//get the color of the contour of the points of the OPD curve points
	QPen getOPDContourColorSymbol();
	//change the size of the OPD plot points 
	void setOPDSizeSymbol(QSize SymbolSize);
	//get the size of the OPD plot points
	QSize getOPDSizeSymbol();
	//change the frame color 
	void setOPDFrameColor(QPen ColorOfTheFrame);
	//get the frame color
	QPen getOPDFrameColor();



	//**************************************RayFan Plot
	//add a comment to the vector containing the comments to be added to the OPD plot
	void AddCommentToRayFanPlot(QString comment, VectorStructR2 position);
	//get the vector containing comments information to be plotted on the OPD plot
	std::vector<CommentandPosCommentToPlot> getRayFanVectorComments();
	//change the color of the OPD plot points
	void setRayFanSymbolColor(QBrush SymbolColor);
	//get the color of the OPD plot points
	QBrush getRayFanSymbolColor();
	//change the chape of the OPD plot points
	void setRayFanSymbolStyle(QwtSymbol::Style SymbolStyle);
	//get the shape of the OPD plot shape
	QwtSymbol::Style getRayFanSymbolStyle();
	//change the color of the contour of the points of the OPD curve points
	void setRayFanContourColorSymbol(QPen SymbolPen);
	//get the color of the contour of the points of the OPD curve points
	QPen getRayFanContourColorSymbol();
	//change the size of the OPD plot points 
	void setRayFanSizeSymbol(QSize SymbolSize);
	//get the size of the OPD plot points
	QSize getRayFanSizeSymbol();
	//change the frame color 
	void setRayFanFrameColor(QPen ColorOfTheFrame);
	//get the frame color
	QPen getRayFanFrameColor();



private:
	QColor mColorSurfaces = { 0,0,0 };
	double mThicknessSurfaces = 1;
	QString mAddedComment;
	VectorStructR2 PositionOfAddedComment;
	QColor mAiryDiskColor = QColor("black");
	int mAiryDiskThickness = 1;
	QBrush mSymbolColorSpotDiagram = QBrush(Qt::blue);
	QwtSymbol::Style mSymbolStyleSpotDiagram = QwtSymbol::Ellipse;
	QPen mSymbolPenSpotDiagram = QPen(Qt::blue, 1);
	QSize mSymbolSizeSpotDiagram = QSize(2, 2);
	QPen mColorOfTheFrameSpotDiagram = QColor("lightGrey");
	std::vector<CommentandPosCommentToPlot> mCommentandPosCommentToRayTracingPlot;
	std::vector<CommentandPosCommentToPlot> mCommentandPosCommentToSpotDiagramPlot;
	std::vector<CommentandPosCommentToPlot> mCommentandPosCommentToOPDPlot;
	std::vector<CommentandPosCommentToPlot> mCommentandPosCommentToRayFanPlot;
	QBrush mSymbolColorOPD = QBrush(Qt::white);
	QwtSymbol::Style mSymbolStyleOPD = QwtSymbol::Ellipse;
	QPen mSymbolPenOPD = QPen(Qt::black, 1);
	QSize mSymbolSizeOPD = QSize(2, 2);
	QPen mColorOfTheFrameOPD = QColor("lightGrey");

	QBrush mSymbolColorRayFan = QBrush(Qt::white);
	QwtSymbol::Style mSymbolStyleRayFan = QwtSymbol::Ellipse;
	QPen mSymbolPenRayFan = QPen(Qt::black, 1);
	QSize mSymbolSizeRayFan = QSize(2, 2);
	QPen mColorOfTheFrameRayFan = QColor("lightGrey");
};