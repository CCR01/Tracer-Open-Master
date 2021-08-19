#pragma once
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"

class TestLensCatalogEO
{
public:
	TestLensCatalogEO();
	~TestLensCatalogEO();

	// test one lens with two surfaces;
	bool testOneLensTwoSurfaces(LightRayStruct lightRay, OpticalSystem_LLT optSysElement, VectorStructR3 positionImageSurface, VectorStructR3 targetVector);
	// test one lens with three surfaces
	bool testOneLensThreeSurfaces(LightRayStruct lightRay, OpticalSystem_LLT optSysElement, VectorStructR3 positionImageSurface, VectorStructR3 targetVector);
	// test the lens catalog from edmund optics with two surfaces
	bool testCatalogEO_TwoSurfaces_1();
	bool testCatalogEO_TwoSurfaces_2();
	bool testCatalogEO_TwoSurfaces_3();
	// test the lens catalog from edmund optics with three surfaces
	bool testCatalogEO_ThreeSurfaces();
	// test Doppelkonkave (DCV) Linsen VIS-NIR AR beschichtet 
	// https://www.edmundoptics.de/f/vis-nir-coated-double-concave-dcv-lenses/13540/
	bool testCatalogEO_DCV();
	// Plankonkave (PCV) Linsen mit VIS-NIR Beschichtung
	// https://www.edmundoptics.de/p/3mm-diameter-x6-fl-vis-nir-coated-plano-concave-lens/27489/
	bool testcatalogEO_PCV();
	// Doppelkonkave Linsen (DCV) mit NIR-I-Beschichtung
	//https://www.edmundoptics.de/f/nir-i-coated-double-concave-dcv-lenses/13500/
	bool test_LensCatalogEO_double_concav_lenses_NIR_I();
	// Achromate mit VIS-NIR-Beschichtung 
	//https://www.edmundoptics.de/f/vis-nir-coated-achromatic-lenses/13536/
	bool test_LensCatalogEO_achromat_VIS_NIR_Coating();
	// Broadband AR Coated Negative Achromatic Lenses
	// https://www.edmundoptics.de/f/broadband-ar-coated-negative-achromatic-lenses/13623/
	bool  checkLensCatalogEO_Broadband_AR_Coated_Negative_Achromatic_Lenses();

	// https://www.edmundoptics.de/f/large-precision-achromatic-lenses/11679/
	bool checkLensCatalogEO_Large_Precision_Achromatic_Lenses_NoAirspace();
	bool checkLensCatalogEO_Large_Precision_Achromatic_Lenses_Airspace01();

	// Hastings Triplet Achromatic Lenses 
	// https://www.edmundoptics.de/f/hastings-triplet-achromatic-lenses/11968/
	bool checkLensCatalogEO_Hastings_Triplet_Achromatic_Lenses();
	
	// Steinheil Triplet Achromatic Lenses 
	// https://www.edmundoptics.de/f/steinheil-triplet-achromatic-lenses/12275/
	bool checkLensCatalogEO_Steinheil_Triplet_Achromatic_Lenses();

	// Micro Plano-Convex (PCX) Lenses 
	// https://www.edmundoptics.de/f/micro-plano-convex-pcx-lenses/39529/
	bool checkLensCatalogEO_Micro_Plano_Convex_PCX_Lenses();

	// Large PCX Condenser Lenses
	// https://www.edmundoptics.de/f/large-pcx-condenser-lenses/13572/
	bool checkLensCatalogEO_Large_PCX_Condenser_Lenses();

private:

};

