#pragma once

#include "importantOptimizeStructs.h"

struct defaultParaDLS
{

public:

	defaultParaDLS();
	~defaultParaDLS();
	
	// damping factor
	real getDampingFactor();
	void setDampingFactor(real dampingFactor);
	// radius factor deviation
	real getFactorRadiusDeviation();
	void setFactorRadiusDeviation(real factorRadisuDev);
	// position factor deviation
	real getFactorPositionDeviation();
	void setFactorPositionDeviation(real factorPositionDev);
	// start refractive index
	real getStartRefractivIndex();
	void setStartRefractivIndex(real startRefIndex);
	// max worst counter
	unsigned int getMaxWorstCounter();
	void setMaxWorstCounter(unsigned int maxWorstCounter);
	// improvement merit stop difference
	real getImprovMeritStopDiff();
	void setImproveMeritStopDiff(real impMeritStopDiff);
	// maximal interations 
	unsigned int getMaxIterations();
	void setMaxInterations(unsigned int maxInterations);
	// flip orientation radius
	real getFlipOrientationRadius();
	void setFlipOrientationRadius(real flipRadius);
	// max border violations
	unsigned int getMaxBoundViolations();
	void setMaxBorderViolations(unsigned maxBoderViol);
	// max delta parameter
	void setMaxDeltaParameter(real maxDelta);
	real getMaxDeltaParameter();
	// min delta parameter
	void setMinDeltaParameter(real minDelta);
	real getMinDeltaParameter();
	// factor getting better
	void setFactorGettingBetter(real factorGetBetter);
	real getFactorGettingBetter();
	// factor getting worst
	void setFactorGettingWorst(real factorGetWorst);
	real getFactorGettingWorst();
	// tolerance without min radius
	void setToleranceWithoutMin(real toleranceWithoutMin);
	real getToleranceWithoutMin();
	// without max radius
	void setToleranceWithoutMax(real toleranceWithoutMax);
	real getToleranceWithoutMax();
	// min damping number before switch factors
	void set_Min_DamNumBefSwitchFactors(real minBeforeSwitchFactors);
	real get_Min_DamNumBefSwitchFactors();
		// max damping number before switch factors
	void set_Max_DamNumBefSwitchFactors(real maxBeforeSwitchFactors);
	real get_Max_DamNumBefSwitchFactors();

private:
	real mDampingFactor{};
	real mChangeRadiusFactorDeviation{};
	real mChangePositionFactorDeviation{};
	real mStartRefractivIndex{};
	unsigned int mMaxWorstCounter{};
	real mImprovementMeritStopDiff{};
	unsigned int mMaxIterations{};
	real mFlipRadius{};
	real mMinThickness_Z_Default{};
	real mMaxThickness_Z_Default{};
	unsigned int mMaxBorderViolations{};
	real mMaxDeltaPara{};
	real mMinDeltaPara{};
	real mFactorGettingBetter{};
	real mFactorGettingWorst{}; 
	real mToleranceWithout_MIN_radius{};
	real mToleranceWithout_MAX_radius{};
	real m_Min_DampingNumberBeforSwitchFactors{};
	real m_Max_DampingNumberBeforeSwitchFactors{};
	
};





class DLS
{

public:

