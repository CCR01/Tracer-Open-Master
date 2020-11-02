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


	// to calculate the global OPD
	OPD(/*exit pupil*/ std::shared_ptr<SurfaceIntersectionRay_LLT> exitPupil,  /*optical system*/ OpticalSystem_LLT optSys,
		/*fill apertur stop with light ray*/ std::vector<LightRayStruct> lightRayFillAperturStop, /*chief ray*/ LightRayStruct chiefLightRay, /*Scalling*/int scalling);

	// to calculate the OPD in X and Y direction
	OPD(/*exit pupil*/ std::shared_ptr<SurfaceIntersectionRay_LLT> exitPupil,  /*optical system*/ OpticalSystem_LLT optSys,
		std::vector<LightRayStruct> lightRayAlong_X, std::vector<LightRayStruct> lightRayAlong_Y, LightRayStruct chiefLightRay);
	~OPD();

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
	void calcGlobalOPD_new(unsigned int sizeMatrix);

	
	void calcGlobalOPD_new_Right_SideOfImaSurface(real positionExitPupil_global, unsigned int sizeMatrix);
	void buildOpticalSystemWithExitPupilPlan(real positionExitPupil_global);
	void buildOpticalSystemWithReferenceSphereAtExitPupil(real radiusRefSphere, VectorStructR3 pointRefSphere, VectorStructR3 directionRefSphere);


	void calcGlobalOPD_new_LEFT_SideOfImaSurface();
	// ***



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
	cv::Mat getGlobalOPD();

	// bilinear interpolator
	double bilinear_interpolator(double fxfy, double fxcy, double cxfy, double cxcy, int fx, int cx, int fy, int cy, double actualX, double actualY);

	//upsampling OPD
	cv::Mat calcUpscaledGlobalOPD();

	//dowlnsampling for PSF
	cv::Mat calcSampledOPDMatrixforPSF();

	//fuction to calculate FFT
	cv::Mat OPD::calcFFT(cv::Mat Matrix);




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
	void saveAllOPDsInMatrix(std::vector<unsigned int> MX, std::vector<unsigned int> MY, unsigned int size);

private:

	std::vector<LightRayStruct> mAimedLightRay{};
	OpticalSystem_LLT mOptSys{};
	OpticalSystem_LLT mOptSysWithExitPupilPlan{};
	OpticalSystem_LLT mOptSysWithReferenceSphere{};
	objectPoint_inf_obj mInf_obj{};
	std::vector<real> mAllOPDs{};
	cv::Mat mGlobalOPD{};
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
	
	

	int mScaling;

	cv::Mat mHuygenPSF;

};

