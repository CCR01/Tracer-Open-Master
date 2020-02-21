#include "testSystemsPeterMA.h"

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

#include "..\..\OptimizeSystem\OptimizeOpticalSystem.h"

// evaluate seidel
#include "..\..\OptimizeSystem\EvaluateManyOptSystems_SeidelCoef.h"

#include "..\..\Inport_Export_Data\Inport_Export_Data.h"
//#include "..\..\LowLevelTracing\Math_LLT.h"

std::string locationToExportData = "../benchmark/testSystemsPeterMA/";
std::string nameExcelFileBestSys_paraxial = "bestOptSys_paraxial";
std::string nameExcelFileBestSys_seidel = "bestOptSys_seidel";
std::string nameExcelFileBestSys_rayTracing = "bestOptSys_rayTracing";

testSystemsPeterMA::testSystemsPeterMA() {}

testSystemsPeterMA::~testSystemsPeterMA() {}

bool testSystemsPeterMA::calcTestSystemPeterMA_superFct()
{
	std::vector<bool> workTestSystemPeterMA_superFct;

	// E0
	bool checkE0_testSysPeterMA = calcTestSystemPeterMA_E0(testParaxial);
	workTestSystemPeterMA_superFct.push_back(checkE0_testSysPeterMA);
	
//	// E1
//	bool checkE1_testSysPeterMA = calcTestSystemPeterMA_E1(testRayTrac);
//	workTestSystemPeterMA_superFct.push_back(checkE1_testSysPeterMA);
	
//	// E2
//	bool checkE2_testSysPeterMA = calcTestSystemPeterMA_E2();
//	workTestSystemPeterMA_superFct.push_back(checkE2_testSysPeterMA);
//	
//	// E3
//	bool checkE3_testSysPeterMA = calcTestSystemPeterMA_E3();
//	workTestSystemPeterMA_superFct.push_back(checkE3_testSysPeterMA);
//	
//	// E4
//	bool checkE4_testSysPeterMA = calcTestSystemPeterMA_E4();
//	workTestSystemPeterMA_superFct.push_back(checkE4_testSysPeterMA);
//
//	// E5
//	bool checkE5_testSysPeterMA = calcTestSystemPeterMA_E5();
//	workTestSystemPeterMA_superFct.push_back(checkE5_testSysPeterMA);
//	
//	// E6
//	bool checkE6_testSysPeterMA = calcTestSystemPeterMA_E6();
//	workTestSystemPeterMA_superFct.push_back(checkE6_testSysPeterMA);
//	
//	// E7
//	bool checkE7_testSysPeterMA = calcTestSystemPeterMA_E7();
//	workTestSystemPeterMA_superFct.push_back(checkE7_testSysPeterMA);
//	
//	// E8
//	bool checkE8_testSysPeterMA = calcTestSystemPeterMA_E8();
//	workTestSystemPeterMA_superFct.push_back(checkE8_testSysPeterMA);
//	
//	// E9
//	bool checkE9_testSysPeterMA = calcTestSystemPeterMA_E9();
//	workTestSystemPeterMA_superFct.push_back(checkE9_testSysPeterMA);
//


	bool checker = Math::checkTrueOfVectorElements(workTestSystemPeterMA_superFct);
	return checker;
}

