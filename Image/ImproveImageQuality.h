#pragma once
#include "..\ImageProcessing/ImageProcessing.h"
#include "..\LowLevelTracing/ImportantStructures.h"


struct ContrastAndGammaStruct
{
	ContrastAndGammaStruct();
	~ContrastAndGammaStruct();

	// set image
	void setImage(cv::Mat const& image);
	// get image
	cv::Mat getImage() const&;
	//set best result
	void setQuality(double const& quality);
	// get best result
	real getQuality() const&;
	// set improvement
	void setImprovement(real const& improvement);
	// get improvement
	real getImprovement() const&;

	// set alpha
	void setAlpha(real const& alpha);
	// get alpha
	real getAlpha() const&;
	// set beta
	void setBeta(real const& beta);
	// get beta
	real getBeta() const&;
	// set gamma
	void setGamme(real const& gamma);
	// get gamma
	real getGamma() const&;

	// print parameters median blur
	void printPara_ContGamma_Struct() const &;

	// export as txt fiel
	void exportAsTXTfile();

private:

	cv::Mat mImage;
	double mQuality;

	real mAlpha;
	real mBeta;
	real mGamma;

	real mImprovement;
};

struct medianBlurStruct
{
	medianBlurStruct();
	medianBlurStruct(cv::Mat const& image, real const& quality, int const& kernelSize);
	~medianBlurStruct();

	// set image
	void setImage(cv::Mat const& image);
	// get image
	cv::Mat getImage() const&;
	//set best result
	void setQuality(double const& quality);
	// get best result
	real getQuality() const&;
	// set kernel size
	void setKernelSize(int const& kernelSize);
	// get kernel size
	int getKernelSize() const&;

	// set improvement
	void setImprovement(real const& improvement);
	// get improvement
	real getImprovement() const&;

	// print parameters median blur
	void printPara_MedianBlur_Struct() const &;

	// export as txt fiel
	void exportAsTXTfile();

	
private:
	cv::Mat mImage;
	double mQuality;
	int mKernelSize;

	real mImprovement;

};

struct detailEnhanceStruct
{	
	detailEnhanceStruct();
	detailEnhanceStruct(cv::Mat image, real const& quality, float const& sigmarS, float const& sigmarR);
	~detailEnhanceStruct();

	// set image
	void setImage(cv::Mat const& image);
	// get image
	cv::Mat getImage() const&;
	//set best result
	void setQuality(double const& quality);
	// get best result
	real getQuality() const&;
	// set sigmar s
	void setSigmar_s(float const& sigmar_s);
	// get sigmar s
	float getSigmar_s() const&;
	// set sigmar r
	void setSigmar_r(float const& sigmar_r);
	// get sigmar r
	float getSigmar_r() const&;

	// set improvement
	void setImprovement(real const& improvement);
	// get improvement
	real getImprovement() const&;

	// print parameters detailEnhanceStruct
	void printPara_DetailEnhance_Struct() const &;

	// export as txt fiel
	void exportAsTXTfile();

	private:
		cv::Mat mImage;
		double mQuality;
		float mSigmar_s;
		float mSigmar_r;

		real mImprovement;

};

struct bilateralFilterStruct
{
	bilateralFilterStruct();
	bilateralFilterStruct(cv::Mat image, real const& quality, int d, real sigmaColor, real sigmaSpace);
	~bilateralFilterStruct();

	// set image
	void setImage(cv::Mat const& image);
	// get image
	cv::Mat getImage() const&;
	// set quality
	void setQuality(real const& quality);
	// get quality
	real getQuality() const&;
	// set d
	void setD(int const& d);
	// get d
	int getD() const&;
	// set sigmaColor
	void setSigmarColor(real const& sigmaColor);
	// get sigmaColo
	real getSigmaColor() const&;
	// set sigmaSpace
	void setSigmaSpace(real const& sigmaSpace);
	// get sigmaSpace
	real getSigmaSpace() const&;
	// set boarder type
	void setBoarderType(int const& boarderType);
	// get boarder type
	int getBoarderType() const&;

	// set improvement
	void setImprovement(real const& improvement);
	// get improvement
	real getImprovement() const&;
	
	// print parameters bilateral filter struct
	void printPara_BilateralFilter_Struct() const &;

	// export as txt fiel
	void exportAsTXTfile();

private:	
	cv::Mat mImage;
	real mQuality;
	int mD;
	real mSigmaColor;
	real mSigmaSpace;
	int mBoarderType;

	real mImprovement;

};


struct unsharpMaskStruct
{
	unsharpMaskStruct();
	unsharpMaskStruct(cv::Mat const& image, real const& quality, cv::Size const& kernelSize, real const& sigmaX, real const& sigmaY, real const& threshold, real const& amount, int const& boarderType);
	~unsharpMaskStruct();

