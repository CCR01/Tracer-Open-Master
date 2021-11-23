#include "testLensReplaceAndOptimize_statistic_threeLensSystem.h"

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


testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLensReplaceAndOptimize_statistic_THREE_LensSystem()
{
	loadImportantParameter();
	turn_OFF_debugMode();
}

testLensReplaceAndOptimize_statistic_THREE_LensSystem::~testLensReplaceAndOptimize_statistic_THREE_LensSystem() {}

typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr<InteractionRay_LLT> interaction_ptr;

// load importent parameter
void testLensReplaceAndOptimize_statistic_THREE_LensSystem::loadImportantParameter()
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

	mWavelength_green_vec.push_back(mWave587d);

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

	mLeftToRight_repSeq = replaceSequence::leftToRight;
	mRightToLeft_repSeq = replaceSequence::RightToLeft;
	mMaxSeidel_repSeq = replaceSequence::maxSeidelAberLens;
	mMinSeidel_repSeq = replaceSequence::minSeidelAberLens;
	mAllSequences_repSeq = replaceSequence::allPossibleSequences;
}


// debug mode
void testLensReplaceAndOptimize_statistic_THREE_LensSystem::turn_ON_debugMode()
{
	mDebugMode = true;
}
void testLensReplaceAndOptimize_statistic_THREE_LensSystem::turn_OFF_debugMode()
{
	mDebugMode = false;
}

// export all statistic data replace three lenses
void testLensReplaceAndOptimize_statistic_THREE_LensSystem::exportAllStatisticDataReplace_THREE_LensesGeneticAndDLS_12()
{
	std::string dataToExportString = "merit_GeneticAndDLS_12, duration_GeneticAndDLS_12, replaceSequence_GeneticAndDLS_12, bestLensNumber_GeneticAndDLS_12 ";
	std::vector<real> dataToExport_vec;
	dataToExport_vec.resize(8);

	std::string location{};
	if (mObj)
	{
		location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems";
	}
	else if (mInf)
	{
		location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/infinity";
	}

	std::string nameExcel = "data_threeLensSystems";
	//inportExportData::removeDateCSV(location, nameExcel);

	for (unsigned int i = 0; i < mSaveAllResults_Three_LensSystem.size(); i++)
	{
		inportExportData::exportDataToExcel_makeOneRowSpace(location, nameExcel);
		inportExportData::exportDataToExcel_name(location, nameExcel, mSaveAllResults_Three_LensSystem[i][0].getExample());


		for (unsigned int k = 0; k < mSaveAllResults_Three_LensSystem[0].size(); k++)
		{

			// Genetic and DLS 12 -> three lens system
			dataToExport_vec[0] = mSaveAllResults_Three_LensSystem[i][k].getMeritVaL_GeneticAndDLS_12();
			dataToExport_vec[1] = mSaveAllResults_Three_LensSystem[i][k].getDurationTime_GeneticAndDLS_12();

			dataToExport_vec[2] = mSaveAllResults_Three_LensSystem[i][k].getReplacedSequence_GeneticAndDLS12()[0];
			dataToExport_vec[3] = mSaveAllResults_Three_LensSystem[i][k].getReplacedSequence_GeneticAndDLS12()[1];
			dataToExport_vec[4] = mSaveAllResults_Three_LensSystem[i][k].getReplacedSequence_GeneticAndDLS12()[2];

			dataToExport_vec[5] = mSaveAllResults_Three_LensSystem[i][k].getBestLensNumberWasTaken()[0];
			dataToExport_vec[6] = mSaveAllResults_Three_LensSystem[i][k].getBestLensNumberWasTaken()[1];
			dataToExport_vec[7] = mSaveAllResults_Three_LensSystem[i][k].getBestLensNumberWasTaken()[2];


			inportExportData::exportDataToExcel_vector(location, nameExcel, dataToExportString, dataToExport_vec);

		}


	}
}

void testLensReplaceAndOptimize_statistic_THREE_LensSystem::exportDataReplace_THREE_LensesGeneticAndDLS_12(std::string location, std::string repSeq, saveLRaO_GeneticAndDLS_12_statistic dataToExport)
{
	std::vector<real> dataToExport_vec;
	dataToExport_vec.resize(8);

	std::string nameExcel = "data_Three_";
	std::string nameExcelTot = nameExcel + repSeq;
	std::string dataToExportString = "merit_GeneticAndDLS_12, duration_GeneticAndDLS_12, replaceSequence_GeneticAndDLS_12, bestLensNumber_GeneticAndDLS_12 ";

	inportExportData::exportDataToExcel_name(location, nameExcelTot, dataToExport.getExample());


	// Genetic and DLS 12 -> three lens system
	dataToExport_vec[0] = dataToExport.getMeritVaL_GeneticAndDLS_12();
	dataToExport_vec[1] = dataToExport.getDurationTime_GeneticAndDLS_12();

	dataToExport_vec[2] = dataToExport.getReplacedSequence_GeneticAndDLS12()[0];
	dataToExport_vec[3] = dataToExport.getReplacedSequence_GeneticAndDLS12()[1];
	dataToExport_vec[4] = dataToExport.getReplacedSequence_GeneticAndDLS12()[2];

	dataToExport_vec[5] = dataToExport.getBestLensNumberWasTaken()[0];
	dataToExport_vec[6] = dataToExport.getBestLensNumberWasTaken()[1];
	dataToExport_vec[7] = dataToExport.getBestLensNumberWasTaken()[2];


	inportExportData::exportDataToExcel_vector(location, nameExcelTot, dataToExportString, dataToExport_vec);


}


