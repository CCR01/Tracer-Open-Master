#pragma once
#include "..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"



class CardinalPoints
{
public:
	CardinalPoints();
	CardinalPoints(OpticalSystem_LLT OptSys, objectPoint_inf_obj objPoint_inf_obj);
	CardinalPoints(OpticalSystemElement optSysEle, real primWavelenght, objectPoint_inf_obj objPoint_inf_obj);
	~CardinalPoints();

	// calc all cardinal points super fct
	void calcAllCardinalPointsSuperFct(OpticalSystemElement optSysEle, real primWavelength, objectPoint_inf_obj objPoint_inf_obj);

	void loadAndResizeParameters();
	void calcSystemMatrix();

	void setObjectPoint(objectPoint_inf_obj point_inf_obj);

	// calculate the separation oflast surface and image plane
	void calcSepSurAndImPlane();
	// calculate aperture size
	void calcDiameterAperture();

	void calcAllRadius();
	void calcAllRefractivIndexes();
	void calcAllSepSur();
	void calcAllSystemMatrix();

	std::vector<real> calcVecTimesVec(std::vector<real> const vec1, std::vector<real> const vec2);

	//********************************************
	// calculate the EFL ot the optical system
	real calcEFL();
	// calculat the  principal plan object
	real calcPP_obj();
	// calculat the  principal plan image
	real calcPP_ima();
	// calculate position of exit pupil according to last surface
	real calcEXPP_lastSurface();
	// calc pos exit pupil gloabl coordinates
	real calcEXPP_globalCoordi();
	// calculate the diameter of the exit pupil of the optical system
	real calcEXPD();
	//calc the magnification of system
	real calcMagnification();
	// calc numerical aperture
	real calcNA_objSpac();
	// calc entrance pupil position according to first surface
	real calcENPP_firstSurface();
	// calc entrance pupil position according to global coord system
	real calcENPP_globalCoordi();
	// calc entrance pupil diameter 
	real calcENPD();
	// calc f number
	real calcFnumberImaSpace();
	// calc NA image space
	real calcNA_imaSpace();
	// calc workinf f number 
	real calcWFNO();
	//********************************************
	// get the EFL
	real getEFL();
	// get principal plane obj
	real getPP_obj();
	// get exit pupil position
	real getEXPP_lastSurface();
	// get exit pupil position
	real getEXPP_globalCoori();
	// get EcitPupilDiameter
	real getEXPD();
	// get magnification of system
	real getMagnification();
	// get principal plane ima
	real getPP_ima();
	// get numerical Aperture calc
	real getNA_objSpace();
	// entrace pupil position first surface
	real getENPP_firstSurface();
	// entrance pupil position global coordi
	real getENPP_globalCoodi();
	// entrance pupil diameter
	real getENPD();
	// get f number
	real getF_num_imaSpace();
	// NA image space
	real getNA_imaSpace();
	// working f number
	real getWorkingFnumber();
	//********************************************




private:

	OpticalSystem_LLT mOpticalSystem_LLT{};
	OpticalSystemElement mOpticalSystem_Ele{};
	real mPrimWavelength{};

	objectPoint_inf_obj mObjectPoint_inf_obj{};

	std::vector<real> mSystemMatrix_vec{};

	std::vector<real> mS_beforeAS_rot{};
	std::vector<real> mS_dash_beforeAS_rot{};

	std::vector<real> mS_afterAS{};
	std::vector<real> mS_dash_afterAS{};

	real mSepSurAndImPlane{};
	real mDiameterOfApertureStop{};

	VectorStructR3 mStartPointRayToCalcNA_obj{};

	//******************************************************
	real mEFL{};
	real mPP_obj{};
	real mPP_ima{};
	real mEXPP_lastSurface{};
	real mEXPP_inGlobalCoordi{};
	real mEXPD{};
	real mMag{};
	real mNA_objSpac{};
	real mENPP_inGlobalCoodi{};
	real mENPP_firstSurface{};
	real mENPD{};
	real mF_number_imaSpace{};
	real mNA_imaSpace{};
	real mWFNO{};
	//******************************************************
	std::vector<real> mAllRadius{};
	std::vector<double> mAllRefractivIndexes{};
	std::vector<double> mAllRefractivIndexes_dash{};
	std::vector<double> mAllThickness_vec{};
	std::vector<real> mAllSystemMatrix{};

	// important parameters
	unsigned int mSizeOfOpt{};
	int mSizeOfOptSysMinOne{};
	int mSizeOfOptSysMinTwo{};
	int mSizeAfterStop{};
	std::vector<PosAndIntsectionSurfaceStruct> mPosAndInteraSurfaceVector{};
	ApertureStop_LLT mApertureStop{};
	unsigned int mPositionApertureStop{};

	// parameters before aperture stop
	std::vector<real> mDistances_vec_BAS_rot{};
	std::vector<real> mRadii_vec_BAS_rot{};
	std::vector<real> mRefIndex_vec_BAS_rot{};
	std::vector<real> mRefIndex_vec_dash_BAS_rot{};
	std::vector<real> mF_dash_vec_BAS_rot{};
};

