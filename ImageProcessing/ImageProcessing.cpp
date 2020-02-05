#include "ImageProcessing.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/calib3d/calib3d.hpp>
//#include <opencv2/imgcodecs.hpp>
#include <opencv2/photo.hpp>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "..\Image\Images.h"

// Brightness and contrast adjustments
	// see https://docs.opencv.org/3.4/d3/dc1/tutorial_basic_linear_transform.html
cv::Mat ImageProcessing::brighContrastAdjust(cv::Mat const& image, real const& alpha, int const& beta)
{
	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());
	image.convertTo(new_image, -1, alpha, beta);

	return new_image;
}

// Correct an underexposed image -> Gamma correction
// https://docs.opencv.org/3.4/d3/dc1/tutorial_basic_linear_transform.html
// more informations: https://learnopengl.com/Advanced-Lighting/Gamma-Correction
cv::Mat ImageProcessing::gammaCorrection(cv::Mat const& image, real const& gamma)
{
	cv::Mat lookUpTable(1, 256, CV_8U);
	uchar* p = lookUpTable.ptr();
	for (int i = 0; i < 256; ++i)
		p[i] = cv::saturate_cast<uchar>(pow(i / 255.0, gamma) * 255.0);
	cv::Mat result = image.clone();
	cv::LUT(image, lookUpTable, result);


	return result;
}

// bilateralFilter
	//can reduce unwanted noise very well while keeping edges fairly sharp.However, it is very slow compared to most filters.
	// https://www.tutorialspoint.com/opencv/opencv_bilateral_filter.htm
cv::Mat ImageProcessing::bilateralFilter(cv::Mat const& image, int const& pixelNeighborhood, int const& sigmaColor, int const& sigmaSpace, int const& borderType)
{
	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());
	cv::bilateralFilter(image, new_image, pixelNeighborhood, sigmaColor, sigmaSpace, borderType);

	return new_image;
}

// boxFilter
// Blurs an image using the box filter.
// https://www.tutorialspoint.com/opencv/opencv_box_filter.htm
cv::Mat ImageProcessing::boxFilter(cv::Mat const& image, int const& depthOutputImage, cv::Size const& ksize, cv::Point const& point, bool const& normalize, int const& borderType)
{
	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());
	cv::boxFilter(image, new_image, depthOutputImage, ksize, point, true, borderType);

	return new_image;
}

// erosion
cv::Mat ImageProcessing::erosion(cv::Mat const& image,/*erosion type*/ int erosionType,/*kernel size*/ cv::Size  const& ksize,/*anchor point*/ cv::Point const& point)
{
	
	
	if (erosionType == 0) { erosionType = cv::MORPH_RECT; }
	else if (erosionType == 1) { erosionType = cv::MORPH_CROSS; }
	else if (erosionType == 2) { erosionType = cv::MORPH_ELLIPSE; }

	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());

	// build the element fpr erosion
	cv::Mat element = cv::getStructuringElement(erosionType, ksize, point);

	cv::erode(image, new_image, element);

	return new_image;

}

// dilation
cv::Mat ImageProcessing::dilation(cv::Mat const& image,/*erosion type*/ int erosionType,/*kernel size*/ cv::Size  const& ksize,/*anchor point*/ cv::Point const& point)
{
	if (erosionType == 0) { erosionType = cv::MORPH_RECT; }
	else if (erosionType == 1) { erosionType = cv::MORPH_CROSS; }
	else if (erosionType == 2) { erosionType = cv::MORPH_ELLIPSE; }

	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());

	// build the element fpr erosion
	cv::Mat element = cv::getStructuringElement(erosionType, ksize, point);

	cv::dilate(image, new_image, element);

	return new_image;
}

//correct distortion of an image
cv::Mat ImageProcessing::correctDistortion(cv::Mat const& image, cv::Mat const& calibrationImage, int const& numCornersHor, int const& numCornersVer) 
{
	//Images::showImage("test", calibrationImage);

	//we just load one image
	int numBoards = 1;

	cv::Mat distortionFreeImage;


	int numSquares = numCornersHor * numCornersVer;
	cv::Size board_sz = cv::Size(numCornersHor, numCornersVer);

	std::vector<std::vector<cv::Point3f>> object_points;
	std::vector<std::vector<cv::Point2f>> image_points_calibration;

	std::vector<cv::Point2f> corners;
	int successes = 0;

	cv::Mat gray_image;
	bool found = false;

	std::vector<cv::Point3f> obj;
	for (int j = 0; j < numSquares; j++)
		obj.push_back(cv::Point3f(j / numCornersHor, j%numCornersHor, 0.0f));

	int interation = 0;


	while (successes < numBoards && interation < 3)
	{
		cv::cvtColor(calibrationImage, gray_image, CV_BGR2GRAY);

		found = cv::findChessboardCorners(calibrationImage, board_sz, corners, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS);

		if (found == 1)
		{
			cv::cornerSubPix(gray_image, corners, cv::Size(11, 11), cv::Size(0, 0), cv::TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 30, 0.1));
			cv::drawChessboardCorners(gray_image, board_sz, corners, found);

		}

		if (found != 0)
		{
			image_points_calibration.push_back(corners);
			object_points.push_back(obj);
			successes++;

		}

		if (interation >= 2)
		{
			std::cout << "we did not find the cornders of the chessboard" << std::endl;
		}
			
		interation++;
	}

	cv::Mat intrinsic = cv::Mat(3, 3, CV_64FC1);
	cv::Mat distCoeffs;
	std::vector<cv::Mat> rvecs;
	std::vector<cv::Mat> tvecs;


	intrinsic.ptr<float>(0)[0] = 1;
	intrinsic.ptr<float>(1)[1] = 1;

	cv::calibrateCamera(object_points, image_points_calibration, calibrationImage.size(), intrinsic, distCoeffs, rvecs, tvecs);
	
	
	cv::undistort(image, distortionFreeImage, intrinsic, distCoeffs);


	
	return distortionFreeImage;
}


