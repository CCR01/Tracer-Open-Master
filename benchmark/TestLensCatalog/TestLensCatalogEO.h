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


private:

};

