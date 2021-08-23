#include "ImproveImaQual_structs.h"
#include <iostream>
#include <fstream>

ContrastAndGammaStruct::ContrastAndGammaStruct() {};
ContrastAndGammaStruct::~ContrastAndGammaStruct() {};

// set image
void ContrastAndGammaStruct::setImage(cv::Mat const& image)
{
	mImage = image;
}
// get image
cv::Mat ContrastAndGammaStruct::getImage() const&
{
	return mImage;
}
//set best result
void ContrastAndGammaStruct::setQuality(double const& quality)
{
	mQuality = quality;
}
// get best result
real ContrastAndGammaStruct::getQuality() const&
{
	return mQuality;
}
// set improvement
void ContrastAndGammaStruct::setImprovement(real const& improvement)
{
	mImprovement = improvement;
}
// get improvement
real ContrastAndGammaStruct::getImprovement() const&
{
	return mImprovement;
}
// set alpha
void ContrastAndGammaStruct::setAlpha(real const& alpha)
{
	mAlpha = alpha;
}
// get alpha
real ContrastAndGammaStruct::getAlpha() const&
{
	return mAlpha;
}
// set beta
void ContrastAndGammaStruct::setBeta(real const& beta)
{
	mBeta = beta;
}
// get beta
real ContrastAndGammaStruct::getBeta() const&
{
	return mBeta;
}
// set gamma
void ContrastAndGammaStruct::setGamme(real const& gamma)
{
	mGamma = gamma;
}
// get gamma
real ContrastAndGammaStruct::getGamma() const&
{
	return mGamma;
}

// print parameters median blur
void ContrastAndGammaStruct::printPara_ContGamma_Struct() const&
{
	std::cout << "" << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "Contrast and GammaStruct" << std::endl;
	std::cout << "alpha: " << mAlpha << std::endl;
	std::cout << "beta: " << mBeta << std::endl;
	std::cout << "gamma: " << mGamma << std::endl;
	std::cout << "improvement " << mImprovement << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "" << std::endl;
}

// export as txt fiel
void ContrastAndGammaStruct::exportAsTXTfile()
{
	{
		std::ofstream file;
		file.open("ContrastAndGamma.txt", std::ios_base::app);
		if (file.is_open())
		{
			file << "" << std::endl;
			file << "___________________________________" << std::endl;
			file << "Contrast and GammaStruct" << std::endl;
			file << "alpha: " << mAlpha << std::endl;
			file << "beta: " << mBeta << std::endl;
			file << "gamma: " << mGamma << std::endl;
			file << "improvement " << mImprovement << std::endl;
			file << "___________________________________" << std::endl;
			file << "" << std::endl;
		}
		file.close();

	}
}


medianBlurStruct::medianBlurStruct() {};
medianBlurStruct::medianBlurStruct(cv::Mat const& image, real const& quality, int const& kernelSize) :
	mImage(image),
	mQuality(quality),
	mKernelSize(kernelSize)

{}
medianBlurStruct::~medianBlurStruct() {};

// set image
void medianBlurStruct::setImage(cv::Mat const& image)
{
	mImage = image;
}
// get image
cv::Mat medianBlurStruct::getImage() const&
{
	return mImage;
}
//set best result
void medianBlurStruct::setQuality(double const& quality)
{
	mQuality = quality;
}
// get best result
real medianBlurStruct::getQuality() const&
{
	return mQuality;
}
// set kernel size
void medianBlurStruct::setKernelSize(int const& kernelSize)
{
	mKernelSize = kernelSize;
}
// get kernel size
int medianBlurStruct::getKernelSize() const&
{
	return mKernelSize;
}


// set improvement
void medianBlurStruct::setImprovement(real const& improvement)
{
	mImprovement = improvement;
}
// get improvement
real medianBlurStruct::getImprovement() const&
{
	return mImprovement;
}