	DLS();
	DLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms);
	DLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, defaultParaDLS defaultParameterDLS);
	~DLS();

	void buildAndLoad(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, defaultParaDLS defaultParameterDLS);
	std::vector<OpticalSystem_LLT> deepCopyOptSysLLT_vec(std::vector<OpticalSystem_LLT> optSys_LLT_vec);

	void loadDefaultParameter();
	void loadAdditionalDefaultParameter();
	void buildOptSys_LLT_wave_vec();
	void calcJacobiMatrixDeviation_Aij();
	void changeRadiusSurfaceTo(unsigned int surfaceNo, real newRadius);
	void changePosition_Z_SurfaceTo(unsigned int surfaceNo, real newPositionZ);
	void changeThickness_Z_SurfaceTo(unsigned int surfaceNo, real newThickness);
	void optimizeSystem_DLS_multiplicativ_Damping();
	void NOT_WORKING_optimizeSystem_DLS_additive_Damping();

	//void calcChange_Radius_AccordingToMeritVal();
	//void calcChange_Position_AccordingToMeritVal();

	std::vector<real> calculateDeviation(real oldVal, real newVal, unsigned surfaceNum, kindParaOptSys tempKindPara);


	real checkBounderiesAndReturnNewVal(real val, unsigned int posDeltaVal, real minVal, real maxVal, real withoutMin, real withoutMax, unsigned int tempSurfaceNum, kindParaOptSys kindPar);

	real calculateMeritVal_RMS(const VectorStructR3& fieldPoint);
	void calculateAberrationFct();

	std::vector<std::vector<real>> calc_A_T_times_A();

	std::vector<real> calc_invMatrix_times_A_T_F(const std::vector<std::vector<real>>& matrix, const std::vector<real>& vector);

	void fillJacobiMatrix(std::vector<real> vector, unsigned int row);

	void setNewSystemParameter();

	void resizeAllRelevantStdVectorsAndCalcConst();

	void calcJacobi_times_Aberration();

	void saveCurMeritAndBestMeritValue();

	bool checkMeritBetter();

	void printCurVariables();
	
	OpticalSystemElement getOptimizedSystem_HLT();

	// *** default parameters *** ///
	// damping factor
	real getDampingFactor();
	void setDampingFactor(real dampingFactor);
	// radius factor deviation
	real getFactorRadiusDeviation();
	void setFactorRadiusDeviation(real factorRadisuDev);
	// position factor deviation
	real getFactorPositionDeviation();
	void setFactorPositionDeviation(real factorPositionDev);
	// start refractive index
	real getStartRefractivIndex();
	void setStartRefractivIndex(real startRefIndex);
	// max worst counter
	unsigned int getMaxWorstCounter();
	void setMaxWorstCounter(unsigned int maxWorstCounter);
	// improvement merit stop difference
	real getImprovMeritStopDiff();
	void setImproveMeritStopDiff(real impMeritStopDiff);
	// maximal interations 
	unsigned int getMaxIterations();
	void setMaxInterations(unsigned int maxInterations);
	// flip orientation radius
	real getFlipOrientationRadius();
	void setFlipOrientationRadius(real flipRadius);
	// max border violations
	unsigned int getMaxBoundViolations();
	void setMaxBorderViolations(unsigned maxBoderViol);
	// max delta parameter
	void setMaxDeltaParameter(real maxDelta);
	real getMaxDeltaParameter();
	// min delta parameter
	void setMinDeltaParameter(real minDelta);
	real getMinDeltaParameter();
	// factor getting better
	void setFactorGettingBetter(real factorGetBetter);
	real getFactorGettingBetter();
	// factor getting worst
	void setFactorGettingWorst(real factorGetWorst);
	real getFactorGettingWorst();
	// min damping number before switch factors
	void set_Min_DamNumBefSwitchFactors(real minBeforeSwitchFactors);
	real get_Min_DamNumBefSwitchFactors();
	// max damping number before switch factors
	void set_Max_DamNumBefSwitchFactors(real maxBeforeSwitchFactors);
	real get_Max_DamNumBefSwitchFactors();
	// *** *** ///

	unsigned int checkImprovementMeritVal(unsigned int iterCounter, const real& impMeritStop);

	void loadThicknessParameter();
	
	std::vector<OpticalSystem_LLT> getOptSys_LLT_vec();
	bool checkBorderViolations(unsigned tempBorderViol);
	void resizeAfterFix();

	void calc_F_T_times_F();
	void calcF_T_times_A_times_A_T_times_F();
	void calc_individualDampingFactors();
	void calcA_T_A_plusIndDampFac();

	void halfInvertedMatrix(std::vector<std::vector<real>> invertedMatrix);
	void scaleSystemParameters(std::vector<real>&  tempSysParam, real scale);

	void checkDeltaParameter(std::vector<real>& deltaSysPara_vec);

	std::vector<VectorStructR3> getField_vec();
	std::vector<real> getWavelength_vev();
	unsigned int getRings();
	unsigned int getArms();
	OpticalSystemElement getInitialOpticalSystemHLT();

	real getBestMeritValue();

	// load without min and Max default
	void loadWithoutMinMaxDefault();

	void loadBestFactorBetterFactorWorstCombinations();

	void fixRadiusSurface_i(unsigned int surfaceNo);
	void fixThicknessSurface_i(unsigned int surfaceNo);

private:

	std::vector<OpticalSystem_LLT> mOptSys_LLT_vec{};
	std::vector<OpticalSystem_LLT> mChangedOptSys_LLT_vec{};
	std::vector<OpticalSystem_LLT> mBestOptSys_LLT_vec{};
	OpticalSystemElement mOpticalSystemEle_initial{};
	OpticalSystemElement mOpticaSystemEle_change{};
	std::vector<VectorStructR3> mFields_vec{};
	std::vector<real> mWeightFields_vec{};
	std::vector<real> mWavelenght_vec{};
	std::vector<unsigned int> mWeightWavelenght_vec{};
	unsigned int mRings{};
	unsigned int mArms{};

	real mCurrentMeritValue;
	defaultParaDLS mDefaultParamDLS{};
	parameterVar mParameterVar{};
	std::vector<std::vector<real>> mJacobi_Aij{};
	Light_LLT mDefaultLight{};
	
	std::vector<real> mAberrationFct_F0{};
	std::vector<real> mNewSystemParameter{};
	unsigned int mNumFieldPoints{};
	std::vector<real> mReturnDeviation_vec{};
	std::vector<real> mDeviationAberrationFct{};
	

	unsigned int mColumns_A_T_A{};
	unsigned int mRows_A_T_A{};
	unsigned int mNumVar{};
	unsigned int mNumOptSys{};
	VectorStructR3 mNewPosition{};
	unsigned int mPosLastSurface{};
	std::vector<real> mReturnVector_invMatrix_times_A_T_F{};

	std::vector<real> mAllMeritVal{};
	real mTempMeritVal{};
	real mBeforeMeritVal{};
	real mBestMeritVal{};

	real mDampingNum{};

	unsigned int mSizeOptSys{};

	std::vector<real> mThickness_vec{};

	std::vector<unsigned int> mBorderViolCounter_Radius{};
	std::vector<unsigned int> mBorderViolCounter_Thickness{};


	//std::vector<posAndOrientation> mPosAndOrientationRadius_save;
	//unsigned int mPosVarRadiusInVec;

	std::vector<real> mA_T_times_F{};
	std::vector<std::vector<real>> m_A_T_A{};
	std::vector<std::vector<real>> mA_T_times_A_PlusIndivDampFac{};
	real mF_T_times_F{};
	real mF_T_times_A_times_A_T_times_F{};
	real mIndividualDampingFactor{};

	std::vector<withOutMinMax> mWithoutMinMax{};

	bool mGlobalStop{};
	std::vector<real> mTempDeltaNewSysPara{};
	
	unsigned int mWorstCounter = 0;
	unsigned int mIterationCounter = 0;

	bool mInBoundery{};

	std::vector<real> factorBetter_vec{};
	std::vector<real> factorWorst_vec{};
	unsigned int mSizeFacrotBetterWorstVec{};
	unsigned int mCounterChangeFactorBetterWorst{};

};