#include "DampedLeastSquares.h"
#include "..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\FillAptertureStop\FillApertureStop.h"
#include "..\RayAiming\RayAiming.h"
#include "..\oftenUseNamespace\oftenUseNamespace.h"


defaultParaDLS::defaultParaDLS(){}
defaultParaDLS::~defaultParaDLS(){};

// damping factor
real defaultParaDLS::getDampingFactor()
{
	return mDampingFactor;
}
void defaultParaDLS::setDampingFactor(real dampingFactor)
{
	mDampingFactor = dampingFactor;
}
// radius factor deviation
real defaultParaDLS::getFactorRadiusDeviation()
{
	return mChangeRadiusFactorDeviation;
}
void defaultParaDLS::setFactorRadiusDeviation(real factorRadisuDev)
{
	mChangeRadiusFactorDeviation = factorRadisuDev;
}
// position factor deviation
real defaultParaDLS::getFactorPositionDeviation()
{
	return mChangePositionFactorDeviation;
}
void defaultParaDLS::setFactorPositionDeviation(real factorPositionDev)
{
	mChangePositionFactorDeviation = factorPositionDev;
}
// start refractive index
real defaultParaDLS::getStartRefractivIndex()
{
	return mStartRefractivIndex;
}
void defaultParaDLS::setStartRefractivIndex(real startRefIndex)
{
	mStartRefractivIndex = startRefIndex;
}
// max worst counter
unsigned int defaultParaDLS::getMaxWorstCounter()
{
	return mMaxWorstCounter;
}
void defaultParaDLS::setMaxWorstCounter(unsigned int maxWorstCounter)
{
	mMaxWorstCounter = maxWorstCounter;
}
// improvement merit stop difference
real defaultParaDLS::getImprovMeritStopDiff()
{
	return mImprovementMeritStopDiff;
}
void defaultParaDLS::setImproveMeritStopDiff(real impMeritStopDiff)
{
	mImprovementMeritStopDiff = impMeritStopDiff;
}

unsigned int defaultParaDLS::getMaxIterations()
{
	return mMaxIterations;
}
void defaultParaDLS::setMaxInterations(unsigned int maxInterations)
{
	mMaxIterations = maxInterations;
}

// flip orientation radius
real defaultParaDLS::getFlipOrientationRadius()
{
	return mFlipRadius;
}
void defaultParaDLS::setFlipOrientationRadius(real flipRadius)
{
	mFlipRadius = flipRadius;
}
// max border violations
unsigned int defaultParaDLS::getMaxBoundViolations()
{
	return mMaxBorderViolations;
}
void defaultParaDLS::setMaxBorderViolations(unsigned maxBoderViol)
{
	mMaxBorderViolations = maxBoderViol;
}
// max delta parameter
void defaultParaDLS::setMaxDeltaParameter(real maxDelta)
{
	mMaxDeltaPara = maxDelta;
}
real defaultParaDLS::getMaxDeltaParameter()
{
	return mMaxDeltaPara;
}
// min delta parameter
void defaultParaDLS::setMinDeltaParameter(real minDelta)
{
	mMinDeltaPara = minDelta;
}
real defaultParaDLS::getMinDeltaParameter()
{
	return mMinDeltaPara;
}
// factor getting better
void defaultParaDLS::setFactorGettingBetter(real factorGetBetter)
{
	mFactorGettingBetter = factorGetBetter;
}
real defaultParaDLS::getFactorGettingBetter()
{
	return mFactorGettingBetter;
}

// factor getting worst
void defaultParaDLS::setFactorGettingWorst(real factorGetWorst)
{
	mFactorGettingWorst = factorGetWorst;
}

real defaultParaDLS::getFactorGettingWorst()
{
	return mFactorGettingWorst;
}

// without min radius
void defaultParaDLS::setToleranceWithoutMin(real toleranceWithoutMin)
{
	mToleranceWithout_MIN_radius = toleranceWithoutMin;
}

real defaultParaDLS::getToleranceWithoutMin()
{
	return mToleranceWithout_MIN_radius;
}

// without max radius
void defaultParaDLS::setToleranceWithoutMax(real toleranceWithoutMax)
{
	mToleranceWithout_MAX_radius = toleranceWithoutMax;
}

real defaultParaDLS::getToleranceWithoutMax()
{
	return mToleranceWithout_MAX_radius;
}
// min damping number before switch factors
void defaultParaDLS::set_Min_DamNumBefSwitchFactors(real minBeforeSwitchFactors)
{
	m_Min_DampingNumberBeforSwitchFactors = minBeforeSwitchFactors;
}
real defaultParaDLS::get_Min_DamNumBefSwitchFactors()
{
	return m_Min_DampingNumberBeforSwitchFactors;
}
// max damping number before switch factors
void defaultParaDLS::set_Max_DamNumBefSwitchFactors(real maxBeforeSwitchFactors)
{
	m_Max_DampingNumberBeforeSwitchFactors = maxBeforeSwitchFactors;
}
real defaultParaDLS::get_Max_DamNumBefSwitchFactors()
{
	return m_Max_DampingNumberBeforeSwitchFactors;
}
// calculate rms using ray tracing
void defaultParaDLS::turn_ON_calcRMSusingRayTracing()
{
	mCalcRMSaccordingToRayTracing = true;
}
void defaultParaDLS::turn_OFF_caclRMSusingRayTracing()
{
	mCalcRMSaccordingToRayTracing = false;
}
bool defaultParaDLS::getCalcRMSusingRayTracing()
{
	return mCalcRMSaccordingToRayTracing;
}


DLS::DLS() {};
DLS::DLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms) :
mOpticalSystemEle_initial(optSysEle.getDeepCopyOptSysEle()),
mOpticaSystemEle_change(optSysEle.getDeepCopyOptSysEle()),
mFields_obj_vec(fields),
mWavelenght_vec(wavelengths),
mRings(rings),
mArms(arms)
{
	mInf_Obj = objectPoint_inf_obj::obj;
	loadDefaultParameter();
	loadAdditionalDefaultParameter();
	buildOptSys_LLT_wave_vec();	
	mParameterVar.loadSystemParameter(mOpticalSystemEle_initial);
	mChangedOptSys_LLT_vec = deepCopyOptSysLLT_vec(mOptSys_LLT_vec);
	mBestOptSys_LLT_vec = deepCopyOptSysLLT_vec(mOptSys_LLT_vec);
	resizeAllRelevantStdVectorsAndCalcConst();
	loadWithoutMinMaxDefault();
	loadThicknessParameter();
	loadBestFactorBetterFactorWorstCombinations();
}
DLS::DLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, defaultParaDLS defaultParameterDLS) :
mOpticalSystemEle_initial(optSysEle.getDeepCopyOptSysEle()),
mOpticaSystemEle_change(optSysEle.getDeepCopyOptSysEle()),
mFields_obj_vec(fields),
mWavelenght_vec(wavelengths),
mRings(rings),
mArms(arms),
mDefaultParamDLS(defaultParameterDLS)
{
	mInf_Obj = objectPoint_inf_obj::obj;
	loadAdditionalDefaultParameter();
	buildOptSys_LLT_wave_vec();
	mParameterVar.loadSystemParameter(mOpticalSystemEle_initial);
	mChangedOptSys_LLT_vec = deepCopyOptSysLLT_vec(mOptSys_LLT_vec);
	mBestOptSys_LLT_vec = deepCopyOptSysLLT_vec(mOptSys_LLT_vec);
	resizeAllRelevantStdVectorsAndCalcConst();
	loadWithoutMinMaxDefault();
	loadThicknessParameter();
	loadBestFactorBetterFactorWorstCombinations();
}

DLS::DLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, bool turnON_Off_rayTracing, targetCardinalPointsStruct targetCardinalPoint) :
mOpticalSystemEle_initial(optSysEle.getDeepCopyOptSysEle()),
mOpticaSystemEle_change(optSysEle.getDeepCopyOptSysEle()),
mFields_obj_vec(fields),
mWavelenght_vec(wavelengths),
mRings(rings),
mArms(arms),
mTargetCardinalPoints(targetCardinalPoint)
{
	mInf_Obj = objectPoint_inf_obj::obj;
	loadDefaultParameter();
	if (turnON_Off_rayTracing)
	{
		mDefaultParamDLS.turn_ON_calcRMSusingRayTracing();
	}
	else
	{
		mDefaultParamDLS.turn_OFF_caclRMSusingRayTracing();
	}
	loadAdditionalDefaultParameter();
	buildOptSys_LLT_wave_vec();
	mParameterVar.loadSystemParameter(mOpticalSystemEle_initial);
	mChangedOptSys_LLT_vec = deepCopyOptSysLLT_vec(mOptSys_LLT_vec);
	mBestOptSys_LLT_vec = deepCopyOptSysLLT_vec(mOptSys_LLT_vec);


	resizeAllRelevantStdVectorsAndCalcConst();
	loadWithoutMinMaxDefault();
	loadThicknessParameter();
	loadBestFactorBetterFactorWorstCombinations();
}

DLS::DLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, targetCardinalPointsStruct targetCardinalPoint, defaultParaDLS defaultParameterDLS) :
	mOpticalSystemEle_initial(optSysEle.getDeepCopyOptSysEle()),
	mOpticaSystemEle_change(optSysEle.getDeepCopyOptSysEle()),
	mFields_obj_vec(fields),
	mWavelenght_vec(wavelengths),
	mRings(rings),
	mArms(arms),
	mTargetCardinalPoints(targetCardinalPoint),
	mDefaultParamDLS(defaultParameterDLS)
{
	mInf_Obj = objectPoint_inf_obj::obj;

	loadAdditionalDefaultParameter();
	buildOptSys_LLT_wave_vec();
	mParameterVar.loadSystemParameter(mOpticalSystemEle_initial);
	mChangedOptSys_LLT_vec = deepCopyOptSysLLT_vec(mOptSys_LLT_vec);
	mBestOptSys_LLT_vec = deepCopyOptSysLLT_vec(mOptSys_LLT_vec);

	resizeAllRelevantStdVectorsAndCalcConst();
	loadWithoutMinMaxDefault();
	loadThicknessParameter();
	loadBestFactorBetterFactorWorstCombinations();
}

