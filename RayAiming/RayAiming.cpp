#include "RayAiming.h"
#include <iostream>
#include <cmath>
#include <typeinfo>   // operator typeid
#include "..\LowLevelTracing\Math_LLT.h"
#include "..\SequentialRayTracing\SequentialRayTracer.h"
#include <iomanip> 
#include "..\oftenUseNamespace\oftenUseNamespace.h"

lightRay_intP_dis_negPos_factor::lightRay_intP_dis_negPos_factor() {};
lightRay_intP_dis_negPos_factor::~lightRay_intP_dis_negPos_factor() {};

lightRay_intP_dis_negPos_factor::lightRay_intP_dis_negPos_factor(LightRayStruct lightRay, VectorStructR3 interPoint, real distanceX, real distanceY, betterSide negOrPos, real factorX, real factorY, VectorStructR3 targerPoint, real interations) :
	mLightRay(lightRay),
	mInterPointAS(interPoint),
	mDistance_X(distanceX),
	mDistance_Y(distanceY),
	mNegPosStay(negOrPos),
	mFactorX(factorX),
	mFactorY(factorY),
	mTargetPoint(targerPoint),
	mInterations(interations)
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

// tolerance
real defaultRayAimingStruct::getTolerance_XandY()
{
	return mTolerance_XandY;
}
void defaultRayAimingStruct::setTolerance_XandY(real& tolerance)
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
void defaultRayAimingStruct::setMaxIterattionsRayAiming(unsigned int maxInterationsRayAiming)
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
bool defaultRayAimingStruct::getRobustRayAiming()
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
void defaultRayAimingStruct::setMayStayCounter(unsigned int maxStayCounter)
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

void defaultRayAimingStruct::loadDefaultParameter()
{
	mTolerance_XandY = 0.0001;
	mStartPointFactor = 1.0;
	mMaxLoopsTraceToLastSurface = 5;
	mMaxInterationsRayAiming = 50;
	mFactor_inf = 0.9;
	mFactor_obj = 0.1;
	turn_On_RobustRayAiming();
	mVariancePercentRobustRA = 5.0;
	mMaxStayCounter = 2;
	mIncreaserFactorTimes = 10.0;
}



RayAiming::RayAiming(OpticalSystem_LLT opticalSystem) :
	mOpticalSystem_LLT(opticalSystem)
{
	loadImportantInfosForRayAiming();
	mDefaultParaRayAiming.loadDefaultParameter();
	
};

// load important infomation for ray aiming
void RayAiming::loadImportantInfosForRayAiming()
{
	mSemiHeightFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface().at(0).getSurfaceInterRay_ptr()->getSemiHeight();
	mRadiusFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface().at(0).getSurfaceInterRay_ptr()->getRadius();
	mPositionFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface().at(0).getSurfaceInterRay_ptr()->getPoint();
	mDirectionFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface().at(0).getSurfaceInterRay_ptr()->getDirection();
	mPosApertureStop = mOpticalSystem_LLT.getPosApertureStop();
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
		char surfSide = seqTrace.getAllInterInfosOfSurf_i_notFiltered(mPosApertureStop)[loopCounter].getSurfaceSide();

		if ('N' == surfSide)
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

		else if ('A' == surfSide || 'B' == surfSide) // ray comes to the last surface
		{
			ray_NOT_AtLastSurface = false;
			tempLightRayAndInterPointAS.setInterPointAperStop(seqTrace.getAllInterPointsAtSurf_i(mPosApertureStop).back());
			tempLightRayAndInterPointAS.setLightRay(lightRay);

			return tempLightRayAndInterPointAS;
		}

		else if (loopCounter > maxLoop)
		{
			std::cout << "we could not trace the ray until the aperture stop. Maybe there is a mistake doing ray aiming" << std::endl;
			ray_NOT_AtLastSurface = false; // -> get out of the loop
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
	std::cout << "best inter point: " << std::endl;
	bestInterPoint.print();
	std::cout << "target point: " << std::endl;
	targetPoint.print();

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
				std::cout << "there is maybe a mistake in the position of the apertrure stop\n";
			}

		}
	}


	// check if there is no or more than one aperture stop -> this would be a mistake in an optical system
	if (checkNumerOfApertureStops != 1)
	{
		positionAperture = -1;
		std::cout << "there is no or more than one aperture stop in your optical system!\n";
	}

	return positionAperture;
}



//_______________________________________________
//_______________________________________________

