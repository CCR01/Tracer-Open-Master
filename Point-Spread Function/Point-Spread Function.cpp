#include "Point-Spread Function.h"

#include "opencv2/core/core.hpp"

#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/highgui/highgui.hpp"

#include "..\Image\Images.h"

#include "..\oftenUseNamespace\oftenUseNamespace.h"

// ray aiming
#include "..\RayAiming\RayAiming.h"

// fill aperture stop with ray
#include "..\FillAptertureStop\FillApertureStop.h"

// optical path difference
#include "..\Analyse\OpticalPathDifference.h"

// cardinal points
#include "..\Analyse\CardinalPoints.h"


loadParameterPSF::loadParameterPSF() {};
loadParameterPSF::~loadParameterPSF() {};


// size matrix OPD
unsigned int loadParameterPSF::getSizeMatrixOPD()
{
	return mSizeMatrixOPD;
}
void loadParameterPSF::setSizeMatrixOPD(unsigned int sizeMatrixOPD)
{
	mSizeMatrixOPD = sizeMatrixOPD;
}
// ray density
unsigned int loadParameterPSF::getRayDensity()
{
	return mRayDensity;
}
void loadParameterPSF::setRayDensity(unsigned int rayDensity)
{
	mRayDensity = rayDensity;
}
// light ray type
typeLight loadParameterPSF::getLightType()
{
	return mLightRayType;
}
void loadParameterPSF::setLightType(typeLight lightType)
{
	mLightRayType = lightType;
}
// intensity light 
real loadParameterPSF::getIntensityLight()
{
	return mIntensityLight;
}
void loadParameterPSF::setIntensityLight(real intensityLight)
{
	mIntensityLight = intensityLight;
}
// jones vector
JonesVector_LLT loadParameterPSF::getJonesVector()
{
	return mJonesVector;
}
void loadParameterPSF::setJonesVector(JonesVector_LLT jonesVector)
{
	mJonesVector = jonesVector;
}
// object point inf obj
objectPoint_inf_obj loadParameterPSF::getObjectPoint_inf_obj()
{
	return mObjPoint_inf_obj;
}
void loadParameterPSF::setObjectPoint_inf_obj(objectPoint_inf_obj objectPoint_inf_obj)
{
	mObjPoint_inf_obj = objectPoint_inf_obj;
}
// max interation bilinear interpolation
unsigned int loadParameterPSF::getMaxIteraBilinInterpola()
{
	return mMaxIterationBilinInterpol;
}
void loadParameterPSF::setMaxInteraBilinInterpolation(unsigned maxIterBilIterpol)
{
	mMaxIterationBilinInterpol = maxIterBilIterpol;
}
// target pixel size
real loadParameterPSF::getTargetPixelSize_µm()
{
	return mTargetPixelSize_µm;
}
void loadParameterPSF::setTargetPixelSize_µm(real targetPixelSize)
{
	mTargetPixelSize_µm = targetPixelSize;
}
// padding factor
unsigned int loadParameterPSF::getPaddingFactor()
{
	return mPaddingFactor;
}
void loadParameterPSF::setPaddingFactor(unsigned int paddingFactor)
{
	mPaddingFactor = paddingFactor;
}

// load default parameter PSF
void loadParameterPSF::loadDefaulParameterPSF()
{
	mSizeMatrixOPD = 128;
	mRayDensity = 30;
	mLightRayType = typeLight::typeLightRay;
	mIntensityLight = 1.0;
	mJonesVector = { 1.0,1.0,1.0,1.0 };
	mObjPoint_inf_obj = objectPoint_inf_obj::obj;
	mMaxIterationBilinInterpol = 4;
	mTargetPixelSize_µm = 1.0;
	mPaddingFactor = 6;
}

PSF::PSF() { mLoadParaPSF.loadDefaulParameterPSF(); }
PSF::~PSF() {}




cv::Mat PSF::MagnitudeOfTwochannelsMat(cv::Mat& Matrix)
{
	cv::Mat chan[2];
	cv::split(Matrix, chan);
	cv::Mat mag;
	cv::magnitude(chan[0], chan[1], mag);
	return mag;
}



