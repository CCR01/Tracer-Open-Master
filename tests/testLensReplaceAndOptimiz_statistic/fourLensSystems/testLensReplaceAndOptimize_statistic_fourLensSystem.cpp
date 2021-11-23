#include "testLensReplaceAndOptimize_statistic_fourLensSystem.h"

#include "..\..\OpticalSystemElement\OpticalSystemElement.h"

//surface HLT
#include "..\..\..\SurfaceElements\PlanElement.h"
#include "..\..\..\SurfaceElements\SphericalElement.h"
#include "..\..\..\SurfaceElements\ApertureStopElement.h"

// often use
#include "..\..\..\oftenUseNamespace\oftenUseNamespace.h"
// lens replace
#include "..\..\..\lensReplace\LensReplace.h"
// lens replace and optimize
#include "..\..\..\LensReplaceAndOptimize\LensReplaceAndOptimize.h"
// inport export
#include "..\..\..\Inport_Export_Data\Inport_Export_Data.h"


testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLensReplaceAndOptimize_statistic_FOUR_LensSystem()
{
	loadImportantParameter();
	turn_OFF_debugMode();
}

testLensReplaceAndOptimize_statistic_FOUR_LensSystem::~testLensReplaceAndOptimize_statistic_FOUR_LensSystem() {}

typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr<InteractionRay_LLT> interaction_ptr;

// load importent parameter
void testLensReplaceAndOptimize_statistic_FOUR_LensSystem::loadImportantParameter()
{
	// load glass catalog
	mGlasses.loadGlassCatalog_Schott();

	// light FdC
	mWave587d = 587.5618;
	mWave486F = 486.1327;
	mWave656C = 656.2725;
	mWavelength_FdV_vec.push_back(mWave587d);
	mWavelength_FdV_vec.push_back(mWave486F);
	mWavelength_FdV_vec.push_back(mWave656C);

	mLight587 = oftenUse::getDefaultLight();
	mLight587.setWavelength(mWave587d);
	mLight486 = oftenUse::getDefaultLight();
	mLight486.setWavelength(mWave486F);
	mLight656 = oftenUse::getDefaultLight();
	mLight656.setWavelength(mWave656C);

	mLight_FdC_Vec.push_back(mLight587);
	mLight_FdC_Vec.push_back(mLight486);
	mLight_FdC_Vec.push_back(mLight656);


	// field obj
	mField0 = { 0.0,0.0,0.0 };
	mField283 = { 0.0,2.83, 0.0 };
	mField4 = { 0.0,4.0,0.0 };
	mField_vec.push_back(mField0);
	mField_vec.push_back(mField283);
	mField_vec.push_back(mField4);

	// field angles
	mFieldAngel_X_0 = 0.0;
	mFieldAngel_Y_0 = 0.0;
	mFieldAngle_Y_707 = 7.07;
	mFieldAngle_Y_10 = 10.0;
	mFieldAngle_Vec_X.push_back(mFieldAngel_X_0);
	mFieldAngle_Vec_X.push_back(mFieldAngel_X_0);
	mFieldAngle_Vec_X.push_back(mFieldAngel_X_0);
	mFieldAngle_Vec_Y.push_back(mFieldAngel_Y_0);
	mFieldAngle_Vec_Y.push_back(mFieldAngle_Y_707);
	mFieldAngle_Vec_Y.push_back(mFieldAngle_Y_10);

	mTolerance = 0.1;
	mRings = 6;
	mArms = 8;

	mDefaulParaDLS = oftenUse::getDefaultPara_DLS(true);
	mDefaultParameterGenetic = oftenUse::getDafulatPara_Genetic(true);
	mPopulation = 1000.0;


	mNumberBestFitLenses = 3;
}

// debug mode
void testLensReplaceAndOptimize_statistic_FOUR_LensSystem::turn_ON_debugMode()
{
	mDebugMode = true;
}
void testLensReplaceAndOptimize_statistic_FOUR_LensSystem::turn_OFF_debugMode()
{
	mDebugMode = false;
}

// export all statistic data replace two lenses
void testLensReplaceAndOptimize_statistic_FOUR_LensSystem::exportAllStatisticDataReplace_FOUR_LensesGeneticAndDLS_12()
{
	std::string dataToExportString = "merit_GeneticAndDLS_12, duration_GeneticAndDLS_12, replaceSequence_GeneticAndDLS_12, bestLensNumber_GeneticAndDLS_12 ";
	std::vector<real> dataToExport_vec;
	dataToExport_vec.resize(10);

	std::string location{};
	if (mObj)
	{
		location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems";
	}
	else if (mInf)
	{
		location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/infinity";
	}

	//inportExportData::removeDateCSV(location, nameExcel);
	std::string nameExcel = "data_fourLensSystems";
	for (unsigned int i = 0; i < mSaveAllResults_FOUR_LensSystem.size(); i++)
	{
		inportExportData::exportDataToExcel_makeOneRowSpace(location, nameExcel);
		inportExportData::exportDataToExcel_name(location, nameExcel, mSaveAllResults_FOUR_LensSystem[i][0].getExample());


		for (unsigned int k = 0; k < mSaveAllResults_FOUR_LensSystem[0].size(); k++)
		{

			// Genetic and DLS 12 -> four lens system
			dataToExport_vec[0] = mSaveAllResults_FOUR_LensSystem[i][k].getMeritVaL_GeneticAndDLS_12();
			dataToExport_vec[1] = mSaveAllResults_FOUR_LensSystem[i][k].getDurationTime_GeneticAndDLS_12();

			dataToExport_vec[2] = mSaveAllResults_FOUR_LensSystem[i][k].getReplacedSequence_GeneticAndDLS12()[0];
			dataToExport_vec[3] = mSaveAllResults_FOUR_LensSystem[i][k].getReplacedSequence_GeneticAndDLS12()[1];
			dataToExport_vec[4] = mSaveAllResults_FOUR_LensSystem[i][k].getReplacedSequence_GeneticAndDLS12()[2];
			dataToExport_vec[5] = mSaveAllResults_FOUR_LensSystem[i][k].getReplacedSequence_GeneticAndDLS12()[3];

			dataToExport_vec[6] = mSaveAllResults_FOUR_LensSystem[i][k].getBestLensNumberWasTaken()[0];
			dataToExport_vec[7] = mSaveAllResults_FOUR_LensSystem[i][k].getBestLensNumberWasTaken()[1];
			dataToExport_vec[8] = mSaveAllResults_FOUR_LensSystem[i][k].getBestLensNumberWasTaken()[2];
			dataToExport_vec[9] = mSaveAllResults_FOUR_LensSystem[i][k].getBestLensNumberWasTaken()[3];


			inportExportData::exportDataToExcel_vector(location, nameExcel, dataToExportString, dataToExport_vec);

		}


	}
}

// super fct
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_superFct_obj()
{
	std::vector<bool> workTheSystem;

	mInf = false;
	mObj = true;

	// debug mode
	turn_ON_debugMode();
	//

	// debug
	if (mDebugMode)
	{
		mDefaulParaDLS.setMaxInterations(1);
		mDefaultParameterGenetic.setMaxInterationGenetic(1);
		mPopulation = 5;
		mNumberBestFitLenses = 1;
	}

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems";
	std::string name = "testLensReplaceAndOptimize_statistic_FOUR_LensSystem";


	//// E0 four lens system
	//bool checkE0_FOUR_LensSystem = testLRaO_stat_FOUR_lensSystem_E0("E0_FOUR_LensSystem");
	//workTheSystem.push_back(checkE0_FOUR_LensSystem);
	//if (checkE0_FOUR_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E0 four lens system worked"); };
	//
	//// E1 four lens system
	//bool checkE1_FOUR_LensSystem = testLRaO_stat_FOUR_lensSystem_E1("E1_FOUR_LensSystem");
	//workTheSystem.push_back(checkE1_FOUR_LensSystem);
	//if (checkE1_FOUR_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E1 four lens system worked"); };
	//
	//// E2 four lens system
	//bool checkE2_FOUR_LensSystem = testLRaO_stat_FOUR_lensSystem_E2("E2_FOUR_LensSystem");
	//workTheSystem.push_back(checkE2_FOUR_LensSystem);
	//if (checkE2_FOUR_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E2 four lens system worked"); };
	//
	//// E3 four lens system
	//bool checkE3_FOUR_LensSystem = testLRaO_stat_FOUR_lensSystem_E3("E3_FOUR_LensSystem");
	//workTheSystem.push_back(checkE3_FOUR_LensSystem);
	//if (checkE3_FOUR_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E3 four lens system worked"); };
	//
	//// E4 four lens system
	//bool checkE4_FOUR_LensSystem = testLRaO_stat_FOUR_lensSystem_E4("E4_FOUR_LensSystem");
	//workTheSystem.push_back(checkE4_FOUR_LensSystem);
	//if (checkE4_FOUR_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E4 four lens system worked"); };
	//
	//// E5 four lens system
	//bool checkE5_FOUR_LensSystem = testLRaO_stat_FOUR_lensSystem_E5("E5_FOUR_LensSystem");
	//workTheSystem.push_back(checkE5_FOUR_LensSystem);
	//if (checkE5_FOUR_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E5 four lens system worked"); };
	//
	//// E6 four lens system
	//bool checkE6_FOUR_LensSystem = testLRaO_stat_FOUR_lensSystem_E6("E6_FOUR_LensSystem");
	//workTheSystem.push_back(checkE6_FOUR_LensSystem);
	//if (checkE6_FOUR_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E6 four lens system worked"); };
	//
	//// E7 four lens system
	//bool checkE7_FOUR_LensSystem = testLRaO_stat_FOUR_lensSystem_E7("E7_FOUR_LensSystem");
	//workTheSystem.push_back(checkE7_FOUR_LensSystem);
	//if (checkE7_FOUR_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E7 four lens system worked"); };
	//
	//// E8 four lens system
	//bool checkE8_FOUR_LensSystem = testLRaO_stat_FOUR_lensSystem_E8("E8_FOUR_LensSystem");
	//workTheSystem.push_back(checkE8_FOUR_LensSystem);
	//if (checkE8_FOUR_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E8 four lens system worked"); };
	//
	//// E9 four lens system
	//bool checkE9_FOUR_LensSystem = testLRaO_stat_FOUR_lensSystem_E9("E9_FOUR_LensSystem");
	//workTheSystem.push_back(checkE9_FOUR_LensSystem);
	//if (checkE9_FOUR_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E9 four lens system worked"); };
	//
	//// E10 four lens system
	//bool checkE10_FOUR_LensSystem = testLRaO_stat_FOUR_lensSystem_E10("E10_FOUR_LensSystem");
	//workTheSystem.push_back(checkE10_FOUR_LensSystem);
	//if (checkE10_FOUR_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E10 four lens system worked"); };
	//
	//// E11 four lens system
	//bool checkE11_FOUR_LensSystem = testLRaO_stat_FOUR_lensSystem_E11("E11_FOUR_LensSystem");
	//workTheSystem.push_back(checkE11_FOUR_LensSystem);
	//if (checkE11_FOUR_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E11 four lens system worked"); };
	//
	//// E12 four lens system
	//bool checkE12_FOUR_LensSystem = testLRaO_stat_FOUR_lensSystem_E12("E12_FOUR_LensSystem");
	//workTheSystem.push_back(checkE12_FOUR_LensSystem);
	//if (checkE12_FOUR_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E12 four lens system worked"); };
	//
	//// E13 four lens system
	//bool checkE13_FOUR_LensSystem = testLRaO_stat_FOUR_lensSystem_E13("E13_FOUR_LensSystem");
	//workTheSystem.push_back(checkE13_FOUR_LensSystem);
	//if (checkE13_FOUR_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E13 four lens system worked"); };
	//
	//// E14 four lens system
	//bool checkE14_FOUR_LensSystem = testLRaO_stat_FOUR_lensSystem_E14("E14_FOUR_LensSystem");
	//workTheSystem.push_back(checkE14_FOUR_LensSystem);
	//if (checkE14_FOUR_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E14 four lens system worked"); };
	//
	//// E15 four lens system
	//bool checkE15_FOUR_LensSystem = testLRaO_stat_FOUR_lensSystem_E15("E15_FOUR_LensSystem");
	//workTheSystem.push_back(checkE15_FOUR_LensSystem);
	//if (checkE15_FOUR_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E15 four lens system worked"); };
	//
	//// E16 four lens system
	//bool checkE16_FOUR_LensSystem = testLRaO_stat_FOUR_lensSystem_E16("E16_FOUR_LensSystem");
	//workTheSystem.push_back(checkE16_FOUR_LensSystem);
	//if (checkE16_FOUR_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E16 four lens system worked"); };
	//
	//// E17 four lens system
	//bool checkE17_FOUR_LensSystem = testLRaO_stat_FOUR_lensSystem_E17("E17_FOUR_LensSystem");
	//workTheSystem.push_back(checkE17_FOUR_LensSystem);
	//if (checkE17_FOUR_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E17 four lens system worked"); };
	//
	//// E18 four lens system
	//bool checkE18_FOUR_LensSystem = testLRaO_stat_FOUR_lensSystem_E18("E18_FOUR_LensSystem");
	//workTheSystem.push_back(checkE18_FOUR_LensSystem);
	//if (checkE18_FOUR_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E18 four lens system worked"); };
	//
	//// E19 four lens system
	//bool checkE19_FOUR_LensSystem = testLRaO_stat_FOUR_lensSystem_E19("E19_FOUR_LensSystem");
	//workTheSystem.push_back(checkE19_FOUR_LensSystem);
	//if (checkE19_FOUR_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E19 four lens system worked"); };


	exportAllStatisticDataReplace_FOUR_LensesGeneticAndDLS_12();



	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}

