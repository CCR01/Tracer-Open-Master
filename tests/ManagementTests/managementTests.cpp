#include "managementTests.h"

#include "..\..\Inport_Export_Data\Inport_Export_Data.h"

#include "..\testAsphericalSurface_LLT\testAsphericalSurface_LLT.h"
#include "..\testFillAS\testFillAS.h"
#include "..\testMath\testMath.h"
#include "..\testApertureStop\testApertureStop.h"
#include "..\testLensCatalog\testLensCatalogEO.h"
#include "..\testSphericalSurface\testSphericalSurface_LLT.h"
#include "..\testGlasses\testGlasses.h"
#include "..\testParaxialLens_LLT\testParaxialLens_LLT.h"
#include "..\testPlanGeometry\testPlanSurface.h"
#include "..\testCardinalPoints\testCardinalPoints.h"
#include "..\testRayAiming\testRayAiming.h"
#include "..\testRayAimingSuperFct\testRayAiming_multiThreads_12.h"
#include "..\TestGenetic\TestGenetic.h"
#include "..\testDLS\testDLS.h"
#include "..\testDLS_multiThreads_12\testDLS_multiThreads_12.h"
#include "..\testOptimizeSystemSuperFct_GeneticAndDLS\testOptimizeSystemSuperFct_GeneticAndDLS.h"
#include "..\testLensReplace\testLenseReplace.h"
#include "..\testOPD\testOPD.h"
#include "..\testGlobalOPD\TestGlobalOPD.h"
#include "..\testImageSimulation\testImageSimulation.h"
#include "..\testPSF\testPSF.h"
#include "..\testImproveImageQuality\testImproveImageQuality.h"
#include "..\testDistortion\testDistortion.h"
#include "..\testNoise\testNoise.h"
#include "..\testImproveImageQuality\WienerDeconvolution\tWienerDeconvolution.h"
#include "..\testImproveImageQuality\testDetailEnhance_DLS.h"
#include "..\testImproveImageQuality\WienerDeconvolutionSuperFunction\tWienerDeconSuperFct.h"
#include "..\testImproveImageQuality\WienerDeconvolutionSuperFunctionParallel\tWienerDeconvolutionSuperFunctionParallel.h"
#include "..\testImproveImageQuality\testRemoveChromaticAberrations.h"
#include "..\testSequentialRayTracing\testSequentialRayTracer.h"
#include "..\testSharpnessEvaluation\testSharpnessEvaluation.h"
#include "..\testLensCatalog\testLensCatalogThorlabs.h"
#include "..\testSeidelCoefficients\testSeidelCoefficients.h"
#include "..\testCalcMaxSeidelAberrationen\testCalcMaxSeidelAberration.h"
#include "..\testLensReplaceAndOptimize\testLensReplaceAndOptimize.h"
#include "..\testLensCatalog\testLensCatalog_Qioptiq.h"
#include "..\testCompareTOMandZemaxOptimizer\testCompareTOMandZemaxOptimizer.h"
#include "..\testLensReplaceAndOptimiz_statistic\twoLensSystems\testLensReplaceAndOptimize_statistic_twoLensSystem.h"

ManagementTests::ManagementTests() {};
ManagementTests::ManagementTests(std::vector<testWhat> testWhat_vec) :
	mTestWhat_vec(testWhat_vec)
{}
ManagementTests::~ManagementTests() {}

bool ManagementTests::testWhatInTestWhatVec(testWhat checkTestWhatInVec)
{
	std::vector<testWhat>::iterator it = std::find(mTestWhat_vec.begin(), mTestWhat_vec.end(), checkTestWhatInVec);
	if (it != mTestWhat_vec.end())
	{
		return true;
	}

	return false;
}

void ManagementTests::checkerAndCout(bool check, std::string currentTestSystem)
{
	if (check == false)
	{
		std::string totalString;
		std::string errorString = "There is an ERROR in ";
		totalString = errorString + currentTestSystem;

		std::cout << totalString << std::endl;

		std::string location = "../tests/ManagementTests/";
		std::string nameLocation = "saveResultsTests";

		inportExportData::saveStringInTXT_includingTime(location, nameLocation, totalString);
	}
}