DLS::DLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<real> /*fields X*/ fields_X, std::vector<real> /*fields Y*/ fields_Y, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms) :
mOpticalSystemEle_initial(optSysEle.getDeepCopyOptSysEle()),
mOpticaSystemEle_change(optSysEle.getDeepCopyOptSysEle()),
mFields_X_inf_vec(fields_X),
mFields_Y_inf_vec(fields_Y),
mWavelenght_vec(wavelengths),	
mRings(rings),
mArms(arms)
{
	mInf_Obj = objectPoint_inf_obj::inf;
	loadDefaultParameter();
	loadAdditionalDefaultParameter();
	buildOptSys_LLT_wave_vec();
	mParameterVar.loadSystemParameter(mOpticalSystemEle_initial);
	mChangedOptSys_LLT_vec = deepCopyOptSysLLT_vec(mOptSys_LLT_vec);
	mBestOptSys_LLT_vec = deepCopyOptSysLLT_vec(mOptSys_LLT_vec);
	resizeAllRelevantStdVectorsAndCalcConst();
	loadWithoutMinMaxDefault();
	loadThicknessParameter();
	loadBestFactorBetterFactorWorstCombinations();
}

DLS::DLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<real> /*fields X*/ fields_X, std::vector<real> /*fields Y*/ fields_Y, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, bool turnON_Off_rayTracing, targetCardinalPointsStruct targetCardinalPoint) :
mOpticalSystemEle_initial(optSysEle.getDeepCopyOptSysEle()),
mOpticaSystemEle_change(optSysEle.getDeepCopyOptSysEle()),
mFields_X_inf_vec(fields_X),
mFields_Y_inf_vec(fields_Y),
mWavelenght_vec(wavelengths),
mRings(rings),
mArms(arms),
mTargetCardinalPoints(targetCardinalPoint)
{
	mInf_Obj = objectPoint_inf_obj::inf;
	loadDefaultParameter();
	if (turnON_Off_rayTracing)
	{
		mDefaultParamDLS.turn_ON_calcRMSusingRayTracing();
	}
	else
	{
		mDefaultParamDLS.turn_OFF_caclRMSusingRayTracing();
	}
	loadAdditionalDefaultParameter();
	buildOptSys_LLT_wave_vec();
	mParameterVar.loadSystemParameter(mOpticalSystemEle_initial);
	mChangedOptSys_LLT_vec = deepCopyOptSysLLT_vec(mOptSys_LLT_vec);
	mBestOptSys_LLT_vec = deepCopyOptSysLLT_vec(mOptSys_LLT_vec);


	resizeAllRelevantStdVectorsAndCalcConst();
	loadWithoutMinMaxDefault();
	loadThicknessParameter();
	loadBestFactorBetterFactorWorstCombinations();


}
DLS::DLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<real> /*fields X*/ fields_X, std::vector<real> /*fields Y*/ fields_Y, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, targetCardinalPointsStruct targetCardinalPoint, defaultParaDLS defaultParameterDLS) :
	mOpticalSystemEle_initial(optSysEle.getDeepCopyOptSysEle()),
	mOpticaSystemEle_change(optSysEle.getDeepCopyOptSysEle()),
	mFields_X_inf_vec(fields_X),
	mFields_Y_inf_vec(fields_Y),
	mWavelenght_vec(wavelengths),
	mRings(rings),
	mArms(arms),
	mTargetCardinalPoints(targetCardinalPoint),
	mDefaultParamDLS(defaultParameterDLS)
{
	mInf_Obj = objectPoint_inf_obj::inf;

	loadAdditionalDefaultParameter();
	buildOptSys_LLT_wave_vec();
	mParameterVar.loadSystemParameter(mOpticalSystemEle_initial);
	mChangedOptSys_LLT_vec = deepCopyOptSysLLT_vec(mOptSys_LLT_vec);
	mBestOptSys_LLT_vec = deepCopyOptSysLLT_vec(mOptSys_LLT_vec);

	resizeAllRelevantStdVectorsAndCalcConst();
	loadWithoutMinMaxDefault();
	loadThicknessParameter();
	loadBestFactorBetterFactorWorstCombinations();
}

DLS::~DLS() {};

void DLS::buildAndLoad(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, defaultParaDLS defaultParameterDLS)
{
	mOpticalSystemEle_initial = optSysEle.getDeepCopyOptSysEle();
	mOpticaSystemEle_change = optSysEle.getDeepCopyOptSysEle();
	mFields_obj_vec = fields;
	mWavelenght_vec = wavelengths;
	mRings = rings;
	mArms = arms;
	mDefaultParamDLS = defaultParameterDLS;

	mInf_Obj = objectPoint_inf_obj::obj;
	loadAdditionalDefaultParameter();
	buildOptSys_LLT_wave_vec();
	mParameterVar.loadSystemParameter(mOpticalSystemEle_initial);
	resizeAllRelevantStdVectorsAndCalcConst();
	mChangedOptSys_LLT_vec = deepCopyOptSysLLT_vec(mOptSys_LLT_vec);
	mBestOptSys_LLT_vec = deepCopyOptSysLLT_vec(mOptSys_LLT_vec);
	loadWithoutMinMaxDefault();
	loadThicknessParameter();
	loadBestFactorBetterFactorWorstCombinations();
}

void DLS::resizeAllRelevantStdVectorsAndCalcConst()
{
	
	mAberrationFct_F0.resize(mNumFieldPoints_Angles + mNumTargetCarPoints);

	mReturnDeviation_RMS_vec.resize(mNumFieldPoints_Angles);
	mReturnDeviation_targetCarPoints_vec.resize(mNumTargetCarPoints);

	mNumVar = mParameterVar.getAllParaWithVar().size();
	mJacobi_Aij.resize(mNumFieldPoints_Angles + mNumTargetCarPoints);
	oftenUse::resizeAllRowsMatrix(mJacobi_Aij, mNumVar);

	mDeviationAberrationFct_RMS.resize(mNumFieldPoints_Angles);
	mDeviationAberrationFct_targetCarPoint.resize(mNumTargetCarPoints);


	mPosFillJacobi = 0;

	mColumns_A_T_A = mJacobi_Aij.size();
	mRows_A_T_A = mJacobi_Aij[0].size();

	m_A_T_A.resize(mRows_A_T_A);
	oftenUse::resizeAllRowsMatrix(m_A_T_A, mRows_A_T_A);

	mA_T_times_A_PlusIndivDampFac.resize(mRows_A_T_A);
	oftenUse::resizeAllRowsMatrix(mA_T_times_A_PlusIndivDampFac, mRows_A_T_A);

	mNewPosition.setX(0.0);
	mNewPosition.setY(0.0);
	mNewPosition.setZ(0.0);

	mSizeOptSys = mOpticalSystemEle_initial.getPosAndElement().size();
	mPosLastSurface = mSizeOptSys - 1;

	mA_T_times_F.resize(mRows_A_T_A);
	mReturnVector_invMatrix_times_A_T_F.resize(mRows_A_T_A);

	mWithoutMinMax.resize(mNumVar);




	mThickness_vec.resize(mPosLastSurface);

	mBorderViolCounter_Radius.resize(mSizeOptSys);
	std::fill(mBorderViolCounter_Radius.begin(), mBorderViolCounter_Radius.end(), 0);
	mBorderViolCounter_Thickness.resize(mSizeOptSys);
	std::fill(mBorderViolCounter_Thickness.begin(), mBorderViolCounter_Thickness.end(), 0);
	
	mIndividualDampingFactor = 1000.0;

	mGlobalStop = true;
	mInBoundery = true;

	mCounterChangeFactorBetterWorst = 0;

	// 
	//calculateAberrationFct();
	mAllMeritVal.push_back(oftenUse::getInfReal());
	mBestMeritVal = mAllMeritVal[0];
}

std::vector<OpticalSystem_LLT> DLS::deepCopyOptSysLLT_vec(std::vector<OpticalSystem_LLT> optSys_LLT_vec)
{
	std::vector<OpticalSystem_LLT> returnDeepCopy_vec;
	returnDeepCopy_vec.resize(mNumOptSys); // --
	OpticalSystem_LLT optSysLLT_deep;

	for (unsigned int i = 0; i < mNumOptSys; ++i)
	{
		optSysLLT_deep = optSys_LLT_vec[i].clone();
		returnDeepCopy_vec[i] = optSysLLT_deep;
	}

	return returnDeepCopy_vec;
}

void DLS::loadDefaultParameter()
{
	mDefaultParamDLS.setDampingFactor(5.0);
	mDefaultParamDLS.setFactorRadiusDeviation(0.000001);
	mDefaultParamDLS.setFactorPositionDeviation(0.000001);
	mDefaultParamDLS.setStartRefractivIndex(1.0);
	mDefaultParamDLS.setMaxWorstCounter(250);
	mDefaultParamDLS.setImproveMeritStopDiff(0.00000001);
	//mDefaultParamDLS.setMaxInterations(1);
	mDefaultParamDLS.setMaxInterations(500);
	mDefaultParamDLS.setFlipOrientationRadius(1000.0);
	mDefaultParamDLS.setMaxBorderViolations(30);
	mDefaultParamDLS.setMaxDeltaParameter(25.0);
	mDefaultParamDLS.setMinDeltaParameter(0.00000001);
	mDefaultParamDLS.setFactorGettingBetter(0.4);
	mDefaultParamDLS.setFactorGettingWorst(1.9);

	mDefaultParamDLS.setToleranceWithoutMin(-0.5);
	mDefaultParamDLS.setToleranceWithoutMax(0.5);

	mDefaultParamDLS.set_Min_DamNumBefSwitchFactors(0.00001);
	mDefaultParamDLS.set_Max_DamNumBefSwitchFactors(9999.0);

	mDefaultParamDLS.turn_ON_calcRMSusingRayTracing();
}


