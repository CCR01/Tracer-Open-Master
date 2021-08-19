
//#include "types.hpp"

#include "OpticalPathDifference.h"
#include "..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\SequentialRayTracing\SequentialRayTracer.h"

#include "..\oftenUseNamespace\oftenUseNamespace.h"

#include "CardinalPoints.h"
#include "..\RayAiming\RayAiming.h"

#include <cmath>
#include <limits>

#include <fstream>
#include <stdlib.h>

#include "..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\LowLevelTracing\Interaction\TraceLightRayBack.h"

#include "..\oftenUseNamespace\oftenUseNamespace.h"

loadParaOPD::loadParaOPD() {};
loadParaOPD::~loadParaOPD() {};

// tolerance for ray aiming
void loadParaOPD::setToleranceForRayAiming(real tolerance)
{
	mToleranceForRayAiming = tolerance;
}
real loadParaOPD::getToleranceForRayAiming()
{
	return mToleranceForRayAiming;
}

// is first aimed ray chief ray
void loadParaOPD::setFirstAimedRayIsChiefRay(bool firstAimedRayIsChiefRay)
{
	mFirstAimedRayIsChiefRay = firstAimedRayIsChiefRay;
}
bool loadParaOPD::getFirstAimedRayIsChiefRay()
{
	return mFirstAimedRayIsChiefRay;
}

// max iteration biliniear interpolation
void loadParaOPD::setMaxIterationsBilinInterpol(unsigned int maxStepsBilinInter)
{
	mMaxIterationBilinInterpol = maxStepsBilinInter;
}
unsigned int loadParaOPD::getMaxIterationsBilinInterpol()
{
	return mMaxIterationBilinInterpol;
}

// factor for ray aiming if object is in inf.
void loadParaOPD::setFactorForRayAimingIfObjInInf(real factorObjInInf)
{
	mFactorRayAimingForObjInInf = factorObjInInf;
}
real loadParaOPD::getFactorForRayAimingIfObjInInf()
{
	return mFactorRayAimingForObjInInf;
}

// field angle chief ray
void loadParaOPD::setFieldAngleChiefRay_X(real fieldAngleChiefRay_X)
{
	mFieldAngleChiefRay_X = fieldAngleChiefRay_X;
}
real loadParaOPD::getFieldAngleChiefRay_X()
{
	return mFieldAngleChiefRay_X;
}
void loadParaOPD::setFieldAngleChiefRay_Y(real fieldAngleChiefRay_Y)
{
	mFieldAngleChiefRay_Y = fieldAngleChiefRay_Y;
}
real loadParaOPD::getFieldAngleChiefRay_Y()
{
	return mFieldAngleChiefRay_Y;
}

// load default parameter
void loadParaOPD::loadDefaultParameter()
{
	mToleranceForRayAiming = 0.000001;
	mFirstAimedRayIsChiefRay = true;
	mMaxIterationBilinInterpol = 4;
	mFactorRayAimingForObjInInf = 0.000001;
}

void PX_PY_MX_MY::resizeAllvector(unsigned int size)
{
	mPX_ChiefRay.resize(size);
	mPY_ChiefRay.resize(size);
	//mOPD.resize(size);
	mMX.resize(size);
	mMY.resize(size);
}
// PX
void PX_PY_MX_MY::setPX_ChiefRay_atPos_i(real px, unsigned int pos)
{
	mPX_ChiefRay[pos] = px;
}
real PX_PY_MX_MY::getPX_ChiefRay_atPos_i(unsigned int pos)
{
	return mPX_ChiefRay[pos];
}
std::vector<real> PX_PY_MX_MY::getAll_PX_chiefRay() const
{
	return mPX_ChiefRay;
}
// PY
void PX_PY_MX_MY::setPY_ChiefRay_atPos_i(real py, unsigned int pos)
{
	mPY_ChiefRay[pos] = py;
}
real PX_PY_MX_MY::getPY_ChiefRay_atPos_i(unsigned int pos)
{
	return mPY_ChiefRay[pos];
}
std::vector<real> PX_PY_MX_MY::getAll_PY_chiefRay() const
{
	return mPY_ChiefRay;
}
//// OPD
//void PX_PY_MX_MY::setOPDatPos_i(real opd, unsigned int pos)
//{
//	mOPD[pos] = opd;
//}
//real PX_PY_MX_MY::getOPDatPos_i(unsigned int pos)
//{
//	return mOPD[pos];
//}
//std::vector<real> PX_PY_MX_MY::getAll_OPD() const
//{
//	return mOPD;
//}
// MX
void PX_PY_MX_MY::setMXatPos_i(unsigned int MX, unsigned int pos)
{
	mMX[pos] = MX;
}
unsigned int PX_PY_MX_MY::getMXatPos_i(unsigned int pos)
{
	return mMX[pos];
}
std::vector<unsigned int> PX_PY_MX_MY::getAll_MX() const
{
	return mMX;
}
// MY
void PX_PY_MX_MY::setMYatPos_i(unsigned int MY, unsigned int pos)
{
	mMY[pos] = MY;
}
unsigned int PX_PY_MX_MY::getMYatPos_i(unsigned int pos)
{
	return mMY[pos];
}
std::vector<unsigned int> PX_PY_MX_MY::getAll_MY() const
{
	return mMY;
}

void PX_PY_MX_MY::calcAllPositionRegardsToChiefRay(const std::vector<VectorStructR3>& interPointsRefSphere, unsigned int sizeMatrix)
{
	unsigned int size = interPointsRefSphere.size();


	// resize all vectors
	resizeAllvector(size);

	// first ray is allways the chief ray!
	real refPoint_X = interPointsRefSphere[0].getX();
	real refPoint_Y = interPointsRefSphere[0].getY();


	for (unsigned int i = 0; i < size; ++i)
	{
		//mOPD[i] = OPDs[i];
		mPX_ChiefRay[i] = interPointsRefSphere[i].getX() - refPoint_X;
		mPY_ChiefRay[i] = interPointsRefSphere[i].getY() - refPoint_Y;
	}

	real minX_val = Math::minValueOfVector(mPX_ChiefRay);
	real maxX_val = Math::maxValueOfVactor(mPX_ChiefRay);
	real minY_val = Math::minValueOfVector(mPY_ChiefRay);
	real maxY_val = Math::maxValueOfVactor(mPY_ChiefRay);

	// calcualte position in matrix 
	real tempPX_ChiefRay{};
	real tempPY_ChiefRay{};
	unsigned int tempPosMatrix_X{};
	unsigned int tempPosMatrix_Y{};
	unsigned int halfSizeMatrix = (sizeMatrix - 1) / 2;
	unsigned int middleMatrix_X = halfSizeMatrix;
	unsigned int middleMatrix_Y = halfSizeMatrix;
	for (unsigned int i = 0; i < size; ++i)
	{
		tempPX_ChiefRay = mPX_ChiefRay[i];
		tempPY_ChiefRay = mPY_ChiefRay[i];

		if (tempPX_ChiefRay >= 0.0 && tempPY_ChiefRay > 0.0)
		{
			tempPosMatrix_X = middleMatrix_X + std::floor((tempPX_ChiefRay / maxX_val) * halfSizeMatrix);
			tempPosMatrix_Y = middleMatrix_Y - std::floor((tempPY_ChiefRay / maxY_val) * halfSizeMatrix);
		}

		else if (tempPX_ChiefRay <= 0.0 && tempPY_ChiefRay > 0.0)
		{
			tempPosMatrix_X = middleMatrix_X - std::floor((tempPX_ChiefRay / minX_val) * halfSizeMatrix);
			tempPosMatrix_Y = middleMatrix_Y - std::floor((tempPY_ChiefRay / maxY_val) * halfSizeMatrix);
		}

		else if (tempPX_ChiefRay <= 0.0 && tempPY_ChiefRay < 0.0)
		{
			tempPosMatrix_X = middleMatrix_X - std::floor((tempPX_ChiefRay / minX_val) * halfSizeMatrix);
			tempPosMatrix_Y = middleMatrix_Y + std::floor((tempPY_ChiefRay / minY_val) * halfSizeMatrix);
		}

		else if (tempPX_ChiefRay >= 0.0 && tempPY_ChiefRay < 0.0)
		{
			tempPosMatrix_X = middleMatrix_X + std::floor((tempPX_ChiefRay / maxX_val) * halfSizeMatrix);
			tempPosMatrix_Y = middleMatrix_Y + std::floor((tempPY_ChiefRay / minY_val) * halfSizeMatrix);
		}

		else if (std::abs(tempPX_ChiefRay) < 0.000001 && std::abs(tempPY_ChiefRay) < 0.000001)
		{
			tempPosMatrix_X = middleMatrix_X;
			tempPosMatrix_Y = middleMatrix_Y;
		}

		// just for debugging
		//std::cout << "temp Pos MX: " << tempPosMatrix_X << std::endl;

		mMX[i] = tempPosMatrix_X;

		// just for debugging
		//std::cout << "temp Pos MY: " << tempPosMatrix_Y << std::endl;

		mMY[i] = tempPosMatrix_Y;

		// just for debugging
		//std::cout << "_____________" << std::endl;
	}
}


OPD::OPD() { mLoadParaOPD.loadDefaultParameter(); };

OPD::OPD(OpticalSystem_LLT optSys, std::vector<LightRayStruct> aimedLightRay, objectPoint_inf_obj inf_obj, /*size matrix with OPDs*/ unsigned int sizeMatrix) :
	mOptSys(optSys),
	mInf_obj(inf_obj),
	mAimedLightRay(aimedLightRay),
	mSizeMatrix(sizeMatrix)
	
{
	mLoadParaOPD.loadDefaultParameter();
};

OPD::OPD(/*optical system*/ OpticalSystem_LLT optSys, /*points in Aperture Stop*/ std::vector<VectorStructR3> pointsInAS, /*light*/ Light_LLT light, /*obj inf*/objectPoint_inf_obj inf_obj, /*size matrix with OPDs*/ unsigned int sizeMatrix) :
	mOptSys(optSys),
	mPointsInAS(pointsInAS),
	mLight(light),
	mInf_obj(inf_obj),
	mSizeMatrix(sizeMatrix)
{
	mLoadParaOPD.loadDefaultParameter();
	mLoadParaOPD.setFirstAimedRayIsChiefRay(false);
}

// to calculate the OPD in X and Y direction
OPD::OPD(/*exit pupil*/ std::shared_ptr<SurfaceIntersectionRay_LLT> exitPupil,  /*optical system*/ OpticalSystem_LLT optSys,
	std::vector<LightRayStruct> lightRayAlong_X, std::vector<LightRayStruct> lightRayAlong_Y, LightRayStruct chiefLightRay) :
	mExitPupil(exitPupil),
	mOptSys(optSys),
	mLightRayX(lightRayAlong_X),
	mLightRayY(lightRayAlong_Y),
	mChiefLightRay(chiefLightRay)
{
	mLoadParaOPD.loadDefaultParameter();

	mPosObject = mChiefLightRay.getRay_LLT().getOriginRay();
	mPosImageSurface = mOptSys.getNumberOfSurfaces();
	mPosExPupilInOptSys = calcPosExPupil_Z();
	//***
	mOptSysWithExitPupilPlan = mOptSys;
	mOptSysWithExitPupilPlan.fillInSurfaceAndInteracAtPos_i(mPosExPupilInOptSys, mExitPupil, mDoNothingInter.clone());
	//***
	mRadiusRefSphere = calcRefDisForRefSphere();
	mRefDistance = calcRefDisForOPD();

	SphericalSurface_LLT refSphere(/*radius*/mRadiusRefSphere, /*semiHeight*/mExitPupil->getSemiHeight() / 2, /*Apex of the sphere*/mChiefRayAtExitPupil,/*Direction*/mChiefRayAtImage - mChiefRayAtExitPupil, /*refIndexSideA*/1.0, /*refIndexSideB*/1.0);
	mRefSphere = refSphere;
	mOPD_X = calcOPD_X();
	mOPD_Y = calcOPD_Y();

};

OPD::~OPD() {};


// calculate OPD for single Ray
real OPD::OPD_singelRay_obj(OpticalSystem_LLT optSys, VectorStructR3 startPointRay, real pupilPositionX, real pupilPositionY, Light_LLT light)
{
	real returnOPD{};

	CardinalPoints carPoints(optSys, objectPoint_inf_obj::obj);
	real positionZ_exitPupil_global = carPoints.getEXPP_globalCoori();
	
	unsigned int sizeOptSys = optSys.getPosAndInteractingSurface().size();
	real positionZ_lastSurface = optSys.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getPoint().getZ();

	// position of exit pupil is on the - right side - of the image surface
	if (positionZ_exitPupil_global > positionZ_lastSurface)
	{
		returnOPD = calculateOPD_exitPupilBehindOptSys_obj(optSys, positionZ_exitPupil_global, startPointRay, pupilPositionX, pupilPositionY, light);
		
	}
	else
	{
		returnOPD = calculateOPD_exitPupilLeftFromImaSurface_obj(optSys, positionZ_exitPupil_global, startPointRay, pupilPositionX, pupilPositionY, light);
	}

	return returnOPD;
}

real OPD::OPD_singelRay_inf(OpticalSystem_LLT optSys, real fieldAngle_X, real fieldAngle_Y, real pupilPositionX, real pupilPositionY, Light_LLT light)
{
	
	// build chiefLightRay
	real refIndexStartMedia = oftenUse::getStartRefIndex(optSys);
	infosAS infosApertureStop = optSys.getInforAS();
	RayAiming rayAiming(optSys);
	rayAiming.setTolerance_XandY(mLoadParaOPD.getToleranceForRayAiming());
	LightRayStruct chiefLightRay = rayAiming.rayAiming_inf(fieldAngle_X, fieldAngle_Y, infosApertureStop.getPointAS(), light, refIndexStartMedia);
	rayAiming.setStartPointRayToInf(chiefLightRay);

	// new start point Ray
	//Ray_LLT chiefRay = chiefLightRay.getRay_LLT();
	//real lamda = (rayAiming.getDefaultParameters().getInfinity_neg() - chiefRay.getOriginRay().getZ()) / chiefRay.getDirectionRayUnit().getZ();
	//real X_inf = chiefRay.getOriginRay().getX() + lamda * chiefRay.getDirectionRayUnit().getX();
	//real Y_inf = chiefRay.getOriginRay().getY() + lamda * chiefRay.getDirectionRayUnit().getY();

	//VectorStructR3 newStartPointRay_inf(X_inf, Y_inf, rayAiming.getDefaultParameters().getInfinity_neg());

	real returnOPD{};

	CardinalPoints carPoints(optSys, objectPoint_inf_obj::inf);
	real positionZ_exitPupil_global = carPoints.getEXPP_globalCoori();

	unsigned int sizeOptSys = optSys.getPosAndInteractingSurface().size();
	real positionZ_lastSurface = optSys.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getPoint().getZ();

	// position of exit pupil is on the - right side - of the image surface
	if (positionZ_exitPupil_global > positionZ_lastSurface)
	{
		returnOPD = calculateOPD_exitPupilBehindOptSys_inf(optSys, positionZ_exitPupil_global, chiefLightRay.getRay_LLT().getOriginRay(), pupilPositionX, pupilPositionY, chiefLightRay);
	}
	else
	{
		returnOPD = calculateOPD_exitPupilLeftFromImaSurface_inf(optSys, positionZ_exitPupil_global, chiefLightRay.getRay_LLT().getOriginRay(), pupilPositionX, pupilPositionY, chiefLightRay);
	}

	return returnOPD;
}

real OPD::calculateOPD_exitPupilBehindOptSys_obj(OpticalSystem_LLT optSys, real posExitPupil_Z_global, VectorStructR3 startPointRay, real pupilPositionX, real pupilPositionY, Light_LLT light)
{
	// calc ref index start media
	real refIndexStartMedia = calcRefractivIndexStartMedia(optSys);
		
	real returnOPD{};
	RefractedRay_LLT refrac{};
	unsigned int sizeOptSys = optSys.getPosAndInteractingSurface().size();

	real refIndexBehindImaSurface{};
	real directionImaSurface = optSys.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getDirection().getZ();
	if (directionImaSurface > 0)
	{
		refIndexBehindImaSurface = optSys.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}
	else
	{
		refIndexBehindImaSurface = optSys.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
	}
	

	PlanGeometry_LLT exitPupilPlan(/*semiHeight*/oftenUse::getInfReal(), /*point*/{ 0.0,0.0,posExitPupil_Z_global }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ refIndexBehindImaSurface, /*refractiveSideB*/ refIndexBehindImaSurface);

	OpticalSystem_LLT optSys_includingExitPupilPlan{};
	optSys_includingExitPupilPlan = optSys.clone();
	optSys_includingExitPupilPlan.setInteractionOfSurface_i(sizeOptSys - 1, refrac.clone());
	optSys_includingExitPupilPlan.fillInSurfaceAndInteracAtPos_i(sizeOptSys, exitPupilPlan.clone(), refrac.clone());

	// build chiefLightRay
	infosAS infosApertureStop = optSys.getInforAS();
	RayAiming rayAiming(optSys);
	rayAiming.setTolerance_XandY(mLoadParaOPD.getToleranceForRayAiming());
	LightRayStruct chiefLightRay = rayAiming.rayAiming_obj(startPointRay, infosApertureStop.getPointAS(), light, refIndexStartMedia);

	SequentialRayTracing seqTraceToExitPupilPlan(optSys_includingExitPupilPlan);
	seqTraceToExitPupilPlan.sequentialRayTracing(chiefLightRay);

	// check for lost rays
	if (seqTraceToExitPupilPlan.getLoosingRays()) oftenUse::errorProtocol_stopSystem("loosing ray", "calculateOPD_exitPupilBehindOptSys - 1", 0, true);

	VectorStructR3 interPointChiefRayImaSurface = seqTraceToExitPupilPlan.getAllInterPointsAtSurface_i_filtered(sizeOptSys - 1)[0];
	VectorStructR3 interPointChiefRayAtExitPupil = seqTraceToExitPupilPlan.getAllInterPointsAtSurface_i_filtered(sizeOptSys)[0];
	VectorStructR3 directionRefSphere = interPointChiefRayImaSurface - interPointChiefRayAtExitPupil;

	real RadiusRefSphere = Math::lengthOfVector(directionRefSphere);
	real referenceDistance = seqTraceToExitPupilPlan.getInterInf_PosSurface_TotalSteps_ofSur_i(sizeOptSys)[0].getTotalSteps();

	// building refSphere at exit pupil
	SphericalSurface_LLT RefSpherAtExitPupilPlanExP(/*radius*/RadiusRefSphere, /*semiHeight*/oftenUse::getInfReal(), /*Apex of the sphere*/interPointChiefRayAtExitPupil, /*Direction*/ directionRefSphere, /*refIndexSideA*/refIndexBehindImaSurface, /*refIndexSideB*/refIndexBehindImaSurface);
	OpticalSystem_LLT optSys_includingRefSphere;
	optSys_includingRefSphere = optSys.clone();
	optSys_includingRefSphere.setInteractionOfSurface_i(sizeOptSys - 1, refrac.clone());
	optSys_includingRefSphere.fillInSurfaceAndInteracAtPos_i(sizeOptSys, RefSpherAtExitPupilPlanExP.clone(), refrac.clone());

	//SequentialRayTracing seqTrace(optSys_includingRefSphere);
	mPos_X_InApertureStop = pupilPositionX * infosApertureStop.getSemiHeightAS();
	mPos_Y_InApertureStop = pupilPositionY * infosApertureStop.getSemiHeightAS();
	mPos_Z_InApertureStop = infosApertureStop.getPointAS().getZ();

	VectorStructR3 targetPointInApertureStop(mPos_X_InApertureStop, mPos_Y_InApertureStop, mPos_Z_InApertureStop);

	mWantedLightRay = rayAiming.rayAiming_obj(startPointRay, targetPointInApertureStop, light, refIndexStartMedia);
	if (mWantedLightRay.getIsAlive() == false)
	{
		std::cout << "ray aiming not possible -> the light ray is not alive -> OPD is not correct!" << std::endl;
		oftenUse::errorProtocol_stopSystem("loosing ray", "calculateOPD_exitPupilBehindOptSys - 2", 0, true);
	}


	SequentialRayTracing seqTraceWantedLighRay(optSys_includingRefSphere);
	seqTraceWantedLighRay.sequentialRayTracing(mWantedLightRay);
	// check for lost rays
	if (seqTraceWantedLighRay.getLoosingRays()) oftenUse::errorProtocol_stopSystem("loosing ray", "calculateOPD_exitPupilBehindOptSys - 3", 0, true);;


	real distanceWantedRay = seqTraceWantedLighRay.getInterInf_PosSurface_TotalSteps_ofSur_i(sizeOptSys)[0].getTotalSteps();

	returnOPD = ((referenceDistance - distanceWantedRay) / light.getWavelength()) * 1000000;

	return returnOPD;
}



