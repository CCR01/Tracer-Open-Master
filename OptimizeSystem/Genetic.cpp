#include "Genetic.h"
#include "..\RayAiming\RayAiming.h"
#include "..\oftenUseNamespace\oftenUseNamespace.h"
#include "..\FillAptertureStop\FillApertureStop.h"
#include "..\SequentialRayTracing\SequentialRayTracer.h"


structToBuildGeneration::structToBuildGeneration() {}
structToBuildGeneration::~structToBuildGeneration() {}

// surface number
unsigned int structToBuildGeneration::getSurfaceNumber()
{
	return mSurfaceNum;
}
void structToBuildGeneration::setSurfaceNumber(unsigned int surfaceNum)
{
	mSurfaceNum = surfaceNum;
}

// kind parameter var
kindParaOptSys structToBuildGeneration::getKindPara()
{
	return mKindParaVar;
}
void structToBuildGeneration::setKindPara(kindParaOptSys kindPara)
{
	mKindParaVar = kindPara;
}

// value
real structToBuildGeneration::getValue()
{
	return mValue;
}
void structToBuildGeneration::setValue(real value)
{
	mValue = value;
}

// copy
void structToBuildGeneration::copy(structToBuildGeneration strctToBuildGene)
{
	setSurfaceNumber(strctToBuildGene.getSurfaceNumber());
	setKindPara(strctToBuildGene.getKindPara());
	setValue(strctToBuildGene.getValue());
}





defaultParaGenetic::defaultParaGenetic() {}
defaultParaGenetic::~defaultParaGenetic() {}

// start refractiv index
real defaultParaGenetic::getStartRefIndex()
{
	return mStartRefractivIndex;
}

void defaultParaGenetic::setStartRefIndex(unsigned int startRefIndex)
{
	mStartRefractivIndex = startRefIndex;
}
// tolerance withoutMin
real defaultParaGenetic::getToleranceWithoutMIN_Radius()
{
	return mToleranceWithoutMIN;
}
void defaultParaGenetic::setToleranceWithoutMIN(real tolWithoutMIN)
{
	mToleranceWithoutMIN = tolWithoutMIN;
}
// tolerance withoutMax
real defaultParaGenetic::getToleranceWithoutMAX_Radius()
{
	return mToleranceWithoutMAX;
}

void defaultParaGenetic::setToleranceWithoutMAX(real tolWithoutMAX)
{
	mToleranceWithoutMAX = tolWithoutMAX;
}
// max iteration genetic
unsigned int defaultParaGenetic::getMaxInterationsGenetic()
{
	return mMaxIterations;
}
void defaultParaGenetic::setMaxInterationGenetic(unsigned int maxIterations)
{
	mMaxIterations = maxIterations;
}
// merit value stop
real defaultParaGenetic::getDeltaMeritValueStop()
{
	return mDeltaMeritValueStop;
}
void defaultParaGenetic::setDeltaMeritValueStop(real meritValueStop)
{
	mDeltaMeritValueStop = meritValueStop;
}
// tolerance for evaluation
real defaultParaGenetic::getToleranceForEvaluatiion()
{
	return mToleranceForEvaluation;
}
void defaultParaGenetic::setToleranceForEvaluation(real toleranceForEvalu)
{
	mToleranceForEvaluation = toleranceForEvalu;
}
// choose value mode
chooseValueForGenerationMode defaultParaGenetic::getChooseValueMode()
{
	return mChooseValueMode;
}
void defaultParaGenetic::setChooseValueMode(chooseValueForGenerationMode chooseMode)
{
	mChooseValueMode = chooseMode;
}



normalDistributionStruct::normalDistributionStruct() {};
normalDistributionStruct::~normalDistributionStruct() {};

// mean to calc normal distribution
real normalDistributionStruct::getMeanToCalcND()
{
	return mMean_ToCalcNormalDistribution;
}
void normalDistributionStruct::setMeanToCalcND(real mean)
{
	mMean_ToCalcNormalDistribution = mean;
}
// stddev to calc normal distribution
real normalDistributionStruct::getStddevToCalcND()
{
	return mStddev_ToCalcNormalDistribution;
}
void normalDistributionStruct::setStddevToCalcND( real stddev)
{
	mStddev_ToCalcNormalDistribution = stddev;
}