bool testSystemsPeterMA::calcTestSystemPeterMA_E0(testWhatEnum testWhat)
{
	std::vector<bool> workTestSystemsPeterMA_E0;


	real optSysNum_E0 = 0;


	
	std::vector<real> exportDataE0_seidel;
	exportDataE0_seidel.push_back(optSysNum_E0);

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	// surfaces E0
	ApertureStopElement AperStop0_E0(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAirZemax());
	SphericalElement Sphere1_E0(/*radius*/ 25.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBK7_S1());
	SphericalElement Sphere2_E0(/*radius*/ 25.00, /*semi height*/7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF11_S1(), /*refractive index B*/glasses.getBK7_S1());
	SphericalElement Sphere3_E0(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF11_S1());
	SphericalElement Sphere4_E0(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF3_S1());
	SphericalElement Sphere5_E0(/*radius*/ 70.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF3_S1());
	SphericalElement Sphere6_E0(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere7_E0(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere8_E0(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getNSSK8_S1());
	PlanElement Plan9_E0(/*semi height*/ 7.0, /*point*/{ 0.0,0.0,80.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAirZemax(), /*refractive index B*/ glasses.getAirZemax());

	Sphere3_E0.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere5_E0.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);
	Sphere7_E0.setParameterRadius(-1000.0, 1000.0, 0.0, typeModifierVariable);

	surfacePtr Aper0_E0_ptr = AperStop0_E0.clone();
	surfacePtr Sphere1_E0_ptr = Sphere1_E0.clone();
	surfacePtr Sphere2_E0_ptr = Sphere2_E0.clone();
	surfacePtr Sphere3_E0_ptr = Sphere3_E0.clone();
	surfacePtr Sphere4_E0_ptr = Sphere4_E0.clone();
	surfacePtr Sphere5_E0_ptr = Sphere5_E0.clone();
	surfacePtr Sphere6_E0_ptr = Sphere6_E0.clone();
	surfacePtr Sphere7_E0_ptr = Sphere7_E0.clone();
	surfacePtr Sphere8_E0_ptr = Sphere8_E0.clone();
	surfacePtr Plan9_E0_ptr = Plan9_E0.clone();

	std::vector<surfacePtr> opticalSystemE0_ptr{ Aper0_E0_ptr, Sphere1_E0_ptr, Sphere2_E0_ptr , Sphere3_E0_ptr, Sphere4_E0_ptr, Sphere5_E0_ptr, Sphere6_E0_ptr, Sphere7_E0_ptr, Sphere8_E0_ptr, Plan9_E0_ptr };
	std::vector<interaction_ptr> interactionsE0_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E0(opticalSystemE0_ptr, interactionsE0_ptr);

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

	// check rms spot radius of initial system 
	// ***
	SequentialRayTracing seqTraceE0_checker(optSystemElement_E0, { 0.0,0.0,0.0 }, 6, 8, 1.0, lightVec_E0);
	Spot spotE0(seqTraceE0_checker.getAllInterPointsAtSurf_i(9), seqTraceE0_checker.getAllInterPointsAtSurf_i(9).at(0));
	real rmsSpotE0 = spotE0.getRMS_µm();
	real excelBest_Zemax_RMS = 209.256;
	bool checkE0_rmsBest = Math::compareTwoNumbers_decimals(excelBest_Zemax_RMS, rmsSpotE0, 2);
	workTestSystemsPeterMA_E0.push_back(checkE0_rmsBest);
	// ***
	   
	


	// ***
	
	// Evaulate the system according to paraxial ray tracing
	// def steps variables
	stepsWithoutMinWithoutMax addInfosVarS3(/*surface num*/ 3, /*step size*/ 30, /*without min*/ -9.9, /*without max*/ 9.9); 
	stepsWithoutMinWithoutMax addInfosVarS5(/*surface num*/ 5, /*step size*/ 30, /*without min*/ -9.9, /*without max*/ 9.9);
	stepsWithoutMinWithoutMax addInfosVarS7(/*surface num*/ 7, /*step size*/ 30, /*without min*/ -9.9, /*without max*/ 9.9);
	std::vector<stepsWithoutMinWithoutMax> addInfosVariable_E0{ addInfosVarS3,addInfosVarS5,addInfosVarS7 };
	
	// start ray
	StartRayPos startRayPos = notInfinity;
	
	std::vector<real> rmsZemax_E0 = { 17.049,22.008,35.681 };
	std::vector<real> Var_vec_Zemax_E0 = { -21.0725, 582.2823,-62.1854 };
	parameterTypeModeStruct R3_E0(3, radius, typeModifierVariable);
	parameterTypeModeStruct R5_E0(5, radius, typeModifierVariable);
	parameterTypeModeStruct R7_E0(7, radius, typeModifierVariable);

	std::vector< parameterTypeModeStruct> parameterTypeModeVec_E0{ R3_E0,R5_E0,R7_E0 };
	std::vector<VectorStructR3> fieldsE0{ {0.0,0.0,0.0},{0.0,1.0,0.0},{0.0,2.0,0.0} };
	std::vector<real>wavelenghtVecE0{ wavelengths587,wavelengths486,wavelengths656 };

	real tempV0;
	real tempDirecV0;
	real tempV1;
	real tempDirecV1;
	real tempV2;
	real tempDirecV2;

	real tempV0_max;
	real tempV0_min;
	real tempV1_max;
	real tempV1_min;
	real tempV2_max;
	real tempV2_min;

	real tempStepSizeV0;
	real tempStepSizeV1;
	real tempStepSizeV2;

	parameterTypeModeStruct paraV0(3, radius, typeModifierVariable);
	parameterTypeModeStruct paraV1(5, radius, typeModifierVariable);
	parameterTypeModeStruct paraV2(7, radius, typeModifierVariable);
	std::vector<parameterTypeModeStruct> parameterVec{ paraV0,paraV1,paraV2 };

	// *** evaluate best optSys ***//
	if (testWhat == testAll || testWhat == testParaxial)
	{
		std::cout << "evaluate best optical system paraxial" << std::endl;
		// *** evaluate best optSys according to paraxial ray tracing ***//

		// time to get best optSys E0
		auto startE0_bestOptSys = std::chrono::system_clock::now();
		// calc the combination vectors
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E0_bestSys(/*optical System Element*/ optSystemElement_E0, /* add infos*/ addInfosVariable_E0, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		OpticalSystem_LLT bestOptSys_LLT_iteration0 = EvManOptSys_ParaDis_E0_bestSys.getBestOptSys();
		auto endE0_bestOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE0_bestOptSy = endE0_bestOptSys - startE0_bestOptSys;
		auto durationE0_bestOptSy_min = durationE0_bestOptSy.count() / 60.0;
			
		// save data Interation 0
		saveSystemData_bestOptSys_paraxial(optSysNum_E0, durationE0_bestOptSy_min, optSystemElement_E0, bestOptSys_LLT_iteration0, EvManOptSys_ParaDis_E0_bestSys.getSystemsForCombination().getAllPosOptSys_LLT().size(), wavelengths587, fieldsE0,  lightVec_E0, rmsZemax_E0, Var_vec_Zemax_E0, addInfosVariable_E0, parameterTypeModeVec_E0, locationToExportData, nameExcelFileBestSys_paraxial);
		
		
		auto startE0_bestOptSys_iteration1 = std::chrono::system_clock::now();
		EvManOptSys_ParaDis_E0_bestSys.doOneMoreIteration_3var(optSystemElement_E0, bestOptSys_LLT_iteration0, paraV0, paraV1, paraV2);
		OpticalSystem_LLT bestOptSys_interation1 = EvManOptSys_ParaDis_E0_bestSys.getBestOptSys();
		auto endE0_bestOptSys_iteration1 = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE0_bestOptSy_iteration1 = endE0_bestOptSys_iteration1 - startE0_bestOptSys_iteration1;
		auto durationE0_bestOptSy_min_iteration1 = durationE0_bestOptSy_iteration1.count() / 60.0;

		// save date interation 1
		saveSystemData_bestOptSys_paraxial(optSysNum_E0, durationE0_bestOptSy_min_iteration1, optSystemElement_E0, bestOptSys_interation1, EvManOptSys_ParaDis_E0_bestSys.getSystemsForCombination().getAllPosOptSys_LLT().size(), wavelengths587, fieldsE0, lightVec_E0, rmsZemax_E0, Var_vec_Zemax_E0, addInfosVariable_E0, parameterTypeModeVec_E0, locationToExportData, nameExcelFileBestSys_paraxial);
		
		// optimize with genetic and local
		//OpticalSystemElement optSysStart_Ele, OpticalSystem_LLT bestOptSys_LLT, std::vector<parameterTypeModeStruct> parameter, std::vector< stepsWithoutMinWithoutMax> stepsWitoutMinMax
		
		stepsWithoutMinWithoutMax stepWMinMaxV0(/*surface num*/ 3, /*step size*/ 10, /*without min*/ 9.9, /*without max*/ 1000);
		stepsWithoutMinWithoutMax stepWMinMaxV1(/*surface num*/ 5, /*step size*/ 10, /*without min*/ 9.9, /*without max*/ 1000);
		stepsWithoutMinWithoutMax stepWMinMaxV2(/*surface num*/ 7, /*step size*/ 10, /*without min*/ 9.9, /*without max*/ 1000);

		std::vector< stepsWithoutMinWithoutMax> stepsWitoutMinMax_genE0{ stepWMinMaxV0, stepWMinMaxV1, stepWMinMaxV2 };

		OpticalSystemElement optSysEleForGen = optSystemElement_E0.convertOptSys_LLT_T0_OptSys_HLT(optSystemElement_E0, bestOptSys_interation1, parameterVec, stepsWitoutMinMax_genE0);

		//	// next we start the optimasation
		std::cout << "start of genetic E0 \n";
			   
		// population of the optimasation process
		unsigned int population_E0 = 500;
		
		// stadt the optim
		localStart localOp_E0 = radiusStart;
		/*mutation factor*/
		real mutarionFactor_E0 = 0.01;

		auto startE0_bestOptSys_gen = std::chrono::system_clock::now();
		OptimizeOpticalSystem optimizedOptSys_E0(optSysEleForGen, population_E0, mutarionFactor_E0, localOp_E0);

		optimizedOptSys_E0.setCheckAllLocalCombinations_optimizer(true);
		optimizedOptSys_E0.add_FieldAndWeight({ 0.0,1.0,0.0 }, 1.0);
		optimizedOptSys_E0.add_FieldAndWeight({ 0.0,2.0,0.0 }, 1.0);
		optimizedOptSys_E0.set_Light(light0);
		optimizedOptSys_E0.add_Light(light1);
		optimizedOptSys_E0.add_Light(light2);
		
		// set rings and arms for the optimasation
		optimizedOptSys_E0.setRings_optimizer(6);
		optimizedOptSys_E0.setArms_optimizer(8);
		// *********************************
		// start optimasation of example E12
		optimizedOptSys_E0.optimizeSUPERFUNCTION();
		// *********************************
		// get the optimized optical system
		OpticalSystemElement optimizedOptSys_Ele_E0 = optimizedOptSys_E0.getOptSysOptimized_Ele();
		auto endE0_bestOptSys_gen = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE0_bestOptSy_gen = endE0_bestOptSys_gen - startE0_bestOptSys_gen;
		auto durationE0_bestOptSy_min_gen = durationE0_bestOptSy_gen.count() / 60.0;

	
		OpticalSystem_LLT bestOptSys_gen_LLT = optimizedOptSys_Ele_E0.getLLTconversion_doConversion();


		// save date interation 1
		saveSystemData_bestOptSys_paraxial(optSysNum_E0, durationE0_bestOptSy_min_gen, optSystemElement_E0, bestOptSys_gen_LLT, 0, wavelengths587, fieldsE0, lightVec_E0, rmsZemax_E0, Var_vec_Zemax_E0, stepsWitoutMinMax_genE0, parameterVec, locationToExportData, nameExcelFileBestSys_paraxial);

	}
	// *** --- ***//
	
	// evaluate the system according to seidel coef
	if (testWhat == testAll || testWhat == testSeidel)
	{
		std::cout << "evaluate best optical system seidel" << std::endl;

		// *** evaluate best optSys according to seidel coeff ***//
		//// time evaluate N best opt Sys
		auto startE0_N_besteOptSys = std::chrono::system_clock::now();
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E0_N_bestSys(/*optical System Element*/ optSystemElement_E0, /* add infos*/ addInfosVariable_E0, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		std::vector<OpticalSystem_LLT> N_bestOptSys_LLT = EvManOptSys_ParaDis_E0_N_bestSys.get_N_BestOptSys_LLT(50);
		auto endE0_N_besteOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE0_LLT_N_bestOptSys = endE0_N_besteOptSys - startE0_N_besteOptSys;
		auto durationE0_LLT_N_bestOptSys_min = durationE0_LLT_N_bestOptSys.count() / 60.0;

		//// time convert N best opt Sys to Element
		optSystemElement_E0.setRefractivIndexAccWave(optSystemElement_E0,wavelengths587);
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

		saveSystemData_bestOptSys_seidel(optSysNum_E0, durationE0_LLT_N_bestOptSys_min, durationE0_N_bestOptSys_convertEle_min, durationE0_N_bestOptSys_seidel_min, optSystemElement_E0, bestOptSysE0_seidel, EvManOptSys_ParaDis_E0_N_bestSys, wavelengths587, fieldsE0, lightVec_E0, rmsZemax_E0, Var_vec_Zemax_E0, addInfosVariable_E0, parameterTypeModeVec_E0, locationToExportData, nameExcelFileBestSys_seidel);

	}
	// *** --- ***//


	// evaluate the system according to ray tracing
	if (testWhat == testAll || testWhat == testRayTrac)
	{
		std::cout << "evaluate best optical system ray tracing" << std::endl;
		// *** evaluate best optSys according to real ray tracing ***//
		auto startE0_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		EvaluateManyOptSys_RayTracing evaluateE0_rayTracing(optSystemElement_E0, addInfosVariable_E0, fieldsE0, wavelenghtVecE0);
		OpticalSystemElement bestOptSysEle_E0_rayTracing = evaluateE0_rayTracing.getBestOptSys();
		auto end_E0_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE0_LLT_N_bestOptSys_rayTracing = end_E0_N_bestOptSys_rayTracing - startE0_N_bestOptSys_rayTracing;
		auto durationE0_LLT_N_bestOptSys_rayTracing_min = durationE0_LLT_N_bestOptSys_rayTracing.count() / 60.0;

		OpticalSystem_LLT bestOptSysE0_rayTracing = bestOptSysEle_E0_rayTracing.getLLTconversion_doConversion();
		bestOptSysE0_rayTracing.printAllOptSysParameter_LLT(bestOptSysE0_rayTracing);

		
		saveSystemData_bestOptSys_RayTracing(optSysNum_E0, durationE0_LLT_N_bestOptSys_rayTracing_min, optSystemElement_E0, bestOptSysE0_rayTracing, evaluateE0_rayTracing, wavelengths587, fieldsE0, lightVec_E0, rmsZemax_E0, Var_vec_Zemax_E0, addInfosVariable_E0, parameterTypeModeVec_E0, locationToExportData, nameExcelFileBestSys_rayTracing);

	}



	bool returnCheckerE0 = Math::checkTrueOfVectorElements(workTestSystemsPeterMA_E0);

	return returnCheckerE0;


}

bool testSystemsPeterMA::calcTestSystemPeterMA_E1(testWhatEnum testWhat)
{

	std::vector<bool> workTestSystemsPeterMA_E1;

	real optSysNum_E1 = 1; 

	std::vector<real> exportDataE1_seidel;
	exportDataE1_seidel.push_back(optSysNum_E1);

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	// surfaces E1
	ApertureStopElement AperStop0_E1(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAirZemax());
	SphericalElement Sphere1_E1(/*radius*/ 35.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBK7_S1());
	SphericalElement Sphere2_E1(/*radius*/ 35.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF11_S1(), /*refractive index B*/glasses.getBK7_S1());
	SphericalElement Sphere3_E1(/*radius*/ 45.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF11_S1());
	SphericalElement Sphere4_E1(/*radius*/ 100.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF3_S1());
	SphericalElement Sphere5_E1(/*radius*/ 90.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF3_S1());
	SphericalElement Sphere6_E1(/*radius*/ 60.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere7_E1(/*radius*/ 45.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere8_E1(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement Sphere9_E1(/*radius*/ 80.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere10_E1(/*radius*/ 70.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF5_S1());
	PlanElement Plan11_E1(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,95.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAirZemax(), /*refractive index B*/ glasses.getAirZemax());

	Sphere3_E1.setParameterRadius(-100.0, 100.0, 0.0, typeModifierVariable);
	Sphere6_E1.setParameterPointZ(55.0, 200.0, 0.0, typeModifierVariable);
	Sphere9_E1.setParameterRadius(-100.0, 100.0, 0.0, typeModifierVariable);

	surfacePtr Aper0_E1_ptr = AperStop0_E1.clone();
	surfacePtr Sphere1_E1_ptr = Sphere1_E1.clone();
	surfacePtr Sphere2_E1_ptr = Sphere2_E1.clone();
	surfacePtr Sphere3_E1_ptr = Sphere3_E1.clone();
	surfacePtr Sphere4_E1_ptr = Sphere4_E1.clone();
	surfacePtr Sphere5_E1_ptr = Sphere5_E1.clone();
	surfacePtr Sphere6_E1_ptr = Sphere6_E1.clone();
	surfacePtr Sphere7_E1_ptr = Sphere7_E1.clone();
	surfacePtr Sphere8_E1_ptr = Sphere8_E1.clone();
	surfacePtr Sphere9_E1_ptr = Sphere9_E1.clone();
	surfacePtr Sphere10_E1_ptr = Sphere10_E1.clone();
	surfacePtr Plan11_E1_ptr = Plan11_E1.clone();

	std::vector<surfacePtr> opticalSystemE1_ptr{ Aper0_E1_ptr, Sphere1_E1_ptr, Sphere2_E1_ptr , Sphere3_E1_ptr, Sphere4_E1_ptr, Sphere5_E1_ptr, Sphere6_E1_ptr, Sphere7_E1_ptr, Sphere8_E1_ptr, Sphere9_E1_ptr, Sphere10_E1_ptr, Plan11_E1_ptr };
	std::vector<interaction_ptr> interactionsE1_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E1(opticalSystemE1_ptr, interactionsE1_ptr);

	// light
	std::vector<Light_LLT> lightVec_E1;
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

	lightVec_E1.push_back(light0);
	lightVec_E1.push_back(light1);
	lightVec_E1.push_back(light2);

	// ***

	// Evaulate the system according to paraxial ray tracing
	// def steps variables
	stepsWithoutMinWithoutMax addInfosVarS3(/*surface num*/ 3, /*step size*/ 50, /*without min*/ -9.9, /*without max*/ 9.9);
	stepsWithoutMinWithoutMax addInfosVarS6(/*surface num*/ 6, /*step size*/ 30, /*without min*/ 0.0, /*without max*/ 0.0);
	stepsWithoutMinWithoutMax addInfosVarS9(/*surface num*/ 9, /*step size*/ 50, /*without min*/ -9.9, /*without max*/ 9.9);
	std::vector<stepsWithoutMinWithoutMax> addInfosVariable_E1{ addInfosVarS3,addInfosVarS6,addInfosVarS9 };

	// start ray
	StartRayPos startRayPos = notInfinity;

	std::vector<real> rmsZemax_E1 = { 30.579, 47.335, 89.337 };
	std::vector<real> Var_vec_Zemax_E1 = { -28.596, 5.000,-12.434 };
	parameterTypeModeStruct R3_E1(3, radius, typeModifierVariable);
	parameterTypeModeStruct D5_6_E1(6, position, typeModifierVariable);
	parameterTypeModeStruct R9_E1(9, radius, typeModifierVariable);

	std::vector< parameterTypeModeStruct> parameterTypeModeVec_E1{ R3_E1,D5_6_E1,R9_E1 };
	std::vector<VectorStructR3> fieldsE1{ {0.0,0.0,0.0},{0.0,2.0,0.0},{0.0,4.0,0.0} };
	std::vector<real>wavelenghtVecE1{ wavelengths587,wavelengths486,wavelengths656 };

	// *** evaluate best optSys ***//
	if (testWhat == testAll || testWhat == testParaxial)
	{
		std::cout << "evaluate best optical system paraxial" << std::endl;
		// *** evaluate best optSys according to paraxial ray tracing ***//

		// time to get best optSys E1
		auto startE1_bestOptSys = std::chrono::system_clock::now();
		// calc the combination vectors
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E1_bestSys(/*optical System Element*/ optSystemElement_E1, /* add infos*/ addInfosVariable_E1, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		OpticalSystem_LLT bestOptSys_LLT = EvManOptSys_ParaDis_E1_bestSys.getBestOptSys();
		auto endE1_bestOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE1_bestOptSy = endE1_bestOptSys - startE1_bestOptSys;
		auto durationE1_bestOptSy_min = durationE1_bestOptSy.count() / 60.0;

		saveSystemData_bestOptSys_paraxial(optSysNum_E1, durationE1_bestOptSy_min, optSystemElement_E1, bestOptSys_LLT, EvManOptSys_ParaDis_E1_bestSys.getSystemsForCombination().getAllPosOptSys_LLT().size(), wavelengths587, fieldsE1, lightVec_E1, rmsZemax_E1, Var_vec_Zemax_E1, addInfosVariable_E1, parameterTypeModeVec_E1, locationToExportData, nameExcelFileBestSys_paraxial);

	}
	// *** --- ***//

	// evaluate the system according to seidel coef
	if (testWhat == testAll || testWhat == testSeidel)
	{
		std::cout << "evaluate best optical system seidel" << std::endl;

		// *** evaluate best optSys according to seidel coeff ***//
		//// time evaluate N best opt Sys
		auto startE1_N_besteOptSys = std::chrono::system_clock::now();
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E1_N_bestSys(/*optical System Element*/ optSystemElement_E1, /* add infos*/ addInfosVariable_E1, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		std::vector<OpticalSystem_LLT> N_bestOptSys_LLT = EvManOptSys_ParaDis_E1_N_bestSys.get_N_BestOptSys_LLT(50);
		auto endE1_N_besteOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE1_LLT_N_bestOptSys = endE1_N_besteOptSys - startE1_N_besteOptSys;
		auto durationE1_LLT_N_bestOptSys_min = durationE1_LLT_N_bestOptSys.count() / 60.0;

		//// time convert N best opt Sys to Element
		optSystemElement_E1.setRefractivIndexAccWave(optSystemElement_E1, wavelengths587);
		auto startE1_N_bestOptSys_convertEle = std::chrono::system_clock::now();
		std::vector<OpticalSystemElement> N_bestOptSys_Ele_E1 = EvManOptSys_ParaDis_E1_N_bestSys.convert_N_optSysLLT_To_elementSystems(N_bestOptSys_LLT, optSystemElement_E1);
		optSystemElement_E1.setRefractivIndexOptSysEle(N_bestOptSys_Ele_E1, wavelengths587);
		auto endE1_N_bestOptSys_convertEle = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE1_N_bestOptSys_convertEle = endE1_N_bestOptSys_convertEle - startE1_N_bestOptSys_convertEle;
		auto durationE1_N_bestOptSys_convertEle_min = durationE1_N_bestOptSys_convertEle.count() / 60.0;

		// evalute N best opt Sys Seidel

		auto startE1_N_bestOptSys_seidel = std::chrono::system_clock::now();
		EvaluateManyOptSystems_SeidelCoef evaluateE1_seidel(N_bestOptSys_Ele_E1, fieldsE1, wavelenghtVecE1);
		OpticalSystemElement bestOptSysEle_E1_seidel = evaluateE1_seidel.calcBestOptSys_OptSysVec();
		auto endE1_N_bestOptSys_seidel = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE1_N_bestOptSys_seidel = endE1_N_bestOptSys_seidel - startE1_N_bestOptSys_seidel;
		auto durationE1_N_bestOptSys_seidel_min = durationE1_N_bestOptSys_seidel.count() / 60.0;

		OpticalSystem_LLT bestOptSysE1_seidel = bestOptSysEle_E1_seidel.getLLTconversion_doConversion();
		bestOptSysE1_seidel.printAllOptSysParameter_LLT(bestOptSysE1_seidel);

		saveSystemData_bestOptSys_seidel(optSysNum_E1, durationE1_LLT_N_bestOptSys_min, durationE1_N_bestOptSys_convertEle_min, durationE1_N_bestOptSys_seidel_min, optSystemElement_E1, bestOptSysE1_seidel, EvManOptSys_ParaDis_E1_N_bestSys, wavelengths587, fieldsE1, lightVec_E1, rmsZemax_E1, Var_vec_Zemax_E1, addInfosVariable_E1, parameterTypeModeVec_E1, locationToExportData, nameExcelFileBestSys_seidel);

	}
	// *** --- ***//


	// evaluate the system according to ray tracing
	if (testWhat == testAll || testWhat == testRayTrac)
	{
		std::cout << "evaluate best optical system ray tracing" << std::endl;
		// *** evaluate best optSys according to real ray tracing ***//
		auto startE1_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		EvaluateManyOptSys_RayTracing evaluateE1_rayTracing(optSystemElement_E1, addInfosVariable_E1, fieldsE1, wavelenghtVecE1);
		OpticalSystemElement bestOptSysEle_E1_rayTracing = evaluateE1_rayTracing.getBestOptSys();
		auto end_E1_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE1_LLT_N_bestOptSys_rayTracing = end_E1_N_bestOptSys_rayTracing - startE1_N_bestOptSys_rayTracing;
		auto durationE1_LLT_N_bestOptSys_rayTracing_min = durationE1_LLT_N_bestOptSys_rayTracing.count() / 60.0;

		OpticalSystem_LLT bestOptSysE1_rayTracing = bestOptSysEle_E1_rayTracing.getLLTconversion_doConversion();
		bestOptSysE1_rayTracing.printAllOptSysParameter_LLT(bestOptSysE1_rayTracing);


		saveSystemData_bestOptSys_RayTracing(optSysNum_E1, durationE1_LLT_N_bestOptSys_rayTracing_min, optSystemElement_E1, bestOptSysE1_rayTracing, evaluateE1_rayTracing, wavelengths587, fieldsE1, lightVec_E1, rmsZemax_E1, Var_vec_Zemax_E1, addInfosVariable_E1, parameterTypeModeVec_E1, locationToExportData, nameExcelFileBestSys_rayTracing);

	}

	// check rms spot radius of initial system 
	SequentialRayTracing seqTraceE1_checker(optSystemElement_E1, { 0.0,0.0,0.0 }, 6, 8, 1.0, lightVec_E1);
	Spot spotE1(seqTraceE1_checker.getAllInterPointsAtSurf_i(11), seqTraceE1_checker.getAllInterPointsAtSurf_i(11).at(0));
	real rmsSpotE1 = spotE1.getRMS_µm();
	real excelBest_Zemax_RMS = 68.245;
	bool checkE1_rmsBest = Math::compareTwoNumbers_decimals(excelBest_Zemax_RMS, rmsSpotE1, 1);
	workTestSystemsPeterMA_E1.push_back(checkE1_rmsBest);
	// ***



	bool returnCheckerE1 = Math::checkTrueOfVectorElements(workTestSystemsPeterMA_E1);

	return returnCheckerE1;


}

bool testSystemsPeterMA::calcTestSystemPeterMA_E2(testWhatEnum testWhat)
{

	std::vector<bool> workTestSystemsPeterMA_E2;

	real optSysNum_E2 = 2;



	std::vector<real> exportDataE2_seidel;
	exportDataE2_seidel.push_back(optSysNum_E2);

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	// surfaces E2
	ApertureStopElement AperStop0_E2(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAirZemax());
	SphericalElement Sphere1_E2(/*radius*/ 100.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF3_S1(), /*refractive index B*/glasses.getAirZemax());
	SphericalElement Sphere2_E2(/*radius*/ 150.00, /*semi height*/7.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF3_S1(), /*refractive index B*/glasses.getAirZemax());
	SphericalElement Sphere3_E2(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere4_E2(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere5_E2(/*radius*/ 30.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement Sphere6_E2(/*radius*/ 50.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF4_S1());
	SphericalElement Sphere7_E2(/*radius*/ 40.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF57_S1(), /*refractive index B*/glasses.getSF4_S1());
	SphericalElement Sphere8_E2(/*radius*/ 35.00, /*semi height*/ 7.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF57_S1());
	PlanElement Plan9_E2(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,90.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAirZemax(), /*refractive index B*/ glasses.getAirZemax());

	Sphere2_E2.setParameterRadius(-100.0, 100.0, 0.0, typeModifierVariable);
	Sphere4_E2.setParameterRadius(-100.0, 100.0, 0.0, typeModifierVariable);
	Sphere6_E2.setParameterRadius(-100.0, 100.0, 0.0, typeModifierVariable);

	surfacePtr Aper0_E2_ptr = AperStop0_E2.clone();
	surfacePtr Sphere1_E2_ptr = Sphere1_E2.clone();
	surfacePtr Sphere2_E2_ptr = Sphere2_E2.clone();
	surfacePtr Sphere3_E2_ptr = Sphere3_E2.clone();
	surfacePtr Sphere4_E2_ptr = Sphere4_E2.clone();
	surfacePtr Sphere5_E2_ptr = Sphere5_E2.clone();
	surfacePtr Sphere6_E2_ptr = Sphere6_E2.clone();
	surfacePtr Sphere7_E2_ptr = Sphere7_E2.clone();
	surfacePtr Sphere8_E2_ptr = Sphere8_E2.clone();
	surfacePtr Plan9_E2_ptr = Plan9_E2.clone();

	std::vector<surfacePtr> opticalSystemE2_ptr{ Aper0_E2_ptr, Sphere1_E2_ptr, Sphere2_E2_ptr , Sphere3_E2_ptr, Sphere4_E2_ptr, Sphere5_E2_ptr, Sphere6_E2_ptr, Sphere7_E2_ptr, Sphere8_E2_ptr, Plan9_E2_ptr };
	std::vector<interaction_ptr> interactionsE2_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E2(opticalSystemE2_ptr, interactionsE2_ptr);

	// light
	std::vector<Light_LLT> lightVec_E2;
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

	lightVec_E2.push_back(light0);
	lightVec_E2.push_back(light1);
	lightVec_E2.push_back(light2);

	// ***

	// Evaulate the system according to paraxial ray tracing
	// def steps variables
	stepsWithoutMinWithoutMax addInfosVarS2(/*surface num*/ 2, /*step size*/ 2, /*without min*/ -9.9, /*without max*/ 9.9);
	stepsWithoutMinWithoutMax addInfosVarS4(/*surface num*/ 4, /*step size*/ 4, /*without min*/ -9.9, /*without max*/ 9.9);
	stepsWithoutMinWithoutMax addInfosVarS6(/*surface num*/ 6, /*step size*/ 2, /*without min*/ -9.9, /*without max*/ 9.9);
	std::vector<stepsWithoutMinWithoutMax> addInfosVariable_E2{ addInfosVarS2,addInfosVarS4,addInfosVarS6 };

	// start ray
	StartRayPos startRayPos = notInfinity;

	std::vector<real> rmsZemax_E2 = { 39.558,50.534,80.670 };
	std::vector<real> Var_vec_Zemax_E2 = { -16.597, -10.060,-12.848 };
	parameterTypeModeStruct R2_E2(2, radius, typeModifierVariable);
	parameterTypeModeStruct R4_E2(4, radius, typeModifierVariable);
	parameterTypeModeStruct R6_E2(6, radius, typeModifierVariable);

	std::vector< parameterTypeModeStruct> parameterTypeModeVec_E2{ R2_E2,R4_E2,R6_E2 };
	std::vector<VectorStructR3> fieldsE2{ {0.0,0.0,0.0},{0.0,1.0,0.0},{0.0,2.0,0.0} };
	std::vector<real>wavelenghtVecE2{ wavelengths587,wavelengths486,wavelengths656 };

	// *** evaluate best optSys ***//
	if (testWhat == testAll || testWhat == testParaxial)
	{
		std::cout << "evaluate best optical system paraxial" << std::endl;
		// *** evaluate best optSys according to paraxial ray tracing ***//

		// time to get best optSys E2
		auto startE2_bestOptSys = std::chrono::system_clock::now();
		// calc the combination vectors
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E2_bestSys(/*optical System Element*/ optSystemElement_E2, /* add infos*/ addInfosVariable_E2, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		OpticalSystem_LLT bestOptSys_LLT = EvManOptSys_ParaDis_E2_bestSys.getBestOptSys();
		auto endE2_bestOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE2_bestOptSy = endE2_bestOptSys - startE2_bestOptSys;
		auto durationE2_bestOptSy_min = durationE2_bestOptSy.count() / 60.0;

		saveSystemData_bestOptSys_paraxial(optSysNum_E2, durationE2_bestOptSy_min, optSystemElement_E2, bestOptSys_LLT, EvManOptSys_ParaDis_E2_bestSys.getSystemsForCombination().getAllPosOptSys_LLT().size(), wavelengths587, fieldsE2, lightVec_E2, rmsZemax_E2, Var_vec_Zemax_E2, addInfosVariable_E2, parameterTypeModeVec_E2, locationToExportData, nameExcelFileBestSys_paraxial);

	}
	// *** --- ***//

	// evaluate the system according to seidel coef
	if (testWhat == testAll || testWhat == testSeidel)
	{
		std::cout << "evaluate best optical system seidel" << std::endl;

		// *** evaluate best optSys according to seidel coeff ***//
		//// time evaluate N best opt Sys
		auto startE2_N_besteOptSys = std::chrono::system_clock::now();
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E2_N_bestSys(/*optical System Element*/ optSystemElement_E2, /* add infos*/ addInfosVariable_E2, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		std::vector<OpticalSystem_LLT> N_bestOptSys_LLT = EvManOptSys_ParaDis_E2_N_bestSys.get_N_BestOptSys_LLT(50);
		auto endE2_N_besteOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE2_LLT_N_bestOptSys = endE2_N_besteOptSys - startE2_N_besteOptSys;
		auto durationE2_LLT_N_bestOptSys_min = durationE2_LLT_N_bestOptSys.count() / 60.0;

		//// time convert N best opt Sys to Element
		optSystemElement_E2.setRefractivIndexAccWave(optSystemElement_E2, wavelengths587);
		auto startE2_N_bestOptSys_convertEle = std::chrono::system_clock::now();
		std::vector<OpticalSystemElement> N_bestOptSys_Ele_E2 = EvManOptSys_ParaDis_E2_N_bestSys.convert_N_optSysLLT_To_elementSystems(N_bestOptSys_LLT, optSystemElement_E2);
		optSystemElement_E2.setRefractivIndexOptSysEle(N_bestOptSys_Ele_E2, wavelengths587);
		auto endE2_N_bestOptSys_convertEle = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE2_N_bestOptSys_convertEle = endE2_N_bestOptSys_convertEle - startE2_N_bestOptSys_convertEle;
		auto durationE2_N_bestOptSys_convertEle_min = durationE2_N_bestOptSys_convertEle.count() / 60.0;

		// evalute N best opt Sys Seidel

		auto startE2_N_bestOptSys_seidel = std::chrono::system_clock::now();
		EvaluateManyOptSystems_SeidelCoef evaluateE2_seidel(N_bestOptSys_Ele_E2, fieldsE2, wavelenghtVecE2);
		OpticalSystemElement bestOptSysEle_E2_seidel = evaluateE2_seidel.calcBestOptSys_OptSysVec();
		auto endE2_N_bestOptSys_seidel = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE2_N_bestOptSys_seidel = endE2_N_bestOptSys_seidel - startE2_N_bestOptSys_seidel;
		auto durationE2_N_bestOptSys_seidel_min = durationE2_N_bestOptSys_seidel.count() / 60.0;

		OpticalSystem_LLT bestOptSysE2_seidel = bestOptSysEle_E2_seidel.getLLTconversion_doConversion();
		bestOptSysE2_seidel.printAllOptSysParameter_LLT(bestOptSysE2_seidel);

		saveSystemData_bestOptSys_seidel(optSysNum_E2, durationE2_LLT_N_bestOptSys_min, durationE2_N_bestOptSys_convertEle_min, durationE2_N_bestOptSys_seidel_min, optSystemElement_E2, bestOptSysE2_seidel, EvManOptSys_ParaDis_E2_N_bestSys, wavelengths587, fieldsE2, lightVec_E2, rmsZemax_E2, Var_vec_Zemax_E2, addInfosVariable_E2, parameterTypeModeVec_E2, locationToExportData, nameExcelFileBestSys_seidel);

	}
	// *** --- ***//


	// evaluate the system according to ray tracing
	if (testWhat == testAll || testWhat == testRayTrac)
	{
		std::cout << "evaluate best optical system ray tracing" << std::endl;
		// *** evaluate best optSys according to real ray tracing ***//
		auto startE2_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		EvaluateManyOptSys_RayTracing evaluateE2_rayTracing(optSystemElement_E2, addInfosVariable_E2, fieldsE2, wavelenghtVecE2);
		OpticalSystemElement bestOptSysEle_E2_rayTracing = evaluateE2_rayTracing.getBestOptSys();
		auto end_E2_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE2_LLT_N_bestOptSys_rayTracing = end_E2_N_bestOptSys_rayTracing - startE2_N_bestOptSys_rayTracing;
		auto durationE2_LLT_N_bestOptSys_rayTracing_min = durationE2_LLT_N_bestOptSys_rayTracing.count() / 60.0;

		OpticalSystem_LLT bestOptSysE2_rayTracing = bestOptSysEle_E2_rayTracing.getLLTconversion_doConversion();
		bestOptSysE2_rayTracing.printAllOptSysParameter_LLT(bestOptSysE2_rayTracing);


		saveSystemData_bestOptSys_RayTracing(optSysNum_E2, durationE2_LLT_N_bestOptSys_rayTracing_min, optSystemElement_E2, bestOptSysE2_rayTracing, evaluateE2_rayTracing, wavelengths587, fieldsE2, lightVec_E2, rmsZemax_E2, Var_vec_Zemax_E2, addInfosVariable_E2, parameterTypeModeVec_E2, locationToExportData, nameExcelFileBestSys_rayTracing);

	}

	// check rms spot radius of initial system 
	SequentialRayTracing seqTraceE2_checker(optSystemElement_E2, { 0.0,0.0,0.0 }, 6, 8, 1.0, lightVec_E2);
	Spot spotE2(seqTraceE2_checker.getAllInterPointsAtSurf_i(9), seqTraceE2_checker.getAllInterPointsAtSurf_i(9).at(0));
	real rmsSpotE2 = spotE2.getRMS_µm();
	real excelBest_Zemax_RMS = 131.716;
	bool checkE2_rmsBest = Math::compareTwoNumbers_decimals(excelBest_Zemax_RMS, rmsSpotE2, 1);
	workTestSystemsPeterMA_E2.push_back(checkE2_rmsBest);
	// ***
	

	bool returnCheckerE2 = Math::checkTrueOfVectorElements(workTestSystemsPeterMA_E2);

	return returnCheckerE2;


}

bool testSystemsPeterMA::calcTestSystemPeterMA_E3(testWhatEnum testWhat)
{

	std::vector<bool> workTestSystemsPeterMA_E3;

	real optSysNum_E3 = 3;



	std::vector<real> exportDataE3_seidel;
	exportDataE3_seidel.push_back(optSysNum_E3);

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	// surfaces E3
	ApertureStopElement AperStop0_E3(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAirZemax());
	SphericalElement Sphere1_E3(/*radius*/ 80.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF3_S1(), /*refractive index B*/glasses.getAirZemax());
	SphericalElement Sphere2_E3(/*radius*/ 110.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF3_S1(), /*refractive index B*/glasses.getBK7_S1());
	SphericalElement Sphere3_E3(/*radius*/ 90.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getAirZemax());
	SphericalElement Sphere4_E3(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere5_E3(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getNSSK8_S1(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere6_E3(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getNSSK8_S1());
	SphericalElement Sphere7_E3(/*radius*/ 100.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF5_S1(), /*refractive index B*/glasses.getAirZemax());
	SphericalElement Sphere8_E3(/*radius*/ 100.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF5_S1(), /*refractive index B*/glasses.getAirZemax());
	SphericalElement Sphere9_E3(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere10_E3(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF57_S1(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere11_E3(/*radius*/ 35.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF57_S1());
	PlanElement Plan12_E3(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,115.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAirZemax(), /*refractive index B*/ glasses.getAirZemax());

	Sphere3_E3.setParameterPointZ(35.0, 85.0, 0.0, typeModifierVariable);
	Sphere6_E3.setParameterPointZ(55.0, 105.0, 0.0, typeModifierVariable);
	Sphere9_E3.setParameterRadius(-100.0, 100.0, 0.0, typeModifierVariable);



	surfacePtr Aper0_E3_ptr = AperStop0_E3.clone();
	surfacePtr Sphere1_E3_ptr = Sphere1_E3.clone();
	surfacePtr Sphere2_E3_ptr = Sphere2_E3.clone();
	surfacePtr Sphere3_E3_ptr = Sphere3_E3.clone();
	surfacePtr Sphere4_E3_ptr = Sphere4_E3.clone();
	surfacePtr Sphere5_E3_ptr = Sphere5_E3.clone();
	surfacePtr Sphere6_E3_ptr = Sphere6_E3.clone();
	surfacePtr Sphere7_E3_ptr = Sphere7_E3.clone();
	surfacePtr Sphere8_E3_ptr = Sphere8_E3.clone();
	surfacePtr Sphere9_E3_ptr = Sphere9_E3.clone();
	surfacePtr Sphere10_E3_ptr = Sphere10_E3.clone();
	surfacePtr Sphere11_E3_ptr = Sphere11_E3.clone();
	surfacePtr Plan12_E3_ptr = Plan12_E3.clone();

	std::vector<surfacePtr> opticalSystemE3_ptr{ Aper0_E3_ptr, Sphere1_E3_ptr, Sphere2_E3_ptr , Sphere3_E3_ptr, Sphere4_E3_ptr, Sphere5_E3_ptr, Sphere6_E3_ptr, Sphere7_E3_ptr, Sphere8_E3_ptr, Sphere9_E3_ptr, Sphere10_E3_ptr, Sphere11_E3_ptr, Plan12_E3_ptr };
	std::vector<interaction_ptr> interactionsE3_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E3(opticalSystemE3_ptr, interactionsE3_ptr);

	// light
	std::vector<Light_LLT> lightVec_E3;
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

	lightVec_E3.push_back(light0);
	lightVec_E3.push_back(light1);
	lightVec_E3.push_back(light2);

	// ***

	// Evaulate the system according to paraxial ray tracing
	// def steps variables
	stepsWithoutMinWithoutMax addInfosVarS3(/*surface num*/ 3, /*step size*/ 2, /*without min*/ -9.9, /*without max*/ 9.9);
	stepsWithoutMinWithoutMax addInfosVarS6(/*surface num*/ 6, /*step size*/ 4, /*without min*/ 0.0, /*without max*/ 0.0);
	stepsWithoutMinWithoutMax addInfosVarS9(/*surface num*/ 9, /*step size*/ 2, /*without min*/ -9.9, /*without max*/ 9.9);
	std::vector<stepsWithoutMinWithoutMax> addInfosVariable_E3{ addInfosVarS3,addInfosVarS6,addInfosVarS9 };

	// start ray
	StartRayPos startRayPos = notInfinity;

	std::vector<real> rmsZemax_E3 = { 48.482,60.820,128.369 };
	std::vector<real> Var_vec_Zemax_E3 = { 5.00,5.00,30.317 };
	parameterTypeModeStruct R2_E3(2, position, typeModifierVariable);
	parameterTypeModeStruct R5_E3(5, position, typeModifierVariable);
	parameterTypeModeStruct R9_E3(9, radius, typeModifierVariable);

	std::vector< parameterTypeModeStruct> parameterTypeModeVec_E3{ R2_E3,R5_E3,R9_E3 };
	std::vector<VectorStructR3> fieldsE3{ {0.0,0.0,0.0},{0.0,1.0,0.0},{0.0,2.0,0.0} };
	std::vector<real>wavelenghtVecE3{ wavelengths587,wavelengths486,wavelengths656 };

	// *** evaluate best optSys ***//
	if (testWhat == testAll || testWhat == testParaxial)
	{
		std::cout << "evaluate best optical system paraxial" << std::endl;
		// *** evaluate best optSys according to paraxial ray tracing ***//

		// time to get best optSys E3
		auto startE3_bestOptSys = std::chrono::system_clock::now();
		// calc the combination vectors
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E3_bestSys(/*optical System Element*/ optSystemElement_E3, /* add infos*/ addInfosVariable_E3, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		OpticalSystem_LLT bestOptSys_LLT = EvManOptSys_ParaDis_E3_bestSys.getBestOptSys();
		auto endE3_bestOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE3_bestOptSy = endE3_bestOptSys - startE3_bestOptSys;
		auto durationE3_bestOptSy_min = durationE3_bestOptSy.count() / 60.0;

		saveSystemData_bestOptSys_paraxial(optSysNum_E3, durationE3_bestOptSy_min, optSystemElement_E3, bestOptSys_LLT, EvManOptSys_ParaDis_E3_bestSys.getSystemsForCombination().getAllPosOptSys_LLT().size(), wavelengths587, fieldsE3, lightVec_E3, rmsZemax_E3, Var_vec_Zemax_E3, addInfosVariable_E3, parameterTypeModeVec_E3, locationToExportData, nameExcelFileBestSys_paraxial);

	}
	// *** --- ***//

	// evaluate the system according to seidel coef
	if (testWhat == testAll || testWhat == testSeidel)
	{
		std::cout << "evaluate best optical system seidel" << std::endl;

		// *** evaluate best optSys according to seidel coeff ***//
		//// time evaluate N best opt Sys
		auto startE3_N_besteOptSys = std::chrono::system_clock::now();
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E3_N_bestSys(/*optical System Element*/ optSystemElement_E3, /* add infos*/ addInfosVariable_E3, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		std::vector<OpticalSystem_LLT> N_bestOptSys_LLT = EvManOptSys_ParaDis_E3_N_bestSys.get_N_BestOptSys_LLT(50);
		auto endE3_N_besteOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE3_LLT_N_bestOptSys = endE3_N_besteOptSys - startE3_N_besteOptSys;
		auto durationE3_LLT_N_bestOptSys_min = durationE3_LLT_N_bestOptSys.count() / 60.0;

		//// time convert N best opt Sys to Element
		optSystemElement_E3.setRefractivIndexAccWave(optSystemElement_E3, wavelengths587);
		auto startE3_N_bestOptSys_convertEle = std::chrono::system_clock::now();
		std::vector<OpticalSystemElement> N_bestOptSys_Ele_E3 = EvManOptSys_ParaDis_E3_N_bestSys.convert_N_optSysLLT_To_elementSystems(N_bestOptSys_LLT, optSystemElement_E3);
		optSystemElement_E3.setRefractivIndexOptSysEle(N_bestOptSys_Ele_E3, wavelengths587);
		auto endE3_N_bestOptSys_convertEle = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE3_N_bestOptSys_convertEle = endE3_N_bestOptSys_convertEle - startE3_N_bestOptSys_convertEle;
		auto durationE3_N_bestOptSys_convertEle_min = durationE3_N_bestOptSys_convertEle.count() / 60.0;

		// evalute N best opt Sys Seidel

		auto startE3_N_bestOptSys_seidel = std::chrono::system_clock::now();
		EvaluateManyOptSystems_SeidelCoef evaluateE3_seidel(N_bestOptSys_Ele_E3, fieldsE3, wavelenghtVecE3);
		OpticalSystemElement bestOptSysEle_E3_seidel = evaluateE3_seidel.calcBestOptSys_OptSysVec();
		auto endE3_N_bestOptSys_seidel = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE3_N_bestOptSys_seidel = endE3_N_bestOptSys_seidel - startE3_N_bestOptSys_seidel;
		auto durationE3_N_bestOptSys_seidel_min = durationE3_N_bestOptSys_seidel.count() / 60.0;

		OpticalSystem_LLT bestOptSysE3_seidel = bestOptSysEle_E3_seidel.getLLTconversion_doConversion();
		bestOptSysE3_seidel.printAllOptSysParameter_LLT(bestOptSysE3_seidel);

		saveSystemData_bestOptSys_seidel(optSysNum_E3, durationE3_LLT_N_bestOptSys_min, durationE3_N_bestOptSys_convertEle_min, durationE3_N_bestOptSys_seidel_min, optSystemElement_E3, bestOptSysE3_seidel, EvManOptSys_ParaDis_E3_N_bestSys, wavelengths587, fieldsE3, lightVec_E3, rmsZemax_E3, Var_vec_Zemax_E3, addInfosVariable_E3, parameterTypeModeVec_E3, locationToExportData, nameExcelFileBestSys_seidel);

	}
	// *** --- ***//


	// evaluate the system according to ray tracing
	if (testWhat == testAll || testWhat == testRayTrac)
	{
		std::cout << "evaluate best optical system ray tracing" << std::endl;
		// *** evaluate best optSys according to real ray tracing ***//
		auto startE3_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		EvaluateManyOptSys_RayTracing evaluateE3_rayTracing(optSystemElement_E3, addInfosVariable_E3, fieldsE3, wavelenghtVecE3);
		OpticalSystemElement bestOptSysEle_E3_rayTracing = evaluateE3_rayTracing.getBestOptSys();
		auto end_E3_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE3_LLT_N_bestOptSys_rayTracing = end_E3_N_bestOptSys_rayTracing - startE3_N_bestOptSys_rayTracing;
		auto durationE3_LLT_N_bestOptSys_rayTracing_min = durationE3_LLT_N_bestOptSys_rayTracing.count() / 60.0;

		OpticalSystem_LLT bestOptSysE3_rayTracing = bestOptSysEle_E3_rayTracing.getLLTconversion_doConversion();
		bestOptSysE3_rayTracing.printAllOptSysParameter_LLT(bestOptSysE3_rayTracing);


		saveSystemData_bestOptSys_RayTracing(optSysNum_E3, durationE3_LLT_N_bestOptSys_rayTracing_min, optSystemElement_E3, bestOptSysE3_rayTracing, evaluateE3_rayTracing, wavelengths587, fieldsE3, lightVec_E3, rmsZemax_E3, Var_vec_Zemax_E3, addInfosVariable_E3, parameterTypeModeVec_E3, locationToExportData, nameExcelFileBestSys_rayTracing);

	}

	// check rms spot radius of initial system 
	SequentialRayTracing seqTraceE3_checker(optSystemElement_E3, { 0.0,0.0,0.0 }, 6, 8, 1.0, lightVec_E3);
	Spot spotE3(seqTraceE3_checker.getAllInterPointsAtSurf_i(12), seqTraceE3_checker.getAllInterPointsAtSurf_i(12).at(0));
	real rmsSpotE3 = spotE3.getRMS_µm();
	real excelBest_Zemax_RMS = 316.664;
	bool checkE3_rmsBest = Math::compareTwoNumbers_decimals(excelBest_Zemax_RMS, rmsSpotE3, 1);
	workTestSystemsPeterMA_E3.push_back(checkE3_rmsBest);
	// ***
	

	bool returnCheckerE3 = Math::checkTrueOfVectorElements(workTestSystemsPeterMA_E3);

	return returnCheckerE3;


}

bool testSystemsPeterMA::calcTestSystemPeterMA_E4(testWhatEnum testWhat)
{

	std::vector<bool> workTestSystemsPeterMA_E4;

	real optSysNum_E4 = 4;



	std::vector<real> exportDataE4_seidel;
	exportDataE4_seidel.push_back(optSysNum_E4);

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	// surfaces E4
	ApertureStopElement AperStop0_E4(/* semi height*/1.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAirZemax());
	SphericalElement Sphere1_E4(/*radius*/ 60.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF3_S1());
	SphericalElement Sphere2_E4(/*radius*/ 70.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getSF3_S1());
	SphericalElement Sphere3_E4(/*radius*/ 50.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBK7_S1());
	SphericalElement Sphere4_E4(/*radius*/ 200.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBAFN10_S1(), /*refractive index B*/glasses.getAirZemax());
	SphericalElement Sphere5_E4(/*radius*/ 150.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getBAFN10_S1(), /*refractive index B*/glasses.getAirZemax());
	SphericalElement Sphere6_E4(/*radius*/ 50.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere7_E4(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere8_E4(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBK7_S1());
	PlanElement Plan9_E4(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,100.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAirZemax(), /*refractive index B*/ glasses.getAirZemax());

	Sphere4_E4.setParameterPointZ(40.0, 130.0, 0.0, typeModifierVariable);
	Sphere6_E4.setParameterPointZ(50.0, 100.0, 0.0, typeModifierVariable);
	Sphere8_E4.setParameterRadius(-100.0, 100.0, 0.0, typeModifierVariable);

	surfacePtr Aper0_E4_ptr = AperStop0_E4.clone();
	surfacePtr Sphere1_E4_ptr = Sphere1_E4.clone();
	surfacePtr Sphere2_E4_ptr = Sphere2_E4.clone();
	surfacePtr Sphere3_E4_ptr = Sphere3_E4.clone();
	surfacePtr Sphere4_E4_ptr = Sphere4_E4.clone();
	surfacePtr Sphere5_E4_ptr = Sphere5_E4.clone();
	surfacePtr Sphere6_E4_ptr = Sphere6_E4.clone();
	surfacePtr Sphere7_E4_ptr = Sphere7_E4.clone();
	surfacePtr Sphere8_E4_ptr = Sphere8_E4.clone();
	surfacePtr Plan9_E4_ptr = Plan9_E4.clone();

	std::vector<surfacePtr> opticalSystemE4_ptr{ Aper0_E4_ptr, Sphere1_E4_ptr, Sphere2_E4_ptr , Sphere3_E4_ptr, Sphere4_E4_ptr, Sphere5_E4_ptr, Sphere6_E4_ptr, Sphere7_E4_ptr, Sphere8_E4_ptr, Plan9_E4_ptr };
	std::vector<interaction_ptr> interactionsE4_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),refrac.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E4(opticalSystemE4_ptr, interactionsE4_ptr);

	// light
	std::vector<Light_LLT> lightVec_E4;
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

	lightVec_E4.push_back(light0);
	lightVec_E4.push_back(light1);
	lightVec_E4.push_back(light2);

	// ***

	// Evaulate the system according to paraxial ray tracing
	// def steps variables
	stepsWithoutMinWithoutMax addInfosVarS4(/*surface num*/ 4, /*step size*/ 2, /*without min*/ 0.0, /*without max*/ 0.0);
	stepsWithoutMinWithoutMax addInfosVarS6(/*surface num*/ 6, /*step size*/ 4, /*without min*/ 0.0, /*without max*/ 0.0);
	stepsWithoutMinWithoutMax addInfosVarS8(/*surface num*/ 8, /*step size*/ 2, /*without min*/ -9.9, /*without max*/ 9.9);
	std::vector<stepsWithoutMinWithoutMax> addInfosVariable_E4{ addInfosVarS4,addInfosVarS6,addInfosVarS8 };

	// start ray
	StartRayPos startRayPos = notInfinity;

	std::vector<real> rmsZemax_E4 = { 37.241,47.714,81.155 };
	std::vector<real> Var_vec_Zemax_E4 = { 5.006, 4.9998,-20.8467 };
	parameterTypeModeStruct D4_E4(4, position, typeModifierVariable);
	parameterTypeModeStruct D6_E4(6, position, typeModifierVariable);
	parameterTypeModeStruct R8_E4(7, radius, typeModifierVariable);

	std::vector< parameterTypeModeStruct> parameterTypeModeVec_E4{ D4_E4,D6_E4,R8_E4 };
	std::vector<VectorStructR3> fieldsE4{ {0.0,0.0,0.0},{0.0,1.0,0.0},{0.0,2.0,0.0} };
	std::vector<real>wavelenghtVecE4{ wavelengths587,wavelengths486,wavelengths656 };

	// *** evaluate best optSys ***//
	if (testWhat == testAll || testWhat == testParaxial)
	{
		std::cout << "evaluate best optical system paraxial" << std::endl;
		// *** evaluate best optSys according to paraxial ray tracing ***//

		// time to get best optSys E4
		auto startE4_bestOptSys = std::chrono::system_clock::now();
		// calc the combination vectors
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E4_bestSys(/*optical System Element*/ optSystemElement_E4, /* add infos*/ addInfosVariable_E4, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		OpticalSystem_LLT bestOptSys_LLT = EvManOptSys_ParaDis_E4_bestSys.getBestOptSys();
		auto endE4_bestOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE4_bestOptSy = endE4_bestOptSys - startE4_bestOptSys;
		auto durationE4_bestOptSy_min = durationE4_bestOptSy.count() / 60.0;

		saveSystemData_bestOptSys_paraxial(optSysNum_E4, durationE4_bestOptSy_min, optSystemElement_E4, bestOptSys_LLT, EvManOptSys_ParaDis_E4_bestSys.getSystemsForCombination().getAllPosOptSys_LLT().size(), wavelengths587, fieldsE4, lightVec_E4, rmsZemax_E4, Var_vec_Zemax_E4, addInfosVariable_E4, parameterTypeModeVec_E4, locationToExportData, nameExcelFileBestSys_paraxial);

	}
	// *** --- ***//

	// evaluate the system according to seidel coef
	if (testWhat == testAll || testWhat == testSeidel)
	{
		std::cout << "evaluate best optical system seidel" << std::endl;

		// *** evaluate best optSys according to seidel coeff ***//
		//// time evaluate N best opt Sys
		auto startE4_N_besteOptSys = std::chrono::system_clock::now();
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E4_N_bestSys(/*optical System Element*/ optSystemElement_E4, /* add infos*/ addInfosVariable_E4, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		std::vector<OpticalSystem_LLT> N_bestOptSys_LLT = EvManOptSys_ParaDis_E4_N_bestSys.get_N_BestOptSys_LLT(50);
		auto endE4_N_besteOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE4_LLT_N_bestOptSys = endE4_N_besteOptSys - startE4_N_besteOptSys;
		auto durationE4_LLT_N_bestOptSys_min = durationE4_LLT_N_bestOptSys.count() / 60.0;

		//// time convert N best opt Sys to Element
		optSystemElement_E4.setRefractivIndexAccWave(optSystemElement_E4, wavelengths587);
		auto startE4_N_bestOptSys_convertEle = std::chrono::system_clock::now();
		std::vector<OpticalSystemElement> N_bestOptSys_Ele_E4 = EvManOptSys_ParaDis_E4_N_bestSys.convert_N_optSysLLT_To_elementSystems(N_bestOptSys_LLT, optSystemElement_E4);
		optSystemElement_E4.setRefractivIndexOptSysEle(N_bestOptSys_Ele_E4, wavelengths587);
		auto endE4_N_bestOptSys_convertEle = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE4_N_bestOptSys_convertEle = endE4_N_bestOptSys_convertEle - startE4_N_bestOptSys_convertEle;
		auto durationE4_N_bestOptSys_convertEle_min = durationE4_N_bestOptSys_convertEle.count() / 60.0;

		// evalute N best opt Sys Seidel

		auto startE4_N_bestOptSys_seidel = std::chrono::system_clock::now();
		EvaluateManyOptSystems_SeidelCoef evaluateE4_seidel(N_bestOptSys_Ele_E4, fieldsE4, wavelenghtVecE4);
		OpticalSystemElement bestOptSysEle_E4_seidel = evaluateE4_seidel.calcBestOptSys_OptSysVec();
		auto endE4_N_bestOptSys_seidel = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE4_N_bestOptSys_seidel = endE4_N_bestOptSys_seidel - startE4_N_bestOptSys_seidel;
		auto durationE4_N_bestOptSys_seidel_min = durationE4_N_bestOptSys_seidel.count() / 60.0;

		OpticalSystem_LLT bestOptSysE4_seidel = bestOptSysEle_E4_seidel.getLLTconversion_doConversion();
		bestOptSysE4_seidel.printAllOptSysParameter_LLT(bestOptSysE4_seidel);

		saveSystemData_bestOptSys_seidel(optSysNum_E4, durationE4_LLT_N_bestOptSys_min, durationE4_N_bestOptSys_convertEle_min, durationE4_N_bestOptSys_seidel_min, optSystemElement_E4, bestOptSysE4_seidel, EvManOptSys_ParaDis_E4_N_bestSys, wavelengths587, fieldsE4, lightVec_E4, rmsZemax_E4, Var_vec_Zemax_E4, addInfosVariable_E4, parameterTypeModeVec_E4, locationToExportData, nameExcelFileBestSys_seidel);

	}
	// *** --- ***//


	// evaluate the system according to ray tracing
	if (testWhat == testAll || testWhat == testRayTrac)
	{
		std::cout << "evaluate best optical system ray tracing" << std::endl;
		// *** evaluate best optSys according to real ray tracing ***//
		auto startE4_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		EvaluateManyOptSys_RayTracing evaluateE4_rayTracing(optSystemElement_E4, addInfosVariable_E4, fieldsE4, wavelenghtVecE4);
		OpticalSystemElement bestOptSysEle_E4_rayTracing = evaluateE4_rayTracing.getBestOptSys();
		auto end_E4_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE4_LLT_N_bestOptSys_rayTracing = end_E4_N_bestOptSys_rayTracing - startE4_N_bestOptSys_rayTracing;
		auto durationE4_LLT_N_bestOptSys_rayTracing_min = durationE4_LLT_N_bestOptSys_rayTracing.count() / 60.0;

		OpticalSystem_LLT bestOptSysE4_rayTracing = bestOptSysEle_E4_rayTracing.getLLTconversion_doConversion();
		bestOptSysE4_rayTracing.printAllOptSysParameter_LLT(bestOptSysE4_rayTracing);


		saveSystemData_bestOptSys_RayTracing(optSysNum_E4, durationE4_LLT_N_bestOptSys_rayTracing_min, optSystemElement_E4, bestOptSysE4_rayTracing, evaluateE4_rayTracing, wavelengths587, fieldsE4, lightVec_E4, rmsZemax_E4, Var_vec_Zemax_E4, addInfosVariable_E4, parameterTypeModeVec_E4, locationToExportData, nameExcelFileBestSys_rayTracing);

	}

	// check rms spot radius of initial system 
	SequentialRayTracing seqTraceE4_checker(optSystemElement_E4, { 0.0,0.0,0.0 }, 6, 8, 1.0, lightVec_E4);
	Spot spotE4(seqTraceE4_checker.getAllInterPointsAtSurf_i(9), seqTraceE4_checker.getAllInterPointsAtSurf_i(9).at(0));
	real rmsSpotE4 = spotE4.getRMS_µm();
	real excelBest_Zemax_RMS = 281.402;
	bool checkE4_rmsBest = Math::compareTwoNumbers_decimals(excelBest_Zemax_RMS, rmsSpotE4, 1);
	workTestSystemsPeterMA_E4.push_back(checkE4_rmsBest);
	// ***
	
	bool returnCheckerE4 = Math::checkTrueOfVectorElements(workTestSystemsPeterMA_E4);

	return returnCheckerE4;


}

bool testSystemsPeterMA::calcTestSystemPeterMA_E5(testWhatEnum testWhat)
{

	std::vector<bool> workTestSystemsPeterMA_E5;

	real optSysNum_E5 = 5;



	std::vector<real> exportDataE5_seidel;
	exportDataE5_seidel.push_back(optSysNum_E5);

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	// surfaces E5
	ApertureStopElement AperStop0_E5(/* semi height*/1.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAirZemax());
	SphericalElement Sphere1_E5(/*radius*/ 80.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere2_E5(/*radius*/ 70.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBAFN10_S1());
	SphericalElement Sphere3_E5(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere4_E5(/*radius*/ 35.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere5_E5(/*radius*/ 20.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBK7_S1());
	PlanElement Plan6_E5(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,70.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAirZemax(), /*refractive index B*/ glasses.getAirZemax());

	Sphere3_E5.setParameterPointZ(25.0, 75.0, 0.0, typeModifierVariable);
	Sphere3_E5.setParameterRadius(-100.0, 100.0, 0.0, typeModifierVariable);
	Sphere5_E5.setParameterPointZ(40.0, 90.0, 0.0, typeModifierVariable);

	surfacePtr Aper0_E5_ptr = AperStop0_E5.clone();
	surfacePtr Sphere1_E5_ptr = Sphere1_E5.clone();
	surfacePtr Sphere2_E5_ptr = Sphere2_E5.clone();
	surfacePtr Sphere3_E5_ptr = Sphere3_E5.clone();
	surfacePtr Sphere4_E5_ptr = Sphere4_E5.clone();
	surfacePtr Sphere5_E5_ptr = Sphere5_E5.clone();
	surfacePtr Plan6_E5_ptr = Plan6_E5.clone();

	std::vector<surfacePtr> opticalSystemE5_ptr{ Aper0_E5_ptr, Sphere1_E5_ptr, Sphere2_E5_ptr , Sphere3_E5_ptr, Sphere4_E5_ptr, Sphere5_E5_ptr,  Plan6_E5_ptr };
	std::vector<interaction_ptr> interactionsE5_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E5(opticalSystemE5_ptr, interactionsE5_ptr);

	// light
	std::vector<Light_LLT> lightVec_E5;
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

	lightVec_E5.push_back(light0);
	lightVec_E5.push_back(light1);
	lightVec_E5.push_back(light2);

	// ***

	// Evaulate the system according to paraxial ray tracing
	// def steps variables
	stepsWithoutMinWithoutMax addInfosVarS3p(/*surface num*/ 3, /*step size*/ 2, /*without min*/ 0.0, /*without max*/ 0.0);
	stepsWithoutMinWithoutMax addInfosVarS3(/*surface num*/ 3, /*step size*/ 4, /*without min*/ -9.9, /*without max*/ 9.9);
	stepsWithoutMinWithoutMax addInfosVarS5(/*surface num*/ 5, /*step size*/ 2, /*without min*/ 0.0, /*without max*/ 0.0);
	std::vector<stepsWithoutMinWithoutMax> addInfosVariable_E5{ addInfosVarS3p,addInfosVarS3,addInfosVarS5 };

	// start ray
	StartRayPos startRayPos = notInfinity;

	std::vector<real> rmsZemax_E5 = { 95.983,102.791,221.645 };
	std::vector<real> Var_vec_Zemax_E5 = { 4.9975, 21.7176,23.8076 };
	parameterTypeModeStruct D3_E5(3, position, typeModifierVariable);
	parameterTypeModeStruct R3_E5(3, radius, typeModifierVariable);
	parameterTypeModeStruct R5_E5(5, position, typeModifierVariable);

	std::vector< parameterTypeModeStruct> parameterTypeModeVec_E5{ D3_E5,R3_E5,R5_E5 };
	std::vector<VectorStructR3> fieldsE5{ {0.0,0.0,0.0},{0.0,1.0,0.0},{0.0,2.0,0.0} };
	std::vector<real>wavelenghtVecE5{ wavelengths587,wavelengths486,wavelengths656 };

	// *** evaluate best optSys ***//
	if (testWhat == testAll || testWhat == testParaxial)
	{
		std::cout << "evaluate best optical system paraxial" << std::endl;
		// *** evaluate best optSys according to paraxial ray tracing ***//

		// time to get best optSys E5
		auto startE5_bestOptSys = std::chrono::system_clock::now();
		// calc the combination vectors
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E5_bestSys(/*optical System Element*/ optSystemElement_E5, /* add infos*/ addInfosVariable_E5, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		OpticalSystem_LLT bestOptSys_LLT = EvManOptSys_ParaDis_E5_bestSys.getBestOptSys();
		auto endE5_bestOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE5_bestOptSy = endE5_bestOptSys - startE5_bestOptSys;
		auto durationE5_bestOptSy_min = durationE5_bestOptSy.count() / 60.0;

		saveSystemData_bestOptSys_paraxial(optSysNum_E5, durationE5_bestOptSy_min, optSystemElement_E5, bestOptSys_LLT, EvManOptSys_ParaDis_E5_bestSys.getSystemsForCombination().getAllPosOptSys_LLT().size(), wavelengths587, fieldsE5, lightVec_E5, rmsZemax_E5, Var_vec_Zemax_E5, addInfosVariable_E5, parameterTypeModeVec_E5, locationToExportData, nameExcelFileBestSys_paraxial);

	}
	// *** --- ***//

	// evaluate the system according to seidel coef
	if (testWhat == testAll || testWhat == testSeidel)
	{
		std::cout << "evaluate best optical system seidel" << std::endl;

		// *** evaluate best optSys according to seidel coeff ***//
		//// time evaluate N best opt Sys
		auto startE5_N_besteOptSys = std::chrono::system_clock::now();
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E5_N_bestSys(/*optical System Element*/ optSystemElement_E5, /* add infos*/ addInfosVariable_E5, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		std::vector<OpticalSystem_LLT> N_bestOptSys_LLT = EvManOptSys_ParaDis_E5_N_bestSys.get_N_BestOptSys_LLT(50);
		auto endE5_N_besteOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE5_LLT_N_bestOptSys = endE5_N_besteOptSys - startE5_N_besteOptSys;
		auto durationE5_LLT_N_bestOptSys_min = durationE5_LLT_N_bestOptSys.count() / 60.0;

		//// time convert N best opt Sys to Element
		optSystemElement_E5.setRefractivIndexAccWave(optSystemElement_E5, wavelengths587);
		auto startE5_N_bestOptSys_convertEle = std::chrono::system_clock::now();
		std::vector<OpticalSystemElement> N_bestOptSys_Ele_E5 = EvManOptSys_ParaDis_E5_N_bestSys.convert_N_optSysLLT_To_elementSystems(N_bestOptSys_LLT, optSystemElement_E5);
		optSystemElement_E5.setRefractivIndexOptSysEle(N_bestOptSys_Ele_E5, wavelengths587);
		auto endE5_N_bestOptSys_convertEle = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE5_N_bestOptSys_convertEle = endE5_N_bestOptSys_convertEle - startE5_N_bestOptSys_convertEle;
		auto durationE5_N_bestOptSys_convertEle_min = durationE5_N_bestOptSys_convertEle.count() / 60.0;

		// evalute N best opt Sys Seidel

		auto startE5_N_bestOptSys_seidel = std::chrono::system_clock::now();
		EvaluateManyOptSystems_SeidelCoef evaluateE5_seidel(N_bestOptSys_Ele_E5, fieldsE5, wavelenghtVecE5);
		OpticalSystemElement bestOptSysEle_E5_seidel = evaluateE5_seidel.calcBestOptSys_OptSysVec();
		auto endE5_N_bestOptSys_seidel = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE5_N_bestOptSys_seidel = endE5_N_bestOptSys_seidel - startE5_N_bestOptSys_seidel;
		auto durationE5_N_bestOptSys_seidel_min = durationE5_N_bestOptSys_seidel.count() / 60.0;

		OpticalSystem_LLT bestOptSysE5_seidel = bestOptSysEle_E5_seidel.getLLTconversion_doConversion();
		bestOptSysE5_seidel.printAllOptSysParameter_LLT(bestOptSysE5_seidel);

		saveSystemData_bestOptSys_seidel(optSysNum_E5, durationE5_LLT_N_bestOptSys_min, durationE5_N_bestOptSys_convertEle_min, durationE5_N_bestOptSys_seidel_min, optSystemElement_E5, bestOptSysE5_seidel, EvManOptSys_ParaDis_E5_N_bestSys, wavelengths587, fieldsE5, lightVec_E5, rmsZemax_E5, Var_vec_Zemax_E5, addInfosVariable_E5, parameterTypeModeVec_E5, locationToExportData, nameExcelFileBestSys_seidel);

	}
	// *** --- ***//


	// evaluate the system according to ray tracing
	if (testWhat == testAll || testWhat == testRayTrac)
	{
		std::cout << "evaluate best optical system ray tracing" << std::endl;
		// *** evaluate best optSys according to real ray tracing ***//
		auto startE5_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		EvaluateManyOptSys_RayTracing evaluateE5_rayTracing(optSystemElement_E5, addInfosVariable_E5, fieldsE5, wavelenghtVecE5);
		OpticalSystemElement bestOptSysEle_E5_rayTracing = evaluateE5_rayTracing.getBestOptSys();
		auto end_E5_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE5_LLT_N_bestOptSys_rayTracing = end_E5_N_bestOptSys_rayTracing - startE5_N_bestOptSys_rayTracing;
		auto durationE5_LLT_N_bestOptSys_rayTracing_min = durationE5_LLT_N_bestOptSys_rayTracing.count() / 60.0;

		OpticalSystem_LLT bestOptSysE5_rayTracing = bestOptSysEle_E5_rayTracing.getLLTconversion_doConversion();
		bestOptSysE5_rayTracing.printAllOptSysParameter_LLT(bestOptSysE5_rayTracing);


		saveSystemData_bestOptSys_RayTracing(optSysNum_E5, durationE5_LLT_N_bestOptSys_rayTracing_min, optSystemElement_E5, bestOptSysE5_rayTracing, evaluateE5_rayTracing, wavelengths587, fieldsE5, lightVec_E5, rmsZemax_E5, Var_vec_Zemax_E5, addInfosVariable_E5, parameterTypeModeVec_E5, locationToExportData, nameExcelFileBestSys_rayTracing);

	}

	// check rms spot radius of initial system 
	SequentialRayTracing seqTraceE5_checker(optSystemElement_E5, { 0.0,0.0,0.0 }, 6, 8, 1.0, lightVec_E5);
	Spot spotE5(seqTraceE5_checker.getAllInterPointsAtSurf_i(6), seqTraceE5_checker.getAllInterPointsAtSurf_i(6).at(0));
	real rmsSpotE5 = spotE5.getRMS_µm();
	real excelBest_Zemax_RMS = 382.642;
	bool checkE5_rmsBest = Math::compareTwoNumbers_decimals(excelBest_Zemax_RMS, rmsSpotE5, 1);
	workTestSystemsPeterMA_E5.push_back(checkE5_rmsBest);
	// ***
	
	bool returnCheckerE5 = Math::checkTrueOfVectorElements(workTestSystemsPeterMA_E5);

	return returnCheckerE5;


}

bool testSystemsPeterMA::calcTestSystemPeterMA_E6(testWhatEnum testWhat)
{

	std::vector<bool> workTestSystemsPeterMA_E6;

	real optSysNum_E6 = 6;



	std::vector<real> exportDataE6_seidel;
	exportDataE6_seidel.push_back(optSysNum_E6);

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	// surfaces E6
	ApertureStopElement AperStop0_E6(/* semi height*/2.0, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAirZemax());
	SphericalElement Sphere1_E6(/*radius*/ 20.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere2_E6(/*radius*/ 20.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getSF6_S1());
	SphericalElement Sphere3_E6(/*radius*/ 20.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBK7_S1());
	PlanElement Plan4_E6(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,65.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAirZemax(), /*refractive index B*/ glasses.getAirZemax());

	Sphere1_E6.setParameterRadius(-100.0, 100.0, 0.0, typeModifierVariable);
	Sphere2_E6.setParameterRadius(-100.0, 100.0, 0.0, typeModifierVariable);
	Sphere3_E6.setParameterRadius(-100.0, 100.0, 0.0, typeModifierVariable);

	surfacePtr Aper0_E6_ptr = AperStop0_E6.clone();
	surfacePtr Sphere1_E6_ptr = Sphere1_E6.clone();
	surfacePtr Sphere2_E6_ptr = Sphere2_E6.clone();
	surfacePtr Sphere3_E6_ptr = Sphere3_E6.clone();
	surfacePtr Plan4_E6_ptr = Plan4_E6.clone();

	std::vector<surfacePtr> opticalSystemE6_ptr{ Aper0_E6_ptr, Sphere1_E6_ptr, Sphere2_E6_ptr , Sphere3_E6_ptr, Plan4_E6_ptr };
	std::vector<interaction_ptr> interactionsE6_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E6(opticalSystemE6_ptr, interactionsE6_ptr);


	// light
	std::vector<Light_LLT> lightVec_E6;
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

	lightVec_E6.push_back(light0);
	lightVec_E6.push_back(light1);
	lightVec_E6.push_back(light2);

	// ***

	// Evaulate the system according to paraxial ray tracing
	// def steps variables
	stepsWithoutMinWithoutMax addInfosVarS1(/*surface num*/ 1, /*step size*/ 2, /*without min*/ -9.9, /*without max*/ 9.9);
	stepsWithoutMinWithoutMax addInfosVarS2(/*surface num*/ 2, /*step size*/ 4, /*without min*/ -9.9, /*without max*/ 9.9);
	stepsWithoutMinWithoutMax addInfosVarS3(/*surface num*/ 3, /*step size*/ 2, /*without min*/ -9.9, /*without max*/ 9.9);
	std::vector<stepsWithoutMinWithoutMax> addInfosVariable_E6{ addInfosVarS1,addInfosVarS2,addInfosVarS3 };

	// start ray
	StartRayPos startRayPos = notInfinity;

	std::vector<real> rmsZemax_E6 = { 180.934,274.870,522.845 };
	std::vector<real> Var_vec_Zemax_E6 = { 23.433, -12.356,-16.040 };
	parameterTypeModeStruct R1_E6(1, radius, typeModifierVariable);
	parameterTypeModeStruct R2_E6(2, radius, typeModifierVariable);
	parameterTypeModeStruct R3_E6(3, radius, typeModifierVariable);

	std::vector< parameterTypeModeStruct> parameterTypeModeVec_E6{ R1_E6,R2_E6,R3_E6 };
	std::vector<VectorStructR3> fieldsE6{ {0.0,0.0,0.0},{0.0,1.0,0.0},{0.0,2.0,0.0} };
	std::vector<real>wavelenghtVecE6{ wavelengths587,wavelengths486,wavelengths656 };

	// *** evaluate best optSys ***//
	if (testWhat == testAll || testWhat == testParaxial)
	{
		std::cout << "evaluate best optical system paraxial" << std::endl;
		// *** evaluate best optSys according to paraxial ray tracing ***//

		// time to get best optSys E6
		auto startE6_bestOptSys = std::chrono::system_clock::now();
		// calc the combination vectors
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E6_bestSys(/*optical System Element*/ optSystemElement_E6, /* add infos*/ addInfosVariable_E6, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		OpticalSystem_LLT bestOptSys_LLT = EvManOptSys_ParaDis_E6_bestSys.getBestOptSys();
		auto endE6_bestOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE6_bestOptSy = endE6_bestOptSys - startE6_bestOptSys;
		auto durationE6_bestOptSy_min = durationE6_bestOptSy.count() / 60.0;

		saveSystemData_bestOptSys_paraxial(optSysNum_E6, durationE6_bestOptSy_min, optSystemElement_E6, bestOptSys_LLT, EvManOptSys_ParaDis_E6_bestSys.getSystemsForCombination().getAllPosOptSys_LLT().size(), wavelengths587, fieldsE6, lightVec_E6, rmsZemax_E6, Var_vec_Zemax_E6, addInfosVariable_E6, parameterTypeModeVec_E6, locationToExportData, nameExcelFileBestSys_paraxial);

	}
	// *** --- ***//

	// evaluate the system according to seidel coef
	if (testWhat == testAll || testWhat == testSeidel)
	{
		std::cout << "evaluate best optical system seidel" << std::endl;

		// *** evaluate best optSys according to seidel coeff ***//
		//// time evaluate N best opt Sys
		auto startE6_N_besteOptSys = std::chrono::system_clock::now();
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E6_N_bestSys(/*optical System Element*/ optSystemElement_E6, /* add infos*/ addInfosVariable_E6, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		std::vector<OpticalSystem_LLT> N_bestOptSys_LLT = EvManOptSys_ParaDis_E6_N_bestSys.get_N_BestOptSys_LLT(50);
		auto endE6_N_besteOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE6_LLT_N_bestOptSys = endE6_N_besteOptSys - startE6_N_besteOptSys;
		auto durationE6_LLT_N_bestOptSys_min = durationE6_LLT_N_bestOptSys.count() / 60.0;

		//// time convert N best opt Sys to Element
		optSystemElement_E6.setRefractivIndexAccWave(optSystemElement_E6, wavelengths587);
		auto startE6_N_bestOptSys_convertEle = std::chrono::system_clock::now();
		std::vector<OpticalSystemElement> N_bestOptSys_Ele_E6 = EvManOptSys_ParaDis_E6_N_bestSys.convert_N_optSysLLT_To_elementSystems(N_bestOptSys_LLT, optSystemElement_E6);
		optSystemElement_E6.setRefractivIndexOptSysEle(N_bestOptSys_Ele_E6, wavelengths587);
		auto endE6_N_bestOptSys_convertEle = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE6_N_bestOptSys_convertEle = endE6_N_bestOptSys_convertEle - startE6_N_bestOptSys_convertEle;
		auto durationE6_N_bestOptSys_convertEle_min = durationE6_N_bestOptSys_convertEle.count() / 60.0;

		// evalute N best opt Sys Seidel

		auto startE6_N_bestOptSys_seidel = std::chrono::system_clock::now();
		EvaluateManyOptSystems_SeidelCoef evaluateE6_seidel(N_bestOptSys_Ele_E6, fieldsE6, wavelenghtVecE6);
		OpticalSystemElement bestOptSysEle_E6_seidel = evaluateE6_seidel.calcBestOptSys_OptSysVec();
		auto endE6_N_bestOptSys_seidel = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE6_N_bestOptSys_seidel = endE6_N_bestOptSys_seidel - startE6_N_bestOptSys_seidel;
		auto durationE6_N_bestOptSys_seidel_min = durationE6_N_bestOptSys_seidel.count() / 60.0;

		OpticalSystem_LLT bestOptSysE6_seidel = bestOptSysEle_E6_seidel.getLLTconversion_doConversion();
		bestOptSysE6_seidel.printAllOptSysParameter_LLT(bestOptSysE6_seidel);

		saveSystemData_bestOptSys_seidel(optSysNum_E6, durationE6_LLT_N_bestOptSys_min, durationE6_N_bestOptSys_convertEle_min, durationE6_N_bestOptSys_seidel_min, optSystemElement_E6, bestOptSysE6_seidel, EvManOptSys_ParaDis_E6_N_bestSys, wavelengths587, fieldsE6, lightVec_E6, rmsZemax_E6, Var_vec_Zemax_E6, addInfosVariable_E6, parameterTypeModeVec_E6, locationToExportData, nameExcelFileBestSys_seidel);

	}
	// *** --- ***//


	// evaluate the system according to ray tracing
	if (testWhat == testAll || testWhat == testRayTrac)
	{
		std::cout << "evaluate best optical system ray tracing" << std::endl;
		// *** evaluate best optSys according to real ray tracing ***//
		auto startE6_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		EvaluateManyOptSys_RayTracing evaluateE6_rayTracing(optSystemElement_E6, addInfosVariable_E6, fieldsE6, wavelenghtVecE6);
		OpticalSystemElement bestOptSysEle_E6_rayTracing = evaluateE6_rayTracing.getBestOptSys();
		auto end_E6_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE6_LLT_N_bestOptSys_rayTracing = end_E6_N_bestOptSys_rayTracing - startE6_N_bestOptSys_rayTracing;
		auto durationE6_LLT_N_bestOptSys_rayTracing_min = durationE6_LLT_N_bestOptSys_rayTracing.count() / 60.0;

		OpticalSystem_LLT bestOptSysE6_rayTracing = bestOptSysEle_E6_rayTracing.getLLTconversion_doConversion();
		bestOptSysE6_rayTracing.printAllOptSysParameter_LLT(bestOptSysE6_rayTracing);


		saveSystemData_bestOptSys_RayTracing(optSysNum_E6, durationE6_LLT_N_bestOptSys_rayTracing_min, optSystemElement_E6, bestOptSysE6_rayTracing, evaluateE6_rayTracing, wavelengths587, fieldsE6, lightVec_E6, rmsZemax_E6, Var_vec_Zemax_E6, addInfosVariable_E6, parameterTypeModeVec_E6, locationToExportData, nameExcelFileBestSys_rayTracing);

	}

	// check rms spot radius of initial system 
	SequentialRayTracing seqTraceE6_checker(optSystemElement_E6, { 0.0,0.0,0.0 }, 6, 8, 1.0, lightVec_E6);
	Spot spotE6(seqTraceE6_checker.getAllInterPointsAtSurf_i(4), seqTraceE6_checker.getAllInterPointsAtSurf_i(4).at(0));
	real rmsSpotE6 = spotE6.getRMS_µm();
	real excelBest_Zemax_RMS = 1032.04;
	bool checkE6_rmsBest = Math::compareTwoNumbers_decimals(excelBest_Zemax_RMS, rmsSpotE6, 1);
	workTestSystemsPeterMA_E6.push_back(checkE6_rmsBest);
	// ***

	bool returnCheckerE6 = Math::checkTrueOfVectorElements(workTestSystemsPeterMA_E6);

	return returnCheckerE6;


}

bool testSystemsPeterMA::calcTestSystemPeterMA_E7(testWhatEnum testWhat)
{

	std::vector<bool> workTestSystemsPeterMA_E7;

	real optSysNum_E7 = 7;



	std::vector<real> exportDataE7_seidel;
	exportDataE7_seidel.push_back(optSysNum_E7);

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	// surfaces E7
	ApertureStopElement AperStop0_E7(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAirZemax());
	SphericalElement Sphere1_E7(/*radius*/ 25.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere2_E7(/*radius*/ 30.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF6_S1(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere3_E7(/*radius*/ 25.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF6_S1());
	PlanElement Plan4_E7(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,75.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAirZemax(), /*refractive index B*/ glasses.getAirZemax());

	Sphere1_E7.setParameterRadius(-100.0, 100.0, 0.0, typeModifierVariable);
	Sphere3_E7.setParameterPointZ(35.0, 85.0, 0.0, typeModifierVariable);
	Sphere3_E7.setParameterRadius(-100.0, 100.0, 0.0, typeModifierVariable);

	surfacePtr Aper0_E7_ptr = AperStop0_E7.clone();
	surfacePtr Sphere1_E7_ptr = Sphere1_E7.clone();
	surfacePtr Sphere2_E7_ptr = Sphere2_E7.clone();
	surfacePtr Sphere3_E7_ptr = Sphere3_E7.clone();
	surfacePtr Plan4_E7_ptr = Plan4_E7.clone();

	std::vector<surfacePtr> opticalSystemE7_ptr{ Aper0_E7_ptr, Sphere1_E7_ptr, Sphere2_E7_ptr , Sphere3_E7_ptr, Plan4_E7_ptr };
	std::vector<interaction_ptr> interactionsE7_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E7(opticalSystemE7_ptr, interactionsE7_ptr);

	// light
	std::vector<Light_LLT> lightVec_E7;
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

	lightVec_E7.push_back(light0);
	lightVec_E7.push_back(light1);
	lightVec_E7.push_back(light2);

	// ***

	// Evaulate the system according to paraxial ray tracing
	// def steps variables
	stepsWithoutMinWithoutMax addInfosVarS1(/*surface num*/ 1, /*step size*/ 2, /*without min*/ -9.9, /*without max*/ 9.9);
	stepsWithoutMinWithoutMax addInfosVarS3p(/*surface num*/ 3, /*step size*/ 4, /*without min*/ 0.0, /*without max*/ 0.0);
	stepsWithoutMinWithoutMax addInfosVarS3(/*surface num*/ 3, /*step size*/ 2, /*without min*/ -9.9, /*without max*/ 9.9);
	std::vector<stepsWithoutMinWithoutMax> addInfosVariable_E7{ addInfosVarS1,addInfosVarS3p,addInfosVarS3 };

	// start ray
	StartRayPos startRayPos = notInfinity;

	std::vector<real> rmsZemax_E7 = { 64.790,77.306,113.967 };
	std::vector<real> Var_vec_Zemax_E7 = { 18.7394, 5.000,-20.2620 };
	parameterTypeModeStruct R1_E7(1, radius, typeModifierVariable);
	parameterTypeModeStruct D3_E7(3, position, typeModifierVariable);
	parameterTypeModeStruct R3_E7(3, radius, typeModifierVariable);

	std::vector< parameterTypeModeStruct> parameterTypeModeVec_E7{ R1_E7,D3_E7,R3_E7 };
	std::vector<VectorStructR3> fieldsE7{ {0.0,0.0,0.0},{0.0,1.0,0.0},{0.0,2.0,0.0} };
	std::vector<real>wavelenghtVecE7{ wavelengths587,wavelengths486,wavelengths656 };

	// *** evaluate best optSys ***//
	if (testWhat == testAll || testWhat == testParaxial)
	{
		std::cout << "evaluate best optical system paraxial" << std::endl;
		// *** evaluate best optSys according to paraxial ray tracing ***//

		// time to get best optSys E7
		auto startE7_bestOptSys = std::chrono::system_clock::now();
		// calc the combination vectors
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E7_bestSys(/*optical System Element*/ optSystemElement_E7, /* add infos*/ addInfosVariable_E7, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		OpticalSystem_LLT bestOptSys_LLT = EvManOptSys_ParaDis_E7_bestSys.getBestOptSys();
		auto endE7_bestOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE7_bestOptSy = endE7_bestOptSys - startE7_bestOptSys;
		auto durationE7_bestOptSy_min = durationE7_bestOptSy.count() / 60.0;

		saveSystemData_bestOptSys_paraxial(optSysNum_E7, durationE7_bestOptSy_min, optSystemElement_E7, bestOptSys_LLT, EvManOptSys_ParaDis_E7_bestSys.getSystemsForCombination().getAllPosOptSys_LLT().size(), wavelengths587, fieldsE7, lightVec_E7, rmsZemax_E7, Var_vec_Zemax_E7, addInfosVariable_E7, parameterTypeModeVec_E7, locationToExportData, nameExcelFileBestSys_paraxial);

	}
	// *** --- ***//

	// evaluate the system according to seidel coef
	if (testWhat == testAll || testWhat == testSeidel)
	{
		std::cout << "evaluate best optical system seidel" << std::endl;

		// *** evaluate best optSys according to seidel coeff ***//
		//// time evaluate N best opt Sys
		auto startE7_N_besteOptSys = std::chrono::system_clock::now();
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E7_N_bestSys(/*optical System Element*/ optSystemElement_E7, /* add infos*/ addInfosVariable_E7, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		std::vector<OpticalSystem_LLT> N_bestOptSys_LLT = EvManOptSys_ParaDis_E7_N_bestSys.get_N_BestOptSys_LLT(50);
		auto endE7_N_besteOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE7_LLT_N_bestOptSys = endE7_N_besteOptSys - startE7_N_besteOptSys;
		auto durationE7_LLT_N_bestOptSys_min = durationE7_LLT_N_bestOptSys.count() / 60.0;

		//// time convert N best opt Sys to Element
		optSystemElement_E7.setRefractivIndexAccWave(optSystemElement_E7, wavelengths587);
		auto startE7_N_bestOptSys_convertEle = std::chrono::system_clock::now();
		std::vector<OpticalSystemElement> N_bestOptSys_Ele_E7 = EvManOptSys_ParaDis_E7_N_bestSys.convert_N_optSysLLT_To_elementSystems(N_bestOptSys_LLT, optSystemElement_E7);
		optSystemElement_E7.setRefractivIndexOptSysEle(N_bestOptSys_Ele_E7, wavelengths587);
		auto endE7_N_bestOptSys_convertEle = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE7_N_bestOptSys_convertEle = endE7_N_bestOptSys_convertEle - startE7_N_bestOptSys_convertEle;
		auto durationE7_N_bestOptSys_convertEle_min = durationE7_N_bestOptSys_convertEle.count() / 60.0;

		// evalute N best opt Sys Seidel

		auto startE7_N_bestOptSys_seidel = std::chrono::system_clock::now();
		EvaluateManyOptSystems_SeidelCoef evaluateE7_seidel(N_bestOptSys_Ele_E7, fieldsE7, wavelenghtVecE7);
		OpticalSystemElement bestOptSysEle_E7_seidel = evaluateE7_seidel.calcBestOptSys_OptSysVec();
		auto endE7_N_bestOptSys_seidel = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE7_N_bestOptSys_seidel = endE7_N_bestOptSys_seidel - startE7_N_bestOptSys_seidel;
		auto durationE7_N_bestOptSys_seidel_min = durationE7_N_bestOptSys_seidel.count() / 60.0;

		OpticalSystem_LLT bestOptSysE7_seidel = bestOptSysEle_E7_seidel.getLLTconversion_doConversion();
		bestOptSysE7_seidel.printAllOptSysParameter_LLT(bestOptSysE7_seidel);

		saveSystemData_bestOptSys_seidel(optSysNum_E7, durationE7_LLT_N_bestOptSys_min, durationE7_N_bestOptSys_convertEle_min, durationE7_N_bestOptSys_seidel_min, optSystemElement_E7, bestOptSysE7_seidel, EvManOptSys_ParaDis_E7_N_bestSys, wavelengths587, fieldsE7, lightVec_E7, rmsZemax_E7, Var_vec_Zemax_E7, addInfosVariable_E7, parameterTypeModeVec_E7, locationToExportData, nameExcelFileBestSys_seidel);

	}
	// *** --- ***//


	// evaluate the system according to ray tracing
	if (testWhat == testAll || testWhat == testRayTrac)
	{
		std::cout << "evaluate best optical system ray tracing" << std::endl;
		// *** evaluate best optSys according to real ray tracing ***//
		auto startE7_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		EvaluateManyOptSys_RayTracing evaluateE7_rayTracing(optSystemElement_E7, addInfosVariable_E7, fieldsE7, wavelenghtVecE7);
		OpticalSystemElement bestOptSysEle_E7_rayTracing = evaluateE7_rayTracing.getBestOptSys();
		auto end_E7_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE7_LLT_N_bestOptSys_rayTracing = end_E7_N_bestOptSys_rayTracing - startE7_N_bestOptSys_rayTracing;
		auto durationE7_LLT_N_bestOptSys_rayTracing_min = durationE7_LLT_N_bestOptSys_rayTracing.count() / 60.0;

		OpticalSystem_LLT bestOptSysE7_rayTracing = bestOptSysEle_E7_rayTracing.getLLTconversion_doConversion();
		bestOptSysE7_rayTracing.printAllOptSysParameter_LLT(bestOptSysE7_rayTracing);


		saveSystemData_bestOptSys_RayTracing(optSysNum_E7, durationE7_LLT_N_bestOptSys_rayTracing_min, optSystemElement_E7, bestOptSysE7_rayTracing, evaluateE7_rayTracing, wavelengths587, fieldsE7, lightVec_E7, rmsZemax_E7, Var_vec_Zemax_E7, addInfosVariable_E7, parameterTypeModeVec_E7, locationToExportData, nameExcelFileBestSys_rayTracing);

	}

	// check rms spot radius of initial system 
	SequentialRayTracing seqTraceE7_checker(optSystemElement_E7, { 0.0,0.0,0.0 }, 6, 8, 1.0, lightVec_E7);
	Spot spotE7(seqTraceE7_checker.getAllInterPointsAtSurf_i(4), seqTraceE7_checker.getAllInterPointsAtSurf_i(4).at(0));
	real rmsSpotE7 = spotE7.getRMS_µm();
	real excelBest_Zemax_RMS = 1031.21;
	bool checkE7_rmsBest = Math::compareTwoNumbers_decimals(excelBest_Zemax_RMS, rmsSpotE7, 1);
	workTestSystemsPeterMA_E7.push_back(checkE7_rmsBest);
	// ***


	bool returnCheckerE7 = Math::checkTrueOfVectorElements(workTestSystemsPeterMA_E7);

	return returnCheckerE7;


}

bool testSystemsPeterMA::calcTestSystemPeterMA_E8(testWhatEnum testWhat)
{

	std::vector<bool> workTestSystemsPeterMA_E8;

	real optSysNum_E8 = 8;



	std::vector<real> exportDataE8_seidel;
	exportDataE8_seidel.push_back(optSysNum_E8);

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	// surfaces E8
	ApertureStopElement AperStop0_E8(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAirZemax());
	SphericalElement Sphere1_E8(/*radius*/ 60.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBK7_S1());
	SphericalElement Sphere2_E8(/*radius*/ 50.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSSKN8_S1(), /*refractive index B*/glasses.getBK7_S1());
	SphericalElement Sphere3_E8(/*radius*/ 40.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSSKN8_S1());
	SphericalElement Sphere4_E8(/*radius*/ 50.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere5_E8(/*radius*/ 50.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSSKN8_S1(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere6_E8(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getSSKN8_S1());
	PlanElement Plan7_E8(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,90.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAirZemax(), /*refractive index B*/ glasses.getAirZemax());

	Sphere2_E8.setParameterRadius(-100.0, 100.0, 0.0, typeModifierVariable);
	Sphere3_E8.setParameterPointZ(40.0,90.0, 0.0, typeModifierVariable);
	Sphere5_E8.setParameterRadius(-100.0, 100.0, 0.0, typeModifierVariable);

	surfacePtr Aper0_E8_ptr = AperStop0_E8.clone();
	surfacePtr Sphere1_E8_ptr = Sphere1_E8.clone();
	surfacePtr Sphere2_E8_ptr = Sphere2_E8.clone();
	surfacePtr Sphere3_E8_ptr = Sphere3_E8.clone();
	surfacePtr Sphere4_E8_ptr = Sphere4_E8.clone();
	surfacePtr Sphere5_E8_ptr = Sphere5_E8.clone();
	surfacePtr Sphere6_E8_ptr = Sphere6_E8.clone();
	surfacePtr Plan7_E8_ptr = Plan7_E8.clone();

	std::vector<surfacePtr> opticalSystemE8_ptr{ Aper0_E8_ptr, Sphere1_E8_ptr, Sphere2_E8_ptr , Sphere3_E8_ptr, Sphere4_E8_ptr, Sphere5_E8_ptr, Sphere6_E8_ptr, Plan7_E8_ptr };
	std::vector<interaction_ptr> interactionsE8_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E8(opticalSystemE8_ptr, interactionsE8_ptr);

	// light
	std::vector<Light_LLT> lightVec_E8;
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

	lightVec_E8.push_back(light0);
	lightVec_E8.push_back(light1);
	lightVec_E8.push_back(light2);

	// ***

	// Evaulate the system according to paraxial ray tracing
	// def steps variables
	stepsWithoutMinWithoutMax addInfosVarS2(/*surface num*/ 2, /*step size*/ 2, /*without min*/ -9.9, /*without max*/ 9.9);
	stepsWithoutMinWithoutMax addInfosVarS3(/*surface num*/ 3, /*step size*/ 4, /*without min*/ 0.0, /*without max*/ 0.0);
	stepsWithoutMinWithoutMax addInfosVarS5(/*surface num*/ 5, /*step size*/ 2, /*without min*/ -9.9, /*without max*/ 9.9);
	std::vector<stepsWithoutMinWithoutMax> addInfosVariable_E8{ addInfosVarS2,addInfosVarS3,addInfosVarS5 };

	// start ray
	StartRayPos startRayPos = notInfinity;

	std::vector<real> rmsZemax_E8 = { 17.049,22.008,35.681 };
	std::vector<real> Var_vec_Zemax_E8 = { -21.0725, 582.2823,-62.1854 };
	parameterTypeModeStruct R2_E8(3, radius, typeModifierVariable);
	parameterTypeModeStruct R2p_E8(5, position, typeModifierVariable);
	parameterTypeModeStruct R5_E8(7, radius, typeModifierVariable);

	std::vector< parameterTypeModeStruct> parameterTypeModeVec_E8{ R2_E8,R2p_E8,R5_E8 };
	std::vector<VectorStructR3> fieldsE8{ {0.0,0.0,0.0},{0.0,1.0,0.0},{0.0,2.0,0.0} };
	std::vector<real>wavelenghtVecE8{ wavelengths587,wavelengths486,wavelengths656 };

	// *** evaluate best optSys ***//
	if (testWhat == testAll || testWhat == testParaxial)
	{
		std::cout << "evaluate best optical system paraxial" << std::endl;
		// *** evaluate best optSys according to paraxial ray tracing ***//

		// time to get best optSys E8
		auto startE8_bestOptSys = std::chrono::system_clock::now();
		// calc the combination vectors
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E8_bestSys(/*optical System Element*/ optSystemElement_E8, /* add infos*/ addInfosVariable_E8, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		OpticalSystem_LLT bestOptSys_LLT = EvManOptSys_ParaDis_E8_bestSys.getBestOptSys();
		auto endE8_bestOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE8_bestOptSy = endE8_bestOptSys - startE8_bestOptSys;
		auto durationE8_bestOptSy_min = durationE8_bestOptSy.count() / 60.0;

		saveSystemData_bestOptSys_paraxial(optSysNum_E8, durationE8_bestOptSy_min, optSystemElement_E8, bestOptSys_LLT, EvManOptSys_ParaDis_E8_bestSys.getSystemsForCombination().getAllPosOptSys_LLT().size(), wavelengths587, fieldsE8, lightVec_E8, rmsZemax_E8, Var_vec_Zemax_E8, addInfosVariable_E8, parameterTypeModeVec_E8, locationToExportData, nameExcelFileBestSys_paraxial);

	}
	// *** --- ***//

	// evaluate the system according to seidel coef
	if (testWhat == testAll || testWhat == testSeidel)
	{
		std::cout << "evaluate best optical system seidel" << std::endl;

		// *** evaluate best optSys according to seidel coeff ***//
		//// time evaluate N best opt Sys
		auto startE8_N_besteOptSys = std::chrono::system_clock::now();
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E8_N_bestSys(/*optical System Element*/ optSystemElement_E8, /* add infos*/ addInfosVariable_E8, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		std::vector<OpticalSystem_LLT> N_bestOptSys_LLT = EvManOptSys_ParaDis_E8_N_bestSys.get_N_BestOptSys_LLT(50);
		auto endE8_N_besteOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE8_LLT_N_bestOptSys = endE8_N_besteOptSys - startE8_N_besteOptSys;
		auto durationE8_LLT_N_bestOptSys_min = durationE8_LLT_N_bestOptSys.count() / 60.0;

		//// time convert N best opt Sys to Element
		optSystemElement_E8.setRefractivIndexAccWave(optSystemElement_E8, wavelengths587);
		auto startE8_N_bestOptSys_convertEle = std::chrono::system_clock::now();
		std::vector<OpticalSystemElement> N_bestOptSys_Ele_E8 = EvManOptSys_ParaDis_E8_N_bestSys.convert_N_optSysLLT_To_elementSystems(N_bestOptSys_LLT, optSystemElement_E8);
		optSystemElement_E8.setRefractivIndexOptSysEle(N_bestOptSys_Ele_E8, wavelengths587);
		auto endE8_N_bestOptSys_convertEle = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE8_N_bestOptSys_convertEle = endE8_N_bestOptSys_convertEle - startE8_N_bestOptSys_convertEle;
		auto durationE8_N_bestOptSys_convertEle_min = durationE8_N_bestOptSys_convertEle.count() / 60.0;

		// evalute N best opt Sys Seidel

		auto startE8_N_bestOptSys_seidel = std::chrono::system_clock::now();
		EvaluateManyOptSystems_SeidelCoef evaluateE8_seidel(N_bestOptSys_Ele_E8, fieldsE8, wavelenghtVecE8);
		OpticalSystemElement bestOptSysEle_E8_seidel = evaluateE8_seidel.calcBestOptSys_OptSysVec();
		auto endE8_N_bestOptSys_seidel = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE8_N_bestOptSys_seidel = endE8_N_bestOptSys_seidel - startE8_N_bestOptSys_seidel;
		auto durationE8_N_bestOptSys_seidel_min = durationE8_N_bestOptSys_seidel.count() / 60.0;

		OpticalSystem_LLT bestOptSysE8_seidel = bestOptSysEle_E8_seidel.getLLTconversion_doConversion();
		bestOptSysE8_seidel.printAllOptSysParameter_LLT(bestOptSysE8_seidel);

		saveSystemData_bestOptSys_seidel(optSysNum_E8, durationE8_LLT_N_bestOptSys_min, durationE8_N_bestOptSys_convertEle_min, durationE8_N_bestOptSys_seidel_min, optSystemElement_E8, bestOptSysE8_seidel, EvManOptSys_ParaDis_E8_N_bestSys, wavelengths587, fieldsE8, lightVec_E8, rmsZemax_E8, Var_vec_Zemax_E8, addInfosVariable_E8, parameterTypeModeVec_E8, locationToExportData, nameExcelFileBestSys_seidel);

	}
	// *** --- ***//


	// evaluate the system according to ray tracing
	if (testWhat == testAll || testWhat == testRayTrac)
	{
		std::cout << "evaluate best optical system ray tracing" << std::endl;
		// *** evaluate best optSys according to real ray tracing ***//
		auto startE8_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		EvaluateManyOptSys_RayTracing evaluateE8_rayTracing(optSystemElement_E8, addInfosVariable_E8, fieldsE8, wavelenghtVecE8);
		OpticalSystemElement bestOptSysEle_E8_rayTracing = evaluateE8_rayTracing.getBestOptSys();
		auto end_E8_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE8_LLT_N_bestOptSys_rayTracing = end_E8_N_bestOptSys_rayTracing - startE8_N_bestOptSys_rayTracing;
		auto durationE8_LLT_N_bestOptSys_rayTracing_min = durationE8_LLT_N_bestOptSys_rayTracing.count() / 60.0;

		OpticalSystem_LLT bestOptSysE8_rayTracing = bestOptSysEle_E8_rayTracing.getLLTconversion_doConversion();
		bestOptSysE8_rayTracing.printAllOptSysParameter_LLT(bestOptSysE8_rayTracing);


		saveSystemData_bestOptSys_RayTracing(optSysNum_E8, durationE8_LLT_N_bestOptSys_rayTracing_min, optSystemElement_E8, bestOptSysE8_rayTracing, evaluateE8_rayTracing, wavelengths587, fieldsE8, lightVec_E8, rmsZemax_E8, Var_vec_Zemax_E8, addInfosVariable_E8, parameterTypeModeVec_E8, locationToExportData, nameExcelFileBestSys_rayTracing);

	}

	// check rms spot radius of initial system 
	SequentialRayTracing seqTraceE8_checker(optSystemElement_E8, { 0.0,0.0,0.0 }, 6, 8, 1.0, lightVec_E8);
	Spot spotE8(seqTraceE8_checker.getAllInterPointsAtSurf_i(7), seqTraceE8_checker.getAllInterPointsAtSurf_i(7).at(0));
	real rmsSpotE8 = spotE8.getRMS_µm();
	real excelBest_Zemax_RMS = 341.198;
	bool checkE8_rmsBest = Math::compareTwoNumbers_decimals(excelBest_Zemax_RMS, rmsSpotE8, 1);
	workTestSystemsPeterMA_E8.push_back(checkE8_rmsBest);
	// ***

	bool returnCheckerE8 = Math::checkTrueOfVectorElements(workTestSystemsPeterMA_E8);

	return returnCheckerE8;


}

bool testSystemsPeterMA::calcTestSystemPeterMA_E9(testWhatEnum testWhat)
{

	std::vector<bool> workTestSystemsPeterMA_E9;

	real optSysNum_E9 = 9;



	std::vector<real> exportDataE9_seidel;
	exportDataE9_seidel.push_back(optSysNum_E9);

	glass glasses;
	glasses.loadGlassCatalog_Schott();

	typedef std::shared_ptr< Element_CR > surfacePtr;
	typedef std::shared_ptr< InteractionRay_LLT > interaction_ptr;

	RefractedRay_LLT refrac;
	Absorb_LLT absorb;
	DoNothingInteraction_LLT doNothing;

	// surfaces E9
	ApertureStopElement AperStop0_E9(/* semi height*/2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ glasses.getAirZemax());
	SphericalElement Sphere1_E9(/*radius*/ 30.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBK7_S1());
	SphericalElement Sphere2_E9(/*radius*/ 100.00, /*semi height*/10.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getBK7_S1(), /*refractive index B*/glasses.getSSKN8_S1());
	SphericalElement Sphere3_E9(/*radius*/ 90.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSSKN8_S1(), /*refractive index B*/glasses.getSF5_S1());
	SphericalElement Sphere4_E9(/*radius*/ 80.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractive index A*/ glasses.getSF5_S1(), /*refractive index B*/glasses.getSSKN8_S1());
	SphericalElement Sphere5_E9(/*radius*/ 70.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getSF10_S1(), /*refractive index B*/glasses.getSSKN8_S1());
	SphericalElement Sphere6_E9(/*radius*/ 60.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getBAK4_S1(), /*refractive index B*/glasses.getSF10_S1());
	SphericalElement Sphere7_E9(/*radius*/ 20.00, /*semi height*/ 10.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ glasses.getAirZemax(), /*refractive index B*/glasses.getBAK4_S1());
	PlanElement Plan8_E9(/*semi height*/ 10.0, /*point*/{ 0.0,0.0,90.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ glasses.getAirZemax(), /*refractive index B*/ glasses.getAirZemax());

	Sphere2_E9.setParameterRadius(-100.0, 100.0, 0.0, typeModifierVariable);
	Sphere4_E9.setParameterRadius(-100.0, 100.0, 0.0, typeModifierVariable);
	Sphere7_E9.setParameterPointZ(65.0, 115.0, 0.0, typeModifierVariable);

	surfacePtr Aper0_E9_ptr = AperStop0_E9.clone();
	surfacePtr Sphere1_E9_ptr = Sphere1_E9.clone();
	surfacePtr Sphere2_E9_ptr = Sphere2_E9.clone();
	surfacePtr Sphere3_E9_ptr = Sphere3_E9.clone();
	surfacePtr Sphere4_E9_ptr = Sphere4_E9.clone();
	surfacePtr Sphere5_E9_ptr = Sphere5_E9.clone();
	surfacePtr Sphere6_E9_ptr = Sphere6_E9.clone();
	surfacePtr Sphere7_E9_ptr = Sphere7_E9.clone();
	surfacePtr Plan8_E9_ptr = Plan8_E9.clone();

	std::vector<surfacePtr> opticalSystemE9_ptr{ Aper0_E9_ptr, Sphere1_E9_ptr, Sphere2_E9_ptr , Sphere3_E9_ptr, Sphere4_E9_ptr, Sphere5_E9_ptr, Sphere6_E9_ptr, Sphere7_E9_ptr, Plan8_E9_ptr };
	std::vector<interaction_ptr> interactionsE9_ptr{ doNothing.clone(), refrac.clone(),refrac.clone(), refrac.clone(), refrac.clone(), refrac.clone(),refrac.clone(),refrac.clone(),absorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement_E9(opticalSystemE9_ptr, interactionsE9_ptr);

	// light
	std::vector<Light_LLT> lightVec_E9;
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

	lightVec_E9.push_back(light0);
	lightVec_E9.push_back(light1);
	lightVec_E9.push_back(light2);

	// ***

	// Evaulate the system according to paraxial ray tracing
	// def steps variables
	stepsWithoutMinWithoutMax addInfosVarS2(/*surface num*/ 2, /*step size*/ 2, /*without min*/ -9.9, /*without max*/ 9.9);
	stepsWithoutMinWithoutMax addInfosVarS4(/*surface num*/ 4, /*step size*/ 4, /*without min*/ -9.9, /*without max*/ 9.9);
	stepsWithoutMinWithoutMax addInfosVarS7(/*surface num*/ 7, /*step size*/ 2, /*without min*/ 0.0, /*without max*/ 0.0);
	std::vector<stepsWithoutMinWithoutMax> addInfosVariable_E9{ addInfosVarS2,addInfosVarS4,addInfosVarS7 };

	// start ray
	StartRayPos startRayPos = notInfinity;

	std::vector<real> rmsZemax_E9 = { 55.490,96.300,187.002 };
	std::vector<real> Var_vec_Zemax_E9 = { 34.6827, 13.8133,57.7194 };
	parameterTypeModeStruct R2_E9(2, radius, typeModifierVariable);
	parameterTypeModeStruct R4_E9(4, radius, typeModifierVariable);
	parameterTypeModeStruct D8_E9(8, position, typeModifierVariable);

	std::vector< parameterTypeModeStruct> parameterTypeModeVec_E9{ R2_E9,R4_E9,D8_E9 };
	std::vector<VectorStructR3> fieldsE9{ {0.0,0.0,0.0},{0.0,1.0,0.0},{0.0,2.0,0.0} };
	std::vector<real>wavelenghtVecE9{ wavelengths587,wavelengths486,wavelengths656 };

	// *** evaluate best optSys ***//
	if (testWhat == testAll || testWhat == testParaxial)
	{
		std::cout << "evaluate best optical system paraxial" << std::endl;
		// *** evaluate best optSys according to paraxial ray tracing ***//

		// time to get best optSys E9
		auto startE9_bestOptSys = std::chrono::system_clock::now();
		// calc the combination vectors
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E9_bestSys(/*optical System Element*/ optSystemElement_E9, /* add infos*/ addInfosVariable_E9, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		OpticalSystem_LLT bestOptSys_LLT = EvManOptSys_ParaDis_E9_bestSys.getBestOptSys();
		auto endE9_bestOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE9_bestOptSy = endE9_bestOptSys - startE9_bestOptSys;
		auto durationE9_bestOptSy_min = durationE9_bestOptSy.count() / 60.0;

		saveSystemData_bestOptSys_paraxial(optSysNum_E9, durationE9_bestOptSy_min, optSystemElement_E9, bestOptSys_LLT, EvManOptSys_ParaDis_E9_bestSys.getSystemsForCombination().getAllPosOptSys_LLT().size(), wavelengths587, fieldsE9, lightVec_E9, rmsZemax_E9, Var_vec_Zemax_E9, addInfosVariable_E9, parameterTypeModeVec_E9, locationToExportData, nameExcelFileBestSys_paraxial);

	}
	// *** --- ***//

	// evaluate the system according to seidel coef
	if (testWhat == testAll || testWhat == testSeidel)
	{
		std::cout << "evaluate best optical system seidel" << std::endl;

		// *** evaluate best optSys according to seidel coeff ***//
		//// time evaluate N best opt Sys
		auto startE9_N_besteOptSys = std::chrono::system_clock::now();
		EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_E9_N_bestSys(/*optical System Element*/ optSystemElement_E9, /* add infos*/ addInfosVariable_E9, /*start point ray*/startRayPos, /*prim wavelenght*/ wavelengths587);
		std::vector<OpticalSystem_LLT> N_bestOptSys_LLT = EvManOptSys_ParaDis_E9_N_bestSys.get_N_BestOptSys_LLT(50);
		auto endE9_N_besteOptSys = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE9_LLT_N_bestOptSys = endE9_N_besteOptSys - startE9_N_besteOptSys;
		auto durationE9_LLT_N_bestOptSys_min = durationE9_LLT_N_bestOptSys.count() / 60.0;

		//// time convert N best opt Sys to Element
		optSystemElement_E9.setRefractivIndexAccWave(optSystemElement_E9, wavelengths587);
		auto startE9_N_bestOptSys_convertEle = std::chrono::system_clock::now();
		std::vector<OpticalSystemElement> N_bestOptSys_Ele_E9 = EvManOptSys_ParaDis_E9_N_bestSys.convert_N_optSysLLT_To_elementSystems(N_bestOptSys_LLT, optSystemElement_E9);
		optSystemElement_E9.setRefractivIndexOptSysEle(N_bestOptSys_Ele_E9, wavelengths587);
		auto endE9_N_bestOptSys_convertEle = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE9_N_bestOptSys_convertEle = endE9_N_bestOptSys_convertEle - startE9_N_bestOptSys_convertEle;
		auto durationE9_N_bestOptSys_convertEle_min = durationE9_N_bestOptSys_convertEle.count() / 60.0;

		// evalute N best opt Sys Seidel

		auto startE9_N_bestOptSys_seidel = std::chrono::system_clock::now();
		EvaluateManyOptSystems_SeidelCoef evaluateE9_seidel(N_bestOptSys_Ele_E9, fieldsE9, wavelenghtVecE9);
		OpticalSystemElement bestOptSysEle_E9_seidel = evaluateE9_seidel.calcBestOptSys_OptSysVec();
		auto endE9_N_bestOptSys_seidel = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE9_N_bestOptSys_seidel = endE9_N_bestOptSys_seidel - startE9_N_bestOptSys_seidel;
		auto durationE9_N_bestOptSys_seidel_min = durationE9_N_bestOptSys_seidel.count() / 60.0;

		OpticalSystem_LLT bestOptSysE9_seidel = bestOptSysEle_E9_seidel.getLLTconversion_doConversion();
		bestOptSysE9_seidel.printAllOptSysParameter_LLT(bestOptSysE9_seidel);

		saveSystemData_bestOptSys_seidel(optSysNum_E9, durationE9_LLT_N_bestOptSys_min, durationE9_N_bestOptSys_convertEle_min, durationE9_N_bestOptSys_seidel_min, optSystemElement_E9, bestOptSysE9_seidel, EvManOptSys_ParaDis_E9_N_bestSys, wavelengths587, fieldsE9, lightVec_E9, rmsZemax_E9, Var_vec_Zemax_E9, addInfosVariable_E9, parameterTypeModeVec_E9, locationToExportData, nameExcelFileBestSys_seidel);

	}
	// *** --- ***//


	// evaluate the system according to ray tracing
	if (testWhat == testAll || testWhat == testRayTrac)
	{
		std::cout << "evaluate best optical system ray tracing" << std::endl;
		// *** evaluate best optSys according to real ray tracing ***//
		auto startE9_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		EvaluateManyOptSys_RayTracing evaluateE9_rayTracing(optSystemElement_E9, addInfosVariable_E9, fieldsE9, wavelenghtVecE9);
		OpticalSystemElement bestOptSysEle_E9_rayTracing = evaluateE9_rayTracing.getBestOptSys();
		auto end_E9_N_bestOptSys_rayTracing = std::chrono::system_clock::now();
		std::chrono::duration<double> durationE9_LLT_N_bestOptSys_rayTracing = end_E9_N_bestOptSys_rayTracing - startE9_N_bestOptSys_rayTracing;
		auto durationE9_LLT_N_bestOptSys_rayTracing_min = durationE9_LLT_N_bestOptSys_rayTracing.count() / 60.0;

		OpticalSystem_LLT bestOptSysE9_rayTracing = bestOptSysEle_E9_rayTracing.getLLTconversion_doConversion();
		bestOptSysE9_rayTracing.printAllOptSysParameter_LLT(bestOptSysE9_rayTracing);


		saveSystemData_bestOptSys_RayTracing(optSysNum_E9, durationE9_LLT_N_bestOptSys_rayTracing_min, optSystemElement_E9, bestOptSysE9_rayTracing, evaluateE9_rayTracing, wavelengths587, fieldsE9, lightVec_E9, rmsZemax_E9, Var_vec_Zemax_E9, addInfosVariable_E9, parameterTypeModeVec_E9, locationToExportData, nameExcelFileBestSys_rayTracing);

	}

	// check rms spot radius of initial system 
	SequentialRayTracing seqTraceE9_checker(optSystemElement_E9, { 0.0,0.0,0.0 }, 6, 8, 1.0, lightVec_E9);
	Spot spotE9(seqTraceE9_checker.getAllInterPointsAtSurf_i(8), seqTraceE9_checker.getAllInterPointsAtSurf_i(8).at(0));
	real rmsSpotE9 = spotE9.getRMS_µm();
	real excelBest_Zemax_RMS = 1272.95;
	bool checkE9_rmsBest = Math::compareTwoNumbers_decimals(excelBest_Zemax_RMS, rmsSpotE9, 1);
	workTestSystemsPeterMA_E9.push_back(checkE9_rmsBest);
	// ***
	

	bool returnCheckerE9 = Math::checkTrueOfVectorElements(workTestSystemsPeterMA_E9);

	return returnCheckerE9;


}

void testSystemsPeterMA::saveSystemData_bestOptSys_paraxial(unsigned int optSysNum, real timeGetBestOptSys, OpticalSystemElement& optSystemElement, OpticalSystem_LLT& bestOptSys_LLT, unsigned int numberEvaSys, real primWave, const std::vector<VectorStructR3>& fields, const std::vector<Light_LLT>& light_vec, const std::vector<real>& rmsZemax,  const std::vector<real>& Var_vec_Zemax, const std::vector<stepsWithoutMinWithoutMax>& addInfos, const std::vector< parameterTypeModeStruct>& parameterTypeMode, std::string location, std::string nameExcel)
{
	std::vector<real> exportData_bestOptSys_paraxial;
	exportData_bestOptSys_paraxial.push_back(optSysNum);
	exportData_bestOptSys_paraxial.push_back(timeGetBestOptSys);


	unsigned int posLastSurface = optSystemElement.getPosAndElement().size() - 1;

	// number evaluated opt Sys
	unsigned int evaluatedOptSys = numberEvaSys;
	exportData_bestOptSys_paraxial.push_back(evaluatedOptSys);
	// convert LLT to Element
	OpticalSystemElement bestOptSysEle = optSystemElement.convertOptSys_LLT_T0_OptSys_HLT(optSystemElement, bestOptSys_LLT);
	bestOptSysEle.setRefractiveIndexAccordingToWavelength(primWave);
	// optical axis
	VectorStructR3 optA_E0 = fields[0];
	SequentialRayTracing seqTraceE0_optAxis(/*optical system element*/ bestOptSysEle,/*start point lightRay*/ optA_E0, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, light_vec);
	Spot spotE0_optA_bestOptSys(seqTraceE0_optAxis.getAllInterPointsAtSurf_i(posLastSurface), seqTraceE0_optAxis.getAllInterPointsAtSurf_i(posLastSurface)[0]);
	real spotOptAxisE0_bestOptSys = spotE0_optA_bestOptSys.getRMS_µm();
	exportData_bestOptSys_paraxial.push_back(spotOptAxisE0_bestOptSys);
	// field 1 at y=1
	VectorStructR3 field1_E0 = fields[1];
	SequentialRayTracing seqTraceE0_field1_E0(/*optical system element*/ bestOptSysEle,/*start point lightRay*/ field1_E0, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, light_vec);
	Spot spotE0_field1_bestOptSys(seqTraceE0_field1_E0.getAllInterPointsAtSurf_i(posLastSurface), seqTraceE0_field1_E0.getAllInterPointsAtSurf_i(posLastSurface)[0]);
	real spotField1E0_bestOptSys = spotE0_field1_bestOptSys.getRMS_µm();
	exportData_bestOptSys_paraxial.push_back(spotField1E0_bestOptSys);
	// field 2 at y=2
	VectorStructR3 field2_E0 = fields[2];
	SequentialRayTracing seqTraceE0_field2_E0(/*optical system element*/ bestOptSysEle,/*start point lightRay*/ field2_E0, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, light_vec);
	Spot spotE0_field2_bestOptSys(seqTraceE0_field2_E0.getAllInterPointsAtSurf_i(posLastSurface), seqTraceE0_field2_E0.getAllInterPointsAtSurf_i(posLastSurface)[0]);
	real spotField2E0_bestOptSys = spotE0_field2_bestOptSys.getRMS_µm();
	exportData_bestOptSys_paraxial.push_back(spotField2E0_bestOptSys);


	OpticalSystem_LLT optSysE0_LLT = bestOptSysEle.getOptSys_LLT_buildSystem();
	std::cout << "spot optA E0: " << spotOptAxisE0_bestOptSys << std::endl;
	std::cout << "spot field1 E0: " << spotField1E0_bestOptSys << std::endl;
	std::cout << "spot field2 E0: " << spotField2E0_bestOptSys << std::endl;
	real sumRMS_TOM = spotOptAxisE0_bestOptSys + spotField1E0_bestOptSys + spotField2E0_bestOptSys;
	exportData_bestOptSys_paraxial.push_back(sumRMS_TOM);
	std::cout << "sum rms TOM: " << sumRMS_TOM << std::endl;

	real ZemaxSumRMS = Math::sumAllVectorValues(rmsZemax);
	exportData_bestOptSys_paraxial.push_back(ZemaxSumRMS);
	std::cout << "sum rms Zemax: " << ZemaxSumRMS << std::endl;

	real V0;
	real V1;
	real V2;

	// check variables V0
	kindOfParameter kindParaV0 = parameterTypeMode[0].getKindParam();
	unsigned int posV0 = parameterTypeMode[0].getSurfaceNum();
	if (kindParaV0 == radius)
	{
		V0 = bestOptSys_LLT.getPosAndInteractingSurface()[posV0].getSurfaceInterRay_ptr()->getRadius() * bestOptSys_LLT.getPosAndInteractingSurface()[posV0].getSurfaceInterRay_ptr()->getDirection().getZ();
		exportData_bestOptSys_paraxial.push_back(V0);
	}
	else if (kindParaV0 == position)
	{
		real posMinOne = bestOptSys_LLT.getPosAndInteractingSurface()[posV0 - 1].getSurfaceInterRay_ptr()->getPoint().getZ();
		real posZero = bestOptSys_LLT.getPosAndInteractingSurface()[posV0].getSurfaceInterRay_ptr()->getPoint().getZ();
		V0 = posZero - posMinOne;
		exportData_bestOptSys_paraxial.push_back(V0);
	}

	// check variables V1
	kindOfParameter kindParaV1 = parameterTypeMode[1].getKindParam();
	unsigned int posV1 = parameterTypeMode[1].getSurfaceNum();
	if (kindParaV1 == radius)
	{
		V1 = bestOptSys_LLT.getPosAndInteractingSurface()[posV1].getSurfaceInterRay_ptr()->getRadius() * bestOptSys_LLT.getPosAndInteractingSurface()[posV1].getSurfaceInterRay_ptr()->getDirection().getZ();
		exportData_bestOptSys_paraxial.push_back(V1);
	}
	else if (kindParaV1 == position)
	{
		real posMinOne = bestOptSys_LLT.getPosAndInteractingSurface()[posV1 - 1].getSurfaceInterRay_ptr()->getPoint().getZ();
		real posZero = bestOptSys_LLT.getPosAndInteractingSurface()[posV1].getSurfaceInterRay_ptr()->getPoint().getZ();
		V1 = posZero - posMinOne;
		exportData_bestOptSys_paraxial.push_back(V1);
	}
	
	// check variables V2
	kindOfParameter kindParaV2 = parameterTypeMode[2].getKindParam();
	unsigned int posV2 = parameterTypeMode[2].getSurfaceNum();
	if (kindParaV2 == radius)
	{
		V2 = bestOptSys_LLT.getPosAndInteractingSurface()[posV2].getSurfaceInterRay_ptr()->getRadius() * bestOptSys_LLT.getPosAndInteractingSurface()[posV2].getSurfaceInterRay_ptr()->getDirection().getZ();
		exportData_bestOptSys_paraxial.push_back(V2);
	}
	else if (kindParaV2 == position)
	{
		real posMinOne = bestOptSys_LLT.getPosAndInteractingSurface()[posV2 - 1].getSurfaceInterRay_ptr()->getPoint().getZ();
		real posZero = bestOptSys_LLT.getPosAndInteractingSurface()[posV2].getSurfaceInterRay_ptr()->getPoint().getZ();
		V2 = posZero - posMinOne;
		exportData_bestOptSys_paraxial.push_back(V2);
	}
	
	real V1_Zemax = Var_vec_Zemax[0];
	exportData_bestOptSys_paraxial.push_back(V1_Zemax);
	real V2_Zemax = Var_vec_Zemax[1];
	exportData_bestOptSys_paraxial.push_back(V2_Zemax);
	real V3_Zemax = Var_vec_Zemax[2];
	exportData_bestOptSys_paraxial.push_back(V3_Zemax);
	real stepV0 = addInfos[0].getSteps();
	exportData_bestOptSys_paraxial.push_back(stepV0);
	real stepV1 = addInfos[1].getSteps();
	exportData_bestOptSys_paraxial.push_back(stepV1);
	real stepV2 = addInfos[2].getSteps();
	exportData_bestOptSys_paraxial.push_back(stepV2);

	// export Data
	inportExportData::exportDataToExcel_vector(location, nameExcel, "numOptSys, timeToGetBestOptSys, evaluatedOptSys, spotOptAxisTOM, spotField1TOM, spotField2TOM, sumRMS_TOM, sumRMS_Zemax, V0TOM, V1TOM, V2TOM, V0Zemax, V1Zemax, V2Zemax, stepV0, stepV1, stepV2", exportData_bestOptSys_paraxial);
}


void testSystemsPeterMA::saveSystemData_bestOptSys_seidel(unsigned int optSysNum, real duration_N_bestOptSys_min, real duration_N_bestOptSys_convertEle_min, real duration_N_bestOptSys_seidel_min,  OpticalSystemElement optSystemElement, OpticalSystem_LLT bestoptSys_LLT_seidel, EvaluateManyOptSystems_ParaxialDistances EvManOptSys_ParaDis_bestSys, real primWave, std::vector<VectorStructR3> fields, std::vector<Light_LLT> light_vec, std::vector<real> rmsZemax, std::vector<real> Var_vec_Zemax, std::vector<stepsWithoutMinWithoutMax> addInfos, std::vector< parameterTypeModeStruct> parameterTypeMode, std::string location, std::string nameExcel)
{
	std::vector<real> exportData_bestOptSys_seidel;
	exportData_bestOptSys_seidel.push_back(optSysNum);

	exportData_bestOptSys_seidel.push_back(duration_N_bestOptSys_min);
	exportData_bestOptSys_seidel.push_back(duration_N_bestOptSys_convertEle_min);
	exportData_bestOptSys_seidel.push_back(duration_N_bestOptSys_seidel_min);

	real sumCalcTime = duration_N_bestOptSys_min + duration_N_bestOptSys_convertEle_min + duration_N_bestOptSys_seidel_min;
	exportData_bestOptSys_seidel.push_back(sumCalcTime);

	unsigned int posLastSurface = optSystemElement.getPosAndElement().size() - 1;

	// number evaluated opt Sys
	unsigned int evaluatedOptSys = EvManOptSys_ParaDis_bestSys.getSystemsForCombination().getAllPosOptSys_LLT().size();
	exportData_bestOptSys_seidel.push_back(evaluatedOptSys);

	// convert LLT to Element
	OpticalSystemElement bestOptSysEle = optSystemElement.convertOptSys_LLT_T0_OptSys_HLT(optSystemElement, bestoptSys_LLT_seidel);
	bestOptSysEle.setRefractiveIndexAccordingToWavelength(primWave);
	// optical axis
	VectorStructR3 optA_E0 = fields[0];
	SequentialRayTracing seqTraceE0_optAxis(/*optical system element*/ bestOptSysEle,/*start point lightRay*/ optA_E0, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, light_vec);
	Spot spotE0_optA_bestOptSys(seqTraceE0_optAxis.getAllInterPointsAtSurf_i(posLastSurface), seqTraceE0_optAxis.getAllInterPointsAtSurf_i(posLastSurface)[0]);
	real spotOptAxisE0_bestOptSys = spotE0_optA_bestOptSys.getRMS_µm();
	exportData_bestOptSys_seidel.push_back(spotOptAxisE0_bestOptSys);
	// field 1 at y=1
	VectorStructR3 field1_E0 = fields[1];
	SequentialRayTracing seqTraceE0_field1_E0(/*optical system element*/ bestOptSysEle,/*start point lightRay*/ field1_E0, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, light_vec);
	Spot spotE0_field1_bestOptSys(seqTraceE0_field1_E0.getAllInterPointsAtSurf_i(posLastSurface), seqTraceE0_field1_E0.getAllInterPointsAtSurf_i(posLastSurface)[0]);
	real spotField1E0_bestOptSys = spotE0_field1_bestOptSys.getRMS_µm();
	exportData_bestOptSys_seidel.push_back(spotField1E0_bestOptSys);
	// field 2 at y=2
	VectorStructR3 field2_E0 = fields[2];
	SequentialRayTracing seqTraceE0_field2_E0(/*optical system element*/ bestOptSysEle,/*start point lightRay*/ field2_E0, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, light_vec);
	Spot spotE0_field2_bestOptSys(seqTraceE0_field2_E0.getAllInterPointsAtSurf_i(posLastSurface), seqTraceE0_field2_E0.getAllInterPointsAtSurf_i(posLastSurface)[0]);
	real spotField2E0_bestOptSys = spotE0_field2_bestOptSys.getRMS_µm();
	exportData_bestOptSys_seidel.push_back(spotField2E0_bestOptSys);

	OpticalSystem_LLT optSysE0_LLT = bestOptSysEle.getOptSys_LLT_buildSystem();
	std::cout << "spot optA E0: " << spotOptAxisE0_bestOptSys << std::endl;
	std::cout << "spot field1 E0: " << spotField1E0_bestOptSys << std::endl;
	std::cout << "spot field2 E0: " << spotField2E0_bestOptSys << std::endl;
	real sumRMS_TOM = spotOptAxisE0_bestOptSys + spotField1E0_bestOptSys + spotField2E0_bestOptSys;
	exportData_bestOptSys_seidel.push_back(sumRMS_TOM);
	std::cout << "sum rms TOM: " << sumRMS_TOM << std::endl;

	real ZemaxSumRMS = Math::sumAllVectorValues(rmsZemax);
	exportData_bestOptSys_seidel.push_back(ZemaxSumRMS);
	std::cout << "sum rms Zemax: " << ZemaxSumRMS << std::endl;

	real V0;
	real V1;
	real V2;

	// check variables V0
	kindOfParameter kindParaV0 = parameterTypeMode[0].getKindParam();
	unsigned int posV0 = parameterTypeMode[0].getSurfaceNum();
	if (kindParaV0 == radius)
	{
		V0 = bestoptSys_LLT_seidel.getPosAndInteractingSurface()[posV0].getSurfaceInterRay_ptr()->getRadius() * bestoptSys_LLT_seidel.getPosAndInteractingSurface()[posV0].getSurfaceInterRay_ptr()->getDirection().getZ();
		exportData_bestOptSys_seidel.push_back(V0);
	}
	else if (kindParaV0 == position)
	{
		real posMinOne = bestoptSys_LLT_seidel.getPosAndInteractingSurface()[posV0 - 1].getSurfaceInterRay_ptr()->getPoint().getZ();
		real posZero = bestoptSys_LLT_seidel.getPosAndInteractingSurface()[posV0].getSurfaceInterRay_ptr()->getPoint().getZ();
		V0 = posZero - posMinOne;
		exportData_bestOptSys_seidel.push_back(V0);
	}

	// check variables V1
	kindOfParameter kindParaV1 = parameterTypeMode[1].getKindParam();
	unsigned int posV1 = parameterTypeMode[1].getSurfaceNum();
	if (kindParaV1 == radius)
	{
		V1 = bestoptSys_LLT_seidel.getPosAndInteractingSurface()[posV1].getSurfaceInterRay_ptr()->getRadius() * bestoptSys_LLT_seidel.getPosAndInteractingSurface()[posV1].getSurfaceInterRay_ptr()->getDirection().getZ();
		exportData_bestOptSys_seidel.push_back(V1);
	}
	else if (kindParaV1 == position)
	{
		real posMinOne = bestoptSys_LLT_seidel.getPosAndInteractingSurface()[posV1 - 1].getSurfaceInterRay_ptr()->getPoint().getZ();
		real posZero = bestoptSys_LLT_seidel.getPosAndInteractingSurface()[posV1].getSurfaceInterRay_ptr()->getPoint().getZ();
		V1 = posZero - posMinOne;
		exportData_bestOptSys_seidel.push_back(V1);
	}

	// check variables V2
	kindOfParameter kindParaV2 = parameterTypeMode[2].getKindParam();
	unsigned int posV2 = parameterTypeMode[2].getSurfaceNum();
	if (kindParaV2 == radius)
	{
		V2 = bestoptSys_LLT_seidel.getPosAndInteractingSurface()[posV2].getSurfaceInterRay_ptr()->getRadius() * bestoptSys_LLT_seidel.getPosAndInteractingSurface()[posV2].getSurfaceInterRay_ptr()->getDirection().getZ();
		exportData_bestOptSys_seidel.push_back(V2);
	}
	else if (kindParaV2 == position)
	{
		real posMinOne = bestoptSys_LLT_seidel.getPosAndInteractingSurface()[posV2 - 1].getSurfaceInterRay_ptr()->getPoint().getZ();
		real posZero = bestoptSys_LLT_seidel.getPosAndInteractingSurface()[posV2].getSurfaceInterRay_ptr()->getPoint().getZ();
		V2 = posZero - posMinOne;
		exportData_bestOptSys_seidel.push_back(V2);
	}

	real V1_Zemax = Var_vec_Zemax[0];
	exportData_bestOptSys_seidel.push_back(V1_Zemax);
	real V2_Zemax = Var_vec_Zemax[1];
	exportData_bestOptSys_seidel.push_back(V2_Zemax);
	real V3_Zemax = Var_vec_Zemax[2];
	exportData_bestOptSys_seidel.push_back(V3_Zemax);
	real stepV0 = addInfos[0].getSteps();
	exportData_bestOptSys_seidel.push_back(stepV0);
	real stepV1 = addInfos[1].getSteps();
	exportData_bestOptSys_seidel.push_back(stepV1);
	real stepV2 = addInfos[2].getSteps();
	exportData_bestOptSys_seidel.push_back(stepV2);

	// export Data
	inportExportData::exportDataToExcel_vector(location, nameExcel, "numOptSys, timeToGetBestOptSys, time convert, seidelTime, evaluatedOptSys, spotOptAxisTOM, spotField1TOM, spotField2TOM, sumRMS_TOM, sumRMS_Zemax, V0TOM, V1TOM, V2TOM, V0Zemax, V1Zemax, V2Zemax, stepV0, stepV1, stepV2", exportData_bestOptSys_seidel);

}

void testSystemsPeterMA::saveSystemData_bestOptSys_RayTracing(unsigned int optSysNum, real timeGetBestOptSys, OpticalSystemElement optSystemElement, OpticalSystem_LLT bestOptSys_LLT, EvaluateManyOptSys_RayTracing EvManOptSys_rayTracing, real primWave, std::vector<VectorStructR3> fields, std::vector<Light_LLT> light_vec, std::vector<real> rmsZemax, std::vector<real> Var_vec_Zemax, std::vector<stepsWithoutMinWithoutMax> addInfos, std::vector< parameterTypeModeStruct> parameterTypeMode, std::string location, std::string nameExcel)
{
	std::vector<real> exportData_bestOptSys_rayTracing;
	exportData_bestOptSys_rayTracing.push_back(optSysNum);

	exportData_bestOptSys_rayTracing.push_back(timeGetBestOptSys);

	unsigned int posLastSurface = optSystemElement.getPosAndElement().size() - 1;

	// number evaluated opt Sys
	unsigned int evaluatedOptSys = EvManOptSys_rayTracing.getSysForCom().getAllPosOptSys_Element().size();
	exportData_bestOptSys_rayTracing.push_back(evaluatedOptSys);
	// convert LLT to Element
	OpticalSystemElement bestOptSysEle = optSystemElement.convertOptSys_LLT_T0_OptSys_HLT(optSystemElement, bestOptSys_LLT);
	bestOptSysEle.setRefractiveIndexAccordingToWavelength(primWave);
	// optical axis
	VectorStructR3 optA_E0 = fields[0];
	SequentialRayTracing seqTraceE0_optAxis(/*optical system element*/ bestOptSysEle,/*start point lightRay*/ optA_E0, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, light_vec);
	Spot spotE0_optA_bestOptSys(seqTraceE0_optAxis.getAllInterPointsAtSurf_i(posLastSurface), seqTraceE0_optAxis.getAllInterPointsAtSurf_i(posLastSurface)[0]);
	real spotOptAxisE0_bestOptSys = spotE0_optA_bestOptSys.getRMS_µm();
	exportData_bestOptSys_rayTracing.push_back(spotOptAxisE0_bestOptSys);
	// field 1 at y=1
	VectorStructR3 field1_E0 = fields[1];
	SequentialRayTracing seqTraceE0_field1_E0(/*optical system element*/ bestOptSysEle,/*start point lightRay*/ field1_E0, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, light_vec);
	Spot spotE0_field1_bestOptSys(seqTraceE0_field1_E0.getAllInterPointsAtSurf_i(posLastSurface), seqTraceE0_field1_E0.getAllInterPointsAtSurf_i(posLastSurface)[0]);
	real spotField1E0_bestOptSys = spotE0_field1_bestOptSys.getRMS_µm();
	exportData_bestOptSys_rayTracing.push_back(spotField1E0_bestOptSys);
	// field 2 at y=2
	VectorStructR3 field2_E0 = fields[2];
	SequentialRayTracing seqTraceE0_field2_E0(/*optical system element*/ bestOptSysEle,/*start point lightRay*/ field2_E0, /*rings*/ 6, /*arms*/ 8, /*refractive index*/ 1.0, light_vec);
	Spot spotE0_field2_bestOptSys(seqTraceE0_field2_E0.getAllInterPointsAtSurf_i(posLastSurface), seqTraceE0_field2_E0.getAllInterPointsAtSurf_i(posLastSurface)[0]);
	real spotField2E0_bestOptSys = spotE0_field2_bestOptSys.getRMS_µm();
	exportData_bestOptSys_rayTracing.push_back(spotField2E0_bestOptSys);


	OpticalSystem_LLT optSysE0_LLT = bestOptSysEle.getOptSys_LLT_buildSystem();
	std::cout << "spot optA E0: " << spotOptAxisE0_bestOptSys << std::endl;
	std::cout << "spot field1 E0: " << spotField1E0_bestOptSys << std::endl;
	std::cout << "spot field2 E0: " << spotField2E0_bestOptSys << std::endl;
	real sumRMS_TOM = spotOptAxisE0_bestOptSys + spotField1E0_bestOptSys + spotField2E0_bestOptSys;
	exportData_bestOptSys_rayTracing.push_back(sumRMS_TOM);
	std::cout << "sum rms TOM: " << sumRMS_TOM << std::endl;

	real ZemaxSumRMS = Math::sumAllVectorValues(rmsZemax);
	exportData_bestOptSys_rayTracing.push_back(ZemaxSumRMS);
	std::cout << "sum rms Zemax: " << ZemaxSumRMS << std::endl;

	real V0;
	real V1;
	real V2;

	// check variables V0
	kindOfParameter kindParaV0 = parameterTypeMode[0].getKindParam();
	unsigned int posV0 = parameterTypeMode[0].getSurfaceNum();
	if (kindParaV0 == radius)
	{
		V0 = bestOptSys_LLT.getPosAndInteractingSurface()[posV0].getSurfaceInterRay_ptr()->getRadius() * bestOptSys_LLT.getPosAndInteractingSurface()[posV0].getSurfaceInterRay_ptr()->getDirection().getZ();
		exportData_bestOptSys_rayTracing.push_back(V0);
	}
	else if (kindParaV0 == position)
	{
		real posMinOne = bestOptSys_LLT.getPosAndInteractingSurface()[posV0 - 1].getSurfaceInterRay_ptr()->getPoint().getZ();
		real posZero = bestOptSys_LLT.getPosAndInteractingSurface()[posV0].getSurfaceInterRay_ptr()->getPoint().getZ();
		V0 = posZero - posMinOne;
		exportData_bestOptSys_rayTracing.push_back(V0);
	}

	// check variables V1
	kindOfParameter kindParaV1 = parameterTypeMode[1].getKindParam();
	unsigned int posV1 = parameterTypeMode[1].getSurfaceNum();
	if (kindParaV1 == radius)
	{
		V1 = bestOptSys_LLT.getPosAndInteractingSurface()[posV1].getSurfaceInterRay_ptr()->getRadius() * bestOptSys_LLT.getPosAndInteractingSurface()[posV1].getSurfaceInterRay_ptr()->getDirection().getZ();
		exportData_bestOptSys_rayTracing.push_back(V1);
	}
	else if (kindParaV1 == position)
	{
		real posMinOne = bestOptSys_LLT.getPosAndInteractingSurface()[posV1 - 1].getSurfaceInterRay_ptr()->getPoint().getZ();
		real posZero = bestOptSys_LLT.getPosAndInteractingSurface()[posV1].getSurfaceInterRay_ptr()->getPoint().getZ();
		V1 = posZero - posMinOne;
		exportData_bestOptSys_rayTracing.push_back(V1);
	}

	// check variables V2
	kindOfParameter kindParaV2 = parameterTypeMode[2].getKindParam();
	unsigned int posV2 = parameterTypeMode[2].getSurfaceNum();
	if (kindParaV2 == radius)
	{
		V2 = bestOptSys_LLT.getPosAndInteractingSurface()[posV2].getSurfaceInterRay_ptr()->getRadius() * bestOptSys_LLT.getPosAndInteractingSurface()[posV2].getSurfaceInterRay_ptr()->getDirection().getZ();
		exportData_bestOptSys_rayTracing.push_back(V2);
	}
	else if (kindParaV2 == position)
	{
		real posMinOne = bestOptSys_LLT.getPosAndInteractingSurface()[posV2 - 1].getSurfaceInterRay_ptr()->getPoint().getZ();
		real posZero = bestOptSys_LLT.getPosAndInteractingSurface()[posV2].getSurfaceInterRay_ptr()->getPoint().getZ();
		V2 = posZero - posMinOne;
		exportData_bestOptSys_rayTracing.push_back(V2);
	}

	real V1_Zemax = Var_vec_Zemax[0];
	exportData_bestOptSys_rayTracing.push_back(V1_Zemax);
	real V2_Zemax = Var_vec_Zemax[1];
	exportData_bestOptSys_rayTracing.push_back(V2_Zemax);
	real V3_Zemax = Var_vec_Zemax[2];
	exportData_bestOptSys_rayTracing.push_back(V3_Zemax);
	real stepV0 = addInfos[0].getSteps();
	exportData_bestOptSys_rayTracing.push_back(stepV0);
	real stepV1 = addInfos[1].getSteps();
	exportData_bestOptSys_rayTracing.push_back(stepV1);
	real stepV2 = addInfos[2].getSteps();
	exportData_bestOptSys_rayTracing.push_back(stepV2);

	// export Data
	inportExportData::exportDataToExcel_vector(location, nameExcel, "numOptSys, timeToGetBestOptSys, evaluatedOptSys, spotOptAxisTOM, spotField1TOM, spotField2TOM, sumRMS_TOM, sumRMS_Zemax, V0TOM, V1TOM, V2TOM, V0Zemax, V1Zemax, V2Zemax, stepV0, stepV1, stepV2", exportData_bestOptSys_rayTracing);
}