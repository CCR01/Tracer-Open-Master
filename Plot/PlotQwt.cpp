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


///////////////////////////////////////////////////////////////////////////////////////////////
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
RayTracingQwtPlot::RayTracingQwtPlot(OpticalSystem_LLT optSys, SequentialRayTracing* SeqRayTrac, QwtPlot* plot, QColor color) :
	mOptSys(optSys),
	mSeqRayTrac(SeqRayTrac),
	mPlot(plot),
	mColor(color)
{

	double height = 1000;
	double Scale = 20;
	double boarterLeft = 50;

	unsigned int counter = 0;
	unsigned int numRay = 0;

	for (unsigned int i = 0; numRay < mSeqRayTrac->getAllIntersectionPointsSRT().size(); i++)

	{
		QPolygonF RaysCoordinates;

		double yStart = mSeqRayTrac->getStartPoints().at(i).getY();
		double zStart = mSeqRayTrac->getStartPoints().at(i).getZ();

		double yStartPlot = height / 2 + yStart * Scale;
		double zStartPlot = boarterLeft + zStart * Scale;

		RaysCoordinates << QPointF(zStartPlot, yStartPlot);

		unsigned int atSurface = 0;

		for (unsigned int j = 0; j <= mOptSys.getNumberOfSurfaces(); j++)
		{
			double tempY = mSeqRayTrac->getAllInterPointsAtSurface_i_filtered(atSurface).at(counter).getY();
			double tempX = mSeqRayTrac->getAllInterPointsAtSurface_i_filtered(atSurface).at(counter).getZ();

			double tempYplot = height / 2 + tempY * Scale;
			double tempXplot = boarterLeft + tempX * Scale;

			RaysCoordinates << QPointF(tempXplot, tempYplot);

			// got to next surface
			atSurface++;
			numRay++;
			QwtPlotCurve* Ray = new QwtPlotCurve;
			Ray->setStyle(QwtPlotCurve::Lines);
			Ray->setPen(color, 1);
			Ray->setSamples(RaysCoordinates);
			Ray->attach(mPlot);

		}
		counter++;

	}

};

