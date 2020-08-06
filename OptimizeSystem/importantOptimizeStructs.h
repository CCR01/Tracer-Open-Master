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
	std::vector<unsigned int> mSurfaceNumWithVar_vec{};
	std::vector<kindParaOptSys> mKindPara_WithVar_vec{};
	std::vector<real> mMinValVar_vec{};
	std::vector<real> mMaxValVar_vec{};
};

struct withOutMinMax
{
public:

	withOutMinMax();
	~withOutMinMax();

	// without min
	real getWithoutMin();
	void setWithoutMin(real withoutMin);

	// without max
	real getWithoutMax();
	void setWithoutMax(real withoutMax);

private:
	real mWithoutMin{};
	real mWithoutMax{};
};

enum class targetOptimization { targetEFL, targetPP_obj, targetPP_ima, targetEXPP_lastSur, targetEXPP_glocalCoodi, targetEXPD, targetMag, targetNA_obj, targetENPP_globalCoordi, targetENPP_firstSur, targetENPD, targetFnum, targetNA_imaSpace, targetWFNO };


struct targetCardinalPointsStruct
{
public:
	targetCardinalPointsStruct();
	~targetCardinalPointsStruct();
	
	void setCardinalPointsNOtarget();
	bool isTargetInVec(targetOptimization target);
	unsigned int getNumerOfTargets();
	void setAllWeightsToOne();
	bool getIsOneTargetCardinalPoint();

	// calculate merit values according to cardinal points
	real calculateMeritVal_targetCardianlPoints(const OpticalSystem_LLT& optSys_LLT, objectPoint_inf_obj inf_obj);

	// *** set and get target cardinal points *** //
	// target EFL
	void setTargetEFL(real targetEFL);
	real getTargetEFL();
	bool isEFL_target();
	// target PP_obj
	void setTargetPP_obj(real targetPP_obj);
	real getTargetPP_obj();
	bool isPP_obj_target();
	// target PP_ima
	void setTargetPP_ima(real targetPP_ima);
	real getTargetPP_ima();
	bool isPP_ima_target();
	// target EXPP_lastSurface
	void setTargetEXPP_lastSurface(real targetEXPP_lastSurface);
	real getTargetEXPP_lastSurface();
	bool isEXPP_lastSurface_target();
	// target EXPP in global coodi
	void setTargetEXPP_globalCoodi(real targetEXPP_globalCoodi);
	real getTargetEXPP_globalCoodi();
	bool isEXPP_globalCoodi_target();
	// target EXPD
	void setTargetEXPD(real targetEXPD);
	real getTargetEXPD();
	bool isEXPD_target();
	// target mag
	void setTargetMag(real targetMag);
	real getTargetMag();
	bool isMag_target();
	// target NA obj space
	void setTargetNA_obj(real targetNA_obj);
	real getTargetNA_obj();
	bool isNA_obj_target();
	// target ENPP in gloabl coodi
	void setTargetENPP_globalCoori(real targetENPP_globalCoodi);
	real getTargetENPP_globalCoodi();
	bool isENPP_globalCoodi_target();
	// target ENPP in first surface
	void setTargetENPP_firstSurface(real targetENPP_firstSurface);
	real getTargetENPP_firstSurface();
	bool isENPP_firstSurface_target();
	// target ENPD
	void setTargetENPD(real targetENPD);
	real getTargetENPD();
	bool isENPD_target();
	// target f number
	void setTargetFnum(real targetF_num);
	real getTargetFnum();
	bool isF_num_target();
	// NA image space
	void setTargetNA_imaSpace(real targetNA_imaSpace);
	real getTargetNA_imaSpace();
	bool isNA_imaSpace();
	// working f number
	void setWFNO(real targetWFNO);
	real getTargetWFNO();
	bool isTargetWFNO();

	// *** *** //

	// *** weight factors *** ///
	// weight EFL
	void setWeight_EFL(real weightEFL );
	real getWeight_EFL();
	// weight PP_obj
	void setWeight_PP_obj(real weightPP_obj);
	real getWeight_PP_obj();
	// weight PP_ima
	void setWeight_PP_ima(real weightPP_ima);
	real getWeight_PP_ima();
	// weight EXPP_lastSurface
	void setWeight_EXPP_lastSur(real weightEXPP_lastSir);
	real getWeight_EXPP_lastSur();
	// weight EXPP in global coodi
	void setWeight_EXPP_globalCoodi(real weightEXPD_globalCoodi);
	real getWeight_EXPP_globalCoodi();
	// weight EXPD
	void setWeight_EXPD(real weightEXPD);
	real getWeight_EXPD();
	// weight mag
	void setWeight_Mag(real weightMag);
	real getWeight_Mag();
	// weight NA obj space
	void setWeight_NA_obj(real weightNA_obj);
	real getWeight_NA_obj();
	// weight ENPP in gloabl coodi
	void setWeight_ENPP_globalCoordi(real weightENPP_globalCoordi);
	real getWeight_ENPP_globalCoordi();
	// weight ENPP in first surface
	void setWeight_ENPP_firstSurface(real weightENPP_firstSurface);
	real getWeight_ENPP_firstSurface();
	// weight ENPD
	void setWeight_ENPD(real weightENPD);
	real getWeight_ENPD();
	// weight f number
	void setWeight_Fnum(real weightFnum);
	real getWeight_Fnum();
	// weight NA image space
	void setWeight_NA_imaSpace(real weightNA_imaSpace);
	real getWeight_NA_imaSpace();
	// weight WFNO
	void setWeight_WFNO(real weightWFNO);
	real getWeight_WFNO();
	// *** *** ///

private:
	real mTargetEFL{};
	real mTargetPP_obj{};
	real mTargetPP_ima{};
	real mTargetEXPP_lastSurface{};
	real mTargetEXPP_inGlobalCoordi{};
	real mTargetEXPD{};
	real mTargetMag{};
	real mTargetNA_obj{};
	real mTargetENPP_inGlobalCoodi{};
	real mTargetENPP_firstSurface{};
	real mTargetENPD{};
	real mTargetF_number{};
	real mTargetNA_imaSpace{};
	real mTargetWFNO{};

	bool mIsEFL_target{};
	bool mIsPP_obj_target{};
	bool mIsPP_ima_target{};
	bool mIsEXPP_lastSurface_target{};
	bool mIsEXPP_inGlobalCoordi_target{};
	bool mIsEXPD_target{};
	bool mIsMag_target{};
	bool mIsNA_objSpac_target{};
	bool mIsENPP_inGlobalCoodi_target{};
	bool mIsENPP_firstSurface_target{};
	bool mIsENPD_target{};
	bool mIsF_number_target{};
	bool mIsNA_imaSpace_target{};
	bool mIsWFNO{};

	real mWeightEFL{};
	real mWeightPP_obj{};
	real mWeightPP_ima{};
	real mWeightEXPP_lastSurface{};
	real mWeightEXPP_inGlobalCoordi{};
	real mWeightEXPD{};
	real mWeightMag{};
	real mWeightNA_obj{};
	real mWeightENPP_inGlobalCoordi{};
	real mWeightENPP_firstSurface{};
	real mWeightENPD{};
	real mWeightF_number{};
	real mWeightNA_imaSpace{};
	real mWeightWFNO{};


	std::vector<targetOptimization> mTargetOpti_vec{};
	bool mIsOneTargetCardinalPoint{};
};
