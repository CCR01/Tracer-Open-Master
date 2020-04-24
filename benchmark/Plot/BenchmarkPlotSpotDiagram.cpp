#pragma once

#include "BenchPlotSpotDiagram.h"
#include "..\..\Plot\PlotSpotDiagram.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\..\FillAptertureStop\FillApertureStop.h"
#include "..\..\Analyse\Spot.h"
#include "..\..\Plot\Plot.h"

#include "..\..\Glasses\Glasses.h"

bool BenchmarkPlotSpotDiagram::checkMethodesPlotSpotDiagram()
{

	
	
	std::vector<bool> checkPlotSpotDia;

	RefractedRay_LLT refrac;
	Light_LLT Light;
	real wavelength = 550.0;
	Light.setWavelength(wavelength);

	FillApertureStop FillEnt0({ 0.0,0.0,0.0 }, 1.0, { 0.0,0.0,15.0 }, {0.0, 0.0, 1.0},6,8,1.0, Light);
	FillApertureStop FillEnt2({ 0.0,2.0,0.0 }, 1.0, { 0.0,0.0,15.0 }, { 0.0, 0.0, 1.0 }, 6, 8, 1.0, Light);

	//calculate the refractive index
	


	//real refRacBK7_Sell1 = BK7_S1.calcRefractiveIndexSnellmeier1(wavelength);
	
	SphericalSurface_LLT S0(/*radius*/9.0, /*semiHeight*/7.0, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S1(/*radius*/9.0, /*semiHeight*/7.0, /*Apex of the sphere*/{ 0.0, 0.0, 27.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT Plan0(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,42.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	// build opitcal system
	OpticalSystem_LLT OptSys1;
	OptSys1.fillVectorSurfaceAndInteractingData(0, &S0, refrac.clone());
	OptSys1.fillVectorSurfaceAndInteractingData(1, &S1, refrac.clone());
	OptSys1.fillVectorSurfaceAndInteractingData(2, &Plan0, refrac.clone());

	// do sequential raytracing
	SequentialRayTracing SeqTrac0(OptSys1);
	SeqTrac0.seqRayTracingWithVectorOfLightRays(FillEnt0.getVectorWithLightRays());

	SequentialRayTracing SeqTrac2(OptSys1);
	SeqTrac2.seqRayTracingWithVectorOfLightRays(FillEnt2.getVectorWithLightRays());

	std::vector<VectorStructR3> interPoints0 = SeqTrac0.getAllInterPointsAtSurf_i_notFiltered(2);
	std::vector<VectorStructR3> interPoints2 = SeqTrac2.getAllInterPointsAtSurf_i_notFiltered(2);

	Spot SpotDiag0(interPoints0, interPoints0.at(0));
	real RMS0 = SpotDiag0.getRMS_mm() * 1000;
	real GeoR0 = SpotDiag0.getGeoRadius() * 1000;

	Spot SpotDiag2(interPoints2, interPoints2.at(0));
	real RMS2 = SpotDiag2.getRMS_mm() * 1000;
	real GeoR2 = SpotDiag2.getGeoRadius() * 1000;


	std::vector<Spot> vecSpotDia0{ SpotDiag0 };
	PlotSpotDiagramm PlotSpotD0(SpotDiag0.getRefPoint(),vecSpotDia0, 0.5, 550);
	PlotCarsten::plotDiagram(PlotSpotD0.getMatrixToPlotSpot(),"Spot Diagram 1");
	PlotCarsten::saveImage(PlotSpotD0.getMatrixToPlotSpot(), "../benchmark/Plot/images/image1.jpg");

	std::vector<Spot> vecSpotDia2{ SpotDiag2 };
	PlotSpotDiagramm PlotSpotD2(SpotDiag2.getRefPoint(), vecSpotDia2, 0.5, 550);
	PlotCarsten::plotDiagram(PlotSpotD2.getMatrixToPlotSpot(), "Spot Diagram 1");
	PlotCarsten::saveImage(PlotSpotD2.getMatrixToPlotSpot(), "../benchmark/Plot/images/image2.jpg");

	return true;

}