// super fct
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_lensSystem_superFct_obj()
{
	std::vector<bool> workTheSystem;
	mInf = false;
	mObj = true;

	// debug mode
	//turn_ON_debugMode();
	//

	// debug
	if (mDebugMode)
	{
		mDefaulParaDLS.setMaxInterations(1);
		mDefaultParameterGenetic.setMaxInterationGenetic(1);
		mPopulation = 1;
		mNumberBestFitLenses = 1;
	}

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems";
	std::string name = "testLensReplaceAndOptimize_statistic_threeLensSystem";


	//// E0 three lens system
	//bool checkE0_threeLensSystem = testLRaO_stat_THREE_LensSystem_E0("E0_threeLensSystem");
	//workTheSystem.push_back(checkE0_threeLensSystem);
	//if (checkE0_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E0 three lens system worked"); };
	//
	//// E1 three lens system
	//bool checkE1_threeLensSystem = testLRaO_stat_THREE_LensSystem_E1("E1_threeLensSystem");
	//workTheSystem.push_back(checkE1_threeLensSystem);
	//if (checkE1_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E1 three lens system worked"); };
	//
	//// E2 three lens system
	//bool checkE2_threeLensSystem = testLRaO_stat_THREE_LensSystem_E2("E2_threeLensSystem");
	//workTheSystem.push_back(checkE2_threeLensSystem);
	//if (checkE2_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E2 three lens system worked"); };
	//
	//// E3 three lens system
	//bool checkE3_threeLensSystem = testLRaO_stat_THREE_LensSystem_E3("E3_threeLensSystem");
	//workTheSystem.push_back(checkE3_threeLensSystem);
	//if (checkE3_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E3 three lens system worked"); };
	//
	//// E4 three lens system
	//bool checkE4_threeLensSystem = testLRaO_stat_THREE_LensSystem_E4("E4_threeLensSystem");
	//workTheSystem.push_back(checkE4_threeLensSystem);
	//if (checkE4_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E4 three lens system worked"); };
	//
	//// E5 three lens system
	//bool checkE5_threeLensSystem = testLRaO_stat_THREE_LensSystem_E5("E5_threeLensSystem");
	//workTheSystem.push_back(checkE5_threeLensSystem);
	//if (checkE5_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E5 three lens system worked"); };
	////
	//// E6 three lens system
	//bool checkE6_threeLensSystem = testLRaO_stat_THREE_LensSystem_E6("E6_threeLensSystem");
	//workTheSystem.push_back(checkE6_threeLensSystem);
	//if (checkE6_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E6 three lens system worked"); };
	//
	//// E7 three lens system
	//bool checkE7_threeLensSystem = testLRaO_stat_THREE_LensSystem_E7("E7_threeLensSystem");
	//workTheSystem.push_back(checkE7_threeLensSystem);
	//if (checkE7_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E7 three lens system worked"); };
	//
	//// E8 three lens system
	//bool checkE8_threeLensSystem = testLRaO_stat_THREE_LensSystem_E8("E8_threeLensSystem");
	//workTheSystem.push_back(checkE8_threeLensSystem);
	//if (checkE8_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E8 three lens system worked"); };
	//
	//// E9 three lens system
	//bool checkE9_threeLensSystem = testLRaO_stat_THREE_LensSystem_E9("E9_threeLensSystem");
	//workTheSystem.push_back(checkE9_threeLensSystem);
	//if (checkE9_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E9 three lens system worked"); };
	//
	//// E10 three lens system
	//bool checkE10_threeLensSystem = testLRaO_stat_THREE_LensSystem_E10("E10_threeLensSystem");
	//workTheSystem.push_back(checkE10_threeLensSystem);
	//if (checkE10_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E10 three lens system worked"); };
	//
	//// E11 three lens system
	//bool checkE11_threeLensSystem = testLRaO_stat_THREE_LensSystem_E11("E11_threeLensSystem");
	//workTheSystem.push_back(checkE11_threeLensSystem);
	//if (checkE11_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E11 three lens system worked"); };
	//
	//// E12 three lens system
	//bool checkE12_threeLensSystem = testLRaO_stat_THREE_LensSystem_E12("E12_threeLensSystem");
	//workTheSystem.push_back(checkE12_threeLensSystem);
	//if (checkE12_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E12 three lens system worked"); };
	//
	//// E13 three lens system
	//bool checkE13_threeLensSystem = testLRaO_stat_THREE_LensSystem_E13("E13_threeLensSystem");
	//workTheSystem.push_back(checkE13_threeLensSystem);
	//if (checkE13_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E13 three lens system worked"); };
	//
	//// E14 three lens system
	//bool checkE14_threeLensSystem = testLRaO_stat_THREE_LensSystem_E14("E14_threeLensSystem");
	//workTheSystem.push_back(checkE14_threeLensSystem);
	//if (checkE14_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E14 three lens system worked"); };
	//
	//// E15 three lens system
	//bool checkE15_threeLensSystem = testLRaO_stat_THREE_LensSystem_E15("E15_threeLensSystem");
	//workTheSystem.push_back(checkE15_threeLensSystem);
	//if (checkE15_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E15 three lens system worked"); };
	//
	//// E16 three lens system
	//bool checkE16_threeLensSystem = testLRaO_stat_THREE_LensSystem_E16("E16_threeLensSystem");
	//workTheSystem.push_back(checkE16_threeLensSystem);
	//if (checkE16_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E16 three lens system worked"); };
	//
	//// E17 three lens system
	//bool checkE17_threeLensSystem = testLRaO_stat_THREE_LensSystem_E17("E17_threeLensSystem");
	//workTheSystem.push_back(checkE17_threeLensSystem);
	//if (checkE17_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E17 three lens system worked"); };
	//
	//// E18 three lens system
	//bool checkE18_threeLensSystem = testLRaO_stat_THREE_LensSystem_E18("E18_threeLensSystem");
	//workTheSystem.push_back(checkE18_threeLensSystem);
	//if (checkE18_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E18 three lens system worked"); };
	//
	//// E19 three lens system
	//bool checkE19_threeLensSystem = testLRaO_stat_THREE_LensSystem_E19("E19_threeLensSystem");
	//workTheSystem.push_back(checkE19_threeLensSystem);
	//if (checkE19_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E19 three lens system worked"); };
	//
	//// E20 three lens system
	//bool checkE20_threeLensSystem = testLRaO_stat_THREE_LensSystem_E20("E20_threeLensSystem");
	//workTheSystem.push_back(checkE20_threeLensSystem);
	//if (checkE20_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E20 three lens system worked"); };
	//
	// E21 three lens system
	bool checkE21_threeLensSystem = testLRaO_stat_THREE_LensSystem_E21("E21_threeLensSystem");
	workTheSystem.push_back(checkE21_threeLensSystem);
	if (checkE21_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E21 three lens system worked"); };
	//
	//// E22 three lens system
	//bool checkE22_threeLensSystem = testLRaO_stat_THREE_LensSystem_E22("E22_threeLensSystem");
	//workTheSystem.push_back(checkE22_threeLensSystem);
	//if (checkE22_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E22 three lens system worked"); };
	//
	//// E23 three lens system
	//bool checkE23_threeLensSystem = testLRaO_stat_THREE_LensSystem_E23("E23_threeLensSystem");
	//workTheSystem.push_back(checkE23_threeLensSystem);
	//if (checkE23_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E23 three lens system worked"); };
	//
	//// E24 three lens system
	//bool checkE24_threeLensSystem = testLRaO_stat_THREE_LensSystem_E24("E24_threeLensSystem");
	//workTheSystem.push_back(checkE24_threeLensSystem);
	//if (checkE24_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E24 three lens system worked"); };
	//
	//// E25 three lens system
	//bool checkE25_threeLensSystem = testLRaO_stat_THREE_LensSystem_E25("E25_threeLensSystem");
	//workTheSystem.push_back(checkE25_threeLensSystem);
	//if (checkE25_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E25 three lens system worked"); };
	//
	//// E26 three lens system
	//bool checkE26_threeLensSystem = testLRaO_stat_THREE_LensSystem_E26("E26_threeLensSystem");
	//workTheSystem.push_back(checkE26_threeLensSystem);
	//if (checkE26_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E26 three lens system worked"); };
	//
	//// E27 three lens system
	//bool checkE27_threeLensSystem = testLRaO_stat_THREE_LensSystem_E27("E27_threeLensSystem");
	//workTheSystem.push_back(checkE27_threeLensSystem);
	//if (checkE27_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E27 three lens system worked"); };
	//
	//// E28 three lens system
	//bool checkE28_threeLensSystem = testLRaO_stat_THREE_LensSystem_E28("E28_threeLensSystem");
	//workTheSystem.push_back(checkE28_threeLensSystem);
	//if (checkE28_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E28 three lens system worked"); };
	//
	//// E29 three lens system
	//bool checkE29_threeLensSystem = testLRaO_stat_THREE_LensSystem_E29("E29_threeLensSystem");
	//workTheSystem.push_back(checkE29_threeLensSystem);
	//if (checkE29_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E29 three lens system worked"); };
	//
	//// E30 three lens system
	//bool checkE30_threeLensSystem = testLRaO_stat_THREE_LensSystem_E30("E30_threeLensSystem");
	//workTheSystem.push_back(checkE30_threeLensSystem);
	//if (checkE30_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E30 three lens system worked"); };
	//
	//// E31 three lens system
	//bool checkE31_threeLensSystem = testLRaO_stat_THREE_LensSystem_E31("E31_threeLensSystem");
	//workTheSystem.push_back(checkE31_threeLensSystem);
	//if (checkE31_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E31 three lens system worked"); };
	//
	//// E32 three lens system
	//bool checkE32_threeLensSystem = testLRaO_stat_THREE_LensSystem_E32("E32_threeLensSystem");
	//workTheSystem.push_back(checkE32_threeLensSystem);
	//if (checkE32_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E32 three lens system worked"); };
	//
	//// E33 three lens system
	//bool checkE33_threeLensSystem = testLRaO_stat_THREE_LensSystem_E33("E33_threeLensSystem");
	//workTheSystem.push_back(checkE33_threeLensSystem);
	//if (checkE33_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E33 three lens system worked"); };
	//
	//// E34 three lens system
	//bool checkE34_threeLensSystem = testLRaO_stat_THREE_LensSystem_E34("E34_threeLensSystem");
	//workTheSystem.push_back(checkE34_threeLensSystem);
	//if (checkE34_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E34 three lens system worked"); };
	//
	//// E35 three lens system
	//bool checkE35_threeLensSystem = testLRaO_stat_THREE_LensSystem_E35("E35_threeLensSystem");
	//workTheSystem.push_back(checkE35_threeLensSystem);
	//if (checkE35_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E35 three lens system worked"); };
	//
	//// E36 three lens system
	//bool checkE36_threeLensSystem = testLRaO_stat_THREE_LensSystem_E36("E36_threeLensSystem");
	//workTheSystem.push_back(checkE36_threeLensSystem);
	//if (checkE36_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E36 three lens system worked"); };
	//
	//// E37 three lens system
	//bool checkE37_threeLensSystem = testLRaO_stat_THREE_LensSystem_E37("E37_threeLensSystem");
	//workTheSystem.push_back(checkE37_threeLensSystem);
	//if (checkE37_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E37 three lens system worked"); };
	//
	//// E38 three lens system
	//bool checkE38_threeLensSystem = testLRaO_stat_THREE_LensSystem_E38("E38_threeLensSystem");
	//workTheSystem.push_back(checkE38_threeLensSystem);
	//if (checkE38_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E38 three lens system worked"); };
	//
	//// E39 three lens system
	//bool checkE39_threeLensSystem = testLRaO_stat_THREE_LensSystem_E39("E39_threeLensSystem");
	//workTheSystem.push_back(checkE39_threeLensSystem);
	//if (checkE39_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E39 three lens system worked"); };
	//


	exportAllStatisticDataReplace_THREE_LensesGeneticAndDLS_12();



	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}

// do the statistic evaluation
std::vector<saveLRaO_GeneticAndDLS_12_statistic> testLensReplaceAndOptimize_statistic_THREE_LensSystem::doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example)
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

