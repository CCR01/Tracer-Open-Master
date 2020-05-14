#include "importantOptimizeStructs.h"



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