Genetic::Genetic() : 
	mDistribution(0.0, 300.0)
{
	
};
Genetic::Genetic(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, unsigned int population):
	mOpticalSystemEle_initial(optSysEle),
	mFields_vec(fields),
	mWavelength_vec(wavelengths),
	mRings(rings),
	mArms(arms),
	mPopulation(population),
	mDistribution(0.0, 300.0)
{
	loadDefaultPra();
	buildOptSys_LLT_wave_vec();
	mParameterVar.loadSystemParameter(mOpticalSystemEle_initial);
	resizeAllRelevantStdVectorsAndCalcConst();
	loadWithoutMinMaxDefault();
	loadThicknessParameter();

}
Genetic::Genetic(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, unsigned int /*populatuion*/ population, /*default parameter*/ defaultParaGenetic defaultParameterGenetic) :
	mOpticalSystemEle_initial(optSysEle),
	mFields_vec(fields),
	mWavelength_vec(wavelengths),
	mRings(rings),
	mArms(arms),
	mPopulation(population),
	mDistribution(0.0, 300.0),
	mDefaultParaGenetic(defaultParameterGenetic)
{
	buildOptSys_LLT_wave_vec();
	mParameterVar.loadSystemParameter(mOpticalSystemEle_initial);
	resizeAllRelevantStdVectorsAndCalcConst();
	loadWithoutMinMaxDefault();
	loadThicknessParameter();
}

void Genetic::buildAndLoad(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, unsigned int /*populatuion*/ population, /*default parameter*/ defaultParaGenetic defaultParameterGenetic)
{
	mOpticalSystemEle_initial = optSysEle;
	mFields_vec = fields;
	mWavelength_vec = wavelengths;
	mRings = rings;
	mArms = arms;
	mPopulation = population;
	mDefaultParaGenetic = defaultParameterGenetic;

	buildOptSys_LLT_wave_vec();
	mParameterVar.loadSystemParameter(mOpticalSystemEle_initial);
	resizeAllRelevantStdVectorsAndCalcConst();
	loadWithoutMinMaxDefault();
	loadThicknessParameter();
}

Genetic::~Genetic() {};

void Genetic::loadDefaultPra()
{
	mDefaultParaGenetic.setStartRefIndex(1.0);
	mDefaultParaGenetic.setToleranceWithoutMIN(-0.5);
	mDefaultParaGenetic.setToleranceWithoutMAX(0.5);
	mDefaultParaGenetic.setMaxInterationGenetic(10);
	mDefaultParaGenetic.setDeltaMeritValueStop(0.1);
	mDefaultParaGenetic.setToleranceForEvaluation(0.001);
	mDefaultParaGenetic.setChooseValueMode(cleverSamplingMode);
}


void Genetic::buildOptSys_LLT_wave_vec()
{
	mNumOptSys = mWavelength_vec.size();
	mChangedOptSys_LLT_vec.resize(mNumOptSys);

	OpticalSystem_LLT tempOptSys;

	for (unsigned int i = 0; i < mNumOptSys; ++i)
	{
		mOpticalSystemEle_initial.setRefractiveIndexAccordingToWavelength(mWavelength_vec[i]);

		tempOptSys = mOpticalSystemEle_initial.getOptSys_LLT_buildSystem();
		mChangedOptSys_LLT_vec[i] = tempOptSys;
	}

}