// Ray Aiming for a ray starting at infinity
LightRayStruct RayAiming::rayAiming_inf(VectorStructR3 rayDirection, VectorStructR3 targetPoint, Light_LLT light, real curRefracIndex)
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
		lightRayi.setLight_LLT(light);
		lightRayi.setIsAlive(1);


	}
	else
	{
		std::shared_ptr<SurfaceIntersectionRay_LLT> firstSurface_ptr = mOpticalSystem_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr();

		VectorStructR3 startPoint = firstSurface_ptr->getPoint();
		//VectorStructR3 directionFirstSurface = firstSurface_ptr->getDirection();
		real directionFirstSurface_Z = mDirectionFirstSurface.getZ();
		//real semiHeightFirstSurface = firstSurface_ptr->getSemiHeight();
		// check if first surface is negativ
		if (directionFirstSurface_Z < 0)
		{
			real radiusFirstSurface = firstSurface_ptr->getRadius();
		}
		else
		{
			startPoint.setZ(startPoint.getZ() - mDefaultParaRayAiming.getStartPointFactor());
		}


		// build first ray for ray aiming

		VectorStructR3 BaseVecor1 = { 1.0,1.0,0.0 };
		VectorStructR3 BaseVecor2 = { 1.0,-1.0,0.0 };

		VectorStructR3 Vector1ToCalcDir = 0.5 * mSemiHeightFirstSurface * Math::unitVector(Math::DoCrossProduct(BaseVecor1, mDirectionFirstSurface));
		VectorStructR3 Vector2ToCalcDir = 0.5 * mSemiHeightFirstSurface * Math::unitVector(Math::DoCrossProduct(BaseVecor2, mDirectionFirstSurface));

		VectorStructR3 startPointRay0 = { startPoint.getX() - Vector1ToCalcDir.getX(), startPoint.getY() - Vector1ToCalcDir.getY(), startPoint.getZ() - mDefaultParaRayAiming.getStartPointFactor() };
		VectorStructR3 startPointRay1 = { startPoint.getX() + Vector1ToCalcDir.getX(), startPoint.getY() - Vector1ToCalcDir.getY(), startPoint.getZ() - mDefaultParaRayAiming.getStartPointFactor() };
		VectorStructR3 startPointRay2 = { startPoint.getX() - Vector1ToCalcDir.getX(), startPoint.getY() + Vector1ToCalcDir.getY(), startPoint.getZ() - mDefaultParaRayAiming.getStartPointFactor() };
		VectorStructR3 startPointRay3 = { startPoint.getX() + Vector1ToCalcDir.getX(), startPoint.getY() + Vector1ToCalcDir.getY(), startPoint.getZ() - mDefaultParaRayAiming.getStartPointFactor() };
		VectorStructR3 startPointRay4 = { startPoint.getX(), startPoint.getY(), startPoint.getZ() - mDefaultParaRayAiming.getStartPointFactor() };

		Ray_LLT startRay0(startPointRay0, rayDirection, curRefracIndex);
		Ray_LLT startRay1(startPointRay1, rayDirection, curRefracIndex);
		Ray_LLT startRay2(startPointRay2, rayDirection, curRefracIndex);
		Ray_LLT startRay3(startPointRay3, rayDirection, curRefracIndex);
		Ray_LLT startRay4(startPointRay4, rayDirection, curRefracIndex);

		LightRayStruct lightRayStart0(light, startRay0, 1.0);
		LightRayStruct lightRayStart1(light, startRay1, 1.0);
		LightRayStruct lightRayStart2(light, startRay2, 1.0);
		LightRayStruct lightRayStart3(light, startRay3, 1.0);
		LightRayStruct lightRayStart4(light, startRay4, 1.0);


		// trace all rays until all of them comes to the last surface
		lightRayAndInterPointAperStop bestLightRayAndInterPoint = getBestLightRayAndInterPoint_inf(lightRayStart0, lightRayStart1, lightRayStart2, lightRayStart3, lightRayStart4, targetPoint);

		LightRayStruct bestLightRay = bestLightRayAndInterPoint.getLightRay();
		VectorStructR3 interPointBestLightRay = bestLightRayAndInterPoint.getInterPointAperStop();

		real disXtoTarget = calcDistance_X(targetPoint, interPointBestLightRay);
		real disYtoTarget = calcDistance_Y(targetPoint, interPointBestLightRay);

		int maxInteration = mDefaultParaRayAiming.getMaxInterationRayAiming();

		unsigned int curInteration = 0;
		lightRay_intP_dis_negPos_factor infosToReduce(bestLightRay, interPointBestLightRay, disXtoTarget, disYtoTarget, stay, mDefaultParaRayAiming.getFactor_inf(), mDefaultParaRayAiming.getFactor_inf(), targetPoint, curInteration);


		// reduce distance in X and Y
		infosToReduce = reduceDistancesIn_X_AND_Y_inf(infosToReduce);

		curInteration = infosToReduce.getInterations();

		if (curInteration >= maxInteration)
		{


			printInterP_Target_distance_X_Y(infosToReduce);

			// here we can start robust ray aiming!
			if (mDefaultParaRayAiming.getRobustRayAiming())
			{
				std::cout << "start robust ray aiming" << std::endl;
				
				infosToReduce = robustRayAiming_inf(infosToReduce);

				std::cout << "results from robust ray aiming" << std::endl;
				printInterP_Target_distance_X_Y(infosToReduce);
			}

			else // no robust ray aiming
			{ 
			std::cout << "attention!!! ray aiming did not work perfectly!!!" << std::endl;
			std::cout << "maybe it would help to turn on robust ray aiming!!!" << std::endl;
			std::cout << "maybe the results are not correct!" << std::endl;
			}
		}


		lightRayi = infosToReduce.getLightRay();
	}

	return lightRayi;
}


