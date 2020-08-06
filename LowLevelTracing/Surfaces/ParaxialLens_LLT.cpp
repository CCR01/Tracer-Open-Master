#include "ParaxialLens_LLT.h"
#include "PlanGeometry_LLT.h"

// get focal lenght of intersected surface side A
real additionalInfosDeflectedRayParaLensStruct::getFocalLengthOfIntersecSurface_Side_A() const
{
	return focalLengthOfIntersecSurface_Side_A;
}

// set focal lenght of intersected surface side A
void additionalInfosDeflectedRayParaLensStruct::setfocalLengthOfIntersecSurface_Side_A(real const focalLengthSide_A)
{
	focalLengthOfIntersecSurface_Side_A = focalLengthSide_A;
}

// get focal lenght of intersected surface side B
real additionalInfosDeflectedRayParaLensStruct::getFocalLengthOfIntersecSurface_Side_B() const
{
	return focalLengthOfIntersecSurface_Side_B;
}

// set focal lenght of intersected surface side B
void additionalInfosDeflectedRayParaLensStruct::setfocalLengthOfIntersecSurface_Side_B(real const focalLengthSide_B)
{
	focalLengthOfIntersecSurface_Side_B = focalLengthSide_B;
}

// get direction of intersected surface;
VectorStructR3 additionalInfosDeflectedRayParaLensStruct::getDirectionOfIntersecSurfaceUNIT() const
{
	return directionOfIntersecSurfaceUNIT;
}
// set direction of intersected surface;
void additionalInfosDeflectedRayParaLensStruct::setDirectionOfIntersecSurfaceUNIT(VectorStructR3 const directionIntersecSurface)
{
	directionOfIntersecSurfaceUNIT = unitVectorForAddInfosParaLens(directionIntersecSurface);
}
// get point of intersected surface
VectorStructR3 additionalInfosDeflectedRayParaLensStruct::getPointofIntersectSurface() const
{
	return pointOfIntersectSurface;
}
// set point of intersected surface
void additionalInfosDeflectedRayParaLensStruct::setPointofIntersectSurface(VectorStructR3 const pointIntersecSurface)
{
	pointOfIntersectSurface = pointIntersecSurface;
}

// calculate unit vector
VectorStructR3 additionalInfosDeflectedRayParaLensStruct::unitVectorForAddInfosParaLens(VectorStructR3 const V)
{
	VectorStructR3 returnUnitVector;
	double lenghtOfVector = 1 / (std::sqrt(V.getX()*V.getX() + V.getY()*V.getY() + V.getZ()*V.getZ()));
	returnUnitVector.setX(lenghtOfVector * V.getX());
	returnUnitVector.setY(lenghtOfVector * V.getY());
	returnUnitVector.setZ(lenghtOfVector * V.getZ());
	return returnUnitVector;
}


// get semt height
double ParaxialLens_LLT::getSemiHeight()
{
	return mSemiHeightParaxialLens;
}
//set semi height
void ParaxialLens_LLT::setSemiHeight(double semiHeight)
{
	mSemiHeightParaxialLens = semiHeight;
}

//get point
VectorStructR3 ParaxialLens_LLT::getPoint() 
{
	return mPointParaxialLens;
}
// set point
void ParaxialLens_LLT::setPoint(VectorStructR3 point)
{
	mPointParaxialLens = point;
}

// get direction
VectorStructR3 ParaxialLens_LLT::getDirection()
{
	return mDirectionParaxialLens;
}

// get direction unit
VectorStructR3 ParaxialLens_LLT::getDirectionParaxialLensUNIT() const
{
	return mDirectionParaxialLensUnit;
}
//set direction unit
void ParaxialLens_LLT::setDirectionParaxialLensUNIT(VectorStructR3 const direction)
{
	mDirectionParaxialLensUnit = Math::unitVector(direction);
}

// get focal length side A
double ParaxialLens_LLT::getFocalLengthParaxialLens() const
{
	return mFocallenght;
}
// set focal lenght side A
void ParaxialLens_LLT::setFocalLengthParaxialLens(double const focalLenght)
{
	mFocallenght = focalLenght;
}



// set refractive index side A
void ParaxialLens_LLT::setRefractiveIndexSide_A(real const refractiveIndex)
{
	mRefractiveIndexA_ParaxialLens = refractiveIndex;
}

