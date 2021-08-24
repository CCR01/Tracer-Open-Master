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

saveLRaO_statistic::saveLRaO_statistic(unsigned int numberLensesInOptSys) :
	mNumberOfLensesInOptSys(numberLensesInOptSys)
{
	mNumBestLensWasTaken.resize(mNumberOfLensesInOptSys);
};

saveLRaO_statistic::saveLRaO_statistic() {};

saveLRaO_statistic::~saveLRaO_statistic() {};

void saveLRaO_statistic::setMeritVal_DLS(real meritValDLS)
{
	mMeritVal_DLS = meritValDLS;
}
real saveLRaO_statistic::getMeritVaL_DLS()
{
	return mMeritVal_DLS;
}

void saveLRaO_statistic::setMeritVal_DLS_12(real meritValDLS12)
{
	mMeritVal_DLS_12 = meritValDLS12;
}
real saveLRaO_statistic::getMeritVal_DLS_12()
{
	return mMeritVal_DLS_12;
}
void saveLRaO_statistic::setMeritVal_GeneticAndDLS(real meritValGeneticAndDLS)
{
	mMeritVal_GeneticAndDLS = meritValGeneticAndDLS;
}
real saveLRaO_statistic::getMeritVaL_GeneticAndDLS()
{
	return mMeritVal_GeneticAndDLS;
}
void saveLRaO_statistic::setMeritVal_GeneticAndDLS_12(real meritValGeneticAndDLS12)
{
	mMeritVal_GeneticAndDLS_12 = meritValGeneticAndDLS12;
}
real saveLRaO_statistic::getMeritVaL_GeneticAndDLS_12()
{
	return mMeritVal_GeneticAndDLS_12;
}

void saveLRaO_statistic::setDurationTime_DLS(real DurationTimeDLS)
{
	mDurationTime_DLS = DurationTimeDLS;
}
real saveLRaO_statistic::getDurationTime_DLS()
{
	return mDurationTime_DLS;
}

void saveLRaO_statistic::setDurationTime_DLS_12(real DurationTimeDLS12)
{
	mDurationTime_DLS_12 = DurationTimeDLS12;
}
real saveLRaO_statistic::getDurationTime_DLS_12()
{
	return mDurationTime_DLS_12;
}
void saveLRaO_statistic::setDurationTime_GeneticAndDLS(real DurationTimeGeneticAndDLS)
{
	mDurationTime_GeneticAndDLS = DurationTimeGeneticAndDLS;
}
real saveLRaO_statistic::getDurationTime_GeneticAndDLS()
{
	return mDurationTime_GeneticAndDLS;
}
void saveLRaO_statistic::setDurationTime_GeneticAndDLS_12(real DurationTimeGeneticAndDLS12)
{
	mDurationTime_GeneticAndDLS_12 = DurationTimeGeneticAndDLS12;
}
real saveLRaO_statistic::getDurationTime_GeneticAndDLS_12()
{
	return mDurationTime_GeneticAndDLS_12;
}

// set replace sequence
void saveLRaO_statistic::setReplaceSequence(replaceSequence repSeq_methode, std::vector<unsigned int> repSeq_vec)
{
	if (repSeq_methode == replaceSequence::leftToRight)
	{
		setReplaceSequence_leftToRight(repSeq_vec);
	}

	else if (repSeq_methode == replaceSequence::RightToLeft)
	{
		setReplaceSequence_rightToLeft(repSeq_vec);
	}

	else if (repSeq_methode == replaceSequence::maxSeidelAberLens)
	{
		setReplaceSequence_maxSeidel(repSeq_vec);
	}

	else if (repSeq_methode == replaceSequence::minSeidelAberLens)
	{
		setReplaceSequence_minSeidel(repSeq_vec);
	}

	else if (repSeq_methode == replaceSequence::allPossibleSequences)
	{
		setReplaceSequence_best(repSeq_vec);
	}
}

std::vector<unsigned int> saveLRaO_statistic::getReplacedSequence()
{
	if (mReplaceSequence_leftToRight.size() > 0)
	{
		return mReplaceSequence_leftToRight;
	}

	else if (mReplaceSequence_rightToLeft.size() > 0)
	{
		return mReplaceSequence_rightToLeft;
	}

	else if (mReplaceSequence_maxSeidel.size() > 0)
	{
		return mReplaceSequence_maxSeidel;
	}

	else if (mReplaceSequence_minSeidel.size() > 0)
	{
		return mReplaceSequence_minSeidel;
	}

	else if (mReplaceSequence_best.size() > 0)
	{
		return mReplaceSequence_best;
	}
}

