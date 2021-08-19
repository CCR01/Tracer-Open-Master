#include "Noise.h"

#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <exception>

#include "..\Image\Images.h"


// 5% in SNR Angabe im Vgl. zu EMVA1288




cameraParameterStruct::cameraParameterStruct() {};
cameraParameterStruct::~cameraParameterStruct() {};

// gQWC
float cameraParameterStruct::getgQWC()
{
    return gQWC;
}
void cameraParameterStruct::setgQWC(float gqwc)
{
    gQWC = gqwc;
}
// gDS
float cameraParameterStruct::getgDS()
{
    return gDS;
}
void cameraParameterStruct::setgDS(float gds)
{
    gDS = gds;
}
// gPS
float cameraParameterStruct::getgPS()
{
    return gPS;
}
void cameraParameterStruct::setgPS(float gps)
{
    gPS = gps;
}
// gDS_dt
float cameraParameterStruct::getgDS_dt()
{
    return gDS_dt;
}
void cameraParameterStruct::setgDS_dt(float gds_dt)
{
    gDS_dt = gds_dt;
}
// gDSNU
float cameraParameterStruct::getgDSNU()
{
    return gDSNU;
}
void cameraParameterStruct::setgDSNU(float gdsnu)
{
    gDSNU = gdsnu;
}
// gDSNU_dt
float cameraParameterStruct::getgDSNU_dt()
{
    return gDSNU_dt;
}
void cameraParameterStruct::setgDSNU_dt( float gdsnu_dt)
{
    gDSNU_dt = gdsnu_dt;
}
// gPRNU
float cameraParameterStruct::getgPRNU()
{
    return gPRNU;
}
void cameraParameterStruct::setgPRNU(float gprnu)
{
    gPRNU = gprnu;
}
// gRON
float cameraParameterStruct::getgRON()
{
    return gRON;
}
void cameraParameterStruct::setgRON(float gron)
{
    gRON = gron;
}
// gEta400
float cameraParameterStruct::getgEta400()
{
    return gEta400;
}
void cameraParameterStruct::setgEta400(float geta400)
{
    gEta400 = geta400;
}
// gEta500
float cameraParameterStruct::getgEta500()
{
    return gEta500;
}
void cameraParameterStruct::setgEta500(float geta500)
{
    gEta500 = geta500;
}
// gEta600
float cameraParameterStruct::getgEta600()
{
    return gEta600;
}
void cameraParameterStruct::setgEta600(float geta600)
{
    gEta600 = geta600;
}
// gEta700
float cameraParameterStruct::getgEta700()
{
    return gEta700;
}
void cameraParameterStruct::setgEta700(float geta700)
{
    gEta700 = geta700;
}
// gEta800
float cameraParameterStruct::getgEta800()
{
    return gEta800;
}
void cameraParameterStruct::setgEta800(float geta800)
{
    gEta800 = geta800;
}
// gEta900
float cameraParameterStruct::getgEta900()
{
    return gEta900;
}
void cameraParameterStruct::setgEta900(float geta900)
{
    gEta900 = geta900;
}
// gADCFaktor
float cameraParameterStruct::getgADCFactor()
{
    return gADCFaktor;
}
void cameraParameterStruct::setgADCFaktor(float gadcFaktor)
{
    gADCFaktor = gadcFaktor;
}
// gADCDynamik
float cameraParameterStruct::getgADCDynamik()
{
    return gADCDynamik;
}
void cameraParameterStruct::setgASCDynamik(float gadcDynamik)
{
    gADCDynamik = gadcDynamik;
}
// gNonlinearity
float cameraParameterStruct::getgNonlinearity()
{
    return gNonlinearity;
}
void cameraParameterStruct::setgNonlinearity(float gnonlinearity)
{
    gNonlinearity = gnonlinearity;
}
// gMin
float cameraParameterStruct::getgMin()
{
    return gMin;
}
void cameraParameterStruct::setgMin(float gmin)
{
    gMin = gmin;
}
// gMax
float cameraParameterStruct::getgMax()
{
    return gMax;
}
void cameraParameterStruct::setgMax(float gmax)
{
    gMax = gmax;
}

Noise::Noise() {}
Noise::~Noise() {}

