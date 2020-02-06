#pragma once

#include <qwt_plot_rescaler.h>
#include <qwt_round_scale_draw.h>
#include <qapplication.h>
#include <qwt_plot.h>

#include <ctime>
#include "..\SequentialRayTracing\SequentialRayTracer.h"
#include "main_LLT.h"
#include "Light_LLT.h"
#include "Interaction\InteractionRay_LLT.h"
#include "..\FillAptertureStop\FillApertureStop.h"
#include "..\benchmark\FillAS\BenchmarkFillAS.h"
#include "../benchmark/SequentialRayTracer/BenchmarkSequentialRayTracer.h"
#include "../benchmark//ParaxialLens_LLT/BenchmarkParaxialLens_LLT.h"
#include "Surfaces\AsphericalSurface_LLT.h"
#include "BaseTransformation_LLT.h"
#include "Surfaces\PlanGeometry_LLT.h"
#include "../benchmark/SphericalSurface/BenchmarkSphericalLens.h"
#include "Interaction\ReflectionRay_LLT.h"
#include "Surfaces\ApertureStop_LLT.h"
#include "Interaction\DoNothingInteraction_LLT.h"
#include "Interaction\Absorb_LLT.h"
#include "..\RayAiming\RayAiming.h"
#include "../SurfaceElements/SphericalElement.h"
#include "../Analyse/Spot.h"
#include "Surfaces\ParaxialLens_LLT.h"
#include "Interaction\DeflectedRayParaxialLens_LLT.h"
#include "..\benchmark\RayAiming\BenchmarkRayAiming.h"
#include "..\benchmark\Math\BechmarkMath.h"
#include "..\benchmark\Plan\BenchmarkPlanSurface.h"
#include "..\benchmark\BenchAnalyse\BenchmarkOpticalPathDifference.h"
#include "..\benchmark\Plan\BenchmarkPlanSurface.h"
#include "..\benchmark\OpticalSystem\BenchmarkOpticalSystem.h"
#include "..\benchmark\Plot\BenchPlotSpotDiagram.h"
#include "..\benchmark\Plot\BenchPlotOPD.h"
#include "..\benchmark\Plot\BenchPlot2D.h"

#include "..\benchmark\Element\SphericalElement\BenchSphericalElement.h"
#include "..\benchmark\Element\OpticalSystemElement\BenchOpticalSystemElement.h"

#include "..\benchmark\BenchAnalyse\BenchmarkExitPupilCalculation.h"

#include "..\benchmark\ComplexOptSys\BenchmarkComplexOptSys.h"
#include "..\benchmark\Element\SphericalElement\BenchSphericalElement.h"

#include "..\benchmark\Glasses\BenchGlasses.h"

#include "..\benchmark\BenchAnalyse\TestGlobalOPD.h"

#include "..\benchmark\BenchAnalyse\testPSF.h"

#include "..\benchmark\ZemaxExamples\Objectives\Cooke40DegreeField.h"

//#include "..\benchmark\Glasses\BenchGlasses.h"

#include "..\benchmark\TestLensCatalog\TestLensCatalogEO.h"

#include "..\benchmark\AsphericalSurface_LLT\TestAsphericalSurface_LLT.h"

#include "..\benchmark\Optimizer\BenchmarkZemaxTest.h"

#include "..\benchmark\RMScalculation\testRMS_Spot.h"


#include "..\benchmark\testCompareTwoImages\testCompareTwoImagesAndImprove.h"

#include "..\benchmark\testImages\testImages.h"

#include "..\benchmark\testImageProcessing\TestImageProcessing.h"

#include "..\benchmark\testImproveImageQuality\testImproveImageQuality.h"

#include "..\benchmark\BenchAnalyse\BenchmarkImageSimulation.h"

#include "..\benchmark\testSeidelCoefficients\testSeidelCoefficients.h"

#include "..\benchmark\testOptimizer_Paper\testOptimizer_Paper_P0.h"
#include "..\benchmark\testOptimizer_Paper\testOptimizer_Paper_P1.h"

#include "..\benchmark\nonLinearityRMS_SpotRadius\nonLinearityRMS_SpotRadius.h"

#include "..\benchmark\Optimizer\localOptimizer\testLocalOptimizer_BM.h"

#include "..\benchmark\testCalculateParaxialDistances\testCalculateParaxialDistances.h"

#include "..\benchmark\Optimizer\testBuildSysForCombination.h"

#include "..\benchmark\testCardinalPoints\testCardinalPoints.h"

#include "..\benchmark\testQwtPlots\TestRayTracingQwtPlot.h"

#include "..\benchmark\testQwtPlots\TestSpotDiagramQwtPlot.h"


#include "..\benchmark\testQwtPlots\TestOPDQwtPlot.h"


#include "..\benchmark\testSeidelCombinations\testSeidelCombinations.h"

#include "..\benchmark\testLensReplace\testLenseReplace.h"

#include "..\benchmark\testEvaluateManyOptSys_RayTracing\testEvaluateManyOptSys_RayTracing.h"

#include"..\benchmark\testCalcCombinationVector\testCalcCombinationVector_Seidel.h"

