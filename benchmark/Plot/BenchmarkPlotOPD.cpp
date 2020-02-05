#pragma once

#include "BenchPlotOPD.h"
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\FillAptertureStop\FillApertureStop.h"""
#include "..\..\Plot\PlotOPD.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"

bool BenchmarkPlotOPD::checkMethodesPlotOPD()
{

	RefractedRay_LLT refrac;
	DoNothingInteraction_LLT doNothing;
	Light_LLT Light;
	Absorb_LLT absorb;


//	//*****************************************************************************************************************
//	//*****************************************************************************************************************
//	//*****************************************************************************************************************
//	// exit pupil of this system is behind the last surface
//	// surfaces of the optical system
//	SphericalSurface_LLT S0E3(/*radius*/15.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 40.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
//	SphericalSurface_LLT S1E3(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 45.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
//	PlanGeometry_LLT PlanE3(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
//
//	OpticalSystem_LLT optSysE3;
//	optSysE3.fillVectorSurfaceAndInteractingData(0, &S0E3, refrac.clone());
//	optSysE3.fillVectorSurfaceAndInteractingData(1, &S1E3, refrac.clone());
//	optSysE3.fillVectorSurfaceAndInteractingData(2, &PlanE3, doNothing.clone());
//
//	PlanGeometry_LLT exitPupilE3(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,74.230762215072 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
//
//	//*****************************************************************************************************************
//	// OPD on optical axis
//	std::vector<LightRayStruct> lightRayAlong_X_optA_E3 = SequentialRayTracing::lightRayAlongX({ 0.0, 0.0, 0.0 }, 200, 20.0, -1.0, 1.0, 550, 1.0);
//	std::vector<LightRayStruct> lightRayAlong_Y_optA_E3 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 200, 20.0, -1.0, 1.0, 550, 1.0);
//	Ray_LLT chiefRayOptA_E3({ 0.0,0.0,0.0 }, { 0.0,0.0,1.0 }, 550, 1.0);
//	LightRayStruct chiefLightRayOptA_E3(chiefRayOptA_E3, Light, 1);
//	// calculate the OPD in X and Y direction
//	OPD OPD3OptA(exitPupilE3, optSysE3, lightRayAlong_X_optA_E3, lightRayAlong_Y_optA_E3, chiefLightRayOptA_E3);
//	PlotOPD plotOPD3optA(OPD3OptA);
//	Plot::plotDiagram(plotOPD3optA.getMatrixToPlotOPD_X_Plane(), "OPD X optical axis");
//	Plot::saveImage(plotOPD3optA.getMatrixToPlotOPD_X_Plane(), "OPD_optAchse_X.jpg");
//	Plot::plotDiagram(plotOPD3optA.getMatrixToPlotOPD_Y_Plane(), "OPD Y optical axis");
//	Plot::saveImage(plotOPD3optA.getMatrixToPlotOPD_Y_Plane(), "OPD_optAchse_Y.jpg");
//
//	//*****************************************************************************************************************
//	// OPD in field x=-0.5
//	std::vector<LightRayStruct> lightRayAlong_Xneg_F1_E3 = SequentialRayTracing::lightRayAlongX({ -0.5, 0.0, 0.0 }, 200, 20.0, -1.0, 1.0, 550, 1.0);
//	std::vector<LightRayStruct> lightRayAlong_Y1_F1_E3 = SequentialRayTracing::lightRayAlongY({ -0.5, 0.0, 0.0 }, 200, 20.0, -1.0, 1.0, 550, 1.0);
//	Ray_LLT chiefRayF05_E3({ -0.5,0.0,0.0 }, { 0.5,0.0,20.0 }, 550, 1.0);
//	LightRayStruct chiefLightRayF1_E3(chiefRayF05_E3, Light, 1);
//	OPD OPD3F1(exitPupilE3, optSysE3, lightRayAlong_Xneg_F1_E3, lightRayAlong_Y1_F1_E3, chiefLightRayF1_E3);
//	// check OPD values X
//	real OPDstart = OPD3F1.getOPD_X_inVec().at(0);
//	unsigned int sizeMatrix = OPD3F1.getOPD_X_inVec().size();
//	real OPDend = OPD3F1.getOPD_X_inVec().at(sizeMatrix-1);
//	PlotOPD plotOPD3feld(OPD3F1);
//	Plot::plotDiagram(plotOPD3feld.getMatrixToPlotOPD_X_Plane(), "OPD X -0.5 field");
//	//*****************************************************************************************************************
//
//	//*****************************************************************************************************************
//	// OPD in field x=0.5
//	std::vector<LightRayStruct> lightRayAlong_Xpos_F1_E3 = SequentialRayTracing::lightRayAlongX({ 0.5, 0.0, 0.0 }, 200, 20.0, -1.0, 1.0, 550, 1.0);
//	std::vector<LightRayStruct> lightRayAlong_Y2_F1_E3 = SequentialRayTracing::lightRayAlongY({ 0.5, 0.0, 0.0 }, 200, 20.0, -1.0, 1.0, 550, 1.0);
//	Ray_LLT chiefRayF05_E3_2({ 0.5,0.0,0.0 }, { -0.5,0.0,20.0 }, 550, 1.0);
//	LightRayStruct chiefLightRayF2_E3(chiefRayF05_E3_2, Light, 1);
//	OPD OPD3F2(exitPupilE3, optSysE3, lightRayAlong_Xpos_F1_E3, lightRayAlong_Y2_F1_E3, chiefLightRayF2_E3);
//	// check OPD values X
//	real OPDstart2 = OPD3F2.getOPD_X_inVec().at(0);
//	unsigned int sizeMatrix2 = OPD3F2.getOPD_X_inVec().size();
//	real OPDend2 = OPD3F2.getOPD_X_inVec().at(sizeMatrix2 - 1);
//	PlotOPD plotOPD3feld2(OPD3F2);
//	Plot::plotDiagram(plotOPD3feld2.getMatrixToPlotOPD_X_Plane(), "OPD X +0.5 field");
//	//*****************************************************************************************************************
//
//	//*****************************************************************************************************************
//	// OPD in field y=0.5
//	std::vector<LightRayStruct> lightRayAlong_X_F1_E3 = SequentialRayTracing::lightRayAlongX({ 0.0, 0.5, 0.0 }, 200, 20.0, -1.0, 1.0, 550, 1.0);
//	std::vector<LightRayStruct> lightRayAlong_Ypos_F1_E3 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.5, 0.0 }, 200, 20.0, -1.0, 1.0, 550, 1.0);
//	Ray_LLT chiefRayF05_E3_Y({ 0.0,0.5,0.0 }, { 0.0,-0.5,20.0 }, 550, 1.0);
//	LightRayStruct chiefLightRayF_E3_Y(chiefRayF05_E3_Y, Light, 1);
//	OPD OPD3F2_Y(exitPupilE3, optSysE3, lightRayAlong_X_F1_E3, lightRayAlong_Ypos_F1_E3, chiefLightRayF_E3_Y);
//	// check OPD values Y
//	real OPDstart_Y = OPD3F2_Y.getOPD_Y_inVec().at(0);
//	unsigned int sizeMatrix_Y = OPD3F2_Y.getOPD_Y_inVec().size();
//	real OPDend_Y = OPD3F2_Y.getOPD_Y_inVec().at(sizeMatrix_Y - 1);
//	PlotOPD plotOPD3feld_Y(OPD3F2_Y);
//	Plot::plotDiagram(plotOPD3feld_Y.getMatrixToPlotOPD_Y_Plane(), "OPD Y +0.5 field");
//	//*****************************************************************************************************************
//
//	//	//*****************************************************************************************************************
//	// OPD in field y=-0.5
//	std::vector<LightRayStruct> lightRayAlong_X_F1_E3_2 = SequentialRayTracing::lightRayAlongX({ 0.0, -0.5, 0.0 }, 200, 20.0, -1.0, 1.0, 550, 1.0);
//	std::vector<LightRayStruct> lightRayAlong_Ypos_F1_E3_2 = SequentialRayTracing::lightRayAlongY({ 0.0, -0.5, 0.0 }, 200, 20.0, -1.0, 1.0, 550, 1.0);
//	Ray_LLT chiefRayF05_E3_Y_2({ 0.0,-0.5,0.0 }, { 0.0,0.5,20.0 }, 550, 1.0);
//	LightRayStruct chiefLightRayF_E3_Y_2(chiefRayF05_E3_Y_2, Light, 1);
//	OPD OPD3F2_Y_2(exitPupilE3, optSysE3, lightRayAlong_X_F1_E3_2, lightRayAlong_Ypos_F1_E3_2, chiefLightRayF_E3_Y_2);
//	// check OPD values Y
//	real OPDstart_Y_2 = OPD3F2_Y_2.getOPD_Y_inVec().at(0);
//	unsigned int sizeMatrix_Y_2 = OPD3F2_Y_2.getOPD_Y_inVec().size();
//	real OPDend_Y_2 = OPD3F2_Y_2.getOPD_Y_inVec().at(sizeMatrix_Y_2 - 1);
//	PlotOPD plotOPD3feld_Y_2(OPD3F2_Y_2);
//	Plot::plotDiagram(plotOPD3feld_Y_2.getMatrixToPlotOPD_Y_Plane(), "OPD Y +0.5 field");
//	//*****************************************************************************************************************
//
//	//*****************************************************************************************************************
//	//*****************************************************************************************************************
//	//*****************************************************************************************************************
//	// exit pupil is in the optical surface
//	// surfaces of the optical system
//	SphericalSurface_LLT S0E2(/*radius*/5.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 13 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
//	SphericalSurface_LLT S1E2(/*radius*/5.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 18 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
//	SphericalSurface_LLT S2E2(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 21 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
//	SphericalSurface_LLT S3E2(/*radius*/10.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0, 0.0, 26 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
//	PlanGeometry_LLT ImageE2(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,31.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
//
//	// build the optical system
//	// exit pupil it at position of Plan_Ex2_2
//	OpticalSystem_LLT OptSysE2;
//	OptSysE2.fillVectorSurfaceAndInteractingData(0, &S0E2, refrac.clone());
//	OptSysE2.fillVectorSurfaceAndInteractingData(1, &S1E2, refrac.clone());
//	OptSysE2.fillVectorSurfaceAndInteractingData(2, &S2E2, refrac.clone());
//	OptSysE2.fillVectorSurfaceAndInteractingData(3, &S3E2, refrac.clone());
//	OptSysE2.fillVectorSurfaceAndInteractingData(4, &ImageE2, refrac.clone());
//
//	PlanGeometry_LLT exitPupil1(/*semiHeight*/3.0, /*point*/{ 0.0,0.0,19.144876330 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
//
//	//*****************************************************************************************************************
//	// OPD P_Y on optical axis 
//	std::vector<LightRayStruct> lightRayAlong_XE2 = SequentialRayTracing::lightRayAlongX({ 0.0, 0.0, 0.0 }, 200, 12.0, -1.0, 1.0, 550, 1.0);
//	std::vector<LightRayStruct> lightRayAlong_Y_E2 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 200, 12.0, -1.0, 1.0, 550, 1.0);
//	Ray_LLT chiefRay_E2({ 0.0,0.0,0.0 }, { 0.0,0.0,20.0 }, 550, 1.0);
//	LightRayStruct chiefLightRayE2(chiefRay_E2, Light, 1);
//	OPD OPD_E2(exitPupil1, OptSysE2, lightRayAlong_XE2, lightRayAlong_Y_E2, chiefLightRayE2);
//	// check OPD values Y
//	real OPDstart_Y_optA_E2_1 = OPD_E2.getOPD_Y_inVec().at(0);
//	unsigned int sizeMatrix_Y2E2 = OPD_E2.getOPD_Y_inVec().size();
//	real OPDstart_Y_optA_E2_2 = OPD_E2.getOPD_Y_inVec().at(sizeMatrix_Y2E2 - 1);
//	PlotOPD plotOPD2(OPD_E2);
//	Plot::plotDiagram(plotOPD2.getMatrixToPlotOPD_Y_Plane(), "OPD Y opt axis");
//	//*****************************************************************************************************************
//	// OPD P_Y in filed y = 1
//	std::vector<LightRayStruct> lightRayAlong_X_F1_E2 = SequentialRayTracing::lightRayAlongX({ 0.0, 1.0, 0.0 }, 200, 12.0, -1.0, 1.0, 550, 1.0);
//	std::vector<LightRayStruct> lightRayAlong_Y_F1_E2 = SequentialRayTracing::lightRayAlongY({ 0.0, 1.0, 0.0 }, 200, 12.0, -1.0, 1.0, 550, 1.0);
//	Ray_LLT chiefRay_E2_FY1({ 0.0,1.0,0.0 }, { 0.0,-1.0,12.0 }, 550, 1.0);
//	LightRayStruct chiefLightRayFY_E2(chiefRay_E2_FY1, Light, 1);
//	OPD OPD_E2_Y(exitPupil1, OptSysE2, lightRayAlong_X_F1_E2, lightRayAlong_Y_F1_E2, chiefLightRayFY_E2);
//	// check OPD values Y
//	real OPDstart_Y_F1 = OPD_E2_Y.getOPD_Y_inVec().at(0);
//	real OPDtest1 = OPD_E2_Y.getOPD_Y_inVec().at(1);
//	real OPDtest2 = OPD_E2_Y.getOPD_Y_inVec().at(2);
//	real OPDtest3 = OPD_E2_Y.getOPD_Y_inVec().at(3);
//	unsigned int sizeMatrix_Y1_2 = OPD_E2_Y.getOPD_Y_inVec().size();
//	real OPDend_Y_2_F1_E1 = OPD_E2_Y.getOPD_Y_inVec().at(sizeMatrix_Y1_2 - 1);
//	PlotOPD plotOPDY1E2(OPD_E2_Y);
//	Plot::plotDiagram(plotOPDY1E2.getMatrixToPlotOPD_Y_Plane(), "OPD Y field y = 1");
//	//*****************************************************************************************************************
//	// OPD P_Y in filed y = -1
//	std::vector<LightRayStruct> lightRayAlong_X_F2_E2 = SequentialRayTracing::lightRayAlongX({ 0.0, -1.0, 0.0 }, 200, 12.0, -1.0, 1.0, 550, 1.0);
//	std::vector<LightRayStruct> lightRayAlong_Y_F2_E2 = SequentialRayTracing::lightRayAlongY({ 0.0, -1.0, 0.0 }, 200, 12.0, -1.0, 1.0, 550, 1.0);
//	Ray_LLT chiefRay_E2_FY2({ 0.0,-1.0,0.0 }, { 0.0,1.0,12.0 }, 550, 1.0);
//	LightRayStruct chiefLightRayFY1_E2(chiefRay_E2_FY2, Light, 1);
//	OPD OPD_E2_Y2(exitPupil1, OptSysE2, lightRayAlong_X_F2_E2, lightRayAlong_Y_F2_E2, chiefLightRayFY1_E2);
//	// check OPD values Y
//	real OPDstart_Y_F2 = OPD_E2_Y2.getOPD_Y_inVec().at(0);
//	real OPDtest1Y2 = OPD_E2_Y2.getOPD_Y_inVec().at(1);
//	real OPDtest2Y2 = OPD_E2_Y2.getOPD_Y_inVec().at(2);
//	real OPDtest3Y2 = OPD_E2_Y2.getOPD_Y_inVec().at(3);
//	unsigned int sizeMatrix_YF2_2 = OPD_E2_Y2.getOPD_Y_inVec().size();
//	real OPDend_Y_2_F1_E2 = OPD_E2_Y2.getOPD_Y_inVec().at(sizeMatrix_YF2_2 - 1);
//	PlotOPD plotOPDY2E2(OPD_E2_Y2);
//	Plot::plotDiagram(plotOPDY2E2.getMatrixToPlotOPD_Y_Plane(), "OPD Y field y = -1");
//	//*****************************************************************************************************************
//	// OPD P_Y in filed x = 1
//	std::vector<LightRayStruct> lightRayAlong_X1_F1_E2 = SequentialRayTracing::lightRayAlongX({ 1.0, 0.0, 0.0 }, 200, 12.0, -1.0, 1.0, 550, 1.0);
//	std::vector<LightRayStruct> lightRayAlong_Y1_F1_E2 = SequentialRayTracing::lightRayAlongY({ 1.0, 0.0, 0.0 }, 200, 12.0, -1.0, 1.0, 550, 1.0);
//	Ray_LLT chiefRay_E2_FX1({ 1.0,0.0,0.0 }, { -1.0,0.0,12.0 }, 550, 1.0);
//	LightRayStruct chiefLightRayFY2_E2(chiefRay_E2_FX1, Light, 1);
//	OPD OPD_E2_X1(exitPupil1, OptSysE2, lightRayAlong_X1_F1_E2, lightRayAlong_Y1_F1_E2, chiefLightRayFY2_E2);
//	// check OPD values Y
//	real OPDstart_X1_F1 = OPD_E2_X1.getOPD_Y_inVec().at(0);
//	real OPDtest1_X1 = OPD_E2_X1.getOPD_Y_inVec().at(1);
//	real OPDtest2_X1 = OPD_E2_X1.getOPD_Y_inVec().at(2);
//	real OPDtest3_X1 = OPD_E2_X1.getOPD_Y_inVec().at(3);
//	unsigned int sizeMatrix_Y2_2 = OPD_E2_X1.getOPD_Y_inVec().size();
//	real OPDend_X1_F1 = OPD_E2_X1.getOPD_Y_inVec().at(sizeMatrix_Y2_2 - 1);
//	PlotOPD plotOPD2_X1(OPD_E2_X1);
//	Plot::plotDiagram(plotOPD2_X1.getMatrixToPlotOPD_X_Plane(), "OPD X field X = 1");
//	//*****************************************************************************************************************
//	// OPD P_Y in filed x = -1
//	std::vector<LightRayStruct> lightRayAlong_X2_F1_E2 = SequentialRayTracing::lightRayAlongX({ -1.0, 0.0, 0.0 }, 200, 12.0, -1.0, 1.0, 550, 1.0);
//	std::vector<LightRayStruct> lightRayAlong_Y2_F1_E2 = SequentialRayTracing::lightRayAlongY({ -1.0, 0.0, 0.0 }, 200, 12.0, -1.0, 1.0, 550, 1.0);
//	Ray_LLT chiefRay_E2_FX2({ -1.0,0.0,0.0 }, { 1.0,0.0,12.0 }, 550, 1.0);
//	LightRayStruct chiefLightRayFX2_E2(chiefRay_E2_FX2, Light, 1);
//	OPD OPD_E2_X2(exitPupil1, OptSysE2, lightRayAlong_X2_F1_E2, lightRayAlong_Y2_F1_E2, chiefLightRayFX2_E2);
//	// check OPD values Y
//	real OPDstart_X2_F1 = OPD_E2_X2.getOPD_Y_inVec().at(0);
//	real OPDtest1_X2 = OPD_E2_X2.getOPD_Y_inVec().at(1);
//	real OPDtest2_X2 = OPD_E2_X2.getOPD_Y_inVec().at(2);
//	real OPDtest3_X2 = OPD_E2_X2.getOPD_Y_inVec().at(3);
//	unsigned int sizeMatrix_X2_2 = OPD_E2_X2.getOPD_Y_inVec().size();
//	real OPDend_X2_F1 = OPD_E2_X2.getOPD_Y_inVec().at(sizeMatrix_X2_2 - 1);
//	PlotOPD plotOPD2_X2(OPD_E2_X2);
//	Plot::plotDiagram(plotOPD2_X2.getMatrixToPlotOPD_X_Plane(), "OPD X field X = -1");


	return true;
}