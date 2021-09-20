#include "ImageSimulation.h"
#include <iostream>

#include "..\..\Analyse\OpticalPathDifference.h"
#include "..\..\LowLevelTracing\Surfaces\SphericalSurface_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\PlanGeometry_LLT.h"
#include "..\..\LowLevelTracing\OpticalSystem_LLT.h"
#include "..\..\LowLevelTracing\Interaction\RefractedRay_LLT.h"
#include "..\..\SequentialRayTracing\SequentialRayTracer.h"
#include "..\..\LowLevelTracing\Surfaces\ParaxialLens_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DeflectedRayParaxialLens_LLT.h"
#include "..\..\LowLevelTracing\Interaction\DoNothingInteraction_LLT.h"
#include "..\..\FillAptertureStop\FillApertureStop.h"
#include "..\..\Analyse\Spot.h"
#include "..\..\LowLevelTracing\Interaction\Absorb_LLT.h"
#include "..\..\LowLevelTracing\Surfaces\ApertureStop_LLT.h"

#include "..\..\FillAptertureStop\FillApertureStop.h"
#include"Images.h"

// ray aiming
#include "..\RayAiming\RayAiming.h"

// import export data
#include "..\Inport_Export_Data\Inport_Export_Data.h"

// calculate PSF
#include "..\Point-Spread Function\Point-Spread Function.h"

// often use namespace
#include "..\oftenUseNamespace\oftenUseNamespace.h"

// cardinal points
#include "..\Analyse\CardinalPoints.h"

// distortion
#include "..\Analyse\Distortion.h"

loadParaImaSim::loadParaImaSim() {};
loadParaImaSim::~loadParaImaSim() {};

// row bigger for convolution
unsigned int loadParaImaSim::getRowBiggerForConv()
{
	return mRow_BiggerForConv;
}
void loadParaImaSim::setRowBiggerForConV(unsigned int rowBiggerConv)
{
	mRow_BiggerForConv = rowBiggerConv;
}
// col bigger for convolution
unsigned int loadParaImaSim::getColBiggerForConv()
{
	return mCol_BiggerForConv;
}
void loadParaImaSim::setColBiggerForConv(unsigned int colBiggerConv)
{
	mCol_BiggerForConv = colBiggerConv;
}
// wave blue
real loadParaImaSim::getWavelengthBlue()
{
	return mWavelength_blue;
}
void loadParaImaSim::setWavelengthBlue(real waveBlue)
{
	mWavelength_blue = waveBlue;
}
// wave green
real loadParaImaSim::getWavelengthGreen()
{
	return mWavelength_green;
}
void loadParaImaSim::setWavelengthGreen(real waveGreen)
{
	mWavelength_green = waveGreen;
}
// wave red
real loadParaImaSim::getWavelengthRed()
{
	return mWavelength_red;
}
void loadParaImaSim::setWavelengthRed(real waveRed)
{
	mWavelength_red = waveRed;
}
// ray density
real loadParaImaSim::getRayDensity()
{
	return mRayDesnity;
}
void loadParaImaSim::setRayDensity(unsigned int rayDensity)
{
	mRayDesnity = rayDensity;
}
// light
Light_LLT loadParaImaSim::getLight()
{
	return mLight;
}
void loadParaImaSim::setLight(Light_LLT light)
{
	mLight = light;
}

// size matrix to save OPD
unsigned int loadParaImaSim::getSizeMatrixToSaveOPD()
{
	return mSizeMatrixToSaveOPD;
}
void loadParaImaSim::setSizeMatrixToSaveOPD(unsigned int sizeMatrixOPD)
{
	mSizeMatrixToSaveOPD = sizeMatrixOPD;
}
// inf of obj
void loadParaImaSim::setInfOrObj(objectPoint_inf_obj inf_obj)
{
	mInf_obj = inf_obj;
}
objectPoint_inf_obj loadParaImaSim::getInfOrObj()
{
	return mInf_obj;
}
// row and col resize OPD
void loadParaImaSim::setRowColResizeOPD(unsigned int rowAndCol)
{
	mRowColResizeOPD = rowAndCol;
}
unsigned int loadParaImaSim::getRowAndColResizeOPD()
{
	return mRowColResizeOPD;
}
// sampling _x
void loadParaImaSim::setSampling_x(unsigned int sampling_x)
{
	mSampling_x = sampling_x;
}
unsigned loadParaImaSim::getSampling_x()
{
	return mSampling_x;
}
// sampling _y
void loadParaImaSim::setSampling_y(unsigned int sampling_y)
{
	mSampling_y = sampling_y;
}
unsigned loadParaImaSim::getSampling_y()
{
	return mSampling_y;
}
// semi height object
void loadParaImaSim::setSemiHeightObj(real semiHeightObject)
{
	mSemiHeightObject = semiHeightObject;
}
real loadParaImaSim::getSemiHeightObj()
{
	return mSemiHeightObject;
}
// semi weidth object
void loadParaImaSim::setSemiWeidthObj(real semiWeigthObject)
{
	mSemiWeidthObject = semiWeigthObject;
}
real loadParaImaSim::getSemiWidthObj()
{
	return mSemiWeidthObject;
}
// position Z object
void loadParaImaSim::setPosition_Z_Object(real pos_Z_obj)
{
	mPosition_Z_Object = pos_Z_obj;
}
real loadParaImaSim::getPosition_Z_Object()
{
	return mPosition_Z_Object;
}
// up sample PSF
void loadParaImaSim::setUpSamplePSF(bool upSamplePSF)
{
	mUpSamplePSF = upSamplePSF;
}
bool loadParaImaSim::getUpSamplePSF()
{
	return mUpSamplePSF;
}
// resize OPD linear
void loadParaImaSim::setResizeOPD_linear(bool resizeOPD_linear)
{
	mResizeOPD_linear = resizeOPD_linear;
}
bool loadParaImaSim::getResizeOPD_linear()
{
	return mResizeOPD_linear;
}
// padding factor PSF
void loadParaImaSim::setPaddingFactorPSF(unsigned int paddingFactor)
{
	mPaddingFactorPSF = paddingFactor;
}
unsigned int loadParaImaSim::getPaddingFactorPSF()
{
	return mPaddingFactorPSF;
}
void loadParaImaSim::setCalcDistortion(bool calcDistortion)
{
	mCalcDistortion = calcDistortion;
}
bool loadParaImaSim::getCalcDistortion()
{
	return mCalcDistortion;
}
// sampling distortion height
void loadParaImaSim::setSamplingDistortionHeight(unsigned int samplingDisHeight)
{
	mSamplingDistortionHeight = samplingDisHeight;
}
unsigned int loadParaImaSim::getSamplingDistortionHeight()
{
	return mSamplingDistortionHeight;
}
// sampling distortion height
void loadParaImaSim::setSamplingDistortionWidth(unsigned int samplingDisWidth)
{
	mSamplingDistortionWidth = samplingDisWidth;
}
unsigned int loadParaImaSim::getSamplingDistortionWidth()
{
	return mSamplingDistortionWidth;
}

void loadParaImaSim::loadImportandStuff()
{
	setWavelengthBlue(486.1327);
	setWavelengthGreen(587.5818);
	setWavelengthRed(656.2725);
	setRayDensity(6);

	//light
	Light_LLT light;
	light.setWavelength(550.0);
	light.setIntensity(1.0);
	light.setJonesVector({ 1.0,1.0,1.0,1.0 });
	light.setTypeLight(typeLight::typeLightRay);

	setLight(light);
	setSizeMatrixToSaveOPD(128);
	setInfOrObj(objectPoint_inf_obj::obj);
	setRowColResizeOPD(64);
	setSampling_x(9);
	setSemiHeightObj(2.0);
	setSemiWeidthObj(2.0);
	setPosition_Z_Object(0.0);
	setUpSamplePSF(true);
	setResizeOPD_linear(true);
	setPaddingFactorPSF(6);
}



ImageSimulationFunctions::ImageSimulationFunctions() {};
ImageSimulationFunctions::~ImageSimulationFunctions() {};

void ImageSimulationFunctions::setInitialObject(cv::Mat initialObj)
{
	mInitialObj = initialObj;
}

void ImageSimulationFunctions::imageSimulationSuperFct(/*optical System Element*/ OpticalSystemElement optSysEle, cv::Mat initialObj, loadParaImaSim defaulPara)
{
	// save default parameter
	mLoadParameterImaSim = defaulPara;
	// save the optical system element
	mOptSysEle = optSysEle;
	// save the initial object
	mInitialObj = initialObj;
	// check refractiv indesx before first surface
	getRefIndexBeforeFirstSurface();
	// build all optical systems LLT
	buildAllOptSysLLT_BGR();
	// calc with object according to height
	calcWidthAccordingToHeight();
	// calculate points to sample object
	calcPointsToSampleObject();
	// calculate ray density according to OPD size
	calcRayDensityAccordingToOPDsize();
	// trace the rays and calculate OPS upsampled
	calcALL_OPDs();
	// check for resize OPD linear
	checkForResizeOPD();
	// calculate all PSFs
	calcAllPSFs();
	//normalizeAllPSFs();
	// check for up sampling psf
	checkForUpSamplingPSF();
	// rotate the PSFs to get all PSFs for convolution
	calcAllPSFsForConv_Q1();
	calcAllPSFsForConv_Q2andQ3();

	if (mLoadParameterImaSim.getUpSamplePSF())
	{
		// adaped sampling
		mLoadParameterImaSim.setSampling_x(mLoadParameterImaSim.getSampling_x() + mLoadParameterImaSim.getSampling_x() - 1);
		mLoadParameterImaSim.setSampling_y(mLoadParameterImaSim.getSampling_y() + mLoadParameterImaSim.getSampling_y() - 1);
	}



	// resize the PSFs and calc best values for row and cols bigger for convolution
	adapetSizeObject_ForConv();
	// adaped the object for later image simulation
	adaptTheObjectForSimulation();
	// split the bgr object in separet objects 
	splitTheBGRImageInColors();
	//separateTheImageInNtimesMimages();
	separateTheImageInNtimesMimages();
	//separateTheImageInNtimesMimages();
	// convolute the 
	convoluteObjectGridWithPSF();
	// put the image grids together
	//putImaGridsTogether();
	//putImaGridsTogether_saveThatFct();
	putImaGridsTogether();
	// integrate distortion
	if (mLoadParameterImaSim.getCalcDistortion())
	{
		calcDistortedImages();
	}
	

	// norm the separated images (RBG) between min and max
	// normSepImagesMinAndMax();
	//fillingBlackStrips();
	// put all channles together, scale the image and save the image as CV_8UC 
	putAllChannlesTogetherScaleAndSaveIma();


}

void ImageSimulationFunctions::setRowBiggerForConv(unsigned int pixBiggerRow)
{
	mLoadParameterImaSim.setRowBiggerForConV(pixBiggerRow);
}
void ImageSimulationFunctions::setColBiggerForConv(unsigned int pixBiggerCol)
{
	mLoadParameterImaSim.setColBiggerForConv(pixBiggerCol);
}

void ImageSimulationFunctions::fillingBlackStrips()
{
	unsigned int rowObjAda = mAdaptedObj_blue.rows;
	unsigned int colObjAda = mAdaptedObj_blue.cols;

	unsigned int tempStartRow = 0;
	unsigned int separationRow = rowObjAda / mLoadParameterImaSim.getSampling_x();
	unsigned int tempEndRow = separationRow;

	unsigned int tempStartCol = 0;
	unsigned int separationCol = (colObjAda / mLoadParameterImaSim.getSampling_x());
	unsigned int tempEndCol = separationCol;

	float tempValBefore{};
	float tempValAfter{};
	
	unsigned int sepRowMinTen = separationRow - 10;
	unsigned int sepColMinTen = separationCol - 10;

	unsigned int sepRowPlusOne = separationRow + 1;
	unsigned int sepColPlusOne = separationCol + 1;

	unsigned int tempRow = separationRow;
	unsigned int tempCol = separationCol;

	
	//cv::Rect region(sepColMinTen, 0, 20, rowObjAda);
	//for (unsigned int c = 0; c < mGridFactor; ++c) // vertical
	//{
	//cv::Mat destiantion_blue;
	//cv::Mat destiantion_green;
	//cv::Mat destiantion_red;
	//	
	//cv::bilateralFilter(mSimulatedIma_blue, destiantion_blue, 9, 75, 75);
	//cv::bilateralFilter(mSimulatedIma_green, destiantion_green, 9, 75, 75);
	//cv::bilateralFilter(mSimulatedIma_green, destiantion_red, 9, 75, 75);
	//
	//mSimulatedIma_blue = destiantion_blue;
	//mSimulatedIma_green = destiantion_green;
	//mSimulatedIma_red = destiantion_red;

		//cv::GaussianBlur(mSimulatedIma_blue(region), mSimulatedIma_blue(region), cv::Size(0, 0), 4);
		//cv::GaussianBlur(mSimulatedIma_green(region), mSimulatedIma_green(region), cv::Size(0, 0), 4);
		//cv::GaussianBlur(mSimulatedIma_red(region), mSimulatedIma_red(region), cv::Size(0, 0), 4);
		//sepColMinTen = sepColMinTen + separationCol;
	//}


	//for (unsigned int c = 0; c < mGridFactor - 1; ++c)
	//{
	//	for (unsigned int i = 0; i < colObjAda; ++i)
	//	{
	//		tempValBefore = mSimulatedIma_blue.at<float>(sepRowMinOne, i);
	//		tempValAfter = mSimulatedIma_blue.at<float>(sepRowPlusOne, i);
	//		mSimulatedIma_blue.at<float>(tempRow, i) = (tempValBefore + tempValAfter) / 2;
	//
	//		tempValBefore = mSimulatedIma_green.at<float>(sepRowMinOne, i);
	//		tempValAfter = mSimulatedIma_green.at<float>(sepRowPlusOne, i);
	//		mSimulatedIma_green.at<float>(tempRow, i) = (tempValBefore + tempValAfter) / 2;
	//
	//		tempValBefore = mSimulatedIma_red.at<float>(sepRowMinOne, i);
	//		tempValAfter = mSimulatedIma_red.at<float>(sepRowPlusOne, i);
	//		mSimulatedIma_red.at<float>(tempRow, i) = (tempValBefore + tempValAfter) / 2;
	//
	//	}
	//
	//	sepRowMinOne = sepRowMinOne + separationRow;
	//	tempRow = tempRow + separationRow;
	//	sepRowPlusOne = sepRowPlusOne + separationRow;
	//}
	//
	//for (unsigned int r = 0; r < mGridFactor - 1; ++r)
	//{
	//	for (unsigned int j = 0; j < rowObjAda; ++j)
	//	{
	//		tempValBefore = mSimulatedIma_blue.at<float>(j, sepColMinOne);
	//		tempValAfter = mSimulatedIma_blue.at<float>(j, sepColPlusOne);
	//		mSimulatedIma_blue.at<float>(j, tempCol) = (tempValBefore + tempValAfter) / 2;
	//
	//		tempValBefore = mSimulatedIma_green.at<float>(j, sepColMinOne);
	//		tempValAfter = mSimulatedIma_green.at<float>(j, sepColPlusOne);
	//		mSimulatedIma_green.at<float>(j, tempCol) = (tempValBefore + tempValAfter) / 2;
	//
	//		tempValBefore = mSimulatedIma_red.at<float>(j, sepColMinOne);
	//		tempValAfter = mSimulatedIma_red.at<float>(j, sepColPlusOne);
	//		mSimulatedIma_red.at<float>(j, tempCol) = (tempValBefore + tempValAfter) / 2;
	//
	//	}
	//
	//	sepColMinOne = sepColMinOne + separationCol;
	//	tempCol = tempCol + separationCol;
	//	sepColPlusOne = sepColPlusOne + separationCol;
	//}

	//
	//mSimulatedIma_red.at<float>(0, separationCol) = 10000.0;
	//mSimulatedIma_red.at<float>(1, separationCol) = 10000.0;
	//mSimulatedIma_red.at<float>(2, separationCol) = 10000.0;
	//mSimulatedIma_red.at<float>(3, separationCol) = 10000.0;
	//mSimulatedIma_red.at<float>(4, separationCol) = 10000.0;
	//float valueStripe1 = mSimulatedIma_red.at<float>(0, separationCol);
	//float valueStripe2 = mSimulatedIma_red.at<float>(0, separationCol+1);
	// just for debugging
	// Images::saveImage("..", "testRed", "png", mSimulatedIma_red);
}

