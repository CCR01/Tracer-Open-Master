#include "testLensCatalogEO.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\..\LensCatalog\EdmundOptics\EdmundOpticsLensCatalog.h"

// test lens catalog
#include "testLensCatalogNameSpace.h"

// often use
#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

TestLensCatalogEO::TestLensCatalogEO() {};
TestLensCatalogEO::~TestLensCatalogEO() {};


bool TestLensCatalogEO::testcatalogEO_PCV()
{
	// test VIS-NIR beschichtete PCV Linsen
	// https://www.edmundoptics.de/f/vis-nir-coated-plano-concave-pcv-lenses/13512/

	std::vector<bool> workTheLensCatalogEO_TwoSurfaces;
	//---
	// load lens catalog from edmund optics
	EdmundOpticsLensCatalog edmundLensCatalog;
	edmundLensCatalog.loadLensCatalogEO_plan_concav_lenses_VIS_NIR(); //https://www.edmundoptics.de/f/vis-nir-coated-plano-concave-pcv-lenses/13512/
	// test light ray 1
	Ray_LLT testRay1({ 0.0,0.25,-1.0 }, { 0.0,0.0,1.0 }, 1.0);
	Light_LLT light1;
	light1.setWavelength(550.0);
	LightRayStruct testLightRay1(light1, testRay1, 1);
	//---


	//EO84380
	OpticalSystem_LLT EO84380_LLT(edmundLensCatalog.getEO84380().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO84380().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO84380 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO84380_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.44187608216,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO84381
	OpticalSystem_LLT EO84381_LLT(edmundLensCatalog.getEO84381().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO84381().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO84381 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO84381_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.37785995665,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84381);

	//EO45910
	OpticalSystem_LLT EO45910_LLT(edmundLensCatalog.getEO45910().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45910().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45910 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45910_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.43257948412,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO48345
	OpticalSystem_LLT EO48345_LLT(edmundLensCatalog.getEO48345().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO48345().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO48345 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO48345_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.37166623317,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO45911
	OpticalSystem_LLT EO45911_LLT(edmundLensCatalog.getEO45911().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45911().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45911 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45911_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.38858188858,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO48696
	OpticalSystem_LLT EO48696_LLT(edmundLensCatalog.getEO48696().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO48696().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO48696 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO48696_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.36646421692,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO45912
	OpticalSystem_LLT EO45912_LLT(edmundLensCatalog.getEO45912().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45912().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45912 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45912_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.33762222888,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO45913
	OpticalSystem_LLT EO45913_LLT(edmundLensCatalog.getEO45913().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45913().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45913 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45913_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.36221639393,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO48346
	OpticalSystem_LLT EO48346_LLT(edmundLensCatalog.getEO48346().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO48346().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO48346 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO48346_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.033418477602,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO45914
	OpticalSystem_LLT EO45914_LLT(edmundLensCatalog.getEO45914().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45914().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45914 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45914_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.30614277256,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO45915
	OpticalSystem_LLT EO45915_LLT(edmundLensCatalog.getEO45915().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45915().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45915 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45915_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.28431116574,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO45916
	OpticalSystem_LLT EO45916_LLT(edmundLensCatalog.getEO45916().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45916().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45916 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45916_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.3346875578,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO48697
	OpticalSystem_LLT EO48697_LLT(edmundLensCatalog.getEO48697().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO48697().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO48697 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO48697_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.31179235807,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO48347
	OpticalSystem_LLT EO48347_LLT(edmundLensCatalog.getEO48347().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO48347().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO48347 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO48347_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.29840691558,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO45917
	OpticalSystem_LLT EO45917_LLT(edmundLensCatalog.getEO45917().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45917().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45917 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45917_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.28980054720,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO45918
	OpticalSystem_LLT EO45918_LLT(edmundLensCatalog.getEO45918().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45918().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45918 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45918_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.269885380080,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO45919
	OpticalSystem_LLT EO45919_LLT(edmundLensCatalog.getEO45919().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45919().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45919 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45919_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.27902902805,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO45920
	OpticalSystem_LLT EO45920_LLT(edmundLensCatalog.getEO45920().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45920().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45920 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45920_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.2738697173,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO45921
	OpticalSystem_LLT EO45921_LLT(edmundLensCatalog.getEO45921().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45921().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45921 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45921_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.26909250683,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO45922
	OpticalSystem_LLT EO45922_LLT(edmundLensCatalog.getEO45922().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45922().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45922 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45922_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.28483122042,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO48698
	OpticalSystem_LLT EO48698_LLT(edmundLensCatalog.getEO48698().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO48698().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO48698 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO48698_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23919047185,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO45923
	OpticalSystem_LLT EO45923_LLT(edmundLensCatalog.getEO45923().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45923().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45923 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45923_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.26909250683,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO45924
	OpticalSystem_LLT EO45924_LLT(edmundLensCatalog.getEO45924().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45924().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45924 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45924_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.25954497468,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO45925
	OpticalSystem_LLT EO45925_LLT(edmundLensCatalog.getEO45925().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45925().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45925 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45925_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.27080199061,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//EO45926
	OpticalSystem_LLT EO45926_LLT(edmundLensCatalog.getEO45926().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45926().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45926 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45926_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.25837885356,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO84380);

	//---
	bool returnCheckTheLensCatalogEO_TwoSurfaces = Math::checkTrueOfVectorElements(workTheLensCatalogEO_TwoSurfaces);
	return returnCheckTheLensCatalogEO_TwoSurfaces;
	//---
}








// test Doppelkonkave (DCV) Linsen VIS-NIR AR beschichtet 
// https://www.edmundoptics.de/f/vis-nir-coated-double-concave-dcv-lenses/13540/
bool TestLensCatalogEO::testCatalogEO_DCV()
{
	std::vector<bool> workTheLensCatalogEO_TwoSurfaces;
	//---
	// load lens catalog from edmund optics
	EdmundOpticsLensCatalog edmundLensCatalog;
	edmundLensCatalog.loadLensCatalogEO_double_concav_lenses_VIS_NIR(); //https://www.edmundoptics.de/f/vis-nir-coated-double-concave-dcv-lenses/13540/
	// test light ray 1
	Ray_LLT testRay1({ 0.0,0.25,-1.0 }, { 0.0,0.0,1.0 }, 1.0);
	Light_LLT light1;
	light1.setWavelength(550.0);
	LightRayStruct testLightRay1(light1, testRay1, 1);
	//---

	//https://www.edmundoptics.de/f/vis-nir-coated-plano-convex-pcx-lenses/12278/
	//EO45927
	OpticalSystem_LLT EO45927_LLT(edmundLensCatalog.getEO45927().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45927().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45927 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45927_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.41418556709,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45927);

	//EO48941
	OpticalSystem_LLT EO48941_LLT(edmundLensCatalog.getEO48941().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO48941().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO48941 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO48941_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.37058949203,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO48941);

	//EO48699
	OpticalSystem_LLT EO48699_LLT(edmundLensCatalog.getEO48699().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO48699().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO48699 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO48699_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.34044772606,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO48699);

	//EO48348
	OpticalSystem_LLT EO48348_LLT(edmundLensCatalog.getEO48348().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO48348().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO48348 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO48348_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.34409365344,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO48348);

	//EO48942
	OpticalSystem_LLT EO48942_LLT(edmundLensCatalog.getEO48942().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO48942().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO48942 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO48942_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.33217196781,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO48942);

	//EO48700
	OpticalSystem_LLT EO48700_LLT(edmundLensCatalog.getEO48700().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO48700().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO48700 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO48700_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.30556129885,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO48700);

	//EO45928
	OpticalSystem_LLT EO45928_LLT(edmundLensCatalog.getEO45928().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45928().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45928 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45928_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.30903324270,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45928);

	//EO48943
	OpticalSystem_LLT EO48943_LLT(edmundLensCatalog.getEO48943().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO48943().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO48943 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO48943_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.30082365116,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO48943);

	//EO48701
	OpticalSystem_LLT EO48701_LLT(edmundLensCatalog.getEO48701().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO48701().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO48701 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO48701_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.28814980751,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO48701);

	//EO45929
	OpticalSystem_LLT EO45929_LLT(edmundLensCatalog.getEO45929().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45929().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45929 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45929_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.29475372241,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45929);

	//EO45930
	OpticalSystem_LLT EO45930_LLT(edmundLensCatalog.getEO45930().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45930().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45930 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45930_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.28214395206,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45930);

	//EO45931
	OpticalSystem_LLT EO45931_LLT(edmundLensCatalog.getEO45931().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45931().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45931 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45931_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.26663813165,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45931);

	//EO45932
	OpticalSystem_LLT EO45932_LLT(edmundLensCatalog.getEO45932().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45932().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45932 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45932_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.26663859272,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45932);



	//---
	bool returnCheckTheLensCatalogEO_TwoSurfaces = Math::checkTrueOfVectorElements(workTheLensCatalogEO_TwoSurfaces);
	return returnCheckTheLensCatalogEO_TwoSurfaces;
	//---

}

// test one lens with two surfaces;
bool TestLensCatalogEO::testOneLensTwoSurfaces(LightRayStruct lightRay, OpticalSystem_LLT optSysElement, VectorStructR3 positionImageSurface, VectorStructR3 targetVector)
{
	Absorb_LLT absorb;

	// build LLT system in LLT
	OpticalSystem_LLT testOptSys_LLT = optSysElement;
	PlanGeometry_LLT ImageSurface(9999, positionImageSurface, { 0.0,0.0,1.0 }, 1.0, 1.0);
	testOptSys_LLT.fillInSurfaceAndInteracAtPos_i(2, ImageSurface.clone(), absorb.clone());

	// trace the ray
	SequentialRayTracing seqTrace(testOptSys_LLT);
	seqTrace.sequentialRayTracing(lightRay);

	// compate target point with real intersection point
	VectorStructR3 intersectionPoint = seqTrace.getAllInterPointsAtSurf_i_notFiltered(2).at(0);
	bool returnCheckLens = Math::compareTwoVectorStructR3_decimals(targetVector, intersectionPoint, 3);

	return returnCheckLens;

}

// test one lens with three surfaces;
bool TestLensCatalogEO::testOneLensThreeSurfaces(LightRayStruct lightRay, OpticalSystem_LLT optSysElement, VectorStructR3 positionImageSurface, VectorStructR3 targetVector)
{
	Absorb_LLT absorb;

	// build LLT system in LLT
	OpticalSystem_LLT testOptSys_LLT = optSysElement;
	PlanGeometry_LLT ImageSurface(9999, positionImageSurface, { 0.0,0.0,1.0 }, 1.0, 1.0);
	testOptSys_LLT.fillInSurfaceAndInteracAtPos_i(3, ImageSurface.clone(), absorb.clone());

	// trace the ray
	SequentialRayTracing seqTrace(testOptSys_LLT);
	seqTrace.sequentialRayTracing(lightRay);

	// compare target point with real intersection point
	VectorStructR3 intersectionPoint = seqTrace.getAllInterPointsAtSurf_i_notFiltered(3).at(0);
	bool returnCheckAchromat = Math::compareTwoVectorStructR3_decimals(targetVector, intersectionPoint, 3);

	return returnCheckAchromat;

}




// test the lens catalog from edmund optics
bool TestLensCatalogEO::testCatalogEO_TwoSurfaces_1()
{
	std::vector<bool> workTheLensCatalogEO_TwoSurfaces;
	//---
	// load lens catalog from edmund optics
	EdmundOpticsLensCatalog edmundLensCatalog;
	edmundLensCatalog.loadLensCatalogEO_plan_convex_lenses_VIS_NIR(); //https://www.edmundoptics.de/f/vis-nir-coated-plano-convex-pcx-lenses/12278/
	// test light ray 0
	Ray_LLT testRay0({ 0.0,1.0,0.0 }, { 0.0,0.0,1.0 }, 1.0);
	Light_LLT light0;
	light0.setWavelength(550.0);
	LightRayStruct testLightRay0(light0, testRay0, 1);
	//---

	// test light ray 1
	Ray_LLT testRay1({ 0.0,0.25,0.0 }, { 0.0,0.0,1.0 }, 1.0);
	Light_LLT light1;
	light1.setWavelength(550.0);
	LightRayStruct testLightRay1(light1, testRay1, 1);
	//---

	//https://www.edmundoptics.de/f/vis-nir-coated-plano-convex-pcx-lenses/12278/
	//EO65289
	OpticalSystem_LLT EO65289_LLT(edmundLensCatalog.getEO65289().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65289().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO65289 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO65289_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,-2.0509695307,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO65289);

	//EO65290
	OpticalSystem_LLT EO65290_LLT(edmundLensCatalog.getEO65290().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65290().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO65290 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO65290_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,-0.97773034083,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO65290);

	//EO65291
	OpticalSystem_LLT EO65291_LLT(edmundLensCatalog.getEO65291().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65291().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO65291 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO65291_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,-0.5438479557,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO65291);

	//EO65292
	OpticalSystem_LLT EO65292_LLT(edmundLensCatalog.getEO65292().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65292().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO65292 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO65292_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,-0.33946896020,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO65292);

	//EO65293
	OpticalSystem_LLT EO65293_LLT(edmundLensCatalog.getEO65293().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65293().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO65293 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO65293_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,-0.97773034083,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO65293);

	//EO65294
	OpticalSystem_LLT EO65294_LLT(edmundLensCatalog.getEO65294().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65294().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO65294 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO65294_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,-0.54060333421,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO65294);

	//EO65295
	OpticalSystem_LLT EO65295_LLT(edmundLensCatalog.getEO65295().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65295().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO65295 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO65295_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,-0.3394689602,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO65295);

	//EO65296
	OpticalSystem_LLT EO65296_LLT(edmundLensCatalog.getEO65296().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65296().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO65296 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO65296_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,-0.54060333421,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO65296);

	//EO65297
	OpticalSystem_LLT EO65297_LLT(edmundLensCatalog.getEO65297().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65297().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO65297 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO65297_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,-0.3394689602,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO65297);

	//EO65298
	OpticalSystem_LLT EO65298_LLT(edmundLensCatalog.getEO65298().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65298().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO65298 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO65298_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,-0.14032231539,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO65298);

	//EO65299
	OpticalSystem_LLT EO65299_LLT(edmundLensCatalog.getEO65299().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65299().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO65299 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO65299_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,-0.042086858578,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO65299);

	//EO65300
	OpticalSystem_LLT EO65300_LLT(edmundLensCatalog.getEO65300().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65300().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO65300 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO65300_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,-0.33946896020,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO65300);

	//EO65301
	OpticalSystem_LLT EO65301_LLT(edmundLensCatalog.getEO65301().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65301().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO65301 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO65301_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,-0.22060870057,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO65301);

	//EO65302
	OpticalSystem_LLT EO65302_LLT(edmundLensCatalog.getEO65302().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65302().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO65302 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO65302_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,-0.14032231539,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO65302);

	//EO65303
	OpticalSystem_LLT EO65303_LLT(edmundLensCatalog.getEO65303().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65303().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO65303 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO65303_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,-0.042086858578,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO65303);

	//EO65304
	OpticalSystem_LLT EO65304_LLT(edmundLensCatalog.getEO65304().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65304().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO65304 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO65304_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.016560070848,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO65304);

	//EO49174
	OpticalSystem_LLT EO49174_LLT(edmundLensCatalog.getEO49174().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49174().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO49174 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO49174_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,-0.097958831405,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO49174);

	//EO49175
	OpticalSystem_LLT EO49175_LLT(edmundLensCatalog.getEO49175().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49175().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO49175 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO49175_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.015563510741,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO49175);

	//EO49176
	OpticalSystem_LLT EO49176_LLT(edmundLensCatalog.getEO49176().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49176().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO49176 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO49176_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.066368142753,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO49176);

	//EO49177
	OpticalSystem_LLT EO49177_LLT(edmundLensCatalog.getEO49177().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49177().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO49177 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO49177_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.099961413299,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO49177);

	//EO49178
	OpticalSystem_LLT EO49178_LLT(edmundLensCatalog.getEO49178().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49178().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO49178 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO49178_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.12485272665,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO49178);

	//EO49179
	OpticalSystem_LLT EO49179_LLT(edmundLensCatalog.getEO49179().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49179().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO49179 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO49179_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.15316798237,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO49179);

	//EO49180
	OpticalSystem_LLT EO49180_LLT(edmundLensCatalog.getEO49180().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49180().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO49180 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO49180_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.17386732696,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO49180);

	//EO47850
	OpticalSystem_LLT EO47850_LLT(edmundLensCatalog.getEO47850().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47850().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47850 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47850_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,-0.017357852809,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47850);

	//EO47851
	OpticalSystem_LLT EO47851_LLT(edmundLensCatalog.getEO47851().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47851().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47851 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47851_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.073534217879,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47851);

	//EO47852
	OpticalSystem_LLT EO47852_LLT(edmundLensCatalog.getEO47852().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47852().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47852 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47852_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.11054958859,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47852);

	//EO47853
	OpticalSystem_LLT EO47853_LLT(edmundLensCatalog.getEO47853().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47853().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47853 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47853_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.13908666460,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47853);

	//EO47854
	OpticalSystem_LLT EO47854_LLT(edmundLensCatalog.getEO47854().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47854().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47854 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47854_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.15661390359,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47854);

	//EO47855
	OpticalSystem_LLT EO47855_LLT(edmundLensCatalog.getEO47855().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47855().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47855 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47855_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.034746487193,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47855);

	//EO47856
	OpticalSystem_LLT EO47856_LLT(edmundLensCatalog.getEO47856().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47856().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47856 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47856_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.13324445042,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47856);

	//EO47857
	OpticalSystem_LLT EO47857_LLT(edmundLensCatalog.getEO47857().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47857().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47857 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47857_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.040548644312,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47857);

	//EO48661
	OpticalSystem_LLT EO48661_LLT(edmundLensCatalog.getEO48661().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO48661().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO48661 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO48661_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.11024381103,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO48661);

	//EO47858
	OpticalSystem_LLT EO47858_LLT(edmundLensCatalog.getEO47858().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47858().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47858 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47858_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.13865709148,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47858);

	//EO47859
	OpticalSystem_LLT EO47859_LLT(edmundLensCatalog.getEO47859().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47859().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47859 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47859_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.15839477342,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47859);

	//EO47860
	OpticalSystem_LLT EO47860_LLT(edmundLensCatalog.getEO47860().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47860().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47860 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47860_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.17551566914,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47860);

	//EO49913
	OpticalSystem_LLT EO49913_LLT(edmundLensCatalog.getEO49913().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49913().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO49913 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO49913_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.19374753745,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO49913);

	//EO87917
	OpticalSystem_LLT EO87917_LLT(edmundLensCatalog.getEO87917().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO87917().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO87917 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO87917_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.20532353675,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO87917);

	//EO87918
	OpticalSystem_LLT EO87918_LLT(edmundLensCatalog.getEO87918().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO87918().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO87918 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO87918_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.21275968525,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO87918);

	//EO45465
	OpticalSystem_LLT EO45465_LLT(edmundLensCatalog.getEO45465().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45465().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45465 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45465_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.086322447383,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45465);

	//EO49914
	OpticalSystem_LLT EO49914_LLT(edmundLensCatalog.getEO49914().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49914().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO49914 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO49914_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.11915719818,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO49914);

	//EO45466
	OpticalSystem_LLT EO45466_LLT(edmundLensCatalog.getEO45466().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45466().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45466 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45466_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.1298546248,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45466);

	//EO38483
	OpticalSystem_LLT EO38483_LLT(edmundLensCatalog.getEO38483().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38483().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38483 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38483_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.14002893337,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38483);

	//EO45467
	OpticalSystem_LLT EO45467_LLT(edmundLensCatalog.getEO45467().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45467().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45467 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45467_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.15688416440,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45467);

	//EO45468
	OpticalSystem_LLT EO45468_LLT(edmundLensCatalog.getEO45468().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45468().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45468 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45468_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.17780173211,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45468);

	//EO45469
	OpticalSystem_LLT EO45469_LLT(edmundLensCatalog.getEO45469().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45469().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45469 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45469_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.18707524594,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45469);

	//EO38484
	OpticalSystem_LLT EO38484_LLT(edmundLensCatalog.getEO38484().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38484().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38484 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38484_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.1935334169,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38484);

	//EO45470
	OpticalSystem_LLT EO45470_LLT(edmundLensCatalog.getEO45470().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45470().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45470 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45470_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.19606535180,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45470);

	//EO45471
	OpticalSystem_LLT EO45471_LLT(edmundLensCatalog.getEO45471().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45471().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45471 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45471_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.20309298184,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45471);

	//EO38485
	OpticalSystem_LLT EO38485_LLT(edmundLensCatalog.getEO38485().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38485().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38485 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38485_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.20480951456,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38485);

	//EO45472
	OpticalSystem_LLT EO45472_LLT(edmundLensCatalog.getEO45472().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45472().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45472 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45472_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.21190282030,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45472);

	//EO45473
	OpticalSystem_LLT EO45473_LLT(edmundLensCatalog.getEO45473().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45473().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45473 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45473_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.2189826360,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45473);

	//EO47381
	OpticalSystem_LLT EO47381_LLT(edmundLensCatalog.getEO47381().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47381().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47381 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47381_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22673322600,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47381);

	//EO67178
	OpticalSystem_LLT EO67178_LLT(edmundLensCatalog.getEO67178().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO67178().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO67178 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO67178_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23138469008,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO67178);

	//EO45696
	OpticalSystem_LLT EO45696_LLT(edmundLensCatalog.getEO45696().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45696().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45696 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45696_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23449032778,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45696);

	//EO45474
	OpticalSystem_LLT EO45474_LLT(edmundLensCatalog.getEO45474().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45474().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45474 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45474_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.14705177037,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45474);

	//EO49915
	OpticalSystem_LLT EO49915_LLT(edmundLensCatalog.getEO49915().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49915().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO49915 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO49915_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.16821147677,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO49915);

	//EO45475
	OpticalSystem_LLT EO45475_LLT(edmundLensCatalog.getEO45475().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45475().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45475 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45475_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.17644790262,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45475);

	//EO49916
	OpticalSystem_LLT EO49916_LLT(edmundLensCatalog.getEO49916().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49916().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO49916 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO49916_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.1835168895,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO49916);

	//EO45476
	OpticalSystem_LLT EO45476_LLT(edmundLensCatalog.getEO45476().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45476().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45476 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45476_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.19191426253,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45476);

	//EO38487
	OpticalSystem_LLT EO38487_LLT(edmundLensCatalog.getEO38487().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38487().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38487 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38487_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.19674522513,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38487);

	//EO45477
	OpticalSystem_LLT EO45477_LLT(edmundLensCatalog.getEO45477().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45477().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45477 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45477_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.20051818221,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45477);

	//EO38488
	OpticalSystem_LLT EO38488_LLT(edmundLensCatalog.getEO38488().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38488().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38488 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38488_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.20669426262,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38488);

	//EO45478
	OpticalSystem_LLT EO45478_LLT(edmundLensCatalog.getEO45478().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45478().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45478 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45478_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.2114784410,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45478);

	//EO45479
	OpticalSystem_LLT EO45479_LLT(edmundLensCatalog.getEO45479().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45479().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45479 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45479_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22064778602,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45479);

	//EO45703
	OpticalSystem_LLT EO45703_LLT(edmundLensCatalog.getEO45703().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45703().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45703 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45703_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22506873854,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45703);

	//EO67179
	OpticalSystem_LLT EO67179_LLT(edmundLensCatalog.getEO67179().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO67179().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO67179 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO67179_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22995168294,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO67179);

	//EO67180
	OpticalSystem_LLT EO67180_LLT(edmundLensCatalog.getEO67180().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO67180().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO67180 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO67180_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23496200566,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO67180);

	//EO67181
	OpticalSystem_LLT EO67181_LLT(edmundLensCatalog.getEO67181().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO67181().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO67181 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO67181_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23796873574,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO67181);

	//EO38486
	OpticalSystem_LLT EO38486_LLT(edmundLensCatalog.getEO38486().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38486().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38486 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38486_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.15407520737,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38486);

	//EO63519
	OpticalSystem_LLT EO63519_LLT(edmundLensCatalog.getEO63519().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63519().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63519 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO63519_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.16020158475,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO63519);

	//EO63520
	OpticalSystem_LLT EO63520_LLT(edmundLensCatalog.getEO63520().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63520().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63520 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO63520_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.18825643199,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO63520);

	//EO63521
	OpticalSystem_LLT EO63521_LLT(edmundLensCatalog.getEO63521().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63521().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63521 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO63521_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.20017115391,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO63521);

	//EO63522
	OpticalSystem_LLT EO63522_LLT(edmundLensCatalog.getEO63522().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63522().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63522 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO63522_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.21012107728,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO63522);

	//EO63523
	OpticalSystem_LLT EO63523_LLT(edmundLensCatalog.getEO63523().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63523().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63523 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO63523_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.2167583883,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO63523);

	//EO63524
	OpticalSystem_LLT EO63524_LLT(edmundLensCatalog.getEO63524().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63524().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63524 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO63524_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22507193764,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO63524);

	//EO63525
	OpticalSystem_LLT EO63525_LLT(edmundLensCatalog.getEO63525().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63525().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63525 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO63525_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23005892751,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO63525);

	//EO63526
	OpticalSystem_LLT EO63526_LLT(edmundLensCatalog.getEO63526().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63526().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63526 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO63526_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23670535819,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO63526);

	//EO63527
	OpticalSystem_LLT EO63527_LLT(edmundLensCatalog.getEO63527().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63527().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63527 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO63527_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.24002876298,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO63527);

	//EO45480
	OpticalSystem_LLT EO45480_LLT(edmundLensCatalog.getEO45480().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45480().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45480 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45480_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.18213132820,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45480);

	//EO45481
	OpticalSystem_LLT EO45481_LLT(edmundLensCatalog.getEO45481().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45481().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45481 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45481_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.19208962567,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45481);

	//EO45482
	OpticalSystem_LLT EO45482_LLT(edmundLensCatalog.getEO45482().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45482().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45482 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45482_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.19704995059,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45482);

	//EO49917
	OpticalSystem_LLT EO49917_LLT(edmundLensCatalog.getEO49917().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49917().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO49917 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO49917_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.2023123594,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO49917);

	//EO45483
	OpticalSystem_LLT EO45483_LLT(edmundLensCatalog.getEO45483().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45483().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45483 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45483_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.20780280423,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45483);

	//EO45484
	OpticalSystem_LLT EO45484_LLT(edmundLensCatalog.getEO45484().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45484().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45484 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45484_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.21675838834,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45484);

	//EO33355
	OpticalSystem_LLT EO33355_LLT(edmundLensCatalog.getEO33355().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO33355().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO33355 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO33355_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22231293599,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO33355);

	//EO45485
	OpticalSystem_LLT EO45485_LLT(edmundLensCatalog.getEO45485().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45485().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45485 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45485_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22566544054,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45485);

	//EO45486
	OpticalSystem_LLT EO45486_LLT(edmundLensCatalog.getEO45486().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45486().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45486 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45486_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22834777091,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45486);

	//EO45487
	OpticalSystem_LLT EO45487_LLT(edmundLensCatalog.getEO45487().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45487().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45487 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45487_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23153772710,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45487);

	//EO45488
	OpticalSystem_LLT EO45488_LLT(edmundLensCatalog.getEO45488().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45488().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45488 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45488_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23267500624,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45488);

	//EO45705
	OpticalSystem_LLT EO45705_LLT(edmundLensCatalog.getEO45705().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45705().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45705 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45705_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23543785133,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45705);

	//EO45489
	OpticalSystem_LLT EO45489_LLT(edmundLensCatalog.getEO45489().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45489().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45489 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45489_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23762517915,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45489);

	//EO45490
	OpticalSystem_LLT EO45490_LLT(edmundLensCatalog.getEO45490().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45490().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45490 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45490_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23960050295,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45490);

	//EO38501
	OpticalSystem_LLT EO38501_LLT(edmundLensCatalog.getEO38501().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38501().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38501 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38501_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.19698290652,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38501);

	//EO38506
	OpticalSystem_LLT EO38506_LLT(edmundLensCatalog.getEO38506().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38506().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38506 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38506_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22004885898,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38506);

	//EO62591
	OpticalSystem_LLT EO62591_LLT(edmundLensCatalog.getEO62591().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO62591().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO62591 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO62591_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.18587545856,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO62591);

	//EO62592
	OpticalSystem_LLT EO62592_LLT(edmundLensCatalog.getEO62592().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO62592().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO62592 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO62592_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.11270296618,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO62592);


	//EO62593
	OpticalSystem_LLT EO62593_LLT(edmundLensCatalog.getEO62593().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO62593().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO62593 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO62593_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.20228482096,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO62593);

	//EO38515
	OpticalSystem_LLT EO38515_LLT(edmundLensCatalog.getEO38515().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38515().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38515 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38515_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.20359708270,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38515);

	//EO62594
	OpticalSystem_LLT EO62594_LLT(edmundLensCatalog.getEO62594().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO62594().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO62594 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO62594_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.21075884407,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO62594);

	//EO38516
	OpticalSystem_LLT EO38516_LLT(edmundLensCatalog.getEO38516().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38516().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38516 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38516_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.21592350599,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38516);

	//EO62595
	OpticalSystem_LLT EO62595_LLT(edmundLensCatalog.getEO62595().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO62595().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO62595 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO62595_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.21863977818,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO62595);

	//EO62596
	OpticalSystem_LLT EO62596_LLT(edmundLensCatalog.getEO62596().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO62596().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO62596 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO62596_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22383139159,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO62596);

	//EO38517
	OpticalSystem_LLT EO38517_LLT(edmundLensCatalog.getEO38517().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38517().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38517 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38517_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22357277004,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38517);

	//EO62597
	OpticalSystem_LLT EO62597_LLT(edmundLensCatalog.getEO62597().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO62597().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO62597 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO62597_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22711579002,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO62597);

	//EO62598
	OpticalSystem_LLT EO62598_LLT(edmundLensCatalog.getEO62598().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO62598().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO62598 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO62598_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22952717422,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO62598);

	//EO45491
	OpticalSystem_LLT EO45491_LLT(edmundLensCatalog.getEO45491().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45491().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45491 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45491_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.11947903465,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45491);


	//EO49918
	OpticalSystem_LLT EO49918_LLT(edmundLensCatalog.getEO49918().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49918().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO49918 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO49918_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.20269535812,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO49918);

	//EO63528
	OpticalSystem_LLT EO63528_LLT(edmundLensCatalog.getEO63528().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63528().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63528 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO63528_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.20642362561,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO63528);

	//EO45492
	OpticalSystem_LLT EO45492_LLT(edmundLensCatalog.getEO45492().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45492().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45492 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45492_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.20917283180,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45492);

	//EO45493
	OpticalSystem_LLT EO45493_LLT(edmundLensCatalog.getEO45493().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45493().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45493 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45493_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.21731467689,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45493);

	//---
	bool returnCheckTheLensCatalogEO_TwoSurfaces = Math::checkTrueOfVectorElements(workTheLensCatalogEO_TwoSurfaces);
	return returnCheckTheLensCatalogEO_TwoSurfaces;
	//---

}



bool TestLensCatalogEO::testCatalogEO_TwoSurfaces_2()
{
	std::vector<bool> workTheLensCatalogEO_TwoSurfaces;
	//---
	// load lens catalog from edmund optics
	EdmundOpticsLensCatalog edmundLensCatalog;
	edmundLensCatalog.loadLensCatalogEO_plan_convex_lenses_VIS_NIR(); //https://www.edmundoptics.de/f/vis-nir-coated-plano-convex-pcx-lenses/12278/
	// test light ray 0
	Ray_LLT testRay0({ 0.0,1.0,0.0 }, { 0.0,0.0,1.0 }, 1.0);
	Light_LLT light0;
	light0.setWavelength(550.0);
	LightRayStruct testLightRay0(light0, testRay0, 1);
	//---

	// test light ray 1
	Ray_LLT testRay1({ 0.0,0.25,0.0 }, { 0.0,0.0,1.0 }, 1.0);
	Light_LLT light1;
	light1.setWavelength(550.0);
	LightRayStruct testLightRay1(light1, testRay1, 1);
	//---

	//https://www.edmundoptics.de/f/vis-nir-coated-plano-convex-pcx-lenses/12278/
	//EO45494
	OpticalSystem_LLT EO45494_LLT(edmundLensCatalog.getEO45494().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45494().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45494 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45494_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22507193764,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45494);

	//EO49919
	OpticalSystem_LLT EO49919_LLT(edmundLensCatalog.getEO49919().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49919().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO49919 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO49919_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.2268957698,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO49919);

	//EO47382
	OpticalSystem_LLT EO47382_LLT(edmundLensCatalog.getEO47382().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47382().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47382 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47382_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23208482164,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47382);

	//EO47383
	OpticalSystem_LLT EO47383_LLT(edmundLensCatalog.getEO47383().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47383().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47383 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47383_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23536917207,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47383);

	//EO45706
	OpticalSystem_LLT EO45706_LLT(edmundLensCatalog.getEO45706().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45706().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45706 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45706_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.24002876298,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45706);

	//EO48426
	OpticalSystem_LLT EO48426_LLT(edmundLensCatalog.getEO48426().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO48426().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO48426 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO48426_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.14093604305,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO48426);


	//EO45496
	OpticalSystem_LLT EO45496_LLT(edmundLensCatalog.getEO45496().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45496().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45496 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45496_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22368298315,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45496);

	//EO45497
	OpticalSystem_LLT EO45497_LLT(edmundLensCatalog.getEO45497().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45497().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45497 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45497_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23153772710,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45497);

	//EO45498
	OpticalSystem_LLT EO45498_LLT(edmundLensCatalog.getEO45498().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45498().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45498 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45498_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23615534015,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45498);

	//EO45499
	OpticalSystem_LLT EO45499_LLT(edmundLensCatalog.getEO45499().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45499().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45499 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45499_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.21261706327,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45499);

	//EO49921
	OpticalSystem_LLT EO49921_LLT(edmundLensCatalog.getEO49921().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49921().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO49921 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO49921_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.21741285781,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO49921);

	//EO45707
	OpticalSystem_LLT EO45707_LLT(edmundLensCatalog.getEO45707().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45707().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45707 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45707_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22330411201,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45707);

	//EO49922
	OpticalSystem_LLT EO49922_LLT(edmundLensCatalog.getEO49922().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49922().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO49922 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO49922_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22518793695,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO49922);

	//EO45500
	OpticalSystem_LLT EO45500_LLT(edmundLensCatalog.getEO45500().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45500().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45500 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45500_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22914110684,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45500);

	//EO45501
	OpticalSystem_LLT EO45501_LLT(edmundLensCatalog.getEO45501().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45501().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45501 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45501_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23045294362,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45501);

	//EO45502
	OpticalSystem_LLT EO45502_LLT(edmundLensCatalog.getEO45502().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45502().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45502 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45502_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23552437512,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45502);

	//EO45503
	OpticalSystem_LLT EO45503_LLT(edmundLensCatalog.getEO45503().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45503().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45503 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45503_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23575741413,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45503);

	//EO47385
	OpticalSystem_LLT EO47385_LLT(edmundLensCatalog.getEO47385().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47385().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47385 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47385_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23688341079,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47385);

	//EO45708
	OpticalSystem_LLT EO45708_LLT(edmundLensCatalog.getEO45708().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45708().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45708 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45708_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.24114223904,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45708);

	//EO47386
	OpticalSystem_LLT EO47386_LLT(edmundLensCatalog.getEO47386().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47386().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47386 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47386_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.24332909024,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47386);

	//EO45504
	OpticalSystem_LLT EO45504_LLT(edmundLensCatalog.getEO45504().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45504().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45504 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45504_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.18186965970,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45504);

	//EO45505
	OpticalSystem_LLT EO45505_LLT(edmundLensCatalog.getEO45505().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45505().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45505 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45505_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.18938947699,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45505);

	//EO45506
	OpticalSystem_LLT EO45506_LLT(edmundLensCatalog.getEO45506().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45506().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45506 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45506_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.19555802356,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45506);

	//EO45507
	OpticalSystem_LLT EO45507_LLT(edmundLensCatalog.getEO45507().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45507().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45507 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45507_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.19928096360,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45507);

	//EO45508
	OpticalSystem_LLT EO45508_LLT(edmundLensCatalog.getEO45508().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45508().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45508 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45508_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23331384321,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45508);

	//EO45509
	OpticalSystem_LLT EO45509_LLT(edmundLensCatalog.getEO45509().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45509().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45509 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45509_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23580987064,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45509);

	//EO45510
	OpticalSystem_LLT EO45510_LLT(edmundLensCatalog.getEO45510().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45510().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45510 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45510_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23841841733,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45510);

	//EO45511
	OpticalSystem_LLT EO45511_LLT(edmundLensCatalog.getEO45511().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45511().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45511 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45511_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23957974879,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45511);

	//EO45512
	OpticalSystem_LLT EO45512_LLT(edmundLensCatalog.getEO45512().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45512().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45512 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45512_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.24114223904,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45512);

	//EO45513
	OpticalSystem_LLT EO45513_LLT(edmundLensCatalog.getEO45513().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45513().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45513 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45513_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.24236784817,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45513);

	//EO45514
	OpticalSystem_LLT EO45514_LLT(edmundLensCatalog.getEO45514().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45514().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45514 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45514_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.24364028894,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45514);

	//EO45515
	OpticalSystem_LLT EO45515_LLT(edmundLensCatalog.getEO45515().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45515().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45515 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45515_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.24454846980,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45515);

	//EO33361
	OpticalSystem_LLT EO33361_LLT(edmundLensCatalog.getEO33361().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO33361().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO33361 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO33361_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.24509982013,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO33361);

	//EO67182
	OpticalSystem_LLT EO67182_LLT(edmundLensCatalog.getEO67182().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO67182().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO67182 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO67182_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.24601129886,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO67182);

	//EO67183
	OpticalSystem_LLT EO67183_LLT(edmundLensCatalog.getEO67183().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO67183().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO67183 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO67183_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.24667606180,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO67183);

	//EO33367
	OpticalSystem_LLT EO33367_LLT(edmundLensCatalog.getEO33367().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO33367().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO33367 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO33367_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.2475498521,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO33367);

	//EO47387
	OpticalSystem_LLT EO47387_LLT(edmundLensCatalog.getEO47387().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47387().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47387 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47387_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.24803987219,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47387);

	//EO47388
	OpticalSystem_LLT EO47388_LLT(edmundLensCatalog.getEO47388().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47388().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47388 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47388_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.24869323953,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47388);

	//EO62599
	OpticalSystem_LLT EO62599_LLT(edmundLensCatalog.getEO62599().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO62599().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO62599 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO62599_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.20050744310,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO62599);

	//EO62600
	OpticalSystem_LLT EO62600_LLT(edmundLensCatalog.getEO62600().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO62600().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO62600 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO62600_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.19990418400,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO62600);

	//EO62601
	OpticalSystem_LLT EO62601_LLT(edmundLensCatalog.getEO62601().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO62601().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO62601 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO62601_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.20905047673,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO62601);

	//EO62602
	OpticalSystem_LLT EO62602_LLT(edmundLensCatalog.getEO62602().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO62602().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO62602 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO62602_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23665977599,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO62602);

	//EO62603
	OpticalSystem_LLT EO62603_LLT(edmundLensCatalog.getEO62603().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO62603().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO62603 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO62603_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23803870742,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO62603);

	//EO62604
	OpticalSystem_LLT EO62604_LLT(edmundLensCatalog.getEO62604().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO62604().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO62604 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO62604_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23974655379,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO62604);

	//EO62605
	OpticalSystem_LLT EO62605_LLT(edmundLensCatalog.getEO62605().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO62605().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO62605 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO62605_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.24102934207,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO62605);

	//EO48662
	OpticalSystem_LLT EO48662_LLT(edmundLensCatalog.getEO48662().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO48662().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO48662 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO48662_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.19158854318,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO48662);

	//EO67184
	OpticalSystem_LLT EO67184_LLT(edmundLensCatalog.getEO67184().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO67184().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO67184 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO67184_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.20090761700,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO67184);

	//EO45709
	OpticalSystem_LLT EO45709_LLT(edmundLensCatalog.getEO45709().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45709().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45709 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45709_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.21257097173,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45709);

	//EO47389
	OpticalSystem_LLT EO47389_LLT(edmundLensCatalog.getEO47389().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47389().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47389 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47389_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.21676354315,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47389);

	//EO45710
	OpticalSystem_LLT EO45710_LLT(edmundLensCatalog.getEO45710().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45710().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45710 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45710_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.22352314459,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45710);

	//EO45711
	OpticalSystem_LLT EO45711_LLT(edmundLensCatalog.getEO45711().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45711().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45711 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45711_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.23005652711,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45711);

	//EO47390
	OpticalSystem_LLT EO47390_LLT(edmundLensCatalog.getEO47390().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47390().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47390 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47390_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.23338142300,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47390);

	//EO48663
	OpticalSystem_LLT EO48663_LLT(edmundLensCatalog.getEO48663().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO48663().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO48663 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO48663_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.21120587902,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO48663);

	//EO45712
	OpticalSystem_LLT EO45712_LLT(edmundLensCatalog.getEO45712().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45712().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45712 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45712_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.22150686990,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45712);

	//EO33385
	OpticalSystem_LLT EO33385_LLT(edmundLensCatalog.getEO33385().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO33385().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO33385 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO33385_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.22720994379,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO33385);

	//EO33373
	OpticalSystem_LLT EO33373_LLT(edmundLensCatalog.getEO33373().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO33373().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO33373 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO33373_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.23091304716,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO33373);

	//EO33379
	OpticalSystem_LLT EO33379_LLT(edmundLensCatalog.getEO33379().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO33379().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO33379 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO33379_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.23959983294,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO33379);

	//EO47391
	OpticalSystem_LLT EO47391_LLT(edmundLensCatalog.getEO47391().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47391().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47391 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47391_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.24306650956,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47391);

	//EO47392
	OpticalSystem_LLT EO47392_LLT(edmundLensCatalog.getEO47392().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47392().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47392 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47392_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.24479986393,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47392);

	//EO45715
	OpticalSystem_LLT EO45715_LLT(edmundLensCatalog.getEO45715().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45715().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45715 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45715_LLT, /*position image surface*/{ 0.0,0.0,15.0 }, /*target point*/{ 0.0,0.20111071963,15.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45715);

	//EO45716
	OpticalSystem_LLT EO45716_LLT(edmundLensCatalog.getEO45716().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45716().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45716 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45716_LLT, /*position image surface*/{ 0.0,0.0,15.0 }, /*target point*/{ 0.0,0.21239660194,15.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45716);

	//EO45717
	OpticalSystem_LLT EO45717_LLT(edmundLensCatalog.getEO45717().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45717().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45717 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45717_LLT, /*position image surface*/{ 0.0,0.0,15.0 }, /*target point*/{ 0.0,0.22094081130,15.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45717);

	//EO47393
	OpticalSystem_LLT EO47393_LLT(edmundLensCatalog.getEO47393().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47393().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47393 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47393_LLT, /*position image surface*/{ 0.0,0.0,15.0 }, /*target point*/{ 0.0,0.22675257156,15.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47393);

	//EO45718
	OpticalSystem_LLT EO45718_LLT(edmundLensCatalog.getEO45718().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45718().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45718 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO45718_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.23841722956,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO45718);

	//EO47394
	OpticalSystem_LLT EO47394_LLT(edmundLensCatalog.getEO47394().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47394().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47394 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47394_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.24007186761,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47394);

	//EO47395
	OpticalSystem_LLT EO47395_LLT(edmundLensCatalog.getEO47395().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47395().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47395 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47395_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.23962981082,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47395);

	//EO47396
	OpticalSystem_LLT EO47396_LLT(edmundLensCatalog.getEO47396().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47396().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47396 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47396_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.24667620769,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47396);

	//EO47397
	OpticalSystem_LLT EO47397_LLT(edmundLensCatalog.getEO47397().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47397().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47397 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO47397_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.24583988210,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO47397);

	//EO86911
	OpticalSystem_LLT EO86911_LLT(edmundLensCatalog.getEO86911().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO86911().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO86911 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO86911_LLT, /*position image surface*/{ 0.0,0.0,35.0 }, /*target point*/{ 0.0,0.17019735101,35.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO86911);

	//EO86912
	OpticalSystem_LLT EO86912_LLT(edmundLensCatalog.getEO86912().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO86912().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO86912 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO86912_LLT, /*position image surface*/{ 0.0,0.0,15.0 }, /*target point*/{ 0.0,0.23145505426,15.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO86912);

	//EO86913
	OpticalSystem_LLT EO86913_LLT(edmundLensCatalog.getEO86913().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO86913().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO86913 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO86913_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.24120150827,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO86913);

	//EO86914
	OpticalSystem_LLT EO86914_LLT(edmundLensCatalog.getEO86914().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO86914().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO86914 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO86914_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.24270764572,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO86914);

	//EO86915
	OpticalSystem_LLT EO86915_LLT(edmundLensCatalog.getEO86915().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO86915().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO86915 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO86915_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.24635378708,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO86915);

	//EO38489
	OpticalSystem_LLT EO38489_LLT(edmundLensCatalog.getEO38489().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38489().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38489 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38489_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.17324585478,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38489);

	//EO38492
	OpticalSystem_LLT EO38492_LLT(edmundLensCatalog.getEO38492().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38492().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38492 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38492_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.19208954081,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38492);

	//EO38494
	OpticalSystem_LLT EO38494_LLT(edmundLensCatalog.getEO38494().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38494().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38494 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38494_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.20909303289,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38494);

	//EO38496
	OpticalSystem_LLT EO38496_LLT(edmundLensCatalog.getEO38496().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38496().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38496 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38496_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22817450262,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38496);

	//EO38499
	OpticalSystem_LLT EO38499_LLT(edmundLensCatalog.getEO38499().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38499().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38499 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38499_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.18260193447,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38499);

	//EO38500
	OpticalSystem_LLT EO38500_LLT(edmundLensCatalog.getEO38500().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38500().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38500 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38500_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.1889989768,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38500);

	//EO38503
	OpticalSystem_LLT EO38503_LLT(edmundLensCatalog.getEO38503().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38503().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38503 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38503_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.20231235940,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38503);

	//EO38504
	OpticalSystem_LLT EO38504_LLT(edmundLensCatalog.getEO38504().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38504().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38504 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38504_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.21046375875,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38504);

	//EO38505
	OpticalSystem_LLT EO38505_LLT(edmundLensCatalog.getEO38505().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38505().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38505 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38505_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.21592350599,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38505);

	//EO38507
	OpticalSystem_LLT EO38507_LLT(edmundLensCatalog.getEO38507().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38507().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38507 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38507_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22335860324,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38507);

	//EO38508
	OpticalSystem_LLT EO38508_LLT(edmundLensCatalog.getEO38508().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38508().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38508 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38508_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22594419104,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38508);

	//EO38509
	OpticalSystem_LLT EO38509_LLT(edmundLensCatalog.getEO38509().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38509().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38509 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38509_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22834581398,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38509);

	//EO38510
	OpticalSystem_LLT EO38510_LLT(edmundLensCatalog.getEO38510().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38510().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38510 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38510_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23522070694,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38510);

	//EO38512
	OpticalSystem_LLT EO38512_LLT(edmundLensCatalog.getEO38512().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38512().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38512 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38512_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23882963491,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38512);

	//EO38518
	OpticalSystem_LLT EO38518_LLT(edmundLensCatalog.getEO38518().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38518().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38518 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38518_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23891528691,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38518);

	//EO38519
	OpticalSystem_LLT EO38519_LLT(edmundLensCatalog.getEO38519().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38519().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38519 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38519_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.21286252902,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38519);

	//EO38520
	OpticalSystem_LLT EO38520_LLT(edmundLensCatalog.getEO38520().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38520().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38520 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38520_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22920237074,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38520);

	//EO38521
	OpticalSystem_LLT EO38521_LLT(edmundLensCatalog.getEO38521().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38521().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38521 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38521_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.21094733223,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38521);

	//EO38522
	OpticalSystem_LLT EO38522_LLT(edmundLensCatalog.getEO38522().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38522().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38522 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38522_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.16782739922,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38522);

	//EO38523
	OpticalSystem_LLT EO38523_LLT(edmundLensCatalog.getEO38523().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38523().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38523 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38523_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22077594244,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38523);

	//EO38524
	OpticalSystem_LLT EO38524_LLT(edmundLensCatalog.getEO38524().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38524().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38524 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38524_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.22988761615,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38524);

	//EO38525
	OpticalSystem_LLT EO38525_LLT(edmundLensCatalog.getEO38525().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38525().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38525 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38525_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.1952286430,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38525);

	//EO38542
	OpticalSystem_LLT EO38542_LLT(edmundLensCatalog.getEO38542().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38542().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38542 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38542_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.19992346400,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38542);

	//EO38543
	OpticalSystem_LLT EO38543_LLT(edmundLensCatalog.getEO38543().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38543().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38543 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38543_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.23727637791,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38543);

	//EO38544
	OpticalSystem_LLT EO38544_LLT(edmundLensCatalog.getEO38544().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38544().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38544 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38544_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.24002876298,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38544);

	//EO38545
	OpticalSystem_LLT EO38545_LLT(edmundLensCatalog.getEO38545().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38545().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38545 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38545_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.24202287918,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38545);

	//EO38547
	OpticalSystem_LLT EO38547_LLT(edmundLensCatalog.getEO38547().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38547().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38547 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38547_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.24335232349,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38547);

	//EO38548
	OpticalSystem_LLT EO38548_LLT(edmundLensCatalog.getEO38548().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38548().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38548 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38548_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.20344373769,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38548);

	//EO38552
	OpticalSystem_LLT EO38552_LLT(edmundLensCatalog.getEO38552().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38552().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38552 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38552_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.21439664328,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38552);

	//EO38561
	OpticalSystem_LLT EO38561_LLT(edmundLensCatalog.getEO38561().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38561().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38561 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38561_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.22151279023,10.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38561);

	//EO38567
	OpticalSystem_LLT EO38567_LLT(edmundLensCatalog.getEO38567().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO38567().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO38567 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay1, /*lens two surface opt sys*/ EO38567_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.24131354305,5.0 });
	workTheLensCatalogEO_TwoSurfaces.push_back(testEO38567);

	//---
	bool returnCheckTheLensCatalogEO_TwoSurfaces = Math::checkTrueOfVectorElements(workTheLensCatalogEO_TwoSurfaces);
	return returnCheckTheLensCatalogEO_TwoSurfaces;
	//---

}


bool TestLensCatalogEO::testCatalogEO_TwoSurfaces_3()
{
	std::vector<bool> workTheLensCatalogEO_TwoSurfaces_3;

	// load lens catalog from edmund optics
	EdmundOpticsLensCatalog edmundLensCatalog;
	edmundLensCatalog.loadLensCatalogEO_double_convex_lenses(); // https://www.edmundoptics.de/f/vis-nir-coated-double-convex-dcx-lenses/13504/

		// test light ray 0
	Ray_LLT testRay0({ 0.0,1.0,0.0 }, { 0.0,0.0,1.0 }, 1.0);
	Light_LLT light0;
	light0.setWavelength(550.0);
	LightRayStruct testLightRay0(light0, testRay0, 1);
	//---

	// test light ray 1
	Ray_LLT testRay1({ 0.0,0.25,0.0 }, { 0.0,0.0,1.0 }, 1.0);
	Light_LLT light1;
	light1.setWavelength(550.0);
	LightRayStruct testLightRay1(light1, testRay1, 1);
	//---

	//EO49447
	OpticalSystem_LLT E49447_LLT(edmundLensCatalog.getEO49447().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49447().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO49447 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E49447_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,-0.3193935646,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO49447);

	//E49448
	OpticalSystem_LLT E49448_LLT(edmundLensCatalog.getEO49448().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49448().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO49448 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E49448_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.11461878709,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO49448);

	//E49449
	OpticalSystem_LLT E49449_LLT(edmundLensCatalog.getEO49449().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49449().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO49449 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E49449_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.33399903274,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO49449);

	//E49450
	OpticalSystem_LLT E49450_LLT(edmundLensCatalog.getEO49450().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49450().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO49450 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E49450_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.55156903746,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO49450);

	//E47893
	OpticalSystem_LLT E47893_LLT(edmundLensCatalog.getEO47893().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47893().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47893 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E47893_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.25308701176,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO47893);

	//E47894
	OpticalSystem_LLT E47894_LLT(edmundLensCatalog.getEO47894().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47894().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO47894 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E47894_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.60948588894,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO47894);

	//E63658
	OpticalSystem_LLT E63658_LLT(edmundLensCatalog.getEO63658().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63658().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63658 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63658_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.30500697741,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63658);

	//E63659
	OpticalSystem_LLT E63659_LLT(edmundLensCatalog.getEO63659().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63659().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63659 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63659_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.62460493211,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63659);

	//E63660
	OpticalSystem_LLT E63660_LLT(edmundLensCatalog.getEO63660().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63660().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63660 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63660_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.75238048265,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63660);

	//E63661
	OpticalSystem_LLT E63661_LLT(edmundLensCatalog.getEO63661().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63661().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63661 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63661_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.79826353074,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63661);

	//E63662
	OpticalSystem_LLT E63662_LLT(edmundLensCatalog.getEO63662().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63662().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63662 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63662_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.83892059886,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63662);

	//E45859
	OpticalSystem_LLT E45859_LLT(edmundLensCatalog.getEO45859().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45859().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45859 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45859_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.43926546538,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45859);

	//E45860
	OpticalSystem_LLT E45860_LLT(edmundLensCatalog.getEO45860().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45860().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45860 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45860_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.60019535283,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45860);

	//E45861
	OpticalSystem_LLT E45861_LLT(edmundLensCatalog.getEO45861().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45861().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45861 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45861_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.71101298836,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45861);

	//E45862
	OpticalSystem_LLT E45862_LLT(edmundLensCatalog.getEO45862().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45862().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45862 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45862_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.80151273075,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45862);

	//E45863
	OpticalSystem_LLT E45863_LLT(edmundLensCatalog.getEO45863().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45863().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45863 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45863_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.86272533576,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45863);

	//E45864
	OpticalSystem_LLT E45864_LLT(edmundLensCatalog.getEO45864().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45864().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45864 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45864_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.88372185433,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45864);

	//E45865
	OpticalSystem_LLT E45865_LLT(edmundLensCatalog.getEO45865().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45865().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45865 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45865_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.89766090786,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45865);

	//E45866
	OpticalSystem_LLT E45866_LLT(edmundLensCatalog.getEO45866().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45866().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45866 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45866_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.70056391274,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45866);

	//E45867
	OpticalSystem_LLT E45867_LLT(edmundLensCatalog.getEO45867().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45867().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45867 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45867_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.76080055433,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45867);

	//E45868
	OpticalSystem_LLT E45868_LLT(edmundLensCatalog.getEO45868().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45868().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45868 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45868_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.81624640750,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45868);

	//E45869
	OpticalSystem_LLT E45869_LLT(edmundLensCatalog.getEO45869().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45869().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45869 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45869_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.88152550238,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45869);

	//E45870
	OpticalSystem_LLT E45870_LLT(edmundLensCatalog.getEO45870().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45870().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45870 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45870_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.90784071369,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45870);

	//E45871
	OpticalSystem_LLT E45871_LLT(edmundLensCatalog.getEO45871().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45871().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45871 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45871_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.92561354567,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45871);

	//E63663
	OpticalSystem_LLT E63663_LLT(edmundLensCatalog.getEO63663().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63663().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63663 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63663_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.73497100517,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63663);

	//E63664
	OpticalSystem_LLT E63664_LLT(edmundLensCatalog.getEO63664().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63664().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63664 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63664_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.81806879481,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63664);

	//E63665
	OpticalSystem_LLT E63665_LLT(edmundLensCatalog.getEO63665().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63665().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63665 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63665_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.83159588630,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63665);

	//E63666
	OpticalSystem_LLT E63666_LLT(edmundLensCatalog.getEO63666().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63666().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63666 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63666_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.86560703888,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63666);

	//E63667
	OpticalSystem_LLT E63667_LLT(edmundLensCatalog.getEO63667().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63667().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63667 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63667_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.88817792511,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63667);

	//E63668
	OpticalSystem_LLT E63668_LLT(edmundLensCatalog.getEO63668().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63668().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63668 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63668_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.91626476841,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63668);

	//E63669
	OpticalSystem_LLT E63669_LLT(edmundLensCatalog.getEO63669().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63669().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63669 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63669_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.93308380576,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63669);

	//E63670
	OpticalSystem_LLT E63670_LLT(edmundLensCatalog.getEO63670().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63670().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63670 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63670_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.96660279204,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63670);

	//E45872
	OpticalSystem_LLT E45872_LLT(edmundLensCatalog.getEO45872().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45872().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45872 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45872_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.80069283518,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45872);

	//E45873
	OpticalSystem_LLT E45873_LLT(edmundLensCatalog.getEO45873().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45873().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45873 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45873_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.84856085587,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45873);

	//E33391
	OpticalSystem_LLT E33391_LLT(edmundLensCatalog.getEO33391().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO33391().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO33391 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E33391_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.90118574885,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO33391);

	//E45875
	OpticalSystem_LLT E45875_LLT(edmundLensCatalog.getEO45875().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45875().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45875 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45875_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.91466497672,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45875);

	//E45876
	OpticalSystem_LLT E45876_LLT(edmundLensCatalog.getEO45876().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45876().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45876 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45876_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.92171798285,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45876);

	//E45877
	OpticalSystem_LLT E45877_LLT(edmundLensCatalog.getEO45877().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45877().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45877 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45877_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.93362066797,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45877);

	//E45878
	OpticalSystem_LLT E45878_LLT(edmundLensCatalog.getEO45878().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45878().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45878 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45878_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.95639058348,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45878);

	//E45879
	OpticalSystem_LLT E45879_LLT(edmundLensCatalog.getEO45879().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45879().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45879 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45879_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.87743791530,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45879);

	//E63671
	OpticalSystem_LLT E63671_LLT(edmundLensCatalog.getEO63671().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63671().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63671 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63671_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.87336400514,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63671);

	//E45880
	OpticalSystem_LLT E45880_LLT(edmundLensCatalog.getEO45880().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45880().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45880 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45880_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.90984248432,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45880);

	//E63672
	OpticalSystem_LLT E63672_LLT(edmundLensCatalog.getEO63672().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63672().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63672 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63672_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.89205612104,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63672);

	//E45881
	OpticalSystem_LLT E45881_LLT(edmundLensCatalog.getEO45881().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45881().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45881 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45881_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.92175931497,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45881);

	//E63673
	OpticalSystem_LLT E63673_LLT(edmundLensCatalog.getEO63673().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63673().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63673 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63673_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.93301924612,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63673);

	//E45882
	OpticalSystem_LLT E45882_LLT(edmundLensCatalog.getEO45882().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45882().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45882 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45882_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.93975447011,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45882);

	//E63674
	OpticalSystem_LLT E63674_LLT(edmundLensCatalog.getEO63674().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63674().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63674 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63674_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.94984110491,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63674);

	//E63675
	OpticalSystem_LLT E63675_LLT(edmundLensCatalog.getEO63675().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63675().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63675 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63675_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.89851601436,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63675);

	//E45883
	OpticalSystem_LLT E45883_LLT(edmundLensCatalog.getEO45883().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45883().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45883 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45883_LLT, /*position image surface*/{ 0.0,0.0,5.5 }, /*target point*/{ 0.0,0.93045310858,5.5 });	//Mittendicke 5.5mm
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45883);

	//E45884
	OpticalSystem_LLT E45884_LLT(edmundLensCatalog.getEO45884().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45884().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45884 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45884_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.94955667262,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45884);

	//E63678
	OpticalSystem_LLT E63678_LLT(edmundLensCatalog.getEO63678().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63678().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63678 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63678_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.92669227207,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63678);

	//E63679
	OpticalSystem_LLT E63679_LLT(edmundLensCatalog.getEO63679().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63679().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63679 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63679_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.91332777488,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63679);

	//E45885
	OpticalSystem_LLT E45885_LLT(edmundLensCatalog.getEO45885().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45885().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45885 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45885_LLT, /*position image surface*/{ 0.0,0.0,5.3 }, /*target point*/{ 0.0,0.9396726227,5.3 });	//Mittendicke 5.3mm
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45885);

	//E45886
	OpticalSystem_LLT E45886_LLT(edmundLensCatalog.getEO45886().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45886().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45886 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45886_LLT, /*position image surface*/{ 0.0,0.0,5.3 }, /*target point*/{ 0.0,0.9554081343,5.3 }); //Mittendicke 5.3mm
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45886);

	//E63680
	OpticalSystem_LLT E63680_LLT(edmundLensCatalog.getEO63680().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63680().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63680 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63680_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.94642504953,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63680);

	//E63681
	OpticalSystem_LLT E63681_LLT(edmundLensCatalog.getEO63681().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63681().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63681 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63681_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.96095775341,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63681);

	//E63682
	OpticalSystem_LLT E63682_LLT(edmundLensCatalog.getEO63682().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63682().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63682 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63682_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.97077378589,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63682);

	//E45887
	OpticalSystem_LLT E45887_LLT(edmundLensCatalog.getEO45887().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45887().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45887 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45887_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.89868584418,8.0 }); //Mittendicke 8.0mm
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45887);

	//E63683
	OpticalSystem_LLT E63683_LLT(edmundLensCatalog.getEO63683().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63683().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63683 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63683_LLT, /*position image surface*/{ 0.0,0.0,5.5 }, /*target point*/{ 0.0,0.94323482202,5.5 });	//Mittendicke 5.5mm
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63683);

	//E45888
	OpticalSystem_LLT E45888_LLT(edmundLensCatalog.getEO45888().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45888().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45888 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45888_LLT, /*position image surface*/{ 0.0,0.0,6.6 }, /*target point*/{ 0.0,0.93565706058,6.6 });	//Mittendicke 6.6mm
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45888);

	//E45889
	OpticalSystem_LLT E45889_LLT(edmundLensCatalog.getEO45889().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45889().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45889 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45889_LLT, /*position image surface*/{ 0.0,0.0,5.3 }, /*target point*/{ 0.0,0.95513183124,5.3 });	//Mittendicke 5.3mm
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45889);

	//E45890
	OpticalSystem_LLT E45890_LLT(edmundLensCatalog.getEO45890().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45890().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45890 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45890_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.96632950934,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45890);

	//E45891
	OpticalSystem_LLT E45891_LLT(edmundLensCatalog.getEO45891().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45891().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45891 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45891_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.96424251571,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45891);

	//E45892
	OpticalSystem_LLT E45892_LLT(edmundLensCatalog.getEO45892().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45892().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45892 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45892_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.97672013711,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45892);

	//E45893
	OpticalSystem_LLT E45893_LLT(edmundLensCatalog.getEO45893().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45893().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45893 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45893_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.97866343036,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45893);

	//E45894
	OpticalSystem_LLT E45894_LLT(edmundLensCatalog.getEO45894().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45894().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45894 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45894_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.98178070785,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45894);

	//E45895
	OpticalSystem_LLT E45895_LLT(edmundLensCatalog.getEO45895().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45895().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45895 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45895_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.98362102738,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45895);

	//E33397
	OpticalSystem_LLT E33397_LLT(edmundLensCatalog.getEO33397().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO33397().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO33397 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E33397_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.99170250857,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO33397);

	//E63684
	OpticalSystem_LLT E63684_LLT(edmundLensCatalog.getEO63684().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63684().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63684 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63684_LLT, /*position image surface*/{ 0.0,0.0,6.5 }, /*target point*/{ 0.0,0.93691616830,6.5 }); //Mittendicke 6.5mm
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63684);

	//E45898
	OpticalSystem_LLT E45898_LLT(edmundLensCatalog.getEO45898().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45898().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45898 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45898_LLT, /*position image surface*/{ 0.0,0.0,6.55 }, /*target point*/{ 0.0,0.95570329996, 6.55 }); //Mittendicke 6.55mm
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45898);

	//E63685
	OpticalSystem_LLT E63685_LLT(edmundLensCatalog.getEO63685().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63685().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63685 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63685_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.97203636018,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63685);

	//E45899
	OpticalSystem_LLT E45899_LLT(edmundLensCatalog.getEO45899().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45899().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45899 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45899_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.97734636325,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45899);

	//E63686
	OpticalSystem_LLT E63686_LLT(edmundLensCatalog.getEO63686().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63686().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63686 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63686_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.98332718216,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63686);

	//E63687
	OpticalSystem_LLT E63687_LLT(edmundLensCatalog.getEO63687().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63687().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63687 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63687_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.98612729596,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63687);

	//E63688
	OpticalSystem_LLT E63688_LLT(edmundLensCatalog.getEO63688().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63688().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63688 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63688_LLT, /*position image surface*/{ 0.0,0.0,8.5 }, /*target point*/{ 0.0,0.93822321919,8.5 });	//Mittendicke 8.5mm
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63688);

	//E45900
	OpticalSystem_LLT E45900_LLT(edmundLensCatalog.getEO45900().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45900().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45900 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/E45900_LLT, /*position image surface*/{ 0.0,0.0,8.8 }, /*target point*/{ 0.0,0.95034032584,8.8 });	//Mittendicke 8.8mm
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45900);

	//E33422
	OpticalSystem_LLT E33422_LLT(edmundLensCatalog.getEO33422().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO33422().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO33422 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E33422_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.96637542965,8.0 });	//Mittendicke 8.0mm
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO33422);

	//E33409
	OpticalSystem_LLT E33409_LLT(edmundLensCatalog.getEO33409().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO33409().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO33409 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E33409_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.97319754084,8.0 });	//Mittendicke 8.0mm
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO33409);

	//E63689
	OpticalSystem_LLT E63689_LLT(edmundLensCatalog.getEO63689().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63689().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO63689 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E63689_LLT, /*position image surface*/{ 0.0,0.0,7.0 }, /*target point*/{ 0.0,0.98052910208,7.0 });	//Mittendicke 7.0mm
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO63689);

	//E33416
	OpticalSystem_LLT E33416_LLT(edmundLensCatalog.getEO33416().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO33416().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO33416 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E33416_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.98669322100,8.0 });	//Mittendicke 8.0mm
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO33416);

	//E45905
	OpticalSystem_LLT E45905_LLT(edmundLensCatalog.getEO45905().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45905().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45905 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45905_LLT, /*position image surface*/{ 0.0,0.0,16.0 }, /*target point*/{ 0.0,0.90544818647,16.0 });	//Mittendicke 16.0mm
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45905);

	//E45906
	OpticalSystem_LLT E45906_LLT(edmundLensCatalog.getEO45906().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45906().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45906 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45906_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.96638575344,10.0 });	//Mittendicke 10.0mm
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45906);

	//E45907
	OpticalSystem_LLT E45907_LLT(edmundLensCatalog.getEO45907().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45907().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45907 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45907_LLT, /*position image surface*/{ 0.0,0.0,9.0 }, /*target point*/{ 0.0,0.97997089143,9.0 });		//Mittendicke 9.0mm
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45907);

	//E45908
	OpticalSystem_LLT E45908_LLT(edmundLensCatalog.getEO45908().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45908().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45908 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45908_LLT, /*position image surface*/{ 0.0,0.0,5.05 }, /*target point*/{ 0.0,0.99161937178,5.05 });	//Mittendicke 5.05mm
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45908);

	//E45909
	OpticalSystem_LLT E45909_LLT(edmundLensCatalog.getEO45909().getHLT_TwoSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45909().getHLT_TwoSurfaces().getPosAndInteraction_LLT());
	bool testEO45909 = testOneLensTwoSurfaces(/*test light ray*/ testLightRay0, /*lens two surface opt sys*/ E45909_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.99318067430,5.0 });
	workTheLensCatalogEO_TwoSurfaces_3.push_back(testEO45909);


	//---
	bool returnCheckTheLensCatalogEO_TwoSurfaces = Math::checkTrueOfVectorElements(workTheLensCatalogEO_TwoSurfaces_3);
	return returnCheckTheLensCatalogEO_TwoSurfaces;
	//---
}


//test the lens catalog from edmund optics with three surfaces
bool TestLensCatalogEO::testCatalogEO_ThreeSurfaces()
{
	std::vector<bool> workTheLensCatalogEO_ThreeSurfaces;
	//---
	// load lens catalog from edmund optics
	EdmundOpticsLensCatalog edmundLensCatalog;
	edmundLensCatalog.loadLensCatalogEO_achroamticLensesMgF();
	// test light ray
	Ray_LLT testRay0({ 0.0,1.0,0.0 }, { 0.0,0.0,1.0 }, 1.0);
	Light_LLT light0;
	light0.setWavelength(550.0);
	LightRayStruct testLightRay0(light0, testRay0, 1);
	//---


	////EO65564
	//OpticalSystem_LLT EO65564_LLT(edmundLensCatalog.getEO65564().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65564().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());					//Glas 1 nicht im Glaskatalog
	//bool testEO65564 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO65564_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0, ,5.0 });
	//workTheLensCatalogEO_ThreeSurfaces.push_back(testEO65564);
	//
	////EO65565
	//OpticalSystem_LLT EO65565_LLT(edmundLensCatalog.getEO65565().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65565().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());					//Glas 1 nicht im Glaskatalog
	//bool testEO65565 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO65565_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0, ,5.0 });
	//workTheLensCatalogEO_ThreeSurfaces.push_back(testEO65565);
	//
	////EO65566
	//OpticalSystem_LLT EO65566_LLT(edmundLensCatalog.getEO65566().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65566().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());					//Glas 1 nicht im Glaskatalog
	//bool testEO65566 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO65566_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0, ,5.0 });
	//workTheLensCatalogEO_ThreeSurfaces.push_back(testEO65566);
	//
	////EO65567
	//OpticalSystem_LLT EO65567_LLT(edmundLensCatalog.getEO65567().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65567().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());					//Glas 1 nicht im Glaskatalog
	//bool testEO65567 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO65567_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0, ,5.0 });
	//workTheLensCatalogEO_ThreeSurfaces.push_back(testEO65567);
	//
	////EO65568
	//OpticalSystem_LLT EO65568_LLT(edmundLensCatalog.getEO65568().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65568().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());					//Glas 1 nicht im Glaskatalog
	//bool testEO65568 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO65568_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0, ,5.0 });
	//workTheLensCatalogEO_ThreeSurfaces.push_back(testEO65568);
	//
	////EO65569
	//OpticalSystem_LLT EO65569_LLT(edmundLensCatalog.getEO65569().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65569().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());					//Glas 1 nicht im Glaskatalog
	//bool testEO65569 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO65569_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0, ,5.0 });
	//workTheLensCatalogEO_ThreeSurfaces.push_back(testEO65569);
	//
	////EO83338
	//OpticalSystem_LLT EO83338_LLT(edmundLensCatalog.getEO83338().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO83338().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());					//Glas 1 nicht im Glaskatalog
	//bool testEO83338 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO83338_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0, ,5.0 });
	//workTheLensCatalogEO_ThreeSurfaces.push_back(testEO83338);
	//
	////EO83339
	//OpticalSystem_LLT EO83339_LLT(edmundLensCatalog.getEO83339().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO83339().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());					//Glas 1 nicht im Glaskatalog
	//bool testEO83339 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO83339_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0, ,5.0 });
	//workTheLensCatalogEO_ThreeSurfaces.push_back(testEO83339);

	//EO45262
	OpticalSystem_LLT EO45262_LLT(edmundLensCatalog.getEO45262().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45262().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45262 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45262_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.70642363578,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45262);

	//EO47721
	OpticalSystem_LLT EO47721_LLT(edmundLensCatalog.getEO47721().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO47721().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO47721 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO47721_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.21875794740,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO47721);

	//EO45089
	OpticalSystem_LLT EO45089_LLT(edmundLensCatalog.getEO45089().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45089().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45089 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45089_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.39322100430,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45089);

	//EO45090
	OpticalSystem_LLT EO45090_LLT(edmundLensCatalog.getEO45090().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45090().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45090 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45090_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.59190391038,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45090);

	//EO63690
	OpticalSystem_LLT EO63690_LLT(edmundLensCatalog.getEO63690().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63690().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO63690 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO63690_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.45301424861,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO63690);

	//EO63691
	OpticalSystem_LLT EO63691_LLT(edmundLensCatalog.getEO63691().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63691().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO63691 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO63691_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.64179427071,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO63691);

	//EO63692
	OpticalSystem_LLT EO63692_LLT(edmundLensCatalog.getEO63692().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63692().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO63692 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO63692_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.71035540004,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO63692);

	//EO45205
	OpticalSystem_LLT EO45205_LLT(edmundLensCatalog.getEO45205().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45205().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45205 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45205_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.52893185175,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45205);

	//EO45206
	OpticalSystem_LLT EO45206_LLT(edmundLensCatalog.getEO45206().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45206().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45206 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45206_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.63285964570,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45206);

	//EO49923
	OpticalSystem_LLT EO49923_LLT(edmundLensCatalog.getEO49923().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49923().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49923 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49923_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.73652994305,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49923);

	//EO45207
	OpticalSystem_LLT EO45207_LLT(edmundLensCatalog.getEO45207().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45207().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45207 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45207_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.74922896335,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45207);

	//EO45408
	OpticalSystem_LLT EO45408_LLT(edmundLensCatalog.getEO45408().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45408().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45408 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45408_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.81253357311,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45408);

	//EO45407
	OpticalSystem_LLT EO45407_LLT(edmundLensCatalog.getEO45407().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45407().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45407 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45407_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.63667465627,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45407);

	//EO49924
	OpticalSystem_LLT EO49924_LLT(edmundLensCatalog.getEO49924().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49924().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49924 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49924_LLT, /*position image surface*/{ 0.0,0.0,6.5 }, /*target point*/{ 0.0,0.52721283760,6.5 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49924);

	//EO45208
	OpticalSystem_LLT EO45208_LLT(edmundLensCatalog.getEO45208().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45208().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45208 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45208_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.68558919034,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45208);

	//EO32299
	OpticalSystem_LLT EO32299_LLT(edmundLensCatalog.getEO32299().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32299().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32299 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32299_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.73442212461,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32299);

	//EO32301
	OpticalSystem_LLT EO32301_LLT(edmundLensCatalog.getEO32301().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32301().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32301 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32301_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.73660027711,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32301);

	//EO49925
	OpticalSystem_LLT EO49925_LLT(edmundLensCatalog.getEO49925().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49925().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49925 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49925_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.81347099352,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49925);

	//EO32303
	OpticalSystem_LLT EO32303_LLT(edmundLensCatalog.getEO32303().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32303().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32303 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32303_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.84235644453,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32303);

	//EO32305
	OpticalSystem_LLT EO32305_LLT(edmundLensCatalog.getEO32305().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32305().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32305 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32305_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.86666455943,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32305);

	//EO45135
	OpticalSystem_LLT EO45135_LLT(edmundLensCatalog.getEO45135().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45135().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45135 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45135_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.88704469365,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45135);

	//EO32307
	OpticalSystem_LLT EO32307_LLT(edmundLensCatalog.getEO32307().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32307().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32307 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32307_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.90855574221,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32307);

	//EO45173
	OpticalSystem_LLT EO45173_LLT(edmundLensCatalog.getEO45173().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45173().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45173 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45173_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.91936232797,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45173);

	//EO45263
	OpticalSystem_LLT EO45263_LLT(edmundLensCatalog.getEO45263().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45263().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45263 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45263_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.93211499420,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45263);

	//EO45345
	OpticalSystem_LLT EO45345_LLT(edmundLensCatalog.getEO45345().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45345().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45345 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45345_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.94585004140,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45345);

	//EO65549
	OpticalSystem_LLT EO65549_LLT(edmundLensCatalog.getEO65549().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65549().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO65549 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO65549_LLT, /*position image surface*/{ 0.0,0.0,9.0 }, /*target point*/{ 0.0,0.45241541125,9.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO65549);

	//EO45346
	OpticalSystem_LLT EO45346_LLT(edmundLensCatalog.getEO45346().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45346().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45346 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45346_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.61188944417,8.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45346);

	//EO49926
	OpticalSystem_LLT EO49926_LLT(edmundLensCatalog.getEO49926().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49926().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49926 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49926_LLT, /*position image surface*/{ 0.0,0.0,6.0 }, /*target point*/{ 0.0,0.77351953508,6.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49926);

	//EO45091
	OpticalSystem_LLT EO45091_LLT(edmundLensCatalog.getEO45091().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45091().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45091 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45091_LLT, /*position image surface*/{ 0.0,0.0,6.0 }, /*target point*/{ 0.0,0.79966504885,6.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45091);

	//EO49927
	OpticalSystem_LLT EO49927_LLT(edmundLensCatalog.getEO49927().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49927().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49927 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49927_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.87671210103,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49927);

	//EO45092
	OpticalSystem_LLT EO45092_LLT(edmundLensCatalog.getEO45092().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45092().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45092 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45092_LLT, /*position image surface*/{ 0.0,0.0,6.0 }, /*target point*/{ 0.0,0.86735199295,6.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45092);

	//EO45264
	OpticalSystem_LLT EO45264_LLT(edmundLensCatalog.getEO45264().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45264().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45264 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45264_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.92163495258,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45264);

	//EO45818
	OpticalSystem_LLT EO45818_LLT(edmundLensCatalog.getEO45818().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45818().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45818 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45818_LLT, /*position image surface*/{ 0.0,0.0,6.0 }, /*target point*/{ 0.0,0.91535423592,6.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45818);

	//EO45347
	OpticalSystem_LLT EO45347_LLT(edmundLensCatalog.getEO45347().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45347().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45347 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45347_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.93939995167,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45347);

	//EO45819
	OpticalSystem_LLT EO45819_LLT(edmundLensCatalog.getEO45819().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45819().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45819 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45819_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.95990502629,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45819);

	//EO45820
	OpticalSystem_LLT EO45820_LLT(edmundLensCatalog.getEO45820().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45820().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45820 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45820_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.96637699197,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45820);

	//EO63693
	OpticalSystem_LLT EO63693_LLT(edmundLensCatalog.getEO63693().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63693().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO63693 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO63693_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.67771721814,8.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO63693);

	//EO63694
	OpticalSystem_LLT EO63694_LLT(edmundLensCatalog.getEO63694().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63694().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO63694 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO63694_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.86340941647,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO63694);

	//EO63695
	OpticalSystem_LLT EO63695_LLT(edmundLensCatalog.getEO63695().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63695().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO63695 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO63695_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.90450984586,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO63695);

	//EO63696
	OpticalSystem_LLT EO63696_LLT(edmundLensCatalog.getEO63696().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63696().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO63696 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO63696_LLT, /*position image surface*/{ 0.0,0.0,6.0 }, /*target point*/{ 0.0,0.89961726103,6.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO63696);

	//EO63697
	OpticalSystem_LLT EO63697_LLT(edmundLensCatalog.getEO63697().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63697().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO63697 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO63697_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.93239809055,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO63697);

	//EO63698
	OpticalSystem_LLT EO63698_LLT(edmundLensCatalog.getEO63698().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63698().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO63698 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO63698_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.93920104356,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO63698);

	//EO63699
	OpticalSystem_LLT EO63699_LLT(edmundLensCatalog.getEO63699().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63699().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO63699 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO63699_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.97164398846,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO63699);

	//EO65550
	OpticalSystem_LLT EO65550_LLT(edmundLensCatalog.getEO65550().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65550().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO65550 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO65550_LLT, /*position image surface*/{ 0.0,0.0,11.0 }, /*target point*/{ 0.0,0.54814013686,11.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO65550);

	//EO45209
	OpticalSystem_LLT EO45209_LLT(edmundLensCatalog.getEO45209().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45209().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45209 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45209_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.68837324226,8.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45209);

	//EO63700
	OpticalSystem_LLT EO63700_LLT(edmundLensCatalog.getEO63700().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63700().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO63700 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO63700_LLT, /*position image surface*/{ 0.0,0.0,7.0 }, /*target point*/{ 0.0,0.72278763469,7.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO63700);

	//EO49928
	OpticalSystem_LLT EO49928_LLT(edmundLensCatalog.getEO49928().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49928().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49928 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49928_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.73704407172,8.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49928);

	////EO32309
	//OpticalSystem_LLT EO32309_LLT(edmundLensCatalog.getEO32309().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32309().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());					//Glas 1 nicht im Glaskatalog
	//bool testEO32309 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32309_LLT, /*position image surface*/{ 0.0,0.0,7.0 }, /*target point*/{ 0.0,0.79087645103,7.0 });	
	//workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32309);

	//EO32311
	OpticalSystem_LLT EO32311_LLT(edmundLensCatalog.getEO32311().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32311().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32311 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32311_LLT, /*position image surface*/{ 0.0,0.0,7.0 }, /*target point*/{ 0.0,0.82949341908,7.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32311);

	//EO32313
	OpticalSystem_LLT EO32313_LLT(edmundLensCatalog.getEO32313().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32313().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32313 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32313_LLT, /*position image surface*/{ 0.0,0.0,6.0 }, /*target point*/{ 0.0,0.86060075468,6.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32313);

	//EO45210
	OpticalSystem_LLT EO45210_LLT(edmundLensCatalog.getEO45210().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45210().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45210 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45210_LLT, /*position image surface*/{ 0.0,0.0,6.0 }, /*target point*/{ 0.0,0.90288450697,6.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45210);

	//EO32315
	OpticalSystem_LLT EO32315_LLT(edmundLensCatalog.getEO32315().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32315().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32315 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32315_LLT, /*position image surface*/{ 0.0,0.0,6.0 }, /*target point*/{ 0.0,0.91535423592,6.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32315);

	//EO45136
	OpticalSystem_LLT EO45136_LLT(edmundLensCatalog.getEO45136().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45136().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45136 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45136_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.94512197606,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45136);

	//EO32317
	OpticalSystem_LLT EO32317_LLT(edmundLensCatalog.getEO32317().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32317().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32317 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32317_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.95230332592,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32317);

	//EO45137
	OpticalSystem_LLT EO45137_LLT(edmundLensCatalog.getEO45137().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45137().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45137 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45137_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.9599050269,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45137);

	//EO32882
	OpticalSystem_LLT EO32882_LLT(edmundLensCatalog.getEO32882().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32882().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32882 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32882_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.96637699197,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32882);

	//EO45409
	OpticalSystem_LLT EO45409_LLT(edmundLensCatalog.getEO45409().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45409().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45409 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45409_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.96356963804,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45409);

	//EO45410
	OpticalSystem_LLT EO45410_LLT(edmundLensCatalog.getEO45410().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45410().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45410 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45410_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.96701455184,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45410);

	//EO45265
	OpticalSystem_LLT EO45265_LLT(edmundLensCatalog.getEO45265().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45265().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45265 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45265_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.97400595173,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45265);

	//EO49758
	OpticalSystem_LLT EO49758_LLT(edmundLensCatalog.getEO49758().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49758().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49758 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49758_LLT, /*position image surface*/{ 0.0,0.0,9.0 }, /*target point*/{ 0.0,0.66998481710,9.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49758);

	//EO49759
	OpticalSystem_LLT EO49759_LLT(edmundLensCatalog.getEO49759().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49759().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49759 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49759_LLT, /*position image surface*/{ 0.0,0.0,7.0 }, /*target point*/{ 0.0,0.79483555794,7.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49759);

	//EO49760
	OpticalSystem_LLT EO49760_LLT(edmundLensCatalog.getEO49760().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49760().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49760 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49760_LLT, /*position image surface*/{ 0.0,0.0,6.0 }, /*target point*/{ 0.0,0.87443250114,6.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49760);

	//EO49761
	OpticalSystem_LLT EO49761_LLT(edmundLensCatalog.getEO49761().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49761().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49761 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49761_LLT, /*position image surface*/{ 0.0,0.0,6.0 }, /*target point*/{ 0.0,0.90064422867,6.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49761);

	//EO49762
	OpticalSystem_LLT EO49762_LLT(edmundLensCatalog.getEO49762().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49762().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49762 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49762_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.93393963617,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49762);

	//EO49763
	OpticalSystem_LLT EO49763_LLT(edmundLensCatalog.getEO49763().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49763().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49763 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49763_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.94473239602,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49763);

	//EO49764
	OpticalSystem_LLT EO49764_LLT(edmundLensCatalog.getEO49764().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49764().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49764 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49764_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.94233425406,5.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49764);

	//EO83415
	OpticalSystem_LLT EO83415_LLT(edmundLensCatalog.getEO83415().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO83415().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO83415 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO83415_LLT, /*position image surface*/{ 0.0,0.0,7.0 }, /*target point*/{ 0.0,0.96592627508,7.0 });		//positive Radien
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO83415);

	//EO65551
	OpticalSystem_LLT EO65551_LLT(edmundLensCatalog.getEO65551().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65551().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO65551 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO65551_LLT, /*position image surface*/{ 0.0,0.0,13.0 }, /*target point*/{ 0.0,0.56211044841,13.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO65551);

	//EO49929
	OpticalSystem_LLT EO49929_LLT(edmundLensCatalog.getEO49929().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49929().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49929 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49929_LLT, /*position image surface*/{ 0.0,0.0,9.0 }, /*target point*/{ 0.0,0.75745761201,9.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49929);

	////EO45174
	//OpticalSystem_LLT EO45174_LLT(edmundLensCatalog.getEO45174().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45174().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());					//Glas 1 nicht im Glaskatalog
	//bool testEO45174 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45174_LLT, /*position image surface*/{ 0.0,0.0,9.0 }, /*target point*/{ 0.0,0.78937874370,9.0 });	
	//workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45174);

	//EO32720
	OpticalSystem_LLT EO32720_LLT(edmundLensCatalog.getEO32720().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32720().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32720 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32720_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.84264425198,8.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32720);

	//EO45103
	OpticalSystem_LLT EO45103_LLT(edmundLensCatalog.getEO45103().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45103().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45103 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45103_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.88040450886,8.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45103);

	//EO45138
	OpticalSystem_LLT EO45138_LLT(edmundLensCatalog.getEO45138().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45138().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45138 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45138_LLT, /*position image surface*/{ 0.0,0.0,7.0 }, /*target point*/{ 0.0,0.91482848104,7.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45138);

	//EO49930
	OpticalSystem_LLT EO49930_LLT(edmundLensCatalog.getEO49930().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49930().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49930 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49930_LLT, /*position image surface*/{ 0.0,0.0,6.0 }, /*target point*/{ 0.0,0.94993385267,6.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49930);

	//EO45139
	OpticalSystem_LLT EO45139_LLT(edmundLensCatalog.getEO45139().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45139().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45139 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45139_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.93703485830,8.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45139);

	//EO45266
	OpticalSystem_LLT EO45266_LLT(edmundLensCatalog.getEO45266().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45266().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45266 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45266_LLT, /*position image surface*/{ 0.0,0.0,7.0 }, /*target point*/{ 0.0,0.97135416812,7.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45266);

	//EO49931
	OpticalSystem_LLT EO49931_LLT(edmundLensCatalog.getEO49931().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49931().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49931 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49931_LLT, /*position image surface*/{ 0.0,0.0,12.0 }, /*target point*/{ 0.0,0.71530435595,12.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49931);

	//EO45412
	OpticalSystem_LLT EO45412_LLT(edmundLensCatalog.getEO45412().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45412().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45412 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45412_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.77864020294,10.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45412);

	//EO45348
	OpticalSystem_LLT EO45348_LLT(edmundLensCatalog.getEO45348().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45348().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45348 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45348_LLT, /*position image surface*/{ 0.0,0.0,9.0 }, /*target point*/{ 0.0,0.83003804892,9.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45348);

	//EO45413
	OpticalSystem_LLT EO45413_LLT(edmundLensCatalog.getEO45413().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45413().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45413 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45413_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.86697912040,8.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45413);

	//EO45104
	OpticalSystem_LLT EO45104_LLT(edmundLensCatalog.getEO45104().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45104().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45104 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45104_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.88040450886,8.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45104);

	//EO32913
	OpticalSystem_LLT EO32913_LLT(edmundLensCatalog.getEO32913().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32913().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32913 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32913_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.89077094791,8.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32913);

	//EO45349
	OpticalSystem_LLT EO45349_LLT(edmundLensCatalog.getEO45349().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45349().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45349 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45349_LLT, /*position image surface*/{ 0.0,0.0,6.0 }, /*target point*/{ 0.0,0.94548093102,6.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45349);

	//EO45350
	OpticalSystem_LLT EO45350_LLT(edmundLensCatalog.getEO45350().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45350().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45350 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45350_LLT, /*position image surface*/{ 0.0,0.0,6.0 }, /*target point*/{ 0.0,0.95297371927,6.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45350);

	//EO32915
	OpticalSystem_LLT EO32915_LLT(edmundLensCatalog.getEO32915().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32915().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32915 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32915_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.95046825857,8.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32915);

	//EO65552
	OpticalSystem_LLT EO65552_LLT(edmundLensCatalog.getEO65552().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65552().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO65552 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO65552_LLT, /*position image surface*/{ 0.0,0.0,17.0 }, /*target point*/{ 0.0,0.56482746949,17.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO65552);

	//EO49932
	OpticalSystem_LLT EO49932_LLT(edmundLensCatalog.getEO49932().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49932().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49932 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49932_LLT, /*position image surface*/{ 0.0,0.0,12.0 }, /*target point*/{ 0.0,0.74829261971,12.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49932);

	////EO45175
	//OpticalSystem_LLT EO_LLT(edmundLensCatalog.getEO45175().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45175().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());						//Glas 1 nicht im Glaskatalog
	//bool testEO45175 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45175_LLT, /*position image surface*/{ 0.0,0.0,11.0 }, /*target point*/{ 0.0,0.78743496960,11.0 });	
	//workTheLensCatalogEO45175_ThreeSurfaces.push_back(testEO45175);

	////EO45251
	//OpticalSystem_LLT EO45351_LLT(edmundLensCatalog.getEO45351().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45351().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());					//Glas 1 nicht im Glaskatalog
	//bool testEO45351 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45351_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.82850461255,10.0 });	
	//workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45351);

	//EO32722
	OpticalSystem_LLT EO32722_LLT(edmundLensCatalog.getEO32722().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32722().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32722 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32722_LLT, /*position image surface*/{ 0.0,0.0,11.0 }, /*target point*/{ 0.0,0.83415224236,11.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32722);

	//EO49933
	OpticalSystem_LLT EO49933_LLT(edmundLensCatalog.getEO49933().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49933().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49933 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49933_LLT, /*position image surface*/{ 0.0,0.0,7.0 }, /*target point*/{ 0.0,0.93464917292,7.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49933);

	//EO45267
	OpticalSystem_LLT EO45267_LLT(edmundLensCatalog.getEO45267().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45267().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45267 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45267_LLT, /*position image surface*/{ 0.0,0.0,7.0 }, /*target point*/{ 0.0,0.94178741938,7.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45267);

	//EO49934
	OpticalSystem_LLT EO49934_LLT(edmundLensCatalog.getEO49934().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49934().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49934 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49934_LLT, /*position image surface*/{ 0.0,0.0,6.0 }, /*target point*/{ 0.0,0.96572997962,6.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49934);

	//EO65553
	OpticalSystem_LLT EO65553_LLT(edmundLensCatalog.getEO65553().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO65553().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO65553 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO65553_LLT, /*position image surface*/{ 0.0,0.0,21.0 }, /*target point*/{ 0.0,0.56694036977,21.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO65553);

	//EO45211
	OpticalSystem_LLT EO45211_LLT(edmundLensCatalog.getEO45211().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45211().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45211 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45211_LLT, /*position image surface*/{ 0.0,0.0,15.0 }, /*target point*/{ 0.0,0.70850698165,15.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45211);

	////EO32319
	//OpticalSystem_LLT EO32319_LLT(edmundLensCatalog.getEO32319().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32319().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());					//Glas 1 nicht im Glaskatalog
	//bool testEO32319 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32319_LLT, /*position image surface*/{ 0.0,0.0,12.0 }, /*target point*/{ 0.0,0.77807967044,14.0 });	
	//workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32319);

	////EO32321
	//OpticalSystem_LLT EO32321_LLT(edmundLensCatalog.getEO32321().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32321().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());					//Glas 1 nicht im Glaskatalog
	//bool testEO32321 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32321_LLT, /*position image surface*/{ 0.0,0.0,12.0 }, /*target point*/{ 0.0,0.83367913444,12.0 });	
	//workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32321);

	//EO45212
	OpticalSystem_LLT EO45212_LLT(edmundLensCatalog.getEO45212().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45212().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45212 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45212_LLT, /*position image surface*/{ 0.0,0.0,11.0 }, /*target point*/{ 0.0,0.87176091393,11.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45212);

	//EO32323
	OpticalSystem_LLT EO32323_LLT(edmundLensCatalog.getEO32323().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32323().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32323 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32323_LLT, /*position image surface*/{ 0.0,0.0,12.0 }, /*target point*/{ 0.0,0.86074261138,12.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32323);

	//EO32724
	OpticalSystem_LLT EO32724_LLT(edmundLensCatalog.getEO32724().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32724().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32724 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32724_LLT, /*position image surface*/{ 0.0,0.0,12.0 }, /*target point*/{ 0.0,0.86007682145,12.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32724);

	//EO32325
	OpticalSystem_LLT EO32325_LLT(edmundLensCatalog.getEO32325().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32325().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32325 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32325_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.93193254523,10.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32325);

	//EO45213
	OpticalSystem_LLT EO45213_LLT(edmundLensCatalog.getEO45213().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45213().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45213 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45213_LLT, /*position image surface*/{ 0.0,0.0,9.0 }, /*target point*/{ 0.0,0.94273413439,9.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45213);

	//EO32327
	OpticalSystem_LLT EO32327_LLT(edmundLensCatalog.getEO32327().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32327().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32327 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32327_LLT, /*position image surface*/{ 0.0,0.0,9.0 }, /*target point*/{ 0.0,0.95426007825,9.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32327);

	//EO32492
	OpticalSystem_LLT EO32492_LLT(edmundLensCatalog.getEO32492().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32492().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32492 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32492_LLT, /*position image surface*/{ 0.0,0.0,9.0 }, /*target point*/{ 0.0,0.96269148772,9.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32492);

	//EO32494
	OpticalSystem_LLT EO32494_LLT(edmundLensCatalog.getEO32494().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32494().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32494 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32494_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.97368343124,8.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32494);

	//EO67328
	OpticalSystem_LLT EO67328_LLT(edmundLensCatalog.getEO67328().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO67328().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO67328 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO67328_LLT, /*position image surface*/{ 0.0,0.0,6.0 }, /*target point*/{ 0.0,0.98357077706,6.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO67328);

	//EO32884
	OpticalSystem_LLT EO32884_LLT(edmundLensCatalog.getEO32884().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32884().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32884 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32884_LLT, /*position image surface*/{ 0.0,0.0,9.0 }, /*target point*/{ 0.0,0.97625539757,9.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32884);

	//EO32917
	OpticalSystem_LLT EO32917_LLT(edmundLensCatalog.getEO32917().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32917().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32917 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32917_LLT, /*position image surface*/{ 0.0,0.0,13.0 }, /*target point*/{ 0.0,0.96839665277,13.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32917);

	//EO45214
	OpticalSystem_LLT EO45214_LLT(edmundLensCatalog.getEO45214().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45214().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45214 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45214_LLT, /*position image surface*/{ 0.0,0.0,6.0 }, /*target point*/{ 0.0,0.98724706847,6.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45214);

	//EO32919
	OpticalSystem_LLT EO32919_LLT(edmundLensCatalog.getEO32919().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32919().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32919 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32919_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.98478954942,8.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32919);

	//EO45414
	OpticalSystem_LLT EO45414_LLT(edmundLensCatalog.getEO45414().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45414().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45414 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45414_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.98561133561,8.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45414);

	//EO45215
	OpticalSystem_LLT EO45215_LLT(edmundLensCatalog.getEO45215().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45215().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45215 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45215_LLT, /*position image surface*/{ 0.0,0.0,6.0 }, /*target point*/{ 0.0,0.99036830474,6.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45215);

	//EO45216
	OpticalSystem_LLT EO45216_LLT(edmundLensCatalog.getEO45216().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45216().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45216 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45216_LLT, /*position image surface*/{ 0.0,0.0,6.0 }, /*target point*/{ 0.0,0.99271694424,6.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45216);

	//EO45268
	OpticalSystem_LLT EO45268_LLT(edmundLensCatalog.getEO45268().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45268().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45268 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45268_LLT, /*position image surface*/{ 0.0,0.0,6.0 }, /*target point*/{ 0.0,0.99383465903,6.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45268);

	//EO67329
	OpticalSystem_LLT EO67329_LLT(edmundLensCatalog.getEO67329().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO67329().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO67329 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO67329_LLT, /*position image surface*/{ 0.0,0.0,5.0 }, /*target point*/{ 0.0,0.99530381937,5.0 });					//R3: infinity
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO67329);

	//EO49765
	OpticalSystem_LLT EO49765_LLT(edmundLensCatalog.getEO49765().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49765().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49765 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49765_LLT, /*position image surface*/{ 0.0,0.0,14.0 }, /*target point*/{ 0.0,0.79409445272,14.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49765);

	//EO49766
	OpticalSystem_LLT EO49766_LLT(edmundLensCatalog.getEO49766().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49766().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49766 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49766_LLT, /*position image surface*/{ 0.0,0.0,12.0 }, /*target point*/{ 0.0,0.87395724518,12.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49766);

	//EO49767
	OpticalSystem_LLT EO49767_LLT(edmundLensCatalog.getEO49767().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49767().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49767 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49767_LLT, /*position image surface*/{ 0.0,0.0,12.0 }, /*target point*/{ 0.0,0.9003375879,12.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49767);

	//EO49768
	OpticalSystem_LLT EO49768_LLT(edmundLensCatalog.getEO49768().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49768().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49768 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49768_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.93369700035,10.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49768);

	//EO49769
	OpticalSystem_LLT EO49769_LLT(edmundLensCatalog.getEO49769().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49769().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49769 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49769_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.94455719093,10.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49769);

	//EO49770
	OpticalSystem_LLT EO49770_LLT(edmundLensCatalog.getEO49770().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49770().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49770 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49770_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.96189363550,8.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49770);

	//EO33917
	OpticalSystem_LLT EO33917_LLT(edmundLensCatalog.getEO33917().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO33917().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO33917 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO33917_LLT, /*position image surface*/{ 0.0,0.0,16.0 }, /*target point*/{ 0.0,0.76592048016,16.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO33917);

	//EO32500
	OpticalSystem_LLT EO32500_LLT(edmundLensCatalog.getEO32500().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32500().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32500 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32500_LLT, /*position image surface*/{ 0.0,0.0,12.0 }, /*target point*/{ 0.0,0.93622410925,12.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32500);

	//EO45217
	OpticalSystem_LLT EO45217_LLT(edmundLensCatalog.getEO45217().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45217().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45217 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45217_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.96610184708,8.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45217);

	//EO32502
	OpticalSystem_LLT EO32502_LLT(edmundLensCatalog.getEO32502().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32502().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32502 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32502_LLT, /*position image surface*/{ 0.0,0.0,11.0 }, /*target point*/{ 0.0,0.96256203972,11.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32502);

	//EO45415
	OpticalSystem_LLT EO45415_LLT(edmundLensCatalog.getEO45415().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45415().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45415 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45415_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.98008483178,8.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45415);

	//EO45269
	OpticalSystem_LLT EO45269_LLT(edmundLensCatalog.getEO45269().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45269().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45269 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45269_LLT, /*position image surface*/{ 0.0,0.0,7.0 }, /*target point*/{ 0.0,0.98923086901,7.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45269);

	//EO32496
	OpticalSystem_LLT EO32496_LLT(edmundLensCatalog.getEO32496().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32496().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32496 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32496_LLT, /*position image surface*/{ 0.0,0.0,14.0 }, /*target point*/{ 0.0,0.83549520936,14.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32496);

	//EO45140
	OpticalSystem_LLT EO45140_LLT(edmundLensCatalog.getEO45140().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45140().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45140 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45140_LLT, /*position image surface*/{ 0.0,0.0,12.0 }, /*target point*/{ 0.0,0.86442978483,12.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45140);

	//EO32498
	OpticalSystem_LLT EO32498_LLT(edmundLensCatalog.getEO32498().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32498().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32498 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32498_LLT, /*position image surface*/{ 0.0,0.0,12.0 }, /*target point*/{ 0.0,0.89089496085,12.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32498);

	//EO89681
	OpticalSystem_LLT EO89681_LLT(edmundLensCatalog.getEO89681().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO89681().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO89681 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO89681_LLT, /*position image surface*/{ 0.0,0.0,30.0 }, /*target point*/{ 0.0,0.6329486446,30.0 });					//R3 positiv
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO89681);

	//EO45218
	OpticalSystem_LLT EO45218_LLT(edmundLensCatalog.getEO45218().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45218().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45218 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45218_LLT, /*position image surface*/{ 0.0,0.0,18.0 }, /*target point*/{ 0.0,0.82942176796,18.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45218);

	//EO45105
	OpticalSystem_LLT EO45105_LLT(edmundLensCatalog.getEO45105().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45105().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45105 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45105_LLT, /*position image surface*/{ 0.0,0.0,17.0 }, /*target point*/{ 0.0,0.87268670167,17.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45105);

	//EO63701
	OpticalSystem_LLT EO63701_LLT(edmundLensCatalog.getEO63701().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO63701().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO63701 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO63701_LLT, /*position image surface*/{ 0.0,0.0,13.0 }, /*target point*/{ 0.0,0.91235390120,13.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO63701);

	//EO32921
	OpticalSystem_LLT EO32921_LLT(edmundLensCatalog.getEO32921().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32921().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32921 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32921_LLT, /*position image surface*/{ 0.0,0.0,14.0 }, /*target point*/{ 0.0,0.92315818449,14.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32921);

	//EO32923
	OpticalSystem_LLT EO32923_LLT(edmundLensCatalog.getEO32923().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32923().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32923 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32923_LLT, /*position image surface*/{ 0.0,0.0,13.0 }, /*target point*/{ 0.0,0.96012947016,13.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32923);

	//EO32925
	OpticalSystem_LLT EO32925_LLT(edmundLensCatalog.getEO32925().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32925().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32925 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32925_LLT, /*position image surface*/{ 0.0,0.0,13.0 }, /*target point*/{ 0.0,0.96839665277,13.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32925);

	//EO32935
	OpticalSystem_LLT EO32935_LLT(edmundLensCatalog.getEO32935().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32935().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32935 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32935_LLT, /*position image surface*/{ 0.0,0.0,13.0 }, /*target point*/{ 0.0,0.97542356825,13.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32935);

	//EO45178
	OpticalSystem_LLT EO45178_LLT(edmundLensCatalog.getEO45178().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45178().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45178 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45178_LLT, /*position image surface*/{ 0.0,0.0,14.0 }, /*target point*/{ 0.0,0.97584976640,14.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45178);

	//EO32927
	OpticalSystem_LLT EO32927_LLT(edmundLensCatalog.getEO32927().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32927().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32927 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32927_LLT, /*position image surface*/{ 0.0,0.0,13.0 }, /*target point*/{ 0.0,0.98486943359,13.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32927);

	//EO45352
	OpticalSystem_LLT EO45352_LLT(edmundLensCatalog.getEO45352().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45352().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45352 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45352_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.99013359020,10.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45352);

	//EO45270
	OpticalSystem_LLT EO45270_LLT(edmundLensCatalog.getEO45270().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45270().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45270 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45270_LLT, /*position image surface*/{ 0.0,0.0,10.0 }, /*target point*/{ 0.0,0.99091745837,10.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45270);

	////EO67330
	OpticalSystem_LLT EO67330_LLT(edmundLensCatalog.getEO67330().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO67330().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO67330 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO67330_LLT, /*position image surface*/{ 0.0,0.0,8.0 }, /*target point*/{ 0.0,0.99248786894,8.0 });					//R3: infinity
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO67330);

	//EO49291
	OpticalSystem_LLT EO49291_LLT(edmundLensCatalog.getEO49291().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO49291().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO49291 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO49291_LLT, /*position image surface*/{ 0.0,0.0,25.0 }, /*target point*/{ 0.0,0.80867719637,25.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO49291);

	//EO45353
	OpticalSystem_LLT EO45353_LLT(edmundLensCatalog.getEO45353().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45353().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45353 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45353_LLT, /*position image surface*/{ 0.0,0.0,18.0 }, /*target point*/{ 0.0,0.89873020306,18.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45353);

	//EO32886
	OpticalSystem_LLT EO32886_LLT(edmundLensCatalog.getEO32886().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO32886().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO32886 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO32886_LLT, /*position image surface*/{ 0.0,0.0,14.0 }, /*target point*/{ 0.0,0.95233815673,14.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO32886);

	//EO45179
	OpticalSystem_LLT EO45179_LLT(edmundLensCatalog.getEO45179().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45179().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45179 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45179_LLT, /*position image surface*/{ 0.0,0.0,13.0 }, /*target point*/{ 0.0,0.96682779682,13.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45179);

	//EO45180
	OpticalSystem_LLT EO45180_LLT(edmundLensCatalog.getEO45180().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45180().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45180 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45180_LLT, /*position image surface*/{ 0.0,0.0,14.0 }, /*target point*/{ 0.0,0.97071498600,14.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45180);

	//EO45181
	OpticalSystem_LLT EO45181_LLT(edmundLensCatalog.getEO45181().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45181().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45181 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45181_LLT, /*position image surface*/{ 0.0,0.0,13.0 }, /*target point*/{ 0.0,0.97474811549,13.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45181);

	//EO45354
	OpticalSystem_LLT EO45354_LLT(edmundLensCatalog.getEO45354().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45354().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45354 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45354_LLT, /*position image surface*/{ 0.0,0.0,12.0 }, /*target point*/{ 0.0,0.98352318661,12.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45354);

	//EO45271
	OpticalSystem_LLT EO45271_LLT(edmundLensCatalog.getEO45271().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45271().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45271 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45271_LLT, /*position image surface*/{ 0.0,0.0,12.0 }, /*target point*/{ 0.0,0.98870172195,12.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45271);

	//EO33918
	OpticalSystem_LLT EO33918_LLT(edmundLensCatalog.getEO33918().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO33918().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO33918 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO33918_LLT, /*position image surface*/{ 0.0,0.0,39.0 }, /*target point*/{ 0.0,0.78008818685,39.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO33918);

	//EO33919
	OpticalSystem_LLT EO33919_LLT(edmundLensCatalog.getEO33919().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO33919().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO33919 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO33919_LLT, /*position image surface*/{ 0.0,0.0,47.0 }, /*target point*/{ 0.0,0.83845204403,47.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO33919);

	//EO45417
	OpticalSystem_LLT EO45417_LLT(edmundLensCatalog.getEO45417().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45417().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45417 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45417_LLT, /*position image surface*/{ 0.0,0.0,24.0 }, /*target point*/{ 0.0,0.93812120288,24.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45417);

	//EO45418
	OpticalSystem_LLT EO45418_LLT(edmundLensCatalog.getEO45418().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45418().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45418 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45418_LLT, /*position image surface*/{ 0.0,0.0,20.0 }, /*target point*/{ 0.0,0.96737260277,20.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45418);

	//EO45419
	OpticalSystem_LLT EO45419_LLT(edmundLensCatalog.getEO45419().getHLT_ThreeSurfaces().getPosAndIntersection_LLT(), edmundLensCatalog.getEO45419().getHLT_ThreeSurfaces().getPosAndInteraction_LLT());
	bool testEO45419 = testOneLensThreeSurfaces(/*test light ray*/ testLightRay0, /*lens three surface opt sys*/ EO45419_LLT, /*position image surface*/{ 0.0,0.0,18.0 }, /*target point*/{ 0.0,0.97788275951,18.0 });
	workTheLensCatalogEO_ThreeSurfaces.push_back(testEO45419);

	//---
	bool returnCheckTheLensCatalogEO_ThreeSurface = Math::checkTrueOfVectorElements(workTheLensCatalogEO_ThreeSurfaces);
	return returnCheckTheLensCatalogEO_ThreeSurface;
	//---

}

// Doppelkonkave Linsen (DCV) mit NIR-I-Beschichtung
//https://www.edmundoptics.de/f/nir-i-coated-double-concave-dcv-lenses/13500/
bool TestLensCatalogEO::test_LensCatalogEO_double_concav_lenses_NIR_I()
{
	std::vector<bool> workLensCatalogEO;

	real wavelength = 550.0;
	real tolerance = 0.05;

	EdmundOpticsLensCatalog edmundLensCata;
	edmundLensCata.loadLensCatalogEO_double_concav_lenses_NIR_I();

	// 49540
	OpticalSystemElement EO49540 = edmundLensCata.getEO49540().getHLT_TwoSurfaces();
	bool checkEO49540 = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49540,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 1790.56, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49540);

	// 49541
	OpticalSystemElement EO49541 = edmundLensCata.getEO49541().getHLT_TwoSurfaces();
	bool checkEO49541 = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49541,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 1475.07, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49541);

	// 49542
	OpticalSystemElement EO49542 = edmundLensCata.getEO49542().getHLT_TwoSurfaces();
	bool checkEO49542 = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49542,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 1293.62, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49542);

	// 49543
	OpticalSystemElement EO49543 = edmundLensCata.getEO49543().getHLT_TwoSurfaces();
	bool checkEO49543 = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49543,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 1392.63, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49543);

	// 49544
	OpticalSystemElement EO49544 = edmundLensCata.getEO49544().getHLT_TwoSurfaces();
	bool checkEO49544 = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49544,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 1268.54, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49544);

	// 49545
	OpticalSystemElement EO49545 = edmundLensCata.getEO49545().getHLT_TwoSurfaces();
	bool checkEO49545 = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49545,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 1100.25, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49545);

	// 49546
	OpticalSystemElement EO49546 = edmundLensCata.getEO49546().getHLT_TwoSurfaces();
	bool checkEO49546 = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49546,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 1197.60, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49546);

	// 49547
	OpticalSystemElement EO49547 = edmundLensCata.getEO49547().getHLT_TwoSurfaces();
	bool checkEO49547 = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49547,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 1085.75, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49547);

	// 49548
	OpticalSystemElement EO49548 = edmundLensCata.getEO49548().getHLT_TwoSurfaces();
	bool checkEO49548 = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49548,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 1004.31, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49548);

	// 49549
	OpticalSystemElement EO49549 = edmundLensCata.getEO49549().getHLT_TwoSurfaces();
	bool checkEO49549 = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49549,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 1050.67, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49549);

	// 49550
	OpticalSystemElement EO49550 = edmundLensCata.getEO49550().getHLT_TwoSurfaces();
	bool checkEO49550 = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49550,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 981.401, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49550);

	// 49551
	OpticalSystemElement EO49551 = edmundLensCata.getEO49551().getHLT_TwoSurfaces();
	bool checkEO49551 = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49551,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 872.453, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49551);

	// 49552
	OpticalSystemElement EO49552 = edmundLensCata.getEO49552().getHLT_TwoSurfaces();
	bool checkEO49552 = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49552,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 803.741, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49552);



	//---
	bool returnChecker = Math::checkTrueOfVectorElements(workLensCatalogEO);
	return returnChecker;
	//---
}

// Achromate mit VIS-NIR-Beschichtung 
//https://www.edmundoptics.de/f/vis-nir-coated-achromatic-lenses/13536/
bool TestLensCatalogEO::test_LensCatalogEO_achromat_VIS_NIR_Coating()
{
	std::vector<bool> workLensCatalogEO;

	real wavelength = 550.0;
	real tolerance = 0.05;

	EdmundOpticsLensCatalog edmundLensCata;
	edmundLensCata.loadLensCatalogEO_achroamticLenses_VIS_NIR_Coating();

	// 84127
	OpticalSystemElement EO84127 = edmundLensCata.getEO84127().getHLT_ThreeSurfaces();
	bool checkEO84127 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*size aperture stop*/0.5, /*wavelength*/ wavelength, /*lens*/ EO84127,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 15.424, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO84127);

	// 84128
	OpticalSystemElement EO84128 = edmundLensCata.getEO84128().getHLT_ThreeSurfaces();
	bool checkEO84128 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO84128,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 121.419, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO84128);

	// 84129
	OpticalSystemElement EO84129 = edmundLensCata.getEO84129().getHLT_ThreeSurfaces();
	bool checkEO84129 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO84129,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 259.829, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO84129);

	// 83980
	OpticalSystemElement EO83980 = edmundLensCata.getEO83980().getHLT_ThreeSurfaces();
	bool checkEO83980 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO83980,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 349.312, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO83980);

	// 83981
	OpticalSystemElement EO83981 = edmundLensCata.getEO83981().getHLT_ThreeSurfaces();
	bool checkEO83981 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO83981,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 392.878, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO83981);

	// 63714
	OpticalSystemElement EO63714 = edmundLensCata.getEO63714().getHLT_ThreeSurfaces();
	bool checkEO63714 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO63714,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 172.996, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO63714);

	// 49300
	OpticalSystemElement EO49300 = edmundLensCata.getEO49300().getHLT_ThreeSurfaces();
	bool checkEO49300 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49300,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 175.592, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49300);

	// 49947
	OpticalSystemElement EO49947 = edmundLensCata.getEO49947().getHLT_ThreeSurfaces();
	bool checkEO49947 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49947,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 315.810, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49947);

	// 49301
	OpticalSystemElement EO49301 = edmundLensCata.getEO49301().getHLT_ThreeSurfaces();
	bool checkEO49301 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49301,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 366.343, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49301);

	// 49302
	OpticalSystemElement EO49302 = edmundLensCata.getEO49302().getHLT_ThreeSurfaces();
	bool checkEO49302 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49302,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 465.580, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49302);

	// 49948
	OpticalSystemElement EO49948 = edmundLensCata.getEO49948().getHLT_ThreeSurfaces();
	bool checkEO49948 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49948,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 144.018, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49948);

	// 49303
	OpticalSystemElement EO49303 = edmundLensCata.getEO49303().getHLT_ThreeSurfaces();
	bool checkEO49303 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49303,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 218.799, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49303);

	// 49304
	OpticalSystemElement EO49304 = edmundLensCata.getEO49304().getHLT_ThreeSurfaces();
	bool checkEO49304 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49304,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 314.078, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49304);

	// 49305
	OpticalSystemElement EO49305 = edmundLensCata.getEO49305().getHLT_ThreeSurfaces();
	bool checkEO49305 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49305,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 356.400, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49305);

	// 49949
	OpticalSystemElement EO49949 = edmundLensCata.getEO49949().getHLT_ThreeSurfaces();
	bool checkEO49949 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49949,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 444.378, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49949);

	// 49306
	OpticalSystemElement EO49306 = edmundLensCata.getEO49306().getHLT_ThreeSurfaces();
	bool checkEO49306 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49306,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 488.263, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49306);

	// 49307
	OpticalSystemElement EO49307 = edmundLensCata.getEO49307().getHLT_ThreeSurfaces();
	bool checkEO49307 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49307,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 537.404, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49307);

	// 49308
	OpticalSystemElement EO49308 = edmundLensCata.getEO49308().getHLT_ThreeSurfaces();
	bool checkEO49308 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49308,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 572.046, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49308);

	// 49309
	OpticalSystemElement EO49309 = edmundLensCata.getEO49309().getHLT_ThreeSurfaces();
	bool checkEO49309 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49309,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 604.166, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49309);

	// 49310
	OpticalSystemElement EO49310 = edmundLensCata.getEO49310().getHLT_ThreeSurfaces();
	bool checkEO49310 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49310,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 623.254, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49310);

	// 49311
	OpticalSystemElement EO49311 = edmundLensCata.getEO49311().getHLT_ThreeSurfaces();
	bool checkEO49311 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49311,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 648.185, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49311);

	// 49312
	OpticalSystemElement EO49312 = edmundLensCata.getEO49312().getHLT_ThreeSurfaces();
	bool checkEO49312 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49312,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 668.800, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49312);

	// 49313
	OpticalSystemElement EO49313 = edmundLensCata.getEO49313().getHLT_ThreeSurfaces();
	bool checkEO49313 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49313,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 401.525, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49313);

	// 49950
	OpticalSystemElement EO49950 = edmundLensCata.getEO49950().getHLT_ThreeSurfaces();
	bool checkEO49950 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49950,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 435.561, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49950);

	// 49314
	OpticalSystemElement EO49314 = edmundLensCata.getEO49314().getHLT_ThreeSurfaces();
	bool checkEO49314 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49314,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 481.114, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49314);

	// 49951
	OpticalSystemElement EO49951 = edmundLensCata.getEO49951().getHLT_ThreeSurfaces();
	bool checkEO49951 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49951,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 531.375, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49951);

	// 49315
	OpticalSystemElement EO49315 = edmundLensCata.getEO49315().getHLT_ThreeSurfaces();
	bool checkEO49315 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49315,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 575.118, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49315);

	// 49316
	OpticalSystemElement EO49316 = edmundLensCata.getEO49316().getHLT_ThreeSurfaces();
	bool checkEO49316 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49316,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 616.495, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49316);

	// 49317
	OpticalSystemElement EO49317 = edmundLensCata.getEO49317().getHLT_ThreeSurfaces();
	bool checkEO49317 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49317,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 639.235, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49317);

	// 49318
	OpticalSystemElement EO49318 = edmundLensCata.getEO49318().getHLT_ThreeSurfaces();
	bool checkEO49318 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49318,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 646.959, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49318);

	// 49319
	OpticalSystemElement EO49319 = edmundLensCata.getEO49319().getHLT_ThreeSurfaces();
	bool checkEO49319 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49319,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 679.490, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49319);

	// 49320
	OpticalSystemElement EO49320 = edmundLensCata.getEO49320().getHLT_ThreeSurfaces();
	bool checkEO49320 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49320,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 694.285, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49320);

	// 63717
	OpticalSystemElement EO63717 = edmundLensCata.getEO63717().getHLT_ThreeSurfaces();
	bool checkEO63717 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO63717,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 464.461, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO63717);

	// 63718
	OpticalSystemElement EO63718 = edmundLensCata.getEO63718().getHLT_ThreeSurfaces();
	bool checkEO63718 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO63718,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 504.213, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO63718);

	// 63719
	OpticalSystemElement EO63719 = edmundLensCata.getEO63719().getHLT_ThreeSurfaces();
	bool checkEO63719 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO63719,
		/*position image plan*/{ 0.0,0.0,10.0 }, /*rms*/ 566.145, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO63719);

	// 63720
	OpticalSystemElement EO63720 = edmundLensCata.getEO63720().getHLT_ThreeSurfaces();
	bool checkEO63720 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO63720,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO63720);

	// 63721
	OpticalSystemElement EO63721 = edmundLensCata.getEO63721().getHLT_ThreeSurfaces();
	bool checkEO63721 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO63721,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO63721);

	// 63722
	OpticalSystemElement EO63722 = edmundLensCata.getEO63722().getHLT_ThreeSurfaces();
	bool checkEO63722 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO63722,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO63722);

	// 63723
	OpticalSystemElement EO63723 = edmundLensCata.getEO63723().getHLT_ThreeSurfaces();
	bool checkEO63723 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO63723,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO63723);

	// 49321
	OpticalSystemElement EO49321 = edmundLensCata.getEO49321().getHLT_ThreeSurfaces();
	bool checkEO49321 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49321,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49321);

	// 63724
	OpticalSystemElement EO63724 = edmundLensCata.getEO63724().getHLT_ThreeSurfaces();
	bool checkEO63724 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO63724,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO63724);

	//// 49952
	//OpticalSystemElement EO49952 = edmundLensCata.getEO49952().getHLT_ThreeSurfaces();
	//bool checkEO49952 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49952,
	///*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	//workLensCatalogEO.push_back(checkEO49952);

	// 49322
	OpticalSystemElement EO49322 = edmundLensCata.getEO49322().getHLT_ThreeSurfaces();
	bool checkEO49322 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49322,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49322);

	// 49323
	OpticalSystemElement EO49323 = edmundLensCata.getEO49323().getHLT_ThreeSurfaces();
	bool checkEO49323 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49323,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49323);

	// 49324
	OpticalSystemElement EO49324 = edmundLensCata.getEO49324().getHLT_ThreeSurfaces();
	bool checkEO49324 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49324,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49324);

	// 49325
	OpticalSystemElement EO49325 = edmundLensCata.getEO49325().getHLT_ThreeSurfaces();
	bool checkEO49325 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49325,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49325);

	// 49326
	OpticalSystemElement EO49326 = edmundLensCata.getEO49326().getHLT_ThreeSurfaces();
	bool checkEO49326 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49326,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49326);

	// 49327
	OpticalSystemElement EO49327 = edmundLensCata.getEO49327().getHLT_ThreeSurfaces();
	bool checkEO49327 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49327,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49327);

	// 49328
	OpticalSystemElement EO49328 = edmundLensCata.getEO49328().getHLT_ThreeSurfaces();
	bool checkEO49328 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49328,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49328);

	// 49329
	OpticalSystemElement EO49329 = edmundLensCata.getEO49329().getHLT_ThreeSurfaces();
	bool checkEO49329 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49329,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49329);

	// 49330
	OpticalSystemElement EO49330 = edmundLensCata.getEO49330().getHLT_ThreeSurfaces();
	bool checkEO49330 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49330,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49330);

	// 49331
	OpticalSystemElement EO49331 = edmundLensCata.getEO49331().getHLT_ThreeSurfaces();
	bool checkEO49331 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49331,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49331);

	// 49332
	OpticalSystemElement EO49332 = edmundLensCata.getEO49332().getHLT_ThreeSurfaces();
	bool checkEO49332 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49332,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49332);

	// 49333
	OpticalSystemElement EO49333 = edmundLensCata.getEO49333().getHLT_ThreeSurfaces();
	bool checkEO49333 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49333,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49333);

	// 49784
	OpticalSystemElement EO49784 = edmundLensCata.getEO49784().getHLT_ThreeSurfaces();
	bool checkEO49784 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49784,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49784);

	// 49785
	OpticalSystemElement EO49785 = edmundLensCata.getEO49785().getHLT_ThreeSurfaces();
	bool checkEO49785 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49785,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49785);

	// 49786
	OpticalSystemElement EO49786 = edmundLensCata.getEO49786().getHLT_ThreeSurfaces();
	bool checkEO49786 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49786,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49786);

	// 49787
	OpticalSystemElement EO49787 = edmundLensCata.getEO49787().getHLT_ThreeSurfaces();
	bool checkEO49787 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49787,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49787);

	// 49788
	OpticalSystemElement EO49788 = edmundLensCata.getEO49788().getHLT_ThreeSurfaces();
	bool checkEO49788 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49788,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49788);

	// 49790
	OpticalSystemElement EO49790 = edmundLensCata.getEO49790().getHLT_ThreeSurfaces();
	bool checkEO49790 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49790,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49790);

	// 83417
	OpticalSystemElement EO83417 = edmundLensCata.getEO83417().getHLT_ThreeSurfaces();
	bool checkEO83417 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO83417,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO83417);

	// 49953
	OpticalSystemElement EO49953 = edmundLensCata.getEO49953().getHLT_ThreeSurfaces();
	bool checkEO49953 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49953,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49953);

	//// 49334
	//OpticalSystemElement EO49334 = edmundLensCata.getEO49334().getHLT_ThreeSurfaces();
	//bool checkEO49334 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49334,
	///*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	//workLensCatalogEO.push_back(checkEO49334);

	// 49335
	OpticalSystemElement EO49335 = edmundLensCata.getEO49335().getHLT_ThreeSurfaces();
	bool checkEO49335 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49335,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49335);

	// 49336
	OpticalSystemElement EO49336 = edmundLensCata.getEO49336().getHLT_ThreeSurfaces();
	bool checkEO49336 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49336,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49336);

	// 49337
	OpticalSystemElement EO49337 = edmundLensCata.getEO49337().getHLT_ThreeSurfaces();
	bool checkEO49337 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49337,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49337);

	// 49954
	OpticalSystemElement EO49954 = edmundLensCata.getEO49954().getHLT_ThreeSurfaces();
	bool checkEO49954 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49954,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49954);

	// 49338
	OpticalSystemElement EO49338 = edmundLensCata.getEO49338().getHLT_ThreeSurfaces();
	bool checkEO49338 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49338,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49338);

	// 49955
	OpticalSystemElement EO49955 = edmundLensCata.getEO49955().getHLT_ThreeSurfaces();
	bool checkEO49955 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49955,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49955);

	// 49339
	OpticalSystemElement EO49339 = edmundLensCata.getEO49339().getHLT_ThreeSurfaces();
	bool checkEO49339 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49339,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49339);

	// 49340
	OpticalSystemElement EO49340 = edmundLensCata.getEO49340().getHLT_ThreeSurfaces();
	bool checkEO49340 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49340,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49340);

	// 49341
	OpticalSystemElement EO49341 = edmundLensCata.getEO49341().getHLT_ThreeSurfaces();
	bool checkEO49341 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49341,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49341);

	// 49342
	OpticalSystemElement EO49342 = edmundLensCata.getEO49342().getHLT_ThreeSurfaces();
	bool checkEO49342 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49342,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49342);

	// 49343
	OpticalSystemElement EO49343 = edmundLensCata.getEO49343().getHLT_ThreeSurfaces();
	bool checkEO49343 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49343,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49343);

	// 49344
	OpticalSystemElement EO49344 = edmundLensCata.getEO49344().getHLT_ThreeSurfaces();
	bool checkEO49344 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49344,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49344);

	// 49345
	OpticalSystemElement EO49345 = edmundLensCata.getEO49345().getHLT_ThreeSurfaces();
	bool checkEO49345 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49345,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49345);

	// 49346
	OpticalSystemElement EO49346 = edmundLensCata.getEO49346().getHLT_ThreeSurfaces();
	bool checkEO49346 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49346,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49346);

	// 49347
	OpticalSystemElement EO49347 = edmundLensCata.getEO49347().getHLT_ThreeSurfaces();
	bool checkEO49347 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49347,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49347);

	// 49956
	OpticalSystemElement EO49956 = edmundLensCata.getEO49956().getHLT_ThreeSurfaces();
	bool checkEO49956 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49956,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49956);

	//// 49348
	//OpticalSystemElement EO49348 = edmundLensCata.getEO49348().getHLT_ThreeSurfaces();
	//bool checkEO49348 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49348,
	///*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	//workLensCatalogEO.push_back(checkEO49348);

	//// 49349
	//OpticalSystemElement EO49349 = edmundLensCata.getEO49349().getHLT_ThreeSurfaces();
	//bool checkEO49349 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49349,
	///*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	//workLensCatalogEO.push_back(checkEO49349);

	// 49350
	OpticalSystemElement EO49350 = edmundLensCata.getEO49350().getHLT_ThreeSurfaces();
	bool checkEO49350 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49350,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49350);

	// 49957
	OpticalSystemElement EO49957 = edmundLensCata.getEO49957().getHLT_ThreeSurfaces();
	bool checkEO49957 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49957,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49957);

	// 49351
	OpticalSystemElement EO49351 = edmundLensCata.getEO49351().getHLT_ThreeSurfaces();
	bool checkEO49351 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49351,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49351);

	// 49958
	OpticalSystemElement EO49958 = edmundLensCata.getEO49958().getHLT_ThreeSurfaces();
	bool checkEO49958 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49958,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49958);

	// 49352
	OpticalSystemElement EO49352 = edmundLensCata.getEO49352().getHLT_ThreeSurfaces();
	bool checkEO49352 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49352,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49352);

	//// 49353
	//OpticalSystemElement EO49353 = edmundLensCata.getEO49353().getHLT_ThreeSurfaces();
	//bool checkEO49353 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49353,
	///*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	//workLensCatalogEO.push_back(checkEO49353);

	//// 49354
	//OpticalSystemElement EO49354 = edmundLensCata.getEO49354().getHLT_ThreeSurfaces();
	//bool checkEO49354 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49354,
	///*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	//workLensCatalogEO.push_back(checkEO49354);

	// 49355
	OpticalSystemElement EO49355 = edmundLensCata.getEO49355().getHLT_ThreeSurfaces();
	bool checkEO49355 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49355,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49355);

	// 49356
	OpticalSystemElement EO49356 = edmundLensCata.getEO49356().getHLT_ThreeSurfaces();
	bool checkEO49356 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49356,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49356);

	// 49357
	OpticalSystemElement EO49357 = edmundLensCata.getEO49357().getHLT_ThreeSurfaces();
	bool checkEO49357 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49357,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49357);

	// 49358
	OpticalSystemElement EO49358 = edmundLensCata.getEO49358().getHLT_ThreeSurfaces();
	bool checkEO49358 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49358,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49358);

	// 49359
	OpticalSystemElement EO49359 = edmundLensCata.getEO49359().getHLT_ThreeSurfaces();
	bool checkEO49359 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49359,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49359);

	// 49360
	OpticalSystemElement EO49360 = edmundLensCata.getEO49360().getHLT_ThreeSurfaces();
	bool checkEO49360 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49360,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49360);

	// 49361
	OpticalSystemElement EO49361 = edmundLensCata.getEO49361().getHLT_ThreeSurfaces();
	bool checkEO49361 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49361,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49361);

	// 49362
	OpticalSystemElement EO49362 = edmundLensCata.getEO49362().getHLT_ThreeSurfaces();
	bool checkEO49362 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49362,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49362);

	// 67334
	OpticalSystemElement EO67334 = edmundLensCata.getEO67334().getHLT_ThreeSurfaces();
	bool checkEO67334 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO67334,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO67334);

	// 49363
	OpticalSystemElement EO49363 = edmundLensCata.getEO49363().getHLT_ThreeSurfaces();
	bool checkEO49363 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49363,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49363);

	// 49364
	OpticalSystemElement EO49364 = edmundLensCata.getEO49364().getHLT_ThreeSurfaces();
	bool checkEO49364 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49364,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49364);

	// 49365
	OpticalSystemElement EO49365 = edmundLensCata.getEO49365().getHLT_ThreeSurfaces();
	bool checkEO49365 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49365,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49365);

	// 49366
	OpticalSystemElement EO49366 = edmundLensCata.getEO49366().getHLT_ThreeSurfaces();
	bool checkEO49366 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49366,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49366);

	// 49367
	OpticalSystemElement EO49367 = edmundLensCata.getEO49367().getHLT_ThreeSurfaces();
	bool checkEO49367 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49367,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49367);

	// 49368
	OpticalSystemElement EO49368 = edmundLensCata.getEO49368().getHLT_ThreeSurfaces();
	bool checkEO49368 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49368,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49368);

	// 49369
	OpticalSystemElement EO49369 = edmundLensCata.getEO49369().getHLT_ThreeSurfaces();
	bool checkEO49369 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49369,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49369);

	// 49370
	OpticalSystemElement EO49370 = edmundLensCata.getEO49370().getHLT_ThreeSurfaces();
	bool checkEO49370 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49370,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49370);

	// 67335
	OpticalSystemElement EO67335 = edmundLensCata.getEO67335().getHLT_ThreeSurfaces();
	bool checkEO67335 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO67335,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO67335);

	// 49791
	OpticalSystemElement EO49791 = edmundLensCata.getEO49791().getHLT_ThreeSurfaces();
	bool checkEO49791 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49791,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49791);

	// 49792
	OpticalSystemElement EO49792 = edmundLensCata.getEO49792().getHLT_ThreeSurfaces();
	bool checkEO49792 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49792,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49792);

	// 49793
	OpticalSystemElement EO49793 = edmundLensCata.getEO49793().getHLT_ThreeSurfaces();
	bool checkEO49793 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49793,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49793);

	// 49794
	OpticalSystemElement EO49794 = edmundLensCata.getEO49794().getHLT_ThreeSurfaces();
	bool checkEO49794 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49794,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49794);

	// 49795
	OpticalSystemElement EO49795 = edmundLensCata.getEO49795().getHLT_ThreeSurfaces();
	bool checkEO49795 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49795,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49795);

	// 49796
	OpticalSystemElement EO49796 = edmundLensCata.getEO49796().getHLT_ThreeSurfaces();
	bool checkEO49796 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49796,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49796);

	// 33923
	OpticalSystemElement EO33923 = edmundLensCata.getEO33923().getHLT_ThreeSurfaces();
	bool checkEO33923 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO33923,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO33923);

	// 49371
	OpticalSystemElement EO49371 = edmundLensCata.getEO49371().getHLT_ThreeSurfaces();
	bool checkEO49371 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49371,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49371);

	// 49372
	OpticalSystemElement EO49372 = edmundLensCata.getEO49372().getHLT_ThreeSurfaces();
	bool checkEO49372 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49372,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49372);

	// 49373
	OpticalSystemElement EO49373 = edmundLensCata.getEO49373().getHLT_ThreeSurfaces();
	bool checkEO49373 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49373,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49373);

	// 49374
	OpticalSystemElement EO49374 = edmundLensCata.getEO49374().getHLT_ThreeSurfaces();
	bool checkEO49374 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49374,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49374);

	// 49375
	OpticalSystemElement EO49375 = edmundLensCata.getEO49375().getHLT_ThreeSurfaces();
	bool checkEO49375 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49375,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49375);

	// 49376
	OpticalSystemElement EO49376 = edmundLensCata.getEO49376().getHLT_ThreeSurfaces();
	bool checkEO49376 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49376,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49376);

	// 49377
	OpticalSystemElement EO49377 = edmundLensCata.getEO49377().getHLT_ThreeSurfaces();
	bool checkEO49377 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49377,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49377);

	// 49378
	OpticalSystemElement EO49378 = edmundLensCata.getEO49378().getHLT_ThreeSurfaces();
	bool checkEO49378 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49378,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49378);

	// 89683
	OpticalSystemElement EO89683 = edmundLensCata.getEO89683().getHLT_ThreeSurfaces();
	bool checkEO89683 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO89683,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO89683);

	// 49379
	OpticalSystemElement EO49379 = edmundLensCata.getEO49379().getHLT_ThreeSurfaces();
	bool checkEO49379 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49379,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49379);

	// 49380
	OpticalSystemElement EO49380 = edmundLensCata.getEO49380().getHLT_ThreeSurfaces();
	bool checkEO49380 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49380,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49380);

	// 63725
	OpticalSystemElement EO63725 = edmundLensCata.getEO63725().getHLT_ThreeSurfaces();
	bool checkEO63725 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO63725,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO63725);

	// 49381
	OpticalSystemElement EO49381 = edmundLensCata.getEO49381().getHLT_ThreeSurfaces();
	bool checkEO49381 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49381,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49381);

	// 49382
	OpticalSystemElement EO49382 = edmundLensCata.getEO49382().getHLT_ThreeSurfaces();
	bool checkEO49382 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49382,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49382);

	// 49383
	OpticalSystemElement EO49383 = edmundLensCata.getEO49383().getHLT_ThreeSurfaces();
	bool checkEO49383 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49383,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49383);

	// 49384
	OpticalSystemElement EO49384 = edmundLensCata.getEO49384().getHLT_ThreeSurfaces();
	bool checkEO49384 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49384,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49384);

	// 49385
	OpticalSystemElement EO49385 = edmundLensCata.getEO49385().getHLT_ThreeSurfaces();
	bool checkEO49385 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49385,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49385);

	// 49386
	OpticalSystemElement EO49386 = edmundLensCata.getEO49386().getHLT_ThreeSurfaces();
	bool checkEO49386 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49386,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49386);

	// 49387
	OpticalSystemElement EO49387 = edmundLensCata.getEO49387().getHLT_ThreeSurfaces();
	bool checkEO49387 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49387,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49387);

	// 49388
	OpticalSystemElement EO49388 = edmundLensCata.getEO49388().getHLT_ThreeSurfaces();
	bool checkEO49388 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49388,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49388);

	// 67336
	OpticalSystemElement EO67336 = edmundLensCata.getEO67336().getHLT_ThreeSurfaces();
	bool checkEO67336 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO67336,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO67336);

	// 49389
	OpticalSystemElement EO49389 = edmundLensCata.getEO49389().getHLT_ThreeSurfaces();
	bool checkEO49389 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49389,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49389);

	// 49390
	OpticalSystemElement EO49390 = edmundLensCata.getEO49390().getHLT_ThreeSurfaces();
	bool checkEO49390 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49390,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49390);

	// 49391
	OpticalSystemElement EO49391 = edmundLensCata.getEO49391().getHLT_ThreeSurfaces();
	bool checkEO49391 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49391,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49391);

	// 49392
	OpticalSystemElement EO49392 = edmundLensCata.getEO49392().getHLT_ThreeSurfaces();
	bool checkEO49392 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49392,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49392);

	// 49393
	OpticalSystemElement EO49393 = edmundLensCata.getEO49393().getHLT_ThreeSurfaces();
	bool checkEO49393 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49393,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49393);

	// 49394
	OpticalSystemElement EO49394 = edmundLensCata.getEO49394().getHLT_ThreeSurfaces();
	bool checkEO49394 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49394,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49394);

	// 49395
	OpticalSystemElement EO49395 = edmundLensCata.getEO49395().getHLT_ThreeSurfaces();
	bool checkEO49395 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49395,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49395);

	// 49396
	OpticalSystemElement EO49396 = edmundLensCata.getEO49396().getHLT_ThreeSurfaces();
	bool checkEO49396 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO49396,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO49396);

	// 33924
	OpticalSystemElement EO33924 = edmundLensCata.getEO33924().getHLT_ThreeSurfaces();
	bool checkEO33924 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO33924,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO33924);

	// 33925
	OpticalSystemElement EO33925 = edmundLensCata.getEO33925().getHLT_ThreeSurfaces();
	bool checkEO33925 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO33925,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO33925);

	// 88596
	OpticalSystemElement EO88596 = edmundLensCata.getEO88596().getHLT_ThreeSurfaces();
	bool checkEO88596 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO88596,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO88596);

	// 88597
	OpticalSystemElement EO88597 = edmundLensCata.getEO88597().getHLT_ThreeSurfaces();
	bool checkEO88597 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO88597,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO88597);

	// 88598
	OpticalSystemElement EO88598 = edmundLensCata.getEO88598().getHLT_ThreeSurfaces();
	bool checkEO88598 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO88598,
		/*position image plan*/{ 0.0,0.0,5.0 }, /*rms*/ 21.963, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO88598);



	//---
	bool returnChecker = Math::checkTrueOfVectorElements(workLensCatalogEO);
	return returnChecker;
	//---
}

