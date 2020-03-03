#include "ApertureStop_LLT.h"
#include <iostream>

// get semt height
double ApertureStop_LLT::getSemiHeight()
{
	return mSemiHeightAperture;
};


//get radius
real ApertureStop_LLT::getRadius()
{
	return 999999999999999999999999999.0;
}

//set semi height
void ApertureStop_LLT::setSemiHeight(double semiHeight)
{
	mSemiHeightAperture = semiHeight;
};

//get point
VectorStructR3 ApertureStop_LLT::getPoint()
{
	return mPointAperture;
}
// set point
void ApertureStop_LLT::setPoint(VectorStructR3 point)
{
	mPointAperture = point;
}

// get direction
VectorStructR3 ApertureStop_LLT::getDirection()
{
	return mDirectionAperture;
}

//set direction
void ApertureStop_LLT::setDirection(VectorStructR3 direction)
{
	mDirectionAperture = direction;
}

// get refractive index
double ApertureStop_LLT::getRefractiveIndex()
{
	return mRrefractiveIndex;
}

// set refractive indes
void ApertureStop_LLT::setRefractiveIndexSide_A(real const& refractiveIndex)
{
	mRrefractiveIndex = refractiveIndex;
}

// set refractive indes
void ApertureStop_LLT::setRefractiveIndexSide_B(real const& refractiveIndex)
{
	mRrefractiveIndex = refractiveIndex;
}

// get focal length side A
real ApertureStop_LLT::getFocalLength_A()
{
	std::cout << "the aperture stop has no focal length! -> there must be a mistake!" << std::endl;
	return 999;
}
// get focal length side B
real ApertureStop_LLT::getFocalLength_B()
{
	std::cout << "the aperture stop has no focal length! -> there must be a mistake!" << std::endl;
	return 999;
}

// get refractive index side A
real ApertureStop_LLT::getRefractiveIndex_A()
{
	return mRrefractiveIndex;
}
// get refractive index side B
real ApertureStop_LLT::getRefractiveIndex_B()
{
	return mRrefractiveIndex;
}

IntersectInformationStruct ApertureStop_LLT::calculateIntersection(LightRayStruct const& lightRay)
{
	// ***
	// ATTENTION: we set that tolerance not so height because of ray aiming
	// the tolerance for ray aiming must be lower than the tolerance for the aperture stop
	real tolerance = 1.0;
	// ***
	
	Ray_LLT ray = lightRay.getRay_LLT();
	Light_LLT light = lightRay.getLight_LLT();
	IntersectInformationStruct returnIntersectInfos = { { 0.0,0.0,0.0 },{ 0.0,0.0,0.0 },N, 0.0,0.0,0.0,{ 0.0,0.0,0.0 }, light };

	// flat in coordinate form: E:Nx * X+ Ny * Y+ Nz * Z= d 
	double d = mDirectionAperture * mPointAperture;
	double denominator = mDirectionAperture * ray.getDirectionRayUnit();
	double numerator = d - mDirectionAperture * ray.getOriginRay();

	if (denominator == 0.0)
	{
		// there is no intersection point
		return returnIntersectInfos; //'N' there is NO intersection poin
	}
	else if (numerator == 0.0)
	{
		// ray is in flat!
		// TODO Question Sergej: Was soll dann gemacht werden?!?!?! hier hat man ja dann unendlich viele Schnittpunkte 	
		return returnIntersectInfos; //'N' there is NO intersection poin
		// -> Das ist ja dann eigentlich falsch?! -> es gibt ja viele Schnittpunkte!
	}

	else {//there must be an intersection point!


		double stepsT = numerator / denominator;


		if (stepsT < 0) // ray would walk in the wrong direction
		{
			return returnIntersectInfos; //'N' there is NO intersection poin
		}

		else // calculate the intersection point
		{
			VectorStructR3 intersectionPoint = ray.getOriginRay() + stepsT * ray.getDirectionRayUnit();
			// calculate distance from intersection point to the "point" from the Aperture Stop
			double distance = std::sqrt(std::pow((intersectionPoint.getX() - mPointAperture.getX()), 2) + pow((intersectionPoint.getY() - mPointAperture.getY()), 2) + pow((intersectionPoint.getZ() - mPointAperture.getZ()), 2));


			// we need the intersection point for ray aiming 
			// here it does not metter if the ray goes thow the intersection point or not

			if (ray.getDirectionRayUnit() * mDirectionAperture >= 0) // switch normale on plan geometry and from side A
			{
				returnIntersectInfos = { intersectionPoint,-1.0 * mDirectionAperture ,A, stepsT,mRrefractiveIndex,mRrefractiveIndex,ray.getDirectionRayUnit(), light };
			}

			else if (ray.getDirectionRayUnit() * mDirectionAperture <= 0)// from side B
			{
				returnIntersectInfos = { intersectionPoint,mDirectionAperture ,B, stepsT,mRrefractiveIndex,mRrefractiveIndex,ray.getDirectionRayUnit(), light };
			}

			
			if ((distance - mSemiHeightAperture) > tolerance) // ray get absorbed by the aperture stop
			{
				returnIntersectInfos.setSurface(N);
			}
		}

	}

	return returnIntersectInfos;
}


