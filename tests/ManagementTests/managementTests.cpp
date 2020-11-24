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

		inportExportData::saveStringInTXT(location, nameLocation, totalString);
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
	
	// 
	if (testWhatInTestWhatVec(testWhat::tRayAiming_inf) || testAll)
	{
		testRayAiming testRayAim_inf;
		bool checkRayAiming_inf = testRayAim_inf.checkRayAimingSuperFct_inf();
		workTheSystem_test.push_back(checkRayAiming_inf);
		checkerAndCout(checkRayAiming_inf, "test ray aiming inf");
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

	// test OPD
	if (testWhatInTestWhatVec(testWhat::tOPD) || testAll)
	{
		TestOPD checkTestOPD;
		bool checkOPD = checkTestOPD.checkOPD_superFct();
		workTheSystem_test.push_back(checkOPD);
		checkerAndCout(checkOPD, "test OPD");
	}


	// test global OPD
	if (testWhatInTestWhatVec(testWhat::tGlobalOPD) || testAll)
	{
		TestGlobalOPD checkTestGlobalOPD;
		bool checkGlobalOPD = checkTestGlobalOPD.checkGlobalOPD_superFunction();
		workTheSystem_test.push_back(checkGlobalOPD);
		checkerAndCout(checkGlobalOPD, "test global OPD");
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


	return Math::checkTrueOfVectorElements(workTheSystem_test);
}