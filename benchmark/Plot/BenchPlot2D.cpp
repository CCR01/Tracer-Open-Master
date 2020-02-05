#include "BenchPlot2D.h"

#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\..\Plot\Plot.h"

#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\ReflectionRay_LLT.h"

#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ParaxialLens_LLT.h"

#include "..\..\LowLevelTracing\Interaction\DeflectedRayParaxialLens_LLT.h"


bool BechmarkPlot2D::checkMethodesPlot2D()
{ 
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	ReflectionRay_LLT reflect;
	

		// surface 0
		SphericalSurface_LLT S00(/*radius*/5.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,5.0 },	/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
		// surface 1
		SphericalSurface_LLT S10(/*radius*/6.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,10.0 },	/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
		// surface 2
		PlanGeometry_LLT S20(/*semiHeight*/ 3.0, /*Apex*/{ 0.0,0.0,20.0 }, /*Direction*/{ 0.0,4.0,-10.0 }, /*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);
		// surface 3
		PlanGeometry_LLT S30(/*semiHeight*/ 3.0, /*Apex*/{ 0.0,7.4,12.5 }, /*Direction*/{ 0.0,-10.0,4.0 }, /*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);
		// surface 4
		SphericalSurface_LLT S40(/*radius*/8.0, /*semiHeight*/2.0, /*Apex of the sphere*/{ 0.0,-3.0,12.2 },	/*Direction*/ VectorStructR3{ 0.0, -1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
		// surface 5
		SphericalSurface_LLT S50(/*radius*/8.0, /*semiHeight*/2.0, /*Apex of the sphere*/{ 0.0,-6.0,12.2 },	/*Direction*/ VectorStructR3{ 0.0,1.0, 0.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
		// surface 6
		PlanGeometry_LLT S60(/*semiHeight*/ 3.0, /*Apex*/{ 0.0,-11.5,12.5 }, /*Direction*/{ 0.0,-1.0,0.0 }, /*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);
	
	
		OpticalSystem_LLT OptSysE0;
		OptSysE0.fillVectorSurfaceAndInteractingData(0, &S00, refrac.clone());
		OptSysE0.fillVectorSurfaceAndInteractingData(1, &S10, refrac.clone());
		OptSysE0.fillVectorSurfaceAndInteractingData(2, &S20, reflect.clone());
		OptSysE0.fillVectorSurfaceAndInteractingData(3, &S30, reflect.clone());
		OptSysE0.fillVectorSurfaceAndInteractingData(4, &S40, refrac.clone());
		OptSysE0.fillVectorSurfaceAndInteractingData(5, &S50, refrac.clone());
		OptSysE0.fillVectorSurfaceAndInteractingData(6, &S60, absorb.clone());
	
		OptSysE0.fillVectorToPlot2D(0, &S00);
		OptSysE0.fillVectorToPlot2D(1, &S10);
		OptSysE0.fillVectorToPlot2D(2, &S20);
		OptSysE0.fillVectorToPlot2D(3, &S30);
		OptSysE0.fillVectorToPlot2D(4, &S40);
		OptSysE0.fillVectorToPlot2D(5, &S50);
		OptSysE0.fillVectorToPlot2D(6, &S60);
		
		SequentialRayTracing SeqTraceE0(OptSysE0);
		std::vector<LightRayStruct> lightRayAlong_Y0 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 7, 5.0, -1.0, 1.0, 550, 1.0);
		SeqTraceE0.seqRayTracingWithVectorOfLightRays(lightRayAlong_Y0);
	
		cv::Mat image0(800, 800, CV_8UC3, cv::Scalar(255, 255, 255));
		
	
		//*************************************************************************
		// Plot the system
		Plot2D plot2D0(OptSysE0, SeqTraceE0, image0, 30,1,8);
		plot2D0.plotOpticalSystem2D();
		plot2D0.plotRays();
		PlotCarsten::plotDiagram(image0, "optical system 0");
		PlotCarsten::saveImage(image0, "OpticalSystem.jpg");
		//*************************************************************************

		// surface 0
		SphericalSurface_LLT S01(/*radius*/5.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,1.0,5.0 },	/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
		// surface 1
		SphericalSurface_LLT S11(/*radius*/7.0, /*semiHeight*/3.0, /*Apex of the sphere*/{ 0.0,0.0,10.0 },	/*Direction*/ VectorStructR3{ 0.0, -1.76, -10.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
		//surface 2
		ParaxialLens_LLT S21(/*semi Height*/ 3.0, /*apex*/{ 0.0,-1.0,15.0 }, /*direction*/{ 0.0,-17.63,100.0 }, /*focallength*/ 5.0, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
		DeflectedRayParaxialLens_LLT deflectS21(S21.getInfosForDefelction());
		// surface 3
		PlanGeometry_LLT S13(/*semiHeight*/ 3.0, /*Apex*/{ 0.0,0.0,20.0 }, /*Direction*/{ 0.0,0.0,-1.0 }, /*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);
	
		OpticalSystem_LLT OptSysE1;
		OptSysE1.fillVectorSurfaceAndInteractingData(0, &S01, refrac.clone());
		OptSysE1.fillVectorSurfaceAndInteractingData(1, &S11, refrac.clone());
		OptSysE1.fillVectorSurfaceAndInteractingData(2, &S21, deflectS21.clone());
		OptSysE1.fillVectorSurfaceAndInteractingData(3, &S13, absorb.clone());
	
		OptSysE1.fillVectorToPlot2D(0, &S01);
		OptSysE1.fillVectorToPlot2D(1, &S11);
		OptSysE1.fillVectorToPlot2D(2, &S21);
		OptSysE1.fillVectorToPlot2D(3, &S13);
	
	
		SequentialRayTracing SeqTraceE1(OptSysE1);
		std::vector<LightRayStruct> lightRayAlong_Y1 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 3, 5.0, -1.0, 1.0, 550, 1.0);
		SeqTraceE1.seqRayTracingWithVectorOfLightRays(lightRayAlong_Y1);
	
		cv::Mat image1(800, 800, CV_8UC3, cv::Scalar(255, 255, 255));
	
		//*************************************************************************
//		// Plot the system
//		Plot2D plot2D1(OptSysE1, SeqTraceE1, image1, 30,1,8);
//		plot2D1.plotOpticalSystem2D();
//		plot2D1.plotRays();
//		Plot::plotDiagram(image1, "optical system 1");
//		//*************************************************************************

		// Plot optic design

		// surface 0
		SphericalSurface_LLT S02(/*radius*/200.0, /*semiHeight*/35.0, /*Apex of the sphere*/{ 0.0,0.0,20.0 },	/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
		// surface 1
		SphericalSurface_LLT S12(/*radius*/180.0, /*semiHeight*/35.0, /*Apex of the sphere*/{ 0.0,0.0,30.0 },	/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
		
		// surface 2
		SphericalSurface_LLT S22(/*radius*/160.0, /*semiHeight*/35.0, /*Apex of the sphere*/{ 0.0,0.0,35.0 },	/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
		// surface 3
		SphericalSurface_LLT S32(/*radius*/120.0, /*semiHeight*/35.0, /*Apex of the sphere*/{ 0.0,0.0,55.0 },	/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
		
		// surface 4
		SphericalSurface_LLT S42(/*radius*/160.0, /*semiHeight*/25.0, /*Apex of the sphere*/{ 0.0,0.0,60.0 },	/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
		// surface 5
		SphericalSurface_LLT S52(/*radius*/80.0, /*semiHeight*/25.0, /*Apex of the sphere*/{ 0.0,0.0,80.0 },	/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
		
		// surface 6
		SphericalSurface_LLT S62(/*radius*/140.0, /*semiHeight*/20.0, /*Apex of the sphere*/{ 0.0,0.0,85.0 },	/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
		// surface 7
		SphericalSurface_LLT S72(/*radius*/120.0, /*semiHeight*/20.0, /*Apex of the sphere*/{ 0.0,0.0,95.0 },	/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
		
		// surface 8
		SphericalSurface_LLT S82(/*radius*/40.0, /*semiHeight*/15.0, /*Apex of the sphere*/{ 0.0,0.0,100.0 },	/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
		// surface 9
		SphericalSurface_LLT S92(/*radius*/99999.0, /*semiHeight*/15.0, /*Apex of the sphere*/{ 0.0,0.0,110.0 },	/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);

		// surface 6
		PlanGeometry_LLT S102(/*semiHeight*/ 3.0, /*Apex*/{ 0.0,0.0,113.2 }, /*Direction*/{ 0.0,0.0,1.0 }, /*refIndexSideA*/  1.0,  /*refIndexSideB*/ 1.0);


		OpticalSystem_LLT OptSysE2;
		OptSysE2.fillVectorSurfaceAndInteractingData(0, &S02, refrac.clone());
		OptSysE2.fillVectorSurfaceAndInteractingData(1, &S12, refrac.clone());
		OptSysE2.fillVectorSurfaceAndInteractingData(2, &S22, reflect.clone());
		OptSysE2.fillVectorSurfaceAndInteractingData(3, &S32, reflect.clone());
		OptSysE2.fillVectorSurfaceAndInteractingData(4, &S42, refrac.clone());
		OptSysE2.fillVectorSurfaceAndInteractingData(5, &S52, refrac.clone());
		OptSysE2.fillVectorSurfaceAndInteractingData(6, &S62, absorb.clone());
		OptSysE2.fillVectorSurfaceAndInteractingData(7, &S72, reflect.clone());
		OptSysE2.fillVectorSurfaceAndInteractingData(8, &S82, refrac.clone());
		OptSysE2.fillVectorSurfaceAndInteractingData(9, &S92, refrac.clone());
		OptSysE2.fillVectorSurfaceAndInteractingData(10, &S102, absorb.clone());

		OptSysE2.fillVectorToPlot2D(0, &S02);
		OptSysE2.fillVectorToPlot2D(1, &S12);
		OptSysE2.fillVectorToPlot2D(2, &S22);
		OptSysE2.fillVectorToPlot2D(3, &S32);
		OptSysE2.fillVectorToPlot2D(4, &S42);
		OptSysE2.fillVectorToPlot2D(5, &S52);
		OptSysE2.fillVectorToPlot2D(6, &S62);
		OptSysE2.fillVectorToPlot2D(7, &S72);
		OptSysE2.fillVectorToPlot2D(8, &S82);
		OptSysE2.fillVectorToPlot2D(9, &S92);
		OptSysE2.fillVectorToPlot2D(10, &S102);

//		SequentialRayTracing SeqTraceE2(OptSysE2);
//		std::vector<LightRayStruct> lightRayAlong_Y2 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 7, 10.0, -1.0, 1.0, 550, 1.0);
//		SeqTraceE2.seqRayTracingWithVectorOfLightRays(lightRayAlong_Y2);
//
//		cv::Mat image2(800, 800, CV_8UC3, cv::Scalar(255, 255, 255));
//
//
//		//*************************************************************************
//		// Plot the system
//		Plot2D plot2D2(OptSysE2, SeqTraceE2, image2, 30,1,8);
//		plot2D2.plotOpticalSystem2D();
//		plot2D2.plotRays();
//		Plot::plotDiagram(image2, "optical system 2");
//		//*************************************************************************

	return true;
}