//----------------------------------------------------------------
// computes the resulting image and returns the sdev of the values
float Noise::basicAnalyse(cv::Mat& im, int p_ron, int p_prnu, int p_dsnu,
    int p_photon, int p_ds)
{
    mLightnoise = p_photon;
    mDsnunoise = p_dsnu;
    mPrnunoise = p_prnu;
    mRonnoise = p_ron;
    mDsnoise = p_ds;

    im = im * 255;

    // debug 
    //Images::showImage_inputUint8("1", im);

    computeElectrons(im, mLambda, mIrradiance, mExposureTimeInSeconds);
    // debug 
    // Images::showImage_inputUint8("2", im);

    addDSNU(im, mExposureTimeInSeconds, mTemperatur);
    // debug 
    // Images::showImage_inputUint8("3", im);

    addDS(im, mExposureTimeInSeconds, mTemperatur);
    // debug 
    // Images::showImage_inputUint8("4", im);

    addPRNU(im);
    // debug 
    // Images::showImage_inputUint8("5", im);

    addRON(im);
    // debug 
   //  Images::showImage_inputUint8("6", im);

    //   addNonlinearity(im);
    for (int y = 0; y < im.size().height; y++) 
    { 
        for (int x = 0; x < im.size().width; x++)
         {
             zahlen[x + y * N] = im.at<uchar>(y, x);
         }
    }
    return   mStatistic.sdev(zahlen, N * N);
}

//----------------------------------------------------------------
// Add the dark signal including the Dark Current (temporal) noise.
void Noise::addDS(cv::Mat& im, float tau, float temp)
{
    int max = pow(2, mCameraParameter.getgADCDynamik()) - 1;
    if (!mDsnoise)
        return;

    float value0 = getDS(temp) * tau * mCameraParameter.getgADCFactor();
    float value;
    for (int y = 0; y < im.size().height; y++)
    {
        for (int x = 0; x < im.size().width; x++)
        {
            value = im.at<uchar>(y, x) + randomNumberUsingGaussDistribution(value0, sqrt(value0));
            if (value > max)
            {
                value = max;
                mClippings++;
            }
            else if (value < 0)
                value = 0;
            im.at<uchar>(y, x) = value;
        }
    }
}

//----------------------------------------------------------------
// Computes the number of electrons for each pixel
// Iradiance given in W pro m^2
// 255 corresponds (always ! also for 10 bit sensors) to the maximum irradiance
// tau = exposure time
// wl = wavelength in nm
void Noise::computeElectrons(cv::Mat& im, float wl, float irradiance, float tau)
{
    int sx = im.size().width;
    int sy = im.size().height;
    int max = pow(2, mCameraParameter.getgADCDynamik());
    float eff = computeEfficiency(wl);
    //  cerr << irradiance << endl;
    float energie = mCameraParameter.getgPS() * mCameraParameter.getgPS() * irradiance * tau * eff * 1e-12;  // in J
    float f = 3e8 / wl / 1e-9;
    float ephoton = 6.626e-34 * f;
    float anzahl = energie / ephoton;
    anzahl *= eff;             // Electronen bei 255 Aussschlag


    double value;
    for (int y = 0; y < im.size().height; y++)
    {
        for (int x = 0; x < im.size().width; x++)
        {
            value = im.at<uchar>(y, x);
            value = value / 255.0 * anzahl;
            if (mLightnoise)
            { 
                value = randomNumberUsingGaussDistribution(value, sqrt(value)); // photon noise (but in electrons)
            }

            value = value * mCameraParameter.getgADCFactor();            // Now we go to Digital numbers (DN)
            // oder muss da auch nochmal Rauschanteil mit dazu ?
            if (value > max - 1)                    // Clipping ?
            {
                value = max - 1;
                mClippings++;
            }
            if (value < 0)
                value = 0;
            im.at<uchar>(y, x) = static_cast<int>(value);
        }
    }
}

//----------------------------------------------------------------
// Hilfsfunktion (für Rauschen) zur Berechnung von gaußverteilten 
// Zufallszahlen 

float Noise::randomNumberUsingGaussDistribution(float mean, float sdev)
{
    static double res0;
    static double factor;
    static int phase = 0;
    double S; 
    double Z;
    double random1;
    double random2;
    double res1;

    if (phase)
        Z = res0 * factor;
    else
    {
        do
        {
            random1 = (double)rand() / RAND_MAX;
            random2 = (double)rand() / RAND_MAX;

            res1 = 2. * random1 - 1.;
            res0 = 2. * random2 - 1.;
            S = std::pow(res1,2) + std::pow(res0,2);
        } 
        
      while (S >= 1);

        factor = sqrt(-2. * log(S) / S);
        Z = res1 * factor;
    }

    phase = 1 - phase;

    return Z * sdev + mean;
}

