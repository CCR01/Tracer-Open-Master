#include "LensReplaceAndOptimize.h"


// often use
#include "..\oftenUseNamespace\oftenUseNamespace.h"
// Seidel Coeff
#include "..\Analyse\Seidel Coefficients.h"
// inport export data
#include "..\Inport_Export_Data\Inport_Export_Data.h"
// DLS 12
#include "..\OptimizeSystem\multiThreads\DLS_mulitThreads12.h"


LensReplaceAndOptimize::LensReplaceAndOptimize() 
{ 
	turn_OFF_DebugMode(); 
}

LensReplaceAndOptimize::~LensReplaceAndOptimize(){}


void LensReplaceAndOptimize::lensReplaceAndOptimize_superFct(OpticalSystemElement optSysEle, std::vector<VectorStructR3> fieldPointsVec, std::vector<real> wavelength_vec, unsigned int rings, unsigned int arms, optimizeMethode optMethode, /*number best fit lenses*/ unsigned int numberBestFitLenses, bool firstInteration, replaceSequence repSequence, Light_LLT light)
{
	mInitalOpticalSystemEle_SuperFct = optSysEle.getDeepCopyOptSysEle();
	OpticalSystem_LLT optSysLLT = optSysEle.getLLTconversion_doConversion();
	std::vector<OpticalSystem_LLT> optSysLLT_lenses_vec = oftenUse::findLensesInOptSys_LLT(optSysLLT); 
	unsigned int lensesInOptSys = optSysLLT_lenses_vec.size();

	OpticalSystemElement tempOptSysToReplace = optSysEle.getDeepCopyOptSysEle();
	bool tempFirstInteration = firstInteration;
	mBestCatalogLensesForReplace.resize(lensesInOptSys);
	unsigned int tempNumberLensToReplace{};
	unsigned int sizeFieldPointVec = fieldPointsVec.size();
	VectorStructR3 maxStartPoint = oftenUse::getMaxStartPoint({ 0.0,0.0,0.0 }, fieldPointsVec);
	//VectorStructR3 maxStartPoint = fieldPointsVec[1];
	unsigned int counter = 0;

	if (repSequence == replaceSequence::leftToRight)
	{		
		mSaveReplacedSequence.resize(lensesInOptSys);
		tempNumberLensToReplace = 0;

		while (tempNumberLensToReplace < lensesInOptSys)
		{
			lensReplaceAndOptimize(tempOptSysToReplace, fieldPointsVec, wavelength_vec, rings, arms, optMethode, tempNumberLensToReplace, /*number best fit lenses*/numberBestFitLenses, tempFirstInteration);
			tempOptSysToReplace = getBestReplacedOpticalSystem();

			// save best parameter cataloge lens for replace
			saveBestParameterCatalogLensForReplace(tempNumberLensToReplace);

			// replace next lens
			mSaveReplacedSequence[tempNumberLensToReplace] = tempNumberLensToReplace;
			tempNumberLensToReplace++;
			tempFirstInteration = false;
			
		}
		

	}

	else if (repSequence == replaceSequence::RightToLeft)
	{
		mSaveReplacedSequence.resize(lensesInOptSys);
		tempNumberLensToReplace = lensesInOptSys - 1;
		int counter = 0;

		while (tempNumberLensToReplace < lensesInOptSys)
		{
			lensReplaceAndOptimize(tempOptSysToReplace, fieldPointsVec, wavelength_vec, rings, arms, optMethode, tempNumberLensToReplace, /*number best fit lenses*/numberBestFitLenses, tempFirstInteration);
			tempOptSysToReplace = getBestReplacedOpticalSystem();

			// save best parameter cataloge lens for replace
			saveBestParameterCatalogLensForReplace(tempNumberLensToReplace);

			// replace next lens
			mSaveReplacedSequence[counter] = tempNumberLensToReplace;
			tempNumberLensToReplace--;
			tempFirstInteration = false;
			++counter;

		}

	}

	else if (repSequence == replaceSequence::maxSeidelAberLens || repSequence == replaceSequence::minSeidelAberLens)
	{
		// lens replaced
		std::vector<bool> lensReplaced;
		lensReplaced.resize(lensesInOptSys);
		for (unsigned int i = 0; i < lensesInOptSys; ++i)
		{
			lensReplaced[i] = false;
		}

		mSaveReplacedSequence.resize(lensesInOptSys);

		while (counter < lensesInOptSys)
		{
			

			SeidelCoefficients seidelCoef;
			seidelCoef.calcSeidelCoef_superFuction(tempOptSysToReplace, wavelength_vec, light, maxStartPoint);
			std::vector<real> seidelSumAllLenses = seidelCoef.calcSeidelSum_allLenses();
			unsigned int nextlensNumber{};

			if (repSequence == replaceSequence::maxSeidelAberLens)
			{
				nextlensNumber = seidelCoef.getLensNumber_Max_SeidelAber(seidelSumAllLenses);
			}
			else if (repSequence == replaceSequence::minSeidelAberLens)
			{
				nextlensNumber = seidelCoef.getLensNumber_Min_SeidelAber(seidelSumAllLenses);
			}

			for (unsigned int tempLensNum = 0; tempLensNum < lensesInOptSys; ++tempLensNum)
			{
				if( std::abs(tempLensNum - nextlensNumber < 0.1))
				{
					
					if (lensReplaced[tempLensNum] == false)
					{
						// set lens to replaced
						lensReplaced[tempLensNum] = true;
						tempNumberLensToReplace = tempLensNum;
						tempLensNum = lensesInOptSys;
					}
					else
					{
						if (repSequence == replaceSequence::maxSeidelAberLens)
						{
							seidelSumAllLenses[tempLensNum] = -1.0 * oftenUse::getInfReal();
							nextlensNumber = seidelCoef.getLensNumber_Max_SeidelAber(seidelSumAllLenses);
						}
						else if (repSequence == replaceSequence::minSeidelAberLens)
						{
							seidelSumAllLenses[tempLensNum] = oftenUse::getInfReal();
							nextlensNumber = seidelCoef.getLensNumber_Min_SeidelAber(seidelSumAllLenses);
						}
												
						tempLensNum = -1;
					}
					
				}
			}

			mSaveReplacedSequence[counter] = tempNumberLensToReplace;

			lensReplaceAndOptimize(tempOptSysToReplace, fieldPointsVec, wavelength_vec, rings, arms, optMethode, tempNumberLensToReplace, /*number best fit lenses*/numberBestFitLenses, tempFirstInteration);
			tempOptSysToReplace = getBestReplacedOpticalSystem();

			// save best parameter cataloge lens for replace
			saveBestParameterCatalogLensForReplace(tempNumberLensToReplace);
						

			++counter; 
			tempFirstInteration = false;
		}
		


	}

	if (repSequence == replaceSequence::allPossibleSequences)
	{
		// sequence lens replace left to right
		std::vector<int> sequenceLensReplaceLeftToRight;
		sequenceLensReplaceLeftToRight.resize(lensesInOptSys);
		for (unsigned int i = 0; i < lensesInOptSys; ++i)
		{
			sequenceLensReplaceLeftToRight[i] = i;
		}

		// calc all possible sequences
		std::vector<std::vector<int>> mAllPossibleSequencesInt = oftenUse::calcAllPossibleSequencesInt(sequenceLensReplaceLeftToRight);
		int counter = 0;
		int size = mAllPossibleSequencesInt.size();

		// resize
		mSaveAllBestLensToReplace_vec_includingFlipedLenses.resize(size);
		mSaveAllBestMeritVal.resize(size);
		mSaveAllBestReplacedOpticalSystem.resize(size);

		while (counter < size)
		{
				
			for (unsigned int i = 0; i < lensesInOptSys; ++i)
			{
				tempNumberLensToReplace = mAllPossibleSequencesInt[counter][i];
				lensReplaceAndOptimize(tempOptSysToReplace, fieldPointsVec, wavelength_vec, rings, arms, optMethode, tempNumberLensToReplace, /*number best fit lenses*/numberBestFitLenses, tempFirstInteration);
				tempOptSysToReplace = getBestReplacedOpticalSystem();
				tempFirstInteration = false;

				// save best parameter cataloge lens for replace
				saveBestParameterCatalogLensForReplace(tempNumberLensToReplace);
			}

			mSaveAllBestLensToReplace_vec_includingFlipedLenses[counter] = mBestCatalogLensesForReplace;
			mSaveAllBestMeritVal[counter] = mBestMeritVal;
			mSaveAllBestReplacedOpticalSystem[counter] = tempOptSysToReplace.getDeepCopyOptSysEle();
						
		
			tempOptSysToReplace = mInitalOpticalSystemEle_SuperFct.getDeepCopyOptSysEle();
			++counter;
			
		}

		// find best replace optical system
		real tempMeritVal = mSaveAllBestMeritVal[0];
		mBestMeritVal = mSaveAllBestMeritVal[0];
		int posBestMeritVal = 0;

		for (unsigned int i = 1; i < mSaveAllBestMeritVal.size(); ++i)
		{
			if (tempMeritVal < mBestMeritVal)
			{
				mBestMeritVal = tempMeritVal;
				posBestMeritVal = i;
			}

			tempMeritVal = mSaveAllBestMeritVal[i];
		}


		mBestReplacedOptSysEle = mSaveAllBestReplacedOpticalSystem[posBestMeritVal];
		mBestCatalogLensesForReplace = mSaveAllBestLensToReplace_vec_includingFlipedLenses[posBestMeritVal];
		mSaveReplacedSequence = mAllPossibleSequencesInt[posBestMeritVal];

	}

	else if (repSequence == replaceSequence::givenSequence)
	{
		unsigned int sizeLoadSequence = mLoadSequence.size();
		int checkSize = sizeLoadSequence - lensesInOptSys;
		// check size of given sequence
		if (std::abs(checkSize) > 0.1)
		{
			oftenUse::errorProtocol_stopSystem("SIZE OF YOUR REPLACE SEQUENCE DO NOT MATCH WITH THE NUMBER OF LENSES IN THE OPTICAL SYSTEM!!!", "LensReplaceAndOptimize.cpp", 0, true);
		}

		// check given sequence
		std::vector<unsigned int> sortedSequence = mLoadSequence;
		std::sort(sortedSequence.begin(), sortedSequence.end());
		real tolerance = 0.1;
		real tempValue{};
		real checker{};
		for (unsigned int i = 0; i < sortedSequence.size(); ++i)
		{
			tempValue = sortedSequence[i] - i;
			checker = std::abs(tempValue);
			if (checker > tolerance)
			{
				oftenUse::errorProtocol_stopSystem("ATTENTION: YOUR SEQUENCE IS NOT CORRECT!!!", "LensReplaceAndOptimize.cpp", 0, true);
			}

		}


		mSaveReplacedSequence.resize(lensesInOptSys);
		tempNumberLensToReplace = 0;
		unsigned int counter = 0;

		while (counter < lensesInOptSys)
		{
			tempNumberLensToReplace = mLoadSequence[counter];

			lensReplaceAndOptimize(tempOptSysToReplace, fieldPointsVec, wavelength_vec, rings, arms, optMethode, tempNumberLensToReplace, /*number best fit lenses*/numberBestFitLenses, tempFirstInteration);
			tempOptSysToReplace = getBestReplacedOpticalSystem();

			// save best parameter cataloge lens for replace
			saveBestParameterCatalogLensForReplace(tempNumberLensToReplace);

			// replace next lens
			mSaveReplacedSequence[counter] = tempNumberLensToReplace;
			counter++;
			tempFirstInteration = false;

		}

	}

	else
	{
		std::cout << "ATTENTION: THE REPLACE SEQUENCE YOU HAVE CHOOSEN DO NOT EXIST!!!" << std::endl;
	}
}