// Broadband AR Coated Negative Achromatic Lenses
bool  TestLensCatalogEO::checkLensCatalogEO_Broadband_AR_Coated_Negative_Achromatic_Lenses()
{
	// https://www.edmundoptics.de/f/broadband-ar-coated-negative-achromatic-lenses/13623/

	std::vector<bool> workLensCatalogEO;

	real wavelength = 550.0;
	real tolerance = 0.2;

	EdmundOpticsLensCatalog edmundLensCata;
	edmundLensCata.loadLensCatalogEO_Broadband_AR_Coated_Negative_Achromatic_Lenses();

	// 62478
	OpticalSystemElement EO62478 = edmundLensCata.getEO62478().getHLT_ThreeSurfaces();
	bool checkEO62478 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO62478, /*position image plan*/{ 0.0,0.0,9.5 }, /*rms*/ 1292.89, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO62478);




	//---
	bool returnChecker = Math::checkTrueOfVectorElements(workLensCatalogEO);
	return returnChecker;
	//---

}


// Large Precision Achromatic Lenses 
// *** NO AIRSPACE *** ///
bool  TestLensCatalogEO::checkLensCatalogEO_Large_Precision_Achromatic_Lenses_NoAirspace()
{
	// https://www.edmundoptics.de/f/large-precision-achromatic-lenses/11679/

	std::vector<bool> workLensCatalogEO;

	real wavelength = 550.0;
	real tolerance = 0.05;

	EdmundOpticsLensCatalog edmundLensCata;
	edmundLensCata.loadLensCatalogEO_Large_Precision_Achromatic_Lenses_NoAirspace();

	// 31402
	OpticalSystemElement EO31402 = edmundLensCata.getEO31402().getHLT_ThreeSurfaces();
	bool checkEO31402 = testLensCata::testOneLensThreeSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO31402, /*position image plan*/{ 0.0,0.0,31.8 }, /*rms*/ 717.131, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO31402);




	//---
	bool returnChecker = Math::checkTrueOfVectorElements(workLensCatalogEO);
	return returnChecker;
	//---
}