void ImageSimulationFunctions::convoluteObjectGridWithPSF()
{
	unsigned int size = mObjectGrid_blue.size();
	//cv::Mat convertedObject_blue{};
	//cv::Mat convertedObject_green{};
	//cv::Mat convertedObject_red{};
	
	mSimulatedImageGrid_blue.resize(size);
	mSimulatedImageGrid_green.resize(size);
	mSimulatedImageGrid_red.resize(size);

	// just for debugging
	// std::string counterStr;
	// int test = 1;

	for (unsigned int i = 0; i < size; ++i)
	{
		// blue
		//mObjectGrid_blue[i].convertTo(convertedObject_blue, CV_64F);
		mSimulatedImageGrid_blue[i] = convolution_Gray_unit8(mObjectGrid_blue[i], mAllPSFForConv_blue[i]);
		//mSimulatedImageGrid_blue[i] = convolution(mObjectGrid_blue[i], mLoadedPSFs_vec_blue[i]);
		
		//// just for debugging
		//real sumPSF_blue = cv::sum(mAllPSFForConv_blue[i])[0];
		//std::cout << "sum PSF blue: " << sumPSF_blue << std::endl;

		// just for debugging
		// if (test == 1)
		// { 
		// 	Images::showImage_inputUint8("grid ima blue", mObjectGrid_blue[i]);
		// 	Images::showImage_inputReal("psf", mAllPSFForConv_blue[i]);
		// 	counterStr = std::to_string(i);
		// 	Images::saveImage("..", "convolutedBlue" + counterStr, "png", mSimulatedImageGrid_blue[i]);
		// 	test = 2;
		// }

		// green
		//mObjectGrid_green[i].convertTo(convertedObject_green, CV_64F);
		mSimulatedImageGrid_green[i] = convolution_Gray_unit8(mObjectGrid_green[i], mAllPSFForConv_green[i]);
		// /*test*/ mSimulatedImageGrid_green[i] = convolution(convertedObject_green, mAllPSFForConv_blue[i]);

		//// just for debugging
		//real sumPSF_green = cv::sum(mAllPSFForConv_green[i])[0];
		//std::cout << "sum PSF green: " << sumPSF_green << std::endl;

		// red
		//mObjectGrid_red[i].convertTo(convertedObject_red, CV_64F);
		mSimulatedImageGrid_red[i] = convolution_Gray_unit8(mObjectGrid_red[i], mAllPSFForConv_red[i]);
		// /*test*/mSimulatedImageGrid_red[i] = convolution(convertedObject_red, mAllPSFForConv_blue[i]);

		//// just for debugging
		//real sumPSF_red = cv::sum(mAllPSFForConv_red[i])[0];
		//std::cout << "sum PSF red: " << sumPSF_red << std::endl;
	}
}

cv::Mat ImageSimulationFunctions::getAdaptedObj_blue()
{
	return mAdaptedObj_blue;
}
cv::Mat ImageSimulationFunctions::getAdaptedObj_green()
{
	return mAdaptedObj_green;
}
cv::Mat ImageSimulationFunctions::getAdaptedObj_red()
{
	return mAdaptedObj_red;
}

void ImageSimulationFunctions::separateTheImageInNtimesMimages_saveThatFct_1()
{
	std::vector <cv::Mat> retrunObjectGrid;

	unsigned int rowObjAda = mAdaptedObj_blue.rows;
	unsigned int colObjAda = mAdaptedObj_blue.cols;

	unsigned int tempStartRow = 0;
	unsigned int separationRow = rowObjAda / mLoadParameterImaSim.getSampling_x();
	unsigned int tempEndRow = separationRow;

	unsigned int tempStartCol = 0;
	unsigned int separationCol = (colObjAda / mLoadParameterImaSim.getSampling_x());
	unsigned int tempEndCol = separationCol;


	unsigned int sizeObjGrid = mLoadParameterImaSim.getSampling_x() * mLoadParameterImaSim.getSampling_x();
	mObjectGrid_blue.resize(sizeObjGrid);
	mObjectGrid_green.resize(sizeObjGrid);
	mObjectGrid_red.resize(sizeObjGrid);
	unsigned int counter = 0;

	cv::Mat tempSeparatedObject_blue;
	cv::Mat tempSeparatedObject_green;
	cv::Mat tempSeparatedObject_red;


	for (unsigned int i = 0; i < mLoadParameterImaSim.getSampling_x(); ++i)
	{
		for (unsigned int j = 0; j < mLoadParameterImaSim.getSampling_x(); ++j)
		{

			tempSeparatedObject_blue = mAdaptedObj_blue(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol));
			tempSeparatedObject_green = mAdaptedObj_green(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol));
			tempSeparatedObject_red = mAdaptedObj_red(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol));

			// just for debugging
			//Images::showImage("tempGridMat", tempSeparatedObject_blue);
			//Images::saveImage("../", "testSave", "png", tempSeparatedObject_blue);

			mObjectGrid_blue[counter] = tempSeparatedObject_blue;
			mObjectGrid_green[counter] = tempSeparatedObject_green;
			mObjectGrid_red[counter] = tempSeparatedObject_red;
			++counter;

			tempStartCol = tempEndCol;
			tempEndCol = tempEndCol + separationCol;

		}

		tempStartCol = 0;
		tempEndCol = separationCol;

		tempStartRow = tempEndRow ;
		tempEndRow = tempEndRow + separationRow;

	}

}

void ImageSimulationFunctions::putImaGridsTogether_saveThatFct_1()
{
	unsigned int rowObjAda = mAdaptedObj_blue.rows;
	unsigned int colObjAda = mAdaptedObj_blue.cols;

	unsigned int tempStartRow = 0;
	unsigned int separationRow = rowObjAda / mLoadParameterImaSim.getSampling_x();
	unsigned int tempEndRow = separationRow;

	unsigned int tempStartCol = 0;
	unsigned int separationCol = (colObjAda / mLoadParameterImaSim.getSampling_x());
	unsigned int tempEndCol = separationCol;


	unsigned int sizeObjGrid = mLoadParameterImaSim.getSampling_x() * mLoadParameterImaSim.getSampling_x();

	mSimulatedIma_blue = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_blue[0].type());
	mSimulatedIma_green = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_green[0].type());
	mSimulatedIma_red = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_red[0].type());

	cv::Mat imagePart_blue;
	cv::Mat imagePart_green;
	cv::Mat imagePart_red;

	unsigned int counter = 0;
	// just for debugging
	// std::string counterStr;

	for (unsigned int i = 0; i < mLoadParameterImaSim.getSampling_x(); ++i)
	{
		for (unsigned int j = 0; j < mLoadParameterImaSim.getSampling_x(); ++j)
		{

			mSimulatedImageGrid_blue[counter].copyTo(mSimulatedIma_blue(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol)));
			// just for debugging
			//Images::showImage("blue ima grid", mSimulatedImageGrid_blue[i]);
			//Images::showImage("blue ima", mSimulatedIma_blue);
			//counterStr = std::to_string(counter);
			//Images::saveImage("..", "partBlue" + counterStr, "png", mSimulatedImageGrid_blue[counter]);


			mSimulatedImageGrid_green[counter].copyTo(mSimulatedIma_green(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol)));

			mSimulatedImageGrid_red[counter].copyTo(mSimulatedIma_red(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol)));

			tempStartCol = tempEndCol;
			tempEndCol = tempEndCol + separationCol;

			++counter;

		}

		tempStartCol = 0;
		tempEndCol = separationCol;

		tempStartRow = tempEndRow;
		tempEndRow = tempEndRow + separationRow;

	}
}

void ImageSimulationFunctions::adaptTheObjectForSimulation()
{
	
	//int a = mResizedObjectForConvolution.size().height;
	//a = a - (a % (mLoadParameterImaSim.getSampling()) );
	//int b = mResizedObjectForConvolution.size().width;
	//b = b - (b % (mLoadParameterImaSim.getSampling()));
	//
	//cv::Rect ROI(0, 0, b, a);
	//mAdaptedObj = mResizedObjectForConvolution(ROI);
	
	mAdaptedObj = mResizedObjectForConvolution;
}

cv::Mat ImageSimulationFunctions::getTheAdaptedObject()
{
	return mAdaptedObj;
}

void ImageSimulationFunctions::splitTheBGRImageInColors()
{
	cv::Mat channel[3];
	cv::split(mAdaptedObj, channel);

	
	mAdaptedObj_blue = channel[0];
	//// just for debugging
	//real minBlue{};
	//real maxBlue{};
	//cv::minMaxLoc(mAdaptedObj_blue, &minBlue, &maxBlue);

	mAdaptedObj_green = channel[1];
	//// just for debugging
	//real minGreen{};
	//real maxGreen{};
	//cv::minMaxLoc(mAdaptedObj_green, &minGreen, &maxGreen);


	mAdaptedObj_red = channel[2];
	//// just for debugging
	//real minRed{};
	//real maxRed{};
	//cv::minMaxLoc(mAdaptedObj_red, &minRed, &maxRed);

	// just for debugging
	// Images::showImage("blue ima", mAdaptedObj_blue);
	// Images::showImage("green ima", mAdaptedObj_green);
	// Images::showImage("red ima", mAdaptedObj_red);
	// cv::Mat ima_BGR;
	// cv::merge(channel, 3, ima_BGR);
	// Images::showImage("BGR ima", ima_BGR);

}
void ImageSimulationFunctions::setOpticalSystemElement(OpticalSystemElement optSysEle)
{
	mOptSysEle = optSysEle;
}
void ImageSimulationFunctions::setInitialParameters(loadParaImaSim initialParaImaSim)
{
	mLoadParameterImaSim = initialParaImaSim;
}

void ImageSimulationFunctions::loadPSFs_blue(std::vector<cv::Mat> PSF_vec_blue)
{
	mAllPSFForConv_blue = PSF_vec_blue;
}
void ImageSimulationFunctions::loadPSFs_green(std::vector<cv::Mat> PSF_vec_green)
{
	mAllPSFForConv_green = PSF_vec_green;
}
void ImageSimulationFunctions::loadPSFs_red(std::vector<cv::Mat> PSF_vec_red)
{
	mAllPSFForConv_red = PSF_vec_red;
}

void ImageSimulationFunctions::plotAllObjektGrids(std::vector<cv::Mat> objGrid_vec)
{
	
	unsigned sizeGrid = objGrid_vec.size();
	std::string tempString{};

	for (unsigned int i = 0; i < sizeGrid; ++i)
	{
		tempString = std::to_string(i);
		Images::showImage_inputReal_normTheImage(tempString, objGrid_vec[i]);
	}
	
}

cv::Mat ImageSimulationFunctions::convolution_BGR_uint8(const cv::Mat obj, const cv::Mat PSF)
{



	// see: https://docs.opencv.org/3.4/d4/d86/group__imgproc__filter.html#ga27c049795ce870216ddfb366086b5a04

	cv::Mat convertedObj;
	obj.convertTo(convertedObj, CV_64FC3, 1.0 / 255.0);

	real kernel_sum = cv::sum(PSF)[0];
	PSF /= kernel_sum;

	cv::Mat flipped_kernel;
	cv::flip(PSF, flipped_kernel, -1);

	cv::Point anchor(PSF.cols - PSF.cols / 2 - 1, PSF.rows - PSF.rows / 2 - 1);
	int delta = 0;
	int ddepth = -1;
	cv::Mat convolutedIma;

	
	cv::filter2D(convertedObj, convolutedIma, ddepth, flipped_kernel, anchor, delta, cv::BORDER_DEFAULT);

	return convolutedIma;
}


cv::Mat ImageSimulationFunctions::convolution_Gray_unit8(const cv::Mat obj, const cv::Mat PSF)
{
	// see: https://docs.opencv.org/3.4/d4/d86/group__imgproc__filter.html#ga27c049795ce870216ddfb366086b5a04

	cv::Mat convertedObj;
	obj.convertTo(convertedObj, CV_64FC1, 1.0 / 255.0 );

	
	real kernel_sum = cv::sum(PSF)[0];
	PSF /= kernel_sum;

	cv::Mat flipped_kernel;
	cv::flip(PSF, flipped_kernel, -1);

	cv::Point anchor(PSF.cols - PSF.cols / 2 - 1, PSF.rows - PSF.rows / 2 - 1);
	int delta = 0;
	int ddepth = -1;
	cv::Mat convolutedIma;


	cv::filter2D(convertedObj, convolutedIma, ddepth, flipped_kernel, anchor, delta, cv::BORDER_DEFAULT);

	return convolutedIma;
}







void ImageSimulationFunctions::putAllChannlesTogetherScaleAndSaveIma()
{

	if (mLoadParameterImaSim.getCalcDistortion())
	{
		checkIntensityDistortedImages();

		std::vector<cv::Mat> array_to_merge;
		array_to_merge.push_back(mSimulatedIma_blue_initialSize);
		array_to_merge.push_back(mSimulatedIma_green_initialSize);
		array_to_merge.push_back(mSimulatedIma_red_initialSize);
		cv::merge(array_to_merge, mSimulatedIma_bgr_final_initialSize);

		std::vector<cv::Mat> array_to_merge_distortionCorrection;
		array_to_merge_distortionCorrection.push_back(mSimulatedIma_blue_initialSize_distortionCorrected);
		array_to_merge_distortionCorrection.push_back(mSimulatedIma_green_initialSize_distortionCorrected);
		array_to_merge_distortionCorrection.push_back(mSimulatedIma_red_initialSize_distortionCorrected);
		cv::merge(array_to_merge_distortionCorrection, mSimulatedIma_bgr_final_initialSize_distortionCorrection);


	}

	else // distortion is not calculated
	{

		// resize the images
		cv::resize(mSimulatedIma_blue, mSimulatedIma_blue_initialSize, mInitialObj.size(), cv::INTER_LANCZOS4);
		cv::resize(mSimulatedIma_green, mSimulatedIma_green_initialSize, mInitialObj.size(), cv::INTER_LANCZOS4);
		cv::resize(mSimulatedIma_red, mSimulatedIma_red_initialSize, mInitialObj.size(), cv::INTER_LANCZOS4);


		std::vector<cv::Mat> array_to_merge;

		array_to_merge.push_back(mSimulatedIma_blue_initialSize);
		array_to_merge.push_back(mSimulatedIma_green_initialSize);
		array_to_merge.push_back(mSimulatedIma_red_initialSize);

		cv::merge(array_to_merge, mSimulatedIma_bgr_final_initialSize);
		
		
		real min{};
		real max{};

		cv::minMaxLoc(mSimulatedIma_bgr_final_initialSize, &min, &max);
		real ratio = 1.0 / max;

		mSimulatedIma_bgr_final_initialSize = mSimulatedIma_bgr_final_initialSize * ratio;
	}



}

