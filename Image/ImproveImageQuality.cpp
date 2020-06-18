#include "ImproveImageQuality.h"
#include "..\LowLevelTracing/Math_LLT.h"
#include "Images.h"
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
void ContrastAndGammaStruct::printPara_ContGamma_Struct() const &
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
void medianBlurStruct::printPara_MedianBlur_Struct() const &
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

detailEnhanceStruct::detailEnhanceStruct() {};
detailEnhanceStruct::detailEnhanceStruct(cv::Mat image, real const& quality, float const& sigmarS, float const& sigmarR):
	mImage(image),
	mQuality(quality),
	mSigmar_s(sigmarS),
	mSigmar_r(sigmarR)
{}

detailEnhanceStruct::~detailEnhanceStruct() {};

// set image
void detailEnhanceStruct::setImage(cv::Mat const& image)
{
	mImage = image;
}

// get image
cv::Mat detailEnhanceStruct::getImage() const&
{
	return mImage;
}

//set best result
void detailEnhanceStruct::setQuality(double const& quality)
{
	mQuality = quality;
}
// get best result
real detailEnhanceStruct::getQuality() const&
{
	return mQuality;
}
// set sigmar s
void detailEnhanceStruct::setSigmar_s(float const& sigmar_s)
{
	mSigmar_s = sigmar_s;
}
// get sigmar s
float detailEnhanceStruct::getSigmar_s() const&
{
	return mSigmar_s;
}
// set sigmar r
void detailEnhanceStruct::setSigmar_r(float const& sigmar_r)
{
	mSigmar_r = sigmar_r;
}
// get sigmar r
float detailEnhanceStruct::getSigmar_r() const&
{
	return mSigmar_r;
}

// set improvement
void detailEnhanceStruct::setImprovement(real const& improvement)
{
	mImprovement = improvement;
}
// get improvement
real detailEnhanceStruct::getImprovement() const&
{
	return mImprovement;
}

// print parameters detailEnhanceStruct
void detailEnhanceStruct::printPara_DetailEnhance_Struct() const &
{	
	std::cout << "" << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "detail enhance parameter:" << std::endl;
	std::cout << "sigma s: " << mSigmar_s << std::endl;
	std::cout << "sigma r: " << mSigmar_r << std::endl;
	std::cout << "improvement " << mImprovement << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << ""<< std::endl;

}