bool ManagementTests::testSuperFct()
{
	std::vector<bool> workTheSystem_test;
	bool testAll = testWhatInTestWhatVec(testWhat::tALL);

	// test aspherical surface LLT
	if (testWhatInTestWhatVec(testWhat::tAspherical_LLT) || testAll)
	{
		testAsphericalSurface_LLT testClassAspericalSurface_LLT;
		bool checkAsphericalSurface_LLT = testClassAspericalSurface_LLT.checkAsphericalSurfaceSuperFct_LLT();
		workTheSystem_test.push_back(checkAsphericalSurface_LLT);
		checkerAndCout(checkAsphericalSurface_LLT, "test aspherical surface LLT");

	}

	// test namespace math
	if (testWhatInTestWhatVec(testWhat::tMath) || testAll)
	{
		testMath testNamespaceMath;
		bool checkMath = testNamespaceMath.checkMethodesMath();
		workTheSystem_test.push_back(checkMath);
		checkerAndCout(checkMath, "test namespace math");
	}

	// test fill aperture stop
	if (testWhatInTestWhatVec(testWhat::tFillAS) || testAll)
	{
		testFillAS testClassFillAS;
		bool checkFillAS = testClassFillAS.chekMethodesFillAS();
		workTheSystem_test.push_back(checkFillAS);
		checkerAndCout(checkFillAS, "test fill aperture stop");
	}

	// test aperture stop
	if (testWhatInTestWhatVec(testWhat::tApertureStop_LLT) || testAll)
	{
		testApertureStop testClassApertureStop;
		bool checkAperStop = testClassApertureStop.checkApertureStop();
		workTheSystem_test.push_back(checkAperStop);
		checkerAndCout(checkAperStop, "test aperture stop");
	}

	///test lens calalog from edmund optics
	if (testWhatInTestWhatVec(testWhat::tLensCatalogEO) || testAll)
	{
		TestLensCatalogEO testClassLensCataEO;

		bool checkLensCataEO_TwoSurfaces_1 = testClassLensCataEO.testCatalogEO_TwoSurfaces_1();
		workTheSystem_test.push_back(checkLensCataEO_TwoSurfaces_1);
		checkerAndCout(checkLensCataEO_TwoSurfaces_1, "test lens calalog from edmund optics -> EO_TwoSurfaces_1");
		
		bool checkLensCataEO_TwoSurfaces_2 = testClassLensCataEO.testCatalogEO_TwoSurfaces_2();
		workTheSystem_test.push_back(checkLensCataEO_TwoSurfaces_2);
		checkerAndCout(checkLensCataEO_TwoSurfaces_2, "test lens calalog from edmund optics -> EO_TwoSurfaces_2");
		
		bool checkLensCataEO_TwoSurfaces_3 = testClassLensCataEO.testCatalogEO_TwoSurfaces_3();
		workTheSystem_test.push_back(checkLensCataEO_TwoSurfaces_3);
		checkerAndCout(checkLensCataEO_TwoSurfaces_3, "test lens calalog from edmund optics -> EO_TwoSurfaces_3");
		
		bool checkLensCataEO_ThreeSurfaces = testClassLensCataEO.testCatalogEO_ThreeSurfaces();
		workTheSystem_test.push_back(checkLensCataEO_ThreeSurfaces);
		checkerAndCout(checkLensCataEO_ThreeSurfaces, "test lens calalog from edmund optics -> EO_ThreeSurfaces");
		
		bool checkLensCataEO_doub_conc_lens = testClassLensCataEO.testCatalogEO_DCV();
		workTheSystem_test.push_back(checkLensCataEO_doub_conc_lens);
		checkerAndCout(checkLensCataEO_ThreeSurfaces, "test lens calalog from edmund optics -> EO_doub_conc_lens");
		
		bool checkLensCataEO_PCV = testClassLensCataEO.testcatalogEO_PCV();
		workTheSystem_test.push_back(checkLensCataEO_PCV);
		checkerAndCout(checkLensCataEO_PCV, "test lens calalog from edmund optics -> EO_PCV");
		checkerAndCout(checkLensCataEO_PCV, "test lens calalog from edmund optics -> EO_PCV");
		
		bool checkLensCatalogEO_double_concav_lenses_NIR_I = testClassLensCataEO.test_LensCatalogEO_double_concav_lenses_NIR_I();
		workTheSystem_test.push_back(checkLensCatalogEO_double_concav_lenses_NIR_I);
		checkerAndCout(checkLensCatalogEO_double_concav_lenses_NIR_I, "test Lens Catalog EO double concav lenses NIR I Coated -> EO_PCV");
		
		bool checkLensCatalogEO_achromat_VIS_NIR_Coating = testClassLensCataEO.test_LensCatalogEO_achromat_VIS_NIR_Coating();
		workTheSystem_test.push_back(checkLensCatalogEO_achromat_VIS_NIR_Coating);
		checkerAndCout(checkLensCatalogEO_achromat_VIS_NIR_Coating, "test Lens Catalog EO achromat VIS NIR Coating -> EO_achro_VIS_NIR");
		
		// https://www.edmundoptics.de/f/broadband-ar-coated-negative-achromatic-lenses/13623/
		bool  checkLensCatalogEO_Broadband_AR_Coated_Negative_Achromatic_Lenses = testClassLensCataEO.checkLensCatalogEO_Broadband_AR_Coated_Negative_Achromatic_Lenses();
		workTheSystem_test.push_back(checkLensCatalogEO_Broadband_AR_Coated_Negative_Achromatic_Lenses);
		checkerAndCout(checkLensCatalogEO_Broadband_AR_Coated_Negative_Achromatic_Lenses, "test Lens Catalog EO Broadband_AR_Coated_Negative_Achromatic_Lenses -> EO_neg_achro_Broadband_AR_Coated");
		
		// https://www.edmundoptics.de/f/large-precision-achromatic-lenses/11679/
		// Large Precision Achromatic Lenses 
		// *** NO AIRSPACE *** ///
		bool checkLensCatalogEO_Large_Precision_Achromatic_Lenses_NoAirspace = testClassLensCataEO.checkLensCatalogEO_Large_Precision_Achromatic_Lenses_NoAirspace();
		workTheSystem_test.push_back(checkLensCatalogEO_Large_Precision_Achromatic_Lenses_NoAirspace);
		checkerAndCout(checkLensCatalogEO_Large_Precision_Achromatic_Lenses_NoAirspace, "test Lens Catalog EO Large Precision Achromatic Lenses NoAirspace -> EO_Large_prec_achro_NO_AIRSPACE");
		
		// https://www.edmundoptics.de/f/large-precision-achromatic-lenses/11679/
		// Large Precision Achromatic Lenses 
		// *** AIRSPACE 0,1 *** ///
		bool checkLensCatalogEO_Large_Precision_Achromatic_Lenses_Airspace01 = testClassLensCataEO.checkLensCatalogEO_Large_Precision_Achromatic_Lenses_Airspace01();
		workTheSystem_test.push_back(checkLensCatalogEO_Large_Precision_Achromatic_Lenses_Airspace01);
		checkerAndCout(checkLensCatalogEO_Large_Precision_Achromatic_Lenses_Airspace01, "test Lens Catalog EO Large Precision Achromatic Lenses NoAirspace -> EO_Large_prec_achro_AIRSPACE_01");
	
		// Hastings Triplet Achromatic Lenses 
		// https://www.edmundoptics.de/f/hastings-triplet-achromatic-lenses/11968/
		bool checkLensCatalogEO_Hastings_Triplet_Achromatic_Lenses = testClassLensCataEO.checkLensCatalogEO_Hastings_Triplet_Achromatic_Lenses();
		workTheSystem_test.push_back(checkLensCatalogEO_Hastings_Triplet_Achromatic_Lenses);
		checkerAndCout(checkLensCatalogEO_Hastings_Triplet_Achromatic_Lenses, "test Lens Catalog EO Hasting Triplet Achromatic lens -> EO_HastingTriplets");

		// Steinheil Triplet Achromatic Lenses 
		// https://www.edmundoptics.de/f/steinheil-triplet-achromatic-lenses/12275/
		bool checkLensCatalogEO_Steinheil_Triplet_Achromatic_Lenses = testClassLensCataEO.checkLensCatalogEO_Steinheil_Triplet_Achromatic_Lenses();
		workTheSystem_test.push_back(checkLensCatalogEO_Steinheil_Triplet_Achromatic_Lenses);
		checkerAndCout(checkLensCatalogEO_Steinheil_Triplet_Achromatic_Lenses, "test Lens Catalog EO Steinheil Triplet Achromatic lens -> EO_SteinheimTriplets");

		// Micro Plano-Convex (PCX) Lenses 
		// https://www.edmundoptics.de/f/micro-plano-convex-pcx-lenses/39529/
		bool checkLensCatalogEO_Micro_Plano_Convex_PCX_Lenses = testClassLensCataEO.checkLensCatalogEO_Micro_Plano_Convex_PCX_Lenses();
		workTheSystem_test.push_back(checkLensCatalogEO_Micro_Plano_Convex_PCX_Lenses);
		checkerAndCout(checkLensCatalogEO_Micro_Plano_Convex_PCX_Lenses, "test Lens Catalog EO Micro Plano-Convex (PCX) Lenses  -> EO_MicroPCX");

		// Large PCX Condenser Lenses
		// https://www.edmundoptics.de/f/large-pcx-condenser-lenses/13572/
		bool checkLensCatalogEO_Large_PCX_Condenser_Lenses = testClassLensCataEO.checkLensCatalogEO_Large_PCX_Condenser_Lenses();
		workTheSystem_test.push_back(checkLensCatalogEO_Large_PCX_Condenser_Lenses);
		checkerAndCout(checkLensCatalogEO_Large_PCX_Condenser_Lenses, "test Lens Catalog EO Large PCX Condenser Lenses  -> EO_LargePCXCondenserLenses");

		

	}

	// test lens catalog from thorlabs
	if (testWhatInTestWhatVec(testWhat::tLensCatalogThorlabs) || testAll)
	{
		testLensCatalogThorlabs testClassLensCataThorlabs;
		bool checkLensCataThorlabs_ThreeSurfaces = testClassLensCataThorlabs.testLensCataThorlabs_Unmounted_Achromatic_Doublets_AR_Coated();
		workTheSystem_test.push_back(checkLensCataThorlabs_ThreeSurfaces);
		checkerAndCout(checkLensCataThorlabs_ThreeSurfaces, "test lens calalog from thorlabs -> Unmounted Achromatic Doublets, AR Coated: 400 - 1100 nmes_1");

		bool checkLensCataThorlabs_N_BK7_Plano_Convex_Lenses_AR_Coating_400_1100_nm = testClassLensCataThorlabs.testLensCataThorlas_N_BK7_Plano_Convex_Lenses_AR_Coating_400_1100_nm();
		workTheSystem_test.push_back(checkLensCataThorlabs_N_BK7_Plano_Convex_Lenses_AR_Coating_400_1100_nm);
		checkerAndCout(checkLensCataThorlabs_N_BK7_Plano_Convex_Lenses_AR_Coating_400_1100_nm, "test lens calalog from thorlabs -> N BK7 Plano Convex Lenses AR Coating 400 1100 nm");
	
		bool checkLensCata_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm = testClassLensCataThorlabs.testLensCataTorlabs_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm();
		workTheSystem_test.push_back(checkLensCata_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm);
		checkerAndCout(checkLensCata_N_BK7_Bi_Convex_Lenses_AR_Coating_350_700_nm, "test lens calalog from thorlabs -> N BK7 Bi-Convex Lenses AR Coating: 350 - 700 nm");

		bool checkLensCata_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm = testClassLensCataThorlabs.testLensCataTorlabs_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm();
		workTheSystem_test.push_back(checkLensCata_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm);
		checkerAndCout(checkLensCata_N_BK7_Plano_Concave_Lenses_AR_Coating_350_700_nm, "test lens calalog from thorlabs -> N-BK7 Plano-Concave Lenses, AR Coating 350 - 700 nm");


		bool checkLensCata_N_BK7_and_N_SF11_Bi_Concave_Lenses_AR_Coating_350_700_nm = testClassLensCataThorlabs.testLensCataTorlabs_N_BK7_and_N_SF11_BiSConcave_Lenses_AR_Coating_350_700_nm();
		workTheSystem_test.push_back(checkLensCata_N_BK7_and_N_SF11_Bi_Concave_Lenses_AR_Coating_350_700_nm);
		checkerAndCout(checkLensCata_N_BK7_and_N_SF11_Bi_Concave_Lenses_AR_Coating_350_700_nm, "test lens calalog from thorlabs -> N-BK7 and N-SF11 Bi-Concave Lenses, AR Coating 350 - 700 nm");
	
		bool checkLensCata_1Zoll_N_BK7_Best_Form_Spherical_Lenses_AR_Coating_350_700_nm = testClassLensCataThorlabs.testLensCataTorlabs_1Zoll_N_BK7_Best_Form_Spherical_Lenses_AR_Coating_350_700_nm();
		workTheSystem_test.push_back(checkLensCata_1Zoll_N_BK7_Best_Form_Spherical_Lenses_AR_Coating_350_700_nm);
		checkerAndCout(checkLensCata_1Zoll_N_BK7_Best_Form_Spherical_Lenses_AR_Coating_350_700_nm, "test lens calalog from thorlabs -> Ø1 N-BK7 Best Form Spherical Lenses, AR Coating: 350-700 nm");

		bool checkLensCata_N_BK7_Positive_Meniscus_Lenses = testClassLensCataThorlabs.testLensCataTorlabs_N_BK7_Positive_Meniscus_Lenses_Uncoated();
		workTheSystem_test.push_back(checkLensCata_N_BK7_Positive_Meniscus_Lenses);
		checkerAndCout(checkLensCata_N_BK7_Positive_Meniscus_Lenses, "test lens calalog from thorlabs -> N-BK7 Positive Meniscus Lenses");

		bool checkLensCata_1Zoll_N_BK7_Negative_Meniscus_Lenses_Uncoated = testClassLensCataThorlabs.testLensCataTorlabs_N_BK7_Negative_Meniscus_Lenses_Uncoated();
		workTheSystem_test.push_back(checkLensCata_1Zoll_N_BK7_Negative_Meniscus_Lenses_Uncoated);
		checkerAndCout(checkLensCata_1Zoll_N_BK7_Negative_Meniscus_Lenses_Uncoated, "test lens calalog from thorlabs -> Ø1 N-BK7 Negative Meniscus Lenses Uncoated");

		bool checkLensCata_Steinheil_Triplet_Achromatic_Lenses_Visible = testClassLensCataThorlabs.testLensCataTorlabs_Steinheil_Triplet_Achromatic_Lenses_Visible();
		workTheSystem_test.push_back(checkLensCata_Steinheil_Triplet_Achromatic_Lenses_Visible);
		checkerAndCout(checkLensCata_Steinheil_Triplet_Achromatic_Lenses_Visible, "test lens calalog from thorlabs -> Steinheil Triplet Achromatic Lenses, Visible");

		bool checkLensCata_Hastings_Triplet_Achromatic_Lenses_Visible = testClassLensCataThorlabs.testLensCataTorlabs_Hastings_Triplet_Achromatic_Lenses_Visible();
		workTheSystem_test.push_back(checkLensCata_Hastings_Triplet_Achromatic_Lenses_Visible);
		checkerAndCout(checkLensCata_Hastings_Triplet_Achromatic_Lenses_Visible, "test lens calalog from thorlabs -> Hastings Triplet Achromatic Lenses, Visible");
	}

	// test lens catalog from qioptiq
	if (testWhatInTestWhatVec(testWhat::tLensCatalogQioptiq) || testAll)
	{
		testLensCata_Qioptiq testClassLensCataQioptiq;
		bool checkLensCataQioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS = testClassLensCataQioptiq.testLensCata_PlanoConvex_lenses_unmounted_ARB2_VIS();
		workTheSystem_test.push_back(checkLensCataQioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS);
		checkerAndCout(checkLensCataQioptiq_PlanoConvex_lenses_unmounted_ARB2_VIS, "test lens calalog from Qioptiq -> Plano-Convex lenses, unmounted, ARB2-VIS");
	
		bool checkLensCataQioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS = testClassLensCataQioptiq.testLensCata_Symmetric_convex_lenses_unmounted_ARB2_VIS();
		workTheSystem_test.push_back(checkLensCataQioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS);
		checkerAndCout(checkLensCataQioptiq_Symmetric_convex_lenses_unmounted_ARB2_VIS, "test lens calalog from Qioptiq -> Symmetric-convex lenses, unmounted, ARB2-VIS");
	
		bool checkLensCataQioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS = testClassLensCataQioptiq.testLensCata_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS();
		workTheSystem_test.push_back(checkLensCataQioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS);
		checkerAndCout(checkLensCataQioptiq_Plano_concave_lenses_unmounted_N_BK7_ARB2_VIS, "test lens calalog from Qioptiq -> Plan-concave lenses, unmounted (N-BK7), ARB2-VIS");
	
		bool checkLensCataQioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS = testClassLensCataQioptiq.testLensCata_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS();
		workTheSystem_test.push_back(checkLensCataQioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS);
		checkerAndCout(checkLensCataQioptiq_Symmetric_concave_lenses_unmounted_N_BK7_ARB2_VIS, "test lens calalog from Qioptiq -> Symmetric-concave lenses, unmounted (N-BK7), ARB2-VIS");

		bool checkLensCataQioptiq_Achromat_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS = testClassLensCataQioptiq.testLensCata_Achromats_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS();
		workTheSystem_test.push_back(checkLensCataQioptiq_Achromat_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS);
		checkerAndCout(checkLensCataQioptiq_Achromat_VIS_Positive_dia_3_mm_to_31_5_mm_unmounted_N_BK7_ARB2_VIS, "test lens calalog from Qioptiq -> Achromats VIS, Positive, dia. 3 mm to 31.5 mm, unmounted, ARB2-VIS");
	
		bool checkLensCataQioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS = testClassLensCataQioptiq.testLensCata_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS();
		workTheSystem_test.push_back(checkLensCataQioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS);
		checkerAndCout(checkLensCataQioptiq_Achromats_VIS_Positive_from_40_mm_diameter_unmounted_N_BK7_ARB2_VIS, "test lens calalog from Qioptiq -> Achromats VIS, Positive from 40 mm diameter, unmounted, ARB2-VIS");
	
		bool checkLensCataQioptiq_Achromats_Negative_Unmounted_ARB2_VIS = testClassLensCataQioptiq.testLensCata_Achromats_Negative_Unmounted_ARB2_VIS();
		workTheSystem_test.push_back(checkLensCataQioptiq_Achromats_Negative_Unmounted_ARB2_VIS);
		checkerAndCout(checkLensCataQioptiq_Achromats_Negative_Unmounted_ARB2_VIS, "test lens calalog from Qioptiq -> Achromats, Negative, Unmounted, ARB2 VIS");
		
	
	}

	// test spherical surface LLT
	if (testWhatInTestWhatVec(testWhat::tSphericalSurface_LLT) || testAll)
	{
		testSphericalSurface_LLT testClassSphSurface_LLT;
		bool checkSphericalLens = testClassSphSurface_LLT.checkSphericalSurface_LLT();
		workTheSystem_test.push_back(checkSphericalLens);
		checkerAndCout(checkSphericalLens, "test spherical surface LLT");
	}

	// test glasses
	if (testWhatInTestWhatVec(testWhat::tGlasses) || testAll)
	{
		testGlasses testClassGlasses;
		bool checkGlasses = testClassGlasses.checkGlasses();
		workTheSystem_test.push_back(checkGlasses);
		checkerAndCout(checkGlasses, "test glasses");
	}

	// test paraxial lens LLT
	if (testWhatInTestWhatVec(testWhat::tParaxialLens_LLT) || testAll)
	{
		testParaxialLens testClassParaxialLens;
		bool checkParaxialLens = testClassParaxialLens.checkMethodesParaxialLens_LLT_superFct();
		workTheSystem_test.push_back(checkParaxialLens);
		checkerAndCout(checkParaxialLens, "test paraxial lens LLT");
	}

	// test plan geometry LLT
	if (testWhatInTestWhatVec(testWhat::tParaxialLens_LLT) || testAll)
	{
		testPlanSurface testClassPlanSurface;
		bool checkPlanSurface = testClassPlanSurface.checkMethodesPlanSurface();
		workTheSystem_test.push_back(checkPlanSurface);
		checkerAndCout(checkPlanSurface, "test plan geometry LLT");
	}

	// test cardinal points
	if (testWhatInTestWhatVec(testWhat::tCardinalPoints) || testAll)
	{
		testCardinalPoints testCarPoints;
		bool checkCardinalPoints = testCarPoints.superFuncTestCalcCardinalPoints();
		workTheSystem_test.push_back(checkCardinalPoints);
		checkerAndCout(checkCardinalPoints, "test cardinal points");
	}

	// test ray aiming obj
	if (testWhatInTestWhatVec(testWhat::tRayAiming_obj) || testAll)
	{
		testRayAiming testRayAim_obj;
		bool checkRayAiming_obj = testRayAim_obj.checkRayAimingSuperFct_obj();
		workTheSystem_test.push_back(checkRayAiming_obj);
		checkerAndCout(checkRayAiming_obj, "test ray aiming obj");
	}

	// test ray aiming obj inital rays
	if (testWhatInTestWhatVec(testWhat::tRayAiming_obj_initialRays) || testAll)
	{
		testRayAiming testRayAim_obj_initalRays;
		bool checkRayAiming_obj_initalRays = testRayAim_obj_initalRays.checkRayAimingSuperFct_obj_initlaRays();
		workTheSystem_test.push_back(checkRayAiming_obj_initalRays);
		checkerAndCout(checkRayAiming_obj_initalRays, "test ray aiming obj inital rays");
	}

	// 
	if (testWhatInTestWhatVec(testWhat::tRayAiming_inf) || testAll)
	{
		testRayAiming testRayAim_inf;
		bool checkRayAiming_inf = testRayAim_inf.checkRayAimingSuperFct_inf();
		workTheSystem_test.push_back(checkRayAiming_inf);
		checkerAndCout(checkRayAiming_inf, "test ray aiming inf");
	}

	// test ray aiming inf inital rays
	if (testWhatInTestWhatVec(testWhat::tRayAiming_inf_initialRays) || testAll)
	{
		testRayAiming testRayAim_inf_initalRays;
		bool checkRayAiming_inf_initalRays = testRayAim_inf_initalRays.checkRayAimingSuperFct_inf_initlaRays();
		workTheSystem_test.push_back(checkRayAiming_inf_initalRays);
		checkerAndCout(checkRayAiming_inf_initalRays, "test ray aiming inf inital rays");
	}

	// test ray aiming 12 cores obj
	if (testWhatInTestWhatVec(testWhat::tRayAiming_12Cores) || testAll)
	{
		testRayAiming_multiThreads_12 testRayAiming_12;
		bool checkRayAiming_12_obj = testRayAiming_12.testRayAiming_multiThreads_12_superFct_obj();
		workTheSystem_test.push_back(checkRayAiming_12_obj);
		checkerAndCout(checkRayAiming_12_obj, "test ray aiming 12 cores");
	}

	// test genetic optimization
	if (testWhatInTestWhatVec(testWhat::tGenetic_opti) || testAll)
	{
		TestGenetic testGenetic;
		bool checkGenetic = testGenetic.testGeneticSuperFunc();
		workTheSystem_test.push_back(checkGenetic);
		checkerAndCout(checkGenetic, "test genetic optimization");
	}

	// test genetic generation mode
	if (testWhatInTestWhatVec(testWhat::tGenetic_modes) || testAll)
	{
		TestGenetic testGenetic;
		bool checkGeneticModes = testGenetic.testGenerationModes(-1000.0, 1000.0, 100.0, 50000);
		workTheSystem_test.push_back(checkGeneticModes);
		checkerAndCout(checkGeneticModes, "test genetic generation mode");
	}

	// test genetic cardinal points
	if (testWhatInTestWhatVec(testWhat::tGenetic_cardinalPoints) || testAll)
	{
		TestGenetic testGenetic;
		bool checkGeneticCardnalPoints = testGenetic.testCardinalPointsSuperFct();
		workTheSystem_test.push_back(checkGeneticCardnalPoints);
		checkerAndCout(checkGeneticCardnalPoints, "test genetic cardinal points");
	}

	// test DLS opti rms
	if (testWhatInTestWhatVec(testWhat::tDLS_optiRMS) || testAll)
	{
		testDLS testDLS_optiRMS;
		bool checkDLS_optiRMS = testDLS_optiRMS.testDLS_superFct_optiRMS();
		workTheSystem_test.push_back(checkDLS_optiRMS);
		checkerAndCout(checkDLS_optiRMS, "test DLS opti rms");
	}

	// test DLS opt cardinal points
	if (testWhatInTestWhatVec(testWhat::tDLS_optiCarPoints) || testAll)
	{
		testDLS testDLS_optiCarPoints;
		bool checkDLS_optiCarPoints = testDLS_optiCarPoints.testDLS_superFct_optiCarPoints();
		workTheSystem_test.push_back(checkDLS_optiCarPoints);
		checkerAndCout(checkDLS_optiCarPoints, "test DLS opt cardinal points");
	}

	// test DLS opt rms and cardinal points
	if (testWhatInTestWhatVec(testWhat::tDLS_optiRMS_carPoints) || testAll)
	{
		testDLS testDLS_optiRMS_CarPoints;
		bool checkDLS_optiRMS_CarPoints = testDLS_optiRMS_CarPoints.testDLS_superFct_optiRMSAndCarPoints();
		workTheSystem_test.push_back(checkDLS_optiRMS_CarPoints);
		checkerAndCout(checkDLS_optiRMS_CarPoints, "test DLS opt rms and cardinal points");
	}

	// test optimize DLS parallel 12 threads
	if (testWhatInTestWhatVec(testWhat::tDLS_Parallel) || testAll)
	{
		testDLS_multiThreads_12 testDLS_multi_12;
		bool checkDLS_multi_12 = testDLS_multi_12.testSuperFunction();
		workTheSystem_test.push_back(checkDLS_multi_12);
		checkerAndCout(checkDLS_multi_12, "test optimize DLS parallel 12 threads");
	}

	// test DLS opt according to image processing
	if (testWhatInTestWhatVec(testWhat::tDLS_optiImageProcessing) || testAll)
	{
		testDLS testDLS_optiImageProcessing;
		bool checkDLS_optiImaProc = testDLS_optiImageProcessing.testDLS_superFct_optiImageProcessing();
		workTheSystem_test.push_back(checkDLS_optiImaProc);
		checkerAndCout(checkDLS_optiImaProc, "test DLS opt according to image processing");
	}

	// test optimize RMS including Genetic and DLS multicore
	if (testWhatInTestWhatVec(testWhat::tOptiIncluding_GeneticAndDLS_Parallel_RMS) || testAll)
	{
		testOptimizeSystemSuperFct_GeneticAndDLS testOpti_GeneticAndDLS_rms;
		bool checkOpti_GeneticAndDLS_rms = testOpti_GeneticAndDLS_rms.testOptimizeSys_SuperFunction_GeneticDLS_rms();
		workTheSystem_test.push_back(checkOpti_GeneticAndDLS_rms);
		checkerAndCout(checkOpti_GeneticAndDLS_rms, "test optimize RMS including Genetic and DLS multicore");
	}

	// test optimize Cardinal points including Genetic and DLS multicore
	if (testWhatInTestWhatVec(testWhat::tOptiIncluding_GeneticAndDLS_Parallel_CardinalPoints) || testAll)
	{
		testOptimizeSystemSuperFct_GeneticAndDLS testOpti_GeneticAndDLS_carPoints;
		bool checkOpti_GeneticAndDLS_carPoints = testOpti_GeneticAndDLS_carPoints.testOptimizeSystem_SuperFunction_GeneticDLS_carPoints();
		workTheSystem_test.push_back(checkOpti_GeneticAndDLS_carPoints);
		checkerAndCout(checkOpti_GeneticAndDLS_carPoints, "test optimize Cardinal points including Genetic and DLS multicore");
	}

	// test lens replace
	if (testWhatInTestWhatVec(testWhat::tLensReplace) || testAll)
	{
		testLensReplace checkTestLensReplace;
		bool checkLensReplace = checkTestLensReplace.testLensReplace_superFct();
		workTheSystem_test.push_back(checkLensReplace);
		checkerAndCout(checkLensReplace, "test lens replace");
	}

	// test OPD obj
	if (testWhatInTestWhatVec(testWhat::tOPD_obj) || testAll)
	{
		TestOPD checkTestOPD_obj;
		bool checkOPD_obj = checkTestOPD_obj.checkOPD_obj_superFct();
		workTheSystem_test.push_back(checkOPD_obj);
		checkerAndCout(checkOPD_obj, "test OPD obj");
	}

	// test OPD inf
	if (testWhatInTestWhatVec(testWhat::tOPD_inf) || testAll)
	{
		TestOPD checkTestOPD;
		bool checkOPD_inf = checkTestOPD.checkOPD_inf_superFct();
		workTheSystem_test.push_back(checkOPD_inf);
		checkerAndCout(checkOPD_inf, "test OPD inf");

	}


	// test global OPD obj
	if (testWhatInTestWhatVec(testWhat::tGlobalOPD_obj) || testAll)
	{
		TestGlobalOPD checkTestGlobalOPD_obj;
		bool checkGlobalOPD_obj = checkTestGlobalOPD_obj.checkGlobalOPD_superFunction_obj();
		workTheSystem_test.push_back(checkGlobalOPD_obj);
		checkerAndCout(checkGlobalOPD_obj, "test global OP obj");
	}

	// test global OPD inf
	if (testWhatInTestWhatVec(testWhat::tGlobalOPD_inf) || testAll)
	{
		TestGlobalOPD checkTestGlobalOPD_inf;
		bool checkGlobalOPD_inf = checkTestGlobalOPD_inf.checkGlobalOPD_superFunction_inf();
		workTheSystem_test.push_back(checkGlobalOPD_inf);
		checkerAndCout(checkGlobalOPD_inf, "test global OP obj");
	}

	// test image simulation
	if (testWhatInTestWhatVec(testWhat::tImaSim) || testAll)
	{
		TestImageSimulation checkImageSimulation;
		bool checkImaSim = checkImageSimulation.testSuperFct();
		workTheSystem_test.push_back(checkImaSim);
		checkerAndCout(checkImaSim, "test Image Simulation");
	}

	// test calcualte PSF
	if (testWhatInTestWhatVec(testWhat::tPSF) || testAll)
	{
		TestPSF checkPSF;
		bool checkCalcPSF = checkPSF.testPSF_superFct();
		workTheSystem_test.push_back(checkCalcPSF);
		checkerAndCout(checkCalcPSF, "test calculate PSF");
	}


	// test improve image quality open CV functions
	if (testWhatInTestWhatVec(testWhat::tImproveImaQuality_openCV_Func) || testAll)
	{
		testImproveImageQuality checkImproveImaQuality;
		bool checkImaQual_OpenCV_Func = checkImproveImaQuality.checkImproveImageQuality_openCV_Func();
		workTheSystem_test.push_back(checkImaQual_OpenCV_Func);
		checkerAndCout(checkImaQual_OpenCV_Func, "test improve image quality open CV Function");
	}


	// test detailEnhance_superFunc brute-force-algorithmus
	if (testWhatInTestWhatVec(testWhat::tDetailEnhance_BFA) || testAll)
	{
		testImproveImageQuality checkDetailEnhance;
		bool checkImaQual_DetailEnhance = checkDetailEnhance.checkDetailEnhance_BFA_superFunc();
		workTheSystem_test.push_back(checkImaQual_DetailEnhance);
		checkerAndCout(checkImaQual_DetailEnhance, "test improve image quality detailEnhance");
	}

	// test unsharp masking brute-force-algorithmus
	if (testWhatInTestWhatVec(testWhat::tUnsharpMasking_BFA) || testAll)
	{
		testImproveImageQuality checkUnsharpMasking;
		bool checkImaQual_UnsharpMasking = checkUnsharpMasking.checkUnsharpMasking_BFA_superFunc();
		workTheSystem_test.push_back(checkImaQual_UnsharpMasking);
		checkerAndCout(checkImaQual_UnsharpMasking, "test improve image quality unsharp masking");
	}

	// test wiener filter
	if (testWhatInTestWhatVec(testWhat::tWienerFilter) || testAll)
	{
		testWienerDeconvolution checkWienerDecon;;
		bool checkImaQual_WienerDeconvolution = checkWienerDecon.checkImproveImageQuality_WienerDeconvolution_superFct();
		workTheSystem_test.push_back(checkImaQual_WienerDeconvolution);
		checkerAndCout(checkImaQual_WienerDeconvolution, "test wiener deconvolution");
	}

	// test wiener filter super function
	if (testWhatInTestWhatVec(testWhat::tWienerFilterSuperFunction) || testAll)
	{
		testWienerDeconSuperFct checkWienerDecon_superFct;;
		bool checkImaQual_WienerDeconvolutionSuperFct = checkWienerDecon_superFct.testWienerDeconSuperFct_superFct();
		workTheSystem_test.push_back(checkImaQual_WienerDeconvolutionSuperFct);
		checkerAndCout(checkImaQual_WienerDeconvolutionSuperFct, "test wiener deconvolution super function");
	}

	// test wiender filter super function parallel
	if (testWhatInTestWhatVec(testWhat::tWienerFilterSuperFunction_parallel) || testAll)
	{
		tWienerDeconSuperFctParallel checkWienerDeconSuperFctParallel;
		bool checkImaQualWienerDeconSuperFctParallel = checkWienerDeconSuperFctParallel.testWD_SuprFct_Parallel();
		workTheSystem_test.push_back(checkImaQualWienerDeconSuperFctParallel);
		checkerAndCout(checkImaQualWienerDeconSuperFctParallel, "test wiener deconvolution super function parallel");
	}

	// test improve image quality
	if (testWhatInTestWhatVec(testWhat::tImproveImaQual_superFct) || testAll)
	{
		testImproveImageQuality testImproveImaQual;
		bool checkImpImaQualSupFct = testImproveImaQual.checkImproverImaQuality_superFunc();
		workTheSystem_test.push_back(checkImpImaQualSupFct);
		checkerAndCout(checkImpImaQualSupFct, "test improve image quality super function");
	}

	// test distortion
	if (testWhatInTestWhatVec(testWhat::tDistortion) || testAll)
	{
		testDistortion checkDistortion;
		bool checkDis = checkDistortion.testDistortion_superFuction();
		workTheSystem_test.push_back(checkDis);
		checkerAndCout(checkDis, "test Distortion");
	}

	// test noise
	if (testWhatInTestWhatVec(testWhat::tNoise) || testAll)
	{
		testNoise checkNoise;
		bool checkN = checkNoise.testNoise_superFct();
		workTheSystem_test.push_back(checkN);
		checkerAndCout(checkN, "test Noise");
	}

	// test remove chromatic aberrations
	if (testWhatInTestWhatVec(testWhat::tRemoveChroAber) || testAll)
	{
		testRemoveChromaticAberrations checkRemChromAber;
		bool checkRemChrAber = checkRemChromAber.testRenChromAber_superFunc();
		workTheSystem_test.push_back(checkRemChrAber);
		checkerAndCout(checkRemChrAber, "test Remove Chromatic Aberrations");
	}

	// test sequantial ray tracing
	if (testWhatInTestWhatVec(testWhat::tSequantialRayTracing) || testAll)
	{
		testSequentialRayTracing checkSeqTracing;
		bool checkSeqTrac = checkSeqTracing.checkSequentialRayTracing_superFct();
		workTheSystem_test.push_back(checkSeqTrac);
		checkerAndCout(checkSeqTrac, "test sequantial ray tracing");
	}

	// test sharpness evaluatin
	if (testWhatInTestWhatVec(testWhat::tSharpnessEvaluation) || testAll)
	{
		testSharpnessEvaluation checkSharpnessEvaluation;
		bool checkSharpEval = checkSharpnessEvaluation.testSharpnessEvaluation_superFct();
		workTheSystem_test.push_back(checkSharpEval);
		checkerAndCout(checkSharpEval, "test sharpness evaluation");
	}

	// test seidel coefficients
	if (testWhatInTestWhatVec(testWhat::tSeidelCoef) || testAll)
	{
		testSeidelCoefficients checkSeidelCoef;
		bool checkSeiCoef = checkSeidelCoef.checkCalculationOfSeidelCoefficients_superFct();
		workTheSystem_test.push_back(checkSeiCoef);
		checkerAndCout(checkSeiCoef, "test seidel coefficients");
	}

	// test calculate max Seidel Aberrations
	if (testWhatInTestWhatVec(testWhat::tCalcMaxSeidelAber) || testAll)
	{
		testCalcMaxSeidelAberration checkCalcMaxSeidelAber;
		bool checkCalcMaxSeiAber = checkCalcMaxSeidelAber.testCalcMaxSeidelAber_superFct();
		workTheSystem_test.push_back(checkCalcMaxSeiAber);
		checkerAndCout(checkCalcMaxSeiAber, "test calc max Seidel Aberration");
	}

	// test lens replace and Optimize
	if (testWhatInTestWhatVec(testWhat::tLensReplaceAndOptimize) || testAll)
	{
		testLensReplaceAndOptimize checkLensReplaceAndOptimize;
		bool checkLendRepAndOpti = checkLensReplaceAndOptimize.testLensReplaceAndOptimize_superFct();
		workTheSystem_test.push_back(checkLendRepAndOpti);
		checkerAndCout(checkLendRepAndOpti, "test lens replace and optimize");
	}

	// test Compare TOM and Zemax Optimizer
	if (testWhatInTestWhatVec(testWhat::tCompareTOMandZemaxOptimizer) || testAll)
	{
		testCompareTOMandZemaxOptimizer checkCompareTOMandZemaxOptimizer;
		bool checkComTOMandZemaxOptimizer = checkCompareTOMandZemaxOptimizer.testCompareTOMandZemaxOptimizer_superFct();
		workTheSystem_test.push_back(checkComTOMandZemaxOptimizer);
		checkerAndCout(checkComTOMandZemaxOptimizer, "test Compare TOM and Zemax Optimizer");
	}

	// test lens replace and optimize statistic two lens system
	if (testWhatInTestWhatVec(testWhat::tLensReplaceAndOptimize_statistic_twoLenses) || testWhatInTestWhatVec(testWhat::tLensReplaceAndOptimize_statistic_ALL) || testAll )
	{
		testLensReplaceAndOptimize_statistic_twoLensSystem testLRaOstatTwoLensSystem{};
		bool testLRaO_statistic_twoLensSystem = testLRaOstatTwoLensSystem.testLRaO_stat_twoLensSystem_superFct();
		workTheSystem_test.push_back(testLRaO_statistic_twoLensSystem);
		checkerAndCout(testLRaO_statistic_twoLensSystem, "test lens replace and optimize statistic two lens system");
	}


	return Math::checkTrueOfVectorElements(workTheSystem_test);
}