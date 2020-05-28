#pragma once

#include "..\OpticalSystemElement\OpticalSystemElement.h"
#include "..\OptimizeSystem\BuildSystemsForCombination.h"

// Cardinal points
#include "..\Analyse\CardinalPoints.h"


struct InterPointsLastSurfaceAndCheckVignetting
{
public:

	// interpoints last surface
	std::vector<VectorStructR3> getInterPointsLastSurface() const;
	void setInterPointsLastSurface(const std::vector<VectorStructR3>& interpointsLastSurface);

	// vignetting
	bool getIsVignetting();
	void setIsVignetting(bool isVignetting);

private:
	std::vector<VectorStructR3> mInterPointsLastSurface;
	bool mIsVignetting;

};

struct settingsMeritFct_RayTracing
{
	
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

	// rings
	unsigned int getRings();
	void setRings(unsigned int rings);
	// arms
	unsigned int getArms();
	void setArms(unsigned int arms);

	// light
	Light_LLT getLight(unsigned int number);
	void setLight(unsigned int number, Light_LLT mLight);

	// filed
	unsigned int getWeightField(unsigned int number);
	void setWeightField(unsigned int number, unsigned int weight);
	// wavelength
	unsigned int getWeightWavelength(unsigned int number);
	void setWeightWavelength(unsigned int number, unsigned int weight);

	void resizeVector(/*number wavelenght*/ unsigned int numWave, /*number fields*/ unsigned int numField);

private:


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

	unsigned int mRings;
	unsigned int mArms;

	std::vector<Light_LLT> mLightVec;

	std::vector<unsigned int> mWeightFieldsVec;
	std::vector<unsigned int> mWeightWavelengthVec;
};

class EvaluateManyOptSys_RayTracing
{
public:
	EvaluateManyOptSys_RayTracing();
	EvaluateManyOptSys_RayTracing(OpticalSystemElement optSysEle, std::vector<stepsWithoutMinWithoutMax> addInfosVariables, std::vector<VectorStructR3> fields, std::vector<real> wavelenght_vec);
	~EvaluateManyOptSys_RayTracing();

	void loadDefaultSettings();

	real doRayTracingOptlSystemAndCalcRMScon(OpticalSystemElement optSysEle);
	real calcContributionMerit(real const& weight, real const& targetValue, real const& currentValue, real const& comparsion);
	real calcMeritValue(real conRMS, OpticalSystemElement optSysEle);

	void calcMetitValueAllOptSys();

	void findBestOptSys();
	OpticalSystemElement getBestOptSys();

	BuildSystemsForCombination getSysForCom();

private:
	BuildSystemsForCombination mSystemForCombinationsElement{};
	std::vector<real> mAllMeritValues;

	settingsMeritFct_RayTracing mSettingsMeritFct;

	std::vector<VectorStructR3> mFields{};
	OpticalSystemElement mOptSysEle{};

	std::vector<stepsWithoutMinWithoutMax> mAddInfosVariables{};
	std::vector<real> mWavelenght_vec{};
	real mPrimeWavelength{};

	OpticalSystemElement mBestOptSysEle;

	real lagrangeInvariant{};

};