//----------------------------------------------------------------
// Just return the most appropriate efficiency value for a given
// wavelength.
// BEWARE: There might be considerable (5%) ripple concerning WL variation
float Noise::computeEfficiency(float wl)
{
    if (wl < 450)
        return mCameraParameter.getgEta400();
    if (wl < 550)
        return mCameraParameter.getgEta500();
    if (wl < 650)
        return mCameraParameter.getgEta600();
    if (wl < 750)
        return mCameraParameter.getgEta700();
    if (wl < 850)
        return mCameraParameter.getgEta800();

    return mCameraParameter.getgEta800();
}

void Noise::addDSNU(cv::Mat& im, float tau, float temp)
{
    bool firsttime = true;
    if (mDsnupattern.size().height > 1)
    {
        firsttime = false;
    }


    int max = pow(2, mCameraParameter.getgADCDynamik()) - 1;
    if (!mDsnunoise)
        return;

    float value;
    if (firsttime)
    {
        mDsnupattern = cv::Mat(mImaHeight, mImaWidth, CV_8UC1);

        for (int y = 0; y < im.size().height; y++) for (int x = 0; x < im.size().width; x++)
        {
            value = getDS(temp) * tau * mCameraParameter.getgADCFactor();
            //	cerr << value << " xxx " << gDS << endl;
            if (mDsnunoise)
                value = randomNumberUsingGaussDistribution(value, getDSNU(temp) * tau * mCameraParameter.getgADCFactor());

            if (value > max)
            {
                mClippings++;
                value = max;
            }
            else if (value < 0)
                value = 0;
            mDsnupattern.at<uchar>(y, x) = static_cast<int>(value);
            //	cerr << dsnupattern->_(x,y) << endl;
        }
        firsttime = false;
    }

    int value_int;
    for (int y = 0; y < im.size().height; y++)
    {
        for (int x = 0; x < im.size().width; x++)
        {
            value_int = im.at<uchar>(y, x) + mDsnupattern.at<uchar>(y, x);
            if (value_int > max)
            {
                value_int = max;
                mClippings++;
            }
            if (value_int < 0)
                value_int = 0;
            im.at<uchar>(y, x) = value_int;
        }
    }
}

//----------------------------------------------------------------
// get the Dark Current for a given Temperature
float Noise::getDS(float temp) // in electrons
{
    //  cerr << gDS * pow(2,(temp - 25)/gDS_dt) << endl;
    return mCameraParameter.getgDS() * pow(2, (temp - 25) / mCameraParameter.getgDS_dt());
}

//----------------------------------------------------------------
// get the Dark Current Nonuniformity for a given Temperature
float Noise::getDSNU(float temp) //  in electrons
{
    //  cerr << gDSNU * pow(2,(temp - 25)/gDSNU_dt) << endl;
    return mCameraParameter.getgDSNU() * pow(2, (temp - 25) / mCameraParameter.getgDSNU_dt());
}

// Add PRNU noise
void Noise::addPRNU(cv::Mat& im)
{
    bool firsttime = true;
    if (mPrnupattern.size().height > 1)
    {
        firsttime = false;
    }
    int max = pow(2, mCameraParameter.getgADCDynamik()) - 1;
    if (!mPrnunoise)
        return;

    float value;
    if (firsttime)  // we first have to simulate a PRNU pattern for the sensor
    {
        mPrnupattern = cv::Mat(mImaHeight, mImaWidth, CV_32FC1);
        for (int y = 0; y < im.size().height; y++)
        {
            for (int x = 0; x < im.size().width; x++)
            {

                value = randomNumberUsingGaussDistribution(1.0, mCameraParameter.getgPRNU() * 0.01);
                if (!mPrnunoise)
                    value = 1;
                mPrnupattern.at<float>(y, x) = value;
                //	cerr << prnupattern->_(x,y) << endl;
            }
        }
        firsttime = false;
    }

    int value_int;
    for (int y = 0; y < im.size().height; y++)
    {
        for (int x = 0; x < im.size().width; x++)
        {
            value_int = static_cast<int>(im.at<uchar>(y, x) * mPrnupattern.at<float>(y, x));
            if (value_int > max)
            {
                value_int = max;
                mClippings++;
            }
            if (value_int < 0)
                value_int = 0;
            im.at<uchar>(y, x) = value_int;
        }
    }
    //  cerr << "Typical Value = " << im._(50,50) << endl;
    //  cerr << "Typical Value PRNU = " << prnupattern->_(50,50) << endl;
}

