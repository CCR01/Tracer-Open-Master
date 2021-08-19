#pragma once
#include "..\SurfaceIntersectionRay_LLT.h"
#include "..\Math_LLT.h"
#include <iostream>
#include "..\..\Plot\Plot2D.h"

class AsphericalSurfaceQwt : public QwtPlotCurve
{
public:
	AsphericalSurfaceQwt(double radius, double semiHeight, VectorStructR3  point, VectorStructR3  direction, double  conic,
		double  A1, double  A2, double  A3, double  A4, double  A5, double  A6,
		double  A7, double  A8);
	//return the points coordinates of the aspherical surface
	virtual QPolygonF points(double radius, double semiHeight, VectorStructR3  point, VectorStructR3  direction, double  conic,
		double  A1, double  A2, double  A3, double  A4, double  A5, double  A6,
		double  A7, double  A8);

private:
	QPolygonF AsphericalSurfacePoints;
};

struct is_Z_ValueAsphere
{
	double Z_Value;
	int yesNo; //yes=1, no=0
};

struct isDerivationAsphere
{
	double derivation;
	double getDerivation() const;
	int yesNo;
};


class AsphericalSurface_LLT : public SurfaceIntersectionRay_LLT {
public:
	AsphericalSurface_LLT();
	AsphericalSurface_LLT& operator=(AsphericalSurface_LLT& source);
	AsphericalSurface_LLT(AsphericalSurface_LLT &source);
	std::shared_ptr<SurfaceIntersectionRay_LLT> clone() override;
	virtual ~AsphericalSurface_LLT() override;
	AsphericalSurface_LLT(/*radius*/ double radius, /*semi height*/ double semiHeight,/*point*/ VectorStructR3  point, /*direction*/ VectorStructR3  direction,/*refractive index A*/ double refractiveSideA,/*refractive index B*/ double refractiveSideB,/*conic*/ double  conic,
		/*second order term*/ double  A1, /*fourth order term*/ double  A2, /*sixth order term*/ double  A3, /*eighth order term*/ double  A4,/*tenth order term*/ double  A5,/*twelfth oder term*/ double  A6,
		/*fourteenth order term*/ double  A7,/*sixteenth order tem*/ double  A8);

	//get radius asphere
	virtual real getRadius() override;
	//set radius asphere
	void setRadiusAsphere(real const radius);
	// get semi height asphere
	real getSemiHeight() override;
	//set semi height asphere
	void setSemiHeight(real semiHeigth);
	// get point asphere
	VectorStructR3 getPoint() override;
	// set point asphere
	void setPoint(VectorStructR3 point);
	// set direction asphere unit
	void setDirectionUnitAsphere(VectorStructR3 direction);
	//get direction asphere
	VectorStructR3 getDirection() override;
	//get refractive index side A
	real getRefracIndexAsphere_A() const;
	//set refractive index side A
	virtual void setRefractiveIndexSide_A(real const refractiveIndex) override;
	//get refractive index side B
	real getRefracIndexAsphere_B() const;
	//set refractive index side B
	virtual void setRefractiveIndexSide_B(real const refractiveIndex) override;
	//get conic
	real getConic() const;
	//set conic
	void setConic(real const conic);
	//get A1
	real getA1() const;
	//set A1
	void setA1(real const A1);
	//get A2
	real getA2() const;
	//set A2
	void setA2(real const A2);
	//get A3
	real getA3() const;
	//set A3
	void setA3(real const A3);
	//get A4
	real getA4() const;
	//set A4
	void setA4(real const A4);
	//get A5
	real getA5() const;
	//set A5
	void setA5(real const A5);
	//get A6
	real getA6() const;
	//set A6
	void setA6(real const A6);
	//get A7
	real getA7() const;
	//set A7
	void setA7(real const A7);
	//get A8
	real getA8() const;
	//set A8
	void setA8(real const A8);

	//set and get the prefix of the aspherical lens.
	void setPrefixAsphere(VectorStructR3 V);
	int getPrefixAsphere();

	/* We have to calculate the intersection point of a ray with an aspherical surface in a numerical-iterative way*/
	/* You can find our approuch in "Handbook of Optical System, Volume 1 -> 5.3.7 */
	virtual IntersectInformationStruct calculateIntersection(LightRayStruct const lightRay) override;
	//calculate z of an aspherical surface in point Q projected on the aspherical surface
	is_Z_ValueAsphere calc_Z_ValueAsphere(double const x, double const y);
	// Projection of a point in z direction
	VectorStructR3 Q_projection(double const x, double const y, double const z);
	// Calculate rise of asphere in x-direction
	isDerivationAsphere rise_X_AsphericalSurface(double const x, double const y);
	// Calculate rise of asphere in Y-direction
	isDerivationAsphere rise_Y_AsphericalSurface(double const x, double const y);

	// get focal length side A
	virtual real getFocalLength() override;
	// get focal length side B
	virtual real getFocalLength_dash() override;
	// calc focal length
	virtual void calcFocalLength() override;
	// get refractive index side A
	virtual real getRefractiveIndex_A() override;
	// get refractive index side B
	virtual real getRefractiveIndex_B() override;

	virtual void setRadius(real radius) override;
	virtual void setPosition(VectorStructR3 position) override;
	virtual void setDirection(VectorStructR3 direction) override;

	// make the 2d plot
	void plot2D(cv::Mat image, unsigned int scale, unsigned int thickness, unsigned int lineType) override;

	//get the pointer of the qwt curve
	virtual AsphericalSurfaceQwt* getPointerPlot();

	//get QPolygonF of the surface
	virtual QPolygonF* getQPolygonFCurve();

	void calcAsphericalSurfaceQwtCoord();

	virtual std::string getSurfaceType() override;

private:
	double mRadiusAsphere;
	double mSemiHeightAsphere;
	VectorStructR3 mPointAsphere;
	VectorStructR3 mDirectionAsphereUnit;
	VectorStructR3 mDirectionAsphere;
	double mRefractiveSideA_Asphere;
	double mRefractiveSideB_Asphere;
	double mConic;
	double m_A1;
	double m_A2;
	double m_A3;
	double m_A4;
	double m_A5;
	double m_A6;
	double m_A7;
	double m_A8;

	double mFocalLength;
	double mFocalLength_dash;

	int mPrefix;
	AsphericalSurfaceQwt* AsphericalSurfaceQwt_Ptr = new AsphericalSurfaceQwt(mRadiusAsphere, mSemiHeightAsphere, mPointAsphere,
		mDirectionAsphere, mConic, m_A1, m_A2, m_A3, m_A4, m_A5, m_A6, m_A7, m_A8);
	QPolygonF pointsofASphericalSurface = AsphericalSurfaceQwt_Ptr->points(mRadiusAsphere, mSemiHeightAsphere, mPointAsphere,
		mDirectionAsphere, mConic, m_A1, m_A2, m_A3, m_A4, m_A5, m_A6, m_A7, m_A8);
};