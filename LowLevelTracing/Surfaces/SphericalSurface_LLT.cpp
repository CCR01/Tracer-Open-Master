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


//SphericalSurfaceQwt* SphericalSurface_LLT::getPointerPlot()
//{
//	return SphericalSurface_Qwt_Ptr;
//}


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

// set Diretion
void SphericalSurface_LLT::setDirectionSphere(VectorStructR3 const& Direction)
{
	mDirection = Direction;
}

// get Direction
VectorStructR3 SphericalSurface_LLT::getDirection()
{
	return mDirection;
}

//get Refractiv Index Left
double SphericalSurface_LLT::getRefractivIndexSide_A() const&
{
	return mRefractiveIndexA;
}

//set Refractive Index Left
void SphericalSurface_LLT::setRefractiveIndexSide_A(double const& refractiveIndexLeft)
{
	mRefractiveIndexA = refractiveIndexLeft;
}

//get Refractiv Index Right
double SphericalSurface_LLT::getRefractivIndexSide_B() const&
{
	return mRefractiveIndexB;
}

//set Refractive Index Right
void SphericalSurface_LLT::setRefractiveIndexSide_B(double const& refractiveIndexRight)
{
	mRefractiveIndexB = refractiveIndexRight;
}

// calculate center of shere after rotation	
void SphericalSurface_LLT::calcCenterSphereAfterRotation()
{
	mCenterSphereAfterRotation = mPointSphere + Math::scaleVector(std::abs(mRadius), Math::unitVector(mDirection));
}



// Struct to save the calculatet intersection point between ray and spherical surface
VectorStructR3 SphericalSurface_LLT::ALL_IntersectionPointsStruct::getFirstIntersectionPoint()
{
	return firstIntersectionPoint;
}
VectorStructR3 SphericalSurface_LLT::ALL_IntersectionPointsStruct::getSecondIntersectionPoint()
{
	return secondIntersectionPoint;
}
int SphericalSurface_LLT::ALL_IntersectionPointsStruct::isIntersectionPoint()
{
	return yesNoIntersectionPoint;
}


VectorStructR3 SphericalSurface_LLT::CheckedIntersectionPointStruct::getIntersectionPoint()
{
	return IntersectionPoint;
};


int SphericalSurface_LLT::CheckedIntersectionPointStruct::yesNoIntersectionPoint()
{
	return isIntersectionPoint;
}

// get focal length side A
real SphericalSurface_LLT::getFocalLength_A()
{
	return mFocalLengthSphericalSurfaceSide_A;
}

// get focal length side B
real SphericalSurface_LLT::getFocalLength_B()
{
	return mFocalLengthSphericalSurfaceSide_B;
}





