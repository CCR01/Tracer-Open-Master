#pragma once
#pragma once
#include <vector>
#include "..\LowLevelTracing\SurfaceIntersectionRay_LLT.h"
#include "..\LowLevelTracing\Interaction\InteractionRay_LLT.h"
#include "..\Plot\Plot.h"
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "..\Plot\PlotSpotDiagram.h"
#include <qwt_symbol.h>

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
	void setSymbolColorOfSpotDiagrammPoints(QBrush SymbolColor, int WavelengthNumber);
	//get the color of the spot diagram plot
	QBrush getSymbolColorOfSpotDiagrammPoints(int WavelengthNumber);
	//change the shape of the Spot diagram plot points
	void setSymbolStyleOfSpotDiagrammPoints(QwtSymbol::Style SymbolStyle, int Wavelengthnumber);
	//get the shape of the Spot diagram plot points
	QwtSymbol::Style getSymbolStyleOfSpotDiagrammPoints(int Wavelengthnumber);
	//change the color of the contour of the symbol of the spot diagram spots
	void setContourColorSymbolOfSpotDiagrammPoints(QPen SymbolPen, int numberOfWavelength);
	//get the color of the contour of the symbol of the spot diagram spots
	QPen getContourColorSymbolOfSpotDiagrammPoints(int numberOfWavelength);
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
	void setOPDSymbolColor(QBrush SymbolColor, int Wavelengthnumber);
	//get the color of the OPD plot points
	QBrush getOPDSymbolColor(int Wavelengthnumber);
	//change the chape of the OPD plot points
	void setOPDSymbolStyle(QwtSymbol::Style SymbolStyle, int WavelengthNumber);
	//get the shape of the OPD plot shape
	QwtSymbol::Style getOPDSymbolStyle(int WavelengthNumber);
	//change the color of the contour of the points of the OPD curve points
	void setOPDContourColorSymbol(QPen SymbolPen, int Wavelength);
	//get the color of the contour of the points of the OPD curve points
	QPen getOPDContourColorSymbol(int Wavelength);
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
	void setRayFanSymbolColor(QBrush SymbolColor, int Wavelength);
	//get the color of the OPD plot points
	QBrush getRayFanSymbolColor(int Wavelength);
	//change the chape of the OPD plot points
	void setRayFanSymbolStyle(QwtSymbol::Style SymbolStyle, int Wavelength);
	//get the shape of the OPD plot shape
	QwtSymbol::Style getRayFanSymbolStyle(int Wavelength);
	//change the color of the contour of the points of the OPD curve points
	void setRayFanContourColorSymbol(QPen SymbolPen, int Wavelength);
	//get the color of the contour of the points of the OPD curve points
	QPen getRayFanContourColorSymbol(int Wavelength);
	//change the size of the OPD plot points 
	void setRayFanSizeSymbol(QSize SymbolSize);
	//get the size of the OPD plot points
	QSize getRayFanSizeSymbol();
	//change the frame color 
	void setRayFanFrameColor(QPen ColorOfTheFrame);
	//get the frame color
	QPen getRayFanFrameColor();



