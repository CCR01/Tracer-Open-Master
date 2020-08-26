#include "testRayFanQwtPlot.h"

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
#include "..\..\Analyse\RayFan.h"

// plot
#include "..\..\Plot\PlotRayFan.h"


bool testRayFanQwtPlot::superFuncTestRayFanQwtPlot()
{
	std::vector<bool> checkRayFanPlot;

	bool testE0 =  testRayFanQwtPlotE0();
	checkRayFanPlot.push_back(testE0);
	bool testE1 = testRayFanQwtPlotE1();
	checkRayFanPlot.push_back(testE1);
	bool testE2 = testRayFanQwtPlotE2();
	checkRayFanPlot.push_back(testE2);

	bool returnCheck = Math::checkTrueOfVectorElements(checkRayFanPlot);
	return returnCheck;

}


//RayFan plot SystemE0
bool testRayFanQwtPlot::testRayFanQwtPlotE0()
{

	// interactions
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	Light_LLT mLight;
	mLight.setWavelength(550.0);


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


	// Plot RayFan opt achse
	PlanGeometry_LLT entrancePupilE0(/*semiHeight*/20.0, /*point*/{ 0.0,0.0,3.5696182 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	std::vector<LightRayStruct> lightRayAlong_X_E0_optAchse2 = SequentialRayTracing::lightRayAlongX({ 0.0, 0.0, 0.0 }, 150, 10.0, -1.0, 1.0, 550, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_E0_optAchse2 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 150, 10.0, -1.0, 1.0, 550, 1.0);

	//load the parameters of the RayFan plot
	PlotParameterQwt plotRayFan_E0_Parameter;
	//change the style of the symbols
	plotRayFan_E0_Parameter.setRayFanSymbolStyle(QwtSymbol::Diamond);
	//change the size of the symbols
	plotRayFan_E0_Parameter.setRayFanSizeSymbol(QSize(2, 2));
	//change the colour of the symbols
	plotRayFan_E0_Parameter.setRayFanSymbolColor(QBrush(QColor("darkYellow")));
	//change the contour colour of the symbols
	plotRayFan_E0_Parameter.setRayFanContourColorSymbol(QPen(Qt::red, 1));
	//add a comment to the RayFan plot at a given position
	plotRayFan_E0_Parameter.AddCommentToRayFanPlot("Comment_On_The_RayFan_Plot", { 150,-200 });
	//change the colour of the frame of the plots
	//plotRayFan_E0_Parameter.setRayFanFrameColor(QColor("white"));
	
	RayFan RayFanE0(entrancePupilE0.clone(), optSysE0, lightRayAlong_X_E0_optAchse2, lightRayAlong_Y_E0_optAchse2);
	PlotRayFan RayFanPlotE0(RayFanE0);
	SystemPlots SystemPlotE0;
	SystemPlotE0.fillVectorRayFanDiagramToPlot(&RayFanPlotE0);
	//RayFan plot
	mRayFanQwtPlotSystem0 = new PlotRayFanQwt(SystemPlotE0, RayFanPlotE0, plotRayFan_E0_Parameter);
	mRayFanQwtPlotSystem0->show();
	
	//check if the RayFan plot is shown
	return mRayFanQwtPlotSystem0->isVisible();
}


bool testRayFanQwtPlot::testRayFanQwtPlotE1()
{


	//all the surfaces
	SphericalSurface_LLT S1E1(/*radius*/38.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 15.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S2E1(/*radius*/10.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S3E1(/*radius*/51.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 22.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S4E1(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,27.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	SphericalSurface_LLT S5E1(/*radius*/61.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 29.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S6E1(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,34.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	SphericalSurface_LLT S7E1(/*radius*/13.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 36.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S8E1(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,41.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.5);
	SphericalSurface_LLT S9E1(/*radius*/100.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 43.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S10E1(/*radius*/26.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 48.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S11E1(/*radius*/21.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 53.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S12E1(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,58.5 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);


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
	optSysE1.fillVectorSurfaceAndInteractingData(10,S11E1.clone(), refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(11,S12E1.clone(), refrac.clone());
	

	Light_LLT mLight;
	mLight.setWavelength(550.0);


	// Plot RayFan field start { 0.0, 0.0, 0.0 }

	PlanGeometry_LLT entrancePupilE1(/*semiHeight*/1.0, /*point*/{ 0.0,0.0,5.000 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	std::vector<LightRayStruct> lightRayAlong_X_E1_optachsis = SequentialRayTracing::lightRayAlongX({ 0.0, 0.0, 0.0 }, 80, 10.0, -1.0, 1.0, 450, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_E1_optachas = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 80, 10.0, -1.0, 1.0, 450, 1.0);
	RayFan RayFan_E1_optachse(entrancePupilE1.clone(), optSysE1, lightRayAlong_X_E1_optachsis, lightRayAlong_Y_E1_optachas);
	PlotRayFan plotRayFan_E1_optachse(RayFan_E1_optachse);
	
	std::vector<LightRayStruct> lightRayAlong_X_E1_Field = SequentialRayTracing::lightRayAlongX({ 0.0, 1.0, 0.5 }, 80, 10.0, -1.0, 1.0, 450, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_E1_Field = SequentialRayTracing::lightRayAlongY({ 0.0, 1.0, 0.5 }, 80, 10.0, -1.0, 1.0, 450, 1.0);
	RayFan RayFan_E1_field(entrancePupilE1.clone(), optSysE1, lightRayAlong_X_E1_Field, lightRayAlong_Y_E1_Field);
	PlotRayFan plotRayFan_E1_field(RayFan_E1_field);

	std::vector<LightRayStruct> lightRayAlong_X_E1_Fiel1 = SequentialRayTracing::lightRayAlongX({ 0.0, 0.5, 0.1 }, 80, 10.0, -1.0, 1.0, 450, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_E1_Fiel1 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.5, 0.1 }, 80, 10.0, -1.0, 1.0, 450, 1.0);
	RayFan RayFan_E1_Fiel1(entrancePupilE1.clone(), optSysE1, lightRayAlong_X_E1_Fiel1, lightRayAlong_Y_E1_Fiel1);
	PlotRayFan plotRayFan_E1_field1(RayFan_E1_Fiel1);

	std::vector<LightRayStruct> lightRayAlong_X_E1_Field2 = SequentialRayTracing::lightRayAlongX({ 0.0, 1.0, 0.8 }, 80, 10.0, -1.0, 1.0, 450, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_E1_Field2 = SequentialRayTracing::lightRayAlongY({ 0.0, 1.0, 0.8 }, 80, 10.0, -1.0, 1.0, 450, 1.0);
	RayFan RayFan_E1_field2(entrancePupilE1.clone(), optSysE1, lightRayAlong_X_E1_Field2, lightRayAlong_Y_E1_Field2);
	PlotRayFan plotRayFan_E1_field2(RayFan_E1_field2);

	//initiate the parameter of the RayFan plot
	PlotParameterQwt plotRayFan_E1_Parameter;

	//Plot the RayFan plot
	SystemPlots SystemPlotE1;
	SystemPlotE1.fillVectorRayFanDiagramToPlot(&plotRayFan_E1_optachse);
	SystemPlotE1.fillVectorRayFanDiagramToPlot(&plotRayFan_E1_field);
	SystemPlotE1.fillVectorRayFanDiagramToPlot(&plotRayFan_E1_field1);
	SystemPlotE1.fillVectorRayFanDiagramToPlot(&plotRayFan_E1_field2);
	//Plot the RayFan plot
	mRayFanQwtPlotSystem1 = new PlotRayFanQwt(SystemPlotE1, RayFan_E1_field, plotRayFan_E1_Parameter);
	mRayFanQwtPlotSystem1->show();
	
	//check if the RayFan plot is shown
	return mRayFanQwtPlotSystem1->isVisible();
}

//RayFan plot SystemE2
bool testRayFanQwtPlot::testRayFanQwtPlotE2()
{

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	Light.setWavelength(550.0);

	ApertureStop_LLT ApertureStop0E2(1.0, { 0.0,0.0,5.0 }, { 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT SphericalSurface1E2(/*radius*/5.5, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,10.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT SphericalSurface2E2(/*radius*/8, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,15.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT SphericalSurface3E2(/*radius*/100.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,20.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT SphericalSurface4E2(/*radius*/100.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,25.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	PlanGeometry_LLT Plan5E2(/*semi Height*/ 3.0, /*apex*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, 1.5, 1.0);


	//*************
	// build the optical system
	OpticalSystem_LLT optSysE2;
	optSysE2.fillVectorSurfaceAndInteractingData(0, ApertureStop0E2.clone(), doNothing.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(1, SphericalSurface1E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(2, SphericalSurface2E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(3, SphericalSurface3E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(4, SphericalSurface4E2.clone(), refrac.clone());
	optSysE2.fillVectorSurfaceAndInteractingData(5, Plan5E2.clone(), absorb.clone());
	
	
	
	// Plot RayFan opt achse
	PlanGeometry_LLT entrancePupilE2(/*semiHeight*/20.0, /*point*/{ 0.0,0.0,2.5696182 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	std::vector<LightRayStruct> lightRayAlong_X_E2_optAchse2 = SequentialRayTracing::lightRayAlongX({ 0.0, 0.0, 0.0 }, 100, 10.0, -1.0, 1.0, 450, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_E2_optAchse2 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 100, 10.0, -1.0, 1.0, 450, 1.0);
	RayFan RayFan_E2_optAchse2(entrancePupilE2.clone(), optSysE2, lightRayAlong_X_E2_optAchse2, lightRayAlong_Y_E2_optAchse2);
	PlotRayFan plotRayFan_E2_optAchse(RayFan_E2_optAchse2);

	std::vector<LightRayStruct> lightRayAlong_X_E2_Field1 = SequentialRayTracing::lightRayAlongX({ 0.0, 1.0, 0.5 }, 100, 10.0, -1.0, 1.0, 450, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_E2_Field1 = SequentialRayTracing::lightRayAlongY({ 0.0, 1.0, 0.5 }, 100, 10.0, -1.0, 1.0, 450, 1.0);
	RayFan RayFan_E2_Field1(entrancePupilE2.clone(), optSysE2, lightRayAlong_X_E2_Field1, lightRayAlong_Y_E2_Field1);
	PlotRayFan plotRayFan_E2_Field1(RayFan_E2_Field1);


	std::vector<LightRayStruct> lightRayAlong_X_E2_Field2 = SequentialRayTracing::lightRayAlongX({ 0.0, 0.5, 1.5 }, 100, 10.0, -1.0, 1.0, 450, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_E2_Field2 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.5, 1.5 }, 100, 10.0, -1.0, 1.0, 450, 1.0);
	RayFan RayFan_E2_Field2(entrancePupilE2.clone(), optSysE2, lightRayAlong_X_E2_Field2, lightRayAlong_Y_E2_Field2);
	PlotRayFan plotRayFan_E2_Field2(RayFan_E2_Field2);

	//initiate the parameter of the RayFan plot
	PlotParameterQwt plotRayFan_E2_Parameter;
	
	//Plot the RayFan plot
	SystemPlots SystemPlotE2;
	SystemPlotE2.fillVectorRayFanDiagramToPlot(&plotRayFan_E2_optAchse);
	SystemPlotE2.fillVectorRayFanDiagramToPlot(&plotRayFan_E2_Field1);
	SystemPlotE2.fillVectorRayFanDiagramToPlot(&plotRayFan_E2_Field2);

	mRayFanQwtPlotSystem2 = new PlotRayFanQwt(SystemPlotE2, plotRayFan_E2_optAchse, plotRayFan_E2_Parameter);
	mRayFanQwtPlotSystem2->show();
	
	//check if the RayFan plot is shown
	return mRayFanQwtPlotSystem2->isVisible();
}