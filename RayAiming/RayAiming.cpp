#include "RayAiming.h"
#include <iostream>
#include <cmath>
#include <typeinfo>   // operator typeid
//#include "..\LowLevelTracing\Math_LLT.h"
//#include "..\SequentialRayTracing\SequentialRayTracer.h"
#include <iomanip> 
#include "..\oftenUseNamespace\oftenUseNamespace.h"
#include "..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"

lightRay_intP_dis_negPos_factor::lightRay_intP_dis_negPos_factor() {};
lightRay_intP_dis_negPos_factor::~lightRay_intP_dis_negPos_factor() {};

lightRay_intP_dis_negPos_factor::lightRay_intP_dis_negPos_factor(LightRayStruct lightRay, VectorStructR3 interPoint, real distanceX, real distanceY, betterSide negOrPos, real factorX, real factorY, VectorStructR3 targerPoint, real interations, real variancePercentRRA) :
	mLightRay(lightRay),
	mInterPointAS(interPoint),
	mDistance_X(distanceX),
	mDistance_Y(distanceY),
	mNegPosStay(negOrPos),
	mFactorX(factorX),
	mFactorY(factorY),
	mTargetPoint(targerPoint),
	mInterations(interations),
	mVarinaceInPercent(variancePercentRRA)
{}

// light ray
LightRayStruct lightRay_intP_dis_negPos_factor::getLightRay()
{
	return mLightRay;
}
void lightRay_intP_dis_negPos_factor::setLightRay(LightRayStruct lightRay)
{
	mLightRay = lightRay;
}

// inter point AS
VectorStructR3 lightRay_intP_dis_negPos_factor::getInterPoint()
{
	return mInterPointAS;
}
void lightRay_intP_dis_negPos_factor::setInterPoint(const VectorStructR3& interPointAS)
{
	mInterPointAS = interPointAS;
}


// distance interpoint to target
real lightRay_intP_dis_negPos_factor::getDistanceInterToTarget_X()
{
	return mDistance_X;
}
void lightRay_intP_dis_negPos_factor::setDistanceInterToTarger_X(real distanceX)
{
	mDistance_X = distanceX;
}

// distance interpoint to target Y
real lightRay_intP_dis_negPos_factor::getDistanceInterToTarget_Y()
{
	return mDistance_Y;
}
void lightRay_intP_dis_negPos_factor::setDistanceInterToTarger_Y(real distanceY)
{
	mDistance_Y = distanceY;
}

// neg or pos side
betterSide lightRay_intP_dis_negPos_factor::getNegOrPosSide()
{
	return mNegPosStay;
}
void lightRay_intP_dis_negPos_factor::setNegOrPosSide(betterSide negPosStay)
{
	mNegPosStay = negPosStay;
}

// factor X
real lightRay_intP_dis_negPos_factor::getFactorX()
{
	return mFactorX;
}
void lightRay_intP_dis_negPos_factor::setFactorX(real factorX)
{
	mFactorX = factorX;
}

// factor Y
real lightRay_intP_dis_negPos_factor::getFactorY()
{
	return mFactorY;
}
void lightRay_intP_dis_negPos_factor::setFactorY(real factorY)
{
	mFactorY = factorY;
}

// target point
VectorStructR3 lightRay_intP_dis_negPos_factor::getTargetPoint()
{
	return mTargetPoint;
}
void lightRay_intP_dis_negPos_factor::setTargetPoint(VectorStructR3 targetPoint)
{
	mTargetPoint = targetPoint;
}

// get interations
unsigned int lightRay_intP_dis_negPos_factor::getInterations()
{
	return mInterations;
}
void lightRay_intP_dis_negPos_factor::setInterations(unsigned int interations)
{
	mInterations = interations;
}

// variance in percent for robust ray aiming
real lightRay_intP_dis_negPos_factor::getVariangeInPercent()
{
	return mVarinaceInPercent;
}
void lightRay_intP_dis_negPos_factor::setVariangeInPercent(real varianceInPercent)
{
	mVarinaceInPercent = varianceInPercent;
}

// light ray
LightRayStruct lightRayAndInterPointAperStop::getLightRay() const
{
	return mLightRayStr;
}
void lightRayAndInterPointAperStop::setLightRay(const LightRayStruct& lightRay)
{
	mLightRayStr = lightRay;
}

//inter point aper stop
VectorStructR3 lightRayAndInterPointAperStop::getInterPointAperStop() const
{
	return mInterPointAperStop;
}
void lightRayAndInterPointAperStop::setInterPointAperStop(const VectorStructR3& interPointAperStop)
{
	mInterPointAperStop = interPointAperStop;
}

//is there an valide intersectiom point 
bool lightRayAndInterPointAperStop::getIsValidInterPointInAS() const
{
	return mIsValidInterPoint;
}
void lightRayAndInterPointAperStop::setIsValidInterPointInAS(bool isValidInterPoint)
{
	mIsValidInterPoint = isValidInterPoint;
}


// tolerance
real defaultRayAimingStruct::getTolerance_XandY()
{
	return mTolerance_XandY;
}
void defaultRayAimingStruct::setTolerance_XandY(real tolerance)
{
	mTolerance_XandY = tolerance;
}

// start point factor
real defaultRayAimingStruct::getStartPointFactor()
{
	return mStartPointFactor;
}
void defaultRayAimingStruct::setStartPointFactor(real startPointFactor)
{
	mStartPointFactor = startPointFactor;
}

// max loops trace to last surface;
unsigned int defaultRayAimingStruct::getMaxLoopsTraceToLastSurface()
{
	return mMaxLoopsTraceToLastSurface;
}
void defaultRayAimingStruct::setMaxLoopsTraceToLastSurface(unsigned int maxLoopLastSurf)
{
	mMaxLoopsTraceToLastSurface = maxLoopLastSurf;
}

// max interations ray aiming
unsigned defaultRayAimingStruct::getMaxInterationRayAiming()
{
	return mMaxInterationsRayAiming;
}
void defaultRayAimingStruct::setMaxIterationsRayAiming(unsigned int maxInterationsRayAiming)
{
	mMaxInterationsRayAiming = maxInterationsRayAiming;
}

// factor inf
real defaultRayAimingStruct::getFactor_inf()
{
	return mFactor_inf;
}
void defaultRayAimingStruct::setFactor_inf(real factor_inf)
{
	mFactor_inf = factor_inf;
}

// factor obj
real defaultRayAimingStruct::getFactor_obj()
{
	return mFactor_obj;
}
void defaultRayAimingStruct::setFactor_obj(real factor_obj)
{
	mFactor_obj = factor_obj;
}

// turn on robust ray aiming
void defaultRayAimingStruct::turn_On_RobustRayAiming()
{
	mRobustRayAiming = true;
}
void defaultRayAimingStruct::turn_Off_RobustRayAiming()
{
	mRobustRayAiming = false;
}
bool defaultRayAimingStruct::getON_OFF_RobustRayAiming()
{
	return mRobustRayAiming;
}

// variance percent robust ray aiming
void defaultRayAimingStruct::setVariancePercentRRA(real percent)
{
	mVariancePercentRobustRA = percent;
}
real defaultRayAimingStruct::getVariancePercentRRA()
{
	return mVariancePercentRobustRA;
}

// stay counter
unsigned int defaultRayAimingStruct::getMaxStayCounter()
{
	return mMaxStayCounter;
}
void defaultRayAimingStruct::setMaxStayCounter(unsigned int maxStayCounter)
{
	mMaxStayCounter = maxStayCounter;
}

// increaser factor times
real defaultRayAimingStruct::getIncreaserFactorTimes()
{
	return mIncreaserFactorTimes;
}
void defaultRayAimingStruct::setIncreaserFactorTimes(real increaserFactorTimes)
{
	mIncreaserFactorTimes = increaserFactorTimes;
}

// tolerance for a real light ray
real defaultRayAimingStruct::getToleranceForRealLightRay()
{
	return mTolerance_XandYforARealLightRay;
}
void defaultRayAimingStruct::setTolerancceForRealLightRay(real toleranceRealLightRay)
{
	mTolerance_XandYforARealLightRay = toleranceRealLightRay;
}

// factor start heigh inf
real defaultRayAimingStruct::getFactorStartHeight_inf()
{
	return mFactorStartHeight_inf;
}
void defaultRayAimingStruct::setFactorStartHeight_inf(real factorStartHeight_inf)
{
	mFactorStartHeight_inf = factorStartHeight_inf;
}
// factor start heigh obj
real defaultRayAimingStruct::getFactorStartHeight_obj()
{
	return mFactorStartHeight_obj;
}
void defaultRayAimingStruct::setFactorStartHeight_obj(real factorStartHeight_obj)
{
	mFactorStartHeight_obj = factorStartHeight_obj;
}

// max interation robust ray aiming
unsigned int defaultRayAimingStruct::getMaxIterationRobustRayAiming()
{
	return mMaxInterationRobustRayAiming;
}
void defaultRayAimingStruct::setMaxInterationRobustRayAiming(unsigned int maxInterationRRA)
{
	mMaxInterationRobustRayAiming = maxInterationRRA;
}

// global stop if one ray is not aimed
void defaultRayAimingStruct::turn_ON_GlobalStopIfToManyRaysAreNotAimed()
{
	mGlobalStopIfOneRayIsNotAimed = true;
}
void defaultRayAimingStruct::turn_OFF_GlobalStopIfToManyRaysAreNotAimed()
{
	mGlobalStopIfOneRayIsNotAimed = false;
}

bool defaultRayAimingStruct::getGlobalStopIfToManyRaysAreNotAimed()
{
	return mGlobalStopIfOneRayIsNotAimed;
}

// max rays that not be aimable
void defaultRayAimingStruct::setMaxRaysThatNotBeAimable(unsigned maxRayNotAimeable)
{
	mMaxRayThatNotBeAimable = maxRayNotAimeable;
}
unsigned int defaultRayAimingStruct::getMaxRayThatNotBeAimable()
{
	return mMaxRayThatNotBeAimable;
}

void defaultRayAimingStruct::loadDefaultParameter()
{
	mTolerance_XandY = 0.0001;
	mStartPointFactor = 1.0;
	mMaxLoopsTraceToLastSurface = 5;
	mMaxInterationsRayAiming = 50;
	mFactor_inf = 0.1;
	mFactor_obj = 0.1;
	turn_On_RobustRayAiming();
	mVariancePercentRobustRA = 5.0;
	mMaxStayCounter = 2;
	mIncreaserFactorTimes = 10.0;
	mTolerance_XandYforARealLightRay = 0.1;
	mFactorStartHeight_inf = 0.5;
	mFactorStartHeight_obj = 0.5;
	mMaxInterationRobustRayAiming = 5;
	mMaxRayThatNotBeAimable = 5;
	
}

RayAiming::RayAiming() {};
RayAiming::~RayAiming() {};

RayAiming::RayAiming(OpticalSystem_LLT opticalSystem) :
	mOpticalSystem_LLT(opticalSystem)
{
	loadImportantInfosForRayAiming();
};

// set optical system LLT
void RayAiming::setOpticalSystem_LLT(const OpticalSystem_LLT& optSys_LLT)
{
	mOpticalSystem_LLT = optSys_LLT;
}

// load important infomation for ray aiming
void RayAiming::loadImportantInfosForRayAiming()
{
	mSemiHeightFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface().at(0).getSurfaceInterRay_ptr()->getSemiHeight();
	mRadiusFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface().at(0).getSurfaceInterRay_ptr()->getRadius();
	mPositionFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface().at(0).getSurfaceInterRay_ptr()->getPoint();
	mDirectionFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface().at(0).getSurfaceInterRay_ptr()->getDirection();
	mPosApertureStop = mOpticalSystem_LLT.getPosApertureStop();

	mDefaultParaRayAiming.loadDefaultParameter();
	mCounter_RaysThatNotBeAimed = 0;
	mGlobalSTOP = false;
}



