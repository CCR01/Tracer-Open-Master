#include "RayAiming.h"
#include <iostream>
#include <cmath>
#include <typeinfo>   // operator typeid
#include "..\LowLevelTracing\Math_LLT.h"
#include "..\SequentialRayTracing\SequentialRayTracer.h"
#include <iomanip> 

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

// factor
real defaultRayAimingStruct::getFactor()
{
	return mFactor;
}
void defaultRayAimingStruct::setFactor(real factor)
{
	mFactor = factor;
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

void defaultRayAimingStruct::loadDefaultParameter()
{
	mTolerance_XandY = 0.0001;
	mStartPointFactor = 1.0;
	mMaxLoopsTraceToLastSurface = 5;
	mMaxInterationsRayAiming = 50;
	mFactor = 0.9;
	turn_Off_RobustRayAiming();
	mVariancePercentRobustRA = 0.1;
}



RayAiming::RayAiming(OpticalSystem_LLT opticalSystem) : 
	mOpticalSystem_LLT(opticalSystem)
{
	loadImportantInfosForRayAiming();
	mDefaultParaRayAiming.loadDefaultParameter();
	insertPlanBeforFirstSur();
	mSeqTracModified_LLT.setOpticalSystem(mOpticalSystemModified_LLT);
	mPosApertureStop = mOpticalSystem_LLT.getPosApertureStop();
	mPosApertureStopModify = mOpticalSystemModified_LLT.getPosApertureStop();
};

// load important infomation for ray aiming
void RayAiming::loadImportantInfosForRayAiming()
{
	mSemiHeightFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface().at(0).getSurfaceInterRay_ptr()->getSemiHeight();
	mRadiusFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface().at(0).getSurfaceInterRay_ptr()->getRadius();
	mPositionFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface().at(0).getSurfaceInterRay_ptr()->getPoint();
	mDirectionFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface().at(0).getSurfaceInterRay_ptr()->getDirection();
}

void RayAiming::insertPlanBeforFirstSur()
{
	mOpticalSystemModified_LLT = mOpticalSystem_LLT;

	PlanGeometry_LLT planeToInsertBeforeFirstSurface;
	real directionZ_firstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getDirection().getZ();

	VectorStructR3 pointFirstSur = mOpticalSystem_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getPoint();
	real semiHeightFirstSur = mOpticalSystem_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getSemiHeight();
	real radiusFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getRadius();;
	real refIndex = 1.0;
	VectorStructR3 direction = { 0.0,0.0,1.0 };

	planeToInsertBeforeFirstSurface.setDirection(direction);
	planeToInsertBeforeFirstSurface.setRefractiveIndexSide_A(refIndex);
	planeToInsertBeforeFirstSurface.setRefractiveIndexSide_B(refIndex);
	planeToInsertBeforeFirstSurface.setSemiHeight(semiHeightFirstSur * 2);

	if (directionZ_firstSurface > 0) // that means we have a "positiv" radius
	{
		// the point of the plane before the first surface must be a little bit before the point of the first surface
		real pointFirstSurface_Z = pointFirstSur.getZ() - mDefaultParaRayAiming.getStartPointFactor();
		pointFirstSur.setZ(pointFirstSurface_Z);
		planeToInsertBeforeFirstSurface.setPoint(pointFirstSur);
	}

	else if (directionZ_firstSurface < 0) // that means we have a negativ radius
	{
		VectorStructR3 PointPlanBeforeFirstSurface = shiftFirstSurface(mRadiusFirstSurface, semiHeightFirstSur, pointFirstSur);
		planeToInsertBeforeFirstSurface.setPoint(PointPlanBeforeFirstSurface);

	}
	else if (directionZ_firstSurface == 0)
	{
		//TODO: we have to handle that case later
		std::cout << "The direction of the first surface is 0! The optical system is mybee not designed along the optical axis in z directio. For that case we can not do the ray aiming" << std::endl;
	}

	std::shared_ptr<SurfaceIntersectionRay_LLT> interactinSurface_ptr(new PlanGeometry_LLT);
	interactinSurface_ptr = planeToInsertBeforeFirstSurface.clone();

	mOpticalSystemModified_LLT.fillInSurfaceAndInteracAtPos_i(0, interactinSurface_ptr, doNothing.clone());
}


// trace one ray until it comes to the last surface;
lightRayAndInterPointAperStop RayAiming::traceOneRayUntilLastSurface_infRayAiming(LightRayStruct lightRay, unsigned int maxLoop)
{
	lightRayAndInterPointAperStop tempLightRayAndInterPointAS{};

	unsigned int loopCounter = 0;
	VectorStructR3 interpointApertureStop{};

	SequentialRayTracing seqTrace(mOpticalSystem_LLT);
	seqTrace.sequentialRayTracing(lightRay);

	real curRefIndex = lightRay.getRay_LLT().getCurrentRefractiveIndex();
	VectorStructR3 DirectionUnit = lightRay.getRay_LLT().getDirectionRayUnit();

	real rayOriginX;
	real rayOriginY;
	real rayOriginZ;
	VectorStructR3 newOrigin;
	Ray_LLT newRay;

	unsigned int posLastSurface = mOpticalSystem_LLT.getPosAndInteractingSurface().size() - 1;
	bool ray_NOT_AtLastSurface = true;
	// check if light ray comes to last surface
	while(ray_NOT_AtLastSurface)
	{ 
		char surfSide = seqTrace.getAllInterInfosOfSurf_i_notFiltered(posLastSurface)[loopCounter].getSurfaceSide();

		if( 'N' == surfSide) // ray comes not to last surface
		{
			// build new ray to trace
			rayOriginX = lightRay.getRay_LLT().getOriginRay().getX();
			rayOriginY = lightRay.getRay_LLT().getOriginRay().getY();
			rayOriginZ = lightRay.getRay_LLT().getOriginRay().getZ();

			newOrigin = { rayOriginX * 0.5, rayOriginY * 0.5, rayOriginZ };

			newRay.setCurrentRefractiveIndex(curRefIndex);
			newRay.setDirectionRay(DirectionUnit);
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
			std::cout << "we could not trace the ray until the last surface. Maybe the is a mistake doing ray aiming" << std::endl;
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

	lightRayAndInterPointAS.at(0) = traceOneRayUntilLastSurface_infRayAiming(lightRay0, maxLoops);
	lightRayAndInterPointAS.at(1) = traceOneRayUntilLastSurface_infRayAiming(lightRay1, maxLoops);
	lightRayAndInterPointAS.at(2) = traceOneRayUntilLastSurface_infRayAiming(lightRay2, maxLoops);
	lightRayAndInterPointAS.at(3) = traceOneRayUntilLastSurface_infRayAiming(lightRay3, maxLoops);
	lightRayAndInterPointAS.at(4) = traceOneRayUntilLastSurface_infRayAiming(lightRay4, maxLoops);

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
// Falls Aperturblende erste Fläche ist, ist kein Ray-Aiming erforderlich. Ansonsten Objekt- oder undendlich-bezogenes Ray-Aiming
LightRayStruct RayAiming::rayAimingMain(VectorStructR3 mainVector /*Ray direction or start point*/, VectorStructR3 targetPoint, double wavelength, double curRefracIndex)
{
	// irgendwo muss noch die Information übergeben werden ob es sich um einen Objekt-Strahl oder einen Infinity-Strahl handelt

	int positionApertureStop = mPosApertureStopModify;
	VectorStructR3 startPoint = { mSeqTracModified_LLT.getPointSurface_i(0).getX(),mSeqTracModified_LLT.getPointSurface_i(0).getY(),mSeqTracModified_LLT.getPointSurface_i(0).getZ() - 0.0000001 };
	VectorStructR3 rayDirection = { 0.0,0.0,1.0 };

	Ray_LLT lightRayLLT0(startPoint, rayDirection, curRefracIndex);
	lightRayLLT0.setDirectionRay(rayDirection);
	Light_LLT light(wavelength, 1.0, { 0.0, 0.0, 0.0,0.0 }, typeLightRay, 0);

	LightRayStruct lightRayStruct0;
	lightRayStruct0.setRay_LLT(lightRayLLT0);
	lightRayStruct0.setLight_LLT(light);

	/*
	Wenn die Aperturblende die erste Fläche ist (0. Fläche wird in der Header-Datei generiert), dann Strahl direkt vektoriell berechnen.
	je nachdem ob infinity- oder Objekt-Strahl wird die entsprechende Methode aufgerufen
	*/
	if (positionApertureStop == 1)
	{
		positionApertureStop = 1;
	}


	return lightRayStruct0;
}


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
LightRayStruct RayAiming::infinityRayAiming(VectorStructR3 rayDirection, VectorStructR3 targetPoint, Light_LLT light, double curRefracIndex)
{

	LightRayStruct lightRayi;
	
	if (mPosApertureStopModify == 0)
	{
		//TODO Carsten: Das muss ich mir noch ganeu anschauen!

		// tan(a) = Gegenkath / Ankath
		double tanDegreeXZ = rayDirection.getX() / rayDirection.getZ();
		double tanDegreeYZ = rayDirection.getY() / rayDirection.getZ();
		double startPointX = targetPoint.getX() - tanDegreeXZ * mDefaultParaRayAiming.getStartPointFactor();
		double startPointY = targetPoint.getY() - tanDegreeYZ * mDefaultParaRayAiming.getStartPointFactor();
		double startPointZ = targetPoint.getZ() - mDefaultParaRayAiming.getStartPointFactor();
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
		VectorStructR3 directionFirstSurface = firstSurface_ptr->getDirection();
		real directionFirstSurface_Z = directionFirstSurface.getZ();
		double semiHeightFirstSurface = firstSurface_ptr->getSemiHeight();
		// check if first surface is negativ
		if (directionFirstSurface_Z < 0)
		{
			real radiusFirstSurface = firstSurface_ptr->getRadius();
			startPoint = shiftFirstSurface(radiusFirstSurface, semiHeightFirstSurface, startPoint);
		}
		else
		{
		  startPoint.setZ(startPoint.getZ() - mDefaultParaRayAiming.getStartPointFactor());
		}
			

		// build first ray for ray aiming
		
		//double semiHeightApertureStop = mSeqTracModified.getSemiHeightOfSurface_i(mPosApertureStopModify);

		VectorStructR3 BaseVecor1 = { 1.0,1.0,0.0 };
		VectorStructR3 BaseVecor2 = { 1.0,-1.0,0.0 };

		VectorStructR3 Vector1ToCalcDir = 0.5 * semiHeightFirstSurface * Math::DoCrossProduct(BaseVecor1, directionFirstSurface);
		VectorStructR3 Vector2ToCalcDir = 0.5 * semiHeightFirstSurface * Math::DoCrossProduct(BaseVecor2, directionFirstSurface);
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
		LightRayStruct lightRayStart1(light, startRay1, 1.0);;
		LightRayStruct lightRayStart2(light, startRay2, 1.0);;
		LightRayStruct lightRayStart3(light, startRay3, 1.0);;
		LightRayStruct lightRayStart4(light, startRay4, 1.0);;
		

		// trace all rays until all of them comes to the last surface
		lightRayAndInterPointAperStop bestLightRayAndInterPoint = getBestLightRayAndInterPoint_inf(lightRayStart0, lightRayStart1, lightRayStart2, lightRayStart3, lightRayStart4, targetPoint);

		LightRayStruct bestLightRay = bestLightRayAndInterPoint.getLightRay();
		VectorStructR3 interPointBestLightRay = bestLightRayAndInterPoint.getInterPointAperStop();

		real disXtoTarget = calcDistance_X(targetPoint, interPointBestLightRay);
		real disYtoTarget = calcDistance_Y(targetPoint, interPointBestLightRay);
		
		int maxInteration = mDefaultParaRayAiming.getMaxInterationRayAiming();

		unsigned int curInteration = 0;
		lightRay_intP_dis_negPos_factor infosToReduce(bestLightRay, interPointBestLightRay, disXtoTarget, disYtoTarget, stay, mDefaultParaRayAiming.getFactor(), mDefaultParaRayAiming.getFactor(), targetPoint, curInteration);
		
		infosToReduce = reduceDistancesIn_X_AND_X_ing(infosToReduce);

		curInteration = infosToReduce.getInterations();
		if (curInteration >= maxInteration)
		{
			// here we can start robust ray aiming!
			if (mDefaultParaRayAiming.getRobustRayAiming())
			{
				std::cout << "start robust ray aiming" << std::endl;
			}


			std::cout << "attention!!! ray aiming did not work perfectly!!!" << std::endl;
			std::cout << "maybe it would help to turn in robust ray aiming!!!" << std::endl;
			std::cout << "fix that bug!!!" << std::endl;
		}
		

		lightRayi = infosToReduce.getLightRay();
	}

	return lightRayi;
}

//_______________________________________________________
//_______________________________________________________







// calculate Ray that goes throw a target point (in the apertur stop)
LightRayStruct RayAiming::calcRayThrowPointInApertureStop(VectorStructR3 startPointRay, VectorStructR3 targetPoint, Light_LLT light, double curRefracIndex)
{
	double tolerance = 0.0000001;
	LightRayStruct newRay0;

	if (mPosApertureStopModify == 1)
	{
		VectorStructR3 rayDirection = Math::unitVector(targetPoint - startPointRay);
		Ray_LLT startRayInfinity(startPointRay, rayDirection, curRefracIndex);
		newRay0.setRay_LLT(startRayInfinity);
		newRay0.setLight_LLT(light);

		return newRay0;
	}
	else
	{
		// build first ray for ray aiming
		VectorStructR3 pointFirstSurface = mSeqTracModified_LLT.getPointSurface_i(0);
		VectorStructR3 directionFirstSurface = mSeqTracModified_LLT.getDirectionSurface_i(0);
		double semiHeightFirstSurface = mSeqTracModified_LLT.getSemiHeightOfSurface_i(0);
		//double semiHeightApertureStop = mSeqTracModified.getSemiHeightOfSurface_i(mPosApertureStopModify);

		VectorStructR3 BaseVecor1 = { 1.0,1.0,0.0 };
		VectorStructR3 BaseVecor2 = { 1.0,-1.0,0.0 };

		VectorStructR3 Vector1ToCalcDir = 0.5 * semiHeightFirstSurface * Math::DoCrossProduct(BaseVecor1, directionFirstSurface);
		VectorStructR3 Vector2ToCalcDir = 0.5 * semiHeightFirstSurface * Math::DoCrossProduct(BaseVecor2, directionFirstSurface);
		VectorStructR3 directionStartRay0 = pointFirstSurface + Vector1ToCalcDir - startPointRay;
		VectorStructR3 directionStartRay1 = pointFirstSurface - Vector1ToCalcDir - startPointRay;
		VectorStructR3 directionStartRay2 = pointFirstSurface + Vector2ToCalcDir - startPointRay;
		VectorStructR3 directionStartRay3 = pointFirstSurface - Vector2ToCalcDir - startPointRay;
		VectorStructR3 directionStartRay4 = pointFirstSurface - startPointRay;

		Ray_LLT startRay0(startPointRay, directionStartRay0, curRefracIndex);
		Ray_LLT startRay1(startPointRay, directionStartRay1, curRefracIndex);
		Ray_LLT startRay2(startPointRay, directionStartRay2, curRefracIndex);
		Ray_LLT startRay3(startPointRay, directionStartRay3, curRefracIndex);
		Ray_LLT startRay4(startPointRay, directionStartRay4, curRefracIndex);

		LightRayStruct lightRayStart0;
		LightRayStruct lightRayStart1;
		LightRayStruct lightRayStart2;
		LightRayStruct lightRayStart3;
		LightRayStruct lightRayStart4;

		lightRayStart0.setRay_LLT(startRay0);
		lightRayStart0.setLight_LLT(light);
		lightRayStart1.setRay_LLT(startRay1);
		lightRayStart1.setLight_LLT(light);
		lightRayStart2.setRay_LLT(startRay2);
		lightRayStart2.setLight_LLT(light);
		lightRayStart3.setRay_LLT(startRay3);
		lightRayStart3.setLight_LLT(light);
		lightRayStart4.setRay_LLT(startRay4);
		lightRayStart4.setLight_LLT(light);


		// trace with start ray to apertur stop
		std::vector<LightRayStruct> lightRayToTrace;
		std::vector<VectorStructR3> interPointFirstRay;
		// choose best intersection point
		std::vector<real> dis;

		VectorStructR3 intersecPointFirstRay0_S1;
		VectorStructR3 intersecPointFirstRay1_S1;
		VectorStructR3 intersecPointFirstRay2_S1;
		VectorStructR3 intersecPointFirstRay3_S1;
		VectorStructR3 intersecPointFirstRay4_S1;
		int rayCounter = 0;

		// Checkt, ob der Strahl alle Elemente durchläuft
		if (checkRayAllElements(lightRayStart0))
		{
			mSeqTracModified_LLT.sequentialRayTracing(lightRayStart0);
			lightRayToTrace.push_back(lightRayStart0);
			intersecPointFirstRay0_S1 = mSeqTracModified_LLT.getInterPoint_i_atSurface_i_notFiltered(rayCounter, mPosApertureStopModify);
			rayCounter++;
			interPointFirstRay.push_back(intersecPointFirstRay0_S1);
			double dis0 = Math::distanceTwoVectors(targetPoint, intersecPointFirstRay0_S1);
			dis.push_back(dis0);
		}
		if (checkRayAllElements(lightRayStart1))
		{
			mSeqTracModified_LLT.sequentialRayTracing(lightRayStart1);
			lightRayToTrace.push_back(lightRayStart1);
			intersecPointFirstRay1_S1 = mSeqTracModified_LLT.getInterPoint_i_atSurface_i_notFiltered(rayCounter, mPosApertureStopModify);
			rayCounter++;
			interPointFirstRay.push_back(intersecPointFirstRay1_S1);
			double dis1 = Math::distanceTwoVectors(targetPoint, intersecPointFirstRay1_S1);
			dis.push_back(dis1);
		}
		if (checkRayAllElements(lightRayStart2))
		{
			mSeqTracModified_LLT.sequentialRayTracing(lightRayStart2);
			lightRayToTrace.push_back(lightRayStart2);
			intersecPointFirstRay2_S1 = mSeqTracModified_LLT.getInterPoint_i_atSurface_i_notFiltered(rayCounter, mPosApertureStopModify);
			rayCounter++;
			interPointFirstRay.push_back(intersecPointFirstRay2_S1);
			double dis2 = Math::distanceTwoVectors(targetPoint, intersecPointFirstRay2_S1);
			dis.push_back(dis2);
		}
		if (checkRayAllElements(lightRayStart3))
		{
			mSeqTracModified_LLT.sequentialRayTracing(lightRayStart3);
			lightRayToTrace.push_back(lightRayStart3);
			intersecPointFirstRay3_S1 = mSeqTracModified_LLT.getInterPoint_i_atSurface_i_notFiltered(rayCounter, mPosApertureStopModify);
			rayCounter++;
			interPointFirstRay.push_back(intersecPointFirstRay3_S1);
			double dis3 = Math::distanceTwoVectors(targetPoint, intersecPointFirstRay3_S1);
			dis.push_back(dis3);
		}
		if (checkRayAllElements(lightRayStart4))
		{
			mSeqTracModified_LLT.sequentialRayTracing(lightRayStart4);
			lightRayToTrace.push_back(lightRayStart4);
			intersecPointFirstRay4_S1 = mSeqTracModified_LLT.getInterPoint_i_atSurface_i_notFiltered(rayCounter, mPosApertureStopModify);
			rayCounter++;
			interPointFirstRay.push_back(intersecPointFirstRay4_S1);
			double dis4 = Math::distanceTwoVectors(targetPoint, intersecPointFirstRay4_S1);
			dis.push_back(dis4);
		}

		VectorStructR3 bestInterPoint;
		VectorStructR3 pointAtFirstSurface;

		if (dis.size() == 0)
		{
			VectorStructR3 foundNewPoint = newStartRay(startPointRay, targetPoint, curRefracIndex, light, semiHeightFirstSurface, pointFirstSurface, directionFirstSurface, 2);

			Ray_LLT startRayNew(startPointRay, foundNewPoint - startPointRay, curRefracIndex);
			LightRayStruct lightRayStartNew;
			lightRayStartNew.setRay_LLT(startRayNew);
			lightRayStart0.setLight_LLT(light);
			SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
			traceDominik.sequentialRayTracing(lightRayStartNew);
			bestInterPoint = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
			pointAtFirstSurface = traceDominik.getAllInterInfosOfSurf_i(0).at(0).getIntersectionPoint();
		}
		else
		{
			// ValueInVectorNearZeroPosSide geändert.
			VectorElementAndPosition minDisAndPos = Math::ValueInVectorNearZeroPosSide(dis);
			bestInterPoint = interPointFirstRay.at(minDisAndPos.getPosInVector());
			// distance S1 and target point
			VectorStructR3 VecS1T = bestInterPoint - mSeqTracModified_LLT.getPointSurface_i(mPosApertureStopModify);
			// distance point apertur stop and target point
			VectorStructR3 VecSPT = targetPoint - mSeqTracModified_LLT.getPointSurface_i(mPosApertureStopModify);
			pointAtFirstSurface = mSeqTracModified_LLT.getInterPoint_i_atSurface_i_notFiltered(minDisAndPos.getPosInVector(), 0);
		}

		double disXtoTarget = targetPoint.getX() - bestInterPoint.getX();
		double disYtoTarget = targetPoint.getY() - bestInterPoint.getY();

		// Punkt auf der ersten Fläche
		startRay0.setDirectionRay(pointAtFirstSurface - startPointRay);
		startRay0.setDirectionRayUnit(pointAtFirstSurface - startPointRay);

		unsigned int interation = 0;
		unsigned int interation2 = 0;
		unsigned int maxInteration = 30;
		unsigned int maxInteration2 = 15;
		VectorStructR3 newDirectionVec = pointAtFirstSurface;
		VectorStructR3 newDirectionVecS;
		double newDirectionX = pointAtFirstSurface.getX();
		double newDirectionY = pointAtFirstSurface.getY();
		double disXtoTargetS = disXtoTarget;
		double disYtoTargetS = disYtoTarget;
		VectorStructR3 interPointAperture = bestInterPoint;
		VectorStructR3 interPointApertureS = bestInterPoint;
		Ray_LLT startRayObjectNew(startPointRay, newDirectionVec - startPointRay, curRefracIndex);
		newRay0.setLight_LLT(light);
		newRay0.setRay_LLT(startRayObjectNew);
		double factor = 0.08; // size of the steps, Faktor

		while (((std::abs(disYtoTarget) > tolerance || std::abs(disXtoTarget) > tolerance)) && (interation < maxInteration))
		{
			if (std::abs(disYtoTarget) > tolerance)
			{
				if (interPointAperture.getY() < targetPoint.getY()) //Falls switchY true, dann handelt es sich vermutlich um ein negatives Linsensystem (bis zur Aperturblende)
				{
					disXtoTargetS = disXtoTarget;
					disYtoTargetS = disYtoTarget;
					interPointApertureS = interPointAperture;
					newDirectionVecS = newDirectionVec;
					newDirectionY = newDirectionVec.getY() + semiHeightFirstSurface * factor;
					newDirectionX = newDirectionVec.getX();
					newDirectionVec = { newDirectionX , newDirectionY , newDirectionVec.getZ() };

					Ray_LLT startRayInfinityNew(startPointRay, newDirectionVec - startPointRay, curRefracIndex);
					newRay0.setRay_LLT(startRayInfinityNew);

					if (checkRayAllElements(newRay0))
					{
						SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
						traceDominik.sequentialRayTracing(newRay0);
						interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
						disXtoTarget = targetPoint.getX() - interPointAperture.getX();
						disYtoTarget = targetPoint.getY() - interPointAperture.getY();
					}
					else
					{
						newDirectionVec = newDirectionVecS;
					}

					if (std::abs(disYtoTarget) < std::abs(disYtoTargetS))
					{
						while ((interPointAperture.getY() < targetPoint.getY()) && (interation2 <= maxInteration2) && (std::abs(disYtoTarget) <= std::abs(disYtoTargetS)) && (std::abs(disYtoTarget) > tolerance))
						{
							disXtoTargetS = disXtoTarget;
							disYtoTargetS = disYtoTarget;
							interPointApertureS = interPointAperture;
							newDirectionVecS = newDirectionVec;
							newDirectionY = newDirectionVec.getY() + semiHeightFirstSurface * factor;
							newDirectionX = newDirectionVec.getX();
							newDirectionVec = { newDirectionX , newDirectionY , newDirectionVec.getZ() };

							Ray_LLT startRayInfinityNew(startPointRay, newDirectionVec - startPointRay, curRefracIndex);
							newRay0.setRay_LLT(startRayInfinityNew);

							if (checkRayAllElements(newRay0))
							{
								SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
								traceDominik.sequentialRayTracing(newRay0);
								interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
								disXtoTarget = targetPoint.getX() - interPointAperture.getX();
								disYtoTarget = targetPoint.getY() - interPointAperture.getY();
							}

							if (std::abs(disYtoTarget) >= std::abs(disYtoTargetS))
							{
								newDirectionVec = newDirectionVecS;
								disXtoTarget = disXtoTargetS;
								disYtoTarget = disYtoTargetS;
								interPointAperture = interPointApertureS;
								interation2 = maxInteration2;
							}
							interation2++;
						}
					}
					else
					{
						newDirectionY = newDirectionVec.getY() - semiHeightFirstSurface * factor * 2;
						newDirectionX = newDirectionVec.getX();
						newDirectionVec = { newDirectionX , newDirectionY , newDirectionVec.getZ() };

						Ray_LLT startRayInfinityNew(startPointRay, newDirectionVec - startPointRay, curRefracIndex);
						newRay0.setRay_LLT(startRayInfinityNew);

						if (checkRayAllElements(newRay0))
						{
							SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
							traceDominik.sequentialRayTracing(newRay0);
							interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
							disXtoTarget = targetPoint.getX() - interPointAperture.getX();
							disYtoTarget = targetPoint.getY() - interPointAperture.getY();
						}
						else
						{
							newDirectionVec = newDirectionVecS;
						}

						if (std::abs(disYtoTarget) < std::abs(disYtoTargetS))
						{
							while ((interPointAperture.getY() < targetPoint.getY()) && (interation2 <= maxInteration2) && (std::abs(disYtoTarget) <= std::abs(disYtoTargetS)) && (std::abs(disYtoTarget) > tolerance))
							{
								disXtoTargetS = disXtoTarget;
								disYtoTargetS = disYtoTarget;
								interPointApertureS = interPointAperture;
								newDirectionVecS = newDirectionVec;
								newDirectionY = newDirectionVec.getY() - semiHeightFirstSurface * factor;
								newDirectionX = newDirectionVec.getX();
								newDirectionVec = { newDirectionX , newDirectionY , newDirectionVec.getZ() };

								Ray_LLT startRayInfinityNew(startPointRay, newDirectionVec - startPointRay, curRefracIndex);
								newRay0.setRay_LLT(startRayInfinityNew);

								if (checkRayAllElements(newRay0))
								{
									SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
									traceDominik.sequentialRayTracing(newRay0);
									interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
									disXtoTarget = targetPoint.getX() - interPointAperture.getX();
									disYtoTarget = targetPoint.getY() - interPointAperture.getY();
								}

								if (std::abs(disYtoTarget) >= std::abs(disYtoTargetS))
								{
									newDirectionVec = newDirectionVecS;
									disXtoTarget = disXtoTargetS;
									disYtoTarget = disYtoTargetS;
									interPointAperture = interPointApertureS;
									interation2 = maxInteration2;
								}
								interation2++;
							}
						}
						else
						{
							newDirectionVec = newDirectionVecS;
							disXtoTarget = disXtoTargetS;
							disYtoTarget = disYtoTargetS;
							interPointAperture = interPointApertureS;
							interation2 = maxInteration2;
						}
					}
				}

				else		// (interPointAperture.getY() > targetPoint.getY())
				{
					disXtoTargetS = disXtoTarget;
					disYtoTargetS = disYtoTarget;
					interPointApertureS = interPointAperture;
					newDirectionVecS = newDirectionVec;
					newDirectionY = newDirectionVec.getY() - semiHeightFirstSurface * factor;
					newDirectionX = newDirectionVec.getX();
					newDirectionVec = { newDirectionX , newDirectionY , newDirectionVec.getZ() };

					Ray_LLT startRayInfinityNew(startPointRay, newDirectionVec - startPointRay, curRefracIndex);
					newRay0.setRay_LLT(startRayInfinityNew);

					if (checkRayAllElements(newRay0))
					{
						SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
						traceDominik.sequentialRayTracing(newRay0);
						interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
						disXtoTarget = targetPoint.getX() - interPointAperture.getX();
						disYtoTarget = targetPoint.getY() - interPointAperture.getY();
					}
					else
					{
						newDirectionVec = newDirectionVecS;
					}

					if (std::abs(disYtoTarget) < std::abs(disYtoTargetS))
					{
						while ((interPointAperture.getY() > targetPoint.getY()) && (interation2 <= maxInteration2) && (std::abs(disYtoTarget) <= std::abs(disYtoTargetS)) && (std::abs(disYtoTarget) > tolerance))
						{
							disXtoTargetS = disXtoTarget;
							disYtoTargetS = disYtoTarget;
							interPointApertureS = interPointAperture;
							newDirectionVecS = newDirectionVec;
							newDirectionY = newDirectionVec.getY() - semiHeightFirstSurface * factor;
							newDirectionX = newDirectionVec.getX();
							newDirectionVec = { newDirectionX , newDirectionY , newDirectionVec.getZ() };

							Ray_LLT startRayInfinityNew(startPointRay, newDirectionVec - startPointRay, curRefracIndex);
							newRay0.setRay_LLT(startRayInfinityNew);

							if (checkRayAllElements(newRay0))
							{
								SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
								traceDominik.sequentialRayTracing(newRay0);
								interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
								disXtoTarget = targetPoint.getX() - interPointAperture.getX();
								disYtoTarget = targetPoint.getY() - interPointAperture.getY();
							}

							if (std::abs(disYtoTarget) >= std::abs(disYtoTargetS))
							{
								newDirectionVec = newDirectionVecS;
								disXtoTarget = disXtoTargetS;
								disYtoTarget = disYtoTargetS;
								interPointAperture = interPointApertureS;
								interation2 = maxInteration2;
							}
							interation2++;
						}
					}
					else
					{
						newDirectionY = newDirectionVec.getY() + semiHeightFirstSurface * factor * 2;
						newDirectionX = newDirectionVec.getX();
						newDirectionVec = { newDirectionX , newDirectionY , newDirectionVec.getZ() };

						Ray_LLT startRayInfinityNew(startPointRay, newDirectionVec - startPointRay, curRefracIndex);
						newRay0.setRay_LLT(startRayInfinityNew);

						if (checkRayAllElements(newRay0))
						{
							SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
							traceDominik.sequentialRayTracing(newRay0);
							interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
							disXtoTarget = targetPoint.getX() - interPointAperture.getX();
							disYtoTarget = targetPoint.getY() - interPointAperture.getY();
						}
						else
						{
							newDirectionVec = newDirectionVecS;
						}

						if (std::abs(disYtoTarget) < std::abs(disYtoTargetS))
						{
							while ((interPointAperture.getY() > targetPoint.getY()) && (interation2 <= maxInteration2) && (std::abs(disYtoTarget) <= std::abs(disYtoTargetS)) && (std::abs(disYtoTarget) > tolerance))
							{
								disXtoTargetS = disXtoTarget;
								disYtoTargetS = disYtoTarget;
								interPointApertureS = interPointAperture;
								newDirectionVecS = newDirectionVec;
								newDirectionY = newDirectionVec.getY() + semiHeightFirstSurface * factor;
								newDirectionX = newDirectionVec.getX();
								newDirectionVec = { newDirectionX , newDirectionY , newDirectionVec.getZ() };

								Ray_LLT startRayInfinityNew(startPointRay, newDirectionVec - startPointRay, curRefracIndex);
								newRay0.setRay_LLT(startRayInfinityNew);

								if (checkRayAllElements(newRay0))
								{
									SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
									traceDominik.sequentialRayTracing(newRay0);
									interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
									disXtoTarget = targetPoint.getX() - interPointAperture.getX();
									disYtoTarget = targetPoint.getY() - interPointAperture.getY();
								}

								if (std::abs(disYtoTarget) >= std::abs(disYtoTargetS))
								{
									newDirectionVec = newDirectionVecS;
									disXtoTarget = disXtoTargetS;
									disYtoTarget = disYtoTargetS;
									interPointAperture = interPointApertureS;
									interation2 = maxInteration2;
								}
								interation2++;
							}
						}
						else
						{
							newDirectionVec = newDirectionVecS;
							disXtoTarget = disXtoTargetS;
							disYtoTarget = disYtoTargetS;
							interPointAperture = interPointApertureS;
							interation2 = maxInteration2;
						}
					}
				}
			}

			interation2 = 0;

			if (std::abs(disXtoTarget) > tolerance)
			{
				if (interPointAperture.getX() < targetPoint.getX())
				{
					disXtoTargetS = disXtoTarget;
					disYtoTargetS = disYtoTarget;
					interPointApertureS = interPointAperture;
					newDirectionVecS = newDirectionVec;
					newDirectionX = newDirectionVec.getX() + semiHeightFirstSurface * factor;
					newDirectionY = newDirectionVec.getY();
					newDirectionVec = { newDirectionX , newDirectionY , newDirectionVec.getZ() };

					Ray_LLT startRayInfinityNew(startPointRay, newDirectionVec - startPointRay, curRefracIndex);
					newRay0.setRay_LLT(startRayInfinityNew);

					if (checkRayAllElements(newRay0))
					{
						SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
						traceDominik.sequentialRayTracing(newRay0);
						interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
						disXtoTarget = targetPoint.getX() - interPointAperture.getX();
						disYtoTarget = targetPoint.getY() - interPointAperture.getY();
					}
					else
					{
						newDirectionVec = newDirectionVecS;
					}

					if (std::abs(disXtoTarget) < std::abs(disXtoTargetS))
					{
						while ((interPointAperture.getX() < targetPoint.getX()) && (interation2 <= maxInteration2) && (std::abs(disXtoTarget) <= std::abs(disXtoTargetS)) && (std::abs(disXtoTarget) > tolerance))
						{
							disXtoTargetS = disXtoTarget;
							disYtoTargetS = disYtoTarget;
							interPointApertureS = interPointAperture;
							newDirectionVecS = newDirectionVec;
							newDirectionX = newDirectionVec.getX() + semiHeightFirstSurface * factor;
							newDirectionY = newDirectionVec.getY();
							newDirectionVec = { newDirectionX , newDirectionY , newDirectionVec.getZ() };

							Ray_LLT startRayInfinityNew(startPointRay, newDirectionVec - startPointRay, curRefracIndex);
							newRay0.setRay_LLT(startRayInfinityNew);

							if (checkRayAllElements(newRay0))
							{
								SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
								traceDominik.sequentialRayTracing(newRay0);
								interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
								disXtoTarget = targetPoint.getX() - interPointAperture.getX();
								disYtoTarget = targetPoint.getY() - interPointAperture.getY();
							}

							if (std::abs(disXtoTarget) >= std::abs(disXtoTargetS))
							{
								newDirectionVec = newDirectionVecS;
								disXtoTarget = disXtoTargetS;
								disYtoTarget = disYtoTargetS;
								interPointAperture = interPointApertureS;
								interation2 = maxInteration2;
							}
							interation2++;
						}
					}
					else // (interPointAperture.getY() >= targetPoint.getY())
					{
						newDirectionX = newDirectionVec.getX() - semiHeightFirstSurface * factor * 2;
						newDirectionY = newDirectionVec.getY();
						newDirectionVec = { newDirectionX , newDirectionY , newDirectionVec.getZ() };

						Ray_LLT startRayInfinityNew(startPointRay, newDirectionVec - startPointRay, curRefracIndex);
						newRay0.setRay_LLT(startRayInfinityNew);

						if (checkRayAllElements(newRay0))
						{
							SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
							traceDominik.sequentialRayTracing(newRay0);
							interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
							disXtoTarget = targetPoint.getX() - interPointAperture.getX();
							disYtoTarget = targetPoint.getY() - interPointAperture.getY();
						}
						else
						{
							newDirectionVec = newDirectionVecS;
						}

						if (std::abs(disXtoTarget) < std::abs(disXtoTargetS))
						{
							while ((interPointAperture.getX() < targetPoint.getX()) && (interation2 <= maxInteration2) && (std::abs(disXtoTarget) <= std::abs(disXtoTargetS)) && (std::abs(disXtoTarget) > tolerance))
							{
								disXtoTargetS = disXtoTarget;
								disYtoTargetS = disYtoTarget;
								interPointApertureS = interPointAperture;
								newDirectionVecS = newDirectionVec;
								newDirectionX = newDirectionVec.getX() - semiHeightFirstSurface * factor;
								newDirectionY = newDirectionVec.getY();
								newDirectionVec = { newDirectionX , newDirectionY , newDirectionVec.getZ() };

								Ray_LLT startRayInfinityNew(startPointRay, newDirectionVec - startPointRay, curRefracIndex);
								newRay0.setRay_LLT(startRayInfinityNew);

								if (checkRayAllElements(newRay0))
								{
									SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
									traceDominik.sequentialRayTracing(newRay0);
									interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
									disXtoTarget = targetPoint.getX() - interPointAperture.getX();
									disYtoTarget = targetPoint.getY() - interPointAperture.getY();
								}

								if (std::abs(disXtoTarget) >= std::abs(disXtoTargetS))
								{
									newDirectionVec = newDirectionVecS;
									disXtoTarget = disXtoTargetS;
									disYtoTarget = disYtoTargetS;
									interPointAperture = interPointApertureS;
									interation2 = maxInteration2;
								}
								interation2++;
							}
						}
						else
						{
							newDirectionVec = newDirectionVecS;
							disXtoTarget = disXtoTargetS;
							disYtoTarget = disYtoTargetS;
							interPointAperture = interPointApertureS;
							interation2 = maxInteration2;
						}
					}
				}

				else // (interPointAperture.getX() > targetPoint.getX())
				{
					disXtoTargetS = disXtoTarget;
					disYtoTargetS = disYtoTarget;
					interPointApertureS = interPointAperture;
					newDirectionVecS = newDirectionVec;
					newDirectionX = newDirectionVec.getX() - semiHeightFirstSurface * factor;
					newDirectionY = newDirectionVec.getY();
					newDirectionVec = { newDirectionX , newDirectionY , newDirectionVec.getZ() };

					Ray_LLT startRayInfinityNew(startPointRay, newDirectionVec - startPointRay, curRefracIndex);
					newRay0.setRay_LLT(startRayInfinityNew);

					if (checkRayAllElements(newRay0))
					{
						SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
						traceDominik.sequentialRayTracing(newRay0);
						interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
						disXtoTarget = targetPoint.getX() - interPointAperture.getX();
						disYtoTarget = targetPoint.getY() - interPointAperture.getY();
					}
					else
					{
						newDirectionVec = newDirectionVecS;
					}

					if (std::abs(disXtoTarget) < std::abs(disXtoTargetS))
					{
						while ((interPointAperture.getX() > targetPoint.getX()) && (interation2 <= maxInteration2) && (std::abs(disXtoTarget) <= std::abs(disXtoTargetS)) && (std::abs(disXtoTarget) > tolerance))
						{
							disXtoTargetS = disXtoTarget;
							disYtoTargetS = disYtoTarget;
							interPointApertureS = interPointAperture;
							newDirectionVecS = newDirectionVec;
							newDirectionX = newDirectionVec.getX() - semiHeightFirstSurface * factor;
							newDirectionY = newDirectionVec.getY();
							newDirectionVec = { newDirectionX , newDirectionY , newDirectionVec.getZ() };

							Ray_LLT startRayInfinityNew(startPointRay, newDirectionVec - startPointRay, curRefracIndex);
							newRay0.setRay_LLT(startRayInfinityNew);

							if (checkRayAllElements(newRay0))
							{
								SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
								traceDominik.sequentialRayTracing(newRay0);
								interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
								disXtoTarget = targetPoint.getX() - interPointAperture.getX();
								disYtoTarget = targetPoint.getY() - interPointAperture.getY();
							}

							if (std::abs(disXtoTarget) >= std::abs(disXtoTargetS))
							{
								newDirectionVec = newDirectionVecS;
								disXtoTarget = disXtoTargetS;
								disYtoTarget = disYtoTargetS;
								interPointAperture = interPointApertureS;
								interation2 = maxInteration2;
							}
							interation2++;
						}
					}
					else
					{
						newDirectionX = newDirectionVec.getX() + semiHeightFirstSurface * factor * 2;
						newDirectionY = newDirectionVec.getY();
						newDirectionVec = { newDirectionX , newDirectionY , newDirectionVec.getZ() };

						Ray_LLT startRayInfinityNew(startPointRay, newDirectionVec - startPointRay, curRefracIndex);
						newRay0.setRay_LLT(startRayInfinityNew);

						if (checkRayAllElements(newRay0))
						{
							SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
							traceDominik.sequentialRayTracing(newRay0);
							interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
							disXtoTarget = targetPoint.getX() - interPointAperture.getX();
							disYtoTarget = targetPoint.getY() - interPointAperture.getY();
						}
						else
						{
							newDirectionVec = newDirectionVecS;
						}

						if (std::abs(disXtoTarget) <= std::abs(disXtoTargetS))
						{
							while ((interPointAperture.getX() > targetPoint.getX()) && (interation2 <= maxInteration2) && (std::abs(disXtoTarget) <= std::abs(disXtoTargetS)) && (std::abs(disXtoTarget) > tolerance))
							{
								disXtoTargetS = disXtoTarget;
								disYtoTargetS = disYtoTarget;
								interPointApertureS = interPointAperture;
								newDirectionVecS = newDirectionVec;
								newDirectionX = newDirectionVec.getX() + semiHeightFirstSurface * factor;
								newDirectionY = newDirectionVec.getY();
								newDirectionVec = { newDirectionX , newDirectionY , newDirectionVec.getZ() };

								Ray_LLT startRayInfinityNew(startPointRay, newDirectionVec - startPointRay, curRefracIndex);
								newRay0.setRay_LLT(startRayInfinityNew);

								if (checkRayAllElements(newRay0))
								{
									SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
									traceDominik.sequentialRayTracing(newRay0);
									interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
									disXtoTarget = targetPoint.getX() - interPointAperture.getX();
									disYtoTarget = targetPoint.getY() - interPointAperture.getY();
								}

								if (std::abs(disXtoTarget) >= std::abs(disXtoTargetS))
								{
									newDirectionVec = newDirectionVecS;
									disXtoTarget = disXtoTargetS;
									disYtoTarget = disYtoTargetS;
									interPointAperture = interPointApertureS;
									interation2 = maxInteration2;
								}
								interation2++;
							}
						}
						else
						{
							newDirectionVec = newDirectionVecS;
							disXtoTarget = disXtoTargetS;
							disYtoTarget = disYtoTargetS;
							interPointAperture = interPointApertureS;
							interation2 = maxInteration2;
						}
					}
				}
			}
			// new Ray
			Ray_LLT startRayInfinityNew(startPointRay, newDirectionVec - startPointRay, curRefracIndex);
			newRay0.setRay_LLT(startRayInfinityNew);
			SequentialRayTracing newTrace(mOpticalSystemModified_LLT);
			newTrace.sequentialRayTracing(newRay0);

			interPointAperture = newTrace.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
			disXtoTarget = targetPoint.getX() - interPointAperture.getX();
			disYtoTarget = targetPoint.getY() - interPointAperture.getY();

			semiHeightFirstSurface = semiHeightFirstSurface / 10;

			interation++;
			interation2 = 0;
		}
		return newRay0;
	}
}











// Ray-Aiming in X- an Y-direction
VectorStructR3 RayAiming::minDistanceIn_XY_Direction(
	VectorStructR3 targetPoint, /* Targetpoint */
	real wavelength,
	VectorStructR3 pointAtFirstSurface, /* Point at first surface */
	double semiHeightFirstSurface, /* Radius der ersten Fläche */
	VectorStructR3 startPoint, /* Ausgangspunkt des Strahls */
	double tolerance,
	Light_LLT light,
	double curRefracIndex)
{
	int counter = 0; // am Ende löschen
	VectorStructR3 pointAperture = mSeqTracModified_LLT.getPointSurface_i(mPosApertureStopModify);

	// Definitionen
	VectorStructR3 newDirection = pointAtFirstSurface;
	int interation = 0;
	int newInteration = 0;
	int maxInteration = 40;
	double saveXvalue = 0.0;
	double saveYvalue = 0.0;
	double startXvalue = pointAtFirstSurface.getX();
	double startYvalue = pointAtFirstSurface.getY();
	double traceNextX = pointAtFirstSurface.getX();
	double traceNextY = pointAtFirstSurface.getY();
	VectorStructR3 newFirstPoint = pointAtFirstSurface;

	// Neuer Strahl
	Ray_LLT startRay1 = newRayHelper(startPoint, pointAtFirstSurface, wavelength, curRefracIndex);
	LightRayStruct lightRayStart;
	lightRayStart.setRay_LLT(startRay1);
	lightRayStart.setLight_LLT(light);

	std::vector<LightRayStruct> lightRayToTrace;
	mSeqTracModified_LLT.sequentialRayTracing(lightRayStart);
	lightRayToTrace.push_back(lightRayStart);

	// Ray Tracing des neuen Strahles
	SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
	traceDominik.sequentialRayTracing(lightRayStart);
	counter++;

	// Schnittpunkt mit der Ebene der Aperturblende
	VectorStructR3 interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
	VectorStructR3 interPointApertureS = interPointAperture;

	// Abstand Schnittpunkt zu Target
	double disXtoTarget = targetPoint.getX() - interPointAperture.getX();
	double disYtoTarget = targetPoint.getY() - interPointAperture.getY();
	double disXtoTargetS = targetPoint.getX() - interPointAperture.getX();
	double disYtoTargetS = targetPoint.getY() - interPointAperture.getY();

	while ((std::abs(disYtoTarget) > tolerance || std::abs(disXtoTarget) > tolerance) && (interation < maxInteration))
	{
		if (std::abs(disYtoTarget) > tolerance)
		{
			if (interPointAperture.getY() < targetPoint.getY())
			{
				traceNextY = startYvalue + (std::abs(std::abs(startYvalue) - std::abs(saveYvalue)) / 2);
				newDirection = { newFirstPoint.getX(), traceNextY, newFirstPoint.getZ() };
				lightRayStart.setRay_LLT(newRayHelper(startPoint, newDirection, 550.0, 1.0));
				counter++; // Löschen
				SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
				traceDominik.sequentialRayTracing(lightRayStart);
				interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
				disXtoTarget = targetPoint.getX() - interPointAperture.getX();
				disYtoTarget = targetPoint.getY() - interPointAperture.getY();

				if (!checkRayAllElements(lightRayStart))
				{
					for (unsigned int i = 4; !checkRayAllElements(lightRayStart) && i < 20; i + 2)
					{
						traceNextY = startYvalue + (std::abs((std::abs(startYvalue) - std::abs(saveYvalue))) / i);
						newDirection = { newFirstPoint.getX(), traceNextY, newFirstPoint.getZ() };
						lightRayStart.setRay_LLT(newRayHelper(startPoint, newDirection, 550.0, 1.0));
						counter++; // Löschen
						SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
						traceDominik.sequentialRayTracing(lightRayStart);
						interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
						disXtoTarget = targetPoint.getX() - interPointAperture.getX();
						disYtoTarget = targetPoint.getY() - interPointAperture.getY();
					}
				}

				if (std::abs(disYtoTarget) > std::abs(disYtoTargetS))
				{
					traceNextY = startYvalue - (std::abs((std::abs(startYvalue) - std::abs(saveYvalue))) / 2);
					newDirection = { newFirstPoint.getX(), traceNextY, newFirstPoint.getZ() };
					lightRayStart.setRay_LLT(newRayHelper(startPoint, newDirection, 550.0, 1.0));
					counter++; // Löschen
					SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
					traceDominik.sequentialRayTracing(lightRayStart);
					interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
					disXtoTarget = targetPoint.getX() - interPointAperture.getX();
					disYtoTarget = targetPoint.getY() - interPointAperture.getY();

					if (!checkRayAllElements(lightRayStart))
					{
						for (unsigned int i = 4; !checkRayAllElements(lightRayStart) && i < 20; i + 2)
						{
							traceNextY = startYvalue - (std::abs((std::abs(startYvalue) - std::abs(saveYvalue))) / i);
							newDirection = { newFirstPoint.getX(), traceNextY, newFirstPoint.getZ() };
							lightRayStart.setRay_LLT(newRayHelper(startPoint, newDirection, 550.0, 1.0));
							counter++; // Löschen
							SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
							traceDominik.sequentialRayTracing(lightRayStart);
							interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
							disXtoTarget = targetPoint.getX() - interPointAperture.getX();
							disYtoTarget = targetPoint.getY() - interPointAperture.getY();
						}
					}
				}

				if ((std::abs(disYtoTarget) > std::abs(disYtoTargetS)) || !checkRayAllElements(lightRayStart))
				{
					newDirection = newFirstPoint;
					if (newFirstPoint.getY() < pointAperture.getY())
					{
						traceNextY = newDirection.getY();
					}
					else
					{

					}
				}
				interPointApertureS = interPointAperture;
			}

			else
			{
				traceNextY = startYvalue - (std::abs((std::abs(startYvalue) - std::abs(saveYvalue))) / 2);
				newDirection = { newFirstPoint.getX(), traceNextY, newFirstPoint.getZ() };
				lightRayStart.setRay_LLT(newRayHelper(startPoint, newDirection, 550.0, 1.0));
				counter++; // Löschen
				SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
				traceDominik.sequentialRayTracing(lightRayStart);
				interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
				disYtoTarget = targetPoint.getY() - interPointAperture.getY();

				for (unsigned int i = 4; !checkRayAllElements(lightRayStart) && i < 20; i + 2)
				{
					traceNextY = startYvalue - (std::abs((std::abs(startYvalue) - std::abs(saveYvalue))) / i);
					newDirection = { newFirstPoint.getX(), traceNextY, newFirstPoint.getZ() };
					lightRayStart.setRay_LLT(newRayHelper(startPoint, newDirection, 550.0, 1.0));
					counter++; // Löschen
					SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
					traceDominik.sequentialRayTracing(lightRayStart);
					interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
					disYtoTarget = targetPoint.getY() - interPointAperture.getY();
				}

				if (interPointApertureS.getY() < interPointAperture.getY())
				{
					traceNextY = startYvalue + (std::abs((std::abs(startYvalue) - std::abs(saveYvalue))) / 2);
					newDirection = { newFirstPoint.getX(), traceNextY, newFirstPoint.getZ() };
					lightRayStart.setRay_LLT(newRayHelper(startPoint, newDirection, 550.0, 1.0));
					counter++; // Löschen
					SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
					traceDominik.sequentialRayTracing(lightRayStart);
					interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
					disYtoTarget = targetPoint.getY() - interPointAperture.getY();
				}
				// Falls sich Y aufgrund eines Fehlers nicht dem Target annähert
				if (interation >= 38 && (std::abs(disXtoTarget) <= tolerance) && (std::abs(disYtoTarget) > tolerance) && newInteration <= 2)
				{
					newDirection = newRaysForRayAiming(lightRayStart, semiHeightFirstSurface, targetPoint, newDirection, curRefracIndex, false, true);
					traceNextY = newDirection.getY();
					startXvalue = newDirection.getX();
					startYvalue = 0.0;
					lightRayStart.setRay_LLT(newRayHelper(startPoint, newDirection, 550.0, 1.0));
					counter++; // Löschen
					SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
					traceDominik.sequentialRayTracing(lightRayStart);
					interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
					disXtoTarget = targetPoint.getX() - interPointAperture.getX();
					disYtoTarget = targetPoint.getY() - interPointAperture.getY();
					newInteration++;
					interation = 0;
				}
				interPointApertureS = interPointAperture;
			}
		}

		if (std::abs(disXtoTarget) > tolerance)
		{
			if (interPointAperture.getX() < targetPoint.getX())
			{
				traceNextX = startXvalue + (std::abs((std::abs(startXvalue) - std::abs(saveXvalue))) / 2);
				newDirection = { traceNextX, traceNextY, newFirstPoint.getZ() };
				lightRayStart.setRay_LLT(newRayHelper(startPoint, newDirection, 550.0, 1.0));
				counter++; // Löschen
				SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
				traceDominik.sequentialRayTracing(lightRayStart);
				interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
				disXtoTarget = targetPoint.getX() - interPointAperture.getX();

				for (unsigned int i = 4; !checkRayAllElements(lightRayStart) && i < 20; i + 2)
				{
					traceNextX = startXvalue + (std::abs((std::abs(startXvalue) - std::abs(saveXvalue))) / i);
					newDirection = { traceNextX, traceNextY, newFirstPoint.getZ() };
					lightRayStart.setRay_LLT(newRayHelper(startPoint, newDirection, 550.0, 1.0));
					counter++; // Löschen
					SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
					traceDominik.sequentialRayTracing(lightRayStart);
					interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
					disXtoTarget = targetPoint.getX() - interPointAperture.getX();
				}

				if (interPointApertureS.getX() > interPointAperture.getX())
				{
					traceNextX = startXvalue - (std::abs((std::abs(startXvalue) - std::abs(saveXvalue))) / 2);
					newDirection = { newFirstPoint.getX(), traceNextY, newFirstPoint.getZ() };
					lightRayStart.setRay_LLT(newRayHelper(startPoint, newDirection, 550.0, 1.0));
					counter++; // Löschen
					SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
					traceDominik.sequentialRayTracing(lightRayStart);
					interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
					disXtoTarget = targetPoint.getX() - interPointAperture.getX();
				}
				// Falls sich X aufgrund eines Fehlers nicht dem Target annähert
				if (interation >= 38 && (std::abs(disXtoTarget) > tolerance) && (std::abs(disYtoTarget) <= tolerance) && newInteration <= 2)
				{
					newDirection = newRaysForRayAiming(lightRayStart, semiHeightFirstSurface, targetPoint, newDirection, curRefracIndex, true, false);
					traceNextX = newDirection.getX();
					startXvalue = 0.0;
					startYvalue = newDirection.getX();
					lightRayStart.setRay_LLT(newRayHelper(startPoint, newDirection, 550.0, 1.0));
					counter++; // Löschen
					SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
					traceDominik.sequentialRayTracing(lightRayStart);
					interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
					disXtoTarget = targetPoint.getX() - interPointAperture.getX();
					disYtoTarget = targetPoint.getY() - interPointAperture.getY();
					newInteration++;
					interation = 0;
				}
				interPointApertureS = interPointAperture;
			}

			else
			{
				traceNextX = startXvalue - (std::abs((std::abs(startXvalue) - std::abs(saveXvalue))) / 2);
				newDirection = { traceNextX, traceNextY, newFirstPoint.getZ() };
				lightRayStart.setRay_LLT(newRayHelper(startPoint, newDirection, 550.0, 1.0));
				counter++; // Löschen
				SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
				traceDominik.sequentialRayTracing(lightRayStart);
				interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
				disXtoTarget = targetPoint.getX() - interPointAperture.getX();

				for (unsigned int i = 4; !checkRayAllElements(lightRayStart) && i < 20; i + 2)
				{
					traceNextX = startXvalue - (std::abs((std::abs(startXvalue) - std::abs(saveXvalue))) / i);
					newDirection = { traceNextX, traceNextY, newFirstPoint.getZ() };
					lightRayStart.setRay_LLT(newRayHelper(startPoint, newDirection, 550.0, 1.0));
					counter++; // Löschen
					SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
					traceDominik.sequentialRayTracing(lightRayStart);
					interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
					disXtoTarget = targetPoint.getX() - interPointAperture.getX();
				}

				if (interPointApertureS.getX() < interPointAperture.getX())
				{
					traceNextX = startXvalue + (std::abs((std::abs(startXvalue) - std::abs(saveXvalue))) / 2);
					newDirection = { newFirstPoint.getX(), traceNextY, newFirstPoint.getZ() };
					lightRayStart.setRay_LLT(newRayHelper(startPoint, newDirection, 550.0, 1.0));
					counter++; // Löschen
					SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
					traceDominik.sequentialRayTracing(lightRayStart);
					interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
					disXtoTarget = targetPoint.getX() - interPointAperture.getX();
				}
				// Falls sich X aufgrund eines Fehlers nicht dem Target annähert
				if (interation >= 38 && (std::abs(disXtoTarget) > tolerance) && (std::abs(disYtoTarget) <= tolerance) && newInteration <= 2)
				{
					newDirection = newRaysForRayAiming(lightRayStart, semiHeightFirstSurface, targetPoint, newDirection, curRefracIndex, true, false);
					startXvalue = 0.0;
					startYvalue = newDirection.getX();
					lightRayStart.setRay_LLT(newRayHelper(startPoint, newDirection, 550.0, 1.0));
					counter++; // Löschen
					SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
					traceDominik.sequentialRayTracing(lightRayStart);
					interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
					disXtoTarget = targetPoint.getX() - interPointAperture.getX();
					disYtoTarget = targetPoint.getY() - interPointAperture.getY();
					newInteration++;
					interation = 0;
				}
				interPointApertureS = interPointAperture;
			}
		}
		newFirstPoint = newDirection;
		saveXvalue = startXvalue;
		saveYvalue = startYvalue;
		startXvalue = traceNextX;
		startYvalue = traceNextY;

		interation++;
	}

	std::cout << "Anzahl an Ray-Aiming Durchläufen (Objekt-Strahl): " << counter << "\n"; // am Ende löschen
	return newFirstPoint;
}



// Troubleshooting: Falls sich in der minDistance in XY-MEthode ein Fehler ergibt
// Berechnet wird eine Linie entlang der passenden höhe X oder Y. Daran werden 10 neue Strahlen simuliert und der dem Target nächste wird weiterverfolgt.
VectorStructR3 RayAiming::newRaysForRayAiming(LightRayStruct lightRayStart, double semiHeightFirstSurface, VectorStructR3 targetPoint, VectorStructR3 pointAtFirstSurface, double curRefracIndex, bool X_ForT, bool Y_ForT) // X/Y false or true
{
	VectorStructR3 directionStartRay1;
	VectorStructR3 directionStartRay2;
	VectorStructR3 directionStartRay3;
	VectorStructR3 directionStartRay4;
	VectorStructR3 directionStartRay5;
	VectorStructR3 directionStartRay6;
	VectorStructR3 directionStartRay7;
	VectorStructR3 directionStartRay8;

	// Für Winkelberechnung:
	double alpha;

	// Falls der X-Wert korigiert werden muss:
	if (X_ForT)
	{
		// X-Range berechnen (Kreisbogen)
		alpha = asin(pointAtFirstSurface.getY() / semiHeightFirstSurface);
		double xMax = semiHeightFirstSurface * cos(alpha);

		directionStartRay1 = { -xMax / 5,pointAtFirstSurface.getY(),pointAtFirstSurface.getZ() };
		directionStartRay2 = { -xMax / 4,pointAtFirstSurface.getY(),pointAtFirstSurface.getZ() };
		directionStartRay3 = { -xMax / 3,pointAtFirstSurface.getY(),pointAtFirstSurface.getZ() };
		directionStartRay4 = { -xMax / 2,pointAtFirstSurface.getY(),pointAtFirstSurface.getZ() };
		directionStartRay5 = { xMax / 2,pointAtFirstSurface.getY(),pointAtFirstSurface.getZ() };
		directionStartRay6 = { xMax / 3,pointAtFirstSurface.getY(),pointAtFirstSurface.getZ() };
		directionStartRay7 = { xMax / 4,pointAtFirstSurface.getY(),pointAtFirstSurface.getZ() };
		directionStartRay8 = { xMax / 5,pointAtFirstSurface.getY(),pointAtFirstSurface.getZ() };
	}
	else
	{
		// Y-Range berechnen (Kreisbogen)
		alpha = asin(pointAtFirstSurface.getX() / semiHeightFirstSurface);
		double YMax = semiHeightFirstSurface * cos(alpha);

		directionStartRay1 = { pointAtFirstSurface.getX(),-YMax / 5,pointAtFirstSurface.getZ() };
		directionStartRay2 = { pointAtFirstSurface.getX(),-YMax / 4,pointAtFirstSurface.getZ() };
		directionStartRay3 = { pointAtFirstSurface.getX(),-YMax / 3,pointAtFirstSurface.getZ() };
		directionStartRay4 = { pointAtFirstSurface.getX(),-YMax / 2,pointAtFirstSurface.getZ() };
		directionStartRay5 = { pointAtFirstSurface.getX(),YMax / 2,pointAtFirstSurface.getZ() };
		directionStartRay6 = { pointAtFirstSurface.getX(),YMax / 3,pointAtFirstSurface.getZ() };
		directionStartRay7 = { pointAtFirstSurface.getX(),YMax / 4,pointAtFirstSurface.getZ() };
		directionStartRay8 = { pointAtFirstSurface.getX(),YMax / 5,pointAtFirstSurface.getZ() };
	}

	Ray_LLT startRay1 = lightRayStart.getRay_LLT();

	LightRayStruct lightRayStart1 = lightRayStart;
	startRay1.setDirectionRayUnit(directionStartRay1);
	lightRayStart1.setRay_LLT(startRay1);

	LightRayStruct lightRayStart2 = lightRayStart;
	startRay1.setDirectionRayUnit(directionStartRay2);
	lightRayStart2.setRay_LLT(startRay1);

	LightRayStruct lightRayStart3 = lightRayStart;
	startRay1.setDirectionRayUnit(directionStartRay3);
	lightRayStart3.setRay_LLT(startRay1);

	LightRayStruct lightRayStart4 = lightRayStart;
	startRay1.setDirectionRayUnit(directionStartRay4);
	lightRayStart4.setRay_LLT(startRay1);

	LightRayStruct lightRayStart5 = lightRayStart;
	startRay1.setDirectionRayUnit(directionStartRay5);
	lightRayStart5.setRay_LLT(startRay1);

	LightRayStruct lightRayStart6 = lightRayStart;
	startRay1.setDirectionRayUnit(directionStartRay6);
	lightRayStart6.setRay_LLT(startRay1);

	LightRayStruct lightRayStart7 = lightRayStart;
	startRay1.setDirectionRayUnit(directionStartRay7);
	lightRayStart7.setRay_LLT(startRay1);

	LightRayStruct lightRayStart8 = lightRayStart;
	startRay1.setDirectionRayUnit(directionStartRay8);
	lightRayStart8.setRay_LLT(startRay1);

	mSeqTracModified_LLT.clearAllTracedRays();

	// trace with start ray to apertur stop
	std::vector<LightRayStruct> lightRayToTrace;
	mSeqTracModified_LLT.sequentialRayTracing(lightRayStart1);
	lightRayToTrace.push_back(lightRayStart1);
	mSeqTracModified_LLT.sequentialRayTracing(lightRayStart2);
	lightRayToTrace.push_back(lightRayStart2);
	mSeqTracModified_LLT.sequentialRayTracing(lightRayStart3);
	lightRayToTrace.push_back(lightRayStart3);
	mSeqTracModified_LLT.sequentialRayTracing(lightRayStart4);
	lightRayToTrace.push_back(lightRayStart4);
	mSeqTracModified_LLT.sequentialRayTracing(lightRayStart5);
	lightRayToTrace.push_back(lightRayStart5);
	mSeqTracModified_LLT.sequentialRayTracing(lightRayStart6);
	lightRayToTrace.push_back(lightRayStart6);
	mSeqTracModified_LLT.sequentialRayTracing(lightRayStart7);
	lightRayToTrace.push_back(lightRayStart7);
	mSeqTracModified_LLT.sequentialRayTracing(lightRayStart8);
	lightRayToTrace.push_back(lightRayStart8);

	// TODO Question: Was soll gemacht werden, wenn die Strahlen nicht die Apertrublende treffen???

	std::vector<VectorStructR3> interPointFirstRay;
	VectorStructR3 intersecPointFirstRay0_S1 = mSeqTracModified_LLT.getInterPoint_i_atSurface_i_notFiltered(0, mPosApertureStopModify);
	interPointFirstRay.push_back(intersecPointFirstRay0_S1);
	VectorStructR3 intersecPointFirstRay1_S1 = mSeqTracModified_LLT.getInterPoint_i_atSurface_i_notFiltered(1, mPosApertureStopModify);
	interPointFirstRay.push_back(intersecPointFirstRay1_S1);
	VectorStructR3 intersecPointFirstRay2_S1 = mSeqTracModified_LLT.getInterPoint_i_atSurface_i_notFiltered(2, mPosApertureStopModify);
	interPointFirstRay.push_back(intersecPointFirstRay2_S1);
	VectorStructR3 intersecPointFirstRay3_S1 = mSeqTracModified_LLT.getInterPoint_i_atSurface_i_notFiltered(3, mPosApertureStopModify);
	interPointFirstRay.push_back(intersecPointFirstRay3_S1);
	VectorStructR3 intersecPointFirstRay4_S1 = mSeqTracModified_LLT.getInterPoint_i_atSurface_i_notFiltered(4, mPosApertureStopModify);
	interPointFirstRay.push_back(intersecPointFirstRay4_S1);
	VectorStructR3 intersecPointFirstRay5_S1 = mSeqTracModified_LLT.getInterPoint_i_atSurface_i_notFiltered(5, mPosApertureStopModify);
	interPointFirstRay.push_back(intersecPointFirstRay5_S1);
	VectorStructR3 intersecPointFirstRay6_S1 = mSeqTracModified_LLT.getInterPoint_i_atSurface_i_notFiltered(6, mPosApertureStopModify);
	interPointFirstRay.push_back(intersecPointFirstRay6_S1);
	VectorStructR3 intersecPointFirstRay7_S1 = mSeqTracModified_LLT.getInterPoint_i_atSurface_i_notFiltered(7, mPosApertureStopModify);
	interPointFirstRay.push_back(intersecPointFirstRay7_S1);


	// choose best intersection point
	std::vector<real> dis;
	double dis0 = Math::distanceTwoVectors(targetPoint, intersecPointFirstRay0_S1);
	dis.push_back(dis0);
	double dis1 = Math::distanceTwoVectors(targetPoint, intersecPointFirstRay1_S1);
	dis.push_back(dis1);
	double dis2 = Math::distanceTwoVectors(targetPoint, intersecPointFirstRay2_S1);
	dis.push_back(dis2);
	double dis3 = Math::distanceTwoVectors(targetPoint, intersecPointFirstRay3_S1);
	dis.push_back(dis3);
	double dis4 = Math::distanceTwoVectors(targetPoint, intersecPointFirstRay4_S1);
	dis.push_back(dis4);
	double dis5 = Math::distanceTwoVectors(targetPoint, intersecPointFirstRay5_S1);
	dis.push_back(dis5);
	double dis6 = Math::distanceTwoVectors(targetPoint, intersecPointFirstRay6_S1);
	dis.push_back(dis6);
	double dis7 = Math::distanceTwoVectors(targetPoint, intersecPointFirstRay7_S1);
	dis.push_back(dis7);

	// ValueInVectorNearZeroPosSide geändert.
	VectorElementAndPosition minDisAndPos = Math::ValueInVectorNearZeroPosSide(dis);
	VectorStructR3 bestInterPoint = interPointFirstRay.at(minDisAndPos.getPosInVector());

	// just look at the y value of S1 and target point
	double disX_S1toTarget = targetPoint.getX() - bestInterPoint.getX();
	double disY_S1toTarget = targetPoint.getY() - bestInterPoint.getY();

	return bestInterPoint;
}


VectorStructR3 RayAiming::newStartRay(VectorStructR3 startPointRay, VectorStructR3 targetPoint, double curRefracIndex, Light_LLT light, double SemiHeightFirstSurface, VectorStructR3 pointFirstSurface, VectorStructR3 directionFirstSurface, int interation0)
{
	VectorStructR3 pointReturn;
	// Neu: /Dominik
	VectorStructR3 BaseVecor1 = { 1.0,0.0,0.0 };
	VectorStructR3 BaseVecor2 = { 0.0,1.0,0.0 };

	VectorStructR3 Vector1ToCalcDir = 0.5 * SemiHeightFirstSurface * Math::DoCrossProduct(BaseVecor1, directionFirstSurface) / interation0;
	VectorStructR3 Vector2ToCalcDir = 0.5 * SemiHeightFirstSurface * Math::DoCrossProduct(BaseVecor2, directionFirstSurface) / interation0;
	VectorStructR3 directionStartRay1 = pointFirstSurface + Vector1ToCalcDir - startPointRay;
	VectorStructR3 directionStartRay2 = pointFirstSurface - Vector1ToCalcDir - startPointRay;
	VectorStructR3 directionStartRay3 = pointFirstSurface + Vector2ToCalcDir - startPointRay;
	VectorStructR3 directionStartRay4 = pointFirstSurface - Vector2ToCalcDir - startPointRay;

	Ray_LLT startRay0(startPointRay, directionStartRay1, curRefracIndex);
	Ray_LLT startRay1(startPointRay, directionStartRay2, curRefracIndex);
	Ray_LLT startRay2(startPointRay, directionStartRay3, curRefracIndex);
	Ray_LLT startRay3(startPointRay, directionStartRay4, curRefracIndex);

	LightRayStruct lightRayStart0;
	LightRayStruct lightRayStart1;
	LightRayStruct lightRayStart2;
	LightRayStruct lightRayStart3;
	lightRayStart0.setRay_LLT(startRay0);
	lightRayStart0.setLight_LLT(light);
	lightRayStart1.setRay_LLT(startRay1);
	lightRayStart1.setLight_LLT(light);
	lightRayStart2.setRay_LLT(startRay2);
	lightRayStart2.setLight_LLT(light);
	lightRayStart3.setRay_LLT(startRay3);
	lightRayStart3.setLight_LLT(light);

	mSeqTracModified_LLT.clearAllTracedRays();

	// trace with start ray to apertur stop
	std::vector<LightRayStruct> lightRayToTrace;
	std::vector<VectorStructR3> interPointFirstRay;
	// choose best intersection point
	std::vector<real> dis;

	VectorStructR3 intersecPointFirstRay0_S1;
	VectorStructR3 intersecPointFirstRay1_S1;
	VectorStructR3 intersecPointFirstRay2_S1;
	VectorStructR3 intersecPointFirstRay3_S1;
	VectorStructR3 intersecPointFirstRay4_S1;
	int rayCounter = 0;

	// Checkt, ob der Strahl alle Elemente durchläuft
	if (checkRayAllElements(lightRayStart0))
	{
		mSeqTracModified_LLT.sequentialRayTracing(lightRayStart0);
		lightRayToTrace.push_back(lightRayStart0);
		intersecPointFirstRay0_S1 = mSeqTracModified_LLT.getInterPoint_i_atSurface_i_notFiltered(rayCounter, mPosApertureStopModify);
		rayCounter++;
		interPointFirstRay.push_back(intersecPointFirstRay0_S1);
		double dis0 = Math::distanceTwoVectors(targetPoint, intersecPointFirstRay0_S1);
		dis.push_back(dis0);
	}
	if (checkRayAllElements(lightRayStart1))
	{
		mSeqTracModified_LLT.sequentialRayTracing(lightRayStart1);
		lightRayToTrace.push_back(lightRayStart1);
		intersecPointFirstRay1_S1 = mSeqTracModified_LLT.getInterPoint_i_atSurface_i_notFiltered(rayCounter, mPosApertureStopModify);
		rayCounter++;
		interPointFirstRay.push_back(intersecPointFirstRay1_S1);
		double dis1 = Math::distanceTwoVectors(targetPoint, intersecPointFirstRay1_S1);
		dis.push_back(dis1);
	}
	if (checkRayAllElements(lightRayStart2))
	{
		mSeqTracModified_LLT.sequentialRayTracing(lightRayStart2);
		lightRayToTrace.push_back(lightRayStart2);
		intersecPointFirstRay2_S1 = mSeqTracModified_LLT.getInterPoint_i_atSurface_i_notFiltered(rayCounter, mPosApertureStopModify);
		rayCounter++;
		interPointFirstRay.push_back(intersecPointFirstRay2_S1);
		double dis2 = Math::distanceTwoVectors(targetPoint, intersecPointFirstRay2_S1);
		dis.push_back(dis2);
	}
	if (checkRayAllElements(lightRayStart3))
	{
		mSeqTracModified_LLT.sequentialRayTracing(lightRayStart3);
		lightRayToTrace.push_back(lightRayStart3);
		intersecPointFirstRay3_S1 = mSeqTracModified_LLT.getInterPoint_i_atSurface_i_notFiltered(rayCounter, mPosApertureStopModify);
		rayCounter++;
		interPointFirstRay.push_back(intersecPointFirstRay3_S1);
		double dis3 = Math::distanceTwoVectors(targetPoint, intersecPointFirstRay3_S1);
		dis.push_back(dis3);
	}

	if (dis.size() > 0)
	{
		// ValueInVectorNearZeroPosSide geändert.
		VectorElementAndPosition minDisAndPos = Math::ValueInVectorNearZeroPosSide(dis);	//Todo: hier kann eine neue Funktion geschrieben werden, da alle "dis" positiv sind
																							// dann spart man sich eine if abfrage.
		VectorStructR3 bestInterPoint = interPointFirstRay.at(minDisAndPos.getPosInVector());

		// distance S1 and target point
		VectorStructR3 VecS1T = bestInterPoint - mSeqTracModified_LLT.getPointSurface_i(mPosApertureStopModify);
		// distance point apertur stop and target point
		VectorStructR3 VecSPT = targetPoint - mSeqTracModified_LLT.getPointSurface_i(mPosApertureStopModify);
		// just look at the y value of S1 and target point
		double disX_S1toTarget = targetPoint.getX() - bestInterPoint.getX();
		double disY_S1toTarget = targetPoint.getY() - bestInterPoint.getY();
		VectorStructR3 pointAtFirstSurface = mSeqTracModified_LLT.getInterPoint_i_atSurface_i_notFiltered(minDisAndPos.getPosInVector(), 0);
		pointReturn = pointAtFirstSurface;
	}
	else
	{
		if (interation0 < 15)
		{
			pointReturn = newStartRay(startPointRay, targetPoint, curRefracIndex, light, SemiHeightFirstSurface, pointFirstSurface, directionFirstSurface, ++interation0);
		}
	}

	return pointReturn;
}

// helper builts new ray
Ray_LLT RayAiming::newRayHelper(VectorStructR3 startPoint, VectorStructR3 direction, real wavelength, double refIndex)
{

	//Neuer Strahl
	Ray_LLT startRay0({ startPoint.getX(), startPoint.getY(), startPoint.getZ() }, { direction.getX() - startPoint.getX(),
			direction.getY() - startPoint.getY(), direction.getZ() - startPoint.getZ() }, 1.0);
	Light_LLT light;
	light.setWavelength(wavelength);

	LightRayStruct lightRayStart0;
	lightRayStart0.setRay_LLT(startRay0);
	lightRayStart0.setLight_LLT(light);
	return startRay0;
}

// calculate point plan surface before first surface with negativ radius
VectorStructR3 RayAiming::shiftFirstSurface(double& radius, double& semiHeight, VectorStructR3& apexOfSphere)
{
	double val = radius - std::sqrt(std::pow(radius, 2) - std::pow(semiHeight, 2));
	VectorStructR3 returnApex = { apexOfSphere.getX(), apexOfSphere.getY(), apexOfSphere.getZ() - val /*to stop errors acording to rounding mistakes*/ - mDefaultParaRayAiming.getStartPointFactor() };
	return returnApex;
}


// Überprüft ob Strahl auf das erste Element trifft. Falls nicht -> true
//bool RayAiming::checkRayFirstElement(VectorStructR3 checkRay, double SemiHeightFirstSurface)
//{
//	bool check1 = (checkRay.getX()*checkRay.getX()) + (checkRay.getY() * checkRay.getY()) > (SemiHeightFirstSurface*SemiHeightFirstSurface);
//	// if X^2 * Y^2 < SH^2 -> true
//	if (check1)
//		return true;
//	else
//		return false;
//}

// Traced einen Strahl und überprüft ob ein Strahl nicht durch alle Elemente getraced werden kann. Falls nicht -> false
bool RayAiming::checkRayAllElements(LightRayStruct lightRay)
{
	SequentialRayTracing TraceCheckRayAllElements(mOpticalSystemModified_LLT);
	TraceCheckRayAllElements.sequentialRayTracing(lightRay);
	char interSide{};

	interSide = TraceCheckRayAllElements.getAllInterInfosOfSurf_i_notFiltered(mOpticalSystemModified_LLT.getPosAndInteractingSurface().size() - 1).at(0).getSurfaceSide();

	if (interSide == 'N')
	{
		//		std::cout << "There is no intersection point with the aperture stop! " << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}

// reduce distance X from light ray
lightRayAndInterPointAperStop RayAiming::reduceDistanceFormLightRay_X_inf(LightRayStruct startLightRay, VectorStructR3 interPointAperStop, VectorStructR3 targetPoint, real initialDistance)
{
	lightRayAndInterPointAperStop returnLightRayAndInterPoint;

	real semiHeightFirstSurface = mOpticalSystem_LLT.getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getSemiHeight();

	LightRayStruct lightRayToTracePos = startLightRay;
	LightRayStruct lightRayToTraceNeg = startLightRay;
	real toleranceX = mDefaultParaRayAiming.getTolerance_XandY();

	VectorStructR3 originPlus = startLightRay.getRay_LLT().getOriginRay();
	VectorStructR3 originNeg = startLightRay.getRay_LLT().getOriginRay();

	real disPosTrace;
	real disNegTrace;

	while (std::abs(initialDistance) > mDefaultParaRayAiming.getTolerance_XandY())
	{
		real factorAdaptable = mDefaultParaRayAiming.getFactor();

		real initialOrigin_X = startLightRay.getRay_LLT().getOriginRay().getX();
		real originPlus_X = initialOrigin_X + semiHeightFirstSurface * factorAdaptable;
		real originMinus_X = initialOrigin_X - semiHeightFirstSurface * factorAdaptable;

		originPlus.setX(originPlus_X);
		originNeg.setX(originMinus_X);

		lightRayToTracePos.getRay_LLT().setOriginRay(originPlus);
		lightRayToTraceNeg.getRay_LLT().setOriginRay(originNeg);

		// pos trace
		SequentialRayTracing tracePLus(mOpticalSystem_LLT);
		tracePLus.sequentialRayTracing(lightRayToTracePos);

		// neg trace
		SequentialRayTracing traceNeg(mOpticalSystem_LLT);
		traceNeg.sequentialRayTracing(lightRayToTraceNeg);

		disPosTrace = Math::distanceTwoVectors(tracePLus.getAllInterPointsAtSurf_i(mPosApertureStop)[0] ,targetPoint);
		disNegTrace = Math::distanceTwoVectors(traceNeg.getAllInterPointsAtSurf_i(mPosApertureStop)[0], targetPoint);

		if (disPosTrace < disNegTrace) // we have to walk in the positiv direction
		{
			if (disPosTrace < initialDistance)
			{
				// check if we have to trace neg or pos
			}

			else if (initialDistance < disPosTrace)
			{
				// check if we have to trace neg or pos
			}
		}
		else if (disNegTrace < disPosTrace) // we have to walk in the negativ direction
		{
			if (disNegTrace < initialDistance)
			{
				// check if we have to trace neg or pos
			}

			else if (initialDistance < disNegTrace)
			{
				// check if we have to trace neg or pos
			}
		}

	}


	//while ((interPointAperStop.getX() < targetPoint.getX()) && (interation2 <= maxInteration2) && (std::abs(disXtoTarget) <= std::abs(disXtoTargetS)) && (std::abs(disXtoTarget) > mDefaultParaRayAiming.getTolerance()))
//	{
//			disXtoTargetS = disXtoTarget;
//			disYtoTargetS = disYtoTarget;
//			interPointApertureS = interPointAperture;
//			newStartPointS = newStartPoint;
//			newStartX = newStartPoint.getX() + semiHeightFirstSurface * factor;
//			newStartY = newStartPoint.getY();
//			newStartPoint = { newStartX, newStartY, startPoint.getZ() };
//
//			Ray_LLT startRayInfinityNew(newStartPoint, rayDirection, curRefracIndex);
//			lightRayi.setRay_LLT(startRayInfinityNew);
//
//			if (checkRayAllElements(lightRayi))
//			{
//				SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
//				traceDominik.sequentialRayTracing(lightRayi);
//				interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
//				disXtoTarget = targetPoint.getX() - interPointAperture.getX();
//				disYtoTarget = targetPoint.getY() - interPointAperture.getY();
//			}
//
//			if (std::abs(disXtoTarget) >= std::abs(disXtoTargetS))
//			{
//				newStartPoint = newStartPointS;
//				disXtoTarget = disXtoTargetS;
//				disYtoTarget = disYtoTargetS;
//				interPointAperture = interPointApertureS;
//				interation2 = maxInteration2;
//			}
//			interation2++;
//		}
//	}
//	else // (interPointAperture.getY() >= targetPoint.getY())
//	{
//		newStartX = newStartPoint.getX() - semiHeightFirstSurface * factor * 2;
//		newStartY = newStartPoint.getY();
//		newStartPoint = { newStartX, newStartY, startPoint.getZ() };
//
//		Ray_LLT startRayInfinityNew(newStartPoint, rayDirection, curRefracIndex);
//		lightRayi.setRay_LLT(startRayInfinityNew);
//
//		if (checkRayAllElements(lightRayi))
//		{
//			SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
//			traceDominik.sequentialRayTracing(lightRayi);
//			interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
//			disXtoTarget = targetPoint.getX() - interPointAperture.getX();
//			disYtoTarget = targetPoint.getY() - interPointAperture.getY();
//		}
//		else
//		{
//			newStartPoint = newStartPointS;
//		}
//
//		if (std::abs(disXtoTarget) < std::abs(disXtoTargetS))
//		{
//			while ((interPointAperture.getX() < targetPoint.getX()) && (interation2 <= maxInteration2) && (std::abs(disXtoTarget) <= std::abs(disXtoTargetS)) && (std::abs(disXtoTarget) > mDefaultParaRayAiming.getTolerance()))
//			{
//				disXtoTargetS = disXtoTarget;
//				disYtoTargetS = disYtoTarget;
//				interPointApertureS = interPointAperture;
//				newStartPointS = newStartPoint;
//				newStartX = newStartPoint.getX() - semiHeightFirstSurface * factor;
//				newStartY = newStartPoint.getY();
//				newStartPoint = { newStartX, newStartY, startPoint.getZ() };
//
//				Ray_LLT startRayInfinityNew(newStartPoint, rayDirection, curRefracIndex);
//				lightRayi.setRay_LLT(startRayInfinityNew);
//
//				if (checkRayAllElements(lightRayi))
//				{
//					SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
//					traceDominik.sequentialRayTracing(lightRayi);
//					interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
//					disXtoTarget = targetPoint.getX() - interPointAperture.getX();
//					disYtoTarget = targetPoint.getY() - interPointAperture.getY();
//				}
//
//				if (std::abs(disXtoTarget) >= std::abs(disXtoTargetS))
//				{
//					newStartPoint = newStartPointS;
//					disXtoTarget = disXtoTargetS;
//					disYtoTarget = disYtoTargetS;
//					interPointAperture = interPointApertureS;
//					interation2 = maxInteration2;
//				}
//				interation2++;
//			}
//		}
//		else
//		{
//			newStartPoint = newStartPointS;
//			disXtoTarget = disXtoTargetS;
//			disYtoTarget = disYtoTargetS;
//			interPointAperture = interPointApertureS;
//			interation2 = maxInteration2;
//		}
//	}
//}
//
//				else // (interPointAperture.getX() > targetPoint.getX())
//				{
//				disXtoTargetS = disXtoTarget;
//				disYtoTargetS = disYtoTarget;
//				interPointApertureS = interPointAperture;
//				newStartPointS = newStartPoint;
//				newStartX = newStartPoint.getX() - semiHeightFirstSurface * factor;
//				newStartY = newStartPoint.getY();
//				newStartPoint = { newStartX, newStartY, startPoint.getZ() };
//
//				Ray_LLT startRayInfinityNew(newStartPoint, rayDirection, curRefracIndex);
//				lightRayi.setRay_LLT(startRayInfinityNew);
//
//				if (checkRayAllElements(lightRayi))
//				{
//					SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
//					traceDominik.sequentialRayTracing(lightRayi);
//					interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
//					disXtoTarget = targetPoint.getX() - interPointAperture.getX();
//					disYtoTarget = targetPoint.getY() - interPointAperture.getY();
//				}
//				else
//				{
//					newStartPoint = newStartPointS;
//				}
//
//				if (std::abs(disXtoTarget) < std::abs(disXtoTargetS))
//				{
//					while ((interPointAperture.getX() > targetPoint.getX()) && (interation2 <= maxInteration2) && (std::abs(disXtoTarget) <= std::abs(disXtoTargetS)) && (std::abs(disXtoTarget) > mDefaultParaRayAiming.getTolerance()))
//					{
//						disXtoTargetS = disXtoTarget;
//						disYtoTargetS = disYtoTarget;
//						interPointApertureS = interPointAperture;
//						newStartPointS = newStartPoint;
//						newStartX = newStartPoint.getX() - semiHeightFirstSurface * factor;
//						newStartY = newStartPoint.getY();
//						newStartPoint = { newStartX, newStartY, startPoint.getZ() };
//
//						Ray_LLT startRayInfinityNew(newStartPoint, rayDirection, curRefracIndex);
//						lightRayi.setRay_LLT(startRayInfinityNew);
//
//						if (checkRayAllElements(lightRayi))
//						{
//							SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
//							traceDominik.sequentialRayTracing(lightRayi);
//							interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
//							disXtoTarget = targetPoint.getX() - interPointAperture.getX();
//							disYtoTarget = targetPoint.getY() - interPointAperture.getY();
//						}
//
//						if (std::abs(disXtoTarget) >= std::abs(disXtoTargetS))
//						{
//							newStartPoint = newStartPointS;
//							disXtoTarget = disXtoTargetS;
//							disYtoTarget = disYtoTargetS;
//							interPointAperture = interPointApertureS;
//							interation2 = maxInteration2;
//						}
//						interation2++;
//					}
//				}
//				else
//				{
//					newStartX = newStartPoint.getX() + semiHeightFirstSurface * factor * 2;
//					newStartY = newStartPoint.getY();
//					newStartPoint = { newStartX, newStartY, startPoint.getZ() };
//
//					Ray_LLT startRayInfinityNew(newStartPoint, rayDirection, curRefracIndex);
//					lightRayi.setRay_LLT(startRayInfinityNew);
//
//					if (checkRayAllElements(lightRayi))
//					{
//						SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
//						traceDominik.sequentialRayTracing(lightRayi);
//						interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
//						disXtoTarget = targetPoint.getX() - interPointAperture.getX();
//						disYtoTarget = targetPoint.getY() - interPointAperture.getY();
//					}
//					else
//					{
//						newStartPoint = newStartPointS;
//					}
//
//					if (std::abs(disXtoTarget) < std::abs(disXtoTargetS))
//					{
//						while ((interPointAperture.getX() > targetPoint.getX()) && (interation2 <= maxInteration2) && (std::abs(disXtoTarget) <= std::abs(disXtoTargetS)) && (std::abs(disXtoTarget) > mDefaultParaRayAiming.getTolerance()))
//						{
//							disXtoTargetS = disXtoTarget;
//							disYtoTargetS = disYtoTarget;
//							interPointApertureS = interPointAperture;
//							newStartPointS = newStartPoint;
//							newStartX = newStartPoint.getX() + semiHeightFirstSurface * factor;
//							newStartY = newStartPoint.getY();
//							newStartPoint = { newStartX, newStartY, startPoint.getZ() };
//
//							Ray_LLT startRayInfinityNew(newStartPoint, rayDirection, curRefracIndex);
//							lightRayi.setRay_LLT(startRayInfinityNew);
//
//							if (checkRayAllElements(lightRayi))
//							{
//								SequentialRayTracing traceDominik(mOpticalSystemModified_LLT);
//								traceDominik.sequentialRayTracing(lightRayi);
//								interPointAperture = traceDominik.getAllInterInfosOfSurf_i(mPosApertureStopModify).at(0).getIntersectionPoint();
//								disXtoTarget = targetPoint.getX() - interPointAperture.getX();
//								disYtoTarget = targetPoint.getY() - interPointAperture.getY();
//							}
//
//							if (std::abs(disXtoTarget) >= std::abs(disXtoTargetS))
//							{
//								newStartPoint = newStartPointS;
//								disXtoTarget = disXtoTargetS;
//								disYtoTarget = disYtoTargetS;
//								interPointAperture = interPointApertureS;
//								interation2 = maxInteration2;
//							}
//							interation2++;
//						}
//					}
//					else
//					{
//						newStartPoint = newStartPointS;
//						disXtoTarget = disXtoTargetS;
//						disYtoTarget = disYtoTargetS;
//						interPointAperture = interPointApertureS;
//						interation2 = maxInteration2;
//					}
//				}
//				}
//			}

return returnLightRayAndInterPoint;

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


// get the intersection point of an ray with the aperture stop
VectorStructR3 RayAiming::getInterPointApertureStop(LightRayStruct lightRay)
{
	unsigned int loopCounter = 0;
	VectorStructR3 interpointApertureStop{};

	SequentialRayTracing seqTrace(mOpticalSystem_LLT);
	seqTrace.sequentialRayTracing(lightRay);

	interpointApertureStop = seqTrace.getAllInterPointsAtSurf_i(mPosApertureStop)[0];
	   
	return interpointApertureStop;
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
	tracePLus.sequentialRayTracing(lightRayToTracePos);

	// neg trace
	SequentialRayTracing traceNeg(mOpticalSystem_LLT);
	traceNeg.sequentialRayTracing(lightRayToTraceNeg);

	IntersectInformationStruct interPointAS_pos = tracePLus.getAllInterInfosOfSurf_i_notFiltered(mPosApertureStop)[0];
	IntersectInformationStruct interPointAS_neg = traceNeg.getAllInterInfosOfSurf_i_notFiltered(mPosApertureStop)[0];

	// pos trace
	real disPosTrace_X = calcDistance_X(interPointAS_pos.getIntersectionPoint(), targetPoint);
	real disPosTrace_Y = calcDistance_Y(interPointAS_pos.getIntersectionPoint(), targetPoint);

	// neg trace
	real disNegTrace_X = calcDistance_X(interPointAS_neg.getIntersectionPoint(), targetPoint);
	real disNegTrace_Y = calcDistance_Y(interPointAS_neg.getIntersectionPoint(), targetPoint);

	if (disPosTrace_X < disNegTrace_X && interPointAS_pos.getSurfaceSide() != 'N')
	{
		if (disPosTrace_X < initialDistanceX )
		{
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_Y(disPosTrace_Y);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY);

			returnLightRay_intP_dis_negPos_fac.setLightRay(lightRayToTracePos);
			returnLightRay_intP_dis_negPos_fac.setInterPoint(interPointAS_pos.getIntersectionPoint());
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_X(disPosTrace_X);
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(posSide);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.9);

		}
		else if (initialDistanceX < disPosTrace_X)
		{
			returnLightRay_intP_dis_negPos_fac = initialInfos;
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(stay);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.9);
		}


		
	}

	else if (disNegTrace_X < disPosTrace_X && interPointAS_neg.getSurfaceSide() != 'N')
	{

		if (disNegTrace_X < initialDistanceX )
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
		returnLightRay_intP_dis_negPos_fac.setFactorX(initialFactorX / 1.9);
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


	if (disPosTrace_Y < disNegTrace_Y && interPointAS_pos.getSurfaceSide() != 'N')
	{
		if (disPosTrace_Y < initialDistanceY)
		{
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_X(disPosTrace_X);
			returnLightRay_intP_dis_negPos_fac.setFactorX(initalFactorX);

			returnLightRay_intP_dis_negPos_fac.setLightRay(lightRayToTracePos);
			returnLightRay_intP_dis_negPos_fac.setInterPoint(interPointAS_pos.getIntersectionPoint());
			returnLightRay_intP_dis_negPos_fac.setDistanceInterToTarger_Y(disPosTrace_Y);
			returnLightRay_intP_dis_negPos_fac.setNegOrPosSide(posSide);
			returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.9);

		}
		else if (initialDistanceY < disPosTrace_Y)
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
		returnLightRay_intP_dis_negPos_fac.setFactorY(initialFactorY / 1.9);
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
LightRayStruct RayAiming::robustRayAiming_inf(lightRay_intP_dis_negPos_factor initialInfos)
{
	real disYtoTarget = initialInfos.getDistanceInterToTarget_Y();
	real disXtoTarget = initialInfos.getDistanceInterToTarget_X();
	unsigned int interation = 0;
	real maxInteration = mDefaultParaRayAiming.getMaxInterationRayAiming();

	lightRay_intP_dis_negPos_factor interInfosRA_new = initialInfos;
	interInfosRA_new.setInterations(interation);

	while (((std::abs(disYtoTarget) > mDefaultParaRayAiming.getTolerance_XandY() || std::abs(disXtoTarget) > mDefaultParaRayAiming.getTolerance_XandY())) && (interation < maxInteration))
	{
		interInfosRA_new = calcNewBestInfos(interInfosRA_new);
		interInfosRA_new = reduceDistancesIn_X_AND_X_ing(interInfosRA_new);
	
		disYtoTarget = initialInfos.getDistanceInterToTarget_Y();
		disXtoTarget = initialInfos.getDistanceInterToTarget_X();
		interation = initialInfos.getInterations();
	}

	LightRayStruct returnLightRay = interInfosRA_new.getLightRay();

	return returnLightRay;
}

lightRay_intP_dis_negPos_factor RayAiming::calcNewBestInfos(lightRay_intP_dis_negPos_factor initialInfos)
{
	lightRay_intP_dis_negPos_factor returnInfos = initialInfos;
	real variancePercent = mDefaultParaRayAiming.getVariancePercentRRA();
	VectorStructR3 targetPoint = initialInfos.getTargetPoint();

	LightRayStruct initialLightRay = initialInfos.getLightRay();

		 

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


	// origin 0
	VectorStructR3 origin0(X_origin, Y_Plus, Z_origin);
	// origin 1
	VectorStructR3 origin1( X_origin, Y_Neg, Z_origin );
	// origin 2
	VectorStructR3 origin2( X_Neg, Y_origin, Z_origin );
	// origin 3
	VectorStructR3 origin3(X_Plus, Y_origin, Z_origin );
	// origin 4
	VectorStructR3 origin4( X_Neg, Y_Plus, Z_origin );
	// origin 5
	VectorStructR3 origin5( X_Plus, Y_Plus, Z_origin );
	// origin 6
	VectorStructR3 origin6(X_Plus, Y_Neg, Z_origin);
	// origin 7
	VectorStructR3 origin7(X_Neg, Y_Neg, Z_origin);
	
	// ray0
	Ray_LLT ray0(origin0, rayDirectionUnit, currentRefIndex);
	// ray1
	Ray_LLT ray1(origin1, rayDirectionUnit, currentRefIndex);
	// ray2
	Ray_LLT ray2(origin2, rayDirectionUnit, currentRefIndex);
	// ray3
	Ray_LLT ray3(origin3, rayDirectionUnit, currentRefIndex);
	// ray4
	Ray_LLT ray4(origin4, rayDirectionUnit, currentRefIndex);
	// ray5
	Ray_LLT ray5(origin5, rayDirectionUnit, currentRefIndex);
	// ray6
	Ray_LLT ray6(origin6, rayDirectionUnit, currentRefIndex);
	// ray7
	Ray_LLT ray7(origin7, rayDirectionUnit, currentRefIndex);


	//light ray 0
	LightRayStruct lightRay0(light, ray0, 1);
	//light ray 1
	LightRayStruct lightRay1(light, ray1, 1);
	//light ray 2
	LightRayStruct lightRay2(light, ray2, 1);
	//light ray 3
	LightRayStruct lightRay3(light, ray3, 1);
	//light ray 4
	LightRayStruct lightRay4(light, ray4, 1);
	//light ray 5
	LightRayStruct lightRay5(light, ray5, 1);
	//light ray 6
	LightRayStruct lightRay6(light, ray6, 1);
	//light ray 7
	LightRayStruct lightRay7(light, ray7, 1);

	std::vector<LightRayStruct> lightRay_vec{ lightRay0,lightRay1,lightRay2,lightRay3,lightRay4,lightRay5,lightRay6,lightRay7 };
	SequentialRayTracing seqTrace(mOpticalSystem_LLT);
	seqTrace.seqRayTracingWithVectorOfLightRays(lightRay_vec);

	unsigned int posApertureStop = mOpticalSystem_LLT.getPosApertureStop();
	std::vector<VectorStructR3> interPointsAS_vec = seqTrace.getAllInterPointsAtSurf_i(posApertureStop);

	unsigned posBestRay = getPosRayLowestDistance(interPointsAS_vec, targetPoint);
	
	// new infos 
	LightRayStruct newBestRay = lightRay_vec[posBestRay];
	VectorStructR3 newInterPointAS = seqTrace.getAllInterPointsAtSurf_i(posApertureStop)[posBestRay];
	real distance_X = calcDistance_X(newInterPointAS, targetPoint);
	real distance_Y = calcDistance_Y(newInterPointAS, targetPoint);
	// ***

	returnInfos.setLightRay(newBestRay);
	returnInfos.setInterPoint(newInterPointAS);
	returnInfos.setDistanceInterToTarger_X(distance_X);
	returnInfos.setDistanceInterToTarger_Y(distance_Y);

	return returnInfos;
}

lightRay_intP_dis_negPos_factor RayAiming::reduceDistancesIn_X_AND_X_ing(lightRay_intP_dis_negPos_factor initialInfos)
{

	real disYtoTarget = initialInfos.getDistanceInterToTarget_Y();
	real disXtoTarget = initialInfos.getDistanceInterToTarget_X();
	unsigned int interation = initialInfos.getInterations();
	real maxInteration = mDefaultParaRayAiming.getMaxInterationRayAiming();

	while (((std::abs(disYtoTarget) > mDefaultParaRayAiming.getTolerance_XandY() || std::abs(disXtoTarget) > mDefaultParaRayAiming.getTolerance_XandY())) && (interation < maxInteration))
	{
		if (disXtoTarget > disYtoTarget)
		{
			initialInfos = traceNegOrPosSide_andReduce_X_inf(initialInfos);
			disXtoTarget = initialInfos.getDistanceInterToTarget_X();
			disYtoTarget = initialInfos.getDistanceInterToTarget_Y();

			++interation;
		}
		else //(disXtoTarget < disYtoTarget)
		{
			initialInfos = traceNegOrPosSide_andReduce_Y_inf(initialInfos);
			disXtoTarget = initialInfos.getDistanceInterToTarget_X();
			disYtoTarget = initialInfos.getDistanceInterToTarget_Y();

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