void LensReplaceAndOptimize::lensReplaceAndOptimize(OpticalSystemElement optSysEle, std::vector<VectorStructR3> fieldPointsVec, std::vector<real> wavelength_vec, unsigned int rings, unsigned int arms, optimizeMethode optMethode, unsigned int numberLensToReplace, /*number best fit lenses*/ unsigned int numberBestFitLenses, bool firstInteration)
{

	mInitalOpticalSystemEle_LensReplaceAndOptimize = optSysEle.getDeepCopyOptSysEle();
	mFieldPointsVec = fieldPointsVec;
	mWavelength_vec = wavelength_vec;
	mRings = rings;
	mArms = arms;

	if (optMethode == optimizeMethode::DLS)
	{
		lensReplaceAndOpti_DLS(numberLensToReplace, numberBestFitLenses, firstInteration);
	}

	else if (optMethode == optimizeMethode::DLS_12)
	{
	
		lensReplaceAndOpti_DLS_12(numberLensToReplace, numberBestFitLenses, firstInteration);
	}

	else if (optMethode == optimizeMethode::GeneticAndDLS)
	{
		lensReplaceAndOpti_GeneticAndDLS(numberLensToReplace, numberBestFitLenses, firstInteration);
	}

	else if (optMethode == optimizeMethode::GeneticAndDLS_12)
	{
		lensReplaceAndOpti_GeneticAndDLS_12(numberLensToReplace, numberBestFitLenses, firstInteration);
	}
}

