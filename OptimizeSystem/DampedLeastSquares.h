#pragma once

#include "importantOptimizeStructs.h"
#include "..\Image\ImageSimulation.h"

// image processing
#include "..\ImageProcessing\ImageProcessing.h"


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
	// calculate rms using ray tracing
	void turn_ON_calcRMSusingRayTracing();
	void turn_OFF_caclRMSusingRayTracing();
	bool getCalcRMSusingRayTracing();


private:
	real mDampingFactor{};
	real mChangeRadiusFactorDeviation{};
	real mChangePositionFactorDeviation{};
	real mStartRefractivIndex{};
	unsigned int mMaxWorstCounter{};
	real mImprovementMeritStopDiff{};
	unsigned int mMaxIterations{};
	real mFlipRadius{};
	unsigned int mMaxBorderViolations{};
	real mMaxDeltaPara{};
	real mMinDeltaPara{};
	real mFactorGettingBetter{};
	real mFactorGettingWorst{};
	real mToleranceWithout_MIN_radius{};
	real mToleranceWithout_MAX_radius{};
	real m_Min_DampingNumberBeforSwitchFactors{};
	real m_Max_DampingNumberBeforeSwitchFactors{};
	bool mCalcRMSaccordingToRayTracing{};

};





class DLS
{

public:

	DLS();
	DLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms);
	DLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, defaultParaDLS defaultParameterDLS);
	DLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, bool turnON_Off_rayTracing, targetCardinalPointsStruct targetCardinalPoint);
	DLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, targetCardinalPointsStruct targetCardinalPoint, defaultParaDLS defaultParameterDLS);

	DLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<real> /*fields X*/ fields_X, std::vector<real> /*fields Y*/ fields_Y, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms);
	DLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<real> /*fields X*/ fields_X, std::vector<real> /*fields Y*/ fields_Y, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, bool turnON_Off_rayTracing, targetCardinalPointsStruct targetCardinalPoint);
	DLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<real> /*fields X*/ fields_X, std::vector<real> /*fields Y*/ fields_Y, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, targetCardinalPointsStruct targetCardinalPoint, defaultParaDLS defaultParameterDLS);
	~DLS();


	// *** obj ***
	void DLS_superFctDLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, targetCardinalPointsStruct targetCardinalPoint, defaultParaDLS defaultParameterDLS);
	void DLS_superFctDLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, defaultParaDLS defaultParameterDLS);
	// *** ***

	// *** inf ***
	void DLS_superFctDLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<real> /*fields X*/ fieldVec_X, std::vector<real> /*fields*/ fieldVec_Y, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, targetCardinalPointsStruct targetCardinalPoint, defaultParaDLS defaultParameterDLS);
	void DLS_superFctDLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<real> /*fields X*/ fieldVec_X, std::vector<real> /*fields*/ fieldVec_Y, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, defaultParaDLS defaultParameterDLS);
	// *** ***

	void buildAndLoad(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, defaultParaDLS defaultParameterDLS);
	std::vector<OpticalSystem_LLT> deepCopyOptSysLLT_vec(std::vector<OpticalSystem_LLT> optSys_LLT_vec);

	void loadDefaultParameter();
	void loadAdditionalDefaultParameter();
	void buildOptSys_LLT_wave_vec();
	void calcJacobiMatrixDeviation_Aij();
	void changeRadiusSurfaceTo_allWavelength(unsigned int surfaceNo, real newRadius);
	void changeRadiusSurfaceTo_HLT(unsigned int surfaceNo, real newRadius);

	void changePosition_Z_SurfaceTo(unsigned int surfaceNo, real newPositionZ);
	void changeThickness_Z_SurfaceTo_All(unsigned int surfaceNo, real newThickness);
	void changeThickness_Z_SurfaceTo_primWavelength(unsigned int surfaceNo, real newThickness);
	void changeThickness_Z_SurfaceTo_HLT(unsigned int surfaceNo, real newThickness);

	// ***
	void optimizeSystem_DLS_multiplicativ_Damping();
	void NOT_WORKING_optimizeSystem_DLS_additive_Damping();

	//void calcChange_Radius_AccordingToMeritVal();
	//void calcChange_Position_AccordingToMeritVal();

	std::vector<real> calculateDeviation_rmsRayTrace(real oldVal, real newVal, unsigned surfaceNum, kindParaOptSys tempKindPara);
	std::vector<real> calculateDeviation_targetCarPoints(real oldVal, real newVal, unsigned surfaceNum, kindParaOptSys tempKindPara);
	std::vector<real> calculateDeviation_ImageProcessing(real oldVal, real newVal, unsigned surfaceNum, kindParaOptSys tempKindPara);


	real checkBounderiesAndReturnNewVal(real val, unsigned int posDeltaVal, real minVal, real maxVal, real withoutMin, real withoutMax, unsigned int tempSurfaceNum, kindParaOptSys kindPar);

	//real calculateMeritVal();
	real calculateMeritVal_RMS_obj(const VectorStructR3& fieldPoint);
	real calculateMeritVal_RMS_inf(real angleX, real angleY);
	real calculateMeritVal_imageProcessing();
	real calculateMeritVal_protectMinWFNO_imaProc();

	void calculateAberrationFct();

	std::vector<std::vector<real>> calc_A_T_times_A();

	std::vector<real> calc_invMatrix_times_A_T_F(const std::vector<std::vector<real>>& matrix, const std::vector<real>& vector);

	void fillJacobiMatrix_RMS(std::vector<real> vector, unsigned int row);
	//void fillJacobiMatrix_CarPoint(real deviation);

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
	// calculate rms using ray tracing
	void turn_ON_calcRMSusingRayTracing();
	void turn_OFF_calcRMSusingRayTracing();
	bool getCalcRMSusingRayTracing();
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
	void scaleSystemParameters(std::vector<real>& tempSysParam, real scale);

	void checkDeltaParameter(std::vector<real>& deltaSysPara_vec);

	std::vector<VectorStructR3> getField_vec();
	std::vector<real> getFieldAngles_X();
	std::vector<real> getFieldAngle_Y();
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
	objectPoint_inf_obj getInfOrObj();

	void setTargetCardinalPoints(const targetCardinalPointsStruct& targetCarPoints);
	targetCardinalPointsStruct getTargetCardinalPoints();

	void setWeightFields(std::vector<real> weightField_vec);
	std::vector<real> getWeigthFields();

	void setWeightWavelength(std::vector<unsigned int> weightWavelength_vec);
	std::vector<unsigned int> getWeightWavelength();


	// *** image simulation / processing
	void turnOFF_imageProcessing();
	void turnON_imageProcessing();

	void setParameterImageSimulation(loadParaImaSim paraImaSim);
	loadParaImaSim getParameterImageSimulation();

	void turnOnImaProc();
	void turnOffImaProc();

	void setImageProcessing(imageProcessing imaProc);
	imageProcessing getImageProcessing();

	void setObject(cv::Mat obj);
	cv::Mat getObject();

	void setCompareImagePercent(real comPercent);
	real getCompateImagePercent();

	void setWeightImaProc(real weight);
	real getWeightImaProc();

	void setImageProcessingSuperFct(ImaProcSuperFct imaProcSuperFct);
	ImaProcSuperFct getImaProcessingSuperFct();

	void setMinWFNO_imaProc(real minWFNO);
	real getMinWFNO_imaProc();

	void setPotenzProtectMinWFNO_imaProc(real potenz);
	real getPotenzProtectMinWFNO_imaProc();

	real asympoticFuncProtecWFNO(real tempWFNO);

	void setReloadParameterChangePercent(real percent);
	// ***

	// set optical system element
	void setOpticalSystemElement(OpticalSystemElement optSysEle);
	// set inf of obj
	void setInfObj(objectPoint_inf_obj inf_obj);
	// load systems for difference color
	void loadSystemsForDifferenceColors(std::vector<real> wavelength_vec);
	// load system parameter
	void loadSystemParameter();

	// check matrix for nan
	bool checkMatrixForNAN(const std::vector<std::vector<real>>& matrix);

