#pragma once
#include "..\LowLevelTracing\OpticalSystem_LLT.h"

class ExitPupilCalculation
{
public:
	ExitPupilCalculation() {};
	ExitPupilCalculation(OpticalSystem_LLT OptSys) :

		mOpticalSystem(OptSys)
	{
		mPosSurfaceAfterStop = calcPosSurAfterStop();
		mSepSurfaceAfterStop = calcSepSurAfterStop();
		mFocalLengthAfterStop = calcFocalLengthAfterStop();
		mRadiusAfterStop = calcRadiusAfterStop();
		mSepSurfaceAndStop = calcSepSurAndStop();
		mSepSurAndImPlane = calcSepSurAndImPlane();
		mRefractivIndexesAfterStop = calcRefractivIndexesAfterStop();
		mDiameterOfApertureStop = calcDiameterAperture();
		mSystemMatrix = calcSystemMatrix();
		mEFL = calcEFL();
		mPP = calcPrincPlanOptSys();
		mEXPP = calcExitPupilPost();
		mEXPD = calcDiameterExitPupil();
	};
	~ExitPupilCalculation() {};

	// get the position of all surfaces after the stop
	std::vector<real> getPosSurAfterStop() const&;
	// calculate the position of all surfaces after the stop
	std::vector<real> calcPosSurAfterStop();
	// calculate the separation of all surfaces after the stop
	std::vector<real> calcSepSurAfterStop();
	// calculate the separation of 1st surfaces and the stop
	real calcSepSurAndStop();
	// calculate the separation oflast surface and image plane
	real calcSepSurAndImPlane();
	// get the focal length of all surfaces after the stop
	std::vector<real> getFocalLengthAfterStop() const&;
	// calculate the focal length of all surfaces after the stop
	std::vector<real> calcFocalLengthAfterStop();
	// get the radius of all surfaces after the stop
	std::vector<real> getRadiusAfterStop() const&;
	// calculate the radius of all surfaces after the stop
	std::vector<real> ExitPupilCalculation::calcRadiusAfterStop();
	// get all refractive indexes
	std::vector<real> getRefractivIndexesAfterStop() const&;
	// calculate all refractive indexes
	std::vector<real> calcRefractivIndexesAfterStop();
	// get aperture size
	real getDiameterAperture() const&;
	// calculate aperture size
	real calcDiameterAperture();

	// calculate the system matrix
	std::vector<real> calcSystemMatrix();
	// calculate the EFL ot the optical system
	real calcEFL();
	// calculat the global principal plan of the optical syste
	real calcPrincPlanOptSys();
	//calculate the exit Pupil position
	real calcExitPupilPost();
	// calculate the diameter of the exit pupil of the optical system
	real calcDiameterExitPupil();
	

private:

	OpticalSystem_LLT mOpticalSystem;

	std::vector<real> mPosSurfaceAfterStop;
	std::vector<real> mSepSurfaceAfterStop;
	real mSepSurfaceAndStop;
	real mSepSurAndImPlane;
	std::vector<real> mFocalLengthAfterStop;
	std::vector<real> mRadiusAfterStop;
	std::vector<real> mRefractivIndexesAfterStop;
	real mDiameterOfApertureStop;
	std::vector<real> mSystemMatrix;
	real mEFL;
	real mPP;
	real mEXPP;
	real mEXPD;
};

