#pragma once
#include "../LowLevelTracing/ImportantStructures.h"
#include <vector>
#include "..\Plot\Plot.h"
#include <qwt_plot_curve.h>
#include "..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\LowLevelTracing\ImportantStructures.h"
#include "..\LowLevelTracing\Math_LLT.h"
#include "..\LowLevelTracing\OpticalSystem_LLT.h"
// plot
#include "..\..\Plot\PlotSpotDiagram.h"
#include "..\..\Plot\PlotOPD.h"

class RayFan {
public:
	RayFan() {};
	RayFan(std::shared_ptr<SurfaceIntersectionRay_LLT> EntrancePupil, OpticalSystem_LLT optSys, std::vector<LightRayStruct> lightRayAlong_X, std::vector<LightRayStruct> lightRayAlong_Y):
		mEntrancePupil(EntrancePupil),
		mOptSys(optSys),
		mLightRayX(lightRayAlong_X),
		mLightRayY(lightRayAlong_Y)
	{
		
		mPosImageSurface = mOptSys.getNumberOfSurfaces();
		mPosEnPupilInOptSys = calcPosEnPupil_Z();
		
		//***
		
		mOptSysWithEntrancePupil = mOptSys;
		mOptSysWithEntrancePupil.fillInSurfaceAndInteracAtPos_i(mPosEnPupilInOptSys, mEntrancePupil, mDoNothingInteraction_ptr);
		//***

		
		calcMatrixRayFanPlane();
		
	}
	~RayFan() {};

	//calculate the maximum at the X plane of a vector of vectors
	double calcMaxX(std::vector<VectorStructR3> vector);
	double calcMaxY(std::vector<VectorStructR3> vector);
	//calculate the Z position of the entrance pupil
	int calcPosEnPupil_Z();

	//calculate the coordinates of the ray fan points 
	void calcMatrixRayFanPlane();

	//return the points of the ray fan plot in the X axis
	QPolygonF getRayFanXPlanePoints();

	//return the points of the ray fan plot in the X axis
	QPolygonF getRayFanYPlanePoints();

	//get the X values of the points of the X axis
	QVector<double> getXX();

	//get the X values of the points of the Y axis
	QVector<double> getXY();

	//get the Y values of the points on the X axis
	QVector<double> getYX();

	//get the Y values of the points on the Y axis
	QVector<double> getYY();

private:
	// hight 
	unsigned int mHeight = 400;
	// wide
	unsigned int mWide = 400;
	unsigned int mEdge = 20;
	QVector <double> X_Values_X_Plane;
	QVector <double> Y_Values_X_Plane;
	QVector <double> X_Values_Y_Plane;
	QVector <double> Y_Values_Y_Plane;

	QPolygonF Ray_Image_X_Plane_Qwt;
	QPolygonF Ray_Image_Y_Plane_Qwt;

	OpticalSystem_LLT mOptSys;
	OpticalSystem_LLT mOptSysWithEntrancePupil;
	VectorStructR3 mChiefRayAtImage;
	VectorStructR3 mChiefRayAtEntrancePupil_X_Plane;
	VectorStructR3 mChiefRayAtEntrancePupil_Y_Plane;
	std::vector<LightRayStruct> mLightRayX;
	std::vector<LightRayStruct> mLightRayY;
	LightRayStruct mChiefLightRay;
	std::shared_ptr<SurfaceIntersectionRay_LLT> mEntrancePupil;
	DoNothingInteraction_LLT doNothingInter;
	std::shared_ptr<InteractionRay_LLT> mDoNothingInteraction_ptr = doNothingInter.clone();
	int mPosImageSurface;
	int mPosEnPupilInOptSys;
	real mRadiusRefSphere;
	SphericalSurface_LLT mRefSphere;
};


