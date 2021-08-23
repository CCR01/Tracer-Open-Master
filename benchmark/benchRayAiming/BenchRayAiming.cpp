#include "BenchRayAiming.h"

// sequantuial ray tracing
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"

// ray aiming
#include "..\..\RayAiming\RayAiming.h"

// interactions
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"

// inport export dara
#include "..\..\Inport_Export_Data\Inport_Export_Data.h"

// light
#include "..\..\LowLevelTracing\Light_LLT.h"


#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"

// glass catalogue
#include "..\..\Glasses\Glasses.h"

// aperture stop
#include "..\..\FillAptertureStop\FillApertureStop.h"

// spot
#include "..\..\Analyse\Spot.h"

#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

// surface
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\PlanElement.h"
#include "..\..\SurfaceElements\ApertureStopElement.h"

// ray Aiming super function 12 cores
#include "..\..\RayAiming\RayAimingSuperFct.h"

// ray aiming inital rays 12 cores 
#include "..\..\RayAiming\RayAiming_12Cores_initalRays.h"

// typedef
typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;
// ***

BenchRayAiming::BenchRayAiming() {}
BenchRayAiming::~BenchRayAiming() {}


bool BenchRayAiming::benchRayAiming_superFct()
{
	std::vector<bool> workTheSystem;

	//// benchE0
	//bool checkE0 =  benchRayAimingE0();
	//workTheSystem.push_back(checkE0);

	//benchE0_
	bool checkE0_ = benchRayAimingE0_();
	workTheSystem.push_back(checkE0_);

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}
// benchE0
bool BenchRayAiming::benchRayAimingE0()
{
	// ***
	bool checkerClassicRayAiming = true;
	bool checkerRayAimingInitalRay = true;
	bool checkerClassicalRayAiming_12Cores = true;
	bool checkerRayAiming_initalRays_12Cores = true;

	bool initalCheckerClassicRayAiming = checkerClassicRayAiming;
	bool initalCheckerRayAimingInitalRay = checkerRayAimingInitalRay;
	bool initalCheckerClassicalRayAiming_12Cores = checkerClassicalRayAiming_12Cores;
	bool initalCheckerRayAiming_initalRays_12Cores = checkerRayAiming_initalRays_12Cores;

	int minRayDensity = 3;
	int maxRayDensity = 60; // total max is 60

	int tempRoundNumber = 1;
	int maxRounds = 10;

	std::vector<std::vector<std::vector<real>>> exportVector_classicalRayAiming;
	std::vector<std::vector<std::vector<real>>> exportVector_classicalRayAiming_12Cores;
	std::vector<std::vector<std::vector<real>>> exportVector_RayAiming_initalRays;
	std::vector<std::vector<std::vector<real>>> exportVector_RayAiming_initalRays_12Cores;

	exportVector_classicalRayAiming.resize(maxRounds);
	exportVector_classicalRayAiming_12Cores.resize(maxRounds);
	exportVector_RayAiming_initalRays.resize(maxRounds);
	exportVector_RayAiming_initalRays_12Cores.resize(maxRounds);

	// ***


	//*** standard ***//
	std::vector<bool> workTheSystem;
	std::string location = "../benchmark/benchRayAiming/E0";
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	glass glasses;
	glasses.loadGlassCatalog_Schott();
	std::vector<real> wavelenght_vec;
	wavelenght_vec.push_back(550.0);
	wavelenght_vec.push_back(400.0);
	wavelenght_vec.push_back(700.0);
	VectorStructR3 startPoint = { 1.0,2.0,0.0 };

	Light_LLT light = oftenUse::getDefaultLight();
	//*** ------  ***//

	real tolerance = 0.2;

	
	// build the optical system
	SphericalElement S0(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S1(/*radius*/ 70.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSF5_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());
	
	SphericalElement S3(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF14_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement S5(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF14_S1());
	
	ApertureStopElement S6(/* semi height*/4.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	
	SphericalElement S7(/*radius*/ 60.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF57_S1());
	SphericalElement S8(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSF6_S1(), /*refractive index B*/glasses.getSF57_S1());
	SphericalElement S9(/*radius*/ 35.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNSF6_S1(), /*refractive index B*/glasses.getAir());
	
	PlanElement S10(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,110.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr };
	std::vector<interaction_ptr> interactions_ptr{ refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSysEle(opticalSystem_ptr, interactions_ptr);

	// test the system
	real rms_Zemax{ 434.867 };
	bool testStart = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle, startPoint, wavelenght_vec, rms_Zemax, tolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testStart);

	int sizeOptSys = optSysEle.getPosAndElement().size() - 1;

	real tolerance_XandY = 0.0001;
	real startPointFactor = 1.0;
	int maxLoopsTraceToLastSurface = 5;
	int maxInterationsRayAiming = 50;
	real factor_inf = 0.1;
	real factor_obj = 0.1;
	bool rubustRayAiming = true;
	real variancePercentRobustRA = 5.0;
	int maxStayCounter = 2;
	real increaserFactorTimes = 10.0;
	real tolerance_XandYforARealLightRay = 0.1;
	real factorStartHeight_inf = 0.5;
	real factorStartHeight_obj = 0.5;
	real maxInterationRobustRayAiming = 10;
	int maxRayThatNotBeAimable = 5;
	real infinity_neg = -1000000.0;


	defaultRayAimingStruct paraRayAiming;
	paraRayAiming.setTolerance_XandY(tolerance_XandY);
	paraRayAiming.setStartPointFactor(startPointFactor);
	paraRayAiming.setMaxLoopsTraceToLastSurface(maxLoopsTraceToLastSurface);
	paraRayAiming.setMaxIterationsRayAiming(maxInterationsRayAiming);
	paraRayAiming.setFactor_inf(factor_inf);
	paraRayAiming.setFactor_obj(factor_obj);
	if (rubustRayAiming)
	{
		paraRayAiming.turn_On_RobustRayAiming();
	}
	else
	{
		paraRayAiming.turn_Off_RobustRayAiming();
	}
	paraRayAiming.setVariancePercentRRA(variancePercentRobustRA);
	paraRayAiming.setMaxStayCounter(maxStayCounter);
	paraRayAiming.setIncreaserFactorTimes(increaserFactorTimes);
	paraRayAiming.setTolerancceForRealLightRay(tolerance_XandYforARealLightRay);
	paraRayAiming.setFactorStartHeight_inf(factorStartHeight_inf);
	paraRayAiming.setFactorStartHeight_obj(factorStartHeight_obj);
	paraRayAiming.setMaxInterationRobustRayAiming(maxInterationRobustRayAiming);
	paraRayAiming.setMaxRaysThatNotBeAimable(maxRayThatNotBeAimable);
	paraRayAiming.setInfinity_neg(infinity_neg);
	paraRayAiming.turn_ON_GlobalStopIfToManyRaysAreNotAimed();
	paraRayAiming.setRecodTimeInitalRay(true);

	infosAS infosAeperStop = optSysEle.getInfoAS();
	real toleranceRMS = 25.0;
	unsigned int tempRayDensity = minRayDensity;
	unsigned int arms = 8;
	real tempRMS;


	bool checkRound = true;
	int tempRoundToSave = 0;
	while (checkRound)
	{
		std::string roundString = std::to_string(tempRoundNumber);

		// **********************
		// *** benchmark classical ray aiming ***
		OpticalSystem_LLT tempOpticalSystem_LLT;
		std::vector<std::vector<LightRayStruct>> aimedLightRays(3);
		std::vector<real> saveTime_sec_RayAimingInital;
		saveTime_sec_RayAimingInital.resize(wavelenght_vec.size());
		std::string nameSave_classicalRayAiming = "classicalRayAiming";
		nameSave_classicalRayAiming = nameSave_classicalRayAiming + "_" + roundString;
		std::vector<real> vectorToExport;
		if (checkerClassicRayAiming)
		{
			inportExportData::removeDateCSV(location, nameSave_classicalRayAiming);
		}
		while (checkerClassicRayAiming)
		{

			FillApertureStop FillAS(infosAeperStop, tempRayDensity, arms);
			int numberOfRays = FillAS.getPointsInAS().size();
			int totalNumberOfRays = FillAS.getPointsInAS().size() * wavelenght_vec.size();

			vectorToExport.push_back(tempRayDensity); // ray density
			vectorToExport.push_back(numberOfRays); // number rays per wavelength
			vectorToExport.push_back(totalNumberOfRays); // total number rays


			RayAiming rayA_classic;
			rayA_classic.setLoadImportantDefaulParameterRayAiming(false);
			rayA_classic.setDefaultParameters(paraRayAiming);

			vectorToExport.push_back(rayA_classic.getTolerance_XandY()); // tolerance in X and Y

			for (unsigned int i = 0; i < wavelenght_vec.size(); ++i)
			{
				light.setWavelength(wavelenght_vec[i]);
				auto timeStart = std::chrono::high_resolution_clock::now();
				optSysEle.setRefractiveIndexAccordingToWavelength(wavelenght_vec[i]);
				tempOpticalSystem_LLT = optSysEle.getLLTconversion_doConversion();
				rayA_classic.setOpticalSystem_LLT(tempOpticalSystem_LLT);
				rayA_classic.loadImportantInfosForRayAiming();
				rayA_classic.turn_On_RobustRayAiming();

				aimedLightRays[i] = rayA_classic.rayAimingMany_obj(FillAS.getPointsInAS(), startPoint, light, 1.0);
				//aimedLightRays[i] = rayA_classic.rayAimingMany_obj_complete(tempOpticalSystem_LLT, FillAS.getPointsInAS(), startPoint, light);
				auto timeEnd = std::chrono::high_resolution_clock::now();
				std::chrono::duration<real> timeTotal_duration = timeEnd - timeStart;
				real timeTotal_sec = timeTotal_duration.count();
				saveTime_sec_RayAimingInital[i] = timeTotal_sec;
			}

			vectorToExport.push_back(saveTime_sec_RayAimingInital[0]); // green
			vectorToExport.push_back(saveTime_sec_RayAimingInital[1]); // blue
			vectorToExport.push_back(saveTime_sec_RayAimingInital[2]); // red
			vectorToExport.push_back(saveTime_sec_RayAimingInital[0] + saveTime_sec_RayAimingInital[1] + saveTime_sec_RayAimingInital[2]); // total time

			// check RayAiming
			SequentialRayTracing tempSeqTrace;
			std::vector<VectorStructR3> tempInterPoints;
			std::vector<VectorStructR3> saveAllInterPoints;
			for (unsigned int i = 0; i < wavelenght_vec.size(); ++i)
			{

				optSysEle.setRefractiveIndexAccordingToWavelength(wavelenght_vec[i]);
				tempOpticalSystem_LLT = optSysEle.getLLTconversion_doConversion();
				tempSeqTrace.setOpticalSystem(optSysEle);
				tempSeqTrace.setTraceToSurface(sizeOptSys);
				tempSeqTrace.seqRayTracingWithVectorOfLightRays(aimedLightRays[i]);

				tempInterPoints = tempSeqTrace.getAllInterPointsAtSurf_i_notFiltered(sizeOptSys);

				saveAllInterPoints.insert(saveAllInterPoints.end(), tempInterPoints.begin(), tempInterPoints.end());

				tempSeqTrace.clearAllTracedRays();
			}


			Spot spotCheck(saveAllInterPoints, saveAllInterPoints[0]);
			tempRMS = spotCheck.getRMS_µm();
			bool checkRMS = Math::compareTwoNumbers_tolerance(tempRMS, rms_Zemax, toleranceRMS);
			vectorToExport.push_back(checkRMS);
			workTheSystem.push_back(checkRMS);
			if (tempRoundNumber == 1)
			{
				inportExportData::exportDataToExcel_vector(location, nameSave_classicalRayAiming, "ray density, number rays per wavelength, total number of rays, tolerance in X and Y, time sec green, time sec blue, time sec red, total time sec, check RMS", vectorToExport);
			}

			exportVector_classicalRayAiming[tempRoundToSave].push_back(vectorToExport);
			vectorToExport.clear();
			++tempRayDensity;

			if (tempRayDensity > maxRayDensity)
			{
				checkerClassicRayAiming = false;
			}


		}
		// **********************


		// **********************
		// *** ray aiming inital rays ***
		tempRayDensity = minRayDensity;
		aimedLightRays.clear();
		aimedLightRays.resize(wavelenght_vec.size());
		std::vector<real> saveTime_sec_RayAiming_initialRays;
		saveTime_sec_RayAiming_initialRays.resize(wavelenght_vec.size());
		std::string nameSave_RayAimingInitalRays = "rayAimingInitalRays";
		nameSave_RayAimingInitalRays = nameSave_RayAimingInitalRays + "_" + roundString;
		vectorToExport.clear();
		if (checkerRayAimingInitalRay)
		{
			inportExportData::removeDateCSV(location, nameSave_RayAimingInitalRays);
		}
		while (checkerRayAimingInitalRay)
		{
			FillApertureStop FillAS(infosAeperStop, tempRayDensity, arms);
			int numberOfRays = FillAS.getPointsInAS().size();
			int totalNumberOfRays = FillAS.getPointsInAS().size() * wavelenght_vec.size();

			vectorToExport.push_back(tempRayDensity); // ray density
			vectorToExport.push_back(numberOfRays); // number rays per wavelength
			vectorToExport.push_back(totalNumberOfRays); // total number rays


			RayAiming rayA_initalRays;
			rayA_initalRays.setLoadImportantDefaulParameterRayAiming(false);
			rayA_initalRays.setDefaultParameters(paraRayAiming);
			rayA_initalRays.setDefaultParametersInitalRays_obj_initalRays();

			vectorToExport.push_back(rayA_initalRays.getTolerance_XandY()); // tolerance in X and Y

			aimedLightRays = rayA_initalRays.rayAiming_obj_initalRays_complete(optSysEle, FillAS.getPointsInAS(), wavelenght_vec, startPoint, light);


			saveTime_sec_RayAiming_initialRays = rayA_initalRays.getTime_sec();
			vectorToExport.push_back(saveTime_sec_RayAiming_initialRays[0]); // green
			vectorToExport.push_back(saveTime_sec_RayAiming_initialRays[1]); // blue
			vectorToExport.push_back(saveTime_sec_RayAiming_initialRays[2]); // red
			vectorToExport.push_back(saveTime_sec_RayAiming_initialRays[0] + saveTime_sec_RayAiming_initialRays[1] + saveTime_sec_RayAiming_initialRays[2]); // total time

			// check RayAiming
			SequentialRayTracing tempSeqTrace;
			std::vector<VectorStructR3> tempInterPoints;
			std::vector<VectorStructR3> saveAllInterPoints;
			for (unsigned int i = 0; i < wavelenght_vec.size(); ++i)
			{

				optSysEle.setRefractiveIndexAccordingToWavelength(wavelenght_vec[i]);
				tempOpticalSystem_LLT = optSysEle.getLLTconversion_doConversion();
				tempSeqTrace.setOpticalSystem(optSysEle);
				tempSeqTrace.setTraceToSurface(sizeOptSys);
				tempSeqTrace.seqRayTracingWithVectorOfLightRays(aimedLightRays[i]);

				tempInterPoints = tempSeqTrace.getAllInterPointsAtSurf_i_notFiltered(sizeOptSys);

				saveAllInterPoints.insert(saveAllInterPoints.end(), tempInterPoints.begin(), tempInterPoints.end());

				tempSeqTrace.clearAllTracedRays();
			}


			Spot spotCheck(saveAllInterPoints, saveAllInterPoints[0]);
			tempRMS = spotCheck.getRMS_µm();
			bool checkRMS = Math::compareTwoNumbers_tolerance(tempRMS, rms_Zemax, toleranceRMS);
			vectorToExport.push_back(checkRMS);
			workTheSystem.push_back(checkRMS);
			if (tempRoundNumber == 1)
			{
				inportExportData::exportDataToExcel_vector(location, nameSave_RayAimingInitalRays, "ray density, number rays per wavelength, total number of rays, tolerance in X and Y, time sec green, time sec blue, time sec red, total time sec, check RMS", vectorToExport);
			}
			exportVector_RayAiming_initalRays[tempRoundToSave].push_back(vectorToExport);

			vectorToExport.clear();
			++tempRayDensity;

			if (tempRayDensity > maxRayDensity)
			{
				checkerRayAimingInitalRay = false;
			}

		}
		// **********************
		// *** classical ray aiming 12 cores ***
		tempRayDensity = minRayDensity;
		aimedLightRays.clear();
		aimedLightRays.resize(wavelenght_vec.size());
		std::vector<real> saveTime_sec_ClassicalRayAiming_12Cores;
		saveTime_sec_ClassicalRayAiming_12Cores.resize(wavelenght_vec.size());
		std::string nameSave_ClassicalRayAiming_12Cores = "classicalRayAiming_12Cores";
		nameSave_ClassicalRayAiming_12Cores = nameSave_ClassicalRayAiming_12Cores + "_" + roundString;
		vectorToExport.clear();
		if (checkerClassicalRayAiming_12Cores)
		{
			inportExportData::removeDateCSV(location, nameSave_ClassicalRayAiming_12Cores);
		}
		while (checkerClassicalRayAiming_12Cores)
		{
			FillApertureStop FillAS(infosAeperStop, tempRayDensity, arms);
			int numberOfRays = FillAS.getPointsInAS().size();
			int totalNumberOfRays = FillAS.getPointsInAS().size() * wavelenght_vec.size();

			vectorToExport.push_back(tempRayDensity); // ray density
			vectorToExport.push_back(numberOfRays); // number rays per wavelength
			vectorToExport.push_back(totalNumberOfRays); // total number rays

			for (unsigned int i = 0; i < wavelenght_vec.size(); ++i)
			{
				light.setWavelength(wavelenght_vec[i]);

				RayAiming_12Cores rayAimingSuperFct_12Cores;
				optSysEle.setRefractiveIndexAccordingToWavelength(wavelenght_vec[i]);
				tempOpticalSystem_LLT = optSysEle.getLLTconversion_doConversion();
				rayAimingSuperFct_12Cores.loadInput(tempOpticalSystem_LLT, tempRayDensity, arms, startPoint, light, 1.0);
				rayAimingSuperFct_12Cores.loadDefaultParameter(paraRayAiming);
				rayAimingSuperFct_12Cores.loadPointsInAS();
				auto timeStart = std::chrono::high_resolution_clock::now();
				rayAimingSuperFct_12Cores.splitPointsInAsFor12Cores();
				aimedLightRays[i] = rayAimingSuperFct_12Cores.calcAimedLightRay_vec_12cores_obj();
				auto timeEnd = std::chrono::high_resolution_clock::now();
				std::chrono::duration<real> timeTotal_duration = timeEnd - timeStart;
				real timeTotal_sec = timeTotal_duration.count();
				saveTime_sec_ClassicalRayAiming_12Cores[i] = timeTotal_sec;
			}


			vectorToExport.push_back(saveTime_sec_ClassicalRayAiming_12Cores[0]); // green
			vectorToExport.push_back(saveTime_sec_ClassicalRayAiming_12Cores[1]); // blue
			vectorToExport.push_back(saveTime_sec_ClassicalRayAiming_12Cores[2]); // red
			vectorToExport.push_back(saveTime_sec_ClassicalRayAiming_12Cores[0] + saveTime_sec_ClassicalRayAiming_12Cores[1] + saveTime_sec_ClassicalRayAiming_12Cores[2]); // total time

			// check RayAiming
			SequentialRayTracing tempSeqTrace;
			std::vector<VectorStructR3> tempInterPoints;
			std::vector<VectorStructR3> saveAllInterPoints;
			for (unsigned int i = 0; i < wavelenght_vec.size(); ++i)
			{

				optSysEle.setRefractiveIndexAccordingToWavelength(wavelenght_vec[i]);
				tempOpticalSystem_LLT = optSysEle.getLLTconversion_doConversion();
				tempSeqTrace.setOpticalSystem(optSysEle);
				tempSeqTrace.setTraceToSurface(sizeOptSys);
				tempSeqTrace.seqRayTracingWithVectorOfLightRays(aimedLightRays[i]);

				tempInterPoints = tempSeqTrace.getAllInterPointsAtSurf_i_notFiltered(sizeOptSys);

				saveAllInterPoints.insert(saveAllInterPoints.end(), tempInterPoints.begin(), tempInterPoints.end());

				tempSeqTrace.clearAllTracedRays();
			}


			Spot spotCheck(saveAllInterPoints, saveAllInterPoints[0]);
			tempRMS = spotCheck.getRMS_µm();
			bool checkRMS = Math::compareTwoNumbers_tolerance(tempRMS, rms_Zemax, toleranceRMS);
			vectorToExport.push_back(checkRMS);
			workTheSystem.push_back(checkRMS);
			if (tempRoundNumber == 1)
			{
				inportExportData::exportDataToExcel_vector(location, nameSave_ClassicalRayAiming_12Cores, "ray density, number rays per wavelength, total number of rays, tolerance in X and Y, time sec green, time sec blue, time sec red, total time sec, check RMS", vectorToExport);
			}
			
			exportVector_classicalRayAiming_12Cores[tempRoundToSave].push_back(vectorToExport);

			vectorToExport.clear();
			++tempRayDensity;

			if (tempRayDensity > maxRayDensity)
			{
				checkerClassicalRayAiming_12Cores = false;
			}
		}


		// **********************
		// *** ray aiming inital rays 12 cores ***
		tempRayDensity = minRayDensity;
		std::string nameSave_RayAiming_initalRays_12Cores = "RayAiming_12Cores_initalRays";
		nameSave_RayAiming_initalRays_12Cores = nameSave_RayAiming_initalRays_12Cores + "_" + roundString;
		vectorToExport.clear();
		std::vector<real> time_sec_vec;
		std::vector<real> saveTime_sec_RayAiming_initalRays_12Cores;
		saveTime_sec_RayAiming_initalRays_12Cores.resize(wavelenght_vec.size());
		if (checkerRayAiming_initalRays_12Cores)
		{
			inportExportData::removeDateCSV(location, nameSave_RayAiming_initalRays_12Cores);
		}
		while (checkerRayAiming_initalRays_12Cores)
		{
			FillApertureStop FillAS(infosAeperStop, tempRayDensity, arms);
			int numberOfRays = FillAS.getPointsInAS().size();
			int totalNumberOfRays = FillAS.getPointsInAS().size() * wavelenght_vec.size();

			vectorToExport.push_back(tempRayDensity); // ray density
			vectorToExport.push_back(numberOfRays); // number rays per wavelength
			vectorToExport.push_back(totalNumberOfRays); // total number rays


			RayAiming_12Cores_initalRays rayA_initalRays_12Cores;
			rayA_initalRays_12Cores.loadInput(optSysEle, tempRayDensity, arms, startPoint, light, wavelenght_vec);
			rayA_initalRays_12Cores.loadDefaultParameter_initalRays(paraRayAiming);
			rayA_initalRays_12Cores.loadPointsInAS();
			rayA_initalRays_12Cores.splitPointsInAsFor12Cores();
			aimedLightRays = rayA_initalRays_12Cores.calcRayAimingInitalRays_vec_12cores_obj();
			saveTime_sec_RayAiming_initalRays_12Cores = rayA_initalRays_12Cores.getTotalTime_sec();

			vectorToExport.push_back(rayA_initalRays_12Cores.getToleranceXandY()); // tolerance in X and Y


			vectorToExport.push_back(saveTime_sec_RayAiming_initalRays_12Cores[0]); // green
			vectorToExport.push_back(saveTime_sec_RayAiming_initalRays_12Cores[1]); // blue
			vectorToExport.push_back(saveTime_sec_RayAiming_initalRays_12Cores[2]); // red
			vectorToExport.push_back(saveTime_sec_RayAiming_initalRays_12Cores[3]); // total time

			// check RayAiming
			SequentialRayTracing tempSeqTrace;
			std::vector<VectorStructR3> tempInterPoints;
			std::vector<VectorStructR3> saveAllInterPoints;
			for (unsigned int i = 0; i < wavelenght_vec.size(); ++i)
			{

				optSysEle.setRefractiveIndexAccordingToWavelength(wavelenght_vec[i]);
				tempOpticalSystem_LLT = optSysEle.getLLTconversion_doConversion();
				tempSeqTrace.setOpticalSystem(optSysEle);
				tempSeqTrace.setTraceToSurface(sizeOptSys);
				tempSeqTrace.seqRayTracingWithVectorOfLightRays(aimedLightRays[i]);

				tempInterPoints = tempSeqTrace.getAllInterPointsAtSurf_i_notFiltered(sizeOptSys);

				saveAllInterPoints.insert(saveAllInterPoints.end(), tempInterPoints.begin(), tempInterPoints.end());

				tempSeqTrace.clearAllTracedRays();
			}


			Spot spotCheck(saveAllInterPoints, saveAllInterPoints[0]);
			tempRMS = spotCheck.getRMS_µm();
			bool checkRMS = Math::compareTwoNumbers_tolerance(tempRMS, rms_Zemax, toleranceRMS);
			vectorToExport.push_back(checkRMS);
			workTheSystem.push_back(checkRMS);

			if (tempRoundNumber == 1)
			{
				inportExportData::exportDataToExcel_vector(location, nameSave_RayAiming_initalRays_12Cores, "ray density, number rays per wavelength, total number of rays, tolerance in X and Y, time sec green, time sec blue, time sec red, total time sec, check RMS", vectorToExport);
			}
			
			
			
			exportVector_RayAiming_initalRays_12Cores[tempRoundToSave].push_back(vectorToExport);

			vectorToExport.clear();
			++tempRayDensity;

			if (tempRayDensity > maxRayDensity)
			{
				checkerRayAiming_initalRays_12Cores = false;
			}


		}

		++tempRoundNumber;
		++tempRoundToSave;
		if (tempRoundNumber > maxRounds)
		{
			checkRound = false;
		}

		if (initalCheckerClassicRayAiming)
		{
			checkerClassicRayAiming = true;
		}
		if (initalCheckerRayAimingInitalRay)
		{
			checkerRayAimingInitalRay = true;
		}
		if (initalCheckerClassicalRayAiming_12Cores)
		{
			checkerClassicalRayAiming_12Cores = true;
		}
		if (initalCheckerRayAiming_initalRays_12Cores)
		{
			checkerRayAiming_initalRays_12Cores = true;
		}

		tempRayDensity = minRayDensity;
		aimedLightRays.clear();
		aimedLightRays.resize(wavelenght_vec.size());
	

	}

	// middle all data to export
	real tempVal = 0.0;
	real totalValue = 0.0;
	real valueMiddle = 0.0;
	std::vector<real> vectorToExport;
	std::vector<std::vector<real>> vectorToExportTotal;

	// middle classical ray aiming
	if (initalCheckerClassicRayAiming)
	{
		for (unsigned int interation = 0; interation < exportVector_classicalRayAiming[0].size(); ++interation)
		{
			for (unsigned int value = 0; value < exportVector_classicalRayAiming[0][0].size(); ++value)
			{
				for (unsigned int round = 0; round < exportVector_classicalRayAiming.size(); ++round)
				{
					// debug
					// std::cout << "interation: " << interation << std::endl;
					// std::cout << "value: " << value << std::endl;
					// std::cout << "round: " << round << std::endl;

					tempVal = exportVector_classicalRayAiming[round][interation][value];
					totalValue = totalValue + tempVal;

				}

				valueMiddle = totalValue / (real)maxRounds;
				// std::cout << "valueMiddle: " << valueMiddle << std::endl; valueMiddle;

				vectorToExport.push_back(valueMiddle);
				totalValue = 0.0;
			}
			vectorToExportTotal.push_back(vectorToExport);
			vectorToExport.clear();
		}


		std::string middle_classicalRayAiming = "classicalRayAiming_middle";
		inportExportData::removeDateCSV(location, middle_classicalRayAiming);
		for (unsigned int i = 0; i < vectorToExportTotal.size(); ++i)
		{
			inportExportData::exportDataToExcel_vector(location, middle_classicalRayAiming, "ray density, number rays per wavelength, total number of rays, tolerance in X and Y, time sec green, time sec blue, time sec red, total time sec, check RMS", vectorToExportTotal[i]);
		}
			
	}
	
	tempVal = 0.0;
	totalValue = 0.0;
	valueMiddle = 0.0;
	vectorToExport.clear();
	vectorToExportTotal.clear();
	
	// middle ray aiming inital rays
	if (initalCheckerRayAimingInitalRay)
	{
		for (unsigned int interation = 0; interation < exportVector_RayAiming_initalRays[0].size(); ++interation)
		{
			for (unsigned int value = 0; value < exportVector_RayAiming_initalRays[0][0].size(); ++value)
			{
				for (unsigned int round = 0; round < exportVector_RayAiming_initalRays.size(); ++round)
				{
					// debug
					//std::cout << "interation: " << interation << std::endl;
					//std::cout << "value: " << value << std::endl;
					//std::cout << "round: " << round << std::endl;

					tempVal = exportVector_RayAiming_initalRays[round][interation][value];
					totalValue = totalValue + tempVal;

				}

				valueMiddle = totalValue / (real)maxRounds;
				//std::cout << "valueMiddle: " << valueMiddle << std::endl; valueMiddle;

				vectorToExport.push_back(valueMiddle);
				totalValue = 0.0;
			}
			vectorToExportTotal.push_back(vectorToExport);
			vectorToExport.clear();
		}


		std::string middle_RayAiming_initalRays = "RayAiming_initalRays_middle";
		inportExportData::removeDateCSV(location, middle_RayAiming_initalRays);
		for (unsigned int i = 0; i < vectorToExportTotal.size(); ++i)
		{
			inportExportData::exportDataToExcel_vector(location, middle_RayAiming_initalRays, "ray density, number rays per wavelength, total number of rays, tolerance in X and Y, time sec green, time sec blue, time sec red, total time sec, check RMS", vectorToExportTotal[i]);
		}

	}
	
	tempVal = 0.0;
	totalValue = 0.0;
	valueMiddle = 0.0;
	vectorToExport.clear();
	vectorToExportTotal.clear();

	// middle calssical ray aiming 12 Cores
	if (initalCheckerClassicalRayAiming_12Cores)
	{
		for (unsigned int interation = 0; interation < exportVector_classicalRayAiming_12Cores[0].size(); ++interation)
		{
			for (unsigned int value = 0; value < exportVector_classicalRayAiming_12Cores[0][0].size(); ++value)
			{
				for (unsigned int round = 0; round < exportVector_classicalRayAiming_12Cores.size(); ++round)
				{
					// debug
					//std::cout << "interation: " << interation << std::endl;
					//std::cout << "value: " << value << std::endl;
					//std::cout << "round: " << round << std::endl;

					tempVal = exportVector_classicalRayAiming_12Cores[round][interation][value];
					totalValue = totalValue + tempVal;

				}

				valueMiddle = totalValue / (real)maxRounds;
				//std::cout << "valueMiddle: " << valueMiddle << std::endl; valueMiddle;

				vectorToExport.push_back(valueMiddle);
				totalValue = 0.0;
			}
			vectorToExportTotal.push_back(vectorToExport);
			vectorToExport.clear();
		}


		std::string middle_ClassicalRayAiming_12Cores = "ClassicalRayAiming_12Cores_middle";
		inportExportData::removeDateCSV(location, middle_ClassicalRayAiming_12Cores);
		for (unsigned int i = 0; i < vectorToExportTotal.size(); ++i)
		{
			inportExportData::exportDataToExcel_vector(location, middle_ClassicalRayAiming_12Cores, "ray density, number rays per wavelength, total number of rays, tolerance in X and Y, time sec green, time sec blue, time sec red, total time sec, check RMS", vectorToExportTotal[i]);
		}

	}

	tempVal = 0.0;
	totalValue = 0.0;
	valueMiddle = 0.0;
	vectorToExport.clear();
	vectorToExportTotal.clear();

	// middle ray aiming inital rays 12 Cores
	if (initalCheckerRayAiming_initalRays_12Cores)
	{
		for (unsigned int interation = 0; interation < exportVector_RayAiming_initalRays_12Cores[0].size(); ++interation)
		{
			for (unsigned int value = 0; value < exportVector_RayAiming_initalRays_12Cores[0][0].size(); ++value)
			{
				for (unsigned int round = 0; round < exportVector_RayAiming_initalRays_12Cores.size(); ++round)
				{
					// debug
					//std::cout << "interation: " << interation << std::endl;
					//std::cout << "value: " << value << std::endl;
					//std::cout << "round: " << round << std::endl;

					tempVal = exportVector_RayAiming_initalRays_12Cores[round][interation][value];
					totalValue = totalValue + tempVal;

				}

				valueMiddle = totalValue / (real)maxRounds;
				//std::cout << "valueMiddle: " << valueMiddle << std::endl; valueMiddle;

				vectorToExport.push_back(valueMiddle);
				totalValue = 0.0;
			}
			vectorToExportTotal.push_back(vectorToExport);
			vectorToExport.clear();
		}


		std::string middle_RayAiming_initalRays_12Cores = "RayAiming_initalRays_12Cores_middle";
		inportExportData::removeDateCSV(location, middle_RayAiming_initalRays_12Cores);
		for (unsigned int i = 0; i < vectorToExportTotal.size(); ++i)
		{
			inportExportData::exportDataToExcel_vector(location, middle_RayAiming_initalRays_12Cores, "ray density, number rays per wavelength, total number of rays, tolerance in X and Y, time sec green, time sec blue, time sec red, total time sec, check RMS", vectorToExportTotal[i]);
		}

	}

	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}


// benchE1
bool BenchRayAiming::benchRayAimingE0_()
{

	std::string nameCSV_middle_bestAimedLightRays = "middle best aimed light rays";
	std::string nameCSV_middle_accurencyRayAiming = "middle accurency ray aiming";
	bool calcBestRMS = true;
	bool calcAccurecncyRayAiming = true;
	real wavelength = 550.0;

	int tempRoundNumber = 0;
	int maxRounds = 10;
	
	real startToleranceX_Y = 0.001;
	real minToleranceX_Y = 0.000001;
	real steps = 60.0;
	real deltaToleranceX_Y = (startToleranceX_Y - minToleranceX_Y) / steps;
	real absolutBestTolerance_X_Y = minToleranceX_Y / 100.0;

	real rayDensity = 6;
	real arms = 8;

	std::vector<std::vector<real>> exportVector_BestAimedLightRay;
	std::vector<std::vector<std::vector<real>>> exportVector_AccurencyRayAiming;
	exportVector_BestAimedLightRay.resize(maxRounds);
	exportVector_AccurencyRayAiming.resize(maxRounds);


	//*** standard ***//
	std::vector<bool> workTheSystem;
	std::string location = "../benchmark/benchRayAiming/E0_";
	std::vector<real> vectorToExport;
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;
	glass glasses;
	glasses.loadGlassCatalog_Schott();
	std::vector<real> wavelenght_vec;
	wavelenght_vec.push_back(550.0);
	wavelenght_vec.push_back(400.0);
	wavelenght_vec.push_back(700.0);
	VectorStructR3 startPoint = { 1.0,2.0,0.0 };

	Light_LLT light = oftenUse::getDefaultLight();
	//*** ------  ***//

	real tolerance = 0.2;
	inportExportData::removeDateCSV(location, nameCSV_middle_bestAimedLightRays);

	// build the optical system
	SphericalElement S0(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S1(/*radius*/ 70.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSF5_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF5_S1());

	SphericalElement S3(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF14_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement S5(/*radius*/ 30.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF14_S1());

	ApertureStopElement S6(/* semi height*/4.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());

	SphericalElement S7(/*radius*/ 60.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF57_S1());
	SphericalElement S8(/*radius*/ 50.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSF6_S1(), /*refractive index B*/glasses.getSF57_S1());
	SphericalElement S9(/*radius*/ 35.0, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNSF6_S1(), /*refractive index B*/glasses.getAir());

	PlanElement S10(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,110.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();
	surfacePtr S7_ptr = S7.clone();
	surfacePtr S8_ptr = S8.clone();
	surfacePtr S9_ptr = S9.clone();
	surfacePtr S10_ptr = S10.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr, S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr };
	std::vector<interaction_ptr> interactions_ptr{ refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), doNothing.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSysEle(opticalSystem_ptr, interactions_ptr);
	int posLastSurface = optSysEle.getPosAndElement().size() - 1;

	// test the system
	real rms_Zemax{ 434.867 };
	//bool testStart = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSysEle, startPoint, wavelenght_vec, rms_Zemax, tolerance, compareTOM_Zemax::comEqual);
	//workTheSystem.push_back(testStart);

	real tolerance_XandY = 0.0001;
	real startPointFactor = 1.0;
	int maxLoopsTraceToLastSurface = 5;
	int maxInterationsRayAiming = 50;
	real factor_inf = 0.1;
	real factor_obj = 0.1;
	bool rubustRayAiming = true;
	real variancePercentRobustRA = 5.0;
	int maxStayCounter = 2;
	real increaserFactorTimes = 10.0;
	real tolerance_XandYforARealLightRay = 0.1;
	real factorStartHeight_inf = 0.5;
	real factorStartHeight_obj = 0.5;
	real maxInterationRobustRayAiming = 10;
	int maxRayThatNotBeAimable = 5;
	real infinity_neg = -1000000.0;


	defaultRayAimingStruct paraRayAiming;
	paraRayAiming.setTolerance_XandY(tolerance_XandY);
	paraRayAiming.setStartPointFactor(startPointFactor);
	paraRayAiming.setMaxLoopsTraceToLastSurface(maxLoopsTraceToLastSurface);
	paraRayAiming.setMaxIterationsRayAiming(maxInterationsRayAiming);
	paraRayAiming.setFactor_inf(factor_inf);
	paraRayAiming.setFactor_obj(factor_obj);
	if (rubustRayAiming)
	{
		paraRayAiming.turn_On_RobustRayAiming();
	}
	else
	{
		paraRayAiming.turn_Off_RobustRayAiming();
	}
	paraRayAiming.setVariancePercentRRA(variancePercentRobustRA);
	paraRayAiming.setMaxStayCounter(maxStayCounter);
	paraRayAiming.setIncreaserFactorTimes(increaserFactorTimes);
	paraRayAiming.setTolerancceForRealLightRay(tolerance_XandYforARealLightRay);
	paraRayAiming.setFactorStartHeight_inf(factorStartHeight_inf);
	paraRayAiming.setFactorStartHeight_obj(factorStartHeight_obj);
	paraRayAiming.setMaxInterationRobustRayAiming(maxInterationRobustRayAiming);
	paraRayAiming.setMaxRaysThatNotBeAimable(maxRayThatNotBeAimable);
	paraRayAiming.setInfinity_neg(infinity_neg);
	paraRayAiming.turn_ON_GlobalStopIfToManyRaysAreNotAimed();
	paraRayAiming.setRecodTimeInitalRay(true);

	bool checkRound_bestRMS = true;
	int tempRoundToSave = 0;
	

	// calc best rms
	if (calcBestRMS)
	{
	
		while (checkRound_bestRMS)
		{

			
			

			infosAS infosAeperStop = optSysEle.getInfoAS();
			paraRayAiming.setTolerance_XandY(absolutBestTolerance_X_Y);
	
			FillApertureStop FillAS(infosAeperStop, rayDensity, arms);

			RayAiming rayA_classic_best;
			rayA_classic_best.setLoadImportantDefaulParameterRayAiming(false);
			rayA_classic_best.setDefaultParameters(paraRayAiming);
					
			light.setWavelength(wavelength);
			optSysEle.setRefractiveIndexAccordingToWavelength(wavelength);
			optSysEle.convertSurfacesToLLT();

			rayA_classic_best.setOpticalSystem_LLT(optSysEle.getOptSys_LLT_buildSystem());
			rayA_classic_best.loadImportantInfosForRayAiming();
			rayA_classic_best.turn_On_RobustRayAiming();

			auto timeStart = std::chrono::high_resolution_clock::now();
			std::vector<LightRayStruct> tempLightRay_vec = rayA_classic_best.rayAimingMany_obj(FillAS.getPointsInAS(), startPoint, light, 1.0);
			auto timeEnd = std::chrono::high_resolution_clock::now();
			std::chrono::duration<real> timeTotal_duration = timeEnd - timeStart;
			real timeTotal_sec = timeTotal_duration.count();

			vectorToExport.push_back(timeTotal_sec); // time in sec
			vectorToExport.push_back(rayA_classic_best.getTolerance_XandY()); // tolerance X and >
			vectorToExport.push_back(rayDensity); // ray density
			vectorToExport.push_back(tempLightRay_vec.size()); // number of rays

			
			SequentialRayTracing seqTrace;
			seqTrace.setOpticalSystem(optSysEle);
			seqTrace.setTraceToSurface(posLastSurface);
			seqTrace.seqRayTracingWithVectorOfLightRays(tempLightRay_vec);

			std::vector<VectorStructR3> tempInterPoints = seqTrace.getAllInterPointsAtSurf_i_notFiltered(posLastSurface);

			Spot spotBest(tempInterPoints, tempInterPoints[0]);
			real bestRMS_µm = spotBest.getRMS_µm();
			vectorToExport.push_back(bestRMS_µm); // number rays

			exportVector_BestAimedLightRay[tempRoundNumber] = vectorToExport;
			++tempRoundNumber;

			if (tempRoundNumber == maxRounds)
			{
				checkRound_bestRMS = false;
			}

			vectorToExport.clear();
		}


		// middle
		std::vector<real> middleVec_bestRMS;
		middleVec_bestRMS.resize(exportVector_BestAimedLightRay[0].size());
		real tempVal = 0.0;
		real tempAllVal = 0.0;
		real tempMiddleVal = 0.0;
		for (unsigned int k = 0; k < exportVector_BestAimedLightRay[0].size(); ++k)
		{
			for (unsigned int i = 0; i < exportVector_BestAimedLightRay.size(); ++i)
			{
				tempVal = exportVector_BestAimedLightRay[i][k];
				tempAllVal = tempAllVal + tempVal;
			}

			tempMiddleVal = tempAllVal / maxRounds;
			middleVec_bestRMS[k] = tempMiddleVal;
			
			tempAllVal = 0.0;
		}


		inportExportData::exportDataToExcel_vector(location, nameCSV_middle_bestAimedLightRays, "time in sec, tolerance in mm, ray density, number of rays, rms spot", middleVec_bestRMS);
	}
	
	bool checkRound_accurency = true;
	bool checkMinToleranceXandY = true;
	tempRoundToSave = 0;

	real tempToleranceX_Y = startToleranceX_Y;
	bool checker = true;
	int posToSave = 0;
	// ***
	if (calcAccurecncyRayAiming)
	{
		while (checkMinToleranceXandY)
		{
			while (checkRound_accurency)
			{
				infosAS infosAeperStop = optSysEle.getInfoAS();
				paraRayAiming.setTolerance_XandY(tempToleranceX_Y);

				FillApertureStop FillAS(infosAeperStop, rayDensity, arms);

				RayAiming rayA_classic;
				rayA_classic.setLoadImportantDefaulParameterRayAiming(false);
				rayA_classic.setDefaultParameters(paraRayAiming);

				light.setWavelength(wavelength);
				optSysEle.setRefractiveIndexAccordingToWavelength(wavelength);
				optSysEle.convertSurfacesToLLT();

				rayA_classic.setOpticalSystem_LLT(optSysEle.getOptSys_LLT_buildSystem());
				rayA_classic.loadImportantInfosForRayAiming();
				rayA_classic.turn_On_RobustRayAiming();

				auto timeStart = std::chrono::high_resolution_clock::now();
				std::vector<LightRayStruct> tempLightRay_vec = rayA_classic.rayAimingMany_obj(FillAS.getPointsInAS(), startPoint, light, 1.0);
				auto timeEnd = std::chrono::high_resolution_clock::now();
				std::chrono::duration<real> timeTotal_duration = timeEnd - timeStart;
				real timeTotal_sec = timeTotal_duration.count();

				vectorToExport.push_back(timeTotal_sec); // time in sec
				vectorToExport.push_back(rayA_classic.getTolerance_XandY()); // tolerance X and >
				vectorToExport.push_back(rayDensity); // ray density
				vectorToExport.push_back(tempLightRay_vec.size()); // number of rays


				SequentialRayTracing seqTrace;
				seqTrace.setOpticalSystem(optSysEle);
				seqTrace.setTraceToSurface(posLastSurface);
				seqTrace.seqRayTracingWithVectorOfLightRays(tempLightRay_vec);

				std::vector<VectorStructR3> tempInterPoints = seqTrace.getAllInterPointsAtSurf_i_notFiltered(posLastSurface);

				Spot spotBest(tempInterPoints, tempInterPoints[0]);
				real bestRMS_µm = spotBest.getRMS_µm();
				vectorToExport.push_back(bestRMS_µm); // number rays

				exportVector_AccurencyRayAiming[posToSave].push_back(vectorToExport);
			
				++posToSave;
				if (posToSave == maxRounds)
				{
					checkRound_accurency = false;
				}

				
				vectorToExport.clear();
			}

			tempToleranceX_Y = tempToleranceX_Y - deltaToleranceX_Y;
			posToSave = 0;
			checkRound_accurency = true;

			if (tempToleranceX_Y < minToleranceX_Y)
			{
				checkMinToleranceXandY = false;
			}
		}


		// middle
		real tempVal = 0.0;
		real totalValue = 0.0;
		real valueMiddle = 0.0;
		std::vector<std::vector<real>> vectorToExportTotal{};

		for (unsigned int interation = 0; interation < exportVector_AccurencyRayAiming[0].size(); ++interation)
		{
			for (unsigned int value = 0; value < exportVector_AccurencyRayAiming[0][0].size(); ++value)
			{
				for (unsigned int round = 0; round < exportVector_AccurencyRayAiming.size(); ++round)
				{
					// debug
					// std::cout << "interation: " << interation << std::endl;
					// std::cout << "value: " << value << std::endl;
					// std::cout << "round: " << round << std::endl;

					tempVal = exportVector_AccurencyRayAiming[round][interation][value];
					totalValue = totalValue + tempVal;

				}

				valueMiddle = totalValue / (real)maxRounds;
				// std::cout << "valueMiddle: " << valueMiddle << std::endl; valueMiddle;

				vectorToExport.push_back(valueMiddle);
				totalValue = 0.0;
			}
			vectorToExportTotal.push_back(vectorToExport);
			vectorToExport.clear();
		}


		inportExportData::removeDateCSV(location, nameCSV_middle_accurencyRayAiming);
		for (unsigned int i = 0; i < vectorToExportTotal.size(); ++i)
		{
			inportExportData::exportDataToExcel_vector(location, nameCSV_middle_accurencyRayAiming, "time in sec, tolerance in mm, ray density, number of rays, rms spot", vectorToExportTotal[i]);
		}

	}


	bool returnChecker = Math::checkTrueOfVectorElements(workTheSystem);
	return returnChecker;
}