#include "..\benchmark\testCalcCombinationVector\testCalcCombinationVector_Paraxial.h"

#include "..\benchmark\IOC2020_Dresten\IOC2020_Dresden.h"

#include "..\TOM(Logo)\TOM(Logo).h"

int main()
{


	// *****************************************************************************************************************
	// Benchmark for traceropen
	// *****************************************************************************************************************
	std::vector<bool> workTheSystem;
	// *****************************************************************************************************************

	// plot TOM logo
	TOM_LOGO tomLogo;
	bool checkOlotLogoTOM = tomLogo.plotTOM_Logo();
	workTheSystem.push_back(checkOlotLogoTOM);

	//// test replace lenses for IOC 2020
	//IOC2020_Dresden system_IOC2020_Dresden;
	//bool checkSysIOC2020 = system_IOC2020_Dresden.systemFor_IOC2020_Dresten();
	//workTheSystem.push_back(checkSysIOC2020);
	
	//// RayAiming
	//BenchmarkRayAiming checkRayAiming;
	//bool RayAiming = checkRayAiming.checkRayAimingSuperFct();
	//workTheSystem.push_back(RayAiming);

	//// lens replace
	//testLensReplace testLensRep;
	//bool chekerLensReplace = testLensRep.testLensReplace_superFct();
	//workTheSystem.push_back(chekerLensReplace);
	
	// ***
	//// test seidel coeffizients
	//testSeidelCoefficients testSeidelCoeff;
	//bool checkSeidelCoeff = testSeidelCoeff.checkCalculationOfSeidelCoefficients();
	//workTheSystem.push_back(checkSeidelCoeff);

	//// test calculate paraxial distance
	//testCalcPraxialDistances testCalcParaDis;
	//bool checkCalcParaDis = testCalcParaDis.checkCalcParaxialDistances();
	//workTheSystem.push_back(checkCalcParaDis);
	//
	//// test build opt sys ele for combinations
	//testBuildSysForCombination testBuildSysCom;
	//bool checkBuildSysCom = testBuildSysCom.checkBuiildSysForCom_SUPERFUNCTION();
	//workTheSystem.push_back(checkBuildSysCom);
	//
	//// test calc combination vector seidel
	//testCalcCombiVector_Seidel testCalcComVec_Seidel;
	//bool checkCalcComVec_Seidel = testCalcComVec_Seidel.testCalcCombiVec_Seidel_superFct();
	//workTheSystem.push_back(checkCalcComVec_Seidel);
	////
	//// test seidel combinations
	//testSeidelCombinations testSeidelCom;
	//bool checkSeidelCom = testSeidelCom.testSeidelCom_superFct();
	//workTheSystem.push_back(checkSeidelCom);
	//
	//// test calc combination vector paraxial
	//testCalcComVec_Paraxial testCaComVec_Paraxial;
	//bool checkCalculateCombinationVector_Paraxial = testCaComVec_Paraxial.testCalcComVec_SuperFct_Paraxial();
	//workTheSystem.push_back(checkCalculateCombinationVector_Paraxial);
	//
	//// test evaluate many opt sys ray tracing
	//testEvaluateManyOptSys_RayTracing testEvaManyOptSys_RayTracing;
	//bool checkEvaOptSys_RT = testEvaManyOptSys_RayTracing.testEvaManyOptSys_RayTracing_SuperFct();
	//workTheSystem.push_back(checkEvaOptSys_RT);

	// ***

	////// test compare two images and improve
	//testCompareTwoImagesAndImprove testCompTwoImaAndImpro;
	//bool checkCompTwoImaAndImpro = testCompTwoImaAndImpro.testMethodesCompageTwoImagesAndImprove();
	//workTheSystem.push_back(checkCompTwoImaAndImpro);

	//TestImages testIma;
	//bool checkImages = testIma.checkMethodesNamespaceImages();
	//workTheSystem.push_back(checkImages);

	////////test image processing
	//TestImageProcessing testImaProc;
	//bool checkImaProc = testImaProc.checkImageProcessing();
	//workTheSystem.push_back(checkImaProc);

	//// test how to improve the image quality
	//testImproveImageQuality testImproveImaQua;
	//bool checkImproveImaQua = testImproveImaQua.checkImproveImageQuality();
	//workTheSystem.push_back(checkImproveImaQua);

	////Benchmark img simulation
	//BenchmarkImageSimulation checkImgSim;
	//bool ImageSimulation = checkImgSim.checkMethodesImgSim();
	//workTheSystem.push_back(ImageSimulation);

	//// check optimizer
	//BenchmarkZemaxTest testOpimizer;
	//bool checkOptimizer = testOpimizer.checkMethodesZemaxTest();
	//workTheSystem.push_back(checkOptimizer);

	////// check optimizer for paper P0
	//testOptimizer_Paper_P0 checkOptimizer_paper_P0;
	//bool checkOptim_paper_P0 = checkOptimizer_paper_P0.checkTestOptimizer_paper_P0();
	//workTheSystem.push_back(checkOptim_paper_P0);

	////// check optimizer for paper P1
	//testOptimizer_Paper_P1 checkOptimizer_paper_p1;
	//bool checkOptim_paper_p1 = checkOptimizer_paper_p1.checkTestOptimizer_paper_p1(25.0,85.0,0.5,0.0,30.0,0.5,25.0,85.0,0.5,0.5);
	//workTheSystem.push_back(checkOptim_paper_p1);

	////// show non linearity of optical system
	//nonLinearityRMS_SpotRadius showNonLineE0;
	//bool checkNonLineE0 = showNonLineE0.showNonLinearityRMS_SpotRadius(15.0, 20.0, 0.01, "nonLinearityRMSspot");
	//workTheSystem.push_back(checkNonLineE0);

	//// show non linearity of optimization
	//nonLinearityRMS_SpotRadius showNonLineE1;
	//bool checkNonLineE1 = showNonLineE1.showNonLinearityRMS_SpotRadius(16.52, 16.54, 0.00001, "nonLinearityRMSspotsSmallerSteps");
	//workTheSystem.push_back(checkNonLineE1);

	////// check local optimization bisection methode
	//testLocalOpti_BM checkLocalOpti_BM;
	//bool checkBM = checkLocalOpti_BM.checkLocalOpti_BM();
	//workTheSystem.push_back(checkBM);
	   


	//// check aspherical surface LLT
	//TestAsphericalSurface_LLT testAspSur_LLT;
	//bool checkAsphericalSurface_LLT = testAspSur_LLT.checkAsphericalSurface_LLT();
	//workTheSystem.push_back(checkAsphericalSurface_LLT);

	//Optical Path Difference
	//BenchmarkOpticalPathDifference checkOPD;
	//bool OPD = checkOPD.checkMethodesOPD();
	//workTheSystem.push_back(OPD);

	////	//Benchmark complex optical system
	//BechmarkComplexOpticalSystem BenchComOptSys;
	//bool checkComOptSys = BenchComOptSys.checkComplexOpticalSystem();
	//workTheSystem.push_back(checkComOptSys);



	////optical system element
	//BenchOpticalSystemElement BenchOptSys;
	//bool checkOptSysElement = BenchOptSys.checkMethodesOpticalSystemElement();
	//workTheSystem.push_back(checkOptSysElement);

	//// test lens calalog from edmund optics
	//TestLensCatalogEO testLensCataEO;
	//bool checkLensCataEO_TwoSurfaces_1 = testLensCataEO.testCatalogEO_TwoSurfaces_1();
	//workTheSystem.push_back(checkLensCataEO_TwoSurfaces_1);
	//bool checkLensCataEO_TwoSurfaces_2 = testLensCataEO.testCatalogEO_TwoSurfaces_2();
	//workTheSystem.push_back(checkLensCataEO_TwoSurfaces_2);
	//bool checkLensCataEO_TwoSurfaces_3 = testLensCataEO.testCatalogEO_TwoSurfaces_3();
	//workTheSystem.push_back(checkLensCataEO_TwoSurfaces_3);
	//bool checkLensCataEO_ThreeSurfaces = testLensCataEO.testCatalogEO_ThreeSurfaces();
	//workTheSystem.push_back(checkLensCataEO_ThreeSurfaces);
	//bool checkLensCataEO_doub_conc_lens = testLensCataEO.testCatalogEO_DCV();
	//workTheSystem.push_back(checkLensCataEO_doub_conc_lens);
	//bool checkLensCataEO_PCV = testLensCataEO.testcatalogEO_PCV();
	//workTheSystem.push_back(checkLensCataEO_PCV);

	////Benchmark Glasses
	//BenchmarkGlasses BenchGlasses;
	//bool checkGlasses = BenchGlasses.checkGlasses();
	//workTheSystem.push_back(checkGlasses);

	// *****************************************************************************************************************
	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	if (checker == true) std::cout << "The system works perfectly\n";
	else std::cout << "There is a fuck fuck fuck fuck fuck in the system\n" << std::endl;
	//*****************************************************************************************************************

	int i;
	std::cout << "insert a rendom number" << std::endl;
	std::cin >> i;

	return 0;
}