// set refractive index side B
void ParaxialLens_LLT::setRefractiveIndexSide_B(real const refractiveIndex)
{
	mRefractiveIndexB_ParaxialLens = refractiveIndex;
}

IntersectInformationStruct ParaxialLens_LLT::calculateIntersection(LightRayStruct const lightRay)
{
	Ray_LLT ray = lightRay.getRay_LLT();
	Light_LLT mLight = lightRay.getLight_LLT();

	// Paraxial lens -> plan geometry
	PlanGeometry_LLT ParaxialLensPlanGeometry(mSemiHeightParaxialLens, mPointParaxialLens, mDirectionParaxialLensUnit, mRefractiveIndexA_ParaxialLens, mRefractiveIndexB_ParaxialLens);
	// Intersectinformation between ray and plan geometry
	IntersectInformationStruct IntersectInfoRayPlanGeometryParaxial = ParaxialLensPlanGeometry.calculateIntersection(lightRay);
		
	return IntersectInfoRayPlanGeometryParaxial;
}

// set infos for deflection
void ParaxialLens_LLT::setInfosForDeflection() 
{
	mInfosForDefelction.setfocalLengthOfIntersecSurface_Side_A(mFocallenght);
	mInfosForDefelction.setfocalLengthOfIntersecSurface_Side_B(mFocallenght_dash);
	mInfosForDefelction.setDirectionOfIntersecSurfaceUNIT(mDirectionParaxialLensUnit);
	mInfosForDefelction.setPointofIntersectSurface(mPointParaxialLens);
}
// get infos for deflection
additionalInfosDeflectedRayParaLensStruct ParaxialLens_LLT::getInfosForDefelction() const
{
	return mInfosForDefelction;
}


// make the 2d plot
void ParaxialLens_LLT::plot2D(cv::Mat image, unsigned int scale, unsigned int thickness, unsigned int lineType)
{
	unsigned int wide = image.rows;
	unsigned int height = image.cols;
	unsigned int sampling = 100;
	int boarterLeft = 50;

	VectorStructR2 point2D{ mPointParaxialLens.getZ(), mPointParaxialLens.getY() };
	VectorStructR2 dir2D{ mDirectionParaxialLens.getZ(), mDirectionParaxialLens.getY() };
	// calc unit vector 2D
	VectorStructR2 dir2DUnit = Math::unitVec2D(dir2D);
	//VectorStructR2 dir2DUnit = Math::calc(dir2D);
	VectorStructR2 ortoUnit = Math::calcOrtoVec2D_Unit(dir2D);


	// attention open cv has a specific coordinat system!!! 
	int startX = boarterLeft + mPointParaxialLens.getZ() * scale + ortoUnit.getX() * mSemiHeightParaxialLens * scale;
	int startY = height / 2 - mPointParaxialLens.getY() * scale - ortoUnit.getY() * mSemiHeightParaxialLens * scale;
	
	int endX = boarterLeft + mPointParaxialLens.getZ() * scale - ortoUnit.getX() * mSemiHeightParaxialLens * scale;
	int endY = height / 2 - mPointParaxialLens.getY() * scale + ortoUnit.getY() * mSemiHeightParaxialLens * scale;
	
	cv::Point plotStartcv{ startX, startY };
	cv::Point plotEndcv{ endX ,endY };

	PlotCarsten::line(image, plotStartcv, plotEndcv, { 255,0,0 }, thickness, lineType);

	int prefix;
	// if there is an negative focal length the prefix has to be negative
	if (mFocallenght_dash < 0)
	{
		prefix = 1;
	}
	else
	{
		prefix = -1;
	}



	// make a arrow to the end of the line
	//_________________________________________________________________________
	VectorStructR2 v0 = Math::unitVec2D( prefix * mSemiHeightParaxialLens * ortoUnit + dir2DUnit*mSemiHeightParaxialLens);
	int v0X = v0.getX() * scale;
	int v0Y = v0.getY() * scale;
	cv::Point V0_point{ v0X, v0Y };
	cv::Point endV0 = plotStartcv + V0_point;
	PlotCarsten::line(image, plotStartcv, endV0, { 255,0,0 }, 1, 8);
	// _________________________________________________________________________
	VectorStructR2 v1 = Math::unitVec2D(prefix * mSemiHeightParaxialLens * ortoUnit - dir2DUnit*mSemiHeightParaxialLens);
	int v1X = v1.getX() * scale;
	int v1Y = v1.getY() * scale;
	cv::Point V1_point{ v1X, v1Y };
	cv::Point endV1 = plotStartcv + V1_point;
	PlotCarsten::line(image, plotStartcv, endV1, { 255,0,0 }, 1, 8);
	// _________________________________________________________________________
	VectorStructR2 v2 = Math::unitVec2D(prefix * mSemiHeightParaxialLens * (-1 * ortoUnit) + dir2DUnit*mSemiHeightParaxialLens);
	int v2X = v2.getX() * scale;
	int v2Y = v2.getY() * scale;
	cv::Point V2_point{ v2X, v2Y };
	cv::Point endV2 = plotEndcv + V2_point;
	PlotCarsten::line(image, plotEndcv, endV2, { 255,0,0 }, 1, 8);
	// _________________________________________________________________________
	VectorStructR2 v3 = Math::unitVec2D(prefix * mSemiHeightParaxialLens * (-1 * ortoUnit) - dir2DUnit*mSemiHeightParaxialLens);
	int v3X = v3.getX() * scale;
	int v3Y = v3.getY() * scale;
	cv::Point V3_point{ v3X, v3Y };
	cv::Point endV3 = plotEndcv + V3_point;
	PlotCarsten::line(image, plotEndcv, endV3, { 255,0,0 }, 1, 8);
	// _________________________________________________________________________

}