void DLS::loadAdditionalDefaultParameter()
{
	// rms from obj
	if (mInf_Obj == objectPoint_inf_obj::obj && mDefaultParamDLS.getCalcRMSusingRayTracing())
	{	
		mNumFieldPoints_Angles = mFields_obj_vec.size();
	}

	// rms from inf
	else if (mInf_Obj == objectPoint_inf_obj::inf && mDefaultParamDLS.getCalcRMSusingRayTracing())
	{
		if (mFields_X_inf_vec.size() != mFields_Y_inf_vec.size())
		{
			std::cout << "ATTENTION: number angles X is not number angle Y" << std::endl;
		}

		mNumFieldPoints_Angles = mFields_X_inf_vec.size();

	}

	// cardinal points
	if (mTargetCardinalPoints.getIsOneTargetCardinalPoint())
	{
		mNumTargetCarPoints = mTargetCardinalPoints.getNumerOfTargets();
	}

	mWeightFields_vec.resize(mNumFieldPoints_Angles); // --
	std::fill(mWeightFields_vec.begin(), mWeightFields_vec.end(), 1.0);

	// weight wavelength default
	unsigned int numWavelength = mWavelenght_vec.size();
	mWeightWavelenght_vec.resize(numWavelength); // --
	std::fill(mWeightWavelenght_vec.begin(), mWeightWavelenght_vec.end(), 1.0);

	// build defautl light
	mDefaultLight.setIntensity(1.0);
	mDefaultLight.setJonesVector({ 1.0,1.0,1.0,1.0 });
	mDefaultLight.setTypeLight(typeLight::typeLightRay);
	mDefaultLight.setWavelength(550.0);


}

void DLS::buildOptSys_LLT_wave_vec()
{
	mNumOptSys = mWavelenght_vec.size();
	mOptSys_LLT_vec.resize(mNumOptSys); // --

	OpticalSystem_LLT tempOptSys;
	
	for(unsigned int i = 0; i<mNumOptSys;++i)
	{
		mOpticalSystemEle_initial.setRefractiveIndexAccordingToWavelength(mWavelenght_vec[i]);

		tempOptSys = mOpticalSystemEle_initial.getOptSys_LLT_buildSystem();
		mOptSys_LLT_vec[i] = tempOptSys;

	}
	
}

void DLS::changeRadiusSurfaceTo_allWavelength(unsigned int surfaceNo, real newRadius)
{	
	real radiusFlipper = mDefaultParamDLS.getFlipOrientationRadius();

	for (unsigned int i = 0; i < mNumOptSys; ++i)
	{
		

		if (radiusFlipper > newRadius)
		{
			mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNo].getSurfaceInterRay_ptr()->setRadius(std::abs(newRadius));
			
		}
		else // radiusFlipper < newRadius
		{
			real currentRefIndex_A = mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNo].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
			real currentRefIndex_B = mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNo].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
			VectorStructR3 curDirection = mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNo].getSurfaceInterRay_ptr()->getDirection();

			mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNo].getSurfaceInterRay_ptr()->setRadius(radiusFlipper - 1);
			mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNo].getSurfaceInterRay_ptr()->setRefractiveIndexSide_A(currentRefIndex_B);
			mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNo].getSurfaceInterRay_ptr()->setRefractiveIndexSide_B(currentRefIndex_A);
			mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNo].getSurfaceInterRay_ptr()->setDirection(-1.0 * curDirection);
		
			//mDampingNum = mDampingNum * 10.0 ;
			mIterationCounter = 0;
			mWorstCounter = 0;
		}
	
	}

}


void DLS::changeThickness_Z_SurfaceTo_All(unsigned int surfaceNo, real newThickness)
{
	real tempSurface_Pos_Z;
	real tempNewPosNextSurface_Z;
	real deltaThickness;
	unsigned int counter = 1;

	for (unsigned int i = 0; i < mNumOptSys; ++i)
	{
		tempSurface_Pos_Z = mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNo].getSurfaceInterRay_ptr()->getPoint().getZ();
		deltaThickness = newThickness - mThickness_vec[surfaceNo];
		tempNewPosNextSurface_Z  = tempSurface_Pos_Z + newThickness;

		while(surfaceNo + counter < mSizeOptSys)
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

void DLS::changeThickness_Z_SurfaceTo_primWavelength(unsigned int surfaceNo, real newThickness)
{
	real tempSurface_Pos_Z;
	real tempNewPosNextSurface_Z;
	real deltaThickness;
	unsigned int counter = 1;


	tempSurface_Pos_Z = mChangedOptSys_LLT_vec[0].getPosAndInteractingSurface()[surfaceNo].getSurfaceInterRay_ptr()->getPoint().getZ();
	deltaThickness = newThickness - mThickness_vec[surfaceNo];
	tempNewPosNextSurface_Z = tempSurface_Pos_Z + newThickness;

	while (surfaceNo + counter < mSizeOptSys)
	{
		mNewPosition.setZ(tempNewPosNextSurface_Z);
		mChangedOptSys_LLT_vec[0].getPosAndInteractingSurface()[surfaceNo + counter].getSurfaceInterRay_ptr()->setPosition(mNewPosition);
		++counter;
		if (surfaceNo + counter < mSizeOptSys)
		{
			tempNewPosNextSurface_Z = mChangedOptSys_LLT_vec[0].getPosAndInteractingSurface()[surfaceNo + counter].getSurfaceInterRay_ptr()->getPoint().getZ();
			tempNewPosNextSurface_Z = tempNewPosNextSurface_Z + deltaThickness;
		}


	}
	counter = 1;
	
}

void DLS::changePosition_Z_SurfaceTo(unsigned int surfaceNo, real newPositionZ)
{
	mNewPosition.setZ(newPositionZ);
	
	for (unsigned int i = 0; i < mNumOptSys; ++i)
	{
		mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNo].getSurfaceInterRay_ptr()->setPosition(mNewPosition);
	}

}

real DLS::calculateMeritVal_RMS_obj(const VectorStructR3& fieldPoint)
{
	real returnMerit_RMS = 0.0;
	FillApertureStop fillAperStop(mChangedOptSys_LLT_vec[0], mRings, mArms);
	unsigned int tempWeightWavelengh;

	// ray aiming
	RayAiming rayAiming(mChangedOptSys_LLT_vec[0]);
	//rayAiming.loadImportantInfosForRayAiming();
	rayAiming.turn_ON_GlobalStopIfToManyRaysAreNotAimed();

	std::vector<LightRayStruct> tempAimedLightRays{};
	SequentialRayTracing seqTrace;
	seqTrace.setTraceToSurface(mPosLastSurface);

	std::vector<VectorStructR3> tempInterPoints;
	std::vector<VectorStructR3> allInterPoints;

	for (unsigned int i = 0; i < mNumOptSys; ++i)
	{
		rayAiming.setOpticalSystem_LLT(mChangedOptSys_LLT_vec[i]);
		tempWeightWavelengh = mWeightWavelenght_vec[i];
		tempAimedLightRays = rayAiming.rayAimingMany_obj(fillAperStop.getPointsInAS(), fieldPoint, mDefaultLight, mDefaultParamDLS.getStartRefractivIndex());
		if (rayAiming.getGlobalStop())
		{
			i = mNumOptSys + i;
		}
		else
		{
			// trace ray
			seqTrace.setOpticalSystem(mChangedOptSys_LLT_vec[i]);
			seqTrace.seqRayTracingWithVectorOfLightRays(tempAimedLightRays);
			
		}


	}

	real numberInterPoints;
	real numberExpecteInterPoints;

	if (rayAiming.getGlobalStop())
	{
		returnMerit_RMS = oftenUse::getInfReal();
	}

	else
	{
		// check for vignetting
		numberExpecteInterPoints = fillAperStop.getPointsInAS().size();
		numberInterPoints = seqTrace.getAllInterPointsAtSurface_i_filtered(mPosLastSurface).size() / mNumOptSys;

		if (std::abs(numberExpecteInterPoints - numberInterPoints) <= 0.0001)
		{
			std::vector<VectorStructR3> interPointsLastSurface = seqTrace.getAllInterPointsAtSurface_i_filtered(mPosLastSurface);

			Spot spot(interPointsLastSurface, interPointsLastSurface[0]);
			returnMerit_RMS = spot.getRMS_�m();
		}

		else // there is vignetting
		{
			returnMerit_RMS = oftenUse::getInfReal();

		}

	}

	// just for debugging
	//std::cout << "number inter points last surface: " << numberInterPoints << std::endl;

	return returnMerit_RMS;
}

real DLS::calculateMeritVal_RMS_inf(real angleX, real angleY)
{
	real returnMerit_RMS{};
	FillApertureStop fillAperStop(mChangedOptSys_LLT_vec[0], mRings, mArms);
	unsigned int tempWeightWavelengh;

	// ray aiming
	RayAiming rayAiming(mChangedOptSys_LLT_vec[0]);
	rayAiming.loadImportantInfosForRayAiming();
	rayAiming.turn_ON_GlobalStopIfToManyRaysAreNotAimed();

	std::vector<LightRayStruct> tempAimedLightRays{};
	SequentialRayTracing seqTrace;
	seqTrace.setTraceToSurface(mPosLastSurface);

	std::vector<VectorStructR3> tempInterPoints;
	std::vector<VectorStructR3> allInterPoints;

	for (unsigned int i = 0; i < mNumOptSys; ++i)
	{
		rayAiming.setOpticalSystem_LLT(mChangedOptSys_LLT_vec[i]);
		tempWeightWavelengh = mWeightWavelenght_vec[i];
		tempAimedLightRays = rayAiming.rayAimingMany_inf(fillAperStop.getPointsInAS(), angleX, angleY, mDefaultLight, mDefaultParamDLS.getStartRefractivIndex());
		if (rayAiming.getGlobalStop())
		{
			i = mNumOptSys + i;
		}
		else
		{
			// trace ray
			seqTrace.setOpticalSystem(mChangedOptSys_LLT_vec[i]);
			seqTrace.seqRayTracingWithVectorOfLightRays(tempAimedLightRays);
			
		}


	}

	real numberInterPoints;
	real numberExpecteInterPoints;

	if (rayAiming.getGlobalStop())
	{
		returnMerit_RMS = oftenUse::getInfReal();
	}

	else
	{
		// check for vignetting
		numberExpecteInterPoints = fillAperStop.getPointsInAS().size();
		numberInterPoints = seqTrace.getAllInterPointsAtSurface_i_filtered(mPosLastSurface).size() / mNumOptSys;

		if (std::abs(numberExpecteInterPoints - numberInterPoints) <= 0.0001)
		{
			std::vector<VectorStructR3> interPointsLastSurface = seqTrace.getAllInterPointsAtSurface_i_filtered(mPosLastSurface);

			Spot spot(interPointsLastSurface, interPointsLastSurface[0]);
			returnMerit_RMS = spot.getRMS_�m();
		}

		else // there is vignetting
		{
			returnMerit_RMS = oftenUse::getInfReal();

		}

	}

	// just for debugging
	//std::cout << "number inter points last surface: " << numberInterPoints << std::endl;

	return returnMerit_RMS;

}

