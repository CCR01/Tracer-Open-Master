#include "Images.h"
#include "..\LowLevelTracing\Math_LLT.h"

// load an image to compare
cv::Mat Images::loadAnImage_Gray(const std::string fileLocation, const std::string fileName)
{

	std::string type = ".png";

	int sizeLocEx = fileLocation.size() - 1;
	char lastCharLocEx = fileLocation[sizeLocEx];
	std::string holeFile;
	if (lastCharLocEx == '/')
	{
		holeFile = fileLocation + fileName + type;
	}
	else
	{
		holeFile = fileLocation + "/" + fileName + type;
	}


	cv::Mat image = cv::imread(holeFile, CV_LOAD_IMAGE_GRAYSCALE);

	// check if the image was loaded correctly
	if (!image.data)
	{
		std::cout << "Could not open or find the image" << std::endl;
	}

	return image;
}

// load a color image
cv::Mat Images::loadAnImage_Color(const std::string fileLocation, const std::string fileName)
{
	std::string type = ".png";

	int sizeLocEx = fileLocation.size() - 1;
	char lastCharLocEx = fileLocation[sizeLocEx];
	std::string holeFile;
	if (lastCharLocEx == '/')
	{
		holeFile = fileLocation + fileName + type;
	}
	else
	{
		holeFile = fileLocation + "/" + fileName + type;
	}


	cv::Mat image = cv::imread(holeFile, CV_LOAD_IMAGE_COLOR);

	// check if the image was loaded correctly
	if (!image.data)
	{
		std::cout << "Could not open or find the image" << std::endl;
	}

	return image;
}

// resize two images
cv::Mat Images::resizeImage(cv::Mat inputImage, cv::Size targetSize, real scaleX, real scaleY, int interpolation)
{
	cv::Mat returnImage = cv::Mat::zeros(targetSize, inputImage.type());

	if (inputImage.size() != targetSize)
	{
		cv::resize(inputImage, returnImage, targetSize, scaleX, scaleY, interpolation);
	}

	else
	{
		returnImage = inputImage;
	}

	return returnImage;
}

// Calculates the per-element absolute difference between two arrays
cv::Mat Images::PerElementAbsDifference(const cv::Mat& image1, const cv::Mat& image2)
{
	cv::Mat returnImage = cv::Mat::zeros(image1.size(), image1.type());

	cv::absdiff(image1, image2, returnImage);

	return returnImage;

}

real Images::calcSumMatrix(const cv::Mat& matrix)
{

	real sumMatrx_0 = cv::sum(matrix)[0];
	real sumMatrx_1 = cv::sum(matrix)[1];
	real sumMatrx_2 = cv::sum(matrix)[2];

	real sum = sumMatrx_0; + sumMatrx_1 + sumMatrx_2;

	return sum;
	
}

// show an image
void Images::showImage_inputReal_normTheImage(const cv::String winname, cv::Mat ima)
{
	cv::Mat showIma = ima.clone();
	std::string imaType = getTypeImageC_VMat(ima);

	// normalize the image to show
	
	
	cv::normalize(showIma, showIma, 0.0, 1.0, cv::NORM_MINMAX, CV_64FC3);

	namedWindow(winname, CV_WINDOW_FREERATIO);
	resizeWindow(winname, showIma.cols, showIma.rows);
	imshow(winname, showIma);
	cv::waitKey(0);

	//just for debugging
	// saveImage("..", "savedIma", "png", imaToShow);
}