std::vector<saveLRaO_GeneticAndDLS_12_statistic> testLensReplaceAndOptimize_statistic_THREE_LensSystem::doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_inf(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example)
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

std::vector<saveLRaO_GeneticAndDLS_12_statistic>  testLensReplaceAndOptimize_statistic_THREE_LensSystem::doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example)
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
std::vector <saveLRaO_GeneticAndDLS_12_statistic>  testLensReplaceAndOptimize_statistic_THREE_LensSystem::doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example)
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

saveLRaO_GeneticAndDLS_12_statistic  testLensReplaceAndOptimize_statistic_THREE_LensSystem::doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj_saveIntermediateResults(OpticalSystemElement optSysEle, std::vector<real> wavelength_vec, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example, replaceSequence repSequence, unsigned int numberBestFitLenses)
{
	unsigned int numberLenses = oftenUse::findLensesInOptSysEle(optSysEle).size();
	saveLRaO_GeneticAndDLS_12_statistic LRaO_statistic_GeneticAndDLS_12;

	LRaO_statistic_GeneticAndDLS_12.setNumberOfLensesInOptSys(numberLenses);
	LRaO_statistic_GeneticAndDLS_12.resizeBestLensNumberWasTaken(numberLenses);
	LRaO_statistic_GeneticAndDLS_12.setExample(example);

	OpticalSystemElement optSysEle_initial;
	optimizeMethode optiMethode = optimizeMethode::GeneticAndDLS_12;
	std::string nameOptimizationMethode = "GeneticAndDLS_12";

	Light_LLT light = oftenUse::getDefaultLight();
	real bestMeritVal{};
	std::vector<unsigned int> usedReplaceSeq{};
	std::vector<OptSysEle_Merit_LensType> optSysMeritLensType;


	std::string locationTotal{};
	std::string reqFolder = oftenUse::getNameFolder(repSequence);
	std::string redSeqName = oftenUse::getRepSequence_string(repSequence);

	locationTotal = location + reqFolder;
	optSysEle_initial = optSysEle.getDeepCopyOptSysEle();

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
	auto startTime = std::chrono::high_resolution_clock::now();
	testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(optSysEle_initial, mField_vec, wavelength_vec, mRings, mArms, optiMethode, /*number best fit lenses*/ numberBestFitLenses, true, repSequence, light);
	// end time
	auto endTime = std::chrono::high_resolution_clock::now();

	OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();


	std::chrono::duration<double> totalDuration_secondes = endTime - startTime;
	bestMeritVal = testLensReplaceAndOptiSuperFct.getBestMeritVal();
	usedReplaceSeq = testLensReplaceAndOptiSuperFct.getReplacedSequence();
	optSysMeritLensType = testLensReplaceAndOptiSuperFct.getBestCatalogLensesForreplace();


	std::string exampleAndOptiMethode = example + "_" + nameOptimizationMethode;
	testLensReplaceAndOptiSuperFct.exportBestParameterCatalogForReplaceTXT(locationTotal, exampleAndOptiMethode);

	std::string nameOptSys = example + "_replacedOptSys_";
	std::string totalNameOptSys = nameOptSys + nameOptimizationMethode;
	inportExportData::saveOpticalSystemAsTXT(optSysEle_lensRepSuperFct, 550.0, locationTotal, totalNameOptSys);

	// export rms values
	std::vector<std::string> nameDoubel_vec = { "fieldAngel_0", "fieldAngle_707", "fieldAngle_10" };
	std::string replaceRMSvalue_str = "replaceRMSvalue";
	std::string nameTXT_ReplaceRMSvalueFields = replaceRMSvalue_str + "_" + redSeqName;
	std::vector<real> rmsVecReplaceSys = oftenUse::getRMSoptSysHLT(optSysEle_lensRepSuperFct, mField_vec, mWavelength_FdV_vec, mRings, mArms);
	inportExportData::saveVecDoubleInTXT(locationTotal, nameTXT_ReplaceRMSvalueFields, nameDoubel_vec, rmsVecReplaceSys, true);

	std::vector<unsigned int> bestLensWasTaken;
	bestLensWasTaken.resize(optSysMeritLensType.size());
	for (unsigned int i = 0; i < optSysMeritLensType.size(); ++i)
	{
		bestLensWasTaken[i] = optSysMeritLensType[i].getPositionInBestMatchLensVec();
	}


	LRaO_statistic_GeneticAndDLS_12.setMeritVal_GeneticAndDLS_12(bestMeritVal);
	LRaO_statistic_GeneticAndDLS_12.setDurationTime_GeneticAndDLS_12(totalDuration_secondes.count());
	LRaO_statistic_GeneticAndDLS_12.setReplaceSequence_GeneticAndDLS(usedReplaceSeq);
	LRaO_statistic_GeneticAndDLS_12.setBestLensNumberWasTaken(bestLensWasTaken);



	return LRaO_statistic_GeneticAndDLS_12;

}


