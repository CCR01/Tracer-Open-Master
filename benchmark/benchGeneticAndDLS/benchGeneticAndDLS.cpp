
#include "benchGeneticAndDLS.h"

// include surfaces
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\PlanElement.h"
#include "..\..\SurfaceElements\ApertureStopElement.h"

// include interactions
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"

// include the glas cataloge
#include "..\..\Glasses\Glasses.h"

// include the optimizer
#include "..\..\OptimizeSystem\OptimizeOpticalSystem.h"

#include "..\..\Inport_Export_Data\Inport_Export_Data.h"

#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

#include "..\..\OptimizeSystem\Genetic.h"

#include "..\..\OptimizeSystem\DampedLeastSquares.h"

#include <chrono>
#include <string>


benchGeneticAndDLS::benchGeneticAndDLS(){}
benchGeneticAndDLS::~benchGeneticAndDLS(){}



bool benchGeneticAndDLS::testSpeedGeneticAndDLS()
{
	unsigned int defaultRings_6 = 6;
	unsigned int defaultArms_8 = 8;

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interactionPtr;

	std::vector<bool> test_vec;
	real tolerance = 0.001;

	// field
	VectorStructR3 field0 = { 0.0,0.0,0.0 };
	VectorStructR3 field2 = { 0.0,2.0,0.0 };
	VectorStructR3 field4 = { 0.0,4.0,0.0 };
	
	std::vector<VectorStructR3> fields_vec024 = { field0, field2, field4 };

	real wave486 = 486.1327;
	real wave587 = 587.5618;
	real wave656 = 656.2725;

	std::vector<real> waveFdC = { wave587, wave486, wave656 };

	std::string location = "../benchmark/testOptimizer_Paper/";
	std::string nameToSave = "exportDataP1";

	// interactions 
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	Light_LLT Light0_P1;
	Light0_P1.setWavelength(587.5618);
	Light0_P1.setIntensity(1.0);

	Light_LLT Light1_P1;
	Light1_P1.setWavelength(486.1327);
	Light1_P1.setIntensity(1.0);

	Light_LLT Light2_P1;
	Light2_P1.setWavelength(656.2725);
	Light2_P1.setIntensity(1.0);


	std::vector<Light_LLT> lichtVecP1{ Light0_P1, Light1_P1, Light2_P1 };

	// surfaces P1
	ApertureStopElement AperStoP1_P1(/* semi height*/3.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_P1(/*radius*/ 100.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2_P1(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF5_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere3_P1(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere4_P1(/*radius*/ 100.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF10_S1());
	SphericalElement Sphere5_P1(/*radius*/ 120.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF10_S1(), /*refractive index B*/glasses.getAir());
	SphericalElement Sphere6_P1(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement Sphere7_P1(/*radius*/ 100.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF57_S1(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement Sphere8_P1(/*radius*/ 60.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF57_S1());
	PlanElement Plan9_P1(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,125.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	// set parameter variable
	Sphere1_P1.setParameterRadius(30.0, 90.0, 0.0, typeModifierVariable); // radius of surface Sphere1_P1 is variable
	Sphere3_P1.setParameterPointZ(0.5, 20.0 , 0.0, typeModifierVariable); // position of surface Sphere4_P1 is variable
	Sphere6_P1.setParameterRadius(30.0, 90.0, 0.0, typeModifierVariable); // radius of surface Sphere6_P1 is variable	

	surfacePtr AperStoP1_P1_ptr = AperStoP1_P1.clone();
	surfacePtr Sphere1_P1_ptr = Sphere1_P1.clone();
	surfacePtr Sphere2_P1_ptr = Sphere2_P1.clone();
	surfacePtr Sphere3_P1_ptr = Sphere3_P1.clone();
	surfacePtr Sphere4_P1_ptr = Sphere4_P1.clone();
	surfacePtr Sphere5_P1_ptr = Sphere5_P1.clone();
	surfacePtr Sphere6_P1_ptr = Sphere6_P1.clone();
	surfacePtr Sphere7_P1_ptr = Sphere7_P1.clone();
	surfacePtr Sphere8_P1_ptr = Sphere8_P1.clone();
	surfacePtr Plan9_P1_ptr = Plan9_P1.clone();

	std::vector<surfacePtr> opticalSystemP1_ptr{ AperStoP1_P1_ptr, Sphere1_P1_ptr, Sphere2_P1_ptr, Sphere3_P1_ptr, Sphere4_P1_ptr, Sphere5_P1_ptr, Sphere6_P1_ptr, Sphere7_P1_ptr, Sphere8_P1_ptr, Plan9_P1_ptr };
	std::vector<interactionPtr> interactionsP1_ptr{ doNothing.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	// build optical system
	OpticalSystemElement optSystemElement_P1(opticalSystemP1_ptr, interactionsP1_ptr);

	// test the system
	std::vector<real> rms_Zemax{ 562.646, 595.267,693.648 };
	bool test_P1 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement_P1, fields_vec024, waveFdC, rms_Zemax, 1.0, compareTOM_Zemax::comEqual);
	test_vec.push_back(test_P1);

	// genetic
	Genetic genetic(/*optSysEle*/ optSystemElement_P1, /*fields*/ fields_vec024,/*wavelengths*/ waveFdC, /*rings*/ defaultRings_6,/*arms*/ defaultArms_8,/*populatuion*/1000);
	
	//* load default parameter genetic
	genetic.setStartRefIndex(1.0);
	genetic.setToleranceWithoutMIN_Radius(-0.5);
	genetic.setToleranceWithoutMAX_Radius(0.5);
	genetic.setMaxInterationGenetic(10);
	genetic.setDeltaMeritValueStop(0.1);
	genetic.setToleranceForEvaluation(0.001);
	genetic.setChooseValueMode(randomMode);
	//*


	// do the genetic process
	auto timeStart_genetic = std::chrono::high_resolution_clock::now();
	genetic.doTheGeneticProcess();
	auto timeEnd_genetic = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> timeTotal_genetic = timeEnd_genetic - timeStart_genetic;
	real timeGenetic_second = timeTotal_genetic.count();
	std::cout << "total time for genetic: " << timeGenetic_second << std::endl;

	real maxTimeForGenetic_1000systems = 60.0;
	test_vec.push_back(timeGenetic_second < maxTimeForGenetic_1000systems);

	OpticalSystemElement optimizedOpticalSystem_genetic = genetic.getOptimizedOpticalSystemElement();
	oftenUse::print(optimizedOpticalSystem_genetic, waveFdC[0]);

	// DLS
	DLS DLS_E0(/*optSysEle*/ optimizedOpticalSystem_genetic,/*fields*/ fields_vec024, /*wavelength*/ waveFdC, /*rings*/ defaultRings_6, /*arms*/ defaultArms_8);
	DLS_E0.setDampingFactor(5.0);
	DLS_E0.setFactorRadiusDeviation(0.000001);
	DLS_E0.setFactorPositionDeviation(0.000001);
	DLS_E0.setStartRefractivIndex(1.0);
	DLS_E0.setMaxWorstCounter(100);
	DLS_E0.setImproveMeritStopDiff(0.000001);
	DLS_E0.setMaxInterations(200);
	DLS_E0.setFlipOrientationRadius(1000.0);
	DLS_E0.setMaxBorderViolations(20);
	DLS_E0.setMaxDeltaParameter(25.0);
	DLS_E0.setMinDeltaParameter(0.00001);
	DLS_E0.setFactorGettingBetter(0.4);
	DLS_E0.setFactorGettingWorst(1.9);

	auto timeStart_DLS = std::chrono::high_resolution_clock::now();
	DLS_E0.optimizeSystem_DLS_multiplicativ_Damping();
	auto timeEnd_DLS = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> timeTotal_DLS = timeEnd_DLS - timeStart_DLS;
	real timeDLS_second = timeTotal_DLS.count();
	std::cout << "total time for DLS: " << timeDLS_second << std::endl;

	real maxTimeForDLS_1000systems = 60.0;
	test_vec.push_back(timeDLS_second < maxTimeForDLS_1000systems);


	OpticalSystemElement optimizedOptSysEle_DLS = DLS_E0.getOptimizedSystem_HLT();

	std::vector<real> rms_Z{ 59.082,68.554,110.298 };
	bool betterZ_E0 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optimizedOptSysEle_DLS, fields_vec024, waveFdC, rms_Z, 1.0, compareTOM_Zemax::comBetter);
	test_vec.push_back(betterZ_E0);

	oftenUse::print(optimizedOptSysEle_DLS, waveFdC[0]);

	bool chcker = Math::checkTrueOfVectorElements(test_vec);
	return chcker;

	
}