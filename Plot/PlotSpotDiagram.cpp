#include "PlotSpotDiagram.h"
#include "..\LowLevelTracing\Math_LLT.h"
#include <iostream>
#include "..\..\FillAptertureStop\FillApertureStop.h"
#include "..\SequentialRayTracing\SequentialRayTracer.h"

PlotSpotDiagramm::PlotSpotDiagramm(std::shared_ptr<SurfaceIntersectionRay_LLT> Aperture, OpticalSystemElement OptSys, VectorStructR3 StartPointLightRay, real centerWavelenth) :
	mAperture(Aperture),
	mOptSysElement(OptSys),
	mStartPointLightRay(StartPointLightRay),
	mCenterWavelenth(centerWavelenth)
{
	Light_LLT light;
	light.setWavelength(mCenterWavelenth);

	OpticalSystem_LLT OpticalSys;
	mOptSysElement.setRefractiveIndexAccordingToWavelength(mCenterWavelenth);
	OpticalSys = mOptSysElement.getLLTconversion_doConversion();

	FillApertureStop fillAperStop(StartPointLightRay, Aperture->getSemiHeight(), Aperture->getPoint(), Aperture->getDirection(), numberOfRings, numberOfArms, refractiveIndex, light);
	SequentialRayTracing seqTrace(OpticalSys);
	seqTrace.seqRayTracingWithVectorOfLightRays(fillAperStop.getVectorWithLightRays());
	Spot spot(seqTrace.getAllInterPointsAtSurface_i_filtered(OpticalSys.getNumberOfSurfaces()), seqTrace.getAllInterPointsAtSurface_i_filtered(OpticalSys.getNumberOfSurfaces()).at(0));
	mVectorSpot = { spot };
	mInterPointChefRay = spot.getRefPoint();
	mNA = 0.09950372;
	mScaleSpotDia = calculateScaleSpotDia();
	calcMatrixToPlot();
};

PlotSpotDiagramm::PlotSpotDiagramm(VectorStructR3 interPointChefRay, std::vector<Spot> vectorSpot, real numericalApertur, real centerWavelenth) :
	mInterPointChefRay(interPointChefRay),
	mVectorSpot(vectorSpot),
	mNA(numericalApertur),
	mCenterWavelenth(centerWavelenth)
{
	mScaleSpotDia = calculateScaleSpotDia();
	calcMatrixToPlot();
}


double PlotSpotDiagramm::getWavelength()
{
	return mCenterWavelenth;
}

Spot PlotSpotDiagramm::getSpot()
{
	return mVectorSpot[0];
}

// calculate scale spot diagram
real PlotSpotDiagramm::calculateScaleSpotDia()
{
	real outputScale;
	unsigned int howManySpots = mVectorSpot.size();
	std::vector<real> vecScale;

	for (unsigned int i = 0; i < howManySpots; i++)
	{

		//***************************************************
		// scale the spot diagram
		std::vector<VectorStructR3> const& allInterPoints = mVectorSpot.at(i).getAllInterPoints();
		VectorStructR3 absMax_X_Y_Z = Math::findMaxDelta_X_Y_Z_inStdV_VectorStructR3(allInterPoints, mInterPointChefRay);

		real deltaAbsMax_X_Z = absMax_X_Y_Z.getX() + absMax_X_Y_Z.getZ();
		real deltaAbsMax_Y_Z = absMax_X_Y_Z.getY() + absMax_X_Y_Z.getZ();


		// to scale the spot diagramm we just use the absMax_X and absMax_Y
		real tempscale = deltaAbsMax_X_Z;
		if (tempscale < deltaAbsMax_Y_Z)
		{
			tempscale = deltaAbsMax_Y_Z;
		}
		//***************************************************

		vecScale.push_back(tempscale);
	}

	outputScale = Math::maxValueOfVactor(vecScale);

	return outputScale;
}


void PlotSpotDiagramm::calcMatrixToPlot()
{
	unsigned int wideOfSpotDia = mWide - 2 * mEdge;
	unsigned int heightOfSpotDia = mHeight - 2 * mEdge;
	// point to plot
	cv::Point P;


	// matrix to create the image
	cv::Mat spotImage(mHeight, mWide, CV_8UC3, cv::Scalar(255, 255, 255));



	// the reference point (chief ray) must be in the center of the diagram
	real const& coorRefPoint_X = mInterPointChefRay.getX();
	real const& coorRefPoint_Y = mInterPointChefRay.getY();
	real const& coorRefPoint_Z = mInterPointChefRay.getZ();

	unsigned int howManySpots = mVectorSpot.size();
	unsigned int i = 0;


	for (i; i < howManySpots; i++)
	{
		unsigned int howManyPoints = mVectorSpot.at(i).getAllInterPoints().size();
		std::vector<VectorStructR3> allInterPoints = mVectorSpot.at(i).getAllInterPoints();

		for (unsigned int point = 0; point < howManyPoints; point++)

		{

			real deltaX = allInterPoints.at(point).getX() - coorRefPoint_X;
			real deltaY = allInterPoints.at(point).getY() - coorRefPoint_Y;
			real deltaZ = allInterPoints.at(point).getZ() - coorRefPoint_Z;


			// set the prefix
			int prefixX = 1;
			int prefixY = 1;
			if (deltaX < 0) prefixX = -1;
			if (deltaY < 0) prefixY = -1;

			real sqrtX = std::sqrt(std::pow(deltaX, 2) + std::pow(deltaZ, 2));
			real sqrtY = std::sqrt(std::pow(deltaY, 2) + std::pow(deltaZ, 2));

			real x = mWide / 2 - (prefixX * sqrtX / mScaleSpotDia * wideOfSpotDia / 2);
			real y = mWide / 2 - (prefixY * sqrtY / mScaleSpotDia * heightOfSpotDia / 2);

			P.x = x;
			P.y = y;
			PlotCarsten::circle(spotImage, P, mHeight / 500, { 255,0,0 }, 3, 8);

			VectorStructR2 pt;
			pt.setX(x);
			pt.setY(-y);
			mPoints.push_back(pt);
		}

	}

	mAllSpotImages = spotImage;

}

