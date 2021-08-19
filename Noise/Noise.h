#pragma once
#include "statistik.h"

#include "opencv2/core/mat.hpp"


struct cameraParameterStruct
{
public:
	cameraParameterStruct();
	~cameraParameterStruct();


	// gQWC
	float getgQWC();
	void setgQWC(float gqwc);
	// gPS
	float getgPS();
	void setgPS(float gps);
	// gDS
	float getgDS();
	void setgDS(float gds);
	// gDS_dt
	float getgDS_dt();
	void setgDS_dt(float gds_dt);
	// gDSNU
	float getgDSNU();
	void setgDSNU(float gdsnu);
	// gDSNU_dt
	float getgDSNU_dt();
	void setgDSNU_dt(float gdsnu_dt);
	// gPRNU
	float getgPRNU();
	void setgPRNU(float gprnu);
	// gRON
	float getgRON();
	void setgRON(float gron);
	// gEta400
	float getgEta400();
	void setgEta400(float geta400);
	// gEta500
	float getgEta500();
	void setgEta500(float geta500);
	// gEta600
	float getgEta600();
	void setgEta600(float geta600);
	// gEta700
	float getgEta700();
	void setgEta700(float geta700);
	// gEta800
	float getgEta800();
	void setgEta800(float geta800);
	// gEta900
	float getgEta900();
	void setgEta900(float geta900);
	// gADCFaktor
	float getgADCFactor();
	void setgADCFaktor(float gadcFaktor);
	// gADCDynamik
	float getgADCDynamik();
	void setgASCDynamik(float gadcDynamik);
	// gNonlinearity
	float getgNonlinearity();
	void setgNonlinearity(float gnonlinearity);
	// gMin
	float getgMin();
	void setgMin(float gmin);
	// gMax
	float getgMax();
	void setgMax(float gmax);

private:
	float  gQWC;			// QWC in electrons
	float  gPS;			// Pixelsize in mu
	float  gDS;			// Dark signal at 25° in electrons
	float  gDS_dt;			// Dark signal doubling Temperature
	float  gDSNU;			// Dark signal nonuniformity in electrons at 25°
	float  gDSNU_dt;		// Dark signal nonuniformity doubling temperature
	float  gPRNU;			// PRNU in %
	float  gRON;			// Readout noise in electrons (bewware for framerate(
	float  gEta400;			// quantum efficiencies at wavelengths
	float  gEta500;
	float  gEta600;
	float  gEta700;
	float  gEta800;
	float  gEta900;
	float  gADCFaktor;		// Conversion Faktor: Digital number per electron
	// Typically computed by QWC/ADCFullScale
	float  gADCDynamik;		// in bits
	float  gNonlinearity;		// currently not used
	float  gMin;                    // currently not used
	float  gMax;                    // currently not used 
};

class Noise
{
public:
	Noise();
	~Noise();

	void noiseSuperFunction_grayImage(cv::Mat image, cameraParameterStruct cameraParameter, int temperature, float exosureTimeInSeconds, float irradiance, float lambda, bool withcorrection);
	void noiseSuperFunction_colorImage(cv::Mat image, cameraParameterStruct cameraParameter, int temperature, float exosureTimeInSeconds, float irradiance, std::vector<float> lambda, bool withcorrection);


	float basicAnalyse(cv::Mat& im, int p_ron, int p_prnu, int p_dsnu, int p_photon, int p_ds);
	void computeElectrons(cv::Mat& im, float wl, float irradiance, float tau);
	float computeEfficiency(float wl);
	float randomNumberUsingGaussDistribution(float mean, float sdev);
	void addDSNU(cv::Mat& im, float tau, float temp);
	void addDS(cv::Mat& im, float tau, float temp);

	float getDS(float temp); // in electrons
	float Noise::getDSNU(float temp); //  in electrons
	void addPRNU(cv::Mat& im);
	void addRON(cv::Mat& im);
	void simpleScale_Gray(cv::Mat& im);
	void simpleScale_Color(cv::Mat& im);

	void splitColorImaInBGR();
	void putChannelsTogether();

	cv::Mat getImageWithNoise_Gray_uint8_normed();
	cv::Mat getImageWithNoise_Color_uint8_normed();

private:

	cameraParameterStruct mCameraParameter{};

	int mLightnoise = 1;			// Defines if lightnoise should be included in simul.
	int mRonnoise = 1;              // Defines if Readoutnoise should be included in simul.
	int mPrnunoise = 1;             // Defines if PRNU  should be included in simul.
	int mDsnunoise = 1;             // Defines if DSNU noise should be included in simul.
	int mDsnoise = 1;               // Defines if DC noise should be included in simul.

	int mTemperatur;   				// in °C
	float mExposureTimeInSeconds;   // exposure time in s
	float mIrradiance;      		// Ee in W/m^2
	float mLambda;      			// wavelength in nm
	std::vector<float> mLambda_vec;
	bool mWithcorrection;
	int mClippings = 0;				// Number of high clipping events

	float mWerte[100];				// Just for reading in the camera file
	cv::Mat mDsnupattern;			// For storing the DSNU cam pattern
	cv::Mat mPrnupattern;		    // For storing the PRNU cam pattern

	Statistik mStatistic;

	cv::Mat mLoadedImage_Gray;
	cv::Mat mImageWithNoise_Gray;
	cv::Mat mImageWithNoise_Color;

	cv::Mat mLoadedImage_Color;
	cv::Mat mImage_blue;
	cv::Mat mImage_green;
	cv::Mat mImage_red;

	cv::Mat mImageWithNoise_blue;
	cv::Mat mImageWithNoise_green;
	cv::Mat mImageWithNoise_red;

	unsigned int mImaWidth{};
	unsigned int mImaHeight{};
	std::vector<float> zahlen{};	// Array for the statistical evaluation
};