// export as txt fiel
void detailEnhanceStruct::exportAsTXTfile()
{
	std::ofstream file;
	file.open("detailEnhanceParameter.txt", std::ios_base::app);
	if (file.is_open())
	{
		file << "" << std::endl;
		file << "___________________________________" << std::endl;
		file << "detail enhance parameter:" << std::endl;
		file << "sigma s: " << mSigmar_s << std::endl;
		file << "sigma r: " << mSigmar_r << std::endl;
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
void bilateralFilterStruct::printPara_BilateralFilter_Struct() const &
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

unsharpMaskStruct::unsharpMaskStruct() {};
unsharpMaskStruct::unsharpMaskStruct(cv::Mat const& image, real const& quality, cv::Size const& kernelSize, real const& sigmaX, real const& sigmaY, real const& threshold, real const& amount, int const& boarderType) :
	mImage(image),
	mQuality(quality),
	mKernelSize(kernelSize),
	mSigmaX(sigmaX),
	mSigmaY(sigmaY),
	mThreshold(threshold),
	mAmoun(amount),
	mBoarderType(boarderType)
{};
unsharpMaskStruct::~unsharpMaskStruct() {};

// set image
void unsharpMaskStruct::setImage(cv::Mat const& image)
{
	mImage = image;
}
// get image
cv::Mat unsharpMaskStruct::getImage() const&
{
	return mImage;
}
// set quality
void unsharpMaskStruct::setQuality(real const& quality)
{
	mQuality = quality;
}
// get quality
real unsharpMaskStruct::getQuality() const&
{
	return mQuality;
}
// get kernel size
cv::Size unsharpMaskStruct::getKernelSize() const&
{
	return mKernelSize;
}
// set kernel size
void unsharpMaskStruct::setKernelSize(cv::Size const& kernelSize)
{
	mKernelSize = kernelSize;
}
// get sigma x
real unsharpMaskStruct::getSigmaX() const&
{
	return mSigmaX;
}
// set sigma x
void unsharpMaskStruct::setSigmaX(real const& sigmaX)
{
	mSigmaX = sigmaX;
}
// get sigma y
real unsharpMaskStruct::getSigmaY() const&
{
	return mSigmaY;
}
// set sigma y
void unsharpMaskStruct::setSigmaY(real const& sigmaY)
{
	mSigmaY = sigmaY;
}
// get threshold
real unsharpMaskStruct::getThreshold() const&
{
	return mThreshold;
}
// set threshold
void unsharpMaskStruct::setThreshold(real const& threshold)
{
	mThreshold = threshold;
}
// get amount
int unsharpMaskStruct::getAmount() const&
{
	return mAmoun;
}
// set amout
void unsharpMaskStruct::setAmount(int const& amount)
{
	mAmoun = amount;
}
// get boarder type
int unsharpMaskStruct::getBoarderType() const&
{
	return mBoarderType;
}
// set boarder type
void unsharpMaskStruct::setBoarderType(int const& boarderType)
{
	mBoarderType = boarderType;
}

// set improvement
void unsharpMaskStruct::setImprovement(real const& improvement)
{
	mImprovement = improvement;
}
// get improvement
real unsharpMaskStruct::getImprovement() const&
{
	return mImprovement;
}

// print parameters unsharp masking filter
void unsharpMaskStruct::printPara_UnsharpMaskinFilter_Struct() const &
{
	std::cout << "" << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "unsharp mask" << std::endl;
	std::cout << "kernel size: " << mKernelSize << std::endl;
	std::cout << "sigma X: " << mSigmaX << std::endl;
	std::cout << "sigma Y: " << mSigmaY << std::endl;
	std::cout << "boarder type: " << mBoarderType << std::endl;
	std::cout << "threshold: " << mThreshold << std::endl;
	std::cout << "amount: " << mAmoun << std::endl;
	std::cout << "improvement: " << mImprovement << std::endl;
	std::cout << "___________________________________" << std::endl;
	std::cout << "" << std::endl;
}

// export as txt fiel
void unsharpMaskStruct::exportAsTXTfile()
{
	std::ofstream file;
	file.open("unsharpMaskStruct.txt", std::ios_base::app);
	if (file.is_open())
	{
		file << "" << std::endl;
		file << "___________________________________" << std::endl;
		file << "unsharp mask parameter" << std::endl;
		file << "kernel size: " << mKernelSize << std::endl;
		file << "sigma X: " << mSigmaX << std::endl;
		file << "sigma Y: " << mSigmaY << std::endl;
		file << "boarder type: " << mBoarderType << std::endl;
		file << "threshold: " << mThreshold << std::endl;
		file << "amount: " << mAmoun << std::endl;
		file << "improvement: " << mImprovement << std::endl;
		file << "___________________________________" << std::endl;
		file << "" << std::endl;
	}
	file.close();
}


ImproveImageQuality::ImproveImageQuality() {}
ImproveImageQuality::~ImproveImageQuality(){}

ContrastAndGammaStruct ImproveImageQuality::improveImageQuality_contrastAndGamma(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, real const& minAlpha, real const& maxAlpha, int const& alphaSteps, real const& minBeta, real const& maxBeta, int const& stepsBeta, real const& minGamma, real const& maxGamma, int const& stepsGamma)
{
	ContrastAndGammaStruct retunrBestResult_ContrastAndGamm;

	real temp_Alpha;
	real temp_Beta;
	real temp_Gamma;

	cv::Mat new_image = cv::Mat::zeros(simulatedImage.size(), simulatedImage.type());
	double bestResult = Images::calcSumMatrix(Images::PerElementAbsDifference(simulatedImage, sharpImage));

	double tempBestResult = Images::calcSumMatrix(Images::PerElementAbsDifference(new_image, sharpImage));
	real bestAlpha = 0.0;
	real bestBeat = 0.0;
	real bestGamma = 0.0;

	std::vector<real> alpha_vec = Math::linDistriAlongTwoValues_double(minAlpha,maxAlpha,alphaSteps);
	std::vector<real> beta_vec = Math::linDistriAlongTwoValues_double(minBeta, maxBeta, stepsBeta);
	std::vector<real> gamma_vec = Math::linDistriAlongTwoValues_double(minGamma, maxGamma, stepsGamma);

	retunrBestResult_ContrastAndGamm.setImage(simulatedImage);
	retunrBestResult_ContrastAndGamm.setQuality(bestResult);

	for (int alpha_loop = 0; alpha_loop < alpha_vec.size(); ++alpha_loop)
	{
		for (int beta_loop = 0; beta_loop < beta_vec.size(); ++beta_loop)
		{ 
			for (int gamma_loop = 0; gamma_loop < gamma_vec.size(); ++gamma_loop)

			{
				new_image = ImageProcessing::brighContrastAdjust(simulatedImage, alpha_vec.at(alpha_loop), beta_vec.at(beta_loop));
				new_image = ImageProcessing::gammaCorrection(new_image, gamma_vec.at(gamma_loop));
				

				tempBestResult = Images::calcSumMatrix(Images::PerElementAbsDifference(new_image, sharpImage));



				if (tempBestResult < bestResult)
				{
					bestResult = tempBestResult;
					retunrBestResult_ContrastAndGamm.setImage(new_image);
					retunrBestResult_ContrastAndGamm.setQuality(tempBestResult);
					retunrBestResult_ContrastAndGamm.setAlpha(alpha_vec.at(alpha_loop));
					retunrBestResult_ContrastAndGamm.setBeta(beta_vec.at(beta_loop));
					retunrBestResult_ContrastAndGamm.setGamme(gamma_vec.at(gamma_loop));

					real improvement = Images::calcImprovement(sharpImage, simulatedImage, new_image);
					retunrBestResult_ContrastAndGamm.setImprovement(improvement);


					retunrBestResult_ContrastAndGamm.exportAsTXTfile();

				}

			}
		}
	}

	real improvement = Images::calcImprovement(sharpImage, simulatedImage, retunrBestResult_ContrastAndGamm.getImage());
	retunrBestResult_ContrastAndGamm.setImprovement(improvement);

	return retunrBestResult_ContrastAndGamm;


}

ContrastAndGammaStruct ImproveImageQuality::improveImageQuality_contrastAndGamma_multiCore(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, real const& minAlpha, real const& maxAlpha, int const& alphaSteps, real const& minBeta, real const& maxBeta, int const& stepsBeta, real const& minGamma, real const& maxGamma, int const& stepsGamma)
{
	cv::Mat new_image = cv::Mat::zeros(simulatedImage.size(), simulatedImage.type());

	int const& numberCores = 8;
	int const& stepPerCore_s = stepsGamma / numberCores;
	float const& deltaPerCore_gamma = std::abs(maxGamma - minGamma) / numberCores;

	// core 1
	real const& minGamma_1 = minGamma;
	real const& maxGamma_s_1 = minGamma + deltaPerCore_gamma;
	// core 2
	real const& minGamma_2 = maxGamma_s_1;
	real const& maxGamma_s_2 = minGamma + 2 * deltaPerCore_gamma;
	// core 3
	real const& minGamma_3 = maxGamma_s_2;
	real const& maxGamma_s_3 = minGamma + 3 * deltaPerCore_gamma;
	// core 4
	real const& minGamma_4 = maxGamma_s_3;
	real const& maxGamma_s_4 = minGamma + 4 * deltaPerCore_gamma;
	// core 5
	real const& minGamma_5 = maxGamma_s_4;
	real const& maxGamma_s_5 = minGamma + 5 * deltaPerCore_gamma;
	// core 6
	real const& minGamma_6 = maxGamma_s_5;
	real const& maxGamma_s_6 = minGamma + 6 * deltaPerCore_gamma;
	// core 7
	real const& minGamma_7 = maxGamma_s_6;
	real const& maxGamma_s_7 = minGamma + 7 * deltaPerCore_gamma;
	// core 8
	real const& minGamma_8 = maxGamma_s_7;
	real const& maxGamma_s_8 = minGamma + 8 * deltaPerCore_gamma;

	ContrastAndGammaStruct Core_1_Result;
	ContrastAndGammaStruct Core_2_Result;
	ContrastAndGammaStruct Core_3_Result;
	ContrastAndGammaStruct Core_4_Result;
	ContrastAndGammaStruct Core_5_Result;
	ContrastAndGammaStruct Core_6_Result;
	ContrastAndGammaStruct Core_7_Result;
	ContrastAndGammaStruct Core_8_Result;


	#pragma omp parallel sections
		{
	

			Core_1_Result = improveImageQuality_contrastAndGamma(sharpImage, simulatedImage, minAlpha, maxAlpha, alphaSteps, minBeta, maxBeta, stepsBeta, minGamma_1, maxGamma_s_1, stepPerCore_s);
	#pragma omp section
			Core_2_Result = improveImageQuality_contrastAndGamma(sharpImage, simulatedImage, minAlpha, maxAlpha, alphaSteps, minBeta, maxBeta, stepsBeta, minGamma_2, maxGamma_s_2, stepPerCore_s);
	#pragma omp section
			Core_3_Result = improveImageQuality_contrastAndGamma(sharpImage, simulatedImage, minAlpha, maxAlpha, alphaSteps, minBeta, maxBeta, stepsBeta, minGamma_3, maxGamma_s_3, stepPerCore_s);
	#pragma omp section
			Core_4_Result = improveImageQuality_contrastAndGamma(sharpImage, simulatedImage, minAlpha, maxAlpha, alphaSteps, minBeta, maxBeta, stepsBeta, minGamma_4, maxGamma_s_4, stepPerCore_s);
	#pragma omp section
			Core_5_Result = improveImageQuality_contrastAndGamma(sharpImage, simulatedImage, minAlpha, maxAlpha, alphaSteps, minBeta, maxBeta, stepsBeta, minGamma_5, maxGamma_s_5, stepPerCore_s);
	#pragma omp section
			Core_6_Result = improveImageQuality_contrastAndGamma(sharpImage, simulatedImage, minAlpha, maxAlpha, alphaSteps, minBeta, maxBeta, stepsBeta, minGamma_6, maxGamma_s_6, stepPerCore_s);
	#pragma omp section
			Core_7_Result = improveImageQuality_contrastAndGamma(sharpImage, simulatedImage, minAlpha, maxAlpha, alphaSteps, minBeta, maxBeta, stepsBeta, minGamma_7, maxGamma_s_7, stepPerCore_s);
	#pragma omp section
		Core_8_Result = improveImageQuality_contrastAndGamma(sharpImage, simulatedImage, minAlpha, maxAlpha, alphaSteps, minBeta, maxBeta, stepsBeta, minGamma_8, maxGamma_s_8, stepPerCore_s);
	}

	std::vector<ContrastAndGammaStruct> bestAllCores{ Core_1_Result, Core_2_Result, Core_3_Result, Core_4_Result, Core_5_Result, Core_6_Result, Core_7_Result, Core_8_Result };

	real bestQuality = bestAllCores.at(0).getQuality();
	real bestAlpha = bestAllCores.at(0).getAlpha();
	real bestBeta = bestAllCores.at(0).getBeta();
	real bestGamma = bestAllCores.at(0).getGamma();

	ContrastAndGammaStruct returnContrastAndGammaStruct;
	returnContrastAndGammaStruct.setImage(bestAllCores.at(0).getImage());
	returnContrastAndGammaStruct.setQuality(bestQuality);
	returnContrastAndGammaStruct.setAlpha(bestAllCores.at(0).getAlpha());
	returnContrastAndGammaStruct.setBeta(bestAllCores.at(0).getBeta());
	returnContrastAndGammaStruct.setGamme(bestAllCores.at(0).getGamma());

	real tempBestQuality;



	// find best result
	for (int i = 0; i < bestAllCores.size(); ++i)
	{
		tempBestQuality = bestAllCores.at(i).getQuality();

		if (tempBestQuality < bestQuality)
		{
			bestQuality = tempBestQuality;
			returnContrastAndGammaStruct.setImage(bestAllCores.at(i).getImage());
			returnContrastAndGammaStruct.setQuality(tempBestQuality);
			returnContrastAndGammaStruct.setAlpha(bestAllCores.at(i).getAlpha());
			returnContrastAndGammaStruct.setBeta(bestAllCores.at(i).getBeta());
			returnContrastAndGammaStruct.setGamme(bestAllCores.at(i).getGamma());

		}

	}

	real improvement = Images::calcImprovement(sharpImage, simulatedImage, returnContrastAndGammaStruct.getImage());
	returnContrastAndGammaStruct.setImprovement(improvement);

	return returnContrastAndGammaStruct;

}

// use ditail enhance filter
detailEnhanceStruct ImproveImageQuality::improveImageQuality_ditailEnhance(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, float const& minSigmar_s, float const& maxSigmar_s, int const& stepsSigmar_s, float const& minSigmar_r, float const& maxSigmar_r, int const& stepsSigmar_r)
{
	detailEnhanceStruct retunrBestResult_ditailEnahnce;

	

	float temp_sigmar_s; // Range between 0 to 200. 
	float temp_sigmar_r; // Range between 0 to 1. 
	
	cv::Mat new_image = cv::Mat::zeros(simulatedImage.size(), simulatedImage.type());

	double bestResult =  Images::calcSumMatrix(Images::PerElementAbsDifference(simulatedImage, sharpImage));

	double tempBestResult = Images::calcSumMatrix(Images::PerElementAbsDifference(new_image, sharpImage));
	float bestSigmar_s = 0.0;
	float bestSigmar_r = 0.0;


	std::vector<float> sigmar_s_vec = Math::linDistriAlongTwoValues_float(minSigmar_s, maxSigmar_s, stepsSigmar_s);
	std::vector<float> sigmar_r_vec = Math::linDistriAlongTwoValues_float(minSigmar_r, maxSigmar_r, stepsSigmar_r);
	
	retunrBestResult_ditailEnahnce.setImage(simulatedImage);
	retunrBestResult_ditailEnahnce.setQuality(bestResult);
	
	for (int s = 0; s < sigmar_s_vec.size(); ++s)
		{			
			for (int r=0; r < sigmar_r_vec.size(); ++r)

				{
					temp_sigmar_s = sigmar_s_vec.at(s);
					temp_sigmar_r = sigmar_r_vec.at(r);
					new_image = ImageProcessing::detailEnhancin(simulatedImage, temp_sigmar_s, temp_sigmar_r);

					tempBestResult = Images::calcSumMatrix(Images::PerElementAbsDifference(new_image, sharpImage));

					//std::cout << "_________________ " << std::endl;
					//std::cout << "temp sigmar s " << temp_sigmar_s << std::endl;
					//std::cout << "temp sigmar r " << temp_sigmar_r << std::endl;
					std::cout << "tempBestResult - best result " << tempBestResult - bestResult << std::endl;
					//std::cout << "_________________ " << std::endl;

					if (tempBestResult < bestResult)
					{
						bestResult = tempBestResult;
						retunrBestResult_ditailEnahnce.setImage(new_image);
						retunrBestResult_ditailEnahnce.setQuality(tempBestResult);
						retunrBestResult_ditailEnahnce.setSigmar_s(temp_sigmar_s);
						retunrBestResult_ditailEnahnce.setSigmar_r(temp_sigmar_r);

						real improvement = Images::calcImprovement(sharpImage, simulatedImage, new_image);
						retunrBestResult_ditailEnahnce.setImprovement(improvement);

					
						retunrBestResult_ditailEnahnce.exportAsTXTfile();
					
					}

				}
			
		}
	

	real improvement = Images::calcImprovement(sharpImage, simulatedImage, retunrBestResult_ditailEnahnce.getImage());
	retunrBestResult_ditailEnahnce.setImprovement(improvement);

	return retunrBestResult_ditailEnahnce;

}


detailEnhanceStruct ImproveImageQuality::improveImageQuality_ditailEnhance_multiCore(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, float const& minSigmar_s, float const& maxSigmar_s, int const& stepsSigmar_s, float const& minSigmar_r, float const& maxSigmar_r, int const& stepsSigmar_r)
{
	cv::Mat new_image = cv::Mat::zeros(simulatedImage.size(), simulatedImage.type());

	int const& numberCores = 8;
	int const& stepPerCore_s = stepsSigmar_s / numberCores;
	float const& deltaPerCore_s = std::abs(maxSigmar_s - minSigmar_s) / numberCores;

	// core 1
	float const& minSigmar_s_1 = minSigmar_s;
	float const& maxSigmar_s_1 = minSigmar_s + deltaPerCore_s;
	// core 2
	float const& minSigmar_s_2 = maxSigmar_s_1;
	float const& maxSigmar_s_2 = minSigmar_s + 2 * deltaPerCore_s;
	// core 3
	float const& minSigmar_s_3 = maxSigmar_s_2;
	float const& maxSigmar_s_3 = minSigmar_s + 3 * deltaPerCore_s;
	// core 4
	float const& minSigmar_s_4 = maxSigmar_s_3;
	float const& maxSigmar_s_4 = minSigmar_s + 4 * deltaPerCore_s;
	// core 5
	float const& minSigmar_s_5 = maxSigmar_s_4;
	float const& maxSigmar_s_5 = minSigmar_s + 5 * deltaPerCore_s;
	// core 6
	float const& minSigmar_s_6 = maxSigmar_s_5 ;
	float const& maxSigmar_s_6 = minSigmar_s + 6 * deltaPerCore_s;
	// core 7
	float const& minSigmar_s_7 = maxSigmar_s_6;
	float const& maxSigmar_s_7 = minSigmar_s + 7 * deltaPerCore_s;
	// core 8
	float const& minSigmar_s_8 = maxSigmar_s_7;
	float const& maxSigmar_s_8 = minSigmar_s + 8 * deltaPerCore_s;


	detailEnhanceStruct Core_1_Result;
	detailEnhanceStruct Core_2_Result;
	detailEnhanceStruct Core_3_Result;
	detailEnhanceStruct Core_4_Result;
	detailEnhanceStruct Core_5_Result;
	detailEnhanceStruct Core_6_Result;
	detailEnhanceStruct Core_7_Result;
	detailEnhanceStruct Core_8_Result;

	#pragma omp parallel
	#pragma omp sections
	{
		#pragma omp section
		Core_1_Result = improveImageQuality_ditailEnhance(sharpImage, simulatedImage, minSigmar_s_1, maxSigmar_s_1, stepPerCore_s, minSigmar_r, maxSigmar_r, stepsSigmar_r);
		#pragma omp section
		Core_2_Result = improveImageQuality_ditailEnhance(sharpImage, simulatedImage, minSigmar_s_2, maxSigmar_s_2, stepPerCore_s, minSigmar_r, maxSigmar_r, stepsSigmar_r);
		#pragma omp section
 		Core_3_Result = improveImageQuality_ditailEnhance(sharpImage, simulatedImage, minSigmar_s_3, maxSigmar_s_3, stepPerCore_s, minSigmar_r, maxSigmar_r, stepsSigmar_r);
		#pragma omp section
		Core_4_Result = improveImageQuality_ditailEnhance(sharpImage, simulatedImage, minSigmar_s_4, maxSigmar_s_4, stepPerCore_s, minSigmar_r, maxSigmar_r, stepsSigmar_r);
		#pragma omp section
		Core_5_Result = improveImageQuality_ditailEnhance(sharpImage, simulatedImage, minSigmar_s_5, maxSigmar_s_5, stepPerCore_s, minSigmar_r, maxSigmar_r, stepsSigmar_r);
		#pragma omp section
		Core_6_Result = improveImageQuality_ditailEnhance(sharpImage, simulatedImage, minSigmar_s_6, maxSigmar_s_6, stepPerCore_s, minSigmar_r, maxSigmar_r, stepsSigmar_r);
		#pragma omp section
		Core_7_Result = improveImageQuality_ditailEnhance(sharpImage, simulatedImage, minSigmar_s_7, maxSigmar_s_7, stepPerCore_s, minSigmar_r, maxSigmar_r, stepsSigmar_r);
		#pragma omp section
		Core_8_Result = improveImageQuality_ditailEnhance(sharpImage, simulatedImage, minSigmar_s_8, maxSigmar_s_8, stepPerCore_s, minSigmar_r, maxSigmar_r, stepsSigmar_r);
	}

	std::vector<detailEnhanceStruct> bestAllCores{Core_1_Result, Core_2_Result, Core_3_Result, Core_4_Result, Core_5_Result, Core_6_Result, Core_7_Result, Core_8_Result };

	real bestQuality = bestAllCores.at(0).getQuality();
	float bestSigmar_s = bestAllCores.at(0).getSigmar_s();
	float bestSigmar_r = bestAllCores.at(0).getSigmar_r();
	
	detailEnhanceStruct returnDetailEnhanceStruct;
	returnDetailEnhanceStruct.setImage(bestAllCores.at(0).getImage());
	returnDetailEnhanceStruct.setQuality(bestQuality);
	returnDetailEnhanceStruct.setSigmar_s(bestAllCores.at(0).getSigmar_s());
	returnDetailEnhanceStruct.setSigmar_r(bestAllCores.at(0).getSigmar_r());

	real tempBestQuality;

	
	
	// find best result
	for (int i = 0; i < bestAllCores.size(); ++i)
	{
		tempBestQuality = bestAllCores.at(i).getQuality();

		if (tempBestQuality < bestQuality)
		{
			bestQuality = tempBestQuality;
			returnDetailEnhanceStruct.setImage(bestAllCores.at(i).getImage());
			returnDetailEnhanceStruct.setQuality(tempBestQuality);
			returnDetailEnhanceStruct.setSigmar_s(bestAllCores.at(i).getSigmar_s());
			returnDetailEnhanceStruct.setSigmar_r(bestAllCores.at(i).getSigmar_r());
			
		}

	}

	real improvement = Images::calcImprovement(sharpImage, simulatedImage, returnDetailEnhanceStruct.getImage());
	returnDetailEnhanceStruct.setImprovement(improvement);

	return returnDetailEnhanceStruct;
}



bilateralFilterStruct ImproveImageQuality::improveImageQuality_bilateralFilter(cv::Mat const& sharpImage, cv::Mat simulatedImage , int const& minD, int const& maxD, int const& stepsD, double const& minSimgaColor, double const& maxSigmaColor, int const& stepsSigmaColor, double const& minSigmaSpace, double const& maxSigmaSpace, double const& stepsSigmaSpace, int const& boarderType)
{
	bilateralFilterStruct retunrBestResult_bilateralFilter;

	std::vector<int> d_vec = Math::linDistriAlongTwoValues_int(minD, maxD, stepsD);
	std::vector<real> sigmaColor_vec = Math::linDistriAlongTwoValues_double(minSimgaColor, maxSigmaColor, stepsSigmaColor);
	std::vector<real> sigmaSpace_vec = Math::linDistriAlongTwoValues_double(minSigmaSpace, maxSigmaSpace, stepsSigmaSpace);


	cv::Mat new_image = cv::Mat::zeros(simulatedImage.size(), simulatedImage.type());

	int bestD;
	real bestSigmaColor;
	real bestSigmaSpace;

	double bestQuality = Images::calcSumMatrix(Images::PerElementAbsDifference(simulatedImage, sharpImage));
	double tempBestQuality = Images::calcSumMatrix(Images::PerElementAbsDifference(new_image, sharpImage));

	retunrBestResult_bilateralFilter.setImage(simulatedImage);
	retunrBestResult_bilateralFilter.setQuality(bestQuality);

	for (int d_loop = 0; d_loop < d_vec.size(); d_loop++)
	{
		for (int color_loop = 0; color_loop < sigmaColor_vec.size(); color_loop++)
		{
			for (int space_loop = 0; space_loop < sigmaSpace_vec.size(); space_loop++)
			{
			
				new_image = ImageProcessing::bilateralFilter(simulatedImage, d_vec.at(d_loop), sigmaColor_vec.at(color_loop), sigmaSpace_vec.at(space_loop), boarderType);

				tempBestQuality = Images::calcSumMatrix(Images::PerElementAbsDifference(new_image, sharpImage));

				//std::cout << "_______________" << std::endl;
				//std::cout << "d " << d_vec.at(d_loop) << std::endl;
				//std::cout << "sigma color " << sigmaColor_vec.at(color_loop) << std::endl;
				//std::cout << "sigma space " << sigmaSpace_vec.at(space_loop) << std::endl;
				//std::cout << "tempBestResult - best result " << tempBestQuality - bestQuality << std::endl;
				//std::cout << "_______________" << std::endl;

				if (tempBestQuality < bestQuality)
				{
					bestQuality = tempBestQuality;
					retunrBestResult_bilateralFilter.setImage(new_image);
					retunrBestResult_bilateralFilter.setQuality(tempBestQuality);
					retunrBestResult_bilateralFilter.setD(d_vec.at(d_loop));
					retunrBestResult_bilateralFilter.setSigmarColor(sigmaColor_vec.at(color_loop));
					retunrBestResult_bilateralFilter.setSigmaSpace(sigmaSpace_vec.at(space_loop));
					retunrBestResult_bilateralFilter.setBoarderType(boarderType);

					real improvement = Images::calcImprovement(sharpImage, simulatedImage, new_image);
					retunrBestResult_bilateralFilter.setImprovement(improvement);

					retunrBestResult_bilateralFilter.exportAsTXTfile();
				}


			}

		}
	}

	real improvement = Images::calcImprovement(sharpImage, simulatedImage, retunrBestResult_bilateralFilter.getImage());
	retunrBestResult_bilateralFilter.setImprovement(improvement);

	return retunrBestResult_bilateralFilter;
}

bilateralFilterStruct ImproveImageQuality::improveImageQuality_bilateralFilter_multiCore(cv::Mat const& sharpImage, cv::Mat simulatedImage, int const& minD, int const& maxD, int const& stepsD, double const& minSimgaColor, double const& maxSigmaColor, int const& stepsSigmaColor, double const& minSigmaSpace, double const& maxSigmaSpace, double const& stepsSigmaSpace, int const& boarderType)
{

	cv::Mat new_image = cv::Mat::zeros(simulatedImage.size(), simulatedImage.type());

	int const& numberCores = 8;

	int const& stepPerCore = ceil(stepsSigmaSpace / numberCores);
	float const& deltaPerCore_s = std::abs(maxSigmaSpace - minSigmaSpace) / numberCores;


	// core 1
	real const& minSigmaSapace_1 = minSigmaSpace;
	real const& maxSigmaSapace_1 = minSigmaSpace + deltaPerCore_s;
	// core 2
	real const& minSigmaSapace_2 = maxSigmaSapace_1;
	real const& maxSigmaSapace_2 = minSigmaSpace + 2 * deltaPerCore_s;
	// core 3
	real const& minSigmaSapace_3 = maxSigmaSapace_2;
	real const& maxSigmaSapace_3 = minSigmaSpace + 3 * deltaPerCore_s;
	// core 4
	real const& minSigmaSapace_4 = maxSigmaSapace_3;
	real const& maxSigmaSapace_4 = minSigmaSpace + 4 * deltaPerCore_s;
	// core 5
	real const& minSigmaSapace_5 = maxSigmaSapace_4;
	real const& maxSigmaSapace_5 = minSigmaSpace + 5 * deltaPerCore_s;
	// core 6
	real const& minSigmaSapace_6 = maxSigmaSapace_5;
	real const& maxSigmaSapace_6 = minSigmaSpace + 6 * deltaPerCore_s;
	// core 7
	real const& minSigmaSapace_7 = maxSigmaSapace_6;
	real const& maxSigmaSapace_7 = minSigmaSpace + 7 * deltaPerCore_s;
	// core 8
	real const& minSigmaSapace_8 = maxSigmaSapace_7;
	real const& maxSigmaSapace_8 = minSigmaSpace + 8 * deltaPerCore_s;


	bilateralFilterStruct Core_1_Result;
	bilateralFilterStruct Core_2_Result;
	bilateralFilterStruct Core_3_Result;
	bilateralFilterStruct Core_4_Result;
	bilateralFilterStruct Core_5_Result;
	bilateralFilterStruct Core_6_Result;
	bilateralFilterStruct Core_7_Result;
	bilateralFilterStruct Core_8_Result;

	#pragma omp parallel
	#pragma omp sections
	{
		#pragma omp section
		Core_1_Result = improveImageQuality_bilateralFilter(sharpImage, simulatedImage, minD, maxD, stepsD, minSimgaColor, maxSigmaColor, stepsSigmaColor, minSigmaSapace_1, maxSigmaSapace_1, stepPerCore,boarderType);
		#pragma omp section
		Core_2_Result = improveImageQuality_bilateralFilter(sharpImage, simulatedImage, minD, maxD, stepsD, minSimgaColor, maxSigmaColor, stepsSigmaColor, minSigmaSapace_2, maxSigmaSapace_2, stepPerCore, boarderType);
		#pragma omp section
		Core_3_Result = improveImageQuality_bilateralFilter(sharpImage, simulatedImage, minD, maxD, stepsD, minSimgaColor, maxSigmaColor, stepsSigmaColor, minSigmaSapace_3, maxSigmaSapace_3, stepPerCore, boarderType);
		#pragma omp section
		Core_4_Result = improveImageQuality_bilateralFilter(sharpImage, simulatedImage, minD, maxD, stepsD, minSimgaColor, maxSigmaColor, stepsSigmaColor, minSigmaSapace_4, maxSigmaSapace_4, stepPerCore, boarderType);
		#pragma omp section
		Core_5_Result = improveImageQuality_bilateralFilter(sharpImage, simulatedImage, minD, maxD, stepsD, minSimgaColor, maxSigmaColor, stepsSigmaColor, minSigmaSapace_5, maxSigmaSapace_5, stepPerCore, boarderType);
		#pragma omp section
		Core_6_Result = improveImageQuality_bilateralFilter(sharpImage, simulatedImage, minD, maxD, stepsD, minSimgaColor, maxSigmaColor, stepsSigmaColor, minSigmaSapace_6, maxSigmaSapace_6, stepPerCore, boarderType);
		#pragma omp section
		Core_7_Result = improveImageQuality_bilateralFilter(sharpImage, simulatedImage, minD, maxD, stepsD, minSimgaColor, maxSigmaColor, stepsSigmaColor, minSigmaSapace_7, maxSigmaSapace_7, stepPerCore, boarderType);
		#pragma omp section
		Core_8_Result = improveImageQuality_bilateralFilter(sharpImage, simulatedImage, minD, maxD, stepsD, minSimgaColor, maxSigmaColor, stepsSigmaColor, minSigmaSapace_8, maxSigmaSapace_8, stepPerCore, boarderType);
	}

	std::vector<bilateralFilterStruct> bestAllCores{ Core_1_Result, Core_2_Result, Core_3_Result, Core_4_Result, Core_5_Result, Core_6_Result, Core_7_Result, Core_8_Result };

	real bestQuality = bestAllCores.at(0).getQuality();
	int bestD = bestAllCores.at(0).getD();
	real bestSigmaColor = bestAllCores.at(0).getSigmaColor();
	real bestSigmarSpace = bestAllCores.at(0).getSigmaSpace();
	int bestBoarderType = bestAllCores.at(0).getBoarderType();
	
	bilateralFilterStruct returnbilateralFilterStruct;
	returnbilateralFilterStruct.setImage(simulatedImage);
	returnbilateralFilterStruct.setImage(bestAllCores.at(0).getImage());
	returnbilateralFilterStruct.setQuality(bestQuality);
	returnbilateralFilterStruct.setD(bestAllCores.at(0).getD());
	returnbilateralFilterStruct.setSigmarColor(bestAllCores.at(0).getSigmaColor());
	returnbilateralFilterStruct.setSigmaSpace(bestAllCores.at(0).getSigmaSpace());
	returnbilateralFilterStruct.setBoarderType(bestAllCores.at(0).getBoarderType());

	real tempBestQuality;
	
	// find best result
	for (int i = 0; i < bestAllCores.size(); ++i)
	{
		tempBestQuality = bestAllCores.at(i).getQuality();

		if (tempBestQuality < bestQuality)
		{
			bestQuality = tempBestQuality;
			returnbilateralFilterStruct.setImage(bestAllCores.at(i).getImage());
			returnbilateralFilterStruct.setQuality(tempBestQuality);
			returnbilateralFilterStruct.setD(bestAllCores.at(i).getD());
			returnbilateralFilterStruct.setSigmarColor(bestAllCores.at(i).getSigmaColor());
			returnbilateralFilterStruct.setSigmaSpace(bestAllCores.at(i).getSigmaSpace());
			returnbilateralFilterStruct.setBoarderType(bestAllCores.at(i).getBoarderType());

		}

	}

	real improvement = Images::calcImprovement(sharpImage, simulatedImage, returnbilateralFilterStruct.getImage());
	returnbilateralFilterStruct.setImprovement(improvement);

	return returnbilateralFilterStruct;

}


unsharpMaskStruct ImproveImageQuality::improveImageQuality_unsharpMask(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, std::vector<cv::Size> const& kernelSize_vec, double const& minSigmaX, double const& maxSigmaX, double const& stepsSgmaX, double const& minSigmaY, double const& maxSigmaY, double const& stepsSigmaY, int const& borderType, double const& minThreshold, double const& maxThreshold, double const& stepsThreshold, double const& minAmount, double const& maxAmount, double const& stepsAmount)
{
	unsharpMaskStruct returnBestResult_unsharpMaskStruct;

	std::vector<real> sigmaX_vec = Math::linDistriAlongTwoValues_double(minSigmaX,maxSigmaX,stepsSgmaX);
	std::vector<real> sigmaY_vec = Math::linDistriAlongTwoValues_double(minSigmaY, maxSigmaY, stepsSigmaY);
	std::vector<real> threshold_vec = Math::linDistriAlongTwoValues_double(minThreshold,maxThreshold,stepsThreshold);
	std::vector<real> amount_vec = Math::linDistriAlongTwoValues_double(minAmount,maxAmount,stepsAmount);

	cv::Mat new_image = cv::Mat::zeros(simulatedImage.size(), simulatedImage.type());

	cv::Size bestKernelSize;
	real bestSigmaX;
	real bestSigmaY;
	real bestThreshold;
	real bestAmount;
	
	double bestResult = Images::calcSumMatrix(Images::PerElementAbsDifference(simulatedImage, sharpImage));
	double tempBestResult = Images::calcSumMatrix(Images::PerElementAbsDifference(new_image, sharpImage));

	returnBestResult_unsharpMaskStruct.setImage(simulatedImage);
	returnBestResult_unsharpMaskStruct.setQuality(bestResult);

	for (int kernerlSize_loop = 0; kernerlSize_loop < kernelSize_vec.size(); kernerlSize_loop++)
	{
		for (int sigmaX_loop = 0; sigmaX_loop < sigmaX_vec.size(); sigmaX_loop++)
		{
			for (int sigmaY_loop = 0; sigmaY_loop < sigmaY_vec.size(); sigmaY_loop++)
			{
				for (int threshold_loop = 0; threshold_loop < threshold_vec.size(); threshold_loop++)

					for (int amount_loop = 0; amount_loop < amount_vec.size(); amount_loop++)
					{

						new_image = ImageProcessing::unsharpMask(simulatedImage, kernelSize_vec.at(kernerlSize_loop), sigmaX_vec.at(sigmaX_loop), sigmaY_vec.at(sigmaY_loop), borderType, threshold_vec.at(threshold_loop), amount_vec.at(amount_loop));
						tempBestResult = Images::calcSumMatrix(Images::PerElementAbsDifference(new_image, sharpImage));

						//std::cout << "_______________" << std::endl;
						//std::cout << "kernel size " << kernelSize_vec.at(kernerlSize_loop) << std::endl;
						//std::cout << "sigma X " << sigmaX_vec.at(sigmaX_loop) << std::endl;
						//std::cout << "sigma Y " << sigmaY_vec.at(sigmaY_loop) << std::endl;
						//std::cout << "threshold " << threshold_vec.at(threshold_loop) << std::endl;
						//std::cout << "amount " << (amount_vec.at(amount_loop)) << std::endl;
						//std::cout << "tempBestResult - best result " << tempBestResult - bestResult << std::endl;
						//std::cout << "_______________" << std::endl;
						

						if (tempBestResult < bestResult)
						{
							bestResult = tempBestResult;
							returnBestResult_unsharpMaskStruct.setImage(new_image);
							returnBestResult_unsharpMaskStruct.setQuality(tempBestResult);
							returnBestResult_unsharpMaskStruct.setKernelSize(kernelSize_vec.at(kernerlSize_loop));
							returnBestResult_unsharpMaskStruct.setSigmaX(sigmaX_vec.at(sigmaX_loop));
							returnBestResult_unsharpMaskStruct.setSigmaY(sigmaY_vec.at(sigmaY_loop));
							returnBestResult_unsharpMaskStruct.setThreshold(threshold_vec.at(threshold_loop));
							returnBestResult_unsharpMaskStruct.setAmount(amount_vec.at(amount_loop));
							returnBestResult_unsharpMaskStruct.setBoarderType(borderType);

							real improvement = Images::calcImprovement(sharpImage, simulatedImage, new_image);
							returnBestResult_unsharpMaskStruct.setImprovement(improvement);

							returnBestResult_unsharpMaskStruct.exportAsTXTfile();
						}

					}


			}


		}
	}

	real improvement = Images::calcImprovement(sharpImage, simulatedImage, returnBestResult_unsharpMaskStruct.getImage());
	returnBestResult_unsharpMaskStruct.setImprovement(improvement);

	return returnBestResult_unsharpMaskStruct;
}

unsharpMaskStruct ImproveImageQuality::improveImageQuality_unsharpMask_multiCore(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, std::vector<cv::Size> const& kernelSize_vec, double const& minSigmaX, double const& maxSigmaX, double const& stepsSgmaX, double const& minSigmaY, double const& maxSigmaY, double const& stepsSigmaY, int const& borderType, double const& minThreshold, double const& maxThreshold, double const& stepsThreshold, double const& minAmount, double const& maxAmount, double const& stepsAmount)
{

	cv::Mat new_image = cv::Mat::zeros(simulatedImage.size(), simulatedImage.type());

	int const& numberCores = 8;

	int const& stepPerCore = ceil(stepsAmount / numberCores);
	float const& deltaPerCore_s = std::abs(maxAmount - minAmount) / numberCores;


	// core 1
	real const& minAmount_1 = minAmount;
	real const& maxAmount_1 = minAmount + deltaPerCore_s;
	// core 2
	real const& minAmount_2 = maxAmount_1;
	real const& maxAmount_2 = minAmount + 2 * deltaPerCore_s;
	// core 3
	real const& minAmount_3 = maxAmount_2;
	real const& maxAmount_3 = minAmount + 3 * deltaPerCore_s;
	// core 4
	real const& minAmount_4 = maxAmount_3;
	real const& maxAmount_4 = minAmount + 4 * deltaPerCore_s;
	// core 5
	real const& minAmount_5 = maxAmount_4;
	real const& maxAmount_5 = minAmount + 5 * deltaPerCore_s;
	// core 6
	real const& minAmount_6 = maxAmount_5;
	real const& maxAmount_6 = minAmount + 6 * deltaPerCore_s;
	// core 7
	real const& minAmount_7 = maxAmount_6;
	real const& maxAmount_7 = minAmount + 7 * deltaPerCore_s;
	// core 8
	real const& minAmount_8 = maxAmount_7;
	real const& maxAmount_8 = minAmount + 8 * deltaPerCore_s;

	unsharpMaskStruct Core_1_Result;
	unsharpMaskStruct Core_2_Result;
	unsharpMaskStruct Core_3_Result;
	unsharpMaskStruct Core_4_Result;
	unsharpMaskStruct Core_5_Result;
	unsharpMaskStruct Core_6_Result;
	unsharpMaskStruct Core_7_Result;
	unsharpMaskStruct Core_8_Result;

#pragma omp parallel
#pragma omp sections
	{
		#pragma omp section
		Core_1_Result = improveImageQuality_unsharpMask(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY, maxSigmaY, stepsSigmaY, borderType, minThreshold, maxThreshold, stepsThreshold, minAmount_1, maxAmount_1, stepPerCore);
		#pragma omp section
		Core_2_Result = improveImageQuality_unsharpMask(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY, maxSigmaY, stepsSigmaY, borderType, minThreshold, maxThreshold, stepsThreshold, minAmount_2, maxAmount_2, stepPerCore);
		#pragma omp section
		Core_3_Result = improveImageQuality_unsharpMask(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY, maxSigmaY, stepsSigmaY, borderType, minThreshold, maxThreshold, stepsThreshold, minAmount_3, maxAmount_3, stepPerCore);
		#pragma omp section
		Core_4_Result = improveImageQuality_unsharpMask(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY, maxSigmaY, stepsSigmaY, borderType, minThreshold, maxThreshold, stepsThreshold, minAmount_4, maxAmount_4, stepPerCore);
		#pragma omp section
		Core_5_Result = improveImageQuality_unsharpMask(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY, maxSigmaY, stepsSigmaY, borderType, minThreshold, maxThreshold, stepsThreshold, minAmount_5, maxAmount_5, stepPerCore);
		#pragma omp section
		Core_6_Result = improveImageQuality_unsharpMask(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY, maxSigmaY, stepsSigmaY, borderType, minThreshold, maxThreshold, stepsThreshold, minAmount_6, maxAmount_6, stepPerCore);
		#pragma omp section
		Core_7_Result = improveImageQuality_unsharpMask(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY, maxSigmaY, stepsSigmaY, borderType, minThreshold, maxThreshold, stepsThreshold, minAmount_7, maxAmount_7, stepPerCore); 
		#pragma omp section
		Core_8_Result = improveImageQuality_unsharpMask(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY, maxSigmaY, stepsSigmaY, borderType, minThreshold, maxThreshold, stepsThreshold, minAmount_8, maxAmount_8, stepPerCore);
	}

	std::vector<unsharpMaskStruct> bestAllCores{ Core_1_Result, Core_2_Result, Core_3_Result, Core_4_Result, Core_5_Result, Core_6_Result, Core_7_Result, Core_8_Result,  };

	real bestQuality = bestAllCores.at(0).getQuality();
	cv::Size bestKernelSize = bestAllCores.at(0).getKernelSize();
	real bestSigmaX = bestAllCores.at(0).getSigmaX();
	real bestSigmaY = bestAllCores.at(0).getSigmaY();
	int bestBoarderType = bestAllCores.at(0).getBoarderType();
	real bestThreshold = bestAllCores.at(0).getThreshold();
	real bestAmount = bestAllCores.at(0).getAmount();
	

	unsharpMaskStruct returnUnsharpMaskStruct;
	returnUnsharpMaskStruct.setImage(bestAllCores.at(0).getImage());
	returnUnsharpMaskStruct.setQuality(bestQuality);
	returnUnsharpMaskStruct.setKernelSize(bestAllCores.at(0).getKernelSize());
	returnUnsharpMaskStruct.setSigmaX(bestAllCores.at(0).getSigmaX());
	returnUnsharpMaskStruct.setSigmaY(bestAllCores.at(0).getSigmaY());
	returnUnsharpMaskStruct.setThreshold(bestAllCores.at(0).getThreshold());
	returnUnsharpMaskStruct.setAmount(bestAllCores.at(0).getAmount());
	returnUnsharpMaskStruct.setBoarderType(bestAllCores.at(0).getBoarderType());


	real tempBestQuality;

	// find best result
	for (int i = 0; i < bestAllCores.size(); ++i)
	{
		tempBestQuality = bestAllCores.at(i).getQuality();

		if (tempBestQuality < bestQuality)
		{
			bestQuality = tempBestQuality;
			returnUnsharpMaskStruct.setImage(bestAllCores.at(i).getImage());
			returnUnsharpMaskStruct.setQuality(tempBestQuality);
			returnUnsharpMaskStruct.setKernelSize(bestAllCores.at(i).getKernelSize());
			returnUnsharpMaskStruct.setSigmaX(bestAllCores.at(i).getSigmaX());
			returnUnsharpMaskStruct.setSigmaY(bestAllCores.at(i).getSigmaY());
			returnUnsharpMaskStruct.setThreshold(bestAllCores.at(i).getThreshold());
			returnUnsharpMaskStruct.setAmount(bestAllCores.at(i).getAmount());
			returnUnsharpMaskStruct.setBoarderType(bestAllCores.at(i).getBoarderType());

		}

	}

	real improvement = Images::calcImprovement(sharpImage, simulatedImage, returnUnsharpMaskStruct.getImage());
	returnUnsharpMaskStruct.setImprovement(improvement);

	return returnUnsharpMaskStruct;

}


medianBlurStruct ImproveImageQuality::improveImageQuality_medianBlur(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, std::vector<int> const& kernelSize_vec)
{

	medianBlurStruct returnBestResult_medianBlur;
	
	cv::Mat new_image = cv::Mat::zeros(simulatedImage.size(), simulatedImage.type());


	double bestResult = Images::calcSumMatrix(Images::PerElementAbsDifference(simulatedImage, sharpImage));

	double tempBestResult = Images::calcSumMatrix(Images::PerElementAbsDifference(new_image, sharpImage));

	returnBestResult_medianBlur.setImage(simulatedImage);
	returnBestResult_medianBlur.setQuality(bestResult);
	returnBestResult_medianBlur.setKernelSize(0);

	for (int kernelSize_loop = 0; kernelSize_loop < kernelSize_vec.size(); kernelSize_loop++)
	{

		new_image = ImageProcessing::MedianBlurFilter(simulatedImage, kernelSize_vec.at(kernelSize_loop));
		tempBestResult = Images::calcSumMatrix(Images::PerElementAbsDifference(new_image, sharpImage));

		if (tempBestResult < bestResult)
		{
			bestResult = tempBestResult;
			returnBestResult_medianBlur.setImage(new_image);
			returnBestResult_medianBlur.setQuality(tempBestResult);
			returnBestResult_medianBlur.setKernelSize(kernelSize_vec.at(kernelSize_loop));

			real improvement = Images::calcImprovement(sharpImage, simulatedImage, new_image);
			returnBestResult_medianBlur.setImprovement(improvement);

			returnBestResult_medianBlur.exportAsTXTfile();
		}

		//std::cout << "_______________" << std::endl;
		//std::cout << "kernel size " << kernelSize_vec.at(kernelSize_loop) << std::endl;
		//std::cout << "_______________" << std::endl;
	}

	real improvement = Images::calcImprovement(sharpImage, simulatedImage, returnBestResult_medianBlur.getImage());
	returnBestResult_medianBlur.setImprovement(improvement);

	return returnBestResult_medianBlur;

}


unsharpMaskStruct ImproveImageQuality::improveImageQuality_unsharpMask_ForServer(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, std::vector<cv::Size> const& kernelSize_vec, double const& minSigmaX, double const& maxSigmaX, double const& stepsSgmaX, double const& minSigmaY, double const& maxSigmaY, double const& stepsSigmaY, int const& borderType, int const& threshold, int const& amount)
{

	unsharpMaskStruct returnBestResult_unsharpMaskStruct_ForServer;

	std::vector<real> sigmaX_vec = Math::linDistriAlongTwoValues_double(minSigmaX, maxSigmaX, stepsSgmaX);
	std::vector<real> sigmaY_vec = Math::linDistriAlongTwoValues_double(minSigmaY, maxSigmaY, stepsSigmaY);


	cv::Mat new_image = cv::Mat::zeros(simulatedImage.size(), simulatedImage.type());

	cv::Size bestKernelSize;
	real bestSigmaX;
	real bestSigmaY;


	double bestResult = Images::calcSumMatrix(Images::PerElementAbsDifference(simulatedImage, sharpImage));
	double tempBestResult = Images::calcSumMatrix(Images::PerElementAbsDifference(new_image, sharpImage));

	returnBestResult_unsharpMaskStruct_ForServer.setImage(simulatedImage);
	returnBestResult_unsharpMaskStruct_ForServer.setQuality(bestResult);
	returnBestResult_unsharpMaskStruct_ForServer.setThreshold(threshold);
	returnBestResult_unsharpMaskStruct_ForServer.setAmount(amount);
	returnBestResult_unsharpMaskStruct_ForServer.setBoarderType(borderType);

	for (int kernerlSize_loop = 0; kernerlSize_loop < kernelSize_vec.size(); kernerlSize_loop++)
	{
		for (int sigmaX_loop = 0; sigmaX_loop < sigmaX_vec.size(); sigmaX_loop++)
		{
			for (int sigmaY_loop = 0; sigmaY_loop < sigmaY_vec.size(); sigmaY_loop++)
			{

				new_image = ImageProcessing::unsharpMask(simulatedImage, kernelSize_vec.at(kernerlSize_loop), sigmaX_vec.at(sigmaX_loop), sigmaY_vec.at(sigmaY_loop), borderType, threshold, amount);
				tempBestResult = Images::calcSumMatrix(Images::PerElementAbsDifference(new_image, sharpImage));

				//std::cout << "_______________" << std::endl;
				//std::cout << "kernel size " << kernelSize_vec.at(kernerlSize_loop) << std::endl;
				//std::cout << "sigma X " << sigmaX_vec.at(sigmaX_loop) << std::endl;
				//std::cout << "sigma Y " << sigmaY_vec.at(sigmaY_loop) << std::endl;
				//std::cout << "threshold " << threshold_vec.at(threshold_loop) << std::endl;
				//std::cout << "amount " << (amount_vec.at(amount_loop)) << std::endl;
				//std::cout << "tempBestResult - best result " << tempBestResult - bestResult << std::endl;
				//std::cout << "_______________" << std::endl;


				if (tempBestResult < bestResult)
				{
					bestResult = tempBestResult;
					returnBestResult_unsharpMaskStruct_ForServer.setImage(new_image);
					returnBestResult_unsharpMaskStruct_ForServer.setQuality(tempBestResult);
					returnBestResult_unsharpMaskStruct_ForServer.setKernelSize(kernelSize_vec.at(kernerlSize_loop));
					returnBestResult_unsharpMaskStruct_ForServer.setSigmaX(sigmaX_vec.at(sigmaX_loop));
					returnBestResult_unsharpMaskStruct_ForServer.setSigmaY(sigmaY_vec.at(sigmaY_loop));

					real improvement = Images::calcImprovement(sharpImage, simulatedImage, new_image);
					returnBestResult_unsharpMaskStruct_ForServer.setImprovement(improvement);

					returnBestResult_unsharpMaskStruct_ForServer.exportAsTXTfile();
				}
			}
		}
	}

	real improvement = Images::calcImprovement(sharpImage, simulatedImage, returnBestResult_unsharpMaskStruct_ForServer.getImage());
	returnBestResult_unsharpMaskStruct_ForServer.setImprovement(improvement);

	return returnBestResult_unsharpMaskStruct_ForServer;


}



unsharpMaskStruct ImproveImageQuality::improveImageQuality_unsharpMask_MultiCor_ForServer(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, std::vector<cv::Size> const& kernelSize_vec, double const& minSigmaX, double const& maxSigmaX, double const& stepsSgmaX, double const& minSigmaY, double const& maxSigmaY, double const& stepsSigmaY, int const& borderType, int const& threshold, int const& amount)
{
	cv::Mat new_image = cv::Mat::zeros(simulatedImage.size(), simulatedImage.type());

	int const& numberCores = 32;

	int const& stepPerCore = ceil(stepsSigmaY / numberCores);
	float const& deltaPerCore_s = std::abs(maxSigmaY - minSigmaY) / numberCores;


	// core 1
	real const& minSigmaY_1 = minSigmaY;
	real const& maxSigmaY_1 = minSigmaY + deltaPerCore_s;
	// core 2
	real const& minSigmaY_2 = maxSigmaY_1;
	real const& maxSigmaY_2 = minSigmaY + 2 * deltaPerCore_s;
	// core 3
	real const& minSigmaY_3 = maxSigmaY_2;
	real const& maxSigmaY_3 = minSigmaY + 3 * deltaPerCore_s;
	// core 4
	real const& minSigmaY_4 = maxSigmaY_3;
	real const& maxSigmaY_4 = minSigmaY + 4 * deltaPerCore_s;
	// core 5
	real const& minSigmaY_5 = maxSigmaY_4;
	real const& maxSigmaY_5 = minSigmaY + 5 * deltaPerCore_s;
	// core 6
	real const& minSigmaY_6 = maxSigmaY_5;
	real const& maxSigmaY_6 = minSigmaY + 6 * deltaPerCore_s;
	// core 7
	real const& minSigmaY_7 = maxSigmaY_6;
	real const& maxSigmaY_7 = minSigmaY + 7 * deltaPerCore_s;
	// core 8
	real const& minSigmaY_8 = maxSigmaY_7;
	real const& maxSigmaY_8 = minSigmaY + 8 * deltaPerCore_s;
	// core 
	real const& minSigmaY_9 = maxSigmaY_8;
	real const& maxSigmaY_9 = minSigmaY +  9 * deltaPerCore_s;
	// core 
	real const& minSigmaY_10 = maxSigmaY_9;
	real const& maxSigmaY_10 = minSigmaY + 10 * deltaPerCore_s;
	// core 
	real const& minSigmaY_11 = maxSigmaY_10;
	real const& maxSigmaY_11 = minSigmaY + 11*deltaPerCore_s;
	// core 
	real const& minSigmaY_12 = maxSigmaY_11;
	real const& maxSigmaY_12 = minSigmaY + 12*deltaPerCore_s;
	// core 
	real const& minSigmaY_13 = maxSigmaY_12;
	real const& maxSigmaY_13 = minSigmaY + 13*deltaPerCore_s;
	// core 
	real const& minSigmaY_14 = maxSigmaY_13;
	real const& maxSigmaY_14 = minSigmaY + 14*deltaPerCore_s;
	// core 
	real const& minSigmaY_15 = maxSigmaY_14;
	real const& maxSigmaY_15 = minSigmaY + 15*deltaPerCore_s;
	// core 
	real const& minSigmaY_16 = maxSigmaY_15;
	real const& maxSigmaY_16 = minSigmaY + 16*deltaPerCore_s;
	// core 
	real const& minSigmaY_17 = maxSigmaY_16;
	real const& maxSigmaY_17 = minSigmaY + 16*deltaPerCore_s;
	// core 
	real const& minSigmaY_18 = maxSigmaY_17;
	real const& maxSigmaY_18 = minSigmaY + 18*deltaPerCore_s;
	// core 
	real const& minSigmaY_19 = maxSigmaY_18;
	real const& maxSigmaY_19 = minSigmaY + 19*deltaPerCore_s;
	// core 
	real const& minSigmaY_20 = maxSigmaY_19;
	real const& maxSigmaY_20 = minSigmaY + 20*deltaPerCore_s;
	// core 
	real const& minSigmaY_21 = maxSigmaY_20;
	real const& maxSigmaY_21 = minSigmaY + 21*deltaPerCore_s;
	// core 
	real const& minSigmaY_22 = maxSigmaY_21;
	real const& maxSigmaY_22 = minSigmaY + 22*deltaPerCore_s;
	// core 
	real const& minSigmaY_23 = maxSigmaY_22;
	real const& maxSigmaY_23 = minSigmaY + 23*deltaPerCore_s;
	// core 
	real const& minSigmaY_24 = maxSigmaY_23;
	real const& maxSigmaY_24 = minSigmaY + 24*deltaPerCore_s;
	// core 
	real const& minSigmaY_25 = maxSigmaY_24;
	real const& maxSigmaY_25 = minSigmaY + 25*deltaPerCore_s;
	// core 
	real const& minSigmaY_26 = maxSigmaY_25;
	real const& maxSigmaY_26 = minSigmaY + 26*deltaPerCore_s;
	// core 
	real const& minSigmaY_27 = maxSigmaY_26;
	real const& maxSigmaY_27 = minSigmaY + 27*deltaPerCore_s;
	// core 
	real const& minSigmaY_28 = maxSigmaY_27;
	real const& maxSigmaY_28 = minSigmaY + 28*deltaPerCore_s;
	// core 
	real const& minSigmaY_29 = maxSigmaY_28;
	real const& maxSigmaY_29 = minSigmaY + 29*deltaPerCore_s;
	// core 
	real const& minSigmaY_30 = maxSigmaY_29;
	real const& maxSigmaY_30 = minSigmaY + 30*deltaPerCore_s;
	// core 
	real const& minSigmaY_31 = maxSigmaY_30;
	real const& maxSigmaY_31 = minSigmaY + 30*deltaPerCore_s;
	// core 
	real const& minSigmaY_32 = maxSigmaY_31;
	real const& maxSigmaY_32 = minSigmaY + 32*deltaPerCore_s;

	unsharpMaskStruct Core_1_Result;
	unsharpMaskStruct Core_2_Result;
	unsharpMaskStruct Core_3_Result;
	unsharpMaskStruct Core_4_Result;
	unsharpMaskStruct Core_5_Result;
	unsharpMaskStruct Core_6_Result;
	unsharpMaskStruct Core_7_Result;
	unsharpMaskStruct Core_8_Result;
	unsharpMaskStruct Core_9_Result;
	unsharpMaskStruct Core_10_Result;
	unsharpMaskStruct Core_11_Result;
	unsharpMaskStruct Core_12_Result;
	unsharpMaskStruct Core_13_Result;
	unsharpMaskStruct Core_14_Result;
	unsharpMaskStruct Core_15_Result;
	unsharpMaskStruct Core_16_Result;
	unsharpMaskStruct Core_17_Result;
	unsharpMaskStruct Core_18_Result;
	unsharpMaskStruct Core_19_Result;
	unsharpMaskStruct Core_20_Result;
	unsharpMaskStruct Core_21_Result;
	unsharpMaskStruct Core_22_Result;
	unsharpMaskStruct Core_23_Result;
	unsharpMaskStruct Core_24_Result;
	unsharpMaskStruct Core_25_Result;
	unsharpMaskStruct Core_26_Result;
	unsharpMaskStruct Core_27_Result;
	unsharpMaskStruct Core_28_Result;
	unsharpMaskStruct Core_29_Result;
	unsharpMaskStruct Core_30_Result;
	unsharpMaskStruct Core_31_Result;
	unsharpMaskStruct Core_32_Result;

	#pragma omp parallel
	#pragma omp sections
	{
	#pragma omp section
	Core_1_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_1, maxSigmaY_1, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_2_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_2, maxSigmaY_2, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_3_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_3, maxSigmaY_3, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_4_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_4, maxSigmaY_4, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_5_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_5, maxSigmaY_5, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_6_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_6, maxSigmaY_6, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_7_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_7, maxSigmaY_7, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_8_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_8, maxSigmaY_8, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_9_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_9, maxSigmaY_9, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_10_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_10, maxSigmaY_10, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_11_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_11, maxSigmaY_11, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_12_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_12, maxSigmaY_12, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_13_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_13, maxSigmaY_13, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_14_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_14, maxSigmaY_14, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_15_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_15, maxSigmaY_15, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_16_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_16, maxSigmaY_16, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_17_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_17, maxSigmaY_17, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_18_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_18, maxSigmaY_18, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_19_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_19, maxSigmaY_19, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_20_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_20, maxSigmaY_20, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_21_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_21, maxSigmaY_21, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_22_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_22, maxSigmaY_22, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_23_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_23, maxSigmaY_23, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_24_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_24, maxSigmaY_24, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_25_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_25, maxSigmaY_25, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_26_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_26, maxSigmaY_26, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_27_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_27, maxSigmaY_27, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_28_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_28, maxSigmaY_28, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_29_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_29, maxSigmaY_29, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_30_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_30, maxSigmaY_30, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_31_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_31, maxSigmaY_31, stepPerCore, borderType, threshold, amount);
	#pragma omp section
	Core_32_Result = improveImageQuality_unsharpMask_ForServer(sharpImage, simulatedImage, kernelSize_vec, minSigmaX, maxSigmaX, stepsSgmaX, minSigmaY_32, maxSigmaY_32, stepPerCore, borderType, threshold, amount);

	}



	std::vector<unsharpMaskStruct> bestAllCores{ Core_1_Result, Core_2_Result, Core_3_Result, Core_4_Result, Core_5_Result, Core_6_Result, Core_7_Result, Core_8_Result,Core_9_Result,Core_10_Result,Core_11_Result,
	Core_12_Result, Core_13_Result, Core_14_Result, Core_15_Result, Core_16_Result, Core_17_Result, Core_18_Result, Core_19_Result, Core_20_Result, Core_21_Result, Core_22_Result, Core_23_Result, Core_24_Result, Core_25_Result, Core_26_Result, Core_27_Result, 
	Core_28_Result, Core_29_Result, Core_30_Result, Core_31_Result, Core_32_Result};

	real bestQuality = bestAllCores.at(0).getQuality();
	cv::Size bestKernelSize = bestAllCores.at(0).getKernelSize();
	real bestSigmaX = bestAllCores.at(0).getSigmaX();
	real bestSigmaY = bestAllCores.at(0).getSigmaY();
	int bestBoarderType = bestAllCores.at(0).getBoarderType();
	real bestThreshold = bestAllCores.at(0).getThreshold();
	real bestAmount = bestAllCores.at(0).getAmount();


	unsharpMaskStruct returnUnsharpMaskStruct;
	returnUnsharpMaskStruct.setImage(bestAllCores.at(0).getImage());
	returnUnsharpMaskStruct.setQuality(bestQuality);
	returnUnsharpMaskStruct.setKernelSize(bestAllCores.at(0).getKernelSize());
	returnUnsharpMaskStruct.setSigmaX(bestAllCores.at(0).getSigmaX());
	returnUnsharpMaskStruct.setSigmaY(bestAllCores.at(0).getSigmaY());
	returnUnsharpMaskStruct.setThreshold(bestAllCores.at(0).getThreshold());
	returnUnsharpMaskStruct.setAmount(bestAllCores.at(0).getAmount());
	returnUnsharpMaskStruct.setBoarderType(bestAllCores.at(0).getBoarderType());


	real tempBestQuality;

	// find best result
	for (int i = 0; i < bestAllCores.size(); ++i)
	{
		tempBestQuality = bestAllCores.at(i).getQuality();

		if (tempBestQuality < bestQuality)
		{
			bestQuality = tempBestQuality;
			returnUnsharpMaskStruct.setImage(bestAllCores.at(i).getImage());
			returnUnsharpMaskStruct.setQuality(tempBestQuality);
			returnUnsharpMaskStruct.setKernelSize(bestAllCores.at(i).getKernelSize());
			returnUnsharpMaskStruct.setSigmaX(bestAllCores.at(i).getSigmaX());
			returnUnsharpMaskStruct.setSigmaY(bestAllCores.at(i).getSigmaY());
			returnUnsharpMaskStruct.setThreshold(bestAllCores.at(i).getThreshold());
			returnUnsharpMaskStruct.setAmount(bestAllCores.at(i).getAmount());
			returnUnsharpMaskStruct.setBoarderType(bestAllCores.at(i).getBoarderType());

		}

	}

	real improvement = Images::calcImprovement(sharpImage, simulatedImage, returnUnsharpMaskStruct.getImage());
	returnUnsharpMaskStruct.setImprovement(improvement);

	return returnUnsharpMaskStruct;

}