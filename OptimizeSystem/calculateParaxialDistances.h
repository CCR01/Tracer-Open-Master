#pragma once

#include "..\OpticalSystemElement\OpticalSystemElement.h"

enum StartRayPos { notInfinity, infinity };

class CalculateParaxialDistances
{
public:
	CalculateParaxialDistances();
	CalculateParaxialDistances(OpticalSystemElement optSysEle, StartRayPos startRay, real primaryWavelength);
	CalculateParaxialDistances(OpticalSystem_LLT optSys_LLT, StartRayPos startRay, real primaryWavelength);
	~CalculateParaxialDistances();

	void setRefractiveIndexesAccordingToPrimWavelength();

	void calcDistancesAllSurfaces();

	void calcNandNdash();
	void calcFocallength_each_surface();
	void calcS_object_image();

	real getS_atSurface_i(unsigned int i);
	real getS_dash_atSurface_i(unsigned int i);
	real getFocallength_atSurface_i(unsigned int i);

	std::vector<real> getAll_S();
	std::vector<real> getAll_S_dash();

private:

	OpticalSystemElement mOptSysEle;
	OpticalSystem_LLT optSys_LLT;
	StartRayPos mStartRay;
	real mPrimaryWavelength;

	std::vector<real> mDistancesAllSurfaces;

	std::vector<real> mParaDis_S_vec;
	std::vector<real> mParaDis_Sdash_vec;

	std::vector<real> mN_vec;
	std::vector<real> mN_dash_vec;



	std::vector<real> mFocalLength_each_surface_vec;
	std::vector<real> mS_vec;
	std::vector<real> mS_dash_vec;
	std::vector<real> mRadius_with_prefix_vec;



};


