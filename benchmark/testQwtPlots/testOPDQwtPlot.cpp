#include "TestOPDQwtPlot.h"

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


testOPDQwtPlot::testOPDQwtPlot() {};
testOPDQwtPlot::~testOPDQwtPlot() {};



bool testOPDQwtPlot::superFuncTestOPDQwtPlot()
{
	std::vector<bool> checkOPDPlot;

	bool testE0 = testOPDQwtPlotE0();
	checkOPDPlot.push_back(testE0);
	bool testE1 = true;// testOPDQwtPlotE1();
	checkOPDPlot.push_back(testE1);
	bool testE2 = true;// testOPDQwtPlotE2();
	checkOPDPlot.push_back(testE2);


	bool returnCheck = Math::checkTrueOfVectorElements(checkOPDPlot);

	return returnCheck;

}


//OPD plot SystemE0
bool testOPDQwtPlot::testOPDQwtPlotE0()
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


	// Plot OPD opt achse
	Ray_LLT chiefRayE0_optAchse({ 0.0,0.0,0.0 }, { 0.0,0.0,0.5 }, 1.0);
	LightRayStruct chiefLightRayE0_optAchse(light, chiefRayE0_optAchse, 1);
	Ray_LLT chiefRayE0_field({ 0.0,0.5,0.0 }, { 0.0,0.5,10.0 }, 1.0);
	LightRayStruct chiefLightRayE0_field(light, chiefRayE0_field, 1);
	PlanGeometry_LLT exitPupilE0(/*semiHeight*/20.0, /*point*/{ 0.0,0.0,2.5696182 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	std::vector<LightRayStruct> lightRayAlong_X_E0_optAchse2 = SequentialRayTracing::lightRayAlongX({ 0.0, 0.0, 0.0 }, 100, 10.0, -1.0, 1.0, 550, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_E0_optAchse2 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 100, 10.0, -1.0, 1.0, 550, 1.0);
	OPD OPD_E0_optAchse2(exitPupilE0.clone(), optSysE0, lightRayAlong_X_E0_optAchse2, lightRayAlong_Y_E0_optAchse2, chiefLightRayE0_optAchse);
	PlotOPD plotOPD_E0_optAchse(OPD_E0_optAchse2);

	//load the parameters of the OPD plot
	PlotParameterQwt plotOPD_E0_Parameter;
	//change the style of the symbols
	//plotOPD_E0_Parameter.setOPDSymbolStyle(QwtSymbol::Rect);
	//change the size of the symbols
	//plotOPD_E0_Parameter.setOPDSizeSymbol(QSize(4, 3));
	//change the colour of the symbols
	//plotOPD_E0_Parameter.setOPDSymbolColor(QBrush(Qt::red));
	//change the contour colour of the symbols
	//plotOPD_E0_Parameter.setOPDContourColorSymbol(QPen(Qt::blue, 1));
	//add a comment to the OPD plot at a given position
	//plotOPD_E0_Parameter.AddCommentToOPDPlot("Comment_OPD_Plot", { -5,-200 });
	//change the colour of the frame of the plots
	//plotOPD_E0_Parameter.setOPDFrameColor(QColor("lightblue"));


	SystemPlots systemPlotsE0;
	systemPlotsE0.fillVectorplotOPDDiagramToPlot(&plotOPD_E0_optAchse);
	//OPD plot
	mOPDQwtPlotSystem0 = new PlotOPDQwt(systemPlotsE0, plotOPD_E0_optAchse, plotOPD_E0_Parameter);
	mOPDQwtPlotSystem0->show();

	//check if the OPD plot is shown
	return mOPDQwtPlotSystem0->isVisible();
}


//OPD plot SystemE1
bool testOPDQwtPlot::testOPDQwtPlotE1()
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

	// Plot OPD field start { 0.0, 1.0, 0.0 }
	Ray_LLT chiefRayE1_optAchse({ 0.0,0.0,0.0 }, { 0.0,0.0,1.0 }, 1.0);
	LightRayStruct chiefLightRayE1_optAchse(light, chiefRayE1_optAchse, 1);
	Ray_LLT chiefRayE1_field({ 0.0,1.0,0.0 }, { 0.0,-1.0,10.0 }, 1.0);
	LightRayStruct chiefLightRayE1_field(light, chiefRayE1_field, 1);
	PlanGeometry_LLT exitPupilE1(/*semiHeight*/20.0, /*point*/{ 0.0,0.0,201.5696182 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	std::vector<LightRayStruct> lightRayAlong_X_E1_field2 = SequentialRayTracing::lightRayAlongX({ 0.0, 1.0, 0.0 }, 80, 10.0, -1.0, 1.0, 550, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_E1_field2 = SequentialRayTracing::lightRayAlongY({ 0.0, 1.0, 0.0 }, 80, 10.0, -1.0, 1.0, 550, 1.0);
	OPD OPD_E1_field2(exitPupilE1.clone(), optSysE1, lightRayAlong_X_E1_field2, lightRayAlong_Y_E1_field2, chiefLightRayE1_field);
	PlotOPD plotOPD_E1_field(OPD_E1_field2);

	//initiate the parameter of the OPD plot
	PlotParameterQwt plotOPD_E1_Parameter;
	SystemPlots systemPlotsE1;
	systemPlotsE1.fillVectorplotOPDDiagramToPlot(&plotOPD_E1_field);
	//Plot the OPD plot
	mOPDQwtPlotSystem1 = new PlotOPDQwt(systemPlotsE1, plotOPD_E1_field, plotOPD_E1_Parameter);
	mOPDQwtPlotSystem1->show();
	//check if the OPD plot is shown
	return mOPDQwtPlotSystem1->isVisible();
}


//OPD plot SystemE2
bool testOPDQwtPlot::testOPDQwtPlotE2()
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



	// Plot OPD opt achse
	Ray_LLT chiefRayE2_optAchse({ 0.0,0.0,0.0 }, { 0.0,0.0,0.5 }, 1.0);
	LightRayStruct chiefLightRayE2_optAchse(light, chiefRayE2_optAchse, 1);
	Ray_LLT chiefRayE2_field({ 0.0,0.5,0.0 }, { 0.0,0.5,10.0 }, 1.0);
	LightRayStruct chiefLightRayE2_field(light, chiefRayE2_field, 1);
	PlanGeometry_LLT exitPupilE2(/*semiHeight*/20.0, /*point*/{ 0.0,0.0,2.5696182 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	std::vector<LightRayStruct> lightRayAlong_X_E2_optAchse2 = SequentialRayTracing::lightRayAlongX({ 0.0, 0.0, 0.0 }, 100, 10.0, -1.0, 1.0, 550, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_E2_optAchse2 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 100, 10.0, -1.0, 1.0, 550, 1.0);
	OPD OPD_E2_optAchse2(exitPupilE2.clone(), optSysE2, lightRayAlong_X_E2_optAchse2, lightRayAlong_Y_E2_optAchse2, chiefLightRayE2_optAchse);
	PlotOPD plotOPD_E2_optAchse(OPD_E2_optAchse2);
	//initiate the parameter of the OPD plot
	PlotParameterQwt plotOPD_E2_Parameter;
	SystemPlots systemPlotsE2;
	systemPlotsE2.fillVectorplotOPDDiagramToPlot(&plotOPD_E2_optAchse);
	//Plot the OPD plot
	mOPDQwtPlotSystem2 = new PlotOPDQwt(systemPlotsE2, plotOPD_E2_optAchse, plotOPD_E2_Parameter);
	mOPDQwtPlotSystem2->show();

	//check if the OPD plot is shown
	return mOPDQwtPlotSystem2->isVisible();
}