// get focal length side A
real ParaxialLens_LLT::getFocalLength()
{
	return mFocallenght;
}
// get focal length side B
real ParaxialLens_LLT::getFocalLength_dash()
{
	return mFocallenght_dash;
}

// calc focal length
void ParaxialLens_LLT::calcFocalLength()
{
	if (mDirectionParaxialLens.getZ() > 0)
	{
		mFocallenght = -1.0 * mFocallenght * mRefractiveIndexA_ParaxialLens;
		mFocallenght_dash = mFocallenght_dash * mRefractiveIndexB_ParaxialLens;
	}
	else
	{
		mFocallenght = mFocallenght * mRefractiveIndexA_ParaxialLens;
		mFocallenght_dash = -1.0 * mFocallenght_dash * mRefractiveIndexB_ParaxialLens;

	}

}

// get refractive index side A
real ParaxialLens_LLT::getRefractiveIndex_A()
{
	return mRefractiveIndexA_ParaxialLens;
}
// get refractive index side B
real ParaxialLens_LLT::getRefractiveIndex_B()
{
	return mRefractiveIndexB_ParaxialLens;
}

//get Radius
double ParaxialLens_LLT::getRadius()
{
	return 99999999999999999999999.0;
}

ParaxialLens_LLT::ParaxialLens_LLT() {};
ParaxialLens_LLT::~ParaxialLens_LLT() {};

ParaxialLens_LLT::ParaxialLens_LLT(double semiHeight, VectorStructR3 point, VectorStructR3 direction, double focallength, double refractiveSideA, double refractiveSideB) :
	mSemiHeightParaxialLens(std::abs(semiHeight)),
	mPointParaxialLens(point),
	mDirectionParaxialLens(direction),
	mDirectionParaxialLensUnit(Math::unitVector(direction)),
	mRefractiveIndexA_ParaxialLens(refractiveSideA),
	mRefractiveIndexB_ParaxialLens(refractiveSideB)
{
	calcFocalLength();
	setInfosForDeflection(); // save the information that are important to deflect a ray at this paraxial lens

};

ParaxialLens_LLT::ParaxialLens_LLT(ParaxialLens_LLT &source)
{
	if (this == &source)
	{
		return;
	}

	mSemiHeightParaxialLens = source.mSemiHeightParaxialLens;
	mPointParaxialLens = source.mPointParaxialLens;
	mDirectionParaxialLens = source.mDirectionParaxialLens;
	mDirectionParaxialLensUnit = source.mDirectionParaxialLensUnit;
	mFocallenght = source.mFocallenght;
	mFocallenght_dash = source.mFocallenght_dash;
	mRefractiveIndexA_ParaxialLens = source.mRefractiveIndexA_ParaxialLens;
	mRefractiveIndexB_ParaxialLens = source.mRefractiveIndexB_ParaxialLens;
	mInfosForDefelction = source.mInfosForDefelction;

	// TODO: Also copy the spherical informaltion to plot!
	// SphericalSurfaceQwt* SphericalSurface_Qwt_Ptr = new SphericalSurfaceQwt(mRadius, mSemiHeight, mDirection, mPointSphere);
}