// make the 2d plot
void ApertureStop_LLT::plot2D(cv::Mat image, unsigned int scale, unsigned int thickness, unsigned int lineType)
{

}

ApertureStop_LLT::ApertureStop_LLT() {};
ApertureStop_LLT::~ApertureStop_LLT() {};

ApertureStop_LLT::ApertureStop_LLT(ApertureStop_LLT &source)
{
	if (this == &source)
	{
		return;
	}

	mSemiHeightAperture = source.mSemiHeightAperture;
	mPointAperture = source.mPointAperture;
	mDirectionAperture = source.mDirectionAperture;
	mRrefractiveIndex = source.mRrefractiveIndex;

	// TODO: Also copy the spherical informaltion to plot!
	// SphericalSurfaceQwt* SphericalSurface_Qwt_Ptr = new SphericalSurfaceQwt(mRadius, mSemiHeight, mDirection, mPointSphere);
}

ApertureStop_LLT& ApertureStop_LLT::operator=(ApertureStop_LLT& source)
{
	if (this == &source)
	{
		return *this;
	}

	mSemiHeightAperture = source.mSemiHeightAperture;
	mPointAperture = source.mPointAperture;
	mDirectionAperture = source.mDirectionAperture;
	mRrefractiveIndex = source.mRrefractiveIndex;

	return *this;
}

std::shared_ptr<SurfaceIntersectionRay_LLT> ApertureStop_LLT::clone()
{
	std::shared_ptr<SurfaceIntersectionRay_LLT> apertureStop_LLT(new ApertureStop_LLT(*this));

	return apertureStop_LLT;
}

void ApertureStop_LLT::setRadius(real radius)
{
	std::cout << "a aperture stop has no radius" << std::endl;
}
void ApertureStop_LLT::setPosition(VectorStructR3 position)
{
	mPointAperture = position;
}

QPolygonF ApertureStopQwtDown::getPoints()
{
	return ApertureStopPoints;
}

QPointF ApertureStopQwtDown::rotate_point(double cx, double cy, double angle, QPointF p)
{
	QPointF rotatedPoint;
	double s = sin(angle);
	double c = cos(angle);

	// translate point back to origin:
	rotatedPoint.setX(p.x() - cx);
	rotatedPoint.setY(p.y() - cy);

	// rotate point
	double xnew = rotatedPoint.x() * c - rotatedPoint.y() * s;
	double ynew = rotatedPoint.x() * s + rotatedPoint.y() * c;

	// translate point back:
	rotatedPoint.setX(xnew + cx);
	rotatedPoint.setY(ynew + cy);

	return rotatedPoint;
}

ApertureStopQwtDown::ApertureStopQwtDown(double semiHeight, VectorStructR3 point, VectorStructR3 direction)
{
	unsigned int wide = 1600;
	unsigned int height = 1000;
	int boarterLeft_Qwt = 50;
	int scale = 20;

	VectorStructR2 dir2D{ direction.getZ(), direction.getY() };
	VectorStructR2 ortoUnit = Math::calcOrtoVec2D_Unit(dir2D);


	// attention open cv has a specific coordinat system!!!
	double endX = boarterLeft_Qwt + point.getZ() * scale - ortoUnit.getX() *semiHeight * scale;
	double endY = height / 2 + point.getY() * scale + ortoUnit.getY() * semiHeight * scale;


	// data points
	// data points
	double RotationAngle = -atan(dir2D.getY() / dir2D.getX());
	double factorX = 4;
	double factorY = 4;

	if (direction.getY() > 0)
	{

		QPointF endPoint(endX - factorX, endY);
		ApertureStopPoints << QPointF(endX, endY) << rotate_point(endX, endY, RotationAngle, endPoint);
		endPoint.setX(endX + factorX);
		endPoint.setY(endY);
		ApertureStopPoints << rotate_point(endX, endY, RotationAngle, endPoint) << QPointF(endX, endY);
		endPoint.setX(endX);
		endPoint.setY(endY - factorY);
		ApertureStopPoints << rotate_point(endX, endY, RotationAngle, endPoint) << QPointF(endX, endY);

	}
	else
	{


		QPointF endPoint(endX - factorX, endY);

		ApertureStopPoints << QPointF(endX, endY) << rotate_point(endX, endY, RotationAngle, endPoint);
		endPoint.setX(endX + factorX);
		endPoint.setY(endY);
		ApertureStopPoints << rotate_point(endX, endY, RotationAngle, endPoint) << QPointF(endX, endY);
		endPoint.setX(endX);
		endPoint.setY(endY + factorY);
		ApertureStopPoints << rotate_point(endX, endY, RotationAngle, endPoint) << QPointF(endX, endY);

	}
	setStyle(QwtPlotCurve::Lines);
	setPen(QColor("black"), 2);

	setSamples(ApertureStopPoints);

}

