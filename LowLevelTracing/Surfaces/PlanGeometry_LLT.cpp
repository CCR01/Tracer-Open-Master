#include "PlanGeometry_LLT.h"
#include "..\Math_LLT.h"
#include <iostream>
#include "..\Interaction\InteractionRay_LLT.h"

QPolygonF PlanGeometryQwt::getPoints()
{
	return PointsOfPlanGeometry;
}

PlanGeometryQwt::PlanGeometryQwt(double semiHeight, VectorStructR3 point, VectorStructR3 direction)
{
	unsigned int wide = 1600;
	unsigned int height = 1000;
	int boarterLeft_Qwt = 50;
	int scale = 20;

	VectorStructR2 dir2D{ -direction.getZ(), direction.getY() };
	VectorStructR2 ortoUnit = Math::calcOrtoVec2D_Unit(dir2D);


	// attention open cv has a specific coordinat system!!!

	double startX = boarterLeft_Qwt + point.getZ() * scale + ortoUnit.getX() * semiHeight * scale;
	double startY = height / 2 + point.getY() * scale - ortoUnit.getY() *semiHeight * scale;


	double endX = boarterLeft_Qwt + point.getZ() * scale - ortoUnit.getX() *semiHeight * scale;
	double endY = height / 2 + point.getY() * scale + ortoUnit.getY() * semiHeight * scale;


	// data points

	PointsOfPlanGeometry << QPointF(startX, startY) << QPointF(endX, endY);

	//Set the curve's drawing style
	setStyle(QwtPlotCurve::Lines);


	setCurveAttribute(Fitted, true);

	QwtSplineCurveFitter* curveFitter = new QwtSplineCurveFitter();
	curveFitter->setFitMode(curveFitter->Auto);
	curveFitter->setSplineSize(1000);
	setCurveFitter(curveFitter);

	setPen(QColor(255, 0, 0), 2);

	setSamples(PointsOfPlanGeometry);




};



//PlanGeometryQwt* PlanGeometry_LLT::getPointerPlot()
//{
//	return PlanGeometry_Qwt_Ptr;
//};

// get semt height
double PlanGeometry_LLT::getSemiHeight()
{
	return mSemiHeightPlan;
}
;
//set semi height
void PlanGeometry_LLT::setSemiHeight(double semiHeight)
{
	mSemiHeightPlan = semiHeight;
};

//get point
VectorStructR3 PlanGeometry_LLT::getPoint()
{
	return mPointPlan;
}
// set point
void PlanGeometry_LLT::setPoint(VectorStructR3 point)
{
	mPointPlan = point;
}

// get direction
VectorStructR3 PlanGeometry_LLT::getDirection()
{
	return mDirectionPlan;
}

// set refractive index side A
void PlanGeometry_LLT::setRefractiveIndexSide_A(double const refractiveIndex)
{
	mRefractiveIndexA_Plan = refractiveIndex;
}


// set refractive index side B
void PlanGeometry_LLT::setRefractiveIndexSide_B(double const refractiveIndex)
{
	mRefractiveIndexB_Plan = refractiveIndex;
}


