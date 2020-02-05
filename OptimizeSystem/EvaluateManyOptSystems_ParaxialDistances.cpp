#include "EvaluateManyOptSystems_ParaxialDistances.h"
#include "..\Analyse\CardinalPoints.h"
#include <functional>



real settingsMeritFct_ParaxialDistances::getTargetS_dash() const
{
	return mTargetS_dash;
}
void settingsMeritFct_ParaxialDistances::setTargetS_dash(const real targetS_dash)
{
	mTargetS_dash = targetS_dash;
}
real settingsMeritFct_ParaxialDistances::getWeightTargetS_dash() const
{
	return mWeightTargetS_dash;
}
void settingsMeritFct_ParaxialDistances::setWeightTargetS_dash(const real weightTargetS_dash)
{
	mWeightTargetS_dash = weightTargetS_dash;
}

real settingsMeritFct_ParaxialDistances::getEFL() const
{
	return mEFL;
}
void settingsMeritFct_ParaxialDistances::setEFL(const real efl)
{
	mEFL = efl;
}
real settingsMeritFct_ParaxialDistances::getWeightEFL() const
{
	return mWeightEFL;
}
void settingsMeritFct_ParaxialDistances::setWeightEFL(const real weightEFL)
{
	mWeightEFL = weightEFL;
}
real settingsMeritFct_ParaxialDistances::getPP() const
{
	return mPP;
}
void settingsMeritFct_ParaxialDistances::setPP(const real pp)
{
	mPP = pp;
}
real settingsMeritFct_ParaxialDistances::getWeightPP() const
{
	return mWeightPP;
}
void settingsMeritFct_ParaxialDistances::setWeightPP(const real weightPP)
{
	mWeightPP = weightPP;
}
real settingsMeritFct_ParaxialDistances::getAntiPP() const
{
	return mAntiPP;
}
void settingsMeritFct_ParaxialDistances::setAntiPP(const real antiPP)
{
	mAntiPP = antiPP;
}
real settingsMeritFct_ParaxialDistances::getWeightAntiPP() const
{
	return mWeightAntiPP;
}
void settingsMeritFct_ParaxialDistances::setWeightAntiPP(const real weightAntiPP)
{
	mWeightAntiPP = weightAntiPP;
}
real settingsMeritFct_ParaxialDistances::getEXPP_accordingToLastSurface() const
{
	return  mEXPP_accordingToLastSurface;
}
void settingsMeritFct_ParaxialDistances::setEXPP_accordingToLastSurface(const real expp_lastSurface)
{
	mEXPP_accordingToLastSurface = expp_lastSurface;
}
real settingsMeritFct_ParaxialDistances::getWeightEXPP_accordingToLastSurface() const
{
	return mWeightEXPP_accordingToLastSurface;
}
void settingsMeritFct_ParaxialDistances::setWeightEXPP_accordingToLastSurface(const real weightEXPP_accordingToLastSurface)
{
	mWeightEXPP_accordingToLastSurface = weightEXPP_accordingToLastSurface;
}
real settingsMeritFct_ParaxialDistances::getEXPP_global() const
{
	return mEXPP_inGlobalCoordinatSystem;
}
void settingsMeritFct_ParaxialDistances::setEXPP_global(const real exppGlobal)
{
	mEXPP_inGlobalCoordinatSystem = exppGlobal;
}
real settingsMeritFct_ParaxialDistances::getWeightEXPP_global() const
{
	return mWeightEXPP_inGlobalCoordinatSystem;
}
void settingsMeritFct_ParaxialDistances::setWeightEXPP_global(const real weightEXPP_global)
{
	mWeightEXPP_inGlobalCoordinatSystem = weightEXPP_global;
}

real settingsMeritFct_ParaxialDistances::getEXPD() const
{
	return mEXPD;
}
void settingsMeritFct_ParaxialDistances::setEXPD(const real expd)
{
	mEXPD = expd;
}
real settingsMeritFct_ParaxialDistances::getWeightEXPD() const
{
	return mWeightEXPD;
}
void settingsMeritFct_ParaxialDistances::setWeightEXPD(const real weightEXPD)
{
	mWeightEXPD = weightEXPD;
}
real settingsMeritFct_ParaxialDistances::getMag() const
{
	return mMag;
}
void settingsMeritFct_ParaxialDistances::setMag(const real mag)
{
	mMag = mag;
}
real settingsMeritFct_ParaxialDistances::getWeightMag() const
{
	return mWeightMag;
}
void settingsMeritFct_ParaxialDistances::setWeightMag(const real weightMag)
{
	mWeightMag = weightMag;
}


