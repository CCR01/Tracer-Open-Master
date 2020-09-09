#include "PlotOPD.h"

PlotOPD::PlotOPD(std::shared_ptr<SurfaceIntersectionRay_LLT> Aperture, std::shared_ptr<SurfaceIntersectionRay_LLT> exitPupil, OpticalSystemElement OptSysEle,
	VectorStructR3 StartPointLightRay, real centerWavelenth, unsigned int numberLightRay) :
	mAperture(Aperture),
	mExitPupil(exitPupil),
	mOptSysEle(OptSysEle),
	mStartPointLightRay(StartPointLightRay),
	mCenterWavelenth(centerWavelenth),
	mNumberLightRay(numberLightRay)
{
	Light_LLT light;
	light.setWavelength(mCenterWavelenth);

	mOptSysEle.setRefractiveIndexAccordingToWavelength(mCenterWavelenth);
	OpticalSystem_LLT OptSys = mOptSysEle.getLLTconversion_doConversion();

	std::vector<LightRayStruct> lightRayAlong_X_Field = SequentialRayTracing::lightRayAlongX(mStartPointLightRay, mNumberLightRay, mAperture->getPoint().getZ(), -mAperture->getSemiHeight(), mAperture->getSemiHeight(), mCenterWavelenth, 1.0);
	std::vector<LightRayStruct> lightRayAlong_Y_Field = SequentialRayTracing::lightRayAlongY(mStartPointLightRay, mNumberLightRay, mAperture->getPoint().getZ(), -mAperture->getSemiHeight(), mAperture->getSemiHeight(), mCenterWavelenth, 1.0);

	Ray_LLT chiefRayField(mStartPointLightRay, { mStartPointLightRay.getX(), mStartPointLightRay.getY(), mAperture->getPoint().getZ() }, 1.0);
	LightRayStruct chiefLightRayField(light, chiefRayField, 1);

	mOPD = OPD(mExitPupil, OptSys, lightRayAlong_X_Field, lightRayAlong_Y_Field, chiefLightRayField);

	calcMatrixToPlotOPD_X_Plane();
	calcMatrixtoPlotOPD_Y_Plane();
}


PlotOPD::PlotOPD(OPD OPD) :
	mOPD(OPD)
{
	calcMatrixToPlotOPD_X_Plane();
	calcMatrixtoPlotOPD_Y_Plane();
}