void LensReplaceAndOptimize::lensReplaceAndOpti_DLS(unsigned int numberLensToReplace, /*number best fit lenses*/ unsigned int numberBestFitLenses, bool firstInteration)
{
	// clear
	mReplaceOpticalSysEle.clear();
	mOptimizedOpticalSystemEle.clearALL();
	mBestLensToReplace_vec_includingFlipedLenses.clear();
	mReplaceOpticalSysEle_opti.clear();
	mReplaceMeritVal_opti.clear();

	

	if (mDebugMode)
	{
		mDefaulParaDLS.setMaxInterations(1);
	}


	if (mTargetCardinalPoints.getIsOneTargetCardinalPoint())
	{
		if(firstInteration)
		{
			DLS DLS_Fct;
			DLS_Fct.turnOFF_imageProcessing();
			// optimize optical system
			DLS_Fct.DLS_superFctDLS(mInitalOpticalSystemEle_LensReplaceAndOptimize, mFieldPointsVec, mWavelength_vec, mRings, mArms, mTargetCardinalPoints, mDefaulParaDLS);
			mOptimizedOpticalSystemEle = DLS_Fct.getOptimizedSystem_HLT();
		}
		else
		{
			mOptimizedOpticalSystemEle = mInitalOpticalSystemEle_LensReplaceAndOptimize.getDeepCopyOptSysEle();
		}
		//debug
		//oftenUse::print(mOptimizedOpticalSystemEle, 550.0);

		// replace lens
		LensReplace lensRep;
		mOptimizedOpticalSystemEle.setRefractiveIndexAccordingToWavelength(550.0);
		lensRep.setRefIndexSurroundMat(oftenUse::getStartRefIndex(mOptimizedOpticalSystemEle.getLLTconversion_doConversion()));
		lensRep.replaceSuperFuction(mOptimizedOpticalSystemEle);
		lensRep.loadLensCata(mLoadLensCatalogEO_vec);

		mBestLensToReplace_vec = lensRep.checkLensCatalogsForBestFitLenses_many(/*lens number*/numberLensToReplace, /*parameter lens*/ lensRep.getParameterLenses()[numberLensToReplace],/*number best fit lenses*/ numberBestFitLenses);
		mBestLensToReplace_vec_includingFlipedLenses = flipOptSysEleBy180Degrees(mBestLensToReplace_vec);
		
		mReplaceOpticalSysEle.resize(mBestLensToReplace_vec_includingFlipedLenses.size());

		bool first = true;
		for (unsigned int i = 0; i < mBestLensToReplace_vec_includingFlipedLenses.size(); ++i)
		{
			if (first == false)
			{
				lensRep.replaceSuperFuction(mOptimizedOpticalSystemEle);
			}
			lensRep.replaceLens(numberLensToReplace, mBestLensToReplace_vec_includingFlipedLenses[i].getOptSysEle());
			lensRep.adjustThicknessesAccordingToFixed();
			mReplaceOpticalSysEle[i] = lensRep.getOpticalSysEle_replacedLens().getDeepCopyOptSysEle();

			first = false;
		}

		mReplaceOpticalSysEle_opti.resize(mBestLensToReplace_vec_includingFlipedLenses.size());
		mReplaceMeritVal_opti.resize(mBestLensToReplace_vec_includingFlipedLenses.size());

		for (unsigned int i = 0; i < mBestLensToReplace_vec_includingFlipedLenses.size(); ++i)
		{
			DLS DLS_Fct_replaced;
			DLS_Fct_replaced.turnOFF_imageProcessing();
			DLS_Fct_replaced.DLS_superFctDLS(mReplaceOpticalSysEle[i], mFieldPointsVec, mWavelength_vec, mRings, mArms, mTargetCardinalPoints, mDefaulParaDLS);
			mReplaceOpticalSysEle_opti[i] = DLS_Fct_replaced.getOptimizedSystem_HLT();
			mReplaceMeritVal_opti[i] = DLS_Fct_replaced.getBestMeritValue();
		}


		// save the best replace optical system
		saveBestReplacedOpticalSystem();

	}


}

