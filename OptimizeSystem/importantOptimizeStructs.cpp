#include "importantOptimizeStructs.h"
#include "..\Analyse\CardinalPoints.h"


parameterVar::parameterVar() {};
parameterVar::~parameterVar() {};

// surface number
std::vector<unsigned int> parameterVar::getAllSurfaceNumWithVar()
{
	return mSurfaceNumWithVar_vec;
}
void parameterVar::setAllSurfaceNumWithVar(std::vector<unsigned int> allSurfaceNumWithVar)
{
	mSurfaceNumWithVar_vec = allSurfaceNumWithVar;
}
// kind parameter
std::vector<kindParaOptSys> parameterVar::getAllParaWithVar()
{
	return mKindPara_WithVar_vec;
}
void parameterVar::setAllParaWithVar(std::vector<kindParaOptSys> allParaWithVar)
{
	mKindPara_WithVar_vec = allParaWithVar;
}
// kind parameter number
kindParaOptSys parameterVar::getKindParameter_i(unsigned int number)
{
	return mKindPara_WithVar_vec[number];
}
void parameterVar::setKindParameter_i(unsigned int number, kindParaOptSys kindPara)
{
	mKindPara_WithVar_vec[number] = kindPara;
}
// minVar
std::vector<real> parameterVar::getAllMinVar()
{
	return mMinValVar_vec;
}
void parameterVar::setAllMinVar(std::vector<real> allMinVar)
{
	mMinValVar_vec = allMinVar;
}
// maxVar
std::vector<real> parameterVar::getAllMaxVar()
{
	return mMaxValVar_vec;
}
void parameterVar::setAllMaxVar(std::vector<real> allMaxVar)
{
	mMaxValVar_vec = allMaxVar;
}


// clear all vector
void parameterVar::clear()
{
	mSurfaceNumWithVar_vec.clear();
	mKindPara_WithVar_vec.clear();
	mMinValVar_vec.clear();
	mMaxValVar_vec.clear();
}

// load system parameter
void parameterVar::loadSystemParameter(OpticalSystemElement optSysEle)
{
	unsigned sizeOptSysEle = optSysEle.getPosAndElement().size();
	std::shared_ptr<Element_CR> tempElement_ptr{};

	//unsigned int tempSurfaceNum;
	kindParaOptSys temKindPara{};

	real tempMin{};
	real tempMax{};

	typeModifier tempTypeMode_Radius{};
	typeModifier tempTypeMode_Position{};

	// check for variable
	for (unsigned int i = 0; i < sizeOptSysEle; ++i)
	{
		tempElement_ptr = optSysEle.getPosAndElement()[i].getElementInOptSys_ptr();
		tempTypeMode_Radius = tempElement_ptr->getParameterRadius().getModifier();
		tempTypeMode_Position = tempElement_ptr->getParameterPositionZ().getModifier();

		// radius
		if (tempTypeMode_Radius == typeModifierVariable)
		{
			mSurfaceNumWithVar_vec.push_back(i);
			mKindPara_WithVar_vec.push_back(radiusVar);

			tempMin = tempElement_ptr->getParameterRadius().getMinimum();
			tempMax = tempElement_ptr->getParameterRadius().getMaximum();

			mMinValVar_vec.push_back(tempMin);
			mMaxValVar_vec.push_back(tempMax);

		}

		// position
		if (tempTypeMode_Position == typeModifierVariable)
		{
			mSurfaceNumWithVar_vec.push_back(i);
			mKindPara_WithVar_vec.push_back(thickness_Var);

			tempMin = tempElement_ptr->getParameterPositionZ().getMinimum();
			tempMax = tempElement_ptr->getParameterPositionZ().getMaximum();

			mMinValVar_vec.push_back(tempMin);
			mMaxValVar_vec.push_back(tempMax);
		}


	}


}

withOutMinMax::withOutMinMax() {};
withOutMinMax::~withOutMinMax() {};


// without min
real withOutMinMax::getWithoutMin()
{
	return mWithoutMin;
}

