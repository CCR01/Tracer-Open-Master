#include "Plot.h"
#include<iostream> 
#include<string.h> 

// draw a circle
void PlotCarsten::circle(cv::Mat img, cv::Point center, int radius, cv::Scalar color, int thickness, int lineType)
{
	cv::circle(img, center, radius, color, thickness, lineType);
}

//draw a line
void PlotCarsten::line(cv::Mat img, cv::Point start, cv::Point end, cv::Scalar color, int thickness, int lineType)
{

	cv::line(img, start, end, color, thickness, lineType);
}



// plot spot diagram
void PlotCarsten::plotDiagram(cv::Mat matrix, std::string imageName)
{

	cv::imshow(imageName, matrix);
	cv::waitKey();
}

// save plot image
void PlotCarsten::saveImage(cv::Mat matrix, std::string location)
{
	cv::imwrite(location, matrix);
}

// get min value of point P.x
real PlotCarsten::getMinValueOfPointX(std::vector<cv::Point2d> const& point)
{
	real outputMin = point.at(0).x;
	for (unsigned int i = 1; i < point.size(); i++)
	{
		real tempPointX = point.at(i).x;
		if (tempPointX < outputMin)
		{
			outputMin = tempPointX;
		}
	}

	return outputMin;
}

// get max value of pont P.x
real PlotCarsten::getMaxValueOfPointX(std::vector<cv::Point2d> const& point)
{
	real outputMax = point.at(0).x;
	for (unsigned int i = 1; i < point.size(); i++)
	{
		real tempPointX = point.at(i).x;
		if (tempPointX > outputMax)
		{
			outputMax = tempPointX;
		}
	}

	return outputMax;
}

// get min value of point P.y
real PlotCarsten::getMinValueOfPointY(std::vector<cv::Point2d> const& point)
{
	real outputMin = point.at(0).y;
	for (unsigned int i = 1; i < point.size(); i++)
	{
		real tempPointX = point.at(i).y;
		if (tempPointX < outputMin)
		{
			outputMin = tempPointX;
		}
	}

	return outputMin;
}



// get max value of pont P.y
real PlotCarsten::getMaxValueOfPointY(std::vector<cv::Point2d> const& point)
{
	real outputMax = point.at(0).y;
	for (unsigned int i = 1; i < point.size(); i++)
	{
		real tempPointX = point.at(i).y;
		if (tempPointX > outputMax)
		{
			outputMax = tempPointX;
		}
	}

	return outputMax;
}