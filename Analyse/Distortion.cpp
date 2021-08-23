#include "Distortion.h"

// ray aiming
#include "..\RayAiming\RayAiming.h"
// cardinal points
#include "..\Analyse\CardinalPoints.h"
// often use namespace
#include "..\oftenUseNamespace\oftenUseNamespace.h"
// important structs
#include "..\LowLevelTracing\ImportantStructures.h"
// inport export data
#include "..\Inport_Export_Data\Inport_Export_Data.h"
// images
#include "..\Image\Images.h"

loadParameterDistortion::loadParameterDistortion() {};
loadParameterDistortion::~loadParameterDistortion() {};

//DistortionXandY::DistortionXandY() {};
//DistortionXandY::~DistortionXandY() {};
//
//DistortionXandY::DistortionXandY(real disX, real disY) :
//	mDistortionX(disX),
//	mDistortionY(disY)
//{}
//
//// X
//real DistortionXandY::getDistortionX()
//{
//	return mDistortionX;
//}
//void DistortionXandY::setDistortionX(real disX)
//{
//	mDistortionX = disX;
//}
//
//// Y
//real DistortionXandY::getDistrotionY()
//{
//	return mDistortionY;
//}
//void DistortionXandY::setDistortionY(real disY)
//{
//	mDistortionY = disY;
//}

Distortion::Distortion() {};
Distortion::~Distortion() {};

void Distortion::calcDistortedIma(cv::Mat& inputImam, cv::Mat& distortedIma, cv::Mat mapX, cv::Mat& mapY)
{
	cv::remap(inputImam, distortedIma, mapX, mapY, cv::INTER_LANCZOS4, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));
}

real Distortion::calcDistortion_obj(OpticalSystem_LLT optSys_LLT, VectorStructR3 startPoint, Light_LLT light)
{
	real tolerance = 0.00001;

	RayAiming rayAiming;
	VectorStructR3 pointAperStop = optSys_LLT.getInforAS().getPointAS();
	std::vector<VectorStructR3> pointAS_vec = { pointAperStop };
	std::vector<LightRayStruct> aimedLightRay = rayAiming.rayAimingMany_obj_complete(optSys_LLT, pointAS_vec, startPoint, light);



	SequentialRayTracing seqTrace(optSys_LLT);
	seqTrace.sequentialRayTracing(aimedLightRay[0]);

	unsigned int posLastSurface = optSys_LLT.getPosAndInteractingSurface().size() - 1;

	VectorStructR3 interPointLastSurface = seqTrace.getAllInterPointsAtSurface_i_filtered(posLastSurface)[0];

	real chiefRay_X = interPointLastSurface.getX();
	real chiefRay_Y = interPointLastSurface.getY();

	// calculate magnification
	real smallStartPointY = 0.0001;
	SequentialRayTracing seqTraceMagnification(optSys_LLT);
	VectorStructR3 startPointMagnification;
	startPointMagnification.setZ(startPoint.getZ());
	startPointMagnification.setY(smallStartPointY);
	startPointMagnification.setX(0.0);
	std::vector<LightRayStruct> aimedLightRayMagnification = rayAiming.rayAimingMany_obj_complete(optSys_LLT, pointAS_vec, startPointMagnification, light);
	seqTraceMagnification.sequentialRayTracing(aimedLightRayMagnification[0]);
	real interPointLastSurface_Y = seqTraceMagnification.getAllInterPointsAtSurface_i_filtered(posLastSurface)[0].getY();

	real magnification = interPointLastSurface_Y / smallStartPointY;

	real refX = startPoint.getX() * magnification;
	real refY = startPoint.getY() * magnification;

	real distortion;
	if (std::abs(refY) > tolerance)
	{
		distortion = 100.0 * (chiefRay_Y - refY) / refY;
	}
	else if (std::abs(refX) > tolerance)
	{
		distortion = 100.0 * (chiefRay_X - refX) / refX;
	}
	else // refX and ref Y are zero
	{
		distortion = 0.0;
	}

	return distortion;

}

void Distortion::calculateDistortion_superFunction_obj(/*image*/cv::Mat& image,/*optical system LLT*/ OpticalSystem_LLT optSys_LLT,/*lght*/ Light_LLT light,/*sampling height*/ unsigned int samplingHeight,/*sampling width*/ unsigned int samplingWidth,/*hight object*/ real heightObject,/*width object*/ real widthObject,/*start point Z*/ real startPointZ)
{
	// save in private
	mImage = image;
	mOpticalSystem_LLT = optSys_LLT;
	mLight = light;
	mSamplingHeight = samplingHeight;
	mSamplingWidth = samplingWidth;
	mStartPointZ = startPointZ;
	mHeightObject = heightObject;
	mWidthObject = widthObject;
	mPixelImage_Height = mImage.size().height;
	mPixelImage_Width = mImage.size().width;


	// calculate distortion map
	calculateDistortionMap();

	// calculate distortion using cv::remap
	calculateDistortedImageUsingRemap();

}

void Distortion::calculateDistortionMap()
{
	
	float toleraceForZero = 0.00001;

	float samplingHeightHalf = mSamplingHeight / 2.0;
	float samplingWidthHalf = mSamplingWidth / 2.0;
	float semiPixelHeightIma = (float)(mPixelImage_Height - 1) / 2.0;
	float semiPixelWidthIma = (float)(mPixelImage_Width - 1) / 2.0;
	float semiHeightHalf = mHeightObject / 2.0;
	float semiWidthHalf = mWidthObject / 2.0;

	

	unsigned int posY_inDisMap_Q0 = semiPixelHeightIma / samplingHeightHalf;
	unsigned int poxX_inDisMap_Q0 = 0.0;

	float deltaPoint_X = semiWidthHalf / (samplingWidthHalf - 1.0);
	float deltaPoint_Y = semiHeightHalf / (samplingHeightHalf - 1.0);


	// calculate points to trace
	std::vector<VectorStructR3> pointsToTrace;
	pointsToTrace.resize((int)samplingHeightHalf * (int)samplingWidthHalf);
	VectorStructR3 tempPoint;
	tempPoint.setZ(mStartPointZ);
	float tempX = 0.0;
	float tempY = 0.0;
	unsigned int counterPoints = 0;
	for (unsigned int y = 0; y < (int)samplingHeightHalf; ++y)
	{
		for (unsigned int x = 0; x < (int)samplingWidthHalf; ++x)
		{
			tempPoint.setX(tempX);
			tempPoint.setY(tempY);
			pointsToTrace[counterPoints] = tempPoint;
			tempX = tempX + deltaPoint_X;
			tempPoint.setX(tempX);
			
			//// just for debugging
			//if (x == (int)samplingWidthHalf - 1)
			//{
			//	int affe;
			//	affe = 1;
			//}
			//Math::print(tempPoint);

			++counterPoints;
		}

		tempY = tempY + deltaPoint_Y;
		tempPoint.setY(tempY);

		tempX = 0.0;
	}


	// trace all the chief rays
	SequentialRayTracing seqTrace_chiefRays(mOpticalSystem_LLT);
	RayAiming rayAiming(mOpticalSystem_LLT);
	rayAiming.setGlobalStop(false);
	rayAiming.setTolerancceForRealLightRay(10.0);

	VectorStructR3 pointAperStop = mOpticalSystem_LLT.getInforAS().getPointAS();
	std::vector<LightRayStruct> lightRaysToTrace;
	lightRaysToTrace.resize(pointsToTrace.size());
	mStartRefIndex = oftenUse::getStartRefIndex(mOpticalSystem_LLT);
	for (unsigned int j = 0; j < pointsToTrace.size(); j++)
	{
		lightRaysToTrace[j] = rayAiming.rayAiming_obj(pointsToTrace[j], pointAperStop, mLight, mStartRefIndex);
	}

	seqTrace_chiefRays.seqRayTracingWithVectorOfLightRays(lightRaysToTrace);
	unsigned int posLastSurface = mOpticalSystem_LLT.getPosAndInteractingSurface().size() - 1;
	std::vector<VectorStructR3> interPointsLastSurface = seqTrace_chiefRays.getAllInterPointsAtSurf_i_notFiltered(posLastSurface);

	// calculate magnification using ray tracing
	calculateMagnificationUsingRayTracing();

	// filling distortion map Q0
	unsigned int tempPosPixel_X = 0;
	unsigned int tempPosPixel_Y = semiPixelHeightIma;
	float deltaPixel_X = semiPixelWidthIma / (samplingWidthHalf - 1.0);
	float deltaPixel_Y = semiPixelHeightIma / (samplingHeightHalf - 1.0);

	mDistortionMap_Q0 = cv::Mat::zeros(cv::Size(semiPixelWidthIma + 1, semiPixelHeightIma + 1), CV_32F);
	
	VectorStructR3 tempPointChiefRay{};
	float tempDistortion{};
	float tempRefY{};
	float tempRefX{};
	unsigned int counter = 0;
	unsigned int maxCounter = interPointsLastSurface.size();
	float toleranceForValidDistortion = 100.0;
	unsigned int noValidDistortionCounter = 0;
	for (int y = 0; y < (int)samplingHeightHalf; ++y)
	{
		for (unsigned int x = 0; x < (int)samplingWidthHalf; ++x)
		{
			// just for debugging
			// std::cout << "counter: " << counter << std::endl;

			tempPointChiefRay = interPointsLastSurface.at(counter);
			tempRefY = pointsToTrace[counter].getY() * mMagnificationUsingRayTracing;
			tempRefX = pointsToTrace[counter].getX() * mMagnificationUsingRayTracing;
			if (std::abs(tempRefY) > toleraceForZero)
			{
				tempDistortion = 100.0 * (tempPointChiefRay.getY() - tempRefY) / tempRefY;
			}

			else if (std::abs(tempRefX) > toleraceForZero)
			{
					tempDistortion = 100.0 * (tempPointChiefRay.getX() - tempRefX) / tempRefX;
			}
			else // refX and ref Y are zero
			{
				tempDistortion = 0.0;
			}

			if (x == (int)samplingWidthHalf - 1)
			{
				tempPosPixel_X = semiPixelWidthIma;
				
			}
			else
			{
				tempPosPixel_X = x * deltaPixel_X;
				
			}

			//// just for debugging
			//std::cout << "tempRefX: " << tempRefX << std::endl;
			//std::cout << "tempRefY: " << tempRefY << std::endl;
			//std::cout << "tempPointChiefRay.getX(): " << tempPointChiefRay.getX() << std::endl;
			//std::cout << "tempPointChiefRay.getY(): " << tempPointChiefRay.getY() << std::endl;
			//std::cout << "temp pos pixel x: " << tempPosPixel_X << std::endl;
			//std::cout << "temp pos pixel y: " << tempPosPixel_Y << std::endl;
			//std::cout << "temp distortion: " << tempDistortion << std::endl;
			//std::cout << "" << std::endl;

			if (std::abs(tempDistortion) < toleranceForValidDistortion)
			{
				mDistortionMap_Q0.at<float>(tempPosPixel_Y, tempPosPixel_X) = tempDistortion;
			}
			
			else // no valid disortion
			{
				++noValidDistortionCounter;
			}

			++counter;

			if (counter > maxCounter - 1)
			{
				y = samplingHeightHalf + 100;
				x = samplingWidthHalf + 100;
			}
		}

		tempPosPixel_X = 0;

		if (y == (int)samplingHeightHalf - 2)
		{
			tempPosPixel_Y = 0;
			
		}
		else
		{
			tempPosPixel_Y = semiPixelHeightIma - deltaPixel_Y - y * deltaPixel_Y;
		}

		// just for debugging
		// std::cout << "temp pos pixel y: " << tempPosPixel_Y << std::endl;
	

	}

	// upsample matrix von Q0
	bilinearInterpolToFillHolesInDistortionMap_Q0();

	// debug
	//std::string location = "../tests/testDistortion/s4";
	//inportExportData::exportCV_MatToExcel(mDistortionMap_Q0_upsampled, location, "disMap_Q0_upsampled");

	// calculate distortion map Q1 by flipping Q0 vertical
	cv::Rect ROI_Q1(1, 0, mDistortionMap_Q0_upsampled.size().width - 1, mDistortionMap_Q0_upsampled.size().height);
	cv::Mat tempQ1 = mDistortionMap_Q0_upsampled(ROI_Q1);
	cv::flip(tempQ1, mDistortionMap_Q1, 1); // 1 --> flip vertical
	
	// putting Q0 and Q1 in one matrix
	int widthQ0 = mDistortionMap_Q0_upsampled.size().width;
	int heightQ0 = mDistortionMap_Q0_upsampled.size().height;
	int widthQ1 = mDistortionMap_Q1.size().width;
	int heightQ1 = mDistortionMap_Q1.size().height;
	
	int widthQ0_Q1 = widthQ0 + widthQ1;


	mDistortionMap_Q0_Q1 = cv::Mat::zeros({ widthQ0_Q1 , heightQ1 }, mDistortionMap_Q0_upsampled.type());

	mDistortionMap_Q1.copyTo(mDistortionMap_Q0_Q1(cv::Range(0, heightQ1), cv::Range(0, widthQ1)));
	mDistortionMap_Q0_upsampled.copyTo(mDistortionMap_Q0_Q1(cv::Range(0, heightQ1), cv::Range(widthQ1, widthQ0_Q1)));

	// calculate distortion for Q2 and Q3 by flipping Q0_Q1 horizontal
	cv::Rect ROI_Q23(0, 0, mDistortionMap_Q0_Q1.size().width, mDistortionMap_Q0_Q1.size().height - 1);
	cv::Mat tempQ23 = mDistortionMap_Q0_Q1(ROI_Q23);
	cv::flip(tempQ23, mDistortionMap_Q2_Q3, 0); // 0 --> flip horizontal

	// building total distortion map
	int widthQ2Q3 = widthQ0_Q1;
	int height_total = heightQ1 + heightQ1 - 1;

	mDistortionMap_Total = cv::Mat::zeros({ widthQ2Q3 , height_total }, mDistortionMap_Q0_upsampled.type());
	mDistortionMap_Q0_Q1.copyTo(mDistortionMap_Total(cv::Range(0, heightQ1), cv::Range(0, widthQ2Q3)));
	mDistortionMap_Q2_Q3.copyTo(mDistortionMap_Total(cv::Range(heightQ1, height_total), cv::Range(0, widthQ2Q3)));


	// check for barrel or pincushion distortion
	unsigned int posX = widthQ0 / 2;
	unsigned int posY = heightQ0 / 2;
	bool checker = true;
	mDecissionValue = mDistortionMap_Total.at<float>(posY, posX);


	// debug
	// std::cout << "val: " << decissionValue << std::endl;
	unsigned counterChangeVal = 0;
	unsigned maxCounterChangeVal = 5;
	while (checker)
	{
		if (mDecissionValue < 0) // barrel distortion 
		{
			calculateBarrelDistortion();
			checker = false;
		}
		else if (mDecissionValue > 0) // pincushion distortion
		{
			calcPincushionDistortion();
			checker = false;
		}
		else
		{
			++posY;
			++posX;
			mDecissionValue = mDistortionMap_Total.at<float>(posY, posX);
			++counterChangeVal;

			if (counterChangeVal > maxCounterChangeVal)
			{
				checker = false;
				oftenUse::errorProtocol_stopSystem("check distortion calculation", "Distortion.cpp", 0, true);
			}
		}

	}


		


	

}