// Large Precision Achromatic Lenses
// *** AIRSPACE 0.1*** ///
bool  TestLensCatalogEO::checkLensCatalogEO_Large_Precision_Achromatic_Lenses_Airspace01()
{
	// https://www.edmundoptics.de/f/large-precision-achromatic-lenses/11679/

	std::vector<bool> workLensCatalogEO;

	real wavelength = 550.0;
	real tolerance = 0.05;

	EdmundOpticsLensCatalog edmundLensCata;
	edmundLensCata.loadLensCatalogEO_Large_Precision_Achromatic_Lenses_Airspace01mm();

	// 30976
	OpticalSystemElement EO30976 = edmundLensCata.getEO30976().getHLT_FourSurfaces();
	bool checkEO30976 = testLensCata::testOneLensFourSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO30976, /*position image plan*/{ 0.0,0.0,44.34 }, /*rms*/ 732.768, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO30976);




	//---
	bool returnChecker = Math::checkTrueOfVectorElements(workLensCatalogEO);
	return returnChecker;
	//---
}

// Hastings Triplet Achromatic Lenses 
bool TestLensCatalogEO::checkLensCatalogEO_Hastings_Triplet_Achromatic_Lenses()
{
	// https://www.edmundoptics.de/f/hastings-triplet-achromatic-lenses/11968/

	std::vector<bool> workLensCatalogEO;

	real wavelength = 550.0;
	real tolerance = 0.05;

	EdmundOpticsLensCatalog edmundLensCata;
	edmundLensCata.loadLensCatalogEO_Hastings_Triplet_Achromatic_Lenses();

	// 13521
	OpticalSystemElement EO13521 = edmundLensCata.getEO13521().getHLT_FourSurfaces();
	bool checkEO13521 = testLensCata::testOneLensFourSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO13521, /*position image plan*/{ 0.0,0.0,18.23 }, /*rms*/ 13.575, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO13521);




	//---
	bool returnChecker = Math::checkTrueOfVectorElements(workLensCatalogEO);
	return returnChecker;
	//---
}

