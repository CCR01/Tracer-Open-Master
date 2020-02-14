#include "TestSpotDiagramQwtPlot.h"

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
#include "..\..\Plot\PlotSpotDiagram.h"
#include "..\..\Plot\PlotOPD.h"
#include "..\..\Plot\PlotParameterQwt.h"


testSpotDiagramQwtPlot::testSpotDiagramQwtPlot() {};
testSpotDiagramQwtPlot::~testSpotDiagramQwtPlot() {};

bool testSpotDiagramQwtPlot::superFuncTestSpotDiagramQwtPlot()
{
	std::vector<bool> checkSpotDiagramQwtPlot;

	bool testE0 = testSpotDiagramQwtPlotE0();
	checkSpotDiagramQwtPlot.push_back(testE0);
	bool testE1 = testSpotDiagramQwtPlotE1();
	checkSpotDiagramQwtPlot.push_back(testE1);
	bool testE2 = testSpotDiagramQwtPlotE2();
	checkSpotDiagramQwtPlot.push_back(testE2);


	bool returnCheck = Math::checkTrueOfVectorElements(checkSpotDiagramQwtPlot);

	return returnCheck;

}


bool testSpotDiagramQwtPlot::testSpotDiagramQwtPlotE0()
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
	optSysE0.fillVectorSurfaceAndInteractingData(1, S0E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(0, S1E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(2, S2E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(3, S3E0.clone(), deflectCR3.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(4, S4E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(5, S5E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(6, S6E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(7, S7E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(8, S8E0.clone(), absorb.clone());




	// fill aperture stop
	FillApertureStop fillAperStopE0_optAchse({ 0.0,0.0,0.0 }, 1, { 0.0,0.0,10.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, light);
	SequentialRayTracing seqTraceE0_OptAchse(optSysE0);
	seqTraceE0_OptAchse.seqRayTracingWithVectorOfLightRays(fillAperStopE0_optAchse.getVectorWithLightRays());

	// fill aperture stop
	FillApertureStop fillAperStopE0_field({ 0.0,0.1,0.0 }, 1, { 0.0,0.0,10.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, light);
	SequentialRayTracing seqTraceE0_field(optSysE0);
	seqTraceE0_field.seqRayTracingWithVectorOfLightRays(fillAperStopE0_field.getVectorWithLightRays());

	//define the Spot Diagramms
	Spot spotE0_optAchese(seqTraceE0_OptAchse.getAllInterPointsAtSurf_i(8), seqTraceE0_OptAchse.getAllInterPointsAtSurf_i(8).at(0));
	std::vector<Spot> vecSpotE0_optAchese{ spotE0_optAchese };
	PlotSpotDiagramm PlotSpotE0_optAchse(spotE0_optAchese.getRefPoint(), vecSpotE0_optAchese, 0.09950372, 550);

	Spot spotE1_field(seqTraceE0_field.getAllInterPointsAtSurf_i(8), seqTraceE0_field.getAllInterPointsAtSurf_i(8).at(0));
	std::vector<Spot> vecSpotE0_field{ spotE1_field };
	PlotSpotDiagramm PlotSpotE0_field(spotE1_field.getRefPoint(), vecSpotE0_field, 0.09950372, 550);

	PlotParameterQwt ParameterPlotSpotDiagramE0;

	//fill vectorSpotDiagram
	optSysE0.fillVectorSpotDiagramToPlot("Spot Diagram optical achse", &PlotSpotE0_optAchse);
	optSysE0.fillVectorSpotDiagramToPlot("Spot Diagram field 1", &PlotSpotE0_field);

	//***********Modify the plot:

	//-add comment at a given position
	ParameterPlotSpotDiagramE0.AddCommentToSpotDiagramPlot("Comment1_SpotDiagram", { 550,-150 });
	ParameterPlotSpotDiagramE0.AddCommentToSpotDiagramPlot("Comment2_SpotDiagram", { 550,-225 });

	//-change the attributes of the airy disc:
	//-----Airy disc color:
	ParameterPlotSpotDiagramE0.setAiryDiskColor(QColor("red"));
	//-----Airy disc thickness
	ParameterPlotSpotDiagramE0.setAiryDiskThickness(2);

	//-change the attributes of the points of the spot diagram
	//-----Style:Ellipse,Rect,Diamond,Triangle, DTriangle, UTriangle, LTriangle, Cross, HLine, Star1, Hexagon, ...
	ParameterPlotSpotDiagramE0.setSymbolStyleOfSpotDiagrammPoints(QwtSymbol::LTriangle);
	//-----Color of the inside of the symbol
	ParameterPlotSpotDiagramE0.setSymbolColorOfSpotDiagrammPoints(QBrush(Qt::yellow));
	//-----Color of the outline of the symbol
	ParameterPlotSpotDiagramE0.setContourColorSymbolOfSpotDiagrammPoints(QPen(Qt::darkGreen, 1));
	//-----Size:
	ParameterPlotSpotDiagramE0.setSizeSymbolOfSpotDiagrammPoints(QSize(4, 4));
	//-----Color of the grid
	ParameterPlotSpotDiagramE0.setFrameColorOfSpotDiagrammPoints(QPen(Qt::white, 2));


	//Plot spot diagram opt achse and field
	mSpotDiagramQwtPlotSystem0 = new SpotPlotDiagramQwt(optSysE0, ParameterPlotSpotDiagramE0, 10, 40);
	mSpotDiagramQwtPlotSystem0->show();
	return mSpotDiagramQwtPlotSystem0->isVisible();

}


bool testSpotDiagramQwtPlot::testSpotDiagramQwtPlotE1()
{
	//all the surfaces
	SphericalSurface_LLT S1E1(/*radius*/38.73360379131933, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, -0.6, 15.0 }, /*Direction*/ VectorStructR3{ 0.0, -0.2, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S2E1(/*radius*/10.33817058758478, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.2, 20.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.1, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S3E1(/*radius*/51.02696739895755, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 22.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S4E1(/*semiHeight*/5.0, /*point*/{ 0.0,0.5,27.0 }, /*direction*/{ 0.0,-0.1,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	SphericalSurface_LLT S5E1(/*radius*/61.48513190056155, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 29.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S6E1(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,34.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	SphericalSurface_LLT S7E1(/*radius*/13.22318498941039, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 36.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S8E1(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,41.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	SphericalSurface_LLT S9E1(/*radius*/12.07896133399859, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 43.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S10E1(/*radius*/26.46510860484050, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 48.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.4, /*refIndexSideB*/1.6);
	SphericalSurface_LLT S11E1(/*radius*/21.48098096423011, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 53.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	SphericalSurface_LLT S12E1(/*radius*/30.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 55.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S13E1(/*radius*/70.0, /*semiHeight*/6.0, /*Apex of the sphere*/{ 0.0, 0.0, 60.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.6, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S14E1(/*radius*/40.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 65.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.6, /*refIndexSideB*/1.0);
	PlanGeometry_LLT S15E1(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,76.8 }, /*direction*/{ 0.0,0.2,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);



	// build the optical system
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

	// fill aperture stops:
   //-optische achse
	FillApertureStop fillAperStopE1_optAchse(/*the start point of the ray*/{ 0.0,0.0,0.0 },/*the semi-height of the apertur*/ 1, /*the position of the apertur */{ 0.0,0.0,10.0 },
		/*the direction of the apertur */{ 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, light);
	SequentialRayTracing seqTraceE1_OptAchse(optSysE1);
	// do sequential ray tracing with vector of many LightRay
	seqTraceE1_OptAchse.seqRayTracingWithVectorOfLightRays(fillAperStopE1_optAchse.getVectorWithLightRays());

	//-field: Ray start at { 0.0,0.1,0.0 }
	FillApertureStop fillAperStopE1_field({ 0.0,0.1,0.0 }, 1, { 0.0,0.0,10.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, light);
	SequentialRayTracing seqTraceE1_field(optSysE1);
	seqTraceE1_field.seqRayTracingWithVectorOfLightRays(fillAperStopE1_field.getVectorWithLightRays());

	//-field: Ray start at { 0.0,0.2,0.0 }
	FillApertureStop fillAperStopE1_field2({ 0.0,0.2,0.0 }, 1, { 0.0,0.0,10.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, light);
	SequentialRayTracing seqTraceE1_field2(optSysE1);
	seqTraceE1_field2.seqRayTracingWithVectorOfLightRays(fillAperStopE1_field2.getVectorWithLightRays());

	//-field: Ray start at { 0.0,0.3,0.0 }
	FillApertureStop fillAperStopE1_field3({ 0.0,0.3,0.0 }, 1, { 0.0,0.0,10.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, light);
	SequentialRayTracing seqTraceE1_field3(optSysE1);
	seqTraceE1_field3.seqRayTracingWithVectorOfLightRays(fillAperStopE1_field3.getVectorWithLightRays());

	//-field: Ray start at { 0.0,0.4,0.0 }
	FillApertureStop fillAperStopE1_field4({ 0.0,0.4,0.0 }, 1, { 0.0,0.0,10.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, light);
	SequentialRayTracing seqTraceE1_field4(optSysE1);
	seqTraceE1_field4.seqRayTracingWithVectorOfLightRays(fillAperStopE1_field4.getVectorWithLightRays());

	//-field: Ray start at { 0.0,0.5,0.0 }
	FillApertureStop fillAperStopE1_field5({ 0.0,0.5,0.0 }, 1, { 0.0,0.0,10.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, light);
	SequentialRayTracing seqTraceE1_field5(optSysE1);
	seqTraceE1_field5.seqRayTracingWithVectorOfLightRays(fillAperStopE1_field5.getVectorWithLightRays());

	//-field: Ray start at { 0.0,0.6,0.0 }
	FillApertureStop fillAperStopE1_field6({ 0.0,0.7,0.0 }, 1, { 0.0,0.0,10.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, light);
	SequentialRayTracing seqTraceE1_field6(optSysE1);
	seqTraceE1_field6.seqRayTracingWithVectorOfLightRays(fillAperStopE1_field6.getVectorWithLightRays());



	//-field: Ray start at { 0.0,0.8,0.0 }
	FillApertureStop fillAperStopE1_field7({ 0.0,0.8,0.0 }, 1, { 0.0,0.0,10.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, light);
	SequentialRayTracing seqTraceE1_field7(optSysE1);
	seqTraceE1_field7.seqRayTracingWithVectorOfLightRays(fillAperStopE1_field7.getVectorWithLightRays());


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


	//define the Spot Diagramms
	Spot spotE1_optAchese(seqTraceE1_OptAchse.getAllInterPointsAtSurf_i(14), seqTraceE1_OptAchse.getAllInterPointsAtSurf_i(14).at(0));
	std::vector<Spot> vecSpotE1_optAchese{ spotE1_optAchese };
	PlotSpotDiagramm PlotSpotE1_optAchse(spotE1_optAchese.getRefPoint(), vecSpotE1_optAchese, 0.09950372, 550);

	Spot spotE1_field(seqTraceE1_field.getAllInterPointsAtSurf_i(14), seqTraceE1_field.getAllInterPointsAtSurf_i(14).at(0));
	std::vector<Spot> vecSpotE1_field{ spotE1_field };
	PlotSpotDiagramm PlotSpotE1_field(spotE1_field.getRefPoint(), vecSpotE1_field, 0.09950372, 550);


	Spot spotE1_field2(seqTraceE1_field2.getAllInterPointsAtSurf_i(14), seqTraceE1_field2.getAllInterPointsAtSurf_i(14).at(0));
	std::vector<Spot> vecSpotE1_field2{ spotE1_field2 };
	PlotSpotDiagramm PlotSpotE1_field2(spotE1_field2.getRefPoint(), vecSpotE1_field2, 0.09950372, 550);

	Spot spotE1_field3(seqTraceE1_field3.getAllInterPointsAtSurf_i(14), seqTraceE1_field3.getAllInterPointsAtSurf_i(14).at(0));
	std::vector<Spot> vecSpotE1_field3{ spotE1_field3 };
	PlotSpotDiagramm PlotSpotE1_field3(spotE1_field3.getRefPoint(), vecSpotE1_field3, 0.09950372, 550);

	Spot spotE1_field4(seqTraceE1_field4.getAllInterPointsAtSurf_i(14), seqTraceE1_field4.getAllInterPointsAtSurf_i(14).at(0));
	std::vector<Spot> vecSpotE1_field4{ spotE1_field4 };
	PlotSpotDiagramm PlotSpotE1_field4(spotE1_field4.getRefPoint(), vecSpotE1_field4, 0.09950372, 550);

	Spot spotE1_field5(seqTraceE1_field5.getAllInterPointsAtSurf_i(14), seqTraceE1_field5.getAllInterPointsAtSurf_i(14).at(0));
	std::vector<Spot> vecSpotE1_field5{ spotE1_field5 };
	PlotSpotDiagramm PlotSpotE1_field5(spotE1_field5.getRefPoint(), vecSpotE1_field5, 0.09950372, 550);

	Spot spotE1_field6(seqTraceE1_field6.getAllInterPointsAtSurf_i(14), seqTraceE1_field6.getAllInterPointsAtSurf_i(14).at(0));
	std::vector<Spot> vecSpotE1_field6{ spotE1_field6 };
	PlotSpotDiagramm PlotSpotE1_field6(spotE1_field6.getRefPoint(), vecSpotE1_field6, 0.09950372, 550);

	Spot spotE1_field7(seqTraceE1_field7.getAllInterPointsAtSurf_i(14), seqTraceE1_field7.getAllInterPointsAtSurf_i(14).at(0));
	std::vector<Spot> vecSpotE1_field7{ spotE1_field7 };
	PlotSpotDiagramm PlotSpotE1_field7(spotE1_field7.getRefPoint(), vecSpotE1_field7, 0.09950372, 550);

	//fill vectorSpotDiagram
	optSysE1.fillVectorSpotDiagramToPlot("Spot Diagram optical achse", &PlotSpotE1_optAchse);
	optSysE1.fillVectorSpotDiagramToPlot("Spot Diagram field 1", &PlotSpotE1_field);
	optSysE1.fillVectorSpotDiagramToPlot("Spot Diagram field 2", &PlotSpotE1_field2);
	optSysE1.fillVectorSpotDiagramToPlot("Spot Diagram field 3", &PlotSpotE1_field3);
	optSysE1.fillVectorSpotDiagramToPlot("Spot Diagram field 4", &PlotSpotE1_field4);
	optSysE1.fillVectorSpotDiagramToPlot("Spot Diagram field 5", &PlotSpotE1_field5);
	optSysE1.fillVectorSpotDiagramToPlot("Spot Diagram field 6", &PlotSpotE1_field6);
	optSysE1.fillVectorSpotDiagramToPlot("Spot Diagram field 7", &PlotSpotE1_field7);


	PlotParameterQwt ParameterPlotSpotDiagramE1;
	//Plot spot diagram opt achse and field
	mSpotDiagramQwtPlotSystem1 = new SpotPlotDiagramQwt(optSysE1, ParameterPlotSpotDiagramE1, 5, 40);
	mSpotDiagramQwtPlotSystem1->show();
	return mSpotDiagramQwtPlotSystem1->isVisible();

}






bool testSpotDiagramQwtPlot::testSpotDiagramQwtPlotE2()
{
	Light_LLT light;
	light.setWavelength(550.0);

	//all the surfaces
	SphericalSurface_LLT S1E2(/*radius*/28.73360379131933, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0, 0.0, 15.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S2E2(/*radius*/50.33817058758478, /*semiHeight*/4.0, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S3E2(/*radius*/51.02696739895755, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 22.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	PlanGeometry_LLT S4E2(/*semiHeight*/5.0, /*point*/{ 0.0,0.5,27.0 }, /*direction*/{ 0.0,-0.1,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	SphericalSurface_LLT S5E2(/*radius*/61.48513190056155, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, -0.2, 29.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S6E2(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,34.0 }, /*direction*/{ 0.0,-0.1,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	SphericalSurface_LLT S7E2(/*radius*/10.22318498941039, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 36.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S8E2(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,41.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	SphericalSurface_LLT S9E2(/*radius*/10.07896133399859, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 43.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S10E2(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,59.5 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);


	// build the optical system
	RefractedRay_LLT refrac;
	OpticalSystem_LLT optSysE2;
	optSysE2.fillVectorSurfaceAndInteractingData(0, S1E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(1, S2E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(2, S3E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(3, S4E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(4, S5E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(5, S6E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(6, S7E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(7, S8E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(8, S9E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(9, S10E2.clone(), refrac.clone());


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

	// fill aperture stop
	FillApertureStop fillAperStopE2_optAchse({ 0.0,0.0,0.0 }, 1, { 0.0,0.0,10.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, light);
	SequentialRayTracing seqTraceE2_OptAchse(optSysE2);
	seqTraceE2_OptAchse.seqRayTracingWithVectorOfLightRays(fillAperStopE2_optAchse.getVectorWithLightRays());

	// fill aperture stop
	FillApertureStop fillAperStopE2_field({ 0.0,0.1,0.0 }, 1, { 0.0,0.0,10.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, light);
	SequentialRayTracing seqTraceE2_field(optSysE2);
	seqTraceE2_field.seqRayTracingWithVectorOfLightRays(fillAperStopE2_field.getVectorWithLightRays());

	// fill aperture stop
	FillApertureStop fillAperStopE2_field2({ 0.0,0.5,0.0 }, 1, { 0.0,0.0,10.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, light);
	SequentialRayTracing seqTraceE2_field2(optSysE2);
	seqTraceE2_field2.seqRayTracingWithVectorOfLightRays(fillAperStopE2_field2.getVectorWithLightRays());


	//define the Spot Diagramms
	Spot spotE1_optAchese(seqTraceE2_OptAchse.getAllInterPointsAtSurf_i(9), seqTraceE2_OptAchse.getAllInterPointsAtSurf_i(9).at(0));
	std::vector<Spot> vecSpotE1_optAchese{ spotE1_optAchese };
	PlotSpotDiagramm PlotSpotE2_optAchse(spotE1_optAchese.getRefPoint(), vecSpotE1_optAchese, 0.09950372, 550);

	Spot spotE1_field(seqTraceE2_field.getAllInterPointsAtSurf_i(9), seqTraceE2_field.getAllInterPointsAtSurf_i(9).at(0));
	std::vector<Spot> vecSpotE1_field{ spotE1_field };
	PlotSpotDiagramm PlotSpotE2_field(spotE1_field.getRefPoint(), vecSpotE1_field, 0.09950372, 550);


	Spot spotE1_field2(seqTraceE2_field2.getAllInterPointsAtSurf_i(9), seqTraceE2_field2.getAllInterPointsAtSurf_i(9).at(0));
	std::vector<Spot> vecSpotE1_field2{ spotE1_field2 };
	PlotSpotDiagramm PlotSpotE2_field2(spotE1_field2.getRefPoint(), vecSpotE1_field2, 0.09950372, 550);

	//fill vectorSpotDiagram
	optSysE2.fillVectorSpotDiagramToPlot("Spot Diagram optical achse", &PlotSpotE2_optAchse);
	optSysE2.fillVectorSpotDiagramToPlot("Spot Diagram field 1", &PlotSpotE2_field);
	optSysE2.fillVectorSpotDiagramToPlot("Spot Diagram field 2", &PlotSpotE2_field2);

	//Plot spot diagram opt achse and field
	PlotParameterQwt ParameterPlotSpotDiagramE2;
	mSpotDiagramQwtPlotSystem2 = new SpotPlotDiagramQwt(optSysE2, ParameterPlotSpotDiagramE2, 3, 50);
	mSpotDiagramQwtPlotSystem2->show();

	return mSpotDiagramQwtPlotSystem2->isVisible();
}