cv::Mat PSF::calcPSF_FFT_NEW(cv::Mat& OPD)
{

	cv::Mat pupilFuc_Real;
	cv::Mat pupilFuc_Ima;
	

	unsigned int heightOPD = OPD.size().height;
	unsigned int widthOPD = OPD.size().width;

	cv::Size sizePupilFct(heightOPD, widthOPD);
	pupilFuc_Real = cv::Mat::zeros(sizePupilFct, OPD.type());
	pupilFuc_Ima = cv::Mat::zeros(sizePupilFct, OPD.type());

	real twoPi = 2.0 * PI;
	real tempOPD;
	real j_normed;
	real i_normed;
	real radius;

	//std::cout << "width: " << widthOPD << std::endl;
	//std::cout << "height: " << heightOPD << std::endl;
	

	// calculate the complex pupil function
	for (unsigned int i = 0; i < heightOPD; ++i)
	{
		for (unsigned int j = 0; j < widthOPD; ++j)
		{
			j_normed = ( 2.0 * (real)j / widthOPD - 1.0);
			i_normed = (2.0 * (real)i / heightOPD - 1.0);
			radius = std::sqrt(j_normed * j_normed + i_normed * i_normed);
		
			

			if(radius <= 1.0)
			{			
				

				tempOPD = OPD.at<real>(i, j);
				pupilFuc_Real.at<real>(i, j) = std::cos(twoPi * tempOPD); // real part
				pupilFuc_Ima.at<real>(i, j) = std::sin(twoPi * tempOPD); // complex part
			}
		
		}
	}

	cv::Mat affe;
	affe = pupilFuc_Real.mul(pupilFuc_Real);
	cv::Mat banane;
	banane = pupilFuc_Ima.mul(pupilFuc_Ima);
	
	cv::Mat affeBanane = affe + banane;
	real sumAffeBanane = cv::sum(affeBanane)[0];
	
	// debug
	// std::cout << "affe und banane: " << sumAffeBanane << std::endl;

	// for more infomrations about tht FFT
	// --> https://docs.opencv.org/3.4/d8/d01/tutorial_discrete_fourier_transform.html



	//expand input image to optimal size
	int m = cv::getOptimalDFTSize(OPD.rows);
	int n = cv::getOptimalDFTSize(OPD.cols);

	int m_padding = m * mLoadParaPSF.getPaddingFactor();
	int n_padding = n * mLoadParaPSF.getPaddingFactor();

	cv::Mat paddedPupilFunction_Real;
	cv::Mat paddedPupilFunction_Complex;
	// on the border add zero values
	cv::copyMakeBorder(pupilFuc_Real, paddedPupilFunction_Real, 0, m_padding - OPD.rows, 0, n_padding - OPD.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));
	cv::copyMakeBorder(pupilFuc_Ima, paddedPupilFunction_Complex, 0, m_padding - OPD.rows, 0, n_padding - OPD.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));


	fftshift(paddedPupilFunction_Real);
	fftshift(paddedPupilFunction_Complex);


	cv::Mat pupilFuc[] = { paddedPupilFunction_Real, paddedPupilFunction_Complex};
	cv::Mat mergedPupilFuc;
	cv::merge(pupilFuc, 2, mergedPupilFuc);
	//cv::Mat complexI;

	cv::Mat amplitudePSF;
	cv::dft(mergedPupilFuc, amplitudePSF, cv::DFT_COMPLEX_OUTPUT);

	cv::split(amplitudePSF, pupilFuc);

	cv::Mat quadReal;
	quadReal = pupilFuc[0].mul(pupilFuc[0]);
	
	cv::Mat quadImagi;
	quadImagi = pupilFuc[1].mul(pupilFuc[1]);
	 
	cv::Mat PSF = quadReal + quadImagi;
	
	// debug
	// real sumPSF = cv::sum(PSF)[0];
	// std::cout << "sum PSF: " << sumPSF << std::endl;

	//cv::Mat PSF = pupilFuc[0] * pupilFuc[0] + pupilFuc[1] * pupilFuc[1];


	fftshift(PSF);

	//cv::Mat originalSize;

	// cut ínformations from the middle

	unsigned int middlePX = m_padding / 2;
	unsigned middlePY = n_padding / 2;
	//magI = magI * magI;
	cv::Mat PSF_relevant(PSF, cv::Rect(middlePY - n / 2, middlePX - m / 2, n, m));

	// debug
	// real sumPSF_relevant = cv::sum(PSF_relevant)[0];
	// std::cout << "sum PSF relevant: " << sumPSF_relevant << std::endl;

	return PSF_relevant;
}