void withOutMinMax::setWithoutMin(real withoutMin)
{
	mWithoutMin = withoutMin;
};

// without max
real withOutMinMax::getWithoutMax()
{
	return mWithoutMax;
}
void withOutMinMax::setWithoutMax(real withoutMax)
{
	mWithoutMax = withoutMax;
}

targetCardinalPointsStruct::targetCardinalPointsStruct()
{
	setCardinalPoints_NO_target();
	setAllWeightsToOne();
}
targetCardinalPointsStruct::~targetCardinalPointsStruct() {}

// *** set and get target cardinal points *** //
// target EFL
void targetCardinalPointsStruct::setTargetEFL(real targetEFL)
{
	mTargetEFL = targetEFL;
	mIsEFL_target = true;
	mTargetOpti_vec.push_back(targetOptimization::targetEFL);
	mIsOneTargetCardinalPoint = true;
}
real targetCardinalPointsStruct::getTargetEFL()
{
	return mTargetEFL;
}
bool targetCardinalPointsStruct::isEFL_target()
{
	return mIsEFL_target;
}
// target PP_obj
void targetCardinalPointsStruct::setTargetPP_obj(real targetPP_obj)
{
	mTargetPP_obj = targetPP_obj;
	mIsPP_obj_target = true;
	mTargetOpti_vec.push_back(targetOptimization::targetPP_obj);
	mIsOneTargetCardinalPoint = true;
}
real targetCardinalPointsStruct::getTargetPP_obj()
{
	return mTargetPP_obj;
}
bool targetCardinalPointsStruct::isPP_obj_target()
{
	return mIsPP_obj_target;
}
// target PP_ima
void targetCardinalPointsStruct::setTargetPP_ima(real targetPP_ima)
{
	mTargetPP_ima = targetPP_ima;
	mIsPP_ima_target = true;
	mTargetOpti_vec.push_back(targetOptimization::targetPP_ima);
	mIsOneTargetCardinalPoint = true;
}
real targetCardinalPointsStruct::getTargetPP_ima()
{
	return mTargetPP_ima;
}
bool targetCardinalPointsStruct::isPP_ima_target()
{
	return mIsPP_ima_target;
}
// target EXPP_lastSurface
void targetCardinalPointsStruct::setTargetEXPP_lastSurface(real targetEXPP_lastSurface)
{
	mTargetEXPP_lastSurface = targetEXPP_lastSurface;
	mIsEXPP_lastSurface_target = true;
	mTargetOpti_vec.push_back(targetOptimization::targetEXPP_lastSur);
	mIsOneTargetCardinalPoint = true;
}
real targetCardinalPointsStruct::getTargetEXPP_lastSurface()
{
	return mTargetEXPP_lastSurface;
}
bool targetCardinalPointsStruct::isEXPP_lastSurface_target()
{
	return mIsEXPP_lastSurface_target;
}
// target EXPP in global coodi
void targetCardinalPointsStruct::setTargetEXPP_globalCoodi(real targetEXPP_globalCoodi)
{
	mTargetEXPP_inGlobalCoordi = targetEXPP_globalCoodi;
	mIsEXPP_inGlobalCoordi_target = true;
	mTargetOpti_vec.push_back(targetOptimization::targetEXPP_glocalCoodi);
	mIsOneTargetCardinalPoint = true;
}
real targetCardinalPointsStruct::getTargetEXPP_globalCoodi()
{
	return mTargetEXPP_inGlobalCoordi;
}
bool targetCardinalPointsStruct::isEXPP_globalCoodi_target()
{
	return mIsEXPP_inGlobalCoordi_target;
}
// target EXPD
void targetCardinalPointsStruct::setTargetEXPD(real targetEXPD)
{
	mTargetEXPD = targetEXPD;
	mIsEXPD_target = true;
	mTargetOpti_vec.push_back(targetOptimization::targetEXPD);
	mIsOneTargetCardinalPoint = true;
}
real targetCardinalPointsStruct::getTargetEXPD()
{
	return mTargetEXPD;
}
bool targetCardinalPointsStruct::isEXPD_target()
{
	return mIsEXPD_target;
}
// target mag
void targetCardinalPointsStruct::setTargetMag(real targetMag)
{
	mTargetMag = targetMag;
	mIsMag_target = true;
	mTargetOpti_vec.push_back(targetOptimization::targetMag);
	mIsOneTargetCardinalPoint = true;
}
real targetCardinalPointsStruct::getTargetMag()
{
	return mTargetMag;
}
bool targetCardinalPointsStruct::isMag_target()
{
	return mIsMag_target;
}
// target NA obj space
void targetCardinalPointsStruct::setTargetNA_obj(real targetNA_obj)
{
	mTargetNA_obj = targetNA_obj;
	mIsNA_objSpac_target = true;
	mTargetOpti_vec.push_back(targetOptimization::targetNA_obj);
	mIsOneTargetCardinalPoint = true;
}
real targetCardinalPointsStruct::getTargetNA_obj()
{
	return mTargetNA_obj;
}
bool targetCardinalPointsStruct::isNA_obj_target()
{
	return mIsNA_objSpac_target;
}
// target ENPP in gloabl coodi
void targetCardinalPointsStruct::setTargetENPP_globalCoori(real targetENPP_globalCoodi)
{
	mTargetENPP_inGlobalCoodi = targetENPP_globalCoodi;
	mIsENPP_inGlobalCoodi_target = true;
	mTargetOpti_vec.push_back(targetOptimization::targetENPP_globalCoordi);
	mIsOneTargetCardinalPoint = true;
}
real targetCardinalPointsStruct::getTargetENPP_globalCoodi()
{
	return mTargetENPP_inGlobalCoodi;
}
bool targetCardinalPointsStruct::isENPP_globalCoodi_target()
{
	return mIsENPP_inGlobalCoodi_target;

}
// target ENPP in first surface
void targetCardinalPointsStruct::setTargetENPP_firstSurface(real targetENPP_firstSurface)
{
	mTargetENPP_firstSurface = targetENPP_firstSurface;
	mIsENPP_firstSurface_target = true;
	mTargetOpti_vec.push_back(targetOptimization::targetENPP_firstSur);
	mIsOneTargetCardinalPoint = true;

}
real targetCardinalPointsStruct::getTargetENPP_firstSurface()
{
	return mTargetENPP_firstSurface;
}
bool targetCardinalPointsStruct::isENPP_firstSurface_target()
{
	return mIsENPP_firstSurface_target;
}
// target ENPD
void targetCardinalPointsStruct::setTargetENPD(real targetENPD)
{
	mTargetENPD = targetENPD;
	mIsENPD_target = true;
	mTargetOpti_vec.push_back(targetOptimization::targetENPD);
	mIsOneTargetCardinalPoint = true;

}
real targetCardinalPointsStruct::getTargetENPD()
{
	return mTargetENPD;
}
bool targetCardinalPointsStruct::isENPD_target()
{
	return mIsENPD_target;
}
// target f number
void targetCardinalPointsStruct::setTargetFnum(real targetF_num)
{
	mTargetF_number = targetF_num;
	mIsF_number_target = true;
	mTargetOpti_vec.push_back(targetOptimization::targetFnum);
	mIsOneTargetCardinalPoint = true;
}
real targetCardinalPointsStruct::getTargetFnum()
{
	return mTargetF_number;
}
bool targetCardinalPointsStruct::isF_num_target()
{
	return mIsF_number_target;
}
// NA image space
void targetCardinalPointsStruct::setTargetNA_imaSpace(real targetNA_imaSpace)
{
	mTargetNA_imaSpace = targetNA_imaSpace;
	mIsNA_imaSpace_target = true;
	mTargetOpti_vec.push_back(targetOptimization::targetNA_imaSpace);
	mIsOneTargetCardinalPoint = true;
}
real targetCardinalPointsStruct::getTargetNA_imaSpace()
{
	return mTargetNA_imaSpace;
}
bool targetCardinalPointsStruct::isNA_imaSpace()
{
	return mIsNA_imaSpace_target;
}
// working f number
void targetCardinalPointsStruct::setTargetWFNO(real targetWFNO)
{
	mTargetWFNO = targetWFNO;
	mIsWFNO = true;
	mTargetOpti_vec.push_back(targetOptimization::targetWFNO);
	mIsOneTargetCardinalPoint = true;
}
real targetCardinalPointsStruct::getTargetWFNO()
{
	return mTargetWFNO;
}
bool targetCardinalPointsStruct::isTargetWFNO()
{
	return mIsWFNO;
}
// *** *** //


