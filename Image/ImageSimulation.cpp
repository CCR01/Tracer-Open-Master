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

defautParaImaSim::defautParaImaSim() {};
defautParaImaSim::~defautParaImaSim() {};

// row bigger for convolution
unsigned int defautParaImaSim::getRowBiggerForConv()
{
	return mRow_BiggerForConv;
}
void defautParaImaSim::setRowBiggerForConV(unsigned int rowBiggerConv)
{
	mRow_BiggerForConv = rowBiggerConv;
}
// col bigger for convolution
unsigned int defautParaImaSim::getColBiggerForConv()
{
	return mCol_BiggerForConv;
}
void defautParaImaSim::setColBiggerForConv(unsigned int colBiggerConv)
{
	mCol_BiggerForConv = colBiggerConv;
}
// wave blue
real defautParaImaSim::getWavelengthBlue()
{
	return mWavelength_blue;
}
void defautParaImaSim::setWavelengthBlue(real waveBlue)
{
	mWavelength_blue = waveBlue;
}
// wave green
real defautParaImaSim::getWavelengthGreen()
{
	return mWavelength_green;
}
void defautParaImaSim::setWavelengthGreen(real waveGreen)
{
	mWavelength_green = waveGreen;
}
// wave red
real defautParaImaSim::getWavelengthRed()
{
	return mWavelength_red;
}
void defautParaImaSim::setWavelengthRed(real waveRed)
{
	mWavelength_red = waveRed;
}
// ray density
real defautParaImaSim::getRayDensity()
{
	return mRayDesnity;
}
void defautParaImaSim::setRayDensity(unsigned int rayDensity)
{
	mRayDesnity = rayDensity;
}
// light
Light_LLT defautParaImaSim::getLight()
{
	return mLight;
}
void defautParaImaSim::setLight(Light_LLT light)
{
	mLight = light;
}
// start refractive index
real defautParaImaSim::getStartRefIndex()
{
	return mStartRefIndex;
}
void defautParaImaSim::setStartRefIndex(real startRefIndex)
{
	mStartRefIndex = startRefIndex;
}
// size matrix to save OPD
unsigned int defautParaImaSim::getSizeMatrixToSaveOPD()
{
	return mSizeMatrixToSaveOPD;
}
void defautParaImaSim::setSizeMatrixToSaveOPD(unsigned int sizeMatrixOPD)
{
	mSizeMatrixToSaveOPD = sizeMatrixOPD;
}
// inf of obj
void defautParaImaSim::setInfOrObj(objectPoint_inf_obj inf_obj)
{
	mInf_obj = inf_obj;
}
objectPoint_inf_obj defautParaImaSim::getInfOrObj()
{
	return mInf_obj;
}
// row and col resize OPD
void defautParaImaSim::setRowColResizeOPD(unsigned int rowAndCol)
{
	mRowColResizeOPD = rowAndCol;
}
unsigned int defautParaImaSim::getRowAndColResizeOPD()
{
	return mRowColResizeOPD;
}


ImageSimulationFunctions::ImageSimulationFunctions() {};
ImageSimulationFunctions::~ImageSimulationFunctions() {};


void ImageSimulationFunctions::imageSimulationSuperFct(cv::Mat initialObj)
{
	// save the initial object
	mInitialObj = initialObj;
	// adaped the object for later image simulation
	adaptTheObjectForSimulation();
	// split the bgr object in separet objects 
	splitTheBGRImageInColors();
	// make the object grid of BGR 
	//separateTheImageInNtimesMimages();
	//separateTheImageInNtimesMimages_saveThatFct();
	separateTheImageInNtimesMimages();
	// convolute the 
	convoluteObjectGridWithPSF();
	// put the image grids together
	//putImaGridsTogether();
	//putImaGridsTogether_saveThatFct();
	putImaGridsTogether();
	// filling black strips
	//fillingBlackStrips();
	// put all channles together, scale the image and save the image as CV_8UC 
	putAllChannlesTogetherScaleAndSaveIma();


}

void ImageSimulationFunctions::setRowBiggerForConv(unsigned int pixBiggerRow)
{
	mDefaultParameterImaSim.setRowBiggerForConV(pixBiggerRow);
}
void ImageSimulationFunctions::setColBiggerForConv(unsigned int pixBiggerCol)
{
	mDefaultParameterImaSim.setColBiggerForConv(pixBiggerCol);
}