void PSF::fftshift(cv::Mat& mat)
{

	
	// rearrange the quadrants of Fourier image  so that the origin is at the image center
	int cx = mat.cols / 2;
	int cy = mat.rows / 2;
	cv::Mat q0(mat, cv::Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
	cv::Mat q1(mat, cv::Rect(cx, 0, cx, cy));  // Top-Right
	cv::Mat q2(mat, cv::Rect(0, cy, cx, cy));  // Bottom-Left
	cv::Mat q3(mat, cv::Rect(cx, cy, cx, cy)); // Bottom-Right
	cv::Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);
	q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
	q2.copyTo(q1);
	tmp.copyTo(q2);

}

// norme the PSF to a target Size in µm
//cv::Mat PSF::normPSF_atImaSurface(cv::Mat& unNormPSF, real distanceEXP_to_imaSurface_mm, real EXPD_mm, real wavelength_nm, real targetSize_µm)
cv::Mat PSF::normPSFtoTargetPixelSize_AtImaSurface(cv::Mat& unNormPSF_atExitPupil, real targetPixelSize_µm, real distanceEXP_ImaSurface_mm, real wavelength_nm, real EXPD_mm, unsigned int paddingFactor)
{
	calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_ImaSurface_mm, wavelength_nm, EXPD_mm, paddingFactor);

	unsigned int heightUnNormPSF = unNormPSF_atExitPupil.size().height;
	unsigned int widthUnNormPSF = unNormPSF_atExitPupil.size().width;

	real resizeFactor = mSizePerPixelAtImaSurface_µm / targetPixelSize_µm;
	real targetHeight = heightUnNormPSF * resizeFactor;
	real targetWidth = widthUnNormPSF * resizeFactor;

	cv::Mat PSF_targetSize;


	//cv::normalize(unNormPSF_atExitPupil, unNormPSF_atExitPupil, 0.0, 1000.0, cv::NORM_MINMAX);

	real sumUnNormPSF = cv::sum(unNormPSF_atExitPupil)[0];
	std::cout << "sum unnorm PSF: " << sumUnNormPSF << std::endl;

	cv::resize(unNormPSF_atExitPupil, PSF_targetSize, cv::Size(targetHeight, targetWidth), cv::INTER_LANCZOS4);

	//if (heightUnNormPSF <= targetHeight)
	//{
	//	PSF_targetSize = cv::Mat::zeros(cv::Size(targetHeight, targetWidth), unNormPSF_atExitPupil.type());
	//	unNormPSF_atExitPupil.copyTo(PSF_targetSize(cv::Range((targetHeight - heightUnNormPSF) / 2, (heightUnNormPSF + targetHeight) / 2), cv::Range((targetWidth - widthUnNormPSF) / 2, (targetWidth + widthUnNormPSF) / 2)));
	//}
	//else
	//{
	//	PSF_targetSize = unNormPSF_atExitPupil(cv::Rect((heightUnNormPSF - targetHeight) / 2, (heightUnNormPSF - targetHeight) / 2, targetHeight, targetWidth));
	//}

	real sumPSF_targetSize = cv::sum(PSF_targetSize)[0];
	std::cout << "sum PSF target size: " << sumPSF_targetSize << std::endl;

	unsigned int heightTargetPSF = PSF_targetSize.size().height;
	unsigned int widthTargetPSF = PSF_targetSize.size().width;

	cv::Mat returnTargetPSF;
	if (heightTargetPSF <= heightUnNormPSF)
	{
		returnTargetPSF = cv::Mat::zeros(cv::Size(heightUnNormPSF , widthUnNormPSF), unNormPSF_atExitPupil.type());
		PSF_targetSize.copyTo(returnTargetPSF(cv::Range((heightUnNormPSF - heightTargetPSF) / 2, (heightUnNormPSF + heightTargetPSF) / 2), cv::Range((widthUnNormPSF - widthTargetPSF) / 2, (widthUnNormPSF + widthTargetPSF) / 2)));
	
	}

	else
	{
		
		 cv::Mat returnTargetPSF(PSF_targetSize, cv::Rect((heightTargetPSF - heightUnNormPSF) / 2, (widthTargetPSF - widthUnNormPSF) / 2, heightUnNormPSF, widthUnNormPSF));
		 return returnTargetPSF;
	}

	
	//real sumTargetPSF = cv::sum(returnTargetPSF)[0];
	//std::cout << "sum target PSF: " << sumTargetPSF << std::endl;
	return returnTargetPSF;
}