// calc all distances
std::vector<real> RayAiming::calcAllDistances(const std::vector<lightRayAndInterPointAperStop>& vecLightRaysAndInterPoints, const VectorStructR3& targetPoint)
{
	unsigned int size = vecLightRaysAndInterPoints.size();
	real distance{};
	std::vector<real> allDistances{};
	allDistances.resize(size);


	for (unsigned int i = 0; i < size; ++i)
	{
		distance = Math::distanceTwoVectors(vecLightRaysAndInterPoints[i].getInterPointAperStop(), targetPoint);
		allDistances[i] = distance;
	}

	return allDistances;
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
	real initialFactorY = initialInfos.getFactorY();
	VectorStructR3 targetPoint = initialInfos.getTargetPoint();
	unsigned int initialInterations = initialInfos.getInterations();

	returnLightRay_intP_dis_negPos_fac.setInterations(++initialInterations);
	returnLightRay_intP_dis_negPos_fac.setTargetPoint(targetPoint);

	real semiHeightFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getSemiHeight();

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
	real originPlus_X = initialOrigin_X + semiHeightFirstSurface * initialFactorX;
	real originMinus_X = initialOrigin_X - semiHeightFirstSurface * initialFactorX;
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

	if (disPosTrace_X <= disNegTrace_X && interPointAS_pos.getSurfaceSide() != 'N')
	{
		if (disPosTrace_X <= initialDistanceX)
		{
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_Y(disPosTrace_Y);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY);

			returnLightRay_intP_dis_negPos_fac.setLightRay(lightRayToTracePos);
			returnLightRay_intP_dis_negPos_fac.setInterPoint(interPointAS_pos.getIntersectionPoint());
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_X(disPosTrace_X);
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(posSide);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.9);

		}
		else if (initialDistanceX <= disPosTrace_X)
		{
			returnLightRay_intP_dis_negPos_fac = initialInfos;
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(stay);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.9);
		}



	}

	else if (disNegTrace_X < disPosTrace_X && interPointAS_neg.getSurfaceSide() != 'N')
	{

		if (disNegTrace_X < initialDistanceX)
		{
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_Y(disNegTrace_Y);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY);

			returnLightRay_intP_dis_negPos_fac.setLightRay(lightRayToTraceNeg);
			returnLightRay_intP_dis_negPos_fac.setInterPoint(interPointAS_neg.getIntersectionPoint());
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_X(disNegTrace_X);
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(negSide);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.9);

		}
		else if (initialDistanceX < disNegTrace_X)
		{
			returnLightRay_intP_dis_negPos_fac = initialInfos;
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(stay);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.9);
		}

	}

	else // there is no intersection point with the aperture stop
	{
		returnLightRay_intP_dis_negPos_fac = initialInfos;
		returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(stay);
		returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.5);
	}


	return returnLightRay_intP_dis_negPos_fac;
}

lightRay_intP_dis_negPos_factor RayAiming::traceNegOrPosSide_andReduce_Y_inf(lightRay_intP_dis_negPos_factor initialInfos)
{
	lightRay_intP_dis_negPos_factor returnLightRay_intP_dis_negPos_fac;
	real initalFactorX = initialInfos.getFactorX();
	real semiHeightFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getSemiHeight();
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
	real originPlus_Y = initialOrigin_Y + semiHeightFirstSurface * initialFactorY;
	real originMinus_Y = initialOrigin_Y - semiHeightFirstSurface * initialFactorY;
	originPlus.setY(originPlus_Y);
	std::cout << "reduce Y pos origin Y: " << originPlus.getY() << std::endl;
	originNeg.setY(originMinus_Y);
	std::cout << "reduce Y neg origin Y: " << originNeg.getY() << std::endl;

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
	std::cout << "reduce Y disPosTrace Y: " << disPosTrace_Y << std::endl;
	real disNegTrace_Y = calcDistance_Y(interPointAS_neg.getIntersectionPoint(), targetPoint);
	real disNegTrace_X = calcDistance_X(interPointAS_neg.getIntersectionPoint(), targetPoint);
	std::cout << "reduce Y disNegTrace Y: " << disNegTrace_Y << std::endl;


	if (disPosTrace_Y <= disNegTrace_Y && interPointAS_pos.getSurfaceSide() != 'N')
	{
		if (disPosTrace_Y <= initialDistanceY)
		{
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_X(disPosTrace_X);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initalFactorX);

			returnLightRay_intP_dis_negPos_fac.setLightRay(lightRayToTracePos);
			returnLightRay_intP_dis_negPos_fac.setInterPoint(interPointAS_pos.getIntersectionPoint());
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_Y(disPosTrace_Y);
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(posSide);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.9);

		}
		else if (initialDistanceY <= disPosTrace_Y)
		{
			returnLightRay_intP_dis_negPos_fac = initialInfos;
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(stay);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.9);
		}



	}

	else if (disNegTrace_Y < disPosTrace_Y && interPointAS_neg.getSurfaceSide() != 'N')
	{

		if (disNegTrace_Y < initialDistanceY)
		{
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_X(disNegTrace_X);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initalFactorX);

			returnLightRay_intP_dis_negPos_fac.setLightRay(lightRayToTraceNeg);
			returnLightRay_intP_dis_negPos_fac.setInterPoint(interPointAS_neg.getIntersectionPoint());
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_Y(disNegTrace_Y);
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(negSide);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.9);

		}
		else if (initialDistanceY < disNegTrace_Y)
		{
			returnLightRay_intP_dis_negPos_fac = initialInfos;
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(stay);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.9);
		}

	}

	else // there is no intersection point with the aperture stop
	{
		returnLightRay_intP_dis_negPos_fac = initialInfos;
		returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(stay);
		returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.5);
	}



	return returnLightRay_intP_dis_negPos_fac;
}

defaultRayAimingStruct RayAiming::getDefaultParameters()
{
	return mDefaultParaRayAiming;
}

