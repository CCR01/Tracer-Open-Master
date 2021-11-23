#include "testLensReplaceAndOptimize_statistic_fiveLensSystem.h"

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


testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLensReplaceAndOptimize_statistic_FIVE_LensSystem()
{
	loadImportantParameter();
	turn_OFF_debugMode();
}

testLensReplaceAndOptimize_statistic_FIVE_LensSystem::~testLensReplaceAndOptimize_statistic_FIVE_LensSystem() {}

typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr<InteractionRay_LLT> interaction_ptr;

// load importent parameter
void testLensReplaceAndOptimize_statistic_FIVE_LensSystem::loadImportantParameter()
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
void testLensReplaceAndOptimize_statistic_FIVE_LensSystem::turn_ON_debugMode()
{
	mDebugMode = true;
}
void testLensReplaceAndOptimize_statistic_FIVE_LensSystem::turn_OFF_debugMode()
{
	mDebugMode = false;
}

// export all statistic data replace two lenses
void testLensReplaceAndOptimize_statistic_FIVE_LensSystem::exportAllStatisticDataReplace_FIVE_LensesGeneticAndDLS_12()
{
	std::string dataToExportString = "merit_GeneticAndDLS_12, duration_GeneticAndDLS_12, replaceSequence_GeneticAndDLS_12, bestLensNumber_GeneticAndDLS_12 ";
	std::vector<real> dataToExport_vec;
	dataToExport_vec.resize(12);


	std::string location{};
	if (mObj)
	{
		location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems";
	}
	else if (mInf)
	{
		location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/infinity";
	}

	std::string nameExcel = "data_FIVE_LensSystems";
	//inportExportData::removeDateCSV(location, nameExcel);

	for (unsigned int i = 0; i < mSaveAllResults_FIVE_LensSystem.size(); i++)
	{
		inportExportData::exportDataToExcel_makeOneRowSpace(location, nameExcel);
		inportExportData::exportDataToExcel_name(location, nameExcel, mSaveAllResults_FIVE_LensSystem[i][0].getExample());


		for (unsigned int k = 0; k < mSaveAllResults_FIVE_LensSystem[0].size(); k++)
		{

			// Genetic and DLS 12 -> FIVE lens system
			dataToExport_vec[0] = mSaveAllResults_FIVE_LensSystem[i][k].getMeritVaL_GeneticAndDLS_12();
			dataToExport_vec[1] = mSaveAllResults_FIVE_LensSystem[i][k].getDurationTime_GeneticAndDLS_12();

			dataToExport_vec[2] = mSaveAllResults_FIVE_LensSystem[i][k].getReplacedSequence_GeneticAndDLS12()[0];
			dataToExport_vec[3] = mSaveAllResults_FIVE_LensSystem[i][k].getReplacedSequence_GeneticAndDLS12()[1];
			dataToExport_vec[4] = mSaveAllResults_FIVE_LensSystem[i][k].getReplacedSequence_GeneticAndDLS12()[2];
			dataToExport_vec[5] = mSaveAllResults_FIVE_LensSystem[i][k].getReplacedSequence_GeneticAndDLS12()[3];
			dataToExport_vec[6] = mSaveAllResults_FIVE_LensSystem[i][k].getReplacedSequence_GeneticAndDLS12()[4];

			dataToExport_vec[7] = mSaveAllResults_FIVE_LensSystem[i][k].getBestLensNumberWasTaken()[0];
			dataToExport_vec[8] = mSaveAllResults_FIVE_LensSystem[i][k].getBestLensNumberWasTaken()[1];
			dataToExport_vec[9] = mSaveAllResults_FIVE_LensSystem[i][k].getBestLensNumberWasTaken()[2];
			dataToExport_vec[10] = mSaveAllResults_FIVE_LensSystem[i][k].getBestLensNumberWasTaken()[3];
			dataToExport_vec[11] = mSaveAllResults_FIVE_LensSystem[i][k].getBestLensNumberWasTaken()[4];


			inportExportData::exportDataToExcel_vector(location, nameExcel, dataToExportString, dataToExport_vec);

		}


	}
}

