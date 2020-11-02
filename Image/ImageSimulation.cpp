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
	separateTheImageInNtimesMimages_final();
	// convolute the 
	convoluteObjectGridWithPSF();
	// put the image grids together
	//putImaGridsTogether();
	//putImaGridsTogether_saveThatFct();
	putImaGridsTogether_final();
	// filling black strips
	//fillingBlackStrips();
	// put all channles together, scale the image and save the image as CV_8UC 
	putAllChannlesTogetherScaleAndSaveIma();


}

void ImageSimulationFunctions::setPixBiggerForConvolution_Row(unsigned int pixBiggerRow)
{
	mRow_BiggerForConv = pixBiggerRow;
}
void ImageSimulationFunctions::setPixBiggerForConvolution_Col(unsigned int pixBiggerCol)
{
	mCol_BiggerForConv = pixBiggerCol;
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
		mObjectGrid_blue[i].convertTo(convertedObject_blue, CV_32F);
		mSimulatedImageGrid_blue[i] = convolution(convertedObject_blue, mLoadedPSFs_vec_blue[i]);
		//mSimulatedImageGrid_blue[i] = convolution(mObjectGrid_blue[i], mLoadedPSFs_vec_blue[i]);
		// just for debugging
		// Images::showImage("grid ima blue", mObjectGrid_blue[i]);
		// counterStr = std::to_string(i);
		// Images::saveImage("..", "convolutedBlue" + counterStr, "png", mSimulatedImageGrid_blue[i]);

		// green
		mObjectGrid_green[i].convertTo(convertedObject_green, CV_32F);
		mSimulatedImageGrid_green[i] = convolution(convertedObject_green, mLoadedPSFs_vec_green[i]);

		// red
		mObjectGrid_red[i].convertTo(convertedObject_red, CV_32F);
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

std::vector<std::vector<cv::Mat>> ImageSimulationFunctions::getObjGrid()
{
	return ObjectGridsMatrix;
}

void ImageSimulationFunctions::plotAllObjektGrids(std::vector<cv::Mat> objGrid_vec)
{
	
	unsigned sizeGrid = objGrid_vec.size();
	std::string tempString{};

	for (unsigned int i = 0; i < sizeGrid; ++i)
	{
		tempString = std::to_string(i);
		Images::showImage(tempString, objGrid_vec[i]);
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


	// just for debugging
	//Images::showImage("simulated ima blue", mSimulatedIma_blue);
	//Images::showImage("simulated ima green", mSimulatedIma_green);
	//Images::showImage("simulated ima red", mSimulatedIma_red);
   

	cv::merge(array_to_merge, mSimulatedIma_bgr_unscaled);
	// just for debugging
	//Images::showImage("simulated ima bgr", mSimulatedIma_bgr_unscaled);

	real min{};
	real max{};
	cv::minMaxLoc(mSimulatedIma_bgr_unscaled, &min, &max);

	double ratio = 255.0 / max;
	mSimulatedIma_bgr_unscaled = mSimulatedIma_bgr_unscaled * ratio;

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

void ImageSimulationFunctions::separateTheImageInNtimesMimages_final()
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

	
	tempEndRow = tempEndRow + mCol_BiggerForConv;
	tempEndCol = tempEndCol + mRow_BiggerForConv;

	for (unsigned int i = 0; i < mGridFactor; ++i)
	{
		for (unsigned int j = 0; j < mGridFactor; ++j)
		{

			if (j == mGridFactor - 1 && i != mGridFactor - 1)
			{
				tempEndCol = tempEndCol - mCol_BiggerForConv;
			}

			else if (j == mGridFactor - 1 && i == mGridFactor - 1)
			{
				tempEndCol = tempEndCol - mCol_BiggerForConv;
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

			tempStartCol = tempEndCol - 2 * mCol_BiggerForConv;
			tempEndCol = tempEndCol + separationCol;

		}

		tempStartCol = 0;
		tempEndCol = separationCol + mCol_BiggerForConv;

		tempStartRow = tempEndRow - 2 * mRow_BiggerForConv;
		tempEndRow = tempEndRow + separationRow;

		if (i == mGridFactor - 2)
		{
			tempEndRow = tempEndRow - mRow_BiggerForConv;
		}

	}


}

void ImageSimulationFunctions::putImaGridsTogether_final()
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

			tempStartColInGrid = mCol_BiggerForConv;
			tempEndColInGrid = separationCol + 10;

			++counter;

		}

		tempStartColInGrid = 0;
		tempEndColInGrid = separationCol;

		tempStartCol = 0;
		tempEndCol = separationCol;

		tempStartRow = tempEndRow;
		tempEndRow = tempEndRow + separationRow;

		tempStartRowInGrid = mRow_BiggerForConv;
		tempEndRowInGrid = separationRow + mRow_BiggerForConv;

	}

}