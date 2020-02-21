#include "OptimizeOpticalSystem.h"
#include "..\FillAptertureStop\FillApertureStop.h"
#include "..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\Analyse\Spot.h"
#include <random>
#include <iostream>
#include <omp.h>
#include <ctime>
#include <limits>
#include <cmath>
#include <math.h>
#include "..\SurfaceElements\ApertureStopElement.h"

#include "..\CompareTwoImagesAndImprove\CompareTwoImagesAndImprove.h"
#include "..\Inport_Export_Data\Inport_Export_Data.h"
//#include "..\ImageSimulation.h"



DistanceAdjustmentStruct::DistanceAdjustmentStruct() {};
DistanceAdjustmentStruct::DistanceAdjustmentStruct(unsigned int postition, real distanceZ, typeModifier typeMod) :
	mPosition(postition),
	mDistanceZ(distanceZ),
	mTypeMod(typeMod)
{};
DistanceAdjustmentStruct::~DistanceAdjustmentStruct() {};

// get position
unsigned int DistanceAdjustmentStruct::getPosition() const
{
	return mPosition;
}
// set position
void DistanceAdjustmentStruct::setPosition(unsigned int const position)
{
	mPosition = position;
}
// get distance
real DistanceAdjustmentStruct::getDistanceZ() const
{
	return mDistanceZ;
}
// set distance Z
void DistanceAdjustmentStruct::setDistance(real const distanceZ)
{
	mDistanceZ = distanceZ;
}
// get type modifier
typeModifier DistanceAdjustmentStruct::getTypeModifier() const
{
	return mTypeMod;
}
// set type modifier
void DistanceAdjustmentStruct::setTypeModifier(typeModifier const typeMod)
{
	mTypeMod = typeMod;
}



void OptimizeParameters::loadDefautSettingOptiParametes()
{

	mStepRadiusLocal = 0.11;
	mStepDistanceLocal = 0.11;
	mStopCriteriaLocal = 0.01;
	maxStepsLocalOpti = 10; // to be prepared from an infinit loop 
	mStopCriteriaGenetic = 0.00001;
	m_minStep_radius = mStepRadiusLocal / (std::pow(2, 8));
	m_minStep_position = mStepDistanceLocal / (std::pow(2, 8));
	counterLocalInterations = 10;
	m_minGapSurfaces = 0.1;
	mCheckAllLocalCombinations = false;
	mRings = 6;
	mArms = 8;


}

void OptimizeParameters::setCheckAllLocalCombinations(bool checkAllLocalCombination)
{
	mCheckAllLocalCombinations = checkAllLocalCombination;

}

real OptimizeParameters::getStepRadiusLocal() const
{
	return mStepRadiusLocal;
}
real OptimizeParameters::getStepDistanceLocal() const
{
	return mStepDistanceLocal;
}
real OptimizeParameters::getStopCtiterialLocal() const
{
	return mStopCriteriaLocal;
}
real OptimizeParameters::getMaxStepsLocalOpti() const
{
	return maxStepsLocalOpti;
}
real OptimizeParameters::getStopCriteria_genetic() const
{
	return mStopCriteriaGenetic;
}
real OptimizeParameters::getMinGapSurface() const
{
	return m_minGapSurfaces;
}
bool OptimizeParameters::getCheckAllLocalComb() const
{
	return mCheckAllLocalCombinations;
}
unsigned int OptimizeParameters::get_gettingWorseGeneticLimit() const
{
	return gettingWorseGeneticLimit;
}
unsigned int OptimizeParameters::getCounterLocalInterations() const
{
	return counterLocalInterations;
}

void OptimizeParameters::setMinStep_radius(real minStep)
{
	m_minStep_radius = minStep;
}


real OptimizeParameters::getMinStep_radius() const
{
	return m_minStep_radius;
}


void OptimizeParameters::setMinStep_position(real minStep)
{
	m_minStep_position = minStep;
}


real OptimizeParameters::getMinStep_position() const
{
	return m_minStep_position;
}

unsigned int OptimizeParameters::getRings() const
{
	return mRings;
}
unsigned int OptimizeParameters::getArms() const
{
	return mArms;
}

OptSysEleAndMeritStruct::OptSysEleAndMeritStruct() {};
OptSysEleAndMeritStruct::OptSysEleAndMeritStruct(OpticalSystemElement optSysEle, real merit) :
	mOptSysEle(optSysEle),
	mMerit(merit)
{};
OptSysEleAndMeritStruct::~OptSysEleAndMeritStruct() {};

// get optical system
OpticalSystemElement OptSysEleAndMeritStruct::getOptSysEle() const
{
	return mOptSysEle;
}
// set optical system
void OptSysEleAndMeritStruct::setOptSysEle(OpticalSystemElement const optSysEle)
{
	mOptSysEle = optSysEle;
}
// get merit
real OptSysEleAndMeritStruct::getMerit() const
{
	return mMerit;
}
// set merit
void OptSysEleAndMeritStruct::setMerit(real const merit)
{
	mMerit = merit;
}


void OptimizeParameters::setStepsLocalRadius(real stepRadiusLocal) {
	mStepRadiusLocal = stepRadiusLocal;
}
void OptimizeParameters::setCriterialLocal(real criterialocal) {
	mStopCriteriaLocal = criterialocal;
}
void OptimizeParameters::setCriterialGenetic(real criteriagenetic) {
	mStopCriteriaGenetic = criteriagenetic;
}
void OptimizeParameters::setMinGapSurfaces(real minGapSur)
{
	m_minGapSurfaces = minGapSur;
}
void OptimizeParameters::setRings(unsigned int rings)
{
	mRings = rings;
}
void OptimizeParameters::setArms(unsigned int arms)
{
	mArms = arms;
}


void MeritConfiguration::setImageQuality_weight(real imageQuality_weight)
{
	mImageQuality_Weight = imageQuality_weight;
}



void MeritConfiguration::DEFAFULT_SETTINGS()
{

	mRMS_Weight = 1.0;

	mEFL_Target = std::numeric_limits<double>::quiet_NaN();
	mEFL_Weight = std::numeric_limits<double>::quiet_NaN();

	mEXPP_Target = std::numeric_limits<double>::quiet_NaN();
	mEXPP_Weight = std::numeric_limits<double>::quiet_NaN();

	mEXPD_Target = std::numeric_limits<double>::quiet_NaN();
	mEXPD_Weight = std::numeric_limits<double>::quiet_NaN();

	mImageQuality_Weight = std::numeric_limits<double>::quiet_NaN();

}

void MeritConfiguration::setRMSWeight(real rms_weight) {
	mRMS_Weight = rms_weight;
}

real MeritConfiguration::getRMSWeight()
{
	return mRMS_Weight;
}

void MeritConfiguration::setEFL_targetValue(real efl_target) 
{
	mEFL_Target = efl_target;
}
real MeritConfiguration::getEFL_targetValue()
{
	return mEFL_Target;
}
void MeritConfiguration::setEFL_weight(real efl_weight) 
{
	mEFL_Weight = efl_weight;
}
real MeritConfiguration::getEFL_weight()
{
	return mEFL_Weight;
}

void MeritConfiguration::setEXPP_targetValue(real expp_target) 
{
	mEXPP_Target = expp_target;
}
real MeritConfiguration::getEXPP_targetValue()
{
	return mEXPP_Target;
}

void MeritConfiguration::setEXPP_weight(real expp_weight) {
	mEXPP_Weight = expp_weight;
}
real MeritConfiguration::getEXPP_weight()
{
	return mEXPP_Weight;
}

void MeritConfiguration::setEXPD_targetValue(real expd_target) {
	mEXPD_Target = expd_target;
}
real MeritConfiguration::getEXPD_targetValue()
{
	return mEXPD_Target;
}

void MeritConfiguration::setEXPD_weight(real expd_weight) 
{
	mEXPD_Weight = expd_weight;
}
real MeritConfiguration::getEXPD_weight()
{
	return mEXPD_Weight;
}

void OptimizeOpticalSystem::add_IMAGEQuality_Weight(real IQ_weight)
{
	mMF_Config.setImageQuality_weight(IQ_weight);
}
real MeritConfiguration::getImageQuality_weight()
{
	return mImageQuality_Weight;
}

void FieldAndLightStruct::DEFAULT_SETTINGS() {

	JonesVector_LLT tempJones(0.0, 0.0, 0.0, 0.0);
	typeLight tempType = typeLightRay;
	Light_LLT tempLight_LLT(550.0, 1.0, tempJones, tempType, 1);

	mLight_LLT_vec.push_back(tempLight_LLT);

	mFieldVector.push_back({ 0.0,0.0,0.0 });
	mWeightingFieldVector.push_back(1.0);
}

void FieldAndLightStruct::setLight_LLT(Light_LLT light_LLT)
{
	mLight_LLT_vec.at(0) = light_LLT;
}

void FieldAndLightStruct::setFieldAndWeight(VectorStructR3 field, real weight)
{
	mFieldVector.at(0) = field;
	mWeightingFieldVector.at(0) = weight;
}