void ImageSimulationFunctions::fillingBlackStrips()
{
	unsigned int rowObjAda = mAdaptedObj_blue.rows;
	unsigned int colObjAda = mAdaptedObj_blue.cols;

	unsigned int tempStartRow = 0;
	unsigned int separationRow = rowObjAda / mGridFactor;
	unsigned int tempEndRow = separationRow;

	unsigned int tempStartCol = 0;
	unsigned int separationCol = (colObjAda / mGridFactor);
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
	cv::Mat convertedObject_blue{};
	cv::Mat convertedObject_green{};
	cv::Mat convertedObject_red{};
	
	mSimulatedImageGrid_blue.resize(size);
	mSimulatedImageGrid_green.resize(size);
	mSimulatedImageGrid_red.resize(size);

	// just for debugging
	// std::string counterStr;

	for (unsigned int i = 0; i < size; ++i)
	{
		// blue
		mObjectGrid_blue[i].convertTo(convertedObject_blue, CV_64F);
		mSimulatedImageGrid_blue[i] = convolution(convertedObject_blue, mLoadedPSFs_vec_blue[i]);
		//mSimulatedImageGrid_blue[i] = convolution(mObjectGrid_blue[i], mLoadedPSFs_vec_blue[i]);
		// just for debugging
		// Images::showImage("grid ima blue", mObjectGrid_blue[i]);
		// counterStr = std::to_string(i);
		// Images::saveImage("..", "convolutedBlue" + counterStr, "png", mSimulatedImageGrid_blue[i]);

		// green
		mObjectGrid_green[i].convertTo(convertedObject_green, CV_64F);
		mSimulatedImageGrid_green[i] = convolution(convertedObject_green, mLoadedPSFs_vec_green[i]);

		// red
		mObjectGrid_red[i].convertTo(convertedObject_red, CV_64F);
		mSimulatedImageGrid_red[i] = convolution(convertedObject_red, mLoadedPSFs_vec_red[i]);
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

void ImageSimulationFunctions::setGridFactor(unsigned int gridFactor)
{
	mGridFactor = gridFactor;
}

void ImageSimulationFunctions::separateTheImageInNtimesMimages_saveThatFct_1()
{
	std::vector <cv::Mat> retrunObjectGrid;

	unsigned int rowObjAda = mAdaptedObj_blue.rows;
	unsigned int colObjAda = mAdaptedObj_blue.cols;

	unsigned int tempStartRow = 0;
	unsigned int separationRow = rowObjAda / mGridFactor;
	unsigned int tempEndRow = separationRow;

	unsigned int tempStartCol = 0;
	unsigned int separationCol = (colObjAda / mGridFactor);
	unsigned int tempEndCol = separationCol;


	unsigned int sizeObjGrid = mGridFactor * mGridFactor;
	mObjectGrid_blue.resize(sizeObjGrid);
	mObjectGrid_green.resize(sizeObjGrid);
	mObjectGrid_red.resize(sizeObjGrid);
	unsigned int counter = 0;

	cv::Mat tempSeparatedObject_blue;
	cv::Mat tempSeparatedObject_green;
	cv::Mat tempSeparatedObject_red;


	for (unsigned int i = 0; i < mGridFactor; ++i)
	{
		for (unsigned int j = 0; j < mGridFactor; ++j)
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
	unsigned int separationRow = rowObjAda / mGridFactor;
	unsigned int tempEndRow = separationRow;

	unsigned int tempStartCol = 0;
	unsigned int separationCol = (colObjAda / mGridFactor);
	unsigned int tempEndCol = separationCol;


	unsigned int sizeObjGrid = mGridFactor * mGridFactor;

	mSimulatedIma_blue = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_blue[0].type());
	mSimulatedIma_green = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_green[0].type());
	mSimulatedIma_red = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_red[0].type());

	cv::Mat imagePart_blue;
	cv::Mat imagePart_green;
	cv::Mat imagePart_red;

	unsigned int counter = 0;
	// just for debugging
	// std::string counterStr;

	for (unsigned int i = 0; i < mGridFactor; ++i)
	{
		for (unsigned int j = 0; j < mGridFactor; ++j)
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
	cv::Mat ProcessedObjectMatrix;
	int a = mInitialObj.size().height;
	a = a - (a % mGridFactor);
	int b = mInitialObj.size().width;
	b = b - (b % mGridFactor);

	cv::Rect ROI(0, 0, b, a);
	mAdaptedObj = mInitialObj(ROI);
	
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
	mAdaptedObj_green = channel[1];
	mAdaptedObj_red = channel[2];

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

void ImageSimulationFunctions::loadPSFs_blue(std::vector<cv::Mat> PSF_vec_blue)
{
	mLoadedPSFs_vec_blue = PSF_vec_blue;
}
void ImageSimulationFunctions::loadPSFs_green(std::vector<cv::Mat> PSF_vec_green)
{
	mLoadedPSFs_vec_green = PSF_vec_green;
}
void ImageSimulationFunctions::loadPSFs_red(std::vector<cv::Mat> PSF_vec_red)
{
	mLoadedPSFs_vec_red = PSF_vec_red;
}

void ImageSimulationFunctions::plotAllObjektGrids(std::vector<cv::Mat> objGrid_vec)
{
	
	unsigned sizeGrid = objGrid_vec.size();
	std::string tempString{};

	for (unsigned int i = 0; i < sizeGrid; ++i)
	{
		tempString = std::to_string(i);
		Images::showImage_inputReal(tempString, objGrid_vec[i]);
	}
	
}

cv::Mat ImageSimulationFunctions::convolution(const cv::Mat& obj, const cv::Mat& PSF)
{

	// see: https://docs.opencv.org/3.4/d4/d86/group__imgproc__filter.html#ga27c049795ce870216ddfb366086b5a04

	cv::Mat flipped_kernel;
	cv::flip(PSF, flipped_kernel, -1);

	cv::Point anchor(PSF.cols - PSF.cols / 2 - 1, PSF.rows - PSF.rows / 2 - 1);
	int delta = 0;
	int ddepth = -1;
	cv::Mat convolutedIma;

	
	cv::filter2D(obj, convolutedIma, ddepth, flipped_kernel, anchor, delta, cv::BORDER_DEFAULT);

	return convolutedIma;
}








void ImageSimulationFunctions::putAllChannlesTogetherScaleAndSaveIma()
{
	std::vector<cv::Mat> array_to_merge;

	array_to_merge.push_back(mSimulatedIma_blue);
	array_to_merge.push_back(mSimulatedIma_green);
	array_to_merge.push_back(mSimulatedIma_red);


	//// just for debugging
	//Images::showImage_inputReal("simulated ima blue", mSimulatedIma_blue);
	//Images::showImage_inputReal("simulated ima green", mSimulatedIma_green);
	//Images::showImage_inputReal("simulated ima red", mSimulatedIma_red);
   

	cv::merge(array_to_merge, mSimulatedIma_bgr_unscaled);
	// just for debugging
	//Images::showImage("simulated ima bgr", mSimulatedIma_bgr_unscaled);

	real min{};
	real max{};
	cv::minMaxLoc(mSimulatedIma_bgr_unscaled, &min, &max);
	
	double ratio = 255.0 / max;
	mSimulatedIma_bgr_unscaled = mSimulatedIma_bgr_unscaled * ratio;


	//cv::normalize(mSimulatedIma_bgr_unscaled, mSimulatedIma_bgr_final, 0, 255, cv::NORM_MINMAX);
	// just for debugging
	// cv::Mat testBlueIma = mSimulatedIma_blue * ratio;
	// cv::Mat testBlueIma_8UC3;
	// testBlueIma.convertTo(testBlueIma_8UC3, CV_8UC1);
	// Images::showImage("test blue ima 8UC3", testBlueIma_8UC3);
	// float test1 = mSimulatedIma_bgr_unscaled.at<cv::Vec3f>(6, 7)[0];


	mSimulatedIma_bgr_unscaled.convertTo(mSimulatedIma_bgr_final, CV_8UC3);

	// just for debugging
	// int test2 = mSimulatedIma_bgr_final.at<cv::Vec3b>(6, 7)[0];

	// just for debugging
	// Images::showImage("simulated ima", mSimulatedIma_bgr_final);


}

cv::Mat ImageSimulationFunctions::getSimulatedImage()
{
	return mSimulatedIma_bgr_final;
}










void ImageSimulationFunctions::separateTheImageInNtimesMimages_saveThatFct_2()
{
	std::vector <cv::Mat> retrunObjectGrid;

	unsigned int rowObjAda = mAdaptedObj_blue.rows;
	unsigned int colObjAda = mAdaptedObj_blue.cols;

	unsigned int tempStartRow = 0;
	unsigned int separationRow = rowObjAda / mGridFactor;
	unsigned int tempEndRow = separationRow;

	unsigned int tempStartCol = 0;
	unsigned int separationCol = (colObjAda / mGridFactor);
	unsigned int tempEndCol = separationCol;


	unsigned int sizeObjGrid = mGridFactor * mGridFactor;
	mObjectGrid_blue.resize(sizeObjGrid);
	mObjectGrid_green.resize(sizeObjGrid);
	mObjectGrid_red.resize(sizeObjGrid);
	unsigned int counter = 0;

	unsigned int Row_BiggerForConv = 10;
	unsigned int Col_BiggerForConv = 10;

	cv::Mat tempSeparatedObject_blue;
	cv::Mat tempSeparatedObject_green;
	cv::Mat tempSeparatedObject_red;


	tempEndRow = tempEndRow + Col_BiggerForConv;
	tempEndCol = tempEndCol + Row_BiggerForConv;

	for (unsigned int i = 0; i < mGridFactor; ++i)
	{
		for (unsigned int j = 0; j < mGridFactor; ++j)
		{

			if (j == mGridFactor - 1 && i != mGridFactor - 1)
			{
				tempEndCol = tempEndCol - Col_BiggerForConv;
			}

			else if (j == mGridFactor - 1 && i == mGridFactor - 1)
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

			tempStartCol = tempEndCol - Col_BiggerForConv;
			tempEndCol = tempEndCol + separationCol;

		}

		tempStartCol = 0;
		tempEndCol = separationCol + Col_BiggerForConv;

		tempStartRow = tempEndRow - Row_BiggerForConv;
		tempEndRow = tempEndRow + separationRow;

		if (i == mGridFactor - 2)
		{
			tempEndRow = tempEndRow - Row_BiggerForConv;
		}

	}



}

void ImageSimulationFunctions::putImaGridsTogether_saveThatFct_2()
{

	unsigned int rowObjAda = mAdaptedObj_blue.rows;
	unsigned int colObjAda = mAdaptedObj_blue.cols;

	unsigned int tempStartRow = 0;
	unsigned int separationRow = rowObjAda / mGridFactor;
	unsigned int tempEndRow = separationRow;

	unsigned int tempStartCol = 0;
	unsigned int separationCol = (colObjAda / mGridFactor);
	unsigned int tempEndCol = separationCol;


	unsigned int sizeObjGrid = mGridFactor * mGridFactor;

	mSimulatedIma_blue = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_blue[0].type());
	mSimulatedIma_green = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_green[0].type());
	mSimulatedIma_red = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_red[0].type());

	cv::Mat imagePart_blue;
	cv::Mat imagePart_green;
	cv::Mat imagePart_red;

	unsigned int counter = 0;
	// just for debugging
	// std::string counterStr;

	for (unsigned int i = 0; i < mGridFactor; ++i)
	{
		for (unsigned int j = 0; j < mGridFactor; ++j)
		{

			imagePart_blue = mSimulatedImageGrid_blue[counter](cv::Range(0, separationRow), cv::Range(0, separationCol));
			imagePart_blue.copyTo(mSimulatedIma_blue(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol)));
			// just for debugging
			//Images::showImage("blue ima grid", mSimulatedImageGrid_blue[i]);
			//Images::showImage("blue ima", mSimulatedIma_blue);
			//counterStr = std::to_string(counter);
			//Images::saveImage("..", "partBlue" + counterStr, "png", imagePart_blue);

			imagePart_green = mSimulatedImageGrid_green[counter](cv::Range(0, separationRow), cv::Range(0, separationCol));
			imagePart_green.copyTo(mSimulatedIma_green(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol)));

			imagePart_red = mSimulatedImageGrid_red[counter](cv::Range(0, separationRow), cv::Range(0, separationCol));
			imagePart_red.copyTo(mSimulatedIma_red(cv::Range(tempStartRow, tempEndRow), cv::Range(tempStartCol, tempEndCol)));

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