// trace one ray until it comes to the last surface;
lightRayAndInterPointAperStop RayAiming::traceOneRayUntilInApertureStop_inf(LightRayStruct lightRay, unsigned int maxLoop)
{
	lightRayAndInterPointAperStop tempLightRayAndInterPointAS{};

	unsigned int loopCounter = 0;
	VectorStructR3 interpointApertureStop{};

	SequentialRayTracing seqTrace(mOpticalSystem_LLT);
	// trace ray only to aperture stop
	seqTrace.setTraceToSurface(mPosApertureStop);
	// trace the light ray
	seqTrace.sequentialRayTracing(lightRay);



	real curRefIndex = lightRay.getRay_LLT().getCurrentRefractiveIndex();
	VectorStructR3 DirectionUnit = lightRay.getRay_LLT().getDirectionRayUnit();

	real rayOriginX;
	real rayOriginY;
	real rayOriginZ;
	VectorStructR3 newOrigin;
	Ray_LLT newRay;

	//unsigned int posLastSurface = mOpticalSystem_LLT.getPosAndInteractingSurface().size() - 1;
	bool ray_NOT_AtLastSurface = true;
	// check if light ray comes to last surface
	while (ray_NOT_AtLastSurface)
	{
		surfaceSide surfSide = seqTrace.getAllInterInfosOfSurf_i_notFiltered(mPosApertureStop)[loopCounter].getSurfaceSide();

		if (N == surfSide)
		{
			// build new ray to trace
			rayOriginX = lightRay.getRay_LLT().getOriginRay().getX();
			rayOriginY = lightRay.getRay_LLT().getOriginRay().getY();
			rayOriginZ = lightRay.getRay_LLT().getOriginRay().getZ();

			newOrigin = { rayOriginX * 0.5, rayOriginY * 0.5, rayOriginZ };

			newRay.setCurrentRefractiveIndex(curRefIndex);
			newRay.setDirectionRayUnit(DirectionUnit);
			newRay.setDirectionRayUnit(DirectionUnit);
			newRay.setOriginRay(newOrigin);

			lightRay.setRay_LLT(newRay);

			// trace new ray
			seqTrace.sequentialRayTracing(lightRay);
		}

		else if (A == surfSide || B == surfSide) // ray comes to the last surface
		{
			ray_NOT_AtLastSurface = false;
			tempLightRayAndInterPointAS.setInterPointAperStop(seqTrace.getAllInterPointsAtSurf_i_notFiltered(mPosApertureStop).back());
			tempLightRayAndInterPointAS.setLightRay(lightRay);
			tempLightRayAndInterPointAS.setIsValidInterPointInAS(true);

			return tempLightRayAndInterPointAS;
		}

		if (loopCounter > maxLoop)
		{
			//just for debugging
			//std::cout << "we could not trace the ray until the aperture stop. Maybe there is a mistake doing ray aiming" << std::endl;
			ray_NOT_AtLastSurface = false; // -> get out of the loop
			tempLightRayAndInterPointAS.setIsValidInterPointInAS(false);
		}

		++loopCounter;

	}



	return tempLightRayAndInterPointAS;
}

// trace all rays until all of them comes to the last surface
lightRayAndInterPointAperStop RayAiming::getBestLightRayAndInterPoint_inf(LightRayStruct lightRay0, LightRayStruct lightRay1, LightRayStruct lightRay2, LightRayStruct lightRay3, LightRayStruct lightRay4, VectorStructR3 targetPoint)
{
	lightRayAndInterPointAperStop bestLightRayAndInterPoint;

	std::vector<lightRayAndInterPointAperStop> lightRayAndInterPointAS;
	lightRayAndInterPointAS.resize(5);
	unsigned maxLoops = mDefaultParaRayAiming.getMaxLoopsTraceToLastSurface();

	lightRayAndInterPointAS.at(0) = traceOneRayUntilInApertureStop_inf(lightRay0, maxLoops);
	lightRayAndInterPointAS.at(1) = traceOneRayUntilInApertureStop_inf(lightRay1, maxLoops);
	lightRayAndInterPointAS.at(2) = traceOneRayUntilInApertureStop_inf(lightRay2, maxLoops);
	lightRayAndInterPointAS.at(3) = traceOneRayUntilInApertureStop_inf(lightRay3, maxLoops);
	lightRayAndInterPointAS.at(4) = traceOneRayUntilInApertureStop_inf(lightRay4, maxLoops);

	std::vector<real> dis = calcAllDistances(lightRayAndInterPointAS, targetPoint);

	// ValueInVectorNearZeroPosSide geändert.
	VectorElementAndPosition minDisAndPos = Math::ValueInVectorNearZeroPosSide(dis);

	unsigned int posBestInterPoint = minDisAndPos.getPosInVector();

	// just for debugging
	VectorStructR3 bestInterPoint = lightRayAndInterPointAS[posBestInterPoint].getInterPointAperStop();
	
	//just for debugging
	//std::cout << "best inter point: " << std::endl;
	//just for debugging
	//bestInterPoint.print();
	//just for debugging
	//std::cout << "target point: " << std::endl;
	//just for debugging
	//targetPoint.print();

	bestLightRayAndInterPoint.setLightRay(lightRayAndInterPointAS[posBestInterPoint].getLightRay());
	bestLightRayAndInterPoint.setInterPointAperStop(lightRayAndInterPointAS[posBestInterPoint].getInterPointAperStop());


	return bestLightRayAndInterPoint;

}

// Ray-Aiming main-method. 



//_______________________________________________
// find aperture stop
unsigned RayAiming::getPositionApertureStop(OpticalSystem_LLT optSys)
{
	std::vector<PosAndIntsectionSurfaceStruct> posAndInteraSurfaceVector = optSys.getPosAndInteractingSurface();
	int positionAperture = -1;
	ApertureStop_LLT apertureStop_ptr;
	unsigned checkNumerOfApertureStops = 0;

	for (unsigned int i = 0; i < posAndInteraSurfaceVector.size(); i++)
	{
		if (typeid(*posAndInteraSurfaceVector.at(i).getSurfaceInterRay_ptr()) == typeid(apertureStop_ptr))
		{
			positionAperture = posAndInteraSurfaceVector.at(i).getPosition();
			checkNumerOfApertureStops++;
			if (positionAperture != i)
			{
				//just for debugging
				std::cout << "there is maybe a mistake in the position of the apertrure stop\n";
			}

		}
	}


	// check if there is no or more than one aperture stop -> this would be a mistake in an optical system
	if (checkNumerOfApertureStops != 1)
	{
		positionAperture = -1;
		//just for debugging
		std::cout << "there is no or more than one aperture stop in your optical system!\n";
	}

	return positionAperture;
}



//_______________________________________________
//_______________________________________________

// Ray Aiming for a ray starting at infinity
LightRayStruct RayAiming::rayAiming_inf(VectorStructR3 rayDirection, VectorStructR3 targetPoint, Light_LLT mLight, real curRefracIndex)
{

	LightRayStruct lightRayi;
	real startPointFactor = mDefaultParaRayAiming.getStartPointFactor();

	if (mPosApertureStop == 0)
	{
		// tan(a) = Gegenkath / Ankath
		real tanDegreeXZ = rayDirection.getX() / rayDirection.getZ();
		real tanDegreeYZ = rayDirection.getY() / rayDirection.getZ();
		real startPointX = targetPoint.getX() - tanDegreeXZ * startPointFactor;
		real startPointY = targetPoint.getY() - tanDegreeYZ * startPointFactor;
		real startPointZ = targetPoint.getZ() - startPointFactor;
		VectorStructR3 startPoint = { startPointX , startPointY, startPointZ };


		Ray_LLT startRayInfinity(startPoint, rayDirection, curRefracIndex);

		lightRayi.setRay_LLT(startRayInfinity);
		lightRayi.setLight_LLT(mLight);


	}
	else
	{
		//std::shared_ptr<SurfaceIntersectionRay_LLT> firstSurface_ptr = mOpticalSystem_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr();

		VectorStructR3 startPoint = mPositionFirstSurface;
		//VectorStructR3 directionFirstSurface = firstSurface_ptr->getDirection();
		real directionFirstSurface_Z = mDirectionFirstSurface.getZ();
		//real semiHeightFirstSurface = firstSurface_ptr->getSemiHeight();
		// check if first surface is negativ
		if (directionFirstSurface_Z < 0)
		{		
			startPoint = shiftFirstSurface(mRadiusFirstSurface, mSemiHeightFirstSurface, mPositionFirstSurface);
		}
		startPoint.setZ(startPoint.getZ() - mDefaultParaRayAiming.getStartPointFactor());

		// build first ray for ray aiming

		VectorStructR3 BaseVecor1 = { 1.0,1.0,0.0 };
		VectorStructR3 BaseVecor2 = { 1.0,-1.0,0.0 };

		VectorStructR3 Vector1ToCalcDir = mDefaultParaRayAiming.getFactorStartHeight_inf() * mSemiHeightFirstSurface * Math::unitVector(Math::DoCrossProduct(BaseVecor1, mDirectionFirstSurface));
		VectorStructR3 Vector2ToCalcDir = mDefaultParaRayAiming.getFactorStartHeight_inf() * mSemiHeightFirstSurface * Math::unitVector(Math::DoCrossProduct(BaseVecor2, mDirectionFirstSurface));

		VectorStructR3 startPointRay0 = { startPoint.getX() - Vector1ToCalcDir.getX(), startPoint.getY() - Vector1ToCalcDir.getY(), startPoint.getZ()};
		VectorStructR3 startPointRay1 = { startPoint.getX() + Vector1ToCalcDir.getX(), startPoint.getY() - Vector1ToCalcDir.getY(), startPoint.getZ()};
		VectorStructR3 startPointRay2 = { startPoint.getX() - Vector1ToCalcDir.getX(), startPoint.getY() + Vector1ToCalcDir.getY(), startPoint.getZ()};
		VectorStructR3 startPointRay3 = { startPoint.getX() + Vector1ToCalcDir.getX(), startPoint.getY() + Vector1ToCalcDir.getY(), startPoint.getZ()};
		VectorStructR3 startPointRay4 = { startPoint.getX(), startPoint.getY(), startPoint.getZ()};

		Ray_LLT startRay0(startPointRay0, rayDirection, curRefracIndex);
		Ray_LLT startRay1(startPointRay1, rayDirection, curRefracIndex);
		Ray_LLT startRay2(startPointRay2, rayDirection, curRefracIndex);
		Ray_LLT startRay3(startPointRay3, rayDirection, curRefracIndex);
		Ray_LLT startRay4(startPointRay4, rayDirection, curRefracIndex);

		LightRayStruct lightRayStart0(mLight, startRay0, 1.0);
		LightRayStruct lightRayStart1(mLight, startRay1, 1.0);
		LightRayStruct lightRayStart2(mLight, startRay2, 1.0);
		LightRayStruct lightRayStart3(mLight, startRay3, 1.0);
		LightRayStruct lightRayStart4(mLight, startRay4, 1.0);


		// trace all rays until all of them comes to the last surface
		lightRayAndInterPointAperStop bestLightRayAndInterPoint = getBestLightRayAndInterPoint_inf(lightRayStart0, lightRayStart1, lightRayStart2, lightRayStart3, lightRayStart4, targetPoint);

		LightRayStruct bestLightRay = bestLightRayAndInterPoint.getLightRay();
		VectorStructR3 interPointBestLightRay = bestLightRayAndInterPoint.getInterPointAperStop();

		real disXtoTarget = calcDistance_X(targetPoint, interPointBestLightRay);
		real disYtoTarget = calcDistance_Y(targetPoint, interPointBestLightRay);

		int maxInteration = mDefaultParaRayAiming.getMaxInterationRayAiming();

		unsigned int curInteration = 0;
		lightRay_intP_dis_negPos_factor infosToReduce(bestLightRay, interPointBestLightRay, disXtoTarget, disYtoTarget, betterSide::stay, mDefaultParaRayAiming.getFactor_inf(), mDefaultParaRayAiming.getFactor_inf(), targetPoint, curInteration, mDefaultParaRayAiming.getVariancePercentRRA());


		// reduce distance in X and Y
		infosToReduce = reduceDistancesIn_X_AND_Y_inf(infosToReduce);

		curInteration = infosToReduce.getInterations();

		if (curInteration >= maxInteration && mGlobalSTOP == false)
		{

			//just for debuggings
			//printInterP_Target_distance_X_Y(infosToReduce);

			// here we can start robust ray aiming!
			if (mDefaultParaRayAiming.getON_OFF_RobustRayAiming())
			{
				//just for debugging
				//std::cout << "start robust ray aiming" << std::endl;
				
				infosToReduce = robustRayAiming_inf(infosToReduce);

				//just for debugging
				//std::cout << "results from robust ray aiming" << std::endl;
				//just for debugging
				//printInterP_Target_distance_X_Y(infosToReduce);
			}

			else // no robust ray aiming
			{ 
			//just for debugging
			//std::cout << "attention!!! ray aiming did not work perfectly!!!" << std::endl;
			//std::cout << "maybe it would help to turn on robust ray aiming!!!" << std::endl;
			//std::cout << "maybe the results are not correct!" << std::endl;
			}
		}


		lightRayi = checkLightRay(infosToReduce.getLightRay(), infosToReduce.getInterPoint(), infosToReduce.getTargetPoint());
	}

	return lightRayi;
}