// Detail Enhancing Filter
cv::Mat ImageProcessing::detailEnhancin(cv::Mat const& image, float const& sigma_s, float const& sigma_r)
{
	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());

	cv::detailEnhance(image, new_image, sigma_s, sigma_r);

	return new_image;

}


// laplacian
// see: https://docs.opencv.org/3.4/d5/db5/tutorial_laplace_operator.html
cv::Mat ImageProcessing::laplacian(cv::Mat const& image, int const& ddepth, int const& kernel_size, int const& scale, int const& delta)
{
	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());
	cv::Mat return_new_image = cv::Mat::zeros(image.size(), image.type());

	cv::Laplacian(image, new_image, ddepth, kernel_size, scale, delta, cv::BORDER_DEFAULT);
	//converting back to CV_8U
	cv::convertScaleAbs(new_image, return_new_image);

	return return_new_image;
}

// canny
	// see: https://docs.opencv.org/2.4/doc/tutorials/imgproc/imgtrans/canny_detector/canny_detector.html
cv::Mat ImageProcessing::canny(cv::Mat const& image, real const& lowThreshold, real const& heightThreshold, int const& apertureSize, bool const& L2gradient)
{

	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());
	cv::Canny(image, new_image, lowThreshold, heightThreshold, apertureSize, L2gradient);

	return new_image;

}

// sobel
	// see: https://docs.opencv.org/2.4/doc/tutorials/imgproc/imgtrans/sobel_derivatives/sobel_derivatives.html
cv::Mat ImageProcessing::sobel(cv::Mat image, int const& ddepth, int const& dx, int const& dy, int const& ksize, double const& scale, double const& delta, int const& borderType)
{
	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());
	cv::Sobel(image, new_image, ddepth, dx, dy, ksize, scale, delta, borderType);

	return new_image;

}


// unsharp mask
// see: https://docs.opencv.org/master/d1/d10/classcv_1_1MatExpr.html#details
cv::Mat	ImageProcessing::unsharpMask(cv::Mat const& image, cv::Size kernelSize, double const& sigmaX, double const& sigmaY, int const& borderType, double const& threshold, double const& amount)
{



	cv::Mat new_image = image;
	cv::Mat blurredGaussian;
	cv::GaussianBlur(image, blurredGaussian, kernelSize, sigmaX, sigmaY, borderType);
	//Images::showImage("GaussianBlur", blurredGaussian);
	cv::Mat lowContrastMask = cv::abs(image - blurredGaussian) < threshold;
	//Images::showImage("lowContrastMast", lowContrastMask);
	cv::Mat sharpenedImage = image * (1 + amount) + blurredGaussian * (-amount);
	//Images::showImage("sharpenedImage1", sharpenedImage);
	//new_image.copyTo(sharpenedImage, lowContrastMask);
	//Images::showImage("return image", new_image);

  	return sharpenedImage;

}

// bilateralFilter 
	// see: https://docs.opencv.org/3.0-beta/modules/imgproc/doc/filtering.html
cv::Mat ImageProcessing::bilateralFilter(cv::Mat const& image, int const& d, double const& sigmarColor, double const& sigmarSpace, int const& boarderType)
{
	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());

	cv::bilateralFilter(image, new_image, d, sigmarColor, sigmarSpace, boarderType);
	return new_image;
}

// median blur
	// see: https://docs.opencv.org/3.3.1/d4/d86/group__imgproc__filter.html#ga564869aa33e58769b4469101aac458f9
	// see: https://docs.opencv.org/3.1.0/d4/d13/tutorial_py_filtering.html
	// The function smoothes an image using the median filter with the ksize×ksize aperture.
	// Each channel of a multi-channel image is processed independently. In-place operation is supported
cv::Mat ImageProcessing::MedianBlurFilter(cv::Mat const& image, int const& ksize)
{
	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());

	cv::medianBlur(image, new_image, ksize);

	return new_image;
}