// show an image
void Images::showImage_inputReal_normImaByROI_inPercent(const cv::String winname, cv::Mat ima, real percent)
{
	cv::Mat showIma = ima.clone();
	std::string imaType = getTypeImageC_VMat(ima);


	unsigned int height = ima.size().height;
	unsigned int width = ima.size().width;

	unsigned int startX = percent * width / 100.0;
	unsigned int startY = percent * height / 100.0;
	unsigned int heighttROI = height - 2 * startY;
	unsigned int widthROI = width - 2 * startX;


	cv::Rect roi;
	roi.x = startX;
	roi.y = startY;
	roi.width = widthROI;
	roi.height = heighttROI;

	real min{};
	real max{};
	cv::minMaxLoc(showIma(roi), &min, &max);

	showIma = showIma * 1.0 / max;

	namedWindow(winname, CV_WINDOW_FREERATIO);
	resizeWindow(winname, showIma.cols, showIma.rows);
	imshow(winname, showIma);
	cv::waitKey(0);

	//just for debugging
	// saveImage("..", "savedIma", "png", imaToShow);
}

// show an image
void Images::showImage_inputUint8(const cv::String winname, cv::Mat ima)
{
	cv::Mat showIma = ima.clone();
	std::string imaType = getTypeImageC_VMat(showIma);

	// normalize the image to show
	//cv::normalize(showIma, showIma, 0, 255, cv::NORM_MINMAX);

	namedWindow(winname, CV_WINDOW_FREERATIO);
	resizeWindow(winname, showIma.cols, showIma.rows);
	imshow(winname, showIma);
	cv::waitKey(0);

	//just for debugging
	// saveImage("..", "savedIma", "png", imaToShow);
}

// show an image
void Images::showImage_inputUint8_normImaByROI_inPercent(const cv::String winname, cv::Mat ima, real percent )
{
	cv::Mat showIma = ima.clone();

	unsigned int height = ima.size().height;
	unsigned int width = ima.size().width;

	unsigned int startX = percent * width / 100.0;
	unsigned int startY = percent * height / 100.0;
	unsigned int heighttROI = height - 2 * startY;
	unsigned int widthROI = width - 2 * startX;


	cv::Rect roi;
	roi.x = startX;
	roi.y = startY;
	roi.width = widthROI;
	roi.height = heighttROI;

	real min{};
	real max{};
	showIma.convertTo(showIma, CV_64F);
	cv::minMaxLoc(showIma(roi), &min, &max);

	double ratio = 1.0 / max;
	
	showIma = showIma * ratio;

	showIma = showIma * 255;
	showIma.convertTo(showIma, CV_8U);
	

	namedWindow(winname, CV_WINDOW_FREERATIO);
	resizeWindow(winname, showIma.cols, showIma.rows);
	imshow(winname, showIma);
	cv::waitKey(0);

	//just for debugging
	// saveImage("..", "savedIma", "png", imaToShow);
}

cv::Mat Images::convertImage_64FC3_to_CV_8UC3(const cv::Mat imaToConvert)
{
	cv::Mat returnConvertedIma{};
	real min{};
	real max{};
	cv::minMaxLoc(imaToConvert, &min, &max);

	double ratio = 255.0 / max;
	cv::Mat scaledIma = imaToConvert * ratio;


	scaledIma.convertTo(returnConvertedIma, CV_8UC3);

	return returnConvertedIma;
}

cv::Mat Images::convertImage_64FC1_to_CV_8UC1(const cv::Mat imaToConvert)
{
	cv::Mat returnConvertedIma{};
	real min{};
	real max{};
	cv::minMaxLoc(imaToConvert, &min, &max);

	double ratio = 255.0 / max;
	cv::Mat scaledIma = imaToConvert * ratio;

	

	scaledIma.convertTo(returnConvertedIma, CV_8UC1);

	return returnConvertedIma;
}