real OPD::calculateOPD_exitPupilLeftFromImaSurface_obj(OpticalSystem_LLT optSys, real posExitPupil_Z_global, VectorStructR3 startPointRay, real pupilPositionX, real pupilPositionY, Light_LLT light)
{
	real refIndexStartMedia = calcRefractivIndexStartMedia(optSys);
	real returnOPD{};

	RefractedRay_LLT refrac{};
	DoNothingInteraction_LLT doNothing{};
	TraceLightRayBack traceBack{};

	unsigned int sizeOptSys = optSys.getPosAndInteractingSurface().size();

	// get refractiv index before exit pupil
	real refIndexBeforeExitPupil{};
	unsigned int posSurfaceBeforeExitPupil{};
	unsigned int positionExitPupilInOptSys = calcPosExPupil_Z(optSys, posExitPupil_Z_global);
	if (positionExitPupilInOptSys == 0)
	{
		posSurfaceBeforeExitPupil = 0;
	}
	else
	{
		posSurfaceBeforeExitPupil = positionExitPupilInOptSys - 1;
	}

	real directionSurfaceBeforeExitPupil = optSys.getPosAndInteractingSurface()[posSurfaceBeforeExitPupil].getSurfaceInterRay_ptr()->getDirection().getZ();
	
	if (directionSurfaceBeforeExitPupil > 0)
	{
		refIndexBeforeExitPupil = optSys.getPosAndInteractingSurface()[posSurfaceBeforeExitPupil].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}
	else
	{
		refIndexBeforeExitPupil = optSys.getPosAndInteractingSurface()[posSurfaceBeforeExitPupil].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
	}
	// ***

	// get refractiv index before image surface

	real directionImaSurface= optSys.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getDirection().getZ();
	real refIndexBeforeImageSurface{};

	if (directionImaSurface > 0)
	{
		refIndexBeforeImageSurface = optSys.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}

	else
	{
		refIndexBeforeImageSurface = optSys.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}
	
	
	

	// get refractiv index after exit pupil
	real refIndexAfterExitPupil{};
	real directionSurfaceAfterExitPupil = optSys.getPosAndInteractingSurface()[positionExitPupilInOptSys].getSurfaceInterRay_ptr()->getDirection().getZ();
	if (directionSurfaceAfterExitPupil > 0)
	{
		refIndexAfterExitPupil = optSys.getPosAndInteractingSurface()[positionExitPupilInOptSys].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
	}
	else
	{
		refIndexAfterExitPupil = optSys.getPosAndInteractingSurface()[positionExitPupilInOptSys].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}
	// ***

	PlanGeometry_LLT exitPupilPlan(/*semiHeight*/oftenUse::getInfReal(), /*point*/{ 0.0,0.0,posExitPupil_Z_global }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ refIndexBeforeExitPupil, /*refractiveSideB*/ refIndexAfterExitPupil);
	

	// build chiefLightRay
	infosAS infosApertureStop = optSys.getInforAS();
	RayAiming rayAimingChiefRay(optSys);
	rayAimingChiefRay.setTolerance_XandY(mLoadParaOPD.getToleranceForRayAiming());
	LightRayStruct chiefLightRay = rayAimingChiefRay.rayAiming_obj(startPointRay, infosApertureStop.getPointAS(), light, refIndexStartMedia);

	OpticalSystem_LLT optSys_includingExitPupilPlan{};
	optSys_includingExitPupilPlan = optSys.clone();

	real prefixForRayTracing = 1.0;
	if (positionExitPupilInOptSys == 0)
	{
		// here first we have to trace back to the exit pupil
		if (posExitPupil_Z_global < startPointRay.getZ())
		{
			
			chiefLightRay.setRayDirectionUni(-1.0 * chiefLightRay.getRay_LLT().getDirectionRayUnit());
			optSys_includingExitPupilPlan.fillInSurfaceAndInteracAtPos_i(positionExitPupilInOptSys, exitPupilPlan.clone(), traceBack.clone());
		}

		else
		{
			optSys_includingExitPupilPlan.fillInSurfaceAndInteracAtPos_i(positionExitPupilInOptSys, exitPupilPlan.clone(), doNothing.clone());
		}
	}

	else
	{
		optSys_includingExitPupilPlan.fillInSurfaceAndInteracAtPos_i(positionExitPupilInOptSys, exitPupilPlan.clone(), doNothing.clone());
	}
		

	SequentialRayTracing seqTraceToImaSurface(optSys_includingExitPupilPlan);
	seqTraceToImaSurface.sequentialRayTracing(chiefLightRay);

	// check for lost ray
	if (seqTraceToImaSurface.getLoosingRays()) oftenUse::errorProtocol_stopSystem("loosing ray", "calculateOPD_exitPupilLeftFromImaSurface - 1", 0, true);

	VectorStructR3 interPointChiefRayImaSurface = seqTraceToImaSurface.getAllInterPointsAtSurface_i_filtered(sizeOptSys)[0];
	VectorStructR3 interPointChiefRayAtExitPupil = seqTraceToImaSurface.getAllInterPointsAtSurface_i_filtered(positionExitPupilInOptSys)[0];
	VectorStructR3 directionRefSphere = interPointChiefRayImaSurface - interPointChiefRayAtExitPupil;

	real RadiusRefSphere = Math::lengthOfVector(directionRefSphere);

	// building optical system with refSphere at exit pupil
	SphericalSurface_LLT RefSpherAtExitPupilPlanExP(/*radius*/RadiusRefSphere, /*semiHeight*/oftenUse::getInfReal(), /*Apex of the sphere*/interPointChiefRayAtExitPupil, /*Direction*/ directionRefSphere, /*refIndexSideA*/refIndexBeforeImageSurface, /*refIndexSideB*/refIndexBeforeImageSurface);
	OpticalSystem_LLT optSys_includingRefSphere;
	optSys_includingRefSphere.fillVectorSurfaceAndInteractingData(0, RefSpherAtExitPupilPlanExP.clone(), doNothing.clone());

	// calculate referece distance
	real length_1_chief = seqTraceToImaSurface.getInterInf_PosSurface_TotalSteps_ofSur_i(sizeOptSys)[0].getTotalSteps();
	if (posExitPupil_Z_global < startPointRay.getZ())
	{
		real firstLength = seqTraceToImaSurface.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[0].getTotalSteps();
		length_1_chief = length_1_chief - 2.0 * firstLength;
	}
	// build light ray to trace back
	Ray_LLT chiefRayToTraceBack(/*origin*/ interPointChiefRayImaSurface,/*direction*/ -1.0 * directionRefSphere,/*refractive index*/ refIndexBeforeImageSurface);
	LightRayStruct chiefLightRay_back(light, chiefRayToTraceBack, true);
	SequentialRayTracing seqTraceBack(optSys_includingRefSphere);
	seqTraceBack.sequentialRayTracing(chiefLightRay_back);
	// check for lost ray
	if (seqTraceBack.getLoosingRays()) oftenUse::errorProtocol_stopSystem("loosing ray", "calculateOPD_exitPupilLeftFromImaSurface - 2", 0, true);

	real lenght_2_chief = seqTraceBack.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[0].getTotalSteps();

	real referenceLenght = length_1_chief - lenght_2_chief;

	// calculate lenght wanted ray
	// build wanted light ray
	mPos_X_InApertureStop = pupilPositionX * infosApertureStop.getSemiHeightAS();
	mPos_Y_InApertureStop = pupilPositionY * infosApertureStop.getSemiHeightAS();
	mPos_Z_InApertureStop = infosApertureStop.getPointAS().getZ();
	VectorStructR3 targetPointInApertureStop(mPos_X_InApertureStop, mPos_Y_InApertureStop, mPos_Z_InApertureStop);
	mWantedLightRay = rayAimingChiefRay.rayAiming_obj(startPointRay, targetPointInApertureStop, light, refIndexStartMedia);
	if (mWantedLightRay.getIsAlive() == false)
	{
		std::cout << "ray aiming not possible -> the light ray is not alive -> OPD is not correct!" << std::endl;
		oftenUse::errorProtocol_stopSystem("loosing ray", "calculateOPD_exitPupilLeftFromImaSurface - 3", 0, true);
	}
	
	SequentialRayTracing seqTraceWantedRay(optSys);
	seqTraceWantedRay.sequentialRayTracing(mWantedLightRay);
	// check for lost ray
	if (seqTraceWantedRay.getLoosingRays()) oftenUse::errorProtocol_stopSystem("loosing ray", "calculateOPD_exitPupilLeftFromImaSurface - 4", 0, true);;

	real length_wanted_1 = seqTraceWantedRay.getInterInf_PosSurface_TotalSteps_ofSur_i(sizeOptSys - 1)[0].getTotalSteps();
	VectorStructR3 interPointWanted = seqTraceWantedRay.getAllInterPointsAtSurface_i_filtered(sizeOptSys - 1)[0];
	VectorStructR3 directionWantedRay_back = -1.0 * seqTraceWantedRay.getAllInterInfosOfSurf_i(sizeOptSys - 1)[0].getDirectionRayUnit();
	Ray_LLT wantedRayToTraceBack(/*origin*/ interPointWanted,/*direction*/directionWantedRay_back,/*refractive index*/ refIndexBeforeImageSurface);
	LightRayStruct wantedLightRayToTraceBack(light, wantedRayToTraceBack, true);
	seqTraceBack.sequentialRayTracing(wantedLightRayToTraceBack);
	// check for lost ray
	if (seqTraceBack.getLoosingRays()) oftenUse::errorProtocol_stopSystem("loosing ray", "calculateOPD_exitPupilLeftFromImaSurface - 5", 0, true);;

	real length_wanted_2 = seqTraceBack.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[1].getTotalSteps();

	real wantedLength = length_wanted_1 - length_wanted_2;


	returnOPD = ((referenceLenght - wantedLength) / light.getWavelength()) * 1000000;;

	return returnOPD;
}

real OPD::calculateOPD_exitPupilBehindOptSys_inf(OpticalSystem_LLT optSys, real posExitPupil_Z_global, VectorStructR3 startPointRay, real pupilPositionX, real pupilPositionY, LightRayStruct chiefLightRay)
{
	// calc ref index start media
	real refIndexStartMedia = calcRefractivIndexStartMedia(optSys);


	real returnOPD{};
	RefractedRay_LLT refrac{};
	unsigned int sizeOptSys = optSys.getPosAndInteractingSurface().size();

	real refIndexBehindImaSurface{};
	real directionImaSurface = optSys.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getDirection().getZ();
	if (directionImaSurface > 0)
	{
		refIndexBehindImaSurface = optSys.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}
	else
	{
		refIndexBehindImaSurface = optSys.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
	}


	PlanGeometry_LLT exitPupilPlan(/*semiHeight*/oftenUse::getInfReal(), /*point*/{ 0.0,0.0,posExitPupil_Z_global }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ refIndexBehindImaSurface, /*refractiveSideB*/ refIndexBehindImaSurface);

	OpticalSystem_LLT optSys_includingExitPupilPlan{};
	optSys_includingExitPupilPlan = optSys.clone();
	optSys_includingExitPupilPlan.setInteractionOfSurface_i(sizeOptSys - 1, refrac.clone());
	optSys_includingExitPupilPlan.fillInSurfaceAndInteracAtPos_i(sizeOptSys, exitPupilPlan.clone(), refrac.clone());


	SequentialRayTracing seqTraceToExitPupilPlan(optSys_includingExitPupilPlan);
	seqTraceToExitPupilPlan.sequentialRayTracing(chiefLightRay);

	// check for lost rays
	if (seqTraceToExitPupilPlan.getLoosingRays()) oftenUse::errorProtocol_stopSystem("loosing ray", "calculateOPD_exitPupilBehindOptSys - 1", 0, true);

	VectorStructR3 interPointChiefRayImaSurface = seqTraceToExitPupilPlan.getAllInterPointsAtSurface_i_filtered(sizeOptSys - 1)[0];
	VectorStructR3 interPointChiefRayAtExitPupil = seqTraceToExitPupilPlan.getAllInterPointsAtSurface_i_filtered(sizeOptSys)[0];
	VectorStructR3 directionRefSphere = interPointChiefRayImaSurface - interPointChiefRayAtExitPupil;

	real RadiusRefSphere = Math::lengthOfVector(directionRefSphere);
	real referenceDistance = seqTraceToExitPupilPlan.getInterInf_PosSurface_TotalSteps_ofSur_i(sizeOptSys)[0].getTotalSteps();

	// building refSphere at exit pupil
	SphericalSurface_LLT RefSpherAtExitPupilPlanExP(/*radius*/RadiusRefSphere, /*semiHeight*/oftenUse::getInfReal(), /*Apex of the sphere*/interPointChiefRayAtExitPupil, /*Direction*/ directionRefSphere, /*refIndexSideA*/refIndexBehindImaSurface, /*refIndexSideB*/refIndexBehindImaSurface);
	OpticalSystem_LLT optSys_includingRefSphere;
	optSys_includingRefSphere = optSys.clone();
	optSys_includingRefSphere.setInteractionOfSurface_i(sizeOptSys - 1, refrac.clone());
	optSys_includingRefSphere.fillInSurfaceAndInteracAtPos_i(sizeOptSys, RefSpherAtExitPupilPlanExP.clone(), refrac.clone());

	//SequentialRayTracing seqTrace(optSys_includingRefSphere);
	infosAS infosApertureStop = optSys.getInforAS();
	mPos_X_InApertureStop = pupilPositionX * infosApertureStop.getSemiHeightAS();
	mPos_Y_InApertureStop = pupilPositionY * infosApertureStop.getSemiHeightAS();
	mPos_Z_InApertureStop = infosApertureStop.getPointAS().getZ();
	VectorStructR3 targetPointInApertureStop(mPos_X_InApertureStop, mPos_Y_InApertureStop, mPos_Z_InApertureStop);

	RayAiming rayAiming(optSys);
	rayAiming.setFactor_obj(mLoadParaOPD.getFactorForRayAimingIfObjInInf());
	rayAiming.setTolerance_XandY(mLoadParaOPD.getToleranceForRayAiming());
	mWantedLightRay = rayAiming.rayAiming_obj(startPointRay, targetPointInApertureStop, chiefLightRay.getLight_LLT(), refIndexStartMedia);

	if (mWantedLightRay.getIsAlive() == false)
	{
		std::cout << "ray aiming not possible -> the light ray is not alive -> OPD is not correct!" << std::endl;
		oftenUse::errorProtocol_stopSystem("loosing ray", "calculateOPD_exitPupilBehindOptSys - 2", 0, true);
	}


	SequentialRayTracing seqTraceWantedLighRay(optSys_includingRefSphere);
	seqTraceWantedLighRay.sequentialRayTracing(mWantedLightRay);
	// check for lost rays
	if (seqTraceWantedLighRay.getLoosingRays()) oftenUse::errorProtocol_stopSystem("loosing ray", "calculateOPD_exitPupilBehindOptSys - 3", 0, true);;


	real distanceWantedRay = seqTraceWantedLighRay.getInterInf_PosSurface_TotalSteps_ofSur_i(sizeOptSys)[0].getTotalSteps();

	returnOPD = ((referenceDistance - distanceWantedRay) / chiefLightRay.getLight_LLT().getWavelength()) * 1000000;

	return returnOPD;
}