void LensReplaceAndOptimize::lensReplaceAndOpti_DLS_12(unsigned int numberLensToReplace, /*number best fit lenses*/ unsigned int numberBestFitLenses, bool firstInteration)
{
	// clear
	mReplaceOpticalSysEle.clear();
	mOptimizedOpticalSystemEle.clearALL();
	mBestLensToReplace_vec_includingFlipedLenses.clear();
	mReplaceOpticalSysEle_opti.clear();
	mReplaceMeritVal_opti.clear();

	if (mDebugMode)
	{
		mDefaulParaDLS.setMaxInterations(1);
	}
	
	

	if (mTargetCardinalPoints.getIsOneTargetCardinalPoint())
	{
		if (firstInteration)
		{
			// optimize optical system
			DLS_multiThreads_12 DLS_multi_12(mInitalOpticalSystemEle_LensReplaceAndOptimize, mFieldPointsVec, mWavelength_vec, mRings, mArms, mTargetCardinalPoints, mDefaulParaDLS);
			mOptimizedOpticalSystemEle = DLS_multi_12.DLS_optimisation_multiThreads_12_obj();
		}
		else
		{
			mOptimizedOpticalSystemEle = mInitalOpticalSystemEle_LensReplaceAndOptimize.getDeepCopyOptSysEle();
		}
		//debug
		//oftenUse::print(mOptimizedOpticalSystemEle, 550.0);

		// replace lens
		LensReplace lensRep;
		mOptimizedOpticalSystemEle.setRefractiveIndexAccordingToWavelength(550.0);
		lensRep.setRefIndexSurroundMat(oftenUse::getStartRefIndex(mOptimizedOpticalSystemEle.getLLTconversion_doConversion()));
		lensRep.replaceSuperFuction(mOptimizedOpticalSystemEle);
		lensRep.loadLensCata(mLoadLensCatalogEO_vec);

		mBestLensToReplace_vec = lensRep.checkLensCatalogsForBestFitLenses_many(/*lens number*/numberLensToReplace, /*parameter lens*/ lensRep.getParameterLenses()[numberLensToReplace],/*number best fit lenses*/ numberBestFitLenses);
		mBestLensToReplace_vec_includingFlipedLenses = flipOptSysEleBy180Degrees(mBestLensToReplace_vec);

		mReplaceOpticalSysEle.resize(mBestLensToReplace_vec_includingFlipedLenses.size());

		bool first = true;
		for (unsigned int i = 0; i < mBestLensToReplace_vec_includingFlipedLenses.size(); ++i)
		{
			if (first == false)
			{
				lensRep.replaceSuperFuction(mOptimizedOpticalSystemEle);
			}
			lensRep.replaceLens(numberLensToReplace, mBestLensToReplace_vec_includingFlipedLenses[i].getOptSysEle());
			lensRep.adjustThicknessesAccordingToFixed();
			mReplaceOpticalSysEle[i] = lensRep.getOpticalSysEle_replacedLens().getDeepCopyOptSysEle();

			first = false;
		}

		mReplaceOpticalSysEle_opti.resize(mBestLensToReplace_vec_includingFlipedLenses.size());
		mReplaceMeritVal_opti.resize(mBestLensToReplace_vec_includingFlipedLenses.size());

		for (unsigned int i = 0; i < mBestLensToReplace_vec_includingFlipedLenses.size(); ++i)
		{

			DLS_multiThreads_12 DLS_multi_12_replaced(mReplaceOpticalSysEle[i], mFieldPointsVec, mWavelength_vec, mRings, mArms, mTargetCardinalPoints, mDefaulParaDLS);

			mReplaceOpticalSysEle_opti[i] = DLS_multi_12_replaced.DLS_optimisation_multiThreads_12_obj();
			mReplaceMeritVal_opti[i] = DLS_multi_12_replaced.getBestMeritValue();
		}


		// save the best replace optical system
		saveBestReplacedOpticalSystem();

	}


}

