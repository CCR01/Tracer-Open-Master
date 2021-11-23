#include "testLensReplaceAndOptimize_statistic_twoLensSystem.h"

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


typedef std::shared_ptr< Element_CR > surfacePtr;
typedef std::shared_ptr<InteractionRay_LLT> interaction_ptr;



testLensReplaceAndOptimize_statistic_twoLensSystem::testLensReplaceAndOptimize_statistic_twoLensSystem()
{
	turn_OFF_debugMode();
	loadImportantParameter();
}
testLensReplaceAndOptimize_statistic_twoLensSystem::~testLensReplaceAndOptimize_statistic_twoLensSystem() {}


// load importent parameter
void testLensReplaceAndOptimize_statistic_twoLensSystem::loadImportantParameter()
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
void testLensReplaceAndOptimize_statistic_twoLensSystem::turn_ON_debugMode()
{
	mDebugMode = true;
}
void testLensReplaceAndOptimize_statistic_twoLensSystem::turn_OFF_debugMode()
{
	mDebugMode = false;
}
// export all statistic data replace two lenses
void testLensReplaceAndOptimize_statistic_twoLensSystem::exportAllStatisticDataReplaceTwoLenses()
{
	std::string dataToExportString = "merit_DLS, duration_DLS, replaceSequence_DLS, bestLensNumber_DLS3, merit_DLS_12, duration_DLS_12, replaceSequence_DLS_12, bestLensNumber_DLS_12, merit_GeneticAndDLS, duration_GeneticAndDLS, replaceSequence_GeneticAndDLS, bestLensNumber_GeneticAndDLS, merit_GeneticAndDLS_12, duration_GeneticAndDLS_12, replaceSequence_GeneticAndDLS_12, bestLensNumber_GeneticAndDLS_12 ";
	std::vector<real> dataToExport_vec;
	dataToExport_vec.resize(24);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems";
	std::string nameExcel = "data_twoLensSystems";
	//inportExportData::removeDateCSV(location, nameExcel);

	for (unsigned int i = 0; i < mSaveAllResults.size(); i++)
	{
		inportExportData::exportDataToExcel_makeOneRowSpace(location, nameExcel);
		inportExportData::exportDataToExcel_name(location, nameExcel, mSaveAllResults[i][0].getExample());


		for (unsigned int k = 0; k < mSaveAllResults[0].size(); k++)
		{

			// DLS
			dataToExport_vec[0] = mSaveAllResults[i][k].getMeritVaL_DLS();
			dataToExport_vec[1] = mSaveAllResults[i][k].getDurationTime_DLS();

			dataToExport_vec[2] = mSaveAllResults[i][k].getReplacedSequence(optimizeMethode::DLS)[0];
			dataToExport_vec[3] = mSaveAllResults[i][k].getReplacedSequence(optimizeMethode::DLS)[1];

			dataToExport_vec[4] = mSaveAllResults[i][k].getBestLensNumberWasTaken(optimizeMethode::DLS)[0];
			dataToExport_vec[5] = mSaveAllResults[i][k].getBestLensNumberWasTaken(optimizeMethode::DLS)[1];

			// DLS_12
			dataToExport_vec[6] = mSaveAllResults[i][k].getMeritVal_DLS_12();
			dataToExport_vec[7] = mSaveAllResults[i][k].getDurationTime_DLS_12();

			dataToExport_vec[8] = mSaveAllResults[i][k].getReplacedSequence(optimizeMethode::DLS_12)[0];
			dataToExport_vec[9] = mSaveAllResults[i][k].getReplacedSequence(optimizeMethode::DLS_12)[1];

			dataToExport_vec[10] = mSaveAllResults[i][k].getBestLensNumberWasTaken(optimizeMethode::DLS_12)[0];
			dataToExport_vec[11] = mSaveAllResults[i][k].getBestLensNumberWasTaken(optimizeMethode::DLS_12)[1];

			// GeneticAndDLS
			dataToExport_vec[12] = mSaveAllResults[i][k].getMeritVaL_GeneticAndDLS();
			dataToExport_vec[13] = mSaveAllResults[i][k].getDurationTime_GeneticAndDLS();

			dataToExport_vec[14] = mSaveAllResults[i][k].getReplacedSequence(optimizeMethode::GeneticAndDLS)[0];
			dataToExport_vec[15] = mSaveAllResults[i][k].getReplacedSequence(optimizeMethode::GeneticAndDLS)[1];

			dataToExport_vec[16] = mSaveAllResults[i][k].getBestLensNumberWasTaken(optimizeMethode::GeneticAndDLS)[0];
			dataToExport_vec[17] = mSaveAllResults[i][k].getBestLensNumberWasTaken(optimizeMethode::GeneticAndDLS)[1];

			// GeneticAndDLS_12
			dataToExport_vec[18] = mSaveAllResults[i][k].getMeritVaL_GeneticAndDLS_12();
			dataToExport_vec[19] = mSaveAllResults[i][k].getDurationTime_GeneticAndDLS_12();

			dataToExport_vec[20] = mSaveAllResults[i][k].getReplacedSequence(optimizeMethode::GeneticAndDLS_12)[0];
			dataToExport_vec[21] = mSaveAllResults[i][k].getReplacedSequence(optimizeMethode::GeneticAndDLS_12)[1];

			dataToExport_vec[22] = mSaveAllResults[i][k].getBestLensNumberWasTaken(optimizeMethode::GeneticAndDLS_12)[0];
			dataToExport_vec[23] = mSaveAllResults[i][k].getBestLensNumberWasTaken(optimizeMethode::GeneticAndDLS_12)[1];



			inportExportData::exportDataToExcel_vector(location, nameExcel, dataToExportString, dataToExport_vec);

		}


	}

}