void Genetic::resizeAllRelevantStdVectorsAndCalcConst()
{
	// size optical system
	mSizeOptSys = mOpticalSystemEle_initial.getPosAndElement().size();
	// position of last surface in optical system
	mPosLastSurface = mSizeOptSys - 1;

	// weight wavelength default
	unsigned int numWavelength = mWavelength_vec.size();
	mWeightWavelenght_vec.resize(numWavelength); 
	std::fill(mWeightWavelenght_vec.begin(), mWeightWavelenght_vec.end(), 1);

	// weight field default
	mNumFieldPoints = mFields_vec.size();
	mWeightFields_vec.resize(mNumFieldPoints); // --
	std::fill(mWeightFields_vec.begin(), mWeightFields_vec.end(), 1);

	// build defautl light
	mDefaultLight.setIntensity(1.0);
	mDefaultLight.setJonesVector({ 1.0,1.0,1.0,1.0 });
	mDefaultLight.setTypeLight(typeLight::typeLightRay);
	mDefaultLight.setWavelength(550.0);

	// vector with merit values
	mAllMeritVal.resize(mPopulation);
	mAllFitnessVal.resize(mPopulation);

	mNumVar = mParameterVar.getAllParaWithVar().size();

	mFirstGenerationVec.resize(mPopulation);
	mSecondGenerationVec.resize(mPopulation);
	resizeVecToBuildGenerations();
	
	mWithoutMinMax.resize(mNumVar);

	mEvaluateSystem.resize(mPopulation);

	mSaveAllBestMeritValues.reserve(mDefaultParaGenetic.getMaxInterationsGenetic());
	mSaveAllBestMeritValues.push_back(oftenUse::getInfReal());

	mCheckToEvaluateVec.resize(mNumVar);

	mTempStructToBuildGeneration_vec.resize(mNumVar);

	mThickness_vec.resize(mPosLastSurface);

	mNewPosition.setX(0.0);
	mNewPosition.setY(0.0);
	mNewPosition.setZ(0.0);

	mNormalDistribution.setMeanToCalcND(0.0);
	mNormalDistribution.setStddevToCalcND(300.0);


}

// resize vector to build generations
void Genetic::resizeVecToBuildGenerations()
{
	for (unsigned int i = 0; i < mPopulation; ++i)
	{
		mFirstGenerationVec[i].resize(mNumVar);
		mSecondGenerationVec[i].resize(mNumVar);
	}
}


real Genetic::calculateMeritVal_RMS(const VectorStructR3& fieldPoint)
{
	real returnMerit_RMS{};
	FillApertureStop fillAperStop(mChangedOptSys_LLT_vec[0], mRings, mArms);
	unsigned int tempWeightWavelengh;

	// ray aiming
	RayAiming rayAiming(mChangedOptSys_LLT_vec[0]);
	rayAiming.loadImportantInfosForRayAiming();

	std::vector<LightRayStruct> tempAimedLightRays{};
	SequentialRayTracing seqTrace;
	seqTrace.setTraceToSurface(mPosLastSurface);

	std::vector<VectorStructR3> tempInterPoints;
	std::vector<VectorStructR3> allInterPoints;

	for (unsigned int i = 0; i < mNumOptSys; ++i)
	{
		tempWeightWavelengh = mWeightWavelenght_vec[i];
		tempAimedLightRays = rayAiming.rayAimingMany_obj(fillAperStop.getPointsInAS(), fieldPoint, mDefaultLight, mDefaultParaGenetic.getStartRefIndex());

		// trace ray
		seqTrace.setOpticalSystem(mChangedOptSys_LLT_vec[i]);
		seqTrace.seqRayTracingWithVectorOfLightRays(tempAimedLightRays);

		rayAiming.setOpticalSystem_LLT(mChangedOptSys_LLT_vec[i]);
	}

	// check for vignetting
	real numberExpecteInterPoints = fillAperStop.getPointsInAS().size();
	std::vector<VectorStructR3> interPoints_vec_lastSurface = seqTrace.getAllInterPointsAtSurface_i_filtered(mPosLastSurface);


	real numberInterPoints = interPoints_vec_lastSurface.size() / mNumOptSys;

	// just for debugging
	//std::cout << "number inter points last surface: " << numberInterPoints << std::endl;

	if (std::abs(numberExpecteInterPoints - numberInterPoints) <= 0.0001)
	{
		Spot spot(interPoints_vec_lastSurface, interPoints_vec_lastSurface[0]);
		returnMerit_RMS = spot.getRMS_µm();
	}
	else // there is vignetting
	{
		returnMerit_RMS = oftenUse::getInfReal();

	}

	return returnMerit_RMS;
}


// randomize a number between min and max 
real Genetic::randomNumberReal(real min, real max)
{
	real f = (real)rand() / RAND_MAX;
	return min + f * (max - min);
}