void RayAiming::setToleranceX_Y(real tolerance)
{
	mDefaultParaRayAiming.setTolerance_XandY(tolerance);
}

void RayAiming::turn_ON_RobustRayAiming()
{
	mDefaultParaRayAiming.turn_On_RobustRayAiming();
}
void RayAiming::turn_OFF_RobustRayAiming()
{
	mDefaultParaRayAiming.turn_Off_RobustRayAiming();
}

// robust ray aiming
lightRay_intP_dis_negPos_factor RayAiming::robustRayAiming_inf(lightRay_intP_dis_negPos_factor initialInfos)
{
	real disYtoTarget = initialInfos.getDistanceInterToTarget_Y();
	real disXtoTarget = initialInfos.getDistanceInterToTarget_X();
	unsigned int interation = 0;
	real maxInteration = mDefaultParaRayAiming.getMaxInterationRayAiming();

	lightRay_intP_dis_negPos_factor interInfosRA_new = initialInfos;
	interInfosRA_new.setInterations(interation);

	real factorReduceX = initialInfos.getFactorX();
	real factorReduceY = initialInfos.getFactorY();

	real newFactorX = mDefaultParaRayAiming.getFactor_inf();
	real newFactorY = mDefaultParaRayAiming.getFactor_inf();

	interInfosRA_new.setFactorX(newFactorX);
	interInfosRA_new.setFactorY(newFactorY);


	while (((std::abs(disYtoTarget) > mDefaultParaRayAiming.getTolerance_XandY() || std::abs(disXtoTarget) > mDefaultParaRayAiming.getTolerance_XandY())) && (interation < maxInteration))
	{
		interInfosRA_new = calcNewBestInfos_inf(interInfosRA_new);
		interInfosRA_new = reduceDistancesIn_X_AND_Y_inf(interInfosRA_new);

		disYtoTarget = interInfosRA_new.getDistanceInterToTarget_Y();
		disXtoTarget = interInfosRA_new.getDistanceInterToTarget_X();
		interation = interInfosRA_new.getInterations();
	}

	//LightRayStruct returnLightRay = interInfosRA_new.getLightRay();

	return interInfosRA_new;
}

