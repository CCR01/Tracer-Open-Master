#pragma once
#include "..\OpticalSystemElement\OpticalSystemElement.h"
#include "..\Analyse\CardinalPoints.h"
#include <ctime>
#include <iostream>


struct OptSysEleAndMeritStruct
{
	OptSysEleAndMeritStruct();
	OptSysEleAndMeritStruct(OpticalSystemElement optSysEle, real merit);
	~OptSysEleAndMeritStruct();

	// get optical system
	OpticalSystemElement getOptSysEle() const;
	// set optical system
	void setOptSysEle(OpticalSystemElement const optSysEle);
	// get merit
	real getMerit() const;
	// set merit
	void setMerit(real const merit);

public:
	OpticalSystemElement mOptSysEle;
	real mMerit;
};



struct DistanceAdjustmentStruct
{
	DistanceAdjustmentStruct();
	DistanceAdjustmentStruct(unsigned int postition, real distanceZ, typeModifier typeMod);
	~DistanceAdjustmentStruct();

	// get position
	unsigned int getPosition() const;
	// set position
	void setPosition(unsigned int const position);
	// get distance
	real getDistanceZ() const;
	// set distance Z
	void setDistance(real const distanceZ);
	// get type modifier
	typeModifier getTypeModifier() const;
	// set type modifier
	void setTypeModifier(typeModifier const typeMod);

	public:
	unsigned int mPosition;
	real mDistanceZ;
	typeModifier mTypeMod;

};


struct OptimizeParameters 
{

public:

	void loadDefautSettingOptiParametes();

	void setStepsLocalRadius(real stepRadiusLocal);
	void setCriterialLocal(real criterialocal);
	void setCriterialGenetic(real criteriagenetic);
	void setMinGapSurfaces(real minGapSur);
	void setRings(unsigned int rings);
	void setArms(unsigned int arms);
	void setCheckAllLocalCombinations(bool checkAllLocalCombination);
	void setMinStep_radius(real minStep);
	void setMinStep_position(real minStep);

	real getStepRadiusLocal() const;
	real getStepDistanceLocal() const;
	real getStopCtiterialLocal() const;
	real getMaxStepsLocalOpti() const;
	real getStopCriteria_genetic() const;
	real getMinGapSurface() const;
	real getMinStep_radius() const;
	real getMinStep_position() const;
	bool getCheckAllLocalComb() const;
	unsigned int get_gettingWorseGeneticLimit() const;
	unsigned int getCounterLocalInterations() const;
	unsigned int getRings() const;
	unsigned int getArms() const;

private:
	real mStepRadiusLocal;
	real mStepDistanceLocal;
	real mStopCriteriaLocal;
	real maxStepsLocalOpti;
	real mStopCriteriaGenetic;
	real m_minGapSurfaces;
	real m_minStep_radius;
	real m_minStep_position;
	bool mCheckAllLocalCombinations;
	unsigned int gettingWorseGeneticLimit;
	unsigned int counterLocalInterations;
	unsigned int mRings;
	unsigned int mArms;


};



struct MeritConfiguration {

public:
	void DEFAFULT_SETTINGS();

	void setRMSWeight(real rms_weight);
	real getRMSWeight();

	void setEFL_targetValue(real efl_target);
	real getEFL_targetValue();
	void setEFL_weight(real efl_weight);
	real getEFL_weight();

	void setEXPP_targetValue(real expp_target);
	real getEXPP_targetValue();
	void setEXPP_weight(real expp_weight);
	real getEXPP_weight();

	void setEXPD_targetValue(real expd_target);
	real getEXPD_targetValue();
	void setEXPD_weight(real expd_weight);
	real getEXPD_weight();

	void setImageQuality_weight(real imageQuality_weight);
	real getImageQuality_weight();

private:
	real mEFL_Target;
	real mEFL_Weight;

	real mRMS_Weight;

	real mEXPP_Target;
	real mEXPP_Weight;

	real mEXPD_Target;
	real mEXPD_Weight;

	real mImageQuality_Weight;

};

struct FieldAndLightStruct {

public:
	void DEFAULT_SETTINGS();