void targetCardinalPointsStruct::setCardinalPoints_NO_target()
{
	mIsEFL_target = false;
	mIsPP_obj_target = false;
	mIsPP_ima_target = false;
	mIsEXPP_lastSurface_target = false;
	mIsEXPP_inGlobalCoordi_target = false;
	mIsEXPD_target = false;
	mIsMag_target = false;
	mIsNA_objSpac_target = false;
	mIsENPP_inGlobalCoodi_target = false;
	mIsENPP_firstSurface_target = false;
	mIsENPD_target = false;
	mIsF_number_target = false;
	mIsNA_imaSpace_target = false;
	mIsWFNO = false;

	mIsOneTargetCardinalPoint = false;
}

bool targetCardinalPointsStruct::isTargetInVec(targetOptimization target)
{
	std::vector<targetOptimization>::iterator it = std::find(mTargetOpti_vec.begin(), mTargetOpti_vec.end(), target);
	if (it != mTargetOpti_vec.end())
	{
		return true;
	}

	return false;
}

unsigned int targetCardinalPointsStruct::getNumerOfTargets()
{
	return mTargetOpti_vec.size();
}

void targetCardinalPointsStruct::setAllWeightsToOne()
{
	mWeightEFL = 1.0;
	mWeightPP_obj = 1.0;
	mWeightPP_ima = 1.0;
	mWeightEXPP_lastSurface = 1.0;
	mWeightEXPP_inGlobalCoordi = 1.0;
	mWeightEXPD = 1.0;
	mWeightMag = 1.0;
	mWeightNA_obj = 1.0;
	mWeightENPP_inGlobalCoordi = 1.0;
	mWeightENPP_firstSurface = 1.0;
	mWeightENPD = 1.0;
	mWeightF_number = 1.0;
	mWeightNA_imaSpace = 1.0;
	mWeightWFNO = 1.0;
}