std::string Images::getTypeImageC_VMat(cv::Mat matrix)
{

	int imgTypeInt = matrix.type();

	int numImgTypes = 35; // 7 base types, with five channel options each (none or C1, ..., C4)

	int enum_ints[] = { CV_8U,  CV_8UC1,  CV_8UC2,  CV_8UC3,  CV_8UC4, // CV_8U is unsigned 8bit/pixel - ie a pixel can have values 0-255
						CV_8S,  CV_8SC1,  CV_8SC2,  CV_8SC3,  CV_8SC4,
						CV_16U, CV_16UC1, CV_16UC2, CV_16UC3, CV_16UC4,
						CV_16S, CV_16SC1, CV_16SC2, CV_16SC3, CV_16SC4,
						CV_32S, CV_32SC1, CV_32SC2, CV_32SC3, CV_32SC4,
						CV_32F, CV_32FC1, CV_32FC2, CV_32FC3, CV_32FC4, // CV_32F is float - the pixel can have any value between 0-1.0
						CV_64F, CV_64FC1, CV_64FC2, CV_64FC3, CV_64FC4 }; // CV_64FC1 contains elements of type double, not float

	std::string enum_strings[] = { "CV_8U",  "CV_8UC1",  "CV_8UC2",  "CV_8UC3",  "CV_8UC4",
									"CV_8S",  "CV_8SC1",  "CV_8SC2",  "CV_8SC3",  "CV_8SC4",
									"CV_16U", "CV_16UC1", "CV_16UC2", "CV_16UC3", "CV_16UC4",
									"CV_16S", "CV_16SC1", "CV_16SC2", "CV_16SC3", "CV_16SC4",
									"CV_32S", "CV_32SC1", "CV_32SC2", "CV_32SC3", "CV_32SC4",
									"CV_32F", "CV_32FC1", "CV_32FC2", "CV_32FC3", "CV_32C4",
									"CV_64F", "CV_64FC1", "CV_64FC2", "CV_64FC3", "CV_64FC4" };

	for (int i = 0; i < numImgTypes; i++)
	{
		if (imgTypeInt == enum_ints[i]) return enum_strings[i];
	}

	return "unknown image type";

}

// save an image
void Images::saveImage_normalized(std::string fileLocation, std::string nameImage, std::string typeIma, const cv::Mat image)
{
	std::string localtionAndName = fileLocation + "/" + nameImage + "." + typeIma;

	cv::Mat imaToSave = image.clone();
	std::string imaType = getTypeImageC_VMat(image);

	// CV_64FC3
	if (imaType == "CV_64FC3")
	{	
		// convert to 8UC1
		imaToSave = convertImage_64FC3_to_CV_8UC3(image);

		// normalize the image to show
		//cv::normalize(imaToSave, imaToSave, 0, 255, cv::NORM_MINMAX);
	}

	// CV_64FC or CV_64FC1
	if (imaType == "CV_64F" || imaType == "CV_64FC")
	{
		// convert to 8UC1
		imaToSave = convertImage_64FC1_to_CV_8UC1(image);

		// normalize the image to show
		//cv::normalize(imaToSave, imaToSave, 0, 255, cv::NORM_MINMAX);
	}

	//Images::showImage_inputReal("image", imaToSave);

	cv::normalize(imaToSave, imaToSave, 0, 255, cv::NORM_MINMAX);

	cv::imwrite(localtionAndName, imaToSave);

}

void Images::saveImage_inputReal_multiplyBy(std::string fileLocation, std::string nameImage, std::string typeIma, const cv::Mat image, real factor)
{
	cv::Mat saveIma = image.clone();

	cv::normalize(saveIma, saveIma, 0.0, 1.0, cv::NORM_MINMAX);


	saveIma = saveIma * factor;
	saveIma = saveIma * 255.0;
	cv::Mat saveImaUint8;
	saveIma.convertTo(saveImaUint8, CV_8UC3);
	std::string localtionAndName = fileLocation + "/" + nameImage + "." + typeIma;
	cv::imwrite(localtionAndName, saveImaUint8);

	//just for debugging
	// saveImage("..", "savedIma", "png", imaToShow);
}