std::vector<unsigned int> saveLRaO_statistic::getReplaceSequence_leftToRight()
{
	return mReplaceSequence_leftToRight;
}

void saveLRaO_statistic::setReplaceSequence_leftToRight(std::vector<unsigned int> repSeq_leftToRight)
{
	mReplaceSequence_leftToRight = repSeq_leftToRight;
}

std::vector<unsigned int> saveLRaO_statistic::getReplaceSequence_rightToLeft()
{
	return mReplaceSequence_rightToLeft;
}
void saveLRaO_statistic::setReplaceSequence_rightToLeft(std::vector<unsigned int> repSeq_rightToLeft)
{
	mReplaceSequence_rightToLeft = repSeq_rightToLeft;
}

std::vector<unsigned int> saveLRaO_statistic::getReplaceSequence_maxSeidel()
{
	return mReplaceSequence_maxSeidel;
}
void saveLRaO_statistic::setReplaceSequence_maxSeidel(std::vector<unsigned int> repSeq_maxSeidel)
{
	mReplaceSequence_maxSeidel = repSeq_maxSeidel;
}
std::vector<unsigned int> saveLRaO_statistic::getReplaceSequence_minSeidel()
{
	return mReplaceSequence_minSeidel;
}
void saveLRaO_statistic::setReplaceSequence_minSeidel(std::vector<unsigned int> repSeq_minSeidel)
{
	mReplaceSequence_minSeidel = repSeq_minSeidel;
}

std::vector<unsigned int> saveLRaO_statistic::getReplaceSequence_best()
{
	return mReplaceSequence_best;
}
void saveLRaO_statistic::setReplaceSequence_best(std::vector<unsigned int> repSeq_best)
{
	mReplaceSequence_best = repSeq_best;
}

void saveLRaO_statistic::calcBestOptimizationMethode()
{
	std::vector<real> allMeritVal;
	allMeritVal.resize(4);

	allMeritVal[0] = getMeritVaL_DLS();
	allMeritVal[1] = getMeritVal_DLS_12();
	allMeritVal[2] = getMeritVaL_GeneticAndDLS();
	allMeritVal[3] = getMeritVaL_GeneticAndDLS_12();

	// find best merit value
	real tempMeritVal = allMeritVal[0];
	real bestMeritVal = oftenUse::getInfReal();
	
	std::vector<optimizeMethode> optiMethode_sequence;
	optiMethode_sequence.resize(4);
	optiMethode_sequence[0] = optimizeMethode::DLS;
	optiMethode_sequence[1] = optimizeMethode::DLS_12;
	optiMethode_sequence[2] = optimizeMethode::GeneticAndDLS;
	optiMethode_sequence[3] = optimizeMethode::GeneticAndDLS_12;

	mOptiMethode_sorted.resize(4);
	int tempBestPosition = 0;
	int counter = 0;
	while (counter < allMeritVal.size())
	{
		for (unsigned int i = 0; i < allMeritVal.size(); ++i)
		{
			if (tempMeritVal < bestMeritVal)
			{
				bestMeritVal = tempMeritVal;
				tempBestPosition = i;
			}

			tempMeritVal = allMeritVal[i];
		}

		mOptiMethode_sorted[counter] = optiMethode_sequence[tempBestPosition];
		
		bestMeritVal = oftenUse::getInfReal();
		allMeritVal[counter] = oftenUse::getInfReal();
		++counter;
	}
		
}

std::vector<optimizeMethode> saveLRaO_statistic::getOptiMethode_sorted()
{
	return mOptiMethode_sorted;
}

std::vector<unsigned int> saveLRaO_statistic::getBestLensNumberWasTaken()
{
	return mNumBestLensWasTaken;
}
void saveLRaO_statistic::setBestLensNumberWasTaken(unsigned int lensNumReplaced, unsigned bestLensNumWasTaken)
{
	mNumBestLensWasTaken[lensNumReplaced] = bestLensNumWasTaken;
}

void saveLRaO_statistic::resizeBestLensNumberWasTaken(unsigned int numberLenses)
{
	mNumBestLensWasTaken.resize(numberLenses);
}

