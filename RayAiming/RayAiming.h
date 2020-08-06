#pragma once

#include "..\LowLevelTracing\OpticalSystem_LLT.h"

struct defaultRayAimingStruct
{
public:

	// tolerance
	real getTolerance_XandY();
	void setTolerance_XandY(real tolerance);

	// start point factor
	real getStartPointFactor();
	void setStartPointFactor(real startPointFactor);

	// max loops trace to last surface;
	unsigned int getMaxLoopsTraceToLastSurface();
	void setMaxLoopsTraceToLastSurface(unsigned int maxLoopLastSurf);

	// max interations ray aiming
	unsigned getMaxInterationRayAiming();
	void setMaxIterationsRayAiming(unsigned int maxInterationsRayAiming);

	// factor inf
	real getFactor_inf();
	void setFactor_inf(real factor_inf);

	// factor obj
	real getFactor_obj();
	void setFactor_obj(real factor_obj);

	// turn on robust ray aiming
	void turn_On_RobustRayAiming();
	void turn_Off_RobustRayAiming();
	bool getON_OFF_RobustRayAiming();

	// variance percent robust ray aiming
	void setVariancePercentRRA(real percent);
	real getVariancePercentRRA();

	// stay counter
	unsigned int getMaxStayCounter();
	void setMaxStayCounter(unsigned int maxStayCounter);

	// increaser factor times
	real getIncreaserFactorTimes();
	void setIncreaserFactorTimes(real increaserFactorTimes);

	// tolerance for a real light ray
	real getToleranceForRealLightRay();
	void setTolerancceForRealLightRay(real toleranceRealLightRay);

	// factor start heigh inf
	real getFactorStartHeight_inf();
	void setFactorStartHeight_inf(real factorStartHeight_inf);

	// factor start heigh obj
	real getFactorStartHeight_obj();
	void setFactorStartHeight_obj(real factorStartHeight_obj);

	// max interation robust ray aiming
	unsigned int getMaxIterationRobustRayAiming();
	void setMaxInterationRobustRayAiming(unsigned int maxInterationRRA);

	// global stop if one ray is not aimed
	void turn_ON_GlobalStopIfToManyRaysAreNotAimed();
	void turn_OFF_GlobalStopIfToManyRaysAreNotAimed();
	bool getGlobalStopIfToManyRaysAreNotAimed();

	// load all default parameters
	void loadDefaultParameter();

	// max rays that not be aimable
	void setMaxRaysThatNotBeAimable(unsigned maxRayNotAimeable);
	unsigned int getMaxRayThatNotBeAimable();

private:
	real mTolerance_XandY{};
	real mStartPointFactor{};
	unsigned int mMaxLoopsTraceToLastSurface{};
	unsigned int mMaxInterationsRayAiming{};
	real mFactor_inf{};
	real mFactor_obj{};
	bool mRobustRayAiming{};
	real mVariancePercentRobustRA{};
	unsigned int mMaxStayCounter{};
	real mIncreaserFactorTimes{};
	real mFactorStartHeight_obj{};
	real mFactorStartHeight_inf{};
	unsigned int mMaxInterationRobustRayAiming{};
	bool mGlobalStopIfOneRayIsNotAimed{};
	unsigned int mMaxRayThatNotBeAimable{};
	real mTolerance_XandYforARealLightRay{};
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

	//is there an valide intersectiom point 
	bool getIsValidInterPointInAS() const;
	void setIsValidInterPointInAS(bool isValidInterPoint);

private:
	LightRayStruct mLightRayStr{};
	VectorStructR3 mInterPointAperStop{};
	bool mIsValidInterPoint{};
};

enum class betterSide { posSide, negSide, stay };
enum class reduceWhat {reduce_X, reduce_Y, neutral};

struct lightRay_intP_dis_negPos_factor
{
	lightRay_intP_dis_negPos_factor();
	lightRay_intP_dis_negPos_factor(LightRayStruct lightRay, VectorStructR3 interPoint, real distanceX, real distanceY, betterSide negOrPos, real factorX, real factorY, VectorStructR3 targerPoint, real interations, real variancePercentRRA);
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