void FieldAndLightStruct::addLight(Light_LLT light_LLT) 
{
	mLight_LLT_vec.push_back(light_LLT);
}

void FieldAndLightStruct::addField(VectorStructR3 field, real weight) 
{
	mFieldVector.push_back(field);
	mWeightingFieldVector.push_back(weight);
}

std::vector<Light_LLT> FieldAndLightStruct::getLightVec() const
{
	return mLight_LLT_vec;
}

std::vector<VectorStructR3>	FieldAndLightStruct::getFieldVec() const
{
	return mFieldVector;
}


std::vector<real> FieldAndLightStruct::getWeightFieldVec() const
{
	return mWeightingFieldVector;
}

OptimizeOpticalSystem::OptimizeOpticalSystem() {};

OptimizeOpticalSystem::OptimizeOpticalSystem(OpticalSystemElement optSysEle, localStart localOptStart) :
	mOptSysElementStart(optSysEle),
	mLocalStart(localOptStart)
{
	mFWL_Config.DEFAULT_SETTINGS();
	mMF_Config.DEFAFULT_SETTINGS();
	mOP_Config.loadDefautSettingOptiParametes();
	calcPosApertureStop();
	calcDistanceAdjustment();
	calcRadiusVariabe();
	calcPointVariable();
	mIsOneRadiusVariable = checkIfOneRadiusIsVariabel();
	mIsOneDistanceVariable = checkIfOneDistanceIsVariable();
};

OptimizeOpticalSystem::~OptimizeOpticalSystem() {};

OptimizeOpticalSystem::OptimizeOpticalSystem(OpticalSystemElement optSysEle, real length, unsigned int population, real mutationRate, localStart localOptStart) :
	mOptSysElementStart(optSysEle),
	mMutationRate(mutationRate),
	mPopulation(population),
	mLengthOpticalSystem(length),
	mLocalStart(localOptStart)
{
	mFWL_Config.DEFAULT_SETTINGS();
	mMF_Config.DEFAFULT_SETTINGS();
	mOP_Config.loadDefautSettingOptiParametes();
	calcPosApertureStop();
	calcDistanceAdjustment();
	calcRadiusVariabe();
	calcPointVariable();
	mIsOneRadiusVariable = checkIfOneRadiusIsVariabel();
	mIsOneDistanceVariable = checkIfOneDistanceIsVariable();
	mGenerationOfSystems.reserve(mPopulation);
	mSecondGeneration.reserve(mPopulation);

	mGenerationOfSystems.resize(mPopulation);
	mSecondGeneration.resize(mPopulation);
	mMERIT_VALUES.resize(mPopulation);

}

OptimizeOpticalSystem::OptimizeOpticalSystem(OpticalSystemElement optSysEle, unsigned int population, real mutationRate, localStart localOptStart) :
	mOptSysElementStart(optSysEle),
	mMutationRate(mutationRate),
	mPopulation(population),
	mLocalStart(localOptStart)
{
	mFWL_Config.DEFAULT_SETTINGS();
	mMF_Config.DEFAFULT_SETTINGS();
	mOP_Config.loadDefautSettingOptiParametes();

	//mOptSysElementStart.setRefractiveIndexAccordingToWavelength(mFWL_Config.getLightVec().at(0).getWavelength());

	mLengthOpticalSystem = calcLengthOptSysEle(mOptSysElementStart);
	calcPosApertureStop();
	calcDistanceAdjustment();
	calcRadiusVariabe();
	calcPointVariable();
	mIsOneRadiusVariable = checkIfOneRadiusIsVariabel();
	mIsOneDistanceVariable = checkIfOneDistanceIsVariable();
	mGenerationOfSystems.reserve(mPopulation);
	mSecondGeneration.reserve(mPopulation);

	mGenerationOfSystems.resize(mPopulation);
	mSecondGeneration.resize(mPopulation);
	mMERIT_VALUES.resize(mPopulation);
}

// calc length optical system
real OptimizeOpticalSystem::calcLengthOptSysEle(OpticalSystemElement optSysEle)
{
	unsigned int numberSurfaces = optSysEle.getPosAndElement().size() - 1;
	real zPosLastSurface = optSysEle.getPosAndElement().at(numberSurfaces).getElementInOptSys_ptr()->getPointElementValue_Z();

	return zPosLastSurface;
}

void OptimizeOpticalSystem::add_FieldAndWeight(VectorStructR3 field, real weight) 
{
	mFWL_Config.addField(field, weight);
}

void OptimizeOpticalSystem::set_Field(VectorStructR3 field, real weight) 
{
	mFWL_Config.setFieldAndWeight(field, weight);
}

void OptimizeOpticalSystem::add_Light(Light_LLT light)
{
	mFWL_Config.addLight(light);
}


void OptimizeOpticalSystem::set_Light(Light_LLT light)
{
	mFWL_Config.setLight_LLT(light);
}

void OptimizeOpticalSystem::add_TargetEFL(real EFL_target, real EFL_weight) 
{
	mMF_Config.setEFL_targetValue(EFL_target);
	mMF_Config.setEFL_weight(EFL_weight);
}

//void OptimizeOpticalSystem::add_RMSWeight(real RMS_weight) {
//	mMF_Config.SET_RMS_WEIGHT(RMS_weight);
//}

void OptimizeOpticalSystem::add_TargetEXPP(real EXPP_target, real EXPP_weight) {
	mMF_Config.setEXPP_targetValue(EXPP_target);
	mMF_Config.setEXPP_weight(EXPP_weight);
}

void OptimizeOpticalSystem::add_TargetEXPD(real EXPD_target, real EXPD_weight) {
	mMF_Config.setEXPD_targetValue(EXPD_target);
	mMF_Config.setEXPD_weight(EXPD_weight);
}



real OptimizeOpticalSystem::getApertureHeight()
{
	return mOptSysElementStart.getPosAndElement().at(mPositionApertureStop).getElementInOptSys_ptr()->getSemiHeightElementValue();
}



real OptimizeOpticalSystem::getApertureDirection_Z()
{
	return mOptSysElementStart.getPosAndElement().at(mPositionApertureStop).getElementInOptSys_ptr()->getDirectionElementValue_Z();
}

real OptimizeOpticalSystem::getAperturePoint_Z()
{
	return mOptSysElementStart.getPosAndElement().at(mPositionApertureStop).getElementInOptSys_ptr()->getPointElementValue_Z();
}


void OptimizeOpticalSystem::printOptSysEle(OpticalSystemElement OptSysEle)
{
	for (int j = 0; j < OptSysEle.getSizeOptSys(); j++)
	{
		OptSysEle.getPosAndElement().at(j).getElementInOptSys_ptr()->print();
	}

}

void OptimizeOpticalSystem::calculateCardinalPoints(OpticalSystemElement system)
{
	
	unsigned int lenghtOptSys = system.getOpticalSystem_LLT().getPosAndInteractingSurface().size();

	for (unsigned int i = 0; i < lenghtOptSys; i++)
	{
		// TOIT
	}

	OpticalSystem_LLT systemLLT(system.getPosAndIntersection_LLT(), system.getPosAndInteraction_LLT());
	CardinalPoints systemCPs(systemLLT);
	mEFL_LOCAL = systemCPs.calcEFL();
	mEXPP_LOCAL = systemCPs.calcExitPupilPost();
	mEXPD_LOCAL = systemCPs.calcDiameterExitPupil();
}




FieldAndLightStruct OptimizeOpticalSystem::getFWL_S()
{
	return mFWL_Config;
}

//randomizing a number between two values
real OptimizeOpticalSystem::randomNumber(real min, real max) {

	real f = (real)rand() / RAND_MAX;

	return min + f * (max - min);

}

int OptimizeOpticalSystem::randomIndex(int min, int max) {
	int f = (int)rand() / RAND_MAX;
	return min + f * (max - min);
}





//randomize a optical system vector with a N population of optical systems, based on a start optical system

void OptimizeOpticalSystem::RANDOMIZE_SYSTEMS()
{
	//mGenerationOfSystems.clear();
	//mGenerationOfSystems.resize(mPopulation);

	for (int i = 0; i < mPopulation; i++)
	{
		unsigned int size = mOptSysElementStart.getSizeOptSys();
		OpticalSystemElement newOpticalSystem;


		std::shared_ptr<Element_CR> tempElement;


		real positionBefore;
		real tempPosition;

		real currentLength = 0.0;
		real push = 0.0;

		real beforePointZ = 0.0;
		real tempPontZ;
		real setPointZ;

		real bananePoint;
		real elefantPoint = 0.0;
		real affeDis;



		for (int j = 0; j < size; j++)
		{

			tempElement = mOptSysElementStart.getPosAndElement().at(j).getElementInOptSys_ptr()->generate_ptr();
			real tempPointZ = tempElement->getPointElementValue_Z();
			real tempDistanceZ = tempPointZ - beforePointZ;

			if (mDistanceAdjustment.at(j).getTypeModifier() == typeModifierFixed)
			{
				setPointZ = beforePointZ + mDistanceAdjustment.at(j).getDistanceZ();
				tempElement->setPointElementValue_Z(setPointZ);
				tempDistanceZ = mDistanceAdjustment.at(j).getDistanceZ();
			}

			if (tempDistanceZ <= 0.0) // if there is a negative distance
			{
				tempDistanceZ = -1 * tempDistanceZ + mOP_Config.getMinGapSurface();
				tempElement->pushPosition(tempDistanceZ);
			}




			beforePointZ = tempElement->getPointElementValue_Z();

			newOpticalSystem.fillPosAndElementAndInteraction(j, tempElement, mOptSysElementStart.getPosAndInteraction_LLT().at(j).getInteractionAtSur_ptr());
			// /*minimum position*/currentLength = tempElement->getPosition();
		}
		newOpticalSystem.convertHLTSurfacesToLLTSurfaces();
		mGenerationOfSystems.at(i) = newOpticalSystem;
	}



}