lightRay_intP_dis_negPos_factor RayAiming::calcNewBestInfos_inf(lightRay_intP_dis_negPos_factor initialInfos)
{
	lightRay_intP_dis_negPos_factor returnInfos = initialInfos;
	real variancePercent = mDefaultParaRayAiming.getVariancePercentRRA();
	VectorStructR3 targetPoint = initialInfos.getTargetPoint();

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
		VectorStructR3 rayDirectionUnit = initialLightRay.getRay_LLT().getDirectionRayUnit();
		real currentRefIndex = initialLightRay.getRay_LLT().getCurrentRefractiveIndex();
		Light_LLT light = initialLightRay.getLight_LLT();

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
			LightRayStruct lightRay0(light, ray0, 1);
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
			LightRayStruct lightRay1(light, ray1, 1);
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
			LightRayStruct lightRay2(light, ray2, 1);
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
			LightRayStruct lightRay3(light, ray3, 1);
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
			LightRayStruct lightRay4(light, ray4, 1);
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
			LightRayStruct lightRay5(light, ray5, 1);
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
			LightRayStruct lightRay6(light, ray6, 1);
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
			LightRayStruct lightRay7(light, ray7, 1);
			lightRay_vec[putLightAtPos] = lightRay7;
			++putLightAtPos;
		}

		// trace the rays
		for (unsigned int i = 0; i < sizeRayToTace; ++i)
		{
			seqTrace.sequentialRayTracing(lightRay_vec[i]);
		}
		

		interInfosAS_vec = seqTrace.getAllInterInfosOfSurf_i_notFiltered(mPosApertureStop);
		interPointsAS = seqTrace.getAllInterPointsAtSurf_i(mPosApertureStop);

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
				if (interInfosAS_vec[i].getSurfaceSide() == 'N') // we have to trace that ray again
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
	unsigned posBestRay = getPosRayLowestDistance(interPointsAS, targetPoint);

	// new infos 
	LightRayStruct newBestRay = lightRay_vec[posBestRay];
	VectorStructR3 newInterPointAS = seqTrace.getAllInterPointsAtSurf_i(mPosApertureStop)[posBestRay];
	real distance_X = calcDistance_X(newInterPointAS, targetPoint);
	real distance_Y = calcDistance_Y(newInterPointAS, targetPoint);
	// ***

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
	reduceWhat redWhat = reduce_X;

	while (((std::abs(disYtoTarget) > mDefaultParaRayAiming.getTolerance_XandY() || std::abs(disXtoTarget) > mDefaultParaRayAiming.getTolerance_XandY())) && (interation < maxInteration))
	{
		if (disXtoTarget >= disYtoTarget && redWhat == reduce_X)
		{

			initialInfos = traceNegOrPosSide_andReduce_X_inf(initialInfos);
			disXtoTarget = initialInfos.getDistanceInterToTarget_X();
			disYtoTarget = initialInfos.getDistanceInterToTarget_Y();

			if (initialInfos.getNegOrPosSide() == stay)
			{
				++stayCounter;
				if (stayCounter > mDefaultParaRayAiming.getMaxStayCounter())
				{
					redWhat = reduce_Y;
					stayCounter = 0;
				}
			}
			else
			{
				stayCounter = 0;
			}

			++interation;
		}
		else
		{
			initialInfos = traceNegOrPosSide_andReduce_Y_inf(initialInfos);
			disXtoTarget = initialInfos.getDistanceInterToTarget_X();
			disYtoTarget = initialInfos.getDistanceInterToTarget_Y();

			if (initialInfos.getNegOrPosSide() == stay)
			{
				++stayCounter;
				if (stayCounter > mDefaultParaRayAiming.getMaxStayCounter())
				{
					redWhat = reduce_X;
					stayCounter = 0;
				}
			}
			else
			{
				stayCounter = 0;
			}

			++interation;
			redWhat = reduce_X;
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

LightRayStruct RayAiming::rayAiming_obj(VectorStructR3 rayOrigin, VectorStructR3 targetPoint, Light_LLT light, real curRefracIndex)
{
	LightRayStruct lightRayi;

	// aperture stop is first (0) surface
	if (mPosApertureStop == 0)
	{
		VectorStructR3 rayDirection = targetPoint - rayOrigin;
		Ray_LLT startRayObj(rayOrigin, rayDirection, curRefracIndex);

		lightRayi.setRay_LLT(startRayObj);
		lightRayi.setLight_LLT(light);
		lightRayi.setIsAlive(1);

	}

	// aperture stop is NOT first surface
	else
	{
		std::shared_ptr<SurfaceIntersectionRay_LLT> firstSurface_ptr = mOpticalSystem_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr();

		// build first ray for ray aiming
		real semiHeightFirstSurface = firstSurface_ptr->getSemiHeight();
		VectorStructR3 originFirstSurface = firstSurface_ptr->getPoint();
		VectorStructR3 directionFirstSurface = firstSurface_ptr->getDirection();

		VectorStructR3 BaseVecor1 = { 1.0,1.0,0.0 };
		VectorStructR3 BaseVecor2 = { 1.0,-1.0,0.0 };

		VectorStructR3 Vector1ToCalcDir = 0.5 * semiHeightFirstSurface * Math::unitVector(Math::DoCrossProduct(BaseVecor1, directionFirstSurface));
		VectorStructR3 Vector2ToCalcDir = 0.5 * semiHeightFirstSurface * Math::unitVector(Math::DoCrossProduct(BaseVecor2, directionFirstSurface));

		VectorStructR3 rayDirection0 = { originFirstSurface - rayOrigin + Vector1ToCalcDir };
		VectorStructR3 rayDirection1 = { originFirstSurface - rayOrigin - Vector1ToCalcDir };
		VectorStructR3 rayDirection2 = { originFirstSurface - rayOrigin + Vector2ToCalcDir };
		VectorStructR3 rayDirection3 = { originFirstSurface - rayOrigin - Vector2ToCalcDir };
		VectorStructR3 rayDirection4 = { originFirstSurface - rayOrigin };

		Ray_LLT startRay0(rayOrigin, rayDirection0, curRefracIndex);
		Ray_LLT startRay1(rayOrigin, rayDirection1, curRefracIndex);
		Ray_LLT startRay2(rayOrigin, rayDirection2, curRefracIndex);
		Ray_LLT startRay3(rayOrigin, rayDirection3, curRefracIndex);
		Ray_LLT startRay4(rayOrigin, rayDirection4, curRefracIndex);

		LightRayStruct lightRayStart0(light, startRay0, 1.0);
		LightRayStruct lightRayStart1(light, startRay1, 1.0);
		LightRayStruct lightRayStart2(light, startRay2, 1.0);
		LightRayStruct lightRayStart3(light, startRay3, 1.0);
		LightRayStruct lightRayStart4(light, startRay4, 1.0);


		// trace all rays until all of them comes to the last surface
		lightRayAndInterPointAperStop bestLightRayAndInterPoint = getBestLightRayAndInterPoint_obj(lightRayStart0, lightRayStart1, lightRayStart2, lightRayStart3, lightRayStart4, targetPoint, Vector1ToCalcDir, Vector2ToCalcDir);

		LightRayStruct bestLightRay = bestLightRayAndInterPoint.getLightRay();
		VectorStructR3 interPointBestLightRay = bestLightRayAndInterPoint.getInterPointAperStop();

		real disXtoTarget = calcDistance_X(targetPoint, interPointBestLightRay);
		real disYtoTarget = calcDistance_Y(targetPoint, interPointBestLightRay);

		int maxInteration = mDefaultParaRayAiming.getMaxInterationRayAiming();

		unsigned int curInteration = 0;
		lightRay_intP_dis_negPos_factor infosToReduce(bestLightRay, interPointBestLightRay, disXtoTarget, disYtoTarget, stay, mDefaultParaRayAiming.getFactor_obj(), mDefaultParaRayAiming.getFactor_obj(), targetPoint, curInteration);


		// reduce distance in X and Y
		infosToReduce = reduceDistancesIn_X_AND_Y_obj(infosToReduce);
			   
		curInteration = infosToReduce.getInterations();

		if (curInteration >= maxInteration)
		{


			printInterP_Target_distance_X_Y(infosToReduce);

			// here we can start robust ray aiming!
			if (mDefaultParaRayAiming.getRobustRayAiming())
			{
				std::cout << "start robust ray aiming" << std::endl;

				infosToReduce = robustRayAiming_obj(infosToReduce);

				std::cout << "results from robust ray aiming" << std::endl;
				printInterP_Target_distance_X_Y(infosToReduce);
			}

			else // no robust ray aiming
			{
				std::cout << "attention!!! ray aiming did not work perfectly!!!" << std::endl;
				std::cout << "maybe it would help to turn on robust ray aiming!!!" << std::endl;
				std::cout << "maybe the results are not correct!" << std::endl;
			}
		}


		lightRayi = infosToReduce.getLightRay();
	}

	return lightRayi;
}



// trace all rays until all of them comes to the last surface
lightRayAndInterPointAperStop RayAiming::getBestLightRayAndInterPoint_obj(LightRayStruct lightRay0, LightRayStruct lightRay1, LightRayStruct lightRay2, LightRayStruct lightRay3, LightRayStruct lightRay4, VectorStructR3 targetPoint, VectorStructR3 vectorToCalc1, VectorStructR3 vectorRoCalc2)
{
	lightRayAndInterPointAperStop bestLightRayAndInterPoint;

	std::vector<lightRayAndInterPointAperStop> lightRayAndInterPointAS;
	lightRayAndInterPointAS.resize(5);
	unsigned maxLoops = mDefaultParaRayAiming.getMaxLoopsTraceToLastSurface();


	lightRayAndInterPointAS.at(0) = traceOneRayUntilInApertureStop_obj(lightRay0, vectorToCalc1, maxLoops);
	lightRayAndInterPointAS.at(1) = traceOneRayUntilInApertureStop_obj(lightRay1, -1.0 * vectorToCalc1, maxLoops);
	lightRayAndInterPointAS.at(2) = traceOneRayUntilInApertureStop_obj(lightRay2, vectorRoCalc2,  maxLoops);
	lightRayAndInterPointAS.at(3) = traceOneRayUntilInApertureStop_obj(lightRay3, -1.0 * vectorRoCalc2, maxLoops);
	lightRayAndInterPointAS.at(4) = traceOneRayUntilInApertureStop_obj(lightRay4, vectorToCalc1, maxLoops);

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
lightRayAndInterPointAperStop RayAiming::traceOneRayUntilInApertureStop_obj(LightRayStruct lightRay, VectorStructR3 vectorToCalcDir, unsigned int maxLoop)
{
	lightRayAndInterPointAperStop tempLightRayAndInterPointAS{};

	unsigned int loopCounter = 0;
	VectorStructR3 interpointApertureStop{};

	SequentialRayTracing seqTrace(mOpticalSystem_LLT);
	// trace ray only to aperture stop
	seqTrace.setTraceToSurface(mPosApertureStop);
	// trace the light ray
	seqTrace.sequentialRayTracing(lightRay);

	VectorStructR3 originFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getPoint();

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
		char surfSide = seqTrace.getAllInterInfosOfSurf_i_notFiltered(mPosApertureStop)[loopCounter].getSurfaceSide();

		if ('N' == surfSide) 
		{
			// build new ray to trace
			tempVecToCalcDir = tempVecToCalcDir * 0.5;
			newRayDirection = { originFirstSurface - originRay + tempVecToCalcDir };

			newRay.setDirectionRayUnit(newRayDirection);
			newRay.setCurrentRefractiveIndex(curRefIndex);
			newRay.setOriginRay(originRay);

			lightRay.setRay_LLT(newRay);

			// trace new ray
			seqTrace.sequentialRayTracing(lightRay);
			
		}

		else if ('A' == surfSide || 'B' == surfSide) // ray comes to the last surface
		{
			ray_NOT_AtLastSurface = false;
			tempLightRayAndInterPointAS.setInterPointAperStop(seqTrace.getAllInterPointsAtSurf_i(mPosApertureStop).back());
			tempLightRayAndInterPointAS.setLightRay(lightRay);

			return tempLightRayAndInterPointAS;
		}

		else if (loopCounter > maxLoop)
		{
			std::cout << "we could not trace the ray until the aperture stop. Maybe there is a mistake doing ray aiming" << std::endl;
			ray_NOT_AtLastSurface = false; // -> get out of the loop
		}

		++loopCounter;

	}



	return tempLightRayAndInterPointAS;
}

lightRay_intP_dis_negPos_factor RayAiming::traceNegOrPosSide_andReduce_X_obj(lightRay_intP_dis_negPos_factor initialInfos)
{
	lightRay_intP_dis_negPos_factor returnLightRay_intP_dis_negPos_fac;
	real initialFactorY = initialInfos.getFactorY();
	VectorStructR3 targetPoint = initialInfos.getTargetPoint();
	unsigned int initialInterations = initialInfos.getInterations();

	returnLightRay_intP_dis_negPos_fac.setInterations(++initialInterations);
	returnLightRay_intP_dis_negPos_fac.setTargetPoint(targetPoint);

	real semiHeightFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getSemiHeight();

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
	real directionPlus_X = initialDirection_X + semiHeightFirstSurface * initialFactorX;
	real directionMinus_X = initialDirection_X - semiHeightFirstSurface * initialFactorX;
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

	if (disPosTrace_X <= disNegTrace_X && interPointAS_pos.getSurfaceSide() != 'N')
	{
		if (disPosTrace_X <= initialDistanceX)
		{
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_Y(disPosTrace_Y);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY);

			returnLightRay_intP_dis_negPos_fac.setLightRay(lightRayToTracePos);
			returnLightRay_intP_dis_negPos_fac.setInterPoint(interPointAS_pos.getIntersectionPoint());
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_X(disPosTrace_X);
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(posSide);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.9);

		}
		else if (initialDistanceX <= disPosTrace_X)
		{
			returnLightRay_intP_dis_negPos_fac = initialInfos;
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(stay);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.9);
		}



	}

	else if (disNegTrace_X < disPosTrace_X && interPointAS_neg.getSurfaceSide() != 'N')
	{

		if (disNegTrace_X < initialDistanceX)
		{
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_Y(disNegTrace_Y);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY);

			returnLightRay_intP_dis_negPos_fac.setLightRay(lightRayToTraceNeg);
			returnLightRay_intP_dis_negPos_fac.setInterPoint(interPointAS_neg.getIntersectionPoint());
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_X(disNegTrace_X);
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(negSide);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.9);

		}
		else if (initialDistanceX < disNegTrace_X)
		{
			returnLightRay_intP_dis_negPos_fac = initialInfos;
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(stay);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.9);
		}

	}

	else // there is no intersection point with the aperture stop
	{
		returnLightRay_intP_dis_negPos_fac = initialInfos;
		returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(stay);
		returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.5);
	}


	return returnLightRay_intP_dis_negPos_fac;
}