void PSF::calcSizePerPixel_PSFAtImageSurface_µm(real distanceEXP_ImaSurface_mm, real wavelength_nm, real EXPD_mm, unsigned int paddingFactor)
{
	mSizePerPixelAtImaSurface_µm = (distanceEXP_ImaSurface_mm / 1000.0) * (wavelength_nm * 1000.0) / (EXPD_mm * 1000.0 * paddingFactor);
}


// get size per pixel norm PSF
real PSF::getSizePerPixcelAtImaSurface_µm()
{
	return mSizePerPixelAtImaSurface_µm;
}

// resize object to match size of pixel PSF
void PSF::resizeObjectToMachSizePixelPSF(cv::Mat& initialObject, cv::Mat& resisedObject, real magnification, real heightObject, real distanceEXP_ImaSurface_mm, real wavelength_nm, real EXPD_mm, unsigned int paddingFactor)
{
	real sizePerPixelObj_µm = (real)heightObject * 1000.0 / (real)initialObject.size().height;
	calcSizePerPixel_PSFAtImageSurface_µm(distanceEXP_ImaSurface_mm, wavelength_nm, EXPD_mm, paddingFactor);

	real sizePerPixelPSF_objectSpace = std::abs(mSizePerPixelAtImaSurface_µm / magnification);

	real resizeFactorObject = sizePerPixelObj_µm / sizePerPixelPSF_objectSpace;
	// real resizeFactorObject = sizePerPixelPSF_objectSpace / sizePerPixelObj_µm;

	unsigned int initialHeightObject = initialObject.size().height;
	unsigned int initialWidthObject = initialObject.size().width;

	unsigned int targetHeightObject = initialHeightObject * resizeFactorObject;
	unsigned int targetWidthObject = initialWidthObject * resizeFactorObject;

	cv::resize(initialObject, resisedObject, cv::Size(targetWidthObject, targetHeightObject), cv::INTER_LANCZOS4);


}

void PSF::calculatePSF_superFunction(OpticalSystemElement optSysEle, real wavelength_nm, VectorStructR3 fieldPointRay)
{
	optSysEle.setRefractiveIndexAccordingToWavelength(wavelength_nm);
	OpticalSystem_LLT optSysLLT = optSysEle.getOptSys_LLT_buildSystem();


	Light_LLT light;
	light.setWavelength(wavelength_nm);
	light.setTypeLight(mLoadParaPSF.getLightType());
	light.setIntensity(mLoadParaPSF.getIntensityLight());
	light.setJonesVector(mLoadParaPSF.getJonesVector());


	// fill aperture stop with points
	FillApertureStop fillAS_128;
	infosAS infAS_128 = optSysEle.getInfoAS();
	std::vector<VectorStructR3> pointsInAS_128 = fillAS_128.fillAS_withPoints(mLoadParaPSF.getRayDensity(), infAS_128.getPointAS(), infAS_128.getDirAS(), infAS_128.getSemiHeightAS());

	// ray aiming
	RayAiming rayAiming;
	std::vector<LightRayStruct> aimedLightRays = rayAiming.rayAimingMany_obj_complete(optSysLLT, pointsInAS_128, fieldPointRay, light);
	// calculate OPD
	mOPD.setOpticalSystemLLT(optSysLLT);
	mOPD.setAimedLightRays(aimedLightRays);
	mOPD.setInfOrObj(mLoadParaPSF.getObjectPoint_inf_obj());
	mOPD.setSizeMatrixToSave(mLoadParaPSF.getSizeMatrixOPD());
	mOPD.setMaxIterationsBilinInterpol(mLoadParaPSF.getMaxIteraBilinInterpola());
	mOPD.calcGlobalOPD_new();
	mOPD.bilinearInterpolToFillHolesInOPDmatrix();


	mPSF_exitPupil = calcPSF_FFT_NEW(mOPD.getUpsampledGlobalOPD());

	// cardinal points
	CardinalPoints carPoints(optSysLLT, mLoadParaPSF.getObjectPoint_inf_obj());
	real distanceEXP_ImaSurface_mm = carPoints.getEXPP_lastSurface();
	real EXPD_mm = carPoints.getEXPD();

	mNormPSF_ImaSurface_targetSize = normPSFtoTargetPixelSize_AtImaSurface(mPSF_exitPupil, mLoadParaPSF.getTargetPixelSize_µm(), distanceEXP_ImaSurface_mm, wavelength_nm, EXPD_mm, mLoadParaPSF.getPaddingFactor());


}

