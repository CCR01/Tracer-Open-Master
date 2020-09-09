#include "QwtPloItems.h"
#include <qwt_symbol.h>
#include <qwt_plot_renderer.h>

void  SaveQwtPlot(const QString location, QwtPlot* plot)
{
	plot->replot();
	QwtPlotRenderer* renderer = new QwtPlotRenderer();
	renderer->renderDocument(plot, location, QString("JPG"), QSizeF(1600, 1000), 1200);

}


void SaveQwtPlotbetterResolution(QwtPlot* plot, QString FileName)
{
	plot->replot();
	QPixmap pix = QPixmap::grabWidget(plot);
	QPixmap pixmap(1600, 1200);
	pixmap.rect();
	QPainter* painter = new QPainter(&pixmap);
	QwtPlotRenderer rend;
	rend.render(plot, painter, plot->geometry());
	pixmap.save(FileName/*"e.g. Name.jpg"*/);

}

QPointF  findPointWithMaxY(QPolygonF* mPoints)
{
	QPointF PointWithMaxY(mPoints->at(0));

	for (unsigned int i = 0; i < mPoints->size(); i++)
	{
		if (PointWithMaxY.y() < mPoints->at(i).y())
		{
			PointWithMaxY = mPoints->at(i);
		}
	}

	return PointWithMaxY;
}

QPointF findPointWithMinY(QPolygonF* mPoints)
{
	QPointF PointWithMinY(mPoints->at(0));

	for (unsigned int i = 0; i < mPoints->size(); i++)
	{
		if (PointWithMinY.y() > mPoints->at(i).y())
		{
			PointWithMinY = mPoints->at(i);
		}
	}

	return PointWithMinY;
}

GridLineHorizontal::GridLineHorizontal(int x, int y, int factor)
{
	QPolygonF points;
	for (unsigned int i = 0; i < 11; i++)
	{

		points << QPointF(x + ((factor * i) / 10), y);

	}

	setPen(QColor("lightGrey"));
	setSamples(points);
}

GridLineVertical::GridLineVertical(int x, int y, int factor)
{
	QPolygonF points;

	for (unsigned int i = 0; i < 11; i++)
	{

		points << QPointF(x, y + ((factor * i) / 10));

	}
	setPen(QColor("lightGrey"));
	setSamples(points);
}

ConnecttwoSurfacesCurve::ConnecttwoSurfacesCurve(QPointF point1, QPointF point2, QColor color, double thickness)
{
	QPolygonF ConnectingLinePoints;
	ConnectingLinePoints << point1 << point2;
	setSamples(ConnectingLinePoints);
	setPen(color, thickness);

};

ConfiguratedText::ConfiguratedText(QString TextToPlot, int XCoordinate, int YCoordinate, double size)
{
	setValue(XCoordinate, YCoordinate);
	QwtText titel(TextToPlot);
	titel.setColor(textColor);
	QFont font("Times", size);
	titel.setFont(font);
	setLabel(titel);
}

void setTextColor(QColor newColor);

ConfiguratedText::ConfiguratedText(QString TextToPlot, int XCoordinate, int YCoordinate)
{
	double HalfLengthText = TextToPlot.length();
	setValue(XCoordinate, YCoordinate);
	QwtText titel(TextToPlot);
	QFont font("Times", 12);
	titel.setFont(font);
	setLabel(titel);
}

ConfiguratedText::ConfiguratedText(QString TextToPlot, int XCoordinate, int YCoordinate, double size, QColor color)
{
	double HalfLengthText = TextToPlot.length();
	setValue(XCoordinate, YCoordinate);
	QwtText titel(TextToPlot);
	titel.setColor(color);
	QFont font("Times", size);
	titel.setFont(font);
	setLabel(titel);
}


AiryDiskCurve::AiryDiskCurve(double x, double y, double radius)
{
	//QwtPlotItem
	//draw---painter
	double numSamples = 10000;
	double distanceXminXmax = 2 * radius;
	double deltaX = distanceXminXmax / numSamples;


	for (unsigned int i = 0; i < numSamples; i++)
	{
		double stepsX = i * deltaX;
		double dx = x - radius + stepsX;
		double dy = y + (std::sqrt(std::pow(radius, 2) - std::pow((dx - x), 2)));
		AiryDiskCoordinates << QPointF(dx, dy);
	}

	for (unsigned int i = 0; i < numSamples; i++)
	{
		double stepsX = i * deltaX;
		double dx = x + radius - stepsX;
		double dy = y - (std::sqrt(std::pow(radius, 2) - std::pow((dx - x), 2)));

		AiryDiskCoordinates << QPointF(dx, dy);

	}

	setSamples(AiryDiskCoordinates);
	setPen(QColor("black"), 1);
}

SpotDiagramScaleBar::SpotDiagramScaleBar(double startx, double starty)
{
	setPen(QPen(Qt::red, 2));
	QPolygonF points;
	points << QPointF(startx, starty) << QPointF(startx, starty + 400);
	QwtSymbol* symbol = new QwtSymbol(QwtSymbol::HLine, QBrush(Qt::red), QPen(Qt::red, 2), QSize(8, 4));       // Größe in Pixel
	setSymbol(symbol);
	setSamples(points);

}


TextField::TextField(int numberOfSpotDiagrams, double length)
{

	int height = 150 + 50 * numberOfSpotDiagrams;
	QPolygonF TextFieldCoordinates;
	TextFieldCoordinates << QPointF(-100, -100) << QPointF(-100 + length, -100) << QPointF(-100 + length, -50) << QPointF(-100, -50) << QPointF(-100, -height) << QPointF(-100 + length, -height) << QPointF(-100 + length, -100);
	setSamples(TextFieldCoordinates);
	setPen(QColor("black"), 1);
}


RectegularFrame::RectegularFrame(int startx, int starty, int factor)
{

	SpotDiagramFrameCoordinates << QPointF(startx, starty) << QPointF(startx + factor, starty) << QPointF(startx + factor, starty + factor) << QPointF(startx, starty + factor) << QPointF(startx, starty);
	setSamples(SpotDiagramFrameCoordinates);
	setPen(QColor("lightGrey"));


}