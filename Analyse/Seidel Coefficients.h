#pragma once

#include "..\OpticalSystemElement\OpticalSystemElement.h"
#include "..\SequentialRayTracing\SequentialRayTracer.h"
#include "CardinalPoints.h"

class SeidelCoefficients
{
public:
	SeidelCoefficients();
	SeidelCoefficients(OpticalSystemElement opticalSys_Ele, LightRayStruct chefLightRay, LightRayStruct marginalLightRay, std::vector<real> wavelenght_vec, unsigned int posAperStop, real focalLength, real lagrangeInvariant, bool aperInlens);
	~SeidelCoefficients();

	void calcSeidelCoef_superFuction(OpticalSystemElement opticalSys_Ele, LightRayStruct chefLightRay, LightRayStruct marginalLightRay, std::vector<real> wavelenght_vec, unsigned int posAperStop, real focalLength, real lagrangeInvariant, bool aperInlens);

	void calculateD();

	void setRefractiveIndexesAccordingToPrimWavelength();

	void buildOptSysWithoutApertureStop();

	void setOpticalSys_Ele();

	// calculate the spherical seidel coeffizients
	void calcOneByR();
	void calculate_RelevantValuesForSeidel();
	void calcCardinalPoints();
	///void calcLagrangeInvariant();
	//void calculate_U_bar();
	void calculate_h_bar();
	//void calculate_A_bar();

	void setWavelength(std::vector<real> wavelenght_vec);

	std::vector<real> getall_S1();

	void calculateRefIndexAtSurface();

	void calcMeanRefIndex();
	void findMinAndMaxRefIndex();
	void calcDeltaNandU_wavelength();


	void calculateOnebyN();
	void calculateDeltaUandN();
	void calculateS1();
	void calculateS2();
	void calculateS3();
	void calculateS4();
	void calculateS5();
	void calculateS6_C1();
	void calculateS7_C2();

	void calcSumS1();
	void calcSumS2();
	void calcSumS3();
	void calcSumS4();
	void calcSumS5();
	void calcSumS6_C1();
	void calcSumS7_C2();

	void setPosApertureStop(unsigned int posApertureStop);

	void calcE();
	void calcA_bar();

	real getS1_at_surface_i(unsigned int i);
	real getS1sum();
	real getS2_at_surface_i(unsigned int i);
	real getS2sum();
	real getS3_at_surface_i(unsigned int i);
	real getS3sum();
	real getS4_at_surface_i(unsigned int i);
	real getS4sum();
	real getS5_at_surface_i(unsigned int i);
	real getS5sum();
	real getS6_C1_at_surface_i(unsigned int i);
	real getS6C1sum();
	real getS7_C2_at_surface_i(unsigned int i);
	real getS7C2sum();




private:

	OpticalSystemElement mOpticalSys_Ele_USE;
	OpticalSystemElement mOpticalSys_Ele;
	OpticalSystemElement mOpticalSys_Ele_WithoutApertureStop;
	LightRayStruct mChiefLightRay;
	LightRayStruct mMarginalLightRay;

	bool mAperInLens;


	//
	std::vector<real> mD;
	real mLagrangeInvariant;



	// dash -> marginal ray
	std::vector<real> mA_vec;
	std::vector<real> mh_vec;
	std::vector<real> mU_vec;
	std::vector<real> mN_vec;
	std::vector<real> mU_dash_vec;
	std::vector<real> mN_dash_vec;

	std::vector<real> mE_afterStop_vec;
	std::vector<real> mE_beforeStop_vec;
	std::vector<real> mE;

	// bar -> chief ray
	std::vector<real> mU_bar_vec;
	std::vector<real> mA_bar_vec;
	std::vector<real> mh_bar_vec;


	// seidel coeffizients
	//std::vector<real> mS1_vec;

	CardinalPoints mCardinalPoints;
	real mFocalLenght;

	std::vector<real> mMinRefIndex_vec;
	std::vector<real> mMaxRefIndex_vec;

	std::vector<real> mWavelength_vec;

	std::vector<std::vector<real>> mRefIndex_vec;
	std::vector<std::vector<real>> mRefIndex_dash_vec;

	std::vector<real> mRefIndexMean_vec;
	std::vector<real> mRefIndexSum_vec;
	std::vector<real> mDeltaNandU_wavelength_vec;
	std::vector<real> mOneByRadius_C_vec;
	std::vector<real> mOneByRadius_C_direction_vec;

	std::vector<real> mOnebyN_vec;
	std::vector<real> mDeltaUandN_vec;

	unsigned int mPosApertureStop;
	unsigned int lengthOptSys; // neu

	std::vector<real> mS1_vec;
	std::vector<real> mS2_vec;
	std::vector<real> mS3_vec;
	std::vector<real> mS4_vec;
	std::vector<real> mS5_vec;
	std::vector<real> mS6_C1_vec;
	std::vector<real> mS7_C2_vec;

	real mSum_S1;
	real mSum_S2;
	real mSum_S3;
	real mSum_S4;
	real mSum_S5;
	real mSum_S6_C1;
	real mSum_S7_C2;


	std::vector<real> mCod_S1_vec;
	std::vector<real> mCod_S2_vec;
	std::vector<real> mCod_Diameter_vec;

};