private:

	//Surfaces Ray Tracing
	QColor mColorSurfaces = { 0,0,0 };
	double mThicknessSurfaces = 1;
	QString mAddedComment;
	VectorStructR2 PositionOfAddedComment;

	//Spot Diagram
	QColor mAiryDiskColor = QColor("black");
	int mAiryDiskThickness = 1;
	std::vector < QBrush> mSymbolColorSpotDiagramVector = { QBrush(Qt::blue),QBrush(Qt::green),QBrush(Qt::red),QBrush(Qt::darkMagenta),QBrush(Qt::darkCyan),QBrush(Qt::darkYellow),QBrush(Qt::magenta),QBrush(Qt::darkRed),QBrush(Qt::darkBlue) };
	std::vector<QwtSymbol::Style> mSymbolStyleSpotDiagramVector = { QwtSymbol::XCross, QwtSymbol::Cross,QwtSymbol::Star1, QwtSymbol::Ellipse, QwtSymbol::Rect,  QwtSymbol::Star2, QwtSymbol::Triangle, QwtSymbol::Diamond, QwtSymbol::LTriangle, QwtSymbol::Hexagon };
	std::vector < QPen> mSymbolPenSpotDiagramVector = { QPen(Qt::blue, 1),  QPen(Qt::green, 1),QPen(Qt::red, 1),QPen(Qt::darkMagenta, 1),QPen(Qt::darkCyan, 1),QPen(Qt::darkYellow, 1),QPen(Qt::magenta, 1),QPen(Qt::darkRed, 1),QPen(Qt::darkBlue, 1) };
	QSize mSymbolSizeSpotDiagram = QSize(4, 4);
	QPen mColorOfTheFrameSpotDiagram = QColor("lightGrey");
	std::vector<CommentandPosCommentToPlot> mCommentandPosCommentToRayTracingPlot;
	std::vector<CommentandPosCommentToPlot> mCommentandPosCommentToSpotDiagramPlot;
	std::vector<CommentandPosCommentToPlot> mCommentandPosCommentToOPDPlot;
	std::vector<CommentandPosCommentToPlot> mCommentandPosCommentToRayFanPlot;

	//OPD
	std::vector < QBrush> mSymbolColorOPD = { QBrush(Qt::blue),QBrush(Qt::green),QBrush(Qt::red),QBrush(Qt::darkMagenta),QBrush(Qt::darkCyan),QBrush(Qt::darkYellow),QBrush(Qt::magenta),QBrush(Qt::darkRed),QBrush(Qt::darkBlue) };
	std::vector < QwtSymbol::Style> mSymbolStyleOPD = { QwtSymbol::XCross, QwtSymbol::Cross, QwtSymbol::Ellipse, QwtSymbol::Rect, QwtSymbol::Star1, QwtSymbol::Star2, QwtSymbol::Triangle, QwtSymbol::Diamond, QwtSymbol::LTriangle, QwtSymbol::Hexagon };
	std::vector < QPen> mSymbolPenOPD = { QPen(Qt::blue, 1),  QPen(Qt::green, 1),QPen(Qt::red, 1),QPen(Qt::darkMagenta, 1),QPen(Qt::darkCyan, 1),QPen(Qt::darkYellow, 1),QPen(Qt::magenta, 1),QPen(Qt::darkRed, 1),QPen(Qt::darkBlue, 1), QPen(Qt::black, 1) };
	QSize mSymbolSizeOPD = QSize(2, 2);
	QPen mColorOfTheFrameOPD = QColor("lightGrey");

	//Ray Fan
	std::vector < QBrush> mSymbolColorRayFan = { QBrush(Qt::blue),QBrush(Qt::green),QBrush(Qt::red),QBrush(Qt::darkMagenta),QBrush(Qt::darkCyan),QBrush(Qt::darkYellow),QBrush(Qt::magenta),QBrush(Qt::darkRed),QBrush(Qt::darkBlue) };
	std::vector<QwtSymbol::Style>  mSymbolStyleRayFan = { QwtSymbol::XCross, QwtSymbol::Cross, QwtSymbol::Ellipse, QwtSymbol::Rect, QwtSymbol::Star1, QwtSymbol::Star2, QwtSymbol::Triangle, QwtSymbol::Diamond, QwtSymbol::LTriangle, QwtSymbol::Hexagon };
	std::vector < QPen> mSymbolPenRayFan = { QPen(Qt::blue, 1),  QPen(Qt::green, 1),QPen(Qt::red, 1),QPen(Qt::darkMagenta, 1),QPen(Qt::darkCyan, 1),QPen(Qt::darkYellow, 1),QPen(Qt::magenta, 1),QPen(Qt::darkRed, 1),QPen(Qt::darkBlue, 1) };
	QSize mSymbolSizeRayFan = QSize(4, 4);
	QPen mColorOfTheFrameRayFan = QColor("lightGrey");
};