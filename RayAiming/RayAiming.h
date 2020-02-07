#pragma once

#include "..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"
#include "..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"

#include "..\LowLevelTracing/Interaction/DoNothingInteraction_LLT.h"


struct defaultRayAimingStruct 
{
public:

	// tolerance
	real getTolerance_XandY();
	void setTolerance_XandY(real& tolerance);

	// start point factor
	real getStartPointFactor();
	void setStartPointFactor(real startPointFactor);

	// max loops trace to last surface;
	unsigned int getMaxLoopsTraceToLastSurface();
	void setMaxLoopsTraceToLastSurface(unsigned int maxLoopLastSurf);

	// max interations ray aiming
	unsigned getMaxInterationRayAiming();
	void setMaxIterattionsRayAiming(unsigned int maxInterationsRayAiming);

	// factor
	real getFactor();
	void setFactor(real factor);

	void loadDefaultParameter();

private:
	real mTolerance_XandY;
	real mStartPointFactor;
	unsigned int mMaxLoopsTraceToLastSurface;
	unsigned int mMaxInterationsRayAiming;
	real mFactor;
};

struct  lightRayAndInterPointAperStop
{
public:

	// light ray
	LightRayStruct getLightRay() const;
	void setLightRay(const LightRayStruct& lightRay);

	//inter point aper stop
	VectorStructR3 getInterPointAperStop() const;
	void setInterPointAperStop(const VectorStructR3& interPointAperStop);

private:
	LightRayStruct mLightRayStr;
	VectorStructR3 mInterPointAperStop;
};

enum betterSide{posSide, negSide, stay};

struct lightRay_intP_dis_negPos_factor
{
	lightRay_intP_dis_negPos_factor();
	lightRay_intP_dis_negPos_factor(LightRayStruct lightRay, VectorStructR3 interPoint, real distanceX, real distanceY, betterSide negOrPos, real factorX, real factorY);
	~lightRay_intP_dis_negPos_factor();

	// light ray
	LightRayStruct getLightRay();
	void setLightRay(LightRayStruct lightRay);

	// inter point AS
	VectorStructR3 getInterPoint();
	void setInterPoint(const VectorStructR3& interPointAS);

	// distance interpoint to target X
	real getDistanceInterToTarget_X();
	void setDistanceInterToTarger_X(real distanceX);

	// distance interpoint to target Y
	real getDistanceInterToTarget_Y();
	void setDistanceInterToTarger_Y(real distanceY);

	// neg or pos side
	betterSide getNegOrPosSide();
	void setNegOrPosSide(betterSide negPosStay);

	// factor X
	real getFactorX();
	void setFactorX(real factorX);

	// factor Y
	real getFactorY();
	void setFactorY(real factorY);
	

private:
	LightRayStruct mLightRay;
	VectorStructR3 mInterPointAS;
	real mDistance_X;
	real mDistance_Y;
	betterSide mNegPosStay;
	real mFactorX;
	real mFactorY;
};

class RayAiming {
public: RayAiming() {};
		RayAiming(OpticalSystem_LLT opticalSystem);
		~RayAiming() {};

		// load important infomation for ray aiming
		void loadImportantInfosForRayAiming();

		// Ray-Aiming Main-Function
		LightRayStruct RayAiming::rayAimingMain(VectorStructR3 mainVector, VectorStructR3 targetPoint, double wavelength, double curRefracIndex);

		// find aperture stop
		unsigned int getPositionApertureStop(OpticalSystem_LLT optSys);

		// Ray Aiming for a ray starting at infinity
		LightRayStruct RayAiming::infinityRayAiming(VectorStructR3 rayDirection, VectorStructR3 targetPoint, Light_LLT light, double curRefracIndex);

		// Ray-Aiming in X- an Y-direction (Infinity)
		//VectorStructR3 RayAiming::minDistanceIn_XY_DirectionInfRay(LightRayStruct lightRay, VectorStructR3 targetPoint, VectorStructR3 rayDirection, VectorStructR3 startPoint, double tolerance);

		// calculate Ray that goes throw an point in the apertur stop
		LightRayStruct calcRayThrowPointInApertureStop(VectorStructR3 startPointRay, VectorStructR3 targetPoint, Light_LLT light, double curRefracIndex);

		// Ray-Aiming in X- an Y-direction
		VectorStructR3 RayAiming::minDistanceIn_XY_Direction(VectorStructR3 targetPoint, real wavelength, VectorStructR3 pointAtFirstSurface, double SemiHeightFirstSurface, VectorStructR3 startPoint, double tolerance, Light_LLT light, double curRefracIndex);

