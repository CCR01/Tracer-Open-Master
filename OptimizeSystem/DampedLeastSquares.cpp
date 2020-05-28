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


DLS::DLS() {};
DLS::DLS(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms) :
mOpticalSystemEle_initial(optSysEle.getDeepCopyOptSysEle()),
mOpticaSystemEle_change(optSysEle.getDeepCopyOptSysEle()),
mFields_vec(fields),
mWavelenght_vec(wavelengths),
mRings(rings),
mArms(arms)
{
	loadDefaultParameter();
	buildOptSys_LLT_wave_vec();	
	mParameterVar.loadSystemParameter(mOpticalSystemEle_initial);
	resizeAllRelevantStdVectorsAndCalcConst();
	mChangedOptSys_LLT_vec = deepCopyOptSysLLT_vec(mOptSys_LLT_vec);
	loadThicknessParameter();
}
DLS::~DLS() {};

void DLS::resizeAllRelevantStdVectorsAndCalcConst()
{
	
	mAberrationFct_F0.resize(mNumFieldPoints);

	mReturnDeviation_vec.resize(mNumFieldPoints);

	mNumVar = mParameterVar.getAllParaWithVar().size();
	mJacobi_Aij.resize(mNumFieldPoints);
	oftenUse::resizeAllRowsMatrix(mJacobi_Aij, mNumVar);

	mDeviationAberrationFct.resize(mNumFieldPoints);
	
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

	

	// 
	mAllMeritVal.push_back(oftenUse::getInfReal());
	mBestMeritVal = mAllMeritVal[0];


	mThickness_vec.resize(mPosLastSurface);

	mBorderViolCounter_Radius.resize(mSizeOptSys);
	std::fill(mBorderViolCounter_Radius.begin(), mBorderViolCounter_Radius.end(), 0);
	mBorderViolCounter_Thickness.resize(mSizeOptSys);
	std::fill(mBorderViolCounter_Thickness.begin(), mBorderViolCounter_Thickness.end(), 0);
	
	mIndividualDampingFactor = 1000.0;

	mGlobalStop = true;
	mInBoundery = true;
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

	// weight field default
	mNumFieldPoints = mFields_vec.size();
	mWeightFields_vec.resize(mNumFieldPoints); // --
	std::fill(mWeightFields_vec.begin(), mWeightFields_vec.end(), 1);

	// weight wavelength default
	unsigned int numWavelength = mWavelenght_vec.size();
	mWeightWavelenght_vec.resize(numWavelength); // --
	std::fill(mWeightWavelenght_vec.begin(), mWeightWavelenght_vec.end(), 1);

	// build defautl light
	mDefaultLight.setIntensity(1.0);
	mDefaultLight.setJonesVector({ 1.0,1.0,1.0,1.0 });
	mDefaultLight.setTypeLight(typeLightRay);
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

void DLS::changeRadiusSurfaceTo(unsigned int surfaceNo, real newRadius)
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

void DLS::changeThickness_Z_SurfaceTo(unsigned int surfaceNo, real newThickness)
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

void DLS::changePosition_Z_SurfaceTo(unsigned int surfaceNo, real newPositionZ)
{
	mNewPosition.setZ(newPositionZ);
	
	for (unsigned int i = 0; i < mNumOptSys; ++i)
	{
		mChangedOptSys_LLT_vec[i].getPosAndInteractingSurface()[surfaceNo].getSurfaceInterRay_ptr()->setPosition(mNewPosition);
	}

}

real DLS::calculateMeritVal_RMS(const VectorStructR3& fieldPoint)
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
		tempAimedLightRays = rayAiming.rayAimingMany_obj(fillAperStop.getPointsInAS(), fieldPoint, mDefaultLight, mDefaultParamDLS.getStartRefractivIndex());
		
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
	std::cout << "number inter points last surface: " << numberInterPoints << std::endl;

	if (std::abs(numberExpecteInterPoints - numberInterPoints) <= 0.0001)
	{
		Spot spot(interPoints_vec_lastSurface, interPoints_vec_lastSurface[0]);
		returnMerit_RMS = spot.getRMS_µm();
	}
	else // there is vignetting
	{
		returnMerit_RMS = oftenUse::getInfReal();
		//mDampingNum = mDampingNum * 10.0;
	}


	return returnMerit_RMS;
}

