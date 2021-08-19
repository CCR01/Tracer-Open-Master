#pragma once

#include "opencv2/core/mat.hpp"
#include "..\LowLevelTracing\ImportantStructures.h"

// optical system element
#include "..\OpticalSystemElement\OpticalSystemElement.h"

// OPD
#include "..\Analyse\OpticalPathDifference.h"

struct loadParameterPSF
{
public:
	loadParameterPSF();
	~loadParameterPSF();
	

	// size matrix OPD
	unsigned int getSizeMatrixOPD();
	void setSizeMatrixOPD(unsigned int sizeMatrixOPD);
	// ray density
	unsigned int getRayDensity();
	void setRayDensity(unsigned int rayDensity);
	// light ray type
	typeLight getLightType();
	void setLightType(typeLight lightType);
	// intensity light 
	real getIntensityLight();
	void setIntensityLight(real intensityLight);
	// jones vector
	JonesVector_LLT getJonesVector();
	void setJonesVector(JonesVector_LLT jonesVector);
	// object point inf obj
	objectPoint_inf_obj getObjectPoint_inf_obj();
	void setObjectPoint_inf_obj(objectPoint_inf_obj objectPoint_inf_obj);
	// max interation bilinear interpolation
	unsigned int getMaxIteraBilinInterpola();
	void setMaxInteraBilinInterpolation(unsigned maxIterBilIterpol);
	// target pixel size
	real getTargetPixelSize_µm();
	void setTargetPixelSize_µm(real targetPixelSize);
	// padding factor
	unsigned int getPaddingFactor();
	void setPaddingFactor(unsigned int paddingFactor);

	// load default parameter PSF
	void loadDefaulParameterPSF();

private:
	unsigned int mSizeMatrixOPD{};
	unsigned int mRayDensity{};
	typeLight mLightRayType{};
	real mIntensityLight{};
	JonesVector_LLT mJonesVector{};
	objectPoint_inf_obj mObjPoint_inf_obj;
	unsigned int mMaxIterationBilinInterpol;
	real mTargetPixelSize_µm;
	unsigned int mPaddingFactor;
};

class PSF
{
public:
	PSF();
	~PSF();

	cv::Mat calcPSF_FFT_NEW(cv::Mat& OPD);

	cv::Mat MagnitudeOfTwochannelsMat(cv::Mat& matrix);

	void fftshift(cv::Mat& mat);
	
	// norme the PSF to a target Size in µm
	//cv::Mat normPSF_atImaSurface(cv::Mat& unNormPSF, real distanceEXP_to_imaSurface_mm, real EXPD_mm, real wavelength_nm, real targetSize_µm);
	cv::Mat PSF::normPSFtoTargetPixelSize_AtImaSurface(cv::Mat& unNormPSF_atExitPupil, real targetPixelSize_µm, real distanceEXP_ImaSurface_mm, real wavelength_nm, real EXPD_mm, unsigned int paddingFactor);
	// calculate size per pixcel from given PSF
	void calcSizePerPixel_PSFAtImageSurface_µm(real distanceEXP_ImaSurface_mm, real wavelength_nm, real EXPD_mm, unsigned int paddingFactor);
	// get size per pixel norm PSF
	real getSizePerPixcelAtImaSurface_µm();
	// resize object to match size of pixel PSF
	void resizeObjectToMachSizePixelPSF(cv::Mat& initialObject, cv::Mat& resisedObject, real magnification, real heightObject, real distanceEXP_ImaSurface_mm, real wavelength_nm, real EXPD_mm, unsigned int paddingFactor);

	// calculate PSF super function
	void calculatePSF_superFunction(OpticalSystemElement optSysEle, real wavelength_nm, VectorStructR3 fieldPointRay);

	// calculate norm PSF at image surface
	cv::Mat calcNormPSF_ImaSurface(cv::Mat OPD, real wavelength, real EXPD_mm, real EXPP_mm, real targetPixelSize_µm, unsigned int paddingFactor);


	// set functions
	// size matrix OPD
	unsigned int getSizeMatrixOPD();
	void setSizeMatrixOPD(unsigned int sizeMatrixOPD);
	// ray density
	unsigned int getRayDensity();
	void setRayDensity(unsigned int rayDensity);
	// light ray type
	typeLight getLightType();
	void setLightType(typeLight lightType);
	// intensity light 
	real getIntensityLight();
	void setIntensityLight(real intensityLight);
	// jones vector
	JonesVector_LLT getJonesVector();
	void setJonesVector(JonesVector_LLT jonesVector);
	// object point inf obj
	objectPoint_inf_obj getObjectPoint_inf_obj();
	void setObjectPoint_inf_obj(objectPoint_inf_obj objectPoint_inf_obj);
	// max interation bilinear interpolation
	unsigned int getMaxIteraBilinInterpola();
	void setMaxInteraBilinInterpolation(unsigned maxIterBilIterpol);
	// target pixel size
	real getTargetPixelSize_µm();
	void setTargetPixelSize_µm(real targetPixelSize);
	// padding factor
	unsigned int getPaddingFactor();
	void setPaddingFactor(unsigned int paddingFactor);
	// load Parameter
	void loadParameter(loadParameterPSF parameterToLoad);
	// ***


	// global OPD
	cv::Mat getGlobalOPD_deepCopy();
	// global sampled up OPD
	cv::Mat getGlobalOPD_sampledUP_deepCopy();
	// get PSF at exit pupil
	cv::Mat getPSF_exitPupil();
	// get PSF image surface target size
	cv::Mat getPSF_imaSurface_targetSize();

private:

	loadParameterPSF mLoadParaPSF{};
	OPD mOPD{};
	cv::Mat mPSF_exitPupil{};
	cv::Mat mNormPSF_ImaSurface_targetSize{};

	real mSizePerPixelAtImaSurface_µm{};


};