	// variance in percent for robust ray aiming
	real getVariangeInPercent();
	void setVariangeInPercent(real varianceInPercent);

private:
	LightRayStruct mLightRay{};
	VectorStructR3 mInterPointAS{};
	real mDistance_X{};
	real mDistance_Y{};
	betterSide mNegPosStay{};
	real mFactorX{};
	real mFactorY{};

	VectorStructR3 mTargetPoint{};
	unsigned int mInterations{};

	real mVarinaceInPercent{};
};

class RayAiming {
public: RayAiming();
		RayAiming(OpticalSystem_LLT opticalSystem);
		~RayAiming();


		// *** general *** //
		// set optical system LLT
		void setOpticalSystem_LLT(const OpticalSystem_LLT& optSys_LLT);
		// load important infomation for ray aiming
		void loadImportantInfosForRayAiming();
		// find aperture stop
		unsigned int getPositionApertureStop(OpticalSystem_LLT optSys);
		// calc all distances
		std::vector<real> calcAllDistances(const std::vector<lightRayAndInterPointAperStop> vecLightRaysAndInterPoints, const VectorStructR3& targetPoint);
		// calc distance X
		real calcDistance_X(VectorStructR3 point, VectorStructR3 targetPoint);
		// calc distance Y
		real calcDistance_Y(VectorStructR3 point, VectorStructR3 targetPoint);
		// get positon ray with lowest distance
		unsigned int getPosRayLowestDistance(std::vector<VectorStructR3> allInterPoints, VectorStructR3 targetPoint);
		// print
		void printInterP_Target_distance_X_Y(lightRay_intP_dis_negPos_factor infosToReduce);
		// shift start point ray from infinity
		VectorStructR3 RayAiming::shiftFirstSurface(real radius, real semiHeight, VectorStructR3 apexOfSphere);
		// check the light ray
		LightRayStruct checkLightRay(const LightRayStruct& lightRayToCheck, const VectorStructR3& intersecPoint, const VectorStructR3& targetPoint);
		// global stop
		bool getGlobalStop();
		void setGlobalStop(bool globalStop);
		bool checkIfThereIsAtLeastOneValidInterPoint(const std::vector<lightRayAndInterPointAperStop> vecLightRaysAndInterPoints);
		// *** *** //


		// *** ray aiming from OBJ *** //
		// Ray Aiming for a ray starting at an object point
		LightRayStruct rayAiming_obj(VectorStructR3 rayOrigin, VectorStructR3 targetPoint, Light_LLT mLight, real curRefracIndex);
		// trace all rays until all of them comes to the last surface
		lightRayAndInterPointAperStop getBestLightRayAndInterPoint_obj(LightRayStruct lightRay0, LightRayStruct lightRay1, LightRayStruct lightRay2, LightRayStruct lightRay3, LightRayStruct lightRay4, LightRayStruct lightRay5, LightRayStruct lightRay6, LightRayStruct lightRay7, LightRayStruct lightRay8, VectorStructR3 targetPoint, VectorStructR3 vectorToCalc1, VectorStructR3 vectorRoCalc2, VectorStructR3 vectorRoCalc3, VectorStructR3 vectorRoCalc4);
		// trace one ray until it comes to the last surface;
		lightRayAndInterPointAperStop traceOneRayUntilInApertureStop_obj(LightRayStruct lightRay, const VectorStructR3& vectorToCalcDir, unsigned int maxLoop);
		// check if we have to trace to neg of pos side
		lightRay_intP_dis_negPos_factor traceNegOrPosSide_andReduce_X_obj(lightRay_intP_dis_negPos_factor& initialInfos);
		lightRay_intP_dis_negPos_factor traceNegOrPosSide_andReduce_Y_obj(lightRay_intP_dis_negPos_factor& initialInfos);
		// reduce distance in x and y 
		lightRay_intP_dis_negPos_factor reduceDistancesIn_X_AND_Y_obj(lightRay_intP_dis_negPos_factor& initialInfos);
		// robust ray aiming
		lightRay_intP_dis_negPos_factor robustRayAiming_obj(lightRay_intP_dis_negPos_factor& initialInfos);
		// calculate new origin variance in percent
		lightRay_intP_dis_negPos_factor calcNewBestInfos_obj(lightRay_intP_dis_negPos_factor& initialInfos);
		// ray aiming many obj many
		std::vector<LightRayStruct> rayAimingMany_obj(const std::vector<VectorStructR3>& pointsInAS,const VectorStructR3& startPointRay, const Light_LLT& mLight, real curRefracIndex);
		std::vector<LightRayStruct> rayAimingMany_obj_complete(const OpticalSystem_LLT& optSys_LLT, const std::vector<VectorStructR3>& pointsInAS, const VectorStructR3 startPointRay, Light_LLT mLight, real curRefracIndex);
		// *** *** //