// generate values for generations
void Genetic::generateValuesFor_FIRST_Generations()
{
	unsigned int tempSurfaceNum{};
	real tempValue{};
	real tempMinVal{};
	real tempWithoutMin{};
	real tempMaxVal{};
	real tempWithoutMax{};
	kindParaOptSys tempKindPara{};
	structToBuildGeneration tempStructToBuildGeneration;

	for(unsigned int i = 0; i<mPopulation;++i)
	{
		for (unsigned int j = 0; j < mNumVar; ++j)
		{
			tempSurfaceNum = mParameterVar.getAllSurfaceNumWithVar()[j];
			tempMinVal = mParameterVar.getAllMinVar()[j];
			tempMaxVal = mParameterVar.getAllMaxVar()[j];
			tempKindPara = mParameterVar.getAllParaWithVar()[j];
			tempWithoutMin = mWithoutMinMax[j].getWithoutMin();
			tempWithoutMax = mWithoutMinMax[j].getWithoutMax();

			if (tempKindPara == radiusVar)
			{

				tempValue = getNumberToBuildOptSys(tempMinVal, tempMaxVal);


				tempValue = checkValueRadius(tempValue, tempMinVal, tempWithoutMin, tempMaxVal, tempWithoutMax);

				// just for debugging
				// std::cout << "radius temp value: " << tempValue << std::endl;

				tempStructToBuildGeneration.setSurfaceNumber(tempSurfaceNum);
				tempStructToBuildGeneration.setKindPara(radiusVar);
				tempStructToBuildGeneration.setValue(tempValue);

				mFirstGenerationVec[i][j] = tempStructToBuildGeneration;

			}

			if (tempKindPara == thickness_Var)
			{

				tempValue = randomNumberReal(tempMinVal, tempMaxVal);
				tempValue = checkValueRadius(tempValue, tempMinVal, tempWithoutMin, tempMaxVal, tempWithoutMax);
				// just for debugging
				// std::cout << "thickness temp value: " << tempValue << std::endl;

				tempStructToBuildGeneration.setSurfaceNumber(tempSurfaceNum);
				tempStructToBuildGeneration.setKindPara(thickness_Var);
				tempStructToBuildGeneration.setValue(tempValue);

				mFirstGenerationVec[i][j] = tempStructToBuildGeneration;

			}
		}

		mEvaluateSystem[i] = true;
 	}

}

// load without min and Max default
void Genetic::loadWithoutMinMaxDefault()
{
	real tempSemiHeight;
	unsigned int tempSurfaceNum;

	real tempWithoutMIN;
	real tempWithoutMAX;

	typeModifier tempTypeModi_Radius;
	typeModifier tempTypeModi_Thickness;
	unsigned int counterVar = 0;

	for (unsigned int i = 0; i < mSizeOptSys; ++i)
	{
		
		tempSemiHeight = mChangedOptSys_LLT_vec[0].getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getSemiHeight();
		tempTypeModi_Radius = mOpticalSystemEle_initial.getPosAndElement()[i].getElementInOptSys_ptr()->getRadiusTypeModifier();
		tempTypeModi_Thickness = mOpticalSystemEle_initial.getPosAndElement()[i].getElementInOptSys_ptr()->getPointTypeModifier_Z();

		if(tempTypeModi_Radius == typeModifierVariable)
		{ 
			tempWithoutMIN = -tempSemiHeight - mDefaultParaGenetic.getToleranceWithoutMIN_Radius();
			if (tempWithoutMIN > 0.0)
			{
				tempWithoutMIN = 0.0;
			}
			mWithoutMinMax[counterVar].setWithoutMin(tempWithoutMIN);
			
			tempWithoutMAX = tempSemiHeight - mDefaultParaGenetic.getToleranceWithoutMAX_Radius();
			if (tempWithoutMAX < 0.0)
			{
				tempWithoutMAX = 0.0;
			}
			mWithoutMinMax[counterVar].setWithoutMax(tempWithoutMAX);

			++counterVar;
		}

		if (tempTypeModi_Thickness == typeModifierVariable)
		{
			mWithoutMinMax[counterVar].setWithoutMin(0.0);
			mWithoutMinMax[counterVar].setWithoutMax(0.0);
			++counterVar;
		}


	}
}

// check if radisu is valide
real Genetic::checkValueRadius(real val, real min, real withoutMin, real max, real withoutMax)
{
	if (val < withoutMin)
	{
		return val;
	}
	else if (val > withoutMax)
	{
		return val;
	}
	if (val < 0)
	{
		return val + withoutMin;
	}
	else
	{
		return val + withoutMax;
	}

}