void Images::saveImage_inputReal_normByROI_percent(std::string fileLocation, std::string nameImage, std::string typeIma, const cv::Mat image, real percent)
{
	cv::Mat imaToSave = image.clone();
	std::string localtionAndName = fileLocation + "/" + nameImage + "." + typeIma;

	unsigned int height = imaToSave.size().height;
	unsigned int width = imaToSave.size().width;

	unsigned int startX = percent * width / 100.0;
	unsigned int startY = percent * height / 100.0;
	unsigned int heighttROI = height - 2 * startY;
	unsigned int widthROI = width - 2 * startX;


	cv::Rect roi;
	roi.x = startX;
	roi.y = startY;
	roi.width = widthROI;
	roi.height = heighttROI;

	real min{};
	real max{};
	cv::minMaxLoc(imaToSave(roi), &min, &max);

	imaToSave = imaToSave * 1.0 / max;

	imaToSave = imaToSave * 255.0;
	cv::Mat saveImaUint8;
	imaToSave.convertTo(saveImaUint8, CV_8UC3);

	cv::imwrite(localtionAndName, saveImaUint8);
}

void Images::saveImage_inputUN8C3_normByROI_percent(std::string fileLocation, std::string nameImage, std::string typeIma, const cv::Mat image, real percent)
{
	cv::Mat imaToSave = image.clone();
	std::string localtionAndName = fileLocation + "/" + nameImage + "." + typeIma;

	unsigned int height = imaToSave.size().height;
	unsigned int width = imaToSave.size().width;

	unsigned int startX = percent * width / 100.0;
	unsigned int startY = percent * height / 100.0;
	unsigned int heighttROI = height - 2 * startY;
	unsigned int widthROI = width - 2 * startX;


	cv::Rect roi;
	roi.x = startX;
	roi.y = startY;
	roi.width = widthROI;
	roi.height = heighttROI;

	imaToSave.convertTo(imaToSave, CV_64FC3);


	imaToSave = imaToSave / 255;
	real min{};
	real max{};
	cv::minMaxLoc(imaToSave(roi), &min, &max);

	imaToSave = imaToSave * 1.0 / max;

	imaToSave = imaToSave * 255.0;
	cv::Mat saveImaUint8;
	imaToSave.convertTo(saveImaUint8, CV_8UC3);

	cv::imwrite(localtionAndName, imaToSave);
}

void Images::saveImageGray_UN8_normByROI_percent(std::string fileLocation, std::string nameImage, std::string typeIma, const cv::Mat image, real percent)
{
	cv::Mat imaToSave = image.clone();
	std::string localtionAndName = fileLocation + "/" + nameImage + "." + typeIma;

	unsigned int height = imaToSave.size().height;
	unsigned int width = imaToSave.size().width;

	unsigned int startX = percent * width / 100.0;
	unsigned int startY = percent * height / 100.0;
	unsigned int heighttROI = height - 2 * startY;
	unsigned int widthROI = width - 2 * startX;


	cv::Rect roi;
	roi.x = startX;
	roi.y = startY;
	roi.width = widthROI;
	roi.height = heighttROI;

	imaToSave.convertTo(imaToSave, CV_64F);


	imaToSave = imaToSave / 255;
	real min{};
	real max{};
	cv::minMaxLoc(imaToSave(roi), &min, &max);

	imaToSave = imaToSave * 1.0 / max;

	imaToSave = imaToSave * 255.0;
	cv::Mat saveImaUint8;
	imaToSave.convertTo(saveImaUint8, CV_8U);

	cv::imwrite(localtionAndName, imaToSave);
}

// calculate improvement
real Images::calcImprovement_noNorming(const cv::Mat& sharpImage, const cv::Mat& simulatedImage, const cv::Mat& improvetImage)
{
	real maxVariance = Images::calcSumMatrix(Images::PerElementAbsDifference(sharpImage, simulatedImage));
	real reducedVariance = Images::calcSumMatrix(Images::PerElementAbsDifference(sharpImage, improvetImage));

	real returnVariance = maxVariance / reducedVariance;

	return returnVariance;
}