	void setLight_LLT(Light_LLT light_LLT);
	void setFieldAndWeight(VectorStructR3 field, real weight);


	void addLight(Light_LLT light_LLT);
	void addField(VectorStructR3 field, real weight);

	std::vector<Light_LLT> getLightVec() const;
	std::vector<VectorStructR3>	getFieldVec() const;
	std::vector<real> getWeightFieldVec() const;

private:
	std::vector<Light_LLT> mLight_LLT_vec;
	std::vector<VectorStructR3>	mFieldVector;
	std::vector<real> mWeightingFieldVector;
};


class OptimizeOpticalSystem
{
public:
	OptimizeOpticalSystem();

	OptimizeOpticalSystem(OpticalSystemElement optSysEle, localStart localOptStart);
	OptimizeOpticalSystem(OpticalSystemElement optSysEle, real length, unsigned int population, real mutationRate, localStart localOptStart);
	OptimizeOpticalSystem(OpticalSystemElement optSysEle, unsigned int population, real mutationRate, localStart localOptStart);

	~OptimizeOpticalSystem();
	
	void printOptSysEle(OpticalSystemElement OptSysEle);

	void calcDistanceAdjustment();
	void calcRadiusVariabe();
	void calcPointVariable();
	

	void calculateCardinalPoints(OpticalSystemElement system);

	// calc length optical system
	real calcLengthOptSysEle(OpticalSystemElement optSysEle);

	FieldAndLightStruct getFWL_S();

	void add_Light(Light_LLT light);
	void add_FieldAndWeight(VectorStructR3 fv, real weight);

	void set_Light(Light_LLT light);
	void set_Field(VectorStructR3 field, real weight);

	//void add_RMSWeight(real RMS_weight);
	void add_IMAGEQuality_Weight(real IQ_weight);

	void add_TargetEFL(real EFL_target, real EFL_weight);
	void add_TargetEXPP(real EXPP_target, real EXPP_weight);
	void add_TargetEXPD(real EXPD_target, real EXPD_weight);

	real		getApertureDirection_Z();
	real		getAperturePoint_Z();
	real		getApertureHeight();



	//####################################################################################################
	//#----------------->> EVOLUTIONARY GENETIC ALGORITHM <<---------------###############################
	//####################################################################################################


	void setCheckAllLocalCombinations_optimizer(bool checkAllLocalCom);

	void setRings_optimizer(unsigned int rings);
	void setArms_optimizer(unsigned int arms);
	void setMinGapSurface_optimizer(real minGap);

	//generate a random number in between two values
	real randomNumber(real min, real max);

	int randomIndex(int min, int max);

	//generating a number of Random optical Systems
	void RANDOMIZE_SYSTEMS();

	//calculating the Fitness of all the members based on RMS values
	void FITNESS_CALCULATE();


	//pick a optical system from the fitness factor
	OpticalSystemElement pickParent();
	OpticalSystemElement pickBestParent();
	//dna permutation of the two parents resulting in a new member of the population
	OpticalSystemElement crossoverPermutation(OpticalSystemElement parentA, OpticalSystemElement parentB);

	//crossover Function with a new population with mutation rate
	void CrossOverPopulation();

	std::vector<OpticalSystemElement> getGenerationOfSystems();

	OpticalSystemElement getStartSystem();

	localStart getLocalStart();
	void setLocalStart(localStart locStart);

	OpticalSystemElement genetic_algorithm();

	void calcPosApertureStop();

	OpticalSystemElement caseSwitcher(OpticalSystemElement optSysEle, localStart localCase);

	OpticalSystemElement localOptimizationStart_BM(OpticalSystemElement optSysEle);

	//void localalgorithm();

	real calculateRMSallFieldAndWavelength(OpticalSystemElement optSysEle);


	//Merit Function
	void MERIT_CALCULATE();
	real calculateMerit(OpticalSystemElement optSysEle);

	real CALCULATE_LOCAL_IMAGEQUALITY();