	// set image
	void setImage(cv::Mat const& image);
	// get image
	cv::Mat getImage() const&;
	// set quality
	void setQuality(real const& quality);
	// get quality
	real getQuality() const&;
	// get kernel size
	cv::Size getKernelSize() const&;
	// set kernel size
	void setKernelSize(cv::Size const& kernelSize);
	// get sigma x
	real getSigmaX() const&;
	// set sigma x
	void setSigmaX(real const& sigmaX);
	// get sigma y
	real getSigmaY() const&;
	// set sigma y
	void setSigmaY(real const& sigmaY);
	// get threshold
	real getThreshold() const&;
	// set threshold
	void setThreshold(real const& threshold);
	// get amount
	int getAmount() const&;
	// set amout
	void setAmount(int const& amount);
	// get boarder type
	int getBoarderType() const&;
	// set boarder type
	void setBoarderType(int const& boarderType);

	// set improvement
	void setImprovement(real const& improvement);
	// get improvement
	real getImprovement() const&;

	// print parameters unsharp masking filter
	void printPara_UnsharpMaskinFilter_Struct() const &;

	// export as txt fiel
	void exportAsTXTfile();

private:
	cv::Mat mImage;
	real mQuality;
	cv::Size mKernelSize;
	real mSigmaX;
	real mSigmaY;
	double mThreshold;
	double mAmoun;
	int mBoarderType;

	real mImprovement;

};

//cv::Mat	unsharpMark(csigmaX, double const& sigmaY, int const& borderType, double const& threshold, double const& amount);


class ImproveImageQuality
{
public:
	ImproveImageQuality();
	~ImproveImageQuality();

	ContrastAndGammaStruct improveImageQuality_contrastAndGamma(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, real const& minAlpha, real const& maxAlpha, int const& alphaSteps, real const& minBeta, real const& maxBeta, int const& stepsBeta, real const& minGamma, real const& maxGamma, int const& stepsGamma);
	ContrastAndGammaStruct improveImageQuality_contrastAndGamma_multiCore(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, real const& minAlpha, real const& maxAlpha, int const& alphaSteps, real const& minBeta, real const& maxBeta, int const& stepsBeta, real const& minGamma, real const& maxGamma, int const& stepsGamma);

	detailEnhanceStruct improveImageQuality_ditailEnhance(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, float const& minSigmar_s, float const& maxSigmar_s, int const& stepsSigmar_s, float const& minSigmar_r, float const& maxSigmar_r, int const& stepsSigmar_r);
	detailEnhanceStruct improveImageQuality_ditailEnhance_multiCore(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, float const& minSigmar_s, float const& maxSigmar_s, int const& stepsSigmar_s, float const& minSigmar_r, float const& maxSigmar_r, int const& stepsSigmar_r);
	
	bilateralFilterStruct improveImageQuality_bilateralFilter(cv::Mat const& sharpImage, cv::Mat simulatedImage, int const& minD, int const& maxD, int const& stepsD, double const& minSimgaColor, double const& maxSigmaColor, int const& stepsSigmaColor, double const& minSigmaSpace, double const& maxSigmaSpace, double const& stepsSigmaSpace, int const& boarderType);
	bilateralFilterStruct improveImageQuality_bilateralFilter_multiCore(cv::Mat const& sharpImage, cv::Mat simulatedImage, int const& minD, int const& maxD, int const& stepsD, double const& minSimgaColor, double const& maxSigmaColor, int const& stepsSigmaColor, double const& minSigmaSpace, double const& maxSigmaSpace, double const& stepsSigmaSpace, int const& boarderType);

	unsharpMaskStruct improveImageQuality_unsharpMask(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, std::vector<cv::Size> const& kernelSize_vec, double const& minSigmaX, double const& maxSigmaX, double const& stepsSgmaX, double const& minSigmaY, double const& maxSigmaY, double const& stepsSigmaY, int const& borderType, double const& minThreshold, double const& maxThreshold, double const& stepsThreshold, double const& minAmount, double const& maxAmount, double const& stepsAmount);
	unsharpMaskStruct improveImageQuality_unsharpMask_multiCore(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, std::vector<cv::Size> const& kernelSize_vec, double const& minSigmaX, double const& maxSigmaX, double const& stepsSgmaX, double const& minSigmaY, double const& maxSigmaY, double const& stepsSigmaY, int const& borderType, double const& minThreshold, double const& maxThreshold, double const& stepsThreshold, double const& minAmount, double const& maxAmount, double const& stepsAmount);

	medianBlurStruct improveImageQuality_medianBlur(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, std::vector<int> const& kernelSize_vec);

	unsharpMaskStruct improveImageQuality_unsharpMask_ForServer(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, std::vector<cv::Size> const& kernelSize_vec, double const& minSigmaX, double const& maxSigmaX, double const& stepsSgmaX, double const& minSigmaY, double const& maxSigmaY, double const& stepsSigmaY, int const& borderType, int const& threshold, int const& amount);
	unsharpMaskStruct improveImageQuality_unsharpMask_MultiCor_ForServer(cv::Mat const& sharpImage, cv::Mat const& simulatedImage, std::vector<cv::Size> const& kernelSize_vec, double const& minSigmaX, double const& maxSigmaX, double const& stepsSgmaX, double const& minSigmaY, double const& maxSigmaY, double const& stepsSigmaY, int const& borderType, int const& threshold, int const& amount);

private:

};

