#pragma once

// important structs
#include "..\LowLevelTracing\ImportantStructures.h"

// open cv
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/calib3d/calib3d.hpp>
//#include <opencv2/imgcodecs.hpp>
#include <opencv2/photo.hpp>

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
	void printPara_ContGamma_Struct() const&;

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
	void printPara_MedianBlur_Struct() const&;

	// export as txt fiel
	void exportAsTXTfile();


private:
	cv::Mat mImage;
	double mQuality;
	int mKernelSize;

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
	void printPara_BilateralFilter_Struct() const&;

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

