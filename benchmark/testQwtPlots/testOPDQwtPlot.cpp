#include "TestOPDQwtPlot.h"


// glasses
#include "..\..\Glasses\Glasses.h"

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
#include "..\..\SurfaceElements\ApertureStopElement.h"
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\PlanElement.h"

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
	//bool testE1 = testOPDQwtPlotE1(); // do it -> tut noch nicht richtig !!!!!
	//checkOPDPlot.push_back(testE1);
	//bool testE2 = true;// testOPDQwtPlotE2();
	//checkOPDPlot.push_back(testE2);
	//bool testE3 = testOPDQwtPlotE3();
	//checkOPDPlot.push_back(testE3);

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
	optSysE0.fillVectorSurfaceAndInteractingData(0, S0E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(1, S1E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(2, S2E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(3, S3E0.clone(), deflectCR3.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(4, S4E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(5, S5E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(6, S6E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(7, S7E0.clone(), refrac.clone());
	optSysE0.fillVectorSurfaceAndInteractingData(8, S8E0.clone(), absorb.clone());

	// Plot OPD opt achse
	Ray_LLT chiefRayE0_optAchse({ 0.0,0.0,0.0 }, { 0.0,0.0,1.0 }, 1.0);
	LightRayStruct chiefLightRayE0_optAchse(light, chiefRayE0_optAchse, 1);
	Ray_LLT chiefRayE0_field({ 0.0,0.5,0.0 }, { 0.0,0.5,10.0 }, 1.0);
	LightRayStruct chiefLightRayE0_field(light, chiefRayE0_field, 1);
	PlanGeometry_LLT exitPupilE0(/*semiHeight*/20.0, /*point*/{ 0.0,0.0,2.5696182 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	std::vector<LightRayStruct> lightRayAlong_X_E0_optAchse2 = SequentialRayTracing::lightRayAlongX({ 0.0, 0.0, 0.0 }, 100, 10.0, -1.0, 1.0, 550, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_E0_optAchse2 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 100, 10.0, -1.0, 1.0, 550, 1.0);
	OPD OPD_E0_optAchse2(exitPupilE0.clone(), optSysE0, lightRayAlong_X_E0_optAchse2, lightRayAlong_Y_E0_optAchse2, chiefLightRayE0_optAchse);
	PlotOPD plotOPD_E0_optAchse(OPD_E0_optAchse2);

	Light_LLT light_1;
	light_1.setWavelength(450.0);

	Ray_LLT chiefRayE0_optAchse_1({ 0.0,0.0,0.0 }, { 0.0,0.0,1.0 }, 1.0);
	LightRayStruct chiefLightRayE0_optAchse_1(light_1, chiefRayE0_optAchse_1, 1);
	std::vector<LightRayStruct> lightRayAlong_X_E0_optAchse_1 = SequentialRayTracing::lightRayAlongX({ 0.0, 0.0, 0.0 }, 100, 10.0, -1.0, 1.0, 450, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_E0_optAchse_1 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 100, 10.0, -1.0, 1.0, 450, 1.0);
	OPD OPD_E0_optAchse_1(exitPupilE0.clone(), optSysE0, lightRayAlong_X_E0_optAchse_1, lightRayAlong_Y_E0_optAchse_1, chiefLightRayE0_optAchse_1);
	PlotOPD plotOPD_E0_optAchse_1(OPD_E0_optAchse_1);


	///load the parameters of the OPD plot
	PlotParameterQwt plotOPD_E0_Parameter;
	//change the style of the symbols
	plotOPD_E0_Parameter.setOPDSymbolStyle(QwtSymbol::Diamond, 1);
	//change the size of the symbols
	plotOPD_E0_Parameter.setOPDSizeSymbol(QSize(4, 3));
	//change the colour of the symbols
	plotOPD_E0_Parameter.setOPDSymbolColor(QBrush(Qt::red), 1);
	//change the contour colour of the symbols
	plotOPD_E0_Parameter.setOPDContourColorSymbol(QPen(Qt::red, 1), 1);
	//add a comment to the OPD plot at a given position
	plotOPD_E0_Parameter.AddCommentToOPDPlot("Comment_OPD_Plot", { -5,-200 });
	//change the colour of the frame of the plots
	plotOPD_E0_Parameter.setOPDFrameColor(QColor("lightblue"));

	OpticalSystemCurves systemPlotsE0;
	systemPlotsE0.giveNumberWavelengthsOPD(1);
	systemPlotsE0.fillVectorplotOPDDiagramToPlot(&plotOPD_E0_optAchse, 1);


	//OPD plot
	mOPDQwtPlotSystem0 = new PlotOPDQwt(systemPlotsE0, plotOPD_E0_Parameter);
	mOPDQwtPlotSystem0->show();

	//check if the OPD plot is shown
	return mOPDQwtPlotSystem0->isVisible();
}


//OPD plot SystemE1
bool testOPDQwtPlot::testOPDQwtPlotE1()
{
	RefractedRay_LLT refrac;
	DoNothingInteraction_LLT doNothing;
	typedef std::shared_ptr< SurfaceIntersectionRay_LLT > surfacePtr_LLT;

	// surfaces of the optical system
	ApertureStop_LLT ApertureStop0E1(1.0, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT S0E1(/*radius*/15.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 40.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S1E1(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 45.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT PlanE3(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	//
	OpticalSystem_LLT optSysE1;
	optSysE1.fillVectorSurfaceAndInteractingData(0, ApertureStop0E1.clone(), doNothing.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(1, S0E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(2, S1E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(3, PlanE3.clone(), refrac.clone());

	PlanGeometry_LLT exitPupilE1(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,74.230762215072 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	surfacePtr_LLT exitPupilE1_ptr = exitPupilE1.clone();

	// OPD on optical axis
	std::vector<LightRayStruct> lightRayAlong_X_optA_E1 = SequentialRayTracing::lightRayAlongX({ 0.0, 0.0, 0.0 }, 100, 20.0, -1.0, 1.0, 550, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_optA_E1 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 100, 20.0, -1.0, 1.0, 550, 1.0);

	Ray_LLT chiefRayOptA_E1({ 0.0,0.0,0.0 }, { 0.0,0.0,1.0 }, 1.0);
	Light_LLT Light550;
	Light550.setWavelength(550);
	LightRayStruct chiefLightRayOptA_E1(Light550, chiefRayOptA_E1, 1);

	OPD OPD1OptA(exitPupilE1_ptr, optSysE1, lightRayAlong_X_optA_E1, lightRayAlong_Y_optA_E1, chiefLightRayOptA_E1);
	PlotOPD plotOPD_E1_optA(OPD1OptA);

	std::vector<LightRayStruct> lightRayAlong_X_Field_E1 = SequentialRayTracing::lightRayAlongX({ 0.0, 0.05, 0.0 }, 100, 20.0, -1.0, 1.0, 550, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_Field_E1 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.05, 0.0 }, 100, 20.0, -1.0, 1.0, 550, 1.0);

	Ray_LLT chiefRayField_E1({ 0.0,0.1,0.0 }, { 0.0,0.0,1.0 }, 1.0);
	LightRayStruct chiefLightRayField_E1(Light550, chiefRayField_E1, 1);

	OPD OPD1Field(exitPupilE1_ptr, optSysE1, lightRayAlong_X_Field_E1, lightRayAlong_Y_Field_E1, chiefLightRayField_E1);
	PlotOPD plotOPD_E1_Field(OPD1Field);

	std::vector<LightRayStruct> lightRayAlong_X_Field1_E1 = SequentialRayTracing::lightRayAlongX({ 0.0, -0.05, 0.0 }, 100, 20.0, -1.0, 1.0, 550, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_Field1_E1 = SequentialRayTracing::lightRayAlongY({ 0.0, -0.05, 0.0 }, 100, 20.0, -1.0, 1.0, 550, 1.0);

	Ray_LLT chiefRayField1_E1({ 0.0,-0.1,0.0 }, { 0.0,0.0,1.0 }, 1.0);
	LightRayStruct chiefLightRayField1_E1(Light550, chiefRayField1_E1, 1);

	OPD OPD1Field1(exitPupilE1_ptr, optSysE1, lightRayAlong_X_Field1_E1, lightRayAlong_Y_Field1_E1, chiefLightRayField1_E1);
	PlotOPD plotOPD_E1_Field1(OPD1Field1);

	//initiate the parameter of the OPD plot
	PlotParameterQwt plotOPD_E1_Parameter;
	OpticalSystemCurves systemPlotsE1;
	systemPlotsE1.giveNumberWavelengthsOPD(1);
	systemPlotsE1.fillVectorplotOPDDiagramToPlot(&plotOPD_E1_optA, 1);
	systemPlotsE1.fillVectorplotOPDDiagramToPlot(&plotOPD_E1_Field, 1);
	systemPlotsE1.fillVectorplotOPDDiagramToPlot(&plotOPD_E1_Field1, 1);

	//Plot the OPD plot
	mOPDQwtPlotSystem1 = new PlotOPDQwt(systemPlotsE1, plotOPD_E1_Parameter);
	mOPDQwtPlotSystem1->show();
	//check if the OPD plot is shown
	return mOPDQwtPlotSystem1->isVisible();
}


//OPD plot SystemE2
bool testOPDQwtPlot::testOPDQwtPlotE2()
{
	//glass catalog
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	//types definition
	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interactionPtr;

	//interactions
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;

	Light_LLT light;
	light.setWavelength(550.0);

	DoNothingInteraction_LLT doNothing;


	ApertureStopElement ApertureStop0E2(2.0, { 0.0,0.0,5.0 }, { 0.0,0.0,1.0 }, glasses.getAir());
	SphericalElement S0E2(/*radius*/20.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 13 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/glasses.getAir(), /*refIndexSideB*/glasses.getNBK7_S1());
	SphericalElement S1E2(/*radius*/20.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 18 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/glasses.getAir(), /*refIndexSideB*/glasses.getNBK7_S1());
	SphericalElement S2E2(/*radius*/30.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 21 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/glasses.getNBK7_S1(), /*refIndexSideB*/glasses.getAir());
	SphericalElement S3E2(/*radius*/60.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 26 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/glasses.getNBK7_S1(), /*refIndexSideB*/glasses.getAir());
	PlanElement ImageE2(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,31.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ glasses.getAir(), /*refractiveSideB*/ glasses.getAir());

	//*************
	// build the optical system
	surfacePtr Aperture0_ptr = ApertureStop0E2.clone();
	surfacePtr Sphere0_ptr = S0E2.clone();
	surfacePtr Sphere1_ptr = S1E2.clone();
	surfacePtr Sphere2_ptr = S2E2.clone();
	surfacePtr Sphere3_ptr = S3E2.clone();
	surfacePtr Plan0_ptr = ImageE2.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ Aperture0_ptr, Sphere0_ptr, Sphere1_ptr, Sphere2_ptr, Sphere3_ptr, Plan0_ptr };
	std::vector<interactionPtr> interactions_ptr{ doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };
	OpticalSystem_LLT OptSysE2;

	//*System definition
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(550);
	OptSysE2 = optSystemElement.getOpticalSystem_LLT();

	//**********************************************************************************************
	//// calculate OPD with start point on optical axis
	std::vector<LightRayStruct> lightRayAlong_X_Field = SequentialRayTracing::lightRayAlongX({ 0.0, 0.0, 0.0 }, 100, 5.0, -2.0, 2.0, 550, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_Field = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 100, 5.0, -2.0, 2.0, 550, 1.0);
	Ray_LLT chiefRayField({ 0.0,0.0,0.0 }, { 0.0,2.0,0.0 }, 1.0);
	LightRayStruct chiefLightRayField(light, chiefRayField, 1);
	PlanGeometry_LLT exitPupil1(/*semiHeight*/4.0, /*point*/{ 0.0,0.0,22.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	OPD OPDoptField(exitPupil1.clone(), OptSysE2, lightRayAlong_X_Field, lightRayAlong_Y_Field, chiefLightRayField);
	PlotOPD plotOPD_E2_Field(OPDoptField);
	//PlotOPD plotOPD_E2_Field(ApertureStop0E2.clone(), exitPupil1, );
	//initiate the parameter of the OPD plot
	PlotParameterQwt plotOPD_E2_Parameter;
	OpticalSystemCurves SystemPlotsE2;
	SystemPlotsE2.giveNumberWavelengthsOPD(1);
	SystemPlotsE2.fillVectorplotOPDDiagramToPlot(&plotOPD_E2_Field, 1);
	//Plot the OPD plot
	mOPDQwtPlotSystem2 = new PlotOPDQwt(SystemPlotsE2, plotOPD_E2_Parameter);
	mOPDQwtPlotSystem2->show();

	//check if the OPD plot is shown
	return mOPDQwtPlotSystem2->isVisible();
}


//OPD plot SystemE1
bool testOPDQwtPlot::testOPDQwtPlotE3()
{

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interactionPtr;


	RefractedRay_LLT refrac;
	DoNothingInteraction_LLT doNothing;
	typedef std::shared_ptr< SurfaceIntersectionRay_LLT > surfacePtr_LLT;

	// surfaces of the optical system
	ApertureStopElement ApertureStop0E3(1.0, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, glasses.getAir());
	SphericalElement S0E3(/*radius*/15.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 40.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/glasses.getAir(), /*refIndexSideB*/glasses.getNBK7_S1());
	SphericalElement S1E3(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 45.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/glasses.getAir(), /*refIndexSideB*/glasses.getNBK7_S1());
	PlanElement PlanE3(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ glasses.getAir(), /*refractiveSideB*/ glasses.getAir());
	//
	OpticalSystem_LLT optSysE3;
	surfacePtr Aperture0_ptr = ApertureStop0E3.clone();
	surfacePtr Sphere0_ptr = S0E3.clone();
	surfacePtr Sphere1_ptr = S1E3.clone();
	surfacePtr Plan0_ptr = PlanE3.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ Aperture0_ptr, Sphere0_ptr, Sphere1_ptr, Plan0_ptr };
	std::vector<interactionPtr> interactions_ptr{ doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone() };

	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);


	PlanGeometry_LLT exitPupilE3(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,74.230762215072 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	surfacePtr_LLT exitPupilE3_ptr = exitPupilE3.clone();

	PlotOPD plotOPD_E3_optA(ApertureStop0E3.getSurfaceForLLT_ptr(), exitPupilE3_ptr, optSystemElement, { 0.0, 0.0, 0.0 }, 550, 100);
	PlotOPD plotOPD_E3_optA_1(ApertureStop0E3.getSurfaceForLLT_ptr(), exitPupilE3_ptr, optSystemElement, { 0.0, 0.0, 0.0 }, 450, 100);



	//initiate the parameter of the OPD plot
	PlotParameterQwt plotOPD_E3_Parameter;
	OpticalSystemCurves systemPlotsE3;
	systemPlotsE3.giveNumberWavelengthsOPD(2);
	systemPlotsE3.fillVectorplotOPDDiagramToPlot(&plotOPD_E3_optA, 1);
	systemPlotsE3.fillVectorplotOPDDiagramToPlot(&plotOPD_E3_optA_1, 2);


	//Plot the OPD plot
	mOPDQwtPlotSystem3 = new PlotOPDQwt(systemPlotsE3, plotOPD_E3_Parameter);
	mOPDQwtPlotSystem3->show();
	//check if the OPD plot is shown
	return mOPDQwtPlotSystem3->isVisible();
}
