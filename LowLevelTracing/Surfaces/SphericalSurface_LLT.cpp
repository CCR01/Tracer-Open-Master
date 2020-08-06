#include "SphericalSurface_LLT.h"
#include "..\Ray_LLT.h"
#include "..\Math_LLT.h"
#include <iostream>

SphericalSurfaceQwt::SphericalSurfaceQwt(double radius, double semiHeight, VectorStructR3 direction, VectorStructR3 point)
{
	//Set the curve's drawing style
	setStyle(QwtPlotCurve::Lines);

	/*QwtSplineCurveFitter* curveFitter = new QwtSplineCurveFitter();
	curveFitter->setFitMode(curveFitter->Auto);
	curveFitter->setSplineSize(1000);
	setCurveFitter(curveFitter);

	setCurveAttribute(Fitted, true);*/

	setPen(QColor(255, 0, 0), 2);


	setSamples(points(radius, semiHeight, direction, point));
}


QPolygonF SphericalSurfaceQwt::points(double radius, double semiHeight, VectorStructR3 direction, VectorStructR3 point)
{
	QPolygonF points;

	unsigned int wide = 1600;
	unsigned int height = 1000;
	// distance to left border
	unsigned int boarterLeft = 50;
	unsigned int scale = 20;



	//sampling
	const int numSamples = 10000;


	VectorStructR2 dir2D_Unit = Math::unitVec2D({ direction.getZ(), direction.getY() });
	VectorStructR2 point2D{ point.getZ(), point.getY() };
	VectorStructR2 orto2D_Unit = Math::calcOrtoVec2D_Unit({ direction.getZ(), direction.getY() });

	// center of sphere in global coordinat system of trace master
	VectorStructR2 centerSphere = point2D + radius * dir2D_Unit;

	// calculate relevant distance to plot according to semiHeight
	double dX_total = radius - (std::sqrt(std::pow(radius, 2) - std::pow(semiHeight, 2)));

	double Xmin = point2D.getX();
	double Xmax = (point2D + dir2D_Unit * dX_total).getX();

	if (Xmin == Xmax) // spherical lens is rotated about plus/minus 90?
	{
		Xmin = point2D.getY();
		Xmax = (point2D + dir2D_Unit * dX_total).getY();
	}

	// calculate staps (deltaX)
	double distanceXminXmax = std::abs(std::abs(Xmax) - std::abs(Xmin));
	double deltaX = distanceXminXmax / numSamples;


	// the first point to plot is always the apex of the sphere
	VectorStructR2 startPoint2D = point2D;

	double xPlotStartPos = boarterLeft + startPoint2D.getX() * scale;
	double yPlotStartPos = height / 2 - startPoint2D.getY() * scale;

	// the start point is in the beginning the same
	double xPlotStartNeg = xPlotStartPos;
	double yPlotStartNeg = yPlotStartPos;



	for (int i = numSamples; i > 0; i--)
	{

		double stepsX = i * deltaX + deltaX;

		double dy = std::sqrt(2 * stepsX*radius - std::pow(stepsX, 2));

		VectorStructR2 newPointNeg = point2D + dir2D_Unit * stepsX - orto2D_Unit * dy;

		double xPlotEndNeg = boarterLeft + newPointNeg.getX() * scale;

		double yPlotEndNeg = height / 2 - newPointNeg.getY() * scale;

		xPlotStartNeg = xPlotEndNeg;
		yPlotStartNeg = yPlotEndNeg;

		points << QPointF(xPlotStartNeg, yPlotStartNeg);

		points << QPointF(xPlotEndNeg, yPlotEndNeg);






	}


	for (int i = 0; i < numSamples; i++)
	{

		double stepsX = i * deltaX + deltaX;

		double dy = std::sqrt(2 * stepsX*radius - std::pow(stepsX, 2));

		VectorStructR2 newPointPos = point2D + dir2D_Unit * stepsX + orto2D_Unit * dy;



		double xPlotEndPos = boarterLeft + newPointPos.getX() * scale;

		double yPlotEndPos = height / 2 - newPointPos.getY() * scale;

		xPlotStartPos = xPlotEndPos;
		yPlotStartPos = yPlotEndPos;

		points << QPointF(xPlotStartPos, yPlotStartPos);

		points << QPointF(xPlotEndPos, yPlotEndPos);

	}




	return points;

}



