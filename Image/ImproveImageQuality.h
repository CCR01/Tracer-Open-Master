#pragma once
#include "..\ImageProcessing/ImageProcessing.h"
#include "..\LowLevelTracing/ImportantStructures.h"

// image simulation
#include "..\Image\ImageSimulation.h"

// improve image quality structs
#include "..\ImageProcessing\ImproveImaQual_structs.h"



class ImproveImageQuality
{
public:
	ImproveImageQuality();
	~ImproveImageQuality();

	ContrastAndGammaStruct improveImageQuality_contrastAndGamma(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, real const& minAlpha, real const& maxAlpha, int const& alphaSteps, real const& minBeta, real const& maxBeta, int const& stepsBeta, real const& minGamma, real const& maxGamma, int const& stepsGamma);
	ContrastAndGammaStruct improveImageQuality_contrastAndGamma_multiCore(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, real const& minAlpha, real const& maxAlpha, int const& alphaSteps, real const& minBeta, real const& maxBeta, int const& stepsBeta, real const& minGamma, real const& maxGamma, int const& stepsGamma);

	bilateralFilterStruct improveImageQuality_bilateralFilter(cv::Mat const& sharpImage, cv::Mat simulatedImage, int const& minD, int const& maxD, int const& stepsD, double const& minSimgaColor, double const& maxSigmaColor, int const& stepsSigmaColor, double const& minSigmaSpace, double const& maxSigmaSpace, double const& stepsSigmaSpace, int const& boarderType);
	bilateralFilterStruct improveImageQuality_bilateralFilter_multiCore(cv::Mat const& sharpImage, cv::Mat simulatedImage, int const& minD, int const& maxD, int const& stepsD, double const& minSimgaColor, double const& maxSigmaColor, int const& stepsSigmaColor, double const& minSigmaSpace, double const& maxSigmaSpace, double const& stepsSigmaSpace, int const& boarderType);

	medianBlurStruct improveImageQuality_medianBlur(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, std::vector<int> const& kernelSize_vec);

	

private:

};