saveLRaO_GeneticAndDLS_12_statistic  testLensReplaceAndOptimize_statistic_THREE_LensSystem::doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_givenSequence(OpticalSystemElement optSysEle, std::vector<real> wavelength_vec, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example, std::vector<unsigned int> seqence_vec, unsigned int numberBestFitLenses)
{
	unsigned int numberLenses = oftenUse::findLensesInOptSysEle(optSysEle).size();
	saveLRaO_GeneticAndDLS_12_statistic LRaO_statistic_GeneticAndDLS_12;

	LRaO_statistic_GeneticAndDLS_12.setNumberOfLensesInOptSys(numberLenses);
	LRaO_statistic_GeneticAndDLS_12.resizeBestLensNumberWasTaken(numberLenses);
	LRaO_statistic_GeneticAndDLS_12.setExample(example);

	OpticalSystemElement optSysEle_initial;
	optimizeMethode optiMethode = optimizeMethode::GeneticAndDLS_12;
	std::string nameOptimizationMethode = "GeneticAndDLS_12";

	Light_LLT light = oftenUse::getDefaultLight();
	real bestMeritVal{};
	std::vector<unsigned int> usedReplaceSeq{};
	std::vector<OptSysEle_Merit_LensType> optSysMeritLensType;


	std::string locationTotal{};
	std::string reqFolder;
	unsigned int tempInt{};
	std::string tempString{};
	for (unsigned int i = 0; i < seqence_vec.size(); ++i)
	{
		tempInt = seqence_vec[i];
		tempString = std::to_string(tempInt);
		reqFolder = reqFolder + tempString;
	}


	locationTotal = location + "/" + reqFolder;
	optSysEle_initial = optSysEle.getDeepCopyOptSysEle();

	LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
	testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(targetCarPoints);
	testLensReplaceAndOptiSuperFct.setDefaulParaDLS(mDefaulParaDLS);
	testLensReplaceAndOptiSuperFct.setDefaultParaGenetic(mDefaultParameterGenetic);
	testLensReplaceAndOptiSuperFct.setPopulation(mPopulation);
	testLensReplaceAndOptiSuperFct.setLoad_ALL_LensCatalogs();
	testLensReplaceAndOptiSuperFct.loadSequence(seqence_vec);

	if (mDebugMode)
	{
		testLensReplaceAndOptiSuperFct.turn_ON_DebugMode();
	}

	// start time
	auto startTime = std::chrono::high_resolution_clock::now();
	testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(optSysEle_initial, mField_vec, wavelength_vec, mRings, mArms, optiMethode, /*number best fit lenses*/ numberBestFitLenses, true, replaceSequence::givenSequence, light);
	// end time
	auto endTime = std::chrono::high_resolution_clock::now();

	OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();


	std::chrono::duration<double> totalDuration_secondes = endTime - startTime;
	bestMeritVal = testLensReplaceAndOptiSuperFct.getBestMeritVal();
	usedReplaceSeq = testLensReplaceAndOptiSuperFct.getReplacedSequence();
	optSysMeritLensType = testLensReplaceAndOptiSuperFct.getBestCatalogLensesForreplace();


	std::string exampleAndOptiMethode = example + "_" + nameOptimizationMethode;
	testLensReplaceAndOptiSuperFct.exportBestParameterCatalogForReplaceTXT(locationTotal, exampleAndOptiMethode);

	std::string nameOptSys = example + "_replacedOptSys_";
	std::string totalNameOptSys = nameOptSys + nameOptimizationMethode;
	inportExportData::saveOpticalSystemAsTXT(optSysEle_lensRepSuperFct, 550.0, locationTotal, totalNameOptSys);

	// export rms values
	std::vector<std::string> nameDoubel_vec = { "fieldAngel_0", "fieldAngle_707", "fieldAngle_10" };
	std::string replaceRMSvalue_str = "replaceRMSvalue";
	std::string nameTXT_ReplaceRMSvalueFields = replaceRMSvalue_str + "_" + reqFolder;
	std::vector<real> rmsVecReplaceSys = oftenUse::getRMSoptSysHLT(optSysEle_lensRepSuperFct, mFieldAngle_Vec_X, mFieldAngle_Vec_Y, mWavelength_FdV_vec, mRings, mArms);
	inportExportData::saveVecDoubleInTXT(locationTotal, nameTXT_ReplaceRMSvalueFields, nameDoubel_vec, rmsVecReplaceSys, true);

	std::vector<unsigned int> bestLensWasTaken;
	bestLensWasTaken.resize(optSysMeritLensType.size());
	for (unsigned int i = 0; i < optSysMeritLensType.size(); ++i)
	{
		bestLensWasTaken[i] = optSysMeritLensType[i].getPositionInBestMatchLensVec();
	}


	LRaO_statistic_GeneticAndDLS_12.setMeritVal_GeneticAndDLS_12(bestMeritVal);
	LRaO_statistic_GeneticAndDLS_12.setDurationTime_GeneticAndDLS_12(totalDuration_secondes.count());
	LRaO_statistic_GeneticAndDLS_12.setReplaceSequence_GeneticAndDLS(usedReplaceSeq);
	LRaO_statistic_GeneticAndDLS_12.setBestLensNumberWasTaken(bestLensWasTaken);



	return LRaO_statistic_GeneticAndDLS_12;
}