QPolygonF ApertureStopQwtUp::getPoints()
{
	return ApertureStopPoints;
}

QPointF ApertureStopQwtUp::rotate_point(double cx, double cy, double angle, QPointF p)
{
	QPointF rotatedPoint;
	double s = sin(angle);
	double c = cos(angle);

	// translate point back to origin:
	rotatedPoint.setX(p.x() - cx);
	rotatedPoint.setY(p.y() - cy);

	// rotate point
	double xnew = rotatedPoint.x() * c - rotatedPoint.y() * s;
	double ynew = rotatedPoint.x() * s + rotatedPoint.y() * c;

	// translate point back:
	rotatedPoint.setX(xnew + cx);
	rotatedPoint.setY(ynew + cy);

	return rotatedPoint;
}
ApertureStopQwtUp::ApertureStopQwtUp(double semiHeight, VectorStructR3 point, VectorStructR3 direction)
{
	unsigned int wide = 1600;
	unsigned int height = 1000;
	int boarterLeft_Qwt = 50;
	int scale = 20;

	VectorStructR2 dir2D{ direction.getZ(), direction.getY() };
	VectorStructR2 ortoUnit = Math::calcOrtoVec2D_Unit(dir2D);


	// attention open cv has a specific coordinat system!!!

	double startX = boarterLeft_Qwt + point.getZ() * scale + ortoUnit.getX() * semiHeight * scale;
	double startY = height / 2 + point.getY() * scale - ortoUnit.getY() *semiHeight * scale;

	// data points
	double RotationAngle = -atan(dir2D.getY() / dir2D.getX());
	double factorX = 4;
	double factorY = 4;

	if (direction.getY() > 0)
	{
		QPointF startPoint(startX, startY + factorY);
		ApertureStopPoints << QPointF(startX, startY) << rotate_point(startX, startY, RotationAngle, startPoint) << QPointF(startX, startY);
		startPoint.setX(startX - factorX);
		startPoint.setY(startY);
		ApertureStopPoints << rotate_point(startX, startY, RotationAngle, startPoint);
		startPoint.setX(startX + factorX);
		startPoint.setY(startY);
		ApertureStopPoints << rotate_point(startX, startY, RotationAngle, startPoint) << QPointF(startX, startY);
	}
	else
	{
		QPointF startPoint(startX, startY - factorY);
		ApertureStopPoints << QPointF(startX, startY) << rotate_point(startX, startY, RotationAngle, startPoint) << QPointF(startX, startY);
		startPoint.setX(startX - factorX);
		startPoint.setY(startY);
		ApertureStopPoints << rotate_point(startX, startY, RotationAngle, startPoint);
		startPoint.setX(startX + factorX);
		startPoint.setY(startY);
		ApertureStopPoints << rotate_point(startX, startY, RotationAngle, startPoint) << QPointF(startX, startY);

	}

	//Set the curve's drawing style
	setStyle(QwtPlotCurve::Lines);
	setPen(QColor("black"), 2);
	setSamples(ApertureStopPoints);

}

//get pointer of the Upper qwt curve
ApertureStopQwtUp* ApertureStop_LLT::getPointerPlotUp()
{
	return ApertureStopUp_Qwt_Ptr;
}

//get pointer of the Upper qwt curve
ApertureStopQwtDown* ApertureStop_LLT::getPointerPlotDown()
{
	return ApertureStopDown_Qwt_Ptr;

}

QPolygonF* ApertureStop_LLT::getQPolygonFCurve() 
{
	return &pointsofApertureStopUp;
}

void ApertureStop_LLT::calcApertureStopQwtCoord()
{
	ApertureStopUp_Qwt_Ptr = new ApertureStopQwtUp(mSemiHeightAperture, mPointAperture, mDirectionAperture);
	ApertureStopDown_Qwt_Ptr = new ApertureStopQwtDown(mSemiHeightAperture, mPointAperture, mDirectionAperture);
	pointsofApertureStopUp = ApertureStopUp_Qwt_Ptr->getPoints();
	pointsofApertureStopDown = ApertureStopDown_Qwt_Ptr->getPoints();
}