void DLS::calculateAberrationFct()
{
		
	VectorStructR3 tempFieldPoint{};
	real tempWeightFieldPoint{};
	real tempMeritField{};

	for (unsigned int i = 0; i < mNumFieldPoints; ++i)
	{
		tempFieldPoint = mFields_vec[i];
		tempWeightFieldPoint = mWeightFields_vec[i];
		tempMeritField = calculateMeritVal_RMS(tempFieldPoint);
		mAberrationFct_F0[i] = tempWeightFieldPoint * tempMeritField;
	}

}

std::vector<real> DLS::calculateDeviation(real oldVal, real newVal, unsigned surfaceNum, kindParaOptSys tempKindPara)
{
	real tempNewMeritValue{};
	real tempDiviation;
	
	

	if (tempKindPara == radiusVar)
	{
		//calcChange_Radius_AccordingToMeritVal();
		//changeRadiusSurfaceTo(surfaceNum, newVal);
		changeRadiusSurfaceTo(surfaceNum, newVal);
		for(unsigned int i=0; i< mNumFieldPoints;++i)
		{ 
			tempNewMeritValue = calculateMeritVal_RMS(mFields_vec[i]);
			
			tempDiviation = (tempNewMeritValue - mAberrationFct_F0[i]) / mDefaultParamDLS.getFactorRadiusDeviation();
				
			mReturnDeviation_vec[i] = tempDiviation;
		}
		changeRadiusSurfaceTo(surfaceNum, oldVal);
		
	}

	else if (tempKindPara == thickness_Var)
	{
		//calcChange_Position_AccordingToMeritVal();
		changeThickness_Z_SurfaceTo(surfaceNum, newVal);
		mThickness_vec[surfaceNum] = newVal;
		for (unsigned int i = 0; i < mNumFieldPoints; ++i)
		{
		tempNewMeritValue = calculateMeritVal_RMS(mFields_vec[i]);
		tempDiviation = (tempNewMeritValue - mAberrationFct_F0[i]) / mDefaultParamDLS.getFactorPositionDeviation();
		mReturnDeviation_vec[i] = tempDiviation;
		}
		
		changeThickness_Z_SurfaceTo(surfaceNum, oldVal);
		mThickness_vec[surfaceNum] = oldVal;
	}


	return mReturnDeviation_vec;
}

void DLS::calcJacobiMatrixDeviation_Aij()
{
	std::vector<unsigned int> surfaceNumWithVar = mParameterVar.getAllSurfaceNumWithVar();
	real tempVal;
	real newVal;
	VectorStructR3 tempFieldPoint;

	real newMeritValue{};

	unsigned int tempSurfaceNum{};
	kindParaOptSys tempKindPara{};


	for (unsigned int i = 0; i < mNumVar; ++i)
	{
		tempSurfaceNum = surfaceNumWithVar[i];
		tempKindPara = mParameterVar.getAllParaWithVar()[i];


		if (tempKindPara == radiusVar)
		{
			tempVal = mChangedOptSys_LLT_vec[0].getPosAndInteractingSurface()[tempSurfaceNum].getSurfaceInterRay_ptr()->getRadius();
			newVal = tempVal + mDefaultParamDLS.getFactorRadiusDeviation();

			mDeviationAberrationFct = calculateDeviation(tempVal, newVal, tempSurfaceNum, tempKindPara);

			// just for debugging
			std::cout << "deviation surface: " << tempSurfaceNum << " " << mDeviationAberrationFct[0] + mDeviationAberrationFct[1] + mDeviationAberrationFct[2] << std::endl;
			
		}

		else if (tempKindPara == thickness_Var)
		{
			tempVal = mThickness_vec[tempSurfaceNum];
			newVal = tempVal + mDefaultParamDLS.getFactorPositionDeviation();

			mDeviationAberrationFct = calculateDeviation(tempVal, newVal, tempSurfaceNum, tempKindPara);
		}

			
		fillJacobiMatrix(mDeviationAberrationFct, i);
	
	}

	// just for debugging
	//oftenUse::print(mJacobi_Aij);
	
}

