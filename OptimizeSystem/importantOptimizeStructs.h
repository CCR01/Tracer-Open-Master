#pragma once
#include "..\OpticalSystemElement\OpticalSystemElement.h"

enum kindParaOptSys { radiusVar, thickness_Var, fix };

struct parameterVar
{
public:

	parameterVar();
	~parameterVar();

	// surface number
	std::vector<unsigned int> getAllSurfaceNumWithVar();
	void setAllSurfaceNumWithVar(std::vector<unsigned int> allSurfaceNumWithVar);
	// kind parameter
	std::vector<kindParaOptSys> getAllParaWithVar();
	void setAllParaWithVar(std::vector<kindParaOptSys> allParaWithVar);
	// kind parameter number
	kindParaOptSys getKindParameter_i(unsigned int number);
	void setKindParameter_i(unsigned int number, kindParaOptSys kindPara);


	// minVar
	std::vector<real> getAllMinVar();
	void setAllMinVar(std::vector<real> allMinVar);
	// maxVar
	std::vector<real> getAllMaxVar();
	void setAllMaxVar(std::vector<real> allMaxVar);

	// load system parameter
	void loadSystemParameter(OpticalSystemElement optSysEle);

	// clear all vector
	void clear();

private:
	std::vector<unsigned int> mSurfaceNumWithVar_vec;
	std::vector<kindParaOptSys> mKindPara_WithVar_vec;
	std::vector<real> mMinValVar_vec;
	std::vector<real> mMaxValVar_vec;
};