		// helper for Ray building /Dominik
		Ray_LLT RayAiming::newRayHelper(VectorStructR3 startPoint, VectorStructR3 direction, real wavelength, double refIndex);

		// Calculates the first plane before the first negative Lens
		VectorStructR3 RayAiming::shiftFirstSurface(double& radius, double& semiHeight, VectorStructR3& apexOfSphere);

		// Korrektur falls alle 4 Ausgangsstrahlen nicht die Blende erreichen 
		VectorStructR3 RayAiming::newStartRay(VectorStructR3 startPointRay, VectorStructR3 targetPoint, double curRefracIndex, Light_LLT light, double SemiHeightFirstSurface, VectorStructR3 pointFirstSurface, VectorStructR3 directionFirstSurface, int interation0);

		VectorStructR3 RayAiming::newRaysForRayAiming(LightRayStruct lightRayStart, double SemiHeightFirstSurface, VectorStructR3 targetPoint, VectorStructR3 newDirection, double curRefracIndex, bool X_ForT, bool Y_ForT);

		// Überprüft ob ein Strahl nicht durch alle Elemente getraced werden kann. Falls nicht -> true
		bool RayAiming::checkRayAllElements(LightRayStruct lightRay);

		//		// Ändert die Intensität eines Strahls anhand des nach einer .csv-Tabelle gegebenen Gradzahl
		//		LightRayStruct RayAiming::changeIntensityByDegree(LightRayStruct lightRay, std::vector<VectorStructR2> vec1);

		// instert a plan surface LLT before firest surface of optical system_LLT
		void insertPlanBeforFirstSur();

		// trace all rays until all of them comes to the last surface
		lightRayAndInterPointAperStop getBestLightRayAndInterPoint_inf(LightRayStruct lightRay0, LightRayStruct lightRay1, LightRayStruct lightRay2, LightRayStruct lightRay3, LightRayStruct lightRay4, VectorStructR3 targetPoint);

		// trace one ray until it comes to the last surface;
		lightRayAndInterPointAperStop traceOneRayUntilLastSurface_infRayAiming(LightRayStruct lightRay, unsigned int maxLoop);

		// calc all distances
		std::vector<real> calcAllDistances(const std::vector<lightRayAndInterPointAperStop>& vecLightRaysAndInterPoints, const VectorStructR3& targetPoint);

		// calc distance X
		real calcDistance_X(VectorStructR3 point, VectorStructR3 targetPoint);
		// calc distance Y
		real calcDistance_Y(VectorStructR3 point, VectorStructR3 targetPoint);
		

		// reduce distance X from light ray
		lightRayAndInterPointAperStop reduceDistanceFormLightRay_X_inf(LightRayStruct startLightRay, VectorStructR3 interPointAperStop,  VectorStructR3 targetPoint, real initialDistance);
		// reduce distance Y from light ray
		//LightRayStruct reduceDistanveFromLightRay_Y_inf(LightRayStruct startLightRay, VectorStructR3 interPointAperStop,  VectorStructR3 targetPoint, real initialDistance);

		// get the intersection point of an ray with the aperture stop
		VectorStructR3 getInterPointApertureStop(LightRayStruct lightRay);

		// check if we have to trace to neg of pos side
		lightRay_intP_dis_negPos_factor traceNegOrPosSide_andReduce_X_inf(lightRay_intP_dis_negPos_factor initialInfos, VectorStructR3 targetPoint);
		lightRay_intP_dis_negPos_factor traceNegOrPosSide_andReduce_Y_inf(lightRay_intP_dis_negPos_factor initialInfos, VectorStructR3 targetPoint);

		// get default parametes
		defaultRayAimingStruct getDefaultParameters();

private:

	OpticalSystem_LLT mOpticalSystem_LLT;
	OpticalSystem_LLT mOpticalSystemModified_LLT;
	unsigned int mPosApertureStop;
	unsigned int mPosApertureStopModify;

	defaultRayAimingStruct mDefaultParaRayAiming;

	real mSemiHeightFirstSurface;
	real mRadiusFirstSurface;
	VectorStructR3 mPositionFirstSurface;
	VectorStructR3 mDirectionFirstSurface;

	VectorStructR3 negLensHelper;
		
	DoNothingInteraction_LLT doNothing;
	SequentialRayTracing mSeqTracModified_LLT;
};