//get Radius
double SphericalSurface_LLT::getRadius()
{
	return mRadius;
}

//get Height
double SphericalSurface_LLT::getSemiHeight()
{
	return mSemiHeight;
}

//set Height
void SphericalSurface_LLT::setSemiHeight(double height)
{
	mSemiHeight = height;
}

// set Point
void SphericalSurface_LLT::setPoint(VectorStructR3 Point)
{
	mPointSphere = Point;
}

// get Point 
VectorStructR3 SphericalSurface_LLT::getPoint()
{
	return mPointSphere;
}

// get Direction
VectorStructR3 SphericalSurface_LLT::getDirection()
{
	return mDirection;
}

//get Refractiv Index Left
double SphericalSurface_LLT::getRefractivIndexSide_A() const
{
	return mRefractiveIndexA;
}

//set Refractive Index Left
void SphericalSurface_LLT::setRefractiveIndexSide_A(double const refractiveIndexLeft)
{
	mRefractiveIndexA = refractiveIndexLeft;
}

//get Refractiv Index Right
double SphericalSurface_LLT::getRefractivIndexSide_B() const
{
	return mRefractiveIndexB;
}

//set Refractive Index Right
void SphericalSurface_LLT::setRefractiveIndexSide_B(double const refractiveIndexRight)
{
	mRefractiveIndexB = refractiveIndexRight;
}

// calculate center of shere after rotation	
void SphericalSurface_LLT::calcCenterSphereAfterRotation()
{
	mCenterSphereAfterRotation = mPointSphere + Math::scaleVector(std::abs(mRadius), Math::unitVector(mDirection));
}


ALL_IntersectionPointsStruct::ALL_IntersectionPointsStruct() {};
ALL_IntersectionPointsStruct::~ALL_IntersectionPointsStruct() {};
// first intersection point
VectorStructR3 ALL_IntersectionPointsStruct::getFirstIntersectionPoint()
{
	return mFirstIntersectionPoint;
}
void ALL_IntersectionPointsStruct::setFirstIntersectionPoint(VectorStructR3 firstInterPoint)
{
	mFirstIntersectionPoint = firstInterPoint;
}
// second intersection point
VectorStructR3 ALL_IntersectionPointsStruct::getSecondIntersectionPoint()
{
	return mSecondIntersectionPoint;
}
void ALL_IntersectionPointsStruct::setSecondIntersectionPoint(VectorStructR3 secondInterPoint)
{
	mSecondIntersectionPoint = secondInterPoint;
}
// steps first inter point
real ALL_IntersectionPointsStruct::getStepsFirstIP()
{
	return mStepsT_first;
}
void ALL_IntersectionPointsStruct::setStepsFirstIP(real stepsFirstIP)
{
	mStepsT_first = stepsFirstIP;
}
// steps second inter pont
real ALL_IntersectionPointsStruct::getStepsSecondIP()
{
	return mStepsT_second;
}
void ALL_IntersectionPointsStruct::setStepsSecondIP(real stepsSecondIP)
{
	mStepsT_second = stepsSecondIP;
}
// is intersection point
unsigned int ALL_IntersectionPointsStruct::getNumIntersectionPoint()
{
	return mNumberIntersectionPoint;
}
void ALL_IntersectionPointsStruct::setNumIntersectionPoint(unsigned int numIntersectionPoint)
{
	mNumberIntersectionPoint = numIntersectionPoint;
}
// setAll
void ALL_IntersectionPointsStruct::setAll(VectorStructR3 firstInterPoint, VectorStructR3 secondInterPoint, real stepFirst, real stepSecond, unsigned int numInterPoints)
{
	setFirstIntersectionPoint(firstInterPoint);
	setSecondIntersectionPoint(secondInterPoint);
	setStepsFirstIP(stepFirst);
	setStepsSecondIP(stepSecond);
	setNumIntersectionPoint(numInterPoints);
}

// get focal length
real SphericalSurface_LLT::getFocalLength()
{
	return mFocalLength;
}

// get focal length dash
real SphericalSurface_LLT::getFocalLength_dash()
{
	return mFocalLength_dash;
}