unsigned int saveLRaO_statistic::getNumberOfLensesInOptSys()
{
	return mNumberOfLensesInOptSys;
}
void saveLRaO_statistic::setNumberOfLensesInOptSys(unsigned int numberOfLenses)
{
	mNumberOfLensesInOptSys = numberOfLenses;
}

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
	std::string name = "data_twoLensSystems";
	inportExportData::removeDateCSV(location, name);

	for (unsigned int i = 0; i < mSaveAllResults.size(); i++)
	{
		std::string space = " ";
		std::vector<real> spaceVal{};
		spaceVal.resize(1);
		spaceVal[0] = i;
		inportExportData::exportDataToExcel_vector(location, name, space, spaceVal);

		for (unsigned int k = 0; k < mSaveAllResults[0].size(); k++)
		{

			// DLS
			dataToExport_vec[0] = mSaveAllResults[i][k][0].getMeritVaL_DLS();
			dataToExport_vec[1] = mSaveAllResults[i][k][0].getDurationTime_DLS();

			dataToExport_vec[2] = mSaveAllResults[i][k][0].getReplacedSequence()[0];
			dataToExport_vec[3] = mSaveAllResults[i][k][0].getReplacedSequence()[1];

			dataToExport_vec[4] = mSaveAllResults[i][k][0].getBestLensNumberWasTaken()[0];
			dataToExport_vec[5] = mSaveAllResults[i][k][0].getBestLensNumberWasTaken()[1];

			// DLS_12
			dataToExport_vec[6] = mSaveAllResults[i][k][1].getMeritVal_DLS_12();
			dataToExport_vec[7] = mSaveAllResults[i][k][1].getDurationTime_DLS_12();

			dataToExport_vec[8] = mSaveAllResults[i][k][1].getReplacedSequence()[0];
			dataToExport_vec[9] = mSaveAllResults[i][k][1].getReplacedSequence()[1];

			dataToExport_vec[10] = mSaveAllResults[i][k][1].getBestLensNumberWasTaken()[0];
			dataToExport_vec[11] = mSaveAllResults[i][k][1].getBestLensNumberWasTaken()[1];

			// GeneticAndDLS
			dataToExport_vec[12] = mSaveAllResults[i][k][2].getMeritVaL_GeneticAndDLS();
			dataToExport_vec[13] = mSaveAllResults[i][k][2].getDurationTime_GeneticAndDLS();

			dataToExport_vec[14] = mSaveAllResults[i][k][2].getReplacedSequence()[0];
			dataToExport_vec[15] = mSaveAllResults[i][k][2].getReplacedSequence()[1];

			dataToExport_vec[16] = mSaveAllResults[i][k][2].getBestLensNumberWasTaken()[0];
			dataToExport_vec[17] = mSaveAllResults[i][k][2].getBestLensNumberWasTaken()[1];

			// GeneticAndDLS_12
			dataToExport_vec[18] = mSaveAllResults[i][k][3].getMeritVaL_GeneticAndDLS_12();
			dataToExport_vec[19] = mSaveAllResults[i][k][3].getDurationTime_GeneticAndDLS_12();

			dataToExport_vec[20] = mSaveAllResults[i][k][3].getReplacedSequence()[0];
			dataToExport_vec[21] = mSaveAllResults[i][k][3].getReplacedSequence()[1];

			dataToExport_vec[22] = mSaveAllResults[i][k][3].getBestLensNumberWasTaken()[0];
			dataToExport_vec[23] = mSaveAllResults[i][k][3].getBestLensNumberWasTaken()[1];



			inportExportData::exportDataToExcel_vector(location, name, dataToExportString, dataToExport_vec);
			
		}


	}

}