void Distortion::calculateBarrelDistortion()
{
	float toleraceForZero = 0.00001;

	int widthQ2Q3 = mDistortionMap_Total.size().width;

	int height_total = mDistortionMap_Total.size().height;

	float R{};
	float newR{};
	int deltaX{};
	int deltaY{};
	int middleX = mDistortionMap_Total.cols / 2;
	int middleY = mDistortionMap_Total.rows / 2;
	float newPixel_X{};
	float newPixel_Y{};
	
	// calculate new coorinates for distorted images
	mMapX_forRemap = cv::Mat::ones({ widthQ2Q3 , height_total }, mDistortionMap_Total.type());
	mMapX_forRemap = -100.0 * mMapX_forRemap;
	mMapY_forRemap = cv::Mat::ones({ widthQ2Q3 , height_total }, mDistortionMap_Total.type());
	mMapY_forRemap = -100.0 * mMapY_forRemap;

	// calculate cordinates to correct distortion
	mMapX_forRemap_CorrectDistortion = cv::Mat::ones({ widthQ2Q3 , height_total }, mDistortionMap_Total.type());
	mMapX_forRemap_CorrectDistortion = -100.0 * mMapX_forRemap_CorrectDistortion;
	mMapY_forRemap_CorrectDistortion = cv::Mat::ones({ widthQ2Q3 , height_total }, mDistortionMap_Total.type());
	mMapY_forRemap_CorrectDistortion = -100.0 * mMapY_forRemap_CorrectDistortion;

	float tempDistortionPercent{};
	//int coubter = 0;
	//int i = 0;

	for (unsigned int posY_pix = 0; posY_pix < height_total; ++posY_pix)
	{
		for (unsigned int posX_pix = 0; posX_pix < widthQ2Q3; ++posX_pix)
		{
			deltaX = middleX - posX_pix;
			deltaY = middleY - posY_pix;
			R = std::sqrt(float(std::pow(deltaX, 2) + std::pow(deltaY, 2)));

			tempDistortionPercent = mDistortionMap_Total.at<float>(posY_pix, posX_pix);

			if (R < toleraceForZero)
			{
				R = toleraceForZero;
			}
			if (std::abs(tempDistortionPercent) < toleraceForZero)
			{
				tempDistortionPercent = toleraceForZero;
			}

			newR = (100.0 + tempDistortionPercent) * R / 100.0;

			//// debugging
			//std::cout << "R: " << R << std::endl;
			//std::cout << "temp distortion: " << tempDistortionPercent << std::endl;

			newPixel_X = middleX - newR * deltaX / R;
			newPixel_Y = middleY - newR * deltaY / R;

			//newPixel_X = middleX - (100.0 + tempDistortionPercent) * (middleX - posX_pix) / 100;
			//newPixel_Y = middleY - (100.0 + tempDistortionPercent) * (middleY - posY_pix) / 100;



			// debug
			//std::cout << "newX" << newPixel_X << std::endl;

			// just for debugging
			// std::cout << counter << std::endl;
			//if (counter == 20303)
			//{				
			//	i = 5;
			//}


			mMapX_forRemap.at<float>(newPixel_Y, newPixel_X) = posX_pix;
			mMapY_forRemap.at<float>(newPixel_Y, newPixel_X) = posY_pix;

			mMapX_forRemap_CorrectDistortion.at<float>(posY_pix, posX_pix) = newPixel_X;
			mMapY_forRemap_CorrectDistortion.at<float>(posY_pix, posX_pix) = newPixel_Y;
		
		}

	}


}


void Distortion::calcPincushionDistortion()
{
	float toleraceForZero = 0.00001;

	int widthQ2Q3 = mDistortionMap_Total.size().width;

	int height_total = mDistortionMap_Total.size().height;

	float R{};
	float newR{};
	int deltaX{};
	int deltaY{};
	int middleX = mDistortionMap_Total.cols / 2;
	int middleY = mDistortionMap_Total.rows / 2;
	float newPixel_X{};
	float newPixel_Y{};


	float maxDistortion = mDistortionMap_Total.at<float>(0, widthQ2Q3 - 1);
	R = std::sqrt(float(std::pow(middleX, 2) + std::pow(middleY, 2)));
	newR = (100.0 + maxDistortion) * R / 100.0;
	newPixel_X = middleX - newR * middleX / R;
	newPixel_Y = middleY - newR * middleY / R;

	// debugging
	std::cout << "R: " << R << std::endl;
	std::cout << "newR: " << newR << std::endl;
	std::cout << "newPixel_X: " << newPixel_X << std::endl;
	std::cout << "newPixel_Y: " << newPixel_Y << std::endl;


	

	float tempDistortionPercent{};
	//int coubter = 0;
	//int i = 0;

	real min;
	real max;
	cv::Point locMin, locMax;

	cv::minMaxLoc(mDistortionMap_Total, &min, &max, &locMin, &locMax);
	float deltaX_forMaxCalc = middleX - locMax.x;
	float deltaY_forMaxCalc = middleY - locMax.y;

	float maxVal = std::sqrt(float(std::pow(deltaX_forMaxCalc, 2) + std::pow(deltaY_forMaxCalc, 2)));
	float maxNewRval = (100.0 + mDistortionMap_Total.at<float>(locMax.y, locMax.x)) * maxVal / 100.0;
	float newPixel_X_max = middleX - maxNewRval * deltaX_forMaxCalc / maxVal;
	float newPixel_Y_max = middleY - maxNewRval * deltaY_forMaxCalc / maxVal;

	unsigned int pixelErrorCounter = 0;

	int twoTime_newPixel_Y_max = 2.0 * std::abs(newPixel_Y_max);
	int twoTime_newPixel_X_max = 2.0 * std::abs(newPixel_X_max);

	// calculate new coorinates for distorted images
	mMapX_forRemap = cv::Mat::zeros({ widthQ2Q3 + twoTime_newPixel_X_max, height_total + twoTime_newPixel_Y_max }, mDistortionMap_Total.type());
	mMapX_forRemap_CorrectDistortion = cv::Mat::zeros({ widthQ2Q3 + twoTime_newPixel_X_max, height_total + twoTime_newPixel_Y_max }, mDistortionMap_Total.type());
	//mMapX_forRemap = -1.0 * mMapX_forRemap;
	// debug 
	//std::string location = "../tests/testDistortion/s4";
	//inportExportData::exportCV_MatToExcel(mMapX_forRemap, location, "mMapX_forRemap");

	mMapY_forRemap = cv::Mat::zeros({ widthQ2Q3 + twoTime_newPixel_X_max ,  height_total + twoTime_newPixel_Y_max }, mDistortionMap_Total.type());
	mMapY_forRemap_CorrectDistortion = cv::Mat::zeros({ widthQ2Q3 + twoTime_newPixel_X_max ,  height_total + twoTime_newPixel_Y_max }, mDistortionMap_Total.type());
	//mMapY_forRemap = -1.0 * mMapY_forRemap;

	int new_middleX = (widthQ2Q3 + twoTime_newPixel_X_max) / 2;
	int new_middleY = (height_total + twoTime_newPixel_Y_max) / 2;

	float minNewPix_X = 0.0;
	float minNewPix_Y = 0.0;
	float maxNewPix_X = widthQ2Q3 + twoTime_newPixel_X_max;
	float maxNewPix_Y = height_total + twoTime_newPixel_Y_max;

	for (unsigned int posY_pix = 0; posY_pix < height_total; ++posY_pix)
	{
		for (unsigned int posX_pix = 0; posX_pix < widthQ2Q3; ++posX_pix)
		{
			deltaX = middleX - posX_pix;
			deltaY = middleY - posY_pix;
			R = std::sqrt(float(std::pow(deltaX, 2) + std::pow(deltaY, 2)));

			tempDistortionPercent = mDistortionMap_Total.at<float>(posY_pix, posX_pix);

			if (R < toleraceForZero)
			{
				R = toleraceForZero;
			}
			if (tempDistortionPercent < toleraceForZero)
			{
				tempDistortionPercent = toleraceForZero;
			}

			newR = (100.0 + tempDistortionPercent) * R / 100.0;
			//newR = newR / maxNewRval * newR;


			newPixel_X = new_middleX - newR * deltaX / R;
			newPixel_Y = new_middleY - newR * deltaY / R;
			
			//// debugging
			//std::cout << "R: " << R << std::endl;
			//std::cout << "temp distortion: " << tempDistortionPercent << std::endl;
			//std::cout << "newPixel_X: " << newPixel_X << std::endl;
			//std::cout << "newPixel_Y: " << newPixel_Y << std::endl;
			

			// just for debugging
			// std::cout << counter << std::endl;
			//if (counter == 20303)
			//{				
			//	i = 5;
			//}

			if(newPixel_X >= minNewPix_X && newPixel_X < maxNewPix_X && newPixel_Y >= minNewPix_Y && newPixel_Y < maxNewPix_Y)
			{
			
			newPixel_X = (int)newPixel_X;	
			newPixel_Y = (int)newPixel_Y;
			
			mMapX_forRemap.at<float>(newPixel_Y, newPixel_X) = posX_pix;
			mMapY_forRemap.at<float>(newPixel_Y, newPixel_X) = posY_pix;

			mMapX_forRemap_CorrectDistortion.at<float>(posY_pix, posX_pix) = newPixel_X;
			mMapY_forRemap_CorrectDistortion.at<float>(posY_pix, posX_pix) = newPixel_Y;
			}
			else
			{
				++pixelErrorCounter;
			}


		}

	}

	//mExandetImaToCorrectDistortion = cv::Mat::zeros({ mMapX_forRemap.cols ,  mMapX_forRemap.rows }, mImage.type());
	////exandetIma = 255 * exandetIma;
	//int xStart = (mMapX_forRemap.cols - mImage.cols) / 2;
	//int yStart = (mMapY_forRemap.rows - mImage.rows) / 2;
	//mImage.copyTo(mExandetImaToCorrectDistortion(cv::Range(yStart, mImage.rows + yStart), cv::Range(xStart, mImage.cols+ xStart)));
	//
	//// debug
	//Images::showImage_inputUint8("extended image", mExandetImaToCorrectDistortion);

	// get ROI
	mROI.x = std::abs(newPixel_X_max);
	mROI.y = std::abs(newPixel_Y_max);
	mROI.width = widthQ2Q3;
	mROI.height = height_total;

	
	//(std::abs(newPixel_X_max), std::abs(newPixel_Y_max) , widthQ2Q3, height_total);
	//mMapX_forRemap = mMapX_forRemap(ROI);
	//mMapY_forRemap = mMapY_forRemap(ROI);
	//mMapX_forRemap_CorrectDistortion = mMapX_forRemap_CorrectDistortion(ROI);
	//mMapY_forRemap_CorrectDistortion = mMapY_forRemap_CorrectDistortion(ROI);

	bilinearInterpolToFillHolesInDistortionMap_RemapX();
	bilinearInterpolToFillHolesInDistortionMap_RemapY();

	//// debug
	//std::string location = "../tests/testDistortion/s4";
	//inportExportData::exportCV_MatToExcel(mMapX_forRemap, location, "mMapX_forRemap");
	//inportExportData::exportCV_MatToExcel(mMapX_forRemap_upsampled, location, "mMapX_forRemap_upsampled");
	//inportExportData::exportCV_MatToExcel(mMapY_forRemap, location, "mMapY_forRemap");
	//inportExportData::exportCV_MatToExcel(mMapY_forRemap_upsampled, location, "mMapY_forRemap_upsampled");
}