void OptimizeOpticalSystem::MERIT_CALCULATE()
{
	std::cout << "calculate merit values" << std::endl;
	real calculatedMerit;

	for (int i = 0; i < mGenerationOfSystems.size(); i++)
	{


		calculatedMerit = calculateMerit(mGenerationOfSystems.at(i).getOpticalSystemElement());
		//calculatedMerit = numerator / (EFL_denominator*EXPP_denominator*EXPD_denominator);

		if (std::isnan(calculatedMerit))
		{
			// if it is not possible to calculate the merit value
			calculatedMerit = 9999999999999999.0;
		}


		mMERIT_VALUES.at(i) = calculatedMerit;
	}

}



//calculating the Fitness of all the members based on RMS values
void OptimizeOpticalSystem::FITNESS_CALCULATE() {
	std::cout << "calculate fitness values" << std::endl;
	mFITNESS_VALUES.resize(mPopulation);
	real tempFitness;
	for (unsigned int i = 0; i < mPopulation; i++)
	{
		   
		tempFitness = (1 / mMERIT_VALUES.at(i));
		mFITNESS_VALUES.at(i) = tempFitness;
	}

}




void OptimizeOpticalSystem::calculateSumFitnessValuse()
{
	mSumFitnessValuse = 0;
	// make that once in a function
	mSumFitnessValuse = std::accumulate(mFITNESS_VALUES.begin(), mFITNESS_VALUES.end(), (real) 0);

}

//picking a parent from the fitness value
//picking a parent from the fitness value
OpticalSystemElement OptimizeOpticalSystem::pickParent() {

	//real fitness = pickFitness();

	

	int index = 0;

	


	real r = randomNumber(0, mSumFitnessValuse);

	while (r > 0)
	{

		r = r - mFITNESS_VALUES[index];


		if (index == mPopulation)
		{
			index = mPopulation - 1;
			r = -1.0; // stop loop
		}

		index++;

	}

	index--;
	if (index < 0)
	{
		index = 0;
	}

	//bool checkIndex = index == positionBestFitness;



	//ptrdiff_t pos = find(mFITNESS_VALUES.begin(), mFITNESS_VALUES.end(), fitness) - mFITNESS_VALUES.begin();
	OpticalSystemElement parent = mGenerationOfSystems[index];

	return parent;
}


OpticalSystemElement OptimizeOpticalSystem::pickBestParent()
{
	std::vector<real>::iterator bestFitness = std::max_element(mFITNESS_VALUES.begin(), mFITNESS_VALUES.end());
	int positionBestFitness = std::distance(mFITNESS_VALUES.begin(), bestFitness);

	OpticalSystemElement parent = mGenerationOfSystems[positionBestFitness];

	return parent;
}


OpticalSystemElement OptimizeOpticalSystem::crossoverPermutation(OpticalSystemElement parentA, OpticalSystemElement parentB) {

	OpticalSystemElement newGene;
	std::shared_ptr<Element_CR> tempElement0;


	for (int i = 0; i < parentA.getSizeOptSys(); i++) {

		tempElement0 = parentB.getPosAndElement().at(i).getElementInOptSys_ptr()->crossover_ptr(parentA.getPosAndElement().at(i).getElementInOptSys_ptr(), parentB.getPosAndElement().at(i).getElementInOptSys_ptr());

		newGene.fillPosAndElementAndInteraction(i, tempElement0, parentA.getPosAndInteraction_LLT().at(i).getInteractionAtSur_ptr());

	}

	//real affe_Z = mGenerationOfSystems.at(5).getPosAndElement().at(3).getElementInOptSys_ptr()->getPointElementValue_Z();
	//std::cout << "affe Z: " << affe_Z << std::endl;

	newGene.convertHLTSurfacesToLLTSurfaces();
	return newGene;

}


//Running the CrossOver Function over the population, creating a new population and considering the MutationRate
void OptimizeOpticalSystem::CrossOverPopulation() {

	//std::vector<OpticalSystemElement> nextGeneration;
	std::cout << "start cross over" << std::endl;
	OpticalSystemElement bestOptSysFromGeneration = pickBestParent();
	//bestOptSysFromGeneration.printValues();
	calculateSumFitnessValuse();

	for (int i = 0; i < mPopulation; i++)
	{
		OpticalSystemElement childC;

		unsigned int chanceMutation = rand() % 100;

		// Mutate the start system
		if (mMutationRate > chanceMutation)
		{
			std::shared_ptr<Element_CR> tempElement;

			for (unsigned int j = 0; j < mOptSysElementStart.getSizeOptSys(); j++)

			{
				// for mutation
				tempElement = mOptSysElementStart.getPosAndElement().at(j).getElementInOptSys_ptr()->generate_ptr();
				childC.fillPosAndElementAndInteraction(j, tempElement, mOptSysElementStart.getPosAndInteraction_LLT().at(j).getInteractionAtSur_ptr());
			}

		}
		else
		{
			childC = crossoverPermutation(bestOptSysFromGeneration, pickParent());
		}

		childC.convertHLTSurfacesToLLTSurfaces();
		mSecondGeneration.at(i) = childC;
		//std::cout << i << std::endl;



	}

	if (distanceChecker(mSecondGeneration, mDistanceAdjustment) == false)
	{
		mSecondGeneration = adjustDistances(mSecondGeneration, mDistanceAdjustment);
	}

}



std::vector<OpticalSystemElement> OptimizeOpticalSystem::getGenerationOfSystems()
{
	return mGenerationOfSystems;
}



OpticalSystemElement OptimizeOpticalSystem::getStartSystem()
{
	return mOptSysElementStart;
}

localStart OptimizeOpticalSystem::getLocalStart()
{
	return mLocalStart;
}

void OptimizeOpticalSystem::setLocalStart(localStart locStart)
{
	mLocalStart = locStart;
}





OpticalSystemElement OptimizeOpticalSystem::caseSwitcher(OpticalSystemElement optSysEle, localStart localCase)
{
	auto startTimeLocal = std::chrono::high_resolution_clock::now();

	bool stopper = true;

	unsigned int countLocal = 0;
	OpticalSystemElement optSysOptiLocal;

	//random INT generator c++11
	//std::mt19937 rng;
	//rng.seed(std::random_device()());

	//real meridOldsave = 9999999999.0;
	real difference;
	real meritCalcLocal;
	real meritCalcLocalSave;

	if (mOptimizedOptSysEle_GeneticOptimizer.getPosAndElement().size() == 0)
	{
		meritCalcLocalSave = calculateMerit(optSysEle);
	}
	else
	{
		meritCalcLocalSave = calculateMerit(mOptimizedOptSysEle_GeneticOptimizer);
	}


	real push = 0.0;
	switch (localCase)
	{


	case radiusStart:
	{
		unsigned int counter = 0;

		while (stopper)
		{
			std::cout << "interations for local optimization: " << counter << std::endl;

			// optimize radius
			optSysOptiLocal = optimizeRadius(optSysEle, mOP_Config.getStepRadiusLocal(), meritCalcLocalSave);
			meritCalcLocal = calculateMerit(optSysOptiLocal);
			
			// optimize distance
			if (mIsOneDistanceVariable)
			{			
				optSysOptiLocal = optimizePosition(optSysOptiLocal, mOP_Config.getStepDistanceLocal(), meritCalcLocal);
				meritCalcLocal = calculateMerit(optSysOptiLocal);
			}

			difference = meritCalcLocal - meritCalcLocalSave;

			if (std::abs(difference) <= mOP_Config.getStopCtiterialLocal() || /*to stop an infinit loop*/ counter > mOP_Config.getCounterLocalInterations())
			{
				stopper = false;
			}

			if (meritCalcLocal >= meritCalcLocalSave)
			{
				stopper = false;
				optSysOptiLocal = optSysEle.getDeepCopyOptSysEle();
			}

			else if (meritCalcLocal < meritCalcLocalSave)
			{
				meritCalcLocalSave = meritCalcLocal;
				optSysEle = optSysOptiLocal.getDeepCopyOptSysEle();
			}


			counter++;

			//mOP_Config.setStepsLocalRadius(mOP_Config.getStepRadiusLocal() * 0.5);
		}


	}
	break;

	case positionStart:
	{
		unsigned int counter = 0;

		while (stopper)
		{
			// optimize position
			optSysOptiLocal = optimizePosition(optSysEle, mOP_Config.getStepDistanceLocal(), meritCalcLocalSave);
			meritCalcLocal = calculateMerit(optSysOptiLocal);

			// optimize radius
			if (mIsOneRadiusVariable)
			{
				optSysOptiLocal = optimizeRadius(optSysOptiLocal, mOP_Config.getStepRadiusLocal(), meritCalcLocal);
				meritCalcLocal = calculateMerit(optSysOptiLocal);
			
			}


			difference = meritCalcLocal - meritCalcLocalSave;

			if (std::abs(difference) <= mOP_Config.getStopCtiterialLocal() || counter > mOP_Config.getCounterLocalInterations())
			{
				stopper = false;
			}

			if (meritCalcLocal >= meritCalcLocalSave)
			{
				stopper = false;
				optSysOptiLocal = optSysEle;
			}

			else if (meritCalcLocal < meritCalcLocalSave)
			{
				meritCalcLocalSave = meritCalcLocal;
				optSysEle = optSysOptiLocal;
			}
			
			counter++;
		}

		


	}
	break;

	//	case randomStart:
	case randomStart:
	{
		// TODO: generate an random start

	}
	break;

	}

	auto endTimeLocal = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> durationLocalOpti = endTimeLocal - startTimeLocal ;
	saveDurationTimeLocalOpti_min(durationLocalOpti.count() / 60.0);

	return optSysOptiLocal;


}