cv::Mat ImageSimulationFunctions::getSimulatedImage_initialSize()
{
	return mSimulatedIma_bgr_final_initialSize;
}

cv::Mat ImageSimulationFunctions::getSimulatedImage_sizeForConvolution()
{
	std::vector<cv::Mat> array_to_merge;

	array_to_merge.push_back(mSimulatedIma_blue);
	array_to_merge.push_back(mSimulatedIma_green);
	array_to_merge.push_back(mSimulatedIma_red);

	cv::Mat simulatedIma_sizeForConv;
	cv::merge(array_to_merge, simulatedIma_sizeForConv);


	//real min{};
	//real max{};
	//
	//cv::minMaxLoc(simulatedIma_sizeForConv, &min, &max);
	//real ratio = 1.0 / max;
	//
	//simulatedIma_sizeForConv = simulatedIma_sizeForConv * ratio;

	return simulatedIma_sizeForConv;
}









void ImageSimulationFunctions::separateTheImageInNtimesMimages_saveThatFct_2()
{
	std::vector <cv::Mat> retrunObjectGrid;

	unsigned int rowObjAda = mAdaptedObj_blue.rows;
	unsigned int colObjAda = mAdaptedObj_blue.cols;

	unsigned int tempStartRow = 0;
	unsigned int separationRow = rowObjAda / mLoadParameterImaSim.getSampling_x();
	unsigned int tempEndRow = separationRow;

	unsigned int tempStartCol = 0;
	unsigned int separationCol = (colObjAda / mLoadParameterImaSim.getSampling_x());
	unsigned int tempEndCol = separationCol;


	unsigned int sizeObjGrid = mLoadParameterImaSim.getSampling_x() * mLoadParameterImaSim.getSampling_x();
	mObjectGrid_blue.resize(sizeObjGrid);
	mObjectGrid_green.resize(sizeObjGrid);
	mObjectGrid_red.resize(sizeObjGrid);
	unsigned int counter = 0;

	unsigned int Row_BiggerForConv = mLoadParameterImaSim.getColBiggerForConv();
	unsigned int Col_BiggerForConv = mLoadParameterImaSim.getColBiggerForConv();

	cv::Mat tempSeparatedObject_blue;
	cv::Mat tempSeparatedObject_green;
	cv::Mat tempSeparatedObject_red;


	tempEndRow = tempEndRow + Col_BiggerForConv;
	tempEndCol = tempEndCol + Row_BiggerForConv;

	for (unsigned int i = 0; i < mLoadParameterImaSim.getSampling_x(); ++i)
	{
		for (unsigned int j = 0; j < mLoadParameterImaSim.getSampling_x(); ++j)
		{

			if (j == mLoadParameterImaSim.getSampling_x() - 1 && i != mLoadParameterImaSim.getSampling_x() - 1)
			{
				tempEndCol = tempEndCol - Col_BiggerForConv;
			}

			else if (j == mLoadParameterImaSim.getSampling_x() - 1 && i == mLoadParameterImaSim.getSampling_x() - 1)
			{
				tempEndCol = tempEndCol - Col_BiggerForConv;
			}

			tempSeparatedObject_blue = mAdaptedObj_blue(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol));
			tempSeparatedObject_green = mAdaptedObj_green(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol));
			tempSeparatedObject_red = mAdaptedObj_red(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol));

			// just for debugging
			//Images::showImage("tempGridMat", tempSeparatedObject_blue);
			//Images::saveImage("../", "testSave", "png", tempSeparatedObject_blue);

			mObjectGrid_blue[counter] = tempSeparatedObject_blue;
			mObjectGrid_green[counter] = tempSeparatedObject_green;
			mObjectGrid_red[counter] = tempSeparatedObject_red;
			++counter;

			tempStartCol = tempEndCol - 2 * Col_BiggerForConv;
			tempEndCol = tempEndCol + separationCol;

		}

		tempStartCol = 0;
		tempEndCol = separationCol + Col_BiggerForConv;

		tempStartRow = tempEndRow - 2 * Row_BiggerForConv;
		tempEndRow = tempEndRow + separationRow;

		if (i == mLoadParameterImaSim.getSampling_x() - 2)
		{
			tempEndRow = tempEndRow - Row_BiggerForConv;
		}

	}



}

void ImageSimulationFunctions::putImaGridsTogether_saveThatFct_2()
{

	unsigned int sampling = mLoadParameterImaSim.getSampling_x();
	unsigned int rowObjAda = mAdaptedObj_blue.rows;
	unsigned int colObjAda = mAdaptedObj_blue.cols;

	unsigned int tempStartRow = 0;
	unsigned int separationRow = rowObjAda / sampling;
	unsigned int tempEndRow = separationRow;

	unsigned int tempStartRowInGrid = 0;
	unsigned int tempEndRowInGrid = separationRow;

	unsigned int tempStartCol = 0;
	unsigned int separationCol = colObjAda / sampling;
	unsigned int tempEndCol = separationCol;

	unsigned int tempStartColInGrid = 0;
	unsigned int tempEndColInGrid = separationCol;

	unsigned int sizeObjGrid = mLoadParameterImaSim.getSampling_x() * mLoadParameterImaSim.getSampling_x();

	mSimulatedIma_blue = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_blue[0].type());
	mSimulatedIma_green = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_green[0].type());
	mSimulatedIma_red = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_red[0].type());

	cv::Mat imagePart_blue;
	cv::Mat imagePart_green;
	cv::Mat imagePart_red;

	unsigned int counter = 0;
	// just for debugging
	//std::string counterStr;

	for (unsigned int i = 0; i < mLoadParameterImaSim.getSampling_x(); ++i)
	{
		for (unsigned int j = 0; j < mLoadParameterImaSim.getSampling_x(); ++j)
		{
			if (j == sampling)
			{
				tempEndColInGrid = mSimulatedImageGrid_blue[counter].size().width;
				tempEndCol = mSimulatedIma_blue.size().width;
			}

			imagePart_blue = mSimulatedImageGrid_blue[counter](cv::Range(tempStartRowInGrid, tempEndRowInGrid), cv::Range(tempStartColInGrid, tempEndColInGrid));
			imagePart_blue.copyTo(mSimulatedIma_blue(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol)));
			// just for debugging
			//Images::showImage_inputReal("blue ima grid", imagePart_blue);
			//Images::showImage_inputReal("blue ima", mSimulatedIma_blue);
			//counterStr = std::to_string(counter);
			//Images::saveImage("..", "partBlue" + counterStr, "png", imagePart_blue);

			imagePart_green = mSimulatedImageGrid_green[counter](cv::Range(tempStartRowInGrid, tempEndRowInGrid), cv::Range(tempStartColInGrid, tempEndColInGrid));
			imagePart_green.copyTo(mSimulatedIma_green(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol)));

			imagePart_red = mSimulatedImageGrid_red[counter](cv::Range(tempStartRowInGrid, tempEndRowInGrid), cv::Range(tempStartColInGrid, tempEndColInGrid));
			imagePart_red.copyTo(mSimulatedIma_red(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol)));

			tempStartCol = tempEndCol;
			tempEndCol = tempEndCol + separationCol;

			tempStartColInGrid = mLoadParameterImaSim.getColBiggerForConv();
			tempEndColInGrid = separationCol + mLoadParameterImaSim.getColBiggerForConv();

			++counter;

		}

		tempStartColInGrid = 0;
		tempEndColInGrid = separationCol;

		tempStartCol = 0;
		tempEndCol = separationCol;

		tempStartRow = tempEndRow;
		tempEndRow = tempEndRow + separationRow;

		tempStartRowInGrid = mLoadParameterImaSim.getRowBiggerForConv();;
		tempEndRowInGrid = separationRow + mLoadParameterImaSim.getRowBiggerForConv();

		if (i == sampling - 2)
		{
			tempEndRowInGrid = mSimulatedImageGrid_blue[counter].size().height;
			tempEndRow = mSimulatedIma_blue.size().height;
		}

	}


}

void ImageSimulationFunctions::separateTheImageInNtimesMimages()
{
	mLoadParameterImaSim.setRowBiggerForConV(mPSF_vec_blue_sampledUp_vertical[0].size().height / 2);
	mLoadParameterImaSim.setColBiggerForConv(mPSF_vec_blue_sampledUp_vertical[0].size().width / 2);

	std::vector <cv::Mat> retrunObjectGrid;
	unsigned int sampling_x = mLoadParameterImaSim.getSampling_x();
	unsigned int sampling_y = mLoadParameterImaSim.getSampling_y();

	unsigned int rowObjAda = mAdaptedObj_blue.rows;
	unsigned int colObjAda = mAdaptedObj_blue.cols;

	int tempStartRow = 0;
	unsigned int separationRow = rowObjAda / (sampling_y - 1);

	int tempStartCol = 0;
	unsigned int separationCol = colObjAda / (sampling_x - 1);


	if (mLoadParameterImaSim.getRowBiggerForConv() > separationRow / 2)
	{
		mLoadParameterImaSim.setRowBiggerForConV(separationRow / 4);
	}

	if (mLoadParameterImaSim.getColBiggerForConv() > separationCol / 2)
	{
		mLoadParameterImaSim.setColBiggerForConv(separationCol / 4);
	}

	unsigned int sizeObjGrid = (sampling_x * sampling_y);

	// resize
	mObjectGrid_blue.resize(sizeObjGrid);
	mObjectGrid_green.resize(sizeObjGrid);
	mObjectGrid_red.resize(sizeObjGrid);
	//mMaxBlue_vec.resize(sizeObjGrid);
	//mMinBlue_vec.resize(sizeObjGrid);
	//mMaxGreen_vec.resize(sizeObjGrid);
	//mMinGreen_vec.resize(sizeObjGrid);
	//mMaxRed_vec.resize(sizeObjGrid);
	//mMinRed_vec.resize(sizeObjGrid);
   
	unsigned int counter = 0;
	bool first = true;

	cv::Mat tempSeparatedObject_blue;
	cv::Mat tempSeparatedObject_green;
	cv::Mat tempSeparatedObject_red;

	real tempMin{};
	real tempMax{};

	unsigned int tempEndRow = separationRow / 2 + mLoadParameterImaSim.getRowBiggerForConv();
	unsigned int tempEndCol = separationCol / 2 + mLoadParameterImaSim.getColBiggerForConv();

	unsigned int halfSepRow = separationRow / 2;
	unsigned int halfSepCol = separationCol / 2;

	unsigned int heightAdaptedObj = mAdaptedObj_blue.size().height;
	unsigned int widthAdaptedObj = mAdaptedObj_blue.size().width;

	for (unsigned int i = 0; i < mLoadParameterImaSim.getSampling_y(); ++i)
	{
		for (unsigned int j = 0; j < mLoadParameterImaSim.getSampling_x(); ++j)
		{
			if (j == sampling_x - 1 || tempEndCol > widthAdaptedObj)
			{
				tempEndCol = colObjAda;
			}


			// blue
			tempSeparatedObject_blue = mAdaptedObj_blue(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol));
			//std::cout << "temp start row: " << tempStartRow << std::endl;
			//std::cout << "temp end row: " << tempEndRow << std::endl;
			//std::cout << "temp start col: " << tempStartCol << std::endl;
			//std::cout << "temp end col: " << tempEndCol << std::endl;
			//cv::minMaxLoc(tempSeparatedObject_blue, &tempMin, &tempMax);
			//mMinBlue_vec[counter] = tempMin;
			//mMaxBlue_vec[counter] = tempMax;

			// green
			tempSeparatedObject_green = mAdaptedObj_green(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol));
			//cv::minMaxLoc(tempSeparatedObject_green, &tempMin, &tempMax);
			//mMinGreen_vec[counter] = tempMin;
			//mMaxGreen_vec[counter] = tempMax;
			
			// red
			tempSeparatedObject_red = mAdaptedObj_red(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol));
			//cv::minMaxLoc(tempSeparatedObject_red, &tempMin, &tempMax);
			//mMinRed_vec[counter] = tempMin;
			//mMaxRed_vec[counter] = tempMax;

			// just for debugging
			//Images::showImage("tempGridMat", tempSeparatedObject_blue);
			//Images::saveImage("../", "testSave", "png", tempSeparatedObject_blue);

			mObjectGrid_blue[counter] = tempSeparatedObject_blue;
			mObjectGrid_green[counter] = tempSeparatedObject_green;
			mObjectGrid_red[counter] = tempSeparatedObject_red;
			++counter;

			tempStartCol = tempEndCol - 2 * mLoadParameterImaSim.getColBiggerForConv();
			tempEndCol = tempEndCol + separationCol;

			if (tempStartCol < 0)
			{
				tempStartCol = 0;
			}

		}

		tempStartCol = 0;
		tempEndCol = separationCol / 2 + mLoadParameterImaSim.getColBiggerForConv();

		tempStartRow = tempEndRow - 2 * mLoadParameterImaSim.getRowBiggerForConv();
		tempEndRow = tempEndRow + separationRow;

		if (i == sampling_x - 2 || tempEndRow > rowObjAda)
		{
			tempEndRow = rowObjAda;
		}

		if (tempStartRow < 0)
		{
			tempStartRow = 0;
		}
	}


}

void ImageSimulationFunctions::separateTheImageInNtimesMimages_saveDoNotUseThat()
{
	std::vector <cv::Mat> retrunObjectGrid;

	unsigned int rowObjAda = mAdaptedObj_blue.rows;
	unsigned int colObjAda = mAdaptedObj_blue.cols;

	unsigned int tempStartRow = 0;
	unsigned int separationRow = rowObjAda / (mLoadParameterImaSim.getSampling_x() + 1);

	unsigned int tempStartCol = 0;
	unsigned int separationCol = (colObjAda / (mLoadParameterImaSim.getSampling_x() + 1));



	unsigned int sizeObjGrid = (mLoadParameterImaSim.getSampling_x() +1)* (mLoadParameterImaSim.getSampling_x()+1);
	mObjectGrid_blue.resize(sizeObjGrid);
	mObjectGrid_green.resize(sizeObjGrid);
	mObjectGrid_red.resize(sizeObjGrid);
	unsigned int counter = 0;


	cv::Mat tempSeparatedObject_blue;
	cv::Mat tempSeparatedObject_green;
	cv::Mat tempSeparatedObject_red;

	
	unsigned int tempEndRow = separationRow + mLoadParameterImaSim.getColBiggerForConv();
	unsigned int tempEndCol = separationCol + mLoadParameterImaSim.getRowBiggerForConv();

	for (unsigned int i = 0; i < mLoadParameterImaSim.getSampling_x() + 1; ++i)
	{
		tempEndRow = tempEndRow + mLoadParameterImaSim.getColBiggerForConv();
		tempEndCol = tempEndCol + mLoadParameterImaSim.getRowBiggerForConv();

		for (unsigned int j = 0; j < mLoadParameterImaSim.getSampling_x() + 1; ++j)
		{
			if (j == mLoadParameterImaSim.getSampling_x() + 1 - 1 && i != mLoadParameterImaSim.getSampling_x())
			{
				tempEndCol = tempEndCol - mLoadParameterImaSim.getColBiggerForConv();
			}

			else if (j == mLoadParameterImaSim.getSampling_x() && i == mLoadParameterImaSim.getSampling_x())
			{
				tempEndCol = tempEndCol - mLoadParameterImaSim.getColBiggerForConv();
			}

			tempSeparatedObject_blue = mAdaptedObj_blue(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol));
			tempSeparatedObject_green = mAdaptedObj_green(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol));
			tempSeparatedObject_red = mAdaptedObj_red(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol));

			// just for debugging
			//Images::showImage("tempGridMat", tempSeparatedObject_blue);
			//Images::saveImage("../", "testSave", "png", tempSeparatedObject_blue);

			mObjectGrid_blue[counter] = tempSeparatedObject_blue;
			mObjectGrid_green[counter] = tempSeparatedObject_green;
			mObjectGrid_red[counter] = tempSeparatedObject_red;
			++counter;

			tempStartCol = tempEndCol - 2 * mLoadParameterImaSim.getColBiggerForConv();
			tempEndCol = tempEndCol + separationCol;

		}

		tempStartCol = 0;
		tempEndCol = separationCol + mLoadParameterImaSim.getColBiggerForConv();

		tempStartRow = tempEndRow - 2 * mLoadParameterImaSim.getRowBiggerForConv();
		tempEndRow = tempEndRow + separationRow;

		if (i == mLoadParameterImaSim.getSampling_x() - 1)
		{
			tempEndRow = tempEndRow - mLoadParameterImaSim.getRowBiggerForConv();
		}

	}


}

