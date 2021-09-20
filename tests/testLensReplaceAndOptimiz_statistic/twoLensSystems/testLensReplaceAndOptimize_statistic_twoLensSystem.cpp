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

// do the statistic evaluation
std::vector<saveLRaO_statistic> testLensReplaceAndOptimize_statistic_twoLensSystem::doTheStatisticEvaluation(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example)
{
	unsigned int numberLenses = oftenUse::findLensesInOptSysEle(optSysEle).size();
	std::vector<saveLRaO_statistic> LRaO_statistic(numberLenses);
	LRaO_statistic.resize(5);

	for (unsigned int k = 0; k < LRaO_statistic.size(); ++k)
	{
		LRaO_statistic[k].setNumberOfLensesInOptSys(numberLenses);
		LRaO_statistic[k].resizeBestLensNumberWasTaken(numberLenses);
		LRaO_statistic[k].setExample(example);
	}

	std::vector<replaceSequence> repSeq_vec = { replaceSequence::leftToRight, replaceSequence::RightToLeft, replaceSequence::maxSeidelAberLens, replaceSequence::minSeidelAberLens, replaceSequence::allPossibleSequences };
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
	std::vector<std::string> nameLoc = { "/leftToRight", "/rightToLeft", "/maxSeidel", "/minSeidel", "/allSequences" };
	std::string tempLocation{};

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

bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_superFct()
{
	std::vector<bool> workTheSystem;

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


	// E0
	bool checkE0 = testLRaO_stat_twoLensSystem_E0("E0");
	workTheSystem.push_back(checkE0);
	if (checkE0) { inportExportData::saveStringInTXT_includingTime(location, name, "E0 worked"); };

	//// E1
	//bool checkE1 = testLRaO_stat_twoLensSystem_E1("E1");
	//workTheSystem.push_back(checkE1);
	//if (checkE1) { inportExportData::saveStringInTXT_includingTime(location, name, "E1 worked"); };
	//
	// E2
	bool checkE2 = testLRaO_stat_twoLensSystem_E2("E2");
	workTheSystem.push_back(checkE2);
	if (checkE2) { inportExportData::saveStringInTXT_includingTime(location, name, "E2 worked"); };

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
	bool checkE8 = testLRaO_stat_twoLensSystem_E8("E8");
	workTheSystem.push_back(checkE8);
	if (checkE8) { inportExportData::saveStringInTXT_includingTime(location, name, "E8 worked"); };


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
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S3.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
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
	tarCarP.setTargetEFL(27.2521);
	tarCarP.setTargetMag(-1.1021);
	tarCarP.setTargetWFNO(-10.9248);

	mSaveAllResults.push_back(doTheStatisticEvaluation(optSystemElement, tarCarP, location, example));


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
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S5.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
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
	tarCarP.setTargetEFL(18.9133);
	tarCarP.setTargetMag(-0.5107);
	tarCarP.setTargetWFNO(-4.8751);

	mSaveAllResults.push_back(doTheStatisticEvaluation(optSystemElement, tarCarP, location, example));


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
	S2.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
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
	tarCarP.setTargetEFL(21.7377);
	tarCarP.setTargetMag(-0.7499);
	tarCarP.setTargetWFNO(-7.4767);

	mSaveAllResults.push_back(doTheStatisticEvaluation(optSystemElement, tarCarP, location, example));


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
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S2.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
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
	tarCarP.setTargetEFL(24.7922);
	tarCarP.setTargetMag(-0.8089);
	tarCarP.setTargetWFNO(-8.0247);

	mSaveAllResults.push_back(doTheStatisticEvaluation(optSystemElement, tarCarP, location, example));


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
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
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
	tarCarP.setTargetEFL(21.3089);
	tarCarP.setTargetMag(-0.5474);
	tarCarP.setTargetWFNO(-5.2672);

	mSaveAllResults.push_back(doTheStatisticEvaluation(optSystemElement, tarCarP, location, example));


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
	S1.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S3.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
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
	tarCarP.setTargetEFL(29.4231);
	tarCarP.setTargetMag(-1.0569);
	tarCarP.setTargetWFNO(-10.4887);

	mSaveAllResults.push_back(doTheStatisticEvaluation(optSystemElement, tarCarP, location, example));


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
	S1.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
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
	tarCarP.setTargetEFL(25.9264);
	tarCarP.setTargetMag(-0.6906);
	tarCarP.setTargetWFNO(-6.7572);

	mSaveAllResults.push_back(doTheStatisticEvaluation(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E7
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E7(std::string example)
{
	std::vector<bool> workTheSystem;
	real semiHeight = 5.0;

	ApertureStopElement S0(/* semi height*/1.5, /*point*/{ 0.0,0.0,30.0 }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index*/ mGlasses.getAir());

	SphericalElement S1(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,40.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S2(/*radius*/ 40.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,45.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getNSSK8_S1(), /*refractive index B*/mGlasses.getNBK7_S1());
	SphericalElement S3(/*radius*/ 30.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,50.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSSK8_S1());

	SphericalElement S4(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,55.0 }, /*direction*/{ 0.0,0.0, 1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());
	SphericalElement S5(/*radius*/ 50.0, /*semi height*/ semiHeight, /*point*/{ 0.0,0.0,60.0 }, /*direction*/{ 0.0,0.0, -1.0 }, /*refractive index A*/ mGlasses.getAir(), /*refractive index B*/mGlasses.getNSF5_S1());

	PlanElement S6(/*semi height*/ 99.0, /*point*/{ 0.0,0.0,90.0 },  /*direction*/{ 0.0,0.0,1.0 }, /*refractiv index A*/ mGlasses.getAir(), /*refractive index B*/ mGlasses.getAir());

	// **********************************
	// set parameter variable
	S1.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S2.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
	S4.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
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
	std::vector<real> rms_Zemax{ 319.055, 341.903, 364.501 };
	bool testSystem = oftenUse::checkOptSysELement_Equal_Better_Zemax(optSystemElement, mField_vec, mWavelength_FdV_vec, rms_Zemax, mTolerance, compareTOM_Zemax::comEqual);
	workTheSystem.push_back(testSystem);

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/twoLensSystems/E7";
	std::string nameStartSys = "startSys_E7";
	inportExportData::saveOpticalSystemAsTXT(optSystemElement, mWave587d, location, nameStartSys);

	// set target cardinal points
	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetEFL(19.5122);
	tarCarP.setTargetMag(-0.6695);
	tarCarP.setTargetWFNO(-6.6614);

	mSaveAllResults.push_back(doTheStatisticEvaluation(optSystemElement, tarCarP, location, example));


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
	S4.setParameterPointZ(/*min value*/ 0.0, /*max value*/ 20.0, 0.0, typeModifierVariable);
	S5.setParameterRadius(/*min value*/ -1000.0, /*max value*/ 1000.0, 0.0, typeModifierVariable);
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
	tarCarP.setTargetEFL(19.8693);
	tarCarP.setTargetMag(-0.6664);
	tarCarP.setTargetWFNO(-6.6259);

	mSaveAllResults.push_back(doTheStatisticEvaluation(optSystemElement, tarCarP, location, example));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}