// export all statistic data replace three lenses
void testLensReplaceAndOptimize_statistic_twoLensSystem::exportAllStatisticDataReplace_TWO_LensesGeneticAndDLS_12()
{
	std::string dataToExportString = "merit_GeneticAndDLS_12, duration_GeneticAndDLS_12, replaceSequence_GeneticAndDLS_12, bestLensNumber_GeneticAndDLS_12 ";
	std::vector<real> dataToExport_vec;
	dataToExport_vec.resize(6);

	std::string location{};
	if (mObj)
	{
		location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems";
	}
	else if (mInf)
	{
		location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/infinity";
	}


	std::string nameExcel = "data_twoLensSystems";
	//inportExportData::removeDateCSV(location, nameExcel);

	for (unsigned int i = 0; i < mSaveAllResults_TWO_LensSystem.size(); i++)
	{
		inportExportData::exportDataToExcel_makeOneRowSpace(location, nameExcel);
		inportExportData::exportDataToExcel_name(location, nameExcel, mSaveAllResults_TWO_LensSystem[i][0].getExample());


		for (unsigned int k = 0; k < mSaveAllResults_TWO_LensSystem[0].size(); k++)
		{

			// Genetic and DLS 12 -> three lens system
			dataToExport_vec[0] = mSaveAllResults_TWO_LensSystem[i][k].getMeritVaL_GeneticAndDLS_12();
			dataToExport_vec[1] = mSaveAllResults_TWO_LensSystem[i][k].getDurationTime_GeneticAndDLS_12();

			dataToExport_vec[2] = mSaveAllResults_TWO_LensSystem[i][k].getReplacedSequence_GeneticAndDLS12()[0];
			dataToExport_vec[3] = mSaveAllResults_TWO_LensSystem[i][k].getReplacedSequence_GeneticAndDLS12()[1];

			dataToExport_vec[5] = mSaveAllResults_TWO_LensSystem[i][k].getBestLensNumberWasTaken()[0];
			dataToExport_vec[6] = mSaveAllResults_TWO_LensSystem[i][k].getBestLensNumberWasTaken()[1];


			inportExportData::exportDataToExcel_vector(location, nameExcel, dataToExportString, dataToExport_vec);

		}


	}

}