bool targetCardinalPointsStruct::getIsOneTargetCardinalPoint()
{
	return mIsOneTargetCardinalPoint;
}

void targetCardinalPointsStruct::setIsOneTargetCardinalPoint(bool isOneTarget)
{
	mIsOneTargetCardinalPoint = isOneTarget;
}

// *** weight factors *** ///
// weight EFL
void targetCardinalPointsStruct::setWeight_EFL(real weightEFL)
{
	mWeightEFL = weightEFL;
}
real targetCardinalPointsStruct::getWeight_EFL()
{
	return mWeightEFL;
}
// weight PP_obj
void targetCardinalPointsStruct::setWeight_PP_obj(real weightPP_obj)
{
	mWeightPP_obj = weightPP_obj;
}
real targetCardinalPointsStruct::getWeight_PP_obj()
{
	return mWeightPP_obj;
}
// weight PP_ima
void targetCardinalPointsStruct::setWeight_PP_ima(real weightPP_ima)
{
	mWeightPP_ima = weightPP_ima;
}
real targetCardinalPointsStruct::getWeight_PP_ima()
{
	return mWeightPP_ima;
}
// weight EXPP_lastSurface
void targetCardinalPointsStruct::setWeight_EXPP_lastSur(real weightEXPP_lastSir)
{
	mWeightEXPP_lastSurface = weightEXPP_lastSir;
}
real targetCardinalPointsStruct::getWeight_EXPP_lastSur()
{
	return mWeightEXPP_lastSurface;
}
// weight EXPP in global coodi
void targetCardinalPointsStruct::setWeight_EXPP_globalCoodi(real weightEXPD_globalCoodi)
{
	mWeightEXPP_inGlobalCoordi = weightEXPD_globalCoodi;
}
real targetCardinalPointsStruct::getWeight_EXPP_globalCoodi()
{
	return mWeightEXPP_inGlobalCoordi;
}
// weight EXPD
void targetCardinalPointsStruct::setWeight_EXPD(real weightEXPD)
{
	mWeightEXPD = weightEXPD;
}
real targetCardinalPointsStruct::getWeight_EXPD()
{
	return mWeightEXPD;
}
// weight mag
void targetCardinalPointsStruct::setWeight_Mag(real weightMag)
{
	mWeightMag = weightMag;
}
real targetCardinalPointsStruct::getWeight_Mag()
{
	return mWeightMag;
}
// weight NA obj space
void targetCardinalPointsStruct::setWeight_NA_obj(real weightNA_obj)
{
	mWeightNA_obj = weightNA_obj;
}
real targetCardinalPointsStruct::getWeight_NA_obj()
{
	return mWeightNA_obj;
}
// weight ENPP in gloabl coodi
void targetCardinalPointsStruct::setWeight_ENPP_globalCoordi(real weightENPP_globalCoordi)
{
	mWeightENPP_inGlobalCoordi = weightENPP_globalCoordi;
}
real targetCardinalPointsStruct::getWeight_ENPP_globalCoordi()
{
	return mWeightENPP_inGlobalCoordi;
}
// weight ENPP in first surface
void targetCardinalPointsStruct::setWeight_ENPP_firstSurface(real weightENPP_firstSurface)
{
	mWeightENPP_firstSurface = weightENPP_firstSurface;
}
real targetCardinalPointsStruct::getWeight_ENPP_firstSurface()
{
	return mWeightENPP_firstSurface;
}
// weight ENPD
void targetCardinalPointsStruct::setWeight_ENPD(real weightENPD)
{
	mWeightENPD = weightENPD;
}
real targetCardinalPointsStruct::getWeight_ENPD()
{
	return mWeightENPD;
}
// weight f number
void targetCardinalPointsStruct::setWeight_Fnum(real weightFnum)
{
	mWeightF_number = weightFnum;
}
real targetCardinalPointsStruct::getWeight_Fnum()
{
	return mWeightF_number;
}
// weight NA image space
void targetCardinalPointsStruct::setWeight_NA_imaSpace(real weightNA_imaSpace)
{
	mWeightNA_imaSpace = weightNA_imaSpace;
}
real targetCardinalPointsStruct::getWeight_NA_imaSpace()
{
	return mWeightNA_imaSpace;
}
// weight WFNO
void targetCardinalPointsStruct::setWeight_WFNO(real weightWFNO)
{
	mWeightWFNO = weightWFNO;
}
real targetCardinalPointsStruct::getWeight_WFNO()
{
	return mWeightWFNO;
}
// *** *** ///