// calculate the intersection information between ray and sphere
// the ray is given from the class "SurfaceIntersection"
IntersectInformationStruct SphericalSurface_LLT::calculateIntersection(LightRayStruct const& lightRay)
{
	Ray_LLT ray = lightRay.getRay_LLT();
	Light_LLT light = lightRay.getLight_LLT();

	IntersectInformationStruct returnIntersectInformation = { { 0.0,0.0,0.0 },{ 0.0,0.0,0.0 }, N, 0.0,0.0,0.0,{ 0.0,0.0,0.0 },light }; //'N' there is NO intersection point
	VectorStructR3 firstIntersectionPoint = { 0.0, 0.0, 0.0 };
	VectorStructR3 secondIntersectionPoint = { 0.0, 0.0, 0.0 };


	ALL_IntersectionPointsStruct ALL_IntersectionPoints = { firstIntersectionPoint, secondIntersectionPoint };


	// TODO Question: Wäre es sinnvoll hier einen Fehler zu schmeißen?!
	/*
	if (mSphericalSurface.getRadius() > 0 && mRay.getDirectionRayUnit().Z < 0)
	{
	std::cout << "It would be better to change the sign of the radius \n";
	}

	if (mSphericalSurface.getRadius() < 0 && mRay.getDirectionRayUnit().Z > 0)
	{
	std::cout << "It would be better to change the sign of the radius \n";
	}
	*/


	// terms to calculate intersection point between ray an sphere
	double cTerm = ray.getOriginRay() * ray.getOriginRay()
		- 2 * (ray.getOriginRay() * mCenterSphereAfterRotation)

		+ (mCenterSphereAfterRotation * mCenterSphereAfterRotation)
		- (mRadius * mRadius);

	double bTerm = 2 * (ray.getOriginRay() * ray.getDirectionRayUnit())
		- 2 * (ray.getDirectionRayUnit() * mCenterSphereAfterRotation);

	double aTerm = ray.getDirectionRayUnit() * ray.getDirectionRayUnit();


	// there are diffente possibilities:
	// there is no intersection point
	// there is 1 intersection point
	// there are 2 intersection points

	// first we check if there is no intersection point between ray an spherical surface
	// so we calculate the term under the sqrt in the Quadratic formula
	double sqrtTermQadraticFormular = bTerm * bTerm - 4 * aTerm * cTerm;
	if (sqrtTermQadraticFormular < 0)
	{
		//std::cout << "there is no intersection point between the ray an the spherical surface \n";
		ALL_IntersectionPoints = { firstIntersectionPoint, firstIntersectionPoint,0,0,0 }; // 0 -> no intersectionpPoint

	}

	else if (sqrtTermQadraticFormular == 0)
	{
		//std::cout << "there is only one intersection point. \n";
		// next we have to calculate that intersection point
		// first we have to calculate the steps we have to walk on the ray
		double stepsT_first_zeroSqrtTerm = -bTerm / (2 * aTerm);

		if (stepsT_first_zeroSqrtTerm < 0) // the ray would walk in the wrong direction
		{
			ALL_IntersectionPoints = { { 0.0,0.0,0.0 },{ 0.0,0.0,0.0 },0,0,0 };
		}
		else
		{
			//calculate intersection Point (there is only ONE intersection point)
			firstIntersectionPoint = ray.getOriginRay() + (stepsT_first_zeroSqrtTerm * ray.getDirectionRayUnit());
			ALL_IntersectionPoints = { firstIntersectionPoint, firstIntersectionPoint,stepsT_first_zeroSqrtTerm,stepsT_first_zeroSqrtTerm, 1 }; // 1 -> one intersection points
		}
	}

	// calculate steps for the first intersection point
	// stepsT_first is always smaller than stepsT_second!!! 
	double stepsT_first = (-bTerm /*for FIRST intersection point*/ - std::sqrt(sqrtTermQadraticFormular)) / (2 * aTerm);

	// calculate steps for the second intersection point
	double stepsT_second = (-bTerm /*for SECOND intersection point*/ + std::sqrt(sqrtTermQadraticFormular)) / (2 * aTerm);

	// there must be two inersection points between ray and spherical surface

	if (stepsT_second < 0) // ray would walk in the wrong direction 
	{
		ALL_IntersectionPoints = { {0.0,0.0,0.0},{ 0.0,0.0,0.0 },0.0,0.0, 0 };
	}


	else if (stepsT_first < 0) // stepT_second is not negative -> checked before
	{
		secondIntersectionPoint = ray.getOriginRay() + stepsT_second * ray.getDirectionRayUnit();
		ALL_IntersectionPoints = { secondIntersectionPoint , secondIntersectionPoint,stepsT_second,stepsT_second, 1 }; // 1 -> one relevate intersection point
	}

	else if (std::abs(stepsT_first - stepsT_second) > 0.00000001 /*TODO select a tolerance*/ && stepsT_first > 0 && stepsT_second > 0) //stepT_first and stepT_second is positive
	{														/*we have to be clear that the intersection points are not the same!*/
		firstIntersectionPoint = ray.getOriginRay() + stepsT_first * ray.getDirectionRayUnit();
		secondIntersectionPoint = ray.getOriginRay() + stepsT_second * ray.getDirectionRayUnit();
		ALL_IntersectionPoints = { firstIntersectionPoint, secondIntersectionPoint,stepsT_first,stepsT_second, 2 }; // 2 -> two intersection points
	}

	else if (std::abs(stepsT_second - stepsT_first) > 0.00000001 /*TODO select a tolerance*/ && stepsT_first >= 0 && stepsT_second > 0)
	{
		firstIntersectionPoint = ray.getOriginRay() + stepsT_first * ray.getDirectionRayUnit();
		secondIntersectionPoint = ray.getOriginRay() + stepsT_second * ray.getDirectionRayUnit();
		ALL_IntersectionPoints = { firstIntersectionPoint, secondIntersectionPoint,stepsT_first,stepsT_second, 2 }; // 2 -> two intersection points
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

	if (ALL_IntersectionPoints.yesNoIntersectionPoint == 0)
	{
		return{ { 0.0,0.0,0.0 },{ 0.0,0.0,0.0 },N, 0.0,0.0,0.0,{ 0.0,0.0,0.0 }, light }; //'N' there is NO intersection point
	}

	else // there must be an intersection point 
	{

		if (ALL_IntersectionPoints.yesNoIntersectionPoint == 1) // there is only on intersection point

		{
			double shortestDistance_FIRST_IntersectionPoint = Math::lengthOfVector(Math::DoCrossProduct((mDirection), (ALL_IntersectionPoints.firstIntersectionPoint - mPointSphere))) / Math::lengthOfVector(mDirection);
			if (shortestDistance_FIRST_IntersectionPoint >= mSemiHeight)
			{
				// the intersection point is NOT in the spherical surface
				return{ { 0.0,0.0,0.0 },{ 0.0,0.0,0.0 }, N, 0.0,0.0,0.0,{ 0.0,0.0,0.0 },light }; //'N' there is NO intersection point
			}
			else // the FIRST intersection point is in the spherical surface
			{
				VectorStructR3 normalOnSphereAtIntersectPointUnit = Math::unitVector(ALL_IntersectionPoints.firstIntersectionPoint - mCenterSphereAfterRotation);
				if (normalOnSphereAtIntersectPointUnit*ray.getDirectionRayUnit() <= 0) // surface side A
				{
					returnIntersectInformation = { ALL_IntersectionPoints.firstIntersectionPoint,normalOnSphereAtIntersectPointUnit,A,std::abs(stepsT_first*ray.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,ray.getDirectionRayUnit(), light };
				}

				else // surface side B 
				{
					returnIntersectInformation = { ALL_IntersectionPoints.firstIntersectionPoint, /*flip normale*/-1.0 * normalOnSphereAtIntersectPointUnit,B,std::abs(stepsT_second*ray.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,ray.getDirectionRayUnit(), light };
				}
			}

		}

		//distance vertex (sphere) and FIRST intersection point
		double distancePointFirstIntersectionPoint = Math::lengthOfVector(mPointSphere - ALL_IntersectionPoints.getFirstIntersectionPoint());
		//distance point (sphere) and SECOND intersection point
		double distancePointSecondIntersectionPoint = Math::lengthOfVector(mPointSphere - ALL_IntersectionPoints.getSecondIntersectionPoint());
		double shortestDistanceDirection_FIRST_IntersectionPoint = Math::lengthOfVector(Math::DoCrossProduct(mDirection, (ALL_IntersectionPoints.firstIntersectionPoint - mPointSphere))) / Math::lengthOfVector(mDirection);
		double shortestDistanceDirection_SECOND_IntersectionPoint = Math::lengthOfVector(Math::DoCrossProduct(mDirection, (ALL_IntersectionPoints.secondIntersectionPoint - mPointSphere))) / Math::lengthOfVector(mDirection);

		if (ALL_IntersectionPoints.yesNoIntersectionPoint == 2) // there are two intersection points
		{	// check witch intersection point is next to the vertex of the sphere




			if (shortestDistanceDirection_FIRST_IntersectionPoint > mSemiHeight && shortestDistanceDirection_SECOND_IntersectionPoint > mSemiHeight)
			{
				// the intersection point is NOT in the spherical surface
				return{ { 0.0,0.0,0.0 },{ 0.0,0.0,0.0 }, N, 0.0,0.0,0.0,{ 0.0,0.0,0.0 }, light }; //'N' there is NO intersection point
			}

			else if (stepsT_first > 0 && stepsT_second > 0 && mDirection * ray.getDirectionRayUnit() >= 0.0 || /*TODO: this is good enought for sequential ray tracing but NOT for non-seq!!!*/ (mDirection.getX() == 0.0 && mDirection.getZ() == 0.0)) // we have to chose the first intersection point
			{
				if (shortestDistanceDirection_FIRST_IntersectionPoint <= mSemiHeight)
				{
					VectorStructR3 normalOnSphereAtIntersectPointUnit = Math::unitVector(ALL_IntersectionPoints.firstIntersectionPoint - mCenterSphereAfterRotation);
					if (normalOnSphereAtIntersectPointUnit*ray.getDirectionRayUnit() <= 0) // surface side A
					{
						returnIntersectInformation = { ALL_IntersectionPoints.firstIntersectionPoint,normalOnSphereAtIntersectPointUnit,A,std::abs(stepsT_first*ray.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,ray.getDirectionRayUnit(), light };
					}
					else // surface side B
					{
						returnIntersectInformation = { ALL_IntersectionPoints.firstIntersectionPoint,/*flip normale*/-1.0 * normalOnSphereAtIntersectPointUnit,B,std::abs(stepsT_first*ray.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,ray.getDirectionRayUnit(), light };
					}
				}

				else if (shortestDistanceDirection_SECOND_IntersectionPoint <= mSemiHeight)
				{
					VectorStructR3 normalOnSphereAtIntersectPointUnit = Math::unitVector(ALL_IntersectionPoints.firstIntersectionPoint - mCenterSphereAfterRotation);
					if (normalOnSphereAtIntersectPointUnit*ray.getDirectionRayUnit() <= 0) // surface side A
					{
						returnIntersectInformation = { ALL_IntersectionPoints.secondIntersectionPoint,normalOnSphereAtIntersectPointUnit,A,std::abs(stepsT_first*ray.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,ray.getDirectionRayUnit(), light };
					}
					else // surface side B
					{
						returnIntersectInformation = { ALL_IntersectionPoints.secondIntersectionPoint,/*flip normale*/-1.0 * normalOnSphereAtIntersectPointUnit,B,std::abs(stepsT_first*ray.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,ray.getDirectionRayUnit(), light };
					}


				}
			}

			// we have to check the first intersection point
			else if (distancePointFirstIntersectionPoint < distancePointSecondIntersectionPoint && shortestDistanceDirection_FIRST_IntersectionPoint <= mSemiHeight)
			{
				// the FIRST intersection point is in the spherical surface

				VectorStructR3 normalOnSphereAtIntersectPointUnit = Math::unitVector(ALL_IntersectionPoints.firstIntersectionPoint - mCenterSphereAfterRotation);
				if (normalOnSphereAtIntersectPointUnit*ray.getDirectionRayUnit() <= 0) // surface side A
				{
					returnIntersectInformation = { ALL_IntersectionPoints.firstIntersectionPoint,normalOnSphereAtIntersectPointUnit,A,std::abs(stepsT_first*ray.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,ray.getDirectionRayUnit(), light };
				}
				else // surface side B
				{
					returnIntersectInformation = { ALL_IntersectionPoints.firstIntersectionPoint,/*flip normale*/-1.0 * normalOnSphereAtIntersectPointUnit,B,std::abs(stepsT_first*ray.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,ray.getDirectionRayUnit(), light };
				}


			}


			else if (distancePointFirstIntersectionPoint > distancePointSecondIntersectionPoint && shortestDistanceDirection_SECOND_IntersectionPoint <= mSemiHeight) // we have to check the second intersection point
			{

				// the SECOND intersection point is in the spherical surface

				VectorStructR3 normalOnSphereAtIntersectPointUnit = Math::unitVector(ALL_IntersectionPoints.secondIntersectionPoint - mCenterSphereAfterRotation);
				if (normalOnSphereAtIntersectPointUnit*ray.getDirectionRayUnit() <= 0) // surface side A
				{
					returnIntersectInformation = { ALL_IntersectionPoints.secondIntersectionPoint ,normalOnSphereAtIntersectPointUnit,A,std::abs(stepsT_second*ray.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,ray.getDirectionRayUnit(), light };
				}
				else // surface side B
				{
					returnIntersectInformation = { ALL_IntersectionPoints.secondIntersectionPoint,/*here we have to flip the nomal vector*/-1 * normalOnSphereAtIntersectPointUnit,B,std::abs(stepsT_second*ray.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,ray.getDirectionRayUnit(), light };
				}
			}

			else if (shortestDistanceDirection_SECOND_IntersectionPoint > mSemiHeight)
			{
				// the intersection point is NOT in the spherical surface
				return{ { 0.0,0.0,0.0 },{ 0.0,0.0,0.0 }, N, 0.0,0.0,0.0,{ 0.0,0.0,0.0 }, light }; //'N' there is NO intersection point
			}

			else if (shortestDistanceDirection_FIRST_IntersectionPoint > mSemiHeight)
			{
				return{ { 0.0,0.0,0.0 },{ 0.0,0.0,0.0 }, N, 0.0,0.0,0.0,{ 0.0,0.0,0.0 }, light }; //'N' there is NO intersection point
			}


		}

		else if (distancePointFirstIntersectionPoint = distancePointSecondIntersectionPoint)  // next we have to check the steps
		{
			if (ALL_IntersectionPoints.stepsT_first < ALL_IntersectionPoints.stepsT_second)
			{
				// shortestDistanceDirection_FIRST_IntersectionPoint = Math::lengthOfVector(Math::DoCrossProduct(mDirection, (ALL_IntersectionPoints.firstIntersectionPoint - mPoint))) / Math::lengthOfVector(mDirection);
				if (shortestDistanceDirection_FIRST_IntersectionPoint > mSemiHeight)
				{
					//the intersection point is NOT in the spherical surface
					returnIntersectInformation = { { 0.0,0.0,0.0 },{ 0.0,0.0,0.0 }, N, 0.0,0.0,0.0,{ 0.0,0.0,0.0 }, light }; //'N' there is NO intersection point
				}
				else // the FIRST intersection point is in the spherical surface
				{

					VectorStructR3 normalOnSphereAtIntersectPointUnit = Math::unitVector(ALL_IntersectionPoints.firstIntersectionPoint - mCenterSphereAfterRotation);
					if (normalOnSphereAtIntersectPointUnit*ray.getDirectionRayUnit() <= 0) // surface side A
					{
						returnIntersectInformation = { ALL_IntersectionPoints.firstIntersectionPoint,normalOnSphereAtIntersectPointUnit,A,std::abs(stepsT_first*ray.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,ray.getDirectionRayUnit(), light };
					}
					else // surface side B
					{
						returnIntersectInformation = { ALL_IntersectionPoints.firstIntersectionPoint,/*flip normale*/-1.0 * normalOnSphereAtIntersectPointUnit,B,std::abs(stepsT_first*ray.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,ray.getDirectionRayUnit(), light };
					}

				}
			}
			else //(IntersectionPoints.stepsT_first > IntersectionPoints.stepsT_second)
			{
				//double shortestDistanceDirection_SECOND_IntersectionPoint = Math::lengthOfVector(Math::DoCrossProduct(mDirection, (ALL_IntersectionPoints.secondIntersectionPoint - mPoint))) / Math::lengthOfVector(mDirection);
				if (shortestDistanceDirection_SECOND_IntersectionPoint > mSemiHeight)
				{
					//the intersection point is NOT in the spherical surface
					return{ { 0.0,0.0,0.0 },{ 0.0,0.0,0.0 }, N, 0.0,0.0,0.0,{ 0.0,0.0,0.0 }, light }; //'N' there is NO intersection point
				}
				else // the SECOND intersection point is in the spherical surface
				{
					VectorStructR3 normalOnSphereAtIntersectPointUnit = Math::unitVector(ALL_IntersectionPoints.firstIntersectionPoint - mCenterSphereAfterRotation);
					if (normalOnSphereAtIntersectPointUnit*ray.getDirectionRayUnit() <= 0) // surface side A
					{
						returnIntersectInformation = { ALL_IntersectionPoints.secondIntersectionPoint,normalOnSphereAtIntersectPointUnit,A,std::abs(stepsT_second*ray.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,ray.getDirectionRayUnit(), light };
					}
					else // surface side B
					{
						returnIntersectInformation = { ALL_IntersectionPoints.secondIntersectionPoint, /*flip normale*/-1.0 * normalOnSphereAtIntersectPointUnit,B,std::abs(stepsT_second*ray.getCurrentRefractiveIndex()),mRefractiveIndexA,mRefractiveIndexB,ray.getDirectionRayUnit(),light };
					}
				}
			}

		}


	}


	return returnIntersectInformation;
}

// calculate focal length spherical surface
double SphericalSurface_LLT::calcFocallLengthSphericalSurface(double const& refIndex_A, double const& refIndex_B, double  const& radius)
{
	if (mDirection.getZ() < 0)
	{
		return (-radius * refIndex_A) / (refIndex_A - refIndex_B);
	}

	else
	{
		return (radius * refIndex_B) / (refIndex_B - refIndex_A);
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
	mFocalLengthSphericalSurfaceSide_A = source.mFocalLengthSphericalSurfaceSide_A;
	mFocalLengthSphericalSurfaceSide_B = source.mFocalLengthSphericalSurfaceSide_B;

	// TODO: Also copy the spherical informaltion to plot!
	// SphericalSurfaceQwt* SphericalSurface_Qwt_Ptr = new SphericalSurfaceQwt(mRadius, mSemiHeight, mDirection, mPointSphere);
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
	mFocalLengthSphericalSurfaceSide_A = source.mFocalLengthSphericalSurfaceSide_A;
	mFocalLengthSphericalSurfaceSide_B = source.mFocalLengthSphericalSurfaceSide_B;

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