void DLS::fillJacobiMatrix(std::vector<real> vector, unsigned int row)
{	

	for (unsigned int i = 0; i < mColumns_A_T_A; i++)
	{
		mJacobi_Aij[i][row] = vector[i];
	}
}

real DLS::checkBounderiesAndReturnNewVal(real val, unsigned int posDeltaValt, real minVal, real maxVal, unsigned int tempSurfaceNum, kindParaOptSys kindPara)
{
	bool tempBorderViolations;
	real tempDeltaVal = mTempDeltaNewSysPara[posDeltaValt];
	real newVal = val + tempDeltaVal;

	real checkValNeg = newVal - 0.001;
	real checkVapPos = newVal + 0.0001;
	bool checkerNeg = checkValNeg < minVal;
	std::cout << checkerNeg << std::endl;
	bool checkerPos = checkVapPos > maxVal;
	std::cout << checkerPos << std::endl;
	if (checkerNeg)
	{ 
		mInBoundery = false;
		std::cout << "boundery check is false" << std::endl;	

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
		std::cout << "boundery check is false" << std::endl;  

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
			

			newVal = checkBounderiesAndReturnNewVal(tempVal, i, tempMinVal, tempMaxVal, tempSurfaceNum, tempKindParameter);

			// just for debugging
			std::cout << "set radius of surface " << tempSurfaceNum << " to " << newVal << std::endl;
			std::cout << std::endl;

			changeRadiusSurfaceTo(tempSurfaceNum, newVal);


		}

		else if (tempKindParameter == thickness_Var)
		{
			tempMinVal = mParameterVar.getAllMinVar()[i];
			tempMaxVal = mParameterVar.getAllMaxVar()[i];


			tempVal = mThickness_vec[tempSurfaceNum];
			
			newVal = checkBounderiesAndReturnNewVal(tempVal, i, tempMinVal, tempMaxVal, tempSurfaceNum, tempKindParameter);

			

			// just for debugging
			std::cout << "set thickness of surface " << tempSurfaceNum << " to " << newVal << std::endl;
			std::cout << std::endl;

			changeThickness_Z_SurfaceTo(tempSurfaceNum, newVal);
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
	std::cout << "temp merit value: " << mTempMeritVal << std::endl;

	mAllMeritVal.push_back(mTempMeritVal);

	if (mTempMeritVal < mBestMeritVal)
	{
		mBestMeritVal = mTempMeritVal;
	}
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
	bool systemGettingbetter = true;
	real improveMeritStop = mDefaultParamDLS.getImprovMeritStopDiff();


	calculateAberrationFct();
	// just for debugging -> print aberration fct
	std::cout << "aberration fct:" << std::endl;
	oftenUse::print(mAberrationFct_F0);

	saveCurMeritAndBestMeritValue();

	while (maxIterations >= mIterationCounter && mGlobalStop)
	{
			
		if (systemGettingbetter)
		{
			calcJacobiMatrixDeviation_Aij();
			// just for debugging -> print jacobi matrix
			std::cout << "jacobi matrix:" << std::endl;
			oftenUse::print(mJacobi_Aij);

			calcJacobi_times_Aberration();
			// just for debugging -> print A_T * F0
			std::cout << "A_T * F0:" << std::endl;
			oftenUse::print(mA_T_times_F);

			calc_A_T_times_A();
			// just for debugging -> print A_T * A
			std::cout << "A_T * A:" << std::endl;
			oftenUse::print(m_A_T_A);

		}

		// else // we take the old values but changed the dumping factor
		
		temp_scalar_times_A_T_times_A = mDampingNum * m_A_T_A;
		// just for debugging -> print p * A_T * A
		std::cout << "p * A_T * A:" << std::endl;
		oftenUse::print(temp_scalar_times_A_T_times_A);

		tempInvertedMatrix = Math::calculateInverse(temp_scalar_times_A_T_times_A);
		// just for debugging -> print inverted matrix
		std::cout << "inverted matrix" << std::endl;
		oftenUse::print(tempInvertedMatrix);

		mTempDeltaNewSysPara = calc_invMatrix_times_A_T_F(tempInvertedMatrix, mA_T_times_F);
		// just for debugging -> print delta new system parameter
		std::cout << "delta system parameter" << std::endl;
		oftenUse::print(mTempDeltaNewSysPara);
		

		checkDeltaParameter(mTempDeltaNewSysPara);
		setNewSystemParameter();
		//save_tempDeltaNewSysPara = tempDeltaNewSysPara;

		calculateAberrationFct();
				
		// just for debugging -> print aberration fct
		std::cout << "aberration fct:" << std::endl;
		oftenUse::print(mAberrationFct_F0);

		// save merit values


		saveCurMeritAndBestMeritValue();

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

			systemGettingbetter = false;
			
			// just for debugging
			std::cout << "worst counter: " << mWorstCounter << std::endl;

			if (mWorstCounter > maxWorst)
			{
				mIterationCounter = maxIterations + 1;
			}

		}

		else // the system was getting better
		{
			systemGettingbetter = true;
			mDampingNum = mDefaultParamDLS.getFactorGettingBetter() * mDampingNum;
			mIterationCounter++;
			mIterationCounter = checkImprovementMeritVal(mIterationCounter, improveMeritStop);

			// just for debugging
			std::cout << "interation counter: " << mIterationCounter << std::endl;
		}
		
		// just for debugging
		printCurVariables();


		
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
			std::cout << "radius of surface " << tempSurfaceNum << " is " << tempVal << std::endl;
			std::cout << std::endl;

		}

		else if (tempKindParameter == thickness_Var)
		{
			tempVal = mChangedOptSys_LLT_vec[0].getPosAndInteractingSurface()[tempSurfaceNum].getSurfaceInterRay_ptr()->getPoint().getZ();
			std::cout << "position Z of surface " << tempSurfaceNum << " is " << tempVal << std::endl;
			std::cout << std::endl;
		}

	}


}