OpticalSystemElement OptimizeOpticalSystem::localOptimizationStart_BM(OpticalSystemElement optSysEle)
{
	OpticalSystemElement optimized = caseSwitcher(optSysEle, mLocalStart);  
	return optimized;
}





real OptimizeOpticalSystem::calculateRMSallFieldAndWavelength(OpticalSystemElement optSysEle)
{

	real RMSmean = 0;
	VectorStructR3 tempField;
	real tempWeightField;
	Spot tempSpot;
	unsigned lastSurface = optSysEle.getPosAndInteraction_LLT().size() - 1;

	std::vector<real> allRMS_weight;
	real tempRMS;
	real weightFieldRMS;

	for (unsigned int i =0; i < mFWL_Config.getFieldVec().size(); i++)
	{ 

	tempField = mFWL_Config.getFieldVec().at(i);
	tempWeightField = mFWL_Config.getWeightFieldVec().at(i);
	SequentialRayTracing seqTrac(/*optical system element*/ optSysEle, /*start point lightRay*/tempField, /*rings*/ mOP_Config.getRings(), /*arms*/ mOP_Config.getArms(), /*refractive index TODO: what happen if the ray start in a glass???*/ 1.0, mFWL_Config.getLightVec());
	
	// the first wavelength is the reference point (intersection point chief ray at the image surface)
	Spot tempSpot(seqTrac.getAllInterPointsAndIntensityAtSurface_i(lastSurface), seqTrac.getAllInterPointsAtSurf_i(lastSurface).at(0));

	tempRMS = tempSpot.getRMS_µm();
	weightFieldRMS = tempWeightField * tempRMS;
	allRMS_weight.push_back(weightFieldRMS);

	}

	for (unsigned int i = 0; i < allRMS_weight.size(); i++)
	{
		RMSmean = RMSmean + allRMS_weight.at(i);
	}


	return RMSmean;


}

void OptimizeOpticalSystem::localOptimizatio_BM()
{
	OpticalSystemElement tempOptSysEleOptimized_local = localOptimizationStart_BM(mOptSysElementStart);
	mOptimizedOptSysEle_LocalOptimizer = tempOptSysEleOptimized_local.getDeepCopyOptSysEle();
}

void OptimizeOpticalSystem::optimizeSUPERFUNCTION() {

	///////////////////////////////////////////////////////////////////
	//genetic algorithm optimization///////////////////////////////////
	///////////////////////////////////////////////////////////////////

	std::cout << "Starting the GENETIC Optimization : \n";
	OpticalSystemElement tempOptSysEleOptimized_genetic;
	tempOptSysEleOptimized_genetic = genetic_algorithm();
	mOptimizedOptSysEle_GeneticOptimizer = tempOptSysEleOptimized_genetic.getDeepCopyOptSysEle();

	std::cout << "Starting the LOCAL Optimization : \n";

	OpticalSystemElement tempOptSysEleOptimized_local = localOptimizationStart_BM(mOptimizedOptSysEle_GeneticOptimizer);

	mOptimizedOptSysEle_LocalOptimizer = tempOptSysEleOptimized_local.getDeepCopyOptSysEle();

	std::cout << "" << std::endl;
	std::cout << "OPTIMIZE SUPERCLASS DONE ! \n";
	std::cout << "" << std::endl;
}





//testing version of splitting super function into the genetic and local part

OpticalSystemElement OptimizeOpticalSystem::genetic_algorithm() {


	OpticalSystemElement geneticreturn;
	//OpticalSystemElement* geneticreturn_ptr = &geneticreturn;

	bool geneticlimites = true;
	mGenerationCount = 0;
	unsigned int gettingWorse = 0;

	auto startTimeGenetic = std::chrono::high_resolution_clock::now();

	std::cout << "randomize generation 0" << std::endl;
	RANDOMIZE_SYSTEMS();
	
	if (distanceChecker(mGenerationOfSystems, mDistanceAdjustment) == false)
	{
		mGenerationOfSystems = adjustDistances(mGenerationOfSystems, mDistanceAdjustment);
	}


	MERIT_CALCULATE();
	FITNESS_CALCULATE();

	std::vector<real> best_merit_of_generation;

	real bestFoundValue;
	std::vector<real>::iterator best_Merit;
	best_Merit = std::min_element(mMERIT_VALUES.begin(), mMERIT_VALUES.end());
	int bestSystemIndex = std::distance(mMERIT_VALUES.begin(), best_Merit);

	best_merit_of_generation.push_back(mMERIT_VALUES[bestSystemIndex]);
	bestFoundValue = mMERIT_VALUES[bestSystemIndex];

	geneticreturn = mGenerationOfSystems.at(bestSystemIndex);
	geneticreturn = geneticreturn.getDeepCopyOptSysEle();

	mBest_MERIT_VALUE_of_Gen.push_back(mMERIT_VALUES.at(bestSystemIndex));

	std::cout << "Best merit value of generation " << mGenerationCount << ": " << best_merit_of_generation.at(mGenerationCount) << std::endl;

	//printStartSystem();
	std::cout << "\n";

	while (geneticlimites)
	{


		
		CrossOverPopulation();

		//// deep copy of second generation
		for (unsigned int i = 0; i < mSecondGeneration.size(); i++)
		{
			mGenerationOfSystems.at(i) = mSecondGeneration.at(i).getDeepCopyOptSysEle();
		}
		//mGenerationOfSystems.swap(mSecondGeneration);
		//delAndFreeMemory(mSecondGeneration);
		//std::vector<OpticalSystemElement>().swap(mSecondGeneration);
		//RMS_CALCULATE();
		MERIT_CALCULATE();
		FITNESS_CALCULATE();

		best_Merit = std::min_element(mMERIT_VALUES.begin(), mMERIT_VALUES.end());
		bestSystemIndex = std::distance(mMERIT_VALUES.begin(), best_Merit);
		mBest_MERIT_VALUE_of_Gen.push_back(mMERIT_VALUES.at(bestSystemIndex));

		mGenerationCount++;
		real lastbestvalue = mBest_MERIT_VALUE_of_Gen[mBest_MERIT_VALUE_of_Gen.size() - 1];
		if (bestFoundValue > lastbestvalue)
		{

			bestFoundValue = lastbestvalue;
			geneticreturn = mGenerationOfSystems[bestSystemIndex];
			geneticreturn = geneticreturn.getDeepCopyOptSysEle();

		}

		if (fabs(mBest_MERIT_VALUE_of_Gen.at(mGenerationCount) - mBest_MERIT_VALUE_of_Gen.at(mGenerationCount - 1)) < mOP_Config.getStopCriteria_genetic()) {
			geneticlimites = false;
		}

		if (bestFoundValue < lastbestvalue)
		{
			gettingWorse++;
		}

		if (gettingWorse > 4)
		{
			geneticlimites = false;
		}

		std::cout << "Best merit value of generation " << mGenerationCount << ": " << bestFoundValue << std::endl;
		//delAndFreeMemory(mGenerationOfSystems);
		//std::vector<OpticalSystemElement>().swap(mGenerationOfSystems);
		//mGenerationOfSystems.resize(mPopulation);

		std::cout << "\n";
	}

	auto endTimeGenetic = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> durationGenetic = endTimeGenetic - startTimeGenetic;


	saveDurationTimeGeneticOpti_min(durationGenetic.count() / 60.0);


	return geneticreturn;
}


