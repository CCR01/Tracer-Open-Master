#pragma once

#include "BuildSystemsForCombination.h"
#include "..\Analyse\Seidel Coefficients.h"

struct settingsMeritFct_SeidelCoef
{
	real getSeidelSum() const;
	void setSeidelSum(const real seidelSUM);
	real getWeightSeidelSUM() const;
	void setWeightSeidelSUM(const real weightSeidelSum);

	real getSum_S1_sphere() const;
	void setSum_S1_sphere(const real Sum_S1_sphere);
	real getWeight_S1_sphere() const;
	void setWeight_S1_sphere(const real weightS1_sphere);

	real getSum_S2_coma() const;
	void setSum_S2_coma(const real Sum_S2_coma);
	real getWeight_S2_coma() const;
	void setWeight_S2_coma(const real weightS2_coma);

	real getSum_S3_astigmatism() const;
	void setSum_S3_astigmatism(const real Sum_S3_astigmatism);
	real getWeight_S3_astigmatism() const;
	void setWeight_S3_astigmatism(const real weightS3_astigmatism);

	real getSum_S4_fieldCurvature() const;
	void setSum_S4_fieldCurvature(const real Sum_S4_fieldCurvature);
	real getWeight_S4_fieldCurvature() const;
	void setWeight_S4_fieldCurvature(const real weightS4_fieldCurvature);

	real getSum_S5_distortion() const;
	void setSum_S5_distortion(const real Sum_S5_distortion);
	real getWeight_S5_distortion() const;
	void setWeight_S5_distortion(const real weightS5_distortion);

	real getSum_S6_C1_axialColor() const;
	void setSum_S6_C1_axialColor(const real Sum_S6_C1_axialColor);
	real getWeight_S6_C1_axialColor() const;
	void setWeight_S6_C1_axialColor(const real weightS6_C1_axialColor);

	real getSum_S7_C2_lateralColor() const;
	void setSum_S7_C2_lateralColor(const real Sum_S7_C2_lateralColor);
	real getWeight_S7_C2_lateralColor() const;
	void setWeight_S7_C2_lateralColor(const real weightS7_C2_lateralColor);

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

	real mSeidelSum;
	real mWeightSeidelSum;
	real mSum_S1_sphere;
	real mWeight_S1_sphere;
	real mSum_S2_coma;
	real mWeight_S2_coma;
	real mSum_S3_astigmatism;
	real mWeight_S3_astigmatism;
	real mSum_S4_fieldCurvature;
	real mWeight_S4_fieldCurvature;
	real mSum_S5_distortion;
	real mWeight_S5_distortion;
	real mSum_S6_C1_axialColor;
	real mWeight_S6_C1_axialColor;
	real mSum_S7_C2_lateralColor;
	real mWeight_S7_C2_lateralColor;


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

//SeidelCoefficients(OpticalSystemElement opticalSys_Ele, LightRayStruct chefLightRay, LightRayStruct marginalLightRay, std::vector<real> wavelenght_vec, unsigned int posAperStop, real focalLength, real lagrangeInvariant, bool aperInlens);

class EvaluateManyOptSystems_SeidelCoef
{
public:
	EvaluateManyOptSystems_SeidelCoef();
	EvaluateManyOptSystems_SeidelCoef(OpticalSystemElement optSysEle, std::vector<stepsWithoutMinWithoutMax> addInfosVariables, std::vector<VectorStructR3> fields, std::vector<real> wavelenght_vec);
	EvaluateManyOptSystems_SeidelCoef(std::vector<OpticalSystemElement> optSysEle_vec, std::vector<VectorStructR3> fields, std::vector<real> wavelenght_vec);
	~EvaluateManyOptSystems_SeidelCoef();

	void loadDefaultSettings();

	void getHeighestFieldPoint_Y(); // get heighest y-value of mFields

	real calcLagrangeInvariant(LightRayStruct marginalLightRay);
	void calcAllSeidelCoefficients(std::vector<OpticalSystemElement> optSysEle_vec);

	// find marginal ray
	LightRayStruct findMarginalRay_obj(OpticalSystemElement optSys_Ele);
	//	LightRayStruct findMarginalRay_inf(VectorStructR3 posApertureStop, real semiHeigthAperStop);

	LightRayStruct findChiefRay_obj(OpticalSystemElement optSys_Ele);
	//	LightRayStruct findChiefRay_inf(real heihestYfromFields, VectorStructR3 posApertureStop, real semiHeigthAperStop);

	real calcContributionMerit(real const& weight, real const& targetValue, real const& currentValue, real const& comparsion);
	real calcMeritValue(SeidelCoefficients seidelCoef, CardinalPoints cardinaPoints);

	void calcBestOptSys_withSysForCom();
	OpticalSystemElement calcBestOptSys_OptSysVec();
	OpticalSystemElement getBestOptSys();

	// calc all seidel coef

private:
	BuildSystemsForCombination mSystemForCombinationsElement{};
	std::vector<OpticalSystemElement> mOptSysEle_vec;
	std::vector<SeidelCoefficients> mAllSeidelCoefficients{};
	std::vector<real> mAllMeritValues;

	std::vector<VectorStructR3> mFields{};
	OpticalSystemElement mOptSysEle{};
	std::vector<stepsWithoutMinWithoutMax> mAddInfosVariables{};
	std::vector<real> mWavelenght_vec{};
	real mPrimeWavelength{};
	settingsMeritFct_SeidelCoef mSettingMeritFunction{};

	OpticalSystemElement mBestOptSys;

	VectorStructR3 mHeighestFieldPoint{};


	real lagrangeInvariant{};


};

