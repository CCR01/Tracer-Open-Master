#pragma once
#ifndef MAIN_H
#define MAIN_H

// Include Files

#include "..\Analyse/OpticalPathDifference.h"

class ImageSimulation
{
public:

	//ImageSimulation() {};
	// to calculate the global OPD
	ImageSimulation()
	{
		mImageSimulation = ImgSimMain();
	};

	// image simulation with 3 PSFs
	ImageSimulation(cv::Mat PSF_1, cv::Mat PSF_2, cv::Mat PSF_3, real magnification, real rmsOptAxis);

	//ImageSimulation() {};

	~ImageSimulation() {};


	OPD calculateOPD();

	//calculate Image
	cv::Mat ImageSimulation::ImgSimMain();



	cv::Mat getSimulatedImage();


private:
	cv::Mat mImageSimulation;
	OPD mOPD;

	cv::Mat mPSF_1;
	cv::Mat mPSF_2;
	cv::Mat mPSF_3;
	real mMagnification;

	real mRMSradius;

};
#endif