// print parameters median blur
void medianBlurStruct::printPara_MedianBlur_Struct() const&
{
	std::cout << "" << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "median blur" << std::endl;
	std::cout << "kernel size: " << mKernelSize << std::endl;
	std::cout << "improvement " << mImprovement << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "" << std::endl;
}

// export as txt fiel
void medianBlurStruct::exportAsTXTfile()
{
	std::ofstream file;
	file.open("medianBlur.txt", std::ios_base::app);
	if (file.is_open())
	{
		file << "" << std::endl;
		file << "___________________________________" << std::endl;
		file << "median blur parameter:" << std::endl;
		file << "kernel size: " << mKernelSize << std::endl;
		file << "improvement " << mImprovement << std::endl;
		file << "___________________________________" << std::endl;
		file << "" << std::endl;
	}
	file.close();

}






bilateralFilterStruct::bilateralFilterStruct() {};
bilateralFilterStruct::bilateralFilterStruct(cv::Mat image, real const& quality, int d, real sigmaColor, real sigmaSpace) :
	mImage(image),
	mQuality(quality),
	mD(d),
	mSigmaColor(sigmaColor),
	mSigmaSpace(sigmaSpace)
{};
bilateralFilterStruct::~bilateralFilterStruct() {};

// set image
void bilateralFilterStruct::setImage(cv::Mat const& image)
{
	mImage = image;
}
// get image
cv::Mat bilateralFilterStruct::getImage() const&
{
	return mImage;
}
// set quality
void bilateralFilterStruct::setQuality(real const& quality)
{
	mQuality = quality;
}
// get quality
real bilateralFilterStruct::getQuality() const&
{
	return mQuality;
}
// set d
void bilateralFilterStruct::setD(int const& d)
{
	mD = d;
}
// get d
int bilateralFilterStruct::getD() const&
{
	return mD;
}
// set sigmaColor
void bilateralFilterStruct::setSigmarColor(real const& sigmaColor)
{
	mSigmaColor = sigmaColor;
}
// get sigmaColo
real bilateralFilterStruct::getSigmaColor() const&
{
	return mSigmaColor;
}
// set sigmaSpace
void bilateralFilterStruct::setSigmaSpace(real const& sigmaSpace)
{
	mSigmaSpace = sigmaSpace;
}
// get sigmaSpace
real bilateralFilterStruct::getSigmaSpace() const&
{
	return mSigmaSpace;
}

// set boarder type
void bilateralFilterStruct::setBoarderType(int const& boarderType)
{
	mBoarderType = boarderType;
}
// get boarder type
int bilateralFilterStruct::getBoarderType() const&
{
	return mBoarderType;
}

// set improvement
void bilateralFilterStruct::setImprovement(real const& improvement)
{
	mImprovement = improvement;
}
// get improvement
real bilateralFilterStruct::getImprovement() const&
{
	return mImprovement;
}

// print parameters bilateral filter struct
void bilateralFilterStruct::printPara_BilateralFilter_Struct() const&
{
	std::cout << "" << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "bilateral filter" << std::endl;
	std::cout << "d: " << mD << std::endl;
	std::cout << "sigma color: " << mSigmaColor << std::endl;
	std::cout << "sigma space: " << mSigmaSpace << std::endl;
	std::cout << "bioarder type: " << mBoarderType << std::endl;
	std::cout << "improvement: " << mImprovement << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "" << std::endl;
}

// export as txt fiel
void bilateralFilterStruct::exportAsTXTfile()
{
	std::ofstream file;
	file.open("bilateralFilterStruct.txt", std::ios_base::app);
	if (file.is_open())
	{
		file << "" << std::endl;
		file << "___________________________________" << std::endl;
		file << "bilateral filter parameter:" << std::endl;
		file << "d: " << mD << std::endl;
		file << "sigma color: " << mSigmaColor << std::endl;
		file << "sigma space: " << mSigmaSpace << std::endl;
		file << "bioarder type: " << mBoarderType << std::endl;
		file << "improvement: " << mImprovement << std::endl;
		file << "___________________________________" << std::endl;
		file << "" << std::endl;
	}
	file.close();
}