// calculate the intersection information
IntersectInformationStruct PlanGeometry_LLT::calculateIntersection(LightRayStruct const lightRay)
{
	IntersectInformationStruct returnIntersectInfos;
	Ray_LLT ray = lightRay.getRay_LLT();
	Light_LLT mLight = lightRay.getLight_LLT();


	// flat in coordinate form: E:Nx * X+ Ny * Y+ Nz * Z= d 
	double d = mDirectionPlan * mPointPlan;
	// calculate steps to walk from origin ray to flat
	//double checkDX = ray.getDirectionRayUnit().X;
	//double checkDY = ray.getDirectionRayUnit().getY();
	//double checkDZ = ray.getDirectionRayUnit().getZ();

	double denominator = mDirectionPlan * ray.getDirectionRayUnit();
	double numerator = d - mDirectionPlan * ray.getOriginRay();
	if (denominator == 0.0)
	{
		// there is no intersection point
		returnIntersectInfos = { { 0.0,0.0,0.0 },{ 0.0,0.0,0.0 },N, 0.0,0.0,0.0,{ 0.0,0.0,0.0 }, mLight }; //N there is NO intersection poin
	}
	else if (numerator == 0.0)
	{
		// ray is in flat!
		// TODO Question Sergej: Was soll dann gemacht werden?!?!?! hier hat man ja dann unendlich viele Schnittpunkte 	
		returnIntersectInfos = { { 0.0,0.0,0.0 },{ 0.0,0.0,0.0 },N, 0.0,0.0,0.0,{ 0.0,0.0,0.0 }, mLight }; //N there is NO intersection poin
		// -> Das ist ja dann eigentlich falsch?! -> es gibt ja viele Schnittpunkte!
	}

	else {//there must be an intersection point!


		double stepsT = numerator / denominator;


		if (stepsT < 0) // ray would walk in the wrong direction
		{
			returnIntersectInfos = { { 0.0,0.0,0.0 },{ 0.0,0.0,0.0 },N, 0.0,0.0,0.0,{ 0.0,0.0,0.0 }, mLight }; //N there is NO intersection poin
		}

		else // calculate the intersection point
		{
			VectorStructR3 intersectionPoint = ray.getOriginRay() + stepsT * ray.getDirectionRayUnit();



			/*
			std::cout << "____________________________________ \n";
			std::cout << "____________________________________ \n";
			std::cout << "____________________________________ \n";
			std::cout << "ray origin: \n ";
			ray.getOriginRay().print();
			std::cout << "ray origin: \n ";
			ray.getDirectionRayUnit().print();
			std::cout << "numerator: " << numerator << std::endl;
			std::cout << "denominator: " << denominator << std::endl;
			std::cout << "steps: " << stepsT << std::endl;
			std::cout << "intersection point: \n";
			intersectionPoint.print();
			std::cout << "____________________________________ \n";
			std::cout << "____________________________________ \n";
			std::cout << "____________________________________ \n";
			*/



			// calculate distance from intersection point to the "point" from the plan geometry
			double distance = std::sqrt(std::pow((intersectionPoint.getX() - mPointPlan.getX()), 2) + pow((intersectionPoint.getY() - mPointPlan.getY()), 2) + pow((intersectionPoint.getZ() - mPointPlan.getZ()), 2));
			/*
			std::cout << "____________________________________ \n";
			std::cout << "____________________________________ \n";
			std::cout << "____________________________________ \n";
			std::cout << denominator << std::endl;
			std::cout << numerator << std::endl;
			std::cout << "___Dist\n" << distance << std::endl;
			std::cout << "intersection point: \n";
			intersectionPoint.print();
			std::cout << "____________________________________ \n";
			std::cout << "____________________________________ \n";
			std::cout << "____________________________________ \n";
			*/
			if (distance > mSemiHeightPlan) // check if intersection point is in the plan geometry
			{
				// the intersection point is not on the plan geometry
				returnIntersectInfos = { { 0.0,0.0,0.0 },{ 0.0,0.0,0.0 },N, 0.0,0.0,0.0,{ 0.0,0.0,0.0 }, mLight }; //N there is NO intersection poin
			}

			else // the intersection point is in the plan geometry
			{
				if (ray.getDirectionRayUnit() * mDirectionPlan > 0) // switch normale on plan geometry and from side A
				{
					returnIntersectInfos = { intersectionPoint,-1.0 * mDirectionPlan ,A, stepsT * mRefractiveIndexA_Plan ,mRefractiveIndexA_Plan,mRefractiveIndexB_Plan,ray.getDirectionRayUnit(), mLight };
				}
				else // from side B
				{
					returnIntersectInfos = { intersectionPoint,mDirectionPlan ,B, stepsT * mRefractiveIndexB_Plan,mRefractiveIndexA_Plan,mRefractiveIndexB_Plan,ray.getDirectionRayUnit(), mLight };
				}
			}


		}

	}

	return returnIntersectInfos;

}


// make the 2d plot
void PlanGeometry_LLT::plot2D(cv::Mat image, unsigned int scale, unsigned int thickness, unsigned int lineType)
{
	unsigned int wide = image.cols;
	unsigned int height = image.rows;
	int boarterLeft = 50;

	VectorStructR2 point2D{ mPointPlan.getZ(), mPointPlan.getY() };
	VectorStructR2 dir2D{ mDirectionPlan.getZ(), mDirectionPlan.getY() };
	VectorStructR2 ortoUnit = Math::calcOrtoVec2D_Unit(dir2D);


	// attention open cv has a specific coordinat system!!! 

	int startX = boarterLeft + mPointPlan.getZ() * scale + ortoUnit.getX() * mSemiHeightPlan * scale;
	int startY = height / 2 - mPointPlan.getY() * scale - ortoUnit.getY() * mSemiHeightPlan * scale;

	int endX = boarterLeft + mPointPlan.getZ() * scale - ortoUnit.getX() * mSemiHeightPlan * scale;
	int endY = height / 2 - mPointPlan.getY() * scale + ortoUnit.getY() * mSemiHeightPlan * scale;

	cv::Point plotStartcv{ startX, startY };
	cv::Point plotEndcv{ endX ,endY };

	PlotCarsten::line(image, plotStartcv, plotEndcv, { 0,0,0 }, thickness * 2, lineType);



}

