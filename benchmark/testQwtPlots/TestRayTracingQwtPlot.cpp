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
	bool testE3 = testRayTracingQwtPlotE3();
	checkQwtPlot.push_back(testE3);

	bool returnCheck = Math::checkTrueOfVectorElements(checkQwtPlot);

	return returnCheck;

}

bool testRayTracingQwtPlot::testRayTracingQwtPlotE0()
{
	// interactions
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	Light_LLT light;
	DoNothingInteraction_LLT doNothing;
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
	optSysE0.fillVectorSurfaceAndInteractingData(0, S0E0.clone(), doNothing.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(1, S1E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(2, S2E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(3, S3E0.clone(), deflectCR3.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(4, S4E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(5, S5E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(6, S6E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(7, S7E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(8, S8E0.clone(), absorb.clone());

	//single ray tracing
	Ray_LLT ray(/*origin*/{ 0.0,0.0,0.0 },/*direction*/{ 0.0,0.5,5.0 },/*refractive index*/ 1.0);
	LightRayStruct lightRay(light, ray, 1);
	SequentialRayTracing seqTrace_single(optSysE0);
	seqTrace_single.sequentialRayTracing(lightRay);
	IntersectInformationStruct interInfosS0 = seqTrace_single.getAllInterInfosOfSurf_i(0).at(0);
	IntersectInformationStruct interInfosS1 = seqTrace_single.getAllInterInfosOfSurf_i(1).at(0);
	IntersectInformationStruct interInfosS2 = seqTrace_single.getAllInterInfosOfSurf_i(2).at(0);
	IntersectInformationStruct interInfosS3 = seqTrace_single.getAllInterInfosOfSurf_i(3).at(0);
	IntersectInformationStruct interInfosS4 = seqTrace_single.getAllInterInfosOfSurf_i(4).at(0);
	IntersectInformationStruct interInfosS5 = seqTrace_single.getAllInterInfosOfSurf_i(5).at(0);
	IntersectInformationStruct interInfosS6 = seqTrace_single.getAllInterInfosOfSurf_i(6).at(0);
	IntersectInformationStruct interInfosS7 = seqTrace_single.getAllInterInfosOfSurf_i(7).at(0);
	IntersectInformationStruct interInfosS8 = seqTrace_single.getAllInterInfosOfSurf_i(8).at(0);


	// ray tracing optica axis
	SequentialRayTracing seqTrace_E0_optA(optSysE0);
	FillApertureStop fillAperStop_optA(/*start point rays*/{ 0.0,0.0,0.0 },/*semi height of aperture stop*/ 0.5,/*point of aperture stop*/{ 0.0,0.0,5.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/6,/*arms*/ 8,/*refractive index*/ 1.0, light);
	seqTrace_E0_optA.seqRayTracingWithVectorOfLightRays(fillAperStop_optA.getVectorWithLightRays());
	Spot spot_optA(/*intersection points*/ seqTrace_E0_optA.getAllInterPointsAtSurf_i(8), /*reference point*/seqTrace_E0_optA.getAllInterPointsAtSurf_i(8).at(0));

	// ray tracing field 1
	SequentialRayTracing seqTrace_E0_field1(optSysE0);
	FillApertureStop fillAperStop_field1(/*start point rays*/{ 0.0,1.0,0.0 },/*semi height of aperture stop*/ 0.5,/*point of aperture stop*/{ 0.0,0.0,5.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/6,/*arms*/ 8,/*refractive index*/ 1.0, light);
	seqTrace_E0_field1.seqRayTracingWithVectorOfLightRays(fillAperStop_field1.getVectorWithLightRays());
	Spot spot_field1(/*intersection points*/ seqTrace_E0_field1.getAllInterPointsAtSurf_i(8), /*reference point*/seqTrace_E0_field1.getAllInterPointsAtSurf_i(8).at(0));

	//to draw the aperturre stop two curves must be added to the table of surfaces to be ploted the upper part through getPointerPlotUp() and the other through getPointerPlotDown()
	//can be ploted using one curve when finding a method to plot a curve with gaps
	optSysE0.fillVectorToPlot2DQwt(0, S0E0.getPointerPlotUp());
	optSysE0.fillVectorToPlot2DQwt(1, S0E0.getPointerPlotDown());
	optSysE0.fillVectorToPlot2DQwt(2, S1E0.getPointerPlot());
	optSysE0.fillVectorToPlot2DQwt(3, S2E0.getPointerPlot());
	optSysE0.fillVectorToPlot2DQwt(4, S3E0.getPointerPlot());
	optSysE0.fillVectorToPlot2DQwt(5, S4E0.getPointerPlot());
	optSysE0.fillVectorToPlot2DQwt(6, S5E0.getPointerPlot());
	optSysE0.fillVectorToPlot2DQwt(7, S6E0.getPointerPlot());
	optSysE0.fillVectorToPlot2DQwt(8, S7E0.getPointerPlot());
	optSysE0.fillVectorToPlot2DQwt(9, S8E0.getPointerPlot());


	//fill vector Ray Tracing
	RayTracingSystem RayTracSysE0;
	RayTracSysE0.fillVectorRayTracing(&seqTrace_E0_optA, { 192,192,192 });
	RayTracSysE0.fillVectorRayTracing(&seqTrace_E0_field1, { 240,128,128 });

	//change Plot Parameter 
	PlotParameterQwt ParameterPlotOptSysE0;
	//Add a comment to the plot
	ParameterPlotOptSysE0.AddCommentToRayTracingPlot("Add-Comment", { 80,200 });
	//change the colour of the surfaces
	ParameterPlotOptSysE0.setColorSurfaces({ 0,128,0 });
	//change the thickness of the surfaces
	ParameterPlotOptSysE0.setThicknessSurfaces(3);

	//// show surfaces with rays
	mRayTracingQwtPlotSystem2 = new RayTracingQwtPlot(optSysE0, RayTracSysE0, ParameterPlotOptSysE0);
	mRayTracingQwtPlotSystem2->show();
	return mRayTracingQwtPlotSystem2->isVisible();
}


bool testRayTracingQwtPlot::testRayTracingQwtPlotE1()
{

	//define all the surfaces of the system
	SphericalSurface_LLT S1E1(/*radius*/38.73360379131933, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, -0.6, 15.0 }, /*Direction*/ VectorStructR3{ 0.0, -0.2, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S2E1(/*radius*/10.33817058758478, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.2, 20.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.1, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S3E1(/*radius*/51.02696739895755, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 22.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S4E1(/*semiHeight*/5.0, /*point*/{ 0.0,0.5,27.0 }, /*direction*/{ 0.0,-0.1,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
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
	PlanGeometry_LLT S15E1(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,73.5 }, /*direction*/{ 0.0,0.2,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);




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

	optSysE1.fillVectorToPlot2DQwt(0, S1E1.getPointerPlot());
	optSysE1.fillVectorToPlot2DQwt(1, S2E1.getPointerPlot());
	optSysE1.fillVectorToPlot2DQwt(2, S3E1.getPointerPlot());
	optSysE1.fillVectorToPlot2DQwt(3, S4E1.getPointerPlot());
	optSysE1.fillVectorToPlot2DQwt(4, S5E1.getPointerPlot());
	optSysE1.fillVectorToPlot2DQwt(5, S6E1.getPointerPlot());
	optSysE1.fillVectorToPlot2DQwt(6, S7E1.getPointerPlot());
	optSysE1.fillVectorToPlot2DQwt(7, S8E1.getPointerPlot());
	optSysE1.fillVectorToPlot2DQwt(8, S9E1.getPointerPlot());
	optSysE1.fillVectorToPlot2DQwt(9, S10E1.getPointerPlot());
	optSysE1.fillVectorToPlot2DQwt(10, S11E1.getPointerPlot());
	optSysE1.fillVectorToPlot2DQwt(11, S12E1.getPointerPlot());
	optSysE1.fillVectorToPlot2DQwt(12, S13E1.getPointerPlot());
	optSysE1.fillVectorToPlot2DQwt(13, S14E1.getPointerPlot());
	optSysE1.fillVectorToPlot2DQwt(14, S15E1.getPointerPlot());

	//// single ray tracing
	//SequentialRayTracing SeqTraceE1_plot2D(optSysE1);
	//std::vector<LightRayStruct> lightRayAlong_Y_E1 = SequentialRayTracing::lightRayAlongY({ 0.0, -0.5, 0.0 }, 3, 10.0, -1.0, 1.0, 550, 1.0);
	//SeqTraceE1_plot2D.seqRayTracingWithVectorOfLightRays(lightRayAlong_Y_E1);

	//// single ray tracing
	SequentialRayTracing SeqTraceE1_plot2D_field(optSysE1);
	std::vector<LightRayStruct> lightRayAlong_E1_field = SequentialRayTracing::lightRayAlongY({ 0.0, 0.4, 0.0 }, 3, 10.0, -1.0, 1.0, 550, 1.0);
	SeqTraceE1_plot2D_field.seqRayTracingWithVectorOfLightRays(lightRayAlong_E1_field);


	////// single ray tracing
	//SequentialRayTracing SeqTraceE1_plot2D_field2(optSysE1);
	//std::vector<LightRayStruct> lightRayAlong_E1_field2 = SequentialRayTracing::lightRayAlongY({ 0.0, -0.4, 0.0 }, 3, 10.0, -1.0, 1.0, 550, 1.0);
	//SeqTraceE1_plot2D_field2.seqRayTracingWithVectorOfLightRays(lightRayAlong_E1_field2);

	//// single ray tracing
	SequentialRayTracing SeqTraceE1_plot2D_field3(optSysE1);
	std::vector<LightRayStruct> lightRayAlong_E1_field3 = SequentialRayTracing::lightRayAlongY({ 0.0, -0.3, 0.0 }, 3, 10.0, -1.0, 1.0, 550, 1.0);
	SeqTraceE1_plot2D_field3.seqRayTracingWithVectorOfLightRays(lightRayAlong_E1_field3);


	//// single ray tracing
	SequentialRayTracing SeqTraceE1_plot2D_field4(optSysE1);
	std::vector<LightRayStruct> lightRayAlong_E1_field4 = SequentialRayTracing::lightRayAlongY({ 0.0, -0.2, 0.0 }, 3, 10.0, -1.0, 1.0, 550, 1.0);
	SeqTraceE1_plot2D_field4.seqRayTracingWithVectorOfLightRays(lightRayAlong_E1_field4);

	//// single ray tracing
	SequentialRayTracing SeqTraceE1_plot2D_field5(optSysE1);
	std::vector<LightRayStruct> lightRayAlong_E1_field5 = SequentialRayTracing::lightRayAlongY({ 0.0, -0.1, 0.0 }, 3, 10.0, -1.0, 1.0, 550, 1.0);
	SeqTraceE1_plot2D_field5.seqRayTracingWithVectorOfLightRays(lightRayAlong_E1_field5);

	//// single ray tracing
	SequentialRayTracing SeqTraceE1_plot2D_field6(optSysE1);
	std::vector<LightRayStruct> lightRayAlong_E1_field6 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.1, 0.0 }, 3, 10.0, -1.0, 1.0, 550, 1.0);
	SeqTraceE1_plot2D_field6.seqRayTracingWithVectorOfLightRays(lightRayAlong_E1_field6);


	//// single ray tracing
	SequentialRayTracing SeqTraceE1_plot2D_field7(optSysE1);
	std::vector<LightRayStruct> lightRayAlong_E1_field7 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.2, 0.0 }, 3, 10.0, -1.0, 1.0, 550, 1.0);
	SeqTraceE1_plot2D_field7.seqRayTracingWithVectorOfLightRays(lightRayAlong_E1_field7);



	//fill vector Ray Tracing
	RayTracingSystem RayTracSysE1;
	//RayTracSysE1.fillVectorRayTracing(&SeqTraceE1_plot2D, { 0,100,0 });
	RayTracSysE1.fillVectorRayTracing(&SeqTraceE1_plot2D_field, { 0,0,255 });
	//RayTracSysE1.fillVectorRayTracing(&SeqTraceE1_plot2D_field2, { 150,0,10 });
	RayTracSysE1.fillVectorRayTracing(&SeqTraceE1_plot2D_field3, { 250,225,0 });
	RayTracSysE1.fillVectorRayTracing(&SeqTraceE1_plot2D_field4, { 150,20,210 });
	RayTracSysE1.fillVectorRayTracing(&SeqTraceE1_plot2D_field5, { 240,40,90 });
	RayTracSysE1.fillVectorRayTracing(&SeqTraceE1_plot2D_field6, { 125,225,180 });
	RayTracSysE1.fillVectorRayTracing(&SeqTraceE1_plot2D_field7, { 198,200,110 });


	//initiate the plot parameter
	PlotParameterQwt ParameterPlotOptSysE1;
	//// show surfaces with rays
	mRayTracingQwtPlotSystem2 = new RayTracingQwtPlot(optSysE1, RayTracSysE1, ParameterPlotOptSysE1);
	mRayTracingQwtPlotSystem2->show();

	return mRayTracingQwtPlotSystem2->isVisible();
}

bool testRayTracingQwtPlot::testRayTracingQwtPlotE2()
{

	typedef std::shared_ptr<SurfaceIntersectionRay_LLT> surfaceLLT_ptr;
	typedef std::shared_ptr<InteractionRay_LLT> interactionLLT_ptr;

	SphericalSurface_LLT S1E2(/*radius*/28.73360379131933, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0, 0.0, 15.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S2E2(/*radius*/50.33817058758478, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S3E2(/*radius*/51.02696739895755, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 22.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	PlanGeometry_LLT S4E2(/*semiHeight*/5.0, /*point*/{ 0.0,0.5,27.0 }, /*direction*/{ 0.0,-0.1,1.0 }, /*refractiveSideA*/ 1.6, /*refractiveSideB*/ 1.0);
	SphericalSurface_LLT S5E2(/*radius*/61.48513190056155, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, -0.2, 29.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S6E2(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,34.0 }, /*direction*/{ 0.0,-0.1,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	SphericalSurface_LLT S7E2(/*radius*/10.22318498941039, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 36.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S8E2(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,41.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.1);
	SphericalSurface_LLT S9E2(/*radius*/10.07896133399859, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 43.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.1, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S10E2(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,62.1 }, /*direction*/{ 0.0,0.1,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);


	// build the optical system
	RefractedRay_LLT refrac;

	// vector with surfaces
	std::vector<surfaceLLT_ptr> surfaces_vec{ S1E2.clone(),S2E2.clone(),S3E2.clone(),S4E2.clone(),S5E2.clone(),S6E2.clone(),S7E2.clone(),S8E2.clone(),S9E2.clone(),S10E2.clone() };
	// vector with interactions
	std::vector<interactionLLT_ptr> interaction_vec{ refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone() };

	OpticalSystem_LLT optSysE2(surfaces_vec, interaction_vec);



	//// plot 2d
	optSysE2.fillVectorToPlot2DQwt(0, S1E2.getPointerPlot());
	optSysE2.fillVectorToPlot2DQwt(1, S2E2.getPointerPlot());
	optSysE2.fillVectorToPlot2DQwt(2, S3E2.getPointerPlot());
	optSysE2.fillVectorToPlot2DQwt(3, S4E2.getPointerPlot());
	optSysE2.fillVectorToPlot2DQwt(4, S5E2.getPointerPlot());
	optSysE2.fillVectorToPlot2DQwt(5, S6E2.getPointerPlot());
	optSysE2.fillVectorToPlot2DQwt(6, S7E2.getPointerPlot());
	optSysE2.fillVectorToPlot2DQwt(7, S8E2.getPointerPlot());
	optSysE2.fillVectorToPlot2DQwt(8, S9E2.getPointerPlot());
	optSysE2.fillVectorToPlot2DQwt(9, S10E2.getPointerPlot());

	// single ray tracing
	SequentialRayTracing SeqTraceE2_plot2D(optSysE2);
	std::vector<LightRayStruct> lightRayAlong_Y_E2 = SequentialRayTracing::lightRayAlongY({ 0.0, -0.5, 0.0 }, 3, 10.0, -1.0, 1.0, 550, 1.0);
	SeqTraceE2_plot2D.seqRayTracingWithVectorOfLightRays(lightRayAlong_Y_E2);

	//// single ray tracing
	SequentialRayTracing SeqTraceE2_plot2D_field(optSysE2);
	std::vector<LightRayStruct> lightRayAlong_E2_field = SequentialRayTracing::lightRayAlongY({ 0.0, -0.3, 0.0 }, 3, 10.0, -1.0, 1.0, 550, 1.0);
	SeqTraceE2_plot2D_field.seqRayTracingWithVectorOfLightRays(lightRayAlong_E2_field);

	//// single ray tracing
	SequentialRayTracing SeqTraceE2_plot2D_field2(optSysE2);
	std::vector<LightRayStruct> lightRayAlong_E1_field2 = SequentialRayTracing::lightRayAlongY({ 0.0, -0.7, 0.0 }, 3, 10.0, -1.0, 1.0, 550, 1.0);
	SeqTraceE2_plot2D_field2.seqRayTracingWithVectorOfLightRays(lightRayAlong_E1_field2);

	//fill vector Ray Tracing
	RayTracingSystem RayTracSysE2;
	RayTracSysE2.fillVectorRayTracing(&SeqTraceE2_plot2D, { 0,255,215 });
	RayTracSysE2.fillVectorRayTracing(&SeqTraceE2_plot2D_field, { 0,40,200 });
	RayTracSysE2.fillVectorRayTracing(&SeqTraceE2_plot2D_field2, { 150,0,255 });

	//// show surfaces with rays
	PlotParameterQwt ParameterPlotOptSysE2;
	mRayTracingQwtPlotSystem2 = new RayTracingQwtPlot(optSysE2, RayTracSysE2, ParameterPlotOptSysE2);
	mRayTracingQwtPlotSystem2->show();

	return mRayTracingQwtPlotSystem2->isVisible();

}

bool testRayTracingQwtPlot::testRayTracingQwtPlotE3()
{
	//define all the surfaces of the system
	SphericalSurface_LLT S1E3(/*radius*/38.73360379131933, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 15.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S2E3(/*radius*/10.33817058758478, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.1, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S3E3(/*radius*/51.02696739895755, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 22.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S4E3(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,27.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	SphericalSurface_LLT S5E3(/*radius*/61.48513190056155, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 29.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S6E3(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,34.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	SphericalSurface_LLT S7E3(/*radius*/13.22318498941039, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 36.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S8E3(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,41.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.1);
	SphericalSurface_LLT S9E3(/*radius*/12.07896133399859, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 43.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.1);
	SphericalSurface_LLT S10E3(/*radius*/26.46510860484050, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 48.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.4, /*refIndexSideB*/1.6);
	SphericalSurface_LLT S11E3(/*radius*/21.48098096423011, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 53.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	SphericalSurface_LLT S12E3(/*radius*/30.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 55.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S13E3(/*radius*/70.0, /*semiHeight*/6.0, /*Apex of the sphere*/{ 0.0, 0.0, 60.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.6, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S14E3(/*radius*/40.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 65.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.6, /*refIndexSideB*/1.0);
	PlanGeometry_LLT S15E3(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,73.5 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);




	// build the optical system by giving the position of each surface, its referance and its interaction
	RefractedRay_LLT refrac;
	OpticalSystem_LLT optSysE3;
	optSysE3.fillVectorSurfaceAndInteractingData(0, S1E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(1, S2E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(2, S3E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(3, S4E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(4, S5E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(5, S6E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(6, S7E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(7, S8E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(8, S9E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(9, S10E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(10, S11E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(11, S12E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(12, S13E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(13, S14E3.clone(), refrac.clone());
	optSysE3.fillVectorSurfaceAndInteractingData(14, S15E3.clone(), refrac.clone());

	Light_LLT light;
	light.setWavelength(550.0);

	//// plot 2d

	optSysE3.fillVectorToPlot2DQwt(0, S1E3.getPointerPlot());
	optSysE3.fillVectorToPlot2DQwt(1, S2E3.getPointerPlot());
	optSysE3.fillVectorToPlot2DQwt(2, S3E3.getPointerPlot());
	optSysE3.fillVectorToPlot2DQwt(3, S4E3.getPointerPlot());
	optSysE3.fillVectorToPlot2DQwt(4, S5E3.getPointerPlot());
	optSysE3.fillVectorToPlot2DQwt(5, S6E3.getPointerPlot());
	optSysE3.fillVectorToPlot2DQwt(6, S7E3.getPointerPlot());
	optSysE3.fillVectorToPlot2DQwt(7, S8E3.getPointerPlot());
	optSysE3.fillVectorToPlot2DQwt(8, S9E3.getPointerPlot());
	optSysE3.fillVectorToPlot2DQwt(9, S10E3.getPointerPlot());
	optSysE3.fillVectorToPlot2DQwt(10, S11E3.getPointerPlot());
	optSysE3.fillVectorToPlot2DQwt(11, S12E3.getPointerPlot());
	optSysE3.fillVectorToPlot2DQwt(12, S13E3.getPointerPlot());
	optSysE3.fillVectorToPlot2DQwt(13, S14E3.getPointerPlot());
	optSysE3.fillVectorToPlot2DQwt(14, S15E3.getPointerPlot());

	// single ray tracing
	SequentialRayTracing SeqTraceE3_plot2D(optSysE3);
	std::vector<LightRayStruct> lightRayAlong_Y_E3 = SequentialRayTracing::lightRayAlongY({ 0.0, -0.5, 0.0 }, 7, 10.0, -2.0, 2.0, 550, 1.0);
	SeqTraceE3_plot2D.seqRayTracingWithVectorOfLightRays(lightRayAlong_Y_E3);

	//// single ray tracing
	SequentialRayTracing SeqTraceE3_plot2D_field(optSysE3);
	std::vector<LightRayStruct> lightRayAlong_E3_field = SequentialRayTracing::lightRayAlongY({ 0.0, 0.5, 0.0 }, 7, 10.0, -2.0, 2.0, 550, 1.0);
	SeqTraceE3_plot2D_field.seqRayTracingWithVectorOfLightRays(lightRayAlong_E3_field);


	//// single ray tracing
	SequentialRayTracing SeqTraceE3_plot2D_field2(optSysE3);
	std::vector<LightRayStruct> lightRayAlong_E3_field2 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 7, 10.0, -2.0, 2.0, 550, 1.0);
	SeqTraceE3_plot2D_field2.seqRayTracingWithVectorOfLightRays(lightRayAlong_E3_field2);

	////// single ray tracing
	//SequentialRayTracing SeqTraceE3_plot2D_field3(optSysE3);
	//std::vector<LightRayStruct> lightRayAlong_E3_field3 = SequentialRayTracing::lightRayAlongY({ 0.0, -0.3, 0.0 }, 3, 10.0, -2.0, 2.0, 550, 1.0);
	//SeqTraceE3_plot2D_field3.seqRayTracingWithVectorOfLightRays(lightRayAlong_E3_field3);
	//
	//
	////// single ray tracing
	//SequentialRayTracing SeqTraceE3_plot2D_field4(optSysE3);
	//std::vector<LightRayStruct> lightRayAlong_E3_field4 = SequentialRayTracing::lightRayAlongY({ 0.0, -0.2, 0.0 }, 3, 10.0, -2.0, 2.0, 550, 1.0);
	//SeqTraceE3_plot2D_field4.seqRayTracingWithVectorOfLightRays(lightRayAlong_E3_field4);
	//
	////// single ray tracing
	//SequentialRayTracing SeqTraceE3_plot2D_field5(optSysE3);
	//std::vector<LightRayStruct> lightRayAlong_E3_field5 = SequentialRayTracing::lightRayAlongY({ 0.0, -0.1, 0.0 }, 3, 10.0, -2.0, 2.0, 550, 1.0);
	//SeqTraceE3_plot2D_field5.seqRayTracingWithVectorOfLightRays(lightRayAlong_E3_field5);
	//
	////// single ray tracing
	//SequentialRayTracing SeqTraceE3_plot2D_field6(optSysE3);
	//std::vector<LightRayStruct> lightRayAlong_E3_field6 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.1, 0.0 }, 3, 10.0, -2.0, 2.0, 550, 1.0);
	//SeqTraceE3_plot2D_field6.seqRayTracingWithVectorOfLightRays(lightRayAlong_E3_field6);
	//
	//
	////// single ray tracing
	//SequentialRayTracing SeqTraceE3_plot2D_field7(optSysE3);
	//std::vector<LightRayStruct> lightRayAlong_E3_field7 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.2, 0.0 }, 3, 10.0, -2.0, 2.0, 550, 1.0);
	//SeqTraceE3_plot2D_field7.seqRayTracingWithVectorOfLightRays(lightRayAlong_E3_field7);



	//fill vector Ray Tracing
	RayTracingSystem RayTracSysE3;
	RayTracSysE3.fillVectorRayTracing(&SeqTraceE3_plot2D, { 255,0,0 });
	RayTracSysE3.fillVectorRayTracing(&SeqTraceE3_plot2D_field, { 0,255,0 });
	RayTracSysE3.fillVectorRayTracing(&SeqTraceE3_plot2D_field2, { 0,0,255 });
	//RayTracSysE3.fillVectorRayTracing(&SeqTraceE3_plot2D_field3, { 250,225,0 });
	//RayTracSysE3.fillVectorRayTracing(&SeqTraceE3_plot2D_field4, { 150,20,210 });
	//RayTracSysE3.fillVectorRayTracing(&SeqTraceE3_plot2D_field5, { 240,40,90 });
	//RayTracSysE3.fillVectorRayTracing(&SeqTraceE3_plot2D_field6, { 125,225,180 });
	//RayTracSysE3.fillVectorRayTracing(&SeqTraceE3_plot2D_field7, { 198,200,110 });


	//initiate the plot parameter
	PlotParameterQwt ParameterPlotOptSysE3;
	//// show surfaces with rays
	mRayTracingQwtPlotSystem2 = new RayTracingQwtPlot(optSysE3, RayTracSysE3, ParameterPlotOptSysE3);
	mRayTracingQwtPlotSystem2->show();

	return mRayTracingQwtPlotSystem2->isVisible();
}