//int main(int argc, char **argv)
//{
//	QApplication a(argc, argv);
//	std::vector<bool> workTheSystem;
//
////	// *****************************************************************************************************************
////	// *** Aya ***
////
////	testRayTracingQwtPlot checkRayTracingPlot;
////	testOPDQwtPlot checkOPDPlot;
////	testSpotDiagramQwtPlot checkSpotPlot;
////	bool checkCardinal_superFct_RayTracing = checkRayTracingPlot.superFuncTestRayTracingQwtPlot();
////	workTheSystem.push_back(checkCardinal_superFct_RayTracing);
////	bool checkCardinal_superFct_OPD = checkOPDPlot.superFuncTestOPDQwtPlot();
////	workTheSystem.push_back(checkCardinal_superFct_OPD);
////	bool checkCardinal_superFct_SpotDiagram = checkSpotPlot.superFuncTestSpotDiagramQwtPlot();
////	workTheSystem.push_back(checkCardinal_superFct_SpotDiagram);
////
////	// *****************************************************************************************************************
//
//	// *****************************************************************************************************************
//	// Benchmark for traceropen
//	// *****************************************************************************************************************
//	
//	// *****************************************************************************************************************
//
//	// test seidel coeffizients
//	testSeidelCoefficients testSeidelCoeff;
//	bool checkSeidelCoeff = testSeidelCoeff.checkCalculationOfSeidelCoefficients();
//	workTheSystem.push_back(checkSeidelCoeff);
//
//	// test calculate paraxial distance
//	testCalcPraxialDistances testCalcParaDis;
//	bool checkCalcParaDis = testCalcParaDis.checkCalcParaxialDistances();
//	workTheSystem.push_back(checkCalcParaDis);
//
//	// test build opt sys ele for combinations
//	testBuildSysForCombination testBuildSysCom;
//	bool checkBuildSysCom = testBuildSysCom.checkBuiildSysForCom_SUPERFUNCTION();
//	workTheSystem.push_back(checkBuildSysCom);
//
//	// test calc combinationVector
//	testCalcComVec testCaComVec;
//	bool checkCalculateCombinationVector = testCaComVec.testCalcComVec_SuperFct();
//	workTheSystem.push_back(checkCalculateCombinationVector);
//
//	// test seidel combinations
//	testSeidelCombinations testSeidelCom;
//	bool checkSeidelCom = testSeidelCom.testSeidelCom_superFct();
//	workTheSystem.push_back(checkSeidelCom);
//	
//	////// test calculation of seidel coeff
//	//testSeidelCoefficients checkCalcSeidelCoeff;
//	//bool checkCalcSeidel = checkCalcSeidelCoeff.checkCalculationOfSeidelCoefficients();
//	//workTheSystem.push_back(checkCalcSeidel);
//	//
//	//// test calculate paraxial distance
//	//testCalcPraxialDistances testCalcParaDis;
//	//bool checkCalcParaDis = testCalcParaDis.checkCalcParaxialDistances();
//	//workTheSystem.push_back(checkCalcParaDis);
//	//
//	//// test build opt sys ele for combinations
//	//testBuildSysForCombination testBuildSysCom;
//	//bool checkBuildSysCom = testBuildSysCom.checkBuiildSysForCom_SUPERFUNCTION();
//	//workTheSystem.push_back(checkBuildSysCom);
//
//
//	////// test compare two images and improve
//	//testCompareTwoImagesAndImprove testCompTwoImaAndImpro;
//	//bool checkCompTwoImaAndImpro = testCompTwoImaAndImpro.testMethodesCompageTwoImagesAndImprove();
//	//workTheSystem.push_back(checkCompTwoImaAndImpro);
//
//	//TestImages testIma;
//	//bool checkImages = testIma.checkMethodesNamespaceImages();
//	//workTheSystem.push_back(checkImages);
//
//	////////test image processing
//	//TestImageProcessing testImaProc;
//	//bool checkImaProc = testImaProc.checkImageProcessing();
//	//workTheSystem.push_back(checkImaProc);
//
//	//// test how to improve the image quality
//	//testImproveImageQuality testImproveImaQua;
//	//bool checkImproveImaQua = testImproveImaQua.checkImproveImageQuality();
//	//workTheSystem.push_back(checkImproveImaQua);
//
//	////Benchmark img simulation
//	//BenchmarkImageSimulation checkImgSim;
//	//bool ImageSimulation = checkImgSim.checkMethodesImgSim();
//	//workTheSystem.push_back(ImageSimulation);
//
//	
//	////// check optimizer for paper P0
//	//testOptimizer_Paper_P0 checkOptimizer_paper_P0;
//	//bool checkOptim_paper_P0 = checkOptimizer_paper_P0.checkTestOptimizer_paper_P0();
//	//workTheSystem.push_back(checkOptim_paper_P0);
//
//	
//	////// check optimizer for paper P1
//	//testOptimizer_Paper_P1 checkOptimizer_paper_p1;
//	//bool checkOptim_paper_p1 = checkOptimizer_paper_p1.checkTestOptimizer_paper_p1(50.0,60.0,1.0,0.0,5.0,1.0,50.0,60.0,1.0,0.5);
//	//workTheSystem.push_back(checkOptim_paper_p1);
//
//	////// show non linearity of optical system
//	//nonLinearityRMS_SpotRadius showNonLineE0;
//	//bool checkNonLineE0 = showNonLineE0.showNonLinearityRMS_SpotRadius(15.0, 20.0, 0.01, "nonLinearityRMSspot");
//	//workTheSystem.push_back(checkNonLineE0);
//
//	//// show non linearity of optimization
//	//nonLinearityRMS_SpotRadius showNonLineE1;
//	//bool checkNonLineE1 = showNonLineE1.showNonLinearityRMS_SpotRadius(16.52, 16.54, 0.00001, "nonLinearityRMSspotsSmallerSteps");
//	//workTheSystem.push_back(checkNonLineE1);
//
//	////// check local optimization bisection methode
//	//testLocalOpti_BM checkLocalOpti_BM;
//	//bool checkBM = checkLocalOpti_BM.checkLocalOpti_BM();
//	//workTheSystem.push_back(checkBM);
//		
//
//	////// check optimizer
//	//BenchmarkZemaxTest testOpimizer;
//	//bool checkOptimizer = testOpimizer.checkMethodesZemaxTest();
//	//workTheSystem.push_back(checkOptimizer);
//
//	//// check aspherical surface LLT
//	//TestAsphericalSurface_LLT testAspSur_LLT;
//	//bool checkAsphericalSurface_LLT = testAspSur_LLT.checkAsphericalSurface_LLT();
//	//workTheSystem.push_back(checkAsphericalSurface_LLT);
//
//	//Optical Path Difference
//	//BenchmarkOpticalPathDifference checkOPD;
//	//bool OPD = checkOPD.checkMethodesOPD();
//	//workTheSystem.push_back(OPD);
//
//	////	//Benchmark complex optical system
//	//BechmarkComplexOpticalSystem BenchComOptSys;
//	//bool checkComOptSys = BenchComOptSys.checkComplexOpticalSystem();
//	//workTheSystem.push_back(checkComOptSys);
//
//	//// RayAiming
//	//BenchmarkRayAiming checkRayAiming;
//	//bool RayAiming = checkRayAiming.checkRayAimingSuperFct();
//	//workTheSystem.push_back(RayAiming);
//
//	////optical system element
//	//BenchOpticalSystemElement BenchOptSys;
//	//bool checkOptSysElement = BenchOptSys.checkMethodesOpticalSystemElement();
//	//workTheSystem.push_back(checkOptSysElement);
//
//	//// test lens calalog from edmund optics
//	//TestLensCatalogEO testLensCataEO;
//	//bool checkLensCataEO_TwoSurfaces_1 = testLensCataEO.testCatalogEO_TwoSurfaces_1();
//	//workTheSystem.push_back(checkLensCataEO_TwoSurfaces_1);
//	//bool checkLensCataEO_TwoSurfaces_2 = testLensCataEO.testCatalogEO_TwoSurfaces_2();
//	//workTheSystem.push_back(checkLensCataEO_TwoSurfaces_2);
//	//bool checkLensCataEO_TwoSurfaces_3 = testLensCataEO.testCatalogEO_TwoSurfaces_3();
//	//workTheSystem.push_back(checkLensCataEO_TwoSurfaces_3);
//	//bool checkLensCataEO_ThreeSurfaces = testLensCataEO.testCatalogEO_ThreeSurfaces();
//	//workTheSystem.push_back(checkLensCataEO_ThreeSurfaces);
//	//bool checkLensCataEO_doub_conc_lens = testLensCataEO.testCatalogEO_DCV();
//	//workTheSystem.push_back(checkLensCataEO_doub_conc_lens);
//	//bool checkLensCataEO_PCV = testLensCataEO.testcatalogEO_PCV();
//	//workTheSystem.push_back(checkLensCataEO_PCV);
//
//	////Benchmark Glasses
//	//BenchmarkGlasses BenchGlasses;
//	//bool checkGlasses = BenchGlasses.checkGlasses();
//	//workTheSystem.push_back(checkGlasses);
//
//	// *****************************************************************************************************************
//	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
//	if (checker == true) std::cout << "The system works perfectly\n";
//	else std::cout << "There is a fuck fuck fuck fuck fuck in the system\n" << std::endl;
//	//*****************************************************************************************************************
//
//	//int i;
//	//std::cout << "insert a rendom number" << std::endl;
//	//std::cin >> i;
//
//	return a.exec();
//}