void ImageSimulationFunctions::separateTheImageInNtimesMimages()
{
	std::vector <cv::Mat> retrunObjectGrid;
	unsigned int sampling = mGridFactor - 1;

	unsigned int rowObjAda = mAdaptedObj_blue.rows;
	unsigned int colObjAda = mAdaptedObj_blue.cols;

	unsigned int tempStartRow = 0;
	unsigned int separationRow = rowObjAda / sampling;

	unsigned int tempStartCol = 0;
	unsigned int separationCol = (colObjAda / sampling);



	unsigned int sizeObjGrid = mGridFactor * mGridFactor;
	mObjectGrid_blue.resize(sizeObjGrid);
	mObjectGrid_green.resize(sizeObjGrid);
	mObjectGrid_red.resize(sizeObjGrid);
	unsigned int counter = 0;
	bool first = true;

	cv::Mat tempSeparatedObject_blue;
	cv::Mat tempSeparatedObject_green;
	cv::Mat tempSeparatedObject_red;


	unsigned int tempEndRow = separationRow / 2 + mDefaultParameterImaSim.getColBiggerForConv();
	unsigned int tempEndCol = separationCol / 2 + mDefaultParameterImaSim.getRowBiggerForConv();

	for (unsigned int i = 0; i < mGridFactor; ++i)
	{
		for (unsigned int j = 0; j < mGridFactor; ++j)
		{
			if (j == sampling)
			{
				tempEndCol = tempEndCol - separationRow /2 - mDefaultParameterImaSim.getColBiggerForConv();
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

			tempStartCol = tempEndCol - 2 * mDefaultParameterImaSim.getColBiggerForConv();
			tempEndCol = tempEndCol + separationCol;

		}

		tempStartCol = 0;
		tempEndCol = separationCol / 2 + mDefaultParameterImaSim.getColBiggerForConv();

		tempStartRow = tempEndRow - 2 * mDefaultParameterImaSim.getRowBiggerForConv();
		tempEndRow = tempEndRow + separationRow;

		if (i == sampling - 1)
		{
			tempEndRow = tempEndRow - separationRow / 2 - mDefaultParameterImaSim.getRowBiggerForConv();
		}

	}


}

void ImageSimulationFunctions::separateTheImageInNtimesMimages_saveDoNotUseThat()
{
	std::vector <cv::Mat> retrunObjectGrid;

	unsigned int rowObjAda = mAdaptedObj_blue.rows;
	unsigned int colObjAda = mAdaptedObj_blue.cols;

	unsigned int tempStartRow = 0;
	unsigned int separationRow = rowObjAda / mGridFactor;

	unsigned int tempStartCol = 0;
	unsigned int separationCol = (colObjAda / mGridFactor);



	unsigned int sizeObjGrid = mGridFactor * mGridFactor;
	mObjectGrid_blue.resize(sizeObjGrid);
	mObjectGrid_green.resize(sizeObjGrid);
	mObjectGrid_red.resize(sizeObjGrid);
	unsigned int counter = 0;


	cv::Mat tempSeparatedObject_blue;
	cv::Mat tempSeparatedObject_green;
	cv::Mat tempSeparatedObject_red;

	
	unsigned int tempEndRow = separationRow + mDefaultParameterImaSim.getColBiggerForConv();
	unsigned int tempEndCol = separationCol + mDefaultParameterImaSim.getRowBiggerForConv();

	for (unsigned int i = 0; i < mGridFactor; ++i)
	{
		tempEndRow = tempEndRow + mDefaultParameterImaSim.getColBiggerForConv();
		tempEndCol = tempEndCol + mDefaultParameterImaSim.getRowBiggerForConv();

		for (unsigned int j = 0; j < mGridFactor; ++j)
		{
			if (j == mGridFactor - 1 && i != mGridFactor - 1)
			{
				tempEndCol = tempEndCol - mDefaultParameterImaSim.getColBiggerForConv();
			}

			else if (j == mGridFactor - 1 && i == mGridFactor - 1)
			{
				tempEndCol = tempEndCol - mDefaultParameterImaSim.getColBiggerForConv();
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

			tempStartCol = tempEndCol - 2 * mDefaultParameterImaSim.getColBiggerForConv();
			tempEndCol = tempEndCol + separationCol;

		}

		tempStartCol = 0;
		tempEndCol = separationCol + mDefaultParameterImaSim.getColBiggerForConv();

		tempStartRow = tempEndRow - 2 * mDefaultParameterImaSim.getRowBiggerForConv();
		tempEndRow = tempEndRow + separationRow;

		if (i == mGridFactor - 2)
		{
			tempEndRow = tempEndRow - mDefaultParameterImaSim.getRowBiggerForConv();
		}

	}


}

void ImageSimulationFunctions::putImaGridsTogether()
{
	unsigned int sampling = mGridFactor - 1;
	unsigned int rowObjAda = mAdaptedObj_blue.rows;
	unsigned int colObjAda = mAdaptedObj_blue.cols;

	unsigned int tempStartRow = 0;
	unsigned int separationRow = rowObjAda / sampling;
	unsigned int tempEndRow = separationRow / 2;

	unsigned int tempStartRowInGrid = 0;
	unsigned int tempEndRowInGrid = separationRow / 2;

	unsigned int tempStartCol = 0;
	unsigned int separationCol = colObjAda / sampling;
	unsigned int tempEndCol = separationCol / 2;

	unsigned int tempStartColInGrid = 0;
	unsigned int tempEndColInGrid = separationCol / 2;

	unsigned int sizeObjGrid = mGridFactor * mGridFactor;

	mSimulatedIma_blue = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_blue[0].type());
	mSimulatedIma_green = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_green[0].type());
	mSimulatedIma_red = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_red[0].type());

	cv::Mat imagePart_blue;
	cv::Mat imagePart_green;
	cv::Mat imagePart_red;

	unsigned int counter = 0;
	// just for debugging
	//std::string counterStr;

	for (unsigned int i = 0; i < mGridFactor; ++i)
	{
		for (unsigned int j = 0; j < mGridFactor; ++j)
		{
			if (j == sampling)
			{
				tempEndColInGrid = separationCol / 2 + mDefaultParameterImaSim.getColBiggerForConv();
				tempEndCol = tempEndCol - separationCol / 2;
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

			tempStartColInGrid = mDefaultParameterImaSim.getColBiggerForConv();
			tempEndColInGrid = separationCol + mDefaultParameterImaSim.getColBiggerForConv();

			++counter;

		}

		tempStartColInGrid = 0;
		tempEndColInGrid = separationCol / 2;

		tempStartCol = 0;
		tempEndCol = separationCol / 2;

		tempStartRow = tempEndRow;
		tempEndRow = tempEndRow + separationRow;

		tempStartRowInGrid = mDefaultParameterImaSim.getRowBiggerForConv();;
		tempEndRowInGrid = separationRow  + mDefaultParameterImaSim.getRowBiggerForConv();

		if (i == sampling - 1)
		{
			tempEndRowInGrid = separationRow / 2 + mDefaultParameterImaSim.getRowBiggerForConv();
			tempEndRow = tempEndRow - separationRow / 2;
		}

	}

}