void  Distortion::calculateMagnificationUsingRayTracing()
{
	// calculate magnification
	real smallStartPointY = 0.0001;
	SequentialRayTracing seqTraceMagnification(mOpticalSystem_LLT);
	VectorStructR3 startPointMagnification;
	startPointMagnification.setZ(mStartPointZ);
	startPointMagnification.setY(smallStartPointY);
	startPointMagnification.setX(0.0);
	RayAiming rayAiming(mOpticalSystem_LLT);
	VectorStructR3 pointAperStop = mOpticalSystem_LLT.getInforAS().getPointAS();
	LightRayStruct aimedLightRayMagnification = rayAiming.rayAiming_obj(startPointMagnification, pointAperStop, mLight, mStartRefIndex);
	seqTraceMagnification.sequentialRayTracing(aimedLightRayMagnification);
	unsigned int posLastSurface = mOpticalSystem_LLT.getPosAndInteractingSurface().size() - 1;
	real interPointLastSurface_Y = seqTraceMagnification.getAllInterPointsAtSurface_i_filtered(posLastSurface)[0].getY();

	mMagnificationUsingRayTracing = interPointLastSurface_Y / smallStartPointY;
}

// bilinear interpolation to fill holes in OPD matrix
void Distortion::bilinearInterpolToFillHolesInDistortionMap_Q0()
{
	mMaxIterationBilinInterpol = 3;
	mToleranceToCheckZero = 0.0000000001;
	mDistortionMap_Q0_upsampled = mDistortionMap_Q0.clone();
	mSizeMatrix_horizontal = mDistortionMap_Q0_upsampled.size().width;
	mSizeMatrix_vertical = mDistortionMap_Q0_upsampled.size().height;
	mMaxStepToLook = 4;

	bool checker = true;
	unsigned int maxStepToLook = 3;
	while (checker)
	{
		horizontalInterpolation_oneStep_Q0();
		verticalInterpolation_oneStep_Q0();

		if (mFilledPoints_horizontal < mToleranceToCheckZero && mFilledPoints_vertical < mToleranceToCheckZero) // there is no improvement
		{
			holizontal_bilinear_Interpolation_Q0();
			vertical_bilinear_Interpolation_Q0();

			if (maxStepToLook > mMaxIterationBilinInterpol)
			{
				checker = false;
			}
			++maxStepToLook;
		}
	}

	//// no distortion on axis
	//unsigned int height =  mDistortionMap_Q0_upsampled.size().height;
	//for (unsigned int i = 0; i < height; ++i)
	//{
	//	mDistortionMap_Q0_upsampled.at<float>(i, 0) = 0.0;
	//}
	//for (unsigned int j = 0; j < mDistortionMap_Q0_upsampled.size().width; ++j)
	//{
	//	mDistortionMap_Q0_upsampled.at<float>(height - 1, j) = 0.0;
	//}

	

}

void Distortion::horizontalInterpolation_oneStep_Q0()
{
	mFilledPoints_horizontal = 0;
	float tempValue{};

	for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix_vertical; ++verticalPos)
	{
		for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix_horizontal; ++horizontalPos)
		{
			tempValue = mDistortionMap_Q0_upsampled.at<float>(verticalPos, horizontalPos);

			if (std::abs(tempValue) < mToleranceToCheckZero)
			{
				lookPositive_X_oneStep_Q0(horizontalPos, verticalPos);
				if (mLook_Pos_X_oneStep_trueVal)
				{
					lookNegativ_X_oneStep_Q0(horizontalPos, verticalPos);
				}

				if (mLook_Neg_X_oneStep_trueVal && mLook_Pos_X_oneStep_trueVal) // calculate new value in OPD matrix
				{
					tempValue = (mValOneStep_posX + mValOneStep_negX) / 2;

					mDistortionMap_Q0_upsampled.at<float>(verticalPos, horizontalPos) = tempValue;
					++mFilledPoints_horizontal;
				}

				if (mLook_Pos_X_oneStep_trueVal)
				{
					++horizontalPos;
				}
			}
		}
	}
}

void Distortion::holizontal_bilinear_Interpolation_Q0()
{
	mFilledPoints_horizontal = 0;
	float tempValue{};


	for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix_vertical; ++verticalPos)
	{
		for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix_horizontal; ++horizontalPos)
		{
			tempValue = mDistortionMap_Q0_upsampled.at<float>(verticalPos, horizontalPos);
			// just for debugging 
			// std::cout << tempValue << std::endl;

			if (std::abs(tempValue) < mToleranceToCheckZero)
			{
				lookNegativ_X_multiSteps_Q0(horizontalPos, verticalPos);
				if (mLook_Neg_X.getTrueVal())
				{
					lookPositiv_X_multiSteps_Q0(horizontalPos, verticalPos);
				}

				if (mLook_Neg_X.getTrueVal() && mLook_Pos_X.getTrueVal()) // calculate new value in OPD matrix
				{
					// see: https://de.wikipedia.org/wiki/Bilineare_Filterung

					tempValue = (float)(mLook_Pos_X.getPos_X() - horizontalPos) / (mLook_Pos_X.getPos_X() - mLook_Neg_X.getPos_X()) * mLook_Neg_X.getVal() + (float)(horizontalPos - mLook_Neg_X.getPos_X()) / (mLook_Pos_X.getPos_X() - mLook_Neg_X.getPos_X()) * mLook_Pos_X.getVal();

					mDistortionMap_Q0_upsampled.at<float>(verticalPos, horizontalPos) = tempValue;
					++mFilledPoints_horizontal;
				}
			}
		}
	}

}




void Distortion::vertical_bilinear_Interpolation_Q0()
{
	mFilledPoints_vertical = 0;
	float tempValue{};

	for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix_horizontal; ++horizontalPos)
	{
		for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix_vertical; ++verticalPos)
		{
			tempValue = mDistortionMap_Q0_upsampled.at<float>(verticalPos, horizontalPos);
			// just for debugging
			//std::cout << tempValue << std::endl;

			if (std::abs(tempValue) < mToleranceToCheckZero)
			{
				lookNegativ_Y_multiSteps_Q0(horizontalPos, verticalPos);
				if (mLook_Neg_Y.getTrueVal())
				{
					lookPositiv_Y_multiSteps_Q0(horizontalPos, verticalPos);
				}

				if (mLook_Neg_Y.getTrueVal() && mLook_Pos_Y.getTrueVal()) // calculate new value in OPD matrix
				{
					// see: https://de.wikipedia.org/wiki/Bilineare_Filterung

					tempValue = (float)(mLook_Pos_Y.getPos_Y() - verticalPos) / (mLook_Pos_Y.getPos_Y() - mLook_Neg_Y.getPos_Y()) * mLook_Neg_Y.getVal() + (float)(verticalPos - mLook_Neg_Y.getPos_Y()) / (mLook_Pos_Y.getPos_Y() - mLook_Neg_Y.getPos_Y()) * mLook_Pos_Y.getVal();

					mDistortionMap_Q0_upsampled.at<float>(verticalPos, horizontalPos) = tempValue;
					++mFilledPoints_vertical;
				}
			}
		}
	}

}

void Distortion::verticalInterpolation_oneStep_Q0()
{
	mFilledPoints_vertical = 0;
	float tempValue{};

	for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix_horizontal; ++horizontalPos)
	{
		for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix_vertical; ++verticalPos)
		{
			tempValue = mDistortionMap_Q0_upsampled.at<float>(verticalPos, horizontalPos);

			if (std::abs(tempValue) < mToleranceToCheckZero)
			{
				lookPositive_Y_oneStep_Q0(horizontalPos, verticalPos);
				if (mLook_Pos_Y_oneStep_trueVal)
				{
					lookNegative_Y_oneStep_Q0(horizontalPos, verticalPos);
				}

				if (mLook_Neg_Y_oneStep_trueVal && mLook_Pos_Y_oneStep_trueVal) // calculate new value in OPD matrix
				{
					tempValue = (mValOneStep_posY + mValOneStep_negY) / 2;

					mDistortionMap_Q0_upsampled.at<float>(verticalPos, horizontalPos) = tempValue;
					++mFilledPoints_vertical;
				}

				if (mLook_Pos_Y_oneStep_trueVal)
				{
					++verticalPos;
				}
			}
		}
	}

}


// look negativ x direction
void Distortion::lookNegativ_X_multiSteps_Q0(unsigned int posX, unsigned int posY)
{
	int tempPosX = posX - 1;
	float tempVal;
	mLook_Neg_X.setTrueVal(false);

	if (tempPosX >= 0)
	{
		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
		{
			tempVal = mDistortionMap_Q0_upsampled.at<float>(posY, tempPosX);

			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
			{
				mLook_Neg_X.setTrueVal(true);
				mLook_Neg_X.setPos_X(tempPosX);
				mLook_Neg_X.setPos_Y(posY);
				mLook_Neg_X.setVal(tempVal);
				i = mMaxStepToLook;
			}


			--tempPosX;
			if (tempPosX < 0)
			{
				i = mMaxStepToLook;
			}

		}


	}


}

void Distortion::lookNegativ_X_oneStep_Q0(unsigned int posX, unsigned int posY)
{
	int tempPosX = posX - 1;
	float tempVal;
	mLook_Neg_X_oneStep_trueVal = false;

	if (tempPosX >= 0)
	{

		tempVal = mDistortionMap_Q0_upsampled.at<float>(posY, tempPosX);

		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
		{
			mValOneStep_negX = tempVal;
			mLook_Neg_X_oneStep_trueVal = true;
		}
	}

}

void Distortion::lookPositive_X_oneStep_Q0(unsigned int posX, unsigned int posY)
{
	int tempPosX = posX + 1;
	float tempVal;
	mLook_Pos_X_oneStep_trueVal = false;

	if (tempPosX < mSizeMatrix_horizontal)
	{
		tempVal = mDistortionMap_Q0_upsampled.at<float>(posY, tempPosX);

		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
		{
			mValOneStep_posX = tempVal;
			mLook_Pos_X_oneStep_trueVal = true;
		}

	}
}

void Distortion::lookNegative_Y_oneStep_Q0(unsigned int posX, unsigned int posY)
{
	int tempPosY = posY - 1;
	float tempVal;
	mLook_Neg_Y_oneStep_trueVal = false;

	if (tempPosY >= 0)
	{

		tempVal = mDistortionMap_Q0_upsampled.at<float>(tempPosY, posX);

		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
		{
			mValOneStep_negY = tempVal;
			mLook_Neg_Y_oneStep_trueVal = true;
		}
	}
}