// calc all distances
std::vector<real> RayAiming::calcAllDistances(const std::vector<lightRayAndInterPointAperStop> vecLightRaysAndInterPoints, const VectorStructR3& targetPoint)
{
	unsigned int size = vecLightRaysAndInterPoints.size();
	real distance{};
	std::vector<real> allDistances{};
	allDistances.resize(size);

	checkIfThereIsAtLeastOneValidInterPoint(vecLightRaysAndInterPoints);

	for (unsigned int i = 0; i < size; ++i)
	{
		if (vecLightRaysAndInterPoints[i].getIsValidInterPointInAS())
		{
			distance = Math::distanceTwoVectors(vecLightRaysAndInterPoints[i].getInterPointAperStop(), targetPoint);
		}
		
		else
		{
			distance = oftenUse::getInfReal();
		}

		allDistances[i] = distance;
	}

	return allDistances;
}

bool RayAiming::checkIfThereIsAtLeastOneValidInterPoint(const std::vector<lightRayAndInterPointAperStop> vecLightRaysAndInterPoints)
{
	unsigned int size = vecLightRaysAndInterPoints.size();
	bool tempValidInterPoint{};
	bool isOnValidInterPoint = false;

	for (unsigned int i=0; i<size;++i)
	{
		if (tempValidInterPoint = vecLightRaysAndInterPoints[i].getIsValidInterPointInAS())
		{
			return true;
		}
	}

	if (isOnValidInterPoint == false)
	{
		std::cout << "ATTENTION: There is no valid intersection point at the aperture stop by the first guess" << std::endl;
		mGlobalSTOP = true;
	}

	return isOnValidInterPoint;
}

// calc distance X
real RayAiming::calcDistance_X(VectorStructR3 point, VectorStructR3 targetPoint)
{
	return std::abs(point.getX() - targetPoint.getX());
}
// calc distance Y
real RayAiming::calcDistance_Y(VectorStructR3 point, VectorStructR3 targetPoint)
{
	return std::abs(point.getY() - targetPoint.getY());
}


// check if we have to trace to neg of pos side
lightRay_intP_dis_negPos_factor RayAiming::traceNegOrPosSide_andReduce_X_inf(lightRay_intP_dis_negPos_factor initialInfos)
{
	lightRay_intP_dis_negPos_factor returnLightRay_intP_dis_negPos_fac;
	returnLightRay_intP_dis_negPos_fac.setVariangeInPercent(initialInfos.getVariangeInPercent());
	real initialFactorY = initialInfos.getFactorY();
	VectorStructR3 targetPoint = initialInfos.getTargetPoint();
	unsigned int initialInterations = initialInfos.getInterations();

	returnLightRay_intP_dis_negPos_fac.setInterations(++initialInterations);
	returnLightRay_intP_dis_negPos_fac.setTargetPoint(targetPoint);

	//real semiHeightFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getSemiHeight();

	LightRayStruct initialLightRay = initialInfos.getLightRay();
	VectorStructR3 initialPointAS = initialInfos.getInterPoint();
	real initialDistanceX = initialInfos.getDistanceInterToTarget_X();
	betterSide initialNegPosStay = initialInfos.getNegOrPosSide();
	real initialFactorX = initialInfos.getFactorX();



	VectorStructR3 originPlus = initialLightRay.getRay_LLT().getOriginRay();
	VectorStructR3 originNeg = initialLightRay.getRay_LLT().getOriginRay();

	LightRayStruct lightRayToTracePos = initialLightRay;
	LightRayStruct lightRayToTraceNeg = initialLightRay;

	real initialOrigin_X = originPlus.getX();
	real originPlus_X = initialOrigin_X + mSemiHeightFirstSurface * initialFactorX;
	real originMinus_X = initialOrigin_X - mSemiHeightFirstSurface * initialFactorX;
	originPlus.setX(originPlus_X);
	originNeg.setX(originMinus_X);

	Ray_LLT rayPos = lightRayToTracePos.getRay_LLT();
	rayPos.setOriginRay(originPlus);
	lightRayToTracePos.setRay_LLT(rayPos);

	Ray_LLT rayNeg = lightRayToTraceNeg.getRay_LLT();
	rayNeg.setOriginRay(originNeg);
	lightRayToTraceNeg.setRay_LLT(rayNeg);

	// pos trace
	SequentialRayTracing tracePLus(mOpticalSystem_LLT);
	tracePLus.setTraceToSurface(mPosApertureStop);
	tracePLus.sequentialRayTracing(lightRayToTracePos);

	// neg trace
	SequentialRayTracing traceNeg(mOpticalSystem_LLT);
	traceNeg.setTraceToSurface(mPosApertureStop);
	traceNeg.sequentialRayTracing(lightRayToTraceNeg);

	IntersectInformationStruct interPointAS_pos = tracePLus.getAllInterInfosOfSurf_i_notFiltered(mPosApertureStop)[0];
	IntersectInformationStruct interPointAS_neg = traceNeg.getAllInterInfosOfSurf_i_notFiltered(mPosApertureStop)[0];

	// pos trace
	real disPosTrace_X = calcDistance_X(interPointAS_pos.getIntersectionPoint(), targetPoint);
	real disPosTrace_Y = calcDistance_Y(interPointAS_pos.getIntersectionPoint(), targetPoint);

	// neg trace
	real disNegTrace_X = calcDistance_X(interPointAS_neg.getIntersectionPoint(), targetPoint);
	real disNegTrace_Y = calcDistance_Y(interPointAS_neg.getIntersectionPoint(), targetPoint);

	if (disPosTrace_X <= disNegTrace_X && interPointAS_pos.getSurfaceSide() != N)
	{
		if (disPosTrace_X <= initialDistanceX)
		{
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_Y(disPosTrace_Y);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY);

			returnLightRay_intP_dis_negPos_fac.setLightRay(lightRayToTracePos);
			returnLightRay_intP_dis_negPos_fac.setInterPoint(interPointAS_pos.getIntersectionPoint());
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_X(disPosTrace_X);
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(betterSide::posSide);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.9);

		}
		else if (initialDistanceX <= disPosTrace_X)
		{
			returnLightRay_intP_dis_negPos_fac = initialInfos;
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(betterSide::stay);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.9);
		}



	}

	else if (disNegTrace_X < disPosTrace_X && interPointAS_neg.getSurfaceSide() != N)
	{

		if (disNegTrace_X < initialDistanceX)
		{
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_Y(disNegTrace_Y);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY);

			returnLightRay_intP_dis_negPos_fac.setLightRay(lightRayToTraceNeg);
			returnLightRay_intP_dis_negPos_fac.setInterPoint(interPointAS_neg.getIntersectionPoint());
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_X(disNegTrace_X);
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(betterSide::negSide);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.9);

		}
		else if (initialDistanceX < disNegTrace_X)
		{
			returnLightRay_intP_dis_negPos_fac = initialInfos;
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(betterSide::stay);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.9);
		}

	}

	else // there is no intersection point with the aperture stop
	{
		returnLightRay_intP_dis_negPos_fac = initialInfos;
		returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(betterSide::stay);
		returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.5);
	}


	return returnLightRay_intP_dis_negPos_fac;
}

lightRay_intP_dis_negPos_factor RayAiming::traceNegOrPosSide_andReduce_Y_inf(lightRay_intP_dis_negPos_factor initialInfos)
{
	lightRay_intP_dis_negPos_factor returnLightRay_intP_dis_negPos_fac;
	returnLightRay_intP_dis_negPos_fac.setVariangeInPercent(initialInfos.getVariangeInPercent());
	real initalFactorX = initialInfos.getFactorX();
	//real semiHeightFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getSemiHeight();
	VectorStructR3 targetPoint = initialInfos.getTargetPoint();

	unsigned int initialInterations = initialInfos.getInterations();
	returnLightRay_intP_dis_negPos_fac.setInterations(++initialInterations);
	returnLightRay_intP_dis_negPos_fac.setTargetPoint(targetPoint);

	LightRayStruct initialLightRay = initialInfos.getLightRay();
	VectorStructR3 initialPointAS = initialInfos.getInterPoint();
	real initialDistanceY = initialInfos.getDistanceInterToTarget_Y();
	betterSide initialNegPosStay = initialInfos.getNegOrPosSide();
	real initialFactorY = initialInfos.getFactorY();



	VectorStructR3 originPlus = initialLightRay.getRay_LLT().getOriginRay();
	VectorStructR3 originNeg = initialLightRay.getRay_LLT().getOriginRay();

	LightRayStruct lightRayToTracePos = initialLightRay;
	LightRayStruct lightRayToTraceNeg = initialLightRay;

	real initialOrigin_Y = originPlus.getY();
	real originPlus_Y = initialOrigin_Y + mSemiHeightFirstSurface * initialFactorY;
	real originMinus_Y = initialOrigin_Y - mSemiHeightFirstSurface * initialFactorY;
	originPlus.setY(originPlus_Y);
	//just for debugging
	//std::cout << "reduce Y pos origin Y: " << originPlus.getY() << std::endl;
	originNeg.setY(originMinus_Y);
	//just for debugging
	//std::cout << "reduce Y neg origin Y: " << originNeg.getY() << std::endl;

	Ray_LLT rayPos = lightRayToTracePos.getRay_LLT();
	rayPos.setOriginRay(originPlus);
	lightRayToTracePos.setRay_LLT(rayPos);

	Ray_LLT rayNeg = lightRayToTraceNeg.getRay_LLT();
	rayNeg.setOriginRay(originNeg);
	lightRayToTraceNeg.setRay_LLT(rayNeg);

	// pos trace
	SequentialRayTracing tracePLus(mOpticalSystem_LLT);
	tracePLus.sequentialRayTracing(lightRayToTracePos);

	// neg trace
	SequentialRayTracing traceNeg(mOpticalSystem_LLT);
	traceNeg.sequentialRayTracing(lightRayToTraceNeg);

	IntersectInformationStruct interPointAS_pos = tracePLus.getAllInterInfosOfSurf_i_notFiltered(mPosApertureStop)[0];
	IntersectInformationStruct interPointAS_neg = traceNeg.getAllInterInfosOfSurf_i_notFiltered(mPosApertureStop)[0];

	//disPosTrace_Y = Math::distanceTwoVectors(interPointAS_pos, targetPoint);

	real disPosTrace_Y = calcDistance_Y(interPointAS_pos.getIntersectionPoint(), targetPoint);
	real disPosTrace_X = calcDistance_X(interPointAS_pos.getIntersectionPoint(), targetPoint);
	//just for debugging
	//std::cout << "reduce Y disPosTrace Y: " << disPosTrace_Y << std::endl;
	real disNegTrace_Y = calcDistance_Y(interPointAS_neg.getIntersectionPoint(), targetPoint);
	real disNegTrace_X = calcDistance_X(interPointAS_neg.getIntersectionPoint(), targetPoint);
	//just for debugging
	//std::cout << "reduce Y disNegTrace Y: " << disNegTrace_Y << std::endl;


	if (disPosTrace_Y <= disNegTrace_Y && interPointAS_pos.getSurfaceSide() != N)
	{
		if (disPosTrace_Y <= initialDistanceY)
		{
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_X(disPosTrace_X);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initalFactorX);

			returnLightRay_intP_dis_negPos_fac.setLightRay(lightRayToTracePos);
			returnLightRay_intP_dis_negPos_fac.setInterPoint(interPointAS_pos.getIntersectionPoint());
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_Y(disPosTrace_Y);
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(betterSide::posSide);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.9);

		}
		else if (initialDistanceY <= disPosTrace_Y)
		{
			returnLightRay_intP_dis_negPos_fac = initialInfos;
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(betterSide::stay);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.9);
		}



	}

	else if (disNegTrace_Y < disPosTrace_Y && interPointAS_neg.getSurfaceSide() != N)
	{

		if (disNegTrace_Y < initialDistanceY)
		{
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_X(disNegTrace_X);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initalFactorX);

			returnLightRay_intP_dis_negPos_fac.setLightRay(lightRayToTraceNeg);
			returnLightRay_intP_dis_negPos_fac.setInterPoint(interPointAS_neg.getIntersectionPoint());
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_Y(disNegTrace_Y);
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(betterSide::negSide);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.9);

		}
		else if (initialDistanceY < disNegTrace_Y)
		{
			returnLightRay_intP_dis_negPos_fac = initialInfos;
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(betterSide::stay);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.9);
		}

	}

	else // there is no intersection point with the aperture stop
	{
		returnLightRay_intP_dis_negPos_fac = initialInfos;
		returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(betterSide::stay);
		returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.5);
	}



	return returnLightRay_intP_dis_negPos_fac;
}

