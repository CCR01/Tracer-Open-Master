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
void Images::showImage(std::string nameImage, cv::Mat image)
{
	cv::imshow(nameImage, image);
	cv::waitKey(0);

}

// save an image
void Images::saveImage(std::string const& fileLocation, std::string const& nameImage, cv::Mat const& image)
{
	std::string localtionAndName = fileLocation + nameImage;

	cv::imwrite(localtionAndName, image);

}

// calculate improvement
real Images::calcImprovement(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, cv::Mat const& improvetImage)
{
	real maxVariance = Images::calcSumMatrix(Images::PerElementAbsDifference(sharpImage, simulatedImage));
	real reducedVariance = Images::calcSumMatrix(Images::PerElementAbsDifference(sharpImage, improvetImage));

	real returnVariance = maxVariance / reducedVariance;

	return returnVariance;
}
