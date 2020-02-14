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

#include "CardinalPoints.h"




// TODO: es wäre bestimmt hilfreich, wenn die Größe und Lage der Ein- und Austrittspupille direkt im optischen System gespeichert wird
// --> dann muss man das hier nicht als Parameter übergeben!

class OPD
{
public:
	static const int  upscaledMatrixSize = 128;
	OPD() {};
	// to calculate the global OPD
	OPD(/*exit pupil*/ std::shared_ptr<SurfaceIntersectionRay_LLT> exitPupil,  /*optical system*/ OpticalSystem_LLT optSys,
		/*fill apertur stop with light ray*/ std::vector<LightRayStruct> lightRayFillAperturStop, /*chief ray*/ LightRayStruct chiefLightRay, /*Scalling*/int scalling) :
		mExitPupil(exitPupil),
		mOptSys(optSys),
		mLightRayFillAperturStop(lightRayFillAperturStop),
		mChiefLightRay(chiefLightRay),
		mScaling(scalling)
	{

		mPosObject = mChiefLightRay.getRay_LLT().getOriginRay();
		mPosImageSurface = mOptSys.getNumberOfSurfaces();
		mPosExPupilInOptSys = calcPosExPupil_Z();
		//***
		mOptSysWithExitPupil = mOptSys;
		mOptSysWithExitPupil.fillInSurfaceAndInteracAtPos_i(mPosExPupilInOptSys, mExitPupil, mDoNothingInteraction_ptr);
		//***
		mRadiusRefSphere = calcRefDisForRefSphere();
		mRefDistance = calcRefDisForOPD();

		SphericalSurface_LLT refSphere(/*radius*/mRadiusRefSphere, /*semiHeight*/mExitPupil->getSemiHeight() / 2, /*Apex of the sphere*/mChiefRayAtExitPupil,/*Direction*/mChiefRayAtImage - mChiefRayAtExitPupil, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
		mRefSphere = refSphere;

		mGlobalOPD = calcGlobalOPD();
		mUpscaledGlobalOPD = calcUpscaledGlobalOPD();

		mSampledOPDMatrixforPSF = calcSampledOPDMatrixforPSF();

		mCutoffFreq = calcCutoffFreq();

		mPSF = calcPSF();

		mMTF = calcMTF();

		mHuygenPSF = calcHuygenPSF();



	};

	// to calculate the OPD in X and Y direction
	OPD(/*exit pupil*/ std::shared_ptr<SurfaceIntersectionRay_LLT> exitPupil,  /*optical system*/ OpticalSystem_LLT optSys,
		std::vector<LightRayStruct> lightRayAlong_X, std::vector<LightRayStruct> lightRayAlong_Y, LightRayStruct chiefLightRay) :
		mExitPupil(exitPupil),
		mOptSys(optSys),
		mLightRayX(lightRayAlong_X),
		mLightRayY(lightRayAlong_Y),
		mChiefLightRay(chiefLightRay)
	{
		mPosObject = mChiefLightRay.getRay_LLT().getOriginRay();
		mPosImageSurface = mOptSys.getNumberOfSurfaces();
		mPosExPupilInOptSys = calcPosExPupil_Z();
		//***
		mOptSysWithExitPupil = mOptSys;
		mOptSysWithExitPupil.fillInSurfaceAndInteracAtPos_i(mPosExPupilInOptSys, mExitPupil, mDoNothingInteraction_ptr);
		//***
		mRadiusRefSphere = calcRefDisForRefSphere();
		mRefDistance = calcRefDisForOPD();


		SphericalSurface_LLT refSphere(/*radius*/mRadiusRefSphere, /*semiHeight*/mExitPupil->getSemiHeight() / 2, /*Apex of the sphere*/mChiefRayAtExitPupil,/*Direction*/mChiefRayAtImage - mChiefRayAtExitPupil, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
		mRefSphere = refSphere;
		mOPD_X = calcOPD_X();
		mOPD_Y = calcOPD_Y();
	};
	~OPD() {};

	// calculate position of exit pupil in optical system according to z direction
	unsigned int calcPosExPupil_Z();

	// calc OPD in X direction
	std::vector<cv::Point2d> calcOPD_X();

	// calc OPD in Y direction
	std::vector<cv::Point2d> calcOPD_Y();

	// calc global optical path difference 
	cv::Mat calcGlobalOPD();

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

	//calculating PSF
	cv::Mat calcPSF();

	//calculate the cut off frequency
	double OPD::calcCutoffFreq();

	//plot function for MTF
	//int OPD::PlotGraph(cv::Mat & data);

	//calculate MTF
	cv::Mat OPD::calcMTF();

	// calcultat cardinal points
	CardinalPoints calculateCardinalPoints();

	//Calculate huygen's integral
	cv::Mat OPD::calcHuygenIntegral(cv::Mat PupilFunction, double waveVector, double prop_distance, double sampling_in);

	//calculate Huygens PSF
	cv::Mat OPD::calcHuygenPSF();

	// export a cv::mat to excel
	void exportCV_MatToExcel(cv::Mat matToExport, std::string locationAndfilename);

	// get vector with all calculated global OPD --> just for debugging
	std::vector<real> getVecWithAllCalcGlobalOPD();

	// export the global OPD as an .csv file
	void exportGloblaOPD(std::string const& directionAndFilename);

	// get the PSF
	cv::Mat getPSF();

private:
	VectorStructR3 mPosObject;
	std::shared_ptr<SurfaceIntersectionRay_LLT> mExitPupil;
	OpticalSystem_LLT mOptSys;
	OpticalSystem_LLT mOptSysWithExitPupil;
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

	DoNothingInteraction_LLT doNothingInter;
	std::shared_ptr<InteractionRay_LLT> mDoNothingInteraction_ptr = doNothingInter.clone();
	//std::shared_ptr<InteractionRay_LLT> refractionRay_LLT(new RefractedRay_LLT(*this));
	unsigned numImageSurfaceWithoutExitPupil;

	std::vector<LightRayStruct> mLightRayFillAperturStop;

	cv::Mat mGlobalOPD;

	cv::Mat mUpscaledGlobalOPD;

	cv::Mat mSampledOPDMatrixforPSF;

	double mCutoffFreq;

	cv::Mat mPSF;

	cv::Mat mMTF;

	CardinalPoints mCardinalPoints;

	cv::Mat mHuygenPSF;

	std::vector<real> mVecWithAllCalcGlobalOPD; // we need that for debugging

	int mScaling;

};