// calculate Matrix to plot OPD
void PlotOPD::calcMatrixToPlotOPD_X_Plane()
{


	// point to plot
	cv::Point P;
	// scale points to plot


	// matrix to create the image
	cv::Mat OPD_Image_X_Plane(height, wide, CV_8UC3, cv::Scalar(255, 255, 255));

	// coordinates of line
	cv::Point startL0(0, height / 2);
	cv::Point endL0(wide, height / 2);
	cv::Point startL1(wide / 2, 0);
	cv::Point endL1(wide / 2, height);
	//cv::Point endL2(wide / 11 * 3, height / 6);
	//cv::Point startL3(wide / 11 * 8, height / 6 * 5);
	//cv::Point startL2(wide / 11 * 3, height / 6 * 5);
	//cv::Point endL3(wide / 11 * 8, height / 6);

	unsigned int thickness = 1;
	unsigned int lineType = 8;

	PlotCarsten::line(OPD_Image_X_Plane, startL0, endL0, (0, 0, 0), thickness, lineType);
	PlotCarsten::line(OPD_Image_X_Plane, startL1, endL1, (0, 0, 0), thickness, lineType);
	//Plot::line(OPD_Image, startL2, endL2, (0, 0, 0), thickness, lineType);
	//Plot::line(OPD_Image, startL3, endL3, (0, 0, 0), thickness, lineType);

	unsigned howManyPointsX = mOPD.getPointsOPD_X().size();

	real maxX = PlotCarsten::getMaxValueOfPointX(mOPD.getPointsOPD_X());
	real minX = PlotCarsten::getMinValueOfPointX(mOPD.getPointsOPD_X());

	real maxY = PlotCarsten::getMaxValueOfPointY(mOPD.getPointsOPD_X());
	real minY = PlotCarsten::getMinValueOfPointY(mOPD.getPointsOPD_X());


	real absMaxY;
	if (std::abs(maxY) > std::abs(minY))
	{
		absMaxY = maxY;
	}
	else // if(std::abs(maxY) < std::abs(minY))
	{
		absMaxY = minY;
	}


	// middle of diagram on X achse
	real middleDiagramX_Achse = wide / 2;

	unsigned int vectorSize = mOPD.getPointsOPD_X().size();
	real pointXmiddle = mOPD.getPointsOPD_X().at(vectorSize / 2).x;


	// create matrix to plot OPD_X
	for (unsigned int i = 0; i < howManyPointsX; i++)
	{



		real currentPointX = mOPD.getPointsOPD_X().at(i).x;
		//real refY = mOPD.getRefPoints().getY();

		if (vectorSize / 2 > i)
		{
			real tempOPD = mOPD.getPointsOPD_X().at(i).y;
			real tempScaleOPD;
			if (tempOPD >= 0)
			{
				tempScaleOPD = (height) / 2 - tempOPD / absMaxY * heightOPDF / 2;
			}
			else
			{
				tempScaleOPD = (height) / 2 + tempOPD / absMaxY * heightOPDF / 2;
			}

			real currentScaledPointX = middleDiagramX_Achse + std::abs(currentPointX - pointXmiddle) / (minX - pointXmiddle) * wideOPDFanHalfe;
			cv::Point centerP(currentScaledPointX, tempScaleOPD);
			PlotCarsten::circle(OPD_Image_X_Plane, centerP, 1, (255, 0, 0), 1, 8);
		}
		else
		{
			real tempOPD = mOPD.getPointsOPD_X().at(i).y;
			real tempScaleOPD;
			if (tempOPD >= 0)
			{
				tempScaleOPD = (heightOPDF + 2 * edge) / 2 - tempOPD / absMaxY * heightOPDF / 2;
			}
			else
			{
				tempScaleOPD = (heightOPDF + 2 * edge) / 2 + tempOPD / absMaxY * heightOPDF / 2;
			}

			real currentScaledPointX = middleDiagramX_Achse + std::abs(currentPointX - pointXmiddle) / (maxX - pointXmiddle) * wideOPDFanHalfe;
			cv::Point centerP(currentScaledPointX, tempScaleOPD);
			PlotCarsten::circle(OPD_Image_X_Plane, centerP, 1, (255, 0, 0), 1, 8);
		}

	}

	mImageOPD_X_Plane = OPD_Image_X_Plane;

}


// calculate Matrix to plot OPD in y plane
void PlotOPD::calcMatrixtoPlotOPD_Y_Plane()
{


	// point to plot
	cv::Point P;
	// scale points to plot


	// matrix to create the image
	cv::Mat OPD_Image_Y_Plane(height, wide, CV_8UC3, cv::Scalar(255, 255, 255));

	// coordinates of line
	cv::Point startL0(0, height / 2);
	cv::Point endL0(wide, height / 2);
	cv::Point startL1(wide / 2, 0);
	cv::Point endL1(wide / 2, height);
	//cv::Point endL2(wide / 11 * 3, height / 6);
	//cv::Point startL3(wide / 11 * 8, height / 6 * 5);
	//cv::Point startL2(wide / 11 * 3, height / 6 * 5);
	//cv::Point endL3(wide / 11 * 8, height / 6);

	unsigned int thickness = 1;
	unsigned int lineType = 8;

	PlotCarsten::line(OPD_Image_Y_Plane, startL0, endL0, (0, 0, 0), thickness, lineType);
	PlotCarsten::line(OPD_Image_Y_Plane, startL1, endL1, (0, 0, 0), thickness, lineType);
	//Plot::line(OPD_Image, startL2, endL2, (0, 0, 0), thickness, lineType);
	//Plot::line(OPD_Image, startL3, endL3, (0, 0, 0), thickness, lineType);

	unsigned howManyPointsX = mOPD.getPointsOPD_Y().size();

	real maxX = PlotCarsten::getMaxValueOfPointX(mOPD.getPointsOPD_Y());
	real minX = PlotCarsten::getMinValueOfPointX(mOPD.getPointsOPD_Y());
	real maxY = PlotCarsten::getMaxValueOfPointY(mOPD.getPointsOPD_Y());
	real minY = PlotCarsten::getMinValueOfPointY(mOPD.getPointsOPD_Y());


	real absMaxY;
	if (std::abs(maxY) > std::abs(minY))
	{
		absMaxY = maxY;
	}
	else // if(std::abs(maxY) < std::abs(minY))
	{
		absMaxY = minY;
	}


	// middle of diagram on X achse
	real middleDiagramX_Achse = wide / 2;

	unsigned int vectorSize = mOPD.getPointsOPD_Y().size();
	real pointXmiddle = mOPD.getPointsOPD_Y().at(vectorSize / 2).x;


	// create matrix to plot OPD_Y
	for (unsigned int i = 0; i < howManyPointsX; i++)
	{



		real currentPointX = mOPD.getPointsOPD_Y().at(i).x;
		//real refY = mOPD.getRefPoints().getY();

		if (vectorSize / 2 > i)
		{
			real tempOPD = mOPD.getPointsOPD_Y().at(i).y;
			real tempScaleOPD;
			if (tempOPD >= 0)
			{
				tempScaleOPD = (height) / 2 - tempOPD / absMaxY * heightOPDF / 2;
			}
			else
			{
				tempScaleOPD = (height) / 2 + tempOPD / absMaxY * heightOPDF / 2;
			}

			real currentScaledPointX = middleDiagramX_Achse + std::abs(currentPointX - pointXmiddle) / (minX - pointXmiddle) * wideOPDFanHalfe;
			cv::Point centerP(currentScaledPointX, tempScaleOPD);
			PlotCarsten::circle(OPD_Image_Y_Plane, centerP, 1, (255, 0, 0), 1, 8);
		}
		else
		{
			real tempOPD = mOPD.getPointsOPD_Y().at(i).y;
			real tempScaleOPD;
			if (tempOPD >= 0)
			{
				tempScaleOPD = (heightOPDF + 2 * edge) / 2 - tempOPD / absMaxY * heightOPDF / 2;
			}
			else
			{
				tempScaleOPD = (heightOPDF + 2 * edge) / 2 + tempOPD / absMaxY * heightOPDF / 2;
			}

			real currentScaledPointX = middleDiagramX_Achse + std::abs(currentPointX - pointXmiddle) / (maxX - pointXmiddle) * wideOPDFanHalfe;
			cv::Point centerP(currentScaledPointX, tempScaleOPD);
			PlotCarsten::circle(OPD_Image_Y_Plane, centerP, 1, (255, 0, 0), 1, 8);
		}

	}

	mImageOPD_Y_Plane = OPD_Image_Y_Plane;

}