// do the statistic evaluation
std::vector<saveLRaO_GeneticAndDLS_12_statistic> testLensReplaceAndOptimize_statistic_FOUR_LensSystem::doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_obj(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example)
{
	unsigned int numberLenses = oftenUse::findLensesInOptSysEle(optSysEle).size();
	std::vector<saveLRaO_GeneticAndDLS_12_statistic> LRaO_statistic_GeneticAndDLS_12(numberLenses);
	LRaO_statistic_GeneticAndDLS_12.resize(5);

	for (unsigned int k = 0; k < LRaO_statistic_GeneticAndDLS_12.size(); ++k)
	{
		LRaO_statistic_GeneticAndDLS_12[k].setNumberOfLensesInOptSys(numberLenses);
		LRaO_statistic_GeneticAndDLS_12[k].resizeBestLensNumberWasTaken(numberLenses);
		LRaO_statistic_GeneticAndDLS_12[k].setExample(example);
	}

	std::vector<replaceSequence> repSeq_vec = { replaceSequence::leftToRight, replaceSequence::RightToLeft, replaceSequence::maxSeidelAberLens, replaceSequence::minSeidelAberLens, replaceSequence::allPossibleSequences };

	OpticalSystemElement tempOptSysEle_initial;
	replaceSequence tempReplaceSequence;
	optimizeMethode optiMethode = optimizeMethode::GeneticAndDLS_12;
	Light_LLT light = oftenUse::getDefaultLight();
	real tempBestMeritVal{};
	std::vector<unsigned int> temUsedReplaceSeq{};
	std::vector<OptSysEle_Merit_LensType> tempOptSysMeritLensType;

	std::string nameOptimizationMethode = "GeneticAndDLS_12";
	std::vector<std::string> nameLoc = { "/leftToRight", "/rightToLeft", "/maxSeidel", "/minSeidel", "/allSequences" };
	std::vector<std::string> nameSequences = { "leftToRight", "rightToLeft", "maxSeidel", "minSeidel", "allSequences" };
	std::string tempLocation{};

	for (unsigned int posRepSeq = 0; posRepSeq < repSeq_vec.size(); ++posRepSeq)
	{
		tempReplaceSequence = repSeq_vec[posRepSeq];
		tempLocation = location + nameLoc[posRepSeq];

		tempOptSysEle_initial = optSysEle.getDeepCopyOptSysEle();

		LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
		testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(targetCarPoints);
		testLensReplaceAndOptiSuperFct.setDefaulParaDLS(mDefaulParaDLS);
		testLensReplaceAndOptiSuperFct.setDefaultParaGenetic(mDefaultParameterGenetic);
		testLensReplaceAndOptiSuperFct.setPopulation(mPopulation);
		testLensReplaceAndOptiSuperFct.setLoad_ALL_LensCatalogs();

		if (mDebugMode)
		{
			testLensReplaceAndOptiSuperFct.turn_ON_DebugMode();
		}

		// start time
		auto tempStartTime = std::chrono::high_resolution_clock::now();
		testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(tempOptSysEle_initial, mField_vec, mWavelength_FdV_vec, mRings, mArms, optiMethode, /*number best fit lenses*/ mNumberBestFitLenses, true, tempReplaceSequence, light);
		// end time
		auto tempEndTime = std::chrono::high_resolution_clock::now();

		OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();

		std::chrono::duration<double> totalDuration_secondes = tempEndTime - tempStartTime;
		tempBestMeritVal = testLensReplaceAndOptiSuperFct.getBestMeritVal();
		temUsedReplaceSeq = testLensReplaceAndOptiSuperFct.getReplacedSequence();
		tempOptSysMeritLensType = testLensReplaceAndOptiSuperFct.getBestCatalogLensesForreplace();

		std::string exampleAndOptiMethode = example + "_" + nameOptimizationMethode;
		testLensReplaceAndOptiSuperFct.exportBestParameterCatalogForReplaceTXT(tempLocation, exampleAndOptiMethode);

		std::string nameOptSys = example + "_replacedOptSys_";
		std::string totalNameOptSys = nameOptSys + nameOptimizationMethode;
		inportExportData::saveOpticalSystemAsTXT(optSysEle_lensRepSuperFct, 550.0, tempLocation, totalNameOptSys);

		// export rms values
		std::vector<std::string> nameDoubel_vec = { "fiel_0", "field_283", "field_4" };
		std::string replaceRMSvalue_str = "replaceRMSvalue";
		std::string nameTXT_ReplaceRMSvalueFields = replaceRMSvalue_str + "_" + nameSequences[posRepSeq];
		std::vector<real> rmsVecReplaceSys = oftenUse::getRMSoptSysHLT(optSysEle_lensRepSuperFct, mField_vec, mWavelength_FdV_vec, mRings, mArms);
		inportExportData::saveVecDoubleInTXT(tempLocation, nameTXT_ReplaceRMSvalueFields, nameDoubel_vec, rmsVecReplaceSys, true);

		std::vector<unsigned int> tempBestLensWasTaken;
		tempBestLensWasTaken.resize(tempOptSysMeritLensType.size());
		for (unsigned int i = 0; i < tempOptSysMeritLensType.size(); ++i)
		{
			tempBestLensWasTaken[i] = tempOptSysMeritLensType[i].getPositionInBestMatchLensVec();
		}


		LRaO_statistic_GeneticAndDLS_12[posRepSeq].setMeritVal_GeneticAndDLS_12(tempBestMeritVal);
		LRaO_statistic_GeneticAndDLS_12[posRepSeq].setDurationTime_GeneticAndDLS_12(totalDuration_secondes.count());
		LRaO_statistic_GeneticAndDLS_12[posRepSeq].setReplaceSequence_GeneticAndDLS(temUsedReplaceSeq);
		LRaO_statistic_GeneticAndDLS_12[posRepSeq].setBestLensNumberWasTaken(tempBestLensWasTaken);

	}

	return LRaO_statistic_GeneticAndDLS_12;
}

std::vector<saveLRaO_GeneticAndDLS_12_statistic> testLensReplaceAndOptimize_statistic_FOUR_LensSystem::doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_inf(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example)
{
	unsigned int numberLenses = oftenUse::findLensesInOptSysEle(optSysEle).size();
	std::vector<saveLRaO_GeneticAndDLS_12_statistic> LRaO_statistic_GeneticAndDLS_12(numberLenses);
	LRaO_statistic_GeneticAndDLS_12.resize(5);

	for (unsigned int k = 0; k < LRaO_statistic_GeneticAndDLS_12.size(); ++k)
	{
		LRaO_statistic_GeneticAndDLS_12[k].setNumberOfLensesInOptSys(numberLenses);
		LRaO_statistic_GeneticAndDLS_12[k].resizeBestLensNumberWasTaken(numberLenses);
		LRaO_statistic_GeneticAndDLS_12[k].setExample(example);
	}

	std::vector<replaceSequence> repSeq_vec = { replaceSequence::leftToRight, replaceSequence::RightToLeft, replaceSequence::maxSeidelAberLens, replaceSequence::minSeidelAberLens, replaceSequence::allPossibleSequences };

	OpticalSystemElement tempOptSysEle_initial;
	replaceSequence tempReplaceSequence;
	optimizeMethode optiMethode = optimizeMethode::GeneticAndDLS_12;
	Light_LLT light = oftenUse::getDefaultLight();
	real tempBestMeritVal{};
	std::vector<unsigned int> temUsedReplaceSeq{};
	std::vector<OptSysEle_Merit_LensType> tempOptSysMeritLensType;

	std::string nameOptimizationMethode = "GeneticAndDLS_12";
	std::vector<std::string> nameLoc = { "/leftToRight", "/rightToLeft", "/maxSeidel", "/minSeidel", "/allSequences" };
	std::vector<std::string> nameSequences = { "leftToRight", "rightToLeft", "maxSeidel", "minSeidel", "allSequences" };
	std::string tempLocation{};

	for (unsigned int posRepSeq = 0; posRepSeq < repSeq_vec.size(); ++posRepSeq)
	{
		tempReplaceSequence = repSeq_vec[posRepSeq];
		tempLocation = location + nameLoc[posRepSeq];

		tempOptSysEle_initial = optSysEle.getDeepCopyOptSysEle();

		LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
		testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(targetCarPoints);
		testLensReplaceAndOptiSuperFct.setDefaulParaDLS(mDefaulParaDLS);
		testLensReplaceAndOptiSuperFct.setDefaultParaGenetic(mDefaultParameterGenetic);
		testLensReplaceAndOptiSuperFct.setPopulation(mPopulation);
		testLensReplaceAndOptiSuperFct.setLoad_ALL_LensCatalogs();

		if (mDebugMode)
		{
			testLensReplaceAndOptiSuperFct.turn_ON_DebugMode();
		}

		// start time
		auto tempStartTime = std::chrono::high_resolution_clock::now();
		testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(tempOptSysEle_initial, mFieldAngle_Vec_X, mFieldAngle_Vec_Y, mWavelength_FdV_vec, mRings, mArms, optiMethode, /*number best fit lenses*/ mNumberBestFitLenses, true, tempReplaceSequence, light);
		// end time
		auto tempEndTime = std::chrono::high_resolution_clock::now();

		OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();

		std::chrono::duration<double> totalDuration_secondes = tempEndTime - tempStartTime;
		tempBestMeritVal = testLensReplaceAndOptiSuperFct.getBestMeritVal();
		temUsedReplaceSeq = testLensReplaceAndOptiSuperFct.getReplacedSequence();
		tempOptSysMeritLensType = testLensReplaceAndOptiSuperFct.getBestCatalogLensesForreplace();

		std::string exampleAndOptiMethode = example + "_" + nameOptimizationMethode;
		testLensReplaceAndOptiSuperFct.exportBestParameterCatalogForReplaceTXT(tempLocation, exampleAndOptiMethode);

		std::string nameOptSys = example + "_replacedOptSys_";
		std::string totalNameOptSys = nameOptSys + nameOptimizationMethode;
		inportExportData::saveOpticalSystemAsTXT(optSysEle_lensRepSuperFct, 550.0, tempLocation, totalNameOptSys);

		// export rms values
		std::vector<std::string> nameDoubel_vec = { "fieldAngel_0", "fieldAngle_707", "fieldAngle_10" };
		std::string replaceRMSvalue_str = "replaceRMSvalue";
		std::string nameTXT_ReplaceRMSvalueFields = replaceRMSvalue_str + "_" + nameSequences[posRepSeq];
		std::vector<real> rmsVecReplaceSys = oftenUse::getRMSoptSysHLT(optSysEle_lensRepSuperFct, mFieldAngle_Vec_X, mFieldAngle_Vec_Y, mWavelength_FdV_vec, mRings, mArms);
		inportExportData::saveVecDoubleInTXT(tempLocation, nameTXT_ReplaceRMSvalueFields, nameDoubel_vec, rmsVecReplaceSys, true);

		std::vector<unsigned int> tempBestLensWasTaken;
		tempBestLensWasTaken.resize(tempOptSysMeritLensType.size());
		for (unsigned int i = 0; i < tempOptSysMeritLensType.size(); ++i)
		{
			tempBestLensWasTaken[i] = tempOptSysMeritLensType[i].getPositionInBestMatchLensVec();
		}


		LRaO_statistic_GeneticAndDLS_12[posRepSeq].setMeritVal_GeneticAndDLS_12(tempBestMeritVal);
		LRaO_statistic_GeneticAndDLS_12[posRepSeq].setDurationTime_GeneticAndDLS_12(totalDuration_secondes.count());
		LRaO_statistic_GeneticAndDLS_12[posRepSeq].setReplaceSequence_GeneticAndDLS(temUsedReplaceSeq);
		LRaO_statistic_GeneticAndDLS_12[posRepSeq].setBestLensNumberWasTaken(tempBestLensWasTaken);

	}

	return LRaO_statistic_GeneticAndDLS_12;
}