real OptimizeOpticalSystem::calculateMerit(OpticalSystemElement optSysEle)
{

	real calculatedMerit;


	//mOptSysElementStart.convertHLTtoLLT();

	//std::vector<real> temp_meritValues;

	real RMS_WEIGHT_INSTANCE;

	real imageQuality_WEIGHT_INSTANCE;

	real EFL_TARGET_INSTANCE;
	real EFL_WEIGHT_INSTANCE;

	real EXPP_TARGET_INSTANCE;
	real EXPP_WEIGHT_INSTANCE;

	real EXPD_TARGET_INSTANCE;
	real EXPD_WEIGHT_INSTANCE;

	if (std::isnan(mMF_Config.getEFL_targetValue()) && std::isnan(mMF_Config.getEXPD_targetValue()) && std::isnan(mMF_Config.getEXPP_targetValue()))
	{
		mEFL_LOCAL = 1.0;
		mEXPP_LOCAL = 1.0;
		mEXPD_LOCAL = 1.0;
	}
	else
	{
		// we have to calculate the cardinal points at the primary wavelength
		optSysEle.setRefractiveIndexAccordingToWavelength(mFWL_Config.getLightVec().at(0).getWavelength());
		calculateCardinalPoints(optSysEle);

	}


	if (std::isnan(mMF_Config.getEFL_targetValue())) {
		EFL_TARGET_INSTANCE = 1.0;
		EFL_WEIGHT_INSTANCE = 0.0;
		//expEFL = 0;
	}
	else {
		EFL_TARGET_INSTANCE = mMF_Config.getEFL_targetValue();
		EFL_WEIGHT_INSTANCE = mMF_Config.getEFL_weight();

	}

	if (std::isnan(mMF_Config.getEXPD_targetValue())) {
		EXPD_TARGET_INSTANCE = 1.0;
		EXPD_WEIGHT_INSTANCE = 0.0;
		//expEXPD = 0;
	}
	else {
		EXPD_TARGET_INSTANCE = mMF_Config.getEXPD_targetValue();
		EXPD_WEIGHT_INSTANCE = mMF_Config.getEXPD_weight();

	}

	if (std::isnan(mMF_Config.getEXPP_targetValue())) {
		EXPP_TARGET_INSTANCE = 1;
		EXPP_WEIGHT_INSTANCE = 0.0;
		//expEXPP = 0;
	}
	else {
		EXPP_TARGET_INSTANCE = mMF_Config.getEXPP_targetValue();
		EXPP_WEIGHT_INSTANCE = mMF_Config.getEXPP_weight();

	}

	if (std::isnan(mMF_Config.getRMSWeight())) {
		RMS_WEIGHT_INSTANCE = 0.0;
		//expRMS = 0;
	}
	else { RMS_WEIGHT_INSTANCE = mMF_Config.getRMSWeight(); }

	if (std::isnan(mMF_Config.getEFL_targetValue()) && std::isnan(mMF_Config.getEXPD_targetValue()) && std::isnan(mMF_Config.getEXPP_targetValue())) {
		//expRMS = 1;
		RMS_WEIGHT_INSTANCE = 1.0;
	}

	if (std::isnan(mMF_Config.getImageQuality_weight()))
	{
		imageQuality_WEIGHT_INSTANCE = 0.0;
	}
	else
	{
		imageQuality_WEIGHT_INSTANCE = mMF_Config.getImageQuality_weight();
	}


	//real numerator = pow((CALCULATE_LOCAL_RMS())*(1 / RMS_WEIGHT_INSTANCE), expRMS);

	//real EFL_denominator = fabs(EFL_WEIGHT_INSTANCE* pow(1.0/(1.0 + fabs(EFL_TARGET_INSTANCE - EFL_LOCAL)), expEFL));

	//real EXPP_denominator = fabs(EXPP_WEIGHT_INSTANCE*pow(1.0 / (1.0 + fabs(EXPP_TARGET_INSTANCE - EXPP_LOCAL)), expEXPP));

	//real EXPD_denominator = fabs(EXPD_WEIGHT_INSTANCE*pow(1.0 / (1.0 + fabs(EXPD_TARGET_INSTANCE - EXPD_LOCAL)), expEXPD));

	//calculatedMerit = numerator + EFL_denominator + EXPP_denominator + EXPD_denominator;

	//calculatedMerit = numerator / (EFL_denominator*EXPP_denominator*EXPD_denominator);

//real RMS_MERIT = CALCULATE_LOCAL_RMS();

//real EFL_MERIT = 1.0 / (1.0 + fabs(EFL_TARGET_INSTANCE - EFL_LOCAL));

//real EXPP_MERIT = 1.0 / (1.0 + fabs(EXPP_TARGET_INSTANCE - EXPP_LOCAL));

//real EXPD_MERIT = 1.0 / (1.0 + fabs(EXPD_TARGET_INSTANCE - EXPD_LOCAL));

	real RMS_MERIT = calculateRMSallFieldAndWavelength(optSysEle);

	real IMAGEQUALITY_MERIT = 1.0;

	if (imageQuality_WEIGHT_INSTANCE != 0.0)
	{
		IMAGEQUALITY_MERIT = CALCULATE_LOCAL_IMAGEQUALITY();
	}

	real correlationfactorTarget = 1.0;
	real correlationFacRMS = 1.0;

	real EFL_merit = std::abs(EFL_TARGET_INSTANCE - mEFL_LOCAL) / EFL_TARGET_INSTANCE;
	real EXPP_merit = std::abs(EXPP_TARGET_INSTANCE - mEXPP_LOCAL) / EXPP_TARGET_INSTANCE;
	real EXPD_merit = std::abs(EXPD_TARGET_INSTANCE - mEXPD_LOCAL) / EXPD_TARGET_INSTANCE;


	real RMS_part = RMS_WEIGHT_INSTANCE *  RMS_MERIT * correlationFacRMS;
	real imageQuality_part = imageQuality_WEIGHT_INSTANCE * IMAGEQUALITY_MERIT*correlationfactorTarget * 1000;
	real EFL_part = EFL_WEIGHT_INSTANCE * EFL_merit / correlationfactorTarget;
	real EXPP_part = EXPP_WEIGHT_INSTANCE * EXPP_merit / correlationfactorTarget;
	real EXPD_part = EXPD_WEIGHT_INSTANCE * EXPD_merit / correlationfactorTarget;

	// std::cout << "rms part: " << RMS_part << std::endl;
	// std::cout << "efl part: " << EFL_part << std::endl;

	calculatedMerit = RMS_part + imageQuality_part + EFL_part + EXPP_part + EXPD_part;

	// std::cout << "merit value : " << calculatedMerit << std::endl;

	//calculatedMerit = (RMS_WEIGHT_INSTANCE + 1.5)*RMS_MERIT + imageQuality_WEIGHT_INSTANCE * IMAGEQUALITY_MERIT*imageQuality_Correlation + EFL_WEIGHT_INSTANCE * EFL_MERIT / correlationfactor + EXPP_WEIGHT_INSTANCE * EXPP_MERIT / correlationfactor + EXPD_WEIGHT_INSTANCE * EXPD_MERIT / correlationfactor;


	//std::cout << "THE CALCULATED LOCAL MERIT IS : " << calculatedMerit << "\n";
	return calculatedMerit;

}


// get optimized optical system LLT
OpticalSystem_LLT OptimizeOpticalSystem::getOptSysOptimized_LLT()
{
	return mOptimizedOptSysEle_LocalOptimizer.getLLTconversion_doConversion();

}

// get optimized optical system element
OpticalSystemElement OptimizeOpticalSystem::getOptSysOptimized_Ele() const
{
	return mOptimizedOptSysEle_LocalOptimizer;
}

real OptimizeOpticalSystem::CALCULATE_LOCAL_IMAGEQUALITY()
{
	real imageQuality = 1.0;
	//// TODO: here we have to do the image simulation
	//ImageSimulation imaSim;
	//imaSim.ImgSimMain();
	//cv::Mat simulatetImage = imaSim.getSimulatedImage();
	//
	//// TODO improve image quality
	//CompareTwoImagesAndImprove comTwoImaAndImprov;
	//QualityAndImageStruct qualityAndImage = comTwoImaAndImprov.comTwoImaAndImprove_testE0();
	//
	//imageQuality = qualityAndImage.getQuality();

	return imageQuality;
}



// get EFL after optimasation
real OptimizeOpticalSystem::getEFL_AO()
{
	return mEFL_LOCAL;
}
// get z position of EXPP after optimasation
real OptimizeOpticalSystem::getEXPP_z_AO()
{
	return mEXPP_LOCAL;
}
// get EXPD after optimasation
real OptimizeOpticalSystem::getEXPD_AO()
{
	return mEXPD_LOCAL;
}


void OptimizeOpticalSystem::calcPosApertureStop()
{
	unsigned int posApertureStop;
	ApertureStopElement typeAperstopStopEle;
	std::shared_ptr<Element_CR> tempElement;

	unsigned sizeOptSys = mOptSysElementStart.getSizeOptSys();
	for (unsigned int i = 0; i < sizeOptSys; i++)
	{
		tempElement = mOptSysElementStart.getPosAndElement().at(i).getElementInOptSys_ptr();

		if (typeid(typeAperstopStopEle) == typeid(*tempElement))
			(posApertureStop = i);
	}

	mPositionApertureStop = posApertureStop;

}


