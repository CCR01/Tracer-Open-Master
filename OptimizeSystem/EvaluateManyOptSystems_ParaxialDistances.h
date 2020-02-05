#pragma once

#include "calculateParaxialDistances.h"
#include "BuildSystemsForCombination.h"

struct settingsMeritFct_ParaxialDistances
{
	real getTargetS_dash() const;
	void setTargetS_dash(const real targetS_dash);
	real getWeightTargetS_dash() const;
	void setWeightTargetS_dash(const real weightTargetS_dash);

	real getEFL() const;
	void setEFL(const real efl);
	real getWeightEFL() const;
	void setWeightEFL(const real weightEFL);

	real getPP() const;
	void setPP(const real pp);
	real getWeightPP() const;
	void setWeightPP(const real weightPP);

	real getAntiPP() const;
	void setAntiPP(const real antiPP);
	real getWeightAntiPP() const;
	void setWeightAntiPP(const real weightAntiPP);

	real getEXPP_accordingToLastSurface() const;
	void setEXPP_accordingToLastSurface(const real expp_lastSurface);
	real getWeightEXPP_accordingToLastSurface() const;
	void setWeightEXPP_accordingToLastSurface(const real weightEXPP_accordingToLastSurface);

	real getEXPP_global() const;
	void setEXPP_global(const real exppGlobal);
	real getWeightEXPP_global() const;
	void setWeightEXPP_global(const real weightEXPP_global);

	real getEXPD() const;
	void setEXPD(const real expd);
	real getWeightEXPD() const;
	void setWeightEXPD(const real weightEXPD);

	real getMag() const;
	void setMag(const real mag);
	real getWeightMag() const;
	void setWeightMag(const real weightMag);


private:
	real mTargetS_dash;
	real mWeightTargetS_dash;
	real mEFL;
	real mWeightEFL;
	real mPP;
	real mWeightPP;
	real mAntiPP;
	real mWeightAntiPP;
	real mEXPP_accordingToLastSurface;
	real mWeightEXPP_accordingToLastSurface;
	real mEXPP_inGlobalCoordinatSystem;
	real mWeightEXPP_inGlobalCoordinatSystem;
	real mEXPD;
	real mWeightEXPD;
	real mMag;
	real mWeightMag;
};

class EvaluateManyOptSystems_ParaxialDistances
{
public:
	EvaluateManyOptSystems_ParaxialDistances();
	EvaluateManyOptSystems_ParaxialDistances(OpticalSystemElement optSysEle, std::vector<stepsWithoutMinWithoutMax> addInfosVariable, StartRayPos startRay, real primWavelength);
	~EvaluateManyOptSystems_ParaxialDistances();

	void calculateTargetS_dash(OpticalSystem_LLT optSys_LLT);
	void loadDefaultSettingsMeritFct();
	real calcContributionMerit(real const& weight, real const& targetValue, real const& currentValue, real const& comparsion);
	real calcMeritValue(OpticalSystem_LLT optSys_LLT, real currentS_dash, real targetS_dahs);

	void calcAllMeritValuesParaxialDistances();
	std::vector<OpticalSystem_LLT> getBestOpticalSys_LLTinVec_meritLessThan(real const lessThan);
	OpticalSystem_LLT getBestOptSys();

	//get n best optical systems
	std::vector<OpticalSystem_LLT> get_N_BestOptSys_LLT(unsigned int numberBestOptSys);

	// convert N optical system LLTs to element systems
	std::vector<OpticalSystemElement> convert_N_optSysLLT_To_elementSystems(std::vector<OpticalSystem_LLT> optSys_LLT_vec, OpticalSystemElement optSysEle);

	// get systems for combination
	BuildSystemsForCombination getSystemsForCombination();

	// do more iterations
	void doOneMoreIteration_3var(OpticalSystemElement startOptSysEle, OpticalSystem_LLT bestOptSys, parameterTypeModeStruct V0, parameterTypeModeStruct V1, parameterTypeModeStruct V2);

private:

	BuildSystemsForCombination mSystemForCombinations;

	OpticalSystemElement mOptSysEle{};
	std::vector<stepsWithoutMinWithoutMax> mAddInfosVariable{};
	StartRayPos mStartRay{};
	real mPrimWavelength{};
	settingsMeritFct_ParaxialDistances mSettingMeritFunction{};


	std::vector<CalculateParaxialDistances> mAllPraxialDistances{};
	std::vector<real> mAllMeritValues_vec{};



};
