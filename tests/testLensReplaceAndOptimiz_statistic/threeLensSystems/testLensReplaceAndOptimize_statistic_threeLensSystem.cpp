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

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems";
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

// super fct
bool testLensReplaceAndOptimize_statistic_THREE_LensSystem::testLRaO_stat_THREE_lensSystem_superFct()
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

	std::string location = "../tests/testLensReplaceAndOptimiz_statistic/threeLensSystems";
	std::string name = "testLensReplaceAndOptimize_statistic_threeLensSystem";


	// E0 three lens system
	bool checkE0_threeLensSystem = testLRaO_stat_THREE_LensSystem_E0("E0_threeLensSystem");
	workTheSystem.push_back(checkE0_threeLensSystem);
	if (checkE0_threeLensSystem) { inportExportData::saveStringInTXT_includingTime(location, name, "E0 three lens system worked"); };






	exportAllStatisticDataReplace_THREE_LensesGeneticAndDLS_12();



	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}

// do the statistic evaluation
std::vector<saveLRaO_GeneticAndDLS_12_statistic> testLensReplaceAndOptimize_statistic_THREE_LensSystem::doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12(OpticalSystemElement optSysEle, targetCardinalPointsStruct targetCarPoints, std::string location, std::string example)
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

	std::string nameOptimizationMethode = "GeneticAndDLS_12" ;
	std::vector<std::string> nameLoc = { "/leftToRight", "/rightToLeft", "/maxSeidel", "/minSeidel", "/allSequences" };
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
	
	mSaveAllResults_Three_LensSystem.push_back(doTheStatisticEvaluation_THREE_lensSystemGeneticAndDLS_12(optSystemElement, tarCarP, location, example));

	bool checker = Math::checkTrueOfVectorElements(workTheSystem);
	return checker;
}

