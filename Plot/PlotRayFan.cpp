#include "PlotRayFan.h"

PlotRayFan::PlotRayFan(std::shared_ptr<SurfaceIntersectionRay_LLT> Aperture, std::shared_ptr<SurfaceIntersectionRay_LLT> EntrancePupil, OpticalSystemElement OptSys, VectorStructR3 StartPointLightRay, real centerWavelenth, unsigned int numberLightRay) :
	mAperture(Aperture),
	mEntrancePupil(EntrancePupil),
	mOptSysEle(OptSys),
	mStartPointLightRay(StartPointLightRay),
	mCenterWavelenth(centerWavelenth),
	mNumberLightRay(numberLightRay)
{
	OpticalSystem_LLT optSys;
	mOptSysEle.setRefractiveIndexAccordingToWavelength(mCenterWavelenth);
	optSys = mOptSysEle.getLLTconversion_doConversion();

	std::vector<LightRayStruct> lightRayAlong_X = SequentialRayTracing::lightRayAlongX(mStartPointLightRay, mNumberLightRay, mAperture->getPoint().getZ(), -mAperture->getSemiHeight(), mAperture->getSemiHeight(), centerWavelenth, curRefInd);
	std::vector<LightRayStruct> lightRayAlong_Y = SequentialRayTracing::lightRayAlongY(mStartPointLightRay, mNumberLightRay, mAperture->getPoint().getZ(), -mAperture->getSemiHeight(), mAperture->getSemiHeight(), centerWavelenth, curRefInd);


	RayFan RayFan(mEntrancePupil, optSys, lightRayAlong_X, lightRayAlong_Y, centerWavelenth);
	mRayFan = RayFan;
	calcYPlanescale();
	calcXPlanescale();
};


PlotRayFan::PlotRayFan(RayFan RayFan) :
	mRayFan(RayFan)
{
	calcYPlanescale();
	calcXPlanescale();
}


//calculate the matrix of the Ray fan in the X plane
QPolygonF PlotRayFan::getRayFanXPlanPoints(double scale, double XStart, double YStart)
{
	unsigned howManyPointsX = mRayFan.getXX().size();

	double maxY = getMaxValueOfPointY(mRayFan.getRayFanXPlanePoints());
	double maxX = getMaxValueOfPointX(mRayFan.getRayFanXPlanePoints());
	double minY = getMinValueOfPointY(mRayFan.getRayFanXPlanePoints());
	double minX = getMinValueOfPointX(mRayFan.getRayFanXPlanePoints());


	// middle of diagram on X achse
	double middleDiagramX_Achse = wide / 2;

	unsigned int vectorSize = mRayFan.getRayFanXPlanePoints().size();
	double pointXmiddle = mRayFan.getRayFanXPlanePoints().at(vectorSize / 2).x();
	double pointYmiddle = mRayFan.getRayFanXPlanePoints().at(vectorSize / 2).y();



	// create matrix to plot RayFan_X
	for (unsigned int i = 0; i < howManyPointsX; i++)
	{
		double currentPointX = mRayFan.getXX().at(i);

		if (vectorSize / 2 > i)
		{
			double tempRayFan = mRayFan.getXY().at(i);
			double tempScaleRayFan;
			if (tempRayFan >= 0)
			{
				tempScaleRayFan = (height) / 2 + tempRayFan / scale * heightRayFan / 3;
			}
			else
			{
				tempScaleRayFan = (height) / 2 - tempRayFan / scale * heightRayFan / 3;
			}

			double currentScaledPointX = middleDiagramX_Achse + std::abs(currentPointX - pointXmiddle) / (minX - pointXmiddle) * wideRayFanHalfe;
			QPointF centerP(currentScaledPointX + XStart, tempScaleRayFan + YStart);
			RayFan_Image_X_Plane_Qwt << centerP;
		}
		if (vectorSize / 2 <= i)
		{
			double tempRayFan = mRayFan.getXY().at(i);
			double tempScaleRayFan;
			if (tempRayFan >= 0)
			{
				tempScaleRayFan = height / 2 - tempRayFan / scale * heightRayFan / 3;
			}
			else
			{
				tempScaleRayFan = height / 2 + tempRayFan / scale * heightRayFan / 3;
			}

			double currentScaledPointX = middleDiagramX_Achse + std::abs(currentPointX - pointXmiddle) / (maxX - pointXmiddle) * wideRayFanHalfe;
			QPointF centerP(currentScaledPointX + XStart, tempScaleRayFan + YStart);
			RayFan_Image_X_Plane_Qwt << centerP;
		}
	}
	return RayFan_Image_X_Plane_Qwt;
};


