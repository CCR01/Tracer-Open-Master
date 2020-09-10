#pragma once
#include <vector>
#include "..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\SequentialRayTracing\SequentialRayTracer.h" 
#include "..\..\Plot\PlotOPD.h"
#include "..\Plot\QwtPloItems.h"
#include "..\Plot\PlotParameterQwt.h"
#include "..\Plot\PlotRayFan.h"

#include <qwt_plot_curve.h>

struct SequentialRayTracingandColorStruct
{
	SequentialRayTracingandColorStruct() {};
	~SequentialRayTracingandColorStruct() {};
	SequentialRayTracingandColorStruct(SequentialRayTracing* SeqRayTrac, QColor color) {
		mSeqRayTrac = SeqRayTrac;
		mColor = color;
	};
	SequentialRayTracing* mSeqRayTrac;
	QColor mColor;

	// set Color
	void setColor(QColor const& color);
	// get Color
	QColor getColor() const&;

	// set SequentialRayTracing
	void setSequentialRayTracing(SequentialRayTracing* SeqRayTrac);
	// get SequentialRayTracing
	SequentialRayTracing* getSequentialRayTracing() const&;

};


class OpticalSystemCurves
{
public:
	OpticalSystemCurves() {};
	~OpticalSystemCurves() {};
	//Raytracer
	//fill the vector with the raytracing 
	void fillVectorRayTracSurfaces(QwtPlotCurve* SurfaceCurvePtr);
	//get vector raytracing
	std::vector<QwtPlotCurve*> getVectorRayTracSurfaces();
	//fill vector with Rays to plot
	void fillVectorSequentialRayTracing(SequentialRayTracing* SeqRayTrac, QColor color);
	//get vector with Rays to plot
	std::vector<SequentialRayTracingandColorStruct> getVectorSeqRayTracingAndColor();


	//Spotdiagram
	//fill the vector with spot diagrams
	void fillVectorSpotDiagramm(PlotSpotDiagramm* PlotSpot, int WavelengthNumber);
	//get vector spot diagram
	std::vector< std::vector< PlotSpotDiagramm*>> getVectorSpotDiagramm();
	//get min scale spotdiagram
	double getMaxSpotDiagrammScale();
	//give number of Wavelengths SpotDiagram
	void giveNumberWavelengthsSpotDiagram(int numberOfWavelengths);

	//RayFan
	// fill the vector with rayFan
	void fillVectorRayFanDiagramToPlot(PlotRayFan* plotRayFan, int numberOfWavelengths);
	//get vector ray fan diagrams
	std::vector< std::vector<PlotRayFan*>> getVectorRayFanDiagram();
	//get min Scale Ray Fan
	double getMaxRayFanScale();
	//give number of Wavelengths SpotDiagram
	void giveNumberWavelengthsRayFan(int numberOfWavelengths);


	//OPD
	// fill the vector with OPD plots
	void fillVectorplotOPDDiagramToPlot(PlotOPD* plotOPD, int numberOfWavelengths);
	//get vector OPD diagrams
	std::vector < std::vector<PlotOPD*>> getVectorOPDDiagram();
	//get min Scale OPD
	double getMaxOPDPlotScale();
	//give number of Wavelengths OPD
	void giveNumberWavelengthsOPD(int numberOfWavelengths);


private:
	std::vector< std::vector<PlotRayFan*>> mVectorRayPlotDiagramm;
	std::vector< std::vector<PlotOPD*>> mVectorOPDPlotDiagramm;
	std::vector<QwtPlotCurve*> mVectorRayTracSurfaces;
	std::vector<SequentialRayTracingandColorStruct> mVectorSeqRayTracPtrAndColor;
	std::vector< std::vector< PlotSpotDiagramm*>> mVectorPlotSpotDiagramm;
};