//----------------------------------------------------------------
// Add readout noise 
void Noise::addRON(cv::Mat& im)
{
    int max = pow(2, mCameraParameter.getgADCDynamik()) - 1;
    if (!mRonnoise)
        return;

    int value;
    for (int y = 0; y < im.size().height; y++)
    {
        for (int x = 0; x < im.size().width; x++)
        {
            value = randomNumberUsingGaussDistribution(im.at<uchar>(y, x), mCameraParameter.getgRON() * mCameraParameter.getgADCFactor());
            if (!mRonnoise)
                value = im.at<uchar>(y, x);
            //    cerr << value << endl;
            if (value > max)
            {
                value = max;
                mClippings++;
            }
            if (value < 0)
                value = 0;
            im.at<uchar>(y, x) = value;

        }
    }
    //  cerr << "Typical Value after RON = " << im._(50,50) << "  " << gRON << endl;
}

//----------------------------------------------------------------
// Just for output saving
void Noise::simpleScale_Gray(cv::Mat& im)
{
    int maxi = INT_MIN;
    for (int y = 0; y < im.size().height; y++)
    {
        for (int x = 0; x < im.size().width; x++)
        {
            if (im.at<uchar>(y, x) > maxi)
            {
                maxi = im.at<uchar>(y, x);

            }
         }
    }
    float scale = 255.0 / maxi;

    for (int y = 0; y < im.size().height; y++)
    {
        for (int x = 0; x < im.size().width; x++)
        {
            im.at<uchar>(y, x) = static_cast<int>(im.at<uchar>(y, x) * scale);
        }
    }
}

void Noise::simpleScale_Color(cv::Mat& im)
{
    int maxi_blue = INT_MIN;
    for (int y = 0; y < im.size().height; y++)
    {
        for (int x = 0; x < im.size().width; x++)
        {
            if (im.at<cv::Vec3b>(y, x)[0] > maxi_blue)
            {
                maxi_blue = im.at<uchar>(y, x);

            }
        }
    }

    int maxi_green = INT_MIN;
    for (int y = 0; y < im.size().height; y++)
    {
        for (int x = 0; x < im.size().width; x++)
        {
            if (im.at<cv::Vec3b>(y, x)[1] > maxi_green)
            {
                maxi_green = im.at<uchar>(y, x);

            }
        }
    }

    int maxi_red = INT_MIN;
    for (int y = 0; y < im.size().height; y++)
    {
        for (int x = 0; x < im.size().width; x++)
        {
            if (im.at<cv::Vec3b>(y, x)[1] > maxi_red)
            {
                maxi_red = im.at<uchar>(y, x);

            }
        }
    }

    std::vector<int> max_vec{ maxi_blue, maxi_green, maxi_red };
    int max = INT_MIN;
    for (unsigned int i = 0; i < max_vec.size(); ++i)
    {
        if (max_vec[i] > max)
        {
            max = max_vec[i];
        }
    }

       float scale = 255.0 / max;

       for (int y = 0; y < im.size().height; y++)
       {
           for (int x = 0; x < im.size().width; x++)
           {
               im.at<cv::Vec3b>(y, x)[0] = static_cast<int>(im.at<cv::Vec3b>(y, x)[0] * scale);
               im.at<cv::Vec3b>(y, x)[1] = static_cast<int>(im.at<cv::Vec3b>(y, x)[1] * scale);
               im.at<cv::Vec3b>(y, x)[2] = static_cast<int>(im.at<cv::Vec3b>(y, x)[2] * scale);
           }
       }

}

cv::Mat Noise::getImageWithNoise_Gray_uint8_normed()
{
    // scale the image
    simpleScale_Gray(mImageWithNoise_Gray);

    return mImageWithNoise_Gray;
}

cv::Mat Noise::getImageWithNoise_Color_uint8_normed()
{
    // scale image
    // simpleScale_Color(mImageWithNoise_Color);
   cv::normalize(mImageWithNoise_Color, mImageWithNoise_Color, 0, 255, cv::NORM_MINMAX, CV_8UC3);

    return mImageWithNoise_Color;
}