///////////////////////////////////////////////////////////////////////////////////////////////
RayTracingQwtPlot::RayTracingQwtPlot(OpticalSystemCurves Plots, OpticalSystem_LLT OptSys, PlotParameterQwt Parameter) :
	mPlots(Plots),
	mOptSys(OptSys),
	mParameter(Parameter)
{
	//inactivate the appearnace of the x- and y axes
	for (int axis = 0; axis < QwtPlot::axisCnt; axis++)
		enableAxis(axis, false);

	QColor mColorSurfaces = mParameter.getColorSurfaces();
	double mThicknessSurfaces = mParameter.getThicknessSurfaces();

	this->setCanvasBackground(Qt::white);

	//Plot the table field below the diagrams
	QwtPlotCurve* FieldSystemSurfaces = new QwtPlotCurve;
	QPolygonF PointsOfTheField;
	double Edge;
	for (unsigned int i = 0; i < mOptSys.getPosAndInteractingSurface().size(); i++)
	{

		Edge = mOptSys.getPosAndInteractingSurface().at(mOptSys.getPosAndInteractingSurface().size() - 1).getSurfaceInterRay_ptr()->getPoint().getZ() * 20 + 150;

		if (Edge > mOptSys.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getPoint().getZ() * 20 + 150)
		{
			Edge = mOptSys.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getPoint().getZ() * 20 + 150;
		}

	}
	Edge = Edge + 150;
	double minY;
	for (unsigned int i = 0; i < mOptSys.getPosAndInteractingSurface().size(); i++)
	{
		minY = mOptSys.getPosAndInteractingSurface().at(mOptSys.getPosAndInteractingSurface().size() - 1).getSurfaceInterRay_ptr()->getPoint().getY() * 20;
		if (minY > mOptSys.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getPoint().getY() * 20)
		{
			minY = mOptSys.getPosAndInteractingSurface().at(i).getSurfaceInterRay_ptr()->getPoint().getY() * 20;
		}
	}


	/*calculate the length of the informaation table depending on the last plotted surface*/
	PointsOfTheField << QPointF(0, minY) << QPointF(0, minY - 100) << QPointF(Edge, minY - 100) << QPointF(Edge, minY) << QPointF(0, minY) << QPointF(0, minY - 500) << QPointF(Edge, minY - 500) << QPointF(Edge, minY);
	FieldSystemSurfaces->setSamples(PointsOfTheField);
	FieldSystemSurfaces->setPen(QColor("black"), 1);
	FieldSystemSurfaces->attach(this);

	//structure the table
	QwtPlotCurve* VerLine = new QwtPlotCurve;/*add the vertical line inside the table*/
	QPolygonF PointsVer;
	PointsVer << QPointF(2 * Edge / 3, minY - 100) << QPointF(2 * Edge / 3, minY - 500);
	VerLine->setSamples(PointsVer);
	VerLine->setPen(QColor("black"));
	VerLine->attach(this);

	QwtPlotCurve* HorLine = new QwtPlotCurve; /*add the horizontal line inside the table*/
	QPolygonF PointsHor;
	PointsHor << QPointF(2 * Edge / 3, minY - 350) << QPointF(Edge, minY - 350);
	HorLine->setSamples(PointsHor);
	HorLine->setPen(QColor("black"));
	HorLine->attach(this);

	//write in the text field
	//-the Titel
	ConfiguratedText* TitleMarker = new ConfiguratedText("Layout", Edge / 2, minY - 38);
	TitleMarker->attach(this);



	//-the current date
	QDate date = QDate::currentDate();
	QString dateString = date.toString("dd.MM.yyyy");
	ConfiguratedText* DateMarker = new ConfiguratedText(dateString, (Edge / 20), minY - 300);
	DateMarker->attach(this);

	//add a comment

	if (mParameter.getVectorCommentsRayTracingPlot().size() != 0)
	{
		for (unsigned int i = 0; i < mParameter.getVectorCommentsRayTracingPlot().size(); i++)
		{
			ConfiguratedText* Comment = new ConfiguratedText(mParameter.getVectorCommentsRayTracingPlot().at(i).getComment(), mParameter.getVectorCommentsRayTracingPlot().at(i).getPositionComment().getX(),
				mParameter.getVectorCommentsRayTracingPlot().at(i).getPositionComment().getY(), 12);
			Comment->attach(this);
		}
	}


	//-the configuration number
	ConfiguratedText* Configuration = new ConfiguratedText("Configuration 1 of 1", 5 * Edge / 6, minY - 400);
	Configuration->attach(this);


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
		if ( (std::abs(RefractiveIndexOfthefirstSurface - RefractiveIndexOfthesecondSurface) < 0.001) && (std::abs(HightOfTheFirstSurface - HightOfTheSecondSurface) < 0.001) && (RefractiveIndexOfthefirstSurface != 1))
		{
			QPointF connectMaxPointSurface1 = findPointWithMaxY(mOptSys.getPosAndInteractingSurface().at(k).getSurfaceInterRay_ptr()->getQPolygonFCurve());
			QPointF connectMaxPointSurface2 = findPointWithMaxY(mOptSys.getPosAndInteractingSurface().at(k + 1).getSurfaceInterRay_ptr()->getQPolygonFCurve());
			ConnecttwoSurfacesCurve* ConnectingLineCurveMax = new ConnecttwoSurfacesCurve(connectMaxPointSurface1, connectMaxPointSurface2, mColorSurfaces, mThicknessSurfaces);
			ConnectingLineCurveMax->attach(this);

			ConnecttwoSurfacesCurve* ConnectingLineCurveMin = new ConnecttwoSurfacesCurve(findPointWithMinY(mOptSys.getPosAndInteractingSurface().at(k).getSurfaceInterRay_ptr()->getQPolygonFCurve()),
				findPointWithMinY(mOptSys.getPosAndInteractingSurface().at(k + 1).getSurfaceInterRay_ptr()->getQPolygonFCurve()), mColorSurfaces, mThicknessSurfaces);
			ConnectingLineCurveMin->attach(this);

		}

		//case2: same refractive index different from 1.0 with height of first surface < height second surface
		if ( (std::abs(RefractiveIndexOfthefirstSurface - RefractiveIndexOfthesecondSurface) < 0.0001) && (HightOfTheFirstSurface < HightOfTheSecondSurface) && (RefractiveIndexOfthefirstSurface != 1))
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
		if ( (std::abs(RefractiveIndexOfthefirstSurface - RefractiveIndexOfthesecondSurface) < 0.0001) && (HightOfTheFirstSurface > HightOfTheSecondSurface) && (RefractiveIndexOfthefirstSurface != 1))
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




	for (unsigned int i = 0; i < mPlots.getVectorRayTracSurfaces().size(); i++)
	{
		mPlots.getVectorRayTracSurfaces().at(i)->setPen(mColorSurfaces, mThicknessSurfaces);
	}



	//plot surfaces
	for (unsigned int i = 0; i < mPlots.getVectorRayTracSurfaces().size(); i++)
	{
		mPlots.getVectorRayTracSurfaces().at(i)->attach(this);
	}




	//plot rays with the given color
	for (unsigned int j = 0; j < mPlots.getVectorSeqRayTracingAndColor().size(); j++)
	{

		RayTracingQwtPlot(mOptSys, mPlots.getVectorSeqRayTracingAndColor().at(j).getSequentialRayTracing(), this, mPlots.getVectorSeqRayTracingAndColor().at(j).getColor());
	}


	//resize the shown plot
	resize(1500, 1000);
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
PlotOPDQwt::PlotOPDQwt(OpticalSystemCurves Plots, PlotParameterQwt Parameter) :
	mSystemPlots(Plots),
	mParameter(Parameter)
{
	//inactivate the appearnace of the x- and y-axes
	for (int axis = 0; axis < QwtPlot::axisCnt; axis++)
		enableAxis(axis, false);

	this->setCanvasBackground(Qt::white);
	double height = 500;
	double wide = 500;

	double numberOfOPDPlots = mSystemPlots.getVectorOPDDiagram()[0].size();
	coordinatesOfFramesOPD(numberOfOPDPlots - 1);

	//Plot the frames of the 2 OPD diagrams
	for (unsigned int i = 0; i < mAllCoordinates.size(); i++)
	{
		RectegularFrame* mOPDDiagramframe = new RectegularFrame(20 + mAllCoordinates.at(i).getX(), 20 + mAllCoordinates.at(i).getY(), 460);
		mOPDDiagramframe->setPen(mParameter.getRayFanFrameColor());
		mOPDDiagramframe->attach(this);
	}


	//Plot the vertical and horizontal lines in the frames of the 2 OPD diagrams (Grid)

	for (unsigned int i = 0; i < mAllCoordinates.size(); i++)
	{
		for (unsigned int k = 0; k < 9; k++)
		{
			double stepX = 520 * i + (460 / 10) * (k + 1);
			GridLineVertical* GridV = new GridLineVertical(20 + stepX + mAllCoordinates.at(i).getX() - 520 * i, 20 + mAllCoordinates.at(i).getY(), 460);
			GridV->setPen(mParameter.getRayFanFrameColor());
			GridV->attach(this);

			double stepY = (460 / 10) * (k + 1);
			GridLineHorizontal* GridH = new GridLineHorizontal(20 + mAllCoordinates.at(i).getX(), stepY + 20 + mAllCoordinates.at(i).getY(), 460);
			GridH->setPen(mParameter.getRayFanFrameColor());
			GridH->attach(this);
		}

	}


	//Plot the x and y axis in both OPD diagrams 
	for (unsigned int j = 0; j < mAllCoordinates.size(); j++)
	{
		QwtSymbol* symbolVerticalLines = new QwtSymbol(QwtSymbol::HLine, QBrush(Qt::black), QPen(Qt::black, 1), QSize(10, 10));
		QwtSymbol* symbolHorizontalLines = new QwtSymbol(QwtSymbol::VLine, QBrush(Qt::black), QPen(Qt::black, 1), QSize(10, 10));

		GridLineHorizontal* HorizontalAxis = new GridLineHorizontal(20 + mAllCoordinates.at(j).getX(), height / 2 + mAllCoordinates.at(j).getY(), 460);
		HorizontalAxis->setPen(QColor("black"));
		HorizontalAxis->setSymbol(symbolHorizontalLines);
		HorizontalAxis->attach(this);

		GridLineVertical* VerticalAxisY = new GridLineVertical((wide / 2) + mAllCoordinates.at(j).getX(), 20 + mAllCoordinates.at(j).getY(), 460);

		VerticalAxisY->setPen(QColor("black"));
		VerticalAxisY->setSymbol(symbolVerticalLines);
		VerticalAxisY->attach(this);
	}

	//add a comment

	if (mParameter.getOPDVectorComments().size() != 0)
	{
		for (unsigned int i = 0; i < mParameter.getOPDVectorComments().size(); i++)
		{
			ConfiguratedText* Comment = new ConfiguratedText(mParameter.getOPDVectorComments().at(i).getComment(),
				mParameter.getOPDVectorComments().at(i).getPositionComment().getX(),
				mParameter.getOPDVectorComments().at(i).getPositionComment().getY());
			Comment->attach(this);
		}
	}

	//plot the OPD Curves
		  // Gr��e in Pixel
	QwtSymbol* symbolOPD;
	unsigned int j = 0;
	for (unsigned int k = 0; k < mSystemPlots.getVectorOPDDiagram().size(); k++)
	{
		j = 0;
		symbolOPD = new QwtSymbol(mParameter.getOPDSymbolStyle(k + 1), mParameter.getOPDSymbolColor(k + 1), mParameter.getOPDContourColorSymbol(k + 1), mParameter.getOPDSizeSymbol());
		for (unsigned int i = 0; i < mSystemPlots.getVectorOPDDiagram()[k].size(); i++)
		{

			QwtPlotCurve* OPDCurveYPlane = new QwtPlotCurve();
			OPDCurveYPlane->setStyle(QwtPlotCurve::Dots);
			OPDCurveYPlane->setSamples(mSystemPlots.getVectorOPDDiagram()[k].at(i)->getPointsVectorPolygon_Y_Plane(mSystemPlots.getMaxOPDPlotScale(), mAllCoordinates.at(j).getX(), mAllCoordinates.at(j).getY()));
			OPDCurveYPlane->setSymbol(symbolOPD);
			OPDCurveYPlane->attach(this);
			j++;
			QwtPlotCurve* OPDCurveXPlane = new QwtPlotCurve();
			OPDCurveXPlane->setStyle(QwtPlotCurve::Dots);
			OPDCurveXPlane->setSamples(mSystemPlots.getVectorOPDDiagram()[k].at(i)->getPointsVectorPolygon_X_Plane(mSystemPlots.getMaxOPDPlotScale(), mAllCoordinates.at(j).getX(), mAllCoordinates.at(j).getY()));
			OPDCurveXPlane->setSymbol(symbolOPD);
			OPDCurveXPlane->attach(this);
			j++;
		}

		QString Legend = "__ _ __ " + QString::number(mSystemPlots.getVectorOPDDiagram()[k].at(0)->getWavelengthOPD());
		ConfiguratedText* LegendWavelength = new ConfiguratedText(Legend, 680, -150 - k * 50, 12, mParameter.getOPDContourColorSymbol(k + 1).color());
		LegendWavelength->attach(this);
	}

	for (unsigned int k = 0; k < mAllCoordinates.size(); k++)
	{
		ConfiguratedText* YLabelMarker = new ConfiguratedText("W", 240 + mAllCoordinates.at(k).getX(), 470 + mAllCoordinates.at(k).getY(), 8);
		YLabelMarker->attach(this);
		ConfiguratedText* markerHorizontalYPlane = new ConfiguratedText("Py", 470 + mAllCoordinates.at(k).getX(), 240 + mAllCoordinates.at(k).getY(), 8);
		markerHorizontalYPlane->attach(this);
		k++;
		ConfiguratedText* XLabelMarker = new ConfiguratedText("W", 240 + mAllCoordinates.at(k).getX(), 470 + mAllCoordinates.at(k).getY(), 8);
		XLabelMarker->attach(this);
		ConfiguratedText* markerHorizontalXPlane = new ConfiguratedText("Px", 470 + mAllCoordinates.at(k).getX(), 240 + mAllCoordinates.at(k).getY(), 8);
		markerHorizontalXPlane->attach(this);
	}

	//Plot the table below the diagrams
	TextField* field = new TextField(3, getLengthTextFieldOPD());
	field->attach(this);
	GridLineHorizontal* HorLine = new GridLineHorizontal(2 * getLengthTextFieldOPD() / 3, -230, getLengthTextFieldOPD() / 3 - 100);
	HorLine->setPen(QColor("black"));
	HorLine->attach(this);

	QwtPlotCurve* VerLine = new QwtPlotCurve;
	QPolygonF VerLinePoints;
	VerLinePoints << QPointF(2 * getLengthTextFieldOPD() / 3, -100) << QPointF(2 * getLengthTextFieldOPD() / 3, -300);
	VerLine->setSamples(VerLinePoints);
	VerLine->setPen(QColor("black"));
	VerLine->attach(this);

	//write in the text field

	//-OPD value
	ConfiguratedText* TitleMarker = new ConfiguratedText("Optical Path Difference", getLengthTextFieldOPD() / 2 - 100, -75);
	TitleMarker->attach(this);

	//-the current date
	QDate date = QDate::currentDate();
	QString dateString = date.toString("dd.MM.yyyy");
	ConfiguratedText* DateMarker = new ConfiguratedText(dateString, 40, -150);
	DateMarker->attach(this);

	//-the maximum scale
	/*ConfiguratedText* Scale = new ConfiguratedText("Maximum Scale: +-10.000 Waves", 90, -150);
	Scale->attach(this);

	ConfiguratedText* Wave = new ConfiguratedText("0.550", -20, -175);
	Wave->attach(this);

	ConfiguratedText* ImageNumber = new ConfiguratedText("Surface: Image (S1)", -20, -275);
	ImageNumber->attach(this);*/

	//Rescale the plot to show the plots in squares
	QwtPlotRescaler* rescaler = new QwtPlotRescaler(this->canvas());
	QwtInterval xInterval(-200, getLengthTextFieldOPD());
	QwtInterval yInterval(-500, getHeightOPDPlot() + 100);
	rescaler->setRescalePolicy(QwtPlotRescaler::Fitting);
	rescaler->setIntervalHint(xBottom, xInterval);
	rescaler->setIntervalHint(yLeft, yInterval);
	rescaler->rescale();

	///resize the shown window
	resize(1400, 800);
}


//return the length of the field under the spot diagram depending on the number pf th fields
double PlotOPDQwt::getLengthTextFieldOPD()
{
	double LengthTextField = 0;

	for (unsigned int i = 0; i < mAllCoordinates.size(); i++)
	{
		if (mAllCoordinates.at(i).getX() > LengthTextField)
		{
			LengthTextField = mAllCoordinates.at(i).getX();
		}
	}

	return LengthTextField + 700;
}

//return the height of the field under the spot diagram depending on the number of the fileds
double PlotOPDQwt::getHeightOPDPlot()
{
	double Height = 0;

	for (unsigned int i = 5; i < mAllCoordinates.size(); i++)
	{
		if (mAllCoordinates.at(i).getY() > Height)
		{
			Height = mAllCoordinates.at(i).getY();
		}
	}

	return Height + 500;
}

//get a vector with the coordinates as (x,y) of the spot frames depending on the given number of Spot Diagrams((x1,y1),(x2,y2),..)
std::vector <VectorStructR2> PlotOPDQwt::coordinatesOfFramesOPD(int numberOffields)
{
	string FileName = "RayFanCoor.txt"; //RayFanCoor.txt contain coordinates only until 9 Ray fans
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


	for (unsigned int i = 0; i < Numbers[numberOffields].size(); ++i)
	{
		VectorStructR2 CoordinatAti = { Numbers[numberOffields][i], Numbers[numberOffields][i + 1] };
		mAllCoordinates.push_back(CoordinatAti);
		i++;
	}

	return mAllCoordinates;
}

///////////////////////////////////////////////////////////////////////////////////////////////
SpotPlotDiagramQwt::SpotPlotDiagramQwt(OpticalSystemCurves Plots, PlotParameterQwt SpotPlotParameter, double NumberOfLines, double AiryDiskRadius, QWidget* parent) : QwtPlot(parent), mSpotPlotParameter(SpotPlotParameter),
mPlots(Plots), mNumberOfLines(NumberOfLines), mAiryDiskRadius(AiryDiskRadius)
{
	//hide the axes scales
	for (int axis = 0; axis < QwtPlot::axisCnt; axis++)
		enableAxis(axis, false);

	this->setCanvasBackground(Qt::white);
	double numberofSpotdiagrams = Plots.getVectorSpotDiagramm()[0].size();


	//get the coordinates of the start points to plot all spot diagrams
	fillVectorSpotDiagramsCoordinates(numberofSpotdiagrams - 1);

	//attach the frames of the Spotdiagrams
	coordinatesOfFrames(numberofSpotdiagrams);
	for (unsigned int i = 0; i < numberofSpotdiagrams; i++)
	{
		RectegularFrame* mSpotDiagramframe = new RectegularFrame(mcoordinatesOfFrames.at(i).getX(), mcoordinatesOfFrames.at(i).getY(), 400);
		mSpotDiagramframe->setPen(mSpotPlotParameter.getFrameColorOfSpotDiagrammPoints());
		mSpotDiagramframe->attach(this);
	}


	//attach the lines of the Spotdiagrams frame
	int m = 0;
	for (unsigned int i = 0; i < numberofSpotdiagrams; i++)
	{
		for (unsigned int k = 0; k < NumberOfLines; k++)
		{
			double stepX = mAllCoordinates.at(m) + (400 / (NumberOfLines + 1)) * (k + 1);
			GridLineVertical* GridV = new GridLineVertical(stepX, mAllCoordinates.at(m + 1), 400);
			GridV->setPen(mSpotPlotParameter.getFrameColorOfSpotDiagrammPoints());
			GridV->attach(this);

			double stepY = mAllCoordinates.at(m + 1) + (400 / (NumberOfLines + 1)) * (k + 1);
			GridLineHorizontal* GridH = new GridLineHorizontal(mAllCoordinates.at(m), stepY, 400);
			GridH->setPen(mSpotPlotParameter.getFrameColorOfSpotDiagrammPoints());
			GridH->attach(this);

		}
		m += 2;
	}

	if (mSpotPlotParameter.getVectorCommentsSpotDiagramPlot().size() != 0)
	{
		for (unsigned int i = 0; i < mSpotPlotParameter.getVectorCommentsSpotDiagramPlot().size(); i++)
		{
			ConfiguratedText* Comment = new ConfiguratedText(mSpotPlotParameter.getVectorCommentsSpotDiagramPlot().at(i).getComment(), mSpotPlotParameter.getVectorCommentsSpotDiagramPlot().at(i).getPositionComment().getX(),
				mSpotPlotParameter.getVectorCommentsSpotDiagramPlot().at(i).getPositionComment().getY(), 12);
			Comment->attach(this);
		}
	}



	//attach the spot diagrams
	int j = 0;
	for (unsigned int k = 0; k < mPlots.getVectorSpotDiagramm().size(); k++)
	{
		j = 0;
		for (unsigned int i = 0; i < numberofSpotdiagrams; i++)
		{
			QPolygonF points;
			points = mPlots.getVectorSpotDiagramm()[k].at(i)->getPointsVectorPolygon(mPlots.getMaxSpotDiagrammScale(), mAllCoordinates.at(j), mAllCoordinates.at(j + 1));
			j += 2;

			QwtPlotCurve* curve = new QwtPlotCurve;
			curve->setStyle(QwtPlotCurve::Dots);
			QwtSymbol* symbol = new QwtSymbol(mSpotPlotParameter.getSymbolStyleOfSpotDiagrammPoints(k + 1),
				mSpotPlotParameter.getSymbolColorOfSpotDiagrammPoints(k + 1),
				mSpotPlotParameter.getContourColorSymbolOfSpotDiagrammPoints(k + 1),
				mSpotPlotParameter.getSizeSymbolOfSpotDiagrammPoints());       // Gr��e in Pixel
			curve->setSymbol(symbol);
			curve->setSamples(points);
			curve->attach(this);


		}

		QString Legend = "__ _ __ " + QString::number(mPlots.getVectorSpotDiagramm()[k].at(0)->getWavelength());
		ConfiguratedText* LegendWavelength = new ConfiguratedText(Legend, 680, -150 - k * 50, 12, mSpotPlotParameter.getContourColorSymbolOfSpotDiagrammPoints(k + 1).color());
		LegendWavelength->attach(this);
	}
	QFont font("Times", 12);
	//write the titel of the text field
	QwtPlotMarker* marker = new QwtPlotMarker;
	marker->setValue(getLengthTextField(numberofSpotdiagrams) / 2 - 100, -75); // location of the label in plot coordinates
	QwtText titel("Spot Diagram");
	titel.setFont(font);
	marker->setLabel(titel);
	marker->attach(this);

	//write the RMS values
	for (unsigned int i = 0; i < numberofSpotdiagrams; i++)
	{
		ConfiguratedText* RMS = new ConfiguratedText("RMS Field" + QString::number(i + 1) + ": " + QString::number(mPlots.getVectorSpotDiagramm()[0].at(i)->getSpot().getRMS_�m()) + "um", 80, -150 - i * 50);
		RMS->attach(this);
	}




	//insert the scale of the spot diagram at the first plot
	SpotDiagramScaleBar* ScaleBar = new SpotDiagramScaleBar(0, 0);
	ScaleBar->attach(this);


	//insert the value of the scale of the spot diagrams
	QwtPlotMarker* barScale = new QwtPlotMarker;
	QwtText scaleSpotDiag(QString::number(400 * mPlots.getMaxSpotDiagrammScale() / 180));
	QFont FontScale("Times", 12, QFont::Normal);
	scaleSpotDiag.setFont(FontScale);
	barScale->setValue(-12, 200);
	barScale->setLabel(scaleSpotDiag);
	barScale->setLabelOrientation(Qt::Vertical);
	barScale->attach(this);


	//Plot the table below the diagrams
	TextField* field = new TextField(numberofSpotdiagrams, getLengthTextField(numberofSpotdiagrams));
	field->attach(this);

	//draw Airy Disk
	for (unsigned int n = 0; n < numberofSpotdiagrams; n++)
	{
		AiryDiskCurve* AiryDisk = new AiryDiskCurve(mcoordinatesOfFrames.at(n).getX() + 200, mcoordinatesOfFrames.at(n).getY() + 200, AiryDiskRadius);
		AiryDisk->setPen(mSpotPlotParameter.getAiryDiskColor(), mSpotPlotParameter.getAiryDiskThickness());
		AiryDisk->attach(this);
	}

	//Rescale the plot to show the plots in squares
	QwtPlotRescaler* rescaler = new QwtPlotRescaler(this->canvas());
	QwtInterval xInterval(-200, getLengthTextField(numberofSpotdiagrams));
	QwtInterval yInterval(-numberofSpotdiagrams * 75 - 200, getHeight());
	rescaler->setRescalePolicy(QwtPlotRescaler::Fitting);
	rescaler->setIntervalHint(xBottom, xInterval);
	rescaler->setIntervalHint(yLeft, yInterval);
	rescaler->rescale();
	//give the size of the shown window
	resize(1000, 1000);
}

///////////////////////////////////////////////////////////////////////////////////////////////
PlotRayFanQwt::PlotRayFanQwt(OpticalSystemCurves Plots, PlotParameterQwt Parameter) :
	mSystemPlots(Plots),
	mParameter(Parameter)
{
	//inactivate the appearnace of the x- and y-axes
	for (int axis = 0; axis < QwtPlot::axisCnt; axis++) enableAxis(axis, false);

	this->setCanvasBackground(Qt::white);

	double height = 500;
	double wide = 500;
	double frameSize = 460;
	double numberOfRayFanPlots = mSystemPlots.getVectorRayFanDiagram().at(0).size();
	coordinatesOfFramesRayFan(numberOfRayFanPlots - 1);

	//Plot the frames
	for (unsigned int i = 0; i < mAllCoordinates.size(); i++)
	{
		RectegularFrame* mRayFanDiagramframe = new RectegularFrame(20 + mAllCoordinates.at(i).getX(), 20 + mAllCoordinates.at(i).getY(), frameSize);
		mRayFanDiagramframe->setPen(mParameter.getRayFanFrameColor());
		mRayFanDiagramframe->attach(this);
	}


	//Plot the vertical and horizontal lines in the frames
	for (unsigned int i = 0; i < mAllCoordinates.size(); i++)
	{
		for (unsigned int k = 0; k < 9; k++)
		{
			double stepX = 520 * i + (460 / 10) * (k + 1);
			GridLineVertical* GridV = new GridLineVertical(20 + stepX + mAllCoordinates.at(i).getX() - 520 * i, 20 + mAllCoordinates.at(i).getY(), frameSize);
			GridV->setPen(mParameter.getRayFanFrameColor());
			GridV->attach(this);

			double stepY = (460 / 10) * (k + 1);
			GridLineHorizontal* GridH = new GridLineHorizontal(20 + mAllCoordinates.at(i).getX(), stepY + 20 + mAllCoordinates.at(i).getY(), frameSize);
			GridH->setPen(mParameter.getRayFanFrameColor());
			GridH->attach(this);
		}

	}


	for (unsigned int j = 0; j < mAllCoordinates.size(); j++)
	{
		QwtSymbol* symbolVerticalLines = new QwtSymbol(QwtSymbol::HLine, QBrush(Qt::black), QPen(Qt::black, 1), QSize(10, 10));
		QwtSymbol* symbolHorizontalLines = new QwtSymbol(QwtSymbol::VLine, QBrush(Qt::black), QPen(Qt::black, 1), QSize(10, 10));

		GridLineHorizontal* HorizontalAxis = new GridLineHorizontal(20 + mAllCoordinates.at(j).getX(), height / 2 + mAllCoordinates.at(j).getY(), frameSize);
		HorizontalAxis->setPen(QColor("black"));
		HorizontalAxis->setSymbol(symbolHorizontalLines);
		HorizontalAxis->attach(this);

		GridLineVertical* VerticalAxisY = new GridLineVertical((wide / 2) + mAllCoordinates.at(j).getX(), 20 + mAllCoordinates.at(j).getY(), frameSize);

		VerticalAxisY->setPen(QColor("black"));
		VerticalAxisY->setSymbol(symbolVerticalLines);
		VerticalAxisY->attach(this);
	}

	//Axis Labeling
	for (unsigned int k = 0; k < mAllCoordinates.size(); k++)
	{
		ConfiguratedText* YLabelMarker = new ConfiguratedText("ey", 240 + mAllCoordinates.at(k).getX(), 470 + mAllCoordinates.at(k).getY(), 8);
		YLabelMarker->attach(this);
		ConfiguratedText* markerHorizontalYPlane = new ConfiguratedText("Py", 470 + mAllCoordinates.at(k).getX(), 240 + mAllCoordinates.at(k).getY(), 8);
		markerHorizontalYPlane->attach(this);
		k++;
		ConfiguratedText* XLabelMarker = new ConfiguratedText("ex", 240 + mAllCoordinates.at(k).getX(), 470 + mAllCoordinates.at(k).getY(), 8);
		XLabelMarker->attach(this);
		ConfiguratedText* markerHorizontalXPlane = new ConfiguratedText("Px", 470 + mAllCoordinates.at(k).getX(), 240 + mAllCoordinates.at(k).getY(), 8);
		markerHorizontalXPlane->attach(this);
	}


	//add a comment
	if (mParameter.getRayFanVectorComments().size() != 0)
	{
		for (unsigned int i = 0; i < mParameter.getRayFanVectorComments().size(); i++)
		{
			ConfiguratedText* Comment = new ConfiguratedText(mParameter.getRayFanVectorComments().at(i).getComment(),
				mParameter.getRayFanVectorComments().at(i).getPositionComment().getX(),
				mParameter.getRayFanVectorComments().at(i).getPositionComment().getY(), 12);
			Comment->attach(this);
		}
	}



	//plot the RayFan Curves



	for (unsigned int i = 0; i < mSystemPlots.getVectorRayFanDiagram().size(); i++)
	{
		QwtSymbol* symbolRayFan = new QwtSymbol(mParameter.getRayFanSymbolStyle(i + 1), mParameter.getRayFanSymbolColor(i + 1),
			mParameter.getRayFanContourColorSymbol(i + 1), mParameter.getRayFanSizeSymbol()); // Gr��e in Pixel
		unsigned int j = 0;

		for (unsigned int k = 0; k < mSystemPlots.getVectorRayFanDiagram().at(i).size(); k++)
		{
			QwtPlotCurve* PlotRayFanCurveYPlane = new QwtPlotCurve();
			PlotRayFanCurveYPlane->setStyle(QwtPlotCurve::Dots);
			PlotRayFanCurveYPlane->setSamples(mSystemPlots.getVectorRayFanDiagram().at(i).at(k)->getRayFanYPlanPoints(mSystemPlots.getMaxRayFanScale(), mAllCoordinates.at(j).getX(), mAllCoordinates.at(j).getY()));
			PlotRayFanCurveYPlane->setSymbol(symbolRayFan);
			PlotRayFanCurveYPlane->attach(this);
			j++;
			QwtPlotCurve* PlotRayFanCurveXPlane = new QwtPlotCurve();
			PlotRayFanCurveXPlane->setStyle(QwtPlotCurve::Dots);
			PlotRayFanCurveXPlane->setSamples(mSystemPlots.getVectorRayFanDiagram().at(i).at(k)->getRayFanXPlanPoints(mSystemPlots.getMaxRayFanScale(), mAllCoordinates.at(j).getX(), mAllCoordinates.at(j).getY()));
			PlotRayFanCurveXPlane->setSymbol(symbolRayFan);
			PlotRayFanCurveXPlane->attach(this);
			j++;
		}

		QString Legend = "__ _ __ " + QString::number(mSystemPlots.getVectorRayFanDiagram()[i].at(0)->getWavelength());
		ConfiguratedText* LegendWavelength = new ConfiguratedText(Legend, 680, -150 - i * 50, 12, mParameter.getRayFanContourColorSymbol(i + 1).color());
		LegendWavelength->attach(this);
	}

	//Plot the table below the diagrams
	TextField* field = new TextField(3, getLengthTextFieldRayFan());
	field->attach(this);
	GridLineHorizontal* HorLine = new GridLineHorizontal(2 * getLengthTextFieldRayFan() / 3, -230, getLengthTextFieldRayFan() / 3 - 100);
	HorLine->setPen(QColor("black"));
	HorLine->attach(this);

	QwtPlotCurve* VerLine = new QwtPlotCurve;
	QPolygonF VerLinePoints;
	VerLinePoints << QPointF(2 * getLengthTextFieldRayFan() / 3, -100) << QPointF(2 * getLengthTextFieldRayFan() / 3, -300);
	VerLine->setSamples(VerLinePoints);
	VerLine->setPen(QColor("black"));
	VerLine->attach(this);

	//write in the text field

	//-RayFan value
	ConfiguratedText* TitleMarker = new ConfiguratedText("Transverse Ray Fan Plot", getLengthTextFieldRayFan() / 2 - 100, -75, 12);
	TitleMarker->attach(this);

	//-the current date
	QDate date = QDate::currentDate();
	QString dateString = date.toString("dd.MM.yyyy");
	ConfiguratedText* DateMarker = new ConfiguratedText(dateString, 20, -125, 12);
	DateMarker->attach(this);

	//-the maximum scale
	/*ConfiguratedText* Scale = new ConfiguratedText("Maximum Scale:+-10.000um", 120, -150, 12);
	Scale->attach(this);

	ConfiguratedText* Wave = new ConfiguratedText("0.550", 0, -175, 12);
	Wave->attach(this);

	ConfiguratedText* ImageNumber = new ConfiguratedText("Surface: Image (S1)", 50, -275, 12);
	ImageNumber->attach(this);

	ConfiguratedText* FileName_Type = new ConfiguratedText("TestSytem", 2 * getLengthTextFieldRayFan() / 3 + 250, -250, 12);
	FileName_Type->attach(this);

	ConfiguratedText* ConfigurationNumber = new ConfiguratedText("Configuration 1 of 1", 2 * getLengthTextFieldRayFan() / 3 + 250, -275, 12);
	ConfigurationNumber->attach(this);
	*/

	//Rescale the plot to show the plots in squares
	QwtPlotRescaler* rescaler = new QwtPlotRescaler(this->canvas());
	QwtInterval xInterval(-200, getLengthTextFieldRayFan());
	QwtInterval yInterval(-300, getHeightRayFanPlot());
	rescaler->setRescalePolicy(QwtPlotRescaler::Fitting);
	rescaler->setIntervalHint(xBottom, xInterval);
	rescaler->setIntervalHint(yLeft, yInterval);
	rescaler->rescale();

	///resize the shown window
	resize(1600, 1000);
}

std::vector <VectorStructR2> PlotRayFanQwt::coordinatesOfFramesRayFan(int numberOffields)
{

	string FileName = "RayFanCoor.txt"; //RayFanCoor.txt contain coordinates only until 9 Ray fans
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


	for (unsigned int i = 0; i < Numbers[numberOffields].size(); ++i)
	{
		VectorStructR2 CoordinatAti = { Numbers[numberOffields][i], Numbers[numberOffields][i + 1] };
		mAllCoordinates.push_back(CoordinatAti);
		i++;
	}

	return mAllCoordinates;

}

double PlotRayFanQwt::getLengthTextFieldRayFan()
{
	double LengthTextField = 0;

	for (unsigned int i = 0; i < mAllCoordinates.size(); i++)
	{
		if (mAllCoordinates.at(i).getX() > LengthTextField)
		{
			LengthTextField = mAllCoordinates.at(i).getX();
		}
	}

	return LengthTextField + 700;
}

double PlotRayFanQwt::getHeightRayFanPlot()
{
	double Height = 0;

	for (unsigned int i = 5; i < mAllCoordinates.size(); i++)
	{
		if (mAllCoordinates.at(i).getY() > Height)
		{
			Height = mAllCoordinates.at(i).getY();
		}
	}

	return Height + 500;
}

