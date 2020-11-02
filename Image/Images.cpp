#include "Images.h"

// load an image to compare
cv::Mat Images::loadAnImage_Gray(std::string const& fileLocation, std::string const& fileName)
{
	std::string fileLocationAndName = fileLocation + fileName;
	cv::Mat image = cv::imread(fileLocationAndName, CV_LOAD_IMAGE_GRAYSCALE);

	// check if the image was loaded correctly
	if (!image.data)
	{
		std::cout << "Could not open or find the image" << std::endl;
	}

	return image;
}

// load a color image
cv::Mat Images::loadAnImage_Color(std::string const& fileLocation, std::string const& fileName)
{
	std::string fileLocationAndName = fileLocation + fileName;
	cv::Mat image = cv::imread(fileLocationAndName, CV_LOAD_IMAGE_COLOR);

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
cv::Mat Images::PerElementAbsDifference(cv::Mat const& image1, cv::Mat const& image2)
{
	cv::Mat returnImage = cv::Mat::zeros(image1.size(), image1.type());


	cv::absdiff(image1, image2, returnImage);

	return returnImage;

}

real Images::calcSumMatrix(cv::Mat const& matrix)
{
	real sumMatrx;
	sumMatrx = cv::sum(matrix)[0];

	return sumMatrx;
	
}

// show an image
void Images::showImage(const cv::String winname, cv::Mat& ima)
{
	
	std::string imaType = getTypeImageC_VMat(ima);

	// normalize the image to show
	cv::normalize(ima, ima, 0, 1, cv::NORM_MINMAX);

	namedWindow(winname, CV_WINDOW_FREERATIO);
	resizeWindow(winname, ima.cols, ima.rows);
	imshow(winname, ima);
	cv::waitKey(0);

	//just for debugging
	// saveImage("..", "savedIma", "png", imaToShow);
}

cv::Mat Images::convertImage_32FC3_to_CV_8UC3(const cv::Mat& imaToConvert)
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

cv::Mat Images::convertImage_32FC1_to_CV_8UC1(const cv::Mat& imaToConvert)
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
									"CV_32F", "CV_32FC1", "CV_32FC2", "CV_32FC3", "CV_32FC4",
									"CV_64F", "CV_64FC1", "CV_64FC2", "CV_64FC3", "CV_64FC4" };

	for (int i = 0; i < numImgTypes; i++)
	{
		if (imgTypeInt == enum_ints[i]) return enum_strings[i];
	}

	return "unknown image type";

}

// save an image
void Images::saveImage(std::string fileLocation, std::string nameImage, std::string typeIma, const cv::Mat& image)
{
	std::string localtionAndName = fileLocation + "/" + nameImage + "." + typeIma;

	cv::Mat imaToSave = image;
	std::string imaType = getTypeImageC_VMat(image);

	// CV_32FC3
	if (imaType == "CV_32FC3")
	{
		imaToSave = convertImage_32FC3_to_CV_8UC3(image);
	}
	// CV_32FC or CV_32FC1
	if (imaType == "CV_32F" || imaType == "CV_32FC")
	{
		imaToSave = convertImage_32FC1_to_CV_8UC1(image);
	}

	cv::imwrite(localtionAndName, imaToSave);

}

// calculate improvement
real Images::calcImprovement(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, cv::Mat const& improvetImage)
{
	real maxVariance = Images::calcSumMatrix(Images::PerElementAbsDifference(sharpImage, simulatedImage));
	real reducedVariance = Images::calcSumMatrix(Images::PerElementAbsDifference(sharpImage, improvetImage));

	real returnVariance = maxVariance / reducedVariance;

	return returnVariance;
}