// do the statistic evaluation
std::vector<saveLRaO_statistic> testLensReplaceAndOptimize_statistic_twoLensSystem::doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example)
{
	unsigned int numberLenses = oftenUse::findLensesInOptSysEle(optSysEle).size();
	std::vector<saveLRaO_statistic> LRaO_statistic(numberLenses);
	LRaO_statistic.resize(4);

	for (unsigned int k = 0; k < LRaO_statistic.size(); ++k)
	{
		LRaO_statistic[k].setNumberOfLensesInOptSys(numberLenses);
		LRaO_statistic[k].resizeBestLensNumberWasTaken(numberLenses);
		LRaO_statistic[k].setExample(example);
	}

	std::vector<replaceSequence> repSeq_vec = { replaceSequence::leftToRight, replaceSequence::RightToLeft, replaceSequence::maxSeidelAberLens, replaceSequence::minSeidelAberLens }; // , replaceSequence::allPossibleSequences};

	std::vector<optimizeMethode> optiMeth_vec{ optimizeMethode::DLS, optimizeMethode::DLS_12, optimizeMethode::GeneticAndDLS, optimizeMethode::GeneticAndDLS_12 };

	OpticalSystemElement tempOptSysEle_initial;
	replaceSequence tempReplaceSequence;
	optimizeMethode tempOptiMethode;
	Light_LLT light = oftenUse::getDefaultLight();
	real tempBestMeritVal{};
	std::vector<unsigned int> temUsedReplaceSeq{};
	std::vector<OptSysEle_Merit_LensType> tempOptSysMeritLensType;

	std::vector<std::string> nameVec = { "DLS", "DLS_12", "GeneticAndDLS", "GeneticAndDLS_12" };
	std::string tempName{};
	std::vector<std::string> nameLoc = { "/leftToRight", "/rightToLeft", "/maxSeidel", "/minSeidel" };// , "/allSequences"};
	std::string tempLocation{};
	std::vector<std::string> nameSequences = { "leftToRight", "rightToLeft", "maxSeidel", "minSeidel" }; // , "allSequences" };

	for (unsigned int posRepSeq = 0; posRepSeq < repSeq_vec.size(); ++posRepSeq)
	{
		tempReplaceSequence = repSeq_vec[posRepSeq];
		tempLocation = location + nameLoc[posRepSeq];

		for (unsigned int posOptiMeth = 0; posOptiMeth < optiMeth_vec.size(); ++posOptiMeth)
		{
			tempOptSysEle_initial = optSysEle.getDeepCopyOptSysEle();
			tempOptiMethode = optiMeth_vec[posOptiMeth];

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

			testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(tempOptSysEle_initial, mField_vec, mWavelength_FdV_vec, mRings, mArms, tempOptiMethode, /*number best fit lenses*/ mNumberBestFitLenses, true, tempReplaceSequence, light);

			// end time
			auto tempEndTime = std::chrono::high_resolution_clock::now();

			OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();

			std::chrono::duration<double> totalDuration_secondes = tempEndTime - tempStartTime;
			tempBestMeritVal = testLensReplaceAndOptiSuperFct.getBestMeritVal();
			temUsedReplaceSeq = testLensReplaceAndOptiSuperFct.getReplacedSequence();
			tempOptSysMeritLensType = testLensReplaceAndOptiSuperFct.getBestCatalogLensesForreplace();

			tempName = nameVec[posOptiMeth];
			testLensReplaceAndOptiSuperFct.exportBestParameterCatalogForReplaceTXT(tempLocation, tempName);

			std::string nameOptSys = "replacedOptSys_";
			std::string totalNameOptSys = nameOptSys + tempName;
			inportExportData::saveOpticalSystemAsTXT(optSysEle_lensRepSuperFct, 550.0, tempLocation, totalNameOptSys);

			// export rms values
			std::vector<std::string> nameDoubel_vec = { "field_0", "field_283", "field_4" };
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

			if (tempOptiMethode == optimizeMethode::DLS)
			{
				LRaO_statistic[posRepSeq].setMeritVal_DLS(tempBestMeritVal);
				LRaO_statistic[posRepSeq].setDurationTime_DLS(totalDuration_secondes.count());
				LRaO_statistic[posRepSeq].setReplaceSequence(tempOptiMethode, temUsedReplaceSeq);
				LRaO_statistic[posRepSeq].setBestLensNumberWasTaken(tempOptiMethode, tempBestLensWasTaken);


			}

			else if (tempOptiMethode == optimizeMethode::DLS_12)
			{
				LRaO_statistic[posRepSeq].setMeritVal_DLS_12(tempBestMeritVal);
				LRaO_statistic[posRepSeq].setDurationTime_DLS_12(totalDuration_secondes.count());
				LRaO_statistic[posRepSeq].setReplaceSequence(tempOptiMethode, temUsedReplaceSeq);
				LRaO_statistic[posRepSeq].setBestLensNumberWasTaken(tempOptiMethode, tempBestLensWasTaken);
			}

			else if (tempOptiMethode == optimizeMethode::GeneticAndDLS)
			{
				LRaO_statistic[posRepSeq].setMeritVal_GeneticAndDLS(tempBestMeritVal);
				LRaO_statistic[posRepSeq].setDurationTime_GeneticAndDLS(totalDuration_secondes.count());
				LRaO_statistic[posRepSeq].setReplaceSequence(tempOptiMethode, temUsedReplaceSeq);
				LRaO_statistic[posRepSeq].setBestLensNumberWasTaken(tempOptiMethode, tempBestLensWasTaken);

			}

			else if (tempOptiMethode == optimizeMethode::GeneticAndDLS_12)
			{
				LRaO_statistic[posRepSeq].setMeritVal_GeneticAndDLS_12(tempBestMeritVal);
				LRaO_statistic[posRepSeq].setDurationTime_GeneticAndDLS_12(totalDuration_secondes.count());
				LRaO_statistic[posRepSeq].setReplaceSequence(tempOptiMethode, temUsedReplaceSeq);
				LRaO_statistic[posRepSeq].setBestLensNumberWasTaken(tempOptiMethode, tempBestLensWasTaken);

			}



		}
	}

	return LRaO_statistic;
}