lightRay_intP_dis_negPos_factor RayAiming::traceNegOrPosSide_andReduce_Y_obj(lightRay_intP_dis_negPos_factor initialInfos)
{
	lightRay_intP_dis_negPos_factor returnLightRay_intP_dis_negPos_fac;
	real initalFactorX = initialInfos.getFactorX();
	real semiHeightFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getSemiHeight();
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
	real directionPlus_Y = initialDirection_Y + semiHeightFirstSurface * initialFactorY;
	real directionMinus_Y = initialDirection_Y - semiHeightFirstSurface * initialFactorY;
	directionPlus.setY(directionPlus_Y);
	std::cout << "reduce Y pos direction Y: " << directionPlus.getY() << std::endl;
	directionNeg.setY(directionMinus_Y);
	std::cout << "reduce Y neg direction Y: " << directionNeg.getY() << std::endl;

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
	std::cout << "reduce Y direction - distance: " << disPosTrace_Y << std::endl;
	real disNegTrace_Y = calcDistance_Y(interPointAS_neg.getIntersectionPoint(), targetPoint);
	real disNegTrace_X = calcDistance_X(interPointAS_neg.getIntersectionPoint(), targetPoint);
	std::cout << "reduce Y direction - distance: " << disNegTrace_Y << std::endl;


	if (disPosTrace_Y <= disNegTrace_Y && interPointAS_pos.getSurfaceSide() != 'N')
	{
		if (disPosTrace_Y <= initialDistanceY)
		{
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_X(disPosTrace_X);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initalFactorX);

			returnLightRay_intP_dis_negPos_fac.setLightRay(lightRayToTracePos);
			returnLightRay_intP_dis_negPos_fac.setInterPoint(interPointAS_pos.getIntersectionPoint());
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_Y(disPosTrace_Y);
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(posSide);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.9);

		}
		else if (initialDistanceY <= disPosTrace_Y)
		{
			returnLightRay_intP_dis_negPos_fac = initialInfos;
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(stay);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.9);
		}



	}

	else if (disNegTrace_Y < disPosTrace_Y && interPointAS_neg.getSurfaceSide() != 'N')
	{

		if (disNegTrace_Y < initialDistanceY)
		{
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_X(disNegTrace_X);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initalFactorX);

			returnLightRay_intP_dis_negPos_fac.setLightRay(lightRayToTraceNeg);
			returnLightRay_intP_dis_negPos_fac.setInterPoint(interPointAS_neg.getIntersectionPoint());
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_Y(disNegTrace_Y);
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(negSide);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.9);

		}
		else if (initialDistanceY < disNegTrace_Y)
		{
			returnLightRay_intP_dis_negPos_fac = initialInfos;
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(stay);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.9);
		}

	}

	else // there is no intersection point with the aperture stop
	{
		returnLightRay_intP_dis_negPos_fac = initialInfos;
		returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(stay);
		returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.5);
	}



	return returnLightRay_intP_dis_negPos_fac;
}