////SequentialRayTracing
//BenchmarkSequentialRayTracing checkSeqRayTracing;
//BenchmarkSequentialRayTracing checkSeqRayTracing;
//bool SeqTrace = checkSeqRayTracing.checkMethodesElement();
//bool SeqTrace = checkSeqRayTracing.checkMethodesElement();
//workTheSystem.push_back(SeqTrace);
//workTheSystem.push_back(SeqTrace);
////ParaxialLens
////ParaxialLens
//BenchmarkParaxialLens checkParaxialLens;
//bool ParaLens = checkParaxialLens.checkMethodesParaxialLens_LLT();
//workTheSystem.push_back(ParaLens);
//// FillEntrancePupilWithLightRays
//BenchmarkFillEntrancePupilWithLightRays checkFillEntPupil;
//bool FillEntPupil = checkFillEntPupil.chekMethodesFillEntrancePupilWithLightRays();
//workTheSystem.push_back(FillEntPupil);
//// Math
//	BenchmarkMath checkMath;
//bool Math = checkMath.checkMethodesMath();
//workTheSystem.push_back(Math);





//// Test Cooke 40 Degree Field
//	Cooke40DegreeField testCooke40DegreeField;
//bool checkCooke40DegreeField = testCooke40DegreeField.buildCooke40DegreeField();
//workTheSystem.push_back(checkCooke40DegreeField);
//// SphericalLens
//BenchmarkSphericalLens checkSphericalLens;
//bool sphericalLens = checkSphericalLens.checkMethodesSphericalLens_LLT();
//workTheSystem.push_back(sphericalLens);
//
//// check RMS calc spot
//testRMS_Spot chechCalcRMSspot;
//bool chechRMSspot = chechCalcRMSspot.checkRMScalculationSpot();
//workTheSystem.push_back(chechRMSspot);
//
//// Plan Surface
//BenchmarkePlanSurface checkPlanSurface;
//bool planSurface = checkPlanSurface.checkMethodesPlanSurface();
//workTheSystem.push_back(planSurface);
////Optical System
//BenchmarkOpticalSystem checkOpticalSystem;
//bool opticalSystem = checkOpticalSystem.checkMethodesOpticalSystem();
//workTheSystem.push_back(opticalSystem);
//
////Optical Path Difference
//BenchmarkOpticalPathDifference checkOPD;
//bool OPD = checkOPD.checkMethodesOPD();
//workTheSystem.push_back(OPD);
//
////Plot Spot Diagram
//BenchmarkPlotSpotDiagram checkPlotSporD;
//bool checkPlotSpot = checkPlotSporD.checkMethodesPlotSpotDiagram();
//workTheSystem.push_back(checkPlotSpot);
//
//// 2D plot
//BechmarkPlot2D checkPlot2D;
//bool plot2D = checkPlot2D.checkMethodesPlot2D();
//workTheSystem.push_back(plot2D);
//
//// Plot OPD
//BenchmarkPlotOPD checkPlotOPD_D;
//bool checkPlotOPD = checkPlotOPD_D.checkMethodesPlotOPD();
//workTheSystem.push_back(checkPlotOPD);
//
//
//// spherical element
//BenchSphericalElement BenchSpherElemen;
//bool checkSpherElement = BenchSpherElemen.checkMethodesSphericalElement();
//workTheSystem.push_back(checkSpherElement);
//
////optical system element
//BenchOpticalSystemElement BenchOptSys;
//bool checkOptSysElement = BenchOptSys.checkMethodesOpticalSystemElement();
//workTheSystem.push_back(checkOptSysElement);
//
//BenchmarkPlotOPD checkPlotOPD_D;
//bool checkPlotOPD = checkPlotOPD_D.checkMethodesPlotOPD();
//workTheSystem.push_back(checkPlotOPD);
//
//BenchmarkExitPupilCalculation checkExPupCalc;
//bool checkExPuCal = checkExPupCalc.checkMethodesExitPupilCalculation();
//workTheSystem.push_back(checkExPuCal);
//
///////Benchmark Glasses
////BenchmarkGlasses BenchGlasses;
////bool checkGlasses = BenchGlasses.checkGlasses();
/////workTheSystem.push_back(checkGlasses);
//

