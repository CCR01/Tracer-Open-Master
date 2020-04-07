#pragma once

#include "..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"
#include "..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"

#include "..\LowLevelTracing/Interaction/DoNothingInteraction_LLT.h"

#include "..\FillAptertureStop\FillApertureStop.h"

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

	// factor inf
	real getFactor_inf();
	void setFactor_inf(real factor_inf);

	// factor obj
	real getFactor_obj();
	void setFactor_obj(real factor_obj);

	// turn on robust ray aiming
	void turn_On_RobustRayAiming();
	void turn_Off_RobustRayAiming();
	bool getRobustRayAiming();

	// variance percent robust ray aiming
	void setVariancePercentRRA(real percent);
	real getVariancePercentRRA();

	// stay counter
	unsigned int getMaxStayCounter();
	void setMayStayCounter(unsigned int maxStayCounter);

	// increaser factor times
	real getIncreaserFactorTimes();
	void setIncreaserFactorTimes(real increaserFactorTimes);

	void loadDefaultParameter();

private:
	real mTolerance_XandY;
	real mStartPointFactor;
	unsigned int mMaxLoopsTraceToLastSurface;
	unsigned int mMaxInterationsRayAiming;
	real mFactor_inf;
	real mFactor_obj;
	bool mRobustRayAiming;
	real mVariancePercentRobustRA;
	unsigned int mMaxStayCounter;
	real mIncreaserFactorTimes;
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

enum betterSide { posSide, negSide, stay };
enum reduceWhat {reduce_X, reduce_Y, neutral};

struct lightRay_intP_dis_negPos_factor
{
	lightRay_intP_dis_negPos_factor();
	lightRay_intP_dis_negPos_factor(LightRayStruct lightRay, VectorStructR3 interPoint, real distanceX, real distanceY, betterSide negOrPos, real factorX, real factorY, VectorStructR3 targerPoint, real interations);
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

	// target point
	VectorStructR3 getTargetPoint();
	void setTargetPoint(VectorStructR3 targetPoint);

	// get interations
	unsigned int getInterations();
	void setInterations(unsigned int interations);

private:
	LightRayStruct mLightRay;
	VectorStructR3 mInterPointAS;
	real mDistance_X;
	real mDistance_Y;
	betterSide mNegPosStay;
	real mFactorX;
	real mFactorY;

	VectorStructR3 mTargetPoint;
	unsigned int mInterations;
};

class RayAiming {
public: RayAiming() {};
		RayAiming(OpticalSystem_LLT opticalSystem);
		~RayAiming() {};


		// *** general *** //
		// load important infomation for ray aiming
		void loadImportantInfosForRayAiming();
		// find aperture stop
		unsigned int getPositionApertureStop(OpticalSystem_LLT optSys);
		// calc all distances
		std::vector<real> calcAllDistances(const std::vector<lightRayAndInterPointAperStop>& vecLightRaysAndInterPoints, const VectorStructR3& targetPoint);
		// calc distance X
		real calcDistance_X(VectorStructR3 point, VectorStructR3 targetPoint);
		// calc distance Y
		real calcDistance_Y(VectorStructR3 point, VectorStructR3 targetPoint);
		// get default parametes
		defaultRayAimingStruct getDefaultParameters();
		void setToleranceX_Y(real tolerance);
		void turn_ON_RobustRayAiming();
		void turn_OFF_RobustRayAiming();
		// get positon ray with lowest distance
		unsigned int getPosRayLowestDistance(std::vector<VectorStructR3> allInterPoints, VectorStructR3 targetPoint);
		// print
		void printInterP_Target_distance_X_Y(lightRay_intP_dis_negPos_factor infosToReduce);
		// shift start point ray from infinity
		VectorStructR3 RayAiming::shiftFirstSurface(real radius, real semiHeight, VectorStructR3 apexOfSphere);
		// *** *** //


