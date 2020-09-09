#include "TestRayTracingQwtPlot.h"

#include "BenchmarkOpticalSystemAllSurfaces.h"
//Qwt
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "..\..\Plot\PlotQwt.h"
#include <qwt_plot_zoomer.h>
// surfaces
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\AsphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ParaxialLens_LLT.h"


// interactions
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DeflectedRayParaxialLens_LLT.h"

// optical system
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\..\FillAptertureStop\FillApertureStop.h"

// analyse 
#include "..\..\Analyse\Spot.h"
#include "..\..\Analyse\OpticalPathDifference.h"

// plot
#include "..\..\Plot\PlotParameterQwt.h"
#include "..\..\Plot\OpticalSystemPlots.h"


bool OpticalSystemAllSurfaces::testQwtPlotsSytem()
{


	ApertureStop_LLT ApertureStop0(3.0, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT SphericalSurface1(/*radius*/80.0, /*semiHeight*/20.0, /*Apex of the sphere*/{ 0.0,0.0,25.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.51852239);
	SphericalSurface_LLT SphericalSurface2(/*radius*/530.0, /*semiHeight*/20.0, /*Apex of the sphere*/{ 0.0,0.0,45.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.51852239, /*refIndexSideB*/1.73366143);
	SphericalSurface_LLT SphericalSurface3(/*radius*/65.0, /*semiHeight*/20.0, /*Apex of the sphere*/{ 0.0,0.0,55.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.73366143);
	ParaxialLens_LLT ParaxialLens1(/*semi Height*/ 20.0, /*apex*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*focallength*/ 50.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflectCR3(ParaxialLens1.getInfosForDefelction());
	SphericalSurface_LLT SphericalSurface4(/*radius*/50.0, /*semiHeight*/20.0, /*Apex of the sphere*/{ 0.0,0.0,95.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.73366143, /*refIndexSideB*/1.0);
	SphericalSurface_LLT SphericalSurface5(/*radius*/100.0, /*semiHeight*/20.0, /*Apex of the sphere*/{ 0.0,0.0,105.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.73366143, /*refIndexSideB*/1.51852239);
	SphericalSurface_LLT SphericalSurface6(/*radius*/50.0, /*semiHeight*/20.0, /*Apex of the sphere*/{ 0.0,0.0,115.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.51852239, /*refIndexSideB*/1.0);
	AsphericalSurface_LLT AsphericalSurface1(/*radius*/ 40.0, /*semi height*/ 20,/*point*/{ 0.0,0.0,125.0 }, /*direction*/{ 0.0,0.0,1.0 },/*refractive index A*/ 1.0,/*refractive index B*/ 1.51852239,/*conic*/ -1.0,
		/*second order term*/ 0.01, /*fourth order term*/ 1.0E-5, /*sixth order term*/ 0, /*eighth order term*/ 0,/*tenth order term*/ 0,/*twelfth oder term*/ 0, /*fourteenth order term*/0,/*sixteenth order tem*/ 0);
	AsphericalSurface_LLT AsphericalSurface2(/*radius*/ 80.0, /*semi height*/ 20,/*point*/{ 0.0,0.0,145.0 }, /*direction*/{ 0.0,0.0,-1.0 },/*refractive index A*/ 1.73366143,/*refractive index B*/ 1.51852239,/*conic*/ -1.0,
		/*second order term*/ -0.01, /*fourth order term*/ 1.0E-5, /*sixth order term*/ 0, /*eighth order term*/ 0,/*tenth order term*/ 0,/*twelfth oder term*/ 0, /*fourteenth order term*/0,/*sixteenth order tem*/ 0);
	SphericalSurface_LLT SphericalSurface7(/*radius*/200.0, /*semiHeight*/20.0, /*Apex of the sphere*/{ 0.0,0.0,155.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.73366143);
	SphericalSurface_LLT SphericalSurface8(/*radius*/200.0, /*semiHeight*/20.0, /*Apex of the sphere*/{ 0.0,0.0,165.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.51852239, /*refIndexSideB*/1.0);
	SphericalSurface_LLT SphericalSurface9(/*radius*/200.0, /*semiHeight*/20.0, /*Apex of the sphere*/{ 0.0,0.0,175.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.51852239, /*refIndexSideB*/1.0);
	SphericalSurface_LLT SphericalSurface10(/*radius*/60.0, /*semiHeight*/20.0, /*Apex of the sphere*/{ 0.0,0.0,185.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.73366143);
	SphericalSurface_LLT SphericalSurface11(/*radius*/60.0, /*semiHeight*/20.0, /*Apex of the sphere*/{ 0.0,0.0,195.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.73366143);
	PlanGeometry_LLT PlanGeometry1(/*semiHeight*/20.0, /*point*/{ 0.0,0.0,215.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);


	// build the optical system
	RefractedRay_LLT refrac;

	OpticalSystem_LLT optSys;

	optSys.fillVectorSurfaceAndInteractingData(0, ApertureStop0.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(1, SphericalSurface1.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(2, SphericalSurface2.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(3, SphericalSurface3.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(4, ParaxialLens1.clone(), deflectCR3.clone());
	optSys.fillVectorSurfaceAndInteractingData(5, SphericalSurface4.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(6, SphericalSurface5.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(7, SphericalSurface6.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(8, AsphericalSurface1.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(9, AsphericalSurface2.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(10, SphericalSurface7.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(11, SphericalSurface8.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(12, SphericalSurface9.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(13, SphericalSurface10.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(14, SphericalSurface11.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(15, PlanGeometry1.clone(), refrac.clone());

	//// plot 2d
	OpticalSystemCurves OpticalSystemPlots;
	OpticalSystemPlots.fillVectorRayTracSurfaces(ApertureStop0.getPointerPlotDown());
	OpticalSystemPlots.fillVectorRayTracSurfaces(ApertureStop0.getPointerPlotUp());
	OpticalSystemPlots.fillVectorRayTracSurfaces(SphericalSurface1.getPointerPlot());
	OpticalSystemPlots.fillVectorRayTracSurfaces(SphericalSurface2.getPointerPlot());
	OpticalSystemPlots.fillVectorRayTracSurfaces(SphericalSurface3.getPointerPlot());
	OpticalSystemPlots.fillVectorRayTracSurfaces(ParaxialLens1.getPointerPlot());
	OpticalSystemPlots.fillVectorRayTracSurfaces(SphericalSurface4.getPointerPlot());
	OpticalSystemPlots.fillVectorRayTracSurfaces(SphericalSurface5.getPointerPlot());
	OpticalSystemPlots.fillVectorRayTracSurfaces(SphericalSurface6.getPointerPlot());
	OpticalSystemPlots.fillVectorRayTracSurfaces(AsphericalSurface1.getPointerPlot());
	OpticalSystemPlots.fillVectorRayTracSurfaces(AsphericalSurface2.getPointerPlot());
	OpticalSystemPlots.fillVectorRayTracSurfaces(SphericalSurface7.getPointerPlot());
	OpticalSystemPlots.fillVectorRayTracSurfaces(SphericalSurface8.getPointerPlot());
	OpticalSystemPlots.fillVectorRayTracSurfaces(SphericalSurface9.getPointerPlot());
	OpticalSystemPlots.fillVectorRayTracSurfaces(SphericalSurface10.getPointerPlot());
	OpticalSystemPlots.fillVectorRayTracSurfaces(SphericalSurface11.getPointerPlot());
	OpticalSystemPlots.fillVectorRayTracSurfaces(PlanGeometry1.getPointerPlot());


	// single ray tracing
	SequentialRayTracing SeqTrace_plot2D(optSys);
	std::vector<LightRayStruct> lightRayAlong_Y = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 7, 20.0, -3.0, 3.0, 550, 1.0);
	SeqTrace_plot2D.seqRayTracingWithVectorOfLightRays(lightRayAlong_Y);

	//// single ray tracing
	SequentialRayTracing SeqTrace_plot2D_field(optSys);
	std::vector<LightRayStruct> lightRayAlong_field = SequentialRayTracing::lightRayAlongY({ 0.0, 1.0, 0.0 }, 7, 20.0, -3.0, 3.0, 550, 1.0);
	SeqTrace_plot2D_field.seqRayTracingWithVectorOfLightRays(lightRayAlong_field);

	//// single ray tracing
	SequentialRayTracing SeqTrace_plot2D_field2(optSys);
	std::vector<LightRayStruct> lightRayAlong_field2 = SequentialRayTracing::lightRayAlongY({ 0.0, 2.0, 0.0 }, 7, 20.0, -3.0, 3.0, 550, 1.0);
	SeqTrace_plot2D_field2.seqRayTracingWithVectorOfLightRays(lightRayAlong_field2);

	//fill vector Ray Tracing
	OpticalSystemPlots.fillVectorSequentialRayTracing(&SeqTrace_plot2D, { 0,0,180 });
	OpticalSystemPlots.fillVectorSequentialRayTracing(&SeqTrace_plot2D_field, { 0,150,0 });
	OpticalSystemPlots.fillVectorSequentialRayTracing(&SeqTrace_plot2D_field2, { 250,0,0 });

	//// show surfaces with rays
	PlotParameterQwt ParameterPlotOptSys;
	mRayTracingQwtPlotSystem = new RayTracingQwtPlot(OpticalSystemPlots, optSys, ParameterPlotOptSys);
	//SaveQwtPlotbetterResolution(mRayTracingQwtPlotSystem, "RayTracPlotOptikKreis.jpg");
	mRayTracingQwtPlotSystem->show();

	//550
	Light_LLT light;
	light.setWavelength(550.0);

	// fill aperture stop
	FillApertureStop fillAperStop_optAchse({ 0.0,0.0,0.0 }, 3, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, light);
	SequentialRayTracing seqTrace_OptAchse(optSys);
	seqTrace_OptAchse.seqRayTracingWithVectorOfLightRays(fillAperStop_optAchse.getVectorWithLightRays());

	FillApertureStop fillAperStop_field({ 0.0,1.0,0.0 }, 3, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, light);
	SequentialRayTracing seqTrace_field(optSys);
	seqTrace_field.seqRayTracingWithVectorOfLightRays(fillAperStop_field.getVectorWithLightRays());

	FillApertureStop fillAperStop_field2({ 0.0,2.0,0.0 }, 3, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, light);
	SequentialRayTracing seqTrace_field2(optSys);
	seqTrace_field2.seqRayTracingWithVectorOfLightRays(fillAperStop_field2.getVectorWithLightRays());

	//define the Spot Diagramms
	Spot spot_optAchese(seqTrace_OptAchse.getAllInterPointsAtSurface_i_filtered(15), seqTrace_OptAchse.getAllInterPointsAtSurface_i_filtered(15).at(0));
	std::vector<Spot> vecSpot_optAchese{ spot_optAchese };
	PlotSpotDiagramm PlotSpot_optAchse(spot_optAchese.getRefPoint(), vecSpot_optAchese, 0.09950372, 550);

	Spot spot_field(seqTrace_field.getAllInterPointsAtSurface_i_filtered(15), seqTrace_field.getAllInterPointsAtSurface_i_filtered(15).at(0));
	std::vector<Spot> vecSpot_field{ spot_field };
	PlotSpotDiagramm PlotSpot_field(spot_field.getRefPoint(), vecSpot_field, 0.09950372, 550);


	Spot spot_field2(seqTrace_field2.getAllInterPointsAtSurface_i_filtered(15), seqTrace_field2.getAllInterPointsAtSurface_i_filtered(15).at(0));
	std::vector<Spot> vecSpot_field2{ spot_field2 };
	PlotSpotDiagramm PlotSpot_field2(spot_field2.getRefPoint(), vecSpot_field2, 0.09950372, 550);


	//fill vectorSpotDiagram
	OpticalSystemPlots.giveNumberWavelengthsSpotDiagram(1);
	OpticalSystemPlots.fillVectorSpotDiagramm(&PlotSpot_optAchse, 1);
	OpticalSystemPlots.fillVectorSpotDiagramm(&PlotSpot_field, 1);
	OpticalSystemPlots.fillVectorSpotDiagramm(&PlotSpot_field2, 1);



	PlotParameterQwt ParameterSpot;
	mSpotDiagramQwtPlotSystem = new SpotPlotDiagramQwt(OpticalSystemPlots, ParameterSpot, 10, 0);
	//SaveQwtPlotbetterResolution(mSpotDiagramQwtPlotSystem, "SpotDiagramPlotOptikKreis.jpg");
	mSpotDiagramQwtPlotSystem->show();

	return mRayTracingQwtPlotSystem->isVisible();
}