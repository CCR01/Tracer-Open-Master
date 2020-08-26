#pragma once

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <vector>
#include <qwt_plot_marker.h>
#include<qwt_plot_renderer.h>

//to draw a line between two lenses 
class ConnecttwoSurfacesCurve : public QwtPlotCurve
{
public:
	ConnecttwoSurfacesCurve(QPointF point1, QPointF point2, QColor color, double thickness);
};


//Save the plot
void SaveQwtPlot(const QString location, QwtPlot* plot);
void SaveQwtPlotbetterResolution(QwtPlot* plot, QString FileName);

//to find the coordinates of the minimum and maximum point in Qwt samples
QPointF findPointWithMaxY(QPolygonF* mPoints);
QPointF findPointWithMinY(QPolygonF* mPoints);

//to print a given text TextToPlot in (X;Y)
class ConfiguratedText : public QwtPlotMarker
{
public:
	//print TexttoPlot at (X,Y)
	ConfiguratedText(QString TextToPlot, int XCoordinate, int YCoordinate, double size);
	ConfiguratedText(QString TextToPlot, int XCoordinate, int YCoordinate);

};

// to draw a vertical line starting of(x, y) with the length factor
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
	AiryDiskCurve(double x, double y, double radius);
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
class RectegularFrame : public QwtPlotCurve
{
public:
	RectegularFrame(int startx, int starty, int factor);

private:
	QPolygonF SpotDiagramFrameCoordinates;
	QPolygonF FrameWithLinesPoints;
	std::vector <QwtPlotCurve*> linesOftheFrame;

};