void Distortion::lookPositive_Y_oneStep_Q0(unsigned int posX, unsigned int posY)
{
	int tempPosY = posY + 1;
	float tempVal;
	mLook_Pos_Y_oneStep_trueVal = false;

	if (tempPosY < mSizeMatrix_vertical)
	{
		tempVal = mDistortionMap_Q0_upsampled.at<float>(tempPosY, posX);

		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
		{
			mValOneStep_posY = tempVal;
			mLook_Pos_Y_oneStep_trueVal = true;
		}

	}
}

// look positiv x direction
void Distortion::lookPositiv_X_multiSteps_Q0(unsigned int posX, unsigned int posY)
{
	int tempPosX = posX + 1;
	float tempVal;
	mLook_Pos_X.setTrueVal(false);

	if (tempPosX < mSizeMatrix_horizontal)
	{
		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
		{
			tempVal = mDistortionMap_Q0_upsampled.at<float>(posY, tempPosX);

			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
			{
				mLook_Pos_X.setTrueVal(true);
				mLook_Pos_X.setPos_X(tempPosX);
				mLook_Pos_X.setPos_Y(posY);
				mLook_Pos_X.setVal(tempVal);
				i = mMaxStepToLook;
			}

			++tempPosX;
			if (tempPosX >= mSizeMatrix_horizontal)
			{
				i = mMaxStepToLook;
			}

		}


	}
}

// look negativ y direction
void Distortion::lookNegativ_Y_multiSteps_Q0(unsigned int posX, unsigned int posY)
{
	int tempPosY = posY - 1;
	float tempVal;
	mLook_Neg_Y.setTrueVal(false);

	if (tempPosY >= 0)
	{
		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
		{
			tempVal = mDistortionMap_Q0_upsampled.at<float>(tempPosY, posX);
			// just for debugging
			// std::cout << tempVal << std::endl;

			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
			{
				mLook_Neg_Y.setTrueVal(true);
				mLook_Neg_Y.setPos_X(posX);
				mLook_Neg_Y.setPos_Y(tempPosY);
				mLook_Neg_Y.setVal(tempVal);
				i = mMaxStepToLook;
			}

			--tempPosY;
			if (tempPosY < 0)
			{
				i = mMaxStepToLook;
			}

		}


	}
}

// look positiv y direction
void Distortion::lookPositiv_Y_multiSteps_Q0(unsigned int posX, unsigned int posY)
{
	int tempPosY = posY + 1;
	float tempVal;
	mLook_Pos_Y.setTrueVal(false);

	if (tempPosY < mSizeMatrix_vertical)
	{
		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
		{
			tempVal = mDistortionMap_Q0_upsampled.at<float>(tempPosY, posX);

			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
			{
				mLook_Pos_Y.setTrueVal(true);
				mLook_Pos_Y.setPos_X(posX);
				mLook_Pos_Y.setPos_Y(tempPosY);
				mLook_Pos_Y.setVal(tempVal);
				i = mMaxStepToLook;
			}

			++tempPosY;
			if (tempPosY >= mSizeMatrix_vertical)
			{
				i = mMaxStepToLook;
			}

		}


	}
}

// *** bilinear interpolation to fill holes in OPD matrix --> RemapX
void Distortion::bilinearInterpolToFillHolesInDistortionMap_RemapX()
{
	mMaxIterationBilinInterpol = 3;
	mToleranceToCheckZero = 0.0000000001;
	mMapX_forRemap_upsampled = mMapX_forRemap.clone();
	mSizeMatrix_horizontal = mMapX_forRemap_upsampled.size().width;
	mSizeMatrix_vertical = mMapX_forRemap_upsampled.size().height;
	mMaxStepToLook = 4;

	bool checker = true;
	unsigned int maxStepToLook = 3;
	while (checker)
	{
		horizontalInterpolation_oneStep_RemapX();
		verticalInterpolation_oneStep_RemapX();

		if (mFilledPoints_horizontal < mToleranceToCheckZero && mFilledPoints_vertical < mToleranceToCheckZero) // there is no improvement
		{
			holizontal_bilinear_Interpolation_RemapX();
			vertical_bilinear_Interpolation_RemapX();

			if (maxStepToLook > mMaxIterationBilinInterpol)
			{
				checker = false;
			}
			++maxStepToLook;
		}
	}
}

void Distortion::holizontal_bilinear_Interpolation_RemapX()
{
	mFilledPoints_horizontal = 0;
	float tempValue{};


	for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix_vertical; ++verticalPos)
	{
		for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix_horizontal; ++horizontalPos)
		{
			tempValue = mMapX_forRemap_upsampled.at<float>(verticalPos, horizontalPos);
			// just for debugging 
			// std::cout << tempValue << std::endl;

			if (std::abs(tempValue) < mToleranceToCheckZero)
			{
				lookNegativ_X_multiSteps_RemapX(horizontalPos, verticalPos);
				if (mLook_Neg_X.getTrueVal())
				{
					lookPositiv_X_multiSteps_RemapX(horizontalPos, verticalPos);
				}

				if (mLook_Neg_X.getTrueVal() && mLook_Pos_X.getTrueVal()) // calculate new value in OPD matrix
				{
					// see: https://de.wikipedia.org/wiki/Bilineare_Filterung

					tempValue = (float)(mLook_Pos_X.getPos_X() - horizontalPos) / (mLook_Pos_X.getPos_X() - mLook_Neg_X.getPos_X()) * mLook_Neg_X.getVal() + (float)(horizontalPos - mLook_Neg_X.getPos_X()) / (mLook_Pos_X.getPos_X() - mLook_Neg_X.getPos_X()) * mLook_Pos_X.getVal();

					mMapX_forRemap_upsampled.at<float>(verticalPos, horizontalPos) = tempValue;
					++mFilledPoints_horizontal;
				}
			}
		}
	}
}

void Distortion::horizontalInterpolation_oneStep_RemapX()
{
	mFilledPoints_horizontal = 0;
	float tempValue{};

	for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix_vertical; ++verticalPos)
	{
		for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix_horizontal; ++horizontalPos)
		{
			tempValue = mMapX_forRemap_upsampled.at<float>(verticalPos, horizontalPos);

			if (std::abs(tempValue) < mToleranceToCheckZero)
			{
				lookPositive_X_oneStep_RemapX(horizontalPos, verticalPos);
				if (mLook_Pos_X_oneStep_trueVal)
				{
					lookNegativ_X_oneStep_RemapX(horizontalPos, verticalPos);
				}

				if (mLook_Neg_X_oneStep_trueVal && mLook_Pos_X_oneStep_trueVal) // calculate new value in OPD matrix
				{
					tempValue = (mValOneStep_posX + mValOneStep_negX) / 2;

					mMapX_forRemap_upsampled.at<float>(verticalPos, horizontalPos) = tempValue;
					++mFilledPoints_horizontal;
				}

				if (mLook_Pos_X_oneStep_trueVal)
				{
					++horizontalPos;
				}
			}
		}
	}
}

void Distortion::vertical_bilinear_Interpolation_RemapX() 
{
	mFilledPoints_vertical = 0;
	float tempValue{};

	for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix_horizontal; ++horizontalPos)
	{
		for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix_vertical; ++verticalPos)
		{
			tempValue = mMapX_forRemap_upsampled.at<float>(verticalPos, horizontalPos);
			// just for debugging
			//std::cout << tempValue << std::endl;

			if (std::abs(tempValue) < mToleranceToCheckZero)
			{
				lookNegativ_Y_multiSteps_RemapX(horizontalPos, verticalPos);
				if (mLook_Neg_Y.getTrueVal())
				{
					lookPositiv_Y_multiSteps_RemapX(horizontalPos, verticalPos);
				}

				if (mLook_Neg_Y.getTrueVal() && mLook_Pos_Y.getTrueVal()) // calculate new value in OPD matrix
				{
					// see: https://de.wikipedia.org/wiki/Bilineare_Filterung

					tempValue = (float)(mLook_Pos_Y.getPos_Y() - verticalPos) / (mLook_Pos_Y.getPos_Y() - mLook_Neg_Y.getPos_Y()) * mLook_Neg_Y.getVal() + (float)(verticalPos - mLook_Neg_Y.getPos_Y()) / (mLook_Pos_Y.getPos_Y() - mLook_Neg_Y.getPos_Y()) * mLook_Pos_Y.getVal();

					mMapX_forRemap_upsampled.at<float>(verticalPos, horizontalPos) = tempValue;
					++mFilledPoints_vertical;
				}
			}
		}
	}

}
void Distortion::verticalInterpolation_oneStep_RemapX()
{
	mFilledPoints_vertical = 0;
	float tempValue{};

	for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix_horizontal; ++horizontalPos)
	{
		for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix_vertical; ++verticalPos)
		{
			tempValue = mMapX_forRemap_upsampled.at<float>(verticalPos, horizontalPos);

			if (std::abs(tempValue) < mToleranceToCheckZero)
			{
				lookPositive_Y_oneStep_RemapX(horizontalPos, verticalPos);
				if (mLook_Pos_Y_oneStep_trueVal)
				{
					lookNegative_Y_oneStep_RemapX(horizontalPos, verticalPos);
				}

				if (mLook_Neg_Y_oneStep_trueVal && mLook_Pos_Y_oneStep_trueVal) // calculate new value in OPD matrix
				{
					tempValue = (mValOneStep_posY + mValOneStep_negY) / 2;

					mMapX_forRemap_upsampled.at<float>(verticalPos, horizontalPos) = tempValue;
					++mFilledPoints_vertical;
				}

				if (mLook_Pos_Y_oneStep_trueVal)
				{
					++verticalPos;
				}
			}
		}
	}
}

// look negativ x direction
void Distortion::lookNegativ_X_multiSteps_RemapX(unsigned int posX, unsigned int posY)
{
	int tempPosX = posX - 1;
	float tempVal;
	mLook_Neg_X.setTrueVal(false);

	if (tempPosX >= 0)
	{
		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
		{
			tempVal = mMapX_forRemap_upsampled.at<float>(posY, tempPosX);

			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
			{
				mLook_Neg_X.setTrueVal(true);
				mLook_Neg_X.setPos_X(tempPosX);
				mLook_Neg_X.setPos_Y(posY);
				mLook_Neg_X.setVal(tempVal);
				i = mMaxStepToLook;
			}


			--tempPosX;
			if (tempPosX < 0)
			{
				i = mMaxStepToLook;
			}

		}


	}
}

void Distortion::lookNegativ_X_oneStep_RemapX(unsigned int posX, unsigned int posY)
{
	int tempPosX = posX - 1;
	float tempVal;
	mLook_Neg_X_oneStep_trueVal = false;

	if (tempPosX >= 0)
	{

		tempVal = mMapX_forRemap_upsampled.at<float>(posY, tempPosX);

		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
		{
			mValOneStep_negX = tempVal;
			mLook_Neg_X_oneStep_trueVal = true;
		}
	}

}

// look positiv x direction
void Distortion::lookPositiv_X_multiSteps_RemapX(unsigned int posX, unsigned int posY)
{
	int tempPosX = posX + 1;
	float tempVal;
	mLook_Pos_X.setTrueVal(false);

	if (tempPosX < mSizeMatrix_horizontal)
	{
		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
		{
			tempVal = mMapX_forRemap_upsampled.at<float>(posY, tempPosX);

			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
			{
				mLook_Pos_X.setTrueVal(true);
				mLook_Pos_X.setPos_X(tempPosX);
				mLook_Pos_X.setPos_Y(posY);
				mLook_Pos_X.setVal(tempVal);
				i = mMaxStepToLook;
			}

			++tempPosX;
			if (tempPosX >= mSizeMatrix_horizontal)
			{
				i = mMaxStepToLook;
			}

		}


	}
}
void Distortion::lookPositive_X_oneStep_RemapX(unsigned int posX, unsigned int posY)
{
	int tempPosX = posX + 1;
	float tempVal;
	mLook_Pos_X_oneStep_trueVal = false;

	if (tempPosX < mSizeMatrix_horizontal)
	{
		tempVal = mMapX_forRemap_upsampled.at<float>(posY, tempPosX);

		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
		{
			mValOneStep_posX = tempVal;
			mLook_Pos_X_oneStep_trueVal = true;
		}

	}
}