void ImageSimulationFunctions::putImaGridsTogether()
{
	unsigned int sampling_x = mLoadParameterImaSim.getSampling_x();
	unsigned int sampling_y = mLoadParameterImaSim.getSampling_y();
	unsigned int rowObjAda = mAdaptedObj_blue.rows;
	unsigned int colObjAda = mAdaptedObj_blue.cols;

	unsigned int tempStartRow = 0;
	unsigned int separationRow = rowObjAda / (sampling_y - 1);
	unsigned int tempEndRow = separationRow / 2;

	unsigned int tempStartRowInGrid = 0;
	unsigned int tempEndRowInGrid = separationRow / 2;

	unsigned int tempStartCol = 0;
	unsigned int separationCol = colObjAda / (sampling_x - 1);
	unsigned int tempEndCol = separationCol / 2;

	unsigned int tempStartColInGrid = 0;
	unsigned int tempEndColInGrid = separationCol / 2;

	unsigned int sizeObjGrid = mLoadParameterImaSim.getSampling_y()  * mLoadParameterImaSim.getSampling_x() ;

	mSimulatedIma_blue = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_blue[0].type());
	mSimulatedIma_green = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_green[0].type());
	mSimulatedIma_red = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_red[0].type());

	cv::Mat imagePart_blue;
	cv::Mat imagePart_green;
	cv::Mat imagePart_red;

	unsigned int counter = 0;
	// just for debugging
	//std::string counterStr;


	int deltaColFinalImage{};
	int deltaRowFinalImage{};
	int deltaColInGrind{};
	int deltaRowInGrind{};


	bool checkerResize = false;

	for (unsigned int i = 0; i < mLoadParameterImaSim.getSampling_y(); ++i)
	{
		for (unsigned int j = 0; j < mLoadParameterImaSim.getSampling_x(); ++j)
		{
			if (j == sampling_x - 1)
			{
				//tempEndColInGrid = mSimulatedImageGrid_blue[counter].size().width;
				tempEndCol = mSimulatedIma_blue.size().width;

				
				tempEndColInGrid = mSimulatedImageGrid_blue[counter].size().width;


			}

			deltaRowFinalImage = tempEndRow - tempStartRow;
			deltaColFinalImage = tempEndCol - tempStartCol;

			deltaRowInGrind = tempEndRowInGrid - tempStartRowInGrid;
			deltaColInGrind = tempEndColInGrid - tempStartColInGrid;

			// *** blue
			imagePart_blue = mSimulatedImageGrid_blue[counter](cv::Range(tempStartRowInGrid, tempEndRowInGrid), cv::Range(tempStartColInGrid, tempEndColInGrid));
			
			if (std::abs(deltaColFinalImage - deltaColInGrind) > 0.1 || std::abs(deltaRowFinalImage - deltaRowInGrind) > 0.1)
			{
				cv::resize(imagePart_blue, imagePart_blue, cv::Size(deltaColFinalImage, deltaRowFinalImage), cv::INTER_LANCZOS4);
				checkerResize = true;
			}
			
			
			//tempMin = mMinBlue_vec[counter];
			//tempMax = mMaxBlue_vec[counter];
			//cv::normalize(imagePart_blue, imagePart_blue, tempMin, tempMax, cv::NORM_MINMAX);
			imagePart_blue.copyTo(mSimulatedIma_blue(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol)));
			// just for debugging
			//Images::showImage_inputReal("blue ima grid", imagePart_blue);
			//Images::showImage_inputReal("blue ima", mSimulatedIma_blue);
			//counterStr = std::to_string(counter);
			//Images::saveImage("..", "partBlue" + counterStr, "png", imagePart_blue);

			// *** green
	

			imagePart_green = mSimulatedImageGrid_green[counter](cv::Range(tempStartRowInGrid, tempEndRowInGrid), cv::Range(tempStartColInGrid, tempEndColInGrid));
			
			if (checkerResize)
			{
				cv::resize(imagePart_green, imagePart_green, cv::Size(deltaColFinalImage, deltaRowFinalImage), cv::INTER_LANCZOS4);
			}

			
			//tempMin = mMinGreen_vec[counter];
			//tempMax = mMaxGreen_vec[counter];
			//cv::normalize(imagePart_green, imagePart_green, tempMin, tempMax, cv::NORM_MINMAX);
			imagePart_green.copyTo(mSimulatedIma_green(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol)));

			// *** red
			imagePart_red = mSimulatedImageGrid_red[counter](cv::Range(tempStartRowInGrid, tempEndRowInGrid), cv::Range(tempStartColInGrid, tempEndColInGrid));
			//tempMin = mMinRed_vec[counter];
			//tempMax = mMaxRed_vec[counter];
			//cv::normalize(imagePart_red, imagePart_red, tempMin, tempMax, cv::NORM_MINMAX);

				if (checkerResize)
			{
				cv::resize(imagePart_red, imagePart_red, cv::Size(deltaColFinalImage, deltaRowFinalImage), cv::INTER_LANCZOS4);
			}

			imagePart_red.copyTo(mSimulatedIma_red(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol)));

			tempStartCol = tempEndCol;
			tempEndCol = tempEndCol + separationCol;

			tempStartColInGrid = mLoadParameterImaSim.getColBiggerForConv();
			tempEndColInGrid = separationCol + mLoadParameterImaSim.getColBiggerForConv();

			++counter;
			checkerResize = false;
		}

		tempStartColInGrid = 0;
		tempEndColInGrid = separationCol / 2;

		tempStartCol = 0;
		tempEndCol = separationCol / 2;

		tempStartRow = tempEndRow;
		tempEndRow = tempEndRow + separationRow;

		tempStartRowInGrid = mLoadParameterImaSim.getRowBiggerForConv();;
		tempEndRowInGrid = separationRow  + mLoadParameterImaSim.getRowBiggerForConv();

		if (i == sampling_y - 2)
		{
			// tempEndRowInGrid = mSimulatedImageGrid_blue[counter].size().height;
			tempEndRow = mSimulatedIma_blue.size().height;
			tempEndRowInGrid = mSimulatedImageGrid_blue[counter].size().height;
		}


	}

}




void ImageSimulationFunctions::putImaGridsTogether_save_doNotUseThatFunction()
{
	
	unsigned int rowObjAda = mAdaptedObj_blue.rows;
	unsigned int colObjAda = mAdaptedObj_blue.cols;

	unsigned int tempStartRow = 0;
	unsigned int separationRow = rowObjAda / (mLoadParameterImaSim.getSampling_x() + 1);
	unsigned int tempEndRow = separationRow;

	unsigned int tempStartRowInGrid = 0;
	unsigned int tempEndRowInGrid = separationRow;

	unsigned int tempStartCol = 0;
	unsigned int separationCol = (colObjAda / (mLoadParameterImaSim.getSampling_x() + 1));
	unsigned int tempEndCol = separationCol;

	unsigned int tempStartColInGrid = 0;
	unsigned int tempEndColInGrid = separationCol;

	unsigned int sizeObjGrid = (mLoadParameterImaSim.getSampling_x() + 1) * (mLoadParameterImaSim.getSampling_x() + 1);

	mSimulatedIma_blue = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_blue[0].type());
	mSimulatedIma_green = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_green[0].type());
	mSimulatedIma_red = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_red[0].type());

	cv::Mat imagePart_blue;
	cv::Mat imagePart_green;
	cv::Mat imagePart_red;

	unsigned int counter = 0;
	// just for debugging
	//std::string counterStr;

	for (unsigned int i = 0; i < mLoadParameterImaSim.getSampling_x() + 1; ++i)
	{
		for (unsigned int j = 0; j < mLoadParameterImaSim.getSampling_x() + 1; ++j)
		{

			imagePart_blue = mSimulatedImageGrid_blue[counter](cv::Range(tempStartRowInGrid, tempEndRowInGrid), cv::Range(tempStartColInGrid, tempEndColInGrid));
			imagePart_blue.copyTo(mSimulatedIma_blue(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol)));
			// just for debugging
			//Images::showImage("blue ima grid", mSimulatedImageGrid_blue[i]);
			//Images::showImage("blue ima", mSimulatedIma_blue);
			//counterStr = std::to_string(counter);
			//Images::saveImage("..", "partBlue" + counterStr, "png", imagePart_blue);

			imagePart_green = mSimulatedImageGrid_green[counter](cv::Range(tempStartRowInGrid, tempEndRowInGrid), cv::Range(tempStartColInGrid, tempEndColInGrid));
			imagePart_green.copyTo(mSimulatedIma_green(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol)));

			imagePart_red = mSimulatedImageGrid_red[counter](cv::Range(tempStartRowInGrid, tempEndRowInGrid), cv::Range(tempStartColInGrid, tempEndColInGrid));
			imagePart_red.copyTo(mSimulatedIma_red(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol)));

			tempStartCol = tempEndCol;
			tempEndCol = tempEndCol + separationCol;

			tempStartColInGrid = mLoadParameterImaSim.getColBiggerForConv();
			tempEndColInGrid = separationCol + mLoadParameterImaSim.getColBiggerForConv();

			++counter;

		}

		tempStartColInGrid = 0;
		tempEndColInGrid = separationCol;

		tempStartCol = 0;
		tempEndCol = separationCol;

		tempStartRow = tempEndRow;
		tempEndRow = tempEndRow + separationRow;

		tempStartRowInGrid = mLoadParameterImaSim.getRowBiggerForConv();;
		tempEndRowInGrid = separationRow + mLoadParameterImaSim.getRowBiggerForConv();

	}

}

void ImageSimulationFunctions::normSepImagesMinAndMax()
{
	//// blue
	//real minBlue;
	//real maxBlue;
	//cv::minMaxLoc(mAdaptedObj_blue, &minBlue, &maxBlue);
	//double ratioBlue = 255.0 / maxBlue;
	//mSimulatedIma_blue = mSimulatedIma_blue * ratioBlue;
	//
	//// Green
	//real minGreen;
	//real maxGreen;
	//cv::minMaxLoc(mAdaptedObj_green, &minGreen, &maxGreen);
	//double ratioGreen = 255.0 / maxGreen;
	//mSimulatedIma_green = mSimulatedIma_green * ratioGreen;
	//
	//// Red
	//real minRed;
	//real maxRed;
	//cv::minMaxLoc(mAdaptedObj_red, &minRed, &maxRed);
	//double ratioRed = 255.0 / maxRed;
	//mSimulatedIma_red = mSimulatedIma_red * ratioRed;


	// norm blue
	real minBlue{};
	real maxBlue{};
	cv::minMaxLoc(mAdaptedObj_blue, &minBlue, &maxBlue);
	cv::normalize(mSimulatedIma_blue, mSimulatedIma_blue, 0.0, 255.0, cv::NORM_MINMAX, CV_64F);
	
	//// just for debugging
	//std::string typeBlueIma = Images::getTypeImageC_VMat(mSimulatedIma_blue);
	//std::cout << "type blue ima: " << typeBlueIma << std::endl;
	
	// norm green
	real minGreen{};
	real maxGreen{};
	cv::minMaxLoc(mAdaptedObj_green, &minGreen, &maxGreen);
	cv::normalize(mSimulatedIma_green, mSimulatedIma_green, 0.0, 255.0, cv::NORM_MINMAX, CV_64F);
	
	// norm red
	real minRed{};
	real maxRed{};
	cv::minMaxLoc(mAdaptedObj_red, &minRed, &maxRed);
	cv::normalize(mSimulatedIma_red, mSimulatedIma_red, 0.0, 255.0, cv::NORM_MINMAX, CV_64F);

}

// calc width object according to height
void ImageSimulationFunctions::calcWidthAccordingToHeight()
{
	real semiHeight = mLoadParameterImaSim.getSemiHeightObj();
	real semiPixelNumHeight = mInitialObj.size().height / 2.0;
	real semiPixelNumWidth = mInitialObj.size().width / 2.0;

	real sizePerPixHeight = semiHeight / semiPixelNumHeight;
	real semiWidth = sizePerPixHeight * semiPixelNumWidth;

	mLoadParameterImaSim.setSemiWeidthObj(semiWidth);
}

// calc points to sampling image 
void ImageSimulationFunctions::calcPointsToSampleObject()
{
	VectorStructR3 startPointRay{};
	startPointRay.setZ(mLoadParameterImaSim.getPosition_Z_Object());

	// sampling must be an odd number
	if (oftenUse::checkForEvenNumber(mLoadParameterImaSim.getSampling_x()))
	{
		mLoadParameterImaSim.setSampling_x(mLoadParameterImaSim.getSampling_x() + 1);
	}
	if (oftenUse::checkForEvenNumber(mLoadParameterImaSim.getSampling_y()))
	{
		mLoadParameterImaSim.setSampling_x(mLoadParameterImaSim.getSampling_y() + 1);
	}

	real tempSemiWeidth = mLoadParameterImaSim.getSemiWidthObj();
	real tempSemiHeight = mLoadParameterImaSim.getSemiHeightObj();
	unsigned int counter = 0;

	unsigned int numPoints_x = ((real)mLoadParameterImaSim.getSampling_x() / 2.0) + 0.5;
	unsigned int numPoints_y = ((real)mLoadParameterImaSim.getSampling_y() / 2.0) + 0.5;
	unsigned int x = 0;
	real thicknessWeidgth = mLoadParameterImaSim.getSemiWidthObj() / (numPoints_x - 1);
	real thicknessHeight = mLoadParameterImaSim.getSemiHeightObj() / (numPoints_y - 1);

	unsigned int size = numPoints_x * numPoints_y;
	mObjectPointsSampling.resize(size);
	for (unsigned int y = 0; y < numPoints_y; ++y)
	{
		for ( x ; x < numPoints_x ; ++x)
		{
			startPointRay.setX(tempSemiWeidth);
			startPointRay.setY(tempSemiHeight);
			mObjectPointsSampling[counter] = startPointRay;

			tempSemiWeidth = tempSemiWeidth - thicknessWeidgth;
			++counter;

		}

		x = 0;
		tempSemiWeidth = mLoadParameterImaSim.getSemiWidthObj();
		tempSemiHeight = tempSemiHeight - thicknessHeight;
		
	}
}