std::vector<saveLRaO_GeneticAndDLS_12_statistic>  testLensReplaceAndOptimize_statistic_FOUR_LensSystem::doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example)
{
	unsigned int numberLenses = oftenUse::findLensesInOptSysEle(optSysEle).size();
	std::vector<saveLRaO_GeneticAndDLS_12_statistic> LRaO_statistic_GeneticAndDLS_12(numberLenses);
	LRaO_statistic_GeneticAndDLS_12.resize(4);

	for (unsigned int k = 0; k < LRaO_statistic_GeneticAndDLS_12.size(); ++k)
	{
		LRaO_statistic_GeneticAndDLS_12[k].setNumberOfLensesInOptSys(numberLenses);
		LRaO_statistic_GeneticAndDLS_12[k].resizeBestLensNumberWasTaken(numberLenses);
		LRaO_statistic_GeneticAndDLS_12[k].setExample(example);
	}

	std::vector<replaceSequence> repSeq_vec = { replaceSequence::leftToRight, replaceSequence::RightToLeft, replaceSequence::maxSeidelAberLens, replaceSequence::minSeidelAberLens };

	OpticalSystemElement tempOptSysEle_initial;
	replaceSequence tempReplaceSequence;
	optimizeMethode optiMethode = optimizeMethode::GeneticAndDLS_12;
	Light_LLT light = oftenUse::getDefaultLight();
	real tempBestMeritVal{};
	std::vector<unsigned int> temUsedReplaceSeq{};
	std::vector<OptSysEle_Merit_LensType> tempOptSysMeritLensType;

	std::string nameOptimizationMethode = "GeneticAndDLS_12";
	std::vector<std::string> nameLoc = { "/leftToRight", "/rightToLeft", "/maxSeidel", "/minSeidel" };
	std::vector<std::string> nameSequences = { "leftToRight", "rightToLeft", "maxSeidel", "minSeidel" };
	std::string tempLocation{};

	for (unsigned int posRepSeq = 0; posRepSeq < repSeq_vec.size(); ++posRepSeq)
	{
		tempReplaceSequence = repSeq_vec[posRepSeq];
		tempLocation = location + nameLoc[posRepSeq];

		tempOptSysEle_initial = optSysEle.getDeepCopyOptSysEle();

		LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
		testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(targetCarPoints);
		testLensReplaceAndOptiSuperFct.setDefaulParaDLS(mDefaulParaDLS);
		testLensReplaceAndOptiSuperFct.setDefaultParaGenetic(mDefaultParameterGenetic);
		testLensReplaceAndOptiSuperFct.setPopulation(mPopulation);
		testLensReplaceAndOptiSuperFct.setLoad_ALL_LensCatalogs();

		if (mDebugMode)
		{
			testLensReplaceAndOptiSuperFct.turn_ON_DebugMode();
		}

		// start time
		auto tempStartTime = std::chrono::high_resolution_clock::now();
		testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(tempOptSysEle_initial, mFieldAngle_Vec_X, mFieldAngle_Vec_Y, mWavelength_FdV_vec, mRings, mArms, optiMethode, /*number best fit lenses*/ mNumberBestFitLenses, true, tempReplaceSequence, light);
		// end time
		auto tempEndTime = std::chrono::high_resolution_clock::now();

		OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();

		std::chrono::duration<double> totalDuration_secondes = tempEndTime - tempStartTime;
		tempBestMeritVal = testLensReplaceAndOptiSuperFct.getBestMeritVal();
		temUsedReplaceSeq = testLensReplaceAndOptiSuperFct.getReplacedSequence();
		tempOptSysMeritLensType = testLensReplaceAndOptiSuperFct.getBestCatalogLensesForreplace();

		std::string exampleAndOptiMethode = example + "_" + nameOptimizationMethode;
		testLensReplaceAndOptiSuperFct.exportBestParameterCatalogForReplaceTXT(tempLocation, exampleAndOptiMethode);

		std::string nameOptSys = example + "_replacedOptSys_";
		std::string totalNameOptSys = nameOptSys + nameOptimizationMethode;
		inportExportData::saveOpticalSystemAsTXT(optSysEle_lensRepSuperFct, 550.0, tempLocation, totalNameOptSys);

		// export rms values
		std::vector<std::string> nameDoubel_vec = { "fieldAngel_0", "fieldAngle_707", "fieldAngle_10" };
		std::string replaceRMSvalue_str = "replaceRMSvalue";
		std::string nameTXT_ReplaceRMSvalueFields = replaceRMSvalue_str + "_" + nameSequences[posRepSeq];
		std::vector<real> rmsVecReplaceSys = oftenUse::getRMSoptSysHLT(optSysEle_lensRepSuperFct, mFieldAngle_Vec_X, mFieldAngle_Vec_Y, mWavelength_FdV_vec, mRings, mArms);
		inportExportData::saveVecDoubleInTXT(tempLocation, nameTXT_ReplaceRMSvalueFields, nameDoubel_vec, rmsVecReplaceSys, true);

		std::vector<unsigned int> tempBestLensWasTaken;
		tempBestLensWasTaken.resize(tempOptSysMeritLensType.size());
		for (unsigned int i = 0; i < tempOptSysMeritLensType.size(); ++i)
		{
			tempBestLensWasTaken[i] = tempOptSysMeritLensType[i].getPositionInBestMatchLensVec();
		}


		LRaO_statistic_GeneticAndDLS_12[posRepSeq].setMeritVal_GeneticAndDLS_12(tempBestMeritVal);
		LRaO_statistic_GeneticAndDLS_12[posRepSeq].setDurationTime_GeneticAndDLS_12(totalDuration_secondes.count());
		LRaO_statistic_GeneticAndDLS_12[posRepSeq].setReplaceSequence_GeneticAndDLS(temUsedReplaceSeq);
		LRaO_statistic_GeneticAndDLS_12[posRepSeq].setBestLensNumberWasTaken(tempBestLensWasTaken);

	}

	return LRaO_statistic_GeneticAndDLS_12;
}

// do the statistic evaluation left to right , right to left, max seidel, min seidel
std::vector<saveLRaO_GeneticAndDLS_12_statistic>  testLensReplaceAndOptimize_statistic_FOUR_LensSystem::doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example)
{
	unsigned int numberLenses = oftenUse::findLensesInOptSysEle(optSysEle).size();
	std::vector<saveLRaO_GeneticAndDLS_12_statistic> LRaO_statistic_GeneticAndDLS_12(numberLenses);
	LRaO_statistic_GeneticAndDLS_12.resize(4);

	for (unsigned int k = 0; k < LRaO_statistic_GeneticAndDLS_12.size(); ++k)
	{
		LRaO_statistic_GeneticAndDLS_12[k].setNumberOfLensesInOptSys(numberLenses);
		LRaO_statistic_GeneticAndDLS_12[k].resizeBestLensNumberWasTaken(numberLenses);
		LRaO_statistic_GeneticAndDLS_12[k].setExample(example);
	}

	std::vector<replaceSequence> repSeq_vec = { replaceSequence::leftToRight, replaceSequence::RightToLeft, replaceSequence::maxSeidelAberLens, replaceSequence::minSeidelAberLens };

	OpticalSystemElement tempOptSysEle_initial;
	replaceSequence tempReplaceSequence;
	optimizeMethode optiMethode = optimizeMethode::GeneticAndDLS_12;
	Light_LLT light = oftenUse::getDefaultLight();
	real tempBestMeritVal{};
	std::vector<unsigned int> temUsedReplaceSeq{};
	std::vector<OptSysEle_Merit_LensType> tempOptSysMeritLensType;

	std::string nameOptimizationMethode = "GeneticAndDLS_12";
	std::vector<std::string> nameLoc = { "/leftToRight", "/rightToLeft", "/maxSeidel", "/minSeidel" };
	std::string tempLocation{};

	for (unsigned int posRepSeq = 0; posRepSeq < repSeq_vec.size(); ++posRepSeq)
	{
		tempReplaceSequence = repSeq_vec[posRepSeq];
		tempLocation = location + nameLoc[posRepSeq];

		tempOptSysEle_initial = optSysEle.getDeepCopyOptSysEle();

		LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
		testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(targetCarPoints);
		testLensReplaceAndOptiSuperFct.setDefaulParaDLS(mDefaulParaDLS);
		testLensReplaceAndOptiSuperFct.setDefaultParaGenetic(mDefaultParameterGenetic);
		testLensReplaceAndOptiSuperFct.setPopulation(mPopulation);
		testLensReplaceAndOptiSuperFct.setLoad_ALL_LensCatalogs();

		if (mDebugMode)
		{
			testLensReplaceAndOptiSuperFct.turn_ON_DebugMode();
		}

		// start time
		auto tempStartTime = std::chrono::high_resolution_clock::now();
		testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(tempOptSysEle_initial, mField_vec, mWavelength_FdV_vec, mRings, mArms, optiMethode, /*number best fit lenses*/ mNumberBestFitLenses, true, tempReplaceSequence, light);
		// end time
		auto tempEndTime = std::chrono::high_resolution_clock::now();

		OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();

		std::chrono::duration<double> totalDuration_secondes = tempEndTime - tempStartTime;
		tempBestMeritVal = testLensReplaceAndOptiSuperFct.getBestMeritVal();
		temUsedReplaceSeq = testLensReplaceAndOptiSuperFct.getReplacedSequence();
		tempOptSysMeritLensType = testLensReplaceAndOptiSuperFct.getBestCatalogLensesForreplace();

		std::string exampleAndOptiMethode = example + "_" + nameOptimizationMethode;
		testLensReplaceAndOptiSuperFct.exportBestParameterCatalogForReplaceTXT(tempLocation, exampleAndOptiMethode);

		std::string nameOptSys = example + "_replacedOptSys_";
		std::string totalNameOptSys = nameOptSys + nameOptimizationMethode;
		inportExportData::saveOpticalSystemAsTXT(optSysEle_lensRepSuperFct, 550.0, tempLocation, totalNameOptSys);

		std::vector<unsigned int> tempBestLensWasTaken;
		tempBestLensWasTaken.resize(tempOptSysMeritLensType.size());
		for (unsigned int i = 0; i < tempOptSysMeritLensType.size(); ++i)
		{
			tempBestLensWasTaken[i] = tempOptSysMeritLensType[i].getPositionInBestMatchLensVec();
		}


		LRaO_statistic_GeneticAndDLS_12[posRepSeq].setMeritVal_GeneticAndDLS_12(tempBestMeritVal);
		LRaO_statistic_GeneticAndDLS_12[posRepSeq].setDurationTime_GeneticAndDLS_12(totalDuration_secondes.count());
		LRaO_statistic_GeneticAndDLS_12[posRepSeq].setReplaceSequence_GeneticAndDLS(temUsedReplaceSeq);
		LRaO_statistic_GeneticAndDLS_12[posRepSeq].setBestLensNumberWasTaken(tempBestLensWasTaken);

	}

	return LRaO_statistic_GeneticAndDLS_12;
}

