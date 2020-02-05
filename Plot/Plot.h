#pragma once

#include "..\basicdefinition\basicdefinitions.h"

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"





namespace PlotCarsten
{
	// see: https://docs.opencv.org/2.4/doc/tutorials/core/basic_geometric_drawing/basic_geometric_drawing.html


	// draw a circle
	void circle(cv::Mat img, cv::Point center, int radius, cv::Scalar color, int thickness, int lineType);

	//draw a line
	void line(cv::Mat img, cv::Point start, cv::Point end, cv::Scalar color, int thickness, int lineType);

	// plot spot diagram
	void plotDiagram(cv::Mat matrix, std::string imageName);

	// save plot image
	void saveImage(cv::Mat matrix, std::string location);

	// get min value of point P.x
	real getMinValueOfPointX(std::vector<cv::Point2d> const& point);

	// get max value of pont P.x
	real getMaxValueOfPointX(std::vector<cv::Point2d> const& point);

	// get min value of point P.y
	real getMinValueOfPointY(std::vector<cv::Point2d> const& point);

	// get max value of pont P.y
	real getMaxValueOfPointY(std::vector<cv::Point2d> const& point);


};