std::vector<VectorStructR3> ImageSimulationFunctions::getPointsToSampleObj()
{
	return mObjectPointsSampling;
}

// the the wavelength for image simulation
void ImageSimulationFunctions::setWavelengthBlue(real waveBlue)
{
	mLoadParameterImaSim.setWavelengthBlue(waveBlue);
}
void ImageSimulationFunctions::setWavelengthGreen(real waveGreen)
{
	mLoadParameterImaSim.setWavelengthGreen(waveGreen);
}
void ImageSimulationFunctions::setWavelengthRed(real waveRed)
{
	mLoadParameterImaSim.setWavelengthRed(waveRed);
}
// ray density
real ImageSimulationFunctions::getRayDensity()
{
	return mLoadParameterImaSim.getRayDensity();
}
void ImageSimulationFunctions::setRayDensity(unsigned int rayDensity)
{
	mLoadParameterImaSim.setRayDensity(rayDensity);
}

// light
Light_LLT ImageSimulationFunctions::getLight()
{
	return mLoadParameterImaSim.getLight();
}
void ImageSimulationFunctions::setLight(Light_LLT light)
{
	mLoadParameterImaSim.setLight(light);
}

// size matrix to save OPD
unsigned int ImageSimulationFunctions::getSizeMatrixToSaveOPD()
{
	return mLoadParameterImaSim.getSizeMatrixToSaveOPD();
}
void ImageSimulationFunctions::setSizeMatrixToSaveOPD(unsigned int sizeMatrixOPD)
{
	mLoadParameterImaSim.setSizeMatrixToSaveOPD(sizeMatrixOPD);
}
// inf of obj
void ImageSimulationFunctions::setInfOrObj(objectPoint_inf_obj inf_obj)
{
	mLoadParameterImaSim.setInfOrObj(inf_obj);
}
objectPoint_inf_obj ImageSimulationFunctions::getInfOrObj()
{
	return mLoadParameterImaSim.getInfOrObj();
}


void ImageSimulationFunctions::setDefaulParameter(loadParaImaSim defaulParaImaSim)
{
	mLoadParameterImaSim = defaulParaImaSim;
}

// sampling
void ImageSimulationFunctions::setSampling(unsigned int sampling)
{
	mLoadParameterImaSim.setSampling_x(sampling);
}
unsigned ImageSimulationFunctions::getSampling()
{
	return mLoadParameterImaSim.getSampling_x();
}

// semi height object
void ImageSimulationFunctions::setSemiHeightObj(real semiHeightObject)
{
	mLoadParameterImaSim.setSemiHeightObj(semiHeightObject);
}
real ImageSimulationFunctions::getSemiHeightObj()
{
	return mLoadParameterImaSim.getSemiHeightObj();
}

// semi weidth object
void ImageSimulationFunctions::setSemiWeidthObj(real semiWeigthObject)
{
	mLoadParameterImaSim.setSemiWeidthObj(semiWeigthObject);
}
real ImageSimulationFunctions::getSemiWeidthOj()
{
	return mLoadParameterImaSim.getSemiWidthObj();
}

// position Z object
void ImageSimulationFunctions::setPosition_Z_Object(real pos_Z_obj)
{
	mLoadParameterImaSim.setPosition_Z_Object(pos_Z_obj);
}
real ImageSimulationFunctions::getPosition_Z_Object()
{
	return mLoadParameterImaSim.getPosition_Z_Object();
}

// up sample PSF
void ImageSimulationFunctions::setUpSamplePSF(bool upSamplePSF)
{
	mLoadParameterImaSim.setUpSamplePSF(upSamplePSF);
}
bool ImageSimulationFunctions::getUpSamplePSF()
{
	return mLoadParameterImaSim.getUpSamplePSF();
}

// resize OPD linear
void ImageSimulationFunctions::setResizeOPD_linear(bool resizeOPD_linear)
{
	mLoadParameterImaSim.setResizeOPD_linear(resizeOPD_linear);
}
bool ImageSimulationFunctions::getResizeOPD_linear()
{
	return mLoadParameterImaSim.getResizeOPD_linear();
}

// padding factor PSF
void ImageSimulationFunctions::setPaddingFactorPSF(unsigned int paddingFactor)
{
	mLoadParameterImaSim.setPaddingFactorPSF(paddingFactor);
}
unsigned int ImageSimulationFunctions::getPaddingFactorPSF()
{
	return mLoadParameterImaSim.getPaddingFactorPSF();
}

void ImageSimulationFunctions::buildAllOptSysLLT_BGR()
{
	buildOpticalSystemBlue();
	buildOpticalSystemGreen();
	buildOpticalSystemRed();
}

// build optical systems according to the wavelength
void ImageSimulationFunctions::buildOpticalSystemBlue()
{
	mOptSysEle.setRefractiveIndexAccordingToWavelength(mLoadParameterImaSim.getWavelengthBlue());
	mOptSysEle.convertSurfacesToLLT();

	mOptSysLLT_blue = mOptSysEle.getOptSys_LLT_buildSystem();
	mOptSysLLT_blue = mOptSysLLT_blue.clone();
}
void ImageSimulationFunctions::buildOpticalSystemGreen()
{
	mOptSysEle.setRefractiveIndexAccordingToWavelength(mLoadParameterImaSim.getWavelengthGreen());
	mOptSysEle.convertSurfacesToLLT();

	mOptSysLLT_green = mOptSysEle.getOptSys_LLT_buildSystem();
	mOptSysLLT_green = mOptSysLLT_green.clone();
}
void ImageSimulationFunctions::buildOpticalSystemRed()
{
	mOptSysEle.setRefractiveIndexAccordingToWavelength(mLoadParameterImaSim.getWavelengthRed());
	mOptSysEle.convertSurfacesToLLT();

	mOptSysLLT_red = mOptSysEle.getOptSys_LLT_buildSystem();
	mOptSysLLT_red = mOptSysLLT_red.clone();
}




// calculate OPDs
void ImageSimulationFunctions::calcALL_OPDs()
{
	// calc points in aperture stop
	// fill aperture stop with points
	FillApertureStop fillAS{};
	infosAS infAS = mOptSysLLT_blue.getInforAS();
	mPointsInAS = fillAS.fillAS_withPoints(mLoadParameterImaSim.getRayDensity(), infAS.getPointAS(), infAS.getDirAS(), infAS.getSemiHeightAS());
	// ***

	calcOPD_blue();
	calcOPD_green();
	calcOPD_red();
}
void ImageSimulationFunctions::calcOPD_blue()
{
	VectorStructR3 tempStartPointRays{};
	unsigned int size = mObjectPointsSampling.size();


	RayAiming rayAiming{};
	std::vector<LightRayStruct> tempAimedLightRays{};
	

	Light_LLT light = mLoadParameterImaSim.getLight();
	light.setWavelength(mLoadParameterImaSim.getWavelengthBlue());
	OPD OPD_blue;
	OPD_blue.setOpticalSystemLLT(mOptSysLLT_blue);
	OPD_blue.setInfOrObj(mLoadParameterImaSim.getInfOrObj());
	OPD_blue.setSizeMatrixToSave(mLoadParameterImaSim.getSizeMatrixToSaveOPD());
	mOPD_vec_blue.resize(size);

	for (unsigned int i = 0; i < size; ++i)
	{
		tempStartPointRays = mObjectPointsSampling[i];
		// ray aiming
		
		tempAimedLightRays = rayAiming.rayAimingMany_obj_complete(mOptSysLLT_blue, mPointsInAS, tempStartPointRays, light);
		OPD_blue.setAimedLightRays(tempAimedLightRays);
		OPD_blue.calcGlobalOPD_new();
		OPD_blue.bilinearInterpolToFillHolesInOPDmatrix();

		// save the upsampled OPD
		mOPD_vec_blue[i] = OPD_blue.getUpsampledGlobalOPD_deepCopy();

		//// just for debugging
		//real tempVal = mOPD_vec_blue[i].at<real>(15, 15);
		//std::cout << tempVal << std::endl;
		//
		//// just for debugging
		//if (i > 0)
		//{
		//	real tempVal2 = mOPD_vec_blue[i - 1].at<real>(15, 15);
		//	std::cout << tempVal2 << std::endl;
		//}

	}

	// just for debugging
	//std::string location = "../tests/testImageSimulation/s4";
	//exportAllCalcOPDs_blue(location);
}
void ImageSimulationFunctions::calcOPD_green()
{
	VectorStructR3 tempStartPointRays{};
	unsigned int size = mObjectPointsSampling.size();

	RayAiming rayAiming{};
	std::vector<LightRayStruct> tempAimedLightRays{};

	Light_LLT light = mLoadParameterImaSim.getLight();
	light.setWavelength(mLoadParameterImaSim.getWavelengthGreen());
	OPD OPD_green;
	OPD_green.setOpticalSystemLLT(mOptSysLLT_green);
	OPD_green.setInfOrObj(mLoadParameterImaSim.getInfOrObj());
	OPD_green.setSizeMatrixToSave(mLoadParameterImaSim.getSizeMatrixToSaveOPD());
	mOPD_vec_green.resize(size);

	for (unsigned int i = 0; i < size; ++i)
	{
		tempStartPointRays = mObjectPointsSampling[i];
		// ray aiming

		tempAimedLightRays = rayAiming.rayAimingMany_obj_complete(mOptSysLLT_green, mPointsInAS, tempStartPointRays, light);
		OPD_green.setAimedLightRays(tempAimedLightRays);
		OPD_green.calcGlobalOPD_new();
		OPD_green.bilinearInterpolToFillHolesInOPDmatrix();

		// save the upsampled OPD
		mOPD_vec_green[i] = OPD_green.getUpsampledGlobalOPD_deepCopy();

	}

	// just for debugging
	//std::string location = "../tests/testImageSimulation/s4";
	//exportAllCalcOPDs_green(location);

	//// just for debugging
	//Images::showImage_inputReal("OPD green", mOPD_vec_green[0]);
}
void ImageSimulationFunctions::calcOPD_red()
{
	VectorStructR3 tempStartPointRays{};
	unsigned int size = mObjectPointsSampling.size();

	RayAiming rayAiming{};
	std::vector<LightRayStruct> tempAimedLightRays{};

	Light_LLT light = mLoadParameterImaSim.getLight();
	light.setWavelength(mLoadParameterImaSim.getWavelengthRed());
	OPD OPD_red;
	OPD_red.setOpticalSystemLLT(mOptSysLLT_red);
	OPD_red.setInfOrObj(mLoadParameterImaSim.getInfOrObj());
	OPD_red.setSizeMatrixToSave(mLoadParameterImaSim.getSizeMatrixToSaveOPD());
	mOPD_vec_red.resize(size);

	for (unsigned int i = 0; i < size; ++i)
	{
		tempStartPointRays = mObjectPointsSampling[i];
		// ray aiming

		tempAimedLightRays = rayAiming.rayAimingMany_obj_complete(mOptSysLLT_red, mPointsInAS, tempStartPointRays, light);
		OPD_red.setAimedLightRays(tempAimedLightRays);
		OPD_red.calcGlobalOPD_new();
		OPD_red.bilinearInterpolToFillHolesInOPDmatrix();

		// save the upsampled OPD
		mOPD_vec_red[i] = OPD_red.getUpsampledGlobalOPD_deepCopy();

	}

	// just for debugging
	//std::string location = "../tests/testImageSimulation/s4";
	//exportAllCalcOPDs_red(location);
}

// check for resize OPD linear
void ImageSimulationFunctions::checkForResizeOPD()
{
	if (mLoadParameterImaSim.getResizeOPD_linear())
	{
		// resize all OPDs linear 
		resizeAllOPDs_unsign_LANCZOS4();
	}
	else
	{
		mOPD_vec_blue_resized = mOPD_vec_blue;
		mOPD_vec_green_resized = mOPD_vec_green;
		mOPD_vec_red_resized = mOPD_vec_red;

	}
}
// check for up sampling psf
void ImageSimulationFunctions::checkForUpSamplingPSF()
{
	if (mLoadParameterImaSim.getUpSamplePSF())
	{
		// greate more PSFs between the calcualted PSFs
		upSample_PSFs_horizontal();
		// up sample PSF vertical
		upSample_PSFs_vertical();

	}
	else
	{
		mPSF_vec_blue_sampledUp_vertical = mPSF_vec_blue;
		mPSF_vec_green_sampledUp_vertical = mPSF_vec_green;
		mPSF_vec_red_sampledUp_vertical = mPSF_vec_red;
	}
}

// check Intensity distorted images
void ImageSimulationFunctions::checkIntensityDistortedImages()
{
	unsigned int height = mSimulatedIma_blue.size().height;
	unsigned int width = mSimulatedIma_blue.size().width;
	
	real maxVal = 1.0;

	// blue
	real tempMinBlue;
	real tempMaxBlue;
	cv::Point minLocBlue, maxLocBlue;
	bool checkerBlue = true;

	// green
	real tempMinGreen;
	real tempMaxGreen;
	cv::Point minLocGreen, maxLocGreen;
	bool checkerGreen = true;

	// red
	real tempMinRed;
	real tempMaxRed;
	cv::Point minLocRed, maxLocRed;
	bool checkerRed = true;

	// check blue
	while (checkerBlue)
	{
		cv::minMaxLoc(mSimulatedIma_blue , &tempMinBlue, &tempMaxBlue, &minLocBlue, &maxLocBlue);

		if (tempMaxBlue > maxVal)
		{
			// just for debugging
			std::cout << "max location blue: " << maxLocBlue << std::endl;
			
			mSimulatedIma_blue.at<real>(maxLocBlue.y, maxLocBlue.x) = maxVal;
		}

		else
		{
			checkerBlue = false;
		}

	}

	// check green
	while (checkerGreen)
	{
		cv::minMaxLoc(mSimulatedIma_green, &tempMinGreen, &tempMaxGreen, &minLocGreen, &maxLocGreen);

		if (tempMaxGreen > maxVal)
		{
			// just for debugging
			std::cout << "max location green: " << maxLocGreen << std::endl;

			mSimulatedIma_green.at<real>(maxLocGreen.y, maxLocGreen.x) = maxVal;
		}

		else
		{
			checkerGreen = false;
		}

	}

	// check red
	while (checkerRed)
	{
		cv::minMaxLoc(mSimulatedIma_red, &tempMinRed, &tempMaxRed, &minLocRed, &maxLocRed);

		if (tempMaxRed > maxVal)
		{
			// just for debugging
			std::cout << "max location red: " << maxLocRed << std::endl;

			mSimulatedIma_red.at<real>(maxLocRed.y, maxLocRed.x) = maxVal;
		}

		else
		{
			checkerRed = false;
		}

	}


}

// adapet size PSF for convolution
void ImageSimulationFunctions::adapetSizeObject_ForConv()
{
	// green
	CardinalPoints carPointsGreen(mOptSysLLT_green, mLoadParameterImaSim.getInfOrObj());
	mEXPD_green = carPointsGreen.getEXPD();
	mEXPP_green = carPointsGreen.getEXPP_lastSurface();
	mMagni_green = carPointsGreen.getMagnification();

	PSF psf;
	psf.resizeObjectToMachSizePixelPSF(mInitialObj, mResizedObjectForConvolution, mMagni_green, 2.0 * mLoadParameterImaSim.getSemiHeightObj(), mEXPP_green, mLoadParameterImaSim.getWavelengthGreen(), mEXPD_green, mLoadParameterImaSim.getPaddingFactorPSF());

	mSizeResizedObjForConv = mResizedObjectForConvolution.size();
	mSizeInitialObj = mInitialObj.size();
}