// build the generations and evaluate
void Genetic::buildTheGenerationsAndEvaluate()
{
	   	for (unsigned int i = 0; i < mPopulation; ++i)
		{
		
		
			
		// just for debugging
		// mChangedOptSys_LLT_vec[0].printAllOptSysParameter_LLT(mChangedOptSys_LLT_vec[0]);

		if (mEvaluateSystem[i])
		{
			buildTheOpticalSystem(i);
			mAllMeritVal[i] = calcMeritVal();
		}

		else
		{
			mAllMeritVal[i] = mMeritVal_bestSystem;
		}
		
	}
}

// do the genetic process
void Genetic::doTheGeneticProcess()
{
	
	// just for debugging 
	std::cout << "build first generation" << std::endl;
	generateValuesFor_FIRST_Generations();
	buildTheGenerationsAndEvaluate();
	bool checker = true;
	findBestSystemNum();
	unsigned int iterations = 1;
	unsigned int selectetSystemNum{};

	while (checker)
	{
		// just for debugging
		std::cout << "generation number: " << iterations << std::endl;
				
		setEvaluateSystemFalse();

		calcFitnessValAndSum();
		

		for (unsigned int i = 0; i < mPopulation; ++i)
		{
			selectetSystemNum = selectSystemInGeneration();
			geneticProcess(selectetSystemNum, i);
		}

		mFirstGenerationVec = mSecondGenerationVec;
		buildTheGenerationsAndEvaluate();
		findBestSystemNum();

		++iterations;
		checker = checkWhileGenetic(iterations);
		
	}
	
	findBestSystemNum();
	buildTheOpticalSystem(mNumBestOptSysInGeneration);
	mOptimizedOpticalSytemElement = mOpticalSystemEle_initial.convertOptSys_LLT_T0_OptSys_HLT(mOpticalSystemEle_initial, mChangedOptSys_LLT_vec[0]);

}

// change radius to value
void Genetic::changeRadiusToValue(unsigned int surfaceNum, real value)
{
	for (unsigned int i = 0; i < mNumOptSys; ++i)
	{
		mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNum].getSurfaceInterRay_ptr()->setRadius(value);
	}
}

// change radius to value and flip direction
void Genetic::changeRadiusAndFlipDierction(unsigned int surfaceNum, real value)
{
	real currentRefIndex_A;
	real currentRefIndex_B;
	VectorStructR3 curDirection;

	for (unsigned int i = 0; i < mNumOptSys; ++i)
	{
		currentRefIndex_A = mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNum].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
		currentRefIndex_B = mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNum].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
		curDirection = mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNum].getSurfaceInterRay_ptr()->getDirection();

		mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNum].getSurfaceInterRay_ptr()->setRadius(std::abs(value));
		mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNum].getSurfaceInterRay_ptr()->setRefractiveIndexSide_A(currentRefIndex_B);
		mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNum].getSurfaceInterRay_ptr()->setRefractiveIndexSide_B(currentRefIndex_A);
		mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNum].getSurfaceInterRay_ptr()->setDirection(-1.0 * curDirection);
	}
}

real Genetic::calcMeritVal()
{
	real tempRMS = 0.0;
	real sumMerit = 0.0;

	for (unsigned int i = 0; i < mNumFieldPoints; ++i)
	{
		tempRMS = mWeightFields_vec[i] * calculateMeritVal_RMS(mFields_vec[i]);
		sumMerit = tempRMS + sumMerit;
	}

	return sumMerit;
	
}

// find best system
void Genetic::findBestSystemNum()
{
	std::vector<real>::iterator result = std::min_element(mAllMeritVal.begin(), mAllMeritVal.end());
	mNumBestOptSysInGeneration = std::distance(mAllMeritVal.begin(), result);

	mMeritVal_bestSystem = mAllMeritVal[mNumBestOptSysInGeneration];
	// just for debugging
	std::cout << "best merit value: " << mMeritVal_bestSystem << std::endl;

	mSaveAllBestMeritValues.push_back(mMeritVal_bestSystem);
}

// select system in generation
unsigned int Genetic::selectSystemInGeneration()
{
	real randomNum = randomNumberReal(0.0, mSumAllFitnessVal);
	real checkVal = randomNum;
	int systemNum = 0.0;


	for(systemNum; systemNum<mPopulation;++systemNum)
	{
		checkVal = checkVal - mAllFitnessVal[systemNum];

		if (checkVal < 0.0)
		{
			return systemNum;
		}
	} 


	return systemNum - 1;
}