lightRay_intP_dis_negPos_factor RayAiming::reduceDistancesIn_X_AND_Y_obj(lightRay_intP_dis_negPos_factor initialInfos)
{
	real disYtoTarget = initialInfos.getDistanceInterToTarget_Y();
	real disXtoTarget = initialInfos.getDistanceInterToTarget_X();
	unsigned int interation = initialInfos.getInterations();
	real maxInteration = mDefaultParaRayAiming.getMaxInterationRayAiming();

	unsigned int stayCounter = 0;
	reduceWhat redWhat = reduce_X;

	while (((std::abs(disYtoTarget) > mDefaultParaRayAiming.getTolerance_XandY() || std::abs(disXtoTarget) > mDefaultParaRayAiming.getTolerance_XandY())) && (interation < maxInteration))
	{
		if (disXtoTarget >= disYtoTarget && redWhat == reduce_X)
		{

			initialInfos = traceNegOrPosSide_andReduce_X_obj(initialInfos);
			disXtoTarget = initialInfos.getDistanceInterToTarget_X();
			disYtoTarget = initialInfos.getDistanceInterToTarget_Y();

			if (initialInfos.getNegOrPosSide() == stay)
			{
				++stayCounter;
				if (stayCounter > mDefaultParaRayAiming.getMaxStayCounter())
				{
					redWhat = reduce_Y;
					stayCounter = 0;
				}
			}
			else
			{
				stayCounter = 0;
			}

			++interation;
		}
		else
		{
			initialInfos = traceNegOrPosSide_andReduce_Y_obj(initialInfos);
			disXtoTarget = initialInfos.getDistanceInterToTarget_X();
			disYtoTarget = initialInfos.getDistanceInterToTarget_Y();

			if (initialInfos.getNegOrPosSide() == stay)
			{
				++stayCounter;
				if (stayCounter > mDefaultParaRayAiming.getMaxStayCounter())
				{
					redWhat = reduce_X;
					stayCounter = 0;
				}
			}
			else
			{
				stayCounter = 0;
			}

			++interation;
			redWhat = reduce_X;
		}
	}

	initialInfos.setInterations(interation);

	return initialInfos;


}