void DLS::calculateAberrationFct()
{
		
	VectorStructR3 tempFieldPoint{};
	real tempFieldAngle_X{};
	real tempFieldAngle_Y{};
	real tempWeightFieldPoint{};
	real tempMeritField = 0.0;
	unsigned int i = 0;

	if (mInf_Obj == objectPoint_inf_obj::obj && mDefaultParamDLS.getCalcRMSusingRayTracing())
	{
		for (i; i < mNumFieldPoints_Angles; ++i)
		{
			tempFieldPoint = mFields_obj_vec[i];
			tempWeightFieldPoint = mWeightFields_vec[i];
			tempMeritField = calculateMeritVal_RMS_obj(tempFieldPoint);
			mAberrationFct_F0[i] = tempWeightFieldPoint * tempMeritField;
		}
	}

	else if (mInf_Obj == objectPoint_inf_obj::inf && mDefaultParamDLS.getCalcRMSusingRayTracing())
	{
		for (i; i < mNumFieldPoints_Angles; ++i)
		{
			tempFieldAngle_X = mFields_X_inf_vec[i];
			tempFieldAngle_Y = mFields_Y_inf_vec[i];
			tempWeightFieldPoint = mWeightFields_vec[i];
			tempMeritField = calculateMeritVal_RMS_inf(tempFieldAngle_X, tempFieldAngle_Y);
			mAberrationFct_F0[i] = tempWeightFieldPoint * tempMeritField;
		}
	}
 

	if (mTargetCardinalPoints.getIsOneTargetCardinalPoint())
	{
		mTargetCardinalPoints.calcualteMeritVal_targetCardinalPoints_forDLS(mChangedOptSys_LLT_vec[0], mInf_Obj,mAberrationFct_F0);
	}


}

std::vector<real> DLS::calculateDeviation_rmsRayTrace(real oldVal, real newVal, unsigned surfaceNum, kindParaOptSys tempKindPara)
{
	real tempNewMeritValue{};
	real tempDiviation;
	
	

	if (tempKindPara == radiusVar)
	{
		//calcChange_Radius_AccordingToMeritVal();
		//changeRadiusSurfaceTo(surfaceNum, newVal);
		changeRadiusSurfaceTo_allWavelength(surfaceNum, newVal);

		for(unsigned int i=0; i< mNumFieldPoints_Angles;++i)
		{ 

			if (mInf_Obj == objectPoint_inf_obj::obj && mDefaultParamDLS.getCalcRMSusingRayTracing())
			{
				tempNewMeritValue = calculateMeritVal_RMS_obj(mFields_obj_vec[i]);
			}

			else if (mInf_Obj == objectPoint_inf_obj::inf && mDefaultParamDLS.getCalcRMSusingRayTracing())
			{
				tempNewMeritValue = calculateMeritVal_RMS_inf(mFields_X_inf_vec[i], mFields_Y_inf_vec[i]);
			}
			
			tempDiviation = (tempNewMeritValue - mAberrationFct_F0[i]) / mDefaultParamDLS.getFactorRadiusDeviation();
				
			mReturnDeviation_RMS_vec[i] = tempDiviation;
		}

		changeRadiusSurfaceTo_allWavelength(surfaceNum, oldVal);
		
	}

	else if (tempKindPara == thickness_Var)
	{
		//calcChange_Position_AccordingToMeritVal();
		changeThickness_Z_SurfaceTo_All(surfaceNum, newVal);
		mThickness_vec[surfaceNum] = newVal;
		for (unsigned int i = 0; i < mNumFieldPoints_Angles; ++i)
		{
			if (mInf_Obj == objectPoint_inf_obj::obj && mDefaultParamDLS.getCalcRMSusingRayTracing())
			{
				tempNewMeritValue = calculateMeritVal_RMS_obj(mFields_obj_vec[i]);
			}

			else if (mInf_Obj == objectPoint_inf_obj::inf && mDefaultParamDLS.getCalcRMSusingRayTracing())
			{
				tempNewMeritValue = calculateMeritVal_RMS_inf(mFields_X_inf_vec[i], mFields_Y_inf_vec[i]);
			}
			
			
			tempDiviation = (tempNewMeritValue - mAberrationFct_F0[i]) / mDefaultParamDLS.getFactorPositionDeviation();
			mReturnDeviation_RMS_vec[i] = tempDiviation;
		}
		
		changeThickness_Z_SurfaceTo_All(surfaceNum, oldVal);
		mThickness_vec[surfaceNum] = oldVal;
	}


	return mReturnDeviation_RMS_vec;
}

std::vector<real> DLS::calculateDeviation_targetCarPoints(real oldVal, real newVal, unsigned surfaceNum, kindParaOptSys tempKindPara)
{
	real tempNewMeritValue{};
	real tempDiviation;


	if (tempKindPara == radiusVar)
	{
		mChangedOptSys_LLT_vec[0].getPosAndInteractingSurface()[surfaceNum].getSurfaceInterRay_ptr()->setRadius(std::abs(newVal));


		if (mInf_Obj == objectPoint_inf_obj::obj)
		{
			mTargetCardinalPoints.calcualteMeritVal_targetCardinalPoints_forDLS(mChangedOptSys_LLT_vec[0],objectPoint_inf_obj::obj, mDeviationAberrationFct_targetCarPoint);
		}

		else if (mInf_Obj == objectPoint_inf_obj::inf)
		{
			mTargetCardinalPoints.calcualteMeritVal_targetCardinalPoints_forDLS(mChangedOptSys_LLT_vec[0], objectPoint_inf_obj::inf, mDeviationAberrationFct_targetCarPoint);
		}

		mChangedOptSys_LLT_vec[0].getPosAndInteractingSurface()[surfaceNum].getSurfaceInterRay_ptr()->setRadius(std::abs(oldVal));
	
		for (unsigned int i = 0; i < mNumTargetCarPoints; ++i)
		{
			tempNewMeritValue = mDeviationAberrationFct_targetCarPoint[i];

			tempDiviation = (tempNewMeritValue - mAberrationFct_F0[i + mNumFieldPoints_Angles]) / mDefaultParamDLS.getFactorRadiusDeviation();
			mReturnDeviation_targetCarPoints_vec[i] = tempDiviation;
		}
		
	}

	else if (tempKindPara == thickness_Var)
	{
		//calcChange_Position_AccordingToMeritVal();
		changeThickness_Z_SurfaceTo_primWavelength(surfaceNum, newVal);
		mThickness_vec[surfaceNum] = newVal;


		if (mInf_Obj == objectPoint_inf_obj::obj && mDefaultParamDLS.getCalcRMSusingRayTracing())
		{
			mTargetCardinalPoints.calcualteMeritVal_targetCardinalPoints_forDLS(mChangedOptSys_LLT_vec[0], objectPoint_inf_obj::obj, mDeviationAberrationFct_targetCarPoint);
		}

		else if (mInf_Obj == objectPoint_inf_obj::inf && mDefaultParamDLS.getCalcRMSusingRayTracing())
		{
			mTargetCardinalPoints.calcualteMeritVal_targetCardinalPoints_forDLS(mChangedOptSys_LLT_vec[0], objectPoint_inf_obj::inf, mDeviationAberrationFct_targetCarPoint);
		}

		changeThickness_Z_SurfaceTo_primWavelength(surfaceNum, oldVal);
		mThickness_vec[surfaceNum] = oldVal;

		for (unsigned int i = 0; i < mNumTargetCarPoints; ++i)
		{
			tempNewMeritValue = mDeviationAberrationFct_targetCarPoint[i];

			tempDiviation = (tempNewMeritValue - mAberrationFct_F0[i + mNumFieldPoints_Angles]) / mDefaultParamDLS.getFactorPositionDeviation();
			mReturnDeviation_targetCarPoints_vec[i] = tempDiviation;
		}

	}

	return mReturnDeviation_targetCarPoints_vec;
}