real OPD::calculateOPD_exitPupilLeftFromImaSurface_inf(OpticalSystem_LLT optSys, real posExitPupil_Z_global, VectorStructR3 startPointRay, real pupilPositionX, real pupilPositionY, LightRayStruct chiefLightRay)
{
	real refIndexStartMedia = calcRefractivIndexStartMedia(optSys);
	real returnOPD{};

	RefractedRay_LLT refrac{};
	DoNothingInteraction_LLT doNothing{};
	TraceLightRayBack traceBack{};

	unsigned int sizeOptSys = optSys.getPosAndInteractingSurface().size();

	// get refractiv index before exit pupil
	real refIndexBeforeExitPupil{};
	unsigned int posSurfaceBeforeExitPupil{};
	unsigned int positionExitPupilInOptSys = calcPosExPupil_Z(optSys, posExitPupil_Z_global);
	if (positionExitPupilInOptSys == 0)
	{
		posSurfaceBeforeExitPupil = 0;
	}
	else
	{
		posSurfaceBeforeExitPupil = positionExitPupilInOptSys - 1;
	}

	real directionSurfaceBeforeExitPupil = optSys.getPosAndInteractingSurface()[posSurfaceBeforeExitPupil].getSurfaceInterRay_ptr()->getDirection().getZ();

	if (directionSurfaceBeforeExitPupil > 0)
	{
		refIndexBeforeExitPupil = optSys.getPosAndInteractingSurface()[posSurfaceBeforeExitPupil].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}
	else
	{
		refIndexBeforeExitPupil = optSys.getPosAndInteractingSurface()[posSurfaceBeforeExitPupil].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
	}
	// ***

	// get refractiv index before image surface

	real directionImaSurface = optSys.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getDirection().getZ();
	real refIndexBeforeImageSurface{};

	if (directionImaSurface > 0)
	{
		refIndexBeforeImageSurface = optSys.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}

	else
	{
		refIndexBeforeImageSurface = optSys.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}




	// get refractiv index after exit pupil
	real refIndexAfterExitPupil{};
	real directionSurfaceAfterExitPupil = optSys.getPosAndInteractingSurface()[positionExitPupilInOptSys].getSurfaceInterRay_ptr()->getDirection().getZ();
	if (directionSurfaceAfterExitPupil > 0)
	{
		refIndexAfterExitPupil = optSys.getPosAndInteractingSurface()[positionExitPupilInOptSys].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
	}
	else
	{
		refIndexAfterExitPupil = optSys.getPosAndInteractingSurface()[positionExitPupilInOptSys].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}
	// ***

	PlanGeometry_LLT exitPupilPlan(/*semiHeight*/oftenUse::getInfReal(), /*point*/{ 0.0,0.0,posExitPupil_Z_global }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ refIndexBeforeExitPupil, /*refractiveSideB*/ refIndexAfterExitPupil);

	OpticalSystem_LLT optSys_includingExitPupilPlan{};
	optSys_includingExitPupilPlan = optSys.clone();


	if (positionExitPupilInOptSys == 0)
	{
	
		if (posExitPupil_Z_global < startPointRay.getZ())
		{
			oftenUse::errorProtocol_stopSystem("start point of ray is not in neg infinity!", "OpticalPathDifference", 0, true);
		}

		else
		{
			optSys_includingExitPupilPlan.fillInSurfaceAndInteracAtPos_i(positionExitPupilInOptSys, exitPupilPlan.clone(), doNothing.clone());
		}
	}

	else
	{
		optSys_includingExitPupilPlan.fillInSurfaceAndInteracAtPos_i(positionExitPupilInOptSys, exitPupilPlan.clone(), doNothing.clone());
	}


	SequentialRayTracing seqTraceToImaSurface(optSys_includingExitPupilPlan);
	seqTraceToImaSurface.sequentialRayTracing(chiefLightRay);

	// check for lost ray
	if (seqTraceToImaSurface.getLoosingRays()) oftenUse::errorProtocol_stopSystem("loosing ray", "calculateOPD_exitPupilLeftFromImaSurface - 1", 0, true);

	VectorStructR3 interPointChiefRayImaSurface = seqTraceToImaSurface.getAllInterPointsAtSurface_i_filtered(sizeOptSys)[0];
	VectorStructR3 interPointChiefRayAtExitPupil = seqTraceToImaSurface.getAllInterPointsAtSurface_i_filtered(positionExitPupilInOptSys)[0];
	VectorStructR3 directionRefSphere = interPointChiefRayImaSurface - interPointChiefRayAtExitPupil;

	real RadiusRefSphere = Math::lengthOfVector(directionRefSphere);

	// building optical system with refSphere at exit pupil
	SphericalSurface_LLT RefSpherAtExitPupilPlanExP(/*radius*/RadiusRefSphere, /*semiHeight*/oftenUse::getInfReal(), /*Apex of the sphere*/interPointChiefRayAtExitPupil, /*Direction*/ directionRefSphere, /*refIndexSideA*/refIndexBeforeImageSurface, /*refIndexSideB*/refIndexBeforeImageSurface);
	OpticalSystem_LLT optSys_includingRefSphere;
	optSys_includingRefSphere.fillVectorSurfaceAndInteractingData(0, RefSpherAtExitPupilPlanExP.clone(), doNothing.clone());

	// calculate referece distance
	real length_1_chief = seqTraceToImaSurface.getInterInf_PosSurface_TotalSteps_ofSur_i(sizeOptSys)[0].getTotalSteps();
	if (posExitPupil_Z_global < startPointRay.getZ())
	{
		real firstLength = seqTraceToImaSurface.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[0].getTotalSteps();
		length_1_chief = length_1_chief - 2.0 * firstLength;
	}
	// build light ray to trace back
	Ray_LLT chiefRayToTraceBack(/*origin*/ interPointChiefRayImaSurface,/*direction*/ -1.0 * directionRefSphere,/*refractive index*/ refIndexBeforeImageSurface);
	LightRayStruct chiefLightRay_back(chiefLightRay.getLight_LLT(), chiefRayToTraceBack, true);
	SequentialRayTracing seqTraceBack(optSys_includingRefSphere);
	seqTraceBack.sequentialRayTracing(chiefLightRay_back);
	// check for lost ray
	if (seqTraceBack.getLoosingRays()) oftenUse::errorProtocol_stopSystem("loosing ray", "calculateOPD_exitPupilLeftFromImaSurface - 2", 0, true);

	real lenght_2_chief = seqTraceBack.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[0].getTotalSteps();

	real referenceLenght = length_1_chief - lenght_2_chief;

	// calculate lenght wanted ray
	// build wanted light ray
	infosAS infosApertureStop = optSys.getInforAS();
	mPos_X_InApertureStop = pupilPositionX * infosApertureStop.getSemiHeightAS();
	mPos_Y_InApertureStop = pupilPositionY * infosApertureStop.getSemiHeightAS();
	mPos_Z_InApertureStop = infosApertureStop.getPointAS().getZ();
	VectorStructR3 targetPointInApertureStop(mPos_X_InApertureStop, mPos_Y_InApertureStop, mPos_Z_InApertureStop);
	RayAiming rayAiming(optSys);
	rayAiming.setFactor_obj(mLoadParaOPD.getFactorForRayAimingIfObjInInf());
	rayAiming.setTolerance_XandY(mLoadParaOPD.getToleranceForRayAiming());
	mWantedLightRay = rayAiming.rayAiming_obj(startPointRay, targetPointInApertureStop, chiefLightRay.getLight_LLT(), refIndexStartMedia);
	if (mWantedLightRay.getIsAlive() == false)
	{
		std::cout << "ray aiming not possible -> the light ray is not alive -> OPD is not correct!" << std::endl;
		oftenUse::errorProtocol_stopSystem("loosing ray", "calculateOPD_exitPupilLeftFromImaSurface - 3", 0, true);
	}

	SequentialRayTracing seqTraceWantedRay(optSys);
	seqTraceWantedRay.sequentialRayTracing(mWantedLightRay);
	// check for lost ray
	if (seqTraceWantedRay.getLoosingRays()) oftenUse::errorProtocol_stopSystem("loosing ray", "calculateOPD_exitPupilLeftFromImaSurface - 4", 0, true);;

	real length_wanted_1 = seqTraceWantedRay.getInterInf_PosSurface_TotalSteps_ofSur_i(sizeOptSys - 1)[0].getTotalSteps();
	VectorStructR3 interPointWanted = seqTraceWantedRay.getAllInterPointsAtSurface_i_filtered(sizeOptSys - 1)[0];
	VectorStructR3 directionWantedRay_back = -1.0 * seqTraceWantedRay.getAllInterInfosOfSurf_i(sizeOptSys - 1)[0].getDirectionRayUnit();
	Ray_LLT wantedRayToTraceBack(/*origin*/ interPointWanted,/*direction*/directionWantedRay_back,/*refractive index*/ refIndexBeforeImageSurface);
	LightRayStruct wantedLightRayToTraceBack(chiefLightRay.getLight_LLT(), wantedRayToTraceBack, true);
	seqTraceBack.sequentialRayTracing(wantedLightRayToTraceBack);
	// check for lost ray
	if (seqTraceBack.getLoosingRays()) oftenUse::errorProtocol_stopSystem("loosing ray", "calculateOPD_exitPupilLeftFromImaSurface - 5", 0, true);;

	real length_wanted_2 = seqTraceBack.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[1].getTotalSteps();

	real wantedLength = length_wanted_1 - length_wanted_2;


	returnOPD = ((referenceLenght - wantedLength) / chiefLightRay.getLight_LLT().getWavelength()) * 1000000;;

	return returnOPD;

}

// calculate position of exit pupil in optical system according to z direction
unsigned int OPD::calcPosExPupil_Z(OpticalSystem_LLT optSys, real position_Z_exitPupil)
{
	unsigned int i = 0.0;
	unsigned int size = optSys.getPosAndInteractingSurface().size();
	//

	for (i; i < size; ++i)
	{
		real Z = optSys.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getPoint().getZ();
		if (Z >= position_Z_exitPupil)
		{
			return optSys.getPosAndInteractingSurface()[i].getPosition();
		}
	}

	return i;
}

// calculate refractiv index start media
real OPD::calcRefractivIndexStartMedia(OpticalSystem_LLT optSys)
{	
	real refIndexStartMedia{};
	real directionFirstSurface = optSys.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getDirection().getZ();
	if (directionFirstSurface > 0)
	{
		refIndexStartMedia = optSys.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
	}
	else
	{
		refIndexStartMedia = optSys.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}

	return refIndexStartMedia;

}

// calculate position of exit pupil in optical system according to z direction
unsigned int OPD::calcPosExPupil_Z()
{
	unsigned int i = 0.0;
	unsigned int size = mOptSys.getPosAndInteractingSurface().size();
	//

	for (i; i < size; ++i)
	{
		real Z = mOptSys.getPosAndInteractingSurface()[i].getSurfaceInterRay_ptr()->getPoint().getZ();
		if (Z >= mExitPupil->getPoint().getZ())
		{
			return mOptSys.getPosAndInteractingSurface()[i].getPosition();
		}
	}

	return i;
}


// calculate global OPD
void OPD::calcGlobalOPD_new()
{
	// calculate the cardinal points to get psoition of exit pupil
	CardinalPoints carPoints(mOptSys, mInf_obj);
	real positionExitPupil_global = carPoints.getEXPP_globalCoori();

	unsigned int sizeOptSys = mOptSys.getPosAndInteractingSurface().size();
	real positionZ_lastSurface = mOptSys.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getPoint().getZ();

	// *** obj ***
	if(mInf_obj == objectPoint_inf_obj::obj)
	{

		// position of exit pupil is on the - right side - of the image surface
		if (positionExitPupil_global > positionZ_lastSurface)
		{
			calcGlobalOPD_new_Right_SideOfImaSurface_obj(positionExitPupil_global);
		}
		// position of exit pupil is in the - left side - of the image surface
		else
		{
			calcGlobalOPD_new_LEFT_SideOfImaSurface_obj(positionExitPupil_global);
		}
	}
	
	// *** inf ***
	else if (mInf_obj == objectPoint_inf_obj::inf)
	{
		// position of exit pupil is on the - right side - of the image surface
		if (positionExitPupil_global > positionZ_lastSurface)
		{
			calcGlobalOPD_new_Right_SideOfImaSurface_inf(positionExitPupil_global);
		}
		// position of exit pupil is in the - left side - of the image surface
		else
		{
			calcGlobalOPD_new_LEFT_SideOfImaSurface_inf(positionExitPupil_global);
		}
	}

	else
	{
		oftenUse::errorProtocol_stopSystem("inf or obj is not selected", "OpticalPathDifference.cpp", 0, true);
	}

}




void OPD::calcGlobalOPD_new_Right_SideOfImaSurface_obj(real positionExitPupil_global)
{

	
	// build the optical system with the exit pupil plan
	buildOpticalSystemWithExitPupilPlan_rightSide(positionExitPupil_global);

	LightRayStruct chiefLightRay;
	if (mLoadParaOPD.getFirstAimedRayIsChiefRay())
	{
		chiefLightRay = mAimedLightRay[0];
	}
	else
	{
		// build chiefLightRay
		infosAS infosApertureStop = mOptSys.getInforAS();
		RayAiming rayAiming(mOptSys);
		rayAiming.setTolerance_XandY(mLoadParaOPD.getToleranceForRayAiming());
		chiefLightRay = rayAiming.rayAiming_obj(mAimedLightRay[0].getRay_LLT().getOriginRay(), infosApertureStop.getPointAS(), mAimedLightRay[0].getLight_LLT(), mAimedLightRay[0].getRay_LLT().getCurrentRefractiveIndex());
	}

	

	// collect infomrations to build optical system including reference sphere
	SequentialRayTracing seqTraceToExitPupilPlan(mOptSysWithExitPupilPlan);
	seqTraceToExitPupilPlan.sequentialRayTracing(chiefLightRay);
	// check for lost rays
	if (seqTraceToExitPupilPlan.getLoosingRays())
	{
		oftenUse::errorProtocol_stopSystem("loosing ray", "calcGlobalOPD_new_Right_SideOfImaSurface - 1", 0, true);
	}
		


	unsigned int positionExitPupil = mOptSysWithExitPupilPlan.getPosAndInteractingSurface().size() - 1;
	VectorStructR3 interPointChiefRayImaSurface = seqTraceToExitPupilPlan.getAllInterPointsAtSurface_i_filtered(positionExitPupil - 1)[0];
	VectorStructR3 interPointChiefRayAtExitPupil = seqTraceToExitPupilPlan.getAllInterPointsAtSurface_i_filtered(positionExitPupil)[0];
	VectorStructR3 directionRefSphere = interPointChiefRayImaSurface - interPointChiefRayAtExitPupil;

	real RadiusRefSphere = Math::lengthOfVector(directionRefSphere);

	// reference distance
	real referenceDistance = seqTraceToExitPupilPlan.getInterInf_PosSurface_TotalSteps_ofSur_i(positionExitPupil)[0].getTotalSteps();

	// build the optical system including reference sphere at exit pupil
	buildOpticalSystemWithReferenceSphereAtExitPupil_rightSide(RadiusRefSphere, interPointChiefRayAtExitPupil, directionRefSphere);

	// trace many ray to fill matrix with OPDs
	SequentialRayTracing seqTrace(mOptSysWithReferenceSphere);
	seqTrace.seqRayTracingWithVectorOfLightRays(mAimedLightRay);
	// check for lost rays
	if (seqTrace.getLoosingRays()) oftenUse::errorProtocol_stopSystem("loosing ray", "calcGlobalOPD_new_Right_SideOfImaSurface - 2", 0 , true);


	// save all datas to fill matrix with OPD
	std::vector<real> allDistances = seqTrace.getAllDistancesSurface_i(positionExitPupil);
	std::vector<VectorStructR3> allInterpointsAtRefSphere = seqTrace.getAllInterPointsAtSurface_i_filtered(positionExitPupil);

	calcAllOPDs(referenceDistance, allDistances);

	PX_PY_MX_MY saveInfosAboutOPD;
	saveInfosAboutOPD.calcAllPositionRegardsToChiefRay(allInterpointsAtRefSphere, mSizeMatrix);

	// save all OPD in matrix
	saveAllOPDsInMatrix(saveInfosAboutOPD.getAll_MX(), saveInfosAboutOPD.getAll_MY());

 }


// calc all OPD
void OPD::calcAllOPDs(real referenceDistance, const std::vector<real>& allDistances)
{
	unsigned int size = allDistances.size();
	mAllOPDs.resize(size);
	real wavelength = mAimedLightRay[0].getLight_LLT().getWavelength();

	real tempOPD{};
	for (unsigned int i = 0; i < size; ++i)
	{
		mAllOPDs[i] = ((referenceDistance - allDistances[i]) / wavelength) * 1000000;
	}
}

// save all OPDS in matrix
void OPD::saveAllOPDsInMatrix(std::vector<unsigned int> MX, std::vector<unsigned int> MY)
{
	mGlobalOPD = cv::Mat::zeros(mSizeMatrix, mSizeMatrix, CV_64F);
	unsigned int numberOfOPD = MX.size();
	// fill the matrix
	for (unsigned int i = 0; i < numberOfOPD; ++i)
	{
		mGlobalOPD.at<real>(MY[i], MX[i]) = mAllOPDs[i];
	}

}

void OPD::buildOpticalSystemWithExitPupilPlan_rightSide(real positionExitPupil_global)
{
	// build the exit pupil plan
	unsigned int sizeOptSysMinOne = mOptSys.getPosAndInteractingSurface().size() - 1;
	real refIndexBehindImaSurface{};
	real directionImaSurface = mOptSys.getPosAndInteractingSurface()[sizeOptSysMinOne].getSurfaceInterRay_ptr()->getDirection().getZ();
	if (directionImaSurface > 0)
	{
		refIndexBehindImaSurface = mOptSys.getPosAndInteractingSurface()[sizeOptSysMinOne].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}
	else
	{
		refIndexBehindImaSurface = mOptSys.getPosAndInteractingSurface()[sizeOptSysMinOne].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
	}

	PlanGeometry_LLT exitPupil(/*semi height*/ oftenUse::getInfReal(),/*point*/{ 0.0,0.0,positionExitPupil_global },/*direction*/{ 0.0,0.0,1.0 },/*refractive index A*/ refIndexBehindImaSurface, /*refractive index B*/ refIndexBehindImaSurface);

	mOptSysWithExitPupilPlan = mOptSys.clone();
	mOptSysWithExitPupilPlan.fillInSurfaceAndInteracAtPos_i(sizeOptSysMinOne + 1, exitPupil.clone(), mDoNothingInter.clone());
	RefractedRay_LLT refrac;
	mOptSysWithExitPupilPlan.setInteractionOfSurface_i(sizeOptSysMinOne, refrac.clone());
}


void OPD::buildOpticalSystemWithReferenceSphereAtExitPupil_rightSide(real radiusRefSphere, VectorStructR3 pointRefSphere, VectorStructR3 directionRefSphere)
{
	unsigned int posLastSurface_imaPlan = mOptSys.getPosAndInteractingSurface().size() - 1;
	real directionZ_lastSurface = mOptSys.getPosAndInteractingSurface()[posLastSurface_imaPlan].getSurfaceInterRay_ptr()->getDirection().getZ();

	real refIndexBehindImaSurface;
	if (directionZ_lastSurface > 0)
	{
		refIndexBehindImaSurface = mOptSys.getPosAndInteractingSurface()[posLastSurface_imaPlan].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}
	else
	{
		refIndexBehindImaSurface = mOptSys.getPosAndInteractingSurface()[posLastSurface_imaPlan].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
	}


	// build the reference sphere
	SphericalSurface_LLT referenceSphere(/*radius*/radiusRefSphere, /*semiHeight*/oftenUse::getInfReal(), /*Apex of the sphere*/pointRefSphere, /*Direction*/  directionRefSphere, /*refIndexSideA*/refIndexBehindImaSurface, /*refIndexSideB*/refIndexBehindImaSurface);
	
	mOptSysWithReferenceSphere = mOptSys.clone();
	RefractedRay_LLT refrac{};
	Absorb_LLT absorb{};
	mOptSysWithReferenceSphere.setInteractionOfSurface_i(posLastSurface_imaPlan, refrac.clone());
	mOptSysWithReferenceSphere.fillInSurfaceAndInteracAtPos_i(posLastSurface_imaPlan + 1, referenceSphere.clone(), absorb.clone());
}