// get default parameters


// ** set and get defaul  parameter ** //
defaultRayAimingStruct RayAiming::getDefaultParameters()
{
	return mDefaultParaRayAiming;
}
// set default parameters
void RayAiming::setDefaultParameters(defaultRayAimingStruct defaultParRayAiming)
{
	mDefaultParaRayAiming = defaultParRayAiming;
}

// tolerance
real RayAiming::getTolerance_XandY()
{
	return mDefaultParaRayAiming.getTolerance_XandY();
}
void RayAiming::setTolerance_XandY(real tolerance)
{
	mDefaultParaRayAiming.setTolerance_XandY(tolerance);
}

// start point factor
real RayAiming::getStartPointFactor()
{
	return mDefaultParaRayAiming.getStartPointFactor();
}
void RayAiming::setStartPointFactor(real startPointFactor)
{
	mDefaultParaRayAiming.setStartPointFactor(startPointFactor);
}

// max loops trace to last surface;
unsigned int RayAiming::getMaxLoopsTraceToLastSurface()
{
	return mDefaultParaRayAiming.getMaxLoopsTraceToLastSurface();
}
void RayAiming::setMaxLoopsTraceToLastSurface(unsigned int maxLoopLastSurf)
{
	mDefaultParaRayAiming.setMaxLoopsTraceToLastSurface(maxLoopLastSurf);
}

// max interations ray aiming
unsigned RayAiming::getMaxInterationRayAiming()
{
	return mDefaultParaRayAiming.getMaxInterationRayAiming();
}
void RayAiming::setMaxIterationsRayAiming(unsigned int maxInterationsRayAiming)
{
	mDefaultParaRayAiming.setMaxIterationsRayAiming(maxInterationsRayAiming);
}

// factor inf
real RayAiming::getFactor_inf()
{
	return mDefaultParaRayAiming.getFactor_inf();
}
void RayAiming::setFactor_inf(real factor_inf)
{
	mDefaultParaRayAiming.setFactor_inf(factor_inf);
}

// factor obj
real RayAiming::getFactor_obj()
{
	return mDefaultParaRayAiming.getFactor_obj();
}
void RayAiming::setFactor_obj(real factor_obj)
{
	mDefaultParaRayAiming.setFactor_obj(factor_obj);
}

// turn on robust ray aiming
void RayAiming::turn_On_RobustRayAiming()
{
	mDefaultParaRayAiming.turn_On_RobustRayAiming();
}
void RayAiming::turn_Off_RobustRayAiming()
{
	mDefaultParaRayAiming.turn_Off_RobustRayAiming();
}
bool RayAiming::getON_OFF_RobustRayAiming()
{
	return mDefaultParaRayAiming.getON_OFF_RobustRayAiming();
}

// variance percent robust ray aiming
void RayAiming::setVariancePercentRRA(real percent)
{
	mDefaultParaRayAiming.setVariancePercentRRA(percent);
}
real RayAiming::getVariancePercentRRA()
{
	return mDefaultParaRayAiming.getVariancePercentRRA();
}

// stay counter
unsigned int RayAiming::getMaxStayCounter()
{
	return mDefaultParaRayAiming.getMaxStayCounter();
}
void RayAiming::setMaxStayCounter(unsigned int maxStayCounter)
{
	mDefaultParaRayAiming.setMaxStayCounter(maxStayCounter);
}

// increaser factor times
real RayAiming::getIncreaserFactorTimes()
{
	return mDefaultParaRayAiming.getIncreaserFactorTimes();
}
void RayAiming::setIncreaserFactorTimes(real increaserFactorTimes)
{
	mDefaultParaRayAiming.setIncreaserFactorTimes(increaserFactorTimes);
}

// tolerance for a real light ray
real RayAiming::getToleranceForRealLightRay()
{
	return mDefaultParaRayAiming.getToleranceForRealLightRay();
}
void RayAiming::setTolerancceForRealLightRay(real toleranceRealLightRay)
{
	mDefaultParaRayAiming.setTolerancceForRealLightRay(toleranceRealLightRay);
}

// factor start heigh inf
real RayAiming::getFactorStartHeight_inf()
{
	return mDefaultParaRayAiming.getFactorStartHeight_inf();
}
void RayAiming::setFactorStartHeight_inf(real factorStartHeight_inf)
{
	mDefaultParaRayAiming.setFactorStartHeight_inf(factorStartHeight_inf);
}
// factor start heigh obj
real RayAiming::getFactorStartHeight_obj()
{
	return mDefaultParaRayAiming.getFactorStartHeight_obj();
}
void RayAiming::setFactorStartHeight_obj(real factorStartHeight_obj)
{
	mDefaultParaRayAiming.setFactorStartHeight_obj(factorStartHeight_obj);
}

// max interation robust ray aiming
unsigned int RayAiming::getMaxIterationRobustRayAiming()
{
	return mDefaultParaRayAiming.getMaxInterationRayAiming();
}

void RayAiming::setMaxInterationRobustRayAiming(unsigned int maxInterationRRA)
{
	mDefaultParaRayAiming.setMaxInterationRobustRayAiming(maxInterationRRA);
}
// load all default parameters
void RayAiming::loadDefaultParameter()
{
	mDefaultParaRayAiming.loadDefaultParameter();
}

void RayAiming::turn_ON_GlobalStopIfToManyRaysAreNotAimed()
{
	mDefaultParaRayAiming.turn_ON_GlobalStopIfToManyRaysAreNotAimed();
}
void RayAiming::turn_OFF_GlobalStopIfToManyRaysAreNotAimed()
{
	mDefaultParaRayAiming.turn_OFF_GlobalStopIfToManyRaysAreNotAimed();
}
bool RayAiming::getGlobalStopIfToManyRaysAreNotAimed()
{
	return mDefaultParaRayAiming.getGlobalStopIfToManyRaysAreNotAimed();
}
// max rays that not be aimable
void RayAiming::setMaxRaysThatNotBeAimable(unsigned maxRayNotAimeable)
{
	mDefaultParaRayAiming.setMaxRaysThatNotBeAimable(maxRayNotAimeable);
}
unsigned int RayAiming::getMaxRayThatNotBeAimable()
{
	return mDefaultParaRayAiming.getMaxRayThatNotBeAimable();
}
// ** ** //


// robust ray aiming
lightRay_intP_dis_negPos_factor RayAiming::robustRayAiming_inf(lightRay_intP_dis_negPos_factor initialInfos)
{
	real disYtoTarget = initialInfos.getDistanceInterToTarget_Y();
	real disXtoTarget = initialInfos.getDistanceInterToTarget_X();
	unsigned int interation = 0;
	real maxInterationRobustRayAiming = mDefaultParaRayAiming.getMaxIterationRobustRayAiming();

	lightRay_intP_dis_negPos_factor interInfosRA_new = initialInfos;
	interInfosRA_new.setInterations(interation);

	real factorReduceX = initialInfos.getFactorX();
	real factorReduceY = initialInfos.getFactorY();

	real newFactorX = mDefaultParaRayAiming.getFactor_inf();
	real newFactorY = mDefaultParaRayAiming.getFactor_inf();

	interInfosRA_new.setFactorX(newFactorX);
	interInfosRA_new.setFactorY(newFactorY);


	while (((std::abs(disYtoTarget) > mDefaultParaRayAiming.getTolerance_XandY() || std::abs(disXtoTarget) > mDefaultParaRayAiming.getTolerance_XandY())) && (interation < maxInterationRobustRayAiming))
	{
		interInfosRA_new = calcNewBestInfos_inf(interInfosRA_new);
		interInfosRA_new.setFactorX(newFactorX);
		interInfosRA_new.setFactorY(newFactorY);
		interInfosRA_new.setInterations(0);
		interInfosRA_new = reduceDistancesIn_X_AND_Y_inf(interInfosRA_new);

		disYtoTarget = interInfosRA_new.getDistanceInterToTarget_Y();
		disXtoTarget = interInfosRA_new.getDistanceInterToTarget_X();
		++interation;
	}

	//LightRayStruct returnLightRay = interInfosRA_new.getLightRay();

	return interInfosRA_new;
}

lightRay_intP_dis_negPos_factor RayAiming::calcNewBestInfos_inf(lightRay_intP_dis_negPos_factor initialInfos)
{
	lightRay_intP_dis_negPos_factor returnInfos = initialInfos;
	real variancePercent = initialInfos.getVariangeInPercent();
	VectorStructR3 targetPoint = initialInfos.getTargetPoint();

	LightRayStruct initialLightRay = initialInfos.getLightRay();
	real initialDistance_X = initialInfos.getDistanceInterToTarget_X();
	real initialDistance_Y = initialInfos.getDistanceInterToTarget_Y();

	bool allInterPointsApertStop = true;
	std::vector<VectorStructR3> interPointsAS;
	std::vector<IntersectInformationStruct> interInfosAS_vec;
	std::vector<LightRayStruct> lightRay_vec;

	SequentialRayTracing seqTrace(mOpticalSystem_LLT);
	seqTrace.setTraceToSurface(mPosApertureStop);

	// light rays to trace
	std::vector<unsigned int> rayNumToTrace{ 0,1,2,3,4,5,6,7 };
	unsigned int sizeRayToTace = rayNumToTrace.size();
	lightRay_vec.resize(sizeRayToTace);
	unsigned int putLightAtPos = 0;

	while (allInterPointsApertStop)
	{
		VectorStructR3 rayDirectionUnit = initialLightRay.getRay_LLT().getDirectionRayUnit();
		real currentRefIndex = initialLightRay.getRay_LLT().getCurrentRefractiveIndex();
		Light_LLT mLight = initialLightRay.getLight_LLT();

		real X_origin = initialLightRay.getRay_LLT().getOriginRay().getX();
		real Y_origin = initialLightRay.getRay_LLT().getOriginRay().getY();
		real Z_origin = initialLightRay.getRay_LLT().getOriginRay().getZ();

		real X_Plus = Math::calcNewValueVariancePercent(X_origin, variancePercent);
		real X_Neg = Math::calcNewValueVariancePercent(X_origin, -variancePercent);
		real Y_Plus = Math::calcNewValueVariancePercent(Y_origin, variancePercent);
		real Y_Neg = Math::calcNewValueVariancePercent(Y_origin, -variancePercent);


		if (oftenUse::checkIfUnsIntIsInVector(0, rayNumToTrace))
		{
			// origin 0
			VectorStructR3 origin0(X_origin, Y_Plus, Z_origin);
			// ray0
			Ray_LLT ray0(origin0, rayDirectionUnit, currentRefIndex);
			//light ray 0
			LightRayStruct lightRay0(mLight, ray0, 1);
			lightRay_vec[putLightAtPos] = lightRay0;
			++putLightAtPos;
		}

		if (oftenUse::checkIfUnsIntIsInVector(1, rayNumToTrace))
		{
			// origin 1
			VectorStructR3 origin1(X_origin, Y_Neg, Z_origin);
			// ray1
			Ray_LLT ray1(origin1, rayDirectionUnit, currentRefIndex);
			//light ray 1
			LightRayStruct lightRay1(mLight, ray1, 1);
			lightRay_vec[putLightAtPos] = lightRay1;
			++putLightAtPos;
		}

		if (oftenUse::checkIfUnsIntIsInVector(2, rayNumToTrace))
		{
			// origin 2
			VectorStructR3 origin2(X_Neg, Y_origin, Z_origin);
			// ray2
			Ray_LLT ray2(origin2, rayDirectionUnit, currentRefIndex);
			//light ray 2
			LightRayStruct lightRay2(mLight, ray2, 1);
			lightRay_vec[putLightAtPos] = lightRay2;
			++putLightAtPos;
		}

		if (oftenUse::checkIfUnsIntIsInVector(3, rayNumToTrace))
		{

			// origin 3
			VectorStructR3 origin3(X_Plus, Y_origin, Z_origin);
			// ray3
			Ray_LLT ray3(origin3, rayDirectionUnit, currentRefIndex);
			//light ray 3
			LightRayStruct lightRay3(mLight, ray3, 1);
			lightRay_vec[putLightAtPos] = lightRay3;
			++putLightAtPos;
		}

		if (oftenUse::checkIfUnsIntIsInVector(4, rayNumToTrace))
		{
			// origin 4
			VectorStructR3 origin4(X_Neg, Y_Plus, Z_origin);
			// ray4
			Ray_LLT ray4(origin4, rayDirectionUnit, currentRefIndex);
			//light ray 4
			LightRayStruct lightRay4(mLight, ray4, 1);
			lightRay_vec[putLightAtPos] = lightRay4;
			++putLightAtPos;
		}

		if (oftenUse::checkIfUnsIntIsInVector(5, rayNumToTrace))
		{
			// origin 5
			VectorStructR3 origin5(X_Plus, Y_Plus, Z_origin);
			// ray5
			Ray_LLT ray5(origin5, rayDirectionUnit, currentRefIndex);
			//light ray 5
			LightRayStruct lightRay5(mLight, ray5, 1);
			lightRay_vec[putLightAtPos] = lightRay5;
			++putLightAtPos;

		}

		if (oftenUse::checkIfUnsIntIsInVector(6, rayNumToTrace))
		{
			// origin 6
			VectorStructR3 origin6(X_Plus, Y_Neg, Z_origin);
			// ray6
			Ray_LLT ray6(origin6, rayDirectionUnit, currentRefIndex);
			//light ray 6
			LightRayStruct lightRay6(mLight, ray6, 1);
			lightRay_vec[putLightAtPos] = lightRay6;
			++putLightAtPos;
		}

		if (oftenUse::checkIfUnsIntIsInVector(7, rayNumToTrace))
		{
			// origin 7
			VectorStructR3 origin7(X_Neg, Y_Neg, Z_origin);
			// ray7
			Ray_LLT ray7(origin7, rayDirectionUnit, currentRefIndex);
			//light ray 7
			LightRayStruct lightRay7(mLight, ray7, 1);
			lightRay_vec[putLightAtPos] = lightRay7;
			++putLightAtPos;
		}

		// trace the rays
		for (unsigned int i = 0; i < sizeRayToTace; ++i)
		{
			seqTrace.sequentialRayTracing(lightRay_vec[i]);
		}
		

		interInfosAS_vec = seqTrace.getAllInterInfosOfSurf_i_notFiltered(mPosApertureStop);
		interPointsAS = seqTrace.getAllInterPointsAtSurf_i_notFiltered(mPosApertureStop);

		if (interPointsAS.size() == 8)
		{
			allInterPointsApertStop = false;
		}

		else
		{
			variancePercent = variancePercent / 1.9;
			rayNumToTrace.clear();
			rayNumToTrace.resize(0);
			// check which ray we have to trace with less variance in percent
			for (unsigned int i = 0; i < sizeRayToTace; ++i)
			{
				if (interInfosAS_vec[i].getSurfaceSide() == N) // we have to trace that ray again
				{
					rayNumToTrace.push_back(i);
				}
			}

			sizeRayToTace = rayNumToTrace.size();
			//lightRay_vec.clear();
			//lightRay_vec.resize(sizeRayToTace);
			putLightAtPos = 0;
			//seqTrace.clearAllTracedRays();
		}
	}
	unsigned int posBestRay = getPosRayLowestDistance(interPointsAS, targetPoint);

	// new infos 
	LightRayStruct newBestRay = lightRay_vec[posBestRay];
	VectorStructR3 newInterPointAS = seqTrace.getAllInterPointsAtSurf_i_notFiltered(mPosApertureStop)[posBestRay];
	real distance_X = calcDistance_X(newInterPointAS, targetPoint);
	real distance_Y = calcDistance_Y(newInterPointAS, targetPoint);
	// ***

	if (distance_X > initialDistance_X || distance_Y > initialDistance_Y) // take the old ray
	{
		initialInfos.setVariangeInPercent(variancePercent / 1.9);
		return initialInfos;
	}

	returnInfos.setLightRay(newBestRay);
	returnInfos.setInterPoint(newInterPointAS);
	returnInfos.setDistanceInterToTarger_X(distance_X);
	returnInfos.setDistanceInterToTarger_Y(distance_Y);

	return returnInfos;
}

