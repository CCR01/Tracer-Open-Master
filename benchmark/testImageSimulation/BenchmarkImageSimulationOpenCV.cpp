#include "BenchmarkImageSimulationOpenCV.h"
#include "..\..\Analyse\OpticalPathDifference.h"
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\..\LowLevelTracing\Surfaces\ParaxialLens_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DeflectedRayParaxialLens_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\FillAptertureStop\FillApertureStop.h"
#include "..\..\Analyse\Spot.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"

#include "..\..\FillAptertureStop\FillApertureStop.h"
#include"..\..\Image\Images.h"





void BenchmarkSimulationOpenCV::test3()
{


	//optical system
	typedef std::shared_ptr< SurfaceIntersectionRay_LLT > surfacePtr_LLT;
	RefractedRay_LLT refrac;
	DoNothingInteraction_LLT doNothing;
	Absorb_LLT absorb;
	real Air = 1.000269;

	// surfaces of the optical system
	ApertureStop_LLT ApertureStop0E0_S0(1.0, { 0.0,0.0,20.0 }, { 0.0,0.0,1.0 }, 1.0);
	SphericalSurface_LLT S1(/*radius*/22.278792, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 25.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S2(/*radius*/18.213171, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 35.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	SphericalSurface_LLT S3(/*radius*/10.98016686, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 45.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	SphericalSurface_LLT S4(/*radius*/32.1826354, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 55.0 },
		/*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	PlanGeometry_LLT PlanS5(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);


	surfacePtr_LLT ApertureStop_ptr = ApertureStop0E0_S0.clone();
	surfacePtr_LLT S1_ptr = S1.clone();
	surfacePtr_LLT S2_ptr = S2.clone();
	surfacePtr_LLT S3_ptr = S3.clone();
	surfacePtr_LLT S4_ptr = S4.clone();
	surfacePtr_LLT S5_ptr = PlanS5.clone();

	// build opitcal system
	OpticalSystem_LLT OptSysE0;
	OptSysE0.fillVectorSurfaceAndInteractingData(0, ApertureStop_ptr, doNothing.clone());
	OptSysE0.fillVectorSurfaceAndInteractingData(1, S1_ptr, refrac.clone());
	OptSysE0.fillVectorSurfaceAndInteractingData(2, S2_ptr, refrac.clone());
	OptSysE0.fillVectorSurfaceAndInteractingData(3, S3_ptr, refrac.clone());
	OptSysE0.fillVectorSurfaceAndInteractingData(4, S4_ptr, refrac.clone());
	OptSysE0.fillVectorSurfaceAndInteractingData(5, S5_ptr, refrac.clone());


	// test the system
	SequentialRayTracing seqTraceE0(OptSysE0);
	Light_LLT Light;
	Light.setWavelength(550.0);
	/*FillApertureStop fillAperStopE0({ 0.0,0.0,0.0 },1.0,{ 0.0,0.0,20.0 },{ 0.0,0.0,1.0 }, 8,10,1.0,Light);
	seqTraceE0.seqRayTracingWithVectorOfLightRays(fillAperStopE0.getVectorWithLightRays());
	Spot spotE0(seqTraceE0.getAllInterPointsAtSurf_i(5), seqTraceE0.getAllInterPointsAtSurf_i(5).at(0));
	spotE0.getRMS_mm();*/
	real rms = 0.002287145;
	real Mag = 0.7033667;
	double objectSemiHeight = 2;
	double imgHeight = Mag * objectSemiHeight;

	Mat IMG = imread("elefant_sharp_squared_210x210.png", CV_LOAD_IMAGE_COLOR);
	ImageSimulationFunctions Functions(IMG, 6);
	std::cout << "image is loaded" << std::endl;

	

	std::cout << "start OTF calculation" << std::endl;

	/*Mat OPD1 = readCMatFromTxt("D:\OPD(0,0).txt");
	Mat OPD2 = readCMatFromTxt("D:\OPD(0,1).txt");
	Mat OPD3 = readCMatFromTxt("D:\OPD(0,-1).txt");
	Mat OPD4 = readCMatFromTxt("D:\OPD(1,0).txt");
	Mat OPD5 = readCMatFromTxt("D:\OPD(1,1).txt");
	Mat OPD6 = readCMatFromTxt("D:\OPD(1,-1).txt");
	Mat OPD7 = readCMatFromTxt("D:\OPD(-1,0).txt");
	Mat OPD8 = readCMatFromTxt("D:\OPD(-1,1).txt");
	Mat OPD9 = readCMatFromTxt("D:\OPD(-1,-1).txt");
	

	Mat PSF1 = Functions.calcPSF(OPD1);
	Mat PSF2 = Functions.calcPSF(OPD2);
	Mat PSF3 = Functions.calcPSF(OPD3);
	Mat PSF4 = Functions.calcPSF(OPD4);
	Mat PSF5 = Functions.calcPSF(OPD5);
	Mat PSF6 = Functions.calcPSF(OPD6);
	Mat PSF7 = Functions.calcPSF(OPD7);
	Mat PSF8 = Functions.calcPSF(OPD8);
	Mat PSF9 = Functions.calcPSF(OPD9);*/

	
	Mat PSF1 = readCMatFromTxt("D:/PSF(0,0).txt");
	Mat PSF2 = readCMatFromTxt("D:/PSF(0,1).txt");
	Mat PSF3 = readCMatFromTxt("D:/PSF(0,-1).txt");
	Mat PSF4 = readCMatFromTxt("D:/PSF(1,0).txt");
	Mat PSF5 = readCMatFromTxt("D:/PSF(1,1).txt");
	Mat PSF6 = readCMatFromTxt("D:/PSF(1,-1).txt");
	Mat PSF7 = readCMatFromTxt("D:/PSF(-1,0).txt");
	Mat PSF8 = readCMatFromTxt("D:/PSF(-1,1).txt");
	Mat PSF9 = readCMatFromTxt("D:/PSF(-1,-1).txt");
	
	Mat OTF1 = Functions.calcFFT(PSF1);
	Mat OTF2 = Functions.calcFFT(PSF2);
	Mat OTF3 = Functions.calcFFT(PSF3);
	Mat OTF4 = Functions.calcFFT(PSF4);
	Mat OTF5 = Functions.calcFFT(PSF5);
	Mat OTF6 = Functions.calcFFT(PSF6);
	Mat OTF7 = Functions.calcFFT(PSF7);
	Mat OTF8 = Functions.calcFFT(PSF8);
	Mat OTF9 = Functions.calcFFT(PSF9);

	std::cout << "end OTF calculation" << std::endl;
	

	////vector with OTF grids
	//std::vector<std::vector<Mat>> OTF_grids = Functions.OTFGrids(OTF8, OTF2, OTF5, OTF7, OTF1, OTF4, OTF9, OTF3, OTF6);
	////vector with PSF grids
	//std::cout << "OTF Grids are ready" << std::endl;
	//std::vector<std::vector<Mat>> PSF_grids = Functions.PSFGrids(OTF_grids, imgHeight, rms);


	//cv::Mat psf = PSF_grids[0][0];
	//showImg("test psf", psf);
	//std::string typePSF = Functions.getTypeCvMat(psf);
	//std::string typeIma = Functions.getTypeCvMat(IMG);
	//std::vector<std::vector<Mat>> objectGrid = Functions.getObjectGrids();
	//std::string typeObjGrid = Functions.getTypeCvMat(objectGrid[0][0]);
	//
	//std::cout << "PSF Grids are calculated from OTF grids" << std::endl;
	//std::vector<std::vector<Mat>> Convolution = Functions.ConvolutionGridsFunction(PSF_grids);
	//
	std::vector<std::vector<Mat>> modified_PSF_grids;
	std::vector<cv::Mat> psf7;
	psf7.push_back(PSF7);
	modified_PSF_grids.push_back(psf7);
	std::vector<std::vector<Mat>> Convolution = Functions.ConvolutionGridsFunction(modified_PSF_grids);

	std::cout << "Convolution between Object and PSF is done" << std::endl;
	Mat SimulatedIMG = Functions.SimulatedImg(Convolution);
	std::cout << "Simulated image is ready" << std::endl << std::endl;

	showImg("original Image", IMG);
	
	showImg("Simulated Image", SimulatedIMG);


}