// look negativ y direction
void Distortion::lookNegativ_Y_multiSteps_RemapX(unsigned int posX, unsigned int posY)
{
	int tempPosY = posY - 1;
	float tempVal;
	mLook_Neg_Y.setTrueVal(false);

	if (tempPosY >= 0)
	{
		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
		{
			tempVal = mMapX_forRemap_upsampled.at<float>(tempPosY, posX);
			// just for debugging
			// std::cout << tempVal << std::endl;

			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
			{
				mLook_Neg_Y.setTrueVal(true);
				mLook_Neg_Y.setPos_X(posX);
				mLook_Neg_Y.setPos_Y(tempPosY);
				mLook_Neg_Y.setVal(tempVal);
				i = mMaxStepToLook;
			}

			--tempPosY;
			if (tempPosY < 0)
			{
				i = mMaxStepToLook;
			}

		}


	}
}
void Distortion::lookNegative_Y_oneStep_RemapX(unsigned int posX, unsigned int posY)
{
	int tempPosY = posY - 1;
	float tempVal;
	mLook_Neg_Y_oneStep_trueVal = false;

	if (tempPosY >= 0)
	{

		tempVal = mMapX_forRemap_upsampled.at<float>(tempPosY, posX);

		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
		{
			mValOneStep_negY = tempVal;
			mLook_Neg_Y_oneStep_trueVal = true;
		}
	}
}

// look positiv y direction
void Distortion::lookPositiv_Y_multiSteps_RemapX(unsigned int posX, unsigned int posY)
{
	int tempPosY = posY + 1;
	float tempVal;
	mLook_Pos_Y.setTrueVal(false);

	if (tempPosY < mSizeMatrix_vertical)
	{
		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
		{
			tempVal = mMapX_forRemap_upsampled.at<float>(tempPosY, posX);

			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
			{
				mLook_Pos_Y.setTrueVal(true);
				mLook_Pos_Y.setPos_X(posX);
				mLook_Pos_Y.setPos_Y(tempPosY);
				mLook_Pos_Y.setVal(tempVal);
				i = mMaxStepToLook;
			}

			++tempPosY;
			if (tempPosY >= mSizeMatrix_vertical)
			{
				i = mMaxStepToLook;
			}

		}


	}
}
void Distortion::lookPositive_Y_oneStep_RemapX(unsigned int posX, unsigned int posY)
{
	int tempPosY = posY + 1;
	float tempVal;
	mLook_Pos_Y_oneStep_trueVal = false;

	if (tempPosY < mSizeMatrix_vertical)
	{
		tempVal = mMapX_forRemap_upsampled.at<float>(tempPosY, posX);

		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
		{
			mValOneStep_posY = tempVal;
			mLook_Pos_Y_oneStep_trueVal = true;
		}

	}
}

void Distortion::calculateDistortedImageUsingRemap()
{
	real tolerance = 0.001;

	// check Size and distortion 
	int sizeX_mapX = mMapX_forRemap.size().width;
	int sizeY_mapX = mMapX_forRemap.size().height;
	int sizeX_mapY = mMapY_forRemap.size().width;
	int sizeY_mapY = mMapY_forRemap.size().height;

	int sizeX_distortionMapTotal = mDistortionMap_Total.size().width;
	int sizeY_distortionMapTotal = mDistortionMap_Total.size().height;

	int sizeX_image = mImage.size().width;
	int sizeY_image = mImage.size().height;

	//*** check for errors in size
	if (std::abs(sizeX_mapX - sizeX_mapY) > tolerance || std::abs(sizeY_mapX - sizeY_mapY) > tolerance)
	{
		// there must be something wrong
		oftenUse::errorProtocol_stopSystem("error in remap for distortion - 1", "Distortion.cpp", 0, true);
	}

	//if (std::abs(sizeX_distortionMapTotal - sizeX_mapX) > tolerance || std::abs(sizeY_distortionMapTotal - sizeY_mapX) > tolerance)
	//{
	//
	//	// there must be something wrong
	//	oftenUse::errorProtocol_stopSystem("error in remap for distortion - 2", "Distortion.cpp", 0, true);
	//}
	if (std::abs(sizeX_image - sizeX_mapX) > tolerance || std::abs(sizeY_image - sizeY_mapY) > tolerance)
	{
		// we have to resize mapX and mapY
		cv::resize(mMapX_forRemap, mMapX_forRemap, cv::Size(sizeX_image, sizeY_image), cv::INTER_LANCZOS4);
		cv::resize(mMapY_forRemap, mMapY_forRemap, cv::Size(sizeX_image, sizeY_image), cv::INTER_LANCZOS4);
	
	
	}
	//***

	// calculate distortion using cv::remap
	// more infomration according to remap -> https://docs.opencv.org/3.4/d1/da0/tutorial_remap.html
	// debug 
	//std::string location = "../tests/testDistortion/s4";
	//inportExportData::exportCV_MatToExcel(mMapX_forRemap, location, "mMapX_forRemap");

	if (mDecissionValue < 0) // barrel distortion 
	{
		cv::remap(mImage, mDistortedImage, mMapX_forRemap, mMapY_forRemap, cv::INTER_LANCZOS4, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));
		mDistortedImage_ROI = mDistortedImage;
	}
	else if (mDecissionValue > 0) // pincushion distortion
	{
		//cv::remap(mImage, mDistortedImage, mMapX_forRemap_upsampled, mMapY_forRemap_upsampled, cv::INTER_LANCZOS4, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));
		cv::remap(mImage, mDistortedImage, mMapX_forRemap_upsampled, mMapY_forRemap_upsampled, cv::INTER_LANCZOS4, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));
		mDistortedImage_ROI = mDistortedImage(mROI);


	}


}

// *** get function
cv::Mat Distortion::getDistortionMap_Q0()
{
	return mDistortionMap_Q0;
}
cv::Mat Distortion::getDistortionMap_Q0_upsampled()
{
	return mDistortionMap_Q0_upsampled;
}
cv::Mat Distortion::getDistortionMap_Q1()
{
	return mDistortionMap_Q1;
}

cv::Mat Distortion::getDistortionMap_Q0_Q1()
{
	return mDistortionMap_Q0_Q1;
}
cv::Mat Distortion::getDistortionMap_Q2_Q3()
{
	return mDistortionMap_Q2_Q3;
}
cv::Mat Distortion::getTotalDistortionMap()
{
	return mDistortionMap_Total;
}

cv::Mat Distortion::getRemap_X()
{
	return mMapX_forRemap;
}
cv::Mat Distortion::getRemap_Y()
{
	return mMapY_forRemap;
}

cv::Mat Distortion::getDistortedImage()
{
	return mDistortedImage_ROI;
}
// ***



cv::Mat Distortion::correctDistortion()
{
	real tolerance = 0.001;

	// check Size and distortion 
	int sizeX_mapX = mMapX_forRemap_CorrectDistortion.size().width;
	int sizeY_mapX = mMapX_forRemap_CorrectDistortion.size().height;
	int sizeX_mapY = mMapY_forRemap_CorrectDistortion.size().width;
	int sizeY_mapY = mMapY_forRemap_CorrectDistortion.size().height;

	int sizeX_distortionMapTotal = mDistortionMap_Total.size().width;
	int sizeY_distortionMapTotal = mDistortionMap_Total.size().height;

	int sizeX_image = mDistortedImage.size().width;
	int sizeY_image = mDistortedImage.size().height;

	//*** check for errors in size
	if (std::abs(sizeX_mapX - sizeX_mapY) > tolerance || std::abs(sizeY_mapX - sizeY_mapY) > tolerance)
	{
		// there must be something wrong
		oftenUse::errorProtocol_stopSystem("error in remap for distortion - 1", "Distortion.cpp", 0, true);
	}

	//if (std::abs(sizeX_distortionMapTotal - sizeX_mapX) > tolerance || std::abs(sizeY_distortionMapTotal - sizeY_mapX) > tolerance)
	//{
	//
	//	// there must be something wrong
	//	oftenUse::errorProtocol_stopSystem("error in remap for distortion - 2", "Distortion.cpp", 0, true);
	//}
	if (std::abs(sizeX_image - sizeX_mapX) > tolerance || std::abs(sizeY_image - sizeY_mapX) > tolerance)
	{
		// we have to resize mapX and mapY
		cv::resize(mMapX_forRemap_CorrectDistortion, mMapX_forRemap_CorrectDistortion, cv::Size(sizeX_image, sizeY_image), cv::INTER_LANCZOS4);
		cv::resize(mMapY_forRemap_CorrectDistortion, mMapY_forRemap_CorrectDistortion, cv::Size(sizeX_image, sizeY_image), cv::INTER_LANCZOS4);
	}
	//***

	// calculate distortion using cv::remap
	// more infomration according to remap -> https://docs.opencv.org/3.4/d1/da0/tutorial_remap.html
	// debug 
	//std::string location = "../tests/testDistortion/s4";
	//inportExportData::exportCV_MatToExcel(mMapX_forRemap, location, "mMapX_forRemap");

	cv::Mat correctedImage;
	//mDecissionValue = -1.0 * mDecissionValue;
	if (mDecissionValue < 0) // barrel distortion 
	{
		cv::remap(mDistortedImage, correctedImage, mMapX_forRemap_CorrectDistortion, mMapY_forRemap_CorrectDistortion, cv::INTER_LANCZOS4, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));

	}
	else if (mDecissionValue > 0) // pincushion distortion
	{
		//// debug 
		//mMapX_forRemap_upsampled_CorrectDistortion = mMapX_forRemap_CorrectDistortion;
		//mMapY_forRemap_upsampled_CorrectDistortion = mMapY_forRemap_CorrectDistortion;
		//bilinearInterpolToFillHolesInDistortionMap_RemapX_correctDistortion();
		//bilinearInterpolToFillHolesInDistortionMap_RemapY_correctDistortion();

		cv::remap(mDistortedImage, correctedImage, mMapX_forRemap_CorrectDistortion, mMapY_forRemap_CorrectDistortion, cv::INTER_LANCZOS4, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));
	
		cv::Rect roi{};
		roi.x = 0;
		roi.y = 0;
		roi.width = mImage.cols;
		roi.height = mImage.rows;

		correctedImage = correctedImage(roi);
	}

	return correctedImage;
}

// *** bilinear interpolation to fill holes in OPD matrix Correct Distortion --> RemapY
void Distortion::bilinearInterpolToFillHolesInDistortionMap_RemapY()
{
	mMaxIterationBilinInterpol = 3;
	mToleranceToCheckZero = 0.0000000001;
	mMapY_forRemap_upsampled = mMapY_forRemap.clone();
	mSizeMatrix_horizontal = mMapY_forRemap_upsampled.size().width;
	mSizeMatrix_vertical = mMapY_forRemap_upsampled.size().height;
	mMaxStepToLook = 4;

	bool checker = true;
	unsigned int maxStepToLook = 3;
	while (checker)
	{
		horizontalInterpolation_oneStep_RemapY();
		verticalInterpolation_oneStep_RemapY();

		if (mFilledPoints_horizontal < mToleranceToCheckZero && mFilledPoints_vertical < mToleranceToCheckZero) // there is no improvement
		{
			holizontal_bilinear_Interpolation_RemapY();
			vertical_bilinear_Interpolation_RemapY();

			if (maxStepToLook > mMaxIterationBilinInterpol)
			{
				checker = false;
			}
			++maxStepToLook;
		}
	}
}

void Distortion::holizontal_bilinear_Interpolation_RemapY()
{
	mFilledPoints_horizontal = 0;
	float tempValue{};


	for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix_vertical; ++verticalPos)
	{
		for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix_horizontal; ++horizontalPos)
		{
			tempValue = mMapY_forRemap_upsampled.at<float>(verticalPos, horizontalPos);
			// just for debugging 
			// std::cout << tempValue << std::endl;

			if (std::abs(tempValue) < mToleranceToCheckZero)
			{
				lookNegativ_X_multiSteps_RemapY(horizontalPos, verticalPos);
				if (mLook_Neg_X.getTrueVal())
				{
					lookPositiv_X_multiSteps_RemapY(horizontalPos, verticalPos);
				}

				if (mLook_Neg_X.getTrueVal() && mLook_Pos_X.getTrueVal()) // calculate new value in OPD matrix
				{
					// see: https://de.wikipedia.org/wiki/Bilineare_Filterung

					tempValue = (float)(mLook_Pos_X.getPos_X() - horizontalPos) / (mLook_Pos_X.getPos_X() - mLook_Neg_X.getPos_X()) * mLook_Neg_X.getVal() + (float)(horizontalPos - mLook_Neg_X.getPos_X()) / (mLook_Pos_X.getPos_X() - mLook_Neg_X.getPos_X()) * mLook_Pos_X.getVal();

					mMapY_forRemap_upsampled.at<float>(verticalPos, horizontalPos) = tempValue;
					++mFilledPoints_horizontal;
				}
			}
		}
	}
}