// get matrix to plot
cv::Mat PlotSpotDiagramm::getMatrixToPlotSpot()
{
	return mAllSpotImages;
}

std::vector<VectorStructR2> PlotSpotDiagramm::getPointsVector()
{
	/*unsigned int wideOfSpotDia = mWide - 2 * mEdge;
	unsigned int heightOfSpotDia = mHeight - 2 * mEdge;



	// the reference point (chief ray) must be in the center of the diagram
	real const& coorRefPoint_X = mInterPointChefRay.getX();
	real const& coorRefPoint_Y = mInterPointChefRay.getY();
	real const& coorRefPoint_Z = mInterPointChefRay.getZ();

	unsigned int howManySpots = mVectorSpot.size();
	unsigned int i = 0;


	for (i; i < howManySpots; i++)
	{
		unsigned int howManyPoints = mVectorSpot.at(i).getAllInterPoints().size();
		std::vector<VectorStructR3> allInterPoints = mVectorSpot.at(i).getAllInterPoints();

		for (unsigned int point = 0; point < howManyPoints; point++)

		{

			real deltaX = allInterPoints.at(point).getX() - coorRefPoint_X;
			real deltaY = allInterPoints.at(point).getY() - coorRefPoint_Y;
			real deltaZ = allInterPoints.at(point).getZ() - coorRefPoint_Z;


			// set the prefix
			int prefixX = 1;
			int prefixY = 1;
			if (deltaX < 0) prefixX = -1;
			if (deltaY < 0) prefixY = -1;

			real sqrtX = std::sqrt(std::pow(deltaX, 2) + std::pow(deltaZ, 2));
			real sqrtY = std::sqrt(std::pow(deltaY, 2) + std::pow(deltaZ, 2));

			real x = mWide / 2 - (prefixX * sqrtX / scale * wideOfSpotDia / 2);
			real y = mWide / 2 - (prefixY * sqrtY / scale * heightOfSpotDia / 2);



			VectorStructR2 pt;
			pt.setX(x);
			pt.setY(-y);
			mPoints.push_back(pt);
		}
	}*/

	return mPoints;
}

QPolygonF PlotSpotDiagramm::getPointsVectorPolygon(double scale, double intx, double inty)
{

	QPolygonF mPointsscaled;

	unsigned int wideOfSpotDia = mWide - 2 * mEdge;
	unsigned int heightOfSpotDia = mHeight - 2 * mEdge;


	// the reference point (chief ray) must be in the center of the diagram
	real const& coorRefPoint_X = mInterPointChefRay.getX();
	real const& coorRefPoint_Y = mInterPointChefRay.getY();
	real const& coorRefPoint_Z = mInterPointChefRay.getZ();

	unsigned int howManySpots = mVectorSpot.size();
	unsigned int i = 0;


	for (i; i < howManySpots; i++)
	{
		unsigned int howManyPoints = mVectorSpot.at(i).getAllInterPoints().size();
		std::vector<VectorStructR3> allInterPoints = mVectorSpot.at(i).getAllInterPoints();

		for (unsigned int point = 0; point < howManyPoints; point++)

		{

			real deltaX = allInterPoints.at(point).getX() - coorRefPoint_X;
			real deltaY = allInterPoints.at(point).getY() - coorRefPoint_Y;
			real deltaZ = allInterPoints.at(point).getZ() - coorRefPoint_Z;


			// set the prefix
			int prefixX = 1;
			int prefixY = 1;
			if (deltaX < 0) prefixX = -1;
			if (deltaY < 0) prefixY = -1;

			real sqrtX = std::sqrt(std::pow(deltaX, 2) + std::pow(deltaZ, 2));
			real sqrtY = std::sqrt(std::pow(deltaY, 2) + std::pow(deltaZ, 2));

			real x = mWide / 2 - (prefixX * sqrtX / scale * wideOfSpotDia / 2) + intx;
			real y = mWide / 2 - (prefixY * sqrtY / scale * heightOfSpotDia / 2) - inty - 400;

			mPointsscaled << QPointF(x, -y);
		}

	}


	return mPointsscaled;
}

void PlotSpotDiagramm::setmaxScale(int scale)
{
	mscale = scale;

}