void LensReplaceAndOptimize::lensReplaceAndOpti_GeneticAndDLS(unsigned int numberLensToReplace, /*number best fit lenses*/ unsigned int numberBestFitLenses, bool firstInteration)
{
	// clear
	mReplaceOpticalSysEle.clear();
	mOptimizedOpticalSystemEle.clearALL();
	mBestLensToReplace_vec_includingFlipedLenses.clear();
	mReplaceOpticalSysEle_opti.clear();
	mReplaceMeritVal_opti.clear();

	if (mDebugMode)
	{
		mDefaulParaDLS.setMaxInterations(1);
		mDefaultParaGenetic.setMaxInterationGenetic(1);
		mPopulation = 5;
	}


	if (mTargetCardinalPoints.getIsOneTargetCardinalPoint())
	{
		if (firstInteration)
		{
			// optimize optical system
			OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ mInitalOpticalSystemEle_LensReplaceAndOptimize,/*fields*/ mFieldPointsVec, /*wavelength*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCardinalPoints, /*default Genetic*/mDefaultParaGenetic, /*default DLS*/ mDefaulParaDLS);
			mOptimizedOpticalSystemEle = GeneticAndDLS.optimizeSuperFct_GeneticAndDLS();
		}
		else
		{
			mOptimizedOpticalSystemEle = mInitalOpticalSystemEle_LensReplaceAndOptimize.getDeepCopyOptSysEle();
		}
		//debug
		//oftenUse::print(mOptimizedOpticalSystemEle, 550.0);

		// replace lens
		LensReplace lensRep;
		mOptimizedOpticalSystemEle.setRefractiveIndexAccordingToWavelength(550.0);
		lensRep.setRefIndexSurroundMat(oftenUse::getStartRefIndex(mOptimizedOpticalSystemEle.getLLTconversion_doConversion()));
		lensRep.replaceSuperFuction(mOptimizedOpticalSystemEle);
		lensRep.loadLensCata(mLoadLensCatalogEO_vec);

		mBestLensToReplace_vec = lensRep.checkLensCatalogsForBestFitLenses_many(/*lens number*/numberLensToReplace, /*parameter lens*/ lensRep.getParameterLenses()[numberLensToReplace],/*number best fit lenses*/ numberBestFitLenses);
		mBestLensToReplace_vec_includingFlipedLenses = flipOptSysEleBy180Degrees(mBestLensToReplace_vec);

		mReplaceOpticalSysEle.resize(mBestLensToReplace_vec_includingFlipedLenses.size());

		bool first = true;
		for (unsigned int i = 0; i < mBestLensToReplace_vec_includingFlipedLenses.size(); ++i)
		{
			if (first == false)
			{
				lensRep.replaceSuperFuction(mOptimizedOpticalSystemEle);
			}
			lensRep.replaceLens(numberLensToReplace, mBestLensToReplace_vec_includingFlipedLenses[i].getOptSysEle());
			lensRep.adjustThicknessesAccordingToFixed();
			mReplaceOpticalSysEle[i] = lensRep.getOpticalSysEle_replacedLens().getDeepCopyOptSysEle();

			first = false;
		}

		mReplaceOpticalSysEle_opti.resize(mBestLensToReplace_vec_includingFlipedLenses.size());
		mReplaceMeritVal_opti.resize(mBestLensToReplace_vec_includingFlipedLenses.size());

		for (unsigned int i = 0; i < mBestLensToReplace_vec_includingFlipedLenses.size(); ++i)
		{

			// optimize optical system
			OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ mReplaceOpticalSysEle[i],/*fields*/ mFieldPointsVec, /*wavelength*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCardinalPoints, /*default Genetic*/mDefaultParaGenetic, /*default DLS*/ mDefaulParaDLS);
	
			mReplaceOpticalSysEle_opti[i] = GeneticAndDLS.optimizeSuperFct_GeneticAndDLS();
			mReplaceMeritVal_opti[i] = GeneticAndDLS.getBestMeritValue();
		}


		// save the best replace optical system
		saveBestReplacedOpticalSystem();

	}


}

