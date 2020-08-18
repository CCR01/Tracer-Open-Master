#include "managementTests.h"

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
	}
	
	// test namespace math
	if (testWhatInTestWhatVec(testWhat::tMath) || testAll)
	{
		testMath testNamespaceMath;
		bool Math = testNamespaceMath.checkMethodesMath();
		workTheSystem_test.push_back(Math);
	}
	
	// test fill aperture stop
	if (testWhatInTestWhatVec(testWhat::tFillAS) || testAll)
	{
		testFillAS testClassFillAS;
		bool checkFillAS = testClassFillAS.chekMethodesFillAS();
		workTheSystem_test.push_back(checkFillAS);
	}
	
	// test aperture stop
	if (testWhatInTestWhatVec(testWhat::tApertureStop_LLT) || testAll)
	{
		testApertureStop testClassApertureStop;
		bool checkAperStop = testClassApertureStop.checkApertureStop();
		workTheSystem_test.push_back(checkAperStop);
	}
	
	///test lens calalog from edmund optics
	if (testWhatInTestWhatVec(testWhat::tLensCatalogEO) || testAll)
	{
		TestLensCatalogEO testClassLensCataEO;
		bool checkLensCataEO_TwoSurfaces_1 = testClassLensCataEO.testCatalogEO_TwoSurfaces_1();
		workTheSystem_test.push_back(checkLensCataEO_TwoSurfaces_1);
		bool checkLensCataEO_TwoSurfaces_2 = testClassLensCataEO.testCatalogEO_TwoSurfaces_2();
		workTheSystem_test.push_back(checkLensCataEO_TwoSurfaces_2);
		bool checkLensCataEO_TwoSurfaces_3 = testClassLensCataEO.testCatalogEO_TwoSurfaces_3();
		workTheSystem_test.push_back(checkLensCataEO_TwoSurfaces_3);
		bool checkLensCataEO_ThreeSurfaces = testClassLensCataEO.testCatalogEO_ThreeSurfaces();
		workTheSystem_test.push_back(checkLensCataEO_ThreeSurfaces);
		bool checkLensCataEO_doub_conc_lens = testClassLensCataEO.testCatalogEO_DCV();
		workTheSystem_test.push_back(checkLensCataEO_doub_conc_lens);
		bool checkLensCataEO_PCV = testClassLensCataEO.testcatalogEO_PCV();
		workTheSystem_test.push_back(checkLensCataEO_PCV);
	}
	
	// test spherical surface LLT
	if (testWhatInTestWhatVec(testWhat::tSphericalSurface_LLT) || testAll)
	{
		testSphericalSurface_LLT testClassSphSurface_LLT;
		bool checkSphericalLens = testClassSphSurface_LLT.checkSphericalSurface_LLT();
		workTheSystem_test.push_back(checkSphericalLens);
	}
	
	// test glasses
	if (testWhatInTestWhatVec(testWhat::tGlasses) || testAll)
	{
		testGlasses testClassGlasses;
		bool checkGlasses = testClassGlasses.checkGlasses();
		workTheSystem_test.push_back(checkGlasses);
	}
	
	// test paraxial lens LLT
	if (testWhatInTestWhatVec(testWhat::tParaxialLens_LLT) || testAll)
	{
		testParaxialLens testClassParaxialLens;
		bool checkParaxialLens = testClassParaxialLens.checkMethodesParaxialLens_LLT_superFct();
		workTheSystem_test.push_back(checkParaxialLens);
	}
	
	// test plan geometry LLT
	if (testWhatInTestWhatVec(testWhat::tParaxialLens_LLT) || testAll)
	{
		testPlanSurface testClassPlanSurface;
		bool checkPlanSurface = testClassPlanSurface.checkMethodesPlanSurface();
		workTheSystem_test.push_back(checkPlanSurface);
	}
	
	if (testWhatInTestWhatVec(testWhat::tCardinalPoints) || testAll)
	{
		testCardinalPoints testCarPoints;
		bool checkCardinalPoints = testCarPoints.superFuncTestCalcCardinalPoints();
		workTheSystem_test.push_back(checkCardinalPoints);
	}
	
	if (testWhatInTestWhatVec(testWhat::tRayAiming_obj) || testAll)
	{
		testRayAiming testRayAim_obj;
		bool checkRayAiming_obj = testRayAim_obj.checkRayAimingSuperFct_obj();
		workTheSystem_test.push_back(checkRayAiming_obj);
	}
	
	if (testWhatInTestWhatVec(testWhat::tRayAiming_inf) || testAll)
	{
		testRayAiming testRayAim_inf;
		bool checkRayAiming_inf = testRayAim_inf.checkRayAimingSuperFct_inf();
		workTheSystem_test.push_back(checkRayAiming_inf);
	}
	
	
	if (testWhatInTestWhatVec(testWhat::tRayAiming_12Cores) || testAll)
	{
		testRayAiming_multiThreads_12 testRayAiming_12;
		bool checkRayAiming_12_obj = testRayAiming_12.testRayAiming_multiThreads_12_superFct_obj();
		workTheSystem_test.push_back(checkRayAiming_12_obj);
	}

	if (testWhatInTestWhatVec(testWhat::tGenetic_opti) || testAll)
	{
	
		TestGenetic testGenetic;
		bool checkGenetic = testGenetic.testGeneticSuperFunc();
		workTheSystem_test.push_back(checkGenetic);
	}
	
	if (testWhatInTestWhatVec(testWhat::tGenetic_modes) || testAll)
	{

		TestGenetic testGenetic;
		bool checkGeneticModes = testGenetic.testGenerationModes(-1000.0, 1000.0, 100.0, 50000);
		workTheSystem_test.push_back(checkGeneticModes);
	}
		
	if (testWhatInTestWhatVec(testWhat::tGenetic_cardinalPoints) || testAll)
	{
		TestGenetic testGenetic;
		bool checkGeneticCardnalPoints = testGenetic.testCardinalPointsSuperFct();
		workTheSystem_test.push_back(checkGeneticCardnalPoints);
	}

	// DLS opti rms
	if (testWhatInTestWhatVec(testWhat::tDLS_optiRMS) || testAll)
	{
		testDLS testDLS_optiRMS;
		bool checkDLS_optiRMS = testDLS_optiRMS.testDLS_superFct_optiRMS();
		workTheSystem_test.push_back(checkDLS_optiRMS);
	}

	// DLS opt cardinal points
	if (testWhatInTestWhatVec(testWhat::tDLS_optiCarPoints) || testAll)
	{
		testDLS testDLS_optiCarPoints;
		bool checkDLS_optiCarPoints = testDLS_optiCarPoints.testDLS_superFct_optiCarPoints();
		workTheSystem_test.push_back(checkDLS_optiCarPoints);
	}

	// DLS opt rms and cardinal points
	if (testWhatInTestWhatVec(testWhat::tDLS_optiRMS_carPoints) || testAll)
	{
		testDLS testDLS_optiRMS_CarPoints;
		bool checkDLS_optiRMS_CarPoints = testDLS_optiRMS_CarPoints.testDLS_superFct_optiRMSAndCarPoints();
		workTheSystem_test.push_back(checkDLS_optiRMS_CarPoints);
	}

	// optimize DLS parallel 12 threads
	if (testWhatInTestWhatVec(testWhat::tDLS_Parallel) || testAll)
	{
		testDLS_multiThreads_12 testDLS_multi_12;
		bool checkDLS_multi_12 = testDLS_multi_12.testSuperFunction();
		workTheSystem_test.push_back(checkDLS_multi_12);
	}

	// optimize RMS including Genetic and DLS multicore
	if (testWhatInTestWhatVec(testWhat::tOptiIncluding_GeneticAndDLS_Parallel_RMS) || testAll)
	{
		testOptimizeSystemSuperFct_GeneticAndDLS testOpti_GeneticAndDLS_rms;
		bool checkOpti_GeneticAndDLS_rms = testOpti_GeneticAndDLS_rms.testOptimizeSys_SuperFunction_GeneticDLS_rms();
		workTheSystem_test.push_back(checkOpti_GeneticAndDLS_rms);

	}

	// optimize Cardinal points including Genetic and DLS multicore
	if (testWhatInTestWhatVec(testWhat::tOptiIncluding_GeneticAndDLS_Parallel_CardinalPoints) || testAll)
	{
		testOptimizeSystemSuperFct_GeneticAndDLS testOpti_GeneticAndDLS_carPoints;
		bool checkOpti_GeneticAndDLS_carPoints = testOpti_GeneticAndDLS_carPoints.testOptimizeSystem_SuperFunction_GeneticDLS_carPoints();
		workTheSystem_test.push_back(checkOpti_GeneticAndDLS_carPoints);

	}
	



	return Math::checkTrueOfVectorElements(workTheSystem_test);
}