lightRay_intP_dis_negPos_factor RayAiming::reduceDistancesIn_X_AND_Y_inf(lightRay_intP_dis_negPos_factor initialInfos)
{

	real disYtoTarget = initialInfos.getDistanceInterToTarget_Y();
	real disXtoTarget = initialInfos.getDistanceInterToTarget_X();
	unsigned int interation = initialInfos.getInterations();
	real maxInteration = mDefaultParaRayAiming.getMaxInterationRayAiming();

	unsigned int stayCounter = 0;
	reduceWhat redWhat = reduceWhat::neutral;

	while (((std::abs(disYtoTarget) > mDefaultParaRayAiming.getTolerance_XandY() || std::abs(disXtoTarget) > mDefaultParaRayAiming.getTolerance_XandY())) && (interation < maxInteration) && mGlobalSTOP == false)
	{
		if ((disXtoTarget >= disYtoTarget && redWhat == reduceWhat::neutral) || redWhat == reduceWhat::reduce_X)
		{

			initialInfos = traceNegOrPosSide_andReduce_X_inf(initialInfos);
			disXtoTarget = initialInfos.getDistanceInterToTarget_X();
			disYtoTarget = initialInfos.getDistanceInterToTarget_Y();

			if (initialInfos.getNegOrPosSide() == betterSide::stay)
			{
				++stayCounter;
				if (stayCounter > mDefaultParaRayAiming.getMaxStayCounter())
				{
					redWhat = reduceWhat::reduce_Y;
					
					stayCounter = 0;
				}
			}
			else
			{
				stayCounter = 0;
				redWhat = reduceWhat::neutral;
			}

			++interation;
		}
		else
		{
			initialInfos = traceNegOrPosSide_andReduce_Y_inf(initialInfos);
			disXtoTarget = initialInfos.getDistanceInterToTarget_X();
			disYtoTarget = initialInfos.getDistanceInterToTarget_Y();

			if (initialInfos.getNegOrPosSide() == betterSide::stay)
			{
				++stayCounter;
				if (stayCounter > mDefaultParaRayAiming.getMaxStayCounter())
				{
					redWhat = reduceWhat::reduce_X;
					stayCounter = 0;
				}
			}
			else
			{
				stayCounter = 0;
				redWhat = reduceWhat::neutral;
			}

			++interation;
			
		}
	}

	initialInfos.setInterations(interation);

	return initialInfos;

}

// get positon ray with lowest distance
unsigned int RayAiming::getPosRayLowestDistance(std::vector<VectorStructR3> allInterPoints, VectorStructR3 targetPoint)
{
	unsigned int size = allInterPoints.size();
	real currenctDistance;
	unsigned int bestPos = 0;
	real bestDistance = Math::distanceTwoVectors(allInterPoints[0], targetPoint);

	for (unsigned int i = 1; i < size; ++i)
	{
		currenctDistance = Math::distanceTwoVectors(allInterPoints[i], targetPoint);

		if (currenctDistance < bestDistance)
		{
			bestDistance = currenctDistance;
			bestPos = i;
		}
	}

	return bestPos;
}


// print
void RayAiming::printInterP_Target_distance_X_Y(lightRay_intP_dis_negPos_factor infosToReduce)
{
	VectorStructR3 interPointTace = infosToReduce.getInterPoint();
	VectorStructR3 targetPoint = infosToReduce.getTargetPoint();
	real distanceX = infosToReduce.getDistanceInterToTarget_X();
	real distanceY = infosToReduce.getDistanceInterToTarget_Y();

	std::cout << "inter point: X: " << interPointTace.getX() << " Y: " << interPointTace.getY() << " Z: " << interPointTace.getZ() << std::endl;
	std::cout << "target point: X: " << targetPoint.getX() << " Y: " << targetPoint.getY() << " Z: " << targetPoint.getZ() << std::endl;
	std::cout << "distance X: " << distanceX << std::endl;
	std::cout << "distance Y: " << distanceY << std::endl;
}

LightRayStruct RayAiming::rayAiming_obj(VectorStructR3 rayOrigin, VectorStructR3 targetPoint, Light_LLT mLight, real curRefracIndex)
{
	LightRayStruct lightRayi;

	// aperture stop is first (0) surface
	if (mPosApertureStop == 0)
	{
		VectorStructR3 rayDirection = targetPoint - rayOrigin;
		Ray_LLT startRayObj(rayOrigin, rayDirection, curRefracIndex);

		lightRayi.setRay_LLT(startRayObj);
		lightRayi.setLight_LLT(mLight);

	}

	// aperture stop is NOT first surface
	else
	{
		//std::shared_ptr<SurfaceIntersectionRay_LLT> firstSurface_ptr = mOpticalSystem_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr();

		// build first ray for ray aiming
		VectorStructR3 baseVector1 = { 1.0,1.0,0.0 };
		VectorStructR3 baseVecotr2 = { 1.0,-1.0,0.0 };
		VectorStructR3 baseVector3 = { 1.0,0.0,0.0 };
		VectorStructR3 baseVector4 = { 0.0,1.0,0.0 };

		VectorStructR3 Vector1ToCalcDir = mDefaultParaRayAiming.getFactorStartHeight_obj() * mSemiHeightFirstSurface * Math::unitVector(Math::DoCrossProduct(baseVector1, mDirectionFirstSurface));
		VectorStructR3 Vector2ToCalcDir = mDefaultParaRayAiming.getFactorStartHeight_obj() * mSemiHeightFirstSurface * Math::unitVector(Math::DoCrossProduct(baseVecotr2, mDirectionFirstSurface));

		VectorStructR3 rayDirection0 = { mPositionFirstSurface - rayOrigin + Vector1ToCalcDir };
		VectorStructR3 rayDirection1 = { mPositionFirstSurface - rayOrigin - Vector1ToCalcDir };
		VectorStructR3 rayDirection2 = { mPositionFirstSurface - rayOrigin + Vector2ToCalcDir };
		VectorStructR3 rayDirection3 = { mPositionFirstSurface - rayOrigin - Vector2ToCalcDir };
		VectorStructR3 rayDirection4 = { mPositionFirstSurface - rayOrigin };
		VectorStructR3 rayDirection5 = { mPositionFirstSurface - rayOrigin + baseVector3 * mDefaultParaRayAiming.getFactorStartHeight_obj() * mSemiHeightFirstSurface };
		VectorStructR3 rayDirection6 = { mPositionFirstSurface - rayOrigin - baseVector3 * mDefaultParaRayAiming.getFactorStartHeight_obj() * mSemiHeightFirstSurface };
		VectorStructR3 rayDirection7 = { mPositionFirstSurface - rayOrigin + baseVector4 * mDefaultParaRayAiming.getFactorStartHeight_obj() * mSemiHeightFirstSurface };
		VectorStructR3 rayDirection8 = { mPositionFirstSurface - rayOrigin - baseVector4 * mDefaultParaRayAiming.getFactorStartHeight_obj() * mSemiHeightFirstSurface };


		Ray_LLT startRay0(rayOrigin, rayDirection0, curRefracIndex);
		Ray_LLT startRay1(rayOrigin, rayDirection1, curRefracIndex);
		Ray_LLT startRay2(rayOrigin, rayDirection2, curRefracIndex);
		Ray_LLT startRay3(rayOrigin, rayDirection3, curRefracIndex);
		Ray_LLT startRay4(rayOrigin, rayDirection4, curRefracIndex);
		Ray_LLT startRay5(rayOrigin, rayDirection5, curRefracIndex);
		Ray_LLT startRay6(rayOrigin, rayDirection6, curRefracIndex);
		Ray_LLT startRay7(rayOrigin, rayDirection7, curRefracIndex);
		Ray_LLT startRay8(rayOrigin, rayDirection8, curRefracIndex);

		LightRayStruct lightRayStart0(mLight, startRay0, 1.0);
		LightRayStruct lightRayStart1(mLight, startRay1, 1.0);
		LightRayStruct lightRayStart2(mLight, startRay2, 1.0);
		LightRayStruct lightRayStart3(mLight, startRay3, 1.0);
		LightRayStruct lightRayStart4(mLight, startRay4, 1.0);
		LightRayStruct lightRayStart5(mLight, startRay5, 1.0);
		LightRayStruct lightRayStart6(mLight, startRay6, 1.0);
		LightRayStruct lightRayStart7(mLight, startRay7, 1.0);
		LightRayStruct lightRayStart8(mLight, startRay8, 1.0);


		// trace all rays until all of them comes to the last surface
		lightRayAndInterPointAperStop bestLightRayAndInterPoint = getBestLightRayAndInterPoint_obj(lightRayStart0, lightRayStart1, lightRayStart2, lightRayStart3, lightRayStart4, lightRayStart5, lightRayStart6, lightRayStart7, lightRayStart8, targetPoint, Vector1ToCalcDir, Vector2ToCalcDir, baseVector3, baseVector4);

		LightRayStruct bestLightRay = bestLightRayAndInterPoint.getLightRay();
		VectorStructR3 interPointBestLightRay = bestLightRayAndInterPoint.getInterPointAperStop();

		real disXtoTarget = calcDistance_X(targetPoint, interPointBestLightRay);
		real disYtoTarget = calcDistance_Y(targetPoint, interPointBestLightRay);

		int maxInteration = mDefaultParaRayAiming.getMaxInterationRayAiming();

		unsigned int curInteration = 0;
		lightRay_intP_dis_negPos_factor infosToReduce(bestLightRay, interPointBestLightRay, disXtoTarget, disYtoTarget, betterSide::stay, mDefaultParaRayAiming.getFactor_obj(), mDefaultParaRayAiming.getFactor_obj(), targetPoint, curInteration, mDefaultParaRayAiming.getVariancePercentRRA());


		// reduce distance in X and Y
		infosToReduce = reduceDistancesIn_X_AND_Y_obj(infosToReduce);
			   
		curInteration = infosToReduce.getInterations();

		if (curInteration >= maxInteration && mGlobalSTOP == false)
		{

			// just for debugging
			// printInterP_Target_distance_X_Y(infosToReduce);

			// here we can start robust ray aiming!
			if (mDefaultParaRayAiming.getON_OFF_RobustRayAiming())
			{
				//just for debugging
				//std::cout << "start robust ray aiming" << std::endl;

				infosToReduce = robustRayAiming_obj(infosToReduce);

				//just for debugging
				//std::cout << "results from robust ray aiming" << std::endl;
				//just for debugging
				//printInterP_Target_distance_X_Y(infosToReduce);
			}

			else // no robust ray aiming
			{
				std::cout << "attention!!! ray aiming did not work perfectly!!!" << std::endl;
				std::cout << "maybe it would help to turn on robust ray aiming!!!" << std::endl;
				std::cout << "maybe the results are not correct!" << std::endl;
			}
		}

		// check the light ray
		lightRayi = checkLightRay(infosToReduce.getLightRay(), infosToReduce.getInterPoint(), infosToReduce.getTargetPoint());

		
	}


	return lightRayi;
}



