#include "benchRayTracing.h"

// element surfaces
#include "..\..\SurfaceElements\ApertureStopElement.h"
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\PlanElement.h"

// interactions
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"

// glass catalogue
#include "..\..\Glasses\Glasses.h"

// often use
#include "..\..\oftenUseNamespace\oftenUseNamespace.h"

// ray aiming
#include "..\..\RayAiming\RayAiming.h"

#include "..\..\Inport_Export_Data\Inport_Export_Data.h"

#include <iomanip>
#include <iostream>
#include <fstream>

BenchRayTracing::BenchRayTracing() {};
BenchRayTracing::~BenchRayTracing() {};


bool BenchRayTracing::benchmarkRayTracing_superFct()
{
	std::vector<bool> test_vec;

	//// E0
	//bool benchE0 = testSpeedRayTracing_E0();
	//test_vec.push_back(benchE0);
	// E1
	bool benchE1 = bechmarklRayTracing_E1();
	test_vec.push_back(benchE1);

	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

bool BenchRayTracing::benchmarkRayTracing_E0()
{
	std::vector<bool> test_vec;
	

	//  wave
	real wave587 = 587.5618;
	real wave486 = 486.1327;
	real wave656 = 656.2725;
	std::vector<real> wavelength_vec = { wave587 , wave486, wave656 };

	Light_LLT Light587;
	Light587.setWavelength(587.5618);
	Light587.setIntensity(1.0);

	Light_LLT Light486;
	Light486.setWavelength(486.1327);
	Light486.setIntensity(1.0);

	Light_LLT Light656;
	Light656.setWavelength(656.2725);
	Light656.setIntensity(1.0);

	std::vector<Light_LLT> lightVec{ Light587, Light486, Light656 };

	// field
	VectorStructR3 field0 = { 0.0,0.0,0.0 };
	VectorStructR3 field2 = { 0.0,3.0,0.0 };
	VectorStructR3 field4 = { 0.0,6.0,0.0 };

	std::vector<VectorStructR3> fields_vec036 = { field0, field2, field4 };

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interactionPtr;

	DoNothingInteraction_LLT doNothing;
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	// surfaces
	ApertureStopElement AperStop0(/* semi height*/5.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1(/*radius*/ 30.0, /*semi height*/ 15.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement Sphere2(/*radius*/ 40.0, /*semi height*/ 15.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getNBK7_S1(), /*refractive index B*/glasses.getNSF14_S1());
	SphericalElement Sphere3(/*radius*/ 30.0, /*semi height*/ 15.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF14_S1());
	PlanElement Plan4(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,90.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());
	
	std::vector<surfacePtr> opticalSystemP0_ptr{ AperStop0.clone(), Sphere1.clone(), Sphere2.clone(), Sphere3.clone(), Plan4.clone() };
	std::vector<interactionPtr> interactionsP0_ptr{ doNothing.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };
	
	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystemP0_ptr, interactionsP0_ptr);
	
	// test single ray
	optSystemElement.setRefractiveIndexAccordingToWavelength(Light587.getWavelength());
	bool checkSingleRay = oftenUse::checkRayTracing({ 0.0,0.0,0.0 }, { 0.0,5.0,30.0 }, { 0.0,2.0052209665,90.0 }, optSystemElement.getLLTconversion_doConversion(), 4, 0.01);
	test_vec.push_back(checkSingleRay);

	// test the system
	std::vector<real> rms_Zemax{1649.47,1582.74,1417.80 };
	bool test_E0 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, fields_vec036, wavelength_vec, rms_Zemax, 1.0, compareTOM_Zemax::comEqual);
	test_vec.push_back(test_E0);

	//FillApertureStop fillAperturStop(/*start point rays*/{ 0.0,0.0,0.0 },/*semi height of aperture stop*/ 5.0,/*point of aperture stop*/{ 0.0,0.0,30.0 },/*direction of aperture stop*/{ 0.0,0.0,1.0 }, /*rings*/ 6,/*arms*/ 8,/*refractive index*/ 1.0,/*light*/ Light_LLT Light) :

	unsigned int startRayDensity = 3;
	unsigned int endRayDensity = 60;
	unsigned int deltaRayDensity = 1;

	std::string location = "../benchmark/benchRayTracing/E0/";
	std::string timeRayTrace = "benchRayTracing";

	std::vector<real> vectorToExport_rayDensity;

	// delete all saved datas
	std::string holeFile = "../benchmark/benachRayTracing/E0/benchRayTracing.csv";
	std::ofstream ofs;
	ofs.open(holeFile, std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	std::vector<real> checkRD3{ 1688.39, 1621.44, 1463.51 };
	std::vector<real> checkRD4{ 1670.53, 1603.64, 1442.14 };
	std::vector<real> checkRD5{ 1658.35, 1591.53, 1427.93 };
	std::vector<real> checkRD6{ 1649.47, 1582.74, 1417.80 };
	std::vector<real> checkRD7{ 1642.72, 1576.06, 1410.22 };
	std::vector<real> checkRD8{ 1637.40, 1570.82, 1404.33 };
	std::vector<real> checkRD9{ 1633.12, 1566.60, 1399.62 };
	std::vector<real> checkRD10{1629.59, 1563.13, 1395.78 };

	std::vector<std::vector<real>> checkAllSpots = { checkRD3,checkRD4,checkRD5,checkRD6,checkRD7,checkRD8,checkRD9,checkRD10 };
	unsigned int sizeChckAllSpots = checkAllSpots.size();
	unsigned int counter = 0;
	real tolerance = 0.1;

	std::vector<real> timePerRay_seconds_vec;

	for (startRayDensity; startRayDensity <= endRayDensity; startRayDensity = startRayDensity + deltaRayDensity)
	{
		vectorToExport_rayDensity.clear();
		vectorToExport_rayDensity.push_back(startRayDensity);
	
		//optA
		auto timeStart_optA = std::chrono::high_resolution_clock::now();
		SequentialRayTracing seqTrace_optA(/*optical system element*/ optSystemElement, /*start point lightRay*/{ 0.0,0.0,0.0 }, /*rings*/ startRayDensity, /*arms*/ 8, /*refractive index*/ 1.0, lightVec);
		auto timeEnd_optA = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> timeTotal_OptA = timeEnd_optA - timeStart_optA;
		auto timeTotal_optA_min = timeTotal_OptA.count() / 60.0;
	
		//field1
		auto timeStart_field1 = std::chrono::high_resolution_clock::now();
		SequentialRayTracing seqTrace_field1(/*optical system element*/ optSystemElement, /*start point lightRay*/{ 0.0,3.0,0.0 }, /*rings*/ startRayDensity, /*arms*/ 8, /*refractive index*/ 1.0, lightVec);
		auto timeEnd_field1 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> timeTotal_Field1 = timeEnd_field1 - timeStart_field1;
		auto timeTotal_Field1_min = timeTotal_Field1.count() / 60.0;
	
		//field2
		auto timeStart_field2 = std::chrono::high_resolution_clock::now();
		SequentialRayTracing seqTrace_field2(/*optical system element*/ optSystemElement, /*start point lightRay*/{ 0.0,6.0,0.0 }, /*rings*/ startRayDensity, /*arms*/ 8, /*refractive index*/ 1.0, lightVec);
		auto timeEnd_field2 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> timeTotal_Field2 = timeEnd_field2 - timeStart_field2;
		auto timeTotal_Field2_min = timeTotal_Field2.count() / 60.0;
	
	
		unsigned int totalNumRay = seqTrace_optA.getStartPoints().size() * lightVec.size() * fields_vec036.size();
		vectorToExport_rayDensity.push_back(totalNumRay);
		vectorToExport_rayDensity.push_back(timeTotal_optA_min);
		vectorToExport_rayDensity.push_back(timeTotal_Field1_min);
		vectorToExport_rayDensity.push_back(timeTotal_Field2_min);
	
		real totalTime = timeTotal_optA_min + timeTotal_Field1_min + timeTotal_Field2_min;
		vectorToExport_rayDensity.push_back(totalTime);
	
		real timePerRay_min = totalTime / totalNumRay;
		real timerPerRay_seconds = timePerRay_min * 60.0;
		timePerRay_seconds_vec.push_back(timerPerRay_seconds);
		vectorToExport_rayDensity.push_back(timePerRay_min);
	
		std::cout << "current ray density: " << startRayDensity << std::endl;
		std::cout << "time per ray in min: " << timePerRay_min << std::endl;
		std::cout << "time per ray in seconds: " << timePerRay_min * 60.0 << std::endl;
	
		if (counter < sizeChckAllSpots)
		{
			Spot spotOptA(/*intersection points*/ seqTrace_optA.getAllInterPointsAtSurface_i_filtered(4),/*reference point*/seqTrace_optA.getAllInterPointsAtSurface_i_filtered(4)[0]);
			real spotOA = spotOptA.getRMS_µm();

			Spot spotF1(/*intersection points*/ seqTrace_field1.getAllInterPointsAtSurface_i_filtered(4),/*reference point*/seqTrace_field1.getAllInterPointsAtSurface_i_filtered(4)[0]);
			real spotRMSF1 = spotF1.getRMS_µm();

			Spot spotF2(/*intersection points*/ seqTrace_field2.getAllInterPointsAtSurface_i_filtered(4),/*reference point*/seqTrace_field2.getAllInterPointsAtSurface_i_filtered(4)[0]);
			real spotRMSF2 = spotF2.getRMS_µm();

			// check the rms values
			bool checkRMS_optA = Math::compareTwoNumbers_tolerance(spotOA, checkAllSpots[counter][0], tolerance);
			bool checkRMS_F1 = Math::compareTwoNumbers_tolerance(spotRMSF1, checkAllSpots[counter][1], tolerance);
			bool checkRMS_F2 = Math::compareTwoNumbers_tolerance(spotRMSF2, checkAllSpots[counter][2], tolerance);

			test_vec.push_back(checkRMS_optA);
			test_vec.push_back(checkRMS_F1);
			test_vec.push_back(checkRMS_F2);

			++counter;

		}



		inportExportData::exportDataToExcel_vector(location, timeRayTrace, "ray density, number ray, time optA, time field2, time field 4, total time, timePerRay checker", vectorToExport_rayDensity);
	
	}
	

	// check if time per ray in seconds is less the given boundery
	//*** min time per ray in seconds
	real minTimePerRay_seconds = 7e-6;
	//***
	bool benchRayTrac = oftenUse::checkAverageOfVecValLessThan(timePerRay_seconds_vec, minTimePerRay_seconds);
	test_vec.push_back(benchRayTrac);
	//***

	bool checker = Math::checkTrueOfVectorElements(test_vec);
	return checker;
}

// E1
bool BenchRayTracing::bechmarklRayTracing_E1()
{
	std::vector<bool> test_vec_total;

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interactionPtr;
	DoNothingInteraction_LLT doNothing;
	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	glass glasses;
	glasses.loadGlassCatalog_Schott();

	std::string location = "../benchmark/benchRayTracing/E1/";
	std::string timeRayTraceAndRMS = "benchRayTracingAndRMS";
	inportExportData::removeDateCSV(location, timeRayTraceAndRMS);

	// build the optical system
	// *************************************************************
	// surfaces
	ApertureStopElement S0(/* semi height*/2.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement S1(/*radius*/ 18.525, /*semi height*/	10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/	{0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 20.0, /*semi height*/	10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/	{0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF5_S1(), /*refractive index B*/glasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 25.0, /*semi height*/	10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/	{0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());

	SphericalElement S4(/*radius*/ 19.287, /*semi height*/	10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/	{0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 50.0, /*semi height*/	10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/	{0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNBAF10_S1(), /*refractive index B*/glasses.getNBASF2_S1());
	SphericalElement S6(/*radius*/ 50.0, /*semi height*/	10.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/	{0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNBASF2_S1(), /*refractive index B*/glasses.getAir());

	SphericalElement S7(/*radius*/ 20.0, /*semi height*/	10.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/	{0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNF2_S1());
	SphericalElement S8(/*radius*/ 15.0, /*semi height*/	10.0, /*point*/{ 0.0,0.0,90.0 }, /*direction*/	{0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNKF9_S1(), /*refractive index B*/glasses.getNF2_S1());
	SphericalElement S9(/*radius*/ 20.0, /*semi height*/	10.0, /*point*/{ 0.0,0.0,100.0 },/*direction*/	{0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNKF9_S1());

	SphericalElement S10(/*radius*/ 37.802, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,110.0 },/*direction*/	{0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAF34_S1());
	SphericalElement S11(/*radius*/ 60.0, /*semi height*/	10.0, /*point*/{ 0.0,0.0,120.0 },/*direction*/	{0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNLAF34_S1(), /*refractive index B*/glasses.getNLAK21_S1());
	SphericalElement S12(/*radius*/ 30.0, /*semi height*/	10.0, /*point*/{ 0.0,0.0,130.0 },/*direction*/	{0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLAK21_S1());

	SphericalElement S13(/*radius*/ 20.338, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,140.0 },/*direction*/	{0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNLASF45_S1());
	SphericalElement S14(/*radius*/ 30.0, /*semi height*/	10.0, /*point*/{ 0.0,0.0,150.0 },/*direction*/	{0.0,0.0, 1.0 }, /*refractive index A*/ glasses.getNLASF45_S1(), /*refractive index B*/glasses.getNSF1_S1());
	SphericalElement S15(/*radius*/ 30.0, /*semi height*/	10.0, /*point*/{ 0.0,0.0,160.0 },/*direction*/	{0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getNSF1_S1());

	PlanElement S16(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,170.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

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
	surfacePtr S11_ptr = S11.clone();
	surfacePtr S12_ptr = S12.clone();
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();
	surfacePtr S15_ptr = S15.clone();
	surfacePtr S16_ptr = S16.clone();

	std::vector<surfacePtr> opticalSystemE2_ptr{ S0_ptr,S1_ptr,S2_ptr,S3_ptr,S4_ptr,S5_ptr,S6_ptr,S7_ptr,S8_ptr,S9_ptr,S10_ptr,S11_ptr,S12_ptr,S13_ptr,S14_ptr,S15_ptr,S16_ptr };
	std::vector<interactionPtr> interactionsE2_ptr{ doNothing.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),absorb.clone() };
	OpticalSystemElement optSystemElement(opticalSystemE2_ptr, interactionsE2_ptr);
	// *************************************************************
	// test the system
	std::vector<real> rms_Zemax{ 172.948, 294.867, 648.013 };
	real wavelength = 550.0;
	std::vector<VectorStructR3> fields123_vec = { {0.0,0.0,0.0}, {0.0,1.0,0.0}, {0.0,2.0,0.0} };
	bool test_E1 = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, fields123_vec, wavelength, rms_Zemax, 1.0, compareTOM_Zemax::comEqual);
	test_vec_total.push_back(test_E1);
	// *************************************************************
	// calculate the time per ray
	unsigned int startRayDensity = 3;
	unsigned int tempRayDensity = startRayDensity;
	unsigned int endRayDensity = 60;
	unsigned int deltaRayDensity = 1;
	std::vector<std::vector<real>> vectorToExport_rayDensity;
	std::vector<real> vectorToExport_rayDensity_middle;
	Light_LLT light;
	light = oftenUse::getDefaultLight();
	light.setWavelength(wavelength);

	unsigned int maxInterations = 10;
	unsigned int startInteration = 0;
	unsigned int tempIteration;

	std::vector<VectorStructR3> allInterPoints_optA;
	std::vector<VectorStructR3> allInterPoints_field1;
	std::vector<VectorStructR3> allInterPoints_field2;

	bool firstInteration;
	vectorToExport_rayDensity.resize(maxInterations);
	real toleranceRMS = 100.0;
	real numberSurfaces = 15.0;
	for (startRayDensity; tempRayDensity <= endRayDensity; ++tempRayDensity)
	{


		tempIteration = startInteration;
		firstInteration = true;
		for (tempIteration; tempIteration < maxInterations; ++tempIteration)
		{
			

			//optA
			auto timeStart_optA = std::chrono::high_resolution_clock::now();
			SequentialRayTracing seqTrace_optA(/*optical system element*/ optSystemElement, /*start point lightRay*/ fields123_vec[0], /*rings*/ tempRayDensity, /*arms*/ 8, /*refractive index*/ 1.0, light);
			auto timeEnd_optA = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> timeTotal_OptA_sec = timeEnd_optA - timeStart_optA;
			real timeTotal_optA_ms = timeTotal_OptA_sec.count() * 1000.0;

			//field1
			auto timeStart_field1 = std::chrono::high_resolution_clock::now();
			SequentialRayTracing seqTrace_field1(/*optical system element*/ optSystemElement, /*start point lightRay*/ fields123_vec[1], /*rings*/ tempRayDensity, /*arms*/ 8, /*refractive index*/ 1.0, light);
			auto timeEnd_field1 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> timeTotal_Field1_sec = timeEnd_field1 - timeStart_field1;
			real timeTotal_Field1_ms = timeTotal_Field1_sec.count() * 1000.0;

			//field2
			auto timeStart_field2 = std::chrono::high_resolution_clock::now();
			SequentialRayTracing seqTrace_field2(/*optical system element*/ optSystemElement, /*start point lightRay*/ fields123_vec[2], /*rings*/ tempRayDensity, /*arms*/ 8, /*refractive index*/ 1.0, light);
			auto timeEnd_field2 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> timeTotal_Field2_sec = timeEnd_field2 - timeStart_field2;
			real timeTotal_Field2_ms = timeTotal_Field2_sec.count() * 1000.0;

			if (firstInteration)
			{
				allInterPoints_optA = seqTrace_optA.getAllInterPointsAtSurface_i_filtered(16);
				allInterPoints_field1 = seqTrace_field1.getAllInterPointsAtSurface_i_filtered(16);
				allInterPoints_field2 = seqTrace_field2.getAllInterPointsAtSurface_i_filtered(16);
				firstInteration = false;
			}

			unsigned int totalNumRay = seqTrace_optA.getStartPoints().size() * fields123_vec.size();
			vectorToExport_rayDensity[tempIteration].push_back(tempRayDensity);
			vectorToExport_rayDensity[tempIteration].push_back(totalNumRay);
			vectorToExport_rayDensity[tempIteration].push_back(timeTotal_optA_ms);
			vectorToExport_rayDensity[tempIteration].push_back(timeTotal_Field1_ms);
			vectorToExport_rayDensity[tempIteration].push_back(timeTotal_Field2_ms);

			real totalTime_ms = timeTotal_optA_ms + timeTotal_Field1_ms + timeTotal_Field2_ms;
			vectorToExport_rayDensity[tempIteration].push_back(totalTime_ms);

			real timePerRay_ms = totalTime_ms / totalNumRay;
			vectorToExport_rayDensity[tempIteration].push_back(timePerRay_ms);

			real timePerSurface_ms = timePerRay_ms / numberSurfaces;
			vectorToExport_rayDensity[tempIteration].push_back(timePerSurface_ms);

			std::cout << "current ray density: " << tempRayDensity << std::endl;
			std::cout << "total time ms: " << totalTime_ms << std::endl;
			std::cout << "temp iteration: " << tempIteration << std::endl;
		}
		
		// middle time
		real tempVal;
		real tempTotalVal;
		real middleVal;
		for (unsigned int k = 0; k < vectorToExport_rayDensity[0].size(); ++k)
		{
			tempTotalVal = 0.0;
			for (unsigned int i = 0; i < vectorToExport_rayDensity.size(); ++i)
			{
				
					tempVal = vectorToExport_rayDensity[i][k];
					tempTotalVal = tempTotalVal + tempVal;
			}

			middleVal = tempTotalVal / (real)maxInterations;
			vectorToExport_rayDensity_middle.push_back(middleVal);
		}


		Spot spotOptA(/*intersection points*/ allInterPoints_optA,/*reference point*/allInterPoints_optA[0]);
		real spotOA = spotOptA.getRMS_µm();

		Spot spotF1(/*intersection points*/ allInterPoints_field1,/*reference point*/allInterPoints_field1[0]);
		real spotRMSF1 = spotF1.getRMS_µm();

		Spot spotF2(/*intersection points*/allInterPoints_field2,/*reference point*/allInterPoints_field2[0]);
		real spotRMSF2 = spotF2.getRMS_µm();

		vectorToExport_rayDensity_middle.push_back(spotOA);
		vectorToExport_rayDensity_middle.push_back(spotRMSF1);
		vectorToExport_rayDensity_middle.push_back(spotRMSF2);

		// check the rms values
		bool checkRMS_optA = Math::compareTwoNumbers_tolerance(spotOA, rms_Zemax[0], toleranceRMS);
		bool checkRMS_F1 = Math::compareTwoNumbers_tolerance(spotRMSF1, rms_Zemax[1], toleranceRMS);
		bool checkRMS_F2 = Math::compareTwoNumbers_tolerance(spotRMSF2, rms_Zemax[2], toleranceRMS);

		test_vec_total.push_back(checkRMS_optA);
		test_vec_total.push_back(checkRMS_F1);
		test_vec_total.push_back(checkRMS_F2);
		
		std::vector<bool> tempCheckRMS;
		tempCheckRMS.push_back(checkRMS_optA);
		tempCheckRMS.push_back(checkRMS_F1);
		tempCheckRMS.push_back(checkRMS_F2);
		bool checkTemp = Math::checkTrueOfVectorElements(tempCheckRMS);
		vectorToExport_rayDensity_middle.push_back(checkTemp);

		inportExportData::exportDataToExcel_vector(location, timeRayTraceAndRMS, "temp ray density, number rays, time optA ms, time field1 ms, time field2 ms, total time ms, timePerRay ms, time per surface ms, spot optA, spot field1, spot field2, checker", vectorToExport_rayDensity_middle);
		vectorToExport_rayDensity_middle.clear();

		for (unsigned int i = 0; i < vectorToExport_rayDensity.size(); ++i)
		{
			vectorToExport_rayDensity[i].clear();
		}
	}


	bool checker = Math::checkTrueOfVectorElements(test_vec_total);
	return checker;
}