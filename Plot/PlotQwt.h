#pragma once
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <vector>
#include "..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\SequentialRayTracing\SequentialRayTracer.h" 
#include <qwt_plot_marker.h>
#include "..\..\Plot\PlotOPD.h"
#include "..\Plot\QwtPloItems.h"
#include "..\Plot\PlotParameterQwt.h"
#include "..\Plot\PlotRayFan.h"

class SystemPlots
{
public:
	SystemPlots() {};
	~SystemPlots() {};


	// fill vector plots
	std::vector<QwtPlotCurve*> getCurveVector()
	{
		return mVectorCurve;
	}
	//get vector plots

	void fillCurveVector(QwtPlotCurve* curvept)
	{
		mVectorCurve.push_back(curvept);
	}

	// fill the vector with rayFan
	void fillVectorRayFanDiagramToPlot(PlotRayFan* plotRayFan);

	//get vector ray fan diagrams
	std::vector<PlotRayFan*> getVectorRayFanDiagram();

	//get min Scale Ray Fan
	double getMaxRayFanScale();


	// fill the vector with rayFan
	void fillVectorplotOPDDiagramToPlot(PlotOPD* plotOPD);


	//get vector ray fan diagrams
	std::vector<PlotOPD*> getVectorOPDDiagram();

	//get min Scale Ray Fan
	double getMaxOPDPlotScale();

private:
	std::vector<PlotRayFan*> mVectorRayPlotDiagramm;
	std::vector<PlotOPD*> mVectorOPDPlotDiagramm;
	std::vector<QwtPlotCurve*> mVectorCurve;
};




class RayTracingQwtPlot : public QwtPlot
{
public:

	//plot one ray line with a defined color
	RayTracingQwtPlot(OpticalSystem_LLT optSys, SequentialRayTracing* SeqRayTrac, QwtPlot* plot, QColor color);
	//plot surfaces and rays in one plot
	RayTracingQwtPlot(OpticalSystem_LLT optSys, RayTracingSystem RayTracSys, PlotParameterQwt Parameter);

private:

	PlotParameterQwt mParameter;
	OpticalSystem_LLT mOptSys;
	RayTracingSystem mRayTracSys;
	SystemPlots mSystem;
	SequentialRayTracing* mSeqRayTrac;
	QwtPlot* mPlot;
	QColor mColor;
};






class PlotOPDQwt : public QwtPlot
{
public:
	//Plot the optical path difference 
	PlotOPDQwt(SystemPlots Plots, PlotOPD mOPD, PlotParameterQwt Parameter);
	//return the length of the field under the spot diagram depending on the number pf th fields
	double getLengthTextFieldOPD();
	//return the height of the field under the spot diagram depending on the number of the fileds
	double getHeightOPDPlot();
	//get a vector with the coordinates as (x,y) of the spot frames depending on the given number of Spot Diagrams((x1,y1),(x2,y2),..)
	std::vector <VectorStructR2> coordinatesOfFramesOPD(int numberOffields);

private:
	SystemPlots mSystemPlots;
	PlotOPD mOPD;
	PlotParameterQwt mParameter;
	std::vector <VectorStructR2> mAllCoordinates;
};


class SpotPlotDiagramQwt : public QwtPlot
{
public:

	//plot spot diagrams
	SpotPlotDiagramQwt(OpticalSystem_LLT OptSys, PlotParameterQwt SpotPlotParameter, double NumberOfLines, double AiryDiskRadius, QWidget* = NULL);
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
	PlotParameterQwt mSpotPlotParameter;
};

class PlotRayFanQwt : public QwtPlot
{
public:
	//Plot the optical path difference 
	PlotRayFanQwt(SystemPlots Plots, PlotRayFan RayFanPlot, PlotParameterQwt Parameter);
	//return the length of the field under the spot diagram depending on the number pf th fields
	double getLengthTextFieldRayFan();
	//return the height of the field under the spot diagram depending on the number of the fileds
	double getHeightRayFanPlot();
	//get a vector with the coordinates as (x,y) of the spot frames depending on the given number of Spot Diagrams((x1,y1),(x2,y2),..)
	std::vector <VectorStructR2> coordinatesOfFramesRayFan(int numberOffields);

private:
	SystemPlots mSystemPlots;
	PlotRayFan mRayFanPlot;
	PlotParameterQwt mParameter;
	std::vector <VectorStructR2> mAllCoordinates;
};