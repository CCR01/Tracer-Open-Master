#pragma once
#include "..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"

class CardinalPoints
{
public:
	CardinalPoints() { loadAndResizeParameters(); };
	CardinalPoints(OpticalSystem_LLT OptSys) :

		mOpticalSystem_LLT(OptSys)
	{
		loadAndResizeParameters();
		calcSystemMatrix();

		mEFL = calcEFL();
		mPP = calcPrincPlanOptSys();
		mAntiPP = calcAntiPrincPlanOptSys();
		mEXPP_accordingToLastSurface = calcExitPupilPost();
		mEXPD = calcDiameterExitPupil();
		mMag = calcMagnification();
		mEXPP_inGlobalCoordinatSystem = calcPosEXXPglobalCoordi();
	};
	~CardinalPoints() {};

	void loadAndResizeParameters();
	void calcSystemMatrix();

	// calculate the separation of all surfaces after the stop
	void calcSepSurAfterStop();
	// calculate the separation of 1st surfaces and the stop
	void calcSepSurAndStop();
	//calculate distance between object plane and first surface
	void calcSepObjandSurface();
	// calculate the separation oflast surface and image plane
	void calcSepSurAndImPlane();
	// get the radius of all surfaces after the stop
	std::vector<real> getRadiusAfterStop() const;
	// calculate the radius of all surfaces after the stop
	void calcRadiusAfterStop();
	// get all refractive indexes
	std::vector<real> getRefractivIndexesAfterStop() const;
	// calculate all refractive indexes
	void calcRefractivIndexesAfterStop();
	// get aperture size
	real getDiameterAperture() const;
	// calculate aperture size
	void calcDiameterAperture();

	// calculate the system matrix
	void calcSystemMatrixAfterStop();
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
	void calcAllRadius();
	void calcAllRefractivIndexes();
	void calcAllSepSur();
	void calcAllSystemMatrix();




private:

	OpticalSystem_LLT mOpticalSystem_LLT{};


	std::vector<real> mSepSurfaceAfterStop{};
	std::vector<real> mALLSepSurfaceStop{};
	real mSepSurfaceAndStop{};
	real mSepObjandSurface{};
	real mSepSurAndImPlane{};

	std::vector<real> mRadiusAfterStop{};
	std::vector<real> mRefractivIndexesAfterStop{};
	real mDiameterOfApertureStop{};
	std::vector<real> mSystemMatrixAfterStop{};
	real mEFL{};
	real mPP{};
	real mAntiPP{};
	real mEXPP_accordingToLastSurface{};
	real mEXPP_inGlobalCoordinatSystem{};
	real mEXPD{};
	real mMag{};
	//******************************************************
	std::vector<real> mAllRadius{};
	std::vector<double> AllmRefractivIndexes{};
	std::vector<double> AllmSepSurface{};
	std::vector<real> mAllSystemMatrix{};

	// important parameters
	unsigned int mSizeOfOpt{};
	unsigned int mSizeOfOptSysMinOne{};
	unsigned int mSizeOfOptSysMinTwo{};
	unsigned int mSizeAfterStop{};
	std::vector<PosAndIntsectionSurfaceStruct> mPosAndInteraSurfaceVector;
	ApertureStop_LLT mApertureStop;
	unsigned int mPositionApertureStop;


};