void DLS::calcJacobiMatrixDeviation_Aij()
{
	std::vector<unsigned int> surfaceNumWithVar = mParameterVar.getAllSurfaceNumWithVar();
	real tempVal;
	real newVal;
	VectorStructR3 tempFieldPoint;

	unsigned int tempSurfaceNum{};
	kindParaOptSys tempKindPara{};

	if (mDefaultParamDLS.getCalcRMSusingRayTracing())
	{ 
		for (unsigned int i = 0; i < mNumVar; ++i)
		{
			tempSurfaceNum = surfaceNumWithVar[i];
			tempKindPara = mParameterVar.getAllParaWithVar()[i];


			if (tempKindPara == radiusVar)
			{
				tempVal = mChangedOptSys_LLT_vec[0].getPosAndInteractingSurface()[tempSurfaceNum].getSurfaceInterRay_ptr()->getRadius();
				newVal = tempVal + mDefaultParamDLS.getFactorRadiusDeviation();

				mDeviationAberrationFct_RMS = calculateDeviation_rmsRayTrace(tempVal, newVal, tempSurfaceNum, tempKindPara);

				// just for debugging
				// std::cout << "deviation surface: " << tempSurfaceNum << " " << mDeviationAberrationFct[0] + mDeviationAberrationFct[1] + mDeviationAberrationFct[2] << std::endl;

			}

			else if (tempKindPara == thickness_Var)
			{
				tempVal = mThickness_vec[tempSurfaceNum];
				newVal = tempVal + mDefaultParamDLS.getFactorPositionDeviation();

				mDeviationAberrationFct_RMS = calculateDeviation_rmsRayTrace(tempVal, newVal, tempSurfaceNum, tempKindPara);
			}

			fillJacobiMatrix_RMS(mDeviationAberrationFct_RMS, i);
			mPosFillJacobi = 0.0;
		}
	}

	if (mTargetCardinalPoints.getIsOneTargetCardinalPoint())
	{
		std::vector<unsigned int> surfaceNumWithVar = mParameterVar.getAllSurfaceNumWithVar();
		real tempVal;
		real newVal;

		unsigned int tempSurfaceNum{};
		kindParaOptSys tempKindPara{};


		for (unsigned int i = 0; i < mNumVar; ++i)
		{
			tempSurfaceNum = surfaceNumWithVar[i];
			tempKindPara = mParameterVar.getAllParaWithVar()[i];
			mPosFillJacobi = mNumFieldPoints_Angles;

			if (tempKindPara == radiusVar)
			{
				tempVal = mChangedOptSys_LLT_vec[0].getPosAndInteractingSurface()[tempSurfaceNum].getSurfaceInterRay_ptr()->getRadius();
				newVal = tempVal + mDefaultParamDLS.getFactorRadiusDeviation();

				mDeviationAberrationFct_targetCarPoint = calculateDeviation_targetCarPoints(tempVal, newVal, tempSurfaceNum, tempKindPara);
			}

			else if (tempKindPara == thickness_Var)
			{
				tempVal = mThickness_vec[tempSurfaceNum];
				newVal = tempVal + mDefaultParamDLS.getFactorPositionDeviation();
				mDeviationAberrationFct_targetCarPoint = calculateDeviation_targetCarPoints(tempVal, newVal, tempSurfaceNum, tempKindPara);
			}


			fillJacobiMatrix_RMS(mDeviationAberrationFct_targetCarPoint,i);

		}

		mPosFillJacobi = 0;
	}
	

	// just for debugging
	//oftenUse::print(mJacobi_Aij);
	
}

void DLS::fillJacobiMatrix_RMS(std::vector<real> vector, unsigned int row)
{	
	unsigned int sizeVec = vector.size();

	for (unsigned int i = 0; i < sizeVec; i++)
	{
		mJacobi_Aij[mPosFillJacobi][row] = vector[i];
		++mPosFillJacobi;
	}
	
}

//void DLS::fillJacobiMatrix_CarPoint(real deviation)
//{
//		mJacobi_Aij[mPosFillJacobi][0] = deviation;
//		++mPosFillJacobi;
//}

real DLS::checkBounderiesAndReturnNewVal(real val, unsigned int posDeltaValt, real minVal, real maxVal, real withoutMin, real withoutMax, unsigned int tempSurfaceNum, kindParaOptSys kindPara)
{
	bool tempBorderViolations;
	real tempDeltaVal = mTempDeltaNewSysPara[posDeltaValt];
	real newVal = val + tempDeltaVal;

	if (newVal < 0.0 || (newVal > withoutMin && newVal < withoutMax))
	{
		
		mInBoundery = false;
		mTempDeltaNewSysPara[posDeltaValt] = 0.0;
		// just for debugging
		// std::cout << "value is not allowed" << std::endl;
		return val;
	}

	real checkValNeg = newVal - 0.001;
	real checkVapPos = newVal + 0.0001;
	bool checkerNeg = checkValNeg < minVal;
	bool checkerPos = checkVapPos > maxVal;
	// just for debugging
	// std::cout << "check if there is boarder violoation from NEGATIV side" << checkerNeg << std::endl;
	// std::cout << "check if there is boarder violoation from POSITIV side" << checkerPos << std::endl;
	if (checkerNeg)
	{ 
		mInBoundery = false;
		// just for debugging
		// std::cout << "boundery check is false" << std::endl;	

		real newDeltaVal = (minVal - newVal) + tempDeltaVal;
		mTempDeltaNewSysPara[posDeltaValt] = newDeltaVal;

		if (kindPara == radiusVar)
		{
			mBorderViolCounter_Radius[tempSurfaceNum]++;
			tempBorderViolations = checkBorderViolations(mBorderViolCounter_Radius[tempSurfaceNum]);
			if (tempBorderViolations)
			{
				fixRadiusSurface_i(tempSurfaceNum);
			}

			
		}
		else if (kindPara == thickness_Var)
		{
			mBorderViolCounter_Thickness[tempSurfaceNum]++;
			tempBorderViolations = checkBorderViolations(mBorderViolCounter_Thickness[tempSurfaceNum]);
			if (tempBorderViolations)
			{
				fixThicknessSurface_i(tempSurfaceNum);
			}
		}
		

		return minVal; 
	}

	else if (checkVapPos > maxVal)
	{ 
		mInBoundery = false;
		// just for debugging
		//std::cout << "boundery check is false" << std::endl;  

		real newDeltaVal = (maxVal - newVal) + tempDeltaVal;
		mTempDeltaNewSysPara[posDeltaValt] = newDeltaVal;

		if (kindPara == radiusVar)
		{
			mBorderViolCounter_Radius[tempSurfaceNum]++;
			tempBorderViolations = checkBorderViolations(mBorderViolCounter_Radius[tempSurfaceNum]);
			if (tempBorderViolations)
			{
				fixRadiusSurface_i(tempSurfaceNum);
			}


		}
		else if (kindPara == thickness_Var)
		{
			mBorderViolCounter_Thickness[tempSurfaceNum]++;
			tempBorderViolations = checkBorderViolations(mBorderViolCounter_Thickness[tempSurfaceNum]);
			if (tempBorderViolations)
			{
				fixThicknessSurface_i(tempSurfaceNum);
			}
		}

		return maxVal; 	
	}

	mInBoundery = true;
	return newVal;
}




std::vector<std::vector<real>> DLS::calc_A_T_times_A()
{



	real tempVal_A_T{};
	real tempVal_A{};

	real tempSaveVal = 0.0;

	unsigned int i = 0;
	unsigned int counter = 0;

	for (unsigned int posRow = 0; counter < mRows_A_T_A; ++posRow )
	{
		for (unsigned int k = 0; k < mRows_A_T_A; ++k )
		{
			for (unsigned int j = 0; j < mColumns_A_T_A; ++j)
			{
				tempVal_A_T = mJacobi_Aij[j][i];
				tempVal_A = mJacobi_Aij[j][posRow];
			
				tempSaveVal = tempVal_A_T * tempVal_A + tempSaveVal;
				
			}
		
			m_A_T_A[i][posRow] = tempSaveVal;
			tempSaveVal = 0.0;
			++i;
		}

		i = 0;
		++counter;

	}
	
	// just for debugging
	// oftenUse::print(m_A_T_A);

	return m_A_T_A;
}

void DLS::calcJacobi_times_Aberration()
{
	real tempValA{};
	real tempValF{};
	real tempSaveVal = 0.0;

	for (unsigned int i = 0; i < mRows_A_T_A; ++i)
	{
		for (unsigned int j = 0; j < mColumns_A_T_A; ++j)
		{
			tempValA = mJacobi_Aij[j][i];
			tempValF = mAberrationFct_F0[j];

			tempSaveVal = tempValA * tempValF + tempSaveVal;

		}

		mA_T_times_F[i] = tempSaveVal;
		tempSaveVal = 0.0;
	}
}

std::vector<real> DLS::calc_invMatrix_times_A_T_F(const std::vector<std::vector<real>>& matrix,const std::vector<real>& vector)
{
	real tempValA{};
	real tempValF{};
	real tempSaveVal = 0.0;
	   	 	
	for (unsigned int i = 0; i < mRows_A_T_A; ++i)
	{
		for (unsigned int j = 0; j < mRows_A_T_A; ++j)
		{
			tempValA = matrix[j][i];
			tempValF = vector[j];

			tempSaveVal = (tempValA * tempValF + tempSaveVal);

		}

		mReturnVector_invMatrix_times_A_T_F[i] = -1.0 * tempSaveVal;
		tempSaveVal = 0.0;
	}

	return mReturnVector_invMatrix_times_A_T_F;
}

void DLS::setNewSystemParameter()
{
	real tempVal;
	real newVal;
	real tempMinVal;
	real tempMaxVal;
	real tempWithout_min;
	real tempWithout_max;

	kindParaOptSys tempKindParameter;
	unsigned int tempSurfaceNum;


	for (unsigned int i = 0; i < mNumVar; ++i)
	{
		tempSurfaceNum = mParameterVar.getAllSurfaceNumWithVar()[i];
		tempKindParameter = mParameterVar.getAllParaWithVar()[i];


		if (tempKindParameter == radiusVar)
		{
			tempMinVal = mParameterVar.getAllMinVar()[i];
			tempMaxVal = mParameterVar.getAllMaxVar()[i];

			tempVal = mChangedOptSys_LLT_vec[0].getPosAndInteractingSurface()[tempSurfaceNum].getSurfaceInterRay_ptr()->getRadius();
			tempWithout_min = mWithoutMinMax[i].getWithoutMin();
			tempWithout_max = mWithoutMinMax[i].getWithoutMax();

			newVal = checkBounderiesAndReturnNewVal(tempVal, i, tempMinVal, tempMaxVal, tempWithout_min, tempWithout_max, tempSurfaceNum, tempKindParameter);

			//just for debugging
			std::cout << "set radius of surface " << tempSurfaceNum << " to " << newVal << std::endl;
			std::cout << std::endl;

			changeRadiusSurfaceTo_allWavelength(tempSurfaceNum, newVal);


		}

		else if (tempKindParameter == thickness_Var)
		{
			tempMinVal = mParameterVar.getAllMinVar()[i];
			tempMaxVal = mParameterVar.getAllMaxVar()[i];


			tempVal = mThickness_vec[tempSurfaceNum];
			tempWithout_min = mWithoutMinMax[i].getWithoutMin();
			tempWithout_max = mWithoutMinMax[i].getWithoutMax();

			
			newVal = checkBounderiesAndReturnNewVal(tempVal, i, tempMinVal, tempMaxVal, tempWithout_min, tempWithout_max, tempSurfaceNum, tempKindParameter);

			

			// just for debugging
			// std::cout << "set thickness of surface " << tempSurfaceNum << " to " << newVal << std::endl;
			// std::cout << std::endl;

			changeThickness_Z_SurfaceTo_All(tempSurfaceNum, newVal);
			mThickness_vec[tempSurfaceNum] = newVal;
		}

	}

}