std::vector<saveLRaO_GeneticAndDLS_12_statistic> testLensReplaceAndOptimize_statistic_twoLensSystem::doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example)
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

	std::vector<replaceSequence> repSeq_vec = { replaceSequence::leftToRight, replaceSequence::RightToLeft, replaceSequence::maxSeidelAberLens, replaceSequence::minSeidelAberLens }; // , replaceSequence::allPossibleSequences};

	OpticalSystemElement tempOptSysEle_initial;
	replaceSequence tempReplaceSequence;
	optimizeMethode optiMethode = optimizeMethode::GeneticAndDLS_12;
	Light_LLT light = oftenUse::getDefaultLight();
	real tempBestMeritVal{};
	std::vector<unsigned int> temUsedReplaceSeq{};
	std::vector<OptSysEle_Merit_LensType> tempOptSysMeritLensType;

	std::string nameOptimizationMethode = "GeneticAndDLS_12";
	std::vector<std::string> nameLoc = { "/leftToRight", "/rightToLeft", "/maxSeidel", "/minSeidel" }; //, "/allSequences"};
	std::vector<std::string> nameSequences = { "leftToRight", "rightToLeft", "maxSeidel", "minSeidel" }; //, "allSequences"};
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

bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_superFct_obj()
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

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems";
	std::string name = "testLensReplaceAndOptimize_statistic_twoLensSystem";


	//// E0
	//bool checkE0 = testLRaO_stat_twoLensSystem_E0("E0");
	//workTheSystem.push_back(checkE0);
	//if (checkE0) { inportExportData::saveStringInTXT_includingTime(location, name, "E0 worked"); };
	//
	//// E1
	//bool checkE1 = testLRaO_stat_twoLensSystem_E1("E1");
	//workTheSystem.push_back(checkE1);
	//if (checkE1) { inportExportData::saveStringInTXT_includingTime(location, name, "E1 worked"); };
	//
	//// E2
	//bool checkE2 = testLRaO_stat_twoLensSystem_E2("E2");
	//workTheSystem.push_back(checkE2);
	//if (checkE2) { inportExportData::saveStringInTXT_includingTime(location, name, "E2 worked"); };
	//
	//// E3
	//bool checkE3 = testLRaO_stat_twoLensSystem_E3("E3");
	//workTheSystem.push_back(checkE3);
	//if (checkE3) { inportExportData::saveStringInTXT_includingTime(location, name, "E3 worked"); };
	//
	//// E4
	//bool checkE4 = testLRaO_stat_twoLensSystem_E4("E4");
	//workTheSystem.push_back(checkE4);
	//if (checkE4) { inportExportData::saveStringInTXT_includingTime(location, name, "E4 worked"); };
	//
	//// E5
	//bool checkE5 = testLRaO_stat_twoLensSystem_E5("E5");
	//workTheSystem.push_back(checkE5);
	//if (checkE5) { inportExportData::saveStringInTXT_includingTime(location, name, "E5 worked"); };
	//
	//// E6
	//bool checkE6 = testLRaO_stat_twoLensSystem_E6("E6");
	//workTheSystem.push_back(checkE6);
	//if (checkE6) { inportExportData::saveStringInTXT_includingTime(location, name, "E6 worked"); };
	//
	//// E7
	//bool checkE7 = testLRaO_stat_twoLensSystem_E7("E7");
	//workTheSystem.push_back(checkE7);
	//if (checkE7) { inportExportData::saveStringInTXT_includingTime(location, name, "E7 worked"); };
	//
	//// E8
	//bool checkE8 = testLRaO_stat_twoLensSystem_E8("E8");
	//workTheSystem.push_back(checkE8);
	//if (checkE8) { inportExportData::saveStringInTXT_includingTime(location, name, "E8 worked"); };
	//
	//// E9
	//bool checkE9 = testLRaO_stat_twoLensSystem_E9("E9");
	//workTheSystem.push_back(checkE9);
	//if (checkE9) { inportExportData::saveStringInTXT_includingTime(location, name, "E9 worked"); };
	//
	//// E10
	//bool checkE10 = testLRaO_stat_twoLensSystem_E10("E10");
	//workTheSystem.push_back(checkE10);
	//if (checkE10) { inportExportData::saveStringInTXT_includingTime(location, name, "E10 worked"); };
	//
	//// E11
	//bool checkE11 = testLRaO_stat_twoLensSystem_E11("E11");
	//workTheSystem.push_back(checkE11);
	//if (checkE11) { inportExportData::saveStringInTXT_includingTime(location, name, "E11 worked"); };
	//
	//// E12
	//bool checkE12 = testLRaO_stat_twoLensSystem_E12("E12");
	//workTheSystem.push_back(checkE12);
	//if (checkE12) { inportExportData::saveStringInTXT_includingTime(location, name, "E12 worked"); };
	//
	//// E13
	//bool checkE13 = testLRaO_stat_twoLensSystem_E13("E13");
	//workTheSystem.push_back(checkE13);
	//if (checkE13) { inportExportData::saveStringInTXT_includingTime(location, name, "E13 worked"); };
	//
	//// E14
	//bool checkE14 = testLRaO_stat_twoLensSystem_E14("E14");
	//workTheSystem.push_back(checkE14);
	//if (checkE14) { inportExportData::saveStringInTXT_includingTime(location, name, "E14 worked"); };
	//
	// E15
	bool checkE15 = testLRaO_stat_twoLensSystem_E15("E15");
	workTheSystem.push_back(checkE15);
	if (checkE15) { inportExportData::saveStringInTXT_includingTime(location, name, "E15 worked"); };

	// E16
	bool checkE16 = testLRaO_stat_twoLensSystem_E16("E16");
	workTheSystem.push_back(checkE16);
	if (checkE16) { inportExportData::saveStringInTXT_includingTime(location, name, "E16 worked"); };

	// E17
	bool checkE17 = testLRaO_stat_twoLensSystem_E17("E17");
	workTheSystem.push_back(checkE17);
	if (checkE17) { inportExportData::saveStringInTXT_includingTime(location, name, "E17 worked"); };
	//
	//// E18
	//bool checkE18 = testLRaO_stat_twoLensSystem_E18("E18");
	//workTheSystem.push_back(checkE18);
	//if (checkE18) { inportExportData::saveStringInTXT_includingTime(location, name, "E18 worked"); };
	//
	//// E19
	//bool checkE19 = testLRaO_stat_twoLensSystem_E19("E19");
	//workTheSystem.push_back(checkE19);
	//if (checkE19) { inportExportData::saveStringInTXT_includingTime(location, name, "E19 worked"); };


	exportAllStatisticDataReplaceTwoLenses();

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}

