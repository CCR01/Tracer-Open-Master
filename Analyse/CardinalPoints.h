#pragma once
#include "..\LowLevelTracing\OpticalSystem_LLT.h"

class CardinalPoints
{
public:
	CardinalPoints() {};
	CardinalPoints(OpticalSystem_LLT OptSys) :

		mOpticalSystem_LLT(OptSys)
	{
		checkForApertureStopInOptSys();
		mPosSurfaceAfterStop = calcPosSurAfterStop();
		mSepSurfaceAfterStop = calcSepSurAfterStop();
		mFocalLengthAfterStop = calcFocalLengthAfterStop();
		mRadiusAfterStop = calcRadiusAfterStop();
		mAllRadius = calcAllRadius();
		mSepSurfaceAndStop = calcSepSurAndStop();
		mSepObjandSurface = calcSepObjandSurface();
		mSepSurAndImPlane = calcSepSurAndImPlane();
		AllmSepSurface = calcAllSepSur();
		mRefractivIndexesAfterStop = calcRefractivIndexesAfterStop();
		AllmRefractivIndexes = calcAllRefractivIndexes();
		mDiameterOfApertureStop = calcDiameterAperture();
		mSystemMatrix = calcSystemMatrix();
		mAllSystemMatrix = calcAllSystemMatrix();

		mEFL = calcEFL();
		mPP = calcPrincPlanOptSys();
		mAntiPP = calcAntiPrincPlanOptSys();
		mEXPP_accordingToLastSurface = calcExitPupilPost();
		mEXPD = calcDiameterExitPupil();
		mMag = calcMagnification();
		mEXPP_inGlobalCoordinatSystem = calcPosEXXPglobalCoordi();
	};
	~CardinalPoints() {};

	// check if there is an aperture stop in the optical system
	void checkForApertureStopInOptSys();

	// get the position of all surfaces after the stop
	std::vector<real> getPosSurAfterStop() const&;
	// calculate the position of all surfaces after the stop
	std::vector<real> calcPosSurAfterStop();
	// calculate the separation of all surfaces after the stop
	std::vector<real> calcSepSurAfterStop();
	// calculate the separation of 1st surfaces and the stop
	real calcSepSurAndStop();
	//calculate distance between object plane and first surface
	real calcSepObjandSurface();
	// calculate the separation oflast surface and image plane
	real calcSepSurAndImPlane();
	// get the focal length of all surfaces after the stop
	std::vector<real> getFocalLengthAfterStop() const&;
	// calculate the focal length of all surfaces after the stop
	std::vector<real> calcFocalLengthAfterStop();
	// get the radius of all surfaces after the stop
	std::vector<real> getRadiusAfterStop() const&;
	// calculate the radius of all surfaces after the stop
	std::vector<real> CardinalPoints::calcRadiusAfterStop();
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
	// calculat the global anti principal plan of the optical syste
	real CardinalPoints::calcAntiPrincPlanOptSys();
	real calcExitPupilPost();
	// calculate the diameter of the exit pupil of the optical system
	real calcDiameterExitPupil();
	//calc the magnification of system
	real calcMagnification();

	// calc pos exit pupil gloabl coordinates
	real calcPosEXXPglobalCoordi();

	// get the EFL
	real getEFL();
	// get position principal plain
	real getPrincipaPlan();
	// get ecit pupil position
	real getExitPupilPosition_lastSurface();
	// get ecit pupil position
	real getExitPupilPosition_globalCoori();
	// get EcitPupilDiameter
	real getExitPupilDiameter();
	// get magnification of system
	real getMagnification();
	// get anti principal plane
	real getAntiPP();

	//********************************************
	std::vector<real> calcAllRadius();
	std::vector<real> calcAllRefractivIndexes();
	std::vector<real> calcAllSepSur();
	std::vector<real> calcAllSystemMatrix();




private:

	OpticalSystem_LLT mOpticalSystem_LLT;

	std::vector<real> mPosSurfaceAfterStop;
	std::vector<real> mSepSurfaceAfterStop;
	real mSepSurfaceAndStop;
	real mSepObjandSurface;
	real mSepSurAndImPlane;
	std::vector<real> mFocalLengthAfterStop;
	std::vector<real> mRadiusAfterStop;
	std::vector<real> mRefractivIndexesAfterStop;
	real mDiameterOfApertureStop;
	std::vector<real> mSystemMatrix;
	real mEFL;
	real mPP;
	real mAntiPP;
	real mEXPP_accordingToLastSurface;
	real mEXPP_inGlobalCoordinatSystem;
	real mEXPD;
	real mMag;
	//******************************************************
	std::vector<real> mAllRadius;
	std::vector<double> AllmRefractivIndexes;
	std::vector<double> AllmSepSurface;
	std::vector<real> mAllSystemMatrix;

};