// calculate norm PSF at image surface
cv::Mat PSF::calcNormPSF_ImaSurface(cv::Mat OPD, real wavelength, real EXPD_mm, real EXPP_mm, real targetPixelSize_µm, unsigned int paddingFactor)
{
	mPSF_exitPupil = calcPSF_FFT_NEW(OPD);
	return normPSFtoTargetPixelSize_AtImaSurface(mPSF_exitPupil, targetPixelSize_µm, EXPP_mm, wavelength, EXPD_mm, paddingFactor);

}

// size matrix OPD
unsigned int PSF::getSizeMatrixOPD()
{
	return mLoadParaPSF.getSizeMatrixOPD();
}
void PSF::setSizeMatrixOPD(unsigned int sizeMatrixOPD)
{
	mLoadParaPSF.setSizeMatrixOPD(sizeMatrixOPD);
}
// ray density
unsigned int PSF::getRayDensity()
{
	return mLoadParaPSF.getRayDensity();
}
void PSF::setRayDensity(unsigned int rayDensity)
{
	mLoadParaPSF.setRayDensity(rayDensity);
}
// light ray type
typeLight PSF::getLightType()
{
	return mLoadParaPSF.getLightType();
}
void PSF::setLightType(typeLight lightType)
{
	mLoadParaPSF.setLightType(lightType);
}
// intensity light 
real PSF::getIntensityLight()
{
	return mLoadParaPSF.getIntensityLight();
}
void PSF::setIntensityLight(real intensityLight)
{
	mLoadParaPSF.setIntensityLight(intensityLight);
}
// jones vector
JonesVector_LLT PSF::getJonesVector()
{
	return mLoadParaPSF.getJonesVector();
}
void PSF::setJonesVector(JonesVector_LLT jonesVector)
{
	mLoadParaPSF.setJonesVector(jonesVector);
}
// object point inf obj
objectPoint_inf_obj PSF::getObjectPoint_inf_obj()
{
	return mLoadParaPSF.getObjectPoint_inf_obj();
}
void PSF::setObjectPoint_inf_obj(objectPoint_inf_obj objectPoint_inf_obj)
{
	mLoadParaPSF.setObjectPoint_inf_obj(objectPoint_inf_obj);
}
// max interation bilinear interpolation
unsigned int PSF::PSF::getMaxIteraBilinInterpola()
{
	return mLoadParaPSF.getMaxIteraBilinInterpola();
}
void PSF::setMaxInteraBilinInterpolation(unsigned maxIterBilIterpol)
{
	mLoadParaPSF.setMaxInteraBilinInterpolation(maxIterBilIterpol);
}
// target pixel size
real PSF::getTargetPixelSize_µm()
{
	return mLoadParaPSF.getTargetPixelSize_µm();
}
void PSF::setTargetPixelSize_µm(real targetPixelSize)
{
	mLoadParaPSF.setTargetPixelSize_µm(targetPixelSize);
}
// padding factor
unsigned int PSF::getPaddingFactor()
{
	return mLoadParaPSF.getPaddingFactor();
}
void PSF::setPaddingFactor(unsigned int paddingFactor)
{
	mLoadParaPSF.setPaddingFactor(paddingFactor);
}

// load Parameter
void PSF::loadParameter(loadParameterPSF parameterToLoad)
{
	mLoadParaPSF = parameterToLoad;
}
// global OPD
cv::Mat PSF::getGlobalOPD_deepCopy()
{
	return mOPD.getGlobalOPD_deepCopy();
}
// global sampled up OPD
cv::Mat PSF::getGlobalOPD_sampledUP_deepCopy()
{
	return mOPD.getUpsampledGlobalOPD_deepCopy();
}
// get PSF at exit pupil
cv::Mat PSF::getPSF_exitPupil()
{
	return mPSF_exitPupil;
}
// get PSF image surface target size
cv::Mat PSF::getPSF_imaSurface_targetSize()
{
	return mNormPSF_ImaSurface_targetSize;
}