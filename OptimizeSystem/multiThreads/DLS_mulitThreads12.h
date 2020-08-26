#pragma once
#include "..\DampedLeastSquares.h"

class DLS_multiThreads_12
{
public:
	DLS_multiThreads_12();
	// obj
	DLS_multiThreads_12(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms);
	DLS_multiThreads_12(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, defaultParaDLS defaultParameterDLS);
	DLS_multiThreads_12(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, /*target cardinal points*/ targetCardinalPointsStruct targetCarPoints, defaultParaDLS defaultParameterDLS);
	// inf
	DLS_multiThreads_12(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<real> /*angleX*/ angleX, std::vector<real> /*angleY*/ angleY, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, /*target cardinal points*/ targetCardinalPointsStruct targetCarPoints, defaultParaDLS defaultParameterDLS);
	
	~DLS_multiThreads_12();

	OpticalSystemElement DLS_optimisation_multiThreads_12_obj();
	OpticalSystemElement DLS_optimisation_multiThreads_12_inf();
	void loadDefaulParameters();
	void loadFactorBetterAndWorst();

private:
	OpticalSystemElement mOpticalSystemElement_start{};
	std::vector<VectorStructR3> mFields_vec{};
	std::vector<real> mAnglesX{};
	std::vector<real> mAnglesY{};
	std::vector<real> mWavelength_vec{};
	unsigned int mRings{};
	unsigned int mArms{};
	defaultParaDLS mDefaultParameterDLS{};

	std::vector<real> mFactorBetter_vec{};
	std::vector<real> mFactorWorst_vec{};
	std::vector<real> mAllMeritVal_vec{};
	real mBestMeritVal{};
	std::vector<OpticalSystemElement> mBestOptSysEle_vec{};
	OpticalSystemElement bestOpticalSystem{};

	targetCardinalPointsStruct mTargetCarPoints{};
};