// calculate ray density according to OPD size
void ImageSimulationFunctions::calcRayDensityAccordingToOPDsize()
{	
	unsigned int sizeOPD = mLoadParameterImaSim.getSizeMatrixToSaveOPD();
	unsigned int rayDensity = sizeOPD / 2;
	mLoadParameterImaSim.setRayDensity(rayDensity);

}

// calcualte target pixel size
void ImageSimulationFunctions::calcTargetPixcelSize()
{
	real sizePixelObject_µm = ((mLoadParameterImaSim.getSemiHeightObj() * 2.0) / mAdaptedObj.size().height) * 1000;
	
	// just for debugging
	std::cout << "size pixel object: " << sizePixelObject_µm << std::endl;

	mTargetPixelSize_blue_µm = std::abs(mMagni_blue * sizePixelObject_µm);
	mTargetPixelSize_green_µm = std::abs(mMagni_green * sizePixelObject_µm);
	mTargetPixelSize_red_µm = std::abs(mMagni_red * sizePixelObject_µm);

}

void ImageSimulationFunctions::normImageToMaxVal()
{
	unsigned delta = 1;

	unsigned int height = mSimulatedIma_bgr_final_initialSize.size().height;
	unsigned int width = mSimulatedIma_bgr_final_initialSize.size().width;
	unsigned int startHeight = delta;
	unsigned int startWidth = delta;
	unsigned int endHeight = height - 2 * delta;
	unsigned int endWidth = width - 2 * delta;


	cv::Rect ROI(startWidth, startHeight, endWidth, endHeight);
	cv::Mat middleIma = mSimulatedIma_bgr_final_initialSize(ROI);

	real min{};
	real max{};

	cv::minMaxLoc(middleIma, &min, &max);
	real ratio = 1.0 / max;

	mSimulatedIma_bgr_final_initialSize = mSimulatedIma_bgr_final_initialSize * ratio;
}

// export all calculated OPDs 
void ImageSimulationFunctions::exportAllCalcOPDs_blue(std::string location)
{
	unsigned int sizeOPD_blue = mOPD_vec_blue.size();
	std::string name = "blue";
	std::string tempNamePlusNum{};

	cv::Mat tempExportMat;

	for (unsigned int i = 0; i < sizeOPD_blue; ++i)
	{
		tempNamePlusNum = name + std::to_string(i);
		tempExportMat = mOPD_vec_blue[i];
		// just for debugging
		//real tempVal = tempExportMat.at<real>(15, 15);
		//std::cout << tempVal << std::endl;

		inportExportData::exportCV_MatToExcel(mOPD_vec_blue[i], location, tempNamePlusNum);
	}
}
void ImageSimulationFunctions::exportAllCalcOPDs_green(std::string location)
{
	unsigned int sizeOPD_green = mOPD_vec_green.size();
	std::string name = "green";
	std::string tempNamePlusNum{};

	for (unsigned int i = 0; i < sizeOPD_green; ++i)
	{
		tempNamePlusNum = name + std::to_string(i);
		inportExportData::exportCV_MatToExcel(mOPD_vec_green[i], location, tempNamePlusNum);
	}
}
void ImageSimulationFunctions::exportAllCalcOPDs_red(std::string location)
{
	unsigned int sizeOPD_red = mOPD_vec_red.size();
	std::string name = "red";
	std::string tempNamePlusNum{};

	for (unsigned int i = 0; i < sizeOPD_red; ++i)
	{
		tempNamePlusNum = name + std::to_string(i);
		inportExportData::exportCV_MatToExcel(mOPD_vec_red[i], location, tempNamePlusNum);
	}
}

// row and col resize OPD
void ImageSimulationFunctions::setRowColResizeOPD(unsigned int rowAndCol)
{
	mLoadParameterImaSim.setRowColResizeOPD(rowAndCol);
}
unsigned int ImageSimulationFunctions::getRowAndColResizeOPD()
{
	return mLoadParameterImaSim.getRowAndColResizeOPD();
}

// scall up all OPDs
void ImageSimulationFunctions::resizeAllOPDs_unsign_LANCZOS4()
{
	unsigned int size = mOPD_vec_blue.size();
	unsigned int row = mLoadParameterImaSim.getRowAndColResizeOPD();
	unsigned int col = mLoadParameterImaSim.getRowAndColResizeOPD();

	mOPD_vec_blue_resized.resize(size);
	mOPD_vec_green_resized.resize(size);
	mOPD_vec_red_resized.resize(size);


	for (unsigned int i = 0; i < size; i++)
	{
		cv::resize(mOPD_vec_blue[i], mOPD_vec_blue_resized[i], cv::Size(col, row), cv::INTER_LANCZOS4);
		cv::resize(mOPD_vec_green[i], mOPD_vec_green_resized[i], cv::Size(col, row), cv::INTER_LANCZOS4);
		cv::resize(mOPD_vec_red[i], mOPD_vec_red_resized[i], cv::Size(col, row), cv::INTER_LANCZOS4);
	
	}
}

// calc all PSFs
void ImageSimulationFunctions::calcAllPSFs()
{

	calcAllPSF_blue();
	calcAllPSF_green();
	calcAllPSF_red();


}



void ImageSimulationFunctions::calcAllPSF_blue()
{
	PSF PSF_blue;
	PSF_blue.setPaddingFactor(mLoadParameterImaSim.getPaddingFactorPSF());

	unsigned int size = mOPD_vec_blue_resized.size();
	mPSF_vec_blue.resize(size);
	for (unsigned int i = 0; i < size; ++i)
	{
		mPSF_vec_blue[i] = PSF_blue.calcPSF_FFT_NEW(mOPD_vec_blue_resized[i]);

		// just for debugging
		// Images::showImage_inputReal_normTheImage ("PSF blue", mPSF_vec_blue[i]);

		// just for debugging
		// real sumPSFBlue = cv::sum(mPSF_vec_blue[i])[0];
		// std::cout << "sum psf blue: " << sumPSFBlue << std::endl;
	}
	
}

void ImageSimulationFunctions::calcAllPSF_green()
{
	PSF PSF_green;
	PSF_green.setPaddingFactor(mLoadParameterImaSim.getPaddingFactorPSF());

	unsigned int size = mOPD_vec_green_resized.size();
	mPSF_vec_green.resize(size);
	for (unsigned int i = 0; i < size; ++i)
	{
		mPSF_vec_green[i] = PSF_green.calcPSF_FFT_NEW(mOPD_vec_green_resized[i]);

		// just for debugging
		// Images::showImage_inputReal("PSF green", mPSF_vec_green[i]);

		// just for debugging
		// real sumPSFGreen = cv::sum(mPSF_vec_green[i])[0];
		// std::cout << "sum psf green: " << sumPSFGreen << std::endl;
	}
}
void ImageSimulationFunctions::calcAllPSF_red()
{
	PSF PSF_red;
	PSF_red.setPaddingFactor(mLoadParameterImaSim.getPaddingFactorPSF());

	unsigned int size = mOPD_vec_red_resized.size();
	mPSF_vec_red.resize(size);
	for (unsigned int i = 0; i < size; ++i)
	{
		mPSF_vec_red[i] = PSF_red.calcPSF_FFT_NEW(mOPD_vec_red_resized[i]);

		// just for debugging
		// Images::showImage_inputReal("PSF red", mPSF_vec_red[i]);

		// just for debugging
		// real sumPSFRed = cv::sum(mPSF_vec_red[i])[0];
		// std::cout << "sum psf red: " << sumPSFRed << std::endl;
	}
}

// normalieze all PSFs
void ImageSimulationFunctions::normalizeAllPSFs()
{
	unsigned int size = mPSF_vec_blue.size();

	for (unsigned int i = 0; i < size; ++i)
	{
		cv::normalize(mPSF_vec_blue[i], mPSF_vec_blue[i], 0.0, 10000.0, cv::NORM_MINMAX, CV_64F);
		cv::normalize(mPSF_vec_green[i], mPSF_vec_green[i], 0.0, 10000.0, cv::NORM_MINMAX, CV_64F);
		cv::normalize(mPSF_vec_red[i], mPSF_vec_red[i], 0.0, 10000.0, cv::NORM_MINMAX, CV_64F);
	}
}

// sample up PSF
void ImageSimulationFunctions::upSample_PSFs_horizontal()
{
	unsigned int size = mPSF_vec_blue.size();

	unsigned int samplingHalf_x = (real)mLoadParameterImaSim.getSampling_x() / 2.0 - 0.5;
	unsigned int samplingHalf_y = (real)mLoadParameterImaSim.getSampling_y() / 2.0 - 0.5;

	unsigned int newSize = (mLoadParameterImaSim.getSampling_x() * (samplingHalf_y + 1));
	mPSF_vec_blue_sampledUp_horizontal.resize(newSize);
	mPSF_vec_green_sampledUp_horizontal.resize(newSize);
	mPSF_vec_red_sampledUp_horizontal.resize(newSize);
	
	unsigned int posTemp = 0;
	unsigned int posPositive = 1;
	bool checker = true;

	unsigned int counter = 0;
	mPSF_vec_blue_sampledUp_horizontal[0] = mPSF_vec_blue[counter];
	mPSF_vec_green_sampledUp_horizontal[0] = mPSF_vec_green[counter];
	mPSF_vec_red_sampledUp_horizontal[0] = mPSF_vec_red[counter];

	unsigned int fillingCounter = 0;
	for (unsigned int i = 1; i < newSize - 1; ++i)
	{

		while (checker)
		{
			++counter;
			mPSF_vec_blue_sampledUp_horizontal[i] = (mPSF_vec_blue[posTemp] + mPSF_vec_blue[posPositive]) / 2;
			mPSF_vec_green_sampledUp_horizontal[i] = (mPSF_vec_green[posTemp] + mPSF_vec_green[posPositive]) / 2;
			mPSF_vec_red_sampledUp_horizontal[i] = (mPSF_vec_red[posTemp] + mPSF_vec_red[posPositive]) / 2;

			++i;
			mPSF_vec_blue_sampledUp_horizontal[i] = mPSF_vec_blue[counter];
			mPSF_vec_green_sampledUp_horizontal[i] = mPSF_vec_green[counter];
			mPSF_vec_red_sampledUp_horizontal[i] = mPSF_vec_red[counter];
			++fillingCounter;

			++i;
			posTemp = counter;
			posPositive = counter + 1;
			if (fillingCounter >= samplingHalf_x)
			{
				checker = false;
			}
		}
		fillingCounter = 0;
		++counter;
		posTemp = counter;
		posPositive = counter + 1;
		checker = true;
		if (counter < size)
		{
			mPSF_vec_blue_sampledUp_horizontal[i] = mPSF_vec_blue[counter];
			mPSF_vec_green_sampledUp_horizontal[i] = mPSF_vec_green[counter];
			mPSF_vec_red_sampledUp_horizontal[i] = mPSF_vec_red[counter];
		}
		
	}
}

void ImageSimulationFunctions::upSample_PSFs_vertical()
{
	//unsigned int samplingHalf = (real)mLoadParameterImaSim.getSampling_x() / 2.0 - 0.5;
	unsigned int PSFsInOneRow = mLoadParameterImaSim.getSampling_y();
	unsigned int newTotalSize = mLoadParameterImaSim.getSampling_x() * mLoadParameterImaSim.getSampling_y();

	mPSF_vec_blue_sampledUp_vertical.resize(newTotalSize);
	mPSF_vec_green_sampledUp_vertical.resize(newTotalSize);
	mPSF_vec_red_sampledUp_vertical.resize(newTotalSize);

	unsigned int rowCounterOrigin = 0;
	unsigned int psfHorizontalCounter = 0;
	unsigned int roundCounter = 1;
	bool first = true;
	unsigned horizontalStepForward;

	for (unsigned int i = 0; i < newTotalSize; ++i)
	{
		if (rowCounterOrigin < PSFsInOneRow)
		{
			mPSF_vec_blue_sampledUp_vertical[i] = mPSF_vec_blue_sampledUp_horizontal[psfHorizontalCounter];
			mPSF_vec_green_sampledUp_vertical[i] = mPSF_vec_green_sampledUp_horizontal[psfHorizontalCounter];
			mPSF_vec_red_sampledUp_vertical[i] = mPSF_vec_red_sampledUp_horizontal[psfHorizontalCounter];

			++rowCounterOrigin;
			++psfHorizontalCounter;
			first = true;
		}
			
		else
		{
			if (first)
			{
				psfHorizontalCounter = psfHorizontalCounter - PSFsInOneRow;
				first = false;
			}
			horizontalStepForward = psfHorizontalCounter + PSFsInOneRow;
			mPSF_vec_blue_sampledUp_vertical[i] = (mPSF_vec_blue_sampledUp_horizontal[psfHorizontalCounter] + mPSF_vec_blue_sampledUp_horizontal[horizontalStepForward]) / 2;
			mPSF_vec_green_sampledUp_vertical[i] = (mPSF_vec_green_sampledUp_horizontal[psfHorizontalCounter] + mPSF_vec_green_sampledUp_horizontal[horizontalStepForward]) / 2;
			mPSF_vec_red_sampledUp_vertical[i] = (mPSF_vec_red_sampledUp_horizontal[psfHorizontalCounter] + mPSF_vec_red_sampledUp_horizontal[horizontalStepForward]) / 2;

			++psfHorizontalCounter;
			if (psfHorizontalCounter >= PSFsInOneRow * roundCounter)
			{
				rowCounterOrigin = 0;
				psfHorizontalCounter = PSFsInOneRow * roundCounter;
				++roundCounter;
			}
		}

	}


}

// rotate matrix by 90°
cv::Mat ImageSimulationFunctions::rotateMatrixBy_90degrees(cv::Mat& mat)
{
	cv::Point2f src_center(mat.cols / 2.0F, mat.rows / 2.0F);
	cv::Mat rot_mat = getRotationMatrix2D(src_center, 90.0, 1.0);
	cv::Mat dst;
	cv::warpAffine(mat, dst, rot_mat, mat.size());

	return dst;
}

cv::Mat ImageSimulationFunctions::flipMatrixHorizontal(cv::Mat& mat)
{
	cv::Mat flipMat;
	cv::flip(mat, flipMat, 0);
	return flipMat;
}

cv::Mat ImageSimulationFunctions::flipMatrixVertical(cv::Mat& mat)
{
	cv::Mat flipMat;
	cv::flip(mat, flipMat, 1);
	return flipMat;
}