//
/// Benchmark Ray Aiming
//	BenchmarkRayAiming checkRayAiming;
//bool RayAiming = checkRayAiming.checkMethodesRayAiming();
//workTheSystem.push_back(RayAiming);
//
//// Benchmark glasses 
//BenchmarkGlasses BenchGlasses;
//bool checkGlasses = BenchGlasses.checkGlasses();
//workTheSystem.push_back(checkGlasses);
//
//BenchSphericalElement BenchSpherElemen;
//bool checkSpherElement = BenchSpherElemen.checkMethodesSphericalElement();
//workTheSystem.push_back(checkSpherElement);
//BenchOpticalSystemElement BenchOptSys;
//bool checkOptSysElement = BenchOptSys.checkMethodesOpticalSystemElement();
//workTheSystem.push_back(checkOptSysElement);
//Updated upstream
//	HEAD
//	/ Test global OPD
//	TestGlobalOPD testGlobalOPD;
//bool checkGlobalOPD = testGlobalOPD.checkMethodesGlobalOPD();
//workTheSystem.push_back(checkGlobalOPD);
//
//// test psf 
//TestPSF testPSF;
//bool checkTestPSF = testPSF.checkMethodesPSF();
//workTheSystem.push_back(checkTestPSF);
//
//
////Test global OPD
//TestGlobalOPD testGlobalOPD;
//bool checkGlobalOPD = testGlobalOPD.checkMethodesGlobalOPD();
//workTheSystem.push_back(checkGlobalOPD);
//
//QApplication a(argc, argv);
//
//
//
//// test lens calalog from edmund optics
//TestLensCatalogEO testLensCataEO;
//bool checkLensCataEO_TwoSurfaces = testLensCataEO.testCatalogEO_TwoSurfaces();
//bool checkLensCataEO_ThreeSurfaces = testLensCataEO.testCatalogEO_ThreeSurfaces();
//workTheSystem.push_back(checkLensCataEO_TwoSurfaces);
//workTheSystem.push_back(checkLensCataEO_ThreeSurfaces);
//
//
//// check Methodes in class FillAS
//BenchmarkFillAS testFillAS;
//bool checkFillAS = testFillAS.chekMethodesFillAS();
//workTheSystem.push_back(checkFillAS);
//