void Distortion::horizontalInterpolation_oneStep_RemapY()
{
	mFilledPoints_horizontal = 0;
	float tempValue{};

	for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix_vertical; ++verticalPos)
	{
		for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix_horizontal; ++horizontalPos)
		{
			tempValue = mMapY_forRemap_upsampled.at<float>(verticalPos, horizontalPos);

			if (std::abs(tempValue) < mToleranceToCheckZero)
			{
				lookPositive_X_oneStep_RemapY(horizontalPos, verticalPos);
				if (mLook_Pos_X_oneStep_trueVal)
				{
					lookNegativ_X_oneStep_RemapY(horizontalPos, verticalPos);
				}

				if (mLook_Neg_X_oneStep_trueVal && mLook_Pos_X_oneStep_trueVal) // calculate new value in OPD matrix
				{
					tempValue = (mValOneStep_posX + mValOneStep_negX) / 2;

					mMapY_forRemap_upsampled.at<float>(verticalPos, horizontalPos) = tempValue;
					++mFilledPoints_horizontal;
				}

				if (mLook_Pos_X_oneStep_trueVal)
				{
					++horizontalPos;
				}
			}
		}
	}
}

void Distortion::vertical_bilinear_Interpolation_RemapY()
{
	mFilledPoints_vertical = 0;
	float tempValue{};

	for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix_horizontal; ++horizontalPos)
	{
		for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix_vertical; ++verticalPos)
		{
			tempValue = mMapY_forRemap_upsampled.at<float>(verticalPos, horizontalPos);
			// just for debugging
			//std::cout << tempValue << std::endl;

			if (std::abs(tempValue) < mToleranceToCheckZero)
			{
				lookNegativ_Y_multiSteps_RemapY(horizontalPos, verticalPos);
				if (mLook_Neg_Y.getTrueVal())
				{
					lookPositiv_Y_multiSteps_RemapY(horizontalPos, verticalPos);
				}

				if (mLook_Neg_Y.getTrueVal() && mLook_Pos_Y.getTrueVal()) // calculate new value in OPD matrix
				{
					// see: https://de.wikipedia.org/wiki/Bilineare_Filterung

					tempValue = (float)(mLook_Pos_Y.getPos_Y() - verticalPos) / (mLook_Pos_Y.getPos_Y() - mLook_Neg_Y.getPos_Y()) * mLook_Neg_Y.getVal() + (float)(verticalPos - mLook_Neg_Y.getPos_Y()) / (mLook_Pos_Y.getPos_Y() - mLook_Neg_Y.getPos_Y()) * mLook_Pos_Y.getVal();

					mMapY_forRemap_upsampled.at<float>(verticalPos, horizontalPos) = tempValue;
					++mFilledPoints_vertical;
				}
			}
		}
	}

}
void Distortion::verticalInterpolation_oneStep_RemapY()
{
	mFilledPoints_vertical = 0;
	float tempValue{};

	for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix_horizontal; ++horizontalPos)
	{
		for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix_vertical; ++verticalPos)
		{
			tempValue = mMapY_forRemap_upsampled.at<float>(verticalPos, horizontalPos);

			if (std::abs(tempValue) < mToleranceToCheckZero)
			{
				lookPositive_Y_oneStep_RemapY(horizontalPos, verticalPos);
				if (mLook_Pos_Y_oneStep_trueVal)
				{
					lookNegative_Y_oneStep_RemapY(horizontalPos, verticalPos);
				}

				if (mLook_Neg_Y_oneStep_trueVal && mLook_Pos_Y_oneStep_trueVal) // calculate new value in OPD matrix
				{
					tempValue = (mValOneStep_posY + mValOneStep_negY) / 2;

					mMapY_forRemap_upsampled.at<float>(verticalPos, horizontalPos) = tempValue;
					++mFilledPoints_vertical;
				}

				if (mLook_Pos_Y_oneStep_trueVal)
				{
					++verticalPos;
				}
			}
		}
	}
}

// look negativ x direction
void Distortion::lookNegativ_X_multiSteps_RemapY(unsigned int posX, unsigned int posY)
{
	int tempPosX = posX - 1;
	float tempVal;
	mLook_Neg_X.setTrueVal(false);

	if (tempPosX >= 0)
	{
		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
		{
			tempVal = mMapY_forRemap_upsampled.at<float>(posY, tempPosX);

			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
			{
				mLook_Neg_X.setTrueVal(true);
				mLook_Neg_X.setPos_X(tempPosX);
				mLook_Neg_X.setPos_Y(posY);
				mLook_Neg_X.setVal(tempVal);
				i = mMaxStepToLook;
			}


			--tempPosX;
			if (tempPosX < 0)
			{
				i = mMaxStepToLook;
			}

		}


	}
}

void Distortion::lookNegativ_X_oneStep_RemapY(unsigned int posX, unsigned int posY)
{
	int tempPosX = posX - 1;
	float tempVal;
	mLook_Neg_X_oneStep_trueVal = false;

	if (tempPosX >= 0)
	{

		tempVal = mMapY_forRemap_upsampled.at<float>(posY, tempPosX);

		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
		{
			mValOneStep_negX = tempVal;
			mLook_Neg_X_oneStep_trueVal = true;
		}
	}

}

// look positiv x direction
void Distortion::lookPositiv_X_multiSteps_RemapY(unsigned int posX, unsigned int posY)
{
	int tempPosX = posX + 1;
	float tempVal;
	mLook_Pos_X.setTrueVal(false);

	if (tempPosX < mSizeMatrix_horizontal)
	{
		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
		{
			tempVal = mMapY_forRemap_upsampled.at<float>(posY, tempPosX);

			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
			{
				mLook_Pos_X.setTrueVal(true);
				mLook_Pos_X.setPos_X(tempPosX);
				mLook_Pos_X.setPos_Y(posY);
				mLook_Pos_X.setVal(tempVal);
				i = mMaxStepToLook;
			}

			++tempPosX;
			if (tempPosX >= mSizeMatrix_horizontal)
			{
				i = mMaxStepToLook;
			}

		}


	}
}
void Distortion::lookPositive_X_oneStep_RemapY(unsigned int posX, unsigned int posY)
{
	int tempPosX = posX + 1;
	float tempVal;
	mLook_Pos_X_oneStep_trueVal = false;

	if (tempPosX < mSizeMatrix_horizontal)
	{
		tempVal = mMapY_forRemap_upsampled.at<float>(posY, tempPosX);

		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
		{
			mValOneStep_posX = tempVal;
			mLook_Pos_X_oneStep_trueVal = true;
		}

	}
}

// look negativ y direction
void Distortion::lookNegativ_Y_multiSteps_RemapY(unsigned int posX, unsigned int posY)
{
	int tempPosY = posY - 1;
	float tempVal;
	mLook_Neg_Y.setTrueVal(false);

	if (tempPosY >= 0)
	{
		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
		{
			tempVal = mMapY_forRemap_upsampled.at<float>(tempPosY, posX);
			// just for debugging
			// std::cout << tempVal << std::endl;

			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
			{
				mLook_Neg_Y.setTrueVal(true);
				mLook_Neg_Y.setPos_X(posX);
				mLook_Neg_Y.setPos_Y(tempPosY);
				mLook_Neg_Y.setVal(tempVal);
				i = mMaxStepToLook;
			}

			--tempPosY;
			if (tempPosY < 0)
			{
				i = mMaxStepToLook;
			}

		}


	}
}
void Distortion::lookNegative_Y_oneStep_RemapY(unsigned int posX, unsigned int posY)
{
	int tempPosY = posY - 1;
	float tempVal;
	mLook_Neg_Y_oneStep_trueVal = false;

	if (tempPosY >= 0)
	{

		tempVal = mMapY_forRemap_upsampled.at<float>(tempPosY, posX);

		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
		{
			mValOneStep_negY = tempVal;
			mLook_Neg_Y_oneStep_trueVal = true;
		}
	}
}

// look positiv y direction
void Distortion::lookPositiv_Y_multiSteps_RemapY(unsigned int posX, unsigned int posY)
{
	int tempPosY = posY + 1;
	float tempVal;
	mLook_Pos_Y.setTrueVal(false);

	if (tempPosY < mSizeMatrix_vertical)
	{
		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
		{
			tempVal = mMapY_forRemap_upsampled.at<float>(tempPosY, posX);

			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
			{
				mLook_Pos_Y.setTrueVal(true);
				mLook_Pos_Y.setPos_X(posX);
				mLook_Pos_Y.setPos_Y(tempPosY);
				mLook_Pos_Y.setVal(tempVal);
				i = mMaxStepToLook;
			}

			++tempPosY;
			if (tempPosY >= mSizeMatrix_vertical)
			{
				i = mMaxStepToLook;
			}

		}


	}
}
void Distortion::lookPositive_Y_oneStep_RemapY(unsigned int posX, unsigned int posY)
{
	int tempPosY = posY + 1;
	float tempVal;
	mLook_Pos_Y_oneStep_trueVal = false;

	if (tempPosY < mSizeMatrix_vertical)
	{
		tempVal = mMapY_forRemap_upsampled.at<float>(tempPosY, posX);

		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
		{
			mValOneStep_posY = tempVal;
			mLook_Pos_Y_oneStep_trueVal = true;
		}

	}
}