void LensReplaceAndOptimize::lensReplaceAndOpti_GeneticAndDLS_12(unsigned int numberLensToReplace, /*number best fit lenses*/ unsigned int numberBestFitLenses, bool firstInteration)
{
	// clear
	mReplaceOpticalSysEle.clear();
	mOptimizedOpticalSystemEle.clearALL();
	mBestLensToReplace_vec_includingFlipedLenses.clear();
	mReplaceOpticalSysEle_opti.clear();
	mReplaceMeritVal_opti.clear();

	if (mDebugMode)
	{
		mDefaulParaDLS.setMaxInterations(1);
		mDefaultParaGenetic.setMaxInterationGenetic(1);
		mPopulation = 5;
	}



	if (mTargetCardinalPoints.getIsOneTargetCardinalPoint())
	{
		if (firstInteration)
		{
			// optimize optical system
			OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ mInitalOpticalSystemEle_LensReplaceAndOptimize,/*fields*/ mFieldPointsVec, /*wavelength*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCardinalPoints, /*default Genetic*/mDefaultParaGenetic, /*default DLS*/ mDefaulParaDLS);
			mOptimizedOpticalSystemEle = GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();
		}
		else
		{
			mOptimizedOpticalSystemEle = mInitalOpticalSystemEle_LensReplaceAndOptimize.getDeepCopyOptSysEle();
		}
		//debug
		//oftenUse::print(mOptimizedOpticalSystemEle, 550.0);

		// replace lens
		LensReplace lensRep;
		mOptimizedOpticalSystemEle.setRefractiveIndexAccordingToWavelength(550.0);
		lensRep.setRefIndexSurroundMat(oftenUse::getStartRefIndex(mOptimizedOpticalSystemEle.getLLTconversion_doConversion()));
		lensRep.replaceSuperFuction(mOptimizedOpticalSystemEle);
		lensRep.loadLensCata(mLoadLensCatalogEO_vec);

		mBestLensToReplace_vec = lensRep.checkLensCatalogsForBestFitLenses_many(/*lens number*/numberLensToReplace, /*parameter lens*/ lensRep.getParameterLenses()[numberLensToReplace],/*number best fit lenses*/ numberBestFitLenses);
		mBestLensToReplace_vec_includingFlipedLenses = flipOptSysEleBy180Degrees(mBestLensToReplace_vec);

		mReplaceOpticalSysEle.resize(mBestLensToReplace_vec_includingFlipedLenses.size());

		bool first = true;
		for (unsigned int i = 0; i < mBestLensToReplace_vec_includingFlipedLenses.size(); ++i)
		{
			if (first == false)
			{
				lensRep.replaceSuperFuction(mOptimizedOpticalSystemEle);
			}
			lensRep.replaceLens(numberLensToReplace, mBestLensToReplace_vec_includingFlipedLenses[i].getOptSysEle());
			lensRep.adjustThicknessesAccordingToFixed();
			mReplaceOpticalSysEle[i] = lensRep.getOpticalSysEle_replacedLens().getDeepCopyOptSysEle();

			first = false;
		}

		mReplaceOpticalSysEle_opti.resize(mBestLensToReplace_vec_includingFlipedLenses.size());
		mReplaceMeritVal_opti.resize(mBestLensToReplace_vec_includingFlipedLenses.size());

		for (unsigned int i = 0; i < mBestLensToReplace_vec_includingFlipedLenses.size(); ++i)
		{

			// optimize optical system
			OptimizeSystemSuperFct_GeneticAndDLS GeneticAndDLS(/*optSysEle*/ mReplaceOpticalSysEle[i],/*fields*/ mFieldPointsVec, /*wavelength*/ mWavelength_vec, /*rings*/ mRings, /*arms*/ mArms, /*populatuion*/ mPopulation, /*target cardinal points*/ mTargetCardinalPoints, /*default Genetic*/mDefaultParaGenetic, /*default DLS*/ mDefaulParaDLS);

			mReplaceOpticalSysEle_opti[i] = GeneticAndDLS.optimizeSuperFct_GeneticAndDLS_12Cores();
			mReplaceMeritVal_opti[i] = GeneticAndDLS.getBestMeritValue();
		}


		// save the best replace optical system
		saveBestReplacedOpticalSystem();

	}
}

