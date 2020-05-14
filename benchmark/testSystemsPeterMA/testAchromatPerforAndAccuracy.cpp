#include "testAchromatPerforAndAccuracy.h"

#include"testSystemsPeterMA.h"

// surfaces
#include "..\..\SurfaceElements\SphericalElement.h"
#include "..\..\SurfaceElements\PlanElement.h"
#include "..\..\SurfaceElements\ApertureStopElement.h"

// interactions
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"

// glasses
#include "..\..\Glasses\Glasses.h"

#include "..\..\FillAptertureStop\FillApertureStop.h"
#include "..\..\Analyse\Spot.h"

// evaluate seidel
#include "..\..\OptimizeSystem\EvaluateManyOptSystems_SeidelCoef.h"

testAchroPerforAndAccur::testAchroPerforAndAccur(){}

testAchroPerforAndAccur::~testAchroPerforAndAccur(){}

bool testAchroPerforAndAccur::testAchromatPerformanceAndAccurancy(double startStepSize, double reduceStepSize)
{
	std::string locationToExport = "../benchmark/testSystemsPeterMA/Achromat/";
	std::string nameExelAchro_paraxial = "achromat_paraxial";
	std::string nameExelAchro_seidel = "achromat_seidel";
	std::string nameExelAchro_rayTracing = "achromat_rayTracing";



	std::vector<bool> workTestSystemsPeterMA_E0;
	unsigned int optSysNum_E0 = 0;

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	// surfaces E0
	ApertureStopElement AperStop0_E0(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAir());
	SphericalElement Sphere1_E0(/*radius*/ 25.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere2_E0(/*radius*/ 30.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF6_S1(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere3_E0(/*radius*/ 25.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAir(), /*refractive index B*/glasses.getSF6_S1());
	PlanElement Plan4_E0(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,75.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAir(), /*refractive index B*/ glasses.getAir());

	Sphere1_E0.setParameterRadius(-200.0, 200.0, 0.0, typeModifierVariable);

	surfacePtr Aper0_E0_ptr = AperStop0_E0.clone();
	surfacePtr Sphere1_E0_ptr = Sphere1_E0.clone();
	surfacePtr Sphere2_E0_ptr = Sphere2_E0.clone();
	surfacePtr Sphere3_E0_ptr = Sphere3_E0.clone();
	surfacePtr Plan4_E0_ptr = Plan4_E0.clone();

	std::vector<surfacePtr> opticalSystemE0_ptr{ Aper0_E0_ptr, Sphere1_E0_ptr, Sphere2_E0_ptr , Sphere3_E0_ptr, Plan4_E0_ptr };
	std::vector<interaction_ptr> interactionsE0_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E0(opticalSystemE0_ptr, interactionsE0_ptr);

	// start ray
	StartRayPos startRayPos = notInfinity;

	// light
	std::vector<Light_LLT> lightVec_E0;
	real intensity_d = 1.0;
	JonesVector_LLT polarisation_d(1.0, 1.0, 1.0, 1.0);
	typeLight lightType_d = typeLightRay;
	int isAlive_d = 1;

	real wavelengths587 = 587.5618;
	Light_LLT light0(wavelengths587, intensity_d, polarisation_d, lightType_d, isAlive_d);
	real wavelengths486 = 486.1327;
	Light_LLT light1(wavelengths486, intensity_d, polarisation_d, lightType_d, isAlive_d);
	real wavelengths656 = 656.2725;
	Light_LLT light2(wavelengths656, intensity_d, polarisation_d, lightType_d, isAlive_d);

	lightVec_E0.push_back(light0);
	lightVec_E0.push_back(light1);
	lightVec_E0.push_back(light2);

	real tempSteps = startStepSize;
	stepsWithoutMinWithoutMax addInfosVarS1_temp(/*surface num*/ 1, /*step size*/ tempSteps, /*without min*/ -9.9, /*without max*/ 9.9);
	stepsWithoutMinWithoutMax addInfosVarS2_temp(/*surface num*/ 2, /*step size*/ 999.0, /*without min*/ -9.9, /*without max*/ 9.9);
	stepsWithoutMinWithoutMax addInfosVarS3_temp(/*surface num*/ 3, /*step size*/ 999.0, /*without min*/ -9.9, /*without max*/ 9.9);
	std::vector<stepsWithoutMinWithoutMax> addInfosVarS1_temp_vec{ addInfosVarS1_temp,addInfosVarS2_temp ,addInfosVarS3_temp };

	std::vector<real> rmsZemax_E0 = { 64.338,81.843,129.943 };
	std::vector<real> Var_vec_Zemax_E0 = { 15.5020, -30.0,-20.0 };
	parameterTypeModeStruct R1_E0(1, radius, typeModifierVariable);
	parameterTypeModeStruct R2_E0(2, radius, typeModifierFixed);
	parameterTypeModeStruct R3_E0(3, radius, typeModifierFixed);

	std::vector< parameterTypeModeStruct> parameterTypeModeVec_E0{ R1_E0,R2_E0,R3_E0 };
	std::vector<VectorStructR3> fieldsE0{ {0.0,0.0,0.0},{0.0,1.0,0.0},{0.0,2.0,0.0} };
	std::vector<real>wavelenghtVecE0{ wavelengths587,wavelengths486,wavelengths656 };

	testSystemsPeterMA testSysPeterDummy;

	while (tempSteps >=0.01)
	{
		std::cout << "current step size: " << addInfosVarS1_temp_vec[0].getSteps() << std::endl;

		std::cout << "evaluate best optical system paraxial" << std::endl;
		// *** evaluate best optSys according to paraxial ray tracing ***//
		// time to get best optSys E0
		auto startE0_bestOptSys = std::chrono::system_clock::now();
		// calc the combination vectors
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E0_bestSys(/*optical System Element*/ optSystemElement_E0, /* add infos*/ addInfosVarS1_temp_vec, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		OpticalSystem_LLT bestOptSys_LLT = EvManOptSys_ParaDis_E0_bestSys.getBestOptSys();
		auto endE0_bestOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE0_bestOptSy = endE0_bestOptSys - startE0_bestOptSys;
		auto durationE0_bestOptSy_min = durationE0_bestOptSy.count() / 60.0;

		// export data paraxial
		testSysPeterDummy.saveSystemData_bestOptSys_paraxial(optSysNum_E0, durationE0_bestOptSy_min, optSystemElement_E0, bestOptSys_LLT, EvManOptSys_ParaDis_E0_bestSys.getSystemsForCombination().getAllPosOptSys_LLT().size(), wavelengths587, fieldsE0, lightVec_E0, rmsZemax_E0, Var_vec_Zemax_E0, addInfosVarS1_temp_vec, parameterTypeModeVec_E0, locationToExport, nameExelAchro_paraxial);
		
		
		
		std::cout << "evaluate best optical system seidel" << std::endl;
		// *** evaluate best optSys according to seidel coeff ***//
		//// time evaluate N best opt Sys
		auto startE0_N_besteOptSys = std::chrono::system_clock::now();
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E0_N_bestSys(/*optical System Element*/ optSystemElement_E0, /* add infos*/ addInfosVarS1_temp_vec, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		std::vector<OpticalSystem_LLT> N_bestOptSys_LLT = EvManOptSys_ParaDis_E0_N_bestSys.get_N_BestOptSys_LLT(50);
		auto endE0_N_besteOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE0_LLT_N_bestOptSys = endE0_N_besteOptSys - startE0_N_besteOptSys;
		auto durationE0_LLT_N_bestOptSys_min = durationE0_LLT_N_bestOptSys.count() / 60.0;

		//// time convert N best opt Sys to Element
		optSystemElement_E0.setRefractivIndexAccWave(optSystemElement_E0, wavelengths587);
		auto startE0_N_bestOptSys_convertEle = std::chrono::system_clock::now();
		std::vector<OpticalSystemElement> N_bestOptSys_Ele_E0 = EvManOptSys_ParaDis_E0_N_bestSys.convert_N_optSysLLT_To_elementSystems(N_bestOptSys_LLT, optSystemElement_E0);
		optSystemElement_E0.setRefractivIndexOptSysEle(N_bestOptSys_Ele_E0, wavelengths587);
		auto endE0_N_bestOptSys_convertEle = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE0_N_bestOptSys_convertEle = endE0_N_bestOptSys_convertEle - startE0_N_bestOptSys_convertEle;
		auto durationE0_N_bestOptSys_convertEle_min = durationE0_N_bestOptSys_convertEle.count() / 60.0;

		// evalute N best opt Sys Seidel
		auto startE0_N_bestOptSys_seidel = std::chrono::system_clock::now();
		EvaluateManyOptSystems_SeidelCoef evaluateE0_seidel(N_bestOptSys_Ele_E0, fieldsE0, wavelenghtVecE0);
		OpticalSystemElement bestOptSysEle_E0_seidel = evaluateE0_seidel.calcBestOptSys_OptSysVec();
		auto endE0_N_bestOptSys_seidel = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE0_N_bestOptSys_seidel = endE0_N_bestOptSys_seidel - startE0_N_bestOptSys_seidel;
		auto durationE0_N_bestOptSys_seidel_min = durationE0_N_bestOptSys_seidel.count() / 60.0;

		OpticalSystem_LLT bestOptSysE0_seidel = bestOptSysEle_E0_seidel.getLLTconversion_doConversion();
		bestOptSysE0_seidel.printAllOptSysParameter_LLT(bestOptSysE0_seidel);

		// export data seidel
		testSysPeterDummy.saveSystemData_bestOptSys_seidel(optSysNum_E0, durationE0_LLT_N_bestOptSys_min, durationE0_N_bestOptSys_convertEle_min, durationE0_N_bestOptSys_seidel_min, optSystemElement_E0, bestOptSysE0_seidel, EvManOptSys_ParaDis_E0_N_bestSys, wavelengths587, fieldsE0, lightVec_E0, rmsZemax_E0, Var_vec_Zemax_E0, addInfosVarS1_temp_vec, parameterTypeModeVec_E0, locationToExport, nameExelAchro_seidel);

		std::cout << "evaluate best optical system ray tracing" << std::endl;
		// *** evaluate best optSys according to ray tracing ***//
	
		std::cout << "evaluate best optical system ray tracing" << std::endl;
		// *** evaluate best optSys according to real ray tracing ***//
		auto startE0_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		EvaluateManyOptSys_RayTracing evaluateE0_rayTracing(optSystemElement_E0, addInfosVarS1_temp_vec, fieldsE0, wavelenghtVecE0);
		OpticalSystemElement bestOptSysEle_E0_rayTracing = evaluateE0_rayTracing.getBestOptSys();
		auto end_E0_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE0_LLT_N_bestOptSys_rayTracing = end_E0_N_bestOptSys_rayTracing - startE0_N_bestOptSys_rayTracing;
		auto durationE0_LLT_N_bestOptSys_rayTracing_min = durationE0_LLT_N_bestOptSys_rayTracing.count() / 60.0;

		OpticalSystem_LLT bestOptSysE0_rayTracing = bestOptSysEle_E0_rayTracing.getLLTconversion_doConversion();
		bestOptSysE0_rayTracing.printAllOptSysParameter_LLT(bestOptSysE0_rayTracing);


		testSysPeterDummy.saveSystemData_bestOptSys_RayTracing(optSysNum_E0, durationE0_LLT_N_bestOptSys_rayTracing_min, optSystemElement_E0, bestOptSysE0_rayTracing, evaluateE0_rayTracing, wavelengths587, fieldsE0, lightVec_E0, rmsZemax_E0, Var_vec_Zemax_E0, addInfosVarS1_temp_vec, parameterTypeModeVec_E0, locationToExport, nameExelAchro_rayTracing);

		// set new step size
		tempSteps = tempSteps - reduceStepSize;
		addInfosVarS1_temp_vec[0].setSteps(tempSteps);
	}

	

	// check rms spot radius of initial system 
	SequentialRayTracing seqTraceE0(optSystemElement_E0, { 0.0,0.0,0.0 }, 6, 8, 1.0, lightVec_E0);
	Spot spotE0(seqTraceE0.getAllInterPointsAtSurf_i_notFiltered(4), seqTraceE0.getAllInterPointsAtSurf_i_notFiltered(4).at(0));
	real rmsSpotE0 = spotE0.getRMS_µm();
	real excelBest_Zemax_RMS = 1031.21;
	bool checkE0_rmsBest = Math::compareTwoNumbers_decimals(excelBest_Zemax_RMS, rmsSpotE0, 2);
	workTestSystemsPeterMA_E0.push_back(checkE0_rmsBest);
	
	bool returnCheckerE0 = Math::checkTrueOfVectorElements(workTestSystemsPeterMA_E0);

	return returnCheckerE0;
}

