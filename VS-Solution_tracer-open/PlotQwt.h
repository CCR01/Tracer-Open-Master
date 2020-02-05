#pragma once
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <vector>
#include "..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\SequentialRayTracing\SequentialRayTracer.h" 
#include <qwt_plot_marker.h>
#include "..\..\Plot\PlotOPD.h"


class RayTracingQwtPlot : public QwtPlot
{
public:

	//plot one ray system in plot with a defined color
	RayTracingQwtPlot(OpticalSystem_LLT optSys, SequentialRayTracing* SeqRayTrac, QwtPlot* plot, QColor color);
	//plot surfaces and rays in one plot
	RayTracingQwtPlot(OpticalSystem_LLT optSys, RayTracingSystem RayTracSys);
	

	//to find the coordinates of the minimum and maximum point in Qwt samples
	QPointF findPointWithMaxY(QPolygonF* mPoints);
	QPointF findPointWithMinY(QPolygonF* mPoints);

private:
	
	OpticalSystem_LLT mOptSys;
	RayTracingSystem mRayTracSys;
};



//to draw a line between two lenses 
class ConnecttwoSurfacesCurve : public QwtPlotCurve
{
public:
	ConnecttwoSurfacesCurve(QPointF point1, QPointF point2, QColor color, double thickness);
};



class PlotOPDQwt : public QwtPlot
{
public:
	//Plot the optical path difference 
	PlotOPDQwt(PlotOPD mOPD);

private:
	PlotOPD mOPD;
};



class SpotPlotDiagramQwt : public QwtPlot
{
public:

	//plot spot diagrams
	SpotPlotDiagramQwt(OpticalSystem_LLT OptSys, double NumberOfLines, double AiryDiskRadius, QWidget* = NULL);
	
	//get a vector with the coordinates as (x,y) of the spot frames depending on the given number of Spot Diagrams((x1,y1),(x2,y2),..)
	std::vector <VectorStructR2> coordinatesOfFrames(int numberOfSpotDiagrams);
	//get a vector with the coordinates of the spot frames depending on the given number of Spot Diagrams (x1,y1,x2,y2,..)
	std::vector <double> fillVectorSpotDiagramsCoordinates(int numberOfSpotDiagrams);
	//return the length of the field under the spot diagram depending on the number of the spot diagrams
	double getLengthTextField(int numberofspotdiagrams);
	//write the RMS value of the given field
	QwtText label(double fieldnumber, double rmsvalue);
	//return the height of the plot
	double getHeight();


private:
	OpticalSystem_LLT mOptSys;
	double mNumberOfLines;
	double mAiryDiskRadius;
	std::vector <VectorStructR2> mcoordinatesOfFrames;
	std::vector <double> mAllCoordinates;
	double Height;
};





//Save the plot
void SaveQwtPlot(const QString location, QwtPlot* plot);



//to print a given text TextToPlot in (X;Y)
class ConfiguratedText : public QwtPlotMarker
{
public:
	//print TexttoPlot at (X,Y)
	ConfiguratedText(QString TextToPlot, int XCoordinate, int YCoordinate);
};





//to draw a vertical line starting of (x,y) with the length factor
class GridLineVertical : public QwtPlotCurve
{
public:
	GridLineVertical(int x, int y, int factor);
};

//to draw a horizontal line starting of (x,y) with the length factor
class GridLineHorizontal : public QwtPlotCurve
{
public:
	GridLineHorizontal(int x, int y, int factor);
};



//to draw the AiryDisk with the center (x,y) and a given radius
class AiryDiskCurve : public QwtPlotCurve
{
public:
	AiryDiskCurve (double x, double y, double radius);
private:
	QPolygonF AiryDiskCoordinates;
};


//to draw the Scale bar at the first diagram in the spot Diagrams
class SpotDiagramScaleBar : public QwtPlotCurve
{
public:
	SpotDiagramScaleBar(double startx, double starty);
	
};


//to draw a text field under the diagrams
class TextField : public QwtPlotCurve
{
public: 
	TextField(int numberOfSpotDiagrams, double length);
	
};


//to draw a frame for the curves starting from (x,y) draw a box with the edge factor
class SpotDiagramframe : public QwtPlotCurve
{
public:
	SpotDiagramframe(int startx, int starty, int factor);
	
private:
	QPolygonF SpotDiagramFrameCoordinates;
	QPolygonF FrameWithLinesPoints;
	std::vector <QwtPlotCurve*> linesOftheFrame;

};





