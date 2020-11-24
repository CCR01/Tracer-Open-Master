#pragma once
#include "..\LowLevelTracing\ImportantStructures.h"
#include "..\LowLevelTracing\Math_LLT.h"
#include "..\LowLevelTracing\OpticalSystem_LLT.h"

#include <opencv2/core/core.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <math.h>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <complex>
#include <typeinfo>
//#include "D:\Tracer-Master-Open-Respos\Tracer-Open-Master\opencv\include\opencv2\plot.hpp"


#include "..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"



enum class posExitPupil {exitPupil_Left_ImaSurface, exitPupil_Right_ImaSurface};

struct PosX_PosY_Val_tureVal
{
public:
	// pos X
	void setPos_X(unsigned int posX);
	unsigned int getPos_X();
	// pos Y
	void setPos_Y(unsigned int posY);
	unsigned int getPos_Y();
	// value
	void setVal(real val);
	real getVal();
	// true value
	void setTrueVal(bool trueVal);
	bool getTrueVal();

private:
	unsigned int mPosX{};
	unsigned int mPosY{};
	real mVal{};
	bool mTrueVal{};
};

struct PX_PY_MX_MY
{
public:
	void resizeAllvector(unsigned int size);
	// PX
	void setPX_ChiefRay_atPos_i(real px, unsigned int pos);
	real getPX_ChiefRay_atPos_i(unsigned int pos);
	std::vector<real> getAll_PX_cheifRay() const;
	// PY
	void setPY_ChiefRay_atPos_i(real py, unsigned int pos);
	real getPY_ChiefRay_atPos_i(unsigned int pos);
	std::vector<real> getAll_PY_cheifRay() const;
	//// OPD
	//void setOPDatPos_i(real opd, unsigned int pos);
	//real getOPDatPos_i(unsigned int pos);
	//std::vector<real> getAll_OPD() const;
	// MX
	void setMXatPos_i(unsigned int MX, unsigned int pos);
	unsigned int getMXatPos_i(unsigned int pos);
	std::vector<unsigned int> getAll_MX() const;
	// MY
	void setMYatPos_i(unsigned int MY, unsigned int pos);
	unsigned int getMYatPos_i(unsigned int pos);
	std::vector<unsigned int> getAll_MY() const;

	void calcAllPositionRegardsToChiefRay(const std::vector<VectorStructR3>& interPointsRefSphere, unsigned int sizeMatrix);

private:
	std::vector<real> mPX_CheifRay;
	std::vector<real> mPY_CheifRay;
	//std::vector<real> mOPD;
	std::vector<unsigned int> mMX;
	std::vector<unsigned int> mMY;
};

class OPD
{
public:
	static const int  upscaledMatrixSize = 128;

	OPD();
	OPD(/*optical system*/ OpticalSystem_LLT optSys, /*aimed light ray*/ std::vector<LightRayStruct> aimedLightRay, /*obj inf*/objectPoint_inf_obj inf_obj, /*size matrix with OPDs*/ unsigned int sizeMatrix);

	// to calculate the OPD in X and Y direction
	OPD(/*exit pupil*/ std::shared_ptr<SurfaceIntersectionRay_LLT> exitPupil,  /*optical system*/ OpticalSystem_LLT optSys,
		std::vector<LightRayStruct> lightRayAlong_X, std::vector<LightRayStruct> lightRayAlong_Y, LightRayStruct chiefLightRay);
	~OPD();


	//***
	// calculate OPD for single Ray
	real OPD_singelRay_obj(OpticalSystem_LLT optSys, VectorStructR3 startPointRay, real pupilPositionX, real pupilPositionY, Light_LLT light);
	real calculateOPD_exitPupilBehindOptSys(OpticalSystem_LLT optSys, real posExitPupil_Z_global, VectorStructR3 startPointRay, real pupilPositionX, real pupilPositionY, Light_LLT light);
	real calculateOPD_exitPupilLeftFromImaSurface(OpticalSystem_LLT optSys, real posExitPupil_Z_global, VectorStructR3 startPointRay, real pupilPositionX, real pupilPositionY, Light_LLT light);

	// calculate position of exit pupil in optical system according to z direction
	unsigned int calcPosExPupil_Z(OpticalSystem_LLT optSys, real position_Z_exitPupil);

	// calculate refractiv index start media
	real calcRefractivIndexStartMedia(OpticalSystem_LLT optSys);

	// calculate position of exit pupil in optical system according to z direction
	unsigned int calcPosExPupil_Z();

	/// ***
	// calculate global OPD
	void calcGlobalOPD_new();

	
	void calcGlobalOPD_new_Right_SideOfImaSurface(real positionExitPupil_global);
	void buildOpticalSystemWithExitPupilPlan_rightSide(real positionExitPupil_global);
	void buildOpticalSystemWithReferenceSphereAtExitPupil_rightSide(real radiusRefSphere, VectorStructR3 pointRefSphere, VectorStructR3 directionRefSphere);


	void calcGlobalOPD_new_LEFT_SideOfImaSurface(real positionExitPupil_globa);


	LightRayStruct getWantedLightRay();
	// ***

	// bilinear interpolation to fill holes in OPD matrix
	void bilinearInterpolToFillHolesInOPDmatrix();
	void holizontal_bilinear_Interpolation();
	void horizontalInterpolation_oneStep();
	void vertical_bilinear_Interpolation();
	void verticalInterpolation_oneStep();