void OPD::calcGlobalOPD_new_LEFT_SideOfImaSurface_obj(real positionExitPupil_global)
{
	mOptSysWithReferenceSphere.clean_optSys_LLT();

	real refIndexStartMedia = calcRefractivIndexStartMedia(mOptSys);

	unsigned int sizeOptSys = mOptSys.getPosAndInteractingSurface().size();

	// get refractiv index before exit pupil
	real refIndexBeforeExitPupil{};
	unsigned int posSurfaceBeforeExitPupil{};
	unsigned int positionExitPupilInOptSys = calcPosExPupil_Z(mOptSys, positionExitPupil_global);
	if (positionExitPupilInOptSys == 0)
	{
		posSurfaceBeforeExitPupil = 0;
	}
	else
	{
		posSurfaceBeforeExitPupil = positionExitPupilInOptSys - 1;
	}

	real directionSurfaceBeforeExitPupil = mOptSys.getPosAndInteractingSurface()[posSurfaceBeforeExitPupil].getSurfaceInterRay_ptr()->getDirection().getZ();

	if (directionSurfaceBeforeExitPupil > 0)
	{
		refIndexBeforeExitPupil = mOptSys.getPosAndInteractingSurface()[posSurfaceBeforeExitPupil].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}
	else
	{
		refIndexBeforeExitPupil = mOptSys.getPosAndInteractingSurface()[posSurfaceBeforeExitPupil].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
	}
	// ***

	// get refractiv index before image surface

	real directionImaSurface = mOptSys.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getDirection().getZ();
	real refIndexBeforeImageSurface{};

	if (directionImaSurface > 0)
	{
		refIndexBeforeImageSurface = mOptSys.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}

	else
	{
		refIndexBeforeImageSurface = mOptSys.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}




	// get refractiv index after exit pupil
	real refIndexAfterExitPupil{};
	real directionSurfaceAfterExitPupil = mOptSys.getPosAndInteractingSurface()[positionExitPupilInOptSys].getSurfaceInterRay_ptr()->getDirection().getZ();
	if (directionSurfaceAfterExitPupil > 0)
	{
		refIndexAfterExitPupil = mOptSys.getPosAndInteractingSurface()[positionExitPupilInOptSys].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
	}
	else
	{
		refIndexAfterExitPupil = mOptSys.getPosAndInteractingSurface()[positionExitPupilInOptSys].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}
	// ***

	PlanGeometry_LLT exitPupilPlan(/*semiHeight*/oftenUse::getInfReal(), /*point*/{ 0.0,0.0,positionExitPupil_global }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ refIndexBeforeExitPupil, /*refractiveSideB*/ refIndexAfterExitPupil);


	// first aimed ray must be chiefLightRay
	//LightRayStruct chiefLightRay = mAimedLightRay[0];

	LightRayStruct chiefLightRay{};
	if (mLoadParaOPD.getFirstAimedRayIsChiefRay())
	{
		chiefLightRay = mAimedLightRay[0];
	}
	else
	{
		// calculating chiefRay
		infosAS infosApertureStop = mOptSys.getInforAS();
		RayAiming rayAimingChiefRay(mOptSys);
		rayAimingChiefRay.setTolerance_XandY(mLoadParaOPD.getToleranceForRayAiming());
		chiefLightRay = rayAimingChiefRay.rayAiming_obj(mAimedLightRay[0].getRay_LLT().getOriginRay(), infosApertureStop.getPointAS(), mAimedLightRay[0].getLight_LLT(), refIndexStartMedia);
	}
	


	mOptSysWithExitPupilPlan = mOptSys.clone();

	TraceLightRayBack traceBack;
	DoNothingInteraction_LLT doNothing;

	real prefixForRayTracing = 1.0;
	if (positionExitPupilInOptSys == 0)
	{
		// here first we have to trace back to the exit pupil
		if (positionExitPupil_global < mAimedLightRay[0].getRay_LLT().getOriginRay().getZ())
		{

			chiefLightRay.setRayDirectionUni(-1.0 * chiefLightRay.getRay_LLT().getDirectionRayUnit());
			mOptSysWithExitPupilPlan.fillInSurfaceAndInteracAtPos_i(positionExitPupilInOptSys, exitPupilPlan.clone(), traceBack.clone());
		}

		else
		{
			mOptSysWithExitPupilPlan.fillInSurfaceAndInteracAtPos_i(positionExitPupilInOptSys, exitPupilPlan.clone(), doNothing.clone());
		}
	}

	else
	{
		mOptSysWithExitPupilPlan.fillInSurfaceAndInteracAtPos_i(positionExitPupilInOptSys, exitPupilPlan.clone(), doNothing.clone());
	}


	SequentialRayTracing seqTraceToImaSurface(mOptSysWithExitPupilPlan);
	seqTraceToImaSurface.sequentialRayTracing(chiefLightRay);
	// check for lost rays
	//if (seqTraceToImaSurface.getLoosingRays()) oftenUse::errorProtocol_stopSystem("loosing ray", "calcGlobalOPD_new_LEFT_SideOfImaSurface - 1", 0, true);

	// debug
	// std::cout << "loosing ray: " << seqTraceToImaSurface.getLoosingRays() << std::endl;

	VectorStructR3 interPointChiefRayImaSurface = seqTraceToImaSurface.getAllInterPointsAtSurface_i_filtered(sizeOptSys)[0];
	VectorStructR3 interPointChiefRayAtExitPupil = seqTraceToImaSurface.getAllInterPointsAtSurface_i_filtered(positionExitPupilInOptSys)[0];
	VectorStructR3 directionRefSphere = interPointChiefRayImaSurface - interPointChiefRayAtExitPupil;

	real RadiusRefSphere = Math::lengthOfVector(directionRefSphere);

	// building optical system with refSphere at exit pupil
	SphericalSurface_LLT RefSpherAtExitPupilPlanExP(/*radius*/RadiusRefSphere, /*semiHeight*/oftenUse::getInfReal(), /*Apex of the sphere*/interPointChiefRayAtExitPupil, /*Direction*/ directionRefSphere, /*refIndexSideA*/refIndexBeforeImageSurface, /*refIndexSideB*/refIndexBeforeImageSurface);
	mOptSysWithReferenceSphere.fillVectorSurfaceAndInteractingData(0, RefSpherAtExitPupilPlanExP.clone(), doNothing.clone());

	// calculate referece distance
	real length_1_chief = seqTraceToImaSurface.getInterInf_PosSurface_TotalSteps_ofSur_i(sizeOptSys)[0].getTotalSteps();
	if (positionExitPupil_global < mAimedLightRay[0].getRay_LLT().getOriginRay().getZ())
	{
		real firstLength = seqTraceToImaSurface.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[0].getTotalSteps();
		length_1_chief = length_1_chief - 2.0 * firstLength;
	}

	// build light ray to trace back
	Ray_LLT chiefRayToTraceBack(/*origin*/ interPointChiefRayImaSurface,/*direction*/ -1.0 * directionRefSphere,/*refractive index*/ refIndexBeforeImageSurface);
	LightRayStruct chiefLightRay_back(mAimedLightRay[0].getLight_LLT(), chiefRayToTraceBack, true);
	SequentialRayTracing seqTraceBack(mOptSysWithReferenceSphere);
	seqTraceBack.sequentialRayTracing(chiefLightRay_back);
	// check for lost rays
	//if (seqTraceBack.getLoosingRays()) oftenUse::errorProtocol_stopSystem("loosing ray", "calcGlobalOPD_new_LEFT_SideOfImaSurface - 2", 0, true);;

	real lenght_2_chief = seqTraceBack.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[0].getTotalSteps();

	real referenceLenght = length_1_chief - lenght_2_chief;

	// seq tracing to ima surface
	SequentialRayTracing seqTraceWantedRay(mOptSys);
	seqTraceWantedRay.seqRayTracingWithVectorOfLightRays(mAimedLightRay);
	// check for lost rays
	//if (seqTraceWantedRay.getLoosingRays()) oftenUse::errorProtocol_stopSystem("loosing ray", "calcGlobalOPD_new_LEFT_SideOfImaSurface - 3", 0, true);;

	std::vector<real> allDistancesTraceForward = seqTraceWantedRay.getAllDistancesSurface_i(sizeOptSys - 1);

	// trace all rays back to ima surface
	std::vector<VectorStructR3> allInterPointsImaSurface = seqTraceWantedRay.getAllInterPointsAtSurface_i_filtered(sizeOptSys - 1);
	std::vector<VectorStructR3> allDirectionsImaSurface = seqTraceWantedRay.getAllDirectionsAtSurface_i_filtered(sizeOptSys - 1);
	std::vector<VectorStructR3> allDirectionsImaSurface_traceBack = -1.0 * allDirectionsImaSurface;

	// build light rays to trace back
	std::vector<LightRayStruct> lightRayTraceBack_vec{};
	lightRayTraceBack_vec.resize(allInterPointsImaSurface.size());
	Light_LLT light = mAimedLightRay[0].getLight_LLT();
	LightRayStruct tempLightRay;
	tempLightRay.setIsAlive(true);
	tempLightRay.setLight_LLT(light);

	tempLightRay.setCurrentRefractivIndex(refIndexBeforeImageSurface);
	for (unsigned int i = 0; i < allInterPointsImaSurface.size(); ++i)
	{
	
		tempLightRay.setRayOrigin(allInterPointsImaSurface[i]);
		tempLightRay.setRayDirectionUni(allDirectionsImaSurface_traceBack[i]);
		lightRayTraceBack_vec[i] = tempLightRay;
	}

	seqTraceBack.clearAllTracedRays();
	seqTraceBack.seqRayTracingWithVectorOfLightRays(lightRayTraceBack_vec);

	std::vector<real> allDistancesTraceBack = seqTraceBack.getAllDistancesSurface_i(0);
	std::vector<VectorStructR3> allInterpointsAtRefSphere = seqTraceBack.getAllInterPointsAtSurface_i_filtered(0);

	std::vector<real> totalDistances(allDistancesTraceBack.size());
	
	for (unsigned int i = 0; i < allDistancesTraceBack.size(); ++i)
	{
		totalDistances[i] = allDistancesTraceForward[i] - allDistancesTraceBack[i];
	}

	calcAllOPDs(referenceLenght, totalDistances);

	PX_PY_MX_MY saveInfosAboutOPD;
	saveInfosAboutOPD.calcAllPositionRegardsToChiefRay(allInterpointsAtRefSphere, mSizeMatrix);

	// save all OPD in matrix
	saveAllOPDsInMatrix(saveInfosAboutOPD.getAll_MX(), saveInfosAboutOPD.getAll_MY());

}

void OPD::calcGlobalOPD_new_LEFT_SideOfImaSurface_inf(real positionExitPupil_global)
{
	real refIndexStartMedia = calcRefractivIndexStartMedia(mOptSys);

	unsigned int sizeOptSys = mOptSys.getPosAndInteractingSurface().size();

	// get refractiv index before exit pupil
	real refIndexBeforeExitPupil{};
	unsigned int posSurfaceBeforeExitPupil{};
	unsigned int positionExitPupilInOptSys = calcPosExPupil_Z(mOptSys, positionExitPupil_global);
	if (positionExitPupilInOptSys == 0)
	{
		posSurfaceBeforeExitPupil = 0;
	}
	else
	{
		posSurfaceBeforeExitPupil = positionExitPupilInOptSys - 1;
	}

	real directionSurfaceBeforeExitPupil = mOptSys.getPosAndInteractingSurface()[posSurfaceBeforeExitPupil].getSurfaceInterRay_ptr()->getDirection().getZ();

	if (directionSurfaceBeforeExitPupil > 0)
	{
		refIndexBeforeExitPupil = mOptSys.getPosAndInteractingSurface()[posSurfaceBeforeExitPupil].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}
	else
	{
		refIndexBeforeExitPupil = mOptSys.getPosAndInteractingSurface()[posSurfaceBeforeExitPupil].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
	}
	// ***

	// get refractiv index before image surface

	real directionImaSurface = mOptSys.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getDirection().getZ();
	real refIndexBeforeImageSurface{};

	if (directionImaSurface > 0)
	{
		refIndexBeforeImageSurface = mOptSys.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}

	else
	{
		refIndexBeforeImageSurface = mOptSys.getPosAndInteractingSurface()[sizeOptSys - 1].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}




	// get refractiv index after exit pupil
	real refIndexAfterExitPupil{};
	real directionSurfaceAfterExitPupil = mOptSys.getPosAndInteractingSurface()[positionExitPupilInOptSys].getSurfaceInterRay_ptr()->getDirection().getZ();
	if (directionSurfaceAfterExitPupil > 0)
	{
		refIndexAfterExitPupil = mOptSys.getPosAndInteractingSurface()[positionExitPupilInOptSys].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
	}
	else
	{
		refIndexAfterExitPupil = mOptSys.getPosAndInteractingSurface()[positionExitPupilInOptSys].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}
	// ***

	PlanGeometry_LLT exitPupilPlan(/*semiHeight*/oftenUse::getInfReal(), /*point*/{ 0.0,0.0,positionExitPupil_global }, /*direction*/{ 0.0,0.0,1.0 }, /*refractiveSideA*/ refIndexBeforeExitPupil, /*refractiveSideB*/ refIndexAfterExitPupil);


	// first aimed ray must be chiefLightRay
	//LightRayStruct chiefLightRay = mAimedLightRay[0];

	VectorStructR3 startPointChiefRayInf{};
	RayAiming rayAiming(mOptSys);
	rayAiming.setTolerance_XandY(mLoadParaOPD.getToleranceForRayAiming());
	LightRayStruct chiefLightRay{};

	if (mLoadParaOPD.getFirstAimedRayIsChiefRay())
	{
		chiefLightRay = mAimedLightRay[0];
		startPointChiefRayInf = chiefLightRay.getRay_LLT().getOriginRay();
		rayAiming.setStartPointRayToInf(chiefLightRay);
	}

	else
	{
		// build cheif ray
		real refIndexStartMedia = oftenUse::getStartRefIndex(mOptSys);
		infosAS infosApertureStop = mOptSys.getInforAS();
		chiefLightRay = rayAiming.rayAiming_inf(mLoadParaOPD.getFieldAngleChiefRay_X(), mLoadParaOPD.getFieldAngleChiefRay_Y(), infosApertureStop.getPointAS(), mLight, refIndexStartMedia);
		rayAiming.setStartPointRayToInf(chiefLightRay);

		startPointChiefRayInf = chiefLightRay.getRay_LLT().getOriginRay();
	}

	// Ray Aiming
	rayAiming.loadDefaultParameter();
	rayAiming.setLoadImportantDefaulParameterRayAiming(false);
	rayAiming.setFactor_obj(mLoadParaOPD.getFactorForRayAimingIfObjInInf());
	mAimedLightRay = rayAiming.rayAimingMany_obj_complete(mOptSys, mPointsInAS, startPointChiefRayInf, mLight);

	mOptSysWithExitPupilPlan = mOptSys.clone();

	TraceLightRayBack traceBack;
	DoNothingInteraction_LLT doNothing;

	real prefixForRayTracing = 1.0;

	//hier
	if (positionExitPupilInOptSys == 0)
	{

		if (positionExitPupil_global < chiefLightRay.getRay_LLT().getOriginRay().getZ())
		{
			oftenUse::errorProtocol_stopSystem("start point of ray is not in neg infinity!", "OpticalPathDifference", 0, true);
		}

		else
		{
			mOptSysWithExitPupilPlan.fillInSurfaceAndInteracAtPos_i(positionExitPupilInOptSys, exitPupilPlan.clone(), doNothing.clone());
		}
	}

	else
	{
		mOptSysWithExitPupilPlan.fillInSurfaceAndInteracAtPos_i(positionExitPupilInOptSys, exitPupilPlan.clone(), doNothing.clone());
	}



	SequentialRayTracing seqTraceToImaSurface(mOptSysWithExitPupilPlan);
	seqTraceToImaSurface.sequentialRayTracing(chiefLightRay);
	// check for lost rays
	if (seqTraceToImaSurface.getLoosingRays()) oftenUse::errorProtocol_stopSystem("loosing ray", "calcGlobalOPD_new_LEFT_SideOfImaSurface - 1", 0, true);

	VectorStructR3 interPointChiefRayImaSurface = seqTraceToImaSurface.getAllInterPointsAtSurface_i_filtered(sizeOptSys)[0];
	VectorStructR3 interPointChiefRayAtExitPupil = seqTraceToImaSurface.getAllInterPointsAtSurface_i_filtered(positionExitPupilInOptSys)[0];
	VectorStructR3 directionRefSphere = interPointChiefRayImaSurface - interPointChiefRayAtExitPupil;

	real RadiusRefSphere = Math::lengthOfVector(directionRefSphere);

	// building optical system with refSphere at exit pupil
	SphericalSurface_LLT RefSpherAtExitPupilPlanExP(/*radius*/RadiusRefSphere, /*semiHeight*/oftenUse::getInfReal(), /*Apex of the sphere*/interPointChiefRayAtExitPupil, /*Direction*/ directionRefSphere, /*refIndexSideA*/refIndexBeforeImageSurface, /*refIndexSideB*/refIndexBeforeImageSurface);
	mOptSysWithReferenceSphere.fillVectorSurfaceAndInteractingData(0, RefSpherAtExitPupilPlanExP.clone(), doNothing.clone());

	// calculate referece distance
	real length_1_chief = seqTraceToImaSurface.getInterInf_PosSurface_TotalSteps_ofSur_i(sizeOptSys)[0].getTotalSteps();
	if (positionExitPupil_global < mAimedLightRay[0].getRay_LLT().getOriginRay().getZ())
	{
		real firstLength = seqTraceToImaSurface.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[0].getTotalSteps();
		length_1_chief = length_1_chief - 2.0 * firstLength;
	}

	// build light ray to trace back
	Ray_LLT chiefRayToTraceBack(/*origin*/ interPointChiefRayImaSurface,/*direction*/ -1.0 * directionRefSphere,/*refractive index*/ refIndexBeforeImageSurface);
	LightRayStruct chiefLightRay_back(mAimedLightRay[0].getLight_LLT(), chiefRayToTraceBack, true);
	SequentialRayTracing seqTraceBack(mOptSysWithReferenceSphere);
	seqTraceBack.sequentialRayTracing(chiefLightRay_back);
	// check for lost rays
	if (seqTraceBack.getLoosingRays()) oftenUse::errorProtocol_stopSystem("loosing ray", "calcGlobalOPD_new_LEFT_SideOfImaSurface - 2", 0, true);;

	real lenght_2_chief = seqTraceBack.getInterInf_PosSurface_TotalSteps_ofSur_i(0)[0].getTotalSteps();

	real referenceLenght = length_1_chief - lenght_2_chief;

	// seq tracing to ima surface
	SequentialRayTracing seqTraceWantedRay(mOptSys);
	seqTraceWantedRay.seqRayTracingWithVectorOfLightRays(mAimedLightRay);
	// check for lost rays
	if (seqTraceWantedRay.getLoosingRays()) oftenUse::errorProtocol_stopSystem("loosing ray", "calcGlobalOPD_new_LEFT_SideOfImaSurface - 3", 0, true);;

	std::vector<real> allDistancesTraceForward = seqTraceWantedRay.getAllDistancesSurface_i(sizeOptSys - 1);

	// trace all rays back to ima surface
	std::vector<VectorStructR3> allInterPointsImaSurface = seqTraceWantedRay.getAllInterPointsAtSurface_i_filtered(sizeOptSys - 1);
	std::vector<VectorStructR3> allDirectionsImaSurface = seqTraceWantedRay.getAllDirectionsAtSurface_i_filtered(sizeOptSys - 1);
	std::vector<VectorStructR3> allDirectionsImaSurface_traceBack = -1.0 * allDirectionsImaSurface;

	// build light rays to trace back
	std::vector<LightRayStruct> lightRayTraceBack_vec{};
	lightRayTraceBack_vec.resize(allInterPointsImaSurface.size());
	Light_LLT light = mAimedLightRay[0].getLight_LLT();
	LightRayStruct tempLightRay;
	tempLightRay.setIsAlive(true);
	tempLightRay.setLight_LLT(light);

	tempLightRay.setCurrentRefractivIndex(refIndexBeforeImageSurface);
	for (unsigned int i = 0; i < allInterPointsImaSurface.size(); ++i)
	{

		tempLightRay.setRayOrigin(allInterPointsImaSurface[i]);
		tempLightRay.setRayDirectionUni(allDirectionsImaSurface_traceBack[i]);
		lightRayTraceBack_vec[i] = tempLightRay;
	}

	seqTraceBack.clearAllTracedRays();
	seqTraceBack.seqRayTracingWithVectorOfLightRays(lightRayTraceBack_vec);

	std::vector<real> allDistancesTraceBack = seqTraceBack.getAllDistancesSurface_i(0);
	std::vector<VectorStructR3> allInterpointsAtRefSphere = seqTraceBack.getAllInterPointsAtSurface_i_filtered(0);

	std::vector<real> totalDistances(allDistancesTraceBack.size());

	for (unsigned int i = 0; i < allDistancesTraceBack.size(); ++i)
	{
		totalDistances[i] = allDistancesTraceForward[i] - allDistancesTraceBack[i];
	}

	calcAllOPDs(referenceLenght, totalDistances);

	PX_PY_MX_MY saveInfosAboutOPD;
	saveInfosAboutOPD.calcAllPositionRegardsToChiefRay(allInterpointsAtRefSphere, mSizeMatrix);

	// save all OPD in matrix
	saveAllOPDsInMatrix(saveInfosAboutOPD.getAll_MX(), saveInfosAboutOPD.getAll_MY());
}