void Noise::noiseSuperFunction_grayImage(cv::Mat image, cameraParameterStruct cameraParameter, int temperature, float exosureTimeInSeconds, float irradiance, float lambda, bool withcorrection)
{
    mLoadedImage_Gray = image;
    mCameraParameter = cameraParameter;
    mTemperatur = temperature;
    mExposureTimeInSeconds = exosureTimeInSeconds;
    mIrradiance = irradiance;
    mLambda = lambda;

    mImaWidth = mLoadedImage_Gray.size().width;
    mImaHeight = mLoadedImage_Gray.size().height;
    
    zahlen.resize(mImaWidth * mImaHeight);

   //const int width{ mImaWidth };
   //const int height{ mImaHeight };
   //
   //float zahlen[width * height];


    // 1. Take a bright image with
    // Frage: Was meinst du hier mit bright image
    mImageWithNoise_Gray = cv::Mat(mImaHeight, mImaWidth, CV_8UC1);
    //mImageWithNoise = mImageWithNoise * 255;

    //debug
    //Images::showImage_inputUint8("bright image", mImageWithNoise);

    basicAnalyse(mImageWithNoise_Gray, 1, 1, 1, 1, 1); // 1x so damit PRNU und DSNU korrekt inititalisiert

    float aron = basicAnalyse(mImageWithNoise_Gray, 1, 0, 0, 0, 0);
    float aprnu = basicAnalyse(mImageWithNoise_Gray, 0, 1, 0, 0, 0);
    float adsnu = basicAnalyse(mImageWithNoise_Gray, 0, 0, 1, 0, 0);
    float aphoton = basicAnalyse(mImageWithNoise_Gray, 0, 0, 0, 1, 0);
    float ads = basicAnalyse(mImageWithNoise_Gray, 0, 0, 0, 0, 1);
    float aall = basicAnalyse(mImageWithNoise_Gray, 1, 1, 1, 1, 1);

    if (mClippings > mImaWidth * mImaHeight * 0.01)  // mehr wie 1% oversat ? -> Ende
    {
        std::cout << irradiance << " 1" << std::endl;
        exit(-1);
    }

    std::cerr << "Value=" << mStatistic.mean(zahlen, N * N) << ", SNR=" << mStatistic.mean(zahlen, N * N) / aall
        << ", Photon=" << aphoton << ", RON=" << aron << ", PRNU=" << aprnu
        << ", DNSU=" << adsnu << ", DCN=" << ads << std::endl;

    if (!mWithcorrection)

        std::cout << irradiance << " " << mStatistic.mean(zahlen, N * N) / aall << std::endl;

    aall = basicAnalyse(mImageWithNoise_Gray, 1, 0, 0, 1, 1);
    std::cerr << "SNR with correction=" << mStatistic.mean(zahlen, N * N) / aall << std::endl;

    if (mWithcorrection)
        std::cout << irradiance << " " << mStatistic.mean(zahlen, N * N) / aall << std::endl;

    // ------------------------------------------------------------------------   
    #if 1				// Berechnung nach EMVA1288
    float eta = computeEfficiency(lambda);
    float energie = mCameraParameter.getgPS() * mCameraParameter.getgPS() * mIrradiance * mExposureTimeInSeconds * eta * 1e-12;  // in J
    float f = 3e8 / lambda / 1e-9;
    float ephoton = 6.626e-34 * f;
    float mu_p = energie / ephoton;

    // DC Noise 
    // Vorsicht: in EMVA wird da von fiktivem Fall bei Belichtungszeit 0
    // ausgegangen. Das macht aus meiner Sicht keinen Sinn. Also wirklich
    // sqrt(dc) nehmen
    float sigma_d0 = sqrt(getDS(mTemperatur));
    float dsnu = getDSNU(mTemperatur);
    float prnu = mCameraParameter.getgPRNU() * 0.01;  	// gPRNU ist in % gegeben

    float snr = eta * mu_p / sqrt(sigma_d0 * sigma_d0 + dsnu * dsnu +
        eta * mu_p + prnu * prnu * eta * eta * mu_p * mu_p);
    std::cerr << "SNR EMVA1288=" << snr << std::endl;
    //   cerr << "dsnu = " << dsnu << "    ds=" << sigma_d0 << "   mup = " << mu_p << endl;
    //   cerr << "eta = " << eta << "  prnu = " << prnu << endl;
    #endif

    // Saving


    // ----------- Now: Image simulation with all noise ------------------------- 

   // int offsetx = mLoadedImage.size().width / 2 - mImaWidth / 2;
   // int offsety = mLoadedImage.size().height / 2 - mImaHeight / 2;
   //
   // // debug
   // //Images::showImage_inputUint8("loaded image", loadImage);
   //
   // for (int y = 0; y < mImageWithNoise.size().height; y++)
   // {
   //     for (int x = 0; x < mImageWithNoise.size().width; x++)
   //     {
   //         mImageWithNoise.at<uchar>(y, x) = mLoadedImage.at<uchar>(y + offsety, x + offsetx);
   //
   //     }
   // }
   //
    mImageWithNoise_Gray = mLoadedImage_Gray.clone();
    //debug
    //Images::showImage_inputUint8("loaded image with noise", mImageWithNoise);

    mLightnoise = 1;
    mDsnunoise = 1;
    mPrnunoise = 1;
    mRonnoise = 1;
    mDsnoise = 1;

    computeElectrons(mImageWithNoise_Gray, lambda, irradiance, mExposureTimeInSeconds);
    //debug
    //Images::showImage_inputUint8("loaded image with noise", mImageWithNoise);

    addDSNU(mImageWithNoise_Gray, mExposureTimeInSeconds, mTemperatur);
    //debug
    //Images::showImage_inputUint8("loaded image with noise", mImageWithNoise);

    addDS(mImageWithNoise_Gray, mExposureTimeInSeconds, mTemperatur);
    //debug
    //Images::showImage_inputUint8("loaded image with noise", mImageWithNoise);

    addPRNU(mImageWithNoise_Gray);
    //debug
    //Images::showImage_inputUint8("loaded image with noise", mImageWithNoise);

    addRON(mImageWithNoise_Gray);
    //debug
    //Images::showImage_inputUint8("loaded image with noise", mImageWithNoise);

   
    // normalize the image
    //cv::normalize(mImageWithNoise, mImageWithNoise, 0, 255, cv::NORM_MINMAX, CV_8UC1);


    //// debug
    //Images::showImage_inputUint8("test", mImageWithNoise);
    //Images::showImage_inputReal_normTheImage("test2", mImageWithNoise);

}

