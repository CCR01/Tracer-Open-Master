#include "Optikkreis.h"


// surfaces
#include "..\..\SurfaceElements\ApertureStopElement.h"
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\PlanElement.h"

// interactions
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"

// analyse
#include "..\..\Analyse\Spot.h"

// glasses
#include "..\..\Glasses\Glasses.h"

// plot spot diagram
#include "..\..\Plot\PlotQwt.h"
#include "..\..\Plot\PlotSpotDiagram.h"
#include "..\..\Plot\PlotOPD.h"
#include "..\..\Plot\PlotParameterQwt.h"

// fill aperture stop
#include "..\..\FillAptertureStop\FillApertureStop.h"



Optikkreis::Optikkreis(){}

Optikkreis::~Optikkreis(){}

bool Optikkreis::systemForOptikkreis()
{
	std::vector<bool> workOptSys;
	std::vector<SequentialRayTracing> seqTrace_vec;
	std::vector<Spot> spot_vec;

	glass glasses;
	glasses.loadGlassCatalog_Schott();
	DoNothingInteraction_LLT doNothong;
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interactionPtr;

	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	std::vector<Light_LLT> light_vec{ light };

	// **********************************
	// build the optical system
	ApertureStopElement AperStop0(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNBAF4_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3(/*radius*/ 40.0, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF4_S1());
	SphericalElement Sphere4(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF10_S1());
	SphericalElement Sphere5(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF10_S1());
	PlanElement Plan6(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	// **********************************

	// **********************************
	// set parameter variable
	Sphere1.setParameterRadius(/*min value*/ 7.0,  /*max value*/ 30.0, 0.0, typeModifierVariable); 
	Sphere4.setParameterRadius(/*min value*/ 12.0, /*max value*/ 70.0, 0.0, typeModifierVariable);
	// **********************************

	surfacePtr AperStop_ptr = AperStop0.clone();
	surfacePtr Sphere1_ptr = Sphere1.clone();
	surfacePtr Sphere2_ptr = Sphere2.clone();
	surfacePtr Sphere3_ptr = Sphere3.clone();
	surfacePtr Sphere4_ptr = Sphere4.clone();
	surfacePtr Sphere5_ptr = Sphere5.clone();
	surfacePtr Plan6_ptr = Plan6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ AperStop_ptr, Sphere1_ptr, Sphere2_ptr, Sphere3_ptr, Sphere4_ptr,Sphere5_ptr,Plan6_ptr };
	std::vector<interactionPtr> interactions_ptr{ doNothong.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
	optSystemElement.setRefractiveIndexAccordingToWavelength(550.0);
	
	bool checkTest = testTheSystem(optSystemElement);
	
	// plot the optical system
	plotStartSystemOK(optSystemElement, seqTrace_vec);

	// plot the spot diagrams
	plotSpotDiagramme_startSystem(spot_vec);
	// **********************************
	// optimize the system
	localStart localOp = radiusStart;
	real mutarionFactor = 0.01;
	unsigned int population = 500;

	OptimizeOpticalSystem optimizedOptSys(optSystemElement, population, mutarionFactor, localOp);
	// check all local combinations
	optimizedOptSys.setCheckAllLocalCombinations_optimizer(true);
	// set fields
	optimizedOptSys.add_FieldAndWeight({ 0.0,2.0,0.0 }, 1.0);
	optimizedOptSys.add_FieldAndWeight({ 0.0,4.0,0.0 }, 1.0);
	// set light
	optimizedOptSys.set_Light(light);
	// set target EFL to 20 mm
	optimizedOptSys.add_TargetEFL(20.0,1.0);
	//print basic definitions
	printBasics(optimizedOptSys);
	// start the optimization
	optimizedOptSys.optimizeSUPERFUNCTION();

	// get the optimized system
	OpticalSystemElement optimizedOpticalSystemEle = optimizedOptSys.getOptSysOptimized_Ele();
	OpticalSystem_LLT opticalSystem_LLT = optimizedOpticalSystemEle.getLLTconversion_doConversion();
	opticalSystem_LLT.printAllOptSysParameter_LLT(opticalSystem_LLT);
	// **********************************


	// plot the optimized system
	plotOptimizedSystemOK(optimizedOpticalSystemEle, seqTrace_vec);

	// plot spot diagrams optimized system
	plotSpotDiagramme_optimizedSystem(spot_vec);

	// calculate cardinal points
	CardinalPoints cardinalPoints(opticalSystem_LLT, objectPoint_inf_obj::obj);
	real EFL = cardinalPoints.getEFL();
	std::cout << "EFL" << EFL << "(target EFL 20)" << std::endl;
	

	bool returnCheck = Math::checkTrueOfVectorElements(workOptSys);
	return returnCheck;

}

bool Optikkreis::plotSpotDiagramme_startSystem(std::vector<Spot> spot_vec)
{
	std::vector<bool> workOptSys;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	Light_LLT light;
	light.setWavelength(550.0);
	DoNothingInteraction_LLT doNothing;


	ApertureStop_LLT S0(/*semiHeight*/ 2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveIndex*/ 1.0);
	SphericalSurface_LLT S1(/*radius*/40.0, /*semiHeight*/7.0, /*Apex of the sphere*/{ 0.0, 0.0, 25.0 }, /*Direction*/{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.52);
	SphericalSurface_LLT S2(/*radius*/40.0, /*semiHeight*/7.0, /*Apex of the sphere*/{ 0.0, 0.0, 35.0 }, /*Direction*/{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.61, /*refIndexSideB*/1.52);
	SphericalSurface_LLT S3(/*radius*/40.0, /*semiHeight*/7.0, /*Apex of the sphere*/{ 0.0, 0.0, 40.0 }, /*Direction*/{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.61);
	SphericalSurface_LLT S4(/*radius*/30.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 50.0 }, /*Direction*/{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.73);
	SphericalSurface_LLT S5(/*radius*/50.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 60.0 }, /*Direction*/{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.73);
	PlanGeometry_LLT S6(/*semiHeight*/7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	OpticalSystem_LLT optSys;
	optSys.fillVectorSurfaceAndInteractingData(0, S0.clone(), doNothing.clone());
	optSys.fillVectorSurfaceAndInteractingData(1, S1.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(2, S2.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(3, S3.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(4, S4.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(5, S5.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(6, S6.clone(), absorb.clone());

	// trace optical axis
	SequentialRayTracing seqTrace_optA(/*optical system element*/ optSys);
	FillApertureStop fillAperOptA(/*start point rays*/{ 0.0,0.0,0.0 },/*semi height of aperture stop*/ 2.0,/*point of aperture stop*/{ 0.0,0.0,20.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/ 6,/*arms*/ 8,/*refractive index*/ 1,/*light*/ light);
	seqTrace_optA.seqRayTracingWithVectorOfLightRays(fillAperOptA.getVectorWithLightRays());
	Spot spot_optA(seqTrace_optA.getAllInterPointsAtSurf_i_notFiltered(6), seqTrace_optA.getAllInterPointsAtSurf_i_notFiltered(6).at(0));
	real rms_optA = spot_optA.getRMS_µm();
	bool checkRMSoptA = Math::compareTwoNumbers_decimals(rms_optA, 1550.00, 2);
	workOptSys.push_back(checkRMSoptA);

	// trace field 1 -> y=2
	SequentialRayTracing seqTrace_y2(/*optical system element*/ optSys);
	FillApertureStop fillAper_y2(/*start point rays*/{ 0.0,2.0,0.0 },/*semi height of aperture stop*/ 2.0,/*point of aperture stop*/{ 0.0,0.0,20.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/ 6,/*arms*/ 8,/*refractive index*/ 1,/*light*/ light);
	seqTrace_y2.seqRayTracingWithVectorOfLightRays(fillAper_y2.getVectorWithLightRays());
	Spot spot_y2(seqTrace_y2.getAllInterPointsAtSurf_i_notFiltered(6), seqTrace_y2.getAllInterPointsAtSurf_i_notFiltered(6).at(0));
	real rms_y2 = spot_y2.getRMS_µm();
	bool checkRMS_y2 = Math::compareTwoNumbers_decimals(rms_y2, 1522.54, 2);
	workOptSys.push_back(checkRMS_y2);

	// trace field 2 -> y=4
	SequentialRayTracing seqTrace_y4(/*optical system element*/ optSys);
	FillApertureStop fillAper_y4(/*start point rays*/{ 0.0,4.0,0.0 },/*semi height of aperture stop*/ 2.0,/*point of aperture stop*/{ 0.0,0.0,20.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/ 6,/*arms*/ 8,/*refractive index*/ 1,/*light*/ light);
	seqTrace_y4.seqRayTracingWithVectorOfLightRays(fillAper_y4.getVectorWithLightRays());
	Spot spot_y4(seqTrace_y4.getAllInterPointsAtSurf_i_notFiltered(6), seqTrace_y4.getAllInterPointsAtSurf_i_notFiltered(6).at(0));
	real rms_y4 = spot_y4.getRMS_µm();
	bool checkRMS_y4 = Math::compareTwoNumbers_decimals(rms_y4, 1442.29, 2);
	workOptSys.push_back(checkRMS_y4);

	// plot the spot diagramms
	std::vector<Spot> vecSpot_optA{ spot_optA };
	PlotSpotDiagramm PlotSpot_optAchse(spot_optA.getRefPoint(), vecSpot_optA, 0.09950372, 550);
	std::vector<Spot> vecSpot_y2{ spot_y2 };
	PlotSpotDiagramm PlotSpot_y2(spot_y2.getRefPoint(), vecSpot_y2, 0.09950372, 550);
	std::vector<Spot> vecSpot_y4{ spot_y4 };
	PlotSpotDiagramm PlotSpot_y4(spot_y4.getRefPoint(), vecSpot_y4, 0.09950372, 550);

	//fill vectorSpotDiagram
	optSys.fillVectorSpotDiagramToPlot("Spot Diagram optical achse START", &PlotSpot_optAchse);
	optSys.fillVectorSpotDiagramToPlot("Spot Diagram field 1 START", &PlotSpot_y2);
	optSys.fillVectorSpotDiagramToPlot("Spot Diagram field 1 START", &PlotSpot_y4);

	// parameter to plot
	PlotParameterQwt ParameterPlotSpotDiagram;
	//-add comment at a given position
	ParameterPlotSpotDiagram.AddCommentToSpotDiagramPlot("Comment1_SpotDiagram", { 550,-150 });
	ParameterPlotSpotDiagram.AddCommentToSpotDiagramPlot("Comment2_SpotDiagram", { 550,-200 });
	ParameterPlotSpotDiagram.AddCommentToSpotDiagramPlot("Carsti ist der Beste!", { 550,-250 });

	//-change the attributes of the airy disc:
	//-----Airy disc color:
	ParameterPlotSpotDiagram.setAiryDiskColor(QColor("red"));
	//-----Airy disc thickness
	ParameterPlotSpotDiagram.setAiryDiskThickness(2);

	//-change the attributes of the points of the spot diagram
	//-----Style:Ellipse,Rect,Diamond,Triangle, DTriangle, UTriangle, LTriangle, Cross, HLine, Star1, Hexagon, ...
	ParameterPlotSpotDiagram.setSymbolStyleOfSpotDiagrammPoints(QwtSymbol::LTriangle);
	//-----Color of the inside of the symbol
	ParameterPlotSpotDiagram.setSymbolColorOfSpotDiagrammPoints(QBrush(Qt::yellow));
	//-----Color of the outline of the symbol
	ParameterPlotSpotDiagram.setContourColorSymbolOfSpotDiagrammPoints(QPen(Qt::black, 1));
	//-----Size:
	ParameterPlotSpotDiagram.setSizeSymbolOfSpotDiagrammPoints(QSize(4, 4));
	//-----Color of the grid
	ParameterPlotSpotDiagram.setFrameColorOfSpotDiagrammPoints(QPen(Qt::black, 1));

	//Plot spot diagram opt achse and field
	QwtPlot* spotDiagramQwtPlotSystem_start;
	spotDiagramQwtPlotSystem_start = new SpotPlotDiagramQwt(optSys, ParameterPlotSpotDiagram, 10, 40);
	spotDiagramQwtPlotSystem_start->show();
	bool chekerPLot = spotDiagramQwtPlotSystem_start->isVisible();
	workOptSys.push_back(chekerPLot);

	bool returnChecker = Math::checkTrueOfVectorElements(workOptSys);
	return returnChecker;
}

bool Optikkreis::plotStartSystemOK(OpticalSystemElement optSysEle, std::vector<SequentialRayTracing> seqTrace_vec)
{


	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	Light_LLT light;
	DoNothingInteraction_LLT doNothing;
	light.setWavelength(550.0);

	ApertureStop_LLT S0(/*semiHeight*/ 2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveIndex*/ 1.0);
	SphericalSurface_LLT S1(/*radius*/40.0, /*semiHeight*/7.0, /*Apex of the sphere*/{ 0.0, 0.0, 25.0 }, /*Direction*/ { 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.52);
	SphericalSurface_LLT S2(/*radius*/40.0, /*semiHeight*/7.0, /*Apex of the sphere*/{ 0.0, 0.0, 35.0 }, /*Direction*/ { 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.61, /*refIndexSideB*/1.52);
	SphericalSurface_LLT S3(/*radius*/40.0, /*semiHeight*/7.0, /*Apex of the sphere*/{ 0.0, 0.0, 40.0 }, /*Direction*/ { 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.61);
	SphericalSurface_LLT S4(/*radius*/30.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 50.0 }, /*Direction*/ { 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.73);
	SphericalSurface_LLT S5(/*radius*/50.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 60.0 }, /*Direction*/ { 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.73);
	PlanGeometry_LLT S6(/*semiHeight*/7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	
	OpticalSystem_LLT optSys;
	optSys.fillVectorSurfaceAndInteractingData(0, S0.clone(), doNothing.clone());
	optSys.fillVectorSurfaceAndInteractingData(1, S1.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(2, S2.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(3, S3.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(4, S4.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(5, S5.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(6, S6.clone(), absorb.clone());

	//to draw the aperturre stop two curves must be added to the table of surfaces to be ploted the upper part through getPointerPlotUp() and the other through getPointerPlotDown()
	//can be ploted using one curve when finding a method to plot a curve with gaps

	optSys.fillVectorToPlot2DQwt(0, S0.getPointerPlotUp());
	optSys.fillVectorToPlot2DQwt(1, S0.getPointerPlotDown());
	optSys.fillVectorToPlot2DQwt(2, S1.getPointerPlot());
	optSys.fillVectorToPlot2DQwt(3, S2.getPointerPlot());
	optSys.fillVectorToPlot2DQwt(4, S3.getPointerPlot());
	optSys.fillVectorToPlot2DQwt(5, S4.getPointerPlot());
	optSys.fillVectorToPlot2DQwt(6, S5.getPointerPlot());
	optSys.fillVectorToPlot2DQwt(7, S6.getPointerPlot());


	// ray tracing from the optical axis
	SequentialRayTracing SeqTrace_plot2D_optA(optSys);
	std::vector<LightRayStruct> lightRayAlong_Y_E3 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 7, 20.0, -2.0, 2.0, 550, 1.0);
	SeqTrace_plot2D_optA.seqRayTracingWithVectorOfLightRays(lightRayAlong_Y_E3);

	// ray tracing from the field y=2
	SequentialRayTracing SeqTrace_plot2D_y2(optSys);
	std::vector<LightRayStruct> lightRayAlong_Y2 = SequentialRayTracing::lightRayAlongY({ 0.0, 2.0, 0.0 }, 7, 20.0, -2.0, 2.0, 550, 1.0);
	SeqTrace_plot2D_y2.seqRayTracingWithVectorOfLightRays(lightRayAlong_Y2);

	// ray tracing from the field y=4
	SequentialRayTracing SeqTrace_plot2D_y4(optSys);
	std::vector<LightRayStruct> lightRayAlong_y4 = SequentialRayTracing::lightRayAlongY({ 0.0, 4.0, 0.0 }, 7, 20.0, -2.0, 2.0, 550, 1.0);
	SeqTrace_plot2D_y4.seqRayTracingWithVectorOfLightRays(lightRayAlong_y4);

	//fill vector Ray Tracing
	RayTracingSystem RayTracSys;
	RayTracSys.fillVectorRayTracing(&SeqTrace_plot2D_optA, { 0,0,255 });
	RayTracSys.fillVectorRayTracing(&SeqTrace_plot2D_y2, { 0,255,0 });
	RayTracSys.fillVectorRayTracing(&SeqTrace_plot2D_y4, { 255,0,0 });

	//change Plot Parameter 
	PlotParameterQwt ParameterPlotOptSysE0;
	//Add a comment to the plot
	ParameterPlotOptSysE0.AddCommentToRayTracingPlot("start system", { 80,200 });
	//change the colour of the surfaces
	ParameterPlotOptSysE0.setColorSurfaces({ 255,0,0 });
	//change the thickness of the surfaces
	ParameterPlotOptSysE0.setThicknessSurfaces(3);

	//// show surfaces with rays
	RayTracingQwtPlot* rayTracingQwtPlotSystem;
	rayTracingQwtPlotSystem = new RayTracingQwtPlot(optSys, RayTracSys, ParameterPlotOptSysE0);
	rayTracingQwtPlotSystem->show();
	bool checker = rayTracingQwtPlotSystem->isVisible();

	return checker;
}


bool Optikkreis::testTheSystem(OpticalSystemElement optSysEle)
{
	std::vector<bool> workOptSys;

	// light
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	std::vector<Light_LLT> light_vec{ light };

	// trace optical axis
	SequentialRayTracing seqTrace_optA(/*optical system element*/ optSysEle, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, light_vec);
	Spot spot_optA(seqTrace_optA.getAllInterPointsAtSurf_i_notFiltered(6), seqTrace_optA.getAllInterPointsAtSurf_i_notFiltered(6).at(0));
	real rms_optA = spot_optA.getRMS_µm();
	bool checkRMSoptA = Math::compareTwoNumbers_decimals(rms_optA, 1550.00, 2);
	workOptSys.push_back(checkRMSoptA);

	// trace field 1 -> y=2
	SequentialRayTracing seqTrace_y2(/*optical system element*/ optSysEle, /*start point lightRay*/{ 0.0,2.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, light_vec);
	Spot spot_y2(seqTrace_y2.getAllInterPointsAtSurf_i_notFiltered(6), seqTrace_y2.getAllInterPointsAtSurf_i_notFiltered(6).at(0));
	real rms_y2 = spot_y2.getRMS_µm();
	bool checkRMS_y2 = Math::compareTwoNumbers_decimals(rms_y2, 1522.54, 2);
	workOptSys.push_back(checkRMS_y2);

	// trace field 2 -> y=4
	SequentialRayTracing seqTrace_y4(/*optical system element*/ optSysEle, /*start point lightRay*/{ 0.0,4.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, light_vec);
	Spot spot_y4(seqTrace_y4.getAllInterPointsAtSurf_i_notFiltered(6), seqTrace_y4.getAllInterPointsAtSurf_i_notFiltered(6).at(0));
	real rms_y4 = spot_y4.getRMS_µm();
	bool checkRMS_y4 = Math::compareTwoNumbers_decimals(rms_y4, 1442.29, 2);
	workOptSys.push_back(checkRMS_y4);

	bool returnChecker = Math::checkTrueOfVectorElements(workOptSys);
	return returnChecker;
}


void Optikkreis::printBasics(OptimizeOpticalSystem optimizedOptSys)
{
	localStart localOp = optimizedOptSys.getLocalStart();
	std::string localSt;
	if (localOp == 0)
	{
		localSt = "radius";
	}
	if (localOp == 1)
	{
		localSt = "position";
	}

	real mutationFactos = optimizedOptSys.getMutationRate();
	real population = optimizedOptSys.getPopulation();
	bool checkAllLocalCom = optimizedOptSys.getOptimizeParameters().getCheckAllLocalComb();
	std::vector<VectorStructR3> field_vec = optimizedOptSys.getFieldAndLightConfig().getFieldVec();
	real wavelenght = optimizedOptSys.getFieldAndLightConfig().getLightVec()[0].getWavelength();
	real targetEFL = optimizedOptSys.getMeritConfig().getEFL_targetValue();
	real targetEXPD = optimizedOptSys.getMeritConfig().getEXPD_targetValue();

	std::cout << "local start: "<< localSt << std::endl;
	std::cout << "mutation factor: " << mutationFactos << std::endl;
	std::cout << "pupulation: " << population << std::endl;
	std::cout << "check all local combos: " << checkAllLocalCom << std::endl;
	std::cout << "field 0: X: " << field_vec[0].getX() << " Y: " << field_vec[0].getY() << " Z: " << field_vec[0].getZ() << std::endl;
	std::cout << "field 1: X: " << field_vec[1].getX() << " Y: " << field_vec[1].getY() << " Z: " << field_vec[1].getZ() << std::endl;
	std::cout << "field 2: X: " << field_vec[2].getX() << " Y: " << field_vec[2].getY() << " Z: " << field_vec[2].getZ() << std::endl;
	std::cout << "wavelength: " << wavelenght << " mm" << std::endl;
	std::cout << "target EFL: " << targetEFL << " mm" << std::endl;
	std::cout << "target EXPD: " << targetEXPD << " mm" << std::endl;
	
}


bool Optikkreis::plotOptimizedSystemOK(OpticalSystemElement optSysEle, std::vector<SequentialRayTracing> seqTrace_vec)
{
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	Light_LLT light;
	DoNothingInteraction_LLT doNothing;
	light.setWavelength(550.0);

	ApertureStop_LLT S0(/*semiHeight*/ 2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveIndex*/ 1.0);
	SphericalSurface_LLT S1(/*radius*/13.4637, /*semiHeight*/7.0, /*Apex of the sphere*/{ 0.0, 0.0, 25.0 }, /*Direction*/{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.52);
	SphericalSurface_LLT S2(/*radius*/40.0, /*semiHeight*/7.0, /*Apex of the sphere*/{ 0.0, 0.0, 35.0 }, /*Direction*/{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.61, /*refIndexSideB*/1.52);
	SphericalSurface_LLT S3(/*radius*/40.0, /*semiHeight*/7.0, /*Apex of the sphere*/{ 0.0, 0.0, 40.0 }, /*Direction*/{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.61);
	SphericalSurface_LLT S4(/*radius*/17.9998, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 50.0 }, /*Direction*/{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.73);
	SphericalSurface_LLT S5(/*radius*/50.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 60.0 }, /*Direction*/{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.73);
	PlanGeometry_LLT S6(/*semiHeight*/7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);

	OpticalSystem_LLT optSys;
	optSys.fillVectorSurfaceAndInteractingData(0, S0.clone(), doNothing.clone());
	optSys.fillVectorSurfaceAndInteractingData(1, S1.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(2, S2.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(3, S3.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(4, S4.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(5, S5.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(6, S6.clone(), absorb.clone());

	//to draw the aperturre stop two curves must be added to the table of surfaces to be ploted the upper part through getPointerPlotUp() and the other through getPointerPlotDown()
	//can be ploted using one curve when finding a method to plot a curve with gaps

	optSys.fillVectorToPlot2DQwt(0, S0.getPointerPlotUp());
	optSys.fillVectorToPlot2DQwt(1, S0.getPointerPlotDown());
	optSys.fillVectorToPlot2DQwt(2, S1.getPointerPlot());
	optSys.fillVectorToPlot2DQwt(3, S2.getPointerPlot());
	optSys.fillVectorToPlot2DQwt(4, S3.getPointerPlot());
	optSys.fillVectorToPlot2DQwt(5, S4.getPointerPlot());
	optSys.fillVectorToPlot2DQwt(6, S5.getPointerPlot());
	optSys.fillVectorToPlot2DQwt(7, S6.getPointerPlot());


	// ray tracing from the optical axis
	SequentialRayTracing SeqTrace_plot2D_optA(optSys);
	std::vector<LightRayStruct> lightRayAlong_Y_E3 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 7, 20.0, -2.0, 2.0, 550, 1.0);
	SeqTrace_plot2D_optA.seqRayTracingWithVectorOfLightRays(lightRayAlong_Y_E3);

	// ray tracing from the field y=2
	SequentialRayTracing SeqTrace_plot2D_y2(optSys);
	std::vector<LightRayStruct> lightRayAlong_Y2 = SequentialRayTracing::lightRayAlongY({ 0.0, 2.0, 0.0 }, 7, 20.0, -2.0, 2.0, 550, 1.0);
	SeqTrace_plot2D_y2.seqRayTracingWithVectorOfLightRays(lightRayAlong_Y2);

	// ray tracing from the field y=4
	SequentialRayTracing SeqTrace_plot2D_y4(optSys);
	std::vector<LightRayStruct> lightRayAlong_y4 = SequentialRayTracing::lightRayAlongY({ 0.0, 4.0, 0.0 }, 7, 20.0, -2.0, 2.0, 550, 1.0);
	SeqTrace_plot2D_y4.seqRayTracingWithVectorOfLightRays(lightRayAlong_y4);

	//fill vector Ray Tracing
	RayTracingSystem RayTracSys;
	RayTracSys.fillVectorRayTracing(&SeqTrace_plot2D_optA, { 0,0,255 });
	RayTracSys.fillVectorRayTracing(&SeqTrace_plot2D_y2, { 0,255,0 });
	RayTracSys.fillVectorRayTracing(&SeqTrace_plot2D_y4, { 255,0,0 });

	//change Plot Parameter 
	PlotParameterQwt ParameterPlotOptSysE0;
	//Add a comment to the plot
	ParameterPlotOptSysE0.AddCommentToRayTracingPlot("optimized system", { 80,200 });
	//change the colour of the surfaces
	ParameterPlotOptSysE0.setColorSurfaces({ 0,255,0 });
	//change the thickness of the surfaces
	ParameterPlotOptSysE0.setThicknessSurfaces(3);

	//// show surfaces with rays
	RayTracingQwtPlot* rayTracingQwtPlotSystem;
	rayTracingQwtPlotSystem = new RayTracingQwtPlot(optSys, RayTracSys, ParameterPlotOptSysE0);
	rayTracingQwtPlotSystem->show();
	bool checker = rayTracingQwtPlotSystem->isVisible();

	return checker;
}


bool Optikkreis::plotSpotDiagramme_optimizedSystem(std::vector<Spot> spot_vec)
{
	std::vector<bool> workOptSys;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	Light_LLT light;
	light.setWavelength(550.0);
	DoNothingInteraction_LLT doNothing;


	ApertureStop_LLT S0(/*semiHeight*/ 2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveIndex*/ 1.0);
	SphericalSurface_LLT S1(/*radius*/13.4637, /*semiHeight*/7.0, /*Apex of the sphere*/{ 0.0, 0.0, 25.0 }, /*Direction*/{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.52);
	SphericalSurface_LLT S2(/*radius*/40.0, /*semiHeight*/7.0, /*Apex of the sphere*/{ 0.0, 0.0, 35.0 }, /*Direction*/{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.61, /*refIndexSideB*/1.52);
	SphericalSurface_LLT S3(/*radius*/40.0, /*semiHeight*/7.0, /*Apex of the sphere*/{ 0.0, 0.0, 40.0 }, /*Direction*/{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.61);
	SphericalSurface_LLT S4(/*radius*/17.9998, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 50.0 }, /*Direction*/{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.73);
	SphericalSurface_LLT S5(/*radius*/50.0, /*semiHeight*/10.0, /*Apex of the sphere*/{ 0.0, 0.0, 60.0 }, /*Direction*/{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.73);
	PlanGeometry_LLT S6(/*semiHeight*/7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	
	OpticalSystem_LLT optSys;
	optSys.fillVectorSurfaceAndInteractingData(0, S0.clone(), doNothing.clone());
	optSys.fillVectorSurfaceAndInteractingData(1, S1.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(2, S2.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(3, S3.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(4, S4.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(5, S5.clone(), refrac.clone());
	optSys.fillVectorSurfaceAndInteractingData(6, S6.clone(), absorb.clone());

	// trace optical axis
	SequentialRayTracing seqTrace_optA(/*optical system element*/ optSys);
	FillApertureStop fillAperOptA(/*start point rays*/{ 0.0,0.0,0.0 },/*semi height of aperture stop*/ 2.0,/*point of aperture stop*/{ 0.0,0.0,20.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/ 6,/*arms*/ 8,/*refractive index*/ 1,/*light*/ light);
	seqTrace_optA.seqRayTracingWithVectorOfLightRays(fillAperOptA.getVectorWithLightRays());
	Spot spot_optA(seqTrace_optA.getAllInterPointsAtSurf_i_notFiltered(6), seqTrace_optA.getAllInterPointsAtSurf_i_notFiltered(6).at(0));
	real rms_optA = spot_optA.getRMS_µm();
	bool checkRMSoptA = Math::compareTwoNumbers_decimals(rms_optA, 1550.00, 2);
	workOptSys.push_back(checkRMSoptA);

	// trace field 1 -> y=2
	SequentialRayTracing seqTrace_y2(/*optical system element*/ optSys);
	FillApertureStop fillAper_y2(/*start point rays*/{ 0.0,2.0,0.0 },/*semi height of aperture stop*/ 2.0,/*point of aperture stop*/{ 0.0,0.0,20.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/ 6,/*arms*/ 8,/*refractive index*/ 1,/*light*/ light);
	seqTrace_y2.seqRayTracingWithVectorOfLightRays(fillAper_y2.getVectorWithLightRays());
	Spot spot_y2(seqTrace_y2.getAllInterPointsAtSurf_i_notFiltered(6), seqTrace_y2.getAllInterPointsAtSurf_i_notFiltered(6).at(0));
	real rms_y2 = spot_y2.getRMS_µm();
	bool checkRMS_y2 = Math::compareTwoNumbers_decimals(rms_y2, 1522.54, 2);
	workOptSys.push_back(checkRMS_y2);

	// trace field 2 -> y=4
	SequentialRayTracing seqTrace_y4(/*optical system element*/ optSys);
	FillApertureStop fillAper_y4(/*start point rays*/{ 0.0,4.0,0.0 },/*semi height of aperture stop*/ 2.0,/*point of aperture stop*/{ 0.0,0.0,20.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/ 6,/*arms*/ 8,/*refractive index*/ 1,/*light*/ light);
	seqTrace_y4.seqRayTracingWithVectorOfLightRays(fillAper_y4.getVectorWithLightRays());
	Spot spot_y4(seqTrace_y4.getAllInterPointsAtSurf_i_notFiltered(6), seqTrace_y4.getAllInterPointsAtSurf_i_notFiltered(6).at(0));
	real rms_y4 = spot_y4.getRMS_µm();
	bool checkRMS_y4 = Math::compareTwoNumbers_decimals(rms_y4, 1442.29, 2);
	workOptSys.push_back(checkRMS_y4);

	// plot the spot diagramms
	std::vector<Spot> vecSpot_optA{ spot_optA };
	PlotSpotDiagramm PlotSpot_optAchse(spot_optA.getRefPoint(), vecSpot_optA, 0.09950372, 550);
	std::vector<Spot> vecSpot_y2{ spot_y2 };
	PlotSpotDiagramm PlotSpot_y2(spot_y2.getRefPoint(), vecSpot_y2, 0.09950372, 550);
	std::vector<Spot> vecSpot_y4{ spot_y4 };
	PlotSpotDiagramm PlotSpot_y4(spot_y4.getRefPoint(), vecSpot_y4, 0.09950372, 550);

	//fill vectorSpotDiagram
	optSys.fillVectorSpotDiagramToPlot("Spot Diagram optical achse OPTIMIZED", &PlotSpot_optAchse);
	optSys.fillVectorSpotDiagramToPlot("Spot Diagram field 1 OPTIMIZED", &PlotSpot_y2);
	optSys.fillVectorSpotDiagramToPlot("Spot Diagram field 1 OPTIMIZED", &PlotSpot_y4);

	// parameter to plot
	PlotParameterQwt ParameterPlotSpotDiagram;
	//-add comment at a given position
	ParameterPlotSpotDiagram.AddCommentToSpotDiagramPlot("Comment1_SpotDiagram", { 550,-150 });
	ParameterPlotSpotDiagram.AddCommentToSpotDiagramPlot("Comment2_SpotDiagram", { 550,-200 });
	ParameterPlotSpotDiagram.AddCommentToSpotDiagramPlot("Carsti ist der Beste!", { 550,-250 });

	//-change the attributes of the airy disc:
	//-----Airy disc color:
	ParameterPlotSpotDiagram.setAiryDiskColor(QColor("red"));
	//-----Airy disc thickness
	ParameterPlotSpotDiagram.setAiryDiskThickness(2);

	//-change the attributes of the points of the spot diagram
	//-----Style:Ellipse,Rect,Diamond,Triangle, DTriangle, UTriangle, LTriangle, Cross, HLine, Star1, Hexagon, ...
	ParameterPlotSpotDiagram.setSymbolStyleOfSpotDiagrammPoints(QwtSymbol::Cross);
	//-----Color of the inside of the symbol
	ParameterPlotSpotDiagram.setSymbolColorOfSpotDiagrammPoints(QBrush(Qt::blue));
	//-----Color of the outline of the symbol
	ParameterPlotSpotDiagram.setContourColorSymbolOfSpotDiagrammPoints(QPen(Qt::red, 1));
	//-----Size:
	ParameterPlotSpotDiagram.setSizeSymbolOfSpotDiagrammPoints(QSize(4, 4));
	//-----Color of the grid
	ParameterPlotSpotDiagram.setFrameColorOfSpotDiagrammPoints(QPen(Qt::black, 2));

	//Plot spot diagram opt achse and field
	QwtPlot* spotDiagramQwtPlotSystem_start;
	spotDiagramQwtPlotSystem_start = new SpotPlotDiagramQwt(optSys, ParameterPlotSpotDiagram, 10, 40);
	spotDiagramQwtPlotSystem_start->show();
	bool chekerPLot = spotDiagramQwtPlotSystem_start->isVisible();
	workOptSys.push_back(chekerPLot);

	bool returnChecker = Math::checkTrueOfVectorElements(workOptSys);
	return returnChecker;
}
