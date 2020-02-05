#include "PlotQwt.h"
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <vector>
#include <qwt_curve_fitter.h>
#include <iostream>
#include<qwt_plot_renderer.h>
#include <qwt_painter.h>
#include <qwt_plot_marker.h>
#include <fstream>
#include <QDate> 
#include <qwt_plot_rescaler.h>
#include <typeinfo>
#include "../LowLevelTracing/Surfaces/AsphericalSurface_LLT.h"
using namespace std;


void  SaveQwtPlot(const QString location, QwtPlot* plot)
{
	plot->replot();
	QwtPlotRenderer *renderer = new QwtPlotRenderer();
	renderer->renderDocument(plot, location, QString("JPG"), QSizeF(1600, 1000), 250);

}


GridLineHorizontal::GridLineHorizontal(int x, int y, int factor)
{
	QPolygonF points;
	for (unsigned int i = 0; i < 11; i++)
	{

		points << QPointF(x + ((factor*i) / 10), y);

	}

	setPen(QColor("lightGrey"));
	setSamples(points);
}

GridLineVertical::GridLineVertical(int x, int y, int factor)
{
	QPolygonF points;

	for (unsigned int i = 0; i < 11; i++)
	{

		points << QPointF(x, y + ((factor*i) / 10));

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

ConfiguratedText::ConfiguratedText(QString TextToPlot, int XCoordinate, int YCoordinate)
{
	setValue(XCoordinate, YCoordinate);
	QwtText titel(TextToPlot);
	QFont font("Times", 12);
	titel.setFont(font);
	setLabel(titel);
}

QPointF  RayTracingQwtPlot::findPointWithMaxY(QPolygonF* mPoints)
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

QPointF  RayTracingQwtPlot::findPointWithMinY(QPolygonF* mPoints)
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

QwtText  SpotPlotDiagramQwt::label(double fieldnumber, double rmsvalue)
{
	return QwtText("RMS Field" + QString::number(fieldnumber) + ": " + QString::number(rmsvalue) + "um");
}

std::vector <double>  SpotPlotDiagramQwt::fillVectorSpotDiagramsCoordinates(int numberOfSpotDiagrams)
{

	string FileName = "SpotDiaCoord.txt"; //SpotDiaCoord.txt contain coordinates only until 20 Spot Diagrams
	ifstream infile(FileName.c_str());
	vector<vector<double>> Numbers;
	string String;
	int a;
	while (getline(infile, String))
	{
		vector<double> Line;                    //Stores each line's numbers
		stringstream Stream(String);
		while (Stream >> a)                  //Extracts numbers from 'Stream'
			Line.push_back(a);               //Each number is added to Line
		Numbers.push_back(Line);             //Each Line is added to Numbers
	}


	for (unsigned int i = 0; i < Numbers[numberOfSpotDiagrams].size(); ++i)
	{
		mAllCoordinates.push_back(Numbers[numberOfSpotDiagrams][i]);
	}

	return mAllCoordinates;

}

SpotDiagramScaleBar::SpotDiagramScaleBar(double startx, double starty)
{
	QPolygonF points;
	points << QPointF(startx, starty) << QPointF(startx, starty + 400);
	QwtSymbol *symbol = new QwtSymbol(QwtSymbol::HLine, QBrush(Qt::black), QPen(Qt::black, 1), QSize(2, 2));       // Größe in Pixel
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


SpotDiagramframe::SpotDiagramframe(int startx, int starty, int factor)
{

	SpotDiagramFrameCoordinates << QPointF(startx, starty) << QPointF(startx + factor, starty) << QPointF(startx + factor, starty + factor) << QPointF(startx, starty + factor) << QPointF(startx, starty);
	setSamples(SpotDiagramFrameCoordinates);
	setPen(QColor("lightGrey"));


}

std::vector <VectorStructR2> SpotPlotDiagramQwt::coordinatesOfFrames(int numberOfSpotDiagrams)
{
	for (unsigned int i = 0; i < mAllCoordinates.size(); i++)
	{

		VectorStructR2 coordinateframe;
		coordinateframe.setX(mAllCoordinates.at(i));
		coordinateframe.setY(mAllCoordinates.at(i + 1));
		i++;
		mcoordinatesOfFrames.push_back(coordinateframe);
	}

	return mcoordinatesOfFrames;
}



double SpotPlotDiagramQwt::getLengthTextField(int numberofspotdiagrams)
{

	double MaxWidth = 0;
	for (unsigned int i = 0; i < mAllCoordinates.size(); i++)
	{

		if (mAllCoordinates.at(i) > MaxWidth)
		{

			MaxWidth = mAllCoordinates.at(i);

		}


	}

	return MaxWidth + 600;
}

double SpotPlotDiagramQwt::getHeight()
{
	Height = mAllCoordinates.at(1);
	for (unsigned int i = 5; i < mAllCoordinates.size(); i++)
	{
		if (mAllCoordinates.at(i) > Height)
		{
			Height = mAllCoordinates.at(i);
		}
		i++;
	}

	return Height + 450;
}





///////////////////////////////////////////////////////////////////////////////////////////////


RayTracingQwtPlot::RayTracingQwtPlot(OpticalSystem_LLT optSys, SequentialRayTracing* SeqRayTrac, QwtPlot* plot, QColor color)
{

	unsigned int height = 1000;
	unsigned int Scale = 20;
	unsigned int boarterLeft = 50;
	unsigned int i = 0;
	unsigned int counter = 0;
	unsigned numRay = 0;



	for (numRay; numRay < SeqRayTrac->getAllIntersectionPointsSRT().size(); numRay)
	{

		for (i; numRay < SeqRayTrac->getAllIntersectionPointsSRT().size(); i++)
		{

			QPolygonF RaysCoordinates;

			double yStart = SeqRayTrac->getStartPoints().at(i).getY();
			double zStart = SeqRayTrac->getStartPoints().at(i).getZ();

			double yStartPlot = height / 2 - yStart * Scale;
			double zStartPlot = boarterLeft + zStart * Scale;

			RaysCoordinates << QPointF(zStartPlot, yStartPlot);

			unsigned int atSurface = 0;

			for (unsigned int j = 0; j <= optSys.getNumberOfSurfaces(); j++)
			{

				double tempY = SeqRayTrac->getAllInterPointsAtSurf_i(atSurface).at(counter).getY();
				double tempX = SeqRayTrac->getAllInterPointsAtSurf_i(atSurface).at(counter).getZ();

				double tempYplot = height / 2 - tempY * Scale;
				double tempXplot = boarterLeft + tempX * Scale;

				RaysCoordinates << QPointF(tempXplot, tempYplot);

				// got to next surface
				atSurface++;
				numRay++;

				QwtPlotCurve* Ray = new QwtPlotCurve;

				Ray->setStyle(QwtPlotCurve::Lines);

				Ray->setPen(color, 1);

				Ray->setSamples(RaysCoordinates);

				Ray->attach(plot);

			}
			counter++;

		}


	}

};




///////////////////////////////////////////////////////////////////////////////////////////////
RayTracingQwtPlot::RayTracingQwtPlot(OpticalSystem_LLT OptSys, RayTracingSystem RayTracSys) :
	mOptSys(OptSys),
	mRayTracSys(RayTracSys)
{
	//inactivate the appearnace of the x- and y axes
	for (int axis = 0; axis < QwtPlot::axisCnt; axis++)
		enableAxis(axis, false);

	QColor mColorSurfaces = mOptSys.getColorSurfaces();
	double mThicknessSurfaces = mOptSys.getThicknessSurfaces();

	//Plot the table field below the diagrams
	QwtPlotCurve* FieldSystemSurfaces = new QwtPlotCurve;
	QPolygonF PointsOfTheField;
	int Edge = mOptSys.getPosAndInteractingSurface().at(mOptSys.getPosAndInteractingSurface().size() - 1).getSurfaceInterRay_ptr()->getPoint().getZ() * 20 + 150;
	/*calculate the length of the informaation table depending on the last plotted surface*/
	PointsOfTheField << QPointF(0, 275) << QPointF(0, 300) << QPointF(Edge, 300) << QPointF(Edge, 275) << QPointF(0, 275) << QPointF(0, 150) << QPointF(Edge, 150) << QPointF(Edge, 275);
	FieldSystemSurfaces->setSamples(PointsOfTheField);
	FieldSystemSurfaces->setPen(QColor("black"), 1);
	FieldSystemSurfaces->attach(this);

	//structure the table
	QwtPlotCurve* VerLine = new QwtPlotCurve;/*add the vertical line inside the table*/
	QPolygonF PointsVer;
	PointsVer << QPointF(2 * Edge / 3, 275) << QPointF(2 * Edge / 3, 150);
	VerLine->setSamples(PointsVer);
	VerLine->setPen(QColor("black"));
	VerLine->attach(this);

	QwtPlotCurve* HorLine = new QwtPlotCurve; /*add the horizontal line inside the table*/
	QPolygonF PointsHor;
	PointsHor << QPointF(2 * Edge / 3, 200) << QPointF(Edge, 200);
	HorLine->setSamples(PointsHor);
	HorLine->setPen(QColor("black"));
	HorLine->attach(this);

	//write in the text field
	//-the Titel
	ConfiguratedText* TitleMarker = new ConfiguratedText("Layout", Edge / 2, 289);
	TitleMarker->attach(this);

	//-the Axial Length
	ConfiguratedText* Information = new ConfiguratedText("Total Axial Length: 132.988mm", Edge / 8, 250);
	Information->attach(this);

	//-the current date
	QDate date = QDate::currentDate();
	QString dateString = date.toString("dd.MM.yyyy");
	ConfiguratedText* DateMarker = new ConfiguratedText(dateString, (Edge / 8) - 60, 225);
	DateMarker->attach(this);

	//-the used Program: Zemax
	ConfiguratedText* Zemax = new ConfiguratedText("Zemax", 5 * Edge / 6, 250);
	Zemax->attach(this);
	ConfiguratedText* ZemaxNumber = new ConfiguratedText("Optic Studio X", 5 * Edge / 6, 225);
	ZemaxNumber->attach(this);

	//-the configuration number
	ConfiguratedText* Configuration = new ConfiguratedText("Configuration 1 of 1", 5 * Edge / 6, 175);
	Configuration->attach(this);

	//add a comment

	if (mOptSys.getVectorCommentsRayTracingPlot().size() != 0)
	{
		for (unsigned int i = 0; i < mOptSys.getVectorCommentsRayTracingPlot().size(); i++)
		{
			ConfiguratedText* Comment = new ConfiguratedText(mOptSys.getVectorCommentsRayTracingPlot().at(i).getComment(), mOptSys.getVectorCommentsRayTracingPlot().at(i).getPositionComment().getX(), mOptSys.getVectorCommentsRayTracingPlot().at(i).getPositionComment().getY());
			Comment->attach(this);
		}
	}




	//link the surfaces if needed
	for (unsigned int k = 0; k < (mOptSys.getPosAndInteractingSurface().size() - 2); k++)
	{
		double firstZValue = mOptSys.getPosAndInteractingSurface().at(k).getSurfaceInterRay_ptr()->getDirection().getZ();/*z coordinate of the first surface*/
		double secondZValue = mOptSys.getPosAndInteractingSurface().at(k + 1).getSurfaceInterRay_ptr()->getDirection().getZ();/*z coordinate of the second surface*/
		double RefractiveIndexOfthefirstSurface;
		double RefractiveIndexOfthesecondSurface;

		//define the needed refractive index
		if (firstZValue < 0)
		{
			RefractiveIndexOfthefirstSurface = mOptSys.getPosAndInteractingSurface().at(k).getSurfaceInterRay_ptr()->getRefractiveIndex_A();
		}
		else
			RefractiveIndexOfthefirstSurface = mOptSys.getPosAndInteractingSurface().at(k).getSurfaceInterRay_ptr()->getRefractiveIndex_B();

		if (secondZValue < 0)
		{
			RefractiveIndexOfthesecondSurface = mOptSys.getPosAndInteractingSurface().at(k + 1).getSurfaceInterRay_ptr()->getRefractiveIndex_B();
		}
		else
			RefractiveIndexOfthesecondSurface = mOptSys.getPosAndInteractingSurface().at(k + 1).getSurfaceInterRay_ptr()->getRefractiveIndex_A();

		//get the hight of the two surfaces
		double HightOfTheFirstSurface = mOptSys.getPosAndInteractingSurface().at(k).getSurfaceInterRay_ptr()->getSemiHeight();
		double HightOfTheSecondSurface = mOptSys.getPosAndInteractingSurface().at(k + 1).getSurfaceInterRay_ptr()->getSemiHeight();

		//case1: same refractive index different from 1.0 with equal heights
		if ((RefractiveIndexOfthefirstSurface == RefractiveIndexOfthesecondSurface) && (HightOfTheFirstSurface == HightOfTheSecondSurface) && (RefractiveIndexOfthefirstSurface != 1))
		{

			ConnecttwoSurfacesCurve* ConnectingLineCurveMax = new ConnecttwoSurfacesCurve(findPointWithMaxY(mOptSys.getPosAndInteractingSurface().at(k).getSurfaceInterRay_ptr()->getQPolygonFCurve()),
				findPointWithMaxY(mOptSys.getPosAndInteractingSurface().at(k + 1).getSurfaceInterRay_ptr()->getQPolygonFCurve()), mColorSurfaces, mThicknessSurfaces);
			ConnectingLineCurveMax->attach(this);

			ConnecttwoSurfacesCurve* ConnectingLineCurveMin = new ConnecttwoSurfacesCurve(findPointWithMinY(mOptSys.getPosAndInteractingSurface().at(k).getSurfaceInterRay_ptr()->getQPolygonFCurve()),
				findPointWithMinY(mOptSys.getPosAndInteractingSurface().at(k + 1).getSurfaceInterRay_ptr()->getQPolygonFCurve()), mColorSurfaces, mThicknessSurfaces);
			ConnectingLineCurveMin->attach(this);

		}

		//case2: same refractive index different from 1.0 with height of first surface < height second surface
		if ((RefractiveIndexOfthefirstSurface == RefractiveIndexOfthesecondSurface) && (HightOfTheFirstSurface < HightOfTheSecondSurface) && (RefractiveIndexOfthefirstSurface != 1))
		{
			QPointF ModifiedfirstPointMax(findPointWithMaxY(mOptSys.getPosAndInteractingSurface().at(k).getSurfaceInterRay_ptr()->getQPolygonFCurve()).x(),
				findPointWithMaxY(mOptSys.getPosAndInteractingSurface().at(k + 1).getSurfaceInterRay_ptr()->getQPolygonFCurve()).y());
			QPointF ModifiedfirstPointMin(findPointWithMinY(mOptSys.getPosAndInteractingSurface().at(k).getSurfaceInterRay_ptr()->getQPolygonFCurve()).x(),
				findPointWithMinY(mOptSys.getPosAndInteractingSurface().at(k + 1).getSurfaceInterRay_ptr()->getQPolygonFCurve()).y());

			ConnecttwoSurfacesCurve* ConnectingLineCurveMax = new ConnecttwoSurfacesCurve(ModifiedfirstPointMax,
				findPointWithMaxY(mOptSys.getPosAndInteractingSurface().at(k + 1).getSurfaceInterRay_ptr()->getQPolygonFCurve()), mColorSurfaces, mThicknessSurfaces);
			ConnectingLineCurveMax->attach(this);

			ConnecttwoSurfacesCurve* ConnectingLineVerticalMax = new ConnecttwoSurfacesCurve(ModifiedfirstPointMax, findPointWithMaxY(mOptSys.getPosAndInteractingSurface().at(k).getSurfaceInterRay_ptr()->getQPolygonFCurve()), mColorSurfaces, mThicknessSurfaces);
			ConnectingLineVerticalMax->attach(this);

			ConnecttwoSurfacesCurve* ConnectingLineCurveMin = new ConnecttwoSurfacesCurve(ModifiedfirstPointMin,
				findPointWithMinY(mOptSys.getPosAndInteractingSurface().at(k + 1).getSurfaceInterRay_ptr()->getQPolygonFCurve()), mColorSurfaces, mThicknessSurfaces);
			ConnectingLineCurveMin->attach(this);

			ConnecttwoSurfacesCurve* ConnectingLineVerticalMin = new ConnecttwoSurfacesCurve(ModifiedfirstPointMin, findPointWithMinY(mOptSys.getPosAndInteractingSurface().at(k).getSurfaceInterRay_ptr()->getQPolygonFCurve()), mColorSurfaces, mThicknessSurfaces);
			ConnectingLineVerticalMin->attach(this);

		}

		//case3: same refractive index different from 1.0 with height of first surface > height second surface
		if ((RefractiveIndexOfthefirstSurface == RefractiveIndexOfthesecondSurface) && (HightOfTheFirstSurface > HightOfTheSecondSurface) && (RefractiveIndexOfthefirstSurface != 1))
		{
			QPointF ModifiedsecondPointMax(findPointWithMaxY(mOptSys.getPosAndInteractingSurface().at(k + 1).getSurfaceInterRay_ptr()->getQPolygonFCurve()).x(),
				findPointWithMaxY(mOptSys.getPosAndInteractingSurface().at(k).getSurfaceInterRay_ptr()->getQPolygonFCurve()).y());
			QPointF ModifiedsecondPointMin(findPointWithMinY(mOptSys.getPosAndInteractingSurface().at(k + 1).getSurfaceInterRay_ptr()->getQPolygonFCurve()).x(),
				findPointWithMinY(mOptSys.getPosAndInteractingSurface().at(k).getSurfaceInterRay_ptr()->getQPolygonFCurve()).y());

			ConnecttwoSurfacesCurve* ConnectingLineCurveMax = new ConnecttwoSurfacesCurve(findPointWithMaxY(mOptSys.getPosAndInteractingSurface().at(k).getSurfaceInterRay_ptr()->getQPolygonFCurve()), ModifiedsecondPointMax, mColorSurfaces, mThicknessSurfaces);
			ConnectingLineCurveMax->attach(this);

			ConnecttwoSurfacesCurve* ConnectingLineVerticalMax = new ConnecttwoSurfacesCurve(ModifiedsecondPointMax, findPointWithMaxY(mOptSys.getPosAndInteractingSurface().at(k + 1).getSurfaceInterRay_ptr()->getQPolygonFCurve()), mColorSurfaces, mThicknessSurfaces);
			ConnectingLineVerticalMax->attach(this);

			ConnecttwoSurfacesCurve* ConnectingLineCurveMin = new ConnecttwoSurfacesCurve(findPointWithMinY(mOptSys.getPosAndInteractingSurface().at(k).getSurfaceInterRay_ptr()->getQPolygonFCurve()), ModifiedsecondPointMin, mColorSurfaces, mThicknessSurfaces);
			ConnectingLineCurveMin->attach(this);

			ConnecttwoSurfacesCurve* ConnectingLineVerticalMin = new ConnecttwoSurfacesCurve(ModifiedsecondPointMin, findPointWithMinY(mOptSys.getPosAndInteractingSurface().at(k + 1).getSurfaceInterRay_ptr()->getQPolygonFCurve()), mColorSurfaces, mThicknessSurfaces);
			ConnectingLineVerticalMin->attach(this);

		}

	}



	for (unsigned int i = 0; i < mOptSys.getPosAndCurveToPlot2DQwt().size(); i++)
	{
		mOptSys.getPosAndCurveToPlot2DQwt().at(i).getCurve()->setPen(mColorSurfaces, mThicknessSurfaces);
	}



	//plot surfaces
	for (unsigned int i = 0; i < mOptSys.getPosAndCurveToPlot2DQwt().size(); i++)
	{
		mOptSys.getPosAndCurveToPlot2DQwt().at(i).getCurve()->attach(this);
	}






	//plot rays with the given color
	for (unsigned int j = 0; j < RayTracSys.getVectorRayTracing().size(); j++)
	{
		RayTracingQwtPlot(mOptSys, RayTracSys.getVectorRayTracing().at(j).getSequentialRayTracing(), this, RayTracSys.getVectorRayTracing().at(j).getColor());
	}





	//resize the shown plot
	resize(1500, 1000);
}




///////////////////////////////////////////////////////////////////////////////////////////////
PlotOPDQwt::PlotOPDQwt(PlotOPD OPD) : mOPD(OPD)
{
	//inactivate the appearnace of the x- and y-axes
	for (int axis = 0; axis < QwtPlot::axisCnt; axis++)
		enableAxis(axis, false);

	double height = 500;
	double wide = 500;

	//Plot the frames of the 2 OPD diagrams
	for (unsigned int i = 0; i < 2; i++)
	{
		SpotDiagramframe* mSpotDiagramframe = new SpotDiagramframe(20 + 550 * i, 0, 460);
		mSpotDiagramframe->setPen(mOPD.getFrameColor());
		mSpotDiagramframe->attach(this);
	}


	//Plot the vertical and horizontal lines in the frames of the 2 OPD diagrams (Grid)
	for (unsigned int i = 0; i < 2; i++)
	{
		for (unsigned int k = 0; k < 9; k++)
		{
			double stepX = 550 * i + (460 / 10)*(k + 1);
			GridLineVertical* GridV = new GridLineVertical(20 + stepX, 0, 460);
			GridV->setPen(mOPD.getFrameColor());
			GridV->attach(this);

			double stepY = (460 / 10)*(k + 1);
			GridLineHorizontal* GridH = new GridLineHorizontal(20 + 550 * i, stepY, 460);
			GridH->setPen(mOPD.getFrameColor());
			GridH->attach(this);
		}

	}


	//Plot the x and y axis in both OPD diagrams 
	for (unsigned int j = 0; j < 2; j++)
	{
		QwtSymbol *symbolVerticalLines = new QwtSymbol(QwtSymbol::HLine, QBrush(Qt::black), QPen(Qt::black, 1), QSize(10, 10));
		QwtSymbol *symbolHorizontalLines = new QwtSymbol(QwtSymbol::VLine, QBrush(Qt::black), QPen(Qt::black, 1), QSize(10, 10));

		GridLineHorizontal* HorizontalAxis = new GridLineHorizontal(20 + 550 * j, height / 2 - 20, 460);
		HorizontalAxis->setPen(QColor("black"));
		HorizontalAxis->setSymbol(symbolHorizontalLines);
		HorizontalAxis->attach(this);

		GridLineVertical* VerticalAxisY = new GridLineVertical(550 * j + (wide / 2), 0, 460);

		VerticalAxisY->setPen(QColor("black"));
		VerticalAxisY->setSymbol(symbolVerticalLines);
		VerticalAxisY->attach(this);
	}

	//add a comment

	if (mOPD.getVectorComments().size() != 0)
	{
		for (unsigned int i = 0; i < mOPD.getVectorComments().size(); i++)
		{
			ConfiguratedText* Comment = new ConfiguratedText(mOPD.getVectorComments().at(i).getComment(), mOPD.getVectorComments().at(i).getPositionComment().getX(), mOPD.getVectorComments().at(i).getPositionComment().getY());
			Comment->attach(this);
		}
	}

	//plot the OPD Curves
	QwtSymbol *symbolOPD = new QwtSymbol(mOPD.getSymbolStyle(), mOPD.getSymbolColor(), mOPD.getContourColorSymbol(), mOPD.getSizeSymbol());       // Größe in Pixel
	QwtPlotCurve* OPDCurve = new QwtPlotCurve();
	OPDCurve->setStyle(QwtPlotCurve::Dots);
	OPDCurve->setSymbol(symbolOPD);
	OPDCurve->setSamples(OPD.getPointsVectorPolygon());
	OPDCurve->attach(this);

	//y axis labeling
	for (unsigned int i = 0; i < 2; i++)
	{
		ConfiguratedText* YLabelMarker = new ConfiguratedText("W", 240 + 550 * i, 450);
		YLabelMarker->attach(this);
	}

	//x axis labeling
	ConfiguratedText* markerHorizontalYPlane = new ConfiguratedText("Py", 470, 240);
	markerHorizontalYPlane->attach(this);

	ConfiguratedText* markerHorizontalXPlane = new ConfiguratedText("Px", 1020, 240);
	markerHorizontalXPlane->attach(this);

	//Plot the table below the diagrams
	TextField* field = new TextField(3, 1250);
	field->attach(this);
	GridLineHorizontal* HorLine = new GridLineHorizontal(800, -230, 350);
	HorLine->setPen(QColor("black"));
	HorLine->attach(this);

	QwtPlotCurve* VerLine = new QwtPlotCurve;
	QPolygonF VerLinePoints;
	VerLinePoints << QPointF(800, -100) << QPointF(800, -300);
	VerLine->setSamples(VerLinePoints);
	VerLine->setPen(QColor("black"));
	VerLine->attach(this);

	//write in the text field

	//-OPD value
	ConfiguratedText* TitleMarker = new ConfiguratedText("Optical Path Difference", 525, -75);
	TitleMarker->attach(this);

	//-the current date
	QDate date = QDate::currentDate();
	QString dateString = date.toString("dd.MM.yyyy");
	ConfiguratedText* DateMarker = new ConfiguratedText(dateString, -20, -125);
	DateMarker->attach(this);

	//-the maximum scale
	ConfiguratedText* Scale = new ConfiguratedText("Maximum Scale: +-10.000 Waves", 58, -150);
	Scale->attach(this);

	ConfiguratedText* Wave = new ConfiguratedText("0.550", -40, -175);
	Wave->attach(this);

	ConfiguratedText* ImageNumber = new ConfiguratedText("Surface: Image (S1)", 10, -275);
	ImageNumber->attach(this);

	ConfiguratedText* FileName_Type = new ConfiguratedText("TestSytem.zmx", 870, -250);
	FileName_Type->attach(this);

	ConfiguratedText* ConfigurationNumber = new ConfiguratedText("Configuration 1 of 1", 890, -275);
	ConfigurationNumber->attach(this);


	//Rescale the plot to show the plots in squares
	QwtPlotRescaler* rescaler = new QwtPlotRescaler(this->canvas());
	QwtInterval xInterval(-200, 1100);
	QwtInterval yInterval(-300, 500);
	rescaler->setRescalePolicy(QwtPlotRescaler::Fitting);
	rescaler->setIntervalHint(xBottom, xInterval);
	rescaler->setIntervalHint(yLeft, yInterval);
	rescaler->rescale();

	///resize the shown window
	resize(1400, 800);
}






///////////////////////////////////////////////////////////////////////////////////////////////

SpotPlotDiagramQwt::SpotPlotDiagramQwt(OpticalSystem_LLT OptSys, double NumberOfLines, double AiryDiskRadius, QWidget *parent) : QwtPlot(parent),
mOptSys(OptSys), mNumberOfLines(NumberOfLines), mAiryDiskRadius(AiryDiskRadius)
{
	//hide the axes scales
	for (int axis = 0; axis < QwtPlot::axisCnt; axis++)
		enableAxis(axis, false);

	//get the coordinates of the start points to plot all spot diagrams
	fillVectorSpotDiagramsCoordinates(OptSys.getVectorSpotDiagramToPlot().size() - 1);

	//attach the frames of the Spotdiagrams
	coordinatesOfFrames(OptSys.getVectorSpotDiagramToPlot().size());
	for (unsigned int i = 0; i < OptSys.getVectorSpotDiagramToPlot().size(); i++)
	{
		SpotDiagramframe* mSpotDiagramframe = new SpotDiagramframe(mcoordinatesOfFrames.at(i).getX(), mcoordinatesOfFrames.at(i).getY(), 400);
		mSpotDiagramframe->setPen(OptSys.getFrameColorOfSpotDiagrammPoints());
		mSpotDiagramframe->attach(this);
	}


	//attach the lines of the Spotdiagrams frame
	int m = 0;
	for (unsigned int i = 0; i < OptSys.getVectorSpotDiagramToPlot().size(); i++)
	{
		for (unsigned int k = 0; k < NumberOfLines; k++)
		{
			double stepX = mAllCoordinates.at(m) + (400 / (NumberOfLines + 1))*(k + 1);
			GridLineVertical* GridV = new GridLineVertical(stepX, mAllCoordinates.at(m + 1), 400);
			GridV->setPen(OptSys.getFrameColorOfSpotDiagrammPoints());
			GridV->attach(this);

			double stepY = mAllCoordinates.at(m + 1) + (400 / (NumberOfLines + 1))*(k + 1);
			GridLineHorizontal* GridH = new GridLineHorizontal(mAllCoordinates.at(m), stepY, 400);
			GridH->setPen(OptSys.getFrameColorOfSpotDiagrammPoints());
			GridH->attach(this);

		}
		m += 2;
	}

	if (OptSys.getVectorCommentsSpotDiagramPlot().size() != 0)
	{
		for (unsigned int i = 0; i < OptSys.getVectorCommentsSpotDiagramPlot().size(); i++)
		{
			ConfiguratedText* Comment = new ConfiguratedText(OptSys.getVectorCommentsSpotDiagramPlot().at(i).getComment(), OptSys.getVectorCommentsSpotDiagramPlot().at(i).getPositionComment().getX(), OptSys.getVectorCommentsSpotDiagramPlot().at(i).getPositionComment().getY());
			Comment->attach(this);
		}
	}

	// draw Airy Disk
	for (unsigned int n = 0; n < OptSys.getVectorSpotDiagramToPlot().size(); n++)
	{
		AiryDiskCurve* AiryDisk = new AiryDiskCurve(mcoordinatesOfFrames.at(n).getX() + 200, mcoordinatesOfFrames.at(n).getY() + 200, AiryDiskRadius);
		AiryDisk->setPen(OptSys.getAiryDiskColor(), OptSys.getAiryDiskThickness());
		AiryDisk->attach(this);
	}

	//attach the spot diagrams
	int j = 0;
	for (unsigned int i = 0; i < OptSys.getVectorSpotDiagramToPlot().size(); i++)
	{
		QPolygonF points;
		points = OptSys.getVectorSpotDiagramToPlot().at(i).getPlotSpotDiagramm()->getPointsVectorPolygon(OptSys.getMinSpotDiagrammScale(), mAllCoordinates.at(j), mAllCoordinates.at(j + 1));
		j += 2;

		QwtPlotCurve* curve = new QwtPlotCurve;
		curve->setStyle(QwtPlotCurve::Dots);
		QwtSymbol *symbol = new QwtSymbol(OptSys.getSymbolStyleOfSpotDiagrammPoints(),
			OptSys.getSymbolColorOfSpotDiagrammPoints(),
			OptSys.getContourColorSymbolOfSpotDiagrammPoints(),
			OptSys.getSizeSymbolOfSpotDiagrammPoints());       // Größe in Pixel
		curve->setSymbol(symbol);
		curve->setSamples(points);
		curve->attach(this);

	}

	QFont font("Times", 12);
	//write the titel of the text field
	QwtPlotMarker* marker = new QwtPlotMarker;
	marker->setValue((getLengthTextField(OptSys.getVectorSpotDiagramToPlot().size()) / 2 - 100), -75); // location of the label in plot coordinates
	QwtText titel("Spot Diagram");
	titel.setFont(font);
	marker->setLabel(titel);
	marker->attach(this);

	//write the RMS values
	for (unsigned int k = 0; k < OptSys.getVectorSpotDiagramToPlot().size(); k++)
	{
		QwtPlotMarker* markerrmsfield = new QwtPlotMarker;
		int y = -150 - k * 50;
		if (k < 9)
		{
			markerrmsfield->setValue(80, y);
		}
		else
		{
			markerrmsfield->setValue(90, y);
		}// location of the label in plot coordinates
		QwtText  str = label(k + 1, 30);
		str.setFont(font);
		markerrmsfield->setLabel(str);
		markerrmsfield->attach(this);
	}

	//insert the scale of the spot diagram at the first plot
	SpotDiagramScaleBar* ScaleBar = new SpotDiagramScaleBar(0, 0);
	ScaleBar->attach(this);


	//insert the value of the scale of the spot diagrams
	QwtPlotMarker* barScale = new QwtPlotMarker;
	QwtText scaleSpotDiag(QString::number(OptSys.getMinSpotDiagrammScale() * 400));
	barScale->setValue(-20, 200);
	barScale->setLabel(scaleSpotDiag);
	barScale->setLabelOrientation(Qt::Vertical);
	barScale->attach(this);


	//Plot the table below the diagrams
	TextField* field = new TextField(OptSys.getVectorSpotDiagramToPlot().size(), getLengthTextField(OptSys.getVectorSpotDiagramToPlot().size()));
	field->attach(this);

	//Rescale the plot to show the plots in squares
	QwtPlotRescaler* rescaler = new QwtPlotRescaler(this->canvas());
	int numberofSpotdiagrams = OptSys.getVectorSpotDiagramToPlot().size();
	QwtInterval xInterval(-200, getLengthTextField(OptSys.getVectorSpotDiagramToPlot().size()));
	QwtInterval yInterval(-numberofSpotdiagrams * 75 - 200, getHeight());
	rescaler->setRescalePolicy(QwtPlotRescaler::Fitting);
	rescaler->setIntervalHint(xBottom, xInterval);
	rescaler->setIntervalHint(yLeft, yInterval);
	rescaler->rescale();
	//give the size of the shown window
	resize(1000, 1000);
}