// genetic process
void Genetic::geneticProcess(unsigned int selectetSystemNum, unsigned int number)
{

	bool tempCheckToEvaluate;
	real randomNum;

	for (unsigned int i = 0; i < mNumVar; ++i)
	{
		randomNum = randomNumberReal(0.0, 1.0);
		if (randomNum > 0.5) // parent 1 gives the genes to next generation
		{

			tempCheckToEvaluate = checkEvaluateSystem(selectetSystemNum, i);

			mTempStructToBuildGeneration_vec[i].copy(mFirstGenerationVec[selectetSystemNum][i]);
			mCheckToEvaluateVec[i] = tempCheckToEvaluate;

	
		}
		else // parent 2 gives the genes to next generation
		{
			mTempStructToBuildGeneration_vec[i].copy(mFirstGenerationVec[mNumBestOptSysInGeneration][i]);
			mCheckToEvaluateVec[i] = false;
		}
				
	}

	mEvaluateSystem[number] = oftenUse::checkIf_ONE_valueIsTrue(mCheckToEvaluateVec);

	mSecondGenerationVec[number] = mTempStructToBuildGeneration_vec;

}

// set evaluate system false
void Genetic::setEvaluateSystemFalse()
{
	std::fill(mEvaluateSystem.begin(), mEvaluateSystem.begin() , false);
}

bool Genetic::checkWhileGenetic(unsigned int iteration)
{
	real meritBefore = mSaveAllBestMeritValues[iteration - 1];
	if (std::abs(meritBefore - mMeritVal_bestSystem) < mDefaultParaGenetic.getDeltaMeritValueStop())
	{
		return false;
	}

	else if (iteration > mDefaultParaGenetic.getMaxInterationsGenetic())
	{
		return false;
	}

	return true;
}

void Genetic::calcFitnessValAndSum()
{
	for(unsigned int i=0;i<mPopulation;++i)
	{
		mAllFitnessVal[i] = 1 / mAllMeritVal[i];
	}

	mSumAllFitnessVal = 0;
	for (real x : mAllFitnessVal)  mSumAllFitnessVal += x;


}

// check if system has to be evaluated
bool Genetic::checkEvaluateSystem(unsigned int systemNumber, unsigned int variableNum)
{
	//just for debugging
	//std::cout << "system number: " << systemNumber << std::endl;
	//std::cout << "variable number: " << variableNum << std::endl;

	mTempValueParent_1 = mFirstGenerationVec[systemNumber][variableNum].getValue();
	mTempValueParent_2 = mFirstGenerationVec[mNumBestOptSysInGeneration][variableNum].getValue();
		
	//just for debugging
	//std::cout << "temp value parent 1: " << mTempValueParent_1 << std::endl;
	//std::cout << "temp value parent 2: " << mTempValueParent_2 << std::endl;

	if (std::abs(mTempValueParent_1 - mTempValueParent_2) < mDefaultParaGenetic.getToleranceForEvaluatiion())
	{
		return false;
	}

	return true;
}

// build the optical system
void Genetic::buildTheOpticalSystem(unsigned int generationNum)
{
	unsigned int tempSurfaceNum;
	kindParaOptSys tempKindPara;
	real tempVal;
	real tempDirectionZ;

	for (unsigned int j = 0; j < mNumVar; ++j)
	{
		tempSurfaceNum = mFirstGenerationVec[generationNum][j].getSurfaceNumber();
		tempKindPara = mFirstGenerationVec[generationNum][j].getKindPara();
		tempVal = mFirstGenerationVec[generationNum][j].getValue();

		if (tempKindPara == radiusVar)
		{
			tempDirectionZ = mChangedOptSys_LLT_vec[0].getPosAndInteractingSurface()[tempSurfaceNum].getSurfaceInterRay_ptr()->getDirection().getZ();

			if (oftenUse::checkSamePrefixTwoVal(tempDirectionZ, tempVal))
			{
				changeRadiusToValue(tempSurfaceNum, std::abs(tempVal));
			}
			else // value and direction have an other prefix -> flip radius
			{
				changeRadiusAndFlipDierction(tempSurfaceNum, std::abs(tempVal));
			}

		}

		if (tempKindPara == thickness_Var)
		{
			changeThickness_Z_SurfaceTo(tempSurfaceNum, tempVal);
		}
	}
}