bool TestLensCatalogEO::checkLensCatalogEO_Steinheil_Triplet_Achromatic_Lenses()
{
	// https://www.edmundoptics.de/f/steinheil-triplet-achromatic-lenses/12275/

	std::vector<bool> workLensCatalogEO;

	real wavelength = 550.0;
	real tolerance = 0.05;

	EdmundOpticsLensCatalog edmundLensCata;
	edmundLensCata.loadLensCatalogEO_Steinheil_Triplet_Achromatic_Lenses();

	// 47673
	OpticalSystemElement EO47673 = edmundLensCata.getEO47673().getHLT_FourSurfaces();
	bool checkEO47673 = testLensCata::testOneLensFourSurfaces_startInf_0deg(/*wavelength*/ wavelength, /*lens*/ EO47673, /*position image plan*/{ 0.0,0.0,20.0 }, /*rms*/ 66.980, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO47673);




	//---
	bool returnChecker = Math::checkTrueOfVectorElements(workLensCatalogEO);
	return returnChecker;
	//---
}

bool TestLensCatalogEO::checkLensCatalogEO_Micro_Plano_Convex_PCX_Lenses()
{
	// https://www.edmundoptics.de/f/micro-plano-convex-pcx-lenses/39529/

	std::vector<bool> workLensCatalogEO;

	real wavelength = 550.0;
	real tolerance = 0.05;

	EdmundOpticsLensCatalog edmundLensCata;
	edmundLensCata.loadLensCatalogEO_Micro_Plano_Convex_PCX_Lenses();

	// 45951
	OpticalSystemElement EO45951 = edmundLensCata.getEO45951().getHLT_TwoSurfaces();
	// here it is possible to adjust the size of the aperture stop
	bool checkEO45951 = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*size aperture stop*/ 0.2, /*wavelength*/ wavelength, /*lens*/ EO45951, /*position image plan*/{ 0.0,0.0,3.0 }, /*rms*/ 291.796, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO45951);




	//---
	bool returnChecker = Math::checkTrueOfVectorElements(workLensCatalogEO);
	return returnChecker;
	//---
}

bool TestLensCatalogEO::checkLensCatalogEO_Large_PCX_Condenser_Lenses()
{
https://www.edmundoptics.de/f/large-pcx-condenser-lenses/13572/

	std::vector<bool> workLensCatalogEO;

	real wavelength = 550.0;
	real tolerance = 0.05;

	EdmundOpticsLensCatalog edmundLensCata;
	edmundLensCata.loadLensCatalogEO_Large_PCX_Condenser_Lenses();

	// 67187
	OpticalSystemElement EO67187 = edmundLensCata.getEO67187().getHLT_TwoSurfaces();
	// here it is possible to adjust the size of the aperture stop
	bool checkEO67187 = testLensCata::testOneLensTwoSurfaces_startInf_0deg(/*size aperture stop*/ 30.0, /*wavelength*/ wavelength, /*lens*/ EO67187, /*position image plan*/{ 0.0,0.0,122.0 }, /*rms*/ 4949.69, /*tolerance*/ tolerance);
	workLensCatalogEO.push_back(checkEO67187);




	//---
	bool returnChecker = Math::checkTrueOfVectorElements(workLensCatalogEO);
	return returnChecker;
	//---

}