// calculate the intersection information between ray and sphere
// the ray is given from the class "SurfaceIntersection"
IntersectInformationStruct SphericalSurface_LLT::calculateIntersection(LightRayStruct const lightRay)
{
	mRay = lightRay.getRay_LLT();
	mLight = lightRay.getLight_LLT();
	ReturnIntersectInformation.setNoIntersectionPoint();

	// terms to calculate intersection point between ray and sphere
	mC_Term = mRay.getOriginRay() * mRay.getOriginRay() - 2 * (mRay.getOriginRay() * mCenterSphereAfterRotation)
		+ (mCenterSphereAfterRotation * mCenterSphereAfterRotation)	- (mRadius * mRadius);

	mB_Term = 2 * (mRay.getOriginRay() * mRay.getDirectionRayUnit()) - 2 * (mRay.getDirectionRayUnit() * mCenterSphereAfterRotation);

	mA_Term = mRay.getDirectionRayUnit() * mRay.getDirectionRayUnit();


	// there are diffente possibilities:
	// there is no intersection point
	// there is 1 intersection point
	// there are 2 intersection points

	// first we check if there is no intersection point between ray an spherical surface
	// so we calculate the term under the sqrt in the Quadratic formula

	mSqrtTermQadraticFormular = mB_Term * mB_Term - 4 * mA_Term * mC_Term;
	if (mSqrtTermQadraticFormular < 0)
	{
		return ReturnIntersectInformation;
	}

	else if (mSqrtTermQadraticFormular == 0)
	{
		//std::cout << "there is only one intersection point. \n";
		// next we have to calculate that intersection point
		// first we have to calculate the steps we have to walk on the ray
		mStepsT_first_zeroSqrtTerm = -mB_Term / (2 * mA_Term);

		if (mStepsT_first_zeroSqrtTerm < 0) // the ray would walk in the wrong direction
		{
			return ReturnIntersectInformation;
		}
		else
		{
			//calculate intersection Point (there is only ONE intersection point)
			mFirstIntersectionPoint = mRay.getOriginRay() + (mStepsT_first_zeroSqrtTerm * mRay.getDirectionRayUnit());
			mALL_IntersectionPoints.setAll(mFirstIntersectionPoint, mFirstIntersectionPoint,mStepsT_first_zeroSqrtTerm,mStepsT_first_zeroSqrtTerm, 1); // 1 -> one intersection points
		}
	}

	// calculate steps for the first intersection point
	// stepsT_first is always smaller than stepsT_second!!! 
	mStepsT_first = (-mB_Term /*for FIRST intersection point*/ - std::sqrt(mSqrtTermQadraticFormular)) / (2 * mA_Term);

	// calculate steps for the second intersection point
	mStepsT_second = (-mB_Term /*for SECOND intersection point*/ + std::sqrt(mSqrtTermQadraticFormular)) / (2 * mA_Term);

	// there must be two inersection points between ray and spherical surface

	if (mStepsT_second < 0) // ray would walk in the wrong direction 
	{
		return ReturnIntersectInformation;
	}


	else if (mStepsT_first < 0) // stepT_second is not negative -> checked before
	{
		mSecondIntersectionPoint = mRay.getOriginRay() + mStepsT_second * mRay.getDirectionRayUnit();
		mALL_IntersectionPoints.setAll(mSecondIntersectionPoint , mSecondIntersectionPoint,mStepsT_second,mStepsT_second, 1); // 1 -> one relevate intersection point
	}

	else if (std::abs(mStepsT_first - mStepsT_second) > 0.00000001 /*TODO select a tolerance*/ && mStepsT_first > 0 && mStepsT_second > 0) //stepT_first and stepT_second is positive
	{														/*we have to be clear that the intersection points are not the same!*/
		mFirstIntersectionPoint = mRay.getOriginRay() + mStepsT_first * mRay.getDirectionRayUnit();
		mSecondIntersectionPoint = mRay.getOriginRay() + mStepsT_second * mRay.getDirectionRayUnit();
		mALL_IntersectionPoints.setAll(mFirstIntersectionPoint, mSecondIntersectionPoint,mStepsT_first,mStepsT_second, 2 ); // 2 -> two intersection points
	}

	else if (std::abs(mStepsT_second - mStepsT_first) > 0.00000001 /*TODO select a tolerance*/ && mStepsT_first >= 0 && mStepsT_second > 0)
	{
		mFirstIntersectionPoint = mRay.getOriginRay() + mStepsT_first * mRay.getDirectionRayUnit();
		mSecondIntersectionPoint = mRay.getOriginRay() + mStepsT_second * mRay.getDirectionRayUnit();
		mALL_IntersectionPoints.setAll(mFirstIntersectionPoint, mSecondIntersectionPoint,mStepsT_first,mStepsT_second, 2); // 2 -> two intersection points
	}

	/*
	// Check
	std::cout << "centerSphereAfterRotation \n";
	CenterSphereAfterRotation.print();
	std::cout << "stepT first: " << stepsT_first << std::endl;
	std::cout << "stepT second: " << stepsT_second << std::endl;
	//Vector origin = mRay.getOriginRay();
	//std::cout << "origin: \n";
	//origin.print();
	//Vector direction = mRay.getDirectionRay();
	//std::cout << "direction: \n";
	//direction.print();
	std::cout << "first intersection point: \n";
	firstIntersectionPoint.print();
	//Vector FirstIntersectionPoint = returnIntersectionPoints.firstIntersectionPoint;
	//Vector SecondIntersectionPoint = returnIntersectionPoints.secondIntersectionPoint;
	//std::cout << "first intersection point: \n";
	//FirstIntersectionPoint.print();
	//std::cout << "second intersection point: \n";
	//SecondIntersectionPoint.print();
	std::cout << "second intersection point: \n";
	secondIntersectionPoint.print();
	*/

	// Next we have to check whitch intersection point is the right on!


	// there is only one intersection point
	if (mALL_IntersectionPoints.getNumIntersectionPoint() == 1) // there is only on intersection point
	{
		mShortestDistance_FIRST_IntersectionPoint = Math::lengthOfVector(Math::DoCrossProduct((mDirection), (mALL_IntersectionPoints.getFirstIntersectionPoint() - mPointSphere))) / Math::lengthOfVector(mDirection);
		if (mShortestDistance_FIRST_IntersectionPoint >= mSemiHeight)
		{
			// the intersection point is NOT in the spherical surface
			return ReturnIntersectInformation; //there is NO intersection point
		}
		else // the FIRST intersection point is in the spherical surface
		{
			mNormalOnSphereAtIntersectPointUnit = Math::unitVector(mALL_IntersectionPoints.getFirstIntersectionPoint() - mCenterSphereAfterRotation);
			if (mNormalOnSphereAtIntersectPointUnit*mRay.getDirectionRayUnit() <= 0) // surface side A
			{
				ReturnIntersectInformation.setAll(mALL_IntersectionPoints.getFirstIntersectionPoint(),mNormalOnSphereAtIntersectPointUnit,A,std::abs(mStepsT_first*mRay.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,mRay.getDirectionRayUnit(), mLight);
				return ReturnIntersectInformation;
			}

			else // surface side B 
			{
				ReturnIntersectInformation.setAll(mALL_IntersectionPoints.getFirstIntersectionPoint(), /*flip normale*/-1.0 * mNormalOnSphereAtIntersectPointUnit,B,std::abs(mStepsT_second*mRay.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,mRay.getDirectionRayUnit(), mLight);
				return ReturnIntersectInformation;
			}
		}

	}

	//distance vertex (sphere) and FIRST intersection point
	mDistancePointFirstIntersectionPoint = Math::lengthOfVector(mPointSphere - mALL_IntersectionPoints.getFirstIntersectionPoint());
	//distance point (sphere) and SECOND intersection point
	mDistancePointSecondIntersectionPoint = Math::lengthOfVector(mPointSphere - mALL_IntersectionPoints.getSecondIntersectionPoint());
	mShortestDistanceDirection_FIRST_IntersectionPoint = Math::lengthOfVector(Math::DoCrossProduct(mDirection, (mALL_IntersectionPoints.getFirstIntersectionPoint() - mPointSphere))) / Math::lengthOfVector(mDirection);
	mShortestDistanceDirection_SECOND_IntersectionPoint = Math::lengthOfVector(Math::DoCrossProduct(mDirection, (mALL_IntersectionPoints.getSecondIntersectionPoint() - mPointSphere))) / Math::lengthOfVector(mDirection);

	if (mALL_IntersectionPoints.getNumIntersectionPoint() == 2) // there are two intersection points
	{	
		// check witch intersection point is next to the vertex of the sphere

		if (mShortestDistanceDirection_FIRST_IntersectionPoint > mSemiHeight && mShortestDistanceDirection_SECOND_IntersectionPoint > mSemiHeight)
		{
			// the intersection point is NOT in the spherical surface
			return ReturnIntersectInformation; //N there is NO intersection point
		}

		else if (mStepsT_first > 0 && mStepsT_second > 0 && mDirection * mRay.getDirectionRayUnit() >= 0.0 || /*TODO: this is good enought for sequential ray tracing but NOT for non-seq!!!*/ (mDirection.getX() == 0.0 && mDirection.getZ() == 0.0)) // we have to chose the first intersection point
		{
			if (mShortestDistanceDirection_FIRST_IntersectionPoint <= mSemiHeight)
			{
				mNormalOnSphereAtIntersectPointUnit = Math::unitVector(mALL_IntersectionPoints.getFirstIntersectionPoint() - mCenterSphereAfterRotation);
				if (mNormalOnSphereAtIntersectPointUnit*mRay.getDirectionRayUnit() <= 0) // surface side A
				{
					ReturnIntersectInformation.setAll(mALL_IntersectionPoints.getFirstIntersectionPoint() ,mNormalOnSphereAtIntersectPointUnit,A,std::abs(mStepsT_first*mRay.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,mRay.getDirectionRayUnit(), mLight);
					return ReturnIntersectInformation;
				}
				else // surface side B
				{
					ReturnIntersectInformation.setAll(mALL_IntersectionPoints.getFirstIntersectionPoint(),/*flip normale*/-1.0 * mNormalOnSphereAtIntersectPointUnit,B,std::abs(mStepsT_first*mRay.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,mRay.getDirectionRayUnit(), mLight);
					return ReturnIntersectInformation;
				}
			}

			else if (mShortestDistanceDirection_SECOND_IntersectionPoint <= mSemiHeight)
			{
				mNormalOnSphereAtIntersectPointUnit = Math::unitVector(mALL_IntersectionPoints.getFirstIntersectionPoint() - mCenterSphereAfterRotation);
				if (mNormalOnSphereAtIntersectPointUnit*mRay.getDirectionRayUnit() <= 0) // surface side A
				{
					ReturnIntersectInformation.setAll(mALL_IntersectionPoints.getSecondIntersectionPoint(),mNormalOnSphereAtIntersectPointUnit,A,std::abs(mStepsT_first*mRay.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,mRay.getDirectionRayUnit(), mLight);
					return ReturnIntersectInformation;
				}
				else // surface side B
				{
					ReturnIntersectInformation.setAll(mALL_IntersectionPoints.getSecondIntersectionPoint(),/*flip normale*/-1.0 * mNormalOnSphereAtIntersectPointUnit,B,std::abs(mStepsT_first*mRay.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,mRay.getDirectionRayUnit(), mLight);
					return ReturnIntersectInformation;
				}


			}
		}

		// we have to check the first intersection point
		else if (mDistancePointFirstIntersectionPoint < mDistancePointSecondIntersectionPoint && mShortestDistanceDirection_FIRST_IntersectionPoint <= mSemiHeight)
		{
			// the FIRST intersection point is in the spherical surface

			mNormalOnSphereAtIntersectPointUnit = Math::unitVector(mALL_IntersectionPoints.getFirstIntersectionPoint() - mCenterSphereAfterRotation);
			if (mNormalOnSphereAtIntersectPointUnit*mRay.getDirectionRayUnit() <= 0) // surface side A
			{
				ReturnIntersectInformation.setAll(mALL_IntersectionPoints.getFirstIntersectionPoint(),mNormalOnSphereAtIntersectPointUnit,A,std::abs(mStepsT_first*mRay.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,mRay.getDirectionRayUnit(), mLight);
				return ReturnIntersectInformation;
			}
			else // surface side B
			{
				ReturnIntersectInformation.setAll(mALL_IntersectionPoints.getFirstIntersectionPoint(),/*flip normale*/-1.0 * mNormalOnSphereAtIntersectPointUnit,B,std::abs(mStepsT_first*mRay.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,mRay.getDirectionRayUnit(), mLight);
				return ReturnIntersectInformation;
			}


		}


		else if (mDistancePointFirstIntersectionPoint > mDistancePointSecondIntersectionPoint && mShortestDistanceDirection_SECOND_IntersectionPoint <= mSemiHeight) // we have to check the second intersection point
		{

			// the SECOND intersection point is in the spherical surface

			mNormalOnSphereAtIntersectPointUnit = Math::unitVector(mALL_IntersectionPoints.getSecondIntersectionPoint() -mCenterSphereAfterRotation);
			if (mNormalOnSphereAtIntersectPointUnit*mRay.getDirectionRayUnit() <= 0) // surface side A
			{
				ReturnIntersectInformation.setAll(mALL_IntersectionPoints.getSecondIntersectionPoint() ,mNormalOnSphereAtIntersectPointUnit,A,std::abs(mStepsT_second*mRay.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,mRay.getDirectionRayUnit(), mLight);
				return ReturnIntersectInformation;
			}
			else // surface side B
			{
				ReturnIntersectInformation.setAll(mALL_IntersectionPoints.getSecondIntersectionPoint(),/*here we have to flip the nomal vector*/-1 * mNormalOnSphereAtIntersectPointUnit,B,std::abs(mStepsT_second*mRay.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,mRay.getDirectionRayUnit(), mLight);
				return ReturnIntersectInformation;
			}
		}

		else if (mShortestDistanceDirection_SECOND_IntersectionPoint > mSemiHeight)
		{
			// the intersection point is NOT in the spherical surface
			return ReturnIntersectInformation; //N there is NO intersection point
		}

		else if (mShortestDistanceDirection_FIRST_IntersectionPoint > mSemiHeight)
		{
			return ReturnIntersectInformation; //N there is NO intersection point
		}


	}

	else if (mDistancePointFirstIntersectionPoint == mDistancePointSecondIntersectionPoint)  // next we have to check the steps
	{
		if (mALL_IntersectionPoints.getStepsFirstIP() < mALL_IntersectionPoints.getStepsSecondIP())
		{
			// shortestDistanceDirection_FIRST_IntersectionPoint = Math::lengthOfVector(Math::DoCrossProduct(mDirection, (ALL_IntersectionPoints.firstIntersectionPoint - mPoint))) / Math::lengthOfVector(mDirection);
			if (mShortestDistanceDirection_FIRST_IntersectionPoint > mSemiHeight)
			{
				//the intersection point is NOT in the spherical surface
				return ReturnIntersectInformation;
			}
			else // the FIRST intersection point is in the spherical surface
			{

				mNormalOnSphereAtIntersectPointUnit = Math::unitVector(mALL_IntersectionPoints.getFirstIntersectionPoint() - mCenterSphereAfterRotation);
				if (mNormalOnSphereAtIntersectPointUnit*mRay.getDirectionRayUnit() <= 0) // surface side A
				{
					ReturnIntersectInformation.setAll(mALL_IntersectionPoints.getFirstIntersectionPoint(),mNormalOnSphereAtIntersectPointUnit,A,std::abs(mStepsT_first*mRay.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,mRay.getDirectionRayUnit(), mLight);
					return ReturnIntersectInformation;
				}
				else // surface side B
				{
					ReturnIntersectInformation.setAll(mALL_IntersectionPoints.getFirstIntersectionPoint(),/*flip normale*/-1.0 * mNormalOnSphereAtIntersectPointUnit,B,std::abs(mStepsT_first*mRay.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,mRay.getDirectionRayUnit(), mLight);
					return ReturnIntersectInformation;
				}

			}
		}
		else //(IntersectionPoints.stepsT_first > IntersectionPoints.stepsT_second)
		{
			//double shortestDistanceDirection_SECOND_IntersectionPoint = Math::lengthOfVector(Math::DoCrossProduct(mDirection, (ALL_IntersectionPoints.secondIntersectionPoint - mPoint))) / Math::lengthOfVector(mDirection);
			if (mShortestDistanceDirection_SECOND_IntersectionPoint > mSemiHeight)
			{
				//the intersection point is NOT in the spherical surface
				return ReturnIntersectInformation; //N there is NO intersection point
			}
			else // the SECOND intersection point is in the spherical surface
			{
				mNormalOnSphereAtIntersectPointUnit = Math::unitVector(mALL_IntersectionPoints.getSecondIntersectionPoint() - mCenterSphereAfterRotation);
				if (mNormalOnSphereAtIntersectPointUnit*mRay.getDirectionRayUnit() <= 0) // surface side A
				{
					ReturnIntersectInformation.setAll(mALL_IntersectionPoints.getSecondIntersectionPoint(),mNormalOnSphereAtIntersectPointUnit,A,std::abs(mStepsT_second*mRay.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,mRay.getDirectionRayUnit(), mLight);
					return ReturnIntersectInformation;
				}
				else // surface side B
				{
					ReturnIntersectInformation.setAll(mALL_IntersectionPoints.getSecondIntersectionPoint(), /*flip normale*/-1.0 * mNormalOnSphereAtIntersectPointUnit,B,std::abs(mStepsT_second*mRay.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,mRay.getDirectionRayUnit(),mLight);
					return ReturnIntersectInformation;
				}
			}
		}

	}
	
	return ReturnIntersectInformation;
}

void SphericalSurface_LLT::calcFocalLength()
{
	if (mDirection.getZ() > 0)
	{
		mFocalLength = - (mRadius * mRefractiveIndexA) / (mRefractiveIndexA - mRefractiveIndexB);
		mFocalLength_dash = (mRadius * mRefractiveIndexA) / (mRefractiveIndexA - mRefractiveIndexB);
	}

	else
	{
		mFocalLength =  (mRadius * mRefractiveIndexA) / (mRefractiveIndexA - mRefractiveIndexB);
		mFocalLength_dash = - (mRadius * mRefractiveIndexA) / (mRefractiveIndexA - mRefractiveIndexB);
	}
}



// get refractive index side A
real SphericalSurface_LLT::getRefractiveIndex_A()
{
	return mRefractiveIndexA;
}
// get refractive index side B
real SphericalSurface_LLT::getRefractiveIndex_B()
{
	return mRefractiveIndexB;
}



// make the 2d plot
void SphericalSurface_LLT::plot2D(cv::Mat image, unsigned int scale, unsigned int thickness, unsigned int lineType)
{
	unsigned int wide = image.cols;
	unsigned int height = image.rows;

	// distance to left border
	unsigned int boarterLeft = 50;

	//sampling
	unsigned int sampling = 30;

	VectorStructR2 dir2D_Unit = Math::unitVec2D({ mDirection.getZ(), mDirection.getY() });
	VectorStructR2 point2D{ mPointSphere.getZ(), mPointSphere.getY() };
	VectorStructR2 orto2D_Unit = Math::calcOrtoVec2D_Unit({ mDirection.getZ(), mDirection.getY() });


	// center of sphere in global coordinat system of trace master
	VectorStructR2 centerSphere = point2D + mRadius * dir2D_Unit;

	// calculate relevant distance to plot according to semiHeight
	real dX_total = mRadius - (std::sqrt(std::pow(mRadius, 2) - std::pow(mSemiHeight, 2)));

	real Xmin = point2D.getX();
	real Xmax = (point2D + dir2D_Unit * dX_total).getX();

	if (Xmin == Xmax) // spherical lens is rotated about plus/minus 90°
	{
		Xmin = point2D.getY();
		Xmax = (point2D + dir2D_Unit * dX_total).getY();
	}

	// calculate staps (deltaX)
	real distanceXminXmax = std::abs(std::abs(Xmax) - std::abs(Xmin));
	real deltaX = distanceXminXmax / sampling;
	real stepsX = 0.0;

	// the first point to plot is always the apex of the sphere
	VectorStructR2 startPoint2D = point2D;

	int xPlotStartPos = boarterLeft + startPoint2D.getX() * scale;
	int yPlotStartPos = height / 2 - startPoint2D.getY() * scale;

	// the start point is in the beginning the same
	int xPlotStartNeg = xPlotStartPos;
	int yPlotStartNeg = yPlotStartPos;


	// we calculate to points on sphere and make a line between them
	for (unsigned int i = 0; i < sampling; i++)
	{
		cv::Point centerStartPos(xPlotStartPos, yPlotStartPos);
		cv::Point centerStartNeg(xPlotStartNeg, yPlotStartNeg);

		stepsX = stepsX + deltaX;

		real dy = std::sqrt(2 * stepsX*mRadius - std::pow(stepsX, 2));

		VectorStructR2 newPointPos = point2D + dir2D_Unit * stepsX + orto2D_Unit * dy;
		VectorStructR2 newPointNeg = point2D + dir2D_Unit * stepsX - orto2D_Unit * dy;

		int xPlotEndPos = boarterLeft + newPointPos.getX() * scale;
		int yPlotEndPos = height / 2 - newPointPos.getY() * scale;

		int xPlotEndNeg = boarterLeft + newPointNeg.getX() * scale;
		int yPlotEndNeg = height / 2 - newPointNeg.getY() * scale;

		cv::Point centerEndPos(xPlotEndPos, yPlotEndPos);
		cv::Point centerEndNeg(xPlotEndNeg, yPlotEndNeg);

		PlotCarsten::line(image, centerStartPos, centerEndPos, { 0,0,0 }, thickness * 2, lineType);
		PlotCarsten::line(image, centerStartNeg, centerEndNeg, { 0,0,0 }, thickness * 2, lineType);

		xPlotStartPos = xPlotEndPos;
		yPlotStartPos = yPlotEndPos;

		xPlotStartNeg = xPlotEndNeg;
		yPlotStartNeg = yPlotEndNeg;

	}


}

SphericalSurface_LLT::SphericalSurface_LLT() {};

SphericalSurface_LLT::SphericalSurface_LLT(SphericalSurface_LLT &source)
{
	if (this == &source)
	{
		return;
	}

	mRadius = source.mRadius;
	mSemiHeight = source.mSemiHeight;
	mPointSphere = source.mPointSphere;
	mDirection = source.mDirection;
	mRefractiveIndexA = source.mRefractiveIndexA;
	mRefractiveIndexB = source.mRefractiveIndexB;
	mCenterSphereAfterRotation = source.mCenterSphereAfterRotation;
	mFocalLength = source.mFocalLength;
	mFocalLength_dash = source.mFocalLength_dash;
	SphericalSurface_Qwt_Ptr = source.SphericalSurface_Qwt_Ptr;
	pointsofSphericalSurface = source.pointsofSphericalSurface;
	
}

SphericalSurface_LLT& SphericalSurface_LLT::operator=(SphericalSurface_LLT& source)
{
	if (this == &source)
	{
		return *this;
	}

	mRadius = source.mRadius;
	mSemiHeight = source.mSemiHeight;
	mPointSphere = source.mPointSphere;
	mDirection = source.mDirection;
	mRefractiveIndexA = source.mRefractiveIndexA;
	mRefractiveIndexB = source.mRefractiveIndexB;
	mCenterSphereAfterRotation = source.mCenterSphereAfterRotation;
	mFocalLength = source.mFocalLength;
	mFocalLength_dash = source.mFocalLength_dash;
	SphericalSurface_Qwt_Ptr = source.SphericalSurface_Qwt_Ptr;
	pointsofSphericalSurface = source.pointsofSphericalSurface;
	return *this;
}


std::shared_ptr<SurfaceIntersectionRay_LLT> SphericalSurface_LLT::clone()
{
	std::shared_ptr<SurfaceIntersectionRay_LLT> sphericalSurface_LLT(new SphericalSurface_LLT(*this));

	return sphericalSurface_LLT;
}

void SphericalSurface_LLT::setRadius(real radius)
{
	mRadius = radius;
	calcCenterSphereAfterRotation();
}
void SphericalSurface_LLT::setPosition(VectorStructR3 position)
{

	mPointSphere = position;
	calcCenterSphereAfterRotation();
}

SphericalSurfaceQwt* SphericalSurface_LLT::getPointerPlot()
{
	return SphericalSurface_Qwt_Ptr;
}

QPolygonF*  SphericalSurface_LLT::getQPolygonFCurve()
{
	return &pointsofSphericalSurface;
}


void SphericalSurface_LLT::setPointerPlotQwt()
{
	SphericalSurface_Qwt_Ptr = new SphericalSurfaceQwt(mRadius, mSemiHeight, mDirection, mPointSphere);
	pointsofSphericalSurface = SphericalSurface_Qwt_Ptr->points(mRadius, mSemiHeight, mDirection, mPointSphere);
}

void SphericalSurface_LLT::setDirection(VectorStructR3 direction)
{
	mDirection = direction;
	calcCenterSphereAfterRotation();
}