// get optimized optical system element
OpticalSystemElement Genetic::getOptimizedOpticalSystemElement()
{
	return mOptimizedOpticalSytemElement;
}

// change thickness surface to
void Genetic::changeThickness_Z_SurfaceTo(unsigned int surfaceNo, real newThickness)
{
	{
		real tempSurface_Pos_Z;
		real tempNewPosNextSurface_Z;
		real deltaThickness;
		unsigned int counter = 1;

		for (unsigned int i = 0; i < mNumOptSys; ++i)
		{
			tempSurface_Pos_Z = mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNo].getSurfaceInterRay_ptr()->getPoint().getZ();
			deltaThickness = newThickness - mThickness_vec[surfaceNo];
			tempNewPosNextSurface_Z = tempSurface_Pos_Z + newThickness;

			while (surfaceNo + counter < mSizeOptSys)
			{
				mNewPosition.setZ(tempNewPosNextSurface_Z);
				mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNo + counter].getSurfaceInterRay_ptr()->setPosition(mNewPosition);
				++counter;
				if (surfaceNo + counter < mSizeOptSys)
				{
					tempNewPosNextSurface_Z = mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNo + counter].getSurfaceInterRay_ptr()->getPoint().getZ();
					tempNewPosNextSurface_Z = tempNewPosNextSurface_Z + deltaThickness;
				}


			}
			counter = 1;
		}

	}
	mThickness_vec[surfaceNo] = newThickness;

	// just for debugging
	// mChangedOptSys_LLT_vec[0].printAllOptSysParameter_LLT(mChangedOptSys_LLT_vec[0]);
}

void Genetic::loadThicknessParameter()
{
	real savePos_Z = mOpticalSystemEle_initial.getPosAndElement()[0].getElementInOptSys_ptr()->getPointElementValue_Z();
	real tempPoint_Z{};
	real tempThickness_Z{};


	for (unsigned int i = 1; i < mSizeOptSys; ++i)
	{
		tempPoint_Z = mOpticalSystemEle_initial.getPosAndElement()[i].getElementInOptSys_ptr()->getPointElementValue_Z();
		tempThickness_Z = tempPoint_Z - savePos_Z;
		mThickness_vec[i - 1] = tempThickness_Z;
		

		savePos_Z = tempPoint_Z;
	}

}

// clever sampling to build optical system
real Genetic::getCleverSampledNumber(real min, real max)
{
	real returnValue{};
	bool checker = true;
	unsigned int counter = 0;

	real randomNumber = randomNumberReal(min, max);

	while(checker)
	{
		if (std::abs(randomNumber) < 10.0)
		{
			return randomNumber;
		}
		else if (std::abs(randomNumber) < 15.0)
		{
			return randomNumberReal(-15.0, 15.0);
		}
		else if (std::abs(randomNumber) < 30.0)
		{
			return randomNumberReal(-30.0, 30.0);
		}
		else if (std::abs(randomNumber) < 50.0)
		{
			return randomNumberReal(-50.0, 50.0);
		}
		else if (std::abs(randomNumber) < 100.0 && counter > 1)
		{
			return randomNumberReal(-100.0, 100.0);
		}
		else if (std::abs(randomNumber) < 200.0 && counter > 2)
		{
			return randomNumberReal(-200.0, 200.0);
		}

		else if (std::abs(randomNumber) < 500.0 && counter > 3)
		{
			return randomNumberReal(-500.0, 500.0);
		}

		else if (std::abs(randomNumber) < 1000.0 && counter > 5)
		{
			return randomNumberReal(-1000.0, 1000.0);
		}
		else if ( counter > 10)
		{
			return randomNumberReal(min, max);
		}

		//randomNumber = randomNumberReal(min, max);

		++counter;
	}

	return returnValue;
}

// get value to build optical system
real Genetic::getNumberToBuildOptSys(real min, real max)
{

	real returnValue;

	switch (mDefaultParaGenetic.getChooseValueMode()) 
	{
		case randomMode:
			returnValue = randomNumberReal(min, max);
			break;

		case cleverSamplingMode:
			returnValue = getCleverSampledNumber(min, max);
			break;

		case normalDistributionMode:
			returnValue = normalDistribution(mNormalDistribution.getMeanToCalcND(), mNormalDistribution.getStddevToCalcND(), min, max);
			break;
			
		case normalDistributionDefaultMode:
			returnValue = defaultNormalDistribution(min, max);
			break;
	}


	return returnValue;

}



