#include "PlotOPD.h"

//set Image name
void  CommentandPosCommentToPlotInOPD::setComment(QString Comment)
{
	mComment = Comment;
}
//get Image name
QString  CommentandPosCommentToPlotInOPD::getComment()
{
	return mComment;
}
// set PlotSpot Diagramm
void  CommentandPosCommentToPlotInOPD::setPositionComment(VectorStructR2 PositionComment)
{
	mPositionComment = PositionComment;
}
//get Plot Spot Diagramm
VectorStructR2  CommentandPosCommentToPlotInOPD::getPositionComment()
{
	return mPositionComment;
}


// calculate Matrix to plot OPD
void PlotOPD::calcMatrixToPlotOPD_X_Plane()
{

	unsigned int edge = 20;
	// hight 
	unsigned int height = 500;
	unsigned int heightOPDF = height - 2 * edge;
	// wide
	unsigned int wide = 500;
	unsigned int wideOPDFanHalfe = (wide - 2 * edge) / 2;
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

	unsigned int edge = 20;
	// hight 
	unsigned int height = 500;
	unsigned int heightOPDF = height - 2 * edge;
	// wide
	unsigned int wide = 500;
	unsigned int wideOPDFanHalfe = (wide - 2 * edge) / 2;
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


QPolygonF PlotOPD::getPointsVectorPolygon_X_Plane()
{
	double edge = 20;
	// hight 
	double height = 500;
	double heightOPDF = height - 2 * edge;
	// wide
	double wide = 500;
	double wideOPDFanHalfe = (wide - 2 * edge) / 2;

	double symmetrie = height / 2;

	unsigned howManyPointsX = mOPD.getPointsOPD_X().size();

	double maxX = PlotCarsten::getMaxValueOfPointX(mOPD.getPointsOPD_X());
	double minX = PlotCarsten::getMinValueOfPointX(mOPD.getPointsOPD_X());

	double maxY = PlotCarsten::getMaxValueOfPointY(mOPD.getPointsOPD_X());
	double minY = PlotCarsten::getMinValueOfPointY(mOPD.getPointsOPD_X());



	if (maxX < PlotCarsten::getMaxValueOfPointX(mOPD.getPointsOPD_X()))
	{
		maxX = PlotCarsten::getMaxValueOfPointX(mOPD.getPointsOPD_X());
	}

	if (minX > PlotCarsten::getMinValueOfPointX(mOPD.getPointsOPD_X()))
	{
		minX = PlotCarsten::getMinValueOfPointX(mOPD.getPointsOPD_X());
	}

	if (maxY < PlotCarsten::getMaxValueOfPointY(mOPD.getPointsOPD_X()))
	{
		maxY = PlotCarsten::getMaxValueOfPointY(mOPD.getPointsOPD_X());
	}

	if (minY > PlotCarsten::getMinValueOfPointY(mOPD.getPointsOPD_X()))
	{
		minY = PlotCarsten::getMinValueOfPointY(mOPD.getPointsOPD_X());
	}


	// scale points to plot



	double absMaxY;
	if (std::abs(maxY) > std::abs(minY))
	{
		absMaxY = maxY;
	}
	else // if(std::abs(maxY) < std::abs(minY))
	{
		absMaxY = minY;
	}



	// middle of diagram on X achse
	double middleDiagramX_Achse = wide / 2;

	unsigned int vectorSize = mOPD.getPointsOPD_X().size();
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
				tempScaleOPD = (height) / 2 + tempOPD / absMaxY * heightOPDF / 2;
			}
			else
			{
				tempScaleOPD = (height) / 2 - tempOPD / absMaxY * heightOPDF / 2;
			}

			double currentScaledPointX = middleDiagramX_Achse + std::abs(currentPointX - pointXmiddle) / (minX - pointXmiddle) * wideOPDFanHalfe + 550;
			QPointF centerP(currentScaledPointX, tempScaleOPD);
			OPD_Image_X_Plane_Qwt << centerP;
		}
		else
		{
			double tempOPD = mOPD.getPointsOPD_X().at(i).y;
			double tempScaleOPD;
			if (tempOPD >= 0)
			{
				tempScaleOPD = (heightOPDF + 2 * edge) / 2 + tempOPD / absMaxY * heightOPDF / 2;
			}
			else
			{
				tempScaleOPD = (heightOPDF + 2 * edge) / 2 - tempOPD / absMaxY * heightOPDF / 2;
			}

			double currentScaledPointX = middleDiagramX_Achse + std::abs(currentPointX - pointXmiddle) / (maxX - pointXmiddle) * wideOPDFanHalfe + 550;
			QPointF centerP(currentScaledPointX, tempScaleOPD);
			OPD_Image_X_Plane_Qwt << centerP;
		}

	}

	return OPD_Image_X_Plane_Qwt;


}