// calculate all PSFs for convolution
void ImageSimulationFunctions::calcAllPSFsForConv_Q1()
{
	real sampling_x = mLoadParameterImaSim.getSampling_x();
	real sampling_y = mLoadParameterImaSim.getSampling_y();

	unsigned int newSize;
	unsigned int totalSize;
	unsigned int stop_x;

	if (mLoadParameterImaSim.getUpSamplePSF())
	{
		
		newSize = sampling_y * (sampling_x + sampling_x - 1);
		totalSize = newSize + newSize - (sampling_x + sampling_x - 1);
		stop_x = sampling_x - 1;

	}
	else
	{
		stop_x = sampling_x / 2;
		newSize = (stop_x + 1) * sampling_y;
		totalSize = sampling_x * sampling_y;;
	}

	mAllPSFForConv_blue.resize(totalSize);
	mAllPSFForConv_green.resize(totalSize);
	mAllPSFForConv_red.resize(totalSize);

	unsigned int posIOriginPSF = 0;
	unsigned int roundCounter = 1;

	for (unsigned int i = 0; i < newSize; ++i)
	{
		for(unsigned int x=0;x< stop_x; ++x)
		{
			
			mAllPSFForConv_blue[i] = flipMatrixVertical(mPSF_vec_blue_sampledUp_vertical[posIOriginPSF]);
			mAllPSFForConv_green[i] = flipMatrixVertical(mPSF_vec_green_sampledUp_vertical[posIOriginPSF]);
			mAllPSFForConv_red[i] = flipMatrixVertical(mPSF_vec_red_sampledUp_vertical[posIOriginPSF]);
			++posIOriginPSF;
			++i;
		}

		if (mLoadParameterImaSim.getUpSamplePSF())
		{
			posIOriginPSF = sampling_x * roundCounter - 1;
		}

		//else
		//{
		//	posIOriginPSF = roundCounter +  roundCounter * stop_j - 1;
		//}
		


		mAllPSFForConv_blue[i] = mPSF_vec_blue_sampledUp_vertical[posIOriginPSF];
		mAllPSFForConv_green[i] = mPSF_vec_green_sampledUp_vertical[posIOriginPSF];
		mAllPSFForConv_red[i] = mPSF_vec_red_sampledUp_vertical[posIOriginPSF];

		for (unsigned int k = 0; k < stop_x; ++k)
		{
			
			++i;
			--posIOriginPSF;
			mAllPSFForConv_blue[i] = mPSF_vec_blue_sampledUp_vertical[posIOriginPSF];
			mAllPSFForConv_green[i] = mPSF_vec_green_sampledUp_vertical[posIOriginPSF];
			mAllPSFForConv_red[i] = mPSF_vec_red_sampledUp_vertical[posIOriginPSF];
			
		}

		if (mLoadParameterImaSim.getUpSamplePSF())
		{
			posIOriginPSF = sampling_x * roundCounter;
		}

		else
		{
			posIOriginPSF = (stop_x + 1 ) * roundCounter;
		}

		


		++roundCounter;
	}

}

void ImageSimulationFunctions::calcAllPSFsForConv_Q2andQ3()
{
	unsigned samp_X_PlusSamp_X_MinOne;
	unsigned int newSize;
	unsigned int posInTotalVec;
	int posInOldVec;
	unsigned int roundCounter;
	int end;

	if (mLoadParameterImaSim.getUpSamplePSF())
	{
		samp_X_PlusSamp_X_MinOne = (mLoadParameterImaSim.getSampling_x() + mLoadParameterImaSim.getSampling_x() - 1);
		newSize = mLoadParameterImaSim.getSampling_y() * samp_X_PlusSamp_X_MinOne;
		posInTotalVec = newSize;
		posInOldVec = newSize - (mLoadParameterImaSim.getSampling_x() + mLoadParameterImaSim.getSampling_x() - 1) * 2;
		roundCounter = 2;
		end = mLoadParameterImaSim.getSampling_y();
	}

	else
	{
		
		samp_X_PlusSamp_X_MinOne = mLoadParameterImaSim.getSampling_x();
		newSize = mLoadParameterImaSim.getSampling_x() * (mLoadParameterImaSim.getSampling_y() / 2  + 1);
		posInTotalVec = newSize;
		posInOldVec = newSize - 2 * mLoadParameterImaSim.getSampling_x();
		roundCounter = 2;
		end = mLoadParameterImaSim.getSampling_y() / 2 + 1;

	}



	bool checker = true;
	while (checker)

	{
		for (unsigned int i = 0; i < samp_X_PlusSamp_X_MinOne; ++i)
		{
			mAllPSFForConv_blue[posInTotalVec] = flipMatrixHorizontal(mAllPSFForConv_blue[posInOldVec]);
			mAllPSFForConv_green[posInTotalVec] = flipMatrixHorizontal(mAllPSFForConv_green[posInOldVec]);
			mAllPSFForConv_red[posInTotalVec] = flipMatrixHorizontal(mAllPSFForConv_red[posInOldVec]);
			++posInTotalVec;
			++posInOldVec;

			
		}

		++roundCounter;
		posInOldVec = newSize - samp_X_PlusSamp_X_MinOne * roundCounter;
		
		// just for debugging 
		//std::cout << "pos in old vector: " << posInOldVec << std::endl;

		if (roundCounter > end)
		{
			checker = false;
		}
	}

}
//// resize all PSFs
//void ImageSimulationFunctions::resizeAllPSFs_using_LANCZOS4()
//{
//	unsigned int size = mAllPSFForConv_blue.size();
//
//	mAllPSFForConv_blue_resized.resize(size);
//	mAllPSFForConv_green_resized.resize(size);
//	mAllPSFForConv_red_resized.resize(size);
//
//	unsigned int row = mLoadParameterImaSim.getRowAndColPsfConvolution();
//	unsigned int col = mLoadParameterImaSim.getRowAndColPsfConvolution();
//
//	for (unsigned int i = 0; i < size; ++i)
//	{
//		cv::resize(mAllPSFForConv_blue[i], mAllPSFForConv_blue_resized[i], cv::Size(col, row), cv::INTER_LANCZOS4);
//		cv::resize(mAllPSFForConv_green[i], mAllPSFForConv_green_resized[i], cv::Size(col, row), cv::INTER_LANCZOS4);
//		cv::resize(mAllPSFForConv_red[i], mAllPSFForConv_red_resized[i], cv::Size(col, row), cv::INTER_LANCZOS4);
//	}
//}

void ImageSimulationFunctions::getRefIndexBeforeFirstSurface()
{
	mOptSysEle.setRefractiveIndexAccordingToWavelength(mLoadParameterImaSim.getWavelengthBlue());
	real directionZfirstSurface = mOptSysEle.getOptSys_LLT_buildSystem().getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getDirection().getZ();
	if (directionZfirstSurface > 0)
	{
		mStartRefIndex = mOptSysEle.getOptSys_LLT_buildSystem().getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getRefractiveIndex_A();
	}

	else if (directionZfirstSurface < 0)
	{
		mStartRefIndex = mOptSysEle.getOptSys_LLT_buildSystem().getPosAndInteractingSurface()[0].getSurfaceInterRay_ptr()->getRefractiveIndex_B();
	}

	else // direction Z first surface must be zero -> error
	{
		oftenUse::errorProtocol_stopSystem("direction first surface is zero", "ImageSimulation.cpp", 0, true);
	}

}

void ImageSimulationFunctions::calcDistortedImages()
{
	// resize the images
	cv::resize(mSimulatedIma_blue, mSimulatedIma_blue_initialSize, mInitialObj.size(), cv::INTER_LANCZOS4);
	cv::resize(mSimulatedIma_green, mSimulatedIma_green_initialSize, mInitialObj.size(), cv::INTER_LANCZOS4);
	cv::resize(mSimulatedIma_red, mSimulatedIma_red_initialSize, mInitialObj.size(), cv::INTER_LANCZOS4);

	std::vector<cv::Mat> array_to_merge;

	array_to_merge.push_back(mSimulatedIma_blue_initialSize);
	array_to_merge.push_back(mSimulatedIma_green_initialSize);
	array_to_merge.push_back(mSimulatedIma_red_initialSize);

	cv::merge(array_to_merge, mSimulatedIma_bgr_noDistortion_initialSize);
	cv::resize(mSimulatedIma_bgr_noDistortion_initialSize, mSimulatedIma_bgr_noDistortion_initialSize, mInitialObj.size(), cv::INTER_LANCZOS4, CV_64FC3);

	real min{};
	real max{};

	cv::minMaxLoc(mSimulatedIma_bgr_noDistortion_initialSize, &min, &max);
	real ratio = 1.0 / max;

	mSimulatedIma_bgr_noDistortion_initialSize = mSimulatedIma_bgr_noDistortion_initialSize * ratio;

	// split the image in BGR
	cv::Mat channel[3];
	cv::split(mSimulatedIma_bgr_noDistortion_initialSize, channel);

	mSimulatedIma_blue_initialSize = channel[0];
	mSimulatedIma_green_initialSize = channel[1];
	mSimulatedIma_red_initialSize = channel[2];


	// distortion blue
	Distortion distortionBlue;
	Light_LLT lightBlue = mLoadParameterImaSim.getLight();
	lightBlue.setWavelength(mLoadParameterImaSim.getWavelengthBlue());
	distortionBlue.calculateDistortion_superFunction_obj(mSimulatedIma_blue_initialSize, mOptSysLLT_blue, lightBlue, mLoadParameterImaSim.getSamplingDistortionHeight(), mLoadParameterImaSim.getSamplingDistortionWidth(), 2.0 * mLoadParameterImaSim.getSemiHeightObj(), 2.0 * mLoadParameterImaSim.getSemiWidthObj(), mLoadParameterImaSim.getPosition_Z_Object());
	mSimulatedIma_blue_initialSize = distortionBlue.getDistortedImage();
	mSimulatedIma_blue_initialSize_distortionCorrected = distortionBlue.correctDistortion();

	// distortion green
	Distortion distortionGreen;
	Light_LLT lightGreen = mLoadParameterImaSim.getLight();
	lightBlue.setWavelength(mLoadParameterImaSim.getWavelengthGreen());
	distortionGreen.calculateDistortion_superFunction_obj(mSimulatedIma_green_initialSize, mOptSysLLT_green, lightGreen, mLoadParameterImaSim.getSamplingDistortionHeight(), mLoadParameterImaSim.getSamplingDistortionWidth(), 2.0 * mLoadParameterImaSim.getSemiHeightObj(), 2.0 * mLoadParameterImaSim.getSemiWidthObj(), mLoadParameterImaSim.getPosition_Z_Object());
	mSimulatedIma_green_initialSize = distortionGreen.getDistortedImage();
	mSimulatedIma_green_initialSize_distortionCorrected = distortionGreen.correctDistortion();

	// distortion red
	Distortion distortionRed;
	Light_LLT lightRed = mLoadParameterImaSim.getLight();
	lightRed.setWavelength(mLoadParameterImaSim.getWavelengthRed());
	distortionRed.calculateDistortion_superFunction_obj(mSimulatedIma_red_initialSize, mOptSysLLT_red, lightRed, mLoadParameterImaSim.getSamplingDistortionHeight(), mLoadParameterImaSim.getSamplingDistortionWidth(), 2.0 * mLoadParameterImaSim.getSemiHeightObj(), 2.0 * mLoadParameterImaSim.getSemiWidthObj(), mLoadParameterImaSim.getPosition_Z_Object());
	mSimulatedIma_red_initialSize = distortionRed.getDistortedImage();
	mSimulatedIma_red_initialSize_distortionCorrected = distortionRed.correctDistortion();
}

// get distorten corrected ima
cv::Mat ImageSimulationFunctions::getSimulatedImage_initialSize_distortionCorrected()
{
	return mSimulatedIma_bgr_final_initialSize_distortionCorrection;
}


// get functions
// ***
// get the LLT systems
OpticalSystem_LLT ImageSimulationFunctions::getOptSys_blue()
{
	return mOptSysLLT_blue;
}
OpticalSystem_LLT ImageSimulationFunctions::getOptSys_green()
{
	return mOptSysLLT_green;
}
OpticalSystem_LLT ImageSimulationFunctions::getOptSys_red()
{
	return mOptSysLLT_red;
}


// get OPDs
std::vector<cv::Mat> ImageSimulationFunctions::getOPD_blue()
{
	return mOPD_vec_blue;
}
std::vector<cv::Mat> ImageSimulationFunctions::getOPD_green()
{
	return mOPD_vec_green;
}
std::vector<cv::Mat> ImageSimulationFunctions::getOPD_red()
{
	return mOPD_vec_red;
}

// get resized OPDs
std::vector<cv::Mat> ImageSimulationFunctions::getOPD_resized_blue()
{
	return mOPD_vec_blue_resized;
}
std::vector<cv::Mat> ImageSimulationFunctions::getOPD_resized_green()
{
	return mOPD_vec_green_resized;
}
std::vector<cv::Mat> ImageSimulationFunctions::getOPD_resized_red()
{
	return mOPD_vec_red_resized;
}

// get calculated PSFs
std::vector<cv::Mat> ImageSimulationFunctions::getCalcPSF_blue()
{
	return mPSF_vec_blue;
}
std::vector<cv::Mat> ImageSimulationFunctions::getCalcPSF_green()
{
	return mPSF_vec_green;
}
std::vector<cv::Mat> ImageSimulationFunctions::getCalcPSF_red()
{
	return mPSF_vec_red;
}


// get sampled UP PSF horizontal
std::vector<cv::Mat> ImageSimulationFunctions::getSampledUpPSF_horizontal_blue()
{
	return mPSF_vec_blue_sampledUp_horizontal;
}
std::vector<cv::Mat> ImageSimulationFunctions::getSampledUpPSF_horizontal_green()
{
	return mPSF_vec_green_sampledUp_horizontal;
}
std::vector<cv::Mat> ImageSimulationFunctions::getSampledUpPSF_horizontal_red()
{
	return mPSF_vec_red_sampledUp_horizontal;
}
// get sampled UP PSF vertical
std::vector<cv::Mat> ImageSimulationFunctions::getSampledUpPSF_vertical_blue()
{
	return mPSF_vec_blue_sampledUp_vertical;
}
std::vector<cv::Mat> ImageSimulationFunctions::getSampledUpPSF_vertical_green()
{
	return mPSF_vec_green_sampledUp_vertical;
}
std::vector<cv::Mat> ImageSimulationFunctions::getSampledUpPSF_vertical_red()
{
	return mPSF_vec_red_sampledUp_vertical;
}

// get all PSFs for convolution
std::vector<cv::Mat> ImageSimulationFunctions::getAllPSFsForConvolution_blue()
{
	return mAllPSFForConv_blue;
}
std::vector<cv::Mat> ImageSimulationFunctions::getAllPSFsForConvolution_green()
{
	return mAllPSFForConv_green;
}
std::vector<cv::Mat> ImageSimulationFunctions::getAllPSFsForConvolution_red()
{
	return mAllPSFForConv_red;
}

// get simulated image grids
std::vector<cv::Mat> ImageSimulationFunctions::getSimulatedImaGrid_blue()
{
	return mSimulatedImageGrid_blue;
}
std::vector<cv::Mat> ImageSimulationFunctions::getSimulatedImaGrid_green()
{
	return mSimulatedImageGrid_green;
}
std::vector<cv::Mat> ImageSimulationFunctions::getSimulatedImaGrid_red()
{
	return mSimulatedImageGrid_red;
}

// simulated image single color
cv::Mat ImageSimulationFunctions::getSimulatedImage_blue()
{
	return mSimulatedIma_blue;
}
cv::Mat ImageSimulationFunctions::getSimulatedImage_green()
{
	return mSimulatedIma_green;
}
cv::Mat ImageSimulationFunctions::getSimulatedImage_red()
{
	return mSimulatedIma_red;
}

// load parameter image simulation
loadParaImaSim ImageSimulationFunctions::getLoadParameterImaSim()
{
	return mLoadParameterImaSim;
}