// default standed defiation
real Genetic::defaultNormalDistribution(real min, real max)
{
	real returnVal{};
		
	if (max < min)
	{
		std::cout << "max is smaller than min !!!" << std::endl;
		return returnVal;
	}

	while (true) 
	{
		returnVal = mDistribution(mGenerator);
		if (returnVal >= min && returnVal <= max)
		{
			return returnVal;
		}
			
	}
	
	return returnVal;

}


// normal distribution
real Genetic::normalDistribution(real mean, real stddev, real min, real max)
{

	// random device class instance, source of 'true' randomness for initializing random seed
	std::random_device rd;

	// Mersenne twister PRNG, initialized with seed from previous random device instance
	std::mt19937 gen(rd());

	real returnVal{};

	std::normal_distribution<double> distribution(mean, stddev);

	if (max < min)
	{
		std::cout << "max is smaller than min !!!" << std::endl;
		return returnVal;
	}

	while(true)
	{
	returnVal = distribution(gen);

		if (returnVal >= min && returnVal <= max)
		{
			return returnVal;
		}
	}



	return returnVal;
}

real Genetic::getMeritValBestSystem()
{
	return mMeritVal_bestSystem;
}

// ***
// mean to calc normal distribution
real Genetic::getMeanToCalcND()
{
	return mNormalDistribution.getMeanToCalcND();
}
void Genetic::setMeanToCalcND(real mean)
{
	mNormalDistribution.setMeanToCalcND(mean);
}
// stddev to calc normal distribution
real Genetic::getStddevToCalcND()
{
	return mNormalDistribution.getStddevToCalcND();
}
void Genetic::setStddevToCalcND(real stddev)
{
	mNormalDistribution.setStddevToCalcND(stddev);
}
// ***

// ***
// start refractiv index
real Genetic::getStartRefIndex()
{
	return mDefaultParaGenetic.getStartRefIndex();
}
void Genetic::setStartRefIndex(unsigned int startRefIndex)
{
	mDefaultParaGenetic.setStartRefIndex(startRefIndex);
}
// tolerance withoutMin
real Genetic::getToleranceWithoutMIN_Radius()
{
	return mDefaultParaGenetic.getToleranceWithoutMIN_Radius();
}
void Genetic::setToleranceWithoutMIN_Radius(real tolWithoutMIN)
{
	mDefaultParaGenetic.setToleranceWithoutMIN(tolWithoutMIN);
}
// tolerance withoutMax
real Genetic::getToleranceWithoutMAX_Radius()
{
	return mDefaultParaGenetic.getToleranceWithoutMAX_Radius();
}
void Genetic::setToleranceWithoutMAX_Radius(real tolWithoutMAX)
{
	mDefaultParaGenetic.setToleranceWithoutMAX(tolWithoutMAX);
}
// max iteration genetic
unsigned int Genetic::getMaxInterationsGenetic()
{
	return mDefaultParaGenetic.getMaxInterationsGenetic();
}
void Genetic::setMaxInterationGenetic(unsigned int maxIterations)
{
	mDefaultParaGenetic.setMaxInterationGenetic(maxIterations);
}
// merit value stop
real Genetic::getDeltaMeritValueStop()
{
	return mDefaultParaGenetic.getDeltaMeritValueStop();
}
void Genetic::setDeltaMeritValueStop(real meritValueStop)
{
	mDefaultParaGenetic.setDeltaMeritValueStop(meritValueStop);
}
// tolerance for evaluation
real Genetic::getToleranceForEvaluatiion()
{
	return mDefaultParaGenetic.getToleranceForEvaluatiion();
}
void Genetic::setToleranceForEvaluation(real toleranceForEvalu)
{
	mDefaultParaGenetic.setToleranceForEvaluation(toleranceForEvalu);
}
// choose value mode
chooseValueForGenerationMode Genetic::getChooseValueMode()
{
	return mDefaultParaGenetic.getChooseValueMode();
}
void Genetic::setChooseValueMode(chooseValueForGenerationMode chooseMode)
{
	mDefaultParaGenetic.setChooseValueMode(chooseMode);
}
// ***