bool Images::checkImagesSame_64FC1(cv::Mat ima1, cv::Mat ima2, real tolerance)
{
	unsigned int widthIma1 = ima1.size().width;
	unsigned int heightIma1 = ima1.size().height;

	unsigned int widthIma2 = ima2.size().height;
	unsigned int heightIma2 = ima2.size().height;

	real tempValIma1{};
	real tempValIma2{};
	bool tempBool{};

	if (widthIma1 != widthIma2 || heightIma1 != heightIma2)
	{
		return false;
	}

	for (unsigned int i = 0; i < widthIma1; ++i)
	{
		for (unsigned int j = 0; j < heightIma1; ++j)
		{
			tempValIma1 = ima1.at<real>(i, j);
			tempValIma2 = ima2.at<real>(i, j);

			tempBool = Math::compareTwoNumbers_tolerance(tempValIma1, tempValIma2, tolerance);

			if (tempBool == false)
			{
				return false;
			}
		}
	}

	return true;

}

// calcualte difference
int Images::calcAbsDiff_BGR_uint8(const cv::Mat& sharpIma, const cv::Mat& filteredIma, real percent)
{
	cv::Mat tempDifMat;
	cv::Rect roiToCalcDif;

	unsigned int height = sharpIma.size().height;
	unsigned int width = sharpIma.size().width;

	unsigned int startX = percent * width / 100.0;
	unsigned int startY = percent * height / 100.0;
	unsigned int heighttROI = height - 2 * startY;
	unsigned int widthROI = width - 2 * startX;

	roiToCalcDif.x = startX;
	roiToCalcDif.y = startY;
	roiToCalcDif.width = widthROI;
	roiToCalcDif.height = heighttROI;

	//// debug
	//Images::showImage_inputUint8("sharpIma", sharpIma);
	//Images::showImage_inputUint8("filteredIma", filteredIma);
	
	cv::absdiff(sharpIma(roiToCalcDif), filteredIma(roiToCalcDif), tempDifMat);

	
	
	int dif = cv::sum(tempDifMat)[0] + cv::sum(tempDifMat)[1] + cv::sum(tempDifMat)[2];
	return dif;
}

// calculate total improvement BGR
real Images::calcImprovementBGR(cv::Mat sharpIma, cv::Mat blueredIma, cv::Mat filteredIma, real percent)
{
	std::vector<cv::Mat> sharpImages = Images::splitImageBGR(sharpIma);
	std::vector<cv::Mat> blueredImages = Images::splitImageBGR(blueredIma);
	std::vector<cv::Mat> filteredImages = Images::splitImageBGR(filteredIma);

	real imp_blue = calcImprovementGray(sharpImages[0], blueredImages[0], filteredImages[0], percent);
	real imp_green = calcImprovementGray(sharpImages[1], blueredImages[1], filteredImages[1], percent);
	real imp_red = calcImprovementGray(sharpImages[2], blueredImages[2], filteredImages[2], percent);


	//real differenceBluered = calcAbsDiff_BGR_uint8(sharpIma, blueredIma, percent);
	//real differenceFilteredIma = calcAbsDiff_BGR_uint8(sharpIma, filteredIma, percent);
	//real returnVariance = differenceBluered / differenceFilteredIma;

	real returnVariance = (imp_blue + imp_green + imp_red) / 3.0;
	return returnVariance;

}