real targetCardinalPointsStruct::calculateMeritVal_targetCardianlPoints_forGenetic(const OpticalSystem_LLT& optSys_LLT, objectPoint_inf_obj inf_obj)
{
	CardinalPoints cardinalPoint(optSys_LLT, inf_obj);

	real returnMeritVal = 0.0;

	if (isTargetInVec(targetOptimization::targetEFL))
	{
		returnMeritVal = returnMeritVal + mWeightEFL * std::abs(mTargetEFL - cardinalPoint.getEFL()) * 1000;
	}

	if (isTargetInVec(targetOptimization::targetPP_obj))
	{
		returnMeritVal = returnMeritVal + mWeightPP_obj * std::abs(mTargetPP_obj - cardinalPoint.getPP_obj()) * 1000;
	}

	if (isTargetInVec(targetOptimization::targetPP_ima))
	{
		returnMeritVal = returnMeritVal + mWeightPP_ima * std::abs(mTargetPP_ima - cardinalPoint.getPP_ima()) * 1000;
	}

	if (isTargetInVec(targetOptimization::targetEXPP_lastSur))
	{
		returnMeritVal = returnMeritVal + mWeightEXPP_lastSurface * std::abs(mTargetEXPP_lastSurface - cardinalPoint.getEXPP_lastSurface()) * 1000;
	}

	if (isTargetInVec(targetOptimization::targetEXPP_glocalCoodi))
	{
		returnMeritVal = returnMeritVal + mWeightEXPP_inGlobalCoordi * std::abs(mTargetEXPP_inGlobalCoordi - cardinalPoint.getEXPP_globalCoori()) * 1000;
	}

	if (isTargetInVec(targetOptimization::targetEXPD))
	{
		returnMeritVal = returnMeritVal + mWeightEXPD * std::abs(mTargetEXPD - cardinalPoint.getEXPD()) * 1000;
	}

	if (isTargetInVec(targetOptimization::targetMag))
	{
		returnMeritVal = returnMeritVal + mWeightMag * std::abs(mTargetMag - cardinalPoint.getMagnification()) * 1000;
	}

	if (isTargetInVec(targetOptimization::targetNA_obj))
	{
		returnMeritVal = returnMeritVal + mWeightNA_obj * std::abs(mTargetNA_obj - cardinalPoint.getNA_objSpace()) * 1000;
	}

	if (isTargetInVec(targetOptimization::targetENPP_globalCoordi))
	{
		returnMeritVal = returnMeritVal + mWeightENPP_inGlobalCoordi * std::abs(mTargetENPP_inGlobalCoodi - cardinalPoint.getENPP_globalCoodi()) * 1000;
	}

	if (isTargetInVec(targetOptimization::targetENPP_firstSur))
	{
		returnMeritVal = returnMeritVal + mWeightENPP_firstSurface * std::abs(mTargetENPP_firstSurface - cardinalPoint.getENPP_firstSurface()) * 1000;
	}

	if (isTargetInVec(targetOptimization::targetENPD))
	{
		returnMeritVal = returnMeritVal + mWeightENPD * std::abs(mTargetENPD - cardinalPoint.getENPD()) * 1000;
	}

	if (isTargetInVec(targetOptimization::targetFnum))
	{
		returnMeritVal = returnMeritVal + mWeightF_number * std::abs(mTargetF_number - cardinalPoint.getF_num_imaSpace()) * 1000;
	}

	if (isTargetInVec(targetOptimization::targetNA_imaSpace))
	{
		returnMeritVal = returnMeritVal + mWeightNA_imaSpace * std::abs(mTargetNA_imaSpace - cardinalPoint.getNA_imaSpace()) * 1000;
	}

	if (isTargetInVec(targetOptimization::targetWFNO))
	{
		returnMeritVal = returnMeritVal + mWeightWFNO * std::abs(mTargetWFNO - cardinalPoint.getWorkingFnumber()) * 1000;
	}

	return returnMeritVal;

}

