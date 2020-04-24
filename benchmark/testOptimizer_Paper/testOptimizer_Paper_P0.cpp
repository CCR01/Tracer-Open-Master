#include "testOptimizer_Paper_P0.h"

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

#include <chrono>
#include "..\..\Inport_Export_Data\Inport_Export_Data.h"


testOptimizer_Paper_P0::testOptimizer_Paper_P0() {};

testOptimizer_Paper_P0::~testOptimizer_Paper_P0() {};


bool testOptimizer_Paper_P0::checkTestOptimizer_paper_P0()
{

	
	std::string test = "test";
	double testDouble = 1.123;
	std::string location = "../benchmark/testOptimizer_Paper/";
	std::string optiSysP0 = "exportDataP0_optiSys";
	std::string timeRayTrace = "exportDataP0_timeRayTrace";
	
	//inportExportData::saveDoubleInTXT(location, nameSaveData, test, testDouble);

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interactionPtr;

	std::vector<bool> workTheOptimizer;
	real tolerance = 0.0001;

	// interactions 
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	Light_LLT Light0_P0;
	Light0_P0.setWavelength(587.5618);
	Light0_P0.setIntensity(1.0);

	Light_LLT Light1_P0;
	Light1_P0.setWavelength(486.1327);
	Light1_P0.setIntensity(1.0);

	Light_LLT Light2_P0;
	Light2_P0.setWavelength(656.2725);
	Light2_P0.setIntensity(1.0);


	std::vector<Light_LLT> lichtVecP0{ Light0_P0, Light1_P0, Light2_P0 };

	// surfaces P0
	ApertureStopElement AperStoP0_P0(/* semi height*/5.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAirZemax());
	SphericalElement Sphere1_P0(/*radius*/ 30.0, /*semi height*/ 15.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBK7_S1());
	SphericalElement Sphere2_P0(/*radius*/ 40.0, /*semi height*/ 15.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getSF13_S1());
	SphericalElement Sphere3_P0(/*radius*/ 30.0, /*semi height*/ 15.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF13_S1());
	PlanElement Plan4_P0(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,90.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAirZemax(), /*refractive index B*/ glasses.getAirZemax());

	// set parameter variable
	Sphere1_P0.setParameterRadius(20.0, 50.0, 0.0, typeModifierVariable); // radius of surface Sphere1_P0 is variable
	Sphere2_P0.setParameterRadius(20.0, 50.0, 0.0, typeModifierVariable); // radius of surface Sphere1_P0 is variable
	Sphere3_P0.setParameterRadius(20.0, 40.0, 0.0, typeModifierVariable); // radius of surface Sphere6_P0 is variable

	surfacePtr AperStoP0_P0_ptr = AperStoP0_P0.clone();
	surfacePtr Sphere1_P0_ptr = Sphere1_P0.clone();
	surfacePtr Sphere2_P0_ptr = Sphere2_P0.clone();
	surfacePtr Sphere3_P0_ptr = Sphere3_P0.clone();
	surfacePtr Plan4_P0_ptr = Plan4_P0.clone();

	std::vector<surfacePtr> opticalSystemP0_ptr{ AperStoP0_P0_ptr, Sphere1_P0_ptr, Sphere2_P0_ptr, Sphere3_P0_ptr, Plan4_P0_ptr };
	std::vector<interactionPtr> interactionsP0_ptr{ doNothing.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_P0(opticalSystemP0_ptr, interactionsP0_ptr);

	// trace the ray thow the optical system
	SequentialRayTracing seqTrace_P0_optA(/*optical system element*/ optSystemElement_P0, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecP0);
	SequentialRayTracing seqTrace_P0_field2(/*optical system element*/ optSystemElement_P0, /*start point lightRay*/{ 0.0,3.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecP0);
	SequentialRayTracing seqTrace_P0_field4(/*optical system element*/ optSystemElement_P0, /*start point lightRay*/{ 0.0,6.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecP0);

	// calculate rms value
	Spot spot_E12_optA(seqTrace_P0_optA.getAllInterPointsAtSurf_i_notFiltered(4), seqTrace_P0_optA.getAllInterPointsAtSurf_i_notFiltered(4).at(0));
	real rms_E12_optA = spot_E12_optA.getRMS_µm();
	bool checkRMSoptA_E12 = Math::compareTwoNumbers_decimals(rms_E12_optA, 1840.14, 2);
	workTheOptimizer.push_back(checkRMSoptA_E12);
	Spot spot_E12_field2(seqTrace_P0_field2.getAllInterPointsAtSurf_i_notFiltered(4), seqTrace_P0_field2.getAllInterPointsAtSurf_i_notFiltered(4).at(0));
	real rms_E12_field2 = spot_E12_field2.getRMS_µm();
	bool checkRMSfield2_E12 = Math::compareTwoNumbers_decimals(rms_E12_field2, 1769.82, 2);
	workTheOptimizer.push_back(checkRMSfield2_E12);
	Spot spot_E12_field4(seqTrace_P0_field4.getAllInterPointsAtSurf_i_notFiltered(4), seqTrace_P0_field4.getAllInterPointsAtSurf_i_notFiltered(4).at(0));
	real rms_E12_field4 = spot_E12_field4.getRMS_µm();
	bool checkRMSfield4_E12 = Math::compareTwoNumbers_decimals(rms_E12_field4, 1586.65, 2);
	workTheOptimizer.push_back(checkRMSfield4_E12);

	// next we start the optimasation
	std::cout << "start of the optimizer P0 changing population rate" << std::endl;
	unsigned int start_population_P0 = 1000;
	unsigned int end_population_P0 = 3000;
	unsigned int changePopulation = 100;

	std::vector<real> vectorToExportP0_opti;

	for (start_population_P0; start_population_P0 <=end_population_P0; start_population_P0 = start_population_P0 + changePopulation)
	{ 	
		vectorToExportP0_opti.clear();

		localStart localOp_P0 = radiusStart;
		real mutarionFactor_P0 = 0.01;

		optSystemElement_P0.setRefractiveIndexAccordingToWavelength(Light0_P0.getWavelength());
		OptimizeOpticalSystem optimizedOptSys_P0(optSystemElement_P0, start_population_P0, mutarionFactor_P0, localOp_P0);
		optimizedOptSys_P0.setCheckAllLocalCombinations_optimizer(true);
		optimizedOptSys_P0.add_FieldAndWeight({ 0.0,3.0,0.0 }, 1.0);
		optimizedOptSys_P0.add_FieldAndWeight({ 0.0,6.0,0.0 }, 1.0);
		optimizedOptSys_P0.set_Light(Light0_P0);
		optimizedOptSys_P0.add_Light(Light1_P0);
		optimizedOptSys_P0.add_Light(Light2_P0);
		//real targetEFL = 20.0;
		//optimizedOptSys_P0.add_TargetEFL(targetEFL, 20.0);
		//real targerEXPD = 25.0;
		//optimizedOptSys_P0.add_TargetEXPD(targerEXPD, 20.0);


		// *********************************
		// start optimtestOptimizerasation of example P0
		auto startTimeOptimization_total = std::chrono::high_resolution_clock::now();
		optimizedOptSys_P0.optimizeSUPERFUNCTION();
		auto endTimeOptimization_total = std::chrono::high_resolution_clock::now();
		//auto durationOptimization_ms = std::chrono::duration_cast<std::chrono::microseconds>(endTimeOptimization - startTimeOptimization).count();
		std::chrono::duration<double> TotalDurationOptimization_secondes = endTimeOptimization_total - startTimeOptimization_total;
		auto totalDurationOptimization_min = TotalDurationOptimization_secondes.count() / 60.0;

		vectorToExportP0_opti.push_back(start_population_P0);
		vectorToExportP0_opti.push_back(optimizedOptSys_P0.getNumberGenerations());
		vectorToExportP0_opti.push_back(optimizedOptSys_P0.getDurationTimeLocalOptiInMin());
		vectorToExportP0_opti.push_back(optimizedOptSys_P0.getDurationTimeGeneticOptiInMin());
		vectorToExportP0_opti.push_back(totalDurationOptimization_min);
		
		
		//std::cout << "total duration time P0 in minutes: " << totalDurationOptimization_min << " minutes" << std::endl;
		// *********************************

		// get the optimized optical system
		OpticalSystemElement optimizedOptSys_Ele_P0 = optimizedOptSys_P0.getOptSysOptimized_Ele();
		
		std::cout << "population " << start_population_P0 << std::endl;

		// trace the ray thow the optimized optical system
		SequentialRayTracing seqTrace_optA_AO_P0(/*optical system element*/ optimizedOptSys_Ele_P0, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecP0);
		Spot Spot_optA_AO_P0(seqTrace_optA_AO_P0.getAllInterPointsAtSurf_i_notFiltered(4), seqTrace_optA_AO_P0.getAllInterPointsAtSurf_i_notFiltered(4).at(0));
		real sporRMS_optA_AO_P0 = Spot_optA_AO_P0.getRMS_µm();
		vectorToExportP0_opti.push_back(sporRMS_optA_AO_P0);
		std::cout << "optA P0 rms " << sporRMS_optA_AO_P0 << std::endl;
		real spotZemaxOA_optA_P0 = 328.252;
	

		SequentialRayTracing seqTrace_field2_AO_P0(/*optical system element*/ optimizedOptSys_Ele_P0, /*start point lightRay*/{ 0.0,3.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecP0);
		Spot Spot_field2_AO_P0(seqTrace_field2_AO_P0.getAllInterPointsAtSurf_i_notFiltered(4), seqTrace_field2_AO_P0.getAllInterPointsAtSurf_i_notFiltered(4).at(0));
		real sporRMS_field2_AO_P0 = Spot_field2_AO_P0.getRMS_µm();
		vectorToExportP0_opti.push_back(sporRMS_field2_AO_P0);
		std::cout << "field2 P0 rms " << sporRMS_field2_AO_P0 << std::endl;
		real spotZemaxOA_field2_P0 = 519.097;

		SequentialRayTracing seqTrace_field4_AO_P0(/*optical system element*/ optimizedOptSys_Ele_P0, /*start point lightRay*/{ 0.0,6.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecP0);
		Spot Spot_field4_AO_P0(seqTrace_field4_AO_P0.getAllInterPointsAtSurf_i_notFiltered(4), seqTrace_field4_AO_P0.getAllInterPointsAtSurf_i_notFiltered(4).at(0));
		real sporRMS_field4_AO_P0 = Spot_field4_AO_P0.getRMS_µm();
		vectorToExportP0_opti.push_back(sporRMS_field4_AO_P0);
		std::cout << "field4 P0 rms " << sporRMS_field4_AO_P0 << std::endl;
		real spotZemaxOA_field4_P0 = 1059.94;



		// get the radii
		real radiusS1 = optimizedOptSys_Ele_P0.getOpticalSystemElement().getPosAndElement().at(1).getElementInOptSys_ptr()->getRadiusElementValue();
		std::cout << "radius S1: " << radiusS1 << std::endl;
		vectorToExportP0_opti.push_back(radiusS1);
		real radiusS2 = optimizedOptSys_Ele_P0.getOpticalSystemElement().getPosAndElement().at(2).getElementInOptSys_ptr()->getRadiusElementValue();
		std::cout << "radius S2: " << radiusS2 << std::endl;
		vectorToExportP0_opti.push_back(radiusS2);
		real radiusS3 = optimizedOptSys_Ele_P0.getOpticalSystemElement().getPosAndElement().at(3).getElementInOptSys_ptr()->getRadiusElementValue();
		std::cout << "radius S3: " << radiusS3 << std::endl;
		vectorToExportP0_opti.push_back(radiusS3);

		real zemaxSum = spotZemaxOA_optA_P0 + spotZemaxOA_field2_P0 + spotZemaxOA_field4_P0;
		std::cout << "zemax sum P0 rms " << zemaxSum << std::endl;
		real GLOWsum = sporRMS_optA_AO_P0 + sporRMS_field2_AO_P0 + sporRMS_field4_AO_P0;
		std::cout << "GLOW sum P0 rms " << GLOWsum << std::endl;
		vectorToExportP0_opti.push_back(GLOWsum);
		bool checkGLOWsumBetterZemaxSum = GLOWsum - zemaxSum < 0.0;
		vectorToExportP0_opti.push_back(checkGLOWsumBetterZemaxSum);

		inportExportData::exportDataToExcel_vector(location, optiSysP0, "population, numberGenerations, timeLocal, timeGenetic, totalTime, spotOptA, spotField2, spotField4, GLOWsumRMS, radiusS1, radiusS2, radiusS3, GLOW better Zemax", vectorToExportP0_opti);

	}
	

//	unsigned int startRayDensity = 3;
//	unsigned int endRayDensity = 60;
//	unsigned int deltaRayDensity = 1;
//
//	std::vector<real> vectorToExportP0_rayDensity;
//
//	for (startRayDensity; startRayDensity <= endRayDensity; startRayDensity = startRayDensity + deltaRayDensity)
//	{
//		vectorToExportP0_rayDensity.clear();
//		//std::cout << "current ray density: " << startRayDensity << std::endl;
//		// trace the ray thow the optical system
//		vectorToExportP0_rayDensity.push_back(startRayDensity);
//		
//		//optA
//		auto timeStart_optA = std::chrono::high_resolution_clock::now();
//		SequentialRayTracing seqTrace_P0_optA(/*optical system element*/ optSystemElement_P0, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ startRayDensity, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecP0);
//		auto timeEnd_optA = std::chrono::high_resolution_clock::now();
//		std::chrono::duration<double> timeTotal_OptA = timeEnd_optA - timeStart_optA;
//		auto timeTotal_optA_min = timeTotal_OptA.count() / 60.0;
//
//		
//		//field2
//		auto timeStart_field2 = std::chrono::high_resolution_clock::now();
//		SequentialRayTracing seqTrace_P0_field2(/*optical system element*/ optSystemElement_P0, /*start point lightRay*/{ 0.0,2.0,0.0 }, /*rings*/ startRayDensity, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecP0);
//		auto timeEnd_field2 = std::chrono::high_resolution_clock::now();
//		std::chrono::duration<double> timeTotal_Field2 = timeEnd_field2 - timeStart_field2;
//		auto timeTotal_Field2_min = timeTotal_Field2.count() / 60.0;
//
//		
//
//		auto timeStart_field4 = std::chrono::high_resolution_clock::now();
//		SequentialRayTracing seqTrace_P0_field4(/*optical system element*/ optSystemElement_P0, /*start point lightRay*/{ 0.0,4.0,0.0 }, /*rings*/ startRayDensity, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecP0);
//		auto timeEnd_field4 = std::chrono::high_resolution_clock::now();
//		std::chrono::duration<double> timeTotal_Field4 = timeEnd_field4 - timeStart_field4;
//		auto timeTotal_Field4_min = timeTotal_Field4.count() / 60.0;
//
//
//		unsigned int totalNumRay = seqTrace_P0_optA.getStartPoints().size();
//		vectorToExportP0_rayDensity.push_back(totalNumRay);
//		vectorToExportP0_rayDensity.push_back(timeTotal_optA_min);
//		vectorToExportP0_rayDensity.push_back(timeTotal_Field2_min);
//		vectorToExportP0_rayDensity.push_back(timeTotal_Field4_min);
//
//		real totalTime = timeTotal_optA_min + timeTotal_Field2_min + timeTotal_Field4_min;
//		vectorToExportP0_rayDensity.push_back(totalTime);
//
//		real timePerRay = totalTime / totalNumRay;
//		vectorToExportP0_rayDensity.push_back(timePerRay);
//
//		std::cout << "current ray density: " << startRayDensity << std::endl;
//		std::cout << "time per ray: " << timePerRay << std::endl;
//
//		inportExportData::exportDataToExcel_vector(location, timeRayTrace, "ray density, number ray, time optA, time field2, time field 4, total time, timePerRay", vectorToExportP0_rayDensity);
//
//	}
//
//
//	
//	
	bool checkTheOptimizer = Math::checkTrueOfVectorElements(workTheOptimizer);

	return checkTheOptimizer;

}