	OpticalSystemElement optimizePosition(OpticalSystemElement optSysEle, real stepsStart, real meritOld);
	OpticalSystemElement optimizeRadius(OpticalSystemElement optSysEle, real stepsStart, real meritOld);

	int fRand_int(int min, int max);
	std::vector<int> fRand_int_vec(std::vector<int> indices);

	//get best optical system
	OpticalSystemElement getBestOptSys(std::vector<OptSysEleAndMeritStruct> optSysAndMerit_vec);



//	void TheWinningTwelve();

	void optimizeSUPERFUNCTION();

	// get optimized optical system element
	OpticalSystemElement getOptSysOptimized_Ele() const;

	// get optimized optical system LLT
	OpticalSystem_LLT getOptSysOptimized_LLT();

	// get EFL after optimasation
	real getEFL_AO();
	// get z position of EXPP after optimasation
	real getEXPP_z_AO();
	// get EXPD after optimasation
	real getEXPD_AO();

	bool distanceChecker(std::vector<OpticalSystemElement> optSysEleVec, std::vector<DistanceAdjustmentStruct> disAdjustmentStruct);
	std::vector<OpticalSystemElement> adjustDistances(std::vector <OpticalSystemElement> optSysEleVec, std::vector<DistanceAdjustmentStruct> disAdjustStr);


	bool checkIfOneDistanceIsVariable();
	bool checkIfOneRadiusIsVariabel();

	void calculateSumFitnessValuse();

	void saveDurationTimeGeneticOpti_min(double saveTime);
	void saveDurationTimeLocalOpti_min(double saveTime);

	//export times (genetic and local) and population
	void exportTimesAndPupulation_txt(std::string location, std::string nameLocation);

	// delete and free momory of vector with points
	//void delAndFreeMemory(std::vector<OpticalSystemElement> optSysEle_vec);

	void localOptimizatio_BM();

	real getDurationTimeGeneticOptiInMin();

	real getDurationTimeLocalOptiInMin();

	unsigned int getNumberGenerations();
	real getPopulation();
	FieldAndLightStruct getFieldAndLightConfig();
	MeritConfiguration getMeritConfig();
	OptimizeParameters getOptimizeParameters();
	real getMutationRate();


private:

	//initialization of the input system parameters with default settings
	FieldAndLightStruct	mFWL_Config;
	MeritConfiguration	mMF_Config;
	OptimizeParameters	mOP_Config;

	// that is the system we get to optimize
	OpticalSystemElement mOptSysElementStart;

	// that is thr optimized system from the genetic optimizer
	OpticalSystemElement mOptimizedOptSysEle_GeneticOptimizer;

	// that is the optimized system from the local optimizer
	OpticalSystemElement mOptimizedOptSysEle_LocalOptimizer;

	unsigned int	mPopulation;
	localStart	mLocalStart;
	real	mMutationRate;
	real	mLengthOpticalSystem;

	unsigned int mGenerationCount;

	//parameters that are going to be calculated from the input
	std::vector<OpticalSystemElement>	mGenerationOfSystems;
	std::vector<OpticalSystemElement>	mSecondGeneration;

	//std::vector<real>	mEFL_VALUES;
	//std::vector<real>	mEXPP_VALUES;
	//std::vector<real>	mEXPD_VALUES;

	std::vector<real>	mMERIT_VALUES;
	std::vector<real>	mFITNESS_VALUES;

	std::vector<real>	mRMS_FIELDS_LOCAL;
	real mEFL_LOCAL;
	real mEXPP_LOCAL;
	real mEXPD_LOCAL;
	real mRMS_LOCAL;
	real mMERIT_LOCAL;
	real mImageQuality_local;
	

	std::vector<real>	mBest_MERIT_VALUE_of_Gen;

	unsigned int mPositionApertureStop;
	std::vector<DistanceAdjustmentStruct> mDistanceAdjustment;


	std::vector<int> mRadiusVariable;
	std::vector<int> mPointVariable;
	

	bool mIsOneDistanceVariable;
	bool mIsOneRadiusVariable;

	real mSumFitnessValuse;

	real mDurationTime_Genetic_Opti;
	real mDurationTime_Local_Opti;

};