void ImageSimulationFunctions::putImaGridsTogether_save_doNotUseThatFunction()
{
	
	unsigned int rowObjAda = mAdaptedObj_blue.rows;
	unsigned int colObjAda = mAdaptedObj_blue.cols;

	unsigned int tempStartRow = 0;
	unsigned int separationRow = rowObjAda / mGridFactor;
	unsigned int tempEndRow = separationRow;

	unsigned int tempStartRowInGrid = 0;
	unsigned int tempEndRowInGrid = separationRow;

	unsigned int tempStartCol = 0;
	unsigned int separationCol = (colObjAda / mGridFactor);
	unsigned int tempEndCol = separationCol;

	unsigned int tempStartColInGrid = 0;
	unsigned int tempEndColInGrid = separationCol;

	unsigned int sizeObjGrid = mGridFactor * mGridFactor;

	mSimulatedIma_blue = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_blue[0].type());
	mSimulatedIma_green = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_green[0].type());
	mSimulatedIma_red = cv::Mat::zeros(cv::Size(colObjAda, rowObjAda), mSimulatedImageGrid_red[0].type());

	cv::Mat imagePart_blue;
	cv::Mat imagePart_green;
	cv::Mat imagePart_red;

	unsigned int counter = 0;
	// just for debugging
	//std::string counterStr;

	for (unsigned int i = 0; i < mGridFactor; ++i)
	{
		for (unsigned int j = 0; j < mGridFactor; ++j)
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

			tempStartColInGrid = mDefaultParameterImaSim.getColBiggerForConv();
			tempEndColInGrid = separationCol + mDefaultParameterImaSim.getColBiggerForConv();

			++counter;

		}

		tempStartColInGrid = 0;
		tempEndColInGrid = separationCol;

		tempStartCol = 0;
		tempEndCol = separationCol;

		tempStartRow = tempEndRow;
		tempEndRow = tempEndRow + separationRow;

		tempStartRowInGrid = mDefaultParameterImaSim.getRowBiggerForConv();;
		tempEndRowInGrid = separationRow + mDefaultParameterImaSim.getRowBiggerForConv();;

	}

}