void OptimizeOpticalSystem::calcDistanceAdjustment()
{
	unsigned int tempPosition;
	real tempDistanceZ;
	typeModifier tempTypeMod;

	DistanceAdjustmentStruct tempDisAndjust;

	real beforePointElementZ = 0.0;
	real tempPointElementZ;

	for (unsigned int i = 0; i < mOptSysElementStart.getSizeOptSys(); i++)
	{

		tempPointElementZ = mOptSysElementStart.getPosAndElement().at(i).getElementInOptSys_ptr()->getPointElementValue_Z();
		tempDistanceZ = tempPointElementZ - beforePointElementZ;
		tempTypeMod = mOptSysElementStart.getPosAndElement().at(i).getElementInOptSys_ptr()->getPointTypeModifier_Z();

		tempDisAndjust.setPosition(i);
		tempDisAndjust.setDistance(tempDistanceZ);
		tempDisAndjust.setTypeModifier(tempTypeMod);

		mDistanceAdjustment.push_back(tempDisAndjust);

		beforePointElementZ = tempPointElementZ;

	}
}



void OptimizeOpticalSystem::calcRadiusVariabe()
{

	for (unsigned int i = 0; i < mOptSysElementStart.getSizeOptSys(); i++)
	{
		if (mOptSysElementStart.getPosAndElement().at(i).getElementInOptSys_ptr()->getRadiusTypeModifier() == typeModifierVariable)
		{
			mRadiusVariable.push_back(i);
		}
	}
}

void OptimizeOpticalSystem::calcPointVariable()
{

	for (unsigned int i = 0; i < mOptSysElementStart.getSizeOptSys(); i++)
	{
		if (mOptSysElementStart.getPosAndElement().at(i).getElementInOptSys_ptr()->getPointTypeModifier_Z() == typeModifierVariable)
		{
			mPointVariable.push_back(i);
		}
	}
}


bool OptimizeOpticalSystem::distanceChecker(std::vector<OpticalSystemElement> optSysEleVec, std::vector<DistanceAdjustmentStruct> disAdjustmentStruct)
{
	// calc all distances
	real realDistance;

	// size optical system
	unsigned int sizeOptSys = optSysEleVec.at(0).getSizeOptSys();

	real tolerance = 0.00001;
	bool checker = true;

	for (unsigned int j = 0; j < optSysEleVec.size(); j++)
	{
		real beforePointElementZ = 0.0;
		for (unsigned int i = 0; i < sizeOptSys; i++)
		{
			realDistance = optSysEleVec.at(j).getPosAndElement().at(i).getElementInOptSys_ptr()->getPointElementValue_Z() - beforePointElementZ;
			if (disAdjustmentStruct.at(i).getTypeModifier() == typeModifierFixed)
			{
				if (realDistance != disAdjustmentStruct.at(i).getDistanceZ())
				{
					checker = false;
				}

			}

			// check for negative distances
			if (disAdjustmentStruct.at(i).getTypeModifier() == typeModifierVariable)
			{
				if (realDistance < mOP_Config.getMinGapSurface())
				{
					checker = false;
				}
			}

			beforePointElementZ = optSysEleVec.at(j).getPosAndElement().at(i).getElementInOptSys_ptr()->getPointElementValue_Z();

		}
	}

	return checker;

}


bool OptimizeOpticalSystem::checkIfOneDistanceIsVariable()
{
	bool checkVari = false;
	for (unsigned int i = 0; i < mOptSysElementStart.getSizeOptSys(); i++)
	{
		if (mDistanceAdjustment.at(i).getTypeModifier() == typeModifierVariable)
		{
			checkVari = true;
			i = mOptSysElementStart.getSizeOptSys();
		}
	}

	return checkVari;

}

bool OptimizeOpticalSystem::checkIfOneRadiusIsVariabel()
{
	bool checkVari = false;

	for (unsigned int i = 0; i < mOptSysElementStart.getSizeOptSys(); i++)
	{
		if (mOptSysElementStart.getPosAndElement().at(i).getElementInOptSys_ptr()->getRadiusTypeModifier() == typeModifierVariable)
		{
			checkVari = true;
			i = mOptSysElementStart.getSizeOptSys();
		}
	}

	return checkVari;
}

std::vector<OpticalSystemElement> OptimizeOpticalSystem::adjustDistances(std::vector <OpticalSystemElement> optSysEleVec, std::vector<DistanceAdjustmentStruct> disAdjustStr)
{

	std::vector<OpticalSystemElement> disKorOptSysEle;
	unsigned generationCounter;
	for (generationCounter = 0; generationCounter < optSysEleVec.size(); generationCounter++)
	{

		real beforePointZ = 0.0;
		real tempPoint;
		OpticalSystemElement tempOptSysEle;
		std::shared_ptr<Element_CR> tempElement_ptr;
		real setPointZ;

		OpticalSystemElement newOpticalSystem;

		tempOptSysEle = optSysEleVec.at(generationCounter);
		for (unsigned int i = 0; i < mOptSysElementStart.getSizeOptSys(); i++)
		{
			tempElement_ptr = tempOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr();
			real tempPointZ = tempElement_ptr->getPointElementValue_Z();
			real tempDistanceZ = tempPointZ - beforePointZ;

			if (mDistanceAdjustment.at(i).getTypeModifier() == typeModifierFixed)
			{
				setPointZ = beforePointZ + mDistanceAdjustment.at(i).getDistanceZ();
				tempElement_ptr->setPointElementValue_Z(setPointZ);
				tempDistanceZ = mDistanceAdjustment.at(i).getDistanceZ();
			}

			if (tempDistanceZ <= 0.0) // if there is a negative distance
			{
				tempDistanceZ = -1 * tempDistanceZ + mOP_Config.getMinGapSurface();
				tempElement_ptr->pushPosition(tempDistanceZ);
			}

			if (tempDistanceZ < mOP_Config.getMinGapSurface() && mDistanceAdjustment.at(i).getTypeModifier() == typeModifierVariable) // distance is smaller than allowed and variable
			{
				tempDistanceZ = mOP_Config.getMinGapSurface();
				tempElement_ptr->pushPosition(tempDistanceZ);
			}

			beforePointZ = tempElement_ptr->getPointElementValue_Z();

			//tempElement_ptr->print();

			newOpticalSystem.fillPosAndElementAndInteraction(i, tempElement_ptr, mOptSysElementStart.getPosAndInteraction_LLT().at(i).getInteractionAtSur_ptr());

		}

		disKorOptSysEle.push_back(newOpticalSystem);
	}

	return disKorOptSysEle;

}


int OptimizeOpticalSystem::fRand_int(int min, int max)
{
	//random INT generator c++11
	std::mt19937 rng;
	rng.seed(std::random_device()());

	std::vector<int> indices;
	std::vector<int> order;

	std::uniform_int_distribution<std::mt19937::result_type> randomdistributor(min, max); // distribution in range [1, i]	
	int randimInt = randomdistributor(rng);

	return randimInt;
}

std::vector<int> OptimizeOpticalSystem::fRand_int_vec(std::vector<int> indices)
{
	//random INT generator c++11
	std::mt19937 rng;
	rng.seed(std::random_device()());

	std::vector<int> order;


	//fill the vector for the order of optimization with indices from 0 -> .size()
	for (int i = indices.size() - 1; i >= 0; i--)
	{
		std::uniform_int_distribution<std::mt19937::result_type> randomdistributor(0, i); // distribution in range [1, 6]	
		int elementIndex = randomdistributor(rng);
		order.push_back(indices.at(elementIndex));
		indices.erase(std::remove(indices.begin(), indices.end(), indices.at(elementIndex)), indices.end());

	}

	return order;

}