void DLS::saveCurMeritAndBestMeritValue()
{
	mBeforeMeritVal = mAllMeritVal.back();
	mTempMeritVal = 0.0;


	for (real& n : mAberrationFct_F0)
			mTempMeritVal += n;

	// just for debugging --> print temp merit val
	// std::cout << "temp merit value: " << mTempMeritVal << std::endl;

	mAllMeritVal.push_back(mTempMeritVal);

	if (mTempMeritVal < mBestMeritVal)
	{
		mBestMeritVal = mTempMeritVal;
		mBestOptSys_LLT_vec = deepCopyOptSysLLT_vec(mChangedOptSys_LLT_vec);

	}

	// just for debugging --> print best merit value
	std::cout << "best merit value: " << mBestMeritVal << std::endl;
}

bool DLS::checkMeritBetter()
{
	return mBeforeMeritVal > mTempMeritVal;
}


// we calculate the new system parameter according to the book:
// Classical and Evolutionary Algorithms in the Optimization of Optical System 
// by Darko Vasiljevic
// Springer Science+Busiess Media, LLC
// ISBN: 978-1-4613-5370-6
// --> see page 18
void DLS::optimizeSystem_DLS_multiplicativ_Damping()
{

	std::vector<std::vector<real>> temp_scalar_times_A_T_times_A{};
	std::vector<std::vector<real>> tempInvertedMatrix{};
	

	mDampingNum = (1 + std::pow(mDefaultParamDLS.getDampingFactor(),2));

	mWorstCounter = 0;
	unsigned int maxWorst = mDefaultParamDLS.getMaxWorstCounter();
	mIterationCounter = 0;

	unsigned int maxIterations = mDefaultParamDLS.getMaxIterations();
	bool checkSystem = true;
	real improveMeritStop = mDefaultParamDLS.getImprovMeritStopDiff();


 	calculateAberrationFct();
	// just for debugging -> print aberration fct
	// std::cout << "aberration fct:" << std::endl;
	// oftenUse::print(mAberrationFct_F0);

	saveCurMeritAndBestMeritValue();

	//bool checkSwichMin{};
	//bool checkSwichMax{};

	real minBeforSwitch = mDefaultParamDLS.get_Min_DamNumBefSwitchFactors();
	real maxBeforeSwitch = mDefaultParamDLS.get_Max_DamNumBefSwitchFactors();
	unsigned int absolutStop = 2 * maxIterations;
	unsigned int absolutStopCounter = 0;

	while (maxIterations >= mIterationCounter && mGlobalStop)
	{
			
		if (checkSystem)
		{
			calcJacobiMatrixDeviation_Aij();
			// just for debugging -> print jacobi matrix
			// std::cout << "jacobi matrix:" << std::endl;
			// oftenUse::print(mJacobi_Aij);

			calcJacobi_times_Aberration();
			// just for debugging -> print A_T * F0
			// std::cout << "A_T * F0:" << std::endl;
			// oftenUse::print(mA_T_times_F);

			calc_A_T_times_A();
			// just for debugging -> print A_T * A
			// std::cout << "A_T * A:" << std::endl;
			// oftenUse::print(m_A_T_A);

		}

		// else // we take the old values but changed the dumping factor
		
		temp_scalar_times_A_T_times_A = mDampingNum * m_A_T_A;
		// just for debugging -> print p * A_T * A
		// std::cout << "p * A_T * A:" << std::endl;
		// oftenUse::print(temp_scalar_times_A_T_times_A);

		tempInvertedMatrix = Math::calculateInverse(temp_scalar_times_A_T_times_A);
		// just for debugging -> print inverted matrix
		// std::cout << "inverted matrix" << std::endl;
		// oftenUse::print(tempInvertedMatrix);

		mTempDeltaNewSysPara = calc_invMatrix_times_A_T_F(tempInvertedMatrix, mA_T_times_F);
		// just for debugging -> print delta new system parameter
		// std::cout << "delta system parameter" << std::endl;
		// oftenUse::print(mTempDeltaNewSysPara);
		

		checkDeltaParameter(mTempDeltaNewSysPara);
		setNewSystemParameter();
		//save_tempDeltaNewSysPara = tempDeltaNewSysPara;

		calculateAberrationFct();
				
		// just for debugging -> print aberration fct
		// std::cout << "aberration fct:" << std::endl;
		// oftenUse::print(mAberrationFct_F0);

		// save merit values


		saveCurMeritAndBestMeritValue();

		//// just for debugging
		//int stop = 0;
		//if (std::abs(mBestMeritVal - 185.12987) < 0.01)
		//{
		//	stop = 1;
		//}

		if(mTempMeritVal > mBestMeritVal) // we have to reverse the change
		{ 
			mWorstCounter++;
			mDampingNum = mDefaultParamDLS.getFactorGettingWorst() * mDampingNum;
			

			mTempDeltaNewSysPara = -1.0 *  mTempDeltaNewSysPara;
			setNewSystemParameter();
					
			//std::cout << "max worst: " << maxWorst << std::endl;
			//std::cout << "worst counter: " << worstCounter << std::endl;
			//bool affe = worstCounter > maxWorst;
			//std::cout << "worst counter > max worst" << affe << std::endl;

			checkSystem = false;
			
			// just for debugging
			// std::cout << "worst counter: " << mWorstCounter << std::endl;

			if (mWorstCounter > maxWorst)
			{
				mIterationCounter = maxIterations + 1;
			}

		}

		else  // the system was getting better
		{
			checkSystem = true;
			mDampingNum = mDefaultParamDLS.getFactorGettingBetter() * mDampingNum;
			mIterationCounter++;
			mIterationCounter = checkImprovementMeritVal(mIterationCounter, improveMeritStop);
			// just for debugging
			// std::cout << "interation counter: " << mIterationCounter << std::endl;
		}

		// just for debugging
		// checkSwichMin = mDampingNum < mDefaultParamDLS.get_Min_DamNumBefSwitchFactors();
		// std::cout << "check swich min: " << checkSwichMin << std::endl;
		if(mDampingNum < minBeforSwitch)
		{			
			if(mCounterChangeFactorBetterWorst < mSizeFacrotBetterWorstVec)
			{
				mDampingNum = 1 + std::pow(mDefaultParamDLS.getDampingFactor(), 2);
				mDefaultParamDLS.setFactorGettingBetter(factorBetter_vec[mCounterChangeFactorBetterWorst]);
				mDefaultParamDLS.setFactorGettingWorst(factorWorst_vec[mCounterChangeFactorBetterWorst]);
				mChangedOptSys_LLT_vec = deepCopyOptSysLLT_vec(mBestOptSys_LLT_vec);
				++mCounterChangeFactorBetterWorst;
				checkSystem = true;
			}

			else
			{
				mIterationCounter = maxIterations + 1;
			}
		}

		// just for debugging
		// checkSwichMax = mDampingNum > mDefaultParamDLS.get_Max_DamNumBefSwitchFactors();
		// std::cout << "check swich max: " << checkSwichMax << std::endl;
		if (mDampingNum > maxBeforeSwitch)
		{
			if (mCounterChangeFactorBetterWorst < mSizeFacrotBetterWorstVec)
			{
				mDampingNum = 1 + std::pow(mDefaultParamDLS.getDampingFactor(), 2);
				mDefaultParamDLS.setFactorGettingBetter(factorBetter_vec[mCounterChangeFactorBetterWorst]);
				mDefaultParamDLS.setFactorGettingWorst(factorWorst_vec[mCounterChangeFactorBetterWorst]);
				mChangedOptSys_LLT_vec = deepCopyOptSysLLT_vec(mBestOptSys_LLT_vec);
				++mCounterChangeFactorBetterWorst;
				checkSystem = true;
			}

			else
			{
				mIterationCounter = maxIterations + 1;
			}
		}
		
		
		++absolutStopCounter;
		if (absolutStopCounter > absolutStop)
		{
			mIterationCounter = maxIterations + 1;
			//std::cout << "ABSOLUT STOP" << std::endl;
		}


		
	}


}


void DLS::printCurVariables()
{

	real tempVal;
	kindParaOptSys tempKindParameter;
	unsigned int tempSurfaceNum;

	for (unsigned int i = 0; i < mNumVar; ++i)
	{
		tempSurfaceNum = mParameterVar.getAllSurfaceNumWithVar()[i];
		tempKindParameter = mParameterVar.getAllParaWithVar()[i];

		if (tempKindParameter == radiusVar)
		{
			tempVal = mChangedOptSys_LLT_vec[0].getPosAndInteractingSurface()[tempSurfaceNum].getSurfaceInterRay_ptr()->getRadius();
			//std::cout << "radius of surface " << tempSurfaceNum << " is " << tempVal << std::endl;
			//std::cout << std::endl;

		}

		else if (tempKindParameter == thickness_Var)
		{
			//tempVal = mChangedOptSys_LLT_vec[0].getPosAndInteractingSurface()[tempSurfaceNum].getSurfaceInterRay_ptr()->getPoint().getZ();
			tempVal = mThickness_vec[tempSurfaceNum];
			//std::cout << "thickness Z of surface " << tempSurfaceNum << " is " << tempVal << std::endl;
			//std::cout << std::endl;
		}

	}


}


