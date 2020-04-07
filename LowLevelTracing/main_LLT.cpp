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

#include "..\benchmark\testQwtPlots\testRayFanQwtPlot.h"

#include "..\benchmark\Optikkreis\Optikkreis.h"

#include "..\benchmark\Optimizer\DLS\testDLS.h"

int main(int argc, char **argv)
{
	QApplication a(argc, argv);

	// *****************************************************************************************************************
	// Benchmark for traceropen
	// *****************************************************************************************************************
	std::vector<bool> workTheSystem;
	// *****************************************************************************************************************

	//// Math
	//BenchmarkMath checkMath;
	//bool Math = checkMath.checkMethodesMath();
	//workTheSystem.push_back(Math);

	//// DLS
	testDLS testDLS;
	bool checkDLS = testDLS.testDLS_superFct();
	workTheSystem.push_back(checkDLS);

	//// Optikkreis
	//Optikkreis optKreis;
	//bool checkOptKreis = optKreis.systemForOptikkreis();
	//workTheSystem.push_back(checkOptKreis);
	//
	//// plot TOM logo
	//TOM_LOGO tomLogo;
    //bool checkOlotLogoTOM = tomLogo.plotTOM_Logo();
	//workTheSystem.push_back(checkOlotLogoTOM);
	
	//testRayTracingQwtPlot checkRayTracingPlot;
	//bool checkCardinal_superFct_RayTracing = checkRayTracingPlot.superFuncTestRayTracingQwtPlot();
	//workTheSystem.push_back(checkCardinal_superFct_RayTracing);

	//testRayFanQwtPlot checkRayFanPlot;
	//bool checkCardinal_superFct_RayFan = checkRayFanPlot.superFuncTestRayFanQwtPlot();
	//workTheSystem.push_back(checkCardinal_superFct_RayFan);
	//
	//testSpotDiagramQwtPlot checkSpotDiagramPlot;
	//bool checkCardinal_superFct_SpotDiagram = checkSpotDiagramPlot.superFuncTestSpotDiagramQwtPlot();
	//workTheSystem.push_back(checkCardinal_superFct_SpotDiagram);
	//
	//testOPDQwtPlot checkOPDPlot;
	//bool checkCardinal_superFct_OPD = checkOPDPlot.superFuncTestOPDQwtPlot();
	//workTheSystem.push_back(checkCardinal_superFct_OPD);
	
	//// test replace lenses for IOC 2020
	//IOC2020_Dresden system_IOC2020_Dresden;
	//bool checkSysIOC2020 = system_IOC2020_Dresden.systemFor_IOC2020_Dresten();
	//workTheSystem.push_back(checkSysIOC2020);
	
	//// RayAiming
	//BenchmarkRayAiming checkRayAiming;
	//bool checkRayAiming_inf = checkRayAiming.checkRayAimingSuperFct_inf();
	//workTheSystem.push_back(checkRayAiming_inf);
	//bool checkRayAiming_obj = checkRayAiming.checkRayAimingSuperFct_obj();
	//workTheSystem.push_back(checkRayAiming_obj);

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

	////// check optimizer
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
	std::cout << "" << std::endl;
	if (checker == true) std::cout << "The system works perfectly\n";
	else std::cout << "There is a fuck fuck fuck fuck fuck in the system\n" << std::endl;
	//*****************************************************************************************************************
	

	/*int i;
	std::cout << "insert a rendom number" << std::endl;
	std::cin >> i;*/

	return a.exec();
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
//}