// do the statistic evaluation
std::vector<std::vector<saveLRaO_statistic>> testLensReplaceAndOptimize_statistic_twoLensSystem::doTheStatisticEvaluation(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location)
{
	unsigned int numberLenses = oftenUse::findLensesInOptSysEle(optSysEle).size();
	std::vector<std::vector<saveLRaO_statistic>> LRaO_statistic(numberLenses);
	LRaO_statistic.resize(5);
	LRaO_statistic[0].resize(4);
	LRaO_statistic[1].resize(4);
	LRaO_statistic[2].resize(4);
	LRaO_statistic[3].resize(4);
	LRaO_statistic[4].resize(4);


	for (unsigned int i = 0; i < LRaO_statistic.size(); ++i)
	{
		for (unsigned int k = 0; k < LRaO_statistic[0].size(); ++k)
		{
			LRaO_statistic[i][k].setNumberOfLensesInOptSys(numberLenses);
			LRaO_statistic[i][k].resizeBestLensNumberWasTaken(numberLenses);
		}
		
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

			if (tempOptiMethode == optimizeMethode::DLS)
			{
				LRaO_statistic[posRepSeq][posOptiMeth].setMeritVal_DLS(tempBestMeritVal);
				LRaO_statistic[posRepSeq][posOptiMeth].setDurationTime_DLS(totalDuration_secondes.count());
				LRaO_statistic[posRepSeq][posOptiMeth].setReplaceSequence(tempReplaceSequence, temUsedReplaceSeq);

				for (unsigned int i = 0; i < tempOptSysMeritLensType.size(); ++i)
				{
					LRaO_statistic[posRepSeq][posOptiMeth].setBestLensNumberWasTaken(i, tempOptSysMeritLensType[i].getPositionInBestMatchLensVec());
				}
				
			}

			else if (tempOptiMethode == optimizeMethode::DLS_12)
			{
				LRaO_statistic[posRepSeq][posOptiMeth].setMeritVal_DLS_12(tempBestMeritVal);
				LRaO_statistic[posRepSeq][posOptiMeth].setDurationTime_DLS_12(totalDuration_secondes.count());
				LRaO_statistic[posRepSeq][posOptiMeth].setReplaceSequence(tempReplaceSequence, temUsedReplaceSeq);

				for (unsigned int i = 0; i < tempOptSysMeritLensType.size(); ++i)
				{
					LRaO_statistic[posRepSeq][posOptiMeth].setBestLensNumberWasTaken(i, tempOptSysMeritLensType[i].getPositionInBestMatchLensVec());
				}

			}

			else if (tempOptiMethode == optimizeMethode::GeneticAndDLS)
			{
				LRaO_statistic[posRepSeq][posOptiMeth].setMeritVal_GeneticAndDLS(tempBestMeritVal);
				LRaO_statistic[posRepSeq][posOptiMeth].setDurationTime_GeneticAndDLS(totalDuration_secondes.count());
				LRaO_statistic[posRepSeq][posOptiMeth].setReplaceSequence(tempReplaceSequence, temUsedReplaceSeq);

				for (unsigned int i = 0; i < tempOptSysMeritLensType.size(); ++i)
				{
					LRaO_statistic[posRepSeq][posOptiMeth].setBestLensNumberWasTaken(i, tempOptSysMeritLensType[i].getPositionInBestMatchLensVec());
				}

			}

			else if (tempOptiMethode == optimizeMethode::GeneticAndDLS_12)
			{
				LRaO_statistic[posRepSeq][posOptiMeth].setMeritVal_GeneticAndDLS_12(tempBestMeritVal);
				LRaO_statistic[posRepSeq][posOptiMeth].setDurationTime_GeneticAndDLS_12(totalDuration_secondes.count());
				LRaO_statistic[posRepSeq][posOptiMeth].setReplaceSequence(tempReplaceSequence, temUsedReplaceSeq);

				for (unsigned int i = 0; i < tempOptSysMeritLensType.size(); ++i)
				{
					LRaO_statistic[posRepSeq][posOptiMeth].setBestLensNumberWasTaken(i, tempOptSysMeritLensType[i].getPositionInBestMatchLensVec());
				}

			}
		


		}
	}

	return LRaO_statistic;
}

bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_superFct()
{
	std::vector<bool> workTheSystem;

	// debug mode
	// turn_ON_debugMode();
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
	bool checkE0 = testLRaO_stat_twoLensSystem_E0();
	workTheSystem.push_back(checkE0);
	if (checkE0) { inportExportData::saveStringInTXT_includingTime(location, name, "E0 worked"); };

	// E1
	bool checkE1 = testLRaO_stat_twoLensSystem_E1();
	workTheSystem.push_back(checkE1);
	if (checkE1) { inportExportData::saveStringInTXT_includingTime(location, name, "E1 worked"); };


	exportAllStatisticDataReplaceTwoLenses();

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}
// E0
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E0()
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

	mSaveAllResults.push_back(doTheStatisticEvaluation(optSystemElement, tarCarP, location));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}

// E1
bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_E1()
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

	mSaveAllResults.push_back(doTheStatisticEvaluation(optSystemElement, tarCarP, location));


	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}