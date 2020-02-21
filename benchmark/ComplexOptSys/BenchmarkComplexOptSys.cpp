#include "BenchmarkComplexOptSys.h"
#include "..\..\LowLevelTracing\Math_LLT.h"

// surfaces
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"

// interactions
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"

// optical system
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\..\FillAptertureStop\FillApertureStop.h"

// analyse 
#include "..\..\Analyse\Spot.h"
#include "..\..\Analyse\OpticalPathDifference.h"

// plot
#include "..\..\Plot\PlotSpotDiagram.h"
#include "..\..\Plot\PlotOPD.h"

//here we design complex optical system and check the functions of the ray tracer
bool BechmarkComplexOpticalSystem::checkComplexOpticalSystem()
{
	typedef std::shared_ptr< SurfaceIntersectionRay_LLT > surfacePtr_LLT;
	std::vector<bool> checkComOptSys;

	// complex opt system

	//***
	//all the surfaces
	ApertureStop_LLT A0(1.0, { 0.0,0.0,10.0 }, { 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT S1(/*radius*/38.73360379131933, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 15.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S2(/*radius*/10.33817058758478, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S3(/*radius*/51.02696739895755, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 22.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S4(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,27.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	SphericalSurface_LLT S5(/*radius*/61.48513190056155, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 29.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S6(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,34.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	SphericalSurface_LLT S7(/*radius*/13.22318498941039, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 36.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	PlanGeometry_LLT S8(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,41.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	SphericalSurface_LLT S9(/*radius*/12.07896133399859, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 43.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	SphericalSurface_LLT S10(/*radius*/26.46510860484050, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 48.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.6);
	SphericalSurface_LLT S11(/*radius*/21.48098096423011, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 53.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	SphericalSurface_LLT S12(/*radius*/30.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 55.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S13(/*radius*/70.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 60.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.6, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S14(/*radius*/40.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 65.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.6, /*refIndexSideB*/1.0);
	PlanGeometry_LLT S15(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	//***

	
	// build the optical system
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	OpticalSystem_LLT optSysE1;
	optSysE1.fillVectorSurfaceAndInteractingData(0, &A0, doNothing.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(1, &S1, refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(2, &S2, refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(3, &S3, refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(4, &S4, refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(5, &S5, refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(6, &S6, refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(7, &S7, refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(8, &S8, refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(9, &S9, refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(10, &S10, refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(11, &S11, refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(12, &S12, refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(13, &S13, refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(14, &S14, refrac.clone());
	optSysE1.fillVectorSurfaceAndInteractingData(15, &S15, refrac.clone());

	// single ray tracing
	Ray_LLT rayE1_0({ 0.0,0.0,0.0 }, { 0.0,1.0,10.0 }, 1.0);
	Light_LLT light;
	light.setWavelength(550.0);
	LightRayStruct lightRayE1_0(light, rayE1_0, 1);
	SequentialRayTracing seqTraceE1_single(optSysE1);
	seqTraceE1_single.sequentialRayTracing(lightRayE1_0);
	IntersectInformationStruct interInfosS0 = seqTraceE1_single.getAllInterInfosOfSurf_i(0).at(0);
	IntersectInformationStruct interInfosS1 = seqTraceE1_single.getAllInterInfosOfSurf_i(1).at(0);
	IntersectInformationStruct interInfosS2 = seqTraceE1_single.getAllInterInfosOfSurf_i(2).at(0);
	IntersectInformationStruct interInfosS3 = seqTraceE1_single.getAllInterInfosOfSurf_i(3).at(0);
	IntersectInformationStruct interInfosS4 = seqTraceE1_single.getAllInterInfosOfSurf_i(4).at(0);
	IntersectInformationStruct interInfosS5 = seqTraceE1_single.getAllInterInfosOfSurf_i(5).at(0);
	IntersectInformationStruct interInfosS6 = seqTraceE1_single.getAllInterInfosOfSurf_i(6).at(0);
	IntersectInformationStruct interInfosS7 = seqTraceE1_single.getAllInterInfosOfSurf_i(7).at(0);
	IntersectInformationStruct interInfosS8 = seqTraceE1_single.getAllInterInfosOfSurf_i(8).at(0);
	IntersectInformationStruct interInfosS9 = seqTraceE1_single.getAllInterInfosOfSurf_i(9).at(0);
	IntersectInformationStruct interInfosS10 = seqTraceE1_single.getAllInterInfosOfSurf_i(10).at(0);
	IntersectInformationStruct interInfosS11 = seqTraceE1_single.getAllInterInfosOfSurf_i(11).at(0);
	IntersectInformationStruct interInfosS12 = seqTraceE1_single.getAllInterInfosOfSurf_i(12).at(0);
	IntersectInformationStruct interInfosS13 = seqTraceE1_single.getAllInterInfosOfSurf_i(13).at(0);
	IntersectInformationStruct interInfosS14 = seqTraceE1_single.getAllInterInfosOfSurf_i(14).at(0);
	IntersectInformationStruct interInfosS15 = seqTraceE1_single.getAllInterInfosOfSurf_i(15).at(0);

	//// plot 2d
	optSysE1.fillVectorToPlot2D(0, &A0);
	optSysE1.fillVectorToPlot2D(1, &S1);
	optSysE1.fillVectorToPlot2D(2, &S2);
	optSysE1.fillVectorToPlot2D(3, &S3);
	optSysE1.fillVectorToPlot2D(4, &S4);
	optSysE1.fillVectorToPlot2D(5, &S5);
	optSysE1.fillVectorToPlot2D(6, &S6);
	optSysE1.fillVectorToPlot2D(7, &S7);
	optSysE1.fillVectorToPlot2D(8, &S8);
	optSysE1.fillVectorToPlot2D(9, &S9);
	optSysE1.fillVectorToPlot2D(10, &S10);
	optSysE1.fillVectorToPlot2D(11, &S11);
	optSysE1.fillVectorToPlot2D(12, &S12);
	optSysE1.fillVectorToPlot2D(13, &S13);
	optSysE1.fillVectorToPlot2D(14, &S14);
	optSysE1.fillVectorToPlot2D(15, &S15);

	SequentialRayTracing SeqTraceE1_plot2D(optSysE1);
	std::vector<LightRayStruct> lightRayAlong_Y_E1 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 7, 10.0, -1.0, 1.0, 550, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_E2 = SequentialRayTracing::lightRayAlongY({ 0.0, 1.5, 0.0 }, 7, 10.0, -1.0, 1.0, 550, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_E3 = SequentialRayTracing::lightRayAlongY({ 0.0, -1.5, 0.0 }, 7, 10.0, -1.0, 1.0, 550, 1.0);
	SeqTraceE1_plot2D.seqRayTracingWithVectorOfLightRays(lightRayAlong_Y_E1);
	SeqTraceE1_plot2D.seqRayTracingWithVectorOfLightRays(lightRayAlong_Y_E2);
	SeqTraceE1_plot2D.seqRayTracingWithVectorOfLightRays(lightRayAlong_Y_E3);
	cv::Mat imageE1(/*x*/800,/*y*/ 1600, CV_8UC3, cv::Scalar(255, 255, 255));
	
	// Plot the system
	Plot2D plot2D0(optSysE1, SeqTraceE1_plot2D, imageE1, /*scale*/ 20, 16, 1);
	plot2D0.plotOpticalSystem2D();
	plot2D0.plotRays();
	PlotCarsten::plotDiagram(imageE1, "complex optical system E1");
	PlotCarsten::saveImage(imageE1, "complexOpticalSystemE1.jpg");
	
	// analyse
	// calc spot diagram opt achse
	FillApertureStop fillAperStopE1_optAchse({ 0.0,0.0,0.0 }, 1, { 0.0,0.0,10.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.5, light);
	SequentialRayTracing seqTraceE1_OptAchse(optSysE1);
	seqTraceE1_OptAchse.seqRayTracingWithVectorOfLightRays(fillAperStopE1_optAchse.getVectorWithLightRays());
	Spot spotE1_optAchese(seqTraceE1_OptAchse.getAllInterPointsAtSurf_i(15), seqTraceE1_OptAchse.getAllInterPointsAtSurf_i(15).at(0));
	real rmsE1_optAchse = spotE1_optAchese.getRMS_mm() * 1000;
	real rmsZemaxE1_optAchse = 2.312; // it is for Ray Density 6 -> rings = 6, arms =8
	real geoE1_optAchse = spotE1_optAchese.getGeoRadius() * 1000;
	real geoZemaxE1_optAchse = 3.620; // it is for Ray Density 6 -> rings = 6, arms =8
	bool checkRSM_optAchse = Math::compareTwoNumbers_decimals(rmsE1_optAchse, rmsZemaxE1_optAchse,2);
	bool checkGeoE1_optAchse = Math::compareTwoNumbers_decimals (geoE1_optAchse, geoZemaxE1_optAchse, 2);
	checkComOptSys.push_back(checkRSM_optAchse);
	checkComOptSys.push_back(checkGeoE1_optAchse);

	// calc spot diagram field
	FillApertureStop fillAperStopE1_filed({ 0.0,1.0,0.0 }, 1, { 0.0,0.0,10.0 }, { 0.0,0.0,1.0 }, 6, 8, 1.5, light);
	SequentialRayTracing seqTraceE1_filed(optSysE1);
	seqTraceE1_filed.seqRayTracingWithVectorOfLightRays(fillAperStopE1_filed.getVectorWithLightRays());
	Spot spotE1_field(seqTraceE1_filed.getAllInterPointsAtSurf_i(15), seqTraceE1_filed.getAllInterPointsAtSurf_i(15).at(0));
	real rmsE1_field = spotE1_field.getRMS_mm() * 1000;
	real rmsZemaxE1_field = 10.724; // it is for Ray Density 6 -> rings = 6, arms =8
	real geoE1_field = spotE1_field.getGeoRadius() * 1000;
	real geoZemaxE1_field = 23.782; // it is for Ray Density 6 -> rings = 6, arms =8
	bool checkRSM_field = Math::compareTwoNumbers_decimals(rmsE1_field, rmsZemaxE1_field,2);
	bool checkGeoE1_field = Math::compareTwoNumbers_decimals(geoE1_field, geoZemaxE1_field,2);
	checkComOptSys.push_back(checkRSM_field);
	checkComOptSys.push_back(checkGeoE1_field);

	// calc OPD opt achse
	std::vector<LightRayStruct> lightRayAlong_X_E1_optAchse = SequentialRayTracing::lightRayAlongX({ 0.0, 0.0, 0.0 }, 5, 10.0, -1.0, 1.0, 550.0, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_E1_optAchse = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 5, 10.0, -1.0, 1.0, 550.0, 1.0);
	PlanGeometry_LLT exitPupilE1(/*semiHeight*/20.0, /*point*/{ 0.0,0.0,201.5696182 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	surfacePtr_LLT exitPupilE1_ptr = exitPupilE1.clone();

	Ray_LLT chiefRayE1_optAchse({ 0.0,0.0,0.0 }, { 0.0,0.0,1.0 }, 1.0);
	LightRayStruct chiefLightRayE1_optAchse(light, chiefRayE1_optAchse, 1);
	OPD OPD_E1_optAchse(exitPupilE1_ptr, optSysE1, lightRayAlong_X_E1_optAchse, lightRayAlong_Y_E1_optAchse, chiefLightRayE1_optAchse);
	real OPD_E1_optAchse_neg1 = OPD_E1_optAchse.getOPD_Y_inVec().at(0);
	bool check_OPD_E1_optAchse_neg1 = Math::compareTwoNumbers_decimals(-0.142047768537, OPD_E1_optAchse_neg1,5);
	checkComOptSys.push_back(check_OPD_E1_optAchse_neg1);
	real OPD_E1_optAchse_neg05 = OPD_E1_optAchse.getOPD_Y_inVec().at(1);
	bool check_OPD_E1_optAchse_neg05 = Math::compareTwoNumbers_decimals(-0.020161259362, OPD_E1_optAchse_neg05, 5);
	checkComOptSys.push_back(check_OPD_E1_optAchse_neg05);
	real OPD_E1_optAchse_0 = OPD_E1_optAchse.getOPD_Y_inVec().at(2);
	bool check_OPD_E1_optAchse_0 = Math::compareTwoNumbers_decimals(0.0, OPD_E1_optAchse_0,5);
	checkComOptSys.push_back(check_OPD_E1_optAchse_0);
	real OPD_E1_optAchse_05 = OPD_E1_optAchse.getOPD_Y_inVec().at(3);
	bool check_OPD_E1_optAchse_05 = Math::compareTwoNumbers_decimals(-0.020161259362, OPD_E1_optAchse_05,5);
	checkComOptSys.push_back(check_OPD_E1_optAchse_05);
	real OPD_E1_optAchse_1 = OPD_E1_optAchse.getOPD_Y_inVec().at(4);
	bool check_OPD_E1_optAchse_1 = Math::compareTwoNumbers_decimals(-0.142047768537, OPD_E1_optAchse_1,5);
	checkComOptSys.push_back(check_OPD_E1_optAchse_1);

//	// calc OPD field
	OPD OPD_E_field;
	std::vector<LightRayStruct> lightRayAlong_X_E1_field = SequentialRayTracing::lightRayAlongX({ 0.0, 1.0, 0.0 }, 5, 10.0, -1.0, 1.0, 550.0, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_E1_field = SequentialRayTracing::lightRayAlongY({ 0.0, 1.0, 0.0 }, 5, 10.0, -1.0, 1.0, 550.0, 1.0);
	Ray_LLT chiefRayE1_field({ 0.0,1.0,0.0 }, { 0.0,-1.0,10.0 }, 1.0);
	LightRayStruct chiefLightRayE1_field(light, chiefRayE1_field, 1);
	OPD OPD_E1_field(exitPupilE1_ptr, optSysE1, lightRayAlong_X_E1_field, lightRayAlong_Y_E1_field, chiefLightRayE1_field);
	real OPD_E1_field_neg1 = OPD_E1_field.getOPD_Y_inVec().at(0);
	bool check_E1_field_neg1 = Math::compareTwoNumbers_decimals(OPD_E1_field_neg1, 0.9275625741142, 5);
	checkComOptSys.push_back(check_E1_field_neg1);
	real OPD_E1_field_neg05 = OPD_E1_field.getOPD_Y_inVec().at(1);
	bool check_OPD_E1_field_neg05 = Math::compareTwoNumbers_decimals(OPD_E1_field_neg05, 0.3238029237669, 5);
	checkComOptSys.push_back(check_OPD_E1_field_neg05);
	real OPD_E1_field_0 = OPD_E1_field.getOPD_Y_inVec().at(2);
	bool check_OPD_E1_field_0 = Math::compareTwoNumbers_decimals(OPD_E1_field_0, 0.0, 5);
	checkComOptSys.push_back(check_OPD_E1_field_0);
	real OPD_E1_field_05 = OPD_E1_field.getOPD_Y_inVec().at(3);
	bool check_OPD_E1_field_05 = Math::compareTwoNumbers_decimals(OPD_E1_field_05, 0.3891952335191, 5);
	checkComOptSys.push_back(check_OPD_E1_field_05);
	real OPD_E1_field_1 = OPD_E1_field.getOPD_Y_inVec().at(4);
	bool check_OPD_E1_field_1 = Math::compareTwoNumbers_decimals(OPD_E1_field_1, 1.5631132361715, 5);
	checkComOptSys.push_back(check_OPD_E1_field_1);

	// Plot spot diagram opt achse
	std::vector<Spot> vecSpotE1_optAchese{ spotE1_optAchese };
	PlotSpotDiagramm PlotSpotE1_optAchse(spotE1_optAchese.getRefPoint(), vecSpotE1_optAchese, 0.09950372, 550);
	PlotCarsten::plotDiagram(PlotSpotE1_optAchse.getMatrixToPlotSpot(), "Spot Diagram optical achse");
	PlotCarsten::saveImage(PlotSpotE1_optAchse.getMatrixToPlotSpot(), "../benchmark/Plot/imagBes/image1.jpg");

	// Plot spot diagram field
	std::vector<Spot> vecSpotE1_field{ spotE1_field };
	PlotSpotDiagramm PlotSpotE1_field(spotE1_field.getRefPoint(), vecSpotE1_field, 0.09950372, 550);
	PlotCarsten::plotDiagram(PlotSpotE1_field.getMatrixToPlotSpot(), "Spot Diagram field");
	PlotCarsten::saveImage(PlotSpotE1_optAchse.getMatrixToPlotSpot(), "../benchmark/Plot/images/image1.jpg");
	
	// Plot OPD opt achse
	std::vector<LightRayStruct> lightRayAlong_X_E1_optAchse2 = SequentialRayTracing::lightRayAlongX({ 0.0, 0.0, 0.0 }, 100, 10.0, -1.0, 1.0, 550, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_E1_optAchse2 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 100, 10.0, -1.0, 1.0, 550, 1.0);
	OPD OPD_E1_optAchse2(exitPupilE1_ptr, optSysE1, lightRayAlong_X_E1_optAchse2, lightRayAlong_Y_E1_optAchse2, chiefLightRayE1_optAchse);
	PlotOPD plotOPD_E1_optAchse(OPD_E1_optAchse2);
	PlotCarsten::plotDiagram(plotOPD_E1_optAchse.getMatrixToPlotOPD_X_Plane(), "OPD E1 opt Achse X");
	//Plot::saveImage(plotOPD_E1_optAchse.getMatrixToPlotOPD_X_Plane(), "OPD_optAchse_X.jpg");
	PlotCarsten::plotDiagram(plotOPD_E1_optAchse.getMatrixToPlotOPD_Y_Plane(), "OPD E1 opt Achse Y");
	//Plot::saveImage(plotOPD_E1_optAchse.getMatrixToPlotOPD_Y_Plane(), "OPD_optAchse_Y.jpg");
	
	// Plot OPD field start { 0.0, 1.0, 0.0 }
	std::vector<LightRayStruct> lightRayAlong_X_E1_field2 = SequentialRayTracing::lightRayAlongX({ 0.0, 1.0, 0.0 }, 100, 10.0, -1.0, 1.0, 550, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_E1_field2 = SequentialRayTracing::lightRayAlongY({ 0.0, 1.0, 0.0 }, 100, 10.0, -1.0, 1.0, 550, 1.0);
	OPD OPD_E1_field2(exitPupilE1_ptr, optSysE1, lightRayAlong_X_E1_field2, lightRayAlong_Y_E1_field2, chiefLightRayE1_field);
	PlotOPD plotOPD_E1_field(OPD_E1_field2);
	PlotCarsten::plotDiagram(plotOPD_E1_field.getMatrixToPlotOPD_X_Plane(), "OPD E1 field X start y=1");
	PlotCarsten::plotDiagram(plotOPD_E1_field.getMatrixToPlotOPD_Y_Plane(), "OPD E1 field Y start y=1");

//	// Plot OPD field start { 1.0, 0.0, 0.0 }
//	std::vector<LightRayStruct> lightRayAlong_X_E1_field2_X1 = SequentialRayTracing::lightRayAlongX({ 1.0, 0.0, 0.0 }, 100, 10.0, -1.0, 1.0, 550, 1.0);
//	std::vector<LightRayStruct> lightRayAlong_Y_E1_field2_X1 = SequentialRayTracing::lightRayAlongY({ 1.0, 0.0, 0.0 }, 100, 10.0, -1.0, 1.0, 550, 1.0);
//	Ray_LLT chiefRayE1_field_X1({ 1.0,0.0,0.0 }, { -1.0,0.0,10.0 }, 0.550, 1.0);
//	LightRayStruct chiefLightRayE1_field_X1(chiefRayE1_field_X1, light, 1);
//	OPD OPD_E1_field2_X1(exitPupilE1, optSysE1, lightRayAlong_X_E1_field2_X1, lightRayAlong_Y_E1_field2_X1, chiefLightRayE1_field_X1);
//	PlotOPD plotOPD_E1_field_X1(OPD_E1_field2_X1);
//	Plot::plotDiagram(plotOPD_E1_field_X1.getMatrixToPlotOPD_X_Plane(), "OPD E1 field X start x=1");
//	Plot::plotDiagram(plotOPD_E1_field_X1.getMatrixToPlotOPD_Y_Plane(), "OPD E1 field Y start x=1");



	// calc global OPD optical achse 
	OPD OPDglobalE1_optAchse(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ fillAperStopE1_optAchse.getVectorWithLightRays(), /*chief ray*/ fillAperStopE1_optAchse.getVectorWithLightRays().at(0), /*scalling*/ 0);
	cv::Mat globalOPD_optAchse = OPDglobalE1_optAchse.getGlobalOPD();

	// calc global OPD field y = 1
	OPD OPDglobalE1_field(/*exit pupil*/ exitPupilE1_ptr,  /*optical system*/ optSysE1,
		/*fill apertur stop with light ray*/ fillAperStopE1_filed.getVectorWithLightRays(), /*chief ray*/ fillAperStopE1_filed.getVectorWithLightRays().at(0), /*scalling*/ 0);
	cv::Mat globalOPD_field = OPDglobalE1_field.getGlobalOPD();
//
//
//
//
	bool output = Math::checkTrueOfVectorElements(checkComOptSys);
	return output;
}