// super fct
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_lensSystem_superFct_obj()
{
	std::vector<bool> workTheSystem;

	// debug mode
	turn_ON_debugMode();
	//
	mInf = false;
	mObj = true;

	// debug
	if (mDebugMode)
	{
		mDefaulParaDLS.setMaxInterations(1);
		mDefaultParameterGenetic.setMaxInterationGenetic(1);
		mPopulation = 5;
		mNumberBestFitLenses = 1;
	}

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems";
	std::string name = "testLensReplaceAndOptimize_statistic_FIVE_LensSystem";


	//// E0 FIVE lens system
	//bool checkE0_FIVE_LensSystem = testLRaO_stat_FIVE_lensSystem_E0("E0_FIVE_LensSystem");
	//workTheSystem.push_back(checkE0_FIVE_LensSystem);
	//if (checkE0_FIVE_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E0 FIVE lens system worked"); };
	//
	//// E1 FIVE lens system
	//bool checkE1_FIVE_LensSystem = testLRaO_stat_FIVE_lensSystem_E1("E1_FIVE_LensSystem");
	//workTheSystem.push_back(checkE1_FIVE_LensSystem);
	//if (checkE1_FIVE_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E1 FIVE lens system worked"); };
	//
	//// E2 FIVE lens system
	//bool checkE2_FIVE_LensSystem = testLRaO_stat_FIVE_lensSystem_E2("E2_FIVE_LensSystem");
	//workTheSystem.push_back(checkE2_FIVE_LensSystem);
	//if (checkE2_FIVE_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E2 FIVE lens system worked"); };
	//
	//// E3 FIVE lens system
	//bool checkE3_FIVE_LensSystem = testLRaO_stat_FIVE_lensSystem_E3("E3_FIVE_LensSystem");
	//workTheSystem.push_back(checkE3_FIVE_LensSystem);
	//if (checkE3_FIVE_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E3 FIVE lens system worked"); };
	//
	//// E4 FIVE lens system
	//bool checkE4_FIVE_LensSystem = testLRaO_stat_FIVE_lensSystem_E4("E4_FIVE_LensSystem");
	//workTheSystem.push_back(checkE4_FIVE_LensSystem);
	//if (checkE4_FIVE_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E4 FIVE lens system worked"); };
	//
	//// E5 FIVE lens system
	//bool checkE5_FIVE_LensSystem = testLRaO_stat_FIVE_lensSystem_E5("E5_FIVE_LensSystem");
	//workTheSystem.push_back(checkE5_FIVE_LensSystem);
	//if (checkE5_FIVE_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E5 FIVE lens system worked"); };
	//
	//// E6 FIVE lens system
	//bool checkE6_FIVE_LensSystem = testLRaO_stat_FIVE_lensSystem_E6("E6_FIVE_LensSystem");
	//workTheSystem.push_back(checkE6_FIVE_LensSystem);
	//if (checkE6_FIVE_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E6 FIVE lens system worked"); };
	//
	//// E7 FIVE lens system
	//bool checkE7_FIVE_LensSystem = testLRaO_stat_FIVE_lensSystem_E7("E7_FIVE_LensSystem");
	//workTheSystem.push_back(checkE7_FIVE_LensSystem);
	//if (checkE7_FIVE_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E7 FIVE lens system worked"); };
	//
	//// E8 FIVE lens system
	//bool checkE8_FIVE_LensSystem = testLRaO_stat_FIVE_lensSystem_E8("E8_FIVE_LensSystem");
	//workTheSystem.push_back(checkE8_FIVE_LensSystem);
	//if (checkE8_FIVE_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E8 FIVE lens system worked"); };
	//
	//// E9 FIVE lens system
	//bool checkE9_FIVE_LensSystem = testLRaO_stat_FIVE_lensSystem_E9("E9_FIVE_LensSystem");
	//workTheSystem.push_back(checkE9_FIVE_LensSystem);
	//if (checkE9_FIVE_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E9 FIVE lens system worked"); };
	//
	//// E10 FIVE lens system
	//bool checkE10_FIVE_LensSystem = testLRaO_stat_FIVE_lensSystem_E10("E10_FIVE_LensSystem");
	//workTheSystem.push_back(checkE10_FIVE_LensSystem);
	//if (checkE10_FIVE_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E10 FIVE lens system worked"); };
	//
	//// E11 FIVE lens system
	//bool checkE11_FIVE_LensSystem = testLRaO_stat_FIVE_lensSystem_E11("E11_FIVE_LensSystem");
	//workTheSystem.push_back(checkE11_FIVE_LensSystem);
	//if (checkE11_FIVE_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E11 FIVE lens system worked"); };
	////
	//// E12 FIVE lens system
	//bool checkE12_FIVE_LensSystem = testLRaO_stat_FIVE_lensSystem_E12("E12_FIVE_LensSystem");
	//workTheSystem.push_back(checkE12_FIVE_LensSystem);
	//if (checkE12_FIVE_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E12 FIVE lens system worked"); };
	//
	//// E13 FIVE lens system
	//bool checkE13_FIVE_LensSystem = testLRaO_stat_FIVE_lensSystem_E13("E13_FIVE_LensSystem");
	//workTheSystem.push_back(checkE13_FIVE_LensSystem);
	//if (checkE13_FIVE_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E13 FIVE lens system worked"); };
	//
	//// E14 FIVE lens system
	//bool checkE14_FIVE_LensSystem = testLRaO_stat_FIVE_lensSystem_E14("E14_FIVE_LensSystem");
	//workTheSystem.push_back(checkE14_FIVE_LensSystem);
	//if (checkE14_FIVE_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E14 FIVE lens system worked"); };
	//
	//// E15 FIVE lens system
	//bool checkE15_FIVE_LensSystem = testLRaO_stat_FIVE_lensSystem_E15("E15_FIVE_LensSystem");
	//workTheSystem.push_back(checkE15_FIVE_LensSystem);
	//if (checkE15_FIVE_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E15 FIVE lens system worked"); };
	//
	//// E16 FIVE lens system
	//bool checkE16_FIVE_LensSystem = testLRaO_stat_FIVE_lensSystem_E16("E16_FIVE_LensSystem");
	//workTheSystem.push_back(checkE16_FIVE_LensSystem);
	//if (checkE16_FIVE_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E16 FIVE lens system worked"); };
	//
	//// E17 FIVE lens system
	//bool checkE17_FIVE_LensSystem = testLRaO_stat_FIVE_lensSystem_E17("E17_FIVE_LensSystem");
	//workTheSystem.push_back(checkE17_FIVE_LensSystem);
	//if (checkE17_FIVE_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E17 FIVE lens system worked"); };
	//
	//// E18 FIVE lens system
	//bool checkE18_FIVE_LensSystem = testLRaO_stat_FIVE_lensSystem_E18("E18_FIVE_LensSystem");
	//workTheSystem.push_back(checkE18_FIVE_LensSystem);
	//if (checkE18_FIVE_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E18 FIVE lens system worked"); };
	//
	//// E19 FIVE lens system
	//bool checkE19_FIVE_LensSystem = testLRaO_stat_FIVE_lensSystem_E19("E19_FIVE_LensSystem");
	//workTheSystem.push_back(checkE19_FIVE_LensSystem);
	//if (checkE19_FIVE_LensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E19 FIVE lens system worked"); };


	exportAllStatisticDataReplace_FIVE_LensesGeneticAndDLS_12();



	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}