OpticalSystemElement DLS::getOptimizedSystem_HLT()
{
	return mOpticalSystemEle_initial.convertOptSys_LLT_T0_OptSys_HLT(mOpticalSystemEle_initial, mBestOptSys_LLT_vec[0]);
}

// *** default parameters *** ///
// damping factor
real DLS::getDampingFactor()
{
	return mDefaultParamDLS.getDampingFactor();
}
void DLS::setDampingFactor(real dampingFactor)
{
	mDefaultParamDLS.setDampingFactor(dampingFactor);
}
// radius factor deviation
real DLS::getFactorRadiusDeviation()
{
	return mDefaultParamDLS.getFactorRadiusDeviation();
}
void DLS::setFactorRadiusDeviation(real factorRadisuDev)
{
	mDefaultParamDLS.setFactorRadiusDeviation(factorRadisuDev);
}
// position factor deviation
real DLS::getFactorPositionDeviation()
{
	return mDefaultParamDLS.getFactorPositionDeviation();
}
void DLS::setFactorPositionDeviation(real factorPositionDev)
{
	mDefaultParamDLS.setFactorPositionDeviation(factorPositionDev);
}
// start refractive index
real DLS::getStartRefractivIndex()
{
	return mDefaultParamDLS.getStartRefractivIndex();
}
void DLS::setStartRefractivIndex(real startRefIndex)
{
	mDefaultParamDLS.setStartRefractivIndex(startRefIndex);
}
// max worst counter
unsigned int DLS::getMaxWorstCounter()
{
	return mDefaultParamDLS.getMaxWorstCounter();
}
void DLS::setMaxWorstCounter(unsigned int maxWorstCounter)
{
	mDefaultParamDLS.setMaxWorstCounter(maxWorstCounter);
}
// improvement merit stop difference
real DLS::getImprovMeritStopDiff()
{
	return mDefaultParamDLS.getImprovMeritStopDiff();
}
void DLS::setImproveMeritStopDiff(real impMeritStopDiff) 
{
	mDefaultParamDLS.setImproveMeritStopDiff(impMeritStopDiff);
}
// maximal interations 
unsigned int DLS::getMaxIterations()
{
	return mDefaultParamDLS.getMaxIterations();
}
void DLS::setMaxInterations(unsigned int maxInterations)
{
	mDefaultParamDLS.setMaxInterations(maxInterations);
}
// flip orientation radius
real DLS::getFlipOrientationRadius()
{
	return mDefaultParamDLS.getFlipOrientationRadius();
}
void DLS::setFlipOrientationRadius(real flipRadius)
{
	mDefaultParamDLS.setFlipOrientationRadius(flipRadius);
}
// max border violations
unsigned int DLS::getMaxBoundViolations()
{
	return mDefaultParamDLS.getMaxBoundViolations();
}
void DLS::setMaxBorderViolations(unsigned maxBoderViol)
{
	mDefaultParamDLS.setMaxBorderViolations(maxBoderViol);
}
// max delta parameter
void DLS::setMaxDeltaParameter(real maxDelta)
{
	mDefaultParamDLS.setMaxDeltaParameter(maxDelta);
}
real DLS::getMaxDeltaParameter()
{
	return mDefaultParamDLS.getMaxDeltaParameter();
}
// min delta parameter
void DLS::setMinDeltaParameter(real minDelta)
{
	mDefaultParamDLS.setMinDeltaParameter(minDelta);
}
real DLS::getMinDeltaParameter()
{
	return mDefaultParamDLS.getMinDeltaParameter();
}
// factor getting better
void DLS::setFactorGettingBetter(real factorGetBetter)
{
	mDefaultParamDLS.setFactorGettingBetter(factorGetBetter);
}
real DLS::getFactorGettingBetter()
{
	return mDefaultParamDLS.getFactorGettingBetter();
}
// factor getting worst
void DLS::setFactorGettingWorst(real factorGetWorst)
{
	mDefaultParamDLS.setFactorGettingWorst(factorGetWorst);
}
real DLS::getFactorGettingWorst()
{
	return mDefaultParamDLS.getFactorGettingWorst();
}

// min damping number before switch factors
void DLS::set_Min_DamNumBefSwitchFactors(real minBeforeSwitchFactors)
{
	mDefaultParamDLS.set_Min_DamNumBefSwitchFactors(minBeforeSwitchFactors);
}
real DLS::get_Min_DamNumBefSwitchFactors()
{
	return mDefaultParamDLS.get_Min_DamNumBefSwitchFactors();
}
// max damping number before switch factors
void DLS::set_Max_DamNumBefSwitchFactors(real maxBeforeSwitchFactors)
{
	mDefaultParamDLS.set_Max_DamNumBefSwitchFactors(maxBeforeSwitchFactors);
}
real DLS::get_Max_DamNumBefSwitchFactors()
{
	return mDefaultParamDLS.get_Max_DamNumBefSwitchFactors();
}
void DLS::turn_ON_calcRMSusingRayTracing()
{
	mDefaultParamDLS.turn_ON_calcRMSusingRayTracing();
}
void DLS::turn_OFF_calcRMSusingRayTracing()
{
	mDefaultParamDLS.turn_OFF_caclRMSusingRayTracing();
	mNumFieldPoints_Angles = mTargetCardinalPoints.getNumerOfTargets();
	mAberrationFct_F0.resize(mNumFieldPoints_Angles);
}
bool DLS::getCalcRMSusingRayTracing()
{
	return mDefaultParamDLS.getCalcRMSusingRayTracing();
}
// *** *** ///

unsigned int DLS::checkImprovementMeritVal(unsigned int iterCounter, const real& impMeritStop)
{
	if (std::abs(mBeforeMeritVal - mTempMeritVal) < impMeritStop && mInBoundery)
	{
		return mDefaultParamDLS.getMaxIterations() + 1;
	}

	return iterCounter;
}





void DLS::loadThicknessParameter()
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


std::vector<OpticalSystem_LLT> DLS::getOptSys_LLT_vec()
{
	return mChangedOptSys_LLT_vec;
}

void DLS::fixRadiusSurface_i(unsigned int surfaceNo)
{


	mDampingNum = (1 + std::pow(mDefaultParamDLS.getDampingFactor(), 2));
	mOpticaSystemEle_change.getPosAndElement()[surfaceNo].getElementInOptSys_ptr()->setParameterRadius(0.0, 0.0, 0.0, typeModifierFixed);
	mParameterVar.clear();
	mParameterVar.loadSystemParameter(mOpticaSystemEle_change);
	resizeAfterFix();
	mAllMeritVal.push_back(oftenUse::getInfReal());

	if (mNumVar == 0) // there is no varibale left
	{
		mGlobalStop = false;
	}



}
void DLS::fixThicknessSurface_i(unsigned int surfaceNo)
{
 
	mDampingNum = (1 + std::pow(mDefaultParamDLS.getDampingFactor(), 2));
	mOpticaSystemEle_change.getPosAndElement()[surfaceNo].getElementInOptSys_ptr()->setParameterPointZ(0.0, 0.0, 0.0, typeModifierFixed);
	mParameterVar.clear();
	mParameterVar.loadSystemParameter(mOpticaSystemEle_change);
	resizeAfterFix();
	mAllMeritVal.push_back(oftenUse::getInfReal());

	if (mNumVar == 0) // there is no varibale left
	{
		mGlobalStop = false;
	}
	
}

bool DLS::checkBorderViolations(unsigned tempBorderViol)
{
	if (tempBorderViol > mDefaultParamDLS.getMaxBoundViolations())
	{
		return true;
	}

	return false;
}

void DLS::resizeAfterFix()
{

	mNumVar = mParameterVar.getAllParaWithVar().size();
	oftenUse::resizeAllRowsMatrix(mJacobi_Aij, mNumVar);

	mRows_A_T_A = mJacobi_Aij[0].size();
	m_A_T_A.resize(mRows_A_T_A);
	oftenUse::resizeAllRowsMatrix(m_A_T_A, mRows_A_T_A);

	mA_T_times_F.resize(mRows_A_T_A);
	mReturnVector_invMatrix_times_A_T_F.resize(mRows_A_T_A);

	mBorderViolCounter_Radius.resize(mSizeOptSys);
	std::fill(mBorderViolCounter_Radius.begin(), mBorderViolCounter_Radius.end(), 0);
	mBorderViolCounter_Thickness.resize(mSizeOptSys);
	std::fill(mBorderViolCounter_Thickness.begin(), mBorderViolCounter_Thickness.end(), 0);
}