// E0 four lens system
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E0(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/2.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S7(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S8(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	SphericalElement S9(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S10(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF6_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S11(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());

	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,100.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E0_ptr = AperStop0_E0.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 239.421, 211.662,186.606 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E0";
	std::string nameStartSys = "startSys_E0_fourLensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(5.597855);
	tarCarP.setTargetMag(-0.752465);

	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E1 four lens system
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E1(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/2.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK10_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,48.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNLAK10_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S3(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,53.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S4(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,59.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF40_S1());
	SphericalElement S5(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,62.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNLASF40_S1());
	SphericalElement S6(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,68.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S7(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,74.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S8(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,78.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S9(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,88.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S10(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,96.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S11(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,103.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,123.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E1_ptr = AperStop0_E1.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 87.672, 157.065, 283.666 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E1";
	std::string nameStartSys = "startSys_E1_fourLensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.4972);
	tarCarP.setTargetMag(-0.4724);

	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E2 four lens system
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E2(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 30.0;

	ApertureStopElement S0(/* semi height*/ 6.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());

	SphericalElement S4(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,133.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,148.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK10_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,163.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK10_S1());

	SphericalElement S7(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,179.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S8(/*radius*/ 220.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,194.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S9(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,209.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());
	SphericalElement S10(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,224.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNF2_S1(), /*refractive index B*/mGlasses.getNSSK8_S1());
	SphericalElement S11(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,239.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNF2_S1());

	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,259.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E2_ptr = AperStop0_E2.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 162.701, 209.460, 259.420 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E2";
	std::string nameStartSys = "startSys_E2_fourLensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.655386);
	tarCarP.setTargetMag(-0.635183);

	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E3 four lens system
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E3(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 20.0;

	ApertureStopElement S0(/* semi height*/ 3.5, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S2(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,67.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF56_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S3(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());

	SphericalElement S4(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,109.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF52_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,123.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF52_S1());

	SphericalElement S7(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,138.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S8(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,149.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S9(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,164.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S10(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,180.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF56_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S11(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,187.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());

	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,217.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E3_ptr = AperStop0_E3.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 369.153, 331.324, 306.908 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E3";
	std::string nameStartSys = "startSys_E3_fourLensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(5.601544);
	tarCarP.setTargetMag(-1.120231);

	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E4 four lens system
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E4(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 15.0;

	ApertureStopElement S0(/* semi height*/ 4.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S2(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S3(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,155.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNF2_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S5(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,175.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNF2_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,190.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S7(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,200.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S8(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,215.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S9(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,230.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK10_S1());
	SphericalElement S10(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,245.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAK1_S1(), /*refractive index B*/mGlasses.getNLAK10_S1());
	SphericalElement S11(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,255.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK1_S1());

	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,280.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E4_ptr = AperStop0_E4.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 165.695, 193.810, 236.795 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E4";
	std::string nameStartSys = "startSys_E4_fourLensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.32533);
	tarCarP.setTargetMag(-0.443188);

	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E5 four lens system
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E5(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/ 2.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S4(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK2_S1());
	SphericalElement S5(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK2_S1());

	SphericalElement S6(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,125.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S7(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S9(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,160.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNF2_S1());
	SphericalElement S10(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,175.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF52_S1(), /*refractive index B*/mGlasses.getNF2_S1());
	SphericalElement S11(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,185.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF52_S1());

	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,200.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E5_ptr = AperStop0_E5.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 201.026, 224.113, 246.876 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E5";
	std::string nameStartSys = "startSys_E5_fourLensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(5.507166);
	tarCarP.setTargetMag(-0.489508);

	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E6 four lens system
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E6(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 30.0;

	ApertureStopElement S0(/* semi height*/ 5.5, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNKF9_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,125.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNKF9_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S3(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,145.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S4(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,165.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,190.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S6(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,210.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBASF64_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S7(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,235.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBASF64_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S8(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,255.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S9(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,275.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S10(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,300.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S11(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,320.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,350.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E6_ptr = AperStop0_E6.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 360.745, 362.563, 381.369 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E6";
	std::string nameStartSys = "startSys_E6_fourLensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.960112);
	tarCarP.setTargetMag(-0.540774);

	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E7 four lens system
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E7(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 20.0;

	ApertureStopElement S0(/* semi height*/ 3.5, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,78.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 110.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,91.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	SphericalElement S4(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,106.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S5(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,116.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());

	SphericalElement S6(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,126.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S7(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,138.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF4_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,146.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF4_S1());

	SphericalElement S9(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,160.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S10(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,174.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNF2_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S11(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,182.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNF2_S1());

	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,192.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E7_ptr = AperStop0_E7.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 110.096, 160.432, 230.806 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E7";
	std::string nameStartSys = "startSys_E7_fourLensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.592105);
	tarCarP.setTargetMag(-0.517591);

	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E8 four lens system
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E8(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 15.0;

	ApertureStopElement S0(/* semi height*/ 3.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,58.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAK4_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,64.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK4_S1());

	SphericalElement S4(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,69.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());
	SphericalElement S5(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,74.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());

	SphericalElement S6(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,79.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S7(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,86.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF4_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF4_S1());

	SphericalElement S9(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());
	SphericalElement S10(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,101.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSSK8_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S11(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,104.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,122.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E8_ptr = AperStop0_E8.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 71.079, 140.109, 203.888 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E8";
	std::string nameStartSys = "startSys_E8_fourLensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.052276);
	tarCarP.setTargetMag(-0.614261);

	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E9 four lens system
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E9(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 25.0;

	ApertureStopElement S0(/* semi height*/ 4.5, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 160.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 130.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,72.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,87.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S4(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNK5_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S5(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,103.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNK5_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S6(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,111.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF10_S1());
	SphericalElement S7(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,126.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLASF44_S1(), /*refractive index B*/mGlasses.getNSF10_S1());
	SphericalElement S8(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,136.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF44_S1());

	SphericalElement S9(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,146.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK8_S1());
	SphericalElement S10(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,166.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNLAK8_S1());
	SphericalElement S11(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,182.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,212.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E9_ptr = AperStop0_E9.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 194.633, 278.513, 370.151 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E9";
	std::string nameStartSys = "startSys_E9_fourLensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.64492);
	tarCarP.setTargetMag(-0.537277);

	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E10 four lens system
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E10(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/ 2.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,57.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,72.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,77.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,92.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,98.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S7(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,103.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S8(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,114.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF6_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S9(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,122.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());

	SphericalElement S10(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,127.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S11(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,139.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,149.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S9.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E10_ptr = AperStop0_E10.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 73.883, 56.895, 75.316 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E10";
	std::string nameStartSys = "startSys_E10_fourLensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(5.397833);
	tarCarP.setTargetMag(-0.720039);

	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E11 four lens system
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E11(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 20.0;

	ApertureStopElement S0(/* semi height*/ 4.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,82.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S3(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S4(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,98.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S5(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S6(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S7(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,118.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,126.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S9(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,134.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());

	SphericalElement S10(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,142.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S11(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,151.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,159.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S9.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E11_ptr = AperStop0_E11.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 78.045, 131.140, 176.444 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E11";
	std::string nameStartSys = "startSys_E11_fourLensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.639995);
	tarCarP.setTargetMag(-0.470143);

	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E12 four lens system
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E12(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 30.0;

	ApertureStopElement S0(/* semi height*/ 6.5, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK34_S1());
	SphericalElement S2(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLASF45_S1(), /*refractive index B*/mGlasses.getNLAK34_S1());
	SphericalElement S3(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,125.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF45_S1());

	SphericalElement S4(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF4_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,160.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF4_S1());

	SphericalElement S7(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,175.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S8(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,185.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S9(/*radius*/ 300.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,200.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S10(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,210.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S11(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,220.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,232.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S9.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E12_ptr = AperStop0_E12.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 114.477, 166.965, 214.059 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E12";
	std::string nameStartSys = "startSys_E12_fourLensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.134509);
	tarCarP.setTargetMag(-0.678143);

	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E13 four lens system
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E13(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 25.0;

	ApertureStopElement S0(/* semi height*/ 4.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK34_S1());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,77.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLASF45_S1(), /*refractive index B*/mGlasses.getNLAK34_S1());
	SphericalElement S3(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,82.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF45_S1());

	SphericalElement S4(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,87.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S5(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,92.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNBAF4_S1());
	SphericalElement S6(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,102.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF4_S1());

	SphericalElement S7(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,107.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,118.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S9(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,126.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S10(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,131.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S11(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,143.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,173.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S9.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E13_ptr = AperStop0_E13.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 111.414, 141.927, 178.930 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E13";
	std::string nameStartSys = "startSys_E13_fourLensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.03209);
	tarCarP.setTargetMag(-0.608397);

	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E14 four lens system
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E14(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 15.0;

	ApertureStopElement S0(/* semi height*/ 3.5, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK34_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,92.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNLAK34_S1(), /*refractive index B*/mGlasses.getNLASF45_S1());
	SphericalElement S3(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,99.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF45_S1());

	SphericalElement S4(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,104.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,114.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,121.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S7(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,126.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S8(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,133.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF4_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S9(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,138.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF4_S1());

	SphericalElement S10(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,143.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S11(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,158.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,183.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S9.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E14_ptr = AperStop0_E14.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 346.142, 329.129, 324.071 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E14";
	std::string nameStartSys = "startSys_E14_fourLensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.9544);
	tarCarP.setTargetMag(-0.419329);

	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E15 four lens system
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E15(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/ 1.5, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF6_S1());
	SphericalElement S3(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());

	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK7_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK7_S1());

	SphericalElement S7(/*radius*/ 300.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S8(/*radius*/ 300.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S9(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());
	SphericalElement S10(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getNSSK8_S1());
	SphericalElement S11(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());

	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,125.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E15_ptr = AperStop0_E15.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 237.770, 175.173, 159.384 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E15";
	std::string nameStartSys = "startSys_E15_fourLensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(5.812368);
	tarCarP.setTargetMag(-0.703037);

	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E16 four lens system
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E16(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 30.0;

	ApertureStopElement S0(/* semi height*/ 9.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S2(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,117.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK9_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S3(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,132.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK9_S1());

	SphericalElement S4(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,142.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLASF40_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S5(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNLASF40_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,161.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S7(/*radius*/ 180.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,171.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK9_S1());
	SphericalElement S8(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,188.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK9_S1());

	SphericalElement S9(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,198.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S10(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,212.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S11(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,218.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,240.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E16_ptr = AperStop0_E16.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 336.672, 447.752, 545.527 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E16";
	std::string nameStartSys = "startSys_E16_fourLensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(1.754755);
	tarCarP.setTargetMag(-0.523827);

	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E17 four lens system
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E17(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 15.0;

	ApertureStopElement S0(/* semi height*/ 4.5, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S2(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,99.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S3(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,104.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	SphericalElement S4(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,109.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK22_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 160.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,119.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK22_S1());

	SphericalElement S7(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,124.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S8(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,127.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S9(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,132.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S10(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,141.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNF2_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S11(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,146.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNF2_S1());

	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,156.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E17_ptr = AperStop0_E17.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 132.632, 180.460, 227.524 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E17";
	std::string nameStartSys = "startSys_E17_fourLensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.403635);
	tarCarP.setTargetMag(-0.530271);

	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E18 four lens system
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E18(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 25.0;

	ApertureStopElement S0(/* semi height*/ 8.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,112.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,117.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	SphericalElement S4(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,122.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF44_S1());
	SphericalElement S5(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNLASF44_S1());
	SphericalElement S6(/*radius*/ 300.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,138.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	SphericalElement S7(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,148.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,158.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S9(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,163.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S10(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,173.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK7_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S11(/*radius*/ 170.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,181.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK7_S1());

	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,203.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E18_ptr = AperStop0_E18.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 263.709, 314.759, 365.619 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E18";
	std::string nameStartSys = "startSys_E18_fourLensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(1.757274);
	tarCarP.setTargetMag(-0.476246);

	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E19 four lens system
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E19(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/ 2.5, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,106.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S5(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S6(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,124.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	SphericalElement S7(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,129.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S8(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,139.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S9(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,144.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S10(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,152.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S11(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,158.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,183.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E19_ptr = AperStop0_E19.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 87.215, 111.190, 142.235 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E19";
	std::string nameStartSys = "startSys_E19_fourLensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.853612);
	tarCarP.setTargetMag(-0.323338);

	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}

//// E20 four lens system
//bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E20(std::string example)
//{
//
//	std::vector<bool> workTheSystem;
//	real semiHeight = 14.0;
//
//	ApertureStopElement S0(/* semi height*/ 3.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
//
//	SphericalElement S1(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S2(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSK10_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S3(/*radius*/ 160.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSK10_S1());
//
//	SphericalElement S4(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S5(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAF3_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S6(/*radius*/ 180.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF3_S1());
//
//	SphericalElement S7(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSK10_S1());
//	SphericalElement S8(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSK10_S1());
//
//	SphericalElement S9(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,160.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getAir());
//	SphericalElement S10(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,170.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAF3_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
//	SphericalElement S11(/*radius*/ 190.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,180.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF3_S1());
//
//	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,205.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());
//
//	// **********************************
//	// set parameter variable
//	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//
//	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	// **********************************
//
//
//	//surfacePtr Aper0_E20_ptr = AperStop0_E20.clone();
//	surfacePtr S0_ptr = S0.clone();
//	surfacePtr S1_ptr = S1.clone();
//	surfacePtr S2_ptr = S2.clone();
//	surfacePtr S3_ptr = S3.clone();
//	surfacePtr S4_ptr = S4.clone();
//	surfacePtr S5_ptr = S5.clone();
//	surfacePtr S6_ptr = S6.clone();
//	surfacePtr S7_ptr = S7.clone();
//	surfacePtr S8_ptr = S8.clone();
//	surfacePtr S9_ptr = S9.clone();
//	surfacePtr S10_ptr = S10.clone();
//	surfacePtr S11_ptr = S11.clone();
//	surfacePtr S12_ptr = S12.clone();
//
//	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
//	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
//
//	// debug
//	oftenUse::print(optSystemElement, 550.0);
//
//	// check the start system
//	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
//	workTheSystem.push_back(checkRefIndexes);
//	std::vector<real> rms_Zemax{ 71.978, 122.485, 166.237 };
//	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
//	workTheSystem.push_back(testSystem);
//
//	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E20";
//	std::string nameStartSys = "startSys_E20_fourLensSystem";
//	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);
//
//	// set target cardinal points
//	targetCardinalPointsStruct tarCarP;
//	tarCarP.setTargetWFNO(5.217467);
//	tarCarP.setTargetMag(-0.630046);
//
//	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei(optSystemElement, tarCarP, location, example));
//
//	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
//	return checker;
//}
//// E21 four lens system
//bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E21(std::string example)
//{
//
//	std::vector<bool> workTheSystem;
//	real semiHeight = 22.0;
//
//	ApertureStopElement S0(/* semi height*/ 5.5, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
//
//	SphericalElement S1(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSK11_S1());
//	SphericalElement S2(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,92.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF2_S1(), /*refractive index B*/mGlasses.getNSK11_S1());
//	SphericalElement S3(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,98.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF2_S1());
//
//	SphericalElement S4(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,103.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSK11_S1());
//	SphericalElement S5(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,111.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNSK11_S1());
//	SphericalElement S6(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,117.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
//
//	SphericalElement S7(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,122.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());
//	SphericalElement S8(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,132.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());
//
//	SphericalElement S9(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,137.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
//	SphericalElement S10(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,145.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
//	SphericalElement S11(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,151.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
//
//	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,159.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());
//
//	// **********************************
//	// set parameter variable
//	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//
//	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	// **********************************
//
//
//	//surfacePtr Aper0_E21_ptr = AperStop0_E21.clone();
//	surfacePtr S0_ptr = S0.clone();
//	surfacePtr S1_ptr = S1.clone();
//	surfacePtr S2_ptr = S2.clone();
//	surfacePtr S3_ptr = S3.clone();
//	surfacePtr S4_ptr = S4.clone();
//	surfacePtr S5_ptr = S5.clone();
//	surfacePtr S6_ptr = S6.clone();
//	surfacePtr S7_ptr = S7.clone();
//	surfacePtr S8_ptr = S8.clone();
//	surfacePtr S9_ptr = S9.clone();
//	surfacePtr S10_ptr = S10.clone();
//	surfacePtr S11_ptr = S11.clone();
//	surfacePtr S12_ptr = S12.clone();
//
//	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
//	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
//
//	// debug
//	oftenUse::print(optSystemElement, 550.0);
//
//	// check the start system
//	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
//	workTheSystem.push_back(checkRefIndexes);
//	std::vector<real> rms_Zemax{ 148.139, 216.811, 282.069 };
//	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
//	workTheSystem.push_back(testSystem);
//
//	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E21";
//	std::string nameStartSys = "startSys_E21_fourLensSystem";
//	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);
//
//	// set target cardinal points
//	targetCardinalPointsStruct tarCarP;
//	tarCarP.setTargetWFNO(1.592392);
//	tarCarP.setTargetMag(-0.352845);
//
//	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei(optSystemElement, tarCarP, location, example));
//
//	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
//	return checker;
//}
//// E22 four lens system
//bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E22(std::string example)
//{
//
//	std::vector<bool> workTheSystem;
//	real semiHeight = 18.0;
//
//	ApertureStopElement S0(/* semi height*/ 5.5, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
//
//	SphericalElement S1(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S2(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,76.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S3(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
//
//	SphericalElement S4(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,88.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
//	SphericalElement S5(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,98.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
//	SphericalElement S6(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,104.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
//
//	SphericalElement S7(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,112.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getAir());
//	SphericalElement S8(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,116.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getAir());
//
//	SphericalElement S9(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,124.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S10(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,132.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S11(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,138.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
//
//	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,165.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());
//
//	// **********************************
//	// set parameter variable
//	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//
//	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	// **********************************
//
//
//	//surfacePtr Aper0_E22_ptr = AperStop0_E22.clone();
//	surfacePtr S0_ptr = S0.clone();
//	surfacePtr S1_ptr = S1.clone();
//	surfacePtr S2_ptr = S2.clone();
//	surfacePtr S3_ptr = S3.clone();
//	surfacePtr S4_ptr = S4.clone();
//	surfacePtr S5_ptr = S5.clone();
//	surfacePtr S6_ptr = S6.clone();
//	surfacePtr S7_ptr = S7.clone();
//	surfacePtr S8_ptr = S8.clone();
//	surfacePtr S9_ptr = S9.clone();
//	surfacePtr S10_ptr = S10.clone();
//	surfacePtr S11_ptr = S11.clone();
//	surfacePtr S12_ptr = S12.clone();
//
//	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
//	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
//
//	// debug
//	oftenUse::print(optSystemElement, 550.0);
//
//	// check the start system
//	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
//	workTheSystem.push_back(checkRefIndexes);
//	std::vector<real> rms_Zemax{ 158.143, 205.603, 262.265 };
//	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
//	workTheSystem.push_back(testSystem);
//
//	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E22";
//	std::string nameStartSys = "startSys_E22_fourLensSystem";
//	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);
//
//	// set target cardinal points
//	targetCardinalPointsStruct tarCarP;
//	tarCarP.setTargetWFNO(3.210215);
//	tarCarP.setTargetMag(-0.811010);
//
//	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei(optSystemElement, tarCarP, location, example));
//
//	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
//	return checker;
//}
//// E23 four lens system
//bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E23(std::string example)
//{
//
//	std::vector<bool> workTheSystem;
//	real semiHeight = 26.0;
//
//	ApertureStopElement S0(/* semi height*/ 6.5, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
//
//	SphericalElement S1(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S2(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S3(/*radius*/ 160.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
//
//	SphericalElement S4(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
//	SphericalElement S5(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
//	SphericalElement S6(/*radius*/ 180.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,155.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
//
//	SphericalElement S7(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,165.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
//	SphericalElement S8(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,180.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
//
//	SphericalElement S9(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,185.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S10(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,195.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S11(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,200.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
//
//	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,208.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());
//
//	// **********************************
//	// set parameter variable
//	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//
//	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	// **********************************
//
//
//	//surfacePtr Aper0_E23_ptr = AperStop0_E23.clone();
//	surfacePtr S0_ptr = S0.clone();
//	surfacePtr S1_ptr = S1.clone();
//	surfacePtr S2_ptr = S2.clone();
//	surfacePtr S3_ptr = S3.clone();
//	surfacePtr S4_ptr = S4.clone();
//	surfacePtr S5_ptr = S5.clone();
//	surfacePtr S6_ptr = S6.clone();
//	surfacePtr S7_ptr = S7.clone();
//	surfacePtr S8_ptr = S8.clone();
//	surfacePtr S9_ptr = S9.clone();
//	surfacePtr S10_ptr = S10.clone();
//	surfacePtr S11_ptr = S11.clone();
//	surfacePtr S12_ptr = S12.clone();
//
//	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
//	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
//
//	// debug
//	oftenUse::print(optSystemElement, 550.0);
//
//	// check the start system
//	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
//	workTheSystem.push_back(checkRefIndexes);
//	std::vector<real> rms_Zemax{ 225.991, 301.914, 377.892 };
//	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
//	workTheSystem.push_back(testSystem);
//
//	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E23";
//	std::string nameStartSys = "startSys_E23_fourLensSystem";
//	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);
//
//	// set target cardinal points
//	targetCardinalPointsStruct tarCarP;
//	tarCarP.setTargetWFNO(1.463596);
//	tarCarP.setTargetMag(-0.276761);
//
//	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei(optSystemElement, tarCarP, location, example));
//
//	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
//	return checker;
//}
//// E24 four lens system
//bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E24(std::string example)
//{
//
//	std::vector<bool> workTheSystem;
//	real semiHeight = 16.0;
//
//	ApertureStopElement S0(/* semi height*/ 3.0, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
//
//	SphericalElement S1(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF45_S1());
//	SphericalElement S2(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSSK5_S1(), /*refractive index B*/mGlasses.getNLASF45_S1());
//	SphericalElement S3(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,155.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK5_S1());
//
//	SphericalElement S4(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,160.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLASF40_S1(), /*refractive index B*/mGlasses.getAir());
//	SphericalElement S5(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,165.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNLASF40_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
//	SphericalElement S6(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,175.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
//
//	SphericalElement S7(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,180.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S8(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,190.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
//
//	SphericalElement S9(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,195.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF45_S1());
//	SphericalElement S10(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,205.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNLASF45_S1());
//	SphericalElement S11(/*radius*/ 110.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,210.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
//
//	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,240.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());
//
//	// **********************************
//	// set parameter variable
//	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//
//	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	// **********************************
//
//
//	//surfacePtr Aper0_E24_ptr = AperStop0_E24.clone();
//	surfacePtr S0_ptr = S0.clone();
//	surfacePtr S1_ptr = S1.clone();
//	surfacePtr S2_ptr = S2.clone();
//	surfacePtr S3_ptr = S3.clone();
//	surfacePtr S4_ptr = S4.clone();
//	surfacePtr S5_ptr = S5.clone();
//	surfacePtr S6_ptr = S6.clone();
//	surfacePtr S7_ptr = S7.clone();
//	surfacePtr S8_ptr = S8.clone();
//	surfacePtr S9_ptr = S9.clone();
//	surfacePtr S10_ptr = S10.clone();
//	surfacePtr S11_ptr = S11.clone();
//	surfacePtr S12_ptr = S12.clone();
//
//	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
//	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
//
//	// debug
//	oftenUse::print(optSystemElement, 550.0);
//
//	// check the start system
//	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
//	workTheSystem.push_back(checkRefIndexes);
//	std::vector<real> rms_Zemax{ 71.520, 91.633, 113.787 };
//	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
//	workTheSystem.push_back(testSystem);
//
//	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E24";
//	std::string nameStartSys = "startSys_E24_fourLensSystem";
//	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);
//
//	// set target cardinal points
//	targetCardinalPointsStruct tarCarP;
//	tarCarP.setTargetWFNO(3.597048);
//	tarCarP.setTargetMag(-0.270614);
//
//	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei(optSystemElement, tarCarP, location, example));
//
//	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
//	return checker;
//}
//// E25 four lens system
//bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E25(std::string example)
//{
//
//	std::vector<bool> workTheSystem;
//	real semiHeight = 30.0;
//
//	ApertureStopElement S0(/* semi height*/ 6.5, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
//
//	SphericalElement S1(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S2(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLASF44_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S3(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,145.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF44_S1());
//
//	SphericalElement S4(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,155.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S5(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,175.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF56_S1(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S6(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,185.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());
//
//	SphericalElement S7(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,195.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getAir());
//	SphericalElement S8(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,200.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getAir());
//
//	SphericalElement S9(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,210.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S10(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,235.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLASF45_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S11(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,245.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF45_S1());
//
//	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,273.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());
//
//	// **********************************
//	// set parameter variable
//	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//
//	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	// **********************************
//
//
//	//surfacePtr Aper0_E25_ptr = AperStop0_E25.clone();
//	surfacePtr S0_ptr = S0.clone();
//	surfacePtr S1_ptr = S1.clone();
//	surfacePtr S2_ptr = S2.clone();
//	surfacePtr S3_ptr = S3.clone();
//	surfacePtr S4_ptr = S4.clone();
//	surfacePtr S5_ptr = S5.clone();
//	surfacePtr S6_ptr = S6.clone();
//	surfacePtr S7_ptr = S7.clone();
//	surfacePtr S8_ptr = S8.clone();
//	surfacePtr S9_ptr = S9.clone();
//	surfacePtr S10_ptr = S10.clone();
//	surfacePtr S11_ptr = S11.clone();
//	surfacePtr S12_ptr = S12.clone();
//
//	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
//	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
//
//	// debug
//	oftenUse::print(optSystemElement, 550.0);
//
//	// check the start system
//	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
//	workTheSystem.push_back(checkRefIndexes);
//	std::vector<real> rms_Zemax{ 73.212, 162.610, 229.065 };
//	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
//	workTheSystem.push_back(testSystem);
//
//	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E25";
//	std::string nameStartSys = "startSys_E25_fourLensSystem";
//	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);
//
//	// set target cardinal points
//	targetCardinalPointsStruct tarCarP;
//	tarCarP.setTargetWFNO(2.716373);
//	tarCarP.setTargetMag(-0.511844);
//
//	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei(optSystemElement, tarCarP, location, example));
//
//	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
//	return checker;
//}
//// E26 four lens system
//bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E26(std::string example)
//{
//
//	std::vector<bool> workTheSystem;
//	real semiHeight = 28.0;
//
//	ApertureStopElement S0(/* semi height*/ 6.0, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
//
//	SphericalElement S1(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF4_S1());
//	SphericalElement S2(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK10_S1(), /*refractive index B*/mGlasses.getNSF4_S1());
//	SphericalElement S3(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,146.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
//
//	SphericalElement S4(/*radius*/ 110.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,151.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
//	SphericalElement S5(/*radius*/ 110.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,161.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
//	SphericalElement S6(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,167.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
//
//	SphericalElement S7(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,172.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF9_S1());
//	SphericalElement S8(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,180.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF9_S1());
//
//	SphericalElement S9(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,185.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());
//	SphericalElement S10(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,197.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLASF41_S1(), /*refractive index B*/mGlasses.getNSF56_S1());
//	SphericalElement S11(/*radius*/ 110.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,203.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF41_S1());
//
//	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,211.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());
//
//	// **********************************
//	// set parameter variable
//	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//
//	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	// **********************************
//
//
//	//surfacePtr Aper0_E26_ptr = AperStop0_E26.clone();
//	surfacePtr S0_ptr = S0.clone();
//	surfacePtr S1_ptr = S1.clone();
//	surfacePtr S2_ptr = S2.clone();
//	surfacePtr S3_ptr = S3.clone();
//	surfacePtr S4_ptr = S4.clone();
//	surfacePtr S5_ptr = S5.clone();
//	surfacePtr S6_ptr = S6.clone();
//	surfacePtr S7_ptr = S7.clone();
//	surfacePtr S8_ptr = S8.clone();
//	surfacePtr S9_ptr = S9.clone();
//	surfacePtr S10_ptr = S10.clone();
//	surfacePtr S11_ptr = S11.clone();
//	surfacePtr S12_ptr = S12.clone();
//
//	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
//	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
//
//	// debug
//	oftenUse::print(optSystemElement, 550.0);
//
//	// check the start system
//	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
//	workTheSystem.push_back(checkRefIndexes);
//	std::vector<real> rms_Zemax{ 172.163, 236.361, 294.564 };
//	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
//	workTheSystem.push_back(testSystem);
//
//	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E26";
//	std::string nameStartSys = "startSys_E26_fourLensSystem";
//	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);
//
//	// set target cardinal points
//	targetCardinalPointsStruct tarCarP;
//	tarCarP.setTargetWFNO(1.543880);
//	tarCarP.setTargetMag(-0.264757);
//
//	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei(optSystemElement, tarCarP, location, example));
//
//	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
//	return checker;
//}
//// E27 four lens system
//bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E27(std::string example)
//{
//
//	std::vector<bool> workTheSystem;
//	real semiHeight = 10.0;
//
//	ApertureStopElement S0(/* semi height*/ 2.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
//
//	SphericalElement S1(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S2(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S3(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
//
//	SphericalElement S4(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
//	SphericalElement S5(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
//	
//	SphericalElement S6(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S7(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK7_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S8(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,160.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK7_S1());
//
//	SphericalElement S9(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,170.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
//	SphericalElement S10(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,180.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
//	SphericalElement S11(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,190.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
//
//	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,200.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());
//
//	// **********************************
//	// set parameter variable
//	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//
//	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	// **********************************
//
//
//	//surfacePtr Aper0_E27_ptr = AperStop0_E27.clone();
//	surfacePtr S0_ptr = S0.clone();
//	surfacePtr S1_ptr = S1.clone();
//	surfacePtr S2_ptr = S2.clone();
//	surfacePtr S3_ptr = S3.clone();
//	surfacePtr S4_ptr = S4.clone();
//	surfacePtr S5_ptr = S5.clone();
//	surfacePtr S6_ptr = S6.clone();
//	surfacePtr S7_ptr = S7.clone();
//	surfacePtr S8_ptr = S8.clone();
//	surfacePtr S9_ptr = S9.clone();
//	surfacePtr S10_ptr = S10.clone();
//	surfacePtr S11_ptr = S11.clone();
//	surfacePtr S12_ptr = S12.clone();
//
//	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
//	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
//
//	// debug
//	oftenUse::print(optSystemElement, 550.0);
//
//	// check the start system
//	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
//	workTheSystem.push_back(checkRefIndexes);
//	std::vector<real> rms_Zemax{ 126.712, 138.387, 149.493 };
//	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
//	workTheSystem.push_back(testSystem);
//
//	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E27";
//	std::string nameStartSys = "startSys_E27_fourLensSystem";
//	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);
//
//	// set target cardinal points
//	targetCardinalPointsStruct tarCarP;
//	tarCarP.setTargetWFNO(6.496067);
//	tarCarP.setTargetMag(-0.432866);
//
//	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei(optSystemElement, tarCarP, location, example));
//
//	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
//	return checker;
//}
//// E28 four lens system
//bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E28(std::string example)
//{
//
//	std::vector<bool> workTheSystem;
//	real semiHeight = 15.0;
//
//	ApertureStopElement S0(/* semi height*/ 2.5, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
//
//	SphericalElement S1(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());
//	SphericalElement S2(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,86.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAK4_S1(), /*refractive index B*/mGlasses.getNSF56_S1());
//	SphericalElement S3(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK4_S1());
//
//	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNF2_S1());
//	SphericalElement S5(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,101.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNF2_S1());
//
//	SphericalElement S6(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,106.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());
//	SphericalElement S7(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,112.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBASF2_S1(), /*refractive index B*/mGlasses.getNSF56_S1());
//	SphericalElement S8(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,116.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBASF2_S1());
//
//	SphericalElement S9(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,121.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNF2_S1());
//	SphericalElement S10(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,127.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAK4_S1(), /*refractive index B*/mGlasses.getNF2_S1());
//	SphericalElement S11(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,131.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK4_S1());
//
//	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,146.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());
//
//	// **********************************
//	// set parameter variable
//	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//
//	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	// **********************************
//
//
//	//surfacePtr Aper0_E28_ptr = AperStop0_E28.clone();
//	surfacePtr S0_ptr = S0.clone();
//	surfacePtr S1_ptr = S1.clone();
//	surfacePtr S2_ptr = S2.clone();
//	surfacePtr S3_ptr = S3.clone();
//	surfacePtr S4_ptr = S4.clone();
//	surfacePtr S5_ptr = S5.clone();
//	surfacePtr S6_ptr = S6.clone();
//	surfacePtr S7_ptr = S7.clone();
//	surfacePtr S8_ptr = S8.clone();
//	surfacePtr S9_ptr = S9.clone();
//	surfacePtr S10_ptr = S10.clone();
//	surfacePtr S11_ptr = S11.clone();
//	surfacePtr S12_ptr = S12.clone();
//
//	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
//	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
//
//	// debug
//	oftenUse::print(optSystemElement, 550.0);
//
//	// check the start system
//	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
//	workTheSystem.push_back(checkRefIndexes);
//	std::vector<real> rms_Zemax{ 65.566, 81.503, 98.138 };
//	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
//	workTheSystem.push_back(testSystem);
//
//	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E28";
//	std::string nameStartSys = "startSys_E28_fourLensSystem";
//	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);
//
//	// set target cardinal points
//	targetCardinalPointsStruct tarCarP;
//	tarCarP.setTargetWFNO(3.708907);
//	tarCarP.setTargetMag(-0.371547);
//
//	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei(optSystemElement, tarCarP, location, example));
//
//	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
//	return checker;
//}
//// E29 four lens system
//bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E29(std::string example)
//{
//
//	std::vector<bool> workTheSystem;
//	real semiHeight = 22.0;
//
//	ApertureStopElement S0(/* semi height*/ 5.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
//
//	SphericalElement S1(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S2(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S3(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,125.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
//
//	SphericalElement S4(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0,-1.0 }, /*refractive index A*/ mGlasses.getNSF56_S1(), /*refractive index B*/mGlasses.getAir());
//	SphericalElement S5(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF56_S1(), /*refractive index B*/mGlasses.getAir());
//
//	SphericalElement S6(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S7(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,155.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAK4_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S8(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,165.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK4_S1());
//
//	SphericalElement S9(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,175.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S10(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,190.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S11(/*radius*/ 110.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,200.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
//
//	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,228.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());
//
//	// **********************************
//	// set parameter variable
//	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//
//	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	// **********************************
//
//
//	//surfacePtr Aper0_E29_ptr = AperStop0_E29.clone();
//	surfacePtr S0_ptr = S0.clone();
//	surfacePtr S1_ptr = S1.clone();
//	surfacePtr S2_ptr = S2.clone();
//	surfacePtr S3_ptr = S3.clone();
//	surfacePtr S4_ptr = S4.clone();
//	surfacePtr S5_ptr = S5.clone();
//	surfacePtr S6_ptr = S6.clone();
//	surfacePtr S7_ptr = S7.clone();
//	surfacePtr S8_ptr = S8.clone();
//	surfacePtr S9_ptr = S9.clone();
//	surfacePtr S10_ptr = S10.clone();
//	surfacePtr S11_ptr = S11.clone();
//	surfacePtr S12_ptr = S12.clone();
//
//	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
//	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
//
//	// debug
//	oftenUse::print(optSystemElement, 550.0);
//
//	// check the start system
//	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
//	workTheSystem.push_back(checkRefIndexes);
//	std::vector<real> rms_Zemax{ 116.051, 172.588, 233.248 };
//	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
//	workTheSystem.push_back(testSystem);
//
//	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E29";
//	std::string nameStartSys = "startSys_E29_fourLensSystem";
//	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);
//
//	// set target cardinal points
//	targetCardinalPointsStruct tarCarP;
//	tarCarP.setTargetWFNO(3.342098);
//	tarCarP.setTargetMag(-0.567934);
//
//	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei(optSystemElement, tarCarP, location, example));
//
//	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
//	return checker;
//}
//// E30 four lens system
//bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E30(std::string example)
//{
//
//	std::vector<bool> workTheSystem;
//	real semiHeight = 18.0;
//
//	ApertureStopElement S0(/* semi height*/ 5.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
//
//	SphericalElement S1(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBASF64_S1());
//	SphericalElement S2(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK10_S1(), /*refractive index B*/mGlasses.getNBASF64_S1());
//	SphericalElement S3(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
//
//	SphericalElement S4(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());
//	SphericalElement S5(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());
//
//	SphericalElement S6(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF52_S1(), /*refractive index B*/mGlasses.getAir());
//	SphericalElement S7(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBAF52_S1(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S8(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,160.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
//
//	SphericalElement S9(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,170.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());
//	SphericalElement S10(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,180.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNF2_S1(), /*refractive index B*/mGlasses.getNSSK8_S1());
//	SphericalElement S11(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,190.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNF2_S1());
//
//	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,200.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());
//
//	// **********************************
//	// set parameter variable
//	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//
//	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	// **********************************
//
//
//	//surfacePtr Aper0_E30_ptr = AperStop0_E30.clone();
//	surfacePtr S0_ptr = S0.clone();
//	surfacePtr S1_ptr = S1.clone();
//	surfacePtr S2_ptr = S2.clone();
//	surfacePtr S3_ptr = S3.clone();
//	surfacePtr S4_ptr = S4.clone();
//	surfacePtr S5_ptr = S5.clone();
//	surfacePtr S6_ptr = S6.clone();
//	surfacePtr S7_ptr = S7.clone();
//	surfacePtr S8_ptr = S8.clone();
//	surfacePtr S9_ptr = S9.clone();
//	surfacePtr S10_ptr = S10.clone();
//	surfacePtr S11_ptr = S11.clone();
//	surfacePtr S12_ptr = S12.clone();
//
//	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
//	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
//
//	// debug
//	oftenUse::print(optSystemElement, 550.0);
//
//	// check the start system
//	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
//	workTheSystem.push_back(checkRefIndexes);
//	std::vector<real> rms_Zemax{ 114.246, 130.834, 150.802 };
//	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
//	workTheSystem.push_back(testSystem);
//
//	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E30";
//	std::string nameStartSys = "startSys_E30_fourLensSystem";
//	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);
//
//	// set target cardinal points
//	targetCardinalPointsStruct tarCarP;
//	tarCarP.setTargetWFNO(3.300116);
//	tarCarP.setTargetMag(-0.600477);
//
//	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei(optSystemElement, tarCarP, location, example));
//
//	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
//	return checker;
//}
//// E31 four lens system
//bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E31(std::string example)
//{
//
//	std::vector<bool> workTheSystem;
//	real semiHeight = 26.0;
//
//	ApertureStopElement S0(/* semi height*/ 6.5, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
//
//	SphericalElement S1(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK33A_S1());
//	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNLAK33A_S1());
//	SphericalElement S3(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,125.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
//
//	SphericalElement S4(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
//	SphericalElement S5(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
//
//	SphericalElement S6(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,145.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAF2_S1(), /*refractive index B*/mGlasses.getAir());
//	SphericalElement S7(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNLAF2_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S8(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,160.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
//
//	SphericalElement S9(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,165.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK33A_S1());
//	SphericalElement S10(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,180.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getNLAK33A_S1());
//	SphericalElement S11(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,185.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
//
//	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,197.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());
//
//	// **********************************
//	// set parameter variable
//	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//
//	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	// **********************************
//
//
//	//surfacePtr Aper0_E31_ptr = AperStop0_E31.clone();
//	surfacePtr S0_ptr = S0.clone();
//	surfacePtr S1_ptr = S1.clone();
//	surfacePtr S2_ptr = S2.clone();
//	surfacePtr S3_ptr = S3.clone();
//	surfacePtr S4_ptr = S4.clone();
//	surfacePtr S5_ptr = S5.clone();
//	surfacePtr S6_ptr = S6.clone();
//	surfacePtr S7_ptr = S7.clone();
//	surfacePtr S8_ptr = S8.clone();
//	surfacePtr S9_ptr = S9.clone();
//	surfacePtr S10_ptr = S10.clone();
//	surfacePtr S11_ptr = S11.clone();
//	surfacePtr S12_ptr = S12.clone();
//
//	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
//	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
//
//	// debug
//	oftenUse::print(optSystemElement, 550.0);
//
//	// check the start system
//	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
//	workTheSystem.push_back(checkRefIndexes);
//	std::vector<real> rms_Zemax{ 152.167, 206.562, 256.364 };
//	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
//	workTheSystem.push_back(testSystem);
//
//	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E31";
//	std::string nameStartSys = "startSys_E31_fourLensSystem";
//	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);
//
//	// set target cardinal points
//	targetCardinalPointsStruct tarCarP;
//	tarCarP.setTargetWFNO(1.851451);
//	tarCarP.setTargetMag(-0.402875);
//
//	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei(optSystemElement, tarCarP, location, example));
//
//	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
//	return checker;
//}
//// E32 four lens system
//bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E32(std::string example)
//{
//
//	std::vector<bool> workTheSystem;
//	real semiHeight = 16.0;
//
//	ApertureStopElement S0(/* semi height*/ 3.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
//
//	SphericalElement S1(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S2(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S3(/*radius*/ 180.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
//
//	SphericalElement S4(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
//	SphericalElement S5(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAK4_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
//	SphericalElement S6(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,125.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK4_S1());
//	
//	SphericalElement S7(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
//	SphericalElement S8(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNLAF2_S1());
//	SphericalElement S9(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,145.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());
//	
//	SphericalElement S10(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
//	SphericalElement S11(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,160.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
//
//	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,182.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());
//
//	// **********************************
//	// set parameter variable
//	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//
//	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S9.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	// **********************************
//
//
//	//surfacePtr Aper0_E32_ptr = AperStop0_E32.clone();
//	surfacePtr S0_ptr = S0.clone();
//	surfacePtr S1_ptr = S1.clone();
//	surfacePtr S2_ptr = S2.clone();
//	surfacePtr S3_ptr = S3.clone();
//	surfacePtr S4_ptr = S4.clone();
//	surfacePtr S5_ptr = S5.clone();
//	surfacePtr S6_ptr = S6.clone();
//	surfacePtr S7_ptr = S7.clone();
//	surfacePtr S8_ptr = S8.clone();
//	surfacePtr S9_ptr = S9.clone();
//	surfacePtr S10_ptr = S10.clone();
//	surfacePtr S11_ptr = S11.clone();
//	surfacePtr S12_ptr = S12.clone();
//
//	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
//	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
//
//	// debug
//	oftenUse::print(optSystemElement, 550.0);
//
//	// check the start system
//	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
//	workTheSystem.push_back(checkRefIndexes);
//	std::vector<real> rms_Zemax{ 85.328, 124.088, 157.897 };
//	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
//	workTheSystem.push_back(testSystem);
//
//	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E32";
//	std::string nameStartSys = "startSys_E32_fourLensSystem";
//	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);
//
//	// set target cardinal points
//	targetCardinalPointsStruct tarCarP;
//	tarCarP.setTargetWFNO(3.700579);
//	tarCarP.setTargetMag(-0.405210);
//
//	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei(optSystemElement, tarCarP, location, example));
//
//	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
//	return checker;
//}
//// E33 four lens system
//bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E33(std::string example)
//{
//
//	std::vector<bool> workTheSystem;
//	real semiHeight = 10.0;
//
//	ApertureStopElement S0(/* semi height*/ 2.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
//
//	SphericalElement S1(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
//	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK7_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
//	SphericalElement S3(/*radius*/ 160.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK7_S1());
//
//	SphericalElement S4(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getAir());
//	SphericalElement S5(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNBAK4_S1());
//	SphericalElement S6(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,125.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK4_S1());
//
//	SphericalElement S7(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
//	SphericalElement S8(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK7_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
//	SphericalElement S9(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK7_S1());
//
//	SphericalElement S10(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,145.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());
//	SphericalElement S11(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());
//
//	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,180.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());
//
//	// **********************************
//	// set parameter variable
//	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//
//	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S9.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	// **********************************
//
//
//	//surfacePtr Aper0_E33_ptr = AperStop0_E33.clone();
//	surfacePtr S0_ptr = S0.clone();
//	surfacePtr S1_ptr = S1.clone();
//	surfacePtr S2_ptr = S2.clone();
//	surfacePtr S3_ptr = S3.clone();
//	surfacePtr S4_ptr = S4.clone();
//	surfacePtr S5_ptr = S5.clone();
//	surfacePtr S6_ptr = S6.clone();
//	surfacePtr S7_ptr = S7.clone();
//	surfacePtr S8_ptr = S8.clone();
//	surfacePtr S9_ptr = S9.clone();
//	surfacePtr S10_ptr = S10.clone();
//	surfacePtr S11_ptr = S11.clone();
//	surfacePtr S12_ptr = S12.clone();
//
//	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
//	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
//
//	// debug
//	oftenUse::print(optSystemElement, 550.0);
//
//	// check the start system
//	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
//	workTheSystem.push_back(checkRefIndexes);
//	std::vector<real> rms_Zemax{ 118.321, 115.738, 115.360 };
//	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
//	workTheSystem.push_back(testSystem);
//
//	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E33";
//	std::string nameStartSys = "startSys_E33_fourLensSystem";
//	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);
//
//	// set target cardinal points
//	targetCardinalPointsStruct tarCarP;
//	tarCarP.setTargetWFNO(5.708910);
//	tarCarP.setTargetMag(-0.381415);
//
//	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei(optSystemElement, tarCarP, location, example));
//
//	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
//	return checker;
//}
//// E34 four lens system
//bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E34(std::string example)
//{
//
//	std::vector<bool> workTheSystem;
//	real semiHeight = 20.0;
//
//	ApertureStopElement S0(/* semi height*/ 4.5, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
//
//	SphericalElement S1(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK10_S1(), /*refractive index B*/mGlasses.getAir());
//	SphericalElement S2(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNLAK10_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
//	SphericalElement S3(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
//
//	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK14_S1());
//	SphericalElement S5(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getNLAK14_S1());
//	SphericalElement S6(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,155.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
//
//	SphericalElement S7(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,165.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S8(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,175.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S9(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,180.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
//
//	SphericalElement S10(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,190.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
//	SphericalElement S11(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,200.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
//
//	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,219.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());
//
//	// **********************************
//	// set parameter variable
//	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//
//	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S9.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	// **********************************
//
//
//	//surfacePtr Aper0_E34_ptr = AperStop0_E34.clone();
//	surfacePtr S0_ptr = S0.clone();
//	surfacePtr S1_ptr = S1.clone();
//	surfacePtr S2_ptr = S2.clone();
//	surfacePtr S3_ptr = S3.clone();
//	surfacePtr S4_ptr = S4.clone();
//	surfacePtr S5_ptr = S5.clone();
//	surfacePtr S6_ptr = S6.clone();
//	surfacePtr S7_ptr = S7.clone();
//	surfacePtr S8_ptr = S8.clone();
//	surfacePtr S9_ptr = S9.clone();
//	surfacePtr S10_ptr = S10.clone();
//	surfacePtr S11_ptr = S11.clone();
//	surfacePtr S12_ptr = S12.clone();
//
//	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
//	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
//
//	// debug
//	oftenUse::print(optSystemElement, 550.0);
//
//	// check the start system
//	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
//	workTheSystem.push_back(checkRefIndexes);
//	std::vector<real> rms_Zemax{ 147.029, 244.894, 325.823 };
//	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
//	workTheSystem.push_back(testSystem);
//
//	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E34";
//	std::string nameStartSys = "startSys_E34_fourLensSystem";
//	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);
//
//	// set target cardinal points
//	targetCardinalPointsStruct tarCarP;
//	tarCarP.setTargetWFNO(2.047004);
//	tarCarP.setTargetMag(-0.264762);
//
//	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei(optSystemElement, tarCarP, location, example));
//
//	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
//	return checker;
//}
//// E35 four lens system
//bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E35(std::string example)
//{
//
//	std::vector<bool> workTheSystem;
//	real semiHeight = 25.0;
//
//	ApertureStopElement S0(/* semi height*/ 6.5, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
//
//	SphericalElement S1(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF44_S1());
//	SphericalElement S2(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,132.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNLASF44_S1());
//	SphericalElement S3(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,136.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
//
//	SphericalElement S4(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,141.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S5(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,149.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S6(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,153.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
//
//	SphericalElement S7(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,158.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF44_S1());
//	SphericalElement S8(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,166.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getNLASF44_S1());
//	SphericalElement S9(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,170.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
//
//	SphericalElement S10(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,175.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S11(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,185.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
//
//	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,191.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());
//
//	// **********************************
//	// set parameter variable
//	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//
//	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S9.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	// **********************************
//
//
//	//surfacePtr Aper0_E35_ptr = AperStop0_E35.clone();
//	surfacePtr S0_ptr = S0.clone();
//	surfacePtr S1_ptr = S1.clone();
//	surfacePtr S2_ptr = S2.clone();
//	surfacePtr S3_ptr = S3.clone();
//	surfacePtr S4_ptr = S4.clone();
//	surfacePtr S5_ptr = S5.clone();
//	surfacePtr S6_ptr = S6.clone();
//	surfacePtr S7_ptr = S7.clone();
//	surfacePtr S8_ptr = S8.clone();
//	surfacePtr S9_ptr = S9.clone();
//	surfacePtr S10_ptr = S10.clone();
//	surfacePtr S11_ptr = S11.clone();
//	surfacePtr S12_ptr = S12.clone();
//
//	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
//	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
//
//	// debug
//	oftenUse::print(optSystemElement, 550.0);
//
//	// check the start system
//	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
//	workTheSystem.push_back(checkRefIndexes);
//	std::vector<real> rms_Zemax{ 175.674, 229.489, 281.351 };
//	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
//	workTheSystem.push_back(testSystem);
//
//	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E35";
//	std::string nameStartSys = "startSys_E35_fourLensSystem";
//	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);
//
//	// set target cardinal points
//	targetCardinalPointsStruct tarCarP;
//	tarCarP.setTargetWFNO(1.465094);
//	tarCarP.setTargetMag(-0.273780);
//
//	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei(optSystemElement, tarCarP, location, example));
//
//	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
//	return checker;
//}
//// E36 four lens system
//bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E36(std::string example)
//{
//
//	std::vector<bool> workTheSystem;
//	real semiHeight = 22.0;
//
//	ApertureStopElement S0(/* semi height*/ 5.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
//
//	SphericalElement S1(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getAir());
//	SphericalElement S2(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,106.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNSSK8_S1());
//	SphericalElement S3(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,112.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());
//
//	SphericalElement S4(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,122.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S5(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,132.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSSK8_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S6(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,138.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());
//
//	SphericalElement S7(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,148.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
//	SphericalElement S8(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,156.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
//	
//	SphericalElement S9(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,166.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
//	SphericalElement S10(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,172.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
//	SphericalElement S11(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,180.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
//
//	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,210.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());
//
//	// **********************************
//	// set parameter variable
//	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//
//	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	// **********************************
//
//
//	//surfacePtr Aper0_E36_ptr = AperStop0_E36.clone();
//	surfacePtr S0_ptr = S0.clone();
//	surfacePtr S1_ptr = S1.clone();
//	surfacePtr S2_ptr = S2.clone();
//	surfacePtr S3_ptr = S3.clone();
//	surfacePtr S4_ptr = S4.clone();
//	surfacePtr S5_ptr = S5.clone();
//	surfacePtr S6_ptr = S6.clone();
//	surfacePtr S7_ptr = S7.clone();
//	surfacePtr S8_ptr = S8.clone();
//	surfacePtr S9_ptr = S9.clone();
//	surfacePtr S10_ptr = S10.clone();
//	surfacePtr S11_ptr = S11.clone();
//	surfacePtr S12_ptr = S12.clone();
//
//	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
//	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
//
//	// debug
//	oftenUse::print(optSystemElement, 550.0);
//
//	// check the start system
//	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
//	workTheSystem.push_back(checkRefIndexes);
//	std::vector<real> rms_Zemax{ 129.956, 254.220, 354.284 };
//	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
//	workTheSystem.push_back(testSystem);
//
//	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E36";
//	std::string nameStartSys = "startSys_E36_fourLensSystem";
//	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);
//
//	// set target cardinal points
//	targetCardinalPointsStruct tarCarP;
//	tarCarP.setTargetWFNO(2.460622);
//	tarCarP.setTargetMag(-0.418222);
//
//	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei(optSystemElement, tarCarP, location, example));
//
//	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
//	return checker;
//}
//// E37 four lens system
//bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E37(std::string example)
//{
//
//	std::vector<bool> workTheSystem;
//	real semiHeight = 14.0;
//
//	ApertureStopElement S0(/* semi height*/ 3.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
//
//	SphericalElement S1(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK22_S1());
//	SphericalElement S2(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNLAK22_S1());
//	SphericalElement S3(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
//
//	SphericalElement S4(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S5(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,125.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK34_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
//	SphericalElement S6(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK34_S1());
//
//	SphericalElement S7(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,145.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
//	SphericalElement S8(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,155.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
//
//	SphericalElement S9(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,165.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK22_S1());
//	SphericalElement S10(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,175.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF2_S1(), /*refractive index B*/mGlasses.getNLAK22_S1());
//	SphericalElement S11(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,185.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF2_S1());
//
//	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,196.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());
//
//	// **********************************
//	// set parameter variable
//	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//
//	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	// **********************************
//
//
//	//surfacePtr Aper0_E37_ptr = AperStop0_E37.clone();
//	surfacePtr S0_ptr = S0.clone();
//	surfacePtr S1_ptr = S1.clone();
//	surfacePtr S2_ptr = S2.clone();
//	surfacePtr S3_ptr = S3.clone();
//	surfacePtr S4_ptr = S4.clone();
//	surfacePtr S5_ptr = S5.clone();
//	surfacePtr S6_ptr = S6.clone();
//	surfacePtr S7_ptr = S7.clone();
//	surfacePtr S8_ptr = S8.clone();
//	surfacePtr S9_ptr = S9.clone();
//	surfacePtr S10_ptr = S10.clone();
//	surfacePtr S11_ptr = S11.clone();
//	surfacePtr S12_ptr = S12.clone();
//
//	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
//	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
//
//	// debug
//	oftenUse::print(optSystemElement, 550.0);
//
//	// check the start system
//	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
//	workTheSystem.push_back(checkRefIndexes);
//	std::vector<real> rms_Zemax{ 60.420, 109.614, 158.211 };
//	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
//	workTheSystem.push_back(testSystem);
//
//	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E37";
//	std::string nameStartSys = "startSys_E37_fourLensSystem";
//	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);
//
//	// set target cardinal points
//	targetCardinalPointsStruct tarCarP;
//	tarCarP.setTargetWFNO(3.059847);
//	tarCarP.setTargetMag(-0.368060);
//
//	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei(optSystemElement, tarCarP, location, example));
//
//	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
//	return checker;
//}
//// E38 four lens system
//bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E38(std::string example)
//{
//
//	std::vector<bool> workTheSystem;
//	real semiHeight = 28.0;
//
//	ApertureStopElement S0(/* semi height*/ 6.5, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
//
//	SphericalElement S1(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF3_S1());
//	SphericalElement S2(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,132.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNLAF3_S1());
//	SphericalElement S3(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
//
//	SphericalElement S4(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,148.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF3_S1(), /*refractive index B*/mGlasses.getAir());
//	SphericalElement S5(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,154.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBAF3_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
//	SphericalElement S6(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,162.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
//
//	SphericalElement S7(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,170.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF3_S1());
//	SphericalElement S8(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,184.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF3_S1());
//
//	SphericalElement S9(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,192.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF3_S1());
//	SphericalElement S10(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,204.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNBAF3_S1());
//	SphericalElement S11(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,210.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
//
//	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,217.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());
//
//	// **********************************
//	// set parameter variable
//	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//
//	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	// **********************************
//
//
//	//surfacePtr Aper0_E38_ptr = AperStop0_E38.clone();
//	surfacePtr S0_ptr = S0.clone();
//	surfacePtr S1_ptr = S1.clone();
//	surfacePtr S2_ptr = S2.clone();
//	surfacePtr S3_ptr = S3.clone();
//	surfacePtr S4_ptr = S4.clone();
//	surfacePtr S5_ptr = S5.clone();
//	surfacePtr S6_ptr = S6.clone();
//	surfacePtr S7_ptr = S7.clone();
//	surfacePtr S8_ptr = S8.clone();
//	surfacePtr S9_ptr = S9.clone();
//	surfacePtr S10_ptr = S10.clone();
//	surfacePtr S11_ptr = S11.clone();
//	surfacePtr S12_ptr = S12.clone();
//
//	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
//	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
//
//	// debug
//	oftenUse::print(optSystemElement, 550.0);
//
//	// check the start system
//	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
//	workTheSystem.push_back(checkRefIndexes);
//	std::vector<real> rms_Zemax{ 131.499, 227.589, 305.283 };
//	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
//	workTheSystem.push_back(testSystem);
//
//	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E38";
//	std::string nameStartSys = "startSys_E38_fourLensSystem";
//	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);
//
//	// set target cardinal points
//	targetCardinalPointsStruct tarCarP;
//	tarCarP.setTargetWFNO(1.630616);
//	tarCarP.setTargetMag(-0.305243);
//
//	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei(optSystemElement, tarCarP, location, example));
//
//	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
//	return checker;
//}
//// E39 four lens system
//bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_lensSystem_E39(std::string example)
//{
//
//	std::vector<bool> workTheSystem;
//	real semiHeight = 12.0;
//
//	ApertureStopElement S0(/* semi height*/ 2.5, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());
//
//	SphericalElement S1(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSK10_S1());
//	SphericalElement S2(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF3_S1(), /*refractive index B*/mGlasses.getNSK10_S1());
//	SphericalElement S3(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF3_S1());
//
//	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S5(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAF3_S1(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S6(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,125.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF3_S1());
//
//	SphericalElement S7(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSK10_S1());
//	SphericalElement S8(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,145.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSK10_S1());
//
//	SphericalElement S9(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,155.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S10(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,165.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF3_S1(), /*refractive index B*/mGlasses.getNBK10_S1());
//	SphericalElement S11(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,175.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF3_S1());
//
//	PlanElement S12(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,196.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());
//
//	// **********************************
//	// set parameter variable
//	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//	S11.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
//
//	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	S11.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
//	// **********************************
//
//
//	//surfacePtr Aper0_E39_ptr = AperStop0_E39.clone();
//	surfacePtr S0_ptr = S0.clone();
//	surfacePtr S1_ptr = S1.clone();
//	surfacePtr S2_ptr = S2.clone();
//	surfacePtr S3_ptr = S3.clone();
//	surfacePtr S4_ptr = S4.clone();
//	surfacePtr S5_ptr = S5.clone();
//	surfacePtr S6_ptr = S6.clone();
//	surfacePtr S7_ptr = S7.clone();
//	surfacePtr S8_ptr = S8.clone();
//	surfacePtr S9_ptr = S9.clone();
//	surfacePtr S10_ptr = S10.clone();
//	surfacePtr S11_ptr = S11.clone();
//	surfacePtr S12_ptr = S12.clone();
//
//	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr };
//	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };
//
//	//	build optical system
//	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);
//
//	// debug
//	oftenUse::print(optSystemElement, 550.0);
//
//	// check the start system
//	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
//	workTheSystem.push_back(checkRefIndexes);
//	std::vector<real> rms_Zemax{ 66.121, 86.782, 105.772 };
//	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
//	workTheSystem.push_back(testSystem);
//
//	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/E39";
//	std::string nameStartSys = "startSys_E39_fourLensSystem";
//	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);
//
//	// set target cardinal points
//	targetCardinalPointsStruct tarCarP;
//	tarCarP.setTargetWFNO(5.701100);
//	tarCarP.setTargetMag(-0.570466);
//
//	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei(optSystemElement, tarCarP, location, example));
//
//	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
//	return checker;
//}
//


// *** inf ***
// super fct
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUR_LensSystem_superFct_inf()
{
	std::vector<bool> workTheSystem;

	mInf = true;
	mObj = false;

	// debug mode
	turn_ON_debugMode();
	//

	// debug
	if (mDebugMode)
	{
		mDefaulParaDLS.setMaxInterations(1);
		mDefaultParameterGenetic.setMaxInterationGenetic(1);
		mPopulation = 5;
		mNumberBestFitLenses = 1;
	}

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/infinity";
	std::string name = "testLensReplaceAndOptimize_statistic_FOUR_LensSystem_inf";


	// EX inf
	bool checkEX_FOUR_LensSystem_inf = testLRaO_stat_FOUE_LensSystem_EX_inf("EX_FOUR_LensSystem_inf");
	workTheSystem.push_back(checkEX_FOUR_LensSystem_inf);
	if (checkEX_FOUR_LensSystem_inf) { inportExportData::saveStringInTXT_includingTime(location, name, "EX inf four lens system worked"); };


	exportAllStatisticDataReplace_FOUR_LensesGeneticAndDLS_12();



	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}


// E0
bool testLensReplaceAndOptimize_statistic_FOUR_LensSystem::testLRaO_stat_FOUE_LensSystem_EX_inf(std::string example)
{
	std::vector<bool> workTheSystem;

	real semiHeight = 10.0;
	mGlasses.loadGlassCatalog_Schott();

	ApertureStopElement S0(/* semi height*/2.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S3(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK10_S1());
	SphericalElement S4(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF6_S1(), /*refractive index B*/mGlasses.getNLAK10_S1());
	SphericalElement S5(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());

	SphericalElement S6(/*radius*/ 300.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S7(/*radius*/ 300.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	SphericalElement S8(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S9(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S10(/*radius*/ 300.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	PlanElement S11(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,85.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S9.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S10.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);


	S2.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S7.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	//surfacePtr Aper0_E5_ptr = AperStop0_E5.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone() , mRefrac.clone(),  mRefrac.clone(),  mRefrac.clone(),  mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 149.914, 147.362, 145.066 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mFieldAngle_Vec_X, mFieldAngle_Vec_Y, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fourLensSystems/infinity/EX";
	std::string nameStartSys = "startSys_EX_inf";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetEFL(45.0);
	tarCarP.setTargetWFNO(12.0);

	mSaveAllResults_FOUR_LensSystem.push_back(doTheStatisticEvaluation_FOUR_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// *** ***