//calculate the matrix of the Ray fan in the Y plane
QPolygonF PlotRayFan::getRayFanYPlanPoints(double scale, double XStart, double YStart)
{
	unsigned howManyPointsX = mRayFan.getRayFanYPlanePoints().size();
	double maxY = getMaxValueOfPointY(mRayFan.getRayFanYPlanePoints());
	double maxX = getMaxValueOfPointX(mRayFan.getRayFanYPlanePoints());
	double minY = getMinValueOfPointY(mRayFan.getRayFanYPlanePoints());
	double minX = getMinValueOfPointX(mRayFan.getRayFanYPlanePoints());




	// middle of diagram on X achse
	double middleDiagramX_Achse = wide / 2;
	unsigned int vectorSize = mRayFan.getRayFanYPlanePoints().size();


	double pointXmiddle = mRayFan.getRayFanYPlanePoints().at(vectorSize / 2).x();
	double pointYmiddle = mRayFan.getRayFanYPlanePoints().at(vectorSize / 2).y();



	// create matrix to plot OPD_X
	for (unsigned int i = 0; i < howManyPointsX; i++)
	{

		double currentPointX = mRayFan.getRayFanYPlanePoints().at(i).x();


		if (vectorSize / 2 > i)
		{
			double tempRayFan = mRayFan.getRayFanYPlanePoints().at(i).y();
			double tempScaleRayFan;
			if (tempRayFan >= 0)
			{
				tempScaleRayFan = (height) / 2 + tempRayFan / scale * heightRayFan / 3;
			}
			else
			{
				tempScaleRayFan = (height) / 2 - tempRayFan / scale * heightRayFan / 3;
			}

			double currentScaledPointX = middleDiagramX_Achse + std::abs(currentPointX - pointXmiddle) / (minX - pointXmiddle) * wideRayFanHalfe;
			QPointF centerP(currentScaledPointX + XStart, tempScaleRayFan + YStart);
			RayFan_Image_Y_Plane_Qwt << centerP;
		}
		if (vectorSize / 2 <= i)
		{
			double tempRayFan = mRayFan.getRayFanYPlanePoints().at(i).y();

			double tempScaleRayFan;
			if (tempRayFan >= 0)
			{
				tempScaleRayFan = height / 2 - tempRayFan / scale * heightRayFan / 3;
			}
			else
			{
				tempScaleRayFan = height / 2 + tempRayFan / scale * heightRayFan / 3;
			}

			double currentScaledPointX = middleDiagramX_Achse + std::abs(currentPointX - pointXmiddle) / (maxX - pointXmiddle) * wideRayFanHalfe;
			QPointF centerP(currentScaledPointX + XStart, tempScaleRayFan + YStart);
			RayFan_Image_Y_Plane_Qwt << centerP;
		}
	}
	return RayFan_Image_Y_Plane_Qwt;
};



double  PlotRayFan::getMaxValueOfPointX(QPolygonF points)
{

	double outputMax = points.at(0).x();
	for (unsigned int i = 1; i < points.size(); i++)
	{
		double tempPointX = points.at(i).x();
		if (tempPointX > outputMax)
		{
			outputMax = tempPointX;
		}
	}

	return outputMax;

}

double  PlotRayFan::getMaxValueOfPointY(QPolygonF points)
{

	double outputMax = points.at(0).y();
	for (unsigned int i = 1; i < points.size(); i++)
	{
		double tempPointY = points.at(i).y();
		if (tempPointY > outputMax)
		{
			outputMax = tempPointY;
		}
	}

	return outputMax;

}

double  PlotRayFan::getMinValueOfPointX(QPolygonF points)
{

	double outputMin = points.at(0).x();
	for (unsigned int i = 1; i < points.size(); i++)
	{
		double tempPointX = points.at(i).x();
		if (tempPointX < outputMin)
		{
			outputMin = tempPointX;
		}
	}

	return outputMin;

}

double  PlotRayFan::getMinValueOfPointY(QPolygonF points)
{

	double outputMin = points.at(0).y();
	for (unsigned int i = 1; i < points.size(); i++)
	{
		double tempPointY = points.at(i).y();
		if (tempPointY < outputMin)
		{
			outputMin = tempPointY;
		}
	}

	return outputMin;

}


double  PlotRayFan::getScaleRayFanPlot()
{
	double outputscale = outputScaleXPlane;


	if (outputScaleXPlane < outputScaleYPlane)
	{
		outputscale = outputScaleYPlane;
	}

	return outputscale;
}

void PlotRayFan::calcYPlanescale()
{
	double maxY = getMaxValueOfPointY(mRayFan.getRayFanYPlanePoints());
	double maxX = getMaxValueOfPointX(mRayFan.getRayFanYPlanePoints());
	double minY = getMinValueOfPointY(mRayFan.getRayFanYPlanePoints());
	double minX = getMinValueOfPointX(mRayFan.getRayFanYPlanePoints());

	double absMaxY = minY;
	if (std::abs(maxY) > std::abs(minY))
	{
		absMaxY = maxY;
	}

	outputScaleYPlane = absMaxY;
}




void PlotRayFan::calcXPlanescale()
{
	double maxY = getMaxValueOfPointY(mRayFan.getRayFanXPlanePoints());
	double maxX = getMaxValueOfPointX(mRayFan.getRayFanXPlanePoints());
	double minY = getMinValueOfPointY(mRayFan.getRayFanXPlanePoints());
	double minX = getMinValueOfPointX(mRayFan.getRayFanXPlanePoints());

	double absMaxY = minY;
	if (std::abs(maxY) > std::abs(minY))
	{
		absMaxY = maxY;
	}

	outputScaleXPlane = absMaxY;
}

double PlotRayFan::getWavelength()
{
	return mRayFan.getRayFanWavelength();
}