// calc points to sampling image 
void ImageSimulationFunctions::calcPointsToSampleObject(/*semi weidth object*/ real semiWeidthObject, /*semi height object*/ real semiHeigtObject, /*sampling*/ unsigned int sampling, /*z pos obejct*/ real zPosObject)
{
	VectorStructR3 startPointRay{};
	startPointRay.setZ(zPosObject);

	// sampling must be an odd number
	if (oftenUse::checkForEvenNumber(sampling))
	{
		sampling = sampling + 1;
	}

	real tempWeidth = semiWeidthObject;
	real tempHeight = semiHeigtObject;
	unsigned int counter = 0;

	unsigned int numPoints = ((real)sampling / 2.0) + 0.5;
	unsigned int j = 0;
	real thicknessWeidgth = semiWeidthObject / (numPoints - 1);
	real thicknessHeight = semiHeigtObject / (numPoints - 1);

	unsigned int size = numPoints * numPoints;
	mObjectPointsSampling.resize(size);
	for (unsigned int i = 0; i < numPoints; ++i)
	{
		for ( j ; j < numPoints ; ++j)
		{
			startPointRay.setX(tempWeidth);
			startPointRay.setY(tempHeight);
			mObjectPointsSampling[counter] = startPointRay;

			tempWeidth = tempWeidth - thicknessWeidgth;
			++counter;

		}

		j = 0;
		tempWeidth = semiWeidthObject;
		tempHeight = tempHeight - thicknessHeight;
		
	}
}