void Noise::noiseSuperFunction_colorImage(cv::Mat image, cameraParameterStruct cameraParameter, int temperature, float exosureTimeInSeconds, float irradiance, std::vector<float> lambda, bool withcorrection)
{
    mLoadedImage_Color = image;
    mCameraParameter = cameraParameter;
    mTemperatur = temperature;
    mExposureTimeInSeconds = exosureTimeInSeconds;
    mIrradiance = irradiance;
    mLambda_vec = lambda;
    mWithcorrection = withcorrection;

    mImaWidth = mLoadedImage_Color.size().width;
    mImaHeight = mLoadedImage_Color.size().height;

    // split the image in BRG
    splitColorImaInBGR();

    // noise blue image
    mClippings = 0;
    noiseSuperFunction_grayImage(mImage_blue, mCameraParameter, mTemperatur, mExposureTimeInSeconds, mIrradiance, mLambda_vec[0], mWithcorrection);
    mImageWithNoise_blue = mImageWithNoise_Gray.clone();

    // noise green image
    mClippings = 0;
    noiseSuperFunction_grayImage(mImage_green, mCameraParameter, mTemperatur, mExposureTimeInSeconds, mIrradiance, mLambda_vec[1], mWithcorrection);
    mImageWithNoise_green = mImageWithNoise_Gray.clone();

    // noise red image
    mClippings = 0;
    noiseSuperFunction_grayImage(mImage_red, mCameraParameter, mTemperatur, mExposureTimeInSeconds, mIrradiance, mLambda_vec[2], mWithcorrection);
    mImageWithNoise_red = mImageWithNoise_Gray.clone();


    // put channels together
    putChannelsTogether();

    // debug
    //Images::showImage_inputUint8("test", mImageWithNoise_Color);

}

void Noise::splitColorImaInBGR()
{

    cv::Mat channel[3];
    cv::split(mLoadedImage_Color, channel);

    mImage_blue = channel[0];
    mImage_green = channel[1];
    mImage_red = channel[2];


}

void Noise::putChannelsTogether()
{
    std::vector<cv::Mat> array_to_merge;
    array_to_merge.push_back(mImageWithNoise_blue);
    array_to_merge.push_back(mImageWithNoise_green);
    array_to_merge.push_back(mImageWithNoise_red);

    cv::merge(array_to_merge, mImageWithNoise_Color);

}