// carindal points
void LensReplaceAndOptimize::setTargetCardinalPoints(targetCardinalPointsStruct tarCarPoints)
{
	mTargetCardinalPoints = tarCarPoints;
}
targetCardinalPointsStruct LensReplaceAndOptimize::getTargetCardinalPoints()
{
	return mTargetCardinalPoints;
}
// ***

// DLS
void LensReplaceAndOptimize::setDefaulParaDLS(defaultParaDLS deParaDLS)
{
	mDefaulParaDLS = deParaDLS;
}
defaultParaDLS LensReplaceAndOptimize::getDefaulParaDLS()
{
	return mDefaulParaDLS;
}
// ***

	// Genetic
void LensReplaceAndOptimize::setDefaultParaGenetic(defaultParaGenetic deParaGenetic)
{
	mDefaultParaGenetic = deParaGenetic;
}
defaultParaGenetic LensReplaceAndOptimize::getDefaultParaGenetic()
{
	return mDefaultParaGenetic;
}
void LensReplaceAndOptimize::setPopulation(unsigned int population)
{
	mPopulation = population;
}
unsigned int LensReplaceAndOptimize::getPopulation()
{
	return mPopulation;
}
// ***

void LensReplaceAndOptimize::setLoadLensCatalogs(std::vector<lensTypes> lensCataVec)
{
	mLoadLensCatalogEO_vec = lensCataVec;
}

void LensReplaceAndOptimize::saveBestReplacedOpticalSystem()
{
	real tempMeritVal{};

	mBestMeritVal = mReplaceMeritVal_opti[0];
	mPosBestMeritVal = 0;

	// find best merit value
	for (unsigned int i = 0; i < mReplaceMeritVal_opti.size(); ++i)
	{
		tempMeritVal = mReplaceMeritVal_opti[i];
		if (tempMeritVal < mBestMeritVal)
		{
			mBestMeritVal = tempMeritVal;
			mPosBestMeritVal = i;
		}
	}

	mBestReplacedOptSysEle = mReplaceOpticalSysEle_opti[mPosBestMeritVal];
}

std::vector<OptSysEle_Merit_LensType> LensReplaceAndOptimize::flipOptSysEleBy180Degrees(std::vector <OptSysEle_Merit_LensType> initialBestOptSysReplace)
{
	OpticalSystemElement optSysEle;
	std::vector<OptSysEle_Merit_LensType> returnBestOptSysReplaceIncludingFliped{};
	returnBestOptSysReplaceIncludingFliped.resize(initialBestOptSysReplace.size() * 2);
	int tempPos = 0;

	OptSysEle_Merit_LensType tempOptSysEleMeritLensType;

	for (unsigned int i = 0; i < initialBestOptSysReplace.size(); ++i)
	{
		returnBestOptSysReplaceIncludingFliped[tempPos] = initialBestOptSysReplace[i];
		// debug
		oftenUse::print(returnBestOptSysReplaceIncludingFliped[tempPos].getOptSysEle(), 550.0);
		++tempPos;



		tempOptSysEleMeritLensType = initialBestOptSysReplace[i];
		tempOptSysEleMeritLensType.setOpticalSystemEle(optSysEle.reverseOptSysEle(initialBestOptSysReplace[i].getOptSysEle()));
		tempOptSysEleMeritLensType.setFlipedBy180Degrees(true);
		returnBestOptSysReplaceIncludingFliped[tempPos] = tempOptSysEleMeritLensType;
		// debug
		oftenUse::print(returnBestOptSysReplaceIncludingFliped[tempPos].getOptSysEle(), 550.0);
		++tempPos;
	}

	return returnBestOptSysReplaceIncludingFliped;
}

OpticalSystemElement LensReplaceAndOptimize::getBestReplacedOpticalSystem()
{
	return mBestReplacedOptSysEle;
}

void LensReplaceAndOptimize::saveBestParameterCatalogLensForReplace(unsigned int numberLensToReplace)
{
	mBestCatalogLensesForReplace[numberLensToReplace] = mBestLensToReplace_vec_includingFlipedLenses[mPosBestMeritVal];
}