std::vector<VectorStructR3> ImageSimulationFunctions::getPointsToSampleObj()
{
	return mObjectPointsSampling;
}

// the the wavelength for image simulation
void ImageSimulationFunctions::setWavelengthBlue(real waveBlue)
{
	mDefaultParameterImaSim.setWavelengthBlue(waveBlue);
}
void ImageSimulationFunctions::setWavelengthGreen(real waveGreen)
{
	mDefaultParameterImaSim.setWavelengthGreen(waveGreen);
}
void ImageSimulationFunctions::setWavelengthRed(real waveRed)
{
	mDefaultParameterImaSim.setWavelengthRed(waveRed);
}
// ray density
real ImageSimulationFunctions::getRayDensity()
{
	return mDefaultParameterImaSim.getRayDensity();
}
void ImageSimulationFunctions::setRayDensity(unsigned int rayDensity)
{
	mDefaultParameterImaSim.setRayDensity(rayDensity);
}

// light
Light_LLT ImageSimulationFunctions::getLight()
{
	return mDefaultParameterImaSim.getLight();
}
void ImageSimulationFunctions::setLight(Light_LLT light)
{
	mDefaultParameterImaSim.setLight(light);
}
// start refractive index
real ImageSimulationFunctions::getStartRefIndex()
{
	return mDefaultParameterImaSim.getStartRefIndex();
}
void ImageSimulationFunctions::setStartRefIndex(real startRefIndex)
{
	mDefaultParameterImaSim.setStartRefIndex(startRefIndex);
}
// size matrix to save OPD
unsigned int ImageSimulationFunctions::getSizeMatrixToSaveOPD()
{
	return mDefaultParameterImaSim.getSizeMatrixToSaveOPD();
}
void ImageSimulationFunctions::setSizeMatrixToSaveOPD(unsigned int sizeMatrixOPD)
{
	mDefaultParameterImaSim.setSizeMatrixToSaveOPD(sizeMatrixOPD);
}
// inf of obj
void ImageSimulationFunctions::setInfOrObj(objectPoint_inf_obj inf_obj)
{
	mDefaultParameterImaSim.setInfOrObj(inf_obj);
}
objectPoint_inf_obj ImageSimulationFunctions::getInfOrObj()
{
	return mDefaultParameterImaSim.getInfOrObj();
}