		// *** ray aiming from OBJ *** //
		// Ray Aiming for a ray starting at an object point
		LightRayStruct rayAiming_obj(VectorStructR3 rayOrigin, VectorStructR3 targetPoint, Light_LLT light, real curRefracIndex);
		// trace all rays until all of them comes to the last surface
		lightRayAndInterPointAperStop getBestLightRayAndInterPoint_obj(LightRayStruct lightRay0, LightRayStruct lightRay1, LightRayStruct lightRay2, LightRayStruct lightRay3, LightRayStruct lightRay4, VectorStructR3 targetPoint, VectorStructR3 vectorToCalc1, VectorStructR3 vectorRoCalc2);
		// trace one ray until it comes to the last surface;
		lightRayAndInterPointAperStop traceOneRayUntilInApertureStop_obj(LightRayStruct lightRay, VectorStructR3 vectorToCalcDir, unsigned int maxLoop);
		// check if we have to trace to neg of pos side
		lightRay_intP_dis_negPos_factor traceNegOrPosSide_andReduce_X_obj(lightRay_intP_dis_negPos_factor initialInfos);
		lightRay_intP_dis_negPos_factor traceNegOrPosSide_andReduce_Y_obj(lightRay_intP_dis_negPos_factor initialInfos);
		// reduce distance in x and y 
		lightRay_intP_dis_negPos_factor reduceDistancesIn_X_AND_Y_obj(lightRay_intP_dis_negPos_factor initialInfos);
		// robust ray aiming
		lightRay_intP_dis_negPos_factor robustRayAiming_obj(lightRay_intP_dis_negPos_factor initialInfos);
		// calculate new origin variance in percent
		lightRay_intP_dis_negPos_factor calcNewBestInfos_obj(lightRay_intP_dis_negPos_factor initialInfos);
		// ray aiming many obj
		std::vector<LightRayStruct> rayAimingMany_obj(std::vector<VectorStructR3> pointsInAS, VectorStructR3 startPointRay, Light_LLT light, real curRefracIndex);
		// set opt sys LLT
		void setOpticalSystem_LLT(OpticalSystem_LLT optSys_LLT);
		// *** *** //



		// *** ray aiming from INF *** //
		// Ray Aiming for a ray starting at infinity
		LightRayStruct rayAiming_inf(VectorStructR3 rayDirection, VectorStructR3 targetPoint, Light_LLT light, real curRefracIndex);
		// trace all rays until all of them comes to the last surface
		lightRayAndInterPointAperStop getBestLightRayAndInterPoint_inf(LightRayStruct lightRay0, LightRayStruct lightRay1, LightRayStruct lightRay2, LightRayStruct lightRay3, LightRayStruct lightRay4, VectorStructR3 targetPoint);
		// trace one ray until it comes to the last surface;
		lightRayAndInterPointAperStop traceOneRayUntilInApertureStop_inf(LightRayStruct lightRay, unsigned int maxLoop);
		// check if we have to trace to neg of pos side
		lightRay_intP_dis_negPos_factor traceNegOrPosSide_andReduce_X_inf(lightRay_intP_dis_negPos_factor initialInfos);
		lightRay_intP_dis_negPos_factor traceNegOrPosSide_andReduce_Y_inf(lightRay_intP_dis_negPos_factor initialInfos);
		// reduce distance in x and y 
		lightRay_intP_dis_negPos_factor reduceDistancesIn_X_AND_Y_inf(lightRay_intP_dis_negPos_factor initialInfos);
		// robust ray aiming
		lightRay_intP_dis_negPos_factor robustRayAiming_inf(lightRay_intP_dis_negPos_factor initialInfos);
		// calculate new origin variance in percent
		lightRay_intP_dis_negPos_factor calcNewBestInfos_inf(lightRay_intP_dis_negPos_factor initialInfos);
		// *** *** //
	


private:

	OpticalSystem_LLT mOpticalSystem_LLT;
	unsigned int mPosApertureStop;

	defaultRayAimingStruct mDefaultParaRayAiming;

	real mSemiHeightFirstSurface;
	real mRadiusFirstSurface;
	VectorStructR3 mPositionFirstSurface;
	VectorStructR3 mDirectionFirstSurface;

	VectorStructR3 negLensHelper;


};