//// *** bilinear interpolation to fill holes in distortion map correctDistortion --> RemapX
//void Distortion::bilinearInterpolToFillHolesInDistortionMap_RemapX_correctDistortion()
//{
//	mMaxIterationBilinInterpol = 3;
//	mToleranceToCheckZero = 0.0000000001;
//	mMapX_forRemap_upsampled_correctDistortion = mMapX_forRemap.clone();
//	mSizeMatrix_horizontal = mMapX_forRemap_upsampled_correctDistortion.size().width;
//	mSizeMatrix_vertical = mMapX_forRemap_upsampled_correctDistortion.size().height;
//	mMaxStepToLook = 4;
//
//	bool checker = true;
//	unsigned int maxStepToLook = 3;
//	while (checker)
//	{
//		horizontalInterpolation_oneStep_RemapX_correctDistortion();
//		verticalInterpolation_oneStep_RemapX_correctDistortion();
//
//		if (mFilledPoints_horizontal < mToleranceToCheckZero && mFilledPoints_vertical < mToleranceToCheckZero) // there is no improvement
//		{
//			holizontal_bilinear_Interpolation_RemapX_correctDistortion();
//			vertical_bilinear_Interpolation_RemapX_correctDistortion();
//
//			if (maxStepToLook > mMaxIterationBilinInterpol)
//			{
//				checker = false;
//			}
//			++maxStepToLook;
//		}
//	}
//}
//
//void Distortion::holizontal_bilinear_Interpolation_RemapX_correctDistortion()
//{
//	mFilledPoints_horizontal = 0;
//	float tempValue{};
//
//
//	for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix_vertical; ++verticalPos)
//	{
//		for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix_horizontal; ++horizontalPos)
//		{
//			tempValue = mMapX_forRemap_upsampled_correctDistortion.at<float>(verticalPos, horizontalPos);
//			// just for debugging 
//			// std::cout << tempValue << std::endl;
//
//			if (std::abs(tempValue) < mToleranceToCheckZero)
//			{
//				lookNegativ_X_multiSteps_RemapX_correctDistortion(horizontalPos, verticalPos);
//				if (mLook_Neg_X.getTrueVal())
//				{
//					lookPositiv_X_multiSteps_RemapX_correctDistortion(horizontalPos, verticalPos);
//				}
//
//				if (mLook_Neg_X.getTrueVal() && mLook_Pos_X.getTrueVal()) // calculate new value in OPD matrix
//				{
//					// see: https://de.wikipedia.org/wiki/Bilineare_Filterung
//
//					tempValue = (float)(mLook_Pos_X.getPos_X() - horizontalPos) / (mLook_Pos_X.getPos_X() - mLook_Neg_X.getPos_X()) * mLook_Neg_X.getVal() + (float)(horizontalPos - mLook_Neg_X.getPos_X()) / (mLook_Pos_X.getPos_X() - mLook_Neg_X.getPos_X()) * mLook_Pos_X.getVal();
//
//					mMapX_forRemap_upsampled_correctDistortion.at<float>(verticalPos, horizontalPos) = tempValue;
//					++mFilledPoints_horizontal;
//				}
//			}
//		}
//	}
//}
//
//void Distortion::horizontalInterpolation_oneStep_RemapX_correctDistortion()
//{
//	mFilledPoints_horizontal = 0;
//	float tempValue{};
//
//	for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix_vertical; ++verticalPos)
//	{
//		for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix_horizontal; ++horizontalPos)
//		{
//			tempValue = mMapX_forRemap_upsampled_correctDistortion.at<float>(verticalPos, horizontalPos);
//
//			if (std::abs(tempValue) < mToleranceToCheckZero)
//			{
//				lookPositive_X_oneStep_RemapX_correctDistortion(horizontalPos, verticalPos);
//				if (mLook_Pos_X_oneStep_trueVal)
//				{
//					lookNegativ_X_oneStep_RemapX_correctDistortion(horizontalPos, verticalPos);
//				}
//
//				if (mLook_Neg_X_oneStep_trueVal && mLook_Pos_X_oneStep_trueVal) // calculate new value in OPD matrix
//				{
//					tempValue = (mValOneStep_posX + mValOneStep_negX) / 2;
//
//					mMapX_forRemap_upsampled_correctDistortion.at<float>(verticalPos, horizontalPos) = tempValue;
//					++mFilledPoints_horizontal;
//				}
//
//				if (mLook_Pos_X_oneStep_trueVal)
//				{
//					++horizontalPos;
//				}
//			}
//		}
//	}
//}
//
//void Distortion::vertical_bilinear_Interpolation_RemapX_correctDistortion()
//{
//	mFilledPoints_vertical = 0;
//	float tempValue{};
//
//	for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix_horizontal; ++horizontalPos)
//	{
//		for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix_vertical; ++verticalPos)
//		{
//			tempValue = mMapX_forRemap_upsampled_correctDistortion.at<float>(verticalPos, horizontalPos);
//			// just for debugging
//			//std::cout << tempValue << std::endl;
//
//			if (std::abs(tempValue) < mToleranceToCheckZero)
//			{
//				lookNegativ_Y_multiSteps_RemapX_correctDistortion(horizontalPos, verticalPos);
//				if (mLook_Neg_Y.getTrueVal())
//				{
//					lookPositiv_Y_multiSteps_RemapX_correctDistortion(horizontalPos, verticalPos);
//				}
//
//				if (mLook_Neg_Y.getTrueVal() && mLook_Pos_Y.getTrueVal()) // calculate new value in OPD matrix
//				{
//					// see: https://de.wikipedia.org/wiki/Bilineare_Filterung
//
//					tempValue = (float)(mLook_Pos_Y.getPos_Y() - verticalPos) / (mLook_Pos_Y.getPos_Y() - mLook_Neg_Y.getPos_Y()) * mLook_Neg_Y.getVal() + (float)(verticalPos - mLook_Neg_Y.getPos_Y()) / (mLook_Pos_Y.getPos_Y() - mLook_Neg_Y.getPos_Y()) * mLook_Pos_Y.getVal();
//
//					mMapX_forRemap_upsampled_correctDistortion.at<float>(verticalPos, horizontalPos) = tempValue;
//					++mFilledPoints_vertical;
//				}
//			}
//		}
//	}
//
//}
//void Distortion::verticalInterpolation_oneStep_RemapX_correctDistortion()
//{
//	mFilledPoints_vertical = 0;
//	float tempValue{};
//
//	for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix_horizontal; ++horizontalPos)
//	{
//		for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix_vertical; ++verticalPos)
//		{
//			tempValue = mMapX_forRemap_upsampled_correctDistortion.at<float>(verticalPos, horizontalPos);
//
//			if (std::abs(tempValue) < mToleranceToCheckZero)
//			{
//				lookPositive_Y_oneStep_RemapX_correctDistortion(horizontalPos, verticalPos);
//				if (mLook_Pos_Y_oneStep_trueVal)
//				{
//					lookNegative_Y_oneStep_RemapX_correctDistortion(horizontalPos, verticalPos);
//				}
//
//				if (mLook_Neg_Y_oneStep_trueVal && mLook_Pos_Y_oneStep_trueVal) // calculate new value in OPD matrix
//				{
//					tempValue = (mValOneStep_posY + mValOneStep_negY) / 2;
//
//					mMapX_forRemap_upsampled_correctDistortion.at<float>(verticalPos, horizontalPos) = tempValue;
//					++mFilledPoints_vertical;
//				}
//
//				if (mLook_Pos_Y_oneStep_trueVal)
//				{
//					++verticalPos;
//				}
//			}
//		}
//	}
//}
//
//// look negativ x direction
//void Distortion::lookNegativ_X_multiSteps_RemapX_correctDistortion(unsigned int posX, unsigned int posY)
//{
//	int tempPosX = posX - 1;
//	float tempVal;
//	mLook_Neg_X.setTrueVal(false);
//
//	if (tempPosX >= 0)
//	{
//		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
//		{
//			tempVal = mMapX_forRemap_upsampled_correctDistortion.at<float>(posY, tempPosX);
//
//			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
//			{
//				mLook_Neg_X.setTrueVal(true);
//				mLook_Neg_X.setPos_X(tempPosX);
//				mLook_Neg_X.setPos_Y(posY);
//				mLook_Neg_X.setVal(tempVal);
//				i = mMaxStepToLook;
//			}
//
//
//			--tempPosX;
//			if (tempPosX < 0)
//			{
//				i = mMaxStepToLook;
//			}
//
//		}
//
//
//	}
//}
//
//void Distortion::lookNegativ_X_oneStep_RemapX_correctDistortion(unsigned int posX, unsigned int posY)
//{
//	int tempPosX = posX - 1;
//	float tempVal;
//	mLook_Neg_X_oneStep_trueVal = false;
//
//	if (tempPosX >= 0)
//	{
//
//		tempVal = mMapX_forRemap_upsampled_correctDistortion.at<float>(posY, tempPosX);
//
//		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
//		{
//			mValOneStep_negX = tempVal;
//			mLook_Neg_X_oneStep_trueVal = true;
//		}
//	}
//
//}
//
//// look positiv x direction
//void Distortion::lookPositiv_X_multiSteps_RemapX_correctDistortion(unsigned int posX, unsigned int posY)
//{
//	int tempPosX = posX + 1;
//	float tempVal;
//	mLook_Pos_X.setTrueVal(false);
//
//	if (tempPosX < mSizeMatrix_horizontal)
//	{
//		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
//		{
//			tempVal = mMapX_forRemap_upsampled_correctDistortion.at<float>(posY, tempPosX);
//
//			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
//			{
//				mLook_Pos_X.setTrueVal(true);
//				mLook_Pos_X.setPos_X(tempPosX);
//				mLook_Pos_X.setPos_Y(posY);
//				mLook_Pos_X.setVal(tempVal);
//				i = mMaxStepToLook;
//			}
//
//			++tempPosX;
//			if (tempPosX >= mSizeMatrix_horizontal)
//			{
//				i = mMaxStepToLook;
//			}
//
//		}
//
//
//	}
//}
//void Distortion::lookPositive_X_oneStep_RemapX_correctDistortion(unsigned int posX, unsigned int posY)
//{
//	int tempPosX = posX + 1;
//	float tempVal;
//	mLook_Pos_X_oneStep_trueVal = false;
//
//	if (tempPosX < mSizeMatrix_horizontal)
//	{
//		tempVal = mMapX_forRemap_upsampled_correctDistortion.at<float>(posY, tempPosX);
//
//		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
//		{
//			mValOneStep_posX = tempVal;
//			mLook_Pos_X_oneStep_trueVal = true;
//		}
//
//	}
//}
//
//// look negativ y direction
//void Distortion::lookNegativ_Y_multiSteps_RemapX_correctDistortion(unsigned int posX, unsigned int posY)
//{
//	int tempPosY = posY - 1;
//	float tempVal;
//	mLook_Neg_Y.setTrueVal(false);
//
//	if (tempPosY >= 0)
//	{
//		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
//		{
//			tempVal = mMapX_forRemap_upsampled_correctDistortion.at<float>(tempPosY, posX);
//			// just for debugging
//			// std::cout << tempVal << std::endl;
//
//			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
//			{
//				mLook_Neg_Y.setTrueVal(true);
//				mLook_Neg_Y.setPos_X(posX);
//				mLook_Neg_Y.setPos_Y(tempPosY);
//				mLook_Neg_Y.setVal(tempVal);
//				i = mMaxStepToLook;
//			}
//
//			--tempPosY;
//			if (tempPosY < 0)
//			{
//				i = mMaxStepToLook;
//			}
//
//		}
//
//
//	}
//}
//void Distortion::lookNegative_Y_oneStep_RemapX_correctDistortion(unsigned int posX, unsigned int posY)
//{
//	int tempPosY = posY - 1;
//	float tempVal;
//	mLook_Neg_Y_oneStep_trueVal = false;
//
//	if (tempPosY >= 0)
//	{
//
//		tempVal = mMapX_forRemap_upsampled_correctDistortion.at<float>(tempPosY, posX);
//
//		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
//		{
//			mValOneStep_negY = tempVal;
//			mLook_Neg_Y_oneStep_trueVal = true;
//		}
//	}
//}
//
//// look positiv y direction
//void Distortion::lookPositiv_Y_multiSteps_RemapX_correctDistortion(unsigned int posX, unsigned int posY)
//{
//	int tempPosY = posY + 1;
//	float tempVal;
//	mLook_Pos_Y.setTrueVal(false);
//
//	if (tempPosY < mSizeMatrix_vertical)
//	{
//		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
//		{
//			tempVal = mMapX_forRemap_upsampled_correctDistortion.at<float>(tempPosY, posX);
//
//			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
//			{
//				mLook_Pos_Y.setTrueVal(true);
//				mLook_Pos_Y.setPos_X(posX);
//				mLook_Pos_Y.setPos_Y(tempPosY);
//				mLook_Pos_Y.setVal(tempVal);
//				i = mMaxStepToLook;
//			}
//
//			++tempPosY;
//			if (tempPosY >= mSizeMatrix_vertical)
//			{
//				i = mMaxStepToLook;
//			}
//
//		}
//
//
//	}
//}
//void Distortion::lookPositive_Y_oneStep_RemapX_correctDistortion(unsigned int posX, unsigned int posY)
//{
//	int tempPosY = posY + 1;
//	float tempVal;
//	mLook_Pos_Y_oneStep_trueVal = false;
//
//	if (tempPosY < mSizeMatrix_vertical)
//	{
//		tempVal = mMapX_forRemap_upsampled_correctDistortion.at<float>(tempPosY, posX);
//
//		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
//		{
//			mValOneStep_posY = tempVal;
//			mLook_Pos_Y_oneStep_trueVal = true;
//		}
//
//	}
//}