void ImageSimulationFunctions::setDefaulParameter(defautParaImaSim defaulParaImaSim)
{
	mDefaultParameterImaSim = defaulParaImaSim;
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
	mOptSysEle.setRefractiveIndexAccordingToWavelength(mDefaultParameterImaSim.getWavelengthBlue());
	mOptSysEle.convertSurfacesToLLT();

	mOptSysLLT_blue = mOptSysEle.getOptSys_LLT_buildSystem();
	mOptSysLLT_blue = mOptSysLLT_blue.clone();
}
void ImageSimulationFunctions::buildOpticalSystemGreen()
{
	mOptSysEle.setRefractiveIndexAccordingToWavelength(mDefaultParameterImaSim.getWavelengthGreen());
	mOptSysEle.convertSurfacesToLLT();

	mOptSysLLT_green = mOptSysEle.getOptSys_LLT_buildSystem();
	mOptSysLLT_green = mOptSysLLT_green.clone();
}
void ImageSimulationFunctions::buildOpticalSystemRed()
{
	mOptSysEle.setRefractiveIndexAccordingToWavelength(mDefaultParameterImaSim.getWavelengthRed());
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
	mPointsInAS = fillAS.fillAS_withPoints(mDefaultParameterImaSim.getRayDensity(), infAS.getPointAS(), infAS.getDirAS(), infAS.getSemiHeightAS());
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
	

	Light_LLT light = mDefaultParameterImaSim.getLight();
	light.setWavelength(mDefaultParameterImaSim.getWavelengthBlue());
	OPD OPD_blue;
	OPD_blue.setOpticalSystemLLT(mOptSysLLT_blue);
	OPD_blue.setInfOrObj(mDefaultParameterImaSim.getInfOrObj());
	OPD_blue.setSizeMatrixToSave(mDefaultParameterImaSim.getSizeMatrixToSaveOPD());
	mOPD_vec_blue.resize(size);

	for (unsigned int i = 0; i < size; ++i)
	{
		tempStartPointRays = mObjectPointsSampling[i];
		// ray aiming
		
		tempAimedLightRays = rayAiming.rayAimingMany_obj_complete(mOptSysLLT_blue, mPointsInAS, tempStartPointRays, light, mDefaultParameterImaSim.getStartRefIndex());
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

	Light_LLT light = mDefaultParameterImaSim.getLight();
	light.setWavelength(mDefaultParameterImaSim.getWavelengthGreen());
	OPD OPD_green;
	OPD_green.setOpticalSystemLLT(mOptSysLLT_green);
	OPD_green.setInfOrObj(mDefaultParameterImaSim.getInfOrObj());
	OPD_green.setSizeMatrixToSave(mDefaultParameterImaSim.getSizeMatrixToSaveOPD());
	mOPD_vec_green.resize(size);

	for (unsigned int i = 0; i < size; ++i)
	{
		tempStartPointRays = mObjectPointsSampling[i];
		// ray aiming

		tempAimedLightRays = rayAiming.rayAimingMany_obj_complete(mOptSysLLT_green, mPointsInAS, tempStartPointRays, light, mDefaultParameterImaSim.getStartRefIndex());
		OPD_green.setAimedLightRays(tempAimedLightRays);
		OPD_green.calcGlobalOPD_new();
		OPD_green.bilinearInterpolToFillHolesInOPDmatrix();

		// save the upsampled OPD
		mOPD_vec_green[i] = OPD_green.getUpsampledGlobalOPD_deepCopy();

	}

	// just for debugging
	//std::string location = "../tests/testImageSimulation/s4";
	//exportAllCalcOPDs_green(location);
}
void ImageSimulationFunctions::calcOPD_red()
{
	VectorStructR3 tempStartPointRays{};
	unsigned int size = mObjectPointsSampling.size();

	RayAiming rayAiming{};
	std::vector<LightRayStruct> tempAimedLightRays{};

	Light_LLT light = mDefaultParameterImaSim.getLight();
	light.setWavelength(mDefaultParameterImaSim.getWavelengthRed());
	OPD OPD_red;
	OPD_red.setOpticalSystemLLT(mOptSysLLT_red);
	OPD_red.setInfOrObj(mDefaultParameterImaSim.getInfOrObj());
	OPD_red.setSizeMatrixToSave(mDefaultParameterImaSim.getSizeMatrixToSaveOPD());
	mOPD_vec_red.resize(size);

	for (unsigned int i = 0; i < size; ++i)
	{
		tempStartPointRays = mObjectPointsSampling[i];
		// ray aiming

		tempAimedLightRays = rayAiming.rayAimingMany_obj_complete(mOptSysLLT_red, mPointsInAS, tempStartPointRays, light, mDefaultParameterImaSim.getStartRefIndex());
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
	mDefaultParameterImaSim.setRowColResizeOPD(rowAndCol);
}
unsigned int ImageSimulationFunctions::getRowAndColResizeOPD()
{
	return mDefaultParameterImaSim.getRowAndColResizeOPD();
}

// scall up all OPDs
void ImageSimulationFunctions::resizeAllOPDs()
{
	unsigned int size = mOPD_vec_blue.size();
	unsigned int row = mDefaultParameterImaSim.getRowAndColResizeOPD();
	unsigned int col = mDefaultParameterImaSim.getRowAndColResizeOPD();

	mOPD_vec_blue_resized.resize(size);
	mOPD_vec_green_resized.resize(size);
	mOPD_vec_red_resized.resize(size);


	for (unsigned int i = 0; i < size; i++)
	{
		cv::resize(mOPD_vec_blue[i], mOPD_vec_blue_resized[i], cv::Size(col, row), cv::INTER_LINEAR);
		cv::resize(mOPD_vec_green[i], mOPD_vec_green_resized[i], cv::Size(col, row), cv::INTER_LINEAR);
		cv::resize(mOPD_vec_red[i], mOPD_vec_red_resized[i], cv::Size(col, row), cv::INTER_LINEAR);
	
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
	
	unsigned int size = mOPD_vec_blue_resized.size();
	mPSF_vec_blue.resize(size);
	for (unsigned int i = 0; i < size; ++i)
	{
		mPSF_vec_blue[i] = PSF_blue.calcPSF_FFT_P_Fct(mOPD_vec_blue_resized[i]);

		// just for debugging
		// Images::showImage_inputReal ("PSF blue", mPSF_vec_blue[i]);
	}
	
}
void ImageSimulationFunctions::calcAllPSF_green()
{
	PSF PSF_green;

	unsigned int size = mOPD_vec_green_resized.size();
	mPSF_vec_green.resize(size);
	for (unsigned int i = 0; i < size; ++i)
	{
		mPSF_vec_green[i] = PSF_green.calcPSF_FFT_P_Fct(mOPD_vec_green_resized[i]);

		// just for debugging
		// Images::showImage_inputReal("PSF green", mPSF_vec_green[i]);
	}
}
void ImageSimulationFunctions::calcAllPSF_red()
{
	PSF PSF_red;

	unsigned int size = mOPD_vec_red_resized.size();
	mPSF_vec_red.resize(size);
	for (unsigned int i = 0; i < size; ++i)
	{
		mPSF_vec_red[i] = PSF_red.calcPSF_FFT_P_Fct(mOPD_vec_red_resized[i]);

		// just for debugging
		// Images::showImage_inputReal("PSF red", mPSF_vec_red[i]);
	}
}

// sample up PSF
void ImageSimulationFunctions::sampleUP_PSFs_horizontal(unsigned int sampling)
{
	unsigned int size = mPSF_vec_blue.size();

	unsigned int samplingHalf = (real)sampling / 2.0 - 0.5;
	unsigned int newSize = (samplingHalf + 1) * (samplingHalf * 2 + 1);
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
			if (fillingCounter >= samplingHalf)
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

void ImageSimulationFunctions::sampleUP_PSFs_vertical(unsigned int sampling)
{
	unsigned int samplingHalf = (real)sampling / 2.0 - 0.5;
	unsigned int PSFsInOneRow = sampling;
	unsigned int newTotalSize = sampling * sampling;

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
void ImageSimulationFunctions::calcAllPSFsForConv_Q1(unsigned int sampling)
{

	unsigned int size = mPSF_vec_blue_sampledUp_horizontal.size();
	unsigned int newSize = sampling * (sampling + sampling - 1);
	unsigned int totalSize = newSize + newSize - (sampling + sampling - 1);
	mAllPSFForConv_blue.resize(totalSize);
	mAllPSFForConv_green.resize(totalSize);
	mAllPSFForConv_red.resize(totalSize);

	unsigned int posIOriginPSF = 0;
	unsigned int roundCounter = 1;

	for (unsigned int i = 0; i < newSize; ++i)
	{
		for(unsigned int j=0;j< sampling -1; ++j)
		{
			
			mAllPSFForConv_blue[i] = flipMatrixVertical(mPSF_vec_blue_sampledUp_vertical[posIOriginPSF]);
			++posIOriginPSF;
			++i;
		}

		posIOriginPSF = sampling * roundCounter - 1;
		mAllPSFForConv_blue[i] = (mPSF_vec_blue_sampledUp_vertical[posIOriginPSF]);
		
		for (unsigned int k = 0; k < sampling - 1; ++k)
		{
			
			++i;
			--posIOriginPSF;
			mAllPSFForConv_blue[i] = mPSF_vec_blue_sampledUp_vertical[posIOriginPSF];
			
		}
		posIOriginPSF = sampling * roundCounter;
		++roundCounter;
	}

}

void ImageSimulationFunctions::calcAllPSFsForConv_Q2andQ3(unsigned int sampling)
{
	unsigned sampPlusSampMinOne = (sampling + sampling - 1);
	unsigned int newSize = sampling * sampPlusSampMinOne;
	unsigned int posInTotalVec = newSize;
	int posInOldVec = newSize - (sampling + sampling - 1) * 2;
	unsigned int roundCounter = 2;

	bool checker = true;
	while (checker)
	{
		for (unsigned int i = 0; i < sampPlusSampMinOne; ++i)
		{
			mAllPSFForConv_blue[posInTotalVec] = flipMatrixHorizontal(mAllPSFForConv_blue[posInOldVec]);
			++posInTotalVec;
			++posInOldVec;

			
		}

		++roundCounter;
		posInOldVec = newSize - sampPlusSampMinOne * roundCounter;
		
		// just for debugging 
		//std::cout << "pos in old vector: " << posInOldVec << std::endl;

		if (roundCounter > sampling)
		{
			checker = false;
		}
	}

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