void DLS::NOT_WORKING_optimizeSystem_DLS_additive_Damping()
{
	
	std::vector<std::vector<real>> tempInvertedMatrix{};

	mDampingNum = (1 + std::pow(mDefaultParamDLS.getDampingFactor(), 2));

	unsigned int worstCounter = 0;
	unsigned int maxWorst = mDefaultParamDLS.getMaxWorstCounter();


	unsigned int iterationCounter = 0;
	unsigned int maxIterations = mDefaultParamDLS.getMaxIterations();
	bool systemGettingbetter = true;
	real improveMeritStop = mDefaultParamDLS.getImprovMeritStopDiff();

	//real scaleSysPara = 1.0;
	calculateAberrationFct();
	// just for debugging -> print aberration fct
	// std::cout << "aberration fct:" << std::endl;
	// oftenUse::print(mAberrationFct_F0);
	saveCurMeritAndBestMeritValue();

	bool calcIndivDampFactor = true;

	while (maxIterations >= iterationCounter)
	{
		

		if (systemGettingbetter)
		{
			calcJacobiMatrixDeviation_Aij();
			//// just for debugging -> print jacobi matrix
			//std::cout << "jacobi matrix:" << std::endl;
			//oftenUse::print(mJacobi_Aij);

			calcJacobi_times_Aberration();
			//// just for debugging -> print A_T * F0
			//std::cout << "A_T * F0:" << std::endl;
			//oftenUse::print(mA_T_times_F);

			calc_A_T_times_A();
			//// just for debugging -> print A_T * A
			//std::cout << "A_T * A:" << std::endl;
			//oftenUse::print(m_A_T_A);

			//// calc matrix with indidual damping factor
			//if (calcIndivDampFactor)
			//{
			//	calc_individualDampingFactors();
			//}
		}
		calcA_T_A_plusIndDampFac();

		tempInvertedMatrix = Math::calculateInverse(mA_T_times_A_PlusIndivDampFac);

		mTempDeltaNewSysPara = calc_invMatrix_times_A_T_F(tempInvertedMatrix, mA_T_times_F);

		//scaleSystemParameters(tempDeltaNewSysPara, scaleSysPara);
		

		// else // we take the old values but changed the dumping factor

		//temp_scalar_times_A_T_times_A = mDampingNum * m_A_T_A;
		// just for debugging -> print p * A_T * A
		//std::cout << "p * A_T * A:" << std::endl;
		//oftenUse::print(temp_scalar_times_A_T_times_A);

		//tempInvertedMatrix = Math::calculateInverse(temp_scalar_times_A_T_times_A);
		//// just for debugging -> print inverted matrix
		//std::cout << "inverted matrix" << std::endl;
		//oftenUse::print(tempInvertedMatrix);

		
		// just for debugging -> print delta new system parameter
		// std::cout << "delta system parameter" << std::endl;
		// oftenUse::print(mTempDeltaNewSysPara);

		setNewSystemParameter();
		//save_tempDeltaNewSysPara = tempDeltaNewSysPara;

		calculateAberrationFct();

		// just for debugging -> print aberration fct
		// std::cout << "aberration fct:" << std::endl;
		// oftenUse::print(mAberrationFct_F0);

		// save merit values

		saveCurMeritAndBestMeritValue();

		if (mTempMeritVal > mBestMeritVal) // we have to reverse the change
		{
			worstCounter++;
			mIndividualDampingFactor = mIndividualDampingFactor * 2.0;
			calcIndivDampFactor = false;

			mTempDeltaNewSysPara = -1.0 *  mTempDeltaNewSysPara;
			setNewSystemParameter();
		
			//std::cout << "max worst: " << maxWorst << std::endl;
			//std::cout << "worst counter: " << worstCounter << std::endl;
			//bool affe = worstCounter > maxWorst;
			//std::cout << "worst counter > max worst" << affe << std::endl;
		
			systemGettingbetter = false;
		
			
		
			if (worstCounter > maxWorst)
			{
				iterationCounter = maxIterations + 1;
			}
		
			//halfInvertedMatrix(tempInvertedMatrix);
			//scaleSystemParameters(tempDeltaNewSysPara, scaleSysPara);

		}
		
		else // the system was getting better
		{
			systemGettingbetter = true;
			iterationCounter++;
			//iterationCounter = checkImprovementMeritVal(iterationCounter, improveMeritStop);
			calcIndivDampFactor = true;
			//scaleSysPara = scaleSysPara * 2.0;
			mIndividualDampingFactor = mIndividualDampingFactor * 0.5;
			
			// just for debugging -> print interation counter 
			// std::cout << " ----- " << iterationCounter << std::endl;
			// std::cout << "iteration: " << iterationCounter << std::endl;
			// std::cout << " ----- " << iterationCounter << std::endl;
	

		}

		// just for debugging
		printCurVariables();



	}
}

void DLS::calc_individualDampingFactors()
{
	calc_F_T_times_F();
	calcF_T_times_A_times_A_T_times_F();
	mIndividualDampingFactor = 2 * mF_T_times_A_times_A_T_times_F / mF_T_times_F;

	//std::cout << "individual damping factor: " << mIndividualDampingFactor << std::endl;
}

void DLS::calc_F_T_times_F()
{
	real tempVal{};
	mF_T_times_F = 0;

	for (unsigned int i = 0; i < mNumFieldPoints_Angles; ++i)
	{
		tempVal = std::pow(mAberrationFct_F0[i], 2);
		mF_T_times_F = mF_T_times_F + tempVal;
	}
}

void DLS::calcF_T_times_A_times_A_T_times_F()
{
	real tempVal{};
	mF_T_times_A_times_A_T_times_F = 0;

	for (unsigned int i = 0; i < mNumVar; ++i)
	{
		tempVal = std::pow(mA_T_times_F[i], 2);
		mF_T_times_A_times_A_T_times_F = mF_T_times_A_times_A_T_times_F + tempVal;
	}

}

void DLS::calcA_T_A_plusIndDampFac()
{
	for (unsigned int i = 0; i < mNumVar; ++i)
	{
		for (unsigned int j = 0; j < mNumVar; ++j)
		{
			if (i == j)
			{
				mA_T_times_A_PlusIndivDampFac[i][j] = m_A_T_A[i][j] + mIndividualDampingFactor;
			}
			else
			{
				mA_T_times_A_PlusIndivDampFac[i][j] = m_A_T_A[i][j];
			}
		}
	}
}

void DLS::halfInvertedMatrix(std::vector<std::vector<real>> invertedMatrix)
{
	for (unsigned int i = 0; i < mNumVar; ++i)
	{
		for (unsigned int j = 0; j < mNumVar; ++j)
		{
			invertedMatrix[i][j] = invertedMatrix[i][j] / 20;
		}
	}
}

void DLS::scaleSystemParameters(std::vector<real>& tempSysParam, real scale)
{
	for (unsigned int i = 0; i < mNumVar; ++i)
	{
		tempSysParam[i] = tempSysParam[i] * scale;
	}
}

void DLS::checkDeltaParameter(std::vector<real>& deltaSysPara_vec)
{
	for (unsigned int i = 0; i < mNumVar; ++i)
	{
		if (std::abs(deltaSysPara_vec[i]) > mDefaultParamDLS.getMaxDeltaParameter())
		{
			if (deltaSysPara_vec[i] > 0)
			{
				deltaSysPara_vec[i] = mDefaultParamDLS.getMaxDeltaParameter();
			}
			else
			{
				deltaSysPara_vec[i] = -1.0 * mDefaultParamDLS.getMaxDeltaParameter();
			}
		}

		else if (std::abs(deltaSysPara_vec[i]) < mDefaultParamDLS.getMinDeltaParameter())
		{
			mGlobalStop = false; // here we stop the iterration in damping
		}

	
			
	}
}

std::vector<VectorStructR3> DLS::getField_vec()
{
	return mFields_obj_vec;
}
std::vector<real> DLS::getFieldAngles_X()
{
	return mFields_X_inf_vec;
}
std::vector<real> DLS::getFieldAngle_Y()
{
	return mFields_Y_inf_vec;
}
std::vector<real> DLS::getWavelength_vev()
{
	return mWavelenght_vec;
}
unsigned int DLS::getRings()
{
	return mRings;
}
unsigned int DLS::getArms()
{
	return mArms;
}
OpticalSystemElement DLS::getInitialOpticalSystemHLT()
{
	return mOpticalSystemEle_initial;
}

real DLS::getBestMeritValue()
{
	return mBestMeritVal;
}

// load without min and Max default
void DLS::loadWithoutMinMaxDefault()
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

		if (tempTypeModi_Radius == typeModifierVariable)
		{
			tempWithoutMIN = -tempSemiHeight - mDefaultParamDLS.getToleranceWithoutMin();
			if (tempWithoutMIN > 0.0)
			{
				tempWithoutMIN = 0.0;
			}
			mWithoutMinMax[counterVar].setWithoutMin(tempWithoutMIN);

			tempWithoutMAX = tempSemiHeight - mDefaultParamDLS.getToleranceWithoutMax();
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

void DLS::loadBestFactorBetterFactorWorstCombinations()
{
	factorBetter_vec.push_back(mDefaultParamDLS.getFactorGettingBetter());
	factorWorst_vec.push_back(mDefaultParamDLS.getFactorGettingWorst());

	factorBetter_vec.push_back(0.2);
	factorWorst_vec.push_back(1.9);

	factorBetter_vec.push_back(0.4);
	factorWorst_vec.push_back(2.1);

	factorBetter_vec.push_back(0.4);
	factorWorst_vec.push_back(1.9);

	factorBetter_vec.push_back(0.8);
	factorWorst_vec.push_back(2.0);

	factorBetter_vec.push_back(0.8);
	factorWorst_vec.push_back(2.3);
	
	factorBetter_vec.push_back(0.2);
	factorWorst_vec.push_back(2.0);

	factorBetter_vec.push_back(0.6);
	factorWorst_vec.push_back(2.0);

	factorBetter_vec.push_back(0.4);
	factorWorst_vec.push_back(2.3);
	
	factorBetter_vec.push_back(0.5);
	factorWorst_vec.push_back(1.9);

	factorBetter_vec.push_back(0.5);
	factorWorst_vec.push_back(2.1);

	factorBetter_vec.push_back(0.3);
	factorWorst_vec.push_back(2.1);

	factorBetter_vec.push_back(0.4);
	factorWorst_vec.push_back(1.8);

	mSizeFacrotBetterWorstVec = factorWorst_vec.size();
}

objectPoint_inf_obj DLS::getInfOrObj()
{
	return mInf_Obj;
}

void DLS::setTargetCardinalPoints(const targetCardinalPointsStruct& targetCarPoints)
{
	mTargetCardinalPoints = targetCarPoints;
}

targetCardinalPointsStruct DLS::getTargetCardinalPoints()
{
	return mTargetCardinalPoints;
}

void DLS::setWeightFields(std::vector<real> weightField_vec)
{
	mWeightFields_vec = weightField_vec;
}
std::vector<real> DLS::getWeigthFields()
{
	return mWeightFields_vec;
}

void DLS::setWeightWavelength(std::vector<unsigned int> weightWavelength_vec)
{
	mWeightWavelenght_vec = weightWavelength_vec;
}
std::vector<unsigned int> DLS::getWeightWavelength()
{
	return mWeightWavelenght_vec;
}