// robust ray aiming
lightRay_intP_dis_negPos_factor RayAiming::robustRayAiming_obj(lightRay_intP_dis_negPos_factor initialInfos)
{
	real disYtoTarget = initialInfos.getDistanceInterToTarget_Y();
	real disXtoTarget = initialInfos.getDistanceInterToTarget_X();
	unsigned int interation = 0;
	real maxInteration = mDefaultParaRayAiming.getMaxInterationRayAiming();

	lightRay_intP_dis_negPos_factor interInfosRA_new = initialInfos;
	interInfosRA_new.setInterations(interation);

	real factorReduceX = initialInfos.getFactorX();
	real factorReduceY = initialInfos.getFactorY();

	real newFactorX = mDefaultParaRayAiming.getFactor_obj();
	real newFactorY = mDefaultParaRayAiming.getFactor_obj();

	interInfosRA_new.setFactorX(newFactorX);
	interInfosRA_new.setFactorY(newFactorY);


	while (((std::abs(disYtoTarget) > mDefaultParaRayAiming.getTolerance_XandY() || std::abs(disXtoTarget) > mDefaultParaRayAiming.getTolerance_XandY())) && (interation < maxInteration))
	{
		interInfosRA_new = calcNewBestInfos_obj(interInfosRA_new);
		interInfosRA_new = reduceDistancesIn_X_AND_Y_obj(interInfosRA_new);

		disYtoTarget = interInfosRA_new.getDistanceInterToTarget_Y();
		disXtoTarget = interInfosRA_new.getDistanceInterToTarget_X();
		interation = interInfosRA_new.getInterations();
	}

	//LightRayStruct returnLightRay = interInfosRA_new.getLightRay();

	return interInfosRA_new;
}

// calculate new origin variance in percent
lightRay_intP_dis_negPos_factor RayAiming::calcNewBestInfos_obj(lightRay_intP_dis_negPos_factor initialInfos)
{
	lightRay_intP_dis_negPos_factor returnInfos = initialInfos;
	real variancePercent = mDefaultParaRayAiming.getVariancePercentRRA();
	VectorStructR3 targetPoint = initialInfos.getTargetPoint();

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
		Light_LLT light = initialLightRay.getLight_LLT();

		real direction_X = initialLightRay.getRay_LLT().getDirectionRayUnit().getX();
		real direction_Y = initialLightRay.getRay_LLT().getDirectionRayUnit().getY();
		real direction_Z = initialLightRay.getRay_LLT().getDirectionRayUnit().getZ();

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
			LightRayStruct lightRay0(light, ray0, 1);
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
			LightRayStruct lightRay1(light, ray1, 1);
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
			LightRayStruct lightRay2(light, ray2, 1);
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
			LightRayStruct lightRay3(light, ray3, 1);
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
			LightRayStruct lightRay4(light, ray4, 1);
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
			LightRayStruct lightRay5(light, ray5, 1);
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
			LightRayStruct lightRay6(light, ray6, 1);
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
			LightRayStruct lightRay7(light, ray7, 1);
			lightRay_vec[putLightAtPos] = lightRay7;
			++putLightAtPos;
		}

		// trace the rays
		for (unsigned int i = 0; i < sizeRayToTace; ++i)
		{
			seqTrace.sequentialRayTracing(lightRay_vec[i]);
		}


		interInfosAS_vec = seqTrace.getAllInterInfosOfSurf_i_notFiltered(mPosApertureStop);
		interPointsAS = seqTrace.getAllInterPointsAtSurf_i(mPosApertureStop);

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
				if (interInfosAS_vec[i].getSurfaceSide() == 'N') // we have to trace that ray again
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
	unsigned posBestRay = getPosRayLowestDistance(interPointsAS, targetPoint);

	// new infos 
	LightRayStruct newBestRay = lightRay_vec[posBestRay];
	VectorStructR3 newInterPointAS = seqTrace.getAllInterPointsAtSurf_i(mPosApertureStop)[posBestRay];
	real distance_X = calcDistance_X(newInterPointAS, targetPoint);
	real distance_Y = calcDistance_Y(newInterPointAS, targetPoint);
	// ***

	returnInfos.setLightRay(newBestRay);
	returnInfos.setInterPoint(newInterPointAS);
	returnInfos.setDistanceInterToTarger_X(distance_X);
	returnInfos.setDistanceInterToTarger_Y(distance_Y);

	return returnInfos;
}