OpticalSystemElement OptimizeOpticalSystem::optimizePosition(OpticalSystemElement optSysEle, real stepsStart, real meritOld)
{
	bool position = true;
	real beforePointZ;
	real tempPointZ;
	int checkDirSteps;

	real steps = stepsStart;

	real meritNew = meritOld;
	real difference;

	real meritPosStep;
	real meritNegStep;

	OptSysEleAndMeritStruct optSysAndMeritSave;
	std::vector<OptSysEleAndMeritStruct> optSysAndMerit_vec;

	real saveMerit;

	// calculate position to start optimize point
	std::vector<std::vector<int>> startOptiPoint_vecVec_rand;
	startOptiPoint_vecVec_rand.push_back(mPointVariable);
	if (mOP_Config.getCheckAllLocalComb())
	{
		while (std::next_permutation(mPointVariable.begin(), mPointVariable.end()))
		{
			startOptiPoint_vecVec_rand.push_back(mPointVariable);
		}
	}

	for (int i = 0; i < startOptiPoint_vecVec_rand.size(); i++)
	{
		// TODO: here we have to use the optimized system
		OpticalSystemElement saveOptSysEle = optSysEle.getDeepCopyOptSysEle();
		saveOptSysEle.convertHLTSurfacesToLLTSurfaces();
		saveMerit = meritOld;

		for (unsigned int j = 0; j < startOptiPoint_vecVec_rand.at(0).size(); j++)

		{
			position = true;
			checkDirSteps = 0;
			real divider = 0.5;
			real stepsPos = mOP_Config.getStepDistanceLocal();
			real stepsNeg = -mOP_Config.getStepDistanceLocal();

			// if the position of the surface is variable
			if (saveOptSysEle.getPosAndElement().at(startOptiPoint_vecVec_rand.at(i).at(j)).getElementInOptSys_ptr()->getPointTypeModifier_Z() == typeModifierVariable)
			{
				while (position)
				{
					switch (checkDirSteps == 0)
					{

						case true:
						{
							// first we have to check in which direction we have to go

							// go to pos side
							OpticalSystemElement saveOptSysEle_pos = saveOptSysEle.getDeepCopyOptSysEle();
							saveOptSysEle_pos.convertHLTSurfacesToLLTSurfaces();
							saveOptSysEle_pos.getPosAndElement().at(startOptiPoint_vecVec_rand.at(i).at(j)).getElementInOptSys_ptr()->localOptimization_position(stepsPos);
							

							//push distances
							for (unsigned int disAdj = 1; disAdj < saveOptSysEle_pos.getSizeOptSys(); disAdj++)
							{

								beforePointZ = saveOptSysEle_pos.getPosAndElement().at(disAdj - 1).getElementInOptSys_ptr()->getPointElementValue_Z();
								tempPointZ = saveOptSysEle_pos.getPosAndElement().at(disAdj).getElementInOptSys_ptr()->getPointElementValue_Z();

								if (tempPointZ - beforePointZ < mOP_Config.getMinGapSurface() || std::abs(tempPointZ - beforePointZ) < mOP_Config.getMinGapSurface()) // distance is negative or distance between surfaces is smaler than min gap  
								{
									saveOptSysEle_pos.getPosAndElement().at(disAdj).getElementInOptSys_ptr()->setPointElementValue_Z(beforePointZ + mOP_Config.getMinGapSurface());
								}

								if (mDistanceAdjustment.at(disAdj).getTypeModifier() == typeModifierFixed)
								{
									saveOptSysEle_pos.getPosAndElement().at(disAdj).getElementInOptSys_ptr()->setPointElementValue_Z(mDistanceAdjustment.at(disAdj).getDistanceZ() + beforePointZ);

								}

							}

							meritPosStep = calculateMerit(saveOptSysEle_pos);

							// go to negative side
							OpticalSystemElement saveOptSysEle_neg = saveOptSysEle.getDeepCopyOptSysEle();
							saveOptSysEle_neg.convertHLTSurfacesToLLTSurfaces();
							saveOptSysEle_neg.getPosAndElement().at(startOptiPoint_vecVec_rand.at(i).at(j)).getElementInOptSys_ptr()->localOptimization_position(stepsNeg);

							//push distances
							for (unsigned int disAdj = 1; disAdj < saveOptSysEle_neg.getSizeOptSys(); disAdj++)
							{

								beforePointZ = saveOptSysEle_neg.getPosAndElement().at(disAdj - 1).getElementInOptSys_ptr()->getPointElementValue_Z();
								tempPointZ = saveOptSysEle_neg.getPosAndElement().at(disAdj).getElementInOptSys_ptr()->getPointElementValue_Z();

								if (tempPointZ - beforePointZ < mOP_Config.getMinGapSurface() || std::abs(tempPointZ - beforePointZ) < mOP_Config.getMinGapSurface()) // distance is negative or distance between surfaces is smaler than min gap  
								{
									saveOptSysEle_neg.getPosAndElement().at(disAdj).getElementInOptSys_ptr()->setPointElementValue_Z(beforePointZ + mOP_Config.getMinGapSurface());
								}

								if (mDistanceAdjustment.at(disAdj).getTypeModifier() == typeModifierFixed)
								{
									saveOptSysEle_neg.getPosAndElement().at(disAdj).getElementInOptSys_ptr()->setPointElementValue_Z(mDistanceAdjustment.at(disAdj).getDistanceZ() + beforePointZ);

								}

							}


							meritNegStep = calculateMerit(saveOptSysEle_neg);

							if (meritPosStep > meritNegStep && saveMerit > meritNegStep) // we have to go in the negativ direction
							{
								steps = stepsNeg;
								meritNew = meritNegStep;
								checkDirSteps++;
								saveOptSysEle = saveOptSysEle_neg;

							}

							else if (meritPosStep < meritNegStep && saveMerit > meritPosStep) // we have to go in the positiv direction
							{
								steps = stepsPos;
								meritNew = meritPosStep;
								checkDirSteps++;
								saveOptSysEle = saveOptSysEle_pos;

							}

							else // we have to reduce the step size to find the local min
							{
								stepsNeg = stepsNeg / 2;
								stepsPos = stepsPos / 2;

								if (std::abs(stepsNeg) < mOP_Config.getMinStep_position())
								{

									position = false;
									break;
								}
							}

						}
					
					
					
						case false:
						{
							saveMerit = meritNew;
						
							saveOptSysEle.getPosAndElement().at(startOptiPoint_vecVec_rand.at(i).at(j)).getElementInOptSys_ptr()->localOptimization_position(steps);
							saveOptSysEle.convertHLTSurfacesToLLTSurfaces();

							//push distances
							for (unsigned int disAdj = 1; disAdj < saveOptSysEle.getSizeOptSys(); disAdj++)
							{

								beforePointZ = saveOptSysEle.getPosAndElement().at(disAdj - 1).getElementInOptSys_ptr()->getPointElementValue_Z();
								tempPointZ = saveOptSysEle.getPosAndElement().at(disAdj).getElementInOptSys_ptr()->getPointElementValue_Z();

								if (tempPointZ - beforePointZ < mOP_Config.getMinGapSurface() || std::abs(tempPointZ - beforePointZ) < mOP_Config.getMinGapSurface()) // distance is negative or distance between surfaces is smaler than min gap  
								{
									saveOptSysEle.getPosAndElement().at(disAdj).getElementInOptSys_ptr()->setPointElementValue_Z(beforePointZ + mOP_Config.getMinGapSurface());
								}

								if (mDistanceAdjustment.at(disAdj).getTypeModifier() == typeModifierFixed)
								{
									saveOptSysEle.getPosAndElement().at(disAdj).getElementInOptSys_ptr()->setPointElementValue_Z(mDistanceAdjustment.at(disAdj).getDistanceZ() + beforePointZ);

								}

							}

						saveOptSysEle.convertHLTSurfacesToLLTSurfaces();

						meritNew = calculateMerit(saveOptSysEle);
						difference = saveMerit - meritNew;

						// we are close enough the local minima 							
						if (std::abs(difference) <= mOP_Config.getStopCtiterialLocal() || std::abs(steps) < mOP_Config.getMinStep_position())
						{
							position = false;

							


							if (saveMerit < meritNew) // we have to walk one step back
							{
								steps = -steps;
								
								saveOptSysEle.getPosAndElement().at(startOptiPoint_vecVec_rand.at(i).at(j)).getElementInOptSys_ptr()->localOptimization_position(steps);
								meritNew = calculateMerit(saveOptSysEle);

								

							}

							break;
						}

						if (saveMerit < meritNew) // minimum must be between saveMerit and meritNew
						{
							steps = -divider * steps;
							divider = divider * 0.5;
							
						}

	
					
						}
					}
				}

			}
		}
		optSysAndMeritSave.setOptSysEle(saveOptSysEle);
		optSysAndMeritSave.setMerit(meritNew);
		optSysAndMerit_vec.push_back(optSysAndMeritSave);

	}

	return getBestOptSys(optSysAndMerit_vec);

}


//get best optical system
OpticalSystemElement OptimizeOpticalSystem::getBestOptSys(std::vector<OptSysEleAndMeritStruct> optSysAndMerit_vec)
{
	OpticalSystemElement bestOptSys = optSysAndMerit_vec.at(0).getOptSysEle();
	real bestMerit = optSysAndMerit_vec.at(0).getMerit();
	real tempMerit;

	for (unsigned int i = 1; i < optSysAndMerit_vec.size(); i++)
	{
		tempMerit = optSysAndMerit_vec.at(i).getMerit();
		if (tempMerit < bestMerit)
		{
			bestOptSys = optSysAndMerit_vec.at(i).getOptSysEle();
			bestMerit = tempMerit;
		}

	}

	return bestOptSys;

}