// E0
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E0(std::string example)
{
	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,105.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E0_ptr = AperStop0_E0.clone();
	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 265.870, 233.334,203.340 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/E0";
	std::string nameStartSys = "startSys_E0";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetMag(-1.1021);
	tarCarP.setTargetWFNO(10.9248);

	mSaveAllResults.push_back(doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}

// E1
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E1(std::string example)
{
	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S3(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF5_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S4(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,95.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************


	//surfacePtr Aper0_E1_ptr = AperStop0_E1.clone();
	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 107.227, 383.186, 652.976 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/E1";
	std::string nameStartSys = "startSys_E1";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetMag(-0.5107);
	tarCarP.setTargetWFNO(4.8751);

	mSaveAllResults.push_back(doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E2
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E2(std::string example)
{
	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK10_S1());
	SphericalElement S2(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNLAK10_S1(), /*refractive index B*/mGlasses.getNSF56_S1());
	SphericalElement S3(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());

	SphericalElement S4(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,90.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	//surfacePtr Aper0_E2_ptr = AperStop0_E2.clone();
	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 93.717, 88.431, 85.892 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/E2";
	std::string nameStartSys = "startSys_E2";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetMag(-0.7499);
	tarCarP.setTargetWFNO(7.4767);

	mSaveAllResults.push_back(doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E3
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E3(std::string example)
{
	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());
	SphericalElement S2(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF15_S1(), /*refractive index B*/mGlasses.getNSSK8_S1());
	SphericalElement S3(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF15_S1());

	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF3_S1());
	SphericalElement S5(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF3_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,95.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	//surfacePtr Aper0_E3_ptr = AperStop0_E3.clone();
	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 381.234, 352.898, 325.742 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/E3";
	std::string nameStartSys = "startSys_E3";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetMag(-0.8089);
	tarCarP.setTargetWFNO(8.0247);

	mSaveAllResults.push_back(doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E4
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E4(std::string example)
{
	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF56_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF56_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S3(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S4(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S5(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,100.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	//surfacePtr Aper0_E4_ptr = AperStop0_E4.clone();
	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 378.250, 311.038, 375.205 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/E4";
	std::string nameStartSys = "startSys_E4";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetMag(-0.5474);
	tarCarP.setTargetWFNO(5.2672);

	mSaveAllResults.push_back(doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E5
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E5(std::string example)
{
	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S3(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK10_S1());
	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF6_S1(), /*refractive index B*/mGlasses.getNLAK10_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,100.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	//surfacePtr Aper0_E5_ptr = AperStop0_E5.clone();
	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 835.354, 809.318, 783.669 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/E5";
	std::string nameStartSys = "startSys_E5";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetMag(-1.0569);
	tarCarP.setTargetWFNO(10.4887);

	mSaveAllResults.push_back(doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E6
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E6(std::string example)
{
	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S3(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBAF10_S1());
	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBAF10_S1(), /*refractive index B*/mGlasses.getNSF56_S1());
	SphericalElement S5(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,105.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	//surfacePtr Aper0_E6_ptr = AperStop0_E6.clone();
	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 850.568, 777.766, 708.123 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/E6";
	std::string nameStartSys = "startSys_E6";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetMag(-0.6906);
	tarCarP.setTargetWFNO(6.7572);

	mSaveAllResults.push_back(doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E7
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E7(std::string example)
{
	std::vector<bool> workTheSystem;
	real semiHeight = 8.0;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSSK8_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());

	SphericalElement S4(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S5(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,85.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	//surfacePtr Aper0_E7_ptr = AperStop0_E7.clone();
	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 39.020, 64.683, 87.244 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/E7";
	std::string nameStartSys = "startSys_E7";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetMag(-0.669529);
	tarCarP.setTargetWFNO(6.66139);

	mSaveAllResults.push_back(doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E8
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E8(std::string example)
{
	std::vector<bool> workTheSystem;
	real semiHeight = 5.0;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNF2_S1());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNF2_S1(), /*refractive index B*/mGlasses.getNLASF9_S1());
	SphericalElement S3(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF9_S1());

	SphericalElement S4(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,90.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	//surfacePtr Aper0_E8_ptr = AperStop0_E8.clone();
	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 184.571, 212.856, 240.773 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/E8";
	std::string nameStartSys = "startSys_8";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetMag(-0.6664);
	tarCarP.setTargetWFNO(6.6259);

	mSaveAllResults.push_back(doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E9
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E9(std::string example)
{
	std::vector<bool> workTheSystem;
	real semiHeight = 5.0;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNPK52A_S1());
	SphericalElement S2(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNPK52A_S1(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S3(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());

	SphericalElement S4(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S5(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,85.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	//surfacePtr Aper0_E9_ptr = AperStop0_E9.clone();
	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 277.292, 307.055, 336.569 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/E9";
	std::string nameStartSys = "startSys9";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetMag(-0.5421);
	tarCarP.setTargetWFNO(5.3916);

	mSaveAllResults.push_back(doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E10
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E10(std::string example)
{
	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNLAF2_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNLAF2_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S3(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,100.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	//surfacePtr Aper0_E10_ptr = AperStop0_E10.clone();
	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 906.170, 864.730, 824.005 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/E10";
	std::string nameStartSys = "startSys_10";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetMag(-0.7787);
	tarCarP.setTargetWFNO(7.6738);

	mSaveAllResults.push_back(doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E11
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E11(std::string example)
{
	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getBAFN10_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getBAFN10_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S3(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNLAF32_S1());
	SphericalElement S5(/*radius*/ 20.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF32_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,100.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	//surfacePtr Aper0_E11_ptr = AperStop0_E11.clone();
	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 673.002, 544.934, 524.137 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/E11";
	std::string nameStartSys = "startSys_11";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetMag(-0.4567);
	tarCarP.setTargetWFNO(4.3964);

	mSaveAllResults.push_back(doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E12
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E12(std::string example)
{
	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S3(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S4(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF40_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF40_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,95.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	//surfacePtr Aper0_E12_ptr = AperStop0_E12.clone();
	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 592.179, 574.088, 556.379 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/E12";
	std::string nameStartSys = "startSys_12";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetMag(-0.7292);
	tarCarP.setTargetWFNO(7.2654);

	mSaveAllResults.push_back(doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E13
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E13(std::string example)
{
	std::vector<bool> workTheSystem;
	real semiHeight = 10.0;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());
	SphericalElement S2(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF56_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S4(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,100.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	//surfacePtr Aper0_E13_ptr = AperStop0_E13.clone();
	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 36.878, 72.694, 103.430 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/E13";
	std::string nameStartSys = "startSys_13";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetMag(-0.6388);
	tarCarP.setTargetWFNO(6.3660);

	mSaveAllResults.push_back(doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E14
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E14(std::string example)
{
	std::vector<bool> workTheSystem;
	real semiHeight = 7.5;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,47.5 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S3(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,52.5 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S4(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,57.5 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,65.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,95.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	//surfacePtr Aper0_E14_ptr = AperStop0_E14.clone();
	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 240.398, 214.905, 192.135 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/E14";
	std::string nameStartSys = "startSys_14";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetMag(-0.7190);
	tarCarP.setTargetWFNO(7.1315);

	mSaveAllResults.push_back(doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E15
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E15(std::string example)
{
	std::vector<bool> workTheSystem;
	real semiHeight = 7.5;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());
	SphericalElement S2(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,47.5 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSSK8_S1(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S3(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,62.5 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	SphericalElement S4(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,67.5 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF15_S1());
	SphericalElement S5(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF15_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,110.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	//surfacePtr Aper0_E15_ptr = AperStop0_E15.clone();
	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 630.425, 615.119, 600.243 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/E15";
	std::string nameStartSys = "startSys_15";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetMag(-1.0027);
	tarCarP.setTargetWFNO(10.0020);

	mSaveAllResults.push_back(doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E16
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E16(std::string example)
{
	std::vector<bool> workTheSystem;
	real semiHeight = 12.5;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNF2_S1(), /*refractive index B*/mGlasses.getAir());
	SphericalElement S2(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNF2_S1(), /*refractive index B*/mGlasses.getAir());

	SphericalElement S3(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S4(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,62.5 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNSF66_S1());
	SphericalElement S5(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,100.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	//surfacePtr Aper0_E16_ptr = AperStop0_E16.clone();
	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 1677.50, 1618.22, 1556.72 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/E16";
	std::string nameStartSys = "startSys_16";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetMag(-1.0548);
	tarCarP.setTargetWFNO(10.2077);

	mSaveAllResults.push_back(doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E17
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E17(std::string example)
{
	std::vector<bool> workTheSystem;
	real semiHeight = 25.0;

	ApertureStopElement S0(/* semi height*/ 3.0, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S2(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,70.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNBK7_S1(), /*refractive index B*/mGlasses.getNLAF2_S1());
	SphericalElement S3(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,85.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S4(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,105.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,160.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	//surfacePtr Aper0_E17_ptr = AperStop0_E17.clone();
	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 263.921, 230.487, 213.903 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/E17";
	std::string nameStartSys = "startSys_17";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetMag(-0.620976);
	tarCarP.setTargetWFNO(4.09527);

	mSaveAllResults.push_back(doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E18
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E18(std::string example)
{
	std::vector<bool> workTheSystem;
	real semiHeight = 20.0;

	ApertureStopElement S0(/* semi height*/ 2.5, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF56_S1());
	SphericalElement S2(/*radius*/ 100.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,80.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getNSF56_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 60.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,92.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,117.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,135.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,165.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	//surfacePtr Aper0_E18_ptr = AperStop0_E18.clone();
	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 483.666, 420.316, 386.315 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/E18";
	std::string nameStartSys = "startSys_18";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetMag(-0.480992);
	tarCarP.setTargetWFNO(3.79648);

	mSaveAllResults.push_back(doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E19
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E19(std::string example)
{
	std::vector<bool> workTheSystem;
	real semiHeight = 15.0;

	ApertureStopElement S0(/* semi height*/ 2.0, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 120.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,75.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLASF9_S1());
	SphericalElement S2(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,89.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNF2_S1(), /*refractive index B*/mGlasses.getNLASF9_S1());
	SphericalElement S3(/*radius*/ 70.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,99.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNF2_S1());

	SphericalElement S4(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,114.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S5(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,130.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,145.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S3.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	//surfacePtr Aper0_E19_ptr = AperStop0_E19.clone();
	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 338.118, 329.014, 319.941 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/E19";
	std::string nameStartSys = "startSys_19";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetMag(-0.373957);
	tarCarP.setTargetWFNO(5.59049);

	mSaveAllResults.push_back(doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_obj(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}


// *** inf ***
// super fct
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_superFct_inf()
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

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/infinity";
	std::string name = "testLensReplaceAndOptimize_statistic_twoLensSystem_inf";

	// EX
	bool checkEX_inf = testLRaO_stat_twoLensSystem_EX_inf("EX");
	workTheSystem.push_back(checkEX_inf);
	if (checkEX_inf) { inportExportData::saveStringInTXT_includingTime(location, name, "EX worked"); };




	// export all data
	exportAllStatisticDataReplace_TWO_LensesGeneticAndDLS_12();

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}

// EX
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_EX_inf(std::string example)
{
	std::vector<bool> workTheSystem;

	real semiHeight = 10.0;
	mGlasses.loadGlassCatalog_Schott();

	ApertureStopElement S0(/* semi height*/2.0, /*point*/{ 0.0,0.0,0.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 200.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,10.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 150.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,15.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());

	SphericalElement S3(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,25.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNLAK10_S1());
	SphericalElement S4(/*radius*/ 80.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,35.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSF6_S1(), /*refractive index B*/mGlasses.getNLAK10_S1());
	SphericalElement S5(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF6_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,60.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);

	S2.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 5.0, /*max value*/ 30.0, 0.0, typeModifierVariable);
	// **********************************

	//surfacePtr Aper0_E5_ptr = AperStop0_E5.clone();
	surfacePtr S0_ptr = S0.clone();
	surfacePtr S1_ptr = S1.clone();
	surfacePtr S2_ptr = S2.clone();
	surfacePtr S3_ptr = S3.clone();
	surfacePtr S4_ptr = S4.clone();
	surfacePtr S5_ptr = S5.clone();
	surfacePtr S6_ptr = S6.clone();

	std::vector<surfacePtr> opticalSystem_ptr{ S0_ptr, S1_ptr , S2_ptr, S3_ptr, S4_ptr, S5_ptr, S6_ptr };
	std::vector<interaction_ptr> interactions_ptr{ mDoNot.clone(), mRefrac.clone(),mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mRefrac.clone(), mAbsorb.clone() };

	//	build optical system
	OpticalSystemElement optSystemElement(opticalSystem_ptr, interactions_ptr);

	// debug
	oftenUse::print(optSystemElement, 550.0);

	// check the start system
	bool checkRefIndexes = oftenUse::checkRefractivIndex(optSystemElement);
	workTheSystem.push_back(checkRefIndexes);
	std::vector<real> rms_Zemax{ 126.384, 114.546, 104.134 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mFieldAngle_Vec_X, mFieldAngle_Vec_Y, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/infinity/EX";
	std::string nameStartSys = "startSys_EX_inf";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetEFL(30.0);
	tarCarP.setTargetWFNO(7.5);

	mSaveAllResults_TWO_LensSystem.push_back(doTheStatisticEvaluation_TWO_lensSystemGeneticAndDLS_12_LTR_RTL_MaxSei_MinSei_inf(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// *** ***