EvaluateManyOptSystems_ParaxialDistances::EvaluateManyOptSystems_ParaxialDistances() {}

EvaluateManyOptSystems_ParaxialDistances::~EvaluateManyOptSystems_ParaxialDistances() {}

EvaluateManyOptSystems_ParaxialDistances::EvaluateManyOptSystems_ParaxialDistances(OpticalSystemElement optSysEle, std::vector<stepsWithoutMinWithoutMax> addInfosVariable, StartRayPos startRay, real primWavelength) :
	mOptSysEle(optSysEle),
	mAddInfosVariable(addInfosVariable),
	mStartRay(startRay),
	mPrimWavelength(primWavelength)
{
	mOptSysEle.setRefractiveIndexAccordingToWavelength(mPrimWavelength);
	//mOptSysEle.convertHLTtoLLT();
	loadDefaultSettingsMeritFct();
	calculateTargetS_dash(optSysEle.getLLTconversion_doConversion());
	mSystemForCombinations.superFct(mOptSysEle, mAddInfosVariable, mPrimWavelength, buildLLT);
	calcAllMeritValuesParaxialDistances();
}


void EvaluateManyOptSystems_ParaxialDistances::loadDefaultSettingsMeritFct()
{
	mSettingMeritFunction.setTargetS_dash(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeightTargetS_dash(1.0);
	mSettingMeritFunction.setEFL(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeightEFL(0.0);
	mSettingMeritFunction.setPP(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeightPP(0.0);
	mSettingMeritFunction.setAntiPP(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeightAntiPP(0.0);
	mSettingMeritFunction.setEXPP_accordingToLastSurface(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeightEXPP_accordingToLastSurface(0.0);
	mSettingMeritFunction.setEXPP_global(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeightEXPP_global(0.0);
	mSettingMeritFunction.setMag(std::numeric_limits<double>::quiet_NaN());
	mSettingMeritFunction.setWeightEXPP_global(0.0);

}

void EvaluateManyOptSystems_ParaxialDistances::calculateTargetS_dash(OpticalSystem_LLT optSys_LLT)
{
	unsigned int sizeOptSys = optSys_LLT.getPosAndInteractingSurface().size() - 1;
	typeModifier typeLasteSurface = mOptSysEle.getPosAndElement().at(sizeOptSys).getElementInOptSys_ptr()->getParameterPositionZ().getModifier();

	if (typeLasteSurface == typeModifierFixed)
	{
		real posZlast = optSys_LLT.getPosAndInteractingSurface().at(sizeOptSys).getSurfaceInterRay_ptr()->getPoint().getZ();
		real posZbeforeLast = optSys_LLT.getPosAndInteractingSurface().at(sizeOptSys - 1).getSurfaceInterRay_ptr()->getPoint().getZ();
		real targetS_dash = posZlast - posZbeforeLast;

		mSettingMeritFunction.setTargetS_dash(targetS_dash);
	}

}

real EvaluateManyOptSystems_ParaxialDistances::calcContributionMerit(real const& weight, real const& targetValue, real const& currentValue, real const& comparsion)
{
	return weight * std::abs((targetValue - currentValue) / targetValue) / comparsion;

}

real EvaluateManyOptSystems_ParaxialDistances::calcMeritValue(OpticalSystem_LLT optSys_LLT, real currentS_dash, real targetS_dahs)
{
	real conTargetS_dash = 0.0;
	real conEFL = 0.0;
	real conPP = 0.0;
	real conAntiPP = 0.0;
	real conEXPP_lastSurface = 0.0;
	real conEXPP_global = 0.0;
	real conEXPD = 0.0;
	real conMag = 0.0;



	CardinalPoints currentCardinalPoints(optSys_LLT);

	real comparisonValue = 1.0;

	// target s dash
	if (std::isnan(mSettingMeritFunction.getTargetS_dash()))
	{
		mSettingMeritFunction.setWeightTargetS_dash(0.0);
	}
	else
	{
		conTargetS_dash = calcContributionMerit(mSettingMeritFunction.getWeightTargetS_dash(), targetS_dahs, currentS_dash, comparisonValue);
	}

	// EFL
	if (std::isnan(mSettingMeritFunction.getEFL()))
	{
		mSettingMeritFunction.setWeightEFL(0.0);
	}
	else
	{
		conEFL = calcContributionMerit(mSettingMeritFunction.getWeightEFL(), mSettingMeritFunction.getEFL(), currentCardinalPoints.getEFL(), comparisonValue);
	}

	// PP
	if (std::isnan(mSettingMeritFunction.getPP()))
	{
		mSettingMeritFunction.setWeightPP(0.0);
	}
	else
	{
		conPP = calcContributionMerit(mSettingMeritFunction.getWeightPP(), mSettingMeritFunction.getPP(), currentCardinalPoints.getPrincipaPlan(), comparisonValue);
	}

	// AntiPP
	if (std::isnan(mSettingMeritFunction.getAntiPP()))
	{
		mSettingMeritFunction.setWeightAntiPP(0.0);
	}
	else
	{
		conAntiPP = calcContributionMerit(mSettingMeritFunction.getWeightAntiPP(), mSettingMeritFunction.getAntiPP(), currentCardinalPoints.getAntiPP(), comparisonValue);
	}

	// EXPP_accordingToLastSurface
	if (std::isnan(mSettingMeritFunction.getEXPP_accordingToLastSurface()))
	{
		mSettingMeritFunction.setWeightEXPP_accordingToLastSurface(0.0);
	}
	else
	{
		conEXPP_lastSurface = calcContributionMerit(mSettingMeritFunction.getWeightEXPP_accordingToLastSurface(), mSettingMeritFunction.getEXPP_accordingToLastSurface(), currentCardinalPoints.getExitPupilPosition_lastSurface(), comparisonValue);
	}

	// EXPP_global
	if (std::isnan(mSettingMeritFunction.getEXPP_global()))
	{
		mSettingMeritFunction.setWeightEXPP_global(0.0);
	}
	else
	{
		conEXPP_global = calcContributionMerit(mSettingMeritFunction.getWeightEXPP_global(), mSettingMeritFunction.getEXPP_global(), currentCardinalPoints.getExitPupilPosition_globalCoori(), comparisonValue);
	}

	// EXPD
	if (std::isnan(mSettingMeritFunction.getEXPD()))
	{
		mSettingMeritFunction.setWeightEXPD(0.0);
	}
	else
	{
		conEXPD = calcContributionMerit(mSettingMeritFunction.getWeightEXPD(), mSettingMeritFunction.getEXPD(), currentCardinalPoints.getExitPupilDiameter(), comparisonValue);
	}

	// Mag
	if (std::isnan(mSettingMeritFunction.getMag()))
	{
		mSettingMeritFunction.setWeightMag(0.0);
	}
	else
	{
		conMag = calcContributionMerit(mSettingMeritFunction.getWeightMag(), mSettingMeritFunction.getMag(), currentCardinalPoints.getMagnification(), comparisonValue);
	}



	real sumMerit = conTargetS_dash + conEFL + conPP + conAntiPP + conEXPP_lastSurface + conEXPP_global + conMag;

	return sumMerit;
}


void EvaluateManyOptSystems_ParaxialDistances::calcAllMeritValuesParaxialDistances()
{
	std::vector<OpticalSystem_LLT> allPosOptSys = mSystemForCombinations.getAllPosOptSys_LLT();
	real tempLastS_dash;
	real tempMeritValue;

	unsigned int sizeOptSys = mOptSysEle.getPosAndElement().size() - 1;
	typeModifier typeLasteSurface = mOptSysEle.getPosAndElement().at(sizeOptSys).getElementInOptSys_ptr()->getParameterPositionZ().getModifier();

	mAllMeritValues_vec.resize(allPosOptSys.size());

	for (unsigned int i = 0; i < allPosOptSys.size(); i++)
	{
		switch (typeLasteSurface)
		{
		case typeModifierFixed:
		{
			CalculateParaxialDistances tempParaDis(allPosOptSys.at(i), mStartRay, mPrimWavelength);
			mAllPraxialDistances.push_back(tempParaDis);
			tempLastS_dash = tempParaDis.getS_dash_atSurface_i(sizeOptSys - 1);
			tempMeritValue = calcMeritValue(allPosOptSys.at(i), tempLastS_dash, mSettingMeritFunction.getTargetS_dash());
			mAllMeritValues_vec[i] = tempMeritValue;
			break;
		}

		case typeModifierVariable:
		{
			CalculateParaxialDistances tempParaDis(allPosOptSys.at(i), mStartRay, mPrimWavelength);
			mAllPraxialDistances.push_back(tempParaDis);
			tempLastS_dash = tempParaDis.getS_dash_atSurface_i(sizeOptSys - 1);
			calculateTargetS_dash(allPosOptSys.at(i));
			tempMeritValue = calcMeritValue(allPosOptSys.at(i), tempLastS_dash, mSettingMeritFunction.getTargetS_dash());
			mAllMeritValues_vec[i] = tempMeritValue;
			break;
		}

		default:
			break;
		}

	}

}
std::vector<OpticalSystem_LLT> EvaluateManyOptSystems_ParaxialDistances::getBestOpticalSys_LLTinVec_meritLessThan(real const lessThan)
{
	std::vector<real> smallestMeritValues_vec{};
	std::copy_if(mAllMeritValues_vec.cbegin(), mAllMeritValues_vec.cend(), std::back_inserter(smallestMeritValues_vec), [lessThan](real n) { return  n < lessThan; });

	std::vector<OpticalSystem_LLT> bestOptSys_LLT;
	real tempSearchingNum;
	bestOptSys_LLT.resize(smallestMeritValues_vec.size());

	for (unsigned int i = 0; i < smallestMeritValues_vec.size(); ++i)
	{
		tempSearchingNum = smallestMeritValues_vec[i];
		std::vector<real>::iterator it = std::find(mAllMeritValues_vec.begin(), mAllMeritValues_vec.end(), tempSearchingNum);
		int index = std::distance(mAllMeritValues_vec.begin(), it);

		bestOptSys_LLT[i] = mSystemForCombinations.getAllPosOptSys_LLT()[index];

	}

	return bestOptSys_LLT;

}

OpticalSystem_LLT EvaluateManyOptSystems_ParaxialDistances::getBestOptSys()
{
	OpticalSystem_LLT bestOptSys;
	std::vector<real>::iterator numMinEle = std::min_element(mAllMeritValues_vec.begin(), mAllMeritValues_vec.end());
	int index = std::distance(mAllMeritValues_vec.begin(), numMinEle);
	bestOptSys = mSystemForCombinations.getAllPosOptSys_LLT()[index];

	return bestOptSys;

}

//get n best optical systems
std::vector<OpticalSystem_LLT> EvaluateManyOptSystems_ParaxialDistances::get_N_BestOptSys_LLT(unsigned int numberBestOptSys)
{

	OpticalSystem_LLT bestOptSys_save;
	real veryHeighNumber = 9999999999999999999999999999.0;

	std::vector<OpticalSystem_LLT> return_N_BestOptSys_LLT_vec;

	unsigned int numMeritValues = mAllMeritValues_vec.size();
	if (numMeritValues <= numberBestOptSys)
	{
		return mSystemForCombinations.getAllPosOptSys_LLT();
	}

	return_N_BestOptSys_LLT_vec.resize(numberBestOptSys);

	for (unsigned int i = 0; i < numberBestOptSys; ++i)
	{
		// position best opt Sys
		std::vector<real>::iterator numMinEle = std::min_element(mAllMeritValues_vec.begin(), mAllMeritValues_vec.end());
		int index = std::distance(mAllMeritValues_vec.begin(), numMinEle);

		bestOptSys_save = mSystemForCombinations.getAllPosOptSys_LLT()[index];
		return_N_BestOptSys_LLT_vec[i] = bestOptSys_save;

		mAllMeritValues_vec[index] = veryHeighNumber;

	}

	return return_N_BestOptSys_LLT_vec;
}


// convert N optical system LLTs to element systems
std::vector<OpticalSystemElement> EvaluateManyOptSystems_ParaxialDistances::convert_N_optSysLLT_To_elementSystems(std::vector<OpticalSystem_LLT> optSys_LLT_vec, OpticalSystemElement optSysEle)
{
	unsigned int size = optSys_LLT_vec.size();
	std::vector<OpticalSystemElement> retunr_N_OptSysEle;
	retunr_N_OptSysEle.resize(size);

	OpticalSystemElement tempOptSysEle;

	for (unsigned int i = 0; i < size; ++i)
	{
		tempOptSysEle = optSysEle.convertOptSys_LLT_T0_OptSys_HLT(optSysEle, optSys_LLT_vec[i]);
		retunr_N_OptSysEle[i] = tempOptSysEle;

	}

	return retunr_N_OptSysEle;
}

// get systems for combination
BuildSystemsForCombination EvaluateManyOptSystems_ParaxialDistances::getSystemsForCombination()
{
	return mSystemForCombinations;
}

// do more iterations
void EvaluateManyOptSystems_ParaxialDistances::doOneMoreIteration_3var(OpticalSystemElement startOptSysEle, OpticalSystem_LLT bestOptSys, parameterTypeModeStruct V0, parameterTypeModeStruct V1, parameterTypeModeStruct V2)
{

	OpticalSystem_LLT bestOptSys_LLT = bestOptSys.clone();
	OpticalSystemElement bestOptSysEle = startOptSysEle.convertOptSys_LLT_T0_OptSys_HLT(startOptSysEle, bestOptSys_LLT);


	unsigned int posV0 = V0.getSurfaceNum();
	unsigned int posV1 = V1.getSurfaceNum();
	unsigned int posV2 = V2.getSurfaceNum();

	real tempStepSizeV0 = mAddInfosVariable[0].getSteps();
	real tempStepSizeV1 = mAddInfosVariable[1].getSteps();
	real tempStepSizeV2 = mAddInfosVariable[2].getSteps();

	real tempV0;
	real tempV0_min;
	real tempV0_max;
	real tempV1;
	real tempV1_min;
	real tempV1_max;
	real tempV2;
	real tempV2_min;
	real tempV2_max;



	if (V0.getKindParam() == radius)
	{
		tempV0 = bestOptSys_LLT.getPosAndInteractingSurface()[posV0].getSurfaceInterRay_ptr()->getRadius();
		tempV0_min = tempV0 - tempStepSizeV0;
		tempV0_max = tempV0 + tempStepSizeV0;

		bestOptSysEle.getPosAndElement()[posV0].getElementInOptSys_ptr()->setParameterRadius(tempV0_min, tempV0_max, 0.0, typeModifierVariable);

	}

	else if (V0.getKindParam() == position)
	{
		tempV0 = bestOptSys_LLT.getPosAndInteractingSurface()[posV0].getSurfaceInterRay_ptr()->getPoint().getZ();
		tempV0_min = tempV0 - tempStepSizeV0;
		if (tempV0_min < 0)
		{
			tempV0_min = mAddInfosVariable[0].getWithoutMax();
		}

		tempV0_max = tempV0 + tempStepSizeV0;

		bestOptSysEle.getPosAndElement()[posV0].getElementInOptSys_ptr()->setParameterPointZ(tempV0_min, tempV0_max, 0.0, typeModifierVariable);

	}


	if (V1.getKindParam() == radius)
	{
		tempV1 = bestOptSys_LLT.getPosAndInteractingSurface()[posV1].getSurfaceInterRay_ptr()->getRadius();
		tempV1_min = tempV1 - tempStepSizeV1;
		tempV1_max = tempV1 + tempStepSizeV1;

		bestOptSysEle.getPosAndElement()[posV1].getElementInOptSys_ptr()->setParameterRadius(tempV1_min, tempV1_max, 0.0, typeModifierVariable);

	}
	else if (V1.getKindParam() == position)
	{
		tempV1 = bestOptSys_LLT.getPosAndInteractingSurface()[posV1].getSurfaceInterRay_ptr()->getPoint().getZ();
		tempV1_min = tempV1 - tempStepSizeV1;
		if (tempV1_min < 0)
		{
			tempV1_min = mAddInfosVariable[1].getWithoutMax();
		}

		tempV1_max = tempV1 + tempStepSizeV1;

		bestOptSysEle.getPosAndElement()[posV1].getElementInOptSys_ptr()->setParameterPointZ(tempV1_min, tempV1_max, 0.0, typeModifierVariable);
	}



	if (V2.getKindParam() == radius)
	{
		tempV2 = bestOptSys_LLT.getPosAndInteractingSurface()[posV2].getSurfaceInterRay_ptr()->getRadius();
		tempV2_min = tempV2 - tempStepSizeV2;
		tempV2_max = tempV2 + tempStepSizeV2;

		bestOptSysEle.getPosAndElement()[posV2].getElementInOptSys_ptr()->setParameterRadius(tempV2_min, tempV2_max, 0.0, typeModifierVariable);

	}
	else if (V2.getKindParam() == position)
	{
		tempV2 = bestOptSys_LLT.getPosAndInteractingSurface()[posV2].getSurfaceInterRay_ptr()->getPoint().getZ();
		tempV2_min = tempV2 - tempStepSizeV2;
		if (tempV2_min < 0)
		{
			tempV2_min = mAddInfosVariable[1].getWithoutMax();
		}

		tempV2_max = tempV2 + tempStepSizeV2;

		bestOptSysEle.getPosAndElement()[posV2].getElementInOptSys_ptr()->setParameterPointZ(tempV2_min, tempV2_max, 0.0, typeModifierVariable);
	}

	mAddInfosVariable[0].setSteps(tempStepSizeV0 / 10);
	mAddInfosVariable[1].setSteps(tempStepSizeV1 / 10);
	mAddInfosVariable[2].setSteps(tempStepSizeV2 / 10);

	mSystemForCombinations.clearAll();

	mSystemForCombinations.superFct(bestOptSysEle, mAddInfosVariable, mPrimWavelength, buildLLT);
	mAllMeritValues_vec.clear();
	mAllMeritValues_vec.resize(0);
	calcAllMeritValuesParaxialDistances();

}