		// *** ray aiming from INF *** //
		// Ray Aiming for a ray starting at infinity
		LightRayStruct rayAiming_inf(VectorStructR3 rayDirection, VectorStructR3 targetPoint, Light_LLT mLight, real curRefracIndex);
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
		// ray aiming many obj many
		std::vector<LightRayStruct> rayAimingMany_inf(const std::vector<VectorStructR3>& pointsInAS, real angleX, real angleY, const Light_LLT& mLight, real curRefracIndex);
		std::vector<LightRayStruct> rayAimingMany_inf_complete(const OpticalSystem_LLT& optSys_LLT, const std::vector<VectorStructR3>& pointsInAS, real angleX, real angleY,  const Light_LLT& mLight, real curRefracIndex);
		// *** *** //
	
		// ** set and get defaul  parameter ** //
		// get default parameters
		defaultRayAimingStruct getDefaultParameters();
		// set default parameters
		void setDefaultParameters(defaultRayAimingStruct defaultParRayAiming);

		// tolerance
		real getTolerance_XandY();
		void setTolerance_XandY(real tolerance);

		// start point factor
		real getStartPointFactor();
		void setStartPointFactor(real startPointFactor);

		// max loops trace to last surface;
		unsigned int getMaxLoopsTraceToLastSurface();
		void setMaxLoopsTraceToLastSurface(unsigned int maxLoopLastSurf);

		// max interations ray aiming
		unsigned getMaxInterationRayAiming();
		void setMaxIterationsRayAiming(unsigned int maxInterationsRayAiming);

		// factor inf
		real getFactor_inf();
		void setFactor_inf(real factor_inf);

		// factor obj
		real getFactor_obj();
		void setFactor_obj(real factor_obj);

		// turn on robust ray aiming
		void turn_On_RobustRayAiming();
		void turn_Off_RobustRayAiming();
		bool getON_OFF_RobustRayAiming();

		// variance percent robust ray aiming
		void setVariancePercentRRA(real percent);
		real getVariancePercentRRA();

		// stay counter
		unsigned int getMaxStayCounter();
		void setMaxStayCounter(unsigned int maxStayCounter);

		// increaser factor times
		real getIncreaserFactorTimes();
		void setIncreaserFactorTimes(real increaserFactorTimes);

		// tolerance for a real light ray
		real getToleranceForRealLightRay();
		void setTolerancceForRealLightRay(real toleranceRealLightRay);

		// factor start heigh inf
		real getFactorStartHeight_inf();
		void setFactorStartHeight_inf(real factorStartHeight_inf);
		// factor start heigh obj
		real getFactorStartHeight_obj();
		void setFactorStartHeight_obj(real factorStartHeight_obj);

		// max interation robust ray aiming
		unsigned int getMaxIterationRobustRayAiming();
		void setMaxInterationRobustRayAiming(unsigned int maxInterationRRA);

		// global stop if one ray is not aimed
		void turn_ON_GlobalStopIfToManyRaysAreNotAimed();
		void turn_OFF_GlobalStopIfToManyRaysAreNotAimed();
		bool getGlobalStopIfToManyRaysAreNotAimed();

		// load all default parameters
		void loadDefaultParameter();

		// max rays that not be aimable
		void setMaxRaysThatNotBeAimable(unsigned maxRayNotAimeable);
		unsigned int getMaxRayThatNotBeAimable();
		// ** ** //

private:

	OpticalSystem_LLT mOpticalSystem_LLT{};
	unsigned int mPosApertureStop{};

	defaultRayAimingStruct mDefaultParaRayAiming{};

	real mSemiHeightFirstSurface{};
	real mRadiusFirstSurface{};
	VectorStructR3 mPositionFirstSurface{};
	VectorStructR3 mDirectionFirstSurface{};

	VectorStructR3 negLensHelper{};

	bool mGlobalSTOP{};
	unsigned int mCounter_RaysThatNotBeAimed{};


};