OpticalSystemElement OptimizeOpticalSystem::optimizeRadius(OpticalSystemElement optSysEle, real stepsStart, real meritOld)
{
	bool radius = true;
	unsigned int checkRadSteps;
	real steps = stepsStart;

	real meritNew = meritOld;
	real difference;

	real meritPosStep;
	real meritNegStep;

	OptSysEleAndMeritStruct optSysAndMeritSave;
	std::vector<OptSysEleAndMeritStruct> optSysAndMerit_vec;

	real saveMerit;

	// calculate radius to start optimize
	std::vector<std::vector<int>> startOptiRadius_vecVec_rand;
	startOptiRadius_vecVec_rand.push_back(mRadiusVariable);

	
	if (mOP_Config.getCheckAllLocalComb())
		{
			while (std::next_permutation(mRadiusVariable.begin(), mRadiusVariable.end()))
			{
				startOptiRadius_vecVec_rand.push_back(mRadiusVariable);
			}
		}

	int combosToCheck = startOptiRadius_vecVec_rand.size();
	std::cout << "" << std::endl;
	std::cout << "check combination number: " << combosToCheck << std::endl;
	std::cout << "" << std::endl;

	for (int i = 0; i < startOptiRadius_vecVec_rand.size(); i++)
	{
		std::cout << "local optimization combo: " << i << std::endl;

		// here we have to use the optimized system
		OpticalSystemElement saveOptSysEle = optSysEle.getDeepCopyOptSysEle();
		saveOptSysEle.convertHLTSurfacesToLLTSurfaces();
		saveMerit = meritOld;

		for (unsigned int j = 0; j < startOptiRadius_vecVec_rand.at(0).size(); j++)

		{
			radius = true;
			real divider = 0.5;
			checkRadSteps = 0;
			real stepsPos = mOP_Config.getStepRadiusLocal();
			real stepsNeg = - mOP_Config.getStepRadiusLocal();
			unsigned int radiusNumToOptimize;

			// if the radius of the surface is variable
			if (saveOptSysEle.getPosAndElement().at(startOptiRadius_vecVec_rand.at(i).at(j)).getElementInOptSys_ptr()->getRadiusTypeModifier() == typeModifierVariable)
			{
				radiusNumToOptimize = startOptiRadius_vecVec_rand.at(i).at(j);
				std::cout << "optimize radius num: " << radiusNumToOptimize << std::endl;

				while (radius)
				{

					
									   					 
					

						if(checkRadSteps == 0)
						{

							// first we have to check in which direction we have to go

							// go to pos side
							
							OpticalSystemElement saveOptSysEle_pos = saveOptSysEle.getDeepCopyOptSysEle();
							saveOptSysEle_pos.getPosAndElement().at(startOptiRadius_vecVec_rand.at(i).at(j)).getElementInOptSys_ptr()->localOptimization_radius(stepsPos);
							saveOptSysEle_pos.convertHLTSurfacesToLLTSurfaces();
							meritPosStep = calculateMerit(saveOptSysEle_pos);

							// go to negative side
							OpticalSystemElement saveOptSysEle_neg = saveOptSysEle.getDeepCopyOptSysEle();
							saveOptSysEle_neg.getPosAndElement().at(startOptiRadius_vecVec_rand.at(i).at(j)).getElementInOptSys_ptr()->localOptimization_radius(stepsNeg);
							saveOptSysEle_neg.convertHLTSurfacesToLLTSurfaces();
							meritNegStep = calculateMerit(saveOptSysEle_neg);

								if (meritPosStep > meritNegStep && saveMerit > meritNegStep) // we have to go in the negativ direction
								{
									steps = stepsNeg;
									meritNew = meritNegStep;
									checkRadSteps++;
									saveOptSysEle = saveOptSysEle_neg;
																		
								}

								else if (meritPosStep < meritNegStep && saveMerit > meritPosStep) // we have to go in the positiv direction
								{
									steps = stepsPos;
									meritNew = meritPosStep;
									checkRadSteps++;
									saveOptSysEle = saveOptSysEle_pos;
																	
								}

								else // we have to reduce the step size to find the local min
								{
									stepsNeg = stepsNeg / 2;
									stepsPos = stepsPos / 2;

									if (std::abs(stepsNeg) < mOP_Config.getMinStep_radius())
									{
										
										radius = false;
										break;
									}
								}
						}
					
											
						else		
						{
		
							saveMerit = meritNew;
							saveOptSysEle.getPosAndElement().at(startOptiRadius_vecVec_rand.at(i).at(j)).getElementInOptSys_ptr()->localOptimization_radius(steps);
							saveOptSysEle.convertHLTSurfacesToLLTSurfaces();

							// std::cout << "save merit " << saveMerit << std::endl;
							// std::cout << "R0: " << saveOptSysEle.getPosAndElement().at(1).getElementInOptSys_ptr()->getRadiusElementValue() << std::endl;
							meritNew = calculateMerit(saveOptSysEle);

							difference = saveMerit - meritNew;

							// we are close enough the local minima 							
							if (std::abs(difference) <= mOP_Config.getStopCtiterialLocal() || std::abs(steps) < mOP_Config.getMinStep_radius())
							{
								radius = false;

								


								if (saveMerit < meritNew) // we have to walk one step back
								{
									steps = -steps;
								
									saveOptSysEle.getPosAndElement().at(startOptiRadius_vecVec_rand.at(i).at(j)).getElementInOptSys_ptr()->localOptimization_radius(steps);						
									meritNew = calculateMerit(saveOptSysEle);


								}


								
								break;

							}

							if (saveMerit < meritNew) // minimum must be between saveMerit and meritNew
							{
								steps = -divider * steps;
								divider = divider * 0.5;
								//stepsStart = stepsStart * 0.5;
							}

						
							
						}
					
				}
				
			}
		}

		optSysAndMeritSave.setOptSysEle(saveOptSysEle);
		optSysAndMeritSave.setMerit(meritNew);
		optSysAndMerit_vec.push_back(optSysAndMeritSave);


	}

	std::cout << "" << std::endl;
	std::cout << "get best optical system local optimization" << std::endl;
	std::cout << "" << std::endl;
	return getBestOptSys(optSysAndMerit_vec);
}

void OptimizeOpticalSystem::setRings_optimizer(unsigned int rings)
{
	mOP_Config.setRings(rings);
}
void OptimizeOpticalSystem::setArms_optimizer(unsigned int arms)
{
	mOP_Config.setArms(arms);
}

void OptimizeOpticalSystem::setMinGapSurface_optimizer(real minGap)
{
	mOP_Config.setMinGapSurfaces(minGap);
}

void OptimizeOpticalSystem::setCheckAllLocalCombinations_optimizer(bool checkAllLocalCom)
{
	mOP_Config.setCheckAllLocalCombinations(checkAllLocalCom);
}

void OptimizeOpticalSystem::saveDurationTimeGeneticOpti_min(double saveTime)
{
	mDurationTime_Genetic_Opti = saveTime;
}

real OptimizeOpticalSystem::getDurationTimeGeneticOptiInMin()
{
	return mDurationTime_Genetic_Opti;
}
real OptimizeOpticalSystem::getDurationTimeLocalOptiInMin()
{
	return mDurationTime_Local_Opti;
}

void OptimizeOpticalSystem::saveDurationTimeLocalOpti_min(double saveTime)
{
	mDurationTime_Local_Opti = saveTime;
}

//export times (genetic and local) and population
void OptimizeOpticalSystem::exportTimesAndPupulation_txt(std::string location, std::string nameLocation)
{
	inportExportData::saveDoubleInTXT(location, nameLocation, "time_Genetic_Opti", mDurationTime_Genetic_Opti);
	inportExportData::saveDoubleInTXT(location, nameLocation, "time_Local_Opti", mDurationTime_Local_Opti);
	inportExportData::saveDoubleInTXT(location, nameLocation, "pupulation", mPopulation);
}

unsigned int OptimizeOpticalSystem::getNumberGenerations()
{
	return mGenerationCount + 1;
}

real OptimizeOpticalSystem::getPopulation()
{
	return mPopulation;
}

real OptimizeOpticalSystem::getMutationRate()
{
	return mMutationRate;
}

FieldAndLightStruct OptimizeOpticalSystem::getFieldAndLightConfig()
{
	return mFWL_Config;
}
MeritConfiguration OptimizeOpticalSystem::getMeritConfig()
{
	return mMF_Config;
}
OptimizeParameters OptimizeOpticalSystem::getOptimizeParameters()
{
	return mOP_Config;
}

//// delete and free momory of vector with points
//void OptimizeOpticalSystem::delAndFreeMemory(std::vector<OpticalSystemElement> optSysEle_vec)
//{
//	OpticalSystemElement tempOptSysEle;
//	unsigned int numberElement = optSysEle_vec.at(0).getPosAndElement().size();
//
//	std::shared_ptr<Element_CR> element_ptr;
//
//	for (unsigned int j =0; j < mPopulation; j++)
//	{
//		tempOptSysEle = optSysEle_vec.at(j);
//			   
//		for (unsigned int i = 0; i < numberElement; i++)
//		{		
//		
//			element_ptr = tempOptSysEle.getPosAndElement().at(i).getElementInOptSys_ptr();
//			
//			if(element_ptr.get() != NULL)
//			{ 
//				delete element_ptr;
//			}
//
//			
//		}
//	
//	}
//
//
//}