// Aya *******************************************************************
//int main(int argc, char **argv)
//{

	//QApplication a(argc, argv);


	////all the surfaces
	//SphericalSurface_LLT S1(/*radius*/38.73360379131933, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 15.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	//SphericalSurface_LLT S2(/*radius*/10.33817058758478, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 20.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	//SphericalSurface_LLT S3(/*radius*/51.02696739895755, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 22.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	//PlanGeometry_LLT S4(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,27.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	//SphericalSurface_LLT S5(/*radius*/61.48513190056155, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 29.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	//PlanGeometry_LLT S6(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,34.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	//SphericalSurface_LLT S7(/*radius*/13.22318498941039, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 36.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	//PlanGeometry_LLT S8(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,41.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.5, /*refractiveSideB*/ 1.0);
	//SphericalSurface_LLT S9(/*radius*/12.07896133399859, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 43.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.0);
	//SphericalSurface_LLT S10(/*radius*/26.46510860484050, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 48.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.5, /*refIndexSideB*/1.6);
	//SphericalSurface_LLT S11(/*radius*/21.48098096423011, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 53.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.6);
	//SphericalSurface_LLT S12(/*radius*/30.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 55.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.0, /*refIndexSideB*/1.5);
	//SphericalSurface_LLT S13(/*radius*/70.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 60.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, -1.0 }, /*refIndexSideA*/1.6, /*refIndexSideB*/1.5);
	//SphericalSurface_LLT S14(/*radius*/40.0, /*semiHeight*/5.0, /*Apex of the sphere*/{ 0.0, 0.0, 65.0 }, /*Direction*/ VectorStructR3{ 0.0, 0.0, 1.0 }, /*refIndexSideA*/1.6, /*refIndexSideB*/1.0);
	//PlanGeometry_LLT S15(/*semiHeight*/5.0, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ 1.0, /*refractiveSideB*/ 1.0);
	//
	//
	//// build the optical system
	//RefractedRay_LLT refrac;
	//OpticalSystem_LLT optSysE1;
	//optSysE1.fillVectorSurfaceAndInteractingData(0, &S1, refrac.clone());
	//optSysE1.fillVectorSurfaceAndInteractingData(1, &S2, refrac.clone());
	//optSysE1.fillVectorSurfaceAndInteractingData(2, &S3, refrac.clone());
	//optSysE1.fillVectorSurfaceAndInteractingData(3, &S4, refrac.clone());
	//optSysE1.fillVectorSurfaceAndInteractingData(4, &S5, refrac.clone());
	//optSysE1.fillVectorSurfaceAndInteractingData(5, &S6, refrac.clone());
	//optSysE1.fillVectorSurfaceAndInteractingData(6, &S7, refrac.clone());
	//optSysE1.fillVectorSurfaceAndInteractingData(7, &S8, refrac.clone());
	//optSysE1.fillVectorSurfaceAndInteractingData(8, &S9, refrac.clone());
	//optSysE1.fillVectorSurfaceAndInteractingData(9, &S10, refrac.clone());
	//optSysE1.fillVectorSurfaceAndInteractingData(10, &S11, refrac.clone());
	//optSysE1.fillVectorSurfaceAndInteractingData(11, &S12, refrac.clone());
	//optSysE1.fillVectorSurfaceAndInteractingData(12, &S13, refrac.clone());
	//optSysE1.fillVectorSurfaceAndInteractingData(13, &S14, refrac.clone());
	//optSysE1.fillVectorSurfaceAndInteractingData(14, &S15, refrac.clone());
	//
	//Light_LLT light;
	//light.setWavelength(550.0);
	//
	//// fill aperture stop
	//FillApertureStop fillAperStopE1_optAchse({ 0.0,0.0,0.0 }, 1, { 0.0,0.0,10.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, light);
	//SequentialRayTracing seqTraceE1_OptAchse(optSysE1);
	//seqTraceE1_OptAchse.seqRayTracingWithVectorOfLightRays(fillAperStopE1_optAchse.getVectorWithLightRays());
	//
	//// fill aperture stop
	//FillApertureStop fillAperStopE1_field({ 0.0,0.5,0.0 }, 1, { 0.0,0.0,10.0 }, { 0.0,0.0,1.0 }, /*rings*/6, /*arms*/8, 1.0, light);
	//SequentialRayTracing seqTraceE1_field(optSysE1);
	//seqTraceE1_field.seqRayTracingWithVectorOfLightRays(fillAperStopE1_field.getVectorWithLightRays());
	//
	//
	////// plot 2d
	//
	//optSysE1.fillVectorToPlot2DQwt(0, S1.getPointerPlot());
	//optSysE1.fillVectorToPlot2DQwt(1, S2.getPointerPlot());
	//optSysE1.fillVectorToPlot2DQwt(2, S3.getPointerPlot());
	//optSysE1.fillVectorToPlot2DQwt(3, S4.getPointerPlot());
	//optSysE1.fillVectorToPlot2DQwt(4, S5.getPointerPlot());
	//optSysE1.fillVectorToPlot2DQwt(5, S6.getPointerPlot());
	//optSysE1.fillVectorToPlot2DQwt(6, S7.getPointerPlot());
	//optSysE1.fillVectorToPlot2DQwt(7, S8.getPointerPlot());
	//optSysE1.fillVectorToPlot2DQwt(8, S9.getPointerPlot());
	//optSysE1.fillVectorToPlot2DQwt(9, S10.getPointerPlot());
	//optSysE1.fillVectorToPlot2DQwt(10, S11.getPointerPlot());
	//optSysE1.fillVectorToPlot2DQwt(11, S12.getPointerPlot());
	//optSysE1.fillVectorToPlot2DQwt(12, S13.getPointerPlot());
	//optSysE1.fillVectorToPlot2DQwt(13, S14.getPointerPlot());
	//optSysE1.fillVectorToPlot2DQwt(14, S15.getPointerPlot());
	//
	//// single ray tracing
	//SequentialRayTracing SeqTraceE1_plot2D(optSysE1);
	//std::vector<LightRayStruct> lightRayAlong_Y_E1 = SequentialRayTracing::lightRayAlongY({ 0.0, -0.5, 0.0 }, 3, 10.0, -2.0, 2.0, 550, 1.0);
	//SeqTraceE1_plot2D.seqRayTracingWithVectorOfLightRays(lightRayAlong_Y_E1);
	//
	////// single ray tracing
	//SequentialRayTracing SeqTraceE1_plot2D_field(optSysE1);
	//std::vector<LightRayStruct> lightRayAlong_E1_field = SequentialRayTracing::lightRayAlongY({ 0.0, 0.5, 0.0 }, 3, 10.0, -2.0, 2.0, 550, 1.0);
	//SeqTraceE1_plot2D_field.seqRayTracingWithVectorOfLightRays(lightRayAlong_E1_field);
	//
	//
	////// single ray tracing
	//SequentialRayTracing SeqTraceE1_plot2D_field1(optSysE1);
	//std::vector<LightRayStruct> lightRayAlong_E1_field1 = SequentialRayTracing::lightRayAlongY({ 0.0, 0.0, 0.0 }, 3, 10.0, -2.0, 2.0, 550, 1.0);
	//SeqTraceE1_plot2D_field1.seqRayTracingWithVectorOfLightRays(lightRayAlong_E1_field1);
	//
	//
	////fill vector Ray Tracing
	//RayTracingSystem RayTracSys;
	//RayTracSys.fillVectorRayTracing(&SeqTraceE1_plot2D, { 0,255,0 });
	//RayTracSys.fillVectorRayTracing(&SeqTraceE1_plot2D_field, { 0,0,255 });
	//RayTracSys.fillVectorRayTracing(&SeqTraceE1_plot2D_field1, { 50,0,10 });
	//
	//
	////// show surfaces with rays:
	//QwtWindow RayTracingPlot(optSysE1, RayTracSys);
	//RayTracingPlot.resize(1600, 1000);
	//RayTracingPlot.show();
	//
	//////save the plot:
	////RayTracingPlot.SaveQwtPlot("../benchmark/Plot/images/Qwt2.jpg");
	//
	//
	////define the Spot Diagramms
	//Spot spotE1_optAchese(seqTraceE1_OptAchse.getAllInterPointsAtSurf_i(14), seqTraceE1_OptAchse.getAllInterPointsAtSurf_i(14).at(0));
	//std::vector<Spot> vecSpotE1_optAchese{ spotE1_optAchese };
	//PlotSpotDiagramm PlotSpotE1_optAchse(spotE1_optAchese.getRefPoint(), vecSpotE1_optAchese, 0.09950372, 550);
	//
	//Spot spotE1_field(seqTraceE1_field.getAllInterPointsAtSurf_i(14), seqTraceE1_field.getAllInterPointsAtSurf_i(14).at(0));
	//std::vector<Spot> vecSpotE1_field{ spotE1_field };
	//PlotSpotDiagramm PlotSpotE1_field(spotE1_field.getRefPoint(), vecSpotE1_field, 0.09950372, 550);
	//
	//Spot spotE1_field1(SeqTraceE1_plot2D_field1.getAllInterPointsAtSurf_i(14), SeqTraceE1_plot2D_field1.getAllInterPointsAtSurf_i(14).at(0));
	//std::vector<Spot> vecSpotE1_field1{ spotE1_field1 };
	//PlotSpotDiagramm PlotSpotE1_field1(spotE1_field1.getRefPoint(), vecSpotE1_field1, 0.09950372, 550);
	//
	////fill vectorSpotDiagram
	//optSysE1.fillVectorSpotDiagramToPlot("Spot Diagram optical achse", &PlotSpotE1_optAchse);
	//optSysE1.fillVectorSpotDiagramToPlot("Spot Diagram field 1", &PlotSpotE1_field);
	//optSysE1.fillVectorSpotDiagramToPlot("Spot Diagram field 2", &PlotSpotE1_field1);
	////optSysE1.fillVectorSpotDiagramToPlot("Spot Diagram optical achse", &PlotSpotE1_optAchse);
	////optSysE1.fillVectorSpotDiagramToPlot("Spot Diagram field", &PlotSpotE1_field);
	//
	//
	//// Plot spot diagram opt achse and field
	//QwtWindow SpotDiagrammPlot(optSysE1);
	//SpotDiagrammPlot.resize(400, 400);
	//SpotDiagrammPlot.show();
	//
	//
	//return a.exec();
//}
// Aya *******************************************************************