//// *** bilinear interpolation to fill holes in distortion map correctDistortion --> RemapY
//void Distortion::bilinearInterpolToFillHolesInDistortionMap_RemapY_correctDistortion()
//{
//	mMaxIterationBilinInterpol = 3;
//	mToleranceToCheckZero = 0.0000000001;
//	mMapY_forRemap_upsampled_correctDistortion = mMapY_forRemap.clone();
//	mSizeMatrix_horizontal = mMapY_forRemap_upsampled_correctDistortion.size().width;
//	mSizeMatrix_vertical = mMapY_forRemap_upsampled_correctDistortion.size().height;
//	mMaxStepToLook = 4;
//
//	bool checker = true;
//	unsigned int maxStepToLook = 3;
//	while (checker)
//	{
//		horizontalInterpolation_oneStep_RemapY_correctDistortion();
//		verticalInterpolation_oneStep_RemapY_correctDistortion();
//
//		if (mFilledPoints_horizontal < mToleranceToCheckZero && mFilledPoints_vertical < mToleranceToCheckZero) // there is no improvement
//		{
//			holizontal_bilinear_Interpolation_RemapY_correctDistortion();
//			vertical_bilinear_Interpolation_RemapY_correctDistortion();
//
//			if (maxStepToLook > mMaxIterationBilinInterpol)
//			{
//				checker = false;
//			}
//			++maxStepToLook;
//		}
//	}
//}
//
//void Distortion::holizontal_bilinear_Interpolation_RemapY_correctDistortion()
//{
//	mFilledPoints_horizontal = 0;
//	float tempValue{};
//
//
//	for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix_vertical; ++verticalPos)
//	{
//		for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix_horizontal; ++horizontalPos)
//		{
//			tempValue = mMapY_forRemap_upsampled_correctDistortion.at<float>(verticalPos, horizontalPos);
//			// just for debugging 
//			// std::cout << tempValue << std::endl;
//
//			if (std::abs(tempValue) < mToleranceToCheckZero)
//			{
//				lookNegativ_X_multiSteps_RemapY_correctDistortion(horizontalPos, verticalPos);
//				if (mLook_Neg_X.getTrueVal())
//				{
//					lookPositiv_X_multiSteps_RemapY_correctDistortion(horizontalPos, verticalPos);
//				}
//
//				if (mLook_Neg_X.getTrueVal() && mLook_Pos_X.getTrueVal()) // calculate new value in OPD matrix
//				{
//					// see: https://de.wikipedia.org/wiki/Bilineare_Filterung
//
//					tempValue = (float)(mLook_Pos_X.getPos_X() - horizontalPos) / (mLook_Pos_X.getPos_X() - mLook_Neg_X.getPos_X()) * mLook_Neg_X.getVal() + (float)(horizontalPos - mLook_Neg_X.getPos_X()) / (mLook_Pos_X.getPos_X() - mLook_Neg_X.getPos_X()) * mLook_Pos_X.getVal();
//
//					mMapY_forRemap_upsampled_correctDistortion.at<float>(verticalPos, horizontalPos) = tempValue;
//					++mFilledPoints_horizontal;
//				}
//			}
//		}
//	}
//}
//
//void Distortion::horizontalInterpolation_oneStep_RemapY_correctDistortion()
//{
//	mFilledPoints_horizontal = 0;
//	float tempValue{};
//
//	for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix_vertical; ++verticalPos)
//	{
//		for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix_horizontal; ++horizontalPos)
//		{
//			tempValue = mMapY_forRemap_upsampled_correctDistortion.at<float>(verticalPos, horizontalPos);
//
//			if (std::abs(tempValue) < mToleranceToCheckZero)
//			{
//				lookPositive_X_oneStep_RemapY_correctDistortion(horizontalPos, verticalPos);
//				if (mLook_Pos_X_oneStep_trueVal)
//				{
//					lookNegativ_X_oneStep_RemapY_correctDistortion(horizontalPos, verticalPos);
//				}
//
//				if (mLook_Neg_X_oneStep_trueVal && mLook_Pos_X_oneStep_trueVal) // calculate new value in OPD matrix
//				{
//					tempValue = (mValOneStep_posX + mValOneStep_negX) / 2;
//
//					mMapY_forRemap_upsampled_correctDistortion.at<float>(verticalPos, horizontalPos) = tempValue;
//					++mFilledPoints_horizontal;
//				}
//
//				if (mLook_Pos_X_oneStep_trueVal)
//				{
//					++horizontalPos;
//				}
//			}
//		}
//	}
//}
//
//void Distortion::vertical_bilinear_Interpolation_RemapY_correctDistortion()
//{
//	mFilledPoints_vertical = 0;
//	float tempValue{};
//
//	for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix_horizontal; ++horizontalPos)
//	{
//		for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix_vertical; ++verticalPos)
//		{
//			tempValue = mMapY_forRemap_upsampled_correctDistortion.at<float>(verticalPos, horizontalPos);
//			// just for debugging
//			//std::cout << tempValue << std::endl;
//
//			if (std::abs(tempValue) < mToleranceToCheckZero)
//			{
//				lookNegativ_Y_multiSteps_RemapY_correctDistortion(horizontalPos, verticalPos);
//				if (mLook_Neg_Y.getTrueVal())
//				{
//					lookPositiv_Y_multiSteps_RemapY_correctDistortion(horizontalPos, verticalPos);
//				}
//
//				if (mLook_Neg_Y.getTrueVal() && mLook_Pos_Y.getTrueVal()) // calculate new value in OPD matrix
//				{
//					// see: https://de.wikipedia.org/wiki/Bilineare_Filterung
//
//					tempValue = (float)(mLook_Pos_Y.getPos_Y() - verticalPos) / (mLook_Pos_Y.getPos_Y() - mLook_Neg_Y.getPos_Y()) * mLook_Neg_Y.getVal() + (float)(verticalPos - mLook_Neg_Y.getPos_Y()) / (mLook_Pos_Y.getPos_Y() - mLook_Neg_Y.getPos_Y()) * mLook_Pos_Y.getVal();
//
//					mMapY_forRemap_upsampled_correctDistortion.at<float>(verticalPos, horizontalPos) = tempValue;
//					++mFilledPoints_vertical;
//				}
//			}
//		}
//	}
//
//}
//void Distortion::verticalInterpolation_oneStep_RemapY_correctDistortion()
//{
//	mFilledPoints_vertical = 0;
//	float tempValue{};
//
//	for (unsigned int horizontalPos = 0; horizontalPos < mSizeMatrix_horizontal; ++horizontalPos)
//	{
//		for (unsigned int verticalPos = 0; verticalPos < mSizeMatrix_vertical; ++verticalPos)
//		{
//			tempValue = mMapY_forRemap_upsampled_correctDistortion.at<float>(verticalPos, horizontalPos);
//
//			if (std::abs(tempValue) < mToleranceToCheckZero)
//			{
//				lookPositive_Y_oneStep_RemapY_correctDistortion(horizontalPos, verticalPos);
//				if (mLook_Pos_Y_oneStep_trueVal)
//				{
//					lookNegative_Y_oneStep_RemapY_correctDistortion(horizontalPos, verticalPos);
//				}
//
//				if (mLook_Neg_Y_oneStep_trueVal && mLook_Pos_Y_oneStep_trueVal) // calculate new value in OPD matrix
//				{
//					tempValue = (mValOneStep_posY + mValOneStep_negY) / 2;
//
//					mMapY_forRemap_upsampled_correctDistortion.at<float>(verticalPos, horizontalPos) = tempValue;
//					++mFilledPoints_vertical;
//				}
//
//				if (mLook_Pos_Y_oneStep_trueVal)
//				{
//					++verticalPos;
//				}
//			}
//		}
//	}
//}
//
//// look negativ x direction
//void Distortion::lookNegativ_X_multiSteps_RemapY_correctDistortion(unsigned int posX, unsigned int posY)
//{
//	int tempPosX = posX - 1;
//	float tempVal;
//	mLook_Neg_X.setTrueVal(false);
//
//	if (tempPosX >= 0)
//	{
//		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
//		{
//			tempVal = mMapY_forRemap_upsampled_correctDistortion.at<float>(posY, tempPosX);
//
//			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
//			{
//				mLook_Neg_X.setTrueVal(true);
//				mLook_Neg_X.setPos_X(tempPosX);
//				mLook_Neg_X.setPos_Y(posY);
//				mLook_Neg_X.setVal(tempVal);
//				i = mMaxStepToLook;
//			}
//
//
//			--tempPosX;
//			if (tempPosX < 0)
//			{
//				i = mMaxStepToLook;
//			}
//
//		}
//
//
//	}
//}
//
//void Distortion::lookNegativ_X_oneStep_RemapY_correctDistortion(unsigned int posX, unsigned int posY)
//{
//	int tempPosX = posX - 1;
//	float tempVal;
//	mLook_Neg_X_oneStep_trueVal = false;
//
//	if (tempPosX >= 0)
//	{
//
//		tempVal = mMapY_forRemap_upsampled_correctDistortion.at<float>(posY, tempPosX);
//
//		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
//		{
//			mValOneStep_negX = tempVal;
//			mLook_Neg_X_oneStep_trueVal = true;
//		}
//	}
//
//}
//
//// look positiv x direction
//void Distortion::lookPositiv_X_multiSteps_RemapY_correctDistortion(unsigned int posX, unsigned int posY)
//{
//	int tempPosX = posX + 1;
//	float tempVal;
//	mLook_Pos_X.setTrueVal(false);
//
//	if (tempPosX < mSizeMatrix_horizontal)
//	{
//		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
//		{
//			tempVal = mMapY_forRemap_upsampled_correctDistortion.at<float>(posY, tempPosX);
//
//			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
//			{
//				mLook_Pos_X.setTrueVal(true);
//				mLook_Pos_X.setPos_X(tempPosX);
//				mLook_Pos_X.setPos_Y(posY);
//				mLook_Pos_X.setVal(tempVal);
//				i = mMaxStepToLook;
//			}
//
//			++tempPosX;
//			if (tempPosX >= mSizeMatrix_horizontal)
//			{
//				i = mMaxStepToLook;
//			}
//
//		}
//
//
//	}
//}
//void Distortion::lookPositive_X_oneStep_RemapY_correctDistortion(unsigned int posX, unsigned int posY)
//{
//	int tempPosX = posX + 1;
//	float tempVal;
//	mLook_Pos_X_oneStep_trueVal = false;
//
//	if (tempPosX < mSizeMatrix_horizontal)
//	{
//		tempVal = mMapY_forRemap_upsampled_correctDistortion.at<float>(posY, tempPosX);
//
//		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
//		{
//			mValOneStep_posX = tempVal;
//			mLook_Pos_X_oneStep_trueVal = true;
//		}
//
//	}
//}
//
//// look negativ y direction
//void Distortion::lookNegativ_Y_multiSteps_RemapY_correctDistortion(unsigned int posX, unsigned int posY)
//{
//	int tempPosY = posY - 1;
//	float tempVal;
//	mLook_Neg_Y.setTrueVal(false);
//
//	if (tempPosY >= 0)
//	{
//		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
//		{
//			tempVal = mMapY_forRemap_upsampled_correctDistortion.at<float>(tempPosY, posX);
//			// just for debugging
//			// std::cout << tempVal << std::endl;
//
//			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
//			{
//				mLook_Neg_Y.setTrueVal(true);
//				mLook_Neg_Y.setPos_X(posX);
//				mLook_Neg_Y.setPos_Y(tempPosY);
//				mLook_Neg_Y.setVal(tempVal);
//				i = mMaxStepToLook;
//			}
//
//			--tempPosY;
//			if (tempPosY < 0)
//			{
//				i = mMaxStepToLook;
//			}
//
//		}
//
//
//	}
//}
//void Distortion::lookNegative_Y_oneStep_RemapY_correctDistortion(unsigned int posX, unsigned int posY)
//{
//	int tempPosY = posY - 1;
//	float tempVal;
//	mLook_Neg_Y_oneStep_trueVal = false;
//
//	if (tempPosY >= 0)
//	{
//
//		tempVal = mMapY_forRemap_upsampled_correctDistortion.at<float>(tempPosY, posX);
//
//		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
//		{
//			mValOneStep_negY = tempVal;
//			mLook_Neg_Y_oneStep_trueVal = true;
//		}
//	}
//}
//
//// look positiv y direction
//void Distortion::lookPositiv_Y_multiSteps_RemapY_correctDistortion(unsigned int posX, unsigned int posY)
//{
//	int tempPosY = posY + 1;
//	float tempVal;
//	mLook_Pos_Y.setTrueVal(false);
//
//	if (tempPosY < mSizeMatrix_vertical)
//	{
//		for (unsigned int i = 0; i < mMaxStepToLook; ++i)
//		{
//			tempVal = mMapY_forRemap_upsampled_correctDistortion.at<float>(tempPosY, posX);
//
//			if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
//			{
//				mLook_Pos_Y.setTrueVal(true);
//				mLook_Pos_Y.setPos_X(posX);
//				mLook_Pos_Y.setPos_Y(tempPosY);
//				mLook_Pos_Y.setVal(tempVal);
//				i = mMaxStepToLook;
//			}
//
//			++tempPosY;
//			if (tempPosY >= mSizeMatrix_vertical)
//			{
//				i = mMaxStepToLook;
//			}
//
//		}
//
//
//	}
//}
//void Distortion::lookPositive_Y_oneStep_RemapY_correctDistortion(unsigned int posX, unsigned int posY)
//{
//	int tempPosY = posY + 1;
//	float tempVal;
//	mLook_Pos_Y_oneStep_trueVal = false;
//
//	if (tempPosY < mSizeMatrix_vertical)
//	{
//		tempVal = mMapY_forRemap_upsampled_correctDistortion.at<float>(tempPosY, posX);
//
//		if (std::abs(tempVal) > mToleranceToCheckZero) // the value is not zero
//		{
//			mValOneStep_posY = tempVal;
//			mLook_Pos_Y_oneStep_trueVal = true;
//		}
//
//	}
//}