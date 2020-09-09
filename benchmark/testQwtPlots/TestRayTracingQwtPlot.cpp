#include "TestRayTracingQwtPlot.h"

//Qwt
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "..\..\Plot\PlotQwt.h"

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


testRayTracingQwtPlot::testRayTracingQwtPlot() {};
testRayTracingQwtPlot::~testRayTracingQwtPlot() {};

bool testRayTracingQwtPlot::superFuncTestRayTracingQwtPlot()
{
	std::vector<bool> checkQwtPlot;

	bool testE0 = testRayTracingQwtPlotE0();
	checkQwtPlot.push_back(testE0);
	bool testE1 = testRayTracingQwtPlotE1();
	checkQwtPlot.push_back(testE1);
	bool testE2 = testRayTracingQwtPlotE2();
	checkQwtPlot.push_back(testE2);


	bool returnCheck = Math::checkTrueOfVectorElements(checkQwtPlot);

	return returnCheck;

}

bool testRayTracingQwtPlot::testRayTracingQwtPlotE0()
{
	// interactions
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	Light_LLT light;
	light.setWavelength(550.0);

	// surfaces
	ApertureStop_LLT S0E0(/*semiHeight*/ 0.5, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveIndex*/ 1.0);
	AsphericalSurface_LLT S1E0(/*radius*/ 30.0, /*semi height*/ 6.0,/*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 },/*refractive index A*/ 1.0,/*refractive index B*/ 1.5,/*conic*/ -1.0,
		/*second order term*/ 2.0E-3, /*fourth order term*/ 2.0E-3, /*sixth order term*/ 2.0E-5, /*eighth order term*/ 1.0E-7,/*tenth order term*/ 1.0E-11,/*twelfth oder term*/ 1.0E-11,
		/*fourteenth order term*/1.0E-11,/*sixteenth order tem*/ 1.0E-15);
	AsphericalSurface_LLT S2E0(/*radius*/ 60.0, /*semi height*/ 6.0,/*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,-1.0 },/*refractive index A*/ 1.0,/*refractive index B*/ 1.5,/*conic*/ 1.0,
		/*second order term*/ -2.0E-3, /*fourth order term*/ 2.0E-3, /*sixth order term*/ -2.0E-5, /*eighth order term*/ -1.0E-7,/*tenth order term*/ 1.0E-11,/*twelfth oder term*/ -1.0E-11,
		/*fourteenth order term*/-1.0E-15,/*sixteenth order tem*/ -1.0E-15);
	ParaxialLens_LLT S3E0(/*semi Height*/ 5.0, /*apex*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*focallength*/ 6.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	DeflectedRayParaxialLens_LLT deflectCR3(S3E0.getInfosForDefelction());
	AsphericalSurface_LLT S4E0(/*radius*/ 100.0, /*semi height*/ 5.0,/*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 },/*refractive index A*/ 1.6,/*refractive index B*/ 1.0,/*conic*/ -2.0,
		/*second order term*/ -1.0E-4, /*fourth order term*/ -1.0E-4, /*sixth order term*/ -1.0E-4, /*eighth order term*/ -1.0E-10,/*tenth order term*/ -1.0E-10,/*twelfth oder term*/ -1.0E-10,
		/*fourteenth order term*/1.0E-10,/*sixteenth order tem*/ 1.0E-15);
	AsphericalSurface_LLT S5E0(/*radius*/ 50.0, /*semi height*/ 5.0,/*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 },/*refractive index A*/ 1.6,/*refractive index B*/ 1.0,/*conic*/ 2.0,
		/*second order term*/ 1.0E-4, /*fourth order term*/ 1.0E-4, /*sixth order term*/ 1.0E-4, /*eighth order term*/ 1.0E-10,/*tenth order term*/ 1.0E-10,/*twelfth oder term*/ 1.0E-10,
		/*fourteenth order term*/1.0E-10,/*sixteenth order tem*/ 1.0E-15);
	SphericalSurface_LLT S6E0(/*radius*/ 20.0,/*semi height*/ 6.0,/*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 },/*refractive index A*/ 1.0,/*refractive index B*/ 1.3);
	SphericalSurface_LLT S7E0(/*radius*/ 20.0,/*semi height*/ 6.0,/*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 },/*refractive index A*/ 1.0,/*refractive index B*/ 1.3);
	PlanGeometry_LLT S8E0(/*semi Height*/5.0, /*apex*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, 1.0, 1.0);

	// build optical system
	OpticalSystem_LLT optSysE0;
	optSysE0.fillVectorSurfaceAndInteractingData(0, S0E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(1, S1E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(2, S2E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(3, S3E0.clone(), deflectCR3.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(4, S4E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(5, S5E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(6, S6E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(7, S7E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(8, S8E0.clone(), absorb.clone());

	// ray tracing optica axis
	SequentialRayTracing seqTrace_E0_optA(optSysE0);
	FillApertureStop fillAperStop_optA(/*start point rays*/{ 0.0,0.0,0.0 },/*semi height of aperture stop*/ 0.5,/*point of aperture stop*/{ 0.0,0.0,5.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/6,/*arms*/ 8,/*refractive index*/ 1.0, light);
	seqTrace_E0_optA.seqRayTracingWithVectorOfLightRays(fillAperStop_optA.getVectorWithLightRays());


	// ray tracing field 1
	SequentialRayTracing seqTrace_E0_field1(optSysE0);
	FillApertureStop fillAperStop_field1(/*start point rays*/{ 0.0,1.0,0.0 },/*semi height of aperture stop*/ 0.5,/*point of aperture stop*/{ 0.0,0.0,5.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/6,/*arms*/ 8,/*refractive index*/ 1.0, light);
	seqTrace_E0_field1.seqRayTracingWithVectorOfLightRays(fillAperStop_field1.getVectorWithLightRays());


	//to draw the aperturre stop two curves must be added to the table of surfaces to be ploted the upper part through getPointerPlotUp() and the other through getPointerPlotDown()
	//can be ploted using one curve when finding a method to plot a curve with gaps

	OpticalSystemCurves OpticalSystemPlotsE0;
	OpticalSystemPlotsE0.fillVectorRayTracSurfaces(S0E0.getPointerPlotUp());
	OpticalSystemPlotsE0.fillVectorRayTracSurfaces(S0E0.getPointerPlotDown());
	OpticalSystemPlotsE0.fillVectorRayTracSurfaces(S1E0.getPointerPlot());
	OpticalSystemPlotsE0.fillVectorRayTracSurfaces(S2E0.getPointerPlot());
	OpticalSystemPlotsE0.fillVectorRayTracSurfaces(S3E0.getPointerPlot());
	OpticalSystemPlotsE0.fillVectorRayTracSurfaces(S4E0.getPointerPlot());
	OpticalSystemPlotsE0.fillVectorRayTracSurfaces(S5E0.getPointerPlot());
	OpticalSystemPlotsE0.fillVectorRayTracSurfaces(S6E0.getPointerPlot());
	OpticalSystemPlotsE0.fillVectorRayTracSurfaces(S7E0.getPointerPlot());
	OpticalSystemPlotsE0.fillVectorRayTracSurfaces(S8E0.getPointerPlot());

	//fill vector Ray Tracing

	OpticalSystemPlotsE0.fillVectorSequentialRayTracing(&seqTrace_E0_optA, { 200,50,0 });
	OpticalSystemPlotsE0.fillVectorSequentialRayTracing(&seqTrace_E0_field1, { 0,0,200 });

	//change Plot Parameter 
	PlotParameterQwt ParameterPlotOptSysE0;

	//// show surfaces with rays
	mRayTracingQwtPlotSystem0 = new RayTracingQwtPlot(OpticalSystemPlotsE0, optSysE0, ParameterPlotOptSysE0);
	mRayTracingQwtPlotSystem0->show();
	//SaveQwtPlotbetterResolution(mRayTracingQwtPlotSystem3, "RayTracE3");
	return mRayTracingQwtPlotSystem0->isVisible();
}


bool testRayTracingQwtPlot::testRayTracingQwtPlotE1()
{

	//define all the surfaces of the system
	SphericalSurface_LLT S1E1(/*radius*/38.73360379131933, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, -0.6, 15.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S2E1(/*radius*/10.33817058758478, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.2, 20.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.1, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S3E1(/*radius*/51.02696739895755, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 22.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S4E1(/*semiHeight*/5.0, /*point*/{ 0.0,0.5,27.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	SphericalSurface_LLT S5E1(/*radius*/61.48513190056155, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 29.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S6E1(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,34.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	SphericalSurface_LLT S7E1(/*radius*/13.22318498941039, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 36.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S8E1(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,41.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.1);
	SphericalSurface_LLT S9E1(/*radius*/12.07896133399859, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 43.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.1);
	SphericalSurface_LLT S10E1(/*radius*/26.46510860484050, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 48.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.4, /*refIndexSideB*/1.6);
	SphericalSurface_LLT S11E1(/*radius*/21.48098096423011, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 53.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	SphericalSurface_LLT S12E1(/*radius*/30.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 55.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S13E1(/*radius*/70.0, /*semiHeight*/6.0, /*Apex of the sphere*/{ 0.0, 0.0, 60.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.6, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S14E1(/*radius*/40.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 65.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.6, /*refIndexSideB*/1.0);
	PlanGeometry_LLT S15E1(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,74.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);




	// build the optical system by giving the position of each surface, its referance and its interaction
	RefractedRay_LLT refrac;
	OpticalSystem_LLT optSysE1;
	optSysE1.fillVectorSurfaceAndInteractingData(0, S1E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(1, S2E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(2, S3E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(3, S4E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(4, S5E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(5, S6E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(6, S7E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(7, S8E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(8, S9E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(9, S10E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(10, S11E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(11, S12E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(12, S13E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(13, S14E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(14, S15E1.clone(), refrac.clone());

	Light_LLT light;
	light.setWavelength(550.0);

	//// plot 2d
	OpticalSystemCurves OpticalSystemPlotsE1;
	OpticalSystemPlotsE1.fillVectorRayTracSurfaces(S1E1.getPointerPlot());
	OpticalSystemPlotsE1.fillVectorRayTracSurfaces(S2E1.getPointerPlot());
	OpticalSystemPlotsE1.fillVectorRayTracSurfaces(S3E1.getPointerPlot());
	OpticalSystemPlotsE1.fillVectorRayTracSurfaces(S4E1.getPointerPlot());
	OpticalSystemPlotsE1.fillVectorRayTracSurfaces(S5E1.getPointerPlot());
	OpticalSystemPlotsE1.fillVectorRayTracSurfaces(S6E1.getPointerPlot());
	OpticalSystemPlotsE1.fillVectorRayTracSurfaces(S7E1.getPointerPlot());
	OpticalSystemPlotsE1.fillVectorRayTracSurfaces(S8E1.getPointerPlot());
	OpticalSystemPlotsE1.fillVectorRayTracSurfaces(S9E1.getPointerPlot());
	OpticalSystemPlotsE1.fillVectorRayTracSurfaces(S10E1.getPointerPlot());
	OpticalSystemPlotsE1.fillVectorRayTracSurfaces(S11E1.getPointerPlot());
	OpticalSystemPlotsE1.fillVectorRayTracSurfaces(S12E1.getPointerPlot());
	OpticalSystemPlotsE1.fillVectorRayTracSurfaces(S13E1.getPointerPlot());
	OpticalSystemPlotsE1.fillVectorRayTracSurfaces(S14E1.getPointerPlot());
	OpticalSystemPlotsE1.fillVectorRayTracSurfaces(S15E1.getPointerPlot());


	// single ray tracing
	SequentialRayTracing SeqTraceE1_plot2D(optSysE1);
	std::vector<LightRayStruct> lightRayAlong_Y_E1 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 3, 10.0, -2.0, 2.0, 550, 1.0);
	SeqTraceE1_plot2D.seqRayTracingWithVectorOfLightRays(lightRayAlong_Y_E1);

	//// single ray tracing
	SequentialRayTracing SeqTraceE1_plot2D_field(optSysE1);
	std::vector<LightRayStruct> lightRayAlong_E1_field = SequentialRayTracing::lightRayAlongY({ 0.0, 0.4, 0.0 }, 3, 10.0, -2.0, 2.0, 550, 1.0);
	SeqTraceE1_plot2D_field.seqRayTracingWithVectorOfLightRays(lightRayAlong_E1_field);


	//// single ray tracing
	SequentialRayTracing SeqTraceE1_plot2D_field2(optSysE1);
	std::vector<LightRayStruct> lightRayAlong_E1_field2 = SequentialRayTracing::lightRayAlongY({ 0.0, -0.4, 0.0 }, 3, 10.0, -2.0, 2.0, 550, 1.0);
	SeqTraceE1_plot2D_field2.seqRayTracingWithVectorOfLightRays(lightRayAlong_E1_field2);

	//// single ray tracing
	SequentialRayTracing SeqTraceE1_plot2D_field3(optSysE1);
	std::vector<LightRayStruct> lightRayAlong_E1_field3 = SequentialRayTracing::lightRayAlongY({ 0.0, -0.3, 0.0 }, 3, 10.0, -2.0, 2.0, 550, 1.0);
	SeqTraceE1_plot2D_field3.seqRayTracingWithVectorOfLightRays(lightRayAlong_E1_field3);


	//// single ray tracing
	SequentialRayTracing SeqTraceE1_plot2D_field4(optSysE1);
	std::vector<LightRayStruct> lightRayAlong_E1_field4 = SequentialRayTracing::lightRayAlongY({ 0.0, -0.2, 0.0 }, 3, 10.0, -2.0, 2.0, 550, 1.0);
	SeqTraceE1_plot2D_field4.seqRayTracingWithVectorOfLightRays(lightRayAlong_E1_field4);

	//// single ray tracing
	SequentialRayTracing SeqTraceE1_plot2D_field5(optSysE1);
	std::vector<LightRayStruct> lightRayAlong_E1_field5 = SequentialRayTracing::lightRayAlongY({ 0.0, -0.1, 0.0 }, 3, 10.0, -2.0, 2.0, 550, 1.0);
	SeqTraceE1_plot2D_field5.seqRayTracingWithVectorOfLightRays(lightRayAlong_E1_field5);

	//// single ray tracing
	SequentialRayTracing SeqTraceE1_plot2D_field6(optSysE1);
	std::vector<LightRayStruct> lightRayAlong_E1_field6 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.1, 0.0 }, 3, 10.0, -2.0, 2.0, 550, 1.0);
	SeqTraceE1_plot2D_field6.seqRayTracingWithVectorOfLightRays(lightRayAlong_E1_field6);


	//// single ray tracing
	SequentialRayTracing SeqTraceE1_plot2D_field7(optSysE1);
	std::vector<LightRayStruct> lightRayAlong_E1_field7 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.2, 0.0 }, 3, 10.0, -2.0, 2.0, 550, 1.0);
	SeqTraceE1_plot2D_field7.seqRayTracingWithVectorOfLightRays(lightRayAlong_E1_field7);



	//fill vector Ray Tracing

	OpticalSystemPlotsE1.fillVectorSequentialRayTracing(&SeqTraceE1_plot2D, { 0,100,0 });
	OpticalSystemPlotsE1.fillVectorSequentialRayTracing(&SeqTraceE1_plot2D_field, { 0,0,255 });
	OpticalSystemPlotsE1.fillVectorSequentialRayTracing(&SeqTraceE1_plot2D_field2, { 150,0,0 });



	//initiate the plot parameter
	PlotParameterQwt ParameterPlotOptSysE1;
	//// show surfaces with rays
	mRayTracingQwtPlotSystem1 = new RayTracingQwtPlot(OpticalSystemPlotsE1, optSysE1, ParameterPlotOptSysE1);
	mRayTracingQwtPlotSystem1->show();
	//SaveQwtPlotbetterResolution(mRayTracingQwtPlotSystem1, "RayTracE4");
	return mRayTracingQwtPlotSystem1->isVisible();
}

bool testRayTracingQwtPlot::testRayTracingQwtPlotE2()
{

	typedef std::shared_ptr<SurfaceIntersectionRay_LLT> surfaceLLT_ptr;
	typedef std::shared_ptr<InteractionRay_LLT> interactionLLT_ptr;

	SphericalSurface_LLT S1E2(/*radius*/28.73360379131933, /*semiHeight*/8.0, /*Apex of the sphere*/{ 0.0, 0.0, 15.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S2E2(/*radius*/50.33817058758478, /*semiHeight*/8.0, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S3E2(/*radius*/51.02696739895755, /*semiHeight*/8.0, /*Apex of the sphere*/{ 0.0, 0.0, 22.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	PlanGeometry_LLT S4E2(/*semiHeight*/8.0, /*point*/{ 0.0,0.5,27.0 }, /*direction*/{ 0.0,-0.1,1.0 }, /*refractiveSideA*/ 1.6, /*refractiveSideB*/ 1.0);
	SphericalSurface_LLT S5E2(/*radius*/61.48513190056155, /*semiHeight*/8.0, /*Apex of the sphere*/{ 0.0, -0.2, 29.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S6E2(/*semiHeight*/8.0, /*point*/{ 0.0,0.0,34.0 }, /*direction*/{ 0.0,-0.1,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	SphericalSurface_LLT S7E2(/*radius*/10.22318498941039, /*semiHeight*/8.0, /*Apex of the sphere*/{ 0.0, 0.0, 36.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S8E2(/*semiHeight*/8.0, /*point*/{ 0.0,0.0,41.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.1);
	SphericalSurface_LLT S9E2(/*radius*/10.07896133399859, /*semiHeight*/8.0, /*Apex of the sphere*/{ 0.0, 0.0, 43.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.1, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S10E2(/*semiHeight*/8.0, /*point*/{ 0.0,0.0,62.1 }, /*direction*/{ 0.0,0.1,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);


	// build the optical system
	RefractedRay_LLT refrac;

	// vector with surfaces
	std::vector<surfaceLLT_ptr> surfaces_vec{ S1E2.clone(),S2E2.clone(),S3E2.clone(),S4E2.clone(),S5E2.clone(),S6E2.clone(),S7E2.clone(),S8E2.clone(),S9E2.clone(),S10E2.clone() };
	// vector with interactions
	std::vector<interactionLLT_ptr> interaction_vec{ refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone() };

	OpticalSystem_LLT optSysE2(surfaces_vec, interaction_vec);



	//// plot 2d
	OpticalSystemCurves OpticalSystemPlotsE2;
	//write a function that takes optsys as an argument and fill the vector raytracsurfaces with pointers
	OpticalSystemPlotsE2.fillVectorRayTracSurfaces(S1E2.getPointerPlot());
	OpticalSystemPlotsE2.fillVectorRayTracSurfaces(S2E2.getPointerPlot());
	OpticalSystemPlotsE2.fillVectorRayTracSurfaces(S3E2.getPointerPlot());
	OpticalSystemPlotsE2.fillVectorRayTracSurfaces(S4E2.getPointerPlot());
	OpticalSystemPlotsE2.fillVectorRayTracSurfaces(S5E2.getPointerPlot());
	OpticalSystemPlotsE2.fillVectorRayTracSurfaces(S6E2.getPointerPlot());
	OpticalSystemPlotsE2.fillVectorRayTracSurfaces(S7E2.getPointerPlot());
	OpticalSystemPlotsE2.fillVectorRayTracSurfaces(S8E2.getPointerPlot());
	OpticalSystemPlotsE2.fillVectorRayTracSurfaces(S9E2.getPointerPlot());
	OpticalSystemPlotsE2.fillVectorRayTracSurfaces(S10E2.getPointerPlot());


	// single ray tracing
	SequentialRayTracing SeqTraceE2_plot2D(optSysE2);
	//write SequentialRayTracing new constructor to reduce the three lines to one
	std::vector<LightRayStruct> lightRayAlong_Y_E2 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 3, 5.0, -1.0, 1.0, 550, 1.0);
	SeqTraceE2_plot2D.seqRayTracingWithVectorOfLightRays(lightRayAlong_Y_E2);

	//// single ray tracing
	SequentialRayTracing SeqTraceE2_plot2D_field(optSysE2);
	std::vector<LightRayStruct> lightRayAlong_E2_field = SequentialRayTracing::lightRayAlongY({ 0.0, 0.1, 0.0 }, 3, 5.0, -1.0, 1.0, 550, 1.0);
	SeqTraceE2_plot2D_field.seqRayTracingWithVectorOfLightRays(lightRayAlong_E2_field);

	//// single ray tracing
	SequentialRayTracing SeqTraceE2_plot2D_field2(optSysE2);
	std::vector<LightRayStruct> lightRayAlong_E1_field2 = SequentialRayTracing::lightRayAlongY({ 0.0, -0.1, 0.0 }, 3, 5.0, -1.0, 1.0, 550, 1.0);
	SeqTraceE2_plot2D_field2.seqRayTracingWithVectorOfLightRays(lightRayAlong_E1_field2);

	//fill vector Ray Tracing

	OpticalSystemPlotsE2.fillVectorSequentialRayTracing(&SeqTraceE2_plot2D, { 0,255,215 });
	OpticalSystemPlotsE2.fillVectorSequentialRayTracing(&SeqTraceE2_plot2D_field, { 0,40,200 });
	OpticalSystemPlotsE2.fillVectorSequentialRayTracing(&SeqTraceE2_plot2D_field2, { 150,0,255 });

	//// show surfaces with rays
	PlotParameterQwt ParameterPlotOptSysE2;
	mRayTracingQwtPlotSystem2 = new RayTracingQwtPlot(OpticalSystemPlotsE2, optSysE2, ParameterPlotOptSysE2);
	mRayTracingQwtPlotSystem2->show();

	return mRayTracingQwtPlotSystem2->isVisible();

}



