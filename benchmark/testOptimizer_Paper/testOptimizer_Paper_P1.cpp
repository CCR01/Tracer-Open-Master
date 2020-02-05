#include "testOptimizer_Paper_P1.h"

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

#include <chrono>
#include <string>

testOptimizer_Paper_P1::testOptimizer_Paper_P1() {}
testOptimizer_Paper_P1::~testOptimizer_Paper_P1() {}

bool testOptimizer_Paper_P1::checkTestOptimizer_paper_p1(double startR1, double endR1, double deltaR1, double startDistanceS4, double endDistanceS4, double deltaDistanceS4, double startR6, double endR6, double deltaR6, double minAirGap)
{


	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interactionPtr;

	std::vector<bool> workTheOptimizer;
	real tolerance = 0.001;
	

	std::string location = "../benchmark/testOptimizer_Paper/";
	std::string nameToSave = "exportDataP1";
	//---
	// data for R1
	real tempStartR1 = startR1;
	real tempEndR1 = endR1;
	real tempDeltaR1 = deltaR1;

	// date for distance S3 - S4 -> positon of spherical surface S4
	real tempStartDistanceS3S4 = startDistanceS4;
	real tempEndDistanceS3S4 = endDistanceS4;
	real tempDeltaDistanceS3S4 = deltaDistanceS4;

	// data for R6
	real tempStartR6 = startR6;
	real tempEndR6 = endR6;
	real tempDeltaR6 = deltaR6;
	//---

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

	while (tempStartR1 >= 25.0)
	{

		// surfaces P1
		ApertureStopElement AperStoP1_P1(/* semi height*/3.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAirZemax());
		SphericalElement Sphere1_P1(/*radius*/ 100.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBK7_S1());
		SphericalElement Sphere2_P1(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF5_S1(), /*refractive index B*/glasses.getBK7_S1());
		SphericalElement Sphere3_P1(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF5_S1());
		SphericalElement Sphere4_P1(/*radius*/ 100.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF10_S1());
		SphericalElement Sphere5_P1(/*radius*/ 120.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF10_S1(), /*refractive index B*/glasses.getAirZemax());
		SphericalElement Sphere6_P1(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getNSSK8_S1());
		SphericalElement Sphere7_P1(/*radius*/ 100.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF57_S1(), /*refractive index B*/glasses.getNSSK8_S1());
		SphericalElement Sphere8_P1(/*radius*/ 60.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF57_S1());
		PlanElement Plan9_P1(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,125.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAirZemax(), /*refractive index B*/ glasses.getAirZemax());

		// set parameter variable
		Sphere1_P1.setParameterRadius(tempStartR1, tempEndR1, 0.0, typeModifierVariable); // radius of surface Sphere1_P1 is variable
		Sphere4_P1.setParameterPointZ(50.0, 50.0 + tempEndDistanceS3S4, 0.0, typeModifierVariable); // position of surface Sphere4_P1 is variable
		Sphere6_P1.setParameterRadius(tempStartR6, tempEndR6, 0.0, typeModifierVariable); // radius of surface Sphere6_P1 is variable	

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

		//	build optical system
		OpticalSystemElement optSystemElement_P1(opticalSystemP1_ptr, interactionsP1_ptr);

		// trace the ray thow the optical system
		SequentialRayTracing seqTrace_P1_optA(/*optical system element*/ optSystemElement_P1, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecP1);
		SequentialRayTracing seqTrace_P1_field2(/*optical system element*/ optSystemElement_P1, /*start point lightRay*/{ 0.0,2.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecP1);
		SequentialRayTracing seqTrace_P1_field4(/*optical system element*/ optSystemElement_P1, /*start point lightRay*/{ 0.0,4.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecP1);
		
		// calculate rms value
		Spot spot_E12_optA(seqTrace_P1_optA.getAllInterPointsAtSurf_i(9), seqTrace_P1_optA.getAllInterPointsAtSurf_i(9).at(0));
		real rms_E12_optA = spot_E12_optA.getRMS_µm();
		bool checkRMSoptA_E12 = Math::compareTwoNumbers(rms_E12_optA, 562.646, 3);
		workTheOptimizer.push_back(checkRMSoptA_E12);
		Spot spot_E12_field2(seqTrace_P1_field2.getAllInterPointsAtSurf_i(9), seqTrace_P1_field2.getAllInterPointsAtSurf_i(9).at(0));
		real rms_E12_field2 = spot_E12_field2.getRMS_µm();
		bool checkRMSfield2_E12 = Math::compareTwoNumbers(rms_E12_field2, 595.267, 3);
		workTheOptimizer.push_back(checkRMSfield2_E12);
		Spot spot_E12_field4(seqTrace_P1_field4.getAllInterPointsAtSurf_i(9), seqTrace_P1_field4.getAllInterPointsAtSurf_i(9).at(0));
		real rms_E12_field4 = spot_E12_field4.getRMS_µm();
		bool checkRMSfield4_E12 = Math::compareTwoNumbers(rms_E12_field4, 693.648, 3);
		workTheOptimizer.push_back(checkRMSfield4_E12);

		// next we start the optimasation
		std::cout << "start of the optimizer P1" << std::endl;
		unsigned int population_P1 = 1000;
		localStart localOp_P1 = radiusStart;
		real mutarionFactor_P1 = 0.01;
		   	 
		OptimizeOpticalSystem optimizedOptSys_P1(optSystemElement_P1, population_P1, mutarionFactor_P1, localOp_P1);
		optimizedOptSys_P1.setCheckAllLocalCombinations_optimizer(true);
		optimizedOptSys_P1.add_FieldAndWeight({ 0.0,2.0,0.0 }, 1.0);
		optimizedOptSys_P1.add_FieldAndWeight({ 0.0,4.0,0.0 }, 1.0);
		optimizedOptSys_P1.set_Light(Light0_P1);
		optimizedOptSys_P1.add_Light(Light1_P1);
		optimizedOptSys_P1.add_Light(Light2_P1);
		optimizedOptSys_P1.setMinGapSurface_optimizer(minAirGap);

		// *********************************
		// start optimtestOptimizerasation of example P1

		std::vector<real> vectorToExport;

		

		auto startOptimization = std::chrono::high_resolution_clock::now();
		optimizedOptSys_P1.optimizeSUPERFUNCTION();
		auto endOptimization = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> durationOptimization = endOptimization - startOptimization;

		OpticalSystemElement optimizedOptSys_Ele_P1 = optimizedOptSys_P1.getOptSysOptimized_Ele();
		real timeGeneticOpt = optimizedOptSys_P1.getDurationTimeGeneticOptiInMin();
		vectorToExport.push_back(timeGeneticOpt);
		real timeLocalOpti = optimizedOptSys_P1.getDurationTimeLocalOptiInMin();
		vectorToExport.push_back(timeLocalOpti);
		real totalDurationOptimization_min = durationOptimization.count() / 60.0;
		vectorToExport.push_back(totalDurationOptimization_min);
		real deltaGes = std::abs(startR1 - tempStartR1) + std::abs(endR1 - tempEndR1) + std::abs(startDistanceS4 - tempStartDistanceS3S4) + std::abs(endDistanceS4 - tempEndDistanceS3S4) + std::abs(startR6 - tempStartR6) + std::abs(endR6 - tempEndR6);
		vectorToExport.push_back(deltaGes);
		real R1_toExport = optimizedOptSys_Ele_P1.getPosAndElement().at(1).getElementInOptSys_ptr()->getRadiusElementValue();
		vectorToExport.push_back(R1_toExport);
		real R6_toExport = optimizedOptSys_Ele_P1.getPosAndElement().at(6).getElementInOptSys_ptr()->getRadiusElementValue();
		vectorToExport.push_back(R6_toExport);
		
		// *********************************
		
		
		// get the optimized optical system
		
		// trace the ray thow the optimized optical system
		SequentialRayTracing seqTrace_optA_AO_P1(/*optical system element*/ optimizedOptSys_Ele_P1, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecP1);
		Spot Spot_optA_AO_P1(seqTrace_optA_AO_P1.getAllInterPointsAtSurf_i(9), seqTrace_optA_AO_P1.getAllInterPointsAtSurf_i(9).at(0));
		real sporRMS_optA_AO_P1 = Spot_optA_AO_P1.getRMS_µm();
		std::cout << "optA P1 rms " << sporRMS_optA_AO_P1 << std::endl;
		real spotZemaxOA_optA_P1 = 55.082;
		
		SequentialRayTracing seqTrace_field2_AO_P1(/*optical system element*/ optimizedOptSys_Ele_P1, /*start point lightRay*/{ 0.0,2.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecP1);
		Spot Spot_field2_AO_P1(seqTrace_field2_AO_P1.getAllInterPointsAtSurf_i(9), seqTrace_field2_AO_P1.getAllInterPointsAtSurf_i(9).at(0));
		real sporRMS_field2_AO_P1 = Spot_field2_AO_P1.getRMS_µm();
		std::cout << "field2 P1 rms " << sporRMS_field2_AO_P1 << std::endl;
		real spotZemaxOA_field2_P1 = 68.554;
		
		SequentialRayTracing seqTrace_field4_AO_P1(/*optical system element*/ optimizedOptSys_Ele_P1, /*start point lightRay*/{ 0.0,4.0,0.0 }, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, lichtVecP1);
		Spot Spot_field4_AO_P1(seqTrace_field4_AO_P1.getAllInterPointsAtSurf_i(9), seqTrace_field4_AO_P1.getAllInterPointsAtSurf_i(9).at(0));
		real sporRMS_field4_AO_P1 = Spot_field4_AO_P1.getRMS_µm();
		std::cout << "field4 P1 rms " << sporRMS_field4_AO_P1 << std::endl;
		real spotZemaxOA_field4_P1 = 110.297;
		
		real zemaxSum = spotZemaxOA_optA_P1 + spotZemaxOA_field2_P1 + spotZemaxOA_field4_P1;
		std::cout << "zemax sum P1 rms " << zemaxSum << std::endl;
		real GLOWsum = sporRMS_optA_AO_P1 + sporRMS_field2_AO_P1 + sporRMS_field4_AO_P1;
		std::cout << "GLOW sum P1 rms " << GLOWsum << std::endl;
		
		//bool checkGLOWsumBetterZemaxSum = GLOWsum - zemaxSum < 0.0;
		// we check that later in the excel file!
		//workTheOptimizer.push_back(checkGLOWsumBetterZemaxSum);
		
		// check if the distances are correct;
		real PointZ_S0_P1 = optimizedOptSys_Ele_P1.getPosAndElement().at(0).getElementInOptSys_ptr()->getPointElementValue_Z();
		real PointZ_S1_P1 = optimizedOptSys_Ele_P1.getPosAndElement().at(1).getElementInOptSys_ptr()->getPointElementValue_Z();
		real PointZ_S2_P1 = optimizedOptSys_Ele_P1.getPosAndElement().at(2).getElementInOptSys_ptr()->getPointElementValue_Z();
		real PointZ_S3_P1 = optimizedOptSys_Ele_P1.getPosAndElement().at(3).getElementInOptSys_ptr()->getPointElementValue_Z();
		real PointZ_S4_P1 = optimizedOptSys_Ele_P1.getPosAndElement().at(4).getElementInOptSys_ptr()->getPointElementValue_Z();
		real PointZ_S5_P1 = optimizedOptSys_Ele_P1.getPosAndElement().at(5).getElementInOptSys_ptr()->getPointElementValue_Z();
		real PointZ_S6_P1 = optimizedOptSys_Ele_P1.getPosAndElement().at(6).getElementInOptSys_ptr()->getPointElementValue_Z();
		real PointZ_S7_P1 = optimizedOptSys_Ele_P1.getPosAndElement().at(7).getElementInOptSys_ptr()->getPointElementValue_Z();
		real PointZ_S8_P1 = optimizedOptSys_Ele_P1.getPosAndElement().at(8).getElementInOptSys_ptr()->getPointElementValue_Z();
		real PointZ_S9_P1 = optimizedOptSys_Ele_P1.getPosAndElement().at(9).getElementInOptSys_ptr()->getPointElementValue_Z();
		
		real distaneS0_S1_P1 = PointZ_S1_P1 - PointZ_S0_P1;
		real distaneS1_S2_P1 = PointZ_S2_P1 - PointZ_S1_P1;
		real distaneS2_S3_P1 = PointZ_S3_P1 - PointZ_S2_P1;
		real distaneS3_S4_P1 = PointZ_S4_P1 - PointZ_S3_P1;
		real distaneS4_S5_P1 = PointZ_S5_P1 - PointZ_S4_P1;
		real distaneS5_S6_P1 = PointZ_S6_P1 - PointZ_S5_P1;
		real distaneS6_S7_P1 = PointZ_S7_P1 - PointZ_S6_P1;
		real distaneS7_S8_P1 = PointZ_S8_P1 - PointZ_S7_P1;
		real distaneS8_S9_P1 = PointZ_S9_P1 - PointZ_S8_P1;
		
		bool checkPosApertureStop = std::abs(optimizedOptSys_Ele_P1.getPosAndElement().at(0).getElementInOptSys_ptr()->getPointElementValue_Z() - 30.0) < tolerance;
		workTheOptimizer.push_back(checkPosApertureStop);
		bool checkDistaneS0_S1 = std::abs(distaneS0_S1_P1 - 5.0) < tolerance;
		workTheOptimizer.push_back(checkDistaneS0_S1);
		bool checkDistaneS1_S2 = std::abs(distaneS1_S2_P1 - 10.0) < tolerance;
		workTheOptimizer.push_back(checkDistaneS1_S2);
		bool checkDistaneS2_S3 = std::abs(distaneS2_S3_P1 - 5.0) < tolerance;
		workTheOptimizer.push_back(checkDistaneS2_S3);
		bool checkDistaneS3_S4 = distaneS3_S4_P1 != 10.0;
		workTheOptimizer.push_back(checkDistaneS3_S4);
		std::cout << "distance S3 to S4: " << distaneS3_S4_P1 << std::endl;
		// distance S3 - S4 must be greater then min air gap
		bool checkDistaneS3_S4_greaterMinAirGap = std::abs(distaneS3_S4_P1 - minAirGap) < tolerance;
		workTheOptimizer.push_back(checkDistaneS3_S4_greaterMinAirGap);
		bool checkDistaneS4_S5 = std::abs(distaneS4_S5_P1 - 10.0) < tolerance;
		workTheOptimizer.push_back(checkDistaneS4_S5);
		bool checkDistaneS5_S6 = std::abs(distaneS5_S6_P1 - 10.0) < tolerance;
		workTheOptimizer.push_back(checkDistaneS5_S6);
		bool checkDistaneS6_S7 = std::abs(distaneS6_S7_P1 - 10.0) < tolerance;
		workTheOptimizer.push_back(checkDistaneS6_S7);
		bool checkDistaneS7_S8 = std::abs(distaneS7_S8_P1 - 5.0) < tolerance;
		workTheOptimizer.push_back(checkDistaneS7_S8);
		bool checkDistaneS8_S9 = std::abs(distaneS8_S9_P1 - 30.0) < tolerance;
		workTheOptimizer.push_back(checkDistaneS8_S9);
		
		vectorToExport.push_back(distaneS3_S4_P1);
		vectorToExport.push_back(sporRMS_optA_AO_P1);
		vectorToExport.push_back(sporRMS_field2_AO_P1);
		vectorToExport.push_back(sporRMS_field4_AO_P1);
		vectorToExport.push_back(GLOWsum);

		bool checkTheOptimizer = Math::checkTrueOfVectorElements(workTheOptimizer);
		vectorToExport.push_back(checkTheOptimizer);
		
		vectorToExport.push_back(tempStartR1);
		vectorToExport.push_back(tempEndR1);
		vectorToExport.push_back(tempStartR6);
		vectorToExport.push_back(tempEndR6);
		vectorToExport.push_back(tempStartDistanceS3S4);
		vectorToExport.push_back(tempEndDistanceS3S4);

		int numberGenerations = optimizedOptSys_P1.getNumberGenerations();
		vectorToExport.push_back(numberGenerations);

		inportExportData::exportDataToExcel_vector(location, nameToSave, "timeGeneticOpti, timeLocalOpti, timeTotalOpti, deltaGes, R1, R6, D3-4, RMS0, RMS2, RMS4, sumRMS, checkTheProzess, tempStartR1, tempEndR1, tempStartR6, tempEndR6, tempStartDis34, tempEndDis34, numberGenerations", vectorToExport);

		tempStartR1 = tempStartR1 - deltaR1;
		tempEndR1 = tempEndR1 + deltaR1;
		tempStartR6 = tempStartR6 - deltaR6;
		tempEndR6 = tempEndR6 + deltaR6;
		tempEndDistanceS3S4 = tempEndDistanceS3S4 + deltaDistanceS4;
	}

	return true;
}