//get Radius
double PlanGeometry_LLT::getRadius()
{
	return 999.0;
}

// calc focal length
void PlanGeometry_LLT::calcFocalLength()
{
	if (mDirectionPlan.getZ() > 0)
	{
		mFocalLength = -999999999999.0;
		mFocalLength_dash =  999999999999.0;
	}

	else
	{
		mFocalLength =  999999999999.0;
		mFocalLength_dash = -999999999999.0;
	}
}

// get focal length side A
real PlanGeometry_LLT::getFocalLength()
{
	return mFocalLength;
}
// get focal length side B
real PlanGeometry_LLT::getFocalLength_dash()
{
	return mFocalLength_dash;
}

// get refractive index side A
real PlanGeometry_LLT::getRefractiveIndex_A()
{
	return mRefractiveIndexA_Plan;
}
// get refractive index side B
real PlanGeometry_LLT::getRefractiveIndex_B()
{
	return mRefractiveIndexB_Plan;
}

PlanGeometry_LLT::PlanGeometry_LLT(PlanGeometry_LLT &source)
{
	if (this == &source)
	{
		return;
	}

	mSemiHeightPlan = source.mSemiHeightPlan;
	mPointPlan = source.mPointPlan;
	mDirectionPlan = source.mDirectionPlan;
	mRefractiveIndexA_Plan = source.mRefractiveIndexA_Plan;
	mRefractiveIndexB_Plan = source.mRefractiveIndexB_Plan;
	PlanGeometry_Qwt_Ptr = source.PlanGeometry_Qwt_Ptr;
	pointsofPlanGeometry = source.pointsofPlanGeometry;

}

PlanGeometry_LLT& PlanGeometry_LLT::operator=(PlanGeometry_LLT& source)
{
	if (this == &source)
	{
		return *this;
	}

	mSemiHeightPlan = source.mSemiHeightPlan;
	mPointPlan = source.mPointPlan;
	mDirectionPlan = source.mDirectionPlan;
	mRefractiveIndexA_Plan = source.mRefractiveIndexA_Plan;
	mRefractiveIndexB_Plan = source.mRefractiveIndexB_Plan;
	PlanGeometry_Qwt_Ptr = source.PlanGeometry_Qwt_Ptr;
	pointsofPlanGeometry = source.pointsofPlanGeometry;

	return *this;
}

PlanGeometry_LLT::PlanGeometry_LLT() {};
PlanGeometry_LLT::~PlanGeometry_LLT() {};
PlanGeometry_LLT::PlanGeometry_LLT(/*semi height*/ double semiHeight,/*point*/ VectorStructR3 point,/*direction*/ VectorStructR3 direction,/*refractive index A*/ double refractiveSideA, /*refractive index B*/ double refractiveSideB) :
	// ToDo Ques Sergej: Was soll passieren, fals mit jemand eine direction von (0,0,0) gibt? Muss ich das überprüfen?
	// Das Gleiche gilt auch für anderen Oberflächen (z.B. Sphäre, Asphäre,...)
	mSemiHeightPlan(semiHeight),
	mPointPlan(point),
	mDirectionPlan(direction),
	mRefractiveIndexA_Plan(refractiveSideA),
	mRefractiveIndexB_Plan(refractiveSideB)
{
	calcSphericalSurfaceQwtCoord();
};

std::shared_ptr<SurfaceIntersectionRay_LLT> PlanGeometry_LLT::clone()
{
	std::shared_ptr<SurfaceIntersectionRay_LLT> planGeometry_LLT(new PlanGeometry_LLT(*this));

	return planGeometry_LLT;
}

void PlanGeometry_LLT::setRadius(real radius)
{
	std::cout << "a plan surface has no radius" << std::endl;
}
void PlanGeometry_LLT::setPosition(VectorStructR3 position)
{
	mPointPlan = position;
}

QPolygonF* PlanGeometry_LLT::getQPolygonFCurve()
{
	return &pointsofPlanGeometry;
}


PlanGeometryQwt* PlanGeometry_LLT::getPointerPlot()
{
	return PlanGeometry_Qwt_Ptr;
};

void PlanGeometry_LLT::calcSphericalSurfaceQwtCoord()
{
	PlanGeometry_Qwt_Ptr = new PlanGeometryQwt(mSemiHeightPlan, mPointPlan, mDirectionPlan);
	pointsofPlanGeometry = PlanGeometry_Qwt_Ptr->getPoints();
}

void PlanGeometry_LLT::setDirection(VectorStructR3 direction)
{
	mDirectionPlan = direction;
}