	// check OPD value in the middle of the matrix
	void checkOPDValueInTheMiddle();
	void setMiddlePointToZero();
	// look negativ x direction
	void lookNegativ_X_multiSteps(unsigned int posX, unsigned int posY);
	void lookNegativ_X_oneStep(unsigned int posX, unsigned int posY);
	// look positiv x direction
	void lookPositiv_X_multiSteps(unsigned int posX, unsigned int posY);
	void lookPositive_X_oneStep(unsigned int posX, unsigned int posY);
	// look negativ y direction
	void lookNegativ_Y_multiSteps(unsigned int posX, unsigned int posY);
	void lookNegative_Y_oneStep(unsigned int posX, unsigned int posY);
	// look positiv y direction
	void lookPositiv_Y_multiSteps(unsigned int posX, unsigned int posY);
	void lookPositive_Y_oneStep(unsigned int posX, unsigned int posY);

	void setGlobalOPD(cv::Mat globalOPD);


	// calc OPD in X direction
	std::vector<cv::Point2d> calcOPD_X();

	// calc OPD in Y direction
	std::vector<cv::Point2d> calcOPD_Y();

	// calc reference distance for referenc sphere
	real calcRefDisForRefSphere();

	// calc reference distance to calculat OPD
	real calcRefDisForOPD();

	// get position of exit pupil in optical system
	unsigned int getPosExPupilInOptSys();

	// get points OPD in Y direction
	std::vector<cv::Point2d> getPointsOPD_Y();

	// get points in X direction
	std::vector<cv::Point2d> getPointsOPD_X();

	// get OPD X in std::vector
	std::vector<real> getOPD_X_inVec();

	// get OPD Y in std::vector
	std::vector<real> getOPD_Y_inVec();

	// get reference point
	VectorStructR3 getRefPoints();


	// get global OPD
	cv::Mat getGlobalOPD_deepCopy();

	// get upsampled global OPD
	cv::Mat getUpsampledGlobalOPD_deepCopy();


	//plot function for MTF
	//int OPD::PlotGraph(cv::Mat & data);


	

	// get vector with all calculated global OPD --> just for debugging
	std::vector<real> getVecWithAllCalcGlobalOPD();

	// get the PSF
	cv::Mat getPSF();

	//get the light
	LightRayStruct getChiefLightRay();

	// calc all OPD
	void calcAllOPDs(real referenceDistance, const std::vector<real>& allDistances);

	// save all OPDS in matrix
	void saveAllOPDsInMatrix(std::vector<unsigned int> MX, std::vector<unsigned int> MY);



	// optical system
	void setOpticalSystemLLT(OpticalSystem_LLT optSysLLT);
	OpticalSystem_LLT getOpticalSystemLLT();
	// aimed light ray
	void setAimedLightRays(std::vector<LightRayStruct> aimedLightRay);
	std::vector<LightRayStruct> getAimedLightRays();
	// obj or inf
	void setInfOrObj(objectPoint_inf_obj inf_obj);
	objectPoint_inf_obj getInfOrObj();
	// size matrix to save
	void setSizeMatrixToSave(unsigned int sizeMatrixToSave);
	unsigned int getSizeMatrixToSave();



private:

	LightRayStruct mWantedLightRay;
	std::vector<LightRayStruct> mAimedLightRay{};
	OpticalSystem_LLT mOptSys{};
	OpticalSystem_LLT mOptSysWithExitPupilPlan{};
	OpticalSystem_LLT mOptSysWithReferenceSphere{};
	objectPoint_inf_obj mInf_obj{};
	std::vector<real> mAllOPDs{};
	cv::Mat mGlobalOPD{};
	cv::Mat mGlobalOPD_upsampled{};
	unsigned int mFilledPoints_horizontal{};
	unsigned int mFilledPoints_vertical{};
	unsigned int mSizeMatrix{};

	VectorStructR3 mPosObject;
	std::shared_ptr<SurfaceIntersectionRay_LLT> mExitPupil;
	
	
	VectorStructR3 mChiefRayAtImage;
	VectorStructR3 mChiefRayAtExitPupil;
	std::vector<LightRayStruct> mLightRayX;
	std::vector<LightRayStruct> mLightRayY;
	LightRayStruct mChiefLightRay;

	

	unsigned int mPosImageSurface;
	unsigned int mPosExPupilInOptSys;
	real mTotalStepsToImageSurfaceRef;
	real mRadiusRefSphere;
	real mRefDistance;
	SphericalSurface_LLT mRefSphere;
	std::vector<cv::Point2d> mOPD_X;
	std::vector<cv::Point2d> mOPD_Y;
	VectorStructR3 mRefPoint;

	DoNothingInteraction_LLT mDoNothingInter;
	std::shared_ptr<InteractionRay_LLT> mDoNothingInteraction_ptr;
	//std::shared_ptr<InteractionRay_LLT> refractionRay_LLT(new RefractedRay_LLT(*this));
	unsigned numImageSurfaceWithoutExitPupil;

	std::vector<LightRayStruct> mLightRayFillAperturStop;

	std::vector<real> mVecWithAllCalcGlobalOPD;
	
	unsigned int mMaxStepToLook;
	real mToleranceToCheckZero;
	PosX_PosY_Val_tureVal mLook_Pos_X;
	PosX_PosY_Val_tureVal mLook_Neg_X_multiSteps;
	PosX_PosY_Val_tureVal mLook_Pos_Y;
	PosX_PosY_Val_tureVal mLook_Neg_Y;

	// look one step
	bool mLook_Pos_X_oneStep_trueVal;
	bool mLook_Neg_X_oneStep_trueVal;
	bool mLook_Pos_Y_oneStep_trueVal;
	bool mLook_Neg_Y_oneStep_trueVal;

	real mValOneStep_posX;
	real mValOneStep_negX;
	real mValOneStep_posY;
	real mValOneStep_negY;

	int mScaling;

	cv::Mat mHuygenPSF;


};