real Images::calcImprovementGray(cv::Mat sharpIma, cv::Mat blueredIma, cv::Mat filteredIma, real percent)
{
	cv::Mat sharpIma_normed;
	cv::normalize(sharpIma, sharpIma_normed, 0.0, 255.0, cv::NORM_MINMAX, CV_8UC1);

	cv::Mat blueredIma_normed;
	cv::normalize(blueredIma, blueredIma_normed, 0.0, 255.0, cv::NORM_MINMAX, CV_8UC1);

	cv::Mat filteredIma_normed;
	cv::normalize(filteredIma, filteredIma_normed, 0.0, 255.0, cv::NORM_MINMAX, CV_8UC1);

	// roi
	unsigned int height = sharpIma.size().height;
	unsigned int width = sharpIma.size().width;
	unsigned int startX = percent * width / 100.0;
	unsigned int startY = percent * height / 100.0;
	unsigned int heighttROI = height - 2 * startY;
	unsigned int widthROI = width - 2 * startX;
	cv::Rect roiToCalcDif;
	roiToCalcDif.x = startX;
	roiToCalcDif.y = startY;
	roiToCalcDif.width = widthROI;
	roiToCalcDif.height = heighttROI;

	cv::Mat difMat_filtered;
	cv::absdiff(sharpIma_normed(roiToCalcDif), filteredIma_normed(roiToCalcDif), difMat_filtered);
	cv::Mat difMat_bluered;
	cv::absdiff(sharpIma_normed(roiToCalcDif), blueredIma_normed(roiToCalcDif), difMat_bluered);
	real differenceFilteredIma = cv::sum(difMat_filtered)[0];
	real differenceBluered = cv::sum(difMat_bluered)[0];
	real improvement = differenceBluered / differenceFilteredIma;

	return improvement;
}


// split the image in BGR
std::vector<cv::Mat> Images::splitImageBGR(cv::Mat imageBGR)
{
	std::vector<cv::Mat> imageVec_BGR;
	imageVec_BGR.resize(3);

	// sharp image
	cv::Mat channelSharpImage[3];
	cv::split(imageBGR, channelSharpImage);
	imageVec_BGR[0] = channelSharpImage[0];
	imageVec_BGR[1] = channelSharpImage[1];
	imageVec_BGR[2] = channelSharpImage[2];

	return imageVec_BGR;
}

// merge images
cv::Mat Images::mergeImages(std::vector<cv::Mat> image_vec)
{
	cv::Mat bgrImage;
	cv::merge(image_vec, bgrImage);

	return bgrImage;
}



// two images equal
bool Images::compateTwoImages(cv::Mat ima1, cv::Mat ima2, int tolerance)
{
	if ((ima1.rows != ima2.rows) || (ima1.cols != ima2.cols))
		return false;

	std::vector<cv::Mat> bgr_vec1;
	cv::split(ima1, bgr_vec1);

	std::vector<cv::Mat> bgr_vec2;
	cv::split(ima2, bgr_vec2);

	cv::Scalar sumB = cv::sum(bgr_vec2[0] - bgr_vec1[0]);
	cv::Scalar sumG = cv::sum(bgr_vec2[1] - bgr_vec1[1]);
	cv::Scalar sumR = cv::sum(bgr_vec2[2] - bgr_vec1[2]);


	bool checkBlue = std::abs(sumB[0]) < tolerance;
	bool checkGreen = std::abs(sumG[0]) < tolerance;
	bool checkRed = std::abs(sumR[0]) < tolerance;

	bool returnChecker = checkBlue && checkGreen && checkRed;

	return returnChecker;
}

// load an image and norm all colors between 0 and 255
void Images::loadImage_BGR_AndNormAllColors(std::string location, std::string name, std::string save_loc, std::string save_name)
{
	cv::Mat image = loadAnImage_Color(location, name);

	std::vector<cv::Mat> image_vec = splitImageBGR(image);

	// blue
	cv::Mat image_blue = image_vec[0];
	cv::Mat image_blue_normalize;
	cv::normalize(image_blue, image_blue_normalize, 0, 255, cv::NORM_MINMAX);

	// green
	cv::Mat image_green = image_vec[1];
	cv::Mat image_green_normalize;
	cv::normalize(image_green, image_green_normalize, 0, 255, cv::NORM_MINMAX);

	// red
	cv::Mat image_red = image_vec[2];
	cv::Mat image_red_normalize;
	cv::normalize(image_red, image_red_normalize, 0, 255, cv::NORM_MINMAX);

	std::vector<cv::Mat> normedIma_vec{ image_blue_normalize, image_green_normalize, image_red_normalize };

	cv::Mat mergeBGR_image = mergeImages(normedIma_vec);

	Images::saveImage_normalized(save_loc, save_name, "png", mergeBGR_image);
}