// trace all rays until all of them comes to the last surface
lightRayAndInterPointAperStop RayAiming::getBestLightRayAndInterPoint_obj(LightRayStruct lightRay0, LightRayStruct lightRay1, LightRayStruct lightRay2, LightRayStruct lightRay3, LightRayStruct lightRay4, LightRayStruct lightRay5, LightRayStruct lightRay6, LightRayStruct lightRay7, LightRayStruct lightRay8, VectorStructR3 targetPoint, VectorStructR3 vectorToCalc1, VectorStructR3 vectorRoCalc2, VectorStructR3 vectorRoCalc3, VectorStructR3 vectorRoCalc4)
{
	lightRayAndInterPointAperStop bestLightRayAndInterPoint;

	std::vector<lightRayAndInterPointAperStop> lightRayAndInterPointAS;
	lightRayAndInterPointAS.resize(9);
	unsigned maxLoops = mDefaultParaRayAiming.getMaxLoopsTraceToLastSurface();


	lightRayAndInterPointAS.at(0) = traceOneRayUntilInApertureStop_obj(lightRay0, vectorToCalc1, maxLoops);
	lightRayAndInterPointAS.at(1) = traceOneRayUntilInApertureStop_obj(lightRay1, -1.0 * vectorToCalc1, maxLoops);
	lightRayAndInterPointAS.at(2) = traceOneRayUntilInApertureStop_obj(lightRay2, vectorRoCalc2,  maxLoops);
	lightRayAndInterPointAS.at(3) = traceOneRayUntilInApertureStop_obj(lightRay3, -1.0 * vectorRoCalc2, maxLoops);
	lightRayAndInterPointAS.at(4) = traceOneRayUntilInApertureStop_obj(lightRay4, vectorToCalc1, maxLoops);
	lightRayAndInterPointAS.at(5) = traceOneRayUntilInApertureStop_obj(lightRay5, vectorRoCalc3, maxLoops);
	lightRayAndInterPointAS.at(6) = traceOneRayUntilInApertureStop_obj(lightRay6, vectorRoCalc3, maxLoops);
	lightRayAndInterPointAS.at(7) = traceOneRayUntilInApertureStop_obj(lightRay7, vectorRoCalc4, maxLoops);
	lightRayAndInterPointAS.at(8) = traceOneRayUntilInApertureStop_obj(lightRay8, vectorRoCalc4, maxLoops);


	std::vector<real> dis = calcAllDistances(lightRayAndInterPointAS, targetPoint);

	// ValueInVectorNearZeroPosSide geändert.
	VectorElementAndPosition minDisAndPos = Math::ValueInVectorNearZeroPosSide(dis);

	unsigned int posBestInterPoint = minDisAndPos.getPosInVector();

	//// just for debugging
	//VectorStructR3 bestInterPoint = lightRayAndInterPointAS[posBestInterPoint].getInterPointAperStop();
	//std::cout << "best inter point: " << std::endl;
	//bestInterPoint.print();
	//std::cout << "target point: " << std::endl;
	//targetPoint.print();

	bestLightRayAndInterPoint.setLightRay(lightRayAndInterPointAS[posBestInterPoint].getLightRay());
	bestLightRayAndInterPoint.setInterPointAperStop(lightRayAndInterPointAS[posBestInterPoint].getInterPointAperStop());


	return bestLightRayAndInterPoint;

}

// trace one ray until it comes to the last surface;
lightRayAndInterPointAperStop RayAiming::traceOneRayUntilInApertureStop_obj(LightRayStruct lightRay, const VectorStructR3& vectorToCalcDir, unsigned int maxLoop)
{
	lightRayAndInterPointAperStop tempLightRayAndInterPointAS{};

	unsigned int loopCounter = 0;
	VectorStructR3 interpointApertureStop{};

	SequentialRayTracing seqTrace(mOpticalSystem_LLT);
	// trace ray only to aperture stop
	seqTrace.setTraceToSurface(mPosApertureStop);
	// trace the light ray
	seqTrace.sequentialRayTracing(lightRay);

	//VectorStructR3 originFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getPoint();

	real curRefIndex = lightRay.getRay_LLT().getCurrentRefractiveIndex();
	VectorStructR3 originRay = lightRay.getRay_LLT().getOriginRay();
	VectorStructR3 tempVecToCalcDir = vectorToCalcDir;
	VectorStructR3 newRayDirection;

	Ray_LLT newRay;

	//unsigned int posLastSurface = mOpticalSystem_LLT.getPosAndInteractingSurface().size() - 1;
	bool ray_NOT_AtLastSurface = true;
	// check if light ray comes to last surface
	while (ray_NOT_AtLastSurface)
	{
		surfaceSide surfSide = seqTrace.getAllInterInfosOfSurf_i_notFiltered(mPosApertureStop)[loopCounter].getSurfaceSide();

		if (N == surfSide) 
		{
			// build new ray to trace
			tempVecToCalcDir = tempVecToCalcDir * 0.5;
			newRayDirection = { mPositionFirstSurface + tempVecToCalcDir };

			newRay.setDirectionRayUnit(newRayDirection);
			newRay.setCurrentRefractiveIndex(curRefIndex);
			newRay.setOriginRay(originRay);

			lightRay.setRay_LLT(newRay);

			// trace new ray
			seqTrace.sequentialRayTracing(lightRay);
			
		}

		else if (A == surfSide || B == surfSide) // ray comes to the last surface
		{
			ray_NOT_AtLastSurface = false;
			tempLightRayAndInterPointAS.setInterPointAperStop(seqTrace.getAllInterPointsAtSurf_i_notFiltered(mPosApertureStop).back());
			tempLightRayAndInterPointAS.setLightRay(lightRay);
			tempLightRayAndInterPointAS.setIsValidInterPointInAS(true);

			return tempLightRayAndInterPointAS;
		}

		if (loopCounter > maxLoop)
		{
			//std::cout << "we could not trace the ray until the aperture stop. Maybe there is a mistake doing ray aiming" << std::endl;
			ray_NOT_AtLastSurface = false; // -> get out of the loop
			tempLightRayAndInterPointAS.setIsValidInterPointInAS(false);
		}

		++loopCounter;

	}



	return tempLightRayAndInterPointAS;
}

lightRay_intP_dis_negPos_factor RayAiming::traceNegOrPosSide_andReduce_X_obj(lightRay_intP_dis_negPos_factor& initialInfos)
{
	lightRay_intP_dis_negPos_factor returnLightRay_intP_dis_negPos_fac;
	returnLightRay_intP_dis_negPos_fac.setVariangeInPercent(initialInfos.getVariangeInPercent());
	real initialFactorY = initialInfos.getFactorY();
	VectorStructR3 targetPoint = initialInfos.getTargetPoint();
	unsigned int initialInterations = initialInfos.getInterations();

	returnLightRay_intP_dis_negPos_fac.setInterations(++initialInterations);
	returnLightRay_intP_dis_negPos_fac.setTargetPoint(targetPoint);

	//real semiHeightFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getSemiHeight();

	LightRayStruct initialLightRay = initialInfos.getLightRay();
	VectorStructR3 initialPointAS = initialInfos.getInterPoint();
	real initialDistanceX = initialInfos.getDistanceInterToTarget_X();
	betterSide initialNegPosStay = initialInfos.getNegOrPosSide();
	real initialFactorX = initialInfos.getFactorX();



	VectorStructR3 directionPos = initialLightRay.getRay_LLT().getDirectionRayUnit();
	VectorStructR3 directionNeg = initialLightRay.getRay_LLT().getDirectionRayUnit();

	LightRayStruct lightRayToTracePos = initialLightRay;
	LightRayStruct lightRayToTraceNeg = initialLightRay;

	real initialDirection_X = directionPos.getX();
	real directionPlus_X = initialDirection_X + mSemiHeightFirstSurface * initialFactorX;
	real directionMinus_X = initialDirection_X - mSemiHeightFirstSurface * initialFactorX;
	directionPos.setX(directionPlus_X);
	directionNeg.setX(directionMinus_X);



	Ray_LLT rayPos = lightRayToTracePos.getRay_LLT();
	rayPos.setDirectionRayUnit(directionPos);
	lightRayToTracePos.setRay_LLT(rayPos);

	Ray_LLT rayNeg = lightRayToTraceNeg.getRay_LLT();
	rayNeg.setDirectionRayUnit(directionNeg);
	lightRayToTraceNeg.setRay_LLT(rayNeg);

	// pos trace
	SequentialRayTracing tracePLus(mOpticalSystem_LLT);
	tracePLus.setTraceToSurface(mPosApertureStop);
	tracePLus.sequentialRayTracing(lightRayToTracePos);

	// neg trace
	SequentialRayTracing traceNeg(mOpticalSystem_LLT);
	traceNeg.setTraceToSurface(mPosApertureStop);
	traceNeg.sequentialRayTracing(lightRayToTraceNeg);

	IntersectInformationStruct interPointAS_pos = tracePLus.getAllInterInfosOfSurf_i_notFiltered(mPosApertureStop)[0];
	IntersectInformationStruct interPointAS_neg = traceNeg.getAllInterInfosOfSurf_i_notFiltered(mPosApertureStop)[0];

	// pos trace
	real disPosTrace_X = calcDistance_X(interPointAS_pos.getIntersectionPoint(), targetPoint);
	real disPosTrace_Y = calcDistance_Y(interPointAS_pos.getIntersectionPoint(), targetPoint);

	// neg trace
	real disNegTrace_X = calcDistance_X(interPointAS_neg.getIntersectionPoint(), targetPoint);
	real disNegTrace_Y = calcDistance_Y(interPointAS_neg.getIntersectionPoint(), targetPoint);

	if (disPosTrace_X <= disNegTrace_X && interPointAS_pos.getSurfaceSide() != N)
	{
		if (disPosTrace_X <= initialDistanceX)
		{
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_Y(disPosTrace_Y);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY);

			returnLightRay_intP_dis_negPos_fac.setLightRay(lightRayToTracePos);
			returnLightRay_intP_dis_negPos_fac.setInterPoint(interPointAS_pos.getIntersectionPoint());
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_X(disPosTrace_X);
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(betterSide::posSide);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.9);

		}
		else if (initialDistanceX <= disPosTrace_X)
		{
			returnLightRay_intP_dis_negPos_fac = initialInfos;
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(betterSide::stay);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.9);
		}



	}

	else if (disNegTrace_X < disPosTrace_X && interPointAS_neg.getSurfaceSide() != N)
	{

		if (disNegTrace_X < initialDistanceX)
		{
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_Y(disNegTrace_Y);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY);

			returnLightRay_intP_dis_negPos_fac.setLightRay(lightRayToTraceNeg);
			returnLightRay_intP_dis_negPos_fac.setInterPoint(interPointAS_neg.getIntersectionPoint());
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_X(disNegTrace_X);
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(betterSide::negSide);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.9);

		}
		else if (initialDistanceX < disNegTrace_X)
		{
			returnLightRay_intP_dis_negPos_fac = initialInfos;
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(betterSide::stay);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.9);
		}

	}

	else // there is no intersection point with the aperture stop
	{
		returnLightRay_intP_dis_negPos_fac = initialInfos;
		returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(betterSide::stay);
		returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.5);
	}


	return returnLightRay_intP_dis_negPos_fac;
}