// E0 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E0(std::string example)
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

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,105.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 146.102, 192.294,236.692 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E0";
	std::string nameStartSys = "startSys_E0_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(5.56785);
	tarCarP.setTargetMag(-0.752465);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E1 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E1(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 8.0;

	ApertureStopElement S0(/* semi height*/2.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S2(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,46.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S3(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,48.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S4(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAK1_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,64.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK1_S1());

	SphericalElement S7(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,69.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNF2_S1());
	SphericalElement S8(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,74.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNF2_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,89.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 205.626, 234.303,262.082 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E1";
	std::string nameStartSys = "startSys_E1_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(4.1773);
	tarCarP.setTargetMag(-0.5591);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E2 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E2(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 12.0;

	ApertureStopElement S0(/* semi height*/2.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAK1_S1());
	SphericalElement S2(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,54.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNF2_S1(), /*refractive index B*/mGlasses.getNBAK1_S1());
	SphericalElement S3(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,62.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNF2_S1());

	SphericalElement S4(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,72.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S5(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S6(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S7(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S8(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,125.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 138.117, 270.651, 389.315 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E2";
	std::string nameStartSys = "startSys_E2_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.72545);
	tarCarP.setTargetMag(-0.45703);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E3 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E3(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 25.0;

	ApertureStopElement S0(/* semi height*/ 3.5, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 110.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAK1_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBAK1_S1(), /*refractive index B*/mGlasses.getNF2_S1());
	SphericalElement S3(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNF2_S1());

	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S5(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,121.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S7(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,143.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S8(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,155.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,165.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 139.369, 336.500, 535.008 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E3";
	std::string nameStartSys = "startSys_E3_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(1.81371);
	tarCarP.setTargetMag(-0.366294);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E4 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E4(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 20.0;

	ApertureStopElement S0(/* semi height*/ 2.0, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBASF2_S1());
	SphericalElement S2(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,58.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNBASF2_S1());
	SphericalElement S3(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S4(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNKF9_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,97.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNKF9_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S7(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK7_S1());
	SphericalElement S8(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,160.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK7_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,185.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 436.800, 324.640, 369.057 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E4";
	std::string nameStartSys = "startSys_E4_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(4.76753);
	tarCarP.setTargetMag(-0.94942);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E5 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E5(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 15.0;

	ApertureStopElement S0(/* semi height*/ 2.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S2(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK10_S1(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S3(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK10_S1());

	SphericalElement S4(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,82.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S5(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S6(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLASF40_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S7(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNLASF40_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,140.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 112.427, 179.265, 237.861 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E5";
	std::string nameStartSys = "startSys_E5_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(7.997285);
	tarCarP.setTargetMag(-1.078267);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E6 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E6(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/ 2.0, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSK11_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSK11_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,78.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S4(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,86.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S5(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,98.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());

	SphericalElement S6(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,108.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());
	SphericalElement S7(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,124.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAF3_S1(), /*refractive index B*/mGlasses.getNSSK8_S1());
	SphericalElement S8(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,128.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF3_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,135.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 130.709, 130.976, 153.019 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E6";
	std::string nameStartSys = "startSys_E6_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.011805);
	tarCarP.setTargetMag(-0.343243);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E7 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E7(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 30.0;

	ApertureStopElement S0(/* semi height*/ 6.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());
	SphericalElement S2(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSK15_S1(), /*refractive index B*/mGlasses.getNSF56_S1());
	SphericalElement S3(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,125.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSK15_S1());

	SphericalElement S4(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S5(/*radius*/ 220.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,175.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());

	SphericalElement S6(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,195.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S7(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,220.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAF3_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,230.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF3_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,242.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 189.175, 231.861, 271.497 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E7";
	std::string nameStartSys = "startSys_E7_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.115608);
	tarCarP.setTargetMag(-0.66765);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E8 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E8(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 20.0;

	ApertureStopElement S0(/* semi height*/ 5.5, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF56_S1());
	SphericalElement S3(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,88.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S4(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLASF9_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S5(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,116.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNLASF9_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S6(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,132.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());
	SphericalElement S7(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,152.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF6_S1());
	SphericalElement S8(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,170.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,200.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 595.840, 604.685, 650.539 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E8";
	std::string nameStartSys = "startSys_E8_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.10907);
	tarCarP.setTargetMag(-0.864927);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E9 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E9(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 15.0;

	ApertureStopElement S0(/* semi height*/ 3.5, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,52.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S3(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,67.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	SphericalElement S6(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,87.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S7(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,109.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,124.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,149.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 368.454, 327.994, 332.360 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E9";
	std::string nameStartSys = "startSys_E9_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.203605);
	tarCarP.setTargetMag(-0.907122);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E10 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E10(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 8.0;

	ApertureStopElement S0(/* semi height*/ 1.5, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getBAFN10_S1());
	SphericalElement S2(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,38.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getBAFN10_S1());

	SphericalElement S3(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,43.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF36_S1());
	SphericalElement S4(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,51.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNLAF36_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,56.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S6(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,61.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());
	SphericalElement S7(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,71.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSSK8_S1(), /*refractive index B*/mGlasses.getNSF56_S1());
	SphericalElement S8(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,83.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,101.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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

	S2.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 160.400, 131.326, 135.940 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E10";
	std::string nameStartSys = "startSys_E10_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(5.636347);
	tarCarP.setTargetMag(-0.848015);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E11 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E11(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 12.0;

	ApertureStopElement S0(/* semi height*/ 2.0, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,74.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S3(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,86.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S4(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,106.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF19_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,113.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF19_S1());

	SphericalElement S6(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,121.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());
	SphericalElement S7(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,145.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSK10_S1(), /*refractive index B*/mGlasses.getNSF56_S1());
	SphericalElement S8(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,163.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSK10_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,188.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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

	S2.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 248.476, 227.286, 242.096 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E11";
	std::string nameStartSys = "startSys_E11_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(4.492078);
	tarCarP.setTargetMag(-0.402367);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E12 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E12(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 27.0;

	ApertureStopElement S0(/* semi height*/ 5.0, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF52_S1());
	SphericalElement S2(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF52_S1());

	SphericalElement S3(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNKF9_S1());
	SphericalElement S4(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,91.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNF2_S1(), /*refractive index B*/mGlasses.getNKF9_S1());
	SphericalElement S5(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,103.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNF2_S1());

	SphericalElement S6(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,121.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBASF64_S1());
	SphericalElement S7(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,139.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNBASF64_S1());
	SphericalElement S8(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,154.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,180.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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

	S2.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 226.306, 345.438, 476.532 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E12";
	std::string nameStartSys = "startSys_E12_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.051951);
	tarCarP.setTargetMag(-1.038181);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E13 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E13(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 15.0;

	ApertureStopElement S0(/* semi height*/ 3.0, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S3(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S4(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNSF6_S1());
	SphericalElement S5(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,123.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());

	SphericalElement S6(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,133.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S7(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,155.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,173.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,203.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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

	S2.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 325.486, 313.338, 302.991 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E13";
	std::string nameStartSys = "startSys_E13_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(5.30956);
	tarCarP.setTargetMag(-0.581807);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E14 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E14(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/ 2.5, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S3(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S4(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF6_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());

	SphericalElement S6(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S7(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,98.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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

	S2.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 326.927, 256.063, 225.922 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E14";
	std::string nameStartSys = "startSys_E14_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(4.325194);
	tarCarP.setTargetMag(-1.095993);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E15 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E15(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 25.0;

	ApertureStopElement S0(/* semi height*/ 4.5, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,77.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF56_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());

	SphericalElement S4(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,92.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,114.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,133.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());

	SphericalElement S7(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,148.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S8(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,163.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,180.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 133.501, 222.483, 322.380 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E15";
	std::string nameStartSys = "startSys_E15_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.694861);
	tarCarP.setTargetMag(-0.693373);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E16 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E16(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 15.0;

	ApertureStopElement S0(/* semi height*/ 3.5, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S2(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S3(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S4(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S5(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSSK8_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S6(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());

	SphericalElement S7(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK10_S1());
	SphericalElement S8(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,145.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK10_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,160.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 132.806, 248.194, 345.460 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E16";
	std::string nameStartSys = "startSys_E16_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.54749);
	tarCarP.setTargetMag(-0.511969);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E17 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E17(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/ 1.5, /*point*/{ 0.0,0.0,20.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK34_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,43.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNLAK34_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S3(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,49.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());

	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,54.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,61.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,66.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	SphericalElement S7(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,74.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S8(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,95.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 308.103, 253.357, 217.739 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E17";
	std::string nameStartSys = "startSys_E17_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.821722);
	tarCarP.setTargetMag(-0.57409);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E18 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E18(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/ 1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF56_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,56.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF56_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,64.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S4(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,71.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,83.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S6(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,91.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S7(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,99.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBASF64_S1());
	SphericalElement S8(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,111.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBASF64_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,136.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 135.034, 138.065, 260.359 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E18";
	std::string nameStartSys = "startSys_E18_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(5.197822);
	tarCarP.setTargetMag(-0.526105);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E19 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E19(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/ 1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,53.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNF2_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,59.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNF2_S1());

	SphericalElement S4(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,64.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK10_S1());
	SphericalElement S5(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,74.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF6_S1(), /*refractive index B*/mGlasses.getNLAK10_S1());
	SphericalElement S6(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,82.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());

	SphericalElement S7(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,87.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,120.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

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

	S3.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 130.741, 105.793, 95.186 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E19";
	std::string nameStartSys = "startSys_E19_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(5.842303);
	tarCarP.setTargetMag(-0.586269);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_obj(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E20 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E20(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;


	SphericalElement S0(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S1(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,38.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,46.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());

	ApertureStopElement S3(/* semi height*/ 4.0, /*point*/{ 0.0,0.0,51.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,56.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,62.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S7(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK34_S1());
	SphericalElement S8(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,88.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK34_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,118.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E20_ptr = AperStop0_E20.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 83.375, 73.399, 67.498 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E20";
	std::string nameStartSys = "startSys_E20_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(4.127848);
	tarCarP.setTargetMag(-0.848248);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E21 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E21(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 14.0;


	SphericalElement S0(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
	SphericalElement S1(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,88.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK9_S1(), /*refractive index B*/mGlasses.getNBK10_S1());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,94.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK9_S1());

	ApertureStopElement S3(/* semi height*/ 5.0, /*point*/{ 0.0,0.0,99.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S4(/*radius*/ 110.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,104.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 110.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,112.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());

	SphericalElement S7(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK9_S1());
	SphericalElement S8(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,138.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK9_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,165.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E21_ptr = AperStop0_E21.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 38.591, 35.435, 32.442 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_green_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E21";
	std::string nameStartSys = "startSys_E21_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.68149);
	tarCarP.setTargetMag(-0.451986);

	unsigned int numberBestFitLenses = 2;
	//// left to right
	//saveLRaO_GeneticAndDLS_12_statistic resultsLeftToRight = doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj_saveIntermediateResults(optSystemElement, mWavelength_green_vec, tarCarP, location, example, mLeftToRight_repSeq, numberBestFitLenses);
	//std::string locLeftToRight = location + "/leftToRight";
	//exportDataReplace_THREE_LensesGeneticAndDLS_12(locLeftToRight, "leftToRight", resultsLeftToRight);
	//
	//// right to left
	//saveLRaO_GeneticAndDLS_12_statistic resultsRightToLeft = doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj_saveIntermediateResults(optSystemElement, mWavelength_green_vec, tarCarP, location, example, mRightToLeft_repSeq, numberBestFitLenses);
	//std::string locRightToLeft = location + "/rightToLeft";
	//exportDataReplace_THREE_LensesGeneticAndDLS_12(locRightToLeft, "rightToLeft", resultsRightToLeft);
	//
	//// max seidel
	//saveLRaO_GeneticAndDLS_12_statistic resultsMaxSeidel = doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj_saveIntermediateResults(optSystemElement, mWavelength_green_vec, tarCarP, location, example, mMaxSeidel_repSeq, numberBestFitLenses);
	//std::string locMaxSeidel = location + "/maxSeidel";
	//exportDataReplace_THREE_LensesGeneticAndDLS_12(locMaxSeidel, "maxSeidel", resultsMaxSeidel);
	//
	//// min seidel
	//saveLRaO_GeneticAndDLS_12_statistic resultsMinSeidel = doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj_saveIntermediateResults(optSystemElement, mWavelength_green_vec, tarCarP, location, example, mMinSeidel_repSeq, numberBestFitLenses);
	//std::string locMinSeidel = location + "/minSeidel";
	//exportDataReplace_THREE_LensesGeneticAndDLS_12(locMinSeidel, "minSeidel", resultsMinSeidel);

	// 021
	std::vector<unsigned int> repSeq021 = { 0,2,1 };
	saveLRaO_GeneticAndDLS_12_statistic results021 = doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_givenSequence(optSystemElement, mWavelength_green_vec, tarCarP, location, example, repSeq021, numberBestFitLenses);
	std::string loc021 = location + "/021";
	exportDataReplace_THREE_LensesGeneticAndDLS_12(loc021, "021", results021);

	// 102
	std::vector<unsigned int> repSeq102 = { 1,0,2 };
	saveLRaO_GeneticAndDLS_12_statistic results102 = doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_givenSequence(optSystemElement, mWavelength_green_vec, tarCarP, location, example, repSeq102, numberBestFitLenses);
	std::string loc102 = location + "/102";
	exportDataReplace_THREE_LensesGeneticAndDLS_12(loc102, "102", results102);

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}

// E22 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E22(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 18.0;


	SphericalElement S0(/*radius*/ 190.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S1(/*radius*/ 190.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,86.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNLASF9_S1());
	SphericalElement S2(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,92.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF9_S1());

	ApertureStopElement S3(/* semi height*/ 9.0, /*point*/{ 0.0,0.0,97.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S4(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());
	SphericalElement S5(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,108.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());

	SphericalElement S6(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,116.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S7(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,124.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLASF9_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF9_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,153.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E22_ptr = AperStop0_E22.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 159.321, 158.453, 157.910 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E22";
	std::string nameStartSys = "startSys_E22_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(1.966624);
	tarCarP.setTargetMag(-0.385982);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E23 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E23(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 20.0;


	SphericalElement S0(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S1(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF57_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF57_S1());

	ApertureStopElement S3(/* semi height*/ 10.0, /*point*/{ 0.0,0.0,122.5 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF46_S1());
	SphericalElement S5(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,145.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNLASF46_S1());
	SphericalElement S6(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,160.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S7(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,175.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,190.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,207.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E23_ptr = AperStop0_E23.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(),mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 110.162, 109.929, 109.972 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E23";
	std::string nameStartSys = "startSys_E23_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.273180);
	tarCarP.setTargetMag(-0.467456);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E24 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E24(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 24.0;


	SphericalElement S0(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF43_S1());
	SphericalElement S1(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNLASF43_S1());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	ApertureStopElement S3(/* semi height*/ 9.0, /*point*/{ 0.0,0.0,112.5 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S4(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S5(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S6(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,145.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S7(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,160.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF43_S1());
	SphericalElement S8(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,175.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF43_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,192.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E24_ptr = AperStop0_E24.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 161.535, 165.280, 169.550 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E24";
	std::string nameStartSys = "startSys_E24_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.393546);
	tarCarP.setTargetMag(-0.600860);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E25 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E25(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 15.0;


	SphericalElement S0(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S1(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,99.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getAir());

	ApertureStopElement S2(/* semi height*/ 8.0, /*point*/{ 0.0,0.0,104.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S3(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,109.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S4(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,119.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,127.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());

	SphericalElement S6(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,132.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S7(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,144.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,176.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S1.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E25_ptr = AperStop0_E25.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 169.490, 179.630, 189.453 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E25";
	std::string nameStartSys = "startSys_E25_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.049244);
	tarCarP.setTargetMag(-0.320631);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E26 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E26(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 16.0;


	SphericalElement S0(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK9_S1());
	SphericalElement S1(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNLAK9_S1());
	SphericalElement S2(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	ApertureStopElement S3(/* semi height*/ 10.0, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S4(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK9_S1());
	SphericalElement S5(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getNLAK9_S1());
	SphericalElement S6(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,165.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());

	SphericalElement S7(/*radius*/ 110.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,185.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S8(/*radius*/ 110.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,200.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,228.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S6.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E26_ptr = AperStop0_E26.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 136.257, 143.055, 149.828 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E26";
	std::string nameStartSys = "startSys_E26_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.576082);
	tarCarP.setTargetMag(-0.585917);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E27 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E27(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;


	SphericalElement S0(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S1(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,88.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK10_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,94.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());

	ApertureStopElement S3(/* semi height*/ 5.5, /*point*/{ 0.0,0.0,99.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S4(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,104.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S5(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S6(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S7(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,123.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,129.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,157.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E27_ptr = AperStop0_E27.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 106.505, 103.124, 101.056 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E27";
	std::string nameStartSys = "startSys_E27_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.870673);
	tarCarP.setTargetMag(-0.641234);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E28 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E28(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 22.0;


	SphericalElement S0(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
	SphericalElement S1(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,142.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());

	SphericalElement S2(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,152.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S3(/*radius*/ 300.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,160.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S4(/*radius*/ 300.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,172.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	ApertureStopElement S5(/* semi height*/ 9.0, /*point*/{ 0.0,0.0,177.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S6(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,182.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
	SphericalElement S7(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,200.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNBK10_S1());
	SphericalElement S8(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,208.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,235.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S1.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S4.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E28_ptr = AperStop0_E28.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 108.748, 125.336, 141.370 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E28";
	std::string nameStartSys = "startSys_E28_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.396194);
	tarCarP.setTargetMag(-0.427578);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E29 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E29(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 15.0;


	SphericalElement S0(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK10_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S1(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,69.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK10_S1(), /*refractive index B*/mGlasses.getNF2_S1());
	SphericalElement S2(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNF2_S1());

	SphericalElement S3(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,83.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK34_S1());
	SphericalElement S4(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,91.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNLAK34_S1());
	SphericalElement S5(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,99.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	ApertureStopElement S6(/* semi height*/ 9.0, /*point*/{ 0.0,0.0,104.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S7(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,107.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK34_S1());
	SphericalElement S8(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,119.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK34_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,149.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E29_ptr = AperStop0_E29.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 154.393, 162.186, 170.542 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E29";
	std::string nameStartSys = "startSys_E29_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.011419);
	tarCarP.setTargetMag(-0.486022);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E30 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E30(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 20.0;


	SphericalElement S0(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
	SphericalElement S1(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF4_S1(), /*refractive index B*/mGlasses.getNBK10_S1());
	SphericalElement S2(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF4_S1());

	SphericalElement S3(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());

	ApertureStopElement S5(/* semi height*/ 9.0, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S6(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
	SphericalElement S7(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNBK10_S1());
	SphericalElement S8(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,159.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S4.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E30_ptr = AperStop0_E30.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 181.437, 206.161, 230.575 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E30";
	std::string nameStartSys = "startSys_E30_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(1.946532);
	tarCarP.setTargetMag(-0.567716);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E31 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E31(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 12.0;


	SphericalElement S0(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());
	SphericalElement S1(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());

	SphericalElement S2(/*radius*/ 160.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S4(/*radius*/ 180.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	ApertureStopElement S5(/* semi height*/ 6.0, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S6(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S7(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF56_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S8(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,137.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S1.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S4.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E31_ptr = AperStop0_E31.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 152.639, 188.000, 226.734 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E31";
	std::string nameStartSys = "startSys_E31_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.847378);
	tarCarP.setTargetMag(-0.763727);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E32 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E32(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 12.0;


	SphericalElement S0(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S1(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAF34_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S2(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF34_S1());

	SphericalElement S3(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,95.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S4(/*radius*/ 110.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF64_S1(), /*refractive index B*/mGlasses.getNSSK8_S1());
	SphericalElement S5(/*radius*/ 110.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());

	ApertureStopElement S6(/* semi height*/ 7.0, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S7(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF44_S1());
	SphericalElement S8(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF44_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,162.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E32_ptr = AperStop0_E32.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 115.803, 122.684, 129.801 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E32";
	std::string nameStartSys = "startSys_E32_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(2.279197);
	tarCarP.setTargetMag(-0.466589);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E33 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E33(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 16.0;


	SphericalElement S0(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S1(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBASF2_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S2(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,76.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBASF2_S1());

	SphericalElement S3(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,81.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S4(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,87.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());

	ApertureStopElement S5(/* semi height*/ 4.5, /*point*/{ 0.0,0.0,92.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S6(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,97.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S7(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBASF64_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S8(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,111.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBASF64_S1());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,140.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S8.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S4.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S8.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E33_ptr = AperStop0_E33.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 116.313, 125.924, 135.988 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E33";
	std::string nameStartSys = "startSys_E33_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(3.903749);
	tarCarP.setTargetMag(-0.657356);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E34 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E34(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 26.0;


	SphericalElement S0(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF2_S1());
	SphericalElement S1(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,110.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF2_S1());

	SphericalElement S2(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S4(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S5(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,160.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF2_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S7(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,170.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF2_S1());

	ApertureStopElement S8(/* semi height*/ 2.0, /*point*/{ 0.0,0.0,175.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,200.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S1.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S4.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S7.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E34_ptr = AperStop0_E34.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 60.838, 80.991, 100.264 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E34";
	std::string nameStartSys = "startSys_E34_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(6.112247);
	tarCarP.setTargetMag(-0.513644);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E35 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E35(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 22.0;


	SphericalElement S0(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSK10_S1());
	SphericalElement S1(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,62.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSK10_S1());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S3(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S4(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,93.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF11_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 250.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,103.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S6(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,113.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSK10_S1());
	SphericalElement S7(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,133.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSK10_S1());

	ApertureStopElement S8(/* semi height*/ 1.5, /*point*/{ 0.0,0.0,143.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,171.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S7.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E35_ptr = AperStop0_E35.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 34.698, 44.286, 77.731 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E35";
	std::string nameStartSys = "startSys_E35_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(9.626548);
	tarCarP.setTargetMag(-0.814556);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E36 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E36(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 14.0;


	SphericalElement S0(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF3_S1());
	SphericalElement S1(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF3_S1());

	SphericalElement S2(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S3(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,82.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK9_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S4(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,90.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK9_S1());

	SphericalElement S5(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S6(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,112.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF3_S1(), /*refractive index B*/mGlasses.getNSF64_S1());
	SphericalElement S7(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF3_S1());

	ApertureStopElement S8(/* semi height*/ 2.0, /*point*/{ 0.0,0.0,132.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,155.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S1.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S4.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S7.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E36_ptr = AperStop0_E36.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 121.802, 155.802, 234.192 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E36";
	std::string nameStartSys = "startSys_E36_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(6.248689);
	tarCarP.setTargetMag(-0.959624);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E37 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E37(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 28.0;


	SphericalElement S0(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF40_S1());
	SphericalElement S1(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,115.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNLASF40_S1());
	SphericalElement S2(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,125.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S3(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,140.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAK8_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S4(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNLAK8_S1(), /*refractive index B*/mGlasses.getNSF11_S1());
	SphericalElement S5(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,165.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF11_S1());

	SphericalElement S6(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,180.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S7(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,195.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	ApertureStopElement S8(/* semi height*/ 1.0, /*point*/{ 0.0,0.0,210.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,225.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S7.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E37_ptr = AperStop0_E37.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 103.878, 109.666, 125.336 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E37";
	std::string nameStartSys = "startSys_E37_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(8.770214);
	tarCarP.setTargetMag(-0.504878);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E38 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E38(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 24.0;


	SphericalElement S0(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S1(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,112.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	SphericalElement S3(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF4_S1());
	SphericalElement S4(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,147.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF4_S1());

	SphericalElement S5(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,162.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S6(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,174.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF4_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S7(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,182.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF4_S1());

	ApertureStopElement S8(/* semi height*/ 2.0, /*point*/{ 0.0,0.0,197.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,212.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S4.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S7.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E38_ptr = AperStop0_E38.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 166.644, 155.225, 168.291 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E38";
	std::string nameStartSys = "startSys_E38_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(4.237135);
	tarCarP.setTargetMag(-0.499658);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E39 three lens system
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_E39(std::string example)
{

	std::vector<bool> workTheSystem;
	real semiHeight = 30.0;


	SphericalElement S0(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,100.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK10_S1());
	SphericalElement S1(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,120.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLASF45_S1(), /*refractive index B*/mGlasses.getNBK10_S1());
	SphericalElement S2(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF45_S1());

	SphericalElement S3(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,150.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S4(/*radius*/ 90.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,165.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S5(/*radius*/ 140.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,185.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	SphericalElement S6(/*radius*/ 110.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,200.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF45_S1());
	SphericalElement S7(/*radius*/ 110.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,220.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF45_S1());

	ApertureStopElement S8(/* semi height*/ 1.5, /*point*/{ 0.0,0.0,230.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	PlanElement S9(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,246.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S0.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S7.setParameterPointZ(/*min value*/5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E39_ptr = AperStop0_E39.clone();
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr, S9_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mDoNot.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 61.519, 104.237, 145.900 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/E39";
	std::string nameStartSys = "startSys_E39_THREE_LensSystem";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetWFNO(5.242105);
	tarCarP.setTargetMag(-0.441491);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}


// *** inf ***
// super fct
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_superFct_inf()
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

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/infinity";
	std::string name = "testLensReplaceAndOptimize_statistic_threeLensSystem_inf";

	// EX
	bool checkEX_inf = testLRaO_stat_THREE_LensSystem_EX_inf("EX");
	workTheSystem.push_back(checkEX_inf);
	if (checkEX_inf) { inportExportData::saveStringInTXT_includingTime(location, name, "EX worked"); };




	// export all data
	exportAllStatisticDataReplace_THREE_LensesGeneticAndDLS_12();


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// EX
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_LensSystem_EX_inf(std::string example)
{
	std::vector<bool> workTheSystem;

	real semiHeight = 10.0;
	mGlasses.loadGlassCatalog_Schott();

	ApertureStopElement S0(/* semi height*/2.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S3(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK10_S1());
	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF6_S1(), /*refractive index B*/mGlasses.getNLAK10_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());

	SphericalElement S6(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S7(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	PlanElement S8(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,65.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S6.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S7.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S7.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
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

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr, S7_ptr, S8_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone() , mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 188.611, 178.372, 168.558 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mFieldAngle_Vec_X, mFieldAngle_Vec_Y, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems/infinity/EX";
	std::string nameStartSys = "startSys_EX_inf";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetEFL(32.0);
	tarCarP.setTargetWFNO(8.0);

	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_inf(optSystemElement, tarCarP, location, example));
	// alternativ kannst du hier die Funktion doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf verwenden.

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// *** ***