ParaxialLens_LLT& ParaxialLens_LLT::operator=(ParaxialLens_LLT& source)
{
	if (this == &source)
	{
		return *this;
	}

	mSemiHeightParaxialLens = source.mSemiHeightParaxialLens;
	mPointParaxialLens = source.mPointParaxialLens;
	mDirectionParaxialLens = source.mDirectionParaxialLens;
	mDirectionParaxialLensUnit = source.mDirectionParaxialLensUnit;
	mFocallenght = source.mFocallenght;
	mFocallenght_dash = source.mFocallenght_dash;
	mRefractiveIndexA_ParaxialLens = source.mRefractiveIndexA_ParaxialLens;
	mRefractiveIndexB_ParaxialLens = source.mRefractiveIndexB_ParaxialLens;
	mInfosForDefelction = source.mInfosForDefelction;

	return *this;
}

std::shared_ptr<SurfaceIntersectionRay_LLT> ParaxialLens_LLT::clone()
{
	std::shared_ptr<SurfaceIntersectionRay_LLT> paraxialLens_LLT(new ParaxialLens_LLT(*this));

	return paraxialLens_LLT;
}

void ParaxialLens_LLT::setRadius(real radius)
{
	std::cout << "a paraxial lens has no radius" << std::endl;
}
void ParaxialLens_LLT::setPosition(VectorStructR3 position)
{
	mPointParaxialLens = position;
}

QPolygonF ParaxialLensQwtCurve::getPoints()
{
	return PointsParaxialLensQwtCurve;
}

QPointF ParaxialLensQwtCurve::rotate_point(double cx, double cy, double angle, QPointF p)
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

ParaxialLensQwtCurve::ParaxialLensQwtCurve(double semiHeight, VectorStructR3 point, VectorStructR3 direction)
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


	double endX = boarterLeft_Qwt + point.getZ() * scale - ortoUnit.getX() *semiHeight * scale;
	double endY = height / 2 + point.getY() * scale + ortoUnit.getY() * semiHeight * scale;


	// data points
	double RotationAngle = -atan(dir2D.getY() / dir2D.getX());
	double factorX = 4;
	double factorY = factorX * sqrt(2);


	if (direction.getY() > 0)
	{
		QPointF startPoint(startX + factorX, startY - factorY);

		QPointF endPoint(endX - factorX, endY + factorY);


		PointsParaxialLensQwtCurve << QPointF(startX, startY) << rotate_point(startX, startY, RotationAngle, startPoint);
		startPoint.setX(startX - factorX);
		startPoint.setY(startY - factorY);
		PointsParaxialLensQwtCurve << rotate_point(startX, startY, RotationAngle, startPoint) << QPointF(startX, startY) << QPointF(endX, endY) << rotate_point(endX, endY, RotationAngle, endPoint);
		endPoint.setX(endX + factorX);
		endPoint.setY(endY + factorY);
		PointsParaxialLensQwtCurve << rotate_point(endX, endY, RotationAngle, endPoint) << QPointF(endX, endY);
	}
	else
	{
		QPointF startPoint(startX + factorX, startY + factorY);

		QPointF endPoint(endX - factorX, endY - factorY);


		PointsParaxialLensQwtCurve << QPointF(startX, startY) << rotate_point(startX, startY, RotationAngle, startPoint);
		startPoint.setX(startX - factorX);
		startPoint.setY(startY + factorY);
		PointsParaxialLensQwtCurve << rotate_point(startX, startY, RotationAngle, startPoint) << QPointF(startX, startY) << QPointF(endX, endY) << rotate_point(endX, endY, RotationAngle, endPoint);
		endPoint.setX(endX + factorX);
		endPoint.setY(endY - factorY);
		PointsParaxialLensQwtCurve << rotate_point(endX, endY, RotationAngle, endPoint) << QPointF(endX, endY);
	}


	//Set the curve's drawing style
	setStyle(QwtPlotCurve::Lines);

	setPen(QColor(255, 0, 0), 2);

	setSamples(PointsParaxialLensQwtCurve);
}

ParaxialLensQwtCurve* ParaxialLens_LLT::getPointerPlot()
{
	return ParaxialLensQwtCurve_Ptr;
}

QPolygonF* ParaxialLens_LLT::getQPolygonFCurve()
{
	return &PointsOfParaxialLens;
}

void ParaxialLens_LLT::setDirection(VectorStructR3 direction)
{
	mDirectionParaxialLens = direction;
}