lightRay_intP_dis_negPos_factor RayAiming::traceNegOrPosSide_andReduce_Y_obj(lightRay_intP_dis_negPos_factor& initialInfos)
{
	lightRay_intP_dis_negPos_factor returnLightRay_intP_dis_negPos_fac;
	returnLightRay_intP_dis_negPos_fac.setVariangeInPercent(initialInfos.getVariangeInPercent());
	real initalFactorX = initialInfos.getFactorX();
	//real semiHeightFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getSemiHeight();
	VectorStructR3 targetPoint = initialInfos.getTargetPoint();

	unsigned int initialInterations = initialInfos.getInterations();
	returnLightRay_intP_dis_negPos_fac.setInterations(++initialInterations);
	returnLightRay_intP_dis_negPos_fac.setTargetPoint(targetPoint);

	LightRayStruct initialLightRay = initialInfos.getLightRay();
	VectorStructR3 initialPointAS = initialInfos.getInterPoint();
	real initialDistanceY = initialInfos.getDistanceInterToTarget_Y();
	betterSide initialNegPosStay = initialInfos.getNegOrPosSide();
	real initialFactorY = initialInfos.getFactorY();



	VectorStructR3 directionPlus = initialLightRay.getRay_LLT().getDirectionRayUnit();
	VectorStructR3 directionNeg = initialLightRay.getRay_LLT().getDirectionRayUnit();

	LightRayStruct lightRayToTracePos = initialLightRay;
	LightRayStruct lightRayToTraceNeg = initialLightRay;


	real initialDirection_Y = directionPlus.getY();
	real directionPlus_Y = initialDirection_Y + mSemiHeightFirstSurface * initialFactorY;
	real directionMinus_Y = initialDirection_Y - mSemiHeightFirstSurface * initialFactorY;
	directionPlus.setY(directionPlus_Y);
	//just for debugging
	//std::cout << "reduce Y pos direction Y: " << directionPlus.getY() << std::endl;
	directionNeg.setY(directionMinus_Y);
	//just for debugging
	//std::cout << "reduce Y neg direction Y: " << directionNeg.getY() << std::endl;

	Ray_LLT rayPos = lightRayToTracePos.getRay_LLT();
	rayPos.setDirectionRayUnit(directionPlus);
	lightRayToTracePos.setRay_LLT(rayPos);

	Ray_LLT rayNeg = lightRayToTraceNeg.getRay_LLT();
	rayNeg.setDirectionRayUnit(directionNeg);
	lightRayToTraceNeg.setRay_LLT(rayNeg);

	// pos trace
	SequentialRayTracing tracePLus(mOpticalSystem_LLT);
	tracePLus.sequentialRayTracing(lightRayToTracePos);

	// neg trace
	SequentialRayTracing traceNeg(mOpticalSystem_LLT);
	traceNeg.sequentialRayTracing(lightRayToTraceNeg);

	IntersectInformationStruct interPointAS_pos = tracePLus.getAllInterInfosOfSurf_i_notFiltered(mPosApertureStop)[0];
	IntersectInformationStruct interPointAS_neg = traceNeg.getAllInterInfosOfSurf_i_notFiltered(mPosApertureStop)[0];

	//disPosTrace_Y = Math::distanceTwoVectors(interPointAS_pos, targetPoint);

	real disPosTrace_Y = calcDistance_Y(interPointAS_pos.getIntersectionPoint(), targetPoint);
	real disPosTrace_X = calcDistance_X(interPointAS_pos.getIntersectionPoint(), targetPoint);
	//just for debugging
	//std::cout << "reduce Y direction - distance: " << disPosTrace_Y << std::endl;
	real disNegTrace_Y = calcDistance_Y(interPointAS_neg.getIntersectionPoint(), targetPoint);
	real disNegTrace_X = calcDistance_X(interPointAS_neg.getIntersectionPoint(), targetPoint);
	//just for debugging
	//std::cout << "reduce Y direction - distance: " << disNegTrace_Y << std::endl;


	if (disPosTrace_Y <= disNegTrace_Y && interPointAS_pos.getSurfaceSide() != N)
	{
		if (disPosTrace_Y <= initialDistanceY)
		{
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_X(disPosTrace_X);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initalFactorX);

			returnLightRay_intP_dis_negPos_fac.setLightRay(lightRayToTracePos);
			returnLightRay_intP_dis_negPos_fac.setInterPoint(interPointAS_pos.getIntersectionPoint());
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_Y(disPosTrace_Y);
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(betterSide::posSide);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.9);

		}
		else if (initialDistanceY <= disPosTrace_Y)
		{
			returnLightRay_intP_dis_negPos_fac = initialInfos;
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(betterSide::stay);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.9);
		}



	}

	else if (disNegTrace_Y < disPosTrace_Y && interPointAS_neg.getSurfaceSide() != N)
	{

		if (disNegTrace_Y < initialDistanceY)
		{
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_X(disNegTrace_X);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initalFactorX);

			returnLightRay_intP_dis_negPos_fac.setLightRay(lightRayToTraceNeg);
			returnLightRay_intP_dis_negPos_fac.setInterPoint(interPointAS_neg.getIntersectionPoint());
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_Y(disNegTrace_Y);
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(betterSide::negSide);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.9);

		}
		else if (initialDistanceY < disNegTrace_Y)
		{
			returnLightRay_intP_dis_negPos_fac = initialInfos;
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(betterSide::stay);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.9);
		}

	}

	else // there is no intersection point with the aperture stop
	{
		returnLightRay_intP_dis_negPos_fac = initialInfos;
		returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(betterSide::stay);
		returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.5);
	}



	return returnLightRay_intP_dis_negPos_fac;
}


lightRay_intP_dis_negPos_factor RayAiming::reduceDistancesIn_X_AND_Y_obj(lightRay_intP_dis_negPos_factor& initialInfos)
{
	real disYtoTarget = initialInfos.getDistanceInterToTarget_Y();
	real disXtoTarget = initialInfos.getDistanceInterToTarget_X();
	unsigned int interation = initialInfos.getInterations();
	real maxInteration = mDefaultParaRayAiming.getMaxInterationRayAiming();

	unsigned int stayCounter = 0;
	reduceWhat redWhat = reduceWhat::neutral;

	while (((std::abs(disYtoTarget) > mDefaultParaRayAiming.getTolerance_XandY() || std::abs(disXtoTarget) > mDefaultParaRayAiming.getTolerance_XandY())) && (interation < maxInteration)&& mGlobalSTOP == false)
	{
		if ((disXtoTarget >= disYtoTarget && redWhat == reduceWhat::neutral) || redWhat == reduceWhat::reduce_X)
		{

			initialInfos = traceNegOrPosSide_andReduce_X_obj(initialInfos);
			

			disXtoTarget = initialInfos.getDistanceInterToTarget_X();
			disYtoTarget = initialInfos.getDistanceInterToTarget_Y();

			//just for debugging
			//std::cout << "reduce X" << std::endl;
			//std::cout << "dis X" << disXtoTarget << std::endl;
			//std::cout << "dis Y" << disYtoTarget << std::endl;


			if (initialInfos.getNegOrPosSide() == betterSide::stay)
			{
				++stayCounter;
				if (stayCounter > mDefaultParaRayAiming.getMaxStayCounter())
				{
					redWhat = reduceWhat::reduce_Y;
					stayCounter = 0;
				}
			}
			else
			{
				stayCounter = 0;
				redWhat = reduceWhat::neutral;
			}

			++interation;
		}
		else
		{
			initialInfos = traceNegOrPosSide_andReduce_Y_obj(initialInfos);
			disXtoTarget = initialInfos.getDistanceInterToTarget_X();
			disYtoTarget = initialInfos.getDistanceInterToTarget_Y();

			//just for debugging
			//std::cout << "reduce Y" << std::endl;
			//std::cout << "dis X" << disXtoTarget << std::endl;
			//std::cout << "dis Y" << disYtoTarget << std::endl;

			if (initialInfos.getNegOrPosSide() == betterSide::stay)
			{
				++stayCounter;
				if (stayCounter > mDefaultParaRayAiming.getMaxStayCounter())
				{
					redWhat = reduceWhat::reduce_X;
					stayCounter = 0;
				}
			}
			else
			{
				stayCounter = 0;
				redWhat = reduceWhat::neutral;
			}

			++interation;
			
		}
	}

	initialInfos.setInterations(interation);

	return initialInfos;


}

// robust ray aiming
lightRay_intP_dis_negPos_factor RayAiming::robustRayAiming_obj(lightRay_intP_dis_negPos_factor& initialInfos)
{
	real disYtoTarget = initialInfos.getDistanceInterToTarget_Y();
	real disXtoTarget = initialInfos.getDistanceInterToTarget_X();
	unsigned int interation = 0;
	real maxInterationRobustRayAiming = mDefaultParaRayAiming.getMaxIterationRobustRayAiming();

	lightRay_intP_dis_negPos_factor interInfosRA_new = initialInfos;
	interInfosRA_new.setInterations(interation);

	real factorReduceX = initialInfos.getFactorX();
	real factorReduceY = initialInfos.getFactorY();

	real newFactorX = mDefaultParaRayAiming.getFactor_obj();
	real newFactorY = mDefaultParaRayAiming.getFactor_obj();


	while (((std::abs(disYtoTarget) > mDefaultParaRayAiming.getTolerance_XandY() || std::abs(disXtoTarget) > mDefaultParaRayAiming.getTolerance_XandY())) && (interation < maxInterationRobustRayAiming))
	{
		interInfosRA_new = calcNewBestInfos_obj(interInfosRA_new);
		interInfosRA_new.setFactorX(newFactorX);
		interInfosRA_new.setFactorY(newFactorY);
		interInfosRA_new.setInterations(0.0);
		interInfosRA_new = reduceDistancesIn_X_AND_Y_obj(interInfosRA_new);

		disYtoTarget = interInfosRA_new.getDistanceInterToTarget_Y();
		disXtoTarget = interInfosRA_new.getDistanceInterToTarget_X();
		++interation;
	}

	

	return interInfosRA_new;
}