QPolygonF PlotOPD::getPointsVectorPolygon()
{
	double edge = 20;
	// hight 
	double height = 500;
	double heightOPDF = height - 2 * edge;
	// wide
	double wide = 500;
	double wideOPDFanHalfe = (wide - 2 * edge) / 2;

	double symmetrie = height / 2;



	unsigned howManyPointsX = mOPD.getPointsOPD_Y().size();

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

	QPolygonF OPD_Image_Y_Plane_Qwt;

	double absMaxY;
	if (std::abs(maxY) > std::abs(minY))
	{
		absMaxY = maxY;
	}
	else // if(std::abs(maxY) < std::abs(minY))
	{
		absMaxY = minY;
	}


	// middle of diagram on X achse
	double middleDiagramX_Achse = wide / 2;

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
				tempScaleOPD = (height) / 2 + tempOPD / absMaxY * heightOPDF / 2;
			}
			else
			{
				tempScaleOPD = (height) / 2 - tempOPD / absMaxY * heightOPDF / 2;
			}

			double currentScaledPointX = middleDiagramX_Achse + std::abs(currentPointX - pointXmiddle) / (minX - pointXmiddle) * wideOPDFanHalfe;
			QPointF centerP(currentScaledPointX, tempScaleOPD - 20);
			OPD_Image_Y_Plane_Qwt << centerP;
		}
		else
		{
			double tempOPD = mOPD.getPointsOPD_Y().at(i).y;
			double tempScaleOPD;
			if (tempOPD >= 0)
			{
				tempScaleOPD = (heightOPDF + 2 * edge) / 2 + tempOPD / absMaxY * heightOPDF / 2;
			}
			else
			{
				tempScaleOPD = (heightOPDF + 2 * edge) / 2 - tempOPD / absMaxY * heightOPDF / 2;
			}

			double currentScaledPointX = middleDiagramX_Achse + std::abs(currentPointX - pointXmiddle) / (maxX - pointXmiddle) * wideOPDFanHalfe;
			QPointF centerP(currentScaledPointX, tempScaleOPD - 20);
			OPD_Image_Y_Plane_Qwt << centerP;
		}

	}





	howManyPointsX = mOPD.getPointsOPD_X().size();


	maxX = PlotCarsten::getMaxValueOfPointX(mOPD.getPointsOPD_X());
	minX = PlotCarsten::getMinValueOfPointX(mOPD.getPointsOPD_X());

	vectorSize = mOPD.getPointsOPD_X().size();
	pointXmiddle = mOPD.getPointsOPD_X().at(vectorSize / 2).x;

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
				tempScaleOPD = (height) / 2 + tempOPD / absMaxY * heightOPDF / 2;
			}
			else
			{
				tempScaleOPD = (height) / 2 - tempOPD / absMaxY * heightOPDF / 2;
			}

			double currentScaledPointX = middleDiagramX_Achse + std::abs(currentPointX - pointXmiddle) / (minX - pointXmiddle) * wideOPDFanHalfe + 550;
			QPointF centerP(currentScaledPointX, tempScaleOPD - 20);
			OPD_Image_Y_Plane_Qwt << centerP;
		}
		else
		{
			double tempOPD = mOPD.getPointsOPD_X().at(i).y;
			double tempScaleOPD;
			if (tempOPD >= 0)
			{
				tempScaleOPD = (heightOPDF + 2 * edge) / 2 + tempOPD / absMaxY * heightOPDF / 2;
			}
			else
			{
				tempScaleOPD = (heightOPDF + 2 * edge) / 2 - tempOPD / absMaxY * heightOPDF / 2;
			}

			double currentScaledPointX = middleDiagramX_Achse + std::abs(currentPointX - pointXmiddle) / (maxX - pointXmiddle) * wideOPDFanHalfe + 550;
			QPointF centerP(currentScaledPointX, tempScaleOPD - 20);
			OPD_Image_Y_Plane_Qwt << centerP;
		}

	}



	return OPD_Image_Y_Plane_Qwt;
}

void PlotOPD::AddCommentToOPDPlot(QString comment, VectorStructR2 position)
{
	CommentandPosCommentToPlotInOPD CommentInfo;
	CommentInfo.setComment(comment);
	CommentInfo.setPositionComment(position);
	mCommentandPosCommentToPlot.push_back(CommentInfo);
}

std::vector<CommentandPosCommentToPlotInOPD> PlotOPD::getVectorComments()
{
	return mCommentandPosCommentToPlot;
}

void PlotOPD::setSymbolColor(QBrush SymbolColor)
{
	mSymbolColorOPD = SymbolColor;
}
QBrush PlotOPD::getSymbolColor()
{
	return mSymbolColorOPD;
}
void PlotOPD::setSymbolStyle(QwtSymbol::Style SymbolStyle)
{
	mSymbolStyleOPD = SymbolStyle;
}
QwtSymbol::Style PlotOPD::getSymbolStyle()
{
	return mSymbolStyleOPD;
}
void PlotOPD::setContourColorSymbol(QPen SymbolPen)
{
	mSymbolPenOPD = SymbolPen;
}
QPen PlotOPD::getContourColorSymbol()
{
	return mSymbolPenOPD;
}
void PlotOPD::setSizeSymbol(QSize SymbolSize)
{
	mSymbolSizeOPD = SymbolSize;
}
QSize PlotOPD::getSizeSymbol()
{
	return mSymbolSizeOPD;
}

void PlotOPD::setFrameColor(QPen ColorOfTheFrame)
{
	mColorOfTheFrameOPD = ColorOfTheFrame;
}
QPen PlotOPD::getFrameColor()
{
	return mColorOfTheFrameOPD;
}