// *** distortion *** 
void ImageSimulationFunctions::calculateDistortedIma_test0(cv::Mat& inputIma, cv::Mat& distortedIma, real k)
{
	// just for debugging
	//std::string imaType = Images::getTypeImageC_VMat(inputIma);

	// die if sample image is not the correct type
	if (inputIma.type() != CV_8UC1 && inputIma.type() != CV_8UC3)
	{
		oftenUse::errorProtocol_stopSystem("we need a 8UC1 or 8UC3 image", "ImageSimulation.cpp", 0, true);
	}

	bool scale = true;
	real Cx = inputIma.cols / 2;
	real Cy = inputIma.rows / 2;

	cv::Mat mapx = cv::Mat(inputIma.size(), CV_32FC1);
	cv::Mat mapy = cv::Mat(inputIma.size(), CV_32FC1);

	unsigned int w = inputIma.cols;
	unsigned int h = inputIma.rows;

	cv::Vec4f props;
	float xShift = calc_shift_test0(0, Cx - 1, Cx, k);
	props[0] = xShift;
	float newCenterX = w - Cx;
	float xShift2 = calc_shift_test0(0, newCenterX - 1, newCenterX, k);
	
	float yShift = calc_shift_test0(0, Cy - 1, Cy, k);
	props[1] = yShift;
	float newCenterY = w - Cy;
	float yShift2 = calc_shift_test0(0, newCenterY - 1, newCenterY, k);
	
	float xScale = (w - xShift - xShift2) / w;
	props[2] = xScale;
	float yScale = (h - yShift - yShift2) / h;
	props[3] = yScale;

	float* p = mapx.ptr<float>(0);

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			*p++ = getRadialX_test0((float)x, (float)y, Cx, Cy, k, scale, props);
		}
	}

	p = mapy.ptr<float>(0);
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			*p++ = getRadialY_test0((float)x, (float)y, Cx, Cy, k, scale, props);
		}
	}

	// just for debugging
	inportExportData::exportCV_MatToExcel(mapx, "..", "test");

	cv::remap(inputIma, distortedIma, mapx, mapy, CV_INTER_LINEAR, cv::BORDER_CONSTANT);

}


float ImageSimulationFunctions::calc_shift_test0(float x1, float x2, float cx, float k)
{
	float thresh = 1.0;
	float x3 = x1 + (x2 - x1) * 0.5;
	float res1 = x1 + ((x1 - cx) * k * ((x1 - cx) * (x1 - cx)));
	float res3 = x3 + ((x3 - cx) * k * ((x3 - cx) * (x3 - cx)));

	//    std::cerr<<"x1: "<<x1<<" - "<<res1<<" x3: "<<x3<<" - "<<res3<<std::endl;

	if (res1 > -thresh && res1 < thresh)
		return x1;

	if (res3 < 0) 
	{
		return calc_shift_test0(x3, x2, cx, k);
	}
	else 
	{
		return calc_shift_test0(x1, x3, cx, k);
	}
}

float ImageSimulationFunctions::getRadialX_test0(float x, float y, float cx, float cy, float k, bool scale, cv::Vec4f props)
{
	float result;
	if (scale)
	{
		float xshift = props[0];
		float yshift = props[1];
		float xscale = props[2];
		float yscale = props[3];

		x = (x * xscale + xshift);
		y = (y * yscale + yshift);
		result = x + ((x - cx) * k * ((x - cx) * (x - cx) + (y - cy) * (y - cy)));
		// see: https://en.wikipedia.org/wiki/Distortion_(optics
	}
	else 
	{
		//        result = (cx+(x-cx)*(1+k*((x-cx)*(x-cx)+(y-cy)*(y-cy))));
		//        or
		result = x + ((x - cx) * k * ((x - cx) * (x - cx) + (y - cy) * (y - cy)));
	}
	return result;
}

float ImageSimulationFunctions::getRadialY_test0(float x, float y, float cx, float cy, float k, bool scale, cv::Vec4f props)
{
	float result;
	if (scale)
	{
		float xshift = props[0];
		float yshift = props[1];
		float xscale = props[2];
		float yscale = props[3];

		x = (x * xscale + xshift);
		y = (y * yscale + yshift);
		result = y + ((y - cy) * k * ((x - cx) * (x - cx) + (y - cy) * (y - cy)));
	}
	else {
		//        result = (cy+(y-cy)*(1+k*((x-cx)*(x-cx)+(y-cy)*(y-cy))));
		//        or
		result = y + ((y - cy) * k * ((x - cx) * (x - cx) + (y - cy) * (y - cy)));
	}
	return result;
}

cv::Mat ImageSimulationFunctions::barrel_pincusion_dist(cv::Mat img, double Cx, double Cy, double kx, double ky)
{

	cv::Mat mapx = cv::Mat(img.size(), CV_32FC1);
	cv::Mat mapy = cv::Mat(img.size(), CV_32FC1);

	int w = img.cols;
	int h = img.rows;

	//float* pbuf = mapx.ptr<float>(0);
	//for (int y = 0; y < h; y++)
	//{
	//	for (int x = 0; x < w; x++)
	//	{
	//		float u = Cx + (x - Cx) * (1 + kx * ((x - Cx) * (x - Cx) + (y - Cy) * (y - Cy)));
	//		*pbuf = u;
	//		++pbuf;
	//	}
	//}
	//
	//pbuf = mapy.ptr<float>(0);
	//for (int y = 0; y < h; y++)
	//{
	//	for (int x = 0; x < w; x++)
	//	{
	//		*pbuf = Cy + (y - Cy) * (1 + ky * ((x - Cx) * (x - Cx) + (y - Cy) * (y - Cy)));
	//		++pbuf;
	//	}
	//}

	float* pbuf = mapx.ptr<float>(0);
	for (int y = 0; y < h; y++)
	{
		int ty= y-Cy;
		for (int x = 0; x < w; x++)
		{
			int tx= x-Cx;
			int rt= tx*tx+ty*ty;

			*pbuf = (float)(tx*(1+kx*rt)+Cx);
			//*pbuf = (float)x + ((float)x - (float)Cx) * kx * tx;

			// just for debugging
			float& affe = *pbuf;
			std::cout << affe << std::endl;

			++pbuf;
		}
	}

	pbuf = mapy.ptr<float>(0);
	for (int y = 0;y < h; y++)
	{
		int ty= y-Cy;
		for (int x = 0; x < w; x++)
		{
			int tx= x-Cx;
			int rt= tx*tx+ty*ty;

			*pbuf = (float)(ty*(1+ky*rt)+Cy);
			
			++pbuf;
		}
	}

	cv::Mat temp = img.clone();
	cv::remap(temp, img, mapx, mapy, CV_INTER_LINEAR, cv::BORDER_CONSTANT);

	//cv::remap(inputIma, distortedIma, mapx, mapy, CV_INTER_LINEAR, cv::BORDER_CONSTANT);

	//cvReleaseImage(&temp);
	//cvReleaseImage(&mapx);
	//cvReleaseImage(&mapy);

	return img;

}

// see: https://answers.opencv.org/question/57179/creation-of-images-with-warpdistortion-due-to-natural-effects-on-camera-lens/?sort=votes
void ImageSimulationFunctions::calculateDistortedIma_testCR_doNotUseThat(cv::Mat& inputIma, cv::Mat& distortedIma, real k)
{
	// just for debugging
	//std::string imaType = Images::getTypeImageC_VMat(inputIma);

	// die if sample image is not the correct type
	if (inputIma.type() != CV_8UC1 && inputIma.type() != CV_8UC3)
	{
		oftenUse::errorProtocol_stopSystem("we need a 8UC1 or 8UC3 image", "ImageSimulation.cpp", 0, true);
	}

	bool scale = true;
	real Cx = inputIma.cols / 2;
	real Cy = inputIma.rows / 2;

	cv::Mat mapx = cv::Mat(inputIma.size(), CV_32FC1);
	cv::Mat mapy = cv::Mat(inputIma.size(), CV_32FC1);

	unsigned int w = inputIma.cols;
	unsigned int h = inputIma.rows;

	cv::Vec4f props;
	float xShift =  calc_shift_testCR_doNotUseThat(0, Cx - 1, Cx, k);
	props[0] = xShift;
	float newCenterX = w - Cx;
	float xShift2 =  calc_shift_testCR_doNotUseThat(0, newCenterX - 1, newCenterX, k);

	float yShift =  calc_shift_testCR_doNotUseThat(0, Cy - 1, Cy, k);
	props[1] = yShift;
	float newCenterY = w - Cy;
	float yShift2 =  calc_shift_testCR_doNotUseThat(0, newCenterY - 1, newCenterY, k);

	float xScale =  (w - xShift - xShift2) / w;
	props[2] = xScale;
	float yScale =  (h - yShift - yShift2) / h;
	props[3] = yScale;

	float* p = mapx.ptr<float>(0);

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			*p++ = getRadialX_testCR_doNotUseThat((float)x, (float)y, Cx, Cy, k, scale, props);
		}
	}

	p = mapy.ptr<float>(0);
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			*p++ = getRadialY_testCR_doNotUseThat((float)x, (float)y, Cx, Cy, k, scale, props);
		}
	}

	// just for debugging
	Images::showImage_inputReal_normTheImage("mapx", mapx);
	Images::showImage_inputReal_normTheImage("mapy", mapy);

	//cv::Mat mapx_flp = flipMatrixHorizontal(mapx);
	//cv::Mat mapy_flp = flipMatrixHorizontal(mapy);
	//
	//// just for debugging
	//Images::showImage_inputReal("mapx_flip", mapx_flp);
	//Images::showImage_inputReal("mapy_flip", mapx_flp);


	cv::remap(inputIma, distortedIma, mapx, mapy, CV_INTER_LINEAR, cv::BORDER_CONSTANT);
}
float ImageSimulationFunctions::calc_shift_testCR_doNotUseThat(float x1, float x2, float cx, float k)
{
	float thresh = 1.0;
	float x3 = x1 + (x2 - x1) * 0.5;
	float res1 = x1 + ((x1 - cx) * k * ((x1 - cx) * (x1 - cx)));
	float res3 = x3 + ((x3 - cx) * k * ((x3 - cx) * (x3 - cx)));

	//    std::cerr<<"x1: "<<x1<<" - "<<res1<<" x3: "<<x3<<" - "<<res3<<std::endl;

	if (res1 > -thresh && res1 < thresh)
		return x1;

	if (res3 < 0)
	{
		return calc_shift_test0(x3, x2, cx, k);
	}
	else
	{
		return calc_shift_test0(x1, x3, cx, k);
	}
}
float ImageSimulationFunctions::getRadialX_testCR_doNotUseThat(float x, float y, float cx, float cy, float k, bool scale, cv::Vec4f props)
{
	float result;
	if (scale)
	{
		float xshift = props[0];
		float yshift = props[1];
		float xscale = props[2];
		float yscale = props[3];

		x = (x * xscale + xshift);

		y = (y * yscale + yshift);
		result = x + ((x - cx) * k *  ((x - cx) * (x - cx) + (y - cy) * (y - cy)));
		// see: https://en.wikipedia.org/wiki/Distortion_(optics

		//std::cout << "result: " << result << std::endl;
	}
	else
	{
		//        result = (cx+(x-cx)*(1+k*((x-cx)*(x-cx)+(y-cy)*(y-cy))));
		//        or
		result = x + ((x - cx) * k * ((x - cx) * (x - cx) + (y - cy) * (y - cy)));
	}
	return result;
}
float ImageSimulationFunctions::getRadialY_testCR_doNotUseThat(float x, float y, float cx, float cy, float k, bool scale, cv::Vec4f props)
{
	float result;
	if (scale)
	{
		float xshift = props[0];
		float yshift = props[1];
		float xscale = props[2];
		float yscale = props[3];

		x = (x * xscale + xshift);
		y = (y * yscale + yshift);
		result = y + ((y - cy) * k * ((x - cx) * (x - cx) + (y - cy) * (y - cy)));
	}
	else {
		//        result = (cy+(y-cy)*(1+k*((x-cx)*(x-cx)+(y-cy)*(y-cy))));
		//        or
		result = y + ((y - cy) * k * ((x - cx) * (x - cx) + (y - cy) * (y - cy)));
	}
	return result;
}

// cv::remap
void ImageSimulationFunctions::remapImage(cv::Mat& inputImag, cv::Mat& remapedIma, int remapNumber)
{	
	cv::Mat map_x(inputImag.size(), CV_32FC1);
	cv::Mat map_y(inputImag.size(), CV_32FC1);

	update_map(remapNumber, map_x, map_y);

	remap(inputImag, remapedIma, map_x, map_y, cv::INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));
}

void ImageSimulationFunctions::update_map(int& ind, cv::Mat& map_x, cv::Mat& map_y)
{
	float mapX_value;
	float mapY_value;

	for (int i = 0; i < map_x.rows; i++)
	{
		for (int j = 0; j < map_x.cols; j++)
		{
			switch (ind)
			{
			case 0:
				if (j > map_x.cols * 0.25 && j < map_x.cols * 0.75 && i > map_x.rows * 0.25 && i < map_x.rows * 0.75)
				{
					map_x.at<float>(i, j) = 2 * (j - map_x.cols * 0.25f) + 0.5f;
					map_y.at<float>(i, j) = 2 * (i - map_x.rows * 0.25f) + 0.5f;
				}
				else
				{
					map_x.at<float>(i, j) = 0;
					map_y.at<float>(i, j) = 0;
				}
				break;
			case 1:

				mapX_value = (float)j;
				mapY_value = (float)(map_x.rows - i);

				map_x.at<float>(i, j) = mapX_value;
				map_y.at<float>(i, j) = mapY_value;
				break;
			case 2:
				map_x.at<float>(i, j) = (float)(map_x.cols - j);
				map_y.at<float>(i, j) = (float)i;
				break;
			case 3:
				map_x.at<float>(i, j) = (float)(map_x.cols - j);
				map_y.at<float>(i, j) = (float)(map_x.rows - i);
				break;
			default:
				break;
			} // end of switch
		}
	}
	ind = (ind + 1) % 4;
}


// cv::remap for distortion
void ImageSimulationFunctions::distorImaUsingRemap(cv::Mat& inputIma, cv::Mat& distortedIma, real factor)
{
	cv::Mat map_x(inputIma.size(), CV_32FC1);
	cv::Mat map_y(inputIma.size(), CV_32FC1);


	int cols = inputIma.cols;
	int row = inputIma.rows;

	real separation = cols;
	real tempX = 0;
	real separationX = 1;



	for (unsigned int i = 0; i < row; ++i)
	{
		tempX = (float)2.0*i;
		//separationX = (cols - 2.0 * tempX) / separation;

		for (unsigned int j = 0; j < cols; ++j)
		{
			std::cout << "tempX: " << tempX << std::endl;

			map_x.at<float>(i, j) = tempX;
			tempX = tempX + separationX;
			map_y.at<float>(i, j) = (float)i;

		}
	}

	//cv::Point2f src_center(map_x.cols / 2.0F, map_x.rows / 2.0F);
	//cv::Mat rot_mat = cv::getRotationMatrix2D(src_center, -90.0, 1.0);
	//
	//cv::warpAffine(map_x, map_y, rot_mat, map_x.size());
	//map_y = map_x;
	remap(inputIma, distortedIma, map_x, map_y, cv::INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));
}

cv::Size ImageSimulationFunctions::getSizeResizedObjForConv()
{
	return mSizeResizedObjForConv;
}

cv::Size ImageSimulationFunctions::getSizeInitialObj()
{
	return mSizeInitialObj;
}