OpticalSystemElement DLS::getOptimizedSystem_HLT()
{
	return mOpticalSystemEle_initial.convertOptSys_LLT_T0_OptSys_HLT(mOpticalSystemEle_initial, mChangedOptSys_LLT_vec[0]);
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
	std::cout << "aberration fct:" << std::endl;
	oftenUse::print(mAberrationFct_F0);
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
		std::cout << "delta system parameter" << std::endl;
		oftenUse::print(mTempDeltaNewSysPara);

		setNewSystemParameter();
		//save_tempDeltaNewSysPara = tempDeltaNewSysPara;

		calculateAberrationFct();

		// just for debugging -> print aberration fct
		std::cout << "aberration fct:" << std::endl;
		oftenUse::print(mAberrationFct_F0);

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
			iterationCounter = checkImprovementMeritVal(iterationCounter, improveMeritStop);
			calcIndivDampFactor = true;
			//scaleSysPara = scaleSysPara * 2.0;
			mIndividualDampingFactor = mIndividualDampingFactor * 0.5;
			
			// just for debugging -> print interation counter 
			std::cout << " ----- " << iterationCounter << std::endl;
			std::cout << "iteration: " << iterationCounter << std::endl;
			std::cout << " ----- " << iterationCounter << std::endl;
	

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

	std::cout << "individual damping factor: " << mIndividualDampingFactor << std::endl;
}

void DLS::calc_F_T_times_F()
{
	real tempVal{};
	mF_T_times_F = 0;

	for (unsigned int i = 0; i < mNumFieldPoints; ++i)
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
	return mFields_vec;
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