void targetCardinalPointsStruct::setTargetOpti_vec(std::vector<targetOptimization> targetOpti_vec)
{
	mTargetOpti_vec = targetOpti_vec;
}
std::vector<targetOptimization> targetCardinalPointsStruct::getTargetOpti_vec()
{
	return mTargetOpti_vec;
}

void targetCardinalPointsStruct::calcualteMeritVal_targetCardinalPoints_forDLS(const OpticalSystem_LLT& optSys_LLT, objectPoint_inf_obj inf_obj, std::vector<real>& aberrationFct)
{
	CardinalPoints cardinalPoint(optSys_LLT, inf_obj);
	real tempMeritVal = 0.0;

	unsigned int sizeAberrationFct = aberrationFct.size();
	unsigned int posInAberFct = aberrationFct.size() - mTargetOpti_vec.size();

	if (isTargetInVec(targetOptimization::targetEFL))
	{
		tempMeritVal = mWeightEFL * std::abs(mTargetEFL - cardinalPoint.getEFL()) * 1000;
		aberrationFct[posInAberFct] = tempMeritVal;
		++posInAberFct;
	}

	if (isTargetInVec(targetOptimization::targetPP_obj))
	{
		tempMeritVal = mWeightPP_obj * std::abs(mTargetPP_obj - cardinalPoint.getPP_obj()) * 1000;
		aberrationFct[posInAberFct] = tempMeritVal;
		++posInAberFct;
	}

	if (isTargetInVec(targetOptimization::targetPP_ima))
	{
		tempMeritVal = mWeightPP_ima * std::abs(mTargetPP_ima - cardinalPoint.getPP_ima()) * 1000;
		aberrationFct[posInAberFct] = tempMeritVal;
		++posInAberFct;
	}

	if (isTargetInVec(targetOptimization::targetEXPP_lastSur))
	{
		tempMeritVal = mWeightEXPP_lastSurface * std::abs(mTargetEXPP_lastSurface - cardinalPoint.getEXPP_lastSurface()) * 1000;
		aberrationFct[posInAberFct] = tempMeritVal;
		++posInAberFct;
	}

	if (isTargetInVec(targetOptimization::targetEXPP_glocalCoodi))
	{
		tempMeritVal = mWeightEXPP_inGlobalCoordi * std::abs(mTargetEXPP_inGlobalCoordi - cardinalPoint.getEXPP_globalCoori()) * 1000;
		aberrationFct[posInAberFct] = tempMeritVal;
		++posInAberFct;
	}

	if (isTargetInVec(targetOptimization::targetEXPD))
	{
		tempMeritVal = mWeightEXPD * std::abs(mTargetEXPD - cardinalPoint.getEXPD()) * 1000;
		aberrationFct[posInAberFct] = tempMeritVal;
		++posInAberFct;
	}

	if (isTargetInVec(targetOptimization::targetMag))
	{
		tempMeritVal = mWeightMag * std::abs(mTargetMag - cardinalPoint.getMagnification()) * 1000;
		aberrationFct[posInAberFct] = tempMeritVal;
		++posInAberFct;
	}

	if (isTargetInVec(targetOptimization::targetNA_obj))
	{
		tempMeritVal = mWeightNA_obj * std::abs(mTargetNA_obj - cardinalPoint.getNA_objSpace()) * 1000;
		aberrationFct[posInAberFct] = tempMeritVal;
		++posInAberFct;
	}

	if (isTargetInVec(targetOptimization::targetENPP_globalCoordi))
	{
		tempMeritVal = mWeightENPP_inGlobalCoordi * std::abs(mTargetENPP_inGlobalCoodi - cardinalPoint.getENPP_globalCoodi()) * 1000;
		aberrationFct[posInAberFct] = tempMeritVal;
		++posInAberFct;
	}

	if (isTargetInVec(targetOptimization::targetENPP_firstSur))
	{
		tempMeritVal = mWeightENPP_firstSurface * std::abs(mTargetENPP_firstSurface - cardinalPoint.getENPP_firstSurface()) * 1000;
		aberrationFct[posInAberFct] = tempMeritVal;
		++posInAberFct;
	}

	if (isTargetInVec(targetOptimization::targetENPD))
	{
		tempMeritVal = mWeightENPD * std::abs(mTargetENPD - cardinalPoint.getENPD()) * 1000;
		aberrationFct[posInAberFct] = tempMeritVal;
		++posInAberFct;
	}

	if (isTargetInVec(targetOptimization::targetFnum))
	{
		tempMeritVal = mWeightF_number * std::abs(mTargetF_number - cardinalPoint.getF_num_imaSpace()) * 1000;
		aberrationFct[posInAberFct] = tempMeritVal;
		++posInAberFct;
	}

	if (isTargetInVec(targetOptimization::targetNA_imaSpace))
	{
		tempMeritVal = mWeightNA_imaSpace * std::abs(mTargetNA_imaSpace - cardinalPoint.getNA_imaSpace()) * 1000;
		aberrationFct[posInAberFct] = tempMeritVal;
		++posInAberFct;
	}

	if (isTargetInVec(targetOptimization::targetWFNO))
	{
		tempMeritVal = mWeightWFNO * std::abs(mTargetWFNO - cardinalPoint.getWorkingFnumber()) * 1000;
		aberrationFct[posInAberFct] = tempMeritVal;
		++posInAberFct;
	}
}