// print best parameter catalog lens for replace
void LensReplaceAndOptimize::printBestParameterCatalogForReplace()
{
	unsigned int numberReplacedLenses = mBestCatalogLensesForReplace.size();
	OptSysEle_Merit_LensType tempLensInCatalog{};

	for (unsigned int i = 0; i < numberReplacedLenses; ++i)
	{
		tempLensInCatalog = mBestCatalogLensesForReplace[i];
		std::cout << "lens number: " << '\t' << i << std::endl;
		std::cout << "catalog: " << '\t' << tempLensInCatalog.getLensCatalog() << std::endl;
		std::cout << "number: " << '\t' << tempLensInCatalog.getCatalogNumber() << std::endl;
		std::cout << "check f: " << '\t' << tempLensInCatalog.getCheckParameters_focalLength() << std::endl;
		std::cout << "check th: " << '\t' << tempLensInCatalog.getCheckParameters_thickness() << std::endl;
		std::cout << "check sh: " << '\t' << tempLensInCatalog.getCheckParameters_semiHeight() << std::endl;
		std::cout << "fliped: " << '\t' << tempLensInCatalog.getFlipedBy180Degrees() << std::endl;
		std::cout << "pos in best lens vec: " << '\t' << tempLensInCatalog.getPositionInBestMatchLensVec() << std::endl;
		std::cout << "" << std::endl;
		std::cout << "______________________" << std::endl;
		std::cout << "" << std::endl;
	}
}

// export best parameter catalog for replace
void LensReplaceAndOptimize::exportBestParameterCatalogForReplaceTXT(std::string locationTXT, std::string nameTXT)
{
	// clear the file
	inportExportData::clearDataInTXT(locationTXT, nameTXT);

	std::string type = ".txt";
	int sizeLocEx = locationTXT.size() - 1;
	char lastCharLocEx = locationTXT[sizeLocEx];
	std::string holeFile;
	if (lastCharLocEx == '/')
	{
		holeFile = locationTXT + nameTXT + type;
	}
	else
	{
		holeFile = locationTXT + "/" + nameTXT + type;
	}

	unsigned int numberReplacedLenses = mBestCatalogLensesForReplace.size();
	OptSysEle_Merit_LensType tempLensInCatalog{};


	std::ofstream file;
	file.open(holeFile, std::ios_base::app);
	if (file.is_open())
	{
		for (unsigned int i = 0; i < numberReplacedLenses; ++i)
		{
			tempLensInCatalog = mBestCatalogLensesForReplace[i];
			file << "______________________" << std::endl;
			file << "lens number: " << '\t' << i << std::endl;
			file << "catalog: " << '\t' << tempLensInCatalog.getLensCatalog() << std::endl;
			file << "number: " << '\t' << tempLensInCatalog.getCatalogNumber() << std::endl;
			file << "check f: " << '\t' << tempLensInCatalog.getCheckParameters_focalLength() << std::endl;
			file << "check th: " << '\t' << tempLensInCatalog.getCheckParameters_thickness() << std::endl;
			file << "check sh: " << '\t' << tempLensInCatalog.getCheckParameters_semiHeight() << std::endl;
			file << "fliped: " << '\t' << tempLensInCatalog.getFlipedBy180Degrees() << std::endl;
			file << "pos in best lens vec: " << '\t' << tempLensInCatalog.getPositionInBestMatchLensVec() << std::endl;
			file << "" << std::endl;
			file << "______________________" << std::endl;
			file << "" << std::endl;
		}

	}
	file.close();

}

// find best replace optical system
void LensReplaceAndOptimize::findBestReplaceOpticalSystem()
{
	// find system with lowest merit value
	real tempMeritVal = mSaveAllBestMeritVal[0];
	mBestMeritVal = mSaveAllBestMeritVal[0];
	int posBestMeritVal = 0;

	for (unsigned int i = 1; i < mSaveAllBestMeritVal.size(); ++i)
	{
		if (tempMeritVal < mBestMeritVal)
		{
			mBestMeritVal = tempMeritVal;
			posBestMeritVal = i;
		}

		tempMeritVal = mSaveAllBestMeritVal[i];
	}

	
	mBestReplacedOptSysEle = mSaveAllBestReplacedOpticalSystem[posBestMeritVal];
	mBestCatalogLensesForReplace = mSaveAllBestLensToReplace_vec_includingFlipedLenses[posBestMeritVal];
	mSaveReplacedSequence = mAllPossibleSequencesInt[posBestMeritVal];
	
}			


// get replaced sequence
std::vector<int> LensReplaceAndOptimize::getReplacedSequence()
{
	return mSaveReplacedSequence;
}

// get best catalog lenese for replace
std::vector<OptSysEle_Merit_LensType> LensReplaceAndOptimize::getBestCatalogLensesForreplace()
{
	return mBestCatalogLensesForReplace;
}

// load sequence
void LensReplaceAndOptimize::loadSequence(std::vector<unsigned int> sequence)
{
	mLoadSequence = sequence;
}

// debug mode
void LensReplaceAndOptimize::turn_ON_DebugMode()
{
	mDebugMode = true;
}
void LensReplaceAndOptimize::turn_OFF_DebugMode()
{
	mDebugMode = false;
}