// do the statistic evaluation
std::vector<saveLRaO_GeneticAndDLS_12_statistic> testLensReplaceAndOptimize_statistic_FIVE_LensSystem::doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_obj(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example)
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

std::vector<saveLRaO_GeneticAndDLS_12_statistic> testLensReplaceAndOptimize_statistic_FIVE_LensSystem::doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_inf(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example)
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

// do the statistic evaluation left to right, right to left, max seidel, min seidel
std::vector<saveLRaO_GeneticAndDLS_12_statistic> testLensReplaceAndOptimize_statistic_FIVE_LensSystem::doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example)
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

std::vector<saveLRaO_GeneticAndDLS_12_statistic>  testLensReplaceAndOptimize_statistic_FIVE_LensSystem::doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example)
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

// E0 FIVE lens system
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_lensSystem_E0(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/2.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S4(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());
	SphericalElement S5(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());

	SphericalElement S6(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S7(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S9(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S10(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	SphericalElement S11(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S12(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF6_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S13(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,110.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 202.570, 243.464,283.469 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/E0";
	std::string nameStartSys = "startSys_E0_FIVELensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(4.21889);
	tarCarP.setTargetMag(-0.56429);

	mSaveAllResults_FIVE_LensSystem.push_back(doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E1 FIVE lens system
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_lensSystem_E1(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/2.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNF2_S1());
	SphericalElement S2(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNF2_S1());
	SphericalElement S3(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,58.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S4(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,68.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S5(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,73.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S6(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,78.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF44_S1());
	SphericalElement S7(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,84.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNLASF44_S1());
	SphericalElement S8(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,89.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S9(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,96.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK12_S1());
	SphericalElement S10(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,101.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK12_S1());

	SphericalElement S11(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,106.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S12(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,111.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNBASF64_S1());
	SphericalElement S13(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,116.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBASF64_S1());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,123.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 165.232, 343.867, 524.657 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/E1";
	std::string nameStartSys = "startSys_E1_FIVELensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.7245);
	tarCarP.setTargetMag(-0.5040);

	mSaveAllResults_FIVE_LensSystem.push_back(doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E2 FIVE lens system
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_lensSystem_E2(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 15.0;

	ApertureStopElement S0(/* semi height*/ 3.5, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK2_S1());
	SphericalElement S2(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK10_S1(), /*refractive index B*/mGlasses.getNBAK2_S1());
	SphericalElement S3(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());

	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S5(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S6(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAK2_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S7(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBAK2_S1(), /*refractive index B*/mGlasses.getNFK5_S1());
	SphericalElement S8(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNFK5_S1());

	SphericalElement S9(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF52_S1());
	SphericalElement S10(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF52_S1());

	SphericalElement S11(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S12(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,125.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S13(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,145.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 113.404, 189.552, 254.041 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/E2";
	std::string nameStartSys = "startSys_E2_FIVELensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.807929);
	tarCarP.setTargetMag(-0.494393);

	mSaveAllResults_FIVE_LensSystem.push_back(doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E3 FIVE lens system
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_lensSystem_E3(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 30.0;

	ApertureStopElement S0(/* semi height*/ 6.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S2(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSSK8_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S3(/*radius*/ 110.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,102.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());

	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,112.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S5(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S6(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,128.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S7(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S8(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,148.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S9(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,158.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S10(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,173.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S11(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,188.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNKF9_S1());
	SphericalElement S12(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,203.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNKF9_S1());
	SphericalElement S13(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,218.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,248.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 203.788, 281.291, 355.718 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/E3";
	std::string nameStartSys = "startSys_E3_FIVELensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.371502);
	tarCarP.setTargetMag(-0.571794);

	mSaveAllResults_FIVE_LensSystem.push_back(doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E4 FIVE lens system
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_lensSystem_E4(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 20.0;

	ApertureStopElement S0(/* semi height*/ 4.5, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAK2_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,86.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBAK2_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,94.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S4(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,102.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	SphericalElement S6(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S7(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,125.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S8(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S9(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S10(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,143.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S11(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,148.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S12(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,156.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S13(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,164.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,176.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 156.800, 194.865, 229.569 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/E4";
	std::string nameStartSys = "startSys_E4_FIVELensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.08352);
	tarCarP.setTargetMag(-0.469253);

	mSaveAllResults_FIVE_LensSystem.push_back(doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E5 FIVE lens system
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_lensSystem_E5(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/ 1.5, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S2(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S3(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S5(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAK1_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S6(/*radius*/ 160.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK1_S1());

	SphericalElement S7(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S8(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S9(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S10(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());

	SphericalElement S11(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S12(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S13(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,138.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 106.694, 131.584, 153.999 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/E5";
	std::string nameStartSys = "startSys_E5_FIVELensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(7.243418);
	tarCarP.setTargetMag(-0.543784);

	mSaveAllResults_FIVE_LensSystem.push_back(doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E6 FIVE lens system
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_lensSystem_E6(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 20.0;

	ApertureStopElement S0(/* semi height*/ 6.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S2(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,96.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S3(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S4(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNF2_S1());
	SphericalElement S5(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,111.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNF2_S1());
	SphericalElement S6(/*radius*/ 180.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S7(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S8(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,124.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());

	SphericalElement S9(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,129.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK4_S1());
	SphericalElement S10(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK4_S1());

	SphericalElement S11(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S12(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,146.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S13(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,163.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 158.588, 256.049, 337.822 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/E6";
	std::string nameStartSys = "startSys_E6_FIVELensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(1.635606);
	tarCarP.setTargetMag(-0.396159);

	mSaveAllResults_FIVE_LensSystem.push_back(doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E7 FIVE lens system
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_lensSystem_E7(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 30.0;

	ApertureStopElement S0(/* semi height*/ 7.5, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 300.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,91.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S3(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,102.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S4(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,112.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S5(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,127.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S6(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,137.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	SphericalElement S7(/*radius*/ 130.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,147.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S8(/*radius*/ 130.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,161.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S9(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,171.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAK4_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S10(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,177.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBAK4_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S11(/*radius*/ 180.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,187.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S12(/*radius*/ 180.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,199.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S13(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,209.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,224.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 308.604, 338.545, 370.183 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/E7";
	std::string nameStartSys = "startSys_E7_FIVELensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.565604);
	tarCarP.setTargetMag(-0.707429);

	mSaveAllResults_FIVE_LensSystem.push_back(doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E8 FIVE lens system
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_lensSystem_E8(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 15.0;

	ApertureStopElement S0(/* semi height*/ 3.5, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK4_S1());
	SphericalElement S2(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNBAK4_S1());
	SphericalElement S3(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S4(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBASF64_S1());
	SphericalElement S5(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,125.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK10_S1(), /*refractive index B*/mGlasses.getNBASF64_S1());
	SphericalElement S6(/*radius*/ 170.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());

	SphericalElement S7(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,145.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAK4_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S8(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,155.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBAK4_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S9(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,165.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S10(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,175.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S11(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,185.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF21_S1());
	SphericalElement S12(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,195.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNLAF21_S1());
	SphericalElement S13(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,205.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,235.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 97.114, 154.748, 205.142 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/E8";
	std::string nameStartSys = "startSys_E8_FIVELensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(4.289004);
	tarCarP.setTargetMag(-0.586818);

	mSaveAllResults_FIVE_LensSystem.push_back(doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E9 FIVE lens system
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_lensSystem_E9(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 25.0;

	ApertureStopElement S0(/* semi height*/ 5.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF44_S1());
	SphericalElement S2(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,102.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNLASF44_S1());
	SphericalElement S3(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S4(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK22_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S5(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,126.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNLAK22_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S6(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,134.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());

	SphericalElement S7(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,144.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF44_S1());
	SphericalElement S8(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,152.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF44_S1());

	SphericalElement S9(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,162.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S10(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,170.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S11(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,180.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S12(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,190.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK10_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S13(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,196.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,201.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 104.026, 173.920, 233.724 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/E9";
	std::string nameStartSys = "startSys_E9_FIVELensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.622942);
	tarCarP.setTargetMag(-0.519951);

	mSaveAllResults_FIVE_LensSystem.push_back(doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E10 FIVE lens system
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_lensSystem_E10(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/ 2.5, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,77.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 160.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,79.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S4(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,84.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());
	SphericalElement S5(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,86.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());

	SphericalElement S6(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,91.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S7(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,93.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S8(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,98.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S9(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S10(/*radius*/ 110.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,102.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	SphericalElement S11(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,107.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S12(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,109.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF6_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S13(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,111.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,119.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S7.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 63.373, 99.391, 139.725 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/E10";
	std::string nameStartSys = "startSys_E10_FIVELensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.533146);
	tarCarP.setTargetMag(-0.282234);

	mSaveAllResults_FIVE_LensSystem.push_back(doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E11 FIVE lens system
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_lensSystem_E11(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 30.0;

	ApertureStopElement S0(/* semi height*/ 6.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,112.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK8_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK8_S1());

	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S5(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,144.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());

	SphericalElement S6(/*radius*/ 160.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,154.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK10_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S7(/*radius*/ 160.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,172.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK10_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S8(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,182.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S9(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,194.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK9_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S10(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,202.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK9_S1());

	SphericalElement S11(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,212.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S12(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,227.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S13(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,235.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,242.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S7.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 166.878, 262.210, 340.787 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/E11";
	std::string nameStartSys = "startSys_E11_FIVELensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.87751);
	tarCarP.setTargetMag(-0.574286);

	mSaveAllResults_FIVE_LensSystem.push_back(doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E12 FIVE lens system
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_lensSystem_E12(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 25.0;

	ApertureStopElement S0(/* semi height*/ 4.5, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF44_S1());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,92.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNLASF44_S1());
	SphericalElement S3(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,98.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S4(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,108.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S5(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S6(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLASF44_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S7(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,138.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNLASF44_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S8(/*radius*/ 180.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,148.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S9(/*radius*/ 110.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,154.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S10(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,162.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S11(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,172.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
	SphericalElement S12(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,180.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getNBK10_S1());
	SphericalElement S13(/*radius*/ 210.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,186.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,200.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S7.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 154.127, 208.467, 261.337 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/E12";
	std::string nameStartSys = "startSys_E12_FIVELensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(5.92255);
	tarCarP.setTargetMag(-1.094166);

	mSaveAllResults_FIVE_LensSystem.push_back(doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E13 FIVE lens system
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_lensSystem_E13(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 20.0;

	ApertureStopElement S0(/* semi height*/ 4.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 160.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 180.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S3(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	SphericalElement S4(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK2_S1());
	SphericalElement S5(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK2_S1());

	SphericalElement S6(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S7(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());

	SphericalElement S8(/*radius*/ 110.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S9(/*radius*/ 110.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,160.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF52_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S10(/*radius*/ 160.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,170.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF52_S1());

	SphericalElement S11(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,180.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S12(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,190.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S13(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,200.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,213.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S7.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 186.937, 243.469, 295.025 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/E13";
	std::string nameStartSys = "startSys_E13_FIVELensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.687554);
	tarCarP.setTargetMag(-0.429713);

	mSaveAllResults_FIVE_LensSystem.push_back(doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E14 FIVE lens system
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_lensSystem_E14(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 15.0;

	ApertureStopElement S0(/* semi height*/ 3.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S2(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,77.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSSK8_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S3(/*radius*/ 180.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,82.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());

	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,87.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK22_S1());
	SphericalElement S5(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,92.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK22_S1());

	SphericalElement S6(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,97.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S7(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,102.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S8(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,107.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF44_S1());
	SphericalElement S9(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,114.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK10_S1(), /*refractive index B*/mGlasses.getNLASF44_S1());
	SphericalElement S10(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,119.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());

	SphericalElement S11(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,124.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK22_S1());
	SphericalElement S12(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,131.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK10_S1(), /*refractive index B*/mGlasses.getNLAK22_S1());
	SphericalElement S13(/*radius*/ 130.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,136.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,151.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S7.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 70.670, 98.684, 135.785 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/E14";
	std::string nameStartSys = "startSys_E14_FIVELensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.481348);
	tarCarP.setTargetMag(-0.524473);

	mSaveAllResults_FIVE_LensSystem.push_back(doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E15 FIVE lens system
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_lensSystem_E15(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 12.0;

	ApertureStopElement S0(/* semi height*/ 3.5, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S2(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,83.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK34_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S3(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,89.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK34_S1());

	SphericalElement S4(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,94.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLASF45_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S5(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,102.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNLASF45_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S6(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,107.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF9_S1());
	SphericalElement S7(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBASF64_S1(), /*refractive index B*/mGlasses.getNLASF9_S1());
	SphericalElement S8(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,121.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBASF64_S1());

	SphericalElement S9(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,126.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK4_S1());
	SphericalElement S10(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,134.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK4_S1());

	SphericalElement S11(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,139.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S12(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,147.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAF2_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S13(/*radius*/ 160.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,153.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,163.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 69.169, 115.795, 155.185 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/E15";
	std::string nameStartSys = "startSys_E15_FIVELensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.933744);
	tarCarP.setTargetMag(-0.41269);

	mSaveAllResults_FIVE_LensSystem.push_back(doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E16 FIVE lens system
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_lensSystem_E16(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 16.0;

	ApertureStopElement S0(/* semi height*/ 4.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,86.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S4(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF40_S1());
	SphericalElement S5(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,101.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF40_S1());

	SphericalElement S6(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,106.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
	SphericalElement S7(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,112.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAF35_S1(), /*refractive index B*/mGlasses.getNBK10_S1());
	SphericalElement S8(/*radius*/ 160.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,116.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF35_S1());

	SphericalElement S9(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,121.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S10(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,127.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S11(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,132.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S12(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,138.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLASF40_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S13(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,142.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF40_S1());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,162.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 50.166, 84.900, 115.466 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/E16";
	std::string nameStartSys = "startSys_E16_FIVELensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.668386);
	tarCarP.setTargetMag(-0.59158);

	mSaveAllResults_FIVE_LensSystem.push_back(doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E17 FIVE lens system
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_lensSystem_E17(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 18.0;

	ApertureStopElement S0(/* semi height*/ 4.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S2(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S3(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,118.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	SphericalElement S4(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,128.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S5(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,133.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S6(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,143.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S7(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,155.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK10_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S8(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,161.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK10_S1());

	SphericalElement S9(/*radius*/ 160.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,171.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S10(/*radius*/ 160.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,177.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S11(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,187.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF7_S1());
	SphericalElement S12(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,191.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNLAF7_S1());
	SphericalElement S13(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,195.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,205.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 130.034, 196.624, 253.994 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/E17";
	std::string nameStartSys = "startSys_E17_FIVELensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.652545);
	tarCarP.setTargetMag(-0.489346);

	mSaveAllResults_FIVE_LensSystem.push_back(doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E18 FIVE lens system
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_lensSystem_E18(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 22.0;

	ApertureStopElement S0(/* semi height*/ 4.5, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,106.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S3(/*radius*/ 160.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,114.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	SphericalElement S4(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,124.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,132.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S6(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,142.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S7(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,152.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK10_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S8(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,158.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK10_S1());

	SphericalElement S9(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,168.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S10(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,174.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S11(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,184.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF7_S1());
	SphericalElement S12(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,192.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNLAF7_S1());
	SphericalElement S13(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,200.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,210.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 207.809, 286.242, 355.881 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/E18";
	std::string nameStartSys = "startSys_E18_FIVELensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.037886);
	tarCarP.setTargetMag(-0.30579);

	mSaveAllResults_FIVE_LensSystem.push_back(doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E19 FIVE lens system
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_lensSystem_E19(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 14.0;

	ApertureStopElement S0(/* semi height*/ 3.0, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 160.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,91.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());

	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,96.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF40_S1());
	SphericalElement S5(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,99.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF40_S1());

	SphericalElement S6(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,104.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
	SphericalElement S7(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,109.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK22_S1(), /*refractive index B*/mGlasses.getNBK10_S1());
	SphericalElement S8(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,112.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK22_S1());

	SphericalElement S9(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,117.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF2_S1());
	SphericalElement S10(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF2_S1());

	SphericalElement S11(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,125.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK22_S1());
	SphericalElement S12(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK10_S1(), /*refractive index B*/mGlasses.getNLAK22_S1());
	SphericalElement S13(/*radius*/ 180.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,133.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());

	PlanElement S14(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,142.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S13.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S13.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S13_ptr = S13.clone();
	surfacePtr S14_ptr = S14.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr, S14_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 62.398, 103.621, 138.158 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/E19";
	std::string nameStartSys = "startSys_E19_FIVELensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.735987);
	tarCarP.setTargetMag(-0.328864);

	mSaveAllResults_FIVE_LensSystem.push_back(doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}


// *** inf ***
// super fct
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_LensSystem_superFct_inf()
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

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/infinity";
	std::string name = "testLensReplaceAndOptimize_statistic_FIVE_LensSystem_inf";


	// EX inf
	bool checkEX_FIVE_LensSystem_inf = testLRaO_stat_FIVE_LensSystem_EX_inf("EX_FIVE_LensSystem_inf");
	workTheSystem.push_back(checkEX_FIVE_LensSystem_inf);
	if (checkEX_FIVE_LensSystem_inf) { inportExportData::saveStringInTXT_includingTime(location, name, "EX inf five lens system worked"); };


	exportAllStatisticDataReplace_FIVE_LensesGeneticAndDLS_12();



	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E0
bool testLensReplaceAndOptimize_statistic_FIVE_LensSystem::testLRaO_stat_FIVE_LensSystem_EX_inf(std::string example)
{
	std::vector<bool> workTheSystem;

	real semiHeight = 10.0;
	mGlasses.loadGlassCatalog_Schott();

	ApertureStopElement S0(/* semi height*/2.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S3(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK10_S1());
	SphericalElement S4(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF6_S1(), /*refractive index B*/mGlasses.getNLAK10_S1());
	SphericalElement S5(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());

	SphericalElement S6(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S7(/*radius*/ 300.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	SphericalElement S8(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S9(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S10(/*radius*/ 300.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	SphericalElement S11(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S12(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S13(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,95.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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
	S12.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);


	S2.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S7.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S10.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S12.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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
	surfacePtr S13_ptr = S13.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr, S10_ptr, S11_ptr, S12_ptr, S13_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(),mRefrac.clone(),mRefrac.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone() , mRefrac.clone(),  mRefrac.clone(),  mRefrac.clone(),  mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 346.927, 358.840, 370.743 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mFieldAngle_Vec_X, mFieldAngle_Vec_Y, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/fiveLensSystems/infinity/EX";
	std::string nameStartSys = "startSys_EX_inf";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetEFL(40.0);
	tarCarP.setTargetWFNO(10.0);

	mSaveAllResults_FIVE_LensSystem.push_back(doTheStatisticEvaluation_FIVE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// *** ***