private:

	std::vector<OpticalSystem_LLT> mOptSys_LLT_vec{};
	std::vector<OpticalSystem_LLT> mChangedOptSys_LLT_vec{};
	std::vector<OpticalSystem_LLT> mBestOptSys_LLT_vec{};
	OpticalSystemElement mOpticalSystemEle_initial{};
	OpticalSystemElement mOpticaSystemEle_change{};
	std::vector<VectorStructR3> mFields_obj_vec{};
	std::vector<real> mFields_X_inf_vec{};
	std::vector<real> mFields_Y_inf_vec{};

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
	unsigned int mNumFieldPoints_Angles{};
	unsigned int mNumTargetCarPoints{};
	unsigned int mNumImaProc{};
	std::vector<real> mReturnDeviation_RMS_vec{};
	std::vector<real> mReturnDeviation_targetCarPoints_vec{};
	std::vector<real> mReturnDeviation_imageProcessing_vec{};
	std::vector<real> mDeviationAberrationFct_RMS{};
	std::vector<real> mDeviationAberrationFct_targetCarPoint{};
	std::vector<real> mDeviationAberrationFct_ImageProcessing{};
	real mDeviatonVal_targetCarPoint{};


	unsigned int mColumns_A_T_A{};
	unsigned int mRows_A_T_A{};
	unsigned int mNumVar{};
	unsigned int mNumOptSys{};
	VectorStructR3 mNewPosition{};
	unsigned int mPosLastSurface{};
	unsigned int mPosFillJacobi{};
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
	bool mThereIsA_NAN{};
	std::vector<real> mTempDeltaNewSysPara{};

	unsigned int mWorstCounter = 0;
	unsigned int mIterationCounter = 0;

	bool mInBoundery{};

	std::vector<real> factorBetter_vec{};
	std::vector<real> factorWorst_vec{};
	unsigned int mSizeFacrotBetterWorstVec{};
	unsigned int mCounterChangeFactorBetterWorst{};

	objectPoint_inf_obj mInf_Obj{};

	targetCardinalPointsStruct mTargetCardinalPoints{};

	// image simulation / processing
	loadParaImaSim mParaImaSim;
	ImageSimulationFunctions mImaSimSuperFct;
	bool mTurnOnOffImageProcessing;
	imageProcessing mImaProc;
	cv::Mat mObject{};
	int numberIma{};
	real mComPercent{};
	real mWeightImaProcessing{};
	ImaProcSuperFct mImaProcSuperFct{};
	real mPotenzProtectMinWFNO_imaProc{};
	real mMinWFNO_imaProc{};
	bool mFirstImaProc{};
	real mReloadParameterChangePercent{};




};