void OPD::calcGlobalOPD_new_Right_SideOfImaSurface_inf(real positionExitPupil_global)
{
	VectorStructR3 startPointChiefRayInf{};
	RayAiming rayAiming(mOptSys);
	rayAiming.setTolerance_XandY(mLoadParaOPD.getToleranceForRayAiming());
	LightRayStruct chiefLightRay{};

	if (mLoadParaOPD.getFirstAimedRayIsChiefRay())
	{
		chiefLightRay = mAimedLightRay[0];
		startPointChiefRayInf = chiefLightRay.getRay_LLT().getOriginRay();
		rayAiming.setStartPointRayToInf(chiefLightRay);
	}

	else
	{
		// build cheif ray
		real refIndexStartMedia = oftenUse::getStartRefIndex(mOptSys);
		infosAS infosApertureStop = mOptSys.getInforAS();
		chiefLightRay = rayAiming.rayAiming_inf(mLoadParaOPD.getFieldAngleChiefRay_X(), mLoadParaOPD.getFieldAngleChiefRay_Y(), infosApertureStop.getPointAS(), mLight, refIndexStartMedia);
		rayAiming.setStartPointRayToInf(chiefLightRay);

		startPointChiefRayInf = chiefLightRay.getRay_LLT().getOriginRay();
	}

	// Ray Aiming
	rayAiming.loadDefaultParameter();
	rayAiming.setLoadImportantDefaulParameterRayAiming(false);
	rayAiming.setFactor_obj(mLoadParaOPD.getFactorForRayAimingIfObjInInf());
	mAimedLightRay = rayAiming.rayAimingMany_obj_complete(mOptSys, mPointsInAS, startPointChiefRayInf, mLight);
 

	// build the optical system with the exit pupil plan
	buildOpticalSystemWithExitPupilPlan_rightSide(positionExitPupil_global);

	// collect infomrations to build optical system including reference sphere
	SequentialRayTracing seqTraceToExitPupilPlan(mOptSysWithExitPupilPlan);
	seqTraceToExitPupilPlan.sequentialRayTracing(chiefLightRay);
	// check for lost rays
	if (seqTraceToExitPupilPlan.getLoosingRays())
	{
		oftenUse::errorProtocol_stopSystem("loosing ray", "calcGlobalOPD_new_Right_SideOfImaSurface - 1", 0, true);
	}



	unsigned int positionExitPupil = mOptSysWithExitPupilPlan.getPosAndInteractingSurface().size() - 1;
	VectorStructR3 interPointChiefRayImaSurface = seqTraceToExitPupilPlan.getAllInterPointsAtSurface_i_filtered(positionExitPupil - 1)[0];
	VectorStructR3 interPointChiefRayAtExitPupil = seqTraceToExitPupilPlan.getAllInterPointsAtSurface_i_filtered(positionExitPupil)[0];
	VectorStructR3 directionRefSphere = interPointChiefRayImaSurface - interPointChiefRayAtExitPupil;

	real RadiusRefSphere = Math::lengthOfVector(directionRefSphere);

	// reference distance
	real referenceDistance = seqTraceToExitPupilPlan.getInterInf_PosSurface_TotalSteps_ofSur_i(positionExitPupil)[0].getTotalSteps();

	// build the optical system including reference sphere at exit pupil
	buildOpticalSystemWithReferenceSphereAtExitPupil_rightSide(RadiusRefSphere, interPointChiefRayAtExitPupil, directionRefSphere);

	// trace many ray to fill matrix with OPDs
	SequentialRayTracing seqTrace(mOptSysWithReferenceSphere);
	seqTrace.seqRayTracingWithVectorOfLightRays(mAimedLightRay);
	// check for lost rays
	if (seqTrace.getLoosingRays()) oftenUse::errorProtocol_stopSystem("loosing ray", "calcGlobalOPD_new_Right_SideOfImaSurface - 2", 0, true);


	// save all datas to fill matrix with OPD
	std::vector<real> allDistances = seqTrace.getAllDistancesSurface_i(positionExitPupil);
	std::vector<VectorStructR3> allInterpointsAtRefSphere = seqTrace.getAllInterPointsAtSurface_i_filtered(positionExitPupil);

	calcAllOPDs(referenceDistance, allDistances);

	PX_PY_MX_MY saveInfosAboutOPD;
	saveInfosAboutOPD.calcAllPositionRegardsToChiefRay(allInterpointsAtRefSphere, mSizeMatrix);

	// save all OPD in matrix
	saveAllOPDsInMatrix(saveInfosAboutOPD.getAll_MX(), saveInfosAboutOPD.getAll_MY());

}

LightRayStruct OPD::getWantedLightRay()
{
	return mWantedLightRay;
}

// calc reference distance for OPD
real OPD::calcRefDisForRefSphere()
{

	SequentialRayTracing seqTrace1(mOptSys);
	seqTrace1.sequentialRayTracing(mChiefLightRay);
	mChiefRayAtImage = seqTrace1.getAllInterPointsAtSurf_i_notFiltered(mPosImageSurface).at(0);
	SequentialRayTracing seqTrace2(mOptSysWithExitPupilPlan);
	seqTrace2.sequentialRayTracing(mChiefLightRay);
	mChiefRayAtExitPupil = seqTrace2.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys).at(0);
	real refDistanceForRefSphere = Math::distanceTwoVectors(mChiefRayAtImage, mChiefRayAtExitPupil);

	return refDistanceForRefSphere;
}

// get reference point
VectorStructR3 OPD::getRefPoints()
{
	return mRefPoint;
}
// calc reference distance to calculat OPD
real OPD::calcRefDisForOPD()
{

	SequentialRayTracing seqTrace(mOptSys);
	seqTrace.sequentialRayTracing(mChiefLightRay);
	unsigned int numImaSurface = mOptSys.getNumberOfSurfaces();
	numImageSurfaceWithoutExitPupil = numImaSurface;
	mTotalStepsToImageSurfaceRef = seqTrace.getInterInf_PosSurface_TotalSteps_ofSur_i(numImaSurface).at(0).getTotalSteps();

	// ref point
	mRefPoint = seqTrace.getInterInf_PosSurface_TotalSteps_ofSur_i(numImaSurface).at(0).getIntersecInfos().getIntersectionPoint();

	real dis2 = mRadiusRefSphere;
	real returnDis;

	if (numImaSurface > mPosExPupilInOptSys)
	{
		returnDis = mTotalStepsToImageSurfaceRef - dis2;
	}

	else
	{
		returnDis = mTotalStepsToImageSurfaceRef + dis2;
	}

	return returnDis;
}

// calc OPD in X direction
std::vector<cv::Point2d> OPD::calcOPD_X()
{
	Absorb_LLT Absorb;
	std::vector<cv::Point2d> returnOPD_X;

	// check if the exit pupil is behind the image surface
	if (mPosImageSurface <= mPosExPupilInOptSys)
	{
		// fill in reference sphere
		OpticalSystem_LLT OptSysWithRefSphere;
		OptSysWithRefSphere = mOptSys;
		OptSysWithRefSphere.fillInSurfaceAndInteracAtPos_i(mPosExPupilInOptSys, mRefSphere.clone(), mDoNothingInter.clone());

		SequentialRayTracing seqTraceRefSphere(OptSysWithRefSphere);
		seqTraceRefSphere.seqRayTracingWithVectorOfLightRays(mLightRayX);

		SequentialRayTracing seqTraceExitPup(mOptSysWithExitPupilPlan);
		seqTraceExitPup.seqRayTracingWithVectorOfLightRays(mLightRayX);

		for (unsigned int i = 0; i < seqTraceRefSphere.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys).size(); i++)
		{
			// according to ZEMAX we give the OPD in the wavelenth unitof the chief ray
			real tempOPD = ((mRefDistance - seqTraceRefSphere.getInterInf_PosSurface_TotalSteps_ofSur_i(mPosExPupilInOptSys).at(i).getTotalSteps()) / mChiefLightRay.getLight_LLT().getWavelength()) * 1000000;

			cv::Point2d tempPoint(mChiefRayAtExitPupil.getX() - seqTraceExitPup.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys).at(i).getX(), tempOPD);
			returnOPD_X.push_back(tempPoint);
		}

		return returnOPD_X;
	}

	SequentialRayTracing seqTrace(mOptSys);
	SequentialRayTracing seqTraceWithExitPupil(mOptSysWithExitPupilPlan);
	// trace all ray
	seqTrace.seqRayTracingWithVectorOfLightRays(mLightRayX);
	seqTraceWithExitPupil.seqRayTracingWithVectorOfLightRays(mLightRayX);
	// save all total steps to image (last) surface
	std::vector<real> totalStepsToImageSurface = seqTrace.getTotalOptPathLenthToSurface_i(mPosImageSurface);
	std::vector<VectorStructR3> posInExitPupilForEveryRay = seqTraceWithExitPupil.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys);
	// *** passt
	OpticalSystem_LLT OptSysOPDX;
	OptSysOPDX.fillVectorSurfaceAndInteractingData(0, mRefSphere.clone(), Absorb.clone());
	// *** passt
	std::vector<LightRayStruct> LightRaysToTraceBack;
	Ray_LLT ray;
	Light_LLT light;
	LightRayStruct lightRay(light, ray, 1);
	std::vector<VectorStructR3> posInExitPupil;




	// build light rays to trace back and save position in exit pupil
	for (unsigned int i = 0; i < seqTrace.getInterInf_PosSurface_TotalSteps_ofSur_i(mPosImageSurface).size(); i++)
	{
		VectorStructR3 tempOrigin = seqTrace.getAllInterPointsAtSurf_i_notFiltered(mPosImageSurface).at(i);
		VectorStructR3 tempDirection = -1 * seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getDirectionRayUnit(); // direction to trace back
		real tempWavelenth = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getLight().getWavelength();
		surfaceSide tempSurSide = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getSurfaceSide();
		real tempCurRefIndex;

		// check from witch side the ray interact with the exit pupil
		if (tempSurSide == A)
		{
			tempCurRefIndex = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getRefractiveIndex_A();
		}

		else if (tempSurSide == B)
		{
			tempCurRefIndex = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getRefractiveIndex_B();
		}

		else // there must be a mistake!!!
		{
			std::cout << "there is a mistake in calculating the OPD!" << std::endl;
		}

		Ray_LLT tempRay(tempOrigin, tempDirection, tempCurRefIndex);
		lightRay.setRay_LLT(tempRay);
		light.setWavelength(tempWavelenth);
		lightRay.setLight_LLT(light);
		LightRaysToTraceBack.push_back(lightRay);
	}

	SequentialRayTracing seqTraceBack(OptSysOPDX);
	seqTraceBack.seqRayTracingWithVectorOfLightRays(LightRaysToTraceBack);
	std::vector<real> totalSteps;

	for (unsigned int i = 0; i < seqTraceBack.getAllInterInfosOfSurf_i(0).size(); i++)
	{
		real tempDisObToIm = totalStepsToImageSurface.at(i);
		real tempDisImToRefSphere = seqTraceBack.getAllInterInfosOfSurf_i(0).at(i).getStepsToWalk();
		totalSteps.push_back(tempDisObToIm - tempDisImToRefSphere);
	}

	cv::Point2d OPDinOnePoint;

	// the x value is the position in the exit pupil and the y value is the OPD 
	// save OPD and position in exit pupil
	for (unsigned int i = 0; i < totalSteps.size(); i++)
	{
		OPDinOnePoint.x = posInExitPupilForEveryRay.at(i).getX();
		// according to ZEMAX we give the OPD in the wavelenth unitof the chief ray
		OPDinOnePoint.y = ((mRefDistance - totalSteps.at(i)) / mChiefLightRay.getLight_LLT().getWavelength()) * 1000;
		returnOPD_X.push_back(OPDinOnePoint);
	}


	return returnOPD_X;
}

// calc OPD in Y direction
std::vector<cv::Point2d> OPD::calcOPD_Y()
{
	Absorb_LLT Absorb;
	std::vector<cv::Point2d> returnOPD_Y;

	// check if the exit pupil is behind the image surface
	if (mPosImageSurface <= mPosExPupilInOptSys)
	{
		// fill in reference sphere
		OpticalSystem_LLT OptSysWithRefSphere;
		OptSysWithRefSphere = mOptSys;
		OptSysWithRefSphere.fillInSurfaceAndInteracAtPos_i(mPosExPupilInOptSys, mRefSphere.clone(), mDoNothingInteraction_ptr);

		SequentialRayTracing seqTraceRefSphere(OptSysWithRefSphere); // optical system include referece sphere
		seqTraceRefSphere.seqRayTracingWithVectorOfLightRays(mLightRayY);

		SequentialRayTracing seqTraceExitPup(mOptSysWithExitPupilPlan); // optical system include exit pupil (plan surface)
		seqTraceExitPup.seqRayTracingWithVectorOfLightRays(mLightRayY);

		for (unsigned int i = 0; i < seqTraceRefSphere.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys).size(); i++)
		{
			// according to ZEMAX we give the OPD in the wavelenth unit of the chief ray
			real tempOPD = ((mRefDistance - seqTraceRefSphere.getInterInf_PosSurface_TotalSteps_ofSur_i(mPosExPupilInOptSys).at(i).getTotalSteps()) / mChiefLightRay.getLight_LLT().getWavelength()) * 1000000;

			cv::Point2d tempPoint(mChiefRayAtExitPupil.getY() - seqTraceRefSphere.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys).at(i).getY(), tempOPD);
			returnOPD_Y.push_back(tempPoint);
		}

		return returnOPD_Y;
	}

	// exit pupil is not behind the image surface
	SequentialRayTracing seqTrace(mOptSys);
	SequentialRayTracing seqTraceWithExitPupil(mOptSysWithExitPupilPlan);
	// trace all ray
	seqTrace.seqRayTracingWithVectorOfLightRays(mLightRayY);
	seqTraceWithExitPupil.seqRayTracingWithVectorOfLightRays(mLightRayY);
	// save all total steps to image (last) surface
	std::vector<real> totalStepsToImageSurface = seqTrace.getTotalOptPathLenthToSurface_i(mPosImageSurface);
	std::vector<VectorStructR3> posInExitPupilForEveryRay = seqTraceWithExitPupil.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys);
	// *** passt
	OpticalSystem_LLT OptSysOPDY;
	OptSysOPDY.fillVectorSurfaceAndInteractingData(0, &mRefSphere, Absorb.clone());
	// *** passt
	std::vector<LightRayStruct> LightRaysToTraceBack;
	Ray_LLT ray;
	Light_LLT light;
	LightRayStruct lightRay(light, ray, 1);
	std::vector<VectorStructR3> posInExitPupil;

	// bild light rays to trace back and save position in exit pupil
	for (unsigned int i = 0; i < seqTrace.getInterInf_PosSurface_TotalSteps_ofSur_i(mPosImageSurface).size(); i++)
	{
		VectorStructR3 tempOrigin = seqTrace.getAllInterPointsAtSurf_i_notFiltered(mPosImageSurface).at(i);
		VectorStructR3 tempDirection = -1 * seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getDirectionRayUnit(); // direction to trace back
		real tempWavelenth = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getLight().getWavelength();
		surfaceSide tempSurSide = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getSurfaceSide();
		real tempCurRefIndex;

		// check from witch side the ray interact with the exit pupil
		if (tempSurSide == A)
		{
			tempCurRefIndex = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getRefractiveIndex_A();
		}

		else if (tempSurSide == B)
		{
			tempCurRefIndex = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getRefractiveIndex_B();
		}

		else // there must be a mistake!!!
		{
			std::cout << "there is a mistake in calculating the OPD!" << std::endl;
		}

		Ray_LLT tempRay(tempOrigin, tempDirection, tempCurRefIndex);
		lightRay.setRay_LLT(tempRay);
		light.setWavelength(tempWavelenth);
		lightRay.setLight_LLT(light);
		LightRaysToTraceBack.push_back(lightRay);
	}


	SequentialRayTracing seqTraceBack(OptSysOPDY);
	seqTraceBack.seqRayTracingWithVectorOfLightRays(LightRaysToTraceBack);
	std::vector<real> totalSteps;

	// save the total steps (distance obj to image - distance image to referece sphere)
	for (unsigned int i = 0; i < seqTraceBack.getAllInterInfosOfSurf_i(0).size(); i++)
	{
		real tempDisObToIm = totalStepsToImageSurface.at(i);
		real tempDisImToRefSphere = seqTraceBack.getAllInterInfosOfSurf_i(0).at(i).getStepsToWalk();
		totalSteps.push_back(tempDisObToIm - tempDisImToRefSphere);
	}

	cv::Point2d OPDinOnePoint;

	// the x value is the position in the exit pupil and the y value is the OPD 
	// save OPD and position in exit pupil
	for (unsigned int i = 0; i < totalSteps.size(); i++)
	{

		OPDinOnePoint.x = posInExitPupilForEveryRay.at(i).getY();
		// according to ZEMAX we give the OPD in the wavelenth unitof the chief ray
		OPDinOnePoint.y = ((mRefDistance - totalSteps.at(i)) / mChiefLightRay.getLight_LLT().getWavelength()) * 1000;
		returnOPD_Y.push_back(OPDinOnePoint);
	}


	return returnOPD_Y;
}




// get position of exit pupil in optical system
unsigned int OPD::getPosExPupilInOptSys()
{
	return mPosExPupilInOptSys;
}

// get points OPD in Y direction
std::vector<cv::Point2d> OPD::getPointsOPD_Y()
{
	return mOPD_Y;
}

// get points in X direction
std::vector<cv::Point2d> OPD::getPointsOPD_X()
{
	return mOPD_X;
}



// get OPD X in std::vector
std::vector<real> OPD::getOPD_X_inVec()
{
	std::vector<real> outputOPD_X;
	for (unsigned int i = 0; i < mOPD_X.size(); i++)
	{
		outputOPD_X.push_back(mOPD_X.at(i).y);
	}

	return outputOPD_X;
}

// get OPD Y in std::vector
std::vector<real> OPD::getOPD_Y_inVec()
{
	std::vector<real> outputOPD_Y;
	for (unsigned int i = 0; i < mOPD_Y.size(); i++)
	{
		outputOPD_Y.push_back(mOPD_Y.at(i).y);
	}

	return outputOPD_Y;
}

//// calc global optical path difference 
//cv::Mat OPD::calcGlobalOPD()
//{
//
//
//	{
//		// fill in reference sphere
//		OpticalSystem_LLT OptSysWithRefSphere;
//		OptSysWithRefSphere = mOptSys;
//		OptSysWithRefSphere.fillInSurfaceAndInteracAtPos_i(mPosExPupilInOptSys, mRefSphere.clone(), mDoNothingInteraction_ptr);
//
//		SequentialRayTracing seqTraceRefSphere(OptSysWithRefSphere); // optical system include referece sphere
//		seqTraceRefSphere.seqRayTracingWithVectorOfLightRays(mLightRayFillAperturStop);
//
//		SequentialRayTracing seqTraceExitPup(mOptSysWithExitPupilPlan); // optical system include exit pupil (plan surface)
//		seqTraceExitPup.seqRayTracingWithVectorOfLightRays(mLightRayFillAperturStop);
//
//		std::vector<real> vectorXvalues;
//		std::vector<real> vectorYvalues;
//
//
//
//		for (unsigned int i = 0; i < seqTraceRefSphere.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys).size(); i++)
//		{
//			// get all X values of the intersection points at the exitpupil (ref sphere)
//			real tempXvalue = mChiefRayAtExitPupil.getX() - seqTraceRefSphere.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys).at(i).getX();
//
//			vectorXvalues.push_back(tempXvalue);
//
//			// get all Y values of the intersection points at the exitpupil (ref sphere)
//			real tempYvalue = mChiefRayAtExitPupil.getY() - seqTraceRefSphere.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys).at(i).getY();
//			vectorYvalues.push_back(tempYvalue);
//		}
//
//		real maxValueInX_Direction = Math::maxValueOfVactor(vectorXvalues);
//		real minValueInX_Direction = Math::minValueOfVector(vectorXvalues);
//		real maxValueInY_Direction = Math::maxValueOfVactor(vectorYvalues);
//		real minValueInY_Direction = Math::minValueOfVector(vectorYvalues);
//
//		switch (mScaling)
//		{
//		case 0:
//		{
//			real maxABSValueInX_Direction = maxValueInX_Direction;
//			if (maxValueInX_Direction < std::abs(minValueInX_Direction))
//			{
//				maxABSValueInX_Direction = std::abs(minValueInX_Direction);
//			}
//
//			real maxABSValueInY_Direction = maxValueInY_Direction;
//			if (maxValueInY_Direction < std::abs(minValueInY_Direction))
//			{
//				maxABSValueInY_Direction = std::abs(minValueInY_Direction);
//			}
//
//			for (unsigned int i = 0; i < seqTraceRefSphere.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys).size(); i++)
//			{
//				// according to ZEMAX we give the OPD in the wavelenth unit of the chief ray
//				real tempOPD = ((mRefDistance - seqTraceRefSphere.getInterInf_PosSurface_TotalSteps_ofSur_i(mPosExPupilInOptSys).at(i).getTotalSteps()) / mChiefLightRay.getLight_LLT().getWavelength()) * 1000000;
//
//				//***
//				// just for debugging
//				mVecWithAllCalcGlobalOPD.push_back(tempOPD);
//				//***
//
//
//				real scalePositionTempOPD_X = vectorXvalues.at(i) / maxABSValueInX_Direction;
//				real scalePositionTempOPD_Y = vectorYvalues.at(i) / maxABSValueInY_Direction;
//
//				// fill the matrix with the OPD valus
//				int matrixScalePosTempOPD_X = sizeOfMatrixToCalcOPD / 2 + scalePositionTempOPD_X * sizeOfMatrixToCalcOPD / 2;
//				//std::cout << matrixScalePosTempOPD_X << std::endl ;
//				//std::cout << "pos OPD X " << matrixScalePosTempOPD_X << std::endl;
//
//				int matrixScalePosTempOPD_Y = sizeOfMatrixToCalcOPD / 2 - scalePositionTempOPD_Y * sizeOfMatrixToCalcOPD / 2;
//				//std::cout << matrixScalePosTempOPD_Y << std::endl;
//				//std::cout << "pos OPD Y " << matrixScalePosTempOPD_Y << std::endl;
//				//std::cout << std::endl;
//				// hier gehts weiter!!!
//
//				returnGlobalOPD.at<real>(matrixScalePosTempOPD_Y, matrixScalePosTempOPD_X) = tempOPD;
//
//			}
//
//
//		}
//		break;
//
//
//		case 1:
//		{
//			// the case for mScaling = 1 is not testet!!! TODO: test it!!!
//			std::cout << "mScaling = 1 is not testet!!! We have to do this in the future!!!" << std::endl;
//			for (unsigned int i = 0; i < seqTraceRefSphere.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys).size(); i++)
//			{
//				// according to ZEMAX we give the OPD in the wavelenth unit of the chief ray
//				real tempOPD = ((mRefDistance - seqTraceRefSphere.getInterInf_PosSurface_TotalSteps_ofSur_i(mPosExPupilInOptSys).at(i).getTotalSteps()) / mChiefLightRay.getLight_LLT().getWavelength()) * 1000000;
//
//				//***
//				// just for debugging
//				mVecWithAllCalcGlobalOPD.push_back(tempOPD);
//				//***
//				real scalePositionTempOPD_X;
//				real scalePositionTempOPD_Y;
//				if (vectorXvalues.at(i) > 0)
//				{
//					scalePositionTempOPD_X = vectorXvalues.at(i) / maxValueInX_Direction;
//				}
//				else
//				{
//					scalePositionTempOPD_X = vectorXvalues.at(i) / std::abs(minValueInX_Direction);
//				}
//				if (vectorYvalues.at(i) > 0)
//				{
//					scalePositionTempOPD_Y = vectorYvalues.at(i) / maxValueInY_Direction;
//				}
//				else
//				{
//					scalePositionTempOPD_Y = vectorYvalues.at(i) / std::abs(minValueInY_Direction);
//				}
//
//				//real scalePositionTempOPD_X = vectorXvalues.at(i) / maxABSValueInX_Direction;
//				//real scalePositionTempOPD_Y = vectorYvalues.at(i) / maxABSValueInY_Direction;
//
//				// fill the matrix with the OPD valus
//				int matrixScalePosTempOPD_X = sizeOfMatrixToCalcOPD / 2 + scalePositionTempOPD_X * sizeOfMatrixToCalcOPD / 2;
//				//std::cout << matrixScalePosTempOPD_X << std::endl ;
//				//std::cout << "pos OPD X " << matrixScalePosTempOPD_X << std::endl;
//
//				int matrixScalePosTempOPD_Y = sizeOfMatrixToCalcOPD / 2 - scalePositionTempOPD_Y * sizeOfMatrixToCalcOPD / 2;
//				//std::cout << matrixScalePosTempOPD_Y << std::endl;
//				//std::cout << "pos OPD Y " << matrixScalePosTempOPD_Y << std::endl;
//				//std::cout << std::endl;
//				// hier gehts weiter!!!
//
//				returnGlobalOPD.at<real>(matrixScalePosTempOPD_Y, matrixScalePosTempOPD_X) = tempOPD;
//
//			}
//
//		}
//		break;
//
//		default: std::cout << "scalling can be 0 or 1;" << std::endl;
//			break;
//		}
//
//
//
//		//mGlobalOPD = returnGlobalOPD;
//
//		// we need that for debugging
//		//exportCV_MatToExcel(mGlobalOPD, "D:\OPDglobalE1_Field.csv");
//
//		return returnGlobalOPD;
//	}
//	//***
//	// exit pupil is not behind the image surface
//	//***
//	else 
//	{
//		SequentialRayTracing seqTrace(mOptSys);
//		SequentialRayTracing seqTraceWithExitPupil(mOptSysWithExitPupilPlan);
//		// trace all ray
//		seqTrace.seqRayTracingWithVectorOfLightRays(mLightRayFillAperturStop);
//		seqTraceWithExitPupil.seqRayTracingWithVectorOfLightRays(mLightRayFillAperturStop);
//		// save all total steps to image (last) surface
//		std::vector<real> totalStepsToImageSurface = seqTrace.getTotalOptPathLenthToSurface_i(mPosImageSurface);
//		std::vector<VectorStructR3> posInExitPupilForEveryRay = seqTraceWithExitPupil.getAllInterPointsAtSurf_i_notFiltered(mPosExPupilInOptSys);
//		OpticalSystem_LLT OptSysOPDglobal;
//		Absorb_LLT Absorb;
//		OptSysOPDglobal.fillVectorSurfaceAndInteractingData(0, &mRefSphere, Absorb.clone());
//		std::vector<LightRayStruct> LightRaysToTraceBack;
//		//Ray_LLT ray;
//		//Light_LLT light;
//		LightRayStruct lightRay;
//		Light_LLT light;
//		std::vector<VectorStructR3> posInExitPupil;
//
//		// bild light rays to trace back and save position in exit pupil
//		for (unsigned int i = 0; i < seqTrace.getInterInf_PosSurface_TotalSteps_ofSur_i(mPosImageSurface).size(); i++)
//		{
//			VectorStructR3 tempOrigin = seqTrace.getAllInterPointsAtSurf_i_notFiltered(mPosImageSurface).at(i);
//			VectorStructR3 tempDirection = -1 * seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getDirectionRayUnit(); // direction to trace back
//			real tempWavelenth = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getLight().getWavelength();
//			surfaceSide tempSurSide = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getSurfaceSide();
//			real tempCurRefIndex;
//
//			// check from witch side the ray interact with the exit pupil
//			if (tempSurSide == A)
//			{
//				tempCurRefIndex = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getRefractiveIndex_A();
//			}
//
//			else if (tempSurSide == B)
//			{
//				tempCurRefIndex = seqTrace.getAllInterInfosOfSurf_i(mPosImageSurface).at(i).getRefractiveIndex_B();
//			}
//
//			else // there must be a mistake!!!
//			{
//				std::cout << "there is a mistake in calculating the OPD!" << std::endl;
//			}
//
//			Ray_LLT tempRay(tempOrigin, tempDirection, tempCurRefIndex);
//			light.setWavelength(tempWavelenth);
//			lightRay.setRay_LLT(tempRay);
//			lightRay.setLight_LLT(light);
//			LightRaysToTraceBack.push_back(lightRay); // save all light rays to trace back in a vector
//		}
//
//
//		SequentialRayTracing seqTraceBack(OptSysOPDglobal);
//		seqTraceBack.seqRayTracingWithVectorOfLightRays(LightRaysToTraceBack);
//		std::vector<real> totalStepsToRefSphere;
//
//		// save the total steps (distance obj to image - distance image to referece sphere)
//		for (unsigned int i = 0; i < seqTraceBack.getAllInterInfosOfSurf_i(0).size(); i++)
//		{
//			real tempDisObToIm = totalStepsToImageSurface.at(i);
//			real tempDisImToRefSphere = seqTraceBack.getAllInterInfosOfSurf_i(0).at(i).getStepsToWalk();
//			totalStepsToRefSphere.push_back(tempDisObToIm - tempDisImToRefSphere);
//		}
//
//		std::vector<real> vectorXvalues;
//		std::vector<real> vectorYvalues;
//
//
//
//		for (unsigned int i = 0; i < seqTraceBack.getAllInterPointsAtSurf_i_notFiltered(0).size(); i++)
//		{
//			// get all X values of the intersection points at the exitpupil
//			real tempXvalue = mChiefRayAtExitPupil.getX() - seqTraceBack.getAllInterPointsAtSurf_i_notFiltered(0).at(i).getX();
//			vectorXvalues.push_back(tempXvalue);
//
//			// get all Y values of the intersection points at the exitpupil
//			real tempYvalue = mChiefRayAtExitPupil.getY() - seqTraceBack.getAllInterPointsAtSurf_i_notFiltered(0).at(i).getY();
//			vectorYvalues.push_back(tempYvalue);
//		}
//
//
//
//		real maxValueInX_Direction = Math::maxValueOfVactor(vectorXvalues);
//		real minValueInX_Direction = Math::minValueOfVector(vectorXvalues);
//		real maxValueInY_Direction = Math::maxValueOfVactor(vectorYvalues);
//		real minValueInY_Direction = Math::minValueOfVector(vectorYvalues);
//
//		switch (mScaling)
//		{
//		case 0:
//		{
//			// save OPD and position in exit pupil
//			real maxABSValueInX_Direction = maxValueInX_Direction;
//			if (maxValueInX_Direction < std::abs(minValueInX_Direction))
//			{
//				maxABSValueInX_Direction = std::abs(minValueInX_Direction);
//			}
//
//			real maxABSValueInY_Direction = maxValueInY_Direction;
//			if (maxValueInY_Direction < std::abs(minValueInY_Direction))
//			{
//				maxABSValueInY_Direction = std::abs(minValueInY_Direction);
//			}
//
//			// save the OPD in a cv matrix
//			for (unsigned int i = 0; i < seqTraceBack.getAllInterPointsAtSurf_i_notFiltered(0).size(); i++)
//			{
//				// according to ZEMAX we give the OPD in the wavelenth unit of the chief ray
//				real tempOPD = ((mRefDistance - totalStepsToRefSphere.at(i)) / mChiefLightRay.getLight_LLT().getWavelength()) * 1000000;
//
//				//***
//				// just for debugging
//				mVecWithAllCalcGlobalOPD.push_back(tempOPD);
//				//***
//
//
//				// scale the position in X and Y direction
//				// max value in X and Y is 1
//
//				real scalePosTempOPD_X = vectorXvalues.at(i) / maxABSValueInX_Direction;
//				real scalePosTempOPD_Y = vectorYvalues.at(i) / maxABSValueInY_Direction;
//
//				// fill the matrix with the OPD valus
//				int matrixScalePosTempOPD_X = sizeOfMatrixToCalcOPD / 2 - scalePosTempOPD_X * sizeOfMatrixToCalcOPD / 2;
//				//std::cout << "pos OPD X " << matrixScalePosTempOPD_X << std::endl;
//
//				int matrixScalePosTempOPD_Y = sizeOfMatrixToCalcOPD / 2 + scalePosTempOPD_Y * sizeOfMatrixToCalcOPD / 2;
//				//std::cout << "pos OPD Y " << matrixScalePosTempOPD_Y << std::endl;
//				//std::cout << std::endl;
//				// hier gehts weiter!!!
//
//				returnGlobalOPD.at<real>(matrixScalePosTempOPD_Y, matrixScalePosTempOPD_X) = tempOPD;
//			}
//		}
//		break;
//
//		case 1:
//		{
//			// the case for mScaling = 1 is not testet!!! TODO: test it!!!
//			std::cout << "mScaling = 1 is not testet!!! We have to do this in the future!!!" << std::endl;
//			for (unsigned int i = 0; i < seqTraceBack.getAllInterPointsAtSurf_i_notFiltered(0).size(); i++)
//			{
//				// according to ZEMAX we give the OPD in the wavelenth unit of the chief ray
//				real tempOPD = ((mRefDistance - totalStepsToRefSphere.at(i)) / mChiefLightRay.getLight_LLT().getWavelength()) * 1000000;
//
//				//***
//				// just for debugging
//				mVecWithAllCalcGlobalOPD.push_back(tempOPD);
//				//***
//				real scalePositionTempOPD_X;
//				real scalePositionTempOPD_Y;
//				if (vectorXvalues.at(i) > 0)
//				{
//					scalePositionTempOPD_X = vectorXvalues.at(i) / maxValueInX_Direction;
//				}
//				else
//				{
//					scalePositionTempOPD_X = vectorXvalues.at(i) / std::abs(minValueInX_Direction);
//				}
//				if (vectorYvalues.at(i) > 0)
//				{
//					scalePositionTempOPD_Y = vectorYvalues.at(i) / maxValueInY_Direction;
//				}
//				else
//				{
//					scalePositionTempOPD_Y = vectorYvalues.at(i) / std::abs(minValueInY_Direction);
//				}
//
//				//real scalePositionTempOPD_X = vectorXvalues.at(i) / maxABSValueInX_Direction;
//				//real scalePositionTempOPD_Y = vectorYvalues.at(i) / maxABSValueInY_Direction;
//
//				// fill the matrix with the OPD valus
//				int matrixScalePosTempOPD_X = sizeOfMatrixToCalcOPD / 2 - scalePositionTempOPD_X * sizeOfMatrixToCalcOPD / 2;
//				//std::cout << matrixScalePosTempOPD_X << std::endl ;
//				//std::cout << "pos OPD X " << matrixScalePosTempOPD_X << std::endl;
//
//				int matrixScalePosTempOPD_Y = sizeOfMatrixToCalcOPD / 2 + scalePositionTempOPD_Y * sizeOfMatrixToCalcOPD / 2;
//				//std::cout << matrixScalePosTempOPD_Y << std::endl;
//				//std::cout << "pos OPD Y " << matrixScalePosTempOPD_Y << std::endl;
//				//std::cout << std::endl;
//				// hier gehts weiter!!!
//
//				returnGlobalOPD.at<real>(matrixScalePosTempOPD_Y, matrixScalePosTempOPD_X) = tempOPD;
//
//			}
//
//		}
//		break;
//
//		}
//	}
//
//
//	//mGlobalOPD = returnGlobalOPD;
//
//	// we need that for debugging
//	//exportCV_MatToExcel(mGlobalOPD, "D:\OPDglobal_leftFromImage.csv");
//
//	return returnGlobalOPD;
//
//}

// get global OPD
cv::Mat OPD::getGlobalOPD()
{
	return mGlobalOPD;
}

// get global OPD deep copy
cv::Mat OPD::getGlobalOPD_deepCopy()
{
	return mGlobalOPD.clone();
}

// get upsampled global OPD
cv::Mat OPD::getUpsampledGlobalOPD()
{
	return mGlobalOPD_upsampled;
}

// get upsampled global OPD deep copy
cv::Mat OPD::getUpsampledGlobalOPD_deepCopy()
{
	return mGlobalOPD_upsampled.clone();
}


// get vector with all calculated global OPD 
std::vector<real> OPD::getVecWithAllCalcGlobalOPD()
{
	return mVecWithAllCalcGlobalOPD;
}





LightRayStruct OPD::getChiefLightRay()
{
	return mChiefLightRay;
}

//cv::Mat OPD::calcPSF()
//{
//
//	calculateCardinalPoints();
//	std::complex<double> twopi = 2 * 3.1415926535897932384626433832;
//
//	//static const int  N = floor(upscaledMatrixSize * (sqrt((32 / upscaledMatrixSize)))); /* check sampling*/
//	double aperture_diameter = mOptSys.getInforAS().getSemiHeightAS() * 2.0;  //meters; 1 inch
//	double efl = mCardinalPoints.getEFL();   //effective focal length in meters
//
//
//
//	double a = mGlobalOPD.cols;
//	double b = sqrt(32 / a);
//	double  SampledMatrixSizeforPSF = floor(mGlobalOPD.cols * b); /* effective grid size for PSF calculation*/
//	int N = SampledMatrixSizeforPSF;
//
//	if (N % 2 == 1)
//	{
//		N = N + 1;
//	}
//	typedef std::complex<double> Complex;
//
//	const Complex J(0, 1);
//
//
//	cv::Mat PupilFunction = cv::Mat::zeros(2 * N, 2 * N, CV_64F);
//
//
//	// sampling
//	double sampling = 0.5e-6;
//	cv::Mat X_pupil = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < mSampledOPDMatrixforPSF.cols; i++)
//	{
//		for (int j = 0; j < mSampledOPDMatrixforPSF.cols; j++)
//		{
//			X_pupil.at<double>(i, j) = (i - floor((mSampledOPDMatrixforPSF.cols / 2)))*0.0005;
//		}
//	}
//
//
//	cv::Mat Y_pupil = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < mSampledOPDMatrixforPSF.cols; i++)
//	{
//		for (int j = 0; j < mSampledOPDMatrixforPSF.cols; j++)
//		{
//			Y_pupil.at<double>(i, j) = (j - floor((mSampledOPDMatrixforPSF.cols / 2)))*0.0005;
//		}
//	}
//
//
//	cv::Mat R_pupil = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < mSampledOPDMatrixforPSF.cols; i++)
//	{
//		for (int j = 0; j < mSampledOPDMatrixforPSF.cols; j++)
//		{
//			R_pupil.at<double>(i, j) = sqrt(X_pupil.at<double>(i, j)*X_pupil.at<double>(i, j) + Y_pupil.at<double>(i, j)*Y_pupil.at<double>(i, j));
//		}
//	}
//
//	cv::Mat R_norm = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < mSampledOPDMatrixforPSF.cols; i++)
//	{
//		for (int j = 0; j < mSampledOPDMatrixforPSF.cols; j++)
//		{
//			R_norm.at<double>(i, j) = (R_pupil.at<double>(i, j)) * 1000 / aperture_diameter;
//		}
//	}
//
//
//
//	////////////////////////////////////////////////////
//
//
//
//
//
//	for (int i = 0; i < mSampledOPDMatrixforPSF.cols; i++)
//	{
//		for (int j = 0; j < mSampledOPDMatrixforPSF.cols; j++)
//		{
//			if (R_norm.at<double>(i, j) > 4)
//			{
//				PupilFunction.at<Complex>(i, j) = (0, 0);
//
//			}
//			else
//			{
//				PupilFunction.at<Complex>(i, j) = (cos(twopi * mSampledOPDMatrixforPSF.at<double>(i, j)) + J * sin(twopi * mSampledOPDMatrixforPSF.at<double>(i, j)));
//
//			}
//		}
//	}
//
//	cv::Mat Amplitude = cv::Mat::zeros(floor(PupilFunction.cols / 2), floor(PupilFunction.cols / 2), CV_64F);
//
//	for (int i = 0; i < floor(PupilFunction.cols / 2); i++)
//	{
//		for (int j = 0; j < floor(PupilFunction.cols / 2); j++)
//		{
//			Amplitude.at<double>(i, j) = abs(PupilFunction.at<Complex>(i, j));
//		}
//
//	}
//
//
//
//	////////////////////////////////////////check below
//	N = Amplitude.cols;
//	cv::Mat mPSF_complex = cv::Mat::zeros(N, N, CV_64F);
//	cv::Mat mPSF = cv::Mat::zeros(2 * N, 2 * N, CV_64F);
//	mPSF_complex = calcFFT(PupilFunction);
//
//	for (int i = N; i < 3 * N; i++)
//	{
//		for (int j = N; j < 3 * N; j++)
//		{
//			//std::cout << abs(mPSF_complex.at<float>(2 * N, 2 * N)) << std::endl;
//			//std::cout << mPSF_complex.at<float>(i , j) << std::endl;
//			mPSF.at<double>(i - N, j - N) = abs(mPSF_complex.at<float>(i, j))*abs(mPSF_complex.at<float>(i, j)) / (abs(mPSF_complex.at<float>(2 * N, 2 * N)*abs(mPSF_complex.at<float>(2 * N, 2 * N))));
//		}
//
//	}
//	/*
//	N = mPSF.cols;
//	cv::Mat mPSF_1 = cv::Mat::zeros( N-28, N, CV_64F);
//
//	for (int i = 14; i <  N-14; i++)
//	{
//		for (int j = 0; j <  N; j++)
//		{
//			mPSF_1.at<double>(i - 14, j) = mPSF.at<double>(i, j);
//		}
//	}*/
//
//
//
//
//
//	//check for total energy equal to one for psf .
//	std::ofstream outData;
//	outData.open("D:\PSFrishav.csv", std::ios::app);
//	outData << mPSF << std::endl;
//
//
//
//	//see results with higher pixels
//	N = 2 * mPSF.cols;
//	//std::cout << mPSF.at<float>(0, 0);//for checking fft function
//	double ratio = (double)(mPSF.cols - 1) / (double)(N - 1);
//	cv::Mat mPSF_high = cv::Mat::zeros(N, N, CV_64F);
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			int fx = floor((double)(i)*ratio);
//			int fy = floor((double)(j)*ratio);
//			int cx = ceil((double)(i)*ratio);
//			int cy = ceil((double)(j)*ratio);
//			double actualX = double(i)*ratio;
//			double actualY = double(j)*ratio;
//
//
//			mPSF_high.at<double>(i, j) = bilinear_interpolator(mPSF.at<double>(fx, fy), mPSF.at<double>(fx, cy),
//				mPSF.at<double>(cx, fy), mPSF.at<double>(cx, cy),
//				fx, cx, fy, cy,
//				actualX, actualY);
//		}
//	}
//
//
//
//	//OPD
//
//
//	cv::Mat display;
//	/*
//		if (mSampledOPDMatrixforPSF.empty())
//		{
//			std::cout << "image not loaded";
//		}
//		else
//		{
//			mSampledOPDMatrixforPSF.convertTo(display, CV_8UC1, 255.0 / 1.0, 0);
//			applyColorMap(display, display, cv::COLORMAP_JET);
//			cv::imshow("imagesc", display);
//			cv::waitKey(0);
//		}
//	*/
//
//	//PSF
//
//	//if (mPSF_high.empty())
//	//
//	//{
//	//	std::cout << "image not loaded";
//	//}
//	//else
//	//{
//	//	mPSF_high.convertTo(display, CV_8UC1, 255.0 / 1.0, 0);
//	//	applyColorMap(display, display, cv::COLORMAP_JET);
//	//	cv::imshow("imagesc", display);
//	//	cv::waitKey(0);
//	//}
//
//
//
//	return mPSF_high;
//}


////calculate the cut off frequency
//double OPD::calcCutoffFreq()
//{
//	calculateCardinalPoints();
//
//	double lambda = 0.550e-6;   //
//	double efl = mCardinalPoints.getEFL();                        //effective focal length
//	double	D = mCardinalPoints.getENPD();       //extrance pupil dia or stop dia
//	double mag = mCardinalPoints.getMagnification();             //image magnification                  
//	double	EXPD = mCardinalPoints.getEXPD();                   //exit pupil dia
//	double	P = EXPD / D;                         //pupil magnification
//	double	F = efl / D;                             //f number
//	double	Fw = (1 + mag / P)*F;                   //working f nummber
//	if (Fw < 0)
//	{
//		Fw = -Fw;
//	}
//	double	mCutoffFreq = 0.001 / (Fw * lambda);  //cut of frequency in lines / mm
//	std::cout << "Cut of Frequency of the system = " << mCutoffFreq << std::endl;
//
//	return mCutoffFreq;
//}

/*
int OPD::PlotGraph(cv::Mat & data)
{

	//converting the Mat to CV_64F
	data.convertTo(data, CV_64F);
	cv::Mat plot_result;

	cv::Ptr<cv::plot::Plot2d> plot = cv::plot::Plot2d::create(data);
	plot->setPlotBackgroundColor(cv::Scalar(50, 50, 50));
	plot->setPlotLineColor(cv::Scalar(50, 50, 255));
	plot->render(plot_result);

	imshow("Graph", plot_result);
	cv::waitKey();

	return 0;
}*/

//calculate MTF
//cv::Mat OPD::calcMTF()
//{
//	/*int N = upscaledMatrixSize;
//	//take 2 times fft to get mtf,cant do fft of psf since psf sampling is low
//
//
//	//sampling
//
//	double aperture_diameter = mCardinalPoints.getDiameterAperture();
//	double sampling = 0.00090;
//	cv::Mat X_pupil = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < upscaledMatrixSize; i++)
//	{
//		for (int j = 0; j < upscaledMatrixSize; j++)
//		{
//			X_pupil.at<double>(i, j) = (i - floor((upscaledMatrixSize / 2)))*0.001;
//		}
//	}
//
//	cv::Mat Y_pupil = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < upscaledMatrixSize; i++)
//	{
//		for (int j = 0; j < upscaledMatrixSize; j++)
//		{
//			Y_pupil.at<double>(i, j) = (j - floor((upscaledMatrixSize / 2)))*0.001;
//		}
//	}
//
//
//	cv::Mat R_pupil = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < upscaledMatrixSize; i++)
//	{
//		for (int j = 0; j < upscaledMatrixSize; j++)
//		{
//			R_pupil.at<double>(i, j) = sqrt(X_pupil.at<double>(i, j)*X_pupil.at<double>(i, j) + Y_pupil.at<double>(i, j)*Y_pupil.at<double>(i, j));
//		}
//	}
//
//	cv::Mat R_norm = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < upscaledMatrixSize; i++)
//	{
//		for (int j = 0; j < upscaledMatrixSize; j++)
//		{
//			R_norm.at<double>(i, j) = (R_pupil.at<double>(i, j) *100) / aperture_diameter;
//		}
//	}
//
//
//	//////////////////////////////////////////////////////////
//	typedef std::complex<double> Complex;
//	std::complex<double> twopi = 2 * 3.1415926535897932384626433832;
//	const Complex J(0, 1);
//	cv::Mat PupilFunction = cv::Mat::zeros(2*N, 2*N, CV_64F);
//
//
//	for (int i = 0; i < upscaledMatrixSize; i++)
//	{
//		for (int j = 0; j < upscaledMatrixSize; j++)
//		{
//			if (R_norm.at<double>(i, j) > 1)
//			{
//				PupilFunction.at<Complex>(i, j) = (0, 0);
//
//			}
//			else
//			{
//				PupilFunction.at<Complex>(i, j) = cos(twopi * mUpscaledGlobalOPD.at<double>(i, j)) + J * sin(twopi * mUpscaledGlobalOPD.at<double>(i, j));
//
//			}
//		}
//	}
//
//	*/
//
//
//	mMTF = calcFFT(mPSF);
//
//	cv::Mat display;
//
//	//if (mMTF.empty())
//	//{
//	//	std::cout << "image not loaded";
//	//}
//	//else
//	//{
//	//    mMTF.convertTo(display, CV_8UC1, 255.0 / 1.0, 0);
//	//	applyColorMap(display, display, cv::COLORMAP_JET);
//	//	cv::imshow("imagesc", display);
//	//	cv::waitKey(0);
//	//
//	//
//	//}
//
//	//plot MTF //fix data type
//	double s = mMTF.cols / 2;
//	std::vector<float> MTFplot(s);
//	double MTFmax = 0;
//
//	for (int i = s; i < mMTF.cols; i++)
//	{
//
//		if (abs(mMTF.at<float>(i, s)) > MTFmax)
//		{
//			MTFmax = abs(mMTF.at<float>(i + 1, s));
//		}
//
//	}
//
//	for (int i = s; i < mMTF.cols; i++)
//	{
//		MTFplot.at(i - s) = abs(mMTF.at<float>(i, s)) / MTFmax;
//		std::cout << MTFplot.at(i - s) << std::endl;
//	}
//
//
//
//	//std::cout << MTFplot << std::endl;
///*std::ofstream outData;
//	outData.open("D:\MTFplot.csv", std::ios::app);
//	outData << MTFplot << std::endl;*/
//
//	return mMTF;
//}
//////////////////////////////




///////////////////////
/*
//mtf plot
cv::plot::Plot2d;
cv::Mat xData, yData, display;
cv::Ptr<plot::Plot2d> plot;
xData.create(1, 100, CV_64F);//1 Row, 100 columns, Double
yData.create(1, 100, CV_64F);

for (int i = 0; i < 100; ++i)
{
	xData.at<double>(i) = i / 10.0;
	yData.at<double>(i) = i;
}
plot = plot::createPlot2d(xData, yData);
plot->setPlotSize(100, 1000);
plot->setMaxX(10);
plot->setMinX(0);
plot->setMaxY(100);
plot->setMinY(-1);
plot->render(display);
imshow("Plot", display);
cv::waitKey();
*/
//double s = PupilFunction.cols / 2;
//std::vector<double> MTFplot(s);


/*double MTFmax = 0;

for (int i = s; i < PupilFunction.cols; i++)
{

	if (abs(mMTF.at<double>(i , s)) > MTFmax)
	{
		MTFmax = abs(mMTF.at<double>(i+1, s));
	}

}

for (int i = s; i < PupilFunction.cols; i++)
{
	MTFplot.at(i - s) = abs(mMTF.at<double>(i, s))/ MTFmax;
}*/


//plot function


////Calculate huygen's integral
//cv::Mat OPD::calcHuygenIntegral(cv::Mat PupilFunction, double waveVector, double prop_distance, double sampling_in)
//{
//	double twopi = 2 * 3.1415926535897932384626433832;
//	typedef std::complex<double> Complex;
//	const Complex J(0, 1);
//	double sampling_out = 0.0005;
//	double sidelength_out = 0.05;
//	double N = floor(PupilFunction.cols / 2);
//
//
//
//
//	// sampling in
//	cv::Mat X_in = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			X_in.at<double>(i, j) = (i - floor((N / 2)))*sampling_in;
//		}
//	}
//
//
//	cv::Mat Y_in = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			Y_in.at<double>(i, j) = (j - floor((N / 2)))*sampling_in;
//		}
//	}
//
//	//sampling out
//	N = floor(sidelength_out / sampling_out);
//
//	cv::Mat X_out = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			X_out.at<double>(i, j) = (i - floor((N / 2)))*sampling_out;
//		}
//	}
//
//
//	cv::Mat Y_out = cv::Mat::zeros(N, N, CV_64F);
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			Y_out.at<double>(i, j) = (j - floor((N / 2)))*sampling_out;
//		}
//	}
//
//	////////////////////////////////////////////////
//
//	cv::Mat mHuygenIntegral = cv::Mat::zeros(2 * N, 2 * N, CV_64F);
//	cv::Mat X = cv::Mat::zeros(N, N, CV_64F);
//	cv::Mat Y = cv::Mat::zeros(N, N, CV_64F);
//	cv::Mat distance_to_target = cv::Mat::zeros(N, N, CV_64F);
//	cv::Mat inverse_distance_to_target = cv::Mat::zeros(N, N, CV_64F);
//	cv::Mat E = cv::Mat::zeros(2 * N, 2 * N, CV_64F);
//	Complex E_sum = (0, 0);
//	cv::Mat Amplitude = cv::Mat::zeros(floor(PupilFunction.cols / 2), floor(PupilFunction.cols / 2), CV_64F);
//
//	for (int i = 0; i < floor(PupilFunction.cols / 2); i++)
//	{
//		for (int j = 0; j < floor(PupilFunction.cols / 2); j++)
//		{
//			Amplitude.at<double>(i, j) = abs(PupilFunction.at<Complex>(i, j));
//		}
//
//	}
//	////////////////////////////////////////////////////
//
//		//see results at higher resolution
//	N = 5 * Amplitude.cols;
//	cv::Mat Amplitude_high = cv::Mat::zeros(N, N, CV_64F);
//	double ratio = (double)(Amplitude.cols - 1) / (double)(N - 1);
//	cv::Mat mHuygenPSF_high = cv::Mat::zeros(N, N, CV_64F);
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			int fx = floor((double)(i)*ratio);
//			int fy = floor((double)(j)*ratio);
//			int cx = ceil((double)(i)*ratio);
//			int cy = ceil((double)(j)*ratio);
//			double actualX = double(i)*ratio;
//			double actualY = double(j)*ratio;
//
//
//			Amplitude_high.at<double>(i, j) = bilinear_interpolator(Amplitude.at<double>(fx, fy), Amplitude.at<double>(fx, cy),
//				Amplitude.at<double>(cx, fy), Amplitude.at<double>(cx, cy),
//				fx, cx, fy, cy,
//				actualX, actualY);
//		}
//	}
//
//	cv::Mat display;
//	if (Amplitude_high.empty())
//
//	{
//		std::cout << "image not loaded";
//	}
//	else
//	{
//		//Amplitude_high.convertTo(display, CV_8UC1, 255.0 / 1.0, 0);
//		//applyColorMap(display, display, cv::COLORMAP_JET);
//		//cv::imshow("Pupil function", display);
//		//cv::waitKey(0);
//	}
//
//	/////////////////////////////////
//	N = floor(sidelength_out / sampling_out);
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			Complex E_sum = (0, 0);
//
//
//			for (int k = 0; k < floor(PupilFunction.cols / 2); k++)
//			{
//				for (int l = 0; l < floor(PupilFunction.cols / 2); l++)
//				{
//					X.at<double>(k, l) = X_in.at<double>(k, l) - X_out.at<double>(i, j);
//					Y.at<double>(k, l) = Y_in.at<double>(k, l) - Y_out.at<double>(i, j);
//					distance_to_target.at<double>(k, l) = sqrt(X.at<double>(k, l)*X.at<double>(k, l) + Y.at<double>(k, l)*Y.at<double>(k, l) + prop_distance * prop_distance);
//					inverse_distance_to_target.at<double>(k, l) = 1 / sqrt(X.at<double>(k, l)*X.at<double>(k, l) + Y.at<double>(k, l)*Y.at<double>(k, l) + prop_distance * prop_distance);
//					E.at<Complex>(k, l) = (Amplitude.at<double>(k, l))*(inverse_distance_to_target.at<double>(k, l))*(cos(-1 * waveVector*distance_to_target.at<double>(k, l) + (twopi * mGlobalOPD.at<double>(k, l))) + J * sin(-1 * waveVector*distance_to_target.at<double>(k, l) + (twopi * mGlobalOPD.at<double>(k, l))));
//					E_sum = (E_sum + E.at<Complex>(k, l));
//
//				}
//			}
//			mHuygenIntegral.at<Complex>(i, j) = E_sum;
//		}
//
//		std::cout << "Percentage completion of integration = " << i + 1 << std::endl;
//
//
//	}
//
//	return mHuygenIntegral;
//}

	// bilinear interpolation to fill holes in OPD matrix
void OPD::bilinearInterpolToFillHolesInOPDmatrix()
{
	mToleranceToCheckZero = 0.0000000001;
	mGlobalOPD_upsampled = mGlobalOPD;
	// check OPD value in the middle
	checkOPDValueInTheMiddle();

	bool checker = true;
	mMaxStepToLook = 2;
	while (checker)
	{
		horizontalInterpolation_oneStep();
		verticalInterpolation_oneStep();

		if (mFilledPoints_horizontal < mToleranceToCheckZero && mFilledPoints_vertical < mToleranceToCheckZero) // there is no improvement
		{
			holizontal_bilinear_Interpolation();
			vertical_bilinear_Interpolation();

			if (mMaxStepToLook > mLoadParaOPD.getMaxIterationsBilinInterpol())
			{
				checker = false;
			}
			++mMaxStepToLook;
		}
	} 

	// in the middle there is allways the chief ray -> OPD is zero
	setMiddlePointToZero();
}

void OPD::horizontalInterpolation_oneStep()
{
	mFilledPoints_horizontal = 0;
	real tempValue{};

	for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix; ++verticalPos)
	{
		for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix; ++horizontalPos)
		{
			tempValue = mGlobalOPD_upsampled.at<real>(verticalPos, horizontalPos);

			if (std::abs(tempValue) < mToleranceToCheckZero)
			{
				lookPositive_X_oneStep(horizontalPos, verticalPos);
				if (mLook_Pos_X_oneStep_trueVal)
				{
					lookNegativ_X_oneStep(horizontalPos, verticalPos);
				}

				if (mLook_Neg_X_oneStep_trueVal && mLook_Pos_X_oneStep_trueVal) // calculate new value in OPD matrix
				{
					tempValue = (mValOneStep_posX + mValOneStep_negX) / 2;

					mGlobalOPD_upsampled.at<real>(verticalPos, horizontalPos) = tempValue;
					++mFilledPoints_horizontal;
				}

				if (mLook_Pos_X_oneStep_trueVal)
				{
					++horizontalPos;
				}
			}
		}
	}
}

void OPD::holizontal_bilinear_Interpolation()
{
	mFilledPoints_horizontal = 0;
	real tempValue{};


	for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix; ++verticalPos)
	{
		for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix; ++horizontalPos)
		{
			tempValue = mGlobalOPD_upsampled.at<real>(verticalPos, horizontalPos);
			// just for debugging 
			// std::cout << tempValue << std::endl;

			if (std::abs(tempValue) < mToleranceToCheckZero )
			{
				lookNegativ_X_multiSteps(horizontalPos, verticalPos);
				if (mLook_Neg_X.getTrueVal())
				{
					lookPositiv_X_multiSteps(horizontalPos, verticalPos);
				}

				if (mLook_Neg_X.getTrueVal() && mLook_Pos_X.getTrueVal()) // calculate new value in OPD matrix
				{
					// see: https://de.wikipedia.org/wiki/Bilineare_Filterung

					tempValue = (real)(mLook_Pos_X.getPos_X() - horizontalPos) / (mLook_Pos_X.getPos_X() - mLook_Neg_X.getPos_X()) * mLook_Neg_X.getVal() + (real)(horizontalPos - mLook_Neg_X.getPos_X()) / (mLook_Pos_X.getPos_X() - mLook_Neg_X.getPos_X()) * mLook_Pos_X.getVal();
				
					mGlobalOPD_upsampled.at<real>(verticalPos, horizontalPos) = tempValue;
					++mFilledPoints_horizontal;
				}
			}
		}
	}

}




void OPD::vertical_bilinear_Interpolation()
{
	mFilledPoints_vertical = 0;
	real tempValue{};

	for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix; ++horizontalPos)
	{
		for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix; ++verticalPos)
		{
			tempValue = mGlobalOPD_upsampled.at<real>(verticalPos, horizontalPos);
			// just for debugging
			//std::cout << tempValue << std::endl;

			if (std::abs(tempValue) < mToleranceToCheckZero)
			{
				lookNegativ_Y_multiSteps(horizontalPos, verticalPos);
				if (mLook_Neg_Y.getTrueVal())
				{
					lookPositiv_Y_multiSteps(horizontalPos, verticalPos);
				}

				if (mLook_Neg_Y.getTrueVal() && mLook_Pos_Y.getTrueVal()) // calculate new value in OPD matrix
				{
					// see: https://de.wikipedia.org/wiki/Bilineare_Filterung

					tempValue = (real)(mLook_Pos_Y.getPos_Y() - verticalPos) / (mLook_Pos_Y.getPos_Y() - mLook_Neg_Y.getPos_Y()) * mLook_Neg_Y.getVal() + (real)(verticalPos - mLook_Neg_Y.getPos_Y()) / (mLook_Pos_Y.getPos_Y() - mLook_Neg_Y.getPos_Y()) * mLook_Pos_Y.getVal();

					mGlobalOPD_upsampled.at<real>(verticalPos, horizontalPos) = tempValue;
					++mFilledPoints_vertical;
				}
			}
		}
	}

}

void OPD::verticalInterpolation_oneStep()
{
	mFilledPoints_vertical = 0;
	real tempValue{};

	for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix; ++horizontalPos)
	{
		for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix; ++verticalPos)
		{
			tempValue = mGlobalOPD_upsampled.at<real>(verticalPos, horizontalPos);

			if (std::abs(tempValue) < mToleranceToCheckZero)
			{
				lookPositive_Y_oneStep(horizontalPos, verticalPos);				
				if (mLook_Pos_Y_oneStep_trueVal)
				{
					lookNegative_Y_oneStep(horizontalPos, verticalPos);
				}

				if (mLook_Neg_Y_oneStep_trueVal && mLook_Pos_Y_oneStep_trueVal) // calculate new value in OPD matrix
				{
					tempValue = (mValOneStep_posY + mValOneStep_negY) / 2;

					mGlobalOPD_upsampled.at<real>(verticalPos, horizontalPos) = tempValue;
					++mFilledPoints_vertical;
				}

				if (mLook_Pos_Y_oneStep_trueVal)
				{
					++verticalPos;
				}
			}
		}
	}

}

// check OPD value in the middle of the matrix
void OPD::checkOPDValueInTheMiddle()
{
	unsigned int middlePoint = mGlobalOPD_upsampled.size().height / 2;

	real valMiddlePoint = mGlobalOPD_upsampled.at<real>(middlePoint, middlePoint);

	if (std::abs(valMiddlePoint) > mToleranceToCheckZero) // it is not zero
	{
		mGlobalOPD_upsampled.at<real>(middlePoint, middlePoint) = 0.0;
		//oftenUse::errorProtocol_stopSystem("maybe the matrix size of the OPD is too small and you lose data", "OpticalPathDifference.cpp", 0, false);
	}


}

void OPD::setMiddlePointToZero()
{
	unsigned int middlePoint = mGlobalOPD_upsampled.size().height / 2 ;
	mGlobalOPD_upsampled.at<real>(middlePoint, middlePoint) = 0.0;
}


// look negativ x direction
void OPD::lookNegativ_X_multiSteps(unsigned int posX, unsigned int posY)
{
	int tempPosX = posX - 1;
	real tempVal;
	mLook_Neg_X.setTrueVal(false);

	if(tempPosX >= 0)
	{
		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
		{
			tempVal = mGlobalOPD_upsampled.at<real>(posY, tempPosX);

			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
			{ 
				mLook_Neg_X.setTrueVal(true);
				mLook_Neg_X.setPos_X(tempPosX);
				mLook_Neg_X.setPos_Y(posY);
				mLook_Neg_X.setVal(tempVal);
				i = mMaxStepToLook;
			}


			--tempPosX;
			if (tempPosX < 0)
			{
				i = mMaxStepToLook;
			}

		}
		

	}


}

void OPD::lookNegativ_X_oneStep(unsigned int posX, unsigned int posY)
{
	int tempPosX = posX - 1;
	real tempVal;
	mLook_Neg_X_oneStep_trueVal = false;

	if(tempPosX >= 0)
	{
		
		tempVal = mGlobalOPD_upsampled.at<real>(posY, tempPosX);

		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
		{
			mValOneStep_negX = tempVal;
			mLook_Neg_X_oneStep_trueVal = true;
		}
	}

}

void OPD::lookPositive_X_oneStep(unsigned int posX, unsigned int posY)
{
	int tempPosX = posX + 1;
	real tempVal;
	mLook_Pos_X_oneStep_trueVal = false;

	if (tempPosX < mSizeMatrix)
	{
			tempVal = mGlobalOPD_upsampled.at<real>(posY, tempPosX);

			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
			{
				mValOneStep_posX = tempVal;
				mLook_Pos_X_oneStep_trueVal = true;
			}

	}
}

void OPD::lookNegative_Y_oneStep(unsigned int posX, unsigned int posY)
{
	int tempPosY = posY - 1;
	real tempVal;
	mLook_Neg_Y_oneStep_trueVal = false;

	if (tempPosY >= 0)
	{

		tempVal = mGlobalOPD_upsampled.at<real>(tempPosY, posX);

		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
		{
			mValOneStep_negY = tempVal;
			mLook_Neg_Y_oneStep_trueVal = true;
		}
	}
}

void OPD::lookPositive_Y_oneStep(unsigned int posX, unsigned int posY)
{
	int tempPosY = posY + 1;
	real tempVal;
	mLook_Pos_Y_oneStep_trueVal = false;

	if (tempPosY < mSizeMatrix)
	{
		tempVal = mGlobalOPD_upsampled.at<real>(tempPosY, posX);

		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
		{
			mValOneStep_posY = tempVal;
			mLook_Pos_Y_oneStep_trueVal = true;
		}

	}
}

// look positiv x direction
void OPD::lookPositiv_X_multiSteps(unsigned int posX, unsigned int posY)
{
	int tempPosX = posX + 1;
	real tempVal;
	mLook_Pos_X.setTrueVal(false);
	
	if(tempPosX < mSizeMatrix)
	{
		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
		{
			tempVal = mGlobalOPD_upsampled.at<real>(posY, tempPosX);
	
			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
			{
				mLook_Pos_X.setTrueVal(true);
				mLook_Pos_X.setPos_X(tempPosX);
				mLook_Pos_X.setPos_Y(posY);
				mLook_Pos_X.setVal(tempVal);
				i = mMaxStepToLook;
			}

			++tempPosX;
			if (tempPosX >= mSizeMatrix)
			{
				i = mMaxStepToLook;
			}
	
		}
	
	
	}
}

void OPD::setGlobalOPD(cv::Mat globalOPD)
{
	mGlobalOPD = globalOPD;
	mSizeMatrix = globalOPD.size().height;

	globalOPD.size().width;

	if (globalOPD.size().width != mSizeMatrix)
	{
		// matrix size must be symetric
		oftenUse::errorProtocol_stopSystem("matrix size of OPD must by symetric", "OpticalPathDifference", 0, true);
	}
}

// look negativ y direction
void OPD::lookNegativ_Y_multiSteps(unsigned int posX, unsigned int posY)
{
	int tempPosY = posY - 1;
	real tempVal;
	mLook_Neg_Y.setTrueVal(false);

	if(tempPosY >= 0)
	{
		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
		{
			tempVal = mGlobalOPD_upsampled.at<real>(tempPosY, posX);
			// just for debugging
			// std::cout << tempVal << std::endl;

			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
			{
				mLook_Neg_Y.setTrueVal(true);
				mLook_Neg_Y.setPos_X(posX);
				mLook_Neg_Y.setPos_Y(tempPosY);
				mLook_Neg_Y.setVal(tempVal);
				i = mMaxStepToLook;
			}

			--tempPosY;
			if (tempPosY < 0)
			{
				i = mMaxStepToLook;
			}

		}


	}
}

// look positiv y direction
void OPD::lookPositiv_Y_multiSteps(unsigned int posX, unsigned int posY)
{
	int tempPosY = posY + 1;
	real tempVal;
	mLook_Pos_Y.setTrueVal(false);

	if (tempPosY < mSizeMatrix)
	{
		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
		{
			tempVal = mGlobalOPD_upsampled.at<real>(tempPosY, posX);

			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
			{
				mLook_Pos_Y.setTrueVal(true);
				mLook_Pos_Y.setPos_X(posX);
				mLook_Pos_Y.setPos_Y(tempPosY);
				mLook_Pos_Y.setVal(tempVal);
				i = mMaxStepToLook;
			}

			++tempPosY;
			if (tempPosY >= mSizeMatrix)
			{
				i = mMaxStepToLook;
			}

		}


	}
}

// optical system
void OPD::setOpticalSystemLLT(OpticalSystem_LLT optSysLLT)
{
	mOptSys = optSysLLT;
}
OpticalSystem_LLT OPD::getOpticalSystemLLT()
{
	return mOptSys;
}
// aimed light ray
void OPD::setAimedLightRays(std::vector<LightRayStruct> aimedLightRay)
{
	mAimedLightRay = aimedLightRay;
}
std::vector<LightRayStruct> OPD::getAimedLightRays()
{
	return mAimedLightRay;
}
// obj or inf
void OPD::setInfOrObj(objectPoint_inf_obj inf_obj)
{
	mInf_obj = inf_obj;
}
objectPoint_inf_obj OPD::getInfOrObj()
{
	return mInf_obj;
}
// size matrix to save
void OPD::setSizeMatrixToSave(unsigned int sizeMatrixToSave)
{
	mSizeMatrix = sizeMatrixToSave;
}
unsigned int OPD::getSizeMatrixToSave()
{
	return mSizeMatrix;
}

real OPD::getPosX_inApStop()
{
	return mPos_X_InApertureStop;
}
real OPD::getPosY_inApStop()
{
	return mPos_Y_InApertureStop;
}
real OPD::getPosZ_inApStop()
{
	return mPos_Z_InApertureStop;
}

// ***
// set and get functions //
	// tolerance for ray aiming
void OPD::setToleranceForRayAiming(real tolerance)
{
	mLoadParaOPD.setToleranceForRayAiming(tolerance);
}
real OPD::OPD::getToleranceForRayAiming()
{
	return mLoadParaOPD.getToleranceForRayAiming();
}

// is first aimed ray chief ray
void OPD::setFirstAimedRayIsChiefRay(bool firstAimedRayIsChiefRay)
{
	mLoadParaOPD.setFirstAimedRayIsChiefRay(firstAimedRayIsChiefRay);
}
bool OPD::getFirstAimedRayIsChiefRay()
{
	return mLoadParaOPD.getFirstAimedRayIsChiefRay();
}

// max iteration biliniear interpolation
void OPD::setMaxIterationsBilinInterpol(unsigned int maxStepsBilinInter)
{
	mLoadParaOPD.setMaxIterationsBilinInterpol(maxStepsBilinInter);
}
unsigned int OPD::getMaxIterationsBilinInterpol()
{
	return mLoadParaOPD.getMaxIterationsBilinInterpol();
}

// factor for ray aiming if object is in inf.
void OPD::setFactorForRayAimingIfObjInInf(real factorObjInInf)
{
	mLoadParaOPD.setFactorForRayAimingIfObjInInf(factorObjInInf);
}
real OPD::getFactorForRayAimingIfObjInInf()
{
	return mLoadParaOPD.getFactorForRayAimingIfObjInInf();
}

// field angle chief ray
void OPD::setFieldAngleChiefRay_X(real fieldAngleChiefRay_X)
{
	mLoadParaOPD.setFieldAngleChiefRay_X(fieldAngleChiefRay_X);

}
real OPD::getFieldAngleChiefRay_X()
{
	return mLoadParaOPD.getFieldAngleChiefRay_X();
}
void OPD::setFieldAngleChiefRay_Y(real fieldAngleChiefRay_Y)
{
	mLoadParaOPD.setFieldAngleChiefRay_Y(fieldAngleChiefRay_Y);
}
real OPD::getFieldAngleChiefRay_Y()
{
	return mLoadParaOPD.getFieldAngleChiefRay_Y();
}


// load default parameter
void OPD::loadDefaultParameter()
{
	mLoadParaOPD.loadDefaultParameter();
}
// ***
