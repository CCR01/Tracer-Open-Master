#include "TOM(Logo).h"

// Surfaces
#include "..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"
#include "..\LowLevelTracing\Surfaces\ParaxialLens_LLT.h"
#include "..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"

// Interaction
#include "..\LowLevelTracing\Interaction\DeflectedRayParaxialLens_LLT.h"
#include "..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\LowLevelTracing\Interaction\ReflectionRay_LLT.h"

// Optical syetem
#include "..\LowLevelTracing\OpticalSystem_LLT.h"

// math
#include "..\LowLevelTracing\Math_LLT.h"

//QwtPlot
#include "..\Plot\PlotQwt.h"

TOM_LOGO::TOM_LOGO() {}
TOM_LOGO::~TOM_LOGO() {}

bool TOM_LOGO::plotTOM_Logo()
{
	typedef std::shared_ptr<SurfaceIntersectionRay_LLT> surfaceLLT_ptr;
	typedef std::shared_ptr<InteractionRay_LLT> interactionLLT_ptr;

	std::vector<bool> checkPlotTOM;

	// interactions
	DoNothingInteraction_LLT doNothing;
	Absorb_LLT absorb;
	ReflectionRay_LLT reflect;

	ApertureStop_LLT A0(/*semi height*/ 8.0, /*point*/{ 0.0,0.0,5.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index*/ 1.0);
	ParaxialLens_LLT P1(/*semi height*/ 10.5, /*point*/{ 0.0,0.0,6.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*focal length*/ 6.0, /*refractive index A*/ 1.0, /*refractive index B*/ 1.0);
	PlanGeometry_LLT M2(/*semi height*/ 10.5, /*point*/{ 0.0,0.0,106.0 },/*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/1.0, /*refractive index B*/ 1.0);
	PlanGeometry_LLT M3(/*semi height*/ 14.5, /*point*/{ 0.0,0.0,56.0 },/*direction*/{ 0.0,-1.0,1.0 }, /*refractive index A*/1.0, /*refractive index B*/ 1.0);
	PlanGeometry_LLT M4(/*semi height*/ 10.5, /*point*/{ 0.0,-110.0,56.0 },/*direction*/{ 0.0,1.0,0.0 }, /*refractive index A*/1.0, /*refractive index B*/ 1.0);
	PlanGeometry_LLT M5(/*semi height*/ 15.0, /*point*/{ 0.0,0.0,56.0 },/*direction*/{ 0.0,-1.0,1.0 }, /*refractive index A*/1.0, /*refractive index B*/ 1.0);
	ParaxialLens_LLT P6(/*semi height*/ 10.5, /*point*/{ 0.0,0.0,106.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*focal length*/ 10.0, /*refractive index A*/ 1.0, /*refractive index B*/ 1.0);
	ParaxialLens_LLT P7(/*semi height*/ 10.5, /*point*/{ 0.0,0.0,126.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*focal length*/ 10.0, /*refractive index A*/ 1.0, /*refractive index B*/ 1.0);
	PlanGeometry_LLT M8(/*semi height*/ 15.0, /*point*/{ 0.0,0.0,226.0 },/*direction*/{ 0.0,-1.0,-1.0 }, /*refractive index A*/1.0, /*refractive index B*/ 1.0);
	PlanGeometry_LLT M9(/*semi height*/ 16.0, /*point*/{ 0.0,-100.0,226.0 },/*direction*/{ 0.0,1.0,-1.0 }, /*refractive index A*/1.0, /*refractive index B*/ 1.0);
	PlanGeometry_LLT M10(/*semi height*/ 16.0, /*point*/{ 0.0,-100.0,126.0 },/*direction*/{ 0.0,1.0,1.0 }, /*refractive index A*/1.0, /*refractive index B*/ 1.0);
	PlanGeometry_LLT M11(/*semi height*/ 16.0, /*point*/{ 0.0,0.0,126.0 },/*direction*/{ 0.0,-1.0,1.0 }, /*refractive index A*/1.0, /*refractive index B*/ 1.0);
	ParaxialLens_LLT P12(/*semi height*/ 11.5, /*point*/{ 0.0,0.0,236.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*focal length*/ 10.0, /*refractive index A*/ 1.0, /*refractive index B*/ 1.0);
	ParaxialLens_LLT P13(/*semi height*/ 11.5, /*point*/{ 0.0,0.0,256.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*focal length*/ 10.0, /*refractive index A*/ 1.0, /*refractive index B*/ 1.0);
	PlanGeometry_LLT M14(/*semi height*/ 16.0, /*point*/{ 0.0,0.0,267.5 },/*direction*/{ 0.0,-1.0,-1.0 }, /*refractive index A*/1.0, /*refractive index B*/ 1.0);
	PlanGeometry_LLT M15(/*semi height*/ 12.0, /*point*/{ 0.0,-110.0,267.5 },/*direction*/{ 0.0,1.0,0.0 }, /*refractive index A*/1.0, /*refractive index B*/ 1.0);
	PlanGeometry_LLT M16(/*semi height*/ 13.0, /*point*/{ 0.0,5.0,267.5 },/*direction*/{ 0.0,-2.144506921,1.0 }, /*refractive index A*/1.0, /*refractive index B*/ 1.0);
	PlanGeometry_LLT M17(/*semi height*/ 20.0, /*point*/{ 0.0,-33.5672566,313.462667 },/*direction*/{ 0.0,1.0,0.0 }, /*refractive index A*/1.0, /*refractive index B*/ 1.0);
	PlanGeometry_LLT M18(/*semi height*/ 14.0, /*point*/{ 0.0,5.0,359.425333 },/*direction*/{ 0.0,-2.144506921,-1.0 }, /*refractive index A*/1.0, /*refractive index B*/ 1.0);
	PlanGeometry_LLT M19(/*semi height*/ 13.0, /*point*/{ 0.0,-110.0,359.425333 },/*direction*/{ 0.0,1.0,0.0 }, /*refractive index A*/1.0, /*refractive index B*/ 1.0);

	// additional information for paraxial ray tracing
	DeflectedRayParaxialLens_LLT deflectRay_P1(P1.getInfosForDefelction());
	DeflectedRayParaxialLens_LLT deflectRay_P6(P6.getInfosForDefelction());
	DeflectedRayParaxialLens_LLT deflectRay_P7(P7.getInfosForDefelction());
	DeflectedRayParaxialLens_LLT deflectRay_P12(P12.getInfosForDefelction());
	DeflectedRayParaxialLens_LLT deflectRay_P13(P13.getInfosForDefelction());


	// vector with surfaces
	std::vector<surfaceLLT_ptr> surfaces_vec{ A0.clone(),P1.clone(),M2.clone(),M3.clone(),M4.clone(),M5.clone(),P6.clone(),P7.clone(),M8.clone(),M9.clone(),
		M10.clone(),M11.clone(),P12.clone(),P13.clone(),M14.clone(),M15.clone(),M16.clone(),M17.clone(),M18.clone(),M19.clone() };
	// vector with interactions
	std::vector<interactionLLT_ptr> interaction_vec{/*0*/ doNothing.clone(),/*1*/deflectRay_P1.clone(),/*2*/reflect.clone(),/*3*/reflect.clone(),/*4*/reflect.clone(),/*5*/reflect.clone(),/*6*/deflectRay_P6.clone(),/*7*/deflectRay_P7.clone(),
		/*8*/reflect.clone(),/*9*/reflect.clone(),/*10*/reflect.clone(),/*11*/reflect.clone(),/*12*/deflectRay_P12.clone(),/*13*/deflectRay_P13.clone(),/*14*/reflect.clone(),/*15*/reflect.clone(),/*16*/reflect.clone(),/*17*/reflect.clone(),/*18*/reflect.clone(),/*19*/absorb.clone() };

	// optical system LLT
	OpticalSystem_LLT optSysTOM_LLT(surfaces_vec, interaction_vec);

	// check by single ray trace
	JonesVector_LLT polarisation;
	typeLight lightType = typeLight::typeLightRay;
	Light_LLT light(/*wavelength*/ 550.0, /*intensity*/ 1.0,/*polarisation*/ polarisation,/*light type*/ lightType);


	// *** *** // sequential ray tracing
	// optical axis
	Ray_LLT ray_optA(/*origin*/{ 0.0,0.0,0.0 },/*direction*/{ 0.0,0.0,1.0 },/*refractive index*/ 1.0);
	LightRayStruct lightRay_optA(light, ray_optA, 1);
	SequentialRayTracing seqTrace_optA(optSysTOM_LLT);
	seqTrace_optA.sequentialRayTracing(lightRay_optA);
	VectorStructR3 rayOptA_Zemax_optA = { 0.0,-110.0,359.42533317 };
	VectorStructR3 rayOptA_TOM_optA = seqTrace_optA.getAllInterPointsAtSurface_i_filtered(19)[0];
	bool checkRayOptA = Math::compareTwoVectorStructR3_decimals(rayOptA_Zemax_optA, rayOptA_TOM_optA, 3);
	checkPlotTOM.push_back(checkRayOptA);

	// field y=0.01
	Ray_LLT ray_field1(/*origin*/{ 0.0,0.01,0.0 },/*direction*/{ 0.0,-8.01,5.0 },/*refractive index*/ 1.0);
	LightRayStruct lightRay_field1(light, ray_field1, 1);
	SequentialRayTracing seqTrace_field1(optSysTOM_LLT);
	seqTrace_field1.sequentialRayTracing(lightRay_field1);
	VectorStructR3 rayOptA_Zemax_field1 = { 0.0,-110.0,371.29649984 };
	VectorStructR3 rayOptA_TOM_field1 = seqTrace_field1.getAllInterPointsAtSurface_i_filtered(19)[0];
	bool checkRayField1 = Math::compareTwoVectorStructR3_decimals(rayOptA_Zemax_field1, rayOptA_TOM_field1, 3);
	checkPlotTOM.push_back(checkRayField1);

	// field y=-0.01
	Ray_LLT ray_field2(/*origin*/{ 0.0,-0.01,0.0 },/*direction*/{ 0.0,8.01,5.0 },/*refractive index*/ 1.0);
	LightRayStruct lightRay_field2(light, ray_field2, 1);
	SequentialRayTracing seqTrace_field2(optSysTOM_LLT);
	seqTrace_field2.sequentialRayTracing(lightRay_field2);
	VectorStructR3 rayOptA_Zemax_field2 = { 0.0,-110.0,347.55416651 };
	VectorStructR3 rayOptA_TOM_field2 = seqTrace_field2.getAllInterPointsAtSurface_i_filtered(19)[0];
	bool checkRayfield2 = Math::compareTwoVectorStructR3_decimals(rayOptA_Zemax_field2, rayOptA_TOM_field2, 3);
	checkPlotTOM.push_back(checkRayfield2);
	// *** *** //

	// plot the system
	// build optical system
	OpticalSystemCurves optSysTOMPlots;
	optSysTOMPlots.fillVectorRayTracSurfaces(A0.getPointerPlotUp());
	optSysTOMPlots.fillVectorRayTracSurfaces(A0.getPointerPlotDown());
	optSysTOMPlots.fillVectorRayTracSurfaces(P1.getPointerPlot());
	optSysTOMPlots.fillVectorRayTracSurfaces(M2.getPointerPlot());
	optSysTOMPlots.fillVectorRayTracSurfaces(M3.getPointerPlot());
	optSysTOMPlots.fillVectorRayTracSurfaces(M4.getPointerPlot());
	optSysTOMPlots.fillVectorRayTracSurfaces(M5.getPointerPlot());
	optSysTOMPlots.fillVectorRayTracSurfaces(P6.getPointerPlot());
	optSysTOMPlots.fillVectorRayTracSurfaces(P7.getPointerPlot());
	optSysTOMPlots.fillVectorRayTracSurfaces(M8.getPointerPlot());
	optSysTOMPlots.fillVectorRayTracSurfaces(M9.getPointerPlot());
	optSysTOMPlots.fillVectorRayTracSurfaces(M10.getPointerPlot());
	optSysTOMPlots.fillVectorRayTracSurfaces(M11.getPointerPlot());
	optSysTOMPlots.fillVectorRayTracSurfaces(P12.getPointerPlot());
	optSysTOMPlots.fillVectorRayTracSurfaces(P13.getPointerPlot());
	optSysTOMPlots.fillVectorRayTracSurfaces(M14.getPointerPlot());
	optSysTOMPlots.fillVectorRayTracSurfaces(M15.getPointerPlot());
	optSysTOMPlots.fillVectorRayTracSurfaces(M16.getPointerPlot());
	optSysTOMPlots.fillVectorRayTracSurfaces(M17.getPointerPlot());
	optSysTOMPlots.fillVectorRayTracSurfaces(M18.getPointerPlot());
	optSysTOMPlots.fillVectorRayTracSurfaces(M19.getPointerPlot());



	SequentialRayTracing SeqTraceTOM_plot2D_optachse(optSysTOM_LLT);

	std::vector<LightRayStruct> lightRayAlong_PlotTOM_optachse = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 7, 50.0, -70.0, 100.0, 550, 1.0);
	SeqTraceTOM_plot2D_optachse.seqRayTracingWithVectorOfLightRays(lightRayAlong_PlotTOM_optachse);

	SequentialRayTracing SeqTraceTOM_plot2D_Field1(optSysTOM_LLT);
	std::vector<LightRayStruct> lightRayAlong_PlotTOM_field1 = SequentialRayTracing::lightRayAlongY({ 0.0, -0.01, 0.0 }, 7, 50.0, -70.0, 100.0, 550, 1.0);
	SeqTraceTOM_plot2D_Field1.seqRayTracingWithVectorOfLightRays(lightRayAlong_PlotTOM_field1);

	SequentialRayTracing SeqTraceTOM_plot2D_Field2(optSysTOM_LLT);
	std::vector<LightRayStruct> lightRayAlong_PlotTOM_field2 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.01, 0.0 }, 7, 50.0, -70.0, 100.0, 550, 1.0);
	SeqTraceTOM_plot2D_Field2.seqRayTracingWithVectorOfLightRays(lightRayAlong_PlotTOM_field2);

	//fill vector Ray Tracing

	optSysTOMPlots.fillVectorSequentialRayTracing(&SeqTraceTOM_plot2D_optachse, { 0,0,255 });
	optSysTOMPlots.fillVectorSequentialRayTracing(&SeqTraceTOM_plot2D_Field1, { 255,0,0 });
	optSysTOMPlots.fillVectorSequentialRayTracing(&SeqTraceTOM_plot2D_Field2, { 80,200, 100 });

	PlotParameterQwt ParameterTOM;
	RayTracingQwtPlot* SysTOMPlot = new RayTracingQwtPlot(optSysTOMPlots, optSysTOM_LLT, ParameterTOM);
	SysTOMPlot->show();
	bool checkerTOM = Math::checkTrueOfVectorElements(checkPlotTOM);

	return checkerTOM;
}