// calculate new origin variance in percent
lightRay_intP_dis_negPos_factor RayAiming::calcNewBestInfos_obj(lightRay_intP_dis_negPos_factor& initialInfos)
{
	lightRay_intP_dis_negPos_factor returnInfos = initialInfos;
	returnInfos.setInterations(0);
	real variancePercent = initialInfos.getVariangeInPercent();
	VectorStructR3 initialTargetPoint = initialInfos.getTargetPoint();
	real initialDistance_X = initialInfos.getDistanceInterToTarget_X();
	real initialDistance_Y = initialInfos.getDistanceInterToTarget_Y();

	LightRayStruct initialLightRay = initialInfos.getLightRay();
	bool allInterPointsApertStop = true;
	std::vector<VectorStructR3> interPointsAS;
	std::vector<IntersectInformationStruct> interInfosAS_vec;
	std::vector<LightRayStruct> lightRay_vec;

	SequentialRayTracing seqTrace(mOpticalSystem_LLT);
	seqTrace.setTraceToSurface(mPosApertureStop);

	// light rays to trace
	std::vector<unsigned int> rayNumToTrace{ 0,1,2,3,4,5,6,7 };
	unsigned int sizeRayToTace = rayNumToTrace.size();
	lightRay_vec.resize(sizeRayToTace);
	unsigned int putLightAtPos = 0;

	while (allInterPointsApertStop)
	{
		VectorStructR3 rayOrigin = initialLightRay.getRay_LLT().getOriginRay();
		
		real currentRefIndex = initialLightRay.getRay_LLT().getCurrentRefractiveIndex();
		Light_LLT mLight = initialLightRay.getLight_LLT();

		real direction_X = initialLightRay.getRay_LLT().getDirectionRayUnit().getX();
		real direction_Y = initialLightRay.getRay_LLT().getDirectionRayUnit().getY();
		real direction_Z = initialLightRay.getRay_LLT().getDirectionRayUnit().getZ();
		//
		//if (std::abs(direction_X) < 0.0001)
		//{
		//	direction_X = 0.01;
		//}
		//
		//if (std::abs(direction_Y) < 0.0001)
		//{
		//	direction_Y = 0.01;
		//}

		real X_Plus = Math::calcNewValueVariancePercent(direction_X, variancePercent);
		real X_Neg = Math::calcNewValueVariancePercent(direction_X, -variancePercent);
		real Y_Plus = Math::calcNewValueVariancePercent(direction_Y, variancePercent);
		real Y_Neg = Math::calcNewValueVariancePercent(direction_Y, -variancePercent);


		if (oftenUse::checkIfUnsIntIsInVector(0, rayNumToTrace))
		{
			// direction 0
			VectorStructR3 direction0(direction_X, Y_Plus, direction_Z);
			// ray0
			Ray_LLT ray0(rayOrigin, direction0, currentRefIndex);
			//light ray 0
			LightRayStruct lightRay0(mLight, ray0, 1);
			lightRay_vec[putLightAtPos] = lightRay0;
			++putLightAtPos;
		}

		if (oftenUse::checkIfUnsIntIsInVector(1, rayNumToTrace))
		{
			// origin 1
			VectorStructR3 direction1(direction_X, Y_Neg, direction_Z);
			// ray1
			Ray_LLT ray1(rayOrigin, direction1, currentRefIndex);
			//light ray 1
			LightRayStruct lightRay1(mLight, ray1, 1);
			lightRay_vec[putLightAtPos] = lightRay1;
			++putLightAtPos;
		}

		if (oftenUse::checkIfUnsIntIsInVector(2, rayNumToTrace))
		{
			// origin 2
			VectorStructR3 direction2(X_Neg, direction_Y, direction_Z);
			// ray2
			Ray_LLT ray2(rayOrigin, direction2, currentRefIndex);
			//light ray 2
			LightRayStruct lightRay2(mLight, ray2, 1);
			lightRay_vec[putLightAtPos] = lightRay2;
			++putLightAtPos;
		}

		if (oftenUse::checkIfUnsIntIsInVector(3, rayNumToTrace))
		{

			// origin 3
			VectorStructR3 direction3(X_Plus, direction_Y, direction_Z);
			// ray3
			Ray_LLT ray3(rayOrigin, direction3, currentRefIndex);
			//light ray 3
			LightRayStruct lightRay3(mLight, ray3, 1);
			lightRay_vec[putLightAtPos] = lightRay3;
			++putLightAtPos;
		}

		if (oftenUse::checkIfUnsIntIsInVector(4, rayNumToTrace))
		{
			// origin 4
			VectorStructR3 direction4(X_Neg, Y_Plus, direction_Z);
			// ray4
			Ray_LLT ray4(rayOrigin, direction4, currentRefIndex);
			//light ray 4
			LightRayStruct lightRay4(mLight, ray4, 1);
			lightRay_vec[putLightAtPos] = lightRay4;
			++putLightAtPos;
		}

		if (oftenUse::checkIfUnsIntIsInVector(5, rayNumToTrace))
		{
			// origin 5
			VectorStructR3 direction5(X_Plus, Y_Plus, direction_Z);
			// ray5
			Ray_LLT ray5(rayOrigin, direction5, currentRefIndex);
			//light ray 5
			LightRayStruct lightRay5(mLight, ray5, 1);
			lightRay_vec[putLightAtPos] = lightRay5;
			++putLightAtPos;

		}

		if (oftenUse::checkIfUnsIntIsInVector(6, rayNumToTrace))
		{
			// origin 6
			VectorStructR3 direction6(X_Plus, Y_Neg, direction_Z);
			// ray6
			Ray_LLT ray6(rayOrigin, direction6, currentRefIndex);
			//light ray 6
			LightRayStruct lightRay6(mLight, ray6, 1);
			lightRay_vec[putLightAtPos] = lightRay6;
			++putLightAtPos;
		}

		if (oftenUse::checkIfUnsIntIsInVector(7, rayNumToTrace))
		{
			// origin 7
			VectorStructR3 direction7(X_Neg, Y_Neg, direction_Z);
			// ray7
			Ray_LLT ray7(rayOrigin, direction7, currentRefIndex);
			//light ray 7
			LightRayStruct lightRay7(mLight, ray7, 1);
			lightRay_vec[putLightAtPos] = lightRay7;
			++putLightAtPos;
		}

		// trace the rays
		for (unsigned int i = 0; i < sizeRayToTace; ++i)
		{
			seqTrace.sequentialRayTracing(lightRay_vec[i]);
		}


		interInfosAS_vec = seqTrace.getAllInterInfosOfSurf_i_notFiltered(mPosApertureStop);
		interPointsAS = seqTrace.getAllInterPointsAtSurf_i_notFiltered(mPosApertureStop);

		if (interPointsAS.size() == 8)
		{
			allInterPointsApertStop = false;
		}

		else
		{
			variancePercent = variancePercent / 1.9;
			rayNumToTrace.clear();
			rayNumToTrace.resize(0);
			// check which ray we have to trace with less variance in percent
			for (unsigned int i = 0; i < sizeRayToTace; ++i)
			{
				if (interInfosAS_vec[i].getSurfaceSide() == N) // we have to trace that ray again
				{
					rayNumToTrace.push_back(i);
				}
			}

			sizeRayToTace = rayNumToTrace.size();
			//lightRay_vec.clear();
			//lightRay_vec.resize(sizeRayToTace);
			putLightAtPos = 0;
			//seqTrace.clearAllTracedRays();
		}
	}
	unsigned int posBestRay = getPosRayLowestDistance(interPointsAS, initialTargetPoint);

	// new infos 
	LightRayStruct newBestRay = lightRay_vec[posBestRay];
	VectorStructR3 newInterPointAS = seqTrace.getAllInterPointsAtSurf_i_notFiltered(mPosApertureStop)[posBestRay];
	real distance_X = calcDistance_X(newInterPointAS, initialTargetPoint);
	real distance_Y = calcDistance_Y(newInterPointAS, initialTargetPoint);
	// ***

	if (distance_X > initialDistance_X || distance_Y > initialDistance_Y) // take the old ray
	{
		returnInfos.setVariangeInPercent(variancePercent / 1.9);

		return returnInfos;
	}

	returnInfos.setLightRay(newBestRay);
	returnInfos.setInterPoint(newInterPointAS);
	returnInfos.setDistanceInterToTarger_X(distance_X);
	returnInfos.setDistanceInterToTarger_Y(distance_Y);

	return returnInfos;
}

// shift start point ray from infinity
VectorStructR3 RayAiming::shiftFirstSurface(real radius, real semiHeight, VectorStructR3 apexOfSphere)
{
	double val = radius - std::sqrt(std::pow(radius, 2) - std::pow(semiHeight, 2));
	VectorStructR3 returnApex = { apexOfSphere.getX(), apexOfSphere.getY(), apexOfSphere.getZ() - val /*to stop errors acording to rounding mistakes*/ - mDefaultParaRayAiming.getStartPointFactor() };
	return returnApex;
}

// ray aiming many obj
std::vector<LightRayStruct> RayAiming::rayAimingMany_obj(const std::vector<VectorStructR3>& pointsInAS, const VectorStructR3& startPointRay, const Light_LLT& mLight, real curRefracIndex)
{
	std::vector<LightRayStruct> returnLightRay_vec;
	unsigned int numRay = pointsInAS.size();
	returnLightRay_vec.resize(numRay);

	LightRayStruct aimedTempLightRay;
	VectorStructR3 tempTargetPoint; 
	
	for (unsigned int i = 0; i < numRay; ++i)
	{
		tempTargetPoint = pointsInAS[i];
		aimedTempLightRay = rayAiming_obj(startPointRay, tempTargetPoint, mLight, curRefracIndex);

		// only save valid light rays
		if (aimedTempLightRay.getIsAlive() == true)
		{
			returnLightRay_vec[i] = aimedTempLightRay;
		}
		if (mGlobalSTOP)
		{
			i = numRay + 1;
		}
	

	}
	mCounter_RaysThatNotBeAimed = 0;
	return returnLightRay_vec;
}

std::vector<LightRayStruct> RayAiming::rayAimingMany_obj_complete(const OpticalSystem_LLT& optSys_LLT, const std::vector<VectorStructR3>& pointsInAS, const VectorStructR3 startPointRay, Light_LLT mLight, real curRefracIndex)
{
	mOpticalSystem_LLT = optSys_LLT;
	loadImportantInfosForRayAiming();
	return rayAimingMany_obj(pointsInAS, startPointRay, mLight, curRefracIndex);
}

std::vector<LightRayStruct> RayAiming::rayAimingMany_inf(const std::vector<VectorStructR3>& pointsInAS, real angleX, real angleY, const Light_LLT& mLight, real curRefracIndex)
{
	std::vector<LightRayStruct> returnLightRay_vec;
	unsigned int numRay = pointsInAS.size();
	returnLightRay_vec.resize(numRay);

	LightRayStruct aimedTempLightRay;
	VectorStructR3 tempTargetPoint;

	VectorStructR3 directionRay = Math::convertAngleInDirection(angleX, angleY);

	for (unsigned int i = 0; i < numRay; ++i)
	{
		tempTargetPoint = pointsInAS[i];
		aimedTempLightRay = rayAiming_inf(directionRay, tempTargetPoint, mLight, curRefracIndex);

		// only save valid light rays
		if (aimedTempLightRay.getIsAlive() == true)
		{
			returnLightRay_vec[i] = aimedTempLightRay;
		}

		if (mGlobalSTOP)
		{
			i = numRay + 1;
		}

	}

	return returnLightRay_vec;
}
std::vector<LightRayStruct> RayAiming::rayAimingMany_inf_complete(const OpticalSystem_LLT& optSys_LLT, const std::vector<VectorStructR3>& pointsInAS, real angleX, real angleY, const Light_LLT& mLight, real curRefracIndex)
{
	mOpticalSystem_LLT = optSys_LLT;
	loadImportantInfosForRayAiming();
	return rayAimingMany_inf(pointsInAS, angleX, angleY, mLight, curRefracIndex);
}

// check the light ray
LightRayStruct RayAiming::checkLightRay(const LightRayStruct& lightRayToCheck, const VectorStructR3& intersecPoint, const VectorStructR3& targetPoint)
{
	real toleranceInXAndY = mDefaultParaRayAiming.getToleranceForRealLightRay();
	bool  checkDisX = std::abs(intersecPoint.getX() - targetPoint.getX()) < toleranceInXAndY;
	bool  checkDisY = std::abs(intersecPoint.getY() - targetPoint.getY()) < toleranceInXAndY;
	bool  checkDisZ = std::abs(intersecPoint.getZ() - targetPoint.getZ()) < toleranceInXAndY;
	
	////just for debugging
	//std::cout << "check distance X: " << std::abs( intersecPoint.getX() - targetPoint.getX()) << std::endl;
	//std::cout << "check distance Y: " << std::abs( intersecPoint.getY() - targetPoint.getY()) << std::endl;
	//std::cout << "check distance Z: " << std::abs( intersecPoint.getZ() - targetPoint.getZ()) << std::endl;

	int i = 0;
	if (checkDisX && checkDisY && checkDisZ)
	{
		return lightRayToCheck;
	}
	
	else
	{


		LightRayStruct notValidLightRay = lightRayToCheck;
		notValidLightRay.setLightRayAbsorb();

		if (mDefaultParaRayAiming.getGlobalStopIfToManyRaysAreNotAimed())
		{
			++mCounter_RaysThatNotBeAimed;
			if (mCounter_RaysThatNotBeAimed > mDefaultParaRayAiming.getMaxRayThatNotBeAimable())
			{
				// just for debugging
				std::cout << i << std::endl;
				i = 5;
				mGlobalSTOP = true;
			}

			
		}

		return notValidLightRay;
	}

}
// global stop
bool RayAiming::getGlobalStop()
{
	return mGlobalSTOP;
}
void RayAiming::setGlobalStop(bool globalStop)
{
	mGlobalSTOP = globalStop;
}