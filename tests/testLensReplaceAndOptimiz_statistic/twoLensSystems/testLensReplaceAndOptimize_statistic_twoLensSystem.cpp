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

	// debug
	mDefaulParaDLS.setMaxInterations(5);
	mPopulation = 5.0;

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

// do the statistic evaluation
saveLRaO_statistic doTheStatisticEvaluation(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location)
{
	unsigned int numberLenses = oftenUse::findLensesInOptSysEle(optSysEle).size();
	saveLRaO_statistic LRaO_statistic(numberLenses);

	//optimizeMethode optMethode = optimizeMethode::DLS;
	//targetCardinalPointsStruct tarCarP;
	//tarCarP.setTargetEFL(15.0);
	//tarCarP.setTargetMag(-1.5);
	//defaultParaDLS defParaDLS = oftenUse::getDefaultPara_DLS(true);
	////defParaDLS.setFlipOrientationRadius(500.0);
	//defParaDLS.setMaxBorderViolations(200.0);
	//
	//// *** set lens catalogs
	//std::vector<lensTypes> loadLensCatalogEO_vec;
	//loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConvex_VIS_NIR);
	//loadLensCatalogEO_vec.push_back(lensTypes::EO_PosAchromat_MgF_Coated);
	//loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConvex_VIS_NIR);
	//loadLensCatalogEO_vec.push_back(lensTypes::EO_DoubleConcav_VIS_NIR);
	//loadLensCatalogEO_vec.push_back(lensTypes::EO_PlanConcav_VIS_NIR);
	//// ***
	//
	//unsigned int numberBestFitLenses = 2;
	//
	//LensReplaceAndOptimize testLensReplaceAndOptiSuperFct;
	//testLensReplaceAndOptiSuperFct.setTargetCardinalPoints(tarCarP);
	//testLensReplaceAndOptiSuperFct.setDefaulParaDLS(defParaDLS);
	//testLensReplaceAndOptiSuperFct.setLoadLensCatalogs(loadLensCatalogEO_vec);
	//
	//replaceSequence repSequence = replaceSequence::RightToLeft;
	//Light_LLT light = oftenUse::getDefaultLight();
	//testLensReplaceAndOptiSuperFct.lensReplaceAndOptimize_superFct(optSystemElement, field_vec, wave_vec, rings, arms, optMethode, /*number best fit lenses*/ numberBestFitLenses, true, repSequence, light);
	//OpticalSystemElement optSysEle_lensRepSuperFct = testLensReplaceAndOptiSuperFct.getBestReplacedOpticalSystem();
	//
	//// debug
	//oftenUse::print(optSysEle_lensRepSuperFct, 550.0);
	//testLensReplaceAndOptiSuperFct.printBestParameterCatalogForReplace();
	//
	//// save parameter
	////std::string location = "../tests/testLensReplaceAndOptimize/E4";
	//std::string nameOptSysReplaced = "E4_optSys_Replaced";
	//std::string bestCatalogLensesForReplace = "E4_bestCatalogLensesForReplace";
	//std::string E4_replaceSequence = "E4_replaceSequence";
	//
	//std::vector<int> E4_replacedSequence = testLensReplaceAndOptiSuperFct.getReplacedSequence();
	//
	//
	//inportExportData::saveOpticalSystemAsTXT(optSysEle_lensRepSuperFct, 550.0, location, nameOptSysReplaced);
	//inportExportData::exportIntVecInTXT(location, E4_replaceSequence, "E4_replaceSequence", E4_replacedSequence, true);
	//testLensReplaceAndOptiSuperFct.exportBestParameterCatalogForReplaceTXT(location, bestCatalogLensesForReplace);

	return LRaO_statistic;
}

bool testLensReplaceAndOptimize_statistic_twoLensSystem::testLRaO_stat_twoLensSystem_superFct()
{
	std::vector<bool> workTheSystem;

	// E0
	bool checkE0 = testLRaO_stat_twoLensSystem_E0();
	workTheSystem.push_back(checkE0);

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


	targetCardinalPointsStruct tarCarP;
	tarCarP.setTargetEFL(15.0);
	tarCarP.setTargetMag(-1.0);



	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}