// get matrix to plot in x plane
cv::Mat PlotOPD::getMatrixToPlotOPD_X_Plane()
{
	return mImageOPD_X_Plane;
}

// get matrix to plot in < plane
cv::Mat PlotOPD::getMatrixToPlotOPD_Y_Plane()
{
	return mImageOPD_Y_Plane;
}


QPolygonF PlotOPD::getPointsVectorPolygon_X_Plane(double scale, double StartX, double StartY)
{

	double howManyPointsX = mOPD.getPointsOPD_X().size();


	double maxX = PlotCarsten::getMaxValueOfPointX(mOPD.getPointsOPD_X());
	double minX = PlotCarsten::getMinValueOfPointX(mOPD.getPointsOPD_X());



	double vectorSize = mOPD.getPointsOPD_X().size();
	double pointXmiddle = mOPD.getPointsOPD_X().at(vectorSize / 2).x;

	QPolygonF OPD_Image_X_Plane_Qwt;
	// create matrix to plot OPD_X
	for (unsigned int i = 0; i < howManyPointsX; i++)
	{

		double currentPointX = mOPD.getPointsOPD_X().at(i).x;
		//real refY = mOPD.getRefPoints().getY();

		if (vectorSize / 2 > i)
		{
			double tempOPD = mOPD.getPointsOPD_X().at(i).y;
			double tempScaleOPD;
			if (tempOPD >= 0)
			{
				tempScaleOPD = (height) / 2 + tempOPD / scale * heightOPDF / 3;
			}
			else
			{
				tempScaleOPD = (height) / 2 - tempOPD / scale * heightOPDF / 3;
			}

			double currentScaledPointX = middleDiagramX_Achse + std::abs(currentPointX - pointXmiddle) / (minX - pointXmiddle) * wideOPDFanHalfe;
			QPointF centerP(currentScaledPointX + StartX, tempScaleOPD + StartY);
			OPD_Image_X_Plane_Qwt << centerP;
		}
		else
		{
			double tempOPD = mOPD.getPointsOPD_X().at(i).y;
			double tempScaleOPD;
			if (tempOPD >= 0)
			{
				tempScaleOPD = (heightOPDF + 2 * edge) / 2 + tempOPD / scale * heightOPDF / 3;
			}
			else
			{
				tempScaleOPD = (heightOPDF + 2 * edge) / 2 - tempOPD / scale * heightOPDF / 3;
			}

			double currentScaledPointX = middleDiagramX_Achse + std::abs(currentPointX - pointXmiddle) / (maxX - pointXmiddle) * wideOPDFanHalfe;
			QPointF centerP(currentScaledPointX + StartX, tempScaleOPD + StartY);
			OPD_Image_X_Plane_Qwt << centerP;
		}

	}

	return OPD_Image_X_Plane_Qwt;


}


QPolygonF PlotOPD::getPointsVectorPolygon_Y_Plane(double scale, double StartX, double StartY)
{




	unsigned howManyPointsX = mOPD.getPointsOPD_Y().size();

	double maxX = PlotCarsten::getMaxValueOfPointX(mOPD.getPointsOPD_Y());
	double minX = PlotCarsten::getMinValueOfPointX(mOPD.getPointsOPD_Y());

	QPolygonF OPD_Image_Y_Plane_Qwt;


	// middle of diagram on X achse

	unsigned int vectorSize = mOPD.getPointsOPD_Y().size();
	double pointXmiddle = mOPD.getPointsOPD_Y().at(vectorSize / 2).x;


	// create matrix to plot OPD_Y
	for (unsigned int i = 0; i < howManyPointsX; i++)
	{
		double currentPointX = mOPD.getPointsOPD_Y().at(i).x;
		//real refY = mOPD.getRefPoints().getY();

		if (vectorSize / 2 > i)
		{
			double tempOPD = mOPD.getPointsOPD_Y().at(i).y;
			double tempScaleOPD;
			if (tempOPD >= 0)
			{
				tempScaleOPD = (height) / 2 + tempOPD / scale * heightOPDF / 3;
			}
			else
			{
				tempScaleOPD = (height) / 2 - tempOPD / scale * heightOPDF / 3;
			}

			double currentScaledPointX = middleDiagramX_Achse + std::abs(currentPointX - pointXmiddle) / (minX - pointXmiddle) * wideOPDFanHalfe;
			QPointF centerP(currentScaledPointX + StartX, tempScaleOPD + StartY);
			OPD_Image_Y_Plane_Qwt << centerP;
		}
		else
		{
			double tempOPD = mOPD.getPointsOPD_Y().at(i).y;
			double tempScaleOPD;
			if (tempOPD >= 0)
			{
				tempScaleOPD = (heightOPDF + 2 * edge) / 2 + tempOPD / scale * heightOPDF / 3;
			}
			else
			{
				tempScaleOPD = (heightOPDF + 2 * edge) / 2 - tempOPD / scale * heightOPDF / 3;
			}

			double currentScaledPointX = middleDiagramX_Achse + std::abs(currentPointX - pointXmiddle) / (maxX - pointXmiddle) * wideOPDFanHalfe;
			QPointF centerP(currentScaledPointX + StartX, tempScaleOPD + StartY);
			OPD_Image_Y_Plane_Qwt << centerP;
		}

	}

	return OPD_Image_Y_Plane_Qwt;
}


double PlotOPD::getScaleOPDPlot()
{


	double maxX = PlotCarsten::getMaxValueOfPointX(mOPD.getPointsOPD_Y());
	double minX = PlotCarsten::getMinValueOfPointX(mOPD.getPointsOPD_Y());

	double maxY = PlotCarsten::getMaxValueOfPointY(mOPD.getPointsOPD_Y());
	double minY = PlotCarsten::getMinValueOfPointY(mOPD.getPointsOPD_Y());



	if (maxY < PlotCarsten::getMaxValueOfPointY(mOPD.getPointsOPD_X()))
	{
		maxY = PlotCarsten::getMaxValueOfPointY(mOPD.getPointsOPD_X());
	}

	if (minY > PlotCarsten::getMinValueOfPointY(mOPD.getPointsOPD_X()))
	{
		minY = PlotCarsten::getMinValueOfPointY(mOPD.getPointsOPD_X());
	}

	double scaleOPD;
	if (std::abs(maxY) > std::abs(minY))
	{
		scaleOPD = maxY;
	}
	else // if(std::abs(maxY) < std::abs(minY))
	{
		scaleOPD = minY;
	}



	return scaleOPD;
}


int PlotOPD::getWavelengthOPD()